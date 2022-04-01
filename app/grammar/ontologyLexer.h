
// Generated from c:\Users\Admin\Desktop\ODE\ontology.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  ontologyLexer : public antlr4::Lexer {
public:
  enum {
    NAME = 1, STRING = 2, NEWLINE = 3, WHITESPACE = 4, TAB = 5, FRAME = 6, 
    CLASS = 7, ENUMERATION = 8, ACTIVITY = 9, ASSOCIATION = 10, ATTRIBUTES = 11, 
    OPERATIONS = 12, AGGREGATION = 13, COMPOSITION = 14, DEPENDENCY = 15, 
    IMPLEMENTATION = 16, INPUT = 17, OUTPUT = 18, LITERALS = 19, COMMENT = 20, 
    LBRACKET = 21, RBRACKET = 22, LBRACE = 23, RBRACE = 24, COLON = 25, 
    COMMA = 26, SEMICOLON = 27
  };

  ontologyLexer(antlr4::CharStream *input);
  ~ontologyLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

