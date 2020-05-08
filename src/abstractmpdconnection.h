#ifndef ABSTRACTMPDCONNECTION_H
#define ABSTRACTMPDCONNECTION_H

#include "abstractmpdsettings.h"
#include "abstractmpdsong.h"
#include <QObject>
#include <mpd/client.h>

class AbstractMPDConnection : public QObject
{
    Q_OBJECT
public:
    explicit AbstractMPDConnection(AbstractMPDSettings *settings, QObject *parent = nullptr);

    virtual mpd_error error();
    virtual const char *error_message();
    virtual bool isNull() const;
    virtual int fd();
    virtual bool send_idle();
    virtual mpd_idle run_noidle();

    virtual QVector<const char *> search_db_tags(mpd_tag_type);
    virtual QVector<AbstractMPDSong *> list_queue_meta();
signals:
    void idle(mpd_idle);
};

#endif // ABSTRACTMPDCONNECTION_H
