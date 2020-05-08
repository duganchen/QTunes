#include "connectionmanager.h"
#include "mpdconnectionfactory.h"
#include <QDebug>

ConnectionManager::ConnectionManager(QObject *parent) : QObject(parent)
{
    auto connectionFactory = new MPDConnectionFactory();
    connectionFactory->moveToThread(&connectionThread);

    connect(&connectionThread, &QThread::finished, connectionFactory, &MPDConnectionFactory::deleteLater);
    connect(this, &ConnectionManager::requestConnectionFromFactory, connectionFactory,
            &MPDConnectionFactory::createConnection);
    connect(connectionFactory, &MPDConnectionFactory::mpd, this, &ConnectionManager::setMPD);

    connectionThread.start();
}

ConnectionManager::~ConnectionManager()
{
    connectionThread.quit();
    connectionThread.wait();
}

void ConnectionManager::createConnection(AbstractMPDSettings *settings)
{
    emit requestConnectionFromFactory(settings);
}

void ConnectionManager::setMPD(AbstractMPDConnection *conn)
{
    emit mpd(conn);
}
