#ifndef MOCKMPDCONNECTION_H
#define MOCKMPDCONNECTION_H

#include "../src/abstractmpdconnection.h"

class MockMPDConnection: public AbstractMPDConnection
{
public:
    explicit MockMPDConnection(const char *host, unsigned port, unsigned timeout_ms, QObject *parent = nullptr);
    virtual bool isNull() const;
};

#endif // MOCKMPDCONNECTION_H
