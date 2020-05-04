#ifndef MOCKMPDSETTINGS_H
#define MOCKMPDSETTINGS_H

#include "../src/abstractmpdsettings.h"

class MockMPDSettings : public AbstractMPDSettings
{
public:
    explicit MockMPDSettings(const char *host, unsigned port, unsigned timeout_ms, const char *reserved, const char *password, QObject *parent = nullptr);

    virtual const char *host();
    virtual unsigned port();
    virtual unsigned timeout_ms();
    virtual const char *password();
};


#endif // MOCKMPDSETTINGS_H
