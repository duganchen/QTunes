#ifndef MOCKMPDSETTINGSFACTORY_H
#define MOCKMPDSETTINGSFACTORY_H

#include <QObject>
#include "../src/abstractmpdsettingsfactory.h"

class MockMPDSettingsFactory : public AbstractMPDSettingsFactory
{
public:
    explicit MockMPDSettingsFactory(QObject *parent = nullptr);
    virtual AbstractMPDSettings *createSettings(const char *host, unsigned port, unsigned timeout_ms, const char *reserved, const char *password, QObject *parent = nullptr);
};

#endif // MOCKMPDSETTINGSFACTORY_H
