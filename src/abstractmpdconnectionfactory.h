#ifndef ABSTRACTMPDCONNECTIONFACTORY_H
#define ABSTRACTMPDCONNECTIONFACTORY_H

#include <QObject>
#include "abstractmpdconnection.h"

class AbstractMPDConnectionFactory : public QObject
{
    Q_OBJECT
public:
    explicit AbstractMPDConnectionFactory(QObject *parent = nullptr);
    virtual AbstractMPDConnection *createMPDConnection(const char *host, unsigned port, unsigned timeout_ms, QObject *parent = nullptr) = 0;
};

#endif // ABSTRACTMPDCONNECTIONFACTORY_H
