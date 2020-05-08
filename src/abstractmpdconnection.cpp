#include "abstractmpdconnection.h"

// Have stub implementations so that mocking isn't as painful.

AbstractMPDConnection::AbstractMPDConnection(AbstractMPDSettings *settings, QObject *parent) : QObject(parent)
{
    Q_UNUSED(settings)
}

mpd_error AbstractMPDConnection::error()
{
    return MPD_ERROR_SUCCESS;
}

const char *AbstractMPDConnection::error_message()
{
    // Note that libmpdclient's implementation asserts that the error state isn't
    // MPD_ERROR_SUCCESS.
    return "";
}

bool AbstractMPDConnection::isNull() const
{
    return false;
}

int AbstractMPDConnection::fd()
{
    return 1;
}

bool AbstractMPDConnection::send_idle()
{
    return true;
}

mpd_idle AbstractMPDConnection::run_noidle()
{
    return static_cast<mpd_idle>(0);
}

QVector<const char *> AbstractMPDConnection::search_db_tags(mpd_tag_type)
{
    QVector<const char *> tags;
    return tags;
}

QVector<AbstractMPDSong *> AbstractMPDConnection::list_queue_meta()
{
    QVector<AbstractMPDSong *> songs;
    return songs;
}
