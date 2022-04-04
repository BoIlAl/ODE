#include "graphicsManager.h"

GraphicsManager::GraphicsManager(){

}

/*void GraphicsManager::setupGView(QGraphicsView *gView)
{
    gView->setScene(scene_);
    scene_->setSceneRect(gView->rect());
    /*
    gView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    */
//}

void GraphicsManager::addObj(const QJsonObject &data) {
    auto newItem = AbsModelObj::createFromJson(data);
    addItem(newItem);
    elems_.append(newItem);
    update();
}

void GraphicsManager::redraw() const {

}

void GraphicsManager::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);

    if (event->buttons() & Qt::LeftButton) {
        //itemAt(event->lastScenePos(), QTransform())->setPos(event->scenePos());
        for (auto elem : elems_)
            if(elem->move(event))
                break;
        update();
    }
}