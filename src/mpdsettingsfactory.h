#ifndef MPDSETTINGSFACTORY_H
#define MPDSETTINGSFACTORY_H

#include <QObject>
#include "abstractmpdsettingsfactory.h"

class MPDSettingsFactory : public AbstractMPDSettingsFactory
{
public:
    explicit MPDSettingsFactory(QObject *parent = nullptr);
    virtual AbstractMPDSettings *createSettings(const char *host, unsigned port, unsigned timeout_ms, const char *reserved, const char *password, QObject *parent = nullptr);
};


#endif // MPDSETTINGSFACTORY_H
