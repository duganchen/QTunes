#ifndef ABSTRACTITEM_H
#define ABSTRACTITEM_H

class AbstractItem
{
public:
    virtual const char *data() = 0;
    virtual ~AbstractItem() {}
};

#endif // ABSTRACTITEM_H
