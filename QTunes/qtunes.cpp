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

    Controller controller;

    PaneModel tagModel(controller.tags());
    PaneModel artistModel(controller.artists());
    PaneModel albumModel(controller.albums());
    PaneModel songModel(controller.songs());
    PaneModel playlistModel(controller.playlists());
    PaneModel queueModel(controller.queue());

    // Create context property objects before the engine. See:
    // https://forum.qt.io/topic/110356/viewpiece-qml-105-typeerror-cannot-read-property-sessionname-of-null/7

    QQmlApplicationEngine engine;

    qmlRegisterUncreatableType<Controller>("QTunes",
                                           1,
                                           0,
                                           "Controller",
                                           "You can't create a Controller sorry");

    engine.rootContext()->setContextProperty("tagModel", &tagModel);
    engine.rootContext()->setContextProperty("artistModel", &artistModel);
    engine.rootContext()->setContextProperty("albumModel", &albumModel);
    engine.rootContext()->setContextProperty("songModel", &songModel);
    engine.rootContext()->setContextProperty("playlistModel", &playlistModel);
    engine.rootContext()->setContextProperty("queueModel", &queueModel);
    engine.rootContext()->setContextProperty("controller", &controller);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
