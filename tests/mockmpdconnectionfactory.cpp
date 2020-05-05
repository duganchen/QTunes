#include "mockmpdconnectionfactory.h"
#include "mockmpdconnection.h"

MockMPDConnectionFactory::MockMPDConnectionFactory(QObject *parent) : AbstractMPDConnectionFactory(parent)
{
}

AbstractMPDConnection *MockMPDConnectionFactory::createMPDConnection(QObject *parent)
{
    return new MockMPDConnection(parent);
}
