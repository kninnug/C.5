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
   case 109: {
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
         case 110: {
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
      case 111: {
         declaration_specifiers();
         } break;
      default: ;
      }
      declarator();
      switch (yyselect()) {
      case 112: {
         declaration_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 113: {
         get_lexval();
         } break;
      case 114: {
         compound_statement();
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
      case 115: {
         init_declarator_list();
         } break;
      default: ;
      }
      get_lexval();
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
         case 116: {
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
         case 117: {
            storage_class_specifier();
            } break;
         case 118: {
            type_specifier();
            } break;
         case 119: {
            type_qualifier();
            } break;
         default: goto yy3;
         }
      }
      yy3: ;
      } break;
   }
}

storage_class_specifier ()
{
   switch(yyselect()) {
   case 8: {
      switch (yyselect()) {
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
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

type_specifier ()
{
   constant_pt i;
   switch(yyselect()) {
   case 9: {
      switch (yyselect()) {
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
      case 133: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   case 10: {
      struct_or_union_specifier();
      } break;
   case 11: {
      enum_specifier();
      } break;
   case 12: {
      id(&i);
#line 130 "ass3.acc"

# line 275 "yygrammar.c"
      } break;
   }
}

type_qualifier ()
{
   switch(yyselect()) {
   case 13: {
      switch (yyselect()) {
      case 134: {
         get_lexval();
         } break;
      case 135: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
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
      case 136: {
         id(&i);
         } break;
      default: ;
      }
      get_lexval();
      struct_declaration_list();
      get_lexval();
      } break;
   case 15: {
      struct_or_union();
      id(&i);
#line 140 "ass3.acc"

# line 318 "yygrammar.c"
      } break;
   }
}

struct_or_union ()
{
   switch(yyselect()) {
   case 16: {
      switch (yyselect()) {
      case 137: {
         get_lexval();
         } break;
      case 138: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

struct_declaration_list ()
{
   switch(yyselect()) {
   case 17: {
      switch (yyselect()) {
      case 139: {
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
      case 140: {
         init_declarator_list();
         get_lexval();
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
      case 141: {
         declarator();
         get_lexval();
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
      } break;
   }
}

specifier_qualifier_list ()
{
   switch(yyselect()) {
   case 21: {
      switch (yyselect()) {
      case 142: {
         type_specifier();
         } break;
      case 143: {
         type_qualifier();
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 144: {
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
      case 145: {
         struct_declarator_list();
         get_lexval();
         } break;
      default: ;
      }
      struct_declarator();
      } break;
   }
}

struct_declarator ()
{
   expression_pt ce;
   switch(yyselect()) {
   case 23: {
      declarator();
      } break;
   case 24: {
      switch (yyselect()) {
      case 146: {
         declarator();
         } break;
      default: ;
      }
      get_lexval();
      constant_expression(&ce);
      } break;
   }
}

enum_specifier ()
{
   constant_pt i;
   switch(yyselect()) {
   case 25: {
      get_lexval();
      switch (yyselect()) {
      case 147: {
         id(&i);
         } break;
      default: ;
      }
      get_lexval();
      enumerator_list();
      get_lexval();
      } break;
   case 26: {
      get_lexval();
      id(&i);
      } break;
   }
}

enumerator_list ()
{
   switch(yyselect()) {
   case 27: {
      switch (yyselect()) {
      case 148: {
         enumerator_list();
         get_lexval();
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
   expression_pt ce;
   switch(yyselect()) {
   case 28: {
      id(&i);
      switch (yyselect()) {
      case 149: {
         get_lexval();
         constant_expression(&ce);
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
      case 150: {
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
      declarator();
      get_lexval();
      } break;
   case 32: {
      direct_declarator();
      switch (yyselect()) {
      case 152: {
         get_lexval();
         switch (yyselect()) {
         case 151: {
            expression(&e);
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 153: {
         get_lexval();
         parameter_type_list();
         get_lexval();
         } break;
      case 155: {
         get_lexval();
         switch (yyselect()) {
         case 154: {
            identifier_list();
            } break;
         default: ;
         }
         get_lexval();
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
      switch (yyselect()) {
      case 156: {
         type_qualifier_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 157: {
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
      case 158: {
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
      case 159: {
         get_lexval();
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
      case 160: {
         parameter_list();
         get_lexval();
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
      case 161: {
         declarator();
         } break;
      case 163: {
         switch (yyselect()) {
         case 162: {
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
      case 164: {
         identifier_list();
         get_lexval();
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
      initializer_list();
      switch (yyselect()) {
      case 165: {
         get_lexval();
         } break;
      default: ;
      }
      get_lexval();
      } break;
   }
}

initializer_list ()
{
   switch(yyselect()) {
   case 41: {
      switch (yyselect()) {
      case 166: {
         initializer_list();
         get_lexval();
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
      case 167: {
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
      case 168: {
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
      abstract_declarator();
      get_lexval();
      } break;
   case 46: {
      switch (yyselect()) {
      case 169: {
         direct_abstract_declarator();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 171: {
         get_lexval();
         switch (yyselect()) {
         case 170: {
            expression(&e);
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 173: {
         get_lexval();
         switch (yyselect()) {
         case 172: {
            parameter_type_list();
            } break;
         default: ;
         }
         get_lexval();
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
   expression_pt ce;
   switch(yyselect()) {
   case 56: {
      id(&i);
      get_lexval();
      statement();
      } break;
   case 57: {
      get_lexval();
      constant_expression(&ce);
      get_lexval();
      statement();
      } break;
   case 58: {
      get_lexval();
      get_lexval();
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
      case 174: {
         expression(&e);
         } break;
      default: ;
      }
      get_lexval();
      } break;
   }
}

compound_statement ()
{
   switch(yyselect()) {
   case 60: {
      get_lexval();
      switch (yyselect()) {
      case 175: {
         declaration_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 176: {
         statement_list();
         } break;
      default: ;
      }
      get_lexval();
      } break;
   }
}

statement_list ()
{
   switch(yyselect()) {
   case 61: {
      while (1) {
         switch (yyselect()) {
         case 177: {
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
      get_lexval();
      expression(&e);
      get_lexval();
      statement();
      switch (yyselect()) {
      case 178: {
         get_lexval();
         statement();
         } break;
      default: ;
      }
      } break;
   case 63: {
      get_lexval();
      get_lexval();
      expression(&e);
      get_lexval();
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
      get_lexval();
#line 293 "ass3.acc"
 PRCH; 
# line 954 "yygrammar.c"
      expression(&e);
      get_lexval();
#line 293 "ass3.acc"
 PRCH; 
# line 959 "yygrammar.c"
      statement();
      } break;
   case 65: {
      get_lexval();
#line 294 "ass3.acc"
 PRKW; 
# line 966 "yygrammar.c"
      statement();
      get_lexval();
#line 294 "ass3.acc"
 PRKW; 
# line 971 "yygrammar.c"
      get_lexval();
#line 294 "ass3.acc"
 PRCH; 
# line 975 "yygrammar.c"
      expression(&e);
      get_lexval();
#line 294 "ass3.acc"
 PRCH; 
# line 980 "yygrammar.c"
      get_lexval();
      } break;
   case 66: {
      get_lexval();
#line 295 "ass3.acc"
 PRKW; 
# line 987 "yygrammar.c"
      get_lexval();
#line 295 "ass3.acc"
 PRCH; 
# line 991 "yygrammar.c"
      switch (yyselect()) {
      case 179: {
         expression(&e);
         } break;
      default: ;
      }
      get_lexval();
      switch (yyselect()) {
      case 180: {
         expression(&e);
         } break;
      default: ;
      }
      get_lexval();
      switch (yyselect()) {
      case 181: {
         expression(&e);
         } break;
      default: ;
      }
      get_lexval();
#line 295 "ass3.acc"
 PRCH; 
# line 1015 "yygrammar.c"
      statement();
      } break;
   }
}

jump_statement ()
{
   constant_pt i;
   expression_pt e;
   switch(yyselect()) {
   case 67: {
      get_lexval();
#line 299 "ass3.acc"
 PRKW; 
# line 1030 "yygrammar.c"
      id(&i);
      get_lexval();
      } break;
   case 68: {
      get_lexval();
#line 300 "ass3.acc"
 PRKW; 
# line 1038 "yygrammar.c"
      get_lexval();
      } break;
   case 69: {
      get_lexval();
#line 301 "ass3.acc"
 PRKW; 
# line 1045 "yygrammar.c"
      get_lexval();
      } break;
   case 70: {
      get_lexval();
#line 302 "ass3.acc"
 PRKW; 
# line 1052 "yygrammar.c"
      switch (yyselect()) {
      case 182: {
         expression(&e);
         } break;
      default: ;
      }
      get_lexval();
      } break;
   }
}

print_statement ()
{
   expression_pt ae;
   switch(yyselect()) {
   case 71: {
      get_lexval();
#line 306 "ass3.acc"
 PRKW; 
# line 1072 "yygrammar.c"
      argument_expression_list(&ae);
      get_lexval();
      } break;
   }
}

input_statement ()
{
   constant_pt i;
   switch(yyselect()) {
   case 72: {
      get_lexval();
#line 310 "ass3.acc"
 PRKW; 
# line 1087 "yygrammar.c"
      while (1) {
         switch (yyselect()) {
         case 183: {
            id(&i);
            get_lexval();
            } break;
         default: goto yy5;
         }
      }
      yy5: ;
      id(&i);
      get_lexval();
      } break;
   }
}

expression (ret)
   expression_pt *ret;
{
   expression_pt e;
   expression_pt ae;
   switch(yyselect()) {
   case 73: {
#line 314 "ass3.acc"
 *ret = makeExpression(1, 0, ','); 
# line 1113 "yygrammar.c"
      switch (yyselect()) {
      case 184: {
         expression(&e);
#line 314 "ass3.acc"
 appendExpression(*ret, e); 
# line 1119 "yygrammar.c"
         get_lexval();
         } break;
      default: ;
      }
      assignment_expression(&ae);
#line 314 "ass3.acc"
 appendExpression(*ret, ae); printExpression(*ret); 
# line 1127 "yygrammar.c"
      } break;
   }
}

assignment_expression (ret)
   expression_pt *ret;
{
   expression_pt ce;
   expression_pt ue;
   expression_pt ae;
   switch(yyselect()) {
   case 74: {
      conditional_expression(&ce);
#line 318 "ass3.acc"
 *ret = ce; 
# line 1143 "yygrammar.c"
      } break;
   case 75: {
#line 319 "ass3.acc"
 *ret = makeExpression(1, 0, '='); 
# line 1148 "yygrammar.c"
      unary_expression(&ue);
#line 319 "ass3.acc"
 appendExpression(*ret, ue); 
# line 1152 "yygrammar.c"
      assignment_operator();
      assignment_expression(&ae);
#line 319 "ass3.acc"
 appendExpression(*ret, ae); 
# line 1157 "yygrammar.c"
      } break;
   }
}

assignment_operator ()
{
   switch(yyselect()) {
   case 76: {
      get_lexval();
      } break;
   case 77: {
      get_lexval();
      } break;
   }
}

conditional_expression (ret)
   expression_pt *ret;
{
   expression_pt loe;
   expression_pt e;
   expression_pt ce;
   switch(yyselect()) {
   case 78: {
      logical_OR_expression(&loe);
#line 328 "ass3.acc"
 *ret = loe; 
# line 1185 "yygrammar.c"
      } break;
   case 79: {
      logical_OR_expression(&loe);
      get_lexval();
      expression(&e);
      get_lexval();
      conditional_expression(&ce);
#line 329 "ass3.acc"
 *ret = makeExpression(1, 3, '?', loe, e, ce); 
# line 1195 "yygrammar.c"
      } break;
   }
}

constant_expression (ret)
   expression_pt *ret;
{
   expression_pt ce;
   switch(yyselect()) {
   case 80: {
      conditional_expression(&ce);
#line 333 "ass3.acc"
 *ret = ce; 
# line 1209 "yygrammar.c"
      } break;
   }
}

logical_OR_expression (ret)
   expression_pt *ret;
{
   expression_pt loe;
   expression_pt lae;
   switch(yyselect()) {
   case 81: {
#line 337 "ass3.acc"
 *ret = makeExpression(1, 0, '||'); 
# line 1223 "yygrammar.c"
      switch (yyselect()) {
      case 185: {
         logical_OR_expression(&loe);
#line 337 "ass3.acc"
 appendExpression(*ret, loe); 
# line 1229 "yygrammar.c"
         get_lexval();
         } break;
      default: ;
      }
      logical_AND_expression(&lae);
#line 337 "ass3.acc"
 appendExpression(*ret, lae); 
# line 1237 "yygrammar.c"
      } break;
   }
}

logical_AND_expression (ret)
   expression_pt *ret;
{
   expression_pt lae;
   expression_pt ioe;
   switch(yyselect()) {
   case 82: {
#line 341 "ass3.acc"
 *ret = makeExpression(1, 0, '&&'); 
# line 1251 "yygrammar.c"
      switch (yyselect()) {
      case 186: {
         logical_AND_expression(&lae);
#line 341 "ass3.acc"
 appendExpression(*ret, lae); 
# line 1257 "yygrammar.c"
         get_lexval();
         } break;
      default: ;
      }
      inclusive_OR_expression(&ioe);
#line 341 "ass3.acc"
 appendExpression(*ret, ioe); 
# line 1265 "yygrammar.c"
      } break;
   }
}

inclusive_OR_expression (ret)
   expression_pt *ret;
{
   expression_pt ioe;
   expression_pt eoe;
   switch(yyselect()) {
   case 83: {
#line 345 "ass3.acc"
 *ret = makeExpression(1, 0, '|'); 
# line 1279 "yygrammar.c"
      switch (yyselect()) {
      case 187: {
         inclusive_OR_expression(&ioe);
#line 345 "ass3.acc"
 appendExpression(*ret, ioe); 
# line 1285 "yygrammar.c"
         get_lexval();
         } break;
      default: ;
      }
      exclusive_OR_expression(&eoe);
#line 345 "ass3.acc"
 appendExpression(*ret, eoe); 
# line 1293 "yygrammar.c"
      } break;
   }
}

exclusive_OR_expression (ret)
   expression_pt *ret;
{
   expression_pt eoe;
   expression_pt ae;
   switch(yyselect()) {
   case 84: {
#line 349 "ass3.acc"
 *ret = makeExpression(1, 0, '^'); 
# line 1307 "yygrammar.c"
      switch (yyselect()) {
      case 188: {
         exclusive_OR_expression(&eoe);
#line 349 "ass3.acc"
 appendExpression(*ret, eoe); 
# line 1313 "yygrammar.c"
         get_lexval();
         } break;
      default: ;
      }
      AND_expression(&ae);
#line 349 "ass3.acc"
 appendExpression(*ret, ae); 
# line 1321 "yygrammar.c"
      } break;
   }
}

AND_expression (ret)
   expression_pt *ret;
{
   expression_pt ae;
   expression_pt ee;
   switch(yyselect()) {
   case 85: {
#line 353 "ass3.acc"
 *ret = makeExpression(1, 0, '&'); 
# line 1335 "yygrammar.c"
      switch (yyselect()) {
      case 189: {
         AND_expression(&ae);
#line 353 "ass3.acc"
 appendExpression(*ret, ae); 
# line 1341 "yygrammar.c"
         get_lexval();
         } break;
      default: ;
      }
      equality_expression(&ee);
#line 353 "ass3.acc"
 appendExpression(*ret, ee); 
# line 1349 "yygrammar.c"
      } break;
   }
}

equality_expression (ret)
   expression_pt *ret;
{
   expression_pt ee;
   expression_pt se;
   switch(yyselect()) {
   case 86: {
#line 357 "ass3.acc"
 *ret = makeExpression(1, 0, 0); 
# line 1363 "yygrammar.c"
      switch (yyselect()) {
      case 190: {
         equality_expression(&ee);
#line 357 "ass3.acc"
 appendExpression(*ret, ee); 
# line 1369 "yygrammar.c"
         get_lexval();
         } break;
      default: ;
      }
      shift_expression(&se);
#line 357 "ass3.acc"
 appendExpression(*ret, se); 
# line 1377 "yygrammar.c"
      } break;
   }
}

shift_expression (ret)
   expression_pt *ret;
{
   expression_pt se;
   expression_pt ae;
   switch(yyselect()) {
   case 87: {
#line 361 "ass3.acc"
 *ret = makeExpression(1, 0, 0); 
# line 1391 "yygrammar.c"
      switch (yyselect()) {
      case 191: {
         shift_expression(&se);
#line 361 "ass3.acc"
 appendExpression(*ret, se); 
# line 1397 "yygrammar.c"
         get_lexval();
         } break;
      default: ;
      }
      additive_expression(&ae);
#line 361 "ass3.acc"
 appendExpression(*ret, ae); 
# line 1405 "yygrammar.c"
      } break;
   }
}

additive_expression (ret)
   expression_pt *ret;
{
   expression_pt ae;
   expression_pt me;
   switch(yyselect()) {
   case 88: {
#line 365 "ass3.acc"
 *ret = makeExpression(1, 0, 0); 
# line 1419 "yygrammar.c"
      switch (yyselect()) {
      case 194: {
         additive_expression(&ae);
#line 365 "ass3.acc"
 appendExpression(*ret, ae); 
# line 1425 "yygrammar.c"
         switch (yyselect()) {
         case 192: {
            get_lexval();
            } break;
         case 193: {
            get_lexval();
            } break;
         default: printf("???\n"); exit(1);
         }
         } break;
      default: ;
      }
      multiplicative_expression(&me);
#line 365 "ass3.acc"
 appendExpression(*ret, me); 
# line 1441 "yygrammar.c"
      } break;
   }
}

multiplicative_expression (ret)
   expression_pt *ret;
{
   expression_pt me;
   expression_pt ce;
   switch(yyselect()) {
   case 89: {
#line 369 "ass3.acc"
 *ret = makeExpression(1, 0, 0); 
# line 1455 "yygrammar.c"
      switch (yyselect()) {
      case 198: {
         multiplicative_expression(&me);
#line 369 "ass3.acc"
 appendExpression(*ret, me); 
# line 1461 "yygrammar.c"
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
         } break;
      default: ;
      }
      cast_expression(&ce);
#line 369 "ass3.acc"
 appendExpression(*ret, ce); 
# line 1480 "yygrammar.c"
      } break;
   }
}

cast_expression (ret)
   expression_pt *ret;
{
   expression_pt ue;
   expression_pt ce;
   switch(yyselect()) {
   case 90: {
      unary_expression(&ue);
#line 373 "ass3.acc"
 *ret =  ue; 
# line 1495 "yygrammar.c"
      } break;
   case 91: {
      get_lexval();
      type_name();
      get_lexval();
      cast_expression(&ce);
#line 374 "ass3.acc"
 *ret = ce; 
# line 1504 "yygrammar.c"
      } break;
   }
}

unary_expression (ret)
   expression_pt *ret;
{
   expression_pt pe;
   expression_pt ue;
   expression_pt ce;
   switch(yyselect()) {
   case 92: {
      postfix_expression(&pe);
#line 378 "ass3.acc"
 *ret = pe; 
# line 1520 "yygrammar.c"
      } break;
   case 93: {
#line 379 "ass3.acc"
 int t; 
# line 1525 "yygrammar.c"
      switch (yyselect()) {
      case 199: {
         get_lexval();
#line 379 "ass3.acc"
t = '++x';
# line 1531 "yygrammar.c"
         } break;
      case 200: {
         get_lexval();
#line 379 "ass3.acc"
t = '--x'; 
# line 1537 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      unary_expression(&ue);
#line 379 "ass3.acc"
 *ret = makeExpression(1, 1, t, ue); 
# line 1544 "yygrammar.c"
      } break;
   case 94: {
      unary_operator();
      cast_expression(&ce);
      } break;
   case 95: {
      get_lexval();
      unary_expression(&ue);
      } break;
   case 96: {
      get_lexval();
      get_lexval();
      type_name();
      get_lexval();
      } break;
   }
}

unary_operator ()
{
   switch(yyselect()) {
   case 97: {
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
      } break;
   }
}

postfix_expression (ret)
   expression_pt *ret;
{
   expression_pt pe;
   expression_pt e;
   expression_pt ae;
   constant_pt i;
   switch(yyselect()) {
   case 98: {
      primary_expression(&pe);
#line 390 "ass3.acc"
 *ret = pe; 
# line 1613 "yygrammar.c"
      } break;
   case 99: {
      postfix_expression(&pe);
#line 391 "ass3.acc"
 *ret = makeExpression(1, 1, 0, pe); 
# line 1619 "yygrammar.c"
      switch (yyselect()) {
      case 211: {
         get_lexval();
         expression(&e);
#line 392 "ass3.acc"
 appendExpression(*ret, e); 
# line 1626 "yygrammar.c"
         switch (yyselect()) {
         case 210: {
            get_lexval();
            expression(&e);
#line 392 "ass3.acc"
 appendExpression(*ret, e); 
# line 1633 "yygrammar.c"
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 213: {
         get_lexval();
         switch (yyselect()) {
         case 212: {
            argument_expression_list(&ae);
#line 393 "ass3.acc"
 appendExpression(*ret, ae); 
# line 1646 "yygrammar.c"
            } break;
         default: ;
         }
         get_lexval();
#line 393 "ass3.acc"
 (*ret)->operator = '()'; 
# line 1653 "yygrammar.c"
         } break;
      case 214: {
         get_lexval();
         id(&i);
#line 394 "ass3.acc"
 appendExpression(*ret, makeExpression(0, 1, 0, i)); (*ret)->operator = '.'; 
# line 1660 "yygrammar.c"
         } break;
      case 215: {
         get_lexval();
         id(&i);
#line 395 "ass3.acc"
 appendExpression(*ret, makeExpression(0, 1, 0, i)); (*ret)->operator = '->'; 
# line 1667 "yygrammar.c"
         } break;
      case 216: {
         get_lexval();
#line 396 "ass3.acc"
 (*ret)->operator = 'x++'; 
# line 1673 "yygrammar.c"
         } break;
      case 217: {
         get_lexval();
#line 397 "ass3.acc"
 (*ret)->operator = 'x--'; 
# line 1679 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

primary_expression (ret)
   expression_pt *ret;
{
   constant_pt i;
   constant_pt c;
   expression_pt e;
   switch(yyselect()) {
   case 100: {
      id(&i);
#line 402 "ass3.acc"
 *ret = makeExpression(0, 1, 0, i); printExpression(*ret); putchar('\n'); 
# line 1698 "yygrammar.c"
      } break;
   case 101: {
      constant(&c);
#line 403 "ass3.acc"
 *ret = makeExpression(0, 1, 0, c); 
# line 1704 "yygrammar.c"
      } break;
   case 102: {
      get_lexval();
      expression(&e);
#line 404 "ass3.acc"
 *ret = e; 
# line 1711 "yygrammar.c"
      get_lexval();
      } break;
   }
}

argument_expression_list (ret)
   expression_pt *ret;
{
   expression_pt ae;
   expression_pt ae2;
   switch(yyselect()) {
   case 103: {
#line 408 "ass3.acc"
 *ret = makeExpression(1, 0, 0); 
# line 1726 "yygrammar.c"
      while (1) {
         switch (yyselect()) {
         case 218: {
            assignment_expression(&ae);
#line 408 "ass3.acc"
 growExpression(*ret); (*ret)->value[(*ret)->length-1].e = ae; 
# line 1733 "yygrammar.c"
            get_lexval();
            } break;
         default: goto yy6;
         }
      }
      yy6: ;
      assignment_expression(&ae2);
#line 408 "ass3.acc"
 growExpression(*ret); (*ret)->value[(*ret)->length-1].e = ae2; 
# line 1743 "yygrammar.c"
      } break;
   }
}

constant (ret)
   constant_pt *ret;
{
   switch(yyselect()) {
   case 104: {
      get_lexval();
#line 412 "ass3.acc"
 fprintf(out, "$%lu$", yylval.i); *ret = makeIntConst(yylval.i); 
# line 1756 "yygrammar.c"
      } break;
   case 105: {
      get_lexval();
#line 413 "ass3.acc"
 *ret = makeIntConst(yylval.i); 
# line 1762 "yygrammar.c"
      } break;
   case 106: {
      get_lexval();
#line 414 "ass3.acc"
 fprintf(out, "$%f$", yylval.d); *ret = makeFloatConst(yylval.d); 
# line 1768 "yygrammar.c"
      } break;
   case 107: {
      get_lexval();
#line 415 "ass3.acc"
 *ret = makeStringConst(yylval.s); 
# line 1774 "yygrammar.c"
      } break;
   }
}

id (ret)
   constant_pt *ret;
{
   switch(yyselect()) {
   case 108: {
      get_lexval();
#line 420 "ass3.acc"
 *ret = makeStringConst(yylval.s); (*ret)->type = IDCONST; 
# line 1787 "yygrammar.c"
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
int c_length = 1215;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 109,
/* 6 */ 0,
/* 7 */ 10,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 15,
/* 11 */ 18,
/* 12 */ 10,
/* 13 */ -10,
/* 14 */ 110,
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
/* 36 */ 111,
/* 37 */ 0,
/* 38 */ -33,
/* 39 */ 220,
/* 40 */ 44,
/* 41 */ 68,
/* 42 */ -40,
/* 43 */ 112,
/* 44 */ 0,
/* 45 */ -40,
/* 46 */ 221,
/* 47 */ 51,
/* 48 */ 50059,
/* 49 */ -47,
/* 50 */ 113,
/* 51 */ 0,
/* 52 */ 683,
/* 53 */ -47,
/* 54 */ 114,
/* 55 */ 0,
/* 56 */ 81,
/* 57 */ 61,
/* 58 */ 50059,
/* 59 */ -55,
/* 60 */ 5,
/* 61 */ 65,
/* 62 */ 235,
/* 63 */ -61,
/* 64 */ 115,
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
/* 77 */ 116,
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
/* 89 */ 117,
/* 90 */ 95,
/* 91 */ 127,
/* 92 */ 85,
/* 93 */ -85,
/* 94 */ 118,
/* 95 */ 100,
/* 96 */ 179,
/* 97 */ 85,
/* 98 */ -85,
/* 99 */ 119,
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
/* 110 */ 120,
/* 111 */ 115,
/* 112 */ 50274,
/* 113 */ -107,
/* 114 */ 121,
/* 115 */ 119,
/* 116 */ 50279,
/* 117 */ -107,
/* 118 */ 122,
/* 119 */ 123,
/* 120 */ 50267,
/* 121 */ -107,
/* 122 */ 123,
/* 123 */ 0,
/* 124 */ 50282,
/* 125 */ -107,
/* 126 */ 124,
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
/* 140 */ 1212,
/* 141 */ -127,
/* 142 */ 12,
/* 143 */ 147,
/* 144 */ 50285,
/* 145 */ -143,
/* 146 */ 125,
/* 147 */ 151,
/* 148 */ 50259,
/* 149 */ -143,
/* 150 */ 126,
/* 151 */ 155,
/* 152 */ 50276,
/* 153 */ -143,
/* 154 */ 127,
/* 155 */ 159,
/* 156 */ 50272,
/* 157 */ -143,
/* 158 */ 128,
/* 159 */ 163,
/* 160 */ 50273,
/* 161 */ -143,
/* 162 */ 129,
/* 163 */ 167,
/* 164 */ 50268,
/* 165 */ -143,
/* 166 */ 130,
/* 167 */ 171,
/* 168 */ 50264,
/* 169 */ -143,
/* 170 */ 131,
/* 171 */ 175,
/* 172 */ 50277,
/* 173 */ -143,
/* 174 */ 132,
/* 175 */ 0,
/* 176 */ 50284,
/* 177 */ -143,
/* 178 */ 133,
/* 179 */ 0,
/* 180 */ 183,
/* 181 */ -179,
/* 182 */ 13,
/* 183 */ 187,
/* 184 */ 50260,
/* 185 */ -183,
/* 186 */ 134,
/* 187 */ 0,
/* 188 */ 50286,
/* 189 */ -183,
/* 190 */ 135,
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
/* 201 */ 1212,
/* 202 */ -191,
/* 203 */ 15,
/* 204 */ 208,
/* 205 */ 1212,
/* 206 */ -204,
/* 207 */ 136,
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
/* 218 */ 137,
/* 219 */ 0,
/* 220 */ 50283,
/* 221 */ -215,
/* 222 */ 138,
/* 223 */ 0,
/* 224 */ 228,
/* 225 */ 261,
/* 226 */ -223,
/* 227 */ 17,
/* 228 */ 232,
/* 229 */ 223,
/* 230 */ -228,
/* 231 */ 139,
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
/* 244 */ 140,
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
/* 257 */ 141,
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
/* 275 */ 142,
/* 276 */ 0,
/* 277 */ 179,
/* 278 */ -272,
/* 279 */ 143,
/* 280 */ 284,
/* 281 */ 267,
/* 282 */ -280,
/* 283 */ 144,
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
/* 296 */ 145,
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
/* 307 */ 887,
/* 308 */ -300,
/* 309 */ 24,
/* 310 */ 314,
/* 311 */ 363,
/* 312 */ -310,
/* 313 */ 146,
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
/* 327 */ 1212,
/* 328 */ -317,
/* 329 */ 26,
/* 330 */ 334,
/* 331 */ 1212,
/* 332 */ -330,
/* 333 */ 147,
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
/* 346 */ 148,
/* 347 */ 0,
/* 348 */ -342,
/* 349 */ 233,
/* 350 */ 0,
/* 351 */ 1212,
/* 352 */ 355,
/* 353 */ -350,
/* 354 */ 28,
/* 355 */ 360,
/* 356 */ 50061,
/* 357 */ 887,
/* 358 */ -355,
/* 359 */ 149,
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
/* 371 */ 150,
/* 372 */ 0,
/* 373 */ -368,
/* 374 */ 235,
/* 375 */ 379,
/* 376 */ 1212,
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
/* 395 */ 152,
/* 396 */ 402,
/* 397 */ 50040,
/* 398 */ 454,
/* 399 */ 50041,
/* 400 */ -390,
/* 401 */ 153,
/* 402 */ 0,
/* 403 */ 50040,
/* 404 */ 415,
/* 405 */ 50041,
/* 406 */ -390,
/* 407 */ 155,
/* 408 */ 412,
/* 409 */ 844,
/* 410 */ -408,
/* 411 */ 151,
/* 412 */ 0,
/* 413 */ -408,
/* 414 */ 236,
/* 415 */ 419,
/* 416 */ 500,
/* 417 */ -415,
/* 418 */ 154,
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
/* 431 */ 156,
/* 432 */ 0,
/* 433 */ -428,
/* 434 */ 238,
/* 435 */ 439,
/* 436 */ 422,
/* 437 */ -435,
/* 438 */ 157,
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
/* 450 */ 158,
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
/* 463 */ 159,
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
/* 476 */ 160,
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
/* 488 */ 161,
/* 489 */ 0,
/* 490 */ 493,
/* 491 */ -485,
/* 492 */ 163,
/* 493 */ 497,
/* 494 */ 556,
/* 495 */ -493,
/* 496 */ 162,
/* 497 */ 0,
/* 498 */ -493,
/* 499 */ 243,
/* 500 */ 0,
/* 501 */ 505,
/* 502 */ 1212,
/* 503 */ -500,
/* 504 */ 38,
/* 505 */ 510,
/* 506 */ 500,
/* 507 */ 50044,
/* 508 */ -505,
/* 509 */ 164,
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
/* 527 */ 165,
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
/* 540 */ 166,
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
/* 552 */ 167,
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
/* 568 */ 168,
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
/* 586 */ 169,
/* 587 */ 0,
/* 588 */ -583,
/* 589 */ 249,
/* 590 */ 596,
/* 591 */ 50091,
/* 592 */ 602,
/* 593 */ 50093,
/* 594 */ -590,
/* 595 */ 171,
/* 596 */ 0,
/* 597 */ 50040,
/* 598 */ 609,
/* 599 */ 50041,
/* 600 */ -590,
/* 601 */ 173,
/* 602 */ 606,
/* 603 */ 844,
/* 604 */ -602,
/* 605 */ 170,
/* 606 */ 0,
/* 607 */ -602,
/* 608 */ 250,
/* 609 */ 613,
/* 610 */ 454,
/* 611 */ -609,
/* 612 */ 172,
/* 613 */ 0,
/* 614 */ -609,
/* 615 */ 251,
/* 616 */ 0,
/* 617 */ 1212,
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
/* 653 */ 1212,
/* 654 */ 50058,
/* 655 */ 620,
/* 656 */ -652,
/* 657 */ 56,
/* 658 */ 665,
/* 659 */ 50258,
/* 660 */ 887,
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
/* 679 */ 174,
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
/* 693 */ 175,
/* 694 */ 0,
/* 695 */ -690,
/* 696 */ 253,
/* 697 */ 701,
/* 698 */ 704,
/* 699 */ -697,
/* 700 */ 176,
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
/* 713 */ 177,
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
/* 738 */ 178,
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
/* 775 */ 179,
/* 776 */ 0,
/* 777 */ -772,
/* 778 */ 257,
/* 779 */ 783,
/* 780 */ 844,
/* 781 */ -779,
/* 782 */ 180,
/* 783 */ 0,
/* 784 */ -779,
/* 785 */ 258,
/* 786 */ 790,
/* 787 */ 844,
/* 788 */ -786,
/* 789 */ 181,
/* 790 */ 0,
/* 791 */ -786,
/* 792 */ 259,
/* 793 */ 799,
/* 794 */ 50270,
/* 795 */ 1212,
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
/* 818 */ 182,
/* 819 */ 0,
/* 820 */ -815,
/* 821 */ 260,
/* 822 */ 0,
/* 823 */ 50305,
/* 824 */ 1182,
/* 825 */ 50059,
/* 826 */ -822,
/* 827 */ 71,
/* 828 */ 0,
/* 829 */ 50306,
/* 830 */ 835,
/* 831 */ 1212,
/* 832 */ 50059,
/* 833 */ -828,
/* 834 */ 72,
/* 835 */ 841,
/* 836 */ 1212,
/* 837 */ 50044,
/* 838 */ 835,
/* 839 */ -835,
/* 840 */ 183,
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
/* 853 */ 184,
/* 854 */ 0,
/* 855 */ -849,
/* 856 */ 262,
/* 857 */ 861,
/* 858 */ 875,
/* 859 */ -857,
/* 860 */ 74,
/* 861 */ 0,
/* 862 */ 1039,
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
/* 875 */ 879,
/* 876 */ 891,
/* 877 */ -875,
/* 878 */ 78,
/* 879 */ 0,
/* 880 */ 891,
/* 881 */ 50063,
/* 882 */ 844,
/* 883 */ 50058,
/* 884 */ 875,
/* 885 */ -875,
/* 886 */ 79,
/* 887 */ 0,
/* 888 */ 875,
/* 889 */ -887,
/* 890 */ 80,
/* 891 */ 0,
/* 892 */ 896,
/* 893 */ 904,
/* 894 */ -891,
/* 895 */ 81,
/* 896 */ 901,
/* 897 */ 891,
/* 898 */ 50297,
/* 899 */ -896,
/* 900 */ 185,
/* 901 */ 0,
/* 902 */ -896,
/* 903 */ 263,
/* 904 */ 0,
/* 905 */ 909,
/* 906 */ 917,
/* 907 */ -904,
/* 908 */ 82,
/* 909 */ 914,
/* 910 */ 904,
/* 911 */ 50298,
/* 912 */ -909,
/* 913 */ 186,
/* 914 */ 0,
/* 915 */ -909,
/* 916 */ 264,
/* 917 */ 0,
/* 918 */ 922,
/* 919 */ 930,
/* 920 */ -917,
/* 921 */ 83,
/* 922 */ 927,
/* 923 */ 917,
/* 924 */ 50124,
/* 925 */ -922,
/* 926 */ 187,
/* 927 */ 0,
/* 928 */ -922,
/* 929 */ 265,
/* 930 */ 0,
/* 931 */ 935,
/* 932 */ 943,
/* 933 */ -930,
/* 934 */ 84,
/* 935 */ 940,
/* 936 */ 930,
/* 937 */ 50094,
/* 938 */ -935,
/* 939 */ 188,
/* 940 */ 0,
/* 941 */ -935,
/* 942 */ 266,
/* 943 */ 0,
/* 944 */ 948,
/* 945 */ 956,
/* 946 */ -943,
/* 947 */ 85,
/* 948 */ 953,
/* 949 */ 943,
/* 950 */ 50038,
/* 951 */ -948,
/* 952 */ 189,
/* 953 */ 0,
/* 954 */ -948,
/* 955 */ 267,
/* 956 */ 0,
/* 957 */ 961,
/* 958 */ 969,
/* 959 */ -956,
/* 960 */ 86,
/* 961 */ 966,
/* 962 */ 956,
/* 963 */ 50292,
/* 964 */ -961,
/* 965 */ 190,
/* 966 */ 0,
/* 967 */ -961,
/* 968 */ 268,
/* 969 */ 0,
/* 970 */ 974,
/* 971 */ 982,
/* 972 */ -969,
/* 973 */ 87,
/* 974 */ 979,
/* 975 */ 969,
/* 976 */ 50300,
/* 977 */ -974,
/* 978 */ 191,
/* 979 */ 0,
/* 980 */ -974,
/* 981 */ 269,
/* 982 */ 0,
/* 983 */ 987,
/* 984 */ 1003,
/* 985 */ -982,
/* 986 */ 88,
/* 987 */ 992,
/* 988 */ 982,
/* 989 */ 995,
/* 990 */ -987,
/* 991 */ 194,
/* 992 */ 0,
/* 993 */ -987,
/* 994 */ 270,
/* 995 */ 999,
/* 996 */ 50043,
/* 997 */ -995,
/* 998 */ 192,
/* 999 */ 0,
/* 1000 */ 50045,
/* 1001 */ -995,
/* 1002 */ 193,
/* 1003 */ 0,
/* 1004 */ 1008,
/* 1005 */ 1028,
/* 1006 */ -1003,
/* 1007 */ 89,
/* 1008 */ 1013,
/* 1009 */ 1003,
/* 1010 */ 1016,
/* 1011 */ -1008,
/* 1012 */ 198,
/* 1013 */ 0,
/* 1014 */ -1008,
/* 1015 */ 271,
/* 1016 */ 1020,
/* 1017 */ 50042,
/* 1018 */ -1016,
/* 1019 */ 195,
/* 1020 */ 1024,
/* 1021 */ 50047,
/* 1022 */ -1016,
/* 1023 */ 196,
/* 1024 */ 0,
/* 1025 */ 50037,
/* 1026 */ -1016,
/* 1027 */ 197,
/* 1028 */ 1032,
/* 1029 */ 1039,
/* 1030 */ -1028,
/* 1031 */ 90,
/* 1032 */ 0,
/* 1033 */ 50040,
/* 1034 */ 544,
/* 1035 */ 50041,
/* 1036 */ 1028,
/* 1037 */ -1028,
/* 1038 */ 91,
/* 1039 */ 1043,
/* 1040 */ 1113,
/* 1041 */ -1039,
/* 1042 */ 92,
/* 1043 */ 1048,
/* 1044 */ 1065,
/* 1045 */ 1039,
/* 1046 */ -1039,
/* 1047 */ 93,
/* 1048 */ 1053,
/* 1049 */ 1073,
/* 1050 */ 1028,
/* 1051 */ -1039,
/* 1052 */ 94,
/* 1053 */ 1058,
/* 1054 */ 50278,
/* 1055 */ 1039,
/* 1056 */ -1039,
/* 1057 */ 95,
/* 1058 */ 0,
/* 1059 */ 50278,
/* 1060 */ 50040,
/* 1061 */ 544,
/* 1062 */ 50041,
/* 1063 */ -1039,
/* 1064 */ 96,
/* 1065 */ 1069,
/* 1066 */ 50294,
/* 1067 */ -1065,
/* 1068 */ 199,
/* 1069 */ 0,
/* 1070 */ 50295,
/* 1071 */ -1065,
/* 1072 */ 200,
/* 1073 */ 0,
/* 1074 */ 1077,
/* 1075 */ -1073,
/* 1076 */ 97,
/* 1077 */ 1081,
/* 1078 */ 50038,
/* 1079 */ -1077,
/* 1080 */ 201,
/* 1081 */ 1085,
/* 1082 */ 50042,
/* 1083 */ -1077,
/* 1084 */ 202,
/* 1085 */ 1089,
/* 1086 */ 50043,
/* 1087 */ -1077,
/* 1088 */ 203,
/* 1089 */ 1093,
/* 1090 */ 50045,
/* 1091 */ -1077,
/* 1092 */ 204,
/* 1093 */ 1097,
/* 1094 */ 50126,
/* 1095 */ -1077,
/* 1096 */ 205,
/* 1097 */ 1101,
/* 1098 */ 50033,
/* 1099 */ -1077,
/* 1100 */ 206,
/* 1101 */ 1105,
/* 1102 */ 50126,
/* 1103 */ -1077,
/* 1104 */ 207,
/* 1105 */ 1109,
/* 1106 */ 50124,
/* 1107 */ -1077,
/* 1108 */ 208,
/* 1109 */ 0,
/* 1110 */ 50094,
/* 1111 */ -1077,
/* 1112 */ 209,
/* 1113 */ 1117,
/* 1114 */ 1168,
/* 1115 */ -1113,
/* 1116 */ 98,
/* 1117 */ 0,
/* 1118 */ 1113,
/* 1119 */ 1122,
/* 1120 */ -1113,
/* 1121 */ 99,
/* 1122 */ 1129,
/* 1123 */ 50091,
/* 1124 */ 844,
/* 1125 */ 1153,
/* 1126 */ 50093,
/* 1127 */ -1122,
/* 1128 */ 211,
/* 1129 */ 1135,
/* 1130 */ 50040,
/* 1131 */ 1161,
/* 1132 */ 50041,
/* 1133 */ -1122,
/* 1134 */ 213,
/* 1135 */ 1140,
/* 1136 */ 50046,
/* 1137 */ 1212,
/* 1138 */ -1122,
/* 1139 */ 214,
/* 1140 */ 1145,
/* 1141 */ 50296,
/* 1142 */ 1212,
/* 1143 */ -1122,
/* 1144 */ 215,
/* 1145 */ 1149,
/* 1146 */ 50294,
/* 1147 */ -1122,
/* 1148 */ 216,
/* 1149 */ 0,
/* 1150 */ 50295,
/* 1151 */ -1122,
/* 1152 */ 217,
/* 1153 */ 1158,
/* 1154 */ 50058,
/* 1155 */ 844,
/* 1156 */ -1153,
/* 1157 */ 210,
/* 1158 */ 0,
/* 1159 */ -1153,
/* 1160 */ 272,
/* 1161 */ 1165,
/* 1162 */ 1182,
/* 1163 */ -1161,
/* 1164 */ 212,
/* 1165 */ 0,
/* 1166 */ -1161,
/* 1167 */ 273,
/* 1168 */ 1172,
/* 1169 */ 1212,
/* 1170 */ -1168,
/* 1171 */ 100,
/* 1172 */ 1176,
/* 1173 */ 1196,
/* 1174 */ -1168,
/* 1175 */ 101,
/* 1176 */ 0,
/* 1177 */ 50040,
/* 1178 */ 844,
/* 1179 */ 50041,
/* 1180 */ -1168,
/* 1181 */ 102,
/* 1182 */ 0,
/* 1183 */ 1187,
/* 1184 */ 857,
/* 1185 */ -1182,
/* 1186 */ 103,
/* 1187 */ 1193,
/* 1188 */ 857,
/* 1189 */ 50044,
/* 1190 */ 1187,
/* 1191 */ -1187,
/* 1192 */ 218,
/* 1193 */ 0,
/* 1194 */ -1187,
/* 1195 */ 274,
/* 1196 */ 1200,
/* 1197 */ 50304,
/* 1198 */ -1196,
/* 1199 */ 104,
/* 1200 */ 1204,
/* 1201 */ 50302,
/* 1202 */ -1196,
/* 1203 */ 105,
/* 1204 */ 1208,
/* 1205 */ 50303,
/* 1206 */ -1196,
/* 1207 */ 106,
/* 1208 */ 0,
/* 1209 */ 50289,
/* 1210 */ -1196,
/* 1211 */ 107,
/* 1212 */ 0,
/* 1213 */ 50299,
/* 1214 */ -1212,
/* 1215 */ 108,
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
/* 823 */ 50305,
/* 824 */ 1,
/* 825 */ 50059,
/* 826 */ -822,
/* 827 */ 1,
/* 828 */ 0,
/* 829 */ 50306,
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
/* 875 */ 879,
/* 876 */ 1,
/* 877 */ -875,
/* 878 */ 1,
/* 879 */ 0,
/* 880 */ 1,
/* 881 */ 50063,
/* 882 */ 1,
/* 883 */ 50058,
/* 884 */ 1,
/* 885 */ -875,
/* 886 */ 2,
/* 887 */ 0,
/* 888 */ 1,
/* 889 */ -887,
/* 890 */ 1,
/* 891 */ 0,
/* 892 */ 1,
/* 893 */ 1,
/* 894 */ -891,
/* 895 */ 1,
/* 896 */ 901,
/* 897 */ 1,
/* 898 */ 50297,
/* 899 */ -896,
/* 900 */ 1,
/* 901 */ 0,
/* 902 */ -896,
/* 903 */ 2,
/* 904 */ 0,
/* 905 */ 1,
/* 906 */ 1,
/* 907 */ -904,
/* 908 */ 1,
/* 909 */ 914,
/* 910 */ 1,
/* 911 */ 50298,
/* 912 */ -909,
/* 913 */ 1,
/* 914 */ 0,
/* 915 */ -909,
/* 916 */ 2,
/* 917 */ 0,
/* 918 */ 1,
/* 919 */ 1,
/* 920 */ -917,
/* 921 */ 1,
/* 922 */ 927,
/* 923 */ 1,
/* 924 */ 50124,
/* 925 */ -922,
/* 926 */ 1,
/* 927 */ 0,
/* 928 */ -922,
/* 929 */ 2,
/* 930 */ 0,
/* 931 */ 1,
/* 932 */ 1,
/* 933 */ -930,
/* 934 */ 1,
/* 935 */ 940,
/* 936 */ 1,
/* 937 */ 50094,
/* 938 */ -935,
/* 939 */ 1,
/* 940 */ 0,
/* 941 */ -935,
/* 942 */ 2,
/* 943 */ 0,
/* 944 */ 1,
/* 945 */ 1,
/* 946 */ -943,
/* 947 */ 1,
/* 948 */ 953,
/* 949 */ 1,
/* 950 */ 50038,
/* 951 */ -948,
/* 952 */ 1,
/* 953 */ 0,
/* 954 */ -948,
/* 955 */ 2,
/* 956 */ 0,
/* 957 */ 1,
/* 958 */ 1,
/* 959 */ -956,
/* 960 */ 1,
/* 961 */ 966,
/* 962 */ 1,
/* 963 */ 50292,
/* 964 */ -961,
/* 965 */ 1,
/* 966 */ 0,
/* 967 */ -961,
/* 968 */ 2,
/* 969 */ 0,
/* 970 */ 1,
/* 971 */ 1,
/* 972 */ -969,
/* 973 */ 1,
/* 974 */ 979,
/* 975 */ 1,
/* 976 */ 50300,
/* 977 */ -974,
/* 978 */ 1,
/* 979 */ 0,
/* 980 */ -974,
/* 981 */ 2,
/* 982 */ 0,
/* 983 */ 1,
/* 984 */ 1,
/* 985 */ -982,
/* 986 */ 1,
/* 987 */ 992,
/* 988 */ 1,
/* 989 */ 1,
/* 990 */ -987,
/* 991 */ 1,
/* 992 */ 0,
/* 993 */ -987,
/* 994 */ 2,
/* 995 */ 999,
/* 996 */ 50043,
/* 997 */ -995,
/* 998 */ 1,
/* 999 */ 0,
/* 1000 */ 50045,
/* 1001 */ -995,
/* 1002 */ 2,
/* 1003 */ 0,
/* 1004 */ 1,
/* 1005 */ 1,
/* 1006 */ -1003,
/* 1007 */ 1,
/* 1008 */ 1013,
/* 1009 */ 1,
/* 1010 */ 1,
/* 1011 */ -1008,
/* 1012 */ 1,
/* 1013 */ 0,
/* 1014 */ -1008,
/* 1015 */ 2,
/* 1016 */ 1020,
/* 1017 */ 50042,
/* 1018 */ -1016,
/* 1019 */ 1,
/* 1020 */ 1024,
/* 1021 */ 50047,
/* 1022 */ -1016,
/* 1023 */ 2,
/* 1024 */ 0,
/* 1025 */ 50037,
/* 1026 */ -1016,
/* 1027 */ 3,
/* 1028 */ 1032,
/* 1029 */ 1,
/* 1030 */ -1028,
/* 1031 */ 1,
/* 1032 */ 0,
/* 1033 */ 50040,
/* 1034 */ 1,
/* 1035 */ 50041,
/* 1036 */ 1,
/* 1037 */ -1028,
/* 1038 */ 2,
/* 1039 */ 1043,
/* 1040 */ 1,
/* 1041 */ -1039,
/* 1042 */ 1,
/* 1043 */ 1048,
/* 1044 */ 1,
/* 1045 */ 1,
/* 1046 */ -1039,
/* 1047 */ 2,
/* 1048 */ 1053,
/* 1049 */ 1,
/* 1050 */ 1,
/* 1051 */ -1039,
/* 1052 */ 3,
/* 1053 */ 1058,
/* 1054 */ 50278,
/* 1055 */ 1,
/* 1056 */ -1039,
/* 1057 */ 4,
/* 1058 */ 0,
/* 1059 */ 50278,
/* 1060 */ 50040,
/* 1061 */ 1,
/* 1062 */ 50041,
/* 1063 */ -1039,
/* 1064 */ 5,
/* 1065 */ 1069,
/* 1066 */ 50294,
/* 1067 */ -1065,
/* 1068 */ 1,
/* 1069 */ 0,
/* 1070 */ 50295,
/* 1071 */ -1065,
/* 1072 */ 2,
/* 1073 */ 0,
/* 1074 */ 1,
/* 1075 */ -1073,
/* 1076 */ 1,
/* 1077 */ 1081,
/* 1078 */ 50038,
/* 1079 */ -1077,
/* 1080 */ 1,
/* 1081 */ 1085,
/* 1082 */ 50042,
/* 1083 */ -1077,
/* 1084 */ 2,
/* 1085 */ 1089,
/* 1086 */ 50043,
/* 1087 */ -1077,
/* 1088 */ 3,
/* 1089 */ 1093,
/* 1090 */ 50045,
/* 1091 */ -1077,
/* 1092 */ 4,
/* 1093 */ 1097,
/* 1094 */ 50126,
/* 1095 */ -1077,
/* 1096 */ 5,
/* 1097 */ 1101,
/* 1098 */ 50033,
/* 1099 */ -1077,
/* 1100 */ 6,
/* 1101 */ 1105,
/* 1102 */ 50126,
/* 1103 */ -1077,
/* 1104 */ 7,
/* 1105 */ 1109,
/* 1106 */ 50124,
/* 1107 */ -1077,
/* 1108 */ 8,
/* 1109 */ 0,
/* 1110 */ 50094,
/* 1111 */ -1077,
/* 1112 */ 9,
/* 1113 */ 1117,
/* 1114 */ 1,
/* 1115 */ -1113,
/* 1116 */ 1,
/* 1117 */ 0,
/* 1118 */ 1,
/* 1119 */ 1,
/* 1120 */ -1113,
/* 1121 */ 2,
/* 1122 */ 1129,
/* 1123 */ 50091,
/* 1124 */ 1,
/* 1125 */ 1,
/* 1126 */ 50093,
/* 1127 */ -1122,
/* 1128 */ 1,
/* 1129 */ 1135,
/* 1130 */ 50040,
/* 1131 */ 1,
/* 1132 */ 50041,
/* 1133 */ -1122,
/* 1134 */ 2,
/* 1135 */ 1140,
/* 1136 */ 50046,
/* 1137 */ 1,
/* 1138 */ -1122,
/* 1139 */ 3,
/* 1140 */ 1145,
/* 1141 */ 50296,
/* 1142 */ 1,
/* 1143 */ -1122,
/* 1144 */ 4,
/* 1145 */ 1149,
/* 1146 */ 50294,
/* 1147 */ -1122,
/* 1148 */ 5,
/* 1149 */ 0,
/* 1150 */ 50295,
/* 1151 */ -1122,
/* 1152 */ 6,
/* 1153 */ 1158,
/* 1154 */ 50058,
/* 1155 */ 1,
/* 1156 */ -1153,
/* 1157 */ 1,
/* 1158 */ 0,
/* 1159 */ -1153,
/* 1160 */ 2,
/* 1161 */ 1165,
/* 1162 */ 1,
/* 1163 */ -1161,
/* 1164 */ 1,
/* 1165 */ 0,
/* 1166 */ -1161,
/* 1167 */ 2,
/* 1168 */ 1172,
/* 1169 */ 1,
/* 1170 */ -1168,
/* 1171 */ 1,
/* 1172 */ 1176,
/* 1173 */ 1,
/* 1174 */ -1168,
/* 1175 */ 2,
/* 1176 */ 0,
/* 1177 */ 50040,
/* 1178 */ 1,
/* 1179 */ 50041,
/* 1180 */ -1168,
/* 1181 */ 3,
/* 1182 */ 0,
/* 1183 */ 1,
/* 1184 */ 1,
/* 1185 */ -1182,
/* 1186 */ 1,
/* 1187 */ 1193,
/* 1188 */ 1,
/* 1189 */ 50044,
/* 1190 */ 1,
/* 1191 */ -1187,
/* 1192 */ 1,
/* 1193 */ 0,
/* 1194 */ -1187,
/* 1195 */ 2,
/* 1196 */ 1200,
/* 1197 */ 50304,
/* 1198 */ -1196,
/* 1199 */ 1,
/* 1200 */ 1204,
/* 1201 */ 50302,
/* 1202 */ -1196,
/* 1203 */ 2,
/* 1204 */ 1208,
/* 1205 */ 50303,
/* 1206 */ -1196,
/* 1207 */ 3,
/* 1208 */ 0,
/* 1209 */ 50289,
/* 1210 */ -1196,
/* 1211 */ 4,
/* 1212 */ 0,
/* 1213 */ 50299,
/* 1214 */ -1212,
/* 1215 */ 1,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 86002,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 86002,
/* 6 */ 9999,
/* 7 */ 86004,
/* 8 */ 9999,
/* 9 */ 86004,
/* 10 */ 9999,
/* 11 */ 86006,
/* 12 */ 86025,
/* 13 */ 9999,
/* 14 */ 86025,
/* 15 */ 9999,
/* 16 */ 9999,
/* 17 */ 86025,
/* 18 */ 9999,
/* 19 */ 90004,
/* 20 */ 9999,
/* 21 */ 90022,
/* 22 */ 9999,
/* 23 */ 91004,
/* 24 */ 9999,
/* 25 */ 91014,
/* 26 */ 9999,
/* 27 */ 95004,
/* 28 */ 95032,
/* 29 */ 95043,
/* 30 */ 95065,
/* 31 */ 9999,
/* 32 */ 95004,
/* 33 */ 9999,
/* 34 */ 95006,
/* 35 */ 9999,
/* 36 */ 95027,
/* 37 */ 9999,
/* 38 */ 9999,
/* 39 */ 95027,
/* 40 */ 9999,
/* 41 */ 95045,
/* 42 */ 9999,
/* 43 */ 95060,
/* 44 */ 9999,
/* 45 */ 9999,
/* 46 */ 95060,
/* 47 */ 9999,
/* 48 */ 9999,
/* 49 */ 9999,
/* 50 */ 95067,
/* 51 */ 9999,
/* 52 */ 95073,
/* 53 */ 9999,
/* 54 */ 95090,
/* 55 */ 9999,
/* 56 */ 99004,
/* 57 */ 99027,
/* 58 */ 9999,
/* 59 */ 9999,
/* 60 */ 99025,
/* 61 */ 9999,
/* 62 */ 99029,
/* 63 */ 9999,
/* 64 */ 99048,
/* 65 */ 9999,
/* 66 */ 9999,
/* 67 */ 99048,
/* 68 */ 9999,
/* 69 */ 103004,
/* 70 */ 103016,
/* 71 */ 9999,
/* 72 */ 103014,
/* 73 */ 9999,
/* 74 */ 103018,
/* 75 */ 103028,
/* 76 */ 9999,
/* 77 */ 103028,
/* 78 */ 9999,
/* 79 */ 9999,
/* 80 */ 103028,
/* 81 */ 9999,
/* 82 */ 107004,
/* 83 */ 9999,
/* 84 */ 107004,
/* 85 */ 9999,
/* 86 */ 107006,
/* 87 */ 107028,
/* 88 */ 9999,
/* 89 */ 107028,
/* 90 */ 9999,
/* 91 */ 107032,
/* 92 */ 107045,
/* 93 */ 9999,
/* 94 */ 107045,
/* 95 */ 9999,
/* 96 */ 107049,
/* 97 */ 107062,
/* 98 */ 9999,
/* 99 */ 107062,
/* 100 */ 9999,
/* 101 */ 9999,
/* 102 */ 107062,
/* 103 */ 9999,
/* 104 */ 111004,
/* 105 */ 9999,
/* 106 */ 111004,
/* 107 */ 9999,
/* 108 */ 9999,
/* 109 */ 9999,
/* 110 */ 111009,
/* 111 */ 9999,
/* 112 */ 9999,
/* 113 */ 9999,
/* 114 */ 112011,
/* 115 */ 9999,
/* 116 */ 9999,
/* 117 */ 9999,
/* 118 */ 113009,
/* 119 */ 9999,
/* 120 */ 9999,
/* 121 */ 9999,
/* 122 */ 114009,
/* 123 */ 9999,
/* 124 */ 9999,
/* 125 */ 9999,
/* 126 */ 115010,
/* 127 */ 9999,
/* 128 */ 120004,
/* 129 */ 9999,
/* 130 */ 120004,
/* 131 */ 9999,
/* 132 */ 129004,
/* 133 */ 9999,
/* 134 */ 129028,
/* 135 */ 9999,
/* 136 */ 129032,
/* 137 */ 9999,
/* 138 */ 129045,
/* 139 */ 9999,
/* 140 */ 130004,
/* 141 */ 9999,
/* 142 */ 130005,
/* 143 */ 9999,
/* 144 */ 9999,
/* 145 */ 9999,
/* 146 */ 120009,
/* 147 */ 9999,
/* 148 */ 9999,
/* 149 */ 9999,
/* 150 */ 121007,
/* 151 */ 9999,
/* 152 */ 9999,
/* 153 */ 9999,
/* 154 */ 122008,
/* 155 */ 9999,
/* 156 */ 9999,
/* 157 */ 9999,
/* 158 */ 123006,
/* 159 */ 9999,
/* 160 */ 9999,
/* 161 */ 9999,
/* 162 */ 124007,
/* 163 */ 9999,
/* 164 */ 9999,
/* 165 */ 9999,
/* 166 */ 125008,
/* 167 */ 9999,
/* 168 */ 9999,
/* 169 */ 9999,
/* 170 */ 126009,
/* 171 */ 9999,
/* 172 */ 9999,
/* 173 */ 9999,
/* 174 */ 127009,
/* 175 */ 9999,
/* 176 */ 9999,
/* 177 */ 9999,
/* 178 */ 128011,
/* 179 */ 9999,
/* 180 */ 134004,
/* 181 */ 9999,
/* 182 */ 134004,
/* 183 */ 9999,
/* 184 */ 9999,
/* 185 */ 9999,
/* 186 */ 134010,
/* 187 */ 9999,
/* 188 */ 9999,
/* 189 */ 9999,
/* 190 */ 135011,
/* 191 */ 9999,
/* 192 */ 139004,
/* 193 */ 139020,
/* 194 */ 9999,
/* 195 */ 139035,
/* 196 */ 9999,
/* 197 */ 9999,
/* 198 */ 139018,
/* 199 */ 9999,
/* 200 */ 140004,
/* 201 */ 140020,
/* 202 */ 9999,
/* 203 */ 140018,
/* 204 */ 9999,
/* 205 */ 139022,
/* 206 */ 9999,
/* 207 */ 139023,
/* 208 */ 9999,
/* 209 */ 9999,
/* 210 */ 139023,
/* 211 */ 9999,
/* 212 */ 144004,
/* 213 */ 9999,
/* 214 */ 144004,
/* 215 */ 9999,
/* 216 */ 9999,
/* 217 */ 9999,
/* 218 */ 144011,
/* 219 */ 9999,
/* 220 */ 9999,
/* 221 */ 9999,
/* 222 */ 144019,
/* 223 */ 9999,
/* 224 */ 148004,
/* 225 */ 148033,
/* 226 */ 9999,
/* 227 */ 148004,
/* 228 */ 9999,
/* 229 */ 148006,
/* 230 */ 9999,
/* 231 */ 148028,
/* 232 */ 9999,
/* 233 */ 9999,
/* 234 */ 148028,
/* 235 */ 9999,
/* 236 */ 152004,
/* 237 */ 152034,
/* 238 */ 9999,
/* 239 */ 152004,
/* 240 */ 9999,
/* 241 */ 152006,
/* 242 */ 9999,
/* 243 */ 9999,
/* 244 */ 152025,
/* 245 */ 9999,
/* 246 */ 9999,
/* 247 */ 152025,
/* 248 */ 9999,
/* 249 */ 156004,
/* 250 */ 156024,
/* 251 */ 9999,
/* 252 */ 156004,
/* 253 */ 9999,
/* 254 */ 156006,
/* 255 */ 9999,
/* 256 */ 9999,
/* 257 */ 156015,
/* 258 */ 9999,
/* 259 */ 9999,
/* 260 */ 156015,
/* 261 */ 9999,
/* 262 */ 160004,
/* 263 */ 160029,
/* 264 */ 9999,
/* 265 */ 9999,
/* 266 */ 160027,
/* 267 */ 9999,
/* 268 */ 164004,
/* 269 */ 164040,
/* 270 */ 9999,
/* 271 */ 164004,
/* 272 */ 9999,
/* 273 */ 164006,
/* 274 */ 9999,
/* 275 */ 164019,
/* 276 */ 9999,
/* 277 */ 164023,
/* 278 */ 9999,
/* 279 */ 164036,
/* 280 */ 9999,
/* 281 */ 164042,
/* 282 */ 9999,
/* 283 */ 164065,
/* 284 */ 9999,
/* 285 */ 9999,
/* 286 */ 164065,
/* 287 */ 9999,
/* 288 */ 168004,
/* 289 */ 168036,
/* 290 */ 9999,
/* 291 */ 168004,
/* 292 */ 9999,
/* 293 */ 168006,
/* 294 */ 9999,
/* 295 */ 9999,
/* 296 */ 168027,
/* 297 */ 9999,
/* 298 */ 9999,
/* 299 */ 168027,
/* 300 */ 9999,
/* 301 */ 172004,
/* 302 */ 9999,
/* 303 */ 172013,
/* 304 */ 9999,
/* 305 */ 173004,
/* 306 */ 9999,
/* 307 */ 173024,
/* 308 */ 9999,
/* 309 */ 173004,
/* 310 */ 9999,
/* 311 */ 173006,
/* 312 */ 9999,
/* 313 */ 173015,
/* 314 */ 9999,
/* 315 */ 9999,
/* 316 */ 173015,
/* 317 */ 9999,
/* 318 */ 9999,
/* 319 */ 177009,
/* 320 */ 9999,
/* 321 */ 177024,
/* 322 */ 9999,
/* 323 */ 9999,
/* 324 */ 177007,
/* 325 */ 9999,
/* 326 */ 9999,
/* 327 */ 178009,
/* 328 */ 9999,
/* 329 */ 178007,
/* 330 */ 9999,
/* 331 */ 177011,
/* 332 */ 9999,
/* 333 */ 177012,
/* 334 */ 9999,
/* 335 */ 9999,
/* 336 */ 177012,
/* 337 */ 9999,
/* 338 */ 182004,
/* 339 */ 182029,
/* 340 */ 9999,
/* 341 */ 182004,
/* 342 */ 9999,
/* 343 */ 182006,
/* 344 */ 9999,
/* 345 */ 9999,
/* 346 */ 182020,
/* 347 */ 9999,
/* 348 */ 9999,
/* 349 */ 182020,
/* 350 */ 9999,
/* 351 */ 186004,
/* 352 */ 186010,
/* 353 */ 9999,
/* 354 */ 186005,
/* 355 */ 9999,
/* 356 */ 9999,
/* 357 */ 186016,
/* 358 */ 9999,
/* 359 */ 186012,
/* 360 */ 9999,
/* 361 */ 9999,
/* 362 */ 186012,
/* 363 */ 9999,
/* 364 */ 190004,
/* 365 */ 190017,
/* 366 */ 9999,
/* 367 */ 190004,
/* 368 */ 9999,
/* 369 */ 190006,
/* 370 */ 9999,
/* 371 */ 190012,
/* 372 */ 9999,
/* 373 */ 9999,
/* 374 */ 190012,
/* 375 */ 9999,
/* 376 */ 194004,
/* 377 */ 9999,
/* 378 */ 194005,
/* 379 */ 9999,
/* 380 */ 9999,
/* 381 */ 195008,
/* 382 */ 9999,
/* 383 */ 9999,
/* 384 */ 195004,
/* 385 */ 9999,
/* 386 */ 196004,
/* 387 */ 196022,
/* 388 */ 9999,
/* 389 */ 196020,
/* 390 */ 9999,
/* 391 */ 9999,
/* 392 */ 196028,
/* 393 */ 9999,
/* 394 */ 9999,
/* 395 */ 196024,
/* 396 */ 9999,
/* 397 */ 9999,
/* 398 */ 197009,
/* 399 */ 9999,
/* 400 */ 9999,
/* 401 */ 197005,
/* 402 */ 9999,
/* 403 */ 9999,
/* 404 */ 198009,
/* 405 */ 9999,
/* 406 */ 9999,
/* 407 */ 198005,
/* 408 */ 9999,
/* 409 */ 196030,
/* 410 */ 9999,
/* 411 */ 196039,
/* 412 */ 9999,
/* 413 */ 9999,
/* 414 */ 196039,
/* 415 */ 9999,
/* 416 */ 198011,
/* 417 */ 9999,
/* 418 */ 198025,
/* 419 */ 9999,
/* 420 */ 9999,
/* 421 */ 198025,
/* 422 */ 9999,
/* 423 */ 9999,
/* 424 */ 202008,
/* 425 */ 202033,
/* 426 */ 9999,
/* 427 */ 202004,
/* 428 */ 9999,
/* 429 */ 202010,
/* 430 */ 9999,
/* 431 */ 202028,
/* 432 */ 9999,
/* 433 */ 9999,
/* 434 */ 202028,
/* 435 */ 9999,
/* 436 */ 202035,
/* 437 */ 9999,
/* 438 */ 202041,
/* 439 */ 9999,
/* 440 */ 9999,
/* 441 */ 202041,
/* 442 */ 9999,
/* 443 */ 206004,
/* 444 */ 206029,
/* 445 */ 9999,
/* 446 */ 206004,
/* 447 */ 9999,
/* 448 */ 206006,
/* 449 */ 9999,
/* 450 */ 206024,
/* 451 */ 9999,
/* 452 */ 9999,
/* 453 */ 206024,
/* 454 */ 9999,
/* 455 */ 210004,
/* 456 */ 210019,
/* 457 */ 9999,
/* 458 */ 210017,
/* 459 */ 9999,
/* 460 */ 9999,
/* 461 */ 9999,
/* 462 */ 9999,
/* 463 */ 210021,
/* 464 */ 9999,
/* 465 */ 9999,
/* 466 */ 210021,
/* 467 */ 9999,
/* 468 */ 214004,
/* 469 */ 214028,
/* 470 */ 9999,
/* 471 */ 214004,
/* 472 */ 9999,
/* 473 */ 214006,
/* 474 */ 9999,
/* 475 */ 9999,
/* 476 */ 214019,
/* 477 */ 9999,
/* 478 */ 9999,
/* 479 */ 214019,
/* 480 */ 9999,
/* 481 */ 218004,
/* 482 */ 218027,
/* 483 */ 9999,
/* 484 */ 218025,
/* 485 */ 9999,
/* 486 */ 218029,
/* 487 */ 9999,
/* 488 */ 218038,
/* 489 */ 9999,
/* 490 */ 218042,
/* 491 */ 9999,
/* 492 */ 218042,
/* 493 */ 9999,
/* 494 */ 218044,
/* 495 */ 9999,
/* 496 */ 218062,
/* 497 */ 9999,
/* 498 */ 9999,
/* 499 */ 218062,
/* 500 */ 9999,
/* 501 */ 222004,
/* 502 */ 222029,
/* 503 */ 9999,
/* 504 */ 222004,
/* 505 */ 9999,
/* 506 */ 222006,
/* 507 */ 9999,
/* 508 */ 9999,
/* 509 */ 222020,
/* 510 */ 9999,
/* 511 */ 9999,
/* 512 */ 222020,
/* 513 */ 9999,
/* 514 */ 226004,
/* 515 */ 9999,
/* 516 */ 226024,
/* 517 */ 9999,
/* 518 */ 9999,
/* 519 */ 227008,
/* 520 */ 227025,
/* 521 */ 9999,
/* 522 */ 9999,
/* 523 */ 227004,
/* 524 */ 9999,
/* 525 */ 9999,
/* 526 */ 9999,
/* 527 */ 227027,
/* 528 */ 9999,
/* 529 */ 9999,
/* 530 */ 227027,
/* 531 */ 9999,
/* 532 */ 231004,
/* 533 */ 231030,
/* 534 */ 9999,
/* 535 */ 231004,
/* 536 */ 9999,
/* 537 */ 231006,
/* 538 */ 9999,
/* 539 */ 9999,
/* 540 */ 231021,
/* 541 */ 9999,
/* 542 */ 9999,
/* 543 */ 231021,
/* 544 */ 9999,
/* 545 */ 235004,
/* 546 */ 235029,
/* 547 */ 9999,
/* 548 */ 235027,
/* 549 */ 9999,
/* 550 */ 235031,
/* 551 */ 9999,
/* 552 */ 235049,
/* 553 */ 9999,
/* 554 */ 9999,
/* 555 */ 235049,
/* 556 */ 9999,
/* 557 */ 239004,
/* 558 */ 9999,
/* 559 */ 239010,
/* 560 */ 9999,
/* 561 */ 240004,
/* 562 */ 240017,
/* 563 */ 9999,
/* 564 */ 240004,
/* 565 */ 9999,
/* 566 */ 240006,
/* 567 */ 9999,
/* 568 */ 240012,
/* 569 */ 9999,
/* 570 */ 9999,
/* 571 */ 240012,
/* 572 */ 9999,
/* 573 */ 9999,
/* 574 */ 244008,
/* 575 */ 9999,
/* 576 */ 9999,
/* 577 */ 244004,
/* 578 */ 9999,
/* 579 */ 245004,
/* 580 */ 245036,
/* 581 */ 9999,
/* 582 */ 245004,
/* 583 */ 9999,
/* 584 */ 245006,
/* 585 */ 9999,
/* 586 */ 245031,
/* 587 */ 9999,
/* 588 */ 9999,
/* 589 */ 245031,
/* 590 */ 9999,
/* 591 */ 9999,
/* 592 */ 245042,
/* 593 */ 9999,
/* 594 */ 9999,
/* 595 */ 245038,
/* 596 */ 9999,
/* 597 */ 9999,
/* 598 */ 246009,
/* 599 */ 9999,
/* 600 */ 9999,
/* 601 */ 246005,
/* 602 */ 9999,
/* 603 */ 245044,
/* 604 */ 9999,
/* 605 */ 245053,
/* 606 */ 9999,
/* 607 */ 9999,
/* 608 */ 245053,
/* 609 */ 9999,
/* 610 */ 246011,
/* 611 */ 9999,
/* 612 */ 246029,
/* 613 */ 9999,
/* 614 */ 9999,
/* 615 */ 246029,
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
/* 645 */ 260004,
/* 646 */ 9999,
/* 647 */ 260018,
/* 648 */ 9999,
/* 649 */ 261004,
/* 650 */ 9999,
/* 651 */ 261018,
/* 652 */ 9999,
/* 653 */ 265004,
/* 654 */ 9999,
/* 655 */ 265014,
/* 656 */ 9999,
/* 657 */ 265005,
/* 658 */ 9999,
/* 659 */ 9999,
/* 660 */ 266009,
/* 661 */ 9999,
/* 662 */ 266037,
/* 663 */ 9999,
/* 664 */ 266007,
/* 665 */ 9999,
/* 666 */ 9999,
/* 667 */ 9999,
/* 668 */ 267016,
/* 669 */ 9999,
/* 670 */ 267010,
/* 671 */ 9999,
/* 672 */ 271004,
/* 673 */ 9999,
/* 674 */ 9999,
/* 675 */ 271004,
/* 676 */ 9999,
/* 677 */ 271006,
/* 678 */ 9999,
/* 679 */ 271015,
/* 680 */ 9999,
/* 681 */ 9999,
/* 682 */ 271015,
/* 683 */ 9999,
/* 684 */ 9999,
/* 685 */ 275008,
/* 686 */ 275030,
/* 687 */ 9999,
/* 688 */ 9999,
/* 689 */ 275004,
/* 690 */ 9999,
/* 691 */ 275010,
/* 692 */ 9999,
/* 693 */ 275025,
/* 694 */ 9999,
/* 695 */ 9999,
/* 696 */ 275025,
/* 697 */ 9999,
/* 698 */ 275032,
/* 699 */ 9999,
/* 700 */ 275045,
/* 701 */ 9999,
/* 702 */ 9999,
/* 703 */ 275045,
/* 704 */ 9999,
/* 705 */ 284004,
/* 706 */ 284019,
/* 707 */ 9999,
/* 708 */ 284004,
/* 709 */ 9999,
/* 710 */ 284006,
/* 711 */ 284014,
/* 712 */ 9999,
/* 713 */ 284014,
/* 714 */ 9999,
/* 715 */ 9999,
/* 716 */ 284014,
/* 717 */ 9999,
/* 718 */ 9999,
/* 719 */ 9999,
/* 720 */ 288011,
/* 721 */ 9999,
/* 722 */ 288029,
/* 723 */ 288039,
/* 724 */ 9999,
/* 725 */ 288005,
/* 726 */ 9999,
/* 727 */ 9999,
/* 728 */ 9999,
/* 729 */ 289015,
/* 730 */ 9999,
/* 731 */ 289033,
/* 732 */ 9999,
/* 733 */ 289009,
/* 734 */ 9999,
/* 735 */ 9999,
/* 736 */ 288046,
/* 737 */ 9999,
/* 738 */ 288044,
/* 739 */ 9999,
/* 740 */ 9999,
/* 741 */ 288044,
/* 742 */ 9999,
/* 743 */ 9999,
/* 744 */ 9999,
/* 745 */ 293024,
/* 746 */ 9999,
/* 747 */ 293052,
/* 748 */ 9999,
/* 749 */ 293008,
/* 750 */ 9999,
/* 751 */ 9999,
/* 752 */ 294017,
/* 753 */ 9999,
/* 754 */ 9999,
/* 755 */ 294057,
/* 756 */ 9999,
/* 757 */ 9999,
/* 758 */ 9999,
/* 759 */ 294005,
/* 760 */ 9999,
/* 761 */ 9999,
/* 762 */ 9999,
/* 763 */ 295032,
/* 764 */ 9999,
/* 765 */ 295055,
/* 766 */ 9999,
/* 767 */ 295078,
/* 768 */ 9999,
/* 769 */ 295111,
/* 770 */ 9999,
/* 771 */ 295006,
/* 772 */ 9999,
/* 773 */ 295034,
/* 774 */ 9999,
/* 775 */ 295043,
/* 776 */ 9999,
/* 777 */ 9999,
/* 778 */ 295043,
/* 779 */ 9999,
/* 780 */ 295057,
/* 781 */ 9999,
/* 782 */ 295066,
/* 783 */ 9999,
/* 784 */ 9999,
/* 785 */ 295066,
/* 786 */ 9999,
/* 787 */ 295080,
/* 788 */ 9999,
/* 789 */ 295089,
/* 790 */ 9999,
/* 791 */ 9999,
/* 792 */ 295089,
/* 793 */ 9999,
/* 794 */ 9999,
/* 795 */ 299019,
/* 796 */ 9999,
/* 797 */ 9999,
/* 798 */ 299007,
/* 799 */ 9999,
/* 800 */ 9999,
/* 801 */ 9999,
/* 802 */ 9999,
/* 803 */ 300011,
/* 804 */ 9999,
/* 805 */ 9999,
/* 806 */ 9999,
/* 807 */ 9999,
/* 808 */ 301008,
/* 809 */ 9999,
/* 810 */ 9999,
/* 811 */ 302021,
/* 812 */ 9999,
/* 813 */ 9999,
/* 814 */ 302009,
/* 815 */ 9999,
/* 816 */ 302023,
/* 817 */ 9999,
/* 818 */ 302032,
/* 819 */ 9999,
/* 820 */ 9999,
/* 821 */ 302032,
/* 822 */ 9999,
/* 823 */ 9999,
/* 824 */ 306020,
/* 825 */ 9999,
/* 826 */ 9999,
/* 827 */ 306008,
/* 828 */ 9999,
/* 829 */ 9999,
/* 830 */ 310020,
/* 831 */ 310035,
/* 832 */ 9999,
/* 833 */ 9999,
/* 834 */ 310008,
/* 835 */ 9999,
/* 836 */ 310022,
/* 837 */ 9999,
/* 838 */ 310023,
/* 839 */ 9999,
/* 840 */ 310023,
/* 841 */ 9999,
/* 842 */ 9999,
/* 843 */ 310023,
/* 844 */ 9999,
/* 845 */ 314042,
/* 846 */ 314096,
/* 847 */ 9999,
/* 848 */ 314004,
/* 849 */ 9999,
/* 850 */ 314044,
/* 851 */ 9999,
/* 852 */ 9999,
/* 853 */ 314053,
/* 854 */ 9999,
/* 855 */ 9999,
/* 856 */ 314053,
/* 857 */ 9999,
/* 858 */ 318004,
/* 859 */ 9999,
/* 860 */ 318025,
/* 861 */ 9999,
/* 862 */ 319042,
/* 863 */ 319095,
/* 864 */ 319115,
/* 865 */ 9999,
/* 866 */ 319004,
/* 867 */ 9999,
/* 868 */ 9999,
/* 869 */ 9999,
/* 870 */ 323009,
/* 871 */ 9999,
/* 872 */ 9999,
/* 873 */ 9999,
/* 874 */ 324004,
/* 875 */ 9999,
/* 876 */ 328004,
/* 877 */ 9999,
/* 878 */ 328024,
/* 879 */ 9999,
/* 880 */ 329004,
/* 881 */ 9999,
/* 882 */ 329035,
/* 883 */ 9999,
/* 884 */ 329053,
/* 885 */ 9999,
/* 886 */ 329024,
/* 887 */ 9999,
/* 888 */ 333004,
/* 889 */ 9999,
/* 890 */ 333025,
/* 891 */ 9999,
/* 892 */ 337043,
/* 893 */ 337119,
/* 894 */ 9999,
/* 895 */ 337004,
/* 896 */ 9999,
/* 897 */ 337045,
/* 898 */ 9999,
/* 899 */ 9999,
/* 900 */ 337065,
/* 901 */ 9999,
/* 902 */ 9999,
/* 903 */ 337065,
/* 904 */ 9999,
/* 905 */ 341043,
/* 906 */ 341121,
/* 907 */ 9999,
/* 908 */ 341004,
/* 909 */ 9999,
/* 910 */ 341045,
/* 911 */ 9999,
/* 912 */ 9999,
/* 913 */ 341066,
/* 914 */ 9999,
/* 915 */ 9999,
/* 916 */ 341066,
/* 917 */ 9999,
/* 918 */ 345042,
/* 919 */ 345113,
/* 920 */ 9999,
/* 921 */ 345004,
/* 922 */ 9999,
/* 923 */ 345044,
/* 924 */ 9999,
/* 925 */ 9999,
/* 926 */ 345066,
/* 927 */ 9999,
/* 928 */ 9999,
/* 929 */ 345066,
/* 930 */ 9999,
/* 931 */ 349042,
/* 932 */ 349113,
/* 933 */ 9999,
/* 934 */ 349004,
/* 935 */ 9999,
/* 936 */ 349044,
/* 937 */ 9999,
/* 938 */ 9999,
/* 939 */ 349066,
/* 940 */ 9999,
/* 941 */ 9999,
/* 942 */ 349066,
/* 943 */ 9999,
/* 944 */ 353042,
/* 945 */ 353101,
/* 946 */ 9999,
/* 947 */ 353004,
/* 948 */ 9999,
/* 949 */ 353043,
/* 950 */ 9999,
/* 951 */ 9999,
/* 952 */ 353056,
/* 953 */ 9999,
/* 954 */ 9999,
/* 955 */ 353056,
/* 956 */ 9999,
/* 957 */ 357040,
/* 958 */ 357109,
/* 959 */ 9999,
/* 960 */ 357004,
/* 961 */ 9999,
/* 962 */ 357042,
/* 963 */ 9999,
/* 964 */ 9999,
/* 965 */ 357060,
/* 966 */ 9999,
/* 967 */ 9999,
/* 968 */ 357060,
/* 969 */ 9999,
/* 970 */ 361040,
/* 971 */ 361103,
/* 972 */ 9999,
/* 973 */ 361004,
/* 974 */ 9999,
/* 975 */ 361041,
/* 976 */ 9999,
/* 977 */ 9999,
/* 978 */ 361056,
/* 979 */ 9999,
/* 980 */ 9999,
/* 981 */ 361056,
/* 982 */ 9999,
/* 983 */ 365040,
/* 984 */ 365115,
/* 985 */ 9999,
/* 986 */ 365004,
/* 987 */ 9999,
/* 988 */ 365042,
/* 989 */ 365098,
/* 990 */ 9999,
/* 991 */ 365060,
/* 992 */ 9999,
/* 993 */ 9999,
/* 994 */ 365060,
/* 995 */ 9999,
/* 996 */ 9999,
/* 997 */ 9999,
/* 998 */ 365100,
/* 999 */ 9999,
/* 1000 */ 9999,
/* 1001 */ 9999,
/* 1002 */ 365106,
/* 1003 */ 9999,
/* 1004 */ 369040,
/* 1005 */ 369127,
/* 1006 */ 9999,
/* 1007 */ 369004,
/* 1008 */ 9999,
/* 1009 */ 369042,
/* 1010 */ 369104,
/* 1011 */ 9999,
/* 1012 */ 369066,
/* 1013 */ 9999,
/* 1014 */ 9999,
/* 1015 */ 369066,
/* 1016 */ 9999,
/* 1017 */ 9999,
/* 1018 */ 9999,
/* 1019 */ 369106,
/* 1020 */ 9999,
/* 1021 */ 9999,
/* 1022 */ 9999,
/* 1023 */ 369112,
/* 1024 */ 9999,
/* 1025 */ 9999,
/* 1026 */ 9999,
/* 1027 */ 369118,
/* 1028 */ 9999,
/* 1029 */ 373004,
/* 1030 */ 9999,
/* 1031 */ 373019,
/* 1032 */ 9999,
/* 1033 */ 9999,
/* 1034 */ 374008,
/* 1035 */ 9999,
/* 1036 */ 374022,
/* 1037 */ 9999,
/* 1038 */ 374004,
/* 1039 */ 9999,
/* 1040 */ 378004,
/* 1041 */ 9999,
/* 1042 */ 378021,
/* 1043 */ 9999,
/* 1044 */ 379015,
/* 1045 */ 379062,
/* 1046 */ 9999,
/* 1047 */ 379004,
/* 1048 */ 9999,
/* 1049 */ 380004,
/* 1050 */ 380019,
/* 1051 */ 9999,
/* 1052 */ 380017,
/* 1053 */ 9999,
/* 1054 */ 9999,
/* 1055 */ 381011,
/* 1056 */ 9999,
/* 1057 */ 381009,
/* 1058 */ 9999,
/* 1059 */ 9999,
/* 1060 */ 9999,
/* 1061 */ 382015,
/* 1062 */ 9999,
/* 1063 */ 9999,
/* 1064 */ 382009,
/* 1065 */ 9999,
/* 1066 */ 9999,
/* 1067 */ 9999,
/* 1068 */ 379022,
/* 1069 */ 9999,
/* 1070 */ 9999,
/* 1071 */ 9999,
/* 1072 */ 379044,
/* 1073 */ 9999,
/* 1074 */ 386004,
/* 1075 */ 9999,
/* 1076 */ 386004,
/* 1077 */ 9999,
/* 1078 */ 9999,
/* 1079 */ 9999,
/* 1080 */ 386005,
/* 1081 */ 9999,
/* 1082 */ 9999,
/* 1083 */ 9999,
/* 1084 */ 386011,
/* 1085 */ 9999,
/* 1086 */ 9999,
/* 1087 */ 9999,
/* 1088 */ 386017,
/* 1089 */ 9999,
/* 1090 */ 9999,
/* 1091 */ 9999,
/* 1092 */ 386023,
/* 1093 */ 9999,
/* 1094 */ 9999,
/* 1095 */ 9999,
/* 1096 */ 386029,
/* 1097 */ 9999,
/* 1098 */ 9999,
/* 1099 */ 9999,
/* 1100 */ 386035,
/* 1101 */ 9999,
/* 1102 */ 9999,
/* 1103 */ 9999,
/* 1104 */ 386041,
/* 1105 */ 9999,
/* 1106 */ 9999,
/* 1107 */ 9999,
/* 1108 */ 386047,
/* 1109 */ 9999,
/* 1110 */ 9999,
/* 1111 */ 9999,
/* 1112 */ 386053,
/* 1113 */ 9999,
/* 1114 */ 390004,
/* 1115 */ 9999,
/* 1116 */ 390021,
/* 1117 */ 9999,
/* 1118 */ 391004,
/* 1119 */ 392003,
/* 1120 */ 9999,
/* 1121 */ 391021,
/* 1122 */ 9999,
/* 1123 */ 9999,
/* 1124 */ 392009,
/* 1125 */ 392054,
/* 1126 */ 9999,
/* 1127 */ 9999,
/* 1128 */ 392005,
/* 1129 */ 9999,
/* 1130 */ 9999,
/* 1131 */ 393009,
/* 1132 */ 9999,
/* 1133 */ 9999,
/* 1134 */ 393005,
/* 1135 */ 9999,
/* 1136 */ 9999,
/* 1137 */ 394009,
/* 1138 */ 9999,
/* 1139 */ 394005,
/* 1140 */ 9999,
/* 1141 */ 9999,
/* 1142 */ 395012,
/* 1143 */ 9999,
/* 1144 */ 395010,
/* 1145 */ 9999,
/* 1146 */ 9999,
/* 1147 */ 9999,
/* 1148 */ 396010,
/* 1149 */ 9999,
/* 1150 */ 9999,
/* 1151 */ 9999,
/* 1152 */ 397010,
/* 1153 */ 9999,
/* 1154 */ 9999,
/* 1155 */ 392060,
/* 1156 */ 9999,
/* 1157 */ 392056,
/* 1158 */ 9999,
/* 1159 */ 9999,
/* 1160 */ 392056,
/* 1161 */ 9999,
/* 1162 */ 393011,
/* 1163 */ 9999,
/* 1164 */ 393034,
/* 1165 */ 9999,
/* 1166 */ 9999,
/* 1167 */ 393034,
/* 1168 */ 9999,
/* 1169 */ 402004,
/* 1170 */ 9999,
/* 1171 */ 402005,
/* 1172 */ 9999,
/* 1173 */ 403004,
/* 1174 */ 9999,
/* 1175 */ 403011,
/* 1176 */ 9999,
/* 1177 */ 9999,
/* 1178 */ 404008,
/* 1179 */ 9999,
/* 1180 */ 9999,
/* 1181 */ 404004,
/* 1182 */ 9999,
/* 1183 */ 408039,
/* 1184 */ 408140,
/* 1185 */ 9999,
/* 1186 */ 408004,
/* 1187 */ 9999,
/* 1188 */ 408041,
/* 1189 */ 9999,
/* 1190 */ 408061,
/* 1191 */ 9999,
/* 1192 */ 408061,
/* 1193 */ 9999,
/* 1194 */ 9999,
/* 1195 */ 408061,
/* 1196 */ 9999,
/* 1197 */ 9999,
/* 1198 */ 9999,
/* 1199 */ 412011,
/* 1200 */ 9999,
/* 1201 */ 9999,
/* 1202 */ 9999,
/* 1203 */ 413012,
/* 1204 */ 9999,
/* 1205 */ 9999,
/* 1206 */ 9999,
/* 1207 */ 414013,
/* 1208 */ 9999,
/* 1209 */ 9999,
/* 1210 */ 9999,
/* 1211 */ 415009,
/* 1212 */ 9999,
/* 1213 */ 9999,
/* 1214 */ 9999,
/* 1215 */ 420013,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[1217];
*/
int TABLE[275][308];
init_dirsets() {
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
TABLE[109][63] = 1;
TABLE[109][278] = 1;
TABLE[109][283] = 1;
TABLE[109][280] = 1;
TABLE[109][294] = 1;
TABLE[109][295] = 1;
TABLE[109][297] = 1;
TABLE[109][94] = 1;
TABLE[109][124] = 1;
TABLE[109][33] = 1;
TABLE[109][126] = 1;
TABLE[109][45] = 1;
TABLE[109][43] = 1;
TABLE[109][38] = 1;
TABLE[109][298] = 1;
TABLE[109][304] = 1;
TABLE[109][302] = 1;
TABLE[109][303] = 1;
TABLE[109][289] = 1;
TABLE[109][292] = 1;
TABLE[109][300] = 1;
TABLE[109][47] = 1;
TABLE[109][37] = 1;
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
TABLE[1][63] = 1;
TABLE[1][295] = 1;
TABLE[1][294] = 1;
TABLE[1][38] = 1;
TABLE[1][43] = 1;
TABLE[1][45] = 1;
TABLE[1][126] = 1;
TABLE[1][33] = 1;
TABLE[1][124] = 1;
TABLE[1][94] = 1;
TABLE[1][297] = 1;
TABLE[1][289] = 1;
TABLE[1][303] = 1;
TABLE[1][302] = 1;
TABLE[1][304] = 1;
TABLE[1][298] = 1;
TABLE[1][292] = 1;
TABLE[1][300] = 1;
TABLE[1][37] = 1;
TABLE[1][47] = 1;
TABLE[110][0] = 1;
TABLE[110][59] = 1;
TABLE[110][123] = 1;
TABLE[110][40] = 1;
TABLE[110][42] = 1;
TABLE[110][299] = 1;
TABLE[110][44] = 1;
TABLE[110][61] = 1;
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
TABLE[110][282] = 1;
TABLE[110][267] = 1;
TABLE[110][279] = 1;
TABLE[110][274] = 1;
TABLE[110][256] = 1;
TABLE[110][63] = 1;
TABLE[110][278] = 1;
TABLE[110][283] = 1;
TABLE[110][280] = 1;
TABLE[110][294] = 1;
TABLE[110][295] = 1;
TABLE[110][297] = 1;
TABLE[110][94] = 1;
TABLE[110][124] = 1;
TABLE[110][33] = 1;
TABLE[110][126] = 1;
TABLE[110][45] = 1;
TABLE[110][43] = 1;
TABLE[110][38] = 1;
TABLE[110][298] = 1;
TABLE[110][304] = 1;
TABLE[110][302] = 1;
TABLE[110][303] = 1;
TABLE[110][289] = 1;
TABLE[110][292] = 1;
TABLE[110][300] = 1;
TABLE[110][47] = 1;
TABLE[110][37] = 1;
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
TABLE[2][63] = 1;
TABLE[2][278] = 1;
TABLE[2][294] = 1;
TABLE[2][295] = 1;
TABLE[2][297] = 1;
TABLE[2][94] = 1;
TABLE[2][124] = 1;
TABLE[2][33] = 1;
TABLE[2][126] = 1;
TABLE[2][45] = 1;
TABLE[2][43] = 1;
TABLE[2][38] = 1;
TABLE[2][298] = 1;
TABLE[2][304] = 1;
TABLE[2][302] = 1;
TABLE[2][303] = 1;
TABLE[2][289] = 1;
TABLE[2][292] = 1;
TABLE[2][300] = 1;
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
TABLE[3][63] = 1;
TABLE[3][40] = 1;
TABLE[3][295] = 1;
TABLE[3][294] = 1;
TABLE[3][42] = 1;
TABLE[3][38] = 1;
TABLE[3][43] = 1;
TABLE[3][45] = 1;
TABLE[3][126] = 1;
TABLE[3][33] = 1;
TABLE[3][124] = 1;
TABLE[3][94] = 1;
TABLE[3][297] = 1;
TABLE[3][289] = 1;
TABLE[3][303] = 1;
TABLE[3][302] = 1;
TABLE[3][304] = 1;
TABLE[3][298] = 1;
TABLE[3][292] = 1;
TABLE[3][300] = 1;
TABLE[3][37] = 1;
TABLE[3][47] = 1;
TABLE[4][59] = 1;
TABLE[4][44] = 1;
TABLE[4][123] = 1;
TABLE[4][61] = 1;
TABLE[4][278] = 1;
TABLE[4][63] = 1;
TABLE[4][295] = 1;
TABLE[4][294] = 1;
TABLE[4][38] = 1;
TABLE[4][43] = 1;
TABLE[4][45] = 1;
TABLE[4][126] = 1;
TABLE[4][33] = 1;
TABLE[4][124] = 1;
TABLE[4][94] = 1;
TABLE[4][297] = 1;
TABLE[4][289] = 1;
TABLE[4][303] = 1;
TABLE[4][302] = 1;
TABLE[4][304] = 1;
TABLE[4][298] = 1;
TABLE[4][292] = 1;
TABLE[4][300] = 1;
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
TABLE[111][44] = 1;
TABLE[111][61] = 1;
TABLE[111][278] = 1;
TABLE[111][63] = 1;
TABLE[111][40] = 1;
TABLE[111][295] = 1;
TABLE[111][294] = 1;
TABLE[111][42] = 1;
TABLE[111][38] = 1;
TABLE[111][43] = 1;
TABLE[111][45] = 1;
TABLE[111][126] = 1;
TABLE[111][33] = 1;
TABLE[111][124] = 1;
TABLE[111][94] = 1;
TABLE[111][297] = 1;
TABLE[111][289] = 1;
TABLE[111][303] = 1;
TABLE[111][302] = 1;
TABLE[111][304] = 1;
TABLE[111][298] = 1;
TABLE[111][292] = 1;
TABLE[111][300] = 1;
TABLE[111][37] = 1;
TABLE[111][47] = 1;
TABLE[111][59] = 1;
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
TABLE[111][283] = 1;
TABLE[111][280] = 1;
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
TABLE[220][63] = 1;
TABLE[220][40] = 1;
TABLE[220][295] = 1;
TABLE[220][294] = 1;
TABLE[220][42] = 1;
TABLE[220][38] = 1;
TABLE[220][43] = 1;
TABLE[220][45] = 1;
TABLE[220][126] = 1;
TABLE[220][33] = 1;
TABLE[220][124] = 1;
TABLE[220][94] = 1;
TABLE[220][297] = 1;
TABLE[220][289] = 1;
TABLE[220][303] = 1;
TABLE[220][302] = 1;
TABLE[220][304] = 1;
TABLE[220][298] = 1;
TABLE[220][292] = 1;
TABLE[220][300] = 1;
TABLE[220][37] = 1;
TABLE[220][47] = 1;
TABLE[220][59] = 1;
TABLE[220][123] = 1;
TABLE[112][59] = 1;
TABLE[112][44] = 1;
TABLE[112][61] = 1;
TABLE[112][123] = 1;
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
TABLE[112][299] = 1;
TABLE[112][282] = 1;
TABLE[112][267] = 1;
TABLE[112][279] = 1;
TABLE[112][274] = 1;
TABLE[112][256] = 1;
TABLE[112][40] = 1;
TABLE[112][63] = 1;
TABLE[112][278] = 1;
TABLE[112][283] = 1;
TABLE[112][280] = 1;
TABLE[112][42] = 1;
TABLE[112][294] = 1;
TABLE[112][295] = 1;
TABLE[112][297] = 1;
TABLE[112][94] = 1;
TABLE[112][124] = 1;
TABLE[112][33] = 1;
TABLE[112][126] = 1;
TABLE[112][45] = 1;
TABLE[112][43] = 1;
TABLE[112][38] = 1;
TABLE[112][298] = 1;
TABLE[112][304] = 1;
TABLE[112][302] = 1;
TABLE[112][303] = 1;
TABLE[112][289] = 1;
TABLE[112][292] = 1;
TABLE[112][300] = 1;
TABLE[112][47] = 1;
TABLE[112][37] = 1;
TABLE[221][59] = 1;
TABLE[221][123] = 1;
TABLE[113][59] = 1;
TABLE[114][123] = 1;
TABLE[5][59] = 1;
TABLE[5][44] = 1;
TABLE[5][61] = 1;
TABLE[5][123] = 1;
TABLE[5][40] = 1;
TABLE[5][63] = 1;
TABLE[5][278] = 1;
TABLE[5][42] = 1;
TABLE[5][294] = 1;
TABLE[5][295] = 1;
TABLE[5][297] = 1;
TABLE[5][94] = 1;
TABLE[5][124] = 1;
TABLE[5][33] = 1;
TABLE[5][126] = 1;
TABLE[5][45] = 1;
TABLE[5][43] = 1;
TABLE[5][38] = 1;
TABLE[5][298] = 1;
TABLE[5][304] = 1;
TABLE[5][302] = 1;
TABLE[5][303] = 1;
TABLE[5][289] = 1;
TABLE[5][292] = 1;
TABLE[5][300] = 1;
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
TABLE[115][59] = 1;
TABLE[115][44] = 1;
TABLE[115][123] = 1;
TABLE[115][61] = 1;
TABLE[115][278] = 1;
TABLE[115][63] = 1;
TABLE[115][40] = 1;
TABLE[115][295] = 1;
TABLE[115][294] = 1;
TABLE[115][299] = 1;
TABLE[115][42] = 1;
TABLE[115][38] = 1;
TABLE[115][43] = 1;
TABLE[115][45] = 1;
TABLE[115][126] = 1;
TABLE[115][33] = 1;
TABLE[115][124] = 1;
TABLE[115][94] = 1;
TABLE[115][297] = 1;
TABLE[115][289] = 1;
TABLE[115][303] = 1;
TABLE[115][302] = 1;
TABLE[115][304] = 1;
TABLE[115][298] = 1;
TABLE[115][292] = 1;
TABLE[115][300] = 1;
TABLE[115][37] = 1;
TABLE[115][47] = 1;
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
TABLE[6][305] = 1;
TABLE[6][306] = 1;
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
TABLE[6][63] = 1;
TABLE[6][40] = 1;
TABLE[6][295] = 1;
TABLE[6][294] = 1;
TABLE[6][42] = 1;
TABLE[6][38] = 1;
TABLE[6][43] = 1;
TABLE[6][45] = 1;
TABLE[6][126] = 1;
TABLE[6][33] = 1;
TABLE[6][124] = 1;
TABLE[6][94] = 1;
TABLE[6][297] = 1;
TABLE[6][289] = 1;
TABLE[6][303] = 1;
TABLE[6][302] = 1;
TABLE[6][304] = 1;
TABLE[6][298] = 1;
TABLE[6][292] = 1;
TABLE[6][300] = 1;
TABLE[6][37] = 1;
TABLE[6][47] = 1;
TABLE[116][262] = 1;
TABLE[116][258] = 1;
TABLE[116][281] = 1;
TABLE[116][271] = 1;
TABLE[116][269] = 1;
TABLE[116][263] = 1;
TABLE[116][287] = 1;
TABLE[116][275] = 1;
TABLE[116][257] = 1;
TABLE[116][261] = 1;
TABLE[116][270] = 1;
TABLE[116][305] = 1;
TABLE[116][306] = 1;
TABLE[116][125] = 1;
TABLE[116][59] = 1;
TABLE[116][44] = 1;
TABLE[116][256] = 1;
TABLE[116][274] = 1;
TABLE[116][279] = 1;
TABLE[116][267] = 1;
TABLE[116][282] = 1;
TABLE[116][299] = 1;
TABLE[116][266] = 1;
TABLE[116][285] = 1;
TABLE[116][259] = 1;
TABLE[116][276] = 1;
TABLE[116][272] = 1;
TABLE[116][273] = 1;
TABLE[116][268] = 1;
TABLE[116][264] = 1;
TABLE[116][277] = 1;
TABLE[116][284] = 1;
TABLE[116][260] = 1;
TABLE[116][286] = 1;
TABLE[116][123] = 1;
TABLE[116][61] = 1;
TABLE[116][280] = 1;
TABLE[116][283] = 1;
TABLE[116][278] = 1;
TABLE[116][63] = 1;
TABLE[116][40] = 1;
TABLE[116][295] = 1;
TABLE[116][294] = 1;
TABLE[116][42] = 1;
TABLE[116][38] = 1;
TABLE[116][43] = 1;
TABLE[116][45] = 1;
TABLE[116][126] = 1;
TABLE[116][33] = 1;
TABLE[116][124] = 1;
TABLE[116][94] = 1;
TABLE[116][297] = 1;
TABLE[116][289] = 1;
TABLE[116][303] = 1;
TABLE[116][302] = 1;
TABLE[116][304] = 1;
TABLE[116][298] = 1;
TABLE[116][292] = 1;
TABLE[116][300] = 1;
TABLE[116][37] = 1;
TABLE[116][47] = 1;
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
TABLE[223][305] = 1;
TABLE[223][306] = 1;
TABLE[223][299] = 1;
TABLE[223][44] = 1;
TABLE[223][63] = 1;
TABLE[223][278] = 1;
TABLE[223][294] = 1;
TABLE[223][295] = 1;
TABLE[223][297] = 1;
TABLE[223][94] = 1;
TABLE[223][124] = 1;
TABLE[223][33] = 1;
TABLE[223][126] = 1;
TABLE[223][45] = 1;
TABLE[223][43] = 1;
TABLE[223][42] = 1;
TABLE[223][38] = 1;
TABLE[223][40] = 1;
TABLE[223][298] = 1;
TABLE[223][304] = 1;
TABLE[223][302] = 1;
TABLE[223][303] = 1;
TABLE[223][289] = 1;
TABLE[223][292] = 1;
TABLE[223][300] = 1;
TABLE[223][47] = 1;
TABLE[223][37] = 1;
TABLE[223][125] = 1;
TABLE[7][44] = 1;
TABLE[7][61] = 1;
TABLE[7][278] = 1;
TABLE[7][63] = 1;
TABLE[7][40] = 1;
TABLE[7][295] = 1;
TABLE[7][294] = 1;
TABLE[7][42] = 1;
TABLE[7][38] = 1;
TABLE[7][43] = 1;
TABLE[7][45] = 1;
TABLE[7][126] = 1;
TABLE[7][33] = 1;
TABLE[7][124] = 1;
TABLE[7][94] = 1;
TABLE[7][297] = 1;
TABLE[7][289] = 1;
TABLE[7][303] = 1;
TABLE[7][302] = 1;
TABLE[7][304] = 1;
TABLE[7][298] = 1;
TABLE[7][292] = 1;
TABLE[7][300] = 1;
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
TABLE[117][282] = 1;
TABLE[117][267] = 1;
TABLE[117][279] = 1;
TABLE[117][274] = 1;
TABLE[117][256] = 1;
TABLE[118][284] = 1;
TABLE[118][277] = 1;
TABLE[118][264] = 1;
TABLE[118][268] = 1;
TABLE[118][273] = 1;
TABLE[118][272] = 1;
TABLE[118][276] = 1;
TABLE[118][259] = 1;
TABLE[118][285] = 1;
TABLE[118][266] = 1;
TABLE[118][299] = 1;
TABLE[118][283] = 1;
TABLE[118][280] = 1;
TABLE[119][286] = 1;
TABLE[119][260] = 1;
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
TABLE[224][63] = 1;
TABLE[224][40] = 1;
TABLE[224][295] = 1;
TABLE[224][294] = 1;
TABLE[224][42] = 1;
TABLE[224][38] = 1;
TABLE[224][43] = 1;
TABLE[224][45] = 1;
TABLE[224][126] = 1;
TABLE[224][33] = 1;
TABLE[224][124] = 1;
TABLE[224][94] = 1;
TABLE[224][297] = 1;
TABLE[224][289] = 1;
TABLE[224][303] = 1;
TABLE[224][302] = 1;
TABLE[224][304] = 1;
TABLE[224][298] = 1;
TABLE[224][292] = 1;
TABLE[224][300] = 1;
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
TABLE[120][256] = 1;
TABLE[121][274] = 1;
TABLE[122][279] = 1;
TABLE[123][267] = 1;
TABLE[124][282] = 1;
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
TABLE[125][285] = 1;
TABLE[126][259] = 1;
TABLE[127][276] = 1;
TABLE[128][272] = 1;
TABLE[129][273] = 1;
TABLE[130][268] = 1;
TABLE[131][264] = 1;
TABLE[132][277] = 1;
TABLE[133][284] = 1;
TABLE[13][260] = 1;
TABLE[13][286] = 1;
TABLE[134][260] = 1;
TABLE[135][286] = 1;
TABLE[14][283] = 1;
TABLE[14][280] = 1;
TABLE[15][283] = 1;
TABLE[15][280] = 1;
TABLE[136][299] = 1;
TABLE[225][123] = 1;
TABLE[16][280] = 1;
TABLE[16][283] = 1;
TABLE[137][280] = 1;
TABLE[138][283] = 1;
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
TABLE[139][286] = 1;
TABLE[139][260] = 1;
TABLE[139][284] = 1;
TABLE[139][277] = 1;
TABLE[139][264] = 1;
TABLE[139][268] = 1;
TABLE[139][273] = 1;
TABLE[139][272] = 1;
TABLE[139][276] = 1;
TABLE[139][259] = 1;
TABLE[139][285] = 1;
TABLE[139][266] = 1;
TABLE[139][299] = 1;
TABLE[139][283] = 1;
TABLE[139][280] = 1;
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
TABLE[18][63] = 1;
TABLE[18][278] = 1;
TABLE[18][42] = 1;
TABLE[18][299] = 1;
TABLE[18][294] = 1;
TABLE[18][295] = 1;
TABLE[18][297] = 1;
TABLE[18][94] = 1;
TABLE[18][124] = 1;
TABLE[18][33] = 1;
TABLE[18][126] = 1;
TABLE[18][45] = 1;
TABLE[18][43] = 1;
TABLE[18][38] = 1;
TABLE[18][298] = 1;
TABLE[18][304] = 1;
TABLE[18][302] = 1;
TABLE[18][303] = 1;
TABLE[18][289] = 1;
TABLE[18][292] = 1;
TABLE[18][300] = 1;
TABLE[18][47] = 1;
TABLE[18][37] = 1;
TABLE[140][44] = 1;
TABLE[140][123] = 1;
TABLE[140][61] = 1;
TABLE[140][278] = 1;
TABLE[140][63] = 1;
TABLE[140][40] = 1;
TABLE[140][295] = 1;
TABLE[140][294] = 1;
TABLE[140][299] = 1;
TABLE[140][42] = 1;
TABLE[140][38] = 1;
TABLE[140][43] = 1;
TABLE[140][45] = 1;
TABLE[140][126] = 1;
TABLE[140][33] = 1;
TABLE[140][124] = 1;
TABLE[140][94] = 1;
TABLE[140][297] = 1;
TABLE[140][289] = 1;
TABLE[140][303] = 1;
TABLE[140][302] = 1;
TABLE[140][304] = 1;
TABLE[140][298] = 1;
TABLE[140][292] = 1;
TABLE[140][300] = 1;
TABLE[140][37] = 1;
TABLE[140][47] = 1;
TABLE[227][61] = 1;
TABLE[227][123] = 1;
TABLE[227][40] = 1;
TABLE[227][63] = 1;
TABLE[227][278] = 1;
TABLE[227][42] = 1;
TABLE[227][299] = 1;
TABLE[227][294] = 1;
TABLE[227][295] = 1;
TABLE[227][297] = 1;
TABLE[227][94] = 1;
TABLE[227][124] = 1;
TABLE[227][33] = 1;
TABLE[227][126] = 1;
TABLE[227][45] = 1;
TABLE[227][43] = 1;
TABLE[227][38] = 1;
TABLE[227][298] = 1;
TABLE[227][304] = 1;
TABLE[227][302] = 1;
TABLE[227][303] = 1;
TABLE[227][289] = 1;
TABLE[227][292] = 1;
TABLE[227][300] = 1;
TABLE[227][47] = 1;
TABLE[227][37] = 1;
TABLE[227][59] = 1;
TABLE[227][44] = 1;
TABLE[19][59] = 1;
TABLE[19][44] = 1;
TABLE[19][123] = 1;
TABLE[19][278] = 1;
TABLE[19][63] = 1;
TABLE[19][295] = 1;
TABLE[19][294] = 1;
TABLE[19][38] = 1;
TABLE[19][43] = 1;
TABLE[19][45] = 1;
TABLE[19][126] = 1;
TABLE[19][33] = 1;
TABLE[19][124] = 1;
TABLE[19][94] = 1;
TABLE[19][297] = 1;
TABLE[19][289] = 1;
TABLE[19][303] = 1;
TABLE[19][302] = 1;
TABLE[19][304] = 1;
TABLE[19][298] = 1;
TABLE[19][292] = 1;
TABLE[19][300] = 1;
TABLE[19][37] = 1;
TABLE[19][47] = 1;
TABLE[19][61] = 1;
TABLE[19][40] = 1;
TABLE[19][299] = 1;
TABLE[19][42] = 1;
TABLE[141][61] = 1;
TABLE[141][40] = 1;
TABLE[141][42] = 1;
TABLE[141][299] = 1;
TABLE[228][123] = 1;
TABLE[228][278] = 1;
TABLE[228][63] = 1;
TABLE[228][295] = 1;
TABLE[228][294] = 1;
TABLE[228][40] = 1;
TABLE[228][38] = 1;
TABLE[228][42] = 1;
TABLE[228][43] = 1;
TABLE[228][45] = 1;
TABLE[228][126] = 1;
TABLE[228][33] = 1;
TABLE[228][124] = 1;
TABLE[228][94] = 1;
TABLE[228][297] = 1;
TABLE[228][299] = 1;
TABLE[228][289] = 1;
TABLE[228][303] = 1;
TABLE[228][302] = 1;
TABLE[228][304] = 1;
TABLE[228][298] = 1;
TABLE[228][292] = 1;
TABLE[228][300] = 1;
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
TABLE[142][284] = 1;
TABLE[142][277] = 1;
TABLE[142][264] = 1;
TABLE[142][268] = 1;
TABLE[142][273] = 1;
TABLE[142][272] = 1;
TABLE[142][276] = 1;
TABLE[142][259] = 1;
TABLE[142][285] = 1;
TABLE[142][266] = 1;
TABLE[142][299] = 1;
TABLE[142][283] = 1;
TABLE[142][280] = 1;
TABLE[143][286] = 1;
TABLE[143][260] = 1;
TABLE[144][286] = 1;
TABLE[144][260] = 1;
TABLE[144][284] = 1;
TABLE[144][277] = 1;
TABLE[144][264] = 1;
TABLE[144][268] = 1;
TABLE[144][273] = 1;
TABLE[144][272] = 1;
TABLE[144][276] = 1;
TABLE[144][259] = 1;
TABLE[144][285] = 1;
TABLE[144][266] = 1;
TABLE[144][299] = 1;
TABLE[144][283] = 1;
TABLE[144][280] = 1;
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
TABLE[145][44] = 1;
TABLE[145][58] = 1;
TABLE[145][40] = 1;
TABLE[145][42] = 1;
TABLE[145][299] = 1;
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
TABLE[146][58] = 1;
TABLE[146][40] = 1;
TABLE[146][42] = 1;
TABLE[146][299] = 1;
TABLE[231][58] = 1;
TABLE[25][266] = 1;
TABLE[26][266] = 1;
TABLE[147][299] = 1;
TABLE[232][123] = 1;
TABLE[27][44] = 1;
TABLE[27][299] = 1;
TABLE[148][44] = 1;
TABLE[148][299] = 1;
TABLE[233][299] = 1;
TABLE[28][299] = 1;
TABLE[149][61] = 1;
TABLE[234][125] = 1;
TABLE[234][44] = 1;
TABLE[29][40] = 1;
TABLE[29][299] = 1;
TABLE[29][42] = 1;
TABLE[150][42] = 1;
TABLE[235][40] = 1;
TABLE[235][299] = 1;
TABLE[30][299] = 1;
TABLE[31][40] = 1;
TABLE[32][40] = 1;
TABLE[32][299] = 1;
TABLE[152][91] = 1;
TABLE[153][40] = 1;
TABLE[155][40] = 1;
TABLE[151][93] = 1;
TABLE[151][44] = 1;
TABLE[151][278] = 1;
TABLE[151][63] = 1;
TABLE[151][295] = 1;
TABLE[151][294] = 1;
TABLE[151][40] = 1;
TABLE[151][38] = 1;
TABLE[151][42] = 1;
TABLE[151][43] = 1;
TABLE[151][45] = 1;
TABLE[151][126] = 1;
TABLE[151][33] = 1;
TABLE[151][124] = 1;
TABLE[151][94] = 1;
TABLE[151][297] = 1;
TABLE[151][299] = 1;
TABLE[151][289] = 1;
TABLE[151][303] = 1;
TABLE[151][302] = 1;
TABLE[151][304] = 1;
TABLE[151][298] = 1;
TABLE[151][292] = 1;
TABLE[151][300] = 1;
TABLE[151][37] = 1;
TABLE[151][47] = 1;
TABLE[236][93] = 1;
TABLE[154][41] = 1;
TABLE[154][44] = 1;
TABLE[154][299] = 1;
TABLE[237][41] = 1;
TABLE[33][42] = 1;
TABLE[156][42] = 1;
TABLE[156][40] = 1;
TABLE[156][299] = 1;
TABLE[156][44] = 1;
TABLE[156][41] = 1;
TABLE[156][91] = 1;
TABLE[156][260] = 1;
TABLE[156][286] = 1;
TABLE[238][42] = 1;
TABLE[238][40] = 1;
TABLE[238][299] = 1;
TABLE[238][44] = 1;
TABLE[238][41] = 1;
TABLE[238][91] = 1;
TABLE[157][42] = 1;
TABLE[239][40] = 1;
TABLE[239][299] = 1;
TABLE[239][44] = 1;
TABLE[239][41] = 1;
TABLE[239][91] = 1;
TABLE[34][286] = 1;
TABLE[34][260] = 1;
TABLE[158][260] = 1;
TABLE[158][286] = 1;
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
TABLE[159][44] = 1;
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
TABLE[160][44] = 1;
TABLE[160][40] = 1;
TABLE[160][42] = 1;
TABLE[160][286] = 1;
TABLE[160][260] = 1;
TABLE[160][284] = 1;
TABLE[160][277] = 1;
TABLE[160][264] = 1;
TABLE[160][268] = 1;
TABLE[160][273] = 1;
TABLE[160][272] = 1;
TABLE[160][276] = 1;
TABLE[160][259] = 1;
TABLE[160][285] = 1;
TABLE[160][266] = 1;
TABLE[160][299] = 1;
TABLE[160][282] = 1;
TABLE[160][267] = 1;
TABLE[160][279] = 1;
TABLE[160][274] = 1;
TABLE[160][256] = 1;
TABLE[160][91] = 1;
TABLE[160][283] = 1;
TABLE[160][280] = 1;
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
TABLE[161][44] = 1;
TABLE[161][41] = 1;
TABLE[161][40] = 1;
TABLE[161][42] = 1;
TABLE[161][299] = 1;
TABLE[163][44] = 1;
TABLE[163][41] = 1;
TABLE[163][42] = 1;
TABLE[163][40] = 1;
TABLE[163][91] = 1;
TABLE[162][44] = 1;
TABLE[162][41] = 1;
TABLE[162][42] = 1;
TABLE[162][40] = 1;
TABLE[162][91] = 1;
TABLE[243][44] = 1;
TABLE[243][41] = 1;
TABLE[38][44] = 1;
TABLE[38][299] = 1;
TABLE[164][44] = 1;
TABLE[164][299] = 1;
TABLE[244][299] = 1;
TABLE[39][59] = 1;
TABLE[39][44] = 1;
TABLE[39][125] = 1;
TABLE[39][63] = 1;
TABLE[39][278] = 1;
TABLE[39][294] = 1;
TABLE[39][295] = 1;
TABLE[39][297] = 1;
TABLE[39][94] = 1;
TABLE[39][124] = 1;
TABLE[39][33] = 1;
TABLE[39][126] = 1;
TABLE[39][45] = 1;
TABLE[39][43] = 1;
TABLE[39][42] = 1;
TABLE[39][38] = 1;
TABLE[39][40] = 1;
TABLE[39][298] = 1;
TABLE[39][304] = 1;
TABLE[39][302] = 1;
TABLE[39][303] = 1;
TABLE[39][289] = 1;
TABLE[39][299] = 1;
TABLE[39][292] = 1;
TABLE[39][300] = 1;
TABLE[39][47] = 1;
TABLE[39][37] = 1;
TABLE[40][123] = 1;
TABLE[165][44] = 1;
TABLE[245][125] = 1;
TABLE[41][125] = 1;
TABLE[41][123] = 1;
TABLE[41][44] = 1;
TABLE[41][278] = 1;
TABLE[41][63] = 1;
TABLE[41][295] = 1;
TABLE[41][294] = 1;
TABLE[41][40] = 1;
TABLE[41][38] = 1;
TABLE[41][42] = 1;
TABLE[41][43] = 1;
TABLE[41][45] = 1;
TABLE[41][126] = 1;
TABLE[41][33] = 1;
TABLE[41][124] = 1;
TABLE[41][94] = 1;
TABLE[41][297] = 1;
TABLE[41][299] = 1;
TABLE[41][289] = 1;
TABLE[41][303] = 1;
TABLE[41][302] = 1;
TABLE[41][304] = 1;
TABLE[41][298] = 1;
TABLE[41][292] = 1;
TABLE[41][300] = 1;
TABLE[41][37] = 1;
TABLE[41][47] = 1;
TABLE[166][123] = 1;
TABLE[166][44] = 1;
TABLE[166][63] = 1;
TABLE[166][278] = 1;
TABLE[166][294] = 1;
TABLE[166][295] = 1;
TABLE[166][297] = 1;
TABLE[166][94] = 1;
TABLE[166][124] = 1;
TABLE[166][33] = 1;
TABLE[166][126] = 1;
TABLE[166][45] = 1;
TABLE[166][43] = 1;
TABLE[166][42] = 1;
TABLE[166][38] = 1;
TABLE[166][40] = 1;
TABLE[166][298] = 1;
TABLE[166][304] = 1;
TABLE[166][302] = 1;
TABLE[166][303] = 1;
TABLE[166][289] = 1;
TABLE[166][299] = 1;
TABLE[166][292] = 1;
TABLE[166][300] = 1;
TABLE[166][47] = 1;
TABLE[166][37] = 1;
TABLE[246][123] = 1;
TABLE[246][278] = 1;
TABLE[246][63] = 1;
TABLE[246][295] = 1;
TABLE[246][294] = 1;
TABLE[246][40] = 1;
TABLE[246][38] = 1;
TABLE[246][42] = 1;
TABLE[246][43] = 1;
TABLE[246][45] = 1;
TABLE[246][126] = 1;
TABLE[246][33] = 1;
TABLE[246][124] = 1;
TABLE[246][94] = 1;
TABLE[246][297] = 1;
TABLE[246][299] = 1;
TABLE[246][289] = 1;
TABLE[246][303] = 1;
TABLE[246][302] = 1;
TABLE[246][304] = 1;
TABLE[246][298] = 1;
TABLE[246][292] = 1;
TABLE[246][300] = 1;
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
TABLE[167][41] = 1;
TABLE[167][42] = 1;
TABLE[167][40] = 1;
TABLE[167][91] = 1;
TABLE[247][41] = 1;
TABLE[43][42] = 1;
TABLE[44][44] = 1;
TABLE[44][41] = 1;
TABLE[44][40] = 1;
TABLE[44][91] = 1;
TABLE[44][42] = 1;
TABLE[168][42] = 1;
TABLE[248][40] = 1;
TABLE[248][91] = 1;
TABLE[248][44] = 1;
TABLE[248][41] = 1;
TABLE[45][40] = 1;
TABLE[46][40] = 1;
TABLE[46][91] = 1;
TABLE[169][40] = 1;
TABLE[169][91] = 1;
TABLE[249][91] = 1;
TABLE[249][40] = 1;
TABLE[171][91] = 1;
TABLE[173][40] = 1;
TABLE[170][93] = 1;
TABLE[170][44] = 1;
TABLE[170][278] = 1;
TABLE[170][63] = 1;
TABLE[170][295] = 1;
TABLE[170][294] = 1;
TABLE[170][40] = 1;
TABLE[170][38] = 1;
TABLE[170][42] = 1;
TABLE[170][43] = 1;
TABLE[170][45] = 1;
TABLE[170][126] = 1;
TABLE[170][33] = 1;
TABLE[170][124] = 1;
TABLE[170][94] = 1;
TABLE[170][297] = 1;
TABLE[170][299] = 1;
TABLE[170][289] = 1;
TABLE[170][303] = 1;
TABLE[170][302] = 1;
TABLE[170][304] = 1;
TABLE[170][298] = 1;
TABLE[170][292] = 1;
TABLE[170][300] = 1;
TABLE[170][37] = 1;
TABLE[170][47] = 1;
TABLE[250][93] = 1;
TABLE[172][41] = 1;
TABLE[172][44] = 1;
TABLE[172][40] = 1;
TABLE[172][256] = 1;
TABLE[172][274] = 1;
TABLE[172][279] = 1;
TABLE[172][267] = 1;
TABLE[172][282] = 1;
TABLE[172][299] = 1;
TABLE[172][266] = 1;
TABLE[172][285] = 1;
TABLE[172][259] = 1;
TABLE[172][276] = 1;
TABLE[172][272] = 1;
TABLE[172][273] = 1;
TABLE[172][268] = 1;
TABLE[172][264] = 1;
TABLE[172][277] = 1;
TABLE[172][284] = 1;
TABLE[172][260] = 1;
TABLE[172][286] = 1;
TABLE[172][42] = 1;
TABLE[172][280] = 1;
TABLE[172][283] = 1;
TABLE[172][91] = 1;
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
TABLE[49][305] = 1;
TABLE[49][306] = 1;
TABLE[49][265] = 1;
TABLE[49][59] = 1;
TABLE[49][44] = 1;
TABLE[49][278] = 1;
TABLE[49][63] = 1;
TABLE[49][295] = 1;
TABLE[49][294] = 1;
TABLE[49][40] = 1;
TABLE[49][38] = 1;
TABLE[49][42] = 1;
TABLE[49][43] = 1;
TABLE[49][45] = 1;
TABLE[49][126] = 1;
TABLE[49][33] = 1;
TABLE[49][124] = 1;
TABLE[49][94] = 1;
TABLE[49][297] = 1;
TABLE[49][299] = 1;
TABLE[49][289] = 1;
TABLE[49][303] = 1;
TABLE[49][302] = 1;
TABLE[49][304] = 1;
TABLE[49][298] = 1;
TABLE[49][292] = 1;
TABLE[49][300] = 1;
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
TABLE[54][305] = 1;
TABLE[55][306] = 1;
TABLE[56][299] = 1;
TABLE[57][258] = 1;
TABLE[58][262] = 1;
TABLE[59][59] = 1;
TABLE[59][44] = 1;
TABLE[59][63] = 1;
TABLE[59][278] = 1;
TABLE[59][294] = 1;
TABLE[59][295] = 1;
TABLE[59][297] = 1;
TABLE[59][94] = 1;
TABLE[59][124] = 1;
TABLE[59][33] = 1;
TABLE[59][126] = 1;
TABLE[59][45] = 1;
TABLE[59][43] = 1;
TABLE[59][42] = 1;
TABLE[59][38] = 1;
TABLE[59][40] = 1;
TABLE[59][298] = 1;
TABLE[59][304] = 1;
TABLE[59][302] = 1;
TABLE[59][303] = 1;
TABLE[59][289] = 1;
TABLE[59][299] = 1;
TABLE[59][292] = 1;
TABLE[59][300] = 1;
TABLE[59][47] = 1;
TABLE[59][37] = 1;
TABLE[174][59] = 1;
TABLE[174][44] = 1;
TABLE[174][278] = 1;
TABLE[174][63] = 1;
TABLE[174][295] = 1;
TABLE[174][294] = 1;
TABLE[174][40] = 1;
TABLE[174][38] = 1;
TABLE[174][42] = 1;
TABLE[174][43] = 1;
TABLE[174][45] = 1;
TABLE[174][126] = 1;
TABLE[174][33] = 1;
TABLE[174][124] = 1;
TABLE[174][94] = 1;
TABLE[174][297] = 1;
TABLE[174][299] = 1;
TABLE[174][289] = 1;
TABLE[174][303] = 1;
TABLE[174][302] = 1;
TABLE[174][304] = 1;
TABLE[174][298] = 1;
TABLE[174][292] = 1;
TABLE[174][300] = 1;
TABLE[174][37] = 1;
TABLE[174][47] = 1;
TABLE[252][59] = 1;
TABLE[60][123] = 1;
TABLE[175][262] = 1;
TABLE[175][258] = 1;
TABLE[175][281] = 1;
TABLE[175][271] = 1;
TABLE[175][269] = 1;
TABLE[175][263] = 1;
TABLE[175][287] = 1;
TABLE[175][275] = 1;
TABLE[175][257] = 1;
TABLE[175][261] = 1;
TABLE[175][270] = 1;
TABLE[175][305] = 1;
TABLE[175][306] = 1;
TABLE[175][125] = 1;
TABLE[175][59] = 1;
TABLE[175][44] = 1;
TABLE[175][61] = 1;
TABLE[175][123] = 1;
TABLE[175][286] = 1;
TABLE[175][260] = 1;
TABLE[175][284] = 1;
TABLE[175][277] = 1;
TABLE[175][264] = 1;
TABLE[175][268] = 1;
TABLE[175][273] = 1;
TABLE[175][272] = 1;
TABLE[175][276] = 1;
TABLE[175][259] = 1;
TABLE[175][285] = 1;
TABLE[175][266] = 1;
TABLE[175][299] = 1;
TABLE[175][282] = 1;
TABLE[175][267] = 1;
TABLE[175][279] = 1;
TABLE[175][274] = 1;
TABLE[175][256] = 1;
TABLE[175][40] = 1;
TABLE[175][63] = 1;
TABLE[175][278] = 1;
TABLE[175][283] = 1;
TABLE[175][280] = 1;
TABLE[175][42] = 1;
TABLE[175][294] = 1;
TABLE[175][295] = 1;
TABLE[175][297] = 1;
TABLE[175][94] = 1;
TABLE[175][124] = 1;
TABLE[175][33] = 1;
TABLE[175][126] = 1;
TABLE[175][45] = 1;
TABLE[175][43] = 1;
TABLE[175][38] = 1;
TABLE[175][298] = 1;
TABLE[175][304] = 1;
TABLE[175][302] = 1;
TABLE[175][303] = 1;
TABLE[175][289] = 1;
TABLE[175][292] = 1;
TABLE[175][300] = 1;
TABLE[175][47] = 1;
TABLE[175][37] = 1;
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
TABLE[253][305] = 1;
TABLE[253][306] = 1;
TABLE[253][299] = 1;
TABLE[253][44] = 1;
TABLE[253][63] = 1;
TABLE[253][278] = 1;
TABLE[253][294] = 1;
TABLE[253][295] = 1;
TABLE[253][297] = 1;
TABLE[253][94] = 1;
TABLE[253][124] = 1;
TABLE[253][33] = 1;
TABLE[253][126] = 1;
TABLE[253][45] = 1;
TABLE[253][43] = 1;
TABLE[253][42] = 1;
TABLE[253][38] = 1;
TABLE[253][40] = 1;
TABLE[253][298] = 1;
TABLE[253][304] = 1;
TABLE[253][302] = 1;
TABLE[253][303] = 1;
TABLE[253][289] = 1;
TABLE[253][292] = 1;
TABLE[253][300] = 1;
TABLE[253][47] = 1;
TABLE[253][37] = 1;
TABLE[253][125] = 1;
TABLE[176][125] = 1;
TABLE[176][306] = 1;
TABLE[176][305] = 1;
TABLE[176][270] = 1;
TABLE[176][261] = 1;
TABLE[176][257] = 1;
TABLE[176][275] = 1;
TABLE[176][287] = 1;
TABLE[176][263] = 1;
TABLE[176][269] = 1;
TABLE[176][271] = 1;
TABLE[176][281] = 1;
TABLE[176][123] = 1;
TABLE[176][59] = 1;
TABLE[176][258] = 1;
TABLE[176][262] = 1;
TABLE[176][299] = 1;
TABLE[176][44] = 1;
TABLE[176][278] = 1;
TABLE[176][63] = 1;
TABLE[176][295] = 1;
TABLE[176][294] = 1;
TABLE[176][40] = 1;
TABLE[176][38] = 1;
TABLE[176][42] = 1;
TABLE[176][43] = 1;
TABLE[176][45] = 1;
TABLE[176][126] = 1;
TABLE[176][33] = 1;
TABLE[176][124] = 1;
TABLE[176][94] = 1;
TABLE[176][297] = 1;
TABLE[176][289] = 1;
TABLE[176][303] = 1;
TABLE[176][302] = 1;
TABLE[176][304] = 1;
TABLE[176][298] = 1;
TABLE[176][292] = 1;
TABLE[176][300] = 1;
TABLE[176][37] = 1;
TABLE[176][47] = 1;
TABLE[254][125] = 1;
TABLE[61][125] = 1;
TABLE[61][306] = 1;
TABLE[61][305] = 1;
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
TABLE[61][63] = 1;
TABLE[61][295] = 1;
TABLE[61][294] = 1;
TABLE[61][40] = 1;
TABLE[61][38] = 1;
TABLE[61][42] = 1;
TABLE[61][43] = 1;
TABLE[61][45] = 1;
TABLE[61][126] = 1;
TABLE[61][33] = 1;
TABLE[61][124] = 1;
TABLE[61][94] = 1;
TABLE[61][297] = 1;
TABLE[61][289] = 1;
TABLE[61][303] = 1;
TABLE[61][302] = 1;
TABLE[61][304] = 1;
TABLE[61][298] = 1;
TABLE[61][292] = 1;
TABLE[61][300] = 1;
TABLE[61][37] = 1;
TABLE[61][47] = 1;
TABLE[177][125] = 1;
TABLE[177][262] = 1;
TABLE[177][258] = 1;
TABLE[177][59] = 1;
TABLE[177][123] = 1;
TABLE[177][281] = 1;
TABLE[177][271] = 1;
TABLE[177][269] = 1;
TABLE[177][263] = 1;
TABLE[177][287] = 1;
TABLE[177][275] = 1;
TABLE[177][257] = 1;
TABLE[177][261] = 1;
TABLE[177][270] = 1;
TABLE[177][305] = 1;
TABLE[177][306] = 1;
TABLE[177][299] = 1;
TABLE[177][44] = 1;
TABLE[177][63] = 1;
TABLE[177][278] = 1;
TABLE[177][294] = 1;
TABLE[177][295] = 1;
TABLE[177][297] = 1;
TABLE[177][94] = 1;
TABLE[177][124] = 1;
TABLE[177][33] = 1;
TABLE[177][126] = 1;
TABLE[177][45] = 1;
TABLE[177][43] = 1;
TABLE[177][42] = 1;
TABLE[177][38] = 1;
TABLE[177][40] = 1;
TABLE[177][298] = 1;
TABLE[177][304] = 1;
TABLE[177][302] = 1;
TABLE[177][303] = 1;
TABLE[177][289] = 1;
TABLE[177][292] = 1;
TABLE[177][300] = 1;
TABLE[177][47] = 1;
TABLE[177][37] = 1;
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
TABLE[255][305] = 1;
TABLE[255][306] = 1;
TABLE[255][299] = 1;
TABLE[255][44] = 1;
TABLE[255][63] = 1;
TABLE[255][278] = 1;
TABLE[255][294] = 1;
TABLE[255][295] = 1;
TABLE[255][297] = 1;
TABLE[255][94] = 1;
TABLE[255][124] = 1;
TABLE[255][33] = 1;
TABLE[255][126] = 1;
TABLE[255][45] = 1;
TABLE[255][43] = 1;
TABLE[255][42] = 1;
TABLE[255][38] = 1;
TABLE[255][40] = 1;
TABLE[255][298] = 1;
TABLE[255][304] = 1;
TABLE[255][302] = 1;
TABLE[255][303] = 1;
TABLE[255][289] = 1;
TABLE[255][292] = 1;
TABLE[255][300] = 1;
TABLE[255][47] = 1;
TABLE[255][37] = 1;
TABLE[255][125] = 1;
TABLE[62][271] = 1;
TABLE[63][281] = 1;
TABLE[178][265] = 1;
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
TABLE[256][305] = 1;
TABLE[256][306] = 1;
TABLE[256][299] = 1;
TABLE[256][44] = 1;
TABLE[256][63] = 1;
TABLE[256][278] = 1;
TABLE[256][294] = 1;
TABLE[256][295] = 1;
TABLE[256][297] = 1;
TABLE[256][94] = 1;
TABLE[256][124] = 1;
TABLE[256][33] = 1;
TABLE[256][126] = 1;
TABLE[256][45] = 1;
TABLE[256][43] = 1;
TABLE[256][42] = 1;
TABLE[256][38] = 1;
TABLE[256][40] = 1;
TABLE[256][298] = 1;
TABLE[256][304] = 1;
TABLE[256][302] = 1;
TABLE[256][303] = 1;
TABLE[256][289] = 1;
TABLE[256][292] = 1;
TABLE[256][300] = 1;
TABLE[256][47] = 1;
TABLE[256][37] = 1;
TABLE[256][265] = 1;
TABLE[64][287] = 1;
TABLE[65][263] = 1;
TABLE[66][269] = 1;
TABLE[179][59] = 1;
TABLE[179][44] = 1;
TABLE[179][278] = 1;
TABLE[179][63] = 1;
TABLE[179][295] = 1;
TABLE[179][294] = 1;
TABLE[179][40] = 1;
TABLE[179][38] = 1;
TABLE[179][42] = 1;
TABLE[179][43] = 1;
TABLE[179][45] = 1;
TABLE[179][126] = 1;
TABLE[179][33] = 1;
TABLE[179][124] = 1;
TABLE[179][94] = 1;
TABLE[179][297] = 1;
TABLE[179][299] = 1;
TABLE[179][289] = 1;
TABLE[179][303] = 1;
TABLE[179][302] = 1;
TABLE[179][304] = 1;
TABLE[179][298] = 1;
TABLE[179][292] = 1;
TABLE[179][300] = 1;
TABLE[179][37] = 1;
TABLE[179][47] = 1;
TABLE[257][59] = 1;
TABLE[180][59] = 1;
TABLE[180][44] = 1;
TABLE[180][278] = 1;
TABLE[180][63] = 1;
TABLE[180][295] = 1;
TABLE[180][294] = 1;
TABLE[180][40] = 1;
TABLE[180][38] = 1;
TABLE[180][42] = 1;
TABLE[180][43] = 1;
TABLE[180][45] = 1;
TABLE[180][126] = 1;
TABLE[180][33] = 1;
TABLE[180][124] = 1;
TABLE[180][94] = 1;
TABLE[180][297] = 1;
TABLE[180][299] = 1;
TABLE[180][289] = 1;
TABLE[180][303] = 1;
TABLE[180][302] = 1;
TABLE[180][304] = 1;
TABLE[180][298] = 1;
TABLE[180][292] = 1;
TABLE[180][300] = 1;
TABLE[180][37] = 1;
TABLE[180][47] = 1;
TABLE[258][59] = 1;
TABLE[181][41] = 1;
TABLE[181][44] = 1;
TABLE[181][278] = 1;
TABLE[181][63] = 1;
TABLE[181][295] = 1;
TABLE[181][294] = 1;
TABLE[181][40] = 1;
TABLE[181][38] = 1;
TABLE[181][42] = 1;
TABLE[181][43] = 1;
TABLE[181][45] = 1;
TABLE[181][126] = 1;
TABLE[181][33] = 1;
TABLE[181][124] = 1;
TABLE[181][94] = 1;
TABLE[181][297] = 1;
TABLE[181][299] = 1;
TABLE[181][289] = 1;
TABLE[181][303] = 1;
TABLE[181][302] = 1;
TABLE[181][304] = 1;
TABLE[181][298] = 1;
TABLE[181][292] = 1;
TABLE[181][300] = 1;
TABLE[181][37] = 1;
TABLE[181][47] = 1;
TABLE[259][41] = 1;
TABLE[67][270] = 1;
TABLE[68][261] = 1;
TABLE[69][257] = 1;
TABLE[70][275] = 1;
TABLE[182][59] = 1;
TABLE[182][44] = 1;
TABLE[182][278] = 1;
TABLE[182][63] = 1;
TABLE[182][295] = 1;
TABLE[182][294] = 1;
TABLE[182][40] = 1;
TABLE[182][38] = 1;
TABLE[182][42] = 1;
TABLE[182][43] = 1;
TABLE[182][45] = 1;
TABLE[182][126] = 1;
TABLE[182][33] = 1;
TABLE[182][124] = 1;
TABLE[182][94] = 1;
TABLE[182][297] = 1;
TABLE[182][299] = 1;
TABLE[182][289] = 1;
TABLE[182][303] = 1;
TABLE[182][302] = 1;
TABLE[182][304] = 1;
TABLE[182][298] = 1;
TABLE[182][292] = 1;
TABLE[182][300] = 1;
TABLE[182][37] = 1;
TABLE[182][47] = 1;
TABLE[260][59] = 1;
TABLE[71][305] = 1;
TABLE[72][306] = 1;
TABLE[183][299] = 1;
TABLE[261][299] = 1;
TABLE[73][93] = 1;
TABLE[73][59] = 1;
TABLE[73][41] = 1;
TABLE[73][58] = 1;
TABLE[73][44] = 1;
TABLE[73][63] = 1;
TABLE[73][278] = 1;
TABLE[73][294] = 1;
TABLE[73][295] = 1;
TABLE[73][297] = 1;
TABLE[73][94] = 1;
TABLE[73][124] = 1;
TABLE[73][33] = 1;
TABLE[73][126] = 1;
TABLE[73][45] = 1;
TABLE[73][43] = 1;
TABLE[73][42] = 1;
TABLE[73][38] = 1;
TABLE[73][40] = 1;
TABLE[73][298] = 1;
TABLE[73][304] = 1;
TABLE[73][302] = 1;
TABLE[73][303] = 1;
TABLE[73][289] = 1;
TABLE[73][299] = 1;
TABLE[73][292] = 1;
TABLE[73][300] = 1;
TABLE[73][47] = 1;
TABLE[73][37] = 1;
TABLE[184][44] = 1;
TABLE[184][278] = 1;
TABLE[184][63] = 1;
TABLE[184][295] = 1;
TABLE[184][294] = 1;
TABLE[184][40] = 1;
TABLE[184][38] = 1;
TABLE[184][42] = 1;
TABLE[184][43] = 1;
TABLE[184][45] = 1;
TABLE[184][126] = 1;
TABLE[184][33] = 1;
TABLE[184][124] = 1;
TABLE[184][94] = 1;
TABLE[184][297] = 1;
TABLE[184][299] = 1;
TABLE[184][289] = 1;
TABLE[184][303] = 1;
TABLE[184][302] = 1;
TABLE[184][304] = 1;
TABLE[184][298] = 1;
TABLE[184][292] = 1;
TABLE[184][300] = 1;
TABLE[184][37] = 1;
TABLE[184][47] = 1;
TABLE[262][63] = 1;
TABLE[262][278] = 1;
TABLE[262][294] = 1;
TABLE[262][295] = 1;
TABLE[262][297] = 1;
TABLE[262][94] = 1;
TABLE[262][124] = 1;
TABLE[262][33] = 1;
TABLE[262][126] = 1;
TABLE[262][45] = 1;
TABLE[262][43] = 1;
TABLE[262][42] = 1;
TABLE[262][38] = 1;
TABLE[262][40] = 1;
TABLE[262][298] = 1;
TABLE[262][304] = 1;
TABLE[262][302] = 1;
TABLE[262][303] = 1;
TABLE[262][289] = 1;
TABLE[262][299] = 1;
TABLE[262][292] = 1;
TABLE[262][300] = 1;
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
TABLE[74][124] = 1;
TABLE[74][94] = 1;
TABLE[74][38] = 1;
TABLE[74][292] = 1;
TABLE[74][300] = 1;
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
TABLE[74][304] = 1;
TABLE[74][302] = 1;
TABLE[74][303] = 1;
TABLE[74][289] = 1;
TABLE[74][299] = 1;
TABLE[75][278] = 1;
TABLE[75][295] = 1;
TABLE[75][294] = 1;
TABLE[75][40] = 1;
TABLE[75][38] = 1;
TABLE[75][42] = 1;
TABLE[75][43] = 1;
TABLE[75][45] = 1;
TABLE[75][126] = 1;
TABLE[75][33] = 1;
TABLE[75][124] = 1;
TABLE[75][94] = 1;
TABLE[75][299] = 1;
TABLE[75][289] = 1;
TABLE[75][303] = 1;
TABLE[75][302] = 1;
TABLE[75][304] = 1;
TABLE[76][291] = 1;
TABLE[77][61] = 1;
TABLE[78][59] = 1;
TABLE[78][93] = 1;
TABLE[78][41] = 1;
TABLE[78][125] = 1;
TABLE[78][58] = 1;
TABLE[78][44] = 1;
TABLE[78][297] = 1;
TABLE[78][298] = 1;
TABLE[78][124] = 1;
TABLE[78][94] = 1;
TABLE[78][38] = 1;
TABLE[78][292] = 1;
TABLE[78][300] = 1;
TABLE[78][40] = 1;
TABLE[78][45] = 1;
TABLE[78][43] = 1;
TABLE[78][42] = 1;
TABLE[78][47] = 1;
TABLE[78][37] = 1;
TABLE[78][278] = 1;
TABLE[78][295] = 1;
TABLE[78][294] = 1;
TABLE[78][126] = 1;
TABLE[78][33] = 1;
TABLE[78][299] = 1;
TABLE[78][289] = 1;
TABLE[78][303] = 1;
TABLE[78][302] = 1;
TABLE[78][304] = 1;
TABLE[79][63] = 1;
TABLE[79][297] = 1;
TABLE[79][298] = 1;
TABLE[79][124] = 1;
TABLE[79][94] = 1;
TABLE[79][38] = 1;
TABLE[79][292] = 1;
TABLE[79][300] = 1;
TABLE[79][40] = 1;
TABLE[79][45] = 1;
TABLE[79][43] = 1;
TABLE[79][42] = 1;
TABLE[79][47] = 1;
TABLE[79][37] = 1;
TABLE[79][278] = 1;
TABLE[79][295] = 1;
TABLE[79][294] = 1;
TABLE[79][126] = 1;
TABLE[79][33] = 1;
TABLE[79][299] = 1;
TABLE[79][289] = 1;
TABLE[79][303] = 1;
TABLE[79][302] = 1;
TABLE[79][304] = 1;
TABLE[80][59] = 1;
TABLE[80][125] = 1;
TABLE[80][58] = 1;
TABLE[80][44] = 1;
TABLE[80][63] = 1;
TABLE[80][297] = 1;
TABLE[80][298] = 1;
TABLE[80][124] = 1;
TABLE[80][94] = 1;
TABLE[80][38] = 1;
TABLE[80][292] = 1;
TABLE[80][300] = 1;
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
TABLE[80][304] = 1;
TABLE[80][302] = 1;
TABLE[80][303] = 1;
TABLE[80][289] = 1;
TABLE[80][299] = 1;
TABLE[81][59] = 1;
TABLE[81][93] = 1;
TABLE[81][41] = 1;
TABLE[81][63] = 1;
TABLE[81][125] = 1;
TABLE[81][58] = 1;
TABLE[81][44] = 1;
TABLE[81][297] = 1;
TABLE[81][298] = 1;
TABLE[81][124] = 1;
TABLE[81][94] = 1;
TABLE[81][38] = 1;
TABLE[81][292] = 1;
TABLE[81][300] = 1;
TABLE[81][43] = 1;
TABLE[81][45] = 1;
TABLE[81][40] = 1;
TABLE[81][278] = 1;
TABLE[81][37] = 1;
TABLE[81][47] = 1;
TABLE[81][42] = 1;
TABLE[81][294] = 1;
TABLE[81][295] = 1;
TABLE[81][33] = 1;
TABLE[81][126] = 1;
TABLE[81][304] = 1;
TABLE[81][302] = 1;
TABLE[81][303] = 1;
TABLE[81][289] = 1;
TABLE[81][299] = 1;
TABLE[185][297] = 1;
TABLE[185][298] = 1;
TABLE[185][124] = 1;
TABLE[185][94] = 1;
TABLE[185][38] = 1;
TABLE[185][292] = 1;
TABLE[185][300] = 1;
TABLE[185][40] = 1;
TABLE[185][45] = 1;
TABLE[185][43] = 1;
TABLE[185][42] = 1;
TABLE[185][47] = 1;
TABLE[185][37] = 1;
TABLE[185][278] = 1;
TABLE[185][295] = 1;
TABLE[185][294] = 1;
TABLE[185][126] = 1;
TABLE[185][33] = 1;
TABLE[185][299] = 1;
TABLE[185][289] = 1;
TABLE[185][303] = 1;
TABLE[185][302] = 1;
TABLE[185][304] = 1;
TABLE[263][298] = 1;
TABLE[263][124] = 1;
TABLE[263][94] = 1;
TABLE[263][38] = 1;
TABLE[263][292] = 1;
TABLE[263][300] = 1;
TABLE[263][43] = 1;
TABLE[263][45] = 1;
TABLE[263][40] = 1;
TABLE[263][278] = 1;
TABLE[263][37] = 1;
TABLE[263][47] = 1;
TABLE[263][42] = 1;
TABLE[263][294] = 1;
TABLE[263][295] = 1;
TABLE[263][33] = 1;
TABLE[263][126] = 1;
TABLE[263][304] = 1;
TABLE[263][302] = 1;
TABLE[263][303] = 1;
TABLE[263][289] = 1;
TABLE[263][299] = 1;
TABLE[263][59] = 1;
TABLE[263][93] = 1;
TABLE[263][41] = 1;
TABLE[263][63] = 1;
TABLE[263][297] = 1;
TABLE[263][125] = 1;
TABLE[263][58] = 1;
TABLE[263][44] = 1;
TABLE[82][59] = 1;
TABLE[82][93] = 1;
TABLE[82][41] = 1;
TABLE[82][63] = 1;
TABLE[82][297] = 1;
TABLE[82][125] = 1;
TABLE[82][58] = 1;
TABLE[82][44] = 1;
TABLE[82][298] = 1;
TABLE[82][124] = 1;
TABLE[82][94] = 1;
TABLE[82][38] = 1;
TABLE[82][292] = 1;
TABLE[82][300] = 1;
TABLE[82][40] = 1;
TABLE[82][45] = 1;
TABLE[82][43] = 1;
TABLE[82][42] = 1;
TABLE[82][47] = 1;
TABLE[82][37] = 1;
TABLE[82][278] = 1;
TABLE[82][295] = 1;
TABLE[82][294] = 1;
TABLE[82][126] = 1;
TABLE[82][33] = 1;
TABLE[82][299] = 1;
TABLE[82][289] = 1;
TABLE[82][303] = 1;
TABLE[82][302] = 1;
TABLE[82][304] = 1;
TABLE[186][298] = 1;
TABLE[186][124] = 1;
TABLE[186][94] = 1;
TABLE[186][38] = 1;
TABLE[186][292] = 1;
TABLE[186][300] = 1;
TABLE[186][43] = 1;
TABLE[186][45] = 1;
TABLE[186][40] = 1;
TABLE[186][278] = 1;
TABLE[186][37] = 1;
TABLE[186][47] = 1;
TABLE[186][42] = 1;
TABLE[186][294] = 1;
TABLE[186][295] = 1;
TABLE[186][33] = 1;
TABLE[186][126] = 1;
TABLE[186][304] = 1;
TABLE[186][302] = 1;
TABLE[186][303] = 1;
TABLE[186][289] = 1;
TABLE[186][299] = 1;
TABLE[264][124] = 1;
TABLE[264][94] = 1;
TABLE[264][38] = 1;
TABLE[264][292] = 1;
TABLE[264][300] = 1;
TABLE[264][40] = 1;
TABLE[264][45] = 1;
TABLE[264][43] = 1;
TABLE[264][42] = 1;
TABLE[264][47] = 1;
TABLE[264][37] = 1;
TABLE[264][278] = 1;
TABLE[264][295] = 1;
TABLE[264][294] = 1;
TABLE[264][126] = 1;
TABLE[264][33] = 1;
TABLE[264][299] = 1;
TABLE[264][289] = 1;
TABLE[264][303] = 1;
TABLE[264][302] = 1;
TABLE[264][304] = 1;
TABLE[264][59] = 1;
TABLE[264][93] = 1;
TABLE[264][41] = 1;
TABLE[264][63] = 1;
TABLE[264][298] = 1;
TABLE[264][297] = 1;
TABLE[264][125] = 1;
TABLE[264][58] = 1;
TABLE[264][44] = 1;
TABLE[83][59] = 1;
TABLE[83][93] = 1;
TABLE[83][41] = 1;
TABLE[83][63] = 1;
TABLE[83][298] = 1;
TABLE[83][297] = 1;
TABLE[83][125] = 1;
TABLE[83][58] = 1;
TABLE[83][44] = 1;
TABLE[83][124] = 1;
TABLE[83][94] = 1;
TABLE[83][38] = 1;
TABLE[83][292] = 1;
TABLE[83][300] = 1;
TABLE[83][43] = 1;
TABLE[83][45] = 1;
TABLE[83][40] = 1;
TABLE[83][278] = 1;
TABLE[83][37] = 1;
TABLE[83][47] = 1;
TABLE[83][42] = 1;
TABLE[83][294] = 1;
TABLE[83][295] = 1;
TABLE[83][33] = 1;
TABLE[83][126] = 1;
TABLE[83][304] = 1;
TABLE[83][302] = 1;
TABLE[83][303] = 1;
TABLE[83][289] = 1;
TABLE[83][299] = 1;
TABLE[187][124] = 1;
TABLE[187][94] = 1;
TABLE[187][38] = 1;
TABLE[187][292] = 1;
TABLE[187][300] = 1;
TABLE[187][40] = 1;
TABLE[187][45] = 1;
TABLE[187][43] = 1;
TABLE[187][42] = 1;
TABLE[187][47] = 1;
TABLE[187][37] = 1;
TABLE[187][278] = 1;
TABLE[187][295] = 1;
TABLE[187][294] = 1;
TABLE[187][126] = 1;
TABLE[187][33] = 1;
TABLE[187][299] = 1;
TABLE[187][289] = 1;
TABLE[187][303] = 1;
TABLE[187][302] = 1;
TABLE[187][304] = 1;
TABLE[265][94] = 1;
TABLE[265][38] = 1;
TABLE[265][292] = 1;
TABLE[265][300] = 1;
TABLE[265][43] = 1;
TABLE[265][45] = 1;
TABLE[265][40] = 1;
TABLE[265][278] = 1;
TABLE[265][37] = 1;
TABLE[265][47] = 1;
TABLE[265][42] = 1;
TABLE[265][294] = 1;
TABLE[265][295] = 1;
TABLE[265][124] = 1;
TABLE[265][33] = 1;
TABLE[265][126] = 1;
TABLE[265][304] = 1;
TABLE[265][302] = 1;
TABLE[265][303] = 1;
TABLE[265][289] = 1;
TABLE[265][299] = 1;
TABLE[265][59] = 1;
TABLE[265][93] = 1;
TABLE[265][41] = 1;
TABLE[265][63] = 1;
TABLE[265][298] = 1;
TABLE[265][297] = 1;
TABLE[265][125] = 1;
TABLE[265][58] = 1;
TABLE[265][44] = 1;
TABLE[84][59] = 1;
TABLE[84][93] = 1;
TABLE[84][41] = 1;
TABLE[84][63] = 1;
TABLE[84][298] = 1;
TABLE[84][297] = 1;
TABLE[84][125] = 1;
TABLE[84][58] = 1;
TABLE[84][44] = 1;
TABLE[84][94] = 1;
TABLE[84][38] = 1;
TABLE[84][292] = 1;
TABLE[84][300] = 1;
TABLE[84][40] = 1;
TABLE[84][45] = 1;
TABLE[84][43] = 1;
TABLE[84][42] = 1;
TABLE[84][47] = 1;
TABLE[84][37] = 1;
TABLE[84][278] = 1;
TABLE[84][295] = 1;
TABLE[84][294] = 1;
TABLE[84][126] = 1;
TABLE[84][33] = 1;
TABLE[84][124] = 1;
TABLE[84][299] = 1;
TABLE[84][289] = 1;
TABLE[84][303] = 1;
TABLE[84][302] = 1;
TABLE[84][304] = 1;
TABLE[188][94] = 1;
TABLE[188][38] = 1;
TABLE[188][292] = 1;
TABLE[188][300] = 1;
TABLE[188][43] = 1;
TABLE[188][45] = 1;
TABLE[188][40] = 1;
TABLE[188][278] = 1;
TABLE[188][37] = 1;
TABLE[188][47] = 1;
TABLE[188][42] = 1;
TABLE[188][294] = 1;
TABLE[188][295] = 1;
TABLE[188][124] = 1;
TABLE[188][33] = 1;
TABLE[188][126] = 1;
TABLE[188][304] = 1;
TABLE[188][302] = 1;
TABLE[188][303] = 1;
TABLE[188][289] = 1;
TABLE[188][299] = 1;
TABLE[266][38] = 1;
TABLE[266][292] = 1;
TABLE[266][300] = 1;
TABLE[266][40] = 1;
TABLE[266][45] = 1;
TABLE[266][43] = 1;
TABLE[266][42] = 1;
TABLE[266][47] = 1;
TABLE[266][37] = 1;
TABLE[266][278] = 1;
TABLE[266][295] = 1;
TABLE[266][294] = 1;
TABLE[266][126] = 1;
TABLE[266][33] = 1;
TABLE[266][124] = 1;
TABLE[266][94] = 1;
TABLE[266][299] = 1;
TABLE[266][289] = 1;
TABLE[266][303] = 1;
TABLE[266][302] = 1;
TABLE[266][304] = 1;
TABLE[266][59] = 1;
TABLE[266][93] = 1;
TABLE[266][41] = 1;
TABLE[266][63] = 1;
TABLE[266][298] = 1;
TABLE[266][297] = 1;
TABLE[266][125] = 1;
TABLE[266][58] = 1;
TABLE[266][44] = 1;
TABLE[85][59] = 1;
TABLE[85][93] = 1;
TABLE[85][41] = 1;
TABLE[85][63] = 1;
TABLE[85][298] = 1;
TABLE[85][297] = 1;
TABLE[85][125] = 1;
TABLE[85][58] = 1;
TABLE[85][44] = 1;
TABLE[85][38] = 1;
TABLE[85][292] = 1;
TABLE[85][300] = 1;
TABLE[85][43] = 1;
TABLE[85][45] = 1;
TABLE[85][40] = 1;
TABLE[85][278] = 1;
TABLE[85][37] = 1;
TABLE[85][47] = 1;
TABLE[85][42] = 1;
TABLE[85][294] = 1;
TABLE[85][295] = 1;
TABLE[85][94] = 1;
TABLE[85][124] = 1;
TABLE[85][33] = 1;
TABLE[85][126] = 1;
TABLE[85][304] = 1;
TABLE[85][302] = 1;
TABLE[85][303] = 1;
TABLE[85][289] = 1;
TABLE[85][299] = 1;
TABLE[189][38] = 1;
TABLE[189][292] = 1;
TABLE[189][300] = 1;
TABLE[189][40] = 1;
TABLE[189][45] = 1;
TABLE[189][43] = 1;
TABLE[189][42] = 1;
TABLE[189][47] = 1;
TABLE[189][37] = 1;
TABLE[189][278] = 1;
TABLE[189][295] = 1;
TABLE[189][294] = 1;
TABLE[189][126] = 1;
TABLE[189][33] = 1;
TABLE[189][124] = 1;
TABLE[189][94] = 1;
TABLE[189][299] = 1;
TABLE[189][289] = 1;
TABLE[189][303] = 1;
TABLE[189][302] = 1;
TABLE[189][304] = 1;
TABLE[267][292] = 1;
TABLE[267][300] = 1;
TABLE[267][43] = 1;
TABLE[267][45] = 1;
TABLE[267][40] = 1;
TABLE[267][278] = 1;
TABLE[267][37] = 1;
TABLE[267][47] = 1;
TABLE[267][42] = 1;
TABLE[267][294] = 1;
TABLE[267][295] = 1;
TABLE[267][94] = 1;
TABLE[267][124] = 1;
TABLE[267][33] = 1;
TABLE[267][126] = 1;
TABLE[267][38] = 1;
TABLE[267][304] = 1;
TABLE[267][302] = 1;
TABLE[267][303] = 1;
TABLE[267][289] = 1;
TABLE[267][299] = 1;
TABLE[267][59] = 1;
TABLE[267][93] = 1;
TABLE[267][41] = 1;
TABLE[267][63] = 1;
TABLE[267][298] = 1;
TABLE[267][297] = 1;
TABLE[267][125] = 1;
TABLE[267][58] = 1;
TABLE[267][44] = 1;
TABLE[86][59] = 1;
TABLE[86][93] = 1;
TABLE[86][41] = 1;
TABLE[86][63] = 1;
TABLE[86][298] = 1;
TABLE[86][297] = 1;
TABLE[86][125] = 1;
TABLE[86][58] = 1;
TABLE[86][44] = 1;
TABLE[86][292] = 1;
TABLE[86][300] = 1;
TABLE[86][40] = 1;
TABLE[86][45] = 1;
TABLE[86][43] = 1;
TABLE[86][42] = 1;
TABLE[86][47] = 1;
TABLE[86][37] = 1;
TABLE[86][278] = 1;
TABLE[86][295] = 1;
TABLE[86][294] = 1;
TABLE[86][38] = 1;
TABLE[86][126] = 1;
TABLE[86][33] = 1;
TABLE[86][124] = 1;
TABLE[86][94] = 1;
TABLE[86][299] = 1;
TABLE[86][289] = 1;
TABLE[86][303] = 1;
TABLE[86][302] = 1;
TABLE[86][304] = 1;
TABLE[190][292] = 1;
TABLE[190][300] = 1;
TABLE[190][43] = 1;
TABLE[190][45] = 1;
TABLE[190][40] = 1;
TABLE[190][278] = 1;
TABLE[190][37] = 1;
TABLE[190][47] = 1;
TABLE[190][42] = 1;
TABLE[190][294] = 1;
TABLE[190][295] = 1;
TABLE[190][94] = 1;
TABLE[190][124] = 1;
TABLE[190][33] = 1;
TABLE[190][126] = 1;
TABLE[190][38] = 1;
TABLE[190][304] = 1;
TABLE[190][302] = 1;
TABLE[190][303] = 1;
TABLE[190][289] = 1;
TABLE[190][299] = 1;
TABLE[268][300] = 1;
TABLE[268][40] = 1;
TABLE[268][45] = 1;
TABLE[268][43] = 1;
TABLE[268][42] = 1;
TABLE[268][47] = 1;
TABLE[268][37] = 1;
TABLE[268][278] = 1;
TABLE[268][295] = 1;
TABLE[268][294] = 1;
TABLE[268][38] = 1;
TABLE[268][126] = 1;
TABLE[268][33] = 1;
TABLE[268][124] = 1;
TABLE[268][94] = 1;
TABLE[268][299] = 1;
TABLE[268][289] = 1;
TABLE[268][303] = 1;
TABLE[268][302] = 1;
TABLE[268][304] = 1;
TABLE[268][59] = 1;
TABLE[268][93] = 1;
TABLE[268][41] = 1;
TABLE[268][63] = 1;
TABLE[268][292] = 1;
TABLE[268][298] = 1;
TABLE[268][297] = 1;
TABLE[268][125] = 1;
TABLE[268][58] = 1;
TABLE[268][44] = 1;
TABLE[87][59] = 1;
TABLE[87][93] = 1;
TABLE[87][41] = 1;
TABLE[87][63] = 1;
TABLE[87][292] = 1;
TABLE[87][298] = 1;
TABLE[87][297] = 1;
TABLE[87][125] = 1;
TABLE[87][58] = 1;
TABLE[87][44] = 1;
TABLE[87][300] = 1;
TABLE[87][43] = 1;
TABLE[87][45] = 1;
TABLE[87][40] = 1;
TABLE[87][278] = 1;
TABLE[87][37] = 1;
TABLE[87][47] = 1;
TABLE[87][42] = 1;
TABLE[87][294] = 1;
TABLE[87][295] = 1;
TABLE[87][94] = 1;
TABLE[87][124] = 1;
TABLE[87][33] = 1;
TABLE[87][126] = 1;
TABLE[87][38] = 1;
TABLE[87][304] = 1;
TABLE[87][302] = 1;
TABLE[87][303] = 1;
TABLE[87][289] = 1;
TABLE[87][299] = 1;
TABLE[191][300] = 1;
TABLE[191][40] = 1;
TABLE[191][45] = 1;
TABLE[191][43] = 1;
TABLE[191][42] = 1;
TABLE[191][47] = 1;
TABLE[191][37] = 1;
TABLE[191][278] = 1;
TABLE[191][295] = 1;
TABLE[191][294] = 1;
TABLE[191][38] = 1;
TABLE[191][126] = 1;
TABLE[191][33] = 1;
TABLE[191][124] = 1;
TABLE[191][94] = 1;
TABLE[191][299] = 1;
TABLE[191][289] = 1;
TABLE[191][303] = 1;
TABLE[191][302] = 1;
TABLE[191][304] = 1;
TABLE[269][43] = 1;
TABLE[269][45] = 1;
TABLE[269][40] = 1;
TABLE[269][278] = 1;
TABLE[269][37] = 1;
TABLE[269][47] = 1;
TABLE[269][42] = 1;
TABLE[269][294] = 1;
TABLE[269][295] = 1;
TABLE[269][94] = 1;
TABLE[269][124] = 1;
TABLE[269][33] = 1;
TABLE[269][126] = 1;
TABLE[269][38] = 1;
TABLE[269][304] = 1;
TABLE[269][302] = 1;
TABLE[269][303] = 1;
TABLE[269][289] = 1;
TABLE[269][299] = 1;
TABLE[269][59] = 1;
TABLE[269][93] = 1;
TABLE[269][41] = 1;
TABLE[269][63] = 1;
TABLE[269][300] = 1;
TABLE[269][292] = 1;
TABLE[269][298] = 1;
TABLE[269][297] = 1;
TABLE[269][125] = 1;
TABLE[269][58] = 1;
TABLE[269][44] = 1;
TABLE[88][59] = 1;
TABLE[88][93] = 1;
TABLE[88][41] = 1;
TABLE[88][63] = 1;
TABLE[88][300] = 1;
TABLE[88][292] = 1;
TABLE[88][298] = 1;
TABLE[88][297] = 1;
TABLE[88][125] = 1;
TABLE[88][58] = 1;
TABLE[88][44] = 1;
TABLE[88][45] = 1;
TABLE[88][43] = 1;
TABLE[88][40] = 1;
TABLE[88][42] = 1;
TABLE[88][47] = 1;
TABLE[88][37] = 1;
TABLE[88][278] = 1;
TABLE[88][295] = 1;
TABLE[88][294] = 1;
TABLE[88][38] = 1;
TABLE[88][126] = 1;
TABLE[88][33] = 1;
TABLE[88][124] = 1;
TABLE[88][94] = 1;
TABLE[88][299] = 1;
TABLE[88][289] = 1;
TABLE[88][303] = 1;
TABLE[88][302] = 1;
TABLE[88][304] = 1;
TABLE[194][43] = 1;
TABLE[194][45] = 1;
TABLE[194][40] = 1;
TABLE[194][278] = 1;
TABLE[194][37] = 1;
TABLE[194][47] = 1;
TABLE[194][42] = 1;
TABLE[194][294] = 1;
TABLE[194][295] = 1;
TABLE[194][94] = 1;
TABLE[194][124] = 1;
TABLE[194][33] = 1;
TABLE[194][126] = 1;
TABLE[194][38] = 1;
TABLE[194][304] = 1;
TABLE[194][302] = 1;
TABLE[194][303] = 1;
TABLE[194][289] = 1;
TABLE[194][299] = 1;
TABLE[270][40] = 1;
TABLE[270][42] = 1;
TABLE[270][47] = 1;
TABLE[270][37] = 1;
TABLE[270][278] = 1;
TABLE[270][295] = 1;
TABLE[270][294] = 1;
TABLE[270][38] = 1;
TABLE[270][43] = 1;
TABLE[270][45] = 1;
TABLE[270][126] = 1;
TABLE[270][33] = 1;
TABLE[270][124] = 1;
TABLE[270][94] = 1;
TABLE[270][299] = 1;
TABLE[270][289] = 1;
TABLE[270][303] = 1;
TABLE[270][302] = 1;
TABLE[270][304] = 1;
TABLE[270][59] = 1;
TABLE[270][93] = 1;
TABLE[270][41] = 1;
TABLE[270][63] = 1;
TABLE[270][300] = 1;
TABLE[270][292] = 1;
TABLE[270][298] = 1;
TABLE[270][297] = 1;
TABLE[270][125] = 1;
TABLE[270][58] = 1;
TABLE[270][44] = 1;
TABLE[192][43] = 1;
TABLE[193][45] = 1;
TABLE[89][40] = 1;
TABLE[89][37] = 1;
TABLE[89][47] = 1;
TABLE[89][42] = 1;
TABLE[89][278] = 1;
TABLE[89][294] = 1;
TABLE[89][295] = 1;
TABLE[89][94] = 1;
TABLE[89][124] = 1;
TABLE[89][33] = 1;
TABLE[89][126] = 1;
TABLE[89][45] = 1;
TABLE[89][43] = 1;
TABLE[89][38] = 1;
TABLE[89][304] = 1;
TABLE[89][302] = 1;
TABLE[89][303] = 1;
TABLE[89][289] = 1;
TABLE[89][299] = 1;
TABLE[198][40] = 1;
TABLE[198][42] = 1;
TABLE[198][47] = 1;
TABLE[198][37] = 1;
TABLE[198][278] = 1;
TABLE[198][295] = 1;
TABLE[198][294] = 1;
TABLE[198][38] = 1;
TABLE[198][43] = 1;
TABLE[198][45] = 1;
TABLE[198][126] = 1;
TABLE[198][33] = 1;
TABLE[198][124] = 1;
TABLE[198][94] = 1;
TABLE[198][299] = 1;
TABLE[198][289] = 1;
TABLE[198][303] = 1;
TABLE[198][302] = 1;
TABLE[198][304] = 1;
TABLE[271][40] = 1;
TABLE[271][278] = 1;
TABLE[271][294] = 1;
TABLE[271][295] = 1;
TABLE[271][94] = 1;
TABLE[271][124] = 1;
TABLE[271][33] = 1;
TABLE[271][126] = 1;
TABLE[271][45] = 1;
TABLE[271][43] = 1;
TABLE[271][42] = 1;
TABLE[271][38] = 1;
TABLE[271][304] = 1;
TABLE[271][302] = 1;
TABLE[271][303] = 1;
TABLE[271][289] = 1;
TABLE[271][299] = 1;
TABLE[195][42] = 1;
TABLE[196][47] = 1;
TABLE[197][37] = 1;
TABLE[90][278] = 1;
TABLE[90][295] = 1;
TABLE[90][294] = 1;
TABLE[90][40] = 1;
TABLE[90][38] = 1;
TABLE[90][42] = 1;
TABLE[90][43] = 1;
TABLE[90][45] = 1;
TABLE[90][126] = 1;
TABLE[90][33] = 1;
TABLE[90][124] = 1;
TABLE[90][94] = 1;
TABLE[90][299] = 1;
TABLE[90][289] = 1;
TABLE[90][303] = 1;
TABLE[90][302] = 1;
TABLE[90][304] = 1;
TABLE[91][40] = 1;
TABLE[92][40] = 1;
TABLE[92][304] = 1;
TABLE[92][302] = 1;
TABLE[92][303] = 1;
TABLE[92][289] = 1;
TABLE[92][299] = 1;
TABLE[93][294] = 1;
TABLE[93][295] = 1;
TABLE[94][94] = 1;
TABLE[94][124] = 1;
TABLE[94][33] = 1;
TABLE[94][126] = 1;
TABLE[94][45] = 1;
TABLE[94][43] = 1;
TABLE[94][42] = 1;
TABLE[94][38] = 1;
TABLE[95][278] = 1;
TABLE[96][278] = 1;
TABLE[199][294] = 1;
TABLE[200][295] = 1;
TABLE[97][38] = 1;
TABLE[97][42] = 1;
TABLE[97][43] = 1;
TABLE[97][45] = 1;
TABLE[97][126] = 1;
TABLE[97][33] = 1;
TABLE[97][124] = 1;
TABLE[97][94] = 1;
TABLE[201][38] = 1;
TABLE[202][42] = 1;
TABLE[203][43] = 1;
TABLE[204][45] = 1;
TABLE[205][126] = 1;
TABLE[206][33] = 1;
TABLE[207][126] = 1;
TABLE[208][124] = 1;
TABLE[209][94] = 1;
TABLE[98][40] = 1;
TABLE[98][299] = 1;
TABLE[98][289] = 1;
TABLE[98][303] = 1;
TABLE[98][302] = 1;
TABLE[98][304] = 1;
TABLE[99][40] = 1;
TABLE[99][304] = 1;
TABLE[99][302] = 1;
TABLE[99][303] = 1;
TABLE[99][289] = 1;
TABLE[99][299] = 1;
TABLE[211][91] = 1;
TABLE[213][40] = 1;
TABLE[214][46] = 1;
TABLE[215][296] = 1;
TABLE[216][294] = 1;
TABLE[217][295] = 1;
TABLE[210][58] = 1;
TABLE[272][93] = 1;
TABLE[212][41] = 1;
TABLE[212][44] = 1;
TABLE[212][278] = 1;
TABLE[212][63] = 1;
TABLE[212][295] = 1;
TABLE[212][294] = 1;
TABLE[212][40] = 1;
TABLE[212][38] = 1;
TABLE[212][42] = 1;
TABLE[212][43] = 1;
TABLE[212][45] = 1;
TABLE[212][126] = 1;
TABLE[212][33] = 1;
TABLE[212][124] = 1;
TABLE[212][94] = 1;
TABLE[212][297] = 1;
TABLE[212][299] = 1;
TABLE[212][289] = 1;
TABLE[212][303] = 1;
TABLE[212][302] = 1;
TABLE[212][304] = 1;
TABLE[212][298] = 1;
TABLE[212][292] = 1;
TABLE[212][300] = 1;
TABLE[212][37] = 1;
TABLE[212][47] = 1;
TABLE[273][41] = 1;
TABLE[100][299] = 1;
TABLE[101][304] = 1;
TABLE[101][302] = 1;
TABLE[101][303] = 1;
TABLE[101][289] = 1;
TABLE[102][40] = 1;
TABLE[103][59] = 1;
TABLE[103][41] = 1;
TABLE[103][44] = 1;
TABLE[103][278] = 1;
TABLE[103][63] = 1;
TABLE[103][295] = 1;
TABLE[103][294] = 1;
TABLE[103][40] = 1;
TABLE[103][38] = 1;
TABLE[103][42] = 1;
TABLE[103][43] = 1;
TABLE[103][45] = 1;
TABLE[103][126] = 1;
TABLE[103][33] = 1;
TABLE[103][124] = 1;
TABLE[103][94] = 1;
TABLE[103][297] = 1;
TABLE[103][299] = 1;
TABLE[103][289] = 1;
TABLE[103][303] = 1;
TABLE[103][302] = 1;
TABLE[103][304] = 1;
TABLE[103][298] = 1;
TABLE[103][292] = 1;
TABLE[103][300] = 1;
TABLE[103][37] = 1;
TABLE[103][47] = 1;
TABLE[218][44] = 1;
TABLE[218][63] = 1;
TABLE[218][278] = 1;
TABLE[218][294] = 1;
TABLE[218][295] = 1;
TABLE[218][297] = 1;
TABLE[218][94] = 1;
TABLE[218][124] = 1;
TABLE[218][33] = 1;
TABLE[218][126] = 1;
TABLE[218][45] = 1;
TABLE[218][43] = 1;
TABLE[218][42] = 1;
TABLE[218][38] = 1;
TABLE[218][40] = 1;
TABLE[218][298] = 1;
TABLE[218][304] = 1;
TABLE[218][302] = 1;
TABLE[218][303] = 1;
TABLE[218][289] = 1;
TABLE[218][299] = 1;
TABLE[218][292] = 1;
TABLE[218][300] = 1;
TABLE[218][47] = 1;
TABLE[218][37] = 1;
TABLE[274][63] = 1;
TABLE[274][278] = 1;
TABLE[274][294] = 1;
TABLE[274][295] = 1;
TABLE[274][297] = 1;
TABLE[274][94] = 1;
TABLE[274][124] = 1;
TABLE[274][33] = 1;
TABLE[274][126] = 1;
TABLE[274][45] = 1;
TABLE[274][43] = 1;
TABLE[274][42] = 1;
TABLE[274][38] = 1;
TABLE[274][40] = 1;
TABLE[274][298] = 1;
TABLE[274][304] = 1;
TABLE[274][302] = 1;
TABLE[274][303] = 1;
TABLE[274][289] = 1;
TABLE[274][299] = 1;
TABLE[274][292] = 1;
TABLE[274][300] = 1;
TABLE[274][47] = 1;
TABLE[274][37] = 1;
TABLE[274][59] = 1;
TABLE[274][41] = 1;
TABLE[104][304] = 1;
TABLE[105][302] = 1;
TABLE[106][303] = 1;
TABLE[107][289] = 1;
TABLE[108][299] = 1;
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
      case 887: return 1; break;
      case 891: return 1; break;
      case 896: return 1; break;
      case 904: return 1; break;
      case 909: return 1; break;
      case 917: return 1; break;
      case 922: return 1; break;
      case 930: return 1; break;
      case 935: return 1; break;
      case 943: return 1; break;
      case 948: return 1; break;
      case 956: return 1; break;
      case 961: return 1; break;
      case 969: return 1; break;
      case 974: return 1; break;
      case 982: return 1; break;
      case 987: return 1; break;
      case 995: return 0; break;
      case 1003: return 1; break;
      case 1008: return 1; break;
      case 1016: return 0; break;
      case 1028: return 0; break;
      case 1039: return 0; break;
      case 1065: return 0; break;
      case 1073: return 0; break;
      case 1077: return 0; break;
      case 1113: return 0; break;
      case 1122: return 0; break;
      case 1153: return 1; break;
      case 1161: return 1; break;
      case 1168: return 0; break;
      case 1182: return 1; break;
      case 1187: return 1; break;
      case 1196: return 0; break;
      case 1212: return 0; break;
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
         case 887: return "constant_expression"; break;
         case 891: return "logical_OR_expression"; break;
         case 896: return "Subphrase"; break;
         case 904: return "logical_AND_expression"; break;
         case 909: return "Subphrase"; break;
         case 917: return "inclusive_OR_expression"; break;
         case 922: return "Subphrase"; break;
         case 930: return "exclusive_OR_expression"; break;
         case 935: return "Subphrase"; break;
         case 943: return "AND_expression"; break;
         case 948: return "Subphrase"; break;
         case 956: return "equality_expression"; break;
         case 961: return "Subphrase"; break;
         case 969: return "shift_expression"; break;
         case 974: return "Subphrase"; break;
         case 982: return "additive_expression"; break;
         case 987: return "Subphrase"; break;
         case 995: return "Subphrase"; break;
         case 1003: return "multiplicative_expression"; break;
         case 1008: return "Subphrase"; break;
         case 1016: return "Subphrase"; break;
         case 1028: return "cast_expression"; break;
         case 1039: return "unary_expression"; break;
         case 1065: return "Subphrase"; break;
         case 1073: return "unary_operator"; break;
         case 1077: return "Subphrase"; break;
         case 1113: return "postfix_expression"; break;
         case 1122: return "Subphrase"; break;
         case 1153: return "Subphrase"; break;
         case 1161: return "Subphrase"; break;
         case 1168: return "primary_expression"; break;
         case 1182: return "argument_expression_list"; break;
         case 1187: return "Subphrase"; break;
         case 1196: return "constant"; break;
         case 1212: return "id"; break;
   }
   else 
      switch(n-50000) {
         case 307: return "EXP"; break;
         case 306: return "INPUT"; break;
         case 305: return "PRINT"; break;
         case 304: return "INTCONST"; break;
         case 303: return "FLOATCONST"; break;
         case 302: return "CHARACTER"; break;
         case 301: return "INCLUDE"; break;
         case 300: return "SHIFT"; break;
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
