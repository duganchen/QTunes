#ifndef HOSTINFO_H
#define HOSTINFO_H

#include "abstracthostinfo.h"

class HostInfo: public AbstractHostInfo
{
    Q_OBJECT
public:
    HostInfo(QObject *parent = nullptr);
    virtual void lookupHost(QString);
};

#endif // HOSTINFO_H
