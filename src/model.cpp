#include "model.h"
#include <QDebug>

Model::Model(QObject *parent) : QObject(parent)
{
}

void Model::printStuff()
{
	qDebug() << "The button was clicked";
}
