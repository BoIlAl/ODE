#pragma once

#include <QString>
#include <vector>
#include <QGraphicsView>
#include "modelObj.h"
#include "arrow.h"

class GraphicsManager : public QGraphicsScene {
private:
    QVector<AbsModelObj*> elems_;

    QVector<Arrow*> arrows_;

    void addArrows(AbsModelObj* obj);
    void updateArrows();

public:

    void addObj(const QJsonObject& data);

    ~GraphicsManager();
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};