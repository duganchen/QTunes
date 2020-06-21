#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Controller_global.h"
#include <mpd/client.h>
#include <QObject>
#include <QSocketNotifier>
#include "itemmodelcontroller.h"

class CONTROLLER_EXPORT Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QString, unsigned, unsigned, QObject *parent = nullptr);

    enum class ConnectionState { Disconnected, Connecting, Connected };
    Q_ENUM(ConnectionState)
public slots:
    void handleConnectClick();
    void handleListAlbumsClick();
    void connectToMPD(QString, int, int);

public:
    QVector<QString> getAlbumList();

    QString host();

    ItemModelController *tags() const;
    ItemModelController *artists() const;
    ItemModelController *albums() const;
    ItemModelController *songs() const;
    ItemModelController *playlists() const;
    ItemModelController *queue() const;
signals:
    void errorMessage(QString);
    void connectionState(Controller::ConnectionState connectionState);

    void requestConnection(QString, unsigned, unsigned);

    void beginMPDCommand();
    void endMPDCommand();

    void unrecoverableError();

    void queueChanged();

private:
    void handleIdle(mpd_idle);
    void createMPD();

    QString m_host;
    unsigned m_port;
    unsigned m_timeout_ms;

    mpd_connection *m_connection;
    QSocketNotifier *m_notifier;

    // artist, albumartist, composer
    ItemModelController *m_tags;

    ItemModelController *m_artists;

    ItemModelController *m_albums;

    ItemModelController *m_songs;

    // stored playlists
    ItemModelController *m_playlists;

    ItemModelController *m_queue;

private slots:
    void handleActivation();
};

Q_DECLARE_METATYPE(Controller::ConnectionState);

#endif // CONTROLLER_H
