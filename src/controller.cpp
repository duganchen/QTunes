#include "controller.h"
#include <QDebug>

Controller::Controller(AbstractMPDSettings *mpdSettings, QObject *parent)
    : QObject(parent), m_connectionState(ConnectionState::Disconnected), m_mpd(nullptr), m_settings(mpdSettings)
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
    if (connectionState != m_connectionState)
    {
        m_connectionState = connectionState;
        emit connectionStateChanged(connectionState);
    }
}

Controller::ConnectionState Controller::state() const
{
    return ConnectionState::Disconnected;
}

void Controller::handleBtnClick()
{
    for (const char *tag : m_mpd->search_db_tags(MPD_TAG_ALBUM))
    {
        qDebug() << tag;
    }
}

void Controller::setMPD(AbstractMPDConnection *mpd)
{
    qDebug() << "Setting it in the controller";

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
