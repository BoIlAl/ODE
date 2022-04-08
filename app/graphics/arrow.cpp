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

    if (lines_[0]->isVisible() == false) {
        for(int i = 0; i < lines_.size(); ++i) {
            lines_[i]->setVisible(true);
        }
    }

    float x, y;
 
    const float ostr = 0.25;
 
    QPointF start = startItem_->rect().center();
    QPointF end = endItem_->rect().center();
    float x1 = startItem_->scenePos().x() + start.x();
    float y1 = startItem_->scenePos().y() + start.y();
    float x2 = endItem_->scenePos().x() + end.x();
    float y2 = endItem_->scenePos().y() + end.y();

    lines_[0]->setLine(x1, y1, x2, y2);
 
    x = x2 - x1;
    y = x2 - y1;

    float lons, ugol;
    lons = sqrt(x*x + y*y) / 7;
    ugol = atan2(y, x);
 
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