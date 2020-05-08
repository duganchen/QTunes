#ifndef ABSTRACTMPDSETTINGS_H
#define ABSTRACTMPDSETTINGS_H

#include <QObject>

class AbstractMPDSettings : public QObject
{
    Q_OBJECT
public:
    explicit AbstractMPDSettings(const char *host, unsigned port, unsigned timeout_ms, const char *reserved,
                                 const char *password, QObject *parent = nullptr);

    virtual const char *host();
    virtual unsigned port();
    virtual unsigned timeout_ms();
    virtual const char *password();
};

#endif // ABSTRACTMPDSETTINGS_H
