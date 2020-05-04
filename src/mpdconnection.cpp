#include "mpdconnection.h"

MPDConnection::MPDConnection(const char *host, unsigned port, unsigned timeout_ms, QObject *parent) : AbstractMPDConnection(host, port, timeout_ms, parent), m_mpd_connection(nullptr)
{
    m_mpd_connection = mpd_connection_new(host, port, timeout_ms);
}

MPDConnection::~MPDConnection()
{
    if (m_mpd_connection)
    {
         mpd_connection_free(m_mpd_connection);
    }
}

bool MPDConnection::isNull() const
{
    return m_mpd_connection == nullptr;
}
