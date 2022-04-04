#pragma once

#include <QString>
#include <QGraphicsItem>
#include <QJsonObject>
#include <QJsonArray>
#include <QGraphicsSceneMouseEvent>

enum RelType {
    RT_GENERALIZATION,
    RT_AGGREGATION,
    RT_COMPOSITION,
    RT_ACT_IN,
    RT_ACT_OUT,
    RT_DEPENDENCY,
    RT_IMPLEMENTATION,
    RT_ASSOCIATION,
    RT_NONE
};

class AbsModelObj : public QGraphicsRectItem {
protected:
    QString name_;
    QGraphicsTextItem* text;

public:
    static AbsModelObj *createFromJson(const QJsonObject&);

    QString getName() const;

    virtual RelType getRelType(const QString& name) const = 0;

    bool move(QGraphicsSceneMouseEvent* event);

};