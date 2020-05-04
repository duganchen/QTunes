#ifndef ABSTRACTMPDSETTINGSFACTORY_H
#define ABSTRACTMPDSETTINGSFACTORY_H

#include <QObject>
#include "abstractmpdsettings.h"

class AbstractMPDSettingsFactory : public QObject
{
    Q_OBJECT
public:
    explicit AbstractMPDSettingsFactory(QObject *parent = nullptr);
    virtual AbstractMPDSettings *createSettings(const char *host, unsigned port, unsigned timeout_ms, const char *reserved, const char *password, QObject *parent = nullptr) = 0;
};

#endif // ABSTRACTMPDSETTINGSFACTORY_H
