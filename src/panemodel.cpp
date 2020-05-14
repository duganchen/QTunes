#include "panemodel.h"
#include <QtAlgorithms>

PaneModel::PaneModel(const QVector<AbstractItem *> &list, ItemModelController *controller, QObject *parent)
	: QAbstractListModel(parent), m_list(list)
{
	controller->setParent(this);
	QObject::connect(controller, &ItemModelController::aboutToBeReset, this, &PaneModel::beginResetModel);
	QObject::connect(controller, &ItemModelController::reset, this, &PaneModel::endResetModel);
}

int PaneModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
	if (parent.isValid())
        return 0;

	return m_list.size();
}

QVariant PaneModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role)

	if (!index.isValid())
    {
        return QVariant();
    }

	if (m_list.size() - 1 < index.row())
    {
        return QVariant();
    }

	return m_list.at(index.row())->data();
}

QHash<int, QByteArray> PaneModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::DisplayRole] = "value";
    return roles;
}
