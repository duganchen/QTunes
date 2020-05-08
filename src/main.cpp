#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "connectionmanager.h"
#include "controller.h"
#include "mockmpdsettings.h"
#include "model.h"
#include "mpdconnection.h"
#include "panemodel.h"

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

	Controller controller(&mpd_settings);

	ConnectionManager connectionManager;

	QObject::connect(&controller, &Controller::requestConnection, &connectionManager,
					 &ConnectionManager::createConnection);
	QObject::connect(&connectionManager, &ConnectionManager::mpd, &controller, &Controller::setMPD);

	Model model;
	QObject::connect(&controller, &Controller::btnClicked, &model, &Model::printStuff);

    QQmlApplicationEngine engine;

	QVector<const char *> artists{"artist 1", "artist 2", "artist 3"};
    PaneModel artistModel;
    artistModel.setList(artists);
    engine.rootContext()->setContextProperty("artistModel", &artistModel);

	QVector<const char *> albums{"album 1", "album 2", "album 3"};
    PaneModel albumModel;
    albumModel.setList(albums);
    engine.rootContext()->setContextProperty("albumModel", &albumModel);

	QVector<const char *> songs{"song 1", "song 2", "song 3"};
    PaneModel songModel;
    songModel.setList(songs);
    engine.rootContext()->setContextProperty("songModel", &songModel);

	QVector<const char *> playlists{"playlist 1", "playlist 2", "playlist 3"};
    PaneModel playlistModel;
    playlistModel.setList(playlists);
    engine.rootContext()->setContextProperty("playlistModel", &playlistModel);

	QVector<const char *> queue{"queued song 1", "queued song 2", "queued song 3"};
    PaneModel queueModel;
    queueModel.setList(queue);
    engine.rootContext()->setContextProperty("queueModel", &queueModel);

	engine.rootContext()->setContextProperty("controller", &controller);

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
