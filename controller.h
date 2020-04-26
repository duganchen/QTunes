#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString host READ host WRITE setHost NOTIFY hostChanged)
    Q_PROPERTY(QString port READ port WRITE setPort NOTIFY portChanged)
    Q_PROPERTY(bool connectEnabled READ connectEnabled WRITE setConnectEnabled NOTIFY connectEnabledChanged)
public:
    explicit Controller(QObject *parent = nullptr);

    QString host() const;
    void setHost(QString);
    QString port() const;
    void setPort(QString);
    bool connectEnabled() const;
    void setConnectEnabled(bool);
signals:
    void hostChanged(QString);
    void portChanged(QString);
    void connectEnabledChanged(bool);
private:
    QString m_host;
    QString m_port;
    bool m_connectEnabled;
};

#endif // CONTROLLER_H
