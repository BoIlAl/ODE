#include "ontologyBaseVisitor.h"

ontologyBaseVisitor::ontologyBaseVisitor(CompilerLogger logger) {
  logger_ = logger;
}

QJsonObject ontologyBaseVisitor::getJson(ontologyParser::FileContext *ctx){
  return visitFile(ctx).as<QJsonObject>();
}

antlrcpp::Any ontologyBaseVisitor::visitFile(ontologyParser::FileContext *ctx) {
    auto frame = ctx->frame();
    return visitFrame(frame).as<QJsonObject>();
}

antlrcpp::Any ontologyBaseVisitor::visitFrame(ontologyParser::FrameContext *ctx) {
    QJsonObject frame;
    frameName_ = ctx->NAME()->toString();
    frames_.push_back(frameName_);

    if (!ctx->class_().empty()) {
      QJsonArray classes;
      auto arrClass = ctx->class_();
      for(int i = 0;  i <  arrClass.size(); ++i) {
          classes.push_back(visitClass_(arrClass[i]).as<QJsonObject>());
      }
      frame.insert("Classes", classes);
    }

    if (!ctx->act().empty()) {
      QJsonArray acts;
      auto arrAct = ctx->act();
      for(int i = 0;  i <  arrAct.size(); ++i) {
          acts.push_back(visitAct(arrAct[i]).as<QJsonObject>());
      }
      frame.insert("Activity", acts);
    }

    if (!ctx->enum_().empty()) {
      QJsonArray enums;
      auto arrEnum = ctx->enum_();
      for(int i = 0;  i <  arrEnum.size(); ++i) {
          enums.push_back(visitEnum_(arrEnum[i]).as<QJsonObject>());
      }
      frame.insert("Enumeration", enums);
    }

    if (!ctx->assoc().empty()) {
      QJsonArray assoc;
      auto arrAssoc = ctx->assoc();
      for(int i = 0;  i <  arrAssoc.size(); ++i) {
          assoc.push_back(visitAssoc(arrAssoc[i]).as<QJsonObject>());
      }
      frame.insert("Association", assoc);
    }

    frame.insert("name", ctx->NAME()->getText().c_str());
    return frame;
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
      class_.insert("attr", attr);
    }

    if (ctx->oper() != nullptr) {
      QJsonArray oper;
      std::vector<std::string> arrOper = visitOper(ctx->oper()).as<std::vector<std::string>>();
      for (int i = 0; i < arrOper.size(); ++i) {
        oper.push_back(arrOper[i].c_str());
      }
      class_.insert("oper", oper);
    }

    if (ctx->aggr() != nullptr) {
      class_.insert("aggr", visitAggr(ctx->aggr()).as<std::string>().c_str());
    }

    if (ctx->comp() != nullptr) {
      class_.insert("comp", visitComp(ctx->comp()).as<std::string>().c_str());
    }

    if (ctx->dep() != nullptr) {
      class_.insert("dep", visitDep(ctx->dep()).as<std::string>().c_str());
    }

    if (ctx->impl() != nullptr) {
      class_.insert("impl", visitImpl(ctx->impl()).as<std::string>().c_str());
    }

    if (ctx->comm() != nullptr) {
      class_.insert("comm", visitComm(ctx->comm()).as<std::string>().c_str());
    }

    classes_.push_back(std::pair<std::string, std::string>(frameName_.c_str(), ctx->NAME()->getText().c_str()));
    class_.insert("name", ctx->NAME()->getText().c_str());
    return class_;
}

antlrcpp::Any ontologyBaseVisitor::visitAct(ontologyParser::ActContext *ctx) {
    QJsonObject act;

    if (ctx->gen() != nullptr) {
      QJsonArray gen;
      std::vector<std::string> arr = visitGen(ctx->gen()).as<std::vector<std::string>>();
      for (int i = 0; i < arr.size(); ++i) {
        gen.push_back(arr[i].c_str());
      }
      act.insert("generalization", gen);
    }

    QJsonArray in;
    std::vector<std::string> arrIN = visitIn(ctx->in()).as<std::vector<std::string>>();
    for (int i = 0; i < arrIN.size(); ++i) {
      in.push_back(arrIN[i].c_str());
    }
    act.insert("in", in);

    QJsonArray out;
    std::vector<std::string> arrOut = visitOut(ctx->out()).as<std::vector<std::string>>();
    for (int i = 0; i < arrOut.size(); ++i) {
      out.push_back(arrOut[i].c_str());
    }
    act.insert("out", out);


    if (ctx->aggr() != nullptr) {
      act.insert("aggr", visitAggr(ctx->aggr()).as<std::string>().c_str());
    }

    if (ctx->comp() != nullptr) {
      act.insert("comp", visitComp(ctx->comp()).as<std::string>().c_str());
    }

    if (ctx->dep() != nullptr) {
      act.insert("dep", visitDep(ctx->dep()).as<std::string>().c_str());
    }

    if (ctx->impl() != nullptr) {
      act.insert("impl", visitImpl(ctx->impl()).as<std::string>().c_str());
    }

    if (ctx->comm() != nullptr) {
      act.insert("comm", visitComm(ctx->comm()).as<std::string>().c_str());
    }

    activities_.push_back(std::pair<std::string, std::string>(frameName_.c_str(), ctx->NAME()->getText().c_str()));
    act.insert("name", ctx->NAME()->getText().c_str());
    return act;
}


antlrcpp::Any ontologyBaseVisitor::visitEnum_(ontologyParser::Enum_Context *ctx) {
    QJsonObject enumeration;

    QJsonArray literals;
    std::vector<std::string> arr = visitEnum_literals(ctx->enum_literals()).as<std::vector<std::string>>();
    for (int i = 0; i < arr.size(); ++i) {
      literals.push_back(arr[i].c_str());
    }
    enumeration.insert("enum_literals", literals);


    enums_.push_back(std::pair<std::string, std::string>(frameName_, ctx->NAME()->getText().c_str()));
    enumeration.insert("name", ctx->NAME()->getText().c_str());
    return enumeration;
}

antlrcpp::Any ontologyBaseVisitor::visitGen(ontologyParser::GenContext *ctx) {
    std::vector<std::string> names;

    auto arr = ctx->NAME();
    
    for(int i = 0;  i <  arr.size(); ++i) {
        names.push_back(arr[i]->getText());
    }
    return names;
}

antlrcpp::Any ontologyBaseVisitor::visitAssoc(ontologyParser::AssocContext *ctx) {
    QJsonObject assoc;
    assoc.insert("name", ctx->STRING()->toString().c_str());
    assoc.insert("left", ctx->NAME(0)->toString().c_str());
    assoc.insert("right", ctx->NAME(1)->toString().c_str());
    return assoc;
}

antlrcpp::Any ontologyBaseVisitor::visitAttr(ontologyParser::AttrContext *ctx) {
    auto arr = ctx->STRING();
    std::vector<std::string> strs;
    for(int i = 0;  i <  arr.size(); ++i) {
        strs.push_back(arr[i]->getText());
    }
    return strs;
}

antlrcpp::Any ontologyBaseVisitor::visitOper(ontologyParser::OperContext *ctx) {
    auto arr = ctx->STRING();
    std::vector<std::string> strs;
    for(int i = 0;  i <  arr.size(); ++i) {
        strs.push_back(arr[i]->getText());
    }
    return strs;
}

antlrcpp::Any ontologyBaseVisitor::visitAggr(ontologyParser::AggrContext *ctx) {
    std::string name = ctx->NAME()->getText();
    return name;
}

antlrcpp::Any ontologyBaseVisitor::visitComp(ontologyParser::CompContext *ctx) {
    std::string name = ctx->NAME()->getText();
    return name;
}

antlrcpp::Any ontologyBaseVisitor::visitDep(ontologyParser::DepContext *ctx) {
    std::string name = ctx->NAME()->getText();
    return name;
}

antlrcpp::Any ontologyBaseVisitor::visitImpl(ontologyParser::ImplContext *ctx) {
    std::string name = ctx->NAME()->getText();
    return name;
}

antlrcpp::Any ontologyBaseVisitor::visitIn(ontologyParser::InContext *ctx) {
    auto arr = ctx->NAME();
    std::vector<std::string> names;
    for(int i = 0;  i <  arr.size(); ++i) {
        names.push_back(arr[i]->getText());
    }
    return names;
}

antlrcpp::Any ontologyBaseVisitor::visitOut(ontologyParser::OutContext *ctx) {
    auto arr = ctx->NAME();
    std::vector<std::string> names;
    for(int i = 0;  i <  arr.size(); ++i) {
        names.push_back(arr[i]->getText());
    }
    return names;
}

antlrcpp::Any ontologyBaseVisitor::visitEnum_literals(ontologyParser::Enum_literalsContext *ctx) {
    auto arr = ctx->STRING();
    std::vector<std::string> strs;
    for(int i = 0;  i <  arr.size(); ++i) {
        strs.push_back(arr[i]->getText());
    }
    return strs;
}

antlrcpp::Any ontologyBaseVisitor::visitComm(ontologyParser::CommContext *ctx) {
    std::string str = ctx->STRING()->getText();
    return str;
}