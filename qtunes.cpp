#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include "artistmodel.h"
#include "albummodel.h"
#include "songmodel.h"
#include "playlistmodel.h"
#include "queuemodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<ArtistModel>("Artist", 1, 0, "ArtistModel");
    qmlRegisterType<AlbumModel>("Album", 1, 0, "AlbumModel");
    qmlRegisterType<SongModel>("Song", 1, 0, "SongModel");
    qmlRegisterType<PlaylistModel>("Playlist", 1, 0, "PlaylistModel");
    qmlRegisterType<QueueModel>("Queue", 1, 0, "QueueModel");

    QQuickStyle::setStyle("Universal");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
