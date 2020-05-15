#ifndef ABSTRACTMPDSONG_H
#define ABSTRACTMPDSONG_H

class AbstractMPDSong
{
public:
    virtual ~AbstractMPDSong(){};
    virtual bool isNull() = 0;
};

#endif // ABSTRACTMPDSONG_H
