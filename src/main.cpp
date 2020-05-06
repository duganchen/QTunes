#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "mpdconnection.h"
#include "mpdsettingsfactory.h"
#include "panemodel.h"
#include "presenter.h"

#include <mpd/client.h>

#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterUncreatableType<Presenter>("QTunes", 1, 0, "ConnectionState", "You can't create a Controller sorry");

    // Create context property objects before the engine. See:
    // https://forum.qt.io/topic/110356/viewpiece-qml-105-typeerror-cannot-read-property-sessionname-of-null/7

    MPDSettingsFactory mpdSettingsFactory;
    MPDConnection mpd;
    Presenter controller(&mpdSettingsFactory, &mpd);

    QQmlApplicationEngine engine;

    QVector<QString> artists{"artist 1", "artist 2", "artist 3"};
    PaneModel artistModel;
    artistModel.setList(artists);
    engine.rootContext()->setContextProperty("artistModel", &artistModel);

    QVector<QString> albums{"album 1", "album 2", "album 3"};
    PaneModel albumModel;
    albumModel.setList(albums);
    engine.rootContext()->setContextProperty("albumModel", &albumModel);

    QVector<QString> songs{"song 1", "song 2", "song 3"};
    PaneModel songModel;
    songModel.setList(songs);
    engine.rootContext()->setContextProperty("songModel", &songModel);

    QVector<QString> playlists{"playlist 1", "playlist 2", "playlist 3"};
    PaneModel playlistModel;
    playlistModel.setList(playlists);
    engine.rootContext()->setContextProperty("playlistModel", &playlistModel);

    QVector<QString> queue{"queued song 1", "queued song 2", "queued song 3"};
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
