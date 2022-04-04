#pragma once

#include <QString>
#include <QGraphicsItem>
#include <vector>

enum RelType {
    RT_GENERALIZATION,
    RT_AGGREGATION,
    RT_COMPOSITION,
    RT_ACT_IN,
    RT_ACT_OUT,
    RT_DEPENDENCE,
    RT_IMPLEMENTATION,
    RT_ASSOCIATION,
    RT_NONE
};

class AbsModelObj : public QGraphicsRectItem {
private:
    QString name_;
protected:
    explicit AbsModelObj(const QString& name);
public:
    static AbsModelObj *createFromJson(const QJsonObject &);

    QString getName() const;

    virtual RelType getRelType(const QString& name) const = 0;
};