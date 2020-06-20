#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>

#include "controller.h"
#include "panemodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQuickStyle::setStyle("Universal");

    QQmlApplicationEngine engine;

    QVector<QString> artists {"artist 1", "artist 2", "artist 3"};
    PaneModel artistModel;
    artistModel.setList(artists);
    engine.rootContext()->setContextProperty("artistModel", &artistModel);

    QVector<QString> albums {"album 1", "album 2", "album 3"};
    PaneModel albumModel;
    albumModel.setList(albums);
    engine.rootContext()->setContextProperty("albumModel", &albumModel);

    QVector<QString> songs {"song 1", "song 2", "song 3"};
    PaneModel songModel;
    songModel.setList(songs);
    engine.rootContext()->setContextProperty("songModel", &songModel);

    QVector<QString> playlists {"playlist 1", "playlist 2", "playlist 3"};
    PaneModel playlistModel;
    playlistModel.setList(playlists);
    engine.rootContext()->setContextProperty("playlistModel", &playlistModel);

    QVector<QString> queue {"queued song 1", "queued song 2", "queued song 3"};
    PaneModel queueModel;
    queueModel.setList(queue);
    engine.rootContext()->setContextProperty("queueModel", &queueModel);

    Controller controller;
    engine.rootContext()->setContextProperty("controller", &controller);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}