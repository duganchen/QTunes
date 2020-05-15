#ifndef PANEMODEL_H
#define PANEMODEL_H

#include "abstractitem.h"
#include "itemmodelcontroller.h"
#include <QAbstractListModel>

class PaneModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit PaneModel(ItemModelController *, QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

private:
    const ItemModelController *m_controller;
};

#endif // PANEMODEL_H
