#line 1 "ass2.acc"

	#include <stdio.h>
	#include <stdlib.h>
	
	#include "parser.h"
	
	extern FILE * f;
	
	void fprintStringConst(FILE * f, char * s){
		while(*s){
			if(*s == '\\') fputs("\\textbackslash ", f);
			else if(*s == '%') fputs("\\%", f);
			else if(*s == '$') fputs("\\$", f);
			else if(*s == '>') fputs("$>$", f);
			else if(*s == '<') fputs("$<$", f);
			else if(*s == '{') fputs("\\{", f);
			else if(*s == '}') fputs("\\}", f);
			else if(*s == '&') fputs("\\&", f);
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
			
			case ASSIGN_AND: fputs("\\ $\\&=$\\ ", f); break;
			case ASSIGN_DIVIDE: fputs("\\ $/=$\\ ", f); break;
			case ASSIGN_MINUS: fputs("\\ $-=$\\ ", f); break;
			case ASSIGN_MOD: fputs("\\ $\\%=$\\ ", f); break;
			case ASSIGN_OR: fputs("\\ $|=$\\ ", f); break;
			case ASSIGN_PLUS: fputs("\\ $+=$\\ ", f); break;
			case ASSIGN_SHLEFT: fputs("\\ $<<=$\\ ", f); break;
			case ASSIGN_SHRIGHT: fputs("\\ $>>=$\\ ", f); break;
			case ASSIGN_XOR: fputs("\\ $\\^=$\\ ", f); break;
		}
	}
	
	#define PRCH prCh(f, yylval.c)
	#define PRCHS PRCH, fputs("\\ ", f)
	#define SPRCHS fputs("\\ ", f), PRCHS
	#define PRS fprintStringConst(f, yylval.s)
	#define PRKW fprintf(f, "{\\bf %s} ", yylval.s)

# line 81 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 105: {
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
         case 106: {
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
      case 107: {
         declaration_specifiers();
         } break;
      default: ;
      }
      declarator();
      switch (yyselect()) {
      case 108: {
         declaration_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 109: {
         get_lexval();
#line 98 "ass2.acc"
 fputs(";\\\\\\\n", f); 
# line 145 "yygrammar.c"
         } break;
      case 110: {
         compound_statement();
#line 98 "ass2.acc"
 fputs("\\\\\n", f); 
# line 151 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

declaration ()
{
   switch(yyselect()) {
   case 5: {
      declaration_specifiers();
      switch (yyselect()) {
      case 111: {
         init_declarator_list();
         } break;
      default: ;
      }
      get_lexval();
#line 102 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 173 "yygrammar.c"
      } break;
   }
}

declaration_list ()
{
   switch(yyselect()) {
   case 6: {
      declaration();
      while (1) {
         switch (yyselect()) {
         case 112: {
            declaration();
            } break;
         default: goto yy2;
         }
      }
      yy2: ;
      } break;
   }
}

declaration_specifiers ()
{
   switch(yyselect()) {
   case 7: {
      while (1) {
         switch (yyselect()) {
         case 113: {
            storage_class_specifier();
            } break;
         case 114: {
            type_specifier();
            } break;
         case 115: {
            type_qualifier();
            } break;
         default: goto yy3;
         }
      }
      yy3: ;
#line 110 "ass2.acc"
 fputc(' ', f); 
# line 217 "yygrammar.c"
      } break;
   }
}

storage_class_specifier ()
{
   switch(yyselect()) {
   case 8: {
      switch (yyselect()) {
      case 116: {
         get_lexval();
         } break;
      case 117: {
         get_lexval();
         } break;
      case 118: {
         get_lexval();
         } break;
      case 119: {
         get_lexval();
         } break;
      case 120: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 118 "ass2.acc"
 PRKW; 
# line 246 "yygrammar.c"
      } break;
   }
}

type_specifier ()
{
   switch(yyselect()) {
   case 9: {
      switch (yyselect()) {
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
      case 127: {
         get_lexval();
         } break;
      case 128: {
         get_lexval();
         } break;
      case 129: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 131 "ass2.acc"
 PRKW; 
# line 287 "yygrammar.c"
      } break;
   case 10: {
      struct_or_union_specifier();
      } break;
   case 11: {
      enum_specifier();
      } break;
   case 12: {
      id();
      } break;
   }
}

type_qualifier ()
{
   switch(yyselect()) {
   case 13: {
      switch (yyselect()) {
      case 130: {
         get_lexval();
         } break;
      case 131: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 138 "ass2.acc"
 PRKW; 
# line 316 "yygrammar.c"
      } break;
   }
}

struct_or_union_specifier ()
{
   switch(yyselect()) {
   case 14: {
      struct_or_union();
      switch (yyselect()) {
      case 132: {
         id();
         } break;
      default: ;
      }
      get_lexval();
#line 142 "ass2.acc"
 fputs("\\{\\\\\n", f); 
# line 335 "yygrammar.c"
      struct_declaration_list();
      get_lexval();
#line 142 "ass2.acc"
 fputs("\\}\\\\\n", f); 
# line 340 "yygrammar.c"
      } break;
   case 15: {
      struct_or_union();
      id();
      } break;
   }
}

struct_or_union ()
{
   switch(yyselect()) {
   case 16: {
      switch (yyselect()) {
      case 133: {
         get_lexval();
         } break;
      case 134: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 147 "ass2.acc"
 PRKW; 
# line 364 "yygrammar.c"
      } break;
   }
}

struct_declaration_list ()
{
   switch(yyselect()) {
   case 17: {
      switch (yyselect()) {
      case 135: {
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
   case 18: {
      switch (yyselect()) {
      case 136: {
         init_declarator_list();
         get_lexval();
#line 155 "ass2.acc"
 PRCHS; 
# line 394 "yygrammar.c"
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
   case 19: {
      switch (yyselect()) {
      case 137: {
         declarator();
         get_lexval();
#line 159 "ass2.acc"
 SPRCHS; 
# line 413 "yygrammar.c"
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
   case 20: {
      specifier_qualifier_list();
      struct_declarator_list();
      get_lexval();
#line 163 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 431 "yygrammar.c"
      } break;
   }
}

specifier_qualifier_list ()
{
   switch(yyselect()) {
   case 21: {
      switch (yyselect()) {
      case 138: {
         type_specifier();
         } break;
      case 139: {
         type_qualifier();
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 140: {
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
   case 22: {
      switch (yyselect()) {
      case 141: {
         struct_declarator_list();
         get_lexval();
#line 171 "ass2.acc"
 PRCHS; 
# line 469 "yygrammar.c"
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
   case 23: {
      declarator();
      } break;
   case 24: {
      switch (yyselect()) {
      case 142: {
         declarator();
         } break;
      default: ;
      }
      get_lexval();
#line 176 "ass2.acc"
 PRCH; 
# line 494 "yygrammar.c"
      constant_expression();
      } break;
   }
}

enum_specifier ()
{
   switch(yyselect()) {
   case 25: {
      get_lexval();
#line 180 "ass2.acc"
 PRKW; 
# line 507 "yygrammar.c"
      switch (yyselect()) {
      case 143: {
         id();
         } break;
      default: ;
      }
#line 180 "ass2.acc"
 fputs("\\{\\\\\n", f); 
# line 516 "yygrammar.c"
      get_lexval();
      enumerator_list();
      get_lexval();
#line 180 "ass2.acc"
 fputs("\\}\\\\\n", f); 
# line 522 "yygrammar.c"
      } break;
   case 26: {
      get_lexval();
#line 181 "ass2.acc"
 PRKW; 
# line 528 "yygrammar.c"
      id();
      } break;
   }
}

enumerator_list ()
{
   switch(yyselect()) {
   case 27: {
      switch (yyselect()) {
      case 144: {
         enumerator_list();
         get_lexval();
#line 185 "ass2.acc"
 PRCHS; 
# line 544 "yygrammar.c"
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
   case 28: {
      id();
      switch (yyselect()) {
      case 145: {
         get_lexval();
#line 189 "ass2.acc"
 SPRCHS; 
# line 563 "yygrammar.c"
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
   case 29: {
      switch (yyselect()) {
      case 146: {
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
   case 30: {
      id();
      } break;
   case 31: {
      get_lexval();
#line 198 "ass2.acc"
 PRCH; 
# line 597 "yygrammar.c"
      declarator();
      get_lexval();
#line 198 "ass2.acc"
 PRCH; 
# line 602 "yygrammar.c"
      } break;
   case 32: {
      direct_declarator();
      switch (yyselect()) {
      case 148: {
         get_lexval();
#line 199 "ass2.acc"
 PRCH; 
# line 611 "yygrammar.c"
         switch (yyselect()) {
         case 147: {
            constant_expression();
            } break;
         default: ;
         }
         get_lexval();
#line 199 "ass2.acc"
 PRCH; 
# line 621 "yygrammar.c"
         } break;
      case 149: {
         get_lexval();
#line 199 "ass2.acc"
 PRCH; 
# line 627 "yygrammar.c"
         parameter_type_list();
         get_lexval();
#line 199 "ass2.acc"
 PRCH; 
# line 632 "yygrammar.c"
         } break;
      case 151: {
         get_lexval();
#line 199 "ass2.acc"
 PRCH; 
# line 638 "yygrammar.c"
         switch (yyselect()) {
         case 150: {
            identifier_list();
            } break;
         default: ;
         }
         get_lexval();
#line 199 "ass2.acc"
 PRCH; 
# line 648 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

pointer ()
{
   switch(yyselect()) {
   case 33: {
      get_lexval();
#line 203 "ass2.acc"
 PRCH; 
# line 663 "yygrammar.c"
      switch (yyselect()) {
      case 152: {
         type_qualifier_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 153: {
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
   case 34: {
      switch (yyselect()) {
      case 154: {
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
   case 35: {
      parameter_list();
      switch (yyselect()) {
      case 155: {
         get_lexval();
#line 211 "ass2.acc"
 PRCHS; 
# line 705 "yygrammar.c"
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
   case 36: {
      switch (yyselect()) {
      case 156: {
         parameter_list();
         get_lexval();
#line 215 "ass2.acc"
 PRCHS; 
# line 724 "yygrammar.c"
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
   case 37: {
      declaration_specifiers();
      switch (yyselect()) {
      case 157: {
         declarator();
         } break;
      case 159: {
         switch (yyselect()) {
         case 158: {
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
   case 38: {
      switch (yyselect()) {
      case 160: {
         identifier_list();
         get_lexval();
#line 223 "ass2.acc"
 PRCHS; 
# line 766 "yygrammar.c"
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
   case 39: {
      assignment_expression();
      } break;
   case 40: {
      get_lexval();
#line 228 "ass2.acc"
 fputs("\\{", f); 
# line 785 "yygrammar.c"
      initializer_list();
      switch (yyselect()) {
      case 161: {
         get_lexval();
         } break;
      default: ;
      }
      get_lexval();
#line 228 "ass2.acc"
 fputs("\\}", f); 
# line 796 "yygrammar.c"
      } break;
   }
}

initializer_list ()
{
   switch(yyselect()) {
   case 41: {
      switch (yyselect()) {
      case 162: {
         initializer_list();
         get_lexval();
#line 232 "ass2.acc"
 PRCHS; 
# line 811 "yygrammar.c"
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
   case 42: {
      specifier_qualifier_list();
      switch (yyselect()) {
      case 163: {
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
   case 43: {
      pointer();
      } break;
   case 44: {
      switch (yyselect()) {
      case 164: {
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
   case 45: {
      get_lexval();
#line 245 "ass2.acc"
 PRCH; 
# line 860 "yygrammar.c"
      abstract_declarator();
      get_lexval();
#line 245 "ass2.acc"
 PRCH; 
# line 865 "yygrammar.c"
      } break;
   case 46: {
      switch (yyselect()) {
      case 165: {
         direct_abstract_declarator();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 167: {
         get_lexval();
#line 246 "ass2.acc"
 PRCH; 
# line 879 "yygrammar.c"
         switch (yyselect()) {
         case 166: {
            constant_expression();
            } break;
         default: ;
         }
         get_lexval();
#line 246 "ass2.acc"
 PRCH; 
# line 889 "yygrammar.c"
         } break;
      case 169: {
         get_lexval();
#line 246 "ass2.acc"
 PRCH; 
# line 895 "yygrammar.c"
         switch (yyselect()) {
         case 168: {
            parameter_type_list();
            } break;
         default: ;
         }
         get_lexval();
#line 246 "ass2.acc"
 PRCH; 
# line 905 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

typedef_name ()
{
   switch(yyselect()) {
   case 47: {
      id();
      } break;
   }
}

statement ()
{
   switch(yyselect()) {
   case 48: {
      labeled_statement();
      } break;
   case 49: {
      expression_statement();
      } break;
   case 50: {
      compound_statement();
      } break;
   case 51: {
      selection_statement();
      } break;
   case 52: {
      iteration_statement();
      } break;
   case 53: {
      jump_statement();
      } break;
   }
}

labeled_statement ()
{
   switch(yyselect()) {
   case 54: {
      id();
      get_lexval();
#line 263 "ass2.acc"
 PRCH; 
# line 954 "yygrammar.c"
      statement();
      } break;
   case 55: {
      get_lexval();
#line 264 "ass2.acc"
 PRKW; 
# line 961 "yygrammar.c"
      constant_expression();
      get_lexval();
#line 264 "ass2.acc"
 PRCH; 
# line 966 "yygrammar.c"
      statement();
      } break;
   case 56: {
      get_lexval();
#line 265 "ass2.acc"
 PRKW; 
# line 973 "yygrammar.c"
      get_lexval();
#line 265 "ass2.acc"
 PRCH; 
# line 977 "yygrammar.c"
      statement();
      } break;
   }
}

expression_statement ()
{
   switch(yyselect()) {
   case 57: {
      switch (yyselect()) {
      case 170: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 269 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 996 "yygrammar.c"
      } break;
   }
}

compound_statement ()
{
   switch(yyselect()) {
   case 58: {
      get_lexval();
#line 273 "ass2.acc"
 fputs("\\{\\+\\\\\n", f); 
# line 1008 "yygrammar.c"
      switch (yyselect()) {
      case 171: {
         declaration_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 172: {
         statement_list();
         } break;
      default: ;
      }
      get_lexval();
#line 273 "ass2.acc"
 fputs("\\<\\}\\-\\\\\n", f); 
# line 1024 "yygrammar.c"
      } break;
   }
}

statement_list ()
{
   switch(yyselect()) {
   case 59: {
      switch (yyselect()) {
      case 173: {
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
   case 60: {
      get_lexval();
#line 281 "ass2.acc"
 PRKW; 
# line 1051 "yygrammar.c"
      get_lexval();
#line 281 "ass2.acc"
 PRCH; 
# line 1055 "yygrammar.c"
      expression();
      get_lexval();
#line 281 "ass2.acc"
 PRCH; 
# line 1060 "yygrammar.c"
      statement();
      switch (yyselect()) {
      case 174: {
         get_lexval();
#line 281 "ass2.acc"
 PRKW; 
# line 1067 "yygrammar.c"
         statement();
         } break;
      default: ;
      }
      } break;
   case 61: {
      get_lexval();
#line 282 "ass2.acc"
 PRKW; 
# line 1077 "yygrammar.c"
      get_lexval();
#line 282 "ass2.acc"
 PRCH; 
# line 1081 "yygrammar.c"
      expression();
      get_lexval();
#line 282 "ass2.acc"
 PRCH; 
# line 1086 "yygrammar.c"
      statement();
      } break;
   }
}

iteration_statement ()
{
   switch(yyselect()) {
   case 62: {
      get_lexval();
#line 286 "ass2.acc"
 PRKW; 
# line 1099 "yygrammar.c"
      get_lexval();
#line 286 "ass2.acc"
 PRCH; 
# line 1103 "yygrammar.c"
      expression();
      get_lexval();
#line 286 "ass2.acc"
 PRCH; 
# line 1108 "yygrammar.c"
      statement();
      } break;
   case 63: {
      get_lexval();
#line 287 "ass2.acc"
 PRKW; 
# line 1115 "yygrammar.c"
      statement();
      get_lexval();
#line 287 "ass2.acc"
 PRKW; 
# line 1120 "yygrammar.c"
      get_lexval();
#line 287 "ass2.acc"
 PRCH; 
# line 1124 "yygrammar.c"
      expression();
      get_lexval();
#line 287 "ass2.acc"
 PRCH; 
# line 1129 "yygrammar.c"
      get_lexval();
#line 287 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 1133 "yygrammar.c"
      } break;
   case 64: {
      get_lexval();
#line 288 "ass2.acc"
 PRKW; 
# line 1139 "yygrammar.c"
      get_lexval();
#line 288 "ass2.acc"
 PRCH; 
# line 1143 "yygrammar.c"
      switch (yyselect()) {
      case 175: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 288 "ass2.acc"
 PRCHS; 
# line 1153 "yygrammar.c"
      switch (yyselect()) {
      case 176: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 288 "ass2.acc"
 PRCHS; 
# line 1163 "yygrammar.c"
      switch (yyselect()) {
      case 177: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 288 "ass2.acc"
 PRCH; 
# line 1173 "yygrammar.c"
      statement();
      } break;
   }
}

jump_statement ()
{
   switch(yyselect()) {
   case 65: {
      get_lexval();
#line 292 "ass2.acc"
 PRKW; 
# line 1186 "yygrammar.c"
      id();
      get_lexval();
#line 292 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 1191 "yygrammar.c"
      } break;
   case 66: {
      get_lexval();
#line 293 "ass2.acc"
 PRKW; 
# line 1197 "yygrammar.c"
      get_lexval();
#line 293 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 1201 "yygrammar.c"
      } break;
   case 67: {
      get_lexval();
#line 294 "ass2.acc"
 PRKW; 
# line 1207 "yygrammar.c"
      get_lexval();
#line 294 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 1211 "yygrammar.c"
      } break;
   case 68: {
      get_lexval();
#line 295 "ass2.acc"
 PRKW; 
# line 1217 "yygrammar.c"
      switch (yyselect()) {
      case 178: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 295 "ass2.acc"
 printf("Return\n"); fputs(";\\\\\n", f); 
# line 1227 "yygrammar.c"
      } break;
   }
}

expression ()
{
   switch(yyselect()) {
   case 69: {
      switch (yyselect()) {
      case 179: {
         expression();
         get_lexval();
#line 299 "ass2.acc"
 PRCHS; 
# line 1242 "yygrammar.c"
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
   case 70: {
      conditional_expression();
      } break;
   case 71: {
      unary_expression();
      assignment_operator();
      assignment_expression();
      } break;
   }
}

assignment_operator ()
{
   switch(yyselect()) {
   case 72: {
      get_lexval();
#line 308 "ass2.acc"
 fprintCompare(f, yylval.subtype); 
# line 1272 "yygrammar.c"
      } break;
   case 73: {
      get_lexval();
#line 309 "ass2.acc"
 PRCHS; 
# line 1278 "yygrammar.c"
      } break;
   }
}

conditional_expression ()
{
   switch(yyselect()) {
   case 74: {
      logical_OR_expression();
      switch (yyselect()) {
      case 180: {
         get_lexval();
#line 313 "ass2.acc"
 PRCH; 
# line 1293 "yygrammar.c"
         expression();
         get_lexval();
#line 313 "ass2.acc"
 PRCH; 
# line 1298 "yygrammar.c"
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
   case 75: {
      conditional_expression();
      } break;
   }
}

logical_OR_expression ()
{
   switch(yyselect()) {
   case 76: {
      switch (yyselect()) {
      case 181: {
         logical_OR_expression();
         get_lexval();
#line 321 "ass2.acc"
 fputs("\\ $\\vee$\\ ", f); 
# line 1326 "yygrammar.c"
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
   case 77: {
      switch (yyselect()) {
      case 182: {
         logical_AND_expression();
         get_lexval();
#line 325 "ass2.acc"
 fputs("\\ $\\wedge$\\ ", f); 
# line 1345 "yygrammar.c"
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
   case 78: {
      switch (yyselect()) {
      case 183: {
         inclusive_OR_expression();
         get_lexval();
#line 329 "ass2.acc"
 SPRCHS; 
# line 1364 "yygrammar.c"
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
   case 79: {
      switch (yyselect()) {
      case 184: {
         exclusive_OR_expression();
         get_lexval();
#line 333 "ass2.acc"
 SPRCHS; 
# line 1383 "yygrammar.c"
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
   case 80: {
      switch (yyselect()) {
      case 185: {
         AND_expression();
         get_lexval();
#line 337 "ass2.acc"
 SPRCHS; 
# line 1402 "yygrammar.c"
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
   case 81: {
      switch (yyselect()) {
      case 186: {
         equality_expression();
         get_lexval();
#line 341 "ass2.acc"
 fprintCompare(f, yylval.subtype); 
# line 1421 "yygrammar.c"
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
   case 82: {
      switch (yyselect()) {
      case 187: {
         shift_expression();
         get_lexval();
#line 345 "ass2.acc"
 yylval.subtype == SHIFT_LEFT ? fputs("\\ $<<$\\ ", f) : fputs("\\ $>>$\\ ", f); 
# line 1440 "yygrammar.c"
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
   case 83: {
      switch (yyselect()) {
      case 190: {
         additive_expression();
         switch (yyselect()) {
         case 188: {
            get_lexval();
            } break;
         case 189: {
            get_lexval();
            } break;
         default: printf("???\n"); exit(1);
         }
#line 349 "ass2.acc"
 SPRCHS; 
# line 1467 "yygrammar.c"
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
   case 84: {
      switch (yyselect()) {
      case 194: {
         multiplicative_expression();
         switch (yyselect()) {
         case 191: {
            get_lexval();
            } break;
         case 192: {
            get_lexval();
            } break;
         case 193: {
            get_lexval();
            } break;
         default: printf("???\n"); exit(1);
         }
#line 353 "ass2.acc"
 SPRCHS; 
# line 1497 "yygrammar.c"
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
   case 85: {
      unary_expression();
      } break;
   case 86: {
      get_lexval();
#line 358 "ass2.acc"
 PRCH; 
# line 1516 "yygrammar.c"
      type_name();
      get_lexval();
#line 358 "ass2.acc"
 PRCH; 
# line 1521 "yygrammar.c"
      cast_expression();
      } break;
   }
}

unary_expression ()
{
   switch(yyselect()) {
   case 87: {
      postfix_expression();
      } break;
   case 88: {
      switch (yyselect()) {
      case 195: {
         get_lexval();
#line 363 "ass2.acc"
 fputs("++", f); 
# line 1539 "yygrammar.c"
         } break;
      case 196: {
         get_lexval();
#line 363 "ass2.acc"
 fputs("--", f); 
# line 1545 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      unary_expression();
      } break;
   case 89: {
      unary_operator();
      cast_expression();
      } break;
   case 90: {
      get_lexval();
#line 365 "ass2.acc"
 PRKW; 
# line 1559 "yygrammar.c"
      unary_expression();
      } break;
   case 91: {
      get_lexval();
#line 366 "ass2.acc"
 PRKW; 
# line 1566 "yygrammar.c"
      get_lexval();
#line 366 "ass2.acc"
 PRCH; 
# line 1570 "yygrammar.c"
      type_name();
      get_lexval();
#line 366 "ass2.acc"
 PRCH; 
# line 1575 "yygrammar.c"
      } break;
   }
}

unary_operator ()
{
   switch(yyselect()) {
   case 92: {
      switch (yyselect()) {
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
      case 202: {
         get_lexval();
         } break;
      case 203: {
         get_lexval();
         } break;
      case 204: {
         get_lexval();
         } break;
      case 205: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 370 "ass2.acc"
 PRCH; 
# line 1616 "yygrammar.c"
      } break;
   }
}

postfix_expression ()
{
   switch(yyselect()) {
   case 93: {
      primary_expression();
      } break;
   case 94: {
      postfix_expression();
      switch (yyselect()) {
      case 206: {
         get_lexval();
#line 375 "ass2.acc"
 PRCH; 
# line 1634 "yygrammar.c"
         expression();
         get_lexval();
#line 375 "ass2.acc"
 PRCH; 
# line 1639 "yygrammar.c"
         } break;
      case 208: {
         get_lexval();
#line 375 "ass2.acc"
 PRCH; 
# line 1645 "yygrammar.c"
         switch (yyselect()) {
         case 207: {
            argument_expression_list();
            } break;
         default: ;
         }
         get_lexval();
#line 375 "ass2.acc"
 PRCH; 
# line 1655 "yygrammar.c"
         } break;
      case 209: {
         get_lexval();
#line 375 "ass2.acc"
 PRCH; 
# line 1661 "yygrammar.c"
         id();
         } break;
      case 210: {
         get_lexval();
#line 375 "ass2.acc"
 fputs("$\\rightarrow$", f); 
# line 1668 "yygrammar.c"
         id();
         } break;
      case 211: {
         get_lexval();
#line 375 "ass2.acc"
 fputs("++", f); 
# line 1675 "yygrammar.c"
         } break;
      case 212: {
         get_lexval();
#line 375 "ass2.acc"
 fputs("--", f); 
# line 1681 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

primary_expression ()
{
   switch(yyselect()) {
   case 95: {
      id();
      } break;
   case 96: {
      constant();
      } break;
   case 97: {
      get_lexval();
#line 381 "ass2.acc"
 fprintStringConst(f, yylval.s); 
# line 1702 "yygrammar.c"
      } break;
   case 98: {
      get_lexval();
#line 382 "ass2.acc"
 PRCH; 
# line 1708 "yygrammar.c"
      expression();
      get_lexval();
#line 382 "ass2.acc"
 PRCH; 
# line 1713 "yygrammar.c"
      } break;
   }
}

argument_expression_list ()
{
   switch(yyselect()) {
   case 99: {
      switch (yyselect()) {
      case 213: {
         argument_expression_list();
         get_lexval();
#line 386 "ass2.acc"
 PRCHS; 
# line 1728 "yygrammar.c"
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
   case 100: {
      get_lexval();
#line 390 "ass2.acc"
 fprintf(f, "$%u$", yylval.i); 
# line 1744 "yygrammar.c"
      } break;
   case 101: {
      get_lexval();
#line 391 "ass2.acc"
 fprintStringConst(f, yylval.s); 
# line 1750 "yygrammar.c"
      } break;
   case 102: {
      get_lexval();
#line 392 "ass2.acc"
 fprintf(f, "$%f$", yylval.d); 
# line 1756 "yygrammar.c"
      } break;
   case 103: {
      id();
      } break;
   }
}

id ()
{
   switch(yyselect()) {
   case 104: {
      get_lexval();
#line 397 "ass2.acc"
 fprintIdentifier(f, yylval.s); 
# line 1771 "yygrammar.c"
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
int c_length = 1181;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 105,
/* 6 */ 0,
/* 7 */ 10,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 15,
/* 11 */ 18,
/* 12 */ 10,
/* 13 */ -10,
/* 14 */ 106,
/* 15 */ 0,
/* 16 */ -10,
/* 17 */ 214,
/* 18 */ 22,
/* 19 */ 26,
/* 20 */ -18,
/* 21 */ 2,
/* 22 */ 0,
/* 23 */ 55,
/* 24 */ -18,
/* 25 */ 3,
/* 26 */ 0,
/* 27 */ 33,
/* 28 */ 363,
/* 29 */ 40,
/* 30 */ 47,
/* 31 */ -26,
/* 32 */ 4,
/* 33 */ 37,
/* 34 */ 81,
/* 35 */ -33,
/* 36 */ 107,
/* 37 */ 0,
/* 38 */ -33,
/* 39 */ 215,
/* 40 */ 44,
/* 41 */ 68,
/* 42 */ -40,
/* 43 */ 108,
/* 44 */ 0,
/* 45 */ -40,
/* 46 */ 216,
/* 47 */ 51,
/* 48 */ 50059,
/* 49 */ -47,
/* 50 */ 109,
/* 51 */ 0,
/* 52 */ 675,
/* 53 */ -47,
/* 54 */ 110,
/* 55 */ 0,
/* 56 */ 81,
/* 57 */ 61,
/* 58 */ 50059,
/* 59 */ -55,
/* 60 */ 5,
/* 61 */ 65,
/* 62 */ 235,
/* 63 */ -61,
/* 64 */ 111,
/* 65 */ 0,
/* 66 */ -61,
/* 67 */ 217,
/* 68 */ 0,
/* 69 */ 55,
/* 70 */ 73,
/* 71 */ -68,
/* 72 */ 6,
/* 73 */ 78,
/* 74 */ 55,
/* 75 */ 73,
/* 76 */ -73,
/* 77 */ 112,
/* 78 */ 0,
/* 79 */ -73,
/* 80 */ 218,
/* 81 */ 0,
/* 82 */ 85,
/* 83 */ -81,
/* 84 */ 7,
/* 85 */ 90,
/* 86 */ 103,
/* 87 */ 85,
/* 88 */ -85,
/* 89 */ 113,
/* 90 */ 95,
/* 91 */ 127,
/* 92 */ 85,
/* 93 */ -85,
/* 94 */ 114,
/* 95 */ 100,
/* 96 */ 179,
/* 97 */ 85,
/* 98 */ -85,
/* 99 */ 115,
/* 100 */ 0,
/* 101 */ -85,
/* 102 */ 219,
/* 103 */ 0,
/* 104 */ 107,
/* 105 */ -103,
/* 106 */ 8,
/* 107 */ 111,
/* 108 */ 50256,
/* 109 */ -107,
/* 110 */ 116,
/* 111 */ 115,
/* 112 */ 50274,
/* 113 */ -107,
/* 114 */ 117,
/* 115 */ 119,
/* 116 */ 50279,
/* 117 */ -107,
/* 118 */ 118,
/* 119 */ 123,
/* 120 */ 50267,
/* 121 */ -107,
/* 122 */ 119,
/* 123 */ 0,
/* 124 */ 50282,
/* 125 */ -107,
/* 126 */ 120,
/* 127 */ 131,
/* 128 */ 143,
/* 129 */ -127,
/* 130 */ 9,
/* 131 */ 135,
/* 132 */ 191,
/* 133 */ -127,
/* 134 */ 10,
/* 135 */ 139,
/* 136 */ 317,
/* 137 */ -127,
/* 138 */ 11,
/* 139 */ 0,
/* 140 */ 1178,
/* 141 */ -127,
/* 142 */ 12,
/* 143 */ 147,
/* 144 */ 50285,
/* 145 */ -143,
/* 146 */ 121,
/* 147 */ 151,
/* 148 */ 50259,
/* 149 */ -143,
/* 150 */ 122,
/* 151 */ 155,
/* 152 */ 50276,
/* 153 */ -143,
/* 154 */ 123,
/* 155 */ 159,
/* 156 */ 50272,
/* 157 */ -143,
/* 158 */ 124,
/* 159 */ 163,
/* 160 */ 50273,
/* 161 */ -143,
/* 162 */ 125,
/* 163 */ 167,
/* 164 */ 50268,
/* 165 */ -143,
/* 166 */ 126,
/* 167 */ 171,
/* 168 */ 50264,
/* 169 */ -143,
/* 170 */ 127,
/* 171 */ 175,
/* 172 */ 50277,
/* 173 */ -143,
/* 174 */ 128,
/* 175 */ 0,
/* 176 */ 50284,
/* 177 */ -143,
/* 178 */ 129,
/* 179 */ 0,
/* 180 */ 183,
/* 181 */ -179,
/* 182 */ 13,
/* 183 */ 187,
/* 184 */ 50260,
/* 185 */ -183,
/* 186 */ 130,
/* 187 */ 0,
/* 188 */ 50286,
/* 189 */ -183,
/* 190 */ 131,
/* 191 */ 199,
/* 192 */ 211,
/* 193 */ 204,
/* 194 */ 50123,
/* 195 */ 223,
/* 196 */ 50125,
/* 197 */ -191,
/* 198 */ 14,
/* 199 */ 0,
/* 200 */ 211,
/* 201 */ 1178,
/* 202 */ -191,
/* 203 */ 15,
/* 204 */ 208,
/* 205 */ 1178,
/* 206 */ -204,
/* 207 */ 132,
/* 208 */ 0,
/* 209 */ -204,
/* 210 */ 220,
/* 211 */ 0,
/* 212 */ 215,
/* 213 */ -211,
/* 214 */ 16,
/* 215 */ 219,
/* 216 */ 50280,
/* 217 */ -215,
/* 218 */ 133,
/* 219 */ 0,
/* 220 */ 50283,
/* 221 */ -215,
/* 222 */ 134,
/* 223 */ 0,
/* 224 */ 228,
/* 225 */ 261,
/* 226 */ -223,
/* 227 */ 17,
/* 228 */ 232,
/* 229 */ 223,
/* 230 */ -228,
/* 231 */ 135,
/* 232 */ 0,
/* 233 */ -228,
/* 234 */ 221,
/* 235 */ 0,
/* 236 */ 240,
/* 237 */ 248,
/* 238 */ -235,
/* 239 */ 18,
/* 240 */ 245,
/* 241 */ 235,
/* 242 */ 50044,
/* 243 */ -240,
/* 244 */ 136,
/* 245 */ 0,
/* 246 */ -240,
/* 247 */ 222,
/* 248 */ 0,
/* 249 */ 253,
/* 250 */ 513,
/* 251 */ -248,
/* 252 */ 19,
/* 253 */ 258,
/* 254 */ 363,
/* 255 */ 50061,
/* 256 */ -253,
/* 257 */ 137,
/* 258 */ 0,
/* 259 */ -253,
/* 260 */ 223,
/* 261 */ 0,
/* 262 */ 267,
/* 263 */ 287,
/* 264 */ 50059,
/* 265 */ -261,
/* 266 */ 20,
/* 267 */ 0,
/* 268 */ 272,
/* 269 */ 280,
/* 270 */ -267,
/* 271 */ 21,
/* 272 */ 276,
/* 273 */ 127,
/* 274 */ -272,
/* 275 */ 138,
/* 276 */ 0,
/* 277 */ 179,
/* 278 */ -272,
/* 279 */ 139,
/* 280 */ 284,
/* 281 */ 267,
/* 282 */ -280,
/* 283 */ 140,
/* 284 */ 0,
/* 285 */ -280,
/* 286 */ 224,
/* 287 */ 0,
/* 288 */ 292,
/* 289 */ 300,
/* 290 */ -287,
/* 291 */ 22,
/* 292 */ 297,
/* 293 */ 287,
/* 294 */ 50044,
/* 295 */ -292,
/* 296 */ 141,
/* 297 */ 0,
/* 298 */ -292,
/* 299 */ 225,
/* 300 */ 304,
/* 301 */ 363,
/* 302 */ -300,
/* 303 */ 23,
/* 304 */ 0,
/* 305 */ 310,
/* 306 */ 50058,
/* 307 */ 859,
/* 308 */ -300,
/* 309 */ 24,
/* 310 */ 314,
/* 311 */ 363,
/* 312 */ -310,
/* 313 */ 142,
/* 314 */ 0,
/* 315 */ -310,
/* 316 */ 226,
/* 317 */ 325,
/* 318 */ 50266,
/* 319 */ 330,
/* 320 */ 50123,
/* 321 */ 337,
/* 322 */ 50125,
/* 323 */ -317,
/* 324 */ 25,
/* 325 */ 0,
/* 326 */ 50266,
/* 327 */ 1178,
/* 328 */ -317,
/* 329 */ 26,
/* 330 */ 334,
/* 331 */ 1178,
/* 332 */ -330,
/* 333 */ 143,
/* 334 */ 0,
/* 335 */ -330,
/* 336 */ 227,
/* 337 */ 0,
/* 338 */ 342,
/* 339 */ 350,
/* 340 */ -337,
/* 341 */ 27,
/* 342 */ 347,
/* 343 */ 337,
/* 344 */ 50044,
/* 345 */ -342,
/* 346 */ 144,
/* 347 */ 0,
/* 348 */ -342,
/* 349 */ 228,
/* 350 */ 0,
/* 351 */ 1178,
/* 352 */ 355,
/* 353 */ -350,
/* 354 */ 28,
/* 355 */ 360,
/* 356 */ 50061,
/* 357 */ 859,
/* 358 */ -355,
/* 359 */ 145,
/* 360 */ 0,
/* 361 */ -355,
/* 362 */ 229,
/* 363 */ 0,
/* 364 */ 368,
/* 365 */ 375,
/* 366 */ -363,
/* 367 */ 29,
/* 368 */ 372,
/* 369 */ 422,
/* 370 */ -368,
/* 371 */ 146,
/* 372 */ 0,
/* 373 */ -368,
/* 374 */ 230,
/* 375 */ 379,
/* 376 */ 1178,
/* 377 */ -375,
/* 378 */ 30,
/* 379 */ 385,
/* 380 */ 50040,
/* 381 */ 363,
/* 382 */ 50041,
/* 383 */ -375,
/* 384 */ 31,
/* 385 */ 0,
/* 386 */ 375,
/* 387 */ 390,
/* 388 */ -375,
/* 389 */ 32,
/* 390 */ 396,
/* 391 */ 50091,
/* 392 */ 408,
/* 393 */ 50093,
/* 394 */ -390,
/* 395 */ 148,
/* 396 */ 402,
/* 397 */ 50040,
/* 398 */ 454,
/* 399 */ 50041,
/* 400 */ -390,
/* 401 */ 149,
/* 402 */ 0,
/* 403 */ 50040,
/* 404 */ 415,
/* 405 */ 50041,
/* 406 */ -390,
/* 407 */ 151,
/* 408 */ 412,
/* 409 */ 859,
/* 410 */ -408,
/* 411 */ 147,
/* 412 */ 0,
/* 413 */ -408,
/* 414 */ 231,
/* 415 */ 419,
/* 416 */ 500,
/* 417 */ -415,
/* 418 */ 150,
/* 419 */ 0,
/* 420 */ -415,
/* 421 */ 232,
/* 422 */ 0,
/* 423 */ 50042,
/* 424 */ 428,
/* 425 */ 435,
/* 426 */ -422,
/* 427 */ 33,
/* 428 */ 432,
/* 429 */ 442,
/* 430 */ -428,
/* 431 */ 152,
/* 432 */ 0,
/* 433 */ -428,
/* 434 */ 233,
/* 435 */ 439,
/* 436 */ 422,
/* 437 */ -435,
/* 438 */ 153,
/* 439 */ 0,
/* 440 */ -435,
/* 441 */ 234,
/* 442 */ 0,
/* 443 */ 447,
/* 444 */ 179,
/* 445 */ -442,
/* 446 */ 34,
/* 447 */ 451,
/* 448 */ 442,
/* 449 */ -447,
/* 450 */ 154,
/* 451 */ 0,
/* 452 */ -447,
/* 453 */ 235,
/* 454 */ 0,
/* 455 */ 467,
/* 456 */ 459,
/* 457 */ -454,
/* 458 */ 35,
/* 459 */ 464,
/* 460 */ 50044,
/* 461 */ 50290,
/* 462 */ -459,
/* 463 */ 155,
/* 464 */ 0,
/* 465 */ -459,
/* 466 */ 236,
/* 467 */ 0,
/* 468 */ 472,
/* 469 */ 480,
/* 470 */ -467,
/* 471 */ 36,
/* 472 */ 477,
/* 473 */ 467,
/* 474 */ 50044,
/* 475 */ -472,
/* 476 */ 156,
/* 477 */ 0,
/* 478 */ -472,
/* 479 */ 237,
/* 480 */ 0,
/* 481 */ 81,
/* 482 */ 485,
/* 483 */ -480,
/* 484 */ 37,
/* 485 */ 489,
/* 486 */ 363,
/* 487 */ -485,
/* 488 */ 157,
/* 489 */ 0,
/* 490 */ 493,
/* 491 */ -485,
/* 492 */ 159,
/* 493 */ 497,
/* 494 */ 556,
/* 495 */ -493,
/* 496 */ 158,
/* 497 */ 0,
/* 498 */ -493,
/* 499 */ 238,
/* 500 */ 0,
/* 501 */ 505,
/* 502 */ 1178,
/* 503 */ -500,
/* 504 */ 38,
/* 505 */ 510,
/* 506 */ 500,
/* 507 */ 50044,
/* 508 */ -505,
/* 509 */ 160,
/* 510 */ 0,
/* 511 */ -505,
/* 512 */ 239,
/* 513 */ 517,
/* 514 */ 826,
/* 515 */ -513,
/* 516 */ 39,
/* 517 */ 0,
/* 518 */ 50123,
/* 519 */ 531,
/* 520 */ 524,
/* 521 */ 50125,
/* 522 */ -513,
/* 523 */ 40,
/* 524 */ 528,
/* 525 */ 50044,
/* 526 */ -524,
/* 527 */ 161,
/* 528 */ 0,
/* 529 */ -524,
/* 530 */ 240,
/* 531 */ 0,
/* 532 */ 536,
/* 533 */ 513,
/* 534 */ -531,
/* 535 */ 41,
/* 536 */ 541,
/* 537 */ 531,
/* 538 */ 50044,
/* 539 */ -536,
/* 540 */ 162,
/* 541 */ 0,
/* 542 */ -536,
/* 543 */ 241,
/* 544 */ 0,
/* 545 */ 267,
/* 546 */ 549,
/* 547 */ -544,
/* 548 */ 42,
/* 549 */ 553,
/* 550 */ 556,
/* 551 */ -549,
/* 552 */ 163,
/* 553 */ 0,
/* 554 */ -549,
/* 555 */ 242,
/* 556 */ 560,
/* 557 */ 422,
/* 558 */ -556,
/* 559 */ 43,
/* 560 */ 0,
/* 561 */ 565,
/* 562 */ 572,
/* 563 */ -556,
/* 564 */ 44,
/* 565 */ 569,
/* 566 */ 422,
/* 567 */ -565,
/* 568 */ 164,
/* 569 */ 0,
/* 570 */ -565,
/* 571 */ 243,
/* 572 */ 578,
/* 573 */ 50040,
/* 574 */ 556,
/* 575 */ 50041,
/* 576 */ -572,
/* 577 */ 45,
/* 578 */ 0,
/* 579 */ 583,
/* 580 */ 590,
/* 581 */ -572,
/* 582 */ 46,
/* 583 */ 587,
/* 584 */ 572,
/* 585 */ -583,
/* 586 */ 165,
/* 587 */ 0,
/* 588 */ -583,
/* 589 */ 244,
/* 590 */ 596,
/* 591 */ 50091,
/* 592 */ 602,
/* 593 */ 50093,
/* 594 */ -590,
/* 595 */ 167,
/* 596 */ 0,
/* 597 */ 50040,
/* 598 */ 609,
/* 599 */ 50041,
/* 600 */ -590,
/* 601 */ 169,
/* 602 */ 606,
/* 603 */ 859,
/* 604 */ -602,
/* 605 */ 166,
/* 606 */ 0,
/* 607 */ -602,
/* 608 */ 245,
/* 609 */ 613,
/* 610 */ 454,
/* 611 */ -609,
/* 612 */ 168,
/* 613 */ 0,
/* 614 */ -609,
/* 615 */ 246,
/* 616 */ 0,
/* 617 */ 1178,
/* 618 */ -616,
/* 619 */ 47,
/* 620 */ 624,
/* 621 */ 644,
/* 622 */ -620,
/* 623 */ 48,
/* 624 */ 628,
/* 625 */ 663,
/* 626 */ -620,
/* 627 */ 49,
/* 628 */ 632,
/* 629 */ 675,
/* 630 */ -620,
/* 631 */ 50,
/* 632 */ 636,
/* 633 */ 708,
/* 634 */ -620,
/* 635 */ 51,
/* 636 */ 640,
/* 637 */ 733,
/* 638 */ -620,
/* 639 */ 52,
/* 640 */ 0,
/* 641 */ 784,
/* 642 */ -620,
/* 643 */ 53,
/* 644 */ 650,
/* 645 */ 1178,
/* 646 */ 50058,
/* 647 */ 620,
/* 648 */ -644,
/* 649 */ 54,
/* 650 */ 657,
/* 651 */ 50258,
/* 652 */ 859,
/* 653 */ 50058,
/* 654 */ 620,
/* 655 */ -644,
/* 656 */ 55,
/* 657 */ 0,
/* 658 */ 50262,
/* 659 */ 50058,
/* 660 */ 620,
/* 661 */ -644,
/* 662 */ 56,
/* 663 */ 0,
/* 664 */ 668,
/* 665 */ 50059,
/* 666 */ -663,
/* 667 */ 57,
/* 668 */ 672,
/* 669 */ 813,
/* 670 */ -668,
/* 671 */ 170,
/* 672 */ 0,
/* 673 */ -668,
/* 674 */ 247,
/* 675 */ 0,
/* 676 */ 50123,
/* 677 */ 682,
/* 678 */ 689,
/* 679 */ 50125,
/* 680 */ -675,
/* 681 */ 58,
/* 682 */ 686,
/* 683 */ 68,
/* 684 */ -682,
/* 685 */ 171,
/* 686 */ 0,
/* 687 */ -682,
/* 688 */ 248,
/* 689 */ 693,
/* 690 */ 696,
/* 691 */ -689,
/* 692 */ 172,
/* 693 */ 0,
/* 694 */ -689,
/* 695 */ 249,
/* 696 */ 0,
/* 697 */ 701,
/* 698 */ 620,
/* 699 */ -696,
/* 700 */ 59,
/* 701 */ 705,
/* 702 */ 696,
/* 703 */ -701,
/* 704 */ 173,
/* 705 */ 0,
/* 706 */ -701,
/* 707 */ 250,
/* 708 */ 717,
/* 709 */ 50271,
/* 710 */ 50040,
/* 711 */ 813,
/* 712 */ 50041,
/* 713 */ 620,
/* 714 */ 725,
/* 715 */ -708,
/* 716 */ 60,
/* 717 */ 0,
/* 718 */ 50281,
/* 719 */ 50040,
/* 720 */ 813,
/* 721 */ 50041,
/* 722 */ 620,
/* 723 */ -708,
/* 724 */ 61,
/* 725 */ 730,
/* 726 */ 50265,
/* 727 */ 620,
/* 728 */ -725,
/* 729 */ 174,
/* 730 */ 0,
/* 731 */ -725,
/* 732 */ 251,
/* 733 */ 741,
/* 734 */ 50287,
/* 735 */ 50040,
/* 736 */ 813,
/* 737 */ 50041,
/* 738 */ 620,
/* 739 */ -733,
/* 740 */ 62,
/* 741 */ 751,
/* 742 */ 50263,
/* 743 */ 620,
/* 744 */ 50287,
/* 745 */ 50040,
/* 746 */ 813,
/* 747 */ 50041,
/* 748 */ 50059,
/* 749 */ -733,
/* 750 */ 63,
/* 751 */ 0,
/* 752 */ 50269,
/* 753 */ 50040,
/* 754 */ 763,
/* 755 */ 50059,
/* 756 */ 770,
/* 757 */ 50059,
/* 758 */ 777,
/* 759 */ 50041,
/* 760 */ 620,
/* 761 */ -733,
/* 762 */ 64,
/* 763 */ 767,
/* 764 */ 813,
/* 765 */ -763,
/* 766 */ 175,
/* 767 */ 0,
/* 768 */ -763,
/* 769 */ 252,
/* 770 */ 774,
/* 771 */ 813,
/* 772 */ -770,
/* 773 */ 176,
/* 774 */ 0,
/* 775 */ -770,
/* 776 */ 253,
/* 777 */ 781,
/* 778 */ 813,
/* 779 */ -777,
/* 780 */ 177,
/* 781 */ 0,
/* 782 */ -777,
/* 783 */ 254,
/* 784 */ 790,
/* 785 */ 50270,
/* 786 */ 1178,
/* 787 */ 50059,
/* 788 */ -784,
/* 789 */ 65,
/* 790 */ 795,
/* 791 */ 50261,
/* 792 */ 50059,
/* 793 */ -784,
/* 794 */ 66,
/* 795 */ 800,
/* 796 */ 50257,
/* 797 */ 50059,
/* 798 */ -784,
/* 799 */ 67,
/* 800 */ 0,
/* 801 */ 50275,
/* 802 */ 806,
/* 803 */ 50059,
/* 804 */ -784,
/* 805 */ 68,
/* 806 */ 810,
/* 807 */ 813,
/* 808 */ -806,
/* 809 */ 178,
/* 810 */ 0,
/* 811 */ -806,
/* 812 */ 255,
/* 813 */ 0,
/* 814 */ 818,
/* 815 */ 826,
/* 816 */ -813,
/* 817 */ 69,
/* 818 */ 823,
/* 819 */ 813,
/* 820 */ 50044,
/* 821 */ -818,
/* 822 */ 179,
/* 823 */ 0,
/* 824 */ -818,
/* 825 */ 256,
/* 826 */ 830,
/* 827 */ 844,
/* 828 */ -826,
/* 829 */ 70,
/* 830 */ 0,
/* 831 */ 1011,
/* 832 */ 836,
/* 833 */ 826,
/* 834 */ -826,
/* 835 */ 71,
/* 836 */ 840,
/* 837 */ 50291,
/* 838 */ -836,
/* 839 */ 72,
/* 840 */ 0,
/* 841 */ 50061,
/* 842 */ -836,
/* 843 */ 73,
/* 844 */ 0,
/* 845 */ 863,
/* 846 */ 849,
/* 847 */ -844,
/* 848 */ 74,
/* 849 */ 856,
/* 850 */ 50063,
/* 851 */ 813,
/* 852 */ 50058,
/* 853 */ 844,
/* 854 */ -849,
/* 855 */ 180,
/* 856 */ 0,
/* 857 */ -849,
/* 858 */ 257,
/* 859 */ 0,
/* 860 */ 844,
/* 861 */ -859,
/* 862 */ 75,
/* 863 */ 0,
/* 864 */ 868,
/* 865 */ 876,
/* 866 */ -863,
/* 867 */ 76,
/* 868 */ 873,
/* 869 */ 863,
/* 870 */ 50297,
/* 871 */ -868,
/* 872 */ 181,
/* 873 */ 0,
/* 874 */ -868,
/* 875 */ 258,
/* 876 */ 0,
/* 877 */ 881,
/* 878 */ 889,
/* 879 */ -876,
/* 880 */ 77,
/* 881 */ 886,
/* 882 */ 876,
/* 883 */ 50298,
/* 884 */ -881,
/* 885 */ 182,
/* 886 */ 0,
/* 887 */ -881,
/* 888 */ 259,
/* 889 */ 0,
/* 890 */ 894,
/* 891 */ 902,
/* 892 */ -889,
/* 893 */ 78,
/* 894 */ 899,
/* 895 */ 889,
/* 896 */ 50301,
/* 897 */ -894,
/* 898 */ 183,
/* 899 */ 0,
/* 900 */ -894,
/* 901 */ 260,
/* 902 */ 0,
/* 903 */ 907,
/* 904 */ 915,
/* 905 */ -902,
/* 906 */ 79,
/* 907 */ 912,
/* 908 */ 902,
/* 909 */ 50303,
/* 910 */ -907,
/* 911 */ 184,
/* 912 */ 0,
/* 913 */ -907,
/* 914 */ 261,
/* 915 */ 0,
/* 916 */ 920,
/* 917 */ 928,
/* 918 */ -915,
/* 919 */ 80,
/* 920 */ 925,
/* 921 */ 915,
/* 922 */ 50302,
/* 923 */ -920,
/* 924 */ 185,
/* 925 */ 0,
/* 926 */ -920,
/* 927 */ 262,
/* 928 */ 0,
/* 929 */ 933,
/* 930 */ 941,
/* 931 */ -928,
/* 932 */ 81,
/* 933 */ 938,
/* 934 */ 928,
/* 935 */ 50292,
/* 936 */ -933,
/* 937 */ 186,
/* 938 */ 0,
/* 939 */ -933,
/* 940 */ 263,
/* 941 */ 0,
/* 942 */ 946,
/* 943 */ 954,
/* 944 */ -941,
/* 945 */ 82,
/* 946 */ 951,
/* 947 */ 941,
/* 948 */ 50304,
/* 949 */ -946,
/* 950 */ 187,
/* 951 */ 0,
/* 952 */ -946,
/* 953 */ 264,
/* 954 */ 0,
/* 955 */ 959,
/* 956 */ 975,
/* 957 */ -954,
/* 958 */ 83,
/* 959 */ 964,
/* 960 */ 954,
/* 961 */ 967,
/* 962 */ -959,
/* 963 */ 190,
/* 964 */ 0,
/* 965 */ -959,
/* 966 */ 265,
/* 967 */ 971,
/* 968 */ 50043,
/* 969 */ -967,
/* 970 */ 188,
/* 971 */ 0,
/* 972 */ 50045,
/* 973 */ -967,
/* 974 */ 189,
/* 975 */ 0,
/* 976 */ 980,
/* 977 */ 1000,
/* 978 */ -975,
/* 979 */ 84,
/* 980 */ 985,
/* 981 */ 975,
/* 982 */ 988,
/* 983 */ -980,
/* 984 */ 194,
/* 985 */ 0,
/* 986 */ -980,
/* 987 */ 266,
/* 988 */ 992,
/* 989 */ 50042,
/* 990 */ -988,
/* 991 */ 191,
/* 992 */ 996,
/* 993 */ 50047,
/* 994 */ -988,
/* 995 */ 192,
/* 996 */ 0,
/* 997 */ 50037,
/* 998 */ -988,
/* 999 */ 193,
/* 1000 */ 1004,
/* 1001 */ 1011,
/* 1002 */ -1000,
/* 1003 */ 85,
/* 1004 */ 0,
/* 1005 */ 50040,
/* 1006 */ 544,
/* 1007 */ 50041,
/* 1008 */ 1000,
/* 1009 */ -1000,
/* 1010 */ 86,
/* 1011 */ 1015,
/* 1012 */ 1085,
/* 1013 */ -1011,
/* 1014 */ 87,
/* 1015 */ 1020,
/* 1016 */ 1037,
/* 1017 */ 1011,
/* 1018 */ -1011,
/* 1019 */ 88,
/* 1020 */ 1025,
/* 1021 */ 1045,
/* 1022 */ 1000,
/* 1023 */ -1011,
/* 1024 */ 89,
/* 1025 */ 1030,
/* 1026 */ 50278,
/* 1027 */ 1011,
/* 1028 */ -1011,
/* 1029 */ 90,
/* 1030 */ 0,
/* 1031 */ 50278,
/* 1032 */ 50040,
/* 1033 */ 544,
/* 1034 */ 50041,
/* 1035 */ -1011,
/* 1036 */ 91,
/* 1037 */ 1041,
/* 1038 */ 50294,
/* 1039 */ -1037,
/* 1040 */ 195,
/* 1041 */ 0,
/* 1042 */ 50295,
/* 1043 */ -1037,
/* 1044 */ 196,
/* 1045 */ 0,
/* 1046 */ 1049,
/* 1047 */ -1045,
/* 1048 */ 92,
/* 1049 */ 1053,
/* 1050 */ 50302,
/* 1051 */ -1049,
/* 1052 */ 197,
/* 1053 */ 1057,
/* 1054 */ 50042,
/* 1055 */ -1049,
/* 1056 */ 198,
/* 1057 */ 1061,
/* 1058 */ 50043,
/* 1059 */ -1049,
/* 1060 */ 199,
/* 1061 */ 1065,
/* 1062 */ 50045,
/* 1063 */ -1049,
/* 1064 */ 200,
/* 1065 */ 1069,
/* 1066 */ 50126,
/* 1067 */ -1049,
/* 1068 */ 201,
/* 1069 */ 1073,
/* 1070 */ 50033,
/* 1071 */ -1049,
/* 1072 */ 202,
/* 1073 */ 1077,
/* 1074 */ 50305,
/* 1075 */ -1049,
/* 1076 */ 203,
/* 1077 */ 1081,
/* 1078 */ 50301,
/* 1079 */ -1049,
/* 1080 */ 204,
/* 1081 */ 0,
/* 1082 */ 50303,
/* 1083 */ -1049,
/* 1084 */ 205,
/* 1085 */ 1089,
/* 1086 */ 1131,
/* 1087 */ -1085,
/* 1088 */ 93,
/* 1089 */ 0,
/* 1090 */ 1085,
/* 1091 */ 1094,
/* 1092 */ -1085,
/* 1093 */ 94,
/* 1094 */ 1100,
/* 1095 */ 50091,
/* 1096 */ 813,
/* 1097 */ 50093,
/* 1098 */ -1094,
/* 1099 */ 206,
/* 1100 */ 1106,
/* 1101 */ 50040,
/* 1102 */ 1124,
/* 1103 */ 50041,
/* 1104 */ -1094,
/* 1105 */ 208,
/* 1106 */ 1111,
/* 1107 */ 50046,
/* 1108 */ 1178,
/* 1109 */ -1094,
/* 1110 */ 209,
/* 1111 */ 1116,
/* 1112 */ 50296,
/* 1113 */ 1178,
/* 1114 */ -1094,
/* 1115 */ 210,
/* 1116 */ 1120,
/* 1117 */ 50294,
/* 1118 */ -1094,
/* 1119 */ 211,
/* 1120 */ 0,
/* 1121 */ 50295,
/* 1122 */ -1094,
/* 1123 */ 212,
/* 1124 */ 1128,
/* 1125 */ 1149,
/* 1126 */ -1124,
/* 1127 */ 207,
/* 1128 */ 0,
/* 1129 */ -1124,
/* 1130 */ 267,
/* 1131 */ 1135,
/* 1132 */ 1178,
/* 1133 */ -1131,
/* 1134 */ 95,
/* 1135 */ 1139,
/* 1136 */ 1162,
/* 1137 */ -1131,
/* 1138 */ 96,
/* 1139 */ 1143,
/* 1140 */ 50289,
/* 1141 */ -1131,
/* 1142 */ 97,
/* 1143 */ 0,
/* 1144 */ 50040,
/* 1145 */ 813,
/* 1146 */ 50041,
/* 1147 */ -1131,
/* 1148 */ 98,
/* 1149 */ 0,
/* 1150 */ 1154,
/* 1151 */ 826,
/* 1152 */ -1149,
/* 1153 */ 99,
/* 1154 */ 1159,
/* 1155 */ 1149,
/* 1156 */ 50044,
/* 1157 */ -1154,
/* 1158 */ 213,
/* 1159 */ 0,
/* 1160 */ -1154,
/* 1161 */ 268,
/* 1162 */ 1166,
/* 1163 */ 50309,
/* 1164 */ -1162,
/* 1165 */ 100,
/* 1166 */ 1170,
/* 1167 */ 50307,
/* 1168 */ -1162,
/* 1169 */ 101,
/* 1170 */ 1174,
/* 1171 */ 50308,
/* 1172 */ -1162,
/* 1173 */ 102,
/* 1174 */ 0,
/* 1175 */ 1178,
/* 1176 */ -1162,
/* 1177 */ 103,
/* 1178 */ 0,
/* 1179 */ 50299,
/* 1180 */ -1178,
/* 1181 */ 104,
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
/* 47 */ 51,
/* 48 */ 50059,
/* 49 */ -47,
/* 50 */ 1,
/* 51 */ 0,
/* 52 */ 1,
/* 53 */ -47,
/* 54 */ 2,
/* 55 */ 0,
/* 56 */ 1,
/* 57 */ 1,
/* 58 */ 50059,
/* 59 */ -55,
/* 60 */ 1,
/* 61 */ 65,
/* 62 */ 1,
/* 63 */ -61,
/* 64 */ 1,
/* 65 */ 0,
/* 66 */ -61,
/* 67 */ 2,
/* 68 */ 0,
/* 69 */ 1,
/* 70 */ 1,
/* 71 */ -68,
/* 72 */ 1,
/* 73 */ 78,
/* 74 */ 1,
/* 75 */ 1,
/* 76 */ -73,
/* 77 */ 1,
/* 78 */ 0,
/* 79 */ -73,
/* 80 */ 2,
/* 81 */ 0,
/* 82 */ 1,
/* 83 */ -81,
/* 84 */ 1,
/* 85 */ 90,
/* 86 */ 1,
/* 87 */ 1,
/* 88 */ -85,
/* 89 */ 1,
/* 90 */ 95,
/* 91 */ 1,
/* 92 */ 1,
/* 93 */ -85,
/* 94 */ 2,
/* 95 */ 100,
/* 96 */ 1,
/* 97 */ 1,
/* 98 */ -85,
/* 99 */ 3,
/* 100 */ 0,
/* 101 */ -85,
/* 102 */ 4,
/* 103 */ 0,
/* 104 */ 1,
/* 105 */ -103,
/* 106 */ 1,
/* 107 */ 111,
/* 108 */ 50256,
/* 109 */ -107,
/* 110 */ 1,
/* 111 */ 115,
/* 112 */ 50274,
/* 113 */ -107,
/* 114 */ 2,
/* 115 */ 119,
/* 116 */ 50279,
/* 117 */ -107,
/* 118 */ 3,
/* 119 */ 123,
/* 120 */ 50267,
/* 121 */ -107,
/* 122 */ 4,
/* 123 */ 0,
/* 124 */ 50282,
/* 125 */ -107,
/* 126 */ 5,
/* 127 */ 131,
/* 128 */ 1,
/* 129 */ -127,
/* 130 */ 1,
/* 131 */ 135,
/* 132 */ 1,
/* 133 */ -127,
/* 134 */ 2,
/* 135 */ 139,
/* 136 */ 1,
/* 137 */ -127,
/* 138 */ 3,
/* 139 */ 0,
/* 140 */ 1,
/* 141 */ -127,
/* 142 */ 4,
/* 143 */ 147,
/* 144 */ 50285,
/* 145 */ -143,
/* 146 */ 1,
/* 147 */ 151,
/* 148 */ 50259,
/* 149 */ -143,
/* 150 */ 2,
/* 151 */ 155,
/* 152 */ 50276,
/* 153 */ -143,
/* 154 */ 3,
/* 155 */ 159,
/* 156 */ 50272,
/* 157 */ -143,
/* 158 */ 4,
/* 159 */ 163,
/* 160 */ 50273,
/* 161 */ -143,
/* 162 */ 5,
/* 163 */ 167,
/* 164 */ 50268,
/* 165 */ -143,
/* 166 */ 6,
/* 167 */ 171,
/* 168 */ 50264,
/* 169 */ -143,
/* 170 */ 7,
/* 171 */ 175,
/* 172 */ 50277,
/* 173 */ -143,
/* 174 */ 8,
/* 175 */ 0,
/* 176 */ 50284,
/* 177 */ -143,
/* 178 */ 9,
/* 179 */ 0,
/* 180 */ 1,
/* 181 */ -179,
/* 182 */ 1,
/* 183 */ 187,
/* 184 */ 50260,
/* 185 */ -183,
/* 186 */ 1,
/* 187 */ 0,
/* 188 */ 50286,
/* 189 */ -183,
/* 190 */ 2,
/* 191 */ 199,
/* 192 */ 1,
/* 193 */ 1,
/* 194 */ 50123,
/* 195 */ 1,
/* 196 */ 50125,
/* 197 */ -191,
/* 198 */ 1,
/* 199 */ 0,
/* 200 */ 1,
/* 201 */ 1,
/* 202 */ -191,
/* 203 */ 2,
/* 204 */ 208,
/* 205 */ 1,
/* 206 */ -204,
/* 207 */ 1,
/* 208 */ 0,
/* 209 */ -204,
/* 210 */ 2,
/* 211 */ 0,
/* 212 */ 1,
/* 213 */ -211,
/* 214 */ 1,
/* 215 */ 219,
/* 216 */ 50280,
/* 217 */ -215,
/* 218 */ 1,
/* 219 */ 0,
/* 220 */ 50283,
/* 221 */ -215,
/* 222 */ 2,
/* 223 */ 0,
/* 224 */ 1,
/* 225 */ 1,
/* 226 */ -223,
/* 227 */ 1,
/* 228 */ 232,
/* 229 */ 1,
/* 230 */ -228,
/* 231 */ 1,
/* 232 */ 0,
/* 233 */ -228,
/* 234 */ 2,
/* 235 */ 0,
/* 236 */ 1,
/* 237 */ 1,
/* 238 */ -235,
/* 239 */ 1,
/* 240 */ 245,
/* 241 */ 1,
/* 242 */ 50044,
/* 243 */ -240,
/* 244 */ 1,
/* 245 */ 0,
/* 246 */ -240,
/* 247 */ 2,
/* 248 */ 0,
/* 249 */ 1,
/* 250 */ 1,
/* 251 */ -248,
/* 252 */ 1,
/* 253 */ 258,
/* 254 */ 1,
/* 255 */ 50061,
/* 256 */ -253,
/* 257 */ 1,
/* 258 */ 0,
/* 259 */ -253,
/* 260 */ 2,
/* 261 */ 0,
/* 262 */ 1,
/* 263 */ 1,
/* 264 */ 50059,
/* 265 */ -261,
/* 266 */ 1,
/* 267 */ 0,
/* 268 */ 1,
/* 269 */ 1,
/* 270 */ -267,
/* 271 */ 1,
/* 272 */ 276,
/* 273 */ 1,
/* 274 */ -272,
/* 275 */ 1,
/* 276 */ 0,
/* 277 */ 1,
/* 278 */ -272,
/* 279 */ 2,
/* 280 */ 284,
/* 281 */ 1,
/* 282 */ -280,
/* 283 */ 1,
/* 284 */ 0,
/* 285 */ -280,
/* 286 */ 2,
/* 287 */ 0,
/* 288 */ 1,
/* 289 */ 1,
/* 290 */ -287,
/* 291 */ 1,
/* 292 */ 297,
/* 293 */ 1,
/* 294 */ 50044,
/* 295 */ -292,
/* 296 */ 1,
/* 297 */ 0,
/* 298 */ -292,
/* 299 */ 2,
/* 300 */ 304,
/* 301 */ 1,
/* 302 */ -300,
/* 303 */ 1,
/* 304 */ 0,
/* 305 */ 1,
/* 306 */ 50058,
/* 307 */ 1,
/* 308 */ -300,
/* 309 */ 2,
/* 310 */ 314,
/* 311 */ 1,
/* 312 */ -310,
/* 313 */ 1,
/* 314 */ 0,
/* 315 */ -310,
/* 316 */ 2,
/* 317 */ 325,
/* 318 */ 50266,
/* 319 */ 1,
/* 320 */ 50123,
/* 321 */ 1,
/* 322 */ 50125,
/* 323 */ -317,
/* 324 */ 1,
/* 325 */ 0,
/* 326 */ 50266,
/* 327 */ 1,
/* 328 */ -317,
/* 329 */ 2,
/* 330 */ 334,
/* 331 */ 1,
/* 332 */ -330,
/* 333 */ 1,
/* 334 */ 0,
/* 335 */ -330,
/* 336 */ 2,
/* 337 */ 0,
/* 338 */ 1,
/* 339 */ 1,
/* 340 */ -337,
/* 341 */ 1,
/* 342 */ 347,
/* 343 */ 1,
/* 344 */ 50044,
/* 345 */ -342,
/* 346 */ 1,
/* 347 */ 0,
/* 348 */ -342,
/* 349 */ 2,
/* 350 */ 0,
/* 351 */ 1,
/* 352 */ 1,
/* 353 */ -350,
/* 354 */ 1,
/* 355 */ 360,
/* 356 */ 50061,
/* 357 */ 1,
/* 358 */ -355,
/* 359 */ 1,
/* 360 */ 0,
/* 361 */ -355,
/* 362 */ 2,
/* 363 */ 0,
/* 364 */ 1,
/* 365 */ 1,
/* 366 */ -363,
/* 367 */ 1,
/* 368 */ 372,
/* 369 */ 1,
/* 370 */ -368,
/* 371 */ 1,
/* 372 */ 0,
/* 373 */ -368,
/* 374 */ 2,
/* 375 */ 379,
/* 376 */ 1,
/* 377 */ -375,
/* 378 */ 1,
/* 379 */ 385,
/* 380 */ 50040,
/* 381 */ 1,
/* 382 */ 50041,
/* 383 */ -375,
/* 384 */ 2,
/* 385 */ 0,
/* 386 */ 1,
/* 387 */ 1,
/* 388 */ -375,
/* 389 */ 3,
/* 390 */ 396,
/* 391 */ 50091,
/* 392 */ 1,
/* 393 */ 50093,
/* 394 */ -390,
/* 395 */ 1,
/* 396 */ 402,
/* 397 */ 50040,
/* 398 */ 1,
/* 399 */ 50041,
/* 400 */ -390,
/* 401 */ 2,
/* 402 */ 0,
/* 403 */ 50040,
/* 404 */ 1,
/* 405 */ 50041,
/* 406 */ -390,
/* 407 */ 3,
/* 408 */ 412,
/* 409 */ 1,
/* 410 */ -408,
/* 411 */ 1,
/* 412 */ 0,
/* 413 */ -408,
/* 414 */ 2,
/* 415 */ 419,
/* 416 */ 1,
/* 417 */ -415,
/* 418 */ 1,
/* 419 */ 0,
/* 420 */ -415,
/* 421 */ 2,
/* 422 */ 0,
/* 423 */ 50042,
/* 424 */ 1,
/* 425 */ 1,
/* 426 */ -422,
/* 427 */ 1,
/* 428 */ 432,
/* 429 */ 1,
/* 430 */ -428,
/* 431 */ 1,
/* 432 */ 0,
/* 433 */ -428,
/* 434 */ 2,
/* 435 */ 439,
/* 436 */ 1,
/* 437 */ -435,
/* 438 */ 1,
/* 439 */ 0,
/* 440 */ -435,
/* 441 */ 2,
/* 442 */ 0,
/* 443 */ 1,
/* 444 */ 1,
/* 445 */ -442,
/* 446 */ 1,
/* 447 */ 451,
/* 448 */ 1,
/* 449 */ -447,
/* 450 */ 1,
/* 451 */ 0,
/* 452 */ -447,
/* 453 */ 2,
/* 454 */ 0,
/* 455 */ 1,
/* 456 */ 1,
/* 457 */ -454,
/* 458 */ 1,
/* 459 */ 464,
/* 460 */ 50044,
/* 461 */ 50290,
/* 462 */ -459,
/* 463 */ 1,
/* 464 */ 0,
/* 465 */ -459,
/* 466 */ 2,
/* 467 */ 0,
/* 468 */ 1,
/* 469 */ 1,
/* 470 */ -467,
/* 471 */ 1,
/* 472 */ 477,
/* 473 */ 1,
/* 474 */ 50044,
/* 475 */ -472,
/* 476 */ 1,
/* 477 */ 0,
/* 478 */ -472,
/* 479 */ 2,
/* 480 */ 0,
/* 481 */ 1,
/* 482 */ 1,
/* 483 */ -480,
/* 484 */ 1,
/* 485 */ 489,
/* 486 */ 1,
/* 487 */ -485,
/* 488 */ 1,
/* 489 */ 0,
/* 490 */ 1,
/* 491 */ -485,
/* 492 */ 2,
/* 493 */ 497,
/* 494 */ 1,
/* 495 */ -493,
/* 496 */ 1,
/* 497 */ 0,
/* 498 */ -493,
/* 499 */ 2,
/* 500 */ 0,
/* 501 */ 1,
/* 502 */ 1,
/* 503 */ -500,
/* 504 */ 1,
/* 505 */ 510,
/* 506 */ 1,
/* 507 */ 50044,
/* 508 */ -505,
/* 509 */ 1,
/* 510 */ 0,
/* 511 */ -505,
/* 512 */ 2,
/* 513 */ 517,
/* 514 */ 1,
/* 515 */ -513,
/* 516 */ 1,
/* 517 */ 0,
/* 518 */ 50123,
/* 519 */ 1,
/* 520 */ 1,
/* 521 */ 50125,
/* 522 */ -513,
/* 523 */ 2,
/* 524 */ 528,
/* 525 */ 50044,
/* 526 */ -524,
/* 527 */ 1,
/* 528 */ 0,
/* 529 */ -524,
/* 530 */ 2,
/* 531 */ 0,
/* 532 */ 1,
/* 533 */ 1,
/* 534 */ -531,
/* 535 */ 1,
/* 536 */ 541,
/* 537 */ 1,
/* 538 */ 50044,
/* 539 */ -536,
/* 540 */ 1,
/* 541 */ 0,
/* 542 */ -536,
/* 543 */ 2,
/* 544 */ 0,
/* 545 */ 1,
/* 546 */ 1,
/* 547 */ -544,
/* 548 */ 1,
/* 549 */ 553,
/* 550 */ 1,
/* 551 */ -549,
/* 552 */ 1,
/* 553 */ 0,
/* 554 */ -549,
/* 555 */ 2,
/* 556 */ 560,
/* 557 */ 1,
/* 558 */ -556,
/* 559 */ 1,
/* 560 */ 0,
/* 561 */ 1,
/* 562 */ 1,
/* 563 */ -556,
/* 564 */ 2,
/* 565 */ 569,
/* 566 */ 1,
/* 567 */ -565,
/* 568 */ 1,
/* 569 */ 0,
/* 570 */ -565,
/* 571 */ 2,
/* 572 */ 578,
/* 573 */ 50040,
/* 574 */ 1,
/* 575 */ 50041,
/* 576 */ -572,
/* 577 */ 1,
/* 578 */ 0,
/* 579 */ 1,
/* 580 */ 1,
/* 581 */ -572,
/* 582 */ 2,
/* 583 */ 587,
/* 584 */ 1,
/* 585 */ -583,
/* 586 */ 1,
/* 587 */ 0,
/* 588 */ -583,
/* 589 */ 2,
/* 590 */ 596,
/* 591 */ 50091,
/* 592 */ 1,
/* 593 */ 50093,
/* 594 */ -590,
/* 595 */ 1,
/* 596 */ 0,
/* 597 */ 50040,
/* 598 */ 1,
/* 599 */ 50041,
/* 600 */ -590,
/* 601 */ 2,
/* 602 */ 606,
/* 603 */ 1,
/* 604 */ -602,
/* 605 */ 1,
/* 606 */ 0,
/* 607 */ -602,
/* 608 */ 2,
/* 609 */ 613,
/* 610 */ 1,
/* 611 */ -609,
/* 612 */ 1,
/* 613 */ 0,
/* 614 */ -609,
/* 615 */ 2,
/* 616 */ 0,
/* 617 */ 1,
/* 618 */ -616,
/* 619 */ 1,
/* 620 */ 624,
/* 621 */ 1,
/* 622 */ -620,
/* 623 */ 1,
/* 624 */ 628,
/* 625 */ 1,
/* 626 */ -620,
/* 627 */ 2,
/* 628 */ 632,
/* 629 */ 1,
/* 630 */ -620,
/* 631 */ 3,
/* 632 */ 636,
/* 633 */ 1,
/* 634 */ -620,
/* 635 */ 4,
/* 636 */ 640,
/* 637 */ 1,
/* 638 */ -620,
/* 639 */ 5,
/* 640 */ 0,
/* 641 */ 1,
/* 642 */ -620,
/* 643 */ 6,
/* 644 */ 650,
/* 645 */ 1,
/* 646 */ 50058,
/* 647 */ 1,
/* 648 */ -644,
/* 649 */ 1,
/* 650 */ 657,
/* 651 */ 50258,
/* 652 */ 1,
/* 653 */ 50058,
/* 654 */ 1,
/* 655 */ -644,
/* 656 */ 2,
/* 657 */ 0,
/* 658 */ 50262,
/* 659 */ 50058,
/* 660 */ 1,
/* 661 */ -644,
/* 662 */ 3,
/* 663 */ 0,
/* 664 */ 1,
/* 665 */ 50059,
/* 666 */ -663,
/* 667 */ 1,
/* 668 */ 672,
/* 669 */ 1,
/* 670 */ -668,
/* 671 */ 1,
/* 672 */ 0,
/* 673 */ -668,
/* 674 */ 2,
/* 675 */ 0,
/* 676 */ 50123,
/* 677 */ 1,
/* 678 */ 1,
/* 679 */ 50125,
/* 680 */ -675,
/* 681 */ 1,
/* 682 */ 686,
/* 683 */ 1,
/* 684 */ -682,
/* 685 */ 1,
/* 686 */ 0,
/* 687 */ -682,
/* 688 */ 2,
/* 689 */ 693,
/* 690 */ 1,
/* 691 */ -689,
/* 692 */ 1,
/* 693 */ 0,
/* 694 */ -689,
/* 695 */ 2,
/* 696 */ 0,
/* 697 */ 1,
/* 698 */ 1,
/* 699 */ -696,
/* 700 */ 1,
/* 701 */ 705,
/* 702 */ 1,
/* 703 */ -701,
/* 704 */ 1,
/* 705 */ 0,
/* 706 */ -701,
/* 707 */ 2,
/* 708 */ 717,
/* 709 */ 50271,
/* 710 */ 50040,
/* 711 */ 1,
/* 712 */ 50041,
/* 713 */ 1,
/* 714 */ 1,
/* 715 */ -708,
/* 716 */ 1,
/* 717 */ 0,
/* 718 */ 50281,
/* 719 */ 50040,
/* 720 */ 1,
/* 721 */ 50041,
/* 722 */ 1,
/* 723 */ -708,
/* 724 */ 2,
/* 725 */ 730,
/* 726 */ 50265,
/* 727 */ 1,
/* 728 */ -725,
/* 729 */ 1,
/* 730 */ 0,
/* 731 */ -725,
/* 732 */ 2,
/* 733 */ 741,
/* 734 */ 50287,
/* 735 */ 50040,
/* 736 */ 1,
/* 737 */ 50041,
/* 738 */ 1,
/* 739 */ -733,
/* 740 */ 1,
/* 741 */ 751,
/* 742 */ 50263,
/* 743 */ 1,
/* 744 */ 50287,
/* 745 */ 50040,
/* 746 */ 1,
/* 747 */ 50041,
/* 748 */ 50059,
/* 749 */ -733,
/* 750 */ 2,
/* 751 */ 0,
/* 752 */ 50269,
/* 753 */ 50040,
/* 754 */ 1,
/* 755 */ 50059,
/* 756 */ 1,
/* 757 */ 50059,
/* 758 */ 1,
/* 759 */ 50041,
/* 760 */ 1,
/* 761 */ -733,
/* 762 */ 3,
/* 763 */ 767,
/* 764 */ 1,
/* 765 */ -763,
/* 766 */ 1,
/* 767 */ 0,
/* 768 */ -763,
/* 769 */ 2,
/* 770 */ 774,
/* 771 */ 1,
/* 772 */ -770,
/* 773 */ 1,
/* 774 */ 0,
/* 775 */ -770,
/* 776 */ 2,
/* 777 */ 781,
/* 778 */ 1,
/* 779 */ -777,
/* 780 */ 1,
/* 781 */ 0,
/* 782 */ -777,
/* 783 */ 2,
/* 784 */ 790,
/* 785 */ 50270,
/* 786 */ 1,
/* 787 */ 50059,
/* 788 */ -784,
/* 789 */ 1,
/* 790 */ 795,
/* 791 */ 50261,
/* 792 */ 50059,
/* 793 */ -784,
/* 794 */ 2,
/* 795 */ 800,
/* 796 */ 50257,
/* 797 */ 50059,
/* 798 */ -784,
/* 799 */ 3,
/* 800 */ 0,
/* 801 */ 50275,
/* 802 */ 1,
/* 803 */ 50059,
/* 804 */ -784,
/* 805 */ 4,
/* 806 */ 810,
/* 807 */ 1,
/* 808 */ -806,
/* 809 */ 1,
/* 810 */ 0,
/* 811 */ -806,
/* 812 */ 2,
/* 813 */ 0,
/* 814 */ 1,
/* 815 */ 1,
/* 816 */ -813,
/* 817 */ 1,
/* 818 */ 823,
/* 819 */ 1,
/* 820 */ 50044,
/* 821 */ -818,
/* 822 */ 1,
/* 823 */ 0,
/* 824 */ -818,
/* 825 */ 2,
/* 826 */ 830,
/* 827 */ 1,
/* 828 */ -826,
/* 829 */ 1,
/* 830 */ 0,
/* 831 */ 1,
/* 832 */ 1,
/* 833 */ 1,
/* 834 */ -826,
/* 835 */ 2,
/* 836 */ 840,
/* 837 */ 50291,
/* 838 */ -836,
/* 839 */ 1,
/* 840 */ 0,
/* 841 */ 50061,
/* 842 */ -836,
/* 843 */ 2,
/* 844 */ 0,
/* 845 */ 1,
/* 846 */ 1,
/* 847 */ -844,
/* 848 */ 1,
/* 849 */ 856,
/* 850 */ 50063,
/* 851 */ 1,
/* 852 */ 50058,
/* 853 */ 1,
/* 854 */ -849,
/* 855 */ 1,
/* 856 */ 0,
/* 857 */ -849,
/* 858 */ 2,
/* 859 */ 0,
/* 860 */ 1,
/* 861 */ -859,
/* 862 */ 1,
/* 863 */ 0,
/* 864 */ 1,
/* 865 */ 1,
/* 866 */ -863,
/* 867 */ 1,
/* 868 */ 873,
/* 869 */ 1,
/* 870 */ 50297,
/* 871 */ -868,
/* 872 */ 1,
/* 873 */ 0,
/* 874 */ -868,
/* 875 */ 2,
/* 876 */ 0,
/* 877 */ 1,
/* 878 */ 1,
/* 879 */ -876,
/* 880 */ 1,
/* 881 */ 886,
/* 882 */ 1,
/* 883 */ 50298,
/* 884 */ -881,
/* 885 */ 1,
/* 886 */ 0,
/* 887 */ -881,
/* 888 */ 2,
/* 889 */ 0,
/* 890 */ 1,
/* 891 */ 1,
/* 892 */ -889,
/* 893 */ 1,
/* 894 */ 899,
/* 895 */ 1,
/* 896 */ 50301,
/* 897 */ -894,
/* 898 */ 1,
/* 899 */ 0,
/* 900 */ -894,
/* 901 */ 2,
/* 902 */ 0,
/* 903 */ 1,
/* 904 */ 1,
/* 905 */ -902,
/* 906 */ 1,
/* 907 */ 912,
/* 908 */ 1,
/* 909 */ 50303,
/* 910 */ -907,
/* 911 */ 1,
/* 912 */ 0,
/* 913 */ -907,
/* 914 */ 2,
/* 915 */ 0,
/* 916 */ 1,
/* 917 */ 1,
/* 918 */ -915,
/* 919 */ 1,
/* 920 */ 925,
/* 921 */ 1,
/* 922 */ 50302,
/* 923 */ -920,
/* 924 */ 1,
/* 925 */ 0,
/* 926 */ -920,
/* 927 */ 2,
/* 928 */ 0,
/* 929 */ 1,
/* 930 */ 1,
/* 931 */ -928,
/* 932 */ 1,
/* 933 */ 938,
/* 934 */ 1,
/* 935 */ 50292,
/* 936 */ -933,
/* 937 */ 1,
/* 938 */ 0,
/* 939 */ -933,
/* 940 */ 2,
/* 941 */ 0,
/* 942 */ 1,
/* 943 */ 1,
/* 944 */ -941,
/* 945 */ 1,
/* 946 */ 951,
/* 947 */ 1,
/* 948 */ 50304,
/* 949 */ -946,
/* 950 */ 1,
/* 951 */ 0,
/* 952 */ -946,
/* 953 */ 2,
/* 954 */ 0,
/* 955 */ 1,
/* 956 */ 1,
/* 957 */ -954,
/* 958 */ 1,
/* 959 */ 964,
/* 960 */ 1,
/* 961 */ 1,
/* 962 */ -959,
/* 963 */ 1,
/* 964 */ 0,
/* 965 */ -959,
/* 966 */ 2,
/* 967 */ 971,
/* 968 */ 50043,
/* 969 */ -967,
/* 970 */ 1,
/* 971 */ 0,
/* 972 */ 50045,
/* 973 */ -967,
/* 974 */ 2,
/* 975 */ 0,
/* 976 */ 1,
/* 977 */ 1,
/* 978 */ -975,
/* 979 */ 1,
/* 980 */ 985,
/* 981 */ 1,
/* 982 */ 1,
/* 983 */ -980,
/* 984 */ 1,
/* 985 */ 0,
/* 986 */ -980,
/* 987 */ 2,
/* 988 */ 992,
/* 989 */ 50042,
/* 990 */ -988,
/* 991 */ 1,
/* 992 */ 996,
/* 993 */ 50047,
/* 994 */ -988,
/* 995 */ 2,
/* 996 */ 0,
/* 997 */ 50037,
/* 998 */ -988,
/* 999 */ 3,
/* 1000 */ 1004,
/* 1001 */ 1,
/* 1002 */ -1000,
/* 1003 */ 1,
/* 1004 */ 0,
/* 1005 */ 50040,
/* 1006 */ 1,
/* 1007 */ 50041,
/* 1008 */ 1,
/* 1009 */ -1000,
/* 1010 */ 2,
/* 1011 */ 1015,
/* 1012 */ 1,
/* 1013 */ -1011,
/* 1014 */ 1,
/* 1015 */ 1020,
/* 1016 */ 1,
/* 1017 */ 1,
/* 1018 */ -1011,
/* 1019 */ 2,
/* 1020 */ 1025,
/* 1021 */ 1,
/* 1022 */ 1,
/* 1023 */ -1011,
/* 1024 */ 3,
/* 1025 */ 1030,
/* 1026 */ 50278,
/* 1027 */ 1,
/* 1028 */ -1011,
/* 1029 */ 4,
/* 1030 */ 0,
/* 1031 */ 50278,
/* 1032 */ 50040,
/* 1033 */ 1,
/* 1034 */ 50041,
/* 1035 */ -1011,
/* 1036 */ 5,
/* 1037 */ 1041,
/* 1038 */ 50294,
/* 1039 */ -1037,
/* 1040 */ 1,
/* 1041 */ 0,
/* 1042 */ 50295,
/* 1043 */ -1037,
/* 1044 */ 2,
/* 1045 */ 0,
/* 1046 */ 1,
/* 1047 */ -1045,
/* 1048 */ 1,
/* 1049 */ 1053,
/* 1050 */ 50302,
/* 1051 */ -1049,
/* 1052 */ 1,
/* 1053 */ 1057,
/* 1054 */ 50042,
/* 1055 */ -1049,
/* 1056 */ 2,
/* 1057 */ 1061,
/* 1058 */ 50043,
/* 1059 */ -1049,
/* 1060 */ 3,
/* 1061 */ 1065,
/* 1062 */ 50045,
/* 1063 */ -1049,
/* 1064 */ 4,
/* 1065 */ 1069,
/* 1066 */ 50126,
/* 1067 */ -1049,
/* 1068 */ 5,
/* 1069 */ 1073,
/* 1070 */ 50033,
/* 1071 */ -1049,
/* 1072 */ 6,
/* 1073 */ 1077,
/* 1074 */ 50305,
/* 1075 */ -1049,
/* 1076 */ 7,
/* 1077 */ 1081,
/* 1078 */ 50301,
/* 1079 */ -1049,
/* 1080 */ 8,
/* 1081 */ 0,
/* 1082 */ 50303,
/* 1083 */ -1049,
/* 1084 */ 9,
/* 1085 */ 1089,
/* 1086 */ 1,
/* 1087 */ -1085,
/* 1088 */ 1,
/* 1089 */ 0,
/* 1090 */ 1,
/* 1091 */ 1,
/* 1092 */ -1085,
/* 1093 */ 2,
/* 1094 */ 1100,
/* 1095 */ 50091,
/* 1096 */ 1,
/* 1097 */ 50093,
/* 1098 */ -1094,
/* 1099 */ 1,
/* 1100 */ 1106,
/* 1101 */ 50040,
/* 1102 */ 1,
/* 1103 */ 50041,
/* 1104 */ -1094,
/* 1105 */ 2,
/* 1106 */ 1111,
/* 1107 */ 50046,
/* 1108 */ 1,
/* 1109 */ -1094,
/* 1110 */ 3,
/* 1111 */ 1116,
/* 1112 */ 50296,
/* 1113 */ 1,
/* 1114 */ -1094,
/* 1115 */ 4,
/* 1116 */ 1120,
/* 1117 */ 50294,
/* 1118 */ -1094,
/* 1119 */ 5,
/* 1120 */ 0,
/* 1121 */ 50295,
/* 1122 */ -1094,
/* 1123 */ 6,
/* 1124 */ 1128,
/* 1125 */ 1,
/* 1126 */ -1124,
/* 1127 */ 1,
/* 1128 */ 0,
/* 1129 */ -1124,
/* 1130 */ 2,
/* 1131 */ 1135,
/* 1132 */ 1,
/* 1133 */ -1131,
/* 1134 */ 1,
/* 1135 */ 1139,
/* 1136 */ 1,
/* 1137 */ -1131,
/* 1138 */ 2,
/* 1139 */ 1143,
/* 1140 */ 50289,
/* 1141 */ -1131,
/* 1142 */ 3,
/* 1143 */ 0,
/* 1144 */ 50040,
/* 1145 */ 1,
/* 1146 */ 50041,
/* 1147 */ -1131,
/* 1148 */ 4,
/* 1149 */ 0,
/* 1150 */ 1,
/* 1151 */ 1,
/* 1152 */ -1149,
/* 1153 */ 1,
/* 1154 */ 1159,
/* 1155 */ 1,
/* 1156 */ 50044,
/* 1157 */ -1154,
/* 1158 */ 1,
/* 1159 */ 0,
/* 1160 */ -1154,
/* 1161 */ 2,
/* 1162 */ 1166,
/* 1163 */ 50309,
/* 1164 */ -1162,
/* 1165 */ 1,
/* 1166 */ 1170,
/* 1167 */ 50307,
/* 1168 */ -1162,
/* 1169 */ 2,
/* 1170 */ 1174,
/* 1171 */ 50308,
/* 1172 */ -1162,
/* 1173 */ 3,
/* 1174 */ 0,
/* 1175 */ 1,
/* 1176 */ -1162,
/* 1177 */ 4,
/* 1178 */ 0,
/* 1179 */ 50299,
/* 1180 */ -1178,
/* 1181 */ 1,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 89002,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 89002,
/* 6 */ 9999,
/* 7 */ 89004,
/* 8 */ 9999,
/* 9 */ 89004,
/* 10 */ 9999,
/* 11 */ 89006,
/* 12 */ 89025,
/* 13 */ 9999,
/* 14 */ 89025,
/* 15 */ 9999,
/* 16 */ 9999,
/* 17 */ 89025,
/* 18 */ 9999,
/* 19 */ 93004,
/* 20 */ 9999,
/* 21 */ 93022,
/* 22 */ 9999,
/* 23 */ 94004,
/* 24 */ 9999,
/* 25 */ 94014,
/* 26 */ 9999,
/* 27 */ 98004,
/* 28 */ 98032,
/* 29 */ 98043,
/* 30 */ 98065,
/* 31 */ 9999,
/* 32 */ 98004,
/* 33 */ 9999,
/* 34 */ 98006,
/* 35 */ 9999,
/* 36 */ 98027,
/* 37 */ 9999,
/* 38 */ 9999,
/* 39 */ 98027,
/* 40 */ 9999,
/* 41 */ 98045,
/* 42 */ 9999,
/* 43 */ 98060,
/* 44 */ 9999,
/* 45 */ 9999,
/* 46 */ 98060,
/* 47 */ 9999,
/* 48 */ 9999,
/* 49 */ 9999,
/* 50 */ 98067,
/* 51 */ 9999,
/* 52 */ 98100,
/* 53 */ 9999,
/* 54 */ 98117,
/* 55 */ 9999,
/* 56 */ 102004,
/* 57 */ 102027,
/* 58 */ 9999,
/* 59 */ 9999,
/* 60 */ 102025,
/* 61 */ 9999,
/* 62 */ 102029,
/* 63 */ 9999,
/* 64 */ 102048,
/* 65 */ 9999,
/* 66 */ 9999,
/* 67 */ 102048,
/* 68 */ 9999,
/* 69 */ 106004,
/* 70 */ 106016,
/* 71 */ 9999,
/* 72 */ 106014,
/* 73 */ 9999,
/* 74 */ 106018,
/* 75 */ 106028,
/* 76 */ 9999,
/* 77 */ 106028,
/* 78 */ 9999,
/* 79 */ 9999,
/* 80 */ 106028,
/* 81 */ 9999,
/* 82 */ 110004,
/* 83 */ 9999,
/* 84 */ 110004,
/* 85 */ 9999,
/* 86 */ 110006,
/* 87 */ 110028,
/* 88 */ 9999,
/* 89 */ 110028,
/* 90 */ 9999,
/* 91 */ 110032,
/* 92 */ 110045,
/* 93 */ 9999,
/* 94 */ 110045,
/* 95 */ 9999,
/* 96 */ 110049,
/* 97 */ 110062,
/* 98 */ 9999,
/* 99 */ 110062,
/* 100 */ 9999,
/* 101 */ 9999,
/* 102 */ 110062,
/* 103 */ 9999,
/* 104 */ 114004,
/* 105 */ 9999,
/* 106 */ 114004,
/* 107 */ 9999,
/* 108 */ 9999,
/* 109 */ 9999,
/* 110 */ 114009,
/* 111 */ 9999,
/* 112 */ 9999,
/* 113 */ 9999,
/* 114 */ 115011,
/* 115 */ 9999,
/* 116 */ 9999,
/* 117 */ 9999,
/* 118 */ 116009,
/* 119 */ 9999,
/* 120 */ 9999,
/* 121 */ 9999,
/* 122 */ 117009,
/* 123 */ 9999,
/* 124 */ 9999,
/* 125 */ 9999,
/* 126 */ 118010,
/* 127 */ 9999,
/* 128 */ 123004,
/* 129 */ 9999,
/* 130 */ 123004,
/* 131 */ 9999,
/* 132 */ 132004,
/* 133 */ 9999,
/* 134 */ 132028,
/* 135 */ 9999,
/* 136 */ 132032,
/* 137 */ 9999,
/* 138 */ 132045,
/* 139 */ 9999,
/* 140 */ 133004,
/* 141 */ 9999,
/* 142 */ 133005,
/* 143 */ 9999,
/* 144 */ 9999,
/* 145 */ 9999,
/* 146 */ 123009,
/* 147 */ 9999,
/* 148 */ 9999,
/* 149 */ 9999,
/* 150 */ 124007,
/* 151 */ 9999,
/* 152 */ 9999,
/* 153 */ 9999,
/* 154 */ 125008,
/* 155 */ 9999,
/* 156 */ 9999,
/* 157 */ 9999,
/* 158 */ 126006,
/* 159 */ 9999,
/* 160 */ 9999,
/* 161 */ 9999,
/* 162 */ 127007,
/* 163 */ 9999,
/* 164 */ 9999,
/* 165 */ 9999,
/* 166 */ 128008,
/* 167 */ 9999,
/* 168 */ 9999,
/* 169 */ 9999,
/* 170 */ 129009,
/* 171 */ 9999,
/* 172 */ 9999,
/* 173 */ 9999,
/* 174 */ 130009,
/* 175 */ 9999,
/* 176 */ 9999,
/* 177 */ 9999,
/* 178 */ 131011,
/* 179 */ 9999,
/* 180 */ 137004,
/* 181 */ 9999,
/* 182 */ 137004,
/* 183 */ 9999,
/* 184 */ 9999,
/* 185 */ 9999,
/* 186 */ 137010,
/* 187 */ 9999,
/* 188 */ 9999,
/* 189 */ 9999,
/* 190 */ 138011,
/* 191 */ 9999,
/* 192 */ 142004,
/* 193 */ 142020,
/* 194 */ 9999,
/* 195 */ 142059,
/* 196 */ 9999,
/* 197 */ 9999,
/* 198 */ 142018,
/* 199 */ 9999,
/* 200 */ 143004,
/* 201 */ 143020,
/* 202 */ 9999,
/* 203 */ 143018,
/* 204 */ 9999,
/* 205 */ 142022,
/* 206 */ 9999,
/* 207 */ 142023,
/* 208 */ 9999,
/* 209 */ 9999,
/* 210 */ 142023,
/* 211 */ 9999,
/* 212 */ 147004,
/* 213 */ 9999,
/* 214 */ 147004,
/* 215 */ 9999,
/* 216 */ 9999,
/* 217 */ 9999,
/* 218 */ 147011,
/* 219 */ 9999,
/* 220 */ 9999,
/* 221 */ 9999,
/* 222 */ 147019,
/* 223 */ 9999,
/* 224 */ 151004,
/* 225 */ 151033,
/* 226 */ 9999,
/* 227 */ 151004,
/* 228 */ 9999,
/* 229 */ 151006,
/* 230 */ 9999,
/* 231 */ 151028,
/* 232 */ 9999,
/* 233 */ 9999,
/* 234 */ 151028,
/* 235 */ 9999,
/* 236 */ 155004,
/* 237 */ 155045,
/* 238 */ 9999,
/* 239 */ 155004,
/* 240 */ 9999,
/* 241 */ 155006,
/* 242 */ 9999,
/* 243 */ 9999,
/* 244 */ 155025,
/* 245 */ 9999,
/* 246 */ 9999,
/* 247 */ 155025,
/* 248 */ 9999,
/* 249 */ 159004,
/* 250 */ 159036,
/* 251 */ 9999,
/* 252 */ 159004,
/* 253 */ 9999,
/* 254 */ 159006,
/* 255 */ 9999,
/* 256 */ 9999,
/* 257 */ 159015,
/* 258 */ 9999,
/* 259 */ 9999,
/* 260 */ 159015,
/* 261 */ 9999,
/* 262 */ 163004,
/* 263 */ 163029,
/* 264 */ 9999,
/* 265 */ 9999,
/* 266 */ 163027,
/* 267 */ 9999,
/* 268 */ 167004,
/* 269 */ 167040,
/* 270 */ 9999,
/* 271 */ 167004,
/* 272 */ 9999,
/* 273 */ 167006,
/* 274 */ 9999,
/* 275 */ 167019,
/* 276 */ 9999,
/* 277 */ 167023,
/* 278 */ 9999,
/* 279 */ 167036,
/* 280 */ 9999,
/* 281 */ 167042,
/* 282 */ 9999,
/* 283 */ 167065,
/* 284 */ 9999,
/* 285 */ 9999,
/* 286 */ 167065,
/* 287 */ 9999,
/* 288 */ 171004,
/* 289 */ 171047,
/* 290 */ 9999,
/* 291 */ 171004,
/* 292 */ 9999,
/* 293 */ 171006,
/* 294 */ 9999,
/* 295 */ 9999,
/* 296 */ 171027,
/* 297 */ 9999,
/* 298 */ 9999,
/* 299 */ 171027,
/* 300 */ 9999,
/* 301 */ 175004,
/* 302 */ 9999,
/* 303 */ 175013,
/* 304 */ 9999,
/* 305 */ 176004,
/* 306 */ 9999,
/* 307 */ 176034,
/* 308 */ 9999,
/* 309 */ 176004,
/* 310 */ 9999,
/* 311 */ 176006,
/* 312 */ 9999,
/* 313 */ 176015,
/* 314 */ 9999,
/* 315 */ 9999,
/* 316 */ 176015,
/* 317 */ 9999,
/* 318 */ 9999,
/* 319 */ 180019,
/* 320 */ 9999,
/* 321 */ 180058,
/* 322 */ 9999,
/* 323 */ 9999,
/* 324 */ 180007,
/* 325 */ 9999,
/* 326 */ 9999,
/* 327 */ 181019,
/* 328 */ 9999,
/* 329 */ 181007,
/* 330 */ 9999,
/* 331 */ 180021,
/* 332 */ 9999,
/* 333 */ 180022,
/* 334 */ 9999,
/* 335 */ 9999,
/* 336 */ 180022,
/* 337 */ 9999,
/* 338 */ 185004,
/* 339 */ 185040,
/* 340 */ 9999,
/* 341 */ 185004,
/* 342 */ 9999,
/* 343 */ 185006,
/* 344 */ 9999,
/* 345 */ 9999,
/* 346 */ 185020,
/* 347 */ 9999,
/* 348 */ 9999,
/* 349 */ 185020,
/* 350 */ 9999,
/* 351 */ 189004,
/* 352 */ 189007,
/* 353 */ 9999,
/* 354 */ 189005,
/* 355 */ 9999,
/* 356 */ 9999,
/* 357 */ 189025,
/* 358 */ 9999,
/* 359 */ 189009,
/* 360 */ 9999,
/* 361 */ 9999,
/* 362 */ 189009,
/* 363 */ 9999,
/* 364 */ 193004,
/* 365 */ 193017,
/* 366 */ 9999,
/* 367 */ 193004,
/* 368 */ 9999,
/* 369 */ 193006,
/* 370 */ 9999,
/* 371 */ 193012,
/* 372 */ 9999,
/* 373 */ 9999,
/* 374 */ 193012,
/* 375 */ 9999,
/* 376 */ 197004,
/* 377 */ 9999,
/* 378 */ 197005,
/* 379 */ 9999,
/* 380 */ 9999,
/* 381 */ 198018,
/* 382 */ 9999,
/* 383 */ 9999,
/* 384 */ 198004,
/* 385 */ 9999,
/* 386 */ 199004,
/* 387 */ 199022,
/* 388 */ 9999,
/* 389 */ 199020,
/* 390 */ 9999,
/* 391 */ 9999,
/* 392 */ 199038,
/* 393 */ 9999,
/* 394 */ 9999,
/* 395 */ 199024,
/* 396 */ 9999,
/* 397 */ 9999,
/* 398 */ 199093,
/* 399 */ 9999,
/* 400 */ 9999,
/* 401 */ 199079,
/* 402 */ 9999,
/* 403 */ 9999,
/* 404 */ 199143,
/* 405 */ 9999,
/* 406 */ 9999,
/* 407 */ 199129,
/* 408 */ 9999,
/* 409 */ 199040,
/* 410 */ 9999,
/* 411 */ 199058,
/* 412 */ 9999,
/* 413 */ 9999,
/* 414 */ 199058,
/* 415 */ 9999,
/* 416 */ 199145,
/* 417 */ 9999,
/* 418 */ 199159,
/* 419 */ 9999,
/* 420 */ 9999,
/* 421 */ 199159,
/* 422 */ 9999,
/* 423 */ 9999,
/* 424 */ 203018,
/* 425 */ 203043,
/* 426 */ 9999,
/* 427 */ 203004,
/* 428 */ 9999,
/* 429 */ 203020,
/* 430 */ 9999,
/* 431 */ 203038,
/* 432 */ 9999,
/* 433 */ 9999,
/* 434 */ 203038,
/* 435 */ 9999,
/* 436 */ 203045,
/* 437 */ 9999,
/* 438 */ 203051,
/* 439 */ 9999,
/* 440 */ 9999,
/* 441 */ 203051,
/* 442 */ 9999,
/* 443 */ 207004,
/* 444 */ 207029,
/* 445 */ 9999,
/* 446 */ 207004,
/* 447 */ 9999,
/* 448 */ 207006,
/* 449 */ 9999,
/* 450 */ 207024,
/* 451 */ 9999,
/* 452 */ 9999,
/* 453 */ 207024,
/* 454 */ 9999,
/* 455 */ 211004,
/* 456 */ 211019,
/* 457 */ 9999,
/* 458 */ 211017,
/* 459 */ 9999,
/* 460 */ 9999,
/* 461 */ 9999,
/* 462 */ 9999,
/* 463 */ 211021,
/* 464 */ 9999,
/* 465 */ 9999,
/* 466 */ 211021,
/* 467 */ 9999,
/* 468 */ 215004,
/* 469 */ 215039,
/* 470 */ 9999,
/* 471 */ 215004,
/* 472 */ 9999,
/* 473 */ 215006,
/* 474 */ 9999,
/* 475 */ 9999,
/* 476 */ 215019,
/* 477 */ 9999,
/* 478 */ 9999,
/* 479 */ 215019,
/* 480 */ 9999,
/* 481 */ 219004,
/* 482 */ 219027,
/* 483 */ 9999,
/* 484 */ 219025,
/* 485 */ 9999,
/* 486 */ 219029,
/* 487 */ 9999,
/* 488 */ 219038,
/* 489 */ 9999,
/* 490 */ 219042,
/* 491 */ 9999,
/* 492 */ 219042,
/* 493 */ 9999,
/* 494 */ 219044,
/* 495 */ 9999,
/* 496 */ 219062,
/* 497 */ 9999,
/* 498 */ 9999,
/* 499 */ 219062,
/* 500 */ 9999,
/* 501 */ 223004,
/* 502 */ 223040,
/* 503 */ 9999,
/* 504 */ 223004,
/* 505 */ 9999,
/* 506 */ 223006,
/* 507 */ 9999,
/* 508 */ 9999,
/* 509 */ 223020,
/* 510 */ 9999,
/* 511 */ 9999,
/* 512 */ 223020,
/* 513 */ 9999,
/* 514 */ 227004,
/* 515 */ 9999,
/* 516 */ 227024,
/* 517 */ 9999,
/* 518 */ 9999,
/* 519 */ 228029,
/* 520 */ 228046,
/* 521 */ 9999,
/* 522 */ 9999,
/* 523 */ 228004,
/* 524 */ 9999,
/* 525 */ 9999,
/* 526 */ 9999,
/* 527 */ 228048,
/* 528 */ 9999,
/* 529 */ 9999,
/* 530 */ 228048,
/* 531 */ 9999,
/* 532 */ 232004,
/* 533 */ 232041,
/* 534 */ 9999,
/* 535 */ 232004,
/* 536 */ 9999,
/* 537 */ 232006,
/* 538 */ 9999,
/* 539 */ 9999,
/* 540 */ 232021,
/* 541 */ 9999,
/* 542 */ 9999,
/* 543 */ 232021,
/* 544 */ 9999,
/* 545 */ 236004,
/* 546 */ 236029,
/* 547 */ 9999,
/* 548 */ 236027,
/* 549 */ 9999,
/* 550 */ 236031,
/* 551 */ 9999,
/* 552 */ 236049,
/* 553 */ 9999,
/* 554 */ 9999,
/* 555 */ 236049,
/* 556 */ 9999,
/* 557 */ 240004,
/* 558 */ 9999,
/* 559 */ 240010,
/* 560 */ 9999,
/* 561 */ 241004,
/* 562 */ 241017,
/* 563 */ 9999,
/* 564 */ 241004,
/* 565 */ 9999,
/* 566 */ 241006,
/* 567 */ 9999,
/* 568 */ 241012,
/* 569 */ 9999,
/* 570 */ 9999,
/* 571 */ 241012,
/* 572 */ 9999,
/* 573 */ 9999,
/* 574 */ 245018,
/* 575 */ 9999,
/* 576 */ 9999,
/* 577 */ 245004,
/* 578 */ 9999,
/* 579 */ 246004,
/* 580 */ 246036,
/* 581 */ 9999,
/* 582 */ 246004,
/* 583 */ 9999,
/* 584 */ 246006,
/* 585 */ 9999,
/* 586 */ 246031,
/* 587 */ 9999,
/* 588 */ 9999,
/* 589 */ 246031,
/* 590 */ 9999,
/* 591 */ 9999,
/* 592 */ 246052,
/* 593 */ 9999,
/* 594 */ 9999,
/* 595 */ 246038,
/* 596 */ 9999,
/* 597 */ 9999,
/* 598 */ 246107,
/* 599 */ 9999,
/* 600 */ 9999,
/* 601 */ 246093,
/* 602 */ 9999,
/* 603 */ 246054,
/* 604 */ 9999,
/* 605 */ 246072,
/* 606 */ 9999,
/* 607 */ 9999,
/* 608 */ 246072,
/* 609 */ 9999,
/* 610 */ 246109,
/* 611 */ 9999,
/* 612 */ 246127,
/* 613 */ 9999,
/* 614 */ 9999,
/* 615 */ 246127,
/* 616 */ 9999,
/* 617 */ 250004,
/* 618 */ 9999,
/* 619 */ 250005,
/* 620 */ 9999,
/* 621 */ 254004,
/* 622 */ 9999,
/* 623 */ 254020,
/* 624 */ 9999,
/* 625 */ 255004,
/* 626 */ 9999,
/* 627 */ 255023,
/* 628 */ 9999,
/* 629 */ 256004,
/* 630 */ 9999,
/* 631 */ 256021,
/* 632 */ 9999,
/* 633 */ 257004,
/* 634 */ 9999,
/* 635 */ 257022,
/* 636 */ 9999,
/* 637 */ 258004,
/* 638 */ 9999,
/* 639 */ 258022,
/* 640 */ 9999,
/* 641 */ 259004,
/* 642 */ 9999,
/* 643 */ 259017,
/* 644 */ 9999,
/* 645 */ 263004,
/* 646 */ 9999,
/* 647 */ 263021,
/* 648 */ 9999,
/* 649 */ 263005,
/* 650 */ 9999,
/* 651 */ 9999,
/* 652 */ 264019,
/* 653 */ 9999,
/* 654 */ 264053,
/* 655 */ 9999,
/* 656 */ 264007,
/* 657 */ 9999,
/* 658 */ 9999,
/* 659 */ 9999,
/* 660 */ 265036,
/* 661 */ 9999,
/* 662 */ 265010,
/* 663 */ 9999,
/* 664 */ 269004,
/* 665 */ 9999,
/* 666 */ 9999,
/* 667 */ 269004,
/* 668 */ 9999,
/* 669 */ 269006,
/* 670 */ 9999,
/* 671 */ 269015,
/* 672 */ 9999,
/* 673 */ 9999,
/* 674 */ 269015,
/* 675 */ 9999,
/* 676 */ 9999,
/* 677 */ 273038,
/* 678 */ 273060,
/* 679 */ 9999,
/* 680 */ 9999,
/* 681 */ 273004,
/* 682 */ 9999,
/* 683 */ 273040,
/* 684 */ 9999,
/* 685 */ 273055,
/* 686 */ 9999,
/* 687 */ 9999,
/* 688 */ 273055,
/* 689 */ 9999,
/* 690 */ 273062,
/* 691 */ 9999,
/* 692 */ 273075,
/* 693 */ 9999,
/* 694 */ 9999,
/* 695 */ 273075,
/* 696 */ 9999,
/* 697 */ 277004,
/* 698 */ 277024,
/* 699 */ 9999,
/* 700 */ 277004,
/* 701 */ 9999,
/* 702 */ 277006,
/* 703 */ 9999,
/* 704 */ 277019,
/* 705 */ 9999,
/* 706 */ 9999,
/* 707 */ 277019,
/* 708 */ 9999,
/* 709 */ 9999,
/* 710 */ 9999,
/* 711 */ 281031,
/* 712 */ 9999,
/* 713 */ 281056,
/* 714 */ 281066,
/* 715 */ 9999,
/* 716 */ 281005,
/* 717 */ 9999,
/* 718 */ 9999,
/* 719 */ 9999,
/* 720 */ 282035,
/* 721 */ 9999,
/* 722 */ 282060,
/* 723 */ 9999,
/* 724 */ 282009,
/* 725 */ 9999,
/* 726 */ 9999,
/* 727 */ 281083,
/* 728 */ 9999,
/* 729 */ 281071,
/* 730 */ 9999,
/* 731 */ 9999,
/* 732 */ 281071,
/* 733 */ 9999,
/* 734 */ 9999,
/* 735 */ 9999,
/* 736 */ 286034,
/* 737 */ 9999,
/* 738 */ 286059,
/* 739 */ 9999,
/* 740 */ 286008,
/* 741 */ 9999,
/* 742 */ 9999,
/* 743 */ 287017,
/* 744 */ 9999,
/* 745 */ 9999,
/* 746 */ 287057,
/* 747 */ 9999,
/* 748 */ 9999,
/* 749 */ 9999,
/* 750 */ 287005,
/* 751 */ 9999,
/* 752 */ 9999,
/* 753 */ 9999,
/* 754 */ 288032,
/* 755 */ 9999,
/* 756 */ 288063,
/* 757 */ 9999,
/* 758 */ 288094,
/* 759 */ 9999,
/* 760 */ 288124,
/* 761 */ 9999,
/* 762 */ 288006,
/* 763 */ 9999,
/* 764 */ 288034,
/* 765 */ 9999,
/* 766 */ 288043,
/* 767 */ 9999,
/* 768 */ 9999,
/* 769 */ 288043,
/* 770 */ 9999,
/* 771 */ 288065,
/* 772 */ 9999,
/* 773 */ 288074,
/* 774 */ 9999,
/* 775 */ 9999,
/* 776 */ 288074,
/* 777 */ 9999,
/* 778 */ 288096,
/* 779 */ 9999,
/* 780 */ 288105,
/* 781 */ 9999,
/* 782 */ 9999,
/* 783 */ 288105,
/* 784 */ 9999,
/* 785 */ 9999,
/* 786 */ 292019,
/* 787 */ 9999,
/* 788 */ 9999,
/* 789 */ 292007,
/* 790 */ 9999,
/* 791 */ 9999,
/* 792 */ 9999,
/* 793 */ 9999,
/* 794 */ 293011,
/* 795 */ 9999,
/* 796 */ 9999,
/* 797 */ 9999,
/* 798 */ 9999,
/* 799 */ 294008,
/* 800 */ 9999,
/* 801 */ 9999,
/* 802 */ 295021,
/* 803 */ 9999,
/* 804 */ 9999,
/* 805 */ 295009,
/* 806 */ 9999,
/* 807 */ 295023,
/* 808 */ 9999,
/* 809 */ 295032,
/* 810 */ 9999,
/* 811 */ 9999,
/* 812 */ 295032,
/* 813 */ 9999,
/* 814 */ 299004,
/* 815 */ 299035,
/* 816 */ 9999,
/* 817 */ 299004,
/* 818 */ 9999,
/* 819 */ 299006,
/* 820 */ 9999,
/* 821 */ 9999,
/* 822 */ 299015,
/* 823 */ 9999,
/* 824 */ 9999,
/* 825 */ 299015,
/* 826 */ 9999,
/* 827 */ 303004,
/* 828 */ 9999,
/* 829 */ 303025,
/* 830 */ 9999,
/* 831 */ 304004,
/* 832 */ 304021,
/* 833 */ 304041,
/* 834 */ 9999,
/* 835 */ 304019,
/* 836 */ 9999,
/* 837 */ 9999,
/* 838 */ 9999,
/* 839 */ 308009,
/* 840 */ 9999,
/* 841 */ 9999,
/* 842 */ 9999,
/* 843 */ 309004,
/* 844 */ 9999,
/* 845 */ 313004,
/* 846 */ 313026,
/* 847 */ 9999,
/* 848 */ 313024,
/* 849 */ 9999,
/* 850 */ 9999,
/* 851 */ 313042,
/* 852 */ 9999,
/* 853 */ 313067,
/* 854 */ 9999,
/* 855 */ 313028,
/* 856 */ 9999,
/* 857 */ 9999,
/* 858 */ 313028,
/* 859 */ 9999,
/* 860 */ 317004,
/* 861 */ 9999,
/* 862 */ 317025,
/* 863 */ 9999,
/* 864 */ 321004,
/* 865 */ 321073,
/* 866 */ 9999,
/* 867 */ 321004,
/* 868 */ 9999,
/* 869 */ 321006,
/* 870 */ 9999,
/* 871 */ 9999,
/* 872 */ 321026,
/* 873 */ 9999,
/* 874 */ 9999,
/* 875 */ 321026,
/* 876 */ 9999,
/* 877 */ 325004,
/* 878 */ 325077,
/* 879 */ 9999,
/* 880 */ 325004,
/* 881 */ 9999,
/* 882 */ 325006,
/* 883 */ 9999,
/* 884 */ 9999,
/* 885 */ 325027,
/* 886 */ 9999,
/* 887 */ 9999,
/* 888 */ 325027,
/* 889 */ 9999,
/* 890 */ 329004,
/* 891 */ 329052,
/* 892 */ 9999,
/* 893 */ 329004,
/* 894 */ 9999,
/* 895 */ 329006,
/* 896 */ 9999,
/* 897 */ 9999,
/* 898 */ 329028,
/* 899 */ 9999,
/* 900 */ 9999,
/* 901 */ 329028,
/* 902 */ 9999,
/* 903 */ 333004,
/* 904 */ 333053,
/* 905 */ 9999,
/* 906 */ 333004,
/* 907 */ 9999,
/* 908 */ 333006,
/* 909 */ 9999,
/* 910 */ 9999,
/* 911 */ 333028,
/* 912 */ 9999,
/* 913 */ 9999,
/* 914 */ 333028,
/* 915 */ 9999,
/* 916 */ 337004,
/* 917 */ 337043,
/* 918 */ 9999,
/* 919 */ 337004,
/* 920 */ 9999,
/* 921 */ 337005,
/* 922 */ 9999,
/* 923 */ 9999,
/* 924 */ 337018,
/* 925 */ 9999,
/* 926 */ 9999,
/* 927 */ 337018,
/* 928 */ 9999,
/* 929 */ 341004,
/* 930 */ 341075,
/* 931 */ 9999,
/* 932 */ 341004,
/* 933 */ 9999,
/* 934 */ 341006,
/* 935 */ 9999,
/* 936 */ 9999,
/* 937 */ 341024,
/* 938 */ 9999,
/* 939 */ 9999,
/* 940 */ 341024,
/* 941 */ 9999,
/* 942 */ 345004,
/* 943 */ 345115,
/* 944 */ 9999,
/* 945 */ 345004,
/* 946 */ 9999,
/* 947 */ 345005,
/* 948 */ 9999,
/* 949 */ 9999,
/* 950 */ 345020,
/* 951 */ 9999,
/* 952 */ 9999,
/* 953 */ 345020,
/* 954 */ 9999,
/* 955 */ 349004,
/* 956 */ 349055,
/* 957 */ 9999,
/* 958 */ 349004,
/* 959 */ 9999,
/* 960 */ 349006,
/* 961 */ 349026,
/* 962 */ 9999,
/* 963 */ 349024,
/* 964 */ 9999,
/* 965 */ 9999,
/* 966 */ 349024,
/* 967 */ 9999,
/* 968 */ 9999,
/* 969 */ 9999,
/* 970 */ 349028,
/* 971 */ 9999,
/* 972 */ 9999,
/* 973 */ 9999,
/* 974 */ 349034,
/* 975 */ 9999,
/* 976 */ 353004,
/* 977 */ 353067,
/* 978 */ 9999,
/* 979 */ 353004,
/* 980 */ 9999,
/* 981 */ 353006,
/* 982 */ 353032,
/* 983 */ 9999,
/* 984 */ 353030,
/* 985 */ 9999,
/* 986 */ 9999,
/* 987 */ 353030,
/* 988 */ 9999,
/* 989 */ 9999,
/* 990 */ 9999,
/* 991 */ 353034,
/* 992 */ 9999,
/* 993 */ 9999,
/* 994 */ 9999,
/* 995 */ 353040,
/* 996 */ 9999,
/* 997 */ 9999,
/* 998 */ 9999,
/* 999 */ 353046,
/* 1000 */ 9999,
/* 1001 */ 357004,
/* 1002 */ 9999,
/* 1003 */ 357019,
/* 1004 */ 9999,
/* 1005 */ 9999,
/* 1006 */ 358018,
/* 1007 */ 9999,
/* 1008 */ 358042,
/* 1009 */ 9999,
/* 1010 */ 358004,
/* 1011 */ 9999,
/* 1012 */ 362004,
/* 1013 */ 9999,
/* 1014 */ 362021,
/* 1015 */ 9999,
/* 1016 */ 363004,
/* 1017 */ 363064,
/* 1018 */ 9999,
/* 1019 */ 363004,
/* 1020 */ 9999,
/* 1021 */ 364004,
/* 1022 */ 364019,
/* 1023 */ 9999,
/* 1024 */ 364017,
/* 1025 */ 9999,
/* 1026 */ 9999,
/* 1027 */ 365021,
/* 1028 */ 9999,
/* 1029 */ 365009,
/* 1030 */ 9999,
/* 1031 */ 9999,
/* 1032 */ 9999,
/* 1033 */ 366035,
/* 1034 */ 9999,
/* 1035 */ 9999,
/* 1036 */ 366009,
/* 1037 */ 9999,
/* 1038 */ 9999,
/* 1039 */ 9999,
/* 1040 */ 363011,
/* 1041 */ 9999,
/* 1042 */ 9999,
/* 1043 */ 9999,
/* 1044 */ 363040,
/* 1045 */ 9999,
/* 1046 */ 370004,
/* 1047 */ 9999,
/* 1048 */ 370004,
/* 1049 */ 9999,
/* 1050 */ 9999,
/* 1051 */ 9999,
/* 1052 */ 370011,
/* 1053 */ 9999,
/* 1054 */ 9999,
/* 1055 */ 9999,
/* 1056 */ 370015,
/* 1057 */ 9999,
/* 1058 */ 9999,
/* 1059 */ 9999,
/* 1060 */ 370021,
/* 1061 */ 9999,
/* 1062 */ 9999,
/* 1063 */ 9999,
/* 1064 */ 370027,
/* 1065 */ 9999,
/* 1066 */ 9999,
/* 1067 */ 9999,
/* 1068 */ 370033,
/* 1069 */ 9999,
/* 1070 */ 9999,
/* 1071 */ 9999,
/* 1072 */ 370039,
/* 1073 */ 9999,
/* 1074 */ 9999,
/* 1075 */ 9999,
/* 1076 */ 370051,
/* 1077 */ 9999,
/* 1078 */ 9999,
/* 1079 */ 9999,
/* 1080 */ 370060,
/* 1081 */ 9999,
/* 1082 */ 9999,
/* 1083 */ 9999,
/* 1084 */ 370070,
/* 1085 */ 9999,
/* 1086 */ 374004,
/* 1087 */ 9999,
/* 1088 */ 374021,
/* 1089 */ 9999,
/* 1090 */ 375004,
/* 1091 */ 375023,
/* 1092 */ 9999,
/* 1093 */ 375021,
/* 1094 */ 9999,
/* 1095 */ 9999,
/* 1096 */ 375039,
/* 1097 */ 9999,
/* 1098 */ 9999,
/* 1099 */ 375025,
/* 1100 */ 9999,
/* 1101 */ 9999,
/* 1102 */ 375080,
/* 1103 */ 9999,
/* 1104 */ 9999,
/* 1105 */ 375066,
/* 1106 */ 9999,
/* 1107 */ 9999,
/* 1108 */ 375140,
/* 1109 */ 9999,
/* 1110 */ 375126,
/* 1111 */ 9999,
/* 1112 */ 9999,
/* 1113 */ 375184,
/* 1114 */ 9999,
/* 1115 */ 375150,
/* 1116 */ 9999,
/* 1117 */ 9999,
/* 1118 */ 9999,
/* 1119 */ 375194,
/* 1120 */ 9999,
/* 1121 */ 9999,
/* 1122 */ 9999,
/* 1123 */ 375223,
/* 1124 */ 9999,
/* 1125 */ 375082,
/* 1126 */ 9999,
/* 1127 */ 375105,
/* 1128 */ 9999,
/* 1129 */ 9999,
/* 1130 */ 375105,
/* 1131 */ 9999,
/* 1132 */ 379004,
/* 1133 */ 9999,
/* 1134 */ 379005,
/* 1135 */ 9999,
/* 1136 */ 380004,
/* 1137 */ 9999,
/* 1138 */ 380011,
/* 1139 */ 9999,
/* 1140 */ 9999,
/* 1141 */ 9999,
/* 1142 */ 381009,
/* 1143 */ 9999,
/* 1144 */ 9999,
/* 1145 */ 382018,
/* 1146 */ 9999,
/* 1147 */ 9999,
/* 1148 */ 382004,
/* 1149 */ 9999,
/* 1150 */ 386004,
/* 1151 */ 386049,
/* 1152 */ 9999,
/* 1153 */ 386004,
/* 1154 */ 9999,
/* 1155 */ 386006,
/* 1156 */ 9999,
/* 1157 */ 9999,
/* 1158 */ 386029,
/* 1159 */ 9999,
/* 1160 */ 9999,
/* 1161 */ 386029,
/* 1162 */ 9999,
/* 1163 */ 9999,
/* 1164 */ 9999,
/* 1165 */ 390011,
/* 1166 */ 9999,
/* 1167 */ 9999,
/* 1168 */ 9999,
/* 1169 */ 391012,
/* 1170 */ 9999,
/* 1171 */ 9999,
/* 1172 */ 9999,
/* 1173 */ 392013,
/* 1174 */ 9999,
/* 1175 */ 393004,
/* 1176 */ 9999,
/* 1177 */ 393005,
/* 1178 */ 9999,
/* 1179 */ 9999,
/* 1180 */ 9999,
/* 1181 */ 397013,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[1183];
*/
int TABLE[269][310];
init_dirsets() {
TABLE[105][0] = 1;
TABLE[105][59] = 1;
TABLE[105][123] = 1;
TABLE[105][40] = 1;
TABLE[105][42] = 1;
TABLE[105][299] = 1;
TABLE[105][44] = 1;
TABLE[105][61] = 1;
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
TABLE[105][278] = 1;
TABLE[105][283] = 1;
TABLE[105][280] = 1;
TABLE[105][63] = 1;
TABLE[105][294] = 1;
TABLE[105][295] = 1;
TABLE[105][297] = 1;
TABLE[105][303] = 1;
TABLE[105][301] = 1;
TABLE[105][305] = 1;
TABLE[105][33] = 1;
TABLE[105][126] = 1;
TABLE[105][45] = 1;
TABLE[105][43] = 1;
TABLE[105][302] = 1;
TABLE[105][289] = 1;
TABLE[105][298] = 1;
TABLE[105][309] = 1;
TABLE[105][307] = 1;
TABLE[105][308] = 1;
TABLE[105][292] = 1;
TABLE[105][304] = 1;
TABLE[105][47] = 1;
TABLE[105][37] = 1;
TABLE[1][0] = 1;
TABLE[1][59] = 1;
TABLE[1][40] = 1;
TABLE[1][123] = 1;
TABLE[1][44] = 1;
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
TABLE[1][61] = 1;
TABLE[1][280] = 1;
TABLE[1][283] = 1;
TABLE[1][278] = 1;
TABLE[1][295] = 1;
TABLE[1][294] = 1;
TABLE[1][63] = 1;
TABLE[1][289] = 1;
TABLE[1][302] = 1;
TABLE[1][43] = 1;
TABLE[1][45] = 1;
TABLE[1][126] = 1;
TABLE[1][33] = 1;
TABLE[1][305] = 1;
TABLE[1][301] = 1;
TABLE[1][303] = 1;
TABLE[1][297] = 1;
TABLE[1][308] = 1;
TABLE[1][307] = 1;
TABLE[1][309] = 1;
TABLE[1][298] = 1;
TABLE[1][292] = 1;
TABLE[1][304] = 1;
TABLE[1][37] = 1;
TABLE[1][47] = 1;
TABLE[106][0] = 1;
TABLE[106][59] = 1;
TABLE[106][123] = 1;
TABLE[106][40] = 1;
TABLE[106][42] = 1;
TABLE[106][299] = 1;
TABLE[106][44] = 1;
TABLE[106][61] = 1;
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
TABLE[106][278] = 1;
TABLE[106][283] = 1;
TABLE[106][280] = 1;
TABLE[106][63] = 1;
TABLE[106][294] = 1;
TABLE[106][295] = 1;
TABLE[106][297] = 1;
TABLE[106][303] = 1;
TABLE[106][301] = 1;
TABLE[106][305] = 1;
TABLE[106][33] = 1;
TABLE[106][126] = 1;
TABLE[106][45] = 1;
TABLE[106][43] = 1;
TABLE[106][302] = 1;
TABLE[106][289] = 1;
TABLE[106][298] = 1;
TABLE[106][309] = 1;
TABLE[106][307] = 1;
TABLE[106][308] = 1;
TABLE[106][292] = 1;
TABLE[106][304] = 1;
TABLE[106][47] = 1;
TABLE[106][37] = 1;
TABLE[214][0] = 1;
TABLE[2][0] = 1;
TABLE[2][59] = 1;
TABLE[2][40] = 1;
TABLE[2][123] = 1;
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
TABLE[2][44] = 1;
TABLE[2][61] = 1;
TABLE[2][283] = 1;
TABLE[2][280] = 1;
TABLE[2][278] = 1;
TABLE[2][63] = 1;
TABLE[2][294] = 1;
TABLE[2][295] = 1;
TABLE[2][297] = 1;
TABLE[2][303] = 1;
TABLE[2][301] = 1;
TABLE[2][305] = 1;
TABLE[2][33] = 1;
TABLE[2][126] = 1;
TABLE[2][45] = 1;
TABLE[2][43] = 1;
TABLE[2][302] = 1;
TABLE[2][289] = 1;
TABLE[2][298] = 1;
TABLE[2][309] = 1;
TABLE[2][307] = 1;
TABLE[2][308] = 1;
TABLE[2][292] = 1;
TABLE[2][304] = 1;
TABLE[2][47] = 1;
TABLE[2][37] = 1;
TABLE[3][0] = 1;
TABLE[3][59] = 1;
TABLE[3][44] = 1;
TABLE[3][256] = 1;
TABLE[3][274] = 1;
TABLE[3][279] = 1;
TABLE[3][267] = 1;
TABLE[3][282] = 1;
TABLE[3][299] = 1;
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
TABLE[3][123] = 1;
TABLE[3][61] = 1;
TABLE[3][280] = 1;
TABLE[3][283] = 1;
TABLE[3][278] = 1;
TABLE[3][40] = 1;
TABLE[3][295] = 1;
TABLE[3][294] = 1;
TABLE[3][63] = 1;
TABLE[3][42] = 1;
TABLE[3][289] = 1;
TABLE[3][302] = 1;
TABLE[3][43] = 1;
TABLE[3][45] = 1;
TABLE[3][126] = 1;
TABLE[3][33] = 1;
TABLE[3][305] = 1;
TABLE[3][301] = 1;
TABLE[3][303] = 1;
TABLE[3][297] = 1;
TABLE[3][308] = 1;
TABLE[3][307] = 1;
TABLE[3][309] = 1;
TABLE[3][298] = 1;
TABLE[3][292] = 1;
TABLE[3][304] = 1;
TABLE[3][37] = 1;
TABLE[3][47] = 1;
TABLE[4][59] = 1;
TABLE[4][44] = 1;
TABLE[4][123] = 1;
TABLE[4][61] = 1;
TABLE[4][278] = 1;
TABLE[4][295] = 1;
TABLE[4][294] = 1;
TABLE[4][63] = 1;
TABLE[4][289] = 1;
TABLE[4][302] = 1;
TABLE[4][43] = 1;
TABLE[4][45] = 1;
TABLE[4][126] = 1;
TABLE[4][33] = 1;
TABLE[4][305] = 1;
TABLE[4][301] = 1;
TABLE[4][303] = 1;
TABLE[4][297] = 1;
TABLE[4][308] = 1;
TABLE[4][307] = 1;
TABLE[4][309] = 1;
TABLE[4][298] = 1;
TABLE[4][292] = 1;
TABLE[4][304] = 1;
TABLE[4][37] = 1;
TABLE[4][47] = 1;
TABLE[4][40] = 1;
TABLE[4][42] = 1;
TABLE[4][256] = 1;
TABLE[4][274] = 1;
TABLE[4][279] = 1;
TABLE[4][267] = 1;
TABLE[4][282] = 1;
TABLE[4][299] = 1;
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
TABLE[107][44] = 1;
TABLE[107][61] = 1;
TABLE[107][278] = 1;
TABLE[107][40] = 1;
TABLE[107][295] = 1;
TABLE[107][294] = 1;
TABLE[107][63] = 1;
TABLE[107][42] = 1;
TABLE[107][289] = 1;
TABLE[107][302] = 1;
TABLE[107][43] = 1;
TABLE[107][45] = 1;
TABLE[107][126] = 1;
TABLE[107][33] = 1;
TABLE[107][305] = 1;
TABLE[107][301] = 1;
TABLE[107][303] = 1;
TABLE[107][297] = 1;
TABLE[107][308] = 1;
TABLE[107][307] = 1;
TABLE[107][309] = 1;
TABLE[107][298] = 1;
TABLE[107][292] = 1;
TABLE[107][304] = 1;
TABLE[107][37] = 1;
TABLE[107][47] = 1;
TABLE[107][59] = 1;
TABLE[107][123] = 1;
TABLE[107][286] = 1;
TABLE[107][260] = 1;
TABLE[107][284] = 1;
TABLE[107][277] = 1;
TABLE[107][264] = 1;
TABLE[107][268] = 1;
TABLE[107][273] = 1;
TABLE[107][272] = 1;
TABLE[107][276] = 1;
TABLE[107][259] = 1;
TABLE[107][285] = 1;
TABLE[107][266] = 1;
TABLE[107][299] = 1;
TABLE[107][282] = 1;
TABLE[107][267] = 1;
TABLE[107][279] = 1;
TABLE[107][274] = 1;
TABLE[107][256] = 1;
TABLE[107][283] = 1;
TABLE[107][280] = 1;
TABLE[215][44] = 1;
TABLE[215][256] = 1;
TABLE[215][274] = 1;
TABLE[215][279] = 1;
TABLE[215][267] = 1;
TABLE[215][282] = 1;
TABLE[215][299] = 1;
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
TABLE[215][61] = 1;
TABLE[215][280] = 1;
TABLE[215][283] = 1;
TABLE[215][278] = 1;
TABLE[215][40] = 1;
TABLE[215][295] = 1;
TABLE[215][294] = 1;
TABLE[215][63] = 1;
TABLE[215][42] = 1;
TABLE[215][289] = 1;
TABLE[215][302] = 1;
TABLE[215][43] = 1;
TABLE[215][45] = 1;
TABLE[215][126] = 1;
TABLE[215][33] = 1;
TABLE[215][305] = 1;
TABLE[215][301] = 1;
TABLE[215][303] = 1;
TABLE[215][297] = 1;
TABLE[215][308] = 1;
TABLE[215][307] = 1;
TABLE[215][309] = 1;
TABLE[215][298] = 1;
TABLE[215][292] = 1;
TABLE[215][304] = 1;
TABLE[215][37] = 1;
TABLE[215][47] = 1;
TABLE[215][59] = 1;
TABLE[215][123] = 1;
TABLE[108][59] = 1;
TABLE[108][44] = 1;
TABLE[108][61] = 1;
TABLE[108][123] = 1;
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
TABLE[108][299] = 1;
TABLE[108][282] = 1;
TABLE[108][267] = 1;
TABLE[108][279] = 1;
TABLE[108][274] = 1;
TABLE[108][256] = 1;
TABLE[108][40] = 1;
TABLE[108][278] = 1;
TABLE[108][283] = 1;
TABLE[108][280] = 1;
TABLE[108][42] = 1;
TABLE[108][63] = 1;
TABLE[108][294] = 1;
TABLE[108][295] = 1;
TABLE[108][297] = 1;
TABLE[108][303] = 1;
TABLE[108][301] = 1;
TABLE[108][305] = 1;
TABLE[108][33] = 1;
TABLE[108][126] = 1;
TABLE[108][45] = 1;
TABLE[108][43] = 1;
TABLE[108][302] = 1;
TABLE[108][289] = 1;
TABLE[108][298] = 1;
TABLE[108][309] = 1;
TABLE[108][307] = 1;
TABLE[108][308] = 1;
TABLE[108][292] = 1;
TABLE[108][304] = 1;
TABLE[108][47] = 1;
TABLE[108][37] = 1;
TABLE[216][59] = 1;
TABLE[216][123] = 1;
TABLE[109][59] = 1;
TABLE[110][123] = 1;
TABLE[5][59] = 1;
TABLE[5][44] = 1;
TABLE[5][61] = 1;
TABLE[5][123] = 1;
TABLE[5][40] = 1;
TABLE[5][278] = 1;
TABLE[5][42] = 1;
TABLE[5][63] = 1;
TABLE[5][294] = 1;
TABLE[5][295] = 1;
TABLE[5][297] = 1;
TABLE[5][303] = 1;
TABLE[5][301] = 1;
TABLE[5][305] = 1;
TABLE[5][33] = 1;
TABLE[5][126] = 1;
TABLE[5][45] = 1;
TABLE[5][43] = 1;
TABLE[5][302] = 1;
TABLE[5][289] = 1;
TABLE[5][298] = 1;
TABLE[5][309] = 1;
TABLE[5][307] = 1;
TABLE[5][308] = 1;
TABLE[5][292] = 1;
TABLE[5][304] = 1;
TABLE[5][47] = 1;
TABLE[5][37] = 1;
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
TABLE[5][299] = 1;
TABLE[5][282] = 1;
TABLE[5][267] = 1;
TABLE[5][279] = 1;
TABLE[5][274] = 1;
TABLE[5][256] = 1;
TABLE[5][283] = 1;
TABLE[5][280] = 1;
TABLE[111][59] = 1;
TABLE[111][44] = 1;
TABLE[111][123] = 1;
TABLE[111][61] = 1;
TABLE[111][278] = 1;
TABLE[111][40] = 1;
TABLE[111][295] = 1;
TABLE[111][294] = 1;
TABLE[111][63] = 1;
TABLE[111][299] = 1;
TABLE[111][42] = 1;
TABLE[111][289] = 1;
TABLE[111][302] = 1;
TABLE[111][43] = 1;
TABLE[111][45] = 1;
TABLE[111][126] = 1;
TABLE[111][33] = 1;
TABLE[111][305] = 1;
TABLE[111][301] = 1;
TABLE[111][303] = 1;
TABLE[111][297] = 1;
TABLE[111][308] = 1;
TABLE[111][307] = 1;
TABLE[111][309] = 1;
TABLE[111][298] = 1;
TABLE[111][292] = 1;
TABLE[111][304] = 1;
TABLE[111][37] = 1;
TABLE[111][47] = 1;
TABLE[217][59] = 1;
TABLE[6][262] = 1;
TABLE[6][258] = 1;
TABLE[6][281] = 1;
TABLE[6][271] = 1;
TABLE[6][269] = 1;
TABLE[6][263] = 1;
TABLE[6][287] = 1;
TABLE[6][275] = 1;
TABLE[6][257] = 1;
TABLE[6][261] = 1;
TABLE[6][270] = 1;
TABLE[6][125] = 1;
TABLE[6][59] = 1;
TABLE[6][44] = 1;
TABLE[6][256] = 1;
TABLE[6][274] = 1;
TABLE[6][279] = 1;
TABLE[6][267] = 1;
TABLE[6][282] = 1;
TABLE[6][299] = 1;
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
TABLE[6][123] = 1;
TABLE[6][61] = 1;
TABLE[6][280] = 1;
TABLE[6][283] = 1;
TABLE[6][278] = 1;
TABLE[6][40] = 1;
TABLE[6][295] = 1;
TABLE[6][294] = 1;
TABLE[6][63] = 1;
TABLE[6][42] = 1;
TABLE[6][289] = 1;
TABLE[6][302] = 1;
TABLE[6][43] = 1;
TABLE[6][45] = 1;
TABLE[6][126] = 1;
TABLE[6][33] = 1;
TABLE[6][305] = 1;
TABLE[6][301] = 1;
TABLE[6][303] = 1;
TABLE[6][297] = 1;
TABLE[6][308] = 1;
TABLE[6][307] = 1;
TABLE[6][309] = 1;
TABLE[6][298] = 1;
TABLE[6][292] = 1;
TABLE[6][304] = 1;
TABLE[6][37] = 1;
TABLE[6][47] = 1;
TABLE[112][262] = 1;
TABLE[112][258] = 1;
TABLE[112][281] = 1;
TABLE[112][271] = 1;
TABLE[112][269] = 1;
TABLE[112][263] = 1;
TABLE[112][287] = 1;
TABLE[112][275] = 1;
TABLE[112][257] = 1;
TABLE[112][261] = 1;
TABLE[112][270] = 1;
TABLE[112][125] = 1;
TABLE[112][59] = 1;
TABLE[112][44] = 1;
TABLE[112][256] = 1;
TABLE[112][274] = 1;
TABLE[112][279] = 1;
TABLE[112][267] = 1;
TABLE[112][282] = 1;
TABLE[112][299] = 1;
TABLE[112][266] = 1;
TABLE[112][285] = 1;
TABLE[112][259] = 1;
TABLE[112][276] = 1;
TABLE[112][272] = 1;
TABLE[112][273] = 1;
TABLE[112][268] = 1;
TABLE[112][264] = 1;
TABLE[112][277] = 1;
TABLE[112][284] = 1;
TABLE[112][260] = 1;
TABLE[112][286] = 1;
TABLE[112][123] = 1;
TABLE[112][61] = 1;
TABLE[112][280] = 1;
TABLE[112][283] = 1;
TABLE[112][278] = 1;
TABLE[112][40] = 1;
TABLE[112][295] = 1;
TABLE[112][294] = 1;
TABLE[112][63] = 1;
TABLE[112][42] = 1;
TABLE[112][289] = 1;
TABLE[112][302] = 1;
TABLE[112][43] = 1;
TABLE[112][45] = 1;
TABLE[112][126] = 1;
TABLE[112][33] = 1;
TABLE[112][305] = 1;
TABLE[112][301] = 1;
TABLE[112][303] = 1;
TABLE[112][297] = 1;
TABLE[112][308] = 1;
TABLE[112][307] = 1;
TABLE[112][309] = 1;
TABLE[112][298] = 1;
TABLE[112][292] = 1;
TABLE[112][304] = 1;
TABLE[112][37] = 1;
TABLE[112][47] = 1;
TABLE[218][59] = 1;
TABLE[218][123] = 1;
TABLE[218][262] = 1;
TABLE[218][258] = 1;
TABLE[218][281] = 1;
TABLE[218][271] = 1;
TABLE[218][269] = 1;
TABLE[218][263] = 1;
TABLE[218][287] = 1;
TABLE[218][275] = 1;
TABLE[218][257] = 1;
TABLE[218][261] = 1;
TABLE[218][270] = 1;
TABLE[218][299] = 1;
TABLE[218][44] = 1;
TABLE[218][278] = 1;
TABLE[218][63] = 1;
TABLE[218][294] = 1;
TABLE[218][295] = 1;
TABLE[218][297] = 1;
TABLE[218][303] = 1;
TABLE[218][301] = 1;
TABLE[218][305] = 1;
TABLE[218][33] = 1;
TABLE[218][126] = 1;
TABLE[218][45] = 1;
TABLE[218][43] = 1;
TABLE[218][42] = 1;
TABLE[218][302] = 1;
TABLE[218][40] = 1;
TABLE[218][289] = 1;
TABLE[218][298] = 1;
TABLE[218][309] = 1;
TABLE[218][307] = 1;
TABLE[218][308] = 1;
TABLE[218][292] = 1;
TABLE[218][304] = 1;
TABLE[218][47] = 1;
TABLE[218][37] = 1;
TABLE[218][125] = 1;
TABLE[7][44] = 1;
TABLE[7][61] = 1;
TABLE[7][278] = 1;
TABLE[7][40] = 1;
TABLE[7][295] = 1;
TABLE[7][294] = 1;
TABLE[7][63] = 1;
TABLE[7][42] = 1;
TABLE[7][289] = 1;
TABLE[7][302] = 1;
TABLE[7][43] = 1;
TABLE[7][45] = 1;
TABLE[7][126] = 1;
TABLE[7][33] = 1;
TABLE[7][305] = 1;
TABLE[7][301] = 1;
TABLE[7][303] = 1;
TABLE[7][297] = 1;
TABLE[7][308] = 1;
TABLE[7][307] = 1;
TABLE[7][309] = 1;
TABLE[7][298] = 1;
TABLE[7][292] = 1;
TABLE[7][304] = 1;
TABLE[7][37] = 1;
TABLE[7][47] = 1;
TABLE[7][59] = 1;
TABLE[7][123] = 1;
TABLE[7][91] = 1;
TABLE[7][41] = 1;
TABLE[7][256] = 1;
TABLE[7][274] = 1;
TABLE[7][279] = 1;
TABLE[7][267] = 1;
TABLE[7][282] = 1;
TABLE[7][299] = 1;
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
TABLE[113][282] = 1;
TABLE[113][267] = 1;
TABLE[113][279] = 1;
TABLE[113][274] = 1;
TABLE[113][256] = 1;
TABLE[114][284] = 1;
TABLE[114][277] = 1;
TABLE[114][264] = 1;
TABLE[114][268] = 1;
TABLE[114][273] = 1;
TABLE[114][272] = 1;
TABLE[114][276] = 1;
TABLE[114][259] = 1;
TABLE[114][285] = 1;
TABLE[114][266] = 1;
TABLE[114][299] = 1;
TABLE[114][283] = 1;
TABLE[114][280] = 1;
TABLE[115][286] = 1;
TABLE[115][260] = 1;
TABLE[219][44] = 1;
TABLE[219][256] = 1;
TABLE[219][274] = 1;
TABLE[219][279] = 1;
TABLE[219][267] = 1;
TABLE[219][282] = 1;
TABLE[219][299] = 1;
TABLE[219][266] = 1;
TABLE[219][285] = 1;
TABLE[219][259] = 1;
TABLE[219][276] = 1;
TABLE[219][272] = 1;
TABLE[219][273] = 1;
TABLE[219][268] = 1;
TABLE[219][264] = 1;
TABLE[219][277] = 1;
TABLE[219][284] = 1;
TABLE[219][260] = 1;
TABLE[219][286] = 1;
TABLE[219][61] = 1;
TABLE[219][280] = 1;
TABLE[219][283] = 1;
TABLE[219][278] = 1;
TABLE[219][40] = 1;
TABLE[219][295] = 1;
TABLE[219][294] = 1;
TABLE[219][63] = 1;
TABLE[219][42] = 1;
TABLE[219][289] = 1;
TABLE[219][302] = 1;
TABLE[219][43] = 1;
TABLE[219][45] = 1;
TABLE[219][126] = 1;
TABLE[219][33] = 1;
TABLE[219][305] = 1;
TABLE[219][301] = 1;
TABLE[219][303] = 1;
TABLE[219][297] = 1;
TABLE[219][308] = 1;
TABLE[219][307] = 1;
TABLE[219][309] = 1;
TABLE[219][298] = 1;
TABLE[219][292] = 1;
TABLE[219][304] = 1;
TABLE[219][37] = 1;
TABLE[219][47] = 1;
TABLE[219][59] = 1;
TABLE[219][123] = 1;
TABLE[219][91] = 1;
TABLE[219][41] = 1;
TABLE[8][256] = 1;
TABLE[8][274] = 1;
TABLE[8][279] = 1;
TABLE[8][267] = 1;
TABLE[8][282] = 1;
TABLE[116][256] = 1;
TABLE[117][274] = 1;
TABLE[118][279] = 1;
TABLE[119][267] = 1;
TABLE[120][282] = 1;
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
TABLE[12][299] = 1;
TABLE[121][285] = 1;
TABLE[122][259] = 1;
TABLE[123][276] = 1;
TABLE[124][272] = 1;
TABLE[125][273] = 1;
TABLE[126][268] = 1;
TABLE[127][264] = 1;
TABLE[128][277] = 1;
TABLE[129][284] = 1;
TABLE[13][260] = 1;
TABLE[13][286] = 1;
TABLE[130][260] = 1;
TABLE[131][286] = 1;
TABLE[14][283] = 1;
TABLE[14][280] = 1;
TABLE[15][283] = 1;
TABLE[15][280] = 1;
TABLE[132][299] = 1;
TABLE[220][123] = 1;
TABLE[16][280] = 1;
TABLE[16][283] = 1;
TABLE[133][280] = 1;
TABLE[134][283] = 1;
TABLE[17][299] = 1;
TABLE[17][266] = 1;
TABLE[17][285] = 1;
TABLE[17][259] = 1;
TABLE[17][276] = 1;
TABLE[17][272] = 1;
TABLE[17][273] = 1;
TABLE[17][268] = 1;
TABLE[17][264] = 1;
TABLE[17][277] = 1;
TABLE[17][284] = 1;
TABLE[17][260] = 1;
TABLE[17][286] = 1;
TABLE[17][280] = 1;
TABLE[17][283] = 1;
TABLE[135][286] = 1;
TABLE[135][260] = 1;
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
TABLE[135][299] = 1;
TABLE[135][283] = 1;
TABLE[135][280] = 1;
TABLE[221][299] = 1;
TABLE[221][266] = 1;
TABLE[221][285] = 1;
TABLE[221][259] = 1;
TABLE[221][276] = 1;
TABLE[221][272] = 1;
TABLE[221][273] = 1;
TABLE[221][268] = 1;
TABLE[221][264] = 1;
TABLE[221][277] = 1;
TABLE[221][284] = 1;
TABLE[221][260] = 1;
TABLE[221][286] = 1;
TABLE[221][280] = 1;
TABLE[221][283] = 1;
TABLE[18][59] = 1;
TABLE[18][44] = 1;
TABLE[18][61] = 1;
TABLE[18][123] = 1;
TABLE[18][40] = 1;
TABLE[18][278] = 1;
TABLE[18][42] = 1;
TABLE[18][299] = 1;
TABLE[18][63] = 1;
TABLE[18][294] = 1;
TABLE[18][295] = 1;
TABLE[18][297] = 1;
TABLE[18][303] = 1;
TABLE[18][301] = 1;
TABLE[18][305] = 1;
TABLE[18][33] = 1;
TABLE[18][126] = 1;
TABLE[18][45] = 1;
TABLE[18][43] = 1;
TABLE[18][302] = 1;
TABLE[18][289] = 1;
TABLE[18][298] = 1;
TABLE[18][309] = 1;
TABLE[18][307] = 1;
TABLE[18][308] = 1;
TABLE[18][292] = 1;
TABLE[18][304] = 1;
TABLE[18][47] = 1;
TABLE[18][37] = 1;
TABLE[136][44] = 1;
TABLE[136][123] = 1;
TABLE[136][61] = 1;
TABLE[136][278] = 1;
TABLE[136][40] = 1;
TABLE[136][295] = 1;
TABLE[136][294] = 1;
TABLE[136][63] = 1;
TABLE[136][299] = 1;
TABLE[136][42] = 1;
TABLE[136][289] = 1;
TABLE[136][302] = 1;
TABLE[136][43] = 1;
TABLE[136][45] = 1;
TABLE[136][126] = 1;
TABLE[136][33] = 1;
TABLE[136][305] = 1;
TABLE[136][301] = 1;
TABLE[136][303] = 1;
TABLE[136][297] = 1;
TABLE[136][308] = 1;
TABLE[136][307] = 1;
TABLE[136][309] = 1;
TABLE[136][298] = 1;
TABLE[136][292] = 1;
TABLE[136][304] = 1;
TABLE[136][37] = 1;
TABLE[136][47] = 1;
TABLE[222][61] = 1;
TABLE[222][123] = 1;
TABLE[222][40] = 1;
TABLE[222][278] = 1;
TABLE[222][42] = 1;
TABLE[222][299] = 1;
TABLE[222][63] = 1;
TABLE[222][294] = 1;
TABLE[222][295] = 1;
TABLE[222][297] = 1;
TABLE[222][303] = 1;
TABLE[222][301] = 1;
TABLE[222][305] = 1;
TABLE[222][33] = 1;
TABLE[222][126] = 1;
TABLE[222][45] = 1;
TABLE[222][43] = 1;
TABLE[222][302] = 1;
TABLE[222][289] = 1;
TABLE[222][298] = 1;
TABLE[222][309] = 1;
TABLE[222][307] = 1;
TABLE[222][308] = 1;
TABLE[222][292] = 1;
TABLE[222][304] = 1;
TABLE[222][47] = 1;
TABLE[222][37] = 1;
TABLE[222][59] = 1;
TABLE[222][44] = 1;
TABLE[19][59] = 1;
TABLE[19][44] = 1;
TABLE[19][123] = 1;
TABLE[19][278] = 1;
TABLE[19][295] = 1;
TABLE[19][294] = 1;
TABLE[19][63] = 1;
TABLE[19][289] = 1;
TABLE[19][302] = 1;
TABLE[19][43] = 1;
TABLE[19][45] = 1;
TABLE[19][126] = 1;
TABLE[19][33] = 1;
TABLE[19][305] = 1;
TABLE[19][301] = 1;
TABLE[19][303] = 1;
TABLE[19][297] = 1;
TABLE[19][308] = 1;
TABLE[19][307] = 1;
TABLE[19][309] = 1;
TABLE[19][298] = 1;
TABLE[19][292] = 1;
TABLE[19][304] = 1;
TABLE[19][37] = 1;
TABLE[19][47] = 1;
TABLE[19][61] = 1;
TABLE[19][40] = 1;
TABLE[19][299] = 1;
TABLE[19][42] = 1;
TABLE[137][61] = 1;
TABLE[137][40] = 1;
TABLE[137][42] = 1;
TABLE[137][299] = 1;
TABLE[223][123] = 1;
TABLE[223][278] = 1;
TABLE[223][295] = 1;
TABLE[223][294] = 1;
TABLE[223][63] = 1;
TABLE[223][289] = 1;
TABLE[223][40] = 1;
TABLE[223][302] = 1;
TABLE[223][42] = 1;
TABLE[223][43] = 1;
TABLE[223][45] = 1;
TABLE[223][126] = 1;
TABLE[223][33] = 1;
TABLE[223][305] = 1;
TABLE[223][301] = 1;
TABLE[223][303] = 1;
TABLE[223][297] = 1;
TABLE[223][299] = 1;
TABLE[223][308] = 1;
TABLE[223][307] = 1;
TABLE[223][309] = 1;
TABLE[223][298] = 1;
TABLE[223][292] = 1;
TABLE[223][304] = 1;
TABLE[223][37] = 1;
TABLE[223][47] = 1;
TABLE[223][59] = 1;
TABLE[223][44] = 1;
TABLE[20][286] = 1;
TABLE[20][260] = 1;
TABLE[20][284] = 1;
TABLE[20][277] = 1;
TABLE[20][264] = 1;
TABLE[20][268] = 1;
TABLE[20][273] = 1;
TABLE[20][272] = 1;
TABLE[20][276] = 1;
TABLE[20][259] = 1;
TABLE[20][285] = 1;
TABLE[20][266] = 1;
TABLE[20][299] = 1;
TABLE[20][283] = 1;
TABLE[20][280] = 1;
TABLE[21][299] = 1;
TABLE[21][266] = 1;
TABLE[21][285] = 1;
TABLE[21][259] = 1;
TABLE[21][276] = 1;
TABLE[21][272] = 1;
TABLE[21][273] = 1;
TABLE[21][268] = 1;
TABLE[21][264] = 1;
TABLE[21][277] = 1;
TABLE[21][284] = 1;
TABLE[21][260] = 1;
TABLE[21][286] = 1;
TABLE[21][280] = 1;
TABLE[21][283] = 1;
TABLE[138][284] = 1;
TABLE[138][277] = 1;
TABLE[138][264] = 1;
TABLE[138][268] = 1;
TABLE[138][273] = 1;
TABLE[138][272] = 1;
TABLE[138][276] = 1;
TABLE[138][259] = 1;
TABLE[138][285] = 1;
TABLE[138][266] = 1;
TABLE[138][299] = 1;
TABLE[138][283] = 1;
TABLE[138][280] = 1;
TABLE[139][286] = 1;
TABLE[139][260] = 1;
TABLE[140][286] = 1;
TABLE[140][260] = 1;
TABLE[140][284] = 1;
TABLE[140][277] = 1;
TABLE[140][264] = 1;
TABLE[140][268] = 1;
TABLE[140][273] = 1;
TABLE[140][272] = 1;
TABLE[140][276] = 1;
TABLE[140][259] = 1;
TABLE[140][285] = 1;
TABLE[140][266] = 1;
TABLE[140][299] = 1;
TABLE[140][283] = 1;
TABLE[140][280] = 1;
TABLE[224][44] = 1;
TABLE[224][58] = 1;
TABLE[224][40] = 1;
TABLE[224][42] = 1;
TABLE[224][299] = 1;
TABLE[224][59] = 1;
TABLE[224][91] = 1;
TABLE[224][41] = 1;
TABLE[22][59] = 1;
TABLE[22][44] = 1;
TABLE[22][58] = 1;
TABLE[22][40] = 1;
TABLE[22][299] = 1;
TABLE[22][42] = 1;
TABLE[141][44] = 1;
TABLE[141][58] = 1;
TABLE[141][40] = 1;
TABLE[141][42] = 1;
TABLE[141][299] = 1;
TABLE[225][58] = 1;
TABLE[225][40] = 1;
TABLE[225][299] = 1;
TABLE[225][42] = 1;
TABLE[225][59] = 1;
TABLE[225][44] = 1;
TABLE[23][59] = 1;
TABLE[23][44] = 1;
TABLE[23][40] = 1;
TABLE[23][42] = 1;
TABLE[23][299] = 1;
TABLE[24][58] = 1;
TABLE[24][40] = 1;
TABLE[24][299] = 1;
TABLE[24][42] = 1;
TABLE[142][58] = 1;
TABLE[142][40] = 1;
TABLE[142][42] = 1;
TABLE[142][299] = 1;
TABLE[226][58] = 1;
TABLE[25][266] = 1;
TABLE[26][266] = 1;
TABLE[143][299] = 1;
TABLE[227][123] = 1;
TABLE[27][44] = 1;
TABLE[27][299] = 1;
TABLE[144][44] = 1;
TABLE[144][299] = 1;
TABLE[228][299] = 1;
TABLE[28][299] = 1;
TABLE[145][61] = 1;
TABLE[229][125] = 1;
TABLE[229][44] = 1;
TABLE[29][40] = 1;
TABLE[29][299] = 1;
TABLE[29][42] = 1;
TABLE[146][42] = 1;
TABLE[230][40] = 1;
TABLE[230][299] = 1;
TABLE[30][299] = 1;
TABLE[31][40] = 1;
TABLE[32][40] = 1;
TABLE[32][299] = 1;
TABLE[148][91] = 1;
TABLE[149][40] = 1;
TABLE[151][40] = 1;
TABLE[147][93] = 1;
TABLE[147][63] = 1;
TABLE[147][297] = 1;
TABLE[147][298] = 1;
TABLE[147][301] = 1;
TABLE[147][303] = 1;
TABLE[147][302] = 1;
TABLE[147][292] = 1;
TABLE[147][304] = 1;
TABLE[147][40] = 1;
TABLE[147][45] = 1;
TABLE[147][43] = 1;
TABLE[147][42] = 1;
TABLE[147][47] = 1;
TABLE[147][37] = 1;
TABLE[147][278] = 1;
TABLE[147][295] = 1;
TABLE[147][294] = 1;
TABLE[147][289] = 1;
TABLE[147][126] = 1;
TABLE[147][33] = 1;
TABLE[147][305] = 1;
TABLE[147][299] = 1;
TABLE[147][308] = 1;
TABLE[147][307] = 1;
TABLE[147][309] = 1;
TABLE[231][93] = 1;
TABLE[150][41] = 1;
TABLE[150][44] = 1;
TABLE[150][299] = 1;
TABLE[232][41] = 1;
TABLE[33][42] = 1;
TABLE[152][42] = 1;
TABLE[152][40] = 1;
TABLE[152][299] = 1;
TABLE[152][44] = 1;
TABLE[152][41] = 1;
TABLE[152][91] = 1;
TABLE[152][260] = 1;
TABLE[152][286] = 1;
TABLE[233][42] = 1;
TABLE[233][40] = 1;
TABLE[233][299] = 1;
TABLE[233][44] = 1;
TABLE[233][41] = 1;
TABLE[233][91] = 1;
TABLE[153][42] = 1;
TABLE[234][40] = 1;
TABLE[234][299] = 1;
TABLE[234][44] = 1;
TABLE[234][41] = 1;
TABLE[234][91] = 1;
TABLE[34][286] = 1;
TABLE[34][260] = 1;
TABLE[154][260] = 1;
TABLE[154][286] = 1;
TABLE[235][286] = 1;
TABLE[235][260] = 1;
TABLE[35][41] = 1;
TABLE[35][44] = 1;
TABLE[35][40] = 1;
TABLE[35][42] = 1;
TABLE[35][286] = 1;
TABLE[35][260] = 1;
TABLE[35][284] = 1;
TABLE[35][277] = 1;
TABLE[35][264] = 1;
TABLE[35][268] = 1;
TABLE[35][273] = 1;
TABLE[35][272] = 1;
TABLE[35][276] = 1;
TABLE[35][259] = 1;
TABLE[35][285] = 1;
TABLE[35][266] = 1;
TABLE[35][299] = 1;
TABLE[35][282] = 1;
TABLE[35][267] = 1;
TABLE[35][279] = 1;
TABLE[35][274] = 1;
TABLE[35][256] = 1;
TABLE[35][91] = 1;
TABLE[35][283] = 1;
TABLE[35][280] = 1;
TABLE[155][44] = 1;
TABLE[236][41] = 1;
TABLE[36][41] = 1;
TABLE[36][44] = 1;
TABLE[36][40] = 1;
TABLE[36][256] = 1;
TABLE[36][274] = 1;
TABLE[36][279] = 1;
TABLE[36][267] = 1;
TABLE[36][282] = 1;
TABLE[36][299] = 1;
TABLE[36][266] = 1;
TABLE[36][285] = 1;
TABLE[36][259] = 1;
TABLE[36][276] = 1;
TABLE[36][272] = 1;
TABLE[36][273] = 1;
TABLE[36][268] = 1;
TABLE[36][264] = 1;
TABLE[36][277] = 1;
TABLE[36][284] = 1;
TABLE[36][260] = 1;
TABLE[36][286] = 1;
TABLE[36][42] = 1;
TABLE[36][280] = 1;
TABLE[36][283] = 1;
TABLE[36][91] = 1;
TABLE[156][44] = 1;
TABLE[156][40] = 1;
TABLE[156][42] = 1;
TABLE[156][286] = 1;
TABLE[156][260] = 1;
TABLE[156][284] = 1;
TABLE[156][277] = 1;
TABLE[156][264] = 1;
TABLE[156][268] = 1;
TABLE[156][273] = 1;
TABLE[156][272] = 1;
TABLE[156][276] = 1;
TABLE[156][259] = 1;
TABLE[156][285] = 1;
TABLE[156][266] = 1;
TABLE[156][299] = 1;
TABLE[156][282] = 1;
TABLE[156][267] = 1;
TABLE[156][279] = 1;
TABLE[156][274] = 1;
TABLE[156][256] = 1;
TABLE[156][91] = 1;
TABLE[156][283] = 1;
TABLE[156][280] = 1;
TABLE[237][40] = 1;
TABLE[237][256] = 1;
TABLE[237][274] = 1;
TABLE[237][279] = 1;
TABLE[237][267] = 1;
TABLE[237][282] = 1;
TABLE[237][299] = 1;
TABLE[237][266] = 1;
TABLE[237][285] = 1;
TABLE[237][259] = 1;
TABLE[237][276] = 1;
TABLE[237][272] = 1;
TABLE[237][273] = 1;
TABLE[237][268] = 1;
TABLE[237][264] = 1;
TABLE[237][277] = 1;
TABLE[237][284] = 1;
TABLE[237][260] = 1;
TABLE[237][286] = 1;
TABLE[237][42] = 1;
TABLE[237][280] = 1;
TABLE[237][283] = 1;
TABLE[237][91] = 1;
TABLE[237][44] = 1;
TABLE[237][41] = 1;
TABLE[37][44] = 1;
TABLE[37][41] = 1;
TABLE[37][40] = 1;
TABLE[37][42] = 1;
TABLE[37][91] = 1;
TABLE[37][286] = 1;
TABLE[37][260] = 1;
TABLE[37][284] = 1;
TABLE[37][277] = 1;
TABLE[37][264] = 1;
TABLE[37][268] = 1;
TABLE[37][273] = 1;
TABLE[37][272] = 1;
TABLE[37][276] = 1;
TABLE[37][259] = 1;
TABLE[37][285] = 1;
TABLE[37][266] = 1;
TABLE[37][299] = 1;
TABLE[37][282] = 1;
TABLE[37][267] = 1;
TABLE[37][279] = 1;
TABLE[37][274] = 1;
TABLE[37][256] = 1;
TABLE[37][283] = 1;
TABLE[37][280] = 1;
TABLE[157][44] = 1;
TABLE[157][41] = 1;
TABLE[157][40] = 1;
TABLE[157][42] = 1;
TABLE[157][299] = 1;
TABLE[159][44] = 1;
TABLE[159][41] = 1;
TABLE[159][42] = 1;
TABLE[159][40] = 1;
TABLE[159][91] = 1;
TABLE[158][44] = 1;
TABLE[158][41] = 1;
TABLE[158][42] = 1;
TABLE[158][40] = 1;
TABLE[158][91] = 1;
TABLE[238][44] = 1;
TABLE[238][41] = 1;
TABLE[38][44] = 1;
TABLE[38][299] = 1;
TABLE[160][44] = 1;
TABLE[160][299] = 1;
TABLE[239][299] = 1;
TABLE[39][59] = 1;
TABLE[39][44] = 1;
TABLE[39][125] = 1;
TABLE[39][278] = 1;
TABLE[39][63] = 1;
TABLE[39][294] = 1;
TABLE[39][295] = 1;
TABLE[39][297] = 1;
TABLE[39][303] = 1;
TABLE[39][301] = 1;
TABLE[39][305] = 1;
TABLE[39][33] = 1;
TABLE[39][126] = 1;
TABLE[39][45] = 1;
TABLE[39][43] = 1;
TABLE[39][42] = 1;
TABLE[39][302] = 1;
TABLE[39][40] = 1;
TABLE[39][289] = 1;
TABLE[39][298] = 1;
TABLE[39][309] = 1;
TABLE[39][307] = 1;
TABLE[39][308] = 1;
TABLE[39][299] = 1;
TABLE[39][292] = 1;
TABLE[39][304] = 1;
TABLE[39][47] = 1;
TABLE[39][37] = 1;
TABLE[40][123] = 1;
TABLE[161][44] = 1;
TABLE[240][125] = 1;
TABLE[41][125] = 1;
TABLE[41][123] = 1;
TABLE[41][44] = 1;
TABLE[41][278] = 1;
TABLE[41][295] = 1;
TABLE[41][294] = 1;
TABLE[41][63] = 1;
TABLE[41][289] = 1;
TABLE[41][40] = 1;
TABLE[41][302] = 1;
TABLE[41][42] = 1;
TABLE[41][43] = 1;
TABLE[41][45] = 1;
TABLE[41][126] = 1;
TABLE[41][33] = 1;
TABLE[41][305] = 1;
TABLE[41][301] = 1;
TABLE[41][303] = 1;
TABLE[41][297] = 1;
TABLE[41][299] = 1;
TABLE[41][308] = 1;
TABLE[41][307] = 1;
TABLE[41][309] = 1;
TABLE[41][298] = 1;
TABLE[41][292] = 1;
TABLE[41][304] = 1;
TABLE[41][37] = 1;
TABLE[41][47] = 1;
TABLE[162][123] = 1;
TABLE[162][44] = 1;
TABLE[162][278] = 1;
TABLE[162][63] = 1;
TABLE[162][294] = 1;
TABLE[162][295] = 1;
TABLE[162][297] = 1;
TABLE[162][303] = 1;
TABLE[162][301] = 1;
TABLE[162][305] = 1;
TABLE[162][33] = 1;
TABLE[162][126] = 1;
TABLE[162][45] = 1;
TABLE[162][43] = 1;
TABLE[162][42] = 1;
TABLE[162][302] = 1;
TABLE[162][40] = 1;
TABLE[162][289] = 1;
TABLE[162][298] = 1;
TABLE[162][309] = 1;
TABLE[162][307] = 1;
TABLE[162][308] = 1;
TABLE[162][299] = 1;
TABLE[162][292] = 1;
TABLE[162][304] = 1;
TABLE[162][47] = 1;
TABLE[162][37] = 1;
TABLE[241][123] = 1;
TABLE[241][278] = 1;
TABLE[241][295] = 1;
TABLE[241][294] = 1;
TABLE[241][63] = 1;
TABLE[241][289] = 1;
TABLE[241][40] = 1;
TABLE[241][302] = 1;
TABLE[241][42] = 1;
TABLE[241][43] = 1;
TABLE[241][45] = 1;
TABLE[241][126] = 1;
TABLE[241][33] = 1;
TABLE[241][305] = 1;
TABLE[241][301] = 1;
TABLE[241][303] = 1;
TABLE[241][297] = 1;
TABLE[241][299] = 1;
TABLE[241][308] = 1;
TABLE[241][307] = 1;
TABLE[241][309] = 1;
TABLE[241][298] = 1;
TABLE[241][292] = 1;
TABLE[241][304] = 1;
TABLE[241][37] = 1;
TABLE[241][47] = 1;
TABLE[241][44] = 1;
TABLE[241][125] = 1;
TABLE[42][286] = 1;
TABLE[42][260] = 1;
TABLE[42][284] = 1;
TABLE[42][277] = 1;
TABLE[42][264] = 1;
TABLE[42][268] = 1;
TABLE[42][273] = 1;
TABLE[42][272] = 1;
TABLE[42][276] = 1;
TABLE[42][259] = 1;
TABLE[42][285] = 1;
TABLE[42][266] = 1;
TABLE[42][299] = 1;
TABLE[42][283] = 1;
TABLE[42][280] = 1;
TABLE[163][41] = 1;
TABLE[163][42] = 1;
TABLE[163][40] = 1;
TABLE[163][91] = 1;
TABLE[242][41] = 1;
TABLE[43][42] = 1;
TABLE[44][44] = 1;
TABLE[44][41] = 1;
TABLE[44][40] = 1;
TABLE[44][91] = 1;
TABLE[44][42] = 1;
TABLE[164][42] = 1;
TABLE[243][40] = 1;
TABLE[243][91] = 1;
TABLE[243][44] = 1;
TABLE[243][41] = 1;
TABLE[45][40] = 1;
TABLE[46][40] = 1;
TABLE[46][91] = 1;
TABLE[165][40] = 1;
TABLE[165][91] = 1;
TABLE[244][91] = 1;
TABLE[244][40] = 1;
TABLE[167][91] = 1;
TABLE[169][40] = 1;
TABLE[166][93] = 1;
TABLE[166][63] = 1;
TABLE[166][297] = 1;
TABLE[166][298] = 1;
TABLE[166][301] = 1;
TABLE[166][303] = 1;
TABLE[166][302] = 1;
TABLE[166][292] = 1;
TABLE[166][304] = 1;
TABLE[166][40] = 1;
TABLE[166][45] = 1;
TABLE[166][43] = 1;
TABLE[166][42] = 1;
TABLE[166][47] = 1;
TABLE[166][37] = 1;
TABLE[166][278] = 1;
TABLE[166][295] = 1;
TABLE[166][294] = 1;
TABLE[166][289] = 1;
TABLE[166][126] = 1;
TABLE[166][33] = 1;
TABLE[166][305] = 1;
TABLE[166][299] = 1;
TABLE[166][308] = 1;
TABLE[166][307] = 1;
TABLE[166][309] = 1;
TABLE[245][93] = 1;
TABLE[168][41] = 1;
TABLE[168][44] = 1;
TABLE[168][40] = 1;
TABLE[168][256] = 1;
TABLE[168][274] = 1;
TABLE[168][279] = 1;
TABLE[168][267] = 1;
TABLE[168][282] = 1;
TABLE[168][299] = 1;
TABLE[168][266] = 1;
TABLE[168][285] = 1;
TABLE[168][259] = 1;
TABLE[168][276] = 1;
TABLE[168][272] = 1;
TABLE[168][273] = 1;
TABLE[168][268] = 1;
TABLE[168][264] = 1;
TABLE[168][277] = 1;
TABLE[168][284] = 1;
TABLE[168][260] = 1;
TABLE[168][286] = 1;
TABLE[168][42] = 1;
TABLE[168][280] = 1;
TABLE[168][283] = 1;
TABLE[168][91] = 1;
TABLE[246][41] = 1;
TABLE[47][299] = 1;
TABLE[48][258] = 1;
TABLE[48][262] = 1;
TABLE[48][299] = 1;
TABLE[49][125] = 1;
TABLE[49][265] = 1;
TABLE[49][287] = 1;
TABLE[49][262] = 1;
TABLE[49][258] = 1;
TABLE[49][123] = 1;
TABLE[49][281] = 1;
TABLE[49][271] = 1;
TABLE[49][269] = 1;
TABLE[49][263] = 1;
TABLE[49][275] = 1;
TABLE[49][257] = 1;
TABLE[49][261] = 1;
TABLE[49][270] = 1;
TABLE[49][59] = 1;
TABLE[49][44] = 1;
TABLE[49][278] = 1;
TABLE[49][295] = 1;
TABLE[49][294] = 1;
TABLE[49][63] = 1;
TABLE[49][289] = 1;
TABLE[49][40] = 1;
TABLE[49][302] = 1;
TABLE[49][42] = 1;
TABLE[49][43] = 1;
TABLE[49][45] = 1;
TABLE[49][126] = 1;
TABLE[49][33] = 1;
TABLE[49][305] = 1;
TABLE[49][301] = 1;
TABLE[49][303] = 1;
TABLE[49][297] = 1;
TABLE[49][299] = 1;
TABLE[49][308] = 1;
TABLE[49][307] = 1;
TABLE[49][309] = 1;
TABLE[49][298] = 1;
TABLE[49][292] = 1;
TABLE[49][304] = 1;
TABLE[49][37] = 1;
TABLE[49][47] = 1;
TABLE[50][123] = 1;
TABLE[51][271] = 1;
TABLE[51][281] = 1;
TABLE[52][287] = 1;
TABLE[52][263] = 1;
TABLE[52][269] = 1;
TABLE[53][270] = 1;
TABLE[53][261] = 1;
TABLE[53][257] = 1;
TABLE[53][275] = 1;
TABLE[54][299] = 1;
TABLE[55][258] = 1;
TABLE[56][262] = 1;
TABLE[57][59] = 1;
TABLE[57][44] = 1;
TABLE[57][278] = 1;
TABLE[57][63] = 1;
TABLE[57][294] = 1;
TABLE[57][295] = 1;
TABLE[57][297] = 1;
TABLE[57][303] = 1;
TABLE[57][301] = 1;
TABLE[57][305] = 1;
TABLE[57][33] = 1;
TABLE[57][126] = 1;
TABLE[57][45] = 1;
TABLE[57][43] = 1;
TABLE[57][42] = 1;
TABLE[57][302] = 1;
TABLE[57][40] = 1;
TABLE[57][289] = 1;
TABLE[57][298] = 1;
TABLE[57][309] = 1;
TABLE[57][307] = 1;
TABLE[57][308] = 1;
TABLE[57][299] = 1;
TABLE[57][292] = 1;
TABLE[57][304] = 1;
TABLE[57][47] = 1;
TABLE[57][37] = 1;
TABLE[170][59] = 1;
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
TABLE[170][305] = 1;
TABLE[170][301] = 1;
TABLE[170][303] = 1;
TABLE[170][297] = 1;
TABLE[170][299] = 1;
TABLE[170][308] = 1;
TABLE[170][307] = 1;
TABLE[170][309] = 1;
TABLE[170][298] = 1;
TABLE[170][292] = 1;
TABLE[170][304] = 1;
TABLE[170][37] = 1;
TABLE[170][47] = 1;
TABLE[247][59] = 1;
TABLE[58][123] = 1;
TABLE[171][262] = 1;
TABLE[171][258] = 1;
TABLE[171][281] = 1;
TABLE[171][271] = 1;
TABLE[171][269] = 1;
TABLE[171][263] = 1;
TABLE[171][287] = 1;
TABLE[171][275] = 1;
TABLE[171][257] = 1;
TABLE[171][261] = 1;
TABLE[171][270] = 1;
TABLE[171][125] = 1;
TABLE[171][59] = 1;
TABLE[171][44] = 1;
TABLE[171][61] = 1;
TABLE[171][123] = 1;
TABLE[171][286] = 1;
TABLE[171][260] = 1;
TABLE[171][284] = 1;
TABLE[171][277] = 1;
TABLE[171][264] = 1;
TABLE[171][268] = 1;
TABLE[171][273] = 1;
TABLE[171][272] = 1;
TABLE[171][276] = 1;
TABLE[171][259] = 1;
TABLE[171][285] = 1;
TABLE[171][266] = 1;
TABLE[171][299] = 1;
TABLE[171][282] = 1;
TABLE[171][267] = 1;
TABLE[171][279] = 1;
TABLE[171][274] = 1;
TABLE[171][256] = 1;
TABLE[171][40] = 1;
TABLE[171][278] = 1;
TABLE[171][283] = 1;
TABLE[171][280] = 1;
TABLE[171][42] = 1;
TABLE[171][63] = 1;
TABLE[171][294] = 1;
TABLE[171][295] = 1;
TABLE[171][297] = 1;
TABLE[171][303] = 1;
TABLE[171][301] = 1;
TABLE[171][305] = 1;
TABLE[171][33] = 1;
TABLE[171][126] = 1;
TABLE[171][45] = 1;
TABLE[171][43] = 1;
TABLE[171][302] = 1;
TABLE[171][289] = 1;
TABLE[171][298] = 1;
TABLE[171][309] = 1;
TABLE[171][307] = 1;
TABLE[171][308] = 1;
TABLE[171][292] = 1;
TABLE[171][304] = 1;
TABLE[171][47] = 1;
TABLE[171][37] = 1;
TABLE[248][262] = 1;
TABLE[248][258] = 1;
TABLE[248][59] = 1;
TABLE[248][123] = 1;
TABLE[248][281] = 1;
TABLE[248][271] = 1;
TABLE[248][269] = 1;
TABLE[248][263] = 1;
TABLE[248][287] = 1;
TABLE[248][275] = 1;
TABLE[248][257] = 1;
TABLE[248][261] = 1;
TABLE[248][270] = 1;
TABLE[248][299] = 1;
TABLE[248][44] = 1;
TABLE[248][278] = 1;
TABLE[248][63] = 1;
TABLE[248][294] = 1;
TABLE[248][295] = 1;
TABLE[248][297] = 1;
TABLE[248][303] = 1;
TABLE[248][301] = 1;
TABLE[248][305] = 1;
TABLE[248][33] = 1;
TABLE[248][126] = 1;
TABLE[248][45] = 1;
TABLE[248][43] = 1;
TABLE[248][42] = 1;
TABLE[248][302] = 1;
TABLE[248][40] = 1;
TABLE[248][289] = 1;
TABLE[248][298] = 1;
TABLE[248][309] = 1;
TABLE[248][307] = 1;
TABLE[248][308] = 1;
TABLE[248][292] = 1;
TABLE[248][304] = 1;
TABLE[248][47] = 1;
TABLE[248][37] = 1;
TABLE[248][125] = 1;
TABLE[172][125] = 1;
TABLE[172][270] = 1;
TABLE[172][261] = 1;
TABLE[172][257] = 1;
TABLE[172][275] = 1;
TABLE[172][287] = 1;
TABLE[172][263] = 1;
TABLE[172][269] = 1;
TABLE[172][271] = 1;
TABLE[172][281] = 1;
TABLE[172][123] = 1;
TABLE[172][59] = 1;
TABLE[172][258] = 1;
TABLE[172][262] = 1;
TABLE[172][299] = 1;
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
TABLE[172][305] = 1;
TABLE[172][301] = 1;
TABLE[172][303] = 1;
TABLE[172][297] = 1;
TABLE[172][308] = 1;
TABLE[172][307] = 1;
TABLE[172][309] = 1;
TABLE[172][298] = 1;
TABLE[172][292] = 1;
TABLE[172][304] = 1;
TABLE[172][37] = 1;
TABLE[172][47] = 1;
TABLE[249][125] = 1;
TABLE[59][125] = 1;
TABLE[59][262] = 1;
TABLE[59][258] = 1;
TABLE[59][59] = 1;
TABLE[59][123] = 1;
TABLE[59][281] = 1;
TABLE[59][271] = 1;
TABLE[59][269] = 1;
TABLE[59][263] = 1;
TABLE[59][287] = 1;
TABLE[59][275] = 1;
TABLE[59][257] = 1;
TABLE[59][261] = 1;
TABLE[59][270] = 1;
TABLE[59][299] = 1;
TABLE[59][44] = 1;
TABLE[59][278] = 1;
TABLE[59][63] = 1;
TABLE[59][294] = 1;
TABLE[59][295] = 1;
TABLE[59][297] = 1;
TABLE[59][303] = 1;
TABLE[59][301] = 1;
TABLE[59][305] = 1;
TABLE[59][33] = 1;
TABLE[59][126] = 1;
TABLE[59][45] = 1;
TABLE[59][43] = 1;
TABLE[59][42] = 1;
TABLE[59][302] = 1;
TABLE[59][40] = 1;
TABLE[59][289] = 1;
TABLE[59][298] = 1;
TABLE[59][309] = 1;
TABLE[59][307] = 1;
TABLE[59][308] = 1;
TABLE[59][292] = 1;
TABLE[59][304] = 1;
TABLE[59][47] = 1;
TABLE[59][37] = 1;
TABLE[173][125] = 1;
TABLE[173][270] = 1;
TABLE[173][261] = 1;
TABLE[173][257] = 1;
TABLE[173][275] = 1;
TABLE[173][287] = 1;
TABLE[173][263] = 1;
TABLE[173][269] = 1;
TABLE[173][271] = 1;
TABLE[173][281] = 1;
TABLE[173][123] = 1;
TABLE[173][59] = 1;
TABLE[173][258] = 1;
TABLE[173][262] = 1;
TABLE[173][299] = 1;
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
TABLE[173][305] = 1;
TABLE[173][301] = 1;
TABLE[173][303] = 1;
TABLE[173][297] = 1;
TABLE[173][308] = 1;
TABLE[173][307] = 1;
TABLE[173][309] = 1;
TABLE[173][298] = 1;
TABLE[173][292] = 1;
TABLE[173][304] = 1;
TABLE[173][37] = 1;
TABLE[173][47] = 1;
TABLE[250][262] = 1;
TABLE[250][258] = 1;
TABLE[250][59] = 1;
TABLE[250][123] = 1;
TABLE[250][281] = 1;
TABLE[250][271] = 1;
TABLE[250][269] = 1;
TABLE[250][263] = 1;
TABLE[250][287] = 1;
TABLE[250][275] = 1;
TABLE[250][257] = 1;
TABLE[250][261] = 1;
TABLE[250][270] = 1;
TABLE[250][299] = 1;
TABLE[250][44] = 1;
TABLE[250][278] = 1;
TABLE[250][63] = 1;
TABLE[250][294] = 1;
TABLE[250][295] = 1;
TABLE[250][297] = 1;
TABLE[250][303] = 1;
TABLE[250][301] = 1;
TABLE[250][305] = 1;
TABLE[250][33] = 1;
TABLE[250][126] = 1;
TABLE[250][45] = 1;
TABLE[250][43] = 1;
TABLE[250][42] = 1;
TABLE[250][302] = 1;
TABLE[250][40] = 1;
TABLE[250][289] = 1;
TABLE[250][298] = 1;
TABLE[250][309] = 1;
TABLE[250][307] = 1;
TABLE[250][308] = 1;
TABLE[250][292] = 1;
TABLE[250][304] = 1;
TABLE[250][47] = 1;
TABLE[250][37] = 1;
TABLE[250][125] = 1;
TABLE[60][271] = 1;
TABLE[61][281] = 1;
TABLE[174][265] = 1;
TABLE[251][125] = 1;
TABLE[251][265] = 1;
TABLE[251][287] = 1;
TABLE[251][262] = 1;
TABLE[251][258] = 1;
TABLE[251][59] = 1;
TABLE[251][123] = 1;
TABLE[251][281] = 1;
TABLE[251][271] = 1;
TABLE[251][269] = 1;
TABLE[251][263] = 1;
TABLE[251][275] = 1;
TABLE[251][257] = 1;
TABLE[251][261] = 1;
TABLE[251][270] = 1;
TABLE[251][299] = 1;
TABLE[251][44] = 1;
TABLE[251][278] = 1;
TABLE[251][63] = 1;
TABLE[251][294] = 1;
TABLE[251][295] = 1;
TABLE[251][297] = 1;
TABLE[251][303] = 1;
TABLE[251][301] = 1;
TABLE[251][305] = 1;
TABLE[251][33] = 1;
TABLE[251][126] = 1;
TABLE[251][45] = 1;
TABLE[251][43] = 1;
TABLE[251][42] = 1;
TABLE[251][302] = 1;
TABLE[251][40] = 1;
TABLE[251][289] = 1;
TABLE[251][298] = 1;
TABLE[251][309] = 1;
TABLE[251][307] = 1;
TABLE[251][308] = 1;
TABLE[251][292] = 1;
TABLE[251][304] = 1;
TABLE[251][47] = 1;
TABLE[251][37] = 1;
TABLE[62][287] = 1;
TABLE[63][263] = 1;
TABLE[64][269] = 1;
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
TABLE[175][305] = 1;
TABLE[175][301] = 1;
TABLE[175][303] = 1;
TABLE[175][297] = 1;
TABLE[175][299] = 1;
TABLE[175][308] = 1;
TABLE[175][307] = 1;
TABLE[175][309] = 1;
TABLE[175][298] = 1;
TABLE[175][292] = 1;
TABLE[175][304] = 1;
TABLE[175][37] = 1;
TABLE[175][47] = 1;
TABLE[252][59] = 1;
TABLE[176][59] = 1;
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
TABLE[176][305] = 1;
TABLE[176][301] = 1;
TABLE[176][303] = 1;
TABLE[176][297] = 1;
TABLE[176][299] = 1;
TABLE[176][308] = 1;
TABLE[176][307] = 1;
TABLE[176][309] = 1;
TABLE[176][298] = 1;
TABLE[176][292] = 1;
TABLE[176][304] = 1;
TABLE[176][37] = 1;
TABLE[176][47] = 1;
TABLE[253][59] = 1;
TABLE[177][41] = 1;
TABLE[177][44] = 1;
TABLE[177][278] = 1;
TABLE[177][295] = 1;
TABLE[177][294] = 1;
TABLE[177][63] = 1;
TABLE[177][289] = 1;
TABLE[177][40] = 1;
TABLE[177][302] = 1;
TABLE[177][42] = 1;
TABLE[177][43] = 1;
TABLE[177][45] = 1;
TABLE[177][126] = 1;
TABLE[177][33] = 1;
TABLE[177][305] = 1;
TABLE[177][301] = 1;
TABLE[177][303] = 1;
TABLE[177][297] = 1;
TABLE[177][299] = 1;
TABLE[177][308] = 1;
TABLE[177][307] = 1;
TABLE[177][309] = 1;
TABLE[177][298] = 1;
TABLE[177][292] = 1;
TABLE[177][304] = 1;
TABLE[177][37] = 1;
TABLE[177][47] = 1;
TABLE[254][41] = 1;
TABLE[65][270] = 1;
TABLE[66][261] = 1;
TABLE[67][257] = 1;
TABLE[68][275] = 1;
TABLE[178][59] = 1;
TABLE[178][44] = 1;
TABLE[178][278] = 1;
TABLE[178][295] = 1;
TABLE[178][294] = 1;
TABLE[178][63] = 1;
TABLE[178][289] = 1;
TABLE[178][40] = 1;
TABLE[178][302] = 1;
TABLE[178][42] = 1;
TABLE[178][43] = 1;
TABLE[178][45] = 1;
TABLE[178][126] = 1;
TABLE[178][33] = 1;
TABLE[178][305] = 1;
TABLE[178][301] = 1;
TABLE[178][303] = 1;
TABLE[178][297] = 1;
TABLE[178][299] = 1;
TABLE[178][308] = 1;
TABLE[178][307] = 1;
TABLE[178][309] = 1;
TABLE[178][298] = 1;
TABLE[178][292] = 1;
TABLE[178][304] = 1;
TABLE[178][37] = 1;
TABLE[178][47] = 1;
TABLE[255][59] = 1;
TABLE[69][59] = 1;
TABLE[69][41] = 1;
TABLE[69][58] = 1;
TABLE[69][93] = 1;
TABLE[69][44] = 1;
TABLE[69][278] = 1;
TABLE[69][63] = 1;
TABLE[69][294] = 1;
TABLE[69][295] = 1;
TABLE[69][297] = 1;
TABLE[69][303] = 1;
TABLE[69][301] = 1;
TABLE[69][305] = 1;
TABLE[69][33] = 1;
TABLE[69][126] = 1;
TABLE[69][45] = 1;
TABLE[69][43] = 1;
TABLE[69][42] = 1;
TABLE[69][302] = 1;
TABLE[69][40] = 1;
TABLE[69][289] = 1;
TABLE[69][298] = 1;
TABLE[69][309] = 1;
TABLE[69][307] = 1;
TABLE[69][308] = 1;
TABLE[69][299] = 1;
TABLE[69][292] = 1;
TABLE[69][304] = 1;
TABLE[69][47] = 1;
TABLE[69][37] = 1;
TABLE[179][44] = 1;
TABLE[179][278] = 1;
TABLE[179][295] = 1;
TABLE[179][294] = 1;
TABLE[179][63] = 1;
TABLE[179][289] = 1;
TABLE[179][40] = 1;
TABLE[179][302] = 1;
TABLE[179][42] = 1;
TABLE[179][43] = 1;
TABLE[179][45] = 1;
TABLE[179][126] = 1;
TABLE[179][33] = 1;
TABLE[179][305] = 1;
TABLE[179][301] = 1;
TABLE[179][303] = 1;
TABLE[179][297] = 1;
TABLE[179][299] = 1;
TABLE[179][308] = 1;
TABLE[179][307] = 1;
TABLE[179][309] = 1;
TABLE[179][298] = 1;
TABLE[179][292] = 1;
TABLE[179][304] = 1;
TABLE[179][37] = 1;
TABLE[179][47] = 1;
TABLE[256][278] = 1;
TABLE[256][63] = 1;
TABLE[256][294] = 1;
TABLE[256][295] = 1;
TABLE[256][297] = 1;
TABLE[256][303] = 1;
TABLE[256][301] = 1;
TABLE[256][305] = 1;
TABLE[256][33] = 1;
TABLE[256][126] = 1;
TABLE[256][45] = 1;
TABLE[256][43] = 1;
TABLE[256][42] = 1;
TABLE[256][302] = 1;
TABLE[256][40] = 1;
TABLE[256][289] = 1;
TABLE[256][298] = 1;
TABLE[256][309] = 1;
TABLE[256][307] = 1;
TABLE[256][308] = 1;
TABLE[256][299] = 1;
TABLE[256][292] = 1;
TABLE[256][304] = 1;
TABLE[256][47] = 1;
TABLE[256][37] = 1;
TABLE[256][59] = 1;
TABLE[256][41] = 1;
TABLE[256][44] = 1;
TABLE[256][58] = 1;
TABLE[256][93] = 1;
TABLE[70][59] = 1;
TABLE[70][41] = 1;
TABLE[70][44] = 1;
TABLE[70][125] = 1;
TABLE[70][58] = 1;
TABLE[70][93] = 1;
TABLE[70][63] = 1;
TABLE[70][297] = 1;
TABLE[70][298] = 1;
TABLE[70][301] = 1;
TABLE[70][303] = 1;
TABLE[70][302] = 1;
TABLE[70][292] = 1;
TABLE[70][304] = 1;
TABLE[70][43] = 1;
TABLE[70][45] = 1;
TABLE[70][40] = 1;
TABLE[70][278] = 1;
TABLE[70][37] = 1;
TABLE[70][47] = 1;
TABLE[70][42] = 1;
TABLE[70][294] = 1;
TABLE[70][295] = 1;
TABLE[70][305] = 1;
TABLE[70][33] = 1;
TABLE[70][126] = 1;
TABLE[70][289] = 1;
TABLE[70][309] = 1;
TABLE[70][307] = 1;
TABLE[70][308] = 1;
TABLE[70][299] = 1;
TABLE[71][278] = 1;
TABLE[71][295] = 1;
TABLE[71][294] = 1;
TABLE[71][289] = 1;
TABLE[71][40] = 1;
TABLE[71][302] = 1;
TABLE[71][42] = 1;
TABLE[71][43] = 1;
TABLE[71][45] = 1;
TABLE[71][126] = 1;
TABLE[71][33] = 1;
TABLE[71][305] = 1;
TABLE[71][301] = 1;
TABLE[71][303] = 1;
TABLE[71][299] = 1;
TABLE[71][308] = 1;
TABLE[71][307] = 1;
TABLE[71][309] = 1;
TABLE[72][291] = 1;
TABLE[73][61] = 1;
TABLE[74][59] = 1;
TABLE[74][41] = 1;
TABLE[74][125] = 1;
TABLE[74][93] = 1;
TABLE[74][58] = 1;
TABLE[74][44] = 1;
TABLE[74][63] = 1;
TABLE[74][297] = 1;
TABLE[74][298] = 1;
TABLE[74][301] = 1;
TABLE[74][303] = 1;
TABLE[74][302] = 1;
TABLE[74][292] = 1;
TABLE[74][304] = 1;
TABLE[74][40] = 1;
TABLE[74][45] = 1;
TABLE[74][43] = 1;
TABLE[74][42] = 1;
TABLE[74][47] = 1;
TABLE[74][37] = 1;
TABLE[74][278] = 1;
TABLE[74][295] = 1;
TABLE[74][294] = 1;
TABLE[74][289] = 1;
TABLE[74][126] = 1;
TABLE[74][33] = 1;
TABLE[74][305] = 1;
TABLE[74][299] = 1;
TABLE[74][308] = 1;
TABLE[74][307] = 1;
TABLE[74][309] = 1;
TABLE[180][63] = 1;
TABLE[257][59] = 1;
TABLE[257][41] = 1;
TABLE[257][125] = 1;
TABLE[257][93] = 1;
TABLE[257][58] = 1;
TABLE[257][44] = 1;
TABLE[75][59] = 1;
TABLE[75][125] = 1;
TABLE[75][93] = 1;
TABLE[75][58] = 1;
TABLE[75][44] = 1;
TABLE[75][63] = 1;
TABLE[75][297] = 1;
TABLE[75][298] = 1;
TABLE[75][301] = 1;
TABLE[75][303] = 1;
TABLE[75][302] = 1;
TABLE[75][292] = 1;
TABLE[75][304] = 1;
TABLE[75][43] = 1;
TABLE[75][45] = 1;
TABLE[75][40] = 1;
TABLE[75][278] = 1;
TABLE[75][37] = 1;
TABLE[75][47] = 1;
TABLE[75][42] = 1;
TABLE[75][294] = 1;
TABLE[75][295] = 1;
TABLE[75][305] = 1;
TABLE[75][33] = 1;
TABLE[75][126] = 1;
TABLE[75][289] = 1;
TABLE[75][309] = 1;
TABLE[75][307] = 1;
TABLE[75][308] = 1;
TABLE[75][299] = 1;
TABLE[76][63] = 1;
TABLE[76][59] = 1;
TABLE[76][41] = 1;
TABLE[76][125] = 1;
TABLE[76][93] = 1;
TABLE[76][58] = 1;
TABLE[76][44] = 1;
TABLE[76][297] = 1;
TABLE[76][298] = 1;
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
TABLE[76][305] = 1;
TABLE[76][33] = 1;
TABLE[76][126] = 1;
TABLE[76][289] = 1;
TABLE[76][309] = 1;
TABLE[76][307] = 1;
TABLE[76][308] = 1;
TABLE[76][299] = 1;
TABLE[181][297] = 1;
TABLE[181][298] = 1;
TABLE[181][301] = 1;
TABLE[181][303] = 1;
TABLE[181][302] = 1;
TABLE[181][292] = 1;
TABLE[181][304] = 1;
TABLE[181][40] = 1;
TABLE[181][45] = 1;
TABLE[181][43] = 1;
TABLE[181][42] = 1;
TABLE[181][47] = 1;
TABLE[181][37] = 1;
TABLE[181][278] = 1;
TABLE[181][295] = 1;
TABLE[181][294] = 1;
TABLE[181][289] = 1;
TABLE[181][126] = 1;
TABLE[181][33] = 1;
TABLE[181][305] = 1;
TABLE[181][299] = 1;
TABLE[181][308] = 1;
TABLE[181][307] = 1;
TABLE[181][309] = 1;
TABLE[258][298] = 1;
TABLE[258][301] = 1;
TABLE[258][303] = 1;
TABLE[258][302] = 1;
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
TABLE[258][305] = 1;
TABLE[258][33] = 1;
TABLE[258][126] = 1;
TABLE[258][289] = 1;
TABLE[258][309] = 1;
TABLE[258][307] = 1;
TABLE[258][308] = 1;
TABLE[258][299] = 1;
TABLE[258][63] = 1;
TABLE[258][59] = 1;
TABLE[258][41] = 1;
TABLE[258][297] = 1;
TABLE[258][125] = 1;
TABLE[258][93] = 1;
TABLE[258][58] = 1;
TABLE[258][44] = 1;
TABLE[77][63] = 1;
TABLE[77][59] = 1;
TABLE[77][41] = 1;
TABLE[77][297] = 1;
TABLE[77][125] = 1;
TABLE[77][93] = 1;
TABLE[77][58] = 1;
TABLE[77][44] = 1;
TABLE[77][298] = 1;
TABLE[77][301] = 1;
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
TABLE[77][305] = 1;
TABLE[77][299] = 1;
TABLE[77][308] = 1;
TABLE[77][307] = 1;
TABLE[77][309] = 1;
TABLE[182][298] = 1;
TABLE[182][301] = 1;
TABLE[182][303] = 1;
TABLE[182][302] = 1;
TABLE[182][292] = 1;
TABLE[182][304] = 1;
TABLE[182][43] = 1;
TABLE[182][45] = 1;
TABLE[182][40] = 1;
TABLE[182][278] = 1;
TABLE[182][37] = 1;
TABLE[182][47] = 1;
TABLE[182][42] = 1;
TABLE[182][294] = 1;
TABLE[182][295] = 1;
TABLE[182][305] = 1;
TABLE[182][33] = 1;
TABLE[182][126] = 1;
TABLE[182][289] = 1;
TABLE[182][309] = 1;
TABLE[182][307] = 1;
TABLE[182][308] = 1;
TABLE[182][299] = 1;
TABLE[259][301] = 1;
TABLE[259][303] = 1;
TABLE[259][302] = 1;
TABLE[259][292] = 1;
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
TABLE[259][126] = 1;
TABLE[259][33] = 1;
TABLE[259][305] = 1;
TABLE[259][299] = 1;
TABLE[259][308] = 1;
TABLE[259][307] = 1;
TABLE[259][309] = 1;
TABLE[259][63] = 1;
TABLE[259][59] = 1;
TABLE[259][41] = 1;
TABLE[259][298] = 1;
TABLE[259][297] = 1;
TABLE[259][125] = 1;
TABLE[259][93] = 1;
TABLE[259][58] = 1;
TABLE[259][44] = 1;
TABLE[78][63] = 1;
TABLE[78][59] = 1;
TABLE[78][41] = 1;
TABLE[78][298] = 1;
TABLE[78][297] = 1;
TABLE[78][125] = 1;
TABLE[78][93] = 1;
TABLE[78][58] = 1;
TABLE[78][44] = 1;
TABLE[78][301] = 1;
TABLE[78][303] = 1;
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
TABLE[78][305] = 1;
TABLE[78][33] = 1;
TABLE[78][126] = 1;
TABLE[78][289] = 1;
TABLE[78][309] = 1;
TABLE[78][307] = 1;
TABLE[78][308] = 1;
TABLE[78][299] = 1;
TABLE[183][301] = 1;
TABLE[183][303] = 1;
TABLE[183][302] = 1;
TABLE[183][292] = 1;
TABLE[183][304] = 1;
TABLE[183][40] = 1;
TABLE[183][45] = 1;
TABLE[183][43] = 1;
TABLE[183][42] = 1;
TABLE[183][47] = 1;
TABLE[183][37] = 1;
TABLE[183][278] = 1;
TABLE[183][295] = 1;
TABLE[183][294] = 1;
TABLE[183][289] = 1;
TABLE[183][126] = 1;
TABLE[183][33] = 1;
TABLE[183][305] = 1;
TABLE[183][299] = 1;
TABLE[183][308] = 1;
TABLE[183][307] = 1;
TABLE[183][309] = 1;
TABLE[260][303] = 1;
TABLE[260][302] = 1;
TABLE[260][292] = 1;
TABLE[260][304] = 1;
TABLE[260][43] = 1;
TABLE[260][45] = 1;
TABLE[260][40] = 1;
TABLE[260][278] = 1;
TABLE[260][37] = 1;
TABLE[260][47] = 1;
TABLE[260][42] = 1;
TABLE[260][294] = 1;
TABLE[260][295] = 1;
TABLE[260][301] = 1;
TABLE[260][305] = 1;
TABLE[260][33] = 1;
TABLE[260][126] = 1;
TABLE[260][289] = 1;
TABLE[260][309] = 1;
TABLE[260][307] = 1;
TABLE[260][308] = 1;
TABLE[260][299] = 1;
TABLE[260][63] = 1;
TABLE[260][59] = 1;
TABLE[260][41] = 1;
TABLE[260][298] = 1;
TABLE[260][297] = 1;
TABLE[260][125] = 1;
TABLE[260][93] = 1;
TABLE[260][58] = 1;
TABLE[260][44] = 1;
TABLE[79][63] = 1;
TABLE[79][59] = 1;
TABLE[79][41] = 1;
TABLE[79][298] = 1;
TABLE[79][297] = 1;
TABLE[79][125] = 1;
TABLE[79][93] = 1;
TABLE[79][58] = 1;
TABLE[79][44] = 1;
TABLE[79][303] = 1;
TABLE[79][302] = 1;
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
TABLE[79][126] = 1;
TABLE[79][33] = 1;
TABLE[79][305] = 1;
TABLE[79][301] = 1;
TABLE[79][299] = 1;
TABLE[79][308] = 1;
TABLE[79][307] = 1;
TABLE[79][309] = 1;
TABLE[184][303] = 1;
TABLE[184][302] = 1;
TABLE[184][292] = 1;
TABLE[184][304] = 1;
TABLE[184][43] = 1;
TABLE[184][45] = 1;
TABLE[184][40] = 1;
TABLE[184][278] = 1;
TABLE[184][37] = 1;
TABLE[184][47] = 1;
TABLE[184][42] = 1;
TABLE[184][294] = 1;
TABLE[184][295] = 1;
TABLE[184][301] = 1;
TABLE[184][305] = 1;
TABLE[184][33] = 1;
TABLE[184][126] = 1;
TABLE[184][289] = 1;
TABLE[184][309] = 1;
TABLE[184][307] = 1;
TABLE[184][308] = 1;
TABLE[184][299] = 1;
TABLE[261][302] = 1;
TABLE[261][292] = 1;
TABLE[261][304] = 1;
TABLE[261][40] = 1;
TABLE[261][45] = 1;
TABLE[261][43] = 1;
TABLE[261][42] = 1;
TABLE[261][47] = 1;
TABLE[261][37] = 1;
TABLE[261][278] = 1;
TABLE[261][295] = 1;
TABLE[261][294] = 1;
TABLE[261][289] = 1;
TABLE[261][126] = 1;
TABLE[261][33] = 1;
TABLE[261][305] = 1;
TABLE[261][301] = 1;
TABLE[261][303] = 1;
TABLE[261][299] = 1;
TABLE[261][308] = 1;
TABLE[261][307] = 1;
TABLE[261][309] = 1;
TABLE[261][63] = 1;
TABLE[261][59] = 1;
TABLE[261][41] = 1;
TABLE[261][298] = 1;
TABLE[261][297] = 1;
TABLE[261][125] = 1;
TABLE[261][93] = 1;
TABLE[261][58] = 1;
TABLE[261][44] = 1;
TABLE[80][63] = 1;
TABLE[80][59] = 1;
TABLE[80][41] = 1;
TABLE[80][298] = 1;
TABLE[80][297] = 1;
TABLE[80][125] = 1;
TABLE[80][93] = 1;
TABLE[80][58] = 1;
TABLE[80][44] = 1;
TABLE[80][302] = 1;
TABLE[80][292] = 1;
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
TABLE[80][303] = 1;
TABLE[80][301] = 1;
TABLE[80][305] = 1;
TABLE[80][33] = 1;
TABLE[80][126] = 1;
TABLE[80][289] = 1;
TABLE[80][309] = 1;
TABLE[80][307] = 1;
TABLE[80][308] = 1;
TABLE[80][299] = 1;
TABLE[185][302] = 1;
TABLE[185][292] = 1;
TABLE[185][304] = 1;
TABLE[185][40] = 1;
TABLE[185][45] = 1;
TABLE[185][43] = 1;
TABLE[185][42] = 1;
TABLE[185][47] = 1;
TABLE[185][37] = 1;
TABLE[185][278] = 1;
TABLE[185][295] = 1;
TABLE[185][294] = 1;
TABLE[185][289] = 1;
TABLE[185][126] = 1;
TABLE[185][33] = 1;
TABLE[185][305] = 1;
TABLE[185][301] = 1;
TABLE[185][303] = 1;
TABLE[185][299] = 1;
TABLE[185][308] = 1;
TABLE[185][307] = 1;
TABLE[185][309] = 1;
TABLE[262][292] = 1;
TABLE[262][304] = 1;
TABLE[262][43] = 1;
TABLE[262][45] = 1;
TABLE[262][40] = 1;
TABLE[262][278] = 1;
TABLE[262][37] = 1;
TABLE[262][47] = 1;
TABLE[262][42] = 1;
TABLE[262][294] = 1;
TABLE[262][295] = 1;
TABLE[262][303] = 1;
TABLE[262][301] = 1;
TABLE[262][305] = 1;
TABLE[262][33] = 1;
TABLE[262][126] = 1;
TABLE[262][302] = 1;
TABLE[262][289] = 1;
TABLE[262][309] = 1;
TABLE[262][307] = 1;
TABLE[262][308] = 1;
TABLE[262][299] = 1;
TABLE[262][63] = 1;
TABLE[262][59] = 1;
TABLE[262][41] = 1;
TABLE[262][298] = 1;
TABLE[262][297] = 1;
TABLE[262][125] = 1;
TABLE[262][93] = 1;
TABLE[262][58] = 1;
TABLE[262][44] = 1;
TABLE[81][63] = 1;
TABLE[81][59] = 1;
TABLE[81][41] = 1;
TABLE[81][298] = 1;
TABLE[81][297] = 1;
TABLE[81][125] = 1;
TABLE[81][93] = 1;
TABLE[81][58] = 1;
TABLE[81][44] = 1;
TABLE[81][292] = 1;
TABLE[81][304] = 1;
TABLE[81][40] = 1;
TABLE[81][45] = 1;
TABLE[81][43] = 1;
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
TABLE[81][305] = 1;
TABLE[81][301] = 1;
TABLE[81][303] = 1;
TABLE[81][299] = 1;
TABLE[81][308] = 1;
TABLE[81][307] = 1;
TABLE[81][309] = 1;
TABLE[186][292] = 1;
TABLE[186][304] = 1;
TABLE[186][43] = 1;
TABLE[186][45] = 1;
TABLE[186][40] = 1;
TABLE[186][278] = 1;
TABLE[186][37] = 1;
TABLE[186][47] = 1;
TABLE[186][42] = 1;
TABLE[186][294] = 1;
TABLE[186][295] = 1;
TABLE[186][303] = 1;
TABLE[186][301] = 1;
TABLE[186][305] = 1;
TABLE[186][33] = 1;
TABLE[186][126] = 1;
TABLE[186][302] = 1;
TABLE[186][289] = 1;
TABLE[186][309] = 1;
TABLE[186][307] = 1;
TABLE[186][308] = 1;
TABLE[186][299] = 1;
TABLE[263][304] = 1;
TABLE[263][40] = 1;
TABLE[263][45] = 1;
TABLE[263][43] = 1;
TABLE[263][42] = 1;
TABLE[263][47] = 1;
TABLE[263][37] = 1;
TABLE[263][278] = 1;
TABLE[263][295] = 1;
TABLE[263][294] = 1;
TABLE[263][289] = 1;
TABLE[263][302] = 1;
TABLE[263][126] = 1;
TABLE[263][33] = 1;
TABLE[263][305] = 1;
TABLE[263][301] = 1;
TABLE[263][303] = 1;
TABLE[263][299] = 1;
TABLE[263][308] = 1;
TABLE[263][307] = 1;
TABLE[263][309] = 1;
TABLE[263][63] = 1;
TABLE[263][59] = 1;
TABLE[263][41] = 1;
TABLE[263][292] = 1;
TABLE[263][298] = 1;
TABLE[263][297] = 1;
TABLE[263][125] = 1;
TABLE[263][93] = 1;
TABLE[263][58] = 1;
TABLE[263][44] = 1;
TABLE[82][63] = 1;
TABLE[82][59] = 1;
TABLE[82][41] = 1;
TABLE[82][292] = 1;
TABLE[82][298] = 1;
TABLE[82][297] = 1;
TABLE[82][125] = 1;
TABLE[82][93] = 1;
TABLE[82][58] = 1;
TABLE[82][44] = 1;
TABLE[82][304] = 1;
TABLE[82][43] = 1;
TABLE[82][45] = 1;
TABLE[82][40] = 1;
TABLE[82][278] = 1;
TABLE[82][37] = 1;
TABLE[82][47] = 1;
TABLE[82][42] = 1;
TABLE[82][294] = 1;
TABLE[82][295] = 1;
TABLE[82][303] = 1;
TABLE[82][301] = 1;
TABLE[82][305] = 1;
TABLE[82][33] = 1;
TABLE[82][126] = 1;
TABLE[82][302] = 1;
TABLE[82][289] = 1;
TABLE[82][309] = 1;
TABLE[82][307] = 1;
TABLE[82][308] = 1;
TABLE[82][299] = 1;
TABLE[187][304] = 1;
TABLE[187][40] = 1;
TABLE[187][45] = 1;
TABLE[187][43] = 1;
TABLE[187][42] = 1;
TABLE[187][47] = 1;
TABLE[187][37] = 1;
TABLE[187][278] = 1;
TABLE[187][295] = 1;
TABLE[187][294] = 1;
TABLE[187][289] = 1;
TABLE[187][302] = 1;
TABLE[187][126] = 1;
TABLE[187][33] = 1;
TABLE[187][305] = 1;
TABLE[187][301] = 1;
TABLE[187][303] = 1;
TABLE[187][299] = 1;
TABLE[187][308] = 1;
TABLE[187][307] = 1;
TABLE[187][309] = 1;
TABLE[264][43] = 1;
TABLE[264][45] = 1;
TABLE[264][40] = 1;
TABLE[264][278] = 1;
TABLE[264][37] = 1;
TABLE[264][47] = 1;
TABLE[264][42] = 1;
TABLE[264][294] = 1;
TABLE[264][295] = 1;
TABLE[264][303] = 1;
TABLE[264][301] = 1;
TABLE[264][305] = 1;
TABLE[264][33] = 1;
TABLE[264][126] = 1;
TABLE[264][302] = 1;
TABLE[264][289] = 1;
TABLE[264][309] = 1;
TABLE[264][307] = 1;
TABLE[264][308] = 1;
TABLE[264][299] = 1;
TABLE[264][63] = 1;
TABLE[264][59] = 1;
TABLE[264][41] = 1;
TABLE[264][304] = 1;
TABLE[264][292] = 1;
TABLE[264][298] = 1;
TABLE[264][297] = 1;
TABLE[264][125] = 1;
TABLE[264][93] = 1;
TABLE[264][58] = 1;
TABLE[264][44] = 1;
TABLE[83][63] = 1;
TABLE[83][59] = 1;
TABLE[83][41] = 1;
TABLE[83][304] = 1;
TABLE[83][292] = 1;
TABLE[83][298] = 1;
TABLE[83][297] = 1;
TABLE[83][125] = 1;
TABLE[83][93] = 1;
TABLE[83][58] = 1;
TABLE[83][44] = 1;
TABLE[83][45] = 1;
TABLE[83][43] = 1;
TABLE[83][40] = 1;
TABLE[83][42] = 1;
TABLE[83][47] = 1;
TABLE[83][37] = 1;
TABLE[83][278] = 1;
TABLE[83][295] = 1;
TABLE[83][294] = 1;
TABLE[83][289] = 1;
TABLE[83][302] = 1;
TABLE[83][126] = 1;
TABLE[83][33] = 1;
TABLE[83][305] = 1;
TABLE[83][301] = 1;
TABLE[83][303] = 1;
TABLE[83][299] = 1;
TABLE[83][308] = 1;
TABLE[83][307] = 1;
TABLE[83][309] = 1;
TABLE[190][43] = 1;
TABLE[190][45] = 1;
TABLE[190][40] = 1;
TABLE[190][278] = 1;
TABLE[190][37] = 1;
TABLE[190][47] = 1;
TABLE[190][42] = 1;
TABLE[190][294] = 1;
TABLE[190][295] = 1;
TABLE[190][303] = 1;
TABLE[190][301] = 1;
TABLE[190][305] = 1;
TABLE[190][33] = 1;
TABLE[190][126] = 1;
TABLE[190][302] = 1;
TABLE[190][289] = 1;
TABLE[190][309] = 1;
TABLE[190][307] = 1;
TABLE[190][308] = 1;
TABLE[190][299] = 1;
TABLE[265][40] = 1;
TABLE[265][42] = 1;
TABLE[265][47] = 1;
TABLE[265][37] = 1;
TABLE[265][278] = 1;
TABLE[265][295] = 1;
TABLE[265][294] = 1;
TABLE[265][289] = 1;
TABLE[265][302] = 1;
TABLE[265][43] = 1;
TABLE[265][45] = 1;
TABLE[265][126] = 1;
TABLE[265][33] = 1;
TABLE[265][305] = 1;
TABLE[265][301] = 1;
TABLE[265][303] = 1;
TABLE[265][299] = 1;
TABLE[265][308] = 1;
TABLE[265][307] = 1;
TABLE[265][309] = 1;
TABLE[265][63] = 1;
TABLE[265][59] = 1;
TABLE[265][41] = 1;
TABLE[265][304] = 1;
TABLE[265][292] = 1;
TABLE[265][298] = 1;
TABLE[265][297] = 1;
TABLE[265][125] = 1;
TABLE[265][93] = 1;
TABLE[265][58] = 1;
TABLE[265][44] = 1;
TABLE[188][43] = 1;
TABLE[189][45] = 1;
TABLE[84][40] = 1;
TABLE[84][37] = 1;
TABLE[84][47] = 1;
TABLE[84][42] = 1;
TABLE[84][278] = 1;
TABLE[84][294] = 1;
TABLE[84][295] = 1;
TABLE[84][303] = 1;
TABLE[84][301] = 1;
TABLE[84][305] = 1;
TABLE[84][33] = 1;
TABLE[84][126] = 1;
TABLE[84][45] = 1;
TABLE[84][43] = 1;
TABLE[84][302] = 1;
TABLE[84][289] = 1;
TABLE[84][309] = 1;
TABLE[84][307] = 1;
TABLE[84][308] = 1;
TABLE[84][299] = 1;
TABLE[194][40] = 1;
TABLE[194][42] = 1;
TABLE[194][47] = 1;
TABLE[194][37] = 1;
TABLE[194][278] = 1;
TABLE[194][295] = 1;
TABLE[194][294] = 1;
TABLE[194][289] = 1;
TABLE[194][302] = 1;
TABLE[194][43] = 1;
TABLE[194][45] = 1;
TABLE[194][126] = 1;
TABLE[194][33] = 1;
TABLE[194][305] = 1;
TABLE[194][301] = 1;
TABLE[194][303] = 1;
TABLE[194][299] = 1;
TABLE[194][308] = 1;
TABLE[194][307] = 1;
TABLE[194][309] = 1;
TABLE[266][40] = 1;
TABLE[266][278] = 1;
TABLE[266][294] = 1;
TABLE[266][295] = 1;
TABLE[266][303] = 1;
TABLE[266][301] = 1;
TABLE[266][305] = 1;
TABLE[266][33] = 1;
TABLE[266][126] = 1;
TABLE[266][45] = 1;
TABLE[266][43] = 1;
TABLE[266][42] = 1;
TABLE[266][302] = 1;
TABLE[266][289] = 1;
TABLE[266][309] = 1;
TABLE[266][307] = 1;
TABLE[266][308] = 1;
TABLE[266][299] = 1;
TABLE[191][42] = 1;
TABLE[192][47] = 1;
TABLE[193][37] = 1;
TABLE[85][278] = 1;
TABLE[85][295] = 1;
TABLE[85][294] = 1;
TABLE[85][289] = 1;
TABLE[85][40] = 1;
TABLE[85][302] = 1;
TABLE[85][42] = 1;
TABLE[85][43] = 1;
TABLE[85][45] = 1;
TABLE[85][126] = 1;
TABLE[85][33] = 1;
TABLE[85][305] = 1;
TABLE[85][301] = 1;
TABLE[85][303] = 1;
TABLE[85][299] = 1;
TABLE[85][308] = 1;
TABLE[85][307] = 1;
TABLE[85][309] = 1;
TABLE[86][40] = 1;
TABLE[87][40] = 1;
TABLE[87][289] = 1;
TABLE[87][309] = 1;
TABLE[87][307] = 1;
TABLE[87][308] = 1;
TABLE[87][299] = 1;
TABLE[88][294] = 1;
TABLE[88][295] = 1;
TABLE[89][303] = 1;
TABLE[89][301] = 1;
TABLE[89][305] = 1;
TABLE[89][33] = 1;
TABLE[89][126] = 1;
TABLE[89][45] = 1;
TABLE[89][43] = 1;
TABLE[89][42] = 1;
TABLE[89][302] = 1;
TABLE[90][278] = 1;
TABLE[91][278] = 1;
TABLE[195][294] = 1;
TABLE[196][295] = 1;
TABLE[92][302] = 1;
TABLE[92][42] = 1;
TABLE[92][43] = 1;
TABLE[92][45] = 1;
TABLE[92][126] = 1;
TABLE[92][33] = 1;
TABLE[92][305] = 1;
TABLE[92][301] = 1;
TABLE[92][303] = 1;
TABLE[197][302] = 1;
TABLE[198][42] = 1;
TABLE[199][43] = 1;
TABLE[200][45] = 1;
TABLE[201][126] = 1;
TABLE[202][33] = 1;
TABLE[203][305] = 1;
TABLE[204][301] = 1;
TABLE[205][303] = 1;
TABLE[93][289] = 1;
TABLE[93][40] = 1;
TABLE[93][299] = 1;
TABLE[93][308] = 1;
TABLE[93][307] = 1;
TABLE[93][309] = 1;
TABLE[94][40] = 1;
TABLE[94][289] = 1;
TABLE[94][309] = 1;
TABLE[94][307] = 1;
TABLE[94][308] = 1;
TABLE[94][299] = 1;
TABLE[206][91] = 1;
TABLE[208][40] = 1;
TABLE[209][46] = 1;
TABLE[210][296] = 1;
TABLE[211][294] = 1;
TABLE[212][295] = 1;
TABLE[207][41] = 1;
TABLE[207][44] = 1;
TABLE[207][278] = 1;
TABLE[207][295] = 1;
TABLE[207][294] = 1;
TABLE[207][63] = 1;
TABLE[207][289] = 1;
TABLE[207][40] = 1;
TABLE[207][302] = 1;
TABLE[207][42] = 1;
TABLE[207][43] = 1;
TABLE[207][45] = 1;
TABLE[207][126] = 1;
TABLE[207][33] = 1;
TABLE[207][305] = 1;
TABLE[207][301] = 1;
TABLE[207][303] = 1;
TABLE[207][297] = 1;
TABLE[207][299] = 1;
TABLE[207][308] = 1;
TABLE[207][307] = 1;
TABLE[207][309] = 1;
TABLE[207][298] = 1;
TABLE[207][292] = 1;
TABLE[207][304] = 1;
TABLE[207][37] = 1;
TABLE[207][47] = 1;
TABLE[267][41] = 1;
TABLE[95][299] = 1;
TABLE[96][309] = 1;
TABLE[96][307] = 1;
TABLE[96][308] = 1;
TABLE[96][299] = 1;
TABLE[97][289] = 1;
TABLE[98][40] = 1;
TABLE[99][41] = 1;
TABLE[99][44] = 1;
TABLE[99][278] = 1;
TABLE[99][63] = 1;
TABLE[99][294] = 1;
TABLE[99][295] = 1;
TABLE[99][297] = 1;
TABLE[99][303] = 1;
TABLE[99][301] = 1;
TABLE[99][305] = 1;
TABLE[99][33] = 1;
TABLE[99][126] = 1;
TABLE[99][45] = 1;
TABLE[99][43] = 1;
TABLE[99][42] = 1;
TABLE[99][302] = 1;
TABLE[99][40] = 1;
TABLE[99][289] = 1;
TABLE[99][298] = 1;
TABLE[99][309] = 1;
TABLE[99][307] = 1;
TABLE[99][308] = 1;
TABLE[99][299] = 1;
TABLE[99][292] = 1;
TABLE[99][304] = 1;
TABLE[99][47] = 1;
TABLE[99][37] = 1;
TABLE[213][44] = 1;
TABLE[213][278] = 1;
TABLE[213][295] = 1;
TABLE[213][294] = 1;
TABLE[213][63] = 1;
TABLE[213][289] = 1;
TABLE[213][40] = 1;
TABLE[213][302] = 1;
TABLE[213][42] = 1;
TABLE[213][43] = 1;
TABLE[213][45] = 1;
TABLE[213][126] = 1;
TABLE[213][33] = 1;
TABLE[213][305] = 1;
TABLE[213][301] = 1;
TABLE[213][303] = 1;
TABLE[213][297] = 1;
TABLE[213][299] = 1;
TABLE[213][308] = 1;
TABLE[213][307] = 1;
TABLE[213][309] = 1;
TABLE[213][298] = 1;
TABLE[213][292] = 1;
TABLE[213][304] = 1;
TABLE[213][37] = 1;
TABLE[213][47] = 1;
TABLE[268][278] = 1;
TABLE[268][63] = 1;
TABLE[268][294] = 1;
TABLE[268][295] = 1;
TABLE[268][297] = 1;
TABLE[268][303] = 1;
TABLE[268][301] = 1;
TABLE[268][305] = 1;
TABLE[268][33] = 1;
TABLE[268][126] = 1;
TABLE[268][45] = 1;
TABLE[268][43] = 1;
TABLE[268][42] = 1;
TABLE[268][302] = 1;
TABLE[268][40] = 1;
TABLE[268][289] = 1;
TABLE[268][298] = 1;
TABLE[268][309] = 1;
TABLE[268][307] = 1;
TABLE[268][308] = 1;
TABLE[268][299] = 1;
TABLE[268][292] = 1;
TABLE[268][304] = 1;
TABLE[268][47] = 1;
TABLE[268][37] = 1;
TABLE[268][41] = 1;
TABLE[268][44] = 1;
TABLE[100][309] = 1;
TABLE[101][307] = 1;
TABLE[102][308] = 1;
TABLE[103][299] = 1;
TABLE[104][299] = 1;
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
      case 55: return 1; break;
      case 61: return 1; break;
      case 68: return 1; break;
      case 73: return 1; break;
      case 81: return 1; break;
      case 85: return 1; break;
      case 103: return 0; break;
      case 107: return 0; break;
      case 127: return 0; break;
      case 143: return 0; break;
      case 179: return 0; break;
      case 183: return 0; break;
      case 191: return 0; break;
      case 204: return 1; break;
      case 211: return 0; break;
      case 215: return 0; break;
      case 223: return 1; break;
      case 228: return 1; break;
      case 235: return 1; break;
      case 240: return 1; break;
      case 248: return 1; break;
      case 253: return 1; break;
      case 261: return 0; break;
      case 267: return 0; break;
      case 272: return 0; break;
      case 280: return 1; break;
      case 287: return 1; break;
      case 292: return 1; break;
      case 300: return 1; break;
      case 310: return 1; break;
      case 317: return 0; break;
      case 330: return 1; break;
      case 337: return 1; break;
      case 342: return 1; break;
      case 350: return 0; break;
      case 355: return 1; break;
      case 363: return 1; break;
      case 368: return 1; break;
      case 375: return 0; break;
      case 390: return 0; break;
      case 408: return 1; break;
      case 415: return 1; break;
      case 422: return 0; break;
      case 428: return 1; break;
      case 435: return 1; break;
      case 442: return 1; break;
      case 447: return 1; break;
      case 454: return 1; break;
      case 459: return 1; break;
      case 467: return 1; break;
      case 472: return 1; break;
      case 480: return 1; break;
      case 485: return 1; break;
      case 493: return 1; break;
      case 500: return 1; break;
      case 505: return 1; break;
      case 513: return 1; break;
      case 524: return 1; break;
      case 531: return 1; break;
      case 536: return 1; break;
      case 544: return 0; break;
      case 549: return 1; break;
      case 556: return 1; break;
      case 565: return 1; break;
      case 572: return 1; break;
      case 583: return 1; break;
      case 590: return 0; break;
      case 602: return 1; break;
      case 609: return 1; break;
      case 616: return 0; break;
      case 620: return 1; break;
      case 644: return 0; break;
      case 663: return 1; break;
      case 668: return 1; break;
      case 675: return 0; break;
      case 682: return 1; break;
      case 689: return 1; break;
      case 696: return 1; break;
      case 701: return 1; break;
      case 708: return 0; break;
      case 725: return 1; break;
      case 733: return 0; break;
      case 763: return 1; break;
      case 770: return 1; break;
      case 777: return 1; break;
      case 784: return 0; break;
      case 806: return 1; break;
      case 813: return 1; break;
      case 818: return 1; break;
      case 826: return 1; break;
      case 836: return 0; break;
      case 844: return 1; break;
      case 849: return 1; break;
      case 859: return 1; break;
      case 863: return 1; break;
      case 868: return 1; break;
      case 876: return 1; break;
      case 881: return 1; break;
      case 889: return 1; break;
      case 894: return 1; break;
      case 902: return 1; break;
      case 907: return 1; break;
      case 915: return 1; break;
      case 920: return 1; break;
      case 928: return 1; break;
      case 933: return 1; break;
      case 941: return 1; break;
      case 946: return 1; break;
      case 954: return 1; break;
      case 959: return 1; break;
      case 967: return 0; break;
      case 975: return 1; break;
      case 980: return 1; break;
      case 988: return 0; break;
      case 1000: return 0; break;
      case 1011: return 0; break;
      case 1037: return 0; break;
      case 1045: return 0; break;
      case 1049: return 0; break;
      case 1085: return 0; break;
      case 1094: return 0; break;
      case 1124: return 1; break;
      case 1131: return 0; break;
      case 1149: return 1; break;
      case 1154: return 1; break;
      case 1162: return 0; break;
      case 1178: return 0; break;
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
         case 47: return "Subphrase"; break;
         case 55: return "declaration"; break;
         case 61: return "Subphrase"; break;
         case 68: return "declaration_list"; break;
         case 73: return "Subphrase"; break;
         case 81: return "declaration_specifiers"; break;
         case 85: return "Subphrase"; break;
         case 103: return "storage_class_specifier"; break;
         case 107: return "Subphrase"; break;
         case 127: return "type_specifier"; break;
         case 143: return "Subphrase"; break;
         case 179: return "type_qualifier"; break;
         case 183: return "Subphrase"; break;
         case 191: return "struct_or_union_specifier"; break;
         case 204: return "Subphrase"; break;
         case 211: return "struct_or_union"; break;
         case 215: return "Subphrase"; break;
         case 223: return "struct_declaration_list"; break;
         case 228: return "Subphrase"; break;
         case 235: return "init_declarator_list"; break;
         case 240: return "Subphrase"; break;
         case 248: return "init_declarator"; break;
         case 253: return "Subphrase"; break;
         case 261: return "struct_declaration"; break;
         case 267: return "specifier_qualifier_list"; break;
         case 272: return "Subphrase"; break;
         case 280: return "Subphrase"; break;
         case 287: return "struct_declarator_list"; break;
         case 292: return "Subphrase"; break;
         case 300: return "struct_declarator"; break;
         case 310: return "Subphrase"; break;
         case 317: return "enum_specifier"; break;
         case 330: return "Subphrase"; break;
         case 337: return "enumerator_list"; break;
         case 342: return "Subphrase"; break;
         case 350: return "enumerator"; break;
         case 355: return "Subphrase"; break;
         case 363: return "declarator"; break;
         case 368: return "Subphrase"; break;
         case 375: return "direct_declarator"; break;
         case 390: return "Subphrase"; break;
         case 408: return "Subphrase"; break;
         case 415: return "Subphrase"; break;
         case 422: return "pointer"; break;
         case 428: return "Subphrase"; break;
         case 435: return "Subphrase"; break;
         case 442: return "type_qualifier_list"; break;
         case 447: return "Subphrase"; break;
         case 454: return "parameter_type_list"; break;
         case 459: return "Subphrase"; break;
         case 467: return "parameter_list"; break;
         case 472: return "Subphrase"; break;
         case 480: return "parameter_declaration"; break;
         case 485: return "Subphrase"; break;
         case 493: return "Subphrase"; break;
         case 500: return "identifier_list"; break;
         case 505: return "Subphrase"; break;
         case 513: return "initializer"; break;
         case 524: return "Subphrase"; break;
         case 531: return "initializer_list"; break;
         case 536: return "Subphrase"; break;
         case 544: return "type_name"; break;
         case 549: return "Subphrase"; break;
         case 556: return "abstract_declarator"; break;
         case 565: return "Subphrase"; break;
         case 572: return "direct_abstract_declarator"; break;
         case 583: return "Subphrase"; break;
         case 590: return "Subphrase"; break;
         case 602: return "Subphrase"; break;
         case 609: return "Subphrase"; break;
         case 616: return "typedef_name"; break;
         case 620: return "statement"; break;
         case 644: return "labeled_statement"; break;
         case 663: return "expression_statement"; break;
         case 668: return "Subphrase"; break;
         case 675: return "compound_statement"; break;
         case 682: return "Subphrase"; break;
         case 689: return "Subphrase"; break;
         case 696: return "statement_list"; break;
         case 701: return "Subphrase"; break;
         case 708: return "selection_statement"; break;
         case 725: return "Subphrase"; break;
         case 733: return "iteration_statement"; break;
         case 763: return "Subphrase"; break;
         case 770: return "Subphrase"; break;
         case 777: return "Subphrase"; break;
         case 784: return "jump_statement"; break;
         case 806: return "Subphrase"; break;
         case 813: return "expression"; break;
         case 818: return "Subphrase"; break;
         case 826: return "assignment_expression"; break;
         case 836: return "assignment_operator"; break;
         case 844: return "conditional_expression"; break;
         case 849: return "Subphrase"; break;
         case 859: return "constant_expression"; break;
         case 863: return "logical_OR_expression"; break;
         case 868: return "Subphrase"; break;
         case 876: return "logical_AND_expression"; break;
         case 881: return "Subphrase"; break;
         case 889: return "inclusive_OR_expression"; break;
         case 894: return "Subphrase"; break;
         case 902: return "exclusive_OR_expression"; break;
         case 907: return "Subphrase"; break;
         case 915: return "AND_expression"; break;
         case 920: return "Subphrase"; break;
         case 928: return "equality_expression"; break;
         case 933: return "Subphrase"; break;
         case 941: return "shift_expression"; break;
         case 946: return "Subphrase"; break;
         case 954: return "additive_expression"; break;
         case 959: return "Subphrase"; break;
         case 967: return "Subphrase"; break;
         case 975: return "multiplicative_expression"; break;
         case 980: return "Subphrase"; break;
         case 988: return "Subphrase"; break;
         case 1000: return "cast_expression"; break;
         case 1011: return "unary_expression"; break;
         case 1037: return "Subphrase"; break;
         case 1045: return "unary_operator"; break;
         case 1049: return "Subphrase"; break;
         case 1085: return "postfix_expression"; break;
         case 1094: return "Subphrase"; break;
         case 1124: return "Subphrase"; break;
         case 1131: return "primary_expression"; break;
         case 1149: return "argument_expression_list"; break;
         case 1154: return "Subphrase"; break;
         case 1162: return "constant"; break;
         case 1178: return "id"; break;
   }
   else 
      switch(n-50000) {
         case 309: return "INTCONST"; break;
         case 308: return "FLOATCONST"; break;
         case 307: return "CHARACTER"; break;
         case 306: return "INCLUDE"; break;
         case 305: return "BIT_NOT"; break;
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
