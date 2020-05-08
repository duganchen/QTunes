#ifndef ABSTRACTMPDSONG_H
#define ABSTRACTMPDSONG_H

#include <QObject>

class AbstractMPDSong : public QObject
{
    Q_OBJECT
public:
    explicit AbstractMPDSong(QObject *parent = nullptr);

signals:

};

#endif // ABSTRACTMPDSONG_H
