#ifndef MPDCONNECTION_H
#define MPDCONNECTION_H

#include <mpd/client.h>
#include "abstractmpdconnection.h"

class MPDConnection : public AbstractMPDConnection
{
    Q_OBJECT
public:
    explicit MPDConnection(const char *host, unsigned port, unsigned timeout_ms, QObject *parent = nullptr);
    ~MPDConnection();

    virtual bool isNull() const;

private:
    struct mpd_connection *m_mpd_connection;
};

#endif // MPDCONNECTION_H
