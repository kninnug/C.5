#include "parser.h"

#include <stdio.h>
#include <stdarg.h>

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

expression_t * makeExpression(int type, size_t length, int operator, ...){
	expression_t * ret = malloc(sizeof *ret);
	size_t i;
	
	ret->length = length;
	ret->type = type;
	ret->operator = operator;
	ret->value = calloc(length, sizeof *ret->value);
	
	va_list ap;
	va_start(ap, operator);
	for(i = 0; i < length; i++){
		if(type) ret->value[i].e = va_arg(ap, expression_t*);
		else ret->value[i].c = va_arg(ap, constant_t*);
	}
	va_end(ap);
	
	return ret;
}

void growExpression(expression_t * ret){
	ret->length++;
	ret->value = realloc(ret->value, ret->length * sizeof *ret->value);
}

void appendExpression(expression_t * exp, expression_t * child){
	growExpression(exp);
	exp->value[exp->length-1].e = child;
}

void appendConstant(expression_t * exp, constant_t * child){
	growExpression(exp);
	exp->value[exp->length-1].c = child;
}

statement_t * makeStatement(){
	statement_t * ret = malloc(sizeof *ret);
	return ret;
}

expstatement_t * makeExpStmt(expression_t * exp){
	expstatement_t * ret = malloc(sizeof *ret);
	ret->exp = exp;
	return ret;
}

compstatement_t * makeCompStmt(){
	compstatement_t * ret = malloc(sizeof *ret);
	ret->length = 0;
	ret->stmts = NULL;
	return ret;
}

size_t growCompStmt(compstatement_t * cs, statement_t * s){
	cs->length++;
	cs->stmts = realloc(cs->stmts, cs->length * sizeof *cs->stmts);
	cs->stmts[cs->length - 1] = s;
	
	return cs->length;
}

ifstatement_t * makeIfStmt(expression_t * cond, statement_t * body){
	ifstatement_t * ret = malloc(sizeof *ret);
	ret->cond = cond;
	ret->body = body;
	ret->otherwise = NULL;
	
	return ret;
}

switchstatement_t * makeSwitchStmt(expression_t * cond, statement_t * body){
	switchstatement_t * ret = malloc(sizeof *ret);
	ret->cond = cond;
	ret->body = body;
	
	return ret;
}

whilestatement_t * makeWhileStmt(expression_t * cond, statement_t * body){
	whilestatement_t * ret = malloc(sizeof *ret);
	ret->cond = cond;
	ret->body = body;
	ret->dowhile = 0;
	
	return ret;
}

forstatement_t * makeForStmt(){
	forstatement_t * ret = malloc(sizeof *ret);
	ret->exp1 = ret->exp2 = ret->exp3 = NULL;
	ret->body = NULL;
	
	return ret;
}

gotostatement_t * makeGotoStmt(int type, constant_t * i){
	gotostatement_t * ret = malloc(sizeof *ret);
	ret->type = type;
	ret->label = i;
}

initializer_t * makeInitializer(){
	initializer_t * ret = malloc(sizeof *ret);
	ret->length = 0;
	ret->values = NULL;
	
	return ret;
}

void growInitializeri(initializer_t * iz, initializer_t * i){
	iz->length++;
	iz->values = realloc(iz->values, iz->length * sizeof *iz->values);
	iz->values[iz->length - 1].type = 0;
	iz->values[iz->length - 1].iz = i;
}

void growInitializera(initializer_t * iz, expression_t * ae){
	iz->length++;
	iz->values = realloc(iz->values, iz->length * sizeof *iz->values);
	iz->values[iz->length - 1].type = 1;
	iz->values[iz->length - 1].ae = ae;
}

identlist_t * makeIdentlist(){
	identlist_t * ret = malloc(sizeof *ret);
	ret->length = 0;
	ret->idents = NULL;
}

void growIdentlist(identlist_t * il, constant_t * i){
	il->length++;
	il->idents = realloc(il->idents, il->length * sizeof *il->idents);
	il->idents[il->length - 1] = i;
}

void mergeTypeTs(type_t * out, type_t * in){
	out->storeAuto |= in->storeAuto;
	out->storeStatic |= in->storeStatic;
	out->storeRegister |= in->storeRegister;
	out->storeExtern |= in->storeExtern;
	
	out->qualConst |= in->qualConst;
	out->qualVolatile |= in->qualVolatile;
	
	out->signedness |= in->signedness;
	out->longness = in->longness;
	out->type = in->type;
}

returnstatement_t * makeReturnStmt(){
	returnstatement_t * ret = malloc(sizeof *ret);
	ret->value = NULL;
	
	return ret;
}

void printExpression(const expression_t * exp, size_t level){
	size_t i, j;
	if(!exp) return;
	
	level++;
	
	putchar('(');
	printf("%c:`%c`[%i]\n", (exp->type ? 'e' : 'c'), exp->operator, exp->operator);
	for(i = 0; i < exp->length; i++){
		for(j = 0; j < level; j++) printf("    ");
		printf("%u = ", i);
		
		if(!exp->type){
			printConstant(exp->value[i].c);
		}
		else printExpression(exp->value[i].e, level);
	}
	putchar(')');
	putchar('\n');
}

void printConstant(const constant_t * c){
	if(!c) return;
	switch(c->type){
		case INTCONST: printf("%lu", c->value.i); break;
		case FLOATCONST: printf("%lf", c->value.d); break;
		case IDCONST:
		case STRINGCONST: printf("%s", c->value.s); break;
	}
}

void printCompStmt(const compstatement_t * cs){
	size_t i;
	puts("{\n");
	for(i = 0; i < cs->length; i++){
		printStatement(cs->stmts[i]);
	}
	puts("}\n");
}

void printStatement(const statement_t * s){
	switch(s->type){
		case 'c': printCompStmt(s->comps); break;
		case 'e': printExpression(s->exps->exp, 0); break;
		case 'i': 
			puts("if");
			printExpression(s->ifs->cond, 0);
			printStatement(s->ifs->body);
			if(s->ifs->otherwise){
				puts("else");
				printStatement(s->ifs->otherwise);
			}
		break;
		case 's':
			puts("switch");
			printExpression(s->switchs->cond, 0);
			printStatement(s->switchs->body);
		break;
		case 'w':
			if(s->whiles->dowhile){
				puts("do");
				printStatement(s->whiles->body);
			}
			puts("while");
			printExpression(s->whiles->cond, 0);
			if(s->whiles->dowhile) puts(";\n");
			else printStatement(s->whiles->body);
		break;
		case 'f':
			puts("for(");
			if(s->fors->exp1) printExpression(s->fors->exp1, 0);
			puts("; ");
			if(s->fors->exp1) printExpression(s->fors->exp2, 0);
			puts("; ");
			if(s->fors->exp1) printExpression(s->fors->exp3, 0);
			puts(")");
			printStatement(s->fors->body);
		break;
		case 'r':
			puts("return");
			if(s->returns->value != NULL){
				putchar(' ');
				printExpression(s->returns->value, 0);
			}
			puts(";\n");
		break;
	}
}

void printInitializer(initializer_t * iz){
	size_t i;
	putchar('{');
	for(i = 0; i < iz->length; i++){
		if(iz->values[i].type) printExpression(iz->values[i].ae, 0);
		else printInitializer(iz->values[i].iz);
		if(i < iz->length - 1) puts(", ");
	}
	putchar('}');
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
