#include "presenter.h"
#include <QDebug>

Presenter::Presenter(AbstractMPDSettingsFactory *mpdSettingsFactory, AbstractMPDConnection *mpd, QObject *parent)
    : QObject(parent), m_isConnecting(false), m_hostErrorString(""), m_portErrorString(""),
      m_connectionState(ConnectionState::Disconnected), m_mpdSettingsFactory(mpdSettingsFactory), m_mpd(mpd)
{
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
    Q_UNUSED(host);
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
