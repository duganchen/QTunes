#ifndef SONGMODEL_H
#define SONGMODEL_H

#include <QAbstractListModel>

class SongModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit SongModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    virtual QHash<int, QByteArray> roleNames() const override;
};


#endif // SONGMODEL_H
