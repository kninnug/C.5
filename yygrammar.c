#line 1 "ass2.y"

#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("%u: Syntax error\n", yypos);
}


# line 17 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 197: {
      primary_expression();
      get_lexval();
      } break;
   }
}

primary_expression ()
{
   switch(yyselect()) {
   case 1: {
      get_lexval();
      } break;
   case 2: {
      get_lexval();
      } break;
   case 3: {
      get_lexval();
      } break;
   case 4: {
      get_lexval();
      expression();
      get_lexval();
      } break;
   }
}

postfix_expression ()
{
   switch(yyselect()) {
   case 5: {
      primary_expression();
      } break;
   case 6: {
      postfix_expression();
      get_lexval();
      expression();
      get_lexval();
      } break;
   case 7: {
      postfix_expression();
      get_lexval();
      get_lexval();
      } break;
   case 8: {
      postfix_expression();
      get_lexval();
      argument_expression_list();
      get_lexval();
      } break;
   case 9: {
      postfix_expression();
      get_lexval();
      get_lexval();
      } break;
   case 10: {
      postfix_expression();
      get_lexval();
      get_lexval();
      } break;
   case 11: {
      postfix_expression();
      get_lexval();
      } break;
   case 12: {
      postfix_expression();
      get_lexval();
      } break;
   }
}

argument_expression_list ()
{
   switch(yyselect()) {
   case 13: {
      assignment_expression();
      } break;
   case 14: {
      argument_expression_list();
      get_lexval();
      assignment_expression();
      } break;
   }
}

unary_expression ()
{
   switch(yyselect()) {
   case 15: {
      postfix_expression();
      } break;
   case 16: {
      get_lexval();
      unary_expression();
      } break;
   case 17: {
      get_lexval();
      unary_expression();
      } break;
   case 18: {
      unary_operator();
      cast_expression();
      } break;
   case 19: {
      get_lexval();
      unary_expression();
      } break;
   case 20: {
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
   case 21: {
      get_lexval();
      } break;
   case 22: {
      get_lexval();
      } break;
   case 23: {
      get_lexval();
      } break;
   case 24: {
      get_lexval();
      } break;
   case 25: {
      get_lexval();
      } break;
   case 26: {
      get_lexval();
      } break;
   }
}

cast_expression ()
{
   switch(yyselect()) {
   case 27: {
      unary_expression();
      } break;
   case 28: {
      get_lexval();
      type_name();
      get_lexval();
      cast_expression();
      } break;
   }
}

multiplicative_expression ()
{
   switch(yyselect()) {
   case 29: {
      cast_expression();
      } break;
   case 30: {
      multiplicative_expression();
      get_lexval();
      cast_expression();
      } break;
   case 31: {
      multiplicative_expression();
      get_lexval();
      cast_expression();
      } break;
   case 32: {
      multiplicative_expression();
      get_lexval();
      cast_expression();
      } break;
   }
}

additive_expression ()
{
   switch(yyselect()) {
   case 33: {
      multiplicative_expression();
      } break;
   case 34: {
      additive_expression();
      get_lexval();
      multiplicative_expression();
      } break;
   case 35: {
      additive_expression();
      get_lexval();
      multiplicative_expression();
      } break;
   }
}

shift_expression ()
{
   switch(yyselect()) {
   case 36: {
      additive_expression();
      } break;
   case 37: {
      shift_expression();
      get_lexval();
      additive_expression();
      } break;
   }
}

relational_expression ()
{
   switch(yyselect()) {
   case 38: {
      shift_expression();
      } break;
   case 39: {
      relational_expression();
      get_lexval();
      shift_expression();
      } break;
   }
}

equality_expression ()
{
   switch(yyselect()) {
   case 40: {
      relational_expression();
      } break;
   case 41: {
      equality_expression();
      get_lexval();
      relational_expression();
      } break;
   }
}

and_expression ()
{
   switch(yyselect()) {
   case 42: {
      equality_expression();
      } break;
   case 43: {
      and_expression();
      get_lexval();
      equality_expression();
      } break;
   }
}

exclusive_or_expression ()
{
   switch(yyselect()) {
   case 44: {
      and_expression();
      } break;
   case 45: {
      exclusive_or_expression();
      get_lexval();
      and_expression();
      } break;
   }
}

inclusive_or_expression ()
{
   switch(yyselect()) {
   case 46: {
      exclusive_or_expression();
      } break;
   case 47: {
      inclusive_or_expression();
      get_lexval();
      exclusive_or_expression();
      } break;
   }
}

logical_and_expression ()
{
   switch(yyselect()) {
   case 48: {
      inclusive_or_expression();
      } break;
   case 49: {
      logical_and_expression();
      get_lexval();
      inclusive_or_expression();
      } break;
   }
}

logical_or_expression ()
{
   switch(yyselect()) {
   case 50: {
      logical_and_expression();
      } break;
   case 51: {
      logical_or_expression();
      get_lexval();
      logical_and_expression();
      } break;
   }
}

conditional_expression ()
{
   switch(yyselect()) {
   case 52: {
      logical_or_expression();
      } break;
   case 53: {
      logical_or_expression();
      get_lexval();
      expression();
      get_lexval();
      conditional_expression();
      } break;
   }
}

assignment_expression ()
{
   switch(yyselect()) {
   case 54: {
      conditional_expression();
      } break;
   case 55: {
      unary_expression();
      assignment_operator();
      assignment_expression();
      } break;
   }
}

assignment_operator ()
{
   switch(yyselect()) {
   case 56: {
      get_lexval();
      } break;
   }
}

expression ()
{
   switch(yyselect()) {
   case 57: {
      assignment_expression();
      } break;
   case 58: {
      expression();
      get_lexval();
      assignment_expression();
      } break;
   }
}

constant_expression ()
{
   switch(yyselect()) {
   case 59: {
      conditional_expression();
      } break;
   }
}

declaration ()
{
   switch(yyselect()) {
   case 60: {
      declaration_specifiers();
      get_lexval();
      } break;
   case 61: {
      declaration_specifiers();
      init_declarator_list();
      get_lexval();
      } break;
   }
}

declaration_specifiers ()
{
   switch(yyselect()) {
   case 62: {
      storage_class_specifier();
      } break;
   case 63: {
      storage_class_specifier();
      declaration_specifiers();
      } break;
   case 64: {
      type_specifier();
      } break;
   case 65: {
      type_specifier();
      declaration_specifiers();
      } break;
   case 66: {
      type_qualifier();
      } break;
   case 67: {
      type_qualifier();
      declaration_specifiers();
      } break;
   }
}

init_declarator_list ()
{
   switch(yyselect()) {
   case 68: {
      init_declarator();
      } break;
   case 69: {
      init_declarator_list();
      get_lexval();
      init_declarator();
      } break;
   }
}

init_declarator ()
{
   switch(yyselect()) {
   case 70: {
      declarator();
      } break;
   case 71: {
      declarator();
      get_lexval();
      initializer();
      } break;
   }
}

storage_class_specifier ()
{
   switch(yyselect()) {
   case 72: {
      get_lexval();
      } break;
   case 73: {
      get_lexval();
      } break;
   case 74: {
      get_lexval();
      } break;
   case 75: {
      get_lexval();
      } break;
   case 76: {
      get_lexval();
      } break;
   }
}

type_specifier ()
{
   switch(yyselect()) {
   case 77: {
      get_lexval();
      } break;
   case 78: {
      get_lexval();
      } break;
   case 79: {
      get_lexval();
      } break;
   case 80: {
      get_lexval();
      } break;
   case 81: {
      get_lexval();
      } break;
   case 82: {
      get_lexval();
      } break;
   case 83: {
      get_lexval();
      } break;
   case 84: {
      get_lexval();
      } break;
   case 85: {
      get_lexval();
      } break;
   case 86: {
      struct_or_union_specifier();
      } break;
   case 87: {
      enum_specifier();
      } break;
   case 88: {
      get_lexval();
      } break;
   }
}

struct_or_union_specifier ()
{
   switch(yyselect()) {
   case 89: {
      struct_or_union();
      get_lexval();
      get_lexval();
      struct_declaration_list();
      get_lexval();
      } break;
   case 90: {
      struct_or_union();
      get_lexval();
      struct_declaration_list();
      get_lexval();
      } break;
   case 91: {
      struct_or_union();
      get_lexval();
      } break;
   }
}

struct_or_union ()
{
   switch(yyselect()) {
   case 92: {
      get_lexval();
      } break;
   case 93: {
      get_lexval();
      } break;
   }
}

struct_declaration_list ()
{
   switch(yyselect()) {
   case 94: {
      struct_declaration();
      } break;
   case 95: {
      struct_declaration_list();
      struct_declaration();
      } break;
   }
}

struct_declaration ()
{
   switch(yyselect()) {
   case 96: {
      specifier_qualifier_list();
      struct_declarator_list();
      get_lexval();
      } break;
   }
}

specifier_qualifier_list ()
{
   switch(yyselect()) {
   case 97: {
      type_specifier();
      specifier_qualifier_list();
      } break;
   case 98: {
      type_specifier();
      } break;
   case 99: {
      type_qualifier();
      specifier_qualifier_list();
      } break;
   case 100: {
      type_qualifier();
      } break;
   }
}

struct_declarator_list ()
{
   switch(yyselect()) {
   case 101: {
      struct_declarator();
      } break;
   case 102: {
      struct_declarator_list();
      get_lexval();
      struct_declarator();
      } break;
   }
}

struct_declarator ()
{
   switch(yyselect()) {
   case 103: {
      declarator();
      } break;
   case 104: {
      get_lexval();
      constant_expression();
      } break;
   case 105: {
      declarator();
      get_lexval();
      constant_expression();
      } break;
   }
}

enum_specifier ()
{
   switch(yyselect()) {
   case 106: {
      get_lexval();
      get_lexval();
      enumerator_list();
      get_lexval();
      } break;
   case 107: {
      get_lexval();
      get_lexval();
      get_lexval();
      enumerator_list();
      get_lexval();
      } break;
   case 108: {
      get_lexval();
      get_lexval();
      } break;
   }
}

enumerator_list ()
{
   switch(yyselect()) {
   case 109: {
      enumerator();
      } break;
   case 110: {
      enumerator_list();
      get_lexval();
      enumerator();
      } break;
   }
}

enumerator ()
{
   switch(yyselect()) {
   case 111: {
      get_lexval();
      } break;
   case 112: {
      get_lexval();
      get_lexval();
      constant_expression();
      } break;
   }
}

type_qualifier ()
{
   switch(yyselect()) {
   case 113: {
      get_lexval();
      } break;
   case 114: {
      get_lexval();
      } break;
   }
}

declarator ()
{
   switch(yyselect()) {
   case 115: {
      pointer();
      direct_declarator();
      } break;
   case 116: {
      direct_declarator();
      } break;
   }
}

direct_declarator ()
{
   switch(yyselect()) {
   case 117: {
      get_lexval();
      } break;
   case 118: {
      get_lexval();
      declarator();
      get_lexval();
      } break;
   case 119: {
      direct_declarator();
      get_lexval();
      constant_expression();
      get_lexval();
      } break;
   case 120: {
      direct_declarator();
      get_lexval();
      get_lexval();
      } break;
   case 121: {
      direct_declarator();
      get_lexval();
      parameter_type_list();
      get_lexval();
      } break;
   case 122: {
      direct_declarator();
      get_lexval();
      identifier_list();
      get_lexval();
      } break;
   case 123: {
      direct_declarator();
      get_lexval();
      get_lexval();
      } break;
   }
}

pointer ()
{
   switch(yyselect()) {
   case 124: {
      get_lexval();
      } break;
   case 125: {
      get_lexval();
      type_qualifier_list();
      } break;
   case 126: {
      get_lexval();
      pointer();
      } break;
   case 127: {
      get_lexval();
      type_qualifier_list();
      pointer();
      } break;
   }
}

type_qualifier_list ()
{
   switch(yyselect()) {
   case 128: {
      type_qualifier();
      } break;
   case 129: {
      type_qualifier_list();
      type_qualifier();
      } break;
   }
}

parameter_type_list ()
{
   switch(yyselect()) {
   case 130: {
      parameter_list();
      } break;
   case 131: {
      parameter_list();
      get_lexval();
      get_lexval();
      } break;
   }
}

parameter_list ()
{
   switch(yyselect()) {
   case 132: {
      parameter_declaration();
      } break;
   case 133: {
      parameter_list();
      get_lexval();
      parameter_declaration();
      } break;
   }
}

parameter_declaration ()
{
   switch(yyselect()) {
   case 134: {
      declaration_specifiers();
      declarator();
      } break;
   case 135: {
      declaration_specifiers();
      abstract_declarator();
      } break;
   case 136: {
      declaration_specifiers();
      } break;
   }
}

identifier_list ()
{
   switch(yyselect()) {
   case 137: {
      get_lexval();
      } break;
   case 138: {
      identifier_list();
      get_lexval();
      get_lexval();
      } break;
   }
}

type_name ()
{
   switch(yyselect()) {
   case 139: {
      specifier_qualifier_list();
      } break;
   case 140: {
      specifier_qualifier_list();
      abstract_declarator();
      } break;
   }
}

abstract_declarator ()
{
   switch(yyselect()) {
   case 141: {
      pointer();
      } break;
   case 142: {
      direct_abstract_declarator();
      } break;
   case 143: {
      pointer();
      direct_abstract_declarator();
      } break;
   }
}

direct_abstract_declarator ()
{
   switch(yyselect()) {
   case 144: {
      get_lexval();
      abstract_declarator();
      get_lexval();
      } break;
   case 145: {
      get_lexval();
      get_lexval();
      } break;
   case 146: {
      get_lexval();
      constant_expression();
      get_lexval();
      } break;
   case 147: {
      direct_abstract_declarator();
      get_lexval();
      get_lexval();
      } break;
   case 148: {
      direct_abstract_declarator();
      get_lexval();
      constant_expression();
      get_lexval();
      } break;
   case 149: {
      get_lexval();
      get_lexval();
      } break;
   case 150: {
      get_lexval();
      parameter_type_list();
      get_lexval();
      } break;
   case 151: {
      direct_abstract_declarator();
      get_lexval();
      get_lexval();
      } break;
   case 152: {
      direct_abstract_declarator();
      get_lexval();
      parameter_type_list();
      get_lexval();
      } break;
   }
}

initializer ()
{
   switch(yyselect()) {
   case 153: {
      assignment_expression();
      } break;
   case 154: {
      get_lexval();
      initializer_list();
      get_lexval();
      } break;
   case 155: {
      get_lexval();
      initializer_list();
      get_lexval();
      get_lexval();
      } break;
   }
}

initializer_list ()
{
   switch(yyselect()) {
   case 156: {
      initializer();
      } break;
   case 157: {
      initializer_list();
      get_lexval();
      initializer();
      } break;
   }
}

statement ()
{
   switch(yyselect()) {
   case 158: {
      labeled_statement();
      } break;
   case 159: {
      compound_statement();
      } break;
   case 160: {
      expression_statement();
      } break;
   case 161: {
      selection_statement();
      } break;
   case 162: {
      iteration_statement();
      } break;
   case 163: {
      jump_statement();
      } break;
   }
}

labeled_statement ()
{
   switch(yyselect()) {
   case 164: {
      get_lexval();
      get_lexval();
      statement();
      } break;
   case 165: {
      get_lexval();
      constant_expression();
      get_lexval();
      statement();
      } break;
   case 166: {
      get_lexval();
      get_lexval();
      statement();
      } break;
   }
}

compound_statement ()
{
   switch(yyselect()) {
   case 167: {
      get_lexval();
      get_lexval();
      } break;
   case 168: {
      get_lexval();
      statement_list();
      get_lexval();
      } break;
   case 169: {
      get_lexval();
      declaration_list();
      get_lexval();
      } break;
   case 170: {
      get_lexval();
      declaration_list();
      statement_list();
      get_lexval();
      } break;
   }
}

declaration_list ()
{
   switch(yyselect()) {
   case 171: {
      declaration();
      } break;
   case 172: {
      declaration_list();
      declaration();
      } break;
   }
}

statement_list ()
{
   switch(yyselect()) {
   case 173: {
      statement();
      } break;
   case 174: {
      statement_list();
      statement();
      } break;
   }
}

expression_statement ()
{
   switch(yyselect()) {
   case 175: {
      get_lexval();
      } break;
   case 176: {
      expression();
      get_lexval();
      } break;
   }
}

selection_statement ()
{
   switch(yyselect()) {
   case 177: {
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      statement();
      } break;
   case 178: {
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      statement();
      get_lexval();
      statement();
      } break;
   case 179: {
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
   case 180: {
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      statement();
      } break;
   case 181: {
      get_lexval();
      statement();
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      get_lexval();
      } break;
   case 182: {
      get_lexval();
      get_lexval();
      expression_statement();
      expression_statement();
      get_lexval();
      statement();
      } break;
   case 183: {
      get_lexval();
      get_lexval();
      expression_statement();
      expression_statement();
      expression();
      get_lexval();
      statement();
      } break;
   }
}

jump_statement ()
{
   switch(yyselect()) {
   case 184: {
      get_lexval();
      get_lexval();
      get_lexval();
      } break;
   case 185: {
      get_lexval();
      get_lexval();
      } break;
   case 186: {
      get_lexval();
      get_lexval();
      } break;
   case 187: {
      get_lexval();
      get_lexval();
      } break;
   case 188: {
      get_lexval();
      expression();
      get_lexval();
      } break;
   }
}

root ()
{
   switch(yyselect()) {
   case 189: {
      external_declaration();
      } break;
   case 190: {
      root();
      external_declaration();
      } break;
   }
}

external_declaration ()
{
   switch(yyselect()) {
   case 191: {
      function_definition();
      } break;
   case 192: {
      declaration();
      } break;
   }
}

function_definition ()
{
   switch(yyselect()) {
   case 193: {
      declaration_specifiers();
      declarator();
      declaration_list();
      compound_statement();
      } break;
   case 194: {
      declaration_specifiers();
      declarator();
      compound_statement();
      } break;
   case 195: {
      declarator();
      declaration_list();
      compound_statement();
      } break;
   case 196: {
      declarator();
      compound_statement();
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
int c_length = 1016;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 197,
/* 6 */ 10,
/* 7 */ 50298,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 14,
/* 11 */ 50288,
/* 12 */ -6,
/* 13 */ 2,
/* 14 */ 18,
/* 15 */ 50289,
/* 16 */ -6,
/* 17 */ 3,
/* 18 */ 0,
/* 19 */ 50040,
/* 20 */ 290,
/* 21 */ 50041,
/* 22 */ -6,
/* 23 */ 4,
/* 24 */ 28,
/* 25 */ 6,
/* 26 */ -24,
/* 27 */ 5,
/* 28 */ 35,
/* 29 */ 24,
/* 30 */ 50091,
/* 31 */ 290,
/* 32 */ 50093,
/* 33 */ -24,
/* 34 */ 6,
/* 35 */ 41,
/* 36 */ 24,
/* 37 */ 50040,
/* 38 */ 50041,
/* 39 */ -24,
/* 40 */ 7,
/* 41 */ 48,
/* 42 */ 24,
/* 43 */ 50040,
/* 44 */ 70,
/* 45 */ 50041,
/* 46 */ -24,
/* 47 */ 8,
/* 48 */ 54,
/* 49 */ 24,
/* 50 */ 50046,
/* 51 */ 50298,
/* 52 */ -24,
/* 53 */ 9,
/* 54 */ 60,
/* 55 */ 24,
/* 56 */ 50296,
/* 57 */ 50298,
/* 58 */ -24,
/* 59 */ 10,
/* 60 */ 65,
/* 61 */ 24,
/* 62 */ 50294,
/* 63 */ -24,
/* 64 */ 11,
/* 65 */ 0,
/* 66 */ 24,
/* 67 */ 50295,
/* 68 */ -24,
/* 69 */ 12,
/* 70 */ 74,
/* 71 */ 276,
/* 72 */ -70,
/* 73 */ 13,
/* 74 */ 0,
/* 75 */ 70,
/* 76 */ 50044,
/* 77 */ 276,
/* 78 */ -70,
/* 79 */ 14,
/* 80 */ 84,
/* 81 */ 24,
/* 82 */ -80,
/* 83 */ 15,
/* 84 */ 89,
/* 85 */ 50294,
/* 86 */ 80,
/* 87 */ -80,
/* 88 */ 16,
/* 89 */ 94,
/* 90 */ 50295,
/* 91 */ 80,
/* 92 */ -80,
/* 93 */ 17,
/* 94 */ 99,
/* 95 */ 111,
/* 96 */ 135,
/* 97 */ -80,
/* 98 */ 18,
/* 99 */ 104,
/* 100 */ 50278,
/* 101 */ 80,
/* 102 */ -80,
/* 103 */ 19,
/* 104 */ 0,
/* 105 */ 50278,
/* 106 */ 50040,
/* 107 */ 689,
/* 108 */ 50041,
/* 109 */ -80,
/* 110 */ 20,
/* 111 */ 115,
/* 112 */ 50038,
/* 113 */ -111,
/* 114 */ 21,
/* 115 */ 119,
/* 116 */ 50042,
/* 117 */ -111,
/* 118 */ 22,
/* 119 */ 123,
/* 120 */ 50043,
/* 121 */ -111,
/* 122 */ 23,
/* 123 */ 127,
/* 124 */ 50045,
/* 125 */ -111,
/* 126 */ 24,
/* 127 */ 131,
/* 128 */ 50126,
/* 129 */ -111,
/* 130 */ 25,
/* 131 */ 0,
/* 132 */ 50033,
/* 133 */ -111,
/* 134 */ 26,
/* 135 */ 139,
/* 136 */ 80,
/* 137 */ -135,
/* 138 */ 27,
/* 139 */ 0,
/* 140 */ 50040,
/* 141 */ 689,
/* 142 */ 50041,
/* 143 */ 135,
/* 144 */ -135,
/* 145 */ 28,
/* 146 */ 150,
/* 147 */ 135,
/* 148 */ -146,
/* 149 */ 29,
/* 150 */ 156,
/* 151 */ 146,
/* 152 */ 50042,
/* 153 */ 135,
/* 154 */ -146,
/* 155 */ 30,
/* 156 */ 162,
/* 157 */ 146,
/* 158 */ 50047,
/* 159 */ 135,
/* 160 */ -146,
/* 161 */ 31,
/* 162 */ 0,
/* 163 */ 146,
/* 164 */ 50037,
/* 165 */ 135,
/* 166 */ -146,
/* 167 */ 32,
/* 168 */ 172,
/* 169 */ 146,
/* 170 */ -168,
/* 171 */ 33,
/* 172 */ 178,
/* 173 */ 168,
/* 174 */ 50043,
/* 175 */ 146,
/* 176 */ -168,
/* 177 */ 34,
/* 178 */ 0,
/* 179 */ 168,
/* 180 */ 50045,
/* 181 */ 146,
/* 182 */ -168,
/* 183 */ 35,
/* 184 */ 188,
/* 185 */ 168,
/* 186 */ -184,
/* 187 */ 36,
/* 188 */ 0,
/* 189 */ 184,
/* 190 */ 50293,
/* 191 */ 168,
/* 192 */ -184,
/* 193 */ 37,
/* 194 */ 198,
/* 195 */ 184,
/* 196 */ -194,
/* 197 */ 38,
/* 198 */ 0,
/* 199 */ 194,
/* 200 */ 50292,
/* 201 */ 184,
/* 202 */ -194,
/* 203 */ 39,
/* 204 */ 208,
/* 205 */ 194,
/* 206 */ -204,
/* 207 */ 40,
/* 208 */ 0,
/* 209 */ 204,
/* 210 */ 50292,
/* 211 */ 194,
/* 212 */ -204,
/* 213 */ 41,
/* 214 */ 218,
/* 215 */ 204,
/* 216 */ -214,
/* 217 */ 42,
/* 218 */ 0,
/* 219 */ 214,
/* 220 */ 50038,
/* 221 */ 204,
/* 222 */ -214,
/* 223 */ 43,
/* 224 */ 228,
/* 225 */ 214,
/* 226 */ -224,
/* 227 */ 44,
/* 228 */ 0,
/* 229 */ 224,
/* 230 */ 50094,
/* 231 */ 214,
/* 232 */ -224,
/* 233 */ 45,
/* 234 */ 238,
/* 235 */ 224,
/* 236 */ -234,
/* 237 */ 46,
/* 238 */ 0,
/* 239 */ 234,
/* 240 */ 50124,
/* 241 */ 224,
/* 242 */ -234,
/* 243 */ 47,
/* 244 */ 248,
/* 245 */ 234,
/* 246 */ -244,
/* 247 */ 48,
/* 248 */ 0,
/* 249 */ 244,
/* 250 */ 50297,
/* 251 */ 234,
/* 252 */ -244,
/* 253 */ 49,
/* 254 */ 258,
/* 255 */ 244,
/* 256 */ -254,
/* 257 */ 50,
/* 258 */ 0,
/* 259 */ 254,
/* 260 */ 50297,
/* 261 */ 244,
/* 262 */ -254,
/* 263 */ 51,
/* 264 */ 268,
/* 265 */ 254,
/* 266 */ -264,
/* 267 */ 52,
/* 268 */ 0,
/* 269 */ 254,
/* 270 */ 50063,
/* 271 */ 290,
/* 272 */ 50058,
/* 273 */ 264,
/* 274 */ -264,
/* 275 */ 53,
/* 276 */ 280,
/* 277 */ 264,
/* 278 */ -276,
/* 279 */ 54,
/* 280 */ 0,
/* 281 */ 80,
/* 282 */ 286,
/* 283 */ 276,
/* 284 */ -276,
/* 285 */ 55,
/* 286 */ 0,
/* 287 */ 50291,
/* 288 */ -286,
/* 289 */ 56,
/* 290 */ 294,
/* 291 */ 276,
/* 292 */ -290,
/* 293 */ 57,
/* 294 */ 0,
/* 295 */ 290,
/* 296 */ 50044,
/* 297 */ 276,
/* 298 */ -290,
/* 299 */ 58,
/* 300 */ 0,
/* 301 */ 264,
/* 302 */ -300,
/* 303 */ 59,
/* 304 */ 309,
/* 305 */ 315,
/* 306 */ 50059,
/* 307 */ -304,
/* 308 */ 60,
/* 309 */ 0,
/* 310 */ 315,
/* 311 */ 342,
/* 312 */ 50059,
/* 313 */ -304,
/* 314 */ 61,
/* 315 */ 319,
/* 316 */ 362,
/* 317 */ -315,
/* 318 */ 62,
/* 319 */ 324,
/* 320 */ 362,
/* 321 */ 315,
/* 322 */ -315,
/* 323 */ 63,
/* 324 */ 328,
/* 325 */ 382,
/* 326 */ -315,
/* 327 */ 64,
/* 328 */ 333,
/* 329 */ 382,
/* 330 */ 315,
/* 331 */ -315,
/* 332 */ 65,
/* 333 */ 337,
/* 334 */ 556,
/* 335 */ -315,
/* 336 */ 66,
/* 337 */ 0,
/* 338 */ 556,
/* 339 */ 315,
/* 340 */ -315,
/* 341 */ 67,
/* 342 */ 346,
/* 343 */ 352,
/* 344 */ -342,
/* 345 */ 68,
/* 346 */ 0,
/* 347 */ 342,
/* 348 */ 50044,
/* 349 */ 352,
/* 350 */ -342,
/* 351 */ 69,
/* 352 */ 356,
/* 353 */ 564,
/* 354 */ -352,
/* 355 */ 70,
/* 356 */ 0,
/* 357 */ 564,
/* 358 */ 50061,
/* 359 */ 765,
/* 360 */ -352,
/* 361 */ 71,
/* 362 */ 366,
/* 363 */ 50282,
/* 364 */ -362,
/* 365 */ 72,
/* 366 */ 370,
/* 367 */ 50267,
/* 368 */ -362,
/* 369 */ 73,
/* 370 */ 374,
/* 371 */ 50279,
/* 372 */ -362,
/* 373 */ 74,
/* 374 */ 378,
/* 375 */ 50256,
/* 376 */ -362,
/* 377 */ 75,
/* 378 */ 0,
/* 379 */ 50274,
/* 380 */ -362,
/* 381 */ 76,
/* 382 */ 386,
/* 383 */ 50285,
/* 384 */ -382,
/* 385 */ 77,
/* 386 */ 390,
/* 387 */ 50259,
/* 388 */ -382,
/* 389 */ 78,
/* 390 */ 394,
/* 391 */ 50276,
/* 392 */ -382,
/* 393 */ 79,
/* 394 */ 398,
/* 395 */ 50272,
/* 396 */ -382,
/* 397 */ 80,
/* 398 */ 402,
/* 399 */ 50273,
/* 400 */ -382,
/* 401 */ 81,
/* 402 */ 406,
/* 403 */ 50268,
/* 404 */ -382,
/* 405 */ 82,
/* 406 */ 410,
/* 407 */ 50264,
/* 408 */ -382,
/* 409 */ 83,
/* 410 */ 414,
/* 411 */ 50277,
/* 412 */ -382,
/* 413 */ 84,
/* 414 */ 418,
/* 415 */ 50284,
/* 416 */ -382,
/* 417 */ 85,
/* 418 */ 422,
/* 419 */ 430,
/* 420 */ -382,
/* 421 */ 86,
/* 422 */ 426,
/* 423 */ 516,
/* 424 */ -382,
/* 425 */ 87,
/* 426 */ 0,
/* 427 */ 50298,
/* 428 */ -382,
/* 429 */ 88,
/* 430 */ 438,
/* 431 */ 450,
/* 432 */ 50298,
/* 433 */ 50123,
/* 434 */ 458,
/* 435 */ 50125,
/* 436 */ -430,
/* 437 */ 89,
/* 438 */ 445,
/* 439 */ 450,
/* 440 */ 50123,
/* 441 */ 458,
/* 442 */ 50125,
/* 443 */ -430,
/* 444 */ 90,
/* 445 */ 0,
/* 446 */ 450,
/* 447 */ 50298,
/* 448 */ -430,
/* 449 */ 91,
/* 450 */ 454,
/* 451 */ 50280,
/* 452 */ -450,
/* 453 */ 92,
/* 454 */ 0,
/* 455 */ 50283,
/* 456 */ -450,
/* 457 */ 93,
/* 458 */ 462,
/* 459 */ 467,
/* 460 */ -458,
/* 461 */ 94,
/* 462 */ 0,
/* 463 */ 458,
/* 464 */ 467,
/* 465 */ -458,
/* 466 */ 95,
/* 467 */ 0,
/* 468 */ 473,
/* 469 */ 491,
/* 470 */ 50059,
/* 471 */ -467,
/* 472 */ 96,
/* 473 */ 478,
/* 474 */ 382,
/* 475 */ 473,
/* 476 */ -473,
/* 477 */ 97,
/* 478 */ 482,
/* 479 */ 382,
/* 480 */ -473,
/* 481 */ 98,
/* 482 */ 487,
/* 483 */ 556,
/* 484 */ 473,
/* 485 */ -473,
/* 486 */ 99,
/* 487 */ 0,
/* 488 */ 556,
/* 489 */ -473,
/* 490 */ 100,
/* 491 */ 495,
/* 492 */ 501,
/* 493 */ -491,
/* 494 */ 101,
/* 495 */ 0,
/* 496 */ 491,
/* 497 */ 50044,
/* 498 */ 501,
/* 499 */ -491,
/* 500 */ 102,
/* 501 */ 505,
/* 502 */ 564,
/* 503 */ -501,
/* 504 */ 103,
/* 505 */ 510,
/* 506 */ 50058,
/* 507 */ 300,
/* 508 */ -501,
/* 509 */ 104,
/* 510 */ 0,
/* 511 */ 564,
/* 512 */ 50058,
/* 513 */ 300,
/* 514 */ -501,
/* 515 */ 105,
/* 516 */ 523,
/* 517 */ 50266,
/* 518 */ 50123,
/* 519 */ 536,
/* 520 */ 50125,
/* 521 */ -516,
/* 522 */ 106,
/* 523 */ 531,
/* 524 */ 50266,
/* 525 */ 50298,
/* 526 */ 50123,
/* 527 */ 536,
/* 528 */ 50125,
/* 529 */ -516,
/* 530 */ 107,
/* 531 */ 0,
/* 532 */ 50266,
/* 533 */ 50298,
/* 534 */ -516,
/* 535 */ 108,
/* 536 */ 540,
/* 537 */ 546,
/* 538 */ -536,
/* 539 */ 109,
/* 540 */ 0,
/* 541 */ 536,
/* 542 */ 50044,
/* 543 */ 546,
/* 544 */ -536,
/* 545 */ 110,
/* 546 */ 550,
/* 547 */ 50298,
/* 548 */ -546,
/* 549 */ 111,
/* 550 */ 0,
/* 551 */ 50298,
/* 552 */ 50061,
/* 553 */ 300,
/* 554 */ -546,
/* 555 */ 112,
/* 556 */ 560,
/* 557 */ 50260,
/* 558 */ -556,
/* 559 */ 113,
/* 560 */ 0,
/* 561 */ 50286,
/* 562 */ -556,
/* 563 */ 114,
/* 564 */ 569,
/* 565 */ 616,
/* 566 */ 573,
/* 567 */ -564,
/* 568 */ 115,
/* 569 */ 0,
/* 570 */ 573,
/* 571 */ -564,
/* 572 */ 116,
/* 573 */ 577,
/* 574 */ 50298,
/* 575 */ -573,
/* 576 */ 117,
/* 577 */ 583,
/* 578 */ 50040,
/* 579 */ 564,
/* 580 */ 50041,
/* 581 */ -573,
/* 582 */ 118,
/* 583 */ 590,
/* 584 */ 573,
/* 585 */ 50091,
/* 586 */ 300,
/* 587 */ 50093,
/* 588 */ -573,
/* 589 */ 119,
/* 590 */ 596,
/* 591 */ 573,
/* 592 */ 50091,
/* 593 */ 50093,
/* 594 */ -573,
/* 595 */ 120,
/* 596 */ 603,
/* 597 */ 573,
/* 598 */ 50040,
/* 599 */ 645,
/* 600 */ 50041,
/* 601 */ -573,
/* 602 */ 121,
/* 603 */ 610,
/* 604 */ 573,
/* 605 */ 50040,
/* 606 */ 679,
/* 607 */ 50041,
/* 608 */ -573,
/* 609 */ 122,
/* 610 */ 0,
/* 611 */ 573,
/* 612 */ 50040,
/* 613 */ 50041,
/* 614 */ -573,
/* 615 */ 123,
/* 616 */ 620,
/* 617 */ 50042,
/* 618 */ -616,
/* 619 */ 124,
/* 620 */ 625,
/* 621 */ 50042,
/* 622 */ 636,
/* 623 */ -616,
/* 624 */ 125,
/* 625 */ 630,
/* 626 */ 50042,
/* 627 */ 616,
/* 628 */ -616,
/* 629 */ 126,
/* 630 */ 0,
/* 631 */ 50042,
/* 632 */ 636,
/* 633 */ 616,
/* 634 */ -616,
/* 635 */ 127,
/* 636 */ 640,
/* 637 */ 556,
/* 638 */ -636,
/* 639 */ 128,
/* 640 */ 0,
/* 641 */ 636,
/* 642 */ 556,
/* 643 */ -636,
/* 644 */ 129,
/* 645 */ 649,
/* 646 */ 655,
/* 647 */ -645,
/* 648 */ 130,
/* 649 */ 0,
/* 650 */ 655,
/* 651 */ 50044,
/* 652 */ 50290,
/* 653 */ -645,
/* 654 */ 131,
/* 655 */ 659,
/* 656 */ 665,
/* 657 */ -655,
/* 658 */ 132,
/* 659 */ 0,
/* 660 */ 655,
/* 661 */ 50044,
/* 662 */ 665,
/* 663 */ -655,
/* 664 */ 133,
/* 665 */ 670,
/* 666 */ 315,
/* 667 */ 564,
/* 668 */ -665,
/* 669 */ 134,
/* 670 */ 675,
/* 671 */ 315,
/* 672 */ 698,
/* 673 */ -665,
/* 674 */ 135,
/* 675 */ 0,
/* 676 */ 315,
/* 677 */ -665,
/* 678 */ 136,
/* 679 */ 683,
/* 680 */ 50298,
/* 681 */ -679,
/* 682 */ 137,
/* 683 */ 0,
/* 684 */ 679,
/* 685 */ 50044,
/* 686 */ 50298,
/* 687 */ -679,
/* 688 */ 138,
/* 689 */ 693,
/* 690 */ 473,
/* 691 */ -689,
/* 692 */ 139,
/* 693 */ 0,
/* 694 */ 473,
/* 695 */ 698,
/* 696 */ -689,
/* 697 */ 140,
/* 698 */ 702,
/* 699 */ 616,
/* 700 */ -698,
/* 701 */ 141,
/* 702 */ 706,
/* 703 */ 711,
/* 704 */ -698,
/* 705 */ 142,
/* 706 */ 0,
/* 707 */ 616,
/* 708 */ 711,
/* 709 */ -698,
/* 710 */ 143,
/* 711 */ 717,
/* 712 */ 50040,
/* 713 */ 698,
/* 714 */ 50041,
/* 715 */ -711,
/* 716 */ 144,
/* 717 */ 722,
/* 718 */ 50091,
/* 719 */ 50093,
/* 720 */ -711,
/* 721 */ 145,
/* 722 */ 728,
/* 723 */ 50091,
/* 724 */ 300,
/* 725 */ 50093,
/* 726 */ -711,
/* 727 */ 146,
/* 728 */ 734,
/* 729 */ 711,
/* 730 */ 50091,
/* 731 */ 50093,
/* 732 */ -711,
/* 733 */ 147,
/* 734 */ 741,
/* 735 */ 711,
/* 736 */ 50091,
/* 737 */ 300,
/* 738 */ 50093,
/* 739 */ -711,
/* 740 */ 148,
/* 741 */ 746,
/* 742 */ 50040,
/* 743 */ 50041,
/* 744 */ -711,
/* 745 */ 149,
/* 746 */ 752,
/* 747 */ 50040,
/* 748 */ 645,
/* 749 */ 50041,
/* 750 */ -711,
/* 751 */ 150,
/* 752 */ 758,
/* 753 */ 711,
/* 754 */ 50040,
/* 755 */ 50041,
/* 756 */ -711,
/* 757 */ 151,
/* 758 */ 0,
/* 759 */ 711,
/* 760 */ 50040,
/* 761 */ 645,
/* 762 */ 50041,
/* 763 */ -711,
/* 764 */ 152,
/* 765 */ 769,
/* 766 */ 276,
/* 767 */ -765,
/* 768 */ 153,
/* 769 */ 775,
/* 770 */ 50123,
/* 771 */ 782,
/* 772 */ 50125,
/* 773 */ -765,
/* 774 */ 154,
/* 775 */ 0,
/* 776 */ 50123,
/* 777 */ 782,
/* 778 */ 50044,
/* 779 */ 50125,
/* 780 */ -765,
/* 781 */ 155,
/* 782 */ 786,
/* 783 */ 765,
/* 784 */ -782,
/* 785 */ 156,
/* 786 */ 0,
/* 787 */ 782,
/* 788 */ 50044,
/* 789 */ 765,
/* 790 */ -782,
/* 791 */ 157,
/* 792 */ 796,
/* 793 */ 816,
/* 794 */ -792,
/* 795 */ 158,
/* 796 */ 800,
/* 797 */ 835,
/* 798 */ -792,
/* 799 */ 159,
/* 800 */ 804,
/* 801 */ 877,
/* 802 */ -792,
/* 803 */ 160,
/* 804 */ 808,
/* 805 */ 886,
/* 806 */ -792,
/* 807 */ 161,
/* 808 */ 812,
/* 809 */ 912,
/* 810 */ -792,
/* 811 */ 162,
/* 812 */ 0,
/* 813 */ 949,
/* 814 */ -792,
/* 815 */ 163,
/* 816 */ 822,
/* 817 */ 50298,
/* 818 */ 50058,
/* 819 */ 792,
/* 820 */ -816,
/* 821 */ 164,
/* 822 */ 829,
/* 823 */ 50258,
/* 824 */ 300,
/* 825 */ 50058,
/* 826 */ 792,
/* 827 */ -816,
/* 828 */ 165,
/* 829 */ 0,
/* 830 */ 50262,
/* 831 */ 50058,
/* 832 */ 792,
/* 833 */ -816,
/* 834 */ 166,
/* 835 */ 840,
/* 836 */ 50123,
/* 837 */ 50125,
/* 838 */ -835,
/* 839 */ 167,
/* 840 */ 846,
/* 841 */ 50123,
/* 842 */ 868,
/* 843 */ 50125,
/* 844 */ -835,
/* 845 */ 168,
/* 846 */ 852,
/* 847 */ 50123,
/* 848 */ 859,
/* 849 */ 50125,
/* 850 */ -835,
/* 851 */ 169,
/* 852 */ 0,
/* 853 */ 50123,
/* 854 */ 859,
/* 855 */ 868,
/* 856 */ 50125,
/* 857 */ -835,
/* 858 */ 170,
/* 859 */ 863,
/* 860 */ 304,
/* 861 */ -859,
/* 862 */ 171,
/* 863 */ 0,
/* 864 */ 859,
/* 865 */ 304,
/* 866 */ -859,
/* 867 */ 172,
/* 868 */ 872,
/* 869 */ 792,
/* 870 */ -868,
/* 871 */ 173,
/* 872 */ 0,
/* 873 */ 868,
/* 874 */ 792,
/* 875 */ -868,
/* 876 */ 174,
/* 877 */ 881,
/* 878 */ 50059,
/* 879 */ -877,
/* 880 */ 175,
/* 881 */ 0,
/* 882 */ 290,
/* 883 */ 50059,
/* 884 */ -877,
/* 885 */ 176,
/* 886 */ 894,
/* 887 */ 50271,
/* 888 */ 50040,
/* 889 */ 290,
/* 890 */ 50041,
/* 891 */ 792,
/* 892 */ -886,
/* 893 */ 177,
/* 894 */ 904,
/* 895 */ 50271,
/* 896 */ 50040,
/* 897 */ 290,
/* 898 */ 50041,
/* 899 */ 792,
/* 900 */ 50265,
/* 901 */ 792,
/* 902 */ -886,
/* 903 */ 178,
/* 904 */ 0,
/* 905 */ 50281,
/* 906 */ 50040,
/* 907 */ 290,
/* 908 */ 50041,
/* 909 */ 792,
/* 910 */ -886,
/* 911 */ 179,
/* 912 */ 920,
/* 913 */ 50287,
/* 914 */ 50040,
/* 915 */ 290,
/* 916 */ 50041,
/* 917 */ 792,
/* 918 */ -912,
/* 919 */ 180,
/* 920 */ 930,
/* 921 */ 50263,
/* 922 */ 792,
/* 923 */ 50287,
/* 924 */ 50040,
/* 925 */ 290,
/* 926 */ 50041,
/* 927 */ 50059,
/* 928 */ -912,
/* 929 */ 181,
/* 930 */ 939,
/* 931 */ 50269,
/* 932 */ 50040,
/* 933 */ 877,
/* 934 */ 877,
/* 935 */ 50041,
/* 936 */ 792,
/* 937 */ -912,
/* 938 */ 182,
/* 939 */ 0,
/* 940 */ 50269,
/* 941 */ 50040,
/* 942 */ 877,
/* 943 */ 877,
/* 944 */ 290,
/* 945 */ 50041,
/* 946 */ 792,
/* 947 */ -912,
/* 948 */ 183,
/* 949 */ 955,
/* 950 */ 50270,
/* 951 */ 50298,
/* 952 */ 50059,
/* 953 */ -949,
/* 954 */ 184,
/* 955 */ 960,
/* 956 */ 50261,
/* 957 */ 50059,
/* 958 */ -949,
/* 959 */ 185,
/* 960 */ 965,
/* 961 */ 50257,
/* 962 */ 50059,
/* 963 */ -949,
/* 964 */ 186,
/* 965 */ 970,
/* 966 */ 50275,
/* 967 */ 50059,
/* 968 */ -949,
/* 969 */ 187,
/* 970 */ 0,
/* 971 */ 50275,
/* 972 */ 290,
/* 973 */ 50059,
/* 974 */ -949,
/* 975 */ 188,
/* 976 */ 980,
/* 977 */ 985,
/* 978 */ -976,
/* 979 */ 189,
/* 980 */ 0,
/* 981 */ 976,
/* 982 */ 985,
/* 983 */ -976,
/* 984 */ 190,
/* 985 */ 989,
/* 986 */ 993,
/* 987 */ -985,
/* 988 */ 191,
/* 989 */ 0,
/* 990 */ 304,
/* 991 */ -985,
/* 992 */ 192,
/* 993 */ 1000,
/* 994 */ 315,
/* 995 */ 564,
/* 996 */ 859,
/* 997 */ 835,
/* 998 */ -993,
/* 999 */ 193,
/* 1000 */ 1006,
/* 1001 */ 315,
/* 1002 */ 564,
/* 1003 */ 835,
/* 1004 */ -993,
/* 1005 */ 194,
/* 1006 */ 1012,
/* 1007 */ 564,
/* 1008 */ 859,
/* 1009 */ 835,
/* 1010 */ -993,
/* 1011 */ 195,
/* 1012 */ 0,
/* 1013 */ 564,
/* 1014 */ 835,
/* 1015 */ -993,
/* 1016 */ 196,
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
/* 7 */ 50298,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 14,
/* 11 */ 50288,
/* 12 */ -6,
/* 13 */ 2,
/* 14 */ 18,
/* 15 */ 50289,
/* 16 */ -6,
/* 17 */ 3,
/* 18 */ 0,
/* 19 */ 50040,
/* 20 */ 1,
/* 21 */ 50041,
/* 22 */ -6,
/* 23 */ 4,
/* 24 */ 28,
/* 25 */ 1,
/* 26 */ -24,
/* 27 */ 1,
/* 28 */ 35,
/* 29 */ 1,
/* 30 */ 50091,
/* 31 */ 1,
/* 32 */ 50093,
/* 33 */ -24,
/* 34 */ 2,
/* 35 */ 41,
/* 36 */ 1,
/* 37 */ 50040,
/* 38 */ 50041,
/* 39 */ -24,
/* 40 */ 3,
/* 41 */ 48,
/* 42 */ 1,
/* 43 */ 50040,
/* 44 */ 1,
/* 45 */ 50041,
/* 46 */ -24,
/* 47 */ 4,
/* 48 */ 54,
/* 49 */ 1,
/* 50 */ 50046,
/* 51 */ 50298,
/* 52 */ -24,
/* 53 */ 5,
/* 54 */ 60,
/* 55 */ 1,
/* 56 */ 50296,
/* 57 */ 50298,
/* 58 */ -24,
/* 59 */ 6,
/* 60 */ 65,
/* 61 */ 1,
/* 62 */ 50294,
/* 63 */ -24,
/* 64 */ 7,
/* 65 */ 0,
/* 66 */ 1,
/* 67 */ 50295,
/* 68 */ -24,
/* 69 */ 8,
/* 70 */ 74,
/* 71 */ 1,
/* 72 */ -70,
/* 73 */ 1,
/* 74 */ 0,
/* 75 */ 1,
/* 76 */ 50044,
/* 77 */ 1,
/* 78 */ -70,
/* 79 */ 2,
/* 80 */ 84,
/* 81 */ 1,
/* 82 */ -80,
/* 83 */ 1,
/* 84 */ 89,
/* 85 */ 50294,
/* 86 */ 1,
/* 87 */ -80,
/* 88 */ 2,
/* 89 */ 94,
/* 90 */ 50295,
/* 91 */ 1,
/* 92 */ -80,
/* 93 */ 3,
/* 94 */ 99,
/* 95 */ 1,
/* 96 */ 1,
/* 97 */ -80,
/* 98 */ 4,
/* 99 */ 104,
/* 100 */ 50278,
/* 101 */ 1,
/* 102 */ -80,
/* 103 */ 5,
/* 104 */ 0,
/* 105 */ 50278,
/* 106 */ 50040,
/* 107 */ 1,
/* 108 */ 50041,
/* 109 */ -80,
/* 110 */ 6,
/* 111 */ 115,
/* 112 */ 50038,
/* 113 */ -111,
/* 114 */ 1,
/* 115 */ 119,
/* 116 */ 50042,
/* 117 */ -111,
/* 118 */ 2,
/* 119 */ 123,
/* 120 */ 50043,
/* 121 */ -111,
/* 122 */ 3,
/* 123 */ 127,
/* 124 */ 50045,
/* 125 */ -111,
/* 126 */ 4,
/* 127 */ 131,
/* 128 */ 50126,
/* 129 */ -111,
/* 130 */ 5,
/* 131 */ 0,
/* 132 */ 50033,
/* 133 */ -111,
/* 134 */ 6,
/* 135 */ 139,
/* 136 */ 1,
/* 137 */ -135,
/* 138 */ 1,
/* 139 */ 0,
/* 140 */ 50040,
/* 141 */ 1,
/* 142 */ 50041,
/* 143 */ 1,
/* 144 */ -135,
/* 145 */ 2,
/* 146 */ 150,
/* 147 */ 1,
/* 148 */ -146,
/* 149 */ 1,
/* 150 */ 156,
/* 151 */ 1,
/* 152 */ 50042,
/* 153 */ 1,
/* 154 */ -146,
/* 155 */ 2,
/* 156 */ 162,
/* 157 */ 1,
/* 158 */ 50047,
/* 159 */ 1,
/* 160 */ -146,
/* 161 */ 3,
/* 162 */ 0,
/* 163 */ 1,
/* 164 */ 50037,
/* 165 */ 1,
/* 166 */ -146,
/* 167 */ 4,
/* 168 */ 172,
/* 169 */ 1,
/* 170 */ -168,
/* 171 */ 1,
/* 172 */ 178,
/* 173 */ 1,
/* 174 */ 50043,
/* 175 */ 1,
/* 176 */ -168,
/* 177 */ 2,
/* 178 */ 0,
/* 179 */ 1,
/* 180 */ 50045,
/* 181 */ 1,
/* 182 */ -168,
/* 183 */ 3,
/* 184 */ 188,
/* 185 */ 1,
/* 186 */ -184,
/* 187 */ 1,
/* 188 */ 0,
/* 189 */ 1,
/* 190 */ 50293,
/* 191 */ 1,
/* 192 */ -184,
/* 193 */ 2,
/* 194 */ 198,
/* 195 */ 1,
/* 196 */ -194,
/* 197 */ 1,
/* 198 */ 0,
/* 199 */ 1,
/* 200 */ 50292,
/* 201 */ 1,
/* 202 */ -194,
/* 203 */ 2,
/* 204 */ 208,
/* 205 */ 1,
/* 206 */ -204,
/* 207 */ 1,
/* 208 */ 0,
/* 209 */ 1,
/* 210 */ 50292,
/* 211 */ 1,
/* 212 */ -204,
/* 213 */ 2,
/* 214 */ 218,
/* 215 */ 1,
/* 216 */ -214,
/* 217 */ 1,
/* 218 */ 0,
/* 219 */ 1,
/* 220 */ 50038,
/* 221 */ 1,
/* 222 */ -214,
/* 223 */ 2,
/* 224 */ 228,
/* 225 */ 1,
/* 226 */ -224,
/* 227 */ 1,
/* 228 */ 0,
/* 229 */ 1,
/* 230 */ 50094,
/* 231 */ 1,
/* 232 */ -224,
/* 233 */ 2,
/* 234 */ 238,
/* 235 */ 1,
/* 236 */ -234,
/* 237 */ 1,
/* 238 */ 0,
/* 239 */ 1,
/* 240 */ 50124,
/* 241 */ 1,
/* 242 */ -234,
/* 243 */ 2,
/* 244 */ 248,
/* 245 */ 1,
/* 246 */ -244,
/* 247 */ 1,
/* 248 */ 0,
/* 249 */ 1,
/* 250 */ 50297,
/* 251 */ 1,
/* 252 */ -244,
/* 253 */ 2,
/* 254 */ 258,
/* 255 */ 1,
/* 256 */ -254,
/* 257 */ 1,
/* 258 */ 0,
/* 259 */ 1,
/* 260 */ 50297,
/* 261 */ 1,
/* 262 */ -254,
/* 263 */ 2,
/* 264 */ 268,
/* 265 */ 1,
/* 266 */ -264,
/* 267 */ 1,
/* 268 */ 0,
/* 269 */ 1,
/* 270 */ 50063,
/* 271 */ 1,
/* 272 */ 50058,
/* 273 */ 1,
/* 274 */ -264,
/* 275 */ 2,
/* 276 */ 280,
/* 277 */ 1,
/* 278 */ -276,
/* 279 */ 1,
/* 280 */ 0,
/* 281 */ 1,
/* 282 */ 1,
/* 283 */ 1,
/* 284 */ -276,
/* 285 */ 2,
/* 286 */ 0,
/* 287 */ 50291,
/* 288 */ -286,
/* 289 */ 1,
/* 290 */ 294,
/* 291 */ 1,
/* 292 */ -290,
/* 293 */ 1,
/* 294 */ 0,
/* 295 */ 1,
/* 296 */ 50044,
/* 297 */ 1,
/* 298 */ -290,
/* 299 */ 2,
/* 300 */ 0,
/* 301 */ 1,
/* 302 */ -300,
/* 303 */ 1,
/* 304 */ 309,
/* 305 */ 1,
/* 306 */ 50059,
/* 307 */ -304,
/* 308 */ 1,
/* 309 */ 0,
/* 310 */ 1,
/* 311 */ 1,
/* 312 */ 50059,
/* 313 */ -304,
/* 314 */ 2,
/* 315 */ 319,
/* 316 */ 1,
/* 317 */ -315,
/* 318 */ 1,
/* 319 */ 324,
/* 320 */ 1,
/* 321 */ 1,
/* 322 */ -315,
/* 323 */ 2,
/* 324 */ 328,
/* 325 */ 1,
/* 326 */ -315,
/* 327 */ 3,
/* 328 */ 333,
/* 329 */ 1,
/* 330 */ 1,
/* 331 */ -315,
/* 332 */ 4,
/* 333 */ 337,
/* 334 */ 1,
/* 335 */ -315,
/* 336 */ 5,
/* 337 */ 0,
/* 338 */ 1,
/* 339 */ 1,
/* 340 */ -315,
/* 341 */ 6,
/* 342 */ 346,
/* 343 */ 1,
/* 344 */ -342,
/* 345 */ 1,
/* 346 */ 0,
/* 347 */ 1,
/* 348 */ 50044,
/* 349 */ 1,
/* 350 */ -342,
/* 351 */ 2,
/* 352 */ 356,
/* 353 */ 1,
/* 354 */ -352,
/* 355 */ 1,
/* 356 */ 0,
/* 357 */ 1,
/* 358 */ 50061,
/* 359 */ 1,
/* 360 */ -352,
/* 361 */ 2,
/* 362 */ 366,
/* 363 */ 50282,
/* 364 */ -362,
/* 365 */ 1,
/* 366 */ 370,
/* 367 */ 50267,
/* 368 */ -362,
/* 369 */ 2,
/* 370 */ 374,
/* 371 */ 50279,
/* 372 */ -362,
/* 373 */ 3,
/* 374 */ 378,
/* 375 */ 50256,
/* 376 */ -362,
/* 377 */ 4,
/* 378 */ 0,
/* 379 */ 50274,
/* 380 */ -362,
/* 381 */ 5,
/* 382 */ 386,
/* 383 */ 50285,
/* 384 */ -382,
/* 385 */ 1,
/* 386 */ 390,
/* 387 */ 50259,
/* 388 */ -382,
/* 389 */ 2,
/* 390 */ 394,
/* 391 */ 50276,
/* 392 */ -382,
/* 393 */ 3,
/* 394 */ 398,
/* 395 */ 50272,
/* 396 */ -382,
/* 397 */ 4,
/* 398 */ 402,
/* 399 */ 50273,
/* 400 */ -382,
/* 401 */ 5,
/* 402 */ 406,
/* 403 */ 50268,
/* 404 */ -382,
/* 405 */ 6,
/* 406 */ 410,
/* 407 */ 50264,
/* 408 */ -382,
/* 409 */ 7,
/* 410 */ 414,
/* 411 */ 50277,
/* 412 */ -382,
/* 413 */ 8,
/* 414 */ 418,
/* 415 */ 50284,
/* 416 */ -382,
/* 417 */ 9,
/* 418 */ 422,
/* 419 */ 1,
/* 420 */ -382,
/* 421 */ 10,
/* 422 */ 426,
/* 423 */ 1,
/* 424 */ -382,
/* 425 */ 11,
/* 426 */ 0,
/* 427 */ 50298,
/* 428 */ -382,
/* 429 */ 12,
/* 430 */ 438,
/* 431 */ 1,
/* 432 */ 50298,
/* 433 */ 50123,
/* 434 */ 1,
/* 435 */ 50125,
/* 436 */ -430,
/* 437 */ 1,
/* 438 */ 445,
/* 439 */ 1,
/* 440 */ 50123,
/* 441 */ 1,
/* 442 */ 50125,
/* 443 */ -430,
/* 444 */ 2,
/* 445 */ 0,
/* 446 */ 1,
/* 447 */ 50298,
/* 448 */ -430,
/* 449 */ 3,
/* 450 */ 454,
/* 451 */ 50280,
/* 452 */ -450,
/* 453 */ 1,
/* 454 */ 0,
/* 455 */ 50283,
/* 456 */ -450,
/* 457 */ 2,
/* 458 */ 462,
/* 459 */ 1,
/* 460 */ -458,
/* 461 */ 1,
/* 462 */ 0,
/* 463 */ 1,
/* 464 */ 1,
/* 465 */ -458,
/* 466 */ 2,
/* 467 */ 0,
/* 468 */ 1,
/* 469 */ 1,
/* 470 */ 50059,
/* 471 */ -467,
/* 472 */ 1,
/* 473 */ 478,
/* 474 */ 1,
/* 475 */ 1,
/* 476 */ -473,
/* 477 */ 1,
/* 478 */ 482,
/* 479 */ 1,
/* 480 */ -473,
/* 481 */ 2,
/* 482 */ 487,
/* 483 */ 1,
/* 484 */ 1,
/* 485 */ -473,
/* 486 */ 3,
/* 487 */ 0,
/* 488 */ 1,
/* 489 */ -473,
/* 490 */ 4,
/* 491 */ 495,
/* 492 */ 1,
/* 493 */ -491,
/* 494 */ 1,
/* 495 */ 0,
/* 496 */ 1,
/* 497 */ 50044,
/* 498 */ 1,
/* 499 */ -491,
/* 500 */ 2,
/* 501 */ 505,
/* 502 */ 1,
/* 503 */ -501,
/* 504 */ 1,
/* 505 */ 510,
/* 506 */ 50058,
/* 507 */ 1,
/* 508 */ -501,
/* 509 */ 2,
/* 510 */ 0,
/* 511 */ 1,
/* 512 */ 50058,
/* 513 */ 1,
/* 514 */ -501,
/* 515 */ 3,
/* 516 */ 523,
/* 517 */ 50266,
/* 518 */ 50123,
/* 519 */ 1,
/* 520 */ 50125,
/* 521 */ -516,
/* 522 */ 1,
/* 523 */ 531,
/* 524 */ 50266,
/* 525 */ 50298,
/* 526 */ 50123,
/* 527 */ 1,
/* 528 */ 50125,
/* 529 */ -516,
/* 530 */ 2,
/* 531 */ 0,
/* 532 */ 50266,
/* 533 */ 50298,
/* 534 */ -516,
/* 535 */ 3,
/* 536 */ 540,
/* 537 */ 1,
/* 538 */ -536,
/* 539 */ 1,
/* 540 */ 0,
/* 541 */ 1,
/* 542 */ 50044,
/* 543 */ 1,
/* 544 */ -536,
/* 545 */ 2,
/* 546 */ 550,
/* 547 */ 50298,
/* 548 */ -546,
/* 549 */ 1,
/* 550 */ 0,
/* 551 */ 50298,
/* 552 */ 50061,
/* 553 */ 1,
/* 554 */ -546,
/* 555 */ 2,
/* 556 */ 560,
/* 557 */ 50260,
/* 558 */ -556,
/* 559 */ 1,
/* 560 */ 0,
/* 561 */ 50286,
/* 562 */ -556,
/* 563 */ 2,
/* 564 */ 569,
/* 565 */ 1,
/* 566 */ 1,
/* 567 */ -564,
/* 568 */ 1,
/* 569 */ 0,
/* 570 */ 1,
/* 571 */ -564,
/* 572 */ 2,
/* 573 */ 577,
/* 574 */ 50298,
/* 575 */ -573,
/* 576 */ 1,
/* 577 */ 583,
/* 578 */ 50040,
/* 579 */ 1,
/* 580 */ 50041,
/* 581 */ -573,
/* 582 */ 2,
/* 583 */ 590,
/* 584 */ 1,
/* 585 */ 50091,
/* 586 */ 1,
/* 587 */ 50093,
/* 588 */ -573,
/* 589 */ 3,
/* 590 */ 596,
/* 591 */ 1,
/* 592 */ 50091,
/* 593 */ 50093,
/* 594 */ -573,
/* 595 */ 4,
/* 596 */ 603,
/* 597 */ 1,
/* 598 */ 50040,
/* 599 */ 1,
/* 600 */ 50041,
/* 601 */ -573,
/* 602 */ 5,
/* 603 */ 610,
/* 604 */ 1,
/* 605 */ 50040,
/* 606 */ 1,
/* 607 */ 50041,
/* 608 */ -573,
/* 609 */ 6,
/* 610 */ 0,
/* 611 */ 1,
/* 612 */ 50040,
/* 613 */ 50041,
/* 614 */ -573,
/* 615 */ 7,
/* 616 */ 620,
/* 617 */ 50042,
/* 618 */ -616,
/* 619 */ 1,
/* 620 */ 625,
/* 621 */ 50042,
/* 622 */ 1,
/* 623 */ -616,
/* 624 */ 2,
/* 625 */ 630,
/* 626 */ 50042,
/* 627 */ 1,
/* 628 */ -616,
/* 629 */ 3,
/* 630 */ 0,
/* 631 */ 50042,
/* 632 */ 1,
/* 633 */ 1,
/* 634 */ -616,
/* 635 */ 4,
/* 636 */ 640,
/* 637 */ 1,
/* 638 */ -636,
/* 639 */ 1,
/* 640 */ 0,
/* 641 */ 1,
/* 642 */ 1,
/* 643 */ -636,
/* 644 */ 2,
/* 645 */ 649,
/* 646 */ 1,
/* 647 */ -645,
/* 648 */ 1,
/* 649 */ 0,
/* 650 */ 1,
/* 651 */ 50044,
/* 652 */ 50290,
/* 653 */ -645,
/* 654 */ 2,
/* 655 */ 659,
/* 656 */ 1,
/* 657 */ -655,
/* 658 */ 1,
/* 659 */ 0,
/* 660 */ 1,
/* 661 */ 50044,
/* 662 */ 1,
/* 663 */ -655,
/* 664 */ 2,
/* 665 */ 670,
/* 666 */ 1,
/* 667 */ 1,
/* 668 */ -665,
/* 669 */ 1,
/* 670 */ 675,
/* 671 */ 1,
/* 672 */ 1,
/* 673 */ -665,
/* 674 */ 2,
/* 675 */ 0,
/* 676 */ 1,
/* 677 */ -665,
/* 678 */ 3,
/* 679 */ 683,
/* 680 */ 50298,
/* 681 */ -679,
/* 682 */ 1,
/* 683 */ 0,
/* 684 */ 1,
/* 685 */ 50044,
/* 686 */ 50298,
/* 687 */ -679,
/* 688 */ 2,
/* 689 */ 693,
/* 690 */ 1,
/* 691 */ -689,
/* 692 */ 1,
/* 693 */ 0,
/* 694 */ 1,
/* 695 */ 1,
/* 696 */ -689,
/* 697 */ 2,
/* 698 */ 702,
/* 699 */ 1,
/* 700 */ -698,
/* 701 */ 1,
/* 702 */ 706,
/* 703 */ 1,
/* 704 */ -698,
/* 705 */ 2,
/* 706 */ 0,
/* 707 */ 1,
/* 708 */ 1,
/* 709 */ -698,
/* 710 */ 3,
/* 711 */ 717,
/* 712 */ 50040,
/* 713 */ 1,
/* 714 */ 50041,
/* 715 */ -711,
/* 716 */ 1,
/* 717 */ 722,
/* 718 */ 50091,
/* 719 */ 50093,
/* 720 */ -711,
/* 721 */ 2,
/* 722 */ 728,
/* 723 */ 50091,
/* 724 */ 1,
/* 725 */ 50093,
/* 726 */ -711,
/* 727 */ 3,
/* 728 */ 734,
/* 729 */ 1,
/* 730 */ 50091,
/* 731 */ 50093,
/* 732 */ -711,
/* 733 */ 4,
/* 734 */ 741,
/* 735 */ 1,
/* 736 */ 50091,
/* 737 */ 1,
/* 738 */ 50093,
/* 739 */ -711,
/* 740 */ 5,
/* 741 */ 746,
/* 742 */ 50040,
/* 743 */ 50041,
/* 744 */ -711,
/* 745 */ 6,
/* 746 */ 752,
/* 747 */ 50040,
/* 748 */ 1,
/* 749 */ 50041,
/* 750 */ -711,
/* 751 */ 7,
/* 752 */ 758,
/* 753 */ 1,
/* 754 */ 50040,
/* 755 */ 50041,
/* 756 */ -711,
/* 757 */ 8,
/* 758 */ 0,
/* 759 */ 1,
/* 760 */ 50040,
/* 761 */ 1,
/* 762 */ 50041,
/* 763 */ -711,
/* 764 */ 9,
/* 765 */ 769,
/* 766 */ 1,
/* 767 */ -765,
/* 768 */ 1,
/* 769 */ 775,
/* 770 */ 50123,
/* 771 */ 1,
/* 772 */ 50125,
/* 773 */ -765,
/* 774 */ 2,
/* 775 */ 0,
/* 776 */ 50123,
/* 777 */ 1,
/* 778 */ 50044,
/* 779 */ 50125,
/* 780 */ -765,
/* 781 */ 3,
/* 782 */ 786,
/* 783 */ 1,
/* 784 */ -782,
/* 785 */ 1,
/* 786 */ 0,
/* 787 */ 1,
/* 788 */ 50044,
/* 789 */ 1,
/* 790 */ -782,
/* 791 */ 2,
/* 792 */ 796,
/* 793 */ 1,
/* 794 */ -792,
/* 795 */ 1,
/* 796 */ 800,
/* 797 */ 1,
/* 798 */ -792,
/* 799 */ 2,
/* 800 */ 804,
/* 801 */ 1,
/* 802 */ -792,
/* 803 */ 3,
/* 804 */ 808,
/* 805 */ 1,
/* 806 */ -792,
/* 807 */ 4,
/* 808 */ 812,
/* 809 */ 1,
/* 810 */ -792,
/* 811 */ 5,
/* 812 */ 0,
/* 813 */ 1,
/* 814 */ -792,
/* 815 */ 6,
/* 816 */ 822,
/* 817 */ 50298,
/* 818 */ 50058,
/* 819 */ 1,
/* 820 */ -816,
/* 821 */ 1,
/* 822 */ 829,
/* 823 */ 50258,
/* 824 */ 1,
/* 825 */ 50058,
/* 826 */ 1,
/* 827 */ -816,
/* 828 */ 2,
/* 829 */ 0,
/* 830 */ 50262,
/* 831 */ 50058,
/* 832 */ 1,
/* 833 */ -816,
/* 834 */ 3,
/* 835 */ 840,
/* 836 */ 50123,
/* 837 */ 50125,
/* 838 */ -835,
/* 839 */ 1,
/* 840 */ 846,
/* 841 */ 50123,
/* 842 */ 1,
/* 843 */ 50125,
/* 844 */ -835,
/* 845 */ 2,
/* 846 */ 852,
/* 847 */ 50123,
/* 848 */ 1,
/* 849 */ 50125,
/* 850 */ -835,
/* 851 */ 3,
/* 852 */ 0,
/* 853 */ 50123,
/* 854 */ 1,
/* 855 */ 1,
/* 856 */ 50125,
/* 857 */ -835,
/* 858 */ 4,
/* 859 */ 863,
/* 860 */ 1,
/* 861 */ -859,
/* 862 */ 1,
/* 863 */ 0,
/* 864 */ 1,
/* 865 */ 1,
/* 866 */ -859,
/* 867 */ 2,
/* 868 */ 872,
/* 869 */ 1,
/* 870 */ -868,
/* 871 */ 1,
/* 872 */ 0,
/* 873 */ 1,
/* 874 */ 1,
/* 875 */ -868,
/* 876 */ 2,
/* 877 */ 881,
/* 878 */ 50059,
/* 879 */ -877,
/* 880 */ 1,
/* 881 */ 0,
/* 882 */ 1,
/* 883 */ 50059,
/* 884 */ -877,
/* 885 */ 2,
/* 886 */ 894,
/* 887 */ 50271,
/* 888 */ 50040,
/* 889 */ 1,
/* 890 */ 50041,
/* 891 */ 1,
/* 892 */ -886,
/* 893 */ 1,
/* 894 */ 904,
/* 895 */ 50271,
/* 896 */ 50040,
/* 897 */ 1,
/* 898 */ 50041,
/* 899 */ 1,
/* 900 */ 50265,
/* 901 */ 1,
/* 902 */ -886,
/* 903 */ 2,
/* 904 */ 0,
/* 905 */ 50281,
/* 906 */ 50040,
/* 907 */ 1,
/* 908 */ 50041,
/* 909 */ 1,
/* 910 */ -886,
/* 911 */ 3,
/* 912 */ 920,
/* 913 */ 50287,
/* 914 */ 50040,
/* 915 */ 1,
/* 916 */ 50041,
/* 917 */ 1,
/* 918 */ -912,
/* 919 */ 1,
/* 920 */ 930,
/* 921 */ 50263,
/* 922 */ 1,
/* 923 */ 50287,
/* 924 */ 50040,
/* 925 */ 1,
/* 926 */ 50041,
/* 927 */ 50059,
/* 928 */ -912,
/* 929 */ 2,
/* 930 */ 939,
/* 931 */ 50269,
/* 932 */ 50040,
/* 933 */ 1,
/* 934 */ 1,
/* 935 */ 50041,
/* 936 */ 1,
/* 937 */ -912,
/* 938 */ 3,
/* 939 */ 0,
/* 940 */ 50269,
/* 941 */ 50040,
/* 942 */ 1,
/* 943 */ 1,
/* 944 */ 1,
/* 945 */ 50041,
/* 946 */ 1,
/* 947 */ -912,
/* 948 */ 4,
/* 949 */ 955,
/* 950 */ 50270,
/* 951 */ 50298,
/* 952 */ 50059,
/* 953 */ -949,
/* 954 */ 1,
/* 955 */ 960,
/* 956 */ 50261,
/* 957 */ 50059,
/* 958 */ -949,
/* 959 */ 2,
/* 960 */ 965,
/* 961 */ 50257,
/* 962 */ 50059,
/* 963 */ -949,
/* 964 */ 3,
/* 965 */ 970,
/* 966 */ 50275,
/* 967 */ 50059,
/* 968 */ -949,
/* 969 */ 4,
/* 970 */ 0,
/* 971 */ 50275,
/* 972 */ 1,
/* 973 */ 50059,
/* 974 */ -949,
/* 975 */ 5,
/* 976 */ 980,
/* 977 */ 1,
/* 978 */ -976,
/* 979 */ 1,
/* 980 */ 0,
/* 981 */ 1,
/* 982 */ 1,
/* 983 */ -976,
/* 984 */ 2,
/* 985 */ 989,
/* 986 */ 1,
/* 987 */ -985,
/* 988 */ 1,
/* 989 */ 0,
/* 990 */ 1,
/* 991 */ -985,
/* 992 */ 2,
/* 993 */ 1000,
/* 994 */ 1,
/* 995 */ 1,
/* 996 */ 1,
/* 997 */ 1,
/* 998 */ -993,
/* 999 */ 1,
/* 1000 */ 1006,
/* 1001 */ 1,
/* 1002 */ 1,
/* 1003 */ 1,
/* 1004 */ -993,
/* 1005 */ 2,
/* 1006 */ 1012,
/* 1007 */ 1,
/* 1008 */ 1,
/* 1009 */ 1,
/* 1010 */ -993,
/* 1011 */ 3,
/* 1012 */ 0,
/* 1013 */ 1,
/* 1014 */ 1,
/* 1015 */ -993,
/* 1016 */ 4,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 37002,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 37002,
/* 6 */ 9999,
/* 7 */ 9999,
/* 8 */ 9999,
/* 9 */ 37013,
/* 10 */ 9999,
/* 11 */ 9999,
/* 12 */ 9999,
/* 13 */ 38011,
/* 14 */ 9999,
/* 15 */ 9999,
/* 16 */ 9999,
/* 17 */ 39017,
/* 18 */ 9999,
/* 19 */ 9999,
/* 20 */ 40008,
/* 21 */ 9999,
/* 22 */ 9999,
/* 23 */ 40004,
/* 24 */ 9999,
/* 25 */ 44004,
/* 26 */ 9999,
/* 27 */ 44021,
/* 28 */ 9999,
/* 29 */ 45004,
/* 30 */ 9999,
/* 31 */ 45027,
/* 32 */ 9999,
/* 33 */ 9999,
/* 34 */ 45021,
/* 35 */ 9999,
/* 36 */ 46004,
/* 37 */ 9999,
/* 38 */ 9999,
/* 39 */ 9999,
/* 40 */ 46021,
/* 41 */ 9999,
/* 42 */ 47004,
/* 43 */ 9999,
/* 44 */ 47027,
/* 45 */ 9999,
/* 46 */ 9999,
/* 47 */ 47021,
/* 48 */ 9999,
/* 49 */ 48004,
/* 50 */ 9999,
/* 51 */ 9999,
/* 52 */ 9999,
/* 53 */ 48021,
/* 54 */ 9999,
/* 55 */ 49004,
/* 56 */ 9999,
/* 57 */ 9999,
/* 58 */ 9999,
/* 59 */ 49021,
/* 60 */ 9999,
/* 61 */ 50004,
/* 62 */ 9999,
/* 63 */ 9999,
/* 64 */ 50021,
/* 65 */ 9999,
/* 66 */ 51004,
/* 67 */ 9999,
/* 68 */ 9999,
/* 69 */ 51021,
/* 70 */ 9999,
/* 71 */ 55004,
/* 72 */ 9999,
/* 73 */ 55024,
/* 74 */ 9999,
/* 75 */ 56004,
/* 76 */ 9999,
/* 77 */ 56033,
/* 78 */ 9999,
/* 79 */ 56027,
/* 80 */ 9999,
/* 81 */ 60004,
/* 82 */ 9999,
/* 83 */ 60021,
/* 84 */ 9999,
/* 85 */ 9999,
/* 86 */ 61011,
/* 87 */ 9999,
/* 88 */ 61009,
/* 89 */ 9999,
/* 90 */ 9999,
/* 91 */ 62011,
/* 92 */ 9999,
/* 93 */ 62009,
/* 94 */ 9999,
/* 95 */ 63004,
/* 96 */ 63019,
/* 97 */ 9999,
/* 98 */ 63017,
/* 99 */ 9999,
/* 100 */ 9999,
/* 101 */ 64011,
/* 102 */ 9999,
/* 103 */ 64009,
/* 104 */ 9999,
/* 105 */ 9999,
/* 106 */ 9999,
/* 107 */ 65015,
/* 108 */ 9999,
/* 109 */ 9999,
/* 110 */ 65009,
/* 111 */ 9999,
/* 112 */ 9999,
/* 113 */ 9999,
/* 114 */ 69004,
/* 115 */ 9999,
/* 116 */ 9999,
/* 117 */ 9999,
/* 118 */ 70004,
/* 119 */ 9999,
/* 120 */ 9999,
/* 121 */ 9999,
/* 122 */ 71004,
/* 123 */ 9999,
/* 124 */ 9999,
/* 125 */ 9999,
/* 126 */ 72004,
/* 127 */ 9999,
/* 128 */ 9999,
/* 129 */ 9999,
/* 130 */ 73004,
/* 131 */ 9999,
/* 132 */ 9999,
/* 133 */ 9999,
/* 134 */ 74004,
/* 135 */ 9999,
/* 136 */ 78004,
/* 137 */ 9999,
/* 138 */ 78019,
/* 139 */ 9999,
/* 140 */ 9999,
/* 141 */ 79008,
/* 142 */ 9999,
/* 143 */ 79022,
/* 144 */ 9999,
/* 145 */ 79004,
/* 146 */ 9999,
/* 147 */ 83004,
/* 148 */ 9999,
/* 149 */ 83018,
/* 150 */ 9999,
/* 151 */ 84004,
/* 152 */ 9999,
/* 153 */ 84034,
/* 154 */ 9999,
/* 155 */ 84028,
/* 156 */ 9999,
/* 157 */ 85004,
/* 158 */ 9999,
/* 159 */ 85034,
/* 160 */ 9999,
/* 161 */ 85028,
/* 162 */ 9999,
/* 163 */ 86004,
/* 164 */ 9999,
/* 165 */ 86034,
/* 166 */ 9999,
/* 167 */ 86028,
/* 168 */ 9999,
/* 169 */ 90004,
/* 170 */ 9999,
/* 171 */ 90028,
/* 172 */ 9999,
/* 173 */ 91004,
/* 174 */ 9999,
/* 175 */ 91028,
/* 176 */ 9999,
/* 177 */ 91022,
/* 178 */ 9999,
/* 179 */ 92004,
/* 180 */ 9999,
/* 181 */ 92028,
/* 182 */ 9999,
/* 183 */ 92022,
/* 184 */ 9999,
/* 185 */ 96004,
/* 186 */ 9999,
/* 187 */ 96022,
/* 188 */ 9999,
/* 189 */ 97004,
/* 190 */ 9999,
/* 191 */ 97029,
/* 192 */ 9999,
/* 193 */ 97019,
/* 194 */ 9999,
/* 195 */ 101004,
/* 196 */ 9999,
/* 197 */ 101019,
/* 198 */ 9999,
/* 199 */ 102004,
/* 200 */ 9999,
/* 201 */ 102034,
/* 202 */ 9999,
/* 203 */ 102024,
/* 204 */ 9999,
/* 205 */ 106004,
/* 206 */ 9999,
/* 207 */ 106024,
/* 208 */ 9999,
/* 209 */ 107004,
/* 210 */ 9999,
/* 211 */ 107032,
/* 212 */ 9999,
/* 213 */ 107022,
/* 214 */ 9999,
/* 215 */ 111004,
/* 216 */ 9999,
/* 217 */ 111022,
/* 218 */ 9999,
/* 219 */ 112004,
/* 220 */ 9999,
/* 221 */ 112023,
/* 222 */ 9999,
/* 223 */ 112017,
/* 224 */ 9999,
/* 225 */ 116004,
/* 226 */ 9999,
/* 227 */ 116017,
/* 228 */ 9999,
/* 229 */ 117004,
/* 230 */ 9999,
/* 231 */ 117032,
/* 232 */ 9999,
/* 233 */ 117026,
/* 234 */ 9999,
/* 235 */ 121004,
/* 236 */ 9999,
/* 237 */ 121026,
/* 238 */ 9999,
/* 239 */ 122004,
/* 240 */ 9999,
/* 241 */ 122032,
/* 242 */ 9999,
/* 243 */ 122026,
/* 244 */ 9999,
/* 245 */ 126004,
/* 246 */ 9999,
/* 247 */ 126026,
/* 248 */ 9999,
/* 249 */ 127004,
/* 250 */ 9999,
/* 251 */ 127036,
/* 252 */ 9999,
/* 253 */ 127025,
/* 254 */ 9999,
/* 255 */ 131004,
/* 256 */ 9999,
/* 257 */ 131025,
/* 258 */ 9999,
/* 259 */ 132004,
/* 260 */ 9999,
/* 261 */ 132035,
/* 262 */ 9999,
/* 263 */ 132024,
/* 264 */ 9999,
/* 265 */ 136004,
/* 266 */ 9999,
/* 267 */ 136024,
/* 268 */ 9999,
/* 269 */ 137004,
/* 270 */ 9999,
/* 271 */ 137030,
/* 272 */ 9999,
/* 273 */ 137045,
/* 274 */ 9999,
/* 275 */ 137024,
/* 276 */ 9999,
/* 277 */ 141004,
/* 278 */ 9999,
/* 279 */ 141025,
/* 280 */ 9999,
/* 281 */ 142004,
/* 282 */ 142021,
/* 283 */ 142041,
/* 284 */ 9999,
/* 285 */ 142019,
/* 286 */ 9999,
/* 287 */ 9999,
/* 288 */ 9999,
/* 289 */ 146009,
/* 290 */ 9999,
/* 291 */ 150004,
/* 292 */ 9999,
/* 293 */ 150024,
/* 294 */ 9999,
/* 295 */ 151004,
/* 296 */ 9999,
/* 297 */ 151019,
/* 298 */ 9999,
/* 299 */ 151013,
/* 300 */ 9999,
/* 301 */ 155004,
/* 302 */ 9999,
/* 303 */ 155025,
/* 304 */ 9999,
/* 305 */ 159004,
/* 306 */ 9999,
/* 307 */ 9999,
/* 308 */ 159025,
/* 309 */ 9999,
/* 310 */ 160004,
/* 311 */ 160027,
/* 312 */ 9999,
/* 313 */ 9999,
/* 314 */ 160025,
/* 315 */ 9999,
/* 316 */ 164004,
/* 317 */ 9999,
/* 318 */ 164026,
/* 319 */ 9999,
/* 320 */ 165004,
/* 321 */ 165028,
/* 322 */ 9999,
/* 323 */ 165026,
/* 324 */ 9999,
/* 325 */ 166004,
/* 326 */ 9999,
/* 327 */ 166017,
/* 328 */ 9999,
/* 329 */ 167004,
/* 330 */ 167019,
/* 331 */ 9999,
/* 332 */ 167017,
/* 333 */ 9999,
/* 334 */ 168004,
/* 335 */ 9999,
/* 336 */ 168017,
/* 337 */ 9999,
/* 338 */ 169004,
/* 339 */ 169019,
/* 340 */ 9999,
/* 341 */ 169017,
/* 342 */ 9999,
/* 343 */ 173004,
/* 344 */ 9999,
/* 345 */ 173018,
/* 346 */ 9999,
/* 347 */ 174004,
/* 348 */ 9999,
/* 349 */ 174029,
/* 350 */ 9999,
/* 351 */ 174023,
/* 352 */ 9999,
/* 353 */ 178004,
/* 354 */ 9999,
/* 355 */ 178013,
/* 356 */ 9999,
/* 357 */ 179004,
/* 358 */ 9999,
/* 359 */ 179019,
/* 360 */ 9999,
/* 361 */ 179013,
/* 362 */ 9999,
/* 363 */ 9999,
/* 364 */ 9999,
/* 365 */ 183010,
/* 366 */ 9999,
/* 367 */ 9999,
/* 368 */ 9999,
/* 369 */ 184009,
/* 370 */ 9999,
/* 371 */ 9999,
/* 372 */ 9999,
/* 373 */ 185009,
/* 374 */ 9999,
/* 375 */ 9999,
/* 376 */ 9999,
/* 377 */ 186007,
/* 378 */ 9999,
/* 379 */ 9999,
/* 380 */ 9999,
/* 381 */ 187011,
/* 382 */ 9999,
/* 383 */ 9999,
/* 384 */ 9999,
/* 385 */ 191007,
/* 386 */ 9999,
/* 387 */ 9999,
/* 388 */ 9999,
/* 389 */ 192007,
/* 390 */ 9999,
/* 391 */ 9999,
/* 392 */ 9999,
/* 393 */ 193008,
/* 394 */ 9999,
/* 395 */ 9999,
/* 396 */ 9999,
/* 397 */ 194006,
/* 398 */ 9999,
/* 399 */ 9999,
/* 400 */ 9999,
/* 401 */ 195007,
/* 402 */ 9999,
/* 403 */ 9999,
/* 404 */ 9999,
/* 405 */ 196008,
/* 406 */ 9999,
/* 407 */ 9999,
/* 408 */ 9999,
/* 409 */ 197009,
/* 410 */ 9999,
/* 411 */ 9999,
/* 412 */ 9999,
/* 413 */ 198009,
/* 414 */ 9999,
/* 415 */ 9999,
/* 416 */ 9999,
/* 417 */ 199011,
/* 418 */ 9999,
/* 419 */ 200004,
/* 420 */ 9999,
/* 421 */ 200028,
/* 422 */ 9999,
/* 423 */ 201004,
/* 424 */ 9999,
/* 425 */ 201017,
/* 426 */ 9999,
/* 427 */ 9999,
/* 428 */ 9999,
/* 429 */ 202013,
/* 430 */ 9999,
/* 431 */ 206004,
/* 432 */ 9999,
/* 433 */ 9999,
/* 434 */ 206035,
/* 435 */ 9999,
/* 436 */ 9999,
/* 437 */ 206018,
/* 438 */ 9999,
/* 439 */ 207004,
/* 440 */ 9999,
/* 441 */ 207024,
/* 442 */ 9999,
/* 443 */ 9999,
/* 444 */ 207018,
/* 445 */ 9999,
/* 446 */ 208004,
/* 447 */ 9999,
/* 448 */ 9999,
/* 449 */ 208018,
/* 450 */ 9999,
/* 451 */ 9999,
/* 452 */ 9999,
/* 453 */ 212009,
/* 454 */ 9999,
/* 455 */ 9999,
/* 456 */ 9999,
/* 457 */ 213008,
/* 458 */ 9999,
/* 459 */ 217004,
/* 460 */ 9999,
/* 461 */ 217021,
/* 462 */ 9999,
/* 463 */ 218004,
/* 464 */ 218028,
/* 465 */ 9999,
/* 466 */ 218026,
/* 467 */ 9999,
/* 468 */ 222004,
/* 469 */ 222029,
/* 470 */ 9999,
/* 471 */ 9999,
/* 472 */ 222027,
/* 473 */ 9999,
/* 474 */ 226004,
/* 475 */ 226019,
/* 476 */ 9999,
/* 477 */ 226017,
/* 478 */ 9999,
/* 479 */ 227004,
/* 480 */ 9999,
/* 481 */ 227017,
/* 482 */ 9999,
/* 483 */ 228004,
/* 484 */ 228019,
/* 485 */ 9999,
/* 486 */ 228017,
/* 487 */ 9999,
/* 488 */ 229004,
/* 489 */ 9999,
/* 490 */ 229017,
/* 491 */ 9999,
/* 492 */ 233004,
/* 493 */ 9999,
/* 494 */ 233020,
/* 495 */ 9999,
/* 496 */ 234004,
/* 497 */ 9999,
/* 498 */ 234031,
/* 499 */ 9999,
/* 500 */ 234025,
/* 501 */ 9999,
/* 502 */ 238004,
/* 503 */ 9999,
/* 504 */ 238013,
/* 505 */ 9999,
/* 506 */ 9999,
/* 507 */ 239008,
/* 508 */ 9999,
/* 509 */ 239004,
/* 510 */ 9999,
/* 511 */ 240004,
/* 512 */ 9999,
/* 513 */ 240019,
/* 514 */ 9999,
/* 515 */ 240013,
/* 516 */ 9999,
/* 517 */ 9999,
/* 518 */ 9999,
/* 519 */ 244013,
/* 520 */ 9999,
/* 521 */ 9999,
/* 522 */ 244007,
/* 523 */ 9999,
/* 524 */ 9999,
/* 525 */ 9999,
/* 526 */ 9999,
/* 527 */ 245024,
/* 528 */ 9999,
/* 529 */ 9999,
/* 530 */ 245007,
/* 531 */ 9999,
/* 532 */ 9999,
/* 533 */ 9999,
/* 534 */ 9999,
/* 535 */ 246007,
/* 536 */ 9999,
/* 537 */ 250004,
/* 538 */ 9999,
/* 539 */ 250013,
/* 540 */ 9999,
/* 541 */ 251004,
/* 542 */ 9999,
/* 543 */ 251024,
/* 544 */ 9999,
/* 545 */ 251018,
/* 546 */ 9999,
/* 547 */ 9999,
/* 548 */ 9999,
/* 549 */ 255013,
/* 550 */ 9999,
/* 551 */ 9999,
/* 552 */ 9999,
/* 553 */ 256019,
/* 554 */ 9999,
/* 555 */ 256013,
/* 556 */ 9999,
/* 557 */ 9999,
/* 558 */ 9999,
/* 559 */ 260008,
/* 560 */ 9999,
/* 561 */ 9999,
/* 562 */ 9999,
/* 563 */ 261011,
/* 564 */ 9999,
/* 565 */ 265004,
/* 566 */ 265012,
/* 567 */ 9999,
/* 568 */ 265010,
/* 569 */ 9999,
/* 570 */ 266004,
/* 571 */ 9999,
/* 572 */ 266020,
/* 573 */ 9999,
/* 574 */ 9999,
/* 575 */ 9999,
/* 576 */ 270013,
/* 577 */ 9999,
/* 578 */ 9999,
/* 579 */ 271008,
/* 580 */ 9999,
/* 581 */ 9999,
/* 582 */ 271004,
/* 583 */ 9999,
/* 584 */ 272004,
/* 585 */ 9999,
/* 586 */ 272026,
/* 587 */ 9999,
/* 588 */ 9999,
/* 589 */ 272020,
/* 590 */ 9999,
/* 591 */ 273004,
/* 592 */ 9999,
/* 593 */ 9999,
/* 594 */ 9999,
/* 595 */ 273020,
/* 596 */ 9999,
/* 597 */ 274004,
/* 598 */ 9999,
/* 599 */ 274026,
/* 600 */ 9999,
/* 601 */ 9999,
/* 602 */ 274020,
/* 603 */ 9999,
/* 604 */ 275004,
/* 605 */ 9999,
/* 606 */ 275026,
/* 607 */ 9999,
/* 608 */ 9999,
/* 609 */ 275020,
/* 610 */ 9999,
/* 611 */ 276004,
/* 612 */ 9999,
/* 613 */ 9999,
/* 614 */ 9999,
/* 615 */ 276020,
/* 616 */ 9999,
/* 617 */ 9999,
/* 618 */ 9999,
/* 619 */ 280004,
/* 620 */ 9999,
/* 621 */ 9999,
/* 622 */ 281008,
/* 623 */ 9999,
/* 624 */ 281004,
/* 625 */ 9999,
/* 626 */ 9999,
/* 627 */ 282008,
/* 628 */ 9999,
/* 629 */ 282004,
/* 630 */ 9999,
/* 631 */ 9999,
/* 632 */ 283008,
/* 633 */ 283028,
/* 634 */ 9999,
/* 635 */ 283004,
/* 636 */ 9999,
/* 637 */ 287004,
/* 638 */ 9999,
/* 639 */ 287017,
/* 640 */ 9999,
/* 641 */ 288004,
/* 642 */ 288024,
/* 643 */ 9999,
/* 644 */ 288022,
/* 645 */ 9999,
/* 646 */ 293004,
/* 647 */ 9999,
/* 648 */ 293017,
/* 649 */ 9999,
/* 650 */ 294004,
/* 651 */ 9999,
/* 652 */ 9999,
/* 653 */ 9999,
/* 654 */ 294017,
/* 655 */ 9999,
/* 656 */ 298004,
/* 657 */ 9999,
/* 658 */ 298024,
/* 659 */ 9999,
/* 660 */ 299004,
/* 661 */ 9999,
/* 662 */ 299023,
/* 663 */ 9999,
/* 664 */ 299017,
/* 665 */ 9999,
/* 666 */ 303004,
/* 667 */ 303027,
/* 668 */ 9999,
/* 669 */ 303025,
/* 670 */ 9999,
/* 671 */ 304004,
/* 672 */ 304027,
/* 673 */ 9999,
/* 674 */ 304025,
/* 675 */ 9999,
/* 676 */ 305004,
/* 677 */ 9999,
/* 678 */ 305025,
/* 679 */ 9999,
/* 680 */ 9999,
/* 681 */ 9999,
/* 682 */ 309013,
/* 683 */ 9999,
/* 684 */ 310004,
/* 685 */ 9999,
/* 686 */ 9999,
/* 687 */ 9999,
/* 688 */ 310018,
/* 689 */ 9999,
/* 690 */ 314004,
/* 691 */ 9999,
/* 692 */ 314027,
/* 693 */ 9999,
/* 694 */ 315004,
/* 695 */ 315029,
/* 696 */ 9999,
/* 697 */ 315027,
/* 698 */ 9999,
/* 699 */ 319004,
/* 700 */ 9999,
/* 701 */ 319010,
/* 702 */ 9999,
/* 703 */ 320004,
/* 704 */ 9999,
/* 705 */ 320029,
/* 706 */ 9999,
/* 707 */ 321004,
/* 708 */ 321012,
/* 709 */ 9999,
/* 710 */ 321010,
/* 711 */ 9999,
/* 712 */ 9999,
/* 713 */ 325008,
/* 714 */ 9999,
/* 715 */ 9999,
/* 716 */ 325004,
/* 717 */ 9999,
/* 718 */ 9999,
/* 719 */ 9999,
/* 720 */ 9999,
/* 721 */ 326004,
/* 722 */ 9999,
/* 723 */ 9999,
/* 724 */ 327008,
/* 725 */ 9999,
/* 726 */ 9999,
/* 727 */ 327004,
/* 728 */ 9999,
/* 729 */ 328004,
/* 730 */ 9999,
/* 731 */ 9999,
/* 732 */ 9999,
/* 733 */ 328029,
/* 734 */ 9999,
/* 735 */ 329004,
/* 736 */ 9999,
/* 737 */ 329035,
/* 738 */ 9999,
/* 739 */ 9999,
/* 740 */ 329029,
/* 741 */ 9999,
/* 742 */ 9999,
/* 743 */ 9999,
/* 744 */ 9999,
/* 745 */ 330004,
/* 746 */ 9999,
/* 747 */ 9999,
/* 748 */ 331008,
/* 749 */ 9999,
/* 750 */ 9999,
/* 751 */ 331004,
/* 752 */ 9999,
/* 753 */ 332004,
/* 754 */ 9999,
/* 755 */ 9999,
/* 756 */ 9999,
/* 757 */ 332029,
/* 758 */ 9999,
/* 759 */ 333004,
/* 760 */ 9999,
/* 761 */ 333035,
/* 762 */ 9999,
/* 763 */ 9999,
/* 764 */ 333029,
/* 765 */ 9999,
/* 766 */ 337004,
/* 767 */ 9999,
/* 768 */ 337024,
/* 769 */ 9999,
/* 770 */ 9999,
/* 771 */ 338008,
/* 772 */ 9999,
/* 773 */ 9999,
/* 774 */ 338004,
/* 775 */ 9999,
/* 776 */ 9999,
/* 777 */ 339008,
/* 778 */ 9999,
/* 779 */ 9999,
/* 780 */ 9999,
/* 781 */ 339004,
/* 782 */ 9999,
/* 783 */ 343004,
/* 784 */ 9999,
/* 785 */ 343014,
/* 786 */ 9999,
/* 787 */ 344004,
/* 788 */ 9999,
/* 789 */ 344025,
/* 790 */ 9999,
/* 791 */ 344019,
/* 792 */ 9999,
/* 793 */ 348004,
/* 794 */ 9999,
/* 795 */ 348020,
/* 796 */ 9999,
/* 797 */ 349004,
/* 798 */ 9999,
/* 799 */ 349021,
/* 800 */ 9999,
/* 801 */ 350004,
/* 802 */ 9999,
/* 803 */ 350023,
/* 804 */ 9999,
/* 805 */ 351004,
/* 806 */ 9999,
/* 807 */ 351022,
/* 808 */ 9999,
/* 809 */ 352004,
/* 810 */ 9999,
/* 811 */ 352022,
/* 812 */ 9999,
/* 813 */ 353004,
/* 814 */ 9999,
/* 815 */ 353017,
/* 816 */ 9999,
/* 817 */ 9999,
/* 818 */ 9999,
/* 819 */ 357019,
/* 820 */ 9999,
/* 821 */ 357013,
/* 822 */ 9999,
/* 823 */ 9999,
/* 824 */ 358009,
/* 825 */ 9999,
/* 826 */ 358033,
/* 827 */ 9999,
/* 828 */ 358007,
/* 829 */ 9999,
/* 830 */ 9999,
/* 831 */ 9999,
/* 832 */ 359016,
/* 833 */ 9999,
/* 834 */ 359010,
/* 835 */ 9999,
/* 836 */ 9999,
/* 837 */ 9999,
/* 838 */ 9999,
/* 839 */ 363004,
/* 840 */ 9999,
/* 841 */ 9999,
/* 842 */ 364008,
/* 843 */ 9999,
/* 844 */ 9999,
/* 845 */ 364004,
/* 846 */ 9999,
/* 847 */ 9999,
/* 848 */ 365008,
/* 849 */ 9999,
/* 850 */ 9999,
/* 851 */ 365004,
/* 852 */ 9999,
/* 853 */ 9999,
/* 854 */ 366008,
/* 855 */ 366025,
/* 856 */ 9999,
/* 857 */ 9999,
/* 858 */ 366004,
/* 859 */ 9999,
/* 860 */ 370004,
/* 861 */ 9999,
/* 862 */ 370014,
/* 863 */ 9999,
/* 864 */ 371004,
/* 865 */ 371021,
/* 866 */ 9999,
/* 867 */ 371019,
/* 868 */ 9999,
/* 869 */ 375004,
/* 870 */ 9999,
/* 871 */ 375012,
/* 872 */ 9999,
/* 873 */ 376004,
/* 874 */ 376019,
/* 875 */ 9999,
/* 876 */ 376017,
/* 877 */ 9999,
/* 878 */ 9999,
/* 879 */ 9999,
/* 880 */ 380004,
/* 881 */ 9999,
/* 882 */ 381004,
/* 883 */ 9999,
/* 884 */ 9999,
/* 885 */ 381013,
/* 886 */ 9999,
/* 887 */ 9999,
/* 888 */ 9999,
/* 889 */ 385011,
/* 890 */ 9999,
/* 891 */ 385026,
/* 892 */ 9999,
/* 893 */ 385005,
/* 894 */ 9999,
/* 895 */ 9999,
/* 896 */ 9999,
/* 897 */ 386011,
/* 898 */ 9999,
/* 899 */ 386026,
/* 900 */ 9999,
/* 901 */ 386041,
/* 902 */ 9999,
/* 903 */ 386005,
/* 904 */ 9999,
/* 905 */ 9999,
/* 906 */ 9999,
/* 907 */ 387015,
/* 908 */ 9999,
/* 909 */ 387030,
/* 910 */ 9999,
/* 911 */ 387009,
/* 912 */ 9999,
/* 913 */ 9999,
/* 914 */ 9999,
/* 915 */ 391014,
/* 916 */ 9999,
/* 917 */ 391029,
/* 918 */ 9999,
/* 919 */ 391008,
/* 920 */ 9999,
/* 921 */ 9999,
/* 922 */ 392007,
/* 923 */ 9999,
/* 924 */ 9999,
/* 925 */ 392027,
/* 926 */ 9999,
/* 927 */ 9999,
/* 928 */ 9999,
/* 929 */ 392005,
/* 930 */ 9999,
/* 931 */ 9999,
/* 932 */ 9999,
/* 933 */ 393012,
/* 934 */ 393033,
/* 935 */ 9999,
/* 936 */ 393058,
/* 937 */ 9999,
/* 938 */ 393006,
/* 939 */ 9999,
/* 940 */ 9999,
/* 941 */ 9999,
/* 942 */ 394012,
/* 943 */ 394033,
/* 944 */ 394054,
/* 945 */ 9999,
/* 946 */ 394069,
/* 947 */ 9999,
/* 948 */ 394006,
/* 949 */ 9999,
/* 950 */ 9999,
/* 951 */ 9999,
/* 952 */ 9999,
/* 953 */ 9999,
/* 954 */ 398007,
/* 955 */ 9999,
/* 956 */ 9999,
/* 957 */ 9999,
/* 958 */ 9999,
/* 959 */ 399011,
/* 960 */ 9999,
/* 961 */ 9999,
/* 962 */ 9999,
/* 963 */ 9999,
/* 964 */ 400008,
/* 965 */ 9999,
/* 966 */ 9999,
/* 967 */ 9999,
/* 968 */ 9999,
/* 969 */ 401009,
/* 970 */ 9999,
/* 971 */ 9999,
/* 972 */ 402011,
/* 973 */ 9999,
/* 974 */ 9999,
/* 975 */ 402009,
/* 976 */ 9999,
/* 977 */ 405004,
/* 978 */ 9999,
/* 979 */ 405023,
/* 980 */ 9999,
/* 981 */ 406004,
/* 982 */ 406009,
/* 983 */ 9999,
/* 984 */ 406007,
/* 985 */ 9999,
/* 986 */ 410004,
/* 987 */ 9999,
/* 988 */ 410022,
/* 989 */ 9999,
/* 990 */ 411004,
/* 991 */ 9999,
/* 992 */ 411014,
/* 993 */ 9999,
/* 994 */ 415004,
/* 995 */ 415027,
/* 996 */ 415038,
/* 997 */ 415055,
/* 998 */ 9999,
/* 999 */ 415025,
/* 1000 */ 9999,
/* 1001 */ 416004,
/* 1002 */ 416027,
/* 1003 */ 416038,
/* 1004 */ 9999,
/* 1005 */ 416025,
/* 1006 */ 9999,
/* 1007 */ 417004,
/* 1008 */ 417015,
/* 1009 */ 417032,
/* 1010 */ 9999,
/* 1011 */ 417013,
/* 1012 */ 9999,
/* 1013 */ 418004,
/* 1014 */ 418015,
/* 1015 */ 9999,
/* 1016 */ 418013,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[1018];
*/
int TABLE[198][305];
init_dirsets() {
TABLE[197][298] = 1;
TABLE[197][288] = 1;
TABLE[197][289] = 1;
TABLE[197][40] = 1;
TABLE[1][298] = 1;
TABLE[2][288] = 1;
TABLE[3][289] = 1;
TABLE[4][40] = 1;
TABLE[5][298] = 1;
TABLE[5][288] = 1;
TABLE[5][289] = 1;
TABLE[5][40] = 1;
TABLE[6][40] = 1;
TABLE[6][289] = 1;
TABLE[6][288] = 1;
TABLE[6][298] = 1;
TABLE[7][40] = 1;
TABLE[7][289] = 1;
TABLE[7][288] = 1;
TABLE[7][298] = 1;
TABLE[8][40] = 1;
TABLE[8][289] = 1;
TABLE[8][288] = 1;
TABLE[8][298] = 1;
TABLE[9][40] = 1;
TABLE[9][289] = 1;
TABLE[9][288] = 1;
TABLE[9][298] = 1;
TABLE[10][40] = 1;
TABLE[10][289] = 1;
TABLE[10][288] = 1;
TABLE[10][298] = 1;
TABLE[11][40] = 1;
TABLE[11][289] = 1;
TABLE[11][288] = 1;
TABLE[11][298] = 1;
TABLE[12][40] = 1;
TABLE[12][289] = 1;
TABLE[12][288] = 1;
TABLE[12][298] = 1;
TABLE[13][278] = 1;
TABLE[13][295] = 1;
TABLE[13][294] = 1;
TABLE[13][40] = 1;
TABLE[13][289] = 1;
TABLE[13][288] = 1;
TABLE[13][298] = 1;
TABLE[13][38] = 1;
TABLE[13][42] = 1;
TABLE[13][43] = 1;
TABLE[13][45] = 1;
TABLE[13][126] = 1;
TABLE[13][33] = 1;
TABLE[14][298] = 1;
TABLE[14][288] = 1;
TABLE[14][289] = 1;
TABLE[14][40] = 1;
TABLE[14][294] = 1;
TABLE[14][295] = 1;
TABLE[14][278] = 1;
TABLE[14][33] = 1;
TABLE[14][126] = 1;
TABLE[14][45] = 1;
TABLE[14][43] = 1;
TABLE[14][42] = 1;
TABLE[14][38] = 1;
TABLE[15][40] = 1;
TABLE[15][289] = 1;
TABLE[15][288] = 1;
TABLE[15][298] = 1;
TABLE[16][294] = 1;
TABLE[17][295] = 1;
TABLE[18][38] = 1;
TABLE[18][42] = 1;
TABLE[18][43] = 1;
TABLE[18][45] = 1;
TABLE[18][126] = 1;
TABLE[18][33] = 1;
TABLE[19][278] = 1;
TABLE[20][278] = 1;
TABLE[21][38] = 1;
TABLE[22][42] = 1;
TABLE[23][43] = 1;
TABLE[24][45] = 1;
TABLE[25][126] = 1;
TABLE[26][33] = 1;
TABLE[27][298] = 1;
TABLE[27][288] = 1;
TABLE[27][289] = 1;
TABLE[27][40] = 1;
TABLE[27][294] = 1;
TABLE[27][295] = 1;
TABLE[27][278] = 1;
TABLE[27][33] = 1;
TABLE[27][126] = 1;
TABLE[27][45] = 1;
TABLE[27][43] = 1;
TABLE[27][42] = 1;
TABLE[27][38] = 1;
TABLE[28][40] = 1;
TABLE[29][278] = 1;
TABLE[29][295] = 1;
TABLE[29][294] = 1;
TABLE[29][40] = 1;
TABLE[29][289] = 1;
TABLE[29][288] = 1;
TABLE[29][298] = 1;
TABLE[29][38] = 1;
TABLE[29][42] = 1;
TABLE[29][43] = 1;
TABLE[29][45] = 1;
TABLE[29][126] = 1;
TABLE[29][33] = 1;
TABLE[30][298] = 1;
TABLE[30][288] = 1;
TABLE[30][289] = 1;
TABLE[30][40] = 1;
TABLE[30][294] = 1;
TABLE[30][295] = 1;
TABLE[30][278] = 1;
TABLE[30][33] = 1;
TABLE[30][126] = 1;
TABLE[30][45] = 1;
TABLE[30][43] = 1;
TABLE[30][42] = 1;
TABLE[30][38] = 1;
TABLE[31][298] = 1;
TABLE[31][288] = 1;
TABLE[31][289] = 1;
TABLE[31][40] = 1;
TABLE[31][294] = 1;
TABLE[31][295] = 1;
TABLE[31][278] = 1;
TABLE[31][33] = 1;
TABLE[31][126] = 1;
TABLE[31][45] = 1;
TABLE[31][43] = 1;
TABLE[31][42] = 1;
TABLE[31][38] = 1;
TABLE[32][298] = 1;
TABLE[32][288] = 1;
TABLE[32][289] = 1;
TABLE[32][40] = 1;
TABLE[32][294] = 1;
TABLE[32][295] = 1;
TABLE[32][278] = 1;
TABLE[32][33] = 1;
TABLE[32][126] = 1;
TABLE[32][45] = 1;
TABLE[32][43] = 1;
TABLE[32][42] = 1;
TABLE[32][38] = 1;
TABLE[33][298] = 1;
TABLE[33][288] = 1;
TABLE[33][289] = 1;
TABLE[33][40] = 1;
TABLE[33][294] = 1;
TABLE[33][295] = 1;
TABLE[33][278] = 1;
TABLE[33][33] = 1;
TABLE[33][126] = 1;
TABLE[33][45] = 1;
TABLE[33][43] = 1;
TABLE[33][42] = 1;
TABLE[33][38] = 1;
TABLE[34][278] = 1;
TABLE[34][295] = 1;
TABLE[34][294] = 1;
TABLE[34][40] = 1;
TABLE[34][289] = 1;
TABLE[34][288] = 1;
TABLE[34][298] = 1;
TABLE[34][38] = 1;
TABLE[34][42] = 1;
TABLE[34][43] = 1;
TABLE[34][45] = 1;
TABLE[34][126] = 1;
TABLE[34][33] = 1;
TABLE[35][278] = 1;
TABLE[35][295] = 1;
TABLE[35][294] = 1;
TABLE[35][40] = 1;
TABLE[35][289] = 1;
TABLE[35][288] = 1;
TABLE[35][298] = 1;
TABLE[35][38] = 1;
TABLE[35][42] = 1;
TABLE[35][43] = 1;
TABLE[35][45] = 1;
TABLE[35][126] = 1;
TABLE[35][33] = 1;
TABLE[36][278] = 1;
TABLE[36][295] = 1;
TABLE[36][294] = 1;
TABLE[36][40] = 1;
TABLE[36][289] = 1;
TABLE[36][288] = 1;
TABLE[36][298] = 1;
TABLE[36][38] = 1;
TABLE[36][42] = 1;
TABLE[36][43] = 1;
TABLE[36][45] = 1;
TABLE[36][126] = 1;
TABLE[36][33] = 1;
TABLE[37][298] = 1;
TABLE[37][288] = 1;
TABLE[37][289] = 1;
TABLE[37][40] = 1;
TABLE[37][294] = 1;
TABLE[37][295] = 1;
TABLE[37][278] = 1;
TABLE[37][33] = 1;
TABLE[37][126] = 1;
TABLE[37][45] = 1;
TABLE[37][43] = 1;
TABLE[37][42] = 1;
TABLE[37][38] = 1;
TABLE[38][298] = 1;
TABLE[38][288] = 1;
TABLE[38][289] = 1;
TABLE[38][40] = 1;
TABLE[38][294] = 1;
TABLE[38][295] = 1;
TABLE[38][278] = 1;
TABLE[38][33] = 1;
TABLE[38][126] = 1;
TABLE[38][45] = 1;
TABLE[38][43] = 1;
TABLE[38][42] = 1;
TABLE[38][38] = 1;
TABLE[39][278] = 1;
TABLE[39][295] = 1;
TABLE[39][294] = 1;
TABLE[39][40] = 1;
TABLE[39][289] = 1;
TABLE[39][288] = 1;
TABLE[39][298] = 1;
TABLE[39][38] = 1;
TABLE[39][42] = 1;
TABLE[39][43] = 1;
TABLE[39][45] = 1;
TABLE[39][126] = 1;
TABLE[39][33] = 1;
TABLE[40][278] = 1;
TABLE[40][295] = 1;
TABLE[40][294] = 1;
TABLE[40][40] = 1;
TABLE[40][289] = 1;
TABLE[40][288] = 1;
TABLE[40][298] = 1;
TABLE[40][38] = 1;
TABLE[40][42] = 1;
TABLE[40][43] = 1;
TABLE[40][45] = 1;
TABLE[40][126] = 1;
TABLE[40][33] = 1;
TABLE[41][298] = 1;
TABLE[41][288] = 1;
TABLE[41][289] = 1;
TABLE[41][40] = 1;
TABLE[41][294] = 1;
TABLE[41][295] = 1;
TABLE[41][278] = 1;
TABLE[41][33] = 1;
TABLE[41][126] = 1;
TABLE[41][45] = 1;
TABLE[41][43] = 1;
TABLE[41][42] = 1;
TABLE[41][38] = 1;
TABLE[42][298] = 1;
TABLE[42][288] = 1;
TABLE[42][289] = 1;
TABLE[42][40] = 1;
TABLE[42][294] = 1;
TABLE[42][295] = 1;
TABLE[42][278] = 1;
TABLE[42][33] = 1;
TABLE[42][126] = 1;
TABLE[42][45] = 1;
TABLE[42][43] = 1;
TABLE[42][42] = 1;
TABLE[42][38] = 1;
TABLE[43][278] = 1;
TABLE[43][295] = 1;
TABLE[43][294] = 1;
TABLE[43][40] = 1;
TABLE[43][289] = 1;
TABLE[43][288] = 1;
TABLE[43][298] = 1;
TABLE[43][38] = 1;
TABLE[43][42] = 1;
TABLE[43][43] = 1;
TABLE[43][45] = 1;
TABLE[43][126] = 1;
TABLE[43][33] = 1;
TABLE[44][278] = 1;
TABLE[44][295] = 1;
TABLE[44][294] = 1;
TABLE[44][40] = 1;
TABLE[44][289] = 1;
TABLE[44][288] = 1;
TABLE[44][298] = 1;
TABLE[44][38] = 1;
TABLE[44][42] = 1;
TABLE[44][43] = 1;
TABLE[44][45] = 1;
TABLE[44][126] = 1;
TABLE[44][33] = 1;
TABLE[45][298] = 1;
TABLE[45][288] = 1;
TABLE[45][289] = 1;
TABLE[45][40] = 1;
TABLE[45][294] = 1;
TABLE[45][295] = 1;
TABLE[45][278] = 1;
TABLE[45][33] = 1;
TABLE[45][126] = 1;
TABLE[45][45] = 1;
TABLE[45][43] = 1;
TABLE[45][42] = 1;
TABLE[45][38] = 1;
TABLE[46][298] = 1;
TABLE[46][288] = 1;
TABLE[46][289] = 1;
TABLE[46][40] = 1;
TABLE[46][294] = 1;
TABLE[46][295] = 1;
TABLE[46][278] = 1;
TABLE[46][33] = 1;
TABLE[46][126] = 1;
TABLE[46][45] = 1;
TABLE[46][43] = 1;
TABLE[46][42] = 1;
TABLE[46][38] = 1;
TABLE[47][278] = 1;
TABLE[47][295] = 1;
TABLE[47][294] = 1;
TABLE[47][40] = 1;
TABLE[47][289] = 1;
TABLE[47][288] = 1;
TABLE[47][298] = 1;
TABLE[47][38] = 1;
TABLE[47][42] = 1;
TABLE[47][43] = 1;
TABLE[47][45] = 1;
TABLE[47][126] = 1;
TABLE[47][33] = 1;
TABLE[48][278] = 1;
TABLE[48][295] = 1;
TABLE[48][294] = 1;
TABLE[48][40] = 1;
TABLE[48][289] = 1;
TABLE[48][288] = 1;
TABLE[48][298] = 1;
TABLE[48][38] = 1;
TABLE[48][42] = 1;
TABLE[48][43] = 1;
TABLE[48][45] = 1;
TABLE[48][126] = 1;
TABLE[48][33] = 1;
TABLE[49][298] = 1;
TABLE[49][288] = 1;
TABLE[49][289] = 1;
TABLE[49][40] = 1;
TABLE[49][294] = 1;
TABLE[49][295] = 1;
TABLE[49][278] = 1;
TABLE[49][33] = 1;
TABLE[49][126] = 1;
TABLE[49][45] = 1;
TABLE[49][43] = 1;
TABLE[49][42] = 1;
TABLE[49][38] = 1;
TABLE[50][298] = 1;
TABLE[50][288] = 1;
TABLE[50][289] = 1;
TABLE[50][40] = 1;
TABLE[50][294] = 1;
TABLE[50][295] = 1;
TABLE[50][278] = 1;
TABLE[50][33] = 1;
TABLE[50][126] = 1;
TABLE[50][45] = 1;
TABLE[50][43] = 1;
TABLE[50][42] = 1;
TABLE[50][38] = 1;
TABLE[51][278] = 1;
TABLE[51][295] = 1;
TABLE[51][294] = 1;
TABLE[51][40] = 1;
TABLE[51][289] = 1;
TABLE[51][288] = 1;
TABLE[51][298] = 1;
TABLE[51][38] = 1;
TABLE[51][42] = 1;
TABLE[51][43] = 1;
TABLE[51][45] = 1;
TABLE[51][126] = 1;
TABLE[51][33] = 1;
TABLE[52][278] = 1;
TABLE[52][295] = 1;
TABLE[52][294] = 1;
TABLE[52][40] = 1;
TABLE[52][289] = 1;
TABLE[52][288] = 1;
TABLE[52][298] = 1;
TABLE[52][38] = 1;
TABLE[52][42] = 1;
TABLE[52][43] = 1;
TABLE[52][45] = 1;
TABLE[52][126] = 1;
TABLE[52][33] = 1;
TABLE[53][278] = 1;
TABLE[53][295] = 1;
TABLE[53][294] = 1;
TABLE[53][40] = 1;
TABLE[53][289] = 1;
TABLE[53][288] = 1;
TABLE[53][298] = 1;
TABLE[53][38] = 1;
TABLE[53][42] = 1;
TABLE[53][43] = 1;
TABLE[53][45] = 1;
TABLE[53][126] = 1;
TABLE[53][33] = 1;
TABLE[54][298] = 1;
TABLE[54][288] = 1;
TABLE[54][289] = 1;
TABLE[54][40] = 1;
TABLE[54][294] = 1;
TABLE[54][295] = 1;
TABLE[54][278] = 1;
TABLE[54][33] = 1;
TABLE[54][126] = 1;
TABLE[54][45] = 1;
TABLE[54][43] = 1;
TABLE[54][42] = 1;
TABLE[54][38] = 1;
TABLE[55][298] = 1;
TABLE[55][288] = 1;
TABLE[55][289] = 1;
TABLE[55][40] = 1;
TABLE[55][294] = 1;
TABLE[55][295] = 1;
TABLE[55][278] = 1;
TABLE[55][33] = 1;
TABLE[55][126] = 1;
TABLE[55][45] = 1;
TABLE[55][43] = 1;
TABLE[55][42] = 1;
TABLE[55][38] = 1;
TABLE[56][291] = 1;
TABLE[57][278] = 1;
TABLE[57][295] = 1;
TABLE[57][294] = 1;
TABLE[57][40] = 1;
TABLE[57][289] = 1;
TABLE[57][288] = 1;
TABLE[57][298] = 1;
TABLE[57][38] = 1;
TABLE[57][42] = 1;
TABLE[57][43] = 1;
TABLE[57][45] = 1;
TABLE[57][126] = 1;
TABLE[57][33] = 1;
TABLE[58][298] = 1;
TABLE[58][288] = 1;
TABLE[58][289] = 1;
TABLE[58][40] = 1;
TABLE[58][294] = 1;
TABLE[58][295] = 1;
TABLE[58][278] = 1;
TABLE[58][33] = 1;
TABLE[58][126] = 1;
TABLE[58][45] = 1;
TABLE[58][43] = 1;
TABLE[58][42] = 1;
TABLE[58][38] = 1;
TABLE[59][298] = 1;
TABLE[59][288] = 1;
TABLE[59][289] = 1;
TABLE[59][40] = 1;
TABLE[59][294] = 1;
TABLE[59][295] = 1;
TABLE[59][278] = 1;
TABLE[59][33] = 1;
TABLE[59][126] = 1;
TABLE[59][45] = 1;
TABLE[59][43] = 1;
TABLE[59][42] = 1;
TABLE[59][38] = 1;
TABLE[60][274] = 1;
TABLE[60][256] = 1;
TABLE[60][279] = 1;
TABLE[60][267] = 1;
TABLE[60][282] = 1;
TABLE[60][298] = 1;
TABLE[60][284] = 1;
TABLE[60][277] = 1;
TABLE[60][264] = 1;
TABLE[60][268] = 1;
TABLE[60][273] = 1;
TABLE[60][272] = 1;
TABLE[60][276] = 1;
TABLE[60][259] = 1;
TABLE[60][285] = 1;
TABLE[60][286] = 1;
TABLE[60][260] = 1;
TABLE[60][266] = 1;
TABLE[60][283] = 1;
TABLE[60][280] = 1;
TABLE[61][274] = 1;
TABLE[61][256] = 1;
TABLE[61][279] = 1;
TABLE[61][267] = 1;
TABLE[61][282] = 1;
TABLE[61][298] = 1;
TABLE[61][284] = 1;
TABLE[61][277] = 1;
TABLE[61][264] = 1;
TABLE[61][268] = 1;
TABLE[61][273] = 1;
TABLE[61][272] = 1;
TABLE[61][276] = 1;
TABLE[61][259] = 1;
TABLE[61][285] = 1;
TABLE[61][286] = 1;
TABLE[61][260] = 1;
TABLE[61][266] = 1;
TABLE[61][283] = 1;
TABLE[61][280] = 1;
TABLE[62][282] = 1;
TABLE[62][267] = 1;
TABLE[62][279] = 1;
TABLE[62][256] = 1;
TABLE[62][274] = 1;
TABLE[63][282] = 1;
TABLE[63][267] = 1;
TABLE[63][279] = 1;
TABLE[63][256] = 1;
TABLE[63][274] = 1;
TABLE[64][285] = 1;
TABLE[64][259] = 1;
TABLE[64][276] = 1;
TABLE[64][272] = 1;
TABLE[64][273] = 1;
TABLE[64][268] = 1;
TABLE[64][264] = 1;
TABLE[64][277] = 1;
TABLE[64][284] = 1;
TABLE[64][298] = 1;
TABLE[64][266] = 1;
TABLE[64][280] = 1;
TABLE[64][283] = 1;
TABLE[65][285] = 1;
TABLE[65][259] = 1;
TABLE[65][276] = 1;
TABLE[65][272] = 1;
TABLE[65][273] = 1;
TABLE[65][268] = 1;
TABLE[65][264] = 1;
TABLE[65][277] = 1;
TABLE[65][284] = 1;
TABLE[65][298] = 1;
TABLE[65][266] = 1;
TABLE[65][280] = 1;
TABLE[65][283] = 1;
TABLE[66][260] = 1;
TABLE[66][286] = 1;
TABLE[67][260] = 1;
TABLE[67][286] = 1;
TABLE[68][298] = 1;
TABLE[68][40] = 1;
TABLE[68][42] = 1;
TABLE[69][42] = 1;
TABLE[69][40] = 1;
TABLE[69][298] = 1;
TABLE[70][42] = 1;
TABLE[70][40] = 1;
TABLE[70][298] = 1;
TABLE[71][42] = 1;
TABLE[71][40] = 1;
TABLE[71][298] = 1;
TABLE[72][282] = 1;
TABLE[73][267] = 1;
TABLE[74][279] = 1;
TABLE[75][256] = 1;
TABLE[76][274] = 1;
TABLE[77][285] = 1;
TABLE[78][259] = 1;
TABLE[79][276] = 1;
TABLE[80][272] = 1;
TABLE[81][273] = 1;
TABLE[82][268] = 1;
TABLE[83][264] = 1;
TABLE[84][277] = 1;
TABLE[85][284] = 1;
TABLE[86][283] = 1;
TABLE[86][280] = 1;
TABLE[87][266] = 1;
TABLE[88][298] = 1;
TABLE[89][280] = 1;
TABLE[89][283] = 1;
TABLE[90][280] = 1;
TABLE[90][283] = 1;
TABLE[91][280] = 1;
TABLE[91][283] = 1;
TABLE[92][280] = 1;
TABLE[93][283] = 1;
TABLE[94][285] = 1;
TABLE[94][259] = 1;
TABLE[94][276] = 1;
TABLE[94][272] = 1;
TABLE[94][273] = 1;
TABLE[94][268] = 1;
TABLE[94][264] = 1;
TABLE[94][277] = 1;
TABLE[94][284] = 1;
TABLE[94][298] = 1;
TABLE[94][260] = 1;
TABLE[94][286] = 1;
TABLE[94][266] = 1;
TABLE[94][280] = 1;
TABLE[94][283] = 1;
TABLE[95][298] = 1;
TABLE[95][284] = 1;
TABLE[95][277] = 1;
TABLE[95][264] = 1;
TABLE[95][268] = 1;
TABLE[95][273] = 1;
TABLE[95][272] = 1;
TABLE[95][276] = 1;
TABLE[95][259] = 1;
TABLE[95][285] = 1;
TABLE[95][266] = 1;
TABLE[95][286] = 1;
TABLE[95][260] = 1;
TABLE[95][283] = 1;
TABLE[95][280] = 1;
TABLE[96][298] = 1;
TABLE[96][284] = 1;
TABLE[96][277] = 1;
TABLE[96][264] = 1;
TABLE[96][268] = 1;
TABLE[96][273] = 1;
TABLE[96][272] = 1;
TABLE[96][276] = 1;
TABLE[96][259] = 1;
TABLE[96][285] = 1;
TABLE[96][266] = 1;
TABLE[96][286] = 1;
TABLE[96][260] = 1;
TABLE[96][283] = 1;
TABLE[96][280] = 1;
TABLE[97][285] = 1;
TABLE[97][259] = 1;
TABLE[97][276] = 1;
TABLE[97][272] = 1;
TABLE[97][273] = 1;
TABLE[97][268] = 1;
TABLE[97][264] = 1;
TABLE[97][277] = 1;
TABLE[97][284] = 1;
TABLE[97][298] = 1;
TABLE[97][266] = 1;
TABLE[97][280] = 1;
TABLE[97][283] = 1;
TABLE[98][285] = 1;
TABLE[98][259] = 1;
TABLE[98][276] = 1;
TABLE[98][272] = 1;
TABLE[98][273] = 1;
TABLE[98][268] = 1;
TABLE[98][264] = 1;
TABLE[98][277] = 1;
TABLE[98][284] = 1;
TABLE[98][298] = 1;
TABLE[98][266] = 1;
TABLE[98][280] = 1;
TABLE[98][283] = 1;
TABLE[99][260] = 1;
TABLE[99][286] = 1;
TABLE[100][260] = 1;
TABLE[100][286] = 1;
TABLE[101][58] = 1;
TABLE[101][298] = 1;
TABLE[101][40] = 1;
TABLE[101][42] = 1;
TABLE[102][58] = 1;
TABLE[102][42] = 1;
TABLE[102][40] = 1;
TABLE[102][298] = 1;
TABLE[103][42] = 1;
TABLE[103][40] = 1;
TABLE[103][298] = 1;
TABLE[104][58] = 1;
TABLE[105][42] = 1;
TABLE[105][40] = 1;
TABLE[105][298] = 1;
TABLE[106][266] = 1;
TABLE[107][266] = 1;
TABLE[108][266] = 1;
TABLE[109][298] = 1;
TABLE[110][298] = 1;
TABLE[111][298] = 1;
TABLE[112][298] = 1;
TABLE[113][260] = 1;
TABLE[114][286] = 1;
TABLE[115][42] = 1;
TABLE[116][298] = 1;
TABLE[116][40] = 1;
TABLE[117][298] = 1;
TABLE[118][40] = 1;
TABLE[119][298] = 1;
TABLE[119][40] = 1;
TABLE[120][298] = 1;
TABLE[120][40] = 1;
TABLE[121][298] = 1;
TABLE[121][40] = 1;
TABLE[122][298] = 1;
TABLE[122][40] = 1;
TABLE[123][298] = 1;
TABLE[123][40] = 1;
TABLE[124][42] = 1;
TABLE[125][42] = 1;
TABLE[126][42] = 1;
TABLE[127][42] = 1;
TABLE[128][260] = 1;
TABLE[128][286] = 1;
TABLE[129][286] = 1;
TABLE[129][260] = 1;
TABLE[130][274] = 1;
TABLE[130][256] = 1;
TABLE[130][279] = 1;
TABLE[130][267] = 1;
TABLE[130][282] = 1;
TABLE[130][298] = 1;
TABLE[130][284] = 1;
TABLE[130][277] = 1;
TABLE[130][264] = 1;
TABLE[130][268] = 1;
TABLE[130][273] = 1;
TABLE[130][272] = 1;
TABLE[130][276] = 1;
TABLE[130][259] = 1;
TABLE[130][285] = 1;
TABLE[130][286] = 1;
TABLE[130][260] = 1;
TABLE[130][266] = 1;
TABLE[130][283] = 1;
TABLE[130][280] = 1;
TABLE[131][274] = 1;
TABLE[131][256] = 1;
TABLE[131][279] = 1;
TABLE[131][267] = 1;
TABLE[131][282] = 1;
TABLE[131][298] = 1;
TABLE[131][284] = 1;
TABLE[131][277] = 1;
TABLE[131][264] = 1;
TABLE[131][268] = 1;
TABLE[131][273] = 1;
TABLE[131][272] = 1;
TABLE[131][276] = 1;
TABLE[131][259] = 1;
TABLE[131][285] = 1;
TABLE[131][286] = 1;
TABLE[131][260] = 1;
TABLE[131][266] = 1;
TABLE[131][283] = 1;
TABLE[131][280] = 1;
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
TABLE[132][298] = 1;
TABLE[132][282] = 1;
TABLE[132][267] = 1;
TABLE[132][279] = 1;
TABLE[132][256] = 1;
TABLE[132][274] = 1;
TABLE[132][266] = 1;
TABLE[132][280] = 1;
TABLE[132][283] = 1;
TABLE[133][274] = 1;
TABLE[133][256] = 1;
TABLE[133][279] = 1;
TABLE[133][267] = 1;
TABLE[133][282] = 1;
TABLE[133][298] = 1;
TABLE[133][284] = 1;
TABLE[133][277] = 1;
TABLE[133][264] = 1;
TABLE[133][268] = 1;
TABLE[133][273] = 1;
TABLE[133][272] = 1;
TABLE[133][276] = 1;
TABLE[133][259] = 1;
TABLE[133][285] = 1;
TABLE[133][286] = 1;
TABLE[133][260] = 1;
TABLE[133][266] = 1;
TABLE[133][283] = 1;
TABLE[133][280] = 1;
TABLE[134][274] = 1;
TABLE[134][256] = 1;
TABLE[134][279] = 1;
TABLE[134][267] = 1;
TABLE[134][282] = 1;
TABLE[134][298] = 1;
TABLE[134][284] = 1;
TABLE[134][277] = 1;
TABLE[134][264] = 1;
TABLE[134][268] = 1;
TABLE[134][273] = 1;
TABLE[134][272] = 1;
TABLE[134][276] = 1;
TABLE[134][259] = 1;
TABLE[134][285] = 1;
TABLE[134][286] = 1;
TABLE[134][260] = 1;
TABLE[134][266] = 1;
TABLE[134][283] = 1;
TABLE[134][280] = 1;
TABLE[135][274] = 1;
TABLE[135][256] = 1;
TABLE[135][279] = 1;
TABLE[135][267] = 1;
TABLE[135][282] = 1;
TABLE[135][298] = 1;
TABLE[135][284] = 1;
TABLE[135][277] = 1;
TABLE[135][264] = 1;
TABLE[135][268] = 1;
TABLE[135][273] = 1;
TABLE[135][272] = 1;
TABLE[135][276] = 1;
TABLE[135][259] = 1;
TABLE[135][285] = 1;
TABLE[135][286] = 1;
TABLE[135][260] = 1;
TABLE[135][266] = 1;
TABLE[135][283] = 1;
TABLE[135][280] = 1;
TABLE[136][274] = 1;
TABLE[136][256] = 1;
TABLE[136][279] = 1;
TABLE[136][267] = 1;
TABLE[136][282] = 1;
TABLE[136][298] = 1;
TABLE[136][284] = 1;
TABLE[136][277] = 1;
TABLE[136][264] = 1;
TABLE[136][268] = 1;
TABLE[136][273] = 1;
TABLE[136][272] = 1;
TABLE[136][276] = 1;
TABLE[136][259] = 1;
TABLE[136][285] = 1;
TABLE[136][286] = 1;
TABLE[136][260] = 1;
TABLE[136][266] = 1;
TABLE[136][283] = 1;
TABLE[136][280] = 1;
TABLE[137][298] = 1;
TABLE[138][298] = 1;
TABLE[139][298] = 1;
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
TABLE[139][286] = 1;
TABLE[139][260] = 1;
TABLE[139][283] = 1;
TABLE[139][280] = 1;
TABLE[140][298] = 1;
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
TABLE[140][286] = 1;
TABLE[140][260] = 1;
TABLE[140][283] = 1;
TABLE[140][280] = 1;
TABLE[141][42] = 1;
TABLE[142][40] = 1;
TABLE[142][91] = 1;
TABLE[143][42] = 1;
TABLE[144][40] = 1;
TABLE[145][91] = 1;
TABLE[146][91] = 1;
TABLE[147][40] = 1;
TABLE[147][91] = 1;
TABLE[148][40] = 1;
TABLE[148][91] = 1;
TABLE[149][40] = 1;
TABLE[150][40] = 1;
TABLE[151][40] = 1;
TABLE[151][91] = 1;
TABLE[152][40] = 1;
TABLE[152][91] = 1;
TABLE[153][278] = 1;
TABLE[153][295] = 1;
TABLE[153][294] = 1;
TABLE[153][40] = 1;
TABLE[153][289] = 1;
TABLE[153][288] = 1;
TABLE[153][298] = 1;
TABLE[153][38] = 1;
TABLE[153][42] = 1;
TABLE[153][43] = 1;
TABLE[153][45] = 1;
TABLE[153][126] = 1;
TABLE[153][33] = 1;
TABLE[154][123] = 1;
TABLE[155][123] = 1;
TABLE[156][298] = 1;
TABLE[156][288] = 1;
TABLE[156][289] = 1;
TABLE[156][40] = 1;
TABLE[156][294] = 1;
TABLE[156][295] = 1;
TABLE[156][278] = 1;
TABLE[156][123] = 1;
TABLE[156][33] = 1;
TABLE[156][126] = 1;
TABLE[156][45] = 1;
TABLE[156][43] = 1;
TABLE[156][42] = 1;
TABLE[156][38] = 1;
TABLE[157][123] = 1;
TABLE[157][278] = 1;
TABLE[157][295] = 1;
TABLE[157][294] = 1;
TABLE[157][40] = 1;
TABLE[157][289] = 1;
TABLE[157][288] = 1;
TABLE[157][298] = 1;
TABLE[157][38] = 1;
TABLE[157][42] = 1;
TABLE[157][43] = 1;
TABLE[157][45] = 1;
TABLE[157][126] = 1;
TABLE[157][33] = 1;
TABLE[158][298] = 1;
TABLE[158][258] = 1;
TABLE[158][262] = 1;
TABLE[159][123] = 1;
TABLE[160][59] = 1;
TABLE[160][278] = 1;
TABLE[160][295] = 1;
TABLE[160][294] = 1;
TABLE[160][40] = 1;
TABLE[160][289] = 1;
TABLE[160][288] = 1;
TABLE[160][298] = 1;
TABLE[160][38] = 1;
TABLE[160][42] = 1;
TABLE[160][43] = 1;
TABLE[160][45] = 1;
TABLE[160][126] = 1;
TABLE[160][33] = 1;
TABLE[161][271] = 1;
TABLE[161][281] = 1;
TABLE[162][287] = 1;
TABLE[162][263] = 1;
TABLE[162][269] = 1;
TABLE[163][270] = 1;
TABLE[163][261] = 1;
TABLE[163][257] = 1;
TABLE[163][275] = 1;
TABLE[164][298] = 1;
TABLE[165][258] = 1;
TABLE[166][262] = 1;
TABLE[167][123] = 1;
TABLE[168][123] = 1;
TABLE[169][123] = 1;
TABLE[170][123] = 1;
TABLE[171][260] = 1;
TABLE[171][286] = 1;
TABLE[171][285] = 1;
TABLE[171][259] = 1;
TABLE[171][276] = 1;
TABLE[171][272] = 1;
TABLE[171][273] = 1;
TABLE[171][268] = 1;
TABLE[171][264] = 1;
TABLE[171][277] = 1;
TABLE[171][284] = 1;
TABLE[171][298] = 1;
TABLE[171][282] = 1;
TABLE[171][267] = 1;
TABLE[171][279] = 1;
TABLE[171][256] = 1;
TABLE[171][274] = 1;
TABLE[171][266] = 1;
TABLE[171][280] = 1;
TABLE[171][283] = 1;
TABLE[172][274] = 1;
TABLE[172][256] = 1;
TABLE[172][279] = 1;
TABLE[172][267] = 1;
TABLE[172][282] = 1;
TABLE[172][298] = 1;
TABLE[172][284] = 1;
TABLE[172][277] = 1;
TABLE[172][264] = 1;
TABLE[172][268] = 1;
TABLE[172][273] = 1;
TABLE[172][272] = 1;
TABLE[172][276] = 1;
TABLE[172][259] = 1;
TABLE[172][285] = 1;
TABLE[172][286] = 1;
TABLE[172][260] = 1;
TABLE[172][266] = 1;
TABLE[172][283] = 1;
TABLE[172][280] = 1;
TABLE[173][262] = 1;
TABLE[173][258] = 1;
TABLE[173][298] = 1;
TABLE[173][123] = 1;
TABLE[173][288] = 1;
TABLE[173][289] = 1;
TABLE[173][40] = 1;
TABLE[173][294] = 1;
TABLE[173][295] = 1;
TABLE[173][278] = 1;
TABLE[173][59] = 1;
TABLE[173][281] = 1;
TABLE[173][271] = 1;
TABLE[173][269] = 1;
TABLE[173][263] = 1;
TABLE[173][287] = 1;
TABLE[173][275] = 1;
TABLE[173][257] = 1;
TABLE[173][261] = 1;
TABLE[173][270] = 1;
TABLE[173][33] = 1;
TABLE[173][126] = 1;
TABLE[173][45] = 1;
TABLE[173][43] = 1;
TABLE[173][42] = 1;
TABLE[173][38] = 1;
TABLE[174][270] = 1;
TABLE[174][261] = 1;
TABLE[174][257] = 1;
TABLE[174][275] = 1;
TABLE[174][287] = 1;
TABLE[174][263] = 1;
TABLE[174][269] = 1;
TABLE[174][271] = 1;
TABLE[174][281] = 1;
TABLE[174][59] = 1;
TABLE[174][278] = 1;
TABLE[174][295] = 1;
TABLE[174][294] = 1;
TABLE[174][40] = 1;
TABLE[174][289] = 1;
TABLE[174][288] = 1;
TABLE[174][123] = 1;
TABLE[174][298] = 1;
TABLE[174][258] = 1;
TABLE[174][262] = 1;
TABLE[174][38] = 1;
TABLE[174][42] = 1;
TABLE[174][43] = 1;
TABLE[174][45] = 1;
TABLE[174][126] = 1;
TABLE[174][33] = 1;
TABLE[175][59] = 1;
TABLE[176][298] = 1;
TABLE[176][288] = 1;
TABLE[176][289] = 1;
TABLE[176][40] = 1;
TABLE[176][294] = 1;
TABLE[176][295] = 1;
TABLE[176][278] = 1;
TABLE[176][33] = 1;
TABLE[176][126] = 1;
TABLE[176][45] = 1;
TABLE[176][43] = 1;
TABLE[176][42] = 1;
TABLE[176][38] = 1;
TABLE[177][271] = 1;
TABLE[178][271] = 1;
TABLE[179][281] = 1;
TABLE[180][287] = 1;
TABLE[181][263] = 1;
TABLE[182][269] = 1;
TABLE[183][269] = 1;
TABLE[184][270] = 1;
TABLE[185][261] = 1;
TABLE[186][257] = 1;
TABLE[187][275] = 1;
TABLE[188][275] = 1;
TABLE[189][42] = 1;
TABLE[189][40] = 1;
TABLE[189][274] = 1;
TABLE[189][256] = 1;
TABLE[189][279] = 1;
TABLE[189][267] = 1;
TABLE[189][282] = 1;
TABLE[189][298] = 1;
TABLE[189][284] = 1;
TABLE[189][277] = 1;
TABLE[189][264] = 1;
TABLE[189][268] = 1;
TABLE[189][273] = 1;
TABLE[189][272] = 1;
TABLE[189][276] = 1;
TABLE[189][259] = 1;
TABLE[189][285] = 1;
TABLE[189][286] = 1;
TABLE[189][260] = 1;
TABLE[189][266] = 1;
TABLE[189][283] = 1;
TABLE[189][280] = 1;
TABLE[190][260] = 1;
TABLE[190][286] = 1;
TABLE[190][285] = 1;
TABLE[190][259] = 1;
TABLE[190][276] = 1;
TABLE[190][272] = 1;
TABLE[190][273] = 1;
TABLE[190][268] = 1;
TABLE[190][264] = 1;
TABLE[190][277] = 1;
TABLE[190][284] = 1;
TABLE[190][298] = 1;
TABLE[190][282] = 1;
TABLE[190][267] = 1;
TABLE[190][279] = 1;
TABLE[190][256] = 1;
TABLE[190][274] = 1;
TABLE[190][40] = 1;
TABLE[190][42] = 1;
TABLE[190][266] = 1;
TABLE[190][280] = 1;
TABLE[190][283] = 1;
TABLE[191][260] = 1;
TABLE[191][286] = 1;
TABLE[191][285] = 1;
TABLE[191][259] = 1;
TABLE[191][276] = 1;
TABLE[191][272] = 1;
TABLE[191][273] = 1;
TABLE[191][268] = 1;
TABLE[191][264] = 1;
TABLE[191][277] = 1;
TABLE[191][284] = 1;
TABLE[191][298] = 1;
TABLE[191][282] = 1;
TABLE[191][267] = 1;
TABLE[191][279] = 1;
TABLE[191][256] = 1;
TABLE[191][274] = 1;
TABLE[191][40] = 1;
TABLE[191][42] = 1;
TABLE[191][266] = 1;
TABLE[191][280] = 1;
TABLE[191][283] = 1;
TABLE[192][260] = 1;
TABLE[192][286] = 1;
TABLE[192][285] = 1;
TABLE[192][259] = 1;
TABLE[192][276] = 1;
TABLE[192][272] = 1;
TABLE[192][273] = 1;
TABLE[192][268] = 1;
TABLE[192][264] = 1;
TABLE[192][277] = 1;
TABLE[192][284] = 1;
TABLE[192][298] = 1;
TABLE[192][282] = 1;
TABLE[192][267] = 1;
TABLE[192][279] = 1;
TABLE[192][256] = 1;
TABLE[192][274] = 1;
TABLE[192][266] = 1;
TABLE[192][280] = 1;
TABLE[192][283] = 1;
TABLE[193][274] = 1;
TABLE[193][256] = 1;
TABLE[193][279] = 1;
TABLE[193][267] = 1;
TABLE[193][282] = 1;
TABLE[193][298] = 1;
TABLE[193][284] = 1;
TABLE[193][277] = 1;
TABLE[193][264] = 1;
TABLE[193][268] = 1;
TABLE[193][273] = 1;
TABLE[193][272] = 1;
TABLE[193][276] = 1;
TABLE[193][259] = 1;
TABLE[193][285] = 1;
TABLE[193][286] = 1;
TABLE[193][260] = 1;
TABLE[193][266] = 1;
TABLE[193][283] = 1;
TABLE[193][280] = 1;
TABLE[194][274] = 1;
TABLE[194][256] = 1;
TABLE[194][279] = 1;
TABLE[194][267] = 1;
TABLE[194][282] = 1;
TABLE[194][298] = 1;
TABLE[194][284] = 1;
TABLE[194][277] = 1;
TABLE[194][264] = 1;
TABLE[194][268] = 1;
TABLE[194][273] = 1;
TABLE[194][272] = 1;
TABLE[194][276] = 1;
TABLE[194][259] = 1;
TABLE[194][285] = 1;
TABLE[194][286] = 1;
TABLE[194][260] = 1;
TABLE[194][266] = 1;
TABLE[194][283] = 1;
TABLE[194][280] = 1;
TABLE[195][42] = 1;
TABLE[195][40] = 1;
TABLE[195][298] = 1;
TABLE[196][42] = 1;
TABLE[196][40] = 1;
TABLE[196][298] = 1;
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
      case 1: return 0; break;
      case 6: return 0; break;
      case 24: return 0; break;
      case 70: return 0; break;
      case 80: return 0; break;
      case 111: return 0; break;
      case 135: return 0; break;
      case 146: return 0; break;
      case 168: return 0; break;
      case 184: return 0; break;
      case 194: return 0; break;
      case 204: return 0; break;
      case 214: return 0; break;
      case 224: return 0; break;
      case 234: return 0; break;
      case 244: return 0; break;
      case 254: return 0; break;
      case 264: return 0; break;
      case 276: return 0; break;
      case 286: return 0; break;
      case 290: return 0; break;
      case 300: return 0; break;
      case 304: return 0; break;
      case 315: return 0; break;
      case 342: return 0; break;
      case 352: return 0; break;
      case 362: return 0; break;
      case 382: return 0; break;
      case 430: return 0; break;
      case 450: return 0; break;
      case 458: return 0; break;
      case 467: return 0; break;
      case 473: return 0; break;
      case 491: return 0; break;
      case 501: return 0; break;
      case 516: return 0; break;
      case 536: return 0; break;
      case 546: return 0; break;
      case 556: return 0; break;
      case 564: return 0; break;
      case 573: return 0; break;
      case 616: return 0; break;
      case 636: return 0; break;
      case 645: return 0; break;
      case 655: return 0; break;
      case 665: return 0; break;
      case 679: return 0; break;
      case 689: return 0; break;
      case 698: return 0; break;
      case 711: return 0; break;
      case 765: return 0; break;
      case 782: return 0; break;
      case 792: return 0; break;
      case 816: return 0; break;
      case 835: return 0; break;
      case 859: return 0; break;
      case 868: return 0; break;
      case 877: return 0; break;
      case 886: return 0; break;
      case 912: return 0; break;
      case 949: return 0; break;
      case 976: return 0; break;
      case 985: return 0; break;
      case 993: return 0; break;
   }
}
char * yyprintname(n)
   int n;
{
   if (n <= 50000)
      switch(n) {
         case 1: return "YYSTART"; break;
         case 6: return "primary_expression"; break;
         case 24: return "postfix_expression"; break;
         case 70: return "argument_expression_list"; break;
         case 80: return "unary_expression"; break;
         case 111: return "unary_operator"; break;
         case 135: return "cast_expression"; break;
         case 146: return "multiplicative_expression"; break;
         case 168: return "additive_expression"; break;
         case 184: return "shift_expression"; break;
         case 194: return "relational_expression"; break;
         case 204: return "equality_expression"; break;
         case 214: return "and_expression"; break;
         case 224: return "exclusive_or_expression"; break;
         case 234: return "inclusive_or_expression"; break;
         case 244: return "logical_and_expression"; break;
         case 254: return "logical_or_expression"; break;
         case 264: return "conditional_expression"; break;
         case 276: return "assignment_expression"; break;
         case 286: return "assignment_operator"; break;
         case 290: return "expression"; break;
         case 300: return "constant_expression"; break;
         case 304: return "declaration"; break;
         case 315: return "declaration_specifiers"; break;
         case 342: return "init_declarator_list"; break;
         case 352: return "init_declarator"; break;
         case 362: return "storage_class_specifier"; break;
         case 382: return "type_specifier"; break;
         case 430: return "struct_or_union_specifier"; break;
         case 450: return "struct_or_union"; break;
         case 458: return "struct_declaration_list"; break;
         case 467: return "struct_declaration"; break;
         case 473: return "specifier_qualifier_list"; break;
         case 491: return "struct_declarator_list"; break;
         case 501: return "struct_declarator"; break;
         case 516: return "enum_specifier"; break;
         case 536: return "enumerator_list"; break;
         case 546: return "enumerator"; break;
         case 556: return "type_qualifier"; break;
         case 564: return "declarator"; break;
         case 573: return "direct_declarator"; break;
         case 616: return "pointer"; break;
         case 636: return "type_qualifier_list"; break;
         case 645: return "parameter_type_list"; break;
         case 655: return "parameter_list"; break;
         case 665: return "parameter_declaration"; break;
         case 679: return "identifier_list"; break;
         case 689: return "type_name"; break;
         case 698: return "abstract_declarator"; break;
         case 711: return "direct_abstract_declarator"; break;
         case 765: return "initializer"; break;
         case 782: return "initializer_list"; break;
         case 792: return "statement"; break;
         case 816: return "labeled_statement"; break;
         case 835: return "compound_statement"; break;
         case 859: return "declaration_list"; break;
         case 868: return "statement_list"; break;
         case 877: return "expression_statement"; break;
         case 886: return "selection_statement"; break;
         case 912: return "iteration_statement"; break;
         case 949: return "jump_statement"; break;
         case 976: return "root"; break;
         case 985: return "external_declaration"; break;
         case 993: return "function_definition"; break;
   }
   else 
      switch(n-50000) {
         case 304: return "INTCONST"; break;
         case 303: return "FLOATCONST"; break;
         case 302: return "CHARACTER"; break;
         case 301: return "INCLUDE"; break;
         case 300: return "BIT_OP"; break;
         case 299: return "PREPROC"; break;
         case 298: return "IDENTIFIER"; break;
         case 297: return "LOGIC_OP"; break;
         case 296: return "PTR_OP"; break;
         case 295: return "DEC_OP"; break;
         case 294: return "INC_OP"; break;
         case 293: return "ARIT_OP"; break;
         case 292: return "COMPARE"; break;
         case 291: return "ASSIGN"; break;
         case 290: return "ELLIPSIS"; break;
         case 289: return "STRING_LITERAL"; break;
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
