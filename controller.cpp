#include "controller.h"

Controller::Controller(QObject *parent) :
    QObject(parent),
    m_host("localhost"),
    m_port("6600")
{
}

QString Controller::host() const
{
    return m_host;
}

void Controller::setHost(QString host)
{
    bool changed = m_host == host ? false : true;
    m_host = host;
    if (changed)
    {
        emit hostChanged();
    }
}

QString Controller::port() const
{
    return m_port;
}

void Controller::setPort(QString port)
{
    bool changed = m_port == port ? false : true;
    m_port = port;
    if (changed)
    {
        emit portChanged();
    }
}
