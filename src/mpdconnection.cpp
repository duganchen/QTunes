#include "mpdconnection.h"
#include "mpdsong.h"
#include <mpd/client.h>
#include <QDebug>
#include <QSocketNotifier>

MPDConnection::MPDConnection(AbstractMPDSettings *settings, QObject *parent)
    : AbstractMPDConnection(settings, parent)
    , m_notifier(nullptr)
{
    // If you're connecting to a host that can't be resolved, then this takes
    // around a second. No matter how low you set the timeout.
    m_mpd = mpd_connection_new(settings->host(), settings->port(), settings->timeout_ms());

    if (mpd_connection_get_error(m_mpd) == MPD_ERROR_SUCCESS) {
        m_notifier = new QSocketNotifier(mpd_connection_get_fd(m_mpd), QSocketNotifier::Read, this);
        connect(m_notifier, &QSocketNotifier::activated, this, &MPDConnection::handleActivation);
        mpd_send_idle(m_mpd);
    }

    // Error handling is done in the Controller, in setMPD.
}

MPDConnection::~MPDConnection()
{
    if (m_mpd) {
        mpd_connection_free(m_mpd);
    }
}

mpd_error MPDConnection::error()
{
    return mpd_connection_get_error(m_mpd);
}

const char *MPDConnection::error_message()
{
    return mpd_connection_get_error_message(m_mpd);
}

bool MPDConnection::isNull() const
{
    return nullptr == m_mpd;
}

int MPDConnection::fd()
{
    return mpd_connection_get_fd(m_mpd);
}

bool MPDConnection::send_idle()
{
    return mpd_send_idle(m_mpd);
}

mpd_idle MPDConnection::run_noidle()
{
    return mpd_run_noidle(m_mpd);
}

QVector<const char *> MPDConnection::search_db_tags(mpd_tag_type type)
{
    QVector<const char *> tags;
    if (!m_mpd || !m_notifier) {
        return tags;
    }

    m_notifier->setEnabled(false);
    emit idle(mpd_run_noidle(m_mpd));

    if (!mpd_search_db_tags(m_mpd, type)) {
        qDebug() << mpd_connection_get_error_message(m_mpd);
        return tags;
    }

    if (!mpd_search_commit(m_mpd)) {
        qDebug() << mpd_connection_get_error_message(m_mpd);
        return tags;
    }

    struct mpd_pair *pair = nullptr;
    while ((pair = mpd_recv_pair_tag(m_mpd, type)) != nullptr) {
        tags.push_back(pair->value);
        mpd_return_pair(m_mpd, pair);
    }

    m_notifier->setEnabled(true);
    mpd_send_idle(m_mpd);

    return tags;
}

void MPDConnection::handleActivation()
{
    emit idle(mpd_recv_idle(m_mpd, false));
}

QVector<AbstractMPDSong *> MPDConnection::list_queue_meta()
{
    // Implementation will come from here.
    // https://www.reddit.com/r/C_Programming/comments/3hl1xt/anyone_have_experience_with_libmpdclient/cu8qb6u

    QVector<AbstractMPDSong *> songs;

    m_notifier->setEnabled(false);

    emit idle(mpd_run_noidle(m_mpd));

    if (!mpd_send_list_queue_meta(m_mpd)) {
        qDebug() << mpd_connection_get_error_message(m_mpd);
    }

    struct mpd_song *song = nullptr;
    while ((song = mpd_recv_song(m_mpd)) != nullptr) {
        songs.push_back(new MPDSong(song));
    };

    m_notifier->setEnabled(true);
    mpd_send_idle(m_mpd);

    return songs;
}
