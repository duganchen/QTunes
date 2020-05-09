#ifndef PANEMODEL_H
#define PANEMODEL_H

#include "abstractitem.h"
#include <QAbstractListModel>

class PaneModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(QVector<AbstractItem *> items READ list WRITE setList NOTIFY listChanged)

public:
    explicit PaneModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVector<AbstractItem *> list() const;
    void setList(QVector<AbstractItem *>);

    virtual QHash<int, QByteArray> roleNames() const override;

signals:
    void listChanged();

private:
    QVector<AbstractItem *> m_list;
};

#endif // PANEMODEL_H
