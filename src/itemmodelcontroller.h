#ifndef ITEMMODELCONTROLLER_H
#define ITEMMODELCONTROLLER_H

#include <QObject>

class ItemModelController : public QObject
{
	Q_OBJECT
public:
	explicit ItemModelController(QObject *parent = nullptr);

	void beginReset();
	void endReset();
signals:
	void aboutToBeReset();
	void reset();
};

#endif // ITEMMODELCONTROLLER_H
