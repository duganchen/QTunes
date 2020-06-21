#include "itemmodelcontroller.h"
#include <QModelIndex>
#include <QtAlgorithms>

ItemModelController::ItemModelController(QObject *parent)
    : QObject(parent)
{}

void ItemModelController::beginRemoveRows(int first, int last)
{
    emit rowsAboutToBeRemoved(QModelIndex(), first, last);
}

void ItemModelController::endRemoveRows()
{
    emit rowsRemoved();
}

ItemModelController::~ItemModelController()
{
    qDeleteAll(items);
}

void ItemModelController::clear()
{
    beginRemoveRows(0, items.size() - 1);
    qDeleteAll(items);
    m_queue->items.clear();
    m_queue->endRemoveRows();
}
