#include "controller.h"
#include <QDebug>

Controller::Controller(QObject *parent) :
    QObject(parent),
    m_host("localhost"),
    m_port("6600"),
    m_connectEnabled(true)
{
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

void Controller::setConnectEnabled(bool value)
{
    if (m_connectEnabled != value)
    {
        m_connectEnabled = value;
        emit connectEnabledChanged(value);
    }
}
