#include "mockmpdsettings.h"

MockMPDSettings::MockMPDSettings(const char *host, unsigned port, unsigned timeout_ms, const char *reserved,
                                 const char *password, QObject *parent)
    : AbstractMPDSettings(host, port, timeout_ms, reserved, password, parent)
{
    Q_UNUSED(host)
    Q_UNUSED(port)
    Q_UNUSED(timeout_ms)
    Q_UNUSED(reserved)
    Q_UNUSED(password)
}

const char *MockMPDSettings::host()
{
    return "localhost";
}

unsigned MockMPDSettings::port()
{
    return 6600;
}

unsigned MockMPDSettings::timeout_ms()
{
    return 0;
}

const char *MockMPDSettings::password()
{
    return "";
}
