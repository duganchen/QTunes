#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "abstractmpdconnection.h"
#include "abstractmpdsettings.h"
#include "mpdsettings.h"
#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(
        ConnectionState connectionState READ connectionState WRITE setConnectionState NOTIFY connectionStateChanged);
    Q_PROPERTY(QString connectionError READ connectionError NOTIFY connectionErrorChanged);

public:
    enum ConnectionState
    {
        Disconnected,
        Connecting,
        Connected
    };
    Q_ENUM(ConnectionState)

    explicit Controller(AbstractMPDSettings *mpdSettings, QObject *parent = nullptr);
    ConnectionState connectionState() const;

    QString connectionError() const;

public slots:
    ConnectionState state() const;
    void connectToMPD();
    void setConnectionState(ConnectionState);
    void handleBtnClick();

    void setMPD(AbstractMPDConnection *);

signals:
    void connectionStateChanged(ConnectionState);

    void connectionError(QString);
    void requestConnection(AbstractMPDSettings *);

    void connectionErrorChanged(QString);

private:
    ConnectionState m_connectionState;
    AbstractMPDConnection *m_mpd;
    AbstractMPDSettings *m_settings;

    void handleIdle(mpd_idle);
    QString m_connectionError;
    void setConnectionError(QString);
};

#endif // CONTROLLER_H
