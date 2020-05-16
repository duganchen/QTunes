#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "connectionmanager.h"
#include "controller.h"
#include "mockmpdsettings.h"
#include "mpdconnection.h"
#include "panemodel.h"

#include "tagitem.h"
#include <QTimer>
#include <mpd/client.h>

#include <QDebug>

int main(int argc, char *argv[])
{
    qDebug() << "Make sure debug logs are working";

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterUncreatableType<Controller>("QTunes", 1, 0, "Controller", "You can't create a Controller sorry");

    // Create context property objects before the engine. See:
    // https://forum.qt.io/topic/110356/viewpiece-qml-105-typeerror-cannot-read-property-sessionname-of-null/7

    MockMPDSettings mpd_settings("localhost", 6600, 200, nullptr, nullptr);

    ConnectionManager connectionManager;

    ItemModelController artists;
    artists.items.push_back(new TagItem("artist"));
    PaneModel artistModel(&artists);

    ItemModelController albums;
    albums.items.push_back(new TagItem("album"));
    PaneModel albumModel(&albums);

    ItemModelController songs;
    songs.items.push_back(new TagItem("song"));
    PaneModel songModel(&songs);

    ItemModelController playlists;
    playlists.items.push_back(new TagItem("playlist"));
    PaneModel playlistModel(&playlists);

    ItemModelController queue;
    queue.items.push_back(new TagItem("queued song"));
    PaneModel queueModel(&queue);

    Controller controller(&mpd_settings, &artists, &albums, &songs, &playlists, &queue);

    QObject::connect(&controller, &Controller::requestConnection, &connectionManager,
                     &ConnectionManager::createConnection);
    QObject::connect(&connectionManager, &ConnectionManager::mpd, &controller, &Controller::setMPD);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("controller", &controller);
    engine.rootContext()->setContextProperty("artistModel", &artistModel);
    engine.rootContext()->setContextProperty("albumModel", &albumModel);
    engine.rootContext()->setContextProperty("songModel", &songModel);
    engine.rootContext()->setContextProperty("playlistModel", &playlistModel);
    engine.rootContext()->setContextProperty("queueModel", &queueModel);

	QTimer timer;
	QObject::connect(&timer, &QTimer::timeout, &controller, &Controller::onTicked);
	timer.start(1000);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
