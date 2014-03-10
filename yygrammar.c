#line 1 "ass2.acc"

	#include <stdio.h>
	#include <stdlib.h>
	
	#include "parser.h"

# line 9 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 123: {
      translation_unit();
      get_lexval();
      } break;
   }
}

translation_unit ()
{
   switch(yyselect()) {
   case 1: {
      external_declaration();
      } break;
   case 2: {
      translation_unit();
      external_declaration();
      } break;
   }
}

external_declaration ()
{
   switch(yyselect()) {
   case 3: {
      function_definition();
      } break;
   case 4: {
      declaration();
      } break;
   }
}

function_definition ()
{
   switch(yyselect()) {
   case 5: {
      switch (yyselect()) {
      case 124: {
         declaration_specifiers();
         } break;
      default: ;
      }
      declarator();
      switch (yyselect()) {
      case 125: {
         declaration_list();
         } break;
      default: ;
      }
      compound_statement();
#line 27 "ass2.acc"
 printf("found a function\n");
# line 67 "yygrammar.c"
      } break;
   }
}

declaration ()
{
   switch(yyselect()) {
   case 6: {
      declaration_specifiers();
      switch (yyselect()) {
      case 126: {
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
   case 7: {
      switch (yyselect()) {
      case 127: {
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
   case 8: {
      switch (yyselect()) {
      case 128: {
         storage_class_specifier();
         } break;
      case 129: {
         type_specifier();
#line 39 "ass2.acc"
printf("type specifier\n");
# line 115 "yygrammar.c"
         } break;
      case 130: {
         type_qualifier();
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 131: {
         declaration_specifiers();
         } break;
      default: ;
      }
#line 39 "ass2.acc"
printf("specifier:\n");
# line 130 "yygrammar.c"
      } break;
   }
}

storage_class_specifier ()
{
   switch(yyselect()) {
   case 9: {
      get_lexval();
      } break;
   case 10: {
      get_lexval();
      } break;
   case 11: {
      get_lexval();
      } break;
   case 12: {
      get_lexval();
      } break;
   case 13: {
      get_lexval();
      } break;
   }
}

type_specifier ()
{
   switch(yyselect()) {
   case 14: {
      get_lexval();
      } break;
   case 15: {
      get_lexval();
      } break;
   case 16: {
      get_lexval();
      } break;
   case 17: {
      get_lexval();
#line 47 "ass2.acc"
printf("Int found, ");
# line 172 "yygrammar.c"
      } break;
   case 18: {
      get_lexval();
      } break;
   case 19: {
      get_lexval();
      } break;
   case 20: {
      get_lexval();
      } break;
   case 21: {
      get_lexval();
      } break;
   case 22: {
      get_lexval();
#line 47 "ass2.acc"
printf("type specifier\n");
# line 190 "yygrammar.c"
      } break;
   case 23: {
      struct_or_union_specifier();
      } break;
   case 24: {
      enum_specifier();
      } break;
   }
}

type_qualifier ()
{
   switch(yyselect()) {
   case 25: {
      get_lexval();
      } break;
   case 26: {
      get_lexval();
      } break;
   }
}

struct_or_union_specifier ()
{
   switch(yyselect()) {
   case 27: {
      struct_or_union();
      switch (yyselect()) {
      case 132: {
         get_lexval();
         } break;
      default: ;
      }
      get_lexval();
      struct_declaration_list();
      get_lexval();
      } break;
   case 28: {
      struct_or_union();
      get_lexval();
      } break;
   }
}

struct_or_union ()
{
   switch(yyselect()) {
   case 29: {
      get_lexval();
      } break;
   case 30: {
      get_lexval();
      } break;
   }
}

struct_declaration_list ()
{
   switch(yyselect()) {
   case 31: {
      switch (yyselect()) {
      case 133: {
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
   case 32: {
      switch (yyselect()) {
      case 134: {
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
   case 33: {
      switch (yyselect()) {
      case 135: {
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
   case 34: {
      specifier_qualifier_list();
      struct_declarator_list();
      get_lexval();
      } break;
   }
}

specifier_qualifier_list ()
{
   switch(yyselect()) {
   case 35: {
      switch (yyselect()) {
      case 136: {
         type_specifier();
         } break;
      case 137: {
         type_qualifier();
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 138: {
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
   case 36: {
      switch (yyselect()) {
      case 139: {
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
   switch(yyselect()) {
   case 37: {
      declarator();
      } break;
   case 38: {
      switch (yyselect()) {
      case 140: {
         declarator();
         } break;
      default: ;
      }
      get_lexval();
      constant_expression();
      } break;
   }
}

enum_specifier ()
{
   switch(yyselect()) {
   case 39: {
      get_lexval();
      switch (yyselect()) {
      case 141: {
         get_lexval();
         } break;
      default: ;
      }
      get_lexval();
      enumerator_list();
      get_lexval();
      } break;
   case 40: {
      get_lexval();
      get_lexval();
      } break;
   }
}

enumerator_list ()
{
   switch(yyselect()) {
   case 41: {
      switch (yyselect()) {
      case 142: {
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
   switch(yyselect()) {
   case 42: {
      get_lexval();
      switch (yyselect()) {
      case 143: {
         get_lexval();
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
   case 43: {
      switch (yyselect()) {
      case 144: {
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
   case 44: {
      get_lexval();
#line 111 "ass2.acc"
printf("Identifier within declarator: %s\n", yylval.s);
# line 439 "yygrammar.c"
      } break;
   case 45: {
      get_lexval();
      declarator();
      get_lexval();
#line 112 "ass2.acc"
printf("iets met haakjes\n");
# line 447 "yygrammar.c"
      } break;
   case 46: {
      direct_declarator();
      switch (yyselect()) {
      case 146: {
         get_lexval();
         switch (yyselect()) {
         case 145: {
            constant_expression();
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 147: {
         get_lexval();
         parameter_type_list();
         get_lexval();
         } break;
      case 149: {
         get_lexval();
         switch (yyselect()) {
         case 148: {
            identifier_list();
            } break;
         default: ;
         }
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 113 "ass2.acc"
printf("nog iets met haakjes\n");
# line 481 "yygrammar.c"
      } break;
   }
}

pointer ()
{
   switch(yyselect()) {
   case 47: {
      get_lexval();
      switch (yyselect()) {
      case 150: {
         type_qualifier_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 151: {
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
   case 48: {
      switch (yyselect()) {
      case 152: {
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
   case 49: {
      parameter_list();
      switch (yyselect()) {
      case 153: {
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
   case 50: {
      switch (yyselect()) {
      case 154: {
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
   case 51: {
      declaration_specifiers();
      switch (yyselect()) {
      case 155: {
         declarator();
         } break;
      case 157: {
         switch (yyselect()) {
         case 156: {
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
   case 52: {
      switch (yyselect()) {
      case 158: {
         identifier_list();
         get_lexval();
         } break;
      default: ;
      }
      get_lexval();
      } break;
   }
}

initializer ()
{
   switch(yyselect()) {
   case 53: {
      assignment_expression();
      } break;
   case 54: {
      get_lexval();
      initializer_list();
      switch (yyselect()) {
      case 159: {
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
   case 55: {
      switch (yyselect()) {
      case 160: {
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
   case 56: {
      specifier_qualifier_list();
      switch (yyselect()) {
      case 161: {
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
   case 57: {
      pointer();
      } break;
   case 58: {
      switch (yyselect()) {
      case 162: {
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
   case 59: {
      get_lexval();
      abstract_declarator();
      get_lexval();
      } break;
   case 60: {
      switch (yyselect()) {
      case 163: {
         direct_abstract_declarator();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 165: {
         get_lexval();
         switch (yyselect()) {
         case 164: {
            constant_expression();
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 167: {
         get_lexval();
         switch (yyselect()) {
         case 166: {
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
   switch(yyselect()) {
   case 61: {
      get_lexval();
      } break;
   }
}

statement ()
{
   switch(yyselect()) {
   case 62: {
      labeled_statement();
      } break;
   case 63: {
      expression_statement();
      } break;
   case 64: {
      compound_statement();
      } break;
   case 65: {
      selection_statement();
      } break;
   case 66: {
      iteration_statement();
      } break;
   case 67: {
      jump_statement();
      } break;
   }
}

labeled_statement ()
{
   switch(yyselect()) {
   case 68: {
      get_lexval();
      get_lexval();
      statement();
      } break;
   case 69: {
      get_lexval();
      constant_expression();
      get_lexval();
      statement();
      } break;
   case 70: {
      get_lexval();
      get_lexval();
      statement();
      } break;
   }
}

expression_statement ()
{
   switch(yyselect()) {
   case 71: {
      switch (yyselect()) {
      case 168: {
         expression();
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
   case 72: {
      get_lexval();
      switch (yyselect()) {
      case 169: {
         declaration_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 170: {
         statement_list();
         } break;
      default: ;
      }
      get_lexval();
#line 187 "ass2.acc"
printf("Compound statement\n");
# line 794 "yygrammar.c"
      } break;
   }
}

statement_list ()
{
   switch(yyselect()) {
   case 73: {
      switch (yyselect()) {
      case 171: {
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
   case 74: {
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      statement();
      switch (yyselect()) {
      case 172: {
         get_lexval();
         statement();
         } break;
      default: ;
      }
      } break;
   case 75: {
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      statement();
      } break;
   }
}

iteration_statement ()
{
   switch(yyselect()) {
   case 76: {
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      statement();
      } break;
   case 77: {
      get_lexval();
      statement();
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      get_lexval();
      } break;
   case 78: {
      get_lexval();
      get_lexval();
      switch (yyselect()) {
      case 173: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
      switch (yyselect()) {
      case 174: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
      switch (yyselect()) {
      case 175: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
      statement();
      } break;
   }
}

jump_statement ()
{
   switch(yyselect()) {
   case 79: {
      get_lexval();
      get_lexval();
      get_lexval();
      } break;
   case 80: {
      get_lexval();
      get_lexval();
      } break;
   case 81: {
      get_lexval();
      get_lexval();
      } break;
   case 82: {
      get_lexval();
      switch (yyselect()) {
      case 176: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 209 "ass2.acc"
 printf("Return\n"); 
# line 916 "yygrammar.c"
      } break;
   }
}

expression ()
{
   switch(yyselect()) {
   case 83: {
      switch (yyselect()) {
      case 177: {
         expression();
         get_lexval();
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
   case 84: {
      conditional_expression();
      } break;
   case 85: {
      unary_expression();
      assignment_operator();
      assignment_expression();
      } break;
   }
}

assignment_operator ()
{
   switch(yyselect()) {
   case 86: {
      get_lexval();
      } break;
   case 87: {
      get_lexval();
      } break;
   }
}

conditional_expression ()
{
   switch(yyselect()) {
   case 88: {
      logical_OR_expression();
      switch (yyselect()) {
      case 178: {
         get_lexval();
         expression();
         get_lexval();
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
   case 89: {
      conditional_expression();
      } break;
   }
}

logical_OR_expression ()
{
   switch(yyselect()) {
   case 90: {
      switch (yyselect()) {
      case 179: {
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
   case 91: {
      switch (yyselect()) {
      case 180: {
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
   case 92: {
      switch (yyselect()) {
      case 181: {
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
   case 93: {
      switch (yyselect()) {
      case 182: {
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
   case 94: {
      switch (yyselect()) {
      case 183: {
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
   case 95: {
      switch (yyselect()) {
      case 184: {
         equality_expression();
         get_lexval();
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
   case 96: {
      switch (yyselect()) {
      case 185: {
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
   case 97: {
      switch (yyselect()) {
      case 188: {
         additive_expression();
         switch (yyselect()) {
         case 186: {
            get_lexval();
            } break;
         case 187: {
            get_lexval();
            } break;
         default: printf("???\n"); exit(1);
         }
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
   case 98: {
      switch (yyselect()) {
      case 192: {
         multiplicative_expression();
         switch (yyselect()) {
         case 189: {
            get_lexval();
            } break;
         case 190: {
            get_lexval();
            } break;
         case 191: {
            get_lexval();
            } break;
         default: printf("???\n"); exit(1);
         }
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
   case 99: {
      unary_expression();
      } break;
   case 100: {
      get_lexval();
      type_name();
      get_lexval();
      cast_expression();
      } break;
   }
}

unary_expression ()
{
   switch(yyselect()) {
   case 101: {
      postfix_expression();
      } break;
   case 102: {
      switch (yyselect()) {
      case 193: {
         get_lexval();
         } break;
      case 194: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
      unary_expression();
      } break;
   case 103: {
      unary_operator();
      cast_expression();
      } break;
   case 104: {
      get_lexval();
      unary_expression();
      } break;
   case 105: {
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
   case 106: {
      get_lexval();
      } break;
   case 107: {
      get_lexval();
      } break;
   case 108: {
      get_lexval();
      } break;
   case 109: {
      get_lexval();
      } break;
   case 110: {
      get_lexval();
      } break;
   case 111: {
      get_lexval();
      } break;
   }
}

postfix_expression ()
{
   switch(yyselect()) {
   case 112: {
      primary_expression();
      } break;
   case 113: {
      postfix_expression();
      switch (yyselect()) {
      case 195: {
         get_lexval();
         expression();
         get_lexval();
         } break;
      case 197: {
         get_lexval();
         switch (yyselect()) {
         case 196: {
            argument_expression_list();
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 198: {
         get_lexval();
         get_lexval();
         } break;
      case 199: {
         get_lexval();
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
      } break;
   }
}

primary_expression ()
{
   switch(yyselect()) {
   case 114: {
      get_lexval();
      } break;
   case 115: {
      constant();
      } break;
   case 116: {
      get_lexval();
      } break;
   case 117: {
      get_lexval();
      expression();
      get_lexval();
      } break;
   }
}

argument_expression_list ()
{
   switch(yyselect()) {
   case 118: {
      switch (yyselect()) {
      case 202: {
         argument_expression_list();
         get_lexval();
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
   case 119: {
      get_lexval();
#line 304 "ass2.acc"
printf("intconst: %lu\n", yylval.i);
# line 1314 "yygrammar.c"
      } break;
   case 120: {
      get_lexval();
      } break;
   case 121: {
      get_lexval();
      } break;
   case 122: {
      get_lexval();
#line 304 "ass2.acc"
 printf("Constant\n"); 
# line 1326 "yygrammar.c"
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
int c_length = 1131;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 123,
/* 6 */ 10,
/* 7 */ 15,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 0,
/* 11 */ 6,
/* 12 */ 15,
/* 13 */ -6,
/* 14 */ 2,
/* 15 */ 19,
/* 16 */ 23,
/* 17 */ -15,
/* 18 */ 3,
/* 19 */ 0,
/* 20 */ 44,
/* 21 */ -15,
/* 22 */ 4,
/* 23 */ 0,
/* 24 */ 30,
/* 25 */ 333,
/* 26 */ 37,
/* 27 */ 645,
/* 28 */ -23,
/* 29 */ 5,
/* 30 */ 34,
/* 31 */ 69,
/* 32 */ -30,
/* 33 */ 124,
/* 34 */ 0,
/* 35 */ -30,
/* 36 */ 203,
/* 37 */ 41,
/* 38 */ 57,
/* 39 */ -37,
/* 40 */ 125,
/* 41 */ 0,
/* 42 */ -37,
/* 43 */ 204,
/* 44 */ 0,
/* 45 */ 69,
/* 46 */ 50,
/* 47 */ 50059,
/* 48 */ -44,
/* 49 */ 6,
/* 50 */ 54,
/* 51 */ 205,
/* 52 */ -50,
/* 53 */ 126,
/* 54 */ 0,
/* 55 */ -50,
/* 56 */ 205,
/* 57 */ 0,
/* 58 */ 62,
/* 59 */ 44,
/* 60 */ -57,
/* 61 */ 7,
/* 62 */ 66,
/* 63 */ 57,
/* 64 */ -62,
/* 65 */ 127,
/* 66 */ 0,
/* 67 */ -62,
/* 68 */ 206,
/* 69 */ 0,
/* 70 */ 74,
/* 71 */ 86,
/* 72 */ -69,
/* 73 */ 8,
/* 74 */ 78,
/* 75 */ 93,
/* 76 */ -74,
/* 77 */ 128,
/* 78 */ 82,
/* 79 */ 113,
/* 80 */ -74,
/* 81 */ 129,
/* 82 */ 0,
/* 83 */ 157,
/* 84 */ -74,
/* 85 */ 130,
/* 86 */ 90,
/* 87 */ 69,
/* 88 */ -86,
/* 89 */ 131,
/* 90 */ 0,
/* 91 */ -86,
/* 92 */ 207,
/* 93 */ 97,
/* 94 */ 50256,
/* 95 */ -93,
/* 96 */ 9,
/* 97 */ 101,
/* 98 */ 50274,
/* 99 */ -93,
/* 100 */ 10,
/* 101 */ 105,
/* 102 */ 50279,
/* 103 */ -93,
/* 104 */ 11,
/* 105 */ 109,
/* 106 */ 50267,
/* 107 */ -93,
/* 108 */ 12,
/* 109 */ 0,
/* 110 */ 50282,
/* 111 */ -93,
/* 112 */ 13,
/* 113 */ 117,
/* 114 */ 50285,
/* 115 */ -113,
/* 116 */ 14,
/* 117 */ 121,
/* 118 */ 50259,
/* 119 */ -113,
/* 120 */ 15,
/* 121 */ 125,
/* 122 */ 50276,
/* 123 */ -113,
/* 124 */ 16,
/* 125 */ 129,
/* 126 */ 50272,
/* 127 */ -113,
/* 128 */ 17,
/* 129 */ 133,
/* 130 */ 50273,
/* 131 */ -113,
/* 132 */ 18,
/* 133 */ 137,
/* 134 */ 50268,
/* 135 */ -113,
/* 136 */ 19,
/* 137 */ 141,
/* 138 */ 50264,
/* 139 */ -113,
/* 140 */ 20,
/* 141 */ 145,
/* 142 */ 50277,
/* 143 */ -113,
/* 144 */ 21,
/* 145 */ 149,
/* 146 */ 50284,
/* 147 */ -113,
/* 148 */ 22,
/* 149 */ 153,
/* 150 */ 165,
/* 151 */ -113,
/* 152 */ 23,
/* 153 */ 0,
/* 154 */ 287,
/* 155 */ -113,
/* 156 */ 24,
/* 157 */ 161,
/* 158 */ 50260,
/* 159 */ -157,
/* 160 */ 25,
/* 161 */ 0,
/* 162 */ 50286,
/* 163 */ -157,
/* 164 */ 26,
/* 165 */ 173,
/* 166 */ 185,
/* 167 */ 178,
/* 168 */ 50123,
/* 169 */ 193,
/* 170 */ 50125,
/* 171 */ -165,
/* 172 */ 27,
/* 173 */ 0,
/* 174 */ 185,
/* 175 */ 50299,
/* 176 */ -165,
/* 177 */ 28,
/* 178 */ 182,
/* 179 */ 50299,
/* 180 */ -178,
/* 181 */ 132,
/* 182 */ 0,
/* 183 */ -178,
/* 184 */ 208,
/* 185 */ 189,
/* 186 */ 50280,
/* 187 */ -185,
/* 188 */ 29,
/* 189 */ 0,
/* 190 */ 50283,
/* 191 */ -185,
/* 192 */ 30,
/* 193 */ 0,
/* 194 */ 198,
/* 195 */ 231,
/* 196 */ -193,
/* 197 */ 31,
/* 198 */ 202,
/* 199 */ 193,
/* 200 */ -198,
/* 201 */ 133,
/* 202 */ 0,
/* 203 */ -198,
/* 204 */ 209,
/* 205 */ 0,
/* 206 */ 210,
/* 207 */ 218,
/* 208 */ -205,
/* 209 */ 32,
/* 210 */ 215,
/* 211 */ 205,
/* 212 */ 50044,
/* 213 */ -210,
/* 214 */ 134,
/* 215 */ 0,
/* 216 */ -210,
/* 217 */ 210,
/* 218 */ 0,
/* 219 */ 223,
/* 220 */ 483,
/* 221 */ -218,
/* 222 */ 33,
/* 223 */ 228,
/* 224 */ 333,
/* 225 */ 50061,
/* 226 */ -223,
/* 227 */ 135,
/* 228 */ 0,
/* 229 */ -223,
/* 230 */ 211,
/* 231 */ 0,
/* 232 */ 237,
/* 233 */ 257,
/* 234 */ 50059,
/* 235 */ -231,
/* 236 */ 34,
/* 237 */ 0,
/* 238 */ 242,
/* 239 */ 250,
/* 240 */ -237,
/* 241 */ 35,
/* 242 */ 246,
/* 243 */ 113,
/* 244 */ -242,
/* 245 */ 136,
/* 246 */ 0,
/* 247 */ 157,
/* 248 */ -242,
/* 249 */ 137,
/* 250 */ 254,
/* 251 */ 237,
/* 252 */ -250,
/* 253 */ 138,
/* 254 */ 0,
/* 255 */ -250,
/* 256 */ 212,
/* 257 */ 0,
/* 258 */ 262,
/* 259 */ 270,
/* 260 */ -257,
/* 261 */ 36,
/* 262 */ 267,
/* 263 */ 257,
/* 264 */ 50044,
/* 265 */ -262,
/* 266 */ 139,
/* 267 */ 0,
/* 268 */ -262,
/* 269 */ 213,
/* 270 */ 274,
/* 271 */ 333,
/* 272 */ -270,
/* 273 */ 37,
/* 274 */ 0,
/* 275 */ 280,
/* 276 */ 50058,
/* 277 */ 829,
/* 278 */ -270,
/* 279 */ 38,
/* 280 */ 284,
/* 281 */ 333,
/* 282 */ -280,
/* 283 */ 140,
/* 284 */ 0,
/* 285 */ -280,
/* 286 */ 214,
/* 287 */ 295,
/* 288 */ 50266,
/* 289 */ 300,
/* 290 */ 50123,
/* 291 */ 307,
/* 292 */ 50125,
/* 293 */ -287,
/* 294 */ 39,
/* 295 */ 0,
/* 296 */ 50266,
/* 297 */ 50299,
/* 298 */ -287,
/* 299 */ 40,
/* 300 */ 304,
/* 301 */ 50299,
/* 302 */ -300,
/* 303 */ 141,
/* 304 */ 0,
/* 305 */ -300,
/* 306 */ 215,
/* 307 */ 0,
/* 308 */ 312,
/* 309 */ 320,
/* 310 */ -307,
/* 311 */ 41,
/* 312 */ 317,
/* 313 */ 307,
/* 314 */ 50044,
/* 315 */ -312,
/* 316 */ 142,
/* 317 */ 0,
/* 318 */ -312,
/* 319 */ 216,
/* 320 */ 0,
/* 321 */ 50299,
/* 322 */ 325,
/* 323 */ -320,
/* 324 */ 42,
/* 325 */ 330,
/* 326 */ 50061,
/* 327 */ 829,
/* 328 */ -325,
/* 329 */ 143,
/* 330 */ 0,
/* 331 */ -325,
/* 332 */ 217,
/* 333 */ 0,
/* 334 */ 338,
/* 335 */ 345,
/* 336 */ -333,
/* 337 */ 43,
/* 338 */ 342,
/* 339 */ 392,
/* 340 */ -338,
/* 341 */ 144,
/* 342 */ 0,
/* 343 */ -338,
/* 344 */ 218,
/* 345 */ 349,
/* 346 */ 50299,
/* 347 */ -345,
/* 348 */ 44,
/* 349 */ 355,
/* 350 */ 50040,
/* 351 */ 333,
/* 352 */ 50041,
/* 353 */ -345,
/* 354 */ 45,
/* 355 */ 0,
/* 356 */ 345,
/* 357 */ 360,
/* 358 */ -345,
/* 359 */ 46,
/* 360 */ 366,
/* 361 */ 50091,
/* 362 */ 378,
/* 363 */ 50093,
/* 364 */ -360,
/* 365 */ 146,
/* 366 */ 372,
/* 367 */ 50040,
/* 368 */ 424,
/* 369 */ 50041,
/* 370 */ -360,
/* 371 */ 147,
/* 372 */ 0,
/* 373 */ 50040,
/* 374 */ 385,
/* 375 */ 50041,
/* 376 */ -360,
/* 377 */ 149,
/* 378 */ 382,
/* 379 */ 829,
/* 380 */ -378,
/* 381 */ 145,
/* 382 */ 0,
/* 383 */ -378,
/* 384 */ 219,
/* 385 */ 389,
/* 386 */ 470,
/* 387 */ -385,
/* 388 */ 148,
/* 389 */ 0,
/* 390 */ -385,
/* 391 */ 220,
/* 392 */ 0,
/* 393 */ 50042,
/* 394 */ 398,
/* 395 */ 405,
/* 396 */ -392,
/* 397 */ 47,
/* 398 */ 402,
/* 399 */ 412,
/* 400 */ -398,
/* 401 */ 150,
/* 402 */ 0,
/* 403 */ -398,
/* 404 */ 221,
/* 405 */ 409,
/* 406 */ 392,
/* 407 */ -405,
/* 408 */ 151,
/* 409 */ 0,
/* 410 */ -405,
/* 411 */ 222,
/* 412 */ 0,
/* 413 */ 417,
/* 414 */ 157,
/* 415 */ -412,
/* 416 */ 48,
/* 417 */ 421,
/* 418 */ 412,
/* 419 */ -417,
/* 420 */ 152,
/* 421 */ 0,
/* 422 */ -417,
/* 423 */ 223,
/* 424 */ 0,
/* 425 */ 437,
/* 426 */ 429,
/* 427 */ -424,
/* 428 */ 49,
/* 429 */ 434,
/* 430 */ 50044,
/* 431 */ 50290,
/* 432 */ -429,
/* 433 */ 153,
/* 434 */ 0,
/* 435 */ -429,
/* 436 */ 224,
/* 437 */ 0,
/* 438 */ 442,
/* 439 */ 450,
/* 440 */ -437,
/* 441 */ 50,
/* 442 */ 447,
/* 443 */ 437,
/* 444 */ 50044,
/* 445 */ -442,
/* 446 */ 154,
/* 447 */ 0,
/* 448 */ -442,
/* 449 */ 225,
/* 450 */ 0,
/* 451 */ 69,
/* 452 */ 455,
/* 453 */ -450,
/* 454 */ 51,
/* 455 */ 459,
/* 456 */ 333,
/* 457 */ -455,
/* 458 */ 155,
/* 459 */ 0,
/* 460 */ 463,
/* 461 */ -455,
/* 462 */ 157,
/* 463 */ 467,
/* 464 */ 526,
/* 465 */ -463,
/* 466 */ 156,
/* 467 */ 0,
/* 468 */ -463,
/* 469 */ 226,
/* 470 */ 0,
/* 471 */ 475,
/* 472 */ 50299,
/* 473 */ -470,
/* 474 */ 52,
/* 475 */ 480,
/* 476 */ 470,
/* 477 */ 50044,
/* 478 */ -475,
/* 479 */ 158,
/* 480 */ 0,
/* 481 */ -475,
/* 482 */ 227,
/* 483 */ 487,
/* 484 */ 796,
/* 485 */ -483,
/* 486 */ 53,
/* 487 */ 0,
/* 488 */ 50123,
/* 489 */ 501,
/* 490 */ 494,
/* 491 */ 50125,
/* 492 */ -483,
/* 493 */ 54,
/* 494 */ 498,
/* 495 */ 50044,
/* 496 */ -494,
/* 497 */ 159,
/* 498 */ 0,
/* 499 */ -494,
/* 500 */ 228,
/* 501 */ 0,
/* 502 */ 506,
/* 503 */ 483,
/* 504 */ -501,
/* 505 */ 55,
/* 506 */ 511,
/* 507 */ 501,
/* 508 */ 50044,
/* 509 */ -506,
/* 510 */ 160,
/* 511 */ 0,
/* 512 */ -506,
/* 513 */ 229,
/* 514 */ 0,
/* 515 */ 237,
/* 516 */ 519,
/* 517 */ -514,
/* 518 */ 56,
/* 519 */ 523,
/* 520 */ 526,
/* 521 */ -519,
/* 522 */ 161,
/* 523 */ 0,
/* 524 */ -519,
/* 525 */ 230,
/* 526 */ 530,
/* 527 */ 392,
/* 528 */ -526,
/* 529 */ 57,
/* 530 */ 0,
/* 531 */ 535,
/* 532 */ 542,
/* 533 */ -526,
/* 534 */ 58,
/* 535 */ 539,
/* 536 */ 392,
/* 537 */ -535,
/* 538 */ 162,
/* 539 */ 0,
/* 540 */ -535,
/* 541 */ 231,
/* 542 */ 548,
/* 543 */ 50040,
/* 544 */ 526,
/* 545 */ 50041,
/* 546 */ -542,
/* 547 */ 59,
/* 548 */ 0,
/* 549 */ 553,
/* 550 */ 560,
/* 551 */ -542,
/* 552 */ 60,
/* 553 */ 557,
/* 554 */ 542,
/* 555 */ -553,
/* 556 */ 163,
/* 557 */ 0,
/* 558 */ -553,
/* 559 */ 232,
/* 560 */ 566,
/* 561 */ 50091,
/* 562 */ 572,
/* 563 */ 50093,
/* 564 */ -560,
/* 565 */ 165,
/* 566 */ 0,
/* 567 */ 50040,
/* 568 */ 579,
/* 569 */ 50041,
/* 570 */ -560,
/* 571 */ 167,
/* 572 */ 576,
/* 573 */ 829,
/* 574 */ -572,
/* 575 */ 164,
/* 576 */ 0,
/* 577 */ -572,
/* 578 */ 233,
/* 579 */ 583,
/* 580 */ 424,
/* 581 */ -579,
/* 582 */ 166,
/* 583 */ 0,
/* 584 */ -579,
/* 585 */ 234,
/* 586 */ 0,
/* 587 */ 50299,
/* 588 */ -586,
/* 589 */ 61,
/* 590 */ 594,
/* 591 */ 614,
/* 592 */ -590,
/* 593 */ 62,
/* 594 */ 598,
/* 595 */ 633,
/* 596 */ -590,
/* 597 */ 63,
/* 598 */ 602,
/* 599 */ 645,
/* 600 */ -590,
/* 601 */ 64,
/* 602 */ 606,
/* 603 */ 678,
/* 604 */ -590,
/* 605 */ 65,
/* 606 */ 610,
/* 607 */ 703,
/* 608 */ -590,
/* 609 */ 66,
/* 610 */ 0,
/* 611 */ 754,
/* 612 */ -590,
/* 613 */ 67,
/* 614 */ 620,
/* 615 */ 50299,
/* 616 */ 50058,
/* 617 */ 590,
/* 618 */ -614,
/* 619 */ 68,
/* 620 */ 627,
/* 621 */ 50258,
/* 622 */ 829,
/* 623 */ 50058,
/* 624 */ 590,
/* 625 */ -614,
/* 626 */ 69,
/* 627 */ 0,
/* 628 */ 50262,
/* 629 */ 50058,
/* 630 */ 590,
/* 631 */ -614,
/* 632 */ 70,
/* 633 */ 0,
/* 634 */ 638,
/* 635 */ 50059,
/* 636 */ -633,
/* 637 */ 71,
/* 638 */ 642,
/* 639 */ 783,
/* 640 */ -638,
/* 641 */ 168,
/* 642 */ 0,
/* 643 */ -638,
/* 644 */ 235,
/* 645 */ 0,
/* 646 */ 50123,
/* 647 */ 652,
/* 648 */ 659,
/* 649 */ 50125,
/* 650 */ -645,
/* 651 */ 72,
/* 652 */ 656,
/* 653 */ 57,
/* 654 */ -652,
/* 655 */ 169,
/* 656 */ 0,
/* 657 */ -652,
/* 658 */ 236,
/* 659 */ 663,
/* 660 */ 666,
/* 661 */ -659,
/* 662 */ 170,
/* 663 */ 0,
/* 664 */ -659,
/* 665 */ 237,
/* 666 */ 0,
/* 667 */ 671,
/* 668 */ 590,
/* 669 */ -666,
/* 670 */ 73,
/* 671 */ 675,
/* 672 */ 666,
/* 673 */ -671,
/* 674 */ 171,
/* 675 */ 0,
/* 676 */ -671,
/* 677 */ 238,
/* 678 */ 687,
/* 679 */ 50271,
/* 680 */ 50040,
/* 681 */ 783,
/* 682 */ 50041,
/* 683 */ 590,
/* 684 */ 695,
/* 685 */ -678,
/* 686 */ 74,
/* 687 */ 0,
/* 688 */ 50281,
/* 689 */ 50040,
/* 690 */ 783,
/* 691 */ 50041,
/* 692 */ 590,
/* 693 */ -678,
/* 694 */ 75,
/* 695 */ 700,
/* 696 */ 50265,
/* 697 */ 590,
/* 698 */ -695,
/* 699 */ 172,
/* 700 */ 0,
/* 701 */ -695,
/* 702 */ 239,
/* 703 */ 711,
/* 704 */ 50287,
/* 705 */ 50040,
/* 706 */ 783,
/* 707 */ 50041,
/* 708 */ 590,
/* 709 */ -703,
/* 710 */ 76,
/* 711 */ 721,
/* 712 */ 50263,
/* 713 */ 590,
/* 714 */ 50287,
/* 715 */ 50040,
/* 716 */ 783,
/* 717 */ 50041,
/* 718 */ 50059,
/* 719 */ -703,
/* 720 */ 77,
/* 721 */ 0,
/* 722 */ 50269,
/* 723 */ 50040,
/* 724 */ 733,
/* 725 */ 50059,
/* 726 */ 740,
/* 727 */ 50059,
/* 728 */ 747,
/* 729 */ 50041,
/* 730 */ 590,
/* 731 */ -703,
/* 732 */ 78,
/* 733 */ 737,
/* 734 */ 783,
/* 735 */ -733,
/* 736 */ 173,
/* 737 */ 0,
/* 738 */ -733,
/* 739 */ 240,
/* 740 */ 744,
/* 741 */ 783,
/* 742 */ -740,
/* 743 */ 174,
/* 744 */ 0,
/* 745 */ -740,
/* 746 */ 241,
/* 747 */ 751,
/* 748 */ 783,
/* 749 */ -747,
/* 750 */ 175,
/* 751 */ 0,
/* 752 */ -747,
/* 753 */ 242,
/* 754 */ 760,
/* 755 */ 50270,
/* 756 */ 50299,
/* 757 */ 50059,
/* 758 */ -754,
/* 759 */ 79,
/* 760 */ 765,
/* 761 */ 50261,
/* 762 */ 50059,
/* 763 */ -754,
/* 764 */ 80,
/* 765 */ 770,
/* 766 */ 50257,
/* 767 */ 50059,
/* 768 */ -754,
/* 769 */ 81,
/* 770 */ 0,
/* 771 */ 50275,
/* 772 */ 776,
/* 773 */ 50059,
/* 774 */ -754,
/* 775 */ 82,
/* 776 */ 780,
/* 777 */ 783,
/* 778 */ -776,
/* 779 */ 176,
/* 780 */ 0,
/* 781 */ -776,
/* 782 */ 243,
/* 783 */ 0,
/* 784 */ 788,
/* 785 */ 796,
/* 786 */ -783,
/* 787 */ 83,
/* 788 */ 793,
/* 789 */ 783,
/* 790 */ 50044,
/* 791 */ -788,
/* 792 */ 177,
/* 793 */ 0,
/* 794 */ -788,
/* 795 */ 244,
/* 796 */ 800,
/* 797 */ 814,
/* 798 */ -796,
/* 799 */ 84,
/* 800 */ 0,
/* 801 */ 981,
/* 802 */ 806,
/* 803 */ 796,
/* 804 */ -796,
/* 805 */ 85,
/* 806 */ 810,
/* 807 */ 50291,
/* 808 */ -806,
/* 809 */ 86,
/* 810 */ 0,
/* 811 */ 50061,
/* 812 */ -806,
/* 813 */ 87,
/* 814 */ 0,
/* 815 */ 833,
/* 816 */ 819,
/* 817 */ -814,
/* 818 */ 88,
/* 819 */ 826,
/* 820 */ 50063,
/* 821 */ 783,
/* 822 */ 50058,
/* 823 */ 814,
/* 824 */ -819,
/* 825 */ 178,
/* 826 */ 0,
/* 827 */ -819,
/* 828 */ 245,
/* 829 */ 0,
/* 830 */ 814,
/* 831 */ -829,
/* 832 */ 89,
/* 833 */ 0,
/* 834 */ 838,
/* 835 */ 846,
/* 836 */ -833,
/* 837 */ 90,
/* 838 */ 843,
/* 839 */ 833,
/* 840 */ 50297,
/* 841 */ -838,
/* 842 */ 179,
/* 843 */ 0,
/* 844 */ -838,
/* 845 */ 246,
/* 846 */ 0,
/* 847 */ 851,
/* 848 */ 859,
/* 849 */ -846,
/* 850 */ 91,
/* 851 */ 856,
/* 852 */ 846,
/* 853 */ 50298,
/* 854 */ -851,
/* 855 */ 180,
/* 856 */ 0,
/* 857 */ -851,
/* 858 */ 247,
/* 859 */ 0,
/* 860 */ 864,
/* 861 */ 872,
/* 862 */ -859,
/* 863 */ 92,
/* 864 */ 869,
/* 865 */ 859,
/* 866 */ 50301,
/* 867 */ -864,
/* 868 */ 181,
/* 869 */ 0,
/* 870 */ -864,
/* 871 */ 248,
/* 872 */ 0,
/* 873 */ 877,
/* 874 */ 885,
/* 875 */ -872,
/* 876 */ 93,
/* 877 */ 882,
/* 878 */ 872,
/* 879 */ 50303,
/* 880 */ -877,
/* 881 */ 182,
/* 882 */ 0,
/* 883 */ -877,
/* 884 */ 249,
/* 885 */ 0,
/* 886 */ 890,
/* 887 */ 898,
/* 888 */ -885,
/* 889 */ 94,
/* 890 */ 895,
/* 891 */ 885,
/* 892 */ 50302,
/* 893 */ -890,
/* 894 */ 183,
/* 895 */ 0,
/* 896 */ -890,
/* 897 */ 250,
/* 898 */ 0,
/* 899 */ 903,
/* 900 */ 911,
/* 901 */ -898,
/* 902 */ 95,
/* 903 */ 908,
/* 904 */ 898,
/* 905 */ 50292,
/* 906 */ -903,
/* 907 */ 184,
/* 908 */ 0,
/* 909 */ -903,
/* 910 */ 251,
/* 911 */ 0,
/* 912 */ 916,
/* 913 */ 924,
/* 914 */ -911,
/* 915 */ 96,
/* 916 */ 921,
/* 917 */ 911,
/* 918 */ 50304,
/* 919 */ -916,
/* 920 */ 185,
/* 921 */ 0,
/* 922 */ -916,
/* 923 */ 252,
/* 924 */ 0,
/* 925 */ 929,
/* 926 */ 945,
/* 927 */ -924,
/* 928 */ 97,
/* 929 */ 934,
/* 930 */ 924,
/* 931 */ 937,
/* 932 */ -929,
/* 933 */ 188,
/* 934 */ 0,
/* 935 */ -929,
/* 936 */ 253,
/* 937 */ 941,
/* 938 */ 50043,
/* 939 */ -937,
/* 940 */ 186,
/* 941 */ 0,
/* 942 */ 50045,
/* 943 */ -937,
/* 944 */ 187,
/* 945 */ 0,
/* 946 */ 950,
/* 947 */ 970,
/* 948 */ -945,
/* 949 */ 98,
/* 950 */ 955,
/* 951 */ 945,
/* 952 */ 958,
/* 953 */ -950,
/* 954 */ 192,
/* 955 */ 0,
/* 956 */ -950,
/* 957 */ 254,
/* 958 */ 962,
/* 959 */ 50042,
/* 960 */ -958,
/* 961 */ 189,
/* 962 */ 966,
/* 963 */ 50047,
/* 964 */ -958,
/* 965 */ 190,
/* 966 */ 0,
/* 967 */ 50037,
/* 968 */ -958,
/* 969 */ 191,
/* 970 */ 974,
/* 971 */ 981,
/* 972 */ -970,
/* 973 */ 99,
/* 974 */ 0,
/* 975 */ 50040,
/* 976 */ 514,
/* 977 */ 50041,
/* 978 */ 970,
/* 979 */ -970,
/* 980 */ 100,
/* 981 */ 985,
/* 982 */ 1039,
/* 983 */ -981,
/* 984 */ 101,
/* 985 */ 990,
/* 986 */ 1007,
/* 987 */ 981,
/* 988 */ -981,
/* 989 */ 102,
/* 990 */ 995,
/* 991 */ 1015,
/* 992 */ 970,
/* 993 */ -981,
/* 994 */ 103,
/* 995 */ 1000,
/* 996 */ 50278,
/* 997 */ 981,
/* 998 */ -981,
/* 999 */ 104,
/* 1000 */ 0,
/* 1001 */ 50278,
/* 1002 */ 50040,
/* 1003 */ 514,
/* 1004 */ 50041,
/* 1005 */ -981,
/* 1006 */ 105,
/* 1007 */ 1011,
/* 1008 */ 50294,
/* 1009 */ -1007,
/* 1010 */ 193,
/* 1011 */ 0,
/* 1012 */ 50295,
/* 1013 */ -1007,
/* 1014 */ 194,
/* 1015 */ 1019,
/* 1016 */ 50038,
/* 1017 */ -1015,
/* 1018 */ 106,
/* 1019 */ 1023,
/* 1020 */ 50042,
/* 1021 */ -1015,
/* 1022 */ 107,
/* 1023 */ 1027,
/* 1024 */ 50043,
/* 1025 */ -1015,
/* 1026 */ 108,
/* 1027 */ 1031,
/* 1028 */ 50045,
/* 1029 */ -1015,
/* 1030 */ 109,
/* 1031 */ 1035,
/* 1032 */ 50126,
/* 1033 */ -1015,
/* 1034 */ 110,
/* 1035 */ 0,
/* 1036 */ 50033,
/* 1037 */ -1015,
/* 1038 */ 111,
/* 1039 */ 1043,
/* 1040 */ 1085,
/* 1041 */ -1039,
/* 1042 */ 112,
/* 1043 */ 0,
/* 1044 */ 1039,
/* 1045 */ 1048,
/* 1046 */ -1039,
/* 1047 */ 113,
/* 1048 */ 1054,
/* 1049 */ 50091,
/* 1050 */ 783,
/* 1051 */ 50093,
/* 1052 */ -1048,
/* 1053 */ 195,
/* 1054 */ 1060,
/* 1055 */ 50040,
/* 1056 */ 1078,
/* 1057 */ 50041,
/* 1058 */ -1048,
/* 1059 */ 197,
/* 1060 */ 1065,
/* 1061 */ 50046,
/* 1062 */ 50299,
/* 1063 */ -1048,
/* 1064 */ 198,
/* 1065 */ 1070,
/* 1066 */ 50296,
/* 1067 */ 50299,
/* 1068 */ -1048,
/* 1069 */ 199,
/* 1070 */ 1074,
/* 1071 */ 50294,
/* 1072 */ -1048,
/* 1073 */ 200,
/* 1074 */ 0,
/* 1075 */ 50295,
/* 1076 */ -1048,
/* 1077 */ 201,
/* 1078 */ 1082,
/* 1079 */ 1103,
/* 1080 */ -1078,
/* 1081 */ 196,
/* 1082 */ 0,
/* 1083 */ -1078,
/* 1084 */ 255,
/* 1085 */ 1089,
/* 1086 */ 50299,
/* 1087 */ -1085,
/* 1088 */ 114,
/* 1089 */ 1093,
/* 1090 */ 1116,
/* 1091 */ -1085,
/* 1092 */ 115,
/* 1093 */ 1097,
/* 1094 */ 50289,
/* 1095 */ -1085,
/* 1096 */ 116,
/* 1097 */ 0,
/* 1098 */ 50040,
/* 1099 */ 783,
/* 1100 */ 50041,
/* 1101 */ -1085,
/* 1102 */ 117,
/* 1103 */ 0,
/* 1104 */ 1108,
/* 1105 */ 796,
/* 1106 */ -1103,
/* 1107 */ 118,
/* 1108 */ 1113,
/* 1109 */ 1103,
/* 1110 */ 50044,
/* 1111 */ -1108,
/* 1112 */ 202,
/* 1113 */ 0,
/* 1114 */ -1108,
/* 1115 */ 256,
/* 1116 */ 1120,
/* 1117 */ 50308,
/* 1118 */ -1116,
/* 1119 */ 119,
/* 1120 */ 1124,
/* 1121 */ 50306,
/* 1122 */ -1116,
/* 1123 */ 120,
/* 1124 */ 1128,
/* 1125 */ 50307,
/* 1126 */ -1116,
/* 1127 */ 121,
/* 1128 */ 0,
/* 1129 */ 50299,
/* 1130 */ -1116,
/* 1131 */ 122,
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
/* 12 */ 1,
/* 13 */ -6,
/* 14 */ 2,
/* 15 */ 19,
/* 16 */ 1,
/* 17 */ -15,
/* 18 */ 1,
/* 19 */ 0,
/* 20 */ 1,
/* 21 */ -15,
/* 22 */ 2,
/* 23 */ 0,
/* 24 */ 1,
/* 25 */ 1,
/* 26 */ 1,
/* 27 */ 1,
/* 28 */ -23,
/* 29 */ 1,
/* 30 */ 34,
/* 31 */ 1,
/* 32 */ -30,
/* 33 */ 1,
/* 34 */ 0,
/* 35 */ -30,
/* 36 */ 2,
/* 37 */ 41,
/* 38 */ 1,
/* 39 */ -37,
/* 40 */ 1,
/* 41 */ 0,
/* 42 */ -37,
/* 43 */ 2,
/* 44 */ 0,
/* 45 */ 1,
/* 46 */ 1,
/* 47 */ 50059,
/* 48 */ -44,
/* 49 */ 1,
/* 50 */ 54,
/* 51 */ 1,
/* 52 */ -50,
/* 53 */ 1,
/* 54 */ 0,
/* 55 */ -50,
/* 56 */ 2,
/* 57 */ 0,
/* 58 */ 1,
/* 59 */ 1,
/* 60 */ -57,
/* 61 */ 1,
/* 62 */ 66,
/* 63 */ 1,
/* 64 */ -62,
/* 65 */ 1,
/* 66 */ 0,
/* 67 */ -62,
/* 68 */ 2,
/* 69 */ 0,
/* 70 */ 1,
/* 71 */ 1,
/* 72 */ -69,
/* 73 */ 1,
/* 74 */ 78,
/* 75 */ 1,
/* 76 */ -74,
/* 77 */ 1,
/* 78 */ 82,
/* 79 */ 1,
/* 80 */ -74,
/* 81 */ 2,
/* 82 */ 0,
/* 83 */ 1,
/* 84 */ -74,
/* 85 */ 3,
/* 86 */ 90,
/* 87 */ 1,
/* 88 */ -86,
/* 89 */ 1,
/* 90 */ 0,
/* 91 */ -86,
/* 92 */ 2,
/* 93 */ 97,
/* 94 */ 50256,
/* 95 */ -93,
/* 96 */ 1,
/* 97 */ 101,
/* 98 */ 50274,
/* 99 */ -93,
/* 100 */ 2,
/* 101 */ 105,
/* 102 */ 50279,
/* 103 */ -93,
/* 104 */ 3,
/* 105 */ 109,
/* 106 */ 50267,
/* 107 */ -93,
/* 108 */ 4,
/* 109 */ 0,
/* 110 */ 50282,
/* 111 */ -93,
/* 112 */ 5,
/* 113 */ 117,
/* 114 */ 50285,
/* 115 */ -113,
/* 116 */ 1,
/* 117 */ 121,
/* 118 */ 50259,
/* 119 */ -113,
/* 120 */ 2,
/* 121 */ 125,
/* 122 */ 50276,
/* 123 */ -113,
/* 124 */ 3,
/* 125 */ 129,
/* 126 */ 50272,
/* 127 */ -113,
/* 128 */ 4,
/* 129 */ 133,
/* 130 */ 50273,
/* 131 */ -113,
/* 132 */ 5,
/* 133 */ 137,
/* 134 */ 50268,
/* 135 */ -113,
/* 136 */ 6,
/* 137 */ 141,
/* 138 */ 50264,
/* 139 */ -113,
/* 140 */ 7,
/* 141 */ 145,
/* 142 */ 50277,
/* 143 */ -113,
/* 144 */ 8,
/* 145 */ 149,
/* 146 */ 50284,
/* 147 */ -113,
/* 148 */ 9,
/* 149 */ 153,
/* 150 */ 1,
/* 151 */ -113,
/* 152 */ 10,
/* 153 */ 0,
/* 154 */ 1,
/* 155 */ -113,
/* 156 */ 11,
/* 157 */ 161,
/* 158 */ 50260,
/* 159 */ -157,
/* 160 */ 1,
/* 161 */ 0,
/* 162 */ 50286,
/* 163 */ -157,
/* 164 */ 2,
/* 165 */ 173,
/* 166 */ 1,
/* 167 */ 1,
/* 168 */ 50123,
/* 169 */ 1,
/* 170 */ 50125,
/* 171 */ -165,
/* 172 */ 1,
/* 173 */ 0,
/* 174 */ 1,
/* 175 */ 50299,
/* 176 */ -165,
/* 177 */ 2,
/* 178 */ 182,
/* 179 */ 50299,
/* 180 */ -178,
/* 181 */ 1,
/* 182 */ 0,
/* 183 */ -178,
/* 184 */ 2,
/* 185 */ 189,
/* 186 */ 50280,
/* 187 */ -185,
/* 188 */ 1,
/* 189 */ 0,
/* 190 */ 50283,
/* 191 */ -185,
/* 192 */ 2,
/* 193 */ 0,
/* 194 */ 1,
/* 195 */ 1,
/* 196 */ -193,
/* 197 */ 1,
/* 198 */ 202,
/* 199 */ 1,
/* 200 */ -198,
/* 201 */ 1,
/* 202 */ 0,
/* 203 */ -198,
/* 204 */ 2,
/* 205 */ 0,
/* 206 */ 1,
/* 207 */ 1,
/* 208 */ -205,
/* 209 */ 1,
/* 210 */ 215,
/* 211 */ 1,
/* 212 */ 50044,
/* 213 */ -210,
/* 214 */ 1,
/* 215 */ 0,
/* 216 */ -210,
/* 217 */ 2,
/* 218 */ 0,
/* 219 */ 1,
/* 220 */ 1,
/* 221 */ -218,
/* 222 */ 1,
/* 223 */ 228,
/* 224 */ 1,
/* 225 */ 50061,
/* 226 */ -223,
/* 227 */ 1,
/* 228 */ 0,
/* 229 */ -223,
/* 230 */ 2,
/* 231 */ 0,
/* 232 */ 1,
/* 233 */ 1,
/* 234 */ 50059,
/* 235 */ -231,
/* 236 */ 1,
/* 237 */ 0,
/* 238 */ 1,
/* 239 */ 1,
/* 240 */ -237,
/* 241 */ 1,
/* 242 */ 246,
/* 243 */ 1,
/* 244 */ -242,
/* 245 */ 1,
/* 246 */ 0,
/* 247 */ 1,
/* 248 */ -242,
/* 249 */ 2,
/* 250 */ 254,
/* 251 */ 1,
/* 252 */ -250,
/* 253 */ 1,
/* 254 */ 0,
/* 255 */ -250,
/* 256 */ 2,
/* 257 */ 0,
/* 258 */ 1,
/* 259 */ 1,
/* 260 */ -257,
/* 261 */ 1,
/* 262 */ 267,
/* 263 */ 1,
/* 264 */ 50044,
/* 265 */ -262,
/* 266 */ 1,
/* 267 */ 0,
/* 268 */ -262,
/* 269 */ 2,
/* 270 */ 274,
/* 271 */ 1,
/* 272 */ -270,
/* 273 */ 1,
/* 274 */ 0,
/* 275 */ 1,
/* 276 */ 50058,
/* 277 */ 1,
/* 278 */ -270,
/* 279 */ 2,
/* 280 */ 284,
/* 281 */ 1,
/* 282 */ -280,
/* 283 */ 1,
/* 284 */ 0,
/* 285 */ -280,
/* 286 */ 2,
/* 287 */ 295,
/* 288 */ 50266,
/* 289 */ 1,
/* 290 */ 50123,
/* 291 */ 1,
/* 292 */ 50125,
/* 293 */ -287,
/* 294 */ 1,
/* 295 */ 0,
/* 296 */ 50266,
/* 297 */ 50299,
/* 298 */ -287,
/* 299 */ 2,
/* 300 */ 304,
/* 301 */ 50299,
/* 302 */ -300,
/* 303 */ 1,
/* 304 */ 0,
/* 305 */ -300,
/* 306 */ 2,
/* 307 */ 0,
/* 308 */ 1,
/* 309 */ 1,
/* 310 */ -307,
/* 311 */ 1,
/* 312 */ 317,
/* 313 */ 1,
/* 314 */ 50044,
/* 315 */ -312,
/* 316 */ 1,
/* 317 */ 0,
/* 318 */ -312,
/* 319 */ 2,
/* 320 */ 0,
/* 321 */ 50299,
/* 322 */ 1,
/* 323 */ -320,
/* 324 */ 1,
/* 325 */ 330,
/* 326 */ 50061,
/* 327 */ 1,
/* 328 */ -325,
/* 329 */ 1,
/* 330 */ 0,
/* 331 */ -325,
/* 332 */ 2,
/* 333 */ 0,
/* 334 */ 1,
/* 335 */ 1,
/* 336 */ -333,
/* 337 */ 1,
/* 338 */ 342,
/* 339 */ 1,
/* 340 */ -338,
/* 341 */ 1,
/* 342 */ 0,
/* 343 */ -338,
/* 344 */ 2,
/* 345 */ 349,
/* 346 */ 50299,
/* 347 */ -345,
/* 348 */ 1,
/* 349 */ 355,
/* 350 */ 50040,
/* 351 */ 1,
/* 352 */ 50041,
/* 353 */ -345,
/* 354 */ 2,
/* 355 */ 0,
/* 356 */ 1,
/* 357 */ 1,
/* 358 */ -345,
/* 359 */ 3,
/* 360 */ 366,
/* 361 */ 50091,
/* 362 */ 1,
/* 363 */ 50093,
/* 364 */ -360,
/* 365 */ 1,
/* 366 */ 372,
/* 367 */ 50040,
/* 368 */ 1,
/* 369 */ 50041,
/* 370 */ -360,
/* 371 */ 2,
/* 372 */ 0,
/* 373 */ 50040,
/* 374 */ 1,
/* 375 */ 50041,
/* 376 */ -360,
/* 377 */ 3,
/* 378 */ 382,
/* 379 */ 1,
/* 380 */ -378,
/* 381 */ 1,
/* 382 */ 0,
/* 383 */ -378,
/* 384 */ 2,
/* 385 */ 389,
/* 386 */ 1,
/* 387 */ -385,
/* 388 */ 1,
/* 389 */ 0,
/* 390 */ -385,
/* 391 */ 2,
/* 392 */ 0,
/* 393 */ 50042,
/* 394 */ 1,
/* 395 */ 1,
/* 396 */ -392,
/* 397 */ 1,
/* 398 */ 402,
/* 399 */ 1,
/* 400 */ -398,
/* 401 */ 1,
/* 402 */ 0,
/* 403 */ -398,
/* 404 */ 2,
/* 405 */ 409,
/* 406 */ 1,
/* 407 */ -405,
/* 408 */ 1,
/* 409 */ 0,
/* 410 */ -405,
/* 411 */ 2,
/* 412 */ 0,
/* 413 */ 1,
/* 414 */ 1,
/* 415 */ -412,
/* 416 */ 1,
/* 417 */ 421,
/* 418 */ 1,
/* 419 */ -417,
/* 420 */ 1,
/* 421 */ 0,
/* 422 */ -417,
/* 423 */ 2,
/* 424 */ 0,
/* 425 */ 1,
/* 426 */ 1,
/* 427 */ -424,
/* 428 */ 1,
/* 429 */ 434,
/* 430 */ 50044,
/* 431 */ 50290,
/* 432 */ -429,
/* 433 */ 1,
/* 434 */ 0,
/* 435 */ -429,
/* 436 */ 2,
/* 437 */ 0,
/* 438 */ 1,
/* 439 */ 1,
/* 440 */ -437,
/* 441 */ 1,
/* 442 */ 447,
/* 443 */ 1,
/* 444 */ 50044,
/* 445 */ -442,
/* 446 */ 1,
/* 447 */ 0,
/* 448 */ -442,
/* 449 */ 2,
/* 450 */ 0,
/* 451 */ 1,
/* 452 */ 1,
/* 453 */ -450,
/* 454 */ 1,
/* 455 */ 459,
/* 456 */ 1,
/* 457 */ -455,
/* 458 */ 1,
/* 459 */ 0,
/* 460 */ 1,
/* 461 */ -455,
/* 462 */ 2,
/* 463 */ 467,
/* 464 */ 1,
/* 465 */ -463,
/* 466 */ 1,
/* 467 */ 0,
/* 468 */ -463,
/* 469 */ 2,
/* 470 */ 0,
/* 471 */ 1,
/* 472 */ 50299,
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
/* 483 */ 487,
/* 484 */ 1,
/* 485 */ -483,
/* 486 */ 1,
/* 487 */ 0,
/* 488 */ 50123,
/* 489 */ 1,
/* 490 */ 1,
/* 491 */ 50125,
/* 492 */ -483,
/* 493 */ 2,
/* 494 */ 498,
/* 495 */ 50044,
/* 496 */ -494,
/* 497 */ 1,
/* 498 */ 0,
/* 499 */ -494,
/* 500 */ 2,
/* 501 */ 0,
/* 502 */ 1,
/* 503 */ 1,
/* 504 */ -501,
/* 505 */ 1,
/* 506 */ 511,
/* 507 */ 1,
/* 508 */ 50044,
/* 509 */ -506,
/* 510 */ 1,
/* 511 */ 0,
/* 512 */ -506,
/* 513 */ 2,
/* 514 */ 0,
/* 515 */ 1,
/* 516 */ 1,
/* 517 */ -514,
/* 518 */ 1,
/* 519 */ 523,
/* 520 */ 1,
/* 521 */ -519,
/* 522 */ 1,
/* 523 */ 0,
/* 524 */ -519,
/* 525 */ 2,
/* 526 */ 530,
/* 527 */ 1,
/* 528 */ -526,
/* 529 */ 1,
/* 530 */ 0,
/* 531 */ 1,
/* 532 */ 1,
/* 533 */ -526,
/* 534 */ 2,
/* 535 */ 539,
/* 536 */ 1,
/* 537 */ -535,
/* 538 */ 1,
/* 539 */ 0,
/* 540 */ -535,
/* 541 */ 2,
/* 542 */ 548,
/* 543 */ 50040,
/* 544 */ 1,
/* 545 */ 50041,
/* 546 */ -542,
/* 547 */ 1,
/* 548 */ 0,
/* 549 */ 1,
/* 550 */ 1,
/* 551 */ -542,
/* 552 */ 2,
/* 553 */ 557,
/* 554 */ 1,
/* 555 */ -553,
/* 556 */ 1,
/* 557 */ 0,
/* 558 */ -553,
/* 559 */ 2,
/* 560 */ 566,
/* 561 */ 50091,
/* 562 */ 1,
/* 563 */ 50093,
/* 564 */ -560,
/* 565 */ 1,
/* 566 */ 0,
/* 567 */ 50040,
/* 568 */ 1,
/* 569 */ 50041,
/* 570 */ -560,
/* 571 */ 2,
/* 572 */ 576,
/* 573 */ 1,
/* 574 */ -572,
/* 575 */ 1,
/* 576 */ 0,
/* 577 */ -572,
/* 578 */ 2,
/* 579 */ 583,
/* 580 */ 1,
/* 581 */ -579,
/* 582 */ 1,
/* 583 */ 0,
/* 584 */ -579,
/* 585 */ 2,
/* 586 */ 0,
/* 587 */ 50299,
/* 588 */ -586,
/* 589 */ 1,
/* 590 */ 594,
/* 591 */ 1,
/* 592 */ -590,
/* 593 */ 1,
/* 594 */ 598,
/* 595 */ 1,
/* 596 */ -590,
/* 597 */ 2,
/* 598 */ 602,
/* 599 */ 1,
/* 600 */ -590,
/* 601 */ 3,
/* 602 */ 606,
/* 603 */ 1,
/* 604 */ -590,
/* 605 */ 4,
/* 606 */ 610,
/* 607 */ 1,
/* 608 */ -590,
/* 609 */ 5,
/* 610 */ 0,
/* 611 */ 1,
/* 612 */ -590,
/* 613 */ 6,
/* 614 */ 620,
/* 615 */ 50299,
/* 616 */ 50058,
/* 617 */ 1,
/* 618 */ -614,
/* 619 */ 1,
/* 620 */ 627,
/* 621 */ 50258,
/* 622 */ 1,
/* 623 */ 50058,
/* 624 */ 1,
/* 625 */ -614,
/* 626 */ 2,
/* 627 */ 0,
/* 628 */ 50262,
/* 629 */ 50058,
/* 630 */ 1,
/* 631 */ -614,
/* 632 */ 3,
/* 633 */ 0,
/* 634 */ 1,
/* 635 */ 50059,
/* 636 */ -633,
/* 637 */ 1,
/* 638 */ 642,
/* 639 */ 1,
/* 640 */ -638,
/* 641 */ 1,
/* 642 */ 0,
/* 643 */ -638,
/* 644 */ 2,
/* 645 */ 0,
/* 646 */ 50123,
/* 647 */ 1,
/* 648 */ 1,
/* 649 */ 50125,
/* 650 */ -645,
/* 651 */ 1,
/* 652 */ 656,
/* 653 */ 1,
/* 654 */ -652,
/* 655 */ 1,
/* 656 */ 0,
/* 657 */ -652,
/* 658 */ 2,
/* 659 */ 663,
/* 660 */ 1,
/* 661 */ -659,
/* 662 */ 1,
/* 663 */ 0,
/* 664 */ -659,
/* 665 */ 2,
/* 666 */ 0,
/* 667 */ 1,
/* 668 */ 1,
/* 669 */ -666,
/* 670 */ 1,
/* 671 */ 675,
/* 672 */ 1,
/* 673 */ -671,
/* 674 */ 1,
/* 675 */ 0,
/* 676 */ -671,
/* 677 */ 2,
/* 678 */ 687,
/* 679 */ 50271,
/* 680 */ 50040,
/* 681 */ 1,
/* 682 */ 50041,
/* 683 */ 1,
/* 684 */ 1,
/* 685 */ -678,
/* 686 */ 1,
/* 687 */ 0,
/* 688 */ 50281,
/* 689 */ 50040,
/* 690 */ 1,
/* 691 */ 50041,
/* 692 */ 1,
/* 693 */ -678,
/* 694 */ 2,
/* 695 */ 700,
/* 696 */ 50265,
/* 697 */ 1,
/* 698 */ -695,
/* 699 */ 1,
/* 700 */ 0,
/* 701 */ -695,
/* 702 */ 2,
/* 703 */ 711,
/* 704 */ 50287,
/* 705 */ 50040,
/* 706 */ 1,
/* 707 */ 50041,
/* 708 */ 1,
/* 709 */ -703,
/* 710 */ 1,
/* 711 */ 721,
/* 712 */ 50263,
/* 713 */ 1,
/* 714 */ 50287,
/* 715 */ 50040,
/* 716 */ 1,
/* 717 */ 50041,
/* 718 */ 50059,
/* 719 */ -703,
/* 720 */ 2,
/* 721 */ 0,
/* 722 */ 50269,
/* 723 */ 50040,
/* 724 */ 1,
/* 725 */ 50059,
/* 726 */ 1,
/* 727 */ 50059,
/* 728 */ 1,
/* 729 */ 50041,
/* 730 */ 1,
/* 731 */ -703,
/* 732 */ 3,
/* 733 */ 737,
/* 734 */ 1,
/* 735 */ -733,
/* 736 */ 1,
/* 737 */ 0,
/* 738 */ -733,
/* 739 */ 2,
/* 740 */ 744,
/* 741 */ 1,
/* 742 */ -740,
/* 743 */ 1,
/* 744 */ 0,
/* 745 */ -740,
/* 746 */ 2,
/* 747 */ 751,
/* 748 */ 1,
/* 749 */ -747,
/* 750 */ 1,
/* 751 */ 0,
/* 752 */ -747,
/* 753 */ 2,
/* 754 */ 760,
/* 755 */ 50270,
/* 756 */ 50299,
/* 757 */ 50059,
/* 758 */ -754,
/* 759 */ 1,
/* 760 */ 765,
/* 761 */ 50261,
/* 762 */ 50059,
/* 763 */ -754,
/* 764 */ 2,
/* 765 */ 770,
/* 766 */ 50257,
/* 767 */ 50059,
/* 768 */ -754,
/* 769 */ 3,
/* 770 */ 0,
/* 771 */ 50275,
/* 772 */ 1,
/* 773 */ 50059,
/* 774 */ -754,
/* 775 */ 4,
/* 776 */ 780,
/* 777 */ 1,
/* 778 */ -776,
/* 779 */ 1,
/* 780 */ 0,
/* 781 */ -776,
/* 782 */ 2,
/* 783 */ 0,
/* 784 */ 1,
/* 785 */ 1,
/* 786 */ -783,
/* 787 */ 1,
/* 788 */ 793,
/* 789 */ 1,
/* 790 */ 50044,
/* 791 */ -788,
/* 792 */ 1,
/* 793 */ 0,
/* 794 */ -788,
/* 795 */ 2,
/* 796 */ 800,
/* 797 */ 1,
/* 798 */ -796,
/* 799 */ 1,
/* 800 */ 0,
/* 801 */ 1,
/* 802 */ 1,
/* 803 */ 1,
/* 804 */ -796,
/* 805 */ 2,
/* 806 */ 810,
/* 807 */ 50291,
/* 808 */ -806,
/* 809 */ 1,
/* 810 */ 0,
/* 811 */ 50061,
/* 812 */ -806,
/* 813 */ 2,
/* 814 */ 0,
/* 815 */ 1,
/* 816 */ 1,
/* 817 */ -814,
/* 818 */ 1,
/* 819 */ 826,
/* 820 */ 50063,
/* 821 */ 1,
/* 822 */ 50058,
/* 823 */ 1,
/* 824 */ -819,
/* 825 */ 1,
/* 826 */ 0,
/* 827 */ -819,
/* 828 */ 2,
/* 829 */ 0,
/* 830 */ 1,
/* 831 */ -829,
/* 832 */ 1,
/* 833 */ 0,
/* 834 */ 1,
/* 835 */ 1,
/* 836 */ -833,
/* 837 */ 1,
/* 838 */ 843,
/* 839 */ 1,
/* 840 */ 50297,
/* 841 */ -838,
/* 842 */ 1,
/* 843 */ 0,
/* 844 */ -838,
/* 845 */ 2,
/* 846 */ 0,
/* 847 */ 1,
/* 848 */ 1,
/* 849 */ -846,
/* 850 */ 1,
/* 851 */ 856,
/* 852 */ 1,
/* 853 */ 50298,
/* 854 */ -851,
/* 855 */ 1,
/* 856 */ 0,
/* 857 */ -851,
/* 858 */ 2,
/* 859 */ 0,
/* 860 */ 1,
/* 861 */ 1,
/* 862 */ -859,
/* 863 */ 1,
/* 864 */ 869,
/* 865 */ 1,
/* 866 */ 50301,
/* 867 */ -864,
/* 868 */ 1,
/* 869 */ 0,
/* 870 */ -864,
/* 871 */ 2,
/* 872 */ 0,
/* 873 */ 1,
/* 874 */ 1,
/* 875 */ -872,
/* 876 */ 1,
/* 877 */ 882,
/* 878 */ 1,
/* 879 */ 50303,
/* 880 */ -877,
/* 881 */ 1,
/* 882 */ 0,
/* 883 */ -877,
/* 884 */ 2,
/* 885 */ 0,
/* 886 */ 1,
/* 887 */ 1,
/* 888 */ -885,
/* 889 */ 1,
/* 890 */ 895,
/* 891 */ 1,
/* 892 */ 50302,
/* 893 */ -890,
/* 894 */ 1,
/* 895 */ 0,
/* 896 */ -890,
/* 897 */ 2,
/* 898 */ 0,
/* 899 */ 1,
/* 900 */ 1,
/* 901 */ -898,
/* 902 */ 1,
/* 903 */ 908,
/* 904 */ 1,
/* 905 */ 50292,
/* 906 */ -903,
/* 907 */ 1,
/* 908 */ 0,
/* 909 */ -903,
/* 910 */ 2,
/* 911 */ 0,
/* 912 */ 1,
/* 913 */ 1,
/* 914 */ -911,
/* 915 */ 1,
/* 916 */ 921,
/* 917 */ 1,
/* 918 */ 50304,
/* 919 */ -916,
/* 920 */ 1,
/* 921 */ 0,
/* 922 */ -916,
/* 923 */ 2,
/* 924 */ 0,
/* 925 */ 1,
/* 926 */ 1,
/* 927 */ -924,
/* 928 */ 1,
/* 929 */ 934,
/* 930 */ 1,
/* 931 */ 1,
/* 932 */ -929,
/* 933 */ 1,
/* 934 */ 0,
/* 935 */ -929,
/* 936 */ 2,
/* 937 */ 941,
/* 938 */ 50043,
/* 939 */ -937,
/* 940 */ 1,
/* 941 */ 0,
/* 942 */ 50045,
/* 943 */ -937,
/* 944 */ 2,
/* 945 */ 0,
/* 946 */ 1,
/* 947 */ 1,
/* 948 */ -945,
/* 949 */ 1,
/* 950 */ 955,
/* 951 */ 1,
/* 952 */ 1,
/* 953 */ -950,
/* 954 */ 1,
/* 955 */ 0,
/* 956 */ -950,
/* 957 */ 2,
/* 958 */ 962,
/* 959 */ 50042,
/* 960 */ -958,
/* 961 */ 1,
/* 962 */ 966,
/* 963 */ 50047,
/* 964 */ -958,
/* 965 */ 2,
/* 966 */ 0,
/* 967 */ 50037,
/* 968 */ -958,
/* 969 */ 3,
/* 970 */ 974,
/* 971 */ 1,
/* 972 */ -970,
/* 973 */ 1,
/* 974 */ 0,
/* 975 */ 50040,
/* 976 */ 1,
/* 977 */ 50041,
/* 978 */ 1,
/* 979 */ -970,
/* 980 */ 2,
/* 981 */ 985,
/* 982 */ 1,
/* 983 */ -981,
/* 984 */ 1,
/* 985 */ 990,
/* 986 */ 1,
/* 987 */ 1,
/* 988 */ -981,
/* 989 */ 2,
/* 990 */ 995,
/* 991 */ 1,
/* 992 */ 1,
/* 993 */ -981,
/* 994 */ 3,
/* 995 */ 1000,
/* 996 */ 50278,
/* 997 */ 1,
/* 998 */ -981,
/* 999 */ 4,
/* 1000 */ 0,
/* 1001 */ 50278,
/* 1002 */ 50040,
/* 1003 */ 1,
/* 1004 */ 50041,
/* 1005 */ -981,
/* 1006 */ 5,
/* 1007 */ 1011,
/* 1008 */ 50294,
/* 1009 */ -1007,
/* 1010 */ 1,
/* 1011 */ 0,
/* 1012 */ 50295,
/* 1013 */ -1007,
/* 1014 */ 2,
/* 1015 */ 1019,
/* 1016 */ 50038,
/* 1017 */ -1015,
/* 1018 */ 1,
/* 1019 */ 1023,
/* 1020 */ 50042,
/* 1021 */ -1015,
/* 1022 */ 2,
/* 1023 */ 1027,
/* 1024 */ 50043,
/* 1025 */ -1015,
/* 1026 */ 3,
/* 1027 */ 1031,
/* 1028 */ 50045,
/* 1029 */ -1015,
/* 1030 */ 4,
/* 1031 */ 1035,
/* 1032 */ 50126,
/* 1033 */ -1015,
/* 1034 */ 5,
/* 1035 */ 0,
/* 1036 */ 50033,
/* 1037 */ -1015,
/* 1038 */ 6,
/* 1039 */ 1043,
/* 1040 */ 1,
/* 1041 */ -1039,
/* 1042 */ 1,
/* 1043 */ 0,
/* 1044 */ 1,
/* 1045 */ 1,
/* 1046 */ -1039,
/* 1047 */ 2,
/* 1048 */ 1054,
/* 1049 */ 50091,
/* 1050 */ 1,
/* 1051 */ 50093,
/* 1052 */ -1048,
/* 1053 */ 1,
/* 1054 */ 1060,
/* 1055 */ 50040,
/* 1056 */ 1,
/* 1057 */ 50041,
/* 1058 */ -1048,
/* 1059 */ 2,
/* 1060 */ 1065,
/* 1061 */ 50046,
/* 1062 */ 50299,
/* 1063 */ -1048,
/* 1064 */ 3,
/* 1065 */ 1070,
/* 1066 */ 50296,
/* 1067 */ 50299,
/* 1068 */ -1048,
/* 1069 */ 4,
/* 1070 */ 1074,
/* 1071 */ 50294,
/* 1072 */ -1048,
/* 1073 */ 5,
/* 1074 */ 0,
/* 1075 */ 50295,
/* 1076 */ -1048,
/* 1077 */ 6,
/* 1078 */ 1082,
/* 1079 */ 1,
/* 1080 */ -1078,
/* 1081 */ 1,
/* 1082 */ 0,
/* 1083 */ -1078,
/* 1084 */ 2,
/* 1085 */ 1089,
/* 1086 */ 50299,
/* 1087 */ -1085,
/* 1088 */ 1,
/* 1089 */ 1093,
/* 1090 */ 1,
/* 1091 */ -1085,
/* 1092 */ 2,
/* 1093 */ 1097,
/* 1094 */ 50289,
/* 1095 */ -1085,
/* 1096 */ 3,
/* 1097 */ 0,
/* 1098 */ 50040,
/* 1099 */ 1,
/* 1100 */ 50041,
/* 1101 */ -1085,
/* 1102 */ 4,
/* 1103 */ 0,
/* 1104 */ 1,
/* 1105 */ 1,
/* 1106 */ -1103,
/* 1107 */ 1,
/* 1108 */ 1113,
/* 1109 */ 1,
/* 1110 */ 50044,
/* 1111 */ -1108,
/* 1112 */ 1,
/* 1113 */ 0,
/* 1114 */ -1108,
/* 1115 */ 2,
/* 1116 */ 1120,
/* 1117 */ 50308,
/* 1118 */ -1116,
/* 1119 */ 1,
/* 1120 */ 1124,
/* 1121 */ 50306,
/* 1122 */ -1116,
/* 1123 */ 2,
/* 1124 */ 1128,
/* 1125 */ 50307,
/* 1126 */ -1116,
/* 1127 */ 3,
/* 1128 */ 0,
/* 1129 */ 50299,
/* 1130 */ -1116,
/* 1131 */ 4,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 17002,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 17002,
/* 6 */ 9999,
/* 7 */ 17004,
/* 8 */ 9999,
/* 9 */ 17023,
/* 10 */ 9999,
/* 11 */ 18004,
/* 12 */ 18021,
/* 13 */ 9999,
/* 14 */ 18019,
/* 15 */ 9999,
/* 16 */ 22004,
/* 17 */ 9999,
/* 18 */ 22022,
/* 19 */ 9999,
/* 20 */ 23004,
/* 21 */ 9999,
/* 22 */ 23014,
/* 23 */ 9999,
/* 24 */ 27004,
/* 25 */ 27032,
/* 26 */ 27043,
/* 27 */ 27065,
/* 28 */ 9999,
/* 29 */ 27004,
/* 30 */ 9999,
/* 31 */ 27006,
/* 32 */ 9999,
/* 33 */ 27027,
/* 34 */ 9999,
/* 35 */ 9999,
/* 36 */ 27027,
/* 37 */ 9999,
/* 38 */ 27045,
/* 39 */ 9999,
/* 40 */ 27060,
/* 41 */ 9999,
/* 42 */ 9999,
/* 43 */ 27060,
/* 44 */ 9999,
/* 45 */ 31004,
/* 46 */ 31027,
/* 47 */ 9999,
/* 48 */ 9999,
/* 49 */ 31025,
/* 50 */ 9999,
/* 51 */ 31029,
/* 52 */ 9999,
/* 53 */ 31048,
/* 54 */ 9999,
/* 55 */ 9999,
/* 56 */ 31048,
/* 57 */ 9999,
/* 58 */ 35004,
/* 59 */ 35026,
/* 60 */ 9999,
/* 61 */ 35004,
/* 62 */ 9999,
/* 63 */ 35006,
/* 64 */ 9999,
/* 65 */ 35021,
/* 66 */ 9999,
/* 67 */ 9999,
/* 68 */ 35021,
/* 69 */ 9999,
/* 70 */ 39004,
/* 71 */ 39095,
/* 72 */ 9999,
/* 73 */ 39004,
/* 74 */ 9999,
/* 75 */ 39006,
/* 76 */ 9999,
/* 77 */ 39028,
/* 78 */ 9999,
/* 79 */ 39032,
/* 80 */ 9999,
/* 81 */ 39045,
/* 82 */ 9999,
/* 83 */ 39078,
/* 84 */ 9999,
/* 85 */ 39091,
/* 86 */ 9999,
/* 87 */ 39097,
/* 88 */ 9999,
/* 89 */ 39118,
/* 90 */ 9999,
/* 91 */ 9999,
/* 92 */ 39118,
/* 93 */ 9999,
/* 94 */ 9999,
/* 95 */ 9999,
/* 96 */ 43007,
/* 97 */ 9999,
/* 98 */ 9999,
/* 99 */ 9999,
/* 100 */ 43018,
/* 101 */ 9999,
/* 102 */ 9999,
/* 103 */ 9999,
/* 104 */ 43027,
/* 105 */ 9999,
/* 106 */ 9999,
/* 107 */ 9999,
/* 108 */ 43036,
/* 109 */ 9999,
/* 110 */ 9999,
/* 111 */ 9999,
/* 112 */ 43046,
/* 113 */ 9999,
/* 114 */ 9999,
/* 115 */ 9999,
/* 116 */ 47007,
/* 117 */ 9999,
/* 118 */ 9999,
/* 119 */ 9999,
/* 120 */ 47014,
/* 121 */ 9999,
/* 122 */ 9999,
/* 123 */ 9999,
/* 124 */ 47022,
/* 125 */ 9999,
/* 126 */ 9999,
/* 127 */ 9999,
/* 128 */ 47028,
/* 129 */ 9999,
/* 130 */ 9999,
/* 131 */ 9999,
/* 132 */ 47060,
/* 133 */ 9999,
/* 134 */ 9999,
/* 135 */ 9999,
/* 136 */ 47068,
/* 137 */ 9999,
/* 138 */ 9999,
/* 139 */ 9999,
/* 140 */ 47077,
/* 141 */ 9999,
/* 142 */ 9999,
/* 143 */ 9999,
/* 144 */ 47086,
/* 145 */ 9999,
/* 146 */ 9999,
/* 147 */ 9999,
/* 148 */ 47097,
/* 149 */ 9999,
/* 150 */ 48004,
/* 151 */ 9999,
/* 152 */ 48028,
/* 153 */ 9999,
/* 154 */ 48032,
/* 155 */ 9999,
/* 156 */ 48045,
/* 157 */ 9999,
/* 158 */ 9999,
/* 159 */ 9999,
/* 160 */ 52008,
/* 161 */ 9999,
/* 162 */ 9999,
/* 163 */ 9999,
/* 164 */ 52019,
/* 165 */ 9999,
/* 166 */ 56004,
/* 167 */ 56020,
/* 168 */ 9999,
/* 169 */ 56040,
/* 170 */ 9999,
/* 171 */ 9999,
/* 172 */ 56018,
/* 173 */ 9999,
/* 174 */ 57004,
/* 175 */ 9999,
/* 176 */ 9999,
/* 177 */ 57018,
/* 178 */ 9999,
/* 179 */ 9999,
/* 180 */ 9999,
/* 181 */ 56031,
/* 182 */ 9999,
/* 183 */ 9999,
/* 184 */ 56031,
/* 185 */ 9999,
/* 186 */ 9999,
/* 187 */ 9999,
/* 188 */ 61009,
/* 189 */ 9999,
/* 190 */ 9999,
/* 191 */ 9999,
/* 192 */ 61017,
/* 193 */ 9999,
/* 194 */ 65004,
/* 195 */ 65033,
/* 196 */ 9999,
/* 197 */ 65004,
/* 198 */ 9999,
/* 199 */ 65006,
/* 200 */ 9999,
/* 201 */ 65028,
/* 202 */ 9999,
/* 203 */ 9999,
/* 204 */ 65028,
/* 205 */ 9999,
/* 206 */ 69004,
/* 207 */ 69034,
/* 208 */ 9999,
/* 209 */ 69004,
/* 210 */ 9999,
/* 211 */ 69006,
/* 212 */ 9999,
/* 213 */ 9999,
/* 214 */ 69025,
/* 215 */ 9999,
/* 216 */ 9999,
/* 217 */ 69025,
/* 218 */ 9999,
/* 219 */ 73004,
/* 220 */ 73024,
/* 221 */ 9999,
/* 222 */ 73004,
/* 223 */ 9999,
/* 224 */ 73006,
/* 225 */ 9999,
/* 226 */ 9999,
/* 227 */ 73015,
/* 228 */ 9999,
/* 229 */ 9999,
/* 230 */ 73015,
/* 231 */ 9999,
/* 232 */ 77004,
/* 233 */ 77029,
/* 234 */ 9999,
/* 235 */ 9999,
/* 236 */ 77027,
/* 237 */ 9999,
/* 238 */ 81004,
/* 239 */ 81040,
/* 240 */ 9999,
/* 241 */ 81004,
/* 242 */ 9999,
/* 243 */ 81006,
/* 244 */ 9999,
/* 245 */ 81019,
/* 246 */ 9999,
/* 247 */ 81023,
/* 248 */ 9999,
/* 249 */ 81036,
/* 250 */ 9999,
/* 251 */ 81042,
/* 252 */ 9999,
/* 253 */ 81065,
/* 254 */ 9999,
/* 255 */ 9999,
/* 256 */ 81065,
/* 257 */ 9999,
/* 258 */ 85004,
/* 259 */ 85036,
/* 260 */ 9999,
/* 261 */ 85004,
/* 262 */ 9999,
/* 263 */ 85006,
/* 264 */ 9999,
/* 265 */ 9999,
/* 266 */ 85027,
/* 267 */ 9999,
/* 268 */ 9999,
/* 269 */ 85027,
/* 270 */ 9999,
/* 271 */ 89004,
/* 272 */ 9999,
/* 273 */ 89013,
/* 274 */ 9999,
/* 275 */ 90004,
/* 276 */ 9999,
/* 277 */ 90024,
/* 278 */ 9999,
/* 279 */ 90004,
/* 280 */ 9999,
/* 281 */ 90006,
/* 282 */ 9999,
/* 283 */ 90015,
/* 284 */ 9999,
/* 285 */ 9999,
/* 286 */ 90015,
/* 287 */ 9999,
/* 288 */ 9999,
/* 289 */ 94009,
/* 290 */ 9999,
/* 291 */ 94029,
/* 292 */ 9999,
/* 293 */ 9999,
/* 294 */ 94007,
/* 295 */ 9999,
/* 296 */ 9999,
/* 297 */ 9999,
/* 298 */ 9999,
/* 299 */ 95007,
/* 300 */ 9999,
/* 301 */ 9999,
/* 302 */ 9999,
/* 303 */ 94020,
/* 304 */ 9999,
/* 305 */ 9999,
/* 306 */ 94020,
/* 307 */ 9999,
/* 308 */ 99004,
/* 309 */ 99029,
/* 310 */ 9999,
/* 311 */ 99004,
/* 312 */ 9999,
/* 313 */ 99006,
/* 314 */ 9999,
/* 315 */ 9999,
/* 316 */ 99020,
/* 317 */ 9999,
/* 318 */ 9999,
/* 319 */ 99020,
/* 320 */ 9999,
/* 321 */ 9999,
/* 322 */ 103015,
/* 323 */ 9999,
/* 324 */ 103013,
/* 325 */ 9999,
/* 326 */ 9999,
/* 327 */ 103021,
/* 328 */ 9999,
/* 329 */ 103017,
/* 330 */ 9999,
/* 331 */ 9999,
/* 332 */ 103017,
/* 333 */ 9999,
/* 334 */ 107004,
/* 335 */ 107017,
/* 336 */ 9999,
/* 337 */ 107004,
/* 338 */ 9999,
/* 339 */ 107006,
/* 340 */ 9999,
/* 341 */ 107012,
/* 342 */ 9999,
/* 343 */ 9999,
/* 344 */ 107012,
/* 345 */ 9999,
/* 346 */ 9999,
/* 347 */ 9999,
/* 348 */ 111013,
/* 349 */ 9999,
/* 350 */ 9999,
/* 351 */ 112008,
/* 352 */ 9999,
/* 353 */ 9999,
/* 354 */ 112004,
/* 355 */ 9999,
/* 356 */ 113004,
/* 357 */ 113022,
/* 358 */ 9999,
/* 359 */ 113020,
/* 360 */ 9999,
/* 361 */ 9999,
/* 362 */ 113028,
/* 363 */ 9999,
/* 364 */ 9999,
/* 365 */ 113024,
/* 366 */ 9999,
/* 367 */ 9999,
/* 368 */ 113063,
/* 369 */ 9999,
/* 370 */ 9999,
/* 371 */ 113059,
/* 372 */ 9999,
/* 373 */ 9999,
/* 374 */ 113093,
/* 375 */ 9999,
/* 376 */ 9999,
/* 377 */ 113089,
/* 378 */ 9999,
/* 379 */ 113030,
/* 380 */ 9999,
/* 381 */ 113048,
/* 382 */ 9999,
/* 383 */ 9999,
/* 384 */ 113048,
/* 385 */ 9999,
/* 386 */ 113095,
/* 387 */ 9999,
/* 388 */ 113109,
/* 389 */ 9999,
/* 390 */ 9999,
/* 391 */ 113109,
/* 392 */ 9999,
/* 393 */ 9999,
/* 394 */ 117008,
/* 395 */ 117033,
/* 396 */ 9999,
/* 397 */ 117004,
/* 398 */ 9999,
/* 399 */ 117010,
/* 400 */ 9999,
/* 401 */ 117028,
/* 402 */ 9999,
/* 403 */ 9999,
/* 404 */ 117028,
/* 405 */ 9999,
/* 406 */ 117035,
/* 407 */ 9999,
/* 408 */ 117041,
/* 409 */ 9999,
/* 410 */ 9999,
/* 411 */ 117041,
/* 412 */ 9999,
/* 413 */ 121004,
/* 414 */ 121029,
/* 415 */ 9999,
/* 416 */ 121004,
/* 417 */ 9999,
/* 418 */ 121006,
/* 419 */ 9999,
/* 420 */ 121024,
/* 421 */ 9999,
/* 422 */ 9999,
/* 423 */ 121024,
/* 424 */ 9999,
/* 425 */ 125004,
/* 426 */ 125019,
/* 427 */ 9999,
/* 428 */ 125017,
/* 429 */ 9999,
/* 430 */ 9999,
/* 431 */ 9999,
/* 432 */ 9999,
/* 433 */ 125021,
/* 434 */ 9999,
/* 435 */ 9999,
/* 436 */ 125021,
/* 437 */ 9999,
/* 438 */ 129004,
/* 439 */ 129028,
/* 440 */ 9999,
/* 441 */ 129004,
/* 442 */ 9999,
/* 443 */ 129006,
/* 444 */ 9999,
/* 445 */ 9999,
/* 446 */ 129019,
/* 447 */ 9999,
/* 448 */ 9999,
/* 449 */ 129019,
/* 450 */ 9999,
/* 451 */ 133004,
/* 452 */ 133027,
/* 453 */ 9999,
/* 454 */ 133025,
/* 455 */ 9999,
/* 456 */ 133029,
/* 457 */ 9999,
/* 458 */ 133038,
/* 459 */ 9999,
/* 460 */ 133042,
/* 461 */ 9999,
/* 462 */ 133042,
/* 463 */ 9999,
/* 464 */ 133044,
/* 465 */ 9999,
/* 466 */ 133062,
/* 467 */ 9999,
/* 468 */ 9999,
/* 469 */ 133062,
/* 470 */ 9999,
/* 471 */ 137004,
/* 472 */ 9999,
/* 473 */ 9999,
/* 474 */ 137004,
/* 475 */ 9999,
/* 476 */ 137006,
/* 477 */ 9999,
/* 478 */ 9999,
/* 479 */ 137020,
/* 480 */ 9999,
/* 481 */ 9999,
/* 482 */ 137020,
/* 483 */ 9999,
/* 484 */ 141004,
/* 485 */ 9999,
/* 486 */ 141024,
/* 487 */ 9999,
/* 488 */ 9999,
/* 489 */ 142008,
/* 490 */ 142025,
/* 491 */ 9999,
/* 492 */ 9999,
/* 493 */ 142004,
/* 494 */ 9999,
/* 495 */ 9999,
/* 496 */ 9999,
/* 497 */ 142027,
/* 498 */ 9999,
/* 499 */ 9999,
/* 500 */ 142027,
/* 501 */ 9999,
/* 502 */ 146004,
/* 503 */ 146030,
/* 504 */ 9999,
/* 505 */ 146004,
/* 506 */ 9999,
/* 507 */ 146006,
/* 508 */ 9999,
/* 509 */ 9999,
/* 510 */ 146021,
/* 511 */ 9999,
/* 512 */ 9999,
/* 513 */ 146021,
/* 514 */ 9999,
/* 515 */ 150004,
/* 516 */ 150029,
/* 517 */ 9999,
/* 518 */ 150027,
/* 519 */ 9999,
/* 520 */ 150031,
/* 521 */ 9999,
/* 522 */ 150049,
/* 523 */ 9999,
/* 524 */ 9999,
/* 525 */ 150049,
/* 526 */ 9999,
/* 527 */ 154004,
/* 528 */ 9999,
/* 529 */ 154010,
/* 530 */ 9999,
/* 531 */ 155004,
/* 532 */ 155017,
/* 533 */ 9999,
/* 534 */ 155004,
/* 535 */ 9999,
/* 536 */ 155006,
/* 537 */ 9999,
/* 538 */ 155012,
/* 539 */ 9999,
/* 540 */ 9999,
/* 541 */ 155012,
/* 542 */ 9999,
/* 543 */ 9999,
/* 544 */ 159008,
/* 545 */ 9999,
/* 546 */ 9999,
/* 547 */ 159004,
/* 548 */ 9999,
/* 549 */ 160004,
/* 550 */ 160036,
/* 551 */ 9999,
/* 552 */ 160004,
/* 553 */ 9999,
/* 554 */ 160006,
/* 555 */ 9999,
/* 556 */ 160031,
/* 557 */ 9999,
/* 558 */ 9999,
/* 559 */ 160031,
/* 560 */ 9999,
/* 561 */ 9999,
/* 562 */ 160042,
/* 563 */ 9999,
/* 564 */ 9999,
/* 565 */ 160038,
/* 566 */ 9999,
/* 567 */ 9999,
/* 568 */ 160077,
/* 569 */ 9999,
/* 570 */ 9999,
/* 571 */ 160073,
/* 572 */ 9999,
/* 573 */ 160044,
/* 574 */ 9999,
/* 575 */ 160062,
/* 576 */ 9999,
/* 577 */ 9999,
/* 578 */ 160062,
/* 579 */ 9999,
/* 580 */ 160079,
/* 581 */ 9999,
/* 582 */ 160097,
/* 583 */ 9999,
/* 584 */ 9999,
/* 585 */ 160097,
/* 586 */ 9999,
/* 587 */ 9999,
/* 588 */ 9999,
/* 589 */ 164013,
/* 590 */ 9999,
/* 591 */ 168004,
/* 592 */ 9999,
/* 593 */ 168020,
/* 594 */ 9999,
/* 595 */ 169004,
/* 596 */ 9999,
/* 597 */ 169023,
/* 598 */ 9999,
/* 599 */ 170004,
/* 600 */ 9999,
/* 601 */ 170021,
/* 602 */ 9999,
/* 603 */ 171004,
/* 604 */ 9999,
/* 605 */ 171022,
/* 606 */ 9999,
/* 607 */ 172004,
/* 608 */ 9999,
/* 609 */ 172022,
/* 610 */ 9999,
/* 611 */ 173004,
/* 612 */ 9999,
/* 613 */ 173017,
/* 614 */ 9999,
/* 615 */ 9999,
/* 616 */ 9999,
/* 617 */ 177019,
/* 618 */ 9999,
/* 619 */ 177013,
/* 620 */ 9999,
/* 621 */ 9999,
/* 622 */ 178009,
/* 623 */ 9999,
/* 624 */ 178033,
/* 625 */ 9999,
/* 626 */ 178007,
/* 627 */ 9999,
/* 628 */ 9999,
/* 629 */ 9999,
/* 630 */ 179016,
/* 631 */ 9999,
/* 632 */ 179010,
/* 633 */ 9999,
/* 634 */ 183004,
/* 635 */ 9999,
/* 636 */ 9999,
/* 637 */ 183004,
/* 638 */ 9999,
/* 639 */ 183006,
/* 640 */ 9999,
/* 641 */ 183015,
/* 642 */ 9999,
/* 643 */ 9999,
/* 644 */ 183015,
/* 645 */ 9999,
/* 646 */ 9999,
/* 647 */ 187008,
/* 648 */ 187030,
/* 649 */ 9999,
/* 650 */ 9999,
/* 651 */ 187004,
/* 652 */ 9999,
/* 653 */ 187010,
/* 654 */ 9999,
/* 655 */ 187025,
/* 656 */ 9999,
/* 657 */ 9999,
/* 658 */ 187025,
/* 659 */ 9999,
/* 660 */ 187032,
/* 661 */ 9999,
/* 662 */ 187045,
/* 663 */ 9999,
/* 664 */ 9999,
/* 665 */ 187045,
/* 666 */ 9999,
/* 667 */ 191004,
/* 668 */ 191024,
/* 669 */ 9999,
/* 670 */ 191004,
/* 671 */ 9999,
/* 672 */ 191006,
/* 673 */ 9999,
/* 674 */ 191019,
/* 675 */ 9999,
/* 676 */ 9999,
/* 677 */ 191019,
/* 678 */ 9999,
/* 679 */ 9999,
/* 680 */ 9999,
/* 681 */ 195011,
/* 682 */ 9999,
/* 683 */ 195026,
/* 684 */ 195036,
/* 685 */ 9999,
/* 686 */ 195005,
/* 687 */ 9999,
/* 688 */ 9999,
/* 689 */ 9999,
/* 690 */ 196015,
/* 691 */ 9999,
/* 692 */ 196030,
/* 693 */ 9999,
/* 694 */ 196009,
/* 695 */ 9999,
/* 696 */ 9999,
/* 697 */ 195043,
/* 698 */ 9999,
/* 699 */ 195041,
/* 700 */ 9999,
/* 701 */ 9999,
/* 702 */ 195041,
/* 703 */ 9999,
/* 704 */ 9999,
/* 705 */ 9999,
/* 706 */ 200014,
/* 707 */ 9999,
/* 708 */ 200029,
/* 709 */ 9999,
/* 710 */ 200008,
/* 711 */ 9999,
/* 712 */ 9999,
/* 713 */ 201007,
/* 714 */ 9999,
/* 715 */ 9999,
/* 716 */ 201027,
/* 717 */ 9999,
/* 718 */ 9999,
/* 719 */ 9999,
/* 720 */ 201005,
/* 721 */ 9999,
/* 722 */ 9999,
/* 723 */ 9999,
/* 724 */ 202012,
/* 725 */ 9999,
/* 726 */ 202032,
/* 727 */ 9999,
/* 728 */ 202052,
/* 729 */ 9999,
/* 730 */ 202072,
/* 731 */ 9999,
/* 732 */ 202006,
/* 733 */ 9999,
/* 734 */ 202014,
/* 735 */ 9999,
/* 736 */ 202023,
/* 737 */ 9999,
/* 738 */ 9999,
/* 739 */ 202023,
/* 740 */ 9999,
/* 741 */ 202034,
/* 742 */ 9999,
/* 743 */ 202043,
/* 744 */ 9999,
/* 745 */ 9999,
/* 746 */ 202043,
/* 747 */ 9999,
/* 748 */ 202054,
/* 749 */ 9999,
/* 750 */ 202063,
/* 751 */ 9999,
/* 752 */ 9999,
/* 753 */ 202063,
/* 754 */ 9999,
/* 755 */ 9999,
/* 756 */ 9999,
/* 757 */ 9999,
/* 758 */ 9999,
/* 759 */ 206007,
/* 760 */ 9999,
/* 761 */ 9999,
/* 762 */ 9999,
/* 763 */ 9999,
/* 764 */ 207011,
/* 765 */ 9999,
/* 766 */ 9999,
/* 767 */ 9999,
/* 768 */ 9999,
/* 769 */ 208008,
/* 770 */ 9999,
/* 771 */ 9999,
/* 772 */ 209011,
/* 773 */ 9999,
/* 774 */ 9999,
/* 775 */ 209009,
/* 776 */ 9999,
/* 777 */ 209013,
/* 778 */ 9999,
/* 779 */ 209022,
/* 780 */ 9999,
/* 781 */ 9999,
/* 782 */ 209022,
/* 783 */ 9999,
/* 784 */ 213004,
/* 785 */ 213024,
/* 786 */ 9999,
/* 787 */ 213004,
/* 788 */ 9999,
/* 789 */ 213006,
/* 790 */ 9999,
/* 791 */ 9999,
/* 792 */ 213015,
/* 793 */ 9999,
/* 794 */ 9999,
/* 795 */ 213015,
/* 796 */ 9999,
/* 797 */ 217004,
/* 798 */ 9999,
/* 799 */ 217025,
/* 800 */ 9999,
/* 801 */ 218004,
/* 802 */ 218021,
/* 803 */ 218041,
/* 804 */ 9999,
/* 805 */ 218019,
/* 806 */ 9999,
/* 807 */ 9999,
/* 808 */ 9999,
/* 809 */ 222009,
/* 810 */ 9999,
/* 811 */ 9999,
/* 812 */ 9999,
/* 813 */ 223004,
/* 814 */ 9999,
/* 815 */ 227004,
/* 816 */ 227026,
/* 817 */ 9999,
/* 818 */ 227024,
/* 819 */ 9999,
/* 820 */ 9999,
/* 821 */ 227032,
/* 822 */ 9999,
/* 823 */ 227047,
/* 824 */ 9999,
/* 825 */ 227028,
/* 826 */ 9999,
/* 827 */ 9999,
/* 828 */ 227028,
/* 829 */ 9999,
/* 830 */ 231004,
/* 831 */ 9999,
/* 832 */ 231025,
/* 833 */ 9999,
/* 834 */ 235004,
/* 835 */ 235042,
/* 836 */ 9999,
/* 837 */ 235004,
/* 838 */ 9999,
/* 839 */ 235006,
/* 840 */ 9999,
/* 841 */ 9999,
/* 842 */ 235026,
/* 843 */ 9999,
/* 844 */ 9999,
/* 845 */ 235026,
/* 846 */ 9999,
/* 847 */ 239004,
/* 848 */ 239044,
/* 849 */ 9999,
/* 850 */ 239004,
/* 851 */ 9999,
/* 852 */ 239006,
/* 853 */ 9999,
/* 854 */ 9999,
/* 855 */ 239027,
/* 856 */ 9999,
/* 857 */ 9999,
/* 858 */ 239027,
/* 859 */ 9999,
/* 860 */ 243004,
/* 861 */ 243040,
/* 862 */ 9999,
/* 863 */ 243004,
/* 864 */ 9999,
/* 865 */ 243006,
/* 866 */ 9999,
/* 867 */ 9999,
/* 868 */ 243028,
/* 869 */ 9999,
/* 870 */ 9999,
/* 871 */ 243028,
/* 872 */ 9999,
/* 873 */ 247004,
/* 874 */ 247041,
/* 875 */ 9999,
/* 876 */ 247004,
/* 877 */ 9999,
/* 878 */ 247006,
/* 879 */ 9999,
/* 880 */ 9999,
/* 881 */ 247028,
/* 882 */ 9999,
/* 883 */ 9999,
/* 884 */ 247028,
/* 885 */ 9999,
/* 886 */ 251004,
/* 887 */ 251031,
/* 888 */ 9999,
/* 889 */ 251004,
/* 890 */ 9999,
/* 891 */ 251005,
/* 892 */ 9999,
/* 893 */ 9999,
/* 894 */ 251018,
/* 895 */ 9999,
/* 896 */ 9999,
/* 897 */ 251018,
/* 898 */ 9999,
/* 899 */ 255004,
/* 900 */ 255037,
/* 901 */ 9999,
/* 902 */ 255004,
/* 903 */ 9999,
/* 904 */ 255006,
/* 905 */ 9999,
/* 906 */ 9999,
/* 907 */ 255024,
/* 908 */ 9999,
/* 909 */ 9999,
/* 910 */ 255024,
/* 911 */ 9999,
/* 912 */ 259004,
/* 913 */ 259031,
/* 914 */ 9999,
/* 915 */ 259004,
/* 916 */ 9999,
/* 917 */ 259005,
/* 918 */ 9999,
/* 919 */ 9999,
/* 920 */ 259020,
/* 921 */ 9999,
/* 922 */ 9999,
/* 923 */ 259020,
/* 924 */ 9999,
/* 925 */ 263004,
/* 926 */ 263043,
/* 927 */ 9999,
/* 928 */ 263004,
/* 929 */ 9999,
/* 930 */ 263006,
/* 931 */ 263026,
/* 932 */ 9999,
/* 933 */ 263024,
/* 934 */ 9999,
/* 935 */ 9999,
/* 936 */ 263024,
/* 937 */ 9999,
/* 938 */ 9999,
/* 939 */ 9999,
/* 940 */ 263028,
/* 941 */ 9999,
/* 942 */ 9999,
/* 943 */ 9999,
/* 944 */ 263034,
/* 945 */ 9999,
/* 946 */ 267004,
/* 947 */ 267055,
/* 948 */ 9999,
/* 949 */ 267004,
/* 950 */ 9999,
/* 951 */ 267006,
/* 952 */ 267032,
/* 953 */ 9999,
/* 954 */ 267030,
/* 955 */ 9999,
/* 956 */ 9999,
/* 957 */ 267030,
/* 958 */ 9999,
/* 959 */ 9999,
/* 960 */ 9999,
/* 961 */ 267034,
/* 962 */ 9999,
/* 963 */ 9999,
/* 964 */ 9999,
/* 965 */ 267040,
/* 966 */ 9999,
/* 967 */ 9999,
/* 968 */ 9999,
/* 969 */ 267046,
/* 970 */ 9999,
/* 971 */ 271004,
/* 972 */ 9999,
/* 973 */ 271019,
/* 974 */ 9999,
/* 975 */ 9999,
/* 976 */ 272008,
/* 977 */ 9999,
/* 978 */ 272022,
/* 979 */ 9999,
/* 980 */ 272004,
/* 981 */ 9999,
/* 982 */ 276004,
/* 983 */ 9999,
/* 984 */ 276021,
/* 985 */ 9999,
/* 986 */ 277004,
/* 987 */ 277024,
/* 988 */ 9999,
/* 989 */ 277004,
/* 990 */ 9999,
/* 991 */ 278004,
/* 992 */ 278019,
/* 993 */ 9999,
/* 994 */ 278017,
/* 995 */ 9999,
/* 996 */ 9999,
/* 997 */ 279011,
/* 998 */ 9999,
/* 999 */ 279009,
/* 1000 */ 9999,
/* 1001 */ 9999,
/* 1002 */ 9999,
/* 1003 */ 280015,
/* 1004 */ 9999,
/* 1005 */ 9999,
/* 1006 */ 280009,
/* 1007 */ 9999,
/* 1008 */ 9999,
/* 1009 */ 9999,
/* 1010 */ 277011,
/* 1011 */ 9999,
/* 1012 */ 9999,
/* 1013 */ 9999,
/* 1014 */ 277020,
/* 1015 */ 9999,
/* 1016 */ 9999,
/* 1017 */ 9999,
/* 1018 */ 284004,
/* 1019 */ 9999,
/* 1020 */ 9999,
/* 1021 */ 9999,
/* 1022 */ 284010,
/* 1023 */ 9999,
/* 1024 */ 9999,
/* 1025 */ 9999,
/* 1026 */ 284016,
/* 1027 */ 9999,
/* 1028 */ 9999,
/* 1029 */ 9999,
/* 1030 */ 284022,
/* 1031 */ 9999,
/* 1032 */ 9999,
/* 1033 */ 9999,
/* 1034 */ 284028,
/* 1035 */ 9999,
/* 1036 */ 9999,
/* 1037 */ 9999,
/* 1038 */ 284034,
/* 1039 */ 9999,
/* 1040 */ 288004,
/* 1041 */ 9999,
/* 1042 */ 288021,
/* 1043 */ 9999,
/* 1044 */ 289004,
/* 1045 */ 289023,
/* 1046 */ 9999,
/* 1047 */ 289021,
/* 1048 */ 9999,
/* 1049 */ 9999,
/* 1050 */ 289029,
/* 1051 */ 9999,
/* 1052 */ 9999,
/* 1053 */ 289025,
/* 1054 */ 9999,
/* 1055 */ 9999,
/* 1056 */ 289050,
/* 1057 */ 9999,
/* 1058 */ 9999,
/* 1059 */ 289046,
/* 1060 */ 9999,
/* 1061 */ 9999,
/* 1062 */ 9999,
/* 1063 */ 9999,
/* 1064 */ 289086,
/* 1065 */ 9999,
/* 1066 */ 9999,
/* 1067 */ 9999,
/* 1068 */ 9999,
/* 1069 */ 289108,
/* 1070 */ 9999,
/* 1071 */ 9999,
/* 1072 */ 9999,
/* 1073 */ 289128,
/* 1074 */ 9999,
/* 1075 */ 9999,
/* 1076 */ 9999,
/* 1077 */ 289137,
/* 1078 */ 9999,
/* 1079 */ 289052,
/* 1080 */ 9999,
/* 1081 */ 289075,
/* 1082 */ 9999,
/* 1083 */ 9999,
/* 1084 */ 289075,
/* 1085 */ 9999,
/* 1086 */ 9999,
/* 1087 */ 9999,
/* 1088 */ 293013,
/* 1089 */ 9999,
/* 1090 */ 294004,
/* 1091 */ 9999,
/* 1092 */ 294011,
/* 1093 */ 9999,
/* 1094 */ 9999,
/* 1095 */ 9999,
/* 1096 */ 295009,
/* 1097 */ 9999,
/* 1098 */ 9999,
/* 1099 */ 296008,
/* 1100 */ 9999,
/* 1101 */ 9999,
/* 1102 */ 296004,
/* 1103 */ 9999,
/* 1104 */ 300004,
/* 1105 */ 300038,
/* 1106 */ 9999,
/* 1107 */ 300004,
/* 1108 */ 9999,
/* 1109 */ 300006,
/* 1110 */ 9999,
/* 1111 */ 9999,
/* 1112 */ 300029,
/* 1113 */ 9999,
/* 1114 */ 9999,
/* 1115 */ 300029,
/* 1116 */ 9999,
/* 1117 */ 9999,
/* 1118 */ 9999,
/* 1119 */ 304011,
/* 1120 */ 9999,
/* 1121 */ 9999,
/* 1122 */ 9999,
/* 1123 */ 304061,
/* 1124 */ 9999,
/* 1125 */ 9999,
/* 1126 */ 9999,
/* 1127 */ 304074,
/* 1128 */ 9999,
/* 1129 */ 9999,
/* 1130 */ 9999,
/* 1131 */ 304087,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[1133];
*/
int TABLE[257][309];
init_dirsets() {
TABLE[123][0] = 1;
TABLE[123][123] = 1;
TABLE[123][299] = 1;
TABLE[123][40] = 1;
TABLE[123][282] = 1;
TABLE[123][267] = 1;
TABLE[123][279] = 1;
TABLE[123][274] = 1;
TABLE[123][256] = 1;
TABLE[123][284] = 1;
TABLE[123][277] = 1;
TABLE[123][264] = 1;
TABLE[123][268] = 1;
TABLE[123][273] = 1;
TABLE[123][272] = 1;
TABLE[123][276] = 1;
TABLE[123][259] = 1;
TABLE[123][285] = 1;
TABLE[123][286] = 1;
TABLE[123][260] = 1;
TABLE[123][42] = 1;
TABLE[123][266] = 1;
TABLE[123][283] = 1;
TABLE[123][280] = 1;
TABLE[1][0] = 1;
TABLE[1][123] = 1;
TABLE[1][40] = 1;
TABLE[1][299] = 1;
TABLE[1][42] = 1;
TABLE[1][260] = 1;
TABLE[1][286] = 1;
TABLE[1][285] = 1;
TABLE[1][259] = 1;
TABLE[1][276] = 1;
TABLE[1][272] = 1;
TABLE[1][273] = 1;
TABLE[1][268] = 1;
TABLE[1][264] = 1;
TABLE[1][277] = 1;
TABLE[1][284] = 1;
TABLE[1][256] = 1;
TABLE[1][274] = 1;
TABLE[1][279] = 1;
TABLE[1][267] = 1;
TABLE[1][282] = 1;
TABLE[1][266] = 1;
TABLE[1][280] = 1;
TABLE[1][283] = 1;
TABLE[2][0] = 1;
TABLE[2][123] = 1;
TABLE[2][299] = 1;
TABLE[2][40] = 1;
TABLE[2][282] = 1;
TABLE[2][267] = 1;
TABLE[2][279] = 1;
TABLE[2][274] = 1;
TABLE[2][256] = 1;
TABLE[2][284] = 1;
TABLE[2][277] = 1;
TABLE[2][264] = 1;
TABLE[2][268] = 1;
TABLE[2][273] = 1;
TABLE[2][272] = 1;
TABLE[2][276] = 1;
TABLE[2][259] = 1;
TABLE[2][285] = 1;
TABLE[2][286] = 1;
TABLE[2][260] = 1;
TABLE[2][42] = 1;
TABLE[2][266] = 1;
TABLE[2][283] = 1;
TABLE[2][280] = 1;
TABLE[3][0] = 1;
TABLE[3][123] = 1;
TABLE[3][299] = 1;
TABLE[3][40] = 1;
TABLE[3][42] = 1;
TABLE[3][260] = 1;
TABLE[3][286] = 1;
TABLE[3][285] = 1;
TABLE[3][259] = 1;
TABLE[3][276] = 1;
TABLE[3][272] = 1;
TABLE[3][273] = 1;
TABLE[3][268] = 1;
TABLE[3][264] = 1;
TABLE[3][277] = 1;
TABLE[3][284] = 1;
TABLE[3][256] = 1;
TABLE[3][274] = 1;
TABLE[3][279] = 1;
TABLE[3][267] = 1;
TABLE[3][282] = 1;
TABLE[3][266] = 1;
TABLE[3][280] = 1;
TABLE[3][283] = 1;
TABLE[4][282] = 1;
TABLE[4][267] = 1;
TABLE[4][279] = 1;
TABLE[4][274] = 1;
TABLE[4][256] = 1;
TABLE[4][284] = 1;
TABLE[4][277] = 1;
TABLE[4][264] = 1;
TABLE[4][268] = 1;
TABLE[4][273] = 1;
TABLE[4][272] = 1;
TABLE[4][276] = 1;
TABLE[4][259] = 1;
TABLE[4][285] = 1;
TABLE[4][286] = 1;
TABLE[4][260] = 1;
TABLE[4][266] = 1;
TABLE[4][283] = 1;
TABLE[4][280] = 1;
TABLE[5][123] = 1;
TABLE[5][40] = 1;
TABLE[5][299] = 1;
TABLE[5][42] = 1;
TABLE[5][282] = 1;
TABLE[5][267] = 1;
TABLE[5][279] = 1;
TABLE[5][274] = 1;
TABLE[5][256] = 1;
TABLE[5][284] = 1;
TABLE[5][277] = 1;
TABLE[5][264] = 1;
TABLE[5][268] = 1;
TABLE[5][273] = 1;
TABLE[5][272] = 1;
TABLE[5][276] = 1;
TABLE[5][259] = 1;
TABLE[5][285] = 1;
TABLE[5][286] = 1;
TABLE[5][260] = 1;
TABLE[5][266] = 1;
TABLE[5][283] = 1;
TABLE[5][280] = 1;
TABLE[124][260] = 1;
TABLE[124][286] = 1;
TABLE[124][285] = 1;
TABLE[124][259] = 1;
TABLE[124][276] = 1;
TABLE[124][272] = 1;
TABLE[124][273] = 1;
TABLE[124][268] = 1;
TABLE[124][264] = 1;
TABLE[124][277] = 1;
TABLE[124][284] = 1;
TABLE[124][256] = 1;
TABLE[124][274] = 1;
TABLE[124][279] = 1;
TABLE[124][267] = 1;
TABLE[124][282] = 1;
TABLE[124][266] = 1;
TABLE[124][280] = 1;
TABLE[124][283] = 1;
TABLE[203][40] = 1;
TABLE[203][299] = 1;
TABLE[203][42] = 1;
TABLE[203][282] = 1;
TABLE[203][267] = 1;
TABLE[203][279] = 1;
TABLE[203][274] = 1;
TABLE[203][256] = 1;
TABLE[203][284] = 1;
TABLE[203][277] = 1;
TABLE[203][264] = 1;
TABLE[203][268] = 1;
TABLE[203][273] = 1;
TABLE[203][272] = 1;
TABLE[203][276] = 1;
TABLE[203][259] = 1;
TABLE[203][285] = 1;
TABLE[203][286] = 1;
TABLE[203][260] = 1;
TABLE[203][266] = 1;
TABLE[203][283] = 1;
TABLE[203][280] = 1;
TABLE[203][123] = 1;
TABLE[125][123] = 1;
TABLE[125][260] = 1;
TABLE[125][286] = 1;
TABLE[125][285] = 1;
TABLE[125][259] = 1;
TABLE[125][276] = 1;
TABLE[125][272] = 1;
TABLE[125][273] = 1;
TABLE[125][268] = 1;
TABLE[125][264] = 1;
TABLE[125][277] = 1;
TABLE[125][284] = 1;
TABLE[125][256] = 1;
TABLE[125][274] = 1;
TABLE[125][279] = 1;
TABLE[125][267] = 1;
TABLE[125][282] = 1;
TABLE[125][266] = 1;
TABLE[125][280] = 1;
TABLE[125][283] = 1;
TABLE[204][123] = 1;
TABLE[6][260] = 1;
TABLE[6][286] = 1;
TABLE[6][285] = 1;
TABLE[6][259] = 1;
TABLE[6][276] = 1;
TABLE[6][272] = 1;
TABLE[6][273] = 1;
TABLE[6][268] = 1;
TABLE[6][264] = 1;
TABLE[6][277] = 1;
TABLE[6][284] = 1;
TABLE[6][256] = 1;
TABLE[6][274] = 1;
TABLE[6][279] = 1;
TABLE[6][267] = 1;
TABLE[6][282] = 1;
TABLE[6][266] = 1;
TABLE[6][280] = 1;
TABLE[6][283] = 1;
TABLE[126][59] = 1;
TABLE[126][44] = 1;
TABLE[126][123] = 1;
TABLE[126][61] = 1;
TABLE[126][278] = 1;
TABLE[126][299] = 1;
TABLE[126][40] = 1;
TABLE[126][295] = 1;
TABLE[126][294] = 1;
TABLE[126][33] = 1;
TABLE[126][126] = 1;
TABLE[126][45] = 1;
TABLE[126][43] = 1;
TABLE[126][38] = 1;
TABLE[126][63] = 1;
TABLE[126][42] = 1;
TABLE[126][289] = 1;
TABLE[126][297] = 1;
TABLE[126][307] = 1;
TABLE[126][306] = 1;
TABLE[126][308] = 1;
TABLE[126][298] = 1;
TABLE[126][301] = 1;
TABLE[126][303] = 1;
TABLE[126][302] = 1;
TABLE[126][292] = 1;
TABLE[126][304] = 1;
TABLE[126][37] = 1;
TABLE[126][47] = 1;
TABLE[205][59] = 1;
TABLE[7][282] = 1;
TABLE[7][267] = 1;
TABLE[7][279] = 1;
TABLE[7][274] = 1;
TABLE[7][256] = 1;
TABLE[7][284] = 1;
TABLE[7][277] = 1;
TABLE[7][264] = 1;
TABLE[7][268] = 1;
TABLE[7][273] = 1;
TABLE[7][272] = 1;
TABLE[7][276] = 1;
TABLE[7][259] = 1;
TABLE[7][285] = 1;
TABLE[7][286] = 1;
TABLE[7][260] = 1;
TABLE[7][266] = 1;
TABLE[7][283] = 1;
TABLE[7][280] = 1;
TABLE[127][260] = 1;
TABLE[127][286] = 1;
TABLE[127][285] = 1;
TABLE[127][259] = 1;
TABLE[127][276] = 1;
TABLE[127][272] = 1;
TABLE[127][273] = 1;
TABLE[127][268] = 1;
TABLE[127][264] = 1;
TABLE[127][277] = 1;
TABLE[127][284] = 1;
TABLE[127][256] = 1;
TABLE[127][274] = 1;
TABLE[127][279] = 1;
TABLE[127][267] = 1;
TABLE[127][282] = 1;
TABLE[127][266] = 1;
TABLE[127][280] = 1;
TABLE[127][283] = 1;
TABLE[206][282] = 1;
TABLE[206][267] = 1;
TABLE[206][279] = 1;
TABLE[206][274] = 1;
TABLE[206][256] = 1;
TABLE[206][284] = 1;
TABLE[206][277] = 1;
TABLE[206][264] = 1;
TABLE[206][268] = 1;
TABLE[206][273] = 1;
TABLE[206][272] = 1;
TABLE[206][276] = 1;
TABLE[206][259] = 1;
TABLE[206][285] = 1;
TABLE[206][286] = 1;
TABLE[206][260] = 1;
TABLE[206][266] = 1;
TABLE[206][283] = 1;
TABLE[206][280] = 1;
TABLE[8][282] = 1;
TABLE[8][267] = 1;
TABLE[8][279] = 1;
TABLE[8][274] = 1;
TABLE[8][256] = 1;
TABLE[8][284] = 1;
TABLE[8][277] = 1;
TABLE[8][264] = 1;
TABLE[8][268] = 1;
TABLE[8][273] = 1;
TABLE[8][272] = 1;
TABLE[8][276] = 1;
TABLE[8][259] = 1;
TABLE[8][285] = 1;
TABLE[8][286] = 1;
TABLE[8][260] = 1;
TABLE[8][266] = 1;
TABLE[8][283] = 1;
TABLE[8][280] = 1;
TABLE[128][256] = 1;
TABLE[128][274] = 1;
TABLE[128][279] = 1;
TABLE[128][267] = 1;
TABLE[128][282] = 1;
TABLE[129][285] = 1;
TABLE[129][259] = 1;
TABLE[129][276] = 1;
TABLE[129][272] = 1;
TABLE[129][273] = 1;
TABLE[129][268] = 1;
TABLE[129][264] = 1;
TABLE[129][277] = 1;
TABLE[129][284] = 1;
TABLE[129][266] = 1;
TABLE[129][280] = 1;
TABLE[129][283] = 1;
TABLE[130][260] = 1;
TABLE[130][286] = 1;
TABLE[131][260] = 1;
TABLE[131][286] = 1;
TABLE[131][285] = 1;
TABLE[131][259] = 1;
TABLE[131][276] = 1;
TABLE[131][272] = 1;
TABLE[131][273] = 1;
TABLE[131][268] = 1;
TABLE[131][264] = 1;
TABLE[131][277] = 1;
TABLE[131][284] = 1;
TABLE[131][256] = 1;
TABLE[131][274] = 1;
TABLE[131][279] = 1;
TABLE[131][267] = 1;
TABLE[131][282] = 1;
TABLE[131][266] = 1;
TABLE[131][280] = 1;
TABLE[131][283] = 1;
TABLE[207][40] = 1;
TABLE[207][299] = 1;
TABLE[207][42] = 1;
TABLE[207][282] = 1;
TABLE[207][267] = 1;
TABLE[207][279] = 1;
TABLE[207][274] = 1;
TABLE[207][256] = 1;
TABLE[207][284] = 1;
TABLE[207][277] = 1;
TABLE[207][264] = 1;
TABLE[207][268] = 1;
TABLE[207][273] = 1;
TABLE[207][272] = 1;
TABLE[207][276] = 1;
TABLE[207][259] = 1;
TABLE[207][285] = 1;
TABLE[207][286] = 1;
TABLE[207][260] = 1;
TABLE[207][266] = 1;
TABLE[207][283] = 1;
TABLE[207][280] = 1;
TABLE[207][123] = 1;
TABLE[207][44] = 1;
TABLE[207][61] = 1;
TABLE[207][278] = 1;
TABLE[207][63] = 1;
TABLE[207][38] = 1;
TABLE[207][43] = 1;
TABLE[207][45] = 1;
TABLE[207][126] = 1;
TABLE[207][33] = 1;
TABLE[207][294] = 1;
TABLE[207][295] = 1;
TABLE[207][297] = 1;
TABLE[207][289] = 1;
TABLE[207][298] = 1;
TABLE[207][308] = 1;
TABLE[207][306] = 1;
TABLE[207][307] = 1;
TABLE[207][301] = 1;
TABLE[207][303] = 1;
TABLE[207][302] = 1;
TABLE[207][292] = 1;
TABLE[207][304] = 1;
TABLE[207][47] = 1;
TABLE[207][37] = 1;
TABLE[207][59] = 1;
TABLE[207][91] = 1;
TABLE[207][41] = 1;
TABLE[9][256] = 1;
TABLE[10][274] = 1;
TABLE[11][279] = 1;
TABLE[12][267] = 1;
TABLE[13][282] = 1;
TABLE[14][285] = 1;
TABLE[15][259] = 1;
TABLE[16][276] = 1;
TABLE[17][272] = 1;
TABLE[18][273] = 1;
TABLE[19][268] = 1;
TABLE[20][264] = 1;
TABLE[21][277] = 1;
TABLE[22][284] = 1;
TABLE[23][283] = 1;
TABLE[23][280] = 1;
TABLE[24][266] = 1;
TABLE[25][260] = 1;
TABLE[26][286] = 1;
TABLE[27][280] = 1;
TABLE[27][283] = 1;
TABLE[28][280] = 1;
TABLE[28][283] = 1;
TABLE[132][299] = 1;
TABLE[208][123] = 1;
TABLE[29][280] = 1;
TABLE[30][283] = 1;
TABLE[31][284] = 1;
TABLE[31][277] = 1;
TABLE[31][264] = 1;
TABLE[31][268] = 1;
TABLE[31][273] = 1;
TABLE[31][272] = 1;
TABLE[31][276] = 1;
TABLE[31][259] = 1;
TABLE[31][285] = 1;
TABLE[31][286] = 1;
TABLE[31][260] = 1;
TABLE[31][266] = 1;
TABLE[31][283] = 1;
TABLE[31][280] = 1;
TABLE[133][260] = 1;
TABLE[133][286] = 1;
TABLE[133][285] = 1;
TABLE[133][259] = 1;
TABLE[133][276] = 1;
TABLE[133][272] = 1;
TABLE[133][273] = 1;
TABLE[133][268] = 1;
TABLE[133][264] = 1;
TABLE[133][277] = 1;
TABLE[133][284] = 1;
TABLE[133][266] = 1;
TABLE[133][280] = 1;
TABLE[133][283] = 1;
TABLE[209][284] = 1;
TABLE[209][277] = 1;
TABLE[209][264] = 1;
TABLE[209][268] = 1;
TABLE[209][273] = 1;
TABLE[209][272] = 1;
TABLE[209][276] = 1;
TABLE[209][259] = 1;
TABLE[209][285] = 1;
TABLE[209][286] = 1;
TABLE[209][260] = 1;
TABLE[209][266] = 1;
TABLE[209][283] = 1;
TABLE[209][280] = 1;
TABLE[32][59] = 1;
TABLE[32][44] = 1;
TABLE[32][61] = 1;
TABLE[32][123] = 1;
TABLE[32][40] = 1;
TABLE[32][299] = 1;
TABLE[32][278] = 1;
TABLE[32][42] = 1;
TABLE[32][63] = 1;
TABLE[32][38] = 1;
TABLE[32][43] = 1;
TABLE[32][45] = 1;
TABLE[32][126] = 1;
TABLE[32][33] = 1;
TABLE[32][294] = 1;
TABLE[32][295] = 1;
TABLE[32][297] = 1;
TABLE[32][289] = 1;
TABLE[32][298] = 1;
TABLE[32][308] = 1;
TABLE[32][306] = 1;
TABLE[32][307] = 1;
TABLE[32][301] = 1;
TABLE[32][303] = 1;
TABLE[32][302] = 1;
TABLE[32][292] = 1;
TABLE[32][304] = 1;
TABLE[32][47] = 1;
TABLE[32][37] = 1;
TABLE[134][44] = 1;
TABLE[134][123] = 1;
TABLE[134][61] = 1;
TABLE[134][278] = 1;
TABLE[134][299] = 1;
TABLE[134][40] = 1;
TABLE[134][295] = 1;
TABLE[134][294] = 1;
TABLE[134][33] = 1;
TABLE[134][126] = 1;
TABLE[134][45] = 1;
TABLE[134][43] = 1;
TABLE[134][38] = 1;
TABLE[134][63] = 1;
TABLE[134][42] = 1;
TABLE[134][289] = 1;
TABLE[134][297] = 1;
TABLE[134][307] = 1;
TABLE[134][306] = 1;
TABLE[134][308] = 1;
TABLE[134][298] = 1;
TABLE[134][301] = 1;
TABLE[134][303] = 1;
TABLE[134][302] = 1;
TABLE[134][292] = 1;
TABLE[134][304] = 1;
TABLE[134][37] = 1;
TABLE[134][47] = 1;
TABLE[210][61] = 1;
TABLE[210][123] = 1;
TABLE[210][40] = 1;
TABLE[210][299] = 1;
TABLE[210][278] = 1;
TABLE[210][42] = 1;
TABLE[210][63] = 1;
TABLE[210][38] = 1;
TABLE[210][43] = 1;
TABLE[210][45] = 1;
TABLE[210][126] = 1;
TABLE[210][33] = 1;
TABLE[210][294] = 1;
TABLE[210][295] = 1;
TABLE[210][297] = 1;
TABLE[210][289] = 1;
TABLE[210][298] = 1;
TABLE[210][308] = 1;
TABLE[210][306] = 1;
TABLE[210][307] = 1;
TABLE[210][301] = 1;
TABLE[210][303] = 1;
TABLE[210][302] = 1;
TABLE[210][292] = 1;
TABLE[210][304] = 1;
TABLE[210][47] = 1;
TABLE[210][37] = 1;
TABLE[210][59] = 1;
TABLE[210][44] = 1;
TABLE[33][59] = 1;
TABLE[33][44] = 1;
TABLE[33][123] = 1;
TABLE[33][278] = 1;
TABLE[33][295] = 1;
TABLE[33][294] = 1;
TABLE[33][33] = 1;
TABLE[33][126] = 1;
TABLE[33][45] = 1;
TABLE[33][43] = 1;
TABLE[33][38] = 1;
TABLE[33][63] = 1;
TABLE[33][289] = 1;
TABLE[33][297] = 1;
TABLE[33][307] = 1;
TABLE[33][306] = 1;
TABLE[33][308] = 1;
TABLE[33][298] = 1;
TABLE[33][301] = 1;
TABLE[33][303] = 1;
TABLE[33][302] = 1;
TABLE[33][292] = 1;
TABLE[33][304] = 1;
TABLE[33][37] = 1;
TABLE[33][47] = 1;
TABLE[33][61] = 1;
TABLE[33][299] = 1;
TABLE[33][40] = 1;
TABLE[33][42] = 1;
TABLE[135][61] = 1;
TABLE[135][40] = 1;
TABLE[135][299] = 1;
TABLE[135][42] = 1;
TABLE[211][123] = 1;
TABLE[211][278] = 1;
TABLE[211][295] = 1;
TABLE[211][294] = 1;
TABLE[211][33] = 1;
TABLE[211][126] = 1;
TABLE[211][45] = 1;
TABLE[211][43] = 1;
TABLE[211][42] = 1;
TABLE[211][38] = 1;
TABLE[211][63] = 1;
TABLE[211][299] = 1;
TABLE[211][289] = 1;
TABLE[211][40] = 1;
TABLE[211][297] = 1;
TABLE[211][307] = 1;
TABLE[211][306] = 1;
TABLE[211][308] = 1;
TABLE[211][298] = 1;
TABLE[211][301] = 1;
TABLE[211][303] = 1;
TABLE[211][302] = 1;
TABLE[211][292] = 1;
TABLE[211][304] = 1;
TABLE[211][37] = 1;
TABLE[211][47] = 1;
TABLE[211][59] = 1;
TABLE[211][44] = 1;
TABLE[34][260] = 1;
TABLE[34][286] = 1;
TABLE[34][285] = 1;
TABLE[34][259] = 1;
TABLE[34][276] = 1;
TABLE[34][272] = 1;
TABLE[34][273] = 1;
TABLE[34][268] = 1;
TABLE[34][264] = 1;
TABLE[34][277] = 1;
TABLE[34][284] = 1;
TABLE[34][266] = 1;
TABLE[34][280] = 1;
TABLE[34][283] = 1;
TABLE[35][284] = 1;
TABLE[35][277] = 1;
TABLE[35][264] = 1;
TABLE[35][268] = 1;
TABLE[35][273] = 1;
TABLE[35][272] = 1;
TABLE[35][276] = 1;
TABLE[35][259] = 1;
TABLE[35][285] = 1;
TABLE[35][286] = 1;
TABLE[35][260] = 1;
TABLE[35][266] = 1;
TABLE[35][283] = 1;
TABLE[35][280] = 1;
TABLE[136][285] = 1;
TABLE[136][259] = 1;
TABLE[136][276] = 1;
TABLE[136][272] = 1;
TABLE[136][273] = 1;
TABLE[136][268] = 1;
TABLE[136][264] = 1;
TABLE[136][277] = 1;
TABLE[136][284] = 1;
TABLE[136][266] = 1;
TABLE[136][280] = 1;
TABLE[136][283] = 1;
TABLE[137][260] = 1;
TABLE[137][286] = 1;
TABLE[138][260] = 1;
TABLE[138][286] = 1;
TABLE[138][285] = 1;
TABLE[138][259] = 1;
TABLE[138][276] = 1;
TABLE[138][272] = 1;
TABLE[138][273] = 1;
TABLE[138][268] = 1;
TABLE[138][264] = 1;
TABLE[138][277] = 1;
TABLE[138][284] = 1;
TABLE[138][266] = 1;
TABLE[138][280] = 1;
TABLE[138][283] = 1;
TABLE[212][44] = 1;
TABLE[212][58] = 1;
TABLE[212][40] = 1;
TABLE[212][299] = 1;
TABLE[212][42] = 1;
TABLE[212][59] = 1;
TABLE[212][91] = 1;
TABLE[212][41] = 1;
TABLE[36][59] = 1;
TABLE[36][44] = 1;
TABLE[36][58] = 1;
TABLE[36][299] = 1;
TABLE[36][40] = 1;
TABLE[36][42] = 1;
TABLE[139][44] = 1;
TABLE[139][58] = 1;
TABLE[139][40] = 1;
TABLE[139][299] = 1;
TABLE[139][42] = 1;
TABLE[213][58] = 1;
TABLE[213][299] = 1;
TABLE[213][40] = 1;
TABLE[213][42] = 1;
TABLE[213][59] = 1;
TABLE[213][44] = 1;
TABLE[37][59] = 1;
TABLE[37][44] = 1;
TABLE[37][40] = 1;
TABLE[37][299] = 1;
TABLE[37][42] = 1;
TABLE[38][58] = 1;
TABLE[38][299] = 1;
TABLE[38][40] = 1;
TABLE[38][42] = 1;
TABLE[140][58] = 1;
TABLE[140][40] = 1;
TABLE[140][299] = 1;
TABLE[140][42] = 1;
TABLE[214][58] = 1;
TABLE[39][266] = 1;
TABLE[40][266] = 1;
TABLE[141][299] = 1;
TABLE[215][123] = 1;
TABLE[41][44] = 1;
TABLE[41][299] = 1;
TABLE[142][44] = 1;
TABLE[142][299] = 1;
TABLE[216][299] = 1;
TABLE[42][299] = 1;
TABLE[143][61] = 1;
TABLE[217][125] = 1;
TABLE[217][44] = 1;
TABLE[43][299] = 1;
TABLE[43][40] = 1;
TABLE[43][42] = 1;
TABLE[144][42] = 1;
TABLE[218][299] = 1;
TABLE[218][40] = 1;
TABLE[44][299] = 1;
TABLE[45][40] = 1;
TABLE[46][299] = 1;
TABLE[46][40] = 1;
TABLE[146][91] = 1;
TABLE[147][40] = 1;
TABLE[149][40] = 1;
TABLE[145][93] = 1;
TABLE[145][63] = 1;
TABLE[145][297] = 1;
TABLE[145][298] = 1;
TABLE[145][301] = 1;
TABLE[145][303] = 1;
TABLE[145][302] = 1;
TABLE[145][292] = 1;
TABLE[145][304] = 1;
TABLE[145][40] = 1;
TABLE[145][45] = 1;
TABLE[145][43] = 1;
TABLE[145][42] = 1;
TABLE[145][47] = 1;
TABLE[145][37] = 1;
TABLE[145][278] = 1;
TABLE[145][295] = 1;
TABLE[145][294] = 1;
TABLE[145][33] = 1;
TABLE[145][126] = 1;
TABLE[145][38] = 1;
TABLE[145][299] = 1;
TABLE[145][289] = 1;
TABLE[145][307] = 1;
TABLE[145][306] = 1;
TABLE[145][308] = 1;
TABLE[219][93] = 1;
TABLE[148][41] = 1;
TABLE[148][299] = 1;
TABLE[148][44] = 1;
TABLE[220][41] = 1;
TABLE[47][42] = 1;
TABLE[150][42] = 1;
TABLE[150][299] = 1;
TABLE[150][40] = 1;
TABLE[150][44] = 1;
TABLE[150][41] = 1;
TABLE[150][91] = 1;
TABLE[150][286] = 1;
TABLE[150][260] = 1;
TABLE[221][42] = 1;
TABLE[221][299] = 1;
TABLE[221][40] = 1;
TABLE[221][44] = 1;
TABLE[221][41] = 1;
TABLE[221][91] = 1;
TABLE[151][42] = 1;
TABLE[222][299] = 1;
TABLE[222][40] = 1;
TABLE[222][44] = 1;
TABLE[222][41] = 1;
TABLE[222][91] = 1;
TABLE[48][260] = 1;
TABLE[48][286] = 1;
TABLE[152][286] = 1;
TABLE[152][260] = 1;
TABLE[223][260] = 1;
TABLE[223][286] = 1;
TABLE[49][41] = 1;
TABLE[49][44] = 1;
TABLE[49][260] = 1;
TABLE[49][286] = 1;
TABLE[49][285] = 1;
TABLE[49][259] = 1;
TABLE[49][276] = 1;
TABLE[49][272] = 1;
TABLE[49][273] = 1;
TABLE[49][268] = 1;
TABLE[49][264] = 1;
TABLE[49][277] = 1;
TABLE[49][284] = 1;
TABLE[49][256] = 1;
TABLE[49][274] = 1;
TABLE[49][279] = 1;
TABLE[49][267] = 1;
TABLE[49][282] = 1;
TABLE[49][266] = 1;
TABLE[49][280] = 1;
TABLE[49][283] = 1;
TABLE[153][44] = 1;
TABLE[224][41] = 1;
TABLE[50][44] = 1;
TABLE[50][282] = 1;
TABLE[50][267] = 1;
TABLE[50][279] = 1;
TABLE[50][274] = 1;
TABLE[50][256] = 1;
TABLE[50][284] = 1;
TABLE[50][277] = 1;
TABLE[50][264] = 1;
TABLE[50][268] = 1;
TABLE[50][273] = 1;
TABLE[50][272] = 1;
TABLE[50][276] = 1;
TABLE[50][259] = 1;
TABLE[50][285] = 1;
TABLE[50][286] = 1;
TABLE[50][260] = 1;
TABLE[50][266] = 1;
TABLE[50][283] = 1;
TABLE[50][280] = 1;
TABLE[154][44] = 1;
TABLE[154][260] = 1;
TABLE[154][286] = 1;
TABLE[154][285] = 1;
TABLE[154][259] = 1;
TABLE[154][276] = 1;
TABLE[154][272] = 1;
TABLE[154][273] = 1;
TABLE[154][268] = 1;
TABLE[154][264] = 1;
TABLE[154][277] = 1;
TABLE[154][284] = 1;
TABLE[154][256] = 1;
TABLE[154][274] = 1;
TABLE[154][279] = 1;
TABLE[154][267] = 1;
TABLE[154][282] = 1;
TABLE[154][266] = 1;
TABLE[154][280] = 1;
TABLE[154][283] = 1;
TABLE[225][282] = 1;
TABLE[225][267] = 1;
TABLE[225][279] = 1;
TABLE[225][274] = 1;
TABLE[225][256] = 1;
TABLE[225][284] = 1;
TABLE[225][277] = 1;
TABLE[225][264] = 1;
TABLE[225][268] = 1;
TABLE[225][273] = 1;
TABLE[225][272] = 1;
TABLE[225][276] = 1;
TABLE[225][259] = 1;
TABLE[225][285] = 1;
TABLE[225][286] = 1;
TABLE[225][260] = 1;
TABLE[225][266] = 1;
TABLE[225][283] = 1;
TABLE[225][280] = 1;
TABLE[51][260] = 1;
TABLE[51][286] = 1;
TABLE[51][285] = 1;
TABLE[51][259] = 1;
TABLE[51][276] = 1;
TABLE[51][272] = 1;
TABLE[51][273] = 1;
TABLE[51][268] = 1;
TABLE[51][264] = 1;
TABLE[51][277] = 1;
TABLE[51][284] = 1;
TABLE[51][256] = 1;
TABLE[51][274] = 1;
TABLE[51][279] = 1;
TABLE[51][267] = 1;
TABLE[51][282] = 1;
TABLE[51][266] = 1;
TABLE[51][280] = 1;
TABLE[51][283] = 1;
TABLE[155][44] = 1;
TABLE[155][41] = 1;
TABLE[155][40] = 1;
TABLE[155][299] = 1;
TABLE[155][42] = 1;
TABLE[157][44] = 1;
TABLE[157][41] = 1;
TABLE[157][42] = 1;
TABLE[157][40] = 1;
TABLE[157][91] = 1;
TABLE[156][44] = 1;
TABLE[156][41] = 1;
TABLE[156][42] = 1;
TABLE[156][40] = 1;
TABLE[156][91] = 1;
TABLE[226][44] = 1;
TABLE[226][41] = 1;
TABLE[52][299] = 1;
TABLE[52][44] = 1;
TABLE[158][299] = 1;
TABLE[158][44] = 1;
TABLE[227][299] = 1;
TABLE[53][59] = 1;
TABLE[53][44] = 1;
TABLE[53][125] = 1;
TABLE[53][278] = 1;
TABLE[53][63] = 1;
TABLE[53][38] = 1;
TABLE[53][42] = 1;
TABLE[53][43] = 1;
TABLE[53][45] = 1;
TABLE[53][126] = 1;
TABLE[53][33] = 1;
TABLE[53][294] = 1;
TABLE[53][295] = 1;
TABLE[53][297] = 1;
TABLE[53][40] = 1;
TABLE[53][289] = 1;
TABLE[53][299] = 1;
TABLE[53][298] = 1;
TABLE[53][308] = 1;
TABLE[53][306] = 1;
TABLE[53][307] = 1;
TABLE[53][301] = 1;
TABLE[53][303] = 1;
TABLE[53][302] = 1;
TABLE[53][292] = 1;
TABLE[53][304] = 1;
TABLE[53][47] = 1;
TABLE[53][37] = 1;
TABLE[54][123] = 1;
TABLE[159][44] = 1;
TABLE[228][125] = 1;
TABLE[55][125] = 1;
TABLE[55][123] = 1;
TABLE[55][44] = 1;
TABLE[55][278] = 1;
TABLE[55][295] = 1;
TABLE[55][294] = 1;
TABLE[55][33] = 1;
TABLE[55][126] = 1;
TABLE[55][45] = 1;
TABLE[55][43] = 1;
TABLE[55][42] = 1;
TABLE[55][38] = 1;
TABLE[55][63] = 1;
TABLE[55][299] = 1;
TABLE[55][289] = 1;
TABLE[55][40] = 1;
TABLE[55][297] = 1;
TABLE[55][307] = 1;
TABLE[55][306] = 1;
TABLE[55][308] = 1;
TABLE[55][298] = 1;
TABLE[55][301] = 1;
TABLE[55][303] = 1;
TABLE[55][302] = 1;
TABLE[55][292] = 1;
TABLE[55][304] = 1;
TABLE[55][37] = 1;
TABLE[55][47] = 1;
TABLE[160][123] = 1;
TABLE[160][44] = 1;
TABLE[160][278] = 1;
TABLE[160][63] = 1;
TABLE[160][38] = 1;
TABLE[160][42] = 1;
TABLE[160][43] = 1;
TABLE[160][45] = 1;
TABLE[160][126] = 1;
TABLE[160][33] = 1;
TABLE[160][294] = 1;
TABLE[160][295] = 1;
TABLE[160][297] = 1;
TABLE[160][40] = 1;
TABLE[160][289] = 1;
TABLE[160][299] = 1;
TABLE[160][298] = 1;
TABLE[160][308] = 1;
TABLE[160][306] = 1;
TABLE[160][307] = 1;
TABLE[160][301] = 1;
TABLE[160][303] = 1;
TABLE[160][302] = 1;
TABLE[160][292] = 1;
TABLE[160][304] = 1;
TABLE[160][47] = 1;
TABLE[160][37] = 1;
TABLE[229][123] = 1;
TABLE[229][278] = 1;
TABLE[229][295] = 1;
TABLE[229][294] = 1;
TABLE[229][33] = 1;
TABLE[229][126] = 1;
TABLE[229][45] = 1;
TABLE[229][43] = 1;
TABLE[229][42] = 1;
TABLE[229][38] = 1;
TABLE[229][63] = 1;
TABLE[229][299] = 1;
TABLE[229][289] = 1;
TABLE[229][40] = 1;
TABLE[229][297] = 1;
TABLE[229][307] = 1;
TABLE[229][306] = 1;
TABLE[229][308] = 1;
TABLE[229][298] = 1;
TABLE[229][301] = 1;
TABLE[229][303] = 1;
TABLE[229][302] = 1;
TABLE[229][292] = 1;
TABLE[229][304] = 1;
TABLE[229][37] = 1;
TABLE[229][47] = 1;
TABLE[229][44] = 1;
TABLE[229][125] = 1;
TABLE[56][260] = 1;
TABLE[56][286] = 1;
TABLE[56][285] = 1;
TABLE[56][259] = 1;
TABLE[56][276] = 1;
TABLE[56][272] = 1;
TABLE[56][273] = 1;
TABLE[56][268] = 1;
TABLE[56][264] = 1;
TABLE[56][277] = 1;
TABLE[56][284] = 1;
TABLE[56][266] = 1;
TABLE[56][280] = 1;
TABLE[56][283] = 1;
TABLE[161][41] = 1;
TABLE[161][42] = 1;
TABLE[161][40] = 1;
TABLE[161][91] = 1;
TABLE[230][41] = 1;
TABLE[57][42] = 1;
TABLE[58][44] = 1;
TABLE[58][41] = 1;
TABLE[58][40] = 1;
TABLE[58][91] = 1;
TABLE[58][42] = 1;
TABLE[162][42] = 1;
TABLE[231][40] = 1;
TABLE[231][91] = 1;
TABLE[231][44] = 1;
TABLE[231][41] = 1;
TABLE[59][40] = 1;
TABLE[60][40] = 1;
TABLE[60][91] = 1;
TABLE[163][40] = 1;
TABLE[163][91] = 1;
TABLE[232][91] = 1;
TABLE[232][40] = 1;
TABLE[165][91] = 1;
TABLE[167][40] = 1;
TABLE[164][93] = 1;
TABLE[164][63] = 1;
TABLE[164][297] = 1;
TABLE[164][298] = 1;
TABLE[164][301] = 1;
TABLE[164][303] = 1;
TABLE[164][302] = 1;
TABLE[164][292] = 1;
TABLE[164][304] = 1;
TABLE[164][40] = 1;
TABLE[164][45] = 1;
TABLE[164][43] = 1;
TABLE[164][42] = 1;
TABLE[164][47] = 1;
TABLE[164][37] = 1;
TABLE[164][278] = 1;
TABLE[164][295] = 1;
TABLE[164][294] = 1;
TABLE[164][33] = 1;
TABLE[164][126] = 1;
TABLE[164][38] = 1;
TABLE[164][299] = 1;
TABLE[164][289] = 1;
TABLE[164][307] = 1;
TABLE[164][306] = 1;
TABLE[164][308] = 1;
TABLE[233][93] = 1;
TABLE[166][41] = 1;
TABLE[166][44] = 1;
TABLE[166][282] = 1;
TABLE[166][267] = 1;
TABLE[166][279] = 1;
TABLE[166][274] = 1;
TABLE[166][256] = 1;
TABLE[166][284] = 1;
TABLE[166][277] = 1;
TABLE[166][264] = 1;
TABLE[166][268] = 1;
TABLE[166][273] = 1;
TABLE[166][272] = 1;
TABLE[166][276] = 1;
TABLE[166][259] = 1;
TABLE[166][285] = 1;
TABLE[166][286] = 1;
TABLE[166][260] = 1;
TABLE[166][266] = 1;
TABLE[166][283] = 1;
TABLE[166][280] = 1;
TABLE[234][41] = 1;
TABLE[61][299] = 1;
TABLE[62][299] = 1;
TABLE[62][258] = 1;
TABLE[62][262] = 1;
TABLE[63][125] = 1;
TABLE[63][265] = 1;
TABLE[63][287] = 1;
TABLE[63][262] = 1;
TABLE[63][258] = 1;
TABLE[63][123] = 1;
TABLE[63][281] = 1;
TABLE[63][271] = 1;
TABLE[63][269] = 1;
TABLE[63][263] = 1;
TABLE[63][275] = 1;
TABLE[63][257] = 1;
TABLE[63][261] = 1;
TABLE[63][270] = 1;
TABLE[63][59] = 1;
TABLE[63][44] = 1;
TABLE[63][278] = 1;
TABLE[63][295] = 1;
TABLE[63][294] = 1;
TABLE[63][33] = 1;
TABLE[63][126] = 1;
TABLE[63][45] = 1;
TABLE[63][43] = 1;
TABLE[63][42] = 1;
TABLE[63][38] = 1;
TABLE[63][63] = 1;
TABLE[63][299] = 1;
TABLE[63][289] = 1;
TABLE[63][40] = 1;
TABLE[63][297] = 1;
TABLE[63][307] = 1;
TABLE[63][306] = 1;
TABLE[63][308] = 1;
TABLE[63][298] = 1;
TABLE[63][301] = 1;
TABLE[63][303] = 1;
TABLE[63][302] = 1;
TABLE[63][292] = 1;
TABLE[63][304] = 1;
TABLE[63][37] = 1;
TABLE[63][47] = 1;
TABLE[64][123] = 1;
TABLE[65][271] = 1;
TABLE[65][281] = 1;
TABLE[66][287] = 1;
TABLE[66][263] = 1;
TABLE[66][269] = 1;
TABLE[67][270] = 1;
TABLE[67][261] = 1;
TABLE[67][257] = 1;
TABLE[67][275] = 1;
TABLE[68][299] = 1;
TABLE[69][258] = 1;
TABLE[70][262] = 1;
TABLE[71][59] = 1;
TABLE[71][44] = 1;
TABLE[71][278] = 1;
TABLE[71][63] = 1;
TABLE[71][38] = 1;
TABLE[71][42] = 1;
TABLE[71][43] = 1;
TABLE[71][45] = 1;
TABLE[71][126] = 1;
TABLE[71][33] = 1;
TABLE[71][294] = 1;
TABLE[71][295] = 1;
TABLE[71][297] = 1;
TABLE[71][40] = 1;
TABLE[71][289] = 1;
TABLE[71][299] = 1;
TABLE[71][298] = 1;
TABLE[71][308] = 1;
TABLE[71][306] = 1;
TABLE[71][307] = 1;
TABLE[71][301] = 1;
TABLE[71][303] = 1;
TABLE[71][302] = 1;
TABLE[71][292] = 1;
TABLE[71][304] = 1;
TABLE[71][47] = 1;
TABLE[71][37] = 1;
TABLE[168][59] = 1;
TABLE[168][44] = 1;
TABLE[168][278] = 1;
TABLE[168][295] = 1;
TABLE[168][294] = 1;
TABLE[168][33] = 1;
TABLE[168][126] = 1;
TABLE[168][45] = 1;
TABLE[168][43] = 1;
TABLE[168][42] = 1;
TABLE[168][38] = 1;
TABLE[168][63] = 1;
TABLE[168][299] = 1;
TABLE[168][289] = 1;
TABLE[168][40] = 1;
TABLE[168][297] = 1;
TABLE[168][307] = 1;
TABLE[168][306] = 1;
TABLE[168][308] = 1;
TABLE[168][298] = 1;
TABLE[168][301] = 1;
TABLE[168][303] = 1;
TABLE[168][302] = 1;
TABLE[168][292] = 1;
TABLE[168][304] = 1;
TABLE[168][37] = 1;
TABLE[168][47] = 1;
TABLE[235][59] = 1;
TABLE[72][123] = 1;
TABLE[169][262] = 1;
TABLE[169][258] = 1;
TABLE[169][299] = 1;
TABLE[169][59] = 1;
TABLE[169][123] = 1;
TABLE[169][281] = 1;
TABLE[169][271] = 1;
TABLE[169][269] = 1;
TABLE[169][263] = 1;
TABLE[169][287] = 1;
TABLE[169][275] = 1;
TABLE[169][257] = 1;
TABLE[169][261] = 1;
TABLE[169][270] = 1;
TABLE[169][44] = 1;
TABLE[169][278] = 1;
TABLE[169][63] = 1;
TABLE[169][38] = 1;
TABLE[169][42] = 1;
TABLE[169][43] = 1;
TABLE[169][45] = 1;
TABLE[169][126] = 1;
TABLE[169][33] = 1;
TABLE[169][294] = 1;
TABLE[169][295] = 1;
TABLE[169][297] = 1;
TABLE[169][40] = 1;
TABLE[169][289] = 1;
TABLE[169][298] = 1;
TABLE[169][308] = 1;
TABLE[169][306] = 1;
TABLE[169][307] = 1;
TABLE[169][301] = 1;
TABLE[169][303] = 1;
TABLE[169][302] = 1;
TABLE[169][292] = 1;
TABLE[169][304] = 1;
TABLE[169][47] = 1;
TABLE[169][37] = 1;
TABLE[169][125] = 1;
TABLE[169][260] = 1;
TABLE[169][286] = 1;
TABLE[169][285] = 1;
TABLE[169][259] = 1;
TABLE[169][276] = 1;
TABLE[169][272] = 1;
TABLE[169][273] = 1;
TABLE[169][268] = 1;
TABLE[169][264] = 1;
TABLE[169][277] = 1;
TABLE[169][284] = 1;
TABLE[169][256] = 1;
TABLE[169][274] = 1;
TABLE[169][279] = 1;
TABLE[169][267] = 1;
TABLE[169][282] = 1;
TABLE[169][266] = 1;
TABLE[169][280] = 1;
TABLE[169][283] = 1;
TABLE[236][262] = 1;
TABLE[236][258] = 1;
TABLE[236][299] = 1;
TABLE[236][59] = 1;
TABLE[236][123] = 1;
TABLE[236][281] = 1;
TABLE[236][271] = 1;
TABLE[236][269] = 1;
TABLE[236][263] = 1;
TABLE[236][287] = 1;
TABLE[236][275] = 1;
TABLE[236][257] = 1;
TABLE[236][261] = 1;
TABLE[236][270] = 1;
TABLE[236][44] = 1;
TABLE[236][278] = 1;
TABLE[236][63] = 1;
TABLE[236][38] = 1;
TABLE[236][42] = 1;
TABLE[236][43] = 1;
TABLE[236][45] = 1;
TABLE[236][126] = 1;
TABLE[236][33] = 1;
TABLE[236][294] = 1;
TABLE[236][295] = 1;
TABLE[236][297] = 1;
TABLE[236][40] = 1;
TABLE[236][289] = 1;
TABLE[236][298] = 1;
TABLE[236][308] = 1;
TABLE[236][306] = 1;
TABLE[236][307] = 1;
TABLE[236][301] = 1;
TABLE[236][303] = 1;
TABLE[236][302] = 1;
TABLE[236][292] = 1;
TABLE[236][304] = 1;
TABLE[236][47] = 1;
TABLE[236][37] = 1;
TABLE[236][125] = 1;
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
TABLE[170][299] = 1;
TABLE[170][258] = 1;
TABLE[170][262] = 1;
TABLE[170][44] = 1;
TABLE[170][278] = 1;
TABLE[170][295] = 1;
TABLE[170][294] = 1;
TABLE[170][33] = 1;
TABLE[170][126] = 1;
TABLE[170][45] = 1;
TABLE[170][43] = 1;
TABLE[170][42] = 1;
TABLE[170][38] = 1;
TABLE[170][63] = 1;
TABLE[170][289] = 1;
TABLE[170][40] = 1;
TABLE[170][297] = 1;
TABLE[170][307] = 1;
TABLE[170][306] = 1;
TABLE[170][308] = 1;
TABLE[170][298] = 1;
TABLE[170][301] = 1;
TABLE[170][303] = 1;
TABLE[170][302] = 1;
TABLE[170][292] = 1;
TABLE[170][304] = 1;
TABLE[170][37] = 1;
TABLE[170][47] = 1;
TABLE[237][125] = 1;
TABLE[73][125] = 1;
TABLE[73][262] = 1;
TABLE[73][258] = 1;
TABLE[73][299] = 1;
TABLE[73][59] = 1;
TABLE[73][123] = 1;
TABLE[73][281] = 1;
TABLE[73][271] = 1;
TABLE[73][269] = 1;
TABLE[73][263] = 1;
TABLE[73][287] = 1;
TABLE[73][275] = 1;
TABLE[73][257] = 1;
TABLE[73][261] = 1;
TABLE[73][270] = 1;
TABLE[73][44] = 1;
TABLE[73][278] = 1;
TABLE[73][63] = 1;
TABLE[73][38] = 1;
TABLE[73][42] = 1;
TABLE[73][43] = 1;
TABLE[73][45] = 1;
TABLE[73][126] = 1;
TABLE[73][33] = 1;
TABLE[73][294] = 1;
TABLE[73][295] = 1;
TABLE[73][297] = 1;
TABLE[73][40] = 1;
TABLE[73][289] = 1;
TABLE[73][298] = 1;
TABLE[73][308] = 1;
TABLE[73][306] = 1;
TABLE[73][307] = 1;
TABLE[73][301] = 1;
TABLE[73][303] = 1;
TABLE[73][302] = 1;
TABLE[73][292] = 1;
TABLE[73][304] = 1;
TABLE[73][47] = 1;
TABLE[73][37] = 1;
TABLE[171][125] = 1;
TABLE[171][270] = 1;
TABLE[171][261] = 1;
TABLE[171][257] = 1;
TABLE[171][275] = 1;
TABLE[171][287] = 1;
TABLE[171][263] = 1;
TABLE[171][269] = 1;
TABLE[171][271] = 1;
TABLE[171][281] = 1;
TABLE[171][123] = 1;
TABLE[171][59] = 1;
TABLE[171][299] = 1;
TABLE[171][258] = 1;
TABLE[171][262] = 1;
TABLE[171][44] = 1;
TABLE[171][278] = 1;
TABLE[171][295] = 1;
TABLE[171][294] = 1;
TABLE[171][33] = 1;
TABLE[171][126] = 1;
TABLE[171][45] = 1;
TABLE[171][43] = 1;
TABLE[171][42] = 1;
TABLE[171][38] = 1;
TABLE[171][63] = 1;
TABLE[171][289] = 1;
TABLE[171][40] = 1;
TABLE[171][297] = 1;
TABLE[171][307] = 1;
TABLE[171][306] = 1;
TABLE[171][308] = 1;
TABLE[171][298] = 1;
TABLE[171][301] = 1;
TABLE[171][303] = 1;
TABLE[171][302] = 1;
TABLE[171][292] = 1;
TABLE[171][304] = 1;
TABLE[171][37] = 1;
TABLE[171][47] = 1;
TABLE[238][262] = 1;
TABLE[238][258] = 1;
TABLE[238][299] = 1;
TABLE[238][59] = 1;
TABLE[238][123] = 1;
TABLE[238][281] = 1;
TABLE[238][271] = 1;
TABLE[238][269] = 1;
TABLE[238][263] = 1;
TABLE[238][287] = 1;
TABLE[238][275] = 1;
TABLE[238][257] = 1;
TABLE[238][261] = 1;
TABLE[238][270] = 1;
TABLE[238][44] = 1;
TABLE[238][278] = 1;
TABLE[238][63] = 1;
TABLE[238][38] = 1;
TABLE[238][42] = 1;
TABLE[238][43] = 1;
TABLE[238][45] = 1;
TABLE[238][126] = 1;
TABLE[238][33] = 1;
TABLE[238][294] = 1;
TABLE[238][295] = 1;
TABLE[238][297] = 1;
TABLE[238][40] = 1;
TABLE[238][289] = 1;
TABLE[238][298] = 1;
TABLE[238][308] = 1;
TABLE[238][306] = 1;
TABLE[238][307] = 1;
TABLE[238][301] = 1;
TABLE[238][303] = 1;
TABLE[238][302] = 1;
TABLE[238][292] = 1;
TABLE[238][304] = 1;
TABLE[238][47] = 1;
TABLE[238][37] = 1;
TABLE[238][125] = 1;
TABLE[74][271] = 1;
TABLE[75][281] = 1;
TABLE[172][265] = 1;
TABLE[239][125] = 1;
TABLE[239][265] = 1;
TABLE[239][287] = 1;
TABLE[239][262] = 1;
TABLE[239][258] = 1;
TABLE[239][299] = 1;
TABLE[239][59] = 1;
TABLE[239][123] = 1;
TABLE[239][281] = 1;
TABLE[239][271] = 1;
TABLE[239][269] = 1;
TABLE[239][263] = 1;
TABLE[239][275] = 1;
TABLE[239][257] = 1;
TABLE[239][261] = 1;
TABLE[239][270] = 1;
TABLE[239][44] = 1;
TABLE[239][278] = 1;
TABLE[239][63] = 1;
TABLE[239][38] = 1;
TABLE[239][42] = 1;
TABLE[239][43] = 1;
TABLE[239][45] = 1;
TABLE[239][126] = 1;
TABLE[239][33] = 1;
TABLE[239][294] = 1;
TABLE[239][295] = 1;
TABLE[239][297] = 1;
TABLE[239][40] = 1;
TABLE[239][289] = 1;
TABLE[239][298] = 1;
TABLE[239][308] = 1;
TABLE[239][306] = 1;
TABLE[239][307] = 1;
TABLE[239][301] = 1;
TABLE[239][303] = 1;
TABLE[239][302] = 1;
TABLE[239][292] = 1;
TABLE[239][304] = 1;
TABLE[239][47] = 1;
TABLE[239][37] = 1;
TABLE[76][287] = 1;
TABLE[77][263] = 1;
TABLE[78][269] = 1;
TABLE[173][59] = 1;
TABLE[173][44] = 1;
TABLE[173][278] = 1;
TABLE[173][295] = 1;
TABLE[173][294] = 1;
TABLE[173][33] = 1;
TABLE[173][126] = 1;
TABLE[173][45] = 1;
TABLE[173][43] = 1;
TABLE[173][42] = 1;
TABLE[173][38] = 1;
TABLE[173][63] = 1;
TABLE[173][299] = 1;
TABLE[173][289] = 1;
TABLE[173][40] = 1;
TABLE[173][297] = 1;
TABLE[173][307] = 1;
TABLE[173][306] = 1;
TABLE[173][308] = 1;
TABLE[173][298] = 1;
TABLE[173][301] = 1;
TABLE[173][303] = 1;
TABLE[173][302] = 1;
TABLE[173][292] = 1;
TABLE[173][304] = 1;
TABLE[173][37] = 1;
TABLE[173][47] = 1;
TABLE[240][59] = 1;
TABLE[174][59] = 1;
TABLE[174][44] = 1;
TABLE[174][278] = 1;
TABLE[174][295] = 1;
TABLE[174][294] = 1;
TABLE[174][33] = 1;
TABLE[174][126] = 1;
TABLE[174][45] = 1;
TABLE[174][43] = 1;
TABLE[174][42] = 1;
TABLE[174][38] = 1;
TABLE[174][63] = 1;
TABLE[174][299] = 1;
TABLE[174][289] = 1;
TABLE[174][40] = 1;
TABLE[174][297] = 1;
TABLE[174][307] = 1;
TABLE[174][306] = 1;
TABLE[174][308] = 1;
TABLE[174][298] = 1;
TABLE[174][301] = 1;
TABLE[174][303] = 1;
TABLE[174][302] = 1;
TABLE[174][292] = 1;
TABLE[174][304] = 1;
TABLE[174][37] = 1;
TABLE[174][47] = 1;
TABLE[241][59] = 1;
TABLE[175][41] = 1;
TABLE[175][44] = 1;
TABLE[175][278] = 1;
TABLE[175][295] = 1;
TABLE[175][294] = 1;
TABLE[175][33] = 1;
TABLE[175][126] = 1;
TABLE[175][45] = 1;
TABLE[175][43] = 1;
TABLE[175][42] = 1;
TABLE[175][38] = 1;
TABLE[175][63] = 1;
TABLE[175][299] = 1;
TABLE[175][289] = 1;
TABLE[175][40] = 1;
TABLE[175][297] = 1;
TABLE[175][307] = 1;
TABLE[175][306] = 1;
TABLE[175][308] = 1;
TABLE[175][298] = 1;
TABLE[175][301] = 1;
TABLE[175][303] = 1;
TABLE[175][302] = 1;
TABLE[175][292] = 1;
TABLE[175][304] = 1;
TABLE[175][37] = 1;
TABLE[175][47] = 1;
TABLE[242][41] = 1;
TABLE[79][270] = 1;
TABLE[80][261] = 1;
TABLE[81][257] = 1;
TABLE[82][275] = 1;
TABLE[176][59] = 1;
TABLE[176][44] = 1;
TABLE[176][278] = 1;
TABLE[176][295] = 1;
TABLE[176][294] = 1;
TABLE[176][33] = 1;
TABLE[176][126] = 1;
TABLE[176][45] = 1;
TABLE[176][43] = 1;
TABLE[176][42] = 1;
TABLE[176][38] = 1;
TABLE[176][63] = 1;
TABLE[176][299] = 1;
TABLE[176][289] = 1;
TABLE[176][40] = 1;
TABLE[176][297] = 1;
TABLE[176][307] = 1;
TABLE[176][306] = 1;
TABLE[176][308] = 1;
TABLE[176][298] = 1;
TABLE[176][301] = 1;
TABLE[176][303] = 1;
TABLE[176][302] = 1;
TABLE[176][292] = 1;
TABLE[176][304] = 1;
TABLE[176][37] = 1;
TABLE[176][47] = 1;
TABLE[243][59] = 1;
TABLE[83][59] = 1;
TABLE[83][41] = 1;
TABLE[83][58] = 1;
TABLE[83][93] = 1;
TABLE[83][44] = 1;
TABLE[83][278] = 1;
TABLE[83][63] = 1;
TABLE[83][38] = 1;
TABLE[83][42] = 1;
TABLE[83][43] = 1;
TABLE[83][45] = 1;
TABLE[83][126] = 1;
TABLE[83][33] = 1;
TABLE[83][294] = 1;
TABLE[83][295] = 1;
TABLE[83][297] = 1;
TABLE[83][40] = 1;
TABLE[83][289] = 1;
TABLE[83][299] = 1;
TABLE[83][298] = 1;
TABLE[83][308] = 1;
TABLE[83][306] = 1;
TABLE[83][307] = 1;
TABLE[83][301] = 1;
TABLE[83][303] = 1;
TABLE[83][302] = 1;
TABLE[83][292] = 1;
TABLE[83][304] = 1;
TABLE[83][47] = 1;
TABLE[83][37] = 1;
TABLE[177][44] = 1;
TABLE[177][278] = 1;
TABLE[177][295] = 1;
TABLE[177][294] = 1;
TABLE[177][33] = 1;
TABLE[177][126] = 1;
TABLE[177][45] = 1;
TABLE[177][43] = 1;
TABLE[177][42] = 1;
TABLE[177][38] = 1;
TABLE[177][63] = 1;
TABLE[177][299] = 1;
TABLE[177][289] = 1;
TABLE[177][40] = 1;
TABLE[177][297] = 1;
TABLE[177][307] = 1;
TABLE[177][306] = 1;
TABLE[177][308] = 1;
TABLE[177][298] = 1;
TABLE[177][301] = 1;
TABLE[177][303] = 1;
TABLE[177][302] = 1;
TABLE[177][292] = 1;
TABLE[177][304] = 1;
TABLE[177][37] = 1;
TABLE[177][47] = 1;
TABLE[244][278] = 1;
TABLE[244][63] = 1;
TABLE[244][38] = 1;
TABLE[244][42] = 1;
TABLE[244][43] = 1;
TABLE[244][45] = 1;
TABLE[244][126] = 1;
TABLE[244][33] = 1;
TABLE[244][294] = 1;
TABLE[244][295] = 1;
TABLE[244][297] = 1;
TABLE[244][40] = 1;
TABLE[244][289] = 1;
TABLE[244][299] = 1;
TABLE[244][298] = 1;
TABLE[244][308] = 1;
TABLE[244][306] = 1;
TABLE[244][307] = 1;
TABLE[244][301] = 1;
TABLE[244][303] = 1;
TABLE[244][302] = 1;
TABLE[244][292] = 1;
TABLE[244][304] = 1;
TABLE[244][47] = 1;
TABLE[244][37] = 1;
TABLE[244][59] = 1;
TABLE[244][41] = 1;
TABLE[244][44] = 1;
TABLE[244][58] = 1;
TABLE[244][93] = 1;
TABLE[84][59] = 1;
TABLE[84][41] = 1;
TABLE[84][44] = 1;
TABLE[84][125] = 1;
TABLE[84][58] = 1;
TABLE[84][93] = 1;
TABLE[84][63] = 1;
TABLE[84][297] = 1;
TABLE[84][298] = 1;
TABLE[84][301] = 1;
TABLE[84][303] = 1;
TABLE[84][302] = 1;
TABLE[84][292] = 1;
TABLE[84][304] = 1;
TABLE[84][43] = 1;
TABLE[84][45] = 1;
TABLE[84][40] = 1;
TABLE[84][278] = 1;
TABLE[84][37] = 1;
TABLE[84][47] = 1;
TABLE[84][42] = 1;
TABLE[84][38] = 1;
TABLE[84][126] = 1;
TABLE[84][33] = 1;
TABLE[84][294] = 1;
TABLE[84][295] = 1;
TABLE[84][289] = 1;
TABLE[84][299] = 1;
TABLE[84][308] = 1;
TABLE[84][306] = 1;
TABLE[84][307] = 1;
TABLE[85][278] = 1;
TABLE[85][295] = 1;
TABLE[85][294] = 1;
TABLE[85][33] = 1;
TABLE[85][126] = 1;
TABLE[85][45] = 1;
TABLE[85][43] = 1;
TABLE[85][42] = 1;
TABLE[85][38] = 1;
TABLE[85][299] = 1;
TABLE[85][289] = 1;
TABLE[85][40] = 1;
TABLE[85][307] = 1;
TABLE[85][306] = 1;
TABLE[85][308] = 1;
TABLE[86][291] = 1;
TABLE[87][61] = 1;
TABLE[88][59] = 1;
TABLE[88][41] = 1;
TABLE[88][125] = 1;
TABLE[88][93] = 1;
TABLE[88][58] = 1;
TABLE[88][44] = 1;
TABLE[88][63] = 1;
TABLE[88][297] = 1;
TABLE[88][298] = 1;
TABLE[88][301] = 1;
TABLE[88][303] = 1;
TABLE[88][302] = 1;
TABLE[88][292] = 1;
TABLE[88][304] = 1;
TABLE[88][40] = 1;
TABLE[88][45] = 1;
TABLE[88][43] = 1;
TABLE[88][42] = 1;
TABLE[88][47] = 1;
TABLE[88][37] = 1;
TABLE[88][278] = 1;
TABLE[88][295] = 1;
TABLE[88][294] = 1;
TABLE[88][33] = 1;
TABLE[88][126] = 1;
TABLE[88][38] = 1;
TABLE[88][299] = 1;
TABLE[88][289] = 1;
TABLE[88][307] = 1;
TABLE[88][306] = 1;
TABLE[88][308] = 1;
TABLE[178][63] = 1;
TABLE[245][59] = 1;
TABLE[245][41] = 1;
TABLE[245][125] = 1;
TABLE[245][93] = 1;
TABLE[245][58] = 1;
TABLE[245][44] = 1;
TABLE[89][59] = 1;
TABLE[89][125] = 1;
TABLE[89][93] = 1;
TABLE[89][58] = 1;
TABLE[89][44] = 1;
TABLE[89][63] = 1;
TABLE[89][297] = 1;
TABLE[89][298] = 1;
TABLE[89][301] = 1;
TABLE[89][303] = 1;
TABLE[89][302] = 1;
TABLE[89][292] = 1;
TABLE[89][304] = 1;
TABLE[89][43] = 1;
TABLE[89][45] = 1;
TABLE[89][40] = 1;
TABLE[89][278] = 1;
TABLE[89][37] = 1;
TABLE[89][47] = 1;
TABLE[89][42] = 1;
TABLE[89][38] = 1;
TABLE[89][126] = 1;
TABLE[89][33] = 1;
TABLE[89][294] = 1;
TABLE[89][295] = 1;
TABLE[89][289] = 1;
TABLE[89][299] = 1;
TABLE[89][308] = 1;
TABLE[89][306] = 1;
TABLE[89][307] = 1;
TABLE[90][63] = 1;
TABLE[90][59] = 1;
TABLE[90][41] = 1;
TABLE[90][125] = 1;
TABLE[90][93] = 1;
TABLE[90][58] = 1;
TABLE[90][44] = 1;
TABLE[90][297] = 1;
TABLE[90][298] = 1;
TABLE[90][301] = 1;
TABLE[90][303] = 1;
TABLE[90][302] = 1;
TABLE[90][292] = 1;
TABLE[90][304] = 1;
TABLE[90][43] = 1;
TABLE[90][45] = 1;
TABLE[90][40] = 1;
TABLE[90][278] = 1;
TABLE[90][37] = 1;
TABLE[90][47] = 1;
TABLE[90][42] = 1;
TABLE[90][38] = 1;
TABLE[90][126] = 1;
TABLE[90][33] = 1;
TABLE[90][294] = 1;
TABLE[90][295] = 1;
TABLE[90][289] = 1;
TABLE[90][299] = 1;
TABLE[90][308] = 1;
TABLE[90][306] = 1;
TABLE[90][307] = 1;
TABLE[179][297] = 1;
TABLE[179][298] = 1;
TABLE[179][301] = 1;
TABLE[179][303] = 1;
TABLE[179][302] = 1;
TABLE[179][292] = 1;
TABLE[179][304] = 1;
TABLE[179][40] = 1;
TABLE[179][45] = 1;
TABLE[179][43] = 1;
TABLE[179][42] = 1;
TABLE[179][47] = 1;
TABLE[179][37] = 1;
TABLE[179][278] = 1;
TABLE[179][295] = 1;
TABLE[179][294] = 1;
TABLE[179][33] = 1;
TABLE[179][126] = 1;
TABLE[179][38] = 1;
TABLE[179][299] = 1;
TABLE[179][289] = 1;
TABLE[179][307] = 1;
TABLE[179][306] = 1;
TABLE[179][308] = 1;
TABLE[246][298] = 1;
TABLE[246][301] = 1;
TABLE[246][303] = 1;
TABLE[246][302] = 1;
TABLE[246][292] = 1;
TABLE[246][304] = 1;
TABLE[246][43] = 1;
TABLE[246][45] = 1;
TABLE[246][40] = 1;
TABLE[246][278] = 1;
TABLE[246][37] = 1;
TABLE[246][47] = 1;
TABLE[246][42] = 1;
TABLE[246][38] = 1;
TABLE[246][126] = 1;
TABLE[246][33] = 1;
TABLE[246][294] = 1;
TABLE[246][295] = 1;
TABLE[246][289] = 1;
TABLE[246][299] = 1;
TABLE[246][308] = 1;
TABLE[246][306] = 1;
TABLE[246][307] = 1;
TABLE[246][63] = 1;
TABLE[246][59] = 1;
TABLE[246][41] = 1;
TABLE[246][297] = 1;
TABLE[246][125] = 1;
TABLE[246][93] = 1;
TABLE[246][58] = 1;
TABLE[246][44] = 1;
TABLE[91][63] = 1;
TABLE[91][59] = 1;
TABLE[91][41] = 1;
TABLE[91][297] = 1;
TABLE[91][125] = 1;
TABLE[91][93] = 1;
TABLE[91][58] = 1;
TABLE[91][44] = 1;
TABLE[91][298] = 1;
TABLE[91][301] = 1;
TABLE[91][303] = 1;
TABLE[91][302] = 1;
TABLE[91][292] = 1;
TABLE[91][304] = 1;
TABLE[91][40] = 1;
TABLE[91][45] = 1;
TABLE[91][43] = 1;
TABLE[91][42] = 1;
TABLE[91][47] = 1;
TABLE[91][37] = 1;
TABLE[91][278] = 1;
TABLE[91][295] = 1;
TABLE[91][294] = 1;
TABLE[91][33] = 1;
TABLE[91][126] = 1;
TABLE[91][38] = 1;
TABLE[91][299] = 1;
TABLE[91][289] = 1;
TABLE[91][307] = 1;
TABLE[91][306] = 1;
TABLE[91][308] = 1;
TABLE[180][298] = 1;
TABLE[180][301] = 1;
TABLE[180][303] = 1;
TABLE[180][302] = 1;
TABLE[180][292] = 1;
TABLE[180][304] = 1;
TABLE[180][43] = 1;
TABLE[180][45] = 1;
TABLE[180][40] = 1;
TABLE[180][278] = 1;
TABLE[180][37] = 1;
TABLE[180][47] = 1;
TABLE[180][42] = 1;
TABLE[180][38] = 1;
TABLE[180][126] = 1;
TABLE[180][33] = 1;
TABLE[180][294] = 1;
TABLE[180][295] = 1;
TABLE[180][289] = 1;
TABLE[180][299] = 1;
TABLE[180][308] = 1;
TABLE[180][306] = 1;
TABLE[180][307] = 1;
TABLE[247][301] = 1;
TABLE[247][303] = 1;
TABLE[247][302] = 1;
TABLE[247][292] = 1;
TABLE[247][304] = 1;
TABLE[247][40] = 1;
TABLE[247][45] = 1;
TABLE[247][43] = 1;
TABLE[247][42] = 1;
TABLE[247][47] = 1;
TABLE[247][37] = 1;
TABLE[247][278] = 1;
TABLE[247][295] = 1;
TABLE[247][294] = 1;
TABLE[247][33] = 1;
TABLE[247][126] = 1;
TABLE[247][38] = 1;
TABLE[247][299] = 1;
TABLE[247][289] = 1;
TABLE[247][307] = 1;
TABLE[247][306] = 1;
TABLE[247][308] = 1;
TABLE[247][63] = 1;
TABLE[247][59] = 1;
TABLE[247][41] = 1;
TABLE[247][298] = 1;
TABLE[247][297] = 1;
TABLE[247][125] = 1;
TABLE[247][93] = 1;
TABLE[247][58] = 1;
TABLE[247][44] = 1;
TABLE[92][63] = 1;
TABLE[92][59] = 1;
TABLE[92][41] = 1;
TABLE[92][298] = 1;
TABLE[92][297] = 1;
TABLE[92][125] = 1;
TABLE[92][93] = 1;
TABLE[92][58] = 1;
TABLE[92][44] = 1;
TABLE[92][301] = 1;
TABLE[92][303] = 1;
TABLE[92][302] = 1;
TABLE[92][292] = 1;
TABLE[92][304] = 1;
TABLE[92][43] = 1;
TABLE[92][45] = 1;
TABLE[92][40] = 1;
TABLE[92][278] = 1;
TABLE[92][37] = 1;
TABLE[92][47] = 1;
TABLE[92][42] = 1;
TABLE[92][38] = 1;
TABLE[92][126] = 1;
TABLE[92][33] = 1;
TABLE[92][294] = 1;
TABLE[92][295] = 1;
TABLE[92][289] = 1;
TABLE[92][299] = 1;
TABLE[92][308] = 1;
TABLE[92][306] = 1;
TABLE[92][307] = 1;
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
TABLE[181][33] = 1;
TABLE[181][126] = 1;
TABLE[181][38] = 1;
TABLE[181][299] = 1;
TABLE[181][289] = 1;
TABLE[181][307] = 1;
TABLE[181][306] = 1;
TABLE[181][308] = 1;
TABLE[248][303] = 1;
TABLE[248][302] = 1;
TABLE[248][292] = 1;
TABLE[248][304] = 1;
TABLE[248][43] = 1;
TABLE[248][45] = 1;
TABLE[248][40] = 1;
TABLE[248][278] = 1;
TABLE[248][37] = 1;
TABLE[248][47] = 1;
TABLE[248][42] = 1;
TABLE[248][38] = 1;
TABLE[248][126] = 1;
TABLE[248][33] = 1;
TABLE[248][294] = 1;
TABLE[248][295] = 1;
TABLE[248][289] = 1;
TABLE[248][299] = 1;
TABLE[248][308] = 1;
TABLE[248][306] = 1;
TABLE[248][307] = 1;
TABLE[248][63] = 1;
TABLE[248][59] = 1;
TABLE[248][41] = 1;
TABLE[248][301] = 1;
TABLE[248][298] = 1;
TABLE[248][297] = 1;
TABLE[248][125] = 1;
TABLE[248][93] = 1;
TABLE[248][58] = 1;
TABLE[248][44] = 1;
TABLE[93][63] = 1;
TABLE[93][59] = 1;
TABLE[93][41] = 1;
TABLE[93][301] = 1;
TABLE[93][298] = 1;
TABLE[93][297] = 1;
TABLE[93][125] = 1;
TABLE[93][93] = 1;
TABLE[93][58] = 1;
TABLE[93][44] = 1;
TABLE[93][303] = 1;
TABLE[93][302] = 1;
TABLE[93][292] = 1;
TABLE[93][304] = 1;
TABLE[93][40] = 1;
TABLE[93][45] = 1;
TABLE[93][43] = 1;
TABLE[93][42] = 1;
TABLE[93][47] = 1;
TABLE[93][37] = 1;
TABLE[93][278] = 1;
TABLE[93][295] = 1;
TABLE[93][294] = 1;
TABLE[93][33] = 1;
TABLE[93][126] = 1;
TABLE[93][38] = 1;
TABLE[93][299] = 1;
TABLE[93][289] = 1;
TABLE[93][307] = 1;
TABLE[93][306] = 1;
TABLE[93][308] = 1;
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
TABLE[182][38] = 1;
TABLE[182][126] = 1;
TABLE[182][33] = 1;
TABLE[182][294] = 1;
TABLE[182][295] = 1;
TABLE[182][289] = 1;
TABLE[182][299] = 1;
TABLE[182][308] = 1;
TABLE[182][306] = 1;
TABLE[182][307] = 1;
TABLE[249][302] = 1;
TABLE[249][292] = 1;
TABLE[249][304] = 1;
TABLE[249][40] = 1;
TABLE[249][45] = 1;
TABLE[249][43] = 1;
TABLE[249][42] = 1;
TABLE[249][47] = 1;
TABLE[249][37] = 1;
TABLE[249][278] = 1;
TABLE[249][295] = 1;
TABLE[249][294] = 1;
TABLE[249][33] = 1;
TABLE[249][126] = 1;
TABLE[249][38] = 1;
TABLE[249][299] = 1;
TABLE[249][289] = 1;
TABLE[249][307] = 1;
TABLE[249][306] = 1;
TABLE[249][308] = 1;
TABLE[249][63] = 1;
TABLE[249][59] = 1;
TABLE[249][41] = 1;
TABLE[249][303] = 1;
TABLE[249][301] = 1;
TABLE[249][298] = 1;
TABLE[249][297] = 1;
TABLE[249][125] = 1;
TABLE[249][93] = 1;
TABLE[249][58] = 1;
TABLE[249][44] = 1;
TABLE[94][63] = 1;
TABLE[94][59] = 1;
TABLE[94][41] = 1;
TABLE[94][303] = 1;
TABLE[94][301] = 1;
TABLE[94][298] = 1;
TABLE[94][297] = 1;
TABLE[94][125] = 1;
TABLE[94][93] = 1;
TABLE[94][58] = 1;
TABLE[94][44] = 1;
TABLE[94][302] = 1;
TABLE[94][292] = 1;
TABLE[94][304] = 1;
TABLE[94][43] = 1;
TABLE[94][45] = 1;
TABLE[94][40] = 1;
TABLE[94][278] = 1;
TABLE[94][37] = 1;
TABLE[94][47] = 1;
TABLE[94][42] = 1;
TABLE[94][38] = 1;
TABLE[94][126] = 1;
TABLE[94][33] = 1;
TABLE[94][294] = 1;
TABLE[94][295] = 1;
TABLE[94][289] = 1;
TABLE[94][299] = 1;
TABLE[94][308] = 1;
TABLE[94][306] = 1;
TABLE[94][307] = 1;
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
TABLE[183][33] = 1;
TABLE[183][126] = 1;
TABLE[183][38] = 1;
TABLE[183][299] = 1;
TABLE[183][289] = 1;
TABLE[183][307] = 1;
TABLE[183][306] = 1;
TABLE[183][308] = 1;
TABLE[250][292] = 1;
TABLE[250][304] = 1;
TABLE[250][43] = 1;
TABLE[250][45] = 1;
TABLE[250][40] = 1;
TABLE[250][278] = 1;
TABLE[250][37] = 1;
TABLE[250][47] = 1;
TABLE[250][42] = 1;
TABLE[250][38] = 1;
TABLE[250][126] = 1;
TABLE[250][33] = 1;
TABLE[250][294] = 1;
TABLE[250][295] = 1;
TABLE[250][289] = 1;
TABLE[250][299] = 1;
TABLE[250][308] = 1;
TABLE[250][306] = 1;
TABLE[250][307] = 1;
TABLE[250][63] = 1;
TABLE[250][59] = 1;
TABLE[250][41] = 1;
TABLE[250][302] = 1;
TABLE[250][303] = 1;
TABLE[250][301] = 1;
TABLE[250][298] = 1;
TABLE[250][297] = 1;
TABLE[250][125] = 1;
TABLE[250][93] = 1;
TABLE[250][58] = 1;
TABLE[250][44] = 1;
TABLE[95][63] = 1;
TABLE[95][59] = 1;
TABLE[95][41] = 1;
TABLE[95][302] = 1;
TABLE[95][303] = 1;
TABLE[95][301] = 1;
TABLE[95][298] = 1;
TABLE[95][297] = 1;
TABLE[95][125] = 1;
TABLE[95][93] = 1;
TABLE[95][58] = 1;
TABLE[95][44] = 1;
TABLE[95][292] = 1;
TABLE[95][304] = 1;
TABLE[95][40] = 1;
TABLE[95][45] = 1;
TABLE[95][43] = 1;
TABLE[95][42] = 1;
TABLE[95][47] = 1;
TABLE[95][37] = 1;
TABLE[95][278] = 1;
TABLE[95][295] = 1;
TABLE[95][294] = 1;
TABLE[95][33] = 1;
TABLE[95][126] = 1;
TABLE[95][38] = 1;
TABLE[95][299] = 1;
TABLE[95][289] = 1;
TABLE[95][307] = 1;
TABLE[95][306] = 1;
TABLE[95][308] = 1;
TABLE[184][292] = 1;
TABLE[184][304] = 1;
TABLE[184][43] = 1;
TABLE[184][45] = 1;
TABLE[184][40] = 1;
TABLE[184][278] = 1;
TABLE[184][37] = 1;
TABLE[184][47] = 1;
TABLE[184][42] = 1;
TABLE[184][38] = 1;
TABLE[184][126] = 1;
TABLE[184][33] = 1;
TABLE[184][294] = 1;
TABLE[184][295] = 1;
TABLE[184][289] = 1;
TABLE[184][299] = 1;
TABLE[184][308] = 1;
TABLE[184][306] = 1;
TABLE[184][307] = 1;
TABLE[251][304] = 1;
TABLE[251][40] = 1;
TABLE[251][45] = 1;
TABLE[251][43] = 1;
TABLE[251][42] = 1;
TABLE[251][47] = 1;
TABLE[251][37] = 1;
TABLE[251][278] = 1;
TABLE[251][295] = 1;
TABLE[251][294] = 1;
TABLE[251][33] = 1;
TABLE[251][126] = 1;
TABLE[251][38] = 1;
TABLE[251][299] = 1;
TABLE[251][289] = 1;
TABLE[251][307] = 1;
TABLE[251][306] = 1;
TABLE[251][308] = 1;
TABLE[251][63] = 1;
TABLE[251][59] = 1;
TABLE[251][41] = 1;
TABLE[251][292] = 1;
TABLE[251][302] = 1;
TABLE[251][303] = 1;
TABLE[251][301] = 1;
TABLE[251][298] = 1;
TABLE[251][297] = 1;
TABLE[251][125] = 1;
TABLE[251][93] = 1;
TABLE[251][58] = 1;
TABLE[251][44] = 1;
TABLE[96][63] = 1;
TABLE[96][59] = 1;
TABLE[96][41] = 1;
TABLE[96][292] = 1;
TABLE[96][302] = 1;
TABLE[96][303] = 1;
TABLE[96][301] = 1;
TABLE[96][298] = 1;
TABLE[96][297] = 1;
TABLE[96][125] = 1;
TABLE[96][93] = 1;
TABLE[96][58] = 1;
TABLE[96][44] = 1;
TABLE[96][304] = 1;
TABLE[96][43] = 1;
TABLE[96][45] = 1;
TABLE[96][40] = 1;
TABLE[96][278] = 1;
TABLE[96][37] = 1;
TABLE[96][47] = 1;
TABLE[96][42] = 1;
TABLE[96][38] = 1;
TABLE[96][126] = 1;
TABLE[96][33] = 1;
TABLE[96][294] = 1;
TABLE[96][295] = 1;
TABLE[96][289] = 1;
TABLE[96][299] = 1;
TABLE[96][308] = 1;
TABLE[96][306] = 1;
TABLE[96][307] = 1;
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
TABLE[185][33] = 1;
TABLE[185][126] = 1;
TABLE[185][38] = 1;
TABLE[185][299] = 1;
TABLE[185][289] = 1;
TABLE[185][307] = 1;
TABLE[185][306] = 1;
TABLE[185][308] = 1;
TABLE[252][43] = 1;
TABLE[252][45] = 1;
TABLE[252][40] = 1;
TABLE[252][278] = 1;
TABLE[252][37] = 1;
TABLE[252][47] = 1;
TABLE[252][42] = 1;
TABLE[252][38] = 1;
TABLE[252][126] = 1;
TABLE[252][33] = 1;
TABLE[252][294] = 1;
TABLE[252][295] = 1;
TABLE[252][289] = 1;
TABLE[252][299] = 1;
TABLE[252][308] = 1;
TABLE[252][306] = 1;
TABLE[252][307] = 1;
TABLE[252][63] = 1;
TABLE[252][59] = 1;
TABLE[252][41] = 1;
TABLE[252][304] = 1;
TABLE[252][292] = 1;
TABLE[252][302] = 1;
TABLE[252][303] = 1;
TABLE[252][301] = 1;
TABLE[252][298] = 1;
TABLE[252][297] = 1;
TABLE[252][125] = 1;
TABLE[252][93] = 1;
TABLE[252][58] = 1;
TABLE[252][44] = 1;
TABLE[97][63] = 1;
TABLE[97][59] = 1;
TABLE[97][41] = 1;
TABLE[97][304] = 1;
TABLE[97][292] = 1;
TABLE[97][302] = 1;
TABLE[97][303] = 1;
TABLE[97][301] = 1;
TABLE[97][298] = 1;
TABLE[97][297] = 1;
TABLE[97][125] = 1;
TABLE[97][93] = 1;
TABLE[97][58] = 1;
TABLE[97][44] = 1;
TABLE[97][45] = 1;
TABLE[97][43] = 1;
TABLE[97][40] = 1;
TABLE[97][42] = 1;
TABLE[97][47] = 1;
TABLE[97][37] = 1;
TABLE[97][278] = 1;
TABLE[97][295] = 1;
TABLE[97][294] = 1;
TABLE[97][33] = 1;
TABLE[97][126] = 1;
TABLE[97][38] = 1;
TABLE[97][299] = 1;
TABLE[97][289] = 1;
TABLE[97][307] = 1;
TABLE[97][306] = 1;
TABLE[97][308] = 1;
TABLE[188][43] = 1;
TABLE[188][45] = 1;
TABLE[188][40] = 1;
TABLE[188][278] = 1;
TABLE[188][37] = 1;
TABLE[188][47] = 1;
TABLE[188][42] = 1;
TABLE[188][38] = 1;
TABLE[188][126] = 1;
TABLE[188][33] = 1;
TABLE[188][294] = 1;
TABLE[188][295] = 1;
TABLE[188][289] = 1;
TABLE[188][299] = 1;
TABLE[188][308] = 1;
TABLE[188][306] = 1;
TABLE[188][307] = 1;
TABLE[253][40] = 1;
TABLE[253][42] = 1;
TABLE[253][47] = 1;
TABLE[253][37] = 1;
TABLE[253][278] = 1;
TABLE[253][295] = 1;
TABLE[253][294] = 1;
TABLE[253][33] = 1;
TABLE[253][126] = 1;
TABLE[253][45] = 1;
TABLE[253][43] = 1;
TABLE[253][38] = 1;
TABLE[253][299] = 1;
TABLE[253][289] = 1;
TABLE[253][307] = 1;
TABLE[253][306] = 1;
TABLE[253][308] = 1;
TABLE[253][63] = 1;
TABLE[253][59] = 1;
TABLE[253][41] = 1;
TABLE[253][304] = 1;
TABLE[253][292] = 1;
TABLE[253][302] = 1;
TABLE[253][303] = 1;
TABLE[253][301] = 1;
TABLE[253][298] = 1;
TABLE[253][297] = 1;
TABLE[253][125] = 1;
TABLE[253][93] = 1;
TABLE[253][58] = 1;
TABLE[253][44] = 1;
TABLE[186][43] = 1;
TABLE[187][45] = 1;
TABLE[98][40] = 1;
TABLE[98][37] = 1;
TABLE[98][47] = 1;
TABLE[98][42] = 1;
TABLE[98][278] = 1;
TABLE[98][38] = 1;
TABLE[98][43] = 1;
TABLE[98][45] = 1;
TABLE[98][126] = 1;
TABLE[98][33] = 1;
TABLE[98][294] = 1;
TABLE[98][295] = 1;
TABLE[98][289] = 1;
TABLE[98][299] = 1;
TABLE[98][308] = 1;
TABLE[98][306] = 1;
TABLE[98][307] = 1;
TABLE[192][40] = 1;
TABLE[192][42] = 1;
TABLE[192][47] = 1;
TABLE[192][37] = 1;
TABLE[192][278] = 1;
TABLE[192][295] = 1;
TABLE[192][294] = 1;
TABLE[192][33] = 1;
TABLE[192][126] = 1;
TABLE[192][45] = 1;
TABLE[192][43] = 1;
TABLE[192][38] = 1;
TABLE[192][299] = 1;
TABLE[192][289] = 1;
TABLE[192][307] = 1;
TABLE[192][306] = 1;
TABLE[192][308] = 1;
TABLE[254][40] = 1;
TABLE[254][278] = 1;
TABLE[254][38] = 1;
TABLE[254][42] = 1;
TABLE[254][43] = 1;
TABLE[254][45] = 1;
TABLE[254][126] = 1;
TABLE[254][33] = 1;
TABLE[254][294] = 1;
TABLE[254][295] = 1;
TABLE[254][289] = 1;
TABLE[254][299] = 1;
TABLE[254][308] = 1;
TABLE[254][306] = 1;
TABLE[254][307] = 1;
TABLE[189][42] = 1;
TABLE[190][47] = 1;
TABLE[191][37] = 1;
TABLE[99][278] = 1;
TABLE[99][295] = 1;
TABLE[99][294] = 1;
TABLE[99][33] = 1;
TABLE[99][126] = 1;
TABLE[99][45] = 1;
TABLE[99][43] = 1;
TABLE[99][42] = 1;
TABLE[99][38] = 1;
TABLE[99][299] = 1;
TABLE[99][289] = 1;
TABLE[99][40] = 1;
TABLE[99][307] = 1;
TABLE[99][306] = 1;
TABLE[99][308] = 1;
TABLE[100][40] = 1;
TABLE[101][40] = 1;
TABLE[101][289] = 1;
TABLE[101][299] = 1;
TABLE[101][308] = 1;
TABLE[101][306] = 1;
TABLE[101][307] = 1;
TABLE[102][294] = 1;
TABLE[102][295] = 1;
TABLE[103][38] = 1;
TABLE[103][42] = 1;
TABLE[103][43] = 1;
TABLE[103][45] = 1;
TABLE[103][126] = 1;
TABLE[103][33] = 1;
TABLE[104][278] = 1;
TABLE[105][278] = 1;
TABLE[193][294] = 1;
TABLE[194][295] = 1;
TABLE[106][38] = 1;
TABLE[107][42] = 1;
TABLE[108][43] = 1;
TABLE[109][45] = 1;
TABLE[110][126] = 1;
TABLE[111][33] = 1;
TABLE[112][299] = 1;
TABLE[112][289] = 1;
TABLE[112][40] = 1;
TABLE[112][307] = 1;
TABLE[112][306] = 1;
TABLE[112][308] = 1;
TABLE[113][40] = 1;
TABLE[113][289] = 1;
TABLE[113][299] = 1;
TABLE[113][308] = 1;
TABLE[113][306] = 1;
TABLE[113][307] = 1;
TABLE[195][91] = 1;
TABLE[197][40] = 1;
TABLE[198][46] = 1;
TABLE[199][296] = 1;
TABLE[200][294] = 1;
TABLE[201][295] = 1;
TABLE[196][41] = 1;
TABLE[196][44] = 1;
TABLE[196][278] = 1;
TABLE[196][295] = 1;
TABLE[196][294] = 1;
TABLE[196][33] = 1;
TABLE[196][126] = 1;
TABLE[196][45] = 1;
TABLE[196][43] = 1;
TABLE[196][42] = 1;
TABLE[196][38] = 1;
TABLE[196][63] = 1;
TABLE[196][299] = 1;
TABLE[196][289] = 1;
TABLE[196][40] = 1;
TABLE[196][297] = 1;
TABLE[196][307] = 1;
TABLE[196][306] = 1;
TABLE[196][308] = 1;
TABLE[196][298] = 1;
TABLE[196][301] = 1;
TABLE[196][303] = 1;
TABLE[196][302] = 1;
TABLE[196][292] = 1;
TABLE[196][304] = 1;
TABLE[196][37] = 1;
TABLE[196][47] = 1;
TABLE[255][41] = 1;
TABLE[114][299] = 1;
TABLE[115][308] = 1;
TABLE[115][306] = 1;
TABLE[115][307] = 1;
TABLE[115][299] = 1;
TABLE[116][289] = 1;
TABLE[117][40] = 1;
TABLE[118][41] = 1;
TABLE[118][44] = 1;
TABLE[118][278] = 1;
TABLE[118][63] = 1;
TABLE[118][38] = 1;
TABLE[118][42] = 1;
TABLE[118][43] = 1;
TABLE[118][45] = 1;
TABLE[118][126] = 1;
TABLE[118][33] = 1;
TABLE[118][294] = 1;
TABLE[118][295] = 1;
TABLE[118][297] = 1;
TABLE[118][40] = 1;
TABLE[118][289] = 1;
TABLE[118][299] = 1;
TABLE[118][298] = 1;
TABLE[118][308] = 1;
TABLE[118][306] = 1;
TABLE[118][307] = 1;
TABLE[118][301] = 1;
TABLE[118][303] = 1;
TABLE[118][302] = 1;
TABLE[118][292] = 1;
TABLE[118][304] = 1;
TABLE[118][47] = 1;
TABLE[118][37] = 1;
TABLE[202][44] = 1;
TABLE[202][278] = 1;
TABLE[202][295] = 1;
TABLE[202][294] = 1;
TABLE[202][33] = 1;
TABLE[202][126] = 1;
TABLE[202][45] = 1;
TABLE[202][43] = 1;
TABLE[202][42] = 1;
TABLE[202][38] = 1;
TABLE[202][63] = 1;
TABLE[202][299] = 1;
TABLE[202][289] = 1;
TABLE[202][40] = 1;
TABLE[202][297] = 1;
TABLE[202][307] = 1;
TABLE[202][306] = 1;
TABLE[202][308] = 1;
TABLE[202][298] = 1;
TABLE[202][301] = 1;
TABLE[202][303] = 1;
TABLE[202][302] = 1;
TABLE[202][292] = 1;
TABLE[202][304] = 1;
TABLE[202][37] = 1;
TABLE[202][47] = 1;
TABLE[256][278] = 1;
TABLE[256][63] = 1;
TABLE[256][38] = 1;
TABLE[256][42] = 1;
TABLE[256][43] = 1;
TABLE[256][45] = 1;
TABLE[256][126] = 1;
TABLE[256][33] = 1;
TABLE[256][294] = 1;
TABLE[256][295] = 1;
TABLE[256][297] = 1;
TABLE[256][40] = 1;
TABLE[256][289] = 1;
TABLE[256][299] = 1;
TABLE[256][298] = 1;
TABLE[256][308] = 1;
TABLE[256][306] = 1;
TABLE[256][307] = 1;
TABLE[256][301] = 1;
TABLE[256][303] = 1;
TABLE[256][302] = 1;
TABLE[256][292] = 1;
TABLE[256][304] = 1;
TABLE[256][47] = 1;
TABLE[256][37] = 1;
TABLE[256][41] = 1;
TABLE[256][44] = 1;
TABLE[119][308] = 1;
TABLE[120][306] = 1;
TABLE[121][307] = 1;
TABLE[122][299] = 1;
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
      case 15: return 1; break;
      case 23: return 1; break;
      case 30: return 1; break;
      case 37: return 1; break;
      case 44: return 0; break;
      case 50: return 1; break;
      case 57: return 1; break;
      case 62: return 1; break;
      case 69: return 0; break;
      case 74: return 0; break;
      case 86: return 1; break;
      case 93: return 0; break;
      case 113: return 0; break;
      case 157: return 0; break;
      case 165: return 0; break;
      case 178: return 1; break;
      case 185: return 0; break;
      case 193: return 1; break;
      case 198: return 1; break;
      case 205: return 1; break;
      case 210: return 1; break;
      case 218: return 1; break;
      case 223: return 1; break;
      case 231: return 0; break;
      case 237: return 0; break;
      case 242: return 0; break;
      case 250: return 1; break;
      case 257: return 1; break;
      case 262: return 1; break;
      case 270: return 1; break;
      case 280: return 1; break;
      case 287: return 0; break;
      case 300: return 1; break;
      case 307: return 1; break;
      case 312: return 1; break;
      case 320: return 0; break;
      case 325: return 1; break;
      case 333: return 1; break;
      case 338: return 1; break;
      case 345: return 0; break;
      case 360: return 0; break;
      case 378: return 1; break;
      case 385: return 1; break;
      case 392: return 0; break;
      case 398: return 1; break;
      case 405: return 1; break;
      case 412: return 1; break;
      case 417: return 1; break;
      case 424: return 1; break;
      case 429: return 1; break;
      case 437: return 1; break;
      case 442: return 1; break;
      case 450: return 0; break;
      case 455: return 1; break;
      case 463: return 1; break;
      case 470: return 1; break;
      case 475: return 1; break;
      case 483: return 1; break;
      case 494: return 1; break;
      case 501: return 1; break;
      case 506: return 1; break;
      case 514: return 0; break;
      case 519: return 1; break;
      case 526: return 1; break;
      case 535: return 1; break;
      case 542: return 1; break;
      case 553: return 1; break;
      case 560: return 0; break;
      case 572: return 1; break;
      case 579: return 1; break;
      case 586: return 0; break;
      case 590: return 1; break;
      case 614: return 0; break;
      case 633: return 1; break;
      case 638: return 1; break;
      case 645: return 0; break;
      case 652: return 1; break;
      case 659: return 1; break;
      case 666: return 1; break;
      case 671: return 1; break;
      case 678: return 0; break;
      case 695: return 1; break;
      case 703: return 0; break;
      case 733: return 1; break;
      case 740: return 1; break;
      case 747: return 1; break;
      case 754: return 0; break;
      case 776: return 1; break;
      case 783: return 1; break;
      case 788: return 1; break;
      case 796: return 1; break;
      case 806: return 0; break;
      case 814: return 1; break;
      case 819: return 1; break;
      case 829: return 1; break;
      case 833: return 1; break;
      case 838: return 1; break;
      case 846: return 1; break;
      case 851: return 1; break;
      case 859: return 1; break;
      case 864: return 1; break;
      case 872: return 1; break;
      case 877: return 1; break;
      case 885: return 1; break;
      case 890: return 1; break;
      case 898: return 1; break;
      case 903: return 1; break;
      case 911: return 1; break;
      case 916: return 1; break;
      case 924: return 1; break;
      case 929: return 1; break;
      case 937: return 0; break;
      case 945: return 1; break;
      case 950: return 1; break;
      case 958: return 0; break;
      case 970: return 0; break;
      case 981: return 0; break;
      case 1007: return 0; break;
      case 1015: return 0; break;
      case 1039: return 0; break;
      case 1048: return 0; break;
      case 1078: return 1; break;
      case 1085: return 0; break;
      case 1103: return 1; break;
      case 1108: return 1; break;
      case 1116: return 0; break;
   }
}
char * yyprintname(n)
   int n;
{
   if (n <= 50000)
      switch(n) {
         case 1: return "YYSTART"; break;
         case 6: return "translation_unit"; break;
         case 15: return "external_declaration"; break;
         case 23: return "function_definition"; break;
         case 30: return "Subphrase"; break;
         case 37: return "Subphrase"; break;
         case 44: return "declaration"; break;
         case 50: return "Subphrase"; break;
         case 57: return "declaration_list"; break;
         case 62: return "Subphrase"; break;
         case 69: return "declaration_specifiers"; break;
         case 74: return "Subphrase"; break;
         case 86: return "Subphrase"; break;
         case 93: return "storage_class_specifier"; break;
         case 113: return "type_specifier"; break;
         case 157: return "type_qualifier"; break;
         case 165: return "struct_or_union_specifier"; break;
         case 178: return "Subphrase"; break;
         case 185: return "struct_or_union"; break;
         case 193: return "struct_declaration_list"; break;
         case 198: return "Subphrase"; break;
         case 205: return "init_declarator_list"; break;
         case 210: return "Subphrase"; break;
         case 218: return "init_declarator"; break;
         case 223: return "Subphrase"; break;
         case 231: return "struct_declaration"; break;
         case 237: return "specifier_qualifier_list"; break;
         case 242: return "Subphrase"; break;
         case 250: return "Subphrase"; break;
         case 257: return "struct_declarator_list"; break;
         case 262: return "Subphrase"; break;
         case 270: return "struct_declarator"; break;
         case 280: return "Subphrase"; break;
         case 287: return "enum_specifier"; break;
         case 300: return "Subphrase"; break;
         case 307: return "enumerator_list"; break;
         case 312: return "Subphrase"; break;
         case 320: return "enumerator"; break;
         case 325: return "Subphrase"; break;
         case 333: return "declarator"; break;
         case 338: return "Subphrase"; break;
         case 345: return "direct_declarator"; break;
         case 360: return "Subphrase"; break;
         case 378: return "Subphrase"; break;
         case 385: return "Subphrase"; break;
         case 392: return "pointer"; break;
         case 398: return "Subphrase"; break;
         case 405: return "Subphrase"; break;
         case 412: return "type_qualifier_list"; break;
         case 417: return "Subphrase"; break;
         case 424: return "parameter_type_list"; break;
         case 429: return "Subphrase"; break;
         case 437: return "parameter_list"; break;
         case 442: return "Subphrase"; break;
         case 450: return "parameter_declaration"; break;
         case 455: return "Subphrase"; break;
         case 463: return "Subphrase"; break;
         case 470: return "identifier_list"; break;
         case 475: return "Subphrase"; break;
         case 483: return "initializer"; break;
         case 494: return "Subphrase"; break;
         case 501: return "initializer_list"; break;
         case 506: return "Subphrase"; break;
         case 514: return "type_name"; break;
         case 519: return "Subphrase"; break;
         case 526: return "abstract_declarator"; break;
         case 535: return "Subphrase"; break;
         case 542: return "direct_abstract_declarator"; break;
         case 553: return "Subphrase"; break;
         case 560: return "Subphrase"; break;
         case 572: return "Subphrase"; break;
         case 579: return "Subphrase"; break;
         case 586: return "typedef_name"; break;
         case 590: return "statement"; break;
         case 614: return "labeled_statement"; break;
         case 633: return "expression_statement"; break;
         case 638: return "Subphrase"; break;
         case 645: return "compound_statement"; break;
         case 652: return "Subphrase"; break;
         case 659: return "Subphrase"; break;
         case 666: return "statement_list"; break;
         case 671: return "Subphrase"; break;
         case 678: return "selection_statement"; break;
         case 695: return "Subphrase"; break;
         case 703: return "iteration_statement"; break;
         case 733: return "Subphrase"; break;
         case 740: return "Subphrase"; break;
         case 747: return "Subphrase"; break;
         case 754: return "jump_statement"; break;
         case 776: return "Subphrase"; break;
         case 783: return "expression"; break;
         case 788: return "Subphrase"; break;
         case 796: return "assignment_expression"; break;
         case 806: return "assignment_operator"; break;
         case 814: return "conditional_expression"; break;
         case 819: return "Subphrase"; break;
         case 829: return "constant_expression"; break;
         case 833: return "logical_OR_expression"; break;
         case 838: return "Subphrase"; break;
         case 846: return "logical_AND_expression"; break;
         case 851: return "Subphrase"; break;
         case 859: return "inclusive_OR_expression"; break;
         case 864: return "Subphrase"; break;
         case 872: return "exclusive_OR_expression"; break;
         case 877: return "Subphrase"; break;
         case 885: return "AND_expression"; break;
         case 890: return "Subphrase"; break;
         case 898: return "equality_expression"; break;
         case 903: return "Subphrase"; break;
         case 911: return "shift_expression"; break;
         case 916: return "Subphrase"; break;
         case 924: return "additive_expression"; break;
         case 929: return "Subphrase"; break;
         case 937: return "Subphrase"; break;
         case 945: return "multiplicative_expression"; break;
         case 950: return "Subphrase"; break;
         case 958: return "Subphrase"; break;
         case 970: return "cast_expression"; break;
         case 981: return "unary_expression"; break;
         case 1007: return "Subphrase"; break;
         case 1015: return "unary_operator"; break;
         case 1039: return "postfix_expression"; break;
         case 1048: return "Subphrase"; break;
         case 1078: return "Subphrase"; break;
         case 1085: return "primary_expression"; break;
         case 1103: return "argument_expression_list"; break;
         case 1108: return "Subphrase"; break;
         case 1116: return "constant"; break;
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
