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
   constant_pt i;
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
# line 281 "yygrammar.c"
      } break;
   case 10: {
      struct_or_union_specifier();
      } break;
   case 11: {
      enum_specifier();
      } break;
   case 12: {
      id(&i);
#line 131 "ass3.acc"

# line 293 "yygrammar.c"
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
# line 313 "yygrammar.c"
      } break;
   }
}

struct_or_union_specifier ()
{
   constant_pt i;
   switch(yyselect()) {
   case 14: {
      struct_or_union();
      switch (yyselect()) {
      case 135: {
         id(&i);
         } break;
      default: ;
      }
      get_lexval();
#line 140 "ass3.acc"
 fputs("\\{\\\\\n", out); 
# line 333 "yygrammar.c"
      struct_declaration_list();
      get_lexval();
#line 140 "ass3.acc"
 fputs("\\}\\\\\n", out); 
# line 338 "yygrammar.c"
      } break;
   case 15: {
      struct_or_union();
      id(&i);
#line 141 "ass3.acc"

# line 345 "yygrammar.c"
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
# line 365 "yygrammar.c"
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
# line 395 "yygrammar.c"
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
# line 414 "yygrammar.c"
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
# line 432 "yygrammar.c"
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
# line 470 "yygrammar.c"
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
# line 495 "yygrammar.c"
      constant_expression();
      } break;
   }
}

enum_specifier ()
{
   constant_pt i;
   switch(yyselect()) {
   case 25: {
      get_lexval();
#line 178 "ass3.acc"
 PRKW; 
# line 509 "yygrammar.c"
      switch (yyselect()) {
      case 146: {
         id(&i);
         } break;
      default: ;
      }
#line 178 "ass3.acc"
 fputs("\\{\\\\\n", out); 
# line 518 "yygrammar.c"
      get_lexval();
      enumerator_list();
      get_lexval();
#line 178 "ass3.acc"
 fputs("\\}\\\\\n", out); 
# line 524 "yygrammar.c"
      } break;
   case 26: {
      get_lexval();
#line 179 "ass3.acc"
 PRKW; 
# line 530 "yygrammar.c"
      id(&i);
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
# line 546 "yygrammar.c"
         } break;
      default: ;
      }
      enumerator();
      } break;
   }
}

enumerator ()
{
   constant_pt i;
   switch(yyselect()) {
   case 28: {
      id(&i);
      switch (yyselect()) {
      case 148: {
         get_lexval();
#line 187 "ass3.acc"
 SPRCHS; 
# line 566 "yygrammar.c"
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
   constant_pt i;
   expression_pt e;
   switch(yyselect()) {
   case 30: {
      id(&i);
      } break;
   case 31: {
      get_lexval();
#line 196 "ass3.acc"
 PRCH; 
# line 602 "yygrammar.c"
      declarator();
      get_lexval();
#line 196 "ass3.acc"
 PRCH; 
# line 607 "yygrammar.c"
      } break;
   case 32: {
      direct_declarator();
      switch (yyselect()) {
      case 151: {
         get_lexval();
#line 197 "ass3.acc"
 PRCH; 
# line 616 "yygrammar.c"
         switch (yyselect()) {
         case 150: {
            expression(&e);
            } break;
         default: ;
         }
         get_lexval();
#line 197 "ass3.acc"
 PRCH; 
# line 626 "yygrammar.c"
         } break;
      case 152: {
         get_lexval();
#line 198 "ass3.acc"
 PRCH; 
# line 632 "yygrammar.c"
         parameter_type_list();
         get_lexval();
#line 198 "ass3.acc"
 PRCH; 
# line 637 "yygrammar.c"
         } break;
      case 154: {
         get_lexval();
#line 199 "ass3.acc"
 PRCH; 
# line 643 "yygrammar.c"
         switch (yyselect()) {
         case 153: {
            identifier_list();
            } break;
         default: ;
         }
         get_lexval();
#line 199 "ass3.acc"
 PRCH; 
# line 653 "yygrammar.c"
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
# line 668 "yygrammar.c"
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
# line 710 "yygrammar.c"
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
# line 729 "yygrammar.c"
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
   constant_pt i;
   switch(yyselect()) {
   case 38: {
      switch (yyselect()) {
      case 163: {
         identifier_list();
         get_lexval();
#line 223 "ass3.acc"
 PRCHS; 
# line 772 "yygrammar.c"
         } break;
      default: ;
      }
      id(&i);
      } break;
   }
}

initializer ()
{
   expression_pt ae;
   switch(yyselect()) {
   case 39: {
      assignment_expression(&ae);
      } break;
   case 40: {
      get_lexval();
#line 228 "ass3.acc"
 fputs("\\{", out); 
# line 792 "yygrammar.c"
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
# line 803 "yygrammar.c"
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
# line 818 "yygrammar.c"
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
   expression_pt e;
   switch(yyselect()) {
   case 45: {
      get_lexval();
#line 245 "ass3.acc"
 PRCH; 
# line 868 "yygrammar.c"
      abstract_declarator();
      get_lexval();
#line 245 "ass3.acc"
 PRCH; 
# line 873 "yygrammar.c"
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
# line 887 "yygrammar.c"
         switch (yyselect()) {
         case 169: {
            expression(&e);
            } break;
         default: ;
         }
         get_lexval();
#line 246 "ass3.acc"
 PRCH; 
# line 897 "yygrammar.c"
         } break;
      case 172: {
         get_lexval();
#line 247 "ass3.acc"
 PRCH; 
# line 903 "yygrammar.c"
         switch (yyselect()) {
         case 171: {
            parameter_type_list();
            } break;
         default: ;
         }
         get_lexval();
#line 247 "ass3.acc"
 PRCH; 
# line 913 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

typedef_name ()
{
   constant_pt i;
   switch(yyselect()) {
   case 47: {
      id(&i);
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
   constant_pt i;
   switch(yyselect()) {
   case 56: {
      id(&i);
      get_lexval();
#line 266 "ass3.acc"
 PRCHS; 
# line 970 "yygrammar.c"
      statement();
      } break;
   case 57: {
      get_lexval();
#line 267 "ass3.acc"
 PRKW; 
# line 977 "yygrammar.c"
      constant_expression();
      get_lexval();
#line 267 "ass3.acc"
 PRCHS; 
# line 982 "yygrammar.c"
      statement();
      } break;
   case 58: {
      get_lexval();
#line 268 "ass3.acc"
 PRKW; 
# line 989 "yygrammar.c"
      get_lexval();
#line 268 "ass3.acc"
 PRCHS; 
# line 993 "yygrammar.c"
      statement();
      } break;
   }
}

expression_statement ()
{
   expression_pt e;
   switch(yyselect()) {
   case 59: {
      switch (yyselect()) {
      case 173: {
         expression(&e);
         } break;
      default: ;
      }
      get_lexval();
#line 272 "ass3.acc"
 PRSC; 
# line 1013 "yygrammar.c"
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
# line 1025 "yygrammar.c"
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
# line 1041 "yygrammar.c"
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
   expression_pt e;
   switch(yyselect()) {
   case 62: {
      get_lexval();
#line 289 "ass3.acc"
 PRKW; 
# line 1072 "yygrammar.c"
      get_lexval();
#line 289 "ass3.acc"
 PRCH; 
# line 1076 "yygrammar.c"
      expression(&e);
      get_lexval();
#line 289 "ass3.acc"
 PRCH; 
# line 1081 "yygrammar.c"
      statement();
      switch (yyselect()) {
      case 177: {
         get_lexval();
#line 289 "ass3.acc"
 PRKW; 
# line 1088 "yygrammar.c"
         statement();
         } break;
      default: ;
      }
      } break;
   case 63: {
      get_lexval();
#line 290 "ass3.acc"
 PRKW; 
# line 1098 "yygrammar.c"
      get_lexval();
#line 290 "ass3.acc"
 PRCH; 
# line 1102 "yygrammar.c"
      expression(&e);
      get_lexval();
#line 290 "ass3.acc"
 PRCH; 
# line 1107 "yygrammar.c"
      statement();
      } break;
   }
}

iteration_statement ()
{
   expression_pt e;
   switch(yyselect()) {
   case 64: {
      get_lexval();
#line 294 "ass3.acc"
 PRKW; 
# line 1121 "yygrammar.c"
      get_lexval();
#line 294 "ass3.acc"
 PRCH; 
# line 1125 "yygrammar.c"
      expression(&e);
      get_lexval();
#line 294 "ass3.acc"
 PRCH; 
# line 1130 "yygrammar.c"
      statement();
      } break;
   case 65: {
      get_lexval();
#line 295 "ass3.acc"
 PRKW; 
# line 1137 "yygrammar.c"
      statement();
      get_lexval();
#line 295 "ass3.acc"
 PRKW; 
# line 1142 "yygrammar.c"
      get_lexval();
#line 295 "ass3.acc"
 PRCH; 
# line 1146 "yygrammar.c"