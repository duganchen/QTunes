#include "mpdconnection.h"

MPDConnection::MPDConnection(QObject *parent)
    : AbstractMPDConnection(parent), m_mpd_connection(nullptr), m_socketNotifier(nullptr)
{
}

void MPDConnection::connectToMPD(const char *host, unsigned int port, unsigned int timeout_ms)
{
    if (m_mpd_connection)
    {
        mpd_connection_free(m_mpd_connection);
        m_mpd_connection = nullptr;
    }

    if (m_socketNotifier)
    {
        delete m_socketNotifier;
        m_socketNotifier = nullptr;
    }

    m_state = ConnectionState::Connecting;

    m_mpd_connection = mpd_connection_new(host, port, timeout_ms);

    if (m_mpd_connection != nullptr && mpd_connection_get_error(m_mpd_connection) == MPD_ERROR_SUCCESS)
    {
        m_socketNotifier = new QSocketNotifier(mpd_connection_get_fd(m_mpd_connection), QSocketNotifier::Read, this);
        connect(m_socketNotifier, &QSocketNotifier::activated, this, &MPDConnection::recvIdle);

        m_state = ConnectionState::Connected;
        emit connected();
    }
    else
    {
        m_state = ConnectionState::Disconnected;
    }
}

MPDConnection::~MPDConnection()
{
    if (m_mpd_connection)
    {
        mpd_connection_free(m_mpd_connection);
    }
}

mpd_error MPDConnection::error()
{
    return mpd_connection_get_error(m_mpd_connection);
}

QString MPDConnection::errorString()
{
    return mpd_connection_get_error_message(m_mpd_connection);
}

bool MPDConnection::isNull() const
{
    return nullptr == m_mpd_connection;
}

void MPDConnection::disableNotifications()
{
    if (!m_socketNotifier)
    {
        return;
    }

    m_socketNotifier->setEnabled(false);
    recvIdle();
}

void MPDConnection::enableNotifications()
{
    if (!m_socketNotifier)
    {
        return;
    }

    m_socketNotifier->setEnabled(true);
    mpd_send_idle(m_mpd_connection);
}

void MPDConnection::recvIdle()
{
    if (!m_mpd_connection)
    {
        return;
    }

    auto changed_systems = mpd_recv_idle(m_mpd_connection, false);

    if (changed_systems == 0)
    {
        emit disconnected();
        return;
    }

    emit idle(changed_systems);
}
