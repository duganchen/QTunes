#ifndef ABSTRACTMPDCONNECTION_H
#define ABSTRACTMPDCONNECTION_H

#include <QObject>

class AbstractMPDConnection : public QObject
{
    Q_OBJECT
public:
    explicit AbstractMPDConnection(const char *host, unsigned port, unsigned timeout_ms, QObject *parent = nullptr);
    virtual bool isNull() const = 0;
};

#endif // ABSTRACTMPDCONNECTION_H
