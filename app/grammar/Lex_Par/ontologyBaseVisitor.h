
// Generated from c:\Users\Admin\Desktop\ODE\app\grammar\ontology.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "ontologyVisitor.h"


/**
 * This class provides an empty implementation of ontologyVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ontologyBaseVisitor : public ontologyVisitor {
public:

  virtual antlrcpp::Any visitFile(ontologyParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFrame(ontologyParser::FrameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_(ontologyParser::Class_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnum_(ontologyParser::Enum_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAct(ontologyParser::ActContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGen(ontologyParser::GenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssoc(ontologyParser::AssocContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttr(ontologyParser::AttrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOper(ontologyParser::OperContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAggr(ontologyParser::AggrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComp(ontologyParser::CompContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDep(ontologyParser::DepContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImpl(ontologyParser::ImplContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIn(ontologyParser::InContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOut(ontologyParser::OutContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnum_literals(ontologyParser::Enum_literalsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComm(ontologyParser::CommContext *ctx) override {
    return visitChildren(ctx);
  }


};

