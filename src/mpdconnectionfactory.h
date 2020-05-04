#ifndef MPDCONNECTIONFACTORY_H
#define MPDCONNECTIONFACTORY_H

#include <QObject>
#include "abstractmpdconnection.h"
#include "abstractmpdconnectionfactory.h"

class MPDConnectionFactory : public AbstractMPDConnectionFactory
{
    Q_OBJECT
public:
    explicit MPDConnectionFactory(QObject *parent = nullptr);
    virtual AbstractMPDConnection *createMPDConnection(const char *host, unsigned port, unsigned timeout_ms, QObject *parent = nullptr);
};

#endif // MPDCONNECTIONFACTORY_H
