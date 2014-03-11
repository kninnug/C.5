#include <stdio.h>
#include <stdlib.h>

const char * initString = /*"\\documentclass{article}\\begin{document}\n"*/
	"\\begin{tabbing}xx\\=xx\\=xx\\=xx\\=xx\\=xx\\=xx\\=xx\\=xx\\=xx\\=xx\\=xx\\=xx\\kill";
const char * endString = "\\end{tabbing}";
/*\\end{document}\n";*/

FILE * f;

int main()
{
	f = fopen("pretty.tex", "w");
	if (f == NULL){
		printf("Error opening file!\n");
		exit(1);
	}
	
	fputs(initString, f);
	
	yyparse();

	fputs(endString, f);

	fclose(f);

	return 0;
}

yyerror(msg)
   char *msg;
{
   extern long yypos;

   printf("line %ld: %s\n", yypos, msg);
   exit(1);
}

yywrap()
{
   return 1;
}
