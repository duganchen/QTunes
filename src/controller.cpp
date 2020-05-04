#include "controller.h"
#include <QDebug>

Controller::Controller(AbstractHostInfo *hostInfo, AbstractMPDSettingsFactory *mpdSettingsFactory, AbstractMPDConnectionFactory *mpdConnectionFactory, QObject *parent) :
    QObject(parent),
    m_host("localhost"),
    m_port("6600"),
    m_isConnecting(false),
    m_hostInfo(hostInfo),
    m_hostErrorString(""),
    m_portErrorString(""),
    m_connectionState(ConnectionState::Disconnected),
    m_mpdSettingsFactory(mpdSettingsFactory),
    m_mpdConnectionFactory(mpdConnectionFactory)
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
    }
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

Controller::ConnectionState Controller::connectionState() const
{
    return m_connectionState;
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

Controller::ConnectionState Controller::state() const
{
    return ConnectionState::Disconnected;
}
