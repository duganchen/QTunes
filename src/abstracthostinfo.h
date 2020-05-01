#ifndef ABSTRACTHOSTINFO_H
#define ABSTRACTHOSTINFO_H

#include <QObject>

class AbstractHostInfo : public QObject
{
    Q_OBJECT
public:
    AbstractHostInfo(QObject *parent = nullptr);
    virtual void lookupHost(QString) = 0;
signals:
    void errorString(QString);
};

#endif // ABSTRACTHOSTINFO_H
