#include <QtNetwork/QHostInfo>
#include "hostinfo.h"

HostInfo::HostInfo(QObject *parent): AbstractHostInfo(parent)
{
}


void HostInfo::lookupHost(QString name)
{
    QHostInfo::lookupHost(name, [=](QHostInfo hostInfo) {
        if (hostInfo.error())
        {
            emit errorString("");
        }
        else
        {
            emit errorString(hostInfo.errorString());
        }
    });
}
