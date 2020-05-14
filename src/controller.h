#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "abstractitem.h"
#include "abstractmpdconnection.h"
#include "abstractmpdsettings.h"
#include "itemmodelcontroller.h"
#include "mpdsettings.h"
#include <QObject>
#include <QVector>

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(
        ConnectionState connectionState READ connectionState WRITE setConnectionState NOTIFY connectionStateChanged);
    Q_PROPERTY(QString connectionError READ connectionError NOTIFY connectionErrorChanged);

public:
    enum ConnectionState
    {
        Disconnected,
        Connecting,
        Connected
    };
    Q_ENUM(ConnectionState)

	explicit Controller(

		AbstractMPDSettings *,
		// artists
		QVector<AbstractItem *> &, ItemModelController *,
		// albums
		QVector<AbstractItem *> &, ItemModelController *,
		// songs
		QVector<AbstractItem *> &, ItemModelController *,
		// stored playlists
		QVector<AbstractItem *> &, ItemModelController *,
		// queue
		QVector<AbstractItem *> &, ItemModelController *,

		QObject *parent = nullptr);
    ConnectionState connectionState() const;

    QString connectionError() const;

public slots:
    ConnectionState state() const;
    void connectToMPD();
    void setConnectionState(ConnectionState);
    void handleBtnClick();

    void setMPD(AbstractMPDConnection *);

signals:
    void connectionStateChanged(ConnectionState);

    void connectionError(QString);
    void requestConnection(AbstractMPDSettings *);

    void connectionErrorChanged(QString);

private:
    ConnectionState m_connectionState;
    AbstractMPDConnection *m_mpd;
    AbstractMPDSettings *m_settings;

    void handleIdle(mpd_idle);
    QString m_connectionError;
    void setConnectionError(QString);

	QVector<AbstractItem *> &m_artists;
	ItemModelController *m_artistsController;
	QVector<AbstractItem *> &m_albums;
	ItemModelController *m_albumsController;
	QVector<AbstractItem *> &m_songs;
	ItemModelController *m_songsController;
	QVector<AbstractItem *> &m_storedPlaylists;
	ItemModelController *m_storedPlaylistsController;
	QVector<AbstractItem *> &m_queue;
	ItemModelController *m_queueController;
};

#endif // CONTROLLER_H
