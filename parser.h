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

#define YYSTYPE union lexeme

typedef struct constant{
	int type;
	union{
		unsigned long int i;
		double d;
		char * s;
	} value;
}constant_t;

typedef struct expression{
	int type;
	size_t length;
	int operator;
	union{
		constant_t * c;
		struct expression * e;
	} value;
} expression_t;

#endif
