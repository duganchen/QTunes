#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "connectionmanager.h"
#include "controller.h"
#include "itemmodeldata.h"
#include "mockmpdsettings.h"
#include "mpdconnection.h"
#include "panemodel.h"

#include "tagitem.h"
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

    QVector<AbstractItem *> artists;
	artists.push_back(new TagItem("artist"));
	auto artistsController = new ItemModelController;
	PaneModel artistModel(artists, artistsController);

    QVector<AbstractItem *> albums;
    albums.push_back(new TagItem("album"));
	auto albumController = new ItemModelController();
	PaneModel albumModel(albums, albumController);

    QVector<AbstractItem *> songs;
    songs.push_back(new TagItem("song"));
	auto songsController = new ItemModelController();
	PaneModel songModel(songs, songsController);

    QVector<AbstractItem *> playlists;
    playlists.push_back(new TagItem("playlist"));
	auto playlistsController = new ItemModelController();
	PaneModel playlistModel(playlists, playlistsController);

    QVector<AbstractItem *> queue;
    queue.push_back(new TagItem("queued song"));
	auto queueController = new ItemModelController;
	PaneModel queueModel(queue, queueController);

	ItemModelData artistData(artists, artistsController);
	ItemModelData albumData(albums, albumController);
	ItemModelData songData(songs, songsController);
	ItemModelData playlistData(playlists, playlistsController);
	ItemModelData queueData(queue, queueController);

	Controller controller(&mpd_settings, artistData, albumData, songData, playlistData, queueData);

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
