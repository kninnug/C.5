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
/* Warning: older compilers may complain about the %zu printf-specifier as it's
	C99 feature. Not on a recent (4.8.1) GCC, even with -ansi -pedantic... */
size_t linenr = 1, column = 1;

/* We return character-literals for many single-character tokens, start these 
	with 256 to make sure they never collide */
	AUTO = 256, BREAK, CASE, CHAR, CONST, CONTINUE, DEFAULT, DO, 
	DOUBLE, ELSE, ENUM, EXTERN, FLOAT, FOR, GOTO, IF, INT, LONG, REGISTER, 
	RETURN, SHORT, SIGNED, SIZEOF, STATIC, STRUCT, SWITCH, TYPEDEF, UNION, 
	UNSIGNED, VOID, VOLATILE, WHILE, CONSTANT, STRING_LITERAL, ELLIPSIS, 
	ASSIGN, COMPARE, ARIT_OP, INC_OP, DEC_OP, PTR_OP, LOGIC_OP, IDENTIFIER, 
	PREPROC, BIT_OP, INCLUDE, CHARACTER, FLOATCONST, INTCONST
}; */

/* Keeps track of lines and columns */
void count();
/* Eats multi-line comments */
void comment();

/* Surpress implicit-declarations under MinGW (this function isn't used anyway) */
int fileno(FILE*);
%}

%%
"/*"			{ comment(); }

"include"		{ return INCLUDE; }

"auto"			{ return AUTO; }
"break"			{ return BREAK; }
"case"			{ return CASE; }
"char"			{ return CHAR; }
"const"			{ return CONST; }
"continue"		{ return CONTINUE; }
"default"		{ return DEFAULT; }
"do"			{ return DO; }
"double"		{ return DOUBLE; }
"else"			{ return ELSE; }
"enum"			{ return ENUM; }
"extern"		{ return EXTERN; }
"float"			{ return FLOAT; }
"for"			{ return FOR; }
"goto"			{ return GOTO; }
"if"			{ return IF; }
"int"			{ return INT; }
"long"			{ return LONG; }
"register"		{ return REGISTER; }
"return"		{ return RETURN; }
"short"			{ return SHORT; }
"signed"		{ return SIGNED; }
"sizeof"		{ return SIZEOF; }
"static"		{ return STATIC; }
"struct"		{ return STRUCT; }
"switch"		{ return SWITCH; }
"typedef"		{ return TYPEDEF; }
"union"			{ return UNION; }
"unsigned"		{ return UNSIGNED; }
"void"			{ return VOID; }
"volatile"		{ return VOLATILE; }
"while"			{ return WHILE; }

{L}({L}|{D})*			{ return IDENTIFIER; }

0[xX]{H}+{IS}?			{ return INTCONST; }
0{D}+{IS}?				{ return INTCONST; }
{D}+{IS}?				{ return INTCONST; }
L?'(\\.|[^\\'])'		{ return CHARACTER; }
	/* Note: multi-character constants *are* legal (K&R 2: A2.5.2 (page 193)): 
	 * "A character constant is a sequence of one or more characters enclosed in single quotes, as in 'x'." */
L?'(\\.|[^\\']){2,}		{ printf("%zu:%zu: Illegal or unterminated character constant....abort\n", linenr, column); exit(-1); }

{D}+{E}{FS}?			{ return FLOATCONST; }
{D}*"."{D}+({E})?{FS}?	{ return FLOATCONST; }
{D}+"."{D}*({E})?{FS}?	{ return FLOATCONST; }

L?\"(\\.|[^\\"\n])*\"		{ return STRING_LITERAL; }

"..."			{ return ELLIPSIS; }

"="				{ return ASSIGN; }
">>="			{ return ASSIGN; }
"<<="			{ return ASSIGN; }
"+="			{ return ASSIGN; }
"-="			{ return ASSIGN; }
"*="			{ return ASSIGN; }
"/="			{ return ASSIGN; }
"%="			{ return ASSIGN; }
"&="			{ return ASSIGN; }
"^="			{ return ASSIGN; }
"|="			{ return ASSIGN; }

">>"			{ return ARIT_OP; }
"<<"			{ return ARIT_OP; }

"&"				{ return BIT_OP; }
"^"				{ return BIT_OP; }
"|"				{ return BIT_OP; }
"~"				{ return BIT_OP; }

"<="			{ return COMPARE; }
">="			{ return COMPARE; }
"=="			{ return COMPARE; }
"!="			{ return COMPARE; }
"<"				{ return COMPARE; }
">"				{ return COMPARE; }

"&&"			{ return LOGIC_OP; }
"||"			{ return LOGIC_OP; }

"++"			{ return INC_OP; }
"--"			{ return DEC_OP; }

"->"			{ return PTR_OP; }

";"				{ return ';'; }
("{"|"<%")		{ return '{'; } /* Who *doesn't* like di-graphs? -_- */
("}"|"%>")		{ return '}'; }
","				{ return ','; }
":"				{ return ':'; }
"("				{ return '('; }
")"				{ return(')'); }
("["|"<:")		{ return '['; }
("]"|":>")		{ return ']'; }
"."				{ return '.'; }
"!"				{ return '!'; }
"-"				{ return '-'; }
"+"				{ return '+'; }
"*"				{ return '*'; }
"/"				{ return '/'; }
"%"				{ return '%'; }
"?"				{ return '?'; }
"#"				{ return '#'; }

[ \t\v\f\n]		{ count(); }

.				{ 
		int c = yytext[0]; 
		printf("%zu:%zu: Illegal character (", linenr, column);
		
		if(isprint(c)) putchar(c); 
		else printf("%i", c);
		
		printf(")....abort\n"); 
		exit(-1); 
	}

%%

int yywrap(){
	return 1;
}

void comment(){
	char c, c1;
	
	column += 2;
	
	while((c = input()) != 0){
		if(c == '\n'){
			linenr++;
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

void count(){
	int i;

	for (i = 0; yytext[i] != '\0'; i++){
		if (yytext[i] == '\n'){
			linenr++;
			yypos = linenr;
			column = 1;
		}else column++;
		/* <Rant> The original included a case for tabs, reporting them as 8 columns.
		Everyone knows that tabs are never replaced by spaces, but always 
		displayed with a maximum width of 4 spaces. Aligned with the tab-stop.
		</Rant> */
	}
}

int main(int argc, char ** argv){
	int t;
	
	if(argc > 1) yyin = fopen(argv[1], "r");
	
	while((t = yylex())){
		printf("%zu:%zu:%d @%s@\n", linenr, column, t, yytext);
		count();
	}
	
	fclose(yyin);
	
	return 0;
}
