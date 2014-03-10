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
		ASSIGN_OR, ASSIGN_AND, ASSIGN_XOR,
		
		SHIFT_LEFT, SHIFT_RIGHT, 
		
		BIT_AND, BIT_OR, BIT_XOR, BIT_NOT,
		
		COMPARE_LEQ, COMPARE_GREQ, COMPARE_EQUAL, COMPARE_UNEQUAL,
		COMPARE_LESS, COMPARE_GREATER,
		
		LOGIC_AND, LOGIC_OR} subtype;
};

#define YYSTYPE union lexeme

#endif
