#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>

class MPDModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit MPDModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

private:
    QVector<QString> m_items;
};

#endif // LISTMODEL_H
