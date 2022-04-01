
// Generated from c:\Users\Admin\Desktop\ODE\ontology.g4 by ANTLR 4.8


#include "ontologyVisitor.h"

#include "ontologyParser.h"


using namespace antlrcpp;
using namespace antlr4;

ontologyParser::ontologyParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ontologyParser::~ontologyParser() {
  delete _interpreter;
}

std::string ontologyParser::getGrammarFileName() const {
  return "ontology.g4";
}

const std::vector<std::string>& ontologyParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ontologyParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

ontologyParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ontologyParser::FrameContext* ontologyParser::FileContext::frame() {
  return getRuleContext<ontologyParser::FrameContext>(0);
}

tree::TerminalNode* ontologyParser::FileContext::EOF() {
  return getToken(ontologyParser::EOF, 0);
}


size_t ontologyParser::FileContext::getRuleIndex() const {
  return ontologyParser::RuleFile;
}


antlrcpp::Any ontologyParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ontologyVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

ontologyParser::FileContext* ontologyParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, ontologyParser::RuleFile);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(34);
    frame();
    setState(35);
    match(ontologyParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FrameContext ------------------------------------------------------------------

ontologyParser::FrameContext::FrameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ontologyParser::FrameContext::FRAME() {
  return getToken(ontologyParser::FRAME, 0);
}

tree::TerminalNode* ontologyParser::FrameContext::NAME() {
  return getToken(ontologyParser::NAME, 0);
}

tree::TerminalNode* ontologyParser::FrameContext::LBRACE() {
  return getToken(ontologyParser::LBRACE, 0);
}

tree::TerminalNode* ontologyParser::FrameContext::RBRACE() {
  return getToken(ontologyParser::RBRACE, 0);
}

std::vector<ontologyParser::Class_Context *> ontologyParser::FrameContext::class_() {
  return getRuleContexts<ontologyParser::Class_Context>();
}

ontologyParser::Class_Context* ontologyParser::FrameContext::class_(size_t i) {
  return getRuleContext<ontologyParser::Class_Context>(i);
}

std::vector<ontologyParser::ActContext *> ontologyParser::FrameContext::act() {
  return getRuleContexts<ontologyParser::ActContext>();
}

ontologyParser::ActContext* ontologyParser::FrameContext::act(size_t i) {
  return getRuleContext<ontologyParser::ActContext>(i);
}

std::vector<ontologyParser::Enum_Context *> ontologyParser::FrameContext::enum_() {
  return getRuleContexts<ontologyParser::Enum_Context>();
}

ontologyParser::Enum_Context* ontologyParser::FrameContext::enum_(size_t i) {
  return getRuleContext<ontologyParser::Enum_Context>(i);
}

std::vector<ontologyParser::AssocContext *> ontologyParser::FrameContext::assoc() {
  return getRuleContexts<ontologyParser::AssocContext>();
}

ontologyParser::AssocContext* ontologyParser::FrameContext::assoc(size_t i) {
  return getRuleContext<ontologyParser::AssocContext>(i);
}


size_t ontologyParser::FrameContext::getRuleIndex() const {
  return ontologyParser::RuleFrame;
}


antlrcpp::Any ontologyParser::FrameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ontologyVisitor*>(visitor))
    return parserVisitor->visitFrame(this);
  else
    return visitor->visitChildren(this);
}

ontologyParser::FrameContext* ontologyParser::frame() {
  FrameContext *_localctx = _tracker.createInstance<FrameContext>(_ctx, getState());
  enterRule(_localctx, 2, ontologyParser::RuleFrame);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(37);
    match(ontologyParser::FRAME);
    setState(38);
    match(ontologyParser::NAME);
    setState(39);
    match(ontologyParser::LBRACE);
    setState(43);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ontologyParser::CLASS) {
      setState(40);
      class_();
      setState(45);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ontologyParser::ACTIVITY) {
      setState(46);
      act();
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(55);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ontologyParser::ENUMERATION) {
      setState(52);
      enum_();
      setState(57);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ontologyParser::ASSOCIATION) {
      setState(58);
      assoc();
      setState(63);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(64);
    match(ontologyParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_Context ------------------------------------------------------------------

ontologyParser::Class_Context::Class_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ontologyParser::Class_Context::CLASS() {
  return getToken(ontologyParser::CLASS, 0);
}

tree::TerminalNode* ontologyParser::Class_Context::NAME() {
  return getToken(ontologyParser::NAME, 0);
}

tree::TerminalNode* ontologyParser::Class_Context::LBRACE() {
  return getToken(ontologyParser::LBRACE, 0);
}

tree::TerminalNode* ontologyParser::Class_Context::RBRACE() {
  return getToken(ontologyParser::RBRACE, 0);
}

ontologyParser::GenContext* ontologyParser::Class_Context::gen() {
  return getRuleContext<ontologyParser::GenContext>(0);
}

ontologyParser::AttrContext* ontologyParser::Class_Context::attr() {
  return getRuleContext<ontologyParser::AttrContext>(0);
}

ontologyParser::OperContext* ontologyParser::Class_Context::oper() {
  return getRuleContext<ontologyParser::OperContext>(0);
}

ontologyParser::AggrContext* ontologyParser::Class_Context::aggr() {
  return getRuleContext<ontologyParser::AggrContext>(0);
}

ontologyParser::CompContext* ontologyParser::Class_Context::comp() {
  return getRuleContext<ontologyParser::CompContext>(0);
}

ontologyParser::DepContext* ontologyParser::Class_Context::dep() {
  return getRuleContext<ontologyParser::DepContext>(0);
}

ontologyParser::ImplContext* ontologyParser::Class_Context::impl() {
  return getRuleContext<ontologyParser::ImplContext>(0);
}

ontologyParser::CommContext* ontologyParser::Class_Context::comm() {
  return getRuleContext<ontologyParser::CommContext>(0);
}


size_t ontologyParser::Class_Context::getRuleIndex() const {
  return ontologyParser::RuleClass_;
}


antlrcpp::Any ontologyParser::Class_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ontologyVisitor*>(visitor))
    return parserVisitor->visitClass_(this);
  else
    return visitor->visitChildren(this);
}

ontologyParser::Class_Context* ontologyParser::class_() {
  Class_Context *_localctx = _tracker.createInstance<Class_Context>(_ctx, getState());
  enterRule(_localctx, 4, ontologyParser::RuleClass_);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(ontologyParser::CLASS);
    setState(67);
    match(ontologyParser::NAME);
    setState(69);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ontologyParser::COLON) {
      setState(68);
      gen();
    }
    setState(71);
    match(ontologyParser::LBRACE);
    setState(73);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ontologyParser::ATTRIBUTES) {
      setState(72);
      attr();
    }
    setState(76);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ontologyParser::OPERATIONS) {
      setState(75);
      oper();
    }
    setState(79);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ontologyParser::AGGREGATION) {
      setState(78);
      aggr();
    }
    setState(82);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ontologyParser::COMPOSITION) {
      setState(81);
      comp();
    }
    setState(85);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ontologyParser::DEPENDENCY) {
      setState(84);
      dep();
    }
    setState(88);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ontologyParser::IMPLEMENTATION) {
      setState(87);
      impl();
    }
    setState(91);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ontologyParser::COMMENT) {
      setState(90);
      comm();
    }
    setState(93);
    match(ontologyParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_Context ------------------------------------------------------------------

ontologyParser::Enum_Context::Enum_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ontologyParser::Enum_Context::ENUMERATION() {
  return getToken(ontologyParser::ENUMERATION, 0);
}

tree::TerminalNode* ontologyParser::Enum_Context::NAME() {
  return getToken(ontologyParser::NAME, 0);
}

tree::TerminalNode* ontologyParser::Enum_Context::LBRACE() {
  return getToken(ontologyParser::LBRACE, 0);
}

ontologyParser::Enum_literalsContext* ontologyParser::Enum_Context::enum_literals() {
  return getRuleContext<ontologyParser::Enum_literalsContext>(0);
}

tree::TerminalNode* ontologyParser::Enum_Context::RBRACE() {
  return getToken(ontologyParser::RBRACE, 0);
}


size_t ontologyParser::Enum_Context::getRuleIndex() const {
  return ontologyParser::RuleEnum_;
}


antlrcpp::Any ontologyParser::Enum_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ontologyVisitor*>(visitor))
    return parserVisitor->visitEnum_(this);
  else
    return visitor->visitChildren(this);
}

ontologyParser::Enum_Context* ontologyParser::enum_() {
  Enum_Context *_localctx = _tracker.createInstance<Enum_Context>(_ctx, getState());
  enterRule(_localctx, 6, ontologyParser::RuleEnum_);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    match(ontologyParser::ENUMERATION);
    setState(96);
    match(ontologyParser::NAME);
    setState(97);
    match(ontologyParser::LBRACE);
    setState(98);
    enum_literals();
    setState(99);
    match(ontologyParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ActContext ------------------------------------------------------------------

ontologyParser::ActContext::ActContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ontologyParser::ActContext::ACTIVITY() {
  return getToken(ontologyParser::ACTIVITY, 0);
}

tree::TerminalNode* ontologyParser::ActContext::NAME() {
  return getToken(ontologyParser::NAME, 0);
}

tree::TerminalNode* ontologyParser::ActContext::LBRACE() {
  return getToken(ontologyParser::LBRACE, 0);
}

ontologyParser::InContext* ontologyParser::ActContext::in() {
  return getRuleContext<ontologyParser::InContext>(0);
}

ontologyParser::OutContext* ontologyParser::ActContext::out() {
  return getRuleContext<ontologyParser::OutContext>(0);
}

tree::TerminalNode* ontologyParser::ActContext::RBRACE() {
  return getToken(ontologyParser::RBRACE, 0);
}

ontologyParser::GenContext* ontologyParser::ActContext::gen() {
  return getRuleContext<ontologyParser::GenContext>(0);
}

ontologyParser::AggrContext* ontologyParser::ActContext::aggr() {
  return getRuleContext<ontologyParser::AggrContext>(0);
}

ontologyParser::CompContext* ontologyParser::ActContext::comp() {
  return getRuleContext<ontologyParser::CompContext>(0);
}

ontologyParser::DepContext* ontologyParser::ActContext::dep() {
  return getRuleContext<ontologyParser::DepContext>(0);
}

ontologyParser::ImplContext* ontologyParser::ActContext::impl() {
  return getRuleContext<ontologyParser::ImplContext>(0);
}

ontologyParser::CommContext* ontologyParser::ActContext::comm() {
  return getRuleContext<ontologyParser::CommContext>(0);
}


size_t ontologyParser::ActContext::getRuleIndex() const {
  return ontologyParser::RuleAct;
}


antlrcpp::Any ontologyParser::ActContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ontologyVisitor*>(visitor))
    return parserVisitor->visitAct(this);
  else
    return visitor->visitChildren(this);
}

ontologyParser::ActContext* ontologyParser::act() {
  ActContext *_localctx = _tracker.createInstance<ActContext>(_ctx, getState());
  enterRule(_localctx, 8, ontologyParser::RuleAct);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    match(ontologyParser::ACTIVITY);
    setState(102);
    match(ontologyParser::NAME);
    setState(104);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ontologyParser::COLON) {
      setState(103);
      gen();
    }
    setState(106);
    match(ontologyParser::LBRACE);
    setState(107);
    in();
    setState(108);
    out();
    setState(110);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ontologyParser::AGGREGATION) {
      setState(109);
      aggr();
    }
    setState(113);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ontologyParser::COMPOSITION) {
      setState(112);
      comp();
    }
    setState(116);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ontologyParser::DEPENDENCY) {
      setState(115);
      dep();
    }
    setState(119);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ontologyParser::IMPLEMENTATION) {
      setState(118);
      impl();
    }
    setState(122);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ontologyParser::COMMENT) {
      setState(121);
      comm();
    }
    setState(124);
    match(ontologyParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GenContext ------------------------------------------------------------------

ontologyParser::GenContext::GenContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ontologyParser::GenContext::COLON() {
  return getToken(ontologyParser::COLON, 0);
}

std::vector<tree::TerminalNode *> ontologyParser::GenContext::NAME() {
  return getTokens(ontologyParser::NAME);
}

tree::TerminalNode* ontologyParser::GenContext::NAME(size_t i) {
  return getToken(ontologyParser::NAME, i);
}

std::vector<tree::TerminalNode *> ontologyParser::GenContext::COMMA() {
  return getTokens(ontologyParser::COMMA);
}

tree::TerminalNode* ontologyParser::GenContext::COMMA(size_t i) {
  return getToken(ontologyParser::COMMA, i);
}


size_t ontologyParser::GenContext::getRuleIndex() const {
  return ontologyParser::RuleGen;
}


antlrcpp::Any ontologyParser::GenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ontologyVisitor*>(visitor))
    return parserVisitor->visitGen(this);
  else
    return visitor->visitChildren(this);
}

ontologyParser::GenContext* ontologyParser::gen() {
  GenContext *_localctx = _tracker.createInstance<GenContext>(_ctx, getState());
  enterRule(_localctx, 10, ontologyParser::RuleGen);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(126);
    match(ontologyParser::COLON);
    setState(131);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(127);
        match(ontologyParser::NAME);
        setState(128);
        match(ontologyParser::COMMA); 
      }
      setState(133);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
    setState(134);
    match(ontologyParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssocContext ------------------------------------------------------------------

ontologyParser::AssocContext::AssocContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ontologyParser::AssocContext::ASSOCIATION() {
  return getToken(ontologyParser::ASSOCIATION, 0);
}

tree::TerminalNode* ontologyParser::AssocContext::STRING() {
  return getToken(ontologyParser::STRING, 0);
}

tree::TerminalNode* ontologyParser::AssocContext::LBRACKET() {
  return getToken(ontologyParser::LBRACKET, 0);
}

std::vector<tree::TerminalNode *> ontologyParser::AssocContext::NAME() {
  return getTokens(ontologyParser::NAME);
}

tree::TerminalNode* ontologyParser::AssocContext::NAME(size_t i) {
  return getToken(ontologyParser::NAME, i);
}

tree::TerminalNode* ontologyParser::AssocContext::COMMA() {
  return getToken(ontologyParser::COMMA, 0);
}

tree::TerminalNode* ontologyParser::AssocContext::RBRACKET() {
  return getToken(ontologyParser::RBRACKET, 0);
}

tree::TerminalNode* ontologyParser::AssocContext::SEMICOLON() {
  return getToken(ontologyParser::SEMICOLON, 0);
}


size_t ontologyParser::AssocContext::getRuleIndex() const {
  return ontologyParser::RuleAssoc;
}


antlrcpp::Any ontologyParser::AssocContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ontologyVisitor*>(visitor))
    return parserVisitor->visitAssoc(this);
  else
    return visitor->visitChildren(this);
}

ontologyParser::AssocContext* ontologyParser::assoc() {
  AssocContext *_localctx = _tracker.createInstance<AssocContext>(_ctx, getState());
  enterRule(_localctx, 12, ontologyParser::RuleAssoc);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    match(ontologyParser::ASSOCIATION);
    setState(137);
    match(ontologyParser::STRING);
    setState(138);
    match(ontologyParser::LBRACKET);
    setState(139);
    match(ontologyParser::NAME);
    setState(140);
    match(ontologyParser::COMMA);
    setState(141);
    match(ontologyParser::NAME);
    setState(142);
    match(ontologyParser::RBRACKET);
    setState(143);
    match(ontologyParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttrContext ------------------------------------------------------------------

ontologyParser::AttrContext::AttrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ontologyParser::AttrContext::ATTRIBUTES() {
  return getToken(ontologyParser::ATTRIBUTES, 0);
}

std::vector<tree::TerminalNode *> ontologyParser::AttrContext::STRING() {
  return getTokens(ontologyParser::STRING);
}

tree::TerminalNode* ontologyParser::AttrContext::STRING(size_t i) {
  return getToken(ontologyParser::STRING, i);
}

tree::TerminalNode* ontologyParser::AttrContext::SEMICOLON() {
  return getToken(ontologyParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> ontologyParser::AttrContext::COMMA() {
  return getTokens(ontologyParser::COMMA);
}

tree::TerminalNode* ontologyParser::AttrContext::COMMA(size_t i) {
  return getToken(ontologyParser::COMMA, i);
}


size_t ontologyParser::AttrContext::getRuleIndex() const {
  return ontologyParser::RuleAttr;
}


antlrcpp::Any ontologyParser::AttrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ontologyVisitor*>(visitor))
    return parserVisitor->visitAttr(this);
  else
    return visitor->visitChildren(this);
}

ontologyParser::AttrContext* ontologyParser::attr() {
  AttrContext *_localctx = _tracker.createInstance<AttrContext>(_ctx, getState());
  enterRule(_localctx, 14, ontologyParser::RuleAttr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(145);
    match(ontologyParser::ATTRIBUTES);
    setState(150);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(146);
        match(ontologyParser::STRING);
        setState(147);
        match(ontologyParser::COMMA); 
      }
      setState(152);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
    setState(153);
    match(ontologyParser::STRING);
    setState(154);
    match(ontologyParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperContext ------------------------------------------------------------------

ontologyParser::OperContext::OperContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ontologyParser::OperContext::OPERATIONS() {
  return getToken(ontologyParser::OPERATIONS, 0);
}

std::vector<tree::TerminalNode *> ontologyParser::OperContext::STRING() {
  return getTokens(ontologyParser::STRING);
}

tree::TerminalNode* ontologyParser::OperContext::STRING(size_t i) {
  return getToken(ontologyParser::STRING, i);
}

tree::TerminalNode* ontologyParser::OperContext::SEMICOLON() {
  return getToken(ontologyParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> ontologyParser::OperContext::COMMA() {
  return getTokens(ontologyParser::COMMA);
}

tree::TerminalNode* ontologyParser::OperContext::COMMA(size_t i) {
  return getToken(ontologyParser::COMMA, i);
}


size_t ontologyParser::OperContext::getRuleIndex() const {
  return ontologyParser::RuleOper;
}


antlrcpp::Any ontologyParser::OperContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ontologyVisitor*>(visitor))
    return parserVisitor->visitOper(this);
  else
    return visitor->visitChildren(this);
}

ontologyParser::OperContext* ontologyParser::oper() {
  OperContext *_localctx = _tracker.createInstance<OperContext>(_ctx, getState());
  enterRule(_localctx, 16, ontologyParser::RuleOper);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(ontologyParser::OPERATIONS);
    setState(161);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(157);
        match(ontologyParser::STRING);
        setState(158);
        match(ontologyParser::COMMA); 
      }
      setState(163);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
    setState(164);
    match(ontologyParser::STRING);
    setState(165);
    match(ontologyParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AggrContext ------------------------------------------------------------------

ontologyParser::AggrContext::AggrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ontologyParser::AggrContext::AGGREGATION() {
  return getToken(ontologyParser::AGGREGATION, 0);
}

tree::TerminalNode* ontologyParser::AggrContext::NAME() {
  return getToken(ontologyParser::NAME, 0);
}

tree::TerminalNode* ontologyParser::AggrContext::SEMICOLON() {
  return getToken(ontologyParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> ontologyParser::AggrContext::LBRACKET() {
  return getTokens(ontologyParser::LBRACKET);
}

tree::TerminalNode* ontologyParser::AggrContext::LBRACKET(size_t i) {
  return getToken(ontologyParser::LBRACKET, i);
}

std::vector<tree::TerminalNode *> ontologyParser::AggrContext::STRING() {
  return getTokens(ontologyParser::STRING);
}

tree::TerminalNode* ontologyParser::AggrContext::STRING(size_t i) {
  return getToken(ontologyParser::STRING, i);
}

std::vector<tree::TerminalNode *> ontologyParser::AggrContext::COMMA() {
  return getTokens(ontologyParser::COMMA);
}

tree::TerminalNode* ontologyParser::AggrContext::COMMA(size_t i) {
  return getToken(ontologyParser::COMMA, i);
}

std::vector<tree::TerminalNode *> ontologyParser::AggrContext::RBRACKET() {
  return getTokens(ontologyParser::RBRACKET);
}

tree::TerminalNode* ontologyParser::AggrContext::RBRACKET(size_t i) {
  return getToken(ontologyParser::RBRACKET, i);
}


size_t ontologyParser::AggrContext::getRuleIndex() const {
  return ontologyParser::RuleAggr;
}


antlrcpp::Any ontologyParser::AggrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ontologyVisitor*>(visitor))
    return parserVisitor->visitAggr(this);
  else
    return visitor->visitChildren(this);
}

ontologyParser::AggrContext* ontologyParser::aggr() {
  AggrContext *_localctx = _tracker.createInstance<AggrContext>(_ctx, getState());
  enterRule(_localctx, 18, ontologyParser::RuleAggr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    match(ontologyParser::AGGREGATION);
    setState(168);
    match(ontologyParser::NAME);
    setState(176);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ontologyParser::LBRACKET) {
      setState(169);
      match(ontologyParser::LBRACKET);
      setState(170);
      match(ontologyParser::STRING);
      setState(171);
      match(ontologyParser::COMMA);
      setState(172);
      match(ontologyParser::STRING);
      setState(173);
      match(ontologyParser::RBRACKET);
      setState(178);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(179);
    match(ontologyParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompContext ------------------------------------------------------------------

ontologyParser::CompContext::CompContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ontologyParser::CompContext::COMPOSITION() {
  return getToken(ontologyParser::COMPOSITION, 0);
}

tree::TerminalNode* ontologyParser::CompContext::NAME() {
  return getToken(ontologyParser::NAME, 0);
}

tree::TerminalNode* ontologyParser::CompContext::SEMICOLON() {
  return getToken(ontologyParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> ontologyParser::CompContext::LBRACKET() {
  return getTokens(ontologyParser::LBRACKET);
}

tree::TerminalNode* ontologyParser::CompContext::LBRACKET(size_t i) {
  return getToken(ontologyParser::LBRACKET, i);
}

std::vector<tree::TerminalNode *> ontologyParser::CompContext::STRING() {
  return getTokens(ontologyParser::STRING);
}

tree::TerminalNode* ontologyParser::CompContext::STRING(size_t i) {
  return getToken(ontologyParser::STRING, i);
}

std::vector<tree::TerminalNode *> ontologyParser::CompContext::COMMA() {
  return getTokens(ontologyParser::COMMA);
}

tree::TerminalNode* ontologyParser::CompContext::COMMA(size_t i) {
  return getToken(ontologyParser::COMMA, i);
}

std::vector<tree::TerminalNode *> ontologyParser::CompContext::RBRACKET() {
  return getTokens(ontologyParser::RBRACKET);
}

tree::TerminalNode* ontologyParser::CompContext::RBRACKET(size_t i) {
  return getToken(ontologyParser::RBRACKET, i);
}


size_t ontologyParser::CompContext::getRuleIndex() const {
  return ontologyParser::RuleComp;
}


antlrcpp::Any ontologyParser::CompContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ontologyVisitor*>(visitor))
    return parserVisitor->visitComp(this);
  else
    return visitor->visitChildren(this);
}

ontologyParser::CompContext* ontologyParser::comp() {
  CompContext *_localctx = _tracker.createInstance<CompContext>(_ctx, getState());
  enterRule(_localctx, 20, ontologyParser::RuleComp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    match(ontologyParser::COMPOSITION);
    setState(182);
    match(ontologyParser::NAME);
    setState(190);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ontologyParser::LBRACKET) {
      setState(183);
      match(ontologyParser::LBRACKET);
      setState(184);
      match(ontologyParser::STRING);
      setState(185);
      match(ontologyParser::COMMA);
      setState(186);
      match(ontologyParser::STRING);
      setState(187);
      match(ontologyParser::RBRACKET);
      setState(192);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(193);
    match(ontologyParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DepContext ------------------------------------------------------------------

ontologyParser::DepContext::DepContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ontologyParser::DepContext::DEPENDENCY() {
  return getToken(ontologyParser::DEPENDENCY, 0);
}

tree::TerminalNode* ontologyParser::DepContext::NAME() {
  return getToken(ontologyParser::NAME, 0);
}

tree::TerminalNode* ontologyParser::DepContext::SEMICOLON() {
  return getToken(ontologyParser::SEMICOLON, 0);
}


size_t ontologyParser::DepContext::getRuleIndex() const {
  return ontologyParser::RuleDep;
}


antlrcpp::Any ontologyParser::DepContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ontologyVisitor*>(visitor))
    return parserVisitor->visitDep(this);
  else
    return visitor->visitChildren(this);
}

ontologyParser::DepContext* ontologyParser::dep() {
  DepContext *_localctx = _tracker.createInstance<DepContext>(_ctx, getState());
  enterRule(_localctx, 22, ontologyParser::RuleDep);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(195);
    match(ontologyParser::DEPENDENCY);
    setState(196);
    match(ontologyParser::NAME);
    setState(197);
    match(ontologyParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImplContext ------------------------------------------------------------------

ontologyParser::ImplContext::ImplContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ontologyParser::ImplContext::IMPLEMENTATION() {
  return getToken(ontologyParser::IMPLEMENTATION, 0);
}

tree::TerminalNode* ontologyParser::ImplContext::NAME() {
  return getToken(ontologyParser::NAME, 0);
}

tree::TerminalNode* ontologyParser::ImplContext::SEMICOLON() {
  return getToken(ontologyParser::SEMICOLON, 0);
}


size_t ontologyParser::ImplContext::getRuleIndex() const {
  return ontologyParser::RuleImpl;
}


antlrcpp::Any ontologyParser::ImplContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ontologyVisitor*>(visitor))
    return parserVisitor->visitImpl(this);
  else
    return visitor->visitChildren(this);
}

ontologyParser::ImplContext* ontologyParser::impl() {
  ImplContext *_localctx = _tracker.createInstance<ImplContext>(_ctx, getState());
  enterRule(_localctx, 24, ontologyParser::RuleImpl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    match(ontologyParser::IMPLEMENTATION);
    setState(200);
    match(ontologyParser::NAME);
    setState(201);
    match(ontologyParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InContext ------------------------------------------------------------------

ontologyParser::InContext::InContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ontologyParser::InContext::INPUT() {
  return getToken(ontologyParser::INPUT, 0);
}

std::vector<tree::TerminalNode *> ontologyParser::InContext::NAME() {
  return getTokens(ontologyParser::NAME);
}

tree::TerminalNode* ontologyParser::InContext::NAME(size_t i) {
  return getToken(ontologyParser::NAME, i);
}

tree::TerminalNode* ontologyParser::InContext::SEMICOLON() {
  return getToken(ontologyParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> ontologyParser::InContext::COMMA() {
  return getTokens(ontologyParser::COMMA);
}

tree::TerminalNode* ontologyParser::InContext::COMMA(size_t i) {
  return getToken(ontologyParser::COMMA, i);
}


size_t ontologyParser::InContext::getRuleIndex() const {
  return ontologyParser::RuleIn;
}


antlrcpp::Any ontologyParser::InContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ontologyVisitor*>(visitor))
    return parserVisitor->visitIn(this);
  else
    return visitor->visitChildren(this);
}

ontologyParser::InContext* ontologyParser::in() {
  InContext *_localctx = _tracker.createInstance<InContext>(_ctx, getState());
  enterRule(_localctx, 26, ontologyParser::RuleIn);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(203);
    match(ontologyParser::INPUT);
    setState(208);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(204);
        match(ontologyParser::NAME);
        setState(205);
        match(ontologyParser::COMMA); 
      }
      setState(210);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
    setState(211);
    match(ontologyParser::NAME);
    setState(212);
    match(ontologyParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OutContext ------------------------------------------------------------------

ontologyParser::OutContext::OutContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ontologyParser::OutContext::OUTPUT() {
  return getToken(ontologyParser::OUTPUT, 0);
}

std::vector<tree::TerminalNode *> ontologyParser::OutContext::NAME() {
  return getTokens(ontologyParser::NAME);
}

tree::TerminalNode* ontologyParser::OutContext::NAME(size_t i) {
  return getToken(ontologyParser::NAME, i);
}

tree::TerminalNode* ontologyParser::OutContext::SEMICOLON() {
  return getToken(ontologyParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> ontologyParser::OutContext::COMMA() {
  return getTokens(ontologyParser::COMMA);
}

tree::TerminalNode* ontologyParser::OutContext::COMMA(size_t i) {
  return getToken(ontologyParser::COMMA, i);
}


size_t ontologyParser::OutContext::getRuleIndex() const {
  return ontologyParser::RuleOut;
}


antlrcpp::Any ontologyParser::OutContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ontologyVisitor*>(visitor))
    return parserVisitor->visitOut(this);
  else
    return visitor->visitChildren(this);
}

ontologyParser::OutContext* ontologyParser::out() {
  OutContext *_localctx = _tracker.createInstance<OutContext>(_ctx, getState());
  enterRule(_localctx, 28, ontologyParser::RuleOut);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(214);
    match(ontologyParser::OUTPUT);
    setState(219);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(215);
        match(ontologyParser::NAME);
        setState(216);
        match(ontologyParser::COMMA); 
      }
      setState(221);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
    setState(222);
    match(ontologyParser::NAME);
    setState(223);
    match(ontologyParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_literalsContext ------------------------------------------------------------------

ontologyParser::Enum_literalsContext::Enum_literalsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ontologyParser::Enum_literalsContext::LITERALS() {
  return getToken(ontologyParser::LITERALS, 0);
}

std::vector<tree::TerminalNode *> ontologyParser::Enum_literalsContext::STRING() {
  return getTokens(ontologyParser::STRING);
}

tree::TerminalNode* ontologyParser::Enum_literalsContext::STRING(size_t i) {
  return getToken(ontologyParser::STRING, i);
}

tree::TerminalNode* ontologyParser::Enum_literalsContext::SEMICOLON() {
  return getToken(ontologyParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> ontologyParser::Enum_literalsContext::COMMA() {
  return getTokens(ontologyParser::COMMA);
}

tree::TerminalNode* ontologyParser::Enum_literalsContext::COMMA(size_t i) {
  return getToken(ontologyParser::COMMA, i);
}


size_t ontologyParser::Enum_literalsContext::getRuleIndex() const {
  return ontologyParser::RuleEnum_literals;
}


antlrcpp::Any ontologyParser::Enum_literalsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ontologyVisitor*>(visitor))
    return parserVisitor->visitEnum_literals(this);
  else
    return visitor->visitChildren(this);
}

ontologyParser::Enum_literalsContext* ontologyParser::enum_literals() {
  Enum_literalsContext *_localctx = _tracker.createInstance<Enum_literalsContext>(_ctx, getState());
  enterRule(_localctx, 30, ontologyParser::RuleEnum_literals);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(225);
    match(ontologyParser::LITERALS);
    setState(230);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(226);
        match(ontologyParser::STRING);
        setState(227);
        match(ontologyParser::COMMA); 
      }
      setState(232);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
    setState(233);
    match(ontologyParser::STRING);
    setState(234);
    match(ontologyParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommContext ------------------------------------------------------------------

ontologyParser::CommContext::CommContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ontologyParser::CommContext::COMMENT() {
  return getToken(ontologyParser::COMMENT, 0);
}

tree::TerminalNode* ontologyParser::CommContext::STRING() {
  return getToken(ontologyParser::STRING, 0);
}

tree::TerminalNode* ontologyParser::CommContext::SEMICOLON() {
  return getToken(ontologyParser::SEMICOLON, 0);
}


size_t ontologyParser::CommContext::getRuleIndex() const {
  return ontologyParser::RuleComm;
}


antlrcpp::Any ontologyParser::CommContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ontologyVisitor*>(visitor))
    return parserVisitor->visitComm(this);
  else
    return visitor->visitChildren(this);
}

ontologyParser::CommContext* ontologyParser::comm() {
  CommContext *_localctx = _tracker.createInstance<CommContext>(_ctx, getState());
  enterRule(_localctx, 32, ontologyParser::RuleComm);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(236);
    match(ontologyParser::COMMENT);
    setState(237);
    match(ontologyParser::STRING);
    setState(238);
    match(ontologyParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> ontologyParser::_decisionToDFA;
atn::PredictionContextCache ontologyParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ontologyParser::_atn;
std::vector<uint16_t> ontologyParser::_serializedATN;

std::vector<std::string> ontologyParser::_ruleNames = {
  "file", "frame", "class_", "enum_", "act", "gen", "assoc", "attr", "oper", 
  "aggr", "comp", "dep", "impl", "in", "out", "enum_literals", "comm"
};

std::vector<std::string> ontologyParser::_literalNames = {
  "", "", "", "", "' '", "'\t'", "'Frame'", "'Class'", "'Enumeration'", 
  "'Activity'", "'Association'", "'attributes'", "'operations'", "'aggregation'", 
  "'composition'", "'dependency'", "'implementation'", "'input'", "'output'", 
  "'literals'", "'comment'", "'('", "')'", "'{'", "'}'", "':'", "','", "';'"
};

std::vector<std::string> ontologyParser::_symbolicNames = {
  "", "NAME", "STRING", "NEWLINE", "WHITESPACE", "TAB", "FRAME", "CLASS", 
  "ENUMERATION", "ACTIVITY", "ASSOCIATION", "ATTRIBUTES", "OPERATIONS", 
  "AGGREGATION", "COMPOSITION", "DEPENDENCY", "IMPLEMENTATION", "INPUT", 
  "OUTPUT", "LITERALS", "COMMENT", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", 
  "COLON", "COMMA", "SEMICOLON"
};

dfa::Vocabulary ontologyParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ontologyParser::_tokenNames;

ontologyParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x1d, 0xf3, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x7, 0x3, 0x2c, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x2f, 0xb, 0x3, 
    0x3, 0x3, 0x7, 0x3, 0x32, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x35, 0xb, 0x3, 
    0x3, 0x3, 0x7, 0x3, 0x38, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x3b, 0xb, 0x3, 
    0x3, 0x3, 0x7, 0x3, 0x3e, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x41, 0xb, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x48, 0xa, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x4c, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x4f, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 0x52, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x55, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 0x58, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x5b, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 0x5e, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x6b, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x5, 0x6, 0x71, 0xa, 0x6, 0x3, 0x6, 0x5, 0x6, 0x74, 0xa, 
    0x6, 0x3, 0x6, 0x5, 0x6, 0x77, 0xa, 0x6, 0x3, 0x6, 0x5, 0x6, 0x7a, 0xa, 
    0x6, 0x3, 0x6, 0x5, 0x6, 0x7d, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x84, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x87, 
    0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x7, 0x9, 0x97, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x9a, 0xb, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 
    0xa2, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xa5, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x7, 0xb, 0xb1, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xb4, 0xb, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xbf, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xc2, 
    0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x7, 0xf, 0xd1, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xd4, 0xb, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xdc, 
    0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xdf, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0xe7, 0xa, 0x11, 
    0xc, 0x11, 0xe, 0x11, 0xea, 0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x2, 0x2, 0x13, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x2, 0x2, 0x2, 0xfb, 0x2, 0x24, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x27, 0x3, 0x2, 0x2, 0x2, 0x6, 0x44, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x61, 0x3, 0x2, 0x2, 0x2, 0xa, 0x67, 0x3, 0x2, 0x2, 0x2, 0xc, 0x80, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x10, 0x93, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x14, 0xa9, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x18, 0xc5, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xcd, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0xd8, 0x3, 0x2, 0x2, 0x2, 0x20, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0xee, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x5, 0x4, 0x3, 0x2, 0x25, 0x26, 
    0x7, 0x2, 0x2, 0x3, 0x26, 0x3, 0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 0x7, 
    0x8, 0x2, 0x2, 0x28, 0x29, 0x7, 0x3, 0x2, 0x2, 0x29, 0x2d, 0x7, 0x19, 
    0x2, 0x2, 0x2a, 0x2c, 0x5, 0x6, 0x4, 0x2, 0x2b, 0x2a, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x2d, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x33, 0x3, 0x2, 0x2, 0x2, 0x2f, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x30, 0x32, 0x5, 0xa, 0x6, 0x2, 0x31, 0x30, 
    0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 0x2, 0x34, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x36, 0x38, 0x5, 0x8, 0x5, 
    0x2, 0x37, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3a, 
    0x3f, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3e, 
    0x5, 0xe, 0x8, 0x2, 0x3d, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x41, 0x3, 
    0x2, 0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x3, 0x2, 
    0x2, 0x2, 0x40, 0x42, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x42, 0x43, 0x7, 0x1a, 0x2, 0x2, 0x43, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x45, 0x7, 0x9, 0x2, 0x2, 0x45, 0x47, 0x7, 0x3, 0x2, 0x2, 0x46, 
    0x48, 0x5, 0xc, 0x7, 0x2, 0x47, 0x46, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 
    0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4b, 0x7, 
    0x19, 0x2, 0x2, 0x4a, 0x4c, 0x5, 0x10, 0x9, 0x2, 0x4b, 0x4a, 0x3, 0x2, 
    0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4e, 0x3, 0x2, 0x2, 
    0x2, 0x4d, 0x4f, 0x5, 0x12, 0xa, 0x2, 0x4e, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x51, 0x3, 0x2, 0x2, 0x2, 0x50, 
    0x52, 0x5, 0x14, 0xb, 0x2, 0x51, 0x50, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 
    0x3, 0x2, 0x2, 0x2, 0x52, 0x54, 0x3, 0x2, 0x2, 0x2, 0x53, 0x55, 0x5, 
    0x16, 0xc, 0x2, 0x54, 0x53, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x3, 0x2, 
    0x2, 0x2, 0x55, 0x57, 0x3, 0x2, 0x2, 0x2, 0x56, 0x58, 0x5, 0x18, 0xd, 
    0x2, 0x57, 0x56, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 
    0x58, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5b, 0x5, 0x1a, 0xe, 0x2, 0x5a, 
    0x59, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5d, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x5e, 0x5, 0x22, 0x12, 0x2, 0x5d, 0x5c, 0x3, 
    0x2, 0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x5f, 0x60, 0x7, 0x1a, 0x2, 0x2, 0x60, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0x61, 0x62, 0x7, 0xa, 0x2, 0x2, 0x62, 0x63, 0x7, 0x3, 0x2, 0x2, 
    0x63, 0x64, 0x7, 0x19, 0x2, 0x2, 0x64, 0x65, 0x5, 0x20, 0x11, 0x2, 0x65, 
    0x66, 0x7, 0x1a, 0x2, 0x2, 0x66, 0x9, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 
    0x7, 0xb, 0x2, 0x2, 0x68, 0x6a, 0x7, 0x3, 0x2, 0x2, 0x69, 0x6b, 0x5, 
    0xc, 0x7, 0x2, 0x6a, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x3, 0x2, 
    0x2, 0x2, 0x6b, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x19, 0x2, 
    0x2, 0x6d, 0x6e, 0x5, 0x1c, 0xf, 0x2, 0x6e, 0x70, 0x5, 0x1e, 0x10, 0x2, 
    0x6f, 0x71, 0x5, 0x14, 0xb, 0x2, 0x70, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x70, 
    0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 0x73, 0x3, 0x2, 0x2, 0x2, 0x72, 0x74, 
    0x5, 0x16, 0xc, 0x2, 0x73, 0x72, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x3, 
    0x2, 0x2, 0x2, 0x74, 0x76, 0x3, 0x2, 0x2, 0x2, 0x75, 0x77, 0x5, 0x18, 
    0xd, 0x2, 0x76, 0x75, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 
    0x2, 0x77, 0x79, 0x3, 0x2, 0x2, 0x2, 0x78, 0x7a, 0x5, 0x1a, 0xe, 0x2, 
    0x79, 0x78, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7d, 0x5, 0x22, 0x12, 0x2, 0x7c, 0x7b, 
    0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x3, 
    0x2, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x1a, 0x2, 0x2, 0x7f, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x80, 0x85, 0x7, 0x1b, 0x2, 0x2, 0x81, 0x82, 0x7, 0x3, 0x2, 
    0x2, 0x82, 0x84, 0x7, 0x1c, 0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x84, 0x87, 0x3, 0x2, 0x2, 0x2, 0x85, 0x83, 0x3, 0x2, 0x2, 0x2, 0x85, 
    0x86, 0x3, 0x2, 0x2, 0x2, 0x86, 0x88, 0x3, 0x2, 0x2, 0x2, 0x87, 0x85, 
    0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x7, 0x3, 0x2, 0x2, 0x89, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0xc, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x4, 
    0x2, 0x2, 0x8c, 0x8d, 0x7, 0x17, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x3, 0x2, 
    0x2, 0x8e, 0x8f, 0x7, 0x1c, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x3, 0x2, 0x2, 
    0x90, 0x91, 0x7, 0x18, 0x2, 0x2, 0x91, 0x92, 0x7, 0x1d, 0x2, 0x2, 0x92, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x93, 0x98, 0x7, 0xd, 0x2, 0x2, 0x94, 0x95, 
    0x7, 0x4, 0x2, 0x2, 0x95, 0x97, 0x7, 0x1c, 0x2, 0x2, 0x96, 0x94, 0x3, 
    0x2, 0x2, 0x2, 0x97, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x98, 0x96, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x99, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9b, 0x3, 0x2, 0x2, 
    0x2, 0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x7, 0x4, 0x2, 0x2, 
    0x9c, 0x9d, 0x7, 0x1d, 0x2, 0x2, 0x9d, 0x11, 0x3, 0x2, 0x2, 0x2, 0x9e, 
    0xa3, 0x7, 0xe, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x4, 0x2, 0x2, 0xa0, 0xa2, 
    0x7, 0x1c, 0x2, 0x2, 0xa1, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa5, 0x3, 
    0x2, 0x2, 0x2, 0xa3, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 
    0x2, 0x2, 0xa4, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 
    0x2, 0xa6, 0xa7, 0x7, 0x4, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x1d, 0x2, 0x2, 
    0xa8, 0x13, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0xf, 0x2, 0x2, 0xaa, 
    0xb2, 0x7, 0x3, 0x2, 0x2, 0xab, 0xac, 0x7, 0x17, 0x2, 0x2, 0xac, 0xad, 
    0x7, 0x4, 0x2, 0x2, 0xad, 0xae, 0x7, 0x1c, 0x2, 0x2, 0xae, 0xaf, 0x7, 
    0x4, 0x2, 0x2, 0xaf, 0xb1, 0x7, 0x18, 0x2, 0x2, 0xb0, 0xab, 0x3, 0x2, 
    0x2, 0x2, 0xb1, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb0, 0x3, 0x2, 0x2, 
    0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb5, 0x3, 0x2, 0x2, 0x2, 
    0xb4, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x7, 0x1d, 0x2, 0x2, 0xb6, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0x10, 0x2, 0x2, 0xb8, 0xc0, 
    0x7, 0x3, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x17, 0x2, 0x2, 0xba, 0xbb, 0x7, 
    0x4, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0x1c, 0x2, 0x2, 0xbc, 0xbd, 0x7, 0x4, 
    0x2, 0x2, 0xbd, 0xbf, 0x7, 0x18, 0x2, 0x2, 0xbe, 0xb9, 0x3, 0x2, 0x2, 
    0x2, 0xbf, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbe, 0x3, 0x2, 0x2, 0x2, 
    0xc0, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc2, 
    0xc0, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x1d, 0x2, 0x2, 0xc4, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 0x7, 0x11, 0x2, 0x2, 0xc6, 0xc7, 0x7, 
    0x3, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0x1d, 0x2, 0x2, 0xc8, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0xc9, 0xca, 0x7, 0x12, 0x2, 0x2, 0xca, 0xcb, 0x7, 0x3, 0x2, 
    0x2, 0xcb, 0xcc, 0x7, 0x1d, 0x2, 0x2, 0xcc, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0xcd, 0xd2, 0x7, 0x13, 0x2, 0x2, 0xce, 0xcf, 0x7, 0x3, 0x2, 0x2, 0xcf, 
    0xd1, 0x7, 0x1c, 0x2, 0x2, 0xd0, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd4, 
    0x3, 0x2, 0x2, 0x2, 0xd2, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x3, 
    0x2, 0x2, 0x2, 0xd3, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd2, 0x3, 0x2, 
    0x2, 0x2, 0xd5, 0xd6, 0x7, 0x3, 0x2, 0x2, 0xd6, 0xd7, 0x7, 0x1d, 0x2, 
    0x2, 0xd7, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xdd, 0x7, 0x14, 0x2, 0x2, 
    0xd9, 0xda, 0x7, 0x3, 0x2, 0x2, 0xda, 0xdc, 0x7, 0x1c, 0x2, 0x2, 0xdb, 
    0xd9, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdb, 
    0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x3, 0x2, 0x2, 0x2, 0xde, 0xe0, 0x3, 
    0x2, 0x2, 0x2, 0xdf, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0x3, 
    0x2, 0x2, 0xe1, 0xe2, 0x7, 0x1d, 0x2, 0x2, 0xe2, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0xe3, 0xe8, 0x7, 0x15, 0x2, 0x2, 0xe4, 0xe5, 0x7, 0x4, 0x2, 0x2, 
    0xe5, 0xe7, 0x7, 0x1c, 0x2, 0x2, 0xe6, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe7, 
    0xea, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 
    0x3, 0x2, 0x2, 0x2, 0xe9, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe8, 0x3, 
    0x2, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x4, 0x2, 0x2, 0xec, 0xed, 0x7, 0x1d, 
    0x2, 0x2, 0xed, 0x21, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x7, 0x16, 0x2, 
    0x2, 0xef, 0xf0, 0x7, 0x4, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0x1d, 0x2, 0x2, 
    0xf1, 0x23, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x2d, 0x33, 0x39, 0x3f, 0x47, 
    0x4b, 0x4e, 0x51, 0x54, 0x57, 0x5a, 0x5d, 0x6a, 0x70, 0x73, 0x76, 0x79, 
    0x7c, 0x85, 0x98, 0xa3, 0xb2, 0xc0, 0xd2, 0xdd, 0xe8, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ontologyParser::Initializer ontologyParser::_init;
