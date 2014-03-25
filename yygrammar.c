#line 6 "ass3.acc"

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
      while (1) {
         switch (yyselect()) {
         case 125: {
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
      switch (yyselect()) {
      case 128: {
         get_lexval();
         } break;
      case 129: {
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
      case 130: {
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
         case 131: {
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
         case 132: {
            storage_class_specifier();
            } break;
         case 133: {
            type_specifier();
            } break;
         case 134: {
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
      case 135: {
         get_lexval();
         } break;
      case 136: {
         get_lexval();
         } break;
      case 137: {
         get_lexval();
         } break;
      case 138: {
         get_lexval();
         } break;
      case 139: {
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
      case 140: {
         get_lexval();
         } break;
      case 141: {
         get_lexval();
         } break;
      case 142: {
         get_lexval();
         } break;
      case 143: {
         get_lexval();
         } break;
      case 144: {
         get_lexval();
         } break;
      case 145: {
         get_lexval();
         } break;
      case 146: {
         get_lexval();
         } break;
      case 147: {
         get_lexval();
         } break;
      case 148: {
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
#line 65 "ass3.acc"

# line 210 "yygrammar.c"
      } break;
   }
}

type_qualifier ()
{
   switch(yyselect()) {
   case 13: {
      switch (yyselect()) {
      case 149: {
         get_lexval();
         } break;
      case 150: {
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
      case 151: {
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
#line 75 "ass3.acc"

# line 253 "yygrammar.c"
      } break;
   }
}

struct_or_union ()
{
   switch(yyselect()) {
   case 16: {
      switch (yyselect()) {
      case 152: {
         get_lexval();
         } break;
      case 153: {
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
      case 154: {
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
      case 155: {
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
      case 156: {
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
      case 157: {
         type_specifier();
         } break;
      case 158: {
         type_qualifier();
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 159: {
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
      case 160: {
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
      case 161: {
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
      case 162: {
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
      case 163: {
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
      case 164: {
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
      case 165: {
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
      case 167: {
         get_lexval();
         switch (yyselect()) {
         case 166: {
            expression(&e);
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 168: {
         get_lexval();
         parameter_type_list();
         get_lexval();
         } break;
      case 170: {
         get_lexval();
         switch (yyselect()) {
         case 169: {
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
      case 171: {
         type_qualifier_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 172: {
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
      case 173: {
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
      case 174: {
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
      case 175: {
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
      case 176: {
         declarator();
         } break;
      case 178: {
         switch (yyselect()) {
         case 177: {
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
      case 179: {
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
      case 180: {
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
      case 181: {
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
      case 182: {
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
      case 183: {
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
      case 184: {
         direct_abstract_declarator();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 186: {
         get_lexval();
         switch (yyselect()) {
         case 185: {
            expression(&e);
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 188: {
         get_lexval();
         switch (yyselect()) {
         case 187: {
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
      case 189: {
         expression(&e);
#line 206 "ass3.acc"
 printExpression(e, 0); 
# line 806 "yygrammar.c"
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
      case 190: {
         declaration_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 191: {
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
         case 192: {
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
      case 193: {
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
      expression(&e);
      get_lexval();
      statement();
      } break;
   case 65: {
      get_lexval();
      statement();
      get_lexval();
      get_lexval();
      expression(&e);
      get_lexval();
      get_lexval();
      } break;
   case 66: {
      get_lexval();
      get_lexval();
      switch (yyselect()) {
      case 194: {
         expression(&e);
         } break;
      default: ;
      }
      get_lexval();
      switch (yyselect()) {
      case 195: {
         expression(&e);
         } break;
      default: ;
      }
      get_lexval();
      switch (yyselect()) {
      case 196: {
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
   case 67: {
      get_lexval();
      id(&i);
      get_lexval();
      } break;
   case 68: {
      get_lexval();
      get_lexval();
      } break;
   case 69: {
      get_lexval();
      get_lexval();
      } break;
   case 70: {
      get_lexval();
      switch (yyselect()) {
      case 197: {
         expression(&e);
#line 237 "ass3.acc"
 printExpression(e, 0); 
# line 957 "yygrammar.c"
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
      while (1) {
         switch (yyselect()) {
         case 198: {
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
   expression_pt ae;
   expression_pt e;
   switch(yyselect()) {
   case 73: {
      assignment_expression(&ae);
#line 249 "ass3.acc"
 *ret = ae; 
# line 1010 "yygrammar.c"
      } break;
   case 74: {
      expression(&e);
      get_lexval();
      assignment_expression(&ae);
#line 250 "ass3.acc"
 *ret = makeExpression(1, 2, ',', e, ae); 
# line 1018 "yygrammar.c"
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
   case 75: {
      conditional_expression(&ce);
#line 254 "ass3.acc"
 *ret = ce; 
# line 1035 "yygrammar.c"
      } break;
   case 76: {
      unary_expression(&ue);
      assignment_operator(&ao);
      assignment_expression(&ae);
#line 255 "ass3.acc"
 *ret = makeExpression(1, 2, ao, ue, ae); 
# line 1043 "yygrammar.c"
      } break;
   }
}

assignment_operator (ret)
   int *ret;
{
   switch(yyselect()) {
   case 77: {
      get_lexval();
#line 259 "ass3.acc"
 *ret = yylval.subtype; 
# line 1056 "yygrammar.c"
      } break;
   case 78: {
      get_lexval();
#line 260 "ass3.acc"
 *ret = '='; 
# line 1062 "yygrammar.c"
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
   case 79: {
      logical_OR_expression(&loe);
#line 264 "ass3.acc"
 *ret = loe; 
# line 1078 "yygrammar.c"
      } break;
   case 80: {
      logical_OR_expression(&loe);
      get_lexval();
      expression(&e);
      get_lexval();
      conditional_expression(&ce);
#line 265 "ass3.acc"
 *ret = makeExpression(1, 3, '?', loe, e, ce); 
# line 1088 "yygrammar.c"
      } break;
   }
}

constant_expression (ret)
   expression_pt *ret;
{
   expression_pt ce;
   switch(yyselect()) {
   case 81: {
      conditional_expression(&ce);
#line 269 "ass3.acc"
 *ret = ce; 
# line 1102 "yygrammar.c"
      } break;
   }
}

logical_OR_expression (ret)
   expression_pt *ret;
{
   expression_pt lae;
   expression_pt loe;
   switch(yyselect()) {
   case 82: {
      logical_AND_expression(&lae);
#line 273 "ass3.acc"
 *ret = lae; 
# line 1117 "yygrammar.c"
      } break;
   case 83: {
      logical_OR_expression(&loe);
      get_lexval();
      logical_AND_expression(&lae);
#line 274 "ass3.acc"
 *ret = makeExpression(1, 2, '||', loe, lae); 
# line 1125 "yygrammar.c"
      } break;
   }
}

logical_AND_expression (ret)
   expression_pt *ret;
{
   expression_pt ioe;
   expression_pt lae;
   switch(yyselect()) {
   case 84: {
      inclusive_OR_expression(&ioe);
#line 278 "ass3.acc"
 *ret = ioe; 
# line 1140 "yygrammar.c"
      } break;
   case 85: {
      logical_AND_expression(&lae);
      get_lexval();
      inclusive_OR_expression(&ioe);
#line 279 "ass3.acc"
 *ret = makeExpression(1, 2, '&&', lae, ioe); 
# line 1148 "yygrammar.c"
      } break;
   }
}

inclusive_OR_expression (ret)
   expression_pt *ret;
{
   expression_pt eoe;
   expression_pt ioe;
   switch(yyselect()) {
   case 86: {
      exclusive_OR_expression(&eoe);
#line 283 "ass3.acc"
 *ret = eoe; 
# line 1163 "yygrammar.c"
      } break;
   case 87: {
      inclusive_OR_expression(&ioe);
      get_lexval();
      exclusive_OR_expression(&eoe);
#line 284 "ass3.acc"
 *ret = makeExpression(1, 2, '|', ioe, eoe); 
# line 1171 "yygrammar.c"
      } break;
   }
}

exclusive_OR_expression (ret)
   expression_pt *ret;
{
   expression_pt ae;
   expression_pt eoe;
   switch(yyselect()) {
   case 88: {
      AND_expression(&ae);
#line 288 "ass3.acc"
 *ret = ae; 
# line 1186 "yygrammar.c"
      } break;
   case 89: {
      exclusive_OR_expression(&eoe);
      get_lexval();
      AND_expression(&ae);
#line 289 "ass3.acc"
 *ret = makeExpression(1, 2, '^', eoe, ae); 
# line 1194 "yygrammar.c"
      } break;
   }
}

AND_expression (ret)
   expression_pt *ret;
{
   expression_pt ee;
   expression_pt ae;
   switch(yyselect()) {
   case 90: {
      equality_expression(&ee);
#line 293 "ass3.acc"
 *ret = ee; 
# line 1209 "yygrammar.c"
      } break;
   case 91: {
      AND_expression(&ae);
      get_lexval();
      equality_expression(&ee);
#line 294 "ass3.acc"
 *ret = makeExpression(1, 2, '&', ae, ee); 
# line 1217 "yygrammar.c"
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
   case 92: {
      shift_expression(&se);
#line 298 "ass3.acc"
 *ret = se; 
# line 1233 "yygrammar.c"
      } break;
   case 93: {
      equality_expression(&ee);
      get_lexval();
      c = yylval;
      shift_expression(&se);
#line 299 "ass3.acc"
 *ret = makeExpression(1, 2, c.subtype, ee, se); 
# line 1242 "yygrammar.c"
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
   case 94: {
      additive_expression(&ae);
#line 303 "ass3.acc"
 *ret = ae; 
# line 1258 "yygrammar.c"
      } break;
   case 95: {
      shift_expression(&se);
      get_lexval();
      s = yylval;
      additive_expression(&ae);
#line 304 "ass3.acc"
 *ret = makeExpression(1, 2, s.subtype, se, ae); 
# line 1267 "yygrammar.c"
      } break;
   }
}

additive_expression (ret)
   expression_pt *ret;
{
   expression_pt me;
   expression_pt ae;
   switch(yyselect()) {
   case 96: {
      multiplicative_expression(&me);
#line 308 "ass3.acc"
 *ret = me; 
# line 1282 "yygrammar.c"
      } break;
   case 97: {
#line 309 "ass3.acc"
 int op = '+'; 
# line 1287 "yygrammar.c"
      additive_expression(&ae);
      switch (yyselect()) {
      case 199: {
         get_lexval();
         } break;
      case 200: {
         get_lexval();
#line 309 "ass3.acc"
 op = '-'; 
# line 1297 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      multiplicative_expression(&me);
#line 309 "ass3.acc"
 *ret = makeExpression(1, 2, op, ae, me); 
# line 1304 "yygrammar.c"
      } break;
   }
}

multiplicative_expression (ret)
   expression_pt *ret;
{
   expression_pt ce;
   expression_pt me;
   switch(yyselect()) {
   case 98: {
      cast_expression(&ce);
#line 313 "ass3.acc"
 *ret = ce; 
# line 1319 "yygrammar.c"
      } break;
   case 99: {
#line 314 "ass3.acc"
 int op = '*'; 
# line 1324 "yygrammar.c"
      multiplicative_expression(&me);
      switch (yyselect()) {
      case 201: {
         get_lexval();
         } break;
      case 202: {
         get_lexval();
#line 314 "ass3.acc"
 op = '/'; 
# line 1334 "yygrammar.c"
         } break;
      case 203: {
         get_lexval();
#line 314 "ass3.acc"
 op = '%'; 
# line 1340 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      cast_expression(&ce);
#line 314 "ass3.acc"
 *ret = makeExpression(1, 2, op, me, ce); 
# line 1347 "yygrammar.c"
      } break;
   }
}

cast_expression (ret)
   expression_pt *ret;
{
   expression_pt ue;
   expression_pt ce;
   switch(yyselect()) {
   case 100: {
      unary_expression(&ue);
#line 318 "ass3.acc"
 *ret =  ue; 
# line 1362 "yygrammar.c"
      } break;
   case 101: {
      get_lexval();
      type_name();
      get_lexval();
      cast_expression(&ce);
#line 319 "ass3.acc"
 *ret = ce; 
# line 1371 "yygrammar.c"
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
   case 102: {
      postfix_expression(&pe);
#line 323 "ass3.acc"
 *ret = pe; 
# line 1388 "yygrammar.c"
      } break;
   case 103: {
#line 324 "ass3.acc"
 int t; 
# line 1393 "yygrammar.c"
      switch (yyselect()) {
      case 204: {
         get_lexval();
#line 324 "ass3.acc"
t = '++x';
# line 1399 "yygrammar.c"
         } break;
      case 205: {
         get_lexval();
#line 324 "ass3.acc"
t = '--x'; 
# line 1405 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      unary_expression(&ue);
#line 324 "ass3.acc"
 *ret = makeExpression(1, 1, t, ue); 
# line 1412 "yygrammar.c"
      } break;
   case 104: {
      unary_operator(&op);
      cast_expression(&ce);
#line 325 "ass3.acc"
 *ret = makeExpression(1, 1, op, ce); 
# line 1419 "yygrammar.c"
      } break;
   case 105: {
      get_lexval();
      unary_expression(&ue);
#line 326 "ass3.acc"
 *ret = ue; 
# line 1426 "yygrammar.c"
      } break;
   case 106: {
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
   case 107: {
      get_lexval();
#line 331 "ass3.acc"
 *op = '&'; 
# line 1445 "yygrammar.c"
      } break;
   case 108: {
      get_lexval();
#line 332 "ass3.acc"
 *op = '*'; 
# line 1451 "yygrammar.c"
      } break;
   case 109: {
      get_lexval();
#line 333 "ass3.acc"
 *op = '+'; 
# line 1457 "yygrammar.c"
      } break;
   case 110: {
      get_lexval();
#line 334 "ass3.acc"
 *op = '-'; 
# line 1463 "yygrammar.c"
      } break;
   case 111: {
      get_lexval();
#line 335 "ass3.acc"
 *op = '~'; 
# line 1469 "yygrammar.c"
      } break;
   case 112: {
      get_lexval();
#line 336 "ass3.acc"
 *op = '!'; 
# line 1475 "yygrammar.c"
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
   case 113: {
      primary_expression(&pe);
#line 340 "ass3.acc"
 *ret = pe; 
# line 1492 "yygrammar.c"
      } break;
   case 114: {
      postfix_expression(&pe);
#line 341 "ass3.acc"
 *ret = makeExpression(1, 1, 0, pe); fprintf(stderr, "@ PE: "); printExpression(*ret, 0); 
# line 1498 "yygrammar.c"
      switch (yyselect()) {
      case 207: {
         get_lexval();
         expression(&e);
#line 342 "ass3.acc"
 appendExpression(*ret, e); 
# line 1505 "yygrammar.c"
         switch (yyselect()) {
         case 206: {
            get_lexval();
            expression(&e);
#line 342 "ass3.acc"
 appendExpression(*ret, e); 
# line 1512 "yygrammar.c"
            } break;
         default: ;
         }
         get_lexval();
#line 342 "ass3.acc"
 (*ret)->operator = '[]'; 
# line 1519 "yygrammar.c"
         } break;
      case 209: {
         get_lexval();
         switch (yyselect()) {
         case 208: {
            argument_expression_list(&ae);
#line 343 "ass3.acc"
 appendExpression(*ret, ae); 
# line 1528 "yygrammar.c"
            } break;
         default: ;
         }
         get_lexval();
#line 343 "ass3.acc"
 (*ret)->operator = '()'; 
# line 1535 "yygrammar.c"
         } break;
      case 210: {
         get_lexval();
         id(&i);
#line 344 "ass3.acc"
 appendExpression(*ret, makeExpression(0, 1, 0, i)); (*ret)->operator = '.'; 
# line 1542 "yygrammar.c"
         } break;
      case 211: {
         get_lexval();
         id(&i);
#line 345 "ass3.acc"
 appendExpression(*ret, makeExpression(0, 1, 0, i)); (*ret)->operator = '->'; 
# line 1549 "yygrammar.c"
         } break;
      case 212: {
         get_lexval();
#line 346 "ass3.acc"
 (*ret)->operator = 'x++'; 
# line 1555 "yygrammar.c"
         } break;
      case 213: {
         get_lexval();
#line 347 "ass3.acc"
 (*ret)->operator = 'x--'; 
# line 1561 "yygrammar.c"
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
   case 115: {
      id(&i);
#line 352 "ass3.acc"
 *ret = makeExpression(0, 1, 0, i); 
# line 1580 "yygrammar.c"
      } break;
   case 116: {
      constant(&c);
#line 353 "ass3.acc"
 *ret = makeExpression(0, 1, 0, c); 
# line 1586 "yygrammar.c"
      } break;
   case 117: {
      get_lexval();
      expression(&e);
#line 354 "ass3.acc"
 *ret = e; 
# line 1593 "yygrammar.c"
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
   case 118: {
#line 358 "ass3.acc"
 *ret = makeExpression(1, 0, '(,)'); 
# line 1608 "yygrammar.c"
      while (1) {
         switch (yyselect()) {
         case 214: {
            assignment_expression(&ae);
#line 358 "ass3.acc"
 appendExpression(*ret, ae); 
# line 1615 "yygrammar.c"
            get_lexval();
            } break;
         default: goto yy6;
         }
      }
      yy6: ;
      assignment_expression(&ae2);
#line 358 "ass3.acc"
 appendExpression(*ret, ae2); 
# line 1625 "yygrammar.c"
      } break;
   }
}

constant (ret)
   constant_pt *ret;
{
   switch(yyselect()) {
   case 119: {
      get_lexval();
#line 362 "ass3.acc"
 *ret = makeIntConst(yylval.i); 
# line 1638 "yygrammar.c"
      } break;
   case 120: {
      get_lexval();
#line 363 "ass3.acc"
 *ret = makeIntConst(yylval.i); 
# line 1644 "yygrammar.c"
      } break;
   case 121: {
      get_lexval();
#line 364 "ass3.acc"
 *ret = makeFloatConst(yylval.d); 
# line 1650 "yygrammar.c"
      } break;
   case 122: {
      get_lexval();
#line 365 "ass3.acc"
 *ret = makeStringConst(yylval.s); 
# line 1656 "yygrammar.c"
      } break;
   }
}

id (ret)
   constant_pt *ret;
{
   switch(yyselect()) {
   case 123: {
      get_lexval();
#line 370 "ass3.acc"
 *ret = makeStringConst(yylval.s); (*ret)->type = IDCONST; 
# line 1669 "yygrammar.c"
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
int c_length = 1169;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 124,
/* 6 */ 0,
/* 7 */ 10,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 15,
/* 11 */ 18,
/* 12 */ 10,
/* 13 */ -10,
/* 14 */ 125,
/* 15 */ 0,
/* 16 */ -10,
/* 17 */ 215,
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
/* 36 */ 126,
/* 37 */ 0,
/* 38 */ -33,
/* 39 */ 216,
/* 40 */ 44,
/* 41 */ 68,
/* 42 */ -40,
/* 43 */ 127,
/* 44 */ 0,
/* 45 */ -40,
/* 46 */ 217,
/* 47 */ 51,
/* 48 */ 50059,
/* 49 */ -47,
/* 50 */ 128,
/* 51 */ 0,
/* 52 */ 683,
/* 53 */ -47,
/* 54 */ 129,
/* 55 */ 0,
/* 56 */ 81,
/* 57 */ 61,
/* 58 */ 50059,
/* 59 */ -55,
/* 60 */ 5,
/* 61 */ 65,
/* 62 */ 235,
/* 63 */ -61,
/* 64 */ 130,
/* 65 */ 0,
/* 66 */ -61,
/* 67 */ 218,
/* 68 */ 0,
/* 69 */ 55,
/* 70 */ 73,
/* 71 */ -68,
/* 72 */ 6,
/* 73 */ 78,
/* 74 */ 55,
/* 75 */ 73,
/* 76 */ -73,
/* 77 */ 131,
/* 78 */ 0,
/* 79 */ -73,
/* 80 */ 219,
/* 81 */ 0,
/* 82 */ 85,
/* 83 */ -81,
/* 84 */ 7,
/* 85 */ 90,
/* 86 */ 103,
/* 87 */ 85,
/* 88 */ -85,
/* 89 */ 132,
/* 90 */ 95,
/* 91 */ 127,
/* 92 */ 85,
/* 93 */ -85,
/* 94 */ 133,
/* 95 */ 100,
/* 96 */ 179,
/* 97 */ 85,
/* 98 */ -85,
/* 99 */ 134,
/* 100 */ 0,
/* 101 */ -85,
/* 102 */ 220,
/* 103 */ 0,
/* 104 */ 107,
/* 105 */ -103,
/* 106 */ 8,
/* 107 */ 111,
/* 108 */ 50256,
/* 109 */ -107,
/* 110 */ 135,
/* 111 */ 115,
/* 112 */ 50274,
/* 113 */ -107,
/* 114 */ 136,
/* 115 */ 119,
/* 116 */ 50279,
/* 117 */ -107,
/* 118 */ 137,
/* 119 */ 123,
/* 120 */ 50267,
/* 121 */ -107,
/* 122 */ 138,
/* 123 */ 0,
/* 124 */ 50282,
/* 125 */ -107,
/* 126 */ 139,
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
/* 140 */ 1166,
/* 141 */ -127,
/* 142 */ 12,
/* 143 */ 147,
/* 144 */ 50285,
/* 145 */ -143,
/* 146 */ 140,
/* 147 */ 151,
/* 148 */ 50259,
/* 149 */ -143,
/* 150 */ 141,
/* 151 */ 155,
/* 152 */ 50276,
/* 153 */ -143,
/* 154 */ 142,
/* 155 */ 159,
/* 156 */ 50272,
/* 157 */ -143,
/* 158 */ 143,
/* 159 */ 163,
/* 160 */ 50273,
/* 161 */ -143,
/* 162 */ 144,
/* 163 */ 167,
/* 164 */ 50268,
/* 165 */ -143,
/* 166 */ 145,
/* 167 */ 171,
/* 168 */ 50264,
/* 169 */ -143,
/* 170 */ 146,
/* 171 */ 175,
/* 172 */ 50277,
/* 173 */ -143,
/* 174 */ 147,
/* 175 */ 0,
/* 176 */ 50284,
/* 177 */ -143,
/* 178 */ 148,
/* 179 */ 0,
/* 180 */ 183,
/* 181 */ -179,
/* 182 */ 13,
/* 183 */ 187,
/* 184 */ 50260,
/* 185 */ -183,
/* 186 */ 149,
/* 187 */ 0,
/* 188 */ 50286,
/* 189 */ -183,
/* 190 */ 150,
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
/* 201 */ 1166,
/* 202 */ -191,
/* 203 */ 15,
/* 204 */ 208,
/* 205 */ 1166,
/* 206 */ -204,
/* 207 */ 151,
/* 208 */ 0,
/* 209 */ -204,
/* 210 */ 221,
/* 211 */ 0,
/* 212 */ 215,
/* 213 */ -211,
/* 214 */ 16,
/* 215 */ 219,
/* 216 */ 50280,
/* 217 */ -215,
/* 218 */ 152,
/* 219 */ 0,
/* 220 */ 50283,
/* 221 */ -215,
/* 222 */ 153,
/* 223 */ 0,
/* 224 */ 228,
/* 225 */ 261,
/* 226 */ -223,
/* 227 */ 17,
/* 228 */ 232,
/* 229 */ 223,
/* 230 */ -228,
/* 231 */ 154,
/* 232 */ 0,
/* 233 */ -228,
/* 234 */ 222,
/* 235 */ 0,
/* 236 */ 240,
/* 237 */ 248,
/* 238 */ -235,
/* 239 */ 18,
/* 240 */ 245,
/* 241 */ 235,
/* 242 */ 50044,
/* 243 */ -240,
/* 244 */ 155,
/* 245 */ 0,
/* 246 */ -240,
/* 247 */ 223,
/* 248 */ 0,
/* 249 */ 253,
/* 250 */ 513,
/* 251 */ -248,
/* 252 */ 19,
/* 253 */ 258,
/* 254 */ 363,
/* 255 */ 50061,
/* 256 */ -253,
/* 257 */ 156,
/* 258 */ 0,
/* 259 */ -253,
/* 260 */ 224,
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
/* 275 */ 157,
/* 276 */ 0,
/* 277 */ 179,
/* 278 */ -272,
/* 279 */ 158,
/* 280 */ 284,
/* 281 */ 267,
/* 282 */ -280,
/* 283 */ 159,
/* 284 */ 0,
/* 285 */ -280,
/* 286 */ 225,
/* 287 */ 0,
/* 288 */ 292,
/* 289 */ 300,
/* 290 */ -287,
/* 291 */ 22,
/* 292 */ 297,
/* 293 */ 287,
/* 294 */ 50044,
/* 295 */ -292,
/* 296 */ 160,
/* 297 */ 0,
/* 298 */ -292,
/* 299 */ 226,
/* 300 */ 304,
/* 301 */ 363,
/* 302 */ -300,
/* 303 */ 23,
/* 304 */ 0,
/* 305 */ 310,
/* 306 */ 50058,
/* 307 */ 884,
/* 308 */ -300,
/* 309 */ 24,
/* 310 */ 314,
/* 311 */ 363,
/* 312 */ -310,
/* 313 */ 161,
/* 314 */ 0,
/* 315 */ -310,
/* 316 */ 227,
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
/* 327 */ 1166,
/* 328 */ -317,
/* 329 */ 26,
/* 330 */ 334,
/* 331 */ 1166,
/* 332 */ -330,
/* 333 */ 162,
/* 334 */ 0,
/* 335 */ -330,
/* 336 */ 228,
/* 337 */ 0,
/* 338 */ 342,
/* 339 */ 350,
/* 340 */ -337,
/* 341 */ 27,
/* 342 */ 347,
/* 343 */ 337,
/* 344 */ 50044,
/* 345 */ -342,
/* 346 */ 163,
/* 347 */ 0,
/* 348 */ -342,
/* 349 */ 229,
/* 350 */ 0,
/* 351 */ 1166,
/* 352 */ 355,
/* 353 */ -350,
/* 354 */ 28,
/* 355 */ 360,
/* 356 */ 50061,
/* 357 */ 884,
/* 358 */ -355,
/* 359 */ 164,
/* 360 */ 0,
/* 361 */ -355,
/* 362 */ 230,
/* 363 */ 0,
/* 364 */ 368,
/* 365 */ 375,
/* 366 */ -363,
/* 367 */ 29,
/* 368 */ 372,
/* 369 */ 422,
/* 370 */ -368,
/* 371 */ 165,
/* 372 */ 0,
/* 373 */ -368,
/* 374 */ 231,
/* 375 */ 379,
/* 376 */ 1166,
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
/* 395 */ 167,
/* 396 */ 402,
/* 397 */ 50040,
/* 398 */ 454,
/* 399 */ 50041,
/* 400 */ -390,
/* 401 */ 168,
/* 402 */ 0,
/* 403 */ 50040,
/* 404 */ 415,
/* 405 */ 50041,
/* 406 */ -390,
/* 407 */ 170,
/* 408 */ 412,
/* 409 */ 844,
/* 410 */ -408,
/* 411 */ 166,
/* 412 */ 0,
/* 413 */ -408,
/* 414 */ 232,
/* 415 */ 419,
/* 416 */ 500,
/* 417 */ -415,
/* 418 */ 169,
/* 419 */ 0,
/* 420 */ -415,
/* 421 */ 233,
/* 422 */ 0,
/* 423 */ 50042,
/* 424 */ 428,
/* 425 */ 435,
/* 426 */ -422,
/* 427 */ 33,
/* 428 */ 432,
/* 429 */ 442,
/* 430 */ -428,
/* 431 */ 171,
/* 432 */ 0,
/* 433 */ -428,
/* 434 */ 234,
/* 435 */ 439,
/* 436 */ 422,
/* 437 */ -435,
/* 438 */ 172,
/* 439 */ 0,
/* 440 */ -435,
/* 441 */ 235,
/* 442 */ 0,
/* 443 */ 447,
/* 444 */ 179,
/* 445 */ -442,
/* 446 */ 34,
/* 447 */ 451,
/* 448 */ 442,
/* 449 */ -447,
/* 450 */ 173,
/* 451 */ 0,
/* 452 */ -447,
/* 453 */ 236,
/* 454 */ 0,
/* 455 */ 467,
/* 456 */ 459,
/* 457 */ -454,
/* 458 */ 35,
/* 459 */ 464,
/* 460 */ 50044,
/* 461 */ 50290,
/* 462 */ -459,
/* 463 */ 174,
/* 464 */ 0,
/* 465 */ -459,
/* 466 */ 237,
/* 467 */ 0,
/* 468 */ 472,
/* 469 */ 480,
/* 470 */ -467,
/* 471 */ 36,
/* 472 */ 477,
/* 473 */ 467,
/* 474 */ 50044,
/* 475 */ -472,
/* 476 */ 175,
/* 477 */ 0,
/* 478 */ -472,
/* 479 */ 238,
/* 480 */ 0,
/* 481 */ 81,
/* 482 */ 485,
/* 483 */ -480,
/* 484 */ 37,
/* 485 */ 489,
/* 486 */ 363,
/* 487 */ -485,
/* 488 */ 176,
/* 489 */ 0,
/* 490 */ 493,
/* 491 */ -485,
/* 492 */ 178,
/* 493 */ 497,
/* 494 */ 556,
/* 495 */ -493,
/* 496 */ 177,
/* 497 */ 0,
/* 498 */ -493,
/* 499 */ 239,
/* 500 */ 0,
/* 501 */ 505,
/* 502 */ 1166,
/* 503 */ -500,
/* 504 */ 38,
/* 505 */ 510,
/* 506 */ 500,
/* 507 */ 50044,
/* 508 */ -505,
/* 509 */ 179,
/* 510 */ 0,
/* 511 */ -505,
/* 512 */ 240,
/* 513 */ 517,
/* 514 */ 854,
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
/* 527 */ 180,
/* 528 */ 0,
/* 529 */ -524,
/* 530 */ 241,
/* 531 */ 0,
/* 532 */ 536,
/* 533 */ 513,
/* 534 */ -531,
/* 535 */ 41,
/* 536 */ 541,
/* 537 */ 531,
/* 538 */ 50044,
/* 539 */ -536,
/* 540 */ 181,
/* 541 */ 0,
/* 542 */ -536,
/* 543 */ 242,
/* 544 */ 0,
/* 545 */ 267,
/* 546 */ 549,
/* 547 */ -544,
/* 548 */ 42,
/* 549 */ 553,
/* 550 */ 556,
/* 551 */ -549,
/* 552 */ 182,
/* 553 */ 0,
/* 554 */ -549,
/* 555 */ 243,
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
/* 568 */ 183,
/* 569 */ 0,
/* 570 */ -565,
/* 571 */ 244,
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
/* 586 */ 184,
/* 587 */ 0,
/* 588 */ -583,
/* 589 */ 245,
/* 590 */ 596,
/* 591 */ 50091,
/* 592 */ 602,
/* 593 */ 50093,
/* 594 */ -590,
/* 595 */ 186,
/* 596 */ 0,
/* 597 */ 50040,
/* 598 */ 609,
/* 599 */ 50041,
/* 600 */ -590,
/* 601 */ 188,
/* 602 */ 606,
/* 603 */ 844,
/* 604 */ -602,
/* 605 */ 185,
/* 606 */ 0,
/* 607 */ -602,
/* 608 */ 246,
/* 609 */ 613,
/* 610 */ 454,
/* 611 */ -609,
/* 612 */ 187,
/* 613 */ 0,
/* 614 */ -609,
/* 615 */ 247,
/* 616 */ 0,
/* 617 */ 1166,
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
/* 653 */ 1166,
/* 654 */ 50058,
/* 655 */ 620,
/* 656 */ -652,
/* 657 */ 56,
/* 658 */ 665,
/* 659 */ 50258,
/* 660 */ 884,
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
/* 679 */ 189,
/* 680 */ 0,
/* 681 */ -676,
/* 682 */ 248,
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
/* 693 */ 190,
/* 694 */ 0,
/* 695 */ -690,
/* 696 */ 249,
/* 697 */ 701,
/* 698 */ 704,
/* 699 */ -697,
/* 700 */ 191,
/* 701 */ 0,
/* 702 */ -697,
/* 703 */ 250,
/* 704 */ 0,
/* 705 */ 709,
/* 706 */ 620,
/* 707 */ -704,
/* 708 */ 61,
/* 709 */ 714,
/* 710 */ 620,
/* 711 */ 709,
/* 712 */ -709,
/* 713 */ 192,
/* 714 */ 0,
/* 715 */ -709,
/* 716 */ 251,
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
/* 738 */ 193,
/* 739 */ 0,
/* 740 */ -734,
/* 741 */ 252,
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
/* 775 */ 194,
/* 776 */ 0,
/* 777 */ -772,
/* 778 */ 253,
/* 779 */ 783,
/* 780 */ 844,
/* 781 */ -779,
/* 782 */ 195,
/* 783 */ 0,
/* 784 */ -779,
/* 785 */ 254,
/* 786 */ 790,
/* 787 */ 844,
/* 788 */ -786,
/* 789 */ 196,
/* 790 */ 0,
/* 791 */ -786,
/* 792 */ 255,
/* 793 */ 799,
/* 794 */ 50270,
/* 795 */ 1166,
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
/* 818 */ 197,
/* 819 */ 0,
/* 820 */ -815,
/* 821 */ 256,
/* 822 */ 0,
/* 823 */ 50305,
/* 824 */ 1136,
/* 825 */ 50059,
/* 826 */ -822,
/* 827 */ 71,
/* 828 */ 0,
/* 829 */ 50306,
/* 830 */ 835,
/* 831 */ 1166,
/* 832 */ 50059,
/* 833 */ -828,
/* 834 */ 72,
/* 835 */ 841,
/* 836 */ 1166,
/* 837 */ 50044,
/* 838 */ 835,
/* 839 */ -835,
/* 840 */ 198,
/* 841 */ 0,
/* 842 */ -835,
/* 843 */ 257,
/* 844 */ 848,
/* 845 */ 854,
/* 846 */ -844,
/* 847 */ 73,
/* 848 */ 0,
/* 849 */ 844,
/* 850 */ 50044,
/* 851 */ 854,
/* 852 */ -844,
/* 853 */ 74,
/* 854 */ 858,
/* 855 */ 872,
/* 856 */ -854,
/* 857 */ 75,
/* 858 */ 0,
/* 859 */ 1009,
/* 860 */ 864,
/* 861 */ 854,
/* 862 */ -854,
/* 863 */ 76,
/* 864 */ 868,
/* 865 */ 50291,
/* 866 */ -864,
/* 867 */ 77,
/* 868 */ 0,
/* 869 */ 50061,
/* 870 */ -864,
/* 871 */ 78,
/* 872 */ 876,
/* 873 */ 888,
/* 874 */ -872,
/* 875 */ 79,
/* 876 */ 0,
/* 877 */ 888,
/* 878 */ 50063,
/* 879 */ 844,
/* 880 */ 50058,
/* 881 */ 872,
/* 882 */ -872,
/* 883 */ 80,
/* 884 */ 0,
/* 885 */ 872,
/* 886 */ -884,
/* 887 */ 81,
/* 888 */ 892,
/* 889 */ 898,
/* 890 */ -888,
/* 891 */ 82,
/* 892 */ 0,
/* 893 */ 888,
/* 894 */ 50297,
/* 895 */ 898,
/* 896 */ -888,
/* 897 */ 83,
/* 898 */ 902,
/* 899 */ 908,
/* 900 */ -898,
/* 901 */ 84,
/* 902 */ 0,
/* 903 */ 898,
/* 904 */ 50298,
/* 905 */ 908,
/* 906 */ -898,
/* 907 */ 85,
/* 908 */ 912,
/* 909 */ 918,
/* 910 */ -908,
/* 911 */ 86,
/* 912 */ 0,
/* 913 */ 908,
/* 914 */ 50124,
/* 915 */ 918,
/* 916 */ -908,
/* 917 */ 87,
/* 918 */ 922,
/* 919 */ 928,
/* 920 */ -918,
/* 921 */ 88,
/* 922 */ 0,
/* 923 */ 918,
/* 924 */ 50094,
/* 925 */ 928,
/* 926 */ -918,
/* 927 */ 89,
/* 928 */ 932,
/* 929 */ 938,
/* 930 */ -928,
/* 931 */ 90,
/* 932 */ 0,
/* 933 */ 928,
/* 934 */ 50038,
/* 935 */ 938,
/* 936 */ -928,
/* 937 */ 91,
/* 938 */ 942,
/* 939 */ 948,
/* 940 */ -938,
/* 941 */ 92,
/* 942 */ 0,
/* 943 */ 938,
/* 944 */ 50292,
/* 945 */ 948,
/* 946 */ -938,
/* 947 */ 93,
/* 948 */ 952,
/* 949 */ 958,
/* 950 */ -948,
/* 951 */ 94,
/* 952 */ 0,
/* 953 */ 948,
/* 954 */ 50300,
/* 955 */ 958,
/* 956 */ -948,
/* 957 */ 95,
/* 958 */ 962,
/* 959 */ 976,
/* 960 */ -958,
/* 961 */ 96,
/* 962 */ 0,
/* 963 */ 958,
/* 964 */ 968,
/* 965 */ 976,
/* 966 */ -958,
/* 967 */ 97,
/* 968 */ 972,
/* 969 */ 50043,
/* 970 */ -968,
/* 971 */ 199,
/* 972 */ 0,
/* 973 */ 50045,
/* 974 */ -968,
/* 975 */ 200,
/* 976 */ 980,
/* 977 */ 998,
/* 978 */ -976,
/* 979 */ 98,
/* 980 */ 0,
/* 981 */ 976,
/* 982 */ 986,
/* 983 */ 998,
/* 984 */ -976,
/* 985 */ 99,
/* 986 */ 990,
/* 987 */ 50042,
/* 988 */ -986,
/* 989 */ 201,
/* 990 */ 994,
/* 991 */ 50047,
/* 992 */ -986,
/* 993 */ 202,
/* 994 */ 0,
/* 995 */ 50037,
/* 996 */ -986,
/* 997 */ 203,
/* 998 */ 1002,
/* 999 */ 1009,
/* 1000 */ -998,
/* 1001 */ 100,
/* 1002 */ 0,
/* 1003 */ 50040,
/* 1004 */ 544,
/* 1005 */ 50041,
/* 1006 */ 998,
/* 1007 */ -998,
/* 1008 */ 101,
/* 1009 */ 1013,
/* 1010 */ 1067,
/* 1011 */ -1009,
/* 1012 */ 102,
/* 1013 */ 1018,
/* 1014 */ 1035,
/* 1015 */ 1009,
/* 1016 */ -1009,
/* 1017 */ 103,
/* 1018 */ 1023,
/* 1019 */ 1043,
/* 1020 */ 998,
/* 1021 */ -1009,
/* 1022 */ 104,
/* 1023 */ 1028,
/* 1024 */ 50278,
/* 1025 */ 1009,
/* 1026 */ -1009,
/* 1027 */ 105,
/* 1028 */ 0,
/* 1029 */ 50278,
/* 1030 */ 50040,
/* 1031 */ 544,
/* 1032 */ 50041,
/* 1033 */ -1009,
/* 1034 */ 106,
/* 1035 */ 1039,
/* 1036 */ 50294,
/* 1037 */ -1035,
/* 1038 */ 204,
/* 1039 */ 0,
/* 1040 */ 50295,
/* 1041 */ -1035,
/* 1042 */ 205,
/* 1043 */ 1047,
/* 1044 */ 50038,
/* 1045 */ -1043,
/* 1046 */ 107,
/* 1047 */ 1051,
/* 1048 */ 50042,
/* 1049 */ -1043,
/* 1050 */ 108,
/* 1051 */ 1055,
/* 1052 */ 50043,
/* 1053 */ -1043,
/* 1054 */ 109,
/* 1055 */ 1059,
/* 1056 */ 50045,
/* 1057 */ -1043,
/* 1058 */ 110,
/* 1059 */ 1063,
/* 1060 */ 50126,
/* 1061 */ -1043,
/* 1062 */ 111,
/* 1063 */ 0,
/* 1064 */ 50033,
/* 1065 */ -1043,
/* 1066 */ 112,
/* 1067 */ 1071,
/* 1068 */ 1122,
/* 1069 */ -1067,
/* 1070 */ 113,
/* 1071 */ 0,
/* 1072 */ 1067,
/* 1073 */ 1076,
/* 1074 */ -1067,
/* 1075 */ 114,
/* 1076 */ 1083,
/* 1077 */ 50091,
/* 1078 */ 844,
/* 1079 */ 1107,
/* 1080 */ 50093,
/* 1081 */ -1076,
/* 1082 */ 207,
/* 1083 */ 1089,
/* 1084 */ 50040,
/* 1085 */ 1115,
/* 1086 */ 50041,
/* 1087 */ -1076,
/* 1088 */ 209,
/* 1089 */ 1094,
/* 1090 */ 50046,
/* 1091 */ 1166,
/* 1092 */ -1076,
/* 1093 */ 210,
/* 1094 */ 1099,
/* 1095 */ 50296,
/* 1096 */ 1166,
/* 1097 */ -1076,
/* 1098 */ 211,
/* 1099 */ 1103,
/* 1100 */ 50294,
/* 1101 */ -1076,
/* 1102 */ 212,
/* 1103 */ 0,
/* 1104 */ 50295,
/* 1105 */ -1076,
/* 1106 */ 213,
/* 1107 */ 1112,
/* 1108 */ 50058,
/* 1109 */ 844,
/* 1110 */ -1107,
/* 1111 */ 206,
/* 1112 */ 0,
/* 1113 */ -1107,
/* 1114 */ 258,
/* 1115 */ 1119,
/* 1116 */ 1136,
/* 1117 */ -1115,
/* 1118 */ 208,
/* 1119 */ 0,
/* 1120 */ -1115,
/* 1121 */ 259,
/* 1122 */ 1126,
/* 1123 */ 1166,
/* 1124 */ -1122,
/* 1125 */ 115,
/* 1126 */ 1130,
/* 1127 */ 1150,
/* 1128 */ -1122,
/* 1129 */ 116,
/* 1130 */ 0,
/* 1131 */ 50040,
/* 1132 */ 844,
/* 1133 */ 50041,
/* 1134 */ -1122,
/* 1135 */ 117,
/* 1136 */ 0,
/* 1137 */ 1141,
/* 1138 */ 854,
/* 1139 */ -1136,
/* 1140 */ 118,
/* 1141 */ 1147,
/* 1142 */ 854,
/* 1143 */ 50044,
/* 1144 */ 1141,
/* 1145 */ -1141,
/* 1146 */ 214,
/* 1147 */ 0,
/* 1148 */ -1141,
/* 1149 */ 260,
/* 1150 */ 1154,
/* 1151 */ 50304,
/* 1152 */ -1150,
/* 1153 */ 119,
/* 1154 */ 1158,
/* 1155 */ 50302,
/* 1156 */ -1150,
/* 1157 */ 120,
/* 1158 */ 1162,
/* 1159 */ 50303,
/* 1160 */ -1150,
/* 1161 */ 121,
/* 1162 */ 0,
/* 1163 */ 50289,
/* 1164 */ -1150,
/* 1165 */ 122,
/* 1166 */ 0,
/* 1167 */ 50299,
/* 1168 */ -1166,
/* 1169 */ 123,
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
/* 844 */ 848,
/* 845 */ 1,
/* 846 */ -844,
/* 847 */ 1,
/* 848 */ 0,
/* 849 */ 1,
/* 850 */ 50044,
/* 851 */ 1,
/* 852 */ -844,
/* 853 */ 2,
/* 854 */ 858,
/* 855 */ 1,
/* 856 */ -854,
/* 857 */ 1,
/* 858 */ 0,
/* 859 */ 1,
/* 860 */ 1,
/* 861 */ 1,
/* 862 */ -854,
/* 863 */ 2,
/* 864 */ 868,
/* 865 */ 50291,
/* 866 */ -864,
/* 867 */ 1,
/* 868 */ 0,
/* 869 */ 50061,
/* 870 */ -864,
/* 871 */ 2,
/* 872 */ 876,
/* 873 */ 1,
/* 874 */ -872,
/* 875 */ 1,
/* 876 */ 0,
/* 877 */ 1,
/* 878 */ 50063,
/* 879 */ 1,
/* 880 */ 50058,
/* 881 */ 1,
/* 882 */ -872,
/* 883 */ 2,
/* 884 */ 0,
/* 885 */ 1,
/* 886 */ -884,
/* 887 */ 1,
/* 888 */ 892,
/* 889 */ 1,
/* 890 */ -888,
/* 891 */ 1,
/* 892 */ 0,
/* 893 */ 1,
/* 894 */ 50297,
/* 895 */ 1,
/* 896 */ -888,
/* 897 */ 2,
/* 898 */ 902,
/* 899 */ 1,
/* 900 */ -898,
/* 901 */ 1,
/* 902 */ 0,
/* 903 */ 1,
/* 904 */ 50298,
/* 905 */ 1,
/* 906 */ -898,
/* 907 */ 2,
/* 908 */ 912,
/* 909 */ 1,
/* 910 */ -908,
/* 911 */ 1,
/* 912 */ 0,
/* 913 */ 1,
/* 914 */ 50124,
/* 915 */ 1,
/* 916 */ -908,
/* 917 */ 2,
/* 918 */ 922,
/* 919 */ 1,
/* 920 */ -918,
/* 921 */ 1,
/* 922 */ 0,
/* 923 */ 1,
/* 924 */ 50094,
/* 925 */ 1,
/* 926 */ -918,
/* 927 */ 2,
/* 928 */ 932,
/* 929 */ 1,
/* 930 */ -928,
/* 931 */ 1,
/* 932 */ 0,
/* 933 */ 1,
/* 934 */ 50038,
/* 935 */ 1,
/* 936 */ -928,
/* 937 */ 2,
/* 938 */ 942,
/* 939 */ 1,
/* 940 */ -938,
/* 941 */ 1,
/* 942 */ 0,
/* 943 */ 1,
/* 944 */ 50292,
/* 945 */ 1,
/* 946 */ -938,
/* 947 */ 2,
/* 948 */ 952,
/* 949 */ 1,
/* 950 */ -948,
/* 951 */ 1,
/* 952 */ 0,
/* 953 */ 1,
/* 954 */ 50300,
/* 955 */ 1,
/* 956 */ -948,
/* 957 */ 2,
/* 958 */ 962,
/* 959 */ 1,
/* 960 */ -958,
/* 961 */ 1,
/* 962 */ 0,
/* 963 */ 1,
/* 964 */ 1,
/* 965 */ 1,
/* 966 */ -958,
/* 967 */ 2,
/* 968 */ 972,
/* 969 */ 50043,
/* 970 */ -968,
/* 971 */ 1,
/* 972 */ 0,
/* 973 */ 50045,
/* 974 */ -968,
/* 975 */ 2,
/* 976 */ 980,
/* 977 */ 1,
/* 978 */ -976,
/* 979 */ 1,
/* 980 */ 0,
/* 981 */ 1,
/* 982 */ 1,
/* 983 */ 1,
/* 984 */ -976,
/* 985 */ 2,
/* 986 */ 990,
/* 987 */ 50042,
/* 988 */ -986,
/* 989 */ 1,
/* 990 */ 994,
/* 991 */ 50047,
/* 992 */ -986,
/* 993 */ 2,
/* 994 */ 0,
/* 995 */ 50037,
/* 996 */ -986,
/* 997 */ 3,
/* 998 */ 1002,
/* 999 */ 1,
/* 1000 */ -998,
/* 1001 */ 1,
/* 1002 */ 0,
/* 1003 */ 50040,
/* 1004 */ 1,
/* 1005 */ 50041,
/* 1006 */ 1,
/* 1007 */ -998,
/* 1008 */ 2,
/* 1009 */ 1013,
/* 1010 */ 1,
/* 1011 */ -1009,
/* 1012 */ 1,
/* 1013 */ 1018,
/* 1014 */ 1,
/* 1015 */ 1,
/* 1016 */ -1009,
/* 1017 */ 2,
/* 1018 */ 1023,
/* 1019 */ 1,
/* 1020 */ 1,
/* 1021 */ -1009,
/* 1022 */ 3,
/* 1023 */ 1028,
/* 1024 */ 50278,
/* 1025 */ 1,
/* 1026 */ -1009,
/* 1027 */ 4,
/* 1028 */ 0,
/* 1029 */ 50278,
/* 1030 */ 50040,
/* 1031 */ 1,
/* 1032 */ 50041,
/* 1033 */ -1009,
/* 1034 */ 5,
/* 1035 */ 1039,
/* 1036 */ 50294,
/* 1037 */ -1035,
/* 1038 */ 1,
/* 1039 */ 0,
/* 1040 */ 50295,
/* 1041 */ -1035,
/* 1042 */ 2,
/* 1043 */ 1047,
/* 1044 */ 50038,
/* 1045 */ -1043,
/* 1046 */ 1,
/* 1047 */ 1051,
/* 1048 */ 50042,
/* 1049 */ -1043,
/* 1050 */ 2,
/* 1051 */ 1055,
/* 1052 */ 50043,
/* 1053 */ -1043,
/* 1054 */ 3,
/* 1055 */ 1059,
/* 1056 */ 50045,
/* 1057 */ -1043,
/* 1058 */ 4,
/* 1059 */ 1063,
/* 1060 */ 50126,
/* 1061 */ -1043,
/* 1062 */ 5,
/* 1063 */ 0,
/* 1064 */ 50033,
/* 1065 */ -1043,
/* 1066 */ 6,
/* 1067 */ 1071,
/* 1068 */ 1,
/* 1069 */ -1067,
/* 1070 */ 1,
/* 1071 */ 0,
/* 1072 */ 1,
/* 1073 */ 1,
/* 1074 */ -1067,
/* 1075 */ 2,
/* 1076 */ 1083,
/* 1077 */ 50091,
/* 1078 */ 1,
/* 1079 */ 1,
/* 1080 */ 50093,
/* 1081 */ -1076,
/* 1082 */ 1,
/* 1083 */ 1089,
/* 1084 */ 50040,
/* 1085 */ 1,
/* 1086 */ 50041,
/* 1087 */ -1076,
/* 1088 */ 2,
/* 1089 */ 1094,
/* 1090 */ 50046,
/* 1091 */ 1,
/* 1092 */ -1076,
/* 1093 */ 3,
/* 1094 */ 1099,
/* 1095 */ 50296,
/* 1096 */ 1,
/* 1097 */ -1076,
/* 1098 */ 4,
/* 1099 */ 1103,
/* 1100 */ 50294,
/* 1101 */ -1076,
/* 1102 */ 5,
/* 1103 */ 0,
/* 1104 */ 50295,
/* 1105 */ -1076,
/* 1106 */ 6,
/* 1107 */ 1112,
/* 1108 */ 50058,
/* 1109 */ 1,
/* 1110 */ -1107,
/* 1111 */ 1,
/* 1112 */ 0,
/* 1113 */ -1107,
/* 1114 */ 2,
/* 1115 */ 1119,
/* 1116 */ 1,
/* 1117 */ -1115,
/* 1118 */ 1,
/* 1119 */ 0,
/* 1120 */ -1115,
/* 1121 */ 2,
/* 1122 */ 1126,
/* 1123 */ 1,
/* 1124 */ -1122,
/* 1125 */ 1,
/* 1126 */ 1130,
/* 1127 */ 1,
/* 1128 */ -1122,
/* 1129 */ 2,
/* 1130 */ 0,
/* 1131 */ 50040,
/* 1132 */ 1,
/* 1133 */ 50041,
/* 1134 */ -1122,
/* 1135 */ 3,
/* 1136 */ 0,
/* 1137 */ 1,
/* 1138 */ 1,
/* 1139 */ -1136,
/* 1140 */ 1,
/* 1141 */ 1147,
/* 1142 */ 1,
/* 1143 */ 50044,
/* 1144 */ 1,
/* 1145 */ -1141,
/* 1146 */ 1,
/* 1147 */ 0,
/* 1148 */ -1141,
/* 1149 */ 2,
/* 1150 */ 1154,
/* 1151 */ 50304,
/* 1152 */ -1150,
/* 1153 */ 1,
/* 1154 */ 1158,
/* 1155 */ 50302,
/* 1156 */ -1150,
/* 1157 */ 2,
/* 1158 */ 1162,
/* 1159 */ 50303,
/* 1160 */ -1150,
/* 1161 */ 3,
/* 1162 */ 0,
/* 1163 */ 50289,
/* 1164 */ -1150,
/* 1165 */ 4,
/* 1166 */ 0,
/* 1167 */ 50299,
/* 1168 */ -1166,
/* 1169 */ 1,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 21002,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 21002,
/* 6 */ 9999,
/* 7 */ 21004,
/* 8 */ 9999,
/* 9 */ 21004,
/* 10 */ 9999,
/* 11 */ 21006,
/* 12 */ 21025,
/* 13 */ 9999,
/* 14 */ 21025,
/* 15 */ 9999,
/* 16 */ 9999,
/* 17 */ 21025,
/* 18 */ 9999,
/* 19 */ 25004,
/* 20 */ 9999,
/* 21 */ 25022,
/* 22 */ 9999,
/* 23 */ 26004,
/* 24 */ 9999,
/* 25 */ 26014,
/* 26 */ 9999,
/* 27 */ 30004,
/* 28 */ 30032,
/* 29 */ 30043,
/* 30 */ 30065,
/* 31 */ 9999,
/* 32 */ 30004,
/* 33 */ 9999,
/* 34 */ 30006,
/* 35 */ 9999,
/* 36 */ 30027,
/* 37 */ 9999,
/* 38 */ 9999,
/* 39 */ 30027,
/* 40 */ 9999,
/* 41 */ 30045,
/* 42 */ 9999,
/* 43 */ 30060,
/* 44 */ 9999,
/* 45 */ 9999,
/* 46 */ 30060,
/* 47 */ 9999,
/* 48 */ 9999,
/* 49 */ 9999,
/* 50 */ 30067,
/* 51 */ 9999,
/* 52 */ 30073,
/* 53 */ 9999,
/* 54 */ 30090,
/* 55 */ 9999,
/* 56 */ 34004,
/* 57 */ 34027,
/* 58 */ 9999,
/* 59 */ 9999,
/* 60 */ 34025,
/* 61 */ 9999,
/* 62 */ 34029,
/* 63 */ 9999,
/* 64 */ 34048,
/* 65 */ 9999,
/* 66 */ 9999,
/* 67 */ 34048,
/* 68 */ 9999,
/* 69 */ 38004,
/* 70 */ 38016,
/* 71 */ 9999,
/* 72 */ 38014,
/* 73 */ 9999,
/* 74 */ 38018,
/* 75 */ 38028,
/* 76 */ 9999,
/* 77 */ 38028,
/* 78 */ 9999,
/* 79 */ 9999,
/* 80 */ 38028,
/* 81 */ 9999,
/* 82 */ 42004,
/* 83 */ 9999,
/* 84 */ 42004,
/* 85 */ 9999,
/* 86 */ 42006,
/* 87 */ 42028,
/* 88 */ 9999,
/* 89 */ 42028,
/* 90 */ 9999,
/* 91 */ 42032,
/* 92 */ 42045,
/* 93 */ 9999,
/* 94 */ 42045,
/* 95 */ 9999,
/* 96 */ 42049,
/* 97 */ 42062,
/* 98 */ 9999,
/* 99 */ 42062,
/* 100 */ 9999,
/* 101 */ 9999,
/* 102 */ 42062,
/* 103 */ 9999,
/* 104 */ 46004,
/* 105 */ 9999,
/* 106 */ 46004,
/* 107 */ 9999,
/* 108 */ 9999,
/* 109 */ 9999,
/* 110 */ 46009,
/* 111 */ 9999,
/* 112 */ 9999,
/* 113 */ 9999,
/* 114 */ 47011,
/* 115 */ 9999,
/* 116 */ 9999,
/* 117 */ 9999,
/* 118 */ 48009,
/* 119 */ 9999,
/* 120 */ 9999,
/* 121 */ 9999,
/* 122 */ 49009,
/* 123 */ 9999,
/* 124 */ 9999,
/* 125 */ 9999,
/* 126 */ 50010,
/* 127 */ 9999,
/* 128 */ 55004,
/* 129 */ 9999,
/* 130 */ 55004,
/* 131 */ 9999,
/* 132 */ 64004,
/* 133 */ 9999,
/* 134 */ 64028,
/* 135 */ 9999,
/* 136 */ 64032,
/* 137 */ 9999,
/* 138 */ 64045,
/* 139 */ 9999,
/* 140 */ 65004,
/* 141 */ 9999,
/* 142 */ 65005,
/* 143 */ 9999,
/* 144 */ 9999,
/* 145 */ 9999,
/* 146 */ 55009,
/* 147 */ 9999,
/* 148 */ 9999,
/* 149 */ 9999,
/* 150 */ 56007,
/* 151 */ 9999,
/* 152 */ 9999,
/* 153 */ 9999,
/* 154 */ 57008,
/* 155 */ 9999,
/* 156 */ 9999,
/* 157 */ 9999,
/* 158 */ 58006,
/* 159 */ 9999,
/* 160 */ 9999,
/* 161 */ 9999,
/* 162 */ 59007,
/* 163 */ 9999,
/* 164 */ 9999,
/* 165 */ 9999,
/* 166 */ 60008,
/* 167 */ 9999,
/* 168 */ 9999,
/* 169 */ 9999,
/* 170 */ 61009,
/* 171 */ 9999,
/* 172 */ 9999,
/* 173 */ 9999,
/* 174 */ 62009,
/* 175 */ 9999,
/* 176 */ 9999,
/* 177 */ 9999,
/* 178 */ 63011,
/* 179 */ 9999,
/* 180 */ 69004,
/* 181 */ 9999,
/* 182 */ 69004,
/* 183 */ 9999,
/* 184 */ 9999,
/* 185 */ 9999,
/* 186 */ 69010,
/* 187 */ 9999,
/* 188 */ 9999,
/* 189 */ 9999,
/* 190 */ 70011,
/* 191 */ 9999,
/* 192 */ 74004,
/* 193 */ 74020,
/* 194 */ 9999,
/* 195 */ 74035,
/* 196 */ 9999,
/* 197 */ 9999,
/* 198 */ 74018,
/* 199 */ 9999,
/* 200 */ 75004,
/* 201 */ 75020,
/* 202 */ 9999,
/* 203 */ 75018,
/* 204 */ 9999,
/* 205 */ 74022,
/* 206 */ 9999,
/* 207 */ 74023,
/* 208 */ 9999,
/* 209 */ 9999,
/* 210 */ 74023,
/* 211 */ 9999,
/* 212 */ 79004,
/* 213 */ 9999,
/* 214 */ 79004,
/* 215 */ 9999,
/* 216 */ 9999,
/* 217 */ 9999,
/* 218 */ 79011,
/* 219 */ 9999,
/* 220 */ 9999,
/* 221 */ 9999,
/* 222 */ 79019,
/* 223 */ 9999,
/* 224 */ 83004,
/* 225 */ 83033,
/* 226 */ 9999,
/* 227 */ 83004,
/* 228 */ 9999,
/* 229 */ 83006,
/* 230 */ 9999,
/* 231 */ 83028,
/* 232 */ 9999,
/* 233 */ 9999,
/* 234 */ 83028,
/* 235 */ 9999,
/* 236 */ 87004,
/* 237 */ 87034,
/* 238 */ 9999,
/* 239 */ 87004,
/* 240 */ 9999,
/* 241 */ 87006,
/* 242 */ 9999,
/* 243 */ 9999,
/* 244 */ 87025,
/* 245 */ 9999,
/* 246 */ 9999,
/* 247 */ 87025,
/* 248 */ 9999,
/* 249 */ 91004,
/* 250 */ 91024,
/* 251 */ 9999,
/* 252 */ 91004,
/* 253 */ 9999,
/* 254 */ 91006,
/* 255 */ 9999,
/* 256 */ 9999,
/* 257 */ 91015,
/* 258 */ 9999,
/* 259 */ 9999,
/* 260 */ 91015,
/* 261 */ 9999,
/* 262 */ 95004,
/* 263 */ 95029,
/* 264 */ 9999,
/* 265 */ 9999,
/* 266 */ 95027,
/* 267 */ 9999,
/* 268 */ 99004,
/* 269 */ 99040,
/* 270 */ 9999,
/* 271 */ 99004,
/* 272 */ 9999,
/* 273 */ 99006,
/* 274 */ 9999,
/* 275 */ 99019,
/* 276 */ 9999,
/* 277 */ 99023,
/* 278 */ 9999,
/* 279 */ 99036,
/* 280 */ 9999,
/* 281 */ 99042,
/* 282 */ 9999,
/* 283 */ 99065,
/* 284 */ 9999,
/* 285 */ 9999,
/* 286 */ 99065,
/* 287 */ 9999,
/* 288 */ 103004,
/* 289 */ 103036,
/* 290 */ 9999,
/* 291 */ 103004,
/* 292 */ 9999,
/* 293 */ 103006,
/* 294 */ 9999,
/* 295 */ 9999,
/* 296 */ 103027,
/* 297 */ 9999,
/* 298 */ 9999,
/* 299 */ 103027,
/* 300 */ 9999,
/* 301 */ 107004,
/* 302 */ 9999,
/* 303 */ 107013,
/* 304 */ 9999,
/* 305 */ 108004,
/* 306 */ 9999,
/* 307 */ 108024,
/* 308 */ 9999,
/* 309 */ 108004,
/* 310 */ 9999,
/* 311 */ 108006,
/* 312 */ 9999,
/* 313 */ 108015,
/* 314 */ 9999,
/* 315 */ 9999,
/* 316 */ 108015,
/* 317 */ 9999,
/* 318 */ 9999,
/* 319 */ 112009,
/* 320 */ 9999,
/* 321 */ 112024,
/* 322 */ 9999,
/* 323 */ 9999,
/* 324 */ 112007,
/* 325 */ 9999,
/* 326 */ 9999,
/* 327 */ 113009,
/* 328 */ 9999,
/* 329 */ 113007,
/* 330 */ 9999,
/* 331 */ 112011,
/* 332 */ 9999,
/* 333 */ 112012,
/* 334 */ 9999,
/* 335 */ 9999,
/* 336 */ 112012,
/* 337 */ 9999,
/* 338 */ 117004,
/* 339 */ 117029,
/* 340 */ 9999,
/* 341 */ 117004,
/* 342 */ 9999,
/* 343 */ 117006,
/* 344 */ 9999,
/* 345 */ 9999,
/* 346 */ 117020,
/* 347 */ 9999,
/* 348 */ 9999,
/* 349 */ 117020,
/* 350 */ 9999,
/* 351 */ 121004,
/* 352 */ 121010,
/* 353 */ 9999,
/* 354 */ 121005,
/* 355 */ 9999,
/* 356 */ 9999,
/* 357 */ 121016,
/* 358 */ 9999,
/* 359 */ 121012,
/* 360 */ 9999,
/* 361 */ 9999,
/* 362 */ 121012,
/* 363 */ 9999,
/* 364 */ 125004,
/* 365 */ 125017,
/* 366 */ 9999,
/* 367 */ 125004,
/* 368 */ 9999,
/* 369 */ 125006,
/* 370 */ 9999,
/* 371 */ 125012,
/* 372 */ 9999,
/* 373 */ 9999,
/* 374 */ 125012,
/* 375 */ 9999,
/* 376 */ 129004,
/* 377 */ 9999,
/* 378 */ 129005,
/* 379 */ 9999,
/* 380 */ 9999,
/* 381 */ 130008,
/* 382 */ 9999,
/* 383 */ 9999,
/* 384 */ 130004,
/* 385 */ 9999,
/* 386 */ 131004,
/* 387 */ 131022,
/* 388 */ 9999,
/* 389 */ 131020,
/* 390 */ 9999,
/* 391 */ 9999,
/* 392 */ 131028,
/* 393 */ 9999,
/* 394 */ 9999,
/* 395 */ 131024,
/* 396 */ 9999,
/* 397 */ 9999,
/* 398 */ 132009,
/* 399 */ 9999,
/* 400 */ 9999,
/* 401 */ 132005,
/* 402 */ 9999,
/* 403 */ 9999,
/* 404 */ 133009,
/* 405 */ 9999,
/* 406 */ 9999,
/* 407 */ 133005,
/* 408 */ 9999,
/* 409 */ 131030,
/* 410 */ 9999,
/* 411 */ 131039,
/* 412 */ 9999,
/* 413 */ 9999,
/* 414 */ 131039,
/* 415 */ 9999,
/* 416 */ 133011,
/* 417 */ 9999,
/* 418 */ 133025,
/* 419 */ 9999,
/* 420 */ 9999,
/* 421 */ 133025,
/* 422 */ 9999,
/* 423 */ 9999,
/* 424 */ 137008,
/* 425 */ 137033,
/* 426 */ 9999,
/* 427 */ 137004,
/* 428 */ 9999,
/* 429 */ 137010,
/* 430 */ 9999,
/* 431 */ 137028,
/* 432 */ 9999,
/* 433 */ 9999,
/* 434 */ 137028,
/* 435 */ 9999,
/* 436 */ 137035,
/* 437 */ 9999,
/* 438 */ 137041,
/* 439 */ 9999,
/* 440 */ 9999,
/* 441 */ 137041,
/* 442 */ 9999,
/* 443 */ 141004,
/* 444 */ 141029,
/* 445 */ 9999,
/* 446 */ 141004,
/* 447 */ 9999,
/* 448 */ 141006,
/* 449 */ 9999,
/* 450 */ 141024,
/* 451 */ 9999,
/* 452 */ 9999,
/* 453 */ 141024,
/* 454 */ 9999,
/* 455 */ 145004,
/* 456 */ 145019,
/* 457 */ 9999,
/* 458 */ 145017,
/* 459 */ 9999,
/* 460 */ 9999,
/* 461 */ 9999,
/* 462 */ 9999,
/* 463 */ 145021,
/* 464 */ 9999,
/* 465 */ 9999,
/* 466 */ 145021,
/* 467 */ 9999,
/* 468 */ 149004,
/* 469 */ 149028,
/* 470 */ 9999,
/* 471 */ 149004,
/* 472 */ 9999,
/* 473 */ 149006,
/* 474 */ 9999,
/* 475 */ 9999,
/* 476 */ 149019,
/* 477 */ 9999,
/* 478 */ 9999,
/* 479 */ 149019,
/* 480 */ 9999,
/* 481 */ 153004,
/* 482 */ 153027,
/* 483 */ 9999,
/* 484 */ 153025,
/* 485 */ 9999,
/* 486 */ 153029,
/* 487 */ 9999,
/* 488 */ 153038,
/* 489 */ 9999,
/* 490 */ 153042,
/* 491 */ 9999,
/* 492 */ 153042,
/* 493 */ 9999,
/* 494 */ 153044,
/* 495 */ 9999,
/* 496 */ 153062,
/* 497 */ 9999,
/* 498 */ 9999,
/* 499 */ 153062,
/* 500 */ 9999,
/* 501 */ 157004,
/* 502 */ 157029,
/* 503 */ 9999,
/* 504 */ 157004,
/* 505 */ 9999,
/* 506 */ 157006,
/* 507 */ 9999,
/* 508 */ 9999,
/* 509 */ 157020,
/* 510 */ 9999,
/* 511 */ 9999,
/* 512 */ 157020,
/* 513 */ 9999,
/* 514 */ 161004,
/* 515 */ 9999,
/* 516 */ 161024,
/* 517 */ 9999,
/* 518 */ 9999,
/* 519 */ 162008,
/* 520 */ 162025,
/* 521 */ 9999,
/* 522 */ 9999,
/* 523 */ 162004,
/* 524 */ 9999,
/* 525 */ 9999,
/* 526 */ 9999,
/* 527 */ 162027,
/* 528 */ 9999,
/* 529 */ 9999,
/* 530 */ 162027,
/* 531 */ 9999,
/* 532 */ 166004,
/* 533 */ 166030,
/* 534 */ 9999,
/* 535 */ 166004,
/* 536 */ 9999,
/* 537 */ 166006,
/* 538 */ 9999,
/* 539 */ 9999,
/* 540 */ 166021,
/* 541 */ 9999,
/* 542 */ 9999,
/* 543 */ 166021,
/* 544 */ 9999,
/* 545 */ 170004,
/* 546 */ 170029,
/* 547 */ 9999,
/* 548 */ 170027,
/* 549 */ 9999,
/* 550 */ 170031,
/* 551 */ 9999,
/* 552 */ 170049,
/* 553 */ 9999,
/* 554 */ 9999,
/* 555 */ 170049,
/* 556 */ 9999,
/* 557 */ 174004,
/* 558 */ 9999,
/* 559 */ 174010,
/* 560 */ 9999,
/* 561 */ 175004,
/* 562 */ 175017,
/* 563 */ 9999,
/* 564 */ 175004,
/* 565 */ 9999,
/* 566 */ 175006,
/* 567 */ 9999,
/* 568 */ 175012,
/* 569 */ 9999,
/* 570 */ 9999,
/* 571 */ 175012,
/* 572 */ 9999,
/* 573 */ 9999,
/* 574 */ 179008,
/* 575 */ 9999,
/* 576 */ 9999,
/* 577 */ 179004,
/* 578 */ 9999,
/* 579 */ 180004,
/* 580 */ 180036,
/* 581 */ 9999,
/* 582 */ 180004,
/* 583 */ 9999,
/* 584 */ 180006,
/* 585 */ 9999,
/* 586 */ 180031,
/* 587 */ 9999,
/* 588 */ 9999,
/* 589 */ 180031,
/* 590 */ 9999,
/* 591 */ 9999,
/* 592 */ 180042,
/* 593 */ 9999,
/* 594 */ 9999,
/* 595 */ 180038,
/* 596 */ 9999,
/* 597 */ 9999,
/* 598 */ 181009,
/* 599 */ 9999,
/* 600 */ 9999,
/* 601 */ 181005,
/* 602 */ 9999,
/* 603 */ 180044,
/* 604 */ 9999,
/* 605 */ 180053,
/* 606 */ 9999,
/* 607 */ 9999,
/* 608 */ 180053,
/* 609 */ 9999,
/* 610 */ 181011,
/* 611 */ 9999,
/* 612 */ 181029,
/* 613 */ 9999,
/* 614 */ 9999,
/* 615 */ 181029,
/* 616 */ 9999,
/* 617 */ 185004,
/* 618 */ 9999,
/* 619 */ 185005,
/* 620 */ 9999,
/* 621 */ 189004,
/* 622 */ 9999,
/* 623 */ 189020,
/* 624 */ 9999,
/* 625 */ 190004,
/* 626 */ 9999,
/* 627 */ 190023,
/* 628 */ 9999,
/* 629 */ 191004,
/* 630 */ 9999,
/* 631 */ 191021,
/* 632 */ 9999,
/* 633 */ 192004,
/* 634 */ 9999,
/* 635 */ 192022,
/* 636 */ 9999,
/* 637 */ 193004,
/* 638 */ 9999,
/* 639 */ 193022,
/* 640 */ 9999,
/* 641 */ 194004,
/* 642 */ 9999,
/* 643 */ 194017,
/* 644 */ 9999,
/* 645 */ 195004,
/* 646 */ 9999,
/* 647 */ 195018,
/* 648 */ 9999,
/* 649 */ 196004,
/* 650 */ 9999,
/* 651 */ 196018,
/* 652 */ 9999,
/* 653 */ 200004,
/* 654 */ 9999,
/* 655 */ 200014,
/* 656 */ 9999,
/* 657 */ 200005,
/* 658 */ 9999,
/* 659 */ 9999,
/* 660 */ 201009,
/* 661 */ 9999,
/* 662 */ 201037,
/* 663 */ 9999,
/* 664 */ 201007,
/* 665 */ 9999,
/* 666 */ 9999,
/* 667 */ 9999,
/* 668 */ 202016,
/* 669 */ 9999,
/* 670 */ 202010,
/* 671 */ 9999,
/* 672 */ 206004,
/* 673 */ 9999,
/* 674 */ 9999,
/* 675 */ 206004,
/* 676 */ 9999,
/* 677 */ 206006,
/* 678 */ 9999,
/* 679 */ 206015,
/* 680 */ 9999,
/* 681 */ 9999,
/* 682 */ 206015,
/* 683 */ 9999,
/* 684 */ 9999,
/* 685 */ 210008,
/* 686 */ 210030,
/* 687 */ 9999,
/* 688 */ 9999,
/* 689 */ 210004,
/* 690 */ 9999,
/* 691 */ 210010,
/* 692 */ 9999,
/* 693 */ 210025,
/* 694 */ 9999,
/* 695 */ 9999,
/* 696 */ 210025,
/* 697 */ 9999,
/* 698 */ 210032,
/* 699 */ 9999,
/* 700 */ 210045,
/* 701 */ 9999,
/* 702 */ 9999,
/* 703 */ 210045,
/* 704 */ 9999,
/* 705 */ 219004,
/* 706 */ 219019,
/* 707 */ 9999,
/* 708 */ 219004,
/* 709 */ 9999,
/* 710 */ 219006,
/* 711 */ 219014,
/* 712 */ 9999,
/* 713 */ 219014,
/* 714 */ 9999,
/* 715 */ 9999,
/* 716 */ 219014,
/* 717 */ 9999,
/* 718 */ 9999,
/* 719 */ 9999,
/* 720 */ 223011,
/* 721 */ 9999,
/* 722 */ 223029,
/* 723 */ 223039,
/* 724 */ 9999,
/* 725 */ 223005,
/* 726 */ 9999,
/* 727 */ 9999,
/* 728 */ 9999,
/* 729 */ 224015,
/* 730 */ 9999,
/* 731 */ 224033,
/* 732 */ 9999,
/* 733 */ 224009,
/* 734 */ 9999,
/* 735 */ 9999,
/* 736 */ 223046,
/* 737 */ 9999,
/* 738 */ 223044,
/* 739 */ 9999,
/* 740 */ 9999,
/* 741 */ 223044,
/* 742 */ 9999,
/* 743 */ 9999,
/* 744 */ 9999,
/* 745 */ 228014,
/* 746 */ 9999,
/* 747 */ 228032,
/* 748 */ 9999,
/* 749 */ 228008,
/* 750 */ 9999,
/* 751 */ 9999,
/* 752 */ 229007,
/* 753 */ 9999,
/* 754 */ 9999,
/* 755 */ 229027,
/* 756 */ 9999,
/* 757 */ 9999,
/* 758 */ 9999,
/* 759 */ 229005,
/* 760 */ 9999,
/* 761 */ 9999,
/* 762 */ 9999,
/* 763 */ 230012,
/* 764 */ 9999,
/* 765 */ 230035,
/* 766 */ 9999,
/* 767 */ 230058,
/* 768 */ 9999,
/* 769 */ 230081,
/* 770 */ 9999,
/* 771 */ 230006,
/* 772 */ 9999,
/* 773 */ 230014,
/* 774 */ 9999,
/* 775 */ 230023,
/* 776 */ 9999,
/* 777 */ 9999,
/* 778 */ 230023,
/* 779 */ 9999,
/* 780 */ 230037,
/* 781 */ 9999,
/* 782 */ 230046,
/* 783 */ 9999,
/* 784 */ 9999,
/* 785 */ 230046,
/* 786 */ 9999,
/* 787 */ 230060,
/* 788 */ 9999,
/* 789 */ 230069,
/* 790 */ 9999,
/* 791 */ 9999,
/* 792 */ 230069,
/* 793 */ 9999,
/* 794 */ 9999,
/* 795 */ 234009,
/* 796 */ 9999,
/* 797 */ 9999,
/* 798 */ 234007,
/* 799 */ 9999,
/* 800 */ 9999,
/* 801 */ 9999,
/* 802 */ 9999,
/* 803 */ 235011,
/* 804 */ 9999,
/* 805 */ 9999,
/* 806 */ 9999,
/* 807 */ 9999,
/* 808 */ 236008,
/* 809 */ 9999,
/* 810 */ 9999,
/* 811 */ 237011,
/* 812 */ 9999,
/* 813 */ 9999,
/* 814 */ 237009,
/* 815 */ 9999,
/* 816 */ 237013,
/* 817 */ 9999,
/* 818 */ 237022,
/* 819 */ 9999,
/* 820 */ 9999,
/* 821 */ 237022,
/* 822 */ 9999,
/* 823 */ 9999,
/* 824 */ 241010,
/* 825 */ 9999,
/* 826 */ 9999,
/* 827 */ 241008,
/* 828 */ 9999,
/* 829 */ 9999,
/* 830 */ 245010,
/* 831 */ 245025,
/* 832 */ 9999,
/* 833 */ 9999,
/* 834 */ 245008,
/* 835 */ 9999,
/* 836 */ 245012,
/* 837 */ 9999,
/* 838 */ 245013,
/* 839 */ 9999,
/* 840 */ 245013,
/* 841 */ 9999,
/* 842 */ 9999,
/* 843 */ 245013,
/* 844 */ 9999,
/* 845 */ 249004,
/* 846 */ 9999,
/* 847 */ 249024,
/* 848 */ 9999,
/* 849 */ 250004,
/* 850 */ 9999,
/* 851 */ 250022,
/* 852 */ 9999,
/* 853 */ 250013,
/* 854 */ 9999,
/* 855 */ 254004,
/* 856 */ 9999,
/* 857 */ 254025,
/* 858 */ 9999,
/* 859 */ 255004,
/* 860 */ 255025,
/* 861 */ 255049,
/* 862 */ 9999,
/* 863 */ 255019,
/* 864 */ 9999,
/* 865 */ 9999,
/* 866 */ 9999,
/* 867 */ 259009,
/* 868 */ 9999,
/* 869 */ 9999,
/* 870 */ 9999,
/* 871 */ 260004,
/* 872 */ 9999,
/* 873 */ 264004,
/* 874 */ 9999,
/* 875 */ 264024,
/* 876 */ 9999,
/* 877 */ 265004,
/* 878 */ 9999,
/* 879 */ 265035,
/* 880 */ 9999,
/* 881 */ 265053,
/* 882 */ 9999,
/* 883 */ 265024,
/* 884 */ 9999,
/* 885 */ 269004,
/* 886 */ 9999,
/* 887 */ 269025,
/* 888 */ 9999,
/* 889 */ 273004,
/* 890 */ 9999,
/* 891 */ 273025,
/* 892 */ 9999,
/* 893 */ 274004,
/* 894 */ 9999,
/* 895 */ 274042,
/* 896 */ 9999,
/* 897 */ 274024,
/* 898 */ 9999,
/* 899 */ 278004,
/* 900 */ 9999,
/* 901 */ 278026,
/* 902 */ 9999,
/* 903 */ 279004,
/* 904 */ 9999,
/* 905 */ 279044,
/* 906 */ 9999,
/* 907 */ 279025,
/* 908 */ 9999,
/* 909 */ 283004,
/* 910 */ 9999,
/* 911 */ 283026,
/* 912 */ 9999,
/* 913 */ 284004,
/* 914 */ 9999,
/* 915 */ 284037,
/* 916 */ 9999,
/* 917 */ 284026,
/* 918 */ 9999,
/* 919 */ 288004,
/* 920 */ 9999,
/* 921 */ 288017,
/* 922 */ 9999,
/* 923 */ 289004,
/* 924 */ 9999,
/* 925 */ 289037,
/* 926 */ 9999,
/* 927 */ 289026,
/* 928 */ 9999,
/* 929 */ 293004,
/* 930 */ 9999,
/* 931 */ 293022,
/* 932 */ 9999,
/* 933 */ 294004,
/* 934 */ 9999,
/* 935 */ 294027,
/* 936 */ 9999,
/* 937 */ 294017,
/* 938 */ 9999,
/* 939 */ 298004,
/* 940 */ 9999,
/* 941 */ 298019,
/* 942 */ 9999,
/* 943 */ 299004,
/* 944 */ 9999,
/* 945 */ 299039,
/* 946 */ 9999,
/* 947 */ 299022,
/* 948 */ 9999,
/* 949 */ 303004,
/* 950 */ 9999,
/* 951 */ 303022,
/* 952 */ 9999,
/* 953 */ 304004,
/* 954 */ 9999,
/* 955 */ 304034,
/* 956 */ 9999,
/* 957 */ 304019,
/* 958 */ 9999,
/* 959 */ 308004,
/* 960 */ 9999,
/* 961 */ 308028,
/* 962 */ 9999,
/* 963 */ 309022,
/* 964 */ 309046,
/* 965 */ 309074,
/* 966 */ 9999,
/* 967 */ 309004,
/* 968 */ 9999,
/* 969 */ 9999,
/* 970 */ 9999,
/* 971 */ 309048,
/* 972 */ 9999,
/* 973 */ 9999,
/* 974 */ 9999,
/* 975 */ 309054,
/* 976 */ 9999,
/* 977 */ 313004,
/* 978 */ 9999,
/* 979 */ 313018,
/* 980 */ 9999,
/* 981 */ 314022,
/* 982 */ 314052,
/* 983 */ 314099,
/* 984 */ 9999,
/* 985 */ 314004,
/* 986 */ 9999,
/* 987 */ 9999,
/* 988 */ 9999,
/* 989 */ 314054,
/* 990 */ 9999,
/* 991 */ 9999,
/* 992 */ 9999,
/* 993 */ 314060,
/* 994 */ 9999,
/* 995 */ 9999,
/* 996 */ 9999,
/* 997 */ 314080,
/* 998 */ 9999,
/* 999 */ 318004,
/* 1000 */ 9999,
/* 1001 */ 318019,
/* 1002 */ 9999,
/* 1003 */ 9999,
/* 1004 */ 319008,
/* 1005 */ 9999,
/* 1006 */ 319022,
/* 1007 */ 9999,
/* 1008 */ 319004,
/* 1009 */ 9999,
/* 1010 */ 323004,
/* 1011 */ 9999,
/* 1012 */ 323021,
/* 1013 */ 9999,
/* 1014 */ 324015,
/* 1015 */ 324062,
/* 1016 */ 9999,
/* 1017 */ 324004,
/* 1018 */ 9999,
/* 1019 */ 325004,
/* 1020 */ 325023,
/* 1021 */ 9999,
/* 1022 */ 325017,
/* 1023 */ 9999,
/* 1024 */ 9999,
/* 1025 */ 326011,
/* 1026 */ 9999,
/* 1027 */ 326009,
/* 1028 */ 9999,
/* 1029 */ 9999,
/* 1030 */ 9999,
/* 1031 */ 327015,
/* 1032 */ 9999,
/* 1033 */ 9999,
/* 1034 */ 327009,
/* 1035 */ 9999,
/* 1036 */ 9999,
/* 1037 */ 9999,
/* 1038 */ 324022,
/* 1039 */ 9999,
/* 1040 */ 9999,
/* 1041 */ 9999,
/* 1042 */ 324044,
/* 1043 */ 9999,
/* 1044 */ 9999,
/* 1045 */ 9999,
/* 1046 */ 331004,
/* 1047 */ 9999,
/* 1048 */ 9999,
/* 1049 */ 9999,
/* 1050 */ 332004,
/* 1051 */ 9999,
/* 1052 */ 9999,
/* 1053 */ 9999,
/* 1054 */ 333004,
/* 1055 */ 9999,
/* 1056 */ 9999,
/* 1057 */ 9999,
/* 1058 */ 334004,
/* 1059 */ 9999,
/* 1060 */ 9999,
/* 1061 */ 9999,
/* 1062 */ 335004,
/* 1063 */ 9999,
/* 1064 */ 9999,
/* 1065 */ 9999,
/* 1066 */ 336004,
/* 1067 */ 9999,
/* 1068 */ 340004,
/* 1069 */ 9999,
/* 1070 */ 340021,
/* 1071 */ 9999,
/* 1072 */ 341004,
/* 1073 */ 342003,
/* 1074 */ 9999,
/* 1075 */ 341021,
/* 1076 */ 9999,
/* 1077 */ 9999,
/* 1078 */ 342009,
/* 1079 */ 342054,
/* 1080 */ 9999,
/* 1081 */ 9999,
/* 1082 */ 342005,
/* 1083 */ 9999,
/* 1084 */ 9999,
/* 1085 */ 343009,
/* 1086 */ 9999,
/* 1087 */ 9999,
/* 1088 */ 343005,
/* 1089 */ 9999,
/* 1090 */ 9999,
/* 1091 */ 344009,
/* 1092 */ 9999,
/* 1093 */ 344005,
/* 1094 */ 9999,
/* 1095 */ 9999,
/* 1096 */ 345012,
/* 1097 */ 9999,
/* 1098 */ 345010,
/* 1099 */ 9999,
/* 1100 */ 9999,
/* 1101 */ 9999,
/* 1102 */ 346010,
/* 1103 */ 9999,
/* 1104 */ 9999,
/* 1105 */ 9999,
/* 1106 */ 347010,
/* 1107 */ 9999,
/* 1108 */ 9999,
/* 1109 */ 342060,
/* 1110 */ 9999,
/* 1111 */ 342056,
/* 1112 */ 9999,
/* 1113 */ 9999,
/* 1114 */ 342056,
/* 1115 */ 9999,
/* 1116 */ 343011,
/* 1117 */ 9999,
/* 1118 */ 343034,
/* 1119 */ 9999,
/* 1120 */ 9999,
/* 1121 */ 343034,
/* 1122 */ 9999,
/* 1123 */ 352004,
/* 1124 */ 9999,
/* 1125 */ 352005,
/* 1126 */ 9999,
/* 1127 */ 353004,
/* 1128 */ 9999,
/* 1129 */ 353011,
/* 1130 */ 9999,
/* 1131 */ 9999,
/* 1132 */ 354008,
/* 1133 */ 9999,
/* 1134 */ 9999,
/* 1135 */ 354004,
/* 1136 */ 9999,
/* 1137 */ 358044,
/* 1138 */ 358111,
/* 1139 */ 9999,
/* 1140 */ 358004,
/* 1141 */ 9999,
/* 1142 */ 358046,
/* 1143 */ 9999,
/* 1144 */ 358066,
/* 1145 */ 9999,
/* 1146 */ 358066,
/* 1147 */ 9999,
/* 1148 */ 9999,
/* 1149 */ 358066,
/* 1150 */ 9999,
/* 1151 */ 9999,
/* 1152 */ 9999,
/* 1153 */ 362011,
/* 1154 */ 9999,
/* 1155 */ 9999,
/* 1156 */ 9999,
/* 1157 */ 363012,
/* 1158 */ 9999,
/* 1159 */ 9999,
/* 1160 */ 9999,
/* 1161 */ 364013,
/* 1162 */ 9999,
/* 1163 */ 9999,
/* 1164 */ 9999,
/* 1165 */ 365009,
/* 1166 */ 9999,
/* 1167 */ 9999,
/* 1168 */ 9999,
/* 1169 */ 370013,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[1171];
*/
int TABLE[261][308];
init_dirsets() {
TABLE[124][0] = 1;
TABLE[124][59] = 1;
TABLE[124][123] = 1;
TABLE[124][40] = 1;
TABLE[124][42] = 1;
TABLE[124][299] = 1;
TABLE[124][44] = 1;
TABLE[124][61] = 1;
TABLE[124][286] = 1;
TABLE[124][260] = 1;
TABLE[124][284] = 1;
TABLE[124][277] = 1;
TABLE[124][264] = 1;
TABLE[124][268] = 1;
TABLE[124][273] = 1;
TABLE[124][272] = 1;
TABLE[124][276] = 1;
TABLE[124][259] = 1;
TABLE[124][285] = 1;
TABLE[124][266] = 1;
TABLE[124][282] = 1;
TABLE[124][267] = 1;
TABLE[124][279] = 1;
TABLE[124][274] = 1;
TABLE[124][256] = 1;
TABLE[124][278] = 1;
TABLE[124][283] = 1;
TABLE[124][280] = 1;
TABLE[124][38] = 1;
TABLE[124][43] = 1;
TABLE[124][45] = 1;
TABLE[124][126] = 1;
TABLE[124][33] = 1;
TABLE[124][294] = 1;
TABLE[124][295] = 1;
TABLE[124][304] = 1;
TABLE[124][302] = 1;
TABLE[124][303] = 1;
TABLE[124][289] = 1;
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
TABLE[1][33] = 1;
TABLE[1][126] = 1;
TABLE[1][45] = 1;
TABLE[1][43] = 1;
TABLE[1][38] = 1;
TABLE[1][289] = 1;
TABLE[1][303] = 1;
TABLE[1][302] = 1;
TABLE[1][304] = 1;
TABLE[125][0] = 1;
TABLE[125][59] = 1;
TABLE[125][123] = 1;
TABLE[125][40] = 1;
TABLE[125][42] = 1;
TABLE[125][299] = 1;
TABLE[125][44] = 1;
TABLE[125][61] = 1;
TABLE[125][286] = 1;
TABLE[125][260] = 1;
TABLE[125][284] = 1;
TABLE[125][277] = 1;
TABLE[125][264] = 1;
TABLE[125][268] = 1;
TABLE[125][273] = 1;
TABLE[125][272] = 1;
TABLE[125][276] = 1;
TABLE[125][259] = 1;
TABLE[125][285] = 1;
TABLE[125][266] = 1;
TABLE[125][282] = 1;
TABLE[125][267] = 1;
TABLE[125][279] = 1;
TABLE[125][274] = 1;
TABLE[125][256] = 1;
TABLE[125][278] = 1;
TABLE[125][283] = 1;
TABLE[125][280] = 1;
TABLE[125][38] = 1;
TABLE[125][43] = 1;
TABLE[125][45] = 1;
TABLE[125][126] = 1;
TABLE[125][33] = 1;
TABLE[125][294] = 1;
TABLE[125][295] = 1;
TABLE[125][304] = 1;
TABLE[125][302] = 1;
TABLE[125][303] = 1;
TABLE[125][289] = 1;
TABLE[215][0] = 1;
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
TABLE[2][38] = 1;
TABLE[2][43] = 1;
TABLE[2][45] = 1;
TABLE[2][126] = 1;
TABLE[2][33] = 1;
TABLE[2][294] = 1;
TABLE[2][295] = 1;
TABLE[2][304] = 1;
TABLE[2][302] = 1;
TABLE[2][303] = 1;
TABLE[2][289] = 1;
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
TABLE[3][33] = 1;
TABLE[3][126] = 1;
TABLE[3][45] = 1;
TABLE[3][43] = 1;
TABLE[3][38] = 1;
TABLE[3][42] = 1;
TABLE[3][289] = 1;
TABLE[3][303] = 1;
TABLE[3][302] = 1;
TABLE[3][304] = 1;
TABLE[4][59] = 1;
TABLE[4][44] = 1;
TABLE[4][123] = 1;
TABLE[4][61] = 1;
TABLE[4][278] = 1;
TABLE[4][295] = 1;
TABLE[4][294] = 1;
TABLE[4][33] = 1;
TABLE[4][126] = 1;
TABLE[4][45] = 1;
TABLE[4][43] = 1;
TABLE[4][38] = 1;
TABLE[4][289] = 1;
TABLE[4][303] = 1;
TABLE[4][302] = 1;
TABLE[4][304] = 1;
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
TABLE[126][44] = 1;
TABLE[126][61] = 1;
TABLE[126][278] = 1;
TABLE[126][40] = 1;
TABLE[126][295] = 1;
TABLE[126][294] = 1;
TABLE[126][33] = 1;
TABLE[126][126] = 1;
TABLE[126][45] = 1;
TABLE[126][43] = 1;
TABLE[126][38] = 1;
TABLE[126][42] = 1;
TABLE[126][289] = 1;
TABLE[126][303] = 1;
TABLE[126][302] = 1;
TABLE[126][304] = 1;
TABLE[126][59] = 1;
TABLE[126][123] = 1;
TABLE[126][286] = 1;
TABLE[126][260] = 1;
TABLE[126][284] = 1;
TABLE[126][277] = 1;
TABLE[126][264] = 1;
TABLE[126][268] = 1;
TABLE[126][273] = 1;
TABLE[126][272] = 1;
TABLE[126][276] = 1;
TABLE[126][259] = 1;
TABLE[126][285] = 1;
TABLE[126][266] = 1;
TABLE[126][299] = 1;
TABLE[126][282] = 1;
TABLE[126][267] = 1;
TABLE[126][279] = 1;
TABLE[126][274] = 1;
TABLE[126][256] = 1;
TABLE[126][283] = 1;
TABLE[126][280] = 1;
TABLE[216][44] = 1;
TABLE[216][256] = 1;
TABLE[216][274] = 1;
TABLE[216][279] = 1;
TABLE[216][267] = 1;
TABLE[216][282] = 1;
TABLE[216][299] = 1;
TABLE[216][266] = 1;
TABLE[216][285] = 1;
TABLE[216][259] = 1;
TABLE[216][276] = 1;
TABLE[216][272] = 1;
TABLE[216][273] = 1;
TABLE[216][268] = 1;
TABLE[216][264] = 1;
TABLE[216][277] = 1;
TABLE[216][284] = 1;
TABLE[216][260] = 1;
TABLE[216][286] = 1;
TABLE[216][61] = 1;
TABLE[216][280] = 1;
TABLE[216][283] = 1;
TABLE[216][278] = 1;
TABLE[216][40] = 1;
TABLE[216][295] = 1;
TABLE[216][294] = 1;
TABLE[216][33] = 1;
TABLE[216][126] = 1;
TABLE[216][45] = 1;
TABLE[216][43] = 1;
TABLE[216][38] = 1;
TABLE[216][42] = 1;
TABLE[216][289] = 1;
TABLE[216][303] = 1;
TABLE[216][302] = 1;
TABLE[216][304] = 1;
TABLE[216][59] = 1;
TABLE[216][123] = 1;
TABLE[127][59] = 1;
TABLE[127][44] = 1;
TABLE[127][61] = 1;
TABLE[127][123] = 1;
TABLE[127][286] = 1;
TABLE[127][260] = 1;
TABLE[127][284] = 1;
TABLE[127][277] = 1;
TABLE[127][264] = 1;
TABLE[127][268] = 1;
TABLE[127][273] = 1;
TABLE[127][272] = 1;
TABLE[127][276] = 1;
TABLE[127][259] = 1;
TABLE[127][285] = 1;
TABLE[127][266] = 1;
TABLE[127][299] = 1;
TABLE[127][282] = 1;
TABLE[127][267] = 1;
TABLE[127][279] = 1;
TABLE[127][274] = 1;
TABLE[127][256] = 1;
TABLE[127][40] = 1;
TABLE[127][278] = 1;
TABLE[127][283] = 1;
TABLE[127][280] = 1;
TABLE[127][42] = 1;
TABLE[127][38] = 1;
TABLE[127][43] = 1;
TABLE[127][45] = 1;
TABLE[127][126] = 1;
TABLE[127][33] = 1;
TABLE[127][294] = 1;
TABLE[127][295] = 1;
TABLE[127][304] = 1;
TABLE[127][302] = 1;
TABLE[127][303] = 1;
TABLE[127][289] = 1;
TABLE[217][59] = 1;
TABLE[217][123] = 1;
TABLE[128][59] = 1;
TABLE[129][123] = 1;
TABLE[5][59] = 1;
TABLE[5][44] = 1;
TABLE[5][61] = 1;
TABLE[5][123] = 1;
TABLE[5][40] = 1;
TABLE[5][278] = 1;
TABLE[5][42] = 1;
TABLE[5][38] = 1;
TABLE[5][43] = 1;
TABLE[5][45] = 1;
TABLE[5][126] = 1;
TABLE[5][33] = 1;
TABLE[5][294] = 1;
TABLE[5][295] = 1;
TABLE[5][304] = 1;
TABLE[5][302] = 1;
TABLE[5][303] = 1;
TABLE[5][289] = 1;
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
TABLE[130][59] = 1;
TABLE[130][44] = 1;
TABLE[130][123] = 1;
TABLE[130][61] = 1;
TABLE[130][278] = 1;
TABLE[130][40] = 1;
TABLE[130][295] = 1;
TABLE[130][294] = 1;
TABLE[130][33] = 1;
TABLE[130][126] = 1;
TABLE[130][45] = 1;
TABLE[130][43] = 1;
TABLE[130][38] = 1;
TABLE[130][299] = 1;
TABLE[130][42] = 1;
TABLE[130][289] = 1;
TABLE[130][303] = 1;
TABLE[130][302] = 1;
TABLE[130][304] = 1;
TABLE[218][59] = 1;
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
TABLE[6][40] = 1;
TABLE[6][295] = 1;
TABLE[6][294] = 1;
TABLE[6][33] = 1;
TABLE[6][126] = 1;
TABLE[6][45] = 1;
TABLE[6][43] = 1;
TABLE[6][38] = 1;
TABLE[6][42] = 1;
TABLE[6][289] = 1;
TABLE[6][303] = 1;
TABLE[6][302] = 1;
TABLE[6][304] = 1;
TABLE[131][262] = 1;
TABLE[131][258] = 1;
TABLE[131][281] = 1;
TABLE[131][271] = 1;
TABLE[131][269] = 1;
TABLE[131][263] = 1;
TABLE[131][287] = 1;
TABLE[131][275] = 1;
TABLE[131][257] = 1;
TABLE[131][261] = 1;
TABLE[131][270] = 1;
TABLE[131][305] = 1;
TABLE[131][306] = 1;
TABLE[131][125] = 1;
TABLE[131][59] = 1;
TABLE[131][44] = 1;
TABLE[131][256] = 1;
TABLE[131][274] = 1;
TABLE[131][279] = 1;
TABLE[131][267] = 1;
TABLE[131][282] = 1;
TABLE[131][299] = 1;
TABLE[131][266] = 1;
TABLE[131][285] = 1;
TABLE[131][259] = 1;
TABLE[131][276] = 1;
TABLE[131][272] = 1;
TABLE[131][273] = 1;
TABLE[131][268] = 1;
TABLE[131][264] = 1;
TABLE[131][277] = 1;
TABLE[131][284] = 1;
TABLE[131][260] = 1;
TABLE[131][286] = 1;
TABLE[131][123] = 1;
TABLE[131][61] = 1;
TABLE[131][280] = 1;
TABLE[131][283] = 1;
TABLE[131][278] = 1;
TABLE[131][40] = 1;
TABLE[131][295] = 1;
TABLE[131][294] = 1;
TABLE[131][33] = 1;
TABLE[131][126] = 1;
TABLE[131][45] = 1;
TABLE[131][43] = 1;
TABLE[131][38] = 1;
TABLE[131][42] = 1;
TABLE[131][289] = 1;
TABLE[131][303] = 1;
TABLE[131][302] = 1;
TABLE[131][304] = 1;
TABLE[219][59] = 1;
TABLE[219][123] = 1;
TABLE[219][262] = 1;
TABLE[219][258] = 1;
TABLE[219][281] = 1;
TABLE[219][271] = 1;
TABLE[219][269] = 1;
TABLE[219][263] = 1;
TABLE[219][287] = 1;
TABLE[219][275] = 1;
TABLE[219][257] = 1;
TABLE[219][261] = 1;
TABLE[219][270] = 1;
TABLE[219][305] = 1;
TABLE[219][306] = 1;
TABLE[219][299] = 1;
TABLE[219][278] = 1;
TABLE[219][38] = 1;
TABLE[219][42] = 1;
TABLE[219][43] = 1;
TABLE[219][45] = 1;
TABLE[219][126] = 1;
TABLE[219][33] = 1;
TABLE[219][294] = 1;
TABLE[219][295] = 1;
TABLE[219][40] = 1;
TABLE[219][304] = 1;
TABLE[219][302] = 1;
TABLE[219][303] = 1;
TABLE[219][289] = 1;
TABLE[219][125] = 1;
TABLE[7][44] = 1;
TABLE[7][61] = 1;
TABLE[7][278] = 1;
TABLE[7][40] = 1;
TABLE[7][295] = 1;
TABLE[7][294] = 1;
TABLE[7][33] = 1;
TABLE[7][126] = 1;
TABLE[7][45] = 1;
TABLE[7][43] = 1;
TABLE[7][38] = 1;
TABLE[7][42] = 1;
TABLE[7][289] = 1;
TABLE[7][303] = 1;
TABLE[7][302] = 1;
TABLE[7][304] = 1;
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
TABLE[132][282] = 1;
TABLE[132][267] = 1;
TABLE[132][279] = 1;
TABLE[132][274] = 1;
TABLE[132][256] = 1;
TABLE[133][284] = 1;
TABLE[133][277] = 1;
TABLE[133][264] = 1;
TABLE[133][268] = 1;
TABLE[133][273] = 1;
TABLE[133][272] = 1;
TABLE[133][276] = 1;
TABLE[133][259] = 1;
TABLE[133][285] = 1;
TABLE[133][266] = 1;
TABLE[133][299] = 1;
TABLE[133][283] = 1;
TABLE[133][280] = 1;
TABLE[134][286] = 1;
TABLE[134][260] = 1;
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
TABLE[220][33] = 1;
TABLE[220][126] = 1;
TABLE[220][45] = 1;
TABLE[220][43] = 1;
TABLE[220][38] = 1;
TABLE[220][42] = 1;
TABLE[220][289] = 1;
TABLE[220][303] = 1;
TABLE[220][302] = 1;
TABLE[220][304] = 1;
TABLE[220][59] = 1;
TABLE[220][123] = 1;
TABLE[220][91] = 1;
TABLE[220][41] = 1;
TABLE[8][256] = 1;
TABLE[8][274] = 1;
TABLE[8][279] = 1;
TABLE[8][267] = 1;
TABLE[8][282] = 1;
TABLE[135][256] = 1;
TABLE[136][274] = 1;
TABLE[137][279] = 1;
TABLE[138][267] = 1;
TABLE[139][282] = 1;
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
TABLE[140][285] = 1;
TABLE[141][259] = 1;
TABLE[142][276] = 1;
TABLE[143][272] = 1;
TABLE[144][273] = 1;
TABLE[145][268] = 1;
TABLE[146][264] = 1;
TABLE[147][277] = 1;
TABLE[148][284] = 1;
TABLE[13][260] = 1;
TABLE[13][286] = 1;
TABLE[149][260] = 1;
TABLE[150][286] = 1;
TABLE[14][283] = 1;
TABLE[14][280] = 1;
TABLE[15][283] = 1;
TABLE[15][280] = 1;
TABLE[151][299] = 1;
TABLE[221][123] = 1;
TABLE[16][280] = 1;
TABLE[16][283] = 1;
TABLE[152][280] = 1;
TABLE[153][283] = 1;
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
TABLE[154][286] = 1;
TABLE[154][260] = 1;
TABLE[154][284] = 1;
TABLE[154][277] = 1;
TABLE[154][264] = 1;
TABLE[154][268] = 1;
TABLE[154][273] = 1;
TABLE[154][272] = 1;
TABLE[154][276] = 1;
TABLE[154][259] = 1;
TABLE[154][285] = 1;
TABLE[154][266] = 1;
TABLE[154][299] = 1;
TABLE[154][283] = 1;
TABLE[154][280] = 1;
TABLE[222][299] = 1;
TABLE[222][266] = 1;
TABLE[222][285] = 1;
TABLE[222][259] = 1;
TABLE[222][276] = 1;
TABLE[222][272] = 1;
TABLE[222][273] = 1;
TABLE[222][268] = 1;
TABLE[222][264] = 1;
TABLE[222][277] = 1;
TABLE[222][284] = 1;
TABLE[222][260] = 1;
TABLE[222][286] = 1;
TABLE[222][280] = 1;
TABLE[222][283] = 1;
TABLE[18][59] = 1;
TABLE[18][44] = 1;
TABLE[18][61] = 1;
TABLE[18][123] = 1;
TABLE[18][40] = 1;
TABLE[18][278] = 1;
TABLE[18][42] = 1;
TABLE[18][299] = 1;
TABLE[18][38] = 1;
TABLE[18][43] = 1;
TABLE[18][45] = 1;
TABLE[18][126] = 1;
TABLE[18][33] = 1;
TABLE[18][294] = 1;
TABLE[18][295] = 1;
TABLE[18][304] = 1;
TABLE[18][302] = 1;
TABLE[18][303] = 1;
TABLE[18][289] = 1;
TABLE[155][44] = 1;
TABLE[155][123] = 1;
TABLE[155][61] = 1;
TABLE[155][278] = 1;
TABLE[155][40] = 1;
TABLE[155][295] = 1;
TABLE[155][294] = 1;
TABLE[155][33] = 1;
TABLE[155][126] = 1;
TABLE[155][45] = 1;
TABLE[155][43] = 1;
TABLE[155][38] = 1;
TABLE[155][299] = 1;
TABLE[155][42] = 1;
TABLE[155][289] = 1;
TABLE[155][303] = 1;
TABLE[155][302] = 1;
TABLE[155][304] = 1;
TABLE[223][61] = 1;
TABLE[223][123] = 1;
TABLE[223][40] = 1;
TABLE[223][278] = 1;
TABLE[223][42] = 1;
TABLE[223][299] = 1;
TABLE[223][38] = 1;
TABLE[223][43] = 1;
TABLE[223][45] = 1;
TABLE[223][126] = 1;
TABLE[223][33] = 1;
TABLE[223][294] = 1;
TABLE[223][295] = 1;
TABLE[223][304] = 1;
TABLE[223][302] = 1;
TABLE[223][303] = 1;
TABLE[223][289] = 1;
TABLE[223][59] = 1;
TABLE[223][44] = 1;
TABLE[19][123] = 1;
TABLE[19][278] = 1;
TABLE[19][295] = 1;
TABLE[19][294] = 1;
TABLE[19][33] = 1;
TABLE[19][126] = 1;
TABLE[19][45] = 1;
TABLE[19][43] = 1;
TABLE[19][38] = 1;
TABLE[19][289] = 1;
TABLE[19][303] = 1;
TABLE[19][302] = 1;
TABLE[19][304] = 1;
TABLE[19][61] = 1;
TABLE[19][40] = 1;
TABLE[19][299] = 1;
TABLE[19][42] = 1;
TABLE[156][61] = 1;
TABLE[156][40] = 1;
TABLE[156][42] = 1;
TABLE[156][299] = 1;
TABLE[224][123] = 1;
TABLE[224][278] = 1;
TABLE[224][295] = 1;
TABLE[224][294] = 1;
TABLE[224][33] = 1;
TABLE[224][126] = 1;
TABLE[224][45] = 1;
TABLE[224][43] = 1;
TABLE[224][42] = 1;
TABLE[224][38] = 1;
TABLE[224][40] = 1;
TABLE[224][299] = 1;
TABLE[224][289] = 1;
TABLE[224][303] = 1;
TABLE[224][302] = 1;
TABLE[224][304] = 1;
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
TABLE[157][284] = 1;
TABLE[157][277] = 1;
TABLE[157][264] = 1;
TABLE[157][268] = 1;
TABLE[157][273] = 1;
TABLE[157][272] = 1;
TABLE[157][276] = 1;
TABLE[157][259] = 1;
TABLE[157][285] = 1;
TABLE[157][266] = 1;
TABLE[157][299] = 1;
TABLE[157][283] = 1;
TABLE[157][280] = 1;
TABLE[158][286] = 1;
TABLE[158][260] = 1;
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
TABLE[159][283] = 1;
TABLE[159][280] = 1;
TABLE[225][44] = 1;
TABLE[225][58] = 1;
TABLE[225][40] = 1;
TABLE[225][42] = 1;
TABLE[225][299] = 1;
TABLE[225][59] = 1;
TABLE[225][91] = 1;
TABLE[225][41] = 1;
TABLE[22][59] = 1;
TABLE[22][44] = 1;
TABLE[22][58] = 1;
TABLE[22][40] = 1;
TABLE[22][299] = 1;
TABLE[22][42] = 1;
TABLE[160][44] = 1;
TABLE[160][58] = 1;
TABLE[160][40] = 1;
TABLE[160][42] = 1;
TABLE[160][299] = 1;
TABLE[226][58] = 1;
TABLE[226][40] = 1;
TABLE[226][299] = 1;
TABLE[226][42] = 1;
TABLE[226][59] = 1;
TABLE[226][44] = 1;
TABLE[23][59] = 1;
TABLE[23][44] = 1;
TABLE[23][40] = 1;
TABLE[23][42] = 1;
TABLE[23][299] = 1;
TABLE[24][58] = 1;
TABLE[24][40] = 1;
TABLE[24][299] = 1;
TABLE[24][42] = 1;
TABLE[161][58] = 1;
TABLE[161][40] = 1;
TABLE[161][42] = 1;
TABLE[161][299] = 1;
TABLE[227][58] = 1;
TABLE[25][266] = 1;
TABLE[26][266] = 1;
TABLE[162][299] = 1;
TABLE[228][123] = 1;
TABLE[27][44] = 1;
TABLE[27][299] = 1;
TABLE[163][44] = 1;
TABLE[163][299] = 1;
TABLE[229][299] = 1;
TABLE[28][299] = 1;
TABLE[164][61] = 1;
TABLE[230][125] = 1;
TABLE[230][44] = 1;
TABLE[29][40] = 1;
TABLE[29][299] = 1;
TABLE[29][42] = 1;
TABLE[165][42] = 1;
TABLE[231][40] = 1;
TABLE[231][299] = 1;
TABLE[30][299] = 1;
TABLE[31][40] = 1;
TABLE[32][40] = 1;
TABLE[32][299] = 1;
TABLE[167][91] = 1;
TABLE[168][40] = 1;
TABLE[170][40] = 1;
TABLE[166][278] = 1;
TABLE[166][295] = 1;
TABLE[166][294] = 1;
TABLE[166][33] = 1;
TABLE[166][126] = 1;
TABLE[166][45] = 1;
TABLE[166][43] = 1;
TABLE[166][42] = 1;
TABLE[166][38] = 1;
TABLE[166][40] = 1;
TABLE[166][299] = 1;
TABLE[166][289] = 1;
TABLE[166][303] = 1;
TABLE[166][302] = 1;
TABLE[166][304] = 1;
TABLE[232][93] = 1;
TABLE[169][41] = 1;
TABLE[169][44] = 1;
TABLE[169][299] = 1;
TABLE[233][41] = 1;
TABLE[33][42] = 1;
TABLE[171][42] = 1;
TABLE[171][40] = 1;
TABLE[171][299] = 1;
TABLE[171][44] = 1;
TABLE[171][41] = 1;
TABLE[171][91] = 1;
TABLE[171][260] = 1;
TABLE[171][286] = 1;
TABLE[234][42] = 1;
TABLE[234][40] = 1;
TABLE[234][299] = 1;
TABLE[234][44] = 1;
TABLE[234][41] = 1;
TABLE[234][91] = 1;
TABLE[172][42] = 1;
TABLE[235][40] = 1;
TABLE[235][299] = 1;
TABLE[235][44] = 1;
TABLE[235][41] = 1;
TABLE[235][91] = 1;
TABLE[34][286] = 1;
TABLE[34][260] = 1;
TABLE[173][260] = 1;
TABLE[173][286] = 1;
TABLE[236][286] = 1;
TABLE[236][260] = 1;
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
TABLE[174][44] = 1;
TABLE[237][41] = 1;
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
TABLE[175][44] = 1;
TABLE[175][40] = 1;
TABLE[175][42] = 1;
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
TABLE[175][91] = 1;
TABLE[175][283] = 1;
TABLE[175][280] = 1;
TABLE[238][40] = 1;
TABLE[238][256] = 1;
TABLE[238][274] = 1;
TABLE[238][279] = 1;
TABLE[238][267] = 1;
TABLE[238][282] = 1;
TABLE[238][299] = 1;
TABLE[238][266] = 1;
TABLE[238][285] = 1;
TABLE[238][259] = 1;
TABLE[238][276] = 1;
TABLE[238][272] = 1;
TABLE[238][273] = 1;
TABLE[238][268] = 1;
TABLE[238][264] = 1;
TABLE[238][277] = 1;
TABLE[238][284] = 1;
TABLE[238][260] = 1;
TABLE[238][286] = 1;
TABLE[238][42] = 1;
TABLE[238][280] = 1;
TABLE[238][283] = 1;
TABLE[238][91] = 1;
TABLE[238][44] = 1;
TABLE[238][41] = 1;
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
TABLE[176][44] = 1;
TABLE[176][41] = 1;
TABLE[176][40] = 1;
TABLE[176][42] = 1;
TABLE[176][299] = 1;
TABLE[178][44] = 1;
TABLE[178][41] = 1;
TABLE[178][42] = 1;
TABLE[178][40] = 1;
TABLE[178][91] = 1;
TABLE[177][44] = 1;
TABLE[177][41] = 1;
TABLE[177][42] = 1;
TABLE[177][40] = 1;
TABLE[177][91] = 1;
TABLE[239][44] = 1;
TABLE[239][41] = 1;
TABLE[38][44] = 1;
TABLE[38][299] = 1;
TABLE[179][44] = 1;
TABLE[179][299] = 1;
TABLE[240][299] = 1;
TABLE[39][278] = 1;
TABLE[39][38] = 1;
TABLE[39][42] = 1;
TABLE[39][43] = 1;
TABLE[39][45] = 1;
TABLE[39][126] = 1;
TABLE[39][33] = 1;
TABLE[39][294] = 1;
TABLE[39][295] = 1;
TABLE[39][40] = 1;
TABLE[39][304] = 1;
TABLE[39][302] = 1;
TABLE[39][303] = 1;
TABLE[39][289] = 1;
TABLE[39][299] = 1;
TABLE[40][123] = 1;
TABLE[180][44] = 1;
TABLE[241][125] = 1;
TABLE[41][123] = 1;
TABLE[41][44] = 1;
TABLE[41][278] = 1;
TABLE[41][295] = 1;
TABLE[41][294] = 1;
TABLE[41][33] = 1;
TABLE[41][126] = 1;
TABLE[41][45] = 1;
TABLE[41][43] = 1;
TABLE[41][42] = 1;
TABLE[41][38] = 1;
TABLE[41][40] = 1;
TABLE[41][299] = 1;
TABLE[41][289] = 1;
TABLE[41][303] = 1;
TABLE[41][302] = 1;
TABLE[41][304] = 1;
TABLE[181][123] = 1;
TABLE[181][44] = 1;
TABLE[181][278] = 1;
TABLE[181][38] = 1;
TABLE[181][42] = 1;
TABLE[181][43] = 1;
TABLE[181][45] = 1;
TABLE[181][126] = 1;
TABLE[181][33] = 1;
TABLE[181][294] = 1;
TABLE[181][295] = 1;
TABLE[181][40] = 1;
TABLE[181][304] = 1;
TABLE[181][302] = 1;
TABLE[181][303] = 1;
TABLE[181][289] = 1;
TABLE[181][299] = 1;
TABLE[242][123] = 1;
TABLE[242][278] = 1;
TABLE[242][295] = 1;
TABLE[242][294] = 1;
TABLE[242][33] = 1;
TABLE[242][126] = 1;
TABLE[242][45] = 1;
TABLE[242][43] = 1;
TABLE[242][42] = 1;
TABLE[242][38] = 1;
TABLE[242][40] = 1;
TABLE[242][299] = 1;
TABLE[242][289] = 1;
TABLE[242][303] = 1;
TABLE[242][302] = 1;
TABLE[242][304] = 1;
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
TABLE[182][41] = 1;
TABLE[182][42] = 1;
TABLE[182][40] = 1;
TABLE[182][91] = 1;
TABLE[243][41] = 1;
TABLE[43][42] = 1;
TABLE[44][44] = 1;
TABLE[44][41] = 1;
TABLE[44][40] = 1;
TABLE[44][91] = 1;
TABLE[44][42] = 1;
TABLE[183][42] = 1;
TABLE[244][40] = 1;
TABLE[244][91] = 1;
TABLE[244][44] = 1;
TABLE[244][41] = 1;
TABLE[45][40] = 1;
TABLE[46][40] = 1;
TABLE[46][91] = 1;
TABLE[184][40] = 1;
TABLE[184][91] = 1;
TABLE[245][91] = 1;
TABLE[245][40] = 1;
TABLE[186][91] = 1;
TABLE[188][40] = 1;
TABLE[185][278] = 1;
TABLE[185][295] = 1;
TABLE[185][294] = 1;
TABLE[185][33] = 1;
TABLE[185][126] = 1;
TABLE[185][45] = 1;
TABLE[185][43] = 1;
TABLE[185][42] = 1;
TABLE[185][38] = 1;
TABLE[185][40] = 1;
TABLE[185][299] = 1;
TABLE[185][289] = 1;
TABLE[185][303] = 1;
TABLE[185][302] = 1;
TABLE[185][304] = 1;
TABLE[246][93] = 1;
TABLE[187][41] = 1;
TABLE[187][44] = 1;
TABLE[187][40] = 1;
TABLE[187][256] = 1;
TABLE[187][274] = 1;
TABLE[187][279] = 1;
TABLE[187][267] = 1;
TABLE[187][282] = 1;
TABLE[187][299] = 1;
TABLE[187][266] = 1;
TABLE[187][285] = 1;
TABLE[187][259] = 1;
TABLE[187][276] = 1;
TABLE[187][272] = 1;
TABLE[187][273] = 1;
TABLE[187][268] = 1;
TABLE[187][264] = 1;
TABLE[187][277] = 1;
TABLE[187][284] = 1;
TABLE[187][260] = 1;
TABLE[187][286] = 1;
TABLE[187][42] = 1;
TABLE[187][280] = 1;
TABLE[187][283] = 1;
TABLE[187][91] = 1;
TABLE[247][41] = 1;
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
TABLE[49][278] = 1;
TABLE[49][295] = 1;
TABLE[49][294] = 1;
TABLE[49][33] = 1;
TABLE[49][126] = 1;
TABLE[49][45] = 1;
TABLE[49][43] = 1;
TABLE[49][42] = 1;
TABLE[49][38] = 1;
TABLE[49][40] = 1;
TABLE[49][299] = 1;
TABLE[49][289] = 1;
TABLE[49][303] = 1;
TABLE[49][302] = 1;
TABLE[49][304] = 1;
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
TABLE[59][278] = 1;
TABLE[59][38] = 1;
TABLE[59][42] = 1;
TABLE[59][43] = 1;
TABLE[59][45] = 1;
TABLE[59][126] = 1;
TABLE[59][33] = 1;
TABLE[59][294] = 1;
TABLE[59][295] = 1;
TABLE[59][40] = 1;
TABLE[59][304] = 1;
TABLE[59][302] = 1;
TABLE[59][303] = 1;
TABLE[59][289] = 1;
TABLE[59][299] = 1;
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
TABLE[189][299] = 1;
TABLE[189][289] = 1;
TABLE[189][303] = 1;
TABLE[189][302] = 1;
TABLE[189][304] = 1;
TABLE[248][59] = 1;
TABLE[60][123] = 1;
TABLE[190][262] = 1;
TABLE[190][258] = 1;
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
TABLE[190][125] = 1;
TABLE[190][59] = 1;
TABLE[190][44] = 1;
TABLE[190][61] = 1;
TABLE[190][123] = 1;
TABLE[190][286] = 1;
TABLE[190][260] = 1;
TABLE[190][284] = 1;
TABLE[190][277] = 1;
TABLE[190][264] = 1;
TABLE[190][268] = 1;
TABLE[190][273] = 1;
TABLE[190][272] = 1;
TABLE[190][276] = 1;
TABLE[190][259] = 1;
TABLE[190][285] = 1;
TABLE[190][266] = 1;
TABLE[190][299] = 1;
TABLE[190][282] = 1;
TABLE[190][267] = 1;
TABLE[190][279] = 1;
TABLE[190][274] = 1;
TABLE[190][256] = 1;
TABLE[190][40] = 1;
TABLE[190][278] = 1;
TABLE[190][283] = 1;
TABLE[190][280] = 1;
TABLE[190][42] = 1;
TABLE[190][38] = 1;
TABLE[190][43] = 1;
TABLE[190][45] = 1;
TABLE[190][126] = 1;
TABLE[190][33] = 1;
TABLE[190][294] = 1;
TABLE[190][295] = 1;
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
TABLE[191][125] = 1;
TABLE[191][306] = 1;
TABLE[191][305] = 1;
TABLE[191][270] = 1;
TABLE[191][261] = 1;
TABLE[191][257] = 1;
TABLE[191][275] = 1;
TABLE[191][287] = 1;
TABLE[191][263] = 1;
TABLE[191][269] = 1;
TABLE[191][271] = 1;
TABLE[191][281] = 1;
TABLE[191][123] = 1;
TABLE[191][59] = 1;
TABLE[191][258] = 1;
TABLE[191][262] = 1;
TABLE[191][299] = 1;
TABLE[191][278] = 1;
TABLE[191][295] = 1;
TABLE[191][294] = 1;
TABLE[191][33] = 1;
TABLE[191][126] = 1;
TABLE[191][45] = 1;
TABLE[191][43] = 1;
TABLE[191][42] = 1;
TABLE[191][38] = 1;
TABLE[191][40] = 1;
TABLE[191][289] = 1;
TABLE[191][303] = 1;
TABLE[191][302] = 1;
TABLE[191][304] = 1;
TABLE[250][125] = 1;
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
TABLE[61][278] = 1;
TABLE[61][295] = 1;
TABLE[61][294] = 1;
TABLE[61][33] = 1;
TABLE[61][126] = 1;
TABLE[61][45] = 1;
TABLE[61][43] = 1;
TABLE[61][42] = 1;
TABLE[61][38] = 1;
TABLE[61][40] = 1;
TABLE[61][289] = 1;
TABLE[61][303] = 1;
TABLE[61][302] = 1;
TABLE[61][304] = 1;
TABLE[192][125] = 1;
TABLE[192][262] = 1;
TABLE[192][258] = 1;
TABLE[192][59] = 1;
TABLE[192][123] = 1;
TABLE[192][281] = 1;
TABLE[192][271] = 1;
TABLE[192][269] = 1;
TABLE[192][263] = 1;
TABLE[192][287] = 1;
TABLE[192][275] = 1;
TABLE[192][257] = 1;
TABLE[192][261] = 1;
TABLE[192][270] = 1;
TABLE[192][305] = 1;
TABLE[192][306] = 1;
TABLE[192][299] = 1;
TABLE[192][278] = 1;
TABLE[192][38] = 1;
TABLE[192][42] = 1;
TABLE[192][43] = 1;
TABLE[192][45] = 1;
TABLE[192][126] = 1;
TABLE[192][33] = 1;
TABLE[192][294] = 1;
TABLE[192][295] = 1;
TABLE[192][40] = 1;
TABLE[192][304] = 1;
TABLE[192][302] = 1;
TABLE[192][303] = 1;
TABLE[192][289] = 1;
TABLE[251][262] = 1;
TABLE[251][258] = 1;
TABLE[251][59] = 1;
TABLE[251][123] = 1;
TABLE[251][281] = 1;
TABLE[251][271] = 1;
TABLE[251][269] = 1;
TABLE[251][263] = 1;
TABLE[251][287] = 1;
TABLE[251][275] = 1;
TABLE[251][257] = 1;
TABLE[251][261] = 1;
TABLE[251][270] = 1;
TABLE[251][305] = 1;
TABLE[251][306] = 1;
TABLE[251][299] = 1;
TABLE[251][278] = 1;
TABLE[251][38] = 1;
TABLE[251][42] = 1;
TABLE[251][43] = 1;
TABLE[251][45] = 1;
TABLE[251][126] = 1;
TABLE[251][33] = 1;
TABLE[251][294] = 1;
TABLE[251][295] = 1;
TABLE[251][40] = 1;
TABLE[251][304] = 1;
TABLE[251][302] = 1;
TABLE[251][303] = 1;
TABLE[251][289] = 1;
TABLE[251][125] = 1;
TABLE[62][271] = 1;
TABLE[63][281] = 1;
TABLE[193][265] = 1;
TABLE[252][125] = 1;
TABLE[252][262] = 1;
TABLE[252][258] = 1;
TABLE[252][59] = 1;
TABLE[252][123] = 1;
TABLE[252][281] = 1;
TABLE[252][271] = 1;
TABLE[252][269] = 1;
TABLE[252][263] = 1;
TABLE[252][287] = 1;
TABLE[252][275] = 1;
TABLE[252][257] = 1;
TABLE[252][261] = 1;
TABLE[252][270] = 1;
TABLE[252][305] = 1;
TABLE[252][306] = 1;
TABLE[252][299] = 1;
TABLE[252][278] = 1;
TABLE[252][38] = 1;
TABLE[252][42] = 1;
TABLE[252][43] = 1;
TABLE[252][45] = 1;
TABLE[252][126] = 1;
TABLE[252][33] = 1;
TABLE[252][294] = 1;
TABLE[252][295] = 1;
TABLE[252][40] = 1;
TABLE[252][304] = 1;
TABLE[252][302] = 1;
TABLE[252][303] = 1;
TABLE[252][289] = 1;
TABLE[252][265] = 1;
TABLE[64][287] = 1;
TABLE[65][263] = 1;
TABLE[66][269] = 1;
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
TABLE[253][59] = 1;
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
TABLE[196][278] = 1;
TABLE[196][295] = 1;
TABLE[196][294] = 1;
TABLE[196][33] = 1;
TABLE[196][126] = 1;
TABLE[196][45] = 1;
TABLE[196][43] = 1;
TABLE[196][42] = 1;
TABLE[196][38] = 1;
TABLE[196][40] = 1;
TABLE[196][299] = 1;
TABLE[196][289] = 1;
TABLE[196][303] = 1;
TABLE[196][302] = 1;
TABLE[196][304] = 1;
TABLE[255][41] = 1;
TABLE[67][270] = 1;
TABLE[68][261] = 1;
TABLE[69][257] = 1;
TABLE[70][275] = 1;
TABLE[197][278] = 1;
TABLE[197][295] = 1;
TABLE[197][294] = 1;
TABLE[197][33] = 1;
TABLE[197][126] = 1;
TABLE[197][45] = 1;
TABLE[197][43] = 1;
TABLE[197][42] = 1;
TABLE[197][38] = 1;
TABLE[197][40] = 1;
TABLE[197][299] = 1;
TABLE[197][289] = 1;
TABLE[197][303] = 1;
TABLE[197][302] = 1;
TABLE[197][304] = 1;
TABLE[256][59] = 1;
TABLE[71][305] = 1;
TABLE[72][306] = 1;
TABLE[198][299] = 1;
TABLE[257][299] = 1;
TABLE[73][278] = 1;
TABLE[73][38] = 1;
TABLE[73][42] = 1;
TABLE[73][43] = 1;
TABLE[73][45] = 1;
TABLE[73][126] = 1;
TABLE[73][33] = 1;
TABLE[73][294] = 1;
TABLE[73][295] = 1;
TABLE[73][40] = 1;
TABLE[73][304] = 1;
TABLE[73][302] = 1;
TABLE[73][303] = 1;
TABLE[73][289] = 1;
TABLE[73][299] = 1;
TABLE[74][278] = 1;
TABLE[74][295] = 1;
TABLE[74][294] = 1;
TABLE[74][33] = 1;
TABLE[74][126] = 1;
TABLE[74][45] = 1;
TABLE[74][43] = 1;
TABLE[74][42] = 1;
TABLE[74][38] = 1;
TABLE[74][40] = 1;
TABLE[74][299] = 1;
TABLE[74][289] = 1;
TABLE[74][303] = 1;
TABLE[74][302] = 1;
TABLE[74][304] = 1;
TABLE[75][40] = 1;
TABLE[75][278] = 1;
TABLE[75][38] = 1;
TABLE[75][42] = 1;
TABLE[75][43] = 1;
TABLE[75][45] = 1;
TABLE[75][126] = 1;
TABLE[75][33] = 1;
TABLE[75][294] = 1;
TABLE[75][295] = 1;
TABLE[75][304] = 1;
TABLE[75][302] = 1;
TABLE[75][303] = 1;
TABLE[75][289] = 1;
TABLE[75][299] = 1;
TABLE[76][278] = 1;
TABLE[76][295] = 1;
TABLE[76][294] = 1;
TABLE[76][33] = 1;
TABLE[76][126] = 1;
TABLE[76][45] = 1;
TABLE[76][43] = 1;
TABLE[76][42] = 1;
TABLE[76][38] = 1;
TABLE[76][40] = 1;
TABLE[76][299] = 1;
TABLE[76][289] = 1;
TABLE[76][303] = 1;
TABLE[76][302] = 1;
TABLE[76][304] = 1;
TABLE[77][291] = 1;
TABLE[78][61] = 1;
TABLE[79][40] = 1;
TABLE[79][278] = 1;
TABLE[79][295] = 1;
TABLE[79][294] = 1;
TABLE[79][33] = 1;
TABLE[79][126] = 1;
TABLE[79][45] = 1;
TABLE[79][43] = 1;
TABLE[79][42] = 1;
TABLE[79][38] = 1;
TABLE[79][299] = 1;
TABLE[79][289] = 1;
TABLE[79][303] = 1;
TABLE[79][302] = 1;
TABLE[79][304] = 1;
TABLE[80][40] = 1;
TABLE[80][278] = 1;
TABLE[80][295] = 1;
TABLE[80][294] = 1;
TABLE[80][33] = 1;
TABLE[80][126] = 1;
TABLE[80][45] = 1;
TABLE[80][43] = 1;
TABLE[80][42] = 1;
TABLE[80][38] = 1;
TABLE[80][299] = 1;
TABLE[80][289] = 1;
TABLE[80][303] = 1;
TABLE[80][302] = 1;
TABLE[80][304] = 1;
TABLE[81][40] = 1;
TABLE[81][278] = 1;
TABLE[81][38] = 1;
TABLE[81][42] = 1;
TABLE[81][43] = 1;
TABLE[81][45] = 1;
TABLE[81][126] = 1;
TABLE[81][33] = 1;
TABLE[81][294] = 1;
TABLE[81][295] = 1;
TABLE[81][304] = 1;
TABLE[81][302] = 1;
TABLE[81][303] = 1;
TABLE[81][289] = 1;
TABLE[81][299] = 1;
TABLE[82][40] = 1;
TABLE[82][278] = 1;
TABLE[82][38] = 1;
TABLE[82][42] = 1;
TABLE[82][43] = 1;
TABLE[82][45] = 1;
TABLE[82][126] = 1;
TABLE[82][33] = 1;
TABLE[82][294] = 1;
TABLE[82][295] = 1;
TABLE[82][304] = 1;
TABLE[82][302] = 1;
TABLE[82][303] = 1;
TABLE[82][289] = 1;
TABLE[82][299] = 1;
TABLE[83][40] = 1;
TABLE[83][278] = 1;
TABLE[83][295] = 1;
TABLE[83][294] = 1;
TABLE[83][33] = 1;
TABLE[83][126] = 1;
TABLE[83][45] = 1;
TABLE[83][43] = 1;
TABLE[83][42] = 1;
TABLE[83][38] = 1;
TABLE[83][299] = 1;
TABLE[83][289] = 1;
TABLE[83][303] = 1;
TABLE[83][302] = 1;
TABLE[83][304] = 1;
TABLE[84][40] = 1;
TABLE[84][278] = 1;
TABLE[84][295] = 1;
TABLE[84][294] = 1;
TABLE[84][33] = 1;
TABLE[84][126] = 1;
TABLE[84][45] = 1;
TABLE[84][43] = 1;
TABLE[84][42] = 1;
TABLE[84][38] = 1;
TABLE[84][299] = 1;
TABLE[84][289] = 1;
TABLE[84][303] = 1;
TABLE[84][302] = 1;
TABLE[84][304] = 1;
TABLE[85][40] = 1;
TABLE[85][278] = 1;
TABLE[85][38] = 1;
TABLE[85][42] = 1;
TABLE[85][43] = 1;
TABLE[85][45] = 1;
TABLE[85][126] = 1;
TABLE[85][33] = 1;
TABLE[85][294] = 1;
TABLE[85][295] = 1;
TABLE[85][304] = 1;
TABLE[85][302] = 1;
TABLE[85][303] = 1;
TABLE[85][289] = 1;
TABLE[85][299] = 1;
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
TABLE[87][40] = 1;
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
TABLE[87][303] = 1;
TABLE[87][302] = 1;
TABLE[87][304] = 1;
TABLE[88][40] = 1;
TABLE[88][278] = 1;
TABLE[88][295] = 1;
TABLE[88][294] = 1;
TABLE[88][33] = 1;
TABLE[88][126] = 1;
TABLE[88][45] = 1;
TABLE[88][43] = 1;
TABLE[88][42] = 1;
TABLE[88][38] = 1;
TABLE[88][299] = 1;
TABLE[88][289] = 1;
TABLE[88][303] = 1;
TABLE[88][302] = 1;
TABLE[88][304] = 1;
TABLE[89][40] = 1;
TABLE[89][278] = 1;
TABLE[89][38] = 1;
TABLE[89][42] = 1;
TABLE[89][43] = 1;
TABLE[89][45] = 1;
TABLE[89][126] = 1;
TABLE[89][33] = 1;
TABLE[89][294] = 1;
TABLE[89][295] = 1;
TABLE[89][304] = 1;
TABLE[89][302] = 1;
TABLE[89][303] = 1;
TABLE[89][289] = 1;
TABLE[89][299] = 1;
TABLE[90][40] = 1;
TABLE[90][278] = 1;
TABLE[90][38] = 1;
TABLE[90][42] = 1;
TABLE[90][43] = 1;
TABLE[90][45] = 1;
TABLE[90][126] = 1;
TABLE[90][33] = 1;
TABLE[90][294] = 1;
TABLE[90][295] = 1;
TABLE[90][304] = 1;
TABLE[90][302] = 1;
TABLE[90][303] = 1;
TABLE[90][289] = 1;
TABLE[90][299] = 1;
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
TABLE[92][295] = 1;
TABLE[92][294] = 1;
TABLE[92][33] = 1;
TABLE[92][126] = 1;
TABLE[92][45] = 1;
TABLE[92][43] = 1;
TABLE[92][42] = 1;
TABLE[92][38] = 1;
TABLE[92][299] = 1;
TABLE[92][289] = 1;
TABLE[92][303] = 1;
TABLE[92][302] = 1;
TABLE[92][304] = 1;
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
TABLE[94][38] = 1;
TABLE[94][42] = 1;
TABLE[94][43] = 1;
TABLE[94][45] = 1;
TABLE[94][126] = 1;
TABLE[94][33] = 1;
TABLE[94][294] = 1;
TABLE[94][295] = 1;
TABLE[94][304] = 1;
TABLE[94][302] = 1;
TABLE[94][303] = 1;
TABLE[94][289] = 1;
TABLE[94][299] = 1;
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
TABLE[96][295] = 1;
TABLE[96][294] = 1;
TABLE[96][33] = 1;
TABLE[96][126] = 1;
TABLE[96][45] = 1;
TABLE[96][43] = 1;
TABLE[96][42] = 1;
TABLE[96][38] = 1;
TABLE[96][299] = 1;
TABLE[96][289] = 1;
TABLE[96][303] = 1;
TABLE[96][302] = 1;
TABLE[96][304] = 1;
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
TABLE[199][43] = 1;
TABLE[200][45] = 1;
TABLE[98][40] = 1;
TABLE[98][278] = 1;
TABLE[98][38] = 1;
TABLE[98][42] = 1;
TABLE[98][43] = 1;
TABLE[98][45] = 1;
TABLE[98][126] = 1;
TABLE[98][33] = 1;
TABLE[98][294] = 1;
TABLE[98][295] = 1;
TABLE[98][304] = 1;
TABLE[98][302] = 1;
TABLE[98][303] = 1;
TABLE[98][289] = 1;
TABLE[98][299] = 1;
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
TABLE[201][42] = 1;
TABLE[202][47] = 1;
TABLE[203][37] = 1;
TABLE[100][278] = 1;
TABLE[100][295] = 1;
TABLE[100][294] = 1;
TABLE[100][33] = 1;
TABLE[100][126] = 1;
TABLE[100][45] = 1;
TABLE[100][43] = 1;
TABLE[100][42] = 1;
TABLE[100][38] = 1;
TABLE[100][40] = 1;
TABLE[100][299] = 1;
TABLE[100][289] = 1;
TABLE[100][303] = 1;
TABLE[100][302] = 1;
TABLE[100][304] = 1;
TABLE[101][40] = 1;
TABLE[102][40] = 1;
TABLE[102][304] = 1;
TABLE[102][302] = 1;
TABLE[102][303] = 1;
TABLE[102][289] = 1;
TABLE[102][299] = 1;
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
TABLE[204][294] = 1;
TABLE[205][295] = 1;
TABLE[107][38] = 1;
TABLE[108][42] = 1;
TABLE[109][43] = 1;
TABLE[110][45] = 1;
TABLE[111][126] = 1;
TABLE[112][33] = 1;
TABLE[113][40] = 1;
TABLE[113][299] = 1;
TABLE[113][289] = 1;
TABLE[113][303] = 1;
TABLE[113][302] = 1;
TABLE[113][304] = 1;
TABLE[114][40] = 1;
TABLE[114][304] = 1;
TABLE[114][302] = 1;
TABLE[114][303] = 1;
TABLE[114][289] = 1;
TABLE[114][299] = 1;
TABLE[207][91] = 1;
TABLE[209][40] = 1;
TABLE[210][46] = 1;
TABLE[211][296] = 1;
TABLE[212][294] = 1;
TABLE[213][295] = 1;
TABLE[206][58] = 1;
TABLE[258][93] = 1;
TABLE[208][41] = 1;
TABLE[208][278] = 1;
TABLE[208][295] = 1;
TABLE[208][294] = 1;
TABLE[208][33] = 1;
TABLE[208][126] = 1;
TABLE[208][45] = 1;
TABLE[208][43] = 1;
TABLE[208][42] = 1;
TABLE[208][38] = 1;
TABLE[208][40] = 1;
TABLE[208][299] = 1;
TABLE[208][289] = 1;
TABLE[208][303] = 1;
TABLE[208][302] = 1;
TABLE[208][304] = 1;
TABLE[259][41] = 1;
TABLE[115][299] = 1;
TABLE[116][304] = 1;
TABLE[116][302] = 1;
TABLE[116][303] = 1;
TABLE[116][289] = 1;
TABLE[117][40] = 1;
TABLE[118][278] = 1;
TABLE[118][295] = 1;
TABLE[118][294] = 1;
TABLE[118][33] = 1;
TABLE[118][126] = 1;
TABLE[118][45] = 1;
TABLE[118][43] = 1;
TABLE[118][42] = 1;
TABLE[118][38] = 1;
TABLE[118][40] = 1;
TABLE[118][299] = 1;
TABLE[118][289] = 1;
TABLE[118][303] = 1;
TABLE[118][302] = 1;
TABLE[118][304] = 1;
TABLE[214][278] = 1;
TABLE[214][38] = 1;
TABLE[214][42] = 1;
TABLE[214][43] = 1;
TABLE[214][45] = 1;
TABLE[214][126] = 1;
TABLE[214][33] = 1;
TABLE[214][294] = 1;
TABLE[214][295] = 1;
TABLE[214][40] = 1;
TABLE[214][304] = 1;
TABLE[214][302] = 1;
TABLE[214][303] = 1;
TABLE[214][289] = 1;
TABLE[214][299] = 1;
TABLE[260][278] = 1;
TABLE[260][38] = 1;
TABLE[260][42] = 1;
TABLE[260][43] = 1;
TABLE[260][45] = 1;
TABLE[260][126] = 1;
TABLE[260][33] = 1;
TABLE[260][294] = 1;
TABLE[260][295] = 1;
TABLE[260][40] = 1;
TABLE[260][304] = 1;
TABLE[260][302] = 1;
TABLE[260][303] = 1;
TABLE[260][289] = 1;
TABLE[260][299] = 1;
TABLE[119][304] = 1;
TABLE[120][302] = 1;
TABLE[121][303] = 1;
TABLE[122][289] = 1;
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
      case 513: return 0; break;
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
      case 844: return 0; break;
      case 854: return 0; break;
      case 864: return 0; break;
      case 872: return 0; break;
      case 884: return 0; break;
      case 888: return 0; break;
      case 898: return 0; break;
      case 908: return 0; break;
      case 918: return 0; break;
      case 928: return 0; break;
      case 938: return 0; break;
      case 948: return 0; break;
      case 958: return 0; break;
      case 968: return 0; break;
      case 976: return 0; break;
      case 986: return 0; break;
      case 998: return 0; break;
      case 1009: return 0; break;
      case 1035: return 0; break;
      case 1043: return 0; break;
      case 1067: return 0; break;
      case 1076: return 0; break;
      case 1107: return 1; break;
      case 1115: return 1; break;
      case 1122: return 0; break;
      case 1136: return 1; break;
      case 1141: return 1; break;
      case 1150: return 0; break;
      case 1166: return 0; break;
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
         case 854: return "assignment_expression"; break;
         case 864: return "assignment_operator"; break;
         case 872: return "conditional_expression"; break;
         case 884: return "constant_expression"; break;
         case 888: return "logical_OR_expression"; break;
         case 898: return "logical_AND_expression"; break;
         case 908: return "inclusive_OR_expression"; break;
         case 918: return "exclusive_OR_expression"; break;
         case 928: return "AND_expression"; break;
         case 938: return "equality_expression"; break;
         case 948: return "shift_expression"; break;
         case 958: return "additive_expression"; break;
         case 968: return "Subphrase"; break;
         case 976: return "multiplicative_expression"; break;
         case 986: return "Subphrase"; break;
         case 998: return "cast_expression"; break;
         case 1009: return "unary_expression"; break;
         case 1035: return "Subphrase"; break;
         case 1043: return "unary_operator"; break;
         case 1067: return "postfix_expression"; break;
         case 1076: return "Subphrase"; break;
         case 1107: return "Subphrase"; break;
         case 1115: return "Subphrase"; break;
         case 1122: return "primary_expression"; break;
         case 1136: return "argument_expression_list"; break;
         case 1141: return "Subphrase"; break;
         case 1150: return "constant"; break;
         case 1166: return "id"; break;
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
