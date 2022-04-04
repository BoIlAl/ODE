
// Generated from c:\Users\Admin\Desktop\ODE\app\grammar\ontology.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "ontologyParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ontologyParser.
 */
class  ontologyVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ontologyParser.
   */
    virtual antlrcpp::Any visitFile(ontologyParser::FileContext *context) = 0;

    virtual antlrcpp::Any visitPackage(ontologyParser::PackageContext *context) = 0;

    virtual antlrcpp::Any visitClass_(ontologyParser::Class_Context *context) = 0;

    virtual antlrcpp::Any visitEnum_(ontologyParser::Enum_Context *context) = 0;

    virtual antlrcpp::Any visitAct(ontologyParser::ActContext *context) = 0;

    virtual antlrcpp::Any visitGen(ontologyParser::GenContext *context) = 0;

    virtual antlrcpp::Any visitAssoc(ontologyParser::AssocContext *context) = 0;

    virtual antlrcpp::Any visitAttr(ontologyParser::AttrContext *context) = 0;

    virtual antlrcpp::Any visitOper(ontologyParser::OperContext *context) = 0;

    virtual antlrcpp::Any visitAggr(ontologyParser::AggrContext *context) = 0;

    virtual antlrcpp::Any visitComp(ontologyParser::CompContext *context) = 0;

    virtual antlrcpp::Any visitDep(ontologyParser::DepContext *context) = 0;

    virtual antlrcpp::Any visitImpl(ontologyParser::ImplContext *context) = 0;

    virtual antlrcpp::Any visitIn(ontologyParser::InContext *context) = 0;

    virtual antlrcpp::Any visitOut(ontologyParser::OutContext *context) = 0;

    virtual antlrcpp::Any visitEnum_literals(ontologyParser::Enum_literalsContext *context) = 0;

    virtual antlrcpp::Any visitComm(ontologyParser::CommContext *context) = 0;


};

