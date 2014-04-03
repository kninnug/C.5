#line 6 "ass3.acc"

	#include <stdio.h>
	#include <stdlib.h>
	
	#include "parser.h"

# line 9 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 135: {
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
         case 136: {
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
      case 137: {
         declaration_specifiers();
         } break;
      default: ;
      }
      declarator();
      switch (yyselect()) {
      case 138: {
         declaration_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 139: {
         get_lexval();
         } break;
      case 140: {
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
      case 141: {
         init_declarator_list();
         } break;
      default: ;
      }
      get_lexval();
#line 35 "ass3.acc"
 fprintf(stderr, "Declarate!\n"); 
# line 95 "yygrammar.c"
      } break;
   }
}

declaration_list ()
{
   switch(yyselect()) {
   case 6: {
      while (1) {
         switch (yyselect()) {
         case 142: {
            declaration();
            } break;
         default: goto yy2;
         }
      }
      yy2: ;
      declaration();
      } break;
   }
}

declaration_specifiers ()
{
   switch(yyselect()) {
   case 7: {
      switch (yyselect()) {
      case 143: {
         storage_class_specifier();
         } break;
      case 144: {
         type_specifier();
         } break;
      case 145: {
         type_qualifier();
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 146: {
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
   case 8: {
      get_lexval();
      } break;
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
   }
}

type_specifier ()
{
   switch(yyselect()) {
   case 13: {
      get_lexval();
      } break;
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
      struct_or_union_specifier();
      } break;
   case 23: {
      enum_specifier();
      } break;
   }
}

type_qualifier ()
{
   switch(yyselect()) {
   case 24: {
      switch (yyselect()) {
      case 147: {
         get_lexval();
         } break;
      case 148: {
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
   case 25: {
      struct_or_union();
      switch (yyselect()) {
      case 149: {
         id(&i);
         } break;
      default: ;
      }
      get_lexval();
      struct_declaration_list();
      get_lexval();
      } break;
   case 26: {
      struct_or_union();
      id(&i);
#line 77 "ass3.acc"

# line 242 "yygrammar.c"
      } break;
   }
}

struct_or_union ()
{
   switch(yyselect()) {
   case 27: {
      switch (yyselect()) {
      case 150: {
         get_lexval();
         } break;
      case 151: {
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
   case 28: {
      switch (yyselect()) {
      case 152: {
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
   case 29: {
      switch (yyselect()) {
      case 153: {
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
   case 30: {
      switch (yyselect()) {
      case 154: {
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
   case 31: {
      specifier_qualifier_list();
      struct_declarator_list();
      get_lexval();
      } break;
   }
}

specifier_qualifier_list ()
{
   switch(yyselect()) {
   case 32: {
      switch (yyselect()) {
      case 155: {
         type_specifier();
         } break;
      case 156: {
         type_qualifier();
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 157: {
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
   case 33: {
      switch (yyselect()) {
      case 158: {
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
   case 34: {
      declarator();
      } break;
   case 35: {
      switch (yyselect()) {
      case 159: {
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
   case 36: {
      get_lexval();
      switch (yyselect()) {
      case 160: {
         id(&i);
         } break;
      default: ;
      }
      get_lexval();
      enumerator_list();
      get_lexval();
      } break;
   case 37: {
      get_lexval();
      id(&i);
      } break;
   }
}

enumerator_list ()
{
   switch(yyselect()) {
   case 38: {
      switch (yyselect()) {
      case 161: {
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
   case 39: {
      id(&i);
      switch (yyselect()) {
      case 162: {
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
   case 40: {
      switch (yyselect()) {
      case 163: {
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
   case 41: {
      id(&i);
      } break;
   case 42: {
      get_lexval();
      declarator();
      get_lexval();
      } break;
   case 43: {
      direct_declarator();
      switch (yyselect()) {
      case 165: {
         get_lexval();
         switch (yyselect()) {
         case 164: {
            expression(&e);
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 166: {
         get_lexval();
         parameter_type_list();
         get_lexval();
         } break;
      case 168: {
         get_lexval();
         switch (yyselect()) {
         case 167: {
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
   case 44: {
      get_lexval();
      switch (yyselect()) {
      case 169: {
         type_qualifier_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 170: {
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
   case 45: {
      switch (yyselect()) {
      case 171: {
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
   case 46: {
      parameter_list();
      switch (yyselect()) {
      case 172: {
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
   case 47: {
      switch (yyselect()) {
      case 173: {
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
   case 48: {
      declaration_specifiers();
      switch (yyselect()) {
      case 174: {
         declarator();
         } break;
      case 176: {
         switch (yyselect()) {
         case 175: {
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
   case 49: {
      switch (yyselect()) {
      case 177: {
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
   case 50: {
      assignment_expression(&ae);
      } break;
   case 51: {
      get_lexval();
      initializer_list();
      switch (yyselect()) {
      case 178: {
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
   case 52: {
      switch (yyselect()) {
      case 179: {
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
   case 53: {
      specifier_qualifier_list();
      switch (yyselect()) {
      case 180: {
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
   case 54: {
      pointer();
      } break;
   case 55: {
      switch (yyselect()) {
      case 181: {
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
   case 56: {
      get_lexval();
      abstract_declarator();
      get_lexval();
      } break;
   case 57: {
      switch (yyselect()) {
      case 182: {
         direct_abstract_declarator();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 184: {
         get_lexval();
         switch (yyselect()) {
         case 183: {
            expression(&e);
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 186: {
         get_lexval();
         switch (yyselect()) {
         case 185: {
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
   case 58: {
      id(&i);
      } break;
   }
}

statement ()
{
   switch(yyselect()) {
   case 59: {
      labeled_statement();
#line 191 "ass3.acc"
 fprintf(stderr, "Label!\n"); 
# line 738 "yygrammar.c"
      } break;
   case 60: {
      expression_statement();
#line 192 "ass3.acc"
 fprintf(stderr, "Express!\n"); 
# line 744 "yygrammar.c"
      } break;
   case 61: {
      compound_statement();
#line 193 "ass3.acc"
 fprintf(stderr, "Confound!\n"); 
# line 750 "yygrammar.c"
      } break;
   case 62: {
      selection_statement();
#line 194 "ass3.acc"
 fprintf(stderr, "Select!\n"); 
# line 756 "yygrammar.c"
      } break;
   case 63: {
      iteration_statement();
#line 195 "ass3.acc"
 fprintf(stderr, "Iterate!\n"); 
# line 762 "yygrammar.c"
      } break;
   case 64: {
      jump_statement();
#line 196 "ass3.acc"
 fprintf(stderr, "Jump!\n"); 
# line 768 "yygrammar.c"
      } break;
   case 65: {
      print_statement();
#line 197 "ass3.acc"
 fprintf(stderr, "Print!\n"); 
# line 774 "yygrammar.c"
      } break;
   case 66: {
      input_statement();
#line 198 "ass3.acc"
 fprintf(stderr, "Input!\n"); 
# line 780 "yygrammar.c"
      } break;
   }
}

labeled_statement ()
{
   constant_pt i;
   expression_pt ce;
   switch(yyselect()) {
   case 67: {
      id(&i);
      get_lexval();
      statement();
      } break;
   case 68: {
      get_lexval();
      constant_expression(&ce);
      get_lexval();
      statement();
      } break;
   case 69: {
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
   case 70: {
      switch (yyselect()) {
      case 187: {
         expression(&e);
#line 208 "ass3.acc"
 printExpression(e, 0); 
# line 819 "yygrammar.c"
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
   case 71: {
      get_lexval();
      switch (yyselect()) {
      case 188: {
         declaration_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 189: {
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
   case 72: {
      while (1) {
         switch (yyselect()) {
         case 190: {
            statement();
            } break;
         default: goto yy3;
         }
      }
      yy3: ;
      statement();
      } break;
   }
}

selection_statement ()
{
   expression_pt e;
   switch(yyselect()) {
   case 73: {
      get_lexval();
      get_lexval();
      expression(&e);
      get_lexval();
      statement();
      switch (yyselect()) {
      case 191: {
         get_lexval();
         statement();
         } break;
      default: ;
      }
      } break;
   case 74: {
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
   case 75: {
      get_lexval();
      get_lexval();
      expression(&e);
      get_lexval();
      statement();
      } break;
   case 76: {
      get_lexval();
      statement();
      get_lexval();
      get_lexval();
      expression(&e);
      get_lexval();
      get_lexval();
      } break;
   case 77: {
      get_lexval();
      get_lexval();
      switch (yyselect()) {
      case 192: {
         expression(&e);
         } break;
      default: ;
      }
      get_lexval();
      switch (yyselect()) {
      case 193: {
         expression(&e);
         } break;
      default: ;
      }
      get_lexval();
      switch (yyselect()) {
      case 194: {
         expression(&e);
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
   constant_pt i;
   expression_pt e;
   switch(yyselect()) {
   case 78: {
      get_lexval();
      id(&i);
      get_lexval();
      } break;
   case 79: {
      get_lexval();
      get_lexval();
      } break;
   case 80: {
      get_lexval();
      get_lexval();
      } break;
   case 81: {
      get_lexval();
      switch (yyselect()) {
      case 195: {
         expression(&e);
#line 239 "ass3.acc"
 printExpression(e, 0); 
# line 970 "yygrammar.c"
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
   case 82: {
      get_lexval();
      argument_expression_list(&ae);
      get_lexval();
      } break;
   }
}

input_statement ()
{
   constant_pt i;
   switch(yyselect()) {
   case 83: {
      get_lexval();
      while (1) {
         switch (yyselect()) {
         case 196: {
            id(&i);
            get_lexval();
            } break;
         default: goto yy4;
         }
      }
      yy4: ;
      id(&i);
      get_lexval();
      } break;
   }
}

expression (ret)
   expression_pt *ret;
{
   expression_pt ae;
   expression_pt e;
   switch(yyselect()) {
   case 84: {
      assignment_expression(&ae);
#line 251 "ass3.acc"
 *ret = ae; 
# line 1023 "yygrammar.c"
      } break;
   case 85: {
      expression(&e);
      get_lexval();
      assignment_expression(&ae);
#line 252 "ass3.acc"
 *ret = makeExpression(1, 2, ',', e, ae); 
# line 1031 "yygrammar.c"
      } break;
   }
}

assignment_expression (ret)
   expression_pt *ret;
{
   expression_pt ce;
   expression_pt ue;
   int ao;
   expression_pt ae;
   switch(yyselect()) {
   case 86: {
      conditional_expression(&ce);
#line 256 "ass3.acc"
 *ret = ce; 
# line 1048 "yygrammar.c"
      } break;
   case 87: {
      unary_expression(&ue);
      assignment_operator(&ao);
      assignment_expression(&ae);
#line 257 "ass3.acc"
 *ret = makeExpression(1, 2, ao, ue, ae); 
# line 1056 "yygrammar.c"
      } break;
   }
}

assignment_operator (ret)
   int *ret;
{
   switch(yyselect()) {
   case 88: {
      get_lexval();
#line 261 "ass3.acc"
 *ret = yylval.subtype; 
# line 1069 "yygrammar.c"
      } break;
   case 89: {
      get_lexval();
#line 262 "ass3.acc"
 *ret = '='; 
# line 1075 "yygrammar.c"
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
   case 90: {
      logical_OR_expression(&loe);
#line 266 "ass3.acc"
 *ret = loe; 
# line 1091 "yygrammar.c"
      } break;
   case 91: {
      logical_OR_expression(&loe);
      get_lexval();
      expression(&e);
      get_lexval();
      conditional_expression(&ce);
#line 267 "ass3.acc"
 *ret = makeExpression(1, 3, '?', loe, e, ce); 
# line 1101 "yygrammar.c"
      } break;
   }
}

constant_expression (ret)
   expression_pt *ret;
{
   expression_pt ce;
   switch(yyselect()) {
   case 92: {
      conditional_expression(&ce);
#line 271 "ass3.acc"
 *ret = ce; 
# line 1115 "yygrammar.c"
      } break;
   }
}

logical_OR_expression (ret)
   expression_pt *ret;
{
   expression_pt lae;
   expression_pt loe;
   switch(yyselect()) {
   case 93: {
      logical_AND_expression(&lae);
#line 275 "ass3.acc"
 *ret = lae; 
# line 1130 "yygrammar.c"
      } break;
   case 94: {
      logical_OR_expression(&loe);
      get_lexval();
      logical_AND_expression(&lae);
#line 276 "ass3.acc"
 *ret = makeExpression(1, 2, '||', loe, lae); 
# line 1138 "yygrammar.c"
      } break;
   }
}

logical_AND_expression (ret)
   expression_pt *ret;
{
   expression_pt ioe;
   expression_pt lae;
   switch(yyselect()) {
   case 95: {
      inclusive_OR_expression(&ioe);
#line 280 "ass3.acc"
 *ret = ioe; 
# line 1153 "yygrammar.c"
      } break;
   case 96: {
      logical_AND_expression(&lae);
      get_lexval();
      inclusive_OR_expression(&ioe);
#line 281 "ass3.acc"
 *ret = makeExpression(1, 2, '&&', lae, ioe); 
# line 1161 "yygrammar.c"
      } break;
   }
}

inclusive_OR_expression (ret)
   expression_pt *ret;
{
   expression_pt eoe;
   expression_pt ioe;
   switch(yyselect()) {
   case 97: {
      exclusive_OR_expression(&eoe);
#line 285 "ass3.acc"
 *ret = eoe; 
# line 1176 "yygrammar.c"
      } break;
   case 98: {
      inclusive_OR_expression(&ioe);
      get_lexval();
      exclusive_OR_expression(&eoe);
#line 286 "ass3.acc"
 *ret = makeExpression(1, 2, '|', ioe, eoe); 
# line 1184 "yygrammar.c"
      } break;
   }
}

exclusive_OR_expression (ret)
   expression_pt *ret;
{
   expression_pt ae;
   expression_pt eoe;
   switch(yyselect()) {
   case 99: {
      AND_expression(&ae);
#line 290 "ass3.acc"
 *ret = ae; 
# line 1199 "yygrammar.c"
      } break;
   case 100: {
      exclusive_OR_expression(&eoe);
      get_lexval();
      AND_expression(&ae);
#line 291 "ass3.acc"
 *ret = makeExpression(1, 2, '^', eoe, ae); 
# line 1207 "yygrammar.c"
      } break;
   }
}

AND_expression (ret)
   expression_pt *ret;
{
   expression_pt ee;
   expression_pt ae;
   switch(yyselect()) {
   case 101: {
      equality_expression(&ee);
#line 295 "ass3.acc"
 *ret = ee; 
# line 1222 "yygrammar.c"
      } break;
   case 102: {
      AND_expression(&ae);
      get_lexval();
      equality_expression(&ee);
#line 296 "ass3.acc"
 *ret = makeExpression(1, 2, '&', ae, ee); 
# line 1230 "yygrammar.c"
      } break;
   }
}

equality_expression (ret)
   expression_pt *ret;
{
   expression_pt se;
   expression_pt ee;
   YYSTYPE c;
   switch(yyselect()) {
   case 103: {
      shift_expression(&se);
#line 300 "ass3.acc"
 *ret = se; 
# line 1246 "yygrammar.c"
      } break;
   case 104: {
      equality_expression(&ee);
      get_lexval();
      c = yylval;
      shift_expression(&se);
#line 301 "ass3.acc"
 *ret = makeExpression(1, 2, c.subtype, ee, se); 
# line 1255 "yygrammar.c"
      } break;
   }
}

shift_expression (ret)
   expression_pt *ret;
{
   expression_pt ae;
   expression_pt se;
   YYSTYPE s;
   switch(yyselect()) {
   case 105: {
      additive_expression(&ae);
#line 305 "ass3.acc"
 *ret = ae; 
# line 1271 "yygrammar.c"
      } break;
   case 106: {
      shift_expression(&se);
      get_lexval();
      s = yylval;
      additive_expression(&ae);
#line 306 "ass3.acc"
 *ret = makeExpression(1, 2, s.subtype, se, ae); 
# line 1280 "yygrammar.c"
      } break;
   }
}

additive_expression (ret)
   expression_pt *ret;
{
   expression_pt me;
   expression_pt ae;
   switch(yyselect()) {
   case 107: {
      multiplicative_expression(&me);
#line 310 "ass3.acc"
 *ret = me; 
# line 1295 "yygrammar.c"
      } break;
   case 108: {
#line 311 "ass3.acc"
 int op = '+'; 
# line 1300 "yygrammar.c"
      additive_expression(&ae);
      switch (yyselect()) {
      case 197: {
         get_lexval();
         } break;
      case 198: {
         get_lexval();
#line 311 "ass3.acc"
 op = '-'; 
# line 1310 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      multiplicative_expression(&me);
#line 311 "ass3.acc"
 *ret = makeExpression(1, 2, op, ae, me); 
# line 1317 "yygrammar.c"
      } break;
   }
}

multiplicative_expression (ret)
   expression_pt *ret;
{
   expression_pt ce;
   expression_pt me;
   switch(yyselect()) {
   case 109: {
      cast_expression(&ce);
#line 315 "ass3.acc"
 *ret = ce; 
# line 1332 "yygrammar.c"
      } break;
   case 110: {
#line 316 "ass3.acc"
 int op = '*'; 
# line 1337 "yygrammar.c"
      multiplicative_expression(&me);
      switch (yyselect()) {
      case 199: {
         get_lexval();
         } break;
      case 200: {
         get_lexval();
#line 316 "ass3.acc"
 op = '/'; 
# line 1347 "yygrammar.c"
         } break;
      case 201: {
         get_lexval();
#line 316 "ass3.acc"
 op = '%'; 
# line 1353 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      cast_expression(&ce);
#line 316 "ass3.acc"
 *ret = makeExpression(1, 2, op, me, ce); 
# line 1360 "yygrammar.c"
      } break;
   }
}

cast_expression (ret)
   expression_pt *ret;
{
   expression_pt ue;
   expression_pt ce;
   switch(yyselect()) {
   case 111: {
      unary_expression(&ue);
#line 320 "ass3.acc"
 *ret =  ue; 
# line 1375 "yygrammar.c"
      } break;
   case 112: {
      get_lexval();
      type_name();
      get_lexval();
      cast_expression(&ce);
#line 321 "ass3.acc"
 *ret = ce; 
# line 1384 "yygrammar.c"
      } break;
   }
}

unary_expression (ret)
   expression_pt *ret;
{
   expression_pt pe;
   expression_pt ue;
   int op;
   expression_pt ce;
   switch(yyselect()) {
   case 113: {
      postfix_expression(&pe);
#line 325 "ass3.acc"
 *ret = pe; 
# line 1401 "yygrammar.c"
      } break;
   case 114: {
#line 326 "ass3.acc"
 int t; 
# line 1406 "yygrammar.c"
      switch (yyselect()) {
      case 202: {
         get_lexval();
#line 326 "ass3.acc"
t = '++x';
# line 1412 "yygrammar.c"
         } break;
      case 203: {
         get_lexval();
#line 326 "ass3.acc"
t = '--x'; 
# line 1418 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      unary_expression(&ue);
#line 326 "ass3.acc"
 *ret = makeExpression(1, 1, t, ue); 
# line 1425 "yygrammar.c"
      } break;
   case 115: {
      unary_operator(&op);
      cast_expression(&ce);
#line 327 "ass3.acc"
 *ret = makeExpression(1, 1, op, ce); 
# line 1432 "yygrammar.c"
      } break;
   case 116: {
      get_lexval();
      unary_expression(&ue);
#line 328 "ass3.acc"
 *ret = ue; 
# line 1439 "yygrammar.c"
      } break;
   case 117: {
      get_lexval();
      get_lexval();
      type_name();
      get_lexval();
      } break;
   }
}

unary_operator (op)
   int *op;
{
   switch(yyselect()) {
   case 118: {
      get_lexval();
#line 333 "ass3.acc"
 *op = '&'; 
# line 1458 "yygrammar.c"
      } break;
   case 119: {
      get_lexval();
#line 334 "ass3.acc"
 *op = '*'; 
# line 1464 "yygrammar.c"
      } break;
   case 120: {
      get_lexval();
#line 335 "ass3.acc"
 *op = '+'; 
# line 1470 "yygrammar.c"
      } break;
   case 121: {
      get_lexval();
#line 336 "ass3.acc"
 *op = '-'; 
# line 1476 "yygrammar.c"
      } break;
   case 122: {
      get_lexval();
#line 337 "ass3.acc"
 *op = '~'; 
# line 1482 "yygrammar.c"
      } break;
   case 123: {
      get_lexval();
#line 338 "ass3.acc"
 *op = '!'; 
# line 1488 "yygrammar.c"
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
   case 124: {
      primary_expression(&pe);
#line 342 "ass3.acc"
 *ret = pe; 
# line 1505 "yygrammar.c"
      } break;
   case 125: {
      postfix_expression(&pe);
#line 343 "ass3.acc"
 *ret = makeExpression(1, 1, 0, pe); fprintf(stderr, "@ PE: "); printExpression(*ret, 0); 
# line 1511 "yygrammar.c"
      switch (yyselect()) {
      case 205: {
         get_lexval();
         expression(&e);
#line 344 "ass3.acc"
 appendExpression(*ret, e); 
# line 1518 "yygrammar.c"
         switch (yyselect()) {
         case 204: {
            get_lexval();
            expression(&e);
#line 344 "ass3.acc"
 appendExpression(*ret, e); 
# line 1525 "yygrammar.c"
            } break;
         default: ;
         }
         get_lexval();
#line 344 "ass3.acc"
 (*ret)->operator = '[]'; 
# line 1532 "yygrammar.c"
         } break;
      case 207: {
         get_lexval();
         switch (yyselect()) {
         case 206: {
            argument_expression_list(&ae);
#line 345 "ass3.acc"
 appendExpression(*ret, ae); 
# line 1541 "yygrammar.c"
            } break;
         default: ;
         }
         get_lexval();
#line 345 "ass3.acc"
 (*ret)->operator = '()'; 
# line 1548 "yygrammar.c"
         } break;
      case 208: {
         get_lexval();
         id(&i);
#line 346 "ass3.acc"
 appendExpression(*ret, makeExpression(0, 1, 0, i)); (*ret)->operator = '.'; 
# line 1555 "yygrammar.c"
         } break;
      case 209: {
         get_lexval();
         id(&i);
#line 347 "ass3.acc"
 appendExpression(*ret, makeExpression(0, 1, 0, i)); (*ret)->operator = '->'; 
# line 1562 "yygrammar.c"
         } break;
      case 210: {
         get_lexval();
#line 348 "ass3.acc"
 (*ret)->operator = 'x++'; 
# line 1568 "yygrammar.c"
         } break;
      case 211: {
         get_lexval();
#line 349 "ass3.acc"
 (*ret)->operator = 'x--'; 
# line 1574 "yygrammar.c"
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
   case 126: {
      id(&i);
#line 354 "ass3.acc"
 *ret = makeExpression(0, 1, 0, i); 
# line 1593 "yygrammar.c"
      } break;
   case 127: {
      constant(&c);
#line 355 "ass3.acc"
 *ret = makeExpression(0, 1, 0, c); 
# line 1599 "yygrammar.c"
      } break;
   case 128: {
      get_lexval();
      expression(&e);
      get_lexval();
#line 356 "ass3.acc"
 *ret = e; 
# line 1607 "yygrammar.c"
      } break;
   }
}

argument_expression_list (ret)
   expression_pt *ret;
{
   expression_pt ae;
   expression_pt ae2;
   switch(yyselect()) {
   case 129: {
#line 360 "ass3.acc"
 *ret = makeExpression(1, 0, '(,)'); 
# line 1621 "yygrammar.c"
      while (1) {
         switch (yyselect()) {
         case 212: {
            assignment_expression(&ae);
#line 360 "ass3.acc"
 appendExpression(*ret, ae); 
# line 1628 "yygrammar.c"
            get_lexval();
            } break;
         default: goto yy5;
         }
      }
      yy5: ;
      assignment_expression(&ae2);
#line 360 "ass3.acc"
 appendExpression(*ret, ae2); 
# line 1638 "yygrammar.c"
      } break;
   }
}

constant (ret)
   constant_pt *ret;
{
   switch(yyselect()) {
   case 130: {
      get_lexval();
#line 364 "ass3.acc"
 *ret = makeIntConst(yylval.i); 
# line 1651 "yygrammar.c"
      } break;
   case 131: {
      get_lexval();
#line 365 "ass3.acc"
 *ret = makeIntConst(yylval.i); 
# line 1657 "yygrammar.c"
      } break;
   case 132: {
      get_lexval();
#line 366 "ass3.acc"
 *ret = makeFloatConst(yylval.d); 
# line 1663 "yygrammar.c"
      } break;
   case 133: {
      get_lexval();
#line 367 "ass3.acc"
 *ret = makeStringConst(yylval.s); 
# line 1669 "yygrammar.c"
      } break;
   }
}

id (ret)
   constant_pt *ret;
{
   switch(yyselect()) {
   case 134: {
      get_lexval();
#line 372 "ass3.acc"
 *ret = makeStringConst(yylval.s); (*ret)->type = IDCONST; 
# line 1682 "yygrammar.c"
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
int c_length = 1159;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 135,
/* 6 */ 0,
/* 7 */ 10,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 15,
/* 11 */ 18,
/* 12 */ 10,
/* 13 */ -10,
/* 14 */ 136,
/* 15 */ 0,
/* 16 */ -10,
/* 17 */ 213,
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
/* 28 */ 353,
/* 29 */ 40,
/* 30 */ 47,
/* 31 */ -26,
/* 32 */ 4,
/* 33 */ 37,
/* 34 */ 81,
/* 35 */ -33,
/* 36 */ 137,
/* 37 */ 0,
/* 38 */ -33,
/* 39 */ 214,
/* 40 */ 44,
/* 41 */ 68,
/* 42 */ -40,
/* 43 */ 138,
/* 44 */ 0,
/* 45 */ -40,
/* 46 */ 215,
/* 47 */ 51,
/* 48 */ 50059,
/* 49 */ -47,
/* 50 */ 139,
/* 51 */ 0,
/* 52 */ 673,
/* 53 */ -47,
/* 54 */ 140,
/* 55 */ 0,
/* 56 */ 81,
/* 57 */ 61,
/* 58 */ 50059,
/* 59 */ -55,
/* 60 */ 5,
/* 61 */ 65,
/* 62 */ 225,
/* 63 */ -61,
/* 64 */ 141,
/* 65 */ 0,
/* 66 */ -61,
/* 67 */ 216,
/* 68 */ 0,
/* 69 */ 73,
/* 70 */ 55,
/* 71 */ -68,
/* 72 */ 6,
/* 73 */ 78,
/* 74 */ 55,
/* 75 */ 73,
/* 76 */ -73,
/* 77 */ 142,
/* 78 */ 0,
/* 79 */ -73,
/* 80 */ 217,
/* 81 */ 0,
/* 82 */ 86,
/* 83 */ 98,
/* 84 */ -81,
/* 85 */ 7,
/* 86 */ 90,
/* 87 */ 105,
/* 88 */ -86,
/* 89 */ 143,
/* 90 */ 94,
/* 91 */ 125,
/* 92 */ -86,
/* 93 */ 144,
/* 94 */ 0,
/* 95 */ 169,
/* 96 */ -86,
/* 97 */ 145,
/* 98 */ 102,
/* 99 */ 81,
/* 100 */ -98,
/* 101 */ 146,
/* 102 */ 0,
/* 103 */ -98,
/* 104 */ 218,
/* 105 */ 109,
/* 106 */ 50256,
/* 107 */ -105,
/* 108 */ 8,
/* 109 */ 113,
/* 110 */ 50274,
/* 111 */ -105,
/* 112 */ 9,
/* 113 */ 117,
/* 114 */ 50279,
/* 115 */ -105,
/* 116 */ 10,
/* 117 */ 121,
/* 118 */ 50267,
/* 119 */ -105,
/* 120 */ 11,
/* 121 */ 0,
/* 122 */ 50282,
/* 123 */ -105,
/* 124 */ 12,
/* 125 */ 129,
/* 126 */ 50285,
/* 127 */ -125,
/* 128 */ 13,
/* 129 */ 133,
/* 130 */ 50259,
/* 131 */ -125,
/* 132 */ 14,
/* 133 */ 137,
/* 134 */ 50276,
/* 135 */ -125,
/* 136 */ 15,
/* 137 */ 141,
/* 138 */ 50272,
/* 139 */ -125,
/* 140 */ 16,
/* 141 */ 145,
/* 142 */ 50273,
/* 143 */ -125,
/* 144 */ 17,
/* 145 */ 149,
/* 146 */ 50268,
/* 147 */ -125,
/* 148 */ 18,
/* 149 */ 153,
/* 150 */ 50264,
/* 151 */ -125,
/* 152 */ 19,
/* 153 */ 157,
/* 154 */ 50277,
/* 155 */ -125,
/* 156 */ 20,
/* 157 */ 161,
/* 158 */ 50284,
/* 159 */ -125,
/* 160 */ 21,
/* 161 */ 165,
/* 162 */ 181,
/* 163 */ -125,
/* 164 */ 22,
/* 165 */ 0,
/* 166 */ 307,
/* 167 */ -125,
/* 168 */ 23,
/* 169 */ 0,
/* 170 */ 173,
/* 171 */ -169,
/* 172 */ 24,
/* 173 */ 177,
/* 174 */ 50260,
/* 175 */ -173,
/* 176 */ 147,
/* 177 */ 0,
/* 178 */ 50286,
/* 179 */ -173,
/* 180 */ 148,
/* 181 */ 189,
/* 182 */ 201,
/* 183 */ 194,
/* 184 */ 50123,
/* 185 */ 213,
/* 186 */ 50125,
/* 187 */ -181,
/* 188 */ 25,
/* 189 */ 0,
/* 190 */ 201,
/* 191 */ 1156,
/* 192 */ -181,
/* 193 */ 26,
/* 194 */ 198,
/* 195 */ 1156,
/* 196 */ -194,
/* 197 */ 149,
/* 198 */ 0,
/* 199 */ -194,
/* 200 */ 219,
/* 201 */ 0,
/* 202 */ 205,
/* 203 */ -201,
/* 204 */ 27,
/* 205 */ 209,
/* 206 */ 50280,
/* 207 */ -205,
/* 208 */ 150,
/* 209 */ 0,
/* 210 */ 50283,
/* 211 */ -205,
/* 212 */ 151,
/* 213 */ 0,
/* 214 */ 218,
/* 215 */ 251,
/* 216 */ -213,
/* 217 */ 28,
/* 218 */ 222,
/* 219 */ 213,
/* 220 */ -218,
/* 221 */ 152,
/* 222 */ 0,
/* 223 */ -218,
/* 224 */ 220,
/* 225 */ 0,
/* 226 */ 230,
/* 227 */ 238,
/* 228 */ -225,
/* 229 */ 29,
/* 230 */ 235,
/* 231 */ 225,
/* 232 */ 50044,
/* 233 */ -230,
/* 234 */ 153,
/* 235 */ 0,
/* 236 */ -230,
/* 237 */ 221,
/* 238 */ 0,
/* 239 */ 243,
/* 240 */ 503,
/* 241 */ -238,
/* 242 */ 30,
/* 243 */ 248,
/* 244 */ 353,
/* 245 */ 50061,
/* 246 */ -243,
/* 247 */ 154,
/* 248 */ 0,
/* 249 */ -243,
/* 250 */ 222,
/* 251 */ 0,
/* 252 */ 257,
/* 253 */ 277,
/* 254 */ 50059,
/* 255 */ -251,
/* 256 */ 31,
/* 257 */ 0,
/* 258 */ 262,
/* 259 */ 270,
/* 260 */ -257,
/* 261 */ 32,
/* 262 */ 266,
/* 263 */ 125,
/* 264 */ -262,
/* 265 */ 155,
/* 266 */ 0,
/* 267 */ 169,
/* 268 */ -262,
/* 269 */ 156,
/* 270 */ 274,
/* 271 */ 257,
/* 272 */ -270,
/* 273 */ 157,
/* 274 */ 0,
/* 275 */ -270,
/* 276 */ 223,
/* 277 */ 0,
/* 278 */ 282,
/* 279 */ 290,
/* 280 */ -277,
/* 281 */ 33,
/* 282 */ 287,
/* 283 */ 277,
/* 284 */ 50044,
/* 285 */ -282,
/* 286 */ 158,
/* 287 */ 0,
/* 288 */ -282,
/* 289 */ 224,
/* 290 */ 294,
/* 291 */ 353,
/* 292 */ -290,
/* 293 */ 34,
/* 294 */ 0,
/* 295 */ 300,
/* 296 */ 50058,
/* 297 */ 874,
/* 298 */ -290,
/* 299 */ 35,
/* 300 */ 304,
/* 301 */ 353,
/* 302 */ -300,
/* 303 */ 159,
/* 304 */ 0,
/* 305 */ -300,
/* 306 */ 225,
/* 307 */ 315,
/* 308 */ 50266,
/* 309 */ 320,
/* 310 */ 50123,
/* 311 */ 327,
/* 312 */ 50125,
/* 313 */ -307,
/* 314 */ 36,
/* 315 */ 0,
/* 316 */ 50266,
/* 317 */ 1156,
/* 318 */ -307,
/* 319 */ 37,
/* 320 */ 324,
/* 321 */ 1156,
/* 322 */ -320,
/* 323 */ 160,
/* 324 */ 0,
/* 325 */ -320,
/* 326 */ 226,
/* 327 */ 0,
/* 328 */ 332,
/* 329 */ 340,
/* 330 */ -327,
/* 331 */ 38,
/* 332 */ 337,
/* 333 */ 327,
/* 334 */ 50044,
/* 335 */ -332,
/* 336 */ 161,
/* 337 */ 0,
/* 338 */ -332,
/* 339 */ 227,
/* 340 */ 0,
/* 341 */ 1156,
/* 342 */ 345,
/* 343 */ -340,
/* 344 */ 39,
/* 345 */ 350,
/* 346 */ 50061,
/* 347 */ 874,
/* 348 */ -345,
/* 349 */ 162,
/* 350 */ 0,
/* 351 */ -345,
/* 352 */ 228,
/* 353 */ 0,
/* 354 */ 358,
/* 355 */ 365,
/* 356 */ -353,
/* 357 */ 40,
/* 358 */ 362,
/* 359 */ 412,
/* 360 */ -358,
/* 361 */ 163,
/* 362 */ 0,
/* 363 */ -358,
/* 364 */ 229,
/* 365 */ 369,
/* 366 */ 1156,
/* 367 */ -365,
/* 368 */ 41,
/* 369 */ 375,
/* 370 */ 50040,
/* 371 */ 353,
/* 372 */ 50041,
/* 373 */ -365,
/* 374 */ 42,
/* 375 */ 0,
/* 376 */ 365,
/* 377 */ 380,
/* 378 */ -365,
/* 379 */ 43,
/* 380 */ 386,
/* 381 */ 50091,
/* 382 */ 398,
/* 383 */ 50093,
/* 384 */ -380,
/* 385 */ 165,
/* 386 */ 392,
/* 387 */ 50040,
/* 388 */ 444,
/* 389 */ 50041,
/* 390 */ -380,
/* 391 */ 166,
/* 392 */ 0,
/* 393 */ 50040,
/* 394 */ 405,
/* 395 */ 50041,
/* 396 */ -380,
/* 397 */ 168,
/* 398 */ 402,
/* 399 */ 834,
/* 400 */ -398,
/* 401 */ 164,
/* 402 */ 0,
/* 403 */ -398,
/* 404 */ 230,
/* 405 */ 409,
/* 406 */ 490,
/* 407 */ -405,
/* 408 */ 167,
/* 409 */ 0,
/* 410 */ -405,
/* 411 */ 231,
/* 412 */ 0,
/* 413 */ 50042,
/* 414 */ 418,
/* 415 */ 425,
/* 416 */ -412,
/* 417 */ 44,
/* 418 */ 422,
/* 419 */ 432,
/* 420 */ -418,
/* 421 */ 169,
/* 422 */ 0,
/* 423 */ -418,
/* 424 */ 232,
/* 425 */ 429,
/* 426 */ 412,
/* 427 */ -425,
/* 428 */ 170,
/* 429 */ 0,
/* 430 */ -425,
/* 431 */ 233,
/* 432 */ 0,
/* 433 */ 437,
/* 434 */ 169,
/* 435 */ -432,
/* 436 */ 45,
/* 437 */ 441,
/* 438 */ 432,
/* 439 */ -437,
/* 440 */ 171,
/* 441 */ 0,
/* 442 */ -437,
/* 443 */ 234,
/* 444 */ 0,
/* 445 */ 457,
/* 446 */ 449,
/* 447 */ -444,
/* 448 */ 46,
/* 449 */ 454,
/* 450 */ 50044,
/* 451 */ 50290,
/* 452 */ -449,
/* 453 */ 172,
/* 454 */ 0,
/* 455 */ -449,
/* 456 */ 235,
/* 457 */ 0,
/* 458 */ 462,
/* 459 */ 470,
/* 460 */ -457,
/* 461 */ 47,
/* 462 */ 467,
/* 463 */ 457,
/* 464 */ 50044,
/* 465 */ -462,
/* 466 */ 173,
/* 467 */ 0,
/* 468 */ -462,
/* 469 */ 236,
/* 470 */ 0,
/* 471 */ 81,
/* 472 */ 475,
/* 473 */ -470,
/* 474 */ 48,
/* 475 */ 479,
/* 476 */ 353,
/* 477 */ -475,
/* 478 */ 174,
/* 479 */ 0,
/* 480 */ 483,
/* 481 */ -475,
/* 482 */ 176,
/* 483 */ 487,
/* 484 */ 546,
/* 485 */ -483,
/* 486 */ 175,
/* 487 */ 0,
/* 488 */ -483,
/* 489 */ 237,
/* 490 */ 0,
/* 491 */ 495,
/* 492 */ 1156,
/* 493 */ -490,
/* 494 */ 49,
/* 495 */ 500,
/* 496 */ 490,
/* 497 */ 50044,
/* 498 */ -495,
/* 499 */ 177,
/* 500 */ 0,
/* 501 */ -495,
/* 502 */ 238,
/* 503 */ 507,
/* 504 */ 844,
/* 505 */ -503,
/* 506 */ 50,
/* 507 */ 0,
/* 508 */ 50123,
/* 509 */ 521,
/* 510 */ 514,
/* 511 */ 50125,
/* 512 */ -503,
/* 513 */ 51,
/* 514 */ 518,
/* 515 */ 50044,
/* 516 */ -514,
/* 517 */ 178,
/* 518 */ 0,
/* 519 */ -514,
/* 520 */ 239,
/* 521 */ 0,
/* 522 */ 526,
/* 523 */ 503,
/* 524 */ -521,
/* 525 */ 52,
/* 526 */ 531,
/* 527 */ 521,
/* 528 */ 50044,
/* 529 */ -526,
/* 530 */ 179,
/* 531 */ 0,
/* 532 */ -526,
/* 533 */ 240,
/* 534 */ 0,
/* 535 */ 257,
/* 536 */ 539,
/* 537 */ -534,
/* 538 */ 53,
/* 539 */ 543,
/* 540 */ 546,
/* 541 */ -539,
/* 542 */ 180,
/* 543 */ 0,
/* 544 */ -539,
/* 545 */ 241,
/* 546 */ 550,
/* 547 */ 412,
/* 548 */ -546,
/* 549 */ 54,
/* 550 */ 0,
/* 551 */ 555,
/* 552 */ 562,
/* 553 */ -546,
/* 554 */ 55,
/* 555 */ 559,
/* 556 */ 412,
/* 557 */ -555,
/* 558 */ 181,
/* 559 */ 0,
/* 560 */ -555,
/* 561 */ 242,
/* 562 */ 568,
/* 563 */ 50040,
/* 564 */ 546,
/* 565 */ 50041,
/* 566 */ -562,
/* 567 */ 56,
/* 568 */ 0,
/* 569 */ 573,
/* 570 */ 580,
/* 571 */ -562,
/* 572 */ 57,
/* 573 */ 577,
/* 574 */ 562,
/* 575 */ -573,
/* 576 */ 182,
/* 577 */ 0,
/* 578 */ -573,
/* 579 */ 243,
/* 580 */ 586,
/* 581 */ 50091,
/* 582 */ 592,
/* 583 */ 50093,
/* 584 */ -580,
/* 585 */ 184,
/* 586 */ 0,
/* 587 */ 50040,
/* 588 */ 599,
/* 589 */ 50041,
/* 590 */ -580,
/* 591 */ 186,
/* 592 */ 596,
/* 593 */ 834,
/* 594 */ -592,
/* 595 */ 183,
/* 596 */ 0,
/* 597 */ -592,
/* 598 */ 244,
/* 599 */ 603,
/* 600 */ 444,
/* 601 */ -599,
/* 602 */ 185,
/* 603 */ 0,
/* 604 */ -599,
/* 605 */ 245,
/* 606 */ 0,
/* 607 */ 1156,
/* 608 */ -606,
/* 609 */ 58,
/* 610 */ 614,
/* 611 */ 642,
/* 612 */ -610,
/* 613 */ 59,
/* 614 */ 618,
/* 615 */ 661,
/* 616 */ -610,
/* 617 */ 60,
/* 618 */ 622,
/* 619 */ 673,
/* 620 */ -610,
/* 621 */ 61,
/* 622 */ 626,
/* 623 */ 707,
/* 624 */ -610,
/* 625 */ 62,
/* 626 */ 630,
/* 627 */ 732,
/* 628 */ -610,
/* 629 */ 63,
/* 630 */ 634,
/* 631 */ 783,
/* 632 */ -610,
/* 633 */ 64,
/* 634 */ 638,
/* 635 */ 812,
/* 636 */ -610,
/* 637 */ 65,
/* 638 */ 0,
/* 639 */ 818,
/* 640 */ -610,
/* 641 */ 66,
/* 642 */ 648,
/* 643 */ 1156,
/* 644 */ 50058,
/* 645 */ 610,
/* 646 */ -642,
/* 647 */ 67,
/* 648 */ 655,
/* 649 */ 50258,
/* 650 */ 874,
/* 651 */ 50058,
/* 652 */ 610,
/* 653 */ -642,
/* 654 */ 68,
/* 655 */ 0,
/* 656 */ 50262,
/* 657 */ 50058,
/* 658 */ 610,
/* 659 */ -642,
/* 660 */ 69,
/* 661 */ 0,
/* 662 */ 666,
/* 663 */ 50059,
/* 664 */ -661,
/* 665 */ 70,
/* 666 */ 670,
/* 667 */ 834,
/* 668 */ -666,
/* 669 */ 187,
/* 670 */ 0,
/* 671 */ -666,
/* 672 */ 246,
/* 673 */ 0,
/* 674 */ 50123,
/* 675 */ 680,
/* 676 */ 687,
/* 677 */ 50125,
/* 678 */ -673,
/* 679 */ 71,
/* 680 */ 684,
/* 681 */ 68,
/* 682 */ -680,
/* 683 */ 188,
/* 684 */ 0,
/* 685 */ -680,
/* 686 */ 247,
/* 687 */ 691,
/* 688 */ 694,
/* 689 */ -687,
/* 690 */ 189,
/* 691 */ 0,
/* 692 */ -687,
/* 693 */ 248,
/* 694 */ 0,
/* 695 */ 699,
/* 696 */ 610,
/* 697 */ -694,
/* 698 */ 72,
/* 699 */ 704,
/* 700 */ 610,
/* 701 */ 699,
/* 702 */ -699,
/* 703 */ 190,
/* 704 */ 0,
/* 705 */ -699,
/* 706 */ 249,
/* 707 */ 716,
/* 708 */ 50271,
/* 709 */ 50040,
/* 710 */ 834,
/* 711 */ 50041,
/* 712 */ 610,
/* 713 */ 724,
/* 714 */ -707,
/* 715 */ 73,
/* 716 */ 0,
/* 717 */ 50281,
/* 718 */ 50040,
/* 719 */ 834,
/* 720 */ 50041,
/* 721 */ 610,
/* 722 */ -707,
/* 723 */ 74,
/* 724 */ 729,
/* 725 */ 50265,
/* 726 */ 610,
/* 727 */ -724,
/* 728 */ 191,
/* 729 */ 0,
/* 730 */ -724,
/* 731 */ 250,
/* 732 */ 740,
/* 733 */ 50287,
/* 734 */ 50040,
/* 735 */ 834,
/* 736 */ 50041,
/* 737 */ 610,
/* 738 */ -732,
/* 739 */ 75,
/* 740 */ 750,
/* 741 */ 50263,
/* 742 */ 610,
/* 743 */ 50287,
/* 744 */ 50040,
/* 745 */ 834,
/* 746 */ 50041,
/* 747 */ 50059,
/* 748 */ -732,
/* 749 */ 76,
/* 750 */ 0,
/* 751 */ 50269,
/* 752 */ 50040,
/* 753 */ 762,
/* 754 */ 50059,
/* 755 */ 769,
/* 756 */ 50059,
/* 757 */ 776,
/* 758 */ 50041,
/* 759 */ 610,
/* 760 */ -732,
/* 761 */ 77,
/* 762 */ 766,
/* 763 */ 834,
/* 764 */ -762,
/* 765 */ 192,
/* 766 */ 0,
/* 767 */ -762,
/* 768 */ 251,
/* 769 */ 773,
/* 770 */ 834,
/* 771 */ -769,
/* 772 */ 193,
/* 773 */ 0,
/* 774 */ -769,
/* 775 */ 252,
/* 776 */ 780,
/* 777 */ 834,
/* 778 */ -776,
/* 779 */ 194,
/* 780 */ 0,
/* 781 */ -776,
/* 782 */ 253,
/* 783 */ 789,
/* 784 */ 50270,
/* 785 */ 1156,
/* 786 */ 50059,
/* 787 */ -783,
/* 788 */ 78,
/* 789 */ 794,
/* 790 */ 50261,
/* 791 */ 50059,
/* 792 */ -783,
/* 793 */ 79,
/* 794 */ 799,
/* 795 */ 50257,
/* 796 */ 50059,
/* 797 */ -783,
/* 798 */ 80,
/* 799 */ 0,
/* 800 */ 50275,
/* 801 */ 805,
/* 802 */ 50059,
/* 803 */ -783,
/* 804 */ 81,
/* 805 */ 809,
/* 806 */ 834,
/* 807 */ -805,
/* 808 */ 195,
/* 809 */ 0,
/* 810 */ -805,
/* 811 */ 254,
/* 812 */ 0,
/* 813 */ 50305,
/* 814 */ 1126,
/* 815 */ 50059,
/* 816 */ -812,
/* 817 */ 82,
/* 818 */ 0,
/* 819 */ 50306,
/* 820 */ 825,
/* 821 */ 1156,
/* 822 */ 50059,
/* 823 */ -818,
/* 824 */ 83,
/* 825 */ 831,
/* 826 */ 1156,
/* 827 */ 50044,
/* 828 */ 825,
/* 829 */ -825,
/* 830 */ 196,
/* 831 */ 0,
/* 832 */ -825,
/* 833 */ 255,
/* 834 */ 838,
/* 835 */ 844,
/* 836 */ -834,
/* 837 */ 84,
/* 838 */ 0,
/* 839 */ 834,
/* 840 */ 50044,
/* 841 */ 844,
/* 842 */ -834,
/* 843 */ 85,
/* 844 */ 848,
/* 845 */ 862,
/* 846 */ -844,
/* 847 */ 86,
/* 848 */ 0,
/* 849 */ 999,
/* 850 */ 854,
/* 851 */ 844,
/* 852 */ -844,
/* 853 */ 87,
/* 854 */ 858,
/* 855 */ 50291,
/* 856 */ -854,
/* 857 */ 88,
/* 858 */ 0,
/* 859 */ 50061,
/* 860 */ -854,
/* 861 */ 89,
/* 862 */ 866,
/* 863 */ 878,
/* 864 */ -862,
/* 865 */ 90,
/* 866 */ 0,
/* 867 */ 878,
/* 868 */ 50063,
/* 869 */ 834,
/* 870 */ 50058,
/* 871 */ 862,
/* 872 */ -862,
/* 873 */ 91,
/* 874 */ 0,
/* 875 */ 862,
/* 876 */ -874,
/* 877 */ 92,
/* 878 */ 882,
/* 879 */ 888,
/* 880 */ -878,
/* 881 */ 93,
/* 882 */ 0,
/* 883 */ 878,
/* 884 */ 50297,
/* 885 */ 888,
/* 886 */ -878,
/* 887 */ 94,
/* 888 */ 892,
/* 889 */ 898,
/* 890 */ -888,
/* 891 */ 95,
/* 892 */ 0,
/* 893 */ 888,
/* 894 */ 50298,
/* 895 */ 898,
/* 896 */ -888,
/* 897 */ 96,
/* 898 */ 902,
/* 899 */ 908,
/* 900 */ -898,
/* 901 */ 97,
/* 902 */ 0,
/* 903 */ 898,
/* 904 */ 50124,
/* 905 */ 908,
/* 906 */ -898,
/* 907 */ 98,
/* 908 */ 912,
/* 909 */ 918,
/* 910 */ -908,
/* 911 */ 99,
/* 912 */ 0,
/* 913 */ 908,
/* 914 */ 50094,
/* 915 */ 918,
/* 916 */ -908,
/* 917 */ 100,
/* 918 */ 922,
/* 919 */ 928,
/* 920 */ -918,
/* 921 */ 101,
/* 922 */ 0,
/* 923 */ 918,
/* 924 */ 50038,
/* 925 */ 928,
/* 926 */ -918,
/* 927 */ 102,
/* 928 */ 932,
/* 929 */ 938,
/* 930 */ -928,
/* 931 */ 103,
/* 932 */ 0,
/* 933 */ 928,
/* 934 */ 50292,
/* 935 */ 938,
/* 936 */ -928,
/* 937 */ 104,
/* 938 */ 942,
/* 939 */ 948,
/* 940 */ -938,
/* 941 */ 105,
/* 942 */ 0,
/* 943 */ 938,
/* 944 */ 50300,
/* 945 */ 948,
/* 946 */ -938,
/* 947 */ 106,
/* 948 */ 952,
/* 949 */ 966,
/* 950 */ -948,
/* 951 */ 107,
/* 952 */ 0,
/* 953 */ 948,
/* 954 */ 958,
/* 955 */ 966,
/* 956 */ -948,
/* 957 */ 108,
/* 958 */ 962,
/* 959 */ 50043,
/* 960 */ -958,
/* 961 */ 197,
/* 962 */ 0,
/* 963 */ 50045,
/* 964 */ -958,
/* 965 */ 198,
/* 966 */ 970,
/* 967 */ 988,
/* 968 */ -966,
/* 969 */ 109,
/* 970 */ 0,
/* 971 */ 966,
/* 972 */ 976,
/* 973 */ 988,
/* 974 */ -966,
/* 975 */ 110,
/* 976 */ 980,
/* 977 */ 50042,
/* 978 */ -976,
/* 979 */ 199,
/* 980 */ 984,
/* 981 */ 50047,
/* 982 */ -976,
/* 983 */ 200,
/* 984 */ 0,
/* 985 */ 50037,
/* 986 */ -976,
/* 987 */ 201,
/* 988 */ 992,
/* 989 */ 999,
/* 990 */ -988,
/* 991 */ 111,
/* 992 */ 0,
/* 993 */ 50040,
/* 994 */ 534,
/* 995 */ 50041,
/* 996 */ 988,
/* 997 */ -988,
/* 998 */ 112,
/* 999 */ 1003,
/* 1000 */ 1057,
/* 1001 */ -999,
/* 1002 */ 113,
/* 1003 */ 1008,
/* 1004 */ 1025,
/* 1005 */ 999,
/* 1006 */ -999,
/* 1007 */ 114,
/* 1008 */ 1013,
/* 1009 */ 1033,
/* 1010 */ 988,
/* 1011 */ -999,
/* 1012 */ 115,
/* 1013 */ 1018,
/* 1014 */ 50278,
/* 1015 */ 999,
/* 1016 */ -999,
/* 1017 */ 116,
/* 1018 */ 0,
/* 1019 */ 50278,
/* 1020 */ 50040,
/* 1021 */ 534,
/* 1022 */ 50041,
/* 1023 */ -999,
/* 1024 */ 117,
/* 1025 */ 1029,
/* 1026 */ 50294,
/* 1027 */ -1025,
/* 1028 */ 202,
/* 1029 */ 0,
/* 1030 */ 50295,
/* 1031 */ -1025,
/* 1032 */ 203,
/* 1033 */ 1037,
/* 1034 */ 50038,
/* 1035 */ -1033,
/* 1036 */ 118,
/* 1037 */ 1041,
/* 1038 */ 50042,
/* 1039 */ -1033,
/* 1040 */ 119,
/* 1041 */ 1045,
/* 1042 */ 50043,
/* 1043 */ -1033,
/* 1044 */ 120,
/* 1045 */ 1049,
/* 1046 */ 50045,
/* 1047 */ -1033,
/* 1048 */ 121,
/* 1049 */ 1053,
/* 1050 */ 50126,
/* 1051 */ -1033,
/* 1052 */ 122,
/* 1053 */ 0,
/* 1054 */ 50033,
/* 1055 */ -1033,
/* 1056 */ 123,
/* 1057 */ 1061,
/* 1058 */ 1112,
/* 1059 */ -1057,
/* 1060 */ 124,
/* 1061 */ 0,
/* 1062 */ 1057,
/* 1063 */ 1066,
/* 1064 */ -1057,
/* 1065 */ 125,
/* 1066 */ 1073,
/* 1067 */ 50091,
/* 1068 */ 834,
/* 1069 */ 1097,
/* 1070 */ 50093,
/* 1071 */ -1066,
/* 1072 */ 205,
/* 1073 */ 1079,
/* 1074 */ 50040,
/* 1075 */ 1105,
/* 1076 */ 50041,
/* 1077 */ -1066,
/* 1078 */ 207,
/* 1079 */ 1084,
/* 1080 */ 50046,
/* 1081 */ 1156,
/* 1082 */ -1066,
/* 1083 */ 208,
/* 1084 */ 1089,
/* 1085 */ 50296,
/* 1086 */ 1156,
/* 1087 */ -1066,
/* 1088 */ 209,
/* 1089 */ 1093,
/* 1090 */ 50294,
/* 1091 */ -1066,
/* 1092 */ 210,
/* 1093 */ 0,
/* 1094 */ 50295,
/* 1095 */ -1066,
/* 1096 */ 211,
/* 1097 */ 1102,
/* 1098 */ 50058,
/* 1099 */ 834,
/* 1100 */ -1097,
/* 1101 */ 204,
/* 1102 */ 0,
/* 1103 */ -1097,
/* 1104 */ 256,
/* 1105 */ 1109,
/* 1106 */ 1126,
/* 1107 */ -1105,
/* 1108 */ 206,
/* 1109 */ 0,
/* 1110 */ -1105,
/* 1111 */ 257,
/* 1112 */ 1116,
/* 1113 */ 1156,
/* 1114 */ -1112,
/* 1115 */ 126,
/* 1116 */ 1120,
/* 1117 */ 1140,
/* 1118 */ -1112,
/* 1119 */ 127,
/* 1120 */ 0,
/* 1121 */ 50040,
/* 1122 */ 834,
/* 1123 */ 50041,
/* 1124 */ -1112,
/* 1125 */ 128,
/* 1126 */ 0,
/* 1127 */ 1131,
/* 1128 */ 844,
/* 1129 */ -1126,
/* 1130 */ 129,
/* 1131 */ 1137,
/* 1132 */ 844,
/* 1133 */ 50044,
/* 1134 */ 1131,
/* 1135 */ -1131,
/* 1136 */ 212,
/* 1137 */ 0,
/* 1138 */ -1131,
/* 1139 */ 258,
/* 1140 */ 1144,
/* 1141 */ 50304,
/* 1142 */ -1140,
/* 1143 */ 130,
/* 1144 */ 1148,
/* 1145 */ 50302,
/* 1146 */ -1140,
/* 1147 */ 131,
/* 1148 */ 1152,
/* 1149 */ 50303,
/* 1150 */ -1140,
/* 1151 */ 132,
/* 1152 */ 0,
/* 1153 */ 50289,
/* 1154 */ -1140,
/* 1155 */ 133,
/* 1156 */ 0,
/* 1157 */ 50299,
/* 1158 */ -1156,
/* 1159 */ 134,
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
/* 83 */ 1,
/* 84 */ -81,
/* 85 */ 1,
/* 86 */ 90,
/* 87 */ 1,
/* 88 */ -86,
/* 89 */ 1,
/* 90 */ 94,
/* 91 */ 1,
/* 92 */ -86,
/* 93 */ 2,
/* 94 */ 0,
/* 95 */ 1,
/* 96 */ -86,
/* 97 */ 3,
/* 98 */ 102,
/* 99 */ 1,
/* 100 */ -98,
/* 101 */ 1,
/* 102 */ 0,
/* 103 */ -98,
/* 104 */ 2,
/* 105 */ 109,
/* 106 */ 50256,
/* 107 */ -105,
/* 108 */ 1,
/* 109 */ 113,
/* 110 */ 50274,
/* 111 */ -105,
/* 112 */ 2,
/* 113 */ 117,
/* 114 */ 50279,
/* 115 */ -105,
/* 116 */ 3,
/* 117 */ 121,
/* 118 */ 50267,
/* 119 */ -105,
/* 120 */ 4,
/* 121 */ 0,
/* 122 */ 50282,
/* 123 */ -105,
/* 124 */ 5,
/* 125 */ 129,
/* 126 */ 50285,
/* 127 */ -125,
/* 128 */ 1,
/* 129 */ 133,
/* 130 */ 50259,
/* 131 */ -125,
/* 132 */ 2,
/* 133 */ 137,
/* 134 */ 50276,
/* 135 */ -125,
/* 136 */ 3,
/* 137 */ 141,
/* 138 */ 50272,
/* 139 */ -125,
/* 140 */ 4,
/* 141 */ 145,
/* 142 */ 50273,
/* 143 */ -125,
/* 144 */ 5,
/* 145 */ 149,
/* 146 */ 50268,
/* 147 */ -125,
/* 148 */ 6,
/* 149 */ 153,
/* 150 */ 50264,
/* 151 */ -125,
/* 152 */ 7,
/* 153 */ 157,
/* 154 */ 50277,
/* 155 */ -125,
/* 156 */ 8,
/* 157 */ 161,
/* 158 */ 50284,
/* 159 */ -125,
/* 160 */ 9,
/* 161 */ 165,
/* 162 */ 1,
/* 163 */ -125,
/* 164 */ 10,
/* 165 */ 0,
/* 166 */ 1,
/* 167 */ -125,
/* 168 */ 11,
/* 169 */ 0,
/* 170 */ 1,
/* 171 */ -169,
/* 172 */ 1,
/* 173 */ 177,
/* 174 */ 50260,
/* 175 */ -173,
/* 176 */ 1,
/* 177 */ 0,
/* 178 */ 50286,
/* 179 */ -173,
/* 180 */ 2,
/* 181 */ 189,
/* 182 */ 1,
/* 183 */ 1,
/* 184 */ 50123,
/* 185 */ 1,
/* 186 */ 50125,
/* 187 */ -181,
/* 188 */ 1,
/* 189 */ 0,
/* 190 */ 1,
/* 191 */ 1,
/* 192 */ -181,
/* 193 */ 2,
/* 194 */ 198,
/* 195 */ 1,
/* 196 */ -194,
/* 197 */ 1,
/* 198 */ 0,
/* 199 */ -194,
/* 200 */ 2,
/* 201 */ 0,
/* 202 */ 1,
/* 203 */ -201,
/* 204 */ 1,
/* 205 */ 209,
/* 206 */ 50280,
/* 207 */ -205,
/* 208 */ 1,
/* 209 */ 0,
/* 210 */ 50283,
/* 211 */ -205,
/* 212 */ 2,
/* 213 */ 0,
/* 214 */ 1,
/* 215 */ 1,
/* 216 */ -213,
/* 217 */ 1,
/* 218 */ 222,
/* 219 */ 1,
/* 220 */ -218,
/* 221 */ 1,
/* 222 */ 0,
/* 223 */ -218,
/* 224 */ 2,
/* 225 */ 0,
/* 226 */ 1,
/* 227 */ 1,
/* 228 */ -225,
/* 229 */ 1,
/* 230 */ 235,
/* 231 */ 1,
/* 232 */ 50044,
/* 233 */ -230,
/* 234 */ 1,
/* 235 */ 0,
/* 236 */ -230,
/* 237 */ 2,
/* 238 */ 0,
/* 239 */ 1,
/* 240 */ 1,
/* 241 */ -238,
/* 242 */ 1,
/* 243 */ 248,
/* 244 */ 1,
/* 245 */ 50061,
/* 246 */ -243,
/* 247 */ 1,
/* 248 */ 0,
/* 249 */ -243,
/* 250 */ 2,
/* 251 */ 0,
/* 252 */ 1,
/* 253 */ 1,
/* 254 */ 50059,
/* 255 */ -251,
/* 256 */ 1,
/* 257 */ 0,
/* 258 */ 1,
/* 259 */ 1,
/* 260 */ -257,
/* 261 */ 1,
/* 262 */ 266,
/* 263 */ 1,
/* 264 */ -262,
/* 265 */ 1,
/* 266 */ 0,
/* 267 */ 1,
/* 268 */ -262,
/* 269 */ 2,
/* 270 */ 274,
/* 271 */ 1,
/* 272 */ -270,
/* 273 */ 1,
/* 274 */ 0,
/* 275 */ -270,
/* 276 */ 2,
/* 277 */ 0,
/* 278 */ 1,
/* 279 */ 1,
/* 280 */ -277,
/* 281 */ 1,
/* 282 */ 287,
/* 283 */ 1,
/* 284 */ 50044,
/* 285 */ -282,
/* 286 */ 1,
/* 287 */ 0,
/* 288 */ -282,
/* 289 */ 2,
/* 290 */ 294,
/* 291 */ 1,
/* 292 */ -290,
/* 293 */ 1,
/* 294 */ 0,
/* 295 */ 1,
/* 296 */ 50058,
/* 297 */ 1,
/* 298 */ -290,
/* 299 */ 2,
/* 300 */ 304,
/* 301 */ 1,
/* 302 */ -300,
/* 303 */ 1,
/* 304 */ 0,
/* 305 */ -300,
/* 306 */ 2,
/* 307 */ 315,
/* 308 */ 50266,
/* 309 */ 1,
/* 310 */ 50123,
/* 311 */ 1,
/* 312 */ 50125,
/* 313 */ -307,
/* 314 */ 1,
/* 315 */ 0,
/* 316 */ 50266,
/* 317 */ 1,
/* 318 */ -307,
/* 319 */ 2,
/* 320 */ 324,
/* 321 */ 1,
/* 322 */ -320,
/* 323 */ 1,
/* 324 */ 0,
/* 325 */ -320,
/* 326 */ 2,
/* 327 */ 0,
/* 328 */ 1,
/* 329 */ 1,
/* 330 */ -327,
/* 331 */ 1,
/* 332 */ 337,
/* 333 */ 1,
/* 334 */ 50044,
/* 335 */ -332,
/* 336 */ 1,
/* 337 */ 0,
/* 338 */ -332,
/* 339 */ 2,
/* 340 */ 0,
/* 341 */ 1,
/* 342 */ 1,
/* 343 */ -340,
/* 344 */ 1,
/* 345 */ 350,
/* 346 */ 50061,
/* 347 */ 1,
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
/* 358 */ 362,
/* 359 */ 1,
/* 360 */ -358,
/* 361 */ 1,
/* 362 */ 0,
/* 363 */ -358,
/* 364 */ 2,
/* 365 */ 369,
/* 366 */ 1,
/* 367 */ -365,
/* 368 */ 1,
/* 369 */ 375,
/* 370 */ 50040,
/* 371 */ 1,
/* 372 */ 50041,
/* 373 */ -365,
/* 374 */ 2,
/* 375 */ 0,
/* 376 */ 1,
/* 377 */ 1,
/* 378 */ -365,
/* 379 */ 3,
/* 380 */ 386,
/* 381 */ 50091,
/* 382 */ 1,
/* 383 */ 50093,
/* 384 */ -380,
/* 385 */ 1,
/* 386 */ 392,
/* 387 */ 50040,
/* 388 */ 1,
/* 389 */ 50041,
/* 390 */ -380,
/* 391 */ 2,
/* 392 */ 0,
/* 393 */ 50040,
/* 394 */ 1,
/* 395 */ 50041,
/* 396 */ -380,
/* 397 */ 3,
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
/* 413 */ 50042,
/* 414 */ 1,
/* 415 */ 1,
/* 416 */ -412,
/* 417 */ 1,
/* 418 */ 422,
/* 419 */ 1,
/* 420 */ -418,
/* 421 */ 1,
/* 422 */ 0,
/* 423 */ -418,
/* 424 */ 2,
/* 425 */ 429,
/* 426 */ 1,
/* 427 */ -425,
/* 428 */ 1,
/* 429 */ 0,
/* 430 */ -425,
/* 431 */ 2,
/* 432 */ 0,
/* 433 */ 1,
/* 434 */ 1,
/* 435 */ -432,
/* 436 */ 1,
/* 437 */ 441,
/* 438 */ 1,
/* 439 */ -437,
/* 440 */ 1,
/* 441 */ 0,
/* 442 */ -437,
/* 443 */ 2,
/* 444 */ 0,
/* 445 */ 1,
/* 446 */ 1,
/* 447 */ -444,
/* 448 */ 1,
/* 449 */ 454,
/* 450 */ 50044,
/* 451 */ 50290,
/* 452 */ -449,
/* 453 */ 1,
/* 454 */ 0,
/* 455 */ -449,
/* 456 */ 2,
/* 457 */ 0,
/* 458 */ 1,
/* 459 */ 1,
/* 460 */ -457,
/* 461 */ 1,
/* 462 */ 467,
/* 463 */ 1,
/* 464 */ 50044,
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
/* 475 */ 479,
/* 476 */ 1,
/* 477 */ -475,
/* 478 */ 1,
/* 479 */ 0,
/* 480 */ 1,
/* 481 */ -475,
/* 482 */ 2,
/* 483 */ 487,
/* 484 */ 1,
/* 485 */ -483,
/* 486 */ 1,
/* 487 */ 0,
/* 488 */ -483,
/* 489 */ 2,
/* 490 */ 0,
/* 491 */ 1,
/* 492 */ 1,
/* 493 */ -490,
/* 494 */ 1,
/* 495 */ 500,
/* 496 */ 1,
/* 497 */ 50044,
/* 498 */ -495,
/* 499 */ 1,
/* 500 */ 0,
/* 501 */ -495,
/* 502 */ 2,
/* 503 */ 507,
/* 504 */ 1,
/* 505 */ -503,
/* 506 */ 1,
/* 507 */ 0,
/* 508 */ 50123,
/* 509 */ 1,
/* 510 */ 1,
/* 511 */ 50125,
/* 512 */ -503,
/* 513 */ 2,
/* 514 */ 518,
/* 515 */ 50044,
/* 516 */ -514,
/* 517 */ 1,
/* 518 */ 0,
/* 519 */ -514,
/* 520 */ 2,
/* 521 */ 0,
/* 522 */ 1,
/* 523 */ 1,
/* 524 */ -521,
/* 525 */ 1,
/* 526 */ 531,
/* 527 */ 1,
/* 528 */ 50044,
/* 529 */ -526,
/* 530 */ 1,
/* 531 */ 0,
/* 532 */ -526,
/* 533 */ 2,
/* 534 */ 0,
/* 535 */ 1,
/* 536 */ 1,
/* 537 */ -534,
/* 538 */ 1,
/* 539 */ 543,
/* 540 */ 1,
/* 541 */ -539,
/* 542 */ 1,
/* 543 */ 0,
/* 544 */ -539,
/* 545 */ 2,
/* 546 */ 550,
/* 547 */ 1,
/* 548 */ -546,
/* 549 */ 1,
/* 550 */ 0,
/* 551 */ 1,
/* 552 */ 1,
/* 553 */ -546,
/* 554 */ 2,
/* 555 */ 559,
/* 556 */ 1,
/* 557 */ -555,
/* 558 */ 1,
/* 559 */ 0,
/* 560 */ -555,
/* 561 */ 2,
/* 562 */ 568,
/* 563 */ 50040,
/* 564 */ 1,
/* 565 */ 50041,
/* 566 */ -562,
/* 567 */ 1,
/* 568 */ 0,
/* 569 */ 1,
/* 570 */ 1,
/* 571 */ -562,
/* 572 */ 2,
/* 573 */ 577,
/* 574 */ 1,
/* 575 */ -573,
/* 576 */ 1,
/* 577 */ 0,
/* 578 */ -573,
/* 579 */ 2,
/* 580 */ 586,
/* 581 */ 50091,
/* 582 */ 1,
/* 583 */ 50093,
/* 584 */ -580,
/* 585 */ 1,
/* 586 */ 0,
/* 587 */ 50040,
/* 588 */ 1,
/* 589 */ 50041,
/* 590 */ -580,
/* 591 */ 2,
/* 592 */ 596,
/* 593 */ 1,
/* 594 */ -592,
/* 595 */ 1,
/* 596 */ 0,
/* 597 */ -592,
/* 598 */ 2,
/* 599 */ 603,
/* 600 */ 1,
/* 601 */ -599,
/* 602 */ 1,
/* 603 */ 0,
/* 604 */ -599,
/* 605 */ 2,
/* 606 */ 0,
/* 607 */ 1,
/* 608 */ -606,
/* 609 */ 1,
/* 610 */ 614,
/* 611 */ 1,
/* 612 */ -610,
/* 613 */ 1,
/* 614 */ 618,
/* 615 */ 1,
/* 616 */ -610,
/* 617 */ 2,
/* 618 */ 622,
/* 619 */ 1,
/* 620 */ -610,
/* 621 */ 3,
/* 622 */ 626,
/* 623 */ 1,
/* 624 */ -610,
/* 625 */ 4,
/* 626 */ 630,
/* 627 */ 1,
/* 628 */ -610,
/* 629 */ 5,
/* 630 */ 634,
/* 631 */ 1,
/* 632 */ -610,
/* 633 */ 6,
/* 634 */ 638,
/* 635 */ 1,
/* 636 */ -610,
/* 637 */ 7,
/* 638 */ 0,
/* 639 */ 1,
/* 640 */ -610,
/* 641 */ 8,
/* 642 */ 648,
/* 643 */ 1,
/* 644 */ 50058,
/* 645 */ 1,
/* 646 */ -642,
/* 647 */ 1,
/* 648 */ 655,
/* 649 */ 50258,
/* 650 */ 1,
/* 651 */ 50058,
/* 652 */ 1,
/* 653 */ -642,
/* 654 */ 2,
/* 655 */ 0,
/* 656 */ 50262,
/* 657 */ 50058,
/* 658 */ 1,
/* 659 */ -642,
/* 660 */ 3,
/* 661 */ 0,
/* 662 */ 1,
/* 663 */ 50059,
/* 664 */ -661,
/* 665 */ 1,
/* 666 */ 670,
/* 667 */ 1,
/* 668 */ -666,
/* 669 */ 1,
/* 670 */ 0,
/* 671 */ -666,
/* 672 */ 2,
/* 673 */ 0,
/* 674 */ 50123,
/* 675 */ 1,
/* 676 */ 1,
/* 677 */ 50125,
/* 678 */ -673,
/* 679 */ 1,
/* 680 */ 684,
/* 681 */ 1,
/* 682 */ -680,
/* 683 */ 1,
/* 684 */ 0,
/* 685 */ -680,
/* 686 */ 2,
/* 687 */ 691,
/* 688 */ 1,
/* 689 */ -687,
/* 690 */ 1,
/* 691 */ 0,
/* 692 */ -687,
/* 693 */ 2,
/* 694 */ 0,
/* 695 */ 1,
/* 696 */ 1,
/* 697 */ -694,
/* 698 */ 1,
/* 699 */ 704,
/* 700 */ 1,
/* 701 */ 1,
/* 702 */ -699,
/* 703 */ 1,
/* 704 */ 0,
/* 705 */ -699,
/* 706 */ 2,
/* 707 */ 716,
/* 708 */ 50271,
/* 709 */ 50040,
/* 710 */ 1,
/* 711 */ 50041,
/* 712 */ 1,
/* 713 */ 1,
/* 714 */ -707,
/* 715 */ 1,
/* 716 */ 0,
/* 717 */ 50281,
/* 718 */ 50040,
/* 719 */ 1,
/* 720 */ 50041,
/* 721 */ 1,
/* 722 */ -707,
/* 723 */ 2,
/* 724 */ 729,
/* 725 */ 50265,
/* 726 */ 1,
/* 727 */ -724,
/* 728 */ 1,
/* 729 */ 0,
/* 730 */ -724,
/* 731 */ 2,
/* 732 */ 740,
/* 733 */ 50287,
/* 734 */ 50040,
/* 735 */ 1,
/* 736 */ 50041,
/* 737 */ 1,
/* 738 */ -732,
/* 739 */ 1,
/* 740 */ 750,
/* 741 */ 50263,
/* 742 */ 1,
/* 743 */ 50287,
/* 744 */ 50040,
/* 745 */ 1,
/* 746 */ 50041,
/* 747 */ 50059,
/* 748 */ -732,
/* 749 */ 2,
/* 750 */ 0,
/* 751 */ 50269,
/* 752 */ 50040,
/* 753 */ 1,
/* 754 */ 50059,
/* 755 */ 1,
/* 756 */ 50059,
/* 757 */ 1,
/* 758 */ 50041,
/* 759 */ 1,
/* 760 */ -732,
/* 761 */ 3,
/* 762 */ 766,
/* 763 */ 1,
/* 764 */ -762,
/* 765 */ 1,
/* 766 */ 0,
/* 767 */ -762,
/* 768 */ 2,
/* 769 */ 773,
/* 770 */ 1,
/* 771 */ -769,
/* 772 */ 1,
/* 773 */ 0,
/* 774 */ -769,
/* 775 */ 2,
/* 776 */ 780,
/* 777 */ 1,
/* 778 */ -776,
/* 779 */ 1,
/* 780 */ 0,
/* 781 */ -776,
/* 782 */ 2,
/* 783 */ 789,
/* 784 */ 50270,
/* 785 */ 1,
/* 786 */ 50059,
/* 787 */ -783,
/* 788 */ 1,
/* 789 */ 794,
/* 790 */ 50261,
/* 791 */ 50059,
/* 792 */ -783,
/* 793 */ 2,
/* 794 */ 799,
/* 795 */ 50257,
/* 796 */ 50059,
/* 797 */ -783,
/* 798 */ 3,
/* 799 */ 0,
/* 800 */ 50275,
/* 801 */ 1,
/* 802 */ 50059,
/* 803 */ -783,
/* 804 */ 4,
/* 805 */ 809,
/* 806 */ 1,
/* 807 */ -805,
/* 808 */ 1,
/* 809 */ 0,
/* 810 */ -805,
/* 811 */ 2,
/* 812 */ 0,
/* 813 */ 50305,
/* 814 */ 1,
/* 815 */ 50059,
/* 816 */ -812,
/* 817 */ 1,
/* 818 */ 0,
/* 819 */ 50306,
/* 820 */ 1,
/* 821 */ 1,
/* 822 */ 50059,
/* 823 */ -818,
/* 824 */ 1,
/* 825 */ 831,
/* 826 */ 1,
/* 827 */ 50044,
/* 828 */ 1,
/* 829 */ -825,
/* 830 */ 1,
/* 831 */ 0,
/* 832 */ -825,
/* 833 */ 2,
/* 834 */ 838,
/* 835 */ 1,
/* 836 */ -834,
/* 837 */ 1,
/* 838 */ 0,
/* 839 */ 1,
/* 840 */ 50044,
/* 841 */ 1,
/* 842 */ -834,
/* 843 */ 2,
/* 844 */ 848,
/* 845 */ 1,
/* 846 */ -844,
/* 847 */ 1,
/* 848 */ 0,
/* 849 */ 1,
/* 850 */ 1,
/* 851 */ 1,
/* 852 */ -844,
/* 853 */ 2,
/* 854 */ 858,
/* 855 */ 50291,
/* 856 */ -854,
/* 857 */ 1,
/* 858 */ 0,
/* 859 */ 50061,
/* 860 */ -854,
/* 861 */ 2,
/* 862 */ 866,
/* 863 */ 1,
/* 864 */ -862,
/* 865 */ 1,
/* 866 */ 0,
/* 867 */ 1,
/* 868 */ 50063,
/* 869 */ 1,
/* 870 */ 50058,
/* 871 */ 1,
/* 872 */ -862,
/* 873 */ 2,
/* 874 */ 0,
/* 875 */ 1,
/* 876 */ -874,
/* 877 */ 1,
/* 878 */ 882,
/* 879 */ 1,
/* 880 */ -878,
/* 881 */ 1,
/* 882 */ 0,
/* 883 */ 1,
/* 884 */ 50297,
/* 885 */ 1,
/* 886 */ -878,
/* 887 */ 2,
/* 888 */ 892,
/* 889 */ 1,
/* 890 */ -888,
/* 891 */ 1,
/* 892 */ 0,
/* 893 */ 1,
/* 894 */ 50298,
/* 895 */ 1,
/* 896 */ -888,
/* 897 */ 2,
/* 898 */ 902,
/* 899 */ 1,
/* 900 */ -898,
/* 901 */ 1,
/* 902 */ 0,
/* 903 */ 1,
/* 904 */ 50124,
/* 905 */ 1,
/* 906 */ -898,
/* 907 */ 2,
/* 908 */ 912,
/* 909 */ 1,
/* 910 */ -908,
/* 911 */ 1,
/* 912 */ 0,
/* 913 */ 1,
/* 914 */ 50094,
/* 915 */ 1,
/* 916 */ -908,
/* 917 */ 2,
/* 918 */ 922,
/* 919 */ 1,
/* 920 */ -918,
/* 921 */ 1,
/* 922 */ 0,
/* 923 */ 1,
/* 924 */ 50038,
/* 925 */ 1,
/* 926 */ -918,
/* 927 */ 2,
/* 928 */ 932,
/* 929 */ 1,
/* 930 */ -928,
/* 931 */ 1,
/* 932 */ 0,
/* 933 */ 1,
/* 934 */ 50292,
/* 935 */ 1,
/* 936 */ -928,
/* 937 */ 2,
/* 938 */ 942,
/* 939 */ 1,
/* 940 */ -938,
/* 941 */ 1,
/* 942 */ 0,
/* 943 */ 1,
/* 944 */ 50300,
/* 945 */ 1,
/* 946 */ -938,
/* 947 */ 2,
/* 948 */ 952,
/* 949 */ 1,
/* 950 */ -948,
/* 951 */ 1,
/* 952 */ 0,
/* 953 */ 1,
/* 954 */ 1,
/* 955 */ 1,
/* 956 */ -948,
/* 957 */ 2,
/* 958 */ 962,
/* 959 */ 50043,
/* 960 */ -958,
/* 961 */ 1,
/* 962 */ 0,
/* 963 */ 50045,
/* 964 */ -958,
/* 965 */ 2,
/* 966 */ 970,
/* 967 */ 1,
/* 968 */ -966,
/* 969 */ 1,
/* 970 */ 0,
/* 971 */ 1,
/* 972 */ 1,
/* 973 */ 1,
/* 974 */ -966,
/* 975 */ 2,
/* 976 */ 980,
/* 977 */ 50042,
/* 978 */ -976,
/* 979 */ 1,
/* 980 */ 984,
/* 981 */ 50047,
/* 982 */ -976,
/* 983 */ 2,
/* 984 */ 0,
/* 985 */ 50037,
/* 986 */ -976,
/* 987 */ 3,
/* 988 */ 992,
/* 989 */ 1,
/* 990 */ -988,
/* 991 */ 1,
/* 992 */ 0,
/* 993 */ 50040,
/* 994 */ 1,
/* 995 */ 50041,
/* 996 */ 1,
/* 997 */ -988,
/* 998 */ 2,
/* 999 */ 1003,
/* 1000 */ 1,
/* 1001 */ -999,
/* 1002 */ 1,
/* 1003 */ 1008,
/* 1004 */ 1,
/* 1005 */ 1,
/* 1006 */ -999,
/* 1007 */ 2,
/* 1008 */ 1013,
/* 1009 */ 1,
/* 1010 */ 1,
/* 1011 */ -999,
/* 1012 */ 3,
/* 1013 */ 1018,
/* 1014 */ 50278,
/* 1015 */ 1,
/* 1016 */ -999,
/* 1017 */ 4,
/* 1018 */ 0,
/* 1019 */ 50278,
/* 1020 */ 50040,
/* 1021 */ 1,
/* 1022 */ 50041,
/* 1023 */ -999,
/* 1024 */ 5,
/* 1025 */ 1029,
/* 1026 */ 50294,
/* 1027 */ -1025,
/* 1028 */ 1,
/* 1029 */ 0,
/* 1030 */ 50295,
/* 1031 */ -1025,
/* 1032 */ 2,
/* 1033 */ 1037,
/* 1034 */ 50038,
/* 1035 */ -1033,
/* 1036 */ 1,
/* 1037 */ 1041,
/* 1038 */ 50042,
/* 1039 */ -1033,
/* 1040 */ 2,
/* 1041 */ 1045,
/* 1042 */ 50043,
/* 1043 */ -1033,
/* 1044 */ 3,
/* 1045 */ 1049,
/* 1046 */ 50045,
/* 1047 */ -1033,
/* 1048 */ 4,
/* 1049 */ 1053,
/* 1050 */ 50126,
/* 1051 */ -1033,
/* 1052 */ 5,
/* 1053 */ 0,
/* 1054 */ 50033,
/* 1055 */ -1033,
/* 1056 */ 6,
/* 1057 */ 1061,
/* 1058 */ 1,
/* 1059 */ -1057,
/* 1060 */ 1,
/* 1061 */ 0,
/* 1062 */ 1,
/* 1063 */ 1,
/* 1064 */ -1057,
/* 1065 */ 2,
/* 1066 */ 1073,
/* 1067 */ 50091,
/* 1068 */ 1,
/* 1069 */ 1,
/* 1070 */ 50093,
/* 1071 */ -1066,
/* 1072 */ 1,
/* 1073 */ 1079,
/* 1074 */ 50040,
/* 1075 */ 1,
/* 1076 */ 50041,
/* 1077 */ -1066,
/* 1078 */ 2,
/* 1079 */ 1084,
/* 1080 */ 50046,
/* 1081 */ 1,
/* 1082 */ -1066,
/* 1083 */ 3,
/* 1084 */ 1089,
/* 1085 */ 50296,
/* 1086 */ 1,
/* 1087 */ -1066,
/* 1088 */ 4,
/* 1089 */ 1093,
/* 1090 */ 50294,
/* 1091 */ -1066,
/* 1092 */ 5,
/* 1093 */ 0,
/* 1094 */ 50295,
/* 1095 */ -1066,
/* 1096 */ 6,
/* 1097 */ 1102,
/* 1098 */ 50058,
/* 1099 */ 1,
/* 1100 */ -1097,
/* 1101 */ 1,
/* 1102 */ 0,
/* 1103 */ -1097,
/* 1104 */ 2,
/* 1105 */ 1109,
/* 1106 */ 1,
/* 1107 */ -1105,
/* 1108 */ 1,
/* 1109 */ 0,
/* 1110 */ -1105,
/* 1111 */ 2,
/* 1112 */ 1116,
/* 1113 */ 1,
/* 1114 */ -1112,
/* 1115 */ 1,
/* 1116 */ 1120,
/* 1117 */ 1,
/* 1118 */ -1112,
/* 1119 */ 2,
/* 1120 */ 0,
/* 1121 */ 50040,
/* 1122 */ 1,
/* 1123 */ 50041,
/* 1124 */ -1112,
/* 1125 */ 3,
/* 1126 */ 0,
/* 1127 */ 1,
/* 1128 */ 1,
/* 1129 */ -1126,
/* 1130 */ 1,
/* 1131 */ 1137,
/* 1132 */ 1,
/* 1133 */ 50044,
/* 1134 */ 1,
/* 1135 */ -1131,
/* 1136 */ 1,
/* 1137 */ 0,
/* 1138 */ -1131,
/* 1139 */ 2,
/* 1140 */ 1144,
/* 1141 */ 50304,
/* 1142 */ -1140,
/* 1143 */ 1,
/* 1144 */ 1148,
/* 1145 */ 50302,
/* 1146 */ -1140,
/* 1147 */ 2,
/* 1148 */ 1152,
/* 1149 */ 50303,
/* 1150 */ -1140,
/* 1151 */ 3,
/* 1152 */ 0,
/* 1153 */ 50289,
/* 1154 */ -1140,
/* 1155 */ 4,
/* 1156 */ 0,
/* 1157 */ 50299,
/* 1158 */ -1156,
/* 1159 */ 1,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 22002,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 22002,
/* 6 */ 9999,
/* 7 */ 22004,
/* 8 */ 9999,
/* 9 */ 22004,
/* 10 */ 9999,
/* 11 */ 22006,
/* 12 */ 22025,
/* 13 */ 9999,
/* 14 */ 22025,
/* 15 */ 9999,
/* 16 */ 9999,
/* 17 */ 22025,
/* 18 */ 9999,
/* 19 */ 26004,
/* 20 */ 9999,
/* 21 */ 26022,
/* 22 */ 9999,
/* 23 */ 27004,
/* 24 */ 9999,
/* 25 */ 27014,
/* 26 */ 9999,
/* 27 */ 31004,
/* 28 */ 31032,
/* 29 */ 31043,
/* 30 */ 31065,
/* 31 */ 9999,
/* 32 */ 31004,
/* 33 */ 9999,
/* 34 */ 31006,
/* 35 */ 9999,
/* 36 */ 31027,
/* 37 */ 9999,
/* 38 */ 9999,
/* 39 */ 31027,
/* 40 */ 9999,
/* 41 */ 31045,
/* 42 */ 9999,
/* 43 */ 31060,
/* 44 */ 9999,
/* 45 */ 9999,
/* 46 */ 31060,
/* 47 */ 9999,
/* 48 */ 9999,
/* 49 */ 9999,
/* 50 */ 31067,
/* 51 */ 9999,
/* 52 */ 31073,
/* 53 */ 9999,
/* 54 */ 31090,
/* 55 */ 9999,
/* 56 */ 35004,
/* 57 */ 35027,
/* 58 */ 9999,
/* 59 */ 9999,
/* 60 */ 35025,
/* 61 */ 9999,
/* 62 */ 35029,
/* 63 */ 9999,
/* 64 */ 35048,
/* 65 */ 9999,
/* 66 */ 9999,
/* 67 */ 35048,
/* 68 */ 9999,
/* 69 */ 39004,
/* 70 */ 39021,
/* 71 */ 9999,
/* 72 */ 39004,
/* 73 */ 9999,
/* 74 */ 39006,
/* 75 */ 39016,
/* 76 */ 9999,
/* 77 */ 39016,
/* 78 */ 9999,
/* 79 */ 9999,
/* 80 */ 39016,
/* 81 */ 9999,
/* 82 */ 43004,
/* 83 */ 43066,
/* 84 */ 9999,
/* 85 */ 43004,
/* 86 */ 9999,
/* 87 */ 43006,
/* 88 */ 9999,
/* 89 */ 43028,
/* 90 */ 9999,
/* 91 */ 43032,
/* 92 */ 9999,
/* 93 */ 43045,
/* 94 */ 9999,
/* 95 */ 43049,
/* 96 */ 9999,
/* 97 */ 43062,
/* 98 */ 9999,
/* 99 */ 43068,
/* 100 */ 9999,
/* 101 */ 43089,
/* 102 */ 9999,
/* 103 */ 9999,
/* 104 */ 43089,
/* 105 */ 9999,
/* 106 */ 9999,
/* 107 */ 9999,
/* 108 */ 47007,
/* 109 */ 9999,
/* 110 */ 9999,
/* 111 */ 9999,
/* 112 */ 48011,
/* 113 */ 9999,
/* 114 */ 9999,
/* 115 */ 9999,
/* 116 */ 49009,
/* 117 */ 9999,
/* 118 */ 9999,
/* 119 */ 9999,
/* 120 */ 50009,
/* 121 */ 9999,
/* 122 */ 9999,
/* 123 */ 9999,
/* 124 */ 51010,
/* 125 */ 9999,
/* 126 */ 9999,
/* 127 */ 9999,
/* 128 */ 56007,
/* 129 */ 9999,
/* 130 */ 9999,
/* 131 */ 9999,
/* 132 */ 57007,
/* 133 */ 9999,
/* 134 */ 9999,
/* 135 */ 9999,
/* 136 */ 58008,
/* 137 */ 9999,
/* 138 */ 9999,
/* 139 */ 9999,
/* 140 */ 59006,
/* 141 */ 9999,
/* 142 */ 9999,
/* 143 */ 9999,
/* 144 */ 60007,
/* 145 */ 9999,
/* 146 */ 9999,
/* 147 */ 9999,
/* 148 */ 61008,
/* 149 */ 9999,
/* 150 */ 9999,
/* 151 */ 9999,
/* 152 */ 62009,
/* 153 */ 9999,
/* 154 */ 9999,
/* 155 */ 9999,
/* 156 */ 63009,
/* 157 */ 9999,
/* 158 */ 9999,
/* 159 */ 9999,
/* 160 */ 64011,
/* 161 */ 9999,
/* 162 */ 65004,
/* 163 */ 9999,
/* 164 */ 65028,
/* 165 */ 9999,
/* 166 */ 66004,
/* 167 */ 9999,
/* 168 */ 66017,
/* 169 */ 9999,
/* 170 */ 71004,
/* 171 */ 9999,
/* 172 */ 71004,
/* 173 */ 9999,
/* 174 */ 9999,
/* 175 */ 9999,
/* 176 */ 71010,
/* 177 */ 9999,
/* 178 */ 9999,
/* 179 */ 9999,
/* 180 */ 72011,
/* 181 */ 9999,
/* 182 */ 76004,
/* 183 */ 76020,
/* 184 */ 9999,
/* 185 */ 76035,
/* 186 */ 9999,
/* 187 */ 9999,
/* 188 */ 76018,
/* 189 */ 9999,
/* 190 */ 77004,
/* 191 */ 77020,
/* 192 */ 9999,
/* 193 */ 77018,
/* 194 */ 9999,
/* 195 */ 76022,
/* 196 */ 9999,
/* 197 */ 76023,
/* 198 */ 9999,
/* 199 */ 9999,
/* 200 */ 76023,
/* 201 */ 9999,
/* 202 */ 81004,
/* 203 */ 9999,
/* 204 */ 81004,
/* 205 */ 9999,
/* 206 */ 9999,
/* 207 */ 9999,
/* 208 */ 81011,
/* 209 */ 9999,
/* 210 */ 9999,
/* 211 */ 9999,
/* 212 */ 81019,
/* 213 */ 9999,
/* 214 */ 85004,
/* 215 */ 85033,
/* 216 */ 9999,
/* 217 */ 85004,
/* 218 */ 9999,
/* 219 */ 85006,
/* 220 */ 9999,
/* 221 */ 85028,
/* 222 */ 9999,
/* 223 */ 9999,
/* 224 */ 85028,
/* 225 */ 9999,
/* 226 */ 89004,
/* 227 */ 89034,
/* 228 */ 9999,
/* 229 */ 89004,
/* 230 */ 9999,
/* 231 */ 89006,
/* 232 */ 9999,
/* 233 */ 9999,
/* 234 */ 89025,
/* 235 */ 9999,
/* 236 */ 9999,
/* 237 */ 89025,
/* 238 */ 9999,
/* 239 */ 93004,
/* 240 */ 93024,
/* 241 */ 9999,
/* 242 */ 93004,
/* 243 */ 9999,
/* 244 */ 93006,
/* 245 */ 9999,
/* 246 */ 9999,
/* 247 */ 93015,
/* 248 */ 9999,
/* 249 */ 9999,
/* 250 */ 93015,
/* 251 */ 9999,
/* 252 */ 97004,
/* 253 */ 97029,
/* 254 */ 9999,
/* 255 */ 9999,
/* 256 */ 97027,
/* 257 */ 9999,
/* 258 */ 101004,
/* 259 */ 101040,
/* 260 */ 9999,
/* 261 */ 101004,
/* 262 */ 9999,
/* 263 */ 101006,
/* 264 */ 9999,
/* 265 */ 101019,
/* 266 */ 9999,
/* 267 */ 101023,
/* 268 */ 9999,
/* 269 */ 101036,
/* 270 */ 9999,
/* 271 */ 101042,
/* 272 */ 9999,
/* 273 */ 101065,
/* 274 */ 9999,
/* 275 */ 9999,
/* 276 */ 101065,
/* 277 */ 9999,
/* 278 */ 105004,
/* 279 */ 105036,
/* 280 */ 9999,
/* 281 */ 105004,
/* 282 */ 9999,
/* 283 */ 105006,
/* 284 */ 9999,
/* 285 */ 9999,
/* 286 */ 105027,
/* 287 */ 9999,
/* 288 */ 9999,
/* 289 */ 105027,
/* 290 */ 9999,
/* 291 */ 109004,
/* 292 */ 9999,
/* 293 */ 109013,
/* 294 */ 9999,
/* 295 */ 110004,
/* 296 */ 9999,
/* 297 */ 110024,
/* 298 */ 9999,
/* 299 */ 110004,
/* 300 */ 9999,
/* 301 */ 110006,
/* 302 */ 9999,
/* 303 */ 110015,
/* 304 */ 9999,
/* 305 */ 9999,
/* 306 */ 110015,
/* 307 */ 9999,
/* 308 */ 9999,
/* 309 */ 114009,
/* 310 */ 9999,
/* 311 */ 114024,
/* 312 */ 9999,
/* 313 */ 9999,
/* 314 */ 114007,
/* 315 */ 9999,
/* 316 */ 9999,
/* 317 */ 115009,
/* 318 */ 9999,
/* 319 */ 115007,
/* 320 */ 9999,
/* 321 */ 114011,
/* 322 */ 9999,
/* 323 */ 114012,
/* 324 */ 9999,
/* 325 */ 9999,
/* 326 */ 114012,
/* 327 */ 9999,
/* 328 */ 119004,
/* 329 */ 119029,
/* 330 */ 9999,
/* 331 */ 119004,
/* 332 */ 9999,
/* 333 */ 119006,
/* 334 */ 9999,
/* 335 */ 9999,
/* 336 */ 119020,
/* 337 */ 9999,
/* 338 */ 9999,
/* 339 */ 119020,
/* 340 */ 9999,
/* 341 */ 123004,
/* 342 */ 123010,
/* 343 */ 9999,
/* 344 */ 123005,
/* 345 */ 9999,
/* 346 */ 9999,
/* 347 */ 123016,
/* 348 */ 9999,
/* 349 */ 123012,
/* 350 */ 9999,
/* 351 */ 9999,
/* 352 */ 123012,
/* 353 */ 9999,
/* 354 */ 127004,
/* 355 */ 127017,
/* 356 */ 9999,
/* 357 */ 127004,
/* 358 */ 9999,
/* 359 */ 127006,
/* 360 */ 9999,
/* 361 */ 127012,
/* 362 */ 9999,
/* 363 */ 9999,
/* 364 */ 127012,
/* 365 */ 9999,
/* 366 */ 131004,
/* 367 */ 9999,
/* 368 */ 131005,
/* 369 */ 9999,
/* 370 */ 9999,
/* 371 */ 132008,
/* 372 */ 9999,
/* 373 */ 9999,
/* 374 */ 132004,
/* 375 */ 9999,
/* 376 */ 133004,
/* 377 */ 133022,
/* 378 */ 9999,
/* 379 */ 133020,
/* 380 */ 9999,
/* 381 */ 9999,
/* 382 */ 133028,
/* 383 */ 9999,
/* 384 */ 9999,
/* 385 */ 133024,
/* 386 */ 9999,
/* 387 */ 9999,
/* 388 */ 134009,
/* 389 */ 9999,
/* 390 */ 9999,
/* 391 */ 134005,
/* 392 */ 9999,
/* 393 */ 9999,
/* 394 */ 135009,
/* 395 */ 9999,
/* 396 */ 9999,
/* 397 */ 135005,
/* 398 */ 9999,
/* 399 */ 133030,
/* 400 */ 9999,
/* 401 */ 133039,
/* 402 */ 9999,
/* 403 */ 9999,
/* 404 */ 133039,
/* 405 */ 9999,
/* 406 */ 135011,
/* 407 */ 9999,
/* 408 */ 135025,
/* 409 */ 9999,
/* 410 */ 9999,
/* 411 */ 135025,
/* 412 */ 9999,
/* 413 */ 9999,
/* 414 */ 139008,
/* 415 */ 139033,
/* 416 */ 9999,
/* 417 */ 139004,
/* 418 */ 9999,
/* 419 */ 139010,
/* 420 */ 9999,
/* 421 */ 139028,
/* 422 */ 9999,
/* 423 */ 9999,
/* 424 */ 139028,
/* 425 */ 9999,
/* 426 */ 139035,
/* 427 */ 9999,
/* 428 */ 139041,
/* 429 */ 9999,
/* 430 */ 9999,
/* 431 */ 139041,
/* 432 */ 9999,
/* 433 */ 143004,
/* 434 */ 143029,
/* 435 */ 9999,
/* 436 */ 143004,
/* 437 */ 9999,
/* 438 */ 143006,
/* 439 */ 9999,
/* 440 */ 143024,
/* 441 */ 9999,
/* 442 */ 9999,
/* 443 */ 143024,
/* 444 */ 9999,
/* 445 */ 147004,
/* 446 */ 147019,
/* 447 */ 9999,
/* 448 */ 147017,
/* 449 */ 9999,
/* 450 */ 9999,
/* 451 */ 9999,
/* 452 */ 9999,
/* 453 */ 147021,
/* 454 */ 9999,
/* 455 */ 9999,
/* 456 */ 147021,
/* 457 */ 9999,
/* 458 */ 151004,
/* 459 */ 151028,
/* 460 */ 9999,
/* 461 */ 151004,
/* 462 */ 9999,
/* 463 */ 151006,
/* 464 */ 9999,
/* 465 */ 9999,
/* 466 */ 151019,
/* 467 */ 9999,
/* 468 */ 9999,
/* 469 */ 151019,
/* 470 */ 9999,
/* 471 */ 155004,
/* 472 */ 155027,
/* 473 */ 9999,
/* 474 */ 155025,
/* 475 */ 9999,
/* 476 */ 155029,
/* 477 */ 9999,
/* 478 */ 155038,
/* 479 */ 9999,
/* 480 */ 155042,
/* 481 */ 9999,
/* 482 */ 155042,
/* 483 */ 9999,
/* 484 */ 155044,
/* 485 */ 9999,
/* 486 */ 155062,
/* 487 */ 9999,
/* 488 */ 9999,
/* 489 */ 155062,
/* 490 */ 9999,
/* 491 */ 159004,
/* 492 */ 159029,
/* 493 */ 9999,
/* 494 */ 159004,
/* 495 */ 9999,
/* 496 */ 159006,
/* 497 */ 9999,
/* 498 */ 9999,
/* 499 */ 159020,
/* 500 */ 9999,
/* 501 */ 9999,
/* 502 */ 159020,
/* 503 */ 9999,
/* 504 */ 163004,
/* 505 */ 9999,
/* 506 */ 163024,
/* 507 */ 9999,
/* 508 */ 9999,
/* 509 */ 164008,
/* 510 */ 164025,
/* 511 */ 9999,
/* 512 */ 9999,
/* 513 */ 164004,
/* 514 */ 9999,
/* 515 */ 9999,
/* 516 */ 9999,
/* 517 */ 164027,
/* 518 */ 9999,
/* 519 */ 9999,
/* 520 */ 164027,
/* 521 */ 9999,
/* 522 */ 168004,
/* 523 */ 168030,
/* 524 */ 9999,
/* 525 */ 168004,
/* 526 */ 9999,
/* 527 */ 168006,
/* 528 */ 9999,
/* 529 */ 9999,
/* 530 */ 168021,
/* 531 */ 9999,
/* 532 */ 9999,
/* 533 */ 168021,
/* 534 */ 9999,
/* 535 */ 172004,
/* 536 */ 172029,
/* 537 */ 9999,
/* 538 */ 172027,
/* 539 */ 9999,
/* 540 */ 172031,
/* 541 */ 9999,
/* 542 */ 172049,
/* 543 */ 9999,
/* 544 */ 9999,
/* 545 */ 172049,
/* 546 */ 9999,
/* 547 */ 176004,
/* 548 */ 9999,
/* 549 */ 176010,
/* 550 */ 9999,
/* 551 */ 177004,
/* 552 */ 177017,
/* 553 */ 9999,
/* 554 */ 177004,
/* 555 */ 9999,
/* 556 */ 177006,
/* 557 */ 9999,
/* 558 */ 177012,
/* 559 */ 9999,
/* 560 */ 9999,
/* 561 */ 177012,
/* 562 */ 9999,
/* 563 */ 9999,
/* 564 */ 181008,
/* 565 */ 9999,
/* 566 */ 9999,
/* 567 */ 181004,
/* 568 */ 9999,
/* 569 */ 182004,
/* 570 */ 182036,
/* 571 */ 9999,
/* 572 */ 182004,
/* 573 */ 9999,
/* 574 */ 182006,
/* 575 */ 9999,
/* 576 */ 182031,
/* 577 */ 9999,
/* 578 */ 9999,
/* 579 */ 182031,
/* 580 */ 9999,
/* 581 */ 9999,
/* 582 */ 182042,
/* 583 */ 9999,
/* 584 */ 9999,
/* 585 */ 182038,
/* 586 */ 9999,
/* 587 */ 9999,
/* 588 */ 183009,
/* 589 */ 9999,
/* 590 */ 9999,
/* 591 */ 183005,
/* 592 */ 9999,
/* 593 */ 182044,
/* 594 */ 9999,
/* 595 */ 182053,
/* 596 */ 9999,
/* 597 */ 9999,
/* 598 */ 182053,
/* 599 */ 9999,
/* 600 */ 183011,
/* 601 */ 9999,
/* 602 */ 183029,
/* 603 */ 9999,
/* 604 */ 9999,
/* 605 */ 183029,
/* 606 */ 9999,
/* 607 */ 187004,
/* 608 */ 9999,
/* 609 */ 187005,
/* 610 */ 9999,
/* 611 */ 191004,
/* 612 */ 9999,
/* 613 */ 191020,
/* 614 */ 9999,
/* 615 */ 192004,
/* 616 */ 9999,
/* 617 */ 192023,
/* 618 */ 9999,
/* 619 */ 193004,
/* 620 */ 9999,
/* 621 */ 193021,
/* 622 */ 9999,
/* 623 */ 194004,
/* 624 */ 9999,
/* 625 */ 194022,
/* 626 */ 9999,
/* 627 */ 195004,
/* 628 */ 9999,
/* 629 */ 195022,
/* 630 */ 9999,
/* 631 */ 196004,
/* 632 */ 9999,
/* 633 */ 196017,
/* 634 */ 9999,
/* 635 */ 197004,
/* 636 */ 9999,
/* 637 */ 197018,
/* 638 */ 9999,
/* 639 */ 198004,
/* 640 */ 9999,
/* 641 */ 198018,
/* 642 */ 9999,
/* 643 */ 202004,
/* 644 */ 9999,
/* 645 */ 202014,
/* 646 */ 9999,
/* 647 */ 202005,
/* 648 */ 9999,
/* 649 */ 9999,
/* 650 */ 203009,
/* 651 */ 9999,
/* 652 */ 203037,
/* 653 */ 9999,
/* 654 */ 203007,
/* 655 */ 9999,
/* 656 */ 9999,
/* 657 */ 9999,
/* 658 */ 204016,
/* 659 */ 9999,
/* 660 */ 204010,
/* 661 */ 9999,
/* 662 */ 208004,
/* 663 */ 9999,
/* 664 */ 9999,
/* 665 */ 208004,
/* 666 */ 9999,
/* 667 */ 208006,
/* 668 */ 9999,
/* 669 */ 208015,
/* 670 */ 9999,
/* 671 */ 9999,
/* 672 */ 208015,
/* 673 */ 9999,
/* 674 */ 9999,
/* 675 */ 212008,
/* 676 */ 212030,
/* 677 */ 9999,
/* 678 */ 9999,
/* 679 */ 212004,
/* 680 */ 9999,
/* 681 */ 212010,
/* 682 */ 9999,
/* 683 */ 212025,
/* 684 */ 9999,
/* 685 */ 9999,
/* 686 */ 212025,
/* 687 */ 9999,
/* 688 */ 212032,
/* 689 */ 9999,
/* 690 */ 212045,
/* 691 */ 9999,
/* 692 */ 9999,
/* 693 */ 212045,
/* 694 */ 9999,
/* 695 */ 221004,
/* 696 */ 221019,
/* 697 */ 9999,
/* 698 */ 221004,
/* 699 */ 9999,
/* 700 */ 221006,
/* 701 */ 221014,
/* 702 */ 9999,
/* 703 */ 221014,
/* 704 */ 9999,
/* 705 */ 9999,
/* 706 */ 221014,
/* 707 */ 9999,
/* 708 */ 9999,
/* 709 */ 9999,
/* 710 */ 225011,
/* 711 */ 9999,
/* 712 */ 225029,
/* 713 */ 225039,
/* 714 */ 9999,
/* 715 */ 225005,
/* 716 */ 9999,
/* 717 */ 9999,
/* 718 */ 9999,
/* 719 */ 226015,
/* 720 */ 9999,
/* 721 */ 226033,
/* 722 */ 9999,
/* 723 */ 226009,
/* 724 */ 9999,
/* 725 */ 9999,
/* 726 */ 225046,
/* 727 */ 9999,
/* 728 */ 225044,
/* 729 */ 9999,
/* 730 */ 9999,
/* 731 */ 225044,
/* 732 */ 9999,
/* 733 */ 9999,
/* 734 */ 9999,
/* 735 */ 230014,
/* 736 */ 9999,
/* 737 */ 230032,
/* 738 */ 9999,
/* 739 */ 230008,
/* 740 */ 9999,
/* 741 */ 9999,
/* 742 */ 231007,
/* 743 */ 9999,
/* 744 */ 9999,
/* 745 */ 231027,
/* 746 */ 9999,
/* 747 */ 9999,
/* 748 */ 9999,
/* 749 */ 231005,
/* 750 */ 9999,
/* 751 */ 9999,
/* 752 */ 9999,
/* 753 */ 232012,
/* 754 */ 9999,
/* 755 */ 232035,
/* 756 */ 9999,
/* 757 */ 232058,
/* 758 */ 9999,
/* 759 */ 232081,
/* 760 */ 9999,
/* 761 */ 232006,
/* 762 */ 9999,
/* 763 */ 232014,
/* 764 */ 9999,
/* 765 */ 232023,
/* 766 */ 9999,
/* 767 */ 9999,
/* 768 */ 232023,
/* 769 */ 9999,
/* 770 */ 232037,
/* 771 */ 9999,
/* 772 */ 232046,
/* 773 */ 9999,
/* 774 */ 9999,
/* 775 */ 232046,
/* 776 */ 9999,
/* 777 */ 232060,
/* 778 */ 9999,
/* 779 */ 232069,
/* 780 */ 9999,
/* 781 */ 9999,
/* 782 */ 232069,
/* 783 */ 9999,
/* 784 */ 9999,
/* 785 */ 236009,
/* 786 */ 9999,
/* 787 */ 9999,
/* 788 */ 236007,
/* 789 */ 9999,
/* 790 */ 9999,
/* 791 */ 9999,
/* 792 */ 9999,
/* 793 */ 237011,
/* 794 */ 9999,
/* 795 */ 9999,
/* 796 */ 9999,
/* 797 */ 9999,
/* 798 */ 238008,
/* 799 */ 9999,
/* 800 */ 9999,
/* 801 */ 239011,
/* 802 */ 9999,
/* 803 */ 9999,
/* 804 */ 239009,
/* 805 */ 9999,
/* 806 */ 239013,
/* 807 */ 9999,
/* 808 */ 239022,
/* 809 */ 9999,
/* 810 */ 9999,
/* 811 */ 239022,
/* 812 */ 9999,
/* 813 */ 9999,
/* 814 */ 243010,
/* 815 */ 9999,
/* 816 */ 9999,
/* 817 */ 243008,
/* 818 */ 9999,
/* 819 */ 9999,
/* 820 */ 247010,
/* 821 */ 247025,
/* 822 */ 9999,
/* 823 */ 9999,
/* 824 */ 247008,
/* 825 */ 9999,
/* 826 */ 247012,
/* 827 */ 9999,
/* 828 */ 247013,
/* 829 */ 9999,
/* 830 */ 247013,
/* 831 */ 9999,
/* 832 */ 9999,
/* 833 */ 247013,
/* 834 */ 9999,
/* 835 */ 251004,
/* 836 */ 9999,
/* 837 */ 251024,
/* 838 */ 9999,
/* 839 */ 252004,
/* 840 */ 9999,
/* 841 */ 252022,
/* 842 */ 9999,
/* 843 */ 252013,
/* 844 */ 9999,
/* 845 */ 256004,
/* 846 */ 9999,
/* 847 */ 256025,
/* 848 */ 9999,
/* 849 */ 257004,
/* 850 */ 257025,
/* 851 */ 257049,
/* 852 */ 9999,
/* 853 */ 257019,
/* 854 */ 9999,
/* 855 */ 9999,
/* 856 */ 9999,
/* 857 */ 261009,
/* 858 */ 9999,
/* 859 */ 9999,
/* 860 */ 9999,
/* 861 */ 262004,
/* 862 */ 9999,
/* 863 */ 266004,
/* 864 */ 9999,
/* 865 */ 266024,
/* 866 */ 9999,
/* 867 */ 267004,
/* 868 */ 9999,
/* 869 */ 267035,
/* 870 */ 9999,
/* 871 */ 267053,
/* 872 */ 9999,
/* 873 */ 267024,
/* 874 */ 9999,
/* 875 */ 271004,
/* 876 */ 9999,
/* 877 */ 271025,
/* 878 */ 9999,
/* 879 */ 275004,
/* 880 */ 9999,
/* 881 */ 275025,
/* 882 */ 9999,
/* 883 */ 276004,
/* 884 */ 9999,
/* 885 */ 276042,
/* 886 */ 9999,
/* 887 */ 276024,
/* 888 */ 9999,
/* 889 */ 280004,
/* 890 */ 9999,
/* 891 */ 280026,
/* 892 */ 9999,
/* 893 */ 281004,
/* 894 */ 9999,
/* 895 */ 281044,
/* 896 */ 9999,
/* 897 */ 281025,
/* 898 */ 9999,
/* 899 */ 285004,
/* 900 */ 9999,
/* 901 */ 285026,
/* 902 */ 9999,
/* 903 */ 286004,
/* 904 */ 9999,
/* 905 */ 286037,
/* 906 */ 9999,
/* 907 */ 286026,
/* 908 */ 9999,
/* 909 */ 290004,
/* 910 */ 9999,
/* 911 */ 290017,
/* 912 */ 9999,
/* 913 */ 291004,
/* 914 */ 9999,
/* 915 */ 291037,
/* 916 */ 9999,
/* 917 */ 291026,
/* 918 */ 9999,
/* 919 */ 295004,
/* 920 */ 9999,
/* 921 */ 295022,
/* 922 */ 9999,
/* 923 */ 296004,
/* 924 */ 9999,
/* 925 */ 296027,
/* 926 */ 9999,
/* 927 */ 296017,
/* 928 */ 9999,
/* 929 */ 300004,
/* 930 */ 9999,
/* 931 */ 300019,
/* 932 */ 9999,
/* 933 */ 301004,
/* 934 */ 9999,
/* 935 */ 301039,
/* 936 */ 9999,
/* 937 */ 301022,
/* 938 */ 9999,
/* 939 */ 305004,
/* 940 */ 9999,
/* 941 */ 305022,
/* 942 */ 9999,
/* 943 */ 306004,
/* 944 */ 9999,
/* 945 */ 306034,
/* 946 */ 9999,
/* 947 */ 306019,
/* 948 */ 9999,
/* 949 */ 310004,
/* 950 */ 9999,
/* 951 */ 310028,
/* 952 */ 9999,
/* 953 */ 311022,
/* 954 */ 311046,
/* 955 */ 311074,
/* 956 */ 9999,
/* 957 */ 311004,
/* 958 */ 9999,
/* 959 */ 9999,
/* 960 */ 9999,
/* 961 */ 311048,
/* 962 */ 9999,
/* 963 */ 9999,
/* 964 */ 9999,
/* 965 */ 311054,
/* 966 */ 9999,
/* 967 */ 315004,
/* 968 */ 9999,
/* 969 */ 315018,
/* 970 */ 9999,
/* 971 */ 316022,
/* 972 */ 316052,
/* 973 */ 316099,
/* 974 */ 9999,
/* 975 */ 316004,
/* 976 */ 9999,
/* 977 */ 9999,
/* 978 */ 9999,
/* 979 */ 316054,
/* 980 */ 9999,
/* 981 */ 9999,
/* 982 */ 9999,
/* 983 */ 316060,
/* 984 */ 9999,
/* 985 */ 9999,
/* 986 */ 9999,
/* 987 */ 316080,
/* 988 */ 9999,
/* 989 */ 320004,
/* 990 */ 9999,
/* 991 */ 320019,
/* 992 */ 9999,
/* 993 */ 9999,
/* 994 */ 321008,
/* 995 */ 9999,
/* 996 */ 321022,
/* 997 */ 9999,
/* 998 */ 321004,
/* 999 */ 9999,
/* 1000 */ 325004,
/* 1001 */ 9999,
/* 1002 */ 325021,
/* 1003 */ 9999,
/* 1004 */ 326015,
/* 1005 */ 326062,
/* 1006 */ 9999,
/* 1007 */ 326004,
/* 1008 */ 9999,
/* 1009 */ 327004,
/* 1010 */ 327023,
/* 1011 */ 9999,
/* 1012 */ 327017,
/* 1013 */ 9999,
/* 1014 */ 9999,
/* 1015 */ 328011,
/* 1016 */ 9999,
/* 1017 */ 328009,
/* 1018 */ 9999,
/* 1019 */ 9999,
/* 1020 */ 9999,
/* 1021 */ 329015,
/* 1022 */ 9999,
/* 1023 */ 9999,
/* 1024 */ 329009,
/* 1025 */ 9999,
/* 1026 */ 9999,
/* 1027 */ 9999,
/* 1028 */ 326022,
/* 1029 */ 9999,
/* 1030 */ 9999,
/* 1031 */ 9999,
/* 1032 */ 326044,
/* 1033 */ 9999,
/* 1034 */ 9999,
/* 1035 */ 9999,
/* 1036 */ 333004,
/* 1037 */ 9999,
/* 1038 */ 9999,
/* 1039 */ 9999,
/* 1040 */ 334004,
/* 1041 */ 9999,
/* 1042 */ 9999,
/* 1043 */ 9999,
/* 1044 */ 335004,
/* 1045 */ 9999,
/* 1046 */ 9999,
/* 1047 */ 9999,
/* 1048 */ 336004,
/* 1049 */ 9999,
/* 1050 */ 9999,
/* 1051 */ 9999,
/* 1052 */ 337004,
/* 1053 */ 9999,
/* 1054 */ 9999,
/* 1055 */ 9999,
/* 1056 */ 338004,
/* 1057 */ 9999,
/* 1058 */ 342004,
/* 1059 */ 9999,
/* 1060 */ 342021,
/* 1061 */ 9999,
/* 1062 */ 343004,
/* 1063 */ 344003,
/* 1064 */ 9999,
/* 1065 */ 343021,
/* 1066 */ 9999,
/* 1067 */ 9999,
/* 1068 */ 344009,
/* 1069 */ 344054,
/* 1070 */ 9999,
/* 1071 */ 9999,
/* 1072 */ 344005,
/* 1073 */ 9999,
/* 1074 */ 9999,
/* 1075 */ 345009,
/* 1076 */ 9999,
/* 1077 */ 9999,
/* 1078 */ 345005,
/* 1079 */ 9999,
/* 1080 */ 9999,
/* 1081 */ 346009,
/* 1082 */ 9999,
/* 1083 */ 346005,
/* 1084 */ 9999,
/* 1085 */ 9999,
/* 1086 */ 347012,
/* 1087 */ 9999,
/* 1088 */ 347010,
/* 1089 */ 9999,
/* 1090 */ 9999,
/* 1091 */ 9999,
/* 1092 */ 348010,
/* 1093 */ 9999,
/* 1094 */ 9999,
/* 1095 */ 9999,
/* 1096 */ 349010,
/* 1097 */ 9999,
/* 1098 */ 9999,
/* 1099 */ 344060,
/* 1100 */ 9999,
/* 1101 */ 344056,
/* 1102 */ 9999,
/* 1103 */ 9999,
/* 1104 */ 344056,
/* 1105 */ 9999,
/* 1106 */ 345011,
/* 1107 */ 9999,
/* 1108 */ 345034,
/* 1109 */ 9999,
/* 1110 */ 9999,
/* 1111 */ 345034,
/* 1112 */ 9999,
/* 1113 */ 354004,
/* 1114 */ 9999,
/* 1115 */ 354005,
/* 1116 */ 9999,
/* 1117 */ 355004,
/* 1118 */ 9999,
/* 1119 */ 355011,
/* 1120 */ 9999,
/* 1121 */ 9999,
/* 1122 */ 356008,
/* 1123 */ 9999,
/* 1124 */ 9999,
/* 1125 */ 356004,
/* 1126 */ 9999,
/* 1127 */ 360044,
/* 1128 */ 360111,
/* 1129 */ 9999,
/* 1130 */ 360004,
/* 1131 */ 9999,
/* 1132 */ 360046,
/* 1133 */ 9999,
/* 1134 */ 360066,
/* 1135 */ 9999,
/* 1136 */ 360066,
/* 1137 */ 9999,
/* 1138 */ 9999,
/* 1139 */ 360066,
/* 1140 */ 9999,
/* 1141 */ 9999,
/* 1142 */ 9999,
/* 1143 */ 364011,
/* 1144 */ 9999,
/* 1145 */ 9999,
/* 1146 */ 9999,
/* 1147 */ 365012,
/* 1148 */ 9999,
/* 1149 */ 9999,
/* 1150 */ 9999,
/* 1151 */ 366013,
/* 1152 */ 9999,
/* 1153 */ 9999,
/* 1154 */ 9999,
/* 1155 */ 367009,
/* 1156 */ 9999,
/* 1157 */ 9999,
/* 1158 */ 9999,
/* 1159 */ 372013,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[1161];
*/
int TABLE[259][308];
init_dirsets() {
TABLE[135][0] = 1;
TABLE[135][59] = 1;
TABLE[135][123] = 1;
TABLE[135][40] = 1;
TABLE[135][42] = 1;
TABLE[135][299] = 1;
TABLE[135][285] = 1;
TABLE[135][259] = 1;
TABLE[135][276] = 1;
TABLE[135][272] = 1;
TABLE[135][273] = 1;
TABLE[135][268] = 1;
TABLE[135][264] = 1;
TABLE[135][277] = 1;
TABLE[135][284] = 1;
TABLE[135][256] = 1;
TABLE[135][274] = 1;
TABLE[135][279] = 1;
TABLE[135][267] = 1;
TABLE[135][282] = 1;
TABLE[135][286] = 1;
TABLE[135][260] = 1;
TABLE[135][266] = 1;
TABLE[135][283] = 1;
TABLE[135][280] = 1;
TABLE[1][0] = 1;
TABLE[1][59] = 1;
TABLE[1][40] = 1;
TABLE[1][123] = 1;
TABLE[1][282] = 1;
TABLE[1][267] = 1;
TABLE[1][279] = 1;
TABLE[1][274] = 1;
TABLE[1][256] = 1;
TABLE[1][284] = 1;
TABLE[1][277] = 1;
TABLE[1][264] = 1;
TABLE[1][268] = 1;
TABLE[1][273] = 1;
TABLE[1][272] = 1;
TABLE[1][276] = 1;
TABLE[1][259] = 1;
TABLE[1][285] = 1;
TABLE[1][299] = 1;
TABLE[1][42] = 1;
TABLE[1][266] = 1;
TABLE[1][260] = 1;
TABLE[1][286] = 1;
TABLE[1][280] = 1;
TABLE[1][283] = 1;
TABLE[136][0] = 1;
TABLE[136][59] = 1;
TABLE[136][123] = 1;
TABLE[136][40] = 1;
TABLE[136][42] = 1;
TABLE[136][299] = 1;
TABLE[136][285] = 1;
TABLE[136][259] = 1;
TABLE[136][276] = 1;
TABLE[136][272] = 1;
TABLE[136][273] = 1;
TABLE[136][268] = 1;
TABLE[136][264] = 1;
TABLE[136][277] = 1;
TABLE[136][284] = 1;
TABLE[136][256] = 1;
TABLE[136][274] = 1;
TABLE[136][279] = 1;
TABLE[136][267] = 1;
TABLE[136][282] = 1;
TABLE[136][286] = 1;
TABLE[136][260] = 1;
TABLE[136][266] = 1;
TABLE[136][283] = 1;
TABLE[136][280] = 1;
TABLE[213][0] = 1;
TABLE[2][0] = 1;
TABLE[2][59] = 1;
TABLE[2][40] = 1;
TABLE[2][123] = 1;
TABLE[2][299] = 1;
TABLE[2][42] = 1;
TABLE[2][285] = 1;
TABLE[2][259] = 1;
TABLE[2][276] = 1;
TABLE[2][272] = 1;
TABLE[2][273] = 1;
TABLE[2][268] = 1;
TABLE[2][264] = 1;
TABLE[2][277] = 1;
TABLE[2][284] = 1;
TABLE[2][256] = 1;
TABLE[2][274] = 1;
TABLE[2][279] = 1;
TABLE[2][267] = 1;
TABLE[2][282] = 1;
TABLE[2][286] = 1;
TABLE[2][260] = 1;
TABLE[2][266] = 1;
TABLE[2][283] = 1;
TABLE[2][280] = 1;
TABLE[3][282] = 1;
TABLE[3][267] = 1;
TABLE[3][279] = 1;
TABLE[3][274] = 1;
TABLE[3][256] = 1;
TABLE[3][284] = 1;
TABLE[3][277] = 1;
TABLE[3][264] = 1;
TABLE[3][268] = 1;
TABLE[3][273] = 1;
TABLE[3][272] = 1;
TABLE[3][276] = 1;
TABLE[3][259] = 1;
TABLE[3][285] = 1;
TABLE[3][266] = 1;
TABLE[3][260] = 1;
TABLE[3][286] = 1;
TABLE[3][280] = 1;
TABLE[3][283] = 1;
TABLE[4][59] = 1;
TABLE[4][123] = 1;
TABLE[4][40] = 1;
TABLE[4][42] = 1;
TABLE[4][299] = 1;
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
TABLE[4][266] = 1;
TABLE[4][260] = 1;
TABLE[4][286] = 1;
TABLE[4][280] = 1;
TABLE[4][283] = 1;
TABLE[137][285] = 1;
TABLE[137][259] = 1;
TABLE[137][276] = 1;
TABLE[137][272] = 1;
TABLE[137][273] = 1;
TABLE[137][268] = 1;
TABLE[137][264] = 1;
TABLE[137][277] = 1;
TABLE[137][284] = 1;
TABLE[137][256] = 1;
TABLE[137][274] = 1;
TABLE[137][279] = 1;
TABLE[137][267] = 1;
TABLE[137][282] = 1;
TABLE[137][286] = 1;
TABLE[137][260] = 1;
TABLE[137][266] = 1;
TABLE[137][283] = 1;
TABLE[137][280] = 1;
TABLE[214][40] = 1;
TABLE[214][42] = 1;
TABLE[214][299] = 1;
TABLE[214][282] = 1;
TABLE[214][267] = 1;
TABLE[214][279] = 1;
TABLE[214][274] = 1;
TABLE[214][256] = 1;
TABLE[214][284] = 1;
TABLE[214][277] = 1;
TABLE[214][264] = 1;
TABLE[214][268] = 1;
TABLE[214][273] = 1;
TABLE[214][272] = 1;
TABLE[214][276] = 1;
TABLE[214][259] = 1;
TABLE[214][285] = 1;
TABLE[214][266] = 1;
TABLE[214][260] = 1;
TABLE[214][286] = 1;
TABLE[214][280] = 1;
TABLE[214][283] = 1;
TABLE[214][59] = 1;
TABLE[214][123] = 1;
TABLE[138][59] = 1;
TABLE[138][123] = 1;
TABLE[138][285] = 1;
TABLE[138][259] = 1;
TABLE[138][276] = 1;
TABLE[138][272] = 1;
TABLE[138][273] = 1;
TABLE[138][268] = 1;
TABLE[138][264] = 1;
TABLE[138][277] = 1;
TABLE[138][284] = 1;
TABLE[138][256] = 1;
TABLE[138][274] = 1;
TABLE[138][279] = 1;
TABLE[138][267] = 1;
TABLE[138][282] = 1;
TABLE[138][286] = 1;
TABLE[138][260] = 1;
TABLE[138][266] = 1;
TABLE[138][283] = 1;
TABLE[138][280] = 1;
TABLE[215][59] = 1;
TABLE[215][123] = 1;
TABLE[139][59] = 1;
TABLE[140][123] = 1;
TABLE[5][285] = 1;
TABLE[5][259] = 1;
TABLE[5][276] = 1;
TABLE[5][272] = 1;
TABLE[5][273] = 1;
TABLE[5][268] = 1;
TABLE[5][264] = 1;
TABLE[5][277] = 1;
TABLE[5][284] = 1;
TABLE[5][256] = 1;
TABLE[5][274] = 1;
TABLE[5][279] = 1;
TABLE[5][267] = 1;
TABLE[5][282] = 1;
TABLE[5][286] = 1;
TABLE[5][260] = 1;
TABLE[5][266] = 1;
TABLE[5][283] = 1;
TABLE[5][280] = 1;
TABLE[141][59] = 1;
TABLE[141][44] = 1;
TABLE[141][123] = 1;
TABLE[141][61] = 1;
TABLE[141][278] = 1;
TABLE[141][40] = 1;
TABLE[141][295] = 1;
TABLE[141][294] = 1;
TABLE[141][33] = 1;
TABLE[141][126] = 1;
TABLE[141][45] = 1;
TABLE[141][43] = 1;
TABLE[141][38] = 1;
TABLE[141][299] = 1;
TABLE[141][42] = 1;
TABLE[141][289] = 1;
TABLE[141][303] = 1;
TABLE[141][302] = 1;
TABLE[141][304] = 1;
TABLE[216][59] = 1;
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
TABLE[6][286] = 1;
TABLE[6][260] = 1;
TABLE[6][266] = 1;
TABLE[6][283] = 1;
TABLE[6][280] = 1;
TABLE[142][282] = 1;
TABLE[142][267] = 1;
TABLE[142][279] = 1;
TABLE[142][274] = 1;
TABLE[142][256] = 1;
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
TABLE[142][260] = 1;
TABLE[142][286] = 1;
TABLE[142][280] = 1;
TABLE[142][283] = 1;
TABLE[217][282] = 1;
TABLE[217][267] = 1;
TABLE[217][279] = 1;
TABLE[217][274] = 1;
TABLE[217][256] = 1;
TABLE[217][284] = 1;
TABLE[217][277] = 1;
TABLE[217][264] = 1;
TABLE[217][268] = 1;
TABLE[217][273] = 1;
TABLE[217][272] = 1;
TABLE[217][276] = 1;
TABLE[217][259] = 1;
TABLE[217][285] = 1;
TABLE[217][266] = 1;
TABLE[217][260] = 1;
TABLE[217][286] = 1;
TABLE[217][280] = 1;
TABLE[217][283] = 1;
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
TABLE[7][266] = 1;
TABLE[7][260] = 1;
TABLE[7][286] = 1;
TABLE[7][280] = 1;
TABLE[7][283] = 1;
TABLE[143][256] = 1;
TABLE[143][274] = 1;
TABLE[143][279] = 1;
TABLE[143][267] = 1;
TABLE[143][282] = 1;
TABLE[144][285] = 1;
TABLE[144][259] = 1;
TABLE[144][276] = 1;
TABLE[144][272] = 1;
TABLE[144][273] = 1;
TABLE[144][268] = 1;
TABLE[144][264] = 1;
TABLE[144][277] = 1;
TABLE[144][284] = 1;
TABLE[144][266] = 1;
TABLE[144][283] = 1;
TABLE[144][280] = 1;
TABLE[145][286] = 1;
TABLE[145][260] = 1;
TABLE[146][285] = 1;
TABLE[146][259] = 1;
TABLE[146][276] = 1;
TABLE[146][272] = 1;
TABLE[146][273] = 1;
TABLE[146][268] = 1;
TABLE[146][264] = 1;
TABLE[146][277] = 1;
TABLE[146][284] = 1;
TABLE[146][256] = 1;
TABLE[146][274] = 1;
TABLE[146][279] = 1;
TABLE[146][267] = 1;
TABLE[146][282] = 1;
TABLE[146][286] = 1;
TABLE[146][260] = 1;
TABLE[146][266] = 1;
TABLE[146][283] = 1;
TABLE[146][280] = 1;
TABLE[218][40] = 1;
TABLE[218][42] = 1;
TABLE[218][299] = 1;
TABLE[218][282] = 1;
TABLE[218][267] = 1;
TABLE[218][279] = 1;
TABLE[218][274] = 1;
TABLE[218][256] = 1;
TABLE[218][284] = 1;
TABLE[218][277] = 1;
TABLE[218][264] = 1;
TABLE[218][268] = 1;
TABLE[218][273] = 1;
TABLE[218][272] = 1;
TABLE[218][276] = 1;
TABLE[218][259] = 1;
TABLE[218][285] = 1;
TABLE[218][266] = 1;
TABLE[218][260] = 1;
TABLE[218][286] = 1;
TABLE[218][280] = 1;
TABLE[218][283] = 1;
TABLE[218][59] = 1;
TABLE[218][123] = 1;
TABLE[218][44] = 1;
TABLE[218][61] = 1;
TABLE[218][278] = 1;
TABLE[218][38] = 1;
TABLE[218][43] = 1;
TABLE[218][45] = 1;
TABLE[218][126] = 1;
TABLE[218][33] = 1;
TABLE[218][294] = 1;
TABLE[218][295] = 1;
TABLE[218][304] = 1;
TABLE[218][302] = 1;
TABLE[218][303] = 1;
TABLE[218][289] = 1;
TABLE[218][91] = 1;
TABLE[218][41] = 1;
TABLE[8][256] = 1;
TABLE[9][274] = 1;
TABLE[10][279] = 1;
TABLE[11][267] = 1;
TABLE[12][282] = 1;
TABLE[13][285] = 1;
TABLE[14][259] = 1;
TABLE[15][276] = 1;
TABLE[16][272] = 1;
TABLE[17][273] = 1;
TABLE[18][268] = 1;
TABLE[19][264] = 1;
TABLE[20][277] = 1;
TABLE[21][284] = 1;
TABLE[22][280] = 1;
TABLE[22][283] = 1;
TABLE[23][266] = 1;
TABLE[24][260] = 1;
TABLE[24][286] = 1;
TABLE[147][260] = 1;
TABLE[148][286] = 1;
TABLE[25][283] = 1;
TABLE[25][280] = 1;
TABLE[26][283] = 1;
TABLE[26][280] = 1;
TABLE[149][299] = 1;
TABLE[219][123] = 1;
TABLE[27][280] = 1;
TABLE[27][283] = 1;
TABLE[150][280] = 1;
TABLE[151][283] = 1;
TABLE[28][284] = 1;
TABLE[28][277] = 1;
TABLE[28][264] = 1;
TABLE[28][268] = 1;
TABLE[28][273] = 1;
TABLE[28][272] = 1;
TABLE[28][276] = 1;
TABLE[28][259] = 1;
TABLE[28][285] = 1;
TABLE[28][266] = 1;
TABLE[28][260] = 1;
TABLE[28][286] = 1;
TABLE[28][280] = 1;
TABLE[28][283] = 1;
TABLE[152][285] = 1;
TABLE[152][259] = 1;
TABLE[152][276] = 1;
TABLE[152][272] = 1;
TABLE[152][273] = 1;
TABLE[152][268] = 1;
TABLE[152][264] = 1;
TABLE[152][277] = 1;
TABLE[152][284] = 1;
TABLE[152][286] = 1;
TABLE[152][260] = 1;
TABLE[152][266] = 1;
TABLE[152][283] = 1;
TABLE[152][280] = 1;
TABLE[220][284] = 1;
TABLE[220][277] = 1;
TABLE[220][264] = 1;
TABLE[220][268] = 1;
TABLE[220][273] = 1;
TABLE[220][272] = 1;
TABLE[220][276] = 1;
TABLE[220][259] = 1;
TABLE[220][285] = 1;
TABLE[220][266] = 1;
TABLE[220][260] = 1;
TABLE[220][286] = 1;
TABLE[220][280] = 1;
TABLE[220][283] = 1;
TABLE[29][59] = 1;
TABLE[29][44] = 1;
TABLE[29][61] = 1;
TABLE[29][123] = 1;
TABLE[29][40] = 1;
TABLE[29][278] = 1;
TABLE[29][42] = 1;
TABLE[29][299] = 1;
TABLE[29][38] = 1;
TABLE[29][43] = 1;
TABLE[29][45] = 1;
TABLE[29][126] = 1;
TABLE[29][33] = 1;
TABLE[29][294] = 1;
TABLE[29][295] = 1;
TABLE[29][304] = 1;
TABLE[29][302] = 1;
TABLE[29][303] = 1;
TABLE[29][289] = 1;
TABLE[153][44] = 1;
TABLE[153][123] = 1;
TABLE[153][61] = 1;
TABLE[153][278] = 1;
TABLE[153][40] = 1;
TABLE[153][295] = 1;
TABLE[153][294] = 1;
TABLE[153][33] = 1;
TABLE[153][126] = 1;
TABLE[153][45] = 1;
TABLE[153][43] = 1;
TABLE[153][38] = 1;
TABLE[153][299] = 1;
TABLE[153][42] = 1;
TABLE[153][289] = 1;
TABLE[153][303] = 1;
TABLE[153][302] = 1;
TABLE[153][304] = 1;
TABLE[221][61] = 1;
TABLE[221][123] = 1;
TABLE[221][40] = 1;
TABLE[221][278] = 1;
TABLE[221][42] = 1;
TABLE[221][299] = 1;
TABLE[221][38] = 1;
TABLE[221][43] = 1;
TABLE[221][45] = 1;
TABLE[221][126] = 1;
TABLE[221][33] = 1;
TABLE[221][294] = 1;
TABLE[221][295] = 1;
TABLE[221][304] = 1;
TABLE[221][302] = 1;
TABLE[221][303] = 1;
TABLE[221][289] = 1;
TABLE[221][59] = 1;
TABLE[221][44] = 1;
TABLE[30][123] = 1;
TABLE[30][278] = 1;
TABLE[30][295] = 1;
TABLE[30][294] = 1;
TABLE[30][33] = 1;
TABLE[30][126] = 1;
TABLE[30][45] = 1;
TABLE[30][43] = 1;
TABLE[30][38] = 1;
TABLE[30][289] = 1;
TABLE[30][303] = 1;
TABLE[30][302] = 1;
TABLE[30][304] = 1;
TABLE[30][61] = 1;
TABLE[30][40] = 1;
TABLE[30][299] = 1;
TABLE[30][42] = 1;
TABLE[154][61] = 1;
TABLE[154][40] = 1;
TABLE[154][42] = 1;
TABLE[154][299] = 1;
TABLE[222][123] = 1;
TABLE[222][278] = 1;
TABLE[222][295] = 1;
TABLE[222][294] = 1;
TABLE[222][33] = 1;
TABLE[222][126] = 1;
TABLE[222][45] = 1;
TABLE[222][43] = 1;
TABLE[222][42] = 1;
TABLE[222][38] = 1;
TABLE[222][40] = 1;
TABLE[222][299] = 1;
TABLE[222][289] = 1;
TABLE[222][303] = 1;
TABLE[222][302] = 1;
TABLE[222][304] = 1;
TABLE[31][285] = 1;
TABLE[31][259] = 1;
TABLE[31][276] = 1;
TABLE[31][272] = 1;
TABLE[31][273] = 1;
TABLE[31][268] = 1;
TABLE[31][264] = 1;
TABLE[31][277] = 1;
TABLE[31][284] = 1;
TABLE[31][286] = 1;
TABLE[31][260] = 1;
TABLE[31][266] = 1;
TABLE[31][283] = 1;
TABLE[31][280] = 1;
TABLE[32][284] = 1;
TABLE[32][277] = 1;
TABLE[32][264] = 1;
TABLE[32][268] = 1;
TABLE[32][273] = 1;
TABLE[32][272] = 1;
TABLE[32][276] = 1;
TABLE[32][259] = 1;
TABLE[32][285] = 1;
TABLE[32][266] = 1;
TABLE[32][260] = 1;
TABLE[32][286] = 1;
TABLE[32][280] = 1;
TABLE[32][283] = 1;
TABLE[155][285] = 1;
TABLE[155][259] = 1;
TABLE[155][276] = 1;
TABLE[155][272] = 1;
TABLE[155][273] = 1;
TABLE[155][268] = 1;
TABLE[155][264] = 1;
TABLE[155][277] = 1;
TABLE[155][284] = 1;
TABLE[155][266] = 1;
TABLE[155][283] = 1;
TABLE[155][280] = 1;
TABLE[156][286] = 1;
TABLE[156][260] = 1;
TABLE[157][285] = 1;
TABLE[157][259] = 1;
TABLE[157][276] = 1;
TABLE[157][272] = 1;
TABLE[157][273] = 1;
TABLE[157][268] = 1;
TABLE[157][264] = 1;
TABLE[157][277] = 1;
TABLE[157][284] = 1;
TABLE[157][286] = 1;
TABLE[157][260] = 1;
TABLE[157][266] = 1;
TABLE[157][283] = 1;
TABLE[157][280] = 1;
TABLE[223][44] = 1;
TABLE[223][58] = 1;
TABLE[223][40] = 1;
TABLE[223][42] = 1;
TABLE[223][299] = 1;
TABLE[223][59] = 1;
TABLE[223][91] = 1;
TABLE[223][41] = 1;
TABLE[33][59] = 1;
TABLE[33][44] = 1;
TABLE[33][58] = 1;
TABLE[33][40] = 1;
TABLE[33][299] = 1;
TABLE[33][42] = 1;
TABLE[158][44] = 1;
TABLE[158][58] = 1;
TABLE[158][40] = 1;
TABLE[158][42] = 1;
TABLE[158][299] = 1;
TABLE[224][58] = 1;
TABLE[224][40] = 1;
TABLE[224][299] = 1;
TABLE[224][42] = 1;
TABLE[224][59] = 1;
TABLE[224][44] = 1;
TABLE[34][59] = 1;
TABLE[34][44] = 1;
TABLE[34][40] = 1;
TABLE[34][42] = 1;
TABLE[34][299] = 1;
TABLE[35][58] = 1;
TABLE[35][40] = 1;
TABLE[35][299] = 1;
TABLE[35][42] = 1;
TABLE[159][58] = 1;
TABLE[159][40] = 1;
TABLE[159][42] = 1;
TABLE[159][299] = 1;
TABLE[225][58] = 1;
TABLE[36][266] = 1;
TABLE[37][266] = 1;
TABLE[160][299] = 1;
TABLE[226][123] = 1;
TABLE[38][44] = 1;
TABLE[38][299] = 1;
TABLE[161][44] = 1;
TABLE[161][299] = 1;
TABLE[227][299] = 1;
TABLE[39][299] = 1;
TABLE[162][61] = 1;
TABLE[228][125] = 1;
TABLE[228][44] = 1;
TABLE[40][40] = 1;
TABLE[40][299] = 1;
TABLE[40][42] = 1;
TABLE[163][42] = 1;
TABLE[229][40] = 1;
TABLE[229][299] = 1;
TABLE[41][299] = 1;
TABLE[42][40] = 1;
TABLE[43][40] = 1;
TABLE[43][299] = 1;
TABLE[165][91] = 1;
TABLE[166][40] = 1;
TABLE[168][40] = 1;
TABLE[164][278] = 1;
TABLE[164][295] = 1;
TABLE[164][294] = 1;
TABLE[164][33] = 1;
TABLE[164][126] = 1;
TABLE[164][45] = 1;
TABLE[164][43] = 1;
TABLE[164][42] = 1;
TABLE[164][38] = 1;
TABLE[164][40] = 1;
TABLE[164][299] = 1;
TABLE[164][289] = 1;
TABLE[164][303] = 1;
TABLE[164][302] = 1;
TABLE[164][304] = 1;
TABLE[230][93] = 1;
TABLE[167][41] = 1;
TABLE[167][44] = 1;
TABLE[167][299] = 1;
TABLE[231][41] = 1;
TABLE[44][42] = 1;
TABLE[169][42] = 1;
TABLE[169][40] = 1;
TABLE[169][299] = 1;
TABLE[169][44] = 1;
TABLE[169][41] = 1;
TABLE[169][91] = 1;
TABLE[169][260] = 1;
TABLE[169][286] = 1;
TABLE[232][42] = 1;
TABLE[232][40] = 1;
TABLE[232][299] = 1;
TABLE[232][44] = 1;
TABLE[232][41] = 1;
TABLE[232][91] = 1;
TABLE[170][42] = 1;
TABLE[233][40] = 1;
TABLE[233][299] = 1;
TABLE[233][44] = 1;
TABLE[233][41] = 1;
TABLE[233][91] = 1;
TABLE[45][286] = 1;
TABLE[45][260] = 1;
TABLE[171][260] = 1;
TABLE[171][286] = 1;
TABLE[234][286] = 1;
TABLE[234][260] = 1;
TABLE[46][41] = 1;
TABLE[46][44] = 1;
TABLE[46][285] = 1;
TABLE[46][259] = 1;
TABLE[46][276] = 1;
TABLE[46][272] = 1;
TABLE[46][273] = 1;
TABLE[46][268] = 1;
TABLE[46][264] = 1;
TABLE[46][277] = 1;
TABLE[46][284] = 1;
TABLE[46][256] = 1;
TABLE[46][274] = 1;
TABLE[46][279] = 1;
TABLE[46][267] = 1;
TABLE[46][282] = 1;
TABLE[46][286] = 1;
TABLE[46][260] = 1;
TABLE[46][266] = 1;
TABLE[46][283] = 1;
TABLE[46][280] = 1;
TABLE[172][44] = 1;
TABLE[235][41] = 1;
TABLE[47][44] = 1;
TABLE[47][282] = 1;
TABLE[47][267] = 1;
TABLE[47][279] = 1;
TABLE[47][274] = 1;
TABLE[47][256] = 1;
TABLE[47][284] = 1;
TABLE[47][277] = 1;
TABLE[47][264] = 1;
TABLE[47][268] = 1;
TABLE[47][273] = 1;
TABLE[47][272] = 1;
TABLE[47][276] = 1;
TABLE[47][259] = 1;
TABLE[47][285] = 1;
TABLE[47][266] = 1;
TABLE[47][260] = 1;
TABLE[47][286] = 1;
TABLE[47][280] = 1;
TABLE[47][283] = 1;
TABLE[173][44] = 1;
TABLE[173][285] = 1;
TABLE[173][259] = 1;
TABLE[173][276] = 1;
TABLE[173][272] = 1;
TABLE[173][273] = 1;
TABLE[173][268] = 1;
TABLE[173][264] = 1;
TABLE[173][277] = 1;
TABLE[173][284] = 1;
TABLE[173][256] = 1;
TABLE[173][274] = 1;
TABLE[173][279] = 1;
TABLE[173][267] = 1;
TABLE[173][282] = 1;
TABLE[173][286] = 1;
TABLE[173][260] = 1;
TABLE[173][266] = 1;
TABLE[173][283] = 1;
TABLE[173][280] = 1;
TABLE[236][282] = 1;
TABLE[236][267] = 1;
TABLE[236][279] = 1;
TABLE[236][274] = 1;
TABLE[236][256] = 1;
TABLE[236][284] = 1;
TABLE[236][277] = 1;
TABLE[236][264] = 1;
TABLE[236][268] = 1;
TABLE[236][273] = 1;
TABLE[236][272] = 1;
TABLE[236][276] = 1;
TABLE[236][259] = 1;
TABLE[236][285] = 1;
TABLE[236][266] = 1;
TABLE[236][260] = 1;
TABLE[236][286] = 1;
TABLE[236][280] = 1;
TABLE[236][283] = 1;
TABLE[48][285] = 1;
TABLE[48][259] = 1;
TABLE[48][276] = 1;
TABLE[48][272] = 1;
TABLE[48][273] = 1;
TABLE[48][268] = 1;
TABLE[48][264] = 1;
TABLE[48][277] = 1;
TABLE[48][284] = 1;
TABLE[48][256] = 1;
TABLE[48][274] = 1;
TABLE[48][279] = 1;
TABLE[48][267] = 1;
TABLE[48][282] = 1;
TABLE[48][286] = 1;
TABLE[48][260] = 1;
TABLE[48][266] = 1;
TABLE[48][283] = 1;
TABLE[48][280] = 1;
TABLE[174][44] = 1;
TABLE[174][41] = 1;
TABLE[174][40] = 1;
TABLE[174][42] = 1;
TABLE[174][299] = 1;
TABLE[176][44] = 1;
TABLE[176][41] = 1;
TABLE[176][42] = 1;
TABLE[176][40] = 1;
TABLE[176][91] = 1;
TABLE[175][44] = 1;
TABLE[175][41] = 1;
TABLE[175][42] = 1;
TABLE[175][40] = 1;
TABLE[175][91] = 1;
TABLE[237][44] = 1;
TABLE[237][41] = 1;
TABLE[49][44] = 1;
TABLE[49][299] = 1;
TABLE[177][44] = 1;
TABLE[177][299] = 1;
TABLE[238][299] = 1;
TABLE[50][278] = 1;
TABLE[50][38] = 1;
TABLE[50][42] = 1;
TABLE[50][43] = 1;
TABLE[50][45] = 1;
TABLE[50][126] = 1;
TABLE[50][33] = 1;
TABLE[50][294] = 1;
TABLE[50][295] = 1;
TABLE[50][40] = 1;
TABLE[50][304] = 1;
TABLE[50][302] = 1;
TABLE[50][303] = 1;
TABLE[50][289] = 1;
TABLE[50][299] = 1;
TABLE[51][123] = 1;
TABLE[178][44] = 1;
TABLE[239][125] = 1;
TABLE[52][123] = 1;
TABLE[52][44] = 1;
TABLE[52][278] = 1;
TABLE[52][295] = 1;
TABLE[52][294] = 1;
TABLE[52][33] = 1;
TABLE[52][126] = 1;
TABLE[52][45] = 1;
TABLE[52][43] = 1;
TABLE[52][42] = 1;
TABLE[52][38] = 1;
TABLE[52][40] = 1;
TABLE[52][299] = 1;
TABLE[52][289] = 1;
TABLE[52][303] = 1;
TABLE[52][302] = 1;
TABLE[52][304] = 1;
TABLE[179][123] = 1;
TABLE[179][44] = 1;
TABLE[179][278] = 1;
TABLE[179][38] = 1;
TABLE[179][42] = 1;
TABLE[179][43] = 1;
TABLE[179][45] = 1;
TABLE[179][126] = 1;
TABLE[179][33] = 1;
TABLE[179][294] = 1;
TABLE[179][295] = 1;
TABLE[179][40] = 1;
TABLE[179][304] = 1;
TABLE[179][302] = 1;
TABLE[179][303] = 1;
TABLE[179][289] = 1;
TABLE[179][299] = 1;
TABLE[240][123] = 1;
TABLE[240][278] = 1;
TABLE[240][295] = 1;
TABLE[240][294] = 1;
TABLE[240][33] = 1;
TABLE[240][126] = 1;
TABLE[240][45] = 1;
TABLE[240][43] = 1;
TABLE[240][42] = 1;
TABLE[240][38] = 1;
TABLE[240][40] = 1;
TABLE[240][299] = 1;
TABLE[240][289] = 1;
TABLE[240][303] = 1;
TABLE[240][302] = 1;
TABLE[240][304] = 1;
TABLE[53][285] = 1;
TABLE[53][259] = 1;
TABLE[53][276] = 1;
TABLE[53][272] = 1;
TABLE[53][273] = 1;
TABLE[53][268] = 1;
TABLE[53][264] = 1;
TABLE[53][277] = 1;
TABLE[53][284] = 1;
TABLE[53][286] = 1;
TABLE[53][260] = 1;
TABLE[53][266] = 1;
TABLE[53][283] = 1;
TABLE[53][280] = 1;
TABLE[180][41] = 1;
TABLE[180][42] = 1;
TABLE[180][40] = 1;
TABLE[180][91] = 1;
TABLE[241][41] = 1;
TABLE[54][42] = 1;
TABLE[55][44] = 1;
TABLE[55][41] = 1;
TABLE[55][40] = 1;
TABLE[55][91] = 1;
TABLE[55][42] = 1;
TABLE[181][42] = 1;
TABLE[242][40] = 1;
TABLE[242][91] = 1;
TABLE[242][44] = 1;
TABLE[242][41] = 1;
TABLE[56][40] = 1;
TABLE[57][40] = 1;
TABLE[57][91] = 1;
TABLE[182][40] = 1;
TABLE[182][91] = 1;
TABLE[243][91] = 1;
TABLE[243][40] = 1;
TABLE[184][91] = 1;
TABLE[186][40] = 1;
TABLE[183][278] = 1;
TABLE[183][295] = 1;
TABLE[183][294] = 1;
TABLE[183][33] = 1;
TABLE[183][126] = 1;
TABLE[183][45] = 1;
TABLE[183][43] = 1;
TABLE[183][42] = 1;
TABLE[183][38] = 1;
TABLE[183][40] = 1;
TABLE[183][299] = 1;
TABLE[183][289] = 1;
TABLE[183][303] = 1;
TABLE[183][302] = 1;
TABLE[183][304] = 1;
TABLE[244][93] = 1;
TABLE[185][41] = 1;
TABLE[185][44] = 1;
TABLE[185][282] = 1;
TABLE[185][267] = 1;
TABLE[185][279] = 1;
TABLE[185][274] = 1;
TABLE[185][256] = 1;
TABLE[185][284] = 1;
TABLE[185][277] = 1;
TABLE[185][264] = 1;
TABLE[185][268] = 1;
TABLE[185][273] = 1;
TABLE[185][272] = 1;
TABLE[185][276] = 1;
TABLE[185][259] = 1;
TABLE[185][285] = 1;
TABLE[185][266] = 1;
TABLE[185][260] = 1;
TABLE[185][286] = 1;
TABLE[185][280] = 1;
TABLE[185][283] = 1;
TABLE[245][41] = 1;
TABLE[58][299] = 1;
TABLE[59][258] = 1;
TABLE[59][262] = 1;
TABLE[59][299] = 1;
TABLE[60][125] = 1;
TABLE[60][262] = 1;
TABLE[60][258] = 1;
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
TABLE[60][305] = 1;
TABLE[60][306] = 1;
TABLE[60][265] = 1;
TABLE[60][59] = 1;
TABLE[60][278] = 1;
TABLE[60][295] = 1;
TABLE[60][294] = 1;
TABLE[60][33] = 1;
TABLE[60][126] = 1;
TABLE[60][45] = 1;
TABLE[60][43] = 1;
TABLE[60][42] = 1;
TABLE[60][38] = 1;
TABLE[60][40] = 1;
TABLE[60][299] = 1;
TABLE[60][289] = 1;
TABLE[60][303] = 1;
TABLE[60][302] = 1;
TABLE[60][304] = 1;
TABLE[61][123] = 1;
TABLE[62][271] = 1;
TABLE[62][281] = 1;
TABLE[63][287] = 1;
TABLE[63][263] = 1;
TABLE[63][269] = 1;
TABLE[64][270] = 1;
TABLE[64][261] = 1;
TABLE[64][257] = 1;
TABLE[64][275] = 1;
TABLE[65][305] = 1;
TABLE[66][306] = 1;
TABLE[67][299] = 1;
TABLE[68][258] = 1;
TABLE[69][262] = 1;
TABLE[70][59] = 1;
TABLE[70][278] = 1;
TABLE[70][38] = 1;
TABLE[70][42] = 1;
TABLE[70][43] = 1;
TABLE[70][45] = 1;
TABLE[70][126] = 1;
TABLE[70][33] = 1;
TABLE[70][294] = 1;
TABLE[70][295] = 1;
TABLE[70][40] = 1;
TABLE[70][304] = 1;
TABLE[70][302] = 1;
TABLE[70][303] = 1;
TABLE[70][289] = 1;
TABLE[70][299] = 1;
TABLE[187][278] = 1;
TABLE[187][295] = 1;
TABLE[187][294] = 1;
TABLE[187][33] = 1;
TABLE[187][126] = 1;
TABLE[187][45] = 1;
TABLE[187][43] = 1;
TABLE[187][42] = 1;
TABLE[187][38] = 1;
TABLE[187][40] = 1;
TABLE[187][299] = 1;
TABLE[187][289] = 1;
TABLE[187][303] = 1;
TABLE[187][302] = 1;
TABLE[187][304] = 1;
TABLE[246][59] = 1;
TABLE[71][123] = 1;
TABLE[188][262] = 1;
TABLE[188][258] = 1;
TABLE[188][59] = 1;
TABLE[188][123] = 1;
TABLE[188][281] = 1;
TABLE[188][271] = 1;
TABLE[188][269] = 1;
TABLE[188][263] = 1;
TABLE[188][287] = 1;
TABLE[188][275] = 1;
TABLE[188][257] = 1;
TABLE[188][261] = 1;
TABLE[188][270] = 1;
TABLE[188][305] = 1;
TABLE[188][306] = 1;
TABLE[188][299] = 1;
TABLE[188][278] = 1;
TABLE[188][38] = 1;
TABLE[188][42] = 1;
TABLE[188][43] = 1;
TABLE[188][45] = 1;
TABLE[188][126] = 1;
TABLE[188][33] = 1;
TABLE[188][294] = 1;
TABLE[188][295] = 1;
TABLE[188][40] = 1;
TABLE[188][304] = 1;
TABLE[188][302] = 1;
TABLE[188][303] = 1;
TABLE[188][289] = 1;
TABLE[188][125] = 1;
TABLE[188][285] = 1;
TABLE[188][259] = 1;
TABLE[188][276] = 1;
TABLE[188][272] = 1;
TABLE[188][273] = 1;
TABLE[188][268] = 1;
TABLE[188][264] = 1;
TABLE[188][277] = 1;
TABLE[188][284] = 1;
TABLE[188][256] = 1;
TABLE[188][274] = 1;
TABLE[188][279] = 1;
TABLE[188][267] = 1;
TABLE[188][282] = 1;
TABLE[188][286] = 1;
TABLE[188][260] = 1;
TABLE[188][266] = 1;
TABLE[188][283] = 1;
TABLE[188][280] = 1;
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
TABLE[247][305] = 1;
TABLE[247][306] = 1;
TABLE[247][299] = 1;
TABLE[247][278] = 1;
TABLE[247][38] = 1;
TABLE[247][42] = 1;
TABLE[247][43] = 1;
TABLE[247][45] = 1;
TABLE[247][126] = 1;
TABLE[247][33] = 1;
TABLE[247][294] = 1;
TABLE[247][295] = 1;
TABLE[247][40] = 1;
TABLE[247][304] = 1;
TABLE[247][302] = 1;
TABLE[247][303] = 1;
TABLE[247][289] = 1;
TABLE[247][125] = 1;
TABLE[189][125] = 1;
TABLE[189][306] = 1;
TABLE[189][305] = 1;
TABLE[189][270] = 1;
TABLE[189][261] = 1;
TABLE[189][257] = 1;
TABLE[189][275] = 1;
TABLE[189][287] = 1;
TABLE[189][263] = 1;
TABLE[189][269] = 1;
TABLE[189][271] = 1;
TABLE[189][281] = 1;
TABLE[189][123] = 1;
TABLE[189][59] = 1;
TABLE[189][258] = 1;
TABLE[189][262] = 1;
TABLE[189][299] = 1;
TABLE[189][278] = 1;
TABLE[189][295] = 1;
TABLE[189][294] = 1;
TABLE[189][33] = 1;
TABLE[189][126] = 1;
TABLE[189][45] = 1;
TABLE[189][43] = 1;
TABLE[189][42] = 1;
TABLE[189][38] = 1;
TABLE[189][40] = 1;
TABLE[189][289] = 1;
TABLE[189][303] = 1;
TABLE[189][302] = 1;
TABLE[189][304] = 1;
TABLE[248][125] = 1;
TABLE[72][125] = 1;
TABLE[72][306] = 1;
TABLE[72][305] = 1;
TABLE[72][270] = 1;
TABLE[72][261] = 1;
TABLE[72][257] = 1;
TABLE[72][275] = 1;
TABLE[72][287] = 1;
TABLE[72][263] = 1;
TABLE[72][269] = 1;
TABLE[72][271] = 1;
TABLE[72][281] = 1;
TABLE[72][123] = 1;
TABLE[72][59] = 1;
TABLE[72][258] = 1;
TABLE[72][262] = 1;
TABLE[72][299] = 1;
TABLE[72][278] = 1;
TABLE[72][295] = 1;
TABLE[72][294] = 1;
TABLE[72][33] = 1;
TABLE[72][126] = 1;
TABLE[72][45] = 1;
TABLE[72][43] = 1;
TABLE[72][42] = 1;
TABLE[72][38] = 1;
TABLE[72][40] = 1;
TABLE[72][289] = 1;
TABLE[72][303] = 1;
TABLE[72][302] = 1;
TABLE[72][304] = 1;
TABLE[190][125] = 1;
TABLE[190][262] = 1;
TABLE[190][258] = 1;
TABLE[190][59] = 1;
TABLE[190][123] = 1;
TABLE[190][281] = 1;
TABLE[190][271] = 1;
TABLE[190][269] = 1;
TABLE[190][263] = 1;
TABLE[190][287] = 1;
TABLE[190][275] = 1;
TABLE[190][257] = 1;
TABLE[190][261] = 1;
TABLE[190][270] = 1;
TABLE[190][305] = 1;
TABLE[190][306] = 1;
TABLE[190][299] = 1;
TABLE[190][278] = 1;
TABLE[190][38] = 1;
TABLE[190][42] = 1;
TABLE[190][43] = 1;
TABLE[190][45] = 1;
TABLE[190][126] = 1;
TABLE[190][33] = 1;
TABLE[190][294] = 1;
TABLE[190][295] = 1;
TABLE[190][40] = 1;
TABLE[190][304] = 1;
TABLE[190][302] = 1;
TABLE[190][303] = 1;
TABLE[190][289] = 1;
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
TABLE[249][305] = 1;
TABLE[249][306] = 1;
TABLE[249][299] = 1;
TABLE[249][278] = 1;
TABLE[249][38] = 1;
TABLE[249][42] = 1;
TABLE[249][43] = 1;
TABLE[249][45] = 1;
TABLE[249][126] = 1;
TABLE[249][33] = 1;
TABLE[249][294] = 1;
TABLE[249][295] = 1;
TABLE[249][40] = 1;
TABLE[249][304] = 1;
TABLE[249][302] = 1;
TABLE[249][303] = 1;
TABLE[249][289] = 1;
TABLE[249][125] = 1;
TABLE[73][271] = 1;
TABLE[74][281] = 1;
TABLE[191][265] = 1;
TABLE[250][125] = 1;
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
TABLE[250][305] = 1;
TABLE[250][306] = 1;
TABLE[250][299] = 1;
TABLE[250][278] = 1;
TABLE[250][38] = 1;
TABLE[250][42] = 1;
TABLE[250][43] = 1;
TABLE[250][45] = 1;
TABLE[250][126] = 1;
TABLE[250][33] = 1;
TABLE[250][294] = 1;
TABLE[250][295] = 1;
TABLE[250][40] = 1;
TABLE[250][304] = 1;
TABLE[250][302] = 1;
TABLE[250][303] = 1;
TABLE[250][289] = 1;
TABLE[250][265] = 1;
TABLE[75][287] = 1;
TABLE[76][263] = 1;
TABLE[77][269] = 1;
TABLE[192][278] = 1;
TABLE[192][295] = 1;
TABLE[192][294] = 1;
TABLE[192][33] = 1;
TABLE[192][126] = 1;
TABLE[192][45] = 1;
TABLE[192][43] = 1;
TABLE[192][42] = 1;
TABLE[192][38] = 1;
TABLE[192][40] = 1;
TABLE[192][299] = 1;
TABLE[192][289] = 1;
TABLE[192][303] = 1;
TABLE[192][302] = 1;
TABLE[192][304] = 1;
TABLE[251][59] = 1;
TABLE[193][278] = 1;
TABLE[193][295] = 1;
TABLE[193][294] = 1;
TABLE[193][33] = 1;
TABLE[193][126] = 1;
TABLE[193][45] = 1;
TABLE[193][43] = 1;
TABLE[193][42] = 1;
TABLE[193][38] = 1;
TABLE[193][40] = 1;
TABLE[193][299] = 1;
TABLE[193][289] = 1;
TABLE[193][303] = 1;
TABLE[193][302] = 1;
TABLE[193][304] = 1;
TABLE[252][59] = 1;
TABLE[194][278] = 1;
TABLE[194][295] = 1;
TABLE[194][294] = 1;
TABLE[194][33] = 1;
TABLE[194][126] = 1;
TABLE[194][45] = 1;
TABLE[194][43] = 1;
TABLE[194][42] = 1;
TABLE[194][38] = 1;
TABLE[194][40] = 1;
TABLE[194][299] = 1;
TABLE[194][289] = 1;
TABLE[194][303] = 1;
TABLE[194][302] = 1;
TABLE[194][304] = 1;
TABLE[253][41] = 1;
TABLE[78][270] = 1;
TABLE[79][261] = 1;
TABLE[80][257] = 1;
TABLE[81][275] = 1;
TABLE[195][278] = 1;
TABLE[195][295] = 1;
TABLE[195][294] = 1;
TABLE[195][33] = 1;
TABLE[195][126] = 1;
TABLE[195][45] = 1;
TABLE[195][43] = 1;
TABLE[195][42] = 1;
TABLE[195][38] = 1;
TABLE[195][40] = 1;
TABLE[195][299] = 1;
TABLE[195][289] = 1;
TABLE[195][303] = 1;
TABLE[195][302] = 1;
TABLE[195][304] = 1;
TABLE[254][59] = 1;
TABLE[82][305] = 1;
TABLE[83][306] = 1;
TABLE[196][299] = 1;
TABLE[255][299] = 1;
TABLE[84][278] = 1;
TABLE[84][38] = 1;
TABLE[84][42] = 1;
TABLE[84][43] = 1;
TABLE[84][45] = 1;
TABLE[84][126] = 1;
TABLE[84][33] = 1;
TABLE[84][294] = 1;
TABLE[84][295] = 1;
TABLE[84][40] = 1;
TABLE[84][304] = 1;
TABLE[84][302] = 1;
TABLE[84][303] = 1;
TABLE[84][289] = 1;
TABLE[84][299] = 1;
TABLE[85][278] = 1;
TABLE[85][295] = 1;
TABLE[85][294] = 1;
TABLE[85][33] = 1;
TABLE[85][126] = 1;
TABLE[85][45] = 1;
TABLE[85][43] = 1;
TABLE[85][42] = 1;
TABLE[85][38] = 1;
TABLE[85][40] = 1;
TABLE[85][299] = 1;
TABLE[85][289] = 1;
TABLE[85][303] = 1;
TABLE[85][302] = 1;
TABLE[85][304] = 1;
TABLE[86][40] = 1;
TABLE[86][278] = 1;
TABLE[86][38] = 1;
TABLE[86][42] = 1;
TABLE[86][43] = 1;
TABLE[86][45] = 1;
TABLE[86][126] = 1;
TABLE[86][33] = 1;
TABLE[86][294] = 1;
TABLE[86][295] = 1;
TABLE[86][304] = 1;
TABLE[86][302] = 1;
TABLE[86][303] = 1;
TABLE[86][289] = 1;
TABLE[86][299] = 1;
TABLE[87][278] = 1;
TABLE[87][295] = 1;
TABLE[87][294] = 1;
TABLE[87][33] = 1;
TABLE[87][126] = 1;
TABLE[87][45] = 1;
TABLE[87][43] = 1;
TABLE[87][42] = 1;
TABLE[87][38] = 1;
TABLE[87][40] = 1;
TABLE[87][299] = 1;
TABLE[87][289] = 1;
TABLE[87][303] = 1;
TABLE[87][302] = 1;
TABLE[87][304] = 1;
TABLE[88][291] = 1;
TABLE[89][61] = 1;
TABLE[90][40] = 1;
TABLE[90][278] = 1;
TABLE[90][295] = 1;
TABLE[90][294] = 1;
TABLE[90][33] = 1;
TABLE[90][126] = 1;
TABLE[90][45] = 1;
TABLE[90][43] = 1;
TABLE[90][42] = 1;
TABLE[90][38] = 1;
TABLE[90][299] = 1;
TABLE[90][289] = 1;
TABLE[90][303] = 1;
TABLE[90][302] = 1;
TABLE[90][304] = 1;
TABLE[91][40] = 1;
TABLE[91][278] = 1;
TABLE[91][295] = 1;
TABLE[91][294] = 1;
TABLE[91][33] = 1;
TABLE[91][126] = 1;
TABLE[91][45] = 1;
TABLE[91][43] = 1;
TABLE[91][42] = 1;
TABLE[91][38] = 1;
TABLE[91][299] = 1;
TABLE[91][289] = 1;
TABLE[91][303] = 1;
TABLE[91][302] = 1;
TABLE[91][304] = 1;
TABLE[92][40] = 1;
TABLE[92][278] = 1;
TABLE[92][38] = 1;
TABLE[92][42] = 1;
TABLE[92][43] = 1;
TABLE[92][45] = 1;
TABLE[92][126] = 1;
TABLE[92][33] = 1;
TABLE[92][294] = 1;
TABLE[92][295] = 1;
TABLE[92][304] = 1;
TABLE[92][302] = 1;
TABLE[92][303] = 1;
TABLE[92][289] = 1;
TABLE[92][299] = 1;
TABLE[93][40] = 1;
TABLE[93][278] = 1;
TABLE[93][38] = 1;
TABLE[93][42] = 1;
TABLE[93][43] = 1;
TABLE[93][45] = 1;
TABLE[93][126] = 1;
TABLE[93][33] = 1;
TABLE[93][294] = 1;
TABLE[93][295] = 1;
TABLE[93][304] = 1;
TABLE[93][302] = 1;
TABLE[93][303] = 1;
TABLE[93][289] = 1;
TABLE[93][299] = 1;
TABLE[94][40] = 1;
TABLE[94][278] = 1;
TABLE[94][295] = 1;
TABLE[94][294] = 1;
TABLE[94][33] = 1;
TABLE[94][126] = 1;
TABLE[94][45] = 1;
TABLE[94][43] = 1;
TABLE[94][42] = 1;
TABLE[94][38] = 1;
TABLE[94][299] = 1;
TABLE[94][289] = 1;
TABLE[94][303] = 1;
TABLE[94][302] = 1;
TABLE[94][304] = 1;
TABLE[95][40] = 1;
TABLE[95][278] = 1;
TABLE[95][295] = 1;
TABLE[95][294] = 1;
TABLE[95][33] = 1;
TABLE[95][126] = 1;
TABLE[95][45] = 1;
TABLE[95][43] = 1;
TABLE[95][42] = 1;
TABLE[95][38] = 1;
TABLE[95][299] = 1;
TABLE[95][289] = 1;
TABLE[95][303] = 1;
TABLE[95][302] = 1;
TABLE[95][304] = 1;
TABLE[96][40] = 1;
TABLE[96][278] = 1;
TABLE[96][38] = 1;
TABLE[96][42] = 1;
TABLE[96][43] = 1;
TABLE[96][45] = 1;
TABLE[96][126] = 1;
TABLE[96][33] = 1;
TABLE[96][294] = 1;
TABLE[96][295] = 1;
TABLE[96][304] = 1;
TABLE[96][302] = 1;
TABLE[96][303] = 1;
TABLE[96][289] = 1;
TABLE[96][299] = 1;
TABLE[97][40] = 1;
TABLE[97][278] = 1;
TABLE[97][38] = 1;
TABLE[97][42] = 1;
TABLE[97][43] = 1;
TABLE[97][45] = 1;
TABLE[97][126] = 1;
TABLE[97][33] = 1;
TABLE[97][294] = 1;
TABLE[97][295] = 1;
TABLE[97][304] = 1;
TABLE[97][302] = 1;
TABLE[97][303] = 1;
TABLE[97][289] = 1;
TABLE[97][299] = 1;
TABLE[98][40] = 1;
TABLE[98][278] = 1;
TABLE[98][295] = 1;
TABLE[98][294] = 1;
TABLE[98][33] = 1;
TABLE[98][126] = 1;
TABLE[98][45] = 1;
TABLE[98][43] = 1;
TABLE[98][42] = 1;
TABLE[98][38] = 1;
TABLE[98][299] = 1;
TABLE[98][289] = 1;
TABLE[98][303] = 1;
TABLE[98][302] = 1;
TABLE[98][304] = 1;
TABLE[99][40] = 1;
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
TABLE[99][303] = 1;
TABLE[99][302] = 1;
TABLE[99][304] = 1;
TABLE[100][40] = 1;
TABLE[100][278] = 1;
TABLE[100][38] = 1;
TABLE[100][42] = 1;
TABLE[100][43] = 1;
TABLE[100][45] = 1;
TABLE[100][126] = 1;
TABLE[100][33] = 1;
TABLE[100][294] = 1;
TABLE[100][295] = 1;
TABLE[100][304] = 1;
TABLE[100][302] = 1;
TABLE[100][303] = 1;
TABLE[100][289] = 1;
TABLE[100][299] = 1;
TABLE[101][40] = 1;
TABLE[101][278] = 1;
TABLE[101][38] = 1;
TABLE[101][42] = 1;
TABLE[101][43] = 1;
TABLE[101][45] = 1;
TABLE[101][126] = 1;
TABLE[101][33] = 1;
TABLE[101][294] = 1;
TABLE[101][295] = 1;
TABLE[101][304] = 1;
TABLE[101][302] = 1;
TABLE[101][303] = 1;
TABLE[101][289] = 1;
TABLE[101][299] = 1;
TABLE[102][40] = 1;
TABLE[102][278] = 1;
TABLE[102][295] = 1;
TABLE[102][294] = 1;
TABLE[102][33] = 1;
TABLE[102][126] = 1;
TABLE[102][45] = 1;
TABLE[102][43] = 1;
TABLE[102][42] = 1;
TABLE[102][38] = 1;
TABLE[102][299] = 1;
TABLE[102][289] = 1;
TABLE[102][303] = 1;
TABLE[102][302] = 1;
TABLE[102][304] = 1;
TABLE[103][40] = 1;
TABLE[103][278] = 1;
TABLE[103][295] = 1;
TABLE[103][294] = 1;
TABLE[103][33] = 1;
TABLE[103][126] = 1;
TABLE[103][45] = 1;
TABLE[103][43] = 1;
TABLE[103][42] = 1;
TABLE[103][38] = 1;
TABLE[103][299] = 1;
TABLE[103][289] = 1;
TABLE[103][303] = 1;
TABLE[103][302] = 1;
TABLE[103][304] = 1;
TABLE[104][40] = 1;
TABLE[104][278] = 1;
TABLE[104][38] = 1;
TABLE[104][42] = 1;
TABLE[104][43] = 1;
TABLE[104][45] = 1;
TABLE[104][126] = 1;
TABLE[104][33] = 1;
TABLE[104][294] = 1;
TABLE[104][295] = 1;
TABLE[104][304] = 1;
TABLE[104][302] = 1;
TABLE[104][303] = 1;
TABLE[104][289] = 1;
TABLE[104][299] = 1;
TABLE[105][40] = 1;
TABLE[105][278] = 1;
TABLE[105][38] = 1;
TABLE[105][42] = 1;
TABLE[105][43] = 1;
TABLE[105][45] = 1;
TABLE[105][126] = 1;
TABLE[105][33] = 1;
TABLE[105][294] = 1;
TABLE[105][295] = 1;
TABLE[105][304] = 1;
TABLE[105][302] = 1;
TABLE[105][303] = 1;
TABLE[105][289] = 1;
TABLE[105][299] = 1;
TABLE[106][40] = 1;
TABLE[106][278] = 1;
TABLE[106][295] = 1;
TABLE[106][294] = 1;
TABLE[106][33] = 1;
TABLE[106][126] = 1;
TABLE[106][45] = 1;
TABLE[106][43] = 1;
TABLE[106][42] = 1;
TABLE[106][38] = 1;
TABLE[106][299] = 1;
TABLE[106][289] = 1;
TABLE[106][303] = 1;
TABLE[106][302] = 1;
TABLE[106][304] = 1;
TABLE[107][40] = 1;
TABLE[107][278] = 1;
TABLE[107][295] = 1;
TABLE[107][294] = 1;
TABLE[107][33] = 1;
TABLE[107][126] = 1;
TABLE[107][45] = 1;
TABLE[107][43] = 1;
TABLE[107][42] = 1;
TABLE[107][38] = 1;
TABLE[107][299] = 1;
TABLE[107][289] = 1;
TABLE[107][303] = 1;
TABLE[107][302] = 1;
TABLE[107][304] = 1;
TABLE[108][40] = 1;
TABLE[108][278] = 1;
TABLE[108][38] = 1;
TABLE[108][42] = 1;
TABLE[108][43] = 1;
TABLE[108][45] = 1;
TABLE[108][126] = 1;
TABLE[108][33] = 1;
TABLE[108][294] = 1;
TABLE[108][295] = 1;
TABLE[108][304] = 1;
TABLE[108][302] = 1;
TABLE[108][303] = 1;
TABLE[108][289] = 1;
TABLE[108][299] = 1;
TABLE[197][43] = 1;
TABLE[198][45] = 1;
TABLE[109][40] = 1;
TABLE[109][278] = 1;
TABLE[109][38] = 1;
TABLE[109][42] = 1;
TABLE[109][43] = 1;
TABLE[109][45] = 1;
TABLE[109][126] = 1;
TABLE[109][33] = 1;
TABLE[109][294] = 1;
TABLE[109][295] = 1;
TABLE[109][304] = 1;
TABLE[109][302] = 1;
TABLE[109][303] = 1;
TABLE[109][289] = 1;
TABLE[109][299] = 1;
TABLE[110][40] = 1;
TABLE[110][278] = 1;
TABLE[110][295] = 1;
TABLE[110][294] = 1;
TABLE[110][33] = 1;
TABLE[110][126] = 1;
TABLE[110][45] = 1;
TABLE[110][43] = 1;
TABLE[110][42] = 1;
TABLE[110][38] = 1;
TABLE[110][299] = 1;
TABLE[110][289] = 1;
TABLE[110][303] = 1;
TABLE[110][302] = 1;
TABLE[110][304] = 1;
TABLE[199][42] = 1;
TABLE[200][47] = 1;
TABLE[201][37] = 1;
TABLE[111][278] = 1;
TABLE[111][295] = 1;
TABLE[111][294] = 1;
TABLE[111][33] = 1;
TABLE[111][126] = 1;
TABLE[111][45] = 1;
TABLE[111][43] = 1;
TABLE[111][42] = 1;
TABLE[111][38] = 1;
TABLE[111][40] = 1;
TABLE[111][299] = 1;
TABLE[111][289] = 1;
TABLE[111][303] = 1;
TABLE[111][302] = 1;
TABLE[111][304] = 1;
TABLE[112][40] = 1;
TABLE[113][40] = 1;
TABLE[113][304] = 1;
TABLE[113][302] = 1;
TABLE[113][303] = 1;
TABLE[113][289] = 1;
TABLE[113][299] = 1;
TABLE[114][294] = 1;
TABLE[114][295] = 1;
TABLE[115][38] = 1;
TABLE[115][42] = 1;
TABLE[115][43] = 1;
TABLE[115][45] = 1;
TABLE[115][126] = 1;
TABLE[115][33] = 1;
TABLE[116][278] = 1;
TABLE[117][278] = 1;
TABLE[202][294] = 1;
TABLE[203][295] = 1;
TABLE[118][38] = 1;
TABLE[119][42] = 1;
TABLE[120][43] = 1;
TABLE[121][45] = 1;
TABLE[122][126] = 1;
TABLE[123][33] = 1;
TABLE[124][40] = 1;
TABLE[124][299] = 1;
TABLE[124][289] = 1;
TABLE[124][303] = 1;
TABLE[124][302] = 1;
TABLE[124][304] = 1;
TABLE[125][40] = 1;
TABLE[125][304] = 1;
TABLE[125][302] = 1;
TABLE[125][303] = 1;
TABLE[125][289] = 1;
TABLE[125][299] = 1;
TABLE[205][91] = 1;
TABLE[207][40] = 1;
TABLE[208][46] = 1;
TABLE[209][296] = 1;
TABLE[210][294] = 1;
TABLE[211][295] = 1;
TABLE[204][58] = 1;
TABLE[256][93] = 1;
TABLE[206][41] = 1;
TABLE[206][278] = 1;
TABLE[206][295] = 1;
TABLE[206][294] = 1;
TABLE[206][33] = 1;
TABLE[206][126] = 1;
TABLE[206][45] = 1;
TABLE[206][43] = 1;
TABLE[206][42] = 1;
TABLE[206][38] = 1;
TABLE[206][40] = 1;
TABLE[206][299] = 1;
TABLE[206][289] = 1;
TABLE[206][303] = 1;
TABLE[206][302] = 1;
TABLE[206][304] = 1;
TABLE[257][41] = 1;
TABLE[126][299] = 1;
TABLE[127][304] = 1;
TABLE[127][302] = 1;
TABLE[127][303] = 1;
TABLE[127][289] = 1;
TABLE[128][40] = 1;
TABLE[129][278] = 1;
TABLE[129][295] = 1;
TABLE[129][294] = 1;
TABLE[129][33] = 1;
TABLE[129][126] = 1;
TABLE[129][45] = 1;
TABLE[129][43] = 1;
TABLE[129][42] = 1;
TABLE[129][38] = 1;
TABLE[129][40] = 1;
TABLE[129][299] = 1;
TABLE[129][289] = 1;
TABLE[129][303] = 1;
TABLE[129][302] = 1;
TABLE[129][304] = 1;
TABLE[212][278] = 1;
TABLE[212][38] = 1;
TABLE[212][42] = 1;
TABLE[212][43] = 1;
TABLE[212][45] = 1;
TABLE[212][126] = 1;
TABLE[212][33] = 1;
TABLE[212][294] = 1;
TABLE[212][295] = 1;
TABLE[212][40] = 1;
TABLE[212][304] = 1;
TABLE[212][302] = 1;
TABLE[212][303] = 1;
TABLE[212][289] = 1;
TABLE[212][299] = 1;
TABLE[258][278] = 1;
TABLE[258][38] = 1;
TABLE[258][42] = 1;
TABLE[258][43] = 1;
TABLE[258][45] = 1;
TABLE[258][126] = 1;
TABLE[258][33] = 1;
TABLE[258][294] = 1;
TABLE[258][295] = 1;
TABLE[258][40] = 1;
TABLE[258][304] = 1;
TABLE[258][302] = 1;
TABLE[258][303] = 1;
TABLE[258][289] = 1;
TABLE[258][299] = 1;
TABLE[130][304] = 1;
TABLE[131][302] = 1;
TABLE[132][303] = 1;
TABLE[133][289] = 1;
TABLE[134][299] = 1;
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
      case 55: return 0; break;
      case 61: return 1; break;
      case 68: return 1; break;
      case 73: return 1; break;
      case 81: return 0; break;
      case 86: return 0; break;
      case 98: return 1; break;
      case 105: return 0; break;
      case 125: return 0; break;
      case 169: return 0; break;
      case 173: return 0; break;
      case 181: return 0; break;
      case 194: return 1; break;
      case 201: return 0; break;
      case 205: return 0; break;
      case 213: return 1; break;
      case 218: return 1; break;
      case 225: return 1; break;
      case 230: return 1; break;
      case 238: return 1; break;
      case 243: return 1; break;
      case 251: return 0; break;
      case 257: return 0; break;
      case 262: return 0; break;
      case 270: return 1; break;
      case 277: return 1; break;
      case 282: return 1; break;
      case 290: return 1; break;
      case 300: return 1; break;
      case 307: return 0; break;
      case 320: return 1; break;
      case 327: return 1; break;
      case 332: return 1; break;
      case 340: return 0; break;
      case 345: return 1; break;
      case 353: return 1; break;
      case 358: return 1; break;
      case 365: return 0; break;
      case 380: return 0; break;
      case 398: return 1; break;
      case 405: return 1; break;
      case 412: return 0; break;
      case 418: return 1; break;
      case 425: return 1; break;
      case 432: return 1; break;
      case 437: return 1; break;
      case 444: return 1; break;
      case 449: return 1; break;
      case 457: return 1; break;
      case 462: return 1; break;
      case 470: return 0; break;
      case 475: return 1; break;
      case 483: return 1; break;
      case 490: return 1; break;
      case 495: return 1; break;
      case 503: return 0; break;
      case 514: return 1; break;
      case 521: return 1; break;
      case 526: return 1; break;
      case 534: return 0; break;
      case 539: return 1; break;
      case 546: return 1; break;
      case 555: return 1; break;
      case 562: return 1; break;
      case 573: return 1; break;
      case 580: return 0; break;
      case 592: return 1; break;
      case 599: return 1; break;
      case 606: return 0; break;
      case 610: return 1; break;
      case 642: return 0; break;
      case 661: return 1; break;
      case 666: return 1; break;
      case 673: return 0; break;
      case 680: return 1; break;
      case 687: return 1; break;
      case 694: return 1; break;
      case 699: return 1; break;
      case 707: return 0; break;
      case 724: return 1; break;
      case 732: return 0; break;
      case 762: return 1; break;
      case 769: return 1; break;
      case 776: return 1; break;
      case 783: return 0; break;
      case 805: return 1; break;
      case 812: return 0; break;
      case 818: return 0; break;
      case 825: return 1; break;
      case 834: return 0; break;
      case 844: return 0; break;
      case 854: return 0; break;
      case 862: return 0; break;
      case 874: return 0; break;
      case 878: return 0; break;
      case 888: return 0; break;
      case 898: return 0; break;
      case 908: return 0; break;
      case 918: return 0; break;
      case 928: return 0; break;
      case 938: return 0; break;
      case 948: return 0; break;
      case 958: return 0; break;
      case 966: return 0; break;
      case 976: return 0; break;
      case 988: return 0; break;
      case 999: return 0; break;
      case 1025: return 0; break;
      case 1033: return 0; break;
      case 1057: return 0; break;
      case 1066: return 0; break;
      case 1097: return 1; break;
      case 1105: return 1; break;
      case 1112: return 0; break;
      case 1126: return 1; break;
      case 1131: return 1; break;
      case 1140: return 0; break;
      case 1156: return 0; break;
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
         case 86: return "Subphrase"; break;
         case 98: return "Subphrase"; break;
         case 105: return "storage_class_specifier"; break;
         case 125: return "type_specifier"; break;
         case 169: return "type_qualifier"; break;
         case 173: return "Subphrase"; break;
         case 181: return "struct_or_union_specifier"; break;
         case 194: return "Subphrase"; break;
         case 201: return "struct_or_union"; break;
         case 205: return "Subphrase"; break;
         case 213: return "struct_declaration_list"; break;
         case 218: return "Subphrase"; break;
         case 225: return "init_declarator_list"; break;
         case 230: return "Subphrase"; break;
         case 238: return "init_declarator"; break;
         case 243: return "Subphrase"; break;
         case 251: return "struct_declaration"; break;
         case 257: return "specifier_qualifier_list"; break;
         case 262: return "Subphrase"; break;
         case 270: return "Subphrase"; break;
         case 277: return "struct_declarator_list"; break;
         case 282: return "Subphrase"; break;
         case 290: return "struct_declarator"; break;
         case 300: return "Subphrase"; break;
         case 307: return "enum_specifier"; break;
         case 320: return "Subphrase"; break;
         case 327: return "enumerator_list"; break;
         case 332: return "Subphrase"; break;
         case 340: return "enumerator"; break;
         case 345: return "Subphrase"; break;
         case 353: return "declarator"; break;
         case 358: return "Subphrase"; break;
         case 365: return "direct_declarator"; break;
         case 380: return "Subphrase"; break;
         case 398: return "Subphrase"; break;
         case 405: return "Subphrase"; break;
         case 412: return "pointer"; break;
         case 418: return "Subphrase"; break;
         case 425: return "Subphrase"; break;
         case 432: return "type_qualifier_list"; break;
         case 437: return "Subphrase"; break;
         case 444: return "parameter_type_list"; break;
         case 449: return "Subphrase"; break;
         case 457: return "parameter_list"; break;
         case 462: return "Subphrase"; break;
         case 470: return "parameter_declaration"; break;
         case 475: return "Subphrase"; break;
         case 483: return "Subphrase"; break;
         case 490: return "identifier_list"; break;
         case 495: return "Subphrase"; break;
         case 503: return "initializer"; break;
         case 514: return "Subphrase"; break;
         case 521: return "initializer_list"; break;
         case 526: return "Subphrase"; break;
         case 534: return "type_name"; break;
         case 539: return "Subphrase"; break;
         case 546: return "abstract_declarator"; break;
         case 555: return "Subphrase"; break;
         case 562: return "direct_abstract_declarator"; break;
         case 573: return "Subphrase"; break;
         case 580: return "Subphrase"; break;
         case 592: return "Subphrase"; break;
         case 599: return "Subphrase"; break;
         case 606: return "typedef_name"; break;
         case 610: return "statement"; break;
         case 642: return "labeled_statement"; break;
         case 661: return "expression_statement"; break;
         case 666: return "Subphrase"; break;
         case 673: return "compound_statement"; break;
         case 680: return "Subphrase"; break;
         case 687: return "Subphrase"; break;
         case 694: return "statement_list"; break;
         case 699: return "Subphrase"; break;
         case 707: return "selection_statement"; break;
         case 724: return "Subphrase"; break;
         case 732: return "iteration_statement"; break;
         case 762: return "Subphrase"; break;
         case 769: return "Subphrase"; break;
         case 776: return "Subphrase"; break;
         case 783: return "jump_statement"; break;
         case 805: return "Subphrase"; break;
         case 812: return "print_statement"; break;
         case 818: return "input_statement"; break;
         case 825: return "Subphrase"; break;
         case 834: return "expression"; break;
         case 844: return "assignment_expression"; break;
         case 854: return "assignment_operator"; break;
         case 862: return "conditional_expression"; break;
         case 874: return "constant_expression"; break;
         case 878: return "logical_OR_expression"; break;
         case 888: return "logical_AND_expression"; break;
         case 898: return "inclusive_OR_expression"; break;
         case 908: return "exclusive_OR_expression"; break;
         case 918: return "AND_expression"; break;
         case 928: return "equality_expression"; break;
         case 938: return "shift_expression"; break;
         case 948: return "additive_expression"; break;
         case 958: return "Subphrase"; break;
         case 966: return "multiplicative_expression"; break;
         case 976: return "Subphrase"; break;
         case 988: return "cast_expression"; break;
         case 999: return "unary_expression"; break;
         case 1025: return "Subphrase"; break;
         case 1033: return "unary_operator"; break;
         case 1057: return "postfix_expression"; break;
         case 1066: return "Subphrase"; break;
         case 1097: return "Subphrase"; break;
         case 1105: return "Subphrase"; break;
         case 1112: return "primary_expression"; break;
         case 1126: return "argument_expression_list"; break;
         case 1131: return "Subphrase"; break;
         case 1140: return "constant"; break;
         case 1156: return "id"; break;
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
