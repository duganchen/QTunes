#include "mpdconnectionfactory.h"
#include "mpdconnection.h"

MPDConnectionFactory::MPDConnectionFactory(QObject *parent) : AbstractMPDConnectionFactory(parent)
{
}

AbstractMPDConnection *MPDConnectionFactory::createMPDConnection(QObject *parent)
{
    return new MPDConnection(parent);
}
