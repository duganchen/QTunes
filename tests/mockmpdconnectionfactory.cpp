#include "mockmpdconnectionfactory.h"
#include "mockmpdconnection.h"

MockMPDConnectionFactory::MockMPDConnectionFactory(QObject *parent) : AbstractMPDConnectionFactory(parent)
{

}

AbstractMPDConnection *MockMPDConnectionFactory::createMPDConnection(const char *host, unsigned port, unsigned timeout_ms, QObject *parent)
{
    return new MockMPDConnection(host, port, timeout_ms, parent);
}
