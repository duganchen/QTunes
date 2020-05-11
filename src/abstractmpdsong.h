#ifndef ABSTRACTMPDSONG_H
#define ABSTRACTMPDSONG_H

#include <QObject>

class AbstractMPDSong : public QObject
{
    Q_OBJECT
public:
    explicit AbstractMPDSong(QObject *parent = nullptr);
    virtual ~AbstractMPDSong(){};
    virtual bool isNull() = 0;
};

#endif // ABSTRACTMPDSONG_H
