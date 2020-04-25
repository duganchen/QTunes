#include "listmodel.h"

MPDModel::MPDModel(QObject *parent)
    : QAbstractListModel(parent)
{
    QVector<QString> m_items {
        "artist 1",
        "artist 2",
        "artist 3"
    };
}

int MPDModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return 3;
}

QVariant MPDModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role);

    if (!index.isValid())
        return QVariant();

    if (index.row() > 2)
    {
        return QVariant();
    }

    return "artist " + QString::number(index.row() + 1);
}


QHash<int, QByteArray> MPDModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::DisplayRole] = "value";
    return roles;
}
