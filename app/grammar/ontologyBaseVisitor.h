#pragma once

#include "antlr4-runtime.h"
#include "ontologyVisitor.h"
#include "compilerLogger.h"
#include <QJsonObject>
#include <QJsonArray>

class  ontologyBaseVisitor : public ontologyVisitor {
public:

  ontologyBaseVisitor(CompilerLogger logger);

  QJsonObject getJson(ontologyParser::FileContext *ctx);

  std::vector<std::pair<std::string, std::string>> getClasses() {return classes_;};
  std::vector<std::pair<std::string, std::string>> getActivities() {return activities_;};
  std::vector<std::pair<std::string, std::string>> getEnums() {return enums_;};
  std::vector<std::string> getFrames() {return frames_;};

private:

  std::string frameName_;

  CompilerLogger logger_;
  std::vector<std::pair<std::string, std::string>> classes_;
  std::vector<std::pair<std::string, std::string>> activities_;
  std::vector<std::pair<std::string, std::string>> enums_;
  std::vector<std::string> frames_;

  virtual antlrcpp::Any visitFile(ontologyParser::FileContext *ctx) override;

  virtual antlrcpp::Any visitFrame(ontologyParser::FrameContext *ctx) override;

  virtual antlrcpp::Any visitClass_(ontologyParser::Class_Context *ctx) override;

  virtual antlrcpp::Any visitAct(ontologyParser::ActContext *ctx) override;

  virtual antlrcpp::Any visitEnum_(ontologyParser::Enum_Context *ctx) override;

  virtual antlrcpp::Any visitGen(ontologyParser::GenContext *ctx) override;

  virtual antlrcpp::Any visitAssoc(ontologyParser::AssocContext *ctx) override;

  virtual antlrcpp::Any visitAttr(ontologyParser::AttrContext *ctx) override;

  virtual antlrcpp::Any visitOper(ontologyParser::OperContext *ctx) override;

  virtual antlrcpp::Any visitAggr(ontologyParser::AggrContext *ctx) override;

  virtual antlrcpp::Any visitComp(ontologyParser::CompContext *ctx) override;

  virtual antlrcpp::Any visitDep(ontologyParser::DepContext *ctx) override;

  virtual antlrcpp::Any visitImpl(ontologyParser::ImplContext *ctx) override;

  virtual antlrcpp::Any visitIn(ontologyParser::InContext *ctx) override;

  virtual antlrcpp::Any visitOut(ontologyParser::OutContext *ctx) override;

  virtual antlrcpp::Any visitEnum_literals(ontologyParser::Enum_literalsContext *ctx) override;

  virtual antlrcpp::Any visitComm(ontologyParser::CommContext *ctx) override;
};