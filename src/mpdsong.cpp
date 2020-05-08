#include "mpdsong.h"

MPDSong::MPDSong(mpd_song *song, QObject *parent) : AbstractMPDSong(parent), m_song(song)
{
}

MPDSong::~MPDSong()
{
    mpd_song_free(m_song);
}
