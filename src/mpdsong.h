#ifndef MPDSONG_H
#define MPDSONG_H

#include "abstractmpdsong.h"
#include <QObject>
#include <mpd/client.h>

class MPDSong : public AbstractMPDSong
{
    Q_OBJECT
public:
    explicit MPDSong(mpd_song *song, QObject *parent = nullptr);
    ~MPDSong();

private:
    mpd_song *m_song;
};

#endif // MPDSONG_H
