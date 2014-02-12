D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include <stdio.h>

int linenr = 0;

enum tokens {AUTO, BREAK, CASE, CHAR, CONST, CONTINUE, DEFAULT, DO, DOUBLE, ELSE, ENUM, EXTERN, FLOAT, FOR, GOTO, IF, INT, LONG, REGISTER, RETURN, SHORT, SIGNED, SIZEOF, STATIC, STRUCT, SWITCH, TYPEDEF, UNION, UNSIGNED, VOID, VOLATILE, WHILE, CONSTANT, STRING_LITERAL, ELLIPSIS, ASSIGN, COMPARE, ARIT_OP, INC_OP, DEC_OP, PTR_OP, LOGIC_OP, IDENTIFIER};

void count();
void comment();
int check_type();

int fileno(FILE*);
%}

%%
"/*"			{ comment(); }
"#"(\\\n|[^\n])*"\n"	{ count(); printf("Preproc: %s", yytext); }

"auto"			{ count(); return(AUTO); }
"break"			{ count(); return(BREAK); }
"case"			{ count(); return(CASE); }
"char"			{ count(); return(CHAR); }
"const"			{ count(); return(CONST); }
"continue"		{ count(); return(CONTINUE); }
"default"		{ count(); return(DEFAULT); }
"do"			{ count(); return(DO); }
"double"		{ count(); return(DOUBLE); }
"else"			{ count(); return(ELSE); }
"enum"			{ count(); return(ENUM); }
"extern"		{ count(); return(EXTERN); }
"float"			{ count(); return(FLOAT); }
"for"			{ count(); return(FOR); }
"goto"			{ count(); return(GOTO); }
"if"			{ count(); return(IF); }
"int"			{ count(); return(INT); }
"long"			{ count(); return(LONG); }
"register"		{ count(); return(REGISTER); }
"return"		{ count(); return(RETURN); }
"short"			{ count(); return(SHORT); }
"signed"		{ count(); return(SIGNED); }
"sizeof"		{ count(); return(SIZEOF); }
"static"		{ count(); return(STATIC); }
"struct"		{ count(); return(STRUCT); }
"switch"		{ count(); return(SWITCH); }
"typedef"		{ count(); return(TYPEDEF); }
"union"			{ count(); return(UNION); }
"unsigned"		{ count(); return(UNSIGNED); }
"void"			{ count(); return(VOID); }
"volatile"		{ count(); return(VOLATILE); }
"while"			{ count(); return(WHILE); }

{L}({L}|{D})*			{ count(); return(check_type()); }

0[xX]{H}+{IS}?			{ count(); return(CONSTANT); }
0{D}+{IS}?				{ count(); return(CONSTANT); }
{D}+{IS}?				{ count(); return(CONSTANT); }
L?'(\\.|[^\\'])+'		{ count(); return(CONSTANT); }

{D}+{E}{FS}?			{ count(); return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ count(); return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ count(); return(CONSTANT); }

L?\"(\\.|[^\\"])*\"		{ count(); return(STRING_LITERAL); }

"..."			{ count(); return(ELLIPSIS); }
">>="			{ count(); return(ASSIGN); }
"<<="			{ count(); return(ASSIGN); }
"+="			{ count(); return(ASSIGN); }
"-="			{ count(); return(ASSIGN); }
"*="			{ count(); return(ASSIGN); }
"/="			{ count(); return(ASSIGN); }
"%="			{ count(); return(ASSIGN); }
"&="			{ count(); return(ASSIGN); }
"^="			{ count(); return(ASSIGN); }
"|="			{ count(); return(ASSIGN); }
">>"			{ count(); return(ARIT_OP); }
"<<"			{ count(); return(ARIT_OP); }
"++"			{ count(); return(INC_OP); }
"--"			{ count(); return(DEC_OP); }
"->"			{ count(); return(PTR_OP); }
"&&"			{ count(); return(LOGIC_OP); }
"||"			{ count(); return(LOGIC_OP); }
"<="			{ count(); return(COMPARE); }
">="			{ count(); return(COMPARE); }
"=="			{ count(); return(COMPARE); }
"!="			{ count(); return(COMPARE); }
";"				{ count(); return(';'); }
("{"|"<%")		{ count(); return('{'); }
("}"|"%>")		{ count(); return('}'); }
","				{ count(); return(','); }
":"				{ count(); return(':'); }
"="				{ count(); return('='); }
"("				{ count(); return('('); }
")"				{ count(); return(')'); }
("["|"<:")		{ count(); return('['); }
("]"|":>")		{ count(); return(']'); }
"."				{ count(); return('.'); }
"&"				{ count(); return('&'); }
"!"				{ count(); return('!'); }
"~"				{ count(); return('~'); }
"-"				{ count(); return('-'); }
"+"				{ count(); return('+'); }
"*"				{ count(); return('*'); }
"/"				{ count(); return('/'); }
"%"				{ count(); return('%'); }
"<"				{ count(); return('<'); }
">"				{ count(); return('>'); }
"^"				{ count(); return('^'); }
"|"				{ count(); return('|'); }
"?"				{ count(); return('?'); }
"\n"			{ count(); linenr++; }
[ \t\v\f]		{ count(); }
.				{ /* ignore bad characters */ }

%%

int yywrap(){
	return(1);
}

void comment(){
	char c, c1;
	
	printf("Comment: ");
	
	while((c = input()) != 0){
		if(c == '*'){
			c1 = input();
			if(c1 == 0) return;
			if(c1 == '/') break;
			
			unput(c1);
		}
		
		putchar(c);
	}
	
	putchar('\n');
}

int column = 0;

void count(){
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	/* ECHO; */
}

int check_type(){
	/*
	* pseudo code --- this is what it should check
	*
	*	if (yytext == type_name)
	*		return(TYPE_NAME);
	*
	*	return(IDENTIFIER);
	*/

	/*
	*	it actually will only return IDENTIFIER
	*/

	return(IDENTIFIER);
}

int main(int argc, char ** argv){
	int t;
	
	if(argc > 1) yyin = fopen(argv[1], "r");
	while((t = yylex())) printf("%d:%d:%d @%s@\n", linenr, column, t, yytext);
	
	fclose(yyin);
	
	return 0;
}

