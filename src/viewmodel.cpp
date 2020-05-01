#include "viewmodel.h"
#include <QDebug>

ViewModel::ViewModel(QObject *parent) :
    QObject(parent),
    m_host("localhost"),
    m_port("6600"),
    m_connectEnabled(true),
    m_isConnecting(false)
{
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

void ViewModel::setConnectEnabled(bool value)
{
    if (m_connectEnabled != value)
    {
        m_connectEnabled = value;
        emit connectEnabledChanged(value);
    }
}


void ViewModel::connect()
{
    qDebug() << "Connect clicked";
}

void ViewModel::setConnecting(bool value)
{
    if (m_isConnecting != value)
    {
        m_isConnecting = value;
        emit connectingChanged(value);
    }
}
