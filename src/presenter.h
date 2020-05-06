#ifndef PRESENTER_H
#define PRESENTER_H

#include "abstractmpdconnection.h"
#include "abstractmpdsettingsfactory.h"
#include "mpdsettings.h"
#include <QObject>

class Presenter : public QObject
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

public:
    enum ConnectionState
    {
        Disconnected,
        Connecting,
        Connected
    };
    Q_ENUM(ConnectionState)

    explicit Presenter(AbstractMPDSettingsFactory *mpdSettingsFactory, AbstractMPDConnection *mpd,
                       QObject *parent = nullptr);
    bool isConnecting() const;
    QString hostErrorString() const;
    QString portErrorString() const;
    ConnectionState connectionState() const;

    QString host() const;
    unsigned port() const;
    unsigned timeout_ms() const;
    QString password() const;

public slots:
    ConnectionState state() const;
    void connectToMPD();
    void setConnecting(bool);
    void setHostErrorString(QString);
    void setPortErrorString(QString);
    void setConnectionState(ConnectionState);
signals:
    void connectingChanged(bool);
    void portErrorStringChanged(QString);
    void hostErrorStringChanged(QString);
    void connectionStateChanged(ConnectionState);

private:
    bool m_isConnecting;
    QString m_hostErrorString;
    QString m_portErrorString;
    ConnectionState m_connectionState;
    AbstractMPDConnection *m_mpd;
    AbstractMPDSettings *m_settings;
};

#endif // PRESENTER_H
