#include "mockmpdsettingsfactory.h"
#include "mockmpdsettings.h"

MockMPDSettingsFactory::MockMPDSettingsFactory(QObject *parent): AbstractMPDSettingsFactory(parent)
{

}

AbstractMPDSettings *MockMPDSettingsFactory::createSettings(const char *host, unsigned port, unsigned timeout_ms, const char *reserved, const char *password, QObject *parent)
{
    return new MockMPDSettings(host, port, timeout_ms, reserved, password, parent);
}
