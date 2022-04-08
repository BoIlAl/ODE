#pragma once
#include "modelObj.h"
#include <QGraphicsScene>

class Arrow {
public:

    Arrow(AbsModelObj *startItem, AbsModelObj *endItem);

    void paint(QGraphicsScene* scene);
private:
    AbsModelObj *startItem_;
    AbsModelObj *endItem_;
    QVector<QGraphicsLineItem*> lines_;
};