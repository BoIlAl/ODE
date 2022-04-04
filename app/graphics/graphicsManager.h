#pragma once

#include <QString>
#include <vector>
#include <QGraphicsView>
#include "modelObj.h"

class GraphicsManager : public QGraphicsScene {
private:
    QVector<AbsModelObj*> elems_;

    //QGraphicsScene* scene_;
public:
    GraphicsManager();

    //void setupGView(QGraphicsView* gView);
    void addObj(const QJsonObject& data);
    void redraw() const;

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};