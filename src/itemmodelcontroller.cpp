#include "itemmodelcontroller.h"
#include <QModelIndex>

ItemModelController::ItemModelController(QObject *parent) : QObject(parent)
{
}

void ItemModelController::beginRemoveRows(int first, int last)
{
	emit rowsAboutToBeRemoved(QModelIndex(), first, last);
}

void ItemModelController::endRemoveRows()
{
	emit rowsRemoved();
}
