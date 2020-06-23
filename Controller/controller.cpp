#include "controller.h"
#include "tagitem.h"
#include <mpd/client.h>
#include <QDebug>
#include <QtNetwork/QLocalSocket>
#include <QtNetwork/QTcpSocket>

Controller::Controller(QObject *parent)
    : QObject(parent)
    , m_connection(nullptr)
    , m_notifier(nullptr)
{
    qRegisterMetaType<Controller::ConnectionState>();

    m_tags = new ItemModelController(this);
    m_tags->items.push_back(new TagItem("artist"));
    m_tags->items.push_back(new TagItem("albumartist"));
    m_tags->items.push_back(new TagItem("composer"));

    m_artists = new ItemModelController(this);
    m_artists->items.push_back(new TagItem("an artist"));

    m_albums = new ItemModelController(this);
    m_albums->items.push_back(new TagItem("An album"));
    m_songs = new ItemModelController(this);

    for (int i = 0; i < 100; i++) {
        QString label = "song %1";
        m_songs->items.push_back(new TagItem(label.arg(i)));
    }
    m_playlists = new ItemModelController(this);
    m_playlists->items.push_back(new TagItem("A stored playlist"));
    m_playlists->items.push_back(new TagItem("Another stored playlist"));

    m_queue = new ItemModelController(this);
    m_queue->items.push_back(new TagItem("A queued song"));
    m_queue->items.push_back(new TagItem("Another queued song"));

    auto settings = mpd_settings_new(nullptr, 0, 0, nullptr, nullptr);
    m_defaultHost = mpd_settings_get_host(settings);
    m_defaultPort = mpd_settings_get_port(settings);
    m_defaultTimeout = mpd_settings_get_timeout_ms(settings);
    mpd_settings_free(settings);
}

void Controller::connectToMPD(QString host, int port, int timeout_ms)
{
    emit connectionState(ConnectionState::Connecting);

    // This is literally how libmpdclient determines if a host is a Unix socket,
    // at least as of 2.18.
    if (host.startsWith("/") || host.startsWith("@")) {
        createMPD(host, port, timeout_ms);

    } else {
        // If it's a Tcp socket, then we first use Qt to asynchronously check if we can actually
        // connect, because libmpdclient's internal host address resolution is blocking and
        // can take a long time to return if it fails..
        auto socket = new QTcpSocket();

        connect(socket, &QTcpSocket::errorOccurred, [=](QTcpSocket::SocketError error) {
            Q_UNUSED(error);
            emit errorMessage(socket->errorString());
            socket->deleteLater();
            emit connectionState(ConnectionState::Disconnected);
        });

        connect(socket, &QTcpSocket::connected, [=]() {
            connect(socket, &QTcpSocket::disconnected, [=]() {
                socket->deleteLater();

                createMPD(host, port, timeout_ms);
            });
            socket->disconnectFromHost();
        });

        socket->connectToHost(host, port);
    }
}

void Controller::handleListAlbumsClick()
{
    if (!m_connection) {
        return;
    }

    for (auto album : getAlbumList()) {
        qDebug() << album;
    }
}

QVector<QString> Controller::getAlbumList()
{
    QVector<QString> albums;

    if (!m_connection) {
        return albums;
    }

    m_notifier->setEnabled(false);
    mpd_run_noidle(m_connection);

    if (!mpd_search_db_tags(m_connection, MPD_TAG_ALBUM)) {
        qDebug() << mpd_connection_get_error_message(m_connection);
        return albums;
    }

    if (!mpd_search_commit(m_connection)) {
        qDebug() << mpd_connection_get_error_message(m_connection);
        return albums;
    }

    struct mpd_pair *pair = nullptr;
    while ((pair = mpd_recv_pair_tag(m_connection, MPD_TAG_ALBUM)) != nullptr) {
        albums.push_back(pair->value);
        mpd_return_pair(m_connection, pair);
    }

    m_notifier->setEnabled(true);
    mpd_send_idle(m_connection);

    return albums;
}

QString Controller::defaultHost()
{
    return m_defaultHost;
}

void Controller::handleIdle(mpd_idle idle)
{
    qDebug() << "Controller has received an idle";
    if (!m_connection) {
        return;
    }

    if (!idle && mpd_connection_get_error(m_connection) != MPD_ERROR_SUCCESS) {
        // This means we lost the connection.
        qDebug() << mpd_connection_get_error_message(m_connection);
        mpd_connection_free(m_connection);
        m_connection = nullptr;
        emit connectionState(ConnectionState::Disconnected);
    }

    if (idle & MPD_IDLE_QUEUE) {
        qDebug() << "THE QUEUE HAS CHANGED";
        emit queueChanged();
    }
}

void Controller::createMPD(QString host, int port, int timeout_ms)
{
    auto connection = mpd_connection_new(host.toUtf8().constData(), port, timeout_ms);

    if (!connection) {
        // OOM
        emit unrecoverableError();
    }

    if (m_connection) {
        mpd_connection_free(m_connection);
    }

    if (m_notifier) {
        delete m_notifier;
    }

    m_connection = connection;

    if (mpd_connection_get_error(m_connection) == MPD_ERROR_SUCCESS) {
        m_notifier = new QSocketNotifier(mpd_connection_get_fd(m_connection),
                                         QSocketNotifier::Read,
                                         this);

        connect(m_notifier, &QSocketNotifier::activated, this, &Controller::handleActivation);

        mpd_send_idle(m_connection);
        emit connectionState(ConnectionState::Connected);
    } else {
        emit errorMessage(mpd_connection_get_error_message(m_connection));
        emit connectionState(ConnectionState::Disconnected);
    }
}

void Controller::handleActivation()
{
    handleIdle(mpd_recv_idle(m_connection, false));
}

ItemModelController *Controller::tags() const
{
    return m_tags;
}

ItemModelController *Controller::artists() const
{
    return m_artists;
}

ItemModelController *Controller::albums() const
{
    return m_albums;
}

ItemModelController *Controller::songs() const
{
    return m_songs;
}

ItemModelController *Controller::playlists() const
{
    return m_playlists;
}

ItemModelController *Controller::queue() const
{
    return m_queue;
}
