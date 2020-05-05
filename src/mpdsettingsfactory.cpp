#include "mpdsettingsfactory.h"
#include "mpdsettings.h"

MPDSettingsFactory::MPDSettingsFactory(QObject *parent) : AbstractMPDSettingsFactory(parent)
{
}

AbstractMPDSettings *MPDSettingsFactory::createSettings(const char *host, unsigned port, unsigned timeout_ms,
                                                        const char *reserved, const char *password, QObject *parent)
{
    return new MPDSettings(host, port, timeout_ms, reserved, password, parent);
}
