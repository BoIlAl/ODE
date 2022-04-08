#include "graphicsManager.h"

void GraphicsManager::addArrows(AbsModelObj* obj) {
    for(int i = 0; i < elems_.size(); ++i) {
        Arrow* newArrow;
        if (obj->getRelType(elems_[i]->getName()) == RT_NONE && elems_[i]->getRelType(obj->getName()) == RT_NONE) {
            continue;
        } else if (obj->getRelType(elems_[i]->getName()) != RT_NONE) {
            if (obj->getRelType(elems_[i]->getName()) == RT_ACT_OUT || obj->getRelType(elems_[i]->getName()) == RT_GENERALIZATION) {
                newArrow = new Arrow(obj, elems_[i]); 
            } else {
                newArrow = new Arrow(elems_[i], obj); 
            }
        } else {
            if (elems_[i]->getRelType(obj->getName()) == RT_ACT_OUT || elems_[i]->getRelType(obj->getName()) == RT_GENERALIZATION) {
                newArrow = new Arrow(elems_[i], obj);
            } else {
                newArrow = new Arrow(obj, elems_[i]);
            }
        }
        newArrow->paint(this);
        arrows_.append(newArrow);
    }
}


void GraphicsManager::addObj(const QJsonObject &data) {
    auto newItem = AbsModelObj::createFromJson(data);

    for (int i = 0; i < elems_.size(); i++) {
        if (newItem->getName() == elems_[i]->getName()) {
            delete newItem;
            return;
        }
    }

    addItem(newItem);
    addArrows(newItem);
    elems_.append(newItem);
    update();
}

void GraphicsManager::updateArrows() {
    for (int i = 0; i < arrows_.size(); ++i) {
        arrows_[i]->paint(this);
    }
}

void GraphicsManager::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    
    if (event->buttons() & Qt::LeftButton) {
        for (int i = 0; i < elems_.size(); i++) {
            if(elems_[i]->move(event)) {
                if (i != 0) {
                    auto ptr = elems_[i];
                    elems_.remove(i);
                    elems_.push_front(ptr);
                }
                break;
            }
        }
        updateArrows();
        update();
    }
}

GraphicsManager::~GraphicsManager(){
    for(int i = 0; i < elems_.size(); ++i) {
        delete elems_[i];
    }
    for(int i = 0; i < elems_.size(); ++i) {
        delete arrows_[i];
    }
}