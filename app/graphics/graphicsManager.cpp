#include "graphicsManager.h"

GraphicsManager::GraphicsManager() : scene_(new QGraphicsScene) {

}

void GraphicsManager::setupGView(QGraphicsView *gView)
{
    gView->setScene(scene_);
    scene_->setSceneRect(gView->rect());
    /*
    gView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    */
}

void GraphicsManager::addObj(const QJsonObject &data) {
    auto newItem = AbsModelObj::createFromJson(data);
    scene_->addItem(newItem);
    scene_->update();
}

void GraphicsManager::redraw() const {

}
