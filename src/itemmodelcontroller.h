#ifndef ITEMMODELCONTROLLER_H
#define ITEMMODELCONTROLLER_H

#include <QObject>

class ItemModelController : public QObject
{
	Q_OBJECT
public:
	explicit ItemModelController(QObject *parent = nullptr);

	void beginRemoveRows(int, int);
	void endRemoveRows();
signals:
	void aboutToBeReset();
	void reset();
	void rowsAboutToBeRemoved(const QModelIndex &, int, int);
	void rowsRemoved();
};

#endif // ITEMMODELCONTROLLER_H
