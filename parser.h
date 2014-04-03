#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include <string.h>

union lexeme{
	unsigned long int i; /* the lexer doesn't parse the preceding '-' */
	double d;
	int c; /* character-literals are ints! */
	char * s;
	
	enum { ASSIGN_ASSIGN, ASSIGN_SHLEFT, ASSIGN_SHRIGHT, ASSIGN_PLUS, 
		ASSIGN_MINUS, ASSIGN_TIMES, ASSIGN_DIVIDE, ASSIGN_MOD, 
		ASSIGN_OR, ASSIGN_AND, ASSIGN_XOR, ASSIGN_SWAP,
		
		SHIFT_LEFT, SHIFT_RIGHT, 
		
		COMPARE_LEQ, COMPARE_GREQ, COMPARE_EQUAL, COMPARE_UNEQUAL,
		COMPARE_LESS, COMPARE_GREATER
	} subtype;
	
	char * text;
};

enum consttypes { INTCONST, FLOATCONST, STRINGCONST, IDCONST };

#define YYSTYPE union lexeme

struct statement;
typedef struct statement statement_t;

typedef struct type{
	/* storage class */
	unsigned storeAuto : 1;
	unsigned storeStatic : 1;
	unsigned storeRegister : 1;
	unsigned storeExtern : 1;
	/* qualifiers */
	unsigned qualConst : 1;
	unsigned qualVolatile : 1;
	/* specifiers */
	unsigned signedness : 1;
	unsigned longness : 2; /* 0: unspecified / normal, 1: short, 2: long, 3: undefined */
	unsigned type : 2; /* 0: int, 1: char, 2: float (double is a long float), 3: void */
} type_t;

typedef struct constant{
	enum consttypes type;
	union{
		unsigned long int i;
		double d;
		char * s;
	} value;
}constant_t, *constant_pt;

typedef struct expression{
	int type;
	size_t length;
	int operator;
	union expressionChildren{
		constant_t * c;
		struct expression * e;
	} * value;
} expression_t, * expression_pt;

typedef struct ifstatement{
	expression_t * cond;
	statement_t * body;
	statement_t * otherwise;
} ifstatement_t, * ifstatement_pt;

typedef struct whilestatement{
	int dowhile;
	expression_t * cond;
	statement_t * body;
} whilestatement_t, * whilestatement_pt;

typedef struct forstatement{
	expression_t * exp1, * exp2, * exp3;
	statement_t * body;
} forstatement_t, * forstatement_pt;

typedef struct gotostatement{
	constant_t * label;
	int type;
} gotostatement_t, * gotostatement_pt;

typedef struct returnstatement{
	expression_t * value;
} returnstatement_t, * returnstatement_pt;

typedef struct switchstatement{
	expression_t * cond;
	statement_t * body;
} switchstatement_t, * switchstatement_pt;

typedef struct labelstatement{
	char * id;
} labelstatement_t, * labelstatement_pt;

typedef struct expstatement{
	expression_t * exp;
} expstatement_t, * expstatement_pt;

typedef struct declaration{
	char * name;
	type_t type;
	expression_t * value;
} declaration_t, * declaration_pt;

typedef struct compstatement{
	size_t length;
	statement_t ** stmts;
	declaration_t ** decls;
} compstatement_t, * compstatement_pt;

typedef struct statement{
	int type;
	union{
		ifstatement_t * ifs;
		whilestatement_t * whiles;
		forstatement_t * fors;
		gotostatement_t * gotos;
		returnstatement_t * returns;
		switchstatement_t * switchs;
		labelstatement_t * labels;
		expstatement_t * exps;
		compstatement_t * comps;
	};
} * statement_pt;

typedef struct initializer{
	size_t length;
	struct{
		int type;
		union{
			struct initializer * iz;
			expression_t * ae;
		};
	} * values;
} initializer_t, * initializer_pt;

typedef struct identifier{
	char * s;
} identifier_t, * identifier_pt;

typedef struct identlist{
	size_t length;
	constant_t ** idents;
} identlist_t, * identlist_pt;

char* mystrdup(const char * yytext);

constant_t * makeIntConst(unsigned long int i);
constant_t * makeFloatConst(double d);
constant_t * makeStringConst(const char * s);

expression_t * makeExpression(int type, size_t length, int operator, ...);

statement_t * makeStatement();
expstatement_t * makeExpStmt(expression_t * exp);
compstatement_t * makeCompStmt();
ifstatement_t * makeIfStmt(expression_t * cond, statement_t * body);
switchstatement_t * makeSwitchStmt(expression_t * cond, statement_t * body);
whilestatement_t * makeWhileStmt(expression_t * cond, statement_t * body);
forstatement_t * makeForStmt();
gotostatement_t * makeGotoStmt(int type, constant_t * i);

size_t growCompStmt(compstatement_t * cs, statement_t * s);

initializer_t * makeInitializer();
identlist_t * makeIdentlist();

void growInitializeri(initializer_t * iz, initializer_t * i);
void growInitializera(initializer_t * iz, expression_t * ae);
void growIdentlist(identlist_t * il, constant_t * i);

void mergeTypeTs(type_t * out, type_t * in);

void printExpression(const expression_t * exp, size_t level);
void printConstant(const constant_t * c);

void printStatement(const statement_t * s);
void printInitializer(initializer_t * iz);

#endif
