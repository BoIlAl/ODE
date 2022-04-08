#include "modelObj.h"

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

    newModelObj->setBrush(QColor(224, 207, 177));

    newModelObj->name_ = obj["name"].toString();

    for(auto key: obj.keys()) {
        if (key == "attributes") {
            QJsonArray jsonArr = obj[key].toArray();
            for (int i = 0; i < jsonArr.size(); ++i) {
                newModelObj->attributes_.append(jsonArr[i].toString());
            }
        } else if (key == "operations") {
            QJsonArray jsonArr = obj[key].toArray();
            for (int i = 0; i < jsonArr.size(); ++i) {
                newModelObj->operations_.append(jsonArr[i].toString());
            }
        } else if (key == "generalization") {
            QJsonArray jsonArr = obj[key].toArray();
            for (int i = 0 ; i < jsonArr.size(); ++i) {
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

    newModelObj->setText();

    return newModelObj;
}

ActivityModelObj* ActivityModelObj::parseActivity(const QJsonObject & obj) {
    ActivityModelObj* newModelObj = new ActivityModelObj();

    newModelObj->setBrush(QColor(152, 255, 152));

    newModelObj->name_ = obj["name"].toString();

    for(auto key: obj.keys()) {
        if (key == "input") {
            QJsonArray jsonArr = obj[key].toArray();
            for (int i = 0; i < jsonArr.size(); ++i) {
                newModelObj->relations_.append({jsonArr[i].toString(), RT_ACT_IN});
            }
        } else if (key == "output") {
            QJsonArray jsonArr = obj[key].toArray();
            for (int i = 0; i < jsonArr.size(); ++i) {
                newModelObj->relations_.append({jsonArr[i].toString(), RT_ACT_OUT});
            }
        } else if (key == "generalization") {
            QJsonArray jsonArr = obj[key].toArray();
            for (int i = 0; i < jsonArr.size(); ++i) {
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

    newModelObj->setText();

    return newModelObj;
}
EnumModelObj* EnumModelObj::parseEnum(const QJsonObject & obj) {
    EnumModelObj* newModelObj = new EnumModelObj();

    newModelObj->name_ = obj["name"].toString();

    newModelObj->setText();
    
    return newModelObj;
}

RelType ClassModelObj::getRelType(const QString& name) const {
    for (int i = 0; i < relations_.size(); ++i) {
        if (relations_[i].first == name) {
            return relations_[i].second;
        }
    }
    return RT_NONE;
}

RelType EnumModelObj::getRelType(const QString& name) const {
    return RT_NONE;
}

RelType ActivityModelObj::getRelType(const QString& name) const {
    for (auto const& relation : relations_){
        if (relation.first == name)
            return relation.second;
    }
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

bool AbsModelObj::move(QGraphicsSceneMouseEvent *event)
{
    if (rect().contains(event->lastScenePos()-pos())){
        auto d = event->scenePos() - event->lastScenePos();
        setPos(pos() + d);
        
        return true;
    }
    return false;
}

QString AbsModelObj::getName() const {
    return name_;
}

void AbsModelObj::setText()
{
    text_ = new QGraphicsTextItem(name_, this);
    setRect(text_->boundingRect());
    setPos(0, 0);
}

AbsModelObj::~AbsModelObj()
{
    delete text_;
}