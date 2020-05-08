#include "controller.h"
#include <QDebug>

Controller::Controller(AbstractMPDSettings *mpdSettings, QObject *parent)
    : QObject(parent), m_isConnecting(false), m_hostErrorString(""), m_portErrorString(""),
      m_connectionState(ConnectionState::Disconnected), m_mpd(nullptr), m_settings(mpdSettings),
      m_connectionError("Do you see this error?")
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

void Controller::setMPD(AbstractMPDConnection *mpd)
{
    if (!mpd || mpd->isNull())
    {
        // The first condition should never happens. The second means we're out of memory.
        qDebug() << "Unrecoverable error";
    }

    if (m_mpd)
    {
        delete m_mpd;
    }

    m_mpd = mpd;

    if (m_mpd->error() == MPD_ERROR_SUCCESS)
    {
        setConnectionState(ConnectionState::Connected);

        connect(mpd, &AbstractMPDConnection::idle, this, &Controller::handleIdle);
    }
    else
    {
        qDebug() << m_mpd->error_message();
        setConnectionState(ConnectionState::Disconnected);
    }
}

QString Controller::connectionError() const
{
    return m_connectionError;
}

void Controller::handleIdle(mpd_idle idle)
{
    if (!m_mpd || m_mpd->isNull())
    {
        return;
    }

    if (!idle && m_mpd->error() != MPD_ERROR_SUCCESS)
    {
        // This means we lost the connection.
        qDebug() << m_mpd->error_message();
        delete m_mpd;
        m_mpd = nullptr;
        setConnectionState(ConnectionState::Disconnected);
    }
}

void Controller::setConnectionError(QString message)
{
    if (m_connectionError != message)
    {
        m_connectionError = message;
        emit connectionErrorChanged(message);
    }
}
