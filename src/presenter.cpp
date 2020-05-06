#include "presenter.h"
#include <QDebug>

Presenter::Presenter(AbstractHostInfo *hostInfo, AbstractMPDSettingsFactory *mpdSettingsFactory,
                     AbstractMPDConnection *mpd, QObject *parent)
    : QObject(parent), m_host("localhost"), m_port("6600"), m_isConnecting(false), m_hostInfo(hostInfo),
      m_hostErrorString(""), m_portErrorString(""), m_connectionState(ConnectionState::Disconnected),
      m_mpdSettingsFactory(mpdSettingsFactory), m_mpd(mpd)
{

    connect(hostInfo, &AbstractHostInfo::errorString, [=](QString errorString) { setHostErrorString(errorString); });
}

QString Presenter::host() const
{
    return m_host;
}

void Presenter::setHost(QString value)
{
    if (m_host != value)
    {
        m_host = value;
        emit hostChanged(value);
    }
}

QString Presenter::port() const
{
    return m_port;
}

void Presenter::setPort(QString value)
{
    if (m_port != value)
    {
        m_port = value;
        emit portChanged(value);
    }
}

bool Presenter::isConnecting() const
{
    return m_isConnecting;
}

QString Presenter::hostErrorString() const
{
    return m_hostErrorString;
}

QString Presenter::portErrorString() const
{
    return m_portErrorString;
}

Presenter::ConnectionState Presenter::connectionState() const
{
    return m_connectionState;
}

void Presenter::connectToMPD(QString host, QString port)
{
    Q_UNUSED(port);

    if (host != "localhost")
    {
        m_hostInfo->lookupHost(host);
    }
}

void Presenter::setConnecting(bool value)
{
    if (m_isConnecting != value)
    {
        m_isConnecting = value;
        emit connectingChanged(value);
    }
}

void Presenter::setHostErrorString(QString value)
{
    if (m_hostErrorString != value)
    {
        m_hostErrorString = value;
        emit hostErrorStringChanged(value);
    }
}

void Presenter::setPortErrorString(QString value)
{
    if (m_portErrorString != value)
    {
        m_portErrorString = value;
        emit portErrorStringChanged(value);
    }
}

void Presenter::setConnectionState(ConnectionState connectionState)
{
    if (connectionState != m_connectionState)
    {
        m_connectionState = connectionState;
        emit connectionStateChanged(connectionState);
    }
}

Presenter::ConnectionState Presenter::state() const
{
    return ConnectionState::Disconnected;
}
