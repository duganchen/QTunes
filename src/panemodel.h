#ifndef PANEMODEL_H
#define PANEMODEL_H

#include "abstractitem.h"
#include <QAbstractListModel>

class PaneModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit PaneModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void setList(QVector<AbstractItem *> *);

    virtual QHash<int, QByteArray> roleNames() const override;

signals:
    void listChanged();

private:
    QVector<AbstractItem *> *m_list;
};

#endif // PANEMODEL_H
