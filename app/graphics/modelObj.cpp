#include "modelObj.h"

class ClassModelObj : public AbsModelObj {
private:
    std::vector<QString> attributes_;
    std::vector<QString> operations_;
    std::vector<QString, RelType> relations_;
public:
    ClassModelObj(const QString& name, const std::vector<QString>&, const std::vector<QString>&, const std::vector<QString, RelType>&);
 
    RelType getRelType(const QString& name) const override;
};

class ActivityModelObj : public AbsModelObj {
private:
    std::vector<QString, RelType> relations_;
public:
    ActivityModelObj(const QString&, const std::vector<QString, RelType>&);

    RelType getRelType(const QString& name) const override;
};

class enumModelObj : public AbsModelObj {
private:
    std::vector<QString> literals_;
public:
    enumModelObj(const QString&, const std::vector<QString>&);

    RelType getRelType(const QString& name) const override;
};