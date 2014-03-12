#include <stdio.h>
#include <stdlib.h>

const char * initString = /*"\\documentclass{article}\\begin{document}\n"*/
	"\\begin{tabbing}xx\\=xx\\=xx\\=xx\\=xx\\=xx\\=xx\\=xx\\=xx\\=xx\\=xx\\=xx\\=xx\\kill\n";
const char * endString = "\\end{tabbing}";
/*\\end{document}\n";*/

FILE * out;
extern FILE * yyin;

int main(int argc, char ** argv){
	yyin = stdin;
	out = stdout;
	
	if(argc == 2){
		yyin = fopen(argv[1], "r");
	}
	if(argc == 3){
		yyin = fopen(argv[1], "r");
		out = fopen(argv[2], "w");
	}
	
	if (out == NULL || yyin == NULL){
		printf("Error opening file!\n");
		exit(1);
	}
	
	fputs(initString, out);
	
	yyparse();

	fputs(endString, out);

	fclose(out);

	return 0;
}

yyerror(char * msg){
   extern long yypos;

   printf("line %ld: %s\n", yypos, msg);
   exit(1);
}

yywrap(){
   return 1;
}
