#include "panemodel.h"
#include <QtAlgorithms>

PaneModel::PaneModel(QObject *parent) : QAbstractListModel(parent)
{
}

PaneModel::~PaneModel()
{
    qDeleteAll(m_list.begin(), m_list.end());
    m_list.clear();
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

    return m_list[index.row()]->data();
}

QVector<AbstractItem *> PaneModel::list() const
{
    return m_list;
}

void PaneModel::setList(QVector<AbstractItem *> list)
{
    qDeleteAll(m_list.begin(), m_list.end());
    m_list.clear();

    for (auto item : list)
    {
        m_list.push_back(item);
    }
}

QHash<int, QByteArray> PaneModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::DisplayRole] = "value";
    return roles;
}
