#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "abstractmpdconnection.h"
#include "abstractmpdsettings.h"
#include "mpdsettings.h"
#include <QObject>

class Controller : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool isConnecting READ isConnecting WRITE setConnecting NOTIFY connectingChanged)

    Q_PROPERTY(QString hostErrorString READ hostErrorString WRITE setHostErrorString NOTIFY hostErrorStringChanged)
    Q_PROPERTY(QString portErrorString READ portErrorString WRITE setPortErrorString NOTIFY portErrorStringChanged)

    Q_PROPERTY(QString host READ host);
    Q_PROPERTY(unsigned port READ port);
    Q_PROPERTY(unsigned timeout_ms READ timeout_ms);
    Q_PROPERTY(QString password READ password);

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
    bool isConnecting() const;
    QString hostErrorString() const;
    QString portErrorString() const;
    ConnectionState connectionState() const;

    QString host() const;
    unsigned port() const;
    unsigned timeout_ms() const;
    QString password() const;

    QString connectionErrorMessage() const;

public slots:
    ConnectionState state() const;
    void connectToMPD();
    void setConnecting(bool);
    void setHostErrorString(QString);
    void setPortErrorString(QString);
    void setConnectionState(ConnectionState);
    void handleBtnClick();

    void setMPD(AbstractMPDConnection *);
    QString connectionError() const;

signals:
    void connectingChanged(bool);
    void portErrorStringChanged(QString);
    void hostErrorStringChanged(QString);
    void connectionStateChanged(ConnectionState);

    void btnClicked();

    void connectionError(QString);
    void requestConnection(AbstractMPDSettings *);

    void connectionErrorChanged(QString);

private:
    bool m_isConnecting;
    QString m_hostErrorString;
    QString m_portErrorString;
    ConnectionState m_connectionState;
    AbstractMPDConnection *m_mpd;
    AbstractMPDSettings *m_settings;

    void handleIdle(mpd_idle);
    QString m_connectionError;
    void setConnectionError(QString);
};

#endif // CONTROLLER_H
