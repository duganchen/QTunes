#include "itemmodeldata.h"

ItemModelData::ItemModelData(QVector<AbstractItem *> &vec, ItemModelController *cntlr) : items(vec), controller(cntlr)
{
}
