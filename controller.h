#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString host READ host WRITE setHost NOTIFY hostChanged)
    Q_PROPERTY(QString port READ port WRITE setPort NOTIFY portChanged)
    Q_PROPERTY(bool connectEnabled READ connectEnabled WRITE setConnectEnabled NOTIFY connectEnabledChanged)
    Q_PROPERTY(bool isConnecting READ isConnecting WRITE setConnecting NOTIFY connectingChanged)
public:
    explicit Controller(QObject *parent = nullptr);
    QString host() const;
    QString port() const;
    bool connectEnabled() const;
    bool isConnecting() const;
public slots:
    void setHost(QString);
    void setPort(QString);
    void setConnectEnabled(bool);
    void connect();
    void setConnecting(bool);
signals:
    void hostChanged(QString);
    void portChanged(QString);
    void connectEnabledChanged(bool);
    void connectingChanged(bool);
private:
    QString m_host;
    QString m_port;
    bool m_connectEnabled;
    bool m_isConnecting;
};

#endif // CONTROLLER_H
