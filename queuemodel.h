#ifndef QUEUEMODEL_H
#define QUEUEMODEL_H

#include <QAbstractListModel>

class QueueModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit QueueModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    virtual QHash<int, QByteArray> roleNames() const override;
};

#endif // QUEUEMODEL_H
