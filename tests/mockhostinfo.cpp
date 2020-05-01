#include "mockhostinfo.h"

MockHostInfo::MockHostInfo(QObject *parent): AbstractHostInfo(parent), m_errorStr("")
{
}


void MockHostInfo::lookupHost(QString name)
{
    Q_UNUSED(name)
    emit errorString(m_errorStr);
}

void MockHostInfo::setErrorString(QString value)
{
    m_errorStr = value;
}
