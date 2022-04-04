grammar ontology;

NAME                : '<' SYMS '>';
STRING              : '"' SYMS '"';
NEWLINE             : ('\r'? '\n' | '\r')+ -> skip;
WHITESPACE          : ' ' -> skip;
TAB                 : '\t' -> skip;
PACKAGE             : 'Package';
CLASS               : 'Class';
ENUMERATION         : 'Enumeration';
ACTIVITY            : 'Activity';
ASSOCIATION         : 'Association';
ATTRIBUTES          : 'attributes';
OPERATIONS          : 'operations';
AGGREGATION         : 'aggregation';
COMPOSITION         : 'composition';
DEPENDENCY          : 'dependency';
IMPLEMENTATION      : 'implementation';
INPUT               : 'input';
OUTPUT              : 'output';
LITERALS            : 'literals';
COMMENT             : 'comment';
LBRACKET            : '(';
RBRACKET            : ')';
LBRACE              : '{';
RBRACE              : '}';
COLON               : ':';
COMMA               : ',';
SEMICOLON           : ';';
fragment SYMS       :  .*?;                              //???                   


file                : package EOF;
package             : PACKAGE NAME LBRACE class_* act* enum_* assoc* RBRACE;
class_              : CLASS NAME gen? LBRACE attr? oper? aggr? comp? dep? impl? comm? RBRACE;
enum_               : ENUMERATION NAME LBRACE enum_literals RBRACE;
act                 : ACTIVITY NAME gen? LBRACE in out aggr? comp? dep? impl? comm? RBRACE;
gen                 : COLON (NAME COMMA)* NAME;
assoc               : ASSOCIATION STRING LBRACKET NAME COMMA NAME RBRACKET SEMICOLON;
attr                : ATTRIBUTES (STRING COMMA)* STRING SEMICOLON;
oper                : OPERATIONS (STRING COMMA)* STRING SEMICOLON;
aggr                : AGGREGATION NAME (LBRACKET STRING COMMA STRING RBRACKET)* SEMICOLON;
comp                : COMPOSITION NAME (LBRACKET STRING COMMA STRING RBRACKET)* SEMICOLON;
dep                 : DEPENDENCY NAME SEMICOLON;
impl                : IMPLEMENTATION NAME SEMICOLON;
in                  : INPUT (NAME COMMA)* NAME SEMICOLON;
out                 : OUTPUT (NAME COMMA)* NAME SEMICOLON;
enum_literals       : LITERALS (STRING COMMA)* STRING SEMICOLON;
comm                : COMMENT STRING SEMICOLON;