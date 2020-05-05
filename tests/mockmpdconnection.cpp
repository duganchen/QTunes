#include "mockmpdconnection.h"

MockMPDConnection::MockMPDConnection(QObject *parent) : AbstractMPDConnection(parent)
{
}

void MockMPDConnection::connectToMPD(const char *host, unsigned int port, unsigned int timeout_ms)
{
    Q_UNUSED(host)
    Q_UNUSED(port)
    Q_UNUSED(timeout_ms)
}

mpd_error MockMPDConnection::error()
{
    return MPD_ERROR_SUCCESS;
}

QString MockMPDConnection::errorString()
{
    // Note: The real version fails an assertion if there is no error to stringify.
    return "";
}

bool MockMPDConnection::isNull() const
{
    return false;
}
