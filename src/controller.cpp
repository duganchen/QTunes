#include "controller.h"
#include <QDebug>

Controller::Controller(AbstractMPDSettings *mpdSettings, AbstractMPDConnection *mpd, QObject *parent)
    : QObject(parent), m_isConnecting(false), m_hostErrorString(""), m_portErrorString(""),
	  m_connectionState(ConnectionState::Disconnected), m_mpd(mpd), m_settings(mpdSettings)
{
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

void Controller::connectToMPD()
{
    qDebug() << "host is " << host();
    qDebug() << "port is " << port();
    qDebug() << "timeout_ms is " << timeout_ms();
    qDebug() << "password is " << password();

    setConnectionState(ConnectionState::Connecting);
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

QString Controller::host() const
{
    return m_settings->host();
}

unsigned Controller::port() const
{
    return m_settings->port();
}

unsigned Controller::timeout_ms() const
{
    return m_settings->timeout_ms();
}

QString Controller::password() const
{
    return m_settings->password();
}

void Controller::handleBtnClick()
{
	qDebug() << "Presenter is handling the button click";
	emit btnClicked();
}
