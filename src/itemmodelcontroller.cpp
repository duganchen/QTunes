#include "itemmodelcontroller.h"

ItemModelController::ItemModelController(QObject *parent) : QObject(parent)
{
}

void ItemModelController::beginReset()
{
	emit aboutToBeReset();
}

void ItemModelController::endReset()
{
	emit reset();
}
