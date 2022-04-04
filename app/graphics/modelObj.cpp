#include "modelObj.h"
#include <stdlib.h>

class ClassModelObj : public AbsModelObj {
private:
    std::vector<QString> attributes_;
    std::vector<QString> operations_;
    //std::vector<QString, RelType> relations_;
public:
    ClassModelObj();

    //ClassModelObj(const QString& name, const std::vector<QString>&, const std::vector<QString>&, const std::vector<QString, RelType>&);
 
    RelType getRelType(const QString& name) const override;
};

class ActivityModelObj : public AbsModelObj {
private:
    //std::vector<QString, RelType> relations_;
public:
    ActivityModelObj(const QString&, const std::vector<QString, RelType>&);

    RelType getRelType(const QString& name) const override;
};

class enumModelObj : public AbsModelObj {
private:
    //std::vector<QString> literals_;
public:
    enumModelObj(const QString&, const std::vector<QString>&);

    RelType getRelType(const QString& name) const override;
};

ClassModelObj::ClassModelObj() : AbsModelObj("djkdjalwj") {

}

RelType ClassModelObj::getRelType(const QString &name) const {
    return RT_AGGREGATION;
}

AbsModelObj::AbsModelObj(const QString &name) {

}

AbsModelObj *AbsModelObj::createFromJson(const QJsonObject &)
{
    auto newRect = new ClassModelObj();
    //newRect->setRect(rand() % 200, rand() % 200, rand() % 100 + 50, rand() % 100 + 50);
    newRect->setRect(-200, -200, 100, 100);
    return newRect;
}
