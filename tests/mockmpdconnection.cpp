#include "mockmpdconnection.h"

MockMPDConnection::MockMPDConnection(const char *host, unsigned port, unsigned timeout_ms, QObject *parent) : AbstractMPDConnection(host, port, timeout_ms, parent)
{
}


bool MockMPDConnection::isNull() const
{
    return false;
}
