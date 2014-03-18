/**
 * C lexer, by Marco Gunnink (2170248) and Bart Offereins (2255243)
 * inspired by http://www.lysator.liu.se/c/ANSI-C-grammar-l.html
*/

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "parser.h"
#include "yygrammar.h"

/* Warning: older compilers may complain about the %zu printf-specifier as it's
	C99 feature. Not on a recent (4.8.1) GCC, even with -ansi -pedantic... */
size_t column = 1;
extern long int yypos;

/* Keeps track of lines (and columns, though not accurately anymore) */
void count();
/* Eats multi-line comments */
void comment();


char* mystrdup(char* yytext);

/* Surpress implicit-declarations under MinGW (this function isn't used anyway) */
int fileno(FILE*);

/* We copy keyword-names into yylval.s to eliminate having 
to retype them all into the parser for pretty-printing.
Same for operator-characters into yylval.c. 

Similar for string- and character-literals: we copy the matched text
into yylval.s (also for characters), so that they can be printed with
quotes and all directly from yylval. */
%}

%%
"/*"			{ comment(); }

"include"		{ count(); yylval.s = mystrdup(yytext); return INCLUDE; }

"auto"			{ count(); yylval.s = mystrdup(yytext); return AUTO; }
"break"			{ count(); yylval.s = mystrdup(yytext); return BREAK; }
"case"			{ count(); yylval.s = mystrdup(yytext); return CASE; }
"char"			{ count(); yylval.s = mystrdup(yytext); return CHAR; }
"const"			{ count(); yylval.s = mystrdup(yytext); return CONST; }
"continue"		{ count(); yylval.s = mystrdup(yytext); return CONTINUE; }
"default"		{ count(); yylval.s = mystrdup(yytext); return DEFAULT; }
"do"			{ count(); yylval.s = mystrdup(yytext); return DO; }
"double"		{ count(); yylval.s = mystrdup(yytext); return DOUBLE; }
"else"			{ count(); yylval.s = mystrdup(yytext); return ELSE; }
"enum"			{ count(); yylval.s = mystrdup(yytext); return ENUM; }
"extern"		{ count(); yylval.s = mystrdup(yytext); return EXTERN; }
"float"			{ count(); yylval.s = mystrdup(yytext); return FLOAT; }
"for"			{ count(); yylval.s = mystrdup(yytext); return FOR; }
"goto"			{ count(); yylval.s = mystrdup(yytext); return GOTO; }
"if"			{ count(); yylval.s = mystrdup(yytext); return IF; }
"int"			{ count(); yylval.s = mystrdup(yytext); return INT; }
"long"			{ count(); yylval.s = mystrdup(yytext); return LONG; }
"register"		{ count(); yylval.s = mystrdup(yytext); return REGISTER; }
"return"		{ count(); yylval.s = mystrdup(yytext); return RETURN; }
"short"			{ count(); yylval.s = mystrdup(yytext); return SHORT; }
"signed"		{ count(); yylval.s = mystrdup(yytext); return SIGNED; }
"sizeof"		{ count(); yylval.s = mystrdup(yytext); return SIZEOF; }
"static"		{ count(); yylval.s = mystrdup(yytext); return STATIC; }
"struct"		{ count(); yylval.s = mystrdup(yytext); return STRUCT; }
"switch"		{ count(); yylval.s = mystrdup(yytext); return SWITCH; }
"typedef"		{ count(); yylval.s = mystrdup(yytext); return TYPEDEF; }
"union"			{ count(); yylval.s = mystrdup(yytext); return UNION; }
"unsigned"		{ count(); yylval.s = mystrdup(yytext); return UNSIGNED; }
"void"			{ count(); yylval.s = mystrdup(yytext); return VOID; }
"volatile"		{ count(); yylval.s = mystrdup(yytext); return VOLATILE; }
"while"			{ count(); yylval.s = mystrdup(yytext); return WHILE; }
"print"			{ count(); yylval.s = mystrdup(yytext); return PRINT; }
"input"			{ count(); yylval.s = mystrdup(yytext); return INPUT; }


{L}({L}|{D})*			{ count(); yylval.s = mystrdup(yytext); return IDENTIFIER; }

0[xX]{H}+{IS}?			{ count(); yylval.i = strtoul(yytext, NULL, 10); return INTCONST; }
0{D}+{IS}?				{ count(); yylval.i = strtoul(yytext, NULL, 10); return INTCONST; }
{D}+{IS}?				{ count(); yylval.i = strtoul(yytext, NULL, 10); return INTCONST; }

L?'(\\.|[^\\'])'		{ count(); yylval.s = mystrdup(yytext); return CHARACTER; }
	/* Note: multi-character constants *are* legal (K&R 2: A2.5.2 (page 193)): 
	 * "A character constant is a sequence of one or more characters enclosed in single quotes, as in 'x'." */
L?'(\\.|[^\\']){2,}		{ count(); printf("%zu:%zu: Illegal or unterminated character constant....abort\n", yypos, column); exit(-1); }

L?\"(\\.|[^\\"\n])*\"		{ count(); yylval.s = mystrdup(yytext); return STRING; }

{D}+{E}{FS}?			{ count(); yylval.d = strtod(yytext, NULL); return FLOATCONST; }
{D}*"."{D}+({E})?{FS}?	{ count(); yylval.d = strtod(yytext, NULL); return FLOATCONST; }
{D}+"."{D}*({E})?{FS}?	{ count(); yylval.d = strtod(yytext, NULL); return FLOATCONST; }

"..."			{ count(); return ELLIPSIS; }

"="				{ count(); yylval.c = '='; return '='; }
">>="			{ count(); yylval.subtype = ASSIGN_SHRIGHT; return ASSIGN; }
"<<="			{ count(); yylval.subtype = ASSIGN_SHLEFT; return ASSIGN; }
"+="			{ count(); yylval.subtype = ASSIGN_PLUS; return ASSIGN; }
"-="			{ count(); yylval.subtype = ASSIGN_MINUS; return ASSIGN; }
"*="			{ count(); yylval.subtype = ASSIGN_TIMES; return ASSIGN; }
"/="			{ count(); yylval.subtype = ASSIGN_DIVIDE; return ASSIGN; }
"%="			{ count(); yylval.subtype = ASSIGN_MOD; return ASSIGN; }
"&="			{ count(); yylval.subtype = ASSIGN_AND; return ASSIGN; }
"^="			{ count(); yylval.subtype = ASSIGN_XOR; return ASSIGN; }
"|="			{ count(); yylval.subtype = ASSIGN_OR; return ASSIGN; }
"<->"			{ count(); yylval.subtype = ASSIGN_SWAP; return ASSIGN; }


">>"			{ count(); yylval.subtype = SHIFT_RIGHT; return SHIFT; }
"<<"			{ count(); yylval.subtype = SHIFT_LEFT; return SHIFT; }

"**"			{ count(); return EXP; }

"&"				{ count(); yylval.c = '&'; return BIT_AND; }
"^"				{ count(); yylval.c = '^'; return BIT_XOR; }
"|"				{ count(); yylval.c = '|'; return BIT_OR; }
"~"				{ count(); yylval.c = '~'; return BIT_NOT; }

"<="			{ count(); yylval.subtype = COMPARE_LEQ; return COMPARE; }
">="			{ count(); yylval.subtype = COMPARE_GREQ; return COMPARE; }
"=="			{ count(); yylval.subtype = COMPARE_EQUAL; return COMPARE; }
"!="			{ count(); yylval.subtype = COMPARE_UNEQUAL; return COMPARE; }
"<"				{ count(); yylval.subtype = COMPARE_LESS; return COMPARE; }
">"				{ count(); yylval.subtype = COMPARE_GREATER; return COMPARE; }

"&&"			{ count(); return LOGICAL_AND; }
"||"			{ count(); return LOGICAL_OR; }

"++"			{ count(); return INC_OP; }
"--"			{ count(); return DEC_OP; }

"->"			{ count(); return PTR_OP; }

";"				{ count(); yylval.c = ';'; return ';'; }
("{"|"<%")		{ count(); yylval.c = '{'; return '{'; } /* Who *doesn't* like di-graphs? -_- */
("}"|"%>")		{ count(); yylval.c = '}'; return '}'; }
","				{ count(); yylval.c = ','; return ','; }
":"				{ count(); yylval.c = ':'; return ':'; }
"("				{ count(); yylval.c = '('; return '('; }
")"				{ count(); yylval.c = ')'; return ')'; }
("["|"<:")		{ count(); yylval.c = '['; return '['; }
("]"|":>")		{ count(); yylval.c = ']'; return ']'; }
"."				{ count(); yylval.c = '.'; return '.'; }
"!"				{ count(); yylval.c = '!'; return '!'; }
"-"				{ count(); yylval.c = '-'; return '-'; }
"+"				{ count(); yylval.c = '+'; return '+'; }
"*"				{ count(); yylval.c = '*'; return '*'; }
"/"				{ count(); yylval.c = '/'; return '/'; }
"%"				{ count(); yylval.c = '%'; return '%'; }
"?"				{ count(); yylval.c = '?'; return '?'; }
"#"				{ count(); yylval.c = '#'; return '#'; }

[ \t\v\f\n]		{ count(); }

.				{ count();
		int c = yytext[0]; 
		printf("%zu:%zu: Illegal character (", yypos, column);
		
		if(isprint(c)) putchar(c); 
		else printf("%i", c);
		
		printf(")....abort\n"); 
		exit(-1); 
	}

%%

void comment(){
	char c, c1;
	
	column += 2;
	
	while((c = input()) != 0){
		if(c == '\n'){
			yypos++;
			column = 0;
		}
		column++;
		
		if(c == '*'){
			c1 = input();
			if(c1 == 0) return;
			if(c1 == '/') break;
			
			unput(c1);
		}
	}
	
	column++;
}

/**
 * Since strdup is *not* C-standard it isn't always available
 * instead of mucking about with feature-test-macros we simply
 * define our own, with a different name so as to not cause linker-errors
*/
char * mystrdup(char * src){
	size_t len = strlen(src);
	char * dst = malloc(len + 1);
	if(dst) strcpy(dst, src);
	return dst;
}

/**
 * Colum-count is no longer accurate, but the linenr (yypos) is
*/
void count(){
	int i;

	for (i = 0; yytext[i] != '\0'; i++){
		if (yytext[i] == '\n'){
			yypos++;
			column = 1;
		}else column++;
	}
}
