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
   case 2: {
      include_line();
      } break;
   }
}

include_line ()
{
   switch(yyselect()) {
   case 3: {
      get_lexval();
#line 77 "ass2.acc"
 PRCH; 
# line 104 "yygrammar.c"
      get_lexval();
#line 77 "ass2.acc"
 PRKW; 
# line 108 "yygrammar.c"
      switch (yyselect()) {
      case 107: {
         get_lexval();
#line 77 "ass2.acc"
 fprintStringConst(f, yylval.s); 
# line 114 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

external_declaration ()
{
   switch(yyselect()) {
   case 4: {
      function_definition();
      } break;
   case 5: {
      declaration();
      } break;
   }
}

function_definition ()
{
   switch(yyselect()) {
   case 6: {
      switch (yyselect()) {
      case 108: {
         declaration_specifiers();
         } break;
      default: ;
      }
      declarator();
      switch (yyselect()) {
      case 109: {
         declaration_list();
         } break;
      default: ;
      }
      compound_statement();
#line 86 "ass2.acc"
 fputs("\\\\\n", f); 
# line 154 "yygrammar.c"
      } break;
   }
}

declaration ()
{
   switch(yyselect()) {
   case 7: {
      declaration_specifiers();
      switch (yyselect()) {
      case 110: {
         init_declarator_list();
         } break;
      default: ;
      }
      get_lexval();
#line 90 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 173 "yygrammar.c"
      } break;
   }
}

declaration_list ()
{
   switch(yyselect()) {
   case 8: {
      switch (yyselect()) {
      case 111: {
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
   case 9: {
      switch (yyselect()) {
      case 112: {
         storage_class_specifier();
         } break;
      case 113: {
         type_specifier();
         } break;
      case 114: {
         type_qualifier();
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 115: {
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
   case 10: {
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
#line 106 "ass2.acc"
 PRKW; 
# line 243 "yygrammar.c"
      } break;
   }
}

type_specifier ()
{
   switch(yyselect()) {
   case 11: {
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
#line 118 "ass2.acc"
 PRKW; 
# line 284 "yygrammar.c"
      } break;
   case 12: {
      struct_or_union_specifier();
      } break;
   case 13: {
      enum_specifier();
      } break;
   }
}

type_qualifier ()
{
   switch(yyselect()) {
   case 14: {
      switch (yyselect()) {
      case 130: {
         get_lexval();
         } break;
      case 131: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 124 "ass2.acc"
 PRKW; 
# line 310 "yygrammar.c"
      } break;
   }
}

struct_or_union_specifier ()
{
   switch(yyselect()) {
   case 15: {
      struct_or_union();
      switch (yyselect()) {
      case 132: {
         id();
         } break;
      default: ;
      }
      get_lexval();
#line 128 "ass2.acc"
 fputs("\\{\\\\\n", f); 
# line 329 "yygrammar.c"
      struct_declaration_list();
      get_lexval();
#line 128 "ass2.acc"
 fputs("\\}\\\\\n", f); 
# line 334 "yygrammar.c"
      } break;
   case 16: {
      struct_or_union();
      id();
      } break;
   }
}

struct_or_union ()
{
   switch(yyselect()) {
   case 17: {
      switch (yyselect()) {
      case 133: {
         get_lexval();
         } break;
      case 134: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 133 "ass2.acc"
 PRKW; 
# line 358 "yygrammar.c"
      } break;
   }
}

struct_declaration_list ()
{
   switch(yyselect()) {
   case 18: {
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
   case 19: {
      switch (yyselect()) {
      case 136: {
         init_declarator_list();
         get_lexval();
#line 141 "ass2.acc"
 PRCHS; 
# line 388 "yygrammar.c"
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
   case 20: {
      switch (yyselect()) {
      case 137: {
         declarator();
         get_lexval();
#line 145 "ass2.acc"
 PRCH; 
# line 407 "yygrammar.c"
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
   case 21: {
      specifier_qualifier_list();
      struct_declarator_list();
      get_lexval();
#line 149 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 425 "yygrammar.c"
      } break;
   }
}

specifier_qualifier_list ()
{
   switch(yyselect()) {
   case 22: {
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
   case 23: {
      switch (yyselect()) {
      case 141: {
         struct_declarator_list();
         get_lexval();
#line 157 "ass2.acc"
 PRCHS; 
# line 463 "yygrammar.c"
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
   case 24: {
      declarator();
      } break;
   case 25: {
      switch (yyselect()) {
      case 142: {
         declarator();
         } break;
      default: ;
      }
      get_lexval();
#line 162 "ass2.acc"
 PRCH; 
# line 488 "yygrammar.c"
      constant_expression();
      } break;
   }
}

enum_specifier ()
{
   switch(yyselect()) {
   case 26: {
      get_lexval();
      switch (yyselect()) {
      case 143: {
         id();
         } break;
      default: ;
      }
#line 166 "ass2.acc"
 fputs("\\{\\\\\n", f); 
# line 507 "yygrammar.c"
      get_lexval();
      enumerator_list();
      get_lexval();
#line 166 "ass2.acc"
 fputs("\\}\\\\\n", f); 
# line 513 "yygrammar.c"
      } break;
   case 27: {
      get_lexval();
      id();
      } break;
   }
}

enumerator_list ()
{
   switch(yyselect()) {
   case 28: {
      switch (yyselect()) {
      case 144: {
         enumerator_list();
         get_lexval();
#line 171 "ass2.acc"
 PRCHS; 
# line 532 "yygrammar.c"
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
   case 29: {
      id();
      switch (yyselect()) {
      case 145: {
         get_lexval();
#line 175 "ass2.acc"
 PRCH; 
# line 551 "yygrammar.c"
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
   case 30: {
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
   case 31: {
      id();
#line 183 "ass2.acc"
printf("Identifier within declarator: %s\n", yylval.s);
# line 582 "yygrammar.c"
      } break;
   case 32: {
      get_lexval();
#line 184 "ass2.acc"
 PRCH; 
# line 588 "yygrammar.c"
      declarator();
      get_lexval();
#line 184 "ass2.acc"
 PRCH; 
# line 593 "yygrammar.c"
      } break;
   case 33: {
      direct_declarator();
      switch (yyselect()) {
      case 148: {
         get_lexval();
#line 185 "ass2.acc"
 PRCH; 
# line 602 "yygrammar.c"
         switch (yyselect()) {
         case 147: {
            constant_expression();
            } break;
         default: ;
         }
         get_lexval();
#line 185 "ass2.acc"
 PRCH; 
# line 612 "yygrammar.c"
         } break;
      case 149: {
         get_lexval();
#line 185 "ass2.acc"
 PRCH; 
# line 618 "yygrammar.c"
         parameter_type_list();
         get_lexval();
#line 185 "ass2.acc"
 PRCH; 
# line 623 "yygrammar.c"
         } break;
      case 151: {
         get_lexval();
#line 185 "ass2.acc"
 PRCH; 
# line 629 "yygrammar.c"
         switch (yyselect()) {
         case 150: {
            identifier_list();
            } break;
         default: ;
         }
         get_lexval();
#line 185 "ass2.acc"
 PRCH; 
# line 639 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

pointer ()
{
   switch(yyselect()) {
   case 34: {
      get_lexval();
#line 189 "ass2.acc"
 PRCH; 
# line 654 "yygrammar.c"
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
   case 35: {
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
   case 36: {
      parameter_list();
      switch (yyselect()) {
      case 155: {
         get_lexval();
#line 197 "ass2.acc"
 PRCHS; 
# line 696 "yygrammar.c"
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
   case 37: {
      switch (yyselect()) {
      case 156: {
         parameter_list();
         get_lexval();
#line 201 "ass2.acc"
 PRCHS; 
# line 715 "yygrammar.c"
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
   case 38: {
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
   case 39: {
      switch (yyselect()) {
      case 160: {
         identifier_list();
         get_lexval();
#line 209 "ass2.acc"
 PRCHS; 
# line 757 "yygrammar.c"
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
   case 40: {
      assignment_expression();
      } break;
   case 41: {
      get_lexval();
#line 214 "ass2.acc"
 fputs("\\{", f); 
# line 776 "yygrammar.c"
      initializer_list();
      switch (yyselect()) {
      case 161: {
         get_lexval();
         } break;
      default: ;
      }
      get_lexval();
#line 214 "ass2.acc"
 fputs("\\}", f); 
# line 787 "yygrammar.c"
      } break;
   }
}

initializer_list ()
{
   switch(yyselect()) {
   case 42: {
      switch (yyselect()) {
      case 162: {
         initializer_list();
         get_lexval();
#line 218 "ass2.acc"
 PRCHS; 
# line 802 "yygrammar.c"
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
   case 43: {
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
   case 44: {
      pointer();
      } break;
   case 45: {
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
   case 46: {
      get_lexval();
#line 231 "ass2.acc"
 PRCH; 
# line 851 "yygrammar.c"
      abstract_declarator();
      get_lexval();
#line 231 "ass2.acc"
 PRCH; 
# line 856 "yygrammar.c"
      } break;
   case 47: {
      switch (yyselect()) {
      case 165: {
         direct_abstract_declarator();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 167: {
         get_lexval();
#line 232 "ass2.acc"
 PRCH; 
# line 870 "yygrammar.c"
         switch (yyselect()) {
         case 166: {
            constant_expression();
            } break;
         default: ;
         }
         get_lexval();
#line 232 "ass2.acc"
 PRCH; 
# line 880 "yygrammar.c"
         } break;
      case 169: {
         get_lexval();
#line 232 "ass2.acc"
 PRCH; 
# line 886 "yygrammar.c"
         switch (yyselect()) {
         case 168: {
            parameter_type_list();
            } break;
         default: ;
         }
         get_lexval();
#line 232 "ass2.acc"
 PRCH; 
# line 896 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

typedef_name ()
{
   switch(yyselect()) {
   case 48: {
      id();
      } break;
   }
}

statement ()
{
   switch(yyselect()) {
   case 49: {
      labeled_statement();
      } break;
   case 50: {
      expression_statement();
      } break;
   case 51: {
      compound_statement();
      } break;
   case 52: {
      selection_statement();
      } break;
   case 53: {
      iteration_statement();
      } break;
   case 54: {
      jump_statement();
      } break;
   }
}

labeled_statement ()
{
   switch(yyselect()) {
   case 55: {
      id();
      get_lexval();
#line 249 "ass2.acc"
 PRCH; 
# line 945 "yygrammar.c"
      statement();
      } break;
   case 56: {
      get_lexval();
#line 250 "ass2.acc"
 PRKW; 
# line 952 "yygrammar.c"
      constant_expression();
      get_lexval();
#line 250 "ass2.acc"
 PRCH; 
# line 957 "yygrammar.c"
      statement();
      } break;
   case 57: {
      get_lexval();
#line 251 "ass2.acc"
 PRKW; 
# line 964 "yygrammar.c"
      get_lexval();
#line 251 "ass2.acc"
 PRCH; 
# line 968 "yygrammar.c"
      statement();
      } break;
   }
}

expression_statement ()
{
   switch(yyselect()) {
   case 58: {
      switch (yyselect()) {
      case 170: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 255 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 987 "yygrammar.c"
      } break;
   }
}

compound_statement ()
{
   switch(yyselect()) {
   case 59: {
      get_lexval();
#line 259 "ass2.acc"
 fputs("\\{\\\\\n", f); 
# line 999 "yygrammar.c"
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
#line 259 "ass2.acc"
 fputs("\\}\\\\\n", f); 
# line 1015 "yygrammar.c"
      } break;
   }
}

statement_list ()
{
   switch(yyselect()) {
   case 60: {
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
   case 61: {
      get_lexval();
#line 267 "ass2.acc"
 PRKW; 
# line 1042 "yygrammar.c"
      get_lexval();
#line 267 "ass2.acc"
 PRCH; 
# line 1046 "yygrammar.c"
      expression();
      get_lexval();
#line 267 "ass2.acc"
 PRCH; 
# line 1051 "yygrammar.c"
      statement();
      switch (yyselect()) {
      case 174: {
         get_lexval();
#line 267 "ass2.acc"
 PRKW; 
# line 1058 "yygrammar.c"
         statement();
         } break;
      default: ;
      }
      } break;
   case 62: {
      get_lexval();
#line 268 "ass2.acc"
 PRKW; 
# line 1068 "yygrammar.c"
      get_lexval();
#line 268 "ass2.acc"
 PRCH; 
# line 1072 "yygrammar.c"
      expression();
      get_lexval();
#line 268 "ass2.acc"
 PRCH; 
# line 1077 "yygrammar.c"
      statement();
      } break;
   }
}

iteration_statement ()
{
   switch(yyselect()) {
   case 63: {
      get_lexval();
#line 272 "ass2.acc"
 PRKW; 
# line 1090 "yygrammar.c"
      get_lexval();
#line 272 "ass2.acc"
 PRCH; 
# line 1094 "yygrammar.c"
      expression();
      get_lexval();
#line 272 "ass2.acc"
 PRCH; 
# line 1099 "yygrammar.c"
      statement();
      } break;
   case 64: {
      get_lexval();
#line 273 "ass2.acc"
 PRKW; 
# line 1106 "yygrammar.c"
      statement();
      get_lexval();
#line 273 "ass2.acc"
 PRKW; 
# line 1111 "yygrammar.c"
      get_lexval();
#line 273 "ass2.acc"
 PRCH; 
# line 1115 "yygrammar.c"
      expression();
      get_lexval();
#line 273 "ass2.acc"
 PRCH; 
# line 1120 "yygrammar.c"
      get_lexval();
#line 273 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 1124 "yygrammar.c"
      } break;
   case 65: {
      get_lexval();
#line 274 "ass2.acc"
 PRKW; 
# line 1130 "yygrammar.c"
      get_lexval();
#line 274 "ass2.acc"
 PRCH; 
# line 1134 "yygrammar.c"
      switch (yyselect()) {
      case 175: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 274 "ass2.acc"
 PRCH; 
# line 1144 "yygrammar.c"
      switch (yyselect()) {
      case 176: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 274 "ass2.acc"
 PRCH; 
# line 1154 "yygrammar.c"
      switch (yyselect()) {
      case 177: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 274 "ass2.acc"
 PRCH; 
# line 1164 "yygrammar.c"
      statement();
      } break;
   }
}

jump_statement ()
{
   switch(yyselect()) {
   case 66: {
      get_lexval();
#line 278 "ass2.acc"
 PRKW; 
# line 1177 "yygrammar.c"
      id();
      get_lexval();
#line 278 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 1182 "yygrammar.c"
      } break;
   case 67: {
      get_lexval();
#line 279 "ass2.acc"
 PRKW; 
# line 1188 "yygrammar.c"
      get_lexval();
#line 279 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 1192 "yygrammar.c"
      } break;
   case 68: {
      get_lexval();
#line 280 "ass2.acc"
 PRKW; 
# line 1198 "yygrammar.c"
      get_lexval();
#line 280 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 1202 "yygrammar.c"
      } break;
   case 69: {
      get_lexval();
#line 281 "ass2.acc"
 PRKW; 
# line 1208 "yygrammar.c"
      switch (yyselect()) {
      case 178: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 281 "ass2.acc"
 printf("Return\n"); fputs(";\\\\\n", f); 
# line 1218 "yygrammar.c"
      } break;
   }
}

expression ()
{
   switch(yyselect()) {
   case 70: {
      switch (yyselect()) {
      case 179: {
         expression();
         get_lexval();
#line 285 "ass2.acc"
 PRCHS; 
# line 1233 "yygrammar.c"
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
   case 71: {
      conditional_expression();
      } break;
   case 72: {
      unary_expression();
      assignment_operator();
      assignment_expression();
      } break;
   }
}

assignment_operator ()
{
   switch(yyselect()) {
   case 73: {
      switch (yyselect()) {
      case 180: {
         get_lexval();
         } break;
      case 181: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 295 "ass2.acc"
 fputc(' ', f); PRCHS; 
# line 1271 "yygrammar.c"
      } break;
   }
}

conditional_expression ()
{
   switch(yyselect()) {
   case 74: {
      logical_OR_expression();
      switch (yyselect()) {
      case 182: {
         get_lexval();
#line 299 "ass2.acc"
 PRCH; 
# line 1286 "yygrammar.c"
         expression();
         get_lexval();
#line 299 "ass2.acc"
 PRCH; 
# line 1291 "yygrammar.c"
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
      case 183: {
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
   case 77: {
      switch (yyselect()) {
      case 184: {
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
   case 78: {
      switch (yyselect()) {
      case 185: {
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
   case 79: {
      switch (yyselect()) {
      case 186: {
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
   case 80: {
      switch (yyselect()) {
      case 187: {
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
   case 81: {
      switch (yyselect()) {
      case 188: {
         equality_expression();
         get_lexval();
#line 327 "ass2.acc"
 fprintCompare(f, yylval.subtype); 
# line 1399 "yygrammar.c"
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
      case 189: {
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
   case 83: {
      switch (yyselect()) {
      case 192: {
         additive_expression();
         switch (yyselect()) {
         case 190: {
            get_lexval();
            } break;
         case 191: {
            get_lexval();
            } break;
         default: printf("???\n"); exit(1);
         }
#line 335 "ass2.acc"
 PRCH; 
# line 1442 "yygrammar.c"
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
      case 196: {
         multiplicative_expression();
         switch (yyselect()) {
         case 193: {
            get_lexval();
            } break;
         case 194: {
            get_lexval();
            } break;
         case 195: {
            get_lexval();
            } break;
         default: printf("???\n"); exit(1);
         }
#line 339 "ass2.acc"
 PRCH; 
# line 1472 "yygrammar.c"
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
#line 344 "ass2.acc"
 PRCH; 
# line 1491 "yygrammar.c"
      type_name();
      get_lexval();
#line 344 "ass2.acc"
 PRCH; 
# line 1496 "yygrammar.c"
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
      case 197: {
         get_lexval();
         } break;
      case 198: {
         get_lexval();
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
      unary_expression();
      } break;
   case 91: {
      get_lexval();
      get_lexval();
#line 352 "ass2.acc"
 PRCH; 
# line 1533 "yygrammar.c"
      type_name();
      get_lexval();
#line 352 "ass2.acc"
 PRCH; 
# line 1538 "yygrammar.c"
      } break;
   }
}

unary_operator ()
{
   switch(yyselect()) {
   case 92: {
      switch (yyselect()) {
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
      default: printf("???\n"); exit(1);
      }
#line 356 "ass2.acc"
 PRCH; 
# line 1570 "yygrammar.c"
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
      case 205: {
         get_lexval();
#line 361 "ass2.acc"
 PRCH; 
# line 1588 "yygrammar.c"
         expression();
         get_lexval();
#line 361 "ass2.acc"
 PRCH; 
# line 1593 "yygrammar.c"
         } break;
      case 207: {
         get_lexval();
#line 361 "ass2.acc"
 PRCH; 
# line 1599 "yygrammar.c"
         switch (yyselect()) {
         case 206: {
            argument_expression_list();
            } break;
         default: ;
         }
         get_lexval();
#line 361 "ass2.acc"
 PRCH; 
# line 1609 "yygrammar.c"
         } break;
      case 208: {
         get_lexval();
#line 361 "ass2.acc"
 PRCH; 
# line 1615 "yygrammar.c"
         id();
         } break;
      case 209: {
         get_lexval();
#line 361 "ass2.acc"
 fputs("->", f); 
# line 1622 "yygrammar.c"
         id();
         } break;
      case 210: {
         get_lexval();
#line 361 "ass2.acc"
 fputs("++", f); 
# line 1629 "yygrammar.c"
         } break;
      case 211: {
         get_lexval();
#line 361 "ass2.acc"
 fputs("--", f); 
# line 1635 "yygrammar.c"
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
#line 367 "ass2.acc"
 fprintStringConst(f, yylval.s); 
# line 1656 "yygrammar.c"
      } break;
   case 98: {
      get_lexval();
#line 368 "ass2.acc"
 PRCH; 
# line 1662 "yygrammar.c"
      expression();
      get_lexval();
#line 368 "ass2.acc"
 PRCH; 
# line 1667 "yygrammar.c"
      } break;
   }
}

argument_expression_list ()
{
   switch(yyselect()) {
   case 99: {
      switch (yyselect()) {
      case 212: {
         argument_expression_list();
         get_lexval();
#line 372 "ass2.acc"
 PRCHS; 
# line 1682 "yygrammar.c"
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
#line 376 "ass2.acc"
 fprintf(f, "$%u$", yylval.i); 
# line 1698 "yygrammar.c"
      } break;
   case 101: {
      get_lexval();
#line 377 "ass2.acc"
 fprintStringConst(f, yylval.s); 
# line 1704 "yygrammar.c"
      } break;
   case 102: {
      get_lexval();
#line 378 "ass2.acc"
 fprintf(f, "$%f$", yylval.d); 
# line 1710 "yygrammar.c"
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
#line 383 "ass2.acc"
 fprintIdentifier(f, yylval.s); 
# line 1725 "yygrammar.c"
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
int c_length = 1176;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 105,
/* 6 */ 10,
/* 7 */ 14,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 0,
/* 11 */ 22,
/* 12 */ -6,
/* 13 */ 2,
/* 14 */ 19,
/* 15 */ 32,
/* 16 */ 14,
/* 17 */ -14,
/* 18 */ 106,
/* 19 */ 0,
/* 20 */ -14,
/* 21 */ 213,
/* 22 */ 0,
/* 23 */ 50035,
/* 24 */ 50305,
/* 25 */ 28,
/* 26 */ -22,
/* 27 */ 3,
/* 28 */ 0,
/* 29 */ 50289,
/* 30 */ -28,
/* 31 */ 107,
/* 32 */ 36,
/* 33 */ 40,
/* 34 */ -32,
/* 35 */ 4,
/* 36 */ 0,
/* 37 */ 61,
/* 38 */ -32,
/* 39 */ 5,
/* 40 */ 0,
/* 41 */ 47,
/* 42 */ 366,
/* 43 */ 54,
/* 44 */ 678,
/* 45 */ -40,
/* 46 */ 6,
/* 47 */ 51,
/* 48 */ 86,
/* 49 */ -47,
/* 50 */ 108,
/* 51 */ 0,
/* 52 */ -47,
/* 53 */ 214,
/* 54 */ 58,
/* 55 */ 74,
/* 56 */ -54,
/* 57 */ 109,
/* 58 */ 0,
/* 59 */ -54,
/* 60 */ 215,
/* 61 */ 0,
/* 62 */ 86,
/* 63 */ 67,
/* 64 */ 50059,
/* 65 */ -61,
/* 66 */ 7,
/* 67 */ 71,
/* 68 */ 238,
/* 69 */ -67,
/* 70 */ 110,
/* 71 */ 0,
/* 72 */ -67,
/* 73 */ 216,
/* 74 */ 0,
/* 75 */ 79,
/* 76 */ 61,
/* 77 */ -74,
/* 78 */ 8,
/* 79 */ 83,
/* 80 */ 74,
/* 81 */ -79,
/* 82 */ 111,
/* 83 */ 0,
/* 84 */ -79,
/* 85 */ 217,
/* 86 */ 0,
/* 87 */ 91,
/* 88 */ 103,
/* 89 */ -86,
/* 90 */ 9,
/* 91 */ 95,
/* 92 */ 110,
/* 93 */ -91,
/* 94 */ 112,
/* 95 */ 99,
/* 96 */ 134,
/* 97 */ -91,
/* 98 */ 113,
/* 99 */ 0,
/* 100 */ 182,
/* 101 */ -91,
/* 102 */ 114,
/* 103 */ 107,
/* 104 */ 86,
/* 105 */ -103,
/* 106 */ 115,
/* 107 */ 0,
/* 108 */ -103,
/* 109 */ 218,
/* 110 */ 0,
/* 111 */ 114,
/* 112 */ -110,
/* 113 */ 10,
/* 114 */ 118,
/* 115 */ 50256,
/* 116 */ -114,
/* 117 */ 116,
/* 118 */ 122,
/* 119 */ 50274,
/* 120 */ -114,
/* 121 */ 117,
/* 122 */ 126,
/* 123 */ 50279,
/* 124 */ -114,
/* 125 */ 118,
/* 126 */ 130,
/* 127 */ 50267,
/* 128 */ -114,
/* 129 */ 119,
/* 130 */ 0,
/* 131 */ 50282,
/* 132 */ -114,
/* 133 */ 120,
/* 134 */ 138,
/* 135 */ 146,
/* 136 */ -134,
/* 137 */ 11,
/* 138 */ 142,
/* 139 */ 194,
/* 140 */ -134,
/* 141 */ 12,
/* 142 */ 0,
/* 143 */ 320,
/* 144 */ -134,
/* 145 */ 13,
/* 146 */ 150,
/* 147 */ 50285,
/* 148 */ -146,
/* 149 */ 121,
/* 150 */ 154,
/* 151 */ 50259,
/* 152 */ -146,
/* 153 */ 122,
/* 154 */ 158,
/* 155 */ 50276,
/* 156 */ -146,
/* 157 */ 123,
/* 158 */ 162,
/* 159 */ 50272,
/* 160 */ -146,
/* 161 */ 124,
/* 162 */ 166,
/* 163 */ 50273,
/* 164 */ -146,
/* 165 */ 125,
/* 166 */ 170,
/* 167 */ 50268,
/* 168 */ -146,
/* 169 */ 126,
/* 170 */ 174,
/* 171 */ 50264,
/* 172 */ -146,
/* 173 */ 127,
/* 174 */ 178,
/* 175 */ 50277,
/* 176 */ -146,
/* 177 */ 128,
/* 178 */ 0,
/* 179 */ 50284,
/* 180 */ -146,
/* 181 */ 129,
/* 182 */ 0,
/* 183 */ 186,
/* 184 */ -182,
/* 185 */ 14,
/* 186 */ 190,
/* 187 */ 50260,
/* 188 */ -186,
/* 189 */ 130,
/* 190 */ 0,
/* 191 */ 50286,
/* 192 */ -186,
/* 193 */ 131,
/* 194 */ 202,
/* 195 */ 214,
/* 196 */ 207,
/* 197 */ 50123,
/* 198 */ 226,
/* 199 */ 50125,
/* 200 */ -194,
/* 201 */ 15,
/* 202 */ 0,
/* 203 */ 214,
/* 204 */ 1173,
/* 205 */ -194,
/* 206 */ 16,
/* 207 */ 211,
/* 208 */ 1173,
/* 209 */ -207,
/* 210 */ 132,
/* 211 */ 0,
/* 212 */ -207,
/* 213 */ 219,
/* 214 */ 0,
/* 215 */ 218,
/* 216 */ -214,
/* 217 */ 17,
/* 218 */ 222,
/* 219 */ 50280,
/* 220 */ -218,
/* 221 */ 133,
/* 222 */ 0,
/* 223 */ 50283,
/* 224 */ -218,
/* 225 */ 134,
/* 226 */ 0,
/* 227 */ 231,
/* 228 */ 264,
/* 229 */ -226,
/* 230 */ 18,
/* 231 */ 235,
/* 232 */ 226,
/* 233 */ -231,
/* 234 */ 135,
/* 235 */ 0,
/* 236 */ -231,
/* 237 */ 220,
/* 238 */ 0,
/* 239 */ 243,
/* 240 */ 251,
/* 241 */ -238,
/* 242 */ 19,
/* 243 */ 248,
/* 244 */ 238,
/* 245 */ 50044,
/* 246 */ -243,
/* 247 */ 136,
/* 248 */ 0,
/* 249 */ -243,
/* 250 */ 221,
/* 251 */ 0,
/* 252 */ 256,
/* 253 */ 516,
/* 254 */ -251,
/* 255 */ 20,
/* 256 */ 261,
/* 257 */ 366,
/* 258 */ 50061,
/* 259 */ -256,
/* 260 */ 137,
/* 261 */ 0,
/* 262 */ -256,
/* 263 */ 222,
/* 264 */ 0,
/* 265 */ 270,
/* 266 */ 290,
/* 267 */ 50059,
/* 268 */ -264,
/* 269 */ 21,
/* 270 */ 0,
/* 271 */ 275,
/* 272 */ 283,
/* 273 */ -270,
/* 274 */ 22,
/* 275 */ 279,
/* 276 */ 134,
/* 277 */ -275,
/* 278 */ 138,
/* 279 */ 0,
/* 280 */ 182,
/* 281 */ -275,
/* 282 */ 139,
/* 283 */ 287,
/* 284 */ 270,
/* 285 */ -283,
/* 286 */ 140,
/* 287 */ 0,
/* 288 */ -283,
/* 289 */ 223,
/* 290 */ 0,
/* 291 */ 295,
/* 292 */ 303,
/* 293 */ -290,
/* 294 */ 23,
/* 295 */ 300,
/* 296 */ 290,
/* 297 */ 50044,
/* 298 */ -295,
/* 299 */ 141,
/* 300 */ 0,
/* 301 */ -295,
/* 302 */ 224,
/* 303 */ 307,
/* 304 */ 366,
/* 305 */ -303,
/* 306 */ 24,
/* 307 */ 0,
/* 308 */ 313,
/* 309 */ 50058,
/* 310 */ 866,
/* 311 */ -303,
/* 312 */ 25,
/* 313 */ 317,
/* 314 */ 366,
/* 315 */ -313,
/* 316 */ 142,
/* 317 */ 0,
/* 318 */ -313,
/* 319 */ 225,
/* 320 */ 328,
/* 321 */ 50266,
/* 322 */ 333,
/* 323 */ 50123,
/* 324 */ 340,
/* 325 */ 50125,
/* 326 */ -320,
/* 327 */ 26,
/* 328 */ 0,
/* 329 */ 50266,
/* 330 */ 1173,
/* 331 */ -320,
/* 332 */ 27,
/* 333 */ 337,
/* 334 */ 1173,
/* 335 */ -333,
/* 336 */ 143,
/* 337 */ 0,
/* 338 */ -333,
/* 339 */ 226,
/* 340 */ 0,
/* 341 */ 345,
/* 342 */ 353,
/* 343 */ -340,
/* 344 */ 28,
/* 345 */ 350,
/* 346 */ 340,
/* 347 */ 50044,
/* 348 */ -345,
/* 349 */ 144,
/* 350 */ 0,
/* 351 */ -345,
/* 352 */ 227,
/* 353 */ 0,
/* 354 */ 1173,
/* 355 */ 358,
/* 356 */ -353,
/* 357 */ 29,
/* 358 */ 363,
/* 359 */ 50061,
/* 360 */ 866,
/* 361 */ -358,
/* 362 */ 145,
/* 363 */ 0,
/* 364 */ -358,
/* 365 */ 228,
/* 366 */ 0,
/* 367 */ 371,
/* 368 */ 378,
/* 369 */ -366,
/* 370 */ 30,
/* 371 */ 375,
/* 372 */ 425,
/* 373 */ -371,
/* 374 */ 146,
/* 375 */ 0,
/* 376 */ -371,
/* 377 */ 229,
/* 378 */ 382,
/* 379 */ 1173,
/* 380 */ -378,
/* 381 */ 31,
/* 382 */ 388,
/* 383 */ 50040,
/* 384 */ 366,
/* 385 */ 50041,
/* 386 */ -378,
/* 387 */ 32,
/* 388 */ 0,
/* 389 */ 378,
/* 390 */ 393,
/* 391 */ -378,
/* 392 */ 33,
/* 393 */ 399,
/* 394 */ 50091,
/* 395 */ 411,
/* 396 */ 50093,
/* 397 */ -393,
/* 398 */ 148,
/* 399 */ 405,
/* 400 */ 50040,
/* 401 */ 457,
/* 402 */ 50041,
/* 403 */ -393,
/* 404 */ 149,
/* 405 */ 0,
/* 406 */ 50040,
/* 407 */ 418,
/* 408 */ 50041,
/* 409 */ -393,
/* 410 */ 151,
/* 411 */ 415,
/* 412 */ 866,
/* 413 */ -411,
/* 414 */ 147,
/* 415 */ 0,
/* 416 */ -411,
/* 417 */ 230,
/* 418 */ 422,
/* 419 */ 503,
/* 420 */ -418,
/* 421 */ 150,
/* 422 */ 0,
/* 423 */ -418,
/* 424 */ 231,
/* 425 */ 0,
/* 426 */ 50042,
/* 427 */ 431,
/* 428 */ 438,
/* 429 */ -425,
/* 430 */ 34,
/* 431 */ 435,
/* 432 */ 445,
/* 433 */ -431,
/* 434 */ 152,
/* 435 */ 0,
/* 436 */ -431,
/* 437 */ 232,
/* 438 */ 442,
/* 439 */ 425,
/* 440 */ -438,
/* 441 */ 153,
/* 442 */ 0,
/* 443 */ -438,
/* 444 */ 233,
/* 445 */ 0,
/* 446 */ 450,
/* 447 */ 182,
/* 448 */ -445,
/* 449 */ 35,
/* 450 */ 454,
/* 451 */ 445,
/* 452 */ -450,
/* 453 */ 154,
/* 454 */ 0,
/* 455 */ -450,
/* 456 */ 234,
/* 457 */ 0,
/* 458 */ 470,
/* 459 */ 462,
/* 460 */ -457,
/* 461 */ 36,
/* 462 */ 467,
/* 463 */ 50044,
/* 464 */ 50290,
/* 465 */ -462,
/* 466 */ 155,
/* 467 */ 0,
/* 468 */ -462,
/* 469 */ 235,
/* 470 */ 0,
/* 471 */ 475,
/* 472 */ 483,
/* 473 */ -470,
/* 474 */ 37,
/* 475 */ 480,
/* 476 */ 470,
/* 477 */ 50044,
/* 478 */ -475,
/* 479 */ 156,
/* 480 */ 0,
/* 481 */ -475,
/* 482 */ 236,
/* 483 */ 0,
/* 484 */ 86,
/* 485 */ 488,
/* 486 */ -483,
/* 487 */ 38,
/* 488 */ 492,
/* 489 */ 366,
/* 490 */ -488,
/* 491 */ 157,
/* 492 */ 0,
/* 493 */ 496,
/* 494 */ -488,
/* 495 */ 159,
/* 496 */ 500,
/* 497 */ 559,
/* 498 */ -496,
/* 499 */ 158,
/* 500 */ 0,
/* 501 */ -496,
/* 502 */ 237,
/* 503 */ 0,
/* 504 */ 508,
/* 505 */ 1173,
/* 506 */ -503,
/* 507 */ 39,
/* 508 */ 513,
/* 509 */ 503,
/* 510 */ 50044,
/* 511 */ -508,
/* 512 */ 160,
/* 513 */ 0,
/* 514 */ -508,
/* 515 */ 238,
/* 516 */ 520,
/* 517 */ 829,
/* 518 */ -516,
/* 519 */ 40,
/* 520 */ 0,
/* 521 */ 50123,
/* 522 */ 534,
/* 523 */ 527,
/* 524 */ 50125,
/* 525 */ -516,
/* 526 */ 41,
/* 527 */ 531,
/* 528 */ 50044,
/* 529 */ -527,
/* 530 */ 161,
/* 531 */ 0,
/* 532 */ -527,
/* 533 */ 239,
/* 534 */ 0,
/* 535 */ 539,
/* 536 */ 516,
/* 537 */ -534,
/* 538 */ 42,
/* 539 */ 544,
/* 540 */ 534,
/* 541 */ 50044,
/* 542 */ -539,
/* 543 */ 162,
/* 544 */ 0,
/* 545 */ -539,
/* 546 */ 240,
/* 547 */ 0,
/* 548 */ 270,
/* 549 */ 552,
/* 550 */ -547,
/* 551 */ 43,
/* 552 */ 556,
/* 553 */ 559,
/* 554 */ -552,
/* 555 */ 163,
/* 556 */ 0,
/* 557 */ -552,
/* 558 */ 241,
/* 559 */ 563,
/* 560 */ 425,
/* 561 */ -559,
/* 562 */ 44,
/* 563 */ 0,
/* 564 */ 568,
/* 565 */ 575,
/* 566 */ -559,
/* 567 */ 45,
/* 568 */ 572,
/* 569 */ 425,
/* 570 */ -568,
/* 571 */ 164,
/* 572 */ 0,
/* 573 */ -568,
/* 574 */ 242,
/* 575 */ 581,
/* 576 */ 50040,
/* 577 */ 559,
/* 578 */ 50041,
/* 579 */ -575,
/* 580 */ 46,
/* 581 */ 0,
/* 582 */ 586,
/* 583 */ 593,
/* 584 */ -575,
/* 585 */ 47,
/* 586 */ 590,
/* 587 */ 575,
/* 588 */ -586,
/* 589 */ 165,
/* 590 */ 0,
/* 591 */ -586,
/* 592 */ 243,
/* 593 */ 599,
/* 594 */ 50091,
/* 595 */ 605,
/* 596 */ 50093,
/* 597 */ -593,
/* 598 */ 167,
/* 599 */ 0,
/* 600 */ 50040,
/* 601 */ 612,
/* 602 */ 50041,
/* 603 */ -593,
/* 604 */ 169,
/* 605 */ 609,
/* 606 */ 866,
/* 607 */ -605,
/* 608 */ 166,
/* 609 */ 0,
/* 610 */ -605,
/* 611 */ 244,
/* 612 */ 616,
/* 613 */ 457,
/* 614 */ -612,
/* 615 */ 168,
/* 616 */ 0,
/* 617 */ -612,
/* 618 */ 245,
/* 619 */ 0,
/* 620 */ 1173,
/* 621 */ -619,
/* 622 */ 48,
/* 623 */ 627,
/* 624 */ 647,
/* 625 */ -623,
/* 626 */ 49,
/* 627 */ 631,
/* 628 */ 666,
/* 629 */ -623,
/* 630 */ 50,
/* 631 */ 635,
/* 632 */ 678,
/* 633 */ -623,
/* 634 */ 51,
/* 635 */ 639,
/* 636 */ 711,
/* 637 */ -623,
/* 638 */ 52,
/* 639 */ 643,
/* 640 */ 736,
/* 641 */ -623,
/* 642 */ 53,
/* 643 */ 0,
/* 644 */ 787,
/* 645 */ -623,
/* 646 */ 54,
/* 647 */ 653,
/* 648 */ 1173,
/* 649 */ 50058,
/* 650 */ 623,
/* 651 */ -647,
/* 652 */ 55,
/* 653 */ 660,
/* 654 */ 50258,
/* 655 */ 866,
/* 656 */ 50058,
/* 657 */ 623,
/* 658 */ -647,
/* 659 */ 56,
/* 660 */ 0,
/* 661 */ 50262,
/* 662 */ 50058,
/* 663 */ 623,
/* 664 */ -647,
/* 665 */ 57,
/* 666 */ 0,
/* 667 */ 671,
/* 668 */ 50059,
/* 669 */ -666,
/* 670 */ 58,
/* 671 */ 675,
/* 672 */ 816,
/* 673 */ -671,
/* 674 */ 170,
/* 675 */ 0,
/* 676 */ -671,
/* 677 */ 246,
/* 678 */ 0,
/* 679 */ 50123,
/* 680 */ 685,
/* 681 */ 692,
/* 682 */ 50125,
/* 683 */ -678,
/* 684 */ 59,
/* 685 */ 689,
/* 686 */ 74,
/* 687 */ -685,
/* 688 */ 171,
/* 689 */ 0,
/* 690 */ -685,
/* 691 */ 247,
/* 692 */ 696,
/* 693 */ 699,
/* 694 */ -692,
/* 695 */ 172,
/* 696 */ 0,
/* 697 */ -692,
/* 698 */ 248,
/* 699 */ 0,
/* 700 */ 704,
/* 701 */ 623,
/* 702 */ -699,
/* 703 */ 60,
/* 704 */ 708,
/* 705 */ 699,
/* 706 */ -704,
/* 707 */ 173,
/* 708 */ 0,
/* 709 */ -704,
/* 710 */ 249,
/* 711 */ 720,
/* 712 */ 50271,
/* 713 */ 50040,
/* 714 */ 816,
/* 715 */ 50041,
/* 716 */ 623,
/* 717 */ 728,
/* 718 */ -711,
/* 719 */ 61,
/* 720 */ 0,
/* 721 */ 50281,
/* 722 */ 50040,
/* 723 */ 816,
/* 724 */ 50041,
/* 725 */ 623,
/* 726 */ -711,
/* 727 */ 62,
/* 728 */ 733,
/* 729 */ 50265,
/* 730 */ 623,
/* 731 */ -728,
/* 732 */ 174,
/* 733 */ 0,
/* 734 */ -728,
/* 735 */ 250,
/* 736 */ 744,
/* 737 */ 50287,
/* 738 */ 50040,
/* 739 */ 816,
/* 740 */ 50041,
/* 741 */ 623,
/* 742 */ -736,
/* 743 */ 63,
/* 744 */ 754,
/* 745 */ 50263,
/* 746 */ 623,
/* 747 */ 50287,
/* 748 */ 50040,
/* 749 */ 816,
/* 750 */ 50041,
/* 751 */ 50059,
/* 752 */ -736,
/* 753 */ 64,
/* 754 */ 0,
/* 755 */ 50269,
/* 756 */ 50040,
/* 757 */ 766,
/* 758 */ 50059,
/* 759 */ 773,
/* 760 */ 50059,
/* 761 */ 780,
/* 762 */ 50041,
/* 763 */ 623,
/* 764 */ -736,
/* 765 */ 65,
/* 766 */ 770,
/* 767 */ 816,
/* 768 */ -766,
/* 769 */ 175,
/* 770 */ 0,
/* 771 */ -766,
/* 772 */ 251,
/* 773 */ 777,
/* 774 */ 816,
/* 775 */ -773,
/* 776 */ 176,
/* 777 */ 0,
/* 778 */ -773,
/* 779 */ 252,
/* 780 */ 784,
/* 781 */ 816,
/* 782 */ -780,
/* 783 */ 177,
/* 784 */ 0,
/* 785 */ -780,
/* 786 */ 253,
/* 787 */ 793,
/* 788 */ 50270,
/* 789 */ 1173,
/* 790 */ 50059,
/* 791 */ -787,
/* 792 */ 66,
/* 793 */ 798,
/* 794 */ 50261,
/* 795 */ 50059,
/* 796 */ -787,
/* 797 */ 67,
/* 798 */ 803,
/* 799 */ 50257,
/* 800 */ 50059,
/* 801 */ -787,
/* 802 */ 68,
/* 803 */ 0,
/* 804 */ 50275,
/* 805 */ 809,
/* 806 */ 50059,
/* 807 */ -787,
/* 808 */ 69,
/* 809 */ 813,
/* 810 */ 816,
/* 811 */ -809,
/* 812 */ 178,
/* 813 */ 0,
/* 814 */ -809,
/* 815 */ 254,
/* 816 */ 0,
/* 817 */ 821,
/* 818 */ 829,
/* 819 */ -816,
/* 820 */ 70,
/* 821 */ 826,
/* 822 */ 816,
/* 823 */ 50044,
/* 824 */ -821,
/* 825 */ 179,
/* 826 */ 0,
/* 827 */ -821,
/* 828 */ 255,
/* 829 */ 833,
/* 830 */ 851,
/* 831 */ -829,
/* 832 */ 71,
/* 833 */ 0,
/* 834 */ 1018,
/* 835 */ 839,
/* 836 */ 829,
/* 837 */ -829,
/* 838 */ 72,
/* 839 */ 0,
/* 840 */ 843,
/* 841 */ -839,
/* 842 */ 73,
/* 843 */ 847,
/* 844 */ 50291,
/* 845 */ -843,
/* 846 */ 180,
/* 847 */ 0,
/* 848 */ 50061,
/* 849 */ -843,
/* 850 */ 181,
/* 851 */ 0,
/* 852 */ 870,
/* 853 */ 856,
/* 854 */ -851,
/* 855 */ 74,
/* 856 */ 863,
/* 857 */ 50063,
/* 858 */ 816,
/* 859 */ 50058,
/* 860 */ 851,
/* 861 */ -856,
/* 862 */ 182,
/* 863 */ 0,
/* 864 */ -856,
/* 865 */ 256,
/* 866 */ 0,
/* 867 */ 851,
/* 868 */ -866,
/* 869 */ 75,
/* 870 */ 0,
/* 871 */ 875,
/* 872 */ 883,
/* 873 */ -870,
/* 874 */ 76,
/* 875 */ 880,
/* 876 */ 870,
/* 877 */ 50297,
/* 878 */ -875,
/* 879 */ 183,
/* 880 */ 0,
/* 881 */ -875,
/* 882 */ 257,
/* 883 */ 0,
/* 884 */ 888,
/* 885 */ 896,
/* 886 */ -883,
/* 887 */ 77,
/* 888 */ 893,
/* 889 */ 883,
/* 890 */ 50298,
/* 891 */ -888,
/* 892 */ 184,
/* 893 */ 0,
/* 894 */ -888,
/* 895 */ 258,
/* 896 */ 0,
/* 897 */ 901,
/* 898 */ 909,
/* 899 */ -896,
/* 900 */ 78,
/* 901 */ 906,
/* 902 */ 896,
/* 903 */ 50301,
/* 904 */ -901,
/* 905 */ 185,
/* 906 */ 0,
/* 907 */ -901,
/* 908 */ 259,
/* 909 */ 0,
/* 910 */ 914,
/* 911 */ 922,
/* 912 */ -909,
/* 913 */ 79,
/* 914 */ 919,
/* 915 */ 909,
/* 916 */ 50303,
/* 917 */ -914,
/* 918 */ 186,
/* 919 */ 0,
/* 920 */ -914,
/* 921 */ 260,
/* 922 */ 0,
/* 923 */ 927,
/* 924 */ 935,
/* 925 */ -922,
/* 926 */ 80,
/* 927 */ 932,
/* 928 */ 922,
/* 929 */ 50302,
/* 930 */ -927,
/* 931 */ 187,
/* 932 */ 0,
/* 933 */ -927,
/* 934 */ 261,
/* 935 */ 0,
/* 936 */ 940,
/* 937 */ 948,
/* 938 */ -935,
/* 939 */ 81,
/* 940 */ 945,
/* 941 */ 935,
/* 942 */ 50292,
/* 943 */ -940,
/* 944 */ 188,
/* 945 */ 0,
/* 946 */ -940,
/* 947 */ 262,
/* 948 */ 0,
/* 949 */ 953,
/* 950 */ 961,
/* 951 */ -948,
/* 952 */ 82,
/* 953 */ 958,
/* 954 */ 948,
/* 955 */ 50304,
/* 956 */ -953,
/* 957 */ 189,
/* 958 */ 0,
/* 959 */ -953,
/* 960 */ 263,
/* 961 */ 0,
/* 962 */ 966,
/* 963 */ 982,
/* 964 */ -961,
/* 965 */ 83,
/* 966 */ 971,
/* 967 */ 961,
/* 968 */ 974,
/* 969 */ -966,
/* 970 */ 192,
/* 971 */ 0,
/* 972 */ -966,
/* 973 */ 264,
/* 974 */ 978,
/* 975 */ 50043,
/* 976 */ -974,
/* 977 */ 190,
/* 978 */ 0,
/* 979 */ 50045,
/* 980 */ -974,
/* 981 */ 191,
/* 982 */ 0,
/* 983 */ 987,
/* 984 */ 1007,
/* 985 */ -982,
/* 986 */ 84,
/* 987 */ 992,
/* 988 */ 982,
/* 989 */ 995,
/* 990 */ -987,
/* 991 */ 196,
/* 992 */ 0,
/* 993 */ -987,
/* 994 */ 265,
/* 995 */ 999,
/* 996 */ 50042,
/* 997 */ -995,
/* 998 */ 193,
/* 999 */ 1003,
/* 1000 */ 50047,
/* 1001 */ -995,
/* 1002 */ 194,
/* 1003 */ 0,
/* 1004 */ 50037,
/* 1005 */ -995,
/* 1006 */ 195,
/* 1007 */ 1011,
/* 1008 */ 1018,
/* 1009 */ -1007,
/* 1010 */ 85,
/* 1011 */ 0,
/* 1012 */ 50040,
/* 1013 */ 547,
/* 1014 */ 50041,
/* 1015 */ 1007,
/* 1016 */ -1007,
/* 1017 */ 86,
/* 1018 */ 1022,
/* 1019 */ 1080,
/* 1020 */ -1018,
/* 1021 */ 87,
/* 1022 */ 1027,
/* 1023 */ 1044,
/* 1024 */ 1018,
/* 1025 */ -1018,
/* 1026 */ 88,
/* 1027 */ 1032,
/* 1028 */ 1052,
/* 1029 */ 1007,
/* 1030 */ -1018,
/* 1031 */ 89,
/* 1032 */ 1037,
/* 1033 */ 50278,
/* 1034 */ 1018,
/* 1035 */ -1018,
/* 1036 */ 90,
/* 1037 */ 0,
/* 1038 */ 50278,
/* 1039 */ 50040,
/* 1040 */ 547,
/* 1041 */ 50041,
/* 1042 */ -1018,
/* 1043 */ 91,
/* 1044 */ 1048,
/* 1045 */ 50294,
/* 1046 */ -1044,
/* 1047 */ 197,
/* 1048 */ 0,
/* 1049 */ 50295,
/* 1050 */ -1044,
/* 1051 */ 198,
/* 1052 */ 0,
/* 1053 */ 1056,
/* 1054 */ -1052,
/* 1055 */ 92,
/* 1056 */ 1060,
/* 1057 */ 50302,
/* 1058 */ -1056,
/* 1059 */ 199,
/* 1060 */ 1064,
/* 1061 */ 50042,
/* 1062 */ -1056,
/* 1063 */ 200,
/* 1064 */ 1068,
/* 1065 */ 50043,
/* 1066 */ -1056,
/* 1067 */ 201,
/* 1068 */ 1072,
/* 1069 */ 50045,
/* 1070 */ -1056,
/* 1071 */ 202,
/* 1072 */ 1076,
/* 1073 */ 50126,
/* 1074 */ -1056,
/* 1075 */ 203,
/* 1076 */ 0,
/* 1077 */ 50033,
/* 1078 */ -1056,
/* 1079 */ 204,
/* 1080 */ 1084,
/* 1081 */ 1126,
/* 1082 */ -1080,
/* 1083 */ 93,
/* 1084 */ 0,
/* 1085 */ 1080,
/* 1086 */ 1089,
/* 1087 */ -1080,
/* 1088 */ 94,
/* 1089 */ 1095,
/* 1090 */ 50091,
/* 1091 */ 816,
/* 1092 */ 50093,
/* 1093 */ -1089,
/* 1094 */ 205,
/* 1095 */ 1101,
/* 1096 */ 50040,
/* 1097 */ 1119,
/* 1098 */ 50041,
/* 1099 */ -1089,
/* 1100 */ 207,
/* 1101 */ 1106,
/* 1102 */ 50046,
/* 1103 */ 1173,
/* 1104 */ -1089,
/* 1105 */ 208,
/* 1106 */ 1111,
/* 1107 */ 50296,
/* 1108 */ 1173,
/* 1109 */ -1089,
/* 1110 */ 209,
/* 1111 */ 1115,
/* 1112 */ 50294,
/* 1113 */ -1089,
/* 1114 */ 210,
/* 1115 */ 0,
/* 1116 */ 50295,
/* 1117 */ -1089,
/* 1118 */ 211,
/* 1119 */ 1123,
/* 1120 */ 1144,
/* 1121 */ -1119,
/* 1122 */ 206,
/* 1123 */ 0,
/* 1124 */ -1119,
/* 1125 */ 266,
/* 1126 */ 1130,
/* 1127 */ 1173,
/* 1128 */ -1126,
/* 1129 */ 95,
/* 1130 */ 1134,
/* 1131 */ 1157,
/* 1132 */ -1126,
/* 1133 */ 96,
/* 1134 */ 1138,
/* 1135 */ 50289,
/* 1136 */ -1126,
/* 1137 */ 97,
/* 1138 */ 0,
/* 1139 */ 50040,
/* 1140 */ 816,
/* 1141 */ 50041,
/* 1142 */ -1126,
/* 1143 */ 98,
/* 1144 */ 0,
/* 1145 */ 1149,
/* 1146 */ 829,
/* 1147 */ -1144,
/* 1148 */ 99,
/* 1149 */ 1154,
/* 1150 */ 1144,
/* 1151 */ 50044,
/* 1152 */ -1149,
/* 1153 */ 212,
/* 1154 */ 0,
/* 1155 */ -1149,
/* 1156 */ 267,
/* 1157 */ 1161,
/* 1158 */ 50308,
/* 1159 */ -1157,
/* 1160 */ 100,
/* 1161 */ 1165,
/* 1162 */ 50306,
/* 1163 */ -1157,
/* 1164 */ 101,
/* 1165 */ 1169,
/* 1166 */ 50307,
/* 1167 */ -1157,
/* 1168 */ 102,
/* 1169 */ 0,
/* 1170 */ 1173,
/* 1171 */ -1157,
/* 1172 */ 103,
/* 1173 */ 0,
/* 1174 */ 50299,
/* 1175 */ -1173,
/* 1176 */ 104,
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
/* 6 */ 10,
/* 7 */ 1,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 0,
/* 11 */ 1,
/* 12 */ -6,
/* 13 */ 2,
/* 14 */ 19,
/* 15 */ 1,
/* 16 */ 1,
/* 17 */ -14,
/* 18 */ 1,
/* 19 */ 0,
/* 20 */ -14,
/* 21 */ 2,
/* 22 */ 0,
/* 23 */ 50035,
/* 24 */ 50305,
/* 25 */ 1,
/* 26 */ -22,
/* 27 */ 1,
/* 28 */ 0,
/* 29 */ 50289,
/* 30 */ -28,
/* 31 */ 1,
/* 32 */ 36,
/* 33 */ 1,
/* 34 */ -32,
/* 35 */ 1,
/* 36 */ 0,
/* 37 */ 1,
/* 38 */ -32,
/* 39 */ 2,
/* 40 */ 0,
/* 41 */ 1,
/* 42 */ 1,
/* 43 */ 1,
/* 44 */ 1,
/* 45 */ -40,
/* 46 */ 1,
/* 47 */ 51,
/* 48 */ 1,
/* 49 */ -47,
/* 50 */ 1,
/* 51 */ 0,
/* 52 */ -47,
/* 53 */ 2,
/* 54 */ 58,
/* 55 */ 1,
/* 56 */ -54,
/* 57 */ 1,
/* 58 */ 0,
/* 59 */ -54,
/* 60 */ 2,
/* 61 */ 0,
/* 62 */ 1,
/* 63 */ 1,
/* 64 */ 50059,
/* 65 */ -61,
/* 66 */ 1,
/* 67 */ 71,
/* 68 */ 1,
/* 69 */ -67,
/* 70 */ 1,
/* 71 */ 0,
/* 72 */ -67,
/* 73 */ 2,
/* 74 */ 0,
/* 75 */ 1,
/* 76 */ 1,
/* 77 */ -74,
/* 78 */ 1,
/* 79 */ 83,
/* 80 */ 1,
/* 81 */ -79,
/* 82 */ 1,
/* 83 */ 0,
/* 84 */ -79,
/* 85 */ 2,
/* 86 */ 0,
/* 87 */ 1,
/* 88 */ 1,
/* 89 */ -86,
/* 90 */ 1,
/* 91 */ 95,
/* 92 */ 1,
/* 93 */ -91,
/* 94 */ 1,
/* 95 */ 99,
/* 96 */ 1,
/* 97 */ -91,
/* 98 */ 2,
/* 99 */ 0,
/* 100 */ 1,
/* 101 */ -91,
/* 102 */ 3,
/* 103 */ 107,
/* 104 */ 1,
/* 105 */ -103,
/* 106 */ 1,
/* 107 */ 0,
/* 108 */ -103,
/* 109 */ 2,
/* 110 */ 0,
/* 111 */ 1,
/* 112 */ -110,
/* 113 */ 1,
/* 114 */ 118,
/* 115 */ 50256,
/* 116 */ -114,
/* 117 */ 1,
/* 118 */ 122,
/* 119 */ 50274,
/* 120 */ -114,
/* 121 */ 2,
/* 122 */ 126,
/* 123 */ 50279,
/* 124 */ -114,
/* 125 */ 3,
/* 126 */ 130,
/* 127 */ 50267,
/* 128 */ -114,
/* 129 */ 4,
/* 130 */ 0,
/* 131 */ 50282,
/* 132 */ -114,
/* 133 */ 5,
/* 134 */ 138,
/* 135 */ 1,
/* 136 */ -134,
/* 137 */ 1,
/* 138 */ 142,
/* 139 */ 1,
/* 140 */ -134,
/* 141 */ 2,
/* 142 */ 0,
/* 143 */ 1,
/* 144 */ -134,
/* 145 */ 3,
/* 146 */ 150,
/* 147 */ 50285,
/* 148 */ -146,
/* 149 */ 1,
/* 150 */ 154,
/* 151 */ 50259,
/* 152 */ -146,
/* 153 */ 2,
/* 154 */ 158,
/* 155 */ 50276,
/* 156 */ -146,
/* 157 */ 3,
/* 158 */ 162,
/* 159 */ 50272,
/* 160 */ -146,
/* 161 */ 4,
/* 162 */ 166,
/* 163 */ 50273,
/* 164 */ -146,
/* 165 */ 5,
/* 166 */ 170,
/* 167 */ 50268,
/* 168 */ -146,
/* 169 */ 6,
/* 170 */ 174,
/* 171 */ 50264,
/* 172 */ -146,
/* 173 */ 7,
/* 174 */ 178,
/* 175 */ 50277,
/* 176 */ -146,
/* 177 */ 8,
/* 178 */ 0,
/* 179 */ 50284,
/* 180 */ -146,
/* 181 */ 9,
/* 182 */ 0,
/* 183 */ 1,
/* 184 */ -182,
/* 185 */ 1,
/* 186 */ 190,
/* 187 */ 50260,
/* 188 */ -186,
/* 189 */ 1,
/* 190 */ 0,
/* 191 */ 50286,
/* 192 */ -186,
/* 193 */ 2,
/* 194 */ 202,
/* 195 */ 1,
/* 196 */ 1,
/* 197 */ 50123,
/* 198 */ 1,
/* 199 */ 50125,
/* 200 */ -194,
/* 201 */ 1,
/* 202 */ 0,
/* 203 */ 1,
/* 204 */ 1,
/* 205 */ -194,
/* 206 */ 2,
/* 207 */ 211,
/* 208 */ 1,
/* 209 */ -207,
/* 210 */ 1,
/* 211 */ 0,
/* 212 */ -207,
/* 213 */ 2,
/* 214 */ 0,
/* 215 */ 1,
/* 216 */ -214,
/* 217 */ 1,
/* 218 */ 222,
/* 219 */ 50280,
/* 220 */ -218,
/* 221 */ 1,
/* 222 */ 0,
/* 223 */ 50283,
/* 224 */ -218,
/* 225 */ 2,
/* 226 */ 0,
/* 227 */ 1,
/* 228 */ 1,
/* 229 */ -226,
/* 230 */ 1,
/* 231 */ 235,
/* 232 */ 1,
/* 233 */ -231,
/* 234 */ 1,
/* 235 */ 0,
/* 236 */ -231,
/* 237 */ 2,
/* 238 */ 0,
/* 239 */ 1,
/* 240 */ 1,
/* 241 */ -238,
/* 242 */ 1,
/* 243 */ 248,
/* 244 */ 1,
/* 245 */ 50044,
/* 246 */ -243,
/* 247 */ 1,
/* 248 */ 0,
/* 249 */ -243,
/* 250 */ 2,
/* 251 */ 0,
/* 252 */ 1,
/* 253 */ 1,
/* 254 */ -251,
/* 255 */ 1,
/* 256 */ 261,
/* 257 */ 1,
/* 258 */ 50061,
/* 259 */ -256,
/* 260 */ 1,
/* 261 */ 0,
/* 262 */ -256,
/* 263 */ 2,
/* 264 */ 0,
/* 265 */ 1,
/* 266 */ 1,
/* 267 */ 50059,
/* 268 */ -264,
/* 269 */ 1,
/* 270 */ 0,
/* 271 */ 1,
/* 272 */ 1,
/* 273 */ -270,
/* 274 */ 1,
/* 275 */ 279,
/* 276 */ 1,
/* 277 */ -275,
/* 278 */ 1,
/* 279 */ 0,
/* 280 */ 1,
/* 281 */ -275,
/* 282 */ 2,
/* 283 */ 287,
/* 284 */ 1,
/* 285 */ -283,
/* 286 */ 1,
/* 287 */ 0,
/* 288 */ -283,
/* 289 */ 2,
/* 290 */ 0,
/* 291 */ 1,
/* 292 */ 1,
/* 293 */ -290,
/* 294 */ 1,
/* 295 */ 300,
/* 296 */ 1,
/* 297 */ 50044,
/* 298 */ -295,
/* 299 */ 1,
/* 300 */ 0,
/* 301 */ -295,
/* 302 */ 2,
/* 303 */ 307,
/* 304 */ 1,
/* 305 */ -303,
/* 306 */ 1,
/* 307 */ 0,
/* 308 */ 1,
/* 309 */ 50058,
/* 310 */ 1,
/* 311 */ -303,
/* 312 */ 2,
/* 313 */ 317,
/* 314 */ 1,
/* 315 */ -313,
/* 316 */ 1,
/* 317 */ 0,
/* 318 */ -313,
/* 319 */ 2,
/* 320 */ 328,
/* 321 */ 50266,
/* 322 */ 1,
/* 323 */ 50123,
/* 324 */ 1,
/* 325 */ 50125,
/* 326 */ -320,
/* 327 */ 1,
/* 328 */ 0,
/* 329 */ 50266,
/* 330 */ 1,
/* 331 */ -320,
/* 332 */ 2,
/* 333 */ 337,
/* 334 */ 1,
/* 335 */ -333,
/* 336 */ 1,
/* 337 */ 0,
/* 338 */ -333,
/* 339 */ 2,
/* 340 */ 0,
/* 341 */ 1,
/* 342 */ 1,
/* 343 */ -340,
/* 344 */ 1,
/* 345 */ 350,
/* 346 */ 1,
/* 347 */ 50044,
/* 348 */ -345,
/* 349 */ 1,
/* 350 */ 0,
/* 351 */ -345,
/* 352 */ 2,
/* 353 */ 0,
/* 354 */ 1,
/* 355 */ 1,
/* 356 */ -353,
/* 357 */ 1,
/* 358 */ 363,
/* 359 */ 50061,
/* 360 */ 1,
/* 361 */ -358,
/* 362 */ 1,
/* 363 */ 0,
/* 364 */ -358,
/* 365 */ 2,
/* 366 */ 0,
/* 367 */ 1,
/* 368 */ 1,
/* 369 */ -366,
/* 370 */ 1,
/* 371 */ 375,
/* 372 */ 1,
/* 373 */ -371,
/* 374 */ 1,
/* 375 */ 0,
/* 376 */ -371,
/* 377 */ 2,
/* 378 */ 382,
/* 379 */ 1,
/* 380 */ -378,
/* 381 */ 1,
/* 382 */ 388,
/* 383 */ 50040,
/* 384 */ 1,
/* 385 */ 50041,
/* 386 */ -378,
/* 387 */ 2,
/* 388 */ 0,
/* 389 */ 1,
/* 390 */ 1,
/* 391 */ -378,
/* 392 */ 3,
/* 393 */ 399,
/* 394 */ 50091,
/* 395 */ 1,
/* 396 */ 50093,
/* 397 */ -393,
/* 398 */ 1,
/* 399 */ 405,
/* 400 */ 50040,
/* 401 */ 1,
/* 402 */ 50041,
/* 403 */ -393,
/* 404 */ 2,
/* 405 */ 0,
/* 406 */ 50040,
/* 407 */ 1,
/* 408 */ 50041,
/* 409 */ -393,
/* 410 */ 3,
/* 411 */ 415,
/* 412 */ 1,
/* 413 */ -411,
/* 414 */ 1,
/* 415 */ 0,
/* 416 */ -411,
/* 417 */ 2,
/* 418 */ 422,
/* 419 */ 1,
/* 420 */ -418,
/* 421 */ 1,
/* 422 */ 0,
/* 423 */ -418,
/* 424 */ 2,
/* 425 */ 0,
/* 426 */ 50042,
/* 427 */ 1,
/* 428 */ 1,
/* 429 */ -425,
/* 430 */ 1,
/* 431 */ 435,
/* 432 */ 1,
/* 433 */ -431,
/* 434 */ 1,
/* 435 */ 0,
/* 436 */ -431,
/* 437 */ 2,
/* 438 */ 442,
/* 439 */ 1,
/* 440 */ -438,
/* 441 */ 1,
/* 442 */ 0,
/* 443 */ -438,
/* 444 */ 2,
/* 445 */ 0,
/* 446 */ 1,
/* 447 */ 1,
/* 448 */ -445,
/* 449 */ 1,
/* 450 */ 454,
/* 451 */ 1,
/* 452 */ -450,
/* 453 */ 1,
/* 454 */ 0,
/* 455 */ -450,
/* 456 */ 2,
/* 457 */ 0,
/* 458 */ 1,
/* 459 */ 1,
/* 460 */ -457,
/* 461 */ 1,
/* 462 */ 467,
/* 463 */ 50044,
/* 464 */ 50290,
/* 465 */ -462,
/* 466 */ 1,
/* 467 */ 0,
/* 468 */ -462,
/* 469 */ 2,
/* 470 */ 0,
/* 471 */ 1,
/* 472 */ 1,
/* 473 */ -470,
/* 474 */ 1,
/* 475 */ 480,
/* 476 */ 1,
/* 477 */ 50044,
/* 478 */ -475,
/* 479 */ 1,
/* 480 */ 0,
/* 481 */ -475,
/* 482 */ 2,
/* 483 */ 0,
/* 484 */ 1,
/* 485 */ 1,
/* 486 */ -483,
/* 487 */ 1,
/* 488 */ 492,
/* 489 */ 1,
/* 490 */ -488,
/* 491 */ 1,
/* 492 */ 0,
/* 493 */ 1,
/* 494 */ -488,
/* 495 */ 2,
/* 496 */ 500,
/* 497 */ 1,
/* 498 */ -496,
/* 499 */ 1,
/* 500 */ 0,
/* 501 */ -496,
/* 502 */ 2,
/* 503 */ 0,
/* 504 */ 1,
/* 505 */ 1,
/* 506 */ -503,
/* 507 */ 1,
/* 508 */ 513,
/* 509 */ 1,
/* 510 */ 50044,
/* 511 */ -508,
/* 512 */ 1,
/* 513 */ 0,
/* 514 */ -508,
/* 515 */ 2,
/* 516 */ 520,
/* 517 */ 1,
/* 518 */ -516,
/* 519 */ 1,
/* 520 */ 0,
/* 521 */ 50123,
/* 522 */ 1,
/* 523 */ 1,
/* 524 */ 50125,
/* 525 */ -516,
/* 526 */ 2,
/* 527 */ 531,
/* 528 */ 50044,
/* 529 */ -527,
/* 530 */ 1,
/* 531 */ 0,
/* 532 */ -527,
/* 533 */ 2,
/* 534 */ 0,
/* 535 */ 1,
/* 536 */ 1,
/* 537 */ -534,
/* 538 */ 1,
/* 539 */ 544,
/* 540 */ 1,
/* 541 */ 50044,
/* 542 */ -539,
/* 543 */ 1,
/* 544 */ 0,
/* 545 */ -539,
/* 546 */ 2,
/* 547 */ 0,
/* 548 */ 1,
/* 549 */ 1,
/* 550 */ -547,
/* 551 */ 1,
/* 552 */ 556,
/* 553 */ 1,
/* 554 */ -552,
/* 555 */ 1,
/* 556 */ 0,
/* 557 */ -552,
/* 558 */ 2,
/* 559 */ 563,
/* 560 */ 1,
/* 561 */ -559,
/* 562 */ 1,
/* 563 */ 0,
/* 564 */ 1,
/* 565 */ 1,
/* 566 */ -559,
/* 567 */ 2,
/* 568 */ 572,
/* 569 */ 1,
/* 570 */ -568,
/* 571 */ 1,
/* 572 */ 0,
/* 573 */ -568,
/* 574 */ 2,
/* 575 */ 581,
/* 576 */ 50040,
/* 577 */ 1,
/* 578 */ 50041,
/* 579 */ -575,
/* 580 */ 1,
/* 581 */ 0,
/* 582 */ 1,
/* 583 */ 1,
/* 584 */ -575,
/* 585 */ 2,
/* 586 */ 590,
/* 587 */ 1,
/* 588 */ -586,
/* 589 */ 1,
/* 590 */ 0,
/* 591 */ -586,
/* 592 */ 2,
/* 593 */ 599,
/* 594 */ 50091,
/* 595 */ 1,
/* 596 */ 50093,
/* 597 */ -593,
/* 598 */ 1,
/* 599 */ 0,
/* 600 */ 50040,
/* 601 */ 1,
/* 602 */ 50041,
/* 603 */ -593,
/* 604 */ 2,
/* 605 */ 609,
/* 606 */ 1,
/* 607 */ -605,
/* 608 */ 1,
/* 609 */ 0,
/* 610 */ -605,
/* 611 */ 2,
/* 612 */ 616,
/* 613 */ 1,
/* 614 */ -612,
/* 615 */ 1,
/* 616 */ 0,
/* 617 */ -612,
/* 618 */ 2,
/* 619 */ 0,
/* 620 */ 1,
/* 621 */ -619,
/* 622 */ 1,
/* 623 */ 627,
/* 624 */ 1,
/* 625 */ -623,
/* 626 */ 1,
/* 627 */ 631,
/* 628 */ 1,
/* 629 */ -623,
/* 630 */ 2,
/* 631 */ 635,
/* 632 */ 1,
/* 633 */ -623,
/* 634 */ 3,
/* 635 */ 639,
/* 636 */ 1,
/* 637 */ -623,
/* 638 */ 4,
/* 639 */ 643,
/* 640 */ 1,
/* 641 */ -623,
/* 642 */ 5,
/* 643 */ 0,
/* 644 */ 1,
/* 645 */ -623,
/* 646 */ 6,
/* 647 */ 653,
/* 648 */ 1,
/* 649 */ 50058,
/* 650 */ 1,
/* 651 */ -647,
/* 652 */ 1,
/* 653 */ 660,
/* 654 */ 50258,
/* 655 */ 1,
/* 656 */ 50058,
/* 657 */ 1,
/* 658 */ -647,
/* 659 */ 2,
/* 660 */ 0,
/* 661 */ 50262,
/* 662 */ 50058,
/* 663 */ 1,
/* 664 */ -647,
/* 665 */ 3,
/* 666 */ 0,
/* 667 */ 1,
/* 668 */ 50059,
/* 669 */ -666,
/* 670 */ 1,
/* 671 */ 675,
/* 672 */ 1,
/* 673 */ -671,
/* 674 */ 1,
/* 675 */ 0,
/* 676 */ -671,
/* 677 */ 2,
/* 678 */ 0,
/* 679 */ 50123,
/* 680 */ 1,
/* 681 */ 1,
/* 682 */ 50125,
/* 683 */ -678,
/* 684 */ 1,
/* 685 */ 689,
/* 686 */ 1,
/* 687 */ -685,
/* 688 */ 1,
/* 689 */ 0,
/* 690 */ -685,
/* 691 */ 2,
/* 692 */ 696,
/* 693 */ 1,
/* 694 */ -692,
/* 695 */ 1,
/* 696 */ 0,
/* 697 */ -692,
/* 698 */ 2,
/* 699 */ 0,
/* 700 */ 1,
/* 701 */ 1,
/* 702 */ -699,
/* 703 */ 1,
/* 704 */ 708,
/* 705 */ 1,
/* 706 */ -704,
/* 707 */ 1,
/* 708 */ 0,
/* 709 */ -704,
/* 710 */ 2,
/* 711 */ 720,
/* 712 */ 50271,
/* 713 */ 50040,
/* 714 */ 1,
/* 715 */ 50041,
/* 716 */ 1,
/* 717 */ 1,
/* 718 */ -711,
/* 719 */ 1,
/* 720 */ 0,
/* 721 */ 50281,
/* 722 */ 50040,
/* 723 */ 1,
/* 724 */ 50041,
/* 725 */ 1,
/* 726 */ -711,
/* 727 */ 2,
/* 728 */ 733,
/* 729 */ 50265,
/* 730 */ 1,
/* 731 */ -728,
/* 732 */ 1,
/* 733 */ 0,
/* 734 */ -728,
/* 735 */ 2,
/* 736 */ 744,
/* 737 */ 50287,
/* 738 */ 50040,
/* 739 */ 1,
/* 740 */ 50041,
/* 741 */ 1,
/* 742 */ -736,
/* 743 */ 1,
/* 744 */ 754,
/* 745 */ 50263,
/* 746 */ 1,
/* 747 */ 50287,
/* 748 */ 50040,
/* 749 */ 1,
/* 750 */ 50041,
/* 751 */ 50059,
/* 752 */ -736,
/* 753 */ 2,
/* 754 */ 0,
/* 755 */ 50269,
/* 756 */ 50040,
/* 757 */ 1,
/* 758 */ 50059,
/* 759 */ 1,
/* 760 */ 50059,
/* 761 */ 1,
/* 762 */ 50041,
/* 763 */ 1,
/* 764 */ -736,
/* 765 */ 3,
/* 766 */ 770,
/* 767 */ 1,
/* 768 */ -766,
/* 769 */ 1,
/* 770 */ 0,
/* 771 */ -766,
/* 772 */ 2,
/* 773 */ 777,
/* 774 */ 1,
/* 775 */ -773,
/* 776 */ 1,
/* 777 */ 0,
/* 778 */ -773,
/* 779 */ 2,
/* 780 */ 784,
/* 781 */ 1,
/* 782 */ -780,
/* 783 */ 1,
/* 784 */ 0,
/* 785 */ -780,
/* 786 */ 2,
/* 787 */ 793,
/* 788 */ 50270,
/* 789 */ 1,
/* 790 */ 50059,
/* 791 */ -787,
/* 792 */ 1,
/* 793 */ 798,
/* 794 */ 50261,
/* 795 */ 50059,
/* 796 */ -787,
/* 797 */ 2,
/* 798 */ 803,
/* 799 */ 50257,
/* 800 */ 50059,
/* 801 */ -787,
/* 802 */ 3,
/* 803 */ 0,
/* 804 */ 50275,
/* 805 */ 1,
/* 806 */ 50059,
/* 807 */ -787,
/* 808 */ 4,
/* 809 */ 813,
/* 810 */ 1,
/* 811 */ -809,
/* 812 */ 1,
/* 813 */ 0,
/* 814 */ -809,
/* 815 */ 2,
/* 816 */ 0,
/* 817 */ 1,
/* 818 */ 1,
/* 819 */ -816,
/* 820 */ 1,
/* 821 */ 826,
/* 822 */ 1,
/* 823 */ 50044,
/* 824 */ -821,
/* 825 */ 1,
/* 826 */ 0,
/* 827 */ -821,
/* 828 */ 2,
/* 829 */ 833,
/* 830 */ 1,
/* 831 */ -829,
/* 832 */ 1,
/* 833 */ 0,
/* 834 */ 1,
/* 835 */ 1,
/* 836 */ 1,
/* 837 */ -829,
/* 838 */ 2,
/* 839 */ 0,
/* 840 */ 1,
/* 841 */ -839,
/* 842 */ 1,
/* 843 */ 847,
/* 844 */ 50291,
/* 845 */ -843,
/* 846 */ 1,
/* 847 */ 0,
/* 848 */ 50061,
/* 849 */ -843,
/* 850 */ 2,
/* 851 */ 0,
/* 852 */ 1,
/* 853 */ 1,
/* 854 */ -851,
/* 855 */ 1,
/* 856 */ 863,
/* 857 */ 50063,
/* 858 */ 1,
/* 859 */ 50058,
/* 860 */ 1,
/* 861 */ -856,
/* 862 */ 1,
/* 863 */ 0,
/* 864 */ -856,
/* 865 */ 2,
/* 866 */ 0,
/* 867 */ 1,
/* 868 */ -866,
/* 869 */ 1,
/* 870 */ 0,
/* 871 */ 1,
/* 872 */ 1,
/* 873 */ -870,
/* 874 */ 1,
/* 875 */ 880,
/* 876 */ 1,
/* 877 */ 50297,
/* 878 */ -875,
/* 879 */ 1,
/* 880 */ 0,
/* 881 */ -875,
/* 882 */ 2,
/* 883 */ 0,
/* 884 */ 1,
/* 885 */ 1,
/* 886 */ -883,
/* 887 */ 1,
/* 888 */ 893,
/* 889 */ 1,
/* 890 */ 50298,
/* 891 */ -888,
/* 892 */ 1,
/* 893 */ 0,
/* 894 */ -888,
/* 895 */ 2,
/* 896 */ 0,
/* 897 */ 1,
/* 898 */ 1,
/* 899 */ -896,
/* 900 */ 1,
/* 901 */ 906,
/* 902 */ 1,
/* 903 */ 50301,
/* 904 */ -901,
/* 905 */ 1,
/* 906 */ 0,
/* 907 */ -901,
/* 908 */ 2,
/* 909 */ 0,
/* 910 */ 1,
/* 911 */ 1,
/* 912 */ -909,
/* 913 */ 1,
/* 914 */ 919,
/* 915 */ 1,
/* 916 */ 50303,
/* 917 */ -914,
/* 918 */ 1,
/* 919 */ 0,
/* 920 */ -914,
/* 921 */ 2,
/* 922 */ 0,
/* 923 */ 1,
/* 924 */ 1,
/* 925 */ -922,
/* 926 */ 1,
/* 927 */ 932,
/* 928 */ 1,
/* 929 */ 50302,
/* 930 */ -927,
/* 931 */ 1,
/* 932 */ 0,
/* 933 */ -927,
/* 934 */ 2,
/* 935 */ 0,
/* 936 */ 1,
/* 937 */ 1,
/* 938 */ -935,
/* 939 */ 1,
/* 940 */ 945,
/* 941 */ 1,
/* 942 */ 50292,
/* 943 */ -940,
/* 944 */ 1,
/* 945 */ 0,
/* 946 */ -940,
/* 947 */ 2,
/* 948 */ 0,
/* 949 */ 1,
/* 950 */ 1,
/* 951 */ -948,
/* 952 */ 1,
/* 953 */ 958,
/* 954 */ 1,
/* 955 */ 50304,
/* 956 */ -953,
/* 957 */ 1,
/* 958 */ 0,
/* 959 */ -953,
/* 960 */ 2,
/* 961 */ 0,
/* 962 */ 1,
/* 963 */ 1,
/* 964 */ -961,
/* 965 */ 1,
/* 966 */ 971,
/* 967 */ 1,
/* 968 */ 1,
/* 969 */ -966,
/* 970 */ 1,
/* 971 */ 0,
/* 972 */ -966,
/* 973 */ 2,
/* 974 */ 978,
/* 975 */ 50043,
/* 976 */ -974,
/* 977 */ 1,
/* 978 */ 0,
/* 979 */ 50045,
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
/* 996 */ 50042,
/* 997 */ -995,
/* 998 */ 1,
/* 999 */ 1003,
/* 1000 */ 50047,
/* 1001 */ -995,
/* 1002 */ 2,
/* 1003 */ 0,
/* 1004 */ 50037,
/* 1005 */ -995,
/* 1006 */ 3,
/* 1007 */ 1011,
/* 1008 */ 1,
/* 1009 */ -1007,
/* 1010 */ 1,
/* 1011 */ 0,
/* 1012 */ 50040,
/* 1013 */ 1,
/* 1014 */ 50041,
/* 1015 */ 1,
/* 1016 */ -1007,
/* 1017 */ 2,
/* 1018 */ 1022,
/* 1019 */ 1,
/* 1020 */ -1018,
/* 1021 */ 1,
/* 1022 */ 1027,
/* 1023 */ 1,
/* 1024 */ 1,
/* 1025 */ -1018,
/* 1026 */ 2,
/* 1027 */ 1032,
/* 1028 */ 1,
/* 1029 */ 1,
/* 1030 */ -1018,
/* 1031 */ 3,
/* 1032 */ 1037,
/* 1033 */ 50278,
/* 1034 */ 1,
/* 1035 */ -1018,
/* 1036 */ 4,
/* 1037 */ 0,
/* 1038 */ 50278,
/* 1039 */ 50040,
/* 1040 */ 1,
/* 1041 */ 50041,
/* 1042 */ -1018,
/* 1043 */ 5,
/* 1044 */ 1048,
/* 1045 */ 50294,
/* 1046 */ -1044,
/* 1047 */ 1,
/* 1048 */ 0,
/* 1049 */ 50295,
/* 1050 */ -1044,
/* 1051 */ 2,
/* 1052 */ 0,
/* 1053 */ 1,
/* 1054 */ -1052,
/* 1055 */ 1,
/* 1056 */ 1060,
/* 1057 */ 50302,
/* 1058 */ -1056,
/* 1059 */ 1,
/* 1060 */ 1064,
/* 1061 */ 50042,
/* 1062 */ -1056,
/* 1063 */ 2,
/* 1064 */ 1068,
/* 1065 */ 50043,
/* 1066 */ -1056,
/* 1067 */ 3,
/* 1068 */ 1072,
/* 1069 */ 50045,
/* 1070 */ -1056,
/* 1071 */ 4,
/* 1072 */ 1076,
/* 1073 */ 50126,
/* 1074 */ -1056,
/* 1075 */ 5,
/* 1076 */ 0,
/* 1077 */ 50033,
/* 1078 */ -1056,
/* 1079 */ 6,
/* 1080 */ 1084,
/* 1081 */ 1,
/* 1082 */ -1080,
/* 1083 */ 1,
/* 1084 */ 0,
/* 1085 */ 1,
/* 1086 */ 1,
/* 1087 */ -1080,
/* 1088 */ 2,
/* 1089 */ 1095,
/* 1090 */ 50091,
/* 1091 */ 1,
/* 1092 */ 50093,
/* 1093 */ -1089,
/* 1094 */ 1,
/* 1095 */ 1101,
/* 1096 */ 50040,
/* 1097 */ 1,
/* 1098 */ 50041,
/* 1099 */ -1089,
/* 1100 */ 2,
/* 1101 */ 1106,
/* 1102 */ 50046,
/* 1103 */ 1,
/* 1104 */ -1089,
/* 1105 */ 3,
/* 1106 */ 1111,
/* 1107 */ 50296,
/* 1108 */ 1,
/* 1109 */ -1089,
/* 1110 */ 4,
/* 1111 */ 1115,
/* 1112 */ 50294,
/* 1113 */ -1089,
/* 1114 */ 5,
/* 1115 */ 0,
/* 1116 */ 50295,
/* 1117 */ -1089,
/* 1118 */ 6,
/* 1119 */ 1123,
/* 1120 */ 1,
/* 1121 */ -1119,
/* 1122 */ 1,
/* 1123 */ 0,
/* 1124 */ -1119,
/* 1125 */ 2,
/* 1126 */ 1130,
/* 1127 */ 1,
/* 1128 */ -1126,
/* 1129 */ 1,
/* 1130 */ 1134,
/* 1131 */ 1,
/* 1132 */ -1126,
/* 1133 */ 2,
/* 1134 */ 1138,
/* 1135 */ 50289,
/* 1136 */ -1126,
/* 1137 */ 3,
/* 1138 */ 0,
/* 1139 */ 50040,
/* 1140 */ 1,
/* 1141 */ 50041,
/* 1142 */ -1126,
/* 1143 */ 4,
/* 1144 */ 0,
/* 1145 */ 1,
/* 1146 */ 1,
/* 1147 */ -1144,
/* 1148 */ 1,
/* 1149 */ 1154,
/* 1150 */ 1,
/* 1151 */ 50044,
/* 1152 */ -1149,
/* 1153 */ 1,
/* 1154 */ 0,
/* 1155 */ -1149,
/* 1156 */ 2,
/* 1157 */ 1161,
/* 1158 */ 50308,
/* 1159 */ -1157,
/* 1160 */ 1,
/* 1161 */ 1165,
/* 1162 */ 50306,
/* 1163 */ -1157,
/* 1164 */ 2,
/* 1165 */ 1169,
/* 1166 */ 50307,
/* 1167 */ -1157,
/* 1168 */ 3,
/* 1169 */ 0,
/* 1170 */ 1,
/* 1171 */ -1157,
/* 1172 */ 4,
/* 1173 */ 0,
/* 1174 */ 50299,
/* 1175 */ -1173,
/* 1176 */ 1,
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
/* 11 */ 73004,
/* 12 */ 9999,
/* 13 */ 73015,
/* 14 */ 9999,
/* 15 */ 72006,
/* 16 */ 72025,
/* 17 */ 9999,
/* 18 */ 72025,
/* 19 */ 9999,
/* 20 */ 9999,
/* 21 */ 72025,
/* 22 */ 9999,
/* 23 */ 9999,
/* 24 */ 9999,
/* 25 */ 77036,
/* 26 */ 9999,
/* 27 */ 77004,
/* 28 */ 9999,
/* 29 */ 9999,
/* 30 */ 9999,
/* 31 */ 77043,
/* 32 */ 9999,
/* 33 */ 81004,
/* 34 */ 9999,
/* 35 */ 81022,
/* 36 */ 9999,
/* 37 */ 82004,
/* 38 */ 9999,
/* 39 */ 82014,
/* 40 */ 9999,
/* 41 */ 86004,
/* 42 */ 86032,
/* 43 */ 86043,
/* 44 */ 86065,
/* 45 */ 9999,
/* 46 */ 86004,
/* 47 */ 9999,
/* 48 */ 86006,
/* 49 */ 9999,
/* 50 */ 86027,
/* 51 */ 9999,
/* 52 */ 9999,
/* 53 */ 86027,
/* 54 */ 9999,
/* 55 */ 86045,
/* 56 */ 9999,
/* 57 */ 86060,
/* 58 */ 9999,
/* 59 */ 9999,
/* 60 */ 86060,
/* 61 */ 9999,
/* 62 */ 90004,
/* 63 */ 90027,
/* 64 */ 9999,
/* 65 */ 9999,
/* 66 */ 90025,
/* 67 */ 9999,
/* 68 */ 90029,
/* 69 */ 9999,
/* 70 */ 90048,
/* 71 */ 9999,
/* 72 */ 9999,
/* 73 */ 90048,
/* 74 */ 9999,
/* 75 */ 94004,
/* 76 */ 94026,
/* 77 */ 9999,
/* 78 */ 94004,
/* 79 */ 9999,
/* 80 */ 94006,
/* 81 */ 9999,
/* 82 */ 94021,
/* 83 */ 9999,
/* 84 */ 9999,
/* 85 */ 94021,
/* 86 */ 9999,
/* 87 */ 98004,
/* 88 */ 98066,
/* 89 */ 9999,
/* 90 */ 98004,
/* 91 */ 9999,
/* 92 */ 98006,
/* 93 */ 9999,
/* 94 */ 98028,
/* 95 */ 9999,
/* 96 */ 98032,
/* 97 */ 9999,
/* 98 */ 98045,
/* 99 */ 9999,
/* 100 */ 98049,
/* 101 */ 9999,
/* 102 */ 98062,
/* 103 */ 9999,
/* 104 */ 98068,
/* 105 */ 9999,
/* 106 */ 98089,
/* 107 */ 9999,
/* 108 */ 9999,
/* 109 */ 98089,
/* 110 */ 9999,
/* 111 */ 102004,
/* 112 */ 9999,
/* 113 */ 102004,
/* 114 */ 9999,
/* 115 */ 9999,
/* 116 */ 9999,
/* 117 */ 102009,
/* 118 */ 9999,
/* 119 */ 9999,
/* 120 */ 9999,
/* 121 */ 103011,
/* 122 */ 9999,
/* 123 */ 9999,
/* 124 */ 9999,
/* 125 */ 104009,
/* 126 */ 9999,
/* 127 */ 9999,
/* 128 */ 9999,
/* 129 */ 105009,
/* 130 */ 9999,
/* 131 */ 9999,
/* 132 */ 9999,
/* 133 */ 106010,
/* 134 */ 9999,
/* 135 */ 110004,
/* 136 */ 9999,
/* 137 */ 110004,
/* 138 */ 9999,
/* 139 */ 119004,
/* 140 */ 9999,
/* 141 */ 119028,
/* 142 */ 9999,
/* 143 */ 119032,
/* 144 */ 9999,
/* 145 */ 119045,
/* 146 */ 9999,
/* 147 */ 9999,
/* 148 */ 9999,
/* 149 */ 110009,
/* 150 */ 9999,
/* 151 */ 9999,
/* 152 */ 9999,
/* 153 */ 111007,
/* 154 */ 9999,
/* 155 */ 9999,
/* 156 */ 9999,
/* 157 */ 112008,
/* 158 */ 9999,
/* 159 */ 9999,
/* 160 */ 9999,
/* 161 */ 113006,
/* 162 */ 9999,
/* 163 */ 9999,
/* 164 */ 9999,
/* 165 */ 114007,
/* 166 */ 9999,
/* 167 */ 9999,
/* 168 */ 9999,
/* 169 */ 115008,
/* 170 */ 9999,
/* 171 */ 9999,
/* 172 */ 9999,
/* 173 */ 116009,
/* 174 */ 9999,
/* 175 */ 9999,
/* 176 */ 9999,
/* 177 */ 117009,
/* 178 */ 9999,
/* 179 */ 9999,
/* 180 */ 9999,
/* 181 */ 118011,
/* 182 */ 9999,
/* 183 */ 123004,
/* 184 */ 9999,
/* 185 */ 123004,
/* 186 */ 9999,
/* 187 */ 9999,
/* 188 */ 9999,
/* 189 */ 123010,
/* 190 */ 9999,
/* 191 */ 9999,
/* 192 */ 9999,
/* 193 */ 124011,
/* 194 */ 9999,
/* 195 */ 128004,
/* 196 */ 128020,
/* 197 */ 9999,
/* 198 */ 128059,
/* 199 */ 9999,
/* 200 */ 9999,
/* 201 */ 128018,
/* 202 */ 9999,
/* 203 */ 129004,
/* 204 */ 129020,
/* 205 */ 9999,
/* 206 */ 129018,
/* 207 */ 9999,
/* 208 */ 128022,
/* 209 */ 9999,
/* 210 */ 128023,
/* 211 */ 9999,
/* 212 */ 9999,
/* 213 */ 128023,
/* 214 */ 9999,
/* 215 */ 133004,
/* 216 */ 9999,
/* 217 */ 133004,
/* 218 */ 9999,
/* 219 */ 9999,
/* 220 */ 9999,
/* 221 */ 133011,
/* 222 */ 9999,
/* 223 */ 9999,
/* 224 */ 9999,
/* 225 */ 133019,
/* 226 */ 9999,
/* 227 */ 137004,
/* 228 */ 137033,
/* 229 */ 9999,
/* 230 */ 137004,
/* 231 */ 9999,
/* 232 */ 137006,
/* 233 */ 9999,
/* 234 */ 137028,
/* 235 */ 9999,
/* 236 */ 9999,
/* 237 */ 137028,
/* 238 */ 9999,
/* 239 */ 141004,
/* 240 */ 141045,
/* 241 */ 9999,
/* 242 */ 141004,
/* 243 */ 9999,
/* 244 */ 141006,
/* 245 */ 9999,
/* 246 */ 9999,
/* 247 */ 141025,
/* 248 */ 9999,
/* 249 */ 9999,
/* 250 */ 141025,
/* 251 */ 9999,
/* 252 */ 145004,
/* 253 */ 145034,
/* 254 */ 9999,
/* 255 */ 145004,
/* 256 */ 9999,
/* 257 */ 145006,
/* 258 */ 9999,
/* 259 */ 9999,
/* 260 */ 145015,
/* 261 */ 9999,
/* 262 */ 9999,
/* 263 */ 145015,
/* 264 */ 9999,
/* 265 */ 149004,
/* 266 */ 149029,
/* 267 */ 9999,
/* 268 */ 9999,
/* 269 */ 149027,
/* 270 */ 9999,
/* 271 */ 153004,
/* 272 */ 153040,
/* 273 */ 9999,
/* 274 */ 153004,
/* 275 */ 9999,
/* 276 */ 153006,
/* 277 */ 9999,
/* 278 */ 153019,
/* 279 */ 9999,
/* 280 */ 153023,
/* 281 */ 9999,
/* 282 */ 153036,
/* 283 */ 9999,
/* 284 */ 153042,
/* 285 */ 9999,
/* 286 */ 153065,
/* 287 */ 9999,
/* 288 */ 9999,
/* 289 */ 153065,
/* 290 */ 9999,
/* 291 */ 157004,
/* 292 */ 157047,
/* 293 */ 9999,
/* 294 */ 157004,
/* 295 */ 9999,
/* 296 */ 157006,
/* 297 */ 9999,
/* 298 */ 9999,
/* 299 */ 157027,
/* 300 */ 9999,
/* 301 */ 9999,
/* 302 */ 157027,
/* 303 */ 9999,
/* 304 */ 161004,
/* 305 */ 9999,
/* 306 */ 161013,
/* 307 */ 9999,
/* 308 */ 162004,
/* 309 */ 9999,
/* 310 */ 162034,
/* 311 */ 9999,
/* 312 */ 162004,
/* 313 */ 9999,
/* 314 */ 162006,
/* 315 */ 9999,
/* 316 */ 162015,
/* 317 */ 9999,
/* 318 */ 9999,
/* 319 */ 162015,
/* 320 */ 9999,
/* 321 */ 9999,
/* 322 */ 166009,
/* 323 */ 9999,
/* 324 */ 166048,
/* 325 */ 9999,
/* 326 */ 9999,
/* 327 */ 166007,
/* 328 */ 9999,
/* 329 */ 9999,
/* 330 */ 167009,
/* 331 */ 9999,
/* 332 */ 167007,
/* 333 */ 9999,
/* 334 */ 166011,
/* 335 */ 9999,
/* 336 */ 166012,
/* 337 */ 9999,
/* 338 */ 9999,
/* 339 */ 166012,
/* 340 */ 9999,
/* 341 */ 171004,
/* 342 */ 171040,
/* 343 */ 9999,
/* 344 */ 171004,
/* 345 */ 9999,
/* 346 */ 171006,
/* 347 */ 9999,
/* 348 */ 9999,
/* 349 */ 171020,
/* 350 */ 9999,
/* 351 */ 9999,
/* 352 */ 171020,
/* 353 */ 9999,
/* 354 */ 175004,
/* 355 */ 175007,
/* 356 */ 9999,
/* 357 */ 175005,
/* 358 */ 9999,
/* 359 */ 9999,
/* 360 */ 175023,
/* 361 */ 9999,
/* 362 */ 175009,
/* 363 */ 9999,
/* 364 */ 9999,
/* 365 */ 175009,
/* 366 */ 9999,
/* 367 */ 179004,
/* 368 */ 179017,
/* 369 */ 9999,
/* 370 */ 179004,
/* 371 */ 9999,
/* 372 */ 179006,
/* 373 */ 9999,
/* 374 */ 179012,
/* 375 */ 9999,
/* 376 */ 9999,
/* 377 */ 179012,
/* 378 */ 9999,
/* 379 */ 183004,
/* 380 */ 9999,
/* 381 */ 183005,
/* 382 */ 9999,
/* 383 */ 9999,
/* 384 */ 184018,
/* 385 */ 9999,
/* 386 */ 9999,
/* 387 */ 184004,
/* 388 */ 9999,
/* 389 */ 185004,
/* 390 */ 185022,
/* 391 */ 9999,
/* 392 */ 185020,
/* 393 */ 9999,
/* 394 */ 9999,
/* 395 */ 185038,
/* 396 */ 9999,
/* 397 */ 9999,
/* 398 */ 185024,
/* 399 */ 9999,
/* 400 */ 9999,
/* 401 */ 185093,
/* 402 */ 9999,
/* 403 */ 9999,
/* 404 */ 185079,
/* 405 */ 9999,
/* 406 */ 9999,
/* 407 */ 185143,
/* 408 */ 9999,
/* 409 */ 9999,
/* 410 */ 185129,
/* 411 */ 9999,
/* 412 */ 185040,
/* 413 */ 9999,
/* 414 */ 185058,
/* 415 */ 9999,
/* 416 */ 9999,
/* 417 */ 185058,
/* 418 */ 9999,
/* 419 */ 185145,
/* 420 */ 9999,
/* 421 */ 185159,
/* 422 */ 9999,
/* 423 */ 9999,
/* 424 */ 185159,
/* 425 */ 9999,
/* 426 */ 9999,
/* 427 */ 189018,
/* 428 */ 189043,
/* 429 */ 9999,
/* 430 */ 189004,
/* 431 */ 9999,
/* 432 */ 189020,
/* 433 */ 9999,
/* 434 */ 189038,
/* 435 */ 9999,
/* 436 */ 9999,
/* 437 */ 189038,
/* 438 */ 9999,
/* 439 */ 189045,
/* 440 */ 9999,
/* 441 */ 189051,
/* 442 */ 9999,
/* 443 */ 9999,
/* 444 */ 189051,
/* 445 */ 9999,
/* 446 */ 193004,
/* 447 */ 193029,
/* 448 */ 9999,
/* 449 */ 193004,
/* 450 */ 9999,
/* 451 */ 193006,
/* 452 */ 9999,
/* 453 */ 193024,
/* 454 */ 9999,
/* 455 */ 9999,
/* 456 */ 193024,
/* 457 */ 9999,
/* 458 */ 197004,
/* 459 */ 197019,
/* 460 */ 9999,
/* 461 */ 197017,
/* 462 */ 9999,
/* 463 */ 9999,
/* 464 */ 9999,
/* 465 */ 9999,
/* 466 */ 197021,
/* 467 */ 9999,
/* 468 */ 9999,
/* 469 */ 197021,
/* 470 */ 9999,
/* 471 */ 201004,
/* 472 */ 201039,
/* 473 */ 9999,
/* 474 */ 201004,
/* 475 */ 9999,
/* 476 */ 201006,
/* 477 */ 9999,
/* 478 */ 9999,
/* 479 */ 201019,
/* 480 */ 9999,
/* 481 */ 9999,
/* 482 */ 201019,
/* 483 */ 9999,
/* 484 */ 205004,
/* 485 */ 205027,
/* 486 */ 9999,
/* 487 */ 205025,
/* 488 */ 9999,
/* 489 */ 205029,
/* 490 */ 9999,
/* 491 */ 205038,
/* 492 */ 9999,
/* 493 */ 205042,
/* 494 */ 9999,
/* 495 */ 205042,
/* 496 */ 9999,
/* 497 */ 205044,
/* 498 */ 9999,
/* 499 */ 205062,
/* 500 */ 9999,
/* 501 */ 9999,
/* 502 */ 205062,
/* 503 */ 9999,
/* 504 */ 209004,
/* 505 */ 209040,
/* 506 */ 9999,
/* 507 */ 209004,
/* 508 */ 9999,
/* 509 */ 209006,
/* 510 */ 9999,
/* 511 */ 9999,
/* 512 */ 209020,
/* 513 */ 9999,
/* 514 */ 9999,
/* 515 */ 209020,
/* 516 */ 9999,
/* 517 */ 213004,
/* 518 */ 9999,
/* 519 */ 213024,
/* 520 */ 9999,
/* 521 */ 9999,
/* 522 */ 214029,
/* 523 */ 214046,
/* 524 */ 9999,
/* 525 */ 9999,
/* 526 */ 214004,
/* 527 */ 9999,
/* 528 */ 9999,
/* 529 */ 9999,
/* 530 */ 214048,
/* 531 */ 9999,
/* 532 */ 9999,
/* 533 */ 214048,
/* 534 */ 9999,
/* 535 */ 218004,
/* 536 */ 218041,
/* 537 */ 9999,
/* 538 */ 218004,
/* 539 */ 9999,
/* 540 */ 218006,
/* 541 */ 9999,
/* 542 */ 9999,
/* 543 */ 218021,
/* 544 */ 9999,
/* 545 */ 9999,
/* 546 */ 218021,
/* 547 */ 9999,
/* 548 */ 222004,
/* 549 */ 222029,
/* 550 */ 9999,
/* 551 */ 222027,
/* 552 */ 9999,
/* 553 */ 222031,
/* 554 */ 9999,
/* 555 */ 222049,
/* 556 */ 9999,
/* 557 */ 9999,
/* 558 */ 222049,
/* 559 */ 9999,
/* 560 */ 226004,
/* 561 */ 9999,
/* 562 */ 226010,
/* 563 */ 9999,
/* 564 */ 227004,
/* 565 */ 227017,
/* 566 */ 9999,
/* 567 */ 227004,
/* 568 */ 9999,
/* 569 */ 227006,
/* 570 */ 9999,
/* 571 */ 227012,
/* 572 */ 9999,
/* 573 */ 9999,
/* 574 */ 227012,
/* 575 */ 9999,
/* 576 */ 9999,
/* 577 */ 231018,
/* 578 */ 9999,
/* 579 */ 9999,
/* 580 */ 231004,
/* 581 */ 9999,
/* 582 */ 232004,
/* 583 */ 232036,
/* 584 */ 9999,
/* 585 */ 232004,
/* 586 */ 9999,
/* 587 */ 232006,
/* 588 */ 9999,
/* 589 */ 232031,
/* 590 */ 9999,
/* 591 */ 9999,
/* 592 */ 232031,
/* 593 */ 9999,
/* 594 */ 9999,
/* 595 */ 232052,
/* 596 */ 9999,
/* 597 */ 9999,
/* 598 */ 232038,
/* 599 */ 9999,
/* 600 */ 9999,
/* 601 */ 232107,
/* 602 */ 9999,
/* 603 */ 9999,
/* 604 */ 232093,
/* 605 */ 9999,
/* 606 */ 232054,
/* 607 */ 9999,
/* 608 */ 232072,
/* 609 */ 9999,
/* 610 */ 9999,
/* 611 */ 232072,
/* 612 */ 9999,
/* 613 */ 232109,
/* 614 */ 9999,
/* 615 */ 232127,
/* 616 */ 9999,
/* 617 */ 9999,
/* 618 */ 232127,
/* 619 */ 9999,
/* 620 */ 236004,
/* 621 */ 9999,
/* 622 */ 236005,
/* 623 */ 9999,
/* 624 */ 240004,
/* 625 */ 9999,
/* 626 */ 240020,
/* 627 */ 9999,
/* 628 */ 241004,
/* 629 */ 9999,
/* 630 */ 241023,
/* 631 */ 9999,
/* 632 */ 242004,
/* 633 */ 9999,
/* 634 */ 242021,
/* 635 */ 9999,
/* 636 */ 243004,
/* 637 */ 9999,
/* 638 */ 243022,
/* 639 */ 9999,
/* 640 */ 244004,
/* 641 */ 9999,
/* 642 */ 244022,
/* 643 */ 9999,
/* 644 */ 245004,
/* 645 */ 9999,
/* 646 */ 245017,
/* 647 */ 9999,
/* 648 */ 249004,
/* 649 */ 9999,
/* 650 */ 249021,
/* 651 */ 9999,
/* 652 */ 249005,
/* 653 */ 9999,
/* 654 */ 9999,
/* 655 */ 250019,
/* 656 */ 9999,
/* 657 */ 250053,
/* 658 */ 9999,
/* 659 */ 250007,
/* 660 */ 9999,
/* 661 */ 9999,
/* 662 */ 9999,
/* 663 */ 251036,
/* 664 */ 9999,
/* 665 */ 251010,
/* 666 */ 9999,
/* 667 */ 255004,
/* 668 */ 9999,
/* 669 */ 9999,
/* 670 */ 255004,
/* 671 */ 9999,
/* 672 */ 255006,
/* 673 */ 9999,
/* 674 */ 255015,
/* 675 */ 9999,
/* 676 */ 9999,
/* 677 */ 255015,
/* 678 */ 9999,
/* 679 */ 9999,
/* 680 */ 259035,
/* 681 */ 259057,
/* 682 */ 9999,
/* 683 */ 9999,
/* 684 */ 259004,
/* 685 */ 9999,
/* 686 */ 259037,
/* 687 */ 9999,
/* 688 */ 259052,
/* 689 */ 9999,
/* 690 */ 9999,
/* 691 */ 259052,
/* 692 */ 9999,
/* 693 */ 259059,
/* 694 */ 9999,
/* 695 */ 259072,
/* 696 */ 9999,
/* 697 */ 9999,
/* 698 */ 259072,
/* 699 */ 9999,
/* 700 */ 263004,
/* 701 */ 263024,
/* 702 */ 9999,
/* 703 */ 263004,
/* 704 */ 9999,
/* 705 */ 263006,
/* 706 */ 9999,
/* 707 */ 263019,
/* 708 */ 9999,
/* 709 */ 9999,
/* 710 */ 263019,
/* 711 */ 9999,
/* 712 */ 9999,
/* 713 */ 9999,
/* 714 */ 267031,
/* 715 */ 9999,
/* 716 */ 267056,
/* 717 */ 267066,
/* 718 */ 9999,
/* 719 */ 267005,
/* 720 */ 9999,
/* 721 */ 9999,
/* 722 */ 9999,
/* 723 */ 268035,
/* 724 */ 9999,
/* 725 */ 268060,
/* 726 */ 9999,
/* 727 */ 268009,
/* 728 */ 9999,
/* 729 */ 9999,
/* 730 */ 267083,
/* 731 */ 9999,
/* 732 */ 267071,
/* 733 */ 9999,
/* 734 */ 9999,
/* 735 */ 267071,
/* 736 */ 9999,
/* 737 */ 9999,
/* 738 */ 9999,
/* 739 */ 272034,
/* 740 */ 9999,
/* 741 */ 272059,
/* 742 */ 9999,
/* 743 */ 272008,
/* 744 */ 9999,
/* 745 */ 9999,
/* 746 */ 273017,
/* 747 */ 9999,
/* 748 */ 9999,
/* 749 */ 273057,
/* 750 */ 9999,
/* 751 */ 9999,
/* 752 */ 9999,
/* 753 */ 273005,
/* 754 */ 9999,
/* 755 */ 9999,
/* 756 */ 9999,
/* 757 */ 274032,
/* 758 */ 9999,
/* 759 */ 274062,
/* 760 */ 9999,
/* 761 */ 274092,
/* 762 */ 9999,
/* 763 */ 274122,
/* 764 */ 9999,
/* 765 */ 274006,
/* 766 */ 9999,
/* 767 */ 274034,
/* 768 */ 9999,
/* 769 */ 274043,
/* 770 */ 9999,
/* 771 */ 9999,
/* 772 */ 274043,
/* 773 */ 9999,
/* 774 */ 274064,
/* 775 */ 9999,
/* 776 */ 274073,
/* 777 */ 9999,
/* 778 */ 9999,
/* 779 */ 274073,
/* 780 */ 9999,
/* 781 */ 274094,
/* 782 */ 9999,
/* 783 */ 274103,
/* 784 */ 9999,
/* 785 */ 9999,
/* 786 */ 274103,
/* 787 */ 9999,
/* 788 */ 9999,
/* 789 */ 278019,
/* 790 */ 9999,
/* 791 */ 9999,
/* 792 */ 278007,
/* 793 */ 9999,
/* 794 */ 9999,
/* 795 */ 9999,
/* 796 */ 9999,
/* 797 */ 279011,
/* 798 */ 9999,
/* 799 */ 9999,
/* 800 */ 9999,
/* 801 */ 9999,
/* 802 */ 280008,
/* 803 */ 9999,
/* 804 */ 9999,
/* 805 */ 281021,
/* 806 */ 9999,
/* 807 */ 9999,
/* 808 */ 281009,
/* 809 */ 9999,
/* 810 */ 281023,
/* 811 */ 9999,
/* 812 */ 281032,
/* 813 */ 9999,
/* 814 */ 9999,
/* 815 */ 281032,
/* 816 */ 9999,
/* 817 */ 285004,
/* 818 */ 285035,
/* 819 */ 9999,
/* 820 */ 285004,
/* 821 */ 9999,
/* 822 */ 285006,
/* 823 */ 9999,
/* 824 */ 9999,
/* 825 */ 285015,
/* 826 */ 9999,
/* 827 */ 9999,
/* 828 */ 285015,
/* 829 */ 9999,
/* 830 */ 289004,
/* 831 */ 9999,
/* 832 */ 289025,
/* 833 */ 9999,
/* 834 */ 290004,
/* 835 */ 290021,
/* 836 */ 290041,
/* 837 */ 9999,
/* 838 */ 290019,
/* 839 */ 9999,
/* 840 */ 294004,
/* 841 */ 9999,
/* 842 */ 294004,
/* 843 */ 9999,
/* 844 */ 9999,
/* 845 */ 9999,
/* 846 */ 294011,
/* 847 */ 9999,
/* 848 */ 9999,
/* 849 */ 9999,
/* 850 */ 295004,
/* 851 */ 9999,
/* 852 */ 299004,
/* 853 */ 299026,
/* 854 */ 9999,
/* 855 */ 299024,
/* 856 */ 9999,
/* 857 */ 9999,
/* 858 */ 299042,
/* 859 */ 9999,
/* 860 */ 299067,
/* 861 */ 9999,
/* 862 */ 299028,
/* 863 */ 9999,
/* 864 */ 9999,
/* 865 */ 299028,
/* 866 */ 9999,
/* 867 */ 303004,
/* 868 */ 9999,
/* 869 */ 303025,
/* 870 */ 9999,
/* 871 */ 307004,
/* 872 */ 307042,
/* 873 */ 9999,
/* 874 */ 307004,
/* 875 */ 9999,
/* 876 */ 307006,
/* 877 */ 9999,
/* 878 */ 9999,
/* 879 */ 307026,
/* 880 */ 9999,
/* 881 */ 9999,
/* 882 */ 307026,
/* 883 */ 9999,
/* 884 */ 311004,
/* 885 */ 311044,
/* 886 */ 9999,
/* 887 */ 311004,
/* 888 */ 9999,
/* 889 */ 311006,
/* 890 */ 9999,
/* 891 */ 9999,
/* 892 */ 311027,
/* 893 */ 9999,
/* 894 */ 9999,
/* 895 */ 311027,
/* 896 */ 9999,
/* 897 */ 315004,
/* 898 */ 315040,
/* 899 */ 9999,
/* 900 */ 315004,
/* 901 */ 9999,
/* 902 */ 315006,
/* 903 */ 9999,
/* 904 */ 9999,
/* 905 */ 315028,
/* 906 */ 9999,
/* 907 */ 9999,
/* 908 */ 315028,
/* 909 */ 9999,
/* 910 */ 319004,
/* 911 */ 319041,
/* 912 */ 9999,
/* 913 */ 319004,
/* 914 */ 9999,
/* 915 */ 319006,
/* 916 */ 9999,
/* 917 */ 9999,
/* 918 */ 319028,
/* 919 */ 9999,
/* 920 */ 9999,
/* 921 */ 319028,
/* 922 */ 9999,
/* 923 */ 323004,
/* 924 */ 323031,
/* 925 */ 9999,
/* 926 */ 323004,
/* 927 */ 9999,
/* 928 */ 323005,
/* 929 */ 9999,
/* 930 */ 9999,
/* 931 */ 323018,
/* 932 */ 9999,
/* 933 */ 9999,
/* 934 */ 323018,
/* 935 */ 9999,
/* 936 */ 327004,
/* 937 */ 327075,
/* 938 */ 9999,
/* 939 */ 327004,
/* 940 */ 9999,
/* 941 */ 327006,
/* 942 */ 9999,
/* 943 */ 9999,
/* 944 */ 327024,
/* 945 */ 9999,
/* 946 */ 9999,
/* 947 */ 327024,
/* 948 */ 9999,
/* 949 */ 331004,
/* 950 */ 331031,
/* 951 */ 9999,
/* 952 */ 331004,
/* 953 */ 9999,
/* 954 */ 331005,
/* 955 */ 9999,
/* 956 */ 9999,
/* 957 */ 331020,
/* 958 */ 9999,
/* 959 */ 9999,
/* 960 */ 331020,
/* 961 */ 9999,
/* 962 */ 335004,
/* 963 */ 335053,
/* 964 */ 9999,
/* 965 */ 335004,
/* 966 */ 9999,
/* 967 */ 335006,
/* 968 */ 335026,
/* 969 */ 9999,
/* 970 */ 335024,
/* 971 */ 9999,
/* 972 */ 9999,
/* 973 */ 335024,
/* 974 */ 9999,
/* 975 */ 9999,
/* 976 */ 9999,
/* 977 */ 335028,
/* 978 */ 9999,
/* 979 */ 9999,
/* 980 */ 9999,
/* 981 */ 335034,
/* 982 */ 9999,
/* 983 */ 339004,
/* 984 */ 339065,
/* 985 */ 9999,
/* 986 */ 339004,
/* 987 */ 9999,
/* 988 */ 339006,
/* 989 */ 339032,
/* 990 */ 9999,
/* 991 */ 339030,
/* 992 */ 9999,
/* 993 */ 9999,
/* 994 */ 339030,
/* 995 */ 9999,
/* 996 */ 9999,
/* 997 */ 9999,
/* 998 */ 339034,
/* 999 */ 9999,
/* 1000 */ 9999,
/* 1001 */ 9999,
/* 1002 */ 339040,
/* 1003 */ 9999,
/* 1004 */ 9999,
/* 1005 */ 9999,
/* 1006 */ 339046,
/* 1007 */ 9999,
/* 1008 */ 343004,
/* 1009 */ 9999,
/* 1010 */ 343019,
/* 1011 */ 9999,
/* 1012 */ 9999,
/* 1013 */ 344018,
/* 1014 */ 9999,
/* 1015 */ 344042,
/* 1016 */ 9999,
/* 1017 */ 344004,
/* 1018 */ 9999,
/* 1019 */ 348004,
/* 1020 */ 9999,
/* 1021 */ 348021,
/* 1022 */ 9999,
/* 1023 */ 349004,
/* 1024 */ 349024,
/* 1025 */ 9999,
/* 1026 */ 349004,
/* 1027 */ 9999,
/* 1028 */ 350004,
/* 1029 */ 350019,
/* 1030 */ 9999,
/* 1031 */ 350017,
/* 1032 */ 9999,
/* 1033 */ 9999,
/* 1034 */ 351011,
/* 1035 */ 9999,
/* 1036 */ 351009,
/* 1037 */ 9999,
/* 1038 */ 9999,
/* 1039 */ 9999,
/* 1040 */ 352025,
/* 1041 */ 9999,
/* 1042 */ 9999,
/* 1043 */ 352009,
/* 1044 */ 9999,
/* 1045 */ 9999,
/* 1046 */ 9999,
/* 1047 */ 349011,
/* 1048 */ 9999,
/* 1049 */ 9999,
/* 1050 */ 9999,
/* 1051 */ 349020,
/* 1052 */ 9999,
/* 1053 */ 356004,
/* 1054 */ 9999,
/* 1055 */ 356004,
/* 1056 */ 9999,
/* 1057 */ 9999,
/* 1058 */ 9999,
/* 1059 */ 356011,
/* 1060 */ 9999,
/* 1061 */ 9999,
/* 1062 */ 9999,
/* 1063 */ 356015,
/* 1064 */ 9999,
/* 1065 */ 9999,
/* 1066 */ 9999,
/* 1067 */ 356021,
/* 1068 */ 9999,
/* 1069 */ 9999,
/* 1070 */ 9999,
/* 1071 */ 356027,
/* 1072 */ 9999,
/* 1073 */ 9999,
/* 1074 */ 9999,
/* 1075 */ 356033,
/* 1076 */ 9999,
/* 1077 */ 9999,
/* 1078 */ 9999,
/* 1079 */ 356039,
/* 1080 */ 9999,
/* 1081 */ 360004,
/* 1082 */ 9999,
/* 1083 */ 360021,
/* 1084 */ 9999,
/* 1085 */ 361004,
/* 1086 */ 361023,
/* 1087 */ 9999,
/* 1088 */ 361021,
/* 1089 */ 9999,
/* 1090 */ 9999,
/* 1091 */ 361039,
/* 1092 */ 9999,
/* 1093 */ 9999,
/* 1094 */ 361025,
/* 1095 */ 9999,
/* 1096 */ 9999,
/* 1097 */ 361080,
/* 1098 */ 9999,
/* 1099 */ 9999,
/* 1100 */ 361066,
/* 1101 */ 9999,
/* 1102 */ 9999,
/* 1103 */ 361140,
/* 1104 */ 9999,
/* 1105 */ 361126,
/* 1106 */ 9999,
/* 1107 */ 9999,
/* 1108 */ 361172,
/* 1109 */ 9999,
/* 1110 */ 361150,
/* 1111 */ 9999,
/* 1112 */ 9999,
/* 1113 */ 9999,
/* 1114 */ 361182,
/* 1115 */ 9999,
/* 1116 */ 9999,
/* 1117 */ 9999,
/* 1118 */ 361211,
/* 1119 */ 9999,
/* 1120 */ 361082,
/* 1121 */ 9999,
/* 1122 */ 361105,
/* 1123 */ 9999,
/* 1124 */ 9999,
/* 1125 */ 361105,
/* 1126 */ 9999,
/* 1127 */ 365004,
/* 1128 */ 9999,
/* 1129 */ 365005,
/* 1130 */ 9999,
/* 1131 */ 366004,
/* 1132 */ 9999,
/* 1133 */ 366011,
/* 1134 */ 9999,
/* 1135 */ 9999,
/* 1136 */ 9999,
/* 1137 */ 367009,
/* 1138 */ 9999,
/* 1139 */ 9999,
/* 1140 */ 368018,
/* 1141 */ 9999,
/* 1142 */ 9999,
/* 1143 */ 368004,
/* 1144 */ 9999,
/* 1145 */ 372004,
/* 1146 */ 372049,
/* 1147 */ 9999,
/* 1148 */ 372004,
/* 1149 */ 9999,
/* 1150 */ 372006,
/* 1151 */ 9999,
/* 1152 */ 9999,
/* 1153 */ 372029,
/* 1154 */ 9999,
/* 1155 */ 9999,
/* 1156 */ 372029,
/* 1157 */ 9999,
/* 1158 */ 9999,
/* 1159 */ 9999,
/* 1160 */ 376011,
/* 1161 */ 9999,
/* 1162 */ 9999,
/* 1163 */ 9999,
/* 1164 */ 377012,
/* 1165 */ 9999,
/* 1166 */ 9999,
/* 1167 */ 9999,
/* 1168 */ 378013,
/* 1169 */ 9999,
/* 1170 */ 379004,
/* 1171 */ 9999,
/* 1172 */ 379005,
/* 1173 */ 9999,
/* 1174 */ 9999,
/* 1175 */ 9999,
/* 1176 */ 383013,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[1178];
*/
int TABLE[268][309];
init_dirsets() {
TABLE[105][0] = 1;
TABLE[105][35] = 1;
TABLE[105][123] = 1;
TABLE[105][40] = 1;
TABLE[105][42] = 1;
TABLE[105][299] = 1;
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
TABLE[2][35] = 1;
TABLE[106][0] = 1;
TABLE[106][123] = 1;
TABLE[106][40] = 1;
TABLE[106][42] = 1;
TABLE[106][299] = 1;
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
TABLE[213][0] = 1;
TABLE[3][35] = 1;
TABLE[107][289] = 1;
TABLE[4][0] = 1;
TABLE[4][123] = 1;
TABLE[4][40] = 1;
TABLE[4][299] = 1;
TABLE[4][42] = 1;
TABLE[4][286] = 1;
TABLE[4][260] = 1;
TABLE[4][284] = 1;
TABLE[4][277] = 1;
TABLE[4][264] = 1;
TABLE[4][268] = 1;
TABLE[4][273] = 1;
TABLE[4][272] = 1;
TABLE[4][276] = 1;
TABLE[4][259] = 1;
TABLE[4][285] = 1;
TABLE[4][266] = 1;
TABLE[4][282] = 1;
TABLE[4][267] = 1;
TABLE[4][279] = 1;
TABLE[4][274] = 1;
TABLE[4][256] = 1;
TABLE[4][283] = 1;
TABLE[4][280] = 1;
TABLE[5][256] = 1;
TABLE[5][274] = 1;
TABLE[5][279] = 1;
TABLE[5][267] = 1;
TABLE[5][282] = 1;
TABLE[5][266] = 1;
TABLE[5][285] = 1;
TABLE[5][259] = 1;
TABLE[5][276] = 1;
TABLE[5][272] = 1;
TABLE[5][273] = 1;
TABLE[5][268] = 1;
TABLE[5][264] = 1;
TABLE[5][277] = 1;
TABLE[5][284] = 1;
TABLE[5][260] = 1;
TABLE[5][286] = 1;
TABLE[5][280] = 1;
TABLE[5][283] = 1;
TABLE[6][123] = 1;
TABLE[6][40] = 1;
TABLE[6][42] = 1;
TABLE[6][299] = 1;
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
TABLE[214][40] = 1;
TABLE[214][42] = 1;
TABLE[214][299] = 1;
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
TABLE[214][123] = 1;
TABLE[109][123] = 1;
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
TABLE[109][283] = 1;
TABLE[109][280] = 1;
TABLE[215][123] = 1;
TABLE[7][286] = 1;
TABLE[7][260] = 1;
TABLE[7][284] = 1;
TABLE[7][277] = 1;
TABLE[7][264] = 1;
TABLE[7][268] = 1;
TABLE[7][273] = 1;
TABLE[7][272] = 1;
TABLE[7][276] = 1;
TABLE[7][259] = 1;
TABLE[7][285] = 1;
TABLE[7][266] = 1;
TABLE[7][282] = 1;
TABLE[7][267] = 1;
TABLE[7][279] = 1;
TABLE[7][274] = 1;
TABLE[7][256] = 1;
TABLE[7][283] = 1;
TABLE[7][280] = 1;
TABLE[110][59] = 1;
TABLE[110][44] = 1;
TABLE[110][123] = 1;
TABLE[110][61] = 1;
TABLE[110][278] = 1;
TABLE[110][40] = 1;
TABLE[110][295] = 1;
TABLE[110][294] = 1;
TABLE[110][63] = 1;
TABLE[110][299] = 1;
TABLE[110][42] = 1;
TABLE[110][289] = 1;
TABLE[110][302] = 1;
TABLE[110][43] = 1;
TABLE[110][45] = 1;
TABLE[110][126] = 1;
TABLE[110][33] = 1;
TABLE[110][297] = 1;
TABLE[110][307] = 1;
TABLE[110][306] = 1;
TABLE[110][308] = 1;
TABLE[110][298] = 1;
TABLE[110][301] = 1;
TABLE[110][303] = 1;
TABLE[110][292] = 1;
TABLE[110][304] = 1;
TABLE[110][37] = 1;
TABLE[110][47] = 1;
TABLE[216][59] = 1;
TABLE[8][256] = 1;
TABLE[8][274] = 1;
TABLE[8][279] = 1;
TABLE[8][267] = 1;
TABLE[8][282] = 1;
TABLE[8][266] = 1;
TABLE[8][285] = 1;
TABLE[8][259] = 1;
TABLE[8][276] = 1;
TABLE[8][272] = 1;
TABLE[8][273] = 1;
TABLE[8][268] = 1;
TABLE[8][264] = 1;
TABLE[8][277] = 1;
TABLE[8][284] = 1;
TABLE[8][260] = 1;
TABLE[8][286] = 1;
TABLE[8][280] = 1;
TABLE[8][283] = 1;
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
TABLE[111][282] = 1;
TABLE[111][267] = 1;
TABLE[111][279] = 1;
TABLE[111][274] = 1;
TABLE[111][256] = 1;
TABLE[111][283] = 1;
TABLE[111][280] = 1;
TABLE[217][256] = 1;
TABLE[217][274] = 1;
TABLE[217][279] = 1;
TABLE[217][267] = 1;
TABLE[217][282] = 1;
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
TABLE[9][256] = 1;
TABLE[9][274] = 1;
TABLE[9][279] = 1;
TABLE[9][267] = 1;
TABLE[9][282] = 1;
TABLE[9][266] = 1;
TABLE[9][285] = 1;
TABLE[9][259] = 1;
TABLE[9][276] = 1;
TABLE[9][272] = 1;
TABLE[9][273] = 1;
TABLE[9][268] = 1;
TABLE[9][264] = 1;
TABLE[9][277] = 1;
TABLE[9][284] = 1;
TABLE[9][260] = 1;
TABLE[9][286] = 1;
TABLE[9][280] = 1;
TABLE[9][283] = 1;
TABLE[112][282] = 1;
TABLE[112][267] = 1;
TABLE[112][279] = 1;
TABLE[112][274] = 1;
TABLE[112][256] = 1;
TABLE[113][284] = 1;
TABLE[113][277] = 1;
TABLE[113][264] = 1;
TABLE[113][268] = 1;
TABLE[113][273] = 1;
TABLE[113][272] = 1;
TABLE[113][276] = 1;
TABLE[113][259] = 1;
TABLE[113][285] = 1;
TABLE[113][266] = 1;
TABLE[113][283] = 1;
TABLE[113][280] = 1;
TABLE[114][286] = 1;
TABLE[114][260] = 1;
TABLE[115][286] = 1;
TABLE[115][260] = 1;
TABLE[115][284] = 1;
TABLE[115][277] = 1;
TABLE[115][264] = 1;
TABLE[115][268] = 1;
TABLE[115][273] = 1;
TABLE[115][272] = 1;
TABLE[115][276] = 1;
TABLE[115][259] = 1;
TABLE[115][285] = 1;
TABLE[115][266] = 1;
TABLE[115][282] = 1;
TABLE[115][267] = 1;
TABLE[115][279] = 1;
TABLE[115][274] = 1;
TABLE[115][256] = 1;
TABLE[115][283] = 1;
TABLE[115][280] = 1;
TABLE[218][40] = 1;
TABLE[218][42] = 1;
TABLE[218][299] = 1;
TABLE[218][256] = 1;
TABLE[218][274] = 1;
TABLE[218][279] = 1;
TABLE[218][267] = 1;
TABLE[218][282] = 1;
TABLE[218][266] = 1;
TABLE[218][285] = 1;
TABLE[218][259] = 1;
TABLE[218][276] = 1;
TABLE[218][272] = 1;
TABLE[218][273] = 1;
TABLE[218][268] = 1;
TABLE[218][264] = 1;
TABLE[218][277] = 1;
TABLE[218][284] = 1;
TABLE[218][260] = 1;
TABLE[218][286] = 1;
TABLE[218][280] = 1;
TABLE[218][283] = 1;
TABLE[218][123] = 1;
TABLE[218][44] = 1;
TABLE[218][61] = 1;
TABLE[218][278] = 1;
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
TABLE[218][91] = 1;
TABLE[218][41] = 1;
TABLE[10][256] = 1;
TABLE[10][274] = 1;
TABLE[10][279] = 1;
TABLE[10][267] = 1;
TABLE[10][282] = 1;
TABLE[116][256] = 1;
TABLE[117][274] = 1;
TABLE[118][279] = 1;
TABLE[119][267] = 1;
TABLE[120][282] = 1;
TABLE[11][285] = 1;
TABLE[11][259] = 1;
TABLE[11][276] = 1;
TABLE[11][272] = 1;
TABLE[11][273] = 1;
TABLE[11][268] = 1;
TABLE[11][264] = 1;
TABLE[11][277] = 1;
TABLE[11][284] = 1;
TABLE[12][280] = 1;
TABLE[12][283] = 1;
TABLE[13][266] = 1;
TABLE[121][285] = 1;
TABLE[122][259] = 1;
TABLE[123][276] = 1;
TABLE[124][272] = 1;
TABLE[125][273] = 1;
TABLE[126][268] = 1;
TABLE[127][264] = 1;
TABLE[128][277] = 1;
TABLE[129][284] = 1;
TABLE[14][260] = 1;
TABLE[14][286] = 1;
TABLE[130][260] = 1;
TABLE[131][286] = 1;
TABLE[15][283] = 1;
TABLE[15][280] = 1;
TABLE[16][283] = 1;
TABLE[16][280] = 1;
TABLE[132][299] = 1;
TABLE[219][123] = 1;
TABLE[17][280] = 1;
TABLE[17][283] = 1;
TABLE[133][280] = 1;
TABLE[134][283] = 1;
TABLE[18][266] = 1;
TABLE[18][285] = 1;
TABLE[18][259] = 1;
TABLE[18][276] = 1;
TABLE[18][272] = 1;
TABLE[18][273] = 1;
TABLE[18][268] = 1;
TABLE[18][264] = 1;
TABLE[18][277] = 1;
TABLE[18][284] = 1;
TABLE[18][260] = 1;
TABLE[18][286] = 1;
TABLE[18][280] = 1;
TABLE[18][283] = 1;
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
TABLE[135][283] = 1;
TABLE[135][280] = 1;
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
TABLE[220][280] = 1;
TABLE[220][283] = 1;
TABLE[19][59] = 1;
TABLE[19][44] = 1;
TABLE[19][61] = 1;
TABLE[19][123] = 1;
TABLE[19][40] = 1;
TABLE[19][278] = 1;
TABLE[19][42] = 1;
TABLE[19][299] = 1;
TABLE[19][63] = 1;
TABLE[19][294] = 1;
TABLE[19][295] = 1;
TABLE[19][297] = 1;
TABLE[19][33] = 1;
TABLE[19][126] = 1;
TABLE[19][45] = 1;
TABLE[19][43] = 1;
TABLE[19][302] = 1;
TABLE[19][289] = 1;
TABLE[19][298] = 1;
TABLE[19][308] = 1;
TABLE[19][306] = 1;
TABLE[19][307] = 1;
TABLE[19][301] = 1;
TABLE[19][303] = 1;
TABLE[19][292] = 1;
TABLE[19][304] = 1;
TABLE[19][47] = 1;
TABLE[19][37] = 1;
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
TABLE[136][297] = 1;
TABLE[136][307] = 1;
TABLE[136][306] = 1;
TABLE[136][308] = 1;
TABLE[136][298] = 1;
TABLE[136][301] = 1;
TABLE[136][303] = 1;
TABLE[136][292] = 1;
TABLE[136][304] = 1;
TABLE[136][37] = 1;
TABLE[136][47] = 1;
TABLE[221][61] = 1;
TABLE[221][123] = 1;
TABLE[221][40] = 1;
TABLE[221][278] = 1;
TABLE[221][42] = 1;
TABLE[221][299] = 1;
TABLE[221][63] = 1;
TABLE[221][294] = 1;
TABLE[221][295] = 1;
TABLE[221][297] = 1;
TABLE[221][33] = 1;
TABLE[221][126] = 1;
TABLE[221][45] = 1;
TABLE[221][43] = 1;
TABLE[221][302] = 1;
TABLE[221][289] = 1;
TABLE[221][298] = 1;
TABLE[221][308] = 1;
TABLE[221][306] = 1;
TABLE[221][307] = 1;
TABLE[221][301] = 1;
TABLE[221][303] = 1;
TABLE[221][292] = 1;
TABLE[221][304] = 1;
TABLE[221][47] = 1;
TABLE[221][37] = 1;
TABLE[221][59] = 1;
TABLE[221][44] = 1;
TABLE[20][59] = 1;
TABLE[20][44] = 1;
TABLE[20][123] = 1;
TABLE[20][278] = 1;
TABLE[20][295] = 1;
TABLE[20][294] = 1;
TABLE[20][63] = 1;
TABLE[20][289] = 1;
TABLE[20][302] = 1;
TABLE[20][43] = 1;
TABLE[20][45] = 1;
TABLE[20][126] = 1;
TABLE[20][33] = 1;
TABLE[20][297] = 1;
TABLE[20][307] = 1;
TABLE[20][306] = 1;
TABLE[20][308] = 1;
TABLE[20][298] = 1;
TABLE[20][301] = 1;
TABLE[20][303] = 1;
TABLE[20][292] = 1;
TABLE[20][304] = 1;
TABLE[20][37] = 1;
TABLE[20][47] = 1;
TABLE[20][61] = 1;
TABLE[20][40] = 1;
TABLE[20][299] = 1;
TABLE[20][42] = 1;
TABLE[137][61] = 1;
TABLE[137][40] = 1;
TABLE[137][42] = 1;
TABLE[137][299] = 1;
TABLE[222][123] = 1;
TABLE[222][278] = 1;
TABLE[222][295] = 1;
TABLE[222][294] = 1;
TABLE[222][63] = 1;
TABLE[222][289] = 1;
TABLE[222][40] = 1;
TABLE[222][302] = 1;
TABLE[222][42] = 1;
TABLE[222][43] = 1;
TABLE[222][45] = 1;
TABLE[222][126] = 1;
TABLE[222][33] = 1;
TABLE[222][297] = 1;
TABLE[222][299] = 1;
TABLE[222][307] = 1;
TABLE[222][306] = 1;
TABLE[222][308] = 1;
TABLE[222][298] = 1;
TABLE[222][301] = 1;
TABLE[222][303] = 1;
TABLE[222][292] = 1;
TABLE[222][304] = 1;
TABLE[222][37] = 1;
TABLE[222][47] = 1;
TABLE[222][59] = 1;
TABLE[222][44] = 1;
TABLE[21][286] = 1;
TABLE[21][260] = 1;
TABLE[21][284] = 1;
TABLE[21][277] = 1;
TABLE[21][264] = 1;
TABLE[21][268] = 1;
TABLE[21][273] = 1;
TABLE[21][272] = 1;
TABLE[21][276] = 1;
TABLE[21][259] = 1;
TABLE[21][285] = 1;
TABLE[21][266] = 1;
TABLE[21][283] = 1;
TABLE[21][280] = 1;
TABLE[22][266] = 1;
TABLE[22][285] = 1;
TABLE[22][259] = 1;
TABLE[22][276] = 1;
TABLE[22][272] = 1;
TABLE[22][273] = 1;
TABLE[22][268] = 1;
TABLE[22][264] = 1;
TABLE[22][277] = 1;
TABLE[22][284] = 1;
TABLE[22][260] = 1;
TABLE[22][286] = 1;
TABLE[22][280] = 1;
TABLE[22][283] = 1;
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
TABLE[140][283] = 1;
TABLE[140][280] = 1;
TABLE[223][44] = 1;
TABLE[223][58] = 1;
TABLE[223][40] = 1;
TABLE[223][42] = 1;
TABLE[223][299] = 1;
TABLE[223][59] = 1;
TABLE[223][91] = 1;
TABLE[223][41] = 1;
TABLE[23][59] = 1;
TABLE[23][44] = 1;
TABLE[23][58] = 1;
TABLE[23][40] = 1;
TABLE[23][299] = 1;
TABLE[23][42] = 1;
TABLE[141][44] = 1;
TABLE[141][58] = 1;
TABLE[141][40] = 1;
TABLE[141][42] = 1;
TABLE[141][299] = 1;
TABLE[224][58] = 1;
TABLE[224][40] = 1;
TABLE[224][299] = 1;
TABLE[224][42] = 1;
TABLE[224][59] = 1;
TABLE[224][44] = 1;
TABLE[24][59] = 1;
TABLE[24][44] = 1;
TABLE[24][40] = 1;
TABLE[24][42] = 1;
TABLE[24][299] = 1;
TABLE[25][58] = 1;
TABLE[25][40] = 1;
TABLE[25][299] = 1;
TABLE[25][42] = 1;
TABLE[142][58] = 1;
TABLE[142][40] = 1;
TABLE[142][42] = 1;
TABLE[142][299] = 1;
TABLE[225][58] = 1;
TABLE[26][266] = 1;
TABLE[27][266] = 1;
TABLE[143][299] = 1;
TABLE[226][123] = 1;
TABLE[28][44] = 1;
TABLE[28][299] = 1;
TABLE[144][44] = 1;
TABLE[144][299] = 1;
TABLE[227][299] = 1;
TABLE[29][299] = 1;
TABLE[145][61] = 1;
TABLE[228][125] = 1;
TABLE[228][44] = 1;
TABLE[30][40] = 1;
TABLE[30][299] = 1;
TABLE[30][42] = 1;
TABLE[146][42] = 1;
TABLE[229][40] = 1;
TABLE[229][299] = 1;
TABLE[31][299] = 1;
TABLE[32][40] = 1;
TABLE[33][40] = 1;
TABLE[33][299] = 1;
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
TABLE[147][299] = 1;
TABLE[147][307] = 1;
TABLE[147][306] = 1;
TABLE[147][308] = 1;
TABLE[230][93] = 1;
TABLE[150][41] = 1;
TABLE[150][44] = 1;
TABLE[150][299] = 1;
TABLE[231][41] = 1;
TABLE[34][42] = 1;
TABLE[152][42] = 1;
TABLE[152][40] = 1;
TABLE[152][299] = 1;
TABLE[152][44] = 1;
TABLE[152][41] = 1;
TABLE[152][91] = 1;
TABLE[152][260] = 1;
TABLE[152][286] = 1;
TABLE[232][42] = 1;
TABLE[232][40] = 1;
TABLE[232][299] = 1;
TABLE[232][44] = 1;
TABLE[232][41] = 1;
TABLE[232][91] = 1;
TABLE[153][42] = 1;
TABLE[233][40] = 1;
TABLE[233][299] = 1;
TABLE[233][44] = 1;
TABLE[233][41] = 1;
TABLE[233][91] = 1;
TABLE[35][286] = 1;
TABLE[35][260] = 1;
TABLE[154][260] = 1;
TABLE[154][286] = 1;
TABLE[234][286] = 1;
TABLE[234][260] = 1;
TABLE[36][41] = 1;
TABLE[36][44] = 1;
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
TABLE[155][44] = 1;
TABLE[235][41] = 1;
TABLE[37][44] = 1;
TABLE[37][256] = 1;
TABLE[37][274] = 1;
TABLE[37][279] = 1;
TABLE[37][267] = 1;
TABLE[37][282] = 1;
TABLE[37][266] = 1;
TABLE[37][285] = 1;
TABLE[37][259] = 1;
TABLE[37][276] = 1;
TABLE[37][272] = 1;
TABLE[37][273] = 1;
TABLE[37][268] = 1;
TABLE[37][264] = 1;
TABLE[37][277] = 1;
TABLE[37][284] = 1;
TABLE[37][260] = 1;
TABLE[37][286] = 1;
TABLE[37][280] = 1;
TABLE[37][283] = 1;
TABLE[156][44] = 1;
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
TABLE[156][282] = 1;
TABLE[156][267] = 1;
TABLE[156][279] = 1;
TABLE[156][274] = 1;
TABLE[156][256] = 1;
TABLE[156][283] = 1;
TABLE[156][280] = 1;
TABLE[236][256] = 1;
TABLE[236][274] = 1;
TABLE[236][279] = 1;
TABLE[236][267] = 1;
TABLE[236][282] = 1;
TABLE[236][266] = 1;
TABLE[236][285] = 1;
TABLE[236][259] = 1;
TABLE[236][276] = 1;
TABLE[236][272] = 1;
TABLE[236][273] = 1;
TABLE[236][268] = 1;
TABLE[236][264] = 1;
TABLE[236][277] = 1;
TABLE[236][284] = 1;
TABLE[236][260] = 1;
TABLE[236][286] = 1;
TABLE[236][280] = 1;
TABLE[236][283] = 1;
TABLE[38][286] = 1;
TABLE[38][260] = 1;
TABLE[38][284] = 1;
TABLE[38][277] = 1;
TABLE[38][264] = 1;
TABLE[38][268] = 1;
TABLE[38][273] = 1;
TABLE[38][272] = 1;
TABLE[38][276] = 1;
TABLE[38][259] = 1;
TABLE[38][285] = 1;
TABLE[38][266] = 1;
TABLE[38][282] = 1;
TABLE[38][267] = 1;
TABLE[38][279] = 1;
TABLE[38][274] = 1;
TABLE[38][256] = 1;
TABLE[38][283] = 1;
TABLE[38][280] = 1;
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
TABLE[237][44] = 1;
TABLE[237][41] = 1;
TABLE[39][44] = 1;
TABLE[39][299] = 1;
TABLE[160][44] = 1;
TABLE[160][299] = 1;
TABLE[238][299] = 1;
TABLE[40][59] = 1;
TABLE[40][44] = 1;
TABLE[40][125] = 1;
TABLE[40][278] = 1;
TABLE[40][63] = 1;
TABLE[40][294] = 1;
TABLE[40][295] = 1;
TABLE[40][297] = 1;
TABLE[40][33] = 1;
TABLE[40][126] = 1;
TABLE[40][45] = 1;
TABLE[40][43] = 1;
TABLE[40][42] = 1;
TABLE[40][302] = 1;
TABLE[40][40] = 1;
TABLE[40][289] = 1;
TABLE[40][298] = 1;
TABLE[40][308] = 1;
TABLE[40][306] = 1;
TABLE[40][307] = 1;
TABLE[40][299] = 1;
TABLE[40][301] = 1;
TABLE[40][303] = 1;
TABLE[40][292] = 1;
TABLE[40][304] = 1;
TABLE[40][47] = 1;
TABLE[40][37] = 1;
TABLE[41][123] = 1;
TABLE[161][44] = 1;
TABLE[239][125] = 1;
TABLE[42][125] = 1;
TABLE[42][123] = 1;
TABLE[42][44] = 1;
TABLE[42][278] = 1;
TABLE[42][295] = 1;
TABLE[42][294] = 1;
TABLE[42][63] = 1;
TABLE[42][289] = 1;
TABLE[42][40] = 1;
TABLE[42][302] = 1;
TABLE[42][42] = 1;
TABLE[42][43] = 1;
TABLE[42][45] = 1;
TABLE[42][126] = 1;
TABLE[42][33] = 1;
TABLE[42][297] = 1;
TABLE[42][299] = 1;
TABLE[42][307] = 1;
TABLE[42][306] = 1;
TABLE[42][308] = 1;
TABLE[42][298] = 1;
TABLE[42][301] = 1;
TABLE[42][303] = 1;
TABLE[42][292] = 1;
TABLE[42][304] = 1;
TABLE[42][37] = 1;
TABLE[42][47] = 1;
TABLE[162][123] = 1;
TABLE[162][44] = 1;
TABLE[162][278] = 1;
TABLE[162][63] = 1;
TABLE[162][294] = 1;
TABLE[162][295] = 1;
TABLE[162][297] = 1;
TABLE[162][33] = 1;
TABLE[162][126] = 1;
TABLE[162][45] = 1;
TABLE[162][43] = 1;
TABLE[162][42] = 1;
TABLE[162][302] = 1;
TABLE[162][40] = 1;
TABLE[162][289] = 1;
TABLE[162][298] = 1;
TABLE[162][308] = 1;
TABLE[162][306] = 1;
TABLE[162][307] = 1;
TABLE[162][299] = 1;
TABLE[162][301] = 1;
TABLE[162][303] = 1;
TABLE[162][292] = 1;
TABLE[162][304] = 1;
TABLE[162][47] = 1;
TABLE[162][37] = 1;
TABLE[240][123] = 1;
TABLE[240][278] = 1;
TABLE[240][295] = 1;
TABLE[240][294] = 1;
TABLE[240][63] = 1;
TABLE[240][289] = 1;
TABLE[240][40] = 1;
TABLE[240][302] = 1;
TABLE[240][42] = 1;
TABLE[240][43] = 1;
TABLE[240][45] = 1;
TABLE[240][126] = 1;
TABLE[240][33] = 1;
TABLE[240][297] = 1;
TABLE[240][299] = 1;
TABLE[240][307] = 1;
TABLE[240][306] = 1;
TABLE[240][308] = 1;
TABLE[240][298] = 1;
TABLE[240][301] = 1;
TABLE[240][303] = 1;
TABLE[240][292] = 1;
TABLE[240][304] = 1;
TABLE[240][37] = 1;
TABLE[240][47] = 1;
TABLE[240][44] = 1;
TABLE[240][125] = 1;
TABLE[43][286] = 1;
TABLE[43][260] = 1;
TABLE[43][284] = 1;
TABLE[43][277] = 1;
TABLE[43][264] = 1;
TABLE[43][268] = 1;
TABLE[43][273] = 1;
TABLE[43][272] = 1;
TABLE[43][276] = 1;
TABLE[43][259] = 1;
TABLE[43][285] = 1;
TABLE[43][266] = 1;
TABLE[43][283] = 1;
TABLE[43][280] = 1;
TABLE[163][41] = 1;
TABLE[163][42] = 1;
TABLE[163][40] = 1;
TABLE[163][91] = 1;
TABLE[241][41] = 1;
TABLE[44][42] = 1;
TABLE[45][44] = 1;
TABLE[45][41] = 1;
TABLE[45][40] = 1;
TABLE[45][91] = 1;
TABLE[45][42] = 1;
TABLE[164][42] = 1;
TABLE[242][40] = 1;
TABLE[242][91] = 1;
TABLE[242][44] = 1;
TABLE[242][41] = 1;
TABLE[46][40] = 1;
TABLE[47][40] = 1;
TABLE[47][91] = 1;
TABLE[165][40] = 1;
TABLE[165][91] = 1;
TABLE[243][91] = 1;
TABLE[243][40] = 1;
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
TABLE[166][299] = 1;
TABLE[166][307] = 1;
TABLE[166][306] = 1;
TABLE[166][308] = 1;
TABLE[244][93] = 1;
TABLE[168][41] = 1;
TABLE[168][44] = 1;
TABLE[168][256] = 1;
TABLE[168][274] = 1;
TABLE[168][279] = 1;
TABLE[168][267] = 1;
TABLE[168][282] = 1;
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
TABLE[168][280] = 1;
TABLE[168][283] = 1;
TABLE[245][41] = 1;
TABLE[48][299] = 1;
TABLE[49][258] = 1;
TABLE[49][262] = 1;
TABLE[49][299] = 1;
TABLE[50][125] = 1;
TABLE[50][265] = 1;
TABLE[50][287] = 1;
TABLE[50][262] = 1;
TABLE[50][258] = 1;
TABLE[50][123] = 1;
TABLE[50][281] = 1;
TABLE[50][271] = 1;
TABLE[50][269] = 1;
TABLE[50][263] = 1;
TABLE[50][275] = 1;
TABLE[50][257] = 1;
TABLE[50][261] = 1;
TABLE[50][270] = 1;
TABLE[50][59] = 1;
TABLE[50][44] = 1;
TABLE[50][278] = 1;
TABLE[50][295] = 1;
TABLE[50][294] = 1;
TABLE[50][63] = 1;
TABLE[50][289] = 1;
TABLE[50][40] = 1;
TABLE[50][302] = 1;
TABLE[50][42] = 1;
TABLE[50][43] = 1;
TABLE[50][45] = 1;
TABLE[50][126] = 1;
TABLE[50][33] = 1;
TABLE[50][297] = 1;
TABLE[50][299] = 1;
TABLE[50][307] = 1;
TABLE[50][306] = 1;
TABLE[50][308] = 1;
TABLE[50][298] = 1;
TABLE[50][301] = 1;
TABLE[50][303] = 1;
TABLE[50][292] = 1;
TABLE[50][304] = 1;
TABLE[50][37] = 1;
TABLE[50][47] = 1;
TABLE[51][123] = 1;
TABLE[52][271] = 1;
TABLE[52][281] = 1;
TABLE[53][287] = 1;
TABLE[53][263] = 1;
TABLE[53][269] = 1;
TABLE[54][270] = 1;
TABLE[54][261] = 1;
TABLE[54][257] = 1;
TABLE[54][275] = 1;
TABLE[55][299] = 1;
TABLE[56][258] = 1;
TABLE[57][262] = 1;
TABLE[58][59] = 1;
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
TABLE[58][299] = 1;
TABLE[58][301] = 1;
TABLE[58][303] = 1;
TABLE[58][292] = 1;
TABLE[58][304] = 1;
TABLE[58][47] = 1;
TABLE[58][37] = 1;
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
TABLE[170][297] = 1;
TABLE[170][299] = 1;
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
TABLE[246][59] = 1;
TABLE[59][123] = 1;
TABLE[171][262] = 1;
TABLE[171][258] = 1;
TABLE[171][59] = 1;
TABLE[171][123] = 1;
TABLE[171][281] = 1;
TABLE[171][271] = 1;
TABLE[171][269] = 1;
TABLE[171][263] = 1;
TABLE[171][287] = 1;
TABLE[171][275] = 1;
TABLE[171][257] = 1;
TABLE[171][261] = 1;
TABLE[171][270] = 1;
TABLE[171][299] = 1;
TABLE[171][44] = 1;
TABLE[171][278] = 1;
TABLE[171][63] = 1;
TABLE[171][294] = 1;
TABLE[171][295] = 1;
TABLE[171][297] = 1;
TABLE[171][33] = 1;
TABLE[171][126] = 1;
TABLE[171][45] = 1;
TABLE[171][43] = 1;
TABLE[171][42] = 1;
TABLE[171][302] = 1;
TABLE[171][40] = 1;
TABLE[171][289] = 1;
TABLE[171][298] = 1;
TABLE[171][308] = 1;
TABLE[171][306] = 1;
TABLE[171][307] = 1;
TABLE[171][301] = 1;
TABLE[171][303] = 1;
TABLE[171][292] = 1;
TABLE[171][304] = 1;
TABLE[171][47] = 1;
TABLE[171][37] = 1;
TABLE[171][125] = 1;
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
TABLE[171][282] = 1;
TABLE[171][267] = 1;
TABLE[171][279] = 1;
TABLE[171][274] = 1;
TABLE[171][256] = 1;
TABLE[171][283] = 1;
TABLE[171][280] = 1;
TABLE[247][262] = 1;
TABLE[247][258] = 1;
TABLE[247][59] = 1;
TABLE[247][123] = 1;
TABLE[247][281] = 1;
TABLE[247][271] = 1;
TABLE[247][269] = 1;
TABLE[247][263] = 1;
TABLE[247][287] = 1;
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
TABLE[247][125] = 1;
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
TABLE[172][297] = 1;
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
TABLE[248][125] = 1;
TABLE[60][125] = 1;
TABLE[60][262] = 1;
TABLE[60][258] = 1;
TABLE[60][59] = 1;
TABLE[60][123] = 1;
TABLE[60][281] = 1;
TABLE[60][271] = 1;
TABLE[60][269] = 1;
TABLE[60][263] = 1;
TABLE[60][287] = 1;
TABLE[60][275] = 1;
TABLE[60][257] = 1;
TABLE[60][261] = 1;
TABLE[60][270] = 1;
TABLE[60][299] = 1;
TABLE[60][44] = 1;
TABLE[60][278] = 1;
TABLE[60][63] = 1;
TABLE[60][294] = 1;
TABLE[60][295] = 1;
TABLE[60][297] = 1;
TABLE[60][33] = 1;
TABLE[60][126] = 1;
TABLE[60][45] = 1;
TABLE[60][43] = 1;
TABLE[60][42] = 1;
TABLE[60][302] = 1;
TABLE[60][40] = 1;
TABLE[60][289] = 1;
TABLE[60][298] = 1;
TABLE[60][308] = 1;
TABLE[60][306] = 1;
TABLE[60][307] = 1;
TABLE[60][301] = 1;
TABLE[60][303] = 1;
TABLE[60][292] = 1;
TABLE[60][304] = 1;
TABLE[60][47] = 1;
TABLE[60][37] = 1;
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
TABLE[173][297] = 1;
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
TABLE[249][262] = 1;
TABLE[249][258] = 1;
TABLE[249][59] = 1;
TABLE[249][123] = 1;
TABLE[249][281] = 1;
TABLE[249][271] = 1;
TABLE[249][269] = 1;
TABLE[249][263] = 1;
TABLE[249][287] = 1;
TABLE[249][275] = 1;
TABLE[249][257] = 1;
TABLE[249][261] = 1;
TABLE[249][270] = 1;
TABLE[249][299] = 1;
TABLE[249][44] = 1;
TABLE[249][278] = 1;
TABLE[249][63] = 1;
TABLE[249][294] = 1;
TABLE[249][295] = 1;
TABLE[249][297] = 1;
TABLE[249][33] = 1;
TABLE[249][126] = 1;
TABLE[249][45] = 1;
TABLE[249][43] = 1;
TABLE[249][42] = 1;
TABLE[249][302] = 1;
TABLE[249][40] = 1;
TABLE[249][289] = 1;
TABLE[249][298] = 1;
TABLE[249][308] = 1;
TABLE[249][306] = 1;
TABLE[249][307] = 1;
TABLE[249][301] = 1;
TABLE[249][303] = 1;
TABLE[249][292] = 1;
TABLE[249][304] = 1;
TABLE[249][47] = 1;
TABLE[249][37] = 1;
TABLE[249][125] = 1;
TABLE[61][271] = 1;
TABLE[62][281] = 1;
TABLE[174][265] = 1;
TABLE[250][125] = 1;
TABLE[250][265] = 1;
TABLE[250][287] = 1;
TABLE[250][262] = 1;
TABLE[250][258] = 1;
TABLE[250][59] = 1;
TABLE[250][123] = 1;
TABLE[250][281] = 1;
TABLE[250][271] = 1;
TABLE[250][269] = 1;
TABLE[250][263] = 1;
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
TABLE[250][33] = 1;
TABLE[250][126] = 1;
TABLE[250][45] = 1;
TABLE[250][43] = 1;
TABLE[250][42] = 1;
TABLE[250][302] = 1;
TABLE[250][40] = 1;
TABLE[250][289] = 1;
TABLE[250][298] = 1;
TABLE[250][308] = 1;
TABLE[250][306] = 1;
TABLE[250][307] = 1;
TABLE[250][301] = 1;
TABLE[250][303] = 1;
TABLE[250][292] = 1;
TABLE[250][304] = 1;
TABLE[250][47] = 1;
TABLE[250][37] = 1;
TABLE[63][287] = 1;
TABLE[64][263] = 1;
TABLE[65][269] = 1;
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
TABLE[252][59] = 1;
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
TABLE[177][297] = 1;
TABLE[177][299] = 1;
TABLE[177][307] = 1;
TABLE[177][306] = 1;
TABLE[177][308] = 1;
TABLE[177][298] = 1;
TABLE[177][301] = 1;
TABLE[177][303] = 1;
TABLE[177][292] = 1;
TABLE[177][304] = 1;
TABLE[177][37] = 1;
TABLE[177][47] = 1;
TABLE[253][41] = 1;
TABLE[66][270] = 1;
TABLE[67][261] = 1;
TABLE[68][257] = 1;
TABLE[69][275] = 1;
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
TABLE[178][297] = 1;
TABLE[178][299] = 1;
TABLE[178][307] = 1;
TABLE[178][306] = 1;
TABLE[178][308] = 1;
TABLE[178][298] = 1;
TABLE[178][301] = 1;
TABLE[178][303] = 1;
TABLE[178][292] = 1;
TABLE[178][304] = 1;
TABLE[178][37] = 1;
TABLE[178][47] = 1;
TABLE[254][59] = 1;
TABLE[70][59] = 1;
TABLE[70][41] = 1;
TABLE[70][58] = 1;
TABLE[70][93] = 1;
TABLE[70][44] = 1;
TABLE[70][278] = 1;
TABLE[70][63] = 1;
TABLE[70][294] = 1;
TABLE[70][295] = 1;
TABLE[70][297] = 1;
TABLE[70][33] = 1;
TABLE[70][126] = 1;
TABLE[70][45] = 1;
TABLE[70][43] = 1;
TABLE[70][42] = 1;
TABLE[70][302] = 1;
TABLE[70][40] = 1;
TABLE[70][289] = 1;
TABLE[70][298] = 1;
TABLE[70][308] = 1;
TABLE[70][306] = 1;
TABLE[70][307] = 1;
TABLE[70][299] = 1;
TABLE[70][301] = 1;
TABLE[70][303] = 1;
TABLE[70][292] = 1;
TABLE[70][304] = 1;
TABLE[70][47] = 1;
TABLE[70][37] = 1;
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
TABLE[179][297] = 1;
TABLE[179][299] = 1;
TABLE[179][307] = 1;
TABLE[179][306] = 1;
TABLE[179][308] = 1;
TABLE[179][298] = 1;
TABLE[179][301] = 1;
TABLE[179][303] = 1;
TABLE[179][292] = 1;
TABLE[179][304] = 1;
TABLE[179][37] = 1;
TABLE[179][47] = 1;
TABLE[255][278] = 1;
TABLE[255][63] = 1;
TABLE[255][294] = 1;
TABLE[255][295] = 1;
TABLE[255][297] = 1;
TABLE[255][33] = 1;
TABLE[255][126] = 1;
TABLE[255][45] = 1;
TABLE[255][43] = 1;
TABLE[255][42] = 1;
TABLE[255][302] = 1;
TABLE[255][40] = 1;
TABLE[255][289] = 1;
TABLE[255][298] = 1;
TABLE[255][308] = 1;
TABLE[255][306] = 1;
TABLE[255][307] = 1;
TABLE[255][299] = 1;
TABLE[255][301] = 1;
TABLE[255][303] = 1;
TABLE[255][292] = 1;
TABLE[255][304] = 1;
TABLE[255][47] = 1;
TABLE[255][37] = 1;
TABLE[255][59] = 1;
TABLE[255][41] = 1;
TABLE[255][44] = 1;
TABLE[255][58] = 1;
TABLE[255][93] = 1;
TABLE[71][59] = 1;
TABLE[71][41] = 1;
TABLE[71][44] = 1;
TABLE[71][125] = 1;
TABLE[71][58] = 1;
TABLE[71][93] = 1;
TABLE[71][63] = 1;
TABLE[71][297] = 1;
TABLE[71][298] = 1;
TABLE[71][301] = 1;
TABLE[71][303] = 1;
TABLE[71][302] = 1;
TABLE[71][292] = 1;
TABLE[71][304] = 1;
TABLE[71][43] = 1;
TABLE[71][45] = 1;
TABLE[71][40] = 1;
TABLE[71][278] = 1;
TABLE[71][37] = 1;
TABLE[71][47] = 1;
TABLE[71][42] = 1;
TABLE[71][294] = 1;
TABLE[71][295] = 1;
TABLE[71][33] = 1;
TABLE[71][126] = 1;
TABLE[71][289] = 1;
TABLE[71][308] = 1;
TABLE[71][306] = 1;
TABLE[71][307] = 1;
TABLE[71][299] = 1;
TABLE[72][278] = 1;
TABLE[72][295] = 1;
TABLE[72][294] = 1;
TABLE[72][289] = 1;
TABLE[72][40] = 1;
TABLE[72][302] = 1;
TABLE[72][42] = 1;
TABLE[72][43] = 1;
TABLE[72][45] = 1;
TABLE[72][126] = 1;
TABLE[72][33] = 1;
TABLE[72][299] = 1;
TABLE[72][307] = 1;
TABLE[72][306] = 1;
TABLE[72][308] = 1;
TABLE[73][291] = 1;
TABLE[73][61] = 1;
TABLE[180][291] = 1;
TABLE[181][61] = 1;
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
TABLE[74][299] = 1;
TABLE[74][307] = 1;
TABLE[74][306] = 1;
TABLE[74][308] = 1;
TABLE[182][63] = 1;
TABLE[256][59] = 1;
TABLE[256][41] = 1;
TABLE[256][125] = 1;
TABLE[256][93] = 1;
TABLE[256][58] = 1;
TABLE[256][44] = 1;
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
TABLE[75][33] = 1;
TABLE[75][126] = 1;
TABLE[75][289] = 1;
TABLE[75][308] = 1;
TABLE[75][306] = 1;
TABLE[75][307] = 1;
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
TABLE[76][33] = 1;
TABLE[76][126] = 1;
TABLE[76][289] = 1;
TABLE[76][308] = 1;
TABLE[76][306] = 1;
TABLE[76][307] = 1;
TABLE[76][299] = 1;
TABLE[183][297] = 1;
TABLE[183][298] = 1;
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
TABLE[183][299] = 1;
TABLE[183][307] = 1;
TABLE[183][306] = 1;
TABLE[183][308] = 1;
TABLE[257][298] = 1;
TABLE[257][301] = 1;
TABLE[257][303] = 1;
TABLE[257][302] = 1;
TABLE[257][292] = 1;
TABLE[257][304] = 1;
TABLE[257][43] = 1;
TABLE[257][45] = 1;
TABLE[257][40] = 1;
TABLE[257][278] = 1;
TABLE[257][37] = 1;
TABLE[257][47] = 1;
TABLE[257][42] = 1;
TABLE[257][294] = 1;
TABLE[257][295] = 1;
TABLE[257][33] = 1;
TABLE[257][126] = 1;
TABLE[257][289] = 1;
TABLE[257][308] = 1;
TABLE[257][306] = 1;
TABLE[257][307] = 1;
TABLE[257][299] = 1;
TABLE[257][63] = 1;
TABLE[257][59] = 1;
TABLE[257][41] = 1;
TABLE[257][297] = 1;
TABLE[257][125] = 1;
TABLE[257][93] = 1;
TABLE[257][58] = 1;
TABLE[257][44] = 1;
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
TABLE[77][299] = 1;
TABLE[77][307] = 1;
TABLE[77][306] = 1;
TABLE[77][308] = 1;
TABLE[184][298] = 1;
TABLE[184][301] = 1;
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
TABLE[184][33] = 1;
TABLE[184][126] = 1;
TABLE[184][289] = 1;
TABLE[184][308] = 1;
TABLE[184][306] = 1;
TABLE[184][307] = 1;
TABLE[184][299] = 1;
TABLE[258][301] = 1;
TABLE[258][303] = 1;
TABLE[258][302] = 1;
TABLE[258][292] = 1;
TABLE[258][304] = 1;
TABLE[258][40] = 1;
TABLE[258][45] = 1;
TABLE[258][43] = 1;
TABLE[258][42] = 1;
TABLE[258][47] = 1;
TABLE[258][37] = 1;
TABLE[258][278] = 1;
TABLE[258][295] = 1;
TABLE[258][294] = 1;
TABLE[258][289] = 1;
TABLE[258][126] = 1;
TABLE[258][33] = 1;
TABLE[258][299] = 1;
TABLE[258][307] = 1;
TABLE[258][306] = 1;
TABLE[258][308] = 1;
TABLE[258][63] = 1;
TABLE[258][59] = 1;
TABLE[258][41] = 1;
TABLE[258][298] = 1;
TABLE[258][297] = 1;
TABLE[258][125] = 1;
TABLE[258][93] = 1;
TABLE[258][58] = 1;
TABLE[258][44] = 1;
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
TABLE[78][33] = 1;
TABLE[78][126] = 1;
TABLE[78][289] = 1;
TABLE[78][308] = 1;
TABLE[78][306] = 1;
TABLE[78][307] = 1;
TABLE[78][299] = 1;
TABLE[185][301] = 1;
TABLE[185][303] = 1;
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
TABLE[185][299] = 1;
TABLE[185][307] = 1;
TABLE[185][306] = 1;
TABLE[185][308] = 1;
TABLE[259][303] = 1;
TABLE[259][302] = 1;
TABLE[259][292] = 1;
TABLE[259][304] = 1;
TABLE[259][43] = 1;
TABLE[259][45] = 1;
TABLE[259][40] = 1;
TABLE[259][278] = 1;
TABLE[259][37] = 1;
TABLE[259][47] = 1;
TABLE[259][42] = 1;
TABLE[259][294] = 1;
TABLE[259][295] = 1;
TABLE[259][33] = 1;
TABLE[259][126] = 1;
TABLE[259][289] = 1;
TABLE[259][308] = 1;
TABLE[259][306] = 1;
TABLE[259][307] = 1;
TABLE[259][299] = 1;
TABLE[259][63] = 1;
TABLE[259][59] = 1;
TABLE[259][41] = 1;
TABLE[259][301] = 1;
TABLE[259][298] = 1;
TABLE[259][297] = 1;
TABLE[259][125] = 1;
TABLE[259][93] = 1;
TABLE[259][58] = 1;
TABLE[259][44] = 1;
TABLE[79][63] = 1;
TABLE[79][59] = 1;
TABLE[79][41] = 1;
TABLE[79][301] = 1;
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
TABLE[79][299] = 1;
TABLE[79][307] = 1;
TABLE[79][306] = 1;
TABLE[79][308] = 1;
TABLE[186][303] = 1;
TABLE[186][302] = 1;
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
TABLE[186][33] = 1;
TABLE[186][126] = 1;
TABLE[186][289] = 1;
TABLE[186][308] = 1;
TABLE[186][306] = 1;
TABLE[186][307] = 1;
TABLE[186][299] = 1;
TABLE[260][302] = 1;
TABLE[260][292] = 1;
TABLE[260][304] = 1;
TABLE[260][40] = 1;
TABLE[260][45] = 1;
TABLE[260][43] = 1;
TABLE[260][42] = 1;
TABLE[260][47] = 1;
TABLE[260][37] = 1;
TABLE[260][278] = 1;
TABLE[260][295] = 1;
TABLE[260][294] = 1;
TABLE[260][289] = 1;
TABLE[260][126] = 1;
TABLE[260][33] = 1;
TABLE[260][299] = 1;
TABLE[260][307] = 1;
TABLE[260][306] = 1;
TABLE[260][308] = 1;
TABLE[260][63] = 1;
TABLE[260][59] = 1;
TABLE[260][41] = 1;
TABLE[260][303] = 1;
TABLE[260][301] = 1;
TABLE[260][298] = 1;
TABLE[260][297] = 1;
TABLE[260][125] = 1;
TABLE[260][93] = 1;
TABLE[260][58] = 1;
TABLE[260][44] = 1;
TABLE[80][63] = 1;
TABLE[80][59] = 1;
TABLE[80][41] = 1;
TABLE[80][303] = 1;
TABLE[80][301] = 1;
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
TABLE[80][33] = 1;
TABLE[80][126] = 1;
TABLE[80][289] = 1;
TABLE[80][308] = 1;
TABLE[80][306] = 1;
TABLE[80][307] = 1;
TABLE[80][299] = 1;
TABLE[187][302] = 1;
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
TABLE[187][299] = 1;
TABLE[187][307] = 1;
TABLE[187][306] = 1;
TABLE[187][308] = 1;
TABLE[261][292] = 1;
TABLE[261][304] = 1;
TABLE[261][43] = 1;
TABLE[261][45] = 1;
TABLE[261][40] = 1;
TABLE[261][278] = 1;
TABLE[261][37] = 1;
TABLE[261][47] = 1;
TABLE[261][42] = 1;
TABLE[261][294] = 1;
TABLE[261][295] = 1;
TABLE[261][33] = 1;
TABLE[261][126] = 1;
TABLE[261][302] = 1;
TABLE[261][289] = 1;
TABLE[261][308] = 1;
TABLE[261][306] = 1;
TABLE[261][307] = 1;
TABLE[261][299] = 1;
TABLE[261][63] = 1;
TABLE[261][59] = 1;
TABLE[261][41] = 1;
TABLE[261][303] = 1;
TABLE[261][301] = 1;
TABLE[261][298] = 1;
TABLE[261][297] = 1;
TABLE[261][125] = 1;
TABLE[261][93] = 1;
TABLE[261][58] = 1;
TABLE[261][44] = 1;
TABLE[81][63] = 1;
TABLE[81][59] = 1;
TABLE[81][41] = 1;
TABLE[81][303] = 1;
TABLE[81][301] = 1;
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
TABLE[81][299] = 1;
TABLE[81][307] = 1;
TABLE[81][306] = 1;
TABLE[81][308] = 1;
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
TABLE[188][33] = 1;
TABLE[188][126] = 1;
TABLE[188][302] = 1;
TABLE[188][289] = 1;
TABLE[188][308] = 1;
TABLE[188][306] = 1;
TABLE[188][307] = 1;
TABLE[188][299] = 1;
TABLE[262][304] = 1;
TABLE[262][40] = 1;
TABLE[262][45] = 1;
TABLE[262][43] = 1;
TABLE[262][42] = 1;
TABLE[262][47] = 1;
TABLE[262][37] = 1;
TABLE[262][278] = 1;
TABLE[262][295] = 1;
TABLE[262][294] = 1;
TABLE[262][289] = 1;
TABLE[262][302] = 1;
TABLE[262][126] = 1;
TABLE[262][33] = 1;
TABLE[262][299] = 1;
TABLE[262][307] = 1;
TABLE[262][306] = 1;
TABLE[262][308] = 1;
TABLE[262][63] = 1;
TABLE[262][59] = 1;
TABLE[262][41] = 1;
TABLE[262][292] = 1;
TABLE[262][303] = 1;
TABLE[262][301] = 1;
TABLE[262][298] = 1;
TABLE[262][297] = 1;
TABLE[262][125] = 1;
TABLE[262][93] = 1;
TABLE[262][58] = 1;
TABLE[262][44] = 1;
TABLE[82][63] = 1;
TABLE[82][59] = 1;
TABLE[82][41] = 1;
TABLE[82][292] = 1;
TABLE[82][303] = 1;
TABLE[82][301] = 1;
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
TABLE[82][33] = 1;
TABLE[82][126] = 1;
TABLE[82][302] = 1;
TABLE[82][289] = 1;
TABLE[82][308] = 1;
TABLE[82][306] = 1;
TABLE[82][307] = 1;
TABLE[82][299] = 1;
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
TABLE[189][302] = 1;
TABLE[189][126] = 1;
TABLE[189][33] = 1;
TABLE[189][299] = 1;
TABLE[189][307] = 1;
TABLE[189][306] = 1;
TABLE[189][308] = 1;
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
TABLE[263][302] = 1;
TABLE[263][289] = 1;
TABLE[263][308] = 1;
TABLE[263][306] = 1;
TABLE[263][307] = 1;
TABLE[263][299] = 1;
TABLE[263][63] = 1;
TABLE[263][59] = 1;
TABLE[263][41] = 1;
TABLE[263][304] = 1;
TABLE[263][292] = 1;
TABLE[263][303] = 1;
TABLE[263][301] = 1;
TABLE[263][298] = 1;
TABLE[263][297] = 1;
TABLE[263][125] = 1;
TABLE[263][93] = 1;
TABLE[263][58] = 1;
TABLE[263][44] = 1;
TABLE[83][63] = 1;
TABLE[83][59] = 1;
TABLE[83][41] = 1;
TABLE[83][304] = 1;
TABLE[83][292] = 1;
TABLE[83][303] = 1;
TABLE[83][301] = 1;
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
TABLE[83][299] = 1;
TABLE[83][307] = 1;
TABLE[83][306] = 1;
TABLE[83][308] = 1;
TABLE[192][43] = 1;
TABLE[192][45] = 1;
TABLE[192][40] = 1;
TABLE[192][278] = 1;
TABLE[192][37] = 1;
TABLE[192][47] = 1;
TABLE[192][42] = 1;
TABLE[192][294] = 1;
TABLE[192][295] = 1;
TABLE[192][33] = 1;
TABLE[192][126] = 1;
TABLE[192][302] = 1;
TABLE[192][289] = 1;
TABLE[192][308] = 1;
TABLE[192][306] = 1;
TABLE[192][307] = 1;
TABLE[192][299] = 1;
TABLE[264][40] = 1;
TABLE[264][42] = 1;
TABLE[264][47] = 1;
TABLE[264][37] = 1;
TABLE[264][278] = 1;
TABLE[264][295] = 1;
TABLE[264][294] = 1;
TABLE[264][289] = 1;
TABLE[264][302] = 1;
TABLE[264][43] = 1;
TABLE[264][45] = 1;
TABLE[264][126] = 1;
TABLE[264][33] = 1;
TABLE[264][299] = 1;
TABLE[264][307] = 1;
TABLE[264][306] = 1;
TABLE[264][308] = 1;
TABLE[264][63] = 1;
TABLE[264][59] = 1;
TABLE[264][41] = 1;
TABLE[264][304] = 1;
TABLE[264][292] = 1;
TABLE[264][303] = 1;
TABLE[264][301] = 1;
TABLE[264][298] = 1;
TABLE[264][297] = 1;
TABLE[264][125] = 1;
TABLE[264][93] = 1;
TABLE[264][58] = 1;
TABLE[264][44] = 1;
TABLE[190][43] = 1;
TABLE[191][45] = 1;
TABLE[84][40] = 1;
TABLE[84][37] = 1;
TABLE[84][47] = 1;
TABLE[84][42] = 1;
TABLE[84][278] = 1;
TABLE[84][294] = 1;
TABLE[84][295] = 1;
TABLE[84][33] = 1;
TABLE[84][126] = 1;
TABLE[84][45] = 1;
TABLE[84][43] = 1;
TABLE[84][302] = 1;
TABLE[84][289] = 1;
TABLE[84][308] = 1;
TABLE[84][306] = 1;
TABLE[84][307] = 1;
TABLE[84][299] = 1;
TABLE[196][40] = 1;
TABLE[196][42] = 1;
TABLE[196][47] = 1;
TABLE[196][37] = 1;
TABLE[196][278] = 1;
TABLE[196][295] = 1;
TABLE[196][294] = 1;
TABLE[196][289] = 1;
TABLE[196][302] = 1;
TABLE[196][43] = 1;
TABLE[196][45] = 1;
TABLE[196][126] = 1;
TABLE[196][33] = 1;
TABLE[196][299] = 1;
TABLE[196][307] = 1;
TABLE[196][306] = 1;
TABLE[196][308] = 1;
TABLE[265][40] = 1;
TABLE[265][278] = 1;
TABLE[265][294] = 1;
TABLE[265][295] = 1;
TABLE[265][33] = 1;
TABLE[265][126] = 1;
TABLE[265][45] = 1;
TABLE[265][43] = 1;
TABLE[265][42] = 1;
TABLE[265][302] = 1;
TABLE[265][289] = 1;
TABLE[265][308] = 1;
TABLE[265][306] = 1;
TABLE[265][307] = 1;
TABLE[265][299] = 1;
TABLE[193][42] = 1;
TABLE[194][47] = 1;
TABLE[195][37] = 1;
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
TABLE[85][299] = 1;
TABLE[85][307] = 1;
TABLE[85][306] = 1;
TABLE[85][308] = 1;
TABLE[86][40] = 1;
TABLE[87][40] = 1;
TABLE[87][289] = 1;
TABLE[87][308] = 1;
TABLE[87][306] = 1;
TABLE[87][307] = 1;
TABLE[87][299] = 1;
TABLE[88][294] = 1;
TABLE[88][295] = 1;
TABLE[89][33] = 1;
TABLE[89][126] = 1;
TABLE[89][45] = 1;
TABLE[89][43] = 1;
TABLE[89][42] = 1;
TABLE[89][302] = 1;
TABLE[90][278] = 1;
TABLE[91][278] = 1;
TABLE[197][294] = 1;
TABLE[198][295] = 1;
TABLE[92][302] = 1;
TABLE[92][42] = 1;
TABLE[92][43] = 1;
TABLE[92][45] = 1;
TABLE[92][126] = 1;
TABLE[92][33] = 1;
TABLE[199][302] = 1;
TABLE[200][42] = 1;
TABLE[201][43] = 1;
TABLE[202][45] = 1;
TABLE[203][126] = 1;
TABLE[204][33] = 1;
TABLE[93][289] = 1;
TABLE[93][40] = 1;
TABLE[93][299] = 1;
TABLE[93][307] = 1;
TABLE[93][306] = 1;
TABLE[93][308] = 1;
TABLE[94][40] = 1;
TABLE[94][289] = 1;
TABLE[94][308] = 1;
TABLE[94][306] = 1;
TABLE[94][307] = 1;
TABLE[94][299] = 1;
TABLE[205][91] = 1;
TABLE[207][40] = 1;
TABLE[208][46] = 1;
TABLE[209][296] = 1;
TABLE[210][294] = 1;
TABLE[211][295] = 1;
TABLE[206][41] = 1;
TABLE[206][44] = 1;
TABLE[206][278] = 1;
TABLE[206][295] = 1;
TABLE[206][294] = 1;
TABLE[206][63] = 1;
TABLE[206][289] = 1;
TABLE[206][40] = 1;
TABLE[206][302] = 1;
TABLE[206][42] = 1;
TABLE[206][43] = 1;
TABLE[206][45] = 1;
TABLE[206][126] = 1;
TABLE[206][33] = 1;
TABLE[206][297] = 1;
TABLE[206][299] = 1;
TABLE[206][307] = 1;
TABLE[206][306] = 1;
TABLE[206][308] = 1;
TABLE[206][298] = 1;
TABLE[206][301] = 1;
TABLE[206][303] = 1;
TABLE[206][292] = 1;
TABLE[206][304] = 1;
TABLE[206][37] = 1;
TABLE[206][47] = 1;
TABLE[266][41] = 1;
TABLE[95][299] = 1;
TABLE[96][308] = 1;
TABLE[96][306] = 1;
TABLE[96][307] = 1;
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
TABLE[99][33] = 1;
TABLE[99][126] = 1;
TABLE[99][45] = 1;
TABLE[99][43] = 1;
TABLE[99][42] = 1;
TABLE[99][302] = 1;
TABLE[99][40] = 1;
TABLE[99][289] = 1;
TABLE[99][298] = 1;
TABLE[99][308] = 1;
TABLE[99][306] = 1;
TABLE[99][307] = 1;
TABLE[99][299] = 1;
TABLE[99][301] = 1;
TABLE[99][303] = 1;
TABLE[99][292] = 1;
TABLE[99][304] = 1;
TABLE[99][47] = 1;
TABLE[99][37] = 1;
TABLE[212][44] = 1;
TABLE[212][278] = 1;
TABLE[212][295] = 1;
TABLE[212][294] = 1;
TABLE[212][63] = 1;
TABLE[212][289] = 1;
TABLE[212][40] = 1;
TABLE[212][302] = 1;
TABLE[212][42] = 1;
TABLE[212][43] = 1;
TABLE[212][45] = 1;
TABLE[212][126] = 1;
TABLE[212][33] = 1;
TABLE[212][297] = 1;
TABLE[212][299] = 1;
TABLE[212][307] = 1;
TABLE[212][306] = 1;
TABLE[212][308] = 1;
TABLE[212][298] = 1;
TABLE[212][301] = 1;
TABLE[212][303] = 1;
TABLE[212][292] = 1;
TABLE[212][304] = 1;
TABLE[212][37] = 1;
TABLE[212][47] = 1;
TABLE[267][278] = 1;
TABLE[267][63] = 1;
TABLE[267][294] = 1;
TABLE[267][295] = 1;
TABLE[267][297] = 1;
TABLE[267][33] = 1;
TABLE[267][126] = 1;
TABLE[267][45] = 1;
TABLE[267][43] = 1;
TABLE[267][42] = 1;
TABLE[267][302] = 1;
TABLE[267][40] = 1;
TABLE[267][289] = 1;
TABLE[267][298] = 1;
TABLE[267][308] = 1;
TABLE[267][306] = 1;
TABLE[267][307] = 1;
TABLE[267][299] = 1;
TABLE[267][301] = 1;
TABLE[267][303] = 1;
TABLE[267][292] = 1;
TABLE[267][304] = 1;
TABLE[267][47] = 1;
TABLE[267][37] = 1;
TABLE[267][41] = 1;
TABLE[267][44] = 1;
TABLE[100][308] = 1;
TABLE[101][306] = 1;
TABLE[102][307] = 1;
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
      case 14: return 1; break;
      case 22: return 0; break;
      case 28: return 0; break;
      case 32: return 1; break;
      case 40: return 1; break;
      case 47: return 1; break;
      case 54: return 1; break;
      case 61: return 0; break;
      case 67: return 1; break;
      case 74: return 1; break;
      case 79: return 1; break;
      case 86: return 0; break;
      case 91: return 0; break;
      case 103: return 1; break;
      case 110: return 0; break;
      case 114: return 0; break;
      case 134: return 0; break;
      case 146: return 0; break;
      case 182: return 0; break;
      case 186: return 0; break;
      case 194: return 0; break;
      case 207: return 1; break;
      case 214: return 0; break;
      case 218: return 0; break;
      case 226: return 1; break;
      case 231: return 1; break;
      case 238: return 1; break;
      case 243: return 1; break;
      case 251: return 1; break;
      case 256: return 1; break;
      case 264: return 0; break;
      case 270: return 0; break;
      case 275: return 0; break;
      case 283: return 1; break;
      case 290: return 1; break;
      case 295: return 1; break;
      case 303: return 1; break;
      case 313: return 1; break;
      case 320: return 0; break;
      case 333: return 1; break;
      case 340: return 1; break;
      case 345: return 1; break;
      case 353: return 0; break;
      case 358: return 1; break;
      case 366: return 1; break;
      case 371: return 1; break;
      case 378: return 0; break;
      case 393: return 0; break;
      case 411: return 1; break;
      case 418: return 1; break;
      case 425: return 0; break;
      case 431: return 1; break;
      case 438: return 1; break;
      case 445: return 1; break;
      case 450: return 1; break;
      case 457: return 1; break;
      case 462: return 1; break;
      case 470: return 1; break;
      case 475: return 1; break;
      case 483: return 0; break;
      case 488: return 1; break;
      case 496: return 1; break;
      case 503: return 1; break;
      case 508: return 1; break;
      case 516: return 1; break;
      case 527: return 1; break;
      case 534: return 1; break;
      case 539: return 1; break;
      case 547: return 0; break;
      case 552: return 1; break;
      case 559: return 1; break;
      case 568: return 1; break;
      case 575: return 1; break;
      case 586: return 1; break;
      case 593: return 0; break;
      case 605: return 1; break;
      case 612: return 1; break;
      case 619: return 0; break;
      case 623: return 1; break;
      case 647: return 0; break;
      case 666: return 1; break;
      case 671: return 1; break;
      case 678: return 0; break;
      case 685: return 1; break;
      case 692: return 1; break;
      case 699: return 1; break;
      case 704: return 1; break;
      case 711: return 0; break;
      case 728: return 1; break;
      case 736: return 0; break;
      case 766: return 1; break;
      case 773: return 1; break;
      case 780: return 1; break;
      case 787: return 0; break;
      case 809: return 1; break;
      case 816: return 1; break;
      case 821: return 1; break;
      case 829: return 1; break;
      case 839: return 0; break;
      case 843: return 0; break;
      case 851: return 1; break;
      case 856: return 1; break;
      case 866: return 1; break;
      case 870: return 1; break;
      case 875: return 1; break;
      case 883: return 1; break;
      case 888: return 1; break;
      case 896: return 1; break;
      case 901: return 1; break;
      case 909: return 1; break;
      case 914: return 1; break;
      case 922: return 1; break;
      case 927: return 1; break;
      case 935: return 1; break;
      case 940: return 1; break;
      case 948: return 1; break;
      case 953: return 1; break;
      case 961: return 1; break;
      case 966: return 1; break;
      case 974: return 0; break;
      case 982: return 1; break;
      case 987: return 1; break;
      case 995: return 0; break;
      case 1007: return 0; break;
      case 1018: return 0; break;
      case 1044: return 0; break;
      case 1052: return 0; break;
      case 1056: return 0; break;
      case 1080: return 0; break;
      case 1089: return 0; break;
      case 1119: return 1; break;
      case 1126: return 0; break;
      case 1144: return 1; break;
      case 1149: return 1; break;
      case 1157: return 0; break;
      case 1173: return 0; break;
   }
}
char * yyprintname(n)
   int n;
{
   if (n <= 50000)
      switch(n) {
         case 1: return "YYSTART"; break;
         case 6: return "translation_unit"; break;
         case 14: return "Subphrase"; break;
         case 22: return "include_line"; break;
         case 28: return "Subphrase"; break;
         case 32: return "external_declaration"; break;
         case 40: return "function_definition"; break;
         case 47: return "Subphrase"; break;
         case 54: return "Subphrase"; break;
         case 61: return "declaration"; break;
         case 67: return "Subphrase"; break;
         case 74: return "declaration_list"; break;
         case 79: return "Subphrase"; break;
         case 86: return "declaration_specifiers"; break;
         case 91: return "Subphrase"; break;
         case 103: return "Subphrase"; break;
         case 110: return "storage_class_specifier"; break;
         case 114: return "Subphrase"; break;
         case 134: return "type_specifier"; break;
         case 146: return "Subphrase"; break;
         case 182: return "type_qualifier"; break;
         case 186: return "Subphrase"; break;
         case 194: return "struct_or_union_specifier"; break;
         case 207: return "Subphrase"; break;
         case 214: return "struct_or_union"; break;
         case 218: return "Subphrase"; break;
         case 226: return "struct_declaration_list"; break;
         case 231: return "Subphrase"; break;
         case 238: return "init_declarator_list"; break;
         case 243: return "Subphrase"; break;
         case 251: return "init_declarator"; break;
         case 256: return "Subphrase"; break;
         case 264: return "struct_declaration"; break;
         case 270: return "specifier_qualifier_list"; break;
         case 275: return "Subphrase"; break;
         case 283: return "Subphrase"; break;
         case 290: return "struct_declarator_list"; break;
         case 295: return "Subphrase"; break;
         case 303: return "struct_declarator"; break;
         case 313: return "Subphrase"; break;
         case 320: return "enum_specifier"; break;
         case 333: return "Subphrase"; break;
         case 340: return "enumerator_list"; break;
         case 345: return "Subphrase"; break;
         case 353: return "enumerator"; break;
         case 358: return "Subphrase"; break;
         case 366: return "declarator"; break;
         case 371: return "Subphrase"; break;
         case 378: return "direct_declarator"; break;
         case 393: return "Subphrase"; break;
         case 411: return "Subphrase"; break;
         case 418: return "Subphrase"; break;
         case 425: return "pointer"; break;
         case 431: return "Subphrase"; break;
         case 438: return "Subphrase"; break;
         case 445: return "type_qualifier_list"; break;
         case 450: return "Subphrase"; break;
         case 457: return "parameter_type_list"; break;
         case 462: return "Subphrase"; break;
         case 470: return "parameter_list"; break;
         case 475: return "Subphrase"; break;
         case 483: return "parameter_declaration"; break;
         case 488: return "Subphrase"; break;
         case 496: return "Subphrase"; break;
         case 503: return "identifier_list"; break;
         case 508: return "Subphrase"; break;
         case 516: return "initializer"; break;
         case 527: return "Subphrase"; break;
         case 534: return "initializer_list"; break;
         case 539: return "Subphrase"; break;
         case 547: return "type_name"; break;
         case 552: return "Subphrase"; break;
         case 559: return "abstract_declarator"; break;
         case 568: return "Subphrase"; break;
         case 575: return "direct_abstract_declarator"; break;
         case 586: return "Subphrase"; break;
         case 593: return "Subphrase"; break;
         case 605: return "Subphrase"; break;
         case 612: return "Subphrase"; break;
         case 619: return "typedef_name"; break;
         case 623: return "statement"; break;
         case 647: return "labeled_statement"; break;
         case 666: return "expression_statement"; break;
         case 671: return "Subphrase"; break;
         case 678: return "compound_statement"; break;
         case 685: return "Subphrase"; break;
         case 692: return "Subphrase"; break;
         case 699: return "statement_list"; break;
         case 704: return "Subphrase"; break;
         case 711: return "selection_statement"; break;
         case 728: return "Subphrase"; break;
         case 736: return "iteration_statement"; break;
         case 766: return "Subphrase"; break;
         case 773: return "Subphrase"; break;
         case 780: return "Subphrase"; break;
         case 787: return "jump_statement"; break;
         case 809: return "Subphrase"; break;
         case 816: return "expression"; break;
         case 821: return "Subphrase"; break;
         case 829: return "assignment_expression"; break;
         case 839: return "assignment_operator"; break;
         case 843: return "Subphrase"; break;
         case 851: return "conditional_expression"; break;
         case 856: return "Subphrase"; break;
         case 866: return "constant_expression"; break;
         case 870: return "logical_OR_expression"; break;
         case 875: return "Subphrase"; break;
         case 883: return "logical_AND_expression"; break;
         case 888: return "Subphrase"; break;
         case 896: return "inclusive_OR_expression"; break;
         case 901: return "Subphrase"; break;
         case 909: return "exclusive_OR_expression"; break;
         case 914: return "Subphrase"; break;
         case 922: return "AND_expression"; break;
         case 927: return "Subphrase"; break;
         case 935: return "equality_expression"; break;
         case 940: return "Subphrase"; break;
         case 948: return "shift_expression"; break;
         case 953: return "Subphrase"; break;
         case 961: return "additive_expression"; break;
         case 966: return "Subphrase"; break;
         case 974: return "Subphrase"; break;
         case 982: return "multiplicative_expression"; break;
         case 987: return "Subphrase"; break;
         case 995: return "Subphrase"; break;
         case 1007: return "cast_expression"; break;
         case 1018: return "unary_expression"; break;
         case 1044: return "Subphrase"; break;
         case 1052: return "unary_operator"; break;
         case 1056: return "Subphrase"; break;
         case 1080: return "postfix_expression"; break;
         case 1089: return "Subphrase"; break;
         case 1119: return "Subphrase"; break;
         case 1126: return "primary_expression"; break;
         case 1144: return "argument_expression_list"; break;
         case 1149: return "Subphrase"; break;
         case 1157: return "constant"; break;
         case 1173: return "id"; break;
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
