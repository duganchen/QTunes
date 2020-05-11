#include "tagitem.h"

TagItem::TagItem(const char *tag) : m_tag(tag)
{
}

const char *TagItem::data()
{
    return m_tag;
}
