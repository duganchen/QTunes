#ifndef MPDSONG_H
#define MPDSONG_H

#include "abstractmpdsong.h"
#include <mpd/client.h>

class MPDSong : public AbstractMPDSong
{
public:
    explicit MPDSong(mpd_song *song);
    bool isNull() override;

    MPDSong(const MPDSong &);
    MPDSong(MPDSong &&);
    MPDSong &operator=(const MPDSong &);
    MPDSong &operator=(MPDSong &&);
    ~MPDSong() override;

private:
    mpd_song *m_song;
};

#endif // MPDSONG_H
