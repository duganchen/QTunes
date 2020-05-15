#include "controller.h"
#include <QDebug>

Controller::Controller(AbstractMPDSettings *mpdSettings,

                       const ItemModelData &artists, const ItemModelData &albums, const ItemModelData &songs,
                       const ItemModelData &playlists, const ItemModelData &queue, QObject *parent)
    : QObject(parent), m_connectionState(ConnectionState::Disconnected), m_mpd(nullptr), m_settings(mpdSettings),
      m_artists(artists), m_albums(albums), m_songs(songs), m_playlists(playlists), m_queue(queue)
{
}

Controller::ConnectionState Controller::connectionState() const
{
    return m_connectionState;
}

void Controller::connectToMPD()
{
    setConnectionState(ConnectionState::Connecting);
    emit requestConnection(m_settings);
}

void Controller::setConnectionState(ConnectionState connectionState)
{
    if (connectionState == m_connectionState)
    {
        return;
    }

    if (ConnectionState::Disconnected == connectionState)
    {
        m_artists.controller->beginRemoveRows(0, m_artists.items.size() - 1);
        for (auto item : m_artists.items)
        {
            delete item;
        }
        m_artists.items.clear();
        m_artists.controller->endRemoveRows();

        m_albums.controller->beginRemoveRows(0, m_albums.items.size() - 1);
        for (auto item : m_albums.items)
        {
            delete item;
        }
        m_albums.items.clear();
        m_albums.controller->endRemoveRows();

        m_songs.controller->beginRemoveRows(0, m_songs.items.size() - 1);
        for (auto item : m_songs.items)
        {
            delete item;
        }
        m_songs.items.clear();
        m_songs.controller->endRemoveRows();

        m_playlists.controller->beginRemoveRows(0, m_playlists.items.size() - 1);
        for (auto item : m_playlists.items)
        {
            delete item;
        }
        m_playlists.items.clear();
        m_playlists.controller->endRemoveRows();

        m_queue.controller->beginRemoveRows(0, m_queue.items.size() - 1);
        for (auto item : m_queue.items)
        {
            delete item;
        }
        m_queue.items.clear();
        m_queue.controller->endRemoveRows();
    }

    m_connectionState = connectionState;
    emit connectionStateChanged(connectionState);
}

Controller::ConnectionState Controller::state() const
{
    return ConnectionState::Disconnected;
}

void Controller::handleBtnClick()
{
    qDebug() << "Button clicked";
    if (m_mpd)
    {
        auto result = m_mpd->list_queue_meta();
    }
}

void Controller::setMPD(AbstractMPDConnection *mpd)
{
    if (!mpd || mpd->isNull())
    {
        // The first condition should never happens. The second means we're out of memory.
        qDebug() << "Unrecoverable error";
    }

    if (m_mpd)
    {
        delete m_mpd;
    }

    m_mpd = mpd;

    if (m_mpd->error() == MPD_ERROR_SUCCESS)
    {

        // Trigger setConnectionState slot
        setConnectionState(ConnectionState::Connected);

        connect(mpd, &AbstractMPDConnection::idle, this, &Controller::handleIdle);
    }
    else
    {
        setConnectionError(m_mpd->error_message());
        setConnectionState(ConnectionState::Disconnected);
    }
}

QString Controller::connectionError() const
{
    return m_connectionError;
}

void Controller::handleIdle(mpd_idle idle)
{
    if (!m_mpd || m_mpd->isNull())
    {
        return;
    }

    if (!idle && m_mpd->error() != MPD_ERROR_SUCCESS)
    {
        // This means we lost the connection.
        setConnectionError(m_mpd->error_message());
        delete m_mpd;
        m_mpd = nullptr;
        setConnectionState(ConnectionState::Disconnected);
    }
}

void Controller::setConnectionError(QString message)
{
    if (m_connectionError != message)
    {
        m_connectionError = message;
        emit connectionErrorChanged(message);
    }
}
