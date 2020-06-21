#ifndef TAGITEM_H

#include "abstractitem.h"
#include <QString>

class TagItem : public AbstractItem
{
public:
    explicit TagItem(QString, QObject *parent = nullptr);
    virtual QString data();
    virtual ~TagItem() {}

private:
    QString m_tag;
};

#define TAGITEM_H
#endif
