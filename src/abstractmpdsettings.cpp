#include "abstractmpdsettings.h"

AbstractMPDSettings::AbstractMPDSettings(const char *host,
                                         unsigned port,
                                         unsigned timeout_ms,
                                         const char *reserved,
                                         const char *password,
                                         QObject *parent)
    : QObject(parent)
{
    Q_UNUSED(host)
    Q_UNUSED(port)
    Q_UNUSED(timeout_ms)
    Q_UNUSED(reserved)
    Q_UNUSED(password)
}

// Add some stub implementations so that mocks aren't as painful.

const char *AbstractMPDSettings::host()
{
    return "localhost";
}

unsigned AbstractMPDSettings::port()
{
    return 6600;
}

unsigned AbstractMPDSettings::timeout_ms()
{
    return 0;
}

const char *AbstractMPDSettings::password()
{
    // Note: this isn't currently used by QTunes.
    return "";
}
