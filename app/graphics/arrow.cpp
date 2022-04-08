#include "arrow.h"
#include <math.h>

const qreal Pi = 3.14;

Arrow::Arrow(AbsModelObj *startItem, AbsModelObj *endItem) {
    startItem_ = startItem;
    endItem_ = endItem;
    lines_.append(new QGraphicsLineItem());
    lines_.append(new QGraphicsLineItem());
    lines_.append(new QGraphicsLineItem());
}

void Arrow::paint(QGraphicsScene* scene) {
    if (startItem_->collidesWithItem(endItem_)) {
        for(int i = 0; i < lines_.size(); ++i) {
            lines_[i]->setVisible(false);
        }
        return;
    }

    if (!lines_[0]->isVisible()) {
        for(int i = 0; i < lines_.size(); ++i) {
            lines_[i]->setVisible(true);
        }
    }

    QPointF start = getLinePoint(startItem_->sceneBoundingRect(), endItem_->sceneBoundingRect());
    QPointF end = getLinePoint(endItem_->sceneBoundingRect(), startItem_->sceneBoundingRect());

    float x1 = start.x(), y1 = start.y();
    float x2 = end.x(), y2 = end.y();

    lines_[0]->setLine(x1, y1, x2, y2);

    const float
    lons = 15,
    ostr = 0.4;

    float x = x2 -x1, y = y2 - y1;
    float ugol = atan2(y, x);
 
    float f1x2 , f1y2;
    f1x2 = x2 - lons * cos(ugol - ostr);
    f1y2 = y2 - lons * sin(ugol - ostr);

    lines_[1]->setLine(x2, y2, f1x2, f1y2);
 
    f1x2 = x2 - lons * cos(ugol + ostr);
    f1y2 = y2 - lons * sin(ugol + ostr);

    lines_[2]->setLine(x2, y2, f1x2, f1y2);

    if (lines_[0]->scene() == nullptr) {
        for(int i = 0; i < lines_.size(); ++i) {
            scene->addItem(lines_[i]);
        }
    }
}

QPointF Arrow::getLinePoint(const QRectF &itemRect1, const QRectF &itemRect2) {
    QLineF conLine(itemRect1.center(), itemRect2.center());
    QPointF resultPoint;
    auto checkLine = [&](QLineF const& rectLine){
        if (conLine.intersect(rectLine, &resultPoint) == QLineF::BoundedIntersection)
            return true;
        return false;
    };

    if (checkLine(QLineF(itemRect1.topRight(), itemRect1.bottomRight())))
        return resultPoint;
    if (checkLine(QLineF(itemRect1.bottomRight(), itemRect1.bottomLeft())))
        return resultPoint;
    if (checkLine(QLineF(itemRect1.bottomLeft(), itemRect1.topLeft())))
        return resultPoint;
    if (checkLine(QLineF(itemRect1.topLeft(), itemRect1.topRight())))
        return resultPoint;

    return QPointF();
}
