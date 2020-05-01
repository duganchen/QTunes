#include "controller.h"
#include <QDebug>

Controller::Controller(AbstractHostInfo *hostInfo, QObject *parent) :
    QObject(parent),
    m_host("localhost"),
    m_port("6600"),
    m_connectEnabled(true),
    m_isConnecting(false),
    m_hostInfo(hostInfo),
    m_hostErrorString(""),
    m_portErrorString(""),
    m_connectionState(ConnectionState::DISCONNECTED)
{

    connect(hostInfo, &AbstractHostInfo::errorString, [=](QString errorString) {
        setHostErrorString(errorString);
    });
}

QString Controller::host() const
{
    return m_host;
}

void Controller::setHost(QString value)
{
    if (m_host != value)
    {
        m_host = value;
        emit hostChanged(value);

        setConnectEnabled(this->host().length() && this->port().length());
    }
}

QString Controller::port() const
{
    return m_port;
}

void Controller::setPort(QString value)
{
    if (m_port != value)
    {
        m_port = value;
        emit portChanged(value);

        setConnectEnabled(this->host().length() && this->port().length());
    }
}

bool Controller::connectEnabled() const
{
    return m_connectEnabled;
}

bool Controller::isConnecting() const
{
    return m_isConnecting;
}

QString Controller::hostErrorString() const
{
    return m_hostErrorString;
}

QString Controller::portErrorString() const
{
    return m_portErrorString;
}

ConnectionState Controller::connectionState() const
{
    return m_connectionState;
}

void Controller::setConnectEnabled(bool value)
{
    if (m_connectEnabled != value)
    {
        m_connectEnabled = value;
        emit connectEnabledChanged(value);
    }
}


void Controller::connectToMPD(QString host, QString port)
{
    Q_UNUSED(port);

    if (host != "localhost")
    {
        m_hostInfo->lookupHost(host);
    }
}

void Controller::setConnecting(bool value)
{
    if (m_isConnecting != value)
    {
        m_isConnecting = value;
        emit connectingChanged(value);
    }
}

void Controller::setHostErrorString(QString value)
{
    if (m_hostErrorString != value)
    {
        m_hostErrorString = value;
        emit hostErrorStringChanged(value);
    }
}

void Controller::setPortErrorString(QString value)
{
    if (m_portErrorString != value)
    {
        m_portErrorString = value;
        emit portErrorStringChanged(value);
    }
}

void Controller::setConnectionState(ConnectionState connectionState)
{
    if (connectionState != m_connectionState)
    {
        m_connectionState = connectionState;
        emit connectionStateChanged(connectionState);
    }
}
