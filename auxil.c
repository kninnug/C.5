#include <stdio.h>
#include <stdlib.h>

const char * initString = "\\documentclass{article}\\author{The accent compiler compiler}\\title{Latex pretty printer}\\begin{document}\\maketitle";
const char * endString = "\\end{document}";

main()
{
   yyparse();

   FILE *f = fopen("pretty.tex", "w");
   if (f == NULL)
     {
       printf("Error opening file!\n");
       exit(1);
     }

   fprintf(f, "%s %s", initString, endString);

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
