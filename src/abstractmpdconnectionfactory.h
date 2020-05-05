#ifndef ABSTRACTMPDCONNECTIONFACTORY_H
#define ABSTRACTMPDCONNECTIONFACTORY_H

#include "abstractmpdconnection.h"
#include <QObject>

class AbstractMPDConnectionFactory : public QObject
{
    Q_OBJECT
public:
    explicit AbstractMPDConnectionFactory(QObject *parent = nullptr);
    virtual AbstractMPDConnection *createMPDConnection(QObject *parent = nullptr) = 0;
};

#endif // ABSTRACTMPDCONNECTIONFACTORY_H
