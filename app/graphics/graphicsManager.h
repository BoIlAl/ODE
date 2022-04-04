#pragma once

#include <QString>
#include <vector>
#include <QGraphicsView>
#include "modelObj.h"

class GraphicsManager {
private:
    std::vector<AbsModelObj*> elems_;
public:
    GraphicsManager(QGraphicsView* view);

    void addObj(const QJsonObject& name);
    void redraw() const;
};