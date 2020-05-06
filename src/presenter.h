#ifndef PRESENTER_H
#define PRESENTER_H

#include "abstractmpdconnection.h"
#include "abstractmpdsettingsfactory.h"
#include <QObject>

class Presenter : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString host READ host WRITE setHost NOTIFY hostChanged)
    Q_PROPERTY(QString port READ port WRITE setPort NOTIFY portChanged)

    Q_PROPERTY(bool isConnecting READ isConnecting WRITE setConnecting NOTIFY connectingChanged)

    Q_PROPERTY(QString hostErrorString READ hostErrorString WRITE setHostErrorString NOTIFY hostErrorStringChanged)
    Q_PROPERTY(QString portErrorString READ portErrorString WRITE setPortErrorString NOTIFY portErrorStringChanged)

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
    QString host() const;
    QString port() const;
    bool isConnecting() const;
    QString hostErrorString() const;
    QString portErrorString() const;
    ConnectionState connectionState() const;
public slots:
    ConnectionState state() const;
    void setHost(QString);
    void setPort(QString);
    void connectToMPD(QString, QString);
    void setConnecting(bool);
    void setHostErrorString(QString);
    void setPortErrorString(QString);
    void setConnectionState(ConnectionState);
signals:
    void hostChanged(QString);
    void portChanged(QString);
    void connectingChanged(bool);
    void portErrorStringChanged(QString);
    void hostErrorStringChanged(QString);
    void connectionStateChanged(ConnectionState);

private:
    QString m_host;
    QString m_port;
    bool m_isConnecting;
    QString m_hostErrorString;
    QString m_portErrorString;
    ConnectionState m_connectionState;
    AbstractMPDSettingsFactory *m_mpdSettingsFactory;
    AbstractMPDConnection *m_mpd;
};

#endif // PRESENTER_H
