#pragma once
#include "modelObj.h"
#include <QGraphicsScene>

class Arrow {
public:

    Arrow(AbsModelObj *startItem, AbsModelObj *endItem);

    void paint(QGraphicsScene* scene);

private:

    QPointF getLinePoint(const QRectF &itemRect1, const QRectF &itemRect2);

    AbsModelObj *startItem_;

    AbsModelObj *endItem_;

    QVector<QGraphicsLineItem*> lines_;
};