#include "mpdsong.h"

MPDSong::MPDSong(mpd_song *song)
    : m_song(song)
{}

bool MPDSong::isNull()
{
    return m_song == nullptr;
}

MPDSong::MPDSong(const MPDSong &other)
    : AbstractMPDSong()
{
    m_song = mpd_song_dup(other.m_song);
}

MPDSong::MPDSong(MPDSong &&other)
    : m_song{other.m_song}
{
    other.m_song = nullptr;
}

MPDSong &MPDSong::operator=(const MPDSong &other)
{
    m_song = mpd_song_dup(other.m_song);
    return *this;
}

MPDSong &MPDSong::operator=(MPDSong &&other)
{
    m_song = other.m_song;
    other.m_song = nullptr;
    return *this;
}

MPDSong::~MPDSong()
{
    if (m_song) {
        mpd_song_free(m_song);
    }
}
