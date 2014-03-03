#line 1 "ass2.acc"

	#include <stdio.h>
	#include <stdlib.h>

# line 7 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 125: {
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
      case 126: {
         declaration_specifiers();
         } break;
      default: ;
      }
      declarator();
      switch (yyselect()) {
      case 127: {
         declaration_list();
         } break;
      default: ;
      }
      compound_statement();
      } break;
   }
}

declaration ()
{
   switch(yyselect()) {
   case 6: {
      declaration_specifiers();
      switch (yyselect()) {
      case 128: {
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
      case 129: {
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
      case 130: {
         storage_class_specifier();
         } break;
      case 131: {
         type_specifier();
         } break;
      case 132: {
         type_qualifier();
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 133: {
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
      } break;
   case 23: {
      struct_or_union_specifier();
      } break;
   case 24: {
      enum_specifier();
      } break;
   case 25: {
      typedef_name();
      } break;
   }
}

type_qualifier ()
{
   switch(yyselect()) {
   case 26: {
      get_lexval();
      } break;
   case 27: {
      get_lexval();
      } break;
   }
}

struct_or_union_specifier ()
{
   switch(yyselect()) {
   case 28: {
      struct_or_union();
      switch (yyselect()) {
      case 134: {
         get_lexval();
         } break;
      default: ;
      }
      get_lexval();
      struct_declaration_list();
      get_lexval();
      } break;
   case 29: {
      struct_or_union();
      get_lexval();
      } break;
   }
}

struct_or_union ()
{
   switch(yyselect()) {
   case 30: {
      get_lexval();
      } break;
   case 31: {
      get_lexval();
      } break;
   }
}

struct_declaration_list ()
{
   switch(yyselect()) {
   case 32: {
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
   case 33: {
      switch (yyselect()) {
      case 136: {
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
   case 34: {
      switch (yyselect()) {
      case 137: {
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
   case 35: {
      specifier_qualifier_list();
      struct_declarator_list();
      get_lexval();
      } break;
   }
}

specifier_qualifier_list ()
{
   switch(yyselect()) {
   case 36: {
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
   case 37: {
      struct_declarator();
      } break;
   case 38: {
      struct_declarator_list();
      get_lexval();
      struct_declarator();
      } break;
   }
}

struct_declarator ()
{
   switch(yyselect()) {
   case 39: {
      declarator();
      } break;
   case 40: {
      switch (yyselect()) {
      case 141: {
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
   case 41: {
      get_lexval();
      switch (yyselect()) {
      case 142: {
         get_lexval();
         } break;
      default: ;
      }
      get_lexval();
      enumerator_list();
      get_lexval();
      } break;
   case 42: {
      get_lexval();
      get_lexval();
      } break;
   }
}

enumerator_list ()
{
   switch(yyselect()) {
   case 43: {
      switch (yyselect()) {
      case 143: {
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
   case 44: {
      get_lexval();
      switch (yyselect()) {
      case 144: {
         get_lexval();
         constant_expression();
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

declarator ()
{
   switch(yyselect()) {
   case 45: {
      switch (yyselect()) {
      case 145: {
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
   case 46: {
      get_lexval();
      } break;
   case 47: {
      get_lexval();
      declarator();
      get_lexval();
      } break;
   case 48: {
      direct_declarator();
      switch (yyselect()) {
      case 147: {
         get_lexval();
         switch (yyselect()) {
         case 146: {
            constant_expression();
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 148: {
         get_lexval();
         parameter_type_list();
         get_lexval();
         } break;
      case 150: {
         get_lexval();
         switch (yyselect()) {
         case 149: {
            IDENTIFIER_list();
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
   case 49: {
      get_lexval();
      switch (yyselect()) {
      case 151: {
         type_qualifier_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 152: {
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
   case 50: {
      switch (yyselect()) {
      case 153: {
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
   case 51: {
      parameter_list();
      switch (yyselect()) {
      case 154: {
         get_lexval();
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

parameter_list ()
{
   switch(yyselect()) {
   case 52: {
      switch (yyselect()) {
      case 155: {
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
   case 53: {
      declaration_specifiers();
      switch (yyselect()) {
      case 156: {
         declarator();
         } break;
      case 158: {
         switch (yyselect()) {
         case 157: {
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

IDENTIFIER_list ()
{
   switch(yyselect()) {
   case 54: {
      switch (yyselect()) {
      case 159: {
         IDENTIFIER_list();
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
   case 55: {
      assignment_expression();
      } break;
   case 56: {
      get_lexval();
      initializer_list();
      switch (yyselect()) {
      case 160: {
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
   case 57: {
      switch (yyselect()) {
      case 161: {
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
   case 58: {
      specifier_qualifier_list();
      switch (yyselect()) {
      case 162: {
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
   case 59: {
      pointer();
      } break;
   case 60: {
      switch (yyselect()) {
      case 163: {
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
   case 61: {
      get_lexval();
      abstract_declarator();
      get_lexval();
      } break;
   case 62: {
      switch (yyselect()) {
      case 164: {
         direct_abstract_declarator();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 166: {
         get_lexval();
         switch (yyselect()) {
         case 165: {
            constant_expression();
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 168: {
         get_lexval();
         switch (yyselect()) {
         case 167: {
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
   case 63: {
      get_lexval();
      } break;
   }
}

statement ()
{
   switch(yyselect()) {
   case 64: {
      labeled_statement();
      } break;
   case 65: {
      expression_statement();
      } break;
   case 66: {
      compound_statement();
      } break;
   case 67: {
      selection_statement();
      } break;
   case 68: {
      iteration_statement();
      } break;
   case 69: {
      jump_statement();
      } break;
   }
}

labeled_statement ()
{
   switch(yyselect()) {
   case 70: {
      get_lexval();
      get_lexval();
      statement();
      } break;
   case 71: {
      get_lexval();
      constant_expression();
      get_lexval();
      statement();
      } break;
   case 72: {
      get_lexval();
      get_lexval();
      statement();
      } break;
   }
}

expression_statement ()
{
   switch(yyselect()) {
   case 73: {
      switch (yyselect()) {
      case 169: {
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
   case 74: {
      get_lexval();
      switch (yyselect()) {
      case 170: {
         declaration_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 171: {
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
   case 75: {
      switch (yyselect()) {
      case 172: {
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
   case 76: {
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      statement();
      switch (yyselect()) {
      case 173: {
         get_lexval();
         statement();
         } break;
      default: ;
      }
      } break;
   case 77: {
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
   case 78: {
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      statement();
      } break;
   case 79: {
      get_lexval();
      statement();
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      get_lexval();
      } break;
   case 80: {
      get_lexval();
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
      switch (yyselect()) {
      case 176: {
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
   case 81: {
      get_lexval();
      get_lexval();
      get_lexval();
      } break;
   case 82: {
      get_lexval();
      get_lexval();
      } break;
   case 83: {
      get_lexval();
      get_lexval();
      } break;
   case 84: {
      get_lexval();
      switch (yyselect()) {
      case 177: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 208 "ass2.acc"
 printf("Return\n"); 
# line 888 "yygrammar.c"
      } break;
   }
}

expression ()
{
   switch(yyselect()) {
   case 85: {
      switch (yyselect()) {
      case 178: {
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
   case 86: {
      conditional_expression();
      } break;
   case 87: {
      unary_expression();
      assignment_operator();
      assignment_expression();
      } break;
   }
}

assignment_operator ()
{
   switch(yyselect()) {
   case 88: {
      get_lexval();
      } break;
   case 89: {
      get_lexval();
      } break;
   }
}

conditional_expression ()
{
   switch(yyselect()) {
   case 90: {
      logical_OR_expression();
      switch (yyselect()) {
      case 179: {
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
   case 91: {
      conditional_expression();
      } break;
   }
}

logical_OR_expression ()
{
   switch(yyselect()) {
   case 92: {
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
   case 93: {
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
   case 94: {
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
   case 95: {
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
   case 96: {
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
   case 97: {
      switch (yyselect()) {
      case 185: {
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
   case 98: {
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
   case 99: {
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
   case 100: {
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
   case 101: {
      unary_expression();
      } break;
   case 102: {
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
   case 103: {
      postfix_expression();
      } break;
   case 104: {
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
   case 105: {
      unary_operator();
      cast_expression();
      } break;
   case 106: {
      get_lexval();
      unary_expression();
      } break;
   case 107: {
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
   case 112: {
      get_lexval();
      } break;
   case 113: {
      get_lexval();
      } break;
   }
}

postfix_expression ()
{
   switch(yyselect()) {
   case 114: {
      primary_expression();
      } break;
   case 115: {
      postfix_expression();
      switch (yyselect()) {
      case 196: {
         get_lexval();
         expression();
         get_lexval();
         } break;
      case 198: {
         get_lexval();
         switch (yyselect()) {
         case 197: {
            argument_expression_list();
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 199: {
         get_lexval();
         get_lexval();
         } break;
      case 200: {
         get_lexval();
         get_lexval();
         } break;
      case 201: {
         get_lexval();
         } break;
      case 202: {
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
   case 116: {
      get_lexval();
      } break;
   case 117: {
      constant();
      } break;
   case 118: {
      get_lexval();
      } break;
   case 119: {
      get_lexval();
      expression();
      get_lexval();
      } break;
   }
}

argument_expression_list ()
{
   switch(yyselect()) {
   case 120: {
      switch (yyselect()) {
      case 203: {
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
#line 303 "ass2.acc"
 printf("Constant\n"); 
# line 1295 "yygrammar.c"
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
int c_length = 1126;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 125,
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
/* 25 */ 331,
/* 26 */ 37,
/* 27 */ 640,
/* 28 */ -23,
/* 29 */ 5,
/* 30 */ 34,
/* 31 */ 69,
/* 32 */ -30,
/* 33 */ 126,
/* 34 */ 0,
/* 35 */ -30,
/* 36 */ 204,
/* 37 */ 41,
/* 38 */ 57,
/* 39 */ -37,
/* 40 */ 127,
/* 41 */ 0,
/* 42 */ -37,
/* 43 */ 205,
/* 44 */ 0,
/* 45 */ 69,
/* 46 */ 50,
/* 47 */ 50059,
/* 48 */ -44,
/* 49 */ 6,
/* 50 */ 54,
/* 51 */ 209,
/* 52 */ -50,
/* 53 */ 128,
/* 54 */ 0,
/* 55 */ -50,
/* 56 */ 206,
/* 57 */ 0,
/* 58 */ 62,
/* 59 */ 44,
/* 60 */ -57,
/* 61 */ 7,
/* 62 */ 66,
/* 63 */ 57,
/* 64 */ -62,
/* 65 */ 129,
/* 66 */ 0,
/* 67 */ -62,
/* 68 */ 207,
/* 69 */ 0,
/* 70 */ 74,
/* 71 */ 86,
/* 72 */ -69,
/* 73 */ 8,
/* 74 */ 78,
/* 75 */ 93,
/* 76 */ -74,
/* 77 */ 130,
/* 78 */ 82,
/* 79 */ 113,
/* 80 */ -74,
/* 81 */ 131,
/* 82 */ 0,
/* 83 */ 161,
/* 84 */ -74,
/* 85 */ 132,
/* 86 */ 90,
/* 87 */ 69,
/* 88 */ -86,
/* 89 */ 133,
/* 90 */ 0,
/* 91 */ -86,
/* 92 */ 208,
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
/* 150 */ 169,
/* 151 */ -113,
/* 152 */ 23,
/* 153 */ 157,
/* 154 */ 288,
/* 155 */ -113,
/* 156 */ 24,
/* 157 */ 0,
/* 158 */ 581,
/* 159 */ -113,
/* 160 */ 25,
/* 161 */ 165,
/* 162 */ 50260,
/* 163 */ -161,
/* 164 */ 26,
/* 165 */ 0,
/* 166 */ 50286,
/* 167 */ -161,
/* 168 */ 27,
/* 169 */ 177,
/* 170 */ 189,
/* 171 */ 182,
/* 172 */ 50123,
/* 173 */ 197,
/* 174 */ 50125,
/* 175 */ -169,
/* 176 */ 28,
/* 177 */ 0,
/* 178 */ 189,
/* 179 */ 50299,
/* 180 */ -169,
/* 181 */ 29,
/* 182 */ 186,
/* 183 */ 50299,
/* 184 */ -182,
/* 185 */ 134,
/* 186 */ 0,
/* 187 */ -182,
/* 188 */ 209,
/* 189 */ 193,
/* 190 */ 50280,
/* 191 */ -189,
/* 192 */ 30,
/* 193 */ 0,
/* 194 */ 50283,
/* 195 */ -189,
/* 196 */ 31,
/* 197 */ 0,
/* 198 */ 202,
/* 199 */ 235,
/* 200 */ -197,
/* 201 */ 32,
/* 202 */ 206,
/* 203 */ 197,
/* 204 */ -202,
/* 205 */ 135,
/* 206 */ 0,
/* 207 */ -202,
/* 208 */ 210,
/* 209 */ 0,
/* 210 */ 214,
/* 211 */ 222,
/* 212 */ -209,
/* 213 */ 33,
/* 214 */ 219,
/* 215 */ 209,
/* 216 */ 50044,
/* 217 */ -214,
/* 218 */ 136,
/* 219 */ 0,
/* 220 */ -214,
/* 221 */ 211,
/* 222 */ 0,
/* 223 */ 227,
/* 224 */ 478,
/* 225 */ -222,
/* 226 */ 34,
/* 227 */ 232,
/* 228 */ 331,
/* 229 */ 50061,
/* 230 */ -227,
/* 231 */ 137,
/* 232 */ 0,
/* 233 */ -227,
/* 234 */ 212,
/* 235 */ 0,
/* 236 */ 241,
/* 237 */ 261,
/* 238 */ 50059,
/* 239 */ -235,
/* 240 */ 35,
/* 241 */ 0,
/* 242 */ 246,
/* 243 */ 254,
/* 244 */ -241,
/* 245 */ 36,
/* 246 */ 250,
/* 247 */ 113,
/* 248 */ -246,
/* 249 */ 138,
/* 250 */ 0,
/* 251 */ 161,
/* 252 */ -246,
/* 253 */ 139,
/* 254 */ 258,
/* 255 */ 241,
/* 256 */ -254,
/* 257 */ 140,
/* 258 */ 0,
/* 259 */ -254,
/* 260 */ 213,
/* 261 */ 265,
/* 262 */ 271,
/* 263 */ -261,
/* 264 */ 37,
/* 265 */ 0,
/* 266 */ 261,
/* 267 */ 50044,
/* 268 */ 271,
/* 269 */ -261,
/* 270 */ 38,
/* 271 */ 275,
/* 272 */ 331,
/* 273 */ -271,
/* 274 */ 39,
/* 275 */ 0,
/* 276 */ 281,
/* 277 */ 50058,
/* 278 */ 824,
/* 279 */ -271,
/* 280 */ 40,
/* 281 */ 285,
/* 282 */ 331,
/* 283 */ -281,
/* 284 */ 141,
/* 285 */ 0,
/* 286 */ -281,
/* 287 */ 214,
/* 288 */ 296,
/* 289 */ 50266,
/* 290 */ 301,
/* 291 */ 50123,
/* 292 */ 308,
/* 293 */ 50125,
/* 294 */ -288,
/* 295 */ 41,
/* 296 */ 0,
/* 297 */ 50266,
/* 298 */ 50299,
/* 299 */ -288,
/* 300 */ 42,
/* 301 */ 305,
/* 302 */ 50299,
/* 303 */ -301,
/* 304 */ 142,
/* 305 */ 0,
/* 306 */ -301,
/* 307 */ 215,
/* 308 */ 0,
/* 309 */ 313,
/* 310 */ 321,
/* 311 */ -308,
/* 312 */ 43,
/* 313 */ 318,
/* 314 */ 308,
/* 315 */ 50044,
/* 316 */ -313,
/* 317 */ 143,
/* 318 */ 0,
/* 319 */ -313,
/* 320 */ 216,
/* 321 */ 0,
/* 322 */ 50299,
/* 323 */ 326,
/* 324 */ -321,
/* 325 */ 44,
/* 326 */ 0,
/* 327 */ 50061,
/* 328 */ 824,
/* 329 */ -326,
/* 330 */ 144,
/* 331 */ 0,
/* 332 */ 336,
/* 333 */ 343,
/* 334 */ -331,
/* 335 */ 45,
/* 336 */ 340,
/* 337 */ 390,
/* 338 */ -336,
/* 339 */ 145,
/* 340 */ 0,
/* 341 */ -336,
/* 342 */ 217,
/* 343 */ 347,
/* 344 */ 50299,
/* 345 */ -343,
/* 346 */ 46,
/* 347 */ 353,
/* 348 */ 50040,
/* 349 */ 331,
/* 350 */ 50041,
/* 351 */ -343,
/* 352 */ 47,
/* 353 */ 0,
/* 354 */ 343,
/* 355 */ 358,
/* 356 */ -343,
/* 357 */ 48,
/* 358 */ 364,
/* 359 */ 50091,
/* 360 */ 376,
/* 361 */ 50093,
/* 362 */ -358,
/* 363 */ 147,
/* 364 */ 370,
/* 365 */ 50040,
/* 366 */ 422,
/* 367 */ 50041,
/* 368 */ -358,
/* 369 */ 148,
/* 370 */ 0,
/* 371 */ 50040,
/* 372 */ 383,
/* 373 */ 50041,
/* 374 */ -358,
/* 375 */ 150,
/* 376 */ 380,
/* 377 */ 824,
/* 378 */ -376,
/* 379 */ 146,
/* 380 */ 0,
/* 381 */ -376,
/* 382 */ 218,
/* 383 */ 387,
/* 384 */ 465,
/* 385 */ -383,
/* 386 */ 149,
/* 387 */ 0,
/* 388 */ -383,
/* 389 */ 219,
/* 390 */ 0,
/* 391 */ 50042,
/* 392 */ 396,
/* 393 */ 403,
/* 394 */ -390,
/* 395 */ 49,
/* 396 */ 400,
/* 397 */ 410,
/* 398 */ -396,
/* 399 */ 151,
/* 400 */ 0,
/* 401 */ -396,
/* 402 */ 220,
/* 403 */ 407,
/* 404 */ 390,
/* 405 */ -403,
/* 406 */ 152,
/* 407 */ 0,
/* 408 */ -403,
/* 409 */ 221,
/* 410 */ 0,
/* 411 */ 415,
/* 412 */ 161,
/* 413 */ -410,
/* 414 */ 50,
/* 415 */ 419,
/* 416 */ 410,
/* 417 */ -415,
/* 418 */ 153,
/* 419 */ 0,
/* 420 */ -415,
/* 421 */ 222,
/* 422 */ 0,
/* 423 */ 432,
/* 424 */ 427,
/* 425 */ -422,
/* 426 */ 51,
/* 427 */ 0,
/* 428 */ 50044,
/* 429 */ 50290,
/* 430 */ -427,
/* 431 */ 154,
/* 432 */ 0,
/* 433 */ 437,
/* 434 */ 445,
/* 435 */ -432,
/* 436 */ 52,
/* 437 */ 442,
/* 438 */ 432,
/* 439 */ 50044,
/* 440 */ -437,
/* 441 */ 155,
/* 442 */ 0,
/* 443 */ -437,
/* 444 */ 223,
/* 445 */ 0,
/* 446 */ 69,
/* 447 */ 450,
/* 448 */ -445,
/* 449 */ 53,
/* 450 */ 454,
/* 451 */ 331,
/* 452 */ -450,
/* 453 */ 156,
/* 454 */ 0,
/* 455 */ 458,
/* 456 */ -450,
/* 457 */ 158,
/* 458 */ 462,
/* 459 */ 521,
/* 460 */ -458,
/* 461 */ 157,
/* 462 */ 0,
/* 463 */ -458,
/* 464 */ 224,
/* 465 */ 0,
/* 466 */ 470,
/* 467 */ 50299,
/* 468 */ -465,
/* 469 */ 54,
/* 470 */ 475,
/* 471 */ 465,
/* 472 */ 50044,
/* 473 */ -470,
/* 474 */ 159,
/* 475 */ 0,
/* 476 */ -470,
/* 477 */ 225,
/* 478 */ 482,
/* 479 */ 791,
/* 480 */ -478,
/* 481 */ 55,
/* 482 */ 0,
/* 483 */ 50123,
/* 484 */ 496,
/* 485 */ 489,
/* 486 */ 50125,
/* 487 */ -478,
/* 488 */ 56,
/* 489 */ 493,
/* 490 */ 50044,
/* 491 */ -489,
/* 492 */ 160,
/* 493 */ 0,
/* 494 */ -489,
/* 495 */ 226,
/* 496 */ 0,
/* 497 */ 501,
/* 498 */ 478,
/* 499 */ -496,
/* 500 */ 57,
/* 501 */ 506,
/* 502 */ 496,
/* 503 */ 50044,
/* 504 */ -501,
/* 505 */ 161,
/* 506 */ 0,
/* 507 */ -501,
/* 508 */ 227,
/* 509 */ 0,
/* 510 */ 241,
/* 511 */ 514,
/* 512 */ -509,
/* 513 */ 58,
/* 514 */ 518,
/* 515 */ 521,
/* 516 */ -514,
/* 517 */ 162,
/* 518 */ 0,
/* 519 */ -514,
/* 520 */ 228,
/* 521 */ 525,
/* 522 */ 390,
/* 523 */ -521,
/* 524 */ 59,
/* 525 */ 0,
/* 526 */ 530,
/* 527 */ 537,
/* 528 */ -521,
/* 529 */ 60,
/* 530 */ 534,
/* 531 */ 390,
/* 532 */ -530,
/* 533 */ 163,
/* 534 */ 0,
/* 535 */ -530,
/* 536 */ 229,
/* 537 */ 543,
/* 538 */ 50040,
/* 539 */ 521,
/* 540 */ 50041,
/* 541 */ -537,
/* 542 */ 61,
/* 543 */ 0,
/* 544 */ 548,
/* 545 */ 555,
/* 546 */ -537,
/* 547 */ 62,
/* 548 */ 552,
/* 549 */ 537,
/* 550 */ -548,
/* 551 */ 164,
/* 552 */ 0,
/* 553 */ -548,
/* 554 */ 230,
/* 555 */ 561,
/* 556 */ 50091,
/* 557 */ 567,
/* 558 */ 50093,
/* 559 */ -555,
/* 560 */ 166,
/* 561 */ 0,
/* 562 */ 50040,
/* 563 */ 574,
/* 564 */ 50041,
/* 565 */ -555,
/* 566 */ 168,
/* 567 */ 571,
/* 568 */ 824,
/* 569 */ -567,
/* 570 */ 165,
/* 571 */ 0,
/* 572 */ -567,
/* 573 */ 231,
/* 574 */ 578,
/* 575 */ 422,
/* 576 */ -574,
/* 577 */ 167,
/* 578 */ 0,
/* 579 */ -574,
/* 580 */ 232,
/* 581 */ 0,
/* 582 */ 50299,
/* 583 */ -581,
/* 584 */ 63,
/* 585 */ 589,
/* 586 */ 609,
/* 587 */ -585,
/* 588 */ 64,
/* 589 */ 593,
/* 590 */ 628,
/* 591 */ -585,
/* 592 */ 65,
/* 593 */ 597,
/* 594 */ 640,
/* 595 */ -585,
/* 596 */ 66,
/* 597 */ 601,
/* 598 */ 673,
/* 599 */ -585,
/* 600 */ 67,
/* 601 */ 605,
/* 602 */ 698,
/* 603 */ -585,
/* 604 */ 68,
/* 605 */ 0,
/* 606 */ 749,
/* 607 */ -585,
/* 608 */ 69,
/* 609 */ 615,
/* 610 */ 50299,
/* 611 */ 50058,
/* 612 */ 585,
/* 613 */ -609,
/* 614 */ 70,
/* 615 */ 622,
/* 616 */ 50258,
/* 617 */ 824,
/* 618 */ 50058,
/* 619 */ 585,
/* 620 */ -609,
/* 621 */ 71,
/* 622 */ 0,
/* 623 */ 50262,
/* 624 */ 50058,
/* 625 */ 585,
/* 626 */ -609,
/* 627 */ 72,
/* 628 */ 0,
/* 629 */ 633,
/* 630 */ 50059,
/* 631 */ -628,
/* 632 */ 73,
/* 633 */ 637,
/* 634 */ 778,
/* 635 */ -633,
/* 636 */ 169,
/* 637 */ 0,
/* 638 */ -633,
/* 639 */ 233,
/* 640 */ 0,
/* 641 */ 50123,
/* 642 */ 647,
/* 643 */ 654,
/* 644 */ 50125,
/* 645 */ -640,
/* 646 */ 74,
/* 647 */ 651,
/* 648 */ 57,
/* 649 */ -647,
/* 650 */ 170,
/* 651 */ 0,
/* 652 */ -647,
/* 653 */ 234,
/* 654 */ 658,
/* 655 */ 661,
/* 656 */ -654,
/* 657 */ 171,
/* 658 */ 0,
/* 659 */ -654,
/* 660 */ 235,
/* 661 */ 0,
/* 662 */ 666,
/* 663 */ 585,
/* 664 */ -661,
/* 665 */ 75,
/* 666 */ 670,
/* 667 */ 661,
/* 668 */ -666,
/* 669 */ 172,
/* 670 */ 0,
/* 671 */ -666,
/* 672 */ 236,
/* 673 */ 682,
/* 674 */ 50271,
/* 675 */ 50040,
/* 676 */ 778,
/* 677 */ 50041,
/* 678 */ 585,
/* 679 */ 690,
/* 680 */ -673,
/* 681 */ 76,
/* 682 */ 0,
/* 683 */ 50281,
/* 684 */ 50040,
/* 685 */ 778,
/* 686 */ 50041,
/* 687 */ 585,
/* 688 */ -673,
/* 689 */ 77,
/* 690 */ 695,
/* 691 */ 50265,
/* 692 */ 585,
/* 693 */ -690,
/* 694 */ 173,
/* 695 */ 0,
/* 696 */ -690,
/* 697 */ 237,
/* 698 */ 706,
/* 699 */ 50287,
/* 700 */ 50040,
/* 701 */ 778,
/* 702 */ 50041,
/* 703 */ 585,
/* 704 */ -698,
/* 705 */ 78,
/* 706 */ 716,
/* 707 */ 50263,
/* 708 */ 585,
/* 709 */ 50287,
/* 710 */ 50040,
/* 711 */ 778,
/* 712 */ 50041,
/* 713 */ 50059,
/* 714 */ -698,
/* 715 */ 79,
/* 716 */ 0,
/* 717 */ 50269,
/* 718 */ 50040,
/* 719 */ 728,
/* 720 */ 50059,
/* 721 */ 735,
/* 722 */ 50059,
/* 723 */ 742,
/* 724 */ 50041,
/* 725 */ 585,
/* 726 */ -698,
/* 727 */ 80,
/* 728 */ 732,
/* 729 */ 778,
/* 730 */ -728,
/* 731 */ 174,
/* 732 */ 0,
/* 733 */ -728,
/* 734 */ 238,
/* 735 */ 739,
/* 736 */ 778,
/* 737 */ -735,
/* 738 */ 175,
/* 739 */ 0,
/* 740 */ -735,
/* 741 */ 239,
/* 742 */ 746,
/* 743 */ 778,
/* 744 */ -742,
/* 745 */ 176,
/* 746 */ 0,
/* 747 */ -742,
/* 748 */ 240,
/* 749 */ 755,
/* 750 */ 50270,
/* 751 */ 50299,
/* 752 */ 50059,
/* 753 */ -749,
/* 754 */ 81,
/* 755 */ 760,
/* 756 */ 50261,
/* 757 */ 50059,
/* 758 */ -749,
/* 759 */ 82,
/* 760 */ 765,
/* 761 */ 50257,
/* 762 */ 50059,
/* 763 */ -749,
/* 764 */ 83,
/* 765 */ 0,
/* 766 */ 50275,
/* 767 */ 771,
/* 768 */ 50059,
/* 769 */ -749,
/* 770 */ 84,
/* 771 */ 775,
/* 772 */ 778,
/* 773 */ -771,
/* 774 */ 177,
/* 775 */ 0,
/* 776 */ -771,
/* 777 */ 241,
/* 778 */ 0,
/* 779 */ 783,
/* 780 */ 791,
/* 781 */ -778,
/* 782 */ 85,
/* 783 */ 788,
/* 784 */ 778,
/* 785 */ 50044,
/* 786 */ -783,
/* 787 */ 178,
/* 788 */ 0,
/* 789 */ -783,
/* 790 */ 242,
/* 791 */ 795,
/* 792 */ 809,
/* 793 */ -791,
/* 794 */ 86,
/* 795 */ 0,
/* 796 */ 976,
/* 797 */ 801,
/* 798 */ 791,
/* 799 */ -791,
/* 800 */ 87,
/* 801 */ 805,
/* 802 */ 50291,
/* 803 */ -801,
/* 804 */ 88,
/* 805 */ 0,
/* 806 */ 50061,
/* 807 */ -801,
/* 808 */ 89,
/* 809 */ 0,
/* 810 */ 828,
/* 811 */ 814,
/* 812 */ -809,
/* 813 */ 90,
/* 814 */ 821,
/* 815 */ 50063,
/* 816 */ 778,
/* 817 */ 50058,
/* 818 */ 809,
/* 819 */ -814,
/* 820 */ 179,
/* 821 */ 0,
/* 822 */ -814,
/* 823 */ 243,
/* 824 */ 0,
/* 825 */ 809,
/* 826 */ -824,
/* 827 */ 91,
/* 828 */ 0,
/* 829 */ 833,
/* 830 */ 841,
/* 831 */ -828,
/* 832 */ 92,
/* 833 */ 838,
/* 834 */ 828,
/* 835 */ 50297,
/* 836 */ -833,
/* 837 */ 180,
/* 838 */ 0,
/* 839 */ -833,
/* 840 */ 244,
/* 841 */ 0,
/* 842 */ 846,
/* 843 */ 854,
/* 844 */ -841,
/* 845 */ 93,
/* 846 */ 851,
/* 847 */ 841,
/* 848 */ 50298,
/* 849 */ -846,
/* 850 */ 181,
/* 851 */ 0,
/* 852 */ -846,
/* 853 */ 245,
/* 854 */ 0,
/* 855 */ 859,
/* 856 */ 867,
/* 857 */ -854,
/* 858 */ 94,
/* 859 */ 864,
/* 860 */ 854,
/* 861 */ 50301,
/* 862 */ -859,
/* 863 */ 182,
/* 864 */ 0,
/* 865 */ -859,
/* 866 */ 246,
/* 867 */ 0,
/* 868 */ 872,
/* 869 */ 880,
/* 870 */ -867,
/* 871 */ 95,
/* 872 */ 877,
/* 873 */ 867,
/* 874 */ 50303,
/* 875 */ -872,
/* 876 */ 183,
/* 877 */ 0,
/* 878 */ -872,
/* 879 */ 247,
/* 880 */ 0,
/* 881 */ 885,
/* 882 */ 893,
/* 883 */ -880,
/* 884 */ 96,
/* 885 */ 890,
/* 886 */ 880,
/* 887 */ 50302,
/* 888 */ -885,
/* 889 */ 184,
/* 890 */ 0,
/* 891 */ -885,
/* 892 */ 248,
/* 893 */ 0,
/* 894 */ 898,
/* 895 */ 906,
/* 896 */ -893,
/* 897 */ 97,
/* 898 */ 903,
/* 899 */ 893,
/* 900 */ 50292,
/* 901 */ -898,
/* 902 */ 185,
/* 903 */ 0,
/* 904 */ -898,
/* 905 */ 249,
/* 906 */ 0,
/* 907 */ 911,
/* 908 */ 919,
/* 909 */ -906,
/* 910 */ 98,
/* 911 */ 916,
/* 912 */ 906,
/* 913 */ 50304,
/* 914 */ -911,
/* 915 */ 186,
/* 916 */ 0,
/* 917 */ -911,
/* 918 */ 250,
/* 919 */ 0,
/* 920 */ 924,
/* 921 */ 940,
/* 922 */ -919,
/* 923 */ 99,
/* 924 */ 929,
/* 925 */ 919,
/* 926 */ 932,
/* 927 */ -924,
/* 928 */ 189,
/* 929 */ 0,
/* 930 */ -924,
/* 931 */ 251,
/* 932 */ 936,
/* 933 */ 50043,
/* 934 */ -932,
/* 935 */ 187,
/* 936 */ 0,
/* 937 */ 50045,
/* 938 */ -932,
/* 939 */ 188,
/* 940 */ 0,
/* 941 */ 945,
/* 942 */ 965,
/* 943 */ -940,
/* 944 */ 100,
/* 945 */ 950,
/* 946 */ 940,
/* 947 */ 953,
/* 948 */ -945,
/* 949 */ 193,
/* 950 */ 0,
/* 951 */ -945,
/* 952 */ 252,
/* 953 */ 957,
/* 954 */ 50042,
/* 955 */ -953,
/* 956 */ 190,
/* 957 */ 961,
/* 958 */ 50047,
/* 959 */ -953,
/* 960 */ 191,
/* 961 */ 0,
/* 962 */ 50037,
/* 963 */ -953,
/* 964 */ 192,
/* 965 */ 969,
/* 966 */ 976,
/* 967 */ -965,
/* 968 */ 101,
/* 969 */ 0,
/* 970 */ 50040,
/* 971 */ 509,
/* 972 */ 50041,
/* 973 */ 965,
/* 974 */ -965,
/* 975 */ 102,
/* 976 */ 980,
/* 977 */ 1034,
/* 978 */ -976,
/* 979 */ 103,
/* 980 */ 985,
/* 981 */ 1002,
/* 982 */ 976,
/* 983 */ -976,
/* 984 */ 104,
/* 985 */ 990,
/* 986 */ 1010,
/* 987 */ 965,
/* 988 */ -976,
/* 989 */ 105,
/* 990 */ 995,
/* 991 */ 50278,
/* 992 */ 976,
/* 993 */ -976,
/* 994 */ 106,
/* 995 */ 0,
/* 996 */ 50278,
/* 997 */ 50040,
/* 998 */ 509,
/* 999 */ 50041,
/* 1000 */ -976,
/* 1001 */ 107,
/* 1002 */ 1006,
/* 1003 */ 50294,
/* 1004 */ -1002,
/* 1005 */ 194,
/* 1006 */ 0,
/* 1007 */ 50295,
/* 1008 */ -1002,
/* 1009 */ 195,
/* 1010 */ 1014,
/* 1011 */ 50038,
/* 1012 */ -1010,
/* 1013 */ 108,
/* 1014 */ 1018,
/* 1015 */ 50042,
/* 1016 */ -1010,
/* 1017 */ 109,
/* 1018 */ 1022,
/* 1019 */ 50043,
/* 1020 */ -1010,
/* 1021 */ 110,
/* 1022 */ 1026,
/* 1023 */ 50045,
/* 1024 */ -1010,
/* 1025 */ 111,
/* 1026 */ 1030,
/* 1027 */ 50126,
/* 1028 */ -1010,
/* 1029 */ 112,
/* 1030 */ 0,
/* 1031 */ 50033,
/* 1032 */ -1010,
/* 1033 */ 113,
/* 1034 */ 1038,
/* 1035 */ 1080,
/* 1036 */ -1034,
/* 1037 */ 114,
/* 1038 */ 0,
/* 1039 */ 1034,
/* 1040 */ 1043,
/* 1041 */ -1034,
/* 1042 */ 115,
/* 1043 */ 1049,
/* 1044 */ 50091,
/* 1045 */ 778,
/* 1046 */ 50093,
/* 1047 */ -1043,
/* 1048 */ 196,
/* 1049 */ 1055,
/* 1050 */ 50040,
/* 1051 */ 1073,
/* 1052 */ 50041,
/* 1053 */ -1043,
/* 1054 */ 198,
/* 1055 */ 1060,
/* 1056 */ 50046,
/* 1057 */ 50299,
/* 1058 */ -1043,
/* 1059 */ 199,
/* 1060 */ 1065,
/* 1061 */ 50296,
/* 1062 */ 50299,
/* 1063 */ -1043,
/* 1064 */ 200,
/* 1065 */ 1069,
/* 1066 */ 50294,
/* 1067 */ -1043,
/* 1068 */ 201,
/* 1069 */ 0,
/* 1070 */ 50295,
/* 1071 */ -1043,
/* 1072 */ 202,
/* 1073 */ 1077,
/* 1074 */ 1098,
/* 1075 */ -1073,
/* 1076 */ 197,
/* 1077 */ 0,
/* 1078 */ -1073,
/* 1079 */ 253,
/* 1080 */ 1084,
/* 1081 */ 50299,
/* 1082 */ -1080,
/* 1083 */ 116,
/* 1084 */ 1088,
/* 1085 */ 1111,
/* 1086 */ -1080,
/* 1087 */ 117,
/* 1088 */ 1092,
/* 1089 */ 50289,
/* 1090 */ -1080,
/* 1091 */ 118,
/* 1092 */ 0,
/* 1093 */ 50040,
/* 1094 */ 778,
/* 1095 */ 50041,
/* 1096 */ -1080,
/* 1097 */ 119,
/* 1098 */ 0,
/* 1099 */ 1103,
/* 1100 */ 791,
/* 1101 */ -1098,
/* 1102 */ 120,
/* 1103 */ 1108,
/* 1104 */ 1098,
/* 1105 */ 50044,
/* 1106 */ -1103,
/* 1107 */ 203,
/* 1108 */ 0,
/* 1109 */ -1103,
/* 1110 */ 254,
/* 1111 */ 1115,
/* 1112 */ 50308,
/* 1113 */ -1111,
/* 1114 */ 121,
/* 1115 */ 1119,
/* 1116 */ 50306,
/* 1117 */ -1111,
/* 1118 */ 122,
/* 1119 */ 1123,
/* 1120 */ 50307,
/* 1121 */ -1111,
/* 1122 */ 123,
/* 1123 */ 0,
/* 1124 */ 50299,
/* 1125 */ -1111,
/* 1126 */ 124,
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
/* 153 */ 157,
/* 154 */ 1,
/* 155 */ -113,
/* 156 */ 11,
/* 157 */ 0,
/* 158 */ 1,
/* 159 */ -113,
/* 160 */ 12,
/* 161 */ 165,
/* 162 */ 50260,
/* 163 */ -161,
/* 164 */ 1,
/* 165 */ 0,
/* 166 */ 50286,
/* 167 */ -161,
/* 168 */ 2,
/* 169 */ 177,
/* 170 */ 1,
/* 171 */ 1,
/* 172 */ 50123,
/* 173 */ 1,
/* 174 */ 50125,
/* 175 */ -169,
/* 176 */ 1,
/* 177 */ 0,
/* 178 */ 1,
/* 179 */ 50299,
/* 180 */ -169,
/* 181 */ 2,
/* 182 */ 186,
/* 183 */ 50299,
/* 184 */ -182,
/* 185 */ 1,
/* 186 */ 0,
/* 187 */ -182,
/* 188 */ 2,
/* 189 */ 193,
/* 190 */ 50280,
/* 191 */ -189,
/* 192 */ 1,
/* 193 */ 0,
/* 194 */ 50283,
/* 195 */ -189,
/* 196 */ 2,
/* 197 */ 0,
/* 198 */ 1,
/* 199 */ 1,
/* 200 */ -197,
/* 201 */ 1,
/* 202 */ 206,
/* 203 */ 1,
/* 204 */ -202,
/* 205 */ 1,
/* 206 */ 0,
/* 207 */ -202,
/* 208 */ 2,
/* 209 */ 0,
/* 210 */ 1,
/* 211 */ 1,
/* 212 */ -209,
/* 213 */ 1,
/* 214 */ 219,
/* 215 */ 1,
/* 216 */ 50044,
/* 217 */ -214,
/* 218 */ 1,
/* 219 */ 0,
/* 220 */ -214,
/* 221 */ 2,
/* 222 */ 0,
/* 223 */ 1,
/* 224 */ 1,
/* 225 */ -222,
/* 226 */ 1,
/* 227 */ 232,
/* 228 */ 1,
/* 229 */ 50061,
/* 230 */ -227,
/* 231 */ 1,
/* 232 */ 0,
/* 233 */ -227,
/* 234 */ 2,
/* 235 */ 0,
/* 236 */ 1,
/* 237 */ 1,
/* 238 */ 50059,
/* 239 */ -235,
/* 240 */ 1,
/* 241 */ 0,
/* 242 */ 1,
/* 243 */ 1,
/* 244 */ -241,
/* 245 */ 1,
/* 246 */ 250,
/* 247 */ 1,
/* 248 */ -246,
/* 249 */ 1,
/* 250 */ 0,
/* 251 */ 1,
/* 252 */ -246,
/* 253 */ 2,
/* 254 */ 258,
/* 255 */ 1,
/* 256 */ -254,
/* 257 */ 1,
/* 258 */ 0,
/* 259 */ -254,
/* 260 */ 2,
/* 261 */ 265,
/* 262 */ 1,
/* 263 */ -261,
/* 264 */ 1,
/* 265 */ 0,
/* 266 */ 1,
/* 267 */ 50044,
/* 268 */ 1,
/* 269 */ -261,
/* 270 */ 2,
/* 271 */ 275,
/* 272 */ 1,
/* 273 */ -271,
/* 274 */ 1,
/* 275 */ 0,
/* 276 */ 1,
/* 277 */ 50058,
/* 278 */ 1,
/* 279 */ -271,
/* 280 */ 2,
/* 281 */ 285,
/* 282 */ 1,
/* 283 */ -281,
/* 284 */ 1,
/* 285 */ 0,
/* 286 */ -281,
/* 287 */ 2,
/* 288 */ 296,
/* 289 */ 50266,
/* 290 */ 1,
/* 291 */ 50123,
/* 292 */ 1,
/* 293 */ 50125,
/* 294 */ -288,
/* 295 */ 1,
/* 296 */ 0,
/* 297 */ 50266,
/* 298 */ 50299,
/* 299 */ -288,
/* 300 */ 2,
/* 301 */ 305,
/* 302 */ 50299,
/* 303 */ -301,
/* 304 */ 1,
/* 305 */ 0,
/* 306 */ -301,
/* 307 */ 2,
/* 308 */ 0,
/* 309 */ 1,
/* 310 */ 1,
/* 311 */ -308,
/* 312 */ 1,
/* 313 */ 318,
/* 314 */ 1,
/* 315 */ 50044,
/* 316 */ -313,
/* 317 */ 1,
/* 318 */ 0,
/* 319 */ -313,
/* 320 */ 2,
/* 321 */ 0,
/* 322 */ 50299,
/* 323 */ 1,
/* 324 */ -321,
/* 325 */ 1,
/* 326 */ 0,
/* 327 */ 50061,
/* 328 */ 1,
/* 329 */ -326,
/* 330 */ 1,
/* 331 */ 0,
/* 332 */ 1,
/* 333 */ 1,
/* 334 */ -331,
/* 335 */ 1,
/* 336 */ 340,
/* 337 */ 1,
/* 338 */ -336,
/* 339 */ 1,
/* 340 */ 0,
/* 341 */ -336,
/* 342 */ 2,
/* 343 */ 347,
/* 344 */ 50299,
/* 345 */ -343,
/* 346 */ 1,
/* 347 */ 353,
/* 348 */ 50040,
/* 349 */ 1,
/* 350 */ 50041,
/* 351 */ -343,
/* 352 */ 2,
/* 353 */ 0,
/* 354 */ 1,
/* 355 */ 1,
/* 356 */ -343,
/* 357 */ 3,
/* 358 */ 364,
/* 359 */ 50091,
/* 360 */ 1,
/* 361 */ 50093,
/* 362 */ -358,
/* 363 */ 1,
/* 364 */ 370,
/* 365 */ 50040,
/* 366 */ 1,
/* 367 */ 50041,
/* 368 */ -358,
/* 369 */ 2,
/* 370 */ 0,
/* 371 */ 50040,
/* 372 */ 1,
/* 373 */ 50041,
/* 374 */ -358,
/* 375 */ 3,
/* 376 */ 380,
/* 377 */ 1,
/* 378 */ -376,
/* 379 */ 1,
/* 380 */ 0,
/* 381 */ -376,
/* 382 */ 2,
/* 383 */ 387,
/* 384 */ 1,
/* 385 */ -383,
/* 386 */ 1,
/* 387 */ 0,
/* 388 */ -383,
/* 389 */ 2,
/* 390 */ 0,
/* 391 */ 50042,
/* 392 */ 1,
/* 393 */ 1,
/* 394 */ -390,
/* 395 */ 1,
/* 396 */ 400,
/* 397 */ 1,
/* 398 */ -396,
/* 399 */ 1,
/* 400 */ 0,
/* 401 */ -396,
/* 402 */ 2,
/* 403 */ 407,
/* 404 */ 1,
/* 405 */ -403,
/* 406 */ 1,
/* 407 */ 0,
/* 408 */ -403,
/* 409 */ 2,
/* 410 */ 0,
/* 411 */ 1,
/* 412 */ 1,
/* 413 */ -410,
/* 414 */ 1,
/* 415 */ 419,
/* 416 */ 1,
/* 417 */ -415,
/* 418 */ 1,
/* 419 */ 0,
/* 420 */ -415,
/* 421 */ 2,
/* 422 */ 0,
/* 423 */ 1,
/* 424 */ 1,
/* 425 */ -422,
/* 426 */ 1,
/* 427 */ 0,
/* 428 */ 50044,
/* 429 */ 50290,
/* 430 */ -427,
/* 431 */ 1,
/* 432 */ 0,
/* 433 */ 1,
/* 434 */ 1,
/* 435 */ -432,
/* 436 */ 1,
/* 437 */ 442,
/* 438 */ 1,
/* 439 */ 50044,
/* 440 */ -437,
/* 441 */ 1,
/* 442 */ 0,
/* 443 */ -437,
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
/* 455 */ 1,
/* 456 */ -450,
/* 457 */ 2,
/* 458 */ 462,
/* 459 */ 1,
/* 460 */ -458,
/* 461 */ 1,
/* 462 */ 0,
/* 463 */ -458,
/* 464 */ 2,
/* 465 */ 0,
/* 466 */ 1,
/* 467 */ 50299,
/* 468 */ -465,
/* 469 */ 1,
/* 470 */ 475,
/* 471 */ 1,
/* 472 */ 50044,
/* 473 */ -470,
/* 474 */ 1,
/* 475 */ 0,
/* 476 */ -470,
/* 477 */ 2,
/* 478 */ 482,
/* 479 */ 1,
/* 480 */ -478,
/* 481 */ 1,
/* 482 */ 0,
/* 483 */ 50123,
/* 484 */ 1,
/* 485 */ 1,
/* 486 */ 50125,
/* 487 */ -478,
/* 488 */ 2,
/* 489 */ 493,
/* 490 */ 50044,
/* 491 */ -489,
/* 492 */ 1,
/* 493 */ 0,
/* 494 */ -489,
/* 495 */ 2,
/* 496 */ 0,
/* 497 */ 1,
/* 498 */ 1,
/* 499 */ -496,
/* 500 */ 1,
/* 501 */ 506,
/* 502 */ 1,
/* 503 */ 50044,
/* 504 */ -501,
/* 505 */ 1,
/* 506 */ 0,
/* 507 */ -501,
/* 508 */ 2,
/* 509 */ 0,
/* 510 */ 1,
/* 511 */ 1,
/* 512 */ -509,
/* 513 */ 1,
/* 514 */ 518,
/* 515 */ 1,
/* 516 */ -514,
/* 517 */ 1,
/* 518 */ 0,
/* 519 */ -514,
/* 520 */ 2,
/* 521 */ 525,
/* 522 */ 1,
/* 523 */ -521,
/* 524 */ 1,
/* 525 */ 0,
/* 526 */ 1,
/* 527 */ 1,
/* 528 */ -521,
/* 529 */ 2,
/* 530 */ 534,
/* 531 */ 1,
/* 532 */ -530,
/* 533 */ 1,
/* 534 */ 0,
/* 535 */ -530,
/* 536 */ 2,
/* 537 */ 543,
/* 538 */ 50040,
/* 539 */ 1,
/* 540 */ 50041,
/* 541 */ -537,
/* 542 */ 1,
/* 543 */ 0,
/* 544 */ 1,
/* 545 */ 1,
/* 546 */ -537,
/* 547 */ 2,
/* 548 */ 552,
/* 549 */ 1,
/* 550 */ -548,
/* 551 */ 1,
/* 552 */ 0,
/* 553 */ -548,
/* 554 */ 2,
/* 555 */ 561,
/* 556 */ 50091,
/* 557 */ 1,
/* 558 */ 50093,
/* 559 */ -555,
/* 560 */ 1,
/* 561 */ 0,
/* 562 */ 50040,
/* 563 */ 1,
/* 564 */ 50041,
/* 565 */ -555,
/* 566 */ 2,
/* 567 */ 571,
/* 568 */ 1,
/* 569 */ -567,
/* 570 */ 1,
/* 571 */ 0,
/* 572 */ -567,
/* 573 */ 2,
/* 574 */ 578,
/* 575 */ 1,
/* 576 */ -574,
/* 577 */ 1,
/* 578 */ 0,
/* 579 */ -574,
/* 580 */ 2,
/* 581 */ 0,
/* 582 */ 50299,
/* 583 */ -581,
/* 584 */ 1,
/* 585 */ 589,
/* 586 */ 1,
/* 587 */ -585,
/* 588 */ 1,
/* 589 */ 593,
/* 590 */ 1,
/* 591 */ -585,
/* 592 */ 2,
/* 593 */ 597,
/* 594 */ 1,
/* 595 */ -585,
/* 596 */ 3,
/* 597 */ 601,
/* 598 */ 1,
/* 599 */ -585,
/* 600 */ 4,
/* 601 */ 605,
/* 602 */ 1,
/* 603 */ -585,
/* 604 */ 5,
/* 605 */ 0,
/* 606 */ 1,
/* 607 */ -585,
/* 608 */ 6,
/* 609 */ 615,
/* 610 */ 50299,
/* 611 */ 50058,
/* 612 */ 1,
/* 613 */ -609,
/* 614 */ 1,
/* 615 */ 622,
/* 616 */ 50258,
/* 617 */ 1,
/* 618 */ 50058,
/* 619 */ 1,
/* 620 */ -609,
/* 621 */ 2,
/* 622 */ 0,
/* 623 */ 50262,
/* 624 */ 50058,
/* 625 */ 1,
/* 626 */ -609,
/* 627 */ 3,
/* 628 */ 0,
/* 629 */ 1,
/* 630 */ 50059,
/* 631 */ -628,
/* 632 */ 1,
/* 633 */ 637,
/* 634 */ 1,
/* 635 */ -633,
/* 636 */ 1,
/* 637 */ 0,
/* 638 */ -633,
/* 639 */ 2,
/* 640 */ 0,
/* 641 */ 50123,
/* 642 */ 1,
/* 643 */ 1,
/* 644 */ 50125,
/* 645 */ -640,
/* 646 */ 1,
/* 647 */ 651,
/* 648 */ 1,
/* 649 */ -647,
/* 650 */ 1,
/* 651 */ 0,
/* 652 */ -647,
/* 653 */ 2,
/* 654 */ 658,
/* 655 */ 1,
/* 656 */ -654,
/* 657 */ 1,
/* 658 */ 0,
/* 659 */ -654,
/* 660 */ 2,
/* 661 */ 0,
/* 662 */ 1,
/* 663 */ 1,
/* 664 */ -661,
/* 665 */ 1,
/* 666 */ 670,
/* 667 */ 1,
/* 668 */ -666,
/* 669 */ 1,
/* 670 */ 0,
/* 671 */ -666,
/* 672 */ 2,
/* 673 */ 682,
/* 674 */ 50271,
/* 675 */ 50040,
/* 676 */ 1,
/* 677 */ 50041,
/* 678 */ 1,
/* 679 */ 1,
/* 680 */ -673,
/* 681 */ 1,
/* 682 */ 0,
/* 683 */ 50281,
/* 684 */ 50040,
/* 685 */ 1,
/* 686 */ 50041,
/* 687 */ 1,
/* 688 */ -673,
/* 689 */ 2,
/* 690 */ 695,
/* 691 */ 50265,
/* 692 */ 1,
/* 693 */ -690,
/* 694 */ 1,
/* 695 */ 0,
/* 696 */ -690,
/* 697 */ 2,
/* 698 */ 706,
/* 699 */ 50287,
/* 700 */ 50040,
/* 701 */ 1,
/* 702 */ 50041,
/* 703 */ 1,
/* 704 */ -698,
/* 705 */ 1,
/* 706 */ 716,
/* 707 */ 50263,
/* 708 */ 1,
/* 709 */ 50287,
/* 710 */ 50040,
/* 711 */ 1,
/* 712 */ 50041,
/* 713 */ 50059,
/* 714 */ -698,
/* 715 */ 2,
/* 716 */ 0,
/* 717 */ 50269,
/* 718 */ 50040,
/* 719 */ 1,
/* 720 */ 50059,
/* 721 */ 1,
/* 722 */ 50059,
/* 723 */ 1,
/* 724 */ 50041,
/* 725 */ 1,
/* 726 */ -698,
/* 727 */ 3,
/* 728 */ 732,
/* 729 */ 1,
/* 730 */ -728,
/* 731 */ 1,
/* 732 */ 0,
/* 733 */ -728,
/* 734 */ 2,
/* 735 */ 739,
/* 736 */ 1,
/* 737 */ -735,
/* 738 */ 1,
/* 739 */ 0,
/* 740 */ -735,
/* 741 */ 2,
/* 742 */ 746,
/* 743 */ 1,
/* 744 */ -742,
/* 745 */ 1,
/* 746 */ 0,
/* 747 */ -742,
/* 748 */ 2,
/* 749 */ 755,
/* 750 */ 50270,
/* 751 */ 50299,
/* 752 */ 50059,
/* 753 */ -749,
/* 754 */ 1,
/* 755 */ 760,
/* 756 */ 50261,
/* 757 */ 50059,
/* 758 */ -749,
/* 759 */ 2,
/* 760 */ 765,
/* 761 */ 50257,
/* 762 */ 50059,
/* 763 */ -749,
/* 764 */ 3,
/* 765 */ 0,
/* 766 */ 50275,
/* 767 */ 1,
/* 768 */ 50059,
/* 769 */ -749,
/* 770 */ 4,
/* 771 */ 775,
/* 772 */ 1,
/* 773 */ -771,
/* 774 */ 1,
/* 775 */ 0,
/* 776 */ -771,
/* 777 */ 2,
/* 778 */ 0,
/* 779 */ 1,
/* 780 */ 1,
/* 781 */ -778,
/* 782 */ 1,
/* 783 */ 788,
/* 784 */ 1,
/* 785 */ 50044,
/* 786 */ -783,
/* 787 */ 1,
/* 788 */ 0,
/* 789 */ -783,
/* 790 */ 2,
/* 791 */ 795,
/* 792 */ 1,
/* 793 */ -791,
/* 794 */ 1,
/* 795 */ 0,
/* 796 */ 1,
/* 797 */ 1,
/* 798 */ 1,
/* 799 */ -791,
/* 800 */ 2,
/* 801 */ 805,
/* 802 */ 50291,
/* 803 */ -801,
/* 804 */ 1,
/* 805 */ 0,
/* 806 */ 50061,
/* 807 */ -801,
/* 808 */ 2,
/* 809 */ 0,
/* 810 */ 1,
/* 811 */ 1,
/* 812 */ -809,
/* 813 */ 1,
/* 814 */ 821,
/* 815 */ 50063,
/* 816 */ 1,
/* 817 */ 50058,
/* 818 */ 1,
/* 819 */ -814,
/* 820 */ 1,
/* 821 */ 0,
/* 822 */ -814,
/* 823 */ 2,
/* 824 */ 0,
/* 825 */ 1,
/* 826 */ -824,
/* 827 */ 1,
/* 828 */ 0,
/* 829 */ 1,
/* 830 */ 1,
/* 831 */ -828,
/* 832 */ 1,
/* 833 */ 838,
/* 834 */ 1,
/* 835 */ 50297,
/* 836 */ -833,
/* 837 */ 1,
/* 838 */ 0,
/* 839 */ -833,
/* 840 */ 2,
/* 841 */ 0,
/* 842 */ 1,
/* 843 */ 1,
/* 844 */ -841,
/* 845 */ 1,
/* 846 */ 851,
/* 847 */ 1,
/* 848 */ 50298,
/* 849 */ -846,
/* 850 */ 1,
/* 851 */ 0,
/* 852 */ -846,
/* 853 */ 2,
/* 854 */ 0,
/* 855 */ 1,
/* 856 */ 1,
/* 857 */ -854,
/* 858 */ 1,
/* 859 */ 864,
/* 860 */ 1,
/* 861 */ 50301,
/* 862 */ -859,
/* 863 */ 1,
/* 864 */ 0,
/* 865 */ -859,
/* 866 */ 2,
/* 867 */ 0,
/* 868 */ 1,
/* 869 */ 1,
/* 870 */ -867,
/* 871 */ 1,
/* 872 */ 877,
/* 873 */ 1,
/* 874 */ 50303,
/* 875 */ -872,
/* 876 */ 1,
/* 877 */ 0,
/* 878 */ -872,
/* 879 */ 2,
/* 880 */ 0,
/* 881 */ 1,
/* 882 */ 1,
/* 883 */ -880,
/* 884 */ 1,
/* 885 */ 890,
/* 886 */ 1,
/* 887 */ 50302,
/* 888 */ -885,
/* 889 */ 1,
/* 890 */ 0,
/* 891 */ -885,
/* 892 */ 2,
/* 893 */ 0,
/* 894 */ 1,
/* 895 */ 1,
/* 896 */ -893,
/* 897 */ 1,
/* 898 */ 903,
/* 899 */ 1,
/* 900 */ 50292,
/* 901 */ -898,
/* 902 */ 1,
/* 903 */ 0,
/* 904 */ -898,
/* 905 */ 2,
/* 906 */ 0,
/* 907 */ 1,
/* 908 */ 1,
/* 909 */ -906,
/* 910 */ 1,
/* 911 */ 916,
/* 912 */ 1,
/* 913 */ 50304,
/* 914 */ -911,
/* 915 */ 1,
/* 916 */ 0,
/* 917 */ -911,
/* 918 */ 2,
/* 919 */ 0,
/* 920 */ 1,
/* 921 */ 1,
/* 922 */ -919,
/* 923 */ 1,
/* 924 */ 929,
/* 925 */ 1,
/* 926 */ 1,
/* 927 */ -924,
/* 928 */ 1,
/* 929 */ 0,
/* 930 */ -924,
/* 931 */ 2,
/* 932 */ 936,
/* 933 */ 50043,
/* 934 */ -932,
/* 935 */ 1,
/* 936 */ 0,
/* 937 */ 50045,
/* 938 */ -932,
/* 939 */ 2,
/* 940 */ 0,
/* 941 */ 1,
/* 942 */ 1,
/* 943 */ -940,
/* 944 */ 1,
/* 945 */ 950,
/* 946 */ 1,
/* 947 */ 1,
/* 948 */ -945,
/* 949 */ 1,
/* 950 */ 0,
/* 951 */ -945,
/* 952 */ 2,
/* 953 */ 957,
/* 954 */ 50042,
/* 955 */ -953,
/* 956 */ 1,
/* 957 */ 961,
/* 958 */ 50047,
/* 959 */ -953,
/* 960 */ 2,
/* 961 */ 0,
/* 962 */ 50037,
/* 963 */ -953,
/* 964 */ 3,
/* 965 */ 969,
/* 966 */ 1,
/* 967 */ -965,
/* 968 */ 1,
/* 969 */ 0,
/* 970 */ 50040,
/* 971 */ 1,
/* 972 */ 50041,
/* 973 */ 1,
/* 974 */ -965,
/* 975 */ 2,
/* 976 */ 980,
/* 977 */ 1,
/* 978 */ -976,
/* 979 */ 1,
/* 980 */ 985,
/* 981 */ 1,
/* 982 */ 1,
/* 983 */ -976,
/* 984 */ 2,
/* 985 */ 990,
/* 986 */ 1,
/* 987 */ 1,
/* 988 */ -976,
/* 989 */ 3,
/* 990 */ 995,
/* 991 */ 50278,
/* 992 */ 1,
/* 993 */ -976,
/* 994 */ 4,
/* 995 */ 0,
/* 996 */ 50278,
/* 997 */ 50040,
/* 998 */ 1,
/* 999 */ 50041,
/* 1000 */ -976,
/* 1001 */ 5,
/* 1002 */ 1006,
/* 1003 */ 50294,
/* 1004 */ -1002,
/* 1005 */ 1,
/* 1006 */ 0,
/* 1007 */ 50295,
/* 1008 */ -1002,
/* 1009 */ 2,
/* 1010 */ 1014,
/* 1011 */ 50038,
/* 1012 */ -1010,
/* 1013 */ 1,
/* 1014 */ 1018,
/* 1015 */ 50042,
/* 1016 */ -1010,
/* 1017 */ 2,
/* 1018 */ 1022,
/* 1019 */ 50043,
/* 1020 */ -1010,
/* 1021 */ 3,
/* 1022 */ 1026,
/* 1023 */ 50045,
/* 1024 */ -1010,
/* 1025 */ 4,
/* 1026 */ 1030,
/* 1027 */ 50126,
/* 1028 */ -1010,
/* 1029 */ 5,
/* 1030 */ 0,
/* 1031 */ 50033,
/* 1032 */ -1010,
/* 1033 */ 6,
/* 1034 */ 1038,
/* 1035 */ 1,
/* 1036 */ -1034,
/* 1037 */ 1,
/* 1038 */ 0,
/* 1039 */ 1,
/* 1040 */ 1,
/* 1041 */ -1034,
/* 1042 */ 2,
/* 1043 */ 1049,
/* 1044 */ 50091,
/* 1045 */ 1,
/* 1046 */ 50093,
/* 1047 */ -1043,
/* 1048 */ 1,
/* 1049 */ 1055,
/* 1050 */ 50040,
/* 1051 */ 1,
/* 1052 */ 50041,
/* 1053 */ -1043,
/* 1054 */ 2,
/* 1055 */ 1060,
/* 1056 */ 50046,
/* 1057 */ 50299,
/* 1058 */ -1043,
/* 1059 */ 3,
/* 1060 */ 1065,
/* 1061 */ 50296,
/* 1062 */ 50299,
/* 1063 */ -1043,
/* 1064 */ 4,
/* 1065 */ 1069,
/* 1066 */ 50294,
/* 1067 */ -1043,
/* 1068 */ 5,
/* 1069 */ 0,
/* 1070 */ 50295,
/* 1071 */ -1043,
/* 1072 */ 6,
/* 1073 */ 1077,
/* 1074 */ 1,
/* 1075 */ -1073,
/* 1076 */ 1,
/* 1077 */ 0,
/* 1078 */ -1073,
/* 1079 */ 2,
/* 1080 */ 1084,
/* 1081 */ 50299,
/* 1082 */ -1080,
/* 1083 */ 1,
/* 1084 */ 1088,
/* 1085 */ 1,
/* 1086 */ -1080,
/* 1087 */ 2,
/* 1088 */ 1092,
/* 1089 */ 50289,
/* 1090 */ -1080,
/* 1091 */ 3,
/* 1092 */ 0,
/* 1093 */ 50040,
/* 1094 */ 1,
/* 1095 */ 50041,
/* 1096 */ -1080,
/* 1097 */ 4,
/* 1098 */ 0,
/* 1099 */ 1,
/* 1100 */ 1,
/* 1101 */ -1098,
/* 1102 */ 1,
/* 1103 */ 1108,
/* 1104 */ 1,
/* 1105 */ 50044,
/* 1106 */ -1103,
/* 1107 */ 1,
/* 1108 */ 0,
/* 1109 */ -1103,
/* 1110 */ 2,
/* 1111 */ 1115,
/* 1112 */ 50308,
/* 1113 */ -1111,
/* 1114 */ 1,
/* 1115 */ 1119,
/* 1116 */ 50306,
/* 1117 */ -1111,
/* 1118 */ 2,
/* 1119 */ 1123,
/* 1120 */ 50307,
/* 1121 */ -1111,
/* 1122 */ 3,
/* 1123 */ 0,
/* 1124 */ 50299,
/* 1125 */ -1111,
/* 1126 */ 4,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 15002,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 15002,
/* 6 */ 9999,
/* 7 */ 15004,
/* 8 */ 9999,
/* 9 */ 15023,
/* 10 */ 9999,
/* 11 */ 16004,
/* 12 */ 16021,
/* 13 */ 9999,
/* 14 */ 16019,
/* 15 */ 9999,
/* 16 */ 20004,
/* 17 */ 9999,
/* 18 */ 20022,
/* 19 */ 9999,
/* 20 */ 21004,
/* 21 */ 9999,
/* 22 */ 21014,
/* 23 */ 9999,
/* 24 */ 25004,
/* 25 */ 25032,
/* 26 */ 25043,
/* 27 */ 25065,
/* 28 */ 9999,
/* 29 */ 25004,
/* 30 */ 9999,
/* 31 */ 25006,
/* 32 */ 9999,
/* 33 */ 25027,
/* 34 */ 9999,
/* 35 */ 9999,
/* 36 */ 25027,
/* 37 */ 9999,
/* 38 */ 25045,
/* 39 */ 9999,
/* 40 */ 25060,
/* 41 */ 9999,
/* 42 */ 9999,
/* 43 */ 25060,
/* 44 */ 9999,
/* 45 */ 29004,
/* 46 */ 29027,
/* 47 */ 9999,
/* 48 */ 9999,
/* 49 */ 29025,
/* 50 */ 9999,
/* 51 */ 29029,
/* 52 */ 9999,
/* 53 */ 29048,
/* 54 */ 9999,
/* 55 */ 9999,
/* 56 */ 29048,
/* 57 */ 9999,
/* 58 */ 33004,
/* 59 */ 33026,
/* 60 */ 9999,
/* 61 */ 33004,
/* 62 */ 9999,
/* 63 */ 33006,
/* 64 */ 9999,
/* 65 */ 33021,
/* 66 */ 9999,
/* 67 */ 9999,
/* 68 */ 33021,
/* 69 */ 9999,
/* 70 */ 37004,
/* 71 */ 37066,
/* 72 */ 9999,
/* 73 */ 37004,
/* 74 */ 9999,
/* 75 */ 37006,
/* 76 */ 9999,
/* 77 */ 37028,
/* 78 */ 9999,
/* 79 */ 37032,
/* 80 */ 9999,
/* 81 */ 37045,
/* 82 */ 9999,
/* 83 */ 37049,
/* 84 */ 9999,
/* 85 */ 37062,
/* 86 */ 9999,
/* 87 */ 37068,
/* 88 */ 9999,
/* 89 */ 37089,
/* 90 */ 9999,
/* 91 */ 9999,
/* 92 */ 37089,
/* 93 */ 9999,
/* 94 */ 9999,
/* 95 */ 9999,
/* 96 */ 41007,
/* 97 */ 9999,
/* 98 */ 9999,
/* 99 */ 9999,
/* 100 */ 41018,
/* 101 */ 9999,
/* 102 */ 9999,
/* 103 */ 9999,
/* 104 */ 41027,
/* 105 */ 9999,
/* 106 */ 9999,
/* 107 */ 9999,
/* 108 */ 41036,
/* 109 */ 9999,
/* 110 */ 9999,
/* 111 */ 9999,
/* 112 */ 41046,
/* 113 */ 9999,
/* 114 */ 9999,
/* 115 */ 9999,
/* 116 */ 45007,
/* 117 */ 9999,
/* 118 */ 9999,
/* 119 */ 9999,
/* 120 */ 45014,
/* 121 */ 9999,
/* 122 */ 9999,
/* 123 */ 9999,
/* 124 */ 45022,
/* 125 */ 9999,
/* 126 */ 9999,
/* 127 */ 9999,
/* 128 */ 45028,
/* 129 */ 9999,
/* 130 */ 9999,
/* 131 */ 9999,
/* 132 */ 45035,
/* 133 */ 9999,
/* 134 */ 9999,
/* 135 */ 9999,
/* 136 */ 45043,
/* 137 */ 9999,
/* 138 */ 9999,
/* 139 */ 9999,
/* 140 */ 45052,
/* 141 */ 9999,
/* 142 */ 9999,
/* 143 */ 9999,
/* 144 */ 45061,
/* 145 */ 9999,
/* 146 */ 9999,
/* 147 */ 9999,
/* 148 */ 45072,
/* 149 */ 9999,
/* 150 */ 46004,
/* 151 */ 9999,
/* 152 */ 46028,
/* 153 */ 9999,
/* 154 */ 46032,
/* 155 */ 9999,
/* 156 */ 46045,
/* 157 */ 9999,
/* 158 */ 46049,
/* 159 */ 9999,
/* 160 */ 46060,
/* 161 */ 9999,
/* 162 */ 9999,
/* 163 */ 9999,
/* 164 */ 50008,
/* 165 */ 9999,
/* 166 */ 9999,
/* 167 */ 9999,
/* 168 */ 50019,
/* 169 */ 9999,
/* 170 */ 54004,
/* 171 */ 54020,
/* 172 */ 9999,
/* 173 */ 54040,
/* 174 */ 9999,
/* 175 */ 9999,
/* 176 */ 54018,
/* 177 */ 9999,
/* 178 */ 55004,
/* 179 */ 9999,
/* 180 */ 9999,
/* 181 */ 55018,
/* 182 */ 9999,
/* 183 */ 9999,
/* 184 */ 9999,
/* 185 */ 54031,
/* 186 */ 9999,
/* 187 */ 9999,
/* 188 */ 54031,
/* 189 */ 9999,
/* 190 */ 9999,
/* 191 */ 9999,
/* 192 */ 59009,
/* 193 */ 9999,
/* 194 */ 9999,
/* 195 */ 9999,
/* 196 */ 59017,
/* 197 */ 9999,
/* 198 */ 63004,
/* 199 */ 63033,
/* 200 */ 9999,
/* 201 */ 63004,
/* 202 */ 9999,
/* 203 */ 63006,
/* 204 */ 9999,
/* 205 */ 63028,
/* 206 */ 9999,
/* 207 */ 9999,
/* 208 */ 63028,
/* 209 */ 9999,
/* 210 */ 67004,
/* 211 */ 67034,
/* 212 */ 9999,
/* 213 */ 67004,
/* 214 */ 9999,
/* 215 */ 67006,
/* 216 */ 9999,
/* 217 */ 9999,
/* 218 */ 67025,
/* 219 */ 9999,
/* 220 */ 9999,
/* 221 */ 67025,
/* 222 */ 9999,
/* 223 */ 71004,
/* 224 */ 71024,
/* 225 */ 9999,
/* 226 */ 71004,
/* 227 */ 9999,
/* 228 */ 71006,
/* 229 */ 9999,
/* 230 */ 9999,
/* 231 */ 71015,
/* 232 */ 9999,
/* 233 */ 9999,
/* 234 */ 71015,
/* 235 */ 9999,
/* 236 */ 75004,
/* 237 */ 75029,
/* 238 */ 9999,
/* 239 */ 9999,
/* 240 */ 75027,
/* 241 */ 9999,
/* 242 */ 79004,
/* 243 */ 79040,
/* 244 */ 9999,
/* 245 */ 79004,
/* 246 */ 9999,
/* 247 */ 79006,
/* 248 */ 9999,
/* 249 */ 79019,
/* 250 */ 9999,
/* 251 */ 79023,
/* 252 */ 9999,
/* 253 */ 79036,
/* 254 */ 9999,
/* 255 */ 79042,
/* 256 */ 9999,
/* 257 */ 79065,
/* 258 */ 9999,
/* 259 */ 9999,
/* 260 */ 79065,
/* 261 */ 9999,
/* 262 */ 83004,
/* 263 */ 9999,
/* 264 */ 83020,
/* 265 */ 9999,
/* 266 */ 84004,
/* 267 */ 9999,
/* 268 */ 84031,
/* 269 */ 9999,
/* 270 */ 84025,
/* 271 */ 9999,
/* 272 */ 88004,
/* 273 */ 9999,
/* 274 */ 88013,
/* 275 */ 9999,
/* 276 */ 89004,
/* 277 */ 9999,
/* 278 */ 89024,
/* 279 */ 9999,
/* 280 */ 89004,
/* 281 */ 9999,
/* 282 */ 89006,
/* 283 */ 9999,
/* 284 */ 89015,
/* 285 */ 9999,
/* 286 */ 9999,
/* 287 */ 89015,
/* 288 */ 9999,
/* 289 */ 9999,
/* 290 */ 93009,
/* 291 */ 9999,
/* 292 */ 93029,
/* 293 */ 9999,
/* 294 */ 9999,
/* 295 */ 93007,
/* 296 */ 9999,
/* 297 */ 9999,
/* 298 */ 9999,
/* 299 */ 9999,
/* 300 */ 94007,
/* 301 */ 9999,
/* 302 */ 9999,
/* 303 */ 9999,
/* 304 */ 93020,
/* 305 */ 9999,
/* 306 */ 9999,
/* 307 */ 93020,
/* 308 */ 9999,
/* 309 */ 98004,
/* 310 */ 98029,
/* 311 */ 9999,
/* 312 */ 98004,
/* 313 */ 9999,
/* 314 */ 98006,
/* 315 */ 9999,
/* 316 */ 9999,
/* 317 */ 98020,
/* 318 */ 9999,
/* 319 */ 9999,
/* 320 */ 98020,
/* 321 */ 9999,
/* 322 */ 9999,
/* 323 */ 102015,
/* 324 */ 9999,
/* 325 */ 102013,
/* 326 */ 9999,
/* 327 */ 9999,
/* 328 */ 102021,
/* 329 */ 9999,
/* 330 */ 102017,
/* 331 */ 9999,
/* 332 */ 106004,
/* 333 */ 106017,
/* 334 */ 9999,
/* 335 */ 106004,
/* 336 */ 9999,
/* 337 */ 106006,
/* 338 */ 9999,
/* 339 */ 106012,
/* 340 */ 9999,
/* 341 */ 9999,
/* 342 */ 106012,
/* 343 */ 9999,
/* 344 */ 9999,
/* 345 */ 9999,
/* 346 */ 110013,
/* 347 */ 9999,
/* 348 */ 9999,
/* 349 */ 111008,
/* 350 */ 9999,
/* 351 */ 9999,
/* 352 */ 111004,
/* 353 */ 9999,
/* 354 */ 112004,
/* 355 */ 112022,
/* 356 */ 9999,
/* 357 */ 112020,
/* 358 */ 9999,
/* 359 */ 9999,
/* 360 */ 112028,
/* 361 */ 9999,
/* 362 */ 9999,
/* 363 */ 112024,
/* 364 */ 9999,
/* 365 */ 9999,
/* 366 */ 112063,
/* 367 */ 9999,
/* 368 */ 9999,
/* 369 */ 112059,
/* 370 */ 9999,
/* 371 */ 9999,
/* 372 */ 112093,
/* 373 */ 9999,
/* 374 */ 9999,
/* 375 */ 112089,
/* 376 */ 9999,
/* 377 */ 112030,
/* 378 */ 9999,
/* 379 */ 112048,
/* 380 */ 9999,
/* 381 */ 9999,
/* 382 */ 112048,
/* 383 */ 9999,
/* 384 */ 112095,
/* 385 */ 9999,
/* 386 */ 112109,
/* 387 */ 9999,
/* 388 */ 9999,
/* 389 */ 112109,
/* 390 */ 9999,
/* 391 */ 9999,
/* 392 */ 116008,
/* 393 */ 116033,
/* 394 */ 9999,
/* 395 */ 116004,
/* 396 */ 9999,
/* 397 */ 116010,
/* 398 */ 9999,
/* 399 */ 116028,
/* 400 */ 9999,
/* 401 */ 9999,
/* 402 */ 116028,
/* 403 */ 9999,
/* 404 */ 116035,
/* 405 */ 9999,
/* 406 */ 116041,
/* 407 */ 9999,
/* 408 */ 9999,
/* 409 */ 116041,
/* 410 */ 9999,
/* 411 */ 120004,
/* 412 */ 120029,
/* 413 */ 9999,
/* 414 */ 120004,
/* 415 */ 9999,
/* 416 */ 120006,
/* 417 */ 9999,
/* 418 */ 120024,
/* 419 */ 9999,
/* 420 */ 9999,
/* 421 */ 120024,
/* 422 */ 9999,
/* 423 */ 124004,
/* 424 */ 124019,
/* 425 */ 9999,
/* 426 */ 124017,
/* 427 */ 9999,
/* 428 */ 9999,
/* 429 */ 9999,
/* 430 */ 9999,
/* 431 */ 124021,
/* 432 */ 9999,
/* 433 */ 128004,
/* 434 */ 128028,
/* 435 */ 9999,
/* 436 */ 128004,
/* 437 */ 9999,
/* 438 */ 128006,
/* 439 */ 9999,
/* 440 */ 9999,
/* 441 */ 128019,
/* 442 */ 9999,
/* 443 */ 9999,
/* 444 */ 128019,
/* 445 */ 9999,
/* 446 */ 132004,
/* 447 */ 132027,
/* 448 */ 9999,
/* 449 */ 132025,
/* 450 */ 9999,
/* 451 */ 132029,
/* 452 */ 9999,
/* 453 */ 132038,
/* 454 */ 9999,
/* 455 */ 132042,
/* 456 */ 9999,
/* 457 */ 132042,
/* 458 */ 9999,
/* 459 */ 132044,
/* 460 */ 9999,
/* 461 */ 132062,
/* 462 */ 9999,
/* 463 */ 9999,
/* 464 */ 132062,
/* 465 */ 9999,
/* 466 */ 136004,
/* 467 */ 9999,
/* 468 */ 9999,
/* 469 */ 136004,
/* 470 */ 9999,
/* 471 */ 136006,
/* 472 */ 9999,
/* 473 */ 9999,
/* 474 */ 136020,
/* 475 */ 9999,
/* 476 */ 9999,
/* 477 */ 136020,
/* 478 */ 9999,
/* 479 */ 140004,
/* 480 */ 9999,
/* 481 */ 140024,
/* 482 */ 9999,
/* 483 */ 9999,
/* 484 */ 141008,
/* 485 */ 141025,
/* 486 */ 9999,
/* 487 */ 9999,
/* 488 */ 141004,
/* 489 */ 9999,
/* 490 */ 9999,
/* 491 */ 9999,
/* 492 */ 141027,
/* 493 */ 9999,
/* 494 */ 9999,
/* 495 */ 141027,
/* 496 */ 9999,
/* 497 */ 145004,
/* 498 */ 145030,
/* 499 */ 9999,
/* 500 */ 145004,
/* 501 */ 9999,
/* 502 */ 145006,
/* 503 */ 9999,
/* 504 */ 9999,
/* 505 */ 145021,
/* 506 */ 9999,
/* 507 */ 9999,
/* 508 */ 145021,
/* 509 */ 9999,
/* 510 */ 149004,
/* 511 */ 149029,
/* 512 */ 9999,
/* 513 */ 149027,
/* 514 */ 9999,
/* 515 */ 149031,
/* 516 */ 9999,
/* 517 */ 149049,
/* 518 */ 9999,
/* 519 */ 9999,
/* 520 */ 149049,
/* 521 */ 9999,
/* 522 */ 153004,
/* 523 */ 9999,
/* 524 */ 153010,
/* 525 */ 9999,
/* 526 */ 154004,
/* 527 */ 154017,
/* 528 */ 9999,
/* 529 */ 154004,
/* 530 */ 9999,
/* 531 */ 154006,
/* 532 */ 9999,
/* 533 */ 154012,
/* 534 */ 9999,
/* 535 */ 9999,
/* 536 */ 154012,
/* 537 */ 9999,
/* 538 */ 9999,
/* 539 */ 158008,
/* 540 */ 9999,
/* 541 */ 9999,
/* 542 */ 158004,
/* 543 */ 9999,
/* 544 */ 159004,
/* 545 */ 159036,
/* 546 */ 9999,
/* 547 */ 159004,
/* 548 */ 9999,
/* 549 */ 159006,
/* 550 */ 9999,
/* 551 */ 159031,
/* 552 */ 9999,
/* 553 */ 9999,
/* 554 */ 159031,
/* 555 */ 9999,
/* 556 */ 9999,
/* 557 */ 159042,
/* 558 */ 9999,
/* 559 */ 9999,
/* 560 */ 159038,
/* 561 */ 9999,
/* 562 */ 9999,
/* 563 */ 159077,
/* 564 */ 9999,
/* 565 */ 9999,
/* 566 */ 159073,
/* 567 */ 9999,
/* 568 */ 159044,
/* 569 */ 9999,
/* 570 */ 159062,
/* 571 */ 9999,
/* 572 */ 9999,
/* 573 */ 159062,
/* 574 */ 9999,
/* 575 */ 159079,
/* 576 */ 9999,
/* 577 */ 159097,
/* 578 */ 9999,
/* 579 */ 9999,
/* 580 */ 159097,
/* 581 */ 9999,
/* 582 */ 9999,
/* 583 */ 9999,
/* 584 */ 163013,
/* 585 */ 9999,
/* 586 */ 167004,
/* 587 */ 9999,
/* 588 */ 167020,
/* 589 */ 9999,
/* 590 */ 168004,
/* 591 */ 9999,
/* 592 */ 168023,
/* 593 */ 9999,
/* 594 */ 169004,
/* 595 */ 9999,
/* 596 */ 169021,
/* 597 */ 9999,
/* 598 */ 170004,
/* 599 */ 9999,
/* 600 */ 170022,
/* 601 */ 9999,
/* 602 */ 171004,
/* 603 */ 9999,
/* 604 */ 171022,
/* 605 */ 9999,
/* 606 */ 172004,
/* 607 */ 9999,
/* 608 */ 172017,
/* 609 */ 9999,
/* 610 */ 9999,
/* 611 */ 9999,
/* 612 */ 176019,
/* 613 */ 9999,
/* 614 */ 176013,
/* 615 */ 9999,
/* 616 */ 9999,
/* 617 */ 177009,
/* 618 */ 9999,
/* 619 */ 177033,
/* 620 */ 9999,
/* 621 */ 177007,
/* 622 */ 9999,
/* 623 */ 9999,
/* 624 */ 9999,
/* 625 */ 178016,
/* 626 */ 9999,
/* 627 */ 178010,
/* 628 */ 9999,
/* 629 */ 182004,
/* 630 */ 9999,
/* 631 */ 9999,
/* 632 */ 182004,
/* 633 */ 9999,
/* 634 */ 182006,
/* 635 */ 9999,
/* 636 */ 182015,
/* 637 */ 9999,
/* 638 */ 9999,
/* 639 */ 182015,
/* 640 */ 9999,
/* 641 */ 9999,
/* 642 */ 186008,
/* 643 */ 186030,
/* 644 */ 9999,
/* 645 */ 9999,
/* 646 */ 186004,
/* 647 */ 9999,
/* 648 */ 186010,
/* 649 */ 9999,
/* 650 */ 186025,
/* 651 */ 9999,
/* 652 */ 9999,
/* 653 */ 186025,
/* 654 */ 9999,
/* 655 */ 186032,
/* 656 */ 9999,
/* 657 */ 186045,
/* 658 */ 9999,
/* 659 */ 9999,
/* 660 */ 186045,
/* 661 */ 9999,
/* 662 */ 190004,
/* 663 */ 190024,
/* 664 */ 9999,
/* 665 */ 190004,
/* 666 */ 9999,
/* 667 */ 190006,
/* 668 */ 9999,
/* 669 */ 190019,
/* 670 */ 9999,
/* 671 */ 9999,
/* 672 */ 190019,
/* 673 */ 9999,
/* 674 */ 9999,
/* 675 */ 9999,
/* 676 */ 194011,
/* 677 */ 9999,
/* 678 */ 194026,
/* 679 */ 194036,
/* 680 */ 9999,
/* 681 */ 194005,
/* 682 */ 9999,
/* 683 */ 9999,
/* 684 */ 9999,
/* 685 */ 195015,
/* 686 */ 9999,
/* 687 */ 195030,
/* 688 */ 9999,
/* 689 */ 195009,
/* 690 */ 9999,
/* 691 */ 9999,
/* 692 */ 194043,
/* 693 */ 9999,
/* 694 */ 194041,
/* 695 */ 9999,
/* 696 */ 9999,
/* 697 */ 194041,
/* 698 */ 9999,
/* 699 */ 9999,
/* 700 */ 9999,
/* 701 */ 199014,
/* 702 */ 9999,
/* 703 */ 199029,
/* 704 */ 9999,
/* 705 */ 199008,
/* 706 */ 9999,
/* 707 */ 9999,
/* 708 */ 200007,
/* 709 */ 9999,
/* 710 */ 9999,
/* 711 */ 200027,
/* 712 */ 9999,
/* 713 */ 9999,
/* 714 */ 9999,
/* 715 */ 200005,
/* 716 */ 9999,
/* 717 */ 9999,
/* 718 */ 9999,
/* 719 */ 201012,
/* 720 */ 9999,
/* 721 */ 201032,
/* 722 */ 9999,
/* 723 */ 201052,
/* 724 */ 9999,
/* 725 */ 201072,
/* 726 */ 9999,
/* 727 */ 201006,
/* 728 */ 9999,
/* 729 */ 201014,
/* 730 */ 9999,
/* 731 */ 201023,
/* 732 */ 9999,
/* 733 */ 9999,
/* 734 */ 201023,
/* 735 */ 9999,
/* 736 */ 201034,
/* 737 */ 9999,
/* 738 */ 201043,
/* 739 */ 9999,
/* 740 */ 9999,
/* 741 */ 201043,
/* 742 */ 9999,
/* 743 */ 201054,
/* 744 */ 9999,
/* 745 */ 201063,
/* 746 */ 9999,
/* 747 */ 9999,
/* 748 */ 201063,
/* 749 */ 9999,
/* 750 */ 9999,
/* 751 */ 9999,
/* 752 */ 9999,
/* 753 */ 9999,
/* 754 */ 205007,
/* 755 */ 9999,
/* 756 */ 9999,
/* 757 */ 9999,
/* 758 */ 9999,
/* 759 */ 206011,
/* 760 */ 9999,
/* 761 */ 9999,
/* 762 */ 9999,
/* 763 */ 9999,
/* 764 */ 207008,
/* 765 */ 9999,
/* 766 */ 9999,
/* 767 */ 208011,
/* 768 */ 9999,
/* 769 */ 9999,
/* 770 */ 208009,
/* 771 */ 9999,
/* 772 */ 208013,
/* 773 */ 9999,
/* 774 */ 208022,
/* 775 */ 9999,
/* 776 */ 9999,
/* 777 */ 208022,
/* 778 */ 9999,
/* 779 */ 212004,
/* 780 */ 212024,
/* 781 */ 9999,
/* 782 */ 212004,
/* 783 */ 9999,
/* 784 */ 212006,
/* 785 */ 9999,
/* 786 */ 9999,
/* 787 */ 212015,
/* 788 */ 9999,
/* 789 */ 9999,
/* 790 */ 212015,
/* 791 */ 9999,
/* 792 */ 216004,
/* 793 */ 9999,
/* 794 */ 216025,
/* 795 */ 9999,
/* 796 */ 217004,
/* 797 */ 217021,
/* 798 */ 217041,
/* 799 */ 9999,
/* 800 */ 217019,
/* 801 */ 9999,
/* 802 */ 9999,
/* 803 */ 9999,
/* 804 */ 221009,
/* 805 */ 9999,
/* 806 */ 9999,
/* 807 */ 9999,
/* 808 */ 222004,
/* 809 */ 9999,
/* 810 */ 226004,
/* 811 */ 226026,
/* 812 */ 9999,
/* 813 */ 226024,
/* 814 */ 9999,
/* 815 */ 9999,
/* 816 */ 226032,
/* 817 */ 9999,
/* 818 */ 226047,
/* 819 */ 9999,
/* 820 */ 226028,
/* 821 */ 9999,
/* 822 */ 9999,
/* 823 */ 226028,
/* 824 */ 9999,
/* 825 */ 230004,
/* 826 */ 9999,
/* 827 */ 230025,
/* 828 */ 9999,
/* 829 */ 234004,
/* 830 */ 234042,
/* 831 */ 9999,
/* 832 */ 234004,
/* 833 */ 9999,
/* 834 */ 234006,
/* 835 */ 9999,
/* 836 */ 9999,
/* 837 */ 234026,
/* 838 */ 9999,
/* 839 */ 9999,
/* 840 */ 234026,
/* 841 */ 9999,
/* 842 */ 238004,
/* 843 */ 238044,
/* 844 */ 9999,
/* 845 */ 238004,
/* 846 */ 9999,
/* 847 */ 238006,
/* 848 */ 9999,
/* 849 */ 9999,
/* 850 */ 238027,
/* 851 */ 9999,
/* 852 */ 9999,
/* 853 */ 238027,
/* 854 */ 9999,
/* 855 */ 242004,
/* 856 */ 242040,
/* 857 */ 9999,
/* 858 */ 242004,
/* 859 */ 9999,
/* 860 */ 242006,
/* 861 */ 9999,
/* 862 */ 9999,
/* 863 */ 242028,
/* 864 */ 9999,
/* 865 */ 9999,
/* 866 */ 242028,
/* 867 */ 9999,
/* 868 */ 246004,
/* 869 */ 246041,
/* 870 */ 9999,
/* 871 */ 246004,
/* 872 */ 9999,
/* 873 */ 246006,
/* 874 */ 9999,
/* 875 */ 9999,
/* 876 */ 246028,
/* 877 */ 9999,
/* 878 */ 9999,
/* 879 */ 246028,
/* 880 */ 9999,
/* 881 */ 250004,
/* 882 */ 250031,
/* 883 */ 9999,
/* 884 */ 250004,
/* 885 */ 9999,
/* 886 */ 250005,
/* 887 */ 9999,
/* 888 */ 9999,
/* 889 */ 250018,
/* 890 */ 9999,
/* 891 */ 9999,
/* 892 */ 250018,
/* 893 */ 9999,
/* 894 */ 254004,
/* 895 */ 254037,
/* 896 */ 9999,
/* 897 */ 254004,
/* 898 */ 9999,
/* 899 */ 254006,
/* 900 */ 9999,
/* 901 */ 9999,
/* 902 */ 254024,
/* 903 */ 9999,
/* 904 */ 9999,
/* 905 */ 254024,
/* 906 */ 9999,
/* 907 */ 258004,
/* 908 */ 258031,
/* 909 */ 9999,
/* 910 */ 258004,
/* 911 */ 9999,
/* 912 */ 258005,
/* 913 */ 9999,
/* 914 */ 9999,
/* 915 */ 258020,
/* 916 */ 9999,
/* 917 */ 9999,
/* 918 */ 258020,
/* 919 */ 9999,
/* 920 */ 262004,
/* 921 */ 262043,
/* 922 */ 9999,
/* 923 */ 262004,
/* 924 */ 9999,
/* 925 */ 262006,
/* 926 */ 262026,
/* 927 */ 9999,
/* 928 */ 262024,
/* 929 */ 9999,
/* 930 */ 9999,
/* 931 */ 262024,
/* 932 */ 9999,
/* 933 */ 9999,
/* 934 */ 9999,
/* 935 */ 262028,
/* 936 */ 9999,
/* 937 */ 9999,
/* 938 */ 9999,
/* 939 */ 262034,
/* 940 */ 9999,
/* 941 */ 266004,
/* 942 */ 266055,
/* 943 */ 9999,
/* 944 */ 266004,
/* 945 */ 9999,
/* 946 */ 266006,
/* 947 */ 266032,
/* 948 */ 9999,
/* 949 */ 266030,
/* 950 */ 9999,
/* 951 */ 9999,
/* 952 */ 266030,
/* 953 */ 9999,
/* 954 */ 9999,
/* 955 */ 9999,
/* 956 */ 266034,
/* 957 */ 9999,
/* 958 */ 9999,
/* 959 */ 9999,
/* 960 */ 266040,
/* 961 */ 9999,
/* 962 */ 9999,
/* 963 */ 9999,
/* 964 */ 266046,
/* 965 */ 9999,
/* 966 */ 270004,
/* 967 */ 9999,
/* 968 */ 270019,
/* 969 */ 9999,
/* 970 */ 9999,
/* 971 */ 271008,
/* 972 */ 9999,
/* 973 */ 271022,
/* 974 */ 9999,
/* 975 */ 271004,
/* 976 */ 9999,
/* 977 */ 275004,
/* 978 */ 9999,
/* 979 */ 275021,
/* 980 */ 9999,
/* 981 */ 276004,
/* 982 */ 276024,
/* 983 */ 9999,
/* 984 */ 276004,
/* 985 */ 9999,
/* 986 */ 277004,
/* 987 */ 277019,
/* 988 */ 9999,
/* 989 */ 277017,
/* 990 */ 9999,
/* 991 */ 9999,
/* 992 */ 278011,
/* 993 */ 9999,
/* 994 */ 278009,
/* 995 */ 9999,
/* 996 */ 9999,
/* 997 */ 9999,
/* 998 */ 279015,
/* 999 */ 9999,
/* 1000 */ 9999,
/* 1001 */ 279009,
/* 1002 */ 9999,
/* 1003 */ 9999,
/* 1004 */ 9999,
/* 1005 */ 276011,
/* 1006 */ 9999,
/* 1007 */ 9999,
/* 1008 */ 9999,
/* 1009 */ 276020,
/* 1010 */ 9999,
/* 1011 */ 9999,
/* 1012 */ 9999,
/* 1013 */ 283004,
/* 1014 */ 9999,
/* 1015 */ 9999,
/* 1016 */ 9999,
/* 1017 */ 283010,
/* 1018 */ 9999,
/* 1019 */ 9999,
/* 1020 */ 9999,
/* 1021 */ 283016,
/* 1022 */ 9999,
/* 1023 */ 9999,
/* 1024 */ 9999,
/* 1025 */ 283022,
/* 1026 */ 9999,
/* 1027 */ 9999,
/* 1028 */ 9999,
/* 1029 */ 283028,
/* 1030 */ 9999,
/* 1031 */ 9999,
/* 1032 */ 9999,
/* 1033 */ 283034,
/* 1034 */ 9999,
/* 1035 */ 287004,
/* 1036 */ 9999,
/* 1037 */ 287021,
/* 1038 */ 9999,
/* 1039 */ 288004,
/* 1040 */ 288023,
/* 1041 */ 9999,
/* 1042 */ 288021,
/* 1043 */ 9999,
/* 1044 */ 9999,
/* 1045 */ 288029,
/* 1046 */ 9999,
/* 1047 */ 9999,
/* 1048 */ 288025,
/* 1049 */ 9999,
/* 1050 */ 9999,
/* 1051 */ 288050,
/* 1052 */ 9999,
/* 1053 */ 9999,
/* 1054 */ 288046,
/* 1055 */ 9999,
/* 1056 */ 9999,
/* 1057 */ 9999,
/* 1058 */ 9999,
/* 1059 */ 288086,
/* 1060 */ 9999,
/* 1061 */ 9999,
/* 1062 */ 9999,
/* 1063 */ 9999,
/* 1064 */ 288108,
/* 1065 */ 9999,
/* 1066 */ 9999,
/* 1067 */ 9999,
/* 1068 */ 288128,
/* 1069 */ 9999,
/* 1070 */ 9999,
/* 1071 */ 9999,
/* 1072 */ 288137,
/* 1073 */ 9999,
/* 1074 */ 288052,
/* 1075 */ 9999,
/* 1076 */ 288075,
/* 1077 */ 9999,
/* 1078 */ 9999,
/* 1079 */ 288075,
/* 1080 */ 9999,
/* 1081 */ 9999,
/* 1082 */ 9999,
/* 1083 */ 292013,
/* 1084 */ 9999,
/* 1085 */ 293004,
/* 1086 */ 9999,
/* 1087 */ 293011,
/* 1088 */ 9999,
/* 1089 */ 9999,
/* 1090 */ 9999,
/* 1091 */ 294009,
/* 1092 */ 9999,
/* 1093 */ 9999,
/* 1094 */ 295008,
/* 1095 */ 9999,
/* 1096 */ 9999,
/* 1097 */ 295004,
/* 1098 */ 9999,
/* 1099 */ 299004,
/* 1100 */ 299038,
/* 1101 */ 9999,
/* 1102 */ 299004,
/* 1103 */ 9999,
/* 1104 */ 299006,
/* 1105 */ 9999,
/* 1106 */ 9999,
/* 1107 */ 299029,
/* 1108 */ 9999,
/* 1109 */ 9999,
/* 1110 */ 299029,
/* 1111 */ 9999,
/* 1112 */ 9999,
/* 1113 */ 9999,
/* 1114 */ 303011,
/* 1115 */ 9999,
/* 1116 */ 9999,
/* 1117 */ 9999,
/* 1118 */ 303023,
/* 1119 */ 9999,
/* 1120 */ 9999,
/* 1121 */ 9999,
/* 1122 */ 303036,
/* 1123 */ 9999,
/* 1124 */ 9999,
/* 1125 */ 9999,
/* 1126 */ 303049,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[1128];
*/
int TABLE[255][309];
init_dirsets() {
TABLE[125][0] = 1;
TABLE[125][123] = 1;
TABLE[125][299] = 1;
TABLE[125][40] = 1;
TABLE[125][282] = 1;
TABLE[125][267] = 1;
TABLE[125][279] = 1;
TABLE[125][274] = 1;
TABLE[125][256] = 1;
TABLE[125][284] = 1;
TABLE[125][277] = 1;
TABLE[125][264] = 1;
TABLE[125][268] = 1;
TABLE[125][273] = 1;
TABLE[125][272] = 1;
TABLE[125][276] = 1;
TABLE[125][259] = 1;
TABLE[125][285] = 1;
TABLE[125][286] = 1;
TABLE[125][260] = 1;
TABLE[125][42] = 1;
TABLE[125][266] = 1;
TABLE[125][283] = 1;
TABLE[125][280] = 1;
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
TABLE[4][299] = 1;
TABLE[4][266] = 1;
TABLE[4][283] = 1;
TABLE[4][280] = 1;
TABLE[5][123] = 1;
TABLE[5][40] = 1;
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
TABLE[5][299] = 1;
TABLE[5][266] = 1;
TABLE[5][283] = 1;
TABLE[5][280] = 1;
TABLE[126][260] = 1;
TABLE[126][286] = 1;
TABLE[126][285] = 1;
TABLE[126][259] = 1;
TABLE[126][276] = 1;
TABLE[126][272] = 1;
TABLE[126][273] = 1;
TABLE[126][268] = 1;
TABLE[126][264] = 1;
TABLE[126][277] = 1;
TABLE[126][284] = 1;
TABLE[126][256] = 1;
TABLE[126][274] = 1;
TABLE[126][279] = 1;
TABLE[126][267] = 1;
TABLE[126][282] = 1;
TABLE[126][266] = 1;
TABLE[126][299] = 1;
TABLE[126][280] = 1;
TABLE[126][283] = 1;
TABLE[204][40] = 1;
TABLE[204][42] = 1;
TABLE[204][282] = 1;
TABLE[204][267] = 1;
TABLE[204][279] = 1;
TABLE[204][274] = 1;
TABLE[204][256] = 1;
TABLE[204][284] = 1;
TABLE[204][277] = 1;
TABLE[204][264] = 1;
TABLE[204][268] = 1;
TABLE[204][273] = 1;
TABLE[204][272] = 1;
TABLE[204][276] = 1;
TABLE[204][259] = 1;
TABLE[204][285] = 1;
TABLE[204][286] = 1;
TABLE[204][260] = 1;
TABLE[204][299] = 1;
TABLE[204][266] = 1;
TABLE[204][283] = 1;
TABLE[204][280] = 1;
TABLE[204][123] = 1;
TABLE[127][123] = 1;
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
TABLE[127][299] = 1;
TABLE[127][280] = 1;
TABLE[127][283] = 1;
TABLE[205][123] = 1;
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
TABLE[6][299] = 1;
TABLE[6][280] = 1;
TABLE[6][283] = 1;
TABLE[128][59] = 1;
TABLE[128][44] = 1;
TABLE[128][123] = 1;
TABLE[128][61] = 1;
TABLE[128][278] = 1;
TABLE[128][299] = 1;
TABLE[128][40] = 1;
TABLE[128][295] = 1;
TABLE[128][294] = 1;
TABLE[128][33] = 1;
TABLE[128][126] = 1;
TABLE[128][45] = 1;
TABLE[128][43] = 1;
TABLE[128][38] = 1;
TABLE[128][63] = 1;
TABLE[128][42] = 1;
TABLE[128][289] = 1;
TABLE[128][297] = 1;
TABLE[128][307] = 1;
TABLE[128][306] = 1;
TABLE[128][308] = 1;
TABLE[128][298] = 1;
TABLE[128][301] = 1;
TABLE[128][303] = 1;
TABLE[128][302] = 1;
TABLE[128][292] = 1;
TABLE[128][304] = 1;
TABLE[128][37] = 1;
TABLE[128][47] = 1;
TABLE[206][59] = 1;
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
TABLE[7][299] = 1;
TABLE[7][266] = 1;
TABLE[7][283] = 1;
TABLE[7][280] = 1;
TABLE[129][260] = 1;
TABLE[129][286] = 1;
TABLE[129][285] = 1;
TABLE[129][259] = 1;
TABLE[129][276] = 1;
TABLE[129][272] = 1;
TABLE[129][273] = 1;
TABLE[129][268] = 1;
TABLE[129][264] = 1;
TABLE[129][277] = 1;
TABLE[129][284] = 1;
TABLE[129][256] = 1;
TABLE[129][274] = 1;
TABLE[129][279] = 1;
TABLE[129][267] = 1;
TABLE[129][282] = 1;
TABLE[129][266] = 1;
TABLE[129][299] = 1;
TABLE[129][280] = 1;
TABLE[129][283] = 1;
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
TABLE[207][299] = 1;
TABLE[207][266] = 1;
TABLE[207][283] = 1;
TABLE[207][280] = 1;
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
TABLE[8][299] = 1;
TABLE[8][266] = 1;
TABLE[8][283] = 1;
TABLE[8][280] = 1;
TABLE[130][256] = 1;
TABLE[130][274] = 1;
TABLE[130][279] = 1;
TABLE[130][267] = 1;
TABLE[130][282] = 1;
TABLE[131][285] = 1;
TABLE[131][259] = 1;
TABLE[131][276] = 1;
TABLE[131][272] = 1;
TABLE[131][273] = 1;
TABLE[131][268] = 1;
TABLE[131][264] = 1;
TABLE[131][277] = 1;
TABLE[131][284] = 1;
TABLE[131][266] = 1;
TABLE[131][299] = 1;
TABLE[131][280] = 1;
TABLE[131][283] = 1;
TABLE[132][260] = 1;
TABLE[132][286] = 1;
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
TABLE[133][256] = 1;
TABLE[133][274] = 1;
TABLE[133][279] = 1;
TABLE[133][267] = 1;
TABLE[133][282] = 1;
TABLE[133][266] = 1;
TABLE[133][299] = 1;
TABLE[133][280] = 1;
TABLE[133][283] = 1;
TABLE[208][40] = 1;
TABLE[208][42] = 1;
TABLE[208][282] = 1;
TABLE[208][267] = 1;
TABLE[208][279] = 1;
TABLE[208][274] = 1;
TABLE[208][256] = 1;
TABLE[208][284] = 1;
TABLE[208][277] = 1;
TABLE[208][264] = 1;
TABLE[208][268] = 1;
TABLE[208][273] = 1;
TABLE[208][272] = 1;
TABLE[208][276] = 1;
TABLE[208][259] = 1;
TABLE[208][285] = 1;
TABLE[208][286] = 1;
TABLE[208][260] = 1;
TABLE[208][299] = 1;
TABLE[208][266] = 1;
TABLE[208][283] = 1;
TABLE[208][280] = 1;
TABLE[208][123] = 1;
TABLE[208][44] = 1;
TABLE[208][61] = 1;
TABLE[208][278] = 1;
TABLE[208][63] = 1;
TABLE[208][38] = 1;
TABLE[208][43] = 1;
TABLE[208][45] = 1;
TABLE[208][126] = 1;
TABLE[208][33] = 1;
TABLE[208][294] = 1;
TABLE[208][295] = 1;
TABLE[208][297] = 1;
TABLE[208][289] = 1;
TABLE[208][298] = 1;
TABLE[208][308] = 1;
TABLE[208][306] = 1;
TABLE[208][307] = 1;
TABLE[208][301] = 1;
TABLE[208][303] = 1;
TABLE[208][302] = 1;
TABLE[208][292] = 1;
TABLE[208][304] = 1;
TABLE[208][47] = 1;
TABLE[208][37] = 1;
TABLE[208][59] = 1;
TABLE[208][91] = 1;
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
TABLE[25][299] = 1;
TABLE[26][260] = 1;
TABLE[27][286] = 1;
TABLE[28][280] = 1;
TABLE[28][283] = 1;
TABLE[29][280] = 1;
TABLE[29][283] = 1;
TABLE[134][299] = 1;
TABLE[209][123] = 1;
TABLE[30][280] = 1;
TABLE[31][283] = 1;
TABLE[32][284] = 1;
TABLE[32][277] = 1;
TABLE[32][264] = 1;
TABLE[32][268] = 1;
TABLE[32][273] = 1;
TABLE[32][272] = 1;
TABLE[32][276] = 1;
TABLE[32][259] = 1;
TABLE[32][285] = 1;
TABLE[32][286] = 1;
TABLE[32][260] = 1;
TABLE[32][299] = 1;
TABLE[32][266] = 1;
TABLE[32][283] = 1;
TABLE[32][280] = 1;
TABLE[135][260] = 1;
TABLE[135][286] = 1;
TABLE[135][285] = 1;
TABLE[135][259] = 1;
TABLE[135][276] = 1;
TABLE[135][272] = 1;
TABLE[135][273] = 1;
TABLE[135][268] = 1;
TABLE[135][264] = 1;
TABLE[135][277] = 1;
TABLE[135][284] = 1;
TABLE[135][266] = 1;
TABLE[135][299] = 1;
TABLE[135][280] = 1;
TABLE[135][283] = 1;
TABLE[210][284] = 1;
TABLE[210][277] = 1;
TABLE[210][264] = 1;
TABLE[210][268] = 1;
TABLE[210][273] = 1;
TABLE[210][272] = 1;
TABLE[210][276] = 1;
TABLE[210][259] = 1;
TABLE[210][285] = 1;
TABLE[210][286] = 1;
TABLE[210][260] = 1;
TABLE[210][299] = 1;
TABLE[210][266] = 1;
TABLE[210][283] = 1;
TABLE[210][280] = 1;
TABLE[33][59] = 1;
TABLE[33][44] = 1;
TABLE[33][61] = 1;
TABLE[33][123] = 1;
TABLE[33][40] = 1;
TABLE[33][299] = 1;
TABLE[33][278] = 1;
TABLE[33][42] = 1;
TABLE[33][63] = 1;
TABLE[33][38] = 1;
TABLE[33][43] = 1;
TABLE[33][45] = 1;
TABLE[33][126] = 1;
TABLE[33][33] = 1;
TABLE[33][294] = 1;
TABLE[33][295] = 1;
TABLE[33][297] = 1;
TABLE[33][289] = 1;
TABLE[33][298] = 1;
TABLE[33][308] = 1;
TABLE[33][306] = 1;
TABLE[33][307] = 1;
TABLE[33][301] = 1;
TABLE[33][303] = 1;
TABLE[33][302] = 1;
TABLE[33][292] = 1;
TABLE[33][304] = 1;
TABLE[33][47] = 1;
TABLE[33][37] = 1;
TABLE[136][44] = 1;
TABLE[136][123] = 1;
TABLE[136][61] = 1;
TABLE[136][278] = 1;
TABLE[136][299] = 1;
TABLE[136][40] = 1;
TABLE[136][295] = 1;
TABLE[136][294] = 1;
TABLE[136][33] = 1;
TABLE[136][126] = 1;
TABLE[136][45] = 1;
TABLE[136][43] = 1;
TABLE[136][38] = 1;
TABLE[136][63] = 1;
TABLE[136][42] = 1;
TABLE[136][289] = 1;
TABLE[136][297] = 1;
TABLE[136][307] = 1;
TABLE[136][306] = 1;
TABLE[136][308] = 1;
TABLE[136][298] = 1;
TABLE[136][301] = 1;
TABLE[136][303] = 1;
TABLE[136][302] = 1;
TABLE[136][292] = 1;
TABLE[136][304] = 1;
TABLE[136][37] = 1;
TABLE[136][47] = 1;
TABLE[211][61] = 1;
TABLE[211][123] = 1;
TABLE[211][40] = 1;
TABLE[211][299] = 1;
TABLE[211][278] = 1;
TABLE[211][42] = 1;
TABLE[211][63] = 1;
TABLE[211][38] = 1;
TABLE[211][43] = 1;
TABLE[211][45] = 1;
TABLE[211][126] = 1;
TABLE[211][33] = 1;
TABLE[211][294] = 1;
TABLE[211][295] = 1;
TABLE[211][297] = 1;
TABLE[211][289] = 1;
TABLE[211][298] = 1;
TABLE[211][308] = 1;
TABLE[211][306] = 1;
TABLE[211][307] = 1;
TABLE[211][301] = 1;
TABLE[211][303] = 1;
TABLE[211][302] = 1;
TABLE[211][292] = 1;
TABLE[211][304] = 1;
TABLE[211][47] = 1;
TABLE[211][37] = 1;
TABLE[211][59] = 1;
TABLE[211][44] = 1;
TABLE[34][59] = 1;
TABLE[34][44] = 1;
TABLE[34][123] = 1;
TABLE[34][278] = 1;
TABLE[34][295] = 1;
TABLE[34][294] = 1;
TABLE[34][33] = 1;
TABLE[34][126] = 1;
TABLE[34][45] = 1;
TABLE[34][43] = 1;
TABLE[34][38] = 1;
TABLE[34][63] = 1;
TABLE[34][289] = 1;
TABLE[34][297] = 1;
TABLE[34][307] = 1;
TABLE[34][306] = 1;
TABLE[34][308] = 1;
TABLE[34][298] = 1;
TABLE[34][301] = 1;
TABLE[34][303] = 1;
TABLE[34][302] = 1;
TABLE[34][292] = 1;
TABLE[34][304] = 1;
TABLE[34][37] = 1;
TABLE[34][47] = 1;
TABLE[34][61] = 1;
TABLE[34][299] = 1;
TABLE[34][40] = 1;
TABLE[34][42] = 1;
TABLE[137][61] = 1;
TABLE[137][40] = 1;
TABLE[137][299] = 1;
TABLE[137][42] = 1;
TABLE[212][123] = 1;
TABLE[212][278] = 1;
TABLE[212][295] = 1;
TABLE[212][294] = 1;
TABLE[212][33] = 1;
TABLE[212][126] = 1;
TABLE[212][45] = 1;
TABLE[212][43] = 1;
TABLE[212][42] = 1;
TABLE[212][38] = 1;
TABLE[212][63] = 1;
TABLE[212][299] = 1;
TABLE[212][289] = 1;
TABLE[212][40] = 1;
TABLE[212][297] = 1;
TABLE[212][307] = 1;
TABLE[212][306] = 1;
TABLE[212][308] = 1;
TABLE[212][298] = 1;
TABLE[212][301] = 1;
TABLE[212][303] = 1;
TABLE[212][302] = 1;
TABLE[212][292] = 1;
TABLE[212][304] = 1;
TABLE[212][37] = 1;
TABLE[212][47] = 1;
TABLE[212][59] = 1;
TABLE[212][44] = 1;
TABLE[35][260] = 1;
TABLE[35][286] = 1;
TABLE[35][285] = 1;
TABLE[35][259] = 1;
TABLE[35][276] = 1;
TABLE[35][272] = 1;
TABLE[35][273] = 1;
TABLE[35][268] = 1;
TABLE[35][264] = 1;
TABLE[35][277] = 1;
TABLE[35][284] = 1;
TABLE[35][266] = 1;
TABLE[35][299] = 1;
TABLE[35][280] = 1;
TABLE[35][283] = 1;
TABLE[36][284] = 1;
TABLE[36][277] = 1;
TABLE[36][264] = 1;
TABLE[36][268] = 1;
TABLE[36][273] = 1;
TABLE[36][272] = 1;
TABLE[36][276] = 1;
TABLE[36][259] = 1;
TABLE[36][285] = 1;
TABLE[36][286] = 1;
TABLE[36][260] = 1;
TABLE[36][299] = 1;
TABLE[36][266] = 1;
TABLE[36][283] = 1;
TABLE[36][280] = 1;
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
TABLE[138][299] = 1;
TABLE[138][280] = 1;
TABLE[138][283] = 1;
TABLE[139][260] = 1;
TABLE[139][286] = 1;
TABLE[140][260] = 1;
TABLE[140][286] = 1;
TABLE[140][285] = 1;
TABLE[140][259] = 1;
TABLE[140][276] = 1;
TABLE[140][272] = 1;
TABLE[140][273] = 1;
TABLE[140][268] = 1;
TABLE[140][264] = 1;
TABLE[140][277] = 1;
TABLE[140][284] = 1;
TABLE[140][266] = 1;
TABLE[140][299] = 1;
TABLE[140][280] = 1;
TABLE[140][283] = 1;
TABLE[213][44] = 1;
TABLE[213][58] = 1;
TABLE[213][40] = 1;
TABLE[213][299] = 1;
TABLE[213][42] = 1;
TABLE[213][59] = 1;
TABLE[213][91] = 1;
TABLE[213][41] = 1;
TABLE[37][59] = 1;
TABLE[37][44] = 1;
TABLE[37][58] = 1;
TABLE[37][299] = 1;
TABLE[37][40] = 1;
TABLE[37][42] = 1;
TABLE[38][44] = 1;
TABLE[38][58] = 1;
TABLE[38][40] = 1;
TABLE[38][299] = 1;
TABLE[38][42] = 1;
TABLE[39][59] = 1;
TABLE[39][44] = 1;
TABLE[39][40] = 1;
TABLE[39][299] = 1;
TABLE[39][42] = 1;
TABLE[40][58] = 1;
TABLE[40][299] = 1;
TABLE[40][40] = 1;
TABLE[40][42] = 1;
TABLE[141][58] = 1;
TABLE[141][40] = 1;
TABLE[141][299] = 1;
TABLE[141][42] = 1;
TABLE[214][58] = 1;
TABLE[41][266] = 1;
TABLE[42][266] = 1;
TABLE[142][299] = 1;
TABLE[215][123] = 1;
TABLE[43][44] = 1;
TABLE[43][299] = 1;
TABLE[143][44] = 1;
TABLE[143][299] = 1;
TABLE[216][299] = 1;
TABLE[44][299] = 1;
TABLE[144][61] = 1;
TABLE[45][299] = 1;
TABLE[45][40] = 1;
TABLE[45][42] = 1;
TABLE[145][42] = 1;
TABLE[217][299] = 1;
TABLE[217][40] = 1;
TABLE[46][299] = 1;
TABLE[47][40] = 1;
TABLE[48][299] = 1;
TABLE[48][40] = 1;
TABLE[147][91] = 1;
TABLE[148][40] = 1;
TABLE[150][40] = 1;
TABLE[146][93] = 1;
TABLE[146][63] = 1;
TABLE[146][297] = 1;
TABLE[146][298] = 1;
TABLE[146][301] = 1;
TABLE[146][303] = 1;
TABLE[146][302] = 1;
TABLE[146][292] = 1;
TABLE[146][304] = 1;
TABLE[146][40] = 1;
TABLE[146][45] = 1;
TABLE[146][43] = 1;
TABLE[146][42] = 1;
TABLE[146][47] = 1;
TABLE[146][37] = 1;
TABLE[146][278] = 1;
TABLE[146][295] = 1;
TABLE[146][294] = 1;
TABLE[146][33] = 1;
TABLE[146][126] = 1;
TABLE[146][38] = 1;
TABLE[146][299] = 1;
TABLE[146][289] = 1;
TABLE[146][307] = 1;
TABLE[146][306] = 1;
TABLE[146][308] = 1;
TABLE[218][93] = 1;
TABLE[149][41] = 1;
TABLE[149][299] = 1;
TABLE[149][44] = 1;
TABLE[219][41] = 1;
TABLE[49][42] = 1;
TABLE[151][42] = 1;
TABLE[151][299] = 1;
TABLE[151][40] = 1;
TABLE[151][44] = 1;
TABLE[151][91] = 1;
TABLE[151][41] = 1;
TABLE[151][286] = 1;
TABLE[151][260] = 1;
TABLE[220][42] = 1;
TABLE[220][299] = 1;
TABLE[220][40] = 1;
TABLE[220][44] = 1;
TABLE[220][91] = 1;
TABLE[220][41] = 1;
TABLE[152][42] = 1;
TABLE[221][299] = 1;
TABLE[221][40] = 1;
TABLE[221][44] = 1;
TABLE[221][91] = 1;
TABLE[221][41] = 1;
TABLE[50][260] = 1;
TABLE[50][286] = 1;
TABLE[153][286] = 1;
TABLE[153][260] = 1;
TABLE[222][260] = 1;
TABLE[222][286] = 1;
TABLE[51][44] = 1;
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
TABLE[51][299] = 1;
TABLE[51][280] = 1;
TABLE[51][283] = 1;
TABLE[154][44] = 1;
TABLE[52][44] = 1;
TABLE[52][282] = 1;
TABLE[52][267] = 1;
TABLE[52][279] = 1;
TABLE[52][274] = 1;
TABLE[52][256] = 1;
TABLE[52][284] = 1;
TABLE[52][277] = 1;
TABLE[52][264] = 1;
TABLE[52][268] = 1;
TABLE[52][273] = 1;
TABLE[52][272] = 1;
TABLE[52][276] = 1;
TABLE[52][259] = 1;
TABLE[52][285] = 1;
TABLE[52][286] = 1;
TABLE[52][260] = 1;
TABLE[52][299] = 1;
TABLE[52][266] = 1;
TABLE[52][283] = 1;
TABLE[52][280] = 1;
TABLE[155][44] = 1;
TABLE[155][260] = 1;
TABLE[155][286] = 1;
TABLE[155][285] = 1;
TABLE[155][259] = 1;
TABLE[155][276] = 1;
TABLE[155][272] = 1;
TABLE[155][273] = 1;
TABLE[155][268] = 1;
TABLE[155][264] = 1;
TABLE[155][277] = 1;
TABLE[155][284] = 1;
TABLE[155][256] = 1;
TABLE[155][274] = 1;
TABLE[155][279] = 1;
TABLE[155][267] = 1;
TABLE[155][282] = 1;
TABLE[155][266] = 1;
TABLE[155][299] = 1;
TABLE[155][280] = 1;
TABLE[155][283] = 1;
TABLE[223][282] = 1;
TABLE[223][267] = 1;
TABLE[223][279] = 1;
TABLE[223][274] = 1;
TABLE[223][256] = 1;
TABLE[223][284] = 1;
TABLE[223][277] = 1;
TABLE[223][264] = 1;
TABLE[223][268] = 1;
TABLE[223][273] = 1;
TABLE[223][272] = 1;
TABLE[223][276] = 1;
TABLE[223][259] = 1;
TABLE[223][285] = 1;
TABLE[223][286] = 1;
TABLE[223][260] = 1;
TABLE[223][299] = 1;
TABLE[223][266] = 1;
TABLE[223][283] = 1;
TABLE[223][280] = 1;
TABLE[53][260] = 1;
TABLE[53][286] = 1;
TABLE[53][285] = 1;
TABLE[53][259] = 1;
TABLE[53][276] = 1;
TABLE[53][272] = 1;
TABLE[53][273] = 1;
TABLE[53][268] = 1;
TABLE[53][264] = 1;
TABLE[53][277] = 1;
TABLE[53][284] = 1;
TABLE[53][256] = 1;
TABLE[53][274] = 1;
TABLE[53][279] = 1;
TABLE[53][267] = 1;
TABLE[53][282] = 1;
TABLE[53][266] = 1;
TABLE[53][299] = 1;
TABLE[53][280] = 1;
TABLE[53][283] = 1;
TABLE[156][44] = 1;
TABLE[156][40] = 1;
TABLE[156][299] = 1;
TABLE[156][42] = 1;
TABLE[158][44] = 1;
TABLE[158][42] = 1;
TABLE[158][40] = 1;
TABLE[158][91] = 1;
TABLE[157][44] = 1;
TABLE[157][42] = 1;
TABLE[157][40] = 1;
TABLE[157][91] = 1;
TABLE[224][44] = 1;
TABLE[54][299] = 1;
TABLE[54][44] = 1;
TABLE[159][299] = 1;
TABLE[159][44] = 1;
TABLE[225][299] = 1;
TABLE[55][59] = 1;
TABLE[55][44] = 1;
TABLE[55][125] = 1;
TABLE[55][278] = 1;
TABLE[55][63] = 1;
TABLE[55][38] = 1;
TABLE[55][42] = 1;
TABLE[55][43] = 1;
TABLE[55][45] = 1;
TABLE[55][126] = 1;
TABLE[55][33] = 1;
TABLE[55][294] = 1;
TABLE[55][295] = 1;
TABLE[55][297] = 1;
TABLE[55][40] = 1;
TABLE[55][289] = 1;
TABLE[55][299] = 1;
TABLE[55][298] = 1;
TABLE[55][308] = 1;
TABLE[55][306] = 1;
TABLE[55][307] = 1;
TABLE[55][301] = 1;
TABLE[55][303] = 1;
TABLE[55][302] = 1;
TABLE[55][292] = 1;
TABLE[55][304] = 1;
TABLE[55][47] = 1;
TABLE[55][37] = 1;
TABLE[56][123] = 1;
TABLE[160][44] = 1;
TABLE[226][125] = 1;
TABLE[57][125] = 1;
TABLE[57][123] = 1;
TABLE[57][44] = 1;
TABLE[57][278] = 1;
TABLE[57][295] = 1;
TABLE[57][294] = 1;
TABLE[57][33] = 1;
TABLE[57][126] = 1;
TABLE[57][45] = 1;
TABLE[57][43] = 1;
TABLE[57][42] = 1;
TABLE[57][38] = 1;
TABLE[57][63] = 1;
TABLE[57][299] = 1;
TABLE[57][289] = 1;
TABLE[57][40] = 1;
TABLE[57][297] = 1;
TABLE[57][307] = 1;
TABLE[57][306] = 1;
TABLE[57][308] = 1;
TABLE[57][298] = 1;
TABLE[57][301] = 1;
TABLE[57][303] = 1;
TABLE[57][302] = 1;
TABLE[57][292] = 1;
TABLE[57][304] = 1;
TABLE[57][37] = 1;
TABLE[57][47] = 1;
TABLE[161][123] = 1;
TABLE[161][44] = 1;
TABLE[161][278] = 1;
TABLE[161][63] = 1;
TABLE[161][38] = 1;
TABLE[161][42] = 1;
TABLE[161][43] = 1;
TABLE[161][45] = 1;
TABLE[161][126] = 1;
TABLE[161][33] = 1;
TABLE[161][294] = 1;
TABLE[161][295] = 1;
TABLE[161][297] = 1;
TABLE[161][40] = 1;
TABLE[161][289] = 1;
TABLE[161][299] = 1;
TABLE[161][298] = 1;
TABLE[161][308] = 1;
TABLE[161][306] = 1;
TABLE[161][307] = 1;
TABLE[161][301] = 1;
TABLE[161][303] = 1;
TABLE[161][302] = 1;
TABLE[161][292] = 1;
TABLE[161][304] = 1;
TABLE[161][47] = 1;
TABLE[161][37] = 1;
TABLE[227][123] = 1;
TABLE[227][278] = 1;
TABLE[227][295] = 1;
TABLE[227][294] = 1;
TABLE[227][33] = 1;
TABLE[227][126] = 1;
TABLE[227][45] = 1;
TABLE[227][43] = 1;
TABLE[227][42] = 1;
TABLE[227][38] = 1;
TABLE[227][63] = 1;
TABLE[227][299] = 1;
TABLE[227][289] = 1;
TABLE[227][40] = 1;
TABLE[227][297] = 1;
TABLE[227][307] = 1;
TABLE[227][306] = 1;
TABLE[227][308] = 1;
TABLE[227][298] = 1;
TABLE[227][301] = 1;
TABLE[227][303] = 1;
TABLE[227][302] = 1;
TABLE[227][292] = 1;
TABLE[227][304] = 1;
TABLE[227][37] = 1;
TABLE[227][47] = 1;
TABLE[227][44] = 1;
TABLE[227][125] = 1;
TABLE[58][260] = 1;
TABLE[58][286] = 1;
TABLE[58][285] = 1;
TABLE[58][259] = 1;
TABLE[58][276] = 1;
TABLE[58][272] = 1;
TABLE[58][273] = 1;
TABLE[58][268] = 1;
TABLE[58][264] = 1;
TABLE[58][277] = 1;
TABLE[58][284] = 1;
TABLE[58][266] = 1;
TABLE[58][299] = 1;
TABLE[58][280] = 1;
TABLE[58][283] = 1;
TABLE[162][41] = 1;
TABLE[162][42] = 1;
TABLE[162][40] = 1;
TABLE[162][91] = 1;
TABLE[228][41] = 1;
TABLE[59][42] = 1;
TABLE[60][44] = 1;
TABLE[60][41] = 1;
TABLE[60][40] = 1;
TABLE[60][91] = 1;
TABLE[60][42] = 1;
TABLE[163][42] = 1;
TABLE[229][40] = 1;
TABLE[229][91] = 1;
TABLE[229][44] = 1;
TABLE[229][41] = 1;
TABLE[61][40] = 1;
TABLE[62][40] = 1;
TABLE[62][91] = 1;
TABLE[164][40] = 1;
TABLE[164][91] = 1;
TABLE[230][91] = 1;
TABLE[230][40] = 1;
TABLE[166][91] = 1;
TABLE[168][40] = 1;
TABLE[165][93] = 1;
TABLE[165][63] = 1;
TABLE[165][297] = 1;
TABLE[165][298] = 1;
TABLE[165][301] = 1;
TABLE[165][303] = 1;
TABLE[165][302] = 1;
TABLE[165][292] = 1;
TABLE[165][304] = 1;
TABLE[165][40] = 1;
TABLE[165][45] = 1;
TABLE[165][43] = 1;
TABLE[165][42] = 1;
TABLE[165][47] = 1;
TABLE[165][37] = 1;
TABLE[165][278] = 1;
TABLE[165][295] = 1;
TABLE[165][294] = 1;
TABLE[165][33] = 1;
TABLE[165][126] = 1;
TABLE[165][38] = 1;
TABLE[165][299] = 1;
TABLE[165][289] = 1;
TABLE[165][307] = 1;
TABLE[165][306] = 1;
TABLE[165][308] = 1;
TABLE[231][93] = 1;
TABLE[167][41] = 1;
TABLE[167][44] = 1;
TABLE[167][282] = 1;
TABLE[167][267] = 1;
TABLE[167][279] = 1;
TABLE[167][274] = 1;
TABLE[167][256] = 1;
TABLE[167][284] = 1;
TABLE[167][277] = 1;
TABLE[167][264] = 1;
TABLE[167][268] = 1;
TABLE[167][273] = 1;
TABLE[167][272] = 1;
TABLE[167][276] = 1;
TABLE[167][259] = 1;
TABLE[167][285] = 1;
TABLE[167][286] = 1;
TABLE[167][260] = 1;
TABLE[167][299] = 1;
TABLE[167][266] = 1;
TABLE[167][283] = 1;
TABLE[167][280] = 1;
TABLE[232][41] = 1;
TABLE[63][299] = 1;
TABLE[64][299] = 1;
TABLE[64][258] = 1;
TABLE[64][262] = 1;
TABLE[65][125] = 1;
TABLE[65][265] = 1;
TABLE[65][287] = 1;
TABLE[65][262] = 1;
TABLE[65][258] = 1;
TABLE[65][123] = 1;
TABLE[65][281] = 1;
TABLE[65][271] = 1;
TABLE[65][269] = 1;
TABLE[65][263] = 1;
TABLE[65][275] = 1;
TABLE[65][257] = 1;
TABLE[65][261] = 1;
TABLE[65][270] = 1;
TABLE[65][59] = 1;
TABLE[65][44] = 1;
TABLE[65][278] = 1;
TABLE[65][295] = 1;
TABLE[65][294] = 1;
TABLE[65][33] = 1;
TABLE[65][126] = 1;
TABLE[65][45] = 1;
TABLE[65][43] = 1;
TABLE[65][42] = 1;
TABLE[65][38] = 1;
TABLE[65][63] = 1;
TABLE[65][299] = 1;
TABLE[65][289] = 1;
TABLE[65][40] = 1;
TABLE[65][297] = 1;
TABLE[65][307] = 1;
TABLE[65][306] = 1;
TABLE[65][308] = 1;
TABLE[65][298] = 1;
TABLE[65][301] = 1;
TABLE[65][303] = 1;
TABLE[65][302] = 1;
TABLE[65][292] = 1;
TABLE[65][304] = 1;
TABLE[65][37] = 1;
TABLE[65][47] = 1;
TABLE[66][123] = 1;
TABLE[67][271] = 1;
TABLE[67][281] = 1;
TABLE[68][287] = 1;
TABLE[68][263] = 1;
TABLE[68][269] = 1;
TABLE[69][270] = 1;
TABLE[69][261] = 1;
TABLE[69][257] = 1;
TABLE[69][275] = 1;
TABLE[70][299] = 1;
TABLE[71][258] = 1;
TABLE[72][262] = 1;
TABLE[73][59] = 1;
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
TABLE[73][299] = 1;
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
TABLE[169][59] = 1;
TABLE[169][44] = 1;
TABLE[169][278] = 1;
TABLE[169][295] = 1;
TABLE[169][294] = 1;
TABLE[169][33] = 1;
TABLE[169][126] = 1;
TABLE[169][45] = 1;
TABLE[169][43] = 1;
TABLE[169][42] = 1;
TABLE[169][38] = 1;
TABLE[169][63] = 1;
TABLE[169][299] = 1;
TABLE[169][289] = 1;
TABLE[169][40] = 1;
TABLE[169][297] = 1;
TABLE[169][307] = 1;
TABLE[169][306] = 1;
TABLE[169][308] = 1;
TABLE[169][298] = 1;
TABLE[169][301] = 1;
TABLE[169][303] = 1;
TABLE[169][302] = 1;
TABLE[169][292] = 1;
TABLE[169][304] = 1;
TABLE[169][37] = 1;
TABLE[169][47] = 1;
TABLE[233][59] = 1;
TABLE[74][123] = 1;
TABLE[170][262] = 1;
TABLE[170][258] = 1;
TABLE[170][59] = 1;
TABLE[170][123] = 1;
TABLE[170][281] = 1;
TABLE[170][271] = 1;
TABLE[170][269] = 1;
TABLE[170][263] = 1;
TABLE[170][287] = 1;
TABLE[170][275] = 1;
TABLE[170][257] = 1;
TABLE[170][261] = 1;
TABLE[170][270] = 1;
TABLE[170][44] = 1;
TABLE[170][278] = 1;
TABLE[170][63] = 1;
TABLE[170][38] = 1;
TABLE[170][42] = 1;
TABLE[170][43] = 1;
TABLE[170][45] = 1;
TABLE[170][126] = 1;
TABLE[170][33] = 1;
TABLE[170][294] = 1;
TABLE[170][295] = 1;
TABLE[170][297] = 1;
TABLE[170][40] = 1;
TABLE[170][289] = 1;
TABLE[170][298] = 1;
TABLE[170][308] = 1;
TABLE[170][306] = 1;
TABLE[170][307] = 1;
TABLE[170][301] = 1;
TABLE[170][303] = 1;
TABLE[170][302] = 1;
TABLE[170][292] = 1;
TABLE[170][304] = 1;
TABLE[170][47] = 1;
TABLE[170][37] = 1;
TABLE[170][125] = 1;
TABLE[170][260] = 1;
TABLE[170][286] = 1;
TABLE[170][285] = 1;
TABLE[170][259] = 1;
TABLE[170][276] = 1;
TABLE[170][272] = 1;
TABLE[170][273] = 1;
TABLE[170][268] = 1;
TABLE[170][264] = 1;
TABLE[170][277] = 1;
TABLE[170][284] = 1;
TABLE[170][256] = 1;
TABLE[170][274] = 1;
TABLE[170][279] = 1;
TABLE[170][267] = 1;
TABLE[170][282] = 1;
TABLE[170][266] = 1;
TABLE[170][299] = 1;
TABLE[170][280] = 1;
TABLE[170][283] = 1;
TABLE[234][262] = 1;
TABLE[234][258] = 1;
TABLE[234][299] = 1;
TABLE[234][59] = 1;
TABLE[234][123] = 1;
TABLE[234][281] = 1;
TABLE[234][271] = 1;
TABLE[234][269] = 1;
TABLE[234][263] = 1;
TABLE[234][287] = 1;
TABLE[234][275] = 1;
TABLE[234][257] = 1;
TABLE[234][261] = 1;
TABLE[234][270] = 1;
TABLE[234][44] = 1;
TABLE[234][278] = 1;
TABLE[234][63] = 1;
TABLE[234][38] = 1;
TABLE[234][42] = 1;
TABLE[234][43] = 1;
TABLE[234][45] = 1;
TABLE[234][126] = 1;
TABLE[234][33] = 1;
TABLE[234][294] = 1;
TABLE[234][295] = 1;
TABLE[234][297] = 1;
TABLE[234][40] = 1;
TABLE[234][289] = 1;
TABLE[234][298] = 1;
TABLE[234][308] = 1;
TABLE[234][306] = 1;
TABLE[234][307] = 1;
TABLE[234][301] = 1;
TABLE[234][303] = 1;
TABLE[234][302] = 1;
TABLE[234][292] = 1;
TABLE[234][304] = 1;
TABLE[234][47] = 1;
TABLE[234][37] = 1;
TABLE[234][125] = 1;
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
TABLE[235][125] = 1;
TABLE[75][125] = 1;
TABLE[75][262] = 1;
TABLE[75][258] = 1;
TABLE[75][299] = 1;
TABLE[75][59] = 1;
TABLE[75][123] = 1;
TABLE[75][281] = 1;
TABLE[75][271] = 1;
TABLE[75][269] = 1;
TABLE[75][263] = 1;
TABLE[75][287] = 1;
TABLE[75][275] = 1;
TABLE[75][257] = 1;
TABLE[75][261] = 1;
TABLE[75][270] = 1;
TABLE[75][44] = 1;
TABLE[75][278] = 1;
TABLE[75][63] = 1;
TABLE[75][38] = 1;
TABLE[75][42] = 1;
TABLE[75][43] = 1;
TABLE[75][45] = 1;
TABLE[75][126] = 1;
TABLE[75][33] = 1;
TABLE[75][294] = 1;
TABLE[75][295] = 1;
TABLE[75][297] = 1;
TABLE[75][40] = 1;
TABLE[75][289] = 1;
TABLE[75][298] = 1;
TABLE[75][308] = 1;
TABLE[75][306] = 1;
TABLE[75][307] = 1;
TABLE[75][301] = 1;
TABLE[75][303] = 1;
TABLE[75][302] = 1;
TABLE[75][292] = 1;
TABLE[75][304] = 1;
TABLE[75][47] = 1;
TABLE[75][37] = 1;
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
TABLE[172][299] = 1;
TABLE[172][258] = 1;
TABLE[172][262] = 1;
TABLE[172][44] = 1;
TABLE[172][278] = 1;
TABLE[172][295] = 1;
TABLE[172][294] = 1;
TABLE[172][33] = 1;
TABLE[172][126] = 1;
TABLE[172][45] = 1;
TABLE[172][43] = 1;
TABLE[172][42] = 1;
TABLE[172][38] = 1;
TABLE[172][63] = 1;
TABLE[172][289] = 1;
TABLE[172][40] = 1;
TABLE[172][297] = 1;
TABLE[172][307] = 1;
TABLE[172][306] = 1;
TABLE[172][308] = 1;
TABLE[172][298] = 1;
TABLE[172][301] = 1;
TABLE[172][303] = 1;
TABLE[172][302] = 1;
TABLE[172][292] = 1;
TABLE[172][304] = 1;
TABLE[172][37] = 1;
TABLE[172][47] = 1;
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
TABLE[76][271] = 1;
TABLE[77][281] = 1;
TABLE[173][265] = 1;
TABLE[237][125] = 1;
TABLE[237][265] = 1;
TABLE[237][287] = 1;
TABLE[237][262] = 1;
TABLE[237][258] = 1;
TABLE[237][299] = 1;
TABLE[237][59] = 1;
TABLE[237][123] = 1;
TABLE[237][281] = 1;
TABLE[237][271] = 1;
TABLE[237][269] = 1;
TABLE[237][263] = 1;
TABLE[237][275] = 1;
TABLE[237][257] = 1;
TABLE[237][261] = 1;
TABLE[237][270] = 1;
TABLE[237][44] = 1;
TABLE[237][278] = 1;
TABLE[237][63] = 1;
TABLE[237][38] = 1;
TABLE[237][42] = 1;
TABLE[237][43] = 1;
TABLE[237][45] = 1;
TABLE[237][126] = 1;
TABLE[237][33] = 1;
TABLE[237][294] = 1;
TABLE[237][295] = 1;
TABLE[237][297] = 1;
TABLE[237][40] = 1;
TABLE[237][289] = 1;
TABLE[237][298] = 1;
TABLE[237][308] = 1;
TABLE[237][306] = 1;
TABLE[237][307] = 1;
TABLE[237][301] = 1;
TABLE[237][303] = 1;
TABLE[237][302] = 1;
TABLE[237][292] = 1;
TABLE[237][304] = 1;
TABLE[237][47] = 1;
TABLE[237][37] = 1;
TABLE[78][287] = 1;
TABLE[79][263] = 1;
TABLE[80][269] = 1;
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
TABLE[238][59] = 1;
TABLE[175][59] = 1;
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
TABLE[239][59] = 1;
TABLE[176][41] = 1;
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
TABLE[240][41] = 1;
TABLE[81][270] = 1;
TABLE[82][261] = 1;
TABLE[83][257] = 1;
TABLE[84][275] = 1;
TABLE[177][59] = 1;
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
TABLE[241][59] = 1;
TABLE[85][59] = 1;
TABLE[85][41] = 1;
TABLE[85][58] = 1;
TABLE[85][93] = 1;
TABLE[85][44] = 1;
TABLE[85][278] = 1;
TABLE[85][63] = 1;
TABLE[85][38] = 1;
TABLE[85][42] = 1;
TABLE[85][43] = 1;
TABLE[85][45] = 1;
TABLE[85][126] = 1;
TABLE[85][33] = 1;
TABLE[85][294] = 1;
TABLE[85][295] = 1;
TABLE[85][297] = 1;
TABLE[85][40] = 1;
TABLE[85][289] = 1;
TABLE[85][299] = 1;
TABLE[85][298] = 1;
TABLE[85][308] = 1;
TABLE[85][306] = 1;
TABLE[85][307] = 1;
TABLE[85][301] = 1;
TABLE[85][303] = 1;
TABLE[85][302] = 1;
TABLE[85][292] = 1;
TABLE[85][304] = 1;
TABLE[85][47] = 1;
TABLE[85][37] = 1;
TABLE[178][44] = 1;
TABLE[178][278] = 1;
TABLE[178][295] = 1;
TABLE[178][294] = 1;
TABLE[178][33] = 1;
TABLE[178][126] = 1;
TABLE[178][45] = 1;
TABLE[178][43] = 1;
TABLE[178][42] = 1;
TABLE[178][38] = 1;
TABLE[178][63] = 1;
TABLE[178][299] = 1;
TABLE[178][289] = 1;
TABLE[178][40] = 1;
TABLE[178][297] = 1;
TABLE[178][307] = 1;
TABLE[178][306] = 1;
TABLE[178][308] = 1;
TABLE[178][298] = 1;
TABLE[178][301] = 1;
TABLE[178][303] = 1;
TABLE[178][302] = 1;
TABLE[178][292] = 1;
TABLE[178][304] = 1;
TABLE[178][37] = 1;
TABLE[178][47] = 1;
TABLE[242][278] = 1;
TABLE[242][63] = 1;
TABLE[242][38] = 1;
TABLE[242][42] = 1;
TABLE[242][43] = 1;
TABLE[242][45] = 1;
TABLE[242][126] = 1;
TABLE[242][33] = 1;
TABLE[242][294] = 1;
TABLE[242][295] = 1;
TABLE[242][297] = 1;
TABLE[242][40] = 1;
TABLE[242][289] = 1;
TABLE[242][299] = 1;
TABLE[242][298] = 1;
TABLE[242][308] = 1;
TABLE[242][306] = 1;
TABLE[242][307] = 1;
TABLE[242][301] = 1;
TABLE[242][303] = 1;
TABLE[242][302] = 1;
TABLE[242][292] = 1;
TABLE[242][304] = 1;
TABLE[242][47] = 1;
TABLE[242][37] = 1;
TABLE[242][59] = 1;
TABLE[242][41] = 1;
TABLE[242][44] = 1;
TABLE[242][58] = 1;
TABLE[242][93] = 1;
TABLE[86][59] = 1;
TABLE[86][41] = 1;
TABLE[86][44] = 1;
TABLE[86][125] = 1;
TABLE[86][58] = 1;
TABLE[86][93] = 1;
TABLE[86][63] = 1;
TABLE[86][297] = 1;
TABLE[86][298] = 1;
TABLE[86][301] = 1;
TABLE[86][303] = 1;
TABLE[86][302] = 1;
TABLE[86][292] = 1;
TABLE[86][304] = 1;
TABLE[86][43] = 1;
TABLE[86][45] = 1;
TABLE[86][40] = 1;
TABLE[86][278] = 1;
TABLE[86][37] = 1;
TABLE[86][47] = 1;
TABLE[86][42] = 1;
TABLE[86][38] = 1;
TABLE[86][126] = 1;
TABLE[86][33] = 1;
TABLE[86][294] = 1;
TABLE[86][295] = 1;
TABLE[86][289] = 1;
TABLE[86][299] = 1;
TABLE[86][308] = 1;
TABLE[86][306] = 1;
TABLE[86][307] = 1;
TABLE[87][278] = 1;
TABLE[87][295] = 1;
TABLE[87][294] = 1;
TABLE[87][33] = 1;
TABLE[87][126] = 1;
TABLE[87][45] = 1;
TABLE[87][43] = 1;
TABLE[87][42] = 1;
TABLE[87][38] = 1;
TABLE[87][299] = 1;
TABLE[87][289] = 1;
TABLE[87][40] = 1;
TABLE[87][307] = 1;
TABLE[87][306] = 1;
TABLE[87][308] = 1;
TABLE[88][291] = 1;
TABLE[89][61] = 1;
TABLE[90][59] = 1;
TABLE[90][41] = 1;
TABLE[90][125] = 1;
TABLE[90][93] = 1;
TABLE[90][58] = 1;
TABLE[90][44] = 1;
TABLE[90][63] = 1;
TABLE[90][297] = 1;
TABLE[90][298] = 1;
TABLE[90][301] = 1;
TABLE[90][303] = 1;
TABLE[90][302] = 1;
TABLE[90][292] = 1;
TABLE[90][304] = 1;
TABLE[90][40] = 1;
TABLE[90][45] = 1;
TABLE[90][43] = 1;
TABLE[90][42] = 1;
TABLE[90][47] = 1;
TABLE[90][37] = 1;
TABLE[90][278] = 1;
TABLE[90][295] = 1;
TABLE[90][294] = 1;
TABLE[90][33] = 1;
TABLE[90][126] = 1;
TABLE[90][38] = 1;
TABLE[90][299] = 1;
TABLE[90][289] = 1;
TABLE[90][307] = 1;
TABLE[90][306] = 1;
TABLE[90][308] = 1;
TABLE[179][63] = 1;
TABLE[243][59] = 1;
TABLE[243][41] = 1;
TABLE[243][125] = 1;
TABLE[243][93] = 1;
TABLE[243][58] = 1;
TABLE[243][44] = 1;
TABLE[91][59] = 1;
TABLE[91][125] = 1;
TABLE[91][93] = 1;
TABLE[91][58] = 1;
TABLE[91][44] = 1;
TABLE[91][63] = 1;
TABLE[91][297] = 1;
TABLE[91][298] = 1;
TABLE[91][301] = 1;
TABLE[91][303] = 1;
TABLE[91][302] = 1;
TABLE[91][292] = 1;
TABLE[91][304] = 1;
TABLE[91][43] = 1;
TABLE[91][45] = 1;
TABLE[91][40] = 1;
TABLE[91][278] = 1;
TABLE[91][37] = 1;
TABLE[91][47] = 1;
TABLE[91][42] = 1;
TABLE[91][38] = 1;
TABLE[91][126] = 1;
TABLE[91][33] = 1;
TABLE[91][294] = 1;
TABLE[91][295] = 1;
TABLE[91][289] = 1;
TABLE[91][299] = 1;
TABLE[91][308] = 1;
TABLE[91][306] = 1;
TABLE[91][307] = 1;
TABLE[92][63] = 1;
TABLE[92][59] = 1;
TABLE[92][41] = 1;
TABLE[92][125] = 1;
TABLE[92][93] = 1;
TABLE[92][58] = 1;
TABLE[92][44] = 1;
TABLE[92][297] = 1;
TABLE[92][298] = 1;
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
TABLE[180][33] = 1;
TABLE[180][126] = 1;
TABLE[180][38] = 1;
TABLE[180][299] = 1;
TABLE[180][289] = 1;
TABLE[180][307] = 1;
TABLE[180][306] = 1;
TABLE[180][308] = 1;
TABLE[244][298] = 1;
TABLE[244][301] = 1;
TABLE[244][303] = 1;
TABLE[244][302] = 1;
TABLE[244][292] = 1;
TABLE[244][304] = 1;
TABLE[244][43] = 1;
TABLE[244][45] = 1;
TABLE[244][40] = 1;
TABLE[244][278] = 1;
TABLE[244][37] = 1;
TABLE[244][47] = 1;
TABLE[244][42] = 1;
TABLE[244][38] = 1;
TABLE[244][126] = 1;
TABLE[244][33] = 1;
TABLE[244][294] = 1;
TABLE[244][295] = 1;
TABLE[244][289] = 1;
TABLE[244][299] = 1;
TABLE[244][308] = 1;
TABLE[244][306] = 1;
TABLE[244][307] = 1;
TABLE[244][63] = 1;
TABLE[244][59] = 1;
TABLE[244][41] = 1;
TABLE[244][297] = 1;
TABLE[244][125] = 1;
TABLE[244][93] = 1;
TABLE[244][58] = 1;
TABLE[244][44] = 1;
TABLE[93][63] = 1;
TABLE[93][59] = 1;
TABLE[93][41] = 1;
TABLE[93][297] = 1;
TABLE[93][125] = 1;
TABLE[93][93] = 1;
TABLE[93][58] = 1;
TABLE[93][44] = 1;
TABLE[93][298] = 1;
TABLE[93][301] = 1;
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
TABLE[181][38] = 1;
TABLE[181][126] = 1;
TABLE[181][33] = 1;
TABLE[181][294] = 1;
TABLE[181][295] = 1;
TABLE[181][289] = 1;
TABLE[181][299] = 1;
TABLE[181][308] = 1;
TABLE[181][306] = 1;
TABLE[181][307] = 1;
TABLE[245][301] = 1;
TABLE[245][303] = 1;
TABLE[245][302] = 1;
TABLE[245][292] = 1;
TABLE[245][304] = 1;
TABLE[245][40] = 1;
TABLE[245][45] = 1;
TABLE[245][43] = 1;
TABLE[245][42] = 1;
TABLE[245][47] = 1;
TABLE[245][37] = 1;
TABLE[245][278] = 1;
TABLE[245][295] = 1;
TABLE[245][294] = 1;
TABLE[245][33] = 1;
TABLE[245][126] = 1;
TABLE[245][38] = 1;
TABLE[245][299] = 1;
TABLE[245][289] = 1;
TABLE[245][307] = 1;
TABLE[245][306] = 1;
TABLE[245][308] = 1;
TABLE[245][63] = 1;
TABLE[245][59] = 1;
TABLE[245][41] = 1;
TABLE[245][298] = 1;
TABLE[245][297] = 1;
TABLE[245][125] = 1;
TABLE[245][93] = 1;
TABLE[245][58] = 1;
TABLE[245][44] = 1;
TABLE[94][63] = 1;
TABLE[94][59] = 1;
TABLE[94][41] = 1;
TABLE[94][298] = 1;
TABLE[94][297] = 1;
TABLE[94][125] = 1;
TABLE[94][93] = 1;
TABLE[94][58] = 1;
TABLE[94][44] = 1;
TABLE[94][301] = 1;
TABLE[94][303] = 1;
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
TABLE[182][33] = 1;
TABLE[182][126] = 1;
TABLE[182][38] = 1;
TABLE[182][299] = 1;
TABLE[182][289] = 1;
TABLE[182][307] = 1;
TABLE[182][306] = 1;
TABLE[182][308] = 1;
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
TABLE[246][301] = 1;
TABLE[246][298] = 1;
TABLE[246][297] = 1;
TABLE[246][125] = 1;
TABLE[246][93] = 1;
TABLE[246][58] = 1;
TABLE[246][44] = 1;
TABLE[95][63] = 1;
TABLE[95][59] = 1;
TABLE[95][41] = 1;
TABLE[95][301] = 1;
TABLE[95][298] = 1;
TABLE[95][297] = 1;
TABLE[95][125] = 1;
TABLE[95][93] = 1;
TABLE[95][58] = 1;
TABLE[95][44] = 1;
TABLE[95][303] = 1;
TABLE[95][302] = 1;
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
TABLE[183][38] = 1;
TABLE[183][126] = 1;
TABLE[183][33] = 1;
TABLE[183][294] = 1;
TABLE[183][295] = 1;
TABLE[183][289] = 1;
TABLE[183][299] = 1;
TABLE[183][308] = 1;
TABLE[183][306] = 1;
TABLE[183][307] = 1;
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
TABLE[247][303] = 1;
TABLE[247][301] = 1;
TABLE[247][298] = 1;
TABLE[247][297] = 1;
TABLE[247][125] = 1;
TABLE[247][93] = 1;
TABLE[247][58] = 1;
TABLE[247][44] = 1;
TABLE[96][63] = 1;
TABLE[96][59] = 1;
TABLE[96][41] = 1;
TABLE[96][303] = 1;
TABLE[96][301] = 1;
TABLE[96][298] = 1;
TABLE[96][297] = 1;
TABLE[96][125] = 1;
TABLE[96][93] = 1;
TABLE[96][58] = 1;
TABLE[96][44] = 1;
TABLE[96][302] = 1;
TABLE[96][292] = 1;
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
TABLE[184][33] = 1;
TABLE[184][126] = 1;
TABLE[184][38] = 1;
TABLE[184][299] = 1;
TABLE[184][289] = 1;
TABLE[184][307] = 1;
TABLE[184][306] = 1;
TABLE[184][308] = 1;
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
TABLE[248][302] = 1;
TABLE[248][303] = 1;
TABLE[248][301] = 1;
TABLE[248][298] = 1;
TABLE[248][297] = 1;
TABLE[248][125] = 1;
TABLE[248][93] = 1;
TABLE[248][58] = 1;
TABLE[248][44] = 1;
TABLE[97][63] = 1;
TABLE[97][59] = 1;
TABLE[97][41] = 1;
TABLE[97][302] = 1;
TABLE[97][303] = 1;
TABLE[97][301] = 1;
TABLE[97][298] = 1;
TABLE[97][297] = 1;
TABLE[97][125] = 1;
TABLE[97][93] = 1;
TABLE[97][58] = 1;
TABLE[97][44] = 1;
TABLE[97][292] = 1;
TABLE[97][304] = 1;
TABLE[97][40] = 1;
TABLE[97][45] = 1;
TABLE[97][43] = 1;
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
TABLE[185][292] = 1;
TABLE[185][304] = 1;
TABLE[185][43] = 1;
TABLE[185][45] = 1;
TABLE[185][40] = 1;
TABLE[185][278] = 1;
TABLE[185][37] = 1;
TABLE[185][47] = 1;
TABLE[185][42] = 1;
TABLE[185][38] = 1;
TABLE[185][126] = 1;
TABLE[185][33] = 1;
TABLE[185][294] = 1;
TABLE[185][295] = 1;
TABLE[185][289] = 1;
TABLE[185][299] = 1;
TABLE[185][308] = 1;
TABLE[185][306] = 1;
TABLE[185][307] = 1;
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
TABLE[249][292] = 1;
TABLE[249][302] = 1;
TABLE[249][303] = 1;
TABLE[249][301] = 1;
TABLE[249][298] = 1;
TABLE[249][297] = 1;
TABLE[249][125] = 1;
TABLE[249][93] = 1;
TABLE[249][58] = 1;
TABLE[249][44] = 1;
TABLE[98][63] = 1;
TABLE[98][59] = 1;
TABLE[98][41] = 1;
TABLE[98][292] = 1;
TABLE[98][302] = 1;
TABLE[98][303] = 1;
TABLE[98][301] = 1;
TABLE[98][298] = 1;
TABLE[98][297] = 1;
TABLE[98][125] = 1;
TABLE[98][93] = 1;
TABLE[98][58] = 1;
TABLE[98][44] = 1;
TABLE[98][304] = 1;
TABLE[98][43] = 1;
TABLE[98][45] = 1;
TABLE[98][40] = 1;
TABLE[98][278] = 1;
TABLE[98][37] = 1;
TABLE[98][47] = 1;
TABLE[98][42] = 1;
TABLE[98][38] = 1;
TABLE[98][126] = 1;
TABLE[98][33] = 1;
TABLE[98][294] = 1;
TABLE[98][295] = 1;
TABLE[98][289] = 1;
TABLE[98][299] = 1;
TABLE[98][308] = 1;
TABLE[98][306] = 1;
TABLE[98][307] = 1;
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
TABLE[186][33] = 1;
TABLE[186][126] = 1;
TABLE[186][38] = 1;
TABLE[186][299] = 1;
TABLE[186][289] = 1;
TABLE[186][307] = 1;
TABLE[186][306] = 1;
TABLE[186][308] = 1;
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
TABLE[250][304] = 1;
TABLE[250][292] = 1;
TABLE[250][302] = 1;
TABLE[250][303] = 1;
TABLE[250][301] = 1;
TABLE[250][298] = 1;
TABLE[250][297] = 1;
TABLE[250][125] = 1;
TABLE[250][93] = 1;
TABLE[250][58] = 1;
TABLE[250][44] = 1;
TABLE[99][63] = 1;
TABLE[99][59] = 1;
TABLE[99][41] = 1;
TABLE[99][304] = 1;
TABLE[99][292] = 1;
TABLE[99][302] = 1;
TABLE[99][303] = 1;
TABLE[99][301] = 1;
TABLE[99][298] = 1;
TABLE[99][297] = 1;
TABLE[99][125] = 1;
TABLE[99][93] = 1;
TABLE[99][58] = 1;
TABLE[99][44] = 1;
TABLE[99][45] = 1;
TABLE[99][43] = 1;
TABLE[99][40] = 1;
TABLE[99][42] = 1;
TABLE[99][47] = 1;
TABLE[99][37] = 1;
TABLE[99][278] = 1;
TABLE[99][295] = 1;
TABLE[99][294] = 1;
TABLE[99][33] = 1;
TABLE[99][126] = 1;
TABLE[99][38] = 1;
TABLE[99][299] = 1;
TABLE[99][289] = 1;
TABLE[99][307] = 1;
TABLE[99][306] = 1;
TABLE[99][308] = 1;
TABLE[189][43] = 1;
TABLE[189][45] = 1;
TABLE[189][40] = 1;
TABLE[189][278] = 1;
TABLE[189][37] = 1;
TABLE[189][47] = 1;
TABLE[189][42] = 1;
TABLE[189][38] = 1;
TABLE[189][126] = 1;
TABLE[189][33] = 1;
TABLE[189][294] = 1;
TABLE[189][295] = 1;
TABLE[189][289] = 1;
TABLE[189][299] = 1;
TABLE[189][308] = 1;
TABLE[189][306] = 1;
TABLE[189][307] = 1;
TABLE[251][40] = 1;
TABLE[251][42] = 1;
TABLE[251][47] = 1;
TABLE[251][37] = 1;
TABLE[251][278] = 1;
TABLE[251][295] = 1;
TABLE[251][294] = 1;
TABLE[251][33] = 1;
TABLE[251][126] = 1;
TABLE[251][45] = 1;
TABLE[251][43] = 1;
TABLE[251][38] = 1;
TABLE[251][299] = 1;
TABLE[251][289] = 1;
TABLE[251][307] = 1;
TABLE[251][306] = 1;
TABLE[251][308] = 1;
TABLE[251][63] = 1;
TABLE[251][59] = 1;
TABLE[251][41] = 1;
TABLE[251][304] = 1;
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
TABLE[187][43] = 1;
TABLE[188][45] = 1;
TABLE[100][40] = 1;
TABLE[100][37] = 1;
TABLE[100][47] = 1;
TABLE[100][42] = 1;
TABLE[100][278] = 1;
TABLE[100][38] = 1;
TABLE[100][43] = 1;
TABLE[100][45] = 1;
TABLE[100][126] = 1;
TABLE[100][33] = 1;
TABLE[100][294] = 1;
TABLE[100][295] = 1;
TABLE[100][289] = 1;
TABLE[100][299] = 1;
TABLE[100][308] = 1;
TABLE[100][306] = 1;
TABLE[100][307] = 1;
TABLE[193][40] = 1;
TABLE[193][42] = 1;
TABLE[193][47] = 1;
TABLE[193][37] = 1;
TABLE[193][278] = 1;
TABLE[193][295] = 1;
TABLE[193][294] = 1;
TABLE[193][33] = 1;
TABLE[193][126] = 1;
TABLE[193][45] = 1;
TABLE[193][43] = 1;
TABLE[193][38] = 1;
TABLE[193][299] = 1;
TABLE[193][289] = 1;
TABLE[193][307] = 1;
TABLE[193][306] = 1;
TABLE[193][308] = 1;
TABLE[252][40] = 1;
TABLE[252][278] = 1;
TABLE[252][38] = 1;
TABLE[252][42] = 1;
TABLE[252][43] = 1;
TABLE[252][45] = 1;
TABLE[252][126] = 1;
TABLE[252][33] = 1;
TABLE[252][294] = 1;
TABLE[252][295] = 1;
TABLE[252][289] = 1;
TABLE[252][299] = 1;
TABLE[252][308] = 1;
TABLE[252][306] = 1;
TABLE[252][307] = 1;
TABLE[190][42] = 1;
TABLE[191][47] = 1;
TABLE[192][37] = 1;
TABLE[101][278] = 1;
TABLE[101][295] = 1;
TABLE[101][294] = 1;
TABLE[101][33] = 1;
TABLE[101][126] = 1;
TABLE[101][45] = 1;
TABLE[101][43] = 1;
TABLE[101][42] = 1;
TABLE[101][38] = 1;
TABLE[101][299] = 1;
TABLE[101][289] = 1;
TABLE[101][40] = 1;
TABLE[101][307] = 1;
TABLE[101][306] = 1;
TABLE[101][308] = 1;
TABLE[102][40] = 1;
TABLE[103][40] = 1;
TABLE[103][289] = 1;
TABLE[103][299] = 1;
TABLE[103][308] = 1;
TABLE[103][306] = 1;
TABLE[103][307] = 1;
TABLE[104][294] = 1;
TABLE[104][295] = 1;
TABLE[105][38] = 1;
TABLE[105][42] = 1;
TABLE[105][43] = 1;
TABLE[105][45] = 1;
TABLE[105][126] = 1;
TABLE[105][33] = 1;
TABLE[106][278] = 1;
TABLE[107][278] = 1;
TABLE[194][294] = 1;
TABLE[195][295] = 1;
TABLE[108][38] = 1;
TABLE[109][42] = 1;
TABLE[110][43] = 1;
TABLE[111][45] = 1;
TABLE[112][126] = 1;
TABLE[113][33] = 1;
TABLE[114][299] = 1;
TABLE[114][289] = 1;
TABLE[114][40] = 1;
TABLE[114][307] = 1;
TABLE[114][306] = 1;
TABLE[114][308] = 1;
TABLE[115][40] = 1;
TABLE[115][289] = 1;
TABLE[115][299] = 1;
TABLE[115][308] = 1;
TABLE[115][306] = 1;
TABLE[115][307] = 1;
TABLE[196][91] = 1;
TABLE[198][40] = 1;
TABLE[199][46] = 1;
TABLE[200][296] = 1;
TABLE[201][294] = 1;
TABLE[202][295] = 1;
TABLE[197][41] = 1;
TABLE[197][44] = 1;
TABLE[197][278] = 1;
TABLE[197][295] = 1;
TABLE[197][294] = 1;
TABLE[197][33] = 1;
TABLE[197][126] = 1;
TABLE[197][45] = 1;
TABLE[197][43] = 1;
TABLE[197][42] = 1;
TABLE[197][38] = 1;
TABLE[197][63] = 1;
TABLE[197][299] = 1;
TABLE[197][289] = 1;
TABLE[197][40] = 1;
TABLE[197][297] = 1;
TABLE[197][307] = 1;
TABLE[197][306] = 1;
TABLE[197][308] = 1;
TABLE[197][298] = 1;
TABLE[197][301] = 1;
TABLE[197][303] = 1;
TABLE[197][302] = 1;
TABLE[197][292] = 1;
TABLE[197][304] = 1;
TABLE[197][37] = 1;
TABLE[197][47] = 1;
TABLE[253][41] = 1;
TABLE[116][299] = 1;
TABLE[117][308] = 1;
TABLE[117][306] = 1;
TABLE[117][307] = 1;
TABLE[117][299] = 1;
TABLE[118][289] = 1;
TABLE[119][40] = 1;
TABLE[120][41] = 1;
TABLE[120][44] = 1;
TABLE[120][278] = 1;
TABLE[120][63] = 1;
TABLE[120][38] = 1;
TABLE[120][42] = 1;
TABLE[120][43] = 1;
TABLE[120][45] = 1;
TABLE[120][126] = 1;
TABLE[120][33] = 1;
TABLE[120][294] = 1;
TABLE[120][295] = 1;
TABLE[120][297] = 1;
TABLE[120][40] = 1;
TABLE[120][289] = 1;
TABLE[120][299] = 1;
TABLE[120][298] = 1;
TABLE[120][308] = 1;
TABLE[120][306] = 1;
TABLE[120][307] = 1;
TABLE[120][301] = 1;
TABLE[120][303] = 1;
TABLE[120][302] = 1;
TABLE[120][292] = 1;
TABLE[120][304] = 1;
TABLE[120][47] = 1;
TABLE[120][37] = 1;
TABLE[203][44] = 1;
TABLE[203][278] = 1;
TABLE[203][295] = 1;
TABLE[203][294] = 1;
TABLE[203][33] = 1;
TABLE[203][126] = 1;
TABLE[203][45] = 1;
TABLE[203][43] = 1;
TABLE[203][42] = 1;
TABLE[203][38] = 1;
TABLE[203][63] = 1;
TABLE[203][299] = 1;
TABLE[203][289] = 1;
TABLE[203][40] = 1;
TABLE[203][297] = 1;
TABLE[203][307] = 1;
TABLE[203][306] = 1;
TABLE[203][308] = 1;
TABLE[203][298] = 1;
TABLE[203][301] = 1;
TABLE[203][303] = 1;
TABLE[203][302] = 1;
TABLE[203][292] = 1;
TABLE[203][304] = 1;
TABLE[203][37] = 1;
TABLE[203][47] = 1;
TABLE[254][278] = 1;
TABLE[254][63] = 1;
TABLE[254][38] = 1;
TABLE[254][42] = 1;
TABLE[254][43] = 1;
TABLE[254][45] = 1;
TABLE[254][126] = 1;
TABLE[254][33] = 1;
TABLE[254][294] = 1;
TABLE[254][295] = 1;
TABLE[254][297] = 1;
TABLE[254][40] = 1;
TABLE[254][289] = 1;
TABLE[254][299] = 1;
TABLE[254][298] = 1;
TABLE[254][308] = 1;
TABLE[254][306] = 1;
TABLE[254][307] = 1;
TABLE[254][301] = 1;
TABLE[254][303] = 1;
TABLE[254][302] = 1;
TABLE[254][292] = 1;
TABLE[254][304] = 1;
TABLE[254][47] = 1;
TABLE[254][37] = 1;
TABLE[254][41] = 1;
TABLE[254][44] = 1;
TABLE[121][308] = 1;
TABLE[122][306] = 1;
TABLE[123][307] = 1;
TABLE[124][299] = 1;
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
      case 161: return 0; break;
      case 169: return 0; break;
      case 182: return 1; break;
      case 189: return 0; break;
      case 197: return 1; break;
      case 202: return 1; break;
      case 209: return 1; break;
      case 214: return 1; break;
      case 222: return 1; break;
      case 227: return 1; break;
      case 235: return 0; break;
      case 241: return 0; break;
      case 246: return 0; break;
      case 254: return 1; break;
      case 261: return 1; break;
      case 271: return 1; break;
      case 281: return 1; break;
      case 288: return 0; break;
      case 301: return 1; break;
      case 308: return 1; break;
      case 313: return 1; break;
      case 321: return 0; break;
      case 326: return 0; break;
      case 331: return 1; break;
      case 336: return 1; break;
      case 343: return 0; break;
      case 358: return 0; break;
      case 376: return 1; break;
      case 383: return 1; break;
      case 390: return 0; break;
      case 396: return 1; break;
      case 403: return 1; break;
      case 410: return 1; break;
      case 415: return 1; break;
      case 422: return 1; break;
      case 427: return 0; break;
      case 432: return 1; break;
      case 437: return 1; break;
      case 445: return 0; break;
      case 450: return 1; break;
      case 458: return 1; break;
      case 465: return 1; break;
      case 470: return 1; break;
      case 478: return 1; break;
      case 489: return 1; break;
      case 496: return 1; break;
      case 501: return 1; break;
      case 509: return 0; break;
      case 514: return 1; break;
      case 521: return 1; break;
      case 530: return 1; break;
      case 537: return 1; break;
      case 548: return 1; break;
      case 555: return 0; break;
      case 567: return 1; break;
      case 574: return 1; break;
      case 581: return 0; break;
      case 585: return 1; break;
      case 609: return 0; break;
      case 628: return 1; break;
      case 633: return 1; break;
      case 640: return 0; break;
      case 647: return 1; break;
      case 654: return 1; break;
      case 661: return 1; break;
      case 666: return 1; break;
      case 673: return 0; break;
      case 690: return 1; break;
      case 698: return 0; break;
      case 728: return 1; break;
      case 735: return 1; break;
      case 742: return 1; break;
      case 749: return 0; break;
      case 771: return 1; break;
      case 778: return 1; break;
      case 783: return 1; break;
      case 791: return 1; break;
      case 801: return 0; break;
      case 809: return 1; break;
      case 814: return 1; break;
      case 824: return 1; break;
      case 828: return 1; break;
      case 833: return 1; break;
      case 841: return 1; break;
      case 846: return 1; break;
      case 854: return 1; break;
      case 859: return 1; break;
      case 867: return 1; break;
      case 872: return 1; break;
      case 880: return 1; break;
      case 885: return 1; break;
      case 893: return 1; break;
      case 898: return 1; break;
      case 906: return 1; break;
      case 911: return 1; break;
      case 919: return 1; break;
      case 924: return 1; break;
      case 932: return 0; break;
      case 940: return 1; break;
      case 945: return 1; break;
      case 953: return 0; break;
      case 965: return 0; break;
      case 976: return 0; break;
      case 1002: return 0; break;
      case 1010: return 0; break;
      case 1034: return 0; break;
      case 1043: return 0; break;
      case 1073: return 1; break;
      case 1080: return 0; break;
      case 1098: return 1; break;
      case 1103: return 1; break;
      case 1111: return 0; break;
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
         case 161: return "type_qualifier"; break;
         case 169: return "struct_or_union_specifier"; break;
         case 182: return "Subphrase"; break;
         case 189: return "struct_or_union"; break;
         case 197: return "struct_declaration_list"; break;
         case 202: return "Subphrase"; break;
         case 209: return "init_declarator_list"; break;
         case 214: return "Subphrase"; break;
         case 222: return "init_declarator"; break;
         case 227: return "Subphrase"; break;
         case 235: return "struct_declaration"; break;
         case 241: return "specifier_qualifier_list"; break;
         case 246: return "Subphrase"; break;
         case 254: return "Subphrase"; break;
         case 261: return "struct_declarator_list"; break;
         case 271: return "struct_declarator"; break;
         case 281: return "Subphrase"; break;
         case 288: return "enum_specifier"; break;
         case 301: return "Subphrase"; break;
         case 308: return "enumerator_list"; break;
         case 313: return "Subphrase"; break;
         case 321: return "enumerator"; break;
         case 326: return "Subphrase"; break;
         case 331: return "declarator"; break;
         case 336: return "Subphrase"; break;
         case 343: return "direct_declarator"; break;
         case 358: return "Subphrase"; break;
         case 376: return "Subphrase"; break;
         case 383: return "Subphrase"; break;
         case 390: return "pointer"; break;
         case 396: return "Subphrase"; break;
         case 403: return "Subphrase"; break;
         case 410: return "type_qualifier_list"; break;
         case 415: return "Subphrase"; break;
         case 422: return "parameter_type_list"; break;
         case 427: return "Subphrase"; break;
         case 432: return "parameter_list"; break;
         case 437: return "Subphrase"; break;
         case 445: return "parameter_declaration"; break;
         case 450: return "Subphrase"; break;
         case 458: return "Subphrase"; break;
         case 465: return "IDENTIFIER_list"; break;
         case 470: return "Subphrase"; break;
         case 478: return "initializer"; break;
         case 489: return "Subphrase"; break;
         case 496: return "initializer_list"; break;
         case 501: return "Subphrase"; break;
         case 509: return "type_name"; break;
         case 514: return "Subphrase"; break;
         case 521: return "abstract_declarator"; break;
         case 530: return "Subphrase"; break;
         case 537: return "direct_abstract_declarator"; break;
         case 548: return "Subphrase"; break;
         case 555: return "Subphrase"; break;
         case 567: return "Subphrase"; break;
         case 574: return "Subphrase"; break;
         case 581: return "typedef_name"; break;
         case 585: return "statement"; break;
         case 609: return "labeled_statement"; break;
         case 628: return "expression_statement"; break;
         case 633: return "Subphrase"; break;
         case 640: return "compound_statement"; break;
         case 647: return "Subphrase"; break;
         case 654: return "Subphrase"; break;
         case 661: return "statement_list"; break;
         case 666: return "Subphrase"; break;
         case 673: return "selection_statement"; break;
         case 690: return "Subphrase"; break;
         case 698: return "iteration_statement"; break;
         case 728: return "Subphrase"; break;
         case 735: return "Subphrase"; break;
         case 742: return "Subphrase"; break;
         case 749: return "jump_statement"; break;
         case 771: return "Subphrase"; break;
         case 778: return "expression"; break;
         case 783: return "Subphrase"; break;
         case 791: return "assignment_expression"; break;
         case 801: return "assignment_operator"; break;
         case 809: return "conditional_expression"; break;
         case 814: return "Subphrase"; break;
         case 824: return "constant_expression"; break;
         case 828: return "logical_OR_expression"; break;
         case 833: return "Subphrase"; break;
         case 841: return "logical_AND_expression"; break;
         case 846: return "Subphrase"; break;
         case 854: return "inclusive_OR_expression"; break;
         case 859: return "Subphrase"; break;
         case 867: return "exclusive_OR_expression"; break;
         case 872: return "Subphrase"; break;
         case 880: return "AND_expression"; break;
         case 885: return "Subphrase"; break;
         case 893: return "equality_expression"; break;
         case 898: return "Subphrase"; break;
         case 906: return "shift_expression"; break;
         case 911: return "Subphrase"; break;
         case 919: return "additive_expression"; break;
         case 924: return "Subphrase"; break;
         case 932: return "Subphrase"; break;
         case 940: return "multiplicative_expression"; break;
         case 945: return "Subphrase"; break;
         case 953: return "Subphrase"; break;
         case 965: return "cast_expression"; break;
         case 976: return "unary_expression"; break;
         case 1002: return "Subphrase"; break;
         case 1010: return "unary_operator"; break;
         case 1034: return "postfix_expression"; break;
         case 1043: return "Subphrase"; break;
         case 1073: return "Subphrase"; break;
         case 1080: return "primary_expression"; break;
         case 1098: return "argument_expression_list"; break;
         case 1103: return "Subphrase"; break;
         case 1111: return "constant"; break;
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
