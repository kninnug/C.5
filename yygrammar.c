#line 1 "ass2.acc"

	#include <stdio.h>
	#include <stdlib.h>
	
	#include "parser.h"

# line 9 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 124: {
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
      case 125: {
         declaration_specifiers();
         } break;
      default: ;
      }
      declarator();
      switch (yyselect()) {
      case 126: {
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
      case 127: {
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
      case 128: {
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
      case 129: {
         storage_class_specifier();
         } break;
      case 130: {
         type_specifier();
#line 39 "ass2.acc"
printf("type specifier\n");
# line 115 "yygrammar.c"
         } break;
      case 131: {
         type_qualifier();
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 132: {
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
      case 133: {
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
      case 134: {
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
      case 135: {
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
      case 136: {
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
      case 137: {
         type_specifier();
         } break;
      case 138: {
         type_qualifier();
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 139: {
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
      struct_declarator();
      } break;
   case 37: {
      struct_declarator_list();
      get_lexval();
      struct_declarator();
      } break;
   }
}

struct_declarator ()
{
   switch(yyselect()) {
   case 38: {
      declarator();
      } break;
   case 39: {
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
   case 40: {
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
   case 41: {
      get_lexval();
      get_lexval();
      } break;
   }
}

enumerator_list ()
{
   switch(yyselect()) {
   case 42: {
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
   case 43: {
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
   case 44: {
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
   case 45: {
      get_lexval();
#line 112 "ass2.acc"
printf("Identifier within declarator: %s\n", yylval.s);
# line 437 "yygrammar.c"
      } break;
   case 46: {
      get_lexval();
      declarator();
      get_lexval();
#line 113 "ass2.acc"
printf("iets met haakjes\n");
# line 445 "yygrammar.c"
      } break;
   case 47: {
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
#line 114 "ass2.acc"
printf("nog iets met haakjes\n");
# line 479 "yygrammar.c"
      } break;
   }
}

pointer ()
{
   switch(yyselect()) {
   case 48: {
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
   case 49: {
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
   case 50: {
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
   case 51: {
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
   case 52: {
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
   case 53: {
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
   case 54: {
      assignment_expression();
      } break;
   case 55: {
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
   case 56: {
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
   case 57: {
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
   case 58: {
      pointer();
      } break;
   case 59: {
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
   case 60: {
      get_lexval();
      abstract_declarator();
      get_lexval();
      } break;
   case 61: {
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
   case 62: {
      get_lexval();
      } break;
   }
}

statement ()
{
   switch(yyselect()) {
   case 63: {
      labeled_statement();
      } break;
   case 64: {
      expression_statement();
      } break;
   case 65: {
      compound_statement();
      } break;
   case 66: {
      selection_statement();
      } break;
   case 67: {
      iteration_statement();
      } break;
   case 68: {
      jump_statement();
      } break;
   }
}

labeled_statement ()
{
   switch(yyselect()) {
   case 69: {
      get_lexval();
      get_lexval();
      statement();
      } break;
   case 70: {
      get_lexval();
      constant_expression();
      get_lexval();
      statement();
      } break;
   case 71: {
      get_lexval();
      get_lexval();
      statement();
      } break;
   }
}

expression_statement ()
{
   switch(yyselect()) {
   case 72: {
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
   case 73: {
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
#line 188 "ass2.acc"
printf("Compound statement\n");
# line 792 "yygrammar.c"
      } break;
   }
}

statement_list ()
{
   switch(yyselect()) {
   case 74: {
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
   case 75: {
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
   case 76: {
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
   case 77: {
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      statement();
      } break;
   case 78: {
      get_lexval();
      statement();
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      get_lexval();
      } break;
   case 79: {
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
   case 80: {
      get_lexval();
      get_lexval();
      get_lexval();
      } break;
   case 81: {
      get_lexval();
      get_lexval();
      } break;
   case 82: {
      get_lexval();
      get_lexval();
      } break;
   case 83: {
      get_lexval();
      switch (yyselect()) {
      case 176: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 210 "ass2.acc"
 printf("Return\n"); 
# line 914 "yygrammar.c"
      } break;
   }
}

expression ()
{
   switch(yyselect()) {
   case 84: {
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
   case 85: {
      conditional_expression();
      } break;
   case 86: {
      unary_expression();
      assignment_operator();
      assignment_expression();
      } break;
   }
}

assignment_operator ()
{
   switch(yyselect()) {
   case 87: {
      get_lexval();
      } break;
   case 88: {
      get_lexval();
      } break;
   }
}

conditional_expression ()
{
   switch(yyselect()) {
   case 89: {
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
   case 90: {
      conditional_expression();
      } break;
   }
}

logical_OR_expression ()
{
   switch(yyselect()) {
   case 91: {
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
   case 92: {
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
   case 93: {
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
   case 94: {
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
   case 95: {
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
   case 96: {
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
   case 97: {
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
   case 98: {
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
   case 99: {
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
   case 100: {
      unary_expression();
      } break;
   case 101: {
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
   case 102: {
      postfix_expression();
      } break;
   case 103: {
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
   case 104: {
      unary_operator();
      cast_expression();
      } break;
   case 105: {
      get_lexval();
      unary_expression();
      } break;
   case 106: {
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
   case 112: {
      get_lexval();
      } break;
   }
}

postfix_expression ()
{
   switch(yyselect()) {
   case 113: {
      primary_expression();
      } break;
   case 114: {
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
   case 115: {
      get_lexval();
      } break;
   case 116: {
      constant();
      } break;
   case 117: {
      get_lexval();
      } break;
   case 118: {
      get_lexval();
      expression();
      get_lexval();
      } break;
   }
}

argument_expression_list ()
{
   switch(yyselect()) {
   case 119: {
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
   case 120: {
      get_lexval();
#line 305 "ass2.acc"
printf("intconst: %lu\n", yylval.i);
# line 1312 "yygrammar.c"
      } break;
   case 121: {
      get_lexval();
      } break;
   case 122: {
      get_lexval();
      } break;
   case 123: {
      get_lexval();
#line 305 "ass2.acc"
 printf("Constant\n"); 
# line 1324 "yygrammar.c"
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
int c_length = 1128;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 124,
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
/* 25 */ 330,
/* 26 */ 37,
/* 27 */ 642,
/* 28 */ -23,
/* 29 */ 5,
/* 30 */ 34,
/* 31 */ 69,
/* 32 */ -30,
/* 33 */ 125,
/* 34 */ 0,
/* 35 */ -30,
/* 36 */ 203,
/* 37 */ 41,
/* 38 */ 57,
/* 39 */ -37,
/* 40 */ 126,
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
/* 53 */ 127,
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
/* 65 */ 128,
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
/* 77 */ 129,
/* 78 */ 82,
/* 79 */ 113,
/* 80 */ -74,
/* 81 */ 130,
/* 82 */ 0,
/* 83 */ 157,
/* 84 */ -74,
/* 85 */ 131,
/* 86 */ 90,
/* 87 */ 69,
/* 88 */ -86,
/* 89 */ 132,
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
/* 154 */ 284,
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
/* 181 */ 133,
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
/* 201 */ 134,
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
/* 214 */ 135,
/* 215 */ 0,
/* 216 */ -210,
/* 217 */ 210,
/* 218 */ 0,
/* 219 */ 223,
/* 220 */ 480,
/* 221 */ -218,
/* 222 */ 33,
/* 223 */ 228,
/* 224 */ 330,
/* 225 */ 50061,
/* 226 */ -223,
/* 227 */ 136,
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
/* 245 */ 137,
/* 246 */ 0,
/* 247 */ 157,
/* 248 */ -242,
/* 249 */ 138,
/* 250 */ 254,
/* 251 */ 237,
/* 252 */ -250,
/* 253 */ 139,
/* 254 */ 0,
/* 255 */ -250,
/* 256 */ 212,
/* 257 */ 261,
/* 258 */ 267,
/* 259 */ -257,
/* 260 */ 36,
/* 261 */ 0,
/* 262 */ 257,
/* 263 */ 50044,
/* 264 */ 267,
/* 265 */ -257,
/* 266 */ 37,
/* 267 */ 271,
/* 268 */ 330,
/* 269 */ -267,
/* 270 */ 38,
/* 271 */ 0,
/* 272 */ 277,
/* 273 */ 50058,
/* 274 */ 826,
/* 275 */ -267,
/* 276 */ 39,
/* 277 */ 281,
/* 278 */ 330,
/* 279 */ -277,
/* 280 */ 140,
/* 281 */ 0,
/* 282 */ -277,
/* 283 */ 213,
/* 284 */ 292,
/* 285 */ 50266,
/* 286 */ 297,
/* 287 */ 50123,
/* 288 */ 304,
/* 289 */ 50125,
/* 290 */ -284,
/* 291 */ 40,
/* 292 */ 0,
/* 293 */ 50266,
/* 294 */ 50299,
/* 295 */ -284,
/* 296 */ 41,
/* 297 */ 301,
/* 298 */ 50299,
/* 299 */ -297,
/* 300 */ 141,
/* 301 */ 0,
/* 302 */ -297,
/* 303 */ 214,
/* 304 */ 0,
/* 305 */ 309,
/* 306 */ 317,
/* 307 */ -304,
/* 308 */ 42,
/* 309 */ 314,
/* 310 */ 304,
/* 311 */ 50044,
/* 312 */ -309,
/* 313 */ 142,
/* 314 */ 0,
/* 315 */ -309,
/* 316 */ 215,
/* 317 */ 0,
/* 318 */ 50299,
/* 319 */ 322,
/* 320 */ -317,
/* 321 */ 43,
/* 322 */ 327,
/* 323 */ 50061,
/* 324 */ 826,
/* 325 */ -322,
/* 326 */ 143,
/* 327 */ 0,
/* 328 */ -322,
/* 329 */ 216,
/* 330 */ 0,
/* 331 */ 335,
/* 332 */ 342,
/* 333 */ -330,
/* 334 */ 44,
/* 335 */ 339,
/* 336 */ 389,
/* 337 */ -335,
/* 338 */ 144,
/* 339 */ 0,
/* 340 */ -335,
/* 341 */ 217,
/* 342 */ 346,
/* 343 */ 50299,
/* 344 */ -342,
/* 345 */ 45,
/* 346 */ 352,
/* 347 */ 50040,
/* 348 */ 330,
/* 349 */ 50041,
/* 350 */ -342,
/* 351 */ 46,
/* 352 */ 0,
/* 353 */ 342,
/* 354 */ 357,
/* 355 */ -342,
/* 356 */ 47,
/* 357 */ 363,
/* 358 */ 50091,
/* 359 */ 375,
/* 360 */ 50093,
/* 361 */ -357,
/* 362 */ 146,
/* 363 */ 369,
/* 364 */ 50040,
/* 365 */ 421,
/* 366 */ 50041,
/* 367 */ -357,
/* 368 */ 147,
/* 369 */ 0,
/* 370 */ 50040,
/* 371 */ 382,
/* 372 */ 50041,
/* 373 */ -357,
/* 374 */ 149,
/* 375 */ 379,
/* 376 */ 826,
/* 377 */ -375,
/* 378 */ 145,
/* 379 */ 0,
/* 380 */ -375,
/* 381 */ 218,
/* 382 */ 386,
/* 383 */ 467,
/* 384 */ -382,
/* 385 */ 148,
/* 386 */ 0,
/* 387 */ -382,
/* 388 */ 219,
/* 389 */ 0,
/* 390 */ 50042,
/* 391 */ 395,
/* 392 */ 402,
/* 393 */ -389,
/* 394 */ 48,
/* 395 */ 399,
/* 396 */ 409,
/* 397 */ -395,
/* 398 */ 150,
/* 399 */ 0,
/* 400 */ -395,
/* 401 */ 220,
/* 402 */ 406,
/* 403 */ 389,
/* 404 */ -402,
/* 405 */ 151,
/* 406 */ 0,
/* 407 */ -402,
/* 408 */ 221,
/* 409 */ 0,
/* 410 */ 414,
/* 411 */ 157,
/* 412 */ -409,
/* 413 */ 49,
/* 414 */ 418,
/* 415 */ 409,
/* 416 */ -414,
/* 417 */ 152,
/* 418 */ 0,
/* 419 */ -414,
/* 420 */ 222,
/* 421 */ 0,
/* 422 */ 434,
/* 423 */ 426,
/* 424 */ -421,
/* 425 */ 50,
/* 426 */ 431,
/* 427 */ 50044,
/* 428 */ 50290,
/* 429 */ -426,
/* 430 */ 153,
/* 431 */ 0,
/* 432 */ -426,
/* 433 */ 223,
/* 434 */ 0,
/* 435 */ 439,
/* 436 */ 447,
/* 437 */ -434,
/* 438 */ 51,
/* 439 */ 444,
/* 440 */ 434,
/* 441 */ 50044,
/* 442 */ -439,
/* 443 */ 154,
/* 444 */ 0,
/* 445 */ -439,
/* 446 */ 224,
/* 447 */ 0,
/* 448 */ 69,
/* 449 */ 452,
/* 450 */ -447,
/* 451 */ 52,
/* 452 */ 456,
/* 453 */ 330,
/* 454 */ -452,
/* 455 */ 155,
/* 456 */ 0,
/* 457 */ 460,
/* 458 */ -452,
/* 459 */ 157,
/* 460 */ 464,
/* 461 */ 523,
/* 462 */ -460,
/* 463 */ 156,
/* 464 */ 0,
/* 465 */ -460,
/* 466 */ 225,
/* 467 */ 0,
/* 468 */ 472,
/* 469 */ 50299,
/* 470 */ -467,
/* 471 */ 53,
/* 472 */ 477,
/* 473 */ 467,
/* 474 */ 50044,
/* 475 */ -472,
/* 476 */ 158,
/* 477 */ 0,
/* 478 */ -472,
/* 479 */ 226,
/* 480 */ 484,
/* 481 */ 793,
/* 482 */ -480,
/* 483 */ 54,
/* 484 */ 0,
/* 485 */ 50123,
/* 486 */ 498,
/* 487 */ 491,
/* 488 */ 50125,
/* 489 */ -480,
/* 490 */ 55,
/* 491 */ 495,
/* 492 */ 50044,
/* 493 */ -491,
/* 494 */ 159,
/* 495 */ 0,
/* 496 */ -491,
/* 497 */ 227,
/* 498 */ 0,
/* 499 */ 503,
/* 500 */ 480,
/* 501 */ -498,
/* 502 */ 56,
/* 503 */ 508,
/* 504 */ 498,
/* 505 */ 50044,
/* 506 */ -503,
/* 507 */ 160,
/* 508 */ 0,
/* 509 */ -503,
/* 510 */ 228,
/* 511 */ 0,
/* 512 */ 237,
/* 513 */ 516,
/* 514 */ -511,
/* 515 */ 57,
/* 516 */ 520,
/* 517 */ 523,
/* 518 */ -516,
/* 519 */ 161,
/* 520 */ 0,
/* 521 */ -516,
/* 522 */ 229,
/* 523 */ 527,
/* 524 */ 389,
/* 525 */ -523,
/* 526 */ 58,
/* 527 */ 0,
/* 528 */ 532,
/* 529 */ 539,
/* 530 */ -523,
/* 531 */ 59,
/* 532 */ 536,
/* 533 */ 389,
/* 534 */ -532,
/* 535 */ 162,
/* 536 */ 0,
/* 537 */ -532,
/* 538 */ 230,
/* 539 */ 545,
/* 540 */ 50040,
/* 541 */ 523,
/* 542 */ 50041,
/* 543 */ -539,
/* 544 */ 60,
/* 545 */ 0,
/* 546 */ 550,
/* 547 */ 557,
/* 548 */ -539,
/* 549 */ 61,
/* 550 */ 554,
/* 551 */ 539,
/* 552 */ -550,
/* 553 */ 163,
/* 554 */ 0,
/* 555 */ -550,
/* 556 */ 231,
/* 557 */ 563,
/* 558 */ 50091,
/* 559 */ 569,
/* 560 */ 50093,
/* 561 */ -557,
/* 562 */ 165,
/* 563 */ 0,
/* 564 */ 50040,
/* 565 */ 576,
/* 566 */ 50041,
/* 567 */ -557,
/* 568 */ 167,
/* 569 */ 573,
/* 570 */ 826,
/* 571 */ -569,
/* 572 */ 164,
/* 573 */ 0,
/* 574 */ -569,
/* 575 */ 232,
/* 576 */ 580,
/* 577 */ 421,
/* 578 */ -576,
/* 579 */ 166,
/* 580 */ 0,
/* 581 */ -576,
/* 582 */ 233,
/* 583 */ 0,
/* 584 */ 50299,
/* 585 */ -583,
/* 586 */ 62,
/* 587 */ 591,
/* 588 */ 611,
/* 589 */ -587,
/* 590 */ 63,
/* 591 */ 595,
/* 592 */ 630,
/* 593 */ -587,
/* 594 */ 64,
/* 595 */ 599,
/* 596 */ 642,
/* 597 */ -587,
/* 598 */ 65,
/* 599 */ 603,
/* 600 */ 675,
/* 601 */ -587,
/* 602 */ 66,
/* 603 */ 607,
/* 604 */ 700,
/* 605 */ -587,
/* 606 */ 67,
/* 607 */ 0,
/* 608 */ 751,
/* 609 */ -587,
/* 610 */ 68,
/* 611 */ 617,
/* 612 */ 50299,
/* 613 */ 50058,
/* 614 */ 587,
/* 615 */ -611,
/* 616 */ 69,
/* 617 */ 624,
/* 618 */ 50258,
/* 619 */ 826,
/* 620 */ 50058,
/* 621 */ 587,
/* 622 */ -611,
/* 623 */ 70,
/* 624 */ 0,
/* 625 */ 50262,
/* 626 */ 50058,
/* 627 */ 587,
/* 628 */ -611,
/* 629 */ 71,
/* 630 */ 0,
/* 631 */ 635,
/* 632 */ 50059,
/* 633 */ -630,
/* 634 */ 72,
/* 635 */ 639,
/* 636 */ 780,
/* 637 */ -635,
/* 638 */ 168,
/* 639 */ 0,
/* 640 */ -635,
/* 641 */ 234,
/* 642 */ 0,
/* 643 */ 50123,
/* 644 */ 649,
/* 645 */ 656,
/* 646 */ 50125,
/* 647 */ -642,
/* 648 */ 73,
/* 649 */ 653,
/* 650 */ 57,
/* 651 */ -649,
/* 652 */ 169,
/* 653 */ 0,
/* 654 */ -649,
/* 655 */ 235,
/* 656 */ 660,
/* 657 */ 663,
/* 658 */ -656,
/* 659 */ 170,
/* 660 */ 0,
/* 661 */ -656,
/* 662 */ 236,
/* 663 */ 0,
/* 664 */ 668,
/* 665 */ 587,
/* 666 */ -663,
/* 667 */ 74,
/* 668 */ 672,
/* 669 */ 663,
/* 670 */ -668,
/* 671 */ 171,
/* 672 */ 0,
/* 673 */ -668,
/* 674 */ 237,
/* 675 */ 684,
/* 676 */ 50271,
/* 677 */ 50040,
/* 678 */ 780,
/* 679 */ 50041,
/* 680 */ 587,
/* 681 */ 692,
/* 682 */ -675,
/* 683 */ 75,
/* 684 */ 0,
/* 685 */ 50281,
/* 686 */ 50040,
/* 687 */ 780,
/* 688 */ 50041,
/* 689 */ 587,
/* 690 */ -675,
/* 691 */ 76,
/* 692 */ 697,
/* 693 */ 50265,
/* 694 */ 587,
/* 695 */ -692,
/* 696 */ 172,
/* 697 */ 0,
/* 698 */ -692,
/* 699 */ 238,
/* 700 */ 708,
/* 701 */ 50287,
/* 702 */ 50040,
/* 703 */ 780,
/* 704 */ 50041,
/* 705 */ 587,
/* 706 */ -700,
/* 707 */ 77,
/* 708 */ 718,
/* 709 */ 50263,
/* 710 */ 587,
/* 711 */ 50287,
/* 712 */ 50040,
/* 713 */ 780,
/* 714 */ 50041,
/* 715 */ 50059,
/* 716 */ -700,
/* 717 */ 78,
/* 718 */ 0,
/* 719 */ 50269,
/* 720 */ 50040,
/* 721 */ 730,
/* 722 */ 50059,
/* 723 */ 737,
/* 724 */ 50059,
/* 725 */ 744,
/* 726 */ 50041,
/* 727 */ 587,
/* 728 */ -700,
/* 729 */ 79,
/* 730 */ 734,
/* 731 */ 780,
/* 732 */ -730,
/* 733 */ 173,
/* 734 */ 0,
/* 735 */ -730,
/* 736 */ 239,
/* 737 */ 741,
/* 738 */ 780,
/* 739 */ -737,
/* 740 */ 174,
/* 741 */ 0,
/* 742 */ -737,
/* 743 */ 240,
/* 744 */ 748,
/* 745 */ 780,
/* 746 */ -744,
/* 747 */ 175,
/* 748 */ 0,
/* 749 */ -744,
/* 750 */ 241,
/* 751 */ 757,
/* 752 */ 50270,
/* 753 */ 50299,
/* 754 */ 50059,
/* 755 */ -751,
/* 756 */ 80,
/* 757 */ 762,
/* 758 */ 50261,
/* 759 */ 50059,
/* 760 */ -751,
/* 761 */ 81,
/* 762 */ 767,
/* 763 */ 50257,
/* 764 */ 50059,
/* 765 */ -751,
/* 766 */ 82,
/* 767 */ 0,
/* 768 */ 50275,
/* 769 */ 773,
/* 770 */ 50059,
/* 771 */ -751,
/* 772 */ 83,
/* 773 */ 777,
/* 774 */ 780,
/* 775 */ -773,
/* 776 */ 176,
/* 777 */ 0,
/* 778 */ -773,
/* 779 */ 242,
/* 780 */ 0,
/* 781 */ 785,
/* 782 */ 793,
/* 783 */ -780,
/* 784 */ 84,
/* 785 */ 790,
/* 786 */ 780,
/* 787 */ 50044,
/* 788 */ -785,
/* 789 */ 177,
/* 790 */ 0,
/* 791 */ -785,
/* 792 */ 243,
/* 793 */ 797,
/* 794 */ 811,
/* 795 */ -793,
/* 796 */ 85,
/* 797 */ 0,
/* 798 */ 978,
/* 799 */ 803,
/* 800 */ 793,
/* 801 */ -793,
/* 802 */ 86,
/* 803 */ 807,
/* 804 */ 50291,
/* 805 */ -803,
/* 806 */ 87,
/* 807 */ 0,
/* 808 */ 50061,
/* 809 */ -803,
/* 810 */ 88,
/* 811 */ 0,
/* 812 */ 830,
/* 813 */ 816,
/* 814 */ -811,
/* 815 */ 89,
/* 816 */ 823,
/* 817 */ 50063,
/* 818 */ 780,
/* 819 */ 50058,
/* 820 */ 811,
/* 821 */ -816,
/* 822 */ 178,
/* 823 */ 0,
/* 824 */ -816,
/* 825 */ 244,
/* 826 */ 0,
/* 827 */ 811,
/* 828 */ -826,
/* 829 */ 90,
/* 830 */ 0,
/* 831 */ 835,
/* 832 */ 843,
/* 833 */ -830,
/* 834 */ 91,
/* 835 */ 840,
/* 836 */ 830,
/* 837 */ 50297,
/* 838 */ -835,
/* 839 */ 179,
/* 840 */ 0,
/* 841 */ -835,
/* 842 */ 245,
/* 843 */ 0,
/* 844 */ 848,
/* 845 */ 856,
/* 846 */ -843,
/* 847 */ 92,
/* 848 */ 853,
/* 849 */ 843,
/* 850 */ 50298,
/* 851 */ -848,
/* 852 */ 180,
/* 853 */ 0,
/* 854 */ -848,
/* 855 */ 246,
/* 856 */ 0,
/* 857 */ 861,
/* 858 */ 869,
/* 859 */ -856,
/* 860 */ 93,
/* 861 */ 866,
/* 862 */ 856,
/* 863 */ 50301,
/* 864 */ -861,
/* 865 */ 181,
/* 866 */ 0,
/* 867 */ -861,
/* 868 */ 247,
/* 869 */ 0,
/* 870 */ 874,
/* 871 */ 882,
/* 872 */ -869,
/* 873 */ 94,
/* 874 */ 879,
/* 875 */ 869,
/* 876 */ 50303,
/* 877 */ -874,
/* 878 */ 182,
/* 879 */ 0,
/* 880 */ -874,
/* 881 */ 248,
/* 882 */ 0,
/* 883 */ 887,
/* 884 */ 895,
/* 885 */ -882,
/* 886 */ 95,
/* 887 */ 892,
/* 888 */ 882,
/* 889 */ 50302,
/* 890 */ -887,
/* 891 */ 183,
/* 892 */ 0,
/* 893 */ -887,
/* 894 */ 249,
/* 895 */ 0,
/* 896 */ 900,
/* 897 */ 908,
/* 898 */ -895,
/* 899 */ 96,
/* 900 */ 905,
/* 901 */ 895,
/* 902 */ 50292,
/* 903 */ -900,
/* 904 */ 184,
/* 905 */ 0,
/* 906 */ -900,
/* 907 */ 250,
/* 908 */ 0,
/* 909 */ 913,
/* 910 */ 921,
/* 911 */ -908,
/* 912 */ 97,
/* 913 */ 918,
/* 914 */ 908,
/* 915 */ 50304,
/* 916 */ -913,
/* 917 */ 185,
/* 918 */ 0,
/* 919 */ -913,
/* 920 */ 251,
/* 921 */ 0,
/* 922 */ 926,
/* 923 */ 942,
/* 924 */ -921,
/* 925 */ 98,
/* 926 */ 931,
/* 927 */ 921,
/* 928 */ 934,
/* 929 */ -926,
/* 930 */ 188,
/* 931 */ 0,
/* 932 */ -926,
/* 933 */ 252,
/* 934 */ 938,
/* 935 */ 50043,
/* 936 */ -934,
/* 937 */ 186,
/* 938 */ 0,
/* 939 */ 50045,
/* 940 */ -934,
/* 941 */ 187,
/* 942 */ 0,
/* 943 */ 947,
/* 944 */ 967,
/* 945 */ -942,
/* 946 */ 99,
/* 947 */ 952,
/* 948 */ 942,
/* 949 */ 955,
/* 950 */ -947,
/* 951 */ 192,
/* 952 */ 0,
/* 953 */ -947,
/* 954 */ 253,
/* 955 */ 959,
/* 956 */ 50042,
/* 957 */ -955,
/* 958 */ 189,
/* 959 */ 963,
/* 960 */ 50047,
/* 961 */ -955,
/* 962 */ 190,
/* 963 */ 0,
/* 964 */ 50037,
/* 965 */ -955,
/* 966 */ 191,
/* 967 */ 971,
/* 968 */ 978,
/* 969 */ -967,
/* 970 */ 100,
/* 971 */ 0,
/* 972 */ 50040,
/* 973 */ 511,
/* 974 */ 50041,
/* 975 */ 967,
/* 976 */ -967,
/* 977 */ 101,
/* 978 */ 982,
/* 979 */ 1036,
/* 980 */ -978,
/* 981 */ 102,
/* 982 */ 987,
/* 983 */ 1004,
/* 984 */ 978,
/* 985 */ -978,
/* 986 */ 103,
/* 987 */ 992,
/* 988 */ 1012,
/* 989 */ 967,
/* 990 */ -978,
/* 991 */ 104,
/* 992 */ 997,
/* 993 */ 50278,
/* 994 */ 978,
/* 995 */ -978,
/* 996 */ 105,
/* 997 */ 0,
/* 998 */ 50278,
/* 999 */ 50040,
/* 1000 */ 511,
/* 1001 */ 50041,
/* 1002 */ -978,
/* 1003 */ 106,
/* 1004 */ 1008,
/* 1005 */ 50294,
/* 1006 */ -1004,
/* 1007 */ 193,
/* 1008 */ 0,
/* 1009 */ 50295,
/* 1010 */ -1004,
/* 1011 */ 194,
/* 1012 */ 1016,
/* 1013 */ 50038,
/* 1014 */ -1012,
/* 1015 */ 107,
/* 1016 */ 1020,
/* 1017 */ 50042,
/* 1018 */ -1012,
/* 1019 */ 108,
/* 1020 */ 1024,
/* 1021 */ 50043,
/* 1022 */ -1012,
/* 1023 */ 109,
/* 1024 */ 1028,
/* 1025 */ 50045,
/* 1026 */ -1012,
/* 1027 */ 110,
/* 1028 */ 1032,
/* 1029 */ 50126,
/* 1030 */ -1012,
/* 1031 */ 111,
/* 1032 */ 0,
/* 1033 */ 50033,
/* 1034 */ -1012,
/* 1035 */ 112,
/* 1036 */ 1040,
/* 1037 */ 1082,
/* 1038 */ -1036,
/* 1039 */ 113,
/* 1040 */ 0,
/* 1041 */ 1036,
/* 1042 */ 1045,
/* 1043 */ -1036,
/* 1044 */ 114,
/* 1045 */ 1051,
/* 1046 */ 50091,
/* 1047 */ 780,
/* 1048 */ 50093,
/* 1049 */ -1045,
/* 1050 */ 195,
/* 1051 */ 1057,
/* 1052 */ 50040,
/* 1053 */ 1075,
/* 1054 */ 50041,
/* 1055 */ -1045,
/* 1056 */ 197,
/* 1057 */ 1062,
/* 1058 */ 50046,
/* 1059 */ 50299,
/* 1060 */ -1045,
/* 1061 */ 198,
/* 1062 */ 1067,
/* 1063 */ 50296,
/* 1064 */ 50299,
/* 1065 */ -1045,
/* 1066 */ 199,
/* 1067 */ 1071,
/* 1068 */ 50294,
/* 1069 */ -1045,
/* 1070 */ 200,
/* 1071 */ 0,
/* 1072 */ 50295,
/* 1073 */ -1045,
/* 1074 */ 201,
/* 1075 */ 1079,
/* 1076 */ 1100,
/* 1077 */ -1075,
/* 1078 */ 196,
/* 1079 */ 0,
/* 1080 */ -1075,
/* 1081 */ 254,
/* 1082 */ 1086,
/* 1083 */ 50299,
/* 1084 */ -1082,
/* 1085 */ 115,
/* 1086 */ 1090,
/* 1087 */ 1113,
/* 1088 */ -1082,
/* 1089 */ 116,
/* 1090 */ 1094,
/* 1091 */ 50289,
/* 1092 */ -1082,
/* 1093 */ 117,
/* 1094 */ 0,
/* 1095 */ 50040,
/* 1096 */ 780,
/* 1097 */ 50041,
/* 1098 */ -1082,
/* 1099 */ 118,
/* 1100 */ 0,
/* 1101 */ 1105,
/* 1102 */ 793,
/* 1103 */ -1100,
/* 1104 */ 119,
/* 1105 */ 1110,
/* 1106 */ 1100,
/* 1107 */ 50044,
/* 1108 */ -1105,
/* 1109 */ 202,
/* 1110 */ 0,
/* 1111 */ -1105,
/* 1112 */ 255,
/* 1113 */ 1117,
/* 1114 */ 50308,
/* 1115 */ -1113,
/* 1116 */ 120,
/* 1117 */ 1121,
/* 1118 */ 50306,
/* 1119 */ -1113,
/* 1120 */ 121,
/* 1121 */ 1125,
/* 1122 */ 50307,
/* 1123 */ -1113,
/* 1124 */ 122,
/* 1125 */ 0,
/* 1126 */ 50299,
/* 1127 */ -1113,
/* 1128 */ 123,
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
/* 257 */ 261,
/* 258 */ 1,
/* 259 */ -257,
/* 260 */ 1,
/* 261 */ 0,
/* 262 */ 1,
/* 263 */ 50044,
/* 264 */ 1,
/* 265 */ -257,
/* 266 */ 2,
/* 267 */ 271,
/* 268 */ 1,
/* 269 */ -267,
/* 270 */ 1,
/* 271 */ 0,
/* 272 */ 1,
/* 273 */ 50058,
/* 274 */ 1,
/* 275 */ -267,
/* 276 */ 2,
/* 277 */ 281,
/* 278 */ 1,
/* 279 */ -277,
/* 280 */ 1,
/* 281 */ 0,
/* 282 */ -277,
/* 283 */ 2,
/* 284 */ 292,
/* 285 */ 50266,
/* 286 */ 1,
/* 287 */ 50123,
/* 288 */ 1,
/* 289 */ 50125,
/* 290 */ -284,
/* 291 */ 1,
/* 292 */ 0,
/* 293 */ 50266,
/* 294 */ 50299,
/* 295 */ -284,
/* 296 */ 2,
/* 297 */ 301,
/* 298 */ 50299,
/* 299 */ -297,
/* 300 */ 1,
/* 301 */ 0,
/* 302 */ -297,
/* 303 */ 2,
/* 304 */ 0,
/* 305 */ 1,
/* 306 */ 1,
/* 307 */ -304,
/* 308 */ 1,
/* 309 */ 314,
/* 310 */ 1,
/* 311 */ 50044,
/* 312 */ -309,
/* 313 */ 1,
/* 314 */ 0,
/* 315 */ -309,
/* 316 */ 2,
/* 317 */ 0,
/* 318 */ 50299,
/* 319 */ 1,
/* 320 */ -317,
/* 321 */ 1,
/* 322 */ 327,
/* 323 */ 50061,
/* 324 */ 1,
/* 325 */ -322,
/* 326 */ 1,
/* 327 */ 0,
/* 328 */ -322,
/* 329 */ 2,
/* 330 */ 0,
/* 331 */ 1,
/* 332 */ 1,
/* 333 */ -330,
/* 334 */ 1,
/* 335 */ 339,
/* 336 */ 1,
/* 337 */ -335,
/* 338 */ 1,
/* 339 */ 0,
/* 340 */ -335,
/* 341 */ 2,
/* 342 */ 346,
/* 343 */ 50299,
/* 344 */ -342,
/* 345 */ 1,
/* 346 */ 352,
/* 347 */ 50040,
/* 348 */ 1,
/* 349 */ 50041,
/* 350 */ -342,
/* 351 */ 2,
/* 352 */ 0,
/* 353 */ 1,
/* 354 */ 1,
/* 355 */ -342,
/* 356 */ 3,
/* 357 */ 363,
/* 358 */ 50091,
/* 359 */ 1,
/* 360 */ 50093,
/* 361 */ -357,
/* 362 */ 1,
/* 363 */ 369,
/* 364 */ 50040,
/* 365 */ 1,
/* 366 */ 50041,
/* 367 */ -357,
/* 368 */ 2,
/* 369 */ 0,
/* 370 */ 50040,
/* 371 */ 1,
/* 372 */ 50041,
/* 373 */ -357,
/* 374 */ 3,
/* 375 */ 379,
/* 376 */ 1,
/* 377 */ -375,
/* 378 */ 1,
/* 379 */ 0,
/* 380 */ -375,
/* 381 */ 2,
/* 382 */ 386,
/* 383 */ 1,
/* 384 */ -382,
/* 385 */ 1,
/* 386 */ 0,
/* 387 */ -382,
/* 388 */ 2,
/* 389 */ 0,
/* 390 */ 50042,
/* 391 */ 1,
/* 392 */ 1,
/* 393 */ -389,
/* 394 */ 1,
/* 395 */ 399,
/* 396 */ 1,
/* 397 */ -395,
/* 398 */ 1,
/* 399 */ 0,
/* 400 */ -395,
/* 401 */ 2,
/* 402 */ 406,
/* 403 */ 1,
/* 404 */ -402,
/* 405 */ 1,
/* 406 */ 0,
/* 407 */ -402,
/* 408 */ 2,
/* 409 */ 0,
/* 410 */ 1,
/* 411 */ 1,
/* 412 */ -409,
/* 413 */ 1,
/* 414 */ 418,
/* 415 */ 1,
/* 416 */ -414,
/* 417 */ 1,
/* 418 */ 0,
/* 419 */ -414,
/* 420 */ 2,
/* 421 */ 0,
/* 422 */ 1,
/* 423 */ 1,
/* 424 */ -421,
/* 425 */ 1,
/* 426 */ 431,
/* 427 */ 50044,
/* 428 */ 50290,
/* 429 */ -426,
/* 430 */ 1,
/* 431 */ 0,
/* 432 */ -426,
/* 433 */ 2,
/* 434 */ 0,
/* 435 */ 1,
/* 436 */ 1,
/* 437 */ -434,
/* 438 */ 1,
/* 439 */ 444,
/* 440 */ 1,
/* 441 */ 50044,
/* 442 */ -439,
/* 443 */ 1,
/* 444 */ 0,
/* 445 */ -439,
/* 446 */ 2,
/* 447 */ 0,
/* 448 */ 1,
/* 449 */ 1,
/* 450 */ -447,
/* 451 */ 1,
/* 452 */ 456,
/* 453 */ 1,
/* 454 */ -452,
/* 455 */ 1,
/* 456 */ 0,
/* 457 */ 1,
/* 458 */ -452,
/* 459 */ 2,
/* 460 */ 464,
/* 461 */ 1,
/* 462 */ -460,
/* 463 */ 1,
/* 464 */ 0,
/* 465 */ -460,
/* 466 */ 2,
/* 467 */ 0,
/* 468 */ 1,
/* 469 */ 50299,
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
/* 480 */ 484,
/* 481 */ 1,
/* 482 */ -480,
/* 483 */ 1,
/* 484 */ 0,
/* 485 */ 50123,
/* 486 */ 1,
/* 487 */ 1,
/* 488 */ 50125,
/* 489 */ -480,
/* 490 */ 2,
/* 491 */ 495,
/* 492 */ 50044,
/* 493 */ -491,
/* 494 */ 1,
/* 495 */ 0,
/* 496 */ -491,
/* 497 */ 2,
/* 498 */ 0,
/* 499 */ 1,
/* 500 */ 1,
/* 501 */ -498,
/* 502 */ 1,
/* 503 */ 508,
/* 504 */ 1,
/* 505 */ 50044,
/* 506 */ -503,
/* 507 */ 1,
/* 508 */ 0,
/* 509 */ -503,
/* 510 */ 2,
/* 511 */ 0,
/* 512 */ 1,
/* 513 */ 1,
/* 514 */ -511,
/* 515 */ 1,
/* 516 */ 520,
/* 517 */ 1,
/* 518 */ -516,
/* 519 */ 1,
/* 520 */ 0,
/* 521 */ -516,
/* 522 */ 2,
/* 523 */ 527,
/* 524 */ 1,
/* 525 */ -523,
/* 526 */ 1,
/* 527 */ 0,
/* 528 */ 1,
/* 529 */ 1,
/* 530 */ -523,
/* 531 */ 2,
/* 532 */ 536,
/* 533 */ 1,
/* 534 */ -532,
/* 535 */ 1,
/* 536 */ 0,
/* 537 */ -532,
/* 538 */ 2,
/* 539 */ 545,
/* 540 */ 50040,
/* 541 */ 1,
/* 542 */ 50041,
/* 543 */ -539,
/* 544 */ 1,
/* 545 */ 0,
/* 546 */ 1,
/* 547 */ 1,
/* 548 */ -539,
/* 549 */ 2,
/* 550 */ 554,
/* 551 */ 1,
/* 552 */ -550,
/* 553 */ 1,
/* 554 */ 0,
/* 555 */ -550,
/* 556 */ 2,
/* 557 */ 563,
/* 558 */ 50091,
/* 559 */ 1,
/* 560 */ 50093,
/* 561 */ -557,
/* 562 */ 1,
/* 563 */ 0,
/* 564 */ 50040,
/* 565 */ 1,
/* 566 */ 50041,
/* 567 */ -557,
/* 568 */ 2,
/* 569 */ 573,
/* 570 */ 1,
/* 571 */ -569,
/* 572 */ 1,
/* 573 */ 0,
/* 574 */ -569,
/* 575 */ 2,
/* 576 */ 580,
/* 577 */ 1,
/* 578 */ -576,
/* 579 */ 1,
/* 580 */ 0,
/* 581 */ -576,
/* 582 */ 2,
/* 583 */ 0,
/* 584 */ 50299,
/* 585 */ -583,
/* 586 */ 1,
/* 587 */ 591,
/* 588 */ 1,
/* 589 */ -587,
/* 590 */ 1,
/* 591 */ 595,
/* 592 */ 1,
/* 593 */ -587,
/* 594 */ 2,
/* 595 */ 599,
/* 596 */ 1,
/* 597 */ -587,
/* 598 */ 3,
/* 599 */ 603,
/* 600 */ 1,
/* 601 */ -587,
/* 602 */ 4,
/* 603 */ 607,
/* 604 */ 1,
/* 605 */ -587,
/* 606 */ 5,
/* 607 */ 0,
/* 608 */ 1,
/* 609 */ -587,
/* 610 */ 6,
/* 611 */ 617,
/* 612 */ 50299,
/* 613 */ 50058,
/* 614 */ 1,
/* 615 */ -611,
/* 616 */ 1,
/* 617 */ 624,
/* 618 */ 50258,
/* 619 */ 1,
/* 620 */ 50058,
/* 621 */ 1,
/* 622 */ -611,
/* 623 */ 2,
/* 624 */ 0,
/* 625 */ 50262,
/* 626 */ 50058,
/* 627 */ 1,
/* 628 */ -611,
/* 629 */ 3,
/* 630 */ 0,
/* 631 */ 1,
/* 632 */ 50059,
/* 633 */ -630,
/* 634 */ 1,
/* 635 */ 639,
/* 636 */ 1,
/* 637 */ -635,
/* 638 */ 1,
/* 639 */ 0,
/* 640 */ -635,
/* 641 */ 2,
/* 642 */ 0,
/* 643 */ 50123,
/* 644 */ 1,
/* 645 */ 1,
/* 646 */ 50125,
/* 647 */ -642,
/* 648 */ 1,
/* 649 */ 653,
/* 650 */ 1,
/* 651 */ -649,
/* 652 */ 1,
/* 653 */ 0,
/* 654 */ -649,
/* 655 */ 2,
/* 656 */ 660,
/* 657 */ 1,
/* 658 */ -656,
/* 659 */ 1,
/* 660 */ 0,
/* 661 */ -656,
/* 662 */ 2,
/* 663 */ 0,
/* 664 */ 1,
/* 665 */ 1,
/* 666 */ -663,
/* 667 */ 1,
/* 668 */ 672,
/* 669 */ 1,
/* 670 */ -668,
/* 671 */ 1,
/* 672 */ 0,
/* 673 */ -668,
/* 674 */ 2,
/* 675 */ 684,
/* 676 */ 50271,
/* 677 */ 50040,
/* 678 */ 1,
/* 679 */ 50041,
/* 680 */ 1,
/* 681 */ 1,
/* 682 */ -675,
/* 683 */ 1,
/* 684 */ 0,
/* 685 */ 50281,
/* 686 */ 50040,
/* 687 */ 1,
/* 688 */ 50041,
/* 689 */ 1,
/* 690 */ -675,
/* 691 */ 2,
/* 692 */ 697,
/* 693 */ 50265,
/* 694 */ 1,
/* 695 */ -692,
/* 696 */ 1,
/* 697 */ 0,
/* 698 */ -692,
/* 699 */ 2,
/* 700 */ 708,
/* 701 */ 50287,
/* 702 */ 50040,
/* 703 */ 1,
/* 704 */ 50041,
/* 705 */ 1,
/* 706 */ -700,
/* 707 */ 1,
/* 708 */ 718,
/* 709 */ 50263,
/* 710 */ 1,
/* 711 */ 50287,
/* 712 */ 50040,
/* 713 */ 1,
/* 714 */ 50041,
/* 715 */ 50059,
/* 716 */ -700,
/* 717 */ 2,
/* 718 */ 0,
/* 719 */ 50269,
/* 720 */ 50040,
/* 721 */ 1,
/* 722 */ 50059,
/* 723 */ 1,
/* 724 */ 50059,
/* 725 */ 1,
/* 726 */ 50041,
/* 727 */ 1,
/* 728 */ -700,
/* 729 */ 3,
/* 730 */ 734,
/* 731 */ 1,
/* 732 */ -730,
/* 733 */ 1,
/* 734 */ 0,
/* 735 */ -730,
/* 736 */ 2,
/* 737 */ 741,
/* 738 */ 1,
/* 739 */ -737,
/* 740 */ 1,
/* 741 */ 0,
/* 742 */ -737,
/* 743 */ 2,
/* 744 */ 748,
/* 745 */ 1,
/* 746 */ -744,
/* 747 */ 1,
/* 748 */ 0,
/* 749 */ -744,
/* 750 */ 2,
/* 751 */ 757,
/* 752 */ 50270,
/* 753 */ 50299,
/* 754 */ 50059,
/* 755 */ -751,
/* 756 */ 1,
/* 757 */ 762,
/* 758 */ 50261,
/* 759 */ 50059,
/* 760 */ -751,
/* 761 */ 2,
/* 762 */ 767,
/* 763 */ 50257,
/* 764 */ 50059,
/* 765 */ -751,
/* 766 */ 3,
/* 767 */ 0,
/* 768 */ 50275,
/* 769 */ 1,
/* 770 */ 50059,
/* 771 */ -751,
/* 772 */ 4,
/* 773 */ 777,
/* 774 */ 1,
/* 775 */ -773,
/* 776 */ 1,
/* 777 */ 0,
/* 778 */ -773,
/* 779 */ 2,
/* 780 */ 0,
/* 781 */ 1,
/* 782 */ 1,
/* 783 */ -780,
/* 784 */ 1,
/* 785 */ 790,
/* 786 */ 1,
/* 787 */ 50044,
/* 788 */ -785,
/* 789 */ 1,
/* 790 */ 0,
/* 791 */ -785,
/* 792 */ 2,
/* 793 */ 797,
/* 794 */ 1,
/* 795 */ -793,
/* 796 */ 1,
/* 797 */ 0,
/* 798 */ 1,
/* 799 */ 1,
/* 800 */ 1,
/* 801 */ -793,
/* 802 */ 2,
/* 803 */ 807,
/* 804 */ 50291,
/* 805 */ -803,
/* 806 */ 1,
/* 807 */ 0,
/* 808 */ 50061,
/* 809 */ -803,
/* 810 */ 2,
/* 811 */ 0,
/* 812 */ 1,
/* 813 */ 1,
/* 814 */ -811,
/* 815 */ 1,
/* 816 */ 823,
/* 817 */ 50063,
/* 818 */ 1,
/* 819 */ 50058,
/* 820 */ 1,
/* 821 */ -816,
/* 822 */ 1,
/* 823 */ 0,
/* 824 */ -816,
/* 825 */ 2,
/* 826 */ 0,
/* 827 */ 1,
/* 828 */ -826,
/* 829 */ 1,
/* 830 */ 0,
/* 831 */ 1,
/* 832 */ 1,
/* 833 */ -830,
/* 834 */ 1,
/* 835 */ 840,
/* 836 */ 1,
/* 837 */ 50297,
/* 838 */ -835,
/* 839 */ 1,
/* 840 */ 0,
/* 841 */ -835,
/* 842 */ 2,
/* 843 */ 0,
/* 844 */ 1,
/* 845 */ 1,
/* 846 */ -843,
/* 847 */ 1,
/* 848 */ 853,
/* 849 */ 1,
/* 850 */ 50298,
/* 851 */ -848,
/* 852 */ 1,
/* 853 */ 0,
/* 854 */ -848,
/* 855 */ 2,
/* 856 */ 0,
/* 857 */ 1,
/* 858 */ 1,
/* 859 */ -856,
/* 860 */ 1,
/* 861 */ 866,
/* 862 */ 1,
/* 863 */ 50301,
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
/* 876 */ 50303,
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
/* 889 */ 50302,
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
/* 902 */ 50292,
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
/* 915 */ 50304,
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
/* 928 */ 1,
/* 929 */ -926,
/* 930 */ 1,
/* 931 */ 0,
/* 932 */ -926,
/* 933 */ 2,
/* 934 */ 938,
/* 935 */ 50043,
/* 936 */ -934,
/* 937 */ 1,
/* 938 */ 0,
/* 939 */ 50045,
/* 940 */ -934,
/* 941 */ 2,
/* 942 */ 0,
/* 943 */ 1,
/* 944 */ 1,
/* 945 */ -942,
/* 946 */ 1,
/* 947 */ 952,
/* 948 */ 1,
/* 949 */ 1,
/* 950 */ -947,
/* 951 */ 1,
/* 952 */ 0,
/* 953 */ -947,
/* 954 */ 2,
/* 955 */ 959,
/* 956 */ 50042,
/* 957 */ -955,
/* 958 */ 1,
/* 959 */ 963,
/* 960 */ 50047,
/* 961 */ -955,
/* 962 */ 2,
/* 963 */ 0,
/* 964 */ 50037,
/* 965 */ -955,
/* 966 */ 3,
/* 967 */ 971,
/* 968 */ 1,
/* 969 */ -967,
/* 970 */ 1,
/* 971 */ 0,
/* 972 */ 50040,
/* 973 */ 1,
/* 974 */ 50041,
/* 975 */ 1,
/* 976 */ -967,
/* 977 */ 2,
/* 978 */ 982,
/* 979 */ 1,
/* 980 */ -978,
/* 981 */ 1,
/* 982 */ 987,
/* 983 */ 1,
/* 984 */ 1,
/* 985 */ -978,
/* 986 */ 2,
/* 987 */ 992,
/* 988 */ 1,
/* 989 */ 1,
/* 990 */ -978,
/* 991 */ 3,
/* 992 */ 997,
/* 993 */ 50278,
/* 994 */ 1,
/* 995 */ -978,
/* 996 */ 4,
/* 997 */ 0,
/* 998 */ 50278,
/* 999 */ 50040,
/* 1000 */ 1,
/* 1001 */ 50041,
/* 1002 */ -978,
/* 1003 */ 5,
/* 1004 */ 1008,
/* 1005 */ 50294,
/* 1006 */ -1004,
/* 1007 */ 1,
/* 1008 */ 0,
/* 1009 */ 50295,
/* 1010 */ -1004,
/* 1011 */ 2,
/* 1012 */ 1016,
/* 1013 */ 50038,
/* 1014 */ -1012,
/* 1015 */ 1,
/* 1016 */ 1020,
/* 1017 */ 50042,
/* 1018 */ -1012,
/* 1019 */ 2,
/* 1020 */ 1024,
/* 1021 */ 50043,
/* 1022 */ -1012,
/* 1023 */ 3,
/* 1024 */ 1028,
/* 1025 */ 50045,
/* 1026 */ -1012,
/* 1027 */ 4,
/* 1028 */ 1032,
/* 1029 */ 50126,
/* 1030 */ -1012,
/* 1031 */ 5,
/* 1032 */ 0,
/* 1033 */ 50033,
/* 1034 */ -1012,
/* 1035 */ 6,
/* 1036 */ 1040,
/* 1037 */ 1,
/* 1038 */ -1036,
/* 1039 */ 1,
/* 1040 */ 0,
/* 1041 */ 1,
/* 1042 */ 1,
/* 1043 */ -1036,
/* 1044 */ 2,
/* 1045 */ 1051,
/* 1046 */ 50091,
/* 1047 */ 1,
/* 1048 */ 50093,
/* 1049 */ -1045,
/* 1050 */ 1,
/* 1051 */ 1057,
/* 1052 */ 50040,
/* 1053 */ 1,
/* 1054 */ 50041,
/* 1055 */ -1045,
/* 1056 */ 2,
/* 1057 */ 1062,
/* 1058 */ 50046,
/* 1059 */ 50299,
/* 1060 */ -1045,
/* 1061 */ 3,
/* 1062 */ 1067,
/* 1063 */ 50296,
/* 1064 */ 50299,
/* 1065 */ -1045,
/* 1066 */ 4,
/* 1067 */ 1071,
/* 1068 */ 50294,
/* 1069 */ -1045,
/* 1070 */ 5,
/* 1071 */ 0,
/* 1072 */ 50295,
/* 1073 */ -1045,
/* 1074 */ 6,
/* 1075 */ 1079,
/* 1076 */ 1,
/* 1077 */ -1075,
/* 1078 */ 1,
/* 1079 */ 0,
/* 1080 */ -1075,
/* 1081 */ 2,
/* 1082 */ 1086,
/* 1083 */ 50299,
/* 1084 */ -1082,
/* 1085 */ 1,
/* 1086 */ 1090,
/* 1087 */ 1,
/* 1088 */ -1082,
/* 1089 */ 2,
/* 1090 */ 1094,
/* 1091 */ 50289,
/* 1092 */ -1082,
/* 1093 */ 3,
/* 1094 */ 0,
/* 1095 */ 50040,
/* 1096 */ 1,
/* 1097 */ 50041,
/* 1098 */ -1082,
/* 1099 */ 4,
/* 1100 */ 0,
/* 1101 */ 1,
/* 1102 */ 1,
/* 1103 */ -1100,
/* 1104 */ 1,
/* 1105 */ 1110,
/* 1106 */ 1,
/* 1107 */ 50044,
/* 1108 */ -1105,
/* 1109 */ 1,
/* 1110 */ 0,
/* 1111 */ -1105,
/* 1112 */ 2,
/* 1113 */ 1117,
/* 1114 */ 50308,
/* 1115 */ -1113,
/* 1116 */ 1,
/* 1117 */ 1121,
/* 1118 */ 50306,
/* 1119 */ -1113,
/* 1120 */ 2,
/* 1121 */ 1125,
/* 1122 */ 50307,
/* 1123 */ -1113,
/* 1124 */ 3,
/* 1125 */ 0,
/* 1126 */ 50299,
/* 1127 */ -1113,
/* 1128 */ 4,
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
/* 259 */ 9999,
/* 260 */ 85020,
/* 261 */ 9999,
/* 262 */ 86004,
/* 263 */ 9999,
/* 264 */ 86031,
/* 265 */ 9999,
/* 266 */ 86025,
/* 267 */ 9999,
/* 268 */ 90004,
/* 269 */ 9999,
/* 270 */ 90013,
/* 271 */ 9999,
/* 272 */ 91004,
/* 273 */ 9999,
/* 274 */ 91024,
/* 275 */ 9999,
/* 276 */ 91004,
/* 277 */ 9999,
/* 278 */ 91006,
/* 279 */ 9999,
/* 280 */ 91015,
/* 281 */ 9999,
/* 282 */ 9999,
/* 283 */ 91015,
/* 284 */ 9999,
/* 285 */ 9999,
/* 286 */ 95009,
/* 287 */ 9999,
/* 288 */ 95029,
/* 289 */ 9999,
/* 290 */ 9999,
/* 291 */ 95007,
/* 292 */ 9999,
/* 293 */ 9999,
/* 294 */ 9999,
/* 295 */ 9999,
/* 296 */ 96007,
/* 297 */ 9999,
/* 298 */ 9999,
/* 299 */ 9999,
/* 300 */ 95020,
/* 301 */ 9999,
/* 302 */ 9999,
/* 303 */ 95020,
/* 304 */ 9999,
/* 305 */ 100004,
/* 306 */ 100029,
/* 307 */ 9999,
/* 308 */ 100004,
/* 309 */ 9999,
/* 310 */ 100006,
/* 311 */ 9999,
/* 312 */ 9999,
/* 313 */ 100020,
/* 314 */ 9999,
/* 315 */ 9999,
/* 316 */ 100020,
/* 317 */ 9999,
/* 318 */ 9999,
/* 319 */ 104015,
/* 320 */ 9999,
/* 321 */ 104013,
/* 322 */ 9999,
/* 323 */ 9999,
/* 324 */ 104021,
/* 325 */ 9999,
/* 326 */ 104017,
/* 327 */ 9999,
/* 328 */ 9999,
/* 329 */ 104017,
/* 330 */ 9999,
/* 331 */ 108004,
/* 332 */ 108017,
/* 333 */ 9999,
/* 334 */ 108004,
/* 335 */ 9999,
/* 336 */ 108006,
/* 337 */ 9999,
/* 338 */ 108012,
/* 339 */ 9999,
/* 340 */ 9999,
/* 341 */ 108012,
/* 342 */ 9999,
/* 343 */ 9999,
/* 344 */ 9999,
/* 345 */ 112013,
/* 346 */ 9999,
/* 347 */ 9999,
/* 348 */ 113008,
/* 349 */ 9999,
/* 350 */ 9999,
/* 351 */ 113004,
/* 352 */ 9999,
/* 353 */ 114004,
/* 354 */ 114022,
/* 355 */ 9999,
/* 356 */ 114020,
/* 357 */ 9999,
/* 358 */ 9999,
/* 359 */ 114028,
/* 360 */ 9999,
/* 361 */ 9999,
/* 362 */ 114024,
/* 363 */ 9999,
/* 364 */ 9999,
/* 365 */ 114063,
/* 366 */ 9999,
/* 367 */ 9999,
/* 368 */ 114059,
/* 369 */ 9999,
/* 370 */ 9999,
/* 371 */ 114093,
/* 372 */ 9999,
/* 373 */ 9999,
/* 374 */ 114089,
/* 375 */ 9999,
/* 376 */ 114030,
/* 377 */ 9999,
/* 378 */ 114048,
/* 379 */ 9999,
/* 380 */ 9999,
/* 381 */ 114048,
/* 382 */ 9999,
/* 383 */ 114095,
/* 384 */ 9999,
/* 385 */ 114109,
/* 386 */ 9999,
/* 387 */ 9999,
/* 388 */ 114109,
/* 389 */ 9999,
/* 390 */ 9999,
/* 391 */ 118008,
/* 392 */ 118033,
/* 393 */ 9999,
/* 394 */ 118004,
/* 395 */ 9999,
/* 396 */ 118010,
/* 397 */ 9999,
/* 398 */ 118028,
/* 399 */ 9999,
/* 400 */ 9999,
/* 401 */ 118028,
/* 402 */ 9999,
/* 403 */ 118035,
/* 404 */ 9999,
/* 405 */ 118041,
/* 406 */ 9999,
/* 407 */ 9999,
/* 408 */ 118041,
/* 409 */ 9999,
/* 410 */ 122004,
/* 411 */ 122029,
/* 412 */ 9999,
/* 413 */ 122004,
/* 414 */ 9999,
/* 415 */ 122006,
/* 416 */ 9999,
/* 417 */ 122024,
/* 418 */ 9999,
/* 419 */ 9999,
/* 420 */ 122024,
/* 421 */ 9999,
/* 422 */ 126004,
/* 423 */ 126019,
/* 424 */ 9999,
/* 425 */ 126017,
/* 426 */ 9999,
/* 427 */ 9999,
/* 428 */ 9999,
/* 429 */ 9999,
/* 430 */ 126021,
/* 431 */ 9999,
/* 432 */ 9999,
/* 433 */ 126021,
/* 434 */ 9999,
/* 435 */ 130004,
/* 436 */ 130028,
/* 437 */ 9999,
/* 438 */ 130004,
/* 439 */ 9999,
/* 440 */ 130006,
/* 441 */ 9999,
/* 442 */ 9999,
/* 443 */ 130019,
/* 444 */ 9999,
/* 445 */ 9999,
/* 446 */ 130019,
/* 447 */ 9999,
/* 448 */ 134004,
/* 449 */ 134027,
/* 450 */ 9999,
/* 451 */ 134025,
/* 452 */ 9999,
/* 453 */ 134029,
/* 454 */ 9999,
/* 455 */ 134038,
/* 456 */ 9999,
/* 457 */ 134042,
/* 458 */ 9999,
/* 459 */ 134042,
/* 460 */ 9999,
/* 461 */ 134044,
/* 462 */ 9999,
/* 463 */ 134062,
/* 464 */ 9999,
/* 465 */ 9999,
/* 466 */ 134062,
/* 467 */ 9999,
/* 468 */ 138004,
/* 469 */ 9999,
/* 470 */ 9999,
/* 471 */ 138004,
/* 472 */ 9999,
/* 473 */ 138006,
/* 474 */ 9999,
/* 475 */ 9999,
/* 476 */ 138020,
/* 477 */ 9999,
/* 478 */ 9999,
/* 479 */ 138020,
/* 480 */ 9999,
/* 481 */ 142004,
/* 482 */ 9999,
/* 483 */ 142024,
/* 484 */ 9999,
/* 485 */ 9999,
/* 486 */ 143008,
/* 487 */ 143025,
/* 488 */ 9999,
/* 489 */ 9999,
/* 490 */ 143004,
/* 491 */ 9999,
/* 492 */ 9999,
/* 493 */ 9999,
/* 494 */ 143027,
/* 495 */ 9999,
/* 496 */ 9999,
/* 497 */ 143027,
/* 498 */ 9999,
/* 499 */ 147004,
/* 500 */ 147030,
/* 501 */ 9999,
/* 502 */ 147004,
/* 503 */ 9999,
/* 504 */ 147006,
/* 505 */ 9999,
/* 506 */ 9999,
/* 507 */ 147021,
/* 508 */ 9999,
/* 509 */ 9999,
/* 510 */ 147021,
/* 511 */ 9999,
/* 512 */ 151004,
/* 513 */ 151029,
/* 514 */ 9999,
/* 515 */ 151027,
/* 516 */ 9999,
/* 517 */ 151031,
/* 518 */ 9999,
/* 519 */ 151049,
/* 520 */ 9999,
/* 521 */ 9999,
/* 522 */ 151049,
/* 523 */ 9999,
/* 524 */ 155004,
/* 525 */ 9999,
/* 526 */ 155010,
/* 527 */ 9999,
/* 528 */ 156004,
/* 529 */ 156017,
/* 530 */ 9999,
/* 531 */ 156004,
/* 532 */ 9999,
/* 533 */ 156006,
/* 534 */ 9999,
/* 535 */ 156012,
/* 536 */ 9999,
/* 537 */ 9999,
/* 538 */ 156012,
/* 539 */ 9999,
/* 540 */ 9999,
/* 541 */ 160008,
/* 542 */ 9999,
/* 543 */ 9999,
/* 544 */ 160004,
/* 545 */ 9999,
/* 546 */ 161004,
/* 547 */ 161036,
/* 548 */ 9999,
/* 549 */ 161004,
/* 550 */ 9999,
/* 551 */ 161006,
/* 552 */ 9999,
/* 553 */ 161031,
/* 554 */ 9999,
/* 555 */ 9999,
/* 556 */ 161031,
/* 557 */ 9999,
/* 558 */ 9999,
/* 559 */ 161042,
/* 560 */ 9999,
/* 561 */ 9999,
/* 562 */ 161038,
/* 563 */ 9999,
/* 564 */ 9999,
/* 565 */ 161077,
/* 566 */ 9999,
/* 567 */ 9999,
/* 568 */ 161073,
/* 569 */ 9999,
/* 570 */ 161044,
/* 571 */ 9999,
/* 572 */ 161062,
/* 573 */ 9999,
/* 574 */ 9999,
/* 575 */ 161062,
/* 576 */ 9999,
/* 577 */ 161079,
/* 578 */ 9999,
/* 579 */ 161097,
/* 580 */ 9999,
/* 581 */ 9999,
/* 582 */ 161097,
/* 583 */ 9999,
/* 584 */ 9999,
/* 585 */ 9999,
/* 586 */ 165013,
/* 587 */ 9999,
/* 588 */ 169004,
/* 589 */ 9999,
/* 590 */ 169020,
/* 591 */ 9999,
/* 592 */ 170004,
/* 593 */ 9999,
/* 594 */ 170023,
/* 595 */ 9999,
/* 596 */ 171004,
/* 597 */ 9999,
/* 598 */ 171021,
/* 599 */ 9999,
/* 600 */ 172004,
/* 601 */ 9999,
/* 602 */ 172022,
/* 603 */ 9999,
/* 604 */ 173004,
/* 605 */ 9999,
/* 606 */ 173022,
/* 607 */ 9999,
/* 608 */ 174004,
/* 609 */ 9999,
/* 610 */ 174017,
/* 611 */ 9999,
/* 612 */ 9999,
/* 613 */ 9999,
/* 614 */ 178019,
/* 615 */ 9999,
/* 616 */ 178013,
/* 617 */ 9999,
/* 618 */ 9999,
/* 619 */ 179009,
/* 620 */ 9999,
/* 621 */ 179033,
/* 622 */ 9999,
/* 623 */ 179007,
/* 624 */ 9999,
/* 625 */ 9999,
/* 626 */ 9999,
/* 627 */ 180016,
/* 628 */ 9999,
/* 629 */ 180010,
/* 630 */ 9999,
/* 631 */ 184004,
/* 632 */ 9999,
/* 633 */ 9999,
/* 634 */ 184004,
/* 635 */ 9999,
/* 636 */ 184006,
/* 637 */ 9999,
/* 638 */ 184015,
/* 639 */ 9999,
/* 640 */ 9999,
/* 641 */ 184015,
/* 642 */ 9999,
/* 643 */ 9999,
/* 644 */ 188008,
/* 645 */ 188030,
/* 646 */ 9999,
/* 647 */ 9999,
/* 648 */ 188004,
/* 649 */ 9999,
/* 650 */ 188010,
/* 651 */ 9999,
/* 652 */ 188025,
/* 653 */ 9999,
/* 654 */ 9999,
/* 655 */ 188025,
/* 656 */ 9999,
/* 657 */ 188032,
/* 658 */ 9999,
/* 659 */ 188045,
/* 660 */ 9999,
/* 661 */ 9999,
/* 662 */ 188045,
/* 663 */ 9999,
/* 664 */ 192004,
/* 665 */ 192024,
/* 666 */ 9999,
/* 667 */ 192004,
/* 668 */ 9999,
/* 669 */ 192006,
/* 670 */ 9999,
/* 671 */ 192019,
/* 672 */ 9999,
/* 673 */ 9999,
/* 674 */ 192019,
/* 675 */ 9999,
/* 676 */ 9999,
/* 677 */ 9999,
/* 678 */ 196011,
/* 679 */ 9999,
/* 680 */ 196026,
/* 681 */ 196036,
/* 682 */ 9999,
/* 683 */ 196005,
/* 684 */ 9999,
/* 685 */ 9999,
/* 686 */ 9999,
/* 687 */ 197015,
/* 688 */ 9999,
/* 689 */ 197030,
/* 690 */ 9999,
/* 691 */ 197009,
/* 692 */ 9999,
/* 693 */ 9999,
/* 694 */ 196043,
/* 695 */ 9999,
/* 696 */ 196041,
/* 697 */ 9999,
/* 698 */ 9999,
/* 699 */ 196041,
/* 700 */ 9999,
/* 701 */ 9999,
/* 702 */ 9999,
/* 703 */ 201014,
/* 704 */ 9999,
/* 705 */ 201029,
/* 706 */ 9999,
/* 707 */ 201008,
/* 708 */ 9999,
/* 709 */ 9999,
/* 710 */ 202007,
/* 711 */ 9999,
/* 712 */ 9999,
/* 713 */ 202027,
/* 714 */ 9999,
/* 715 */ 9999,
/* 716 */ 9999,
/* 717 */ 202005,
/* 718 */ 9999,
/* 719 */ 9999,
/* 720 */ 9999,
/* 721 */ 203012,
/* 722 */ 9999,
/* 723 */ 203032,
/* 724 */ 9999,
/* 725 */ 203052,
/* 726 */ 9999,
/* 727 */ 203072,
/* 728 */ 9999,
/* 729 */ 203006,
/* 730 */ 9999,
/* 731 */ 203014,
/* 732 */ 9999,
/* 733 */ 203023,
/* 734 */ 9999,
/* 735 */ 9999,
/* 736 */ 203023,
/* 737 */ 9999,
/* 738 */ 203034,
/* 739 */ 9999,
/* 740 */ 203043,
/* 741 */ 9999,
/* 742 */ 9999,
/* 743 */ 203043,
/* 744 */ 9999,
/* 745 */ 203054,
/* 746 */ 9999,
/* 747 */ 203063,
/* 748 */ 9999,
/* 749 */ 9999,
/* 750 */ 203063,
/* 751 */ 9999,
/* 752 */ 9999,
/* 753 */ 9999,
/* 754 */ 9999,
/* 755 */ 9999,
/* 756 */ 207007,
/* 757 */ 9999,
/* 758 */ 9999,
/* 759 */ 9999,
/* 760 */ 9999,
/* 761 */ 208011,
/* 762 */ 9999,
/* 763 */ 9999,
/* 764 */ 9999,
/* 765 */ 9999,
/* 766 */ 209008,
/* 767 */ 9999,
/* 768 */ 9999,
/* 769 */ 210011,
/* 770 */ 9999,
/* 771 */ 9999,
/* 772 */ 210009,
/* 773 */ 9999,
/* 774 */ 210013,
/* 775 */ 9999,
/* 776 */ 210022,
/* 777 */ 9999,
/* 778 */ 9999,
/* 779 */ 210022,
/* 780 */ 9999,
/* 781 */ 214004,
/* 782 */ 214024,
/* 783 */ 9999,
/* 784 */ 214004,
/* 785 */ 9999,
/* 786 */ 214006,
/* 787 */ 9999,
/* 788 */ 9999,
/* 789 */ 214015,
/* 790 */ 9999,
/* 791 */ 9999,
/* 792 */ 214015,
/* 793 */ 9999,
/* 794 */ 218004,
/* 795 */ 9999,
/* 796 */ 218025,
/* 797 */ 9999,
/* 798 */ 219004,
/* 799 */ 219021,
/* 800 */ 219041,
/* 801 */ 9999,
/* 802 */ 219019,
/* 803 */ 9999,
/* 804 */ 9999,
/* 805 */ 9999,
/* 806 */ 223009,
/* 807 */ 9999,
/* 808 */ 9999,
/* 809 */ 9999,
/* 810 */ 224004,
/* 811 */ 9999,
/* 812 */ 228004,
/* 813 */ 228026,
/* 814 */ 9999,
/* 815 */ 228024,
/* 816 */ 9999,
/* 817 */ 9999,
/* 818 */ 228032,
/* 819 */ 9999,
/* 820 */ 228047,
/* 821 */ 9999,
/* 822 */ 228028,
/* 823 */ 9999,
/* 824 */ 9999,
/* 825 */ 228028,
/* 826 */ 9999,
/* 827 */ 232004,
/* 828 */ 9999,
/* 829 */ 232025,
/* 830 */ 9999,
/* 831 */ 236004,
/* 832 */ 236042,
/* 833 */ 9999,
/* 834 */ 236004,
/* 835 */ 9999,
/* 836 */ 236006,
/* 837 */ 9999,
/* 838 */ 9999,
/* 839 */ 236026,
/* 840 */ 9999,
/* 841 */ 9999,
/* 842 */ 236026,
/* 843 */ 9999,
/* 844 */ 240004,
/* 845 */ 240044,
/* 846 */ 9999,
/* 847 */ 240004,
/* 848 */ 9999,
/* 849 */ 240006,
/* 850 */ 9999,
/* 851 */ 9999,
/* 852 */ 240027,
/* 853 */ 9999,
/* 854 */ 9999,
/* 855 */ 240027,
/* 856 */ 9999,
/* 857 */ 244004,
/* 858 */ 244040,
/* 859 */ 9999,
/* 860 */ 244004,
/* 861 */ 9999,
/* 862 */ 244006,
/* 863 */ 9999,
/* 864 */ 9999,
/* 865 */ 244028,
/* 866 */ 9999,
/* 867 */ 9999,
/* 868 */ 244028,
/* 869 */ 9999,
/* 870 */ 248004,
/* 871 */ 248041,
/* 872 */ 9999,
/* 873 */ 248004,
/* 874 */ 9999,
/* 875 */ 248006,
/* 876 */ 9999,
/* 877 */ 9999,
/* 878 */ 248028,
/* 879 */ 9999,
/* 880 */ 9999,
/* 881 */ 248028,
/* 882 */ 9999,
/* 883 */ 252004,
/* 884 */ 252031,
/* 885 */ 9999,
/* 886 */ 252004,
/* 887 */ 9999,
/* 888 */ 252005,
/* 889 */ 9999,
/* 890 */ 9999,
/* 891 */ 252018,
/* 892 */ 9999,
/* 893 */ 9999,
/* 894 */ 252018,
/* 895 */ 9999,
/* 896 */ 256004,
/* 897 */ 256037,
/* 898 */ 9999,
/* 899 */ 256004,
/* 900 */ 9999,
/* 901 */ 256006,
/* 902 */ 9999,
/* 903 */ 9999,
/* 904 */ 256024,
/* 905 */ 9999,
/* 906 */ 9999,
/* 907 */ 256024,
/* 908 */ 9999,
/* 909 */ 260004,
/* 910 */ 260031,
/* 911 */ 9999,
/* 912 */ 260004,
/* 913 */ 9999,
/* 914 */ 260005,
/* 915 */ 9999,
/* 916 */ 9999,
/* 917 */ 260020,
/* 918 */ 9999,
/* 919 */ 9999,
/* 920 */ 260020,
/* 921 */ 9999,
/* 922 */ 264004,
/* 923 */ 264043,
/* 924 */ 9999,
/* 925 */ 264004,
/* 926 */ 9999,
/* 927 */ 264006,
/* 928 */ 264026,
/* 929 */ 9999,
/* 930 */ 264024,
/* 931 */ 9999,
/* 932 */ 9999,
/* 933 */ 264024,
/* 934 */ 9999,
/* 935 */ 9999,
/* 936 */ 9999,
/* 937 */ 264028,
/* 938 */ 9999,
/* 939 */ 9999,
/* 940 */ 9999,
/* 941 */ 264034,
/* 942 */ 9999,
/* 943 */ 268004,
/* 944 */ 268055,
/* 945 */ 9999,
/* 946 */ 268004,
/* 947 */ 9999,
/* 948 */ 268006,
/* 949 */ 268032,
/* 950 */ 9999,
/* 951 */ 268030,
/* 952 */ 9999,
/* 953 */ 9999,
/* 954 */ 268030,
/* 955 */ 9999,
/* 956 */ 9999,
/* 957 */ 9999,
/* 958 */ 268034,
/* 959 */ 9999,
/* 960 */ 9999,
/* 961 */ 9999,
/* 962 */ 268040,
/* 963 */ 9999,
/* 964 */ 9999,
/* 965 */ 9999,
/* 966 */ 268046,
/* 967 */ 9999,
/* 968 */ 272004,
/* 969 */ 9999,
/* 970 */ 272019,
/* 971 */ 9999,
/* 972 */ 9999,
/* 973 */ 273008,
/* 974 */ 9999,
/* 975 */ 273022,
/* 976 */ 9999,
/* 977 */ 273004,
/* 978 */ 9999,
/* 979 */ 277004,
/* 980 */ 9999,
/* 981 */ 277021,
/* 982 */ 9999,
/* 983 */ 278004,
/* 984 */ 278024,
/* 985 */ 9999,
/* 986 */ 278004,
/* 987 */ 9999,
/* 988 */ 279004,
/* 989 */ 279019,
/* 990 */ 9999,
/* 991 */ 279017,
/* 992 */ 9999,
/* 993 */ 9999,
/* 994 */ 280011,
/* 995 */ 9999,
/* 996 */ 280009,
/* 997 */ 9999,
/* 998 */ 9999,
/* 999 */ 9999,
/* 1000 */ 281015,
/* 1001 */ 9999,
/* 1002 */ 9999,
/* 1003 */ 281009,
/* 1004 */ 9999,
/* 1005 */ 9999,
/* 1006 */ 9999,
/* 1007 */ 278011,
/* 1008 */ 9999,
/* 1009 */ 9999,
/* 1010 */ 9999,
/* 1011 */ 278020,
/* 1012 */ 9999,
/* 1013 */ 9999,
/* 1014 */ 9999,
/* 1015 */ 285004,
/* 1016 */ 9999,
/* 1017 */ 9999,
/* 1018 */ 9999,
/* 1019 */ 285010,
/* 1020 */ 9999,
/* 1021 */ 9999,
/* 1022 */ 9999,
/* 1023 */ 285016,
/* 1024 */ 9999,
/* 1025 */ 9999,
/* 1026 */ 9999,
/* 1027 */ 285022,
/* 1028 */ 9999,
/* 1029 */ 9999,
/* 1030 */ 9999,
/* 1031 */ 285028,
/* 1032 */ 9999,
/* 1033 */ 9999,
/* 1034 */ 9999,
/* 1035 */ 285034,
/* 1036 */ 9999,
/* 1037 */ 289004,
/* 1038 */ 9999,
/* 1039 */ 289021,
/* 1040 */ 9999,
/* 1041 */ 290004,
/* 1042 */ 290023,
/* 1043 */ 9999,
/* 1044 */ 290021,
/* 1045 */ 9999,
/* 1046 */ 9999,
/* 1047 */ 290029,
/* 1048 */ 9999,
/* 1049 */ 9999,
/* 1050 */ 290025,
/* 1051 */ 9999,
/* 1052 */ 9999,
/* 1053 */ 290050,
/* 1054 */ 9999,
/* 1055 */ 9999,
/* 1056 */ 290046,
/* 1057 */ 9999,
/* 1058 */ 9999,
/* 1059 */ 9999,
/* 1060 */ 9999,
/* 1061 */ 290086,
/* 1062 */ 9999,
/* 1063 */ 9999,
/* 1064 */ 9999,
/* 1065 */ 9999,
/* 1066 */ 290108,
/* 1067 */ 9999,
/* 1068 */ 9999,
/* 1069 */ 9999,
/* 1070 */ 290128,
/* 1071 */ 9999,
/* 1072 */ 9999,
/* 1073 */ 9999,
/* 1074 */ 290137,
/* 1075 */ 9999,
/* 1076 */ 290052,
/* 1077 */ 9999,
/* 1078 */ 290075,
/* 1079 */ 9999,
/* 1080 */ 9999,
/* 1081 */ 290075,
/* 1082 */ 9999,
/* 1083 */ 9999,
/* 1084 */ 9999,
/* 1085 */ 294013,
/* 1086 */ 9999,
/* 1087 */ 295004,
/* 1088 */ 9999,
/* 1089 */ 295011,
/* 1090 */ 9999,
/* 1091 */ 9999,
/* 1092 */ 9999,
/* 1093 */ 296009,
/* 1094 */ 9999,
/* 1095 */ 9999,
/* 1096 */ 297008,
/* 1097 */ 9999,
/* 1098 */ 9999,
/* 1099 */ 297004,
/* 1100 */ 9999,
/* 1101 */ 301004,
/* 1102 */ 301038,
/* 1103 */ 9999,
/* 1104 */ 301004,
/* 1105 */ 9999,
/* 1106 */ 301006,
/* 1107 */ 9999,
/* 1108 */ 9999,
/* 1109 */ 301029,
/* 1110 */ 9999,
/* 1111 */ 9999,
/* 1112 */ 301029,
/* 1113 */ 9999,
/* 1114 */ 9999,
/* 1115 */ 9999,
/* 1116 */ 305011,
/* 1117 */ 9999,
/* 1118 */ 9999,
/* 1119 */ 9999,
/* 1120 */ 305061,
/* 1121 */ 9999,
/* 1122 */ 9999,
/* 1123 */ 9999,
/* 1124 */ 305074,
/* 1125 */ 9999,
/* 1126 */ 9999,
/* 1127 */ 9999,
/* 1128 */ 305087,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[1130];
*/
int TABLE[256][309];
init_dirsets() {
TABLE[124][0] = 1;
TABLE[124][123] = 1;
TABLE[124][299] = 1;
TABLE[124][40] = 1;
TABLE[124][282] = 1;
TABLE[124][267] = 1;
TABLE[124][279] = 1;
TABLE[124][274] = 1;
TABLE[124][256] = 1;
TABLE[124][284] = 1;
TABLE[124][277] = 1;
TABLE[124][264] = 1;
TABLE[124][268] = 1;
TABLE[124][273] = 1;
TABLE[124][272] = 1;
TABLE[124][276] = 1;
TABLE[124][259] = 1;
TABLE[124][285] = 1;
TABLE[124][286] = 1;
TABLE[124][260] = 1;
TABLE[124][42] = 1;
TABLE[124][266] = 1;
TABLE[124][283] = 1;
TABLE[124][280] = 1;
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
TABLE[126][123] = 1;
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
TABLE[126][280] = 1;
TABLE[126][283] = 1;
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
TABLE[127][59] = 1;
TABLE[127][44] = 1;
TABLE[127][123] = 1;
TABLE[127][61] = 1;
TABLE[127][278] = 1;
TABLE[127][299] = 1;
TABLE[127][40] = 1;
TABLE[127][295] = 1;
TABLE[127][294] = 1;
TABLE[127][33] = 1;
TABLE[127][126] = 1;
TABLE[127][45] = 1;
TABLE[127][43] = 1;
TABLE[127][38] = 1;
TABLE[127][63] = 1;
TABLE[127][42] = 1;
TABLE[127][289] = 1;
TABLE[127][297] = 1;
TABLE[127][307] = 1;
TABLE[127][306] = 1;
TABLE[127][308] = 1;
TABLE[127][298] = 1;
TABLE[127][301] = 1;
TABLE[127][303] = 1;
TABLE[127][302] = 1;
TABLE[127][292] = 1;
TABLE[127][304] = 1;
TABLE[127][37] = 1;
TABLE[127][47] = 1;
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
TABLE[128][260] = 1;
TABLE[128][286] = 1;
TABLE[128][285] = 1;
TABLE[128][259] = 1;
TABLE[128][276] = 1;
TABLE[128][272] = 1;
TABLE[128][273] = 1;
TABLE[128][268] = 1;
TABLE[128][264] = 1;
TABLE[128][277] = 1;
TABLE[128][284] = 1;
TABLE[128][256] = 1;
TABLE[128][274] = 1;
TABLE[128][279] = 1;
TABLE[128][267] = 1;
TABLE[128][282] = 1;
TABLE[128][266] = 1;
TABLE[128][280] = 1;
TABLE[128][283] = 1;
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
TABLE[129][256] = 1;
TABLE[129][274] = 1;
TABLE[129][279] = 1;
TABLE[129][267] = 1;
TABLE[129][282] = 1;
TABLE[130][285] = 1;
TABLE[130][259] = 1;
TABLE[130][276] = 1;
TABLE[130][272] = 1;
TABLE[130][273] = 1;
TABLE[130][268] = 1;
TABLE[130][264] = 1;
TABLE[130][277] = 1;
TABLE[130][284] = 1;
TABLE[130][266] = 1;
TABLE[130][280] = 1;
TABLE[130][283] = 1;
TABLE[131][260] = 1;
TABLE[131][286] = 1;
TABLE[132][260] = 1;
TABLE[132][286] = 1;
TABLE[132][285] = 1;
TABLE[132][259] = 1;
TABLE[132][276] = 1;
TABLE[132][272] = 1;
TABLE[132][273] = 1;
TABLE[132][268] = 1;
TABLE[132][264] = 1;
TABLE[132][277] = 1;
TABLE[132][284] = 1;
TABLE[132][256] = 1;
TABLE[132][274] = 1;
TABLE[132][279] = 1;
TABLE[132][267] = 1;
TABLE[132][282] = 1;
TABLE[132][266] = 1;
TABLE[132][280] = 1;
TABLE[132][283] = 1;
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
TABLE[133][299] = 1;
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
TABLE[134][260] = 1;
TABLE[134][286] = 1;
TABLE[134][285] = 1;
TABLE[134][259] = 1;
TABLE[134][276] = 1;
TABLE[134][272] = 1;
TABLE[134][273] = 1;
TABLE[134][268] = 1;
TABLE[134][264] = 1;
TABLE[134][277] = 1;
TABLE[134][284] = 1;
TABLE[134][266] = 1;
TABLE[134][280] = 1;
TABLE[134][283] = 1;
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
TABLE[135][44] = 1;
TABLE[135][123] = 1;
TABLE[135][61] = 1;
TABLE[135][278] = 1;
TABLE[135][299] = 1;
TABLE[135][40] = 1;
TABLE[135][295] = 1;
TABLE[135][294] = 1;
TABLE[135][33] = 1;
TABLE[135][126] = 1;
TABLE[135][45] = 1;
TABLE[135][43] = 1;
TABLE[135][38] = 1;
TABLE[135][63] = 1;
TABLE[135][42] = 1;
TABLE[135][289] = 1;
TABLE[135][297] = 1;
TABLE[135][307] = 1;
TABLE[135][306] = 1;
TABLE[135][308] = 1;
TABLE[135][298] = 1;
TABLE[135][301] = 1;
TABLE[135][303] = 1;
TABLE[135][302] = 1;
TABLE[135][292] = 1;
TABLE[135][304] = 1;
TABLE[135][37] = 1;
TABLE[135][47] = 1;
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
TABLE[136][61] = 1;
TABLE[136][40] = 1;
TABLE[136][299] = 1;
TABLE[136][42] = 1;
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
TABLE[137][285] = 1;
TABLE[137][259] = 1;
TABLE[137][276] = 1;
TABLE[137][272] = 1;
TABLE[137][273] = 1;
TABLE[137][268] = 1;
TABLE[137][264] = 1;
TABLE[137][277] = 1;
TABLE[137][284] = 1;
TABLE[137][266] = 1;
TABLE[137][280] = 1;
TABLE[137][283] = 1;
TABLE[138][260] = 1;
TABLE[138][286] = 1;
TABLE[139][260] = 1;
TABLE[139][286] = 1;
TABLE[139][285] = 1;
TABLE[139][259] = 1;
TABLE[139][276] = 1;
TABLE[139][272] = 1;
TABLE[139][273] = 1;
TABLE[139][268] = 1;
TABLE[139][264] = 1;
TABLE[139][277] = 1;
TABLE[139][284] = 1;
TABLE[139][266] = 1;
TABLE[139][280] = 1;
TABLE[139][283] = 1;
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
TABLE[37][44] = 1;
TABLE[37][58] = 1;
TABLE[37][40] = 1;
TABLE[37][299] = 1;
TABLE[37][42] = 1;
TABLE[38][59] = 1;
TABLE[38][44] = 1;
TABLE[38][40] = 1;
TABLE[38][299] = 1;
TABLE[38][42] = 1;
TABLE[39][58] = 1;
TABLE[39][299] = 1;
TABLE[39][40] = 1;
TABLE[39][42] = 1;
TABLE[140][58] = 1;
TABLE[140][40] = 1;
TABLE[140][299] = 1;
TABLE[140][42] = 1;
TABLE[213][58] = 1;
TABLE[40][266] = 1;
TABLE[41][266] = 1;
TABLE[141][299] = 1;
TABLE[214][123] = 1;
TABLE[42][44] = 1;
TABLE[42][299] = 1;
TABLE[142][44] = 1;
TABLE[142][299] = 1;
TABLE[215][299] = 1;
TABLE[43][299] = 1;
TABLE[143][61] = 1;
TABLE[216][125] = 1;
TABLE[216][44] = 1;
TABLE[44][299] = 1;
TABLE[44][40] = 1;
TABLE[44][42] = 1;
TABLE[144][42] = 1;
TABLE[217][299] = 1;
TABLE[217][40] = 1;
TABLE[45][299] = 1;
TABLE[46][40] = 1;
TABLE[47][299] = 1;
TABLE[47][40] = 1;
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
TABLE[218][93] = 1;
TABLE[148][41] = 1;
TABLE[148][299] = 1;
TABLE[148][44] = 1;
TABLE[219][41] = 1;
TABLE[48][42] = 1;
TABLE[150][42] = 1;
TABLE[150][299] = 1;
TABLE[150][40] = 1;
TABLE[150][44] = 1;
TABLE[150][41] = 1;
TABLE[150][91] = 1;
TABLE[150][286] = 1;
TABLE[150][260] = 1;
TABLE[220][42] = 1;
TABLE[220][299] = 1;
TABLE[220][40] = 1;
TABLE[220][44] = 1;
TABLE[220][41] = 1;
TABLE[220][91] = 1;
TABLE[151][42] = 1;
TABLE[221][299] = 1;
TABLE[221][40] = 1;
TABLE[221][44] = 1;
TABLE[221][41] = 1;
TABLE[221][91] = 1;
TABLE[49][260] = 1;
TABLE[49][286] = 1;
TABLE[152][286] = 1;
TABLE[152][260] = 1;
TABLE[222][260] = 1;
TABLE[222][286] = 1;
TABLE[50][41] = 1;
TABLE[50][44] = 1;
TABLE[50][260] = 1;
TABLE[50][286] = 1;
TABLE[50][285] = 1;
TABLE[50][259] = 1;
TABLE[50][276] = 1;
TABLE[50][272] = 1;
TABLE[50][273] = 1;
TABLE[50][268] = 1;
TABLE[50][264] = 1;
TABLE[50][277] = 1;
TABLE[50][284] = 1;
TABLE[50][256] = 1;
TABLE[50][274] = 1;
TABLE[50][279] = 1;
TABLE[50][267] = 1;
TABLE[50][282] = 1;
TABLE[50][266] = 1;
TABLE[50][280] = 1;
TABLE[50][283] = 1;
TABLE[153][44] = 1;
TABLE[223][41] = 1;
TABLE[51][44] = 1;
TABLE[51][282] = 1;
TABLE[51][267] = 1;
TABLE[51][279] = 1;
TABLE[51][274] = 1;
TABLE[51][256] = 1;
TABLE[51][284] = 1;
TABLE[51][277] = 1;
TABLE[51][264] = 1;
TABLE[51][268] = 1;
TABLE[51][273] = 1;
TABLE[51][272] = 1;
TABLE[51][276] = 1;
TABLE[51][259] = 1;
TABLE[51][285] = 1;
TABLE[51][286] = 1;
TABLE[51][260] = 1;
TABLE[51][266] = 1;
TABLE[51][283] = 1;
TABLE[51][280] = 1;
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
TABLE[224][282] = 1;
TABLE[224][267] = 1;
TABLE[224][279] = 1;
TABLE[224][274] = 1;
TABLE[224][256] = 1;
TABLE[224][284] = 1;
TABLE[224][277] = 1;
TABLE[224][264] = 1;
TABLE[224][268] = 1;
TABLE[224][273] = 1;
TABLE[224][272] = 1;
TABLE[224][276] = 1;
TABLE[224][259] = 1;
TABLE[224][285] = 1;
TABLE[224][286] = 1;
TABLE[224][260] = 1;
TABLE[224][266] = 1;
TABLE[224][283] = 1;
TABLE[224][280] = 1;
TABLE[52][260] = 1;
TABLE[52][286] = 1;
TABLE[52][285] = 1;
TABLE[52][259] = 1;
TABLE[52][276] = 1;
TABLE[52][272] = 1;
TABLE[52][273] = 1;
TABLE[52][268] = 1;
TABLE[52][264] = 1;
TABLE[52][277] = 1;
TABLE[52][284] = 1;
TABLE[52][256] = 1;
TABLE[52][274] = 1;
TABLE[52][279] = 1;
TABLE[52][267] = 1;
TABLE[52][282] = 1;
TABLE[52][266] = 1;
TABLE[52][280] = 1;
TABLE[52][283] = 1;
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
TABLE[225][44] = 1;
TABLE[225][41] = 1;
TABLE[53][299] = 1;
TABLE[53][44] = 1;
TABLE[158][299] = 1;
TABLE[158][44] = 1;
TABLE[226][299] = 1;
TABLE[54][59] = 1;
TABLE[54][44] = 1;
TABLE[54][125] = 1;
TABLE[54][278] = 1;
TABLE[54][63] = 1;
TABLE[54][38] = 1;
TABLE[54][42] = 1;
TABLE[54][43] = 1;
TABLE[54][45] = 1;
TABLE[54][126] = 1;
TABLE[54][33] = 1;
TABLE[54][294] = 1;
TABLE[54][295] = 1;
TABLE[54][297] = 1;
TABLE[54][40] = 1;
TABLE[54][289] = 1;
TABLE[54][299] = 1;
TABLE[54][298] = 1;
TABLE[54][308] = 1;
TABLE[54][306] = 1;
TABLE[54][307] = 1;
TABLE[54][301] = 1;
TABLE[54][303] = 1;
TABLE[54][302] = 1;
TABLE[54][292] = 1;
TABLE[54][304] = 1;
TABLE[54][47] = 1;
TABLE[54][37] = 1;
TABLE[55][123] = 1;
TABLE[159][44] = 1;
TABLE[227][125] = 1;
TABLE[56][125] = 1;
TABLE[56][123] = 1;
TABLE[56][44] = 1;
TABLE[56][278] = 1;
TABLE[56][295] = 1;
TABLE[56][294] = 1;
TABLE[56][33] = 1;
TABLE[56][126] = 1;
TABLE[56][45] = 1;
TABLE[56][43] = 1;
TABLE[56][42] = 1;
TABLE[56][38] = 1;
TABLE[56][63] = 1;
TABLE[56][299] = 1;
TABLE[56][289] = 1;
TABLE[56][40] = 1;
TABLE[56][297] = 1;
TABLE[56][307] = 1;
TABLE[56][306] = 1;
TABLE[56][308] = 1;
TABLE[56][298] = 1;
TABLE[56][301] = 1;
TABLE[56][303] = 1;
TABLE[56][302] = 1;
TABLE[56][292] = 1;
TABLE[56][304] = 1;
TABLE[56][37] = 1;
TABLE[56][47] = 1;
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
TABLE[228][123] = 1;
TABLE[228][278] = 1;
TABLE[228][295] = 1;
TABLE[228][294] = 1;
TABLE[228][33] = 1;
TABLE[228][126] = 1;
TABLE[228][45] = 1;
TABLE[228][43] = 1;
TABLE[228][42] = 1;
TABLE[228][38] = 1;
TABLE[228][63] = 1;
TABLE[228][299] = 1;
TABLE[228][289] = 1;
TABLE[228][40] = 1;
TABLE[228][297] = 1;
TABLE[228][307] = 1;
TABLE[228][306] = 1;
TABLE[228][308] = 1;
TABLE[228][298] = 1;
TABLE[228][301] = 1;
TABLE[228][303] = 1;
TABLE[228][302] = 1;
TABLE[228][292] = 1;
TABLE[228][304] = 1;
TABLE[228][37] = 1;
TABLE[228][47] = 1;
TABLE[228][44] = 1;
TABLE[228][125] = 1;
TABLE[57][260] = 1;
TABLE[57][286] = 1;
TABLE[57][285] = 1;
TABLE[57][259] = 1;
TABLE[57][276] = 1;
TABLE[57][272] = 1;
TABLE[57][273] = 1;
TABLE[57][268] = 1;
TABLE[57][264] = 1;
TABLE[57][277] = 1;
TABLE[57][284] = 1;
TABLE[57][266] = 1;
TABLE[57][280] = 1;
TABLE[57][283] = 1;
TABLE[161][41] = 1;
TABLE[161][42] = 1;
TABLE[161][40] = 1;
TABLE[161][91] = 1;
TABLE[229][41] = 1;
TABLE[58][42] = 1;
TABLE[59][44] = 1;
TABLE[59][41] = 1;
TABLE[59][40] = 1;
TABLE[59][91] = 1;
TABLE[59][42] = 1;
TABLE[162][42] = 1;
TABLE[230][40] = 1;
TABLE[230][91] = 1;
TABLE[230][44] = 1;
TABLE[230][41] = 1;
TABLE[60][40] = 1;
TABLE[61][40] = 1;
TABLE[61][91] = 1;
TABLE[163][40] = 1;
TABLE[163][91] = 1;
TABLE[231][91] = 1;
TABLE[231][40] = 1;
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
TABLE[232][93] = 1;
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
TABLE[233][41] = 1;
TABLE[62][299] = 1;
TABLE[63][299] = 1;
TABLE[63][258] = 1;
TABLE[63][262] = 1;
TABLE[64][125] = 1;
TABLE[64][265] = 1;
TABLE[64][287] = 1;
TABLE[64][262] = 1;
TABLE[64][258] = 1;
TABLE[64][123] = 1;
TABLE[64][281] = 1;
TABLE[64][271] = 1;
TABLE[64][269] = 1;
TABLE[64][263] = 1;
TABLE[64][275] = 1;
TABLE[64][257] = 1;
TABLE[64][261] = 1;
TABLE[64][270] = 1;
TABLE[64][59] = 1;
TABLE[64][44] = 1;
TABLE[64][278] = 1;
TABLE[64][295] = 1;
TABLE[64][294] = 1;
TABLE[64][33] = 1;
TABLE[64][126] = 1;
TABLE[64][45] = 1;
TABLE[64][43] = 1;
TABLE[64][42] = 1;
TABLE[64][38] = 1;
TABLE[64][63] = 1;
TABLE[64][299] = 1;
TABLE[64][289] = 1;
TABLE[64][40] = 1;
TABLE[64][297] = 1;
TABLE[64][307] = 1;
TABLE[64][306] = 1;
TABLE[64][308] = 1;
TABLE[64][298] = 1;
TABLE[64][301] = 1;
TABLE[64][303] = 1;
TABLE[64][302] = 1;
TABLE[64][292] = 1;
TABLE[64][304] = 1;
TABLE[64][37] = 1;
TABLE[64][47] = 1;
TABLE[65][123] = 1;
TABLE[66][271] = 1;
TABLE[66][281] = 1;
TABLE[67][287] = 1;
TABLE[67][263] = 1;
TABLE[67][269] = 1;
TABLE[68][270] = 1;
TABLE[68][261] = 1;
TABLE[68][257] = 1;
TABLE[68][275] = 1;
TABLE[69][299] = 1;
TABLE[70][258] = 1;
TABLE[71][262] = 1;
TABLE[72][59] = 1;
TABLE[72][44] = 1;
TABLE[72][278] = 1;
TABLE[72][63] = 1;
TABLE[72][38] = 1;
TABLE[72][42] = 1;
TABLE[72][43] = 1;
TABLE[72][45] = 1;
TABLE[72][126] = 1;
TABLE[72][33] = 1;
TABLE[72][294] = 1;
TABLE[72][295] = 1;
TABLE[72][297] = 1;
TABLE[72][40] = 1;
TABLE[72][289] = 1;
TABLE[72][299] = 1;
TABLE[72][298] = 1;
TABLE[72][308] = 1;
TABLE[72][306] = 1;
TABLE[72][307] = 1;
TABLE[72][301] = 1;
TABLE[72][303] = 1;
TABLE[72][302] = 1;
TABLE[72][292] = 1;
TABLE[72][304] = 1;
TABLE[72][47] = 1;
TABLE[72][37] = 1;
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
TABLE[234][59] = 1;
TABLE[73][123] = 1;
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
TABLE[235][262] = 1;
TABLE[235][258] = 1;
TABLE[235][299] = 1;
TABLE[235][59] = 1;
TABLE[235][123] = 1;
TABLE[235][281] = 1;
TABLE[235][271] = 1;
TABLE[235][269] = 1;
TABLE[235][263] = 1;
TABLE[235][287] = 1;
TABLE[235][275] = 1;
TABLE[235][257] = 1;
TABLE[235][261] = 1;
TABLE[235][270] = 1;
TABLE[235][44] = 1;
TABLE[235][278] = 1;
TABLE[235][63] = 1;
TABLE[235][38] = 1;
TABLE[235][42] = 1;
TABLE[235][43] = 1;
TABLE[235][45] = 1;
TABLE[235][126] = 1;
TABLE[235][33] = 1;
TABLE[235][294] = 1;
TABLE[235][295] = 1;
TABLE[235][297] = 1;
TABLE[235][40] = 1;
TABLE[235][289] = 1;
TABLE[235][298] = 1;
TABLE[235][308] = 1;
TABLE[235][306] = 1;
TABLE[235][307] = 1;
TABLE[235][301] = 1;
TABLE[235][303] = 1;
TABLE[235][302] = 1;
TABLE[235][292] = 1;
TABLE[235][304] = 1;
TABLE[235][47] = 1;
TABLE[235][37] = 1;
TABLE[235][125] = 1;
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
TABLE[236][125] = 1;
TABLE[74][125] = 1;
TABLE[74][262] = 1;
TABLE[74][258] = 1;
TABLE[74][299] = 1;
TABLE[74][59] = 1;
TABLE[74][123] = 1;
TABLE[74][281] = 1;
TABLE[74][271] = 1;
TABLE[74][269] = 1;
TABLE[74][263] = 1;
TABLE[74][287] = 1;
TABLE[74][275] = 1;
TABLE[74][257] = 1;
TABLE[74][261] = 1;
TABLE[74][270] = 1;
TABLE[74][44] = 1;
TABLE[74][278] = 1;
TABLE[74][63] = 1;
TABLE[74][38] = 1;
TABLE[74][42] = 1;
TABLE[74][43] = 1;
TABLE[74][45] = 1;
TABLE[74][126] = 1;
TABLE[74][33] = 1;
TABLE[74][294] = 1;
TABLE[74][295] = 1;
TABLE[74][297] = 1;
TABLE[74][40] = 1;
TABLE[74][289] = 1;
TABLE[74][298] = 1;
TABLE[74][308] = 1;
TABLE[74][306] = 1;
TABLE[74][307] = 1;
TABLE[74][301] = 1;
TABLE[74][303] = 1;
TABLE[74][302] = 1;
TABLE[74][292] = 1;
TABLE[74][304] = 1;
TABLE[74][47] = 1;
TABLE[74][37] = 1;
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
TABLE[237][262] = 1;
TABLE[237][258] = 1;
TABLE[237][299] = 1;
TABLE[237][59] = 1;
TABLE[237][123] = 1;
TABLE[237][281] = 1;
TABLE[237][271] = 1;
TABLE[237][269] = 1;
TABLE[237][263] = 1;
TABLE[237][287] = 1;
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
TABLE[237][125] = 1;
TABLE[75][271] = 1;
TABLE[76][281] = 1;
TABLE[172][265] = 1;
TABLE[238][125] = 1;
TABLE[238][265] = 1;
TABLE[238][287] = 1;
TABLE[238][262] = 1;
TABLE[238][258] = 1;
TABLE[238][299] = 1;
TABLE[238][59] = 1;
TABLE[238][123] = 1;
TABLE[238][281] = 1;
TABLE[238][271] = 1;
TABLE[238][269] = 1;
TABLE[238][263] = 1;
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
TABLE[77][287] = 1;
TABLE[78][263] = 1;
TABLE[79][269] = 1;
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
TABLE[239][59] = 1;
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
TABLE[240][59] = 1;
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
TABLE[241][41] = 1;
TABLE[80][270] = 1;
TABLE[81][261] = 1;
TABLE[82][257] = 1;
TABLE[83][275] = 1;
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
TABLE[242][59] = 1;
TABLE[84][59] = 1;
TABLE[84][41] = 1;
TABLE[84][58] = 1;
TABLE[84][93] = 1;
TABLE[84][44] = 1;
TABLE[84][278] = 1;
TABLE[84][63] = 1;
TABLE[84][38] = 1;
TABLE[84][42] = 1;
TABLE[84][43] = 1;
TABLE[84][45] = 1;
TABLE[84][126] = 1;
TABLE[84][33] = 1;
TABLE[84][294] = 1;
TABLE[84][295] = 1;
TABLE[84][297] = 1;
TABLE[84][40] = 1;
TABLE[84][289] = 1;
TABLE[84][299] = 1;
TABLE[84][298] = 1;
TABLE[84][308] = 1;
TABLE[84][306] = 1;
TABLE[84][307] = 1;
TABLE[84][301] = 1;
TABLE[84][303] = 1;
TABLE[84][302] = 1;
TABLE[84][292] = 1;
TABLE[84][304] = 1;
TABLE[84][47] = 1;
TABLE[84][37] = 1;
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
TABLE[243][278] = 1;
TABLE[243][63] = 1;
TABLE[243][38] = 1;
TABLE[243][42] = 1;
TABLE[243][43] = 1;
TABLE[243][45] = 1;
TABLE[243][126] = 1;
TABLE[243][33] = 1;
TABLE[243][294] = 1;
TABLE[243][295] = 1;
TABLE[243][297] = 1;
TABLE[243][40] = 1;
TABLE[243][289] = 1;
TABLE[243][299] = 1;
TABLE[243][298] = 1;
TABLE[243][308] = 1;
TABLE[243][306] = 1;
TABLE[243][307] = 1;
TABLE[243][301] = 1;
TABLE[243][303] = 1;
TABLE[243][302] = 1;
TABLE[243][292] = 1;
TABLE[243][304] = 1;
TABLE[243][47] = 1;
TABLE[243][37] = 1;
TABLE[243][59] = 1;
TABLE[243][41] = 1;
TABLE[243][44] = 1;
TABLE[243][58] = 1;
TABLE[243][93] = 1;
TABLE[85][59] = 1;
TABLE[85][41] = 1;
TABLE[85][44] = 1;
TABLE[85][125] = 1;
TABLE[85][58] = 1;
TABLE[85][93] = 1;
TABLE[85][63] = 1;
TABLE[85][297] = 1;
TABLE[85][298] = 1;
TABLE[85][301] = 1;
TABLE[85][303] = 1;
TABLE[85][302] = 1;
TABLE[85][292] = 1;
TABLE[85][304] = 1;
TABLE[85][43] = 1;
TABLE[85][45] = 1;
TABLE[85][40] = 1;
TABLE[85][278] = 1;
TABLE[85][37] = 1;
TABLE[85][47] = 1;
TABLE[85][42] = 1;
TABLE[85][38] = 1;
TABLE[85][126] = 1;
TABLE[85][33] = 1;
TABLE[85][294] = 1;
TABLE[85][295] = 1;
TABLE[85][289] = 1;
TABLE[85][299] = 1;
TABLE[85][308] = 1;
TABLE[85][306] = 1;
TABLE[85][307] = 1;
TABLE[86][278] = 1;
TABLE[86][295] = 1;
TABLE[86][294] = 1;
TABLE[86][33] = 1;
TABLE[86][126] = 1;
TABLE[86][45] = 1;
TABLE[86][43] = 1;
TABLE[86][42] = 1;
TABLE[86][38] = 1;
TABLE[86][299] = 1;
TABLE[86][289] = 1;
TABLE[86][40] = 1;
TABLE[86][307] = 1;
TABLE[86][306] = 1;
TABLE[86][308] = 1;
TABLE[87][291] = 1;
TABLE[88][61] = 1;
TABLE[89][59] = 1;
TABLE[89][41] = 1;
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
TABLE[89][40] = 1;
TABLE[89][45] = 1;
TABLE[89][43] = 1;
TABLE[89][42] = 1;
TABLE[89][47] = 1;
TABLE[89][37] = 1;
TABLE[89][278] = 1;
TABLE[89][295] = 1;
TABLE[89][294] = 1;
TABLE[89][33] = 1;
TABLE[89][126] = 1;
TABLE[89][38] = 1;
TABLE[89][299] = 1;
TABLE[89][289] = 1;
TABLE[89][307] = 1;
TABLE[89][306] = 1;
TABLE[89][308] = 1;
TABLE[178][63] = 1;
TABLE[244][59] = 1;
TABLE[244][41] = 1;
TABLE[244][125] = 1;
TABLE[244][93] = 1;
TABLE[244][58] = 1;
TABLE[244][44] = 1;
TABLE[90][59] = 1;
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
TABLE[91][63] = 1;
TABLE[91][59] = 1;
TABLE[91][41] = 1;
TABLE[91][125] = 1;
TABLE[91][93] = 1;
TABLE[91][58] = 1;
TABLE[91][44] = 1;
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
TABLE[245][298] = 1;
TABLE[245][301] = 1;
TABLE[245][303] = 1;
TABLE[245][302] = 1;
TABLE[245][292] = 1;
TABLE[245][304] = 1;
TABLE[245][43] = 1;
TABLE[245][45] = 1;
TABLE[245][40] = 1;
TABLE[245][278] = 1;
TABLE[245][37] = 1;
TABLE[245][47] = 1;
TABLE[245][42] = 1;
TABLE[245][38] = 1;
TABLE[245][126] = 1;
TABLE[245][33] = 1;
TABLE[245][294] = 1;
TABLE[245][295] = 1;
TABLE[245][289] = 1;
TABLE[245][299] = 1;
TABLE[245][308] = 1;
TABLE[245][306] = 1;
TABLE[245][307] = 1;
TABLE[245][63] = 1;
TABLE[245][59] = 1;
TABLE[245][41] = 1;
TABLE[245][297] = 1;
TABLE[245][125] = 1;
TABLE[245][93] = 1;
TABLE[245][58] = 1;
TABLE[245][44] = 1;
TABLE[92][63] = 1;
TABLE[92][59] = 1;
TABLE[92][41] = 1;
TABLE[92][297] = 1;
TABLE[92][125] = 1;
TABLE[92][93] = 1;
TABLE[92][58] = 1;
TABLE[92][44] = 1;
TABLE[92][298] = 1;
TABLE[92][301] = 1;
TABLE[92][303] = 1;
TABLE[92][302] = 1;
TABLE[92][292] = 1;
TABLE[92][304] = 1;
TABLE[92][40] = 1;
TABLE[92][45] = 1;
TABLE[92][43] = 1;
TABLE[92][42] = 1;
TABLE[92][47] = 1;
TABLE[92][37] = 1;
TABLE[92][278] = 1;
TABLE[92][295] = 1;
TABLE[92][294] = 1;
TABLE[92][33] = 1;
TABLE[92][126] = 1;
TABLE[92][38] = 1;
TABLE[92][299] = 1;
TABLE[92][289] = 1;
TABLE[92][307] = 1;
TABLE[92][306] = 1;
TABLE[92][308] = 1;
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
TABLE[246][301] = 1;
TABLE[246][303] = 1;
TABLE[246][302] = 1;
TABLE[246][292] = 1;
TABLE[246][304] = 1;
TABLE[246][40] = 1;
TABLE[246][45] = 1;
TABLE[246][43] = 1;
TABLE[246][42] = 1;
TABLE[246][47] = 1;
TABLE[246][37] = 1;
TABLE[246][278] = 1;
TABLE[246][295] = 1;
TABLE[246][294] = 1;
TABLE[246][33] = 1;
TABLE[246][126] = 1;
TABLE[246][38] = 1;
TABLE[246][299] = 1;
TABLE[246][289] = 1;
TABLE[246][307] = 1;
TABLE[246][306] = 1;
TABLE[246][308] = 1;
TABLE[246][63] = 1;
TABLE[246][59] = 1;
TABLE[246][41] = 1;
TABLE[246][298] = 1;
TABLE[246][297] = 1;
TABLE[246][125] = 1;
TABLE[246][93] = 1;
TABLE[246][58] = 1;
TABLE[246][44] = 1;
TABLE[93][63] = 1;
TABLE[93][59] = 1;
TABLE[93][41] = 1;
TABLE[93][298] = 1;
TABLE[93][297] = 1;
TABLE[93][125] = 1;
TABLE[93][93] = 1;
TABLE[93][58] = 1;
TABLE[93][44] = 1;
TABLE[93][301] = 1;
TABLE[93][303] = 1;
TABLE[93][302] = 1;
TABLE[93][292] = 1;
TABLE[93][304] = 1;
TABLE[93][43] = 1;
TABLE[93][45] = 1;
TABLE[93][40] = 1;
TABLE[93][278] = 1;
TABLE[93][37] = 1;
TABLE[93][47] = 1;
TABLE[93][42] = 1;
TABLE[93][38] = 1;
TABLE[93][126] = 1;
TABLE[93][33] = 1;
TABLE[93][294] = 1;
TABLE[93][295] = 1;
TABLE[93][289] = 1;
TABLE[93][299] = 1;
TABLE[93][308] = 1;
TABLE[93][306] = 1;
TABLE[93][307] = 1;
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
TABLE[247][303] = 1;
TABLE[247][302] = 1;
TABLE[247][292] = 1;
TABLE[247][304] = 1;
TABLE[247][43] = 1;
TABLE[247][45] = 1;
TABLE[247][40] = 1;
TABLE[247][278] = 1;
TABLE[247][37] = 1;
TABLE[247][47] = 1;
TABLE[247][42] = 1;
TABLE[247][38] = 1;
TABLE[247][126] = 1;
TABLE[247][33] = 1;
TABLE[247][294] = 1;
TABLE[247][295] = 1;
TABLE[247][289] = 1;
TABLE[247][299] = 1;
TABLE[247][308] = 1;
TABLE[247][306] = 1;
TABLE[247][307] = 1;
TABLE[247][63] = 1;
TABLE[247][59] = 1;
TABLE[247][41] = 1;
TABLE[247][301] = 1;
TABLE[247][298] = 1;
TABLE[247][297] = 1;
TABLE[247][125] = 1;
TABLE[247][93] = 1;
TABLE[247][58] = 1;
TABLE[247][44] = 1;
TABLE[94][63] = 1;
TABLE[94][59] = 1;
TABLE[94][41] = 1;
TABLE[94][301] = 1;
TABLE[94][298] = 1;
TABLE[94][297] = 1;
TABLE[94][125] = 1;
TABLE[94][93] = 1;
TABLE[94][58] = 1;
TABLE[94][44] = 1;
TABLE[94][303] = 1;
TABLE[94][302] = 1;
TABLE[94][292] = 1;
TABLE[94][304] = 1;
TABLE[94][40] = 1;
TABLE[94][45] = 1;
TABLE[94][43] = 1;
TABLE[94][42] = 1;
TABLE[94][47] = 1;
TABLE[94][37] = 1;
TABLE[94][278] = 1;
TABLE[94][295] = 1;
TABLE[94][294] = 1;
TABLE[94][33] = 1;
TABLE[94][126] = 1;
TABLE[94][38] = 1;
TABLE[94][299] = 1;
TABLE[94][289] = 1;
TABLE[94][307] = 1;
TABLE[94][306] = 1;
TABLE[94][308] = 1;
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
TABLE[248][302] = 1;
TABLE[248][292] = 1;
TABLE[248][304] = 1;
TABLE[248][40] = 1;
TABLE[248][45] = 1;
TABLE[248][43] = 1;
TABLE[248][42] = 1;
TABLE[248][47] = 1;
TABLE[248][37] = 1;
TABLE[248][278] = 1;
TABLE[248][295] = 1;
TABLE[248][294] = 1;
TABLE[248][33] = 1;
TABLE[248][126] = 1;
TABLE[248][38] = 1;
TABLE[248][299] = 1;
TABLE[248][289] = 1;
TABLE[248][307] = 1;
TABLE[248][306] = 1;
TABLE[248][308] = 1;
TABLE[248][63] = 1;
TABLE[248][59] = 1;
TABLE[248][41] = 1;
TABLE[248][303] = 1;
TABLE[248][301] = 1;
TABLE[248][298] = 1;
TABLE[248][297] = 1;
TABLE[248][125] = 1;
TABLE[248][93] = 1;
TABLE[248][58] = 1;
TABLE[248][44] = 1;
TABLE[95][63] = 1;
TABLE[95][59] = 1;
TABLE[95][41] = 1;
TABLE[95][303] = 1;
TABLE[95][301] = 1;
TABLE[95][298] = 1;
TABLE[95][297] = 1;
TABLE[95][125] = 1;
TABLE[95][93] = 1;
TABLE[95][58] = 1;
TABLE[95][44] = 1;
TABLE[95][302] = 1;
TABLE[95][292] = 1;
TABLE[95][304] = 1;
TABLE[95][43] = 1;
TABLE[95][45] = 1;
TABLE[95][40] = 1;
TABLE[95][278] = 1;
TABLE[95][37] = 1;
TABLE[95][47] = 1;
TABLE[95][42] = 1;
TABLE[95][38] = 1;
TABLE[95][126] = 1;
TABLE[95][33] = 1;
TABLE[95][294] = 1;
TABLE[95][295] = 1;
TABLE[95][289] = 1;
TABLE[95][299] = 1;
TABLE[95][308] = 1;
TABLE[95][306] = 1;
TABLE[95][307] = 1;
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
TABLE[249][292] = 1;
TABLE[249][304] = 1;
TABLE[249][43] = 1;
TABLE[249][45] = 1;
TABLE[249][40] = 1;
TABLE[249][278] = 1;
TABLE[249][37] = 1;
TABLE[249][47] = 1;
TABLE[249][42] = 1;
TABLE[249][38] = 1;
TABLE[249][126] = 1;
TABLE[249][33] = 1;
TABLE[249][294] = 1;
TABLE[249][295] = 1;
TABLE[249][289] = 1;
TABLE[249][299] = 1;
TABLE[249][308] = 1;
TABLE[249][306] = 1;
TABLE[249][307] = 1;
TABLE[249][63] = 1;
TABLE[249][59] = 1;
TABLE[249][41] = 1;
TABLE[249][302] = 1;
TABLE[249][303] = 1;
TABLE[249][301] = 1;
TABLE[249][298] = 1;
TABLE[249][297] = 1;
TABLE[249][125] = 1;
TABLE[249][93] = 1;
TABLE[249][58] = 1;
TABLE[249][44] = 1;
TABLE[96][63] = 1;
TABLE[96][59] = 1;
TABLE[96][41] = 1;
TABLE[96][302] = 1;
TABLE[96][303] = 1;
TABLE[96][301] = 1;
TABLE[96][298] = 1;
TABLE[96][297] = 1;
TABLE[96][125] = 1;
TABLE[96][93] = 1;
TABLE[96][58] = 1;
TABLE[96][44] = 1;
TABLE[96][292] = 1;
TABLE[96][304] = 1;
TABLE[96][40] = 1;
TABLE[96][45] = 1;
TABLE[96][43] = 1;
TABLE[96][42] = 1;
TABLE[96][47] = 1;
TABLE[96][37] = 1;
TABLE[96][278] = 1;
TABLE[96][295] = 1;
TABLE[96][294] = 1;
TABLE[96][33] = 1;
TABLE[96][126] = 1;
TABLE[96][38] = 1;
TABLE[96][299] = 1;
TABLE[96][289] = 1;
TABLE[96][307] = 1;
TABLE[96][306] = 1;
TABLE[96][308] = 1;
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
TABLE[250][304] = 1;
TABLE[250][40] = 1;
TABLE[250][45] = 1;
TABLE[250][43] = 1;
TABLE[250][42] = 1;
TABLE[250][47] = 1;
TABLE[250][37] = 1;
TABLE[250][278] = 1;
TABLE[250][295] = 1;
TABLE[250][294] = 1;
TABLE[250][33] = 1;
TABLE[250][126] = 1;
TABLE[250][38] = 1;
TABLE[250][299] = 1;
TABLE[250][289] = 1;
TABLE[250][307] = 1;
TABLE[250][306] = 1;
TABLE[250][308] = 1;
TABLE[250][63] = 1;
TABLE[250][59] = 1;
TABLE[250][41] = 1;
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
TABLE[97][63] = 1;
TABLE[97][59] = 1;
TABLE[97][41] = 1;
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
TABLE[97][304] = 1;
TABLE[97][43] = 1;
TABLE[97][45] = 1;
TABLE[97][40] = 1;
TABLE[97][278] = 1;
TABLE[97][37] = 1;
TABLE[97][47] = 1;
TABLE[97][42] = 1;
TABLE[97][38] = 1;
TABLE[97][126] = 1;
TABLE[97][33] = 1;
TABLE[97][294] = 1;
TABLE[97][295] = 1;
TABLE[97][289] = 1;
TABLE[97][299] = 1;
TABLE[97][308] = 1;
TABLE[97][306] = 1;
TABLE[97][307] = 1;
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
TABLE[251][43] = 1;
TABLE[251][45] = 1;
TABLE[251][40] = 1;
TABLE[251][278] = 1;
TABLE[251][37] = 1;
TABLE[251][47] = 1;
TABLE[251][42] = 1;
TABLE[251][38] = 1;
TABLE[251][126] = 1;
TABLE[251][33] = 1;
TABLE[251][294] = 1;
TABLE[251][295] = 1;
TABLE[251][289] = 1;
TABLE[251][299] = 1;
TABLE[251][308] = 1;
TABLE[251][306] = 1;
TABLE[251][307] = 1;
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
TABLE[98][63] = 1;
TABLE[98][59] = 1;
TABLE[98][41] = 1;
TABLE[98][304] = 1;
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
TABLE[98][45] = 1;
TABLE[98][43] = 1;
TABLE[98][40] = 1;
TABLE[98][42] = 1;
TABLE[98][47] = 1;
TABLE[98][37] = 1;
TABLE[98][278] = 1;
TABLE[98][295] = 1;
TABLE[98][294] = 1;
TABLE[98][33] = 1;
TABLE[98][126] = 1;
TABLE[98][38] = 1;
TABLE[98][299] = 1;
TABLE[98][289] = 1;
TABLE[98][307] = 1;
TABLE[98][306] = 1;
TABLE[98][308] = 1;
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
TABLE[252][40] = 1;
TABLE[252][42] = 1;
TABLE[252][47] = 1;
TABLE[252][37] = 1;
TABLE[252][278] = 1;
TABLE[252][295] = 1;
TABLE[252][294] = 1;
TABLE[252][33] = 1;
TABLE[252][126] = 1;
TABLE[252][45] = 1;
TABLE[252][43] = 1;
TABLE[252][38] = 1;
TABLE[252][299] = 1;
TABLE[252][289] = 1;
TABLE[252][307] = 1;
TABLE[252][306] = 1;
TABLE[252][308] = 1;
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
TABLE[186][43] = 1;
TABLE[187][45] = 1;
TABLE[99][40] = 1;
TABLE[99][37] = 1;
TABLE[99][47] = 1;
TABLE[99][42] = 1;
TABLE[99][278] = 1;
TABLE[99][38] = 1;
TABLE[99][43] = 1;
TABLE[99][45] = 1;
TABLE[99][126] = 1;
TABLE[99][33] = 1;
TABLE[99][294] = 1;
TABLE[99][295] = 1;
TABLE[99][289] = 1;
TABLE[99][299] = 1;
TABLE[99][308] = 1;
TABLE[99][306] = 1;
TABLE[99][307] = 1;
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
TABLE[253][40] = 1;
TABLE[253][278] = 1;
TABLE[253][38] = 1;
TABLE[253][42] = 1;
TABLE[253][43] = 1;
TABLE[253][45] = 1;
TABLE[253][126] = 1;
TABLE[253][33] = 1;
TABLE[253][294] = 1;
TABLE[253][295] = 1;
TABLE[253][289] = 1;
TABLE[253][299] = 1;
TABLE[253][308] = 1;
TABLE[253][306] = 1;
TABLE[253][307] = 1;
TABLE[189][42] = 1;
TABLE[190][47] = 1;
TABLE[191][37] = 1;
TABLE[100][278] = 1;
TABLE[100][295] = 1;
TABLE[100][294] = 1;
TABLE[100][33] = 1;
TABLE[100][126] = 1;
TABLE[100][45] = 1;
TABLE[100][43] = 1;
TABLE[100][42] = 1;
TABLE[100][38] = 1;
TABLE[100][299] = 1;
TABLE[100][289] = 1;
TABLE[100][40] = 1;
TABLE[100][307] = 1;
TABLE[100][306] = 1;
TABLE[100][308] = 1;
TABLE[101][40] = 1;
TABLE[102][40] = 1;
TABLE[102][289] = 1;
TABLE[102][299] = 1;
TABLE[102][308] = 1;
TABLE[102][306] = 1;
TABLE[102][307] = 1;
TABLE[103][294] = 1;
TABLE[103][295] = 1;
TABLE[104][38] = 1;
TABLE[104][42] = 1;
TABLE[104][43] = 1;
TABLE[104][45] = 1;
TABLE[104][126] = 1;
TABLE[104][33] = 1;
TABLE[105][278] = 1;
TABLE[106][278] = 1;
TABLE[193][294] = 1;
TABLE[194][295] = 1;
TABLE[107][38] = 1;
TABLE[108][42] = 1;
TABLE[109][43] = 1;
TABLE[110][45] = 1;
TABLE[111][126] = 1;
TABLE[112][33] = 1;
TABLE[113][299] = 1;
TABLE[113][289] = 1;
TABLE[113][40] = 1;
TABLE[113][307] = 1;
TABLE[113][306] = 1;
TABLE[113][308] = 1;
TABLE[114][40] = 1;
TABLE[114][289] = 1;
TABLE[114][299] = 1;
TABLE[114][308] = 1;
TABLE[114][306] = 1;
TABLE[114][307] = 1;
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
TABLE[254][41] = 1;
TABLE[115][299] = 1;
TABLE[116][308] = 1;
TABLE[116][306] = 1;
TABLE[116][307] = 1;
TABLE[116][299] = 1;
TABLE[117][289] = 1;
TABLE[118][40] = 1;
TABLE[119][41] = 1;
TABLE[119][44] = 1;
TABLE[119][278] = 1;
TABLE[119][63] = 1;
TABLE[119][38] = 1;
TABLE[119][42] = 1;
TABLE[119][43] = 1;
TABLE[119][45] = 1;
TABLE[119][126] = 1;
TABLE[119][33] = 1;
TABLE[119][294] = 1;
TABLE[119][295] = 1;
TABLE[119][297] = 1;
TABLE[119][40] = 1;
TABLE[119][289] = 1;
TABLE[119][299] = 1;
TABLE[119][298] = 1;
TABLE[119][308] = 1;
TABLE[119][306] = 1;
TABLE[119][307] = 1;
TABLE[119][301] = 1;
TABLE[119][303] = 1;
TABLE[119][302] = 1;
TABLE[119][292] = 1;
TABLE[119][304] = 1;
TABLE[119][47] = 1;
TABLE[119][37] = 1;
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
TABLE[255][278] = 1;
TABLE[255][63] = 1;
TABLE[255][38] = 1;
TABLE[255][42] = 1;
TABLE[255][43] = 1;
TABLE[255][45] = 1;
TABLE[255][126] = 1;
TABLE[255][33] = 1;
TABLE[255][294] = 1;
TABLE[255][295] = 1;
TABLE[255][297] = 1;
TABLE[255][40] = 1;
TABLE[255][289] = 1;
TABLE[255][299] = 1;
TABLE[255][298] = 1;
TABLE[255][308] = 1;
TABLE[255][306] = 1;
TABLE[255][307] = 1;
TABLE[255][301] = 1;
TABLE[255][303] = 1;
TABLE[255][302] = 1;
TABLE[255][292] = 1;
TABLE[255][304] = 1;
TABLE[255][47] = 1;
TABLE[255][37] = 1;
TABLE[255][41] = 1;
TABLE[255][44] = 1;
TABLE[120][308] = 1;
TABLE[121][306] = 1;
TABLE[122][307] = 1;
TABLE[123][299] = 1;
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
      case 267: return 1; break;
      case 277: return 1; break;
      case 284: return 0; break;
      case 297: return 1; break;
      case 304: return 1; break;
      case 309: return 1; break;
      case 317: return 0; break;
      case 322: return 1; break;
      case 330: return 1; break;
      case 335: return 1; break;
      case 342: return 0; break;
      case 357: return 0; break;
      case 375: return 1; break;
      case 382: return 1; break;
      case 389: return 0; break;
      case 395: return 1; break;
      case 402: return 1; break;
      case 409: return 1; break;
      case 414: return 1; break;
      case 421: return 1; break;
      case 426: return 1; break;
      case 434: return 1; break;
      case 439: return 1; break;
      case 447: return 0; break;
      case 452: return 1; break;
      case 460: return 1; break;
      case 467: return 1; break;
      case 472: return 1; break;
      case 480: return 1; break;
      case 491: return 1; break;
      case 498: return 1; break;
      case 503: return 1; break;
      case 511: return 0; break;
      case 516: return 1; break;
      case 523: return 1; break;
      case 532: return 1; break;
      case 539: return 1; break;
      case 550: return 1; break;
      case 557: return 0; break;
      case 569: return 1; break;
      case 576: return 1; break;
      case 583: return 0; break;
      case 587: return 1; break;
      case 611: return 0; break;
      case 630: return 1; break;
      case 635: return 1; break;
      case 642: return 0; break;
      case 649: return 1; break;
      case 656: return 1; break;
      case 663: return 1; break;
      case 668: return 1; break;
      case 675: return 0; break;
      case 692: return 1; break;
      case 700: return 0; break;
      case 730: return 1; break;
      case 737: return 1; break;
      case 744: return 1; break;
      case 751: return 0; break;
      case 773: return 1; break;
      case 780: return 1; break;
      case 785: return 1; break;
      case 793: return 1; break;
      case 803: return 0; break;
      case 811: return 1; break;
      case 816: return 1; break;
      case 826: return 1; break;
      case 830: return 1; break;
      case 835: return 1; break;
      case 843: return 1; break;
      case 848: return 1; break;
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
      case 934: return 0; break;
      case 942: return 1; break;
      case 947: return 1; break;
      case 955: return 0; break;
      case 967: return 0; break;
      case 978: return 0; break;
      case 1004: return 0; break;
      case 1012: return 0; break;
      case 1036: return 0; break;
      case 1045: return 0; break;
      case 1075: return 1; break;
      case 1082: return 0; break;
      case 1100: return 1; break;
      case 1105: return 1; break;
      case 1113: return 0; break;
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
         case 267: return "struct_declarator"; break;
         case 277: return "Subphrase"; break;
         case 284: return "enum_specifier"; break;
         case 297: return "Subphrase"; break;
         case 304: return "enumerator_list"; break;
         case 309: return "Subphrase"; break;
         case 317: return "enumerator"; break;
         case 322: return "Subphrase"; break;
         case 330: return "declarator"; break;
         case 335: return "Subphrase"; break;
         case 342: return "direct_declarator"; break;
         case 357: return "Subphrase"; break;
         case 375: return "Subphrase"; break;
         case 382: return "Subphrase"; break;
         case 389: return "pointer"; break;
         case 395: return "Subphrase"; break;
         case 402: return "Subphrase"; break;
         case 409: return "type_qualifier_list"; break;
         case 414: return "Subphrase"; break;
         case 421: return "parameter_type_list"; break;
         case 426: return "Subphrase"; break;
         case 434: return "parameter_list"; break;
         case 439: return "Subphrase"; break;
         case 447: return "parameter_declaration"; break;
         case 452: return "Subphrase"; break;
         case 460: return "Subphrase"; break;
         case 467: return "identifier_list"; break;
         case 472: return "Subphrase"; break;
         case 480: return "initializer"; break;
         case 491: return "Subphrase"; break;
         case 498: return "initializer_list"; break;
         case 503: return "Subphrase"; break;
         case 511: return "type_name"; break;
         case 516: return "Subphrase"; break;
         case 523: return "abstract_declarator"; break;
         case 532: return "Subphrase"; break;
         case 539: return "direct_abstract_declarator"; break;
         case 550: return "Subphrase"; break;
         case 557: return "Subphrase"; break;
         case 569: return "Subphrase"; break;
         case 576: return "Subphrase"; break;
         case 583: return "typedef_name"; break;
         case 587: return "statement"; break;
         case 611: return "labeled_statement"; break;
         case 630: return "expression_statement"; break;
         case 635: return "Subphrase"; break;
         case 642: return "compound_statement"; break;
         case 649: return "Subphrase"; break;
         case 656: return "Subphrase"; break;
         case 663: return "statement_list"; break;
         case 668: return "Subphrase"; break;
         case 675: return "selection_statement"; break;
         case 692: return "Subphrase"; break;
         case 700: return "iteration_statement"; break;
         case 730: return "Subphrase"; break;
         case 737: return "Subphrase"; break;
         case 744: return "Subphrase"; break;
         case 751: return "jump_statement"; break;
         case 773: return "Subphrase"; break;
         case 780: return "expression"; break;
         case 785: return "Subphrase"; break;
         case 793: return "assignment_expression"; break;
         case 803: return "assignment_operator"; break;
         case 811: return "conditional_expression"; break;
         case 816: return "Subphrase"; break;
         case 826: return "constant_expression"; break;
         case 830: return "logical_OR_expression"; break;
         case 835: return "Subphrase"; break;
         case 843: return "logical_AND_expression"; break;
         case 848: return "Subphrase"; break;
         case 856: return "inclusive_OR_expression"; break;
         case 861: return "Subphrase"; break;
         case 869: return "exclusive_OR_expression"; break;
         case 874: return "Subphrase"; break;
         case 882: return "AND_expression"; break;
         case 887: return "Subphrase"; break;
         case 895: return "equality_expression"; break;
         case 900: return "Subphrase"; break;
         case 908: return "shift_expression"; break;
         case 913: return "Subphrase"; break;
         case 921: return "additive_expression"; break;
         case 926: return "Subphrase"; break;
         case 934: return "Subphrase"; break;
         case 942: return "multiplicative_expression"; break;
         case 947: return "Subphrase"; break;
         case 955: return "Subphrase"; break;
         case 967: return "cast_expression"; break;
         case 978: return "unary_expression"; break;
         case 1004: return "Subphrase"; break;
         case 1012: return "unary_operator"; break;
         case 1036: return "postfix_expression"; break;
         case 1045: return "Subphrase"; break;
         case 1075: return "Subphrase"; break;
         case 1082: return "primary_expression"; break;
         case 1100: return "argument_expression_list"; break;
         case 1105: return "Subphrase"; break;
         case 1113: return "constant"; break;
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
