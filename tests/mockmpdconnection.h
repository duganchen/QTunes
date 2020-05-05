#ifndef MOCKMPDCONNECTION_H
#define MOCKMPDCONNECTION_H

#include "../src/abstractmpdconnection.h"

class MockMPDConnection : public AbstractMPDConnection
{
public:
    explicit MockMPDConnection(QObject *parent = nullptr);

    virtual void connectToMPD(const char *host, unsigned port, unsigned timeout_ms);

    virtual mpd_error error();
    virtual QString errorString();

    virtual bool isNull() const;
};

#endif // MOCKMPDCONNECTION_H
