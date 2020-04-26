#ifndef ALBUMMODEL_H
#define ALBUMMODEL_H

#include <QAbstractListModel>

class AlbumModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit AlbumModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    virtual QHash<int, QByteArray> roleNames() const override;
private:
};

#endif // ALBUMMODEL_H
