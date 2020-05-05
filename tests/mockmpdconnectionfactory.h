#ifndef MOCKMPDCONNECTIONFACTORY_H
#define MOCKMPDCONNECTIONFACTORY_H

#include "../src/abstractmpdconnectionfactory.h"

class MockMPDConnectionFactory : public AbstractMPDConnectionFactory
{
public:
    explicit MockMPDConnectionFactory(QObject *parent = nullptr);
    virtual AbstractMPDConnection *createMPDConnection(QObject *parent = nullptr);
};

#endif // MOCKMPDCONNECTIONFACTORY_H
