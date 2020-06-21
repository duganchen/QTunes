#ifndef PANEMODEL_H
#define PANEMODEL_H

#include <QAbstractListModel>
#include "itemmodelcontroller.h"

class PaneModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PaneModel(ItemModelController *controller, QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

private:
    ItemModelController *m_controller;
};

#endif // PANEMODEL_H
