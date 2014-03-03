#include "parser.h"
#include "yygrammar.h"

#include <stdio.h>

extern FILE* yyin;

int main(int argc, char ** argv){
	if(argc > 1){
		yyin = fopen(argv[1], "r");
	}
	yyparse();
	return 0;
}
