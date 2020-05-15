#ifndef ITEMMODELDATA_H
#define ITEMMODELDATA_H

#include "abstractitem.h"
#include "itemmodelcontroller.h"
#include <QVector>

struct ItemModelData
{
	ItemModelData(QVector<AbstractItem *> &, ItemModelController *);
	QVector<AbstractItem *> &items;
	ItemModelController *controller;
};

#endif // ITEMMODELDATA_H
