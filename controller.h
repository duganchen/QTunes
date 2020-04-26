#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString host READ host WRITE setHost NOTIFY hostChanged)
    Q_PROPERTY(QString port READ port WRITE setPort NOTIFY portChanged)
public:
    explicit Controller(QObject *parent = nullptr);

    QString host() const;
    void setHost(QString);
    QString port() const;
    void setPort(QString);
signals:
    void hostChanged();
    void portChanged();
private:
    QString m_host;
    QString m_port;
};

#endif // CONTROLLER_H
