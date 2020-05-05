#ifndef ABSTRACTMPDCONNECTION_H
#define ABSTRACTMPDCONNECTION_H

#include <QObject>
#include <mpd/client.h>

class AbstractMPDConnection : public QObject
{
    Q_OBJECT
public:
    explicit AbstractMPDConnection(QObject *parent = nullptr);

    virtual void connectToMPD(const char *host, unsigned port, unsigned timeout_ms) = 0;

    virtual mpd_error error() = 0;
    virtual QString errorString() = 0;

    virtual bool isNull() const = 0;

    enum ConnectionState
    {
        Disconnected,
        Connecting,
        Connected
    };
    Q_ENUM(ConnectionState)

    ConnectionState state() const;

signals:
    void connected();
    void disconnected();

    void idle(mpd_idle);

protected:
    ConnectionState m_state;
};

#endif // ABSTRACTMPDCONNECTION_H
