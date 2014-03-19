#include "parser.h"

/**
 * Since strdup is *not* C-standard it isn't always available
 * instead of mucking about with feature-test-macros we simply
 * define our own, with a different name so as to not cause linker-errors
*/
char * mystrdup(const char * src){
	size_t len = strlen(src);
	char * dst = malloc(len + 1);
	if(dst) strcpy(dst, src);
	return dst;
}

constant_t * makeIntConst(unsigned long int i){
	constant_t * ret = malloc(sizeof *ret);
	ret->type = INTCONST;
	ret->value.i = i;
	return ret;
}

constant_t * makeFloatConst(double d){
	constant_t * ret = malloc(sizeof *ret);
	ret->type = FLOATCONST;
	ret->value.d = d;
	return ret;
}

constant_t * makeStringConst(const char * s){
	constant_t * ret = malloc(sizeof *ret);
	ret->type = STRINGCONST;
	ret->value.s = mystrdup(s);
	return ret;
}

expression_t * makeExpression(int type, size_t length, int operator){
	expression_t * ret = malloc(sizeof *ret);
	ret->length = length;
	ret->type = type;
	ret->operator = operator;
	if(type){ /* expression */
		ret->value.c = calloc(length, sizeof *ret->value.c);
	}else{ /* constant */
		ret->value.e = calloc(length, sizeof *ret->value.e);
	}
	return ret;
}

/*
int i = 0;
i = ++i;

int rhs;

rhs = i + 1; // result of ++i
i = i + 1; // side effect of ++i
i = rhs; // assignment

rhs = i + 1; // result of ++i
i = rhs; // assignment
i = i + 1; // side effect of ++i
*/
