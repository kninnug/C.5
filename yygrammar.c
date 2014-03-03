#line 1 "ass2.y"

#include <stdio.h>

extern char yytext[];
extern int column;
extern long int yypos;

void yyerror(char * s){
	fflush(stdout);
	printf("%u: Syntax error: %s\n", yypos, s);
}


# line 16 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 198: {
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

primary_expression ()
{
   switch(yyselect()) {
   case 3: {
      get_lexval();
#line 28 "ass2.y"
 printf("Identifier\n"); 
# line 49 "yygrammar.c"
      } break;
   case 4: {
      get_lexval();
#line 29 "ass2.y"
 printf("Constant\n"); 
# line 55 "yygrammar.c"
      } break;
   case 5: {
      get_lexval();
#line 30 "ass2.y"
 printf("String\n"); 
# line 61 "yygrammar.c"
      } break;
   case 6: {
      get_lexval();
      expression();
      get_lexval();
#line 31 "ass2.y"
 printf("Expression\n"); 
# line 69 "yygrammar.c"
      } break;
   }
}

postfix_expression ()
{
   switch(yyselect()) {
   case 7: {
      primary_expression();
      } break;
   case 8: {
      postfix_expression();
      get_lexval();
      expression();
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
      argument_expression_list();
      get_lexval();
      } break;
   case 11: {
      postfix_expression();
      get_lexval();
      get_lexval();
      } break;
   case 12: {
      postfix_expression();
      get_lexval();
      get_lexval();
      } break;
   case 13: {
      postfix_expression();
      get_lexval();
      } break;
   case 14: {
      postfix_expression();
      get_lexval();
      } break;
   }
}

argument_expression_list ()
{
   switch(yyselect()) {
   case 15: {
      assignment_expression();
      } break;
   case 16: {
      argument_expression_list();
      get_lexval();
      assignment_expression();
      } break;
   }
}

unary_expression ()
{
   switch(yyselect()) {
   case 17: {
      postfix_expression();
      } break;
   case 18: {
      get_lexval();
      unary_expression();
      } break;
   case 19: {
      get_lexval();
      unary_expression();
      } break;
   case 20: {
      unary_operator();
      cast_expression();
      } break;
   case 21: {
      get_lexval();
      unary_expression();
      } break;
   case 22: {
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
   case 27: {
      get_lexval();
      } break;
   case 28: {
      get_lexval();
      } break;
   }
}

cast_expression ()
{
   switch(yyselect()) {
   case 29: {
      unary_expression();
      } break;
   case 30: {
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
   case 31: {
      cast_expression();
      } break;
   case 32: {
      multiplicative_expression();
      get_lexval();
      cast_expression();
      } break;
   case 33: {
      multiplicative_expression();
      get_lexval();
      cast_expression();
      } break;
   case 34: {
      multiplicative_expression();
      get_lexval();
      cast_expression();
      } break;
   }
}

additive_expression ()
{
   switch(yyselect()) {
   case 35: {
      multiplicative_expression();
      } break;
   case 36: {
      additive_expression();
      get_lexval();
      multiplicative_expression();
      } break;
   case 37: {
      additive_expression();
      get_lexval();
      multiplicative_expression();
      } break;
   }
}

shift_expression ()
{
   switch(yyselect()) {
   case 38: {
      additive_expression();
      } break;
   case 39: {
      shift_expression();
      get_lexval();
      additive_expression();
      } break;
   }
}

relational_expression ()
{
   switch(yyselect()) {
   case 40: {
      shift_expression();
      } break;
   case 41: {
      relational_expression();
      get_lexval();
      shift_expression();
      } break;
   }
}

equality_expression ()
{
   switch(yyselect()) {
   case 42: {
      relational_expression();
      } break;
   case 43: {
      equality_expression();
      get_lexval();
      relational_expression();
      } break;
   }
}

and_expression ()
{
   switch(yyselect()) {
   case 44: {
      equality_expression();
      } break;
   case 45: {
      and_expression();
      get_lexval();
      equality_expression();
      } break;
   }
}

exclusive_or_expression ()
{
   switch(yyselect()) {
   case 46: {
      and_expression();
      } break;
   case 47: {
      exclusive_or_expression();
      get_lexval();
      and_expression();
      } break;
   }
}

inclusive_or_expression ()
{
   switch(yyselect()) {
   case 48: {
      exclusive_or_expression();
      } break;
   case 49: {
      inclusive_or_expression();
      get_lexval();
      exclusive_or_expression();
      } break;
   }
}

logical_and_expression ()
{
   switch(yyselect()) {
   case 50: {
      inclusive_or_expression();
      } break;
   case 51: {
      logical_and_expression();
      get_lexval();
      inclusive_or_expression();
      } break;
   }
}

logical_or_expression ()
{
   switch(yyselect()) {
   case 52: {
      logical_and_expression();
      } break;
   case 53: {
      logical_or_expression();
      get_lexval();
      logical_and_expression();
      } break;
   }
}

conditional_expression ()
{
   switch(yyselect()) {
   case 54: {
      logical_or_expression();
      } break;
   case 55: {
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
   case 56: {
      conditional_expression();
      } break;
   case 57: {
      unary_expression();
      get_lexval();
      assignment_expression();
      } break;
   }
}

expression ()
{
   switch(yyselect()) {
   case 58: {
      assignment_expression();
      } break;
   case 59: {
      expression();
      get_lexval();
      assignment_expression();
      } break;
   }
}

constant_expression ()
{
   switch(yyselect()) {
   case 60: {
      conditional_expression();
      } break;
   }
}

declaration ()
{
   switch(yyselect()) {
   case 61: {
      declaration_specifiers();
      get_lexval();
      } break;
   case 62: {
      declaration_specifiers();
      init_declarator_list();
      get_lexval();
      } break;
   }
}

declaration_specifiers ()
{
   switch(yyselect()) {
   case 63: {
      storage_class_specifier();
      } break;
   case 64: {
      storage_class_specifier();
      declaration_specifiers();
      } break;
   case 65: {
      type_specifier();
      } break;
   case 66: {
      type_specifier();
      declaration_specifiers();
      } break;
   case 67: {
      type_qualifier();
      } break;
   case 68: {
      type_qualifier();
      declaration_specifiers();
      } break;
   }
}

init_declarator_list ()
{
   switch(yyselect()) {
   case 69: {
      init_declarator();
      } break;
   case 70: {
      init_declarator_list();
      get_lexval();
      init_declarator();
      } break;
   }
}

init_declarator ()
{
   switch(yyselect()) {
   case 71: {
      declarator();
      } break;
   case 72: {
      declarator();
      get_lexval();
      initializer();
      } break;
   }
}

storage_class_specifier ()
{
   switch(yyselect()) {
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
   case 77: {
      get_lexval();
      } break;
   }
}

type_specifier ()
{
   switch(yyselect()) {
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
      get_lexval();
      } break;
   case 87: {
      struct_or_union_specifier();
      } break;
   case 88: {
      enum_specifier();
      } break;
   case 89: {
      get_lexval();
      } break;
   }
}

struct_or_union_specifier ()
{
   switch(yyselect()) {
   case 90: {
      struct_or_union();
      get_lexval();
      get_lexval();
      struct_declaration_list();
      get_lexval();
      } break;
   case 91: {
      struct_or_union();
      get_lexval();
      struct_declaration_list();
      get_lexval();
      } break;
   case 92: {
      struct_or_union();
      get_lexval();
      } break;
   }
}

struct_or_union ()
{
   switch(yyselect()) {
   case 93: {
      get_lexval();
      } break;
   case 94: {
      get_lexval();
      } break;
   }
}

struct_declaration_list ()
{
   switch(yyselect()) {
   case 95: {
      struct_declaration();
      } break;
   case 96: {
      struct_declaration_list();
      struct_declaration();
      } break;
   }
}

struct_declaration ()
{
   switch(yyselect()) {
   case 97: {
      specifier_qualifier_list();
      struct_declarator_list();
      get_lexval();
      } break;
   }
}

specifier_qualifier_list ()
{
   switch(yyselect()) {
   case 98: {
      type_specifier();
      specifier_qualifier_list();
      } break;
   case 99: {
      type_specifier();
      } break;
   case 100: {
      type_qualifier();
      specifier_qualifier_list();
      } break;
   case 101: {
      type_qualifier();
      } break;
   }
}

struct_declarator_list ()
{
   switch(yyselect()) {
   case 102: {
      struct_declarator();
      } break;
   case 103: {
      struct_declarator_list();
      get_lexval();
      struct_declarator();
      } break;
   }
}

struct_declarator ()
{
   switch(yyselect()) {
   case 104: {
      declarator();
      } break;
   case 105: {
      get_lexval();
      constant_expression();
      } break;
   case 106: {
      declarator();
      get_lexval();
      constant_expression();
      } break;
   }
}

enum_specifier ()
{
   switch(yyselect()) {
   case 107: {
      get_lexval();
      get_lexval();
      enumerator_list();
      get_lexval();
      } break;
   case 108: {
      get_lexval();
      get_lexval();
      get_lexval();
      enumerator_list();
      get_lexval();
      } break;
   case 109: {
      get_lexval();
      get_lexval();
      } break;
   }
}

enumerator_list ()
{
   switch(yyselect()) {
   case 110: {
      enumerator();
      } break;
   case 111: {
      enumerator_list();
      get_lexval();
      enumerator();
      } break;
   }
}

enumerator ()
{
   switch(yyselect()) {
   case 112: {
      get_lexval();
      } break;
   case 113: {
      get_lexval();
      get_lexval();
      constant_expression();
      } break;
   }
}

type_qualifier ()
{
   switch(yyselect()) {
   case 114: {
      get_lexval();
      } break;
   case 115: {
      get_lexval();
      } break;
   }
}

declarator ()
{
   switch(yyselect()) {
   case 116: {
      pointer();
      direct_declarator();
      } break;
   case 117: {
      direct_declarator();
      } break;
   }
}

direct_declarator ()
{
   switch(yyselect()) {
   case 118: {
      get_lexval();
      } break;
   case 119: {
      get_lexval();
      declarator();
      get_lexval();
      } break;
   case 120: {
      direct_declarator();
      get_lexval();
      constant_expression();
      get_lexval();
      } break;
   case 121: {
      direct_declarator();
      get_lexval();
      get_lexval();
      } break;
   case 122: {
      direct_declarator();
      get_lexval();
      parameter_type_list();
      get_lexval();
      } break;
   case 123: {
      direct_declarator();
      get_lexval();
      identifier_list();
      get_lexval();
      } break;
   case 124: {
      direct_declarator();
      get_lexval();
      get_lexval();
      } break;
   }
}

pointer ()
{
   switch(yyselect()) {
   case 125: {
      get_lexval();
      } break;
   case 126: {
      get_lexval();
      type_qualifier_list();
      } break;
   case 127: {
      get_lexval();
      pointer();
      } break;
   case 128: {
      get_lexval();
      type_qualifier_list();
      pointer();
      } break;
   }
}

type_qualifier_list ()
{
   switch(yyselect()) {
   case 129: {
      type_qualifier();
      } break;
   case 130: {
      type_qualifier_list();
      type_qualifier();
      } break;
   }
}

parameter_type_list ()
{
   switch(yyselect()) {
   case 131: {
      parameter_list();
      } break;
   case 132: {
      parameter_list();
      get_lexval();
      get_lexval();
      } break;
   }
}

parameter_list ()
{
   switch(yyselect()) {
   case 133: {
      parameter_declaration();
      } break;
   case 134: {
      parameter_list();
      get_lexval();
      parameter_declaration();
      } break;
   }
}

parameter_declaration ()
{
   switch(yyselect()) {
   case 135: {
      declaration_specifiers();
      declarator();
      } break;
   case 136: {
      declaration_specifiers();
      abstract_declarator();
      } break;
   case 137: {
      declaration_specifiers();
      } break;
   }
}

identifier_list ()
{
   switch(yyselect()) {
   case 138: {
      get_lexval();
      } break;
   case 139: {
      identifier_list();
      get_lexval();
      get_lexval();
      } break;
   }
}

type_name ()
{
   switch(yyselect()) {
   case 140: {
      specifier_qualifier_list();
      } break;
   case 141: {
      specifier_qualifier_list();
      abstract_declarator();
      } break;
   }
}

abstract_declarator ()
{
   switch(yyselect()) {
   case 142: {
      pointer();
      } break;
   case 143: {
      direct_abstract_declarator();
      } break;
   case 144: {
      pointer();
      direct_abstract_declarator();
      } break;
   }
}

direct_abstract_declarator ()
{
   switch(yyselect()) {
   case 145: {
      get_lexval();
      abstract_declarator();
      get_lexval();
      } break;
   case 146: {
      get_lexval();
      get_lexval();
      } break;
   case 147: {
      get_lexval();
      constant_expression();
      get_lexval();
      } break;
   case 148: {
      direct_abstract_declarator();
      get_lexval();
      get_lexval();
      } break;
   case 149: {
      direct_abstract_declarator();
      get_lexval();
      constant_expression();
      get_lexval();
      } break;
   case 150: {
      get_lexval();
      get_lexval();
      } break;
   case 151: {
      get_lexval();
      parameter_type_list();
      get_lexval();
      } break;
   case 152: {
      direct_abstract_declarator();
      get_lexval();
      get_lexval();
      } break;
   case 153: {
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
   case 154: {
      assignment_expression();
      } break;
   case 155: {
      get_lexval();
      initializer_list();
      get_lexval();
      } break;
   case 156: {
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
   case 157: {
      initializer();
      } break;
   case 158: {
      initializer_list();
      get_lexval();
      initializer();
      } break;
   }
}

statement ()
{
   switch(yyselect()) {
   case 159: {
      labeled_statement();
      } break;
   case 160: {
      compound_statement();
      } break;
   case 161: {
      expression_statement();
      } break;
   case 162: {
      selection_statement();
      } break;
   case 163: {
      iteration_statement();
      } break;
   case 164: {
      jump_statement();
      } break;
   }
}

labeled_statement ()
{
   switch(yyselect()) {
   case 165: {
      get_lexval();
      get_lexval();
      statement();
      } break;
   case 166: {
      get_lexval();
      constant_expression();
      get_lexval();
      statement();
      } break;
   case 167: {
      get_lexval();
      get_lexval();
      statement();
      } break;
   }
}

compound_statement ()
{
   switch(yyselect()) {
   case 168: {
      get_lexval();
      get_lexval();
      } break;
   case 169: {
      get_lexval();
      statement_list();
      get_lexval();
      } break;
   case 170: {
      get_lexval();
      declaration_list();
      get_lexval();
      } break;
   case 171: {
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
   case 172: {
      declaration();
      } break;
   case 173: {
      declaration_list();
      declaration();
      } break;
   }
}

statement_list ()
{
   switch(yyselect()) {
   case 174: {
      statement();
      } break;
   case 175: {
      statement_list();
      statement();
      } break;
   }
}

expression_statement ()
{
   switch(yyselect()) {
   case 176: {
      get_lexval();
      } break;
   case 177: {
      expression();
      get_lexval();
      } break;
   }
}

selection_statement ()
{
   switch(yyselect()) {
   case 178: {
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      statement();
      } break;
   case 179: {
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      statement();
      get_lexval();
      statement();
      } break;
   case 180: {
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
   case 181: {
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      statement();
      } break;
   case 182: {
      get_lexval();
      statement();
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      get_lexval();
      } break;
   case 183: {
      get_lexval();
      get_lexval();
      expression_statement();
      expression_statement();
      get_lexval();
      statement();
      } break;
   case 184: {
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
   case 185: {
      get_lexval();
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
      get_lexval();
      } break;
   case 189: {
      get_lexval();
      expression();
      get_lexval();
      } break;
   }
}

root ()
{
   switch(yyselect()) {
   case 190: {
      external_declaration();
      } break;
   case 191: {
      root();
      external_declaration();
      } break;
   }
}

external_declaration ()
{
   switch(yyselect()) {
   case 192: {
      function_definition();
      } break;
   case 193: {
      declaration();
      } break;
   }
}

function_definition ()
{
   switch(yyselect()) {
   case 194: {
      declaration_specifiers();
      declarator();
      declaration_list();
      compound_statement();
      } break;
   case 195: {
      declaration_specifiers();
      declarator();
      compound_statement();
      } break;
   case 196: {
      declarator();
      declaration_list();
      compound_statement();
      } break;
   case 197: {
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
int c_length = 1021;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 198,
/* 6 */ 10,
/* 7 */ 990,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 0,
/* 11 */ 6,
/* 12 */ 990,
/* 13 */ -6,
/* 14 */ 2,
/* 15 */ 19,
/* 16 */ 50298,
/* 17 */ -15,
/* 18 */ 3,
/* 19 */ 23,
/* 20 */ 50288,
/* 21 */ -15,
/* 22 */ 4,
/* 23 */ 27,
/* 24 */ 50289,
/* 25 */ -15,
/* 26 */ 5,
/* 27 */ 0,
/* 28 */ 50040,
/* 29 */ 295,
/* 30 */ 50041,
/* 31 */ -15,
/* 32 */ 6,
/* 33 */ 37,
/* 34 */ 15,
/* 35 */ -33,
/* 36 */ 7,
/* 37 */ 44,
/* 38 */ 33,
/* 39 */ 50091,
/* 40 */ 295,
/* 41 */ 50093,
/* 42 */ -33,
/* 43 */ 8,
/* 44 */ 50,
/* 45 */ 33,
/* 46 */ 50040,
/* 47 */ 50041,
/* 48 */ -33,
/* 49 */ 9,
/* 50 */ 57,
/* 51 */ 33,
/* 52 */ 50040,
/* 53 */ 79,
/* 54 */ 50041,
/* 55 */ -33,
/* 56 */ 10,
/* 57 */ 63,
/* 58 */ 33,
/* 59 */ 50046,
/* 60 */ 50298,
/* 61 */ -33,
/* 62 */ 11,
/* 63 */ 69,
/* 64 */ 33,
/* 65 */ 50296,
/* 66 */ 50298,
/* 67 */ -33,
/* 68 */ 12,
/* 69 */ 74,
/* 70 */ 33,
/* 71 */ 50294,
/* 72 */ -33,
/* 73 */ 13,
/* 74 */ 0,
/* 75 */ 33,
/* 76 */ 50295,
/* 77 */ -33,
/* 78 */ 14,
/* 79 */ 83,
/* 80 */ 285,
/* 81 */ -79,
/* 82 */ 15,
/* 83 */ 0,
/* 84 */ 79,
/* 85 */ 50044,
/* 86 */ 285,
/* 87 */ -79,
/* 88 */ 16,
/* 89 */ 93,
/* 90 */ 33,
/* 91 */ -89,
/* 92 */ 17,
/* 93 */ 98,
/* 94 */ 50294,
/* 95 */ 89,
/* 96 */ -89,
/* 97 */ 18,
/* 98 */ 103,
/* 99 */ 50295,
/* 100 */ 89,
/* 101 */ -89,
/* 102 */ 19,
/* 103 */ 108,
/* 104 */ 120,
/* 105 */ 144,
/* 106 */ -89,
/* 107 */ 20,
/* 108 */ 113,
/* 109 */ 50278,
/* 110 */ 89,
/* 111 */ -89,
/* 112 */ 21,
/* 113 */ 0,
/* 114 */ 50278,
/* 115 */ 50040,
/* 116 */ 694,
/* 117 */ 50041,
/* 118 */ -89,
/* 119 */ 22,
/* 120 */ 124,
/* 121 */ 50038,
/* 122 */ -120,
/* 123 */ 23,
/* 124 */ 128,
/* 125 */ 50042,
/* 126 */ -120,
/* 127 */ 24,
/* 128 */ 132,
/* 129 */ 50043,
/* 130 */ -120,
/* 131 */ 25,
/* 132 */ 136,
/* 133 */ 50045,
/* 134 */ -120,
/* 135 */ 26,
/* 136 */ 140,
/* 137 */ 50126,
/* 138 */ -120,
/* 139 */ 27,
/* 140 */ 0,
/* 141 */ 50033,
/* 142 */ -120,
/* 143 */ 28,
/* 144 */ 148,
/* 145 */ 89,
/* 146 */ -144,
/* 147 */ 29,
/* 148 */ 0,
/* 149 */ 50040,
/* 150 */ 694,
/* 151 */ 50041,
/* 152 */ 144,
/* 153 */ -144,
/* 154 */ 30,
/* 155 */ 159,
/* 156 */ 144,
/* 157 */ -155,
/* 158 */ 31,
/* 159 */ 165,
/* 160 */ 155,
/* 161 */ 50042,
/* 162 */ 144,
/* 163 */ -155,
/* 164 */ 32,
/* 165 */ 171,
/* 166 */ 155,
/* 167 */ 50047,
/* 168 */ 144,
/* 169 */ -155,
/* 170 */ 33,
/* 171 */ 0,
/* 172 */ 155,
/* 173 */ 50037,
/* 174 */ 144,
/* 175 */ -155,
/* 176 */ 34,
/* 177 */ 181,
/* 178 */ 155,
/* 179 */ -177,
/* 180 */ 35,
/* 181 */ 187,
/* 182 */ 177,
/* 183 */ 50043,
/* 184 */ 155,
/* 185 */ -177,
/* 186 */ 36,
/* 187 */ 0,
/* 188 */ 177,
/* 189 */ 50045,
/* 190 */ 155,
/* 191 */ -177,
/* 192 */ 37,
/* 193 */ 197,
/* 194 */ 177,
/* 195 */ -193,
/* 196 */ 38,
/* 197 */ 0,
/* 198 */ 193,
/* 199 */ 50293,
/* 200 */ 177,
/* 201 */ -193,
/* 202 */ 39,
/* 203 */ 207,
/* 204 */ 193,
/* 205 */ -203,
/* 206 */ 40,
/* 207 */ 0,
/* 208 */ 203,
/* 209 */ 50292,
/* 210 */ 193,
/* 211 */ -203,
/* 212 */ 41,
/* 213 */ 217,
/* 214 */ 203,
/* 215 */ -213,
/* 216 */ 42,
/* 217 */ 0,
/* 218 */ 213,
/* 219 */ 50292,
/* 220 */ 203,
/* 221 */ -213,
/* 222 */ 43,
/* 223 */ 227,
/* 224 */ 213,
/* 225 */ -223,
/* 226 */ 44,
/* 227 */ 0,
/* 228 */ 223,
/* 229 */ 50038,
/* 230 */ 213,
/* 231 */ -223,
/* 232 */ 45,
/* 233 */ 237,
/* 234 */ 223,
/* 235 */ -233,
/* 236 */ 46,
/* 237 */ 0,
/* 238 */ 233,
/* 239 */ 50094,
/* 240 */ 223,
/* 241 */ -233,
/* 242 */ 47,
/* 243 */ 247,
/* 244 */ 233,
/* 245 */ -243,
/* 246 */ 48,
/* 247 */ 0,
/* 248 */ 243,
/* 249 */ 50124,
/* 250 */ 233,
/* 251 */ -243,
/* 252 */ 49,
/* 253 */ 257,
/* 254 */ 243,
/* 255 */ -253,
/* 256 */ 50,
/* 257 */ 0,
/* 258 */ 253,
/* 259 */ 50297,
/* 260 */ 243,
/* 261 */ -253,
/* 262 */ 51,
/* 263 */ 267,
/* 264 */ 253,
/* 265 */ -263,
/* 266 */ 52,
/* 267 */ 0,
/* 268 */ 263,
/* 269 */ 50297,
/* 270 */ 253,
/* 271 */ -263,
/* 272 */ 53,
/* 273 */ 277,
/* 274 */ 263,
/* 275 */ -273,
/* 276 */ 54,
/* 277 */ 0,
/* 278 */ 263,
/* 279 */ 50063,
/* 280 */ 295,
/* 281 */ 50058,
/* 282 */ 273,
/* 283 */ -273,
/* 284 */ 55,
/* 285 */ 289,
/* 286 */ 273,
/* 287 */ -285,
/* 288 */ 56,
/* 289 */ 0,
/* 290 */ 89,
/* 291 */ 50291,
/* 292 */ 285,
/* 293 */ -285,
/* 294 */ 57,
/* 295 */ 299,
/* 296 */ 285,
/* 297 */ -295,
/* 298 */ 58,
/* 299 */ 0,
/* 300 */ 295,
/* 301 */ 50044,
/* 302 */ 285,
/* 303 */ -295,
/* 304 */ 59,
/* 305 */ 0,
/* 306 */ 273,
/* 307 */ -305,
/* 308 */ 60,
/* 309 */ 314,
/* 310 */ 320,
/* 311 */ 50059,
/* 312 */ -309,
/* 313 */ 61,
/* 314 */ 0,
/* 315 */ 320,
/* 316 */ 347,
/* 317 */ 50059,
/* 318 */ -309,
/* 319 */ 62,
/* 320 */ 324,
/* 321 */ 367,
/* 322 */ -320,
/* 323 */ 63,
/* 324 */ 329,
/* 325 */ 367,
/* 326 */ 320,
/* 327 */ -320,
/* 328 */ 64,
/* 329 */ 333,
/* 330 */ 387,
/* 331 */ -320,
/* 332 */ 65,
/* 333 */ 338,
/* 334 */ 387,
/* 335 */ 320,
/* 336 */ -320,
/* 337 */ 66,
/* 338 */ 342,
/* 339 */ 561,
/* 340 */ -320,
/* 341 */ 67,
/* 342 */ 0,
/* 343 */ 561,
/* 344 */ 320,
/* 345 */ -320,
/* 346 */ 68,
/* 347 */ 351,
/* 348 */ 357,
/* 349 */ -347,
/* 350 */ 69,
/* 351 */ 0,
/* 352 */ 347,
/* 353 */ 50044,
/* 354 */ 357,
/* 355 */ -347,
/* 356 */ 70,
/* 357 */ 361,
/* 358 */ 569,
/* 359 */ -357,
/* 360 */ 71,
/* 361 */ 0,
/* 362 */ 569,
/* 363 */ 50061,
/* 364 */ 770,
/* 365 */ -357,
/* 366 */ 72,
/* 367 */ 371,
/* 368 */ 50282,
/* 369 */ -367,
/* 370 */ 73,
/* 371 */ 375,
/* 372 */ 50267,
/* 373 */ -367,
/* 374 */ 74,
/* 375 */ 379,
/* 376 */ 50279,
/* 377 */ -367,
/* 378 */ 75,
/* 379 */ 383,
/* 380 */ 50256,
/* 381 */ -367,
/* 382 */ 76,
/* 383 */ 0,
/* 384 */ 50274,
/* 385 */ -367,
/* 386 */ 77,
/* 387 */ 391,
/* 388 */ 50285,
/* 389 */ -387,
/* 390 */ 78,
/* 391 */ 395,
/* 392 */ 50259,
/* 393 */ -387,
/* 394 */ 79,
/* 395 */ 399,
/* 396 */ 50276,
/* 397 */ -387,
/* 398 */ 80,
/* 399 */ 403,
/* 400 */ 50272,
/* 401 */ -387,
/* 402 */ 81,
/* 403 */ 407,
/* 404 */ 50273,
/* 405 */ -387,
/* 406 */ 82,
/* 407 */ 411,
/* 408 */ 50268,
/* 409 */ -387,
/* 410 */ 83,
/* 411 */ 415,
/* 412 */ 50264,
/* 413 */ -387,
/* 414 */ 84,
/* 415 */ 419,
/* 416 */ 50277,
/* 417 */ -387,
/* 418 */ 85,
/* 419 */ 423,
/* 420 */ 50284,
/* 421 */ -387,
/* 422 */ 86,
/* 423 */ 427,
/* 424 */ 435,
/* 425 */ -387,
/* 426 */ 87,
/* 427 */ 431,
/* 428 */ 521,
/* 429 */ -387,
/* 430 */ 88,
/* 431 */ 0,
/* 432 */ 50298,
/* 433 */ -387,
/* 434 */ 89,
/* 435 */ 443,
/* 436 */ 455,
/* 437 */ 50298,
/* 438 */ 50123,
/* 439 */ 463,
/* 440 */ 50125,
/* 441 */ -435,
/* 442 */ 90,
/* 443 */ 450,
/* 444 */ 455,
/* 445 */ 50123,
/* 446 */ 463,
/* 447 */ 50125,
/* 448 */ -435,
/* 449 */ 91,
/* 450 */ 0,
/* 451 */ 455,
/* 452 */ 50298,
/* 453 */ -435,
/* 454 */ 92,
/* 455 */ 459,
/* 456 */ 50280,
/* 457 */ -455,
/* 458 */ 93,
/* 459 */ 0,
/* 460 */ 50283,
/* 461 */ -455,
/* 462 */ 94,
/* 463 */ 467,
/* 464 */ 472,
/* 465 */ -463,
/* 466 */ 95,
/* 467 */ 0,
/* 468 */ 463,
/* 469 */ 472,
/* 470 */ -463,
/* 471 */ 96,
/* 472 */ 0,
/* 473 */ 478,
/* 474 */ 496,
/* 475 */ 50059,
/* 476 */ -472,
/* 477 */ 97,
/* 478 */ 483,
/* 479 */ 387,
/* 480 */ 478,
/* 481 */ -478,
/* 482 */ 98,
/* 483 */ 487,
/* 484 */ 387,
/* 485 */ -478,
/* 486 */ 99,
/* 487 */ 492,
/* 488 */ 561,
/* 489 */ 478,
/* 490 */ -478,
/* 491 */ 100,
/* 492 */ 0,
/* 493 */ 561,
/* 494 */ -478,
/* 495 */ 101,
/* 496 */ 500,
/* 497 */ 506,
/* 498 */ -496,
/* 499 */ 102,
/* 500 */ 0,
/* 501 */ 496,
/* 502 */ 50044,
/* 503 */ 506,
/* 504 */ -496,
/* 505 */ 103,
/* 506 */ 510,
/* 507 */ 569,
/* 508 */ -506,
/* 509 */ 104,
/* 510 */ 515,
/* 511 */ 50058,
/* 512 */ 305,
/* 513 */ -506,
/* 514 */ 105,
/* 515 */ 0,
/* 516 */ 569,
/* 517 */ 50058,
/* 518 */ 305,
/* 519 */ -506,
/* 520 */ 106,
/* 521 */ 528,
/* 522 */ 50266,
/* 523 */ 50123,
/* 524 */ 541,
/* 525 */ 50125,
/* 526 */ -521,
/* 527 */ 107,
/* 528 */ 536,
/* 529 */ 50266,
/* 530 */ 50298,
/* 531 */ 50123,
/* 532 */ 541,
/* 533 */ 50125,
/* 534 */ -521,
/* 535 */ 108,
/* 536 */ 0,
/* 537 */ 50266,
/* 538 */ 50298,
/* 539 */ -521,
/* 540 */ 109,
/* 541 */ 545,
/* 542 */ 551,
/* 543 */ -541,
/* 544 */ 110,
/* 545 */ 0,
/* 546 */ 541,
/* 547 */ 50044,
/* 548 */ 551,
/* 549 */ -541,
/* 550 */ 111,
/* 551 */ 555,
/* 552 */ 50298,
/* 553 */ -551,
/* 554 */ 112,
/* 555 */ 0,
/* 556 */ 50298,
/* 557 */ 50061,
/* 558 */ 305,
/* 559 */ -551,
/* 560 */ 113,
/* 561 */ 565,
/* 562 */ 50260,
/* 563 */ -561,
/* 564 */ 114,
/* 565 */ 0,
/* 566 */ 50286,
/* 567 */ -561,
/* 568 */ 115,
/* 569 */ 574,
/* 570 */ 621,
/* 571 */ 578,
/* 572 */ -569,
/* 573 */ 116,
/* 574 */ 0,
/* 575 */ 578,
/* 576 */ -569,
/* 577 */ 117,
/* 578 */ 582,
/* 579 */ 50298,
/* 580 */ -578,
/* 581 */ 118,
/* 582 */ 588,
/* 583 */ 50040,
/* 584 */ 569,
/* 585 */ 50041,
/* 586 */ -578,
/* 587 */ 119,
/* 588 */ 595,
/* 589 */ 578,
/* 590 */ 50091,
/* 591 */ 305,
/* 592 */ 50093,
/* 593 */ -578,
/* 594 */ 120,
/* 595 */ 601,
/* 596 */ 578,
/* 597 */ 50091,
/* 598 */ 50093,
/* 599 */ -578,
/* 600 */ 121,
/* 601 */ 608,
/* 602 */ 578,
/* 603 */ 50040,
/* 604 */ 650,
/* 605 */ 50041,
/* 606 */ -578,
/* 607 */ 122,
/* 608 */ 615,
/* 609 */ 578,
/* 610 */ 50040,
/* 611 */ 684,
/* 612 */ 50041,
/* 613 */ -578,
/* 614 */ 123,
/* 615 */ 0,
/* 616 */ 578,
/* 617 */ 50040,
/* 618 */ 50041,
/* 619 */ -578,
/* 620 */ 124,
/* 621 */ 625,
/* 622 */ 50042,
/* 623 */ -621,
/* 624 */ 125,
/* 625 */ 630,
/* 626 */ 50042,
/* 627 */ 641,
/* 628 */ -621,
/* 629 */ 126,
/* 630 */ 635,
/* 631 */ 50042,
/* 632 */ 621,
/* 633 */ -621,
/* 634 */ 127,
/* 635 */ 0,
/* 636 */ 50042,
/* 637 */ 641,
/* 638 */ 621,
/* 639 */ -621,
/* 640 */ 128,
/* 641 */ 645,
/* 642 */ 561,
/* 643 */ -641,
/* 644 */ 129,
/* 645 */ 0,
/* 646 */ 641,
/* 647 */ 561,
/* 648 */ -641,
/* 649 */ 130,
/* 650 */ 654,
/* 651 */ 660,
/* 652 */ -650,
/* 653 */ 131,
/* 654 */ 0,
/* 655 */ 660,
/* 656 */ 50044,
/* 657 */ 50290,
/* 658 */ -650,
/* 659 */ 132,
/* 660 */ 664,
/* 661 */ 670,
/* 662 */ -660,
/* 663 */ 133,
/* 664 */ 0,
/* 665 */ 660,
/* 666 */ 50044,
/* 667 */ 670,
/* 668 */ -660,
/* 669 */ 134,
/* 670 */ 675,
/* 671 */ 320,
/* 672 */ 569,
/* 673 */ -670,
/* 674 */ 135,
/* 675 */ 680,
/* 676 */ 320,
/* 677 */ 703,
/* 678 */ -670,
/* 679 */ 136,
/* 680 */ 0,
/* 681 */ 320,
/* 682 */ -670,
/* 683 */ 137,
/* 684 */ 688,
/* 685 */ 50298,
/* 686 */ -684,
/* 687 */ 138,
/* 688 */ 0,
/* 689 */ 684,
/* 690 */ 50044,
/* 691 */ 50298,
/* 692 */ -684,
/* 693 */ 139,
/* 694 */ 698,
/* 695 */ 478,
/* 696 */ -694,
/* 697 */ 140,
/* 698 */ 0,
/* 699 */ 478,
/* 700 */ 703,
/* 701 */ -694,
/* 702 */ 141,
/* 703 */ 707,
/* 704 */ 621,
/* 705 */ -703,
/* 706 */ 142,
/* 707 */ 711,
/* 708 */ 716,
/* 709 */ -703,
/* 710 */ 143,
/* 711 */ 0,
/* 712 */ 621,
/* 713 */ 716,
/* 714 */ -703,
/* 715 */ 144,
/* 716 */ 722,
/* 717 */ 50040,
/* 718 */ 703,
/* 719 */ 50041,
/* 720 */ -716,
/* 721 */ 145,
/* 722 */ 727,
/* 723 */ 50091,
/* 724 */ 50093,
/* 725 */ -716,
/* 726 */ 146,
/* 727 */ 733,
/* 728 */ 50091,
/* 729 */ 305,
/* 730 */ 50093,
/* 731 */ -716,
/* 732 */ 147,
/* 733 */ 739,
/* 734 */ 716,
/* 735 */ 50091,
/* 736 */ 50093,
/* 737 */ -716,
/* 738 */ 148,
/* 739 */ 746,
/* 740 */ 716,
/* 741 */ 50091,
/* 742 */ 305,
/* 743 */ 50093,
/* 744 */ -716,
/* 745 */ 149,
/* 746 */ 751,
/* 747 */ 50040,
/* 748 */ 50041,
/* 749 */ -716,
/* 750 */ 150,
/* 751 */ 757,
/* 752 */ 50040,
/* 753 */ 650,
/* 754 */ 50041,
/* 755 */ -716,
/* 756 */ 151,
/* 757 */ 763,
/* 758 */ 716,
/* 759 */ 50040,
/* 760 */ 50041,
/* 761 */ -716,
/* 762 */ 152,
/* 763 */ 0,
/* 764 */ 716,
/* 765 */ 50040,
/* 766 */ 650,
/* 767 */ 50041,
/* 768 */ -716,
/* 769 */ 153,
/* 770 */ 774,
/* 771 */ 285,
/* 772 */ -770,
/* 773 */ 154,
/* 774 */ 780,
/* 775 */ 50123,
/* 776 */ 787,
/* 777 */ 50125,
/* 778 */ -770,
/* 779 */ 155,
/* 780 */ 0,
/* 781 */ 50123,
/* 782 */ 787,
/* 783 */ 50044,
/* 784 */ 50125,
/* 785 */ -770,
/* 786 */ 156,
/* 787 */ 791,
/* 788 */ 770,
/* 789 */ -787,
/* 790 */ 157,
/* 791 */ 0,
/* 792 */ 787,
/* 793 */ 50044,
/* 794 */ 770,
/* 795 */ -787,
/* 796 */ 158,
/* 797 */ 801,
/* 798 */ 821,
/* 799 */ -797,
/* 800 */ 159,
/* 801 */ 805,
/* 802 */ 840,
/* 803 */ -797,
/* 804 */ 160,
/* 805 */ 809,
/* 806 */ 882,
/* 807 */ -797,
/* 808 */ 161,
/* 809 */ 813,
/* 810 */ 891,
/* 811 */ -797,
/* 812 */ 162,
/* 813 */ 817,
/* 814 */ 917,
/* 815 */ -797,
/* 816 */ 163,
/* 817 */ 0,
/* 818 */ 954,
/* 819 */ -797,
/* 820 */ 164,
/* 821 */ 827,
/* 822 */ 50298,
/* 823 */ 50058,
/* 824 */ 797,
/* 825 */ -821,
/* 826 */ 165,
/* 827 */ 834,
/* 828 */ 50258,
/* 829 */ 305,
/* 830 */ 50058,
/* 831 */ 797,
/* 832 */ -821,
/* 833 */ 166,
/* 834 */ 0,
/* 835 */ 50262,
/* 836 */ 50058,
/* 837 */ 797,
/* 838 */ -821,
/* 839 */ 167,
/* 840 */ 845,
/* 841 */ 50123,
/* 842 */ 50125,
/* 843 */ -840,
/* 844 */ 168,
/* 845 */ 851,
/* 846 */ 50123,
/* 847 */ 873,
/* 848 */ 50125,
/* 849 */ -840,
/* 850 */ 169,
/* 851 */ 857,
/* 852 */ 50123,
/* 853 */ 864,
/* 854 */ 50125,
/* 855 */ -840,
/* 856 */ 170,
/* 857 */ 0,
/* 858 */ 50123,
/* 859 */ 864,
/* 860 */ 873,
/* 861 */ 50125,
/* 862 */ -840,
/* 863 */ 171,
/* 864 */ 868,
/* 865 */ 309,
/* 866 */ -864,
/* 867 */ 172,
/* 868 */ 0,
/* 869 */ 864,
/* 870 */ 309,
/* 871 */ -864,
/* 872 */ 173,
/* 873 */ 877,
/* 874 */ 797,
/* 875 */ -873,
/* 876 */ 174,
/* 877 */ 0,
/* 878 */ 873,
/* 879 */ 797,
/* 880 */ -873,
/* 881 */ 175,
/* 882 */ 886,
/* 883 */ 50059,
/* 884 */ -882,
/* 885 */ 176,
/* 886 */ 0,
/* 887 */ 295,
/* 888 */ 50059,
/* 889 */ -882,
/* 890 */ 177,
/* 891 */ 899,
/* 892 */ 50271,
/* 893 */ 50040,
/* 894 */ 295,
/* 895 */ 50041,
/* 896 */ 797,
/* 897 */ -891,
/* 898 */ 178,
/* 899 */ 909,
/* 900 */ 50271,
/* 901 */ 50040,
/* 902 */ 295,
/* 903 */ 50041,
/* 904 */ 797,
/* 905 */ 50265,
/* 906 */ 797,
/* 907 */ -891,
/* 908 */ 179,
/* 909 */ 0,
/* 910 */ 50281,
/* 911 */ 50040,
/* 912 */ 295,
/* 913 */ 50041,
/* 914 */ 797,
/* 915 */ -891,
/* 916 */ 180,
/* 917 */ 925,
/* 918 */ 50287,
/* 919 */ 50040,
/* 920 */ 295,
/* 921 */ 50041,
/* 922 */ 797,
/* 923 */ -917,
/* 924 */ 181,
/* 925 */ 935,
/* 926 */ 50263,
/* 927 */ 797,
/* 928 */ 50287,
/* 929 */ 50040,
/* 930 */ 295,
/* 931 */ 50041,
/* 932 */ 50059,
/* 933 */ -917,
/* 934 */ 182,
/* 935 */ 944,
/* 936 */ 50269,
/* 937 */ 50040,
/* 938 */ 882,
/* 939 */ 882,
/* 940 */ 50041,
/* 941 */ 797,
/* 942 */ -917,
/* 943 */ 183,
/* 944 */ 0,
/* 945 */ 50269,
/* 946 */ 50040,
/* 947 */ 882,
/* 948 */ 882,
/* 949 */ 295,
/* 950 */ 50041,
/* 951 */ 797,
/* 952 */ -917,
/* 953 */ 184,
/* 954 */ 960,
/* 955 */ 50270,
/* 956 */ 50298,
/* 957 */ 50059,
/* 958 */ -954,
/* 959 */ 185,
/* 960 */ 965,
/* 961 */ 50261,
/* 962 */ 50059,
/* 963 */ -954,
/* 964 */ 186,
/* 965 */ 970,
/* 966 */ 50257,
/* 967 */ 50059,
/* 968 */ -954,
/* 969 */ 187,
/* 970 */ 975,
/* 971 */ 50275,
/* 972 */ 50059,
/* 973 */ -954,
/* 974 */ 188,
/* 975 */ 0,
/* 976 */ 50275,
/* 977 */ 295,
/* 978 */ 50059,
/* 979 */ -954,
/* 980 */ 189,
/* 981 */ 985,
/* 982 */ 990,
/* 983 */ -981,
/* 984 */ 190,
/* 985 */ 0,
/* 986 */ 981,
/* 987 */ 990,
/* 988 */ -981,
/* 989 */ 191,
/* 990 */ 994,
/* 991 */ 998,
/* 992 */ -990,
/* 993 */ 192,
/* 994 */ 0,
/* 995 */ 309,
/* 996 */ -990,
/* 997 */ 193,
/* 998 */ 1005,
/* 999 */ 320,
/* 1000 */ 569,
/* 1001 */ 864,
/* 1002 */ 840,
/* 1003 */ -998,
/* 1004 */ 194,
/* 1005 */ 1011,
/* 1006 */ 320,
/* 1007 */ 569,
/* 1008 */ 840,
/* 1009 */ -998,
/* 1010 */ 195,
/* 1011 */ 1017,
/* 1012 */ 569,
/* 1013 */ 864,
/* 1014 */ 840,
/* 1015 */ -998,
/* 1016 */ 196,
/* 1017 */ 0,
/* 1018 */ 569,
/* 1019 */ 840,
/* 1020 */ -998,
/* 1021 */ 197,
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
/* 16 */ 50298,
/* 17 */ -15,
/* 18 */ 1,
/* 19 */ 23,
/* 20 */ 50288,
/* 21 */ -15,
/* 22 */ 2,
/* 23 */ 27,
/* 24 */ 50289,
/* 25 */ -15,
/* 26 */ 3,
/* 27 */ 0,
/* 28 */ 50040,
/* 29 */ 1,
/* 30 */ 50041,
/* 31 */ -15,
/* 32 */ 4,
/* 33 */ 37,
/* 34 */ 1,
/* 35 */ -33,
/* 36 */ 1,
/* 37 */ 44,
/* 38 */ 1,
/* 39 */ 50091,
/* 40 */ 1,
/* 41 */ 50093,
/* 42 */ -33,
/* 43 */ 2,
/* 44 */ 50,
/* 45 */ 1,
/* 46 */ 50040,
/* 47 */ 50041,
/* 48 */ -33,
/* 49 */ 3,
/* 50 */ 57,
/* 51 */ 1,
/* 52 */ 50040,
/* 53 */ 1,
/* 54 */ 50041,
/* 55 */ -33,
/* 56 */ 4,
/* 57 */ 63,
/* 58 */ 1,
/* 59 */ 50046,
/* 60 */ 50298,
/* 61 */ -33,
/* 62 */ 5,
/* 63 */ 69,
/* 64 */ 1,
/* 65 */ 50296,
/* 66 */ 50298,
/* 67 */ -33,
/* 68 */ 6,
/* 69 */ 74,
/* 70 */ 1,
/* 71 */ 50294,
/* 72 */ -33,
/* 73 */ 7,
/* 74 */ 0,
/* 75 */ 1,
/* 76 */ 50295,
/* 77 */ -33,
/* 78 */ 8,
/* 79 */ 83,
/* 80 */ 1,
/* 81 */ -79,
/* 82 */ 1,
/* 83 */ 0,
/* 84 */ 1,
/* 85 */ 50044,
/* 86 */ 1,
/* 87 */ -79,
/* 88 */ 2,
/* 89 */ 93,
/* 90 */ 1,
/* 91 */ -89,
/* 92 */ 1,
/* 93 */ 98,
/* 94 */ 50294,
/* 95 */ 1,
/* 96 */ -89,
/* 97 */ 2,
/* 98 */ 103,
/* 99 */ 50295,
/* 100 */ 1,
/* 101 */ -89,
/* 102 */ 3,
/* 103 */ 108,
/* 104 */ 1,
/* 105 */ 1,
/* 106 */ -89,
/* 107 */ 4,
/* 108 */ 113,
/* 109 */ 50278,
/* 110 */ 1,
/* 111 */ -89,
/* 112 */ 5,
/* 113 */ 0,
/* 114 */ 50278,
/* 115 */ 50040,
/* 116 */ 1,
/* 117 */ 50041,
/* 118 */ -89,
/* 119 */ 6,
/* 120 */ 124,
/* 121 */ 50038,
/* 122 */ -120,
/* 123 */ 1,
/* 124 */ 128,
/* 125 */ 50042,
/* 126 */ -120,
/* 127 */ 2,
/* 128 */ 132,
/* 129 */ 50043,
/* 130 */ -120,
/* 131 */ 3,
/* 132 */ 136,
/* 133 */ 50045,
/* 134 */ -120,
/* 135 */ 4,
/* 136 */ 140,
/* 137 */ 50126,
/* 138 */ -120,
/* 139 */ 5,
/* 140 */ 0,
/* 141 */ 50033,
/* 142 */ -120,
/* 143 */ 6,
/* 144 */ 148,
/* 145 */ 1,
/* 146 */ -144,
/* 147 */ 1,
/* 148 */ 0,
/* 149 */ 50040,
/* 150 */ 1,
/* 151 */ 50041,
/* 152 */ 1,
/* 153 */ -144,
/* 154 */ 2,
/* 155 */ 159,
/* 156 */ 1,
/* 157 */ -155,
/* 158 */ 1,
/* 159 */ 165,
/* 160 */ 1,
/* 161 */ 50042,
/* 162 */ 1,
/* 163 */ -155,
/* 164 */ 2,
/* 165 */ 171,
/* 166 */ 1,
/* 167 */ 50047,
/* 168 */ 1,
/* 169 */ -155,
/* 170 */ 3,
/* 171 */ 0,
/* 172 */ 1,
/* 173 */ 50037,
/* 174 */ 1,
/* 175 */ -155,
/* 176 */ 4,
/* 177 */ 181,
/* 178 */ 1,
/* 179 */ -177,
/* 180 */ 1,
/* 181 */ 187,
/* 182 */ 1,
/* 183 */ 50043,
/* 184 */ 1,
/* 185 */ -177,
/* 186 */ 2,
/* 187 */ 0,
/* 188 */ 1,
/* 189 */ 50045,
/* 190 */ 1,
/* 191 */ -177,
/* 192 */ 3,
/* 193 */ 197,
/* 194 */ 1,
/* 195 */ -193,
/* 196 */ 1,
/* 197 */ 0,
/* 198 */ 1,
/* 199 */ 50293,
/* 200 */ 1,
/* 201 */ -193,
/* 202 */ 2,
/* 203 */ 207,
/* 204 */ 1,
/* 205 */ -203,
/* 206 */ 1,
/* 207 */ 0,
/* 208 */ 1,
/* 209 */ 50292,
/* 210 */ 1,
/* 211 */ -203,
/* 212 */ 2,
/* 213 */ 217,
/* 214 */ 1,
/* 215 */ -213,
/* 216 */ 1,
/* 217 */ 0,
/* 218 */ 1,
/* 219 */ 50292,
/* 220 */ 1,
/* 221 */ -213,
/* 222 */ 2,
/* 223 */ 227,
/* 224 */ 1,
/* 225 */ -223,
/* 226 */ 1,
/* 227 */ 0,
/* 228 */ 1,
/* 229 */ 50038,
/* 230 */ 1,
/* 231 */ -223,
/* 232 */ 2,
/* 233 */ 237,
/* 234 */ 1,
/* 235 */ -233,
/* 236 */ 1,
/* 237 */ 0,
/* 238 */ 1,
/* 239 */ 50094,
/* 240 */ 1,
/* 241 */ -233,
/* 242 */ 2,
/* 243 */ 247,
/* 244 */ 1,
/* 245 */ -243,
/* 246 */ 1,
/* 247 */ 0,
/* 248 */ 1,
/* 249 */ 50124,
/* 250 */ 1,
/* 251 */ -243,
/* 252 */ 2,
/* 253 */ 257,
/* 254 */ 1,
/* 255 */ -253,
/* 256 */ 1,
/* 257 */ 0,
/* 258 */ 1,
/* 259 */ 50297,
/* 260 */ 1,
/* 261 */ -253,
/* 262 */ 2,
/* 263 */ 267,
/* 264 */ 1,
/* 265 */ -263,
/* 266 */ 1,
/* 267 */ 0,
/* 268 */ 1,
/* 269 */ 50297,
/* 270 */ 1,
/* 271 */ -263,
/* 272 */ 2,
/* 273 */ 277,
/* 274 */ 1,
/* 275 */ -273,
/* 276 */ 1,
/* 277 */ 0,
/* 278 */ 1,
/* 279 */ 50063,
/* 280 */ 1,
/* 281 */ 50058,
/* 282 */ 1,
/* 283 */ -273,
/* 284 */ 2,
/* 285 */ 289,
/* 286 */ 1,
/* 287 */ -285,
/* 288 */ 1,
/* 289 */ 0,
/* 290 */ 1,
/* 291 */ 50291,
/* 292 */ 1,
/* 293 */ -285,
/* 294 */ 2,
/* 295 */ 299,
/* 296 */ 1,
/* 297 */ -295,
/* 298 */ 1,
/* 299 */ 0,
/* 300 */ 1,
/* 301 */ 50044,
/* 302 */ 1,
/* 303 */ -295,
/* 304 */ 2,
/* 305 */ 0,
/* 306 */ 1,
/* 307 */ -305,
/* 308 */ 1,
/* 309 */ 314,
/* 310 */ 1,
/* 311 */ 50059,
/* 312 */ -309,
/* 313 */ 1,
/* 314 */ 0,
/* 315 */ 1,
/* 316 */ 1,
/* 317 */ 50059,
/* 318 */ -309,
/* 319 */ 2,
/* 320 */ 324,
/* 321 */ 1,
/* 322 */ -320,
/* 323 */ 1,
/* 324 */ 329,
/* 325 */ 1,
/* 326 */ 1,
/* 327 */ -320,
/* 328 */ 2,
/* 329 */ 333,
/* 330 */ 1,
/* 331 */ -320,
/* 332 */ 3,
/* 333 */ 338,
/* 334 */ 1,
/* 335 */ 1,
/* 336 */ -320,
/* 337 */ 4,
/* 338 */ 342,
/* 339 */ 1,
/* 340 */ -320,
/* 341 */ 5,
/* 342 */ 0,
/* 343 */ 1,
/* 344 */ 1,
/* 345 */ -320,
/* 346 */ 6,
/* 347 */ 351,
/* 348 */ 1,
/* 349 */ -347,
/* 350 */ 1,
/* 351 */ 0,
/* 352 */ 1,
/* 353 */ 50044,
/* 354 */ 1,
/* 355 */ -347,
/* 356 */ 2,
/* 357 */ 361,
/* 358 */ 1,
/* 359 */ -357,
/* 360 */ 1,
/* 361 */ 0,
/* 362 */ 1,
/* 363 */ 50061,
/* 364 */ 1,
/* 365 */ -357,
/* 366 */ 2,
/* 367 */ 371,
/* 368 */ 50282,
/* 369 */ -367,
/* 370 */ 1,
/* 371 */ 375,
/* 372 */ 50267,
/* 373 */ -367,
/* 374 */ 2,
/* 375 */ 379,
/* 376 */ 50279,
/* 377 */ -367,
/* 378 */ 3,
/* 379 */ 383,
/* 380 */ 50256,
/* 381 */ -367,
/* 382 */ 4,
/* 383 */ 0,
/* 384 */ 50274,
/* 385 */ -367,
/* 386 */ 5,
/* 387 */ 391,
/* 388 */ 50285,
/* 389 */ -387,
/* 390 */ 1,
/* 391 */ 395,
/* 392 */ 50259,
/* 393 */ -387,
/* 394 */ 2,
/* 395 */ 399,
/* 396 */ 50276,
/* 397 */ -387,
/* 398 */ 3,
/* 399 */ 403,
/* 400 */ 50272,
/* 401 */ -387,
/* 402 */ 4,
/* 403 */ 407,
/* 404 */ 50273,
/* 405 */ -387,
/* 406 */ 5,
/* 407 */ 411,
/* 408 */ 50268,
/* 409 */ -387,
/* 410 */ 6,
/* 411 */ 415,
/* 412 */ 50264,
/* 413 */ -387,
/* 414 */ 7,
/* 415 */ 419,
/* 416 */ 50277,
/* 417 */ -387,
/* 418 */ 8,
/* 419 */ 423,
/* 420 */ 50284,
/* 421 */ -387,
/* 422 */ 9,
/* 423 */ 427,
/* 424 */ 1,
/* 425 */ -387,
/* 426 */ 10,
/* 427 */ 431,
/* 428 */ 1,
/* 429 */ -387,
/* 430 */ 11,
/* 431 */ 0,
/* 432 */ 50298,
/* 433 */ -387,
/* 434 */ 12,
/* 435 */ 443,
/* 436 */ 1,
/* 437 */ 50298,
/* 438 */ 50123,
/* 439 */ 1,
/* 440 */ 50125,
/* 441 */ -435,
/* 442 */ 1,
/* 443 */ 450,
/* 444 */ 1,
/* 445 */ 50123,
/* 446 */ 1,
/* 447 */ 50125,
/* 448 */ -435,
/* 449 */ 2,
/* 450 */ 0,
/* 451 */ 1,
/* 452 */ 50298,
/* 453 */ -435,
/* 454 */ 3,
/* 455 */ 459,
/* 456 */ 50280,
/* 457 */ -455,
/* 458 */ 1,
/* 459 */ 0,
/* 460 */ 50283,
/* 461 */ -455,
/* 462 */ 2,
/* 463 */ 467,
/* 464 */ 1,
/* 465 */ -463,
/* 466 */ 1,
/* 467 */ 0,
/* 468 */ 1,
/* 469 */ 1,
/* 470 */ -463,
/* 471 */ 2,
/* 472 */ 0,
/* 473 */ 1,
/* 474 */ 1,
/* 475 */ 50059,
/* 476 */ -472,
/* 477 */ 1,
/* 478 */ 483,
/* 479 */ 1,
/* 480 */ 1,
/* 481 */ -478,
/* 482 */ 1,
/* 483 */ 487,
/* 484 */ 1,
/* 485 */ -478,
/* 486 */ 2,
/* 487 */ 492,
/* 488 */ 1,
/* 489 */ 1,
/* 490 */ -478,
/* 491 */ 3,
/* 492 */ 0,
/* 493 */ 1,
/* 494 */ -478,
/* 495 */ 4,
/* 496 */ 500,
/* 497 */ 1,
/* 498 */ -496,
/* 499 */ 1,
/* 500 */ 0,
/* 501 */ 1,
/* 502 */ 50044,
/* 503 */ 1,
/* 504 */ -496,
/* 505 */ 2,
/* 506 */ 510,
/* 507 */ 1,
/* 508 */ -506,
/* 509 */ 1,
/* 510 */ 515,
/* 511 */ 50058,
/* 512 */ 1,
/* 513 */ -506,
/* 514 */ 2,
/* 515 */ 0,
/* 516 */ 1,
/* 517 */ 50058,
/* 518 */ 1,
/* 519 */ -506,
/* 520 */ 3,
/* 521 */ 528,
/* 522 */ 50266,
/* 523 */ 50123,
/* 524 */ 1,
/* 525 */ 50125,
/* 526 */ -521,
/* 527 */ 1,
/* 528 */ 536,
/* 529 */ 50266,
/* 530 */ 50298,
/* 531 */ 50123,
/* 532 */ 1,
/* 533 */ 50125,
/* 534 */ -521,
/* 535 */ 2,
/* 536 */ 0,
/* 537 */ 50266,
/* 538 */ 50298,
/* 539 */ -521,
/* 540 */ 3,
/* 541 */ 545,
/* 542 */ 1,
/* 543 */ -541,
/* 544 */ 1,
/* 545 */ 0,
/* 546 */ 1,
/* 547 */ 50044,
/* 548 */ 1,
/* 549 */ -541,
/* 550 */ 2,
/* 551 */ 555,
/* 552 */ 50298,
/* 553 */ -551,
/* 554 */ 1,
/* 555 */ 0,
/* 556 */ 50298,
/* 557 */ 50061,
/* 558 */ 1,
/* 559 */ -551,
/* 560 */ 2,
/* 561 */ 565,
/* 562 */ 50260,
/* 563 */ -561,
/* 564 */ 1,
/* 565 */ 0,
/* 566 */ 50286,
/* 567 */ -561,
/* 568 */ 2,
/* 569 */ 574,
/* 570 */ 1,
/* 571 */ 1,
/* 572 */ -569,
/* 573 */ 1,
/* 574 */ 0,
/* 575 */ 1,
/* 576 */ -569,
/* 577 */ 2,
/* 578 */ 582,
/* 579 */ 50298,
/* 580 */ -578,
/* 581 */ 1,
/* 582 */ 588,
/* 583 */ 50040,
/* 584 */ 1,
/* 585 */ 50041,
/* 586 */ -578,
/* 587 */ 2,
/* 588 */ 595,
/* 589 */ 1,
/* 590 */ 50091,
/* 591 */ 1,
/* 592 */ 50093,
/* 593 */ -578,
/* 594 */ 3,
/* 595 */ 601,
/* 596 */ 1,
/* 597 */ 50091,
/* 598 */ 50093,
/* 599 */ -578,
/* 600 */ 4,
/* 601 */ 608,
/* 602 */ 1,
/* 603 */ 50040,
/* 604 */ 1,
/* 605 */ 50041,
/* 606 */ -578,
/* 607 */ 5,
/* 608 */ 615,
/* 609 */ 1,
/* 610 */ 50040,
/* 611 */ 1,
/* 612 */ 50041,
/* 613 */ -578,
/* 614 */ 6,
/* 615 */ 0,
/* 616 */ 1,
/* 617 */ 50040,
/* 618 */ 50041,
/* 619 */ -578,
/* 620 */ 7,
/* 621 */ 625,
/* 622 */ 50042,
/* 623 */ -621,
/* 624 */ 1,
/* 625 */ 630,
/* 626 */ 50042,
/* 627 */ 1,
/* 628 */ -621,
/* 629 */ 2,
/* 630 */ 635,
/* 631 */ 50042,
/* 632 */ 1,
/* 633 */ -621,
/* 634 */ 3,
/* 635 */ 0,
/* 636 */ 50042,
/* 637 */ 1,
/* 638 */ 1,
/* 639 */ -621,
/* 640 */ 4,
/* 641 */ 645,
/* 642 */ 1,
/* 643 */ -641,
/* 644 */ 1,
/* 645 */ 0,
/* 646 */ 1,
/* 647 */ 1,
/* 648 */ -641,
/* 649 */ 2,
/* 650 */ 654,
/* 651 */ 1,
/* 652 */ -650,
/* 653 */ 1,
/* 654 */ 0,
/* 655 */ 1,
/* 656 */ 50044,
/* 657 */ 50290,
/* 658 */ -650,
/* 659 */ 2,
/* 660 */ 664,
/* 661 */ 1,
/* 662 */ -660,
/* 663 */ 1,
/* 664 */ 0,
/* 665 */ 1,
/* 666 */ 50044,
/* 667 */ 1,
/* 668 */ -660,
/* 669 */ 2,
/* 670 */ 675,
/* 671 */ 1,
/* 672 */ 1,
/* 673 */ -670,
/* 674 */ 1,
/* 675 */ 680,
/* 676 */ 1,
/* 677 */ 1,
/* 678 */ -670,
/* 679 */ 2,
/* 680 */ 0,
/* 681 */ 1,
/* 682 */ -670,
/* 683 */ 3,
/* 684 */ 688,
/* 685 */ 50298,
/* 686 */ -684,
/* 687 */ 1,
/* 688 */ 0,
/* 689 */ 1,
/* 690 */ 50044,
/* 691 */ 50298,
/* 692 */ -684,
/* 693 */ 2,
/* 694 */ 698,
/* 695 */ 1,
/* 696 */ -694,
/* 697 */ 1,
/* 698 */ 0,
/* 699 */ 1,
/* 700 */ 1,
/* 701 */ -694,
/* 702 */ 2,
/* 703 */ 707,
/* 704 */ 1,
/* 705 */ -703,
/* 706 */ 1,
/* 707 */ 711,
/* 708 */ 1,
/* 709 */ -703,
/* 710 */ 2,
/* 711 */ 0,
/* 712 */ 1,
/* 713 */ 1,
/* 714 */ -703,
/* 715 */ 3,
/* 716 */ 722,
/* 717 */ 50040,
/* 718 */ 1,
/* 719 */ 50041,
/* 720 */ -716,
/* 721 */ 1,
/* 722 */ 727,
/* 723 */ 50091,
/* 724 */ 50093,
/* 725 */ -716,
/* 726 */ 2,
/* 727 */ 733,
/* 728 */ 50091,
/* 729 */ 1,
/* 730 */ 50093,
/* 731 */ -716,
/* 732 */ 3,
/* 733 */ 739,
/* 734 */ 1,
/* 735 */ 50091,
/* 736 */ 50093,
/* 737 */ -716,
/* 738 */ 4,
/* 739 */ 746,
/* 740 */ 1,
/* 741 */ 50091,
/* 742 */ 1,
/* 743 */ 50093,
/* 744 */ -716,
/* 745 */ 5,
/* 746 */ 751,
/* 747 */ 50040,
/* 748 */ 50041,
/* 749 */ -716,
/* 750 */ 6,
/* 751 */ 757,
/* 752 */ 50040,
/* 753 */ 1,
/* 754 */ 50041,
/* 755 */ -716,
/* 756 */ 7,
/* 757 */ 763,
/* 758 */ 1,
/* 759 */ 50040,
/* 760 */ 50041,
/* 761 */ -716,
/* 762 */ 8,
/* 763 */ 0,
/* 764 */ 1,
/* 765 */ 50040,
/* 766 */ 1,
/* 767 */ 50041,
/* 768 */ -716,
/* 769 */ 9,
/* 770 */ 774,
/* 771 */ 1,
/* 772 */ -770,
/* 773 */ 1,
/* 774 */ 780,
/* 775 */ 50123,
/* 776 */ 1,
/* 777 */ 50125,
/* 778 */ -770,
/* 779 */ 2,
/* 780 */ 0,
/* 781 */ 50123,
/* 782 */ 1,
/* 783 */ 50044,
/* 784 */ 50125,
/* 785 */ -770,
/* 786 */ 3,
/* 787 */ 791,
/* 788 */ 1,
/* 789 */ -787,
/* 790 */ 1,
/* 791 */ 0,
/* 792 */ 1,
/* 793 */ 50044,
/* 794 */ 1,
/* 795 */ -787,
/* 796 */ 2,
/* 797 */ 801,
/* 798 */ 1,
/* 799 */ -797,
/* 800 */ 1,
/* 801 */ 805,
/* 802 */ 1,
/* 803 */ -797,
/* 804 */ 2,
/* 805 */ 809,
/* 806 */ 1,
/* 807 */ -797,
/* 808 */ 3,
/* 809 */ 813,
/* 810 */ 1,
/* 811 */ -797,
/* 812 */ 4,
/* 813 */ 817,
/* 814 */ 1,
/* 815 */ -797,
/* 816 */ 5,
/* 817 */ 0,
/* 818 */ 1,
/* 819 */ -797,
/* 820 */ 6,
/* 821 */ 827,
/* 822 */ 50298,
/* 823 */ 50058,
/* 824 */ 1,
/* 825 */ -821,
/* 826 */ 1,
/* 827 */ 834,
/* 828 */ 50258,
/* 829 */ 1,
/* 830 */ 50058,
/* 831 */ 1,
/* 832 */ -821,
/* 833 */ 2,
/* 834 */ 0,
/* 835 */ 50262,
/* 836 */ 50058,
/* 837 */ 1,
/* 838 */ -821,
/* 839 */ 3,
/* 840 */ 845,
/* 841 */ 50123,
/* 842 */ 50125,
/* 843 */ -840,
/* 844 */ 1,
/* 845 */ 851,
/* 846 */ 50123,
/* 847 */ 1,
/* 848 */ 50125,
/* 849 */ -840,
/* 850 */ 2,
/* 851 */ 857,
/* 852 */ 50123,
/* 853 */ 1,
/* 854 */ 50125,
/* 855 */ -840,
/* 856 */ 3,
/* 857 */ 0,
/* 858 */ 50123,
/* 859 */ 1,
/* 860 */ 1,
/* 861 */ 50125,
/* 862 */ -840,
/* 863 */ 4,
/* 864 */ 868,
/* 865 */ 1,
/* 866 */ -864,
/* 867 */ 1,
/* 868 */ 0,
/* 869 */ 1,
/* 870 */ 1,
/* 871 */ -864,
/* 872 */ 2,
/* 873 */ 877,
/* 874 */ 1,
/* 875 */ -873,
/* 876 */ 1,
/* 877 */ 0,
/* 878 */ 1,
/* 879 */ 1,
/* 880 */ -873,
/* 881 */ 2,
/* 882 */ 886,
/* 883 */ 50059,
/* 884 */ -882,
/* 885 */ 1,
/* 886 */ 0,
/* 887 */ 1,
/* 888 */ 50059,
/* 889 */ -882,
/* 890 */ 2,
/* 891 */ 899,
/* 892 */ 50271,
/* 893 */ 50040,
/* 894 */ 1,
/* 895 */ 50041,
/* 896 */ 1,
/* 897 */ -891,
/* 898 */ 1,
/* 899 */ 909,
/* 900 */ 50271,
/* 901 */ 50040,
/* 902 */ 1,
/* 903 */ 50041,
/* 904 */ 1,
/* 905 */ 50265,
/* 906 */ 1,
/* 907 */ -891,
/* 908 */ 2,
/* 909 */ 0,
/* 910 */ 50281,
/* 911 */ 50040,
/* 912 */ 1,
/* 913 */ 50041,
/* 914 */ 1,
/* 915 */ -891,
/* 916 */ 3,
/* 917 */ 925,
/* 918 */ 50287,
/* 919 */ 50040,
/* 920 */ 1,
/* 921 */ 50041,
/* 922 */ 1,
/* 923 */ -917,
/* 924 */ 1,
/* 925 */ 935,
/* 926 */ 50263,
/* 927 */ 1,
/* 928 */ 50287,
/* 929 */ 50040,
/* 930 */ 1,
/* 931 */ 50041,
/* 932 */ 50059,
/* 933 */ -917,
/* 934 */ 2,
/* 935 */ 944,
/* 936 */ 50269,
/* 937 */ 50040,
/* 938 */ 1,
/* 939 */ 1,
/* 940 */ 50041,
/* 941 */ 1,
/* 942 */ -917,
/* 943 */ 3,
/* 944 */ 0,
/* 945 */ 50269,
/* 946 */ 50040,
/* 947 */ 1,
/* 948 */ 1,
/* 949 */ 1,
/* 950 */ 50041,
/* 951 */ 1,
/* 952 */ -917,
/* 953 */ 4,
/* 954 */ 960,
/* 955 */ 50270,
/* 956 */ 50298,
/* 957 */ 50059,
/* 958 */ -954,
/* 959 */ 1,
/* 960 */ 965,
/* 961 */ 50261,
/* 962 */ 50059,
/* 963 */ -954,
/* 964 */ 2,
/* 965 */ 970,
/* 966 */ 50257,
/* 967 */ 50059,
/* 968 */ -954,
/* 969 */ 3,
/* 970 */ 975,
/* 971 */ 50275,
/* 972 */ 50059,
/* 973 */ -954,
/* 974 */ 4,
/* 975 */ 0,
/* 976 */ 50275,
/* 977 */ 1,
/* 978 */ 50059,
/* 979 */ -954,
/* 980 */ 5,
/* 981 */ 985,
/* 982 */ 1,
/* 983 */ -981,
/* 984 */ 1,
/* 985 */ 0,
/* 986 */ 1,
/* 987 */ 1,
/* 988 */ -981,
/* 989 */ 2,
/* 990 */ 994,
/* 991 */ 1,
/* 992 */ -990,
/* 993 */ 1,
/* 994 */ 0,
/* 995 */ 1,
/* 996 */ -990,
/* 997 */ 2,
/* 998 */ 1005,
/* 999 */ 1,
/* 1000 */ 1,
/* 1001 */ 1,
/* 1002 */ 1,
/* 1003 */ -998,
/* 1004 */ 1,
/* 1005 */ 1011,
/* 1006 */ 1,
/* 1007 */ 1,
/* 1008 */ 1,
/* 1009 */ -998,
/* 1010 */ 2,
/* 1011 */ 1017,
/* 1012 */ 1,
/* 1013 */ 1,
/* 1014 */ 1,
/* 1015 */ -998,
/* 1016 */ 3,
/* 1017 */ 0,
/* 1018 */ 1,
/* 1019 */ 1,
/* 1020 */ -998,
/* 1021 */ 4,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 23002,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 23002,
/* 6 */ 9999,
/* 7 */ 23004,
/* 8 */ 9999,
/* 9 */ 23023,
/* 10 */ 9999,
/* 11 */ 24004,
/* 12 */ 24021,
/* 13 */ 9999,
/* 14 */ 24019,
/* 15 */ 9999,
/* 16 */ 9999,
/* 17 */ 9999,
/* 18 */ 28013,
/* 19 */ 9999,
/* 20 */ 9999,
/* 21 */ 9999,
/* 22 */ 29011,
/* 23 */ 9999,
/* 24 */ 9999,
/* 25 */ 9999,
/* 26 */ 30017,
/* 27 */ 9999,
/* 28 */ 9999,
/* 29 */ 31008,
/* 30 */ 9999,
/* 31 */ 9999,
/* 32 */ 31004,
/* 33 */ 9999,
/* 34 */ 35004,
/* 35 */ 9999,
/* 36 */ 35021,
/* 37 */ 9999,
/* 38 */ 36004,
/* 39 */ 9999,
/* 40 */ 36027,
/* 41 */ 9999,
/* 42 */ 9999,
/* 43 */ 36021,
/* 44 */ 9999,
/* 45 */ 37004,
/* 46 */ 9999,
/* 47 */ 9999,
/* 48 */ 9999,
/* 49 */ 37021,
/* 50 */ 9999,
/* 51 */ 38004,
/* 52 */ 9999,
/* 53 */ 38027,
/* 54 */ 9999,
/* 55 */ 9999,
/* 56 */ 38021,
/* 57 */ 9999,
/* 58 */ 39004,
/* 59 */ 9999,
/* 60 */ 9999,
/* 61 */ 9999,
/* 62 */ 39021,
/* 63 */ 9999,
/* 64 */ 40004,
/* 65 */ 9999,
/* 66 */ 9999,
/* 67 */ 9999,
/* 68 */ 40021,
/* 69 */ 9999,
/* 70 */ 41004,
/* 71 */ 9999,
/* 72 */ 9999,
/* 73 */ 41021,
/* 74 */ 9999,
/* 75 */ 42004,
/* 76 */ 9999,
/* 77 */ 9999,
/* 78 */ 42021,
/* 79 */ 9999,
/* 80 */ 46004,
/* 81 */ 9999,
/* 82 */ 46024,
/* 83 */ 9999,
/* 84 */ 47004,
/* 85 */ 9999,
/* 86 */ 47033,
/* 87 */ 9999,
/* 88 */ 47027,
/* 89 */ 9999,
/* 90 */ 51004,
/* 91 */ 9999,
/* 92 */ 51021,
/* 93 */ 9999,
/* 94 */ 9999,
/* 95 */ 52011,
/* 96 */ 9999,
/* 97 */ 52009,
/* 98 */ 9999,
/* 99 */ 9999,
/* 100 */ 53011,
/* 101 */ 9999,
/* 102 */ 53009,
/* 103 */ 9999,
/* 104 */ 54004,
/* 105 */ 54019,
/* 106 */ 9999,
/* 107 */ 54017,
/* 108 */ 9999,
/* 109 */ 9999,
/* 110 */ 55011,
/* 111 */ 9999,
/* 112 */ 55009,
/* 113 */ 9999,
/* 114 */ 9999,
/* 115 */ 9999,
/* 116 */ 56015,
/* 117 */ 9999,
/* 118 */ 9999,
/* 119 */ 56009,
/* 120 */ 9999,
/* 121 */ 9999,
/* 122 */ 9999,
/* 123 */ 60004,
/* 124 */ 9999,
/* 125 */ 9999,
/* 126 */ 9999,
/* 127 */ 61004,
/* 128 */ 9999,
/* 129 */ 9999,
/* 130 */ 9999,
/* 131 */ 62004,
/* 132 */ 9999,
/* 133 */ 9999,
/* 134 */ 9999,
/* 135 */ 63004,
/* 136 */ 9999,
/* 137 */ 9999,
/* 138 */ 9999,
/* 139 */ 64004,
/* 140 */ 9999,
/* 141 */ 9999,
/* 142 */ 9999,
/* 143 */ 65004,
/* 144 */ 9999,
/* 145 */ 69004,
/* 146 */ 9999,
/* 147 */ 69019,
/* 148 */ 9999,
/* 149 */ 9999,
/* 150 */ 70008,
/* 151 */ 9999,
/* 152 */ 70022,
/* 153 */ 9999,
/* 154 */ 70004,
/* 155 */ 9999,
/* 156 */ 74004,
/* 157 */ 9999,
/* 158 */ 74018,
/* 159 */ 9999,
/* 160 */ 75004,
/* 161 */ 9999,
/* 162 */ 75034,
/* 163 */ 9999,
/* 164 */ 75028,
/* 165 */ 9999,
/* 166 */ 76004,
/* 167 */ 9999,
/* 168 */ 76034,
/* 169 */ 9999,
/* 170 */ 76028,
/* 171 */ 9999,
/* 172 */ 77004,
/* 173 */ 9999,
/* 174 */ 77034,
/* 175 */ 9999,
/* 176 */ 77028,
/* 177 */ 9999,
/* 178 */ 81004,
/* 179 */ 9999,
/* 180 */ 81028,
/* 181 */ 9999,
/* 182 */ 82004,
/* 183 */ 9999,
/* 184 */ 82028,
/* 185 */ 9999,
/* 186 */ 82022,
/* 187 */ 9999,
/* 188 */ 83004,
/* 189 */ 9999,
/* 190 */ 83028,
/* 191 */ 9999,
/* 192 */ 83022,
/* 193 */ 9999,
/* 194 */ 87004,
/* 195 */ 9999,
/* 196 */ 87022,
/* 197 */ 9999,
/* 198 */ 88004,
/* 199 */ 9999,
/* 200 */ 88029,
/* 201 */ 9999,
/* 202 */ 88019,
/* 203 */ 9999,
/* 204 */ 92004,
/* 205 */ 9999,
/* 206 */ 92019,
/* 207 */ 9999,
/* 208 */ 93004,
/* 209 */ 9999,
/* 210 */ 93034,
/* 211 */ 9999,
/* 212 */ 93024,
/* 213 */ 9999,
/* 214 */ 97004,
/* 215 */ 9999,
/* 216 */ 97024,
/* 217 */ 9999,
/* 218 */ 98004,
/* 219 */ 9999,
/* 220 */ 98032,
/* 221 */ 9999,
/* 222 */ 98022,
/* 223 */ 9999,
/* 224 */ 102004,
/* 225 */ 9999,
/* 226 */ 102022,
/* 227 */ 9999,
/* 228 */ 103004,
/* 229 */ 9999,
/* 230 */ 103023,
/* 231 */ 9999,
/* 232 */ 103017,
/* 233 */ 9999,
/* 234 */ 107004,
/* 235 */ 9999,
/* 236 */ 107017,
/* 237 */ 9999,
/* 238 */ 108004,
/* 239 */ 9999,
/* 240 */ 108032,
/* 241 */ 9999,
/* 242 */ 108026,
/* 243 */ 9999,
/* 244 */ 112004,
/* 245 */ 9999,
/* 246 */ 112026,
/* 247 */ 9999,
/* 248 */ 113004,
/* 249 */ 9999,
/* 250 */ 113032,
/* 251 */ 9999,
/* 252 */ 113026,
/* 253 */ 9999,
/* 254 */ 117004,
/* 255 */ 9999,
/* 256 */ 117026,
/* 257 */ 9999,
/* 258 */ 118004,
/* 259 */ 9999,
/* 260 */ 118036,
/* 261 */ 9999,
/* 262 */ 118025,
/* 263 */ 9999,
/* 264 */ 122004,
/* 265 */ 9999,
/* 266 */ 122025,
/* 267 */ 9999,
/* 268 */ 123004,
/* 269 */ 9999,
/* 270 */ 123035,
/* 271 */ 9999,
/* 272 */ 123024,
/* 273 */ 9999,
/* 274 */ 127004,
/* 275 */ 9999,
/* 276 */ 127024,
/* 277 */ 9999,
/* 278 */ 128004,
/* 279 */ 9999,
/* 280 */ 128030,
/* 281 */ 9999,
/* 282 */ 128045,
/* 283 */ 9999,
/* 284 */ 128024,
/* 285 */ 9999,
/* 286 */ 132004,
/* 287 */ 9999,
/* 288 */ 132025,
/* 289 */ 9999,
/* 290 */ 133004,
/* 291 */ 9999,
/* 292 */ 133028,
/* 293 */ 9999,
/* 294 */ 133019,
/* 295 */ 9999,
/* 296 */ 137004,
/* 297 */ 9999,
/* 298 */ 137024,
/* 299 */ 9999,
/* 300 */ 138004,
/* 301 */ 9999,
/* 302 */ 138019,
/* 303 */ 9999,
/* 304 */ 138013,
/* 305 */ 9999,
/* 306 */ 142004,
/* 307 */ 9999,
/* 308 */ 142025,
/* 309 */ 9999,
/* 310 */ 146004,
/* 311 */ 9999,
/* 312 */ 9999,
/* 313 */ 146025,
/* 314 */ 9999,
/* 315 */ 147004,
/* 316 */ 147027,
/* 317 */ 9999,
/* 318 */ 9999,
/* 319 */ 147025,
/* 320 */ 9999,
/* 321 */ 151004,
/* 322 */ 9999,
/* 323 */ 151026,
/* 324 */ 9999,
/* 325 */ 152004,
/* 326 */ 152028,
/* 327 */ 9999,
/* 328 */ 152026,
/* 329 */ 9999,
/* 330 */ 153004,
/* 331 */ 9999,
/* 332 */ 153017,
/* 333 */ 9999,
/* 334 */ 154004,
/* 335 */ 154019,
/* 336 */ 9999,
/* 337 */ 154017,
/* 338 */ 9999,
/* 339 */ 155004,
/* 340 */ 9999,
/* 341 */ 155017,
/* 342 */ 9999,
/* 343 */ 156004,
/* 344 */ 156019,
/* 345 */ 9999,
/* 346 */ 156017,
/* 347 */ 9999,
/* 348 */ 160004,
/* 349 */ 9999,
/* 350 */ 160018,
/* 351 */ 9999,
/* 352 */ 161004,
/* 353 */ 9999,
/* 354 */ 161029,
/* 355 */ 9999,
/* 356 */ 161023,
/* 357 */ 9999,
/* 358 */ 165004,
/* 359 */ 9999,
/* 360 */ 165013,
/* 361 */ 9999,
/* 362 */ 166004,
/* 363 */ 9999,
/* 364 */ 166019,
/* 365 */ 9999,
/* 366 */ 166013,
/* 367 */ 9999,
/* 368 */ 9999,
/* 369 */ 9999,
/* 370 */ 170010,
/* 371 */ 9999,
/* 372 */ 9999,
/* 373 */ 9999,
/* 374 */ 171009,
/* 375 */ 9999,
/* 376 */ 9999,
/* 377 */ 9999,
/* 378 */ 172009,
/* 379 */ 9999,
/* 380 */ 9999,
/* 381 */ 9999,
/* 382 */ 173007,
/* 383 */ 9999,
/* 384 */ 9999,
/* 385 */ 9999,
/* 386 */ 174011,
/* 387 */ 9999,
/* 388 */ 9999,
/* 389 */ 9999,
/* 390 */ 178007,
/* 391 */ 9999,
/* 392 */ 9999,
/* 393 */ 9999,
/* 394 */ 179007,
/* 395 */ 9999,
/* 396 */ 9999,
/* 397 */ 9999,
/* 398 */ 180008,
/* 399 */ 9999,
/* 400 */ 9999,
/* 401 */ 9999,
/* 402 */ 181006,
/* 403 */ 9999,
/* 404 */ 9999,
/* 405 */ 9999,
/* 406 */ 182007,
/* 407 */ 9999,
/* 408 */ 9999,
/* 409 */ 9999,
/* 410 */ 183008,
/* 411 */ 9999,
/* 412 */ 9999,
/* 413 */ 9999,
/* 414 */ 184009,
/* 415 */ 9999,
/* 416 */ 9999,
/* 417 */ 9999,
/* 418 */ 185009,
/* 419 */ 9999,
/* 420 */ 9999,
/* 421 */ 9999,
/* 422 */ 186011,
/* 423 */ 9999,
/* 424 */ 187004,
/* 425 */ 9999,
/* 426 */ 187028,
/* 427 */ 9999,
/* 428 */ 188004,
/* 429 */ 9999,
/* 430 */ 188017,
/* 431 */ 9999,
/* 432 */ 9999,
/* 433 */ 9999,
/* 434 */ 189013,
/* 435 */ 9999,
/* 436 */ 193004,
/* 437 */ 9999,
/* 438 */ 9999,
/* 439 */ 193035,
/* 440 */ 9999,
/* 441 */ 9999,
/* 442 */ 193018,
/* 443 */ 9999,
/* 444 */ 194004,
/* 445 */ 9999,
/* 446 */ 194024,
/* 447 */ 9999,
/* 448 */ 9999,
/* 449 */ 194018,
/* 450 */ 9999,
/* 451 */ 195004,
/* 452 */ 9999,
/* 453 */ 9999,
/* 454 */ 195018,
/* 455 */ 9999,
/* 456 */ 9999,
/* 457 */ 9999,
/* 458 */ 199009,
/* 459 */ 9999,
/* 460 */ 9999,
/* 461 */ 9999,
/* 462 */ 200008,
/* 463 */ 9999,
/* 464 */ 204004,
/* 465 */ 9999,
/* 466 */ 204021,
/* 467 */ 9999,
/* 468 */ 205004,
/* 469 */ 205028,
/* 470 */ 9999,
/* 471 */ 205026,
/* 472 */ 9999,
/* 473 */ 209004,
/* 474 */ 209029,
/* 475 */ 9999,
/* 476 */ 9999,
/* 477 */ 209027,
/* 478 */ 9999,
/* 479 */ 213004,
/* 480 */ 213019,
/* 481 */ 9999,
/* 482 */ 213017,
/* 483 */ 9999,
/* 484 */ 214004,
/* 485 */ 9999,
/* 486 */ 214017,
/* 487 */ 9999,
/* 488 */ 215004,
/* 489 */ 215019,
/* 490 */ 9999,
/* 491 */ 215017,
/* 492 */ 9999,
/* 493 */ 216004,
/* 494 */ 9999,
/* 495 */ 216017,
/* 496 */ 9999,
/* 497 */ 220004,
/* 498 */ 9999,
/* 499 */ 220020,
/* 500 */ 9999,
/* 501 */ 221004,
/* 502 */ 9999,
/* 503 */ 221031,
/* 504 */ 9999,
/* 505 */ 221025,
/* 506 */ 9999,
/* 507 */ 225004,
/* 508 */ 9999,
/* 509 */ 225013,
/* 510 */ 9999,
/* 511 */ 9999,
/* 512 */ 226008,
/* 513 */ 9999,
/* 514 */ 226004,
/* 515 */ 9999,
/* 516 */ 227004,
/* 517 */ 9999,
/* 518 */ 227019,
/* 519 */ 9999,
/* 520 */ 227013,
/* 521 */ 9999,
/* 522 */ 9999,
/* 523 */ 9999,
/* 524 */ 231013,
/* 525 */ 9999,
/* 526 */ 9999,
/* 527 */ 231007,
/* 528 */ 9999,
/* 529 */ 9999,
/* 530 */ 9999,
/* 531 */ 9999,
/* 532 */ 232024,
/* 533 */ 9999,
/* 534 */ 9999,
/* 535 */ 232007,
/* 536 */ 9999,
/* 537 */ 9999,
/* 538 */ 9999,
/* 539 */ 9999,
/* 540 */ 233007,
/* 541 */ 9999,
/* 542 */ 237004,
/* 543 */ 9999,
/* 544 */ 237013,
/* 545 */ 9999,
/* 546 */ 238004,
/* 547 */ 9999,
/* 548 */ 238024,
/* 549 */ 9999,
/* 550 */ 238018,
/* 551 */ 9999,
/* 552 */ 9999,
/* 553 */ 9999,
/* 554 */ 242013,
/* 555 */ 9999,
/* 556 */ 9999,
/* 557 */ 9999,
/* 558 */ 243019,
/* 559 */ 9999,
/* 560 */ 243013,
/* 561 */ 9999,
/* 562 */ 9999,
/* 563 */ 9999,
/* 564 */ 247008,
/* 565 */ 9999,
/* 566 */ 9999,
/* 567 */ 9999,
/* 568 */ 248011,
/* 569 */ 9999,
/* 570 */ 252004,
/* 571 */ 252012,
/* 572 */ 9999,
/* 573 */ 252010,
/* 574 */ 9999,
/* 575 */ 253004,
/* 576 */ 9999,
/* 577 */ 253020,
/* 578 */ 9999,
/* 579 */ 9999,
/* 580 */ 9999,
/* 581 */ 257013,
/* 582 */ 9999,
/* 583 */ 9999,
/* 584 */ 258008,
/* 585 */ 9999,
/* 586 */ 9999,
/* 587 */ 258004,
/* 588 */ 9999,
/* 589 */ 259004,
/* 590 */ 9999,
/* 591 */ 259026,
/* 592 */ 9999,
/* 593 */ 9999,
/* 594 */ 259020,
/* 595 */ 9999,
/* 596 */ 260004,
/* 597 */ 9999,
/* 598 */ 9999,
/* 599 */ 9999,
/* 600 */ 260020,
/* 601 */ 9999,
/* 602 */ 261004,
/* 603 */ 9999,
/* 604 */ 261026,
/* 605 */ 9999,
/* 606 */ 9999,
/* 607 */ 261020,
/* 608 */ 9999,
/* 609 */ 262004,
/* 610 */ 9999,
/* 611 */ 262026,
/* 612 */ 9999,
/* 613 */ 9999,
/* 614 */ 262020,
/* 615 */ 9999,
/* 616 */ 263004,
/* 617 */ 9999,
/* 618 */ 9999,
/* 619 */ 9999,
/* 620 */ 263020,
/* 621 */ 9999,
/* 622 */ 9999,
/* 623 */ 9999,
/* 624 */ 267004,
/* 625 */ 9999,
/* 626 */ 9999,
/* 627 */ 268008,
/* 628 */ 9999,
/* 629 */ 268004,
/* 630 */ 9999,
/* 631 */ 9999,
/* 632 */ 269008,
/* 633 */ 9999,
/* 634 */ 269004,
/* 635 */ 9999,
/* 636 */ 9999,
/* 637 */ 270008,
/* 638 */ 270028,
/* 639 */ 9999,
/* 640 */ 270004,
/* 641 */ 9999,
/* 642 */ 274004,
/* 643 */ 9999,
/* 644 */ 274017,
/* 645 */ 9999,
/* 646 */ 275004,
/* 647 */ 275024,
/* 648 */ 9999,
/* 649 */ 275022,
/* 650 */ 9999,
/* 651 */ 280004,
/* 652 */ 9999,
/* 653 */ 280017,
/* 654 */ 9999,
/* 655 */ 281004,
/* 656 */ 9999,
/* 657 */ 9999,
/* 658 */ 9999,
/* 659 */ 281017,
/* 660 */ 9999,
/* 661 */ 285004,
/* 662 */ 9999,
/* 663 */ 285024,
/* 664 */ 9999,
/* 665 */ 286004,
/* 666 */ 9999,
/* 667 */ 286023,
/* 668 */ 9999,
/* 669 */ 286017,
/* 670 */ 9999,
/* 671 */ 290004,
/* 672 */ 290027,
/* 673 */ 9999,
/* 674 */ 290025,
/* 675 */ 9999,
/* 676 */ 291004,
/* 677 */ 291027,
/* 678 */ 9999,
/* 679 */ 291025,
/* 680 */ 9999,
/* 681 */ 292004,
/* 682 */ 9999,
/* 683 */ 292025,
/* 684 */ 9999,
/* 685 */ 9999,
/* 686 */ 9999,
/* 687 */ 296013,
/* 688 */ 9999,
/* 689 */ 297004,
/* 690 */ 9999,
/* 691 */ 9999,
/* 692 */ 9999,
/* 693 */ 297018,
/* 694 */ 9999,
/* 695 */ 301004,
/* 696 */ 9999,
/* 697 */ 301027,
/* 698 */ 9999,
/* 699 */ 302004,
/* 700 */ 302029,
/* 701 */ 9999,
/* 702 */ 302027,
/* 703 */ 9999,
/* 704 */ 306004,
/* 705 */ 9999,
/* 706 */ 306010,
/* 707 */ 9999,
/* 708 */ 307004,
/* 709 */ 9999,
/* 710 */ 307029,
/* 711 */ 9999,
/* 712 */ 308004,
/* 713 */ 308012,
/* 714 */ 9999,
/* 715 */ 308010,
/* 716 */ 9999,
/* 717 */ 9999,
/* 718 */ 312008,
/* 719 */ 9999,
/* 720 */ 9999,
/* 721 */ 312004,
/* 722 */ 9999,
/* 723 */ 9999,
/* 724 */ 9999,
/* 725 */ 9999,
/* 726 */ 313004,
/* 727 */ 9999,
/* 728 */ 9999,
/* 729 */ 314008,
/* 730 */ 9999,
/* 731 */ 9999,
/* 732 */ 314004,
/* 733 */ 9999,
/* 734 */ 315004,
/* 735 */ 9999,
/* 736 */ 9999,
/* 737 */ 9999,
/* 738 */ 315029,
/* 739 */ 9999,
/* 740 */ 316004,
/* 741 */ 9999,
/* 742 */ 316035,
/* 743 */ 9999,
/* 744 */ 9999,
/* 745 */ 316029,
/* 746 */ 9999,
/* 747 */ 9999,
/* 748 */ 9999,
/* 749 */ 9999,
/* 750 */ 317004,
/* 751 */ 9999,
/* 752 */ 9999,
/* 753 */ 318008,
/* 754 */ 9999,
/* 755 */ 9999,
/* 756 */ 318004,
/* 757 */ 9999,
/* 758 */ 319004,
/* 759 */ 9999,
/* 760 */ 9999,
/* 761 */ 9999,
/* 762 */ 319029,
/* 763 */ 9999,
/* 764 */ 320004,
/* 765 */ 9999,
/* 766 */ 320035,
/* 767 */ 9999,
/* 768 */ 9999,
/* 769 */ 320029,
/* 770 */ 9999,
/* 771 */ 324004,
/* 772 */ 9999,
/* 773 */ 324024,
/* 774 */ 9999,
/* 775 */ 9999,
/* 776 */ 325008,
/* 777 */ 9999,
/* 778 */ 9999,
/* 779 */ 325004,
/* 780 */ 9999,
/* 781 */ 9999,
/* 782 */ 326008,
/* 783 */ 9999,
/* 784 */ 9999,
/* 785 */ 9999,
/* 786 */ 326004,
/* 787 */ 9999,
/* 788 */ 330004,
/* 789 */ 9999,
/* 790 */ 330014,
/* 791 */ 9999,
/* 792 */ 331004,
/* 793 */ 9999,
/* 794 */ 331025,
/* 795 */ 9999,
/* 796 */ 331019,
/* 797 */ 9999,
/* 798 */ 335004,
/* 799 */ 9999,
/* 800 */ 335020,
/* 801 */ 9999,
/* 802 */ 336004,
/* 803 */ 9999,
/* 804 */ 336021,
/* 805 */ 9999,
/* 806 */ 337004,
/* 807 */ 9999,
/* 808 */ 337023,
/* 809 */ 9999,
/* 810 */ 338004,
/* 811 */ 9999,
/* 812 */ 338022,
/* 813 */ 9999,
/* 814 */ 339004,
/* 815 */ 9999,
/* 816 */ 339022,
/* 817 */ 9999,
/* 818 */ 340004,
/* 819 */ 9999,
/* 820 */ 340017,
/* 821 */ 9999,
/* 822 */ 9999,
/* 823 */ 9999,
/* 824 */ 344019,
/* 825 */ 9999,
/* 826 */ 344013,
/* 827 */ 9999,
/* 828 */ 9999,
/* 829 */ 345009,
/* 830 */ 9999,
/* 831 */ 345033,
/* 832 */ 9999,
/* 833 */ 345007,
/* 834 */ 9999,
/* 835 */ 9999,
/* 836 */ 9999,
/* 837 */ 346016,
/* 838 */ 9999,
/* 839 */ 346010,
/* 840 */ 9999,
/* 841 */ 9999,
/* 842 */ 9999,
/* 843 */ 9999,
/* 844 */ 350004,
/* 845 */ 9999,
/* 846 */ 9999,
/* 847 */ 351008,
/* 848 */ 9999,
/* 849 */ 9999,
/* 850 */ 351004,
/* 851 */ 9999,
/* 852 */ 9999,
/* 853 */ 352008,
/* 854 */ 9999,
/* 855 */ 9999,
/* 856 */ 352004,
/* 857 */ 9999,
/* 858 */ 9999,
/* 859 */ 353008,
/* 860 */ 353025,
/* 861 */ 9999,
/* 862 */ 9999,
/* 863 */ 353004,
/* 864 */ 9999,
/* 865 */ 357004,
/* 866 */ 9999,
/* 867 */ 357014,
/* 868 */ 9999,
/* 869 */ 358004,
/* 870 */ 358021,
/* 871 */ 9999,
/* 872 */ 358019,
/* 873 */ 9999,
/* 874 */ 362004,
/* 875 */ 9999,
/* 876 */ 362012,
/* 877 */ 9999,
/* 878 */ 363004,
/* 879 */ 363019,
/* 880 */ 9999,
/* 881 */ 363017,
/* 882 */ 9999,
/* 883 */ 9999,
/* 884 */ 9999,
/* 885 */ 367004,
/* 886 */ 9999,
/* 887 */ 368004,
/* 888 */ 9999,
/* 889 */ 9999,
/* 890 */ 368013,
/* 891 */ 9999,
/* 892 */ 9999,
/* 893 */ 9999,
/* 894 */ 372011,
/* 895 */ 9999,
/* 896 */ 372026,
/* 897 */ 9999,
/* 898 */ 372005,
/* 899 */ 9999,
/* 900 */ 9999,
/* 901 */ 9999,
/* 902 */ 373011,
/* 903 */ 9999,
/* 904 */ 373026,
/* 905 */ 9999,
/* 906 */ 373041,
/* 907 */ 9999,
/* 908 */ 373005,
/* 909 */ 9999,
/* 910 */ 9999,
/* 911 */ 9999,
/* 912 */ 374015,
/* 913 */ 9999,
/* 914 */ 374030,
/* 915 */ 9999,
/* 916 */ 374009,
/* 917 */ 9999,
/* 918 */ 9999,
/* 919 */ 9999,
/* 920 */ 378014,
/* 921 */ 9999,
/* 922 */ 378029,
/* 923 */ 9999,
/* 924 */ 378008,
/* 925 */ 9999,
/* 926 */ 9999,
/* 927 */ 379007,
/* 928 */ 9999,
/* 929 */ 9999,
/* 930 */ 379027,
/* 931 */ 9999,
/* 932 */ 9999,
/* 933 */ 9999,
/* 934 */ 379005,
/* 935 */ 9999,
/* 936 */ 9999,
/* 937 */ 9999,
/* 938 */ 380012,
/* 939 */ 380033,
/* 940 */ 9999,
/* 941 */ 380058,
/* 942 */ 9999,
/* 943 */ 380006,
/* 944 */ 9999,
/* 945 */ 9999,
/* 946 */ 9999,
/* 947 */ 381012,
/* 948 */ 381033,
/* 949 */ 381054,
/* 950 */ 9999,
/* 951 */ 381069,
/* 952 */ 9999,
/* 953 */ 381006,
/* 954 */ 9999,
/* 955 */ 9999,
/* 956 */ 9999,
/* 957 */ 9999,
/* 958 */ 9999,
/* 959 */ 385007,
/* 960 */ 9999,
/* 961 */ 9999,
/* 962 */ 9999,
/* 963 */ 9999,
/* 964 */ 386011,
/* 965 */ 9999,
/* 966 */ 9999,
/* 967 */ 9999,
/* 968 */ 9999,
/* 969 */ 387008,
/* 970 */ 9999,
/* 971 */ 9999,
/* 972 */ 9999,
/* 973 */ 9999,
/* 974 */ 388009,
/* 975 */ 9999,
/* 976 */ 9999,
/* 977 */ 389011,
/* 978 */ 9999,
/* 979 */ 9999,
/* 980 */ 389009,
/* 981 */ 9999,
/* 982 */ 392004,
/* 983 */ 9999,
/* 984 */ 392023,
/* 985 */ 9999,
/* 986 */ 393004,
/* 987 */ 393009,
/* 988 */ 9999,
/* 989 */ 393007,
/* 990 */ 9999,
/* 991 */ 397004,
/* 992 */ 9999,
/* 993 */ 397022,
/* 994 */ 9999,
/* 995 */ 398004,
/* 996 */ 9999,
/* 997 */ 398014,
/* 998 */ 9999,
/* 999 */ 402004,
/* 1000 */ 402027,
/* 1001 */ 402038,
/* 1002 */ 402055,
/* 1003 */ 9999,
/* 1004 */ 402025,
/* 1005 */ 9999,
/* 1006 */ 403004,
/* 1007 */ 403027,
/* 1008 */ 403038,
/* 1009 */ 9999,
/* 1010 */ 403025,
/* 1011 */ 9999,
/* 1012 */ 404004,
/* 1013 */ 404015,
/* 1014 */ 404032,
/* 1015 */ 9999,
/* 1016 */ 404013,
/* 1017 */ 9999,
/* 1018 */ 405004,
/* 1019 */ 405015,
/* 1020 */ 9999,
/* 1021 */ 405013,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[1023];
*/
int TABLE[199][305];
init_dirsets() {
TABLE[198][260] = 1;
TABLE[198][286] = 1;
TABLE[198][285] = 1;
TABLE[198][259] = 1;
TABLE[198][276] = 1;
TABLE[198][272] = 1;
TABLE[198][273] = 1;
TABLE[198][268] = 1;
TABLE[198][264] = 1;
TABLE[198][277] = 1;
TABLE[198][284] = 1;
TABLE[198][298] = 1;
TABLE[198][282] = 1;
TABLE[198][267] = 1;
TABLE[198][279] = 1;
TABLE[198][256] = 1;
TABLE[198][274] = 1;
TABLE[198][40] = 1;
TABLE[198][42] = 1;
TABLE[198][266] = 1;
TABLE[198][280] = 1;
TABLE[198][283] = 1;
TABLE[1][42] = 1;
TABLE[1][40] = 1;
TABLE[1][274] = 1;
TABLE[1][256] = 1;
TABLE[1][279] = 1;
TABLE[1][267] = 1;
TABLE[1][282] = 1;
TABLE[1][298] = 1;
TABLE[1][284] = 1;
TABLE[1][277] = 1;
TABLE[1][264] = 1;
TABLE[1][268] = 1;
TABLE[1][273] = 1;
TABLE[1][272] = 1;
TABLE[1][276] = 1;
TABLE[1][259] = 1;
TABLE[1][285] = 1;
TABLE[1][286] = 1;
TABLE[1][260] = 1;
TABLE[1][266] = 1;
TABLE[1][283] = 1;
TABLE[1][280] = 1;
TABLE[2][260] = 1;
TABLE[2][286] = 1;
TABLE[2][285] = 1;
TABLE[2][259] = 1;
TABLE[2][276] = 1;
TABLE[2][272] = 1;
TABLE[2][273] = 1;
TABLE[2][268] = 1;
TABLE[2][264] = 1;
TABLE[2][277] = 1;
TABLE[2][284] = 1;
TABLE[2][298] = 1;
TABLE[2][282] = 1;
TABLE[2][267] = 1;
TABLE[2][279] = 1;
TABLE[2][256] = 1;
TABLE[2][274] = 1;
TABLE[2][40] = 1;
TABLE[2][42] = 1;
TABLE[2][266] = 1;
TABLE[2][280] = 1;
TABLE[2][283] = 1;
TABLE[3][298] = 1;
TABLE[4][288] = 1;
TABLE[5][289] = 1;
TABLE[6][40] = 1;
TABLE[7][298] = 1;
TABLE[7][288] = 1;
TABLE[7][289] = 1;
TABLE[7][40] = 1;
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
TABLE[13][40] = 1;
TABLE[13][289] = 1;
TABLE[13][288] = 1;
TABLE[13][298] = 1;
TABLE[14][40] = 1;
TABLE[14][289] = 1;
TABLE[14][288] = 1;
TABLE[14][298] = 1;
TABLE[15][278] = 1;
TABLE[15][295] = 1;
TABLE[15][294] = 1;
TABLE[15][40] = 1;
TABLE[15][289] = 1;
TABLE[15][288] = 1;
TABLE[15][298] = 1;
TABLE[15][38] = 1;
TABLE[15][42] = 1;
TABLE[15][43] = 1;
TABLE[15][45] = 1;
TABLE[15][126] = 1;
TABLE[15][33] = 1;
TABLE[16][298] = 1;
TABLE[16][288] = 1;
TABLE[16][289] = 1;
TABLE[16][40] = 1;
TABLE[16][294] = 1;
TABLE[16][295] = 1;
TABLE[16][278] = 1;
TABLE[16][33] = 1;
TABLE[16][126] = 1;
TABLE[16][45] = 1;
TABLE[16][43] = 1;
TABLE[16][42] = 1;
TABLE[16][38] = 1;
TABLE[17][40] = 1;
TABLE[17][289] = 1;
TABLE[17][288] = 1;
TABLE[17][298] = 1;
TABLE[18][294] = 1;
TABLE[19][295] = 1;
TABLE[20][38] = 1;
TABLE[20][42] = 1;
TABLE[20][43] = 1;
TABLE[20][45] = 1;
TABLE[20][126] = 1;
TABLE[20][33] = 1;
TABLE[21][278] = 1;
TABLE[22][278] = 1;
TABLE[23][38] = 1;
TABLE[24][42] = 1;
TABLE[25][43] = 1;
TABLE[26][45] = 1;
TABLE[27][126] = 1;
TABLE[28][33] = 1;
TABLE[29][298] = 1;
TABLE[29][288] = 1;
TABLE[29][289] = 1;
TABLE[29][40] = 1;
TABLE[29][294] = 1;
TABLE[29][295] = 1;
TABLE[29][278] = 1;
TABLE[29][33] = 1;
TABLE[29][126] = 1;
TABLE[29][45] = 1;
TABLE[29][43] = 1;
TABLE[29][42] = 1;
TABLE[29][38] = 1;
TABLE[30][40] = 1;
TABLE[31][278] = 1;
TABLE[31][295] = 1;
TABLE[31][294] = 1;
TABLE[31][40] = 1;
TABLE[31][289] = 1;
TABLE[31][288] = 1;
TABLE[31][298] = 1;
TABLE[31][38] = 1;
TABLE[31][42] = 1;
TABLE[31][43] = 1;
TABLE[31][45] = 1;
TABLE[31][126] = 1;
TABLE[31][33] = 1;
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
TABLE[34][298] = 1;
TABLE[34][288] = 1;
TABLE[34][289] = 1;
TABLE[34][40] = 1;
TABLE[34][294] = 1;
TABLE[34][295] = 1;
TABLE[34][278] = 1;
TABLE[34][33] = 1;
TABLE[34][126] = 1;
TABLE[34][45] = 1;
TABLE[34][43] = 1;
TABLE[34][42] = 1;
TABLE[34][38] = 1;
TABLE[35][298] = 1;
TABLE[35][288] = 1;
TABLE[35][289] = 1;
TABLE[35][40] = 1;
TABLE[35][294] = 1;
TABLE[35][295] = 1;
TABLE[35][278] = 1;
TABLE[35][33] = 1;
TABLE[35][126] = 1;
TABLE[35][45] = 1;
TABLE[35][43] = 1;
TABLE[35][42] = 1;
TABLE[35][38] = 1;
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
TABLE[37][278] = 1;
TABLE[37][295] = 1;
TABLE[37][294] = 1;
TABLE[37][40] = 1;
TABLE[37][289] = 1;
TABLE[37][288] = 1;
TABLE[37][298] = 1;
TABLE[37][38] = 1;
TABLE[37][42] = 1;
TABLE[37][43] = 1;
TABLE[37][45] = 1;
TABLE[37][126] = 1;
TABLE[37][33] = 1;
TABLE[38][278] = 1;
TABLE[38][295] = 1;
TABLE[38][294] = 1;
TABLE[38][40] = 1;
TABLE[38][289] = 1;
TABLE[38][288] = 1;
TABLE[38][298] = 1;
TABLE[38][38] = 1;
TABLE[38][42] = 1;
TABLE[38][43] = 1;
TABLE[38][45] = 1;
TABLE[38][126] = 1;
TABLE[38][33] = 1;
TABLE[39][298] = 1;
TABLE[39][288] = 1;
TABLE[39][289] = 1;
TABLE[39][40] = 1;
TABLE[39][294] = 1;
TABLE[39][295] = 1;
TABLE[39][278] = 1;
TABLE[39][33] = 1;
TABLE[39][126] = 1;
TABLE[39][45] = 1;
TABLE[39][43] = 1;
TABLE[39][42] = 1;
TABLE[39][38] = 1;
TABLE[40][298] = 1;
TABLE[40][288] = 1;
TABLE[40][289] = 1;
TABLE[40][40] = 1;
TABLE[40][294] = 1;
TABLE[40][295] = 1;
TABLE[40][278] = 1;
TABLE[40][33] = 1;
TABLE[40][126] = 1;
TABLE[40][45] = 1;
TABLE[40][43] = 1;
TABLE[40][42] = 1;
TABLE[40][38] = 1;
TABLE[41][278] = 1;
TABLE[41][295] = 1;
TABLE[41][294] = 1;
TABLE[41][40] = 1;
TABLE[41][289] = 1;
TABLE[41][288] = 1;
TABLE[41][298] = 1;
TABLE[41][38] = 1;
TABLE[41][42] = 1;
TABLE[41][43] = 1;
TABLE[41][45] = 1;
TABLE[41][126] = 1;
TABLE[41][33] = 1;
TABLE[42][278] = 1;
TABLE[42][295] = 1;
TABLE[42][294] = 1;
TABLE[42][40] = 1;
TABLE[42][289] = 1;
TABLE[42][288] = 1;
TABLE[42][298] = 1;
TABLE[42][38] = 1;
TABLE[42][42] = 1;
TABLE[42][43] = 1;
TABLE[42][45] = 1;
TABLE[42][126] = 1;
TABLE[42][33] = 1;
TABLE[43][298] = 1;
TABLE[43][288] = 1;
TABLE[43][289] = 1;
TABLE[43][40] = 1;
TABLE[43][294] = 1;
TABLE[43][295] = 1;
TABLE[43][278] = 1;
TABLE[43][33] = 1;
TABLE[43][126] = 1;
TABLE[43][45] = 1;
TABLE[43][43] = 1;
TABLE[43][42] = 1;
TABLE[43][38] = 1;
TABLE[44][298] = 1;
TABLE[44][288] = 1;
TABLE[44][289] = 1;
TABLE[44][40] = 1;
TABLE[44][294] = 1;
TABLE[44][295] = 1;
TABLE[44][278] = 1;
TABLE[44][33] = 1;
TABLE[44][126] = 1;
TABLE[44][45] = 1;
TABLE[44][43] = 1;
TABLE[44][42] = 1;
TABLE[44][38] = 1;
TABLE[45][278] = 1;
TABLE[45][295] = 1;
TABLE[45][294] = 1;
TABLE[45][40] = 1;
TABLE[45][289] = 1;
TABLE[45][288] = 1;
TABLE[45][298] = 1;
TABLE[45][38] = 1;
TABLE[45][42] = 1;
TABLE[45][43] = 1;
TABLE[45][45] = 1;
TABLE[45][126] = 1;
TABLE[45][33] = 1;
TABLE[46][278] = 1;
TABLE[46][295] = 1;
TABLE[46][294] = 1;
TABLE[46][40] = 1;
TABLE[46][289] = 1;
TABLE[46][288] = 1;
TABLE[46][298] = 1;
TABLE[46][38] = 1;
TABLE[46][42] = 1;
TABLE[46][43] = 1;
TABLE[46][45] = 1;
TABLE[46][126] = 1;
TABLE[46][33] = 1;
TABLE[47][298] = 1;
TABLE[47][288] = 1;
TABLE[47][289] = 1;
TABLE[47][40] = 1;
TABLE[47][294] = 1;
TABLE[47][295] = 1;
TABLE[47][278] = 1;
TABLE[47][33] = 1;
TABLE[47][126] = 1;
TABLE[47][45] = 1;
TABLE[47][43] = 1;
TABLE[47][42] = 1;
TABLE[47][38] = 1;
TABLE[48][298] = 1;
TABLE[48][288] = 1;
TABLE[48][289] = 1;
TABLE[48][40] = 1;
TABLE[48][294] = 1;
TABLE[48][295] = 1;
TABLE[48][278] = 1;
TABLE[48][33] = 1;
TABLE[48][126] = 1;
TABLE[48][45] = 1;
TABLE[48][43] = 1;
TABLE[48][42] = 1;
TABLE[48][38] = 1;
TABLE[49][278] = 1;
TABLE[49][295] = 1;
TABLE[49][294] = 1;
TABLE[49][40] = 1;
TABLE[49][289] = 1;
TABLE[49][288] = 1;
TABLE[49][298] = 1;
TABLE[49][38] = 1;
TABLE[49][42] = 1;
TABLE[49][43] = 1;
TABLE[49][45] = 1;
TABLE[49][126] = 1;
TABLE[49][33] = 1;
TABLE[50][278] = 1;
TABLE[50][295] = 1;
TABLE[50][294] = 1;
TABLE[50][40] = 1;
TABLE[50][289] = 1;
TABLE[50][288] = 1;
TABLE[50][298] = 1;
TABLE[50][38] = 1;
TABLE[50][42] = 1;
TABLE[50][43] = 1;
TABLE[50][45] = 1;
TABLE[50][126] = 1;
TABLE[50][33] = 1;
TABLE[51][298] = 1;
TABLE[51][288] = 1;
TABLE[51][289] = 1;
TABLE[51][40] = 1;
TABLE[51][294] = 1;
TABLE[51][295] = 1;
TABLE[51][278] = 1;
TABLE[51][33] = 1;
TABLE[51][126] = 1;
TABLE[51][45] = 1;
TABLE[51][43] = 1;
TABLE[51][42] = 1;
TABLE[51][38] = 1;
TABLE[52][298] = 1;
TABLE[52][288] = 1;
TABLE[52][289] = 1;
TABLE[52][40] = 1;
TABLE[52][294] = 1;
TABLE[52][295] = 1;
TABLE[52][278] = 1;
TABLE[52][33] = 1;
TABLE[52][126] = 1;
TABLE[52][45] = 1;
TABLE[52][43] = 1;
TABLE[52][42] = 1;
TABLE[52][38] = 1;
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
TABLE[54][278] = 1;
TABLE[54][295] = 1;
TABLE[54][294] = 1;
TABLE[54][40] = 1;
TABLE[54][289] = 1;
TABLE[54][288] = 1;
TABLE[54][298] = 1;
TABLE[54][38] = 1;
TABLE[54][42] = 1;
TABLE[54][43] = 1;
TABLE[54][45] = 1;
TABLE[54][126] = 1;
TABLE[54][33] = 1;
TABLE[55][278] = 1;
TABLE[55][295] = 1;
TABLE[55][294] = 1;
TABLE[55][40] = 1;
TABLE[55][289] = 1;
TABLE[55][288] = 1;
TABLE[55][298] = 1;
TABLE[55][38] = 1;
TABLE[55][42] = 1;
TABLE[55][43] = 1;
TABLE[55][45] = 1;
TABLE[55][126] = 1;
TABLE[55][33] = 1;
TABLE[56][298] = 1;
TABLE[56][288] = 1;
TABLE[56][289] = 1;
TABLE[56][40] = 1;
TABLE[56][294] = 1;
TABLE[56][295] = 1;
TABLE[56][278] = 1;
TABLE[56][33] = 1;
TABLE[56][126] = 1;
TABLE[56][45] = 1;
TABLE[56][43] = 1;
TABLE[56][42] = 1;
TABLE[56][38] = 1;
TABLE[57][298] = 1;
TABLE[57][288] = 1;
TABLE[57][289] = 1;
TABLE[57][40] = 1;
TABLE[57][294] = 1;
TABLE[57][295] = 1;
TABLE[57][278] = 1;
TABLE[57][33] = 1;
TABLE[57][126] = 1;
TABLE[57][45] = 1;
TABLE[57][43] = 1;
TABLE[57][42] = 1;
TABLE[57][38] = 1;
TABLE[58][278] = 1;
TABLE[58][295] = 1;
TABLE[58][294] = 1;
TABLE[58][40] = 1;
TABLE[58][289] = 1;
TABLE[58][288] = 1;
TABLE[58][298] = 1;
TABLE[58][38] = 1;
TABLE[58][42] = 1;
TABLE[58][43] = 1;
TABLE[58][45] = 1;
TABLE[58][126] = 1;
TABLE[58][33] = 1;
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
TABLE[60][298] = 1;
TABLE[60][288] = 1;
TABLE[60][289] = 1;
TABLE[60][40] = 1;
TABLE[60][294] = 1;
TABLE[60][295] = 1;
TABLE[60][278] = 1;
TABLE[60][33] = 1;
TABLE[60][126] = 1;
TABLE[60][45] = 1;
TABLE[60][43] = 1;
TABLE[60][42] = 1;
TABLE[60][38] = 1;
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
TABLE[62][274] = 1;
TABLE[62][256] = 1;
TABLE[62][279] = 1;
TABLE[62][267] = 1;
TABLE[62][282] = 1;
TABLE[62][298] = 1;
TABLE[62][284] = 1;
TABLE[62][277] = 1;
TABLE[62][264] = 1;
TABLE[62][268] = 1;
TABLE[62][273] = 1;
TABLE[62][272] = 1;
TABLE[62][276] = 1;
TABLE[62][259] = 1;
TABLE[62][285] = 1;
TABLE[62][286] = 1;
TABLE[62][260] = 1;
TABLE[62][266] = 1;
TABLE[62][283] = 1;
TABLE[62][280] = 1;
TABLE[63][282] = 1;
TABLE[63][267] = 1;
TABLE[63][279] = 1;
TABLE[63][256] = 1;
TABLE[63][274] = 1;
TABLE[64][282] = 1;
TABLE[64][267] = 1;
TABLE[64][279] = 1;
TABLE[64][256] = 1;
TABLE[64][274] = 1;
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
TABLE[66][285] = 1;
TABLE[66][259] = 1;
TABLE[66][276] = 1;
TABLE[66][272] = 1;
TABLE[66][273] = 1;
TABLE[66][268] = 1;
TABLE[66][264] = 1;
TABLE[66][277] = 1;
TABLE[66][284] = 1;
TABLE[66][298] = 1;
TABLE[66][266] = 1;
TABLE[66][280] = 1;
TABLE[66][283] = 1;
TABLE[67][260] = 1;
TABLE[67][286] = 1;
TABLE[68][260] = 1;
TABLE[68][286] = 1;
TABLE[69][298] = 1;
TABLE[69][40] = 1;
TABLE[69][42] = 1;
TABLE[70][42] = 1;
TABLE[70][40] = 1;
TABLE[70][298] = 1;
TABLE[71][42] = 1;
TABLE[71][40] = 1;
TABLE[71][298] = 1;
TABLE[72][42] = 1;
TABLE[72][40] = 1;
TABLE[72][298] = 1;
TABLE[73][282] = 1;
TABLE[74][267] = 1;
TABLE[75][279] = 1;
TABLE[76][256] = 1;
TABLE[77][274] = 1;
TABLE[78][285] = 1;
TABLE[79][259] = 1;
TABLE[80][276] = 1;
TABLE[81][272] = 1;
TABLE[82][273] = 1;
TABLE[83][268] = 1;
TABLE[84][264] = 1;
TABLE[85][277] = 1;
TABLE[86][284] = 1;
TABLE[87][283] = 1;
TABLE[87][280] = 1;
TABLE[88][266] = 1;
TABLE[89][298] = 1;
TABLE[90][280] = 1;
TABLE[90][283] = 1;
TABLE[91][280] = 1;
TABLE[91][283] = 1;
TABLE[92][280] = 1;
TABLE[92][283] = 1;
TABLE[93][280] = 1;
TABLE[94][283] = 1;
TABLE[95][285] = 1;
TABLE[95][259] = 1;
TABLE[95][276] = 1;
TABLE[95][272] = 1;
TABLE[95][273] = 1;
TABLE[95][268] = 1;
TABLE[95][264] = 1;
TABLE[95][277] = 1;
TABLE[95][284] = 1;
TABLE[95][298] = 1;
TABLE[95][260] = 1;
TABLE[95][286] = 1;
TABLE[95][266] = 1;
TABLE[95][280] = 1;
TABLE[95][283] = 1;
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
TABLE[97][298] = 1;
TABLE[97][284] = 1;
TABLE[97][277] = 1;
TABLE[97][264] = 1;
TABLE[97][268] = 1;
TABLE[97][273] = 1;
TABLE[97][272] = 1;
TABLE[97][276] = 1;
TABLE[97][259] = 1;
TABLE[97][285] = 1;
TABLE[97][266] = 1;
TABLE[97][286] = 1;
TABLE[97][260] = 1;
TABLE[97][283] = 1;
TABLE[97][280] = 1;
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
TABLE[99][285] = 1;
TABLE[99][259] = 1;
TABLE[99][276] = 1;
TABLE[99][272] = 1;
TABLE[99][273] = 1;
TABLE[99][268] = 1;
TABLE[99][264] = 1;
TABLE[99][277] = 1;
TABLE[99][284] = 1;
TABLE[99][298] = 1;
TABLE[99][266] = 1;
TABLE[99][280] = 1;
TABLE[99][283] = 1;
TABLE[100][260] = 1;
TABLE[100][286] = 1;
TABLE[101][260] = 1;
TABLE[101][286] = 1;
TABLE[102][58] = 1;
TABLE[102][298] = 1;
TABLE[102][40] = 1;
TABLE[102][42] = 1;
TABLE[103][58] = 1;
TABLE[103][42] = 1;
TABLE[103][40] = 1;
TABLE[103][298] = 1;
TABLE[104][42] = 1;
TABLE[104][40] = 1;
TABLE[104][298] = 1;
TABLE[105][58] = 1;
TABLE[106][42] = 1;
TABLE[106][40] = 1;
TABLE[106][298] = 1;
TABLE[107][266] = 1;
TABLE[108][266] = 1;
TABLE[109][266] = 1;
TABLE[110][298] = 1;
TABLE[111][298] = 1;
TABLE[112][298] = 1;
TABLE[113][298] = 1;
TABLE[114][260] = 1;
TABLE[115][286] = 1;
TABLE[116][42] = 1;
TABLE[117][298] = 1;
TABLE[117][40] = 1;
TABLE[118][298] = 1;
TABLE[119][40] = 1;
TABLE[120][298] = 1;
TABLE[120][40] = 1;
TABLE[121][298] = 1;
TABLE[121][40] = 1;
TABLE[122][298] = 1;
TABLE[122][40] = 1;
TABLE[123][298] = 1;
TABLE[123][40] = 1;
TABLE[124][298] = 1;
TABLE[124][40] = 1;
TABLE[125][42] = 1;
TABLE[126][42] = 1;
TABLE[127][42] = 1;
TABLE[128][42] = 1;
TABLE[129][260] = 1;
TABLE[129][286] = 1;
TABLE[130][286] = 1;
TABLE[130][260] = 1;
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
TABLE[132][274] = 1;
TABLE[132][256] = 1;
TABLE[132][279] = 1;
TABLE[132][267] = 1;
TABLE[132][282] = 1;
TABLE[132][298] = 1;
TABLE[132][284] = 1;
TABLE[132][277] = 1;
TABLE[132][264] = 1;
TABLE[132][268] = 1;
TABLE[132][273] = 1;
TABLE[132][272] = 1;
TABLE[132][276] = 1;
TABLE[132][259] = 1;
TABLE[132][285] = 1;
TABLE[132][286] = 1;
TABLE[132][260] = 1;
TABLE[132][266] = 1;
TABLE[132][283] = 1;
TABLE[132][280] = 1;
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
TABLE[133][298] = 1;
TABLE[133][282] = 1;
TABLE[133][267] = 1;
TABLE[133][279] = 1;
TABLE[133][256] = 1;
TABLE[133][274] = 1;
TABLE[133][266] = 1;
TABLE[133][280] = 1;
TABLE[133][283] = 1;
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
TABLE[137][274] = 1;
TABLE[137][256] = 1;
TABLE[137][279] = 1;
TABLE[137][267] = 1;
TABLE[137][282] = 1;
TABLE[137][298] = 1;
TABLE[137][284] = 1;
TABLE[137][277] = 1;
TABLE[137][264] = 1;
TABLE[137][268] = 1;
TABLE[137][273] = 1;
TABLE[137][272] = 1;
TABLE[137][276] = 1;
TABLE[137][259] = 1;
TABLE[137][285] = 1;
TABLE[137][286] = 1;
TABLE[137][260] = 1;
TABLE[137][266] = 1;
TABLE[137][283] = 1;
TABLE[137][280] = 1;
TABLE[138][298] = 1;
TABLE[139][298] = 1;
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
TABLE[141][298] = 1;
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
TABLE[141][286] = 1;
TABLE[141][260] = 1;
TABLE[141][283] = 1;
TABLE[141][280] = 1;
TABLE[142][42] = 1;
TABLE[143][40] = 1;
TABLE[143][91] = 1;
TABLE[144][42] = 1;
TABLE[145][40] = 1;
TABLE[146][91] = 1;
TABLE[147][91] = 1;
TABLE[148][40] = 1;
TABLE[148][91] = 1;
TABLE[149][40] = 1;
TABLE[149][91] = 1;
TABLE[150][40] = 1;
TABLE[151][40] = 1;
TABLE[152][40] = 1;
TABLE[152][91] = 1;
TABLE[153][40] = 1;
TABLE[153][91] = 1;
TABLE[154][278] = 1;
TABLE[154][295] = 1;
TABLE[154][294] = 1;
TABLE[154][40] = 1;
TABLE[154][289] = 1;
TABLE[154][288] = 1;
TABLE[154][298] = 1;
TABLE[154][38] = 1;
TABLE[154][42] = 1;
TABLE[154][43] = 1;
TABLE[154][45] = 1;
TABLE[154][126] = 1;
TABLE[154][33] = 1;
TABLE[155][123] = 1;
TABLE[156][123] = 1;
TABLE[157][298] = 1;
TABLE[157][288] = 1;
TABLE[157][289] = 1;
TABLE[157][40] = 1;
TABLE[157][294] = 1;
TABLE[157][295] = 1;
TABLE[157][278] = 1;
TABLE[157][123] = 1;
TABLE[157][33] = 1;
TABLE[157][126] = 1;
TABLE[157][45] = 1;
TABLE[157][43] = 1;
TABLE[157][42] = 1;
TABLE[157][38] = 1;
TABLE[158][123] = 1;
TABLE[158][278] = 1;
TABLE[158][295] = 1;
TABLE[158][294] = 1;
TABLE[158][40] = 1;
TABLE[158][289] = 1;
TABLE[158][288] = 1;
TABLE[158][298] = 1;
TABLE[158][38] = 1;
TABLE[158][42] = 1;
TABLE[158][43] = 1;
TABLE[158][45] = 1;
TABLE[158][126] = 1;
TABLE[158][33] = 1;
TABLE[159][298] = 1;
TABLE[159][258] = 1;
TABLE[159][262] = 1;
TABLE[160][123] = 1;
TABLE[161][59] = 1;
TABLE[161][278] = 1;
TABLE[161][295] = 1;
TABLE[161][294] = 1;
TABLE[161][40] = 1;
TABLE[161][289] = 1;
TABLE[161][288] = 1;
TABLE[161][298] = 1;
TABLE[161][38] = 1;
TABLE[161][42] = 1;
TABLE[161][43] = 1;
TABLE[161][45] = 1;
TABLE[161][126] = 1;
TABLE[161][33] = 1;
TABLE[162][271] = 1;
TABLE[162][281] = 1;
TABLE[163][287] = 1;
TABLE[163][263] = 1;
TABLE[163][269] = 1;
TABLE[164][270] = 1;
TABLE[164][261] = 1;
TABLE[164][257] = 1;
TABLE[164][275] = 1;
TABLE[165][298] = 1;
TABLE[166][258] = 1;
TABLE[167][262] = 1;
TABLE[168][123] = 1;
TABLE[169][123] = 1;
TABLE[170][123] = 1;
TABLE[171][123] = 1;
TABLE[172][260] = 1;
TABLE[172][286] = 1;
TABLE[172][285] = 1;
TABLE[172][259] = 1;
TABLE[172][276] = 1;
TABLE[172][272] = 1;
TABLE[172][273] = 1;
TABLE[172][268] = 1;
TABLE[172][264] = 1;
TABLE[172][277] = 1;
TABLE[172][284] = 1;
TABLE[172][298] = 1;
TABLE[172][282] = 1;
TABLE[172][267] = 1;
TABLE[172][279] = 1;
TABLE[172][256] = 1;
TABLE[172][274] = 1;
TABLE[172][266] = 1;
TABLE[172][280] = 1;
TABLE[172][283] = 1;
TABLE[173][274] = 1;
TABLE[173][256] = 1;
TABLE[173][279] = 1;
TABLE[173][267] = 1;
TABLE[173][282] = 1;
TABLE[173][298] = 1;
TABLE[173][284] = 1;
TABLE[173][277] = 1;
TABLE[173][264] = 1;
TABLE[173][268] = 1;
TABLE[173][273] = 1;
TABLE[173][272] = 1;
TABLE[173][276] = 1;
TABLE[173][259] = 1;
TABLE[173][285] = 1;
TABLE[173][286] = 1;
TABLE[173][260] = 1;
TABLE[173][266] = 1;
TABLE[173][283] = 1;
TABLE[173][280] = 1;
TABLE[174][262] = 1;
TABLE[174][258] = 1;
TABLE[174][298] = 1;
TABLE[174][123] = 1;
TABLE[174][288] = 1;
TABLE[174][289] = 1;
TABLE[174][40] = 1;
TABLE[174][294] = 1;
TABLE[174][295] = 1;
TABLE[174][278] = 1;
TABLE[174][59] = 1;
TABLE[174][281] = 1;
TABLE[174][271] = 1;
TABLE[174][269] = 1;
TABLE[174][263] = 1;
TABLE[174][287] = 1;
TABLE[174][275] = 1;
TABLE[174][257] = 1;
TABLE[174][261] = 1;
TABLE[174][270] = 1;
TABLE[174][33] = 1;
TABLE[174][126] = 1;
TABLE[174][45] = 1;
TABLE[174][43] = 1;
TABLE[174][42] = 1;
TABLE[174][38] = 1;
TABLE[175][270] = 1;
TABLE[175][261] = 1;
TABLE[175][257] = 1;
TABLE[175][275] = 1;
TABLE[175][287] = 1;
TABLE[175][263] = 1;
TABLE[175][269] = 1;
TABLE[175][271] = 1;
TABLE[175][281] = 1;
TABLE[175][59] = 1;
TABLE[175][278] = 1;
TABLE[175][295] = 1;
TABLE[175][294] = 1;
TABLE[175][40] = 1;
TABLE[175][289] = 1;
TABLE[175][288] = 1;
TABLE[175][123] = 1;
TABLE[175][298] = 1;
TABLE[175][258] = 1;
TABLE[175][262] = 1;
TABLE[175][38] = 1;
TABLE[175][42] = 1;
TABLE[175][43] = 1;
TABLE[175][45] = 1;
TABLE[175][126] = 1;
TABLE[175][33] = 1;
TABLE[176][59] = 1;
TABLE[177][298] = 1;
TABLE[177][288] = 1;
TABLE[177][289] = 1;
TABLE[177][40] = 1;
TABLE[177][294] = 1;
TABLE[177][295] = 1;
TABLE[177][278] = 1;
TABLE[177][33] = 1;
TABLE[177][126] = 1;
TABLE[177][45] = 1;
TABLE[177][43] = 1;
TABLE[177][42] = 1;
TABLE[177][38] = 1;
TABLE[178][271] = 1;
TABLE[179][271] = 1;
TABLE[180][281] = 1;
TABLE[181][287] = 1;
TABLE[182][263] = 1;
TABLE[183][269] = 1;
TABLE[184][269] = 1;
TABLE[185][270] = 1;
TABLE[186][261] = 1;
TABLE[187][257] = 1;
TABLE[188][275] = 1;
TABLE[189][275] = 1;
TABLE[190][42] = 1;
TABLE[190][40] = 1;
TABLE[190][274] = 1;
TABLE[190][256] = 1;
TABLE[190][279] = 1;
TABLE[190][267] = 1;
TABLE[190][282] = 1;
TABLE[190][298] = 1;
TABLE[190][284] = 1;
TABLE[190][277] = 1;
TABLE[190][264] = 1;
TABLE[190][268] = 1;
TABLE[190][273] = 1;
TABLE[190][272] = 1;
TABLE[190][276] = 1;
TABLE[190][259] = 1;
TABLE[190][285] = 1;
TABLE[190][286] = 1;
TABLE[190][260] = 1;
TABLE[190][266] = 1;
TABLE[190][283] = 1;
TABLE[190][280] = 1;
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
TABLE[192][40] = 1;
TABLE[192][42] = 1;
TABLE[192][266] = 1;
TABLE[192][280] = 1;
TABLE[192][283] = 1;
TABLE[193][260] = 1;
TABLE[193][286] = 1;
TABLE[193][285] = 1;
TABLE[193][259] = 1;
TABLE[193][276] = 1;
TABLE[193][272] = 1;
TABLE[193][273] = 1;
TABLE[193][268] = 1;
TABLE[193][264] = 1;
TABLE[193][277] = 1;
TABLE[193][284] = 1;
TABLE[193][298] = 1;
TABLE[193][282] = 1;
TABLE[193][267] = 1;
TABLE[193][279] = 1;
TABLE[193][256] = 1;
TABLE[193][274] = 1;
TABLE[193][266] = 1;
TABLE[193][280] = 1;
TABLE[193][283] = 1;
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
TABLE[195][274] = 1;
TABLE[195][256] = 1;
TABLE[195][279] = 1;
TABLE[195][267] = 1;
TABLE[195][282] = 1;
TABLE[195][298] = 1;
TABLE[195][284] = 1;
TABLE[195][277] = 1;
TABLE[195][264] = 1;
TABLE[195][268] = 1;
TABLE[195][273] = 1;
TABLE[195][272] = 1;
TABLE[195][276] = 1;
TABLE[195][259] = 1;
TABLE[195][285] = 1;
TABLE[195][286] = 1;
TABLE[195][260] = 1;
TABLE[195][266] = 1;
TABLE[195][283] = 1;
TABLE[195][280] = 1;
TABLE[196][42] = 1;
TABLE[196][40] = 1;
TABLE[196][298] = 1;
TABLE[197][42] = 1;
TABLE[197][40] = 1;
TABLE[197][298] = 1;
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
      case 15: return 0; break;
      case 33: return 0; break;
      case 79: return 0; break;
      case 89: return 0; break;
      case 120: return 0; break;
      case 144: return 0; break;
      case 155: return 0; break;
      case 177: return 0; break;
      case 193: return 0; break;
      case 203: return 0; break;
      case 213: return 0; break;
      case 223: return 0; break;
      case 233: return 0; break;
      case 243: return 0; break;
      case 253: return 0; break;
      case 263: return 0; break;
      case 273: return 0; break;
      case 285: return 0; break;
      case 295: return 0; break;
      case 305: return 0; break;
      case 309: return 0; break;
      case 320: return 0; break;
      case 347: return 0; break;
      case 357: return 0; break;
      case 367: return 0; break;
      case 387: return 0; break;
      case 435: return 0; break;
      case 455: return 0; break;
      case 463: return 0; break;
      case 472: return 0; break;
      case 478: return 0; break;
      case 496: return 0; break;
      case 506: return 0; break;
      case 521: return 0; break;
      case 541: return 0; break;
      case 551: return 0; break;
      case 561: return 0; break;
      case 569: return 0; break;
      case 578: return 0; break;
      case 621: return 0; break;
      case 641: return 0; break;
      case 650: return 0; break;
      case 660: return 0; break;
      case 670: return 0; break;
      case 684: return 0; break;
      case 694: return 0; break;
      case 703: return 0; break;
      case 716: return 0; break;
      case 770: return 0; break;
      case 787: return 0; break;
      case 797: return 0; break;
      case 821: return 0; break;
      case 840: return 0; break;
      case 864: return 0; break;
      case 873: return 0; break;
      case 882: return 0; break;
      case 891: return 0; break;
      case 917: return 0; break;
      case 954: return 0; break;
      case 981: return 0; break;
      case 990: return 0; break;
      case 998: return 0; break;
   }
}
char * yyprintname(n)
   int n;
{
   if (n <= 50000)
      switch(n) {
         case 1: return "YYSTART"; break;
         case 6: return "translation_unit"; break;
         case 15: return "primary_expression"; break;
         case 33: return "postfix_expression"; break;
         case 79: return "argument_expression_list"; break;
         case 89: return "unary_expression"; break;
         case 120: return "unary_operator"; break;
         case 144: return "cast_expression"; break;
         case 155: return "multiplicative_expression"; break;
         case 177: return "additive_expression"; break;
         case 193: return "shift_expression"; break;
         case 203: return "relational_expression"; break;
         case 213: return "equality_expression"; break;
         case 223: return "and_expression"; break;
         case 233: return "exclusive_or_expression"; break;
         case 243: return "inclusive_or_expression"; break;
         case 253: return "logical_and_expression"; break;
         case 263: return "logical_or_expression"; break;
         case 273: return "conditional_expression"; break;
         case 285: return "assignment_expression"; break;
         case 295: return "expression"; break;
         case 305: return "constant_expression"; break;
         case 309: return "declaration"; break;
         case 320: return "declaration_specifiers"; break;
         case 347: return "init_declarator_list"; break;
         case 357: return "init_declarator"; break;
         case 367: return "storage_class_specifier"; break;
         case 387: return "type_specifier"; break;
         case 435: return "struct_or_union_specifier"; break;
         case 455: return "struct_or_union"; break;
         case 463: return "struct_declaration_list"; break;
         case 472: return "struct_declaration"; break;
         case 478: return "specifier_qualifier_list"; break;
         case 496: return "struct_declarator_list"; break;
         case 506: return "struct_declarator"; break;
         case 521: return "enum_specifier"; break;
         case 541: return "enumerator_list"; break;
         case 551: return "enumerator"; break;
         case 561: return "type_qualifier"; break;
         case 569: return "declarator"; break;
         case 578: return "direct_declarator"; break;
         case 621: return "pointer"; break;
         case 641: return "type_qualifier_list"; break;
         case 650: return "parameter_type_list"; break;
         case 660: return "parameter_list"; break;
         case 670: return "parameter_declaration"; break;
         case 684: return "identifier_list"; break;
         case 694: return "type_name"; break;
         case 703: return "abstract_declarator"; break;
         case 716: return "direct_abstract_declarator"; break;
         case 770: return "initializer"; break;
         case 787: return "initializer_list"; break;
         case 797: return "statement"; break;
         case 821: return "labeled_statement"; break;
         case 840: return "compound_statement"; break;
         case 864: return "declaration_list"; break;
         case 873: return "statement_list"; break;
         case 882: return "expression_statement"; break;
         case 891: return "selection_statement"; break;
         case 917: return "iteration_statement"; break;
         case 954: return "jump_statement"; break;
         case 981: return "root"; break;
         case 990: return "external_declaration"; break;
         case 998: return "function_definition"; break;
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
