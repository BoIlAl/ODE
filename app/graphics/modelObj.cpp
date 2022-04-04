#include "modelObj.h"
#include <stdlib.h>

class ClassModelObj : public AbsModelObj {
private:
    QVector<QString> attributes_;
    QVector<QString> operations_;
    QVector<QPair<QString, RelType>> relations_;
public:

    static ClassModelObj* parseClass(const QJsonObject & obj);
 
    RelType getRelType(const QString& name) const override;
};

class ActivityModelObj : public AbsModelObj {
private:
    QVector<QPair<QString, RelType>> relations_;
public:

    static ActivityModelObj* parseActivity(const QJsonObject & obj);

    RelType getRelType(const QString& name) const override;
};

class EnumModelObj : public AbsModelObj {
private:
    QVector<QString> literals_;
public:

    static EnumModelObj* parseEnum(const QJsonObject & obj);

    RelType getRelType(const QString& name) const override;
};

ClassModelObj* ClassModelObj::parseClass(const QJsonObject & obj) {
    ClassModelObj* newModelObj = new ClassModelObj();

    newModelObj->name_ = obj["name"].toString();

    for(auto key: obj.keys()) {
        if (key == "attributes") {
            QJsonArray jsonArr = obj[key].toArray();
            for (int i; i < jsonArr.size(); ++i) {
                newModelObj->attributes_.append(jsonArr[i].toString());
            }
        } else if (key == "operations") {
            QJsonArray jsonArr = obj[key].toArray();
            for (int i; i < jsonArr.size(); ++i) {
                newModelObj->operations_.append(jsonArr[i].toString());
            }
        } else if (key == "generalization") {
            QJsonArray jsonArr = obj[key].toArray();
            for (int i; i < jsonArr.size(); ++i) {
                newModelObj->relations_.append({jsonArr[i].toString(), RT_GENERALIZATION});
            }
        } else if (key == "composition") {
            newModelObj->relations_.append({obj[key].toString(), RT_COMPOSITION});
        } else if (key == "aggregation") {
            newModelObj->relations_.append({obj[key].toString(), RT_AGGREGATION});
        } else if (key == "dependency") {
            newModelObj->relations_.append({obj[key].toString(), RT_DEPENDENCY});
        } else if (key == "implementation") {
            newModelObj->relations_.append({obj[key].toString(), RT_IMPLEMENTATION});
        } else if (key == "comment") {
            ////////Адский Говно Код
        } 
    }

    QGraphicsTextItem text(newModelObj->name_, newModelObj);

    newModelObj->setRect(-200, -240, 100, 100);
    return newModelObj;
}

ActivityModelObj* ActivityModelObj::parseActivity(const QJsonObject & obj) {
    ActivityModelObj* newModelObj = new ActivityModelObj();

    newModelObj->name_ = obj["name"].toString();

    for(auto key: obj.keys()) {
        if (key == "in") {
            QJsonArray jsonArr = obj[key].toArray();
            for (int i; i < jsonArr.size(); ++i) {
                newModelObj->relations_.append({jsonArr[i].toString(), RT_ACT_IN});
            }
        } else if (key == "out") {
            QJsonArray jsonArr = obj[key].toArray();
            for (int i; i < jsonArr.size(); ++i) {
                newModelObj->relations_.append({jsonArr[i].toString(), RT_ACT_OUT});
            }
        } else if (key == "generalization") {
            QJsonArray jsonArr = obj[key].toArray();
            for (int i; i < jsonArr.size(); ++i) {
                newModelObj->relations_.append({jsonArr[i].toString(), RT_GENERALIZATION});
            }
        } else if (key == "composition") {
            newModelObj->relations_.append({obj[key].toString(), RT_COMPOSITION});
        } else if (key == "aggregation") {
            newModelObj->relations_.append({obj[key].toString(), RT_AGGREGATION});
        } else if (key == "dependency") {
            newModelObj->relations_.append({obj[key].toString(), RT_DEPENDENCY});
        } else if (key == "implementation") {
            newModelObj->relations_.append({obj[key].toString(), RT_IMPLEMENTATION});
        } else if (key == "comment") {
            ////////Адский Говно Код
        } 
    }

    QGraphicsTextItem text(newModelObj->name_, newModelObj);

    newModelObj->setRect(-200, -240, 100, 100);
    return newModelObj;
}
EnumModelObj* EnumModelObj::parseEnum(const QJsonObject & obj) {
    EnumModelObj* newModelObj = new EnumModelObj();

    newModelObj->name_ = obj["name"].toString();

    QGraphicsTextItem text(newModelObj->name_, newModelObj);

    newModelObj->setRect(-200, -240, 100, 100);
    return newModelObj;
}

RelType ClassModelObj::getRelType(const QString& name) const {
    for (int i; i < relations_.size(); ++i) {
        if (relations_[i].first == name) {
            return relations_[i].second;
        }
    }
    return RT_NONE;
}

RelType ActivityModelObj::getRelType(const QString& name) const {
    for (int i; i < relations_.size(); ++i) {
        if (relations_[i].first == name) {
            return relations_[i].second;
        }
    }
    return RT_NONE;
}

RelType EnumModelObj::getRelType(const QString& name) const {
    return RT_NONE;
}

AbsModelObj *AbsModelObj::createFromJson(const QJsonObject & obj)
{
    if (obj["type"].toString() == "Class") {
        return ClassModelObj::parseClass(obj);
    } 
    else if (obj["type"].toString() == "Activity") {
        return ActivityModelObj::parseActivity(obj);
    } 
    else if (obj["type"].toString() == "Enumeration") {
        return EnumModelObj::parseEnum(obj);
    } 
    else {
        ///////////////
        return nullptr;
    }
}
