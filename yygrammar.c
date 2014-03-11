#line 1 "ass2.acc"

	#include <stdio.h>
	#include <stdlib.h>
	
	#include "parser.h"
	
	extern FILE * f;
	
	void fprintStringConst(FILE * f, char * s){
		while(*s){
			if(*s == '\\') fputs("\\textbackslash ", f);
			else if(*s == '%') fputs("\\%", f);
			else fputc(*s, f);
			s++;
		}
	}
	
	void fprintIdentifier(FILE * f, char * s){
		while(*s){
			if(*s == '_') fputc('\\', f), fputc('_', f);
			else fputc(*s, f);
			s++;
		}
	}
	
	void prCh(FILE * f, int c){
		switch(c){
			case '&':
			case '%':
			case '{':
			case '}':
				fputc('\\', f);
				fputc(c, f);
			break;
			case '<':
			case '>':
				fputc('$', f);
				fputc(c, f);
				fputc('$', f);
			break;
			default:
				fputc(c, f);
		}
	}
	
	void fprintCompare(FILE * f, int st){
		switch(st){
			case COMPARE_EQUAL: fputs("\\ $==$\\ ", f); break;
			case COMPARE_UNEQUAL: fputs("\\ $\\neq$\\ ", f); break;
			case COMPARE_LEQ: fputs("\\ $\\leq$\\ ", f); break;
			case COMPARE_GREQ: fputs("\\ $\\geq$\\ ", f); break;
			case COMPARE_GREATER: fputs("\\ $>$\\ ", f); break;
			case COMPARE_LESS: fputs("\\ $<$\\ ", f); break;
		}
	}
	
	#define PRCHS prCh(f, yylval.c), fprintf(f, "\\ ")
	#define PRCH prCh(f, yylval.c)
	#define PRS fprintStringConst(f, yylval.s)
	#define PRKW fprintf(f, "{\\bf %s} ", yylval.s)

# line 64 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 103: {
      translation_unit();
      get_lexval();
      } break;
   }
}

translation_unit ()
{
   switch(yyselect()) {
   case 1: {
      while (1) {
         switch (yyselect()) {
         case 104: {
            external_declaration();
            } break;
         default: goto yy1;
         }
      }
      yy1: ;
      } break;
   }
}

external_declaration ()
{
   switch(yyselect()) {
   case 2: {
      function_definition();
      } break;
   case 3: {
      declaration();
      } break;
   }
}

function_definition ()
{
   switch(yyselect()) {
   case 4: {
      switch (yyselect()) {
      case 105: {
         declaration_specifiers();
         } break;
      default: ;
      }
      declarator();
      switch (yyselect()) {
      case 106: {
         declaration_list();
         } break;
      default: ;
      }
      compound_statement();
#line 81 "ass2.acc"
 fputs("\\\\\n", f); 
# line 126 "yygrammar.c"
      } break;
   }
}

declaration ()
{
   switch(yyselect()) {
   case 5: {
      declaration_specifiers();
      switch (yyselect()) {
      case 107: {
         init_declarator_list();
         } break;
      default: ;
      }
      get_lexval();
#line 85 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 145 "yygrammar.c"
      } break;
   }
}

declaration_list ()
{
   switch(yyselect()) {
   case 6: {
      switch (yyselect()) {
      case 108: {
         declaration_list();
         } break;
      default: ;
      }
      declaration();
      } break;
   }
}

declaration_specifiers ()
{
   switch(yyselect()) {
   case 7: {
      switch (yyselect()) {
      case 109: {
         storage_class_specifier();
         } break;
      case 110: {
         type_specifier();
         } break;
      case 111: {
         type_qualifier();
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 112: {
         declaration_specifiers();
         } break;
      default: ;
      }
      } break;
   }
}

storage_class_specifier ()
{
   switch(yyselect()) {
   case 8: {
      switch (yyselect()) {
      case 113: {
         get_lexval();
         } break;
      case 114: {
         get_lexval();
         } break;
      case 115: {
         get_lexval();
         } break;
      case 116: {
         get_lexval();
         } break;
      case 117: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 101 "ass2.acc"
 PRKW; 
# line 215 "yygrammar.c"
      } break;
   }
}

type_specifier ()
{
   switch(yyselect()) {
   case 9: {
      switch (yyselect()) {
      case 118: {
         get_lexval();
         } break;
      case 119: {
         get_lexval();
         } break;
      case 120: {
         get_lexval();
         } break;
      case 121: {
         get_lexval();
         } break;
      case 122: {
         get_lexval();
         } break;
      case 123: {
         get_lexval();
         } break;
      case 124: {
         get_lexval();
         } break;
      case 125: {
         get_lexval();
         } break;
      case 126: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 113 "ass2.acc"
 PRKW; 
# line 256 "yygrammar.c"
      } break;
   case 10: {
      struct_or_union_specifier();
      } break;
   case 11: {
      enum_specifier();
      } break;
   }
}

type_qualifier ()
{
   switch(yyselect()) {
   case 12: {
      switch (yyselect()) {
      case 127: {
         get_lexval();
         } break;
      case 128: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 119 "ass2.acc"
 PRKW; 
# line 282 "yygrammar.c"
      } break;
   }
}

struct_or_union_specifier ()
{
   switch(yyselect()) {
   case 13: {
      struct_or_union();
      switch (yyselect()) {
      case 129: {
         id();
         } break;
      default: ;
      }
      get_lexval();
#line 123 "ass2.acc"
 fputs("\\{\\\\\n", f); 
# line 301 "yygrammar.c"
      struct_declaration_list();
      get_lexval();
#line 123 "ass2.acc"
 fputs("\\}\\\\\n", f); 
# line 306 "yygrammar.c"
      } break;
   case 14: {
      struct_or_union();
      id();
      } break;
   }
}

struct_or_union ()
{
   switch(yyselect()) {
   case 15: {
      switch (yyselect()) {
      case 130: {
         get_lexval();
         } break;
      case 131: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 128 "ass2.acc"
 PRKW; 
# line 330 "yygrammar.c"
      } break;
   }
}

struct_declaration_list ()
{
   switch(yyselect()) {
   case 16: {
      switch (yyselect()) {
      case 132: {
         struct_declaration_list();
         } break;
      default: ;
      }
      struct_declaration();
      } break;
   }
}

init_declarator_list ()
{
   switch(yyselect()) {
   case 17: {
      switch (yyselect()) {
      case 133: {
         init_declarator_list();
         get_lexval();
#line 136 "ass2.acc"
 PRCHS; 
# line 360 "yygrammar.c"
         } break;
      default: ;
      }
      init_declarator();
      } break;
   }
}

init_declarator ()
{
   switch(yyselect()) {
   case 18: {
      switch (yyselect()) {
      case 134: {
         declarator();
         get_lexval();
#line 140 "ass2.acc"
 PRCH; 
# line 379 "yygrammar.c"
         } break;
      default: ;
      }
      initializer();
      } break;
   }
}

struct_declaration ()
{
   switch(yyselect()) {
   case 19: {
      specifier_qualifier_list();
      struct_declarator_list();
      get_lexval();
#line 144 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 397 "yygrammar.c"
      } break;
   }
}

specifier_qualifier_list ()
{
   switch(yyselect()) {
   case 20: {
      switch (yyselect()) {
      case 135: {
         type_specifier();
         } break;
      case 136: {
         type_qualifier();
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 137: {
         specifier_qualifier_list();
         } break;
      default: ;
      }
      } break;
   }
}

struct_declarator_list ()
{
   switch(yyselect()) {
   case 21: {
      switch (yyselect()) {
      case 138: {
         struct_declarator_list();
         get_lexval();
#line 152 "ass2.acc"
 PRCHS; 
# line 435 "yygrammar.c"
         } break;
      default: ;
      }
      struct_declarator();
      } break;
   }
}

struct_declarator ()
{
   switch(yyselect()) {
   case 22: {
      declarator();
      } break;
   case 23: {
      switch (yyselect()) {
      case 139: {
         declarator();
         } break;
      default: ;
      }
      get_lexval();
#line 157 "ass2.acc"
 PRCH; 
# line 460 "yygrammar.c"
      constant_expression();
      } break;
   }
}

enum_specifier ()
{
   switch(yyselect()) {
   case 24: {
      get_lexval();
      switch (yyselect()) {
      case 140: {
         id();
         } break;
      default: ;
      }
#line 161 "ass2.acc"
 fputs("\\{\\\\\n", f); 
# line 479 "yygrammar.c"
      get_lexval();
      enumerator_list();
      get_lexval();
#line 161 "ass2.acc"
 fputs("\\}\\\\\n", f); 
# line 485 "yygrammar.c"
      } break;
   case 25: {
      get_lexval();
      id();
      } break;
   }
}

enumerator_list ()
{
   switch(yyselect()) {
   case 26: {
      switch (yyselect()) {
      case 141: {
         enumerator_list();
         get_lexval();
#line 166 "ass2.acc"
 PRCHS; 
# line 504 "yygrammar.c"
         } break;
      default: ;
      }
      enumerator();
      } break;
   }
}

enumerator ()
{
   switch(yyselect()) {
   case 27: {
      id();
      switch (yyselect()) {
      case 142: {
         get_lexval();
#line 170 "ass2.acc"
 PRCH; 
# line 523 "yygrammar.c"
         constant_expression();
         } break;
      default: ;
      }
      } break;
   }
}

declarator ()
{
   switch(yyselect()) {
   case 28: {
      switch (yyselect()) {
      case 143: {
         pointer();
         } break;
      default: ;
      }
      direct_declarator();
      } break;
   }
}

direct_declarator ()
{
   switch(yyselect()) {
   case 29: {
      id();
#line 178 "ass2.acc"
printf("Identifier within declarator: %s\n", yylval.s);
# line 554 "yygrammar.c"
      } break;
   case 30: {
      get_lexval();
#line 179 "ass2.acc"
 PRCH; 
# line 560 "yygrammar.c"
      declarator();
      get_lexval();
#line 179 "ass2.acc"
 PRCH; 
# line 565 "yygrammar.c"
      } break;
   case 31: {
      direct_declarator();
      switch (yyselect()) {
      case 145: {
         get_lexval();
#line 180 "ass2.acc"
 PRCH; 
# line 574 "yygrammar.c"
         switch (yyselect()) {
         case 144: {
            constant_expression();
            } break;
         default: ;
         }
         get_lexval();
#line 180 "ass2.acc"
 PRCH; 
# line 584 "yygrammar.c"
         } break;
      case 146: {
         get_lexval();
#line 180 "ass2.acc"
 PRCH; 
# line 590 "yygrammar.c"
         parameter_type_list();
         get_lexval();
#line 180 "ass2.acc"
 PRCH; 
# line 595 "yygrammar.c"
         } break;
      case 148: {
         get_lexval();
#line 180 "ass2.acc"
 PRCH; 
# line 601 "yygrammar.c"
         switch (yyselect()) {
         case 147: {
            identifier_list();
            } break;
         default: ;
         }
         get_lexval();
#line 180 "ass2.acc"
 PRCH; 
# line 611 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

pointer ()
{
   switch(yyselect()) {
   case 32: {
      get_lexval();
#line 184 "ass2.acc"
 PRCH; 
# line 626 "yygrammar.c"
      switch (yyselect()) {
      case 149: {
         type_qualifier_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 150: {
         pointer();
         } break;
      default: ;
      }
      } break;
   }
}

type_qualifier_list ()
{
   switch(yyselect()) {
   case 33: {
      switch (yyselect()) {
      case 151: {
         type_qualifier_list();
         } break;
      default: ;
      }
      type_qualifier();
      } break;
   }
}

parameter_type_list ()
{
   switch(yyselect()) {
   case 34: {
      parameter_list();
      switch (yyselect()) {
      case 152: {
         get_lexval();
#line 192 "ass2.acc"
 PRCHS; 
# line 668 "yygrammar.c"
         get_lexval();
         } break;
      default: ;
      }
      } break;
   }
}

parameter_list ()
{
   switch(yyselect()) {
   case 35: {
      switch (yyselect()) {
      case 153: {
         parameter_list();
         get_lexval();
#line 196 "ass2.acc"
 PRCHS; 
# line 687 "yygrammar.c"
         } break;
      default: ;
      }
      parameter_declaration();
      } break;
   }
}

parameter_declaration ()
{
   switch(yyselect()) {
   case 36: {
      declaration_specifiers();
      switch (yyselect()) {
      case 154: {
         declarator();
         } break;
      case 156: {
         switch (yyselect()) {
         case 155: {
            abstract_declarator();
            } break;
         default: ;
         }
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

identifier_list ()
{
   switch(yyselect()) {
   case 37: {
      switch (yyselect()) {
      case 157: {
         identifier_list();
         get_lexval();
#line 204 "ass2.acc"
 PRCHS; 
# line 729 "yygrammar.c"
         } break;
      default: ;
      }
      id();
      } break;
   }
}

initializer ()
{
   switch(yyselect()) {
   case 38: {
      assignment_expression();
      } break;
   case 39: {
      get_lexval();
#line 209 "ass2.acc"
 fputs("\\{", f); 
# line 748 "yygrammar.c"
      initializer_list();
      switch (yyselect()) {
      case 158: {
         get_lexval();
         } break;
      default: ;
      }
      get_lexval();
#line 209 "ass2.acc"
 fputs("\\}", f); 
# line 759 "yygrammar.c"
      } break;
   }
}

initializer_list ()
{
   switch(yyselect()) {
   case 40: {
      switch (yyselect()) {
      case 159: {
         initializer_list();
         get_lexval();
#line 213 "ass2.acc"
 PRCHS; 
# line 774 "yygrammar.c"
         } break;
      default: ;
      }
      initializer();
      } break;
   }
}

type_name ()
{
   switch(yyselect()) {
   case 41: {
      specifier_qualifier_list();
      switch (yyselect()) {
      case 160: {
         abstract_declarator();
         } break;
      default: ;
      }
      } break;
   }
}

abstract_declarator ()
{
   switch(yyselect()) {
   case 42: {
      pointer();
      } break;
   case 43: {
      switch (yyselect()) {
      case 161: {
         pointer();
         } break;
      default: ;
      }
      direct_abstract_declarator();
      } break;
   }
}

direct_abstract_declarator ()
{
   switch(yyselect()) {
   case 44: {
      get_lexval();
#line 226 "ass2.acc"
 PRCH; 
# line 823 "yygrammar.c"
      abstract_declarator();
      get_lexval();
#line 226 "ass2.acc"
 PRCH; 
# line 828 "yygrammar.c"
      } break;
   case 45: {
      switch (yyselect()) {
      case 162: {
         direct_abstract_declarator();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 164: {
         get_lexval();
#line 227 "ass2.acc"
 PRCH; 
# line 842 "yygrammar.c"
         switch (yyselect()) {
         case 163: {
            constant_expression();
            } break;
         default: ;
         }
         get_lexval();
#line 227 "ass2.acc"
 PRCH; 
# line 852 "yygrammar.c"
         } break;
      case 166: {
         get_lexval();
#line 227 "ass2.acc"
 PRCH; 
# line 858 "yygrammar.c"
         switch (yyselect()) {
         case 165: {
            parameter_type_list();
            } break;
         default: ;
         }
         get_lexval();
#line 227 "ass2.acc"
 PRCH; 
# line 868 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

typedef_name ()
{
   switch(yyselect()) {
   case 46: {
      id();
      } break;
   }
}

statement ()
{
   switch(yyselect()) {
   case 47: {
      labeled_statement();
      } break;
   case 48: {
      expression_statement();
      } break;
   case 49: {
      compound_statement();
      } break;
   case 50: {
      selection_statement();
      } break;
   case 51: {
      iteration_statement();
      } break;
   case 52: {
      jump_statement();
      } break;
   }
}

labeled_statement ()
{
   switch(yyselect()) {
   case 53: {
      id();
      get_lexval();
#line 244 "ass2.acc"
 PRCH; 
# line 917 "yygrammar.c"
      statement();
      } break;
   case 54: {
      get_lexval();
#line 245 "ass2.acc"
 PRKW; 
# line 924 "yygrammar.c"
      constant_expression();
      get_lexval();
#line 245 "ass2.acc"
 PRCH; 
# line 929 "yygrammar.c"
      statement();
      } break;
   case 55: {
      get_lexval();
#line 246 "ass2.acc"
 PRKW; 
# line 936 "yygrammar.c"
      get_lexval();
#line 246 "ass2.acc"
 PRCH; 
# line 940 "yygrammar.c"
      statement();
      } break;
   }
}

expression_statement ()
{
   switch(yyselect()) {
   case 56: {
      switch (yyselect()) {
      case 167: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 250 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 959 "yygrammar.c"
      } break;
   }
}

compound_statement ()
{
   switch(yyselect()) {
   case 57: {
      get_lexval();
#line 254 "ass2.acc"
 fputs("\\{\\+\\\\\n", f); 
# line 971 "yygrammar.c"
      switch (yyselect()) {
      case 168: {
         declaration_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 169: {
         statement_list();
         } break;
      default: ;
      }
      get_lexval();
#line 254 "ass2.acc"
 fputs("\\<\\}\\-\\\\\n", f); 
# line 987 "yygrammar.c"
      } break;
   }
}

statement_list ()
{
   switch(yyselect()) {
   case 58: {
      switch (yyselect()) {
      case 170: {
         statement_list();
         } break;
      default: ;
      }
      statement();
      } break;
   }
}

selection_statement ()
{
   switch(yyselect()) {
   case 59: {
      get_lexval();
#line 262 "ass2.acc"
 PRKW; 
# line 1014 "yygrammar.c"
      get_lexval();
#line 262 "ass2.acc"
 PRCH; 
# line 1018 "yygrammar.c"
      expression();
      get_lexval();
#line 262 "ass2.acc"
 PRCH; 
# line 1023 "yygrammar.c"
      statement();
      switch (yyselect()) {
      case 171: {
         get_lexval();
#line 262 "ass2.acc"
 PRKW; 
# line 1030 "yygrammar.c"
         statement();
         } break;
      default: ;
      }
      } break;
   case 60: {
      get_lexval();
#line 263 "ass2.acc"
 PRKW; 
# line 1040 "yygrammar.c"
      get_lexval();
#line 263 "ass2.acc"
 PRCH; 
# line 1044 "yygrammar.c"
      expression();
      get_lexval();
#line 263 "ass2.acc"
 PRCH; 
# line 1049 "yygrammar.c"
      statement();
      } break;
   }
}

iteration_statement ()
{
   switch(yyselect()) {
   case 61: {
      get_lexval();
#line 267 "ass2.acc"
 PRKW; 
# line 1062 "yygrammar.c"
      get_lexval();
#line 267 "ass2.acc"
 PRCH; 
# line 1066 "yygrammar.c"
      expression();
      get_lexval();
#line 267 "ass2.acc"
 PRCH; 
# line 1071 "yygrammar.c"
      statement();
      } break;
   case 62: {
      get_lexval();
#line 268 "ass2.acc"
 PRKW; 
# line 1078 "yygrammar.c"
      statement();
      get_lexval();
#line 268 "ass2.acc"
 PRKW; 
# line 1083 "yygrammar.c"
      get_lexval();
#line 268 "ass2.acc"
 PRCH; 
# line 1087 "yygrammar.c"
      expression();
      get_lexval();
#line 268 "ass2.acc"
 PRCH; 
# line 1092 "yygrammar.c"
      get_lexval();
#line 268 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 1096 "yygrammar.c"
      } break;
   case 63: {
      get_lexval();
#line 269 "ass2.acc"
 PRKW; 
# line 1102 "yygrammar.c"
      get_lexval();
#line 269 "ass2.acc"
 PRCH; 
# line 1106 "yygrammar.c"
      switch (yyselect()) {
      case 172: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 269 "ass2.acc"
 PRCH; 
# line 1116 "yygrammar.c"
      switch (yyselect()) {
      case 173: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 269 "ass2.acc"
 PRCH; 
# line 1126 "yygrammar.c"
      switch (yyselect()) {
      case 174: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 269 "ass2.acc"
 PRCH; 
# line 1136 "yygrammar.c"
      statement();
      } break;
   }
}

jump_statement ()
{
   switch(yyselect()) {
   case 64: {
      get_lexval();
#line 273 "ass2.acc"
 PRKW; 
# line 1149 "yygrammar.c"
      id();
      get_lexval();
#line 273 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 1154 "yygrammar.c"
      } break;
   case 65: {
      get_lexval();
#line 274 "ass2.acc"
 PRKW; 
# line 1160 "yygrammar.c"
      get_lexval();
#line 274 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 1164 "yygrammar.c"
      } break;
   case 66: {
      get_lexval();
#line 275 "ass2.acc"
 PRKW; 
# line 1170 "yygrammar.c"
      get_lexval();
#line 275 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 1174 "yygrammar.c"
      } break;
   case 67: {
      get_lexval();
#line 276 "ass2.acc"
 PRKW; 
# line 1180 "yygrammar.c"
      switch (yyselect()) {
      case 175: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 276 "ass2.acc"
 printf("Return\n"); fputs(";\\\\\n", f); 
# line 1190 "yygrammar.c"
      } break;
   }
}

expression ()
{
   switch(yyselect()) {
   case 68: {
      switch (yyselect()) {
      case 176: {
         expression();
         get_lexval();
#line 280 "ass2.acc"
 PRCHS; 
# line 1205 "yygrammar.c"
         } break;
      default: ;
      }
      assignment_expression();
      } break;
   }
}

assignment_expression ()
{
   switch(yyselect()) {
   case 69: {
      conditional_expression();
      } break;
   case 70: {
      unary_expression();
      assignment_operator();
      assignment_expression();
      } break;
   }
}

assignment_operator ()
{
   switch(yyselect()) {
   case 71: {
      switch (yyselect()) {
      case 177: {
         get_lexval();
         } break;
      case 178: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 290 "ass2.acc"
 fputc(' ', f); PRCHS; 
# line 1243 "yygrammar.c"
      } break;
   }
}

conditional_expression ()
{
   switch(yyselect()) {
   case 72: {
      logical_OR_expression();
      switch (yyselect()) {
      case 179: {
         get_lexval();
#line 294 "ass2.acc"
 PRCH; 
# line 1258 "yygrammar.c"
         expression();
         get_lexval();
#line 294 "ass2.acc"
 PRCH; 
# line 1263 "yygrammar.c"
         conditional_expression();
         } break;
      default: ;
      }
      } break;
   }
}

constant_expression ()
{
   switch(yyselect()) {
   case 73: {
      conditional_expression();
      } break;
   }
}

logical_OR_expression ()
{
   switch(yyselect()) {
   case 74: {
      switch (yyselect()) {
      case 180: {
         logical_OR_expression();
         get_lexval();
         } break;
      default: ;
      }
      logical_AND_expression();
      } break;
   }
}

logical_AND_expression ()
{
   switch(yyselect()) {
   case 75: {
      switch (yyselect()) {
      case 181: {
         logical_AND_expression();
         get_lexval();
         } break;
      default: ;
      }
      inclusive_OR_expression();
      } break;
   }
}

inclusive_OR_expression ()
{
   switch(yyselect()) {
   case 76: {
      switch (yyselect()) {
      case 182: {
         inclusive_OR_expression();
         get_lexval();
         } break;
      default: ;
      }
      exclusive_OR_expression();
      } break;
   }
}

exclusive_OR_expression ()
{
   switch(yyselect()) {
   case 77: {
      switch (yyselect()) {
      case 183: {
         exclusive_OR_expression();
         get_lexval();
         } break;
      default: ;
      }
      AND_expression();
      } break;
   }
}

AND_expression ()
{
   switch(yyselect()) {
   case 78: {
      switch (yyselect()) {
      case 184: {
         AND_expression();
         get_lexval();
         } break;
      default: ;
      }
      equality_expression();
      } break;
   }
}

equality_expression ()
{
   switch(yyselect()) {
   case 79: {
      switch (yyselect()) {
      case 185: {
         equality_expression();
         get_lexval();
#line 322 "ass2.acc"
 fprintCompare(f, yylval.subtype); 
# line 1371 "yygrammar.c"
         } break;
      default: ;
      }
      shift_expression();
      } break;
   }
}

shift_expression ()
{
   switch(yyselect()) {
   case 80: {
      switch (yyselect()) {
      case 186: {
         shift_expression();
         get_lexval();
         } break;
      default: ;
      }
      additive_expression();
      } break;
   }
}

additive_expression ()
{
   switch(yyselect()) {
   case 81: {
      switch (yyselect()) {
      case 189: {
         additive_expression();
         switch (yyselect()) {
         case 187: {
            get_lexval();
            } break;
         case 188: {
            get_lexval();
            } break;
         default: printf("???\n"); exit(1);
         }
#line 330 "ass2.acc"
 PRCH; 
# line 1414 "yygrammar.c"
         } break;
      default: ;
      }
      multiplicative_expression();
      } break;
   }
}

multiplicative_expression ()
{
   switch(yyselect()) {
   case 82: {
      switch (yyselect()) {
      case 193: {
         multiplicative_expression();
         switch (yyselect()) {
         case 190: {
            get_lexval();
            } break;
         case 191: {
            get_lexval();
            } break;
         case 192: {
            get_lexval();
            } break;
         default: printf("???\n"); exit(1);
         }
#line 334 "ass2.acc"
 PRCH; 
# line 1444 "yygrammar.c"
         } break;
      default: ;
      }
      cast_expression();
      } break;
   }
}

cast_expression ()
{
   switch(yyselect()) {
   case 83: {
      unary_expression();
      } break;
   case 84: {
      get_lexval();
#line 339 "ass2.acc"
 PRCH; 
# line 1463 "yygrammar.c"
      type_name();
      get_lexval();
#line 339 "ass2.acc"
 PRCH; 
# line 1468 "yygrammar.c"
      cast_expression();
      } break;
   }
}

unary_expression ()
{
   switch(yyselect()) {
   case 85: {
      postfix_expression();
      } break;
   case 86: {
      switch (yyselect()) {
      case 194: {
         get_lexval();
         } break;
      case 195: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
      unary_expression();
      } break;
   case 87: {
      unary_operator();
      cast_expression();
      } break;
   case 88: {
      get_lexval();
      unary_expression();
      } break;
   case 89: {
      get_lexval();
      get_lexval();
#line 347 "ass2.acc"
 PRCH; 
# line 1505 "yygrammar.c"
      type_name();
      get_lexval();
#line 347 "ass2.acc"
 PRCH; 
# line 1510 "yygrammar.c"
      } break;
   }
}

unary_operator ()
{
   switch(yyselect()) {
   case 90: {
      switch (yyselect()) {
      case 196: {
         get_lexval();
         } break;
      case 197: {
         get_lexval();
         } break;
      case 198: {
         get_lexval();
         } break;
      case 199: {
         get_lexval();
         } break;
      case 200: {
         get_lexval();
         } break;
      case 201: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 351 "ass2.acc"
 PRCH; 
# line 1542 "yygrammar.c"
      } break;
   }
}

postfix_expression ()
{
   switch(yyselect()) {
   case 91: {
      primary_expression();
      } break;
   case 92: {
      postfix_expression();
      switch (yyselect()) {
      case 202: {
         get_lexval();
#line 356 "ass2.acc"
 PRCH; 
# line 1560 "yygrammar.c"
         expression();
         get_lexval();
#line 356 "ass2.acc"
 PRCH; 
# line 1565 "yygrammar.c"
         } break;
      case 204: {
         get_lexval();
#line 356 "ass2.acc"
 PRCH; 
# line 1571 "yygrammar.c"
         switch (yyselect()) {
         case 203: {
            argument_expression_list();
            } break;
         default: ;
         }
         get_lexval();
#line 356 "ass2.acc"
 PRCH; 
# line 1581 "yygrammar.c"
         } break;
      case 205: {
         get_lexval();
#line 356 "ass2.acc"
 PRCH; 
# line 1587 "yygrammar.c"
         id();
         } break;
      case 206: {
         get_lexval();
#line 356 "ass2.acc"
 fputs("->", f); 
# line 1594 "yygrammar.c"
         id();
         } break;
      case 207: {
         get_lexval();
#line 356 "ass2.acc"
 fputs("++", f); 
# line 1601 "yygrammar.c"
         } break;
      case 208: {
         get_lexval();
#line 356 "ass2.acc"
 fputs("--", f); 
# line 1607 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

primary_expression ()
{
   switch(yyselect()) {
   case 93: {
      id();
      } break;
   case 94: {
      constant();
      } break;
   case 95: {
      get_lexval();
#line 362 "ass2.acc"
 fprintStringConst(f, yylval.s); 
# line 1628 "yygrammar.c"
      } break;
   case 96: {
      get_lexval();
#line 363 "ass2.acc"
 PRCH; 
# line 1634 "yygrammar.c"
      expression();
      get_lexval();
#line 363 "ass2.acc"
 PRCH; 
# line 1639 "yygrammar.c"
      } break;
   }
}

argument_expression_list ()
{
   switch(yyselect()) {
   case 97: {
      switch (yyselect()) {
      case 209: {
         argument_expression_list();
         get_lexval();
#line 367 "ass2.acc"
 PRCHS; 
# line 1654 "yygrammar.c"
         } break;
      default: ;
      }
      assignment_expression();
      } break;
   }
}

constant ()
{
   switch(yyselect()) {
   case 98: {
      get_lexval();
#line 371 "ass2.acc"
 fprintf(f, "$%u$", yylval.i); 
# line 1670 "yygrammar.c"
      } break;
   case 99: {
      get_lexval();
#line 372 "ass2.acc"
 fprintStringConst(f, yylval.s); 
# line 1676 "yygrammar.c"
      } break;
   case 100: {
      get_lexval();
#line 373 "ass2.acc"
 fprintf(f, "$%f$", yylval.d); 
# line 1682 "yygrammar.c"
      } break;
   case 101: {
      id();
      } break;
   }
}

id ()
{
   switch(yyselect()) {
   case 102: {
      get_lexval();
#line 378 "ass2.acc"
 fprintIdentifier(f, yylval.s); 
# line 1697 "yygrammar.c"
      } break;
   }
}

extern YYSTYPE yylval;
YYSTYPE yylval;
extern long yypos;
long yypos = 1;
/* GentleFlag = no */

typedef struct LEXELEMSTRUCT {
   YYSTYPE val;
   long pos;
   long sym;
   char * text;
   struct LEXELEMSTRUCT *next;
} LEXELEM;
   
LEXELEM *first_lexelem, *cur_lexelem;

init_lexelem()
{
   cur_lexelem = first_lexelem;
}

first_lexval () {
   LEXELEM *p;
   p = (LEXELEM *)malloc(sizeof(LEXELEM));
   if (! p) yymallocerror();
   p->val = yylval;
   p->pos = yypos;
   p->next = 0;
   cur_lexelem = p;
   first_lexelem = p;
}

next_lexval() {
   LEXELEM *p;
   p = (LEXELEM *)malloc(sizeof(LEXELEM));
   if (! p) yymallocerror();
   cur_lexelem-> next = p;
   p->val = yylval;
   p->pos = yypos;
   p->next = 0;
   cur_lexelem = p;
}

get_lexval() {
   extern int FREE_LEXELEMS;
   LEXELEM *p;
   yylval = cur_lexelem->val;
   yypos = cur_lexelem->pos;
   p = cur_lexelem;
   cur_lexelem = cur_lexelem->next;
   free(p);
}

extern int c_length;
int c_length = 1162;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 103,
/* 6 */ 0,
/* 7 */ 10,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 15,
/* 11 */ 18,
/* 12 */ 10,
/* 13 */ -10,
/* 14 */ 104,
/* 15 */ 0,
/* 16 */ -10,
/* 17 */ 210,
/* 18 */ 22,
/* 19 */ 26,
/* 20 */ -18,
/* 21 */ 2,
/* 22 */ 0,
/* 23 */ 47,
/* 24 */ -18,
/* 25 */ 3,
/* 26 */ 0,
/* 27 */ 33,
/* 28 */ 352,
/* 29 */ 40,
/* 30 */ 664,
/* 31 */ -26,
/* 32 */ 4,
/* 33 */ 37,
/* 34 */ 72,
/* 35 */ -33,
/* 36 */ 105,
/* 37 */ 0,
/* 38 */ -33,
/* 39 */ 211,
/* 40 */ 44,
/* 41 */ 60,
/* 42 */ -40,
/* 43 */ 106,
/* 44 */ 0,
/* 45 */ -40,
/* 46 */ 212,
/* 47 */ 0,
/* 48 */ 72,
/* 49 */ 53,
/* 50 */ 50059,
/* 51 */ -47,
/* 52 */ 5,
/* 53 */ 57,
/* 54 */ 224,
/* 55 */ -53,
/* 56 */ 107,
/* 57 */ 0,
/* 58 */ -53,
/* 59 */ 213,
/* 60 */ 0,
/* 61 */ 65,
/* 62 */ 47,
/* 63 */ -60,
/* 64 */ 6,
/* 65 */ 69,
/* 66 */ 60,
/* 67 */ -65,
/* 68 */ 108,
/* 69 */ 0,
/* 70 */ -65,
/* 71 */ 214,
/* 72 */ 0,
/* 73 */ 77,
/* 74 */ 89,
/* 75 */ -72,
/* 76 */ 7,
/* 77 */ 81,
/* 78 */ 96,
/* 79 */ -77,
/* 80 */ 109,
/* 81 */ 85,
/* 82 */ 120,
/* 83 */ -77,
/* 84 */ 110,
/* 85 */ 0,
/* 86 */ 168,
/* 87 */ -77,
/* 88 */ 111,
/* 89 */ 93,
/* 90 */ 72,
/* 91 */ -89,
/* 92 */ 112,
/* 93 */ 0,
/* 94 */ -89,
/* 95 */ 215,
/* 96 */ 0,
/* 97 */ 100,
/* 98 */ -96,
/* 99 */ 8,
/* 100 */ 104,
/* 101 */ 50256,
/* 102 */ -100,
/* 103 */ 113,
/* 104 */ 108,
/* 105 */ 50274,
/* 106 */ -100,
/* 107 */ 114,
/* 108 */ 112,
/* 109 */ 50279,
/* 110 */ -100,
/* 111 */ 115,
/* 112 */ 116,
/* 113 */ 50267,
/* 114 */ -100,
/* 115 */ 116,
/* 116 */ 0,
/* 117 */ 50282,
/* 118 */ -100,
/* 119 */ 117,
/* 120 */ 124,
/* 121 */ 132,
/* 122 */ -120,
/* 123 */ 9,
/* 124 */ 128,
/* 125 */ 180,
/* 126 */ -120,
/* 127 */ 10,
/* 128 */ 0,
/* 129 */ 306,
/* 130 */ -120,
/* 131 */ 11,
/* 132 */ 136,
/* 133 */ 50285,
/* 134 */ -132,
/* 135 */ 118,
/* 136 */ 140,
/* 137 */ 50259,
/* 138 */ -132,
/* 139 */ 119,
/* 140 */ 144,
/* 141 */ 50276,
/* 142 */ -132,
/* 143 */ 120,
/* 144 */ 148,
/* 145 */ 50272,
/* 146 */ -132,
/* 147 */ 121,
/* 148 */ 152,
/* 149 */ 50273,
/* 150 */ -132,
/* 151 */ 122,
/* 152 */ 156,
/* 153 */ 50268,
/* 154 */ -132,
/* 155 */ 123,
/* 156 */ 160,
/* 157 */ 50264,
/* 158 */ -132,
/* 159 */ 124,
/* 160 */ 164,
/* 161 */ 50277,
/* 162 */ -132,
/* 163 */ 125,
/* 164 */ 0,
/* 165 */ 50284,
/* 166 */ -132,
/* 167 */ 126,
/* 168 */ 0,
/* 169 */ 172,
/* 170 */ -168,
/* 171 */ 12,
/* 172 */ 176,
/* 173 */ 50260,
/* 174 */ -172,
/* 175 */ 127,
/* 176 */ 0,
/* 177 */ 50286,
/* 178 */ -172,
/* 179 */ 128,
/* 180 */ 188,
/* 181 */ 200,
/* 182 */ 193,
/* 183 */ 50123,
/* 184 */ 212,
/* 185 */ 50125,
/* 186 */ -180,
/* 187 */ 13,
/* 188 */ 0,
/* 189 */ 200,
/* 190 */ 1159,
/* 191 */ -180,
/* 192 */ 14,
/* 193 */ 197,
/* 194 */ 1159,
/* 195 */ -193,
/* 196 */ 129,
/* 197 */ 0,
/* 198 */ -193,
/* 199 */ 216,
/* 200 */ 0,
/* 201 */ 204,
/* 202 */ -200,
/* 203 */ 15,
/* 204 */ 208,
/* 205 */ 50280,
/* 206 */ -204,
/* 207 */ 130,
/* 208 */ 0,
/* 209 */ 50283,
/* 210 */ -204,
/* 211 */ 131,
/* 212 */ 0,
/* 213 */ 217,
/* 214 */ 250,
/* 215 */ -212,
/* 216 */ 16,
/* 217 */ 221,
/* 218 */ 212,
/* 219 */ -217,
/* 220 */ 132,
/* 221 */ 0,
/* 222 */ -217,
/* 223 */ 217,
/* 224 */ 0,
/* 225 */ 229,
/* 226 */ 237,
/* 227 */ -224,
/* 228 */ 17,
/* 229 */ 234,
/* 230 */ 224,
/* 231 */ 50044,
/* 232 */ -229,
/* 233 */ 133,
/* 234 */ 0,
/* 235 */ -229,
/* 236 */ 218,
/* 237 */ 0,
/* 238 */ 242,
/* 239 */ 502,
/* 240 */ -237,
/* 241 */ 18,
/* 242 */ 247,
/* 243 */ 352,
/* 244 */ 50061,
/* 245 */ -242,
/* 246 */ 134,
/* 247 */ 0,
/* 248 */ -242,
/* 249 */ 219,
/* 250 */ 0,
/* 251 */ 256,
/* 252 */ 276,
/* 253 */ 50059,
/* 254 */ -250,
/* 255 */ 19,
/* 256 */ 0,
/* 257 */ 261,
/* 258 */ 269,
/* 259 */ -256,
/* 260 */ 20,
/* 261 */ 265,
/* 262 */ 120,
/* 263 */ -261,
/* 264 */ 135,
/* 265 */ 0,
/* 266 */ 168,
/* 267 */ -261,
/* 268 */ 136,
/* 269 */ 273,
/* 270 */ 256,
/* 271 */ -269,
/* 272 */ 137,
/* 273 */ 0,
/* 274 */ -269,
/* 275 */ 220,
/* 276 */ 0,
/* 277 */ 281,
/* 278 */ 289,
/* 279 */ -276,
/* 280 */ 21,
/* 281 */ 286,
/* 282 */ 276,
/* 283 */ 50044,
/* 284 */ -281,
/* 285 */ 138,
/* 286 */ 0,
/* 287 */ -281,
/* 288 */ 221,
/* 289 */ 293,
/* 290 */ 352,
/* 291 */ -289,
/* 292 */ 22,
/* 293 */ 0,
/* 294 */ 299,
/* 295 */ 50058,
/* 296 */ 852,
/* 297 */ -289,
/* 298 */ 23,
/* 299 */ 303,
/* 300 */ 352,
/* 301 */ -299,
/* 302 */ 139,
/* 303 */ 0,
/* 304 */ -299,
/* 305 */ 222,
/* 306 */ 314,
/* 307 */ 50266,
/* 308 */ 319,
/* 309 */ 50123,
/* 310 */ 326,
/* 311 */ 50125,
/* 312 */ -306,
/* 313 */ 24,
/* 314 */ 0,
/* 315 */ 50266,
/* 316 */ 1159,
/* 317 */ -306,
/* 318 */ 25,
/* 319 */ 323,
/* 320 */ 1159,
/* 321 */ -319,
/* 322 */ 140,
/* 323 */ 0,
/* 324 */ -319,
/* 325 */ 223,
/* 326 */ 0,
/* 327 */ 331,
/* 328 */ 339,
/* 329 */ -326,
/* 330 */ 26,
/* 331 */ 336,
/* 332 */ 326,
/* 333 */ 50044,
/* 334 */ -331,
/* 335 */ 141,
/* 336 */ 0,
/* 337 */ -331,
/* 338 */ 224,
/* 339 */ 0,
/* 340 */ 1159,
/* 341 */ 344,
/* 342 */ -339,
/* 343 */ 27,
/* 344 */ 349,
/* 345 */ 50061,
/* 346 */ 852,
/* 347 */ -344,
/* 348 */ 142,
/* 349 */ 0,
/* 350 */ -344,
/* 351 */ 225,
/* 352 */ 0,
/* 353 */ 357,
/* 354 */ 364,
/* 355 */ -352,
/* 356 */ 28,
/* 357 */ 361,
/* 358 */ 411,
/* 359 */ -357,
/* 360 */ 143,
/* 361 */ 0,
/* 362 */ -357,
/* 363 */ 226,
/* 364 */ 368,
/* 365 */ 1159,
/* 366 */ -364,
/* 367 */ 29,
/* 368 */ 374,
/* 369 */ 50040,
/* 370 */ 352,
/* 371 */ 50041,
/* 372 */ -364,
/* 373 */ 30,
/* 374 */ 0,
/* 375 */ 364,
/* 376 */ 379,
/* 377 */ -364,
/* 378 */ 31,
/* 379 */ 385,
/* 380 */ 50091,
/* 381 */ 397,
/* 382 */ 50093,
/* 383 */ -379,
/* 384 */ 145,
/* 385 */ 391,
/* 386 */ 50040,
/* 387 */ 443,
/* 388 */ 50041,
/* 389 */ -379,
/* 390 */ 146,
/* 391 */ 0,
/* 392 */ 50040,
/* 393 */ 404,
/* 394 */ 50041,
/* 395 */ -379,
/* 396 */ 148,
/* 397 */ 401,
/* 398 */ 852,
/* 399 */ -397,
/* 400 */ 144,
/* 401 */ 0,
/* 402 */ -397,
/* 403 */ 227,
/* 404 */ 408,
/* 405 */ 489,
/* 406 */ -404,
/* 407 */ 147,
/* 408 */ 0,
/* 409 */ -404,
/* 410 */ 228,
/* 411 */ 0,
/* 412 */ 50042,
/* 413 */ 417,
/* 414 */ 424,
/* 415 */ -411,
/* 416 */ 32,
/* 417 */ 421,
/* 418 */ 431,
/* 419 */ -417,
/* 420 */ 149,
/* 421 */ 0,
/* 422 */ -417,
/* 423 */ 229,
/* 424 */ 428,
/* 425 */ 411,
/* 426 */ -424,
/* 427 */ 150,
/* 428 */ 0,
/* 429 */ -424,
/* 430 */ 230,
/* 431 */ 0,
/* 432 */ 436,
/* 433 */ 168,
/* 434 */ -431,
/* 435 */ 33,
/* 436 */ 440,
/* 437 */ 431,
/* 438 */ -436,
/* 439 */ 151,
/* 440 */ 0,
/* 441 */ -436,
/* 442 */ 231,
/* 443 */ 0,
/* 444 */ 456,
/* 445 */ 448,
/* 446 */ -443,
/* 447 */ 34,
/* 448 */ 453,
/* 449 */ 50044,
/* 450 */ 50290,
/* 451 */ -448,
/* 452 */ 152,
/* 453 */ 0,
/* 454 */ -448,
/* 455 */ 232,
/* 456 */ 0,
/* 457 */ 461,
/* 458 */ 469,
/* 459 */ -456,
/* 460 */ 35,
/* 461 */ 466,
/* 462 */ 456,
/* 463 */ 50044,
/* 464 */ -461,
/* 465 */ 153,
/* 466 */ 0,
/* 467 */ -461,
/* 468 */ 233,
/* 469 */ 0,
/* 470 */ 72,
/* 471 */ 474,
/* 472 */ -469,
/* 473 */ 36,
/* 474 */ 478,
/* 475 */ 352,
/* 476 */ -474,
/* 477 */ 154,
/* 478 */ 0,
/* 479 */ 482,
/* 480 */ -474,
/* 481 */ 156,
/* 482 */ 486,
/* 483 */ 545,
/* 484 */ -482,
/* 485 */ 155,
/* 486 */ 0,
/* 487 */ -482,
/* 488 */ 234,
/* 489 */ 0,
/* 490 */ 494,
/* 491 */ 1159,
/* 492 */ -489,
/* 493 */ 37,
/* 494 */ 499,
/* 495 */ 489,
/* 496 */ 50044,
/* 497 */ -494,
/* 498 */ 157,
/* 499 */ 0,
/* 500 */ -494,
/* 501 */ 235,
/* 502 */ 506,
/* 503 */ 815,
/* 504 */ -502,
/* 505 */ 38,
/* 506 */ 0,
/* 507 */ 50123,
/* 508 */ 520,
/* 509 */ 513,
/* 510 */ 50125,
/* 511 */ -502,
/* 512 */ 39,
/* 513 */ 517,
/* 514 */ 50044,
/* 515 */ -513,
/* 516 */ 158,
/* 517 */ 0,
/* 518 */ -513,
/* 519 */ 236,
/* 520 */ 0,
/* 521 */ 525,
/* 522 */ 502,
/* 523 */ -520,
/* 524 */ 40,
/* 525 */ 530,
/* 526 */ 520,
/* 527 */ 50044,
/* 528 */ -525,
/* 529 */ 159,
/* 530 */ 0,
/* 531 */ -525,
/* 532 */ 237,
/* 533 */ 0,
/* 534 */ 256,
/* 535 */ 538,
/* 536 */ -533,
/* 537 */ 41,
/* 538 */ 542,
/* 539 */ 545,
/* 540 */ -538,
/* 541 */ 160,
/* 542 */ 0,
/* 543 */ -538,
/* 544 */ 238,
/* 545 */ 549,
/* 546 */ 411,
/* 547 */ -545,
/* 548 */ 42,
/* 549 */ 0,
/* 550 */ 554,
/* 551 */ 561,
/* 552 */ -545,
/* 553 */ 43,
/* 554 */ 558,
/* 555 */ 411,
/* 556 */ -554,
/* 557 */ 161,
/* 558 */ 0,
/* 559 */ -554,
/* 560 */ 239,
/* 561 */ 567,
/* 562 */ 50040,
/* 563 */ 545,
/* 564 */ 50041,
/* 565 */ -561,
/* 566 */ 44,
/* 567 */ 0,
/* 568 */ 572,
/* 569 */ 579,
/* 570 */ -561,
/* 571 */ 45,
/* 572 */ 576,
/* 573 */ 561,
/* 574 */ -572,
/* 575 */ 162,
/* 576 */ 0,
/* 577 */ -572,
/* 578 */ 240,
/* 579 */ 585,
/* 580 */ 50091,
/* 581 */ 591,
/* 582 */ 50093,
/* 583 */ -579,
/* 584 */ 164,
/* 585 */ 0,
/* 586 */ 50040,
/* 587 */ 598,
/* 588 */ 50041,
/* 589 */ -579,
/* 590 */ 166,
/* 591 */ 595,
/* 592 */ 852,
/* 593 */ -591,
/* 594 */ 163,
/* 595 */ 0,
/* 596 */ -591,
/* 597 */ 241,
/* 598 */ 602,
/* 599 */ 443,
/* 600 */ -598,
/* 601 */ 165,
/* 602 */ 0,
/* 603 */ -598,
/* 604 */ 242,
/* 605 */ 0,
/* 606 */ 1159,
/* 607 */ -605,
/* 608 */ 46,
/* 609 */ 613,
/* 610 */ 633,
/* 611 */ -609,
/* 612 */ 47,
/* 613 */ 617,
/* 614 */ 652,
/* 615 */ -609,
/* 616 */ 48,
/* 617 */ 621,
/* 618 */ 664,
/* 619 */ -609,
/* 620 */ 49,
/* 621 */ 625,
/* 622 */ 697,
/* 623 */ -609,
/* 624 */ 50,
/* 625 */ 629,
/* 626 */ 722,
/* 627 */ -609,
/* 628 */ 51,
/* 629 */ 0,
/* 630 */ 773,
/* 631 */ -609,
/* 632 */ 52,
/* 633 */ 639,
/* 634 */ 1159,
/* 635 */ 50058,
/* 636 */ 609,
/* 637 */ -633,
/* 638 */ 53,
/* 639 */ 646,
/* 640 */ 50258,
/* 641 */ 852,
/* 642 */ 50058,
/* 643 */ 609,
/* 644 */ -633,
/* 645 */ 54,
/* 646 */ 0,
/* 647 */ 50262,
/* 648 */ 50058,
/* 649 */ 609,
/* 650 */ -633,
/* 651 */ 55,
/* 652 */ 0,
/* 653 */ 657,
/* 654 */ 50059,
/* 655 */ -652,
/* 656 */ 56,
/* 657 */ 661,
/* 658 */ 802,
/* 659 */ -657,
/* 660 */ 167,
/* 661 */ 0,
/* 662 */ -657,
/* 663 */ 243,
/* 664 */ 0,
/* 665 */ 50123,
/* 666 */ 671,
/* 667 */ 678,
/* 668 */ 50125,
/* 669 */ -664,
/* 670 */ 57,
/* 671 */ 675,
/* 672 */ 60,
/* 673 */ -671,
/* 674 */ 168,
/* 675 */ 0,
/* 676 */ -671,
/* 677 */ 244,
/* 678 */ 682,
/* 679 */ 685,
/* 680 */ -678,
/* 681 */ 169,
/* 682 */ 0,
/* 683 */ -678,
/* 684 */ 245,
/* 685 */ 0,
/* 686 */ 690,
/* 687 */ 609,
/* 688 */ -685,
/* 689 */ 58,
/* 690 */ 694,
/* 691 */ 685,
/* 692 */ -690,
/* 693 */ 170,
/* 694 */ 0,
/* 695 */ -690,
/* 696 */ 246,
/* 697 */ 706,
/* 698 */ 50271,
/* 699 */ 50040,
/* 700 */ 802,
/* 701 */ 50041,
/* 702 */ 609,
/* 703 */ 714,
/* 704 */ -697,
/* 705 */ 59,
/* 706 */ 0,
/* 707 */ 50281,
/* 708 */ 50040,
/* 709 */ 802,
/* 710 */ 50041,
/* 711 */ 609,
/* 712 */ -697,
/* 713 */ 60,
/* 714 */ 719,
/* 715 */ 50265,
/* 716 */ 609,
/* 717 */ -714,
/* 718 */ 171,
/* 719 */ 0,
/* 720 */ -714,
/* 721 */ 247,
/* 722 */ 730,
/* 723 */ 50287,
/* 724 */ 50040,
/* 725 */ 802,
/* 726 */ 50041,
/* 727 */ 609,
/* 728 */ -722,
/* 729 */ 61,
/* 730 */ 740,
/* 731 */ 50263,
/* 732 */ 609,
/* 733 */ 50287,
/* 734 */ 50040,
/* 735 */ 802,
/* 736 */ 50041,
/* 737 */ 50059,
/* 738 */ -722,
/* 739 */ 62,
/* 740 */ 0,
/* 741 */ 50269,
/* 742 */ 50040,
/* 743 */ 752,
/* 744 */ 50059,
/* 745 */ 759,
/* 746 */ 50059,
/* 747 */ 766,
/* 748 */ 50041,
/* 749 */ 609,
/* 750 */ -722,
/* 751 */ 63,
/* 752 */ 756,
/* 753 */ 802,
/* 754 */ -752,
/* 755 */ 172,
/* 756 */ 0,
/* 757 */ -752,
/* 758 */ 248,
/* 759 */ 763,
/* 760 */ 802,
/* 761 */ -759,
/* 762 */ 173,
/* 763 */ 0,
/* 764 */ -759,
/* 765 */ 249,
/* 766 */ 770,
/* 767 */ 802,
/* 768 */ -766,
/* 769 */ 174,
/* 770 */ 0,
/* 771 */ -766,
/* 772 */ 250,
/* 773 */ 779,
/* 774 */ 50270,
/* 775 */ 1159,
/* 776 */ 50059,
/* 777 */ -773,
/* 778 */ 64,
/* 779 */ 784,
/* 780 */ 50261,
/* 781 */ 50059,
/* 782 */ -773,
/* 783 */ 65,
/* 784 */ 789,
/* 785 */ 50257,
/* 786 */ 50059,
/* 787 */ -773,
/* 788 */ 66,
/* 789 */ 0,
/* 790 */ 50275,
/* 791 */ 795,
/* 792 */ 50059,
/* 793 */ -773,
/* 794 */ 67,
/* 795 */ 799,
/* 796 */ 802,
/* 797 */ -795,
/* 798 */ 175,
/* 799 */ 0,
/* 800 */ -795,
/* 801 */ 251,
/* 802 */ 0,
/* 803 */ 807,
/* 804 */ 815,
/* 805 */ -802,
/* 806 */ 68,
/* 807 */ 812,
/* 808 */ 802,
/* 809 */ 50044,
/* 810 */ -807,
/* 811 */ 176,
/* 812 */ 0,
/* 813 */ -807,
/* 814 */ 252,
/* 815 */ 819,
/* 816 */ 837,
/* 817 */ -815,
/* 818 */ 69,
/* 819 */ 0,
/* 820 */ 1004,
/* 821 */ 825,
/* 822 */ 815,
/* 823 */ -815,
/* 824 */ 70,
/* 825 */ 0,
/* 826 */ 829,
/* 827 */ -825,
/* 828 */ 71,
/* 829 */ 833,
/* 830 */ 50291,
/* 831 */ -829,
/* 832 */ 177,
/* 833 */ 0,
/* 834 */ 50061,
/* 835 */ -829,
/* 836 */ 178,
/* 837 */ 0,
/* 838 */ 856,
/* 839 */ 842,
/* 840 */ -837,
/* 841 */ 72,
/* 842 */ 849,
/* 843 */ 50063,
/* 844 */ 802,
/* 845 */ 50058,
/* 846 */ 837,
/* 847 */ -842,
/* 848 */ 179,
/* 849 */ 0,
/* 850 */ -842,
/* 851 */ 253,
/* 852 */ 0,
/* 853 */ 837,
/* 854 */ -852,
/* 855 */ 73,
/* 856 */ 0,
/* 857 */ 861,
/* 858 */ 869,
/* 859 */ -856,
/* 860 */ 74,
/* 861 */ 866,
/* 862 */ 856,
/* 863 */ 50297,
/* 864 */ -861,
/* 865 */ 180,
/* 866 */ 0,
/* 867 */ -861,
/* 868 */ 254,
/* 869 */ 0,
/* 870 */ 874,
/* 871 */ 882,
/* 872 */ -869,
/* 873 */ 75,
/* 874 */ 879,
/* 875 */ 869,
/* 876 */ 50298,
/* 877 */ -874,
/* 878 */ 181,
/* 879 */ 0,
/* 880 */ -874,
/* 881 */ 255,
/* 882 */ 0,
/* 883 */ 887,
/* 884 */ 895,
/* 885 */ -882,
/* 886 */ 76,
/* 887 */ 892,
/* 888 */ 882,
/* 889 */ 50301,
/* 890 */ -887,
/* 891 */ 182,
/* 892 */ 0,
/* 893 */ -887,
/* 894 */ 256,
/* 895 */ 0,
/* 896 */ 900,
/* 897 */ 908,
/* 898 */ -895,
/* 899 */ 77,
/* 900 */ 905,
/* 901 */ 895,
/* 902 */ 50303,
/* 903 */ -900,
/* 904 */ 183,
/* 905 */ 0,
/* 906 */ -900,
/* 907 */ 257,
/* 908 */ 0,
/* 909 */ 913,
/* 910 */ 921,
/* 911 */ -908,
/* 912 */ 78,
/* 913 */ 918,
/* 914 */ 908,
/* 915 */ 50302,
/* 916 */ -913,
/* 917 */ 184,
/* 918 */ 0,
/* 919 */ -913,
/* 920 */ 258,
/* 921 */ 0,
/* 922 */ 926,
/* 923 */ 934,
/* 924 */ -921,
/* 925 */ 79,
/* 926 */ 931,
/* 927 */ 921,
/* 928 */ 50292,
/* 929 */ -926,
/* 930 */ 185,
/* 931 */ 0,
/* 932 */ -926,
/* 933 */ 259,
/* 934 */ 0,
/* 935 */ 939,
/* 936 */ 947,
/* 937 */ -934,
/* 938 */ 80,
/* 939 */ 944,
/* 940 */ 934,
/* 941 */ 50304,
/* 942 */ -939,
/* 943 */ 186,
/* 944 */ 0,
/* 945 */ -939,
/* 946 */ 260,
/* 947 */ 0,
/* 948 */ 952,
/* 949 */ 968,
/* 950 */ -947,
/* 951 */ 81,
/* 952 */ 957,
/* 953 */ 947,
/* 954 */ 960,
/* 955 */ -952,
/* 956 */ 189,
/* 957 */ 0,
/* 958 */ -952,
/* 959 */ 261,
/* 960 */ 964,
/* 961 */ 50043,
/* 962 */ -960,
/* 963 */ 187,
/* 964 */ 0,
/* 965 */ 50045,
/* 966 */ -960,
/* 967 */ 188,
/* 968 */ 0,
/* 969 */ 973,
/* 970 */ 993,
/* 971 */ -968,
/* 972 */ 82,
/* 973 */ 978,
/* 974 */ 968,
/* 975 */ 981,
/* 976 */ -973,
/* 977 */ 193,
/* 978 */ 0,
/* 979 */ -973,
/* 980 */ 262,
/* 981 */ 985,
/* 982 */ 50042,
/* 983 */ -981,
/* 984 */ 190,
/* 985 */ 989,
/* 986 */ 50047,
/* 987 */ -981,
/* 988 */ 191,
/* 989 */ 0,
/* 990 */ 50037,
/* 991 */ -981,
/* 992 */ 192,
/* 993 */ 997,
/* 994 */ 1004,
/* 995 */ -993,
/* 996 */ 83,
/* 997 */ 0,
/* 998 */ 50040,
/* 999 */ 533,
/* 1000 */ 50041,
/* 1001 */ 993,
/* 1002 */ -993,
/* 1003 */ 84,
/* 1004 */ 1008,
/* 1005 */ 1066,
/* 1006 */ -1004,
/* 1007 */ 85,
/* 1008 */ 1013,
/* 1009 */ 1030,
/* 1010 */ 1004,
/* 1011 */ -1004,
/* 1012 */ 86,
/* 1013 */ 1018,
/* 1014 */ 1038,
/* 1015 */ 993,
/* 1016 */ -1004,
/* 1017 */ 87,
/* 1018 */ 1023,
/* 1019 */ 50278,
/* 1020 */ 1004,
/* 1021 */ -1004,
/* 1022 */ 88,
/* 1023 */ 0,
/* 1024 */ 50278,
/* 1025 */ 50040,
/* 1026 */ 533,
/* 1027 */ 50041,
/* 1028 */ -1004,
/* 1029 */ 89,
/* 1030 */ 1034,
/* 1031 */ 50294,
/* 1032 */ -1030,
/* 1033 */ 194,
/* 1034 */ 0,
/* 1035 */ 50295,
/* 1036 */ -1030,
/* 1037 */ 195,
/* 1038 */ 0,
/* 1039 */ 1042,
/* 1040 */ -1038,
/* 1041 */ 90,
/* 1042 */ 1046,
/* 1043 */ 50302,
/* 1044 */ -1042,
/* 1045 */ 196,
/* 1046 */ 1050,
/* 1047 */ 50042,
/* 1048 */ -1042,
/* 1049 */ 197,
/* 1050 */ 1054,
/* 1051 */ 50043,
/* 1052 */ -1042,
/* 1053 */ 198,
/* 1054 */ 1058,
/* 1055 */ 50045,
/* 1056 */ -1042,
/* 1057 */ 199,
/* 1058 */ 1062,
/* 1059 */ 50126,
/* 1060 */ -1042,
/* 1061 */ 200,
/* 1062 */ 0,
/* 1063 */ 50033,
/* 1064 */ -1042,
/* 1065 */ 201,
/* 1066 */ 1070,
/* 1067 */ 1112,
/* 1068 */ -1066,
/* 1069 */ 91,
/* 1070 */ 0,
/* 1071 */ 1066,
/* 1072 */ 1075,
/* 1073 */ -1066,
/* 1074 */ 92,
/* 1075 */ 1081,
/* 1076 */ 50091,
/* 1077 */ 802,
/* 1078 */ 50093,
/* 1079 */ -1075,
/* 1080 */ 202,
/* 1081 */ 1087,
/* 1082 */ 50040,
/* 1083 */ 1105,
/* 1084 */ 50041,
/* 1085 */ -1075,
/* 1086 */ 204,
/* 1087 */ 1092,
/* 1088 */ 50046,
/* 1089 */ 1159,
/* 1090 */ -1075,
/* 1091 */ 205,
/* 1092 */ 1097,
/* 1093 */ 50296,
/* 1094 */ 1159,
/* 1095 */ -1075,
/* 1096 */ 206,
/* 1097 */ 1101,
/* 1098 */ 50294,
/* 1099 */ -1075,
/* 1100 */ 207,
/* 1101 */ 0,
/* 1102 */ 50295,
/* 1103 */ -1075,
/* 1104 */ 208,
/* 1105 */ 1109,
/* 1106 */ 1130,
/* 1107 */ -1105,
/* 1108 */ 203,
/* 1109 */ 0,
/* 1110 */ -1105,
/* 1111 */ 263,
/* 1112 */ 1116,
/* 1113 */ 1159,
/* 1114 */ -1112,
/* 1115 */ 93,
/* 1116 */ 1120,
/* 1117 */ 1143,
/* 1118 */ -1112,
/* 1119 */ 94,
/* 1120 */ 1124,
/* 1121 */ 50289,
/* 1122 */ -1112,
/* 1123 */ 95,
/* 1124 */ 0,
/* 1125 */ 50040,
/* 1126 */ 802,
/* 1127 */ 50041,
/* 1128 */ -1112,
/* 1129 */ 96,
/* 1130 */ 0,
/* 1131 */ 1135,
/* 1132 */ 815,
/* 1133 */ -1130,
/* 1134 */ 97,
/* 1135 */ 1140,
/* 1136 */ 1130,
/* 1137 */ 50044,
/* 1138 */ -1135,
/* 1139 */ 209,
/* 1140 */ 0,
/* 1141 */ -1135,
/* 1142 */ 264,
/* 1143 */ 1147,
/* 1144 */ 50308,
/* 1145 */ -1143,
/* 1146 */ 98,
/* 1147 */ 1151,
/* 1148 */ 50306,
/* 1149 */ -1143,
/* 1150 */ 99,
/* 1151 */ 1155,
/* 1152 */ 50307,
/* 1153 */ -1143,
/* 1154 */ 100,
/* 1155 */ 0,
/* 1156 */ 1159,
/* 1157 */ -1143,
/* 1158 */ 101,
/* 1159 */ 0,
/* 1160 */ 50299,
/* 1161 */ -1159,
/* 1162 */ 102,
0
};
extern int yyannotation[];
int yyannotation[] = {
0,
/* 1 */ 0,
/* 2 */ 0,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 0,
/* 6 */ 0,
/* 7 */ 1,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 15,
/* 11 */ 1,
/* 12 */ 1,
/* 13 */ -10,
/* 14 */ 1,
/* 15 */ 0,
/* 16 */ -10,
/* 17 */ 2,
/* 18 */ 22,
/* 19 */ 1,
/* 20 */ -18,
/* 21 */ 1,
/* 22 */ 0,
/* 23 */ 1,
/* 24 */ -18,
/* 25 */ 2,
/* 26 */ 0,
/* 27 */ 1,
/* 28 */ 1,
/* 29 */ 1,
/* 30 */ 1,
/* 31 */ -26,
/* 32 */ 1,
/* 33 */ 37,
/* 34 */ 1,
/* 35 */ -33,
/* 36 */ 1,
/* 37 */ 0,
/* 38 */ -33,
/* 39 */ 2,
/* 40 */ 44,
/* 41 */ 1,
/* 42 */ -40,
/* 43 */ 1,
/* 44 */ 0,
/* 45 */ -40,
/* 46 */ 2,
/* 47 */ 0,
/* 48 */ 1,
/* 49 */ 1,
/* 50 */ 50059,
/* 51 */ -47,
/* 52 */ 1,
/* 53 */ 57,
/* 54 */ 1,
/* 55 */ -53,
/* 56 */ 1,
/* 57 */ 0,
/* 58 */ -53,
/* 59 */ 2,
/* 60 */ 0,
/* 61 */ 1,
/* 62 */ 1,
/* 63 */ -60,
/* 64 */ 1,
/* 65 */ 69,
/* 66 */ 1,
/* 67 */ -65,
/* 68 */ 1,
/* 69 */ 0,
/* 70 */ -65,
/* 71 */ 2,
/* 72 */ 0,
/* 73 */ 1,
/* 74 */ 1,
/* 75 */ -72,
/* 76 */ 1,
/* 77 */ 81,
/* 78 */ 1,
/* 79 */ -77,
/* 80 */ 1,
/* 81 */ 85,
/* 82 */ 1,
/* 83 */ -77,
/* 84 */ 2,
/* 85 */ 0,
/* 86 */ 1,
/* 87 */ -77,
/* 88 */ 3,
/* 89 */ 93,
/* 90 */ 1,
/* 91 */ -89,
/* 92 */ 1,
/* 93 */ 0,
/* 94 */ -89,
/* 95 */ 2,
/* 96 */ 0,
/* 97 */ 1,
/* 98 */ -96,
/* 99 */ 1,
/* 100 */ 104,
/* 101 */ 50256,
/* 102 */ -100,
/* 103 */ 1,
/* 104 */ 108,
/* 105 */ 50274,
/* 106 */ -100,
/* 107 */ 2,
/* 108 */ 112,
/* 109 */ 50279,
/* 110 */ -100,
/* 111 */ 3,
/* 112 */ 116,
/* 113 */ 50267,
/* 114 */ -100,
/* 115 */ 4,
/* 116 */ 0,
/* 117 */ 50282,
/* 118 */ -100,
/* 119 */ 5,
/* 120 */ 124,
/* 121 */ 1,
/* 122 */ -120,
/* 123 */ 1,
/* 124 */ 128,
/* 125 */ 1,
/* 126 */ -120,
/* 127 */ 2,
/* 128 */ 0,
/* 129 */ 1,
/* 130 */ -120,
/* 131 */ 3,
/* 132 */ 136,
/* 133 */ 50285,
/* 134 */ -132,
/* 135 */ 1,
/* 136 */ 140,
/* 137 */ 50259,
/* 138 */ -132,
/* 139 */ 2,
/* 140 */ 144,
/* 141 */ 50276,
/* 142 */ -132,
/* 143 */ 3,
/* 144 */ 148,
/* 145 */ 50272,
/* 146 */ -132,
/* 147 */ 4,
/* 148 */ 152,
/* 149 */ 50273,
/* 150 */ -132,
/* 151 */ 5,
/* 152 */ 156,
/* 153 */ 50268,
/* 154 */ -132,
/* 155 */ 6,
/* 156 */ 160,
/* 157 */ 50264,
/* 158 */ -132,
/* 159 */ 7,
/* 160 */ 164,
/* 161 */ 50277,
/* 162 */ -132,
/* 163 */ 8,
/* 164 */ 0,
/* 165 */ 50284,
/* 166 */ -132,
/* 167 */ 9,
/* 168 */ 0,
/* 169 */ 1,
/* 170 */ -168,
/* 171 */ 1,
/* 172 */ 176,
/* 173 */ 50260,
/* 174 */ -172,
/* 175 */ 1,
/* 176 */ 0,
/* 177 */ 50286,
/* 178 */ -172,
/* 179 */ 2,
/* 180 */ 188,
/* 181 */ 1,
/* 182 */ 1,
/* 183 */ 50123,
/* 184 */ 1,
/* 185 */ 50125,
/* 186 */ -180,
/* 187 */ 1,
/* 188 */ 0,
/* 189 */ 1,
/* 190 */ 1,
/* 191 */ -180,
/* 192 */ 2,
/* 193 */ 197,
/* 194 */ 1,
/* 195 */ -193,
/* 196 */ 1,
/* 197 */ 0,
/* 198 */ -193,
/* 199 */ 2,
/* 200 */ 0,
/* 201 */ 1,
/* 202 */ -200,
/* 203 */ 1,
/* 204 */ 208,
/* 205 */ 50280,
/* 206 */ -204,
/* 207 */ 1,
/* 208 */ 0,
/* 209 */ 50283,
/* 210 */ -204,
/* 211 */ 2,
/* 212 */ 0,
/* 213 */ 1,
/* 214 */ 1,
/* 215 */ -212,
/* 216 */ 1,
/* 217 */ 221,
/* 218 */ 1,
/* 219 */ -217,
/* 220 */ 1,
/* 221 */ 0,
/* 222 */ -217,
/* 223 */ 2,
/* 224 */ 0,
/* 225 */ 1,
/* 226 */ 1,
/* 227 */ -224,
/* 228 */ 1,
/* 229 */ 234,
/* 230 */ 1,
/* 231 */ 50044,
/* 232 */ -229,
/* 233 */ 1,
/* 234 */ 0,
/* 235 */ -229,
/* 236 */ 2,
/* 237 */ 0,
/* 238 */ 1,
/* 239 */ 1,
/* 240 */ -237,
/* 241 */ 1,
/* 242 */ 247,
/* 243 */ 1,
/* 244 */ 50061,
/* 245 */ -242,
/* 246 */ 1,
/* 247 */ 0,
/* 248 */ -242,
/* 249 */ 2,
/* 250 */ 0,
/* 251 */ 1,
/* 252 */ 1,
/* 253 */ 50059,
/* 254 */ -250,
/* 255 */ 1,
/* 256 */ 0,
/* 257 */ 1,
/* 258 */ 1,
/* 259 */ -256,
/* 260 */ 1,
/* 261 */ 265,
/* 262 */ 1,
/* 263 */ -261,
/* 264 */ 1,
/* 265 */ 0,
/* 266 */ 1,
/* 267 */ -261,
/* 268 */ 2,
/* 269 */ 273,
/* 270 */ 1,
/* 271 */ -269,
/* 272 */ 1,
/* 273 */ 0,
/* 274 */ -269,
/* 275 */ 2,
/* 276 */ 0,
/* 277 */ 1,
/* 278 */ 1,
/* 279 */ -276,
/* 280 */ 1,
/* 281 */ 286,
/* 282 */ 1,
/* 283 */ 50044,
/* 284 */ -281,
/* 285 */ 1,
/* 286 */ 0,
/* 287 */ -281,
/* 288 */ 2,
/* 289 */ 293,
/* 290 */ 1,
/* 291 */ -289,
/* 292 */ 1,
/* 293 */ 0,
/* 294 */ 1,
/* 295 */ 50058,
/* 296 */ 1,
/* 297 */ -289,
/* 298 */ 2,
/* 299 */ 303,
/* 300 */ 1,
/* 301 */ -299,
/* 302 */ 1,
/* 303 */ 0,
/* 304 */ -299,
/* 305 */ 2,
/* 306 */ 314,
/* 307 */ 50266,
/* 308 */ 1,
/* 309 */ 50123,
/* 310 */ 1,
/* 311 */ 50125,
/* 312 */ -306,
/* 313 */ 1,
/* 314 */ 0,
/* 315 */ 50266,
/* 316 */ 1,
/* 317 */ -306,
/* 318 */ 2,
/* 319 */ 323,
/* 320 */ 1,
/* 321 */ -319,
/* 322 */ 1,
/* 323 */ 0,
/* 324 */ -319,
/* 325 */ 2,
/* 326 */ 0,
/* 327 */ 1,
/* 328 */ 1,
/* 329 */ -326,
/* 330 */ 1,
/* 331 */ 336,
/* 332 */ 1,
/* 333 */ 50044,
/* 334 */ -331,
/* 335 */ 1,
/* 336 */ 0,
/* 337 */ -331,
/* 338 */ 2,
/* 339 */ 0,
/* 340 */ 1,
/* 341 */ 1,
/* 342 */ -339,
/* 343 */ 1,
/* 344 */ 349,
/* 345 */ 50061,
/* 346 */ 1,
/* 347 */ -344,
/* 348 */ 1,
/* 349 */ 0,
/* 350 */ -344,
/* 351 */ 2,
/* 352 */ 0,
/* 353 */ 1,
/* 354 */ 1,
/* 355 */ -352,
/* 356 */ 1,
/* 357 */ 361,
/* 358 */ 1,
/* 359 */ -357,
/* 360 */ 1,
/* 361 */ 0,
/* 362 */ -357,
/* 363 */ 2,
/* 364 */ 368,
/* 365 */ 1,
/* 366 */ -364,
/* 367 */ 1,
/* 368 */ 374,
/* 369 */ 50040,
/* 370 */ 1,
/* 371 */ 50041,
/* 372 */ -364,
/* 373 */ 2,
/* 374 */ 0,
/* 375 */ 1,
/* 376 */ 1,
/* 377 */ -364,
/* 378 */ 3,
/* 379 */ 385,
/* 380 */ 50091,
/* 381 */ 1,
/* 382 */ 50093,
/* 383 */ -379,
/* 384 */ 1,
/* 385 */ 391,
/* 386 */ 50040,
/* 387 */ 1,
/* 388 */ 50041,
/* 389 */ -379,
/* 390 */ 2,
/* 391 */ 0,
/* 392 */ 50040,
/* 393 */ 1,
/* 394 */ 50041,
/* 395 */ -379,
/* 396 */ 3,
/* 397 */ 401,
/* 398 */ 1,
/* 399 */ -397,
/* 400 */ 1,
/* 401 */ 0,
/* 402 */ -397,
/* 403 */ 2,
/* 404 */ 408,
/* 405 */ 1,
/* 406 */ -404,
/* 407 */ 1,
/* 408 */ 0,
/* 409 */ -404,
/* 410 */ 2,
/* 411 */ 0,
/* 412 */ 50042,
/* 413 */ 1,
/* 414 */ 1,
/* 415 */ -411,
/* 416 */ 1,
/* 417 */ 421,
/* 418 */ 1,
/* 419 */ -417,
/* 420 */ 1,
/* 421 */ 0,
/* 422 */ -417,
/* 423 */ 2,
/* 424 */ 428,
/* 425 */ 1,
/* 426 */ -424,
/* 427 */ 1,
/* 428 */ 0,
/* 429 */ -424,
/* 430 */ 2,
/* 431 */ 0,
/* 432 */ 1,
/* 433 */ 1,
/* 434 */ -431,
/* 435 */ 1,
/* 436 */ 440,
/* 437 */ 1,
/* 438 */ -436,
/* 439 */ 1,
/* 440 */ 0,
/* 441 */ -436,
/* 442 */ 2,
/* 443 */ 0,
/* 444 */ 1,
/* 445 */ 1,
/* 446 */ -443,
/* 447 */ 1,
/* 448 */ 453,
/* 449 */ 50044,
/* 450 */ 50290,
/* 451 */ -448,
/* 452 */ 1,
/* 453 */ 0,
/* 454 */ -448,
/* 455 */ 2,
/* 456 */ 0,
/* 457 */ 1,
/* 458 */ 1,
/* 459 */ -456,
/* 460 */ 1,
/* 461 */ 466,
/* 462 */ 1,
/* 463 */ 50044,
/* 464 */ -461,
/* 465 */ 1,
/* 466 */ 0,
/* 467 */ -461,
/* 468 */ 2,
/* 469 */ 0,
/* 470 */ 1,
/* 471 */ 1,
/* 472 */ -469,
/* 473 */ 1,
/* 474 */ 478,
/* 475 */ 1,
/* 476 */ -474,
/* 477 */ 1,
/* 478 */ 0,
/* 479 */ 1,
/* 480 */ -474,
/* 481 */ 2,
/* 482 */ 486,
/* 483 */ 1,
/* 484 */ -482,
/* 485 */ 1,
/* 486 */ 0,
/* 487 */ -482,
/* 488 */ 2,
/* 489 */ 0,
/* 490 */ 1,
/* 491 */ 1,
/* 492 */ -489,
/* 493 */ 1,
/* 494 */ 499,
/* 495 */ 1,
/* 496 */ 50044,
/* 497 */ -494,
/* 498 */ 1,
/* 499 */ 0,
/* 500 */ -494,
/* 501 */ 2,
/* 502 */ 506,
/* 503 */ 1,
/* 504 */ -502,
/* 505 */ 1,
/* 506 */ 0,
/* 507 */ 50123,
/* 508 */ 1,
/* 509 */ 1,
/* 510 */ 50125,
/* 511 */ -502,
/* 512 */ 2,
/* 513 */ 517,
/* 514 */ 50044,
/* 515 */ -513,
/* 516 */ 1,
/* 517 */ 0,
/* 518 */ -513,
/* 519 */ 2,
/* 520 */ 0,
/* 521 */ 1,
/* 522 */ 1,
/* 523 */ -520,
/* 524 */ 1,
/* 525 */ 530,
/* 526 */ 1,
/* 527 */ 50044,
/* 528 */ -525,
/* 529 */ 1,
/* 530 */ 0,
/* 531 */ -525,
/* 532 */ 2,
/* 533 */ 0,
/* 534 */ 1,
/* 535 */ 1,
/* 536 */ -533,
/* 537 */ 1,
/* 538 */ 542,
/* 539 */ 1,
/* 540 */ -538,
/* 541 */ 1,
/* 542 */ 0,
/* 543 */ -538,
/* 544 */ 2,
/* 545 */ 549,
/* 546 */ 1,
/* 547 */ -545,
/* 548 */ 1,
/* 549 */ 0,
/* 550 */ 1,
/* 551 */ 1,
/* 552 */ -545,
/* 553 */ 2,
/* 554 */ 558,
/* 555 */ 1,
/* 556 */ -554,
/* 557 */ 1,
/* 558 */ 0,
/* 559 */ -554,
/* 560 */ 2,
/* 561 */ 567,
/* 562 */ 50040,
/* 563 */ 1,
/* 564 */ 50041,
/* 565 */ -561,
/* 566 */ 1,
/* 567 */ 0,
/* 568 */ 1,
/* 569 */ 1,
/* 570 */ -561,
/* 571 */ 2,
/* 572 */ 576,
/* 573 */ 1,
/* 574 */ -572,
/* 575 */ 1,
/* 576 */ 0,
/* 577 */ -572,
/* 578 */ 2,
/* 579 */ 585,
/* 580 */ 50091,
/* 581 */ 1,
/* 582 */ 50093,
/* 583 */ -579,
/* 584 */ 1,
/* 585 */ 0,
/* 586 */ 50040,
/* 587 */ 1,
/* 588 */ 50041,
/* 589 */ -579,
/* 590 */ 2,
/* 591 */ 595,
/* 592 */ 1,
/* 593 */ -591,
/* 594 */ 1,
/* 595 */ 0,
/* 596 */ -591,
/* 597 */ 2,
/* 598 */ 602,
/* 599 */ 1,
/* 600 */ -598,
/* 601 */ 1,
/* 602 */ 0,
/* 603 */ -598,
/* 604 */ 2,
/* 605 */ 0,
/* 606 */ 1,
/* 607 */ -605,
/* 608 */ 1,
/* 609 */ 613,
/* 610 */ 1,
/* 611 */ -609,
/* 612 */ 1,
/* 613 */ 617,
/* 614 */ 1,
/* 615 */ -609,
/* 616 */ 2,
/* 617 */ 621,
/* 618 */ 1,
/* 619 */ -609,
/* 620 */ 3,
/* 621 */ 625,
/* 622 */ 1,
/* 623 */ -609,
/* 624 */ 4,
/* 625 */ 629,
/* 626 */ 1,
/* 627 */ -609,
/* 628 */ 5,
/* 629 */ 0,
/* 630 */ 1,
/* 631 */ -609,
/* 632 */ 6,
/* 633 */ 639,
/* 634 */ 1,
/* 635 */ 50058,
/* 636 */ 1,
/* 637 */ -633,
/* 638 */ 1,
/* 639 */ 646,
/* 640 */ 50258,
/* 641 */ 1,
/* 642 */ 50058,
/* 643 */ 1,
/* 644 */ -633,
/* 645 */ 2,
/* 646 */ 0,
/* 647 */ 50262,
/* 648 */ 50058,
/* 649 */ 1,
/* 650 */ -633,
/* 651 */ 3,
/* 652 */ 0,
/* 653 */ 1,
/* 654 */ 50059,
/* 655 */ -652,
/* 656 */ 1,
/* 657 */ 661,
/* 658 */ 1,
/* 659 */ -657,
/* 660 */ 1,
/* 661 */ 0,
/* 662 */ -657,
/* 663 */ 2,
/* 664 */ 0,
/* 665 */ 50123,
/* 666 */ 1,
/* 667 */ 1,
/* 668 */ 50125,
/* 669 */ -664,
/* 670 */ 1,
/* 671 */ 675,
/* 672 */ 1,
/* 673 */ -671,
/* 674 */ 1,
/* 675 */ 0,
/* 676 */ -671,
/* 677 */ 2,
/* 678 */ 682,
/* 679 */ 1,
/* 680 */ -678,
/* 681 */ 1,
/* 682 */ 0,
/* 683 */ -678,
/* 684 */ 2,
/* 685 */ 0,
/* 686 */ 1,
/* 687 */ 1,
/* 688 */ -685,
/* 689 */ 1,
/* 690 */ 694,
/* 691 */ 1,
/* 692 */ -690,
/* 693 */ 1,
/* 694 */ 0,
/* 695 */ -690,
/* 696 */ 2,
/* 697 */ 706,
/* 698 */ 50271,
/* 699 */ 50040,
/* 700 */ 1,
/* 701 */ 50041,
/* 702 */ 1,
/* 703 */ 1,
/* 704 */ -697,
/* 705 */ 1,
/* 706 */ 0,
/* 707 */ 50281,
/* 708 */ 50040,
/* 709 */ 1,
/* 710 */ 50041,
/* 711 */ 1,
/* 712 */ -697,
/* 713 */ 2,
/* 714 */ 719,
/* 715 */ 50265,
/* 716 */ 1,
/* 717 */ -714,
/* 718 */ 1,
/* 719 */ 0,
/* 720 */ -714,
/* 721 */ 2,
/* 722 */ 730,
/* 723 */ 50287,
/* 724 */ 50040,
/* 725 */ 1,
/* 726 */ 50041,
/* 727 */ 1,
/* 728 */ -722,
/* 729 */ 1,
/* 730 */ 740,
/* 731 */ 50263,
/* 732 */ 1,
/* 733 */ 50287,
/* 734 */ 50040,
/* 735 */ 1,
/* 736 */ 50041,
/* 737 */ 50059,
/* 738 */ -722,
/* 739 */ 2,
/* 740 */ 0,
/* 741 */ 50269,
/* 742 */ 50040,
/* 743 */ 1,
/* 744 */ 50059,
/* 745 */ 1,
/* 746 */ 50059,
/* 747 */ 1,
/* 748 */ 50041,
/* 749 */ 1,
/* 750 */ -722,
/* 751 */ 3,
/* 752 */ 756,
/* 753 */ 1,
/* 754 */ -752,
/* 755 */ 1,
/* 756 */ 0,
/* 757 */ -752,
/* 758 */ 2,
/* 759 */ 763,
/* 760 */ 1,
/* 761 */ -759,
/* 762 */ 1,
/* 763 */ 0,
/* 764 */ -759,
/* 765 */ 2,
/* 766 */ 770,
/* 767 */ 1,
/* 768 */ -766,
/* 769 */ 1,
/* 770 */ 0,
/* 771 */ -766,
/* 772 */ 2,
/* 773 */ 779,
/* 774 */ 50270,
/* 775 */ 1,
/* 776 */ 50059,
/* 777 */ -773,
/* 778 */ 1,
/* 779 */ 784,
/* 780 */ 50261,
/* 781 */ 50059,
/* 782 */ -773,
/* 783 */ 2,
/* 784 */ 789,
/* 785 */ 50257,
/* 786 */ 50059,
/* 787 */ -773,
/* 788 */ 3,
/* 789 */ 0,
/* 790 */ 50275,
/* 791 */ 1,
/* 792 */ 50059,
/* 793 */ -773,
/* 794 */ 4,
/* 795 */ 799,
/* 796 */ 1,
/* 797 */ -795,
/* 798 */ 1,
/* 799 */ 0,
/* 800 */ -795,
/* 801 */ 2,
/* 802 */ 0,
/* 803 */ 1,
/* 804 */ 1,
/* 805 */ -802,
/* 806 */ 1,
/* 807 */ 812,
/* 808 */ 1,
/* 809 */ 50044,
/* 810 */ -807,
/* 811 */ 1,
/* 812 */ 0,
/* 813 */ -807,
/* 814 */ 2,
/* 815 */ 819,
/* 816 */ 1,
/* 817 */ -815,
/* 818 */ 1,
/* 819 */ 0,
/* 820 */ 1,
/* 821 */ 1,
/* 822 */ 1,
/* 823 */ -815,
/* 824 */ 2,
/* 825 */ 0,
/* 826 */ 1,
/* 827 */ -825,
/* 828 */ 1,
/* 829 */ 833,
/* 830 */ 50291,
/* 831 */ -829,
/* 832 */ 1,
/* 833 */ 0,
/* 834 */ 50061,
/* 835 */ -829,
/* 836 */ 2,
/* 837 */ 0,
/* 838 */ 1,
/* 839 */ 1,
/* 840 */ -837,
/* 841 */ 1,
/* 842 */ 849,
/* 843 */ 50063,
/* 844 */ 1,
/* 845 */ 50058,
/* 846 */ 1,
/* 847 */ -842,
/* 848 */ 1,
/* 849 */ 0,
/* 850 */ -842,
/* 851 */ 2,
/* 852 */ 0,
/* 853 */ 1,
/* 854 */ -852,
/* 855 */ 1,
/* 856 */ 0,
/* 857 */ 1,
/* 858 */ 1,
/* 859 */ -856,
/* 860 */ 1,
/* 861 */ 866,
/* 862 */ 1,
/* 863 */ 50297,
/* 864 */ -861,
/* 865 */ 1,
/* 866 */ 0,
/* 867 */ -861,
/* 868 */ 2,
/* 869 */ 0,
/* 870 */ 1,
/* 871 */ 1,
/* 872 */ -869,
/* 873 */ 1,
/* 874 */ 879,
/* 875 */ 1,
/* 876 */ 50298,
/* 877 */ -874,
/* 878 */ 1,
/* 879 */ 0,
/* 880 */ -874,
/* 881 */ 2,
/* 882 */ 0,
/* 883 */ 1,
/* 884 */ 1,
/* 885 */ -882,
/* 886 */ 1,
/* 887 */ 892,
/* 888 */ 1,
/* 889 */ 50301,
/* 890 */ -887,
/* 891 */ 1,
/* 892 */ 0,
/* 893 */ -887,
/* 894 */ 2,
/* 895 */ 0,
/* 896 */ 1,
/* 897 */ 1,
/* 898 */ -895,
/* 899 */ 1,
/* 900 */ 905,
/* 901 */ 1,
/* 902 */ 50303,
/* 903 */ -900,
/* 904 */ 1,
/* 905 */ 0,
/* 906 */ -900,
/* 907 */ 2,
/* 908 */ 0,
/* 909 */ 1,
/* 910 */ 1,
/* 911 */ -908,
/* 912 */ 1,
/* 913 */ 918,
/* 914 */ 1,
/* 915 */ 50302,
/* 916 */ -913,
/* 917 */ 1,
/* 918 */ 0,
/* 919 */ -913,
/* 920 */ 2,
/* 921 */ 0,
/* 922 */ 1,
/* 923 */ 1,
/* 924 */ -921,
/* 925 */ 1,
/* 926 */ 931,
/* 927 */ 1,
/* 928 */ 50292,
/* 929 */ -926,
/* 930 */ 1,
/* 931 */ 0,
/* 932 */ -926,
/* 933 */ 2,
/* 934 */ 0,
/* 935 */ 1,
/* 936 */ 1,
/* 937 */ -934,
/* 938 */ 1,
/* 939 */ 944,
/* 940 */ 1,
/* 941 */ 50304,
/* 942 */ -939,
/* 943 */ 1,
/* 944 */ 0,
/* 945 */ -939,
/* 946 */ 2,
/* 947 */ 0,
/* 948 */ 1,
/* 949 */ 1,
/* 950 */ -947,
/* 951 */ 1,
/* 952 */ 957,
/* 953 */ 1,
/* 954 */ 1,
/* 955 */ -952,
/* 956 */ 1,
/* 957 */ 0,
/* 958 */ -952,
/* 959 */ 2,
/* 960 */ 964,
/* 961 */ 50043,
/* 962 */ -960,
/* 963 */ 1,
/* 964 */ 0,
/* 965 */ 50045,
/* 966 */ -960,
/* 967 */ 2,
/* 968 */ 0,
/* 969 */ 1,
/* 970 */ 1,
/* 971 */ -968,
/* 972 */ 1,
/* 973 */ 978,
/* 974 */ 1,
/* 975 */ 1,
/* 976 */ -973,
/* 977 */ 1,
/* 978 */ 0,
/* 979 */ -973,
/* 980 */ 2,
/* 981 */ 985,
/* 982 */ 50042,
/* 983 */ -981,
/* 984 */ 1,
/* 985 */ 989,
/* 986 */ 50047,
/* 987 */ -981,
/* 988 */ 2,
/* 989 */ 0,
/* 990 */ 50037,
/* 991 */ -981,
/* 992 */ 3,
/* 993 */ 997,
/* 994 */ 1,
/* 995 */ -993,
/* 996 */ 1,
/* 997 */ 0,
/* 998 */ 50040,
/* 999 */ 1,
/* 1000 */ 50041,
/* 1001 */ 1,
/* 1002 */ -993,
/* 1003 */ 2,
/* 1004 */ 1008,
/* 1005 */ 1,
/* 1006 */ -1004,
/* 1007 */ 1,
/* 1008 */ 1013,
/* 1009 */ 1,
/* 1010 */ 1,
/* 1011 */ -1004,
/* 1012 */ 2,
/* 1013 */ 1018,
/* 1014 */ 1,
/* 1015 */ 1,
/* 1016 */ -1004,
/* 1017 */ 3,
/* 1018 */ 1023,
/* 1019 */ 50278,
/* 1020 */ 1,
/* 1021 */ -1004,
/* 1022 */ 4,
/* 1023 */ 0,
/* 1024 */ 50278,
/* 1025 */ 50040,
/* 1026 */ 1,
/* 1027 */ 50041,
/* 1028 */ -1004,
/* 1029 */ 5,
/* 1030 */ 1034,
/* 1031 */ 50294,
/* 1032 */ -1030,
/* 1033 */ 1,
/* 1034 */ 0,
/* 1035 */ 50295,
/* 1036 */ -1030,
/* 1037 */ 2,
/* 1038 */ 0,
/* 1039 */ 1,
/* 1040 */ -1038,
/* 1041 */ 1,
/* 1042 */ 1046,
/* 1043 */ 50302,
/* 1044 */ -1042,
/* 1045 */ 1,
/* 1046 */ 1050,
/* 1047 */ 50042,
/* 1048 */ -1042,
/* 1049 */ 2,
/* 1050 */ 1054,
/* 1051 */ 50043,
/* 1052 */ -1042,
/* 1053 */ 3,
/* 1054 */ 1058,
/* 1055 */ 50045,
/* 1056 */ -1042,
/* 1057 */ 4,
/* 1058 */ 1062,
/* 1059 */ 50126,
/* 1060 */ -1042,
/* 1061 */ 5,
/* 1062 */ 0,
/* 1063 */ 50033,
/* 1064 */ -1042,
/* 1065 */ 6,
/* 1066 */ 1070,
/* 1067 */ 1,
/* 1068 */ -1066,
/* 1069 */ 1,
/* 1070 */ 0,
/* 1071 */ 1,
/* 1072 */ 1,
/* 1073 */ -1066,
/* 1074 */ 2,
/* 1075 */ 1081,
/* 1076 */ 50091,
/* 1077 */ 1,
/* 1078 */ 50093,
/* 1079 */ -1075,
/* 1080 */ 1,
/* 1081 */ 1087,
/* 1082 */ 50040,
/* 1083 */ 1,
/* 1084 */ 50041,
/* 1085 */ -1075,
/* 1086 */ 2,
/* 1087 */ 1092,
/* 1088 */ 50046,
/* 1089 */ 1,
/* 1090 */ -1075,
/* 1091 */ 3,
/* 1092 */ 1097,
/* 1093 */ 50296,
/* 1094 */ 1,
/* 1095 */ -1075,
/* 1096 */ 4,
/* 1097 */ 1101,
/* 1098 */ 50294,
/* 1099 */ -1075,
/* 1100 */ 5,
/* 1101 */ 0,
/* 1102 */ 50295,
/* 1103 */ -1075,
/* 1104 */ 6,
/* 1105 */ 1109,
/* 1106 */ 1,
/* 1107 */ -1105,
/* 1108 */ 1,
/* 1109 */ 0,
/* 1110 */ -1105,
/* 1111 */ 2,
/* 1112 */ 1116,
/* 1113 */ 1,
/* 1114 */ -1112,
/* 1115 */ 1,
/* 1116 */ 1120,
/* 1117 */ 1,
/* 1118 */ -1112,
/* 1119 */ 2,
/* 1120 */ 1124,
/* 1121 */ 50289,
/* 1122 */ -1112,
/* 1123 */ 3,
/* 1124 */ 0,
/* 1125 */ 50040,
/* 1126 */ 1,
/* 1127 */ 50041,
/* 1128 */ -1112,
/* 1129 */ 4,
/* 1130 */ 0,
/* 1131 */ 1,
/* 1132 */ 1,
/* 1133 */ -1130,
/* 1134 */ 1,
/* 1135 */ 1140,
/* 1136 */ 1,
/* 1137 */ 50044,
/* 1138 */ -1135,
/* 1139 */ 1,
/* 1140 */ 0,
/* 1141 */ -1135,
/* 1142 */ 2,
/* 1143 */ 1147,
/* 1144 */ 50308,
/* 1145 */ -1143,
/* 1146 */ 1,
/* 1147 */ 1151,
/* 1148 */ 50306,
/* 1149 */ -1143,
/* 1150 */ 2,
/* 1151 */ 1155,
/* 1152 */ 50307,
/* 1153 */ -1143,
/* 1154 */ 3,
/* 1155 */ 0,
/* 1156 */ 1,
/* 1157 */ -1143,
/* 1158 */ 4,
/* 1159 */ 0,
/* 1160 */ 50299,
/* 1161 */ -1159,
/* 1162 */ 1,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 72002,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 72002,
/* 6 */ 9999,
/* 7 */ 72004,
/* 8 */ 9999,
/* 9 */ 72004,
/* 10 */ 9999,
/* 11 */ 72006,
/* 12 */ 72025,
/* 13 */ 9999,
/* 14 */ 72025,
/* 15 */ 9999,
/* 16 */ 9999,
/* 17 */ 72025,
/* 18 */ 9999,
/* 19 */ 76004,
/* 20 */ 9999,
/* 21 */ 76022,
/* 22 */ 9999,
/* 23 */ 77004,
/* 24 */ 9999,
/* 25 */ 77014,
/* 26 */ 9999,
/* 27 */ 81004,
/* 28 */ 81032,
/* 29 */ 81043,
/* 30 */ 81065,
/* 31 */ 9999,
/* 32 */ 81004,
/* 33 */ 9999,
/* 34 */ 81006,
/* 35 */ 9999,
/* 36 */ 81027,
/* 37 */ 9999,
/* 38 */ 9999,
/* 39 */ 81027,
/* 40 */ 9999,
/* 41 */ 81045,
/* 42 */ 9999,
/* 43 */ 81060,
/* 44 */ 9999,
/* 45 */ 9999,
/* 46 */ 81060,
/* 47 */ 9999,
/* 48 */ 85004,
/* 49 */ 85027,
/* 50 */ 9999,
/* 51 */ 9999,
/* 52 */ 85025,
/* 53 */ 9999,
/* 54 */ 85029,
/* 55 */ 9999,
/* 56 */ 85048,
/* 57 */ 9999,
/* 58 */ 9999,
/* 59 */ 85048,
/* 60 */ 9999,
/* 61 */ 89004,
/* 62 */ 89026,
/* 63 */ 9999,
/* 64 */ 89004,
/* 65 */ 9999,
/* 66 */ 89006,
/* 67 */ 9999,
/* 68 */ 89021,
/* 69 */ 9999,
/* 70 */ 9999,
/* 71 */ 89021,
/* 72 */ 9999,
/* 73 */ 93004,
/* 74 */ 93066,
/* 75 */ 9999,
/* 76 */ 93004,
/* 77 */ 9999,
/* 78 */ 93006,
/* 79 */ 9999,
/* 80 */ 93028,
/* 81 */ 9999,
/* 82 */ 93032,
/* 83 */ 9999,
/* 84 */ 93045,
/* 85 */ 9999,
/* 86 */ 93049,
/* 87 */ 9999,
/* 88 */ 93062,
/* 89 */ 9999,
/* 90 */ 93068,
/* 91 */ 9999,
/* 92 */ 93089,
/* 93 */ 9999,
/* 94 */ 9999,
/* 95 */ 93089,
/* 96 */ 9999,
/* 97 */ 97004,
/* 98 */ 9999,
/* 99 */ 97004,
/* 100 */ 9999,
/* 101 */ 9999,
/* 102 */ 9999,
/* 103 */ 97009,
/* 104 */ 9999,
/* 105 */ 9999,
/* 106 */ 9999,
/* 107 */ 98011,
/* 108 */ 9999,
/* 109 */ 9999,
/* 110 */ 9999,
/* 111 */ 99009,
/* 112 */ 9999,
/* 113 */ 9999,
/* 114 */ 9999,
/* 115 */ 100009,
/* 116 */ 9999,
/* 117 */ 9999,
/* 118 */ 9999,
/* 119 */ 101010,
/* 120 */ 9999,
/* 121 */ 105004,
/* 122 */ 9999,
/* 123 */ 105004,
/* 124 */ 9999,
/* 125 */ 114004,
/* 126 */ 9999,
/* 127 */ 114028,
/* 128 */ 9999,
/* 129 */ 114032,
/* 130 */ 9999,
/* 131 */ 114045,
/* 132 */ 9999,
/* 133 */ 9999,
/* 134 */ 9999,
/* 135 */ 105009,
/* 136 */ 9999,
/* 137 */ 9999,
/* 138 */ 9999,
/* 139 */ 106007,
/* 140 */ 9999,
/* 141 */ 9999,
/* 142 */ 9999,
/* 143 */ 107008,
/* 144 */ 9999,
/* 145 */ 9999,
/* 146 */ 9999,
/* 147 */ 108006,
/* 148 */ 9999,
/* 149 */ 9999,
/* 150 */ 9999,
/* 151 */ 109007,
/* 152 */ 9999,
/* 153 */ 9999,
/* 154 */ 9999,
/* 155 */ 110008,
/* 156 */ 9999,
/* 157 */ 9999,
/* 158 */ 9999,
/* 159 */ 111009,
/* 160 */ 9999,
/* 161 */ 9999,
/* 162 */ 9999,
/* 163 */ 112009,
/* 164 */ 9999,
/* 165 */ 9999,
/* 166 */ 9999,
/* 167 */ 113011,
/* 168 */ 9999,
/* 169 */ 118004,
/* 170 */ 9999,
/* 171 */ 118004,
/* 172 */ 9999,
/* 173 */ 9999,
/* 174 */ 9999,
/* 175 */ 118010,
/* 176 */ 9999,
/* 177 */ 9999,
/* 178 */ 9999,
/* 179 */ 119011,
/* 180 */ 9999,
/* 181 */ 123004,
/* 182 */ 123020,
/* 183 */ 9999,
/* 184 */ 123059,
/* 185 */ 9999,
/* 186 */ 9999,
/* 187 */ 123018,
/* 188 */ 9999,
/* 189 */ 124004,
/* 190 */ 124020,
/* 191 */ 9999,
/* 192 */ 124018,
/* 193 */ 9999,
/* 194 */ 123022,
/* 195 */ 9999,
/* 196 */ 123023,
/* 197 */ 9999,
/* 198 */ 9999,
/* 199 */ 123023,
/* 200 */ 9999,
/* 201 */ 128004,
/* 202 */ 9999,
/* 203 */ 128004,
/* 204 */ 9999,
/* 205 */ 9999,
/* 206 */ 9999,
/* 207 */ 128011,
/* 208 */ 9999,
/* 209 */ 9999,
/* 210 */ 9999,
/* 211 */ 128019,
/* 212 */ 9999,
/* 213 */ 132004,
/* 214 */ 132033,
/* 215 */ 9999,
/* 216 */ 132004,
/* 217 */ 9999,
/* 218 */ 132006,
/* 219 */ 9999,
/* 220 */ 132028,
/* 221 */ 9999,
/* 222 */ 9999,
/* 223 */ 132028,
/* 224 */ 9999,
/* 225 */ 136004,
/* 226 */ 136045,
/* 227 */ 9999,
/* 228 */ 136004,
/* 229 */ 9999,
/* 230 */ 136006,
/* 231 */ 9999,
/* 232 */ 9999,
/* 233 */ 136025,
/* 234 */ 9999,
/* 235 */ 9999,
/* 236 */ 136025,
/* 237 */ 9999,
/* 238 */ 140004,
/* 239 */ 140034,
/* 240 */ 9999,
/* 241 */ 140004,
/* 242 */ 9999,
/* 243 */ 140006,
/* 244 */ 9999,
/* 245 */ 9999,
/* 246 */ 140015,
/* 247 */ 9999,
/* 248 */ 9999,
/* 249 */ 140015,
/* 250 */ 9999,
/* 251 */ 144004,
/* 252 */ 144029,
/* 253 */ 9999,
/* 254 */ 9999,
/* 255 */ 144027,
/* 256 */ 9999,
/* 257 */ 148004,
/* 258 */ 148040,
/* 259 */ 9999,
/* 260 */ 148004,
/* 261 */ 9999,
/* 262 */ 148006,
/* 263 */ 9999,
/* 264 */ 148019,
/* 265 */ 9999,
/* 266 */ 148023,
/* 267 */ 9999,
/* 268 */ 148036,
/* 269 */ 9999,
/* 270 */ 148042,
/* 271 */ 9999,
/* 272 */ 148065,
/* 273 */ 9999,
/* 274 */ 9999,
/* 275 */ 148065,
/* 276 */ 9999,
/* 277 */ 152004,
/* 278 */ 152047,
/* 279 */ 9999,
/* 280 */ 152004,
/* 281 */ 9999,
/* 282 */ 152006,
/* 283 */ 9999,
/* 284 */ 9999,
/* 285 */ 152027,
/* 286 */ 9999,
/* 287 */ 9999,
/* 288 */ 152027,
/* 289 */ 9999,
/* 290 */ 156004,
/* 291 */ 9999,
/* 292 */ 156013,
/* 293 */ 9999,
/* 294 */ 157004,
/* 295 */ 9999,
/* 296 */ 157034,
/* 297 */ 9999,
/* 298 */ 157004,
/* 299 */ 9999,
/* 300 */ 157006,
/* 301 */ 9999,
/* 302 */ 157015,
/* 303 */ 9999,
/* 304 */ 9999,
/* 305 */ 157015,
/* 306 */ 9999,
/* 307 */ 9999,
/* 308 */ 161009,
/* 309 */ 9999,
/* 310 */ 161048,
/* 311 */ 9999,
/* 312 */ 9999,
/* 313 */ 161007,
/* 314 */ 9999,
/* 315 */ 9999,
/* 316 */ 162009,
/* 317 */ 9999,
/* 318 */ 162007,
/* 319 */ 9999,
/* 320 */ 161011,
/* 321 */ 9999,
/* 322 */ 161012,
/* 323 */ 9999,
/* 324 */ 9999,
/* 325 */ 161012,
/* 326 */ 9999,
/* 327 */ 166004,
/* 328 */ 166040,
/* 329 */ 9999,
/* 330 */ 166004,
/* 331 */ 9999,
/* 332 */ 166006,
/* 333 */ 9999,
/* 334 */ 9999,
/* 335 */ 166020,
/* 336 */ 9999,
/* 337 */ 9999,
/* 338 */ 166020,
/* 339 */ 9999,
/* 340 */ 170004,
/* 341 */ 170007,
/* 342 */ 9999,
/* 343 */ 170005,
/* 344 */ 9999,
/* 345 */ 9999,
/* 346 */ 170023,
/* 347 */ 9999,
/* 348 */ 170009,
/* 349 */ 9999,
/* 350 */ 9999,
/* 351 */ 170009,
/* 352 */ 9999,
/* 353 */ 174004,
/* 354 */ 174017,
/* 355 */ 9999,
/* 356 */ 174004,
/* 357 */ 9999,
/* 358 */ 174006,
/* 359 */ 9999,
/* 360 */ 174012,
/* 361 */ 9999,
/* 362 */ 9999,
/* 363 */ 174012,
/* 364 */ 9999,
/* 365 */ 178004,
/* 366 */ 9999,
/* 367 */ 178005,
/* 368 */ 9999,
/* 369 */ 9999,
/* 370 */ 179018,
/* 371 */ 9999,
/* 372 */ 9999,
/* 373 */ 179004,
/* 374 */ 9999,
/* 375 */ 180004,
/* 376 */ 180022,
/* 377 */ 9999,
/* 378 */ 180020,
/* 379 */ 9999,
/* 380 */ 9999,
/* 381 */ 180038,
/* 382 */ 9999,
/* 383 */ 9999,
/* 384 */ 180024,
/* 385 */ 9999,
/* 386 */ 9999,
/* 387 */ 180093,
/* 388 */ 9999,
/* 389 */ 9999,
/* 390 */ 180079,
/* 391 */ 9999,
/* 392 */ 9999,
/* 393 */ 180143,
/* 394 */ 9999,
/* 395 */ 9999,
/* 396 */ 180129,
/* 397 */ 9999,
/* 398 */ 180040,
/* 399 */ 9999,
/* 400 */ 180058,
/* 401 */ 9999,
/* 402 */ 9999,
/* 403 */ 180058,
/* 404 */ 9999,
/* 405 */ 180145,
/* 406 */ 9999,
/* 407 */ 180159,
/* 408 */ 9999,
/* 409 */ 9999,
/* 410 */ 180159,
/* 411 */ 9999,
/* 412 */ 9999,
/* 413 */ 184018,
/* 414 */ 184043,
/* 415 */ 9999,
/* 416 */ 184004,
/* 417 */ 9999,
/* 418 */ 184020,
/* 419 */ 9999,
/* 420 */ 184038,
/* 421 */ 9999,
/* 422 */ 9999,
/* 423 */ 184038,
/* 424 */ 9999,
/* 425 */ 184045,
/* 426 */ 9999,
/* 427 */ 184051,
/* 428 */ 9999,
/* 429 */ 9999,
/* 430 */ 184051,
/* 431 */ 9999,
/* 432 */ 188004,
/* 433 */ 188029,
/* 434 */ 9999,
/* 435 */ 188004,
/* 436 */ 9999,
/* 437 */ 188006,
/* 438 */ 9999,
/* 439 */ 188024,
/* 440 */ 9999,
/* 441 */ 9999,
/* 442 */ 188024,
/* 443 */ 9999,
/* 444 */ 192004,
/* 445 */ 192019,
/* 446 */ 9999,
/* 447 */ 192017,
/* 448 */ 9999,
/* 449 */ 9999,
/* 450 */ 9999,
/* 451 */ 9999,
/* 452 */ 192021,
/* 453 */ 9999,
/* 454 */ 9999,
/* 455 */ 192021,
/* 456 */ 9999,
/* 457 */ 196004,
/* 458 */ 196039,
/* 459 */ 9999,
/* 460 */ 196004,
/* 461 */ 9999,
/* 462 */ 196006,
/* 463 */ 9999,
/* 464 */ 9999,
/* 465 */ 196019,
/* 466 */ 9999,
/* 467 */ 9999,
/* 468 */ 196019,
/* 469 */ 9999,
/* 470 */ 200004,
/* 471 */ 200027,
/* 472 */ 9999,
/* 473 */ 200025,
/* 474 */ 9999,
/* 475 */ 200029,
/* 476 */ 9999,
/* 477 */ 200038,
/* 478 */ 9999,
/* 479 */ 200042,
/* 480 */ 9999,
/* 481 */ 200042,
/* 482 */ 9999,
/* 483 */ 200044,
/* 484 */ 9999,
/* 485 */ 200062,
/* 486 */ 9999,
/* 487 */ 9999,
/* 488 */ 200062,
/* 489 */ 9999,
/* 490 */ 204004,
/* 491 */ 204040,
/* 492 */ 9999,
/* 493 */ 204004,
/* 494 */ 9999,
/* 495 */ 204006,
/* 496 */ 9999,
/* 497 */ 9999,
/* 498 */ 204020,
/* 499 */ 9999,
/* 500 */ 9999,
/* 501 */ 204020,
/* 502 */ 9999,
/* 503 */ 208004,
/* 504 */ 9999,
/* 505 */ 208024,
/* 506 */ 9999,
/* 507 */ 9999,
/* 508 */ 209029,
/* 509 */ 209046,
/* 510 */ 9999,
/* 511 */ 9999,
/* 512 */ 209004,
/* 513 */ 9999,
/* 514 */ 9999,
/* 515 */ 9999,
/* 516 */ 209048,
/* 517 */ 9999,
/* 518 */ 9999,
/* 519 */ 209048,
/* 520 */ 9999,
/* 521 */ 213004,
/* 522 */ 213041,
/* 523 */ 9999,
/* 524 */ 213004,
/* 525 */ 9999,
/* 526 */ 213006,
/* 527 */ 9999,
/* 528 */ 9999,
/* 529 */ 213021,
/* 530 */ 9999,
/* 531 */ 9999,
/* 532 */ 213021,
/* 533 */ 9999,
/* 534 */ 217004,
/* 535 */ 217029,
/* 536 */ 9999,
/* 537 */ 217027,
/* 538 */ 9999,
/* 539 */ 217031,
/* 540 */ 9999,
/* 541 */ 217049,
/* 542 */ 9999,
/* 543 */ 9999,
/* 544 */ 217049,
/* 545 */ 9999,
/* 546 */ 221004,
/* 547 */ 9999,
/* 548 */ 221010,
/* 549 */ 9999,
/* 550 */ 222004,
/* 551 */ 222017,
/* 552 */ 9999,
/* 553 */ 222004,
/* 554 */ 9999,
/* 555 */ 222006,
/* 556 */ 9999,
/* 557 */ 222012,
/* 558 */ 9999,
/* 559 */ 9999,
/* 560 */ 222012,
/* 561 */ 9999,
/* 562 */ 9999,
/* 563 */ 226018,
/* 564 */ 9999,
/* 565 */ 9999,
/* 566 */ 226004,
/* 567 */ 9999,
/* 568 */ 227004,
/* 569 */ 227036,
/* 570 */ 9999,
/* 571 */ 227004,
/* 572 */ 9999,
/* 573 */ 227006,
/* 574 */ 9999,
/* 575 */ 227031,
/* 576 */ 9999,
/* 577 */ 9999,
/* 578 */ 227031,
/* 579 */ 9999,
/* 580 */ 9999,
/* 581 */ 227052,
/* 582 */ 9999,
/* 583 */ 9999,
/* 584 */ 227038,
/* 585 */ 9999,
/* 586 */ 9999,
/* 587 */ 227107,
/* 588 */ 9999,
/* 589 */ 9999,
/* 590 */ 227093,
/* 591 */ 9999,
/* 592 */ 227054,
/* 593 */ 9999,
/* 594 */ 227072,
/* 595 */ 9999,
/* 596 */ 9999,
/* 597 */ 227072,
/* 598 */ 9999,
/* 599 */ 227109,
/* 600 */ 9999,
/* 601 */ 227127,
/* 602 */ 9999,
/* 603 */ 9999,
/* 604 */ 227127,
/* 605 */ 9999,
/* 606 */ 231004,
/* 607 */ 9999,
/* 608 */ 231005,
/* 609 */ 9999,
/* 610 */ 235004,
/* 611 */ 9999,
/* 612 */ 235020,
/* 613 */ 9999,
/* 614 */ 236004,
/* 615 */ 9999,
/* 616 */ 236023,
/* 617 */ 9999,
/* 618 */ 237004,
/* 619 */ 9999,
/* 620 */ 237021,
/* 621 */ 9999,
/* 622 */ 238004,
/* 623 */ 9999,
/* 624 */ 238022,
/* 625 */ 9999,
/* 626 */ 239004,
/* 627 */ 9999,
/* 628 */ 239022,
/* 629 */ 9999,
/* 630 */ 240004,
/* 631 */ 9999,
/* 632 */ 240017,
/* 633 */ 9999,
/* 634 */ 244004,
/* 635 */ 9999,
/* 636 */ 244021,
/* 637 */ 9999,
/* 638 */ 244005,
/* 639 */ 9999,
/* 640 */ 9999,
/* 641 */ 245019,
/* 642 */ 9999,
/* 643 */ 245053,
/* 644 */ 9999,
/* 645 */ 245007,
/* 646 */ 9999,
/* 647 */ 9999,
/* 648 */ 9999,
/* 649 */ 246036,
/* 650 */ 9999,
/* 651 */ 246010,
/* 652 */ 9999,
/* 653 */ 250004,
/* 654 */ 9999,
/* 655 */ 9999,
/* 656 */ 250004,
/* 657 */ 9999,
/* 658 */ 250006,
/* 659 */ 9999,
/* 660 */ 250015,
/* 661 */ 9999,
/* 662 */ 9999,
/* 663 */ 250015,
/* 664 */ 9999,
/* 665 */ 9999,
/* 666 */ 254038,
/* 667 */ 254060,
/* 668 */ 9999,
/* 669 */ 9999,
/* 670 */ 254004,
/* 671 */ 9999,
/* 672 */ 254040,
/* 673 */ 9999,
/* 674 */ 254055,
/* 675 */ 9999,
/* 676 */ 9999,
/* 677 */ 254055,
/* 678 */ 9999,
/* 679 */ 254062,
/* 680 */ 9999,
/* 681 */ 254075,
/* 682 */ 9999,
/* 683 */ 9999,
/* 684 */ 254075,
/* 685 */ 9999,
/* 686 */ 258004,
/* 687 */ 258024,
/* 688 */ 9999,
/* 689 */ 258004,
/* 690 */ 9999,
/* 691 */ 258006,
/* 692 */ 9999,
/* 693 */ 258019,
/* 694 */ 9999,
/* 695 */ 9999,
/* 696 */ 258019,
/* 697 */ 9999,
/* 698 */ 9999,
/* 699 */ 9999,
/* 700 */ 262031,
/* 701 */ 9999,
/* 702 */ 262056,
/* 703 */ 262066,
/* 704 */ 9999,
/* 705 */ 262005,
/* 706 */ 9999,
/* 707 */ 9999,
/* 708 */ 9999,
/* 709 */ 263035,
/* 710 */ 9999,
/* 711 */ 263060,
/* 712 */ 9999,
/* 713 */ 263009,
/* 714 */ 9999,
/* 715 */ 9999,
/* 716 */ 262083,
/* 717 */ 9999,
/* 718 */ 262071,
/* 719 */ 9999,
/* 720 */ 9999,
/* 721 */ 262071,
/* 722 */ 9999,
/* 723 */ 9999,
/* 724 */ 9999,
/* 725 */ 267034,
/* 726 */ 9999,
/* 727 */ 267059,
/* 728 */ 9999,
/* 729 */ 267008,
/* 730 */ 9999,
/* 731 */ 9999,
/* 732 */ 268017,
/* 733 */ 9999,
/* 734 */ 9999,
/* 735 */ 268057,
/* 736 */ 9999,
/* 737 */ 9999,
/* 738 */ 9999,
/* 739 */ 268005,
/* 740 */ 9999,
/* 741 */ 9999,
/* 742 */ 9999,
/* 743 */ 269032,
/* 744 */ 9999,
/* 745 */ 269062,
/* 746 */ 9999,
/* 747 */ 269092,
/* 748 */ 9999,
/* 749 */ 269122,
/* 750 */ 9999,
/* 751 */ 269006,
/* 752 */ 9999,
/* 753 */ 269034,
/* 754 */ 9999,
/* 755 */ 269043,
/* 756 */ 9999,
/* 757 */ 9999,
/* 758 */ 269043,
/* 759 */ 9999,
/* 760 */ 269064,
/* 761 */ 9999,
/* 762 */ 269073,
/* 763 */ 9999,
/* 764 */ 9999,
/* 765 */ 269073,
/* 766 */ 9999,
/* 767 */ 269094,
/* 768 */ 9999,
/* 769 */ 269103,
/* 770 */ 9999,
/* 771 */ 9999,
/* 772 */ 269103,
/* 773 */ 9999,
/* 774 */ 9999,
/* 775 */ 273019,
/* 776 */ 9999,
/* 777 */ 9999,
/* 778 */ 273007,
/* 779 */ 9999,
/* 780 */ 9999,
/* 781 */ 9999,
/* 782 */ 9999,
/* 783 */ 274011,
/* 784 */ 9999,
/* 785 */ 9999,
/* 786 */ 9999,
/* 787 */ 9999,
/* 788 */ 275008,
/* 789 */ 9999,
/* 790 */ 9999,
/* 791 */ 276021,
/* 792 */ 9999,
/* 793 */ 9999,
/* 794 */ 276009,
/* 795 */ 9999,
/* 796 */ 276023,
/* 797 */ 9999,
/* 798 */ 276032,
/* 799 */ 9999,
/* 800 */ 9999,
/* 801 */ 276032,
/* 802 */ 9999,
/* 803 */ 280004,
/* 804 */ 280035,
/* 805 */ 9999,
/* 806 */ 280004,
/* 807 */ 9999,
/* 808 */ 280006,
/* 809 */ 9999,
/* 810 */ 9999,
/* 811 */ 280015,
/* 812 */ 9999,
/* 813 */ 9999,
/* 814 */ 280015,
/* 815 */ 9999,
/* 816 */ 284004,
/* 817 */ 9999,
/* 818 */ 284025,
/* 819 */ 9999,
/* 820 */ 285004,
/* 821 */ 285021,
/* 822 */ 285041,
/* 823 */ 9999,
/* 824 */ 285019,
/* 825 */ 9999,
/* 826 */ 289004,
/* 827 */ 9999,
/* 828 */ 289004,
/* 829 */ 9999,
/* 830 */ 9999,
/* 831 */ 9999,
/* 832 */ 289011,
/* 833 */ 9999,
/* 834 */ 9999,
/* 835 */ 9999,
/* 836 */ 290004,
/* 837 */ 9999,
/* 838 */ 294004,
/* 839 */ 294026,
/* 840 */ 9999,
/* 841 */ 294024,
/* 842 */ 9999,
/* 843 */ 9999,
/* 844 */ 294042,
/* 845 */ 9999,
/* 846 */ 294067,
/* 847 */ 9999,
/* 848 */ 294028,
/* 849 */ 9999,
/* 850 */ 9999,
/* 851 */ 294028,
/* 852 */ 9999,
/* 853 */ 298004,
/* 854 */ 9999,
/* 855 */ 298025,
/* 856 */ 9999,
/* 857 */ 302004,
/* 858 */ 302042,
/* 859 */ 9999,
/* 860 */ 302004,
/* 861 */ 9999,
/* 862 */ 302006,
/* 863 */ 9999,
/* 864 */ 9999,
/* 865 */ 302026,
/* 866 */ 9999,
/* 867 */ 9999,
/* 868 */ 302026,
/* 869 */ 9999,
/* 870 */ 306004,
/* 871 */ 306044,
/* 872 */ 9999,
/* 873 */ 306004,
/* 874 */ 9999,
/* 875 */ 306006,
/* 876 */ 9999,
/* 877 */ 9999,
/* 878 */ 306027,
/* 879 */ 9999,
/* 880 */ 9999,
/* 881 */ 306027,
/* 882 */ 9999,
/* 883 */ 310004,
/* 884 */ 310040,
/* 885 */ 9999,
/* 886 */ 310004,
/* 887 */ 9999,
/* 888 */ 310006,
/* 889 */ 9999,
/* 890 */ 9999,
/* 891 */ 310028,
/* 892 */ 9999,
/* 893 */ 9999,
/* 894 */ 310028,
/* 895 */ 9999,
/* 896 */ 314004,
/* 897 */ 314041,
/* 898 */ 9999,
/* 899 */ 314004,
/* 900 */ 9999,
/* 901 */ 314006,
/* 902 */ 9999,
/* 903 */ 9999,
/* 904 */ 314028,
/* 905 */ 9999,
/* 906 */ 9999,
/* 907 */ 314028,
/* 908 */ 9999,
/* 909 */ 318004,
/* 910 */ 318031,
/* 911 */ 9999,
/* 912 */ 318004,
/* 913 */ 9999,
/* 914 */ 318005,
/* 915 */ 9999,
/* 916 */ 9999,
/* 917 */ 318018,
/* 918 */ 9999,
/* 919 */ 9999,
/* 920 */ 318018,
/* 921 */ 9999,
/* 922 */ 322004,
/* 923 */ 322075,
/* 924 */ 9999,
/* 925 */ 322004,
/* 926 */ 9999,
/* 927 */ 322006,
/* 928 */ 9999,
/* 929 */ 9999,
/* 930 */ 322024,
/* 931 */ 9999,
/* 932 */ 9999,
/* 933 */ 322024,
/* 934 */ 9999,
/* 935 */ 326004,
/* 936 */ 326031,
/* 937 */ 9999,
/* 938 */ 326004,
/* 939 */ 9999,
/* 940 */ 326005,
/* 941 */ 9999,
/* 942 */ 9999,
/* 943 */ 326020,
/* 944 */ 9999,
/* 945 */ 9999,
/* 946 */ 326020,
/* 947 */ 9999,
/* 948 */ 330004,
/* 949 */ 330053,
/* 950 */ 9999,
/* 951 */ 330004,
/* 952 */ 9999,
/* 953 */ 330006,
/* 954 */ 330026,
/* 955 */ 9999,
/* 956 */ 330024,
/* 957 */ 9999,
/* 958 */ 9999,
/* 959 */ 330024,
/* 960 */ 9999,
/* 961 */ 9999,
/* 962 */ 9999,
/* 963 */ 330028,
/* 964 */ 9999,
/* 965 */ 9999,
/* 966 */ 9999,
/* 967 */ 330034,
/* 968 */ 9999,
/* 969 */ 334004,
/* 970 */ 334065,
/* 971 */ 9999,
/* 972 */ 334004,
/* 973 */ 9999,
/* 974 */ 334006,
/* 975 */ 334032,
/* 976 */ 9999,
/* 977 */ 334030,
/* 978 */ 9999,
/* 979 */ 9999,
/* 980 */ 334030,
/* 981 */ 9999,
/* 982 */ 9999,
/* 983 */ 9999,
/* 984 */ 334034,
/* 985 */ 9999,
/* 986 */ 9999,
/* 987 */ 9999,
/* 988 */ 334040,
/* 989 */ 9999,
/* 990 */ 9999,
/* 991 */ 9999,
/* 992 */ 334046,
/* 993 */ 9999,
/* 994 */ 338004,
/* 995 */ 9999,
/* 996 */ 338019,
/* 997 */ 9999,
/* 998 */ 9999,
/* 999 */ 339018,
/* 1000 */ 9999,
/* 1001 */ 339042,
/* 1002 */ 9999,
/* 1003 */ 339004,
/* 1004 */ 9999,
/* 1005 */ 343004,
/* 1006 */ 9999,
/* 1007 */ 343021,
/* 1008 */ 9999,
/* 1009 */ 344004,
/* 1010 */ 344024,
/* 1011 */ 9999,
/* 1012 */ 344004,
/* 1013 */ 9999,
/* 1014 */ 345004,
/* 1015 */ 345019,
/* 1016 */ 9999,
/* 1017 */ 345017,
/* 1018 */ 9999,
/* 1019 */ 9999,
/* 1020 */ 346011,
/* 1021 */ 9999,
/* 1022 */ 346009,
/* 1023 */ 9999,
/* 1024 */ 9999,
/* 1025 */ 9999,
/* 1026 */ 347025,
/* 1027 */ 9999,
/* 1028 */ 9999,
/* 1029 */ 347009,
/* 1030 */ 9999,
/* 1031 */ 9999,
/* 1032 */ 9999,
/* 1033 */ 344011,
/* 1034 */ 9999,
/* 1035 */ 9999,
/* 1036 */ 9999,
/* 1037 */ 344020,
/* 1038 */ 9999,
/* 1039 */ 351004,
/* 1040 */ 9999,
/* 1041 */ 351004,
/* 1042 */ 9999,
/* 1043 */ 9999,
/* 1044 */ 9999,
/* 1045 */ 351011,
/* 1046 */ 9999,
/* 1047 */ 9999,
/* 1048 */ 9999,
/* 1049 */ 351015,
/* 1050 */ 9999,
/* 1051 */ 9999,
/* 1052 */ 9999,
/* 1053 */ 351021,
/* 1054 */ 9999,
/* 1055 */ 9999,
/* 1056 */ 9999,
/* 1057 */ 351027,
/* 1058 */ 9999,
/* 1059 */ 9999,
/* 1060 */ 9999,
/* 1061 */ 351033,
/* 1062 */ 9999,
/* 1063 */ 9999,
/* 1064 */ 9999,
/* 1065 */ 351039,
/* 1066 */ 9999,
/* 1067 */ 355004,
/* 1068 */ 9999,
/* 1069 */ 355021,
/* 1070 */ 9999,
/* 1071 */ 356004,
/* 1072 */ 356023,
/* 1073 */ 9999,
/* 1074 */ 356021,
/* 1075 */ 9999,
/* 1076 */ 9999,
/* 1077 */ 356039,
/* 1078 */ 9999,
/* 1079 */ 9999,
/* 1080 */ 356025,
/* 1081 */ 9999,
/* 1082 */ 9999,
/* 1083 */ 356080,
/* 1084 */ 9999,
/* 1085 */ 9999,
/* 1086 */ 356066,
/* 1087 */ 9999,
/* 1088 */ 9999,
/* 1089 */ 356140,
/* 1090 */ 9999,
/* 1091 */ 356126,
/* 1092 */ 9999,
/* 1093 */ 9999,
/* 1094 */ 356172,
/* 1095 */ 9999,
/* 1096 */ 356150,
/* 1097 */ 9999,
/* 1098 */ 9999,
/* 1099 */ 9999,
/* 1100 */ 356182,
/* 1101 */ 9999,
/* 1102 */ 9999,
/* 1103 */ 9999,
/* 1104 */ 356211,
/* 1105 */ 9999,
/* 1106 */ 356082,
/* 1107 */ 9999,
/* 1108 */ 356105,
/* 1109 */ 9999,
/* 1110 */ 9999,
/* 1111 */ 356105,
/* 1112 */ 9999,
/* 1113 */ 360004,
/* 1114 */ 9999,
/* 1115 */ 360005,
/* 1116 */ 9999,
/* 1117 */ 361004,
/* 1118 */ 9999,
/* 1119 */ 361011,
/* 1120 */ 9999,
/* 1121 */ 9999,
/* 1122 */ 9999,
/* 1123 */ 362009,
/* 1124 */ 9999,
/* 1125 */ 9999,
/* 1126 */ 363018,
/* 1127 */ 9999,
/* 1128 */ 9999,
/* 1129 */ 363004,
/* 1130 */ 9999,
/* 1131 */ 367004,
/* 1132 */ 367049,
/* 1133 */ 9999,
/* 1134 */ 367004,
/* 1135 */ 9999,
/* 1136 */ 367006,
/* 1137 */ 9999,
/* 1138 */ 9999,
/* 1139 */ 367029,
/* 1140 */ 9999,
/* 1141 */ 9999,
/* 1142 */ 367029,
/* 1143 */ 9999,
/* 1144 */ 9999,
/* 1145 */ 9999,
/* 1146 */ 371011,
/* 1147 */ 9999,
/* 1148 */ 9999,
/* 1149 */ 9999,
/* 1150 */ 372012,
/* 1151 */ 9999,
/* 1152 */ 9999,
/* 1153 */ 9999,
/* 1154 */ 373013,
/* 1155 */ 9999,
/* 1156 */ 374004,
/* 1157 */ 9999,
/* 1158 */ 374005,
/* 1159 */ 9999,
/* 1160 */ 9999,
/* 1161 */ 9999,
/* 1162 */ 378013,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[1164];
*/
int TABLE[265][309];
init_dirsets() {
TABLE[103][0] = 1;
TABLE[103][123] = 1;
TABLE[103][40] = 1;
TABLE[103][42] = 1;
TABLE[103][299] = 1;
TABLE[103][286] = 1;
TABLE[103][260] = 1;
TABLE[103][284] = 1;
TABLE[103][277] = 1;
TABLE[103][264] = 1;
TABLE[103][268] = 1;
TABLE[103][273] = 1;
TABLE[103][272] = 1;
TABLE[103][276] = 1;
TABLE[103][259] = 1;
TABLE[103][285] = 1;
TABLE[103][266] = 1;
TABLE[103][282] = 1;
TABLE[103][267] = 1;
TABLE[103][279] = 1;
TABLE[103][274] = 1;
TABLE[103][256] = 1;
TABLE[103][283] = 1;
TABLE[103][280] = 1;
TABLE[1][0] = 1;
TABLE[1][123] = 1;
TABLE[1][40] = 1;
TABLE[1][299] = 1;
TABLE[1][42] = 1;
TABLE[1][256] = 1;
TABLE[1][274] = 1;
TABLE[1][279] = 1;
TABLE[1][267] = 1;
TABLE[1][282] = 1;
TABLE[1][266] = 1;
TABLE[1][285] = 1;
TABLE[1][259] = 1;
TABLE[1][276] = 1;
TABLE[1][272] = 1;
TABLE[1][273] = 1;
TABLE[1][268] = 1;
TABLE[1][264] = 1;
TABLE[1][277] = 1;
TABLE[1][284] = 1;
TABLE[1][260] = 1;
TABLE[1][286] = 1;
TABLE[1][280] = 1;
TABLE[1][283] = 1;
TABLE[104][0] = 1;
TABLE[104][123] = 1;
TABLE[104][40] = 1;
TABLE[104][42] = 1;
TABLE[104][299] = 1;
TABLE[104][286] = 1;
TABLE[104][260] = 1;
TABLE[104][284] = 1;
TABLE[104][277] = 1;
TABLE[104][264] = 1;
TABLE[104][268] = 1;
TABLE[104][273] = 1;
TABLE[104][272] = 1;
TABLE[104][276] = 1;
TABLE[104][259] = 1;
TABLE[104][285] = 1;
TABLE[104][266] = 1;
TABLE[104][282] = 1;
TABLE[104][267] = 1;
TABLE[104][279] = 1;
TABLE[104][274] = 1;
TABLE[104][256] = 1;
TABLE[104][283] = 1;
TABLE[104][280] = 1;
TABLE[210][0] = 1;
TABLE[2][0] = 1;
TABLE[2][123] = 1;
TABLE[2][40] = 1;
TABLE[2][299] = 1;
TABLE[2][42] = 1;
TABLE[2][286] = 1;
TABLE[2][260] = 1;
TABLE[2][284] = 1;
TABLE[2][277] = 1;
TABLE[2][264] = 1;
TABLE[2][268] = 1;
TABLE[2][273] = 1;
TABLE[2][272] = 1;
TABLE[2][276] = 1;
TABLE[2][259] = 1;
TABLE[2][285] = 1;
TABLE[2][266] = 1;
TABLE[2][282] = 1;
TABLE[2][267] = 1;
TABLE[2][279] = 1;
TABLE[2][274] = 1;
TABLE[2][256] = 1;
TABLE[2][283] = 1;
TABLE[2][280] = 1;
TABLE[3][256] = 1;
TABLE[3][274] = 1;
TABLE[3][279] = 1;
TABLE[3][267] = 1;
TABLE[3][282] = 1;
TABLE[3][266] = 1;
TABLE[3][285] = 1;
TABLE[3][259] = 1;
TABLE[3][276] = 1;
TABLE[3][272] = 1;
TABLE[3][273] = 1;
TABLE[3][268] = 1;
TABLE[3][264] = 1;
TABLE[3][277] = 1;
TABLE[3][284] = 1;
TABLE[3][260] = 1;
TABLE[3][286] = 1;
TABLE[3][280] = 1;
TABLE[3][283] = 1;
TABLE[4][123] = 1;
TABLE[4][40] = 1;
TABLE[4][42] = 1;
TABLE[4][299] = 1;
TABLE[4][256] = 1;
TABLE[4][274] = 1;
TABLE[4][279] = 1;
TABLE[4][267] = 1;
TABLE[4][282] = 1;
TABLE[4][266] = 1;
TABLE[4][285] = 1;
TABLE[4][259] = 1;
TABLE[4][276] = 1;
TABLE[4][272] = 1;
TABLE[4][273] = 1;
TABLE[4][268] = 1;
TABLE[4][264] = 1;
TABLE[4][277] = 1;
TABLE[4][284] = 1;
TABLE[4][260] = 1;
TABLE[4][286] = 1;
TABLE[4][280] = 1;
TABLE[4][283] = 1;
TABLE[105][286] = 1;
TABLE[105][260] = 1;
TABLE[105][284] = 1;
TABLE[105][277] = 1;
TABLE[105][264] = 1;
TABLE[105][268] = 1;
TABLE[105][273] = 1;
TABLE[105][272] = 1;
TABLE[105][276] = 1;
TABLE[105][259] = 1;
TABLE[105][285] = 1;
TABLE[105][266] = 1;
TABLE[105][282] = 1;
TABLE[105][267] = 1;
TABLE[105][279] = 1;
TABLE[105][274] = 1;
TABLE[105][256] = 1;
TABLE[105][283] = 1;
TABLE[105][280] = 1;
TABLE[211][40] = 1;
TABLE[211][42] = 1;
TABLE[211][299] = 1;
TABLE[211][256] = 1;
TABLE[211][274] = 1;
TABLE[211][279] = 1;
TABLE[211][267] = 1;
TABLE[211][282] = 1;
TABLE[211][266] = 1;
TABLE[211][285] = 1;
TABLE[211][259] = 1;
TABLE[211][276] = 1;
TABLE[211][272] = 1;
TABLE[211][273] = 1;
TABLE[211][268] = 1;
TABLE[211][264] = 1;
TABLE[211][277] = 1;
TABLE[211][284] = 1;
TABLE[211][260] = 1;
TABLE[211][286] = 1;
TABLE[211][280] = 1;
TABLE[211][283] = 1;
TABLE[211][123] = 1;
TABLE[106][123] = 1;
TABLE[106][286] = 1;
TABLE[106][260] = 1;
TABLE[106][284] = 1;
TABLE[106][277] = 1;
TABLE[106][264] = 1;
TABLE[106][268] = 1;
TABLE[106][273] = 1;
TABLE[106][272] = 1;
TABLE[106][276] = 1;
TABLE[106][259] = 1;
TABLE[106][285] = 1;
TABLE[106][266] = 1;
TABLE[106][282] = 1;
TABLE[106][267] = 1;
TABLE[106][279] = 1;
TABLE[106][274] = 1;
TABLE[106][256] = 1;
TABLE[106][283] = 1;
TABLE[106][280] = 1;
TABLE[212][123] = 1;
TABLE[5][286] = 1;
TABLE[5][260] = 1;
TABLE[5][284] = 1;
TABLE[5][277] = 1;
TABLE[5][264] = 1;
TABLE[5][268] = 1;
TABLE[5][273] = 1;
TABLE[5][272] = 1;
TABLE[5][276] = 1;
TABLE[5][259] = 1;
TABLE[5][285] = 1;
TABLE[5][266] = 1;
TABLE[5][282] = 1;
TABLE[5][267] = 1;
TABLE[5][279] = 1;
TABLE[5][274] = 1;
TABLE[5][256] = 1;
TABLE[5][283] = 1;
TABLE[5][280] = 1;
TABLE[107][59] = 1;
TABLE[107][44] = 1;
TABLE[107][123] = 1;
TABLE[107][61] = 1;
TABLE[107][278] = 1;
TABLE[107][40] = 1;
TABLE[107][295] = 1;
TABLE[107][294] = 1;
TABLE[107][63] = 1;
TABLE[107][299] = 1;
TABLE[107][42] = 1;
TABLE[107][289] = 1;
TABLE[107][302] = 1;
TABLE[107][43] = 1;
TABLE[107][45] = 1;
TABLE[107][126] = 1;
TABLE[107][33] = 1;
TABLE[107][297] = 1;
TABLE[107][307] = 1;
TABLE[107][306] = 1;
TABLE[107][308] = 1;
TABLE[107][298] = 1;
TABLE[107][301] = 1;
TABLE[107][303] = 1;
TABLE[107][292] = 1;
TABLE[107][304] = 1;
TABLE[107][37] = 1;
TABLE[107][47] = 1;
TABLE[213][59] = 1;
TABLE[6][256] = 1;
TABLE[6][274] = 1;
TABLE[6][279] = 1;
TABLE[6][267] = 1;
TABLE[6][282] = 1;
TABLE[6][266] = 1;
TABLE[6][285] = 1;
TABLE[6][259] = 1;
TABLE[6][276] = 1;
TABLE[6][272] = 1;
TABLE[6][273] = 1;
TABLE[6][268] = 1;
TABLE[6][264] = 1;
TABLE[6][277] = 1;
TABLE[6][284] = 1;
TABLE[6][260] = 1;
TABLE[6][286] = 1;
TABLE[6][280] = 1;
TABLE[6][283] = 1;
TABLE[108][286] = 1;
TABLE[108][260] = 1;
TABLE[108][284] = 1;
TABLE[108][277] = 1;
TABLE[108][264] = 1;
TABLE[108][268] = 1;
TABLE[108][273] = 1;
TABLE[108][272] = 1;
TABLE[108][276] = 1;
TABLE[108][259] = 1;
TABLE[108][285] = 1;
TABLE[108][266] = 1;
TABLE[108][282] = 1;
TABLE[108][267] = 1;
TABLE[108][279] = 1;
TABLE[108][274] = 1;
TABLE[108][256] = 1;
TABLE[108][283] = 1;
TABLE[108][280] = 1;
TABLE[214][256] = 1;
TABLE[214][274] = 1;
TABLE[214][279] = 1;
TABLE[214][267] = 1;
TABLE[214][282] = 1;
TABLE[214][266] = 1;
TABLE[214][285] = 1;
TABLE[214][259] = 1;
TABLE[214][276] = 1;
TABLE[214][272] = 1;
TABLE[214][273] = 1;
TABLE[214][268] = 1;
TABLE[214][264] = 1;
TABLE[214][277] = 1;
TABLE[214][284] = 1;
TABLE[214][260] = 1;
TABLE[214][286] = 1;
TABLE[214][280] = 1;
TABLE[214][283] = 1;
TABLE[7][256] = 1;
TABLE[7][274] = 1;
TABLE[7][279] = 1;
TABLE[7][267] = 1;
TABLE[7][282] = 1;
TABLE[7][266] = 1;
TABLE[7][285] = 1;
TABLE[7][259] = 1;
TABLE[7][276] = 1;
TABLE[7][272] = 1;
TABLE[7][273] = 1;
TABLE[7][268] = 1;
TABLE[7][264] = 1;
TABLE[7][277] = 1;
TABLE[7][284] = 1;
TABLE[7][260] = 1;
TABLE[7][286] = 1;
TABLE[7][280] = 1;
TABLE[7][283] = 1;
TABLE[109][282] = 1;
TABLE[109][267] = 1;
TABLE[109][279] = 1;
TABLE[109][274] = 1;
TABLE[109][256] = 1;
TABLE[110][284] = 1;
TABLE[110][277] = 1;
TABLE[110][264] = 1;
TABLE[110][268] = 1;
TABLE[110][273] = 1;
TABLE[110][272] = 1;
TABLE[110][276] = 1;
TABLE[110][259] = 1;
TABLE[110][285] = 1;
TABLE[110][266] = 1;
TABLE[110][283] = 1;
TABLE[110][280] = 1;
TABLE[111][286] = 1;
TABLE[111][260] = 1;
TABLE[112][286] = 1;
TABLE[112][260] = 1;
TABLE[112][284] = 1;
TABLE[112][277] = 1;
TABLE[112][264] = 1;
TABLE[112][268] = 1;
TABLE[112][273] = 1;
TABLE[112][272] = 1;
TABLE[112][276] = 1;
TABLE[112][259] = 1;
TABLE[112][285] = 1;
TABLE[112][266] = 1;
TABLE[112][282] = 1;
TABLE[112][267] = 1;
TABLE[112][279] = 1;
TABLE[112][274] = 1;
TABLE[112][256] = 1;
TABLE[112][283] = 1;
TABLE[112][280] = 1;
TABLE[215][40] = 1;
TABLE[215][42] = 1;
TABLE[215][299] = 1;
TABLE[215][256] = 1;
TABLE[215][274] = 1;
TABLE[215][279] = 1;
TABLE[215][267] = 1;
TABLE[215][282] = 1;
TABLE[215][266] = 1;
TABLE[215][285] = 1;
TABLE[215][259] = 1;
TABLE[215][276] = 1;
TABLE[215][272] = 1;
TABLE[215][273] = 1;
TABLE[215][268] = 1;
TABLE[215][264] = 1;
TABLE[215][277] = 1;
TABLE[215][284] = 1;
TABLE[215][260] = 1;
TABLE[215][286] = 1;
TABLE[215][280] = 1;
TABLE[215][283] = 1;
TABLE[215][123] = 1;
TABLE[215][44] = 1;
TABLE[215][61] = 1;
TABLE[215][278] = 1;
TABLE[215][63] = 1;
TABLE[215][294] = 1;
TABLE[215][295] = 1;
TABLE[215][297] = 1;
TABLE[215][33] = 1;
TABLE[215][126] = 1;
TABLE[215][45] = 1;
TABLE[215][43] = 1;
TABLE[215][302] = 1;
TABLE[215][289] = 1;
TABLE[215][298] = 1;
TABLE[215][308] = 1;
TABLE[215][306] = 1;
TABLE[215][307] = 1;
TABLE[215][301] = 1;
TABLE[215][303] = 1;
TABLE[215][292] = 1;
TABLE[215][304] = 1;
TABLE[215][47] = 1;
TABLE[215][37] = 1;
TABLE[215][59] = 1;
TABLE[215][91] = 1;
TABLE[215][41] = 1;
TABLE[8][256] = 1;
TABLE[8][274] = 1;
TABLE[8][279] = 1;
TABLE[8][267] = 1;
TABLE[8][282] = 1;
TABLE[113][256] = 1;
TABLE[114][274] = 1;
TABLE[115][279] = 1;
TABLE[116][267] = 1;
TABLE[117][282] = 1;
TABLE[9][285] = 1;
TABLE[9][259] = 1;
TABLE[9][276] = 1;
TABLE[9][272] = 1;
TABLE[9][273] = 1;
TABLE[9][268] = 1;
TABLE[9][264] = 1;
TABLE[9][277] = 1;
TABLE[9][284] = 1;
TABLE[10][280] = 1;
TABLE[10][283] = 1;
TABLE[11][266] = 1;
TABLE[118][285] = 1;
TABLE[119][259] = 1;
TABLE[120][276] = 1;
TABLE[121][272] = 1;
TABLE[122][273] = 1;
TABLE[123][268] = 1;
TABLE[124][264] = 1;
TABLE[125][277] = 1;
TABLE[126][284] = 1;
TABLE[12][260] = 1;
TABLE[12][286] = 1;
TABLE[127][260] = 1;
TABLE[128][286] = 1;
TABLE[13][283] = 1;
TABLE[13][280] = 1;
TABLE[14][283] = 1;
TABLE[14][280] = 1;
TABLE[129][299] = 1;
TABLE[216][123] = 1;
TABLE[15][280] = 1;
TABLE[15][283] = 1;
TABLE[130][280] = 1;
TABLE[131][283] = 1;
TABLE[16][266] = 1;
TABLE[16][285] = 1;
TABLE[16][259] = 1;
TABLE[16][276] = 1;
TABLE[16][272] = 1;
TABLE[16][273] = 1;
TABLE[16][268] = 1;
TABLE[16][264] = 1;
TABLE[16][277] = 1;
TABLE[16][284] = 1;
TABLE[16][260] = 1;
TABLE[16][286] = 1;
TABLE[16][280] = 1;
TABLE[16][283] = 1;
TABLE[132][286] = 1;
TABLE[132][260] = 1;
TABLE[132][284] = 1;
TABLE[132][277] = 1;
TABLE[132][264] = 1;
TABLE[132][268] = 1;
TABLE[132][273] = 1;
TABLE[132][272] = 1;
TABLE[132][276] = 1;
TABLE[132][259] = 1;
TABLE[132][285] = 1;
TABLE[132][266] = 1;
TABLE[132][283] = 1;
TABLE[132][280] = 1;
TABLE[217][266] = 1;
TABLE[217][285] = 1;
TABLE[217][259] = 1;
TABLE[217][276] = 1;
TABLE[217][272] = 1;
TABLE[217][273] = 1;
TABLE[217][268] = 1;
TABLE[217][264] = 1;
TABLE[217][277] = 1;
TABLE[217][284] = 1;
TABLE[217][260] = 1;
TABLE[217][286] = 1;
TABLE[217][280] = 1;
TABLE[217][283] = 1;
TABLE[17][59] = 1;
TABLE[17][44] = 1;
TABLE[17][61] = 1;
TABLE[17][123] = 1;
TABLE[17][40] = 1;
TABLE[17][278] = 1;
TABLE[17][42] = 1;
TABLE[17][299] = 1;
TABLE[17][63] = 1;
TABLE[17][294] = 1;
TABLE[17][295] = 1;
TABLE[17][297] = 1;
TABLE[17][33] = 1;
TABLE[17][126] = 1;
TABLE[17][45] = 1;
TABLE[17][43] = 1;
TABLE[17][302] = 1;
TABLE[17][289] = 1;
TABLE[17][298] = 1;
TABLE[17][308] = 1;
TABLE[17][306] = 1;
TABLE[17][307] = 1;
TABLE[17][301] = 1;
TABLE[17][303] = 1;
TABLE[17][292] = 1;
TABLE[17][304] = 1;
TABLE[17][47] = 1;
TABLE[17][37] = 1;
TABLE[133][44] = 1;
TABLE[133][123] = 1;
TABLE[133][61] = 1;
TABLE[133][278] = 1;
TABLE[133][40] = 1;
TABLE[133][295] = 1;
TABLE[133][294] = 1;
TABLE[133][63] = 1;
TABLE[133][299] = 1;
TABLE[133][42] = 1;
TABLE[133][289] = 1;
TABLE[133][302] = 1;
TABLE[133][43] = 1;
TABLE[133][45] = 1;
TABLE[133][126] = 1;
TABLE[133][33] = 1;
TABLE[133][297] = 1;
TABLE[133][307] = 1;
TABLE[133][306] = 1;
TABLE[133][308] = 1;
TABLE[133][298] = 1;
TABLE[133][301] = 1;
TABLE[133][303] = 1;
TABLE[133][292] = 1;
TABLE[133][304] = 1;
TABLE[133][37] = 1;
TABLE[133][47] = 1;
TABLE[218][61] = 1;
TABLE[218][123] = 1;
TABLE[218][40] = 1;
TABLE[218][278] = 1;
TABLE[218][42] = 1;
TABLE[218][299] = 1;
TABLE[218][63] = 1;
TABLE[218][294] = 1;
TABLE[218][295] = 1;
TABLE[218][297] = 1;
TABLE[218][33] = 1;
TABLE[218][126] = 1;
TABLE[218][45] = 1;
TABLE[218][43] = 1;
TABLE[218][302] = 1;
TABLE[218][289] = 1;
TABLE[218][298] = 1;
TABLE[218][308] = 1;
TABLE[218][306] = 1;
TABLE[218][307] = 1;
TABLE[218][301] = 1;
TABLE[218][303] = 1;
TABLE[218][292] = 1;
TABLE[218][304] = 1;
TABLE[218][47] = 1;
TABLE[218][37] = 1;
TABLE[218][59] = 1;
TABLE[218][44] = 1;
TABLE[18][59] = 1;
TABLE[18][44] = 1;
TABLE[18][123] = 1;
TABLE[18][278] = 1;
TABLE[18][295] = 1;
TABLE[18][294] = 1;
TABLE[18][63] = 1;
TABLE[18][289] = 1;
TABLE[18][302] = 1;
TABLE[18][43] = 1;
TABLE[18][45] = 1;
TABLE[18][126] = 1;
TABLE[18][33] = 1;
TABLE[18][297] = 1;
TABLE[18][307] = 1;
TABLE[18][306] = 1;
TABLE[18][308] = 1;
TABLE[18][298] = 1;
TABLE[18][301] = 1;
TABLE[18][303] = 1;
TABLE[18][292] = 1;
TABLE[18][304] = 1;
TABLE[18][37] = 1;
TABLE[18][47] = 1;
TABLE[18][61] = 1;
TABLE[18][40] = 1;
TABLE[18][299] = 1;
TABLE[18][42] = 1;
TABLE[134][61] = 1;
TABLE[134][40] = 1;
TABLE[134][42] = 1;
TABLE[134][299] = 1;
TABLE[219][123] = 1;
TABLE[219][278] = 1;
TABLE[219][295] = 1;
TABLE[219][294] = 1;
TABLE[219][63] = 1;
TABLE[219][289] = 1;
TABLE[219][40] = 1;
TABLE[219][302] = 1;
TABLE[219][42] = 1;
TABLE[219][43] = 1;
TABLE[219][45] = 1;
TABLE[219][126] = 1;
TABLE[219][33] = 1;
TABLE[219][297] = 1;
TABLE[219][299] = 1;
TABLE[219][307] = 1;
TABLE[219][306] = 1;
TABLE[219][308] = 1;
TABLE[219][298] = 1;
TABLE[219][301] = 1;
TABLE[219][303] = 1;
TABLE[219][292] = 1;
TABLE[219][304] = 1;
TABLE[219][37] = 1;
TABLE[219][47] = 1;
TABLE[219][59] = 1;
TABLE[219][44] = 1;
TABLE[19][286] = 1;
TABLE[19][260] = 1;
TABLE[19][284] = 1;
TABLE[19][277] = 1;
TABLE[19][264] = 1;
TABLE[19][268] = 1;
TABLE[19][273] = 1;
TABLE[19][272] = 1;
TABLE[19][276] = 1;
TABLE[19][259] = 1;
TABLE[19][285] = 1;
TABLE[19][266] = 1;
TABLE[19][283] = 1;
TABLE[19][280] = 1;
TABLE[20][266] = 1;
TABLE[20][285] = 1;
TABLE[20][259] = 1;
TABLE[20][276] = 1;
TABLE[20][272] = 1;
TABLE[20][273] = 1;
TABLE[20][268] = 1;
TABLE[20][264] = 1;
TABLE[20][277] = 1;
TABLE[20][284] = 1;
TABLE[20][260] = 1;
TABLE[20][286] = 1;
TABLE[20][280] = 1;
TABLE[20][283] = 1;
TABLE[135][284] = 1;
TABLE[135][277] = 1;
TABLE[135][264] = 1;
TABLE[135][268] = 1;
TABLE[135][273] = 1;
TABLE[135][272] = 1;
TABLE[135][276] = 1;
TABLE[135][259] = 1;
TABLE[135][285] = 1;
TABLE[135][266] = 1;
TABLE[135][283] = 1;
TABLE[135][280] = 1;
TABLE[136][286] = 1;
TABLE[136][260] = 1;
TABLE[137][286] = 1;
TABLE[137][260] = 1;
TABLE[137][284] = 1;
TABLE[137][277] = 1;
TABLE[137][264] = 1;
TABLE[137][268] = 1;
TABLE[137][273] = 1;
TABLE[137][272] = 1;
TABLE[137][276] = 1;
TABLE[137][259] = 1;
TABLE[137][285] = 1;
TABLE[137][266] = 1;
TABLE[137][283] = 1;
TABLE[137][280] = 1;
TABLE[220][44] = 1;
TABLE[220][58] = 1;
TABLE[220][40] = 1;
TABLE[220][42] = 1;
TABLE[220][299] = 1;
TABLE[220][59] = 1;
TABLE[220][91] = 1;
TABLE[220][41] = 1;
TABLE[21][59] = 1;
TABLE[21][44] = 1;
TABLE[21][58] = 1;
TABLE[21][40] = 1;
TABLE[21][299] = 1;
TABLE[21][42] = 1;
TABLE[138][44] = 1;
TABLE[138][58] = 1;
TABLE[138][40] = 1;
TABLE[138][42] = 1;
TABLE[138][299] = 1;
TABLE[221][58] = 1;
TABLE[221][40] = 1;
TABLE[221][299] = 1;
TABLE[221][42] = 1;
TABLE[221][59] = 1;
TABLE[221][44] = 1;
TABLE[22][59] = 1;
TABLE[22][44] = 1;
TABLE[22][40] = 1;
TABLE[22][42] = 1;
TABLE[22][299] = 1;
TABLE[23][58] = 1;
TABLE[23][40] = 1;
TABLE[23][299] = 1;
TABLE[23][42] = 1;
TABLE[139][58] = 1;
TABLE[139][40] = 1;
TABLE[139][42] = 1;
TABLE[139][299] = 1;
TABLE[222][58] = 1;
TABLE[24][266] = 1;
TABLE[25][266] = 1;
TABLE[140][299] = 1;
TABLE[223][123] = 1;
TABLE[26][44] = 1;
TABLE[26][299] = 1;
TABLE[141][44] = 1;
TABLE[141][299] = 1;
TABLE[224][299] = 1;
TABLE[27][299] = 1;
TABLE[142][61] = 1;
TABLE[225][125] = 1;
TABLE[225][44] = 1;
TABLE[28][40] = 1;
TABLE[28][299] = 1;
TABLE[28][42] = 1;
TABLE[143][42] = 1;
TABLE[226][40] = 1;
TABLE[226][299] = 1;
TABLE[29][299] = 1;
TABLE[30][40] = 1;
TABLE[31][40] = 1;
TABLE[31][299] = 1;
TABLE[145][91] = 1;
TABLE[146][40] = 1;
TABLE[148][40] = 1;
TABLE[144][93] = 1;
TABLE[144][63] = 1;
TABLE[144][297] = 1;
TABLE[144][298] = 1;
TABLE[144][301] = 1;
TABLE[144][303] = 1;
TABLE[144][302] = 1;
TABLE[144][292] = 1;
TABLE[144][304] = 1;
TABLE[144][40] = 1;
TABLE[144][45] = 1;
TABLE[144][43] = 1;
TABLE[144][42] = 1;
TABLE[144][47] = 1;
TABLE[144][37] = 1;
TABLE[144][278] = 1;
TABLE[144][295] = 1;
TABLE[144][294] = 1;
TABLE[144][289] = 1;
TABLE[144][126] = 1;
TABLE[144][33] = 1;
TABLE[144][299] = 1;
TABLE[144][307] = 1;
TABLE[144][306] = 1;
TABLE[144][308] = 1;
TABLE[227][93] = 1;
TABLE[147][41] = 1;
TABLE[147][44] = 1;
TABLE[147][299] = 1;
TABLE[228][41] = 1;
TABLE[32][42] = 1;
TABLE[149][42] = 1;
TABLE[149][40] = 1;
TABLE[149][299] = 1;
TABLE[149][44] = 1;
TABLE[149][41] = 1;
TABLE[149][91] = 1;
TABLE[149][260] = 1;
TABLE[149][286] = 1;
TABLE[229][42] = 1;
TABLE[229][40] = 1;
TABLE[229][299] = 1;
TABLE[229][44] = 1;
TABLE[229][41] = 1;
TABLE[229][91] = 1;
TABLE[150][42] = 1;
TABLE[230][40] = 1;
TABLE[230][299] = 1;
TABLE[230][44] = 1;
TABLE[230][41] = 1;
TABLE[230][91] = 1;
TABLE[33][286] = 1;
TABLE[33][260] = 1;
TABLE[151][260] = 1;
TABLE[151][286] = 1;
TABLE[231][286] = 1;
TABLE[231][260] = 1;
TABLE[34][41] = 1;
TABLE[34][44] = 1;
TABLE[34][286] = 1;
TABLE[34][260] = 1;
TABLE[34][284] = 1;
TABLE[34][277] = 1;
TABLE[34][264] = 1;
TABLE[34][268] = 1;
TABLE[34][273] = 1;
TABLE[34][272] = 1;
TABLE[34][276] = 1;
TABLE[34][259] = 1;
TABLE[34][285] = 1;
TABLE[34][266] = 1;
TABLE[34][282] = 1;
TABLE[34][267] = 1;
TABLE[34][279] = 1;
TABLE[34][274] = 1;
TABLE[34][256] = 1;
TABLE[34][283] = 1;
TABLE[34][280] = 1;
TABLE[152][44] = 1;
TABLE[232][41] = 1;
TABLE[35][44] = 1;
TABLE[35][256] = 1;
TABLE[35][274] = 1;
TABLE[35][279] = 1;
TABLE[35][267] = 1;
TABLE[35][282] = 1;
TABLE[35][266] = 1;
TABLE[35][285] = 1;
TABLE[35][259] = 1;
TABLE[35][276] = 1;
TABLE[35][272] = 1;
TABLE[35][273] = 1;
TABLE[35][268] = 1;
TABLE[35][264] = 1;
TABLE[35][277] = 1;
TABLE[35][284] = 1;
TABLE[35][260] = 1;
TABLE[35][286] = 1;
TABLE[35][280] = 1;
TABLE[35][283] = 1;
TABLE[153][44] = 1;
TABLE[153][286] = 1;
TABLE[153][260] = 1;
TABLE[153][284] = 1;
TABLE[153][277] = 1;
TABLE[153][264] = 1;
TABLE[153][268] = 1;
TABLE[153][273] = 1;
TABLE[153][272] = 1;
TABLE[153][276] = 1;
TABLE[153][259] = 1;
TABLE[153][285] = 1;
TABLE[153][266] = 1;
TABLE[153][282] = 1;
TABLE[153][267] = 1;
TABLE[153][279] = 1;
TABLE[153][274] = 1;
TABLE[153][256] = 1;
TABLE[153][283] = 1;
TABLE[153][280] = 1;
TABLE[233][256] = 1;
TABLE[233][274] = 1;
TABLE[233][279] = 1;
TABLE[233][267] = 1;
TABLE[233][282] = 1;
TABLE[233][266] = 1;
TABLE[233][285] = 1;
TABLE[233][259] = 1;
TABLE[233][276] = 1;
TABLE[233][272] = 1;
TABLE[233][273] = 1;
TABLE[233][268] = 1;
TABLE[233][264] = 1;
TABLE[233][277] = 1;
TABLE[233][284] = 1;
TABLE[233][260] = 1;
TABLE[233][286] = 1;
TABLE[233][280] = 1;
TABLE[233][283] = 1;
TABLE[36][286] = 1;
TABLE[36][260] = 1;
TABLE[36][284] = 1;
TABLE[36][277] = 1;
TABLE[36][264] = 1;
TABLE[36][268] = 1;
TABLE[36][273] = 1;
TABLE[36][272] = 1;
TABLE[36][276] = 1;
TABLE[36][259] = 1;
TABLE[36][285] = 1;
TABLE[36][266] = 1;
TABLE[36][282] = 1;
TABLE[36][267] = 1;
TABLE[36][279] = 1;
TABLE[36][274] = 1;
TABLE[36][256] = 1;
TABLE[36][283] = 1;
TABLE[36][280] = 1;
TABLE[154][44] = 1;
TABLE[154][41] = 1;
TABLE[154][40] = 1;
TABLE[154][42] = 1;
TABLE[154][299] = 1;
TABLE[156][44] = 1;
TABLE[156][41] = 1;
TABLE[156][42] = 1;
TABLE[156][40] = 1;
TABLE[156][91] = 1;
TABLE[155][44] = 1;
TABLE[155][41] = 1;
TABLE[155][42] = 1;
TABLE[155][40] = 1;
TABLE[155][91] = 1;
TABLE[234][44] = 1;
TABLE[234][41] = 1;
TABLE[37][44] = 1;
TABLE[37][299] = 1;
TABLE[157][44] = 1;
TABLE[157][299] = 1;
TABLE[235][299] = 1;
TABLE[38][59] = 1;
TABLE[38][44] = 1;
TABLE[38][125] = 1;
TABLE[38][278] = 1;
TABLE[38][63] = 1;
TABLE[38][294] = 1;
TABLE[38][295] = 1;
TABLE[38][297] = 1;
TABLE[38][33] = 1;
TABLE[38][126] = 1;
TABLE[38][45] = 1;
TABLE[38][43] = 1;
TABLE[38][42] = 1;
TABLE[38][302] = 1;
TABLE[38][40] = 1;
TABLE[38][289] = 1;
TABLE[38][298] = 1;
TABLE[38][308] = 1;
TABLE[38][306] = 1;
TABLE[38][307] = 1;
TABLE[38][299] = 1;
TABLE[38][301] = 1;
TABLE[38][303] = 1;
TABLE[38][292] = 1;
TABLE[38][304] = 1;
TABLE[38][47] = 1;
TABLE[38][37] = 1;
TABLE[39][123] = 1;
TABLE[158][44] = 1;
TABLE[236][125] = 1;
TABLE[40][125] = 1;
TABLE[40][123] = 1;
TABLE[40][44] = 1;
TABLE[40][278] = 1;
TABLE[40][295] = 1;
TABLE[40][294] = 1;
TABLE[40][63] = 1;
TABLE[40][289] = 1;
TABLE[40][40] = 1;
TABLE[40][302] = 1;
TABLE[40][42] = 1;
TABLE[40][43] = 1;
TABLE[40][45] = 1;
TABLE[40][126] = 1;
TABLE[40][33] = 1;
TABLE[40][297] = 1;
TABLE[40][299] = 1;
TABLE[40][307] = 1;
TABLE[40][306] = 1;
TABLE[40][308] = 1;
TABLE[40][298] = 1;
TABLE[40][301] = 1;
TABLE[40][303] = 1;
TABLE[40][292] = 1;
TABLE[40][304] = 1;
TABLE[40][37] = 1;
TABLE[40][47] = 1;
TABLE[159][123] = 1;
TABLE[159][44] = 1;
TABLE[159][278] = 1;
TABLE[159][63] = 1;
TABLE[159][294] = 1;
TABLE[159][295] = 1;
TABLE[159][297] = 1;
TABLE[159][33] = 1;
TABLE[159][126] = 1;
TABLE[159][45] = 1;
TABLE[159][43] = 1;
TABLE[159][42] = 1;
TABLE[159][302] = 1;
TABLE[159][40] = 1;
TABLE[159][289] = 1;
TABLE[159][298] = 1;
TABLE[159][308] = 1;
TABLE[159][306] = 1;
TABLE[159][307] = 1;
TABLE[159][299] = 1;
TABLE[159][301] = 1;
TABLE[159][303] = 1;
TABLE[159][292] = 1;
TABLE[159][304] = 1;
TABLE[159][47] = 1;
TABLE[159][37] = 1;
TABLE[237][123] = 1;
TABLE[237][278] = 1;
TABLE[237][295] = 1;
TABLE[237][294] = 1;
TABLE[237][63] = 1;
TABLE[237][289] = 1;
TABLE[237][40] = 1;
TABLE[237][302] = 1;
TABLE[237][42] = 1;
TABLE[237][43] = 1;
TABLE[237][45] = 1;
TABLE[237][126] = 1;
TABLE[237][33] = 1;
TABLE[237][297] = 1;
TABLE[237][299] = 1;
TABLE[237][307] = 1;
TABLE[237][306] = 1;
TABLE[237][308] = 1;
TABLE[237][298] = 1;
TABLE[237][301] = 1;
TABLE[237][303] = 1;
TABLE[237][292] = 1;
TABLE[237][304] = 1;
TABLE[237][37] = 1;
TABLE[237][47] = 1;
TABLE[237][44] = 1;
TABLE[237][125] = 1;
TABLE[41][286] = 1;
TABLE[41][260] = 1;
TABLE[41][284] = 1;
TABLE[41][277] = 1;
TABLE[41][264] = 1;
TABLE[41][268] = 1;
TABLE[41][273] = 1;
TABLE[41][272] = 1;
TABLE[41][276] = 1;
TABLE[41][259] = 1;
TABLE[41][285] = 1;
TABLE[41][266] = 1;
TABLE[41][283] = 1;
TABLE[41][280] = 1;
TABLE[160][41] = 1;
TABLE[160][42] = 1;
TABLE[160][40] = 1;
TABLE[160][91] = 1;
TABLE[238][41] = 1;
TABLE[42][42] = 1;
TABLE[43][44] = 1;
TABLE[43][41] = 1;
TABLE[43][40] = 1;
TABLE[43][91] = 1;
TABLE[43][42] = 1;
TABLE[161][42] = 1;
TABLE[239][40] = 1;
TABLE[239][91] = 1;
TABLE[239][44] = 1;
TABLE[239][41] = 1;
TABLE[44][40] = 1;
TABLE[45][40] = 1;
TABLE[45][91] = 1;
TABLE[162][40] = 1;
TABLE[162][91] = 1;
TABLE[240][91] = 1;
TABLE[240][40] = 1;
TABLE[164][91] = 1;
TABLE[166][40] = 1;
TABLE[163][93] = 1;
TABLE[163][63] = 1;
TABLE[163][297] = 1;
TABLE[163][298] = 1;
TABLE[163][301] = 1;
TABLE[163][303] = 1;
TABLE[163][302] = 1;
TABLE[163][292] = 1;
TABLE[163][304] = 1;
TABLE[163][40] = 1;
TABLE[163][45] = 1;
TABLE[163][43] = 1;
TABLE[163][42] = 1;
TABLE[163][47] = 1;
TABLE[163][37] = 1;
TABLE[163][278] = 1;
TABLE[163][295] = 1;
TABLE[163][294] = 1;
TABLE[163][289] = 1;
TABLE[163][126] = 1;
TABLE[163][33] = 1;
TABLE[163][299] = 1;
TABLE[163][307] = 1;
TABLE[163][306] = 1;
TABLE[163][308] = 1;
TABLE[241][93] = 1;
TABLE[165][41] = 1;
TABLE[165][44] = 1;
TABLE[165][256] = 1;
TABLE[165][274] = 1;
TABLE[165][279] = 1;
TABLE[165][267] = 1;
TABLE[165][282] = 1;
TABLE[165][266] = 1;
TABLE[165][285] = 1;
TABLE[165][259] = 1;
TABLE[165][276] = 1;
TABLE[165][272] = 1;
TABLE[165][273] = 1;
TABLE[165][268] = 1;
TABLE[165][264] = 1;
TABLE[165][277] = 1;
TABLE[165][284] = 1;
TABLE[165][260] = 1;
TABLE[165][286] = 1;
TABLE[165][280] = 1;
TABLE[165][283] = 1;
TABLE[242][41] = 1;
TABLE[46][299] = 1;
TABLE[47][258] = 1;
TABLE[47][262] = 1;
TABLE[47][299] = 1;
TABLE[48][125] = 1;
TABLE[48][265] = 1;
TABLE[48][287] = 1;
TABLE[48][262] = 1;
TABLE[48][258] = 1;
TABLE[48][123] = 1;
TABLE[48][281] = 1;
TABLE[48][271] = 1;
TABLE[48][269] = 1;
TABLE[48][263] = 1;
TABLE[48][275] = 1;
TABLE[48][257] = 1;
TABLE[48][261] = 1;
TABLE[48][270] = 1;
TABLE[48][59] = 1;
TABLE[48][44] = 1;
TABLE[48][278] = 1;
TABLE[48][295] = 1;
TABLE[48][294] = 1;
TABLE[48][63] = 1;
TABLE[48][289] = 1;
TABLE[48][40] = 1;
TABLE[48][302] = 1;
TABLE[48][42] = 1;
TABLE[48][43] = 1;
TABLE[48][45] = 1;
TABLE[48][126] = 1;
TABLE[48][33] = 1;
TABLE[48][297] = 1;
TABLE[48][299] = 1;
TABLE[48][307] = 1;
TABLE[48][306] = 1;
TABLE[48][308] = 1;
TABLE[48][298] = 1;
TABLE[48][301] = 1;
TABLE[48][303] = 1;
TABLE[48][292] = 1;
TABLE[48][304] = 1;
TABLE[48][37] = 1;
TABLE[48][47] = 1;
TABLE[49][123] = 1;
TABLE[50][271] = 1;
TABLE[50][281] = 1;
TABLE[51][287] = 1;
TABLE[51][263] = 1;
TABLE[51][269] = 1;
TABLE[52][270] = 1;
TABLE[52][261] = 1;
TABLE[52][257] = 1;
TABLE[52][275] = 1;
TABLE[53][299] = 1;
TABLE[54][258] = 1;
TABLE[55][262] = 1;
TABLE[56][59] = 1;
TABLE[56][44] = 1;
TABLE[56][278] = 1;
TABLE[56][63] = 1;
TABLE[56][294] = 1;
TABLE[56][295] = 1;
TABLE[56][297] = 1;
TABLE[56][33] = 1;
TABLE[56][126] = 1;
TABLE[56][45] = 1;
TABLE[56][43] = 1;
TABLE[56][42] = 1;
TABLE[56][302] = 1;
TABLE[56][40] = 1;
TABLE[56][289] = 1;
TABLE[56][298] = 1;
TABLE[56][308] = 1;
TABLE[56][306] = 1;
TABLE[56][307] = 1;
TABLE[56][299] = 1;
TABLE[56][301] = 1;
TABLE[56][303] = 1;
TABLE[56][292] = 1;
TABLE[56][304] = 1;
TABLE[56][47] = 1;
TABLE[56][37] = 1;
TABLE[167][59] = 1;
TABLE[167][44] = 1;
TABLE[167][278] = 1;
TABLE[167][295] = 1;
TABLE[167][294] = 1;
TABLE[167][63] = 1;
TABLE[167][289] = 1;
TABLE[167][40] = 1;
TABLE[167][302] = 1;
TABLE[167][42] = 1;
TABLE[167][43] = 1;
TABLE[167][45] = 1;
TABLE[167][126] = 1;
TABLE[167][33] = 1;
TABLE[167][297] = 1;
TABLE[167][299] = 1;
TABLE[167][307] = 1;
TABLE[167][306] = 1;
TABLE[167][308] = 1;
TABLE[167][298] = 1;
TABLE[167][301] = 1;
TABLE[167][303] = 1;
TABLE[167][292] = 1;
TABLE[167][304] = 1;
TABLE[167][37] = 1;
TABLE[167][47] = 1;
TABLE[243][59] = 1;
TABLE[57][123] = 1;
TABLE[168][262] = 1;
TABLE[168][258] = 1;
TABLE[168][59] = 1;
TABLE[168][123] = 1;
TABLE[168][281] = 1;
TABLE[168][271] = 1;
TABLE[168][269] = 1;
TABLE[168][263] = 1;
TABLE[168][287] = 1;
TABLE[168][275] = 1;
TABLE[168][257] = 1;
TABLE[168][261] = 1;
TABLE[168][270] = 1;
TABLE[168][299] = 1;
TABLE[168][44] = 1;
TABLE[168][278] = 1;
TABLE[168][63] = 1;
TABLE[168][294] = 1;
TABLE[168][295] = 1;
TABLE[168][297] = 1;
TABLE[168][33] = 1;
TABLE[168][126] = 1;
TABLE[168][45] = 1;
TABLE[168][43] = 1;
TABLE[168][42] = 1;
TABLE[168][302] = 1;
TABLE[168][40] = 1;
TABLE[168][289] = 1;
TABLE[168][298] = 1;
TABLE[168][308] = 1;
TABLE[168][306] = 1;
TABLE[168][307] = 1;
TABLE[168][301] = 1;
TABLE[168][303] = 1;
TABLE[168][292] = 1;
TABLE[168][304] = 1;
TABLE[168][47] = 1;
TABLE[168][37] = 1;
TABLE[168][125] = 1;
TABLE[168][286] = 1;
TABLE[168][260] = 1;
TABLE[168][284] = 1;
TABLE[168][277] = 1;
TABLE[168][264] = 1;
TABLE[168][268] = 1;
TABLE[168][273] = 1;
TABLE[168][272] = 1;
TABLE[168][276] = 1;
TABLE[168][259] = 1;
TABLE[168][285] = 1;
TABLE[168][266] = 1;
TABLE[168][282] = 1;
TABLE[168][267] = 1;
TABLE[168][279] = 1;
TABLE[168][274] = 1;
TABLE[168][256] = 1;
TABLE[168][283] = 1;
TABLE[168][280] = 1;
TABLE[244][262] = 1;
TABLE[244][258] = 1;
TABLE[244][59] = 1;
TABLE[244][123] = 1;
TABLE[244][281] = 1;
TABLE[244][271] = 1;
TABLE[244][269] = 1;
TABLE[244][263] = 1;
TABLE[244][287] = 1;
TABLE[244][275] = 1;
TABLE[244][257] = 1;
TABLE[244][261] = 1;
TABLE[244][270] = 1;
TABLE[244][299] = 1;
TABLE[244][44] = 1;
TABLE[244][278] = 1;
TABLE[244][63] = 1;
TABLE[244][294] = 1;
TABLE[244][295] = 1;
TABLE[244][297] = 1;
TABLE[244][33] = 1;
TABLE[244][126] = 1;
TABLE[244][45] = 1;
TABLE[244][43] = 1;
TABLE[244][42] = 1;
TABLE[244][302] = 1;
TABLE[244][40] = 1;
TABLE[244][289] = 1;
TABLE[244][298] = 1;
TABLE[244][308] = 1;
TABLE[244][306] = 1;
TABLE[244][307] = 1;
TABLE[244][301] = 1;
TABLE[244][303] = 1;
TABLE[244][292] = 1;
TABLE[244][304] = 1;
TABLE[244][47] = 1;
TABLE[244][37] = 1;
TABLE[244][125] = 1;
TABLE[169][125] = 1;
TABLE[169][270] = 1;
TABLE[169][261] = 1;
TABLE[169][257] = 1;
TABLE[169][275] = 1;
TABLE[169][287] = 1;
TABLE[169][263] = 1;
TABLE[169][269] = 1;
TABLE[169][271] = 1;
TABLE[169][281] = 1;
TABLE[169][123] = 1;
TABLE[169][59] = 1;
TABLE[169][258] = 1;
TABLE[169][262] = 1;
TABLE[169][299] = 1;
TABLE[169][44] = 1;
TABLE[169][278] = 1;
TABLE[169][295] = 1;
TABLE[169][294] = 1;
TABLE[169][63] = 1;
TABLE[169][289] = 1;
TABLE[169][40] = 1;
TABLE[169][302] = 1;
TABLE[169][42] = 1;
TABLE[169][43] = 1;
TABLE[169][45] = 1;
TABLE[169][126] = 1;
TABLE[169][33] = 1;
TABLE[169][297] = 1;
TABLE[169][307] = 1;
TABLE[169][306] = 1;
TABLE[169][308] = 1;
TABLE[169][298] = 1;
TABLE[169][301] = 1;
TABLE[169][303] = 1;
TABLE[169][292] = 1;
TABLE[169][304] = 1;
TABLE[169][37] = 1;
TABLE[169][47] = 1;
TABLE[245][125] = 1;
TABLE[58][125] = 1;
TABLE[58][262] = 1;
TABLE[58][258] = 1;
TABLE[58][59] = 1;
TABLE[58][123] = 1;
TABLE[58][281] = 1;
TABLE[58][271] = 1;
TABLE[58][269] = 1;
TABLE[58][263] = 1;
TABLE[58][287] = 1;
TABLE[58][275] = 1;
TABLE[58][257] = 1;
TABLE[58][261] = 1;
TABLE[58][270] = 1;
TABLE[58][299] = 1;
TABLE[58][44] = 1;
TABLE[58][278] = 1;
TABLE[58][63] = 1;
TABLE[58][294] = 1;
TABLE[58][295] = 1;
TABLE[58][297] = 1;
TABLE[58][33] = 1;
TABLE[58][126] = 1;
TABLE[58][45] = 1;
TABLE[58][43] = 1;
TABLE[58][42] = 1;
TABLE[58][302] = 1;
TABLE[58][40] = 1;
TABLE[58][289] = 1;
TABLE[58][298] = 1;
TABLE[58][308] = 1;
TABLE[58][306] = 1;
TABLE[58][307] = 1;
TABLE[58][301] = 1;
TABLE[58][303] = 1;
TABLE[58][292] = 1;
TABLE[58][304] = 1;
TABLE[58][47] = 1;
TABLE[58][37] = 1;
TABLE[170][125] = 1;
TABLE[170][270] = 1;
TABLE[170][261] = 1;
TABLE[170][257] = 1;
TABLE[170][275] = 1;
TABLE[170][287] = 1;
TABLE[170][263] = 1;
TABLE[170][269] = 1;
TABLE[170][271] = 1;
TABLE[170][281] = 1;
TABLE[170][123] = 1;
TABLE[170][59] = 1;
TABLE[170][258] = 1;
TABLE[170][262] = 1;
TABLE[170][299] = 1;
TABLE[170][44] = 1;
TABLE[170][278] = 1;
TABLE[170][295] = 1;
TABLE[170][294] = 1;
TABLE[170][63] = 1;
TABLE[170][289] = 1;
TABLE[170][40] = 1;
TABLE[170][302] = 1;
TABLE[170][42] = 1;
TABLE[170][43] = 1;
TABLE[170][45] = 1;
TABLE[170][126] = 1;
TABLE[170][33] = 1;
TABLE[170][297] = 1;
TABLE[170][307] = 1;
TABLE[170][306] = 1;
TABLE[170][308] = 1;
TABLE[170][298] = 1;
TABLE[170][301] = 1;
TABLE[170][303] = 1;
TABLE[170][292] = 1;
TABLE[170][304] = 1;
TABLE[170][37] = 1;
TABLE[170][47] = 1;
TABLE[246][262] = 1;
TABLE[246][258] = 1;
TABLE[246][59] = 1;
TABLE[246][123] = 1;
TABLE[246][281] = 1;
TABLE[246][271] = 1;
TABLE[246][269] = 1;
TABLE[246][263] = 1;
TABLE[246][287] = 1;
TABLE[246][275] = 1;
TABLE[246][257] = 1;
TABLE[246][261] = 1;
TABLE[246][270] = 1;
TABLE[246][299] = 1;
TABLE[246][44] = 1;
TABLE[246][278] = 1;
TABLE[246][63] = 1;
TABLE[246][294] = 1;
TABLE[246][295] = 1;
TABLE[246][297] = 1;
TABLE[246][33] = 1;
TABLE[246][126] = 1;
TABLE[246][45] = 1;
TABLE[246][43] = 1;
TABLE[246][42] = 1;
TABLE[246][302] = 1;
TABLE[246][40] = 1;
TABLE[246][289] = 1;
TABLE[246][298] = 1;
TABLE[246][308] = 1;
TABLE[246][306] = 1;
TABLE[246][307] = 1;
TABLE[246][301] = 1;
TABLE[246][303] = 1;
TABLE[246][292] = 1;
TABLE[246][304] = 1;
TABLE[246][47] = 1;
TABLE[246][37] = 1;
TABLE[246][125] = 1;
TABLE[59][271] = 1;
TABLE[60][281] = 1;
TABLE[171][265] = 1;
TABLE[247][125] = 1;
TABLE[247][265] = 1;
TABLE[247][287] = 1;
TABLE[247][262] = 1;
TABLE[247][258] = 1;
TABLE[247][59] = 1;
TABLE[247][123] = 1;
TABLE[247][281] = 1;
TABLE[247][271] = 1;
TABLE[247][269] = 1;
TABLE[247][263] = 1;
TABLE[247][275] = 1;
TABLE[247][257] = 1;
TABLE[247][261] = 1;
TABLE[247][270] = 1;
TABLE[247][299] = 1;
TABLE[247][44] = 1;
TABLE[247][278] = 1;
TABLE[247][63] = 1;
TABLE[247][294] = 1;
TABLE[247][295] = 1;
TABLE[247][297] = 1;
TABLE[247][33] = 1;
TABLE[247][126] = 1;
TABLE[247][45] = 1;
TABLE[247][43] = 1;
TABLE[247][42] = 1;
TABLE[247][302] = 1;
TABLE[247][40] = 1;
TABLE[247][289] = 1;
TABLE[247][298] = 1;
TABLE[247][308] = 1;
TABLE[247][306] = 1;
TABLE[247][307] = 1;
TABLE[247][301] = 1;
TABLE[247][303] = 1;
TABLE[247][292] = 1;
TABLE[247][304] = 1;
TABLE[247][47] = 1;
TABLE[247][37] = 1;
TABLE[61][287] = 1;
TABLE[62][263] = 1;
TABLE[63][269] = 1;
TABLE[172][59] = 1;
TABLE[172][44] = 1;
TABLE[172][278] = 1;
TABLE[172][295] = 1;
TABLE[172][294] = 1;
TABLE[172][63] = 1;
TABLE[172][289] = 1;
TABLE[172][40] = 1;
TABLE[172][302] = 1;
TABLE[172][42] = 1;
TABLE[172][43] = 1;
TABLE[172][45] = 1;
TABLE[172][126] = 1;
TABLE[172][33] = 1;
TABLE[172][297] = 1;
TABLE[172][299] = 1;
TABLE[172][307] = 1;
TABLE[172][306] = 1;
TABLE[172][308] = 1;
TABLE[172][298] = 1;
TABLE[172][301] = 1;
TABLE[172][303] = 1;
TABLE[172][292] = 1;
TABLE[172][304] = 1;
TABLE[172][37] = 1;
TABLE[172][47] = 1;
TABLE[248][59] = 1;
TABLE[173][59] = 1;
TABLE[173][44] = 1;
TABLE[173][278] = 1;
TABLE[173][295] = 1;
TABLE[173][294] = 1;
TABLE[173][63] = 1;
TABLE[173][289] = 1;
TABLE[173][40] = 1;
TABLE[173][302] = 1;
TABLE[173][42] = 1;
TABLE[173][43] = 1;
TABLE[173][45] = 1;
TABLE[173][126] = 1;
TABLE[173][33] = 1;
TABLE[173][297] = 1;
TABLE[173][299] = 1;
TABLE[173][307] = 1;
TABLE[173][306] = 1;
TABLE[173][308] = 1;
TABLE[173][298] = 1;
TABLE[173][301] = 1;
TABLE[173][303] = 1;
TABLE[173][292] = 1;
TABLE[173][304] = 1;
TABLE[173][37] = 1;
TABLE[173][47] = 1;
TABLE[249][59] = 1;
TABLE[174][41] = 1;
TABLE[174][44] = 1;
TABLE[174][278] = 1;
TABLE[174][295] = 1;
TABLE[174][294] = 1;
TABLE[174][63] = 1;
TABLE[174][289] = 1;
TABLE[174][40] = 1;
TABLE[174][302] = 1;
TABLE[174][42] = 1;
TABLE[174][43] = 1;
TABLE[174][45] = 1;
TABLE[174][126] = 1;
TABLE[174][33] = 1;
TABLE[174][297] = 1;
TABLE[174][299] = 1;
TABLE[174][307] = 1;
TABLE[174][306] = 1;
TABLE[174][308] = 1;
TABLE[174][298] = 1;
TABLE[174][301] = 1;
TABLE[174][303] = 1;
TABLE[174][292] = 1;
TABLE[174][304] = 1;
TABLE[174][37] = 1;
TABLE[174][47] = 1;
TABLE[250][41] = 1;
TABLE[64][270] = 1;
TABLE[65][261] = 1;
TABLE[66][257] = 1;
TABLE[67][275] = 1;
TABLE[175][59] = 1;
TABLE[175][44] = 1;
TABLE[175][278] = 1;
TABLE[175][295] = 1;
TABLE[175][294] = 1;
TABLE[175][63] = 1;
TABLE[175][289] = 1;
TABLE[175][40] = 1;
TABLE[175][302] = 1;
TABLE[175][42] = 1;
TABLE[175][43] = 1;
TABLE[175][45] = 1;
TABLE[175][126] = 1;
TABLE[175][33] = 1;
TABLE[175][297] = 1;
TABLE[175][299] = 1;
TABLE[175][307] = 1;
TABLE[175][306] = 1;
TABLE[175][308] = 1;
TABLE[175][298] = 1;
TABLE[175][301] = 1;
TABLE[175][303] = 1;
TABLE[175][292] = 1;
TABLE[175][304] = 1;
TABLE[175][37] = 1;
TABLE[175][47] = 1;
TABLE[251][59] = 1;
TABLE[68][59] = 1;
TABLE[68][41] = 1;
TABLE[68][58] = 1;
TABLE[68][93] = 1;
TABLE[68][44] = 1;
TABLE[68][278] = 1;
TABLE[68][63] = 1;
TABLE[68][294] = 1;
TABLE[68][295] = 1;
TABLE[68][297] = 1;
TABLE[68][33] = 1;
TABLE[68][126] = 1;
TABLE[68][45] = 1;
TABLE[68][43] = 1;
TABLE[68][42] = 1;
TABLE[68][302] = 1;
TABLE[68][40] = 1;
TABLE[68][289] = 1;
TABLE[68][298] = 1;
TABLE[68][308] = 1;
TABLE[68][306] = 1;
TABLE[68][307] = 1;
TABLE[68][299] = 1;
TABLE[68][301] = 1;
TABLE[68][303] = 1;
TABLE[68][292] = 1;
TABLE[68][304] = 1;
TABLE[68][47] = 1;
TABLE[68][37] = 1;
TABLE[176][44] = 1;
TABLE[176][278] = 1;
TABLE[176][295] = 1;
TABLE[176][294] = 1;
TABLE[176][63] = 1;
TABLE[176][289] = 1;
TABLE[176][40] = 1;
TABLE[176][302] = 1;
TABLE[176][42] = 1;
TABLE[176][43] = 1;
TABLE[176][45] = 1;
TABLE[176][126] = 1;
TABLE[176][33] = 1;
TABLE[176][297] = 1;
TABLE[176][299] = 1;
TABLE[176][307] = 1;
TABLE[176][306] = 1;
TABLE[176][308] = 1;
TABLE[176][298] = 1;
TABLE[176][301] = 1;
TABLE[176][303] = 1;
TABLE[176][292] = 1;
TABLE[176][304] = 1;
TABLE[176][37] = 1;
TABLE[176][47] = 1;
TABLE[252][278] = 1;
TABLE[252][63] = 1;
TABLE[252][294] = 1;
TABLE[252][295] = 1;
TABLE[252][297] = 1;
TABLE[252][33] = 1;
TABLE[252][126] = 1;
TABLE[252][45] = 1;
TABLE[252][43] = 1;
TABLE[252][42] = 1;
TABLE[252][302] = 1;
TABLE[252][40] = 1;
TABLE[252][289] = 1;
TABLE[252][298] = 1;
TABLE[252][308] = 1;
TABLE[252][306] = 1;
TABLE[252][307] = 1;
TABLE[252][299] = 1;
TABLE[252][301] = 1;
TABLE[252][303] = 1;
TABLE[252][292] = 1;
TABLE[252][304] = 1;
TABLE[252][47] = 1;
TABLE[252][37] = 1;
TABLE[252][59] = 1;
TABLE[252][41] = 1;
TABLE[252][44] = 1;
TABLE[252][58] = 1;
TABLE[252][93] = 1;
TABLE[69][59] = 1;
TABLE[69][41] = 1;
TABLE[69][44] = 1;
TABLE[69][125] = 1;
TABLE[69][58] = 1;
TABLE[69][93] = 1;
TABLE[69][63] = 1;
TABLE[69][297] = 1;
TABLE[69][298] = 1;
TABLE[69][301] = 1;
TABLE[69][303] = 1;
TABLE[69][302] = 1;
TABLE[69][292] = 1;
TABLE[69][304] = 1;
TABLE[69][43] = 1;
TABLE[69][45] = 1;
TABLE[69][40] = 1;
TABLE[69][278] = 1;
TABLE[69][37] = 1;
TABLE[69][47] = 1;
TABLE[69][42] = 1;
TABLE[69][294] = 1;
TABLE[69][295] = 1;
TABLE[69][33] = 1;
TABLE[69][126] = 1;
TABLE[69][289] = 1;
TABLE[69][308] = 1;
TABLE[69][306] = 1;
TABLE[69][307] = 1;
TABLE[69][299] = 1;
TABLE[70][278] = 1;
TABLE[70][295] = 1;
TABLE[70][294] = 1;
TABLE[70][289] = 1;
TABLE[70][40] = 1;
TABLE[70][302] = 1;
TABLE[70][42] = 1;
TABLE[70][43] = 1;
TABLE[70][45] = 1;
TABLE[70][126] = 1;
TABLE[70][33] = 1;
TABLE[70][299] = 1;
TABLE[70][307] = 1;
TABLE[70][306] = 1;
TABLE[70][308] = 1;
TABLE[71][291] = 1;
TABLE[71][61] = 1;
TABLE[177][291] = 1;
TABLE[178][61] = 1;
TABLE[72][59] = 1;
TABLE[72][41] = 1;
TABLE[72][125] = 1;
TABLE[72][93] = 1;
TABLE[72][58] = 1;
TABLE[72][44] = 1;
TABLE[72][63] = 1;
TABLE[72][297] = 1;
TABLE[72][298] = 1;
TABLE[72][301] = 1;
TABLE[72][303] = 1;
TABLE[72][302] = 1;
TABLE[72][292] = 1;
TABLE[72][304] = 1;
TABLE[72][40] = 1;
TABLE[72][45] = 1;
TABLE[72][43] = 1;
TABLE[72][42] = 1;
TABLE[72][47] = 1;
TABLE[72][37] = 1;
TABLE[72][278] = 1;
TABLE[72][295] = 1;
TABLE[72][294] = 1;
TABLE[72][289] = 1;
TABLE[72][126] = 1;
TABLE[72][33] = 1;
TABLE[72][299] = 1;
TABLE[72][307] = 1;
TABLE[72][306] = 1;
TABLE[72][308] = 1;
TABLE[179][63] = 1;
TABLE[253][59] = 1;
TABLE[253][41] = 1;
TABLE[253][125] = 1;
TABLE[253][93] = 1;
TABLE[253][58] = 1;
TABLE[253][44] = 1;
TABLE[73][59] = 1;
TABLE[73][125] = 1;
TABLE[73][93] = 1;
TABLE[73][58] = 1;
TABLE[73][44] = 1;
TABLE[73][63] = 1;
TABLE[73][297] = 1;
TABLE[73][298] = 1;
TABLE[73][301] = 1;
TABLE[73][303] = 1;
TABLE[73][302] = 1;
TABLE[73][292] = 1;
TABLE[73][304] = 1;
TABLE[73][43] = 1;
TABLE[73][45] = 1;
TABLE[73][40] = 1;
TABLE[73][278] = 1;
TABLE[73][37] = 1;
TABLE[73][47] = 1;
TABLE[73][42] = 1;
TABLE[73][294] = 1;
TABLE[73][295] = 1;
TABLE[73][33] = 1;
TABLE[73][126] = 1;
TABLE[73][289] = 1;
TABLE[73][308] = 1;
TABLE[73][306] = 1;
TABLE[73][307] = 1;
TABLE[73][299] = 1;
TABLE[74][63] = 1;
TABLE[74][59] = 1;
TABLE[74][41] = 1;
TABLE[74][125] = 1;
TABLE[74][93] = 1;
TABLE[74][58] = 1;
TABLE[74][44] = 1;
TABLE[74][297] = 1;
TABLE[74][298] = 1;
TABLE[74][301] = 1;
TABLE[74][303] = 1;
TABLE[74][302] = 1;
TABLE[74][292] = 1;
TABLE[74][304] = 1;
TABLE[74][43] = 1;
TABLE[74][45] = 1;
TABLE[74][40] = 1;
TABLE[74][278] = 1;
TABLE[74][37] = 1;
TABLE[74][47] = 1;
TABLE[74][42] = 1;
TABLE[74][294] = 1;
TABLE[74][295] = 1;
TABLE[74][33] = 1;
TABLE[74][126] = 1;
TABLE[74][289] = 1;
TABLE[74][308] = 1;
TABLE[74][306] = 1;
TABLE[74][307] = 1;
TABLE[74][299] = 1;
TABLE[180][297] = 1;
TABLE[180][298] = 1;
TABLE[180][301] = 1;
TABLE[180][303] = 1;
TABLE[180][302] = 1;
TABLE[180][292] = 1;
TABLE[180][304] = 1;
TABLE[180][40] = 1;
TABLE[180][45] = 1;
TABLE[180][43] = 1;
TABLE[180][42] = 1;
TABLE[180][47] = 1;
TABLE[180][37] = 1;
TABLE[180][278] = 1;
TABLE[180][295] = 1;
TABLE[180][294] = 1;
TABLE[180][289] = 1;
TABLE[180][126] = 1;
TABLE[180][33] = 1;
TABLE[180][299] = 1;
TABLE[180][307] = 1;
TABLE[180][306] = 1;
TABLE[180][308] = 1;
TABLE[254][298] = 1;
TABLE[254][301] = 1;
TABLE[254][303] = 1;
TABLE[254][302] = 1;
TABLE[254][292] = 1;
TABLE[254][304] = 1;
TABLE[254][43] = 1;
TABLE[254][45] = 1;
TABLE[254][40] = 1;
TABLE[254][278] = 1;
TABLE[254][37] = 1;
TABLE[254][47] = 1;
TABLE[254][42] = 1;
TABLE[254][294] = 1;
TABLE[254][295] = 1;
TABLE[254][33] = 1;
TABLE[254][126] = 1;
TABLE[254][289] = 1;
TABLE[254][308] = 1;
TABLE[254][306] = 1;
TABLE[254][307] = 1;
TABLE[254][299] = 1;
TABLE[254][63] = 1;
TABLE[254][59] = 1;
TABLE[254][41] = 1;
TABLE[254][297] = 1;
TABLE[254][125] = 1;
TABLE[254][93] = 1;
TABLE[254][58] = 1;
TABLE[254][44] = 1;
TABLE[75][63] = 1;
TABLE[75][59] = 1;
TABLE[75][41] = 1;
TABLE[75][297] = 1;
TABLE[75][125] = 1;
TABLE[75][93] = 1;
TABLE[75][58] = 1;
TABLE[75][44] = 1;
TABLE[75][298] = 1;
TABLE[75][301] = 1;
TABLE[75][303] = 1;
TABLE[75][302] = 1;
TABLE[75][292] = 1;
TABLE[75][304] = 1;
TABLE[75][40] = 1;
TABLE[75][45] = 1;
TABLE[75][43] = 1;
TABLE[75][42] = 1;
TABLE[75][47] = 1;
TABLE[75][37] = 1;
TABLE[75][278] = 1;
TABLE[75][295] = 1;
TABLE[75][294] = 1;
TABLE[75][289] = 1;
TABLE[75][126] = 1;
TABLE[75][33] = 1;
TABLE[75][299] = 1;
TABLE[75][307] = 1;
TABLE[75][306] = 1;
TABLE[75][308] = 1;
TABLE[181][298] = 1;
TABLE[181][301] = 1;
TABLE[181][303] = 1;
TABLE[181][302] = 1;
TABLE[181][292] = 1;
TABLE[181][304] = 1;
TABLE[181][43] = 1;
TABLE[181][45] = 1;
TABLE[181][40] = 1;
TABLE[181][278] = 1;
TABLE[181][37] = 1;
TABLE[181][47] = 1;
TABLE[181][42] = 1;
TABLE[181][294] = 1;
TABLE[181][295] = 1;
TABLE[181][33] = 1;
TABLE[181][126] = 1;
TABLE[181][289] = 1;
TABLE[181][308] = 1;
TABLE[181][306] = 1;
TABLE[181][307] = 1;
TABLE[181][299] = 1;
TABLE[255][301] = 1;
TABLE[255][303] = 1;
TABLE[255][302] = 1;
TABLE[255][292] = 1;
TABLE[255][304] = 1;
TABLE[255][40] = 1;
TABLE[255][45] = 1;
TABLE[255][43] = 1;
TABLE[255][42] = 1;
TABLE[255][47] = 1;
TABLE[255][37] = 1;
TABLE[255][278] = 1;
TABLE[255][295] = 1;
TABLE[255][294] = 1;
TABLE[255][289] = 1;
TABLE[255][126] = 1;
TABLE[255][33] = 1;
TABLE[255][299] = 1;
TABLE[255][307] = 1;
TABLE[255][306] = 1;
TABLE[255][308] = 1;
TABLE[255][63] = 1;
TABLE[255][59] = 1;
TABLE[255][41] = 1;
TABLE[255][298] = 1;
TABLE[255][297] = 1;
TABLE[255][125] = 1;
TABLE[255][93] = 1;
TABLE[255][58] = 1;
TABLE[255][44] = 1;
TABLE[76][63] = 1;
TABLE[76][59] = 1;
TABLE[76][41] = 1;
TABLE[76][298] = 1;
TABLE[76][297] = 1;
TABLE[76][125] = 1;
TABLE[76][93] = 1;
TABLE[76][58] = 1;
TABLE[76][44] = 1;
TABLE[76][301] = 1;
TABLE[76][303] = 1;
TABLE[76][302] = 1;
TABLE[76][292] = 1;
TABLE[76][304] = 1;
TABLE[76][43] = 1;
TABLE[76][45] = 1;
TABLE[76][40] = 1;
TABLE[76][278] = 1;
TABLE[76][37] = 1;
TABLE[76][47] = 1;
TABLE[76][42] = 1;
TABLE[76][294] = 1;
TABLE[76][295] = 1;
TABLE[76][33] = 1;
TABLE[76][126] = 1;
TABLE[76][289] = 1;
TABLE[76][308] = 1;
TABLE[76][306] = 1;
TABLE[76][307] = 1;
TABLE[76][299] = 1;
TABLE[182][301] = 1;
TABLE[182][303] = 1;
TABLE[182][302] = 1;
TABLE[182][292] = 1;
TABLE[182][304] = 1;
TABLE[182][40] = 1;
TABLE[182][45] = 1;
TABLE[182][43] = 1;
TABLE[182][42] = 1;
TABLE[182][47] = 1;
TABLE[182][37] = 1;
TABLE[182][278] = 1;
TABLE[182][295] = 1;
TABLE[182][294] = 1;
TABLE[182][289] = 1;
TABLE[182][126] = 1;
TABLE[182][33] = 1;
TABLE[182][299] = 1;
TABLE[182][307] = 1;
TABLE[182][306] = 1;
TABLE[182][308] = 1;
TABLE[256][303] = 1;
TABLE[256][302] = 1;
TABLE[256][292] = 1;
TABLE[256][304] = 1;
TABLE[256][43] = 1;
TABLE[256][45] = 1;
TABLE[256][40] = 1;
TABLE[256][278] = 1;
TABLE[256][37] = 1;
TABLE[256][47] = 1;
TABLE[256][42] = 1;
TABLE[256][294] = 1;
TABLE[256][295] = 1;
TABLE[256][33] = 1;
TABLE[256][126] = 1;
TABLE[256][289] = 1;
TABLE[256][308] = 1;
TABLE[256][306] = 1;
TABLE[256][307] = 1;
TABLE[256][299] = 1;
TABLE[256][63] = 1;
TABLE[256][59] = 1;
TABLE[256][41] = 1;
TABLE[256][301] = 1;
TABLE[256][298] = 1;
TABLE[256][297] = 1;
TABLE[256][125] = 1;
TABLE[256][93] = 1;
TABLE[256][58] = 1;
TABLE[256][44] = 1;
TABLE[77][63] = 1;
TABLE[77][59] = 1;
TABLE[77][41] = 1;
TABLE[77][301] = 1;
TABLE[77][298] = 1;
TABLE[77][297] = 1;
TABLE[77][125] = 1;
TABLE[77][93] = 1;
TABLE[77][58] = 1;
TABLE[77][44] = 1;
TABLE[77][303] = 1;
TABLE[77][302] = 1;
TABLE[77][292] = 1;
TABLE[77][304] = 1;
TABLE[77][40] = 1;
TABLE[77][45] = 1;
TABLE[77][43] = 1;
TABLE[77][42] = 1;
TABLE[77][47] = 1;
TABLE[77][37] = 1;
TABLE[77][278] = 1;
TABLE[77][295] = 1;
TABLE[77][294] = 1;
TABLE[77][289] = 1;
TABLE[77][126] = 1;
TABLE[77][33] = 1;
TABLE[77][299] = 1;
TABLE[77][307] = 1;
TABLE[77][306] = 1;
TABLE[77][308] = 1;
TABLE[183][303] = 1;
TABLE[183][302] = 1;
TABLE[183][292] = 1;
TABLE[183][304] = 1;
TABLE[183][43] = 1;
TABLE[183][45] = 1;
TABLE[183][40] = 1;
TABLE[183][278] = 1;
TABLE[183][37] = 1;
TABLE[183][47] = 1;
TABLE[183][42] = 1;
TABLE[183][294] = 1;
TABLE[183][295] = 1;
TABLE[183][33] = 1;
TABLE[183][126] = 1;
TABLE[183][289] = 1;
TABLE[183][308] = 1;
TABLE[183][306] = 1;
TABLE[183][307] = 1;
TABLE[183][299] = 1;
TABLE[257][302] = 1;
TABLE[257][292] = 1;
TABLE[257][304] = 1;
TABLE[257][40] = 1;
TABLE[257][45] = 1;
TABLE[257][43] = 1;
TABLE[257][42] = 1;
TABLE[257][47] = 1;
TABLE[257][37] = 1;
TABLE[257][278] = 1;
TABLE[257][295] = 1;
TABLE[257][294] = 1;
TABLE[257][289] = 1;
TABLE[257][126] = 1;
TABLE[257][33] = 1;
TABLE[257][299] = 1;
TABLE[257][307] = 1;
TABLE[257][306] = 1;
TABLE[257][308] = 1;
TABLE[257][63] = 1;
TABLE[257][59] = 1;
TABLE[257][41] = 1;
TABLE[257][303] = 1;
TABLE[257][301] = 1;
TABLE[257][298] = 1;
TABLE[257][297] = 1;
TABLE[257][125] = 1;
TABLE[257][93] = 1;
TABLE[257][58] = 1;
TABLE[257][44] = 1;
TABLE[78][63] = 1;
TABLE[78][59] = 1;
TABLE[78][41] = 1;
TABLE[78][303] = 1;
TABLE[78][301] = 1;
TABLE[78][298] = 1;
TABLE[78][297] = 1;
TABLE[78][125] = 1;
TABLE[78][93] = 1;
TABLE[78][58] = 1;
TABLE[78][44] = 1;
TABLE[78][302] = 1;
TABLE[78][292] = 1;
TABLE[78][304] = 1;
TABLE[78][43] = 1;
TABLE[78][45] = 1;
TABLE[78][40] = 1;
TABLE[78][278] = 1;
TABLE[78][37] = 1;
TABLE[78][47] = 1;
TABLE[78][42] = 1;
TABLE[78][294] = 1;
TABLE[78][295] = 1;
TABLE[78][33] = 1;
TABLE[78][126] = 1;
TABLE[78][289] = 1;
TABLE[78][308] = 1;
TABLE[78][306] = 1;
TABLE[78][307] = 1;
TABLE[78][299] = 1;
TABLE[184][302] = 1;
TABLE[184][292] = 1;
TABLE[184][304] = 1;
TABLE[184][40] = 1;
TABLE[184][45] = 1;
TABLE[184][43] = 1;
TABLE[184][42] = 1;
TABLE[184][47] = 1;
TABLE[184][37] = 1;
TABLE[184][278] = 1;
TABLE[184][295] = 1;
TABLE[184][294] = 1;
TABLE[184][289] = 1;
TABLE[184][126] = 1;
TABLE[184][33] = 1;
TABLE[184][299] = 1;
TABLE[184][307] = 1;
TABLE[184][306] = 1;
TABLE[184][308] = 1;
TABLE[258][292] = 1;
TABLE[258][304] = 1;
TABLE[258][43] = 1;
TABLE[258][45] = 1;
TABLE[258][40] = 1;
TABLE[258][278] = 1;
TABLE[258][37] = 1;
TABLE[258][47] = 1;
TABLE[258][42] = 1;
TABLE[258][294] = 1;
TABLE[258][295] = 1;
TABLE[258][33] = 1;
TABLE[258][126] = 1;
TABLE[258][302] = 1;
TABLE[258][289] = 1;
TABLE[258][308] = 1;
TABLE[258][306] = 1;
TABLE[258][307] = 1;
TABLE[258][299] = 1;
TABLE[258][63] = 1;
TABLE[258][59] = 1;
TABLE[258][41] = 1;
TABLE[258][303] = 1;
TABLE[258][301] = 1;
TABLE[258][298] = 1;
TABLE[258][297] = 1;
TABLE[258][125] = 1;
TABLE[258][93] = 1;
TABLE[258][58] = 1;
TABLE[258][44] = 1;
TABLE[79][63] = 1;
TABLE[79][59] = 1;
TABLE[79][41] = 1;
TABLE[79][303] = 1;
TABLE[79][301] = 1;
TABLE[79][298] = 1;
TABLE[79][297] = 1;
TABLE[79][125] = 1;
TABLE[79][93] = 1;
TABLE[79][58] = 1;
TABLE[79][44] = 1;
TABLE[79][292] = 1;
TABLE[79][304] = 1;
TABLE[79][40] = 1;
TABLE[79][45] = 1;
TABLE[79][43] = 1;
TABLE[79][42] = 1;
TABLE[79][47] = 1;
TABLE[79][37] = 1;
TABLE[79][278] = 1;
TABLE[79][295] = 1;
TABLE[79][294] = 1;
TABLE[79][289] = 1;
TABLE[79][302] = 1;
TABLE[79][126] = 1;
TABLE[79][33] = 1;
TABLE[79][299] = 1;
TABLE[79][307] = 1;
TABLE[79][306] = 1;
TABLE[79][308] = 1;
TABLE[185][292] = 1;
TABLE[185][304] = 1;
TABLE[185][43] = 1;
TABLE[185][45] = 1;
TABLE[185][40] = 1;
TABLE[185][278] = 1;
TABLE[185][37] = 1;
TABLE[185][47] = 1;
TABLE[185][42] = 1;
TABLE[185][294] = 1;
TABLE[185][295] = 1;
TABLE[185][33] = 1;
TABLE[185][126] = 1;
TABLE[185][302] = 1;
TABLE[185][289] = 1;
TABLE[185][308] = 1;
TABLE[185][306] = 1;
TABLE[185][307] = 1;
TABLE[185][299] = 1;
TABLE[259][304] = 1;
TABLE[259][40] = 1;
TABLE[259][45] = 1;
TABLE[259][43] = 1;
TABLE[259][42] = 1;
TABLE[259][47] = 1;
TABLE[259][37] = 1;
TABLE[259][278] = 1;
TABLE[259][295] = 1;
TABLE[259][294] = 1;
TABLE[259][289] = 1;
TABLE[259][302] = 1;
TABLE[259][126] = 1;
TABLE[259][33] = 1;
TABLE[259][299] = 1;
TABLE[259][307] = 1;
TABLE[259][306] = 1;
TABLE[259][308] = 1;
TABLE[259][63] = 1;
TABLE[259][59] = 1;
TABLE[259][41] = 1;
TABLE[259][292] = 1;
TABLE[259][303] = 1;
TABLE[259][301] = 1;
TABLE[259][298] = 1;
TABLE[259][297] = 1;
TABLE[259][125] = 1;
TABLE[259][93] = 1;
TABLE[259][58] = 1;
TABLE[259][44] = 1;
TABLE[80][63] = 1;
TABLE[80][59] = 1;
TABLE[80][41] = 1;
TABLE[80][292] = 1;
TABLE[80][303] = 1;
TABLE[80][301] = 1;
TABLE[80][298] = 1;
TABLE[80][297] = 1;
TABLE[80][125] = 1;
TABLE[80][93] = 1;
TABLE[80][58] = 1;
TABLE[80][44] = 1;
TABLE[80][304] = 1;
TABLE[80][43] = 1;
TABLE[80][45] = 1;
TABLE[80][40] = 1;
TABLE[80][278] = 1;
TABLE[80][37] = 1;
TABLE[80][47] = 1;
TABLE[80][42] = 1;
TABLE[80][294] = 1;
TABLE[80][295] = 1;
TABLE[80][33] = 1;
TABLE[80][126] = 1;
TABLE[80][302] = 1;
TABLE[80][289] = 1;
TABLE[80][308] = 1;
TABLE[80][306] = 1;
TABLE[80][307] = 1;
TABLE[80][299] = 1;
TABLE[186][304] = 1;
TABLE[186][40] = 1;
TABLE[186][45] = 1;
TABLE[186][43] = 1;
TABLE[186][42] = 1;
TABLE[186][47] = 1;
TABLE[186][37] = 1;
TABLE[186][278] = 1;
TABLE[186][295] = 1;
TABLE[186][294] = 1;
TABLE[186][289] = 1;
TABLE[186][302] = 1;
TABLE[186][126] = 1;
TABLE[186][33] = 1;
TABLE[186][299] = 1;
TABLE[186][307] = 1;
TABLE[186][306] = 1;
TABLE[186][308] = 1;
TABLE[260][43] = 1;
TABLE[260][45] = 1;
TABLE[260][40] = 1;
TABLE[260][278] = 1;
TABLE[260][37] = 1;
TABLE[260][47] = 1;
TABLE[260][42] = 1;
TABLE[260][294] = 1;
TABLE[260][295] = 1;
TABLE[260][33] = 1;
TABLE[260][126] = 1;
TABLE[260][302] = 1;
TABLE[260][289] = 1;
TABLE[260][308] = 1;
TABLE[260][306] = 1;
TABLE[260][307] = 1;
TABLE[260][299] = 1;
TABLE[260][63] = 1;
TABLE[260][59] = 1;
TABLE[260][41] = 1;
TABLE[260][304] = 1;
TABLE[260][292] = 1;
TABLE[260][303] = 1;
TABLE[260][301] = 1;
TABLE[260][298] = 1;
TABLE[260][297] = 1;
TABLE[260][125] = 1;
TABLE[260][93] = 1;
TABLE[260][58] = 1;
TABLE[260][44] = 1;
TABLE[81][63] = 1;
TABLE[81][59] = 1;
TABLE[81][41] = 1;
TABLE[81][304] = 1;
TABLE[81][292] = 1;
TABLE[81][303] = 1;
TABLE[81][301] = 1;
TABLE[81][298] = 1;
TABLE[81][297] = 1;
TABLE[81][125] = 1;
TABLE[81][93] = 1;
TABLE[81][58] = 1;
TABLE[81][44] = 1;
TABLE[81][45] = 1;
TABLE[81][43] = 1;
TABLE[81][40] = 1;
TABLE[81][42] = 1;
TABLE[81][47] = 1;
TABLE[81][37] = 1;
TABLE[81][278] = 1;
TABLE[81][295] = 1;
TABLE[81][294] = 1;
TABLE[81][289] = 1;
TABLE[81][302] = 1;
TABLE[81][126] = 1;
TABLE[81][33] = 1;
TABLE[81][299] = 1;
TABLE[81][307] = 1;
TABLE[81][306] = 1;
TABLE[81][308] = 1;
TABLE[189][43] = 1;
TABLE[189][45] = 1;
TABLE[189][40] = 1;
TABLE[189][278] = 1;
TABLE[189][37] = 1;
TABLE[189][47] = 1;
TABLE[189][42] = 1;
TABLE[189][294] = 1;
TABLE[189][295] = 1;
TABLE[189][33] = 1;
TABLE[189][126] = 1;
TABLE[189][302] = 1;
TABLE[189][289] = 1;
TABLE[189][308] = 1;
TABLE[189][306] = 1;
TABLE[189][307] = 1;
TABLE[189][299] = 1;
TABLE[261][40] = 1;
TABLE[261][42] = 1;
TABLE[261][47] = 1;
TABLE[261][37] = 1;
TABLE[261][278] = 1;
TABLE[261][295] = 1;
TABLE[261][294] = 1;
TABLE[261][289] = 1;
TABLE[261][302] = 1;
TABLE[261][43] = 1;
TABLE[261][45] = 1;
TABLE[261][126] = 1;
TABLE[261][33] = 1;
TABLE[261][299] = 1;
TABLE[261][307] = 1;
TABLE[261][306] = 1;
TABLE[261][308] = 1;
TABLE[261][63] = 1;
TABLE[261][59] = 1;
TABLE[261][41] = 1;
TABLE[261][304] = 1;
TABLE[261][292] = 1;
TABLE[261][303] = 1;
TABLE[261][301] = 1;
TABLE[261][298] = 1;
TABLE[261][297] = 1;
TABLE[261][125] = 1;
TABLE[261][93] = 1;
TABLE[261][58] = 1;
TABLE[261][44] = 1;
TABLE[187][43] = 1;
TABLE[188][45] = 1;
TABLE[82][40] = 1;
TABLE[82][37] = 1;
TABLE[82][47] = 1;
TABLE[82][42] = 1;
TABLE[82][278] = 1;
TABLE[82][294] = 1;
TABLE[82][295] = 1;
TABLE[82][33] = 1;
TABLE[82][126] = 1;
TABLE[82][45] = 1;
TABLE[82][43] = 1;
TABLE[82][302] = 1;
TABLE[82][289] = 1;
TABLE[82][308] = 1;
TABLE[82][306] = 1;
TABLE[82][307] = 1;
TABLE[82][299] = 1;
TABLE[193][40] = 1;
TABLE[193][42] = 1;
TABLE[193][47] = 1;
TABLE[193][37] = 1;
TABLE[193][278] = 1;
TABLE[193][295] = 1;
TABLE[193][294] = 1;
TABLE[193][289] = 1;
TABLE[193][302] = 1;
TABLE[193][43] = 1;
TABLE[193][45] = 1;
TABLE[193][126] = 1;
TABLE[193][33] = 1;
TABLE[193][299] = 1;
TABLE[193][307] = 1;
TABLE[193][306] = 1;
TABLE[193][308] = 1;
TABLE[262][40] = 1;
TABLE[262][278] = 1;
TABLE[262][294] = 1;
TABLE[262][295] = 1;
TABLE[262][33] = 1;
TABLE[262][126] = 1;
TABLE[262][45] = 1;
TABLE[262][43] = 1;
TABLE[262][42] = 1;
TABLE[262][302] = 1;
TABLE[262][289] = 1;
TABLE[262][308] = 1;
TABLE[262][306] = 1;
TABLE[262][307] = 1;
TABLE[262][299] = 1;
TABLE[190][42] = 1;
TABLE[191][47] = 1;
TABLE[192][37] = 1;
TABLE[83][278] = 1;
TABLE[83][295] = 1;
TABLE[83][294] = 1;
TABLE[83][289] = 1;
TABLE[83][40] = 1;
TABLE[83][302] = 1;
TABLE[83][42] = 1;
TABLE[83][43] = 1;
TABLE[83][45] = 1;
TABLE[83][126] = 1;
TABLE[83][33] = 1;
TABLE[83][299] = 1;
TABLE[83][307] = 1;
TABLE[83][306] = 1;
TABLE[83][308] = 1;
TABLE[84][40] = 1;
TABLE[85][40] = 1;
TABLE[85][289] = 1;
TABLE[85][308] = 1;
TABLE[85][306] = 1;
TABLE[85][307] = 1;
TABLE[85][299] = 1;
TABLE[86][294] = 1;
TABLE[86][295] = 1;
TABLE[87][33] = 1;
TABLE[87][126] = 1;
TABLE[87][45] = 1;
TABLE[87][43] = 1;
TABLE[87][42] = 1;
TABLE[87][302] = 1;
TABLE[88][278] = 1;
TABLE[89][278] = 1;
TABLE[194][294] = 1;
TABLE[195][295] = 1;
TABLE[90][302] = 1;
TABLE[90][42] = 1;
TABLE[90][43] = 1;
TABLE[90][45] = 1;
TABLE[90][126] = 1;
TABLE[90][33] = 1;
TABLE[196][302] = 1;
TABLE[197][42] = 1;
TABLE[198][43] = 1;
TABLE[199][45] = 1;
TABLE[200][126] = 1;
TABLE[201][33] = 1;
TABLE[91][289] = 1;
TABLE[91][40] = 1;
TABLE[91][299] = 1;
TABLE[91][307] = 1;
TABLE[91][306] = 1;
TABLE[91][308] = 1;
TABLE[92][40] = 1;
TABLE[92][289] = 1;
TABLE[92][308] = 1;
TABLE[92][306] = 1;
TABLE[92][307] = 1;
TABLE[92][299] = 1;
TABLE[202][91] = 1;
TABLE[204][40] = 1;
TABLE[205][46] = 1;
TABLE[206][296] = 1;
TABLE[207][294] = 1;
TABLE[208][295] = 1;
TABLE[203][41] = 1;
TABLE[203][44] = 1;
TABLE[203][278] = 1;
TABLE[203][295] = 1;
TABLE[203][294] = 1;
TABLE[203][63] = 1;
TABLE[203][289] = 1;
TABLE[203][40] = 1;
TABLE[203][302] = 1;
TABLE[203][42] = 1;
TABLE[203][43] = 1;
TABLE[203][45] = 1;
TABLE[203][126] = 1;
TABLE[203][33] = 1;
TABLE[203][297] = 1;
TABLE[203][299] = 1;
TABLE[203][307] = 1;
TABLE[203][306] = 1;
TABLE[203][308] = 1;
TABLE[203][298] = 1;
TABLE[203][301] = 1;
TABLE[203][303] = 1;
TABLE[203][292] = 1;
TABLE[203][304] = 1;
TABLE[203][37] = 1;
TABLE[203][47] = 1;
TABLE[263][41] = 1;
TABLE[93][299] = 1;
TABLE[94][308] = 1;
TABLE[94][306] = 1;
TABLE[94][307] = 1;
TABLE[94][299] = 1;
TABLE[95][289] = 1;
TABLE[96][40] = 1;
TABLE[97][41] = 1;
TABLE[97][44] = 1;
TABLE[97][278] = 1;
TABLE[97][63] = 1;
TABLE[97][294] = 1;
TABLE[97][295] = 1;
TABLE[97][297] = 1;
TABLE[97][33] = 1;
TABLE[97][126] = 1;
TABLE[97][45] = 1;
TABLE[97][43] = 1;
TABLE[97][42] = 1;
TABLE[97][302] = 1;
TABLE[97][40] = 1;
TABLE[97][289] = 1;
TABLE[97][298] = 1;
TABLE[97][308] = 1;
TABLE[97][306] = 1;
TABLE[97][307] = 1;
TABLE[97][299] = 1;
TABLE[97][301] = 1;
TABLE[97][303] = 1;
TABLE[97][292] = 1;
TABLE[97][304] = 1;
TABLE[97][47] = 1;
TABLE[97][37] = 1;
TABLE[209][44] = 1;
TABLE[209][278] = 1;
TABLE[209][295] = 1;
TABLE[209][294] = 1;
TABLE[209][63] = 1;
TABLE[209][289] = 1;
TABLE[209][40] = 1;
TABLE[209][302] = 1;
TABLE[209][42] = 1;
TABLE[209][43] = 1;
TABLE[209][45] = 1;
TABLE[209][126] = 1;
TABLE[209][33] = 1;
TABLE[209][297] = 1;
TABLE[209][299] = 1;
TABLE[209][307] = 1;
TABLE[209][306] = 1;
TABLE[209][308] = 1;
TABLE[209][298] = 1;
TABLE[209][301] = 1;
TABLE[209][303] = 1;
TABLE[209][292] = 1;
TABLE[209][304] = 1;
TABLE[209][37] = 1;
TABLE[209][47] = 1;
TABLE[264][278] = 1;
TABLE[264][63] = 1;
TABLE[264][294] = 1;
TABLE[264][295] = 1;
TABLE[264][297] = 1;
TABLE[264][33] = 1;
TABLE[264][126] = 1;
TABLE[264][45] = 1;
TABLE[264][43] = 1;
TABLE[264][42] = 1;
TABLE[264][302] = 1;
TABLE[264][40] = 1;
TABLE[264][289] = 1;
TABLE[264][298] = 1;
TABLE[264][308] = 1;
TABLE[264][306] = 1;
TABLE[264][307] = 1;
TABLE[264][299] = 1;
TABLE[264][301] = 1;
TABLE[264][303] = 1;
TABLE[264][292] = 1;
TABLE[264][304] = 1;
TABLE[264][47] = 1;
TABLE[264][37] = 1;
TABLE[264][41] = 1;
TABLE[264][44] = 1;
TABLE[98][308] = 1;
TABLE[99][306] = 1;
TABLE[100][307] = 1;
TABLE[101][299] = 1;
TABLE[102][299] = 1;
}

extern int yydirset();
int yydirset(i,j)
   int i,j;
{
   return TABLE[i][j];
}
int yytransparent(n)
   int n;
{
   switch(n) {
      case 1: return 1; break;
      case 6: return 1; break;
      case 10: return 1; break;
      case 18: return 1; break;
      case 26: return 1; break;
      case 33: return 1; break;
      case 40: return 1; break;
      case 47: return 0; break;
      case 53: return 1; break;
      case 60: return 1; break;
      case 65: return 1; break;
      case 72: return 0; break;
      case 77: return 0; break;
      case 89: return 1; break;
      case 96: return 0; break;
      case 100: return 0; break;
      case 120: return 0; break;
      case 132: return 0; break;
      case 168: return 0; break;
      case 172: return 0; break;
      case 180: return 0; break;
      case 193: return 1; break;
      case 200: return 0; break;
      case 204: return 0; break;
      case 212: return 1; break;
      case 217: return 1; break;
      case 224: return 1; break;
      case 229: return 1; break;
      case 237: return 1; break;
      case 242: return 1; break;
      case 250: return 0; break;
      case 256: return 0; break;
      case 261: return 0; break;
      case 269: return 1; break;
      case 276: return 1; break;
      case 281: return 1; break;
      case 289: return 1; break;
      case 299: return 1; break;
      case 306: return 0; break;
      case 319: return 1; break;
      case 326: return 1; break;
      case 331: return 1; break;
      case 339: return 0; break;
      case 344: return 1; break;
      case 352: return 1; break;
      case 357: return 1; break;
      case 364: return 0; break;
      case 379: return 0; break;
      case 397: return 1; break;
      case 404: return 1; break;
      case 411: return 0; break;
      case 417: return 1; break;
      case 424: return 1; break;
      case 431: return 1; break;
      case 436: return 1; break;
      case 443: return 1; break;
      case 448: return 1; break;
      case 456: return 1; break;
      case 461: return 1; break;
      case 469: return 0; break;
      case 474: return 1; break;
      case 482: return 1; break;
      case 489: return 1; break;
      case 494: return 1; break;
      case 502: return 1; break;
      case 513: return 1; break;
      case 520: return 1; break;
      case 525: return 1; break;
      case 533: return 0; break;
      case 538: return 1; break;
      case 545: return 1; break;
      case 554: return 1; break;
      case 561: return 1; break;
      case 572: return 1; break;
      case 579: return 0; break;
      case 591: return 1; break;
      case 598: return 1; break;
      case 605: return 0; break;
      case 609: return 1; break;
      case 633: return 0; break;
      case 652: return 1; break;
      case 657: return 1; break;
      case 664: return 0; break;
      case 671: return 1; break;
      case 678: return 1; break;
      case 685: return 1; break;
      case 690: return 1; break;
      case 697: return 0; break;
      case 714: return 1; break;
      case 722: return 0; break;
      case 752: return 1; break;
      case 759: return 1; break;
      case 766: return 1; break;
      case 773: return 0; break;
      case 795: return 1; break;
      case 802: return 1; break;
      case 807: return 1; break;
      case 815: return 1; break;
      case 825: return 0; break;
      case 829: return 0; break;
      case 837: return 1; break;
      case 842: return 1; break;
      case 852: return 1; break;
      case 856: return 1; break;
      case 861: return 1; break;
      case 869: return 1; break;
      case 874: return 1; break;
      case 882: return 1; break;
      case 887: return 1; break;
      case 895: return 1; break;
      case 900: return 1; break;
      case 908: return 1; break;
      case 913: return 1; break;
      case 921: return 1; break;
      case 926: return 1; break;
      case 934: return 1; break;
      case 939: return 1; break;
      case 947: return 1; break;
      case 952: return 1; break;
      case 960: return 0; break;
      case 968: return 1; break;
      case 973: return 1; break;
      case 981: return 0; break;
      case 993: return 0; break;
      case 1004: return 0; break;
      case 1030: return 0; break;
      case 1038: return 0; break;
      case 1042: return 0; break;
      case 1066: return 0; break;
      case 1075: return 0; break;
      case 1105: return 1; break;
      case 1112: return 0; break;
      case 1130: return 1; break;
      case 1135: return 1; break;
      case 1143: return 0; break;
      case 1159: return 0; break;
   }
}
char * yyprintname(n)
   int n;
{
   if (n <= 50000)
      switch(n) {
         case 1: return "YYSTART"; break;
         case 6: return "translation_unit"; break;
         case 10: return "Subphrase"; break;
         case 18: return "external_declaration"; break;
         case 26: return "function_definition"; break;
         case 33: return "Subphrase"; break;
         case 40: return "Subphrase"; break;
         case 47: return "declaration"; break;
         case 53: return "Subphrase"; break;
         case 60: return "declaration_list"; break;
         case 65: return "Subphrase"; break;
         case 72: return "declaration_specifiers"; break;
         case 77: return "Subphrase"; break;
         case 89: return "Subphrase"; break;
         case 96: return "storage_class_specifier"; break;
         case 100: return "Subphrase"; break;
         case 120: return "type_specifier"; break;
         case 132: return "Subphrase"; break;
         case 168: return "type_qualifier"; break;
         case 172: return "Subphrase"; break;
         case 180: return "struct_or_union_specifier"; break;
         case 193: return "Subphrase"; break;
         case 200: return "struct_or_union"; break;
         case 204: return "Subphrase"; break;
         case 212: return "struct_declaration_list"; break;
         case 217: return "Subphrase"; break;
         case 224: return "init_declarator_list"; break;
         case 229: return "Subphrase"; break;
         case 237: return "init_declarator"; break;
         case 242: return "Subphrase"; break;
         case 250: return "struct_declaration"; break;
         case 256: return "specifier_qualifier_list"; break;
         case 261: return "Subphrase"; break;
         case 269: return "Subphrase"; break;
         case 276: return "struct_declarator_list"; break;
         case 281: return "Subphrase"; break;
         case 289: return "struct_declarator"; break;
         case 299: return "Subphrase"; break;
         case 306: return "enum_specifier"; break;
         case 319: return "Subphrase"; break;
         case 326: return "enumerator_list"; break;
         case 331: return "Subphrase"; break;
         case 339: return "enumerator"; break;
         case 344: return "Subphrase"; break;
         case 352: return "declarator"; break;
         case 357: return "Subphrase"; break;
         case 364: return "direct_declarator"; break;
         case 379: return "Subphrase"; break;
         case 397: return "Subphrase"; break;
         case 404: return "Subphrase"; break;
         case 411: return "pointer"; break;
         case 417: return "Subphrase"; break;
         case 424: return "Subphrase"; break;
         case 431: return "type_qualifier_list"; break;
         case 436: return "Subphrase"; break;
         case 443: return "parameter_type_list"; break;
         case 448: return "Subphrase"; break;
         case 456: return "parameter_list"; break;
         case 461: return "Subphrase"; break;
         case 469: return "parameter_declaration"; break;
         case 474: return "Subphrase"; break;
         case 482: return "Subphrase"; break;
         case 489: return "identifier_list"; break;
         case 494: return "Subphrase"; break;
         case 502: return "initializer"; break;
         case 513: return "Subphrase"; break;
         case 520: return "initializer_list"; break;
         case 525: return "Subphrase"; break;
         case 533: return "type_name"; break;
         case 538: return "Subphrase"; break;
         case 545: return "abstract_declarator"; break;
         case 554: return "Subphrase"; break;
         case 561: return "direct_abstract_declarator"; break;
         case 572: return "Subphrase"; break;
         case 579: return "Subphrase"; break;
         case 591: return "Subphrase"; break;
         case 598: return "Subphrase"; break;
         case 605: return "typedef_name"; break;
         case 609: return "statement"; break;
         case 633: return "labeled_statement"; break;
         case 652: return "expression_statement"; break;
         case 657: return "Subphrase"; break;
         case 664: return "compound_statement"; break;
         case 671: return "Subphrase"; break;
         case 678: return "Subphrase"; break;
         case 685: return "statement_list"; break;
         case 690: return "Subphrase"; break;
         case 697: return "selection_statement"; break;
         case 714: return "Subphrase"; break;
         case 722: return "iteration_statement"; break;
         case 752: return "Subphrase"; break;
         case 759: return "Subphrase"; break;
         case 766: return "Subphrase"; break;
         case 773: return "jump_statement"; break;
         case 795: return "Subphrase"; break;
         case 802: return "expression"; break;
         case 807: return "Subphrase"; break;
         case 815: return "assignment_expression"; break;
         case 825: return "assignment_operator"; break;
         case 829: return "Subphrase"; break;
         case 837: return "conditional_expression"; break;
         case 842: return "Subphrase"; break;
         case 852: return "constant_expression"; break;
         case 856: return "logical_OR_expression"; break;
         case 861: return "Subphrase"; break;
         case 869: return "logical_AND_expression"; break;
         case 874: return "Subphrase"; break;
         case 882: return "inclusive_OR_expression"; break;
         case 887: return "Subphrase"; break;
         case 895: return "exclusive_OR_expression"; break;
         case 900: return "Subphrase"; break;
         case 908: return "AND_expression"; break;
         case 913: return "Subphrase"; break;
         case 921: return "equality_expression"; break;
         case 926: return "Subphrase"; break;
         case 934: return "shift_expression"; break;
         case 939: return "Subphrase"; break;
         case 947: return "additive_expression"; break;
         case 952: return "Subphrase"; break;
         case 960: return "Subphrase"; break;
         case 968: return "multiplicative_expression"; break;
         case 973: return "Subphrase"; break;
         case 981: return "Subphrase"; break;
         case 993: return "cast_expression"; break;
         case 1004: return "unary_expression"; break;
         case 1030: return "Subphrase"; break;
         case 1038: return "unary_operator"; break;
         case 1042: return "Subphrase"; break;
         case 1066: return "postfix_expression"; break;
         case 1075: return "Subphrase"; break;
         case 1105: return "Subphrase"; break;
         case 1112: return "primary_expression"; break;
         case 1130: return "argument_expression_list"; break;
         case 1135: return "Subphrase"; break;
         case 1143: return "constant"; break;
         case 1159: return "id"; break;
   }
   else 
      switch(n-50000) {
         case 308: return "INTCONST"; break;
         case 307: return "FLOATCONST"; break;
         case 306: return "CHARACTER"; break;
         case 305: return "INCLUDE"; break;
         case 304: return "SHIFT"; break;
         case 303: return "BIT_XOR"; break;
         case 302: return "BIT_AND"; break;
         case 301: return "BIT_OR"; break;
         case 300: return "PREPROC"; break;
         case 299: return "IDENTIFIER"; break;
         case 298: return "LOGICAL_AND"; break;
         case 297: return "LOGICAL_OR"; break;
         case 296: return "PTR_OP"; break;
         case 295: return "DEC_OP"; break;
         case 294: return "INC_OP"; break;
         case 293: return "ARIT_OP"; break;
         case 292: return "COMPARE"; break;
         case 291: return "ASSIGN"; break;
         case 290: return "ELLIPSIS"; break;
         case 289: return "STRING"; break;
         case 288: return "CONSTANT"; break;
         case 287: return "WHILE"; break;
         case 286: return "VOLATILE"; break;
         case 285: return "VOID"; break;
         case 284: return "UNSIGNED"; break;
         case 283: return "UNION"; break;
         case 282: return "TYPEDEF"; break;
         case 281: return "SWITCH"; break;
         case 280: return "STRUCT"; break;
         case 279: return "STATIC"; break;
         case 278: return "SIZEOF"; break;
         case 277: return "SIGNED"; break;
         case 276: return "SHORT"; break;
         case 275: return "RETURN"; break;
         case 274: return "REGISTER"; break;
         case 273: return "LONG"; break;
         case 272: return "INT"; break;
         case 271: return "IF"; break;
         case 270: return "GOTO"; break;
         case 269: return "FOR"; break;
         case 268: return "FLOAT"; break;
         case 267: return "EXTERN"; break;
         case 266: return "ENUM"; break;
         case 265: return "ELSE"; break;
         case 264: return "DOUBLE"; break;
         case 263: return "DO"; break;
         case 262: return "DEFAULT"; break;
         case 261: return "CONTINUE"; break;
         case 260: return "CONST"; break;
         case 259: return "CHAR"; break;
         case 258: return "CASE"; break;
         case 257: return "BREAK"; break;
         case 256: return "AUTO"; break;
      }
   return "special_character";
}
