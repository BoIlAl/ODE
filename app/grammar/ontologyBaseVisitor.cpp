#include "ontologyBaseVisitor.h"

ontologyBaseVisitor::ontologyBaseVisitor(Logger* logger) : logger_(logger) {}

bool ontologyBaseVisitor::isUsed(const std::string& str) const {
  int i;
  for (i = 0; i < currUsedObjs_.size(); ++i) {
    if (currUsedObjs_[i] == str) {
      return true;
    }
  }
  return false;
}

void ontologyBaseVisitor::redefCheck() const {
  
  if (defClasses_.size() > 1) {
    for (int i = 0; i < defClasses_.size() - 1; ++i) {
      for (int j = i + 1; j < defClasses_.size(); ++j) {
        if (defClasses_[i] == defClasses_[j]) {
          logger_->log(CompErrorLevel::CEL_ERROR, CompErrorType::CE_REDEF, ("class " + defClasses_[i]).c_str());
        }
      }
    }
  }

  if (defActivities_.size() > 1) {
    for (int i = 0; i < defActivities_.size() - 1; ++i) {
      for (int j = i + 1; j < defActivities_.size(); ++j) {
        if (defActivities_[i] == defActivities_[j]) {
          logger_->log(CompErrorLevel::CEL_ERROR, CompErrorType::CE_REDEF, ("activity " + defActivities_[i]).c_str());
        }
      }
    }
  }
}

QJsonArray ontologyBaseVisitor::createUsedArr(std::vector<std::string> used, std::vector<std::string> def) const {
  QJsonArray usedArr;
  for (int i = 0; i < used.size(); ++i) {
    int j;
    for (j = 0; j < def.size(); ++j) {
      if (used[i] == def[j]) {
        break;
      }
    }
    if (j == def.size()) {
      usedArr.push_back(used[i].c_str());
    }
  }
  return usedArr;
}

QJsonObject ontologyBaseVisitor::getJson(ontologyParser::FileContext *ctx) {

  QJsonObject json = visitFile(ctx).as<QJsonObject>();

  redefCheck();

  QJsonArray usedClassesArr = createUsedArr(usedClasses_, defClasses_);
  if (usedClassesArr.size() > 0) {
    json.insert("Used Сlasses", usedClassesArr);
  }

  QJsonArray usedActivitiesArr = createUsedArr(usedActivities_, defActivities_);
  if (usedActivitiesArr.size() > 0) {
    json.insert("Used Activities", usedActivitiesArr);
  }

  defClasses_.clear();
  usedClasses_.clear();

  defActivities_.clear();
  usedActivities_.clear();

  return json;
}

antlrcpp::Any ontologyBaseVisitor::visitFile(ontologyParser::FileContext *ctx) {
    return visitPackage(ctx->package()).as<QJsonObject>();
}

antlrcpp::Any ontologyBaseVisitor::visitPackage(ontologyParser::PackageContext *ctx) {
    QJsonObject package;

    std::function<antlrcpp::Any(antlr4::ParserRuleContext)> visitFunc;

    currUsedObjs_ = usedClasses_;
    if (!ctx->class_().empty()) {
      QJsonArray classes;
      auto arrClass = ctx->class_();
      for(int i = 0;  i <  arrClass.size(); ++i) {
          classes.push_back(visitClass_(arrClass[i]).as<QJsonObject>());
      }
      package.insert("Class", classes);
    }

    if (!ctx->assoc().empty()) {
      QJsonArray assoc;
      auto arrAssoc = ctx->assoc();
      for(int i = 0;  i <  arrAssoc.size(); ++i) {
          assoc.push_back(visitAssoc(arrAssoc[i]).as<QJsonObject>());
      }
      package.insert("Association", assoc);
    }
    usedClasses_ = currUsedObjs_;

    currUsedObjs_ = usedActivities_;
    if (!ctx->act().empty()) {
      QJsonArray acts;
      auto arrAct = ctx->act();
      for(int i = 0;  i <  arrAct.size(); ++i) {
          acts.push_back(visitAct(arrAct[i]).as<QJsonObject>());
      }
      package.insert("Activity", acts);
    }
    usedActivities_ = currUsedObjs_;

    if (!ctx->enum_().empty()) {
      QJsonArray enums;
      auto arrEnum = ctx->enum_();
      for(int i = 0;  i <  arrEnum.size(); ++i) {
          enums.push_back(visitEnum_(arrEnum[i]).as<QJsonObject>());
      }
      package.insert("Enumeration", enums);
    }

    std::string name = ctx->NAME()->getText();
    package.insert("name", name.substr(1, name.size() - 2).c_str()); 

    return package;
}

antlrcpp::Any ontologyBaseVisitor::visitClass_(ontologyParser::Class_Context *ctx) {
    QJsonObject class_;

    if (ctx->gen() != nullptr) {
      QJsonArray gen;
      std::vector<std::string> arrGen = visitGen(ctx->gen()).as<std::vector<std::string>>();
      for (int i = 0; i < arrGen.size(); ++i) {
        gen.push_back(arrGen[i].c_str());
      }
      class_.insert("generalization", gen);
    }

    if (ctx->attr() != nullptr) {
      QJsonArray attr;
      std::vector<std::string> arrAttr = visitAttr(ctx->attr()).as<std::vector<std::string>>();
      for (int i = 0; i < arrAttr.size(); ++i) {
        attr.push_back(arrAttr[i].c_str());
      }
      class_.insert("attributes", attr);
    }

    if (ctx->oper() != nullptr) {
      QJsonArray oper;
      std::vector<std::string> arrOper = visitOper(ctx->oper()).as<std::vector<std::string>>();
      for (int i = 0; i < arrOper.size(); ++i) {
        oper.push_back(arrOper[i].c_str());
      }
      class_.insert("operations", oper);
    }

    if (ctx->aggr() != nullptr) {
      class_.insert("aggregation", visitAggr(ctx->aggr()).as<std::string>().c_str());
    }

    if (ctx->comp() != nullptr) {
      class_.insert("composition", visitComp(ctx->comp()).as<std::string>().c_str());
    }

    if (ctx->dep() != nullptr) {
      class_.insert("dependency", visitDep(ctx->dep()).as<std::string>().c_str());
    }

    if (ctx->impl() != nullptr) {
      class_.insert("implementation", visitImpl(ctx->impl()).as<std::string>().c_str());
    }

    if (ctx->comm() != nullptr) {
      class_.insert("comment", visitComm(ctx->comm()).as<std::string>().c_str());
    }

    std::string name = ctx->NAME()->getText();
    name = name.substr(1, name.size() - 2);
    defClasses_.push_back(name);
    class_.insert("name", name.c_str());    

    return class_;
}

antlrcpp::Any ontologyBaseVisitor::visitAct(ontologyParser::ActContext *ctx) {
    QJsonObject act;

    if (ctx->gen() != nullptr) {
      QJsonArray gen;
      std::vector<std::string> arrGen = visitGen(ctx->gen()).as<std::vector<std::string>>();
      for (int i = 0; i < arrGen.size(); ++i) {
        gen.push_back(arrGen[i].c_str());
      }
      act.insert("generalization", gen);
    }

    QJsonArray in;
    std::vector<std::string> arrIN = visitIn(ctx->in()).as<std::vector<std::string>>();
    currUsedObjs_ = usedClasses_;
    for (int i = 0; i < arrIN.size(); ++i) {
      in.push_back(arrIN[i].c_str());
    }
    act.insert("input", in);

    QJsonArray out;
    std::vector<std::string> arrOut = visitOut(ctx->out()).as<std::vector<std::string>>();
    for (int i = 0; i < arrOut.size(); ++i) {
      out.push_back(arrOut[i].c_str());
    }
    act.insert("output", out);
    usedClasses_ = currUsedObjs_;

    currUsedObjs_ = usedActivities_;
    if (ctx->aggr() != nullptr) {
      act.insert("aggregation", visitAggr(ctx->aggr()).as<std::string>().c_str());
    }

    if (ctx->comp() != nullptr) {
      act.insert("composition", visitComp(ctx->comp()).as<std::string>().c_str());
    }

    if (ctx->dep() != nullptr) {
      act.insert("dependency", visitDep(ctx->dep()).as<std::string>().c_str());
    }

    if (ctx->impl() != nullptr) {
      act.insert("implementation", visitImpl(ctx->impl()).as<std::string>().c_str());
    }

    if (ctx->comm() != nullptr) {
      act.insert("comment", visitComm(ctx->comm()).as<std::string>().c_str());
    }

    std::string name = ctx->NAME()->getText();
    name = name.substr(1, name.size() - 2);
    defActivities_.push_back(name);
    act.insert("name", name.c_str());
    return act;
}


antlrcpp::Any ontologyBaseVisitor::visitEnum_(ontologyParser::Enum_Context *ctx) {
    QJsonObject enumeration;

    QJsonArray literals;
    std::vector<std::string> arr = visitEnum_literals(ctx->enum_literals()).as<std::vector<std::string>>();
    for (int i = 0; i < arr.size(); ++i) {
      literals.push_back(arr[i].c_str());
    }
    enumeration.insert("literals", literals);

    std::string name = ctx->NAME()->getText();
    enumeration.insert("name", name.substr(1, name.size() - 2).c_str());

    return enumeration;
}

std::vector<std::string> ontologyBaseVisitor::getNames(std::vector<antlr4::tree::TerminalNode*> arr) {
  std::vector<std::string> names;
  std::string name;

  for(int i = 0;  i < arr.size(); ++i) {
      name = arr[i]->getText();
      name = name.substr(1, name.size() - 2);
      if (!isUsed(name)) {
        currUsedObjs_.push_back(name);
      }
      names.push_back(name);
  }
  return names;
}

antlrcpp::Any ontologyBaseVisitor::visitGen(ontologyParser::GenContext *ctx) {
  return getNames(ctx->NAME());
}

antlrcpp::Any ontologyBaseVisitor::visitIn(ontologyParser::InContext *ctx) {
  return getNames(ctx->NAME());
}

antlrcpp::Any ontologyBaseVisitor::visitOut(ontologyParser::OutContext *ctx) {
  return getNames(ctx->NAME());
}

std::vector<std::string> ontologyBaseVisitor::getStrs(std::vector<antlr4::tree::TerminalNode*> arr) {
  std::vector<std::string> strs;
    for(int i = 0;  i <  arr.size(); ++i) {
        std::string str = arr[i]->getText();
        strs.push_back(str.substr(1, str.size() - 2));
    }
    return strs;
}

antlrcpp::Any ontologyBaseVisitor::visitAttr(ontologyParser::AttrContext *ctx) {
  return getStrs(ctx->STRING());
}

antlrcpp::Any ontologyBaseVisitor::visitOper(ontologyParser::OperContext *ctx) {
  return getStrs(ctx->STRING());
}

antlrcpp::Any ontologyBaseVisitor::visitEnum_literals(ontologyParser::Enum_literalsContext *ctx) {
  return getStrs(ctx->STRING());
}

std::string ontologyBaseVisitor::getName(antlr4::tree::TerminalNode* node) {
  std::string name = node->getText();
  name = name.substr(1, name.size() - 2);

  if (!isUsed(name)) {
      currUsedObjs_.push_back(name); 
  }
  return name;
}

antlrcpp::Any ontologyBaseVisitor::visitAssoc(ontologyParser::AssocContext *ctx) {
    QJsonObject assoc;

    std::string name = ctx->STRING()->toString();

    assoc.insert("name", name.substr(1, name.size() - 2).c_str());
    assoc.insert("left", getName(ctx->NAME(0)).c_str());
    assoc.insert("right", getName(ctx->NAME(1)).c_str());
    return assoc;
}

antlrcpp::Any ontologyBaseVisitor::visitAggr(ontologyParser::AggrContext *ctx) {
  return getName(ctx->NAME());
}

antlrcpp::Any ontologyBaseVisitor::visitComp(ontologyParser::CompContext *ctx) {
  return getName(ctx->NAME());
}

antlrcpp::Any ontologyBaseVisitor::visitDep(ontologyParser::DepContext *ctx) {
  return getName(ctx->NAME());
}

antlrcpp::Any ontologyBaseVisitor::visitImpl(ontologyParser::ImplContext *ctx) {
  return getName(ctx->NAME());
}

antlrcpp::Any ontologyBaseVisitor::visitComm(ontologyParser::CommContext *ctx) {
    std::string str = ctx->STRING()->getText();
    return str.substr(1, str.size() - 2);
}