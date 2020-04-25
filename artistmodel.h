#ifndef ARTISTMODEL_H
#define ARTISTMODEL_H

#include <QAbstractListModel>

class ArtistModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ArtistModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    virtual QHash<int, QByteArray> roleNames() const override;
};

#endif // LISTMODEL_H
