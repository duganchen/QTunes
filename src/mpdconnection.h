#ifndef MPDCONNECTION_H
#define MPDCONNECTION_H

#include "abstractmpdconnection.h"
#include <QSocketNotifier>
#include <mpd/client.h>

class MPDConnection : public AbstractMPDConnection
{
    Q_OBJECT
public:
    explicit MPDConnection(QObject *parent = nullptr);
    ~MPDConnection();

    virtual void connectToMPD(const char *host, unsigned port, unsigned timeout_ms);

    virtual mpd_error error();
    virtual QString errorString();

    virtual bool isNull() const;

private:
    struct mpd_connection *m_mpd_connection;
    QSocketNotifier *m_socketNotifier;

    void disableNotifications();
    void enableNotifications();

private slots:
    void recvIdle();
};

#endif // MPDCONNECTION_H
