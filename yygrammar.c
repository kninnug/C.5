#line 6 "ass3.acc"

	#include <stdio.h>
	#include <stdlib.h>
	
	#include "parser.h"
	
	extern FILE * out;
	
	void escapeChar(FILE * out, int c){
		switch(c){
			case '\\':
				fputs("\\textbackslash ", out);
			break;
			
			case '<':
			case '>':
				fputc('$', out);
				fputc(c, out);
				fputc('$', out);
			break;
			
			case '&':
			case '%':
			case '{':
			case '}':
			case '_':
				fputc('\\', out);
			/* fall-through: w00t! */
			default:
				fputc(c, out);
		}
	}
	
	void escapeString(FILE * out, char * s){
		while(*s) escapeChar(out, *s++);
	}
	
	void printSubtype(FILE * out, int st){
		fputs("\\ $", out);
		switch(st){
			case COMPARE_EQUAL: fputs("==", out); break;
			case COMPARE_UNEQUAL: fputs("\\neq", out); break;
			case COMPARE_LEQ: fputs("\\leq", out); break;
			case COMPARE_GREQ: fputs("\\geq", out); break;
			case COMPARE_GREATER: fputs(">", out); break;
			case COMPARE_LESS: fputs("<", out); break;
			
			case ASSIGN_AND: fputs("\\&=", out); break;
			case ASSIGN_DIVIDE: fputs("/=", out); break;
			case ASSIGN_MINUS: fputs("-=", out); break;
			case ASSIGN_MOD: fputs("\\%=", out); break;
			case ASSIGN_OR: fputs("|=", out); break;
			case ASSIGN_PLUS: fputs("+=", out); break;
			case ASSIGN_SHLEFT: fputs("<<=", out); break;
			case ASSIGN_SHRIGHT: fputs(">>=", out); break;
			case ASSIGN_XOR: fputs("\\^=", out); break;
			
			case ASSIGN_SWAP: fputs("\\leftrightarrow", out); break;
		}
		fputs("$\\ ", out);
	}
	
	/* Nice cryptic macros for shortening semantic-action blocks */
	#define PRCH escapeChar(out, yylval.c)
	#define PRCHS PRCH, fputs("\\ ", out)
	/* long live the comma-operator! */
	#define SPRCHS fputs("\\ ", out), PRCHS
	#define PRS escapeString(out, yylval.s)
	#define PRKW fprintf(out, "{\\bf %s} ", yylval.s)
	#define PRSC fputs(";\\\\\n", out)

# line 74 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 108: {
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
         case 109: {
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
      case 110: {
         declaration_specifiers();
         } break;
      default: ;
      }
      declarator();
      switch (yyselect()) {
      case 111: {
         declaration_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 112: {
         get_lexval();
#line 96 "ass3.acc"
 fputs(";\\\\\\\n", out); 
# line 138 "yygrammar.c"
         } break;
      case 113: {
         compound_statement();
#line 96 "ass3.acc"
 fputs("\\\\\n", out); 
# line 144 "yygrammar.c"
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
      case 114: {
         init_declarator_list();
         } break;
      default: ;
      }
      get_lexval();
#line 100 "ass3.acc"
 PRSC; 
# line 166 "yygrammar.c"
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
         case 115: {
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
         case 116: {
            storage_class_specifier();
            } break;
         case 117: {
            type_specifier();
            } break;
         case 118: {
            type_qualifier();
            } break;
         default: goto yy3;
         }
      }
      yy3: ;
#line 108 "ass3.acc"
 fputc(' ', out); 
# line 210 "yygrammar.c"
      } break;
   }
}

storage_class_specifier ()
{
   switch(yyselect()) {
   case 8: {
      switch (yyselect()) {
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
      default: printf("???\n"); exit(1);
      }
#line 116 "ass3.acc"
 PRKW; 
# line 239 "yygrammar.c"
      } break;
   }
}

type_specifier ()
{
   switch(yyselect()) {
   case 9: {
      switch (yyselect()) {
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
      case 130: {
         get_lexval();
         } break;
      case 131: {
         get_lexval();
         } break;
      case 132: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 129 "ass3.acc"
 PRKW; 
# line 280 "yygrammar.c"
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
      case 133: {
         get_lexval();
         } break;
      case 134: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 136 "ass3.acc"
 PRKW; 
# line 309 "yygrammar.c"
      } break;
   }
}

struct_or_union_specifier ()
{
   switch(yyselect()) {
   case 14: {
      struct_or_union();
      switch (yyselect()) {
      case 135: {
         id();
         } break;
      default: ;
      }
      get_lexval();
#line 140 "ass3.acc"
 fputs("\\{\\\\\n", out); 
# line 328 "yygrammar.c"
      struct_declaration_list();
      get_lexval();
#line 140 "ass3.acc"
 fputs("\\}\\\\\n", out); 
# line 333 "yygrammar.c"
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
      case 136: {
         get_lexval();
         } break;
      case 137: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 145 "ass3.acc"
 PRKW; 
# line 357 "yygrammar.c"
      } break;
   }
}

struct_declaration_list ()
{
   switch(yyselect()) {
   case 17: {
      switch (yyselect()) {
      case 138: {
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
      case 139: {
         init_declarator_list();
         get_lexval();
#line 153 "ass3.acc"
 PRCHS; 
# line 387 "yygrammar.c"
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
      case 140: {
         declarator();
         get_lexval();
#line 157 "ass3.acc"
 SPRCHS; 
# line 406 "yygrammar.c"
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
#line 161 "ass3.acc"
 PRSC; 
# line 424 "yygrammar.c"
      } break;
   }
}

specifier_qualifier_list ()
{
   switch(yyselect()) {
   case 21: {
      switch (yyselect()) {
      case 141: {
         type_specifier();
         } break;
      case 142: {
         type_qualifier();
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 143: {
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
      case 144: {
         struct_declarator_list();
         get_lexval();
#line 169 "ass3.acc"
 PRCHS; 
# line 462 "yygrammar.c"
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
      case 145: {
         declarator();
         } break;
      default: ;
      }
      get_lexval();
#line 174 "ass3.acc"
 PRCHS; 
# line 487 "yygrammar.c"
      constant_expression();
      } break;
   }
}

enum_specifier ()
{
   switch(yyselect()) {
   case 25: {
      get_lexval();
#line 178 "ass3.acc"
 PRKW; 
# line 500 "yygrammar.c"
      switch (yyselect()) {
      case 146: {
         id();
         } break;
      default: ;
      }
#line 178 "ass3.acc"
 fputs("\\{\\\\\n", out); 
# line 509 "yygrammar.c"
      get_lexval();
      enumerator_list();
      get_lexval();
#line 178 "ass3.acc"
 fputs("\\}\\\\\n", out); 
# line 515 "yygrammar.c"
      } break;
   case 26: {
      get_lexval();
#line 179 "ass3.acc"
 PRKW; 
# line 521 "yygrammar.c"
      id();
      } break;
   }
}

enumerator_list ()
{
   switch(yyselect()) {
   case 27: {
      switch (yyselect()) {
      case 147: {
         enumerator_list();
         get_lexval();
#line 183 "ass3.acc"
 PRCHS; 
# line 537 "yygrammar.c"
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
      case 148: {
         get_lexval();
#line 187 "ass3.acc"
 SPRCHS; 
# line 556 "yygrammar.c"
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
      case 149: {
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
#line 196 "ass3.acc"
 PRCH; 
# line 590 "yygrammar.c"
      declarator();
      get_lexval();
#line 196 "ass3.acc"
 PRCH; 
# line 595 "yygrammar.c"
      } break;
   case 32: {
      direct_declarator();
      switch (yyselect()) {
      case 151: {
         get_lexval();
#line 197 "ass3.acc"
 PRCH; 
# line 604 "yygrammar.c"
         switch (yyselect()) {
         case 150: {
            expression();
            } break;
         default: ;
         }
         get_lexval();
#line 197 "ass3.acc"
 PRCH; 
# line 614 "yygrammar.c"
         } break;
      case 152: {
         get_lexval();
#line 198 "ass3.acc"
 PRCH; 
# line 620 "yygrammar.c"
         parameter_type_list();
         get_lexval();
#line 198 "ass3.acc"
 PRCH; 
# line 625 "yygrammar.c"
         } break;
      case 154: {
         get_lexval();
#line 199 "ass3.acc"
 PRCH; 
# line 631 "yygrammar.c"
         switch (yyselect()) {
         case 153: {
            identifier_list();
            } break;
         default: ;
         }
         get_lexval();
#line 199 "ass3.acc"
 PRCH; 
# line 641 "yygrammar.c"
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
#line 203 "ass3.acc"
 PRCH; 
# line 656 "yygrammar.c"
      switch (yyselect()) {
      case 155: {
         type_qualifier_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 156: {
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
      case 157: {
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
      case 158: {
         get_lexval();
#line 211 "ass3.acc"
 PRCHS; 
# line 698 "yygrammar.c"
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
      case 159: {
         parameter_list();
         get_lexval();
#line 215 "ass3.acc"
 PRCHS; 
# line 717 "yygrammar.c"
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
      case 160: {
         declarator();
         } break;
      case 162: {
         switch (yyselect()) {
         case 161: {
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
      case 163: {
         identifier_list();
         get_lexval();
#line 223 "ass3.acc"
 PRCHS; 
# line 759 "yygrammar.c"
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
#line 228 "ass3.acc"
 fputs("\\{", out); 
# line 778 "yygrammar.c"
      initializer_list();
      switch (yyselect()) {
      case 164: {
         get_lexval();
         } break;
      default: ;
      }
      get_lexval();
#line 228 "ass3.acc"
 fputs("\\}", out); 
# line 789 "yygrammar.c"
      } break;
   }
}

initializer_list ()
{
   switch(yyselect()) {
   case 41: {
      switch (yyselect()) {
      case 165: {
         initializer_list();
         get_lexval();
#line 232 "ass3.acc"
 PRCHS; 
# line 804 "yygrammar.c"
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
      case 166: {
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
      case 167: {
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
#line 245 "ass3.acc"
 PRCH; 
# line 853 "yygrammar.c"
      abstract_declarator();
      get_lexval();
#line 245 "ass3.acc"
 PRCH; 
# line 858 "yygrammar.c"
      } break;
   case 46: {
      switch (yyselect()) {
      case 168: {
         direct_abstract_declarator();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 170: {
         get_lexval();
#line 246 "ass3.acc"
 PRCH; 
# line 872 "yygrammar.c"
         switch (yyselect()) {
         case 169: {
            expression();
            } break;
         default: ;
         }
         get_lexval();
#line 246 "ass3.acc"
 PRCH; 
# line 882 "yygrammar.c"
         } break;
      case 172: {
         get_lexval();
#line 247 "ass3.acc"
 PRCH; 
# line 888 "yygrammar.c"
         switch (yyselect()) {
         case 171: {
            parameter_type_list();
            } break;
         default: ;
         }
         get_lexval();
#line 247 "ass3.acc"
 PRCH; 
# line 898 "yygrammar.c"
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
   case 54: {
      print_statement();
      } break;
   case 55: {
      input_statement();
      } break;
   }
}

labeled_statement ()
{
   switch(yyselect()) {
   case 56: {
      id();
      get_lexval();
#line 266 "ass3.acc"
 PRCHS; 
# line 953 "yygrammar.c"
      statement();
      } break;
   case 57: {
      get_lexval();
#line 267 "ass3.acc"
 PRKW; 
# line 960 "yygrammar.c"
      constant_expression();
      get_lexval();
#line 267 "ass3.acc"
 PRCHS; 
# line 965 "yygrammar.c"
      statement();
      } break;
   case 58: {
      get_lexval();
#line 268 "ass3.acc"
 PRKW; 
# line 972 "yygrammar.c"
      get_lexval();
#line 268 "ass3.acc"
 PRCHS; 
# line 976 "yygrammar.c"
      statement();
      } break;
   }
}

expression_statement ()
{
   switch(yyselect()) {
   case 59: {
      switch (yyselect()) {
      case 173: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 272 "ass3.acc"
 PRSC; 
# line 995 "yygrammar.c"
      } break;
   }
}

compound_statement ()
{
   switch(yyselect()) {
   case 60: {
      get_lexval();
#line 276 "ass3.acc"
 fputs("\\{\\+\\\\\n", out); 
# line 1007 "yygrammar.c"
      switch (yyselect()) {
      case 174: {
         declaration_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 175: {
         statement_list();
         } break;
      default: ;
      }
      get_lexval();
#line 276 "ass3.acc"
 fputs("\\<\\}\\-\\\\\n", out); 
# line 1023 "yygrammar.c"
      } break;
   }
}

statement_list ()
{
   switch(yyselect()) {
   case 61: {
      while (1) {
         switch (yyselect()) {
         case 176: {
            statement();
            } break;
         default: goto yy4;
         }
      }
      yy4: ;
      statement();
      } break;
   }
}

selection_statement ()
{
   switch(yyselect()) {
   case 62: {
      get_lexval();
#line 289 "ass3.acc"
 PRKW; 
# line 1053 "yygrammar.c"
      get_lexval();
#line 289 "ass3.acc"
 PRCH; 
# line 1057 "yygrammar.c"
      expression();
      get_lexval();
#line 289 "ass3.acc"
 PRCH; 
# line 1062 "yygrammar.c"
      statement();
      switch (yyselect()) {
      case 177: {
         get_lexval();
#line 289 "ass3.acc"
 PRKW; 
# line 1069 "yygrammar.c"
         statement();
         } break;
      default: ;
      }
      } break;
   case 63: {
      get_lexval();
#line 290 "ass3.acc"
 PRKW; 
# line 1079 "yygrammar.c"
      get_lexval();
#line 290 "ass3.acc"
 PRCH; 
# line 1083 "yygrammar.c"
      expression();
      get_lexval();
#line 290 "ass3.acc"
 PRCH; 
# line 1088 "yygrammar.c"
      statement();
      } break;
   }
}

iteration_statement ()
{
   switch(yyselect()) {
   case 64: {
      get_lexval();
#line 294 "ass3.acc"
 PRKW; 
# line 1101 "yygrammar.c"
      get_lexval();
#line 294 "ass3.acc"
 PRCH; 
# line 1105 "yygrammar.c"
      expression();
      get_lexval();
#line 294 "ass3.acc"
 PRCH; 
# line 1110 "yygrammar.c"
      statement();
      } break;
   case 65: {
      get_lexval();
#line 295 "ass3.acc"
 PRKW; 
# line 1117 "yygrammar.c"
      statement();
      get_lexval();
#line 295 "ass3.acc"
 PRKW; 
# line 1122 "yygrammar.c"
      get_lexval();
#line 295 "ass3.acc"
 PRCH; 
# line 1126 "yygrammar.c"
      expression();
      get_lexval();
#line 295 "ass3.acc"
 PRCH; 
# line 1131 "yygrammar.c"
      get_lexval();
#line 295 "ass3.acc"
 PRSC; 
# line 1135 "yygrammar.c"
      } break;
   case 66: {
      get_lexval();
#line 296 "ass3.acc"
 PRKW; 
# line 1141 "yygrammar.c"
      get_lexval();
#line 296 "ass3.acc"
 PRCH; 
# line 1145 "yygrammar.c"
      switch (yyselect()) {
      case 178: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 296 "ass3.acc"
 PRCHS; 
# line 1155 "yygrammar.c"
      switch (yyselect()) {
      case 179: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 296 "ass3.acc"
 PRCHS; 
# line 1165 "yygrammar.c"
      switch (yyselect()) {
      case 180: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 296 "ass3.acc"
 PRCH; 
# line 1175 "yygrammar.c"
      statement();
      } break;
   }
}

jump_statement ()
{
   switch(yyselect()) {
   case 67: {
      get_lexval();
#line 300 "ass3.acc"
 PRKW; 
# line 1188 "yygrammar.c"
      id();
      get_lexval();
#line 300 "ass3.acc"
 PRSC; 
# line 1193 "yygrammar.c"
      } break;
   case 68: {
      get_lexval();
#line 301 "ass3.acc"
 PRKW; 
# line 1199 "yygrammar.c"
      get_lexval();
#line 301 "ass3.acc"
 PRSC; 
# line 1203 "yygrammar.c"
      } break;
   case 69: {
      get_lexval();
#line 302 "ass3.acc"
 PRKW; 
# line 1209 "yygrammar.c"
      get_lexval();
#line 302 "ass3.acc"
 PRSC; 
# line 1213 "yygrammar.c"
      } break;
   case 70: {
      get_lexval();
#line 303 "ass3.acc"
 PRKW; 
# line 1219 "yygrammar.c"
      switch (yyselect()) {
      case 181: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 303 "ass3.acc"
 PRSC; 
# line 1229 "yygrammar.c"
      } break;
   }
}

print_statement ()
{
   switch(yyselect()) {
   case 71: {
      get_lexval();
#line 307 "ass3.acc"
 PRKW; 
# line 1241 "yygrammar.c"
      argument_expression_list();
      get_lexval();
#line 307 "ass3.acc"
 PRSC; 
# line 1246 "yygrammar.c"
      } break;
   }
}

input_statement ()
{
   switch(yyselect()) {
   case 72: {
      get_lexval();
#line 311 "ass3.acc"
 PRKW; 
# line 1258 "yygrammar.c"
      while (1) {
         switch (yyselect()) {
         case 182: {
            id();
            get_lexval();
#line 311 "ass3.acc"
 PRCHS; 
# line 1266 "yygrammar.c"
            } break;
         default: goto yy5;
         }
      }
      yy5: ;
      id();
      get_lexval();
#line 311 "ass3.acc"
 PRSC; 
# line 1276 "yygrammar.c"
      } break;
   }
}

expression ()
{
   switch(yyselect()) {
   case 73: {
      switch (yyselect()) {
      case 183: {
         expression();
         get_lexval();
#line 315 "ass3.acc"
 PRCHS; 
# line 1291 "yygrammar.c"
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
   case 74: {
      conditional_expression();
      } break;
   case 75: {
      unary_expression();
      assignment_operator();
      assignment_expression();
      } break;
   }
}

assignment_operator ()
{
   switch(yyselect()) {
   case 76: {
      get_lexval();
#line 324 "ass3.acc"
 printSubtype(out, yylval.subtype); 
# line 1321 "yygrammar.c"
      } break;
   case 77: {
      get_lexval();
#line 325 "ass3.acc"
 SPRCHS; 
# line 1327 "yygrammar.c"
      } break;
   }
}

conditional_expression ()
{
   switch(yyselect()) {
   case 78: {
      logical_OR_expression();
      switch (yyselect()) {
      case 184: {
         get_lexval();
#line 329 "ass3.acc"
 SPRCHS; 
# line 1342 "yygrammar.c"
         expression();
         get_lexval();
#line 329 "ass3.acc"
 SPRCHS; 
# line 1347 "yygrammar.c"
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
   case 79: {
      conditional_expression();
      } break;
   }
}

logical_OR_expression ()
{
   switch(yyselect()) {
   case 80: {
      switch (yyselect()) {
      case 185: {
         logical_OR_expression();
         get_lexval();
#line 337 "ass3.acc"
 fputs("\\ $\\vee$\\ ", out); 
# line 1375 "yygrammar.c"
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
   case 81: {
      switch (yyselect()) {
      case 186: {
         logical_AND_expression();
         get_lexval();
#line 341 "ass3.acc"
 fputs("\\ $\\wedge$\\ ", out); 
# line 1394 "yygrammar.c"
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
   case 82: {
      switch (yyselect()) {
      case 187: {
         inclusive_OR_expression();
         get_lexval();
#line 345 "ass3.acc"
 SPRCHS; 
# line 1413 "yygrammar.c"
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
   case 83: {
      switch (yyselect()) {
      case 188: {
         exclusive_OR_expression();
         get_lexval();
#line 349 "ass3.acc"
 SPRCHS; 
# line 1432 "yygrammar.c"
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
   case 84: {
      switch (yyselect()) {
      case 189: {
         AND_expression();
         get_lexval();
#line 353 "ass3.acc"
 SPRCHS; 
# line 1451 "yygrammar.c"
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
   case 85: {
      switch (yyselect()) {
      case 190: {
         equality_expression();
         get_lexval();
#line 357 "ass3.acc"
 printSubtype(out, yylval.subtype); 
# line 1470 "yygrammar.c"
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
   case 86: {
      switch (yyselect()) {
      case 191: {
         shift_expression();
         get_lexval();
#line 361 "ass3.acc"
 yylval.subtype == SHIFT_LEFT ? fputs("\\ $<<$\\ ", out) : fputs("\\ $>>$\\ ", out); 
# line 1489 "yygrammar.c"
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
   case 87: {
      switch (yyselect()) {
      case 194: {
         additive_expression();
         switch (yyselect()) {
         case 192: {
            get_lexval();
            } break;
         case 193: {
            get_lexval();
            } break;
         default: printf("???\n"); exit(1);
         }
#line 365 "ass3.acc"
 SPRCHS; 
# line 1516 "yygrammar.c"
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
   case 88: {
      switch (yyselect()) {
      case 198: {
         multiplicative_expression();
         switch (yyselect()) {
         case 195: {
            get_lexval();
            } break;
         case 196: {
            get_lexval();
            } break;
         case 197: {
            get_lexval();
            } break;
         default: printf("???\n"); exit(1);
         }
#line 369 "ass3.acc"
 SPRCHS; 
# line 1546 "yygrammar.c"
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
   case 89: {
      unary_expression();
      } break;
   case 90: {
      get_lexval();
#line 374 "ass3.acc"
 PRCH; 
# line 1565 "yygrammar.c"
      type_name();
      get_lexval();
#line 374 "ass3.acc"
 PRCH; 
# line 1570 "yygrammar.c"
      cast_expression();
      } break;
   }
}

unary_expression ()
{
   switch(yyselect()) {
   case 91: {
      postfix_expression();
      } break;
   case 92: {
      switch (yyselect()) {
      case 199: {
         get_lexval();
#line 379 "ass3.acc"
 fputs("++", out); 
# line 1588 "yygrammar.c"
         } break;
      case 200: {
         get_lexval();
#line 379 "ass3.acc"
 fputs("--", out); 
# line 1594 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      unary_expression();
      } break;
   case 93: {
      unary_operator();
      cast_expression();
      } break;
   case 94: {
      get_lexval();
#line 381 "ass3.acc"
 PRKW; 
# line 1608 "yygrammar.c"
      unary_expression();
      } break;
   case 95: {
      get_lexval();
#line 382 "ass3.acc"
 PRKW; 
# line 1615 "yygrammar.c"
      get_lexval();
#line 382 "ass3.acc"
 PRCH; 
# line 1619 "yygrammar.c"
      type_name();
      get_lexval();
#line 382 "ass3.acc"
 PRCH; 
# line 1624 "yygrammar.c"
      } break;
   }
}

unary_operator ()
{
   switch(yyselect()) {
   case 96: {
      switch (yyselect()) {
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
      case 206: {
         get_lexval();
         } break;
      case 207: {
         get_lexval();
         } break;
      case 208: {
         get_lexval();
         } break;
      case 209: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 386 "ass3.acc"
 PRCH; 
# line 1665 "yygrammar.c"
      } break;
   }
}

postfix_expression ()
{
   switch(yyselect()) {
   case 97: {
      primary_expression();
      } break;
   case 98: {
      postfix_expression();
      switch (yyselect()) {
      case 211: {
         get_lexval();
#line 391 "ass3.acc"
 PRCH; 
# line 1683 "yygrammar.c"
         expression();
         switch (yyselect()) {
         case 210: {
            get_lexval();
#line 391 "ass3.acc"
 SPRCHS; 
# line 1690 "yygrammar.c"
            expression();
            } break;
         default: ;
         }
         get_lexval();
#line 391 "ass3.acc"
 PRCH; 
# line 1698 "yygrammar.c"
         } break;
      case 213: {
         get_lexval();
#line 392 "ass3.acc"
 PRCH; 
# line 1704 "yygrammar.c"
         switch (yyselect()) {
         case 212: {
            argument_expression_list();
            } break;
         default: ;
         }
         get_lexval();
#line 392 "ass3.acc"
 PRCH; 
# line 1714 "yygrammar.c"
         } break;
      case 214: {
         get_lexval();
#line 393 "ass3.acc"
 PRCH; 
# line 1720 "yygrammar.c"
         id();
         } break;
      case 215: {
         get_lexval();
#line 394 "ass3.acc"
 fputs("$\\rightarrow$", out); 
# line 1727 "yygrammar.c"
         id();
         } break;
      case 216: {
         get_lexval();
#line 395 "ass3.acc"
 fputs("++", out); 
# line 1734 "yygrammar.c"
         } break;
      case 217: {
         get_lexval();
#line 396 "ass3.acc"
 fputs("--", out); 
# line 1740 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

primary_expression ()
{
   switch(yyselect()) {
   case 99: {
      id();
      } break;
   case 100: {
      constant();
      } break;
   case 101: {
      get_lexval();
#line 402 "ass3.acc"
 escapeString(out, yylval.s); 
# line 1761 "yygrammar.c"
      } break;
   case 102: {
      get_lexval();
#line 403 "ass3.acc"
 PRCH; 
# line 1767 "yygrammar.c"
      expression();
      get_lexval();
#line 403 "ass3.acc"
 PRCH; 
# line 1772 "yygrammar.c"
      } break;
   }
}

argument_expression_list ()
{
   switch(yyselect()) {
   case 103: {
      switch (yyselect()) {
      case 218: {
         argument_expression_list();
         get_lexval();
#line 407 "ass3.acc"
 PRCHS; 
# line 1787 "yygrammar.c"
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
   case 104: {
      get_lexval();
#line 411 "ass3.acc"
 fprintf(out, "$%u$", yylval.i); 
# line 1803 "yygrammar.c"
      } break;
   case 105: {
      get_lexval();
#line 412 "ass3.acc"
 escapeString(out, yylval.s); 
# line 1809 "yygrammar.c"
      } break;
   case 106: {
      get_lexval();
#line 413 "ass3.acc"
 fprintf(out, "$%f$", yylval.d); 
# line 1815 "yygrammar.c"
      } break;
   }
}

id ()
{
   switch(yyselect()) {
   case 107: {
      get_lexval();
#line 418 "ass3.acc"
 escapeString(out, yylval.s); 
# line 1827 "yygrammar.c"
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
int c_length = 1217;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 108,
/* 6 */ 0,
/* 7 */ 10,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 15,
/* 11 */ 18,
/* 12 */ 10,
/* 13 */ -10,
/* 14 */ 109,
/* 15 */ 0,
/* 16 */ -10,
/* 17 */ 219,
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
/* 36 */ 110,
/* 37 */ 0,
/* 38 */ -33,
/* 39 */ 220,
/* 40 */ 44,
/* 41 */ 68,
/* 42 */ -40,
/* 43 */ 111,
/* 44 */ 0,
/* 45 */ -40,
/* 46 */ 221,
/* 47 */ 51,
/* 48 */ 50059,
/* 49 */ -47,
/* 50 */ 112,
/* 51 */ 0,
/* 52 */ 683,
/* 53 */ -47,
/* 54 */ 113,
/* 55 */ 0,
/* 56 */ 81,
/* 57 */ 61,
/* 58 */ 50059,
/* 59 */ -55,
/* 60 */ 5,
/* 61 */ 65,
/* 62 */ 235,
/* 63 */ -61,
/* 64 */ 114,
/* 65 */ 0,
/* 66 */ -61,
/* 67 */ 222,
/* 68 */ 0,
/* 69 */ 55,
/* 70 */ 73,
/* 71 */ -68,
/* 72 */ 6,
/* 73 */ 78,
/* 74 */ 55,
/* 75 */ 73,
/* 76 */ -73,
/* 77 */ 115,
/* 78 */ 0,
/* 79 */ -73,
/* 80 */ 223,
/* 81 */ 0,
/* 82 */ 85,
/* 83 */ -81,
/* 84 */ 7,
/* 85 */ 90,
/* 86 */ 103,
/* 87 */ 85,
/* 88 */ -85,
/* 89 */ 116,
/* 90 */ 95,
/* 91 */ 127,
/* 92 */ 85,
/* 93 */ -85,
/* 94 */ 117,
/* 95 */ 100,
/* 96 */ 179,
/* 97 */ 85,
/* 98 */ -85,
/* 99 */ 118,
/* 100 */ 0,
/* 101 */ -85,
/* 102 */ 224,
/* 103 */ 0,
/* 104 */ 107,
/* 105 */ -103,
/* 106 */ 8,
/* 107 */ 111,
/* 108 */ 50256,
/* 109 */ -107,
/* 110 */ 119,
/* 111 */ 115,
/* 112 */ 50274,
/* 113 */ -107,
/* 114 */ 120,
/* 115 */ 119,
/* 116 */ 50279,
/* 117 */ -107,
/* 118 */ 121,
/* 119 */ 123,
/* 120 */ 50267,
/* 121 */ -107,
/* 122 */ 122,
/* 123 */ 0,
/* 124 */ 50282,
/* 125 */ -107,
/* 126 */ 123,
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
/* 140 */ 1214,
/* 141 */ -127,
/* 142 */ 12,
/* 143 */ 147,
/* 144 */ 50285,
/* 145 */ -143,
/* 146 */ 124,
/* 147 */ 151,
/* 148 */ 50259,
/* 149 */ -143,
/* 150 */ 125,
/* 151 */ 155,
/* 152 */ 50276,
/* 153 */ -143,
/* 154 */ 126,
/* 155 */ 159,
/* 156 */ 50272,
/* 157 */ -143,
/* 158 */ 127,
/* 159 */ 163,
/* 160 */ 50273,
/* 161 */ -143,
/* 162 */ 128,
/* 163 */ 167,
/* 164 */ 50268,
/* 165 */ -143,
/* 166 */ 129,
/* 167 */ 171,
/* 168 */ 50264,
/* 169 */ -143,
/* 170 */ 130,
/* 171 */ 175,
/* 172 */ 50277,
/* 173 */ -143,
/* 174 */ 131,
/* 175 */ 0,
/* 176 */ 50284,
/* 177 */ -143,
/* 178 */ 132,
/* 179 */ 0,
/* 180 */ 183,
/* 181 */ -179,
/* 182 */ 13,
/* 183 */ 187,
/* 184 */ 50260,
/* 185 */ -183,
/* 186 */ 133,
/* 187 */ 0,
/* 188 */ 50286,
/* 189 */ -183,
/* 190 */ 134,
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
/* 201 */ 1214,
/* 202 */ -191,
/* 203 */ 15,
/* 204 */ 208,
/* 205 */ 1214,
/* 206 */ -204,
/* 207 */ 135,
/* 208 */ 0,
/* 209 */ -204,
/* 210 */ 225,
/* 211 */ 0,
/* 212 */ 215,
/* 213 */ -211,
/* 214 */ 16,
/* 215 */ 219,
/* 216 */ 50280,
/* 217 */ -215,
/* 218 */ 136,
/* 219 */ 0,
/* 220 */ 50283,
/* 221 */ -215,
/* 222 */ 137,
/* 223 */ 0,
/* 224 */ 228,
/* 225 */ 261,
/* 226 */ -223,
/* 227 */ 17,
/* 228 */ 232,
/* 229 */ 223,
/* 230 */ -228,
/* 231 */ 138,
/* 232 */ 0,
/* 233 */ -228,
/* 234 */ 226,
/* 235 */ 0,
/* 236 */ 240,
/* 237 */ 248,
/* 238 */ -235,
/* 239 */ 18,
/* 240 */ 245,
/* 241 */ 235,
/* 242 */ 50044,
/* 243 */ -240,
/* 244 */ 139,
/* 245 */ 0,
/* 246 */ -240,
/* 247 */ 227,
/* 248 */ 0,
/* 249 */ 253,
/* 250 */ 513,
/* 251 */ -248,
/* 252 */ 19,
/* 253 */ 258,
/* 254 */ 363,
/* 255 */ 50061,
/* 256 */ -253,
/* 257 */ 140,
/* 258 */ 0,
/* 259 */ -253,
/* 260 */ 228,
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
/* 275 */ 141,
/* 276 */ 0,
/* 277 */ 179,
/* 278 */ -272,
/* 279 */ 142,
/* 280 */ 284,
/* 281 */ 267,
/* 282 */ -280,
/* 283 */ 143,
/* 284 */ 0,
/* 285 */ -280,
/* 286 */ 229,
/* 287 */ 0,
/* 288 */ 292,
/* 289 */ 300,
/* 290 */ -287,
/* 291 */ 22,
/* 292 */ 297,
/* 293 */ 287,
/* 294 */ 50044,
/* 295 */ -292,
/* 296 */ 144,
/* 297 */ 0,
/* 298 */ -292,
/* 299 */ 230,
/* 300 */ 304,
/* 301 */ 363,
/* 302 */ -300,
/* 303 */ 23,
/* 304 */ 0,
/* 305 */ 310,
/* 306 */ 50058,
/* 307 */ 890,
/* 308 */ -300,
/* 309 */ 24,
/* 310 */ 314,
/* 311 */ 363,
/* 312 */ -310,
/* 313 */ 145,
/* 314 */ 0,
/* 315 */ -310,
/* 316 */ 231,
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
/* 327 */ 1214,
/* 328 */ -317,
/* 329 */ 26,
/* 330 */ 334,
/* 331 */ 1214,
/* 332 */ -330,
/* 333 */ 146,
/* 334 */ 0,
/* 335 */ -330,
/* 336 */ 232,
/* 337 */ 0,
/* 338 */ 342,
/* 339 */ 350,
/* 340 */ -337,
/* 341 */ 27,
/* 342 */ 347,
/* 343 */ 337,
/* 344 */ 50044,
/* 345 */ -342,
/* 346 */ 147,
/* 347 */ 0,
/* 348 */ -342,
/* 349 */ 233,
/* 350 */ 0,
/* 351 */ 1214,
/* 352 */ 355,
/* 353 */ -350,
/* 354 */ 28,
/* 355 */ 360,
/* 356 */ 50061,
/* 357 */ 890,
/* 358 */ -355,
/* 359 */ 148,
/* 360 */ 0,
/* 361 */ -355,
/* 362 */ 234,
/* 363 */ 0,
/* 364 */ 368,
/* 365 */ 375,
/* 366 */ -363,
/* 367 */ 29,
/* 368 */ 372,
/* 369 */ 422,
/* 370 */ -368,
/* 371 */ 149,
/* 372 */ 0,
/* 373 */ -368,
/* 374 */ 235,
/* 375 */ 379,
/* 376 */ 1214,
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
/* 395 */ 151,
/* 396 */ 402,
/* 397 */ 50040,
/* 398 */ 454,
/* 399 */ 50041,
/* 400 */ -390,
/* 401 */ 152,
/* 402 */ 0,
/* 403 */ 50040,
/* 404 */ 415,
/* 405 */ 50041,
/* 406 */ -390,
/* 407 */ 154,
/* 408 */ 412,
/* 409 */ 844,
/* 410 */ -408,
/* 411 */ 150,
/* 412 */ 0,
/* 413 */ -408,
/* 414 */ 236,
/* 415 */ 419,
/* 416 */ 500,
/* 417 */ -415,
/* 418 */ 153,
/* 419 */ 0,
/* 420 */ -415,
/* 421 */ 237,
/* 422 */ 0,
/* 423 */ 50042,
/* 424 */ 428,
/* 425 */ 435,
/* 426 */ -422,
/* 427 */ 33,
/* 428 */ 432,
/* 429 */ 442,
/* 430 */ -428,
/* 431 */ 155,
/* 432 */ 0,
/* 433 */ -428,
/* 434 */ 238,
/* 435 */ 439,
/* 436 */ 422,
/* 437 */ -435,
/* 438 */ 156,
/* 439 */ 0,
/* 440 */ -435,
/* 441 */ 239,
/* 442 */ 0,
/* 443 */ 447,
/* 444 */ 179,
/* 445 */ -442,
/* 446 */ 34,
/* 447 */ 451,
/* 448 */ 442,
/* 449 */ -447,
/* 450 */ 157,
/* 451 */ 0,
/* 452 */ -447,
/* 453 */ 240,
/* 454 */ 0,
/* 455 */ 467,
/* 456 */ 459,
/* 457 */ -454,
/* 458 */ 35,
/* 459 */ 464,
/* 460 */ 50044,
/* 461 */ 50290,
/* 462 */ -459,
/* 463 */ 158,
/* 464 */ 0,
/* 465 */ -459,
/* 466 */ 241,
/* 467 */ 0,
/* 468 */ 472,
/* 469 */ 480,
/* 470 */ -467,
/* 471 */ 36,
/* 472 */ 477,
/* 473 */ 467,
/* 474 */ 50044,
/* 475 */ -472,
/* 476 */ 159,
/* 477 */ 0,
/* 478 */ -472,
/* 479 */ 242,
/* 480 */ 0,
/* 481 */ 81,
/* 482 */ 485,
/* 483 */ -480,
/* 484 */ 37,
/* 485 */ 489,
/* 486 */ 363,
/* 487 */ -485,
/* 488 */ 160,
/* 489 */ 0,
/* 490 */ 493,
/* 491 */ -485,
/* 492 */ 162,
/* 493 */ 497,
/* 494 */ 556,
/* 495 */ -493,
/* 496 */ 161,
/* 497 */ 0,
/* 498 */ -493,
/* 499 */ 243,
/* 500 */ 0,
/* 501 */ 505,
/* 502 */ 1214,
/* 503 */ -500,
/* 504 */ 38,
/* 505 */ 510,
/* 506 */ 500,
/* 507 */ 50044,
/* 508 */ -505,
/* 509 */ 163,
/* 510 */ 0,
/* 511 */ -505,
/* 512 */ 244,
/* 513 */ 517,
/* 514 */ 857,
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
/* 527 */ 164,
/* 528 */ 0,
/* 529 */ -524,
/* 530 */ 245,
/* 531 */ 0,
/* 532 */ 536,
/* 533 */ 513,
/* 534 */ -531,
/* 535 */ 41,
/* 536 */ 541,
/* 537 */ 531,
/* 538 */ 50044,
/* 539 */ -536,
/* 540 */ 165,
/* 541 */ 0,
/* 542 */ -536,
/* 543 */ 246,
/* 544 */ 0,
/* 545 */ 267,
/* 546 */ 549,
/* 547 */ -544,
/* 548 */ 42,
/* 549 */ 553,
/* 550 */ 556,
/* 551 */ -549,
/* 552 */ 166,
/* 553 */ 0,
/* 554 */ -549,
/* 555 */ 247,
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
/* 568 */ 167,
/* 569 */ 0,
/* 570 */ -565,
/* 571 */ 248,
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
/* 586 */ 168,
/* 587 */ 0,
/* 588 */ -583,
/* 589 */ 249,
/* 590 */ 596,
/* 591 */ 50091,
/* 592 */ 602,
/* 593 */ 50093,
/* 594 */ -590,
/* 595 */ 170,
/* 596 */ 0,
/* 597 */ 50040,
/* 598 */ 609,
/* 599 */ 50041,
/* 600 */ -590,
/* 601 */ 172,
/* 602 */ 606,
/* 603 */ 844,
/* 604 */ -602,
/* 605 */ 169,
/* 606 */ 0,
/* 607 */ -602,
/* 608 */ 250,
/* 609 */ 613,
/* 610 */ 454,
/* 611 */ -609,
/* 612 */ 171,
/* 613 */ 0,
/* 614 */ -609,
/* 615 */ 251,
/* 616 */ 0,
/* 617 */ 1214,
/* 618 */ -616,
/* 619 */ 47,
/* 620 */ 624,
/* 621 */ 652,
/* 622 */ -620,
/* 623 */ 48,
/* 624 */ 628,
/* 625 */ 671,
/* 626 */ -620,
/* 627 */ 49,
/* 628 */ 632,
/* 629 */ 683,
/* 630 */ -620,
/* 631 */ 50,
/* 632 */ 636,
/* 633 */ 717,
/* 634 */ -620,
/* 635 */ 51,
/* 636 */ 640,
/* 637 */ 742,
/* 638 */ -620,
/* 639 */ 52,
/* 640 */ 644,
/* 641 */ 793,
/* 642 */ -620,
/* 643 */ 53,
/* 644 */ 648,
/* 645 */ 822,
/* 646 */ -620,
/* 647 */ 54,
/* 648 */ 0,
/* 649 */ 828,
/* 650 */ -620,
/* 651 */ 55,
/* 652 */ 658,
/* 653 */ 1214,
/* 654 */ 50058,
/* 655 */ 620,
/* 656 */ -652,
/* 657 */ 56,
/* 658 */ 665,
/* 659 */ 50258,
/* 660 */ 890,
/* 661 */ 50058,
/* 662 */ 620,
/* 663 */ -652,
/* 664 */ 57,
/* 665 */ 0,
/* 666 */ 50262,
/* 667 */ 50058,
/* 668 */ 620,
/* 669 */ -652,
/* 670 */ 58,
/* 671 */ 0,
/* 672 */ 676,
/* 673 */ 50059,
/* 674 */ -671,
/* 675 */ 59,
/* 676 */ 680,
/* 677 */ 844,
/* 678 */ -676,
/* 679 */ 173,
/* 680 */ 0,
/* 681 */ -676,
/* 682 */ 252,
/* 683 */ 0,
/* 684 */ 50123,
/* 685 */ 690,
/* 686 */ 697,
/* 687 */ 50125,
/* 688 */ -683,
/* 689 */ 60,
/* 690 */ 694,
/* 691 */ 68,
/* 692 */ -690,
/* 693 */ 174,
/* 694 */ 0,
/* 695 */ -690,
/* 696 */ 253,
/* 697 */ 701,
/* 698 */ 704,
/* 699 */ -697,
/* 700 */ 175,
/* 701 */ 0,
/* 702 */ -697,
/* 703 */ 254,
/* 704 */ 0,
/* 705 */ 709,
/* 706 */ 620,
/* 707 */ -704,
/* 708 */ 61,
/* 709 */ 714,
/* 710 */ 620,
/* 711 */ 709,
/* 712 */ -709,
/* 713 */ 176,
/* 714 */ 0,
/* 715 */ -709,
/* 716 */ 255,
/* 717 */ 726,
/* 718 */ 50271,
/* 719 */ 50040,
/* 720 */ 844,
/* 721 */ 50041,
/* 722 */ 620,
/* 723 */ 734,
/* 724 */ -717,
/* 725 */ 62,
/* 726 */ 0,
/* 727 */ 50281,
/* 728 */ 50040,
/* 729 */ 844,
/* 730 */ 50041,
/* 731 */ 620,
/* 732 */ -717,
/* 733 */ 63,
/* 734 */ 739,
/* 735 */ 50265,
/* 736 */ 620,
/* 737 */ -734,
/* 738 */ 177,
/* 739 */ 0,
/* 740 */ -734,
/* 741 */ 256,
/* 742 */ 750,
/* 743 */ 50287,
/* 744 */ 50040,
/* 745 */ 844,
/* 746 */ 50041,
/* 747 */ 620,
/* 748 */ -742,
/* 749 */ 64,
/* 750 */ 760,
/* 751 */ 50263,
/* 752 */ 620,
/* 753 */ 50287,
/* 754 */ 50040,
/* 755 */ 844,
/* 756 */ 50041,
/* 757 */ 50059,
/* 758 */ -742,
/* 759 */ 65,
/* 760 */ 0,
/* 761 */ 50269,
/* 762 */ 50040,
/* 763 */ 772,
/* 764 */ 50059,
/* 765 */ 779,
/* 766 */ 50059,
/* 767 */ 786,
/* 768 */ 50041,
/* 769 */ 620,
/* 770 */ -742,
/* 771 */ 66,
/* 772 */ 776,
/* 773 */ 844,
/* 774 */ -772,
/* 775 */ 178,
/* 776 */ 0,
/* 777 */ -772,
/* 778 */ 257,
/* 779 */ 783,
/* 780 */ 844,
/* 781 */ -779,
/* 782 */ 179,
/* 783 */ 0,
/* 784 */ -779,
/* 785 */ 258,
/* 786 */ 790,
/* 787 */ 844,
/* 788 */ -786,
/* 789 */ 180,
/* 790 */ 0,
/* 791 */ -786,
/* 792 */ 259,
/* 793 */ 799,
/* 794 */ 50270,
/* 795 */ 1214,
/* 796 */ 50059,
/* 797 */ -793,
/* 798 */ 67,
/* 799 */ 804,
/* 800 */ 50261,
/* 801 */ 50059,
/* 802 */ -793,
/* 803 */ 68,
/* 804 */ 809,
/* 805 */ 50257,
/* 806 */ 50059,
/* 807 */ -793,
/* 808 */ 69,
/* 809 */ 0,
/* 810 */ 50275,
/* 811 */ 815,
/* 812 */ 50059,
/* 813 */ -793,
/* 814 */ 70,
/* 815 */ 819,
/* 816 */ 844,
/* 817 */ -815,
/* 818 */ 181,
/* 819 */ 0,
/* 820 */ -815,
/* 821 */ 260,
/* 822 */ 0,
/* 823 */ 50309,
/* 824 */ 1189,
/* 825 */ 50059,
/* 826 */ -822,
/* 827 */ 71,
/* 828 */ 0,
/* 829 */ 50310,
/* 830 */ 835,
/* 831 */ 1214,
/* 832 */ 50059,
/* 833 */ -828,
/* 834 */ 72,
/* 835 */ 841,
/* 836 */ 1214,
/* 837 */ 50044,
/* 838 */ 835,
/* 839 */ -835,
/* 840 */ 182,
/* 841 */ 0,
/* 842 */ -835,
/* 843 */ 261,
/* 844 */ 0,
/* 845 */ 849,
/* 846 */ 857,
/* 847 */ -844,
/* 848 */ 73,
/* 849 */ 854,
/* 850 */ 844,
/* 851 */ 50044,
/* 852 */ -849,
/* 853 */ 183,
/* 854 */ 0,
/* 855 */ -849,
/* 856 */ 262,
/* 857 */ 861,
/* 858 */ 875,
/* 859 */ -857,
/* 860 */ 74,
/* 861 */ 0,
/* 862 */ 1042,
/* 863 */ 867,
/* 864 */ 857,
/* 865 */ -857,
/* 866 */ 75,
/* 867 */ 871,
/* 868 */ 50291,
/* 869 */ -867,
/* 870 */ 76,
/* 871 */ 0,
/* 872 */ 50061,
/* 873 */ -867,
/* 874 */ 77,
/* 875 */ 0,
/* 876 */ 894,
/* 877 */ 880,
/* 878 */ -875,
/* 879 */ 78,
/* 880 */ 887,
/* 881 */ 50063,
/* 882 */ 844,
/* 883 */ 50058,
/* 884 */ 875,
/* 885 */ -880,
/* 886 */ 184,
/* 887 */ 0,
/* 888 */ -880,
/* 889 */ 263,
/* 890 */ 0,
/* 891 */ 875,
/* 892 */ -890,
/* 893 */ 79,
/* 894 */ 0,
/* 895 */ 899,
/* 896 */ 907,
/* 897 */ -894,
/* 898 */ 80,
/* 899 */ 904,
/* 900 */ 894,
/* 901 */ 50297,
/* 902 */ -899,
/* 903 */ 185,
/* 904 */ 0,
/* 905 */ -899,
/* 906 */ 264,
/* 907 */ 0,
/* 908 */ 912,
/* 909 */ 920,
/* 910 */ -907,
/* 911 */ 81,
/* 912 */ 917,
/* 913 */ 907,
/* 914 */ 50298,
/* 915 */ -912,
/* 916 */ 186,
/* 917 */ 0,
/* 918 */ -912,
/* 919 */ 265,
/* 920 */ 0,
/* 921 */ 925,
/* 922 */ 933,
/* 923 */ -920,
/* 924 */ 82,
/* 925 */ 930,
/* 926 */ 920,
/* 927 */ 50300,
/* 928 */ -925,
/* 929 */ 187,
/* 930 */ 0,
/* 931 */ -925,
/* 932 */ 266,
/* 933 */ 0,
/* 934 */ 938,
/* 935 */ 946,
/* 936 */ -933,
/* 937 */ 83,
/* 938 */ 943,
/* 939 */ 933,
/* 940 */ 50302,
/* 941 */ -938,
/* 942 */ 188,
/* 943 */ 0,
/* 944 */ -938,
/* 945 */ 267,
/* 946 */ 0,
/* 947 */ 951,
/* 948 */ 959,
/* 949 */ -946,
/* 950 */ 84,
/* 951 */ 956,
/* 952 */ 946,
/* 953 */ 50301,
/* 954 */ -951,
/* 955 */ 189,
/* 956 */ 0,
/* 957 */ -951,
/* 958 */ 268,
/* 959 */ 0,
/* 960 */ 964,
/* 961 */ 972,
/* 962 */ -959,
/* 963 */ 85,
/* 964 */ 969,
/* 965 */ 959,
/* 966 */ 50292,
/* 967 */ -964,
/* 968 */ 190,
/* 969 */ 0,
/* 970 */ -964,
/* 971 */ 269,
/* 972 */ 0,
/* 973 */ 977,
/* 974 */ 985,
/* 975 */ -972,
/* 976 */ 86,
/* 977 */ 982,
/* 978 */ 972,
/* 979 */ 50304,
/* 980 */ -977,
/* 981 */ 191,
/* 982 */ 0,
/* 983 */ -977,
/* 984 */ 270,
/* 985 */ 0,
/* 986 */ 990,
/* 987 */ 1006,
/* 988 */ -985,
/* 989 */ 87,
/* 990 */ 995,
/* 991 */ 985,
/* 992 */ 998,
/* 993 */ -990,
/* 994 */ 194,
/* 995 */ 0,
/* 996 */ -990,
/* 997 */ 271,
/* 998 */ 1002,
/* 999 */ 50043,
/* 1000 */ -998,
/* 1001 */ 192,
/* 1002 */ 0,
/* 1003 */ 50045,
/* 1004 */ -998,
/* 1005 */ 193,
/* 1006 */ 0,
/* 1007 */ 1011,
/* 1008 */ 1031,
/* 1009 */ -1006,
/* 1010 */ 88,
/* 1011 */ 1016,
/* 1012 */ 1006,
/* 1013 */ 1019,
/* 1014 */ -1011,
/* 1015 */ 198,
/* 1016 */ 0,
/* 1017 */ -1011,
/* 1018 */ 272,
/* 1019 */ 1023,
/* 1020 */ 50042,
/* 1021 */ -1019,
/* 1022 */ 195,
/* 1023 */ 1027,
/* 1024 */ 50047,
/* 1025 */ -1019,
/* 1026 */ 196,
/* 1027 */ 0,
/* 1028 */ 50037,
/* 1029 */ -1019,
/* 1030 */ 197,
/* 1031 */ 1035,
/* 1032 */ 1042,
/* 1033 */ -1031,
/* 1034 */ 89,
/* 1035 */ 0,
/* 1036 */ 50040,
/* 1037 */ 544,
/* 1038 */ 50041,
/* 1039 */ 1031,
/* 1040 */ -1031,
/* 1041 */ 90,
/* 1042 */ 1046,
/* 1043 */ 1116,
/* 1044 */ -1042,
/* 1045 */ 91,
/* 1046 */ 1051,
/* 1047 */ 1068,
/* 1048 */ 1042,
/* 1049 */ -1042,
/* 1050 */ 92,
/* 1051 */ 1056,
/* 1052 */ 1076,
/* 1053 */ 1031,
/* 1054 */ -1042,
/* 1055 */ 93,
/* 1056 */ 1061,
/* 1057 */ 50278,
/* 1058 */ 1042,
/* 1059 */ -1042,
/* 1060 */ 94,
/* 1061 */ 0,
/* 1062 */ 50278,
/* 1063 */ 50040,
/* 1064 */ 544,
/* 1065 */ 50041,
/* 1066 */ -1042,
/* 1067 */ 95,
/* 1068 */ 1072,
/* 1069 */ 50294,
/* 1070 */ -1068,
/* 1071 */ 199,
/* 1072 */ 0,
/* 1073 */ 50295,
/* 1074 */ -1068,
/* 1075 */ 200,
/* 1076 */ 0,
/* 1077 */ 1080,
/* 1078 */ -1076,
/* 1079 */ 96,
/* 1080 */ 1084,
/* 1081 */ 50301,
/* 1082 */ -1080,
/* 1083 */ 201,
/* 1084 */ 1088,
/* 1085 */ 50042,
/* 1086 */ -1080,
/* 1087 */ 202,
/* 1088 */ 1092,
/* 1089 */ 50043,
/* 1090 */ -1080,
/* 1091 */ 203,
/* 1092 */ 1096,
/* 1093 */ 50045,
/* 1094 */ -1080,
/* 1095 */ 204,
/* 1096 */ 1100,
/* 1097 */ 50126,
/* 1098 */ -1080,
/* 1099 */ 205,
/* 1100 */ 1104,
/* 1101 */ 50033,
/* 1102 */ -1080,
/* 1103 */ 206,
/* 1104 */ 1108,
/* 1105 */ 50303,
/* 1106 */ -1080,
/* 1107 */ 207,
/* 1108 */ 1112,
/* 1109 */ 50300,
/* 1110 */ -1080,
/* 1111 */ 208,
/* 1112 */ 0,
/* 1113 */ 50302,
/* 1114 */ -1080,
/* 1115 */ 209,
/* 1116 */ 1120,
/* 1117 */ 1171,
/* 1118 */ -1116,
/* 1119 */ 97,
/* 1120 */ 0,
/* 1121 */ 1116,
/* 1122 */ 1125,
/* 1123 */ -1116,
/* 1124 */ 98,
/* 1125 */ 1132,
/* 1126 */ 50091,
/* 1127 */ 844,
/* 1128 */ 1156,
/* 1129 */ 50093,
/* 1130 */ -1125,
/* 1131 */ 211,
/* 1132 */ 1138,
/* 1133 */ 50040,
/* 1134 */ 1164,
/* 1135 */ 50041,
/* 1136 */ -1125,
/* 1137 */ 213,
/* 1138 */ 1143,
/* 1139 */ 50046,
/* 1140 */ 1214,
/* 1141 */ -1125,
/* 1142 */ 214,
/* 1143 */ 1148,
/* 1144 */ 50296,
/* 1145 */ 1214,
/* 1146 */ -1125,
/* 1147 */ 215,
/* 1148 */ 1152,
/* 1149 */ 50294,
/* 1150 */ -1125,
/* 1151 */ 216,
/* 1152 */ 0,
/* 1153 */ 50295,
/* 1154 */ -1125,
/* 1155 */ 217,
/* 1156 */ 1161,
/* 1157 */ 50058,
/* 1158 */ 844,
/* 1159 */ -1156,
/* 1160 */ 210,
/* 1161 */ 0,
/* 1162 */ -1156,
/* 1163 */ 273,
/* 1164 */ 1168,
/* 1165 */ 1189,
/* 1166 */ -1164,
/* 1167 */ 212,
/* 1168 */ 0,
/* 1169 */ -1164,
/* 1170 */ 274,
/* 1171 */ 1175,
/* 1172 */ 1214,
/* 1173 */ -1171,
/* 1174 */ 99,
/* 1175 */ 1179,
/* 1176 */ 1202,
/* 1177 */ -1171,
/* 1178 */ 100,
/* 1179 */ 1183,
/* 1180 */ 50289,
/* 1181 */ -1171,
/* 1182 */ 101,
/* 1183 */ 0,
/* 1184 */ 50040,
/* 1185 */ 844,
/* 1186 */ 50041,
/* 1187 */ -1171,
/* 1188 */ 102,
/* 1189 */ 0,
/* 1190 */ 1194,
/* 1191 */ 857,
/* 1192 */ -1189,
/* 1193 */ 103,
/* 1194 */ 1199,
/* 1195 */ 1189,
/* 1196 */ 50044,
/* 1197 */ -1194,
/* 1198 */ 218,
/* 1199 */ 0,
/* 1200 */ -1194,
/* 1201 */ 275,
/* 1202 */ 1206,
/* 1203 */ 50308,
/* 1204 */ -1202,
/* 1205 */ 104,
/* 1206 */ 1210,
/* 1207 */ 50306,
/* 1208 */ -1202,
/* 1209 */ 105,
/* 1210 */ 0,
/* 1211 */ 50307,
/* 1212 */ -1202,
/* 1213 */ 106,
/* 1214 */ 0,
/* 1215 */ 50299,
/* 1216 */ -1214,
/* 1217 */ 107,
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
/* 640 */ 644,
/* 641 */ 1,
/* 642 */ -620,
/* 643 */ 6,
/* 644 */ 648,
/* 645 */ 1,
/* 646 */ -620,
/* 647 */ 7,
/* 648 */ 0,
/* 649 */ 1,
/* 650 */ -620,
/* 651 */ 8,
/* 652 */ 658,
/* 653 */ 1,
/* 654 */ 50058,
/* 655 */ 1,
/* 656 */ -652,
/* 657 */ 1,
/* 658 */ 665,
/* 659 */ 50258,
/* 660 */ 1,
/* 661 */ 50058,
/* 662 */ 1,
/* 663 */ -652,
/* 664 */ 2,
/* 665 */ 0,
/* 666 */ 50262,
/* 667 */ 50058,
/* 668 */ 1,
/* 669 */ -652,
/* 670 */ 3,
/* 671 */ 0,
/* 672 */ 1,
/* 673 */ 50059,
/* 674 */ -671,
/* 675 */ 1,
/* 676 */ 680,
/* 677 */ 1,
/* 678 */ -676,
/* 679 */ 1,
/* 680 */ 0,
/* 681 */ -676,
/* 682 */ 2,
/* 683 */ 0,
/* 684 */ 50123,
/* 685 */ 1,
/* 686 */ 1,
/* 687 */ 50125,
/* 688 */ -683,
/* 689 */ 1,
/* 690 */ 694,
/* 691 */ 1,
/* 692 */ -690,
/* 693 */ 1,
/* 694 */ 0,
/* 695 */ -690,
/* 696 */ 2,
/* 697 */ 701,
/* 698 */ 1,
/* 699 */ -697,
/* 700 */ 1,
/* 701 */ 0,
/* 702 */ -697,
/* 703 */ 2,
/* 704 */ 0,
/* 705 */ 1,
/* 706 */ 1,
/* 707 */ -704,
/* 708 */ 1,
/* 709 */ 714,
/* 710 */ 1,
/* 711 */ 1,
/* 712 */ -709,
/* 713 */ 1,
/* 714 */ 0,
/* 715 */ -709,
/* 716 */ 2,
/* 717 */ 726,
/* 718 */ 50271,
/* 719 */ 50040,
/* 720 */ 1,
/* 721 */ 50041,
/* 722 */ 1,
/* 723 */ 1,
/* 724 */ -717,
/* 725 */ 1,
/* 726 */ 0,
/* 727 */ 50281,
/* 728 */ 50040,
/* 729 */ 1,
/* 730 */ 50041,
/* 731 */ 1,
/* 732 */ -717,
/* 733 */ 2,
/* 734 */ 739,
/* 735 */ 50265,
/* 736 */ 1,
/* 737 */ -734,
/* 738 */ 1,
/* 739 */ 0,
/* 740 */ -734,
/* 741 */ 2,
/* 742 */ 750,
/* 743 */ 50287,
/* 744 */ 50040,
/* 745 */ 1,
/* 746 */ 50041,
/* 747 */ 1,
/* 748 */ -742,
/* 749 */ 1,
/* 750 */ 760,
/* 751 */ 50263,
/* 752 */ 1,
/* 753 */ 50287,
/* 754 */ 50040,
/* 755 */ 1,
/* 756 */ 50041,
/* 757 */ 50059,
/* 758 */ -742,
/* 759 */ 2,
/* 760 */ 0,
/* 761 */ 50269,
/* 762 */ 50040,
/* 763 */ 1,
/* 764 */ 50059,
/* 765 */ 1,
/* 766 */ 50059,
/* 767 */ 1,
/* 768 */ 50041,
/* 769 */ 1,
/* 770 */ -742,
/* 771 */ 3,
/* 772 */ 776,
/* 773 */ 1,
/* 774 */ -772,
/* 775 */ 1,
/* 776 */ 0,
/* 777 */ -772,
/* 778 */ 2,
/* 779 */ 783,
/* 780 */ 1,
/* 781 */ -779,
/* 782 */ 1,
/* 783 */ 0,
/* 784 */ -779,
/* 785 */ 2,
/* 786 */ 790,
/* 787 */ 1,
/* 788 */ -786,
/* 789 */ 1,
/* 790 */ 0,
/* 791 */ -786,
/* 792 */ 2,
/* 793 */ 799,
/* 794 */ 50270,
/* 795 */ 1,
/* 796 */ 50059,
/* 797 */ -793,
/* 798 */ 1,
/* 799 */ 804,
/* 800 */ 50261,
/* 801 */ 50059,
/* 802 */ -793,
/* 803 */ 2,
/* 804 */ 809,
/* 805 */ 50257,
/* 806 */ 50059,
/* 807 */ -793,
/* 808 */ 3,
/* 809 */ 0,
/* 810 */ 50275,
/* 811 */ 1,
/* 812 */ 50059,
/* 813 */ -793,
/* 814 */ 4,
/* 815 */ 819,
/* 816 */ 1,
/* 817 */ -815,
/* 818 */ 1,
/* 819 */ 0,
/* 820 */ -815,
/* 821 */ 2,
/* 822 */ 0,
/* 823 */ 50309,
/* 824 */ 1,
/* 825 */ 50059,
/* 826 */ -822,
/* 827 */ 1,
/* 828 */ 0,
/* 829 */ 50310,
/* 830 */ 1,
/* 831 */ 1,
/* 832 */ 50059,
/* 833 */ -828,
/* 834 */ 1,
/* 835 */ 841,
/* 836 */ 1,
/* 837 */ 50044,
/* 838 */ 1,
/* 839 */ -835,
/* 840 */ 1,
/* 841 */ 0,
/* 842 */ -835,
/* 843 */ 2,
/* 844 */ 0,
/* 845 */ 1,
/* 846 */ 1,
/* 847 */ -844,
/* 848 */ 1,
/* 849 */ 854,
/* 850 */ 1,
/* 851 */ 50044,
/* 852 */ -849,
/* 853 */ 1,
/* 854 */ 0,
/* 855 */ -849,
/* 856 */ 2,
/* 857 */ 861,
/* 858 */ 1,
/* 859 */ -857,
/* 860 */ 1,
/* 861 */ 0,
/* 862 */ 1,
/* 863 */ 1,
/* 864 */ 1,
/* 865 */ -857,
/* 866 */ 2,
/* 867 */ 871,
/* 868 */ 50291,
/* 869 */ -867,
/* 870 */ 1,
/* 871 */ 0,
/* 872 */ 50061,
/* 873 */ -867,
/* 874 */ 2,
/* 875 */ 0,
/* 876 */ 1,
/* 877 */ 1,
/* 878 */ -875,
/* 879 */ 1,
/* 880 */ 887,
/* 881 */ 50063,
/* 882 */ 1,
/* 883 */ 50058,
/* 884 */ 1,
/* 885 */ -880,
/* 886 */ 1,
/* 887 */ 0,
/* 888 */ -880,
/* 889 */ 2,
/* 890 */ 0,
/* 891 */ 1,
/* 892 */ -890,
/* 893 */ 1,
/* 894 */ 0,
/* 895 */ 1,
/* 896 */ 1,
/* 897 */ -894,
/* 898 */ 1,
/* 899 */ 904,
/* 900 */ 1,
/* 901 */ 50297,
/* 902 */ -899,
/* 903 */ 1,
/* 904 */ 0,
/* 905 */ -899,
/* 906 */ 2,
/* 907 */ 0,
/* 908 */ 1,
/* 909 */ 1,
/* 910 */ -907,
/* 911 */ 1,
/* 912 */ 917,
/* 913 */ 1,
/* 914 */ 50298,
/* 915 */ -912,
/* 916 */ 1,
/* 917 */ 0,
/* 918 */ -912,
/* 919 */ 2,
/* 920 */ 0,
/* 921 */ 1,
/* 922 */ 1,
/* 923 */ -920,
/* 924 */ 1,
/* 925 */ 930,
/* 926 */ 1,
/* 927 */ 50300,
/* 928 */ -925,
/* 929 */ 1,
/* 930 */ 0,
/* 931 */ -925,
/* 932 */ 2,
/* 933 */ 0,
/* 934 */ 1,
/* 935 */ 1,
/* 936 */ -933,
/* 937 */ 1,
/* 938 */ 943,
/* 939 */ 1,
/* 940 */ 50302,
/* 941 */ -938,
/* 942 */ 1,
/* 943 */ 0,
/* 944 */ -938,
/* 945 */ 2,
/* 946 */ 0,
/* 947 */ 1,
/* 948 */ 1,
/* 949 */ -946,
/* 950 */ 1,
/* 951 */ 956,
/* 952 */ 1,
/* 953 */ 50301,
/* 954 */ -951,
/* 955 */ 1,
/* 956 */ 0,
/* 957 */ -951,
/* 958 */ 2,
/* 959 */ 0,
/* 960 */ 1,
/* 961 */ 1,
/* 962 */ -959,
/* 963 */ 1,
/* 964 */ 969,
/* 965 */ 1,
/* 966 */ 50292,
/* 967 */ -964,
/* 968 */ 1,
/* 969 */ 0,
/* 970 */ -964,
/* 971 */ 2,
/* 972 */ 0,
/* 973 */ 1,
/* 974 */ 1,
/* 975 */ -972,
/* 976 */ 1,
/* 977 */ 982,
/* 978 */ 1,
/* 979 */ 50304,
/* 980 */ -977,
/* 981 */ 1,
/* 982 */ 0,
/* 983 */ -977,
/* 984 */ 2,
/* 985 */ 0,
/* 986 */ 1,
/* 987 */ 1,
/* 988 */ -985,
/* 989 */ 1,
/* 990 */ 995,
/* 991 */ 1,
/* 992 */ 1,
/* 993 */ -990,
/* 994 */ 1,
/* 995 */ 0,
/* 996 */ -990,
/* 997 */ 2,
/* 998 */ 1002,
/* 999 */ 50043,
/* 1000 */ -998,
/* 1001 */ 1,
/* 1002 */ 0,
/* 1003 */ 50045,
/* 1004 */ -998,
/* 1005 */ 2,
/* 1006 */ 0,
/* 1007 */ 1,
/* 1008 */ 1,
/* 1009 */ -1006,
/* 1010 */ 1,
/* 1011 */ 1016,
/* 1012 */ 1,
/* 1013 */ 1,
/* 1014 */ -1011,
/* 1015 */ 1,
/* 1016 */ 0,
/* 1017 */ -1011,
/* 1018 */ 2,
/* 1019 */ 1023,
/* 1020 */ 50042,
/* 1021 */ -1019,
/* 1022 */ 1,
/* 1023 */ 1027,
/* 1024 */ 50047,
/* 1025 */ -1019,
/* 1026 */ 2,
/* 1027 */ 0,
/* 1028 */ 50037,
/* 1029 */ -1019,
/* 1030 */ 3,
/* 1031 */ 1035,
/* 1032 */ 1,
/* 1033 */ -1031,
/* 1034 */ 1,
/* 1035 */ 0,
/* 1036 */ 50040,
/* 1037 */ 1,
/* 1038 */ 50041,
/* 1039 */ 1,
/* 1040 */ -1031,
/* 1041 */ 2,
/* 1042 */ 1046,
/* 1043 */ 1,
/* 1044 */ -1042,
/* 1045 */ 1,
/* 1046 */ 1051,
/* 1047 */ 1,
/* 1048 */ 1,
/* 1049 */ -1042,
/* 1050 */ 2,
/* 1051 */ 1056,
/* 1052 */ 1,
/* 1053 */ 1,
/* 1054 */ -1042,
/* 1055 */ 3,
/* 1056 */ 1061,
/* 1057 */ 50278,
/* 1058 */ 1,
/* 1059 */ -1042,
/* 1060 */ 4,
/* 1061 */ 0,
/* 1062 */ 50278,
/* 1063 */ 50040,
/* 1064 */ 1,
/* 1065 */ 50041,
/* 1066 */ -1042,
/* 1067 */ 5,
/* 1068 */ 1072,
/* 1069 */ 50294,
/* 1070 */ -1068,
/* 1071 */ 1,
/* 1072 */ 0,
/* 1073 */ 50295,
/* 1074 */ -1068,
/* 1075 */ 2,
/* 1076 */ 0,
/* 1077 */ 1,
/* 1078 */ -1076,
/* 1079 */ 1,
/* 1080 */ 1084,
/* 1081 */ 50301,
/* 1082 */ -1080,
/* 1083 */ 1,
/* 1084 */ 1088,
/* 1085 */ 50042,
/* 1086 */ -1080,
/* 1087 */ 2,
/* 1088 */ 1092,
/* 1089 */ 50043,
/* 1090 */ -1080,
/* 1091 */ 3,
/* 1092 */ 1096,
/* 1093 */ 50045,
/* 1094 */ -1080,
/* 1095 */ 4,
/* 1096 */ 1100,
/* 1097 */ 50126,
/* 1098 */ -1080,
/* 1099 */ 5,
/* 1100 */ 1104,
/* 1101 */ 50033,
/* 1102 */ -1080,
/* 1103 */ 6,
/* 1104 */ 1108,
/* 1105 */ 50303,
/* 1106 */ -1080,
/* 1107 */ 7,
/* 1108 */ 1112,
/* 1109 */ 50300,
/* 1110 */ -1080,
/* 1111 */ 8,
/* 1112 */ 0,
/* 1113 */ 50302,
/* 1114 */ -1080,
/* 1115 */ 9,
/* 1116 */ 1120,
/* 1117 */ 1,
/* 1118 */ -1116,
/* 1119 */ 1,
/* 1120 */ 0,
/* 1121 */ 1,
/* 1122 */ 1,
/* 1123 */ -1116,
/* 1124 */ 2,
/* 1125 */ 1132,
/* 1126 */ 50091,
/* 1127 */ 1,
/* 1128 */ 1,
/* 1129 */ 50093,
/* 1130 */ -1125,
/* 1131 */ 1,
/* 1132 */ 1138,
/* 1133 */ 50040,
/* 1134 */ 1,
/* 1135 */ 50041,
/* 1136 */ -1125,
/* 1137 */ 2,
/* 1138 */ 1143,
/* 1139 */ 50046,
/* 1140 */ 1,
/* 1141 */ -1125,
/* 1142 */ 3,
/* 1143 */ 1148,
/* 1144 */ 50296,
/* 1145 */ 1,
/* 1146 */ -1125,
/* 1147 */ 4,
/* 1148 */ 1152,
/* 1149 */ 50294,
/* 1150 */ -1125,
/* 1151 */ 5,
/* 1152 */ 0,
/* 1153 */ 50295,
/* 1154 */ -1125,
/* 1155 */ 6,
/* 1156 */ 1161,
/* 1157 */ 50058,
/* 1158 */ 1,
/* 1159 */ -1156,
/* 1160 */ 1,
/* 1161 */ 0,
/* 1162 */ -1156,
/* 1163 */ 2,
/* 1164 */ 1168,
/* 1165 */ 1,
/* 1166 */ -1164,
/* 1167 */ 1,
/* 1168 */ 0,
/* 1169 */ -1164,
/* 1170 */ 2,
/* 1171 */ 1175,
/* 1172 */ 1,
/* 1173 */ -1171,
/* 1174 */ 1,
/* 1175 */ 1179,
/* 1176 */ 1,
/* 1177 */ -1171,
/* 1178 */ 2,
/* 1179 */ 1183,
/* 1180 */ 50289,
/* 1181 */ -1171,
/* 1182 */ 3,
/* 1183 */ 0,
/* 1184 */ 50040,
/* 1185 */ 1,
/* 1186 */ 50041,
/* 1187 */ -1171,
/* 1188 */ 4,
/* 1189 */ 0,
/* 1190 */ 1,
/* 1191 */ 1,
/* 1192 */ -1189,
/* 1193 */ 1,
/* 1194 */ 1199,
/* 1195 */ 1,
/* 1196 */ 50044,
/* 1197 */ -1194,
/* 1198 */ 1,
/* 1199 */ 0,
/* 1200 */ -1194,
/* 1201 */ 2,
/* 1202 */ 1206,
/* 1203 */ 50308,
/* 1204 */ -1202,
/* 1205 */ 1,
/* 1206 */ 1210,
/* 1207 */ 50306,
/* 1208 */ -1202,
/* 1209 */ 2,
/* 1210 */ 0,
/* 1211 */ 50307,
/* 1212 */ -1202,
/* 1213 */ 3,
/* 1214 */ 0,
/* 1215 */ 50299,
/* 1216 */ -1214,
/* 1217 */ 1,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 87002,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 87002,
/* 6 */ 9999,
/* 7 */ 87004,
/* 8 */ 9999,
/* 9 */ 87004,
/* 10 */ 9999,
/* 11 */ 87006,
/* 12 */ 87025,
/* 13 */ 9999,
/* 14 */ 87025,
/* 15 */ 9999,
/* 16 */ 9999,
/* 17 */ 87025,
/* 18 */ 9999,
/* 19 */ 91004,
/* 20 */ 9999,
/* 21 */ 91022,
/* 22 */ 9999,
/* 23 */ 92004,
/* 24 */ 9999,
/* 25 */ 92014,
/* 26 */ 9999,
/* 27 */ 96004,
/* 28 */ 96032,
/* 29 */ 96043,
/* 30 */ 96065,
/* 31 */ 9999,
/* 32 */ 96004,
/* 33 */ 9999,
/* 34 */ 96006,
/* 35 */ 9999,
/* 36 */ 96027,
/* 37 */ 9999,
/* 38 */ 9999,
/* 39 */ 96027,
/* 40 */ 9999,
/* 41 */ 96045,
/* 42 */ 9999,
/* 43 */ 96060,
/* 44 */ 9999,
/* 45 */ 9999,
/* 46 */ 96060,
/* 47 */ 9999,
/* 48 */ 9999,
/* 49 */ 9999,
/* 50 */ 96067,
/* 51 */ 9999,
/* 52 */ 96102,
/* 53 */ 9999,
/* 54 */ 96119,
/* 55 */ 9999,
/* 56 */ 100004,
/* 57 */ 100027,
/* 58 */ 9999,
/* 59 */ 9999,
/* 60 */ 100025,
/* 61 */ 9999,
/* 62 */ 100029,
/* 63 */ 9999,
/* 64 */ 100048,
/* 65 */ 9999,
/* 66 */ 9999,
/* 67 */ 100048,
/* 68 */ 9999,
/* 69 */ 104004,
/* 70 */ 104016,
/* 71 */ 9999,
/* 72 */ 104014,
/* 73 */ 9999,
/* 74 */ 104018,
/* 75 */ 104028,
/* 76 */ 9999,
/* 77 */ 104028,
/* 78 */ 9999,
/* 79 */ 9999,
/* 80 */ 104028,
/* 81 */ 9999,
/* 82 */ 108004,
/* 83 */ 9999,
/* 84 */ 108004,
/* 85 */ 9999,
/* 86 */ 108006,
/* 87 */ 108028,
/* 88 */ 9999,
/* 89 */ 108028,
/* 90 */ 9999,
/* 91 */ 108032,
/* 92 */ 108045,
/* 93 */ 9999,
/* 94 */ 108045,
/* 95 */ 9999,
/* 96 */ 108049,
/* 97 */ 108062,
/* 98 */ 9999,
/* 99 */ 108062,
/* 100 */ 9999,
/* 101 */ 9999,
/* 102 */ 108062,
/* 103 */ 9999,
/* 104 */ 112004,
/* 105 */ 9999,
/* 106 */ 112004,
/* 107 */ 9999,
/* 108 */ 9999,
/* 109 */ 9999,
/* 110 */ 112009,
/* 111 */ 9999,
/* 112 */ 9999,
/* 113 */ 9999,
/* 114 */ 113011,
/* 115 */ 9999,
/* 116 */ 9999,
/* 117 */ 9999,
/* 118 */ 114009,
/* 119 */ 9999,
/* 120 */ 9999,
/* 121 */ 9999,
/* 122 */ 115009,
/* 123 */ 9999,
/* 124 */ 9999,
/* 125 */ 9999,
/* 126 */ 116010,
/* 127 */ 9999,
/* 128 */ 121004,
/* 129 */ 9999,
/* 130 */ 121004,
/* 131 */ 9999,
/* 132 */ 130004,
/* 133 */ 9999,
/* 134 */ 130028,
/* 135 */ 9999,
/* 136 */ 130032,
/* 137 */ 9999,
/* 138 */ 130045,
/* 139 */ 9999,
/* 140 */ 131004,
/* 141 */ 9999,
/* 142 */ 131005,
/* 143 */ 9999,
/* 144 */ 9999,
/* 145 */ 9999,
/* 146 */ 121009,
/* 147 */ 9999,
/* 148 */ 9999,
/* 149 */ 9999,
/* 150 */ 122007,
/* 151 */ 9999,
/* 152 */ 9999,
/* 153 */ 9999,
/* 154 */ 123008,
/* 155 */ 9999,
/* 156 */ 9999,
/* 157 */ 9999,
/* 158 */ 124006,
/* 159 */ 9999,
/* 160 */ 9999,
/* 161 */ 9999,
/* 162 */ 125007,
/* 163 */ 9999,
/* 164 */ 9999,
/* 165 */ 9999,
/* 166 */ 126008,
/* 167 */ 9999,
/* 168 */ 9999,
/* 169 */ 9999,
/* 170 */ 127009,
/* 171 */ 9999,
/* 172 */ 9999,
/* 173 */ 9999,
/* 174 */ 128009,
/* 175 */ 9999,
/* 176 */ 9999,
/* 177 */ 9999,
/* 178 */ 129011,
/* 179 */ 9999,
/* 180 */ 135004,
/* 181 */ 9999,
/* 182 */ 135004,
/* 183 */ 9999,
/* 184 */ 9999,
/* 185 */ 9999,
/* 186 */ 135010,
/* 187 */ 9999,
/* 188 */ 9999,
/* 189 */ 9999,
/* 190 */ 136011,
/* 191 */ 9999,
/* 192 */ 140004,
/* 193 */ 140020,
/* 194 */ 9999,
/* 195 */ 140061,
/* 196 */ 9999,
/* 197 */ 9999,
/* 198 */ 140018,
/* 199 */ 9999,
/* 200 */ 141004,
/* 201 */ 141020,
/* 202 */ 9999,
/* 203 */ 141018,
/* 204 */ 9999,
/* 205 */ 140022,
/* 206 */ 9999,
/* 207 */ 140023,
/* 208 */ 9999,
/* 209 */ 9999,
/* 210 */ 140023,
/* 211 */ 9999,
/* 212 */ 145004,
/* 213 */ 9999,
/* 214 */ 145004,
/* 215 */ 9999,
/* 216 */ 9999,
/* 217 */ 9999,
/* 218 */ 145011,
/* 219 */ 9999,
/* 220 */ 9999,
/* 221 */ 9999,
/* 222 */ 145019,
/* 223 */ 9999,
/* 224 */ 149004,
/* 225 */ 149033,
/* 226 */ 9999,
/* 227 */ 149004,
/* 228 */ 9999,
/* 229 */ 149006,
/* 230 */ 9999,
/* 231 */ 149028,
/* 232 */ 9999,
/* 233 */ 9999,
/* 234 */ 149028,
/* 235 */ 9999,
/* 236 */ 153004,
/* 237 */ 153045,
/* 238 */ 9999,
/* 239 */ 153004,
/* 240 */ 9999,
/* 241 */ 153006,
/* 242 */ 9999,
/* 243 */ 9999,
/* 244 */ 153025,
/* 245 */ 9999,
/* 246 */ 9999,
/* 247 */ 153025,
/* 248 */ 9999,
/* 249 */ 157004,
/* 250 */ 157036,
/* 251 */ 9999,
/* 252 */ 157004,
/* 253 */ 9999,
/* 254 */ 157006,
/* 255 */ 9999,
/* 256 */ 9999,
/* 257 */ 157015,
/* 258 */ 9999,
/* 259 */ 9999,
/* 260 */ 157015,
/* 261 */ 9999,
/* 262 */ 161004,
/* 263 */ 161029,
/* 264 */ 9999,
/* 265 */ 9999,
/* 266 */ 161027,
/* 267 */ 9999,
/* 268 */ 165004,
/* 269 */ 165040,
/* 270 */ 9999,
/* 271 */ 165004,
/* 272 */ 9999,
/* 273 */ 165006,
/* 274 */ 9999,
/* 275 */ 165019,
/* 276 */ 9999,
/* 277 */ 165023,
/* 278 */ 9999,
/* 279 */ 165036,
/* 280 */ 9999,
/* 281 */ 165042,
/* 282 */ 9999,
/* 283 */ 165065,
/* 284 */ 9999,
/* 285 */ 9999,
/* 286 */ 165065,
/* 287 */ 9999,
/* 288 */ 169004,
/* 289 */ 169047,
/* 290 */ 9999,
/* 291 */ 169004,
/* 292 */ 9999,
/* 293 */ 169006,
/* 294 */ 9999,
/* 295 */ 9999,
/* 296 */ 169027,
/* 297 */ 9999,
/* 298 */ 9999,
/* 299 */ 169027,
/* 300 */ 9999,
/* 301 */ 173004,
/* 302 */ 9999,
/* 303 */ 173013,
/* 304 */ 9999,
/* 305 */ 174004,
/* 306 */ 9999,
/* 307 */ 174035,
/* 308 */ 9999,
/* 309 */ 174004,
/* 310 */ 9999,
/* 311 */ 174006,
/* 312 */ 9999,
/* 313 */ 174015,
/* 314 */ 9999,
/* 315 */ 9999,
/* 316 */ 174015,
/* 317 */ 9999,
/* 318 */ 9999,
/* 319 */ 178019,
/* 320 */ 9999,
/* 321 */ 178060,
/* 322 */ 9999,
/* 323 */ 9999,
/* 324 */ 178007,
/* 325 */ 9999,
/* 326 */ 9999,
/* 327 */ 179019,
/* 328 */ 9999,
/* 329 */ 179007,
/* 330 */ 9999,
/* 331 */ 178021,
/* 332 */ 9999,
/* 333 */ 178022,
/* 334 */ 9999,
/* 335 */ 9999,
/* 336 */ 178022,
/* 337 */ 9999,
/* 338 */ 183004,
/* 339 */ 183040,
/* 340 */ 9999,
/* 341 */ 183004,
/* 342 */ 9999,
/* 343 */ 183006,
/* 344 */ 9999,
/* 345 */ 9999,
/* 346 */ 183020,
/* 347 */ 9999,
/* 348 */ 9999,
/* 349 */ 183020,
/* 350 */ 9999,
/* 351 */ 187004,
/* 352 */ 187007,
/* 353 */ 9999,
/* 354 */ 187005,
/* 355 */ 9999,
/* 356 */ 9999,
/* 357 */ 187025,
/* 358 */ 9999,
/* 359 */ 187009,
/* 360 */ 9999,
/* 361 */ 9999,
/* 362 */ 187009,
/* 363 */ 9999,
/* 364 */ 191004,
/* 365 */ 191017,
/* 366 */ 9999,
/* 367 */ 191004,
/* 368 */ 9999,
/* 369 */ 191006,
/* 370 */ 9999,
/* 371 */ 191012,
/* 372 */ 9999,
/* 373 */ 9999,
/* 374 */ 191012,
/* 375 */ 9999,
/* 376 */ 195004,
/* 377 */ 9999,
/* 378 */ 195005,
/* 379 */ 9999,
/* 380 */ 9999,
/* 381 */ 196018,
/* 382 */ 9999,
/* 383 */ 9999,
/* 384 */ 196004,
/* 385 */ 9999,
/* 386 */ 197004,
/* 387 */ 197022,
/* 388 */ 9999,
/* 389 */ 197020,
/* 390 */ 9999,
/* 391 */ 9999,
/* 392 */ 197038,
/* 393 */ 9999,
/* 394 */ 9999,
/* 395 */ 197024,
/* 396 */ 9999,
/* 397 */ 9999,
/* 398 */ 198019,
/* 399 */ 9999,
/* 400 */ 9999,
/* 401 */ 198005,
/* 402 */ 9999,
/* 403 */ 9999,
/* 404 */ 199019,
/* 405 */ 9999,
/* 406 */ 9999,
/* 407 */ 199005,
/* 408 */ 9999,
/* 409 */ 197040,
/* 410 */ 9999,
/* 411 */ 197049,
/* 412 */ 9999,
/* 413 */ 9999,
/* 414 */ 197049,
/* 415 */ 9999,
/* 416 */ 199021,
/* 417 */ 9999,
/* 418 */ 199035,
/* 419 */ 9999,
/* 420 */ 9999,
/* 421 */ 199035,
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
/* 519 */ 228031,
/* 520 */ 228048,
/* 521 */ 9999,
/* 522 */ 9999,
/* 523 */ 228004,
/* 524 */ 9999,
/* 525 */ 9999,
/* 526 */ 9999,
/* 527 */ 228050,
/* 528 */ 9999,
/* 529 */ 9999,
/* 530 */ 228050,
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
/* 598 */ 247019,
/* 599 */ 9999,
/* 600 */ 9999,
/* 601 */ 247005,
/* 602 */ 9999,
/* 603 */ 246054,
/* 604 */ 9999,
/* 605 */ 246063,
/* 606 */ 9999,
/* 607 */ 9999,
/* 608 */ 246063,
/* 609 */ 9999,
/* 610 */ 247021,
/* 611 */ 9999,
/* 612 */ 247039,
/* 613 */ 9999,
/* 614 */ 9999,
/* 615 */ 247039,
/* 616 */ 9999,
/* 617 */ 251004,
/* 618 */ 9999,
/* 619 */ 251005,
/* 620 */ 9999,
/* 621 */ 255004,
/* 622 */ 9999,
/* 623 */ 255020,
/* 624 */ 9999,
/* 625 */ 256004,
/* 626 */ 9999,
/* 627 */ 256023,
/* 628 */ 9999,
/* 629 */ 257004,
/* 630 */ 9999,
/* 631 */ 257021,
/* 632 */ 9999,
/* 633 */ 258004,
/* 634 */ 9999,
/* 635 */ 258022,
/* 636 */ 9999,
/* 637 */ 259004,
/* 638 */ 9999,
/* 639 */ 259022,
/* 640 */ 9999,
/* 641 */ 260004,
/* 642 */ 9999,
/* 643 */ 260017,
/* 644 */ 9999,
/* 645 */ 261004,
/* 646 */ 9999,
/* 647 */ 261018,
/* 648 */ 9999,
/* 649 */ 262004,
/* 650 */ 9999,
/* 651 */ 262018,
/* 652 */ 9999,
/* 653 */ 266004,
/* 654 */ 9999,
/* 655 */ 266022,
/* 656 */ 9999,
/* 657 */ 266005,
/* 658 */ 9999,
/* 659 */ 9999,
/* 660 */ 267019,
/* 661 */ 9999,
/* 662 */ 267054,
/* 663 */ 9999,
/* 664 */ 267007,
/* 665 */ 9999,
/* 666 */ 9999,
/* 667 */ 9999,
/* 668 */ 268037,
/* 669 */ 9999,
/* 670 */ 268010,
/* 671 */ 9999,
/* 672 */ 272004,
/* 673 */ 9999,
/* 674 */ 9999,
/* 675 */ 272004,
/* 676 */ 9999,
/* 677 */ 272006,
/* 678 */ 9999,
/* 679 */ 272015,
/* 680 */ 9999,
/* 681 */ 9999,
/* 682 */ 272015,
/* 683 */ 9999,
/* 684 */ 9999,
/* 685 */ 276040,
/* 686 */ 276062,
/* 687 */ 9999,
/* 688 */ 9999,
/* 689 */ 276004,
/* 690 */ 9999,
/* 691 */ 276042,
/* 692 */ 9999,
/* 693 */ 276057,
/* 694 */ 9999,
/* 695 */ 9999,
/* 696 */ 276057,
/* 697 */ 9999,
/* 698 */ 276064,
/* 699 */ 9999,
/* 700 */ 276077,
/* 701 */ 9999,
/* 702 */ 9999,
/* 703 */ 276077,
/* 704 */ 9999,
/* 705 */ 285004,
/* 706 */ 285019,
/* 707 */ 9999,
/* 708 */ 285004,
/* 709 */ 9999,
/* 710 */ 285006,
/* 711 */ 285014,
/* 712 */ 9999,
/* 713 */ 285014,
/* 714 */ 9999,
/* 715 */ 9999,
/* 716 */ 285014,
/* 717 */ 9999,
/* 718 */ 9999,
/* 719 */ 9999,
/* 720 */ 289031,
/* 721 */ 9999,
/* 722 */ 289056,
/* 723 */ 289066,
/* 724 */ 9999,
/* 725 */ 289005,
/* 726 */ 9999,
/* 727 */ 9999,
/* 728 */ 9999,
/* 729 */ 290035,
/* 730 */ 9999,
/* 731 */ 290060,
/* 732 */ 9999,
/* 733 */ 290009,
/* 734 */ 9999,
/* 735 */ 9999,
/* 736 */ 289083,
/* 737 */ 9999,
/* 738 */ 289071,
/* 739 */ 9999,
/* 740 */ 9999,
/* 741 */ 289071,
/* 742 */ 9999,
/* 743 */ 9999,
/* 744 */ 9999,
/* 745 */ 294034,
/* 746 */ 9999,
/* 747 */ 294059,
/* 748 */ 9999,
/* 749 */ 294008,
/* 750 */ 9999,
/* 751 */ 9999,
/* 752 */ 295017,
/* 753 */ 9999,
/* 754 */ 9999,
/* 755 */ 295057,
/* 756 */ 9999,
/* 757 */ 9999,
/* 758 */ 9999,
/* 759 */ 295005,
/* 760 */ 9999,
/* 761 */ 9999,
/* 762 */ 9999,
/* 763 */ 296032,
/* 764 */ 9999,
/* 765 */ 296063,
/* 766 */ 9999,
/* 767 */ 296094,
/* 768 */ 9999,
/* 769 */ 296124,
/* 770 */ 9999,
/* 771 */ 296006,
/* 772 */ 9999,
/* 773 */ 296034,
/* 774 */ 9999,
/* 775 */ 296043,
/* 776 */ 9999,
/* 777 */ 9999,
/* 778 */ 296043,
/* 779 */ 9999,
/* 780 */ 296065,
/* 781 */ 9999,
/* 782 */ 296074,
/* 783 */ 9999,
/* 784 */ 9999,
/* 785 */ 296074,
/* 786 */ 9999,
/* 787 */ 296096,
/* 788 */ 9999,
/* 789 */ 296105,
/* 790 */ 9999,
/* 791 */ 9999,
/* 792 */ 296105,
/* 793 */ 9999,
/* 794 */ 9999,
/* 795 */ 300019,
/* 796 */ 9999,
/* 797 */ 9999,
/* 798 */ 300007,
/* 799 */ 9999,
/* 800 */ 9999,
/* 801 */ 9999,
/* 802 */ 9999,
/* 803 */ 301011,
/* 804 */ 9999,
/* 805 */ 9999,
/* 806 */ 9999,
/* 807 */ 9999,
/* 808 */ 302008,
/* 809 */ 9999,
/* 810 */ 9999,
/* 811 */ 303021,
/* 812 */ 9999,
/* 813 */ 9999,
/* 814 */ 303009,
/* 815 */ 9999,
/* 816 */ 303023,
/* 817 */ 9999,
/* 818 */ 303032,
/* 819 */ 9999,
/* 820 */ 9999,
/* 821 */ 303032,
/* 822 */ 9999,
/* 823 */ 9999,
/* 824 */ 307020,
/* 825 */ 9999,
/* 826 */ 9999,
/* 827 */ 307008,
/* 828 */ 9999,
/* 829 */ 9999,
/* 830 */ 311020,
/* 831 */ 311043,
/* 832 */ 9999,
/* 833 */ 9999,
/* 834 */ 311008,
/* 835 */ 9999,
/* 836 */ 311022,
/* 837 */ 9999,
/* 838 */ 311023,
/* 839 */ 9999,
/* 840 */ 311023,
/* 841 */ 9999,
/* 842 */ 9999,
/* 843 */ 311023,
/* 844 */ 9999,
/* 845 */ 315004,
/* 846 */ 315035,
/* 847 */ 9999,
/* 848 */ 315004,
/* 849 */ 9999,
/* 850 */ 315006,
/* 851 */ 9999,
/* 852 */ 9999,
/* 853 */ 315015,
/* 854 */ 9999,
/* 855 */ 9999,
/* 856 */ 315015,
/* 857 */ 9999,
/* 858 */ 319004,
/* 859 */ 9999,
/* 860 */ 319025,
/* 861 */ 9999,
/* 862 */ 320004,
/* 863 */ 320021,
/* 864 */ 320041,
/* 865 */ 9999,
/* 866 */ 320019,
/* 867 */ 9999,
/* 868 */ 9999,
/* 869 */ 9999,
/* 870 */ 324009,
/* 871 */ 9999,
/* 872 */ 9999,
/* 873 */ 9999,
/* 874 */ 325004,
/* 875 */ 9999,
/* 876 */ 329004,
/* 877 */ 329026,
/* 878 */ 9999,
/* 879 */ 329024,
/* 880 */ 9999,
/* 881 */ 9999,
/* 882 */ 329044,
/* 883 */ 9999,
/* 884 */ 329071,
/* 885 */ 9999,
/* 886 */ 329028,
/* 887 */ 9999,
/* 888 */ 9999,
/* 889 */ 329028,
/* 890 */ 9999,
/* 891 */ 333004,
/* 892 */ 9999,
/* 893 */ 333025,
/* 894 */ 9999,
/* 895 */ 337004,
/* 896 */ 337075,
/* 897 */ 9999,
/* 898 */ 337004,
/* 899 */ 9999,
/* 900 */ 337006,
/* 901 */ 9999,
/* 902 */ 9999,
/* 903 */ 337026,
/* 904 */ 9999,
/* 905 */ 9999,
/* 906 */ 337026,
/* 907 */ 9999,
/* 908 */ 341004,
/* 909 */ 341079,
/* 910 */ 9999,
/* 911 */ 341004,
/* 912 */ 9999,
/* 913 */ 341006,
/* 914 */ 9999,
/* 915 */ 9999,
/* 916 */ 341027,
/* 917 */ 9999,
/* 918 */ 9999,
/* 919 */ 341027,
/* 920 */ 9999,
/* 921 */ 345004,
/* 922 */ 345052,
/* 923 */ 9999,
/* 924 */ 345004,
/* 925 */ 9999,
/* 926 */ 345006,
/* 927 */ 9999,
/* 928 */ 9999,
/* 929 */ 345028,
/* 930 */ 9999,
/* 931 */ 9999,
/* 932 */ 345028,
/* 933 */ 9999,
/* 934 */ 349004,
/* 935 */ 349053,
/* 936 */ 9999,
/* 937 */ 349004,
/* 938 */ 9999,
/* 939 */ 349006,
/* 940 */ 9999,
/* 941 */ 9999,
/* 942 */ 349028,
/* 943 */ 9999,
/* 944 */ 9999,
/* 945 */ 349028,
/* 946 */ 9999,
/* 947 */ 353004,
/* 948 */ 353043,
/* 949 */ 9999,
/* 950 */ 353004,
/* 951 */ 9999,
/* 952 */ 353005,
/* 953 */ 9999,
/* 954 */ 9999,
/* 955 */ 353018,
/* 956 */ 9999,
/* 957 */ 9999,
/* 958 */ 353018,
/* 959 */ 9999,
/* 960 */ 357004,
/* 961 */ 357076,
/* 962 */ 9999,
/* 963 */ 357004,
/* 964 */ 9999,
/* 965 */ 357006,
/* 966 */ 9999,
/* 967 */ 9999,
/* 968 */ 357024,
/* 969 */ 9999,
/* 970 */ 9999,
/* 971 */ 357024,
/* 972 */ 9999,
/* 973 */ 361004,
/* 974 */ 361119,
/* 975 */ 9999,
/* 976 */ 361004,
/* 977 */ 9999,
/* 978 */ 361005,
/* 979 */ 9999,
/* 980 */ 9999,
/* 981 */ 361020,
/* 982 */ 9999,
/* 983 */ 9999,
/* 984 */ 361020,
/* 985 */ 9999,
/* 986 */ 365004,
/* 987 */ 365055,
/* 988 */ 9999,
/* 989 */ 365004,
/* 990 */ 9999,
/* 991 */ 365006,
/* 992 */ 365026,
/* 993 */ 9999,
/* 994 */ 365024,
/* 995 */ 9999,
/* 996 */ 9999,
/* 997 */ 365024,
/* 998 */ 9999,
/* 999 */ 9999,
/* 1000 */ 9999,
/* 1001 */ 365028,
/* 1002 */ 9999,
/* 1003 */ 9999,
/* 1004 */ 9999,
/* 1005 */ 365034,
/* 1006 */ 9999,
/* 1007 */ 369004,
/* 1008 */ 369067,
/* 1009 */ 9999,
/* 1010 */ 369004,
/* 1011 */ 9999,
/* 1012 */ 369006,
/* 1013 */ 369032,
/* 1014 */ 9999,
/* 1015 */ 369030,
/* 1016 */ 9999,
/* 1017 */ 9999,
/* 1018 */ 369030,
/* 1019 */ 9999,
/* 1020 */ 9999,
/* 1021 */ 9999,
/* 1022 */ 369034,
/* 1023 */ 9999,
/* 1024 */ 9999,
/* 1025 */ 9999,
/* 1026 */ 369040,
/* 1027 */ 9999,
/* 1028 */ 9999,
/* 1029 */ 9999,
/* 1030 */ 369046,
/* 1031 */ 9999,
/* 1032 */ 373004,
/* 1033 */ 9999,
/* 1034 */ 373019,
/* 1035 */ 9999,
/* 1036 */ 9999,
/* 1037 */ 374018,
/* 1038 */ 9999,
/* 1039 */ 374042,
/* 1040 */ 9999,
/* 1041 */ 374004,
/* 1042 */ 9999,
/* 1043 */ 378004,
/* 1044 */ 9999,
/* 1045 */ 378021,
/* 1046 */ 9999,
/* 1047 */ 379004,
/* 1048 */ 379068,
/* 1049 */ 9999,
/* 1050 */ 379004,
/* 1051 */ 9999,
/* 1052 */ 380004,
/* 1053 */ 380019,
/* 1054 */ 9999,
/* 1055 */ 380017,
/* 1056 */ 9999,
/* 1057 */ 9999,
/* 1058 */ 381021,
/* 1059 */ 9999,
/* 1060 */ 381009,
/* 1061 */ 9999,
/* 1062 */ 9999,
/* 1063 */ 9999,
/* 1064 */ 382035,
/* 1065 */ 9999,
/* 1066 */ 9999,
/* 1067 */ 382009,
/* 1068 */ 9999,
/* 1069 */ 9999,
/* 1070 */ 9999,
/* 1071 */ 379011,
/* 1072 */ 9999,
/* 1073 */ 9999,
/* 1074 */ 9999,
/* 1075 */ 379042,
/* 1076 */ 9999,
/* 1077 */ 386004,
/* 1078 */ 9999,
/* 1079 */ 386004,
/* 1080 */ 9999,
/* 1081 */ 9999,
/* 1082 */ 9999,
/* 1083 */ 386011,
/* 1084 */ 9999,
/* 1085 */ 9999,
/* 1086 */ 9999,
/* 1087 */ 386015,
/* 1088 */ 9999,
/* 1089 */ 9999,
/* 1090 */ 9999,
/* 1091 */ 386021,
/* 1092 */ 9999,
/* 1093 */ 9999,
/* 1094 */ 9999,
/* 1095 */ 386027,
/* 1096 */ 9999,
/* 1097 */ 9999,
/* 1098 */ 9999,
/* 1099 */ 386033,
/* 1100 */ 9999,
/* 1101 */ 9999,
/* 1102 */ 9999,
/* 1103 */ 386039,
/* 1104 */ 9999,
/* 1105 */ 9999,
/* 1106 */ 9999,
/* 1107 */ 386051,
/* 1108 */ 9999,
/* 1109 */ 9999,
/* 1110 */ 9999,
/* 1111 */ 386060,
/* 1112 */ 9999,
/* 1113 */ 9999,
/* 1114 */ 9999,
/* 1115 */ 386070,
/* 1116 */ 9999,
/* 1117 */ 390004,
/* 1118 */ 9999,
/* 1119 */ 390021,
/* 1120 */ 9999,
/* 1121 */ 391004,
/* 1122 */ 391023,
/* 1123 */ 9999,
/* 1124 */ 391021,
/* 1125 */ 9999,
/* 1126 */ 9999,
/* 1127 */ 391039,
/* 1128 */ 391050,
/* 1129 */ 9999,
/* 1130 */ 9999,
/* 1131 */ 391025,
/* 1132 */ 9999,
/* 1133 */ 9999,
/* 1134 */ 392019,
/* 1135 */ 9999,
/* 1136 */ 9999,
/* 1137 */ 392005,
/* 1138 */ 9999,
/* 1139 */ 9999,
/* 1140 */ 393019,
/* 1141 */ 9999,
/* 1142 */ 393005,
/* 1143 */ 9999,
/* 1144 */ 9999,
/* 1145 */ 394046,
/* 1146 */ 9999,
/* 1147 */ 394010,
/* 1148 */ 9999,
/* 1149 */ 9999,
/* 1150 */ 9999,
/* 1151 */ 395010,
/* 1152 */ 9999,
/* 1153 */ 9999,
/* 1154 */ 9999,
/* 1155 */ 396010,
/* 1156 */ 9999,
/* 1157 */ 9999,
/* 1158 */ 391068,
/* 1159 */ 9999,
/* 1160 */ 391052,
/* 1161 */ 9999,
/* 1162 */ 9999,
/* 1163 */ 391052,
/* 1164 */ 9999,
/* 1165 */ 392021,
/* 1166 */ 9999,
/* 1167 */ 392044,
/* 1168 */ 9999,
/* 1169 */ 9999,
/* 1170 */ 392044,
/* 1171 */ 9999,
/* 1172 */ 400004,
/* 1173 */ 9999,
/* 1174 */ 400005,
/* 1175 */ 9999,
/* 1176 */ 401004,
/* 1177 */ 9999,
/* 1178 */ 401011,
/* 1179 */ 9999,
/* 1180 */ 9999,
/* 1181 */ 9999,
/* 1182 */ 402009,
/* 1183 */ 9999,
/* 1184 */ 9999,
/* 1185 */ 403018,
/* 1186 */ 9999,
/* 1187 */ 9999,
/* 1188 */ 403004,
/* 1189 */ 9999,
/* 1190 */ 407004,
/* 1191 */ 407049,
/* 1192 */ 9999,
/* 1193 */ 407004,
/* 1194 */ 9999,
/* 1195 */ 407006,
/* 1196 */ 9999,
/* 1197 */ 9999,
/* 1198 */ 407029,
/* 1199 */ 9999,
/* 1200 */ 9999,
/* 1201 */ 407029,
/* 1202 */ 9999,
/* 1203 */ 9999,
/* 1204 */ 9999,
/* 1205 */ 411011,
/* 1206 */ 9999,
/* 1207 */ 9999,
/* 1208 */ 9999,
/* 1209 */ 412012,
/* 1210 */ 9999,
/* 1211 */ 9999,
/* 1212 */ 9999,
/* 1213 */ 413013,
/* 1214 */ 9999,
/* 1215 */ 9999,
/* 1216 */ 9999,
/* 1217 */ 418013,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[1219];
*/
int TABLE[276][312];
init_dirsets() {
TABLE[108][0] = 1;
TABLE[108][59] = 1;
TABLE[108][123] = 1;
TABLE[108][40] = 1;
TABLE[108][42] = 1;
TABLE[108][299] = 1;
TABLE[108][44] = 1;
TABLE[108][61] = 1;
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
TABLE[108][278] = 1;
TABLE[108][283] = 1;
TABLE[108][280] = 1;
TABLE[108][63] = 1;
TABLE[108][294] = 1;
TABLE[108][295] = 1;
TABLE[108][297] = 1;
TABLE[108][302] = 1;
TABLE[108][300] = 1;
TABLE[108][303] = 1;
TABLE[108][33] = 1;
TABLE[108][126] = 1;
TABLE[108][45] = 1;
TABLE[108][43] = 1;
TABLE[108][301] = 1;
TABLE[108][289] = 1;
TABLE[108][298] = 1;
TABLE[108][308] = 1;
TABLE[108][306] = 1;
TABLE[108][307] = 1;
TABLE[108][292] = 1;
TABLE[108][304] = 1;
TABLE[108][47] = 1;
TABLE[108][37] = 1;
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
TABLE[1][301] = 1;
TABLE[1][43] = 1;
TABLE[1][45] = 1;
TABLE[1][126] = 1;
TABLE[1][33] = 1;
TABLE[1][303] = 1;
TABLE[1][300] = 1;
TABLE[1][302] = 1;
TABLE[1][297] = 1;
TABLE[1][307] = 1;
TABLE[1][306] = 1;
TABLE[1][308] = 1;
TABLE[1][298] = 1;
TABLE[1][292] = 1;
TABLE[1][304] = 1;
TABLE[1][37] = 1;
TABLE[1][47] = 1;
TABLE[109][0] = 1;
TABLE[109][59] = 1;
TABLE[109][123] = 1;
TABLE[109][40] = 1;
TABLE[109][42] = 1;
TABLE[109][299] = 1;
TABLE[109][44] = 1;
TABLE[109][61] = 1;
TABLE[109][286] = 1;
TABLE[109][260] = 1;
TABLE[109][284] = 1;
TABLE[109][277] = 1;
TABLE[109][264] = 1;
TABLE[109][268] = 1;
TABLE[109][273] = 1;
TABLE[109][272] = 1;
TABLE[109][276] = 1;
TABLE[109][259] = 1;
TABLE[109][285] = 1;
TABLE[109][266] = 1;
TABLE[109][282] = 1;
TABLE[109][267] = 1;
TABLE[109][279] = 1;
TABLE[109][274] = 1;
TABLE[109][256] = 1;
TABLE[109][278] = 1;
TABLE[109][283] = 1;
TABLE[109][280] = 1;
TABLE[109][63] = 1;
TABLE[109][294] = 1;
TABLE[109][295] = 1;
TABLE[109][297] = 1;
TABLE[109][302] = 1;
TABLE[109][300] = 1;
TABLE[109][303] = 1;
TABLE[109][33] = 1;
TABLE[109][126] = 1;
TABLE[109][45] = 1;
TABLE[109][43] = 1;
TABLE[109][301] = 1;
TABLE[109][289] = 1;
TABLE[109][298] = 1;
TABLE[109][308] = 1;
TABLE[109][306] = 1;
TABLE[109][307] = 1;
TABLE[109][292] = 1;
TABLE[109][304] = 1;
TABLE[109][47] = 1;
TABLE[109][37] = 1;
TABLE[219][0] = 1;
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
TABLE[2][302] = 1;
TABLE[2][300] = 1;
TABLE[2][303] = 1;
TABLE[2][33] = 1;
TABLE[2][126] = 1;
TABLE[2][45] = 1;
TABLE[2][43] = 1;
TABLE[2][301] = 1;
TABLE[2][289] = 1;
TABLE[2][298] = 1;
TABLE[2][308] = 1;
TABLE[2][306] = 1;
TABLE[2][307] = 1;
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
TABLE[3][301] = 1;
TABLE[3][43] = 1;
TABLE[3][45] = 1;
TABLE[3][126] = 1;
TABLE[3][33] = 1;
TABLE[3][303] = 1;
TABLE[3][300] = 1;
TABLE[3][302] = 1;
TABLE[3][297] = 1;
TABLE[3][307] = 1;
TABLE[3][306] = 1;
TABLE[3][308] = 1;
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
TABLE[4][301] = 1;
TABLE[4][43] = 1;
TABLE[4][45] = 1;
TABLE[4][126] = 1;
TABLE[4][33] = 1;
TABLE[4][303] = 1;
TABLE[4][300] = 1;
TABLE[4][302] = 1;
TABLE[4][297] = 1;
TABLE[4][307] = 1;
TABLE[4][306] = 1;
TABLE[4][308] = 1;
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
TABLE[110][44] = 1;
TABLE[110][61] = 1;
TABLE[110][278] = 1;
TABLE[110][40] = 1;
TABLE[110][295] = 1;
TABLE[110][294] = 1;
TABLE[110][63] = 1;
TABLE[110][42] = 1;
TABLE[110][289] = 1;
TABLE[110][301] = 1;
TABLE[110][43] = 1;
TABLE[110][45] = 1;
TABLE[110][126] = 1;
TABLE[110][33] = 1;
TABLE[110][303] = 1;
TABLE[110][300] = 1;
TABLE[110][302] = 1;
TABLE[110][297] = 1;
TABLE[110][307] = 1;
TABLE[110][306] = 1;
TABLE[110][308] = 1;
TABLE[110][298] = 1;
TABLE[110][292] = 1;
TABLE[110][304] = 1;
TABLE[110][37] = 1;
TABLE[110][47] = 1;
TABLE[110][59] = 1;
TABLE[110][123] = 1;
TABLE[110][286] = 1;
TABLE[110][260] = 1;
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
TABLE[110][299] = 1;
TABLE[110][282] = 1;
TABLE[110][267] = 1;
TABLE[110][279] = 1;
TABLE[110][274] = 1;
TABLE[110][256] = 1;
TABLE[110][283] = 1;
TABLE[110][280] = 1;
TABLE[220][44] = 1;
TABLE[220][256] = 1;
TABLE[220][274] = 1;
TABLE[220][279] = 1;
TABLE[220][267] = 1;
TABLE[220][282] = 1;
TABLE[220][299] = 1;
TABLE[220][266] = 1;
TABLE[220][285] = 1;
TABLE[220][259] = 1;
TABLE[220][276] = 1;
TABLE[220][272] = 1;
TABLE[220][273] = 1;
TABLE[220][268] = 1;
TABLE[220][264] = 1;
TABLE[220][277] = 1;
TABLE[220][284] = 1;
TABLE[220][260] = 1;
TABLE[220][286] = 1;
TABLE[220][61] = 1;
TABLE[220][280] = 1;
TABLE[220][283] = 1;
TABLE[220][278] = 1;
TABLE[220][40] = 1;
TABLE[220][295] = 1;
TABLE[220][294] = 1;
TABLE[220][63] = 1;
TABLE[220][42] = 1;
TABLE[220][289] = 1;
TABLE[220][301] = 1;
TABLE[220][43] = 1;
TABLE[220][45] = 1;
TABLE[220][126] = 1;
TABLE[220][33] = 1;
TABLE[220][303] = 1;
TABLE[220][300] = 1;
TABLE[220][302] = 1;
TABLE[220][297] = 1;
TABLE[220][307] = 1;
TABLE[220][306] = 1;
TABLE[220][308] = 1;
TABLE[220][298] = 1;
TABLE[220][292] = 1;
TABLE[220][304] = 1;
TABLE[220][37] = 1;
TABLE[220][47] = 1;
TABLE[220][59] = 1;
TABLE[220][123] = 1;
TABLE[111][59] = 1;
TABLE[111][44] = 1;
TABLE[111][61] = 1;
TABLE[111][123] = 1;
TABLE[111][286] = 1;
TABLE[111][260] = 1;
TABLE[111][284] = 1;
TABLE[111][277] = 1;
TABLE[111][264] = 1;
TABLE[111][268] = 1;
TABLE[111][273] = 1;
TABLE[111][272] = 1;
TABLE[111][276] = 1;
TABLE[111][259] = 1;
TABLE[111][285] = 1;
TABLE[111][266] = 1;
TABLE[111][299] = 1;
TABLE[111][282] = 1;
TABLE[111][267] = 1;
TABLE[111][279] = 1;
TABLE[111][274] = 1;
TABLE[111][256] = 1;
TABLE[111][40] = 1;
TABLE[111][278] = 1;
TABLE[111][283] = 1;
TABLE[111][280] = 1;
TABLE[111][42] = 1;
TABLE[111][63] = 1;
TABLE[111][294] = 1;
TABLE[111][295] = 1;
TABLE[111][297] = 1;
TABLE[111][302] = 1;
TABLE[111][300] = 1;
TABLE[111][303] = 1;
TABLE[111][33] = 1;
TABLE[111][126] = 1;
TABLE[111][45] = 1;
TABLE[111][43] = 1;
TABLE[111][301] = 1;
TABLE[111][289] = 1;
TABLE[111][298] = 1;
TABLE[111][308] = 1;
TABLE[111][306] = 1;
TABLE[111][307] = 1;
TABLE[111][292] = 1;
TABLE[111][304] = 1;
TABLE[111][47] = 1;
TABLE[111][37] = 1;
TABLE[221][59] = 1;
TABLE[221][123] = 1;
TABLE[112][59] = 1;
TABLE[113][123] = 1;
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
TABLE[5][302] = 1;
TABLE[5][300] = 1;
TABLE[5][303] = 1;
TABLE[5][33] = 1;
TABLE[5][126] = 1;
TABLE[5][45] = 1;
TABLE[5][43] = 1;
TABLE[5][301] = 1;
TABLE[5][289] = 1;
TABLE[5][298] = 1;
TABLE[5][308] = 1;
TABLE[5][306] = 1;
TABLE[5][307] = 1;
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
TABLE[114][59] = 1;
TABLE[114][44] = 1;
TABLE[114][123] = 1;
TABLE[114][61] = 1;
TABLE[114][278] = 1;
TABLE[114][40] = 1;
TABLE[114][295] = 1;
TABLE[114][294] = 1;
TABLE[114][63] = 1;
TABLE[114][299] = 1;
TABLE[114][42] = 1;
TABLE[114][289] = 1;
TABLE[114][301] = 1;
TABLE[114][43] = 1;
TABLE[114][45] = 1;
TABLE[114][126] = 1;
TABLE[114][33] = 1;
TABLE[114][303] = 1;
TABLE[114][300] = 1;
TABLE[114][302] = 1;
TABLE[114][297] = 1;
TABLE[114][307] = 1;
TABLE[114][306] = 1;
TABLE[114][308] = 1;
TABLE[114][298] = 1;
TABLE[114][292] = 1;
TABLE[114][304] = 1;
TABLE[114][37] = 1;
TABLE[114][47] = 1;
TABLE[222][59] = 1;
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
TABLE[6][309] = 1;
TABLE[6][310] = 1;
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
TABLE[6][301] = 1;
TABLE[6][43] = 1;
TABLE[6][45] = 1;
TABLE[6][126] = 1;
TABLE[6][33] = 1;
TABLE[6][303] = 1;
TABLE[6][300] = 1;
TABLE[6][302] = 1;
TABLE[6][297] = 1;
TABLE[6][307] = 1;
TABLE[6][306] = 1;
TABLE[6][308] = 1;
TABLE[6][298] = 1;
TABLE[6][292] = 1;
TABLE[6][304] = 1;
TABLE[6][37] = 1;
TABLE[6][47] = 1;
TABLE[115][262] = 1;
TABLE[115][258] = 1;
TABLE[115][281] = 1;
TABLE[115][271] = 1;
TABLE[115][269] = 1;
TABLE[115][263] = 1;
TABLE[115][287] = 1;
TABLE[115][275] = 1;
TABLE[115][257] = 1;
TABLE[115][261] = 1;
TABLE[115][270] = 1;
TABLE[115][309] = 1;
TABLE[115][310] = 1;
TABLE[115][125] = 1;
TABLE[115][59] = 1;
TABLE[115][44] = 1;
TABLE[115][256] = 1;
TABLE[115][274] = 1;
TABLE[115][279] = 1;
TABLE[115][267] = 1;
TABLE[115][282] = 1;
TABLE[115][299] = 1;
TABLE[115][266] = 1;
TABLE[115][285] = 1;
TABLE[115][259] = 1;
TABLE[115][276] = 1;
TABLE[115][272] = 1;
TABLE[115][273] = 1;
TABLE[115][268] = 1;
TABLE[115][264] = 1;
TABLE[115][277] = 1;
TABLE[115][284] = 1;
TABLE[115][260] = 1;
TABLE[115][286] = 1;
TABLE[115][123] = 1;
TABLE[115][61] = 1;
TABLE[115][280] = 1;
TABLE[115][283] = 1;
TABLE[115][278] = 1;
TABLE[115][40] = 1;
TABLE[115][295] = 1;
TABLE[115][294] = 1;
TABLE[115][63] = 1;
TABLE[115][42] = 1;
TABLE[115][289] = 1;
TABLE[115][301] = 1;
TABLE[115][43] = 1;
TABLE[115][45] = 1;
TABLE[115][126] = 1;
TABLE[115][33] = 1;
TABLE[115][303] = 1;
TABLE[115][300] = 1;
TABLE[115][302] = 1;
TABLE[115][297] = 1;
TABLE[115][307] = 1;
TABLE[115][306] = 1;
TABLE[115][308] = 1;
TABLE[115][298] = 1;
TABLE[115][292] = 1;
TABLE[115][304] = 1;
TABLE[115][37] = 1;
TABLE[115][47] = 1;
TABLE[223][59] = 1;
TABLE[223][123] = 1;
TABLE[223][262] = 1;
TABLE[223][258] = 1;
TABLE[223][281] = 1;
TABLE[223][271] = 1;
TABLE[223][269] = 1;
TABLE[223][263] = 1;
TABLE[223][287] = 1;
TABLE[223][275] = 1;
TABLE[223][257] = 1;
TABLE[223][261] = 1;
TABLE[223][270] = 1;
TABLE[223][309] = 1;
TABLE[223][310] = 1;
TABLE[223][299] = 1;
TABLE[223][44] = 1;
TABLE[223][278] = 1;
TABLE[223][63] = 1;
TABLE[223][294] = 1;
TABLE[223][295] = 1;
TABLE[223][297] = 1;
TABLE[223][302] = 1;
TABLE[223][300] = 1;
TABLE[223][303] = 1;
TABLE[223][33] = 1;
TABLE[223][126] = 1;
TABLE[223][45] = 1;
TABLE[223][43] = 1;
TABLE[223][42] = 1;
TABLE[223][301] = 1;
TABLE[223][40] = 1;
TABLE[223][289] = 1;
TABLE[223][298] = 1;
TABLE[223][308] = 1;
TABLE[223][306] = 1;
TABLE[223][307] = 1;
TABLE[223][292] = 1;
TABLE[223][304] = 1;
TABLE[223][47] = 1;
TABLE[223][37] = 1;
TABLE[223][125] = 1;
TABLE[7][44] = 1;
TABLE[7][61] = 1;
TABLE[7][278] = 1;
TABLE[7][40] = 1;
TABLE[7][295] = 1;
TABLE[7][294] = 1;
TABLE[7][63] = 1;
TABLE[7][42] = 1;
TABLE[7][289] = 1;
TABLE[7][301] = 1;
TABLE[7][43] = 1;
TABLE[7][45] = 1;
TABLE[7][126] = 1;
TABLE[7][33] = 1;
TABLE[7][303] = 1;
TABLE[7][300] = 1;
TABLE[7][302] = 1;
TABLE[7][297] = 1;
TABLE[7][307] = 1;
TABLE[7][306] = 1;
TABLE[7][308] = 1;
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
TABLE[116][282] = 1;
TABLE[116][267] = 1;
TABLE[116][279] = 1;
TABLE[116][274] = 1;
TABLE[116][256] = 1;
TABLE[117][284] = 1;
TABLE[117][277] = 1;
TABLE[117][264] = 1;
TABLE[117][268] = 1;
TABLE[117][273] = 1;
TABLE[117][272] = 1;
TABLE[117][276] = 1;
TABLE[117][259] = 1;
TABLE[117][285] = 1;
TABLE[117][266] = 1;
TABLE[117][299] = 1;
TABLE[117][283] = 1;
TABLE[117][280] = 1;
TABLE[118][286] = 1;
TABLE[118][260] = 1;
TABLE[224][44] = 1;
TABLE[224][256] = 1;
TABLE[224][274] = 1;
TABLE[224][279] = 1;
TABLE[224][267] = 1;
TABLE[224][282] = 1;
TABLE[224][299] = 1;
TABLE[224][266] = 1;
TABLE[224][285] = 1;
TABLE[224][259] = 1;
TABLE[224][276] = 1;
TABLE[224][272] = 1;
TABLE[224][273] = 1;
TABLE[224][268] = 1;
TABLE[224][264] = 1;
TABLE[224][277] = 1;
TABLE[224][284] = 1;
TABLE[224][260] = 1;
TABLE[224][286] = 1;
TABLE[224][61] = 1;
TABLE[224][280] = 1;
TABLE[224][283] = 1;
TABLE[224][278] = 1;
TABLE[224][40] = 1;
TABLE[224][295] = 1;
TABLE[224][294] = 1;
TABLE[224][63] = 1;
TABLE[224][42] = 1;
TABLE[224][289] = 1;
TABLE[224][301] = 1;
TABLE[224][43] = 1;
TABLE[224][45] = 1;
TABLE[224][126] = 1;
TABLE[224][33] = 1;
TABLE[224][303] = 1;
TABLE[224][300] = 1;
TABLE[224][302] = 1;
TABLE[224][297] = 1;
TABLE[224][307] = 1;
TABLE[224][306] = 1;
TABLE[224][308] = 1;
TABLE[224][298] = 1;
TABLE[224][292] = 1;
TABLE[224][304] = 1;
TABLE[224][37] = 1;
TABLE[224][47] = 1;
TABLE[224][59] = 1;
TABLE[224][123] = 1;
TABLE[224][91] = 1;
TABLE[224][41] = 1;
TABLE[8][256] = 1;
TABLE[8][274] = 1;
TABLE[8][279] = 1;
TABLE[8][267] = 1;
TABLE[8][282] = 1;
TABLE[119][256] = 1;
TABLE[120][274] = 1;
TABLE[121][279] = 1;
TABLE[122][267] = 1;
TABLE[123][282] = 1;
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
TABLE[124][285] = 1;
TABLE[125][259] = 1;
TABLE[126][276] = 1;
TABLE[127][272] = 1;
TABLE[128][273] = 1;
TABLE[129][268] = 1;
TABLE[130][264] = 1;
TABLE[131][277] = 1;
TABLE[132][284] = 1;
TABLE[13][260] = 1;
TABLE[13][286] = 1;
TABLE[133][260] = 1;
TABLE[134][286] = 1;
TABLE[14][283] = 1;
TABLE[14][280] = 1;
TABLE[15][283] = 1;
TABLE[15][280] = 1;
TABLE[135][299] = 1;
TABLE[225][123] = 1;
TABLE[16][280] = 1;
TABLE[16][283] = 1;
TABLE[136][280] = 1;
TABLE[137][283] = 1;
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
TABLE[138][286] = 1;
TABLE[138][260] = 1;
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
TABLE[226][299] = 1;
TABLE[226][266] = 1;
TABLE[226][285] = 1;
TABLE[226][259] = 1;
TABLE[226][276] = 1;
TABLE[226][272] = 1;
TABLE[226][273] = 1;
TABLE[226][268] = 1;
TABLE[226][264] = 1;
TABLE[226][277] = 1;
TABLE[226][284] = 1;
TABLE[226][260] = 1;
TABLE[226][286] = 1;
TABLE[226][280] = 1;
TABLE[226][283] = 1;
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
TABLE[18][302] = 1;
TABLE[18][300] = 1;
TABLE[18][303] = 1;
TABLE[18][33] = 1;
TABLE[18][126] = 1;
TABLE[18][45] = 1;
TABLE[18][43] = 1;
TABLE[18][301] = 1;
TABLE[18][289] = 1;
TABLE[18][298] = 1;
TABLE[18][308] = 1;
TABLE[18][306] = 1;
TABLE[18][307] = 1;
TABLE[18][292] = 1;
TABLE[18][304] = 1;
TABLE[18][47] = 1;
TABLE[18][37] = 1;
TABLE[139][44] = 1;
TABLE[139][123] = 1;
TABLE[139][61] = 1;
TABLE[139][278] = 1;
TABLE[139][40] = 1;
TABLE[139][295] = 1;
TABLE[139][294] = 1;
TABLE[139][63] = 1;
TABLE[139][299] = 1;
TABLE[139][42] = 1;
TABLE[139][289] = 1;
TABLE[139][301] = 1;
TABLE[139][43] = 1;
TABLE[139][45] = 1;
TABLE[139][126] = 1;
TABLE[139][33] = 1;
TABLE[139][303] = 1;
TABLE[139][300] = 1;
TABLE[139][302] = 1;
TABLE[139][297] = 1;
TABLE[139][307] = 1;
TABLE[139][306] = 1;
TABLE[139][308] = 1;
TABLE[139][298] = 1;
TABLE[139][292] = 1;
TABLE[139][304] = 1;
TABLE[139][37] = 1;
TABLE[139][47] = 1;
TABLE[227][61] = 1;
TABLE[227][123] = 1;
TABLE[227][40] = 1;
TABLE[227][278] = 1;
TABLE[227][42] = 1;
TABLE[227][299] = 1;
TABLE[227][63] = 1;
TABLE[227][294] = 1;
TABLE[227][295] = 1;
TABLE[227][297] = 1;
TABLE[227][302] = 1;
TABLE[227][300] = 1;
TABLE[227][303] = 1;
TABLE[227][33] = 1;
TABLE[227][126] = 1;
TABLE[227][45] = 1;
TABLE[227][43] = 1;
TABLE[227][301] = 1;
TABLE[227][289] = 1;
TABLE[227][298] = 1;
TABLE[227][308] = 1;
TABLE[227][306] = 1;
TABLE[227][307] = 1;
TABLE[227][292] = 1;
TABLE[227][304] = 1;
TABLE[227][47] = 1;
TABLE[227][37] = 1;
TABLE[227][59] = 1;
TABLE[227][44] = 1;
TABLE[19][59] = 1;
TABLE[19][44] = 1;
TABLE[19][123] = 1;
TABLE[19][278] = 1;
TABLE[19][295] = 1;
TABLE[19][294] = 1;
TABLE[19][63] = 1;
TABLE[19][289] = 1;
TABLE[19][301] = 1;
TABLE[19][43] = 1;
TABLE[19][45] = 1;
TABLE[19][126] = 1;
TABLE[19][33] = 1;
TABLE[19][303] = 1;
TABLE[19][300] = 1;
TABLE[19][302] = 1;
TABLE[19][297] = 1;
TABLE[19][307] = 1;
TABLE[19][306] = 1;
TABLE[19][308] = 1;
TABLE[19][298] = 1;
TABLE[19][292] = 1;
TABLE[19][304] = 1;
TABLE[19][37] = 1;
TABLE[19][47] = 1;
TABLE[19][61] = 1;
TABLE[19][40] = 1;
TABLE[19][299] = 1;
TABLE[19][42] = 1;
TABLE[140][61] = 1;
TABLE[140][40] = 1;
TABLE[140][42] = 1;
TABLE[140][299] = 1;
TABLE[228][123] = 1;
TABLE[228][278] = 1;
TABLE[228][295] = 1;
TABLE[228][294] = 1;
TABLE[228][63] = 1;
TABLE[228][289] = 1;
TABLE[228][40] = 1;
TABLE[228][301] = 1;
TABLE[228][42] = 1;
TABLE[228][43] = 1;
TABLE[228][45] = 1;
TABLE[228][126] = 1;
TABLE[228][33] = 1;
TABLE[228][303] = 1;
TABLE[228][300] = 1;
TABLE[228][302] = 1;
TABLE[228][297] = 1;
TABLE[228][299] = 1;
TABLE[228][307] = 1;
TABLE[228][306] = 1;
TABLE[228][308] = 1;
TABLE[228][298] = 1;
TABLE[228][292] = 1;
TABLE[228][304] = 1;
TABLE[228][37] = 1;
TABLE[228][47] = 1;
TABLE[228][59] = 1;
TABLE[228][44] = 1;
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
TABLE[141][284] = 1;
TABLE[141][277] = 1;
TABLE[141][264] = 1;
TABLE[141][268] = 1;
TABLE[141][273] = 1;
TABLE[141][272] = 1;
TABLE[141][276] = 1;
TABLE[141][259] = 1;
TABLE[141][285] = 1;
TABLE[141][266] = 1;
TABLE[141][299] = 1;
TABLE[141][283] = 1;
TABLE[141][280] = 1;
TABLE[142][286] = 1;
TABLE[142][260] = 1;
TABLE[143][286] = 1;
TABLE[143][260] = 1;
TABLE[143][284] = 1;
TABLE[143][277] = 1;
TABLE[143][264] = 1;
TABLE[143][268] = 1;
TABLE[143][273] = 1;
TABLE[143][272] = 1;
TABLE[143][276] = 1;
TABLE[143][259] = 1;
TABLE[143][285] = 1;
TABLE[143][266] = 1;
TABLE[143][299] = 1;
TABLE[143][283] = 1;
TABLE[143][280] = 1;
TABLE[229][44] = 1;
TABLE[229][58] = 1;
TABLE[229][40] = 1;
TABLE[229][42] = 1;
TABLE[229][299] = 1;
TABLE[229][59] = 1;
TABLE[229][91] = 1;
TABLE[229][41] = 1;
TABLE[22][59] = 1;
TABLE[22][44] = 1;
TABLE[22][58] = 1;
TABLE[22][40] = 1;
TABLE[22][299] = 1;
TABLE[22][42] = 1;
TABLE[144][44] = 1;
TABLE[144][58] = 1;
TABLE[144][40] = 1;
TABLE[144][42] = 1;
TABLE[144][299] = 1;
TABLE[230][58] = 1;
TABLE[230][40] = 1;
TABLE[230][299] = 1;
TABLE[230][42] = 1;
TABLE[230][59] = 1;
TABLE[230][44] = 1;
TABLE[23][59] = 1;
TABLE[23][44] = 1;
TABLE[23][40] = 1;
TABLE[23][42] = 1;
TABLE[23][299] = 1;
TABLE[24][58] = 1;
TABLE[24][40] = 1;
TABLE[24][299] = 1;
TABLE[24][42] = 1;
TABLE[145][58] = 1;
TABLE[145][40] = 1;
TABLE[145][42] = 1;
TABLE[145][299] = 1;
TABLE[231][58] = 1;
TABLE[25][266] = 1;
TABLE[26][266] = 1;
TABLE[146][299] = 1;
TABLE[232][123] = 1;
TABLE[27][44] = 1;
TABLE[27][299] = 1;
TABLE[147][44] = 1;
TABLE[147][299] = 1;
TABLE[233][299] = 1;
TABLE[28][299] = 1;
TABLE[148][61] = 1;
TABLE[234][125] = 1;
TABLE[234][44] = 1;
TABLE[29][40] = 1;
TABLE[29][299] = 1;
TABLE[29][42] = 1;
TABLE[149][42] = 1;
TABLE[235][40] = 1;
TABLE[235][299] = 1;
TABLE[30][299] = 1;
TABLE[31][40] = 1;
TABLE[32][40] = 1;
TABLE[32][299] = 1;
TABLE[151][91] = 1;
TABLE[152][40] = 1;
TABLE[154][40] = 1;
TABLE[150][93] = 1;
TABLE[150][44] = 1;
TABLE[150][278] = 1;
TABLE[150][295] = 1;
TABLE[150][294] = 1;
TABLE[150][63] = 1;
TABLE[150][289] = 1;
TABLE[150][40] = 1;
TABLE[150][301] = 1;
TABLE[150][42] = 1;
TABLE[150][43] = 1;
TABLE[150][45] = 1;
TABLE[150][126] = 1;
TABLE[150][33] = 1;
TABLE[150][303] = 1;
TABLE[150][300] = 1;
TABLE[150][302] = 1;
TABLE[150][297] = 1;
TABLE[150][299] = 1;
TABLE[150][307] = 1;
TABLE[150][306] = 1;
TABLE[150][308] = 1;
TABLE[150][298] = 1;
TABLE[150][292] = 1;
TABLE[150][304] = 1;
TABLE[150][37] = 1;
TABLE[150][47] = 1;
TABLE[236][93] = 1;
TABLE[153][41] = 1;
TABLE[153][44] = 1;
TABLE[153][299] = 1;
TABLE[237][41] = 1;
TABLE[33][42] = 1;
TABLE[155][42] = 1;
TABLE[155][40] = 1;
TABLE[155][299] = 1;
TABLE[155][44] = 1;
TABLE[155][41] = 1;
TABLE[155][91] = 1;
TABLE[155][260] = 1;
TABLE[155][286] = 1;
TABLE[238][42] = 1;
TABLE[238][40] = 1;
TABLE[238][299] = 1;
TABLE[238][44] = 1;
TABLE[238][41] = 1;
TABLE[238][91] = 1;
TABLE[156][42] = 1;
TABLE[239][40] = 1;
TABLE[239][299] = 1;
TABLE[239][44] = 1;
TABLE[239][41] = 1;
TABLE[239][91] = 1;
TABLE[34][286] = 1;
TABLE[34][260] = 1;
TABLE[157][260] = 1;
TABLE[157][286] = 1;
TABLE[240][286] = 1;
TABLE[240][260] = 1;
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
TABLE[158][44] = 1;
TABLE[241][41] = 1;
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
TABLE[159][44] = 1;
TABLE[159][40] = 1;
TABLE[159][42] = 1;
TABLE[159][286] = 1;
TABLE[159][260] = 1;
TABLE[159][284] = 1;
TABLE[159][277] = 1;
TABLE[159][264] = 1;
TABLE[159][268] = 1;
TABLE[159][273] = 1;
TABLE[159][272] = 1;
TABLE[159][276] = 1;
TABLE[159][259] = 1;
TABLE[159][285] = 1;
TABLE[159][266] = 1;
TABLE[159][299] = 1;
TABLE[159][282] = 1;
TABLE[159][267] = 1;
TABLE[159][279] = 1;
TABLE[159][274] = 1;
TABLE[159][256] = 1;
TABLE[159][91] = 1;
TABLE[159][283] = 1;
TABLE[159][280] = 1;
TABLE[242][40] = 1;
TABLE[242][256] = 1;
TABLE[242][274] = 1;
TABLE[242][279] = 1;
TABLE[242][267] = 1;
TABLE[242][282] = 1;
TABLE[242][299] = 1;
TABLE[242][266] = 1;
TABLE[242][285] = 1;
TABLE[242][259] = 1;
TABLE[242][276] = 1;
TABLE[242][272] = 1;
TABLE[242][273] = 1;
TABLE[242][268] = 1;
TABLE[242][264] = 1;
TABLE[242][277] = 1;
TABLE[242][284] = 1;
TABLE[242][260] = 1;
TABLE[242][286] = 1;
TABLE[242][42] = 1;
TABLE[242][280] = 1;
TABLE[242][283] = 1;
TABLE[242][91] = 1;
TABLE[242][44] = 1;
TABLE[242][41] = 1;
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
TABLE[160][44] = 1;
TABLE[160][41] = 1;
TABLE[160][40] = 1;
TABLE[160][42] = 1;
TABLE[160][299] = 1;
TABLE[162][44] = 1;
TABLE[162][41] = 1;
TABLE[162][42] = 1;
TABLE[162][40] = 1;
TABLE[162][91] = 1;
TABLE[161][44] = 1;
TABLE[161][41] = 1;
TABLE[161][42] = 1;
TABLE[161][40] = 1;
TABLE[161][91] = 1;
TABLE[243][44] = 1;
TABLE[243][41] = 1;
TABLE[38][44] = 1;
TABLE[38][299] = 1;
TABLE[163][44] = 1;
TABLE[163][299] = 1;
TABLE[244][299] = 1;
TABLE[39][59] = 1;
TABLE[39][44] = 1;
TABLE[39][125] = 1;
TABLE[39][278] = 1;
TABLE[39][63] = 1;
TABLE[39][294] = 1;
TABLE[39][295] = 1;
TABLE[39][297] = 1;
TABLE[39][302] = 1;
TABLE[39][300] = 1;
TABLE[39][303] = 1;
TABLE[39][33] = 1;
TABLE[39][126] = 1;
TABLE[39][45] = 1;
TABLE[39][43] = 1;
TABLE[39][42] = 1;
TABLE[39][301] = 1;
TABLE[39][40] = 1;
TABLE[39][289] = 1;
TABLE[39][298] = 1;
TABLE[39][308] = 1;
TABLE[39][306] = 1;
TABLE[39][307] = 1;
TABLE[39][299] = 1;
TABLE[39][292] = 1;
TABLE[39][304] = 1;
TABLE[39][47] = 1;
TABLE[39][37] = 1;
TABLE[40][123] = 1;
TABLE[164][44] = 1;
TABLE[245][125] = 1;
TABLE[41][125] = 1;
TABLE[41][123] = 1;
TABLE[41][44] = 1;
TABLE[41][278] = 1;
TABLE[41][295] = 1;
TABLE[41][294] = 1;
TABLE[41][63] = 1;
TABLE[41][289] = 1;
TABLE[41][40] = 1;
TABLE[41][301] = 1;
TABLE[41][42] = 1;
TABLE[41][43] = 1;
TABLE[41][45] = 1;
TABLE[41][126] = 1;
TABLE[41][33] = 1;
TABLE[41][303] = 1;
TABLE[41][300] = 1;
TABLE[41][302] = 1;
TABLE[41][297] = 1;
TABLE[41][299] = 1;
TABLE[41][307] = 1;
TABLE[41][306] = 1;
TABLE[41][308] = 1;
TABLE[41][298] = 1;
TABLE[41][292] = 1;
TABLE[41][304] = 1;
TABLE[41][37] = 1;
TABLE[41][47] = 1;
TABLE[165][123] = 1;
TABLE[165][44] = 1;
TABLE[165][278] = 1;
TABLE[165][63] = 1;
TABLE[165][294] = 1;
TABLE[165][295] = 1;
TABLE[165][297] = 1;
TABLE[165][302] = 1;
TABLE[165][300] = 1;
TABLE[165][303] = 1;
TABLE[165][33] = 1;
TABLE[165][126] = 1;
TABLE[165][45] = 1;
TABLE[165][43] = 1;
TABLE[165][42] = 1;
TABLE[165][301] = 1;
TABLE[165][40] = 1;
TABLE[165][289] = 1;
TABLE[165][298] = 1;
TABLE[165][308] = 1;
TABLE[165][306] = 1;
TABLE[165][307] = 1;
TABLE[165][299] = 1;
TABLE[165][292] = 1;
TABLE[165][304] = 1;
TABLE[165][47] = 1;
TABLE[165][37] = 1;
TABLE[246][123] = 1;
TABLE[246][278] = 1;
TABLE[246][295] = 1;
TABLE[246][294] = 1;
TABLE[246][63] = 1;
TABLE[246][289] = 1;
TABLE[246][40] = 1;
TABLE[246][301] = 1;
TABLE[246][42] = 1;
TABLE[246][43] = 1;
TABLE[246][45] = 1;
TABLE[246][126] = 1;
TABLE[246][33] = 1;
TABLE[246][303] = 1;
TABLE[246][300] = 1;
TABLE[246][302] = 1;
TABLE[246][297] = 1;
TABLE[246][299] = 1;
TABLE[246][307] = 1;
TABLE[246][306] = 1;
TABLE[246][308] = 1;
TABLE[246][298] = 1;
TABLE[246][292] = 1;
TABLE[246][304] = 1;
TABLE[246][37] = 1;
TABLE[246][47] = 1;
TABLE[246][44] = 1;
TABLE[246][125] = 1;
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
TABLE[166][41] = 1;
TABLE[166][42] = 1;
TABLE[166][40] = 1;
TABLE[166][91] = 1;
TABLE[247][41] = 1;
TABLE[43][42] = 1;
TABLE[44][44] = 1;
TABLE[44][41] = 1;
TABLE[44][40] = 1;
TABLE[44][91] = 1;
TABLE[44][42] = 1;
TABLE[167][42] = 1;
TABLE[248][40] = 1;
TABLE[248][91] = 1;
TABLE[248][44] = 1;
TABLE[248][41] = 1;
TABLE[45][40] = 1;
TABLE[46][40] = 1;
TABLE[46][91] = 1;
TABLE[168][40] = 1;
TABLE[168][91] = 1;
TABLE[249][91] = 1;
TABLE[249][40] = 1;
TABLE[170][91] = 1;
TABLE[172][40] = 1;
TABLE[169][93] = 1;
TABLE[169][44] = 1;
TABLE[169][278] = 1;
TABLE[169][295] = 1;
TABLE[169][294] = 1;
TABLE[169][63] = 1;
TABLE[169][289] = 1;
TABLE[169][40] = 1;
TABLE[169][301] = 1;
TABLE[169][42] = 1;
TABLE[169][43] = 1;
TABLE[169][45] = 1;
TABLE[169][126] = 1;
TABLE[169][33] = 1;
TABLE[169][303] = 1;
TABLE[169][300] = 1;
TABLE[169][302] = 1;
TABLE[169][297] = 1;
TABLE[169][299] = 1;
TABLE[169][307] = 1;
TABLE[169][306] = 1;
TABLE[169][308] = 1;
TABLE[169][298] = 1;
TABLE[169][292] = 1;
TABLE[169][304] = 1;
TABLE[169][37] = 1;
TABLE[169][47] = 1;
TABLE[250][93] = 1;
TABLE[171][41] = 1;
TABLE[171][44] = 1;
TABLE[171][40] = 1;
TABLE[171][256] = 1;
TABLE[171][274] = 1;
TABLE[171][279] = 1;
TABLE[171][267] = 1;
TABLE[171][282] = 1;
TABLE[171][299] = 1;
TABLE[171][266] = 1;
TABLE[171][285] = 1;
TABLE[171][259] = 1;
TABLE[171][276] = 1;
TABLE[171][272] = 1;
TABLE[171][273] = 1;
TABLE[171][268] = 1;
TABLE[171][264] = 1;
TABLE[171][277] = 1;
TABLE[171][284] = 1;
TABLE[171][260] = 1;
TABLE[171][286] = 1;
TABLE[171][42] = 1;
TABLE[171][280] = 1;
TABLE[171][283] = 1;
TABLE[171][91] = 1;
TABLE[251][41] = 1;
TABLE[47][299] = 1;
TABLE[48][258] = 1;
TABLE[48][262] = 1;
TABLE[48][299] = 1;
TABLE[49][125] = 1;
TABLE[49][262] = 1;
TABLE[49][258] = 1;
TABLE[49][123] = 1;
TABLE[49][281] = 1;
TABLE[49][271] = 1;
TABLE[49][269] = 1;
TABLE[49][263] = 1;
TABLE[49][287] = 1;
TABLE[49][275] = 1;
TABLE[49][257] = 1;
TABLE[49][261] = 1;
TABLE[49][270] = 1;
TABLE[49][309] = 1;
TABLE[49][310] = 1;
TABLE[49][265] = 1;
TABLE[49][59] = 1;
TABLE[49][44] = 1;
TABLE[49][278] = 1;
TABLE[49][295] = 1;
TABLE[49][294] = 1;
TABLE[49][63] = 1;
TABLE[49][289] = 1;
TABLE[49][40] = 1;
TABLE[49][301] = 1;
TABLE[49][42] = 1;
TABLE[49][43] = 1;
TABLE[49][45] = 1;
TABLE[49][126] = 1;
TABLE[49][33] = 1;
TABLE[49][303] = 1;
TABLE[49][300] = 1;
TABLE[49][302] = 1;
TABLE[49][297] = 1;
TABLE[49][299] = 1;
TABLE[49][307] = 1;
TABLE[49][306] = 1;
TABLE[49][308] = 1;
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
TABLE[54][309] = 1;
TABLE[55][310] = 1;
TABLE[56][299] = 1;
TABLE[57][258] = 1;
TABLE[58][262] = 1;
TABLE[59][59] = 1;
TABLE[59][44] = 1;
TABLE[59][278] = 1;
TABLE[59][63] = 1;
TABLE[59][294] = 1;
TABLE[59][295] = 1;
TABLE[59][297] = 1;
TABLE[59][302] = 1;
TABLE[59][300] = 1;
TABLE[59][303] = 1;
TABLE[59][33] = 1;
TABLE[59][126] = 1;
TABLE[59][45] = 1;
TABLE[59][43] = 1;
TABLE[59][42] = 1;
TABLE[59][301] = 1;
TABLE[59][40] = 1;
TABLE[59][289] = 1;
TABLE[59][298] = 1;
TABLE[59][308] = 1;
TABLE[59][306] = 1;
TABLE[59][307] = 1;
TABLE[59][299] = 1;
TABLE[59][292] = 1;
TABLE[59][304] = 1;
TABLE[59][47] = 1;
TABLE[59][37] = 1;
TABLE[173][59] = 1;
TABLE[173][44] = 1;
TABLE[173][278] = 1;
TABLE[173][295] = 1;
TABLE[173][294] = 1;
TABLE[173][63] = 1;
TABLE[173][289] = 1;
TABLE[173][40] = 1;
TABLE[173][301] = 1;
TABLE[173][42] = 1;
TABLE[173][43] = 1;
TABLE[173][45] = 1;
TABLE[173][126] = 1;
TABLE[173][33] = 1;
TABLE[173][303] = 1;
TABLE[173][300] = 1;
TABLE[173][302] = 1;
TABLE[173][297] = 1;
TABLE[173][299] = 1;
TABLE[173][307] = 1;
TABLE[173][306] = 1;
TABLE[173][308] = 1;
TABLE[173][298] = 1;
TABLE[173][292] = 1;
TABLE[173][304] = 1;
TABLE[173][37] = 1;
TABLE[173][47] = 1;
TABLE[252][59] = 1;
TABLE[60][123] = 1;
TABLE[174][262] = 1;
TABLE[174][258] = 1;
TABLE[174][281] = 1;
TABLE[174][271] = 1;
TABLE[174][269] = 1;
TABLE[174][263] = 1;
TABLE[174][287] = 1;
TABLE[174][275] = 1;
TABLE[174][257] = 1;
TABLE[174][261] = 1;
TABLE[174][270] = 1;
TABLE[174][309] = 1;
TABLE[174][310] = 1;
TABLE[174][125] = 1;
TABLE[174][59] = 1;
TABLE[174][44] = 1;
TABLE[174][61] = 1;
TABLE[174][123] = 1;
TABLE[174][286] = 1;
TABLE[174][260] = 1;
TABLE[174][284] = 1;
TABLE[174][277] = 1;
TABLE[174][264] = 1;
TABLE[174][268] = 1;
TABLE[174][273] = 1;
TABLE[174][272] = 1;
TABLE[174][276] = 1;
TABLE[174][259] = 1;
TABLE[174][285] = 1;
TABLE[174][266] = 1;
TABLE[174][299] = 1;
TABLE[174][282] = 1;
TABLE[174][267] = 1;
TABLE[174][279] = 1;
TABLE[174][274] = 1;
TABLE[174][256] = 1;
TABLE[174][40] = 1;
TABLE[174][278] = 1;
TABLE[174][283] = 1;
TABLE[174][280] = 1;
TABLE[174][42] = 1;
TABLE[174][63] = 1;
TABLE[174][294] = 1;
TABLE[174][295] = 1;
TABLE[174][297] = 1;
TABLE[174][302] = 1;
TABLE[174][300] = 1;
TABLE[174][303] = 1;
TABLE[174][33] = 1;
TABLE[174][126] = 1;
TABLE[174][45] = 1;
TABLE[174][43] = 1;
TABLE[174][301] = 1;
TABLE[174][289] = 1;
TABLE[174][298] = 1;
TABLE[174][308] = 1;
TABLE[174][306] = 1;
TABLE[174][307] = 1;
TABLE[174][292] = 1;
TABLE[174][304] = 1;
TABLE[174][47] = 1;
TABLE[174][37] = 1;
TABLE[253][262] = 1;
TABLE[253][258] = 1;
TABLE[253][59] = 1;
TABLE[253][123] = 1;
TABLE[253][281] = 1;
TABLE[253][271] = 1;
TABLE[253][269] = 1;
TABLE[253][263] = 1;
TABLE[253][287] = 1;
TABLE[253][275] = 1;
TABLE[253][257] = 1;
TABLE[253][261] = 1;
TABLE[253][270] = 1;
TABLE[253][309] = 1;
TABLE[253][310] = 1;
TABLE[253][299] = 1;
TABLE[253][44] = 1;
TABLE[253][278] = 1;
TABLE[253][63] = 1;
TABLE[253][294] = 1;
TABLE[253][295] = 1;
TABLE[253][297] = 1;
TABLE[253][302] = 1;
TABLE[253][300] = 1;
TABLE[253][303] = 1;
TABLE[253][33] = 1;
TABLE[253][126] = 1;
TABLE[253][45] = 1;
TABLE[253][43] = 1;
TABLE[253][42] = 1;
TABLE[253][301] = 1;
TABLE[253][40] = 1;
TABLE[253][289] = 1;
TABLE[253][298] = 1;
TABLE[253][308] = 1;
TABLE[253][306] = 1;
TABLE[253][307] = 1;
TABLE[253][292] = 1;
TABLE[253][304] = 1;
TABLE[253][47] = 1;
TABLE[253][37] = 1;
TABLE[253][125] = 1;
TABLE[175][125] = 1;
TABLE[175][310] = 1;
TABLE[175][309] = 1;
TABLE[175][270] = 1;
TABLE[175][261] = 1;
TABLE[175][257] = 1;
TABLE[175][275] = 1;
TABLE[175][287] = 1;
TABLE[175][263] = 1;
TABLE[175][269] = 1;
TABLE[175][271] = 1;
TABLE[175][281] = 1;
TABLE[175][123] = 1;
TABLE[175][59] = 1;
TABLE[175][258] = 1;
TABLE[175][262] = 1;
TABLE[175][299] = 1;
TABLE[175][44] = 1;
TABLE[175][278] = 1;
TABLE[175][295] = 1;
TABLE[175][294] = 1;
TABLE[175][63] = 1;
TABLE[175][289] = 1;
TABLE[175][40] = 1;
TABLE[175][301] = 1;
TABLE[175][42] = 1;
TABLE[175][43] = 1;
TABLE[175][45] = 1;
TABLE[175][126] = 1;
TABLE[175][33] = 1;
TABLE[175][303] = 1;
TABLE[175][300] = 1;
TABLE[175][302] = 1;
TABLE[175][297] = 1;
TABLE[175][307] = 1;
TABLE[175][306] = 1;
TABLE[175][308] = 1;
TABLE[175][298] = 1;
TABLE[175][292] = 1;
TABLE[175][304] = 1;
TABLE[175][37] = 1;
TABLE[175][47] = 1;
TABLE[254][125] = 1;
TABLE[61][125] = 1;
TABLE[61][310] = 1;
TABLE[61][309] = 1;
TABLE[61][270] = 1;
TABLE[61][261] = 1;
TABLE[61][257] = 1;
TABLE[61][275] = 1;
TABLE[61][287] = 1;
TABLE[61][263] = 1;
TABLE[61][269] = 1;
TABLE[61][271] = 1;
TABLE[61][281] = 1;
TABLE[61][123] = 1;
TABLE[61][59] = 1;
TABLE[61][258] = 1;
TABLE[61][262] = 1;
TABLE[61][299] = 1;
TABLE[61][44] = 1;
TABLE[61][278] = 1;
TABLE[61][295] = 1;
TABLE[61][294] = 1;
TABLE[61][63] = 1;
TABLE[61][289] = 1;
TABLE[61][40] = 1;
TABLE[61][301] = 1;
TABLE[61][42] = 1;
TABLE[61][43] = 1;
TABLE[61][45] = 1;
TABLE[61][126] = 1;
TABLE[61][33] = 1;
TABLE[61][303] = 1;
TABLE[61][300] = 1;
TABLE[61][302] = 1;
TABLE[61][297] = 1;
TABLE[61][307] = 1;
TABLE[61][306] = 1;
TABLE[61][308] = 1;
TABLE[61][298] = 1;
TABLE[61][292] = 1;
TABLE[61][304] = 1;
TABLE[61][37] = 1;
TABLE[61][47] = 1;
TABLE[176][125] = 1;
TABLE[176][262] = 1;
TABLE[176][258] = 1;
TABLE[176][59] = 1;
TABLE[176][123] = 1;
TABLE[176][281] = 1;
TABLE[176][271] = 1;
TABLE[176][269] = 1;
TABLE[176][263] = 1;
TABLE[176][287] = 1;
TABLE[176][275] = 1;
TABLE[176][257] = 1;
TABLE[176][261] = 1;
TABLE[176][270] = 1;
TABLE[176][309] = 1;
TABLE[176][310] = 1;
TABLE[176][299] = 1;
TABLE[176][44] = 1;
TABLE[176][278] = 1;
TABLE[176][63] = 1;
TABLE[176][294] = 1;
TABLE[176][295] = 1;
TABLE[176][297] = 1;
TABLE[176][302] = 1;
TABLE[176][300] = 1;
TABLE[176][303] = 1;
TABLE[176][33] = 1;
TABLE[176][126] = 1;
TABLE[176][45] = 1;
TABLE[176][43] = 1;
TABLE[176][42] = 1;
TABLE[176][301] = 1;
TABLE[176][40] = 1;
TABLE[176][289] = 1;
TABLE[176][298] = 1;
TABLE[176][308] = 1;
TABLE[176][306] = 1;
TABLE[176][307] = 1;
TABLE[176][292] = 1;
TABLE[176][304] = 1;
TABLE[176][47] = 1;
TABLE[176][37] = 1;
TABLE[255][262] = 1;
TABLE[255][258] = 1;
TABLE[255][59] = 1;
TABLE[255][123] = 1;
TABLE[255][281] = 1;
TABLE[255][271] = 1;
TABLE[255][269] = 1;
TABLE[255][263] = 1;
TABLE[255][287] = 1;
TABLE[255][275] = 1;
TABLE[255][257] = 1;
TABLE[255][261] = 1;
TABLE[255][270] = 1;
TABLE[255][309] = 1;
TABLE[255][310] = 1;
TABLE[255][299] = 1;
TABLE[255][44] = 1;
TABLE[255][278] = 1;
TABLE[255][63] = 1;
TABLE[255][294] = 1;
TABLE[255][295] = 1;
TABLE[255][297] = 1;
TABLE[255][302] = 1;
TABLE[255][300] = 1;
TABLE[255][303] = 1;
TABLE[255][33] = 1;
TABLE[255][126] = 1;
TABLE[255][45] = 1;
TABLE[255][43] = 1;
TABLE[255][42] = 1;
TABLE[255][301] = 1;
TABLE[255][40] = 1;
TABLE[255][289] = 1;
TABLE[255][298] = 1;
TABLE[255][308] = 1;
TABLE[255][306] = 1;
TABLE[255][307] = 1;
TABLE[255][292] = 1;
TABLE[255][304] = 1;
TABLE[255][47] = 1;
TABLE[255][37] = 1;
TABLE[255][125] = 1;
TABLE[62][271] = 1;
TABLE[63][281] = 1;
TABLE[177][265] = 1;
TABLE[256][125] = 1;
TABLE[256][262] = 1;
TABLE[256][258] = 1;
TABLE[256][59] = 1;
TABLE[256][123] = 1;
TABLE[256][281] = 1;
TABLE[256][271] = 1;
TABLE[256][269] = 1;
TABLE[256][263] = 1;
TABLE[256][287] = 1;
TABLE[256][275] = 1;
TABLE[256][257] = 1;
TABLE[256][261] = 1;
TABLE[256][270] = 1;
TABLE[256][309] = 1;
TABLE[256][310] = 1;
TABLE[256][299] = 1;
TABLE[256][44] = 1;
TABLE[256][278] = 1;
TABLE[256][63] = 1;
TABLE[256][294] = 1;
TABLE[256][295] = 1;
TABLE[256][297] = 1;
TABLE[256][302] = 1;
TABLE[256][300] = 1;
TABLE[256][303] = 1;
TABLE[256][33] = 1;
TABLE[256][126] = 1;
TABLE[256][45] = 1;
TABLE[256][43] = 1;
TABLE[256][42] = 1;
TABLE[256][301] = 1;
TABLE[256][40] = 1;
TABLE[256][289] = 1;
TABLE[256][298] = 1;
TABLE[256][308] = 1;
TABLE[256][306] = 1;
TABLE[256][307] = 1;
TABLE[256][292] = 1;
TABLE[256][304] = 1;
TABLE[256][47] = 1;
TABLE[256][37] = 1;
TABLE[256][265] = 1;
TABLE[64][287] = 1;
TABLE[65][263] = 1;
TABLE[66][269] = 1;
TABLE[178][59] = 1;
TABLE[178][44] = 1;
TABLE[178][278] = 1;
TABLE[178][295] = 1;
TABLE[178][294] = 1;
TABLE[178][63] = 1;
TABLE[178][289] = 1;
TABLE[178][40] = 1;
TABLE[178][301] = 1;
TABLE[178][42] = 1;
TABLE[178][43] = 1;
TABLE[178][45] = 1;
TABLE[178][126] = 1;
TABLE[178][33] = 1;
TABLE[178][303] = 1;
TABLE[178][300] = 1;
TABLE[178][302] = 1;
TABLE[178][297] = 1;
TABLE[178][299] = 1;
TABLE[178][307] = 1;
TABLE[178][306] = 1;
TABLE[178][308] = 1;
TABLE[178][298] = 1;
TABLE[178][292] = 1;
TABLE[178][304] = 1;
TABLE[178][37] = 1;
TABLE[178][47] = 1;
TABLE[257][59] = 1;
TABLE[179][59] = 1;
TABLE[179][44] = 1;
TABLE[179][278] = 1;
TABLE[179][295] = 1;
TABLE[179][294] = 1;
TABLE[179][63] = 1;
TABLE[179][289] = 1;
TABLE[179][40] = 1;
TABLE[179][301] = 1;
TABLE[179][42] = 1;
TABLE[179][43] = 1;
TABLE[179][45] = 1;
TABLE[179][126] = 1;
TABLE[179][33] = 1;
TABLE[179][303] = 1;
TABLE[179][300] = 1;
TABLE[179][302] = 1;
TABLE[179][297] = 1;
TABLE[179][299] = 1;
TABLE[179][307] = 1;
TABLE[179][306] = 1;
TABLE[179][308] = 1;
TABLE[179][298] = 1;
TABLE[179][292] = 1;
TABLE[179][304] = 1;
TABLE[179][37] = 1;
TABLE[179][47] = 1;
TABLE[258][59] = 1;
TABLE[180][41] = 1;
TABLE[180][44] = 1;
TABLE[180][278] = 1;
TABLE[180][295] = 1;
TABLE[180][294] = 1;
TABLE[180][63] = 1;
TABLE[180][289] = 1;
TABLE[180][40] = 1;
TABLE[180][301] = 1;
TABLE[180][42] = 1;
TABLE[180][43] = 1;
TABLE[180][45] = 1;
TABLE[180][126] = 1;
TABLE[180][33] = 1;
TABLE[180][303] = 1;
TABLE[180][300] = 1;
TABLE[180][302] = 1;
TABLE[180][297] = 1;
TABLE[180][299] = 1;
TABLE[180][307] = 1;
TABLE[180][306] = 1;
TABLE[180][308] = 1;
TABLE[180][298] = 1;
TABLE[180][292] = 1;
TABLE[180][304] = 1;
TABLE[180][37] = 1;
TABLE[180][47] = 1;
TABLE[259][41] = 1;
TABLE[67][270] = 1;
TABLE[68][261] = 1;
TABLE[69][257] = 1;
TABLE[70][275] = 1;
TABLE[181][59] = 1;
TABLE[181][44] = 1;
TABLE[181][278] = 1;
TABLE[181][295] = 1;
TABLE[181][294] = 1;
TABLE[181][63] = 1;
TABLE[181][289] = 1;
TABLE[181][40] = 1;
TABLE[181][301] = 1;
TABLE[181][42] = 1;
TABLE[181][43] = 1;
TABLE[181][45] = 1;
TABLE[181][126] = 1;
TABLE[181][33] = 1;
TABLE[181][303] = 1;
TABLE[181][300] = 1;
TABLE[181][302] = 1;
TABLE[181][297] = 1;
TABLE[181][299] = 1;
TABLE[181][307] = 1;
TABLE[181][306] = 1;
TABLE[181][308] = 1;
TABLE[181][298] = 1;
TABLE[181][292] = 1;
TABLE[181][304] = 1;
TABLE[181][37] = 1;
TABLE[181][47] = 1;
TABLE[260][59] = 1;
TABLE[71][309] = 1;
TABLE[72][310] = 1;
TABLE[182][299] = 1;
TABLE[261][299] = 1;
TABLE[73][93] = 1;
TABLE[73][59] = 1;
TABLE[73][41] = 1;
TABLE[73][58] = 1;
TABLE[73][44] = 1;
TABLE[73][278] = 1;
TABLE[73][63] = 1;
TABLE[73][294] = 1;
TABLE[73][295] = 1;
TABLE[73][297] = 1;
TABLE[73][302] = 1;
TABLE[73][300] = 1;
TABLE[73][303] = 1;
TABLE[73][33] = 1;
TABLE[73][126] = 1;
TABLE[73][45] = 1;
TABLE[73][43] = 1;
TABLE[73][42] = 1;
TABLE[73][301] = 1;
TABLE[73][40] = 1;
TABLE[73][289] = 1;
TABLE[73][298] = 1;
TABLE[73][308] = 1;
TABLE[73][306] = 1;
TABLE[73][307] = 1;
TABLE[73][299] = 1;
TABLE[73][292] = 1;
TABLE[73][304] = 1;
TABLE[73][47] = 1;
TABLE[73][37] = 1;
TABLE[183][44] = 1;
TABLE[183][278] = 1;
TABLE[183][295] = 1;
TABLE[183][294] = 1;
TABLE[183][63] = 1;
TABLE[183][289] = 1;
TABLE[183][40] = 1;
TABLE[183][301] = 1;
TABLE[183][42] = 1;
TABLE[183][43] = 1;
TABLE[183][45] = 1;
TABLE[183][126] = 1;
TABLE[183][33] = 1;
TABLE[183][303] = 1;
TABLE[183][300] = 1;
TABLE[183][302] = 1;
TABLE[183][297] = 1;
TABLE[183][299] = 1;
TABLE[183][307] = 1;
TABLE[183][306] = 1;
TABLE[183][308] = 1;
TABLE[183][298] = 1;
TABLE[183][292] = 1;
TABLE[183][304] = 1;
TABLE[183][37] = 1;
TABLE[183][47] = 1;
TABLE[262][278] = 1;
TABLE[262][63] = 1;
TABLE[262][294] = 1;
TABLE[262][295] = 1;
TABLE[262][297] = 1;
TABLE[262][302] = 1;
TABLE[262][300] = 1;
TABLE[262][303] = 1;
TABLE[262][33] = 1;
TABLE[262][126] = 1;
TABLE[262][45] = 1;
TABLE[262][43] = 1;
TABLE[262][42] = 1;
TABLE[262][301] = 1;
TABLE[262][40] = 1;
TABLE[262][289] = 1;
TABLE[262][298] = 1;
TABLE[262][308] = 1;
TABLE[262][306] = 1;
TABLE[262][307] = 1;
TABLE[262][299] = 1;
TABLE[262][292] = 1;
TABLE[262][304] = 1;
TABLE[262][47] = 1;
TABLE[262][37] = 1;
TABLE[262][93] = 1;
TABLE[262][59] = 1;
TABLE[262][41] = 1;
TABLE[262][44] = 1;
TABLE[262][58] = 1;
TABLE[74][59] = 1;
TABLE[74][93] = 1;
TABLE[74][41] = 1;
TABLE[74][44] = 1;
TABLE[74][125] = 1;
TABLE[74][58] = 1;
TABLE[74][63] = 1;
TABLE[74][297] = 1;
TABLE[74][298] = 1;
TABLE[74][300] = 1;
TABLE[74][302] = 1;
TABLE[74][301] = 1;
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
TABLE[74][303] = 1;
TABLE[74][33] = 1;
TABLE[74][126] = 1;
TABLE[74][289] = 1;
TABLE[74][308] = 1;
TABLE[74][306] = 1;
TABLE[74][307] = 1;
TABLE[74][299] = 1;
TABLE[75][278] = 1;
TABLE[75][295] = 1;
TABLE[75][294] = 1;
TABLE[75][289] = 1;
TABLE[75][40] = 1;
TABLE[75][301] = 1;
TABLE[75][42] = 1;
TABLE[75][43] = 1;
TABLE[75][45] = 1;
TABLE[75][126] = 1;
TABLE[75][33] = 1;
TABLE[75][303] = 1;
TABLE[75][300] = 1;
TABLE[75][302] = 1;
TABLE[75][299] = 1;
TABLE[75][307] = 1;
TABLE[75][306] = 1;
TABLE[75][308] = 1;
TABLE[76][291] = 1;
TABLE[77][61] = 1;
TABLE[78][59] = 1;
TABLE[78][93] = 1;
TABLE[78][41] = 1;
TABLE[78][125] = 1;
TABLE[78][58] = 1;
TABLE[78][44] = 1;
TABLE[78][63] = 1;
TABLE[78][297] = 1;
TABLE[78][298] = 1;
TABLE[78][300] = 1;
TABLE[78][302] = 1;
TABLE[78][301] = 1;
TABLE[78][292] = 1;
TABLE[78][304] = 1;
TABLE[78][40] = 1;
TABLE[78][45] = 1;
TABLE[78][43] = 1;
TABLE[78][42] = 1;
TABLE[78][47] = 1;
TABLE[78][37] = 1;
TABLE[78][278] = 1;
TABLE[78][295] = 1;
TABLE[78][294] = 1;
TABLE[78][289] = 1;
TABLE[78][126] = 1;
TABLE[78][33] = 1;
TABLE[78][303] = 1;
TABLE[78][299] = 1;
TABLE[78][307] = 1;
TABLE[78][306] = 1;
TABLE[78][308] = 1;
TABLE[184][63] = 1;
TABLE[263][59] = 1;
TABLE[263][93] = 1;
TABLE[263][41] = 1;
TABLE[263][125] = 1;
TABLE[263][58] = 1;
TABLE[263][44] = 1;
TABLE[79][59] = 1;
TABLE[79][125] = 1;
TABLE[79][58] = 1;
TABLE[79][44] = 1;
TABLE[79][63] = 1;
TABLE[79][297] = 1;
TABLE[79][298] = 1;
TABLE[79][300] = 1;
TABLE[79][302] = 1;
TABLE[79][301] = 1;
TABLE[79][292] = 1;
TABLE[79][304] = 1;
TABLE[79][43] = 1;
TABLE[79][45] = 1;
TABLE[79][40] = 1;
TABLE[79][278] = 1;
TABLE[79][37] = 1;
TABLE[79][47] = 1;
TABLE[79][42] = 1;
TABLE[79][294] = 1;
TABLE[79][295] = 1;
TABLE[79][303] = 1;
TABLE[79][33] = 1;
TABLE[79][126] = 1;
TABLE[79][289] = 1;
TABLE[79][308] = 1;
TABLE[79][306] = 1;
TABLE[79][307] = 1;
TABLE[79][299] = 1;
TABLE[80][63] = 1;
TABLE[80][59] = 1;
TABLE[80][93] = 1;
TABLE[80][41] = 1;
TABLE[80][125] = 1;
TABLE[80][58] = 1;
TABLE[80][44] = 1;
TABLE[80][297] = 1;
TABLE[80][298] = 1;
TABLE[80][300] = 1;
TABLE[80][302] = 1;
TABLE[80][301] = 1;
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
TABLE[80][33] = 1;
TABLE[80][126] = 1;
TABLE[80][289] = 1;
TABLE[80][308] = 1;
TABLE[80][306] = 1;
TABLE[80][307] = 1;
TABLE[80][299] = 1;
TABLE[185][297] = 1;
TABLE[185][298] = 1;
TABLE[185][300] = 1;
TABLE[185][302] = 1;
TABLE[185][301] = 1;
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
TABLE[185][303] = 1;
TABLE[185][299] = 1;
TABLE[185][307] = 1;
TABLE[185][306] = 1;
TABLE[185][308] = 1;
TABLE[264][298] = 1;
TABLE[264][300] = 1;
TABLE[264][302] = 1;
TABLE[264][301] = 1;
TABLE[264][292] = 1;
TABLE[264][304] = 1;
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
TABLE[264][33] = 1;
TABLE[264][126] = 1;
TABLE[264][289] = 1;
TABLE[264][308] = 1;
TABLE[264][306] = 1;
TABLE[264][307] = 1;
TABLE[264][299] = 1;
TABLE[264][63] = 1;
TABLE[264][59] = 1;
TABLE[264][93] = 1;
TABLE[264][41] = 1;
TABLE[264][297] = 1;
TABLE[264][125] = 1;
TABLE[264][58] = 1;
TABLE[264][44] = 1;
TABLE[81][63] = 1;
TABLE[81][59] = 1;
TABLE[81][93] = 1;
TABLE[81][41] = 1;
TABLE[81][297] = 1;
TABLE[81][125] = 1;
TABLE[81][58] = 1;
TABLE[81][44] = 1;
TABLE[81][298] = 1;
TABLE[81][300] = 1;
TABLE[81][302] = 1;
TABLE[81][301] = 1;
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
TABLE[81][126] = 1;
TABLE[81][33] = 1;
TABLE[81][303] = 1;
TABLE[81][299] = 1;
TABLE[81][307] = 1;
TABLE[81][306] = 1;
TABLE[81][308] = 1;
TABLE[186][298] = 1;
TABLE[186][300] = 1;
TABLE[186][302] = 1;
TABLE[186][301] = 1;
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
TABLE[186][33] = 1;
TABLE[186][126] = 1;
TABLE[186][289] = 1;
TABLE[186][308] = 1;
TABLE[186][306] = 1;
TABLE[186][307] = 1;
TABLE[186][299] = 1;
TABLE[265][300] = 1;
TABLE[265][302] = 1;
TABLE[265][301] = 1;
TABLE[265][292] = 1;
TABLE[265][304] = 1;
TABLE[265][40] = 1;
TABLE[265][45] = 1;
TABLE[265][43] = 1;
TABLE[265][42] = 1;
TABLE[265][47] = 1;
TABLE[265][37] = 1;
TABLE[265][278] = 1;
TABLE[265][295] = 1;
TABLE[265][294] = 1;
TABLE[265][289] = 1;
TABLE[265][126] = 1;
TABLE[265][33] = 1;
TABLE[265][303] = 1;
TABLE[265][299] = 1;
TABLE[265][307] = 1;
TABLE[265][306] = 1;
TABLE[265][308] = 1;
TABLE[265][63] = 1;
TABLE[265][59] = 1;
TABLE[265][93] = 1;
TABLE[265][41] = 1;
TABLE[265][298] = 1;
TABLE[265][297] = 1;
TABLE[265][125] = 1;
TABLE[265][58] = 1;
TABLE[265][44] = 1;
TABLE[82][63] = 1;
TABLE[82][59] = 1;
TABLE[82][93] = 1;
TABLE[82][41] = 1;
TABLE[82][298] = 1;
TABLE[82][297] = 1;
TABLE[82][125] = 1;
TABLE[82][58] = 1;
TABLE[82][44] = 1;
TABLE[82][300] = 1;
TABLE[82][302] = 1;
TABLE[82][301] = 1;
TABLE[82][292] = 1;
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
TABLE[82][33] = 1;
TABLE[82][126] = 1;
TABLE[82][289] = 1;
TABLE[82][308] = 1;
TABLE[82][306] = 1;
TABLE[82][307] = 1;
TABLE[82][299] = 1;
TABLE[187][300] = 1;
TABLE[187][302] = 1;
TABLE[187][301] = 1;
TABLE[187][292] = 1;
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
TABLE[187][126] = 1;
TABLE[187][33] = 1;
TABLE[187][303] = 1;
TABLE[187][299] = 1;
TABLE[187][307] = 1;
TABLE[187][306] = 1;
TABLE[187][308] = 1;
TABLE[266][302] = 1;
TABLE[266][301] = 1;
TABLE[266][292] = 1;
TABLE[266][304] = 1;
TABLE[266][43] = 1;
TABLE[266][45] = 1;
TABLE[266][40] = 1;
TABLE[266][278] = 1;
TABLE[266][37] = 1;
TABLE[266][47] = 1;
TABLE[266][42] = 1;
TABLE[266][294] = 1;
TABLE[266][295] = 1;
TABLE[266][300] = 1;
TABLE[266][303] = 1;
TABLE[266][33] = 1;
TABLE[266][126] = 1;
TABLE[266][289] = 1;
TABLE[266][308] = 1;
TABLE[266][306] = 1;
TABLE[266][307] = 1;
TABLE[266][299] = 1;
TABLE[266][63] = 1;
TABLE[266][59] = 1;
TABLE[266][93] = 1;
TABLE[266][41] = 1;
TABLE[266][298] = 1;
TABLE[266][297] = 1;
TABLE[266][125] = 1;
TABLE[266][58] = 1;
TABLE[266][44] = 1;
TABLE[83][63] = 1;
TABLE[83][59] = 1;
TABLE[83][93] = 1;
TABLE[83][41] = 1;
TABLE[83][298] = 1;
TABLE[83][297] = 1;
TABLE[83][125] = 1;
TABLE[83][58] = 1;
TABLE[83][44] = 1;
TABLE[83][302] = 1;
TABLE[83][301] = 1;
TABLE[83][292] = 1;
TABLE[83][304] = 1;
TABLE[83][40] = 1;
TABLE[83][45] = 1;
TABLE[83][43] = 1;
TABLE[83][42] = 1;
TABLE[83][47] = 1;
TABLE[83][37] = 1;
TABLE[83][278] = 1;
TABLE[83][295] = 1;
TABLE[83][294] = 1;
TABLE[83][289] = 1;
TABLE[83][126] = 1;
TABLE[83][33] = 1;
TABLE[83][303] = 1;
TABLE[83][300] = 1;
TABLE[83][299] = 1;
TABLE[83][307] = 1;
TABLE[83][306] = 1;
TABLE[83][308] = 1;
TABLE[188][302] = 1;
TABLE[188][301] = 1;
TABLE[188][292] = 1;
TABLE[188][304] = 1;
TABLE[188][43] = 1;
TABLE[188][45] = 1;
TABLE[188][40] = 1;
TABLE[188][278] = 1;
TABLE[188][37] = 1;
TABLE[188][47] = 1;
TABLE[188][42] = 1;
TABLE[188][294] = 1;
TABLE[188][295] = 1;
TABLE[188][300] = 1;
TABLE[188][303] = 1;
TABLE[188][33] = 1;
TABLE[188][126] = 1;
TABLE[188][289] = 1;
TABLE[188][308] = 1;
TABLE[188][306] = 1;
TABLE[188][307] = 1;
TABLE[188][299] = 1;
TABLE[267][301] = 1;
TABLE[267][292] = 1;
TABLE[267][304] = 1;
TABLE[267][40] = 1;
TABLE[267][45] = 1;
TABLE[267][43] = 1;
TABLE[267][42] = 1;
TABLE[267][47] = 1;
TABLE[267][37] = 1;
TABLE[267][278] = 1;
TABLE[267][295] = 1;
TABLE[267][294] = 1;
TABLE[267][289] = 1;
TABLE[267][126] = 1;
TABLE[267][33] = 1;
TABLE[267][303] = 1;
TABLE[267][300] = 1;
TABLE[267][302] = 1;
TABLE[267][299] = 1;
TABLE[267][307] = 1;
TABLE[267][306] = 1;
TABLE[267][308] = 1;
TABLE[267][63] = 1;
TABLE[267][59] = 1;
TABLE[267][93] = 1;
TABLE[267][41] = 1;
TABLE[267][298] = 1;
TABLE[267][297] = 1;
TABLE[267][125] = 1;
TABLE[267][58] = 1;
TABLE[267][44] = 1;
TABLE[84][63] = 1;
TABLE[84][59] = 1;
TABLE[84][93] = 1;
TABLE[84][41] = 1;
TABLE[84][298] = 1;
TABLE[84][297] = 1;
TABLE[84][125] = 1;
TABLE[84][58] = 1;
TABLE[84][44] = 1;
TABLE[84][301] = 1;
TABLE[84][292] = 1;
TABLE[84][304] = 1;
TABLE[84][43] = 1;
TABLE[84][45] = 1;
TABLE[84][40] = 1;
TABLE[84][278] = 1;
TABLE[84][37] = 1;
TABLE[84][47] = 1;
TABLE[84][42] = 1;
TABLE[84][294] = 1;
TABLE[84][295] = 1;
TABLE[84][302] = 1;
TABLE[84][300] = 1;
TABLE[84][303] = 1;
TABLE[84][33] = 1;
TABLE[84][126] = 1;
TABLE[84][289] = 1;
TABLE[84][308] = 1;
TABLE[84][306] = 1;
TABLE[84][307] = 1;
TABLE[84][299] = 1;
TABLE[189][301] = 1;
TABLE[189][292] = 1;
TABLE[189][304] = 1;
TABLE[189][40] = 1;
TABLE[189][45] = 1;
TABLE[189][43] = 1;
TABLE[189][42] = 1;
TABLE[189][47] = 1;
TABLE[189][37] = 1;
TABLE[189][278] = 1;
TABLE[189][295] = 1;
TABLE[189][294] = 1;
TABLE[189][289] = 1;
TABLE[189][126] = 1;
TABLE[189][33] = 1;
TABLE[189][303] = 1;
TABLE[189][300] = 1;
TABLE[189][302] = 1;
TABLE[189][299] = 1;
TABLE[189][307] = 1;
TABLE[189][306] = 1;
TABLE[189][308] = 1;
TABLE[268][292] = 1;
TABLE[268][304] = 1;
TABLE[268][43] = 1;
TABLE[268][45] = 1;
TABLE[268][40] = 1;
TABLE[268][278] = 1;
TABLE[268][37] = 1;
TABLE[268][47] = 1;
TABLE[268][42] = 1;
TABLE[268][294] = 1;
TABLE[268][295] = 1;
TABLE[268][302] = 1;
TABLE[268][300] = 1;
TABLE[268][303] = 1;
TABLE[268][33] = 1;
TABLE[268][126] = 1;
TABLE[268][301] = 1;
TABLE[268][289] = 1;
TABLE[268][308] = 1;
TABLE[268][306] = 1;
TABLE[268][307] = 1;
TABLE[268][299] = 1;
TABLE[268][63] = 1;
TABLE[268][59] = 1;
TABLE[268][93] = 1;
TABLE[268][41] = 1;
TABLE[268][298] = 1;
TABLE[268][297] = 1;
TABLE[268][125] = 1;
TABLE[268][58] = 1;
TABLE[268][44] = 1;
TABLE[85][63] = 1;
TABLE[85][59] = 1;
TABLE[85][93] = 1;
TABLE[85][41] = 1;
TABLE[85][298] = 1;
TABLE[85][297] = 1;
TABLE[85][125] = 1;
TABLE[85][58] = 1;
TABLE[85][44] = 1;
TABLE[85][292] = 1;
TABLE[85][304] = 1;
TABLE[85][40] = 1;
TABLE[85][45] = 1;
TABLE[85][43] = 1;
TABLE[85][42] = 1;
TABLE[85][47] = 1;
TABLE[85][37] = 1;
TABLE[85][278] = 1;
TABLE[85][295] = 1;
TABLE[85][294] = 1;
TABLE[85][289] = 1;
TABLE[85][301] = 1;
TABLE[85][126] = 1;
TABLE[85][33] = 1;
TABLE[85][303] = 1;
TABLE[85][300] = 1;
TABLE[85][302] = 1;
TABLE[85][299] = 1;
TABLE[85][307] = 1;
TABLE[85][306] = 1;
TABLE[85][308] = 1;
TABLE[190][292] = 1;
TABLE[190][304] = 1;
TABLE[190][43] = 1;
TABLE[190][45] = 1;
TABLE[190][40] = 1;
TABLE[190][278] = 1;
TABLE[190][37] = 1;
TABLE[190][47] = 1;
TABLE[190][42] = 1;
TABLE[190][294] = 1;
TABLE[190][295] = 1;
TABLE[190][302] = 1;
TABLE[190][300] = 1;
TABLE[190][303] = 1;
TABLE[190][33] = 1;
TABLE[190][126] = 1;
TABLE[190][301] = 1;
TABLE[190][289] = 1;
TABLE[190][308] = 1;
TABLE[190][306] = 1;
TABLE[190][307] = 1;
TABLE[190][299] = 1;
TABLE[269][304] = 1;
TABLE[269][40] = 1;
TABLE[269][45] = 1;
TABLE[269][43] = 1;
TABLE[269][42] = 1;
TABLE[269][47] = 1;
TABLE[269][37] = 1;
TABLE[269][278] = 1;
TABLE[269][295] = 1;
TABLE[269][294] = 1;
TABLE[269][289] = 1;
TABLE[269][301] = 1;
TABLE[269][126] = 1;
TABLE[269][33] = 1;
TABLE[269][303] = 1;
TABLE[269][300] = 1;
TABLE[269][302] = 1;
TABLE[269][299] = 1;
TABLE[269][307] = 1;
TABLE[269][306] = 1;
TABLE[269][308] = 1;
TABLE[269][63] = 1;
TABLE[269][59] = 1;
TABLE[269][93] = 1;
TABLE[269][41] = 1;
TABLE[269][292] = 1;
TABLE[269][298] = 1;
TABLE[269][297] = 1;
TABLE[269][125] = 1;
TABLE[269][58] = 1;
TABLE[269][44] = 1;
TABLE[86][63] = 1;
TABLE[86][59] = 1;
TABLE[86][93] = 1;
TABLE[86][41] = 1;
TABLE[86][292] = 1;
TABLE[86][298] = 1;
TABLE[86][297] = 1;
TABLE[86][125] = 1;
TABLE[86][58] = 1;
TABLE[86][44] = 1;
TABLE[86][304] = 1;
TABLE[86][43] = 1;
TABLE[86][45] = 1;
TABLE[86][40] = 1;
TABLE[86][278] = 1;
TABLE[86][37] = 1;
TABLE[86][47] = 1;
TABLE[86][42] = 1;
TABLE[86][294] = 1;
TABLE[86][295] = 1;
TABLE[86][302] = 1;
TABLE[86][300] = 1;
TABLE[86][303] = 1;
TABLE[86][33] = 1;
TABLE[86][126] = 1;
TABLE[86][301] = 1;
TABLE[86][289] = 1;
TABLE[86][308] = 1;
TABLE[86][306] = 1;
TABLE[86][307] = 1;
TABLE[86][299] = 1;
TABLE[191][304] = 1;
TABLE[191][40] = 1;
TABLE[191][45] = 1;
TABLE[191][43] = 1;
TABLE[191][42] = 1;
TABLE[191][47] = 1;
TABLE[191][37] = 1;
TABLE[191][278] = 1;
TABLE[191][295] = 1;
TABLE[191][294] = 1;
TABLE[191][289] = 1;
TABLE[191][301] = 1;
TABLE[191][126] = 1;
TABLE[191][33] = 1;
TABLE[191][303] = 1;
TABLE[191][300] = 1;
TABLE[191][302] = 1;
TABLE[191][299] = 1;
TABLE[191][307] = 1;
TABLE[191][306] = 1;
TABLE[191][308] = 1;
TABLE[270][43] = 1;
TABLE[270][45] = 1;
TABLE[270][40] = 1;
TABLE[270][278] = 1;
TABLE[270][37] = 1;
TABLE[270][47] = 1;
TABLE[270][42] = 1;
TABLE[270][294] = 1;
TABLE[270][295] = 1;
TABLE[270][302] = 1;
TABLE[270][300] = 1;
TABLE[270][303] = 1;
TABLE[270][33] = 1;
TABLE[270][126] = 1;
TABLE[270][301] = 1;
TABLE[270][289] = 1;
TABLE[270][308] = 1;
TABLE[270][306] = 1;
TABLE[270][307] = 1;
TABLE[270][299] = 1;
TABLE[270][63] = 1;
TABLE[270][59] = 1;
TABLE[270][93] = 1;
TABLE[270][41] = 1;
TABLE[270][304] = 1;
TABLE[270][292] = 1;
TABLE[270][298] = 1;
TABLE[270][297] = 1;
TABLE[270][125] = 1;
TABLE[270][58] = 1;
TABLE[270][44] = 1;
TABLE[87][63] = 1;
TABLE[87][59] = 1;
TABLE[87][93] = 1;
TABLE[87][41] = 1;
TABLE[87][304] = 1;
TABLE[87][292] = 1;
TABLE[87][298] = 1;
TABLE[87][297] = 1;
TABLE[87][125] = 1;
TABLE[87][58] = 1;
TABLE[87][44] = 1;
TABLE[87][45] = 1;
TABLE[87][43] = 1;
TABLE[87][40] = 1;
TABLE[87][42] = 1;
TABLE[87][47] = 1;
TABLE[87][37] = 1;
TABLE[87][278] = 1;
TABLE[87][295] = 1;
TABLE[87][294] = 1;
TABLE[87][289] = 1;
TABLE[87][301] = 1;
TABLE[87][126] = 1;
TABLE[87][33] = 1;
TABLE[87][303] = 1;
TABLE[87][300] = 1;
TABLE[87][302] = 1;
TABLE[87][299] = 1;
TABLE[87][307] = 1;
TABLE[87][306] = 1;
TABLE[87][308] = 1;
TABLE[194][43] = 1;
TABLE[194][45] = 1;
TABLE[194][40] = 1;
TABLE[194][278] = 1;
TABLE[194][37] = 1;
TABLE[194][47] = 1;
TABLE[194][42] = 1;
TABLE[194][294] = 1;
TABLE[194][295] = 1;
TABLE[194][302] = 1;
TABLE[194][300] = 1;
TABLE[194][303] = 1;
TABLE[194][33] = 1;
TABLE[194][126] = 1;
TABLE[194][301] = 1;
TABLE[194][289] = 1;
TABLE[194][308] = 1;
TABLE[194][306] = 1;
TABLE[194][307] = 1;
TABLE[194][299] = 1;
TABLE[271][40] = 1;
TABLE[271][42] = 1;
TABLE[271][47] = 1;
TABLE[271][37] = 1;
TABLE[271][278] = 1;
TABLE[271][295] = 1;
TABLE[271][294] = 1;
TABLE[271][289] = 1;
TABLE[271][301] = 1;
TABLE[271][43] = 1;
TABLE[271][45] = 1;
TABLE[271][126] = 1;
TABLE[271][33] = 1;
TABLE[271][303] = 1;
TABLE[271][300] = 1;
TABLE[271][302] = 1;
TABLE[271][299] = 1;
TABLE[271][307] = 1;
TABLE[271][306] = 1;
TABLE[271][308] = 1;
TABLE[271][63] = 1;
TABLE[271][59] = 1;
TABLE[271][93] = 1;
TABLE[271][41] = 1;
TABLE[271][304] = 1;
TABLE[271][292] = 1;
TABLE[271][298] = 1;
TABLE[271][297] = 1;
TABLE[271][125] = 1;
TABLE[271][58] = 1;
TABLE[271][44] = 1;
TABLE[192][43] = 1;
TABLE[193][45] = 1;
TABLE[88][40] = 1;
TABLE[88][37] = 1;
TABLE[88][47] = 1;
TABLE[88][42] = 1;
TABLE[88][278] = 1;
TABLE[88][294] = 1;
TABLE[88][295] = 1;
TABLE[88][302] = 1;
TABLE[88][300] = 1;
TABLE[88][303] = 1;
TABLE[88][33] = 1;
TABLE[88][126] = 1;
TABLE[88][45] = 1;
TABLE[88][43] = 1;
TABLE[88][301] = 1;
TABLE[88][289] = 1;
TABLE[88][308] = 1;
TABLE[88][306] = 1;
TABLE[88][307] = 1;
TABLE[88][299] = 1;
TABLE[198][40] = 1;
TABLE[198][42] = 1;
TABLE[198][47] = 1;
TABLE[198][37] = 1;
TABLE[198][278] = 1;
TABLE[198][295] = 1;
TABLE[198][294] = 1;
TABLE[198][289] = 1;
TABLE[198][301] = 1;
TABLE[198][43] = 1;
TABLE[198][45] = 1;
TABLE[198][126] = 1;
TABLE[198][33] = 1;
TABLE[198][303] = 1;
TABLE[198][300] = 1;
TABLE[198][302] = 1;
TABLE[198][299] = 1;
TABLE[198][307] = 1;
TABLE[198][306] = 1;
TABLE[198][308] = 1;
TABLE[272][40] = 1;
TABLE[272][278] = 1;
TABLE[272][294] = 1;
TABLE[272][295] = 1;
TABLE[272][302] = 1;
TABLE[272][300] = 1;
TABLE[272][303] = 1;
TABLE[272][33] = 1;
TABLE[272][126] = 1;
TABLE[272][45] = 1;
TABLE[272][43] = 1;
TABLE[272][42] = 1;
TABLE[272][301] = 1;
TABLE[272][289] = 1;
TABLE[272][308] = 1;
TABLE[272][306] = 1;
TABLE[272][307] = 1;
TABLE[272][299] = 1;
TABLE[195][42] = 1;
TABLE[196][47] = 1;
TABLE[197][37] = 1;
TABLE[89][278] = 1;
TABLE[89][295] = 1;
TABLE[89][294] = 1;
TABLE[89][289] = 1;
TABLE[89][40] = 1;
TABLE[89][301] = 1;
TABLE[89][42] = 1;
TABLE[89][43] = 1;
TABLE[89][45] = 1;
TABLE[89][126] = 1;
TABLE[89][33] = 1;
TABLE[89][303] = 1;
TABLE[89][300] = 1;
TABLE[89][302] = 1;
TABLE[89][299] = 1;
TABLE[89][307] = 1;
TABLE[89][306] = 1;
TABLE[89][308] = 1;
TABLE[90][40] = 1;
TABLE[91][40] = 1;
TABLE[91][289] = 1;
TABLE[91][308] = 1;
TABLE[91][306] = 1;
TABLE[91][307] = 1;
TABLE[91][299] = 1;
TABLE[92][294] = 1;
TABLE[92][295] = 1;
TABLE[93][302] = 1;
TABLE[93][300] = 1;
TABLE[93][303] = 1;
TABLE[93][33] = 1;
TABLE[93][126] = 1;
TABLE[93][45] = 1;
TABLE[93][43] = 1;
TABLE[93][42] = 1;
TABLE[93][301] = 1;
TABLE[94][278] = 1;
TABLE[95][278] = 1;
TABLE[199][294] = 1;
TABLE[200][295] = 1;
TABLE[96][301] = 1;
TABLE[96][42] = 1;
TABLE[96][43] = 1;
TABLE[96][45] = 1;
TABLE[96][126] = 1;
TABLE[96][33] = 1;
TABLE[96][303] = 1;
TABLE[96][300] = 1;
TABLE[96][302] = 1;
TABLE[201][301] = 1;
TABLE[202][42] = 1;
TABLE[203][43] = 1;
TABLE[204][45] = 1;
TABLE[205][126] = 1;
TABLE[206][33] = 1;
TABLE[207][303] = 1;
TABLE[208][300] = 1;
TABLE[209][302] = 1;
TABLE[97][289] = 1;
TABLE[97][40] = 1;
TABLE[97][299] = 1;
TABLE[97][307] = 1;
TABLE[97][306] = 1;
TABLE[97][308] = 1;
TABLE[98][40] = 1;
TABLE[98][289] = 1;
TABLE[98][308] = 1;
TABLE[98][306] = 1;
TABLE[98][307] = 1;
TABLE[98][299] = 1;
TABLE[211][91] = 1;
TABLE[213][40] = 1;
TABLE[214][46] = 1;
TABLE[215][296] = 1;
TABLE[216][294] = 1;
TABLE[217][295] = 1;
TABLE[210][58] = 1;
TABLE[273][93] = 1;
TABLE[212][41] = 1;
TABLE[212][44] = 1;
TABLE[212][278] = 1;
TABLE[212][295] = 1;
TABLE[212][294] = 1;
TABLE[212][63] = 1;
TABLE[212][289] = 1;
TABLE[212][40] = 1;
TABLE[212][301] = 1;
TABLE[212][42] = 1;
TABLE[212][43] = 1;
TABLE[212][45] = 1;
TABLE[212][126] = 1;
TABLE[212][33] = 1;
TABLE[212][303] = 1;
TABLE[212][300] = 1;
TABLE[212][302] = 1;
TABLE[212][297] = 1;
TABLE[212][299] = 1;
TABLE[212][307] = 1;
TABLE[212][306] = 1;
TABLE[212][308] = 1;
TABLE[212][298] = 1;
TABLE[212][292] = 1;
TABLE[212][304] = 1;
TABLE[212][37] = 1;
TABLE[212][47] = 1;
TABLE[274][41] = 1;
TABLE[99][299] = 1;
TABLE[100][308] = 1;
TABLE[100][306] = 1;
TABLE[100][307] = 1;
TABLE[101][289] = 1;
TABLE[102][40] = 1;
TABLE[103][59] = 1;
TABLE[103][41] = 1;
TABLE[103][44] = 1;
TABLE[103][278] = 1;
TABLE[103][63] = 1;
TABLE[103][294] = 1;
TABLE[103][295] = 1;
TABLE[103][297] = 1;
TABLE[103][302] = 1;
TABLE[103][300] = 1;
TABLE[103][303] = 1;
TABLE[103][33] = 1;
TABLE[103][126] = 1;
TABLE[103][45] = 1;
TABLE[103][43] = 1;
TABLE[103][42] = 1;
TABLE[103][301] = 1;
TABLE[103][40] = 1;
TABLE[103][289] = 1;
TABLE[103][298] = 1;
TABLE[103][308] = 1;
TABLE[103][306] = 1;
TABLE[103][307] = 1;
TABLE[103][299] = 1;
TABLE[103][292] = 1;
TABLE[103][304] = 1;
TABLE[103][47] = 1;
TABLE[103][37] = 1;
TABLE[218][44] = 1;
TABLE[218][278] = 1;
TABLE[218][295] = 1;
TABLE[218][294] = 1;
TABLE[218][63] = 1;
TABLE[218][289] = 1;
TABLE[218][40] = 1;
TABLE[218][301] = 1;
TABLE[218][42] = 1;
TABLE[218][43] = 1;
TABLE[218][45] = 1;
TABLE[218][126] = 1;
TABLE[218][33] = 1;
TABLE[218][303] = 1;
TABLE[218][300] = 1;
TABLE[218][302] = 1;
TABLE[218][297] = 1;
TABLE[218][299] = 1;
TABLE[218][307] = 1;
TABLE[218][306] = 1;
TABLE[218][308] = 1;
TABLE[218][298] = 1;
TABLE[218][292] = 1;
TABLE[218][304] = 1;
TABLE[218][37] = 1;
TABLE[218][47] = 1;
TABLE[275][278] = 1;
TABLE[275][63] = 1;
TABLE[275][294] = 1;
TABLE[275][295] = 1;
TABLE[275][297] = 1;
TABLE[275][302] = 1;
TABLE[275][300] = 1;
TABLE[275][303] = 1;
TABLE[275][33] = 1;
TABLE[275][126] = 1;
TABLE[275][45] = 1;
TABLE[275][43] = 1;
TABLE[275][42] = 1;
TABLE[275][301] = 1;
TABLE[275][40] = 1;
TABLE[275][289] = 1;
TABLE[275][298] = 1;
TABLE[275][308] = 1;
TABLE[275][306] = 1;
TABLE[275][307] = 1;
TABLE[275][299] = 1;
TABLE[275][292] = 1;
TABLE[275][304] = 1;
TABLE[275][47] = 1;
TABLE[275][37] = 1;
TABLE[275][59] = 1;
TABLE[275][41] = 1;
TABLE[275][44] = 1;
TABLE[104][308] = 1;
TABLE[105][306] = 1;
TABLE[106][307] = 1;
TABLE[107][299] = 1;
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
      case 652: return 0; break;
      case 671: return 1; break;
      case 676: return 1; break;
      case 683: return 0; break;
      case 690: return 1; break;
      case 697: return 1; break;
      case 704: return 1; break;
      case 709: return 1; break;
      case 717: return 0; break;
      case 734: return 1; break;
      case 742: return 0; break;
      case 772: return 1; break;
      case 779: return 1; break;
      case 786: return 1; break;
      case 793: return 0; break;
      case 815: return 1; break;
      case 822: return 0; break;
      case 828: return 0; break;
      case 835: return 1; break;
      case 844: return 1; break;
      case 849: return 1; break;
      case 857: return 1; break;
      case 867: return 0; break;
      case 875: return 1; break;
      case 880: return 1; break;
      case 890: return 1; break;
      case 894: return 1; break;
      case 899: return 1; break;
      case 907: return 1; break;
      case 912: return 1; break;
      case 920: return 1; break;
      case 925: return 1; break;
      case 933: return 1; break;
      case 938: return 1; break;
      case 946: return 1; break;
      case 951: return 1; break;
      case 959: return 1; break;
      case 964: return 1; break;
      case 972: return 1; break;
      case 977: return 1; break;
      case 985: return 1; break;
      case 990: return 1; break;
      case 998: return 0; break;
      case 1006: return 1; break;
      case 1011: return 1; break;
      case 1019: return 0; break;
      case 1031: return 0; break;
      case 1042: return 0; break;
      case 1068: return 0; break;
      case 1076: return 0; break;
      case 1080: return 0; break;
      case 1116: return 0; break;
      case 1125: return 0; break;
      case 1156: return 1; break;
      case 1164: return 1; break;
      case 1171: return 0; break;
      case 1189: return 1; break;
      case 1194: return 1; break;
      case 1202: return 0; break;
      case 1214: return 0; break;
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
         case 652: return "labeled_statement"; break;
         case 671: return "expression_statement"; break;
         case 676: return "Subphrase"; break;
         case 683: return "compound_statement"; break;
         case 690: return "Subphrase"; break;
         case 697: return "Subphrase"; break;
         case 704: return "statement_list"; break;
         case 709: return "Subphrase"; break;
         case 717: return "selection_statement"; break;
         case 734: return "Subphrase"; break;
         case 742: return "iteration_statement"; break;
         case 772: return "Subphrase"; break;
         case 779: return "Subphrase"; break;
         case 786: return "Subphrase"; break;
         case 793: return "jump_statement"; break;
         case 815: return "Subphrase"; break;
         case 822: return "print_statement"; break;
         case 828: return "input_statement"; break;
         case 835: return "Subphrase"; break;
         case 844: return "expression"; break;
         case 849: return "Subphrase"; break;
         case 857: return "assignment_expression"; break;
         case 867: return "assignment_operator"; break;
         case 875: return "conditional_expression"; break;
         case 880: return "Subphrase"; break;
         case 890: return "constant_expression"; break;
         case 894: return "logical_OR_expression"; break;
         case 899: return "Subphrase"; break;
         case 907: return "logical_AND_expression"; break;
         case 912: return "Subphrase"; break;
         case 920: return "inclusive_OR_expression"; break;
         case 925: return "Subphrase"; break;
         case 933: return "exclusive_OR_expression"; break;
         case 938: return "Subphrase"; break;
         case 946: return "AND_expression"; break;
         case 951: return "Subphrase"; break;
         case 959: return "equality_expression"; break;
         case 964: return "Subphrase"; break;
         case 972: return "shift_expression"; break;
         case 977: return "Subphrase"; break;
         case 985: return "additive_expression"; break;
         case 990: return "Subphrase"; break;
         case 998: return "Subphrase"; break;
         case 1006: return "multiplicative_expression"; break;
         case 1011: return "Subphrase"; break;
         case 1019: return "Subphrase"; break;
         case 1031: return "cast_expression"; break;
         case 1042: return "unary_expression"; break;
         case 1068: return "Subphrase"; break;
         case 1076: return "unary_operator"; break;
         case 1080: return "Subphrase"; break;
         case 1116: return "postfix_expression"; break;
         case 1125: return "Subphrase"; break;
         case 1156: return "Subphrase"; break;
         case 1164: return "Subphrase"; break;
         case 1171: return "primary_expression"; break;
         case 1189: return "argument_expression_list"; break;
         case 1194: return "Subphrase"; break;
         case 1202: return "constant"; break;
         case 1214: return "id"; break;
   }
   else 
      switch(n-50000) {
         case 311: return "EXP"; break;
         case 310: return "INPUT"; break;
         case 309: return "PRINT"; break;
         case 308: return "INTCONST"; break;
         case 307: return "FLOATCONST"; break;
         case 306: return "CHARACTER"; break;
         case 305: return "INCLUDE"; break;
         case 304: return "SHIFT"; break;
         case 303: return "BIT_NOT"; break;
         case 302: return "BIT_XOR"; break;
         case 301: return "BIT_AND"; break;
         case 300: return "BIT_OR"; break;
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
