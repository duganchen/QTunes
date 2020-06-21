#ifndef ABSTRACTITEM_H
#define ABSTRACTITEM_H

#include <QObject>
#include <QString>

class AbstractItem: public QObject
{
public:
    explicit AbstractItem(QObject *parent = nullptr): QObject(parent) {}
    virtual QString data() = 0;
    virtual ~AbstractItem() {}
};

#endif // ABSTRACTITEM_H
