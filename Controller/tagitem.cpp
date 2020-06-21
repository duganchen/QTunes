#include "tagitem.h"
#include <QDebug>

TagItem::TagItem(QString tag, QObject * parent)
    : AbstractItem(parent), m_tag(tag)
{}

QString TagItem::data()
{
    return m_tag;
}
