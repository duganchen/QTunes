#ifndef MPDCONNECTIONFACTORY_H
#define MPDCONNECTIONFACTORY_H

#include "abstractmpdconnection.h"
#include "abstractmpdconnectionfactory.h"
#include <QObject>

class MPDConnectionFactory : public AbstractMPDConnectionFactory
{
    Q_OBJECT
public:
    explicit MPDConnectionFactory(QObject *parent = nullptr);
    virtual AbstractMPDConnection *createMPDConnection(QObject *parent = nullptr);
};

#endif // MPDCONNECTIONFACTORY_H
