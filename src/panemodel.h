#ifndef PANEMODEL_H
#define PANEMODEL_H

#include <QAbstractListModel>

class PaneModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(QVector<QString> items READ list WRITE setList NOTIFY listChanged)

public:
    explicit PaneModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVector<QString> list() const;
    void setList(QVector<QString>);

    virtual QHash<int, QByteArray> roleNames() const override;

signals:
    void listChanged();

private:
    QVector<QString> m_list;
};

#endif // PANEMODEL_H
