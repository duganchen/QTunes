#include "viewmodel.h"
#include <QDebug>

ViewModel::ViewModel(AbstractHostInfo *hostInfo, QObject *parent) :
    QObject(parent),
    m_host("localhost"),
    m_port("6600"),
    m_connectEnabled(true),
    m_isConnecting(false),
    m_hostInfo(hostInfo),
    m_hostErrorString(""),
    m_portErrorString("")
{

    connect(hostInfo, &AbstractHostInfo::errorString, [=](QString errorString) {
        setHostErrorString(errorString);
    });
}

QString ViewModel::host() const
{
    return m_host;
}

void ViewModel::setHost(QString value)
{
    if (m_host != value)
    {
        m_host = value;
        emit hostChanged(value);

        setConnectEnabled(this->host().length() && this->port().length());
    }
}

QString ViewModel::port() const
{
    return m_port;
}

void ViewModel::setPort(QString value)
{
    if (m_port != value)
    {
        m_port = value;
        emit portChanged(value);

        setConnectEnabled(this->host().length() && this->port().length());
    }
}

bool ViewModel::connectEnabled() const
{
    return m_connectEnabled;
}

bool ViewModel::isConnecting() const
{
    return m_isConnecting;
}

QString ViewModel::hostErrorString() const
{
    return m_hostErrorString;
}

QString ViewModel::portErrorString() const
{
    return m_portErrorString;
}

void ViewModel::setConnectEnabled(bool value)
{
    if (m_connectEnabled != value)
    {
        m_connectEnabled = value;
        emit connectEnabledChanged(value);
    }
}


void ViewModel::connectToMPD(QString host, QString port)
{
    Q_UNUSED(port);

    if (host != "localhost")
    {
        m_hostInfo->lookupHost(host);
    }
}

void ViewModel::setConnecting(bool value)
{
    if (m_isConnecting != value)
    {
        m_isConnecting = value;
        emit connectingChanged(value);
    }
}

void ViewModel::setHostErrorString(QString value)
{
    if (m_hostErrorString != value)
    {
        m_hostErrorString = value;
        emit hostErrorStringChanged(value);
    }
}

void ViewModel::setPortErrorString(QString value)
{
    if (m_portErrorString != value)
    {
        m_portErrorString = value;
        emit portErrorStringChanged(value);
    }
}
