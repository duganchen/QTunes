#include "albummodel.h"

AlbumModel::AlbumModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int AlbumModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return 3;
}

QVariant AlbumModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role);

    if (!index.isValid())
        return QVariant();

    if (index.row() > 2)
    {
        return QVariant();
    }

    return "Song " + QString::number(index.row() + 1);
}


QHash<int, QByteArray> AlbumModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::DisplayRole] = "value";
    return roles;
}
