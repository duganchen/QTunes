#include "hostinfo.h"
#include <QtNetwork/QHostInfo>

HostInfo::HostInfo(QObject *parent) : AbstractHostInfo(parent)
{
}

void HostInfo::lookupHost(QString name)
{
    QHostInfo::lookupHost(name, [=](QHostInfo hostInfo) {
        if (hostInfo.error())
        {
            emit errorString(hostInfo.errorString());
        }
        else
        {
            emit errorString("");
        }
    });
}
