#ifndef TAGITEM_H
#define TAGITEM_H

#include "abstractitem.h"

class TagItem : public AbstractItem
{
public:
    TagItem(const char *);
    const char *data() override;

private:
    const char *m_tag;
};

#endif // TAGITEM_H
