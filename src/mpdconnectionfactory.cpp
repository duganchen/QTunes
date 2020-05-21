#include "mpdconnectionfactory.h"
#include "mpdconnection.h"
#include <QDebug>
#include <QGuiApplication>

MPDConnectionFactory::MPDConnectionFactory(QObject *parent)
    : QObject(parent)
{}

void MPDConnectionFactory::createConnection(AbstractMPDSettings *settings)
{
    auto mpdConnection = new MPDConnection(settings);
    mpdConnection->setParent(nullptr);
    mpdConnection->moveToThread(QGuiApplication::instance()->thread());
    emit mpd(mpdConnection);
}
