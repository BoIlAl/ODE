#pragma once

#include "antlr4-runtime.h"
#include "ontologyVisitor.h"
#include "logger.h"
#include <QJsonObject>
#include <QJsonArray>

class  ontologyBaseVisitor : public ontologyVisitor {
public:

  ontologyBaseVisitor(Logger* logger);

  QJsonObject getJson(ontologyParser::FileContext *ctx);

private:

  Logger* logger_;
  std::vector<std::string> defClasses_;
  std::vector<std::string> usedClasses_;

  std::vector<std::string> defActivities_;
  std::vector<std::string> usedActivities_;

  std::vector<std::string> currUsedObjs_;

  bool isUsed(const std::string& str) const;

  QJsonArray createUsedArr(std::vector<std::string> used, std::vector<std::string> def) const;

  void redefCheck() const;

  std::vector<std::string> getNames(std::vector<antlr4::tree::TerminalNode*> arr);
  std::vector<std::string> getStrs(std::vector<antlr4::tree::TerminalNode*> arr);
  std::string getName(antlr4::tree::TerminalNode* node);

  virtual antlrcpp::Any visitFile(ontologyParser::FileContext *ctx) override;

  virtual antlrcpp::Any visitPackage(ontologyParser::PackageContext *ctx) override;

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