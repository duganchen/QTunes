#include "mpdconnectionfactory.h"
#include "mpdconnection.h"

MPDConnectionFactory::MPDConnectionFactory(QObject *parent) : AbstractMPDConnectionFactory(parent)
{

}

AbstractMPDConnection *MPDConnectionFactory::createMPDConnection(const char *host, unsigned port, unsigned timeout_ms, QObject *parent)
{
    return new MPDConnection(host, port, timeout_ms, parent);
}
