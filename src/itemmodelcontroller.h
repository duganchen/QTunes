#ifndef ITEMMODELCONTROLLER_H
#define ITEMMODELCONTROLLER_H

#include "abstractitem.h"
#include <QObject>

class ItemModelController : public QObject
{
    Q_OBJECT
public:
    explicit ItemModelController(QObject *parent = nullptr);

    void beginRemoveRows(int, int);
    void endRemoveRows();

    QVector<AbstractItem *> items;

    ~ItemModelController();

signals:
    void aboutToBeReset();
    void reset();
    void rowsAboutToBeRemoved(const QModelIndex &, int, int);
    void rowsRemoved();
};

#endif // ITEMMODELCONTROLLER_H
