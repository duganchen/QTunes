#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include <QObject>
#include "abstracthostinfo.h"

class ViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString host READ host WRITE setHost NOTIFY hostChanged)
    Q_PROPERTY(QString port READ port WRITE setPort NOTIFY portChanged)

    Q_PROPERTY(bool connectEnabled READ connectEnabled WRITE setConnectEnabled NOTIFY connectEnabledChanged)
    Q_PROPERTY(bool isConnecting READ isConnecting WRITE setConnecting NOTIFY connectingChanged)

    Q_PROPERTY(QString hostErrorString READ hostErrorString WRITE setHostErrorString NOTIFY hostErrorStringChanged)
    Q_PROPERTY(QString portErrorString READ portErrorString WRITE setPortErrorString NOTIFY portErrorStringChanged)
public:
    explicit ViewModel(AbstractHostInfo *hostInfo, QObject *parent = nullptr);
    QString host() const;
    QString port() const;
    bool connectEnabled() const;
    bool isConnecting() const;
    QString hostErrorString() const;
    QString portErrorString() const;
public slots:
    void setHost(QString);
    void setPort(QString);
    void setConnectEnabled(bool);
    void connect();
    void setConnecting(bool);
    void setHostErrorString (QString);
    void setPortErrorString(QString);
signals:
    void hostChanged(QString);
    void portChanged(QString);
    void connectEnabledChanged(bool);
    void connectingChanged(bool);
    void portErrorStringChanged(QString);
    void hostErrorStringChanged(QString);
private:
    QString m_host;
    QString m_port;
    bool m_connectEnabled;
    bool m_isConnecting;
    AbstractHostInfo *m_hostInfo;
    QString m_hostErrorString;
    QString m_portErrorString;
};

#endif // VIEWMODEL_H
