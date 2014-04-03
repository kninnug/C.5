#line 6 "ass3.acc"

	#include <stdio.h>
	#include <stdlib.h>
	
	#include "parser.h"

# line 9 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 127: {
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
         case 128: {
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
   compstatement_pt cs;
   switch(yyselect()) {
   case 4: {
      switch (yyselect()) {
      case 129: {
         declaration_specifiers();
         } break;
      default: ;
      }
      declarator();
      switch (yyselect()) {
      case 130: {
         declaration_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 131: {
         get_lexval();
         } break;
      case 132: {
         compound_statement(&cs);
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
      case 133: {
         init_declarator_list();
         } break;
      default: ;
      }
      get_lexval();
#line 35 "ass3.acc"
 fprintf(stderr, "Declarate!\n"); 
# line 96 "yygrammar.c"
      } break;
   }
}

declaration_list ()
{
   switch(yyselect()) {
   case 6: {
      while (1) {
         switch (yyselect()) {
         case 134: {
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
      case 135: {
         storage_class_specifier();
         } break;
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
   }
}

type_specifier ()
{
   switch(yyselect()) {
   case 12: {
      get_lexval();
      } break;
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
      struct_or_union_specifier();
      } break;
   case 22: {
      enum_specifier();
      } break;
   }
}

type_qualifier ()
{
   switch(yyselect()) {
   case 23: {
      get_lexval();
      } break;
   case 24: {
      get_lexval();
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
      case 139: {
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
#line 76 "ass3.acc"

# line 235 "yygrammar.c"
      } break;
   }
}

struct_or_union ()
{
   switch(yyselect()) {
   case 27: {
      get_lexval();
      } break;
   case 28: {
      get_lexval();
      } break;
   }
}

struct_declaration_list ()
{
   switch(yyselect()) {
   case 29: {
      switch (yyselect()) {
      case 140: {
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
   case 30: {
      switch (yyselect()) {
      case 141: {
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
   case 31: {
      switch (yyselect()) {
      case 142: {
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
   case 32: {
      specifier_qualifier_list();
      struct_declarator_list();
      get_lexval();
      } break;
   }
}

specifier_qualifier_list ()
{
   switch(yyselect()) {
   case 33: {
      switch (yyselect()) {
      case 143: {
         type_specifier();
         } break;
      case 144: {
         type_qualifier();
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 145: {
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
   case 34: {
      switch (yyselect()) {
      case 146: {
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
   case 35: {
      declarator();
      } break;
   case 36: {
      switch (yyselect()) {
      case 147: {
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
   case 37: {
      get_lexval();
      switch (yyselect()) {
      case 148: {
         id(&i);
         } break;
      default: ;
      }
      get_lexval();
      enumerator_list();
      get_lexval();
      } break;
   case 38: {
      get_lexval();
      id(&i);
      } break;
   }
}

enumerator_list ()
{
   switch(yyselect()) {
   case 39: {
      switch (yyselect()) {
      case 149: {
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
   case 40: {
      id(&i);
      switch (yyselect()) {
      case 150: {
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
   case 41: {
      switch (yyselect()) {
      case 151: {
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
   case 42: {
      id(&i);
      } break;
   case 43: {
      get_lexval();
      declarator();
      get_lexval();
      } break;
   case 44: {
      direct_declarator();
      switch (yyselect()) {
      case 153: {
         get_lexval();
         switch (yyselect()) {
         case 152: {
            expression(&e);
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 154: {
         get_lexval();
         parameter_type_list();
         get_lexval();
         } break;
      case 156: {
         get_lexval();
         switch (yyselect()) {
         case 155: {
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
   case 45: {
      get_lexval();
      switch (yyselect()) {
      case 157: {
         type_qualifier_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 158: {
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
   case 46: {
      switch (yyselect()) {
      case 159: {
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
   case 47: {
      parameter_list();
      switch (yyselect()) {
      case 160: {
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
   case 48: {
      switch (yyselect()) {
      case 161: {
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
   case 49: {
      declaration_specifiers();
      switch (yyselect()) {
      case 162: {
         declarator();
         } break;
      case 164: {
         switch (yyselect()) {
         case 163: {
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
   case 50: {
      switch (yyselect()) {
      case 165: {
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
   case 51: {
      assignment_expression(&ae);
      } break;
   case 52: {
      get_lexval();
      initializer_list();
      switch (yyselect()) {
      case 166: {
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
   case 53: {
      switch (yyselect()) {
      case 167: {
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
   case 54: {
      specifier_qualifier_list();
      switch (yyselect()) {
      case 168: {
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
   case 55: {
      pointer();
      } break;
   case 56: {
      switch (yyselect()) {
      case 169: {
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
   case 57: {
      get_lexval();
      abstract_declarator();
      get_lexval();
      } break;
   case 58: {
      switch (yyselect()) {
      case 170: {
         direct_abstract_declarator();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 172: {
         get_lexval();
         switch (yyselect()) {
         case 171: {
            expression(&e);
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 174: {
         get_lexval();
         switch (yyselect()) {
         case 173: {
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
   case 59: {
      id(&i);
      } break;
   }
}

statement (ret)
   statement_pt *ret;
{
   expstatement_pt es;
   compstatement_pt cs;
   statement_pt s;
   switch(yyselect()) {
   case 60: {
#line 193 "ass3.acc"
 *ret = makeStatement(); (*ret)->type = 0; 
# line 729 "yygrammar.c"
      switch (yyselect()) {
      case 175: {
         labeled_statement();
#line 194 "ass3.acc"
 fprintf(stderr, "Label!\n"); 
# line 735 "yygrammar.c"
         } break;
      case 176: {
         expression_statement(&es);
#line 195 "ass3.acc"
 fprintf(stderr, "Express!\n"); (*ret)->type = 'e'; (*ret)->exps = es; 
# line 741 "yygrammar.c"
         } break;
      case 177: {
         compound_statement(&cs);
#line 196 "ass3.acc"
 fprintf(stderr, "Confound!\n"); (*ret)->type = 'c'; (*ret)->comps = cs; printStatement(*ret); 
# line 747 "yygrammar.c"
         } break;
      case 178: {
         selection_statement(&s);
#line 197 "ass3.acc"
 fprintf(stderr, "Select!\n"); *ret = s; printStatement(*ret); 
# line 753 "yygrammar.c"
         } break;
      case 179: {
         iteration_statement(&s);
#line 198 "ass3.acc"
 fprintf(stderr, "Iterate!\n"); *ret = s; printStatement(*ret); 
# line 759 "yygrammar.c"
         } break;
      case 180: {
         jump_statement();
#line 199 "ass3.acc"
 fprintf(stderr, "Jump!\n"); 
# line 765 "yygrammar.c"
         } break;
      case 181: {
         print_statement();
#line 200 "ass3.acc"
 fprintf(stderr, "Print!\n"); 
# line 771 "yygrammar.c"
         } break;
      case 182: {
         input_statement();
#line 201 "ass3.acc"
 fprintf(stderr, "Input!\n"); 
# line 777 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

labeled_statement ()
{
   constant_pt i;
   statement_pt s;
   expression_pt ce;
   switch(yyselect()) {
   case 61: {
      id(&i);
      get_lexval();
      statement(&s);
      } break;
   case 62: {
      get_lexval();
      constant_expression(&ce);
      get_lexval();
      statement(&s);
      } break;
   case 63: {
      get_lexval();
      get_lexval();
      statement(&s);
      } break;
   }
}

expression_statement (ret)
   expstatement_pt *ret;
{
   expression_pt e;
   switch(yyselect()) {
   case 64: {
#line 212 "ass3.acc"
 *ret = NULL; 
# line 818 "yygrammar.c"
      switch (yyselect()) {
      case 183: {
         expression(&e);
#line 212 "ass3.acc"
 printExpression(e, 0); *ret = makeExpStmt(e); 
# line 824 "yygrammar.c"
         } break;
      default: ;
      }
      get_lexval();
      } break;
   }
}

compound_statement (cs)
   compstatement_pt *cs;
{
   switch(yyselect()) {
   case 65: {
#line 216 "ass3.acc"
 *cs = makeCompStmt(); 
# line 840 "yygrammar.c"
      get_lexval();
      switch (yyselect()) {
      case 184: {
         declaration_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 185: {
         statement_list(*cs);
         } break;
      default: ;
      }
      get_lexval();
      } break;
   }
}

statement_list (cs)
   compstatement_pt cs;
{
   statement_pt s;
   switch(yyselect()) {
   case 66: {
      while (1) {
         switch (yyselect()) {
         case 186: {
            statement(&s);
#line 225 "ass3.acc"
 growCompStmt(cs, s); 
# line 871 "yygrammar.c"
            } break;
         default: goto yy3;
         }
      }
      yy3: ;
      statement(&s);
#line 225 "ass3.acc"
 growCompStmt(cs, s); 
# line 880 "yygrammar.c"
      } break;
   }
}

selection_statement (ss)
   statement_pt *ss;
{
   expression_pt e;
   statement_pt s;
   statement_pt se;
   switch(yyselect()) {
   case 67: {
      get_lexval();
      get_lexval();
      expression(&e);
      get_lexval();
      statement(&s);
#line 229 "ass3.acc"
 *ss = makeStatement(); (*ss)->type = 'i'; (*ss)->ifs = makeIfStmt(e, s); 
# line 900 "yygrammar.c"
      switch (yyselect()) {
      case 187: {
         get_lexval();
         statement(&se);
#line 230 "ass3.acc"
 (*ss)->ifs->otherwise = se; 
# line 907 "yygrammar.c"
         } break;
      default: ;
      }
      } break;
   case 68: {
      get_lexval();
      get_lexval();
      expression(&e);
      get_lexval();
      statement(&s);
#line 231 "ass3.acc"
 *ss = makeStatement(); (*ss)->type = 's'; (*ss)->switchs = makeSwitchStmt(e, s); 
# line 920 "yygrammar.c"
      } break;
   }
}

iteration_statement (is)
   statement_pt *is;
{
   expression_pt e;
   statement_pt s;
   switch(yyselect()) {
   case 69: {
#line 235 "ass3.acc"
 *is = makeStatement(); 
# line 934 "yygrammar.c"
      switch (yyselect()) {
      case 188: {
         get_lexval();
         get_lexval();
         expression(&e);
         get_lexval();
         statement(&s);
#line 236 "ass3.acc"
 (*is)->type = 'w'; (*is)->whiles = makeWhileStmt(e, s); 
# line 944 "yygrammar.c"
         } break;
      case 189: {
         get_lexval();
         statement(&s);
         get_lexval();
         get_lexval();
         expression(&e);
         get_lexval();
         get_lexval();
#line 237 "ass3.acc"
 (*is)->type = 'w'; (*is)->whiles = makeWhileStmt(e, s); (*is)->whiles->dowhile = 1; 
# line 956 "yygrammar.c"
         } break;
      case 193: {
         get_lexval();
#line 238 "ass3.acc"
 (*is)->type = 'f'; (*is)->fors = makeForStmt(); 
# line 962 "yygrammar.c"
         get_lexval();
         switch (yyselect()) {
         case 190: {
            expression(&e);
#line 238 "ass3.acc"
 (*is)->fors->exp1= e; 
# line 969 "yygrammar.c"
            } break;
         default: ;
         }
         get_lexval();
         switch (yyselect()) {
         case 191: {
            expression(&e);
#line 238 "ass3.acc"
 (*is)->fors->exp2= e; 
# line 979 "yygrammar.c"
            } break;
         default: ;
         }
         get_lexval();
         switch (yyselect()) {
         case 192: {
            expression(&e);
#line 238 "ass3.acc"
 (*is)->fors->exp3= e; 
# line 989 "yygrammar.c"
            } break;
         default: ;
         }
         get_lexval();
         statement(&s);
#line 238 "ass3.acc"
  { (*is)->fors->body= s; } 
# line 997 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

jump_statement ()
{
   constant_pt i;
   expression_pt e;
   switch(yyselect()) {
   case 70: {
      get_lexval();
      id(&i);
      get_lexval();
      } break;
   case 71: {
      get_lexval();
      get_lexval();
      } break;
   case 72: {
      get_lexval();
      get_lexval();
      } break;
   case 73: {
      get_lexval();
      switch (yyselect()) {
      case 194: {
         expression(&e);
#line 245 "ass3.acc"
 printExpression(e, 0); 
# line 1030 "yygrammar.c"
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
   case 74: {
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
   case 75: {
      get_lexval();
      while (1) {
         switch (yyselect()) {
         case 195: {
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
   case 76: {
      assignment_expression(&ae);
#line 257 "ass3.acc"
 *ret = ae; 
# line 1083 "yygrammar.c"
      } break;
   case 77: {
      expression(&e);
      get_lexval();
      assignment_expression(&ae);
#line 258 "ass3.acc"
 *ret = makeExpression(1, 2, ',', e, ae); 
# line 1091 "yygrammar.c"
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
   case 78: {
      conditional_expression(&ce);
#line 262 "ass3.acc"
 *ret = ce; 
# line 1108 "yygrammar.c"
      } break;
   case 79: {
      unary_expression(&ue);
      assignment_operator(&ao);
      assignment_expression(&ae);
#line 263 "ass3.acc"
 *ret = makeExpression(1, 2, ao, ue, ae); 
# line 1116 "yygrammar.c"
      } break;
   }
}

assignment_operator (ret)
   int *ret;
{
   switch(yyselect()) {
   case 80: {
      get_lexval();
#line 267 "ass3.acc"
 *ret = yylval.subtype; 
# line 1129 "yygrammar.c"
      } break;
   case 81: {
      get_lexval();
#line 268 "ass3.acc"
 *ret = '='; 
# line 1135 "yygrammar.c"
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
   case 82: {
      logical_OR_expression(&loe);
#line 272 "ass3.acc"
 *ret = loe; 
# line 1151 "yygrammar.c"
      } break;
   case 83: {
      logical_OR_expression(&loe);
      get_lexval();
      expression(&e);
      get_lexval();
      conditional_expression(&ce);
#line 273 "ass3.acc"
 *ret = makeExpression(1, 3, '?', loe, e, ce); 
# line 1161 "yygrammar.c"
      } break;
   }
}

constant_expression (ret)
   expression_pt *ret;
{
   expression_pt ce;
   switch(yyselect()) {
   case 84: {
      conditional_expression(&ce);
#line 277 "ass3.acc"
 *ret = ce; 
# line 1175 "yygrammar.c"
      } break;
   }
}

logical_OR_expression (ret)
   expression_pt *ret;
{
   expression_pt lae;
   expression_pt loe;
   switch(yyselect()) {
   case 85: {
      logical_AND_expression(&lae);
#line 281 "ass3.acc"
 *ret = lae; 
# line 1190 "yygrammar.c"
      } break;
   case 86: {
      logical_OR_expression(&loe);
      get_lexval();
      logical_AND_expression(&lae);
#line 282 "ass3.acc"
 *ret = makeExpression(1, 2, '||', loe, lae); 
# line 1198 "yygrammar.c"
      } break;
   }
}

logical_AND_expression (ret)
   expression_pt *ret;
{
   expression_pt ioe;
   expression_pt lae;
   switch(yyselect()) {
   case 87: {
      inclusive_OR_expression(&ioe);
#line 286 "ass3.acc"
 *ret = ioe; 
# line 1213 "yygrammar.c"
      } break;
   case 88: {
      logical_AND_expression(&lae);
      get_lexval();
      inclusive_OR_expression(&ioe);
#line 287 "ass3.acc"
 *ret = makeExpression(1, 2, '&&', lae, ioe); 
# line 1221 "yygrammar.c"
      } break;
   }
}

inclusive_OR_expression (ret)
   expression_pt *ret;
{
   expression_pt eoe;
   expression_pt ioe;
   switch(yyselect()) {
   case 89: {
      exclusive_OR_expression(&eoe);
#line 291 "ass3.acc"
 *ret = eoe; 
# line 1236 "yygrammar.c"
      } break;
   case 90: {
      inclusive_OR_expression(&ioe);
      get_lexval();
      exclusive_OR_expression(&eoe);
#line 292 "ass3.acc"
 *ret = makeExpression(1, 2, '|', ioe, eoe); 
# line 1244 "yygrammar.c"
      } break;
   }
}

exclusive_OR_expression (ret)
   expression_pt *ret;
{
   expression_pt ae;
   expression_pt eoe;
   switch(yyselect()) {
   case 91: {
      AND_expression(&ae);
#line 296 "ass3.acc"
 *ret = ae; 
# line 1259 "yygrammar.c"
      } break;
   case 92: {
      exclusive_OR_expression(&eoe);
      get_lexval();
      AND_expression(&ae);
#line 297 "ass3.acc"
 *ret = makeExpression(1, 2, '^', eoe, ae); 
# line 1267 "yygrammar.c"
      } break;
   }
}

AND_expression (ret)
   expression_pt *ret;
{
   expression_pt ee;
   expression_pt ae;
   switch(yyselect()) {
   case 93: {
      equality_expression(&ee);
#line 301 "ass3.acc"
 *ret = ee; 
# line 1282 "yygrammar.c"
      } break;
   case 94: {
      AND_expression(&ae);
      get_lexval();
      equality_expression(&ee);
#line 302 "ass3.acc"
 *ret = makeExpression(1, 2, '&', ae, ee); 
# line 1290 "yygrammar.c"
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
   case 95: {
      shift_expression(&se);
#line 306 "ass3.acc"
 *ret = se; 
# line 1306 "yygrammar.c"
      } break;
   case 96: {
      equality_expression(&ee);
      get_lexval();
      c = yylval;
      shift_expression(&se);
#line 307 "ass3.acc"
 *ret = makeExpression(1, 2, c.subtype, ee, se); 
# line 1315 "yygrammar.c"
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
   case 97: {
      additive_expression(&ae);
#line 311 "ass3.acc"
 *ret = ae; 
# line 1331 "yygrammar.c"
      } break;
   case 98: {
      shift_expression(&se);
      get_lexval();
      s = yylval;
      additive_expression(&ae);
#line 312 "ass3.acc"
 *ret = makeExpression(1, 2, s.subtype, se, ae); 
# line 1340 "yygrammar.c"
      } break;
   }
}

additive_expression (ret)
   expression_pt *ret;
{
   expression_pt me;
   expression_pt ae;
   switch(yyselect()) {
   case 99: {
      multiplicative_expression(&me);
#line 316 "ass3.acc"
 *ret = me; 
# line 1355 "yygrammar.c"
      } break;
   case 100: {
#line 317 "ass3.acc"
 int op = '+'; 
# line 1360 "yygrammar.c"
      additive_expression(&ae);
      switch (yyselect()) {
      case 196: {
         get_lexval();
         } break;
      case 197: {
         get_lexval();
#line 317 "ass3.acc"
 op = '-'; 
# line 1370 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      multiplicative_expression(&me);
#line 317 "ass3.acc"
 *ret = makeExpression(1, 2, op, ae, me); 
# line 1377 "yygrammar.c"
      } break;
   }
}

multiplicative_expression (ret)
   expression_pt *ret;
{
   expression_pt ce;
   expression_pt me;
   switch(yyselect()) {
   case 101: {
      cast_expression(&ce);
#line 321 "ass3.acc"
 *ret = ce; 
# line 1392 "yygrammar.c"
      } break;
   case 102: {
#line 322 "ass3.acc"
 int op = '*'; 
# line 1397 "yygrammar.c"
      multiplicative_expression(&me);
      switch (yyselect()) {
      case 198: {
         get_lexval();
         } break;
      case 199: {
         get_lexval();
#line 322 "ass3.acc"
 op = '/'; 
# line 1407 "yygrammar.c"
         } break;
      case 200: {
         get_lexval();
#line 322 "ass3.acc"
 op = '%'; 
# line 1413 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      cast_expression(&ce);
#line 322 "ass3.acc"
 *ret = makeExpression(1, 2, op, me, ce); 
# line 1420 "yygrammar.c"
      } break;
   }
}

cast_expression (ret)
   expression_pt *ret;
{
   expression_pt ue;
   expression_pt ce;
   switch(yyselect()) {
   case 103: {
      unary_expression(&ue);
#line 326 "ass3.acc"
 *ret =  ue; 
# line 1435 "yygrammar.c"
      } break;
   case 104: {
      get_lexval();
      type_name();
      get_lexval();
      cast_expression(&ce);
#line 327 "ass3.acc"
 *ret = ce; 
# line 1444 "yygrammar.c"
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
   case 105: {
      postfix_expression(&pe);
#line 331 "ass3.acc"
 *ret = pe; 
# line 1461 "yygrammar.c"
      } break;
   case 106: {
#line 332 "ass3.acc"
 int t; 
# line 1466 "yygrammar.c"
      switch (yyselect()) {
      case 201: {
         get_lexval();
#line 332 "ass3.acc"
t = '++x';
# line 1472 "yygrammar.c"
         } break;
      case 202: {
         get_lexval();
#line 332 "ass3.acc"
t = '--x'; 
# line 1478 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      unary_expression(&ue);
#line 332 "ass3.acc"
 *ret = makeExpression(1, 1, t, ue); 
# line 1485 "yygrammar.c"
      } break;
   case 107: {
      unary_operator(&op);
      cast_expression(&ce);
#line 333 "ass3.acc"
 *ret = makeExpression(1, 1, op, ce); 
# line 1492 "yygrammar.c"
      } break;
   case 108: {
      get_lexval();
      unary_expression(&ue);
#line 334 "ass3.acc"
 *ret = ue; 
# line 1499 "yygrammar.c"
      } break;
   case 109: {
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
   case 110: {
      get_lexval();
#line 339 "ass3.acc"
 *op = '&'; 
# line 1518 "yygrammar.c"
      } break;
   case 111: {
      get_lexval();
#line 340 "ass3.acc"
 *op = '*'; 
# line 1524 "yygrammar.c"
      } break;
   case 112: {
      get_lexval();
#line 341 "ass3.acc"
 *op = '+'; 
# line 1530 "yygrammar.c"
      } break;
   case 113: {
      get_lexval();
#line 342 "ass3.acc"
 *op = '-'; 
# line 1536 "yygrammar.c"
      } break;
   case 114: {
      get_lexval();
#line 343 "ass3.acc"
 *op = '~'; 
# line 1542 "yygrammar.c"
      } break;
   case 115: {
      get_lexval();
#line 344 "ass3.acc"
 *op = '!'; 
# line 1548 "yygrammar.c"
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
   case 116: {
      primary_expression(&pe);
#line 348 "ass3.acc"
 *ret = pe; 
# line 1565 "yygrammar.c"
      } break;
   case 117: {
      postfix_expression(&pe);
#line 349 "ass3.acc"
 *ret = makeExpression(1, 1, 0, pe); fprintf(stderr, "@ PE: "); printExpression(*ret, 0); 
# line 1571 "yygrammar.c"
      switch (yyselect()) {
      case 204: {
         get_lexval();
         expression(&e);
#line 350 "ass3.acc"
 appendExpression(*ret, e); 
# line 1578 "yygrammar.c"
         switch (yyselect()) {
         case 203: {
            get_lexval();
            expression(&e);
#line 350 "ass3.acc"
 appendExpression(*ret, e); 
# line 1585 "yygrammar.c"
            } break;
         default: ;
         }
         get_lexval();
#line 350 "ass3.acc"
 (*ret)->operator = '[]'; 
# line 1592 "yygrammar.c"
         } break;
      case 206: {
         get_lexval();
         switch (yyselect()) {
         case 205: {
            argument_expression_list(&ae);
#line 351 "ass3.acc"
 appendExpression(*ret, ae); 
# line 1601 "yygrammar.c"
            } break;
         default: ;
         }
         get_lexval();
#line 351 "ass3.acc"
 (*ret)->operator = '()'; 
# line 1608 "yygrammar.c"
         } break;
      case 207: {
         get_lexval();
         id(&i);
#line 352 "ass3.acc"
 appendExpression(*ret, makeExpression(0, 1, 0, i)); (*ret)->operator = '.'; 
# line 1615 "yygrammar.c"
         } break;
      case 208: {
         get_lexval();
         id(&i);
#line 353 "ass3.acc"
 appendExpression(*ret, makeExpression(0, 1, 0, i)); (*ret)->operator = '->'; 
# line 1622 "yygrammar.c"
         } break;
      case 209: {
         get_lexval();
#line 354 "ass3.acc"
 (*ret)->operator = 'x++'; 
# line 1628 "yygrammar.c"
         } break;
      case 210: {
         get_lexval();
#line 355 "ass3.acc"
 (*ret)->operator = 'x--'; 
# line 1634 "yygrammar.c"
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
   case 118: {
      id(&i);
#line 360 "ass3.acc"
 *ret = makeExpression(0, 1, 0, i); 
# line 1653 "yygrammar.c"
      } break;
   case 119: {
      constant(&c);
#line 361 "ass3.acc"
 *ret = makeExpression(0, 1, 0, c); 
# line 1659 "yygrammar.c"
      } break;
   case 120: {
      get_lexval();
      expression(&e);
      get_lexval();
#line 362 "ass3.acc"
 *ret = e; 
# line 1667 "yygrammar.c"
      } break;
   }
}

argument_expression_list (ret)
   expression_pt *ret;
{
   expression_pt ae;
   expression_pt ae2;
   switch(yyselect()) {
   case 121: {
#line 366 "ass3.acc"
 *ret = makeExpression(1, 0, '(,)'); 
# line 1681 "yygrammar.c"
      while (1) {
         switch (yyselect()) {
         case 211: {
            assignment_expression(&ae);
#line 366 "ass3.acc"
 appendExpression(*ret, ae); 
# line 1688 "yygrammar.c"
            get_lexval();
            } break;
         default: goto yy5;
         }
      }
      yy5: ;
      assignment_expression(&ae2);
#line 366 "ass3.acc"
 appendExpression(*ret, ae2); 
# line 1698 "yygrammar.c"
      } break;
   }
}

constant (ret)
   constant_pt *ret;
{
   switch(yyselect()) {
   case 122: {
      get_lexval();
#line 370 "ass3.acc"
 *ret = makeIntConst(yylval.i); 
# line 1711 "yygrammar.c"
      } break;
   case 123: {
      get_lexval();
#line 371 "ass3.acc"
 *ret = makeIntConst(yylval.i); 
# line 1717 "yygrammar.c"
      } break;
   case 124: {
      get_lexval();
#line 372 "ass3.acc"
 *ret = makeFloatConst(yylval.d); 
# line 1723 "yygrammar.c"
      } break;
   case 125: {
      get_lexval();
#line 373 "ass3.acc"
 *ret = makeStringConst(yylval.s); 
# line 1729 "yygrammar.c"
      } break;
   }
}

id (ret)
   constant_pt *ret;
{
   switch(yyselect()) {
   case 126: {
      get_lexval();
#line 378 "ass3.acc"
 *ret = makeStringConst(yylval.s); (*ret)->type = IDCONST; 
# line 1742 "yygrammar.c"
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
int c_length = 1155;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 127,
/* 6 */ 0,
/* 7 */ 10,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 15,
/* 11 */ 18,
/* 12 */ 10,
/* 13 */ -10,
/* 14 */ 128,
/* 15 */ 0,
/* 16 */ -10,
/* 17 */ 212,
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
/* 28 */ 341,
/* 29 */ 40,
/* 30 */ 47,
/* 31 */ -26,
/* 32 */ 4,
/* 33 */ 37,
/* 34 */ 81,
/* 35 */ -33,
/* 36 */ 129,
/* 37 */ 0,
/* 38 */ -33,
/* 39 */ 213,
/* 40 */ 44,
/* 41 */ 68,
/* 42 */ -40,
/* 43 */ 130,
/* 44 */ 0,
/* 45 */ -40,
/* 46 */ 214,
/* 47 */ 51,
/* 48 */ 50059,
/* 49 */ -47,
/* 50 */ 131,
/* 51 */ 0,
/* 52 */ 665,
/* 53 */ -47,
/* 54 */ 132,
/* 55 */ 0,
/* 56 */ 81,
/* 57 */ 61,
/* 58 */ 50059,
/* 59 */ -55,
/* 60 */ 5,
/* 61 */ 65,
/* 62 */ 213,
/* 63 */ -61,
/* 64 */ 133,
/* 65 */ 0,
/* 66 */ -61,
/* 67 */ 215,
/* 68 */ 0,
/* 69 */ 73,
/* 70 */ 55,
/* 71 */ -68,
/* 72 */ 6,
/* 73 */ 78,
/* 74 */ 55,
/* 75 */ 73,
/* 76 */ -73,
/* 77 */ 134,
/* 78 */ 0,
/* 79 */ -73,
/* 80 */ 216,
/* 81 */ 0,
/* 82 */ 86,
/* 83 */ 98,
/* 84 */ -81,
/* 85 */ 7,
/* 86 */ 90,
/* 87 */ 105,
/* 88 */ -86,
/* 89 */ 135,
/* 90 */ 94,
/* 91 */ 121,
/* 92 */ -86,
/* 93 */ 136,
/* 94 */ 0,
/* 95 */ 165,
/* 96 */ -86,
/* 97 */ 137,
/* 98 */ 102,
/* 99 */ 81,
/* 100 */ -98,
/* 101 */ 138,
/* 102 */ 0,
/* 103 */ -98,
/* 104 */ 217,
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
/* 117 */ 0,
/* 118 */ 50267,
/* 119 */ -105,
/* 120 */ 11,
/* 121 */ 125,
/* 122 */ 50285,
/* 123 */ -121,
/* 124 */ 12,
/* 125 */ 129,
/* 126 */ 50277,
/* 127 */ -121,
/* 128 */ 13,
/* 129 */ 133,
/* 130 */ 50284,
/* 131 */ -121,
/* 132 */ 14,
/* 133 */ 137,
/* 134 */ 50276,
/* 135 */ -121,
/* 136 */ 15,
/* 137 */ 141,
/* 138 */ 50273,
/* 139 */ -121,
/* 140 */ 16,
/* 141 */ 145,
/* 142 */ 50272,
/* 143 */ -121,
/* 144 */ 17,
/* 145 */ 149,
/* 146 */ 50259,
/* 147 */ -121,
/* 148 */ 18,
/* 149 */ 153,
/* 150 */ 50268,
/* 151 */ -121,
/* 152 */ 19,
/* 153 */ 157,
/* 154 */ 50264,
/* 155 */ -121,
/* 156 */ 20,
/* 157 */ 161,
/* 158 */ 173,
/* 159 */ -121,
/* 160 */ 21,
/* 161 */ 0,
/* 162 */ 295,
/* 163 */ -121,
/* 164 */ 22,
/* 165 */ 169,
/* 166 */ 50260,
/* 167 */ -165,
/* 168 */ 23,
/* 169 */ 0,
/* 170 */ 50286,
/* 171 */ -165,
/* 172 */ 24,
/* 173 */ 181,
/* 174 */ 193,
/* 175 */ 186,
/* 176 */ 50123,
/* 177 */ 201,
/* 178 */ 50125,
/* 179 */ -173,
/* 180 */ 25,
/* 181 */ 0,
/* 182 */ 193,
/* 183 */ 1152,
/* 184 */ -173,
/* 185 */ 26,
/* 186 */ 190,
/* 187 */ 1152,
/* 188 */ -186,
/* 189 */ 139,
/* 190 */ 0,
/* 191 */ -186,
/* 192 */ 218,
/* 193 */ 197,
/* 194 */ 50280,
/* 195 */ -193,
/* 196 */ 27,
/* 197 */ 0,
/* 198 */ 50283,
/* 199 */ -193,
/* 200 */ 28,
/* 201 */ 0,
/* 202 */ 206,
/* 203 */ 239,
/* 204 */ -201,
/* 205 */ 29,
/* 206 */ 210,
/* 207 */ 201,
/* 208 */ -206,
/* 209 */ 140,
/* 210 */ 0,
/* 211 */ -206,
/* 212 */ 219,
/* 213 */ 0,
/* 214 */ 218,
/* 215 */ 226,
/* 216 */ -213,
/* 217 */ 30,
/* 218 */ 223,
/* 219 */ 213,
/* 220 */ 50044,
/* 221 */ -218,
/* 222 */ 141,
/* 223 */ 0,
/* 224 */ -218,
/* 225 */ 220,
/* 226 */ 0,
/* 227 */ 231,
/* 228 */ 491,
/* 229 */ -226,
/* 230 */ 31,
/* 231 */ 236,
/* 232 */ 341,
/* 233 */ 50061,
/* 234 */ -231,
/* 235 */ 142,
/* 236 */ 0,
/* 237 */ -231,
/* 238 */ 221,
/* 239 */ 0,
/* 240 */ 245,
/* 241 */ 265,
/* 242 */ 50059,
/* 243 */ -239,
/* 244 */ 32,
/* 245 */ 0,
/* 246 */ 250,
/* 247 */ 258,
/* 248 */ -245,
/* 249 */ 33,
/* 250 */ 254,
/* 251 */ 121,
/* 252 */ -250,
/* 253 */ 143,
/* 254 */ 0,
/* 255 */ 165,
/* 256 */ -250,
/* 257 */ 144,
/* 258 */ 262,
/* 259 */ 245,
/* 260 */ -258,
/* 261 */ 145,
/* 262 */ 0,
/* 263 */ -258,
/* 264 */ 222,
/* 265 */ 0,
/* 266 */ 270,
/* 267 */ 278,
/* 268 */ -265,
/* 269 */ 34,
/* 270 */ 275,
/* 271 */ 265,
/* 272 */ 50044,
/* 273 */ -270,
/* 274 */ 146,
/* 275 */ 0,
/* 276 */ -270,
/* 277 */ 223,
/* 278 */ 282,
/* 279 */ 341,
/* 280 */ -278,
/* 281 */ 35,
/* 282 */ 0,
/* 283 */ 288,
/* 284 */ 50058,
/* 285 */ 870,
/* 286 */ -278,
/* 287 */ 36,
/* 288 */ 292,
/* 289 */ 341,
/* 290 */ -288,
/* 291 */ 147,
/* 292 */ 0,
/* 293 */ -288,
/* 294 */ 224,
/* 295 */ 303,
/* 296 */ 50266,
/* 297 */ 308,
/* 298 */ 50123,
/* 299 */ 315,
/* 300 */ 50125,
/* 301 */ -295,
/* 302 */ 37,
/* 303 */ 0,
/* 304 */ 50266,
/* 305 */ 1152,
/* 306 */ -295,
/* 307 */ 38,
/* 308 */ 312,
/* 309 */ 1152,
/* 310 */ -308,
/* 311 */ 148,
/* 312 */ 0,
/* 313 */ -308,
/* 314 */ 225,
/* 315 */ 0,
/* 316 */ 320,
/* 317 */ 328,
/* 318 */ -315,
/* 319 */ 39,
/* 320 */ 325,
/* 321 */ 315,
/* 322 */ 50044,
/* 323 */ -320,
/* 324 */ 149,
/* 325 */ 0,
/* 326 */ -320,
/* 327 */ 226,
/* 328 */ 0,
/* 329 */ 1152,
/* 330 */ 333,
/* 331 */ -328,
/* 332 */ 40,
/* 333 */ 338,
/* 334 */ 50061,
/* 335 */ 870,
/* 336 */ -333,
/* 337 */ 150,
/* 338 */ 0,
/* 339 */ -333,
/* 340 */ 227,
/* 341 */ 0,
/* 342 */ 346,
/* 343 */ 353,
/* 344 */ -341,
/* 345 */ 41,
/* 346 */ 350,
/* 347 */ 400,
/* 348 */ -346,
/* 349 */ 151,
/* 350 */ 0,
/* 351 */ -346,
/* 352 */ 228,
/* 353 */ 357,
/* 354 */ 1152,
/* 355 */ -353,
/* 356 */ 42,
/* 357 */ 363,
/* 358 */ 50040,
/* 359 */ 341,
/* 360 */ 50041,
/* 361 */ -353,
/* 362 */ 43,
/* 363 */ 0,
/* 364 */ 353,
/* 365 */ 368,
/* 366 */ -353,
/* 367 */ 44,
/* 368 */ 374,
/* 369 */ 50091,
/* 370 */ 386,
/* 371 */ 50093,
/* 372 */ -368,
/* 373 */ 153,
/* 374 */ 380,
/* 375 */ 50040,
/* 376 */ 432,
/* 377 */ 50041,
/* 378 */ -368,
/* 379 */ 154,
/* 380 */ 0,
/* 381 */ 50040,
/* 382 */ 393,
/* 383 */ 50041,
/* 384 */ -368,
/* 385 */ 156,
/* 386 */ 390,
/* 387 */ 830,
/* 388 */ -386,
/* 389 */ 152,
/* 390 */ 0,
/* 391 */ -386,
/* 392 */ 229,
/* 393 */ 397,
/* 394 */ 478,
/* 395 */ -393,
/* 396 */ 155,
/* 397 */ 0,
/* 398 */ -393,
/* 399 */ 230,
/* 400 */ 0,
/* 401 */ 50042,
/* 402 */ 406,
/* 403 */ 413,
/* 404 */ -400,
/* 405 */ 45,
/* 406 */ 410,
/* 407 */ 420,
/* 408 */ -406,
/* 409 */ 157,
/* 410 */ 0,
/* 411 */ -406,
/* 412 */ 231,
/* 413 */ 417,
/* 414 */ 400,
/* 415 */ -413,
/* 416 */ 158,
/* 417 */ 0,
/* 418 */ -413,
/* 419 */ 232,
/* 420 */ 0,
/* 421 */ 425,
/* 422 */ 165,
/* 423 */ -420,
/* 424 */ 46,
/* 425 */ 429,
/* 426 */ 420,
/* 427 */ -425,
/* 428 */ 159,
/* 429 */ 0,
/* 430 */ -425,
/* 431 */ 233,
/* 432 */ 0,
/* 433 */ 445,
/* 434 */ 437,
/* 435 */ -432,
/* 436 */ 47,
/* 437 */ 442,
/* 438 */ 50044,
/* 439 */ 50290,
/* 440 */ -437,
/* 441 */ 160,
/* 442 */ 0,
/* 443 */ -437,
/* 444 */ 234,
/* 445 */ 0,
/* 446 */ 450,
/* 447 */ 458,
/* 448 */ -445,
/* 449 */ 48,
/* 450 */ 455,
/* 451 */ 445,
/* 452 */ 50044,
/* 453 */ -450,
/* 454 */ 161,
/* 455 */ 0,
/* 456 */ -450,
/* 457 */ 235,
/* 458 */ 0,
/* 459 */ 81,
/* 460 */ 463,
/* 461 */ -458,
/* 462 */ 49,
/* 463 */ 467,
/* 464 */ 341,
/* 465 */ -463,
/* 466 */ 162,
/* 467 */ 0,
/* 468 */ 471,
/* 469 */ -463,
/* 470 */ 164,
/* 471 */ 475,
/* 472 */ 534,
/* 473 */ -471,
/* 474 */ 163,
/* 475 */ 0,
/* 476 */ -471,
/* 477 */ 236,
/* 478 */ 0,
/* 479 */ 483,
/* 480 */ 1152,
/* 481 */ -478,
/* 482 */ 50,
/* 483 */ 488,
/* 484 */ 478,
/* 485 */ 50044,
/* 486 */ -483,
/* 487 */ 165,
/* 488 */ 0,
/* 489 */ -483,
/* 490 */ 237,
/* 491 */ 495,
/* 492 */ 840,
/* 493 */ -491,
/* 494 */ 51,
/* 495 */ 0,
/* 496 */ 50123,
/* 497 */ 509,
/* 498 */ 502,
/* 499 */ 50125,
/* 500 */ -491,
/* 501 */ 52,
/* 502 */ 506,
/* 503 */ 50044,
/* 504 */ -502,
/* 505 */ 166,
/* 506 */ 0,
/* 507 */ -502,
/* 508 */ 238,
/* 509 */ 0,
/* 510 */ 514,
/* 511 */ 491,
/* 512 */ -509,
/* 513 */ 53,
/* 514 */ 519,
/* 515 */ 509,
/* 516 */ 50044,
/* 517 */ -514,
/* 518 */ 167,
/* 519 */ 0,
/* 520 */ -514,
/* 521 */ 239,
/* 522 */ 0,
/* 523 */ 245,
/* 524 */ 527,
/* 525 */ -522,
/* 526 */ 54,
/* 527 */ 531,
/* 528 */ 534,
/* 529 */ -527,
/* 530 */ 168,
/* 531 */ 0,
/* 532 */ -527,
/* 533 */ 240,
/* 534 */ 538,
/* 535 */ 400,
/* 536 */ -534,
/* 537 */ 55,
/* 538 */ 0,
/* 539 */ 543,
/* 540 */ 550,
/* 541 */ -534,
/* 542 */ 56,
/* 543 */ 547,
/* 544 */ 400,
/* 545 */ -543,
/* 546 */ 169,
/* 547 */ 0,
/* 548 */ -543,
/* 549 */ 241,
/* 550 */ 556,
/* 551 */ 50040,
/* 552 */ 534,
/* 553 */ 50041,
/* 554 */ -550,
/* 555 */ 57,
/* 556 */ 0,
/* 557 */ 561,
/* 558 */ 568,
/* 559 */ -550,
/* 560 */ 58,
/* 561 */ 565,
/* 562 */ 550,
/* 563 */ -561,
/* 564 */ 170,
/* 565 */ 0,
/* 566 */ -561,
/* 567 */ 242,
/* 568 */ 574,
/* 569 */ 50091,
/* 570 */ 580,
/* 571 */ 50093,
/* 572 */ -568,
/* 573 */ 172,
/* 574 */ 0,
/* 575 */ 50040,
/* 576 */ 587,
/* 577 */ 50041,
/* 578 */ -568,
/* 579 */ 174,
/* 580 */ 584,
/* 581 */ 830,
/* 582 */ -580,
/* 583 */ 171,
/* 584 */ 0,
/* 585 */ -580,
/* 586 */ 243,
/* 587 */ 591,
/* 588 */ 432,
/* 589 */ -587,
/* 590 */ 173,
/* 591 */ 0,
/* 592 */ -587,
/* 593 */ 244,
/* 594 */ 0,
/* 595 */ 1152,
/* 596 */ -594,
/* 597 */ 59,
/* 598 */ 0,
/* 599 */ 602,
/* 600 */ -598,
/* 601 */ 60,
/* 602 */ 606,
/* 603 */ 634,
/* 604 */ -602,
/* 605 */ 175,
/* 606 */ 610,
/* 607 */ 653,
/* 608 */ -602,
/* 609 */ 176,
/* 610 */ 614,
/* 611 */ 665,
/* 612 */ -602,
/* 613 */ 177,
/* 614 */ 618,
/* 615 */ 699,
/* 616 */ -602,
/* 617 */ 178,
/* 618 */ 622,
/* 619 */ 724,
/* 620 */ -602,
/* 621 */ 179,
/* 622 */ 626,
/* 623 */ 779,
/* 624 */ -602,
/* 625 */ 180,
/* 626 */ 630,
/* 627 */ 808,
/* 628 */ -602,
/* 629 */ 181,
/* 630 */ 0,
/* 631 */ 814,
/* 632 */ -602,
/* 633 */ 182,
/* 634 */ 640,
/* 635 */ 1152,
/* 636 */ 50058,
/* 637 */ 598,
/* 638 */ -634,
/* 639 */ 61,
/* 640 */ 647,
/* 641 */ 50258,
/* 642 */ 870,
/* 643 */ 50058,
/* 644 */ 598,
/* 645 */ -634,
/* 646 */ 62,
/* 647 */ 0,
/* 648 */ 50262,
/* 649 */ 50058,
/* 650 */ 598,
/* 651 */ -634,
/* 652 */ 63,
/* 653 */ 0,
/* 654 */ 658,
/* 655 */ 50059,
/* 656 */ -653,
/* 657 */ 64,
/* 658 */ 662,
/* 659 */ 830,
/* 660 */ -658,
/* 661 */ 183,
/* 662 */ 0,
/* 663 */ -658,
/* 664 */ 245,
/* 665 */ 0,
/* 666 */ 50123,
/* 667 */ 672,
/* 668 */ 679,
/* 669 */ 50125,
/* 670 */ -665,
/* 671 */ 65,
/* 672 */ 676,
/* 673 */ 68,
/* 674 */ -672,
/* 675 */ 184,
/* 676 */ 0,
/* 677 */ -672,
/* 678 */ 246,
/* 679 */ 683,
/* 680 */ 686,
/* 681 */ -679,
/* 682 */ 185,
/* 683 */ 0,
/* 684 */ -679,
/* 685 */ 247,
/* 686 */ 0,
/* 687 */ 691,
/* 688 */ 598,
/* 689 */ -686,
/* 690 */ 66,
/* 691 */ 696,
/* 692 */ 598,
/* 693 */ 691,
/* 694 */ -691,
/* 695 */ 186,
/* 696 */ 0,
/* 697 */ -691,
/* 698 */ 248,
/* 699 */ 708,
/* 700 */ 50271,
/* 701 */ 50040,
/* 702 */ 830,
/* 703 */ 50041,
/* 704 */ 598,
/* 705 */ 716,
/* 706 */ -699,
/* 707 */ 67,
/* 708 */ 0,
/* 709 */ 50281,
/* 710 */ 50040,
/* 711 */ 830,
/* 712 */ 50041,
/* 713 */ 598,
/* 714 */ -699,
/* 715 */ 68,
/* 716 */ 721,
/* 717 */ 50265,
/* 718 */ 598,
/* 719 */ -716,
/* 720 */ 187,
/* 721 */ 0,
/* 722 */ -716,
/* 723 */ 249,
/* 724 */ 0,
/* 725 */ 728,
/* 726 */ -724,
/* 727 */ 69,
/* 728 */ 736,
/* 729 */ 50287,
/* 730 */ 50040,
/* 731 */ 830,
/* 732 */ 50041,
/* 733 */ 598,
/* 734 */ -728,
/* 735 */ 188,
/* 736 */ 746,
/* 737 */ 50263,
/* 738 */ 598,
/* 739 */ 50287,
/* 740 */ 50040,
/* 741 */ 830,
/* 742 */ 50041,
/* 743 */ 50059,
/* 744 */ -728,
/* 745 */ 189,
/* 746 */ 0,
/* 747 */ 50269,
/* 748 */ 50040,
/* 749 */ 758,
/* 750 */ 50059,
/* 751 */ 765,
/* 752 */ 50059,
/* 753 */ 772,
/* 754 */ 50041,
/* 755 */ 598,
/* 756 */ -728,
/* 757 */ 193,
/* 758 */ 762,
/* 759 */ 830,
/* 760 */ -758,
/* 761 */ 190,
/* 762 */ 0,
/* 763 */ -758,
/* 764 */ 250,
/* 765 */ 769,
/* 766 */ 830,
/* 767 */ -765,
/* 768 */ 191,
/* 769 */ 0,
/* 770 */ -765,
/* 771 */ 251,
/* 772 */ 776,
/* 773 */ 830,
/* 774 */ -772,
/* 775 */ 192,
/* 776 */ 0,
/* 777 */ -772,
/* 778 */ 252,
/* 779 */ 785,
/* 780 */ 50270,
/* 781 */ 1152,
/* 782 */ 50059,
/* 783 */ -779,
/* 784 */ 70,
/* 785 */ 790,
/* 786 */ 50261,
/* 787 */ 50059,
/* 788 */ -779,
/* 789 */ 71,
/* 790 */ 795,
/* 791 */ 50257,
/* 792 */ 50059,
/* 793 */ -779,
/* 794 */ 72,
/* 795 */ 0,
/* 796 */ 50275,
/* 797 */ 801,
/* 798 */ 50059,
/* 799 */ -779,
/* 800 */ 73,
/* 801 */ 805,
/* 802 */ 830,
/* 803 */ -801,
/* 804 */ 194,
/* 805 */ 0,
/* 806 */ -801,
/* 807 */ 253,
/* 808 */ 0,
/* 809 */ 50305,
/* 810 */ 1122,
/* 811 */ 50059,
/* 812 */ -808,
/* 813 */ 74,
/* 814 */ 0,
/* 815 */ 50306,
/* 816 */ 821,
/* 817 */ 1152,
/* 818 */ 50059,
/* 819 */ -814,
/* 820 */ 75,
/* 821 */ 827,
/* 822 */ 1152,
/* 823 */ 50044,
/* 824 */ 821,
/* 825 */ -821,
/* 826 */ 195,
/* 827 */ 0,
/* 828 */ -821,
/* 829 */ 254,
/* 830 */ 834,
/* 831 */ 840,
/* 832 */ -830,
/* 833 */ 76,
/* 834 */ 0,
/* 835 */ 830,
/* 836 */ 50044,
/* 837 */ 840,
/* 838 */ -830,
/* 839 */ 77,
/* 840 */ 844,
/* 841 */ 858,
/* 842 */ -840,
/* 843 */ 78,
/* 844 */ 0,
/* 845 */ 995,
/* 846 */ 850,
/* 847 */ 840,
/* 848 */ -840,
/* 849 */ 79,
/* 850 */ 854,
/* 851 */ 50291,
/* 852 */ -850,
/* 853 */ 80,
/* 854 */ 0,
/* 855 */ 50061,
/* 856 */ -850,
/* 857 */ 81,
/* 858 */ 862,
/* 859 */ 874,
/* 860 */ -858,
/* 861 */ 82,
/* 862 */ 0,
/* 863 */ 874,
/* 864 */ 50063,
/* 865 */ 830,
/* 866 */ 50058,
/* 867 */ 858,
/* 868 */ -858,
/* 869 */ 83,
/* 870 */ 0,
/* 871 */ 858,
/* 872 */ -870,
/* 873 */ 84,
/* 874 */ 878,
/* 875 */ 884,
/* 876 */ -874,
/* 877 */ 85,
/* 878 */ 0,
/* 879 */ 874,
/* 880 */ 50297,
/* 881 */ 884,
/* 882 */ -874,
/* 883 */ 86,
/* 884 */ 888,
/* 885 */ 894,
/* 886 */ -884,
/* 887 */ 87,
/* 888 */ 0,
/* 889 */ 884,
/* 890 */ 50298,
/* 891 */ 894,
/* 892 */ -884,
/* 893 */ 88,
/* 894 */ 898,
/* 895 */ 904,
/* 896 */ -894,
/* 897 */ 89,
/* 898 */ 0,
/* 899 */ 894,
/* 900 */ 50124,
/* 901 */ 904,
/* 902 */ -894,
/* 903 */ 90,
/* 904 */ 908,
/* 905 */ 914,
/* 906 */ -904,
/* 907 */ 91,
/* 908 */ 0,
/* 909 */ 904,
/* 910 */ 50094,
/* 911 */ 914,
/* 912 */ -904,
/* 913 */ 92,
/* 914 */ 918,
/* 915 */ 924,
/* 916 */ -914,
/* 917 */ 93,
/* 918 */ 0,
/* 919 */ 914,
/* 920 */ 50038,
/* 921 */ 924,
/* 922 */ -914,
/* 923 */ 94,
/* 924 */ 928,
/* 925 */ 934,
/* 926 */ -924,
/* 927 */ 95,
/* 928 */ 0,
/* 929 */ 924,
/* 930 */ 50292,
/* 931 */ 934,
/* 932 */ -924,
/* 933 */ 96,
/* 934 */ 938,
/* 935 */ 944,
/* 936 */ -934,
/* 937 */ 97,
/* 938 */ 0,
/* 939 */ 934,
/* 940 */ 50300,
/* 941 */ 944,
/* 942 */ -934,
/* 943 */ 98,
/* 944 */ 948,
/* 945 */ 962,
/* 946 */ -944,
/* 947 */ 99,
/* 948 */ 0,
/* 949 */ 944,
/* 950 */ 954,
/* 951 */ 962,
/* 952 */ -944,
/* 953 */ 100,
/* 954 */ 958,
/* 955 */ 50043,
/* 956 */ -954,
/* 957 */ 196,
/* 958 */ 0,
/* 959 */ 50045,
/* 960 */ -954,
/* 961 */ 197,
/* 962 */ 966,
/* 963 */ 984,
/* 964 */ -962,
/* 965 */ 101,
/* 966 */ 0,
/* 967 */ 962,
/* 968 */ 972,
/* 969 */ 984,
/* 970 */ -962,
/* 971 */ 102,
/* 972 */ 976,
/* 973 */ 50042,
/* 974 */ -972,
/* 975 */ 198,
/* 976 */ 980,
/* 977 */ 50047,
/* 978 */ -972,
/* 979 */ 199,
/* 980 */ 0,
/* 981 */ 50037,
/* 982 */ -972,
/* 983 */ 200,
/* 984 */ 988,
/* 985 */ 995,
/* 986 */ -984,
/* 987 */ 103,
/* 988 */ 0,
/* 989 */ 50040,
/* 990 */ 522,
/* 991 */ 50041,
/* 992 */ 984,
/* 993 */ -984,
/* 994 */ 104,
/* 995 */ 999,
/* 996 */ 1053,
/* 997 */ -995,
/* 998 */ 105,
/* 999 */ 1004,
/* 1000 */ 1021,
/* 1001 */ 995,
/* 1002 */ -995,
/* 1003 */ 106,
/* 1004 */ 1009,
/* 1005 */ 1029,
/* 1006 */ 984,
/* 1007 */ -995,
/* 1008 */ 107,
/* 1009 */ 1014,
/* 1010 */ 50278,
/* 1011 */ 995,
/* 1012 */ -995,
/* 1013 */ 108,
/* 1014 */ 0,
/* 1015 */ 50278,
/* 1016 */ 50040,
/* 1017 */ 522,
/* 1018 */ 50041,
/* 1019 */ -995,
/* 1020 */ 109,
/* 1021 */ 1025,
/* 1022 */ 50294,
/* 1023 */ -1021,
/* 1024 */ 201,
/* 1025 */ 0,
/* 1026 */ 50295,
/* 1027 */ -1021,
/* 1028 */ 202,
/* 1029 */ 1033,
/* 1030 */ 50038,
/* 1031 */ -1029,
/* 1032 */ 110,
/* 1033 */ 1037,
/* 1034 */ 50042,
/* 1035 */ -1029,
/* 1036 */ 111,
/* 1037 */ 1041,
/* 1038 */ 50043,
/* 1039 */ -1029,
/* 1040 */ 112,
/* 1041 */ 1045,
/* 1042 */ 50045,
/* 1043 */ -1029,
/* 1044 */ 113,
/* 1045 */ 1049,
/* 1046 */ 50126,
/* 1047 */ -1029,
/* 1048 */ 114,
/* 1049 */ 0,
/* 1050 */ 50033,
/* 1051 */ -1029,
/* 1052 */ 115,
/* 1053 */ 1057,
/* 1054 */ 1108,
/* 1055 */ -1053,
/* 1056 */ 116,
/* 1057 */ 0,
/* 1058 */ 1053,
/* 1059 */ 1062,
/* 1060 */ -1053,
/* 1061 */ 117,
/* 1062 */ 1069,
/* 1063 */ 50091,
/* 1064 */ 830,
/* 1065 */ 1093,
/* 1066 */ 50093,
/* 1067 */ -1062,
/* 1068 */ 204,
/* 1069 */ 1075,
/* 1070 */ 50040,
/* 1071 */ 1101,
/* 1072 */ 50041,
/* 1073 */ -1062,
/* 1074 */ 206,
/* 1075 */ 1080,
/* 1076 */ 50046,
/* 1077 */ 1152,
/* 1078 */ -1062,
/* 1079 */ 207,
/* 1080 */ 1085,
/* 1081 */ 50296,
/* 1082 */ 1152,
/* 1083 */ -1062,
/* 1084 */ 208,
/* 1085 */ 1089,
/* 1086 */ 50294,
/* 1087 */ -1062,
/* 1088 */ 209,
/* 1089 */ 0,
/* 1090 */ 50295,
/* 1091 */ -1062,
/* 1092 */ 210,
/* 1093 */ 1098,
/* 1094 */ 50058,
/* 1095 */ 830,
/* 1096 */ -1093,
/* 1097 */ 203,
/* 1098 */ 0,
/* 1099 */ -1093,
/* 1100 */ 255,
/* 1101 */ 1105,
/* 1102 */ 1122,
/* 1103 */ -1101,
/* 1104 */ 205,
/* 1105 */ 0,
/* 1106 */ -1101,
/* 1107 */ 256,
/* 1108 */ 1112,
/* 1109 */ 1152,
/* 1110 */ -1108,
/* 1111 */ 118,
/* 1112 */ 1116,
/* 1113 */ 1136,
/* 1114 */ -1108,
/* 1115 */ 119,
/* 1116 */ 0,
/* 1117 */ 50040,
/* 1118 */ 830,
/* 1119 */ 50041,
/* 1120 */ -1108,
/* 1121 */ 120,
/* 1122 */ 0,
/* 1123 */ 1127,
/* 1124 */ 840,
/* 1125 */ -1122,
/* 1126 */ 121,
/* 1127 */ 1133,
/* 1128 */ 840,
/* 1129 */ 50044,
/* 1130 */ 1127,
/* 1131 */ -1127,
/* 1132 */ 211,
/* 1133 */ 0,
/* 1134 */ -1127,
/* 1135 */ 257,
/* 1136 */ 1140,
/* 1137 */ 50304,
/* 1138 */ -1136,
/* 1139 */ 122,
/* 1140 */ 1144,
/* 1141 */ 50302,
/* 1142 */ -1136,
/* 1143 */ 123,
/* 1144 */ 1148,
/* 1145 */ 50303,
/* 1146 */ -1136,
/* 1147 */ 124,
/* 1148 */ 0,
/* 1149 */ 50289,
/* 1150 */ -1136,
/* 1151 */ 125,
/* 1152 */ 0,
/* 1153 */ 50299,
/* 1154 */ -1152,
/* 1155 */ 126,
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
/* 117 */ 0,
/* 118 */ 50267,
/* 119 */ -105,
/* 120 */ 4,
/* 121 */ 125,
/* 122 */ 50285,
/* 123 */ -121,
/* 124 */ 1,
/* 125 */ 129,
/* 126 */ 50277,
/* 127 */ -121,
/* 128 */ 2,
/* 129 */ 133,
/* 130 */ 50284,
/* 131 */ -121,
/* 132 */ 3,
/* 133 */ 137,
/* 134 */ 50276,
/* 135 */ -121,
/* 136 */ 4,
/* 137 */ 141,
/* 138 */ 50273,
/* 139 */ -121,
/* 140 */ 5,
/* 141 */ 145,
/* 142 */ 50272,
/* 143 */ -121,
/* 144 */ 6,
/* 145 */ 149,
/* 146 */ 50259,
/* 147 */ -121,
/* 148 */ 7,
/* 149 */ 153,
/* 150 */ 50268,
/* 151 */ -121,
/* 152 */ 8,
/* 153 */ 157,
/* 154 */ 50264,
/* 155 */ -121,
/* 156 */ 9,
/* 157 */ 161,
/* 158 */ 1,
/* 159 */ -121,
/* 160 */ 10,
/* 161 */ 0,
/* 162 */ 1,
/* 163 */ -121,
/* 164 */ 11,
/* 165 */ 169,
/* 166 */ 50260,
/* 167 */ -165,
/* 168 */ 1,
/* 169 */ 0,
/* 170 */ 50286,
/* 171 */ -165,
/* 172 */ 2,
/* 173 */ 181,
/* 174 */ 1,
/* 175 */ 1,
/* 176 */ 50123,
/* 177 */ 1,
/* 178 */ 50125,
/* 179 */ -173,
/* 180 */ 1,
/* 181 */ 0,
/* 182 */ 1,
/* 183 */ 1,
/* 184 */ -173,
/* 185 */ 2,
/* 186 */ 190,
/* 187 */ 1,
/* 188 */ -186,
/* 189 */ 1,
/* 190 */ 0,
/* 191 */ -186,
/* 192 */ 2,
/* 193 */ 197,
/* 194 */ 50280,
/* 195 */ -193,
/* 196 */ 1,
/* 197 */ 0,
/* 198 */ 50283,
/* 199 */ -193,
/* 200 */ 2,
/* 201 */ 0,
/* 202 */ 1,
/* 203 */ 1,
/* 204 */ -201,
/* 205 */ 1,
/* 206 */ 210,
/* 207 */ 1,
/* 208 */ -206,
/* 209 */ 1,
/* 210 */ 0,
/* 211 */ -206,
/* 212 */ 2,
/* 213 */ 0,
/* 214 */ 1,
/* 215 */ 1,
/* 216 */ -213,
/* 217 */ 1,
/* 218 */ 223,
/* 219 */ 1,
/* 220 */ 50044,
/* 221 */ -218,
/* 222 */ 1,
/* 223 */ 0,
/* 224 */ -218,
/* 225 */ 2,
/* 226 */ 0,
/* 227 */ 1,
/* 228 */ 1,
/* 229 */ -226,
/* 230 */ 1,
/* 231 */ 236,
/* 232 */ 1,
/* 233 */ 50061,
/* 234 */ -231,
/* 235 */ 1,
/* 236 */ 0,
/* 237 */ -231,
/* 238 */ 2,
/* 239 */ 0,
/* 240 */ 1,
/* 241 */ 1,
/* 242 */ 50059,
/* 243 */ -239,
/* 244 */ 1,
/* 245 */ 0,
/* 246 */ 1,
/* 247 */ 1,
/* 248 */ -245,
/* 249 */ 1,
/* 250 */ 254,
/* 251 */ 1,
/* 252 */ -250,
/* 253 */ 1,
/* 254 */ 0,
/* 255 */ 1,
/* 256 */ -250,
/* 257 */ 2,
/* 258 */ 262,
/* 259 */ 1,
/* 260 */ -258,
/* 261 */ 1,
/* 262 */ 0,
/* 263 */ -258,
/* 264 */ 2,
/* 265 */ 0,
/* 266 */ 1,
/* 267 */ 1,
/* 268 */ -265,
/* 269 */ 1,
/* 270 */ 275,
/* 271 */ 1,
/* 272 */ 50044,
/* 273 */ -270,
/* 274 */ 1,
/* 275 */ 0,
/* 276 */ -270,
/* 277 */ 2,
/* 278 */ 282,
/* 279 */ 1,
/* 280 */ -278,
/* 281 */ 1,
/* 282 */ 0,
/* 283 */ 1,
/* 284 */ 50058,
/* 285 */ 1,
/* 286 */ -278,
/* 287 */ 2,
/* 288 */ 292,
/* 289 */ 1,
/* 290 */ -288,
/* 291 */ 1,
/* 292 */ 0,
/* 293 */ -288,
/* 294 */ 2,
/* 295 */ 303,
/* 296 */ 50266,
/* 297 */ 1,
/* 298 */ 50123,
/* 299 */ 1,
/* 300 */ 50125,
/* 301 */ -295,
/* 302 */ 1,
/* 303 */ 0,
/* 304 */ 50266,
/* 305 */ 1,
/* 306 */ -295,
/* 307 */ 2,
/* 308 */ 312,
/* 309 */ 1,
/* 310 */ -308,
/* 311 */ 1,
/* 312 */ 0,
/* 313 */ -308,
/* 314 */ 2,
/* 315 */ 0,
/* 316 */ 1,
/* 317 */ 1,
/* 318 */ -315,
/* 319 */ 1,
/* 320 */ 325,
/* 321 */ 1,
/* 322 */ 50044,
/* 323 */ -320,
/* 324 */ 1,
/* 325 */ 0,
/* 326 */ -320,
/* 327 */ 2,
/* 328 */ 0,
/* 329 */ 1,
/* 330 */ 1,
/* 331 */ -328,
/* 332 */ 1,
/* 333 */ 338,
/* 334 */ 50061,
/* 335 */ 1,
/* 336 */ -333,
/* 337 */ 1,
/* 338 */ 0,
/* 339 */ -333,
/* 340 */ 2,
/* 341 */ 0,
/* 342 */ 1,
/* 343 */ 1,
/* 344 */ -341,
/* 345 */ 1,
/* 346 */ 350,
/* 347 */ 1,
/* 348 */ -346,
/* 349 */ 1,
/* 350 */ 0,
/* 351 */ -346,
/* 352 */ 2,
/* 353 */ 357,
/* 354 */ 1,
/* 355 */ -353,
/* 356 */ 1,
/* 357 */ 363,
/* 358 */ 50040,
/* 359 */ 1,
/* 360 */ 50041,
/* 361 */ -353,
/* 362 */ 2,
/* 363 */ 0,
/* 364 */ 1,
/* 365 */ 1,
/* 366 */ -353,
/* 367 */ 3,
/* 368 */ 374,
/* 369 */ 50091,
/* 370 */ 1,
/* 371 */ 50093,
/* 372 */ -368,
/* 373 */ 1,
/* 374 */ 380,
/* 375 */ 50040,
/* 376 */ 1,
/* 377 */ 50041,
/* 378 */ -368,
/* 379 */ 2,
/* 380 */ 0,
/* 381 */ 50040,
/* 382 */ 1,
/* 383 */ 50041,
/* 384 */ -368,
/* 385 */ 3,
/* 386 */ 390,
/* 387 */ 1,
/* 388 */ -386,
/* 389 */ 1,
/* 390 */ 0,
/* 391 */ -386,
/* 392 */ 2,
/* 393 */ 397,
/* 394 */ 1,
/* 395 */ -393,
/* 396 */ 1,
/* 397 */ 0,
/* 398 */ -393,
/* 399 */ 2,
/* 400 */ 0,
/* 401 */ 50042,
/* 402 */ 1,
/* 403 */ 1,
/* 404 */ -400,
/* 405 */ 1,
/* 406 */ 410,
/* 407 */ 1,
/* 408 */ -406,
/* 409 */ 1,
/* 410 */ 0,
/* 411 */ -406,
/* 412 */ 2,
/* 413 */ 417,
/* 414 */ 1,
/* 415 */ -413,
/* 416 */ 1,
/* 417 */ 0,
/* 418 */ -413,
/* 419 */ 2,
/* 420 */ 0,
/* 421 */ 1,
/* 422 */ 1,
/* 423 */ -420,
/* 424 */ 1,
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
/* 437 */ 442,
/* 438 */ 50044,
/* 439 */ 50290,
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
/* 450 */ 455,
/* 451 */ 1,
/* 452 */ 50044,
/* 453 */ -450,
/* 454 */ 1,
/* 455 */ 0,
/* 456 */ -450,
/* 457 */ 2,
/* 458 */ 0,
/* 459 */ 1,
/* 460 */ 1,
/* 461 */ -458,
/* 462 */ 1,
/* 463 */ 467,
/* 464 */ 1,
/* 465 */ -463,
/* 466 */ 1,
/* 467 */ 0,
/* 468 */ 1,
/* 469 */ -463,
/* 470 */ 2,
/* 471 */ 475,
/* 472 */ 1,
/* 473 */ -471,
/* 474 */ 1,
/* 475 */ 0,
/* 476 */ -471,
/* 477 */ 2,
/* 478 */ 0,
/* 479 */ 1,
/* 480 */ 1,
/* 481 */ -478,
/* 482 */ 1,
/* 483 */ 488,
/* 484 */ 1,
/* 485 */ 50044,
/* 486 */ -483,
/* 487 */ 1,
/* 488 */ 0,
/* 489 */ -483,
/* 490 */ 2,
/* 491 */ 495,
/* 492 */ 1,
/* 493 */ -491,
/* 494 */ 1,
/* 495 */ 0,
/* 496 */ 50123,
/* 497 */ 1,
/* 498 */ 1,
/* 499 */ 50125,
/* 500 */ -491,
/* 501 */ 2,
/* 502 */ 506,
/* 503 */ 50044,
/* 504 */ -502,
/* 505 */ 1,
/* 506 */ 0,
/* 507 */ -502,
/* 508 */ 2,
/* 509 */ 0,
/* 510 */ 1,
/* 511 */ 1,
/* 512 */ -509,
/* 513 */ 1,
/* 514 */ 519,
/* 515 */ 1,
/* 516 */ 50044,
/* 517 */ -514,
/* 518 */ 1,
/* 519 */ 0,
/* 520 */ -514,
/* 521 */ 2,
/* 522 */ 0,
/* 523 */ 1,
/* 524 */ 1,
/* 525 */ -522,
/* 526 */ 1,
/* 527 */ 531,
/* 528 */ 1,
/* 529 */ -527,
/* 530 */ 1,
/* 531 */ 0,
/* 532 */ -527,
/* 533 */ 2,
/* 534 */ 538,
/* 535 */ 1,
/* 536 */ -534,
/* 537 */ 1,
/* 538 */ 0,
/* 539 */ 1,
/* 540 */ 1,
/* 541 */ -534,
/* 542 */ 2,
/* 543 */ 547,
/* 544 */ 1,
/* 545 */ -543,
/* 546 */ 1,
/* 547 */ 0,
/* 548 */ -543,
/* 549 */ 2,
/* 550 */ 556,
/* 551 */ 50040,
/* 552 */ 1,
/* 553 */ 50041,
/* 554 */ -550,
/* 555 */ 1,
/* 556 */ 0,
/* 557 */ 1,
/* 558 */ 1,
/* 559 */ -550,
/* 560 */ 2,
/* 561 */ 565,
/* 562 */ 1,
/* 563 */ -561,
/* 564 */ 1,
/* 565 */ 0,
/* 566 */ -561,
/* 567 */ 2,
/* 568 */ 574,
/* 569 */ 50091,
/* 570 */ 1,
/* 571 */ 50093,
/* 572 */ -568,
/* 573 */ 1,
/* 574 */ 0,
/* 575 */ 50040,
/* 576 */ 1,
/* 577 */ 50041,
/* 578 */ -568,
/* 579 */ 2,
/* 580 */ 584,
/* 581 */ 1,
/* 582 */ -580,
/* 583 */ 1,
/* 584 */ 0,
/* 585 */ -580,
/* 586 */ 2,
/* 587 */ 591,
/* 588 */ 1,
/* 589 */ -587,
/* 590 */ 1,
/* 591 */ 0,
/* 592 */ -587,
/* 593 */ 2,
/* 594 */ 0,
/* 595 */ 1,
/* 596 */ -594,
/* 597 */ 1,
/* 598 */ 0,
/* 599 */ 1,
/* 600 */ -598,
/* 601 */ 1,
/* 602 */ 606,
/* 603 */ 1,
/* 604 */ -602,
/* 605 */ 1,
/* 606 */ 610,
/* 607 */ 1,
/* 608 */ -602,
/* 609 */ 2,
/* 610 */ 614,
/* 611 */ 1,
/* 612 */ -602,
/* 613 */ 3,
/* 614 */ 618,
/* 615 */ 1,
/* 616 */ -602,
/* 617 */ 4,
/* 618 */ 622,
/* 619 */ 1,
/* 620 */ -602,
/* 621 */ 5,
/* 622 */ 626,
/* 623 */ 1,
/* 624 */ -602,
/* 625 */ 6,
/* 626 */ 630,
/* 627 */ 1,
/* 628 */ -602,
/* 629 */ 7,
/* 630 */ 0,
/* 631 */ 1,
/* 632 */ -602,
/* 633 */ 8,
/* 634 */ 640,
/* 635 */ 1,
/* 636 */ 50058,
/* 637 */ 1,
/* 638 */ -634,
/* 639 */ 1,
/* 640 */ 647,
/* 641 */ 50258,
/* 642 */ 1,
/* 643 */ 50058,
/* 644 */ 1,
/* 645 */ -634,
/* 646 */ 2,
/* 647 */ 0,
/* 648 */ 50262,
/* 649 */ 50058,
/* 650 */ 1,
/* 651 */ -634,
/* 652 */ 3,
/* 653 */ 0,
/* 654 */ 1,
/* 655 */ 50059,
/* 656 */ -653,
/* 657 */ 1,
/* 658 */ 662,
/* 659 */ 1,
/* 660 */ -658,
/* 661 */ 1,
/* 662 */ 0,
/* 663 */ -658,
/* 664 */ 2,
/* 665 */ 0,
/* 666 */ 50123,
/* 667 */ 1,
/* 668 */ 1,
/* 669 */ 50125,
/* 670 */ -665,
/* 671 */ 1,
/* 672 */ 676,
/* 673 */ 1,
/* 674 */ -672,
/* 675 */ 1,
/* 676 */ 0,
/* 677 */ -672,
/* 678 */ 2,
/* 679 */ 683,
/* 680 */ 1,
/* 681 */ -679,
/* 682 */ 1,
/* 683 */ 0,
/* 684 */ -679,
/* 685 */ 2,
/* 686 */ 0,
/* 687 */ 1,
/* 688 */ 1,
/* 689 */ -686,
/* 690 */ 1,
/* 691 */ 696,
/* 692 */ 1,
/* 693 */ 1,
/* 694 */ -691,
/* 695 */ 1,
/* 696 */ 0,
/* 697 */ -691,
/* 698 */ 2,
/* 699 */ 708,
/* 700 */ 50271,
/* 701 */ 50040,
/* 702 */ 1,
/* 703 */ 50041,
/* 704 */ 1,
/* 705 */ 1,
/* 706 */ -699,
/* 707 */ 1,
/* 708 */ 0,
/* 709 */ 50281,
/* 710 */ 50040,
/* 711 */ 1,
/* 712 */ 50041,
/* 713 */ 1,
/* 714 */ -699,
/* 715 */ 2,
/* 716 */ 721,
/* 717 */ 50265,
/* 718 */ 1,
/* 719 */ -716,
/* 720 */ 1,
/* 721 */ 0,
/* 722 */ -716,
/* 723 */ 2,
/* 724 */ 0,
/* 725 */ 1,
/* 726 */ -724,
/* 727 */ 1,
/* 728 */ 736,
/* 729 */ 50287,
/* 730 */ 50040,
/* 731 */ 1,
/* 732 */ 50041,
/* 733 */ 1,
/* 734 */ -728,
/* 735 */ 1,
/* 736 */ 746,
/* 737 */ 50263,
/* 738 */ 1,
/* 739 */ 50287,
/* 740 */ 50040,
/* 741 */ 1,
/* 742 */ 50041,
/* 743 */ 50059,
/* 744 */ -728,
/* 745 */ 2,
/* 746 */ 0,
/* 747 */ 50269,
/* 748 */ 50040,
/* 749 */ 1,
/* 750 */ 50059,
/* 751 */ 1,
/* 752 */ 50059,
/* 753 */ 1,
/* 754 */ 50041,
/* 755 */ 1,
/* 756 */ -728,
/* 757 */ 3,
/* 758 */ 762,
/* 759 */ 1,
/* 760 */ -758,
/* 761 */ 1,
/* 762 */ 0,
/* 763 */ -758,
/* 764 */ 2,
/* 765 */ 769,
/* 766 */ 1,
/* 767 */ -765,
/* 768 */ 1,
/* 769 */ 0,
/* 770 */ -765,
/* 771 */ 2,
/* 772 */ 776,
/* 773 */ 1,
/* 774 */ -772,
/* 775 */ 1,
/* 776 */ 0,
/* 777 */ -772,
/* 778 */ 2,
/* 779 */ 785,
/* 780 */ 50270,
/* 781 */ 1,
/* 782 */ 50059,
/* 783 */ -779,
/* 784 */ 1,
/* 785 */ 790,
/* 786 */ 50261,
/* 787 */ 50059,
/* 788 */ -779,
/* 789 */ 2,
/* 790 */ 795,
/* 791 */ 50257,
/* 792 */ 50059,
/* 793 */ -779,
/* 794 */ 3,
/* 795 */ 0,
/* 796 */ 50275,
/* 797 */ 1,
/* 798 */ 50059,
/* 799 */ -779,
/* 800 */ 4,
/* 801 */ 805,
/* 802 */ 1,
/* 803 */ -801,
/* 804 */ 1,
/* 805 */ 0,
/* 806 */ -801,
/* 807 */ 2,
/* 808 */ 0,
/* 809 */ 50305,
/* 810 */ 1,
/* 811 */ 50059,
/* 812 */ -808,
/* 813 */ 1,
/* 814 */ 0,
/* 815 */ 50306,
/* 816 */ 1,
/* 817 */ 1,
/* 818 */ 50059,
/* 819 */ -814,
/* 820 */ 1,
/* 821 */ 827,
/* 822 */ 1,
/* 823 */ 50044,
/* 824 */ 1,
/* 825 */ -821,
/* 826 */ 1,
/* 827 */ 0,
/* 828 */ -821,
/* 829 */ 2,
/* 830 */ 834,
/* 831 */ 1,
/* 832 */ -830,
/* 833 */ 1,
/* 834 */ 0,
/* 835 */ 1,
/* 836 */ 50044,
/* 837 */ 1,
/* 838 */ -830,
/* 839 */ 2,
/* 840 */ 844,
/* 841 */ 1,
/* 842 */ -840,
/* 843 */ 1,
/* 844 */ 0,
/* 845 */ 1,
/* 846 */ 1,
/* 847 */ 1,
/* 848 */ -840,
/* 849 */ 2,
/* 850 */ 854,
/* 851 */ 50291,
/* 852 */ -850,
/* 853 */ 1,
/* 854 */ 0,
/* 855 */ 50061,
/* 856 */ -850,
/* 857 */ 2,
/* 858 */ 862,
/* 859 */ 1,
/* 860 */ -858,
/* 861 */ 1,
/* 862 */ 0,
/* 863 */ 1,
/* 864 */ 50063,
/* 865 */ 1,
/* 866 */ 50058,
/* 867 */ 1,
/* 868 */ -858,
/* 869 */ 2,
/* 870 */ 0,
/* 871 */ 1,
/* 872 */ -870,
/* 873 */ 1,
/* 874 */ 878,
/* 875 */ 1,
/* 876 */ -874,
/* 877 */ 1,
/* 878 */ 0,
/* 879 */ 1,
/* 880 */ 50297,
/* 881 */ 1,
/* 882 */ -874,
/* 883 */ 2,
/* 884 */ 888,
/* 885 */ 1,
/* 886 */ -884,
/* 887 */ 1,
/* 888 */ 0,
/* 889 */ 1,
/* 890 */ 50298,
/* 891 */ 1,
/* 892 */ -884,
/* 893 */ 2,
/* 894 */ 898,
/* 895 */ 1,
/* 896 */ -894,
/* 897 */ 1,
/* 898 */ 0,
/* 899 */ 1,
/* 900 */ 50124,
/* 901 */ 1,
/* 902 */ -894,
/* 903 */ 2,
/* 904 */ 908,
/* 905 */ 1,
/* 906 */ -904,
/* 907 */ 1,
/* 908 */ 0,
/* 909 */ 1,
/* 910 */ 50094,
/* 911 */ 1,
/* 912 */ -904,
/* 913 */ 2,
/* 914 */ 918,
/* 915 */ 1,
/* 916 */ -914,
/* 917 */ 1,
/* 918 */ 0,
/* 919 */ 1,
/* 920 */ 50038,
/* 921 */ 1,
/* 922 */ -914,
/* 923 */ 2,
/* 924 */ 928,
/* 925 */ 1,
/* 926 */ -924,
/* 927 */ 1,
/* 928 */ 0,
/* 929 */ 1,
/* 930 */ 50292,
/* 931 */ 1,
/* 932 */ -924,
/* 933 */ 2,
/* 934 */ 938,
/* 935 */ 1,
/* 936 */ -934,
/* 937 */ 1,
/* 938 */ 0,
/* 939 */ 1,
/* 940 */ 50300,
/* 941 */ 1,
/* 942 */ -934,
/* 943 */ 2,
/* 944 */ 948,
/* 945 */ 1,
/* 946 */ -944,
/* 947 */ 1,
/* 948 */ 0,
/* 949 */ 1,
/* 950 */ 1,
/* 951 */ 1,
/* 952 */ -944,
/* 953 */ 2,
/* 954 */ 958,
/* 955 */ 50043,
/* 956 */ -954,
/* 957 */ 1,
/* 958 */ 0,
/* 959 */ 50045,
/* 960 */ -954,
/* 961 */ 2,
/* 962 */ 966,
/* 963 */ 1,
/* 964 */ -962,
/* 965 */ 1,
/* 966 */ 0,
/* 967 */ 1,
/* 968 */ 1,
/* 969 */ 1,
/* 970 */ -962,
/* 971 */ 2,
/* 972 */ 976,
/* 973 */ 50042,
/* 974 */ -972,
/* 975 */ 1,
/* 976 */ 980,
/* 977 */ 50047,
/* 978 */ -972,
/* 979 */ 2,
/* 980 */ 0,
/* 981 */ 50037,
/* 982 */ -972,
/* 983 */ 3,
/* 984 */ 988,
/* 985 */ 1,
/* 986 */ -984,
/* 987 */ 1,
/* 988 */ 0,
/* 989 */ 50040,
/* 990 */ 1,
/* 991 */ 50041,
/* 992 */ 1,
/* 993 */ -984,
/* 994 */ 2,
/* 995 */ 999,
/* 996 */ 1,
/* 997 */ -995,
/* 998 */ 1,
/* 999 */ 1004,
/* 1000 */ 1,
/* 1001 */ 1,
/* 1002 */ -995,
/* 1003 */ 2,
/* 1004 */ 1009,
/* 1005 */ 1,
/* 1006 */ 1,
/* 1007 */ -995,
/* 1008 */ 3,
/* 1009 */ 1014,
/* 1010 */ 50278,
/* 1011 */ 1,
/* 1012 */ -995,
/* 1013 */ 4,
/* 1014 */ 0,
/* 1015 */ 50278,
/* 1016 */ 50040,
/* 1017 */ 1,
/* 1018 */ 50041,
/* 1019 */ -995,
/* 1020 */ 5,
/* 1021 */ 1025,
/* 1022 */ 50294,
/* 1023 */ -1021,
/* 1024 */ 1,
/* 1025 */ 0,
/* 1026 */ 50295,
/* 1027 */ -1021,
/* 1028 */ 2,
/* 1029 */ 1033,
/* 1030 */ 50038,
/* 1031 */ -1029,
/* 1032 */ 1,
/* 1033 */ 1037,
/* 1034 */ 50042,
/* 1035 */ -1029,
/* 1036 */ 2,
/* 1037 */ 1041,
/* 1038 */ 50043,
/* 1039 */ -1029,
/* 1040 */ 3,
/* 1041 */ 1045,
/* 1042 */ 50045,
/* 1043 */ -1029,
/* 1044 */ 4,
/* 1045 */ 1049,
/* 1046 */ 50126,
/* 1047 */ -1029,
/* 1048 */ 5,
/* 1049 */ 0,
/* 1050 */ 50033,
/* 1051 */ -1029,
/* 1052 */ 6,
/* 1053 */ 1057,
/* 1054 */ 1,
/* 1055 */ -1053,
/* 1056 */ 1,
/* 1057 */ 0,
/* 1058 */ 1,
/* 1059 */ 1,
/* 1060 */ -1053,
/* 1061 */ 2,
/* 1062 */ 1069,
/* 1063 */ 50091,
/* 1064 */ 1,
/* 1065 */ 1,
/* 1066 */ 50093,
/* 1067 */ -1062,
/* 1068 */ 1,
/* 1069 */ 1075,
/* 1070 */ 50040,
/* 1071 */ 1,
/* 1072 */ 50041,
/* 1073 */ -1062,
/* 1074 */ 2,
/* 1075 */ 1080,
/* 1076 */ 50046,
/* 1077 */ 1,
/* 1078 */ -1062,
/* 1079 */ 3,
/* 1080 */ 1085,
/* 1081 */ 50296,
/* 1082 */ 1,
/* 1083 */ -1062,
/* 1084 */ 4,
/* 1085 */ 1089,
/* 1086 */ 50294,
/* 1087 */ -1062,
/* 1088 */ 5,
/* 1089 */ 0,
/* 1090 */ 50295,
/* 1091 */ -1062,
/* 1092 */ 6,
/* 1093 */ 1098,
/* 1094 */ 50058,
/* 1095 */ 1,
/* 1096 */ -1093,
/* 1097 */ 1,
/* 1098 */ 0,
/* 1099 */ -1093,
/* 1100 */ 2,
/* 1101 */ 1105,
/* 1102 */ 1,
/* 1103 */ -1101,
/* 1104 */ 1,
/* 1105 */ 0,
/* 1106 */ -1101,
/* 1107 */ 2,
/* 1108 */ 1112,
/* 1109 */ 1,
/* 1110 */ -1108,
/* 1111 */ 1,
/* 1112 */ 1116,
/* 1113 */ 1,
/* 1114 */ -1108,
/* 1115 */ 2,
/* 1116 */ 0,
/* 1117 */ 50040,
/* 1118 */ 1,
/* 1119 */ 50041,
/* 1120 */ -1108,
/* 1121 */ 3,
/* 1122 */ 0,
/* 1123 */ 1,
/* 1124 */ 1,
/* 1125 */ -1122,
/* 1126 */ 1,
/* 1127 */ 1133,
/* 1128 */ 1,
/* 1129 */ 50044,
/* 1130 */ 1,
/* 1131 */ -1127,
/* 1132 */ 1,
/* 1133 */ 0,
/* 1134 */ -1127,
/* 1135 */ 2,
/* 1136 */ 1140,
/* 1137 */ 50304,
/* 1138 */ -1136,
/* 1139 */ 1,
/* 1140 */ 1144,
/* 1141 */ 50302,
/* 1142 */ -1136,
/* 1143 */ 2,
/* 1144 */ 1148,
/* 1145 */ 50303,
/* 1146 */ -1136,
/* 1147 */ 3,
/* 1148 */ 0,
/* 1149 */ 50289,
/* 1150 */ -1136,
/* 1151 */ 4,
/* 1152 */ 0,
/* 1153 */ 50299,
/* 1154 */ -1152,
/* 1155 */ 1,
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
/* 124 */ 55007,
/* 125 */ 9999,
/* 126 */ 9999,
/* 127 */ 9999,
/* 128 */ 56009,
/* 129 */ 9999,
/* 130 */ 9999,
/* 131 */ 9999,
/* 132 */ 57011,
/* 133 */ 9999,
/* 134 */ 9999,
/* 135 */ 9999,
/* 136 */ 58008,
/* 137 */ 9999,
/* 138 */ 9999,
/* 139 */ 9999,
/* 140 */ 59007,
/* 141 */ 9999,
/* 142 */ 9999,
/* 143 */ 9999,
/* 144 */ 60006,
/* 145 */ 9999,
/* 146 */ 9999,
/* 147 */ 9999,
/* 148 */ 61007,
/* 149 */ 9999,
/* 150 */ 9999,
/* 151 */ 9999,
/* 152 */ 62008,
/* 153 */ 9999,
/* 154 */ 9999,
/* 155 */ 9999,
/* 156 */ 63009,
/* 157 */ 9999,
/* 158 */ 64004,
/* 159 */ 9999,
/* 160 */ 64028,
/* 161 */ 9999,
/* 162 */ 65004,
/* 163 */ 9999,
/* 164 */ 65017,
/* 165 */ 9999,
/* 166 */ 9999,
/* 167 */ 9999,
/* 168 */ 70008,
/* 169 */ 9999,
/* 170 */ 9999,
/* 171 */ 9999,
/* 172 */ 71011,
/* 173 */ 9999,
/* 174 */ 75004,
/* 175 */ 75020,
/* 176 */ 9999,
/* 177 */ 75035,
/* 178 */ 9999,
/* 179 */ 9999,
/* 180 */ 75018,
/* 181 */ 9999,
/* 182 */ 76004,
/* 183 */ 76020,
/* 184 */ 9999,
/* 185 */ 76018,
/* 186 */ 9999,
/* 187 */ 75022,
/* 188 */ 9999,
/* 189 */ 75023,
/* 190 */ 9999,
/* 191 */ 9999,
/* 192 */ 75023,
/* 193 */ 9999,
/* 194 */ 9999,
/* 195 */ 9999,
/* 196 */ 80009,
/* 197 */ 9999,
/* 198 */ 9999,
/* 199 */ 9999,
/* 200 */ 81008,
/* 201 */ 9999,
/* 202 */ 85004,
/* 203 */ 85033,
/* 204 */ 9999,
/* 205 */ 85004,
/* 206 */ 9999,
/* 207 */ 85006,
/* 208 */ 9999,
/* 209 */ 85028,
/* 210 */ 9999,
/* 211 */ 9999,
/* 212 */ 85028,
/* 213 */ 9999,
/* 214 */ 89004,
/* 215 */ 89034,
/* 216 */ 9999,
/* 217 */ 89004,
/* 218 */ 9999,
/* 219 */ 89006,
/* 220 */ 9999,
/* 221 */ 9999,
/* 222 */ 89025,
/* 223 */ 9999,
/* 224 */ 9999,
/* 225 */ 89025,
/* 226 */ 9999,
/* 227 */ 93004,
/* 228 */ 93024,
/* 229 */ 9999,
/* 230 */ 93004,
/* 231 */ 9999,
/* 232 */ 93006,
/* 233 */ 9999,
/* 234 */ 9999,
/* 235 */ 93015,
/* 236 */ 9999,
/* 237 */ 9999,
/* 238 */ 93015,
/* 239 */ 9999,
/* 240 */ 97004,
/* 241 */ 97029,
/* 242 */ 9999,
/* 243 */ 9999,
/* 244 */ 97027,
/* 245 */ 9999,
/* 246 */ 101004,
/* 247 */ 101040,
/* 248 */ 9999,
/* 249 */ 101004,
/* 250 */ 9999,
/* 251 */ 101006,
/* 252 */ 9999,
/* 253 */ 101019,
/* 254 */ 9999,
/* 255 */ 101023,
/* 256 */ 9999,
/* 257 */ 101036,
/* 258 */ 9999,
/* 259 */ 101042,
/* 260 */ 9999,
/* 261 */ 101065,
/* 262 */ 9999,
/* 263 */ 9999,
/* 264 */ 101065,
/* 265 */ 9999,
/* 266 */ 105004,
/* 267 */ 105036,
/* 268 */ 9999,
/* 269 */ 105004,
/* 270 */ 9999,
/* 271 */ 105006,
/* 272 */ 9999,
/* 273 */ 9999,
/* 274 */ 105027,
/* 275 */ 9999,
/* 276 */ 9999,
/* 277 */ 105027,
/* 278 */ 9999,
/* 279 */ 109004,
/* 280 */ 9999,
/* 281 */ 109013,
/* 282 */ 9999,
/* 283 */ 110004,
/* 284 */ 9999,
/* 285 */ 110024,
/* 286 */ 9999,
/* 287 */ 110004,
/* 288 */ 9999,
/* 289 */ 110006,
/* 290 */ 9999,
/* 291 */ 110015,
/* 292 */ 9999,
/* 293 */ 9999,
/* 294 */ 110015,
/* 295 */ 9999,
/* 296 */ 9999,
/* 297 */ 114009,
/* 298 */ 9999,
/* 299 */ 114024,
/* 300 */ 9999,
/* 301 */ 9999,
/* 302 */ 114007,
/* 303 */ 9999,
/* 304 */ 9999,
/* 305 */ 115009,
/* 306 */ 9999,
/* 307 */ 115007,
/* 308 */ 9999,
/* 309 */ 114011,
/* 310 */ 9999,
/* 311 */ 114012,
/* 312 */ 9999,
/* 313 */ 9999,
/* 314 */ 114012,
/* 315 */ 9999,
/* 316 */ 119004,
/* 317 */ 119029,
/* 318 */ 9999,
/* 319 */ 119004,
/* 320 */ 9999,
/* 321 */ 119006,
/* 322 */ 9999,
/* 323 */ 9999,
/* 324 */ 119020,
/* 325 */ 9999,
/* 326 */ 9999,
/* 327 */ 119020,
/* 328 */ 9999,
/* 329 */ 123004,
/* 330 */ 123010,
/* 331 */ 9999,
/* 332 */ 123005,
/* 333 */ 9999,
/* 334 */ 9999,
/* 335 */ 123016,
/* 336 */ 9999,
/* 337 */ 123012,
/* 338 */ 9999,
/* 339 */ 9999,
/* 340 */ 123012,
/* 341 */ 9999,
/* 342 */ 127004,
/* 343 */ 127017,
/* 344 */ 9999,
/* 345 */ 127004,
/* 346 */ 9999,
/* 347 */ 127006,
/* 348 */ 9999,
/* 349 */ 127012,
/* 350 */ 9999,
/* 351 */ 9999,
/* 352 */ 127012,
/* 353 */ 9999,
/* 354 */ 131004,
/* 355 */ 9999,
/* 356 */ 131005,
/* 357 */ 9999,
/* 358 */ 9999,
/* 359 */ 132008,
/* 360 */ 9999,
/* 361 */ 9999,
/* 362 */ 132004,
/* 363 */ 9999,
/* 364 */ 133004,
/* 365 */ 134003,
/* 366 */ 9999,
/* 367 */ 133020,
/* 368 */ 9999,
/* 369 */ 9999,
/* 370 */ 134009,
/* 371 */ 9999,
/* 372 */ 9999,
/* 373 */ 134005,
/* 374 */ 9999,
/* 375 */ 9999,
/* 376 */ 135009,
/* 377 */ 9999,
/* 378 */ 9999,
/* 379 */ 135005,
/* 380 */ 9999,
/* 381 */ 9999,
/* 382 */ 136009,
/* 383 */ 9999,
/* 384 */ 9999,
/* 385 */ 136005,
/* 386 */ 9999,
/* 387 */ 134011,
/* 388 */ 9999,
/* 389 */ 134020,
/* 390 */ 9999,
/* 391 */ 9999,
/* 392 */ 134020,
/* 393 */ 9999,
/* 394 */ 136011,
/* 395 */ 9999,
/* 396 */ 136025,
/* 397 */ 9999,
/* 398 */ 9999,
/* 399 */ 136025,
/* 400 */ 9999,
/* 401 */ 9999,
/* 402 */ 141008,
/* 403 */ 141033,
/* 404 */ 9999,
/* 405 */ 141004,
/* 406 */ 9999,
/* 407 */ 141010,
/* 408 */ 9999,
/* 409 */ 141028,
/* 410 */ 9999,
/* 411 */ 9999,
/* 412 */ 141028,
/* 413 */ 9999,
/* 414 */ 141035,
/* 415 */ 9999,
/* 416 */ 141041,
/* 417 */ 9999,
/* 418 */ 9999,
/* 419 */ 141041,
/* 420 */ 9999,
/* 421 */ 145004,
/* 422 */ 145029,
/* 423 */ 9999,
/* 424 */ 145004,
/* 425 */ 9999,
/* 426 */ 145006,
/* 427 */ 9999,
/* 428 */ 145024,
/* 429 */ 9999,
/* 430 */ 9999,
/* 431 */ 145024,
/* 432 */ 9999,
/* 433 */ 149004,
/* 434 */ 149019,
/* 435 */ 9999,
/* 436 */ 149017,
/* 437 */ 9999,
/* 438 */ 9999,
/* 439 */ 9999,
/* 440 */ 9999,
/* 441 */ 149021,
/* 442 */ 9999,
/* 443 */ 9999,
/* 444 */ 149021,
/* 445 */ 9999,
/* 446 */ 153004,
/* 447 */ 153028,
/* 448 */ 9999,
/* 449 */ 153004,
/* 450 */ 9999,
/* 451 */ 153006,
/* 452 */ 9999,
/* 453 */ 9999,
/* 454 */ 153019,
/* 455 */ 9999,
/* 456 */ 9999,
/* 457 */ 153019,
/* 458 */ 9999,
/* 459 */ 157004,
/* 460 */ 157027,
/* 461 */ 9999,
/* 462 */ 157025,
/* 463 */ 9999,
/* 464 */ 157029,
/* 465 */ 9999,
/* 466 */ 157038,
/* 467 */ 9999,
/* 468 */ 157042,
/* 469 */ 9999,
/* 470 */ 157042,
/* 471 */ 9999,
/* 472 */ 157044,
/* 473 */ 9999,
/* 474 */ 157062,
/* 475 */ 9999,
/* 476 */ 9999,
/* 477 */ 157062,
/* 478 */ 9999,
/* 479 */ 161004,
/* 480 */ 161029,
/* 481 */ 9999,
/* 482 */ 161004,
/* 483 */ 9999,
/* 484 */ 161006,
/* 485 */ 9999,
/* 486 */ 9999,
/* 487 */ 161020,
/* 488 */ 9999,
/* 489 */ 9999,
/* 490 */ 161020,
/* 491 */ 9999,
/* 492 */ 165004,
/* 493 */ 9999,
/* 494 */ 165024,
/* 495 */ 9999,
/* 496 */ 9999,
/* 497 */ 166008,
/* 498 */ 166025,
/* 499 */ 9999,
/* 500 */ 9999,
/* 501 */ 166004,
/* 502 */ 9999,
/* 503 */ 9999,
/* 504 */ 9999,
/* 505 */ 166027,
/* 506 */ 9999,
/* 507 */ 9999,
/* 508 */ 166027,
/* 509 */ 9999,
/* 510 */ 170004,
/* 511 */ 170030,
/* 512 */ 9999,
/* 513 */ 170004,
/* 514 */ 9999,
/* 515 */ 170006,
/* 516 */ 9999,
/* 517 */ 9999,
/* 518 */ 170021,
/* 519 */ 9999,
/* 520 */ 9999,
/* 521 */ 170021,
/* 522 */ 9999,
/* 523 */ 174004,
/* 524 */ 174029,
/* 525 */ 9999,
/* 526 */ 174027,
/* 527 */ 9999,
/* 528 */ 174031,
/* 529 */ 9999,
/* 530 */ 174049,
/* 531 */ 9999,
/* 532 */ 9999,
/* 533 */ 174049,
/* 534 */ 9999,
/* 535 */ 178004,
/* 536 */ 9999,
/* 537 */ 178010,
/* 538 */ 9999,
/* 539 */ 179004,
/* 540 */ 179017,
/* 541 */ 9999,
/* 542 */ 179004,
/* 543 */ 9999,
/* 544 */ 179006,
/* 545 */ 9999,
/* 546 */ 179012,
/* 547 */ 9999,
/* 548 */ 9999,
/* 549 */ 179012,
/* 550 */ 9999,
/* 551 */ 9999,
/* 552 */ 183008,
/* 553 */ 9999,
/* 554 */ 9999,
/* 555 */ 183004,
/* 556 */ 9999,
/* 557 */ 184004,
/* 558 */ 184036,
/* 559 */ 9999,
/* 560 */ 184004,
/* 561 */ 9999,
/* 562 */ 184006,
/* 563 */ 9999,
/* 564 */ 184031,
/* 565 */ 9999,
/* 566 */ 9999,
/* 567 */ 184031,
/* 568 */ 9999,
/* 569 */ 9999,
/* 570 */ 184042,
/* 571 */ 9999,
/* 572 */ 9999,
/* 573 */ 184038,
/* 574 */ 9999,
/* 575 */ 9999,
/* 576 */ 185009,
/* 577 */ 9999,
/* 578 */ 9999,
/* 579 */ 185005,
/* 580 */ 9999,
/* 581 */ 184044,
/* 582 */ 9999,
/* 583 */ 184053,
/* 584 */ 9999,
/* 585 */ 9999,
/* 586 */ 184053,
/* 587 */ 9999,
/* 588 */ 185011,
/* 589 */ 9999,
/* 590 */ 185029,
/* 591 */ 9999,
/* 592 */ 9999,
/* 593 */ 185029,
/* 594 */ 9999,
/* 595 */ 189004,
/* 596 */ 9999,
/* 597 */ 189005,
/* 598 */ 9999,
/* 599 */ 194002,
/* 600 */ 9999,
/* 601 */ 193004,
/* 602 */ 9999,
/* 603 */ 194004,
/* 604 */ 9999,
/* 605 */ 194020,
/* 606 */ 9999,
/* 607 */ 195004,
/* 608 */ 9999,
/* 609 */ 195023,
/* 610 */ 9999,
/* 611 */ 196004,
/* 612 */ 9999,
/* 613 */ 196021,
/* 614 */ 9999,
/* 615 */ 197004,
/* 616 */ 9999,
/* 617 */ 197022,
/* 618 */ 9999,
/* 619 */ 198004,
/* 620 */ 9999,
/* 621 */ 198022,
/* 622 */ 9999,
/* 623 */ 199004,
/* 624 */ 9999,
/* 625 */ 199017,
/* 626 */ 9999,
/* 627 */ 200004,
/* 628 */ 9999,
/* 629 */ 200018,
/* 630 */ 9999,
/* 631 */ 201004,
/* 632 */ 9999,
/* 633 */ 201018,
/* 634 */ 9999,
/* 635 */ 206004,
/* 636 */ 9999,
/* 637 */ 206014,
/* 638 */ 9999,
/* 639 */ 206005,
/* 640 */ 9999,
/* 641 */ 9999,
/* 642 */ 207009,
/* 643 */ 9999,
/* 644 */ 207037,
/* 645 */ 9999,
/* 646 */ 207007,
/* 647 */ 9999,
/* 648 */ 9999,
/* 649 */ 9999,
/* 650 */ 208016,
/* 651 */ 9999,
/* 652 */ 208010,
/* 653 */ 9999,
/* 654 */ 212021,
/* 655 */ 9999,
/* 656 */ 9999,
/* 657 */ 212004,
/* 658 */ 9999,
/* 659 */ 212023,
/* 660 */ 9999,
/* 661 */ 212032,
/* 662 */ 9999,
/* 663 */ 9999,
/* 664 */ 212032,
/* 665 */ 9999,
/* 666 */ 9999,
/* 667 */ 216033,
/* 668 */ 216055,
/* 669 */ 9999,
/* 670 */ 9999,
/* 671 */ 216004,
/* 672 */ 9999,
/* 673 */ 216035,
/* 674 */ 9999,
/* 675 */ 216050,
/* 676 */ 9999,
/* 677 */ 9999,
/* 678 */ 216050,
/* 679 */ 9999,
/* 680 */ 216057,
/* 681 */ 9999,
/* 682 */ 216070,
/* 683 */ 9999,
/* 684 */ 9999,
/* 685 */ 216070,
/* 686 */ 9999,
/* 687 */ 225004,
/* 688 */ 225047,
/* 689 */ 9999,
/* 690 */ 225004,
/* 691 */ 9999,
/* 692 */ 225006,
/* 693 */ 225014,
/* 694 */ 9999,
/* 695 */ 225014,
/* 696 */ 9999,
/* 697 */ 9999,
/* 698 */ 225014,
/* 699 */ 9999,
/* 700 */ 9999,
/* 701 */ 9999,
/* 702 */ 229011,
/* 703 */ 9999,
/* 704 */ 229029,
/* 705 */ 230003,
/* 706 */ 9999,
/* 707 */ 229005,
/* 708 */ 9999,
/* 709 */ 9999,
/* 710 */ 9999,
/* 711 */ 231015,
/* 712 */ 9999,
/* 713 */ 231033,
/* 714 */ 9999,
/* 715 */ 231009,
/* 716 */ 9999,
/* 717 */ 9999,
/* 718 */ 230010,
/* 719 */ 9999,
/* 720 */ 230008,
/* 721 */ 9999,
/* 722 */ 9999,
/* 723 */ 230008,
/* 724 */ 9999,
/* 725 */ 236002,
/* 726 */ 9999,
/* 727 */ 235004,
/* 728 */ 9999,
/* 729 */ 9999,
/* 730 */ 9999,
/* 731 */ 236014,
/* 732 */ 9999,
/* 733 */ 236032,
/* 734 */ 9999,
/* 735 */ 236008,
/* 736 */ 9999,
/* 737 */ 9999,
/* 738 */ 237007,
/* 739 */ 9999,
/* 740 */ 9999,
/* 741 */ 237030,
/* 742 */ 9999,
/* 743 */ 9999,
/* 744 */ 9999,
/* 745 */ 237005,
/* 746 */ 9999,
/* 747 */ 9999,
/* 748 */ 9999,
/* 749 */ 238064,
/* 750 */ 9999,
/* 751 */ 238113,
/* 752 */ 9999,
/* 753 */ 238162,
/* 754 */ 9999,
/* 755 */ 238211,
/* 756 */ 9999,
/* 757 */ 238006,
/* 758 */ 9999,
/* 759 */ 238066,
/* 760 */ 9999,
/* 761 */ 238075,
/* 762 */ 9999,
/* 763 */ 9999,
/* 764 */ 238075,
/* 765 */ 9999,
/* 766 */ 238115,
/* 767 */ 9999,
/* 768 */ 238124,
/* 769 */ 9999,
/* 770 */ 9999,
/* 771 */ 238124,
/* 772 */ 9999,
/* 773 */ 238164,
/* 774 */ 9999,
/* 775 */ 238173,
/* 776 */ 9999,
/* 777 */ 9999,
/* 778 */ 238173,
/* 779 */ 9999,
/* 780 */ 9999,
/* 781 */ 242009,
/* 782 */ 9999,
/* 783 */ 9999,
/* 784 */ 242007,
/* 785 */ 9999,
/* 786 */ 9999,
/* 787 */ 9999,
/* 788 */ 9999,
/* 789 */ 243011,
/* 790 */ 9999,
/* 791 */ 9999,
/* 792 */ 9999,
/* 793 */ 9999,
/* 794 */ 244008,
/* 795 */ 9999,
/* 796 */ 9999,
/* 797 */ 245011,
/* 798 */ 9999,
/* 799 */ 9999,
/* 800 */ 245009,
/* 801 */ 9999,
/* 802 */ 245013,
/* 803 */ 9999,
/* 804 */ 245022,
/* 805 */ 9999,
/* 806 */ 9999,
/* 807 */ 245022,
/* 808 */ 9999,
/* 809 */ 9999,
/* 810 */ 249010,
/* 811 */ 9999,
/* 812 */ 9999,
/* 813 */ 249008,
/* 814 */ 9999,
/* 815 */ 9999,
/* 816 */ 253010,
/* 817 */ 253025,
/* 818 */ 9999,
/* 819 */ 9999,
/* 820 */ 253008,
/* 821 */ 9999,
/* 822 */ 253012,
/* 823 */ 9999,
/* 824 */ 253013,
/* 825 */ 9999,
/* 826 */ 253013,
/* 827 */ 9999,
/* 828 */ 9999,
/* 829 */ 253013,
/* 830 */ 9999,
/* 831 */ 257004,
/* 832 */ 9999,
/* 833 */ 257024,
/* 834 */ 9999,
/* 835 */ 258004,
/* 836 */ 9999,
/* 837 */ 258022,
/* 838 */ 9999,
/* 839 */ 258013,
/* 840 */ 9999,
/* 841 */ 262004,
/* 842 */ 9999,
/* 843 */ 262025,
/* 844 */ 9999,
/* 845 */ 263004,
/* 846 */ 263025,
/* 847 */ 263049,
/* 848 */ 9999,
/* 849 */ 263019,
/* 850 */ 9999,
/* 851 */ 9999,
/* 852 */ 9999,
/* 853 */ 267009,
/* 854 */ 9999,
/* 855 */ 9999,
/* 856 */ 9999,
/* 857 */ 268004,
/* 858 */ 9999,
/* 859 */ 272004,
/* 860 */ 9999,
/* 861 */ 272024,
/* 862 */ 9999,
/* 863 */ 273004,
/* 864 */ 9999,
/* 865 */ 273035,
/* 866 */ 9999,
/* 867 */ 273053,
/* 868 */ 9999,
/* 869 */ 273024,
/* 870 */ 9999,
/* 871 */ 277004,
/* 872 */ 9999,
/* 873 */ 277025,
/* 874 */ 9999,
/* 875 */ 281004,
/* 876 */ 9999,
/* 877 */ 281025,
/* 878 */ 9999,
/* 879 */ 282004,
/* 880 */ 9999,
/* 881 */ 282042,
/* 882 */ 9999,
/* 883 */ 282024,
/* 884 */ 9999,
/* 885 */ 286004,
/* 886 */ 9999,
/* 887 */ 286026,
/* 888 */ 9999,
/* 889 */ 287004,
/* 890 */ 9999,
/* 891 */ 287044,
/* 892 */ 9999,
/* 893 */ 287025,
/* 894 */ 9999,
/* 895 */ 291004,
/* 896 */ 9999,
/* 897 */ 291026,
/* 898 */ 9999,
/* 899 */ 292004,
/* 900 */ 9999,
/* 901 */ 292037,
/* 902 */ 9999,
/* 903 */ 292026,
/* 904 */ 9999,
/* 905 */ 296004,
/* 906 */ 9999,
/* 907 */ 296017,
/* 908 */ 9999,
/* 909 */ 297004,
/* 910 */ 9999,
/* 911 */ 297037,
/* 912 */ 9999,
/* 913 */ 297026,
/* 914 */ 9999,
/* 915 */ 301004,
/* 916 */ 9999,
/* 917 */ 301022,
/* 918 */ 9999,
/* 919 */ 302004,
/* 920 */ 9999,
/* 921 */ 302027,
/* 922 */ 9999,
/* 923 */ 302017,
/* 924 */ 9999,
/* 925 */ 306004,
/* 926 */ 9999,
/* 927 */ 306019,
/* 928 */ 9999,
/* 929 */ 307004,
/* 930 */ 9999,
/* 931 */ 307039,
/* 932 */ 9999,
/* 933 */ 307022,
/* 934 */ 9999,
/* 935 */ 311004,
/* 936 */ 9999,
/* 937 */ 311022,
/* 938 */ 9999,
/* 939 */ 312004,
/* 940 */ 9999,
/* 941 */ 312034,
/* 942 */ 9999,
/* 943 */ 312019,
/* 944 */ 9999,
/* 945 */ 316004,
/* 946 */ 9999,
/* 947 */ 316028,
/* 948 */ 9999,
/* 949 */ 317022,
/* 950 */ 317046,
/* 951 */ 317074,
/* 952 */ 9999,
/* 953 */ 317004,
/* 954 */ 9999,
/* 955 */ 9999,
/* 956 */ 9999,
/* 957 */ 317048,
/* 958 */ 9999,
/* 959 */ 9999,
/* 960 */ 9999,
/* 961 */ 317054,
/* 962 */ 9999,
/* 963 */ 321004,
/* 964 */ 9999,
/* 965 */ 321018,
/* 966 */ 9999,
/* 967 */ 322022,
/* 968 */ 322052,
/* 969 */ 322099,
/* 970 */ 9999,
/* 971 */ 322004,
/* 972 */ 9999,
/* 973 */ 9999,
/* 974 */ 9999,
/* 975 */ 322054,
/* 976 */ 9999,
/* 977 */ 9999,
/* 978 */ 9999,
/* 979 */ 322060,
/* 980 */ 9999,
/* 981 */ 9999,
/* 982 */ 9999,
/* 983 */ 322080,
/* 984 */ 9999,
/* 985 */ 326004,
/* 986 */ 9999,
/* 987 */ 326019,
/* 988 */ 9999,
/* 989 */ 9999,
/* 990 */ 327008,
/* 991 */ 9999,
/* 992 */ 327022,
/* 993 */ 9999,
/* 994 */ 327004,
/* 995 */ 9999,
/* 996 */ 331004,
/* 997 */ 9999,
/* 998 */ 331021,
/* 999 */ 9999,
/* 1000 */ 332015,
/* 1001 */ 332062,
/* 1002 */ 9999,
/* 1003 */ 332004,
/* 1004 */ 9999,
/* 1005 */ 333004,
/* 1006 */ 333023,
/* 1007 */ 9999,
/* 1008 */ 333017,
/* 1009 */ 9999,
/* 1010 */ 9999,
/* 1011 */ 334011,
/* 1012 */ 9999,
/* 1013 */ 334009,
/* 1014 */ 9999,
/* 1015 */ 9999,
/* 1016 */ 9999,
/* 1017 */ 335015,
/* 1018 */ 9999,
/* 1019 */ 9999,
/* 1020 */ 335009,
/* 1021 */ 9999,
/* 1022 */ 9999,
/* 1023 */ 9999,
/* 1024 */ 332022,
/* 1025 */ 9999,
/* 1026 */ 9999,
/* 1027 */ 9999,
/* 1028 */ 332044,
/* 1029 */ 9999,
/* 1030 */ 9999,
/* 1031 */ 9999,
/* 1032 */ 339004,
/* 1033 */ 9999,
/* 1034 */ 9999,
/* 1035 */ 9999,
/* 1036 */ 340004,
/* 1037 */ 9999,
/* 1038 */ 9999,
/* 1039 */ 9999,
/* 1040 */ 341004,
/* 1041 */ 9999,
/* 1042 */ 9999,
/* 1043 */ 9999,
/* 1044 */ 342004,
/* 1045 */ 9999,
/* 1046 */ 9999,
/* 1047 */ 9999,
/* 1048 */ 343004,
/* 1049 */ 9999,
/* 1050 */ 9999,
/* 1051 */ 9999,
/* 1052 */ 344004,
/* 1053 */ 9999,
/* 1054 */ 348004,
/* 1055 */ 9999,
/* 1056 */ 348021,
/* 1057 */ 9999,
/* 1058 */ 349004,
/* 1059 */ 350003,
/* 1060 */ 9999,
/* 1061 */ 349021,
/* 1062 */ 9999,
/* 1063 */ 9999,
/* 1064 */ 350009,
/* 1065 */ 350054,
/* 1066 */ 9999,
/* 1067 */ 9999,
/* 1068 */ 350005,
/* 1069 */ 9999,
/* 1070 */ 9999,
/* 1071 */ 351009,
/* 1072 */ 9999,
/* 1073 */ 9999,
/* 1074 */ 351005,
/* 1075 */ 9999,
/* 1076 */ 9999,
/* 1077 */ 352009,
/* 1078 */ 9999,
/* 1079 */ 352005,
/* 1080 */ 9999,
/* 1081 */ 9999,
/* 1082 */ 353012,
/* 1083 */ 9999,
/* 1084 */ 353010,
/* 1085 */ 9999,
/* 1086 */ 9999,
/* 1087 */ 9999,
/* 1088 */ 354010,
/* 1089 */ 9999,
/* 1090 */ 9999,
/* 1091 */ 9999,
/* 1092 */ 355010,
/* 1093 */ 9999,
/* 1094 */ 9999,
/* 1095 */ 350060,
/* 1096 */ 9999,
/* 1097 */ 350056,
/* 1098 */ 9999,
/* 1099 */ 9999,
/* 1100 */ 350056,
/* 1101 */ 9999,
/* 1102 */ 351011,
/* 1103 */ 9999,
/* 1104 */ 351034,
/* 1105 */ 9999,
/* 1106 */ 9999,
/* 1107 */ 351034,
/* 1108 */ 9999,
/* 1109 */ 360004,
/* 1110 */ 9999,
/* 1111 */ 360005,
/* 1112 */ 9999,
/* 1113 */ 361004,
/* 1114 */ 9999,
/* 1115 */ 361011,
/* 1116 */ 9999,
/* 1117 */ 9999,
/* 1118 */ 362008,
/* 1119 */ 9999,
/* 1120 */ 9999,
/* 1121 */ 362004,
/* 1122 */ 9999,
/* 1123 */ 366044,
/* 1124 */ 366111,
/* 1125 */ 9999,
/* 1126 */ 366004,
/* 1127 */ 9999,
/* 1128 */ 366046,
/* 1129 */ 9999,
/* 1130 */ 366066,
/* 1131 */ 9999,
/* 1132 */ 366066,
/* 1133 */ 9999,
/* 1134 */ 9999,
/* 1135 */ 366066,
/* 1136 */ 9999,
/* 1137 */ 9999,
/* 1138 */ 9999,
/* 1139 */ 370011,
/* 1140 */ 9999,
/* 1141 */ 9999,
/* 1142 */ 9999,
/* 1143 */ 371012,
/* 1144 */ 9999,
/* 1145 */ 9999,
/* 1146 */ 9999,
/* 1147 */ 372013,
/* 1148 */ 9999,
/* 1149 */ 9999,
/* 1150 */ 9999,
/* 1151 */ 373009,
/* 1152 */ 9999,
/* 1153 */ 9999,
/* 1154 */ 9999,
/* 1155 */ 378013,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[1157];
*/
int TABLE[258][308];
init_dirsets() {
TABLE[127][0] = 1;
TABLE[127][59] = 1;
TABLE[127][123] = 1;
TABLE[127][40] = 1;
TABLE[127][42] = 1;
TABLE[127][299] = 1;
TABLE[127][260] = 1;
TABLE[127][286] = 1;
TABLE[127][285] = 1;
TABLE[127][277] = 1;
TABLE[127][284] = 1;
TABLE[127][276] = 1;
TABLE[127][273] = 1;
TABLE[127][272] = 1;
TABLE[127][259] = 1;
TABLE[127][268] = 1;
TABLE[127][264] = 1;
TABLE[127][256] = 1;
TABLE[127][274] = 1;
TABLE[127][279] = 1;
TABLE[127][267] = 1;
TABLE[127][266] = 1;
TABLE[127][280] = 1;
TABLE[127][283] = 1;
TABLE[1][0] = 1;
TABLE[1][59] = 1;
TABLE[1][40] = 1;
TABLE[1][123] = 1;
TABLE[1][267] = 1;
TABLE[1][279] = 1;
TABLE[1][274] = 1;
TABLE[1][256] = 1;
TABLE[1][264] = 1;
TABLE[1][268] = 1;
TABLE[1][259] = 1;
TABLE[1][272] = 1;
TABLE[1][273] = 1;
TABLE[1][276] = 1;
TABLE[1][284] = 1;
TABLE[1][277] = 1;
TABLE[1][285] = 1;
TABLE[1][286] = 1;
TABLE[1][260] = 1;
TABLE[1][299] = 1;
TABLE[1][42] = 1;
TABLE[1][266] = 1;
TABLE[1][283] = 1;
TABLE[1][280] = 1;
TABLE[128][0] = 1;
TABLE[128][59] = 1;
TABLE[128][123] = 1;
TABLE[128][40] = 1;
TABLE[128][42] = 1;
TABLE[128][299] = 1;
TABLE[128][260] = 1;
TABLE[128][286] = 1;
TABLE[128][285] = 1;
TABLE[128][277] = 1;
TABLE[128][284] = 1;
TABLE[128][276] = 1;
TABLE[128][273] = 1;
TABLE[128][272] = 1;
TABLE[128][259] = 1;
TABLE[128][268] = 1;
TABLE[128][264] = 1;
TABLE[128][256] = 1;
TABLE[128][274] = 1;
TABLE[128][279] = 1;
TABLE[128][267] = 1;
TABLE[128][266] = 1;
TABLE[128][280] = 1;
TABLE[128][283] = 1;
TABLE[212][0] = 1;
TABLE[2][0] = 1;
TABLE[2][59] = 1;
TABLE[2][40] = 1;
TABLE[2][123] = 1;
TABLE[2][299] = 1;
TABLE[2][42] = 1;
TABLE[2][260] = 1;
TABLE[2][286] = 1;
TABLE[2][285] = 1;
TABLE[2][277] = 1;
TABLE[2][284] = 1;
TABLE[2][276] = 1;
TABLE[2][273] = 1;
TABLE[2][272] = 1;
TABLE[2][259] = 1;
TABLE[2][268] = 1;
TABLE[2][264] = 1;
TABLE[2][256] = 1;
TABLE[2][274] = 1;
TABLE[2][279] = 1;
TABLE[2][267] = 1;
TABLE[2][266] = 1;
TABLE[2][280] = 1;
TABLE[2][283] = 1;
TABLE[3][267] = 1;
TABLE[3][279] = 1;
TABLE[3][274] = 1;
TABLE[3][256] = 1;
TABLE[3][264] = 1;
TABLE[3][268] = 1;
TABLE[3][259] = 1;
TABLE[3][272] = 1;
TABLE[3][273] = 1;
TABLE[3][276] = 1;
TABLE[3][284] = 1;
TABLE[3][277] = 1;
TABLE[3][285] = 1;
TABLE[3][286] = 1;
TABLE[3][260] = 1;
TABLE[3][266] = 1;
TABLE[3][283] = 1;
TABLE[3][280] = 1;
TABLE[4][59] = 1;
TABLE[4][123] = 1;
TABLE[4][40] = 1;
TABLE[4][42] = 1;
TABLE[4][299] = 1;
TABLE[4][267] = 1;
TABLE[4][279] = 1;
TABLE[4][274] = 1;
TABLE[4][256] = 1;
TABLE[4][264] = 1;
TABLE[4][268] = 1;
TABLE[4][259] = 1;
TABLE[4][272] = 1;
TABLE[4][273] = 1;
TABLE[4][276] = 1;
TABLE[4][284] = 1;
TABLE[4][277] = 1;
TABLE[4][285] = 1;
TABLE[4][286] = 1;
TABLE[4][260] = 1;
TABLE[4][266] = 1;
TABLE[4][283] = 1;
TABLE[4][280] = 1;
TABLE[129][260] = 1;
TABLE[129][286] = 1;
TABLE[129][285] = 1;
TABLE[129][277] = 1;
TABLE[129][284] = 1;
TABLE[129][276] = 1;
TABLE[129][273] = 1;
TABLE[129][272] = 1;
TABLE[129][259] = 1;
TABLE[129][268] = 1;
TABLE[129][264] = 1;
TABLE[129][256] = 1;
TABLE[129][274] = 1;
TABLE[129][279] = 1;
TABLE[129][267] = 1;
TABLE[129][266] = 1;
TABLE[129][280] = 1;
TABLE[129][283] = 1;
TABLE[213][40] = 1;
TABLE[213][42] = 1;
TABLE[213][299] = 1;
TABLE[213][267] = 1;
TABLE[213][279] = 1;
TABLE[213][274] = 1;
TABLE[213][256] = 1;
TABLE[213][264] = 1;
TABLE[213][268] = 1;
TABLE[213][259] = 1;
TABLE[213][272] = 1;
TABLE[213][273] = 1;
TABLE[213][276] = 1;
TABLE[213][284] = 1;
TABLE[213][277] = 1;
TABLE[213][285] = 1;
TABLE[213][286] = 1;
TABLE[213][260] = 1;
TABLE[213][266] = 1;
TABLE[213][283] = 1;
TABLE[213][280] = 1;
TABLE[213][59] = 1;
TABLE[213][123] = 1;
TABLE[130][59] = 1;
TABLE[130][123] = 1;
TABLE[130][260] = 1;
TABLE[130][286] = 1;
TABLE[130][285] = 1;
TABLE[130][277] = 1;
TABLE[130][284] = 1;
TABLE[130][276] = 1;
TABLE[130][273] = 1;
TABLE[130][272] = 1;
TABLE[130][259] = 1;
TABLE[130][268] = 1;
TABLE[130][264] = 1;
TABLE[130][256] = 1;
TABLE[130][274] = 1;
TABLE[130][279] = 1;
TABLE[130][267] = 1;
TABLE[130][266] = 1;
TABLE[130][280] = 1;
TABLE[130][283] = 1;
TABLE[214][59] = 1;
TABLE[214][123] = 1;
TABLE[131][59] = 1;
TABLE[132][123] = 1;
TABLE[5][260] = 1;
TABLE[5][286] = 1;
TABLE[5][285] = 1;
TABLE[5][277] = 1;
TABLE[5][284] = 1;
TABLE[5][276] = 1;
TABLE[5][273] = 1;
TABLE[5][272] = 1;
TABLE[5][259] = 1;
TABLE[5][268] = 1;
TABLE[5][264] = 1;
TABLE[5][256] = 1;
TABLE[5][274] = 1;
TABLE[5][279] = 1;
TABLE[5][267] = 1;
TABLE[5][266] = 1;
TABLE[5][280] = 1;
TABLE[5][283] = 1;
TABLE[133][59] = 1;
TABLE[133][44] = 1;
TABLE[133][123] = 1;
TABLE[133][61] = 1;
TABLE[133][278] = 1;
TABLE[133][40] = 1;
TABLE[133][295] = 1;
TABLE[133][294] = 1;
TABLE[133][33] = 1;
TABLE[133][126] = 1;
TABLE[133][45] = 1;
TABLE[133][43] = 1;
TABLE[133][38] = 1;
TABLE[133][299] = 1;
TABLE[133][42] = 1;
TABLE[133][289] = 1;
TABLE[133][303] = 1;
TABLE[133][302] = 1;
TABLE[133][304] = 1;
TABLE[215][59] = 1;
TABLE[6][260] = 1;
TABLE[6][286] = 1;
TABLE[6][285] = 1;
TABLE[6][277] = 1;
TABLE[6][284] = 1;
TABLE[6][276] = 1;
TABLE[6][273] = 1;
TABLE[6][272] = 1;
TABLE[6][259] = 1;
TABLE[6][268] = 1;
TABLE[6][264] = 1;
TABLE[6][256] = 1;
TABLE[6][274] = 1;
TABLE[6][279] = 1;
TABLE[6][267] = 1;
TABLE[6][266] = 1;
TABLE[6][280] = 1;
TABLE[6][283] = 1;
TABLE[134][267] = 1;
TABLE[134][279] = 1;
TABLE[134][274] = 1;
TABLE[134][256] = 1;
TABLE[134][264] = 1;
TABLE[134][268] = 1;
TABLE[134][259] = 1;
TABLE[134][272] = 1;
TABLE[134][273] = 1;
TABLE[134][276] = 1;
TABLE[134][284] = 1;
TABLE[134][277] = 1;
TABLE[134][285] = 1;
TABLE[134][286] = 1;
TABLE[134][260] = 1;
TABLE[134][266] = 1;
TABLE[134][283] = 1;
TABLE[134][280] = 1;
TABLE[216][267] = 1;
TABLE[216][279] = 1;
TABLE[216][274] = 1;
TABLE[216][256] = 1;
TABLE[216][264] = 1;
TABLE[216][268] = 1;
TABLE[216][259] = 1;
TABLE[216][272] = 1;
TABLE[216][273] = 1;
TABLE[216][276] = 1;
TABLE[216][284] = 1;
TABLE[216][277] = 1;
TABLE[216][285] = 1;
TABLE[216][286] = 1;
TABLE[216][260] = 1;
TABLE[216][266] = 1;
TABLE[216][283] = 1;
TABLE[216][280] = 1;
TABLE[7][267] = 1;
TABLE[7][279] = 1;
TABLE[7][274] = 1;
TABLE[7][256] = 1;
TABLE[7][264] = 1;
TABLE[7][268] = 1;
TABLE[7][259] = 1;
TABLE[7][272] = 1;
TABLE[7][273] = 1;
TABLE[7][276] = 1;
TABLE[7][284] = 1;
TABLE[7][277] = 1;
TABLE[7][285] = 1;
TABLE[7][286] = 1;
TABLE[7][260] = 1;
TABLE[7][266] = 1;
TABLE[7][283] = 1;
TABLE[7][280] = 1;
TABLE[135][256] = 1;
TABLE[135][274] = 1;
TABLE[135][279] = 1;
TABLE[135][267] = 1;
TABLE[136][285] = 1;
TABLE[136][277] = 1;
TABLE[136][284] = 1;
TABLE[136][276] = 1;
TABLE[136][273] = 1;
TABLE[136][272] = 1;
TABLE[136][259] = 1;
TABLE[136][268] = 1;
TABLE[136][264] = 1;
TABLE[136][266] = 1;
TABLE[136][280] = 1;
TABLE[136][283] = 1;
TABLE[137][260] = 1;
TABLE[137][286] = 1;
TABLE[138][260] = 1;
TABLE[138][286] = 1;
TABLE[138][285] = 1;
TABLE[138][277] = 1;
TABLE[138][284] = 1;
TABLE[138][276] = 1;
TABLE[138][273] = 1;
TABLE[138][272] = 1;
TABLE[138][259] = 1;
TABLE[138][268] = 1;
TABLE[138][264] = 1;
TABLE[138][256] = 1;
TABLE[138][274] = 1;
TABLE[138][279] = 1;
TABLE[138][267] = 1;
TABLE[138][266] = 1;
TABLE[138][280] = 1;
TABLE[138][283] = 1;
TABLE[217][40] = 1;
TABLE[217][42] = 1;
TABLE[217][299] = 1;
TABLE[217][267] = 1;
TABLE[217][279] = 1;
TABLE[217][274] = 1;
TABLE[217][256] = 1;
TABLE[217][264] = 1;
TABLE[217][268] = 1;
TABLE[217][259] = 1;
TABLE[217][272] = 1;
TABLE[217][273] = 1;
TABLE[217][276] = 1;
TABLE[217][284] = 1;
TABLE[217][277] = 1;
TABLE[217][285] = 1;
TABLE[217][286] = 1;
TABLE[217][260] = 1;
TABLE[217][266] = 1;
TABLE[217][283] = 1;
TABLE[217][280] = 1;
TABLE[217][59] = 1;
TABLE[217][123] = 1;
TABLE[217][44] = 1;
TABLE[217][61] = 1;
TABLE[217][278] = 1;
TABLE[217][38] = 1;
TABLE[217][43] = 1;
TABLE[217][45] = 1;
TABLE[217][126] = 1;
TABLE[217][33] = 1;
TABLE[217][294] = 1;
TABLE[217][295] = 1;
TABLE[217][304] = 1;
TABLE[217][302] = 1;
TABLE[217][303] = 1;
TABLE[217][289] = 1;
TABLE[217][91] = 1;
TABLE[217][41] = 1;
TABLE[8][256] = 1;
TABLE[9][274] = 1;
TABLE[10][279] = 1;
TABLE[11][267] = 1;
TABLE[12][285] = 1;
TABLE[13][277] = 1;
TABLE[14][284] = 1;
TABLE[15][276] = 1;
TABLE[16][273] = 1;
TABLE[17][272] = 1;
TABLE[18][259] = 1;
TABLE[19][268] = 1;
TABLE[20][264] = 1;
TABLE[21][283] = 1;
TABLE[21][280] = 1;
TABLE[22][266] = 1;
TABLE[23][260] = 1;
TABLE[24][286] = 1;
TABLE[25][280] = 1;
TABLE[25][283] = 1;
TABLE[26][280] = 1;
TABLE[26][283] = 1;
TABLE[139][299] = 1;
TABLE[218][123] = 1;
TABLE[27][280] = 1;
TABLE[28][283] = 1;
TABLE[29][264] = 1;
TABLE[29][268] = 1;
TABLE[29][259] = 1;
TABLE[29][272] = 1;
TABLE[29][273] = 1;
TABLE[29][276] = 1;
TABLE[29][284] = 1;
TABLE[29][277] = 1;
TABLE[29][285] = 1;
TABLE[29][286] = 1;
TABLE[29][260] = 1;
TABLE[29][266] = 1;
TABLE[29][283] = 1;
TABLE[29][280] = 1;
TABLE[140][260] = 1;
TABLE[140][286] = 1;
TABLE[140][285] = 1;
TABLE[140][277] = 1;
TABLE[140][284] = 1;
TABLE[140][276] = 1;
TABLE[140][273] = 1;
TABLE[140][272] = 1;
TABLE[140][259] = 1;
TABLE[140][268] = 1;
TABLE[140][264] = 1;
TABLE[140][266] = 1;
TABLE[140][280] = 1;
TABLE[140][283] = 1;
TABLE[219][264] = 1;
TABLE[219][268] = 1;
TABLE[219][259] = 1;
TABLE[219][272] = 1;
TABLE[219][273] = 1;
TABLE[219][276] = 1;
TABLE[219][284] = 1;
TABLE[219][277] = 1;
TABLE[219][285] = 1;
TABLE[219][286] = 1;
TABLE[219][260] = 1;
TABLE[219][266] = 1;
TABLE[219][283] = 1;
TABLE[219][280] = 1;
TABLE[30][59] = 1;
TABLE[30][44] = 1;
TABLE[30][61] = 1;
TABLE[30][123] = 1;
TABLE[30][40] = 1;
TABLE[30][278] = 1;
TABLE[30][42] = 1;
TABLE[30][299] = 1;
TABLE[30][38] = 1;
TABLE[30][43] = 1;
TABLE[30][45] = 1;
TABLE[30][126] = 1;
TABLE[30][33] = 1;
TABLE[30][294] = 1;
TABLE[30][295] = 1;
TABLE[30][304] = 1;
TABLE[30][302] = 1;
TABLE[30][303] = 1;
TABLE[30][289] = 1;
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
TABLE[220][61] = 1;
TABLE[220][123] = 1;
TABLE[220][40] = 1;
TABLE[220][278] = 1;
TABLE[220][42] = 1;
TABLE[220][299] = 1;
TABLE[220][38] = 1;
TABLE[220][43] = 1;
TABLE[220][45] = 1;
TABLE[220][126] = 1;
TABLE[220][33] = 1;
TABLE[220][294] = 1;
TABLE[220][295] = 1;
TABLE[220][304] = 1;
TABLE[220][302] = 1;
TABLE[220][303] = 1;
TABLE[220][289] = 1;
TABLE[220][59] = 1;
TABLE[220][44] = 1;
TABLE[31][123] = 1;
TABLE[31][278] = 1;
TABLE[31][295] = 1;
TABLE[31][294] = 1;
TABLE[31][33] = 1;
TABLE[31][126] = 1;
TABLE[31][45] = 1;
TABLE[31][43] = 1;
TABLE[31][38] = 1;
TABLE[31][289] = 1;
TABLE[31][303] = 1;
TABLE[31][302] = 1;
TABLE[31][304] = 1;
TABLE[31][61] = 1;
TABLE[31][40] = 1;
TABLE[31][299] = 1;
TABLE[31][42] = 1;
TABLE[142][61] = 1;
TABLE[142][40] = 1;
TABLE[142][42] = 1;
TABLE[142][299] = 1;
TABLE[221][123] = 1;
TABLE[221][278] = 1;
TABLE[221][295] = 1;
TABLE[221][294] = 1;
TABLE[221][33] = 1;
TABLE[221][126] = 1;
TABLE[221][45] = 1;
TABLE[221][43] = 1;
TABLE[221][42] = 1;
TABLE[221][38] = 1;
TABLE[221][40] = 1;
TABLE[221][299] = 1;
TABLE[221][289] = 1;
TABLE[221][303] = 1;
TABLE[221][302] = 1;
TABLE[221][304] = 1;
TABLE[32][260] = 1;
TABLE[32][286] = 1;
TABLE[32][285] = 1;
TABLE[32][277] = 1;
TABLE[32][284] = 1;
TABLE[32][276] = 1;
TABLE[32][273] = 1;
TABLE[32][272] = 1;
TABLE[32][259] = 1;
TABLE[32][268] = 1;
TABLE[32][264] = 1;
TABLE[32][266] = 1;
TABLE[32][280] = 1;
TABLE[32][283] = 1;
TABLE[33][264] = 1;
TABLE[33][268] = 1;
TABLE[33][259] = 1;
TABLE[33][272] = 1;
TABLE[33][273] = 1;
TABLE[33][276] = 1;
TABLE[33][284] = 1;
TABLE[33][277] = 1;
TABLE[33][285] = 1;
TABLE[33][286] = 1;
TABLE[33][260] = 1;
TABLE[33][266] = 1;
TABLE[33][283] = 1;
TABLE[33][280] = 1;
TABLE[143][285] = 1;
TABLE[143][277] = 1;
TABLE[143][284] = 1;
TABLE[143][276] = 1;
TABLE[143][273] = 1;
TABLE[143][272] = 1;
TABLE[143][259] = 1;
TABLE[143][268] = 1;
TABLE[143][264] = 1;
TABLE[143][266] = 1;
TABLE[143][280] = 1;
TABLE[143][283] = 1;
TABLE[144][260] = 1;
TABLE[144][286] = 1;
TABLE[145][260] = 1;
TABLE[145][286] = 1;
TABLE[145][285] = 1;
TABLE[145][277] = 1;
TABLE[145][284] = 1;
TABLE[145][276] = 1;
TABLE[145][273] = 1;
TABLE[145][272] = 1;
TABLE[145][259] = 1;
TABLE[145][268] = 1;
TABLE[145][264] = 1;
TABLE[145][266] = 1;
TABLE[145][280] = 1;
TABLE[145][283] = 1;
TABLE[222][44] = 1;
TABLE[222][58] = 1;
TABLE[222][40] = 1;
TABLE[222][42] = 1;
TABLE[222][299] = 1;
TABLE[222][59] = 1;
TABLE[222][91] = 1;
TABLE[222][41] = 1;
TABLE[34][59] = 1;
TABLE[34][44] = 1;
TABLE[34][58] = 1;
TABLE[34][40] = 1;
TABLE[34][299] = 1;
TABLE[34][42] = 1;
TABLE[146][44] = 1;
TABLE[146][58] = 1;
TABLE[146][40] = 1;
TABLE[146][42] = 1;
TABLE[146][299] = 1;
TABLE[223][58] = 1;
TABLE[223][40] = 1;
TABLE[223][299] = 1;
TABLE[223][42] = 1;
TABLE[223][59] = 1;
TABLE[223][44] = 1;
TABLE[35][59] = 1;
TABLE[35][44] = 1;
TABLE[35][40] = 1;
TABLE[35][42] = 1;
TABLE[35][299] = 1;
TABLE[36][58] = 1;
TABLE[36][40] = 1;
TABLE[36][299] = 1;
TABLE[36][42] = 1;
TABLE[147][58] = 1;
TABLE[147][40] = 1;
TABLE[147][42] = 1;
TABLE[147][299] = 1;
TABLE[224][58] = 1;
TABLE[37][266] = 1;
TABLE[38][266] = 1;
TABLE[148][299] = 1;
TABLE[225][123] = 1;
TABLE[39][44] = 1;
TABLE[39][299] = 1;
TABLE[149][44] = 1;
TABLE[149][299] = 1;
TABLE[226][299] = 1;
TABLE[40][299] = 1;
TABLE[150][61] = 1;
TABLE[227][125] = 1;
TABLE[227][44] = 1;
TABLE[41][40] = 1;
TABLE[41][299] = 1;
TABLE[41][42] = 1;
TABLE[151][42] = 1;
TABLE[228][40] = 1;
TABLE[228][299] = 1;
TABLE[42][299] = 1;
TABLE[43][40] = 1;
TABLE[44][40] = 1;
TABLE[44][299] = 1;
TABLE[153][91] = 1;
TABLE[154][40] = 1;
TABLE[156][40] = 1;
TABLE[152][278] = 1;
TABLE[152][295] = 1;
TABLE[152][294] = 1;
TABLE[152][33] = 1;
TABLE[152][126] = 1;
TABLE[152][45] = 1;
TABLE[152][43] = 1;
TABLE[152][42] = 1;
TABLE[152][38] = 1;
TABLE[152][40] = 1;
TABLE[152][299] = 1;
TABLE[152][289] = 1;
TABLE[152][303] = 1;
TABLE[152][302] = 1;
TABLE[152][304] = 1;
TABLE[229][93] = 1;
TABLE[155][41] = 1;
TABLE[155][44] = 1;
TABLE[155][299] = 1;
TABLE[230][41] = 1;
TABLE[45][42] = 1;
TABLE[157][42] = 1;
TABLE[157][40] = 1;
TABLE[157][299] = 1;
TABLE[157][44] = 1;
TABLE[157][41] = 1;
TABLE[157][91] = 1;
TABLE[157][286] = 1;
TABLE[157][260] = 1;
TABLE[231][42] = 1;
TABLE[231][40] = 1;
TABLE[231][299] = 1;
TABLE[231][44] = 1;
TABLE[231][41] = 1;
TABLE[231][91] = 1;
TABLE[158][42] = 1;
TABLE[232][40] = 1;
TABLE[232][299] = 1;
TABLE[232][44] = 1;
TABLE[232][41] = 1;
TABLE[232][91] = 1;
TABLE[46][260] = 1;
TABLE[46][286] = 1;
TABLE[159][286] = 1;
TABLE[159][260] = 1;
TABLE[233][260] = 1;
TABLE[233][286] = 1;
TABLE[47][41] = 1;
TABLE[47][44] = 1;
TABLE[47][260] = 1;
TABLE[47][286] = 1;
TABLE[47][285] = 1;
TABLE[47][277] = 1;
TABLE[47][284] = 1;
TABLE[47][276] = 1;
TABLE[47][273] = 1;
TABLE[47][272] = 1;
TABLE[47][259] = 1;
TABLE[47][268] = 1;
TABLE[47][264] = 1;
TABLE[47][256] = 1;
TABLE[47][274] = 1;
TABLE[47][279] = 1;
TABLE[47][267] = 1;
TABLE[47][266] = 1;
TABLE[47][280] = 1;
TABLE[47][283] = 1;
TABLE[160][44] = 1;
TABLE[234][41] = 1;
TABLE[48][44] = 1;
TABLE[48][267] = 1;
TABLE[48][279] = 1;
TABLE[48][274] = 1;
TABLE[48][256] = 1;
TABLE[48][264] = 1;
TABLE[48][268] = 1;
TABLE[48][259] = 1;
TABLE[48][272] = 1;
TABLE[48][273] = 1;
TABLE[48][276] = 1;
TABLE[48][284] = 1;
TABLE[48][277] = 1;
TABLE[48][285] = 1;
TABLE[48][286] = 1;
TABLE[48][260] = 1;
TABLE[48][266] = 1;
TABLE[48][283] = 1;
TABLE[48][280] = 1;
TABLE[161][44] = 1;
TABLE[161][260] = 1;
TABLE[161][286] = 1;
TABLE[161][285] = 1;
TABLE[161][277] = 1;
TABLE[161][284] = 1;
TABLE[161][276] = 1;
TABLE[161][273] = 1;
TABLE[161][272] = 1;
TABLE[161][259] = 1;
TABLE[161][268] = 1;
TABLE[161][264] = 1;
TABLE[161][256] = 1;
TABLE[161][274] = 1;
TABLE[161][279] = 1;
TABLE[161][267] = 1;
TABLE[161][266] = 1;
TABLE[161][280] = 1;
TABLE[161][283] = 1;
TABLE[235][267] = 1;
TABLE[235][279] = 1;
TABLE[235][274] = 1;
TABLE[235][256] = 1;
TABLE[235][264] = 1;
TABLE[235][268] = 1;
TABLE[235][259] = 1;
TABLE[235][272] = 1;
TABLE[235][273] = 1;
TABLE[235][276] = 1;
TABLE[235][284] = 1;
TABLE[235][277] = 1;
TABLE[235][285] = 1;
TABLE[235][286] = 1;
TABLE[235][260] = 1;
TABLE[235][266] = 1;
TABLE[235][283] = 1;
TABLE[235][280] = 1;
TABLE[49][260] = 1;
TABLE[49][286] = 1;
TABLE[49][285] = 1;
TABLE[49][277] = 1;
TABLE[49][284] = 1;
TABLE[49][276] = 1;
TABLE[49][273] = 1;
TABLE[49][272] = 1;
TABLE[49][259] = 1;
TABLE[49][268] = 1;
TABLE[49][264] = 1;
TABLE[49][256] = 1;
TABLE[49][274] = 1;
TABLE[49][279] = 1;
TABLE[49][267] = 1;
TABLE[49][266] = 1;
TABLE[49][280] = 1;
TABLE[49][283] = 1;
TABLE[162][44] = 1;
TABLE[162][41] = 1;
TABLE[162][40] = 1;
TABLE[162][42] = 1;
TABLE[162][299] = 1;
TABLE[164][44] = 1;
TABLE[164][41] = 1;
TABLE[164][42] = 1;
TABLE[164][40] = 1;
TABLE[164][91] = 1;
TABLE[163][44] = 1;
TABLE[163][41] = 1;
TABLE[163][42] = 1;
TABLE[163][40] = 1;
TABLE[163][91] = 1;
TABLE[236][44] = 1;
TABLE[236][41] = 1;
TABLE[50][44] = 1;
TABLE[50][299] = 1;
TABLE[165][44] = 1;
TABLE[165][299] = 1;
TABLE[237][299] = 1;
TABLE[51][278] = 1;
TABLE[51][38] = 1;
TABLE[51][42] = 1;
TABLE[51][43] = 1;
TABLE[51][45] = 1;
TABLE[51][126] = 1;
TABLE[51][33] = 1;
TABLE[51][294] = 1;
TABLE[51][295] = 1;
TABLE[51][40] = 1;
TABLE[51][304] = 1;
TABLE[51][302] = 1;
TABLE[51][303] = 1;
TABLE[51][289] = 1;
TABLE[51][299] = 1;
TABLE[52][123] = 1;
TABLE[166][44] = 1;
TABLE[238][125] = 1;
TABLE[53][123] = 1;
TABLE[53][44] = 1;
TABLE[53][278] = 1;
TABLE[53][295] = 1;
TABLE[53][294] = 1;
TABLE[53][33] = 1;
TABLE[53][126] = 1;
TABLE[53][45] = 1;
TABLE[53][43] = 1;
TABLE[53][42] = 1;
TABLE[53][38] = 1;
TABLE[53][40] = 1;
TABLE[53][299] = 1;
TABLE[53][289] = 1;
TABLE[53][303] = 1;
TABLE[53][302] = 1;
TABLE[53][304] = 1;
TABLE[167][123] = 1;
TABLE[167][44] = 1;
TABLE[167][278] = 1;
TABLE[167][38] = 1;
TABLE[167][42] = 1;
TABLE[167][43] = 1;
TABLE[167][45] = 1;
TABLE[167][126] = 1;
TABLE[167][33] = 1;
TABLE[167][294] = 1;
TABLE[167][295] = 1;
TABLE[167][40] = 1;
TABLE[167][304] = 1;
TABLE[167][302] = 1;
TABLE[167][303] = 1;
TABLE[167][289] = 1;
TABLE[167][299] = 1;
TABLE[239][123] = 1;
TABLE[239][278] = 1;
TABLE[239][295] = 1;
TABLE[239][294] = 1;
TABLE[239][33] = 1;
TABLE[239][126] = 1;
TABLE[239][45] = 1;
TABLE[239][43] = 1;
TABLE[239][42] = 1;
TABLE[239][38] = 1;
TABLE[239][40] = 1;
TABLE[239][299] = 1;
TABLE[239][289] = 1;
TABLE[239][303] = 1;
TABLE[239][302] = 1;
TABLE[239][304] = 1;
TABLE[54][260] = 1;
TABLE[54][286] = 1;
TABLE[54][285] = 1;
TABLE[54][277] = 1;
TABLE[54][284] = 1;
TABLE[54][276] = 1;
TABLE[54][273] = 1;
TABLE[54][272] = 1;
TABLE[54][259] = 1;
TABLE[54][268] = 1;
TABLE[54][264] = 1;
TABLE[54][266] = 1;
TABLE[54][280] = 1;
TABLE[54][283] = 1;
TABLE[168][41] = 1;
TABLE[168][42] = 1;
TABLE[168][40] = 1;
TABLE[168][91] = 1;
TABLE[240][41] = 1;
TABLE[55][42] = 1;
TABLE[56][44] = 1;
TABLE[56][41] = 1;
TABLE[56][40] = 1;
TABLE[56][91] = 1;
TABLE[56][42] = 1;
TABLE[169][42] = 1;
TABLE[241][40] = 1;
TABLE[241][91] = 1;
TABLE[241][44] = 1;
TABLE[241][41] = 1;
TABLE[57][40] = 1;
TABLE[58][40] = 1;
TABLE[58][91] = 1;
TABLE[170][40] = 1;
TABLE[170][91] = 1;
TABLE[242][91] = 1;
TABLE[242][40] = 1;
TABLE[172][91] = 1;
TABLE[174][40] = 1;
TABLE[171][278] = 1;
TABLE[171][295] = 1;
TABLE[171][294] = 1;
TABLE[171][33] = 1;
TABLE[171][126] = 1;
TABLE[171][45] = 1;
TABLE[171][43] = 1;
TABLE[171][42] = 1;
TABLE[171][38] = 1;
TABLE[171][40] = 1;
TABLE[171][299] = 1;
TABLE[171][289] = 1;
TABLE[171][303] = 1;
TABLE[171][302] = 1;
TABLE[171][304] = 1;
TABLE[243][93] = 1;
TABLE[173][41] = 1;
TABLE[173][44] = 1;
TABLE[173][267] = 1;
TABLE[173][279] = 1;
TABLE[173][274] = 1;
TABLE[173][256] = 1;
TABLE[173][264] = 1;
TABLE[173][268] = 1;
TABLE[173][259] = 1;
TABLE[173][272] = 1;
TABLE[173][273] = 1;
TABLE[173][276] = 1;
TABLE[173][284] = 1;
TABLE[173][277] = 1;
TABLE[173][285] = 1;
TABLE[173][286] = 1;
TABLE[173][260] = 1;
TABLE[173][266] = 1;
TABLE[173][283] = 1;
TABLE[173][280] = 1;
TABLE[244][41] = 1;
TABLE[59][299] = 1;
TABLE[60][125] = 1;
TABLE[60][265] = 1;
TABLE[60][262] = 1;
TABLE[60][258] = 1;
TABLE[60][59] = 1;
TABLE[60][123] = 1;
TABLE[60][281] = 1;
TABLE[60][271] = 1;
TABLE[60][275] = 1;
TABLE[60][257] = 1;
TABLE[60][261] = 1;
TABLE[60][270] = 1;
TABLE[60][305] = 1;
TABLE[60][306] = 1;
TABLE[60][299] = 1;
TABLE[60][287] = 1;
TABLE[60][263] = 1;
TABLE[60][269] = 1;
TABLE[60][278] = 1;
TABLE[60][38] = 1;
TABLE[60][42] = 1;
TABLE[60][43] = 1;
TABLE[60][45] = 1;
TABLE[60][126] = 1;
TABLE[60][33] = 1;
TABLE[60][294] = 1;
TABLE[60][295] = 1;
TABLE[60][40] = 1;
TABLE[60][304] = 1;
TABLE[60][302] = 1;
TABLE[60][303] = 1;
TABLE[60][289] = 1;
TABLE[175][258] = 1;
TABLE[175][262] = 1;
TABLE[175][299] = 1;
TABLE[176][125] = 1;
TABLE[176][306] = 1;
TABLE[176][305] = 1;
TABLE[176][270] = 1;
TABLE[176][261] = 1;
TABLE[176][257] = 1;
TABLE[176][275] = 1;
TABLE[176][271] = 1;
TABLE[176][281] = 1;
TABLE[176][123] = 1;
TABLE[176][258] = 1;
TABLE[176][262] = 1;
TABLE[176][269] = 1;
TABLE[176][263] = 1;
TABLE[176][287] = 1;
TABLE[176][265] = 1;
TABLE[176][59] = 1;
TABLE[176][278] = 1;
TABLE[176][295] = 1;
TABLE[176][294] = 1;
TABLE[176][33] = 1;
TABLE[176][126] = 1;
TABLE[176][45] = 1;
TABLE[176][43] = 1;
TABLE[176][42] = 1;
TABLE[176][38] = 1;
TABLE[176][40] = 1;
TABLE[176][299] = 1;
TABLE[176][289] = 1;
TABLE[176][303] = 1;
TABLE[176][302] = 1;
TABLE[176][304] = 1;
TABLE[177][123] = 1;
TABLE[178][271] = 1;
TABLE[178][281] = 1;
TABLE[179][269] = 1;
TABLE[179][263] = 1;
TABLE[179][287] = 1;
TABLE[180][270] = 1;
TABLE[180][261] = 1;
TABLE[180][257] = 1;
TABLE[180][275] = 1;
TABLE[181][305] = 1;
TABLE[182][306] = 1;
TABLE[61][299] = 1;
TABLE[62][258] = 1;
TABLE[63][262] = 1;
TABLE[64][59] = 1;
TABLE[64][278] = 1;
TABLE[64][38] = 1;
TABLE[64][42] = 1;
TABLE[64][43] = 1;
TABLE[64][45] = 1;
TABLE[64][126] = 1;
TABLE[64][33] = 1;
TABLE[64][294] = 1;
TABLE[64][295] = 1;
TABLE[64][40] = 1;
TABLE[64][304] = 1;
TABLE[64][302] = 1;
TABLE[64][303] = 1;
TABLE[64][289] = 1;
TABLE[64][299] = 1;
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
TABLE[245][59] = 1;
TABLE[65][123] = 1;
TABLE[184][306] = 1;
TABLE[184][305] = 1;
TABLE[184][270] = 1;
TABLE[184][261] = 1;
TABLE[184][257] = 1;
TABLE[184][275] = 1;
TABLE[184][271] = 1;
TABLE[184][281] = 1;
TABLE[184][123] = 1;
TABLE[184][59] = 1;
TABLE[184][258] = 1;
TABLE[184][262] = 1;
TABLE[184][269] = 1;
TABLE[184][263] = 1;
TABLE[184][287] = 1;
TABLE[184][299] = 1;
TABLE[184][278] = 1;
TABLE[184][295] = 1;
TABLE[184][294] = 1;
TABLE[184][33] = 1;
TABLE[184][126] = 1;
TABLE[184][45] = 1;
TABLE[184][43] = 1;
TABLE[184][42] = 1;
TABLE[184][38] = 1;
TABLE[184][40] = 1;
TABLE[184][289] = 1;
TABLE[184][303] = 1;
TABLE[184][302] = 1;
TABLE[184][304] = 1;
TABLE[184][125] = 1;
TABLE[184][260] = 1;
TABLE[184][286] = 1;
TABLE[184][285] = 1;
TABLE[184][277] = 1;
TABLE[184][284] = 1;
TABLE[184][276] = 1;
TABLE[184][273] = 1;
TABLE[184][272] = 1;
TABLE[184][259] = 1;
TABLE[184][268] = 1;
TABLE[184][264] = 1;
TABLE[184][256] = 1;
TABLE[184][274] = 1;
TABLE[184][279] = 1;
TABLE[184][267] = 1;
TABLE[184][266] = 1;
TABLE[184][280] = 1;
TABLE[184][283] = 1;
TABLE[246][306] = 1;
TABLE[246][305] = 1;
TABLE[246][270] = 1;
TABLE[246][261] = 1;
TABLE[246][257] = 1;
TABLE[246][275] = 1;
TABLE[246][271] = 1;
TABLE[246][281] = 1;
TABLE[246][123] = 1;
TABLE[246][59] = 1;
TABLE[246][258] = 1;
TABLE[246][262] = 1;
TABLE[246][269] = 1;
TABLE[246][263] = 1;
TABLE[246][287] = 1;
TABLE[246][299] = 1;
TABLE[246][278] = 1;
TABLE[246][295] = 1;
TABLE[246][294] = 1;
TABLE[246][33] = 1;
TABLE[246][126] = 1;
TABLE[246][45] = 1;
TABLE[246][43] = 1;
TABLE[246][42] = 1;
TABLE[246][38] = 1;
TABLE[246][40] = 1;
TABLE[246][289] = 1;
TABLE[246][303] = 1;
TABLE[246][302] = 1;
TABLE[246][304] = 1;
TABLE[246][125] = 1;
TABLE[185][125] = 1;
TABLE[185][262] = 1;
TABLE[185][258] = 1;
TABLE[185][59] = 1;
TABLE[185][123] = 1;
TABLE[185][281] = 1;
TABLE[185][271] = 1;
TABLE[185][275] = 1;
TABLE[185][257] = 1;
TABLE[185][261] = 1;
TABLE[185][270] = 1;
TABLE[185][305] = 1;
TABLE[185][306] = 1;
TABLE[185][299] = 1;
TABLE[185][287] = 1;
TABLE[185][263] = 1;
TABLE[185][269] = 1;
TABLE[185][278] = 1;
TABLE[185][38] = 1;
TABLE[185][42] = 1;
TABLE[185][43] = 1;
TABLE[185][45] = 1;
TABLE[185][126] = 1;
TABLE[185][33] = 1;
TABLE[185][294] = 1;
TABLE[185][295] = 1;
TABLE[185][40] = 1;
TABLE[185][304] = 1;
TABLE[185][302] = 1;
TABLE[185][303] = 1;
TABLE[185][289] = 1;
TABLE[247][125] = 1;
TABLE[66][125] = 1;
TABLE[66][262] = 1;
TABLE[66][258] = 1;
TABLE[66][59] = 1;
TABLE[66][123] = 1;
TABLE[66][281] = 1;
TABLE[66][271] = 1;
TABLE[66][275] = 1;
TABLE[66][257] = 1;
TABLE[66][261] = 1;
TABLE[66][270] = 1;
TABLE[66][305] = 1;
TABLE[66][306] = 1;
TABLE[66][299] = 1;
TABLE[66][287] = 1;
TABLE[66][263] = 1;
TABLE[66][269] = 1;
TABLE[66][278] = 1;
TABLE[66][38] = 1;
TABLE[66][42] = 1;
TABLE[66][43] = 1;
TABLE[66][45] = 1;
TABLE[66][126] = 1;
TABLE[66][33] = 1;
TABLE[66][294] = 1;
TABLE[66][295] = 1;
TABLE[66][40] = 1;
TABLE[66][304] = 1;
TABLE[66][302] = 1;
TABLE[66][303] = 1;
TABLE[66][289] = 1;
TABLE[186][125] = 1;
TABLE[186][306] = 1;
TABLE[186][305] = 1;
TABLE[186][270] = 1;
TABLE[186][261] = 1;
TABLE[186][257] = 1;
TABLE[186][275] = 1;
TABLE[186][271] = 1;
TABLE[186][281] = 1;
TABLE[186][123] = 1;
TABLE[186][59] = 1;
TABLE[186][258] = 1;
TABLE[186][262] = 1;
TABLE[186][269] = 1;
TABLE[186][263] = 1;
TABLE[186][287] = 1;
TABLE[186][299] = 1;
TABLE[186][278] = 1;
TABLE[186][295] = 1;
TABLE[186][294] = 1;
TABLE[186][33] = 1;
TABLE[186][126] = 1;
TABLE[186][45] = 1;
TABLE[186][43] = 1;
TABLE[186][42] = 1;
TABLE[186][38] = 1;
TABLE[186][40] = 1;
TABLE[186][289] = 1;
TABLE[186][303] = 1;
TABLE[186][302] = 1;
TABLE[186][304] = 1;
TABLE[248][306] = 1;
TABLE[248][305] = 1;
TABLE[248][270] = 1;
TABLE[248][261] = 1;
TABLE[248][257] = 1;
TABLE[248][275] = 1;
TABLE[248][271] = 1;
TABLE[248][281] = 1;
TABLE[248][123] = 1;
TABLE[248][59] = 1;
TABLE[248][258] = 1;
TABLE[248][262] = 1;
TABLE[248][269] = 1;
TABLE[248][263] = 1;
TABLE[248][287] = 1;
TABLE[248][299] = 1;
TABLE[248][278] = 1;
TABLE[248][295] = 1;
TABLE[248][294] = 1;
TABLE[248][33] = 1;
TABLE[248][126] = 1;
TABLE[248][45] = 1;
TABLE[248][43] = 1;
TABLE[248][42] = 1;
TABLE[248][38] = 1;
TABLE[248][40] = 1;
TABLE[248][289] = 1;
TABLE[248][303] = 1;
TABLE[248][302] = 1;
TABLE[248][304] = 1;
TABLE[248][125] = 1;
TABLE[67][271] = 1;
TABLE[68][281] = 1;
TABLE[187][265] = 1;
TABLE[249][125] = 1;
TABLE[249][306] = 1;
TABLE[249][305] = 1;
TABLE[249][270] = 1;
TABLE[249][261] = 1;
TABLE[249][257] = 1;
TABLE[249][275] = 1;
TABLE[249][271] = 1;
TABLE[249][281] = 1;
TABLE[249][123] = 1;
TABLE[249][59] = 1;
TABLE[249][258] = 1;
TABLE[249][262] = 1;
TABLE[249][269] = 1;
TABLE[249][263] = 1;
TABLE[249][287] = 1;
TABLE[249][299] = 1;
TABLE[249][278] = 1;
TABLE[249][295] = 1;
TABLE[249][294] = 1;
TABLE[249][33] = 1;
TABLE[249][126] = 1;
TABLE[249][45] = 1;
TABLE[249][43] = 1;
TABLE[249][42] = 1;
TABLE[249][38] = 1;
TABLE[249][40] = 1;
TABLE[249][289] = 1;
TABLE[249][303] = 1;
TABLE[249][302] = 1;
TABLE[249][304] = 1;
TABLE[249][265] = 1;
TABLE[69][287] = 1;
TABLE[69][263] = 1;
TABLE[69][269] = 1;
TABLE[188][287] = 1;
TABLE[189][263] = 1;
TABLE[193][269] = 1;
TABLE[190][278] = 1;
TABLE[190][295] = 1;
TABLE[190][294] = 1;
TABLE[190][33] = 1;
TABLE[190][126] = 1;
TABLE[190][45] = 1;
TABLE[190][43] = 1;
TABLE[190][42] = 1;
TABLE[190][38] = 1;
TABLE[190][40] = 1;
TABLE[190][299] = 1;
TABLE[190][289] = 1;
TABLE[190][303] = 1;
TABLE[190][302] = 1;
TABLE[190][304] = 1;
TABLE[250][59] = 1;
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
TABLE[191][299] = 1;
TABLE[191][289] = 1;
TABLE[191][303] = 1;
TABLE[191][302] = 1;
TABLE[191][304] = 1;
TABLE[251][59] = 1;
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
TABLE[252][41] = 1;
TABLE[70][270] = 1;
TABLE[71][261] = 1;
TABLE[72][257] = 1;
TABLE[73][275] = 1;
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
TABLE[74][305] = 1;
TABLE[75][306] = 1;
TABLE[195][299] = 1;
TABLE[254][299] = 1;
TABLE[76][278] = 1;
TABLE[76][38] = 1;
TABLE[76][42] = 1;
TABLE[76][43] = 1;
TABLE[76][45] = 1;
TABLE[76][126] = 1;
TABLE[76][33] = 1;
TABLE[76][294] = 1;
TABLE[76][295] = 1;
TABLE[76][40] = 1;
TABLE[76][304] = 1;
TABLE[76][302] = 1;
TABLE[76][303] = 1;
TABLE[76][289] = 1;
TABLE[76][299] = 1;
TABLE[77][278] = 1;
TABLE[77][295] = 1;
TABLE[77][294] = 1;
TABLE[77][33] = 1;
TABLE[77][126] = 1;
TABLE[77][45] = 1;
TABLE[77][43] = 1;
TABLE[77][42] = 1;
TABLE[77][38] = 1;
TABLE[77][40] = 1;
TABLE[77][299] = 1;
TABLE[77][289] = 1;
TABLE[77][303] = 1;
TABLE[77][302] = 1;
TABLE[77][304] = 1;
TABLE[78][40] = 1;
TABLE[78][278] = 1;
TABLE[78][38] = 1;
TABLE[78][42] = 1;
TABLE[78][43] = 1;
TABLE[78][45] = 1;
TABLE[78][126] = 1;
TABLE[78][33] = 1;
TABLE[78][294] = 1;
TABLE[78][295] = 1;
TABLE[78][304] = 1;
TABLE[78][302] = 1;
TABLE[78][303] = 1;
TABLE[78][289] = 1;
TABLE[78][299] = 1;
TABLE[79][278] = 1;
TABLE[79][295] = 1;
TABLE[79][294] = 1;
TABLE[79][33] = 1;
TABLE[79][126] = 1;
TABLE[79][45] = 1;
TABLE[79][43] = 1;
TABLE[79][42] = 1;
TABLE[79][38] = 1;
TABLE[79][40] = 1;
TABLE[79][299] = 1;
TABLE[79][289] = 1;
TABLE[79][303] = 1;
TABLE[79][302] = 1;
TABLE[79][304] = 1;
TABLE[80][291] = 1;
TABLE[81][61] = 1;
TABLE[82][40] = 1;
TABLE[82][278] = 1;
TABLE[82][295] = 1;
TABLE[82][294] = 1;
TABLE[82][33] = 1;
TABLE[82][126] = 1;
TABLE[82][45] = 1;
TABLE[82][43] = 1;
TABLE[82][42] = 1;
TABLE[82][38] = 1;
TABLE[82][299] = 1;
TABLE[82][289] = 1;
TABLE[82][303] = 1;
TABLE[82][302] = 1;
TABLE[82][304] = 1;
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
TABLE[84][38] = 1;
TABLE[84][42] = 1;
TABLE[84][43] = 1;
TABLE[84][45] = 1;
TABLE[84][126] = 1;
TABLE[84][33] = 1;
TABLE[84][294] = 1;
TABLE[84][295] = 1;
TABLE[84][304] = 1;
TABLE[84][302] = 1;
TABLE[84][303] = 1;
TABLE[84][289] = 1;
TABLE[84][299] = 1;
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
TABLE[86][303] = 1;
TABLE[86][302] = 1;
TABLE[86][304] = 1;
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
TABLE[88][38] = 1;
TABLE[88][42] = 1;
TABLE[88][43] = 1;
TABLE[88][45] = 1;
TABLE[88][126] = 1;
TABLE[88][33] = 1;
TABLE[88][294] = 1;
TABLE[88][295] = 1;
TABLE[88][304] = 1;
TABLE[88][302] = 1;
TABLE[88][303] = 1;
TABLE[88][289] = 1;
TABLE[88][299] = 1;
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
TABLE[196][43] = 1;
TABLE[197][45] = 1;
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
TABLE[198][42] = 1;
TABLE[199][47] = 1;
TABLE[200][37] = 1;
TABLE[103][278] = 1;
TABLE[103][295] = 1;
TABLE[103][294] = 1;
TABLE[103][33] = 1;
TABLE[103][126] = 1;
TABLE[103][45] = 1;
TABLE[103][43] = 1;
TABLE[103][42] = 1;
TABLE[103][38] = 1;
TABLE[103][40] = 1;
TABLE[103][299] = 1;
TABLE[103][289] = 1;
TABLE[103][303] = 1;
TABLE[103][302] = 1;
TABLE[103][304] = 1;
TABLE[104][40] = 1;
TABLE[105][40] = 1;
TABLE[105][304] = 1;
TABLE[105][302] = 1;
TABLE[105][303] = 1;
TABLE[105][289] = 1;
TABLE[105][299] = 1;
TABLE[106][294] = 1;
TABLE[106][295] = 1;
TABLE[107][38] = 1;
TABLE[107][42] = 1;
TABLE[107][43] = 1;
TABLE[107][45] = 1;
TABLE[107][126] = 1;
TABLE[107][33] = 1;
TABLE[108][278] = 1;
TABLE[109][278] = 1;
TABLE[201][294] = 1;
TABLE[202][295] = 1;
TABLE[110][38] = 1;
TABLE[111][42] = 1;
TABLE[112][43] = 1;
TABLE[113][45] = 1;
TABLE[114][126] = 1;
TABLE[115][33] = 1;
TABLE[116][40] = 1;
TABLE[116][299] = 1;
TABLE[116][289] = 1;
TABLE[116][303] = 1;
TABLE[116][302] = 1;
TABLE[116][304] = 1;
TABLE[117][40] = 1;
TABLE[117][304] = 1;
TABLE[117][302] = 1;
TABLE[117][303] = 1;
TABLE[117][289] = 1;
TABLE[117][299] = 1;
TABLE[204][91] = 1;
TABLE[206][40] = 1;
TABLE[207][46] = 1;
TABLE[208][296] = 1;
TABLE[209][294] = 1;
TABLE[210][295] = 1;
TABLE[203][58] = 1;
TABLE[255][93] = 1;
TABLE[205][41] = 1;
TABLE[205][278] = 1;
TABLE[205][295] = 1;
TABLE[205][294] = 1;
TABLE[205][33] = 1;
TABLE[205][126] = 1;
TABLE[205][45] = 1;
TABLE[205][43] = 1;
TABLE[205][42] = 1;
TABLE[205][38] = 1;
TABLE[205][40] = 1;
TABLE[205][299] = 1;
TABLE[205][289] = 1;
TABLE[205][303] = 1;
TABLE[205][302] = 1;
TABLE[205][304] = 1;
TABLE[256][41] = 1;
TABLE[118][299] = 1;
TABLE[119][304] = 1;
TABLE[119][302] = 1;
TABLE[119][303] = 1;
TABLE[119][289] = 1;
TABLE[120][40] = 1;
TABLE[121][278] = 1;
TABLE[121][295] = 1;
TABLE[121][294] = 1;
TABLE[121][33] = 1;
TABLE[121][126] = 1;
TABLE[121][45] = 1;
TABLE[121][43] = 1;
TABLE[121][42] = 1;
TABLE[121][38] = 1;
TABLE[121][40] = 1;
TABLE[121][299] = 1;
TABLE[121][289] = 1;
TABLE[121][303] = 1;
TABLE[121][302] = 1;
TABLE[121][304] = 1;
TABLE[211][278] = 1;
TABLE[211][38] = 1;
TABLE[211][42] = 1;
TABLE[211][43] = 1;
TABLE[211][45] = 1;
TABLE[211][126] = 1;
TABLE[211][33] = 1;
TABLE[211][294] = 1;
TABLE[211][295] = 1;
TABLE[211][40] = 1;
TABLE[211][304] = 1;
TABLE[211][302] = 1;
TABLE[211][303] = 1;
TABLE[211][289] = 1;
TABLE[211][299] = 1;
TABLE[257][278] = 1;
TABLE[257][38] = 1;
TABLE[257][42] = 1;
TABLE[257][43] = 1;
TABLE[257][45] = 1;
TABLE[257][126] = 1;
TABLE[257][33] = 1;
TABLE[257][294] = 1;
TABLE[257][295] = 1;
TABLE[257][40] = 1;
TABLE[257][304] = 1;
TABLE[257][302] = 1;
TABLE[257][303] = 1;
TABLE[257][289] = 1;
TABLE[257][299] = 1;
TABLE[122][304] = 1;
TABLE[123][302] = 1;
TABLE[124][303] = 1;
TABLE[125][289] = 1;
TABLE[126][299] = 1;
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
      case 121: return 0; break;
      case 165: return 0; break;
      case 173: return 0; break;
      case 186: return 1; break;
      case 193: return 0; break;
      case 201: return 1; break;
      case 206: return 1; break;
      case 213: return 1; break;
      case 218: return 1; break;
      case 226: return 1; break;
      case 231: return 1; break;
      case 239: return 0; break;
      case 245: return 0; break;
      case 250: return 0; break;
      case 258: return 1; break;
      case 265: return 1; break;
      case 270: return 1; break;
      case 278: return 1; break;
      case 288: return 1; break;
      case 295: return 0; break;
      case 308: return 1; break;
      case 315: return 1; break;
      case 320: return 1; break;
      case 328: return 0; break;
      case 333: return 1; break;
      case 341: return 1; break;
      case 346: return 1; break;
      case 353: return 0; break;
      case 368: return 0; break;
      case 386: return 1; break;
      case 393: return 1; break;
      case 400: return 0; break;
      case 406: return 1; break;
      case 413: return 1; break;
      case 420: return 1; break;
      case 425: return 1; break;
      case 432: return 1; break;
      case 437: return 1; break;
      case 445: return 1; break;
      case 450: return 1; break;
      case 458: return 0; break;
      case 463: return 1; break;
      case 471: return 1; break;
      case 478: return 1; break;
      case 483: return 1; break;
      case 491: return 0; break;
      case 502: return 1; break;
      case 509: return 1; break;
      case 514: return 1; break;
      case 522: return 0; break;
      case 527: return 1; break;
      case 534: return 1; break;
      case 543: return 1; break;
      case 550: return 1; break;
      case 561: return 1; break;
      case 568: return 0; break;
      case 580: return 1; break;
      case 587: return 1; break;
      case 594: return 0; break;
      case 598: return 1; break;
      case 602: return 1; break;
      case 634: return 0; break;
      case 653: return 1; break;
      case 658: return 1; break;
      case 665: return 0; break;
      case 672: return 1; break;
      case 679: return 1; break;
      case 686: return 1; break;
      case 691: return 1; break;
      case 699: return 0; break;
      case 716: return 1; break;
      case 724: return 0; break;
      case 728: return 0; break;
      case 758: return 1; break;
      case 765: return 1; break;
      case 772: return 1; break;
      case 779: return 0; break;
      case 801: return 1; break;
      case 808: return 0; break;
      case 814: return 0; break;
      case 821: return 1; break;
      case 830: return 0; break;
      case 840: return 0; break;
      case 850: return 0; break;
      case 858: return 0; break;
      case 870: return 0; break;
      case 874: return 0; break;
      case 884: return 0; break;
      case 894: return 0; break;
      case 904: return 0; break;
      case 914: return 0; break;
      case 924: return 0; break;
      case 934: return 0; break;
      case 944: return 0; break;
      case 954: return 0; break;
      case 962: return 0; break;
      case 972: return 0; break;
      case 984: return 0; break;
      case 995: return 0; break;
      case 1021: return 0; break;
      case 1029: return 0; break;
      case 1053: return 0; break;
      case 1062: return 0; break;
      case 1093: return 1; break;
      case 1101: return 1; break;
      case 1108: return 0; break;
      case 1122: return 1; break;
      case 1127: return 1; break;
      case 1136: return 0; break;
      case 1152: return 0; break;
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
         case 121: return "type_specifier"; break;
         case 165: return "type_qualifier"; break;
         case 173: return "struct_or_union_specifier"; break;
         case 186: return "Subphrase"; break;
         case 193: return "struct_or_union"; break;
         case 201: return "struct_declaration_list"; break;
         case 206: return "Subphrase"; break;
         case 213: return "init_declarator_list"; break;
         case 218: return "Subphrase"; break;
         case 226: return "init_declarator"; break;
         case 231: return "Subphrase"; break;
         case 239: return "struct_declaration"; break;
         case 245: return "specifier_qualifier_list"; break;
         case 250: return "Subphrase"; break;
         case 258: return "Subphrase"; break;
         case 265: return "struct_declarator_list"; break;
         case 270: return "Subphrase"; break;
         case 278: return "struct_declarator"; break;
         case 288: return "Subphrase"; break;
         case 295: return "enum_specifier"; break;
         case 308: return "Subphrase"; break;
         case 315: return "enumerator_list"; break;
         case 320: return "Subphrase"; break;
         case 328: return "enumerator"; break;
         case 333: return "Subphrase"; break;
         case 341: return "declarator"; break;
         case 346: return "Subphrase"; break;
         case 353: return "direct_declarator"; break;
         case 368: return "Subphrase"; break;
         case 386: return "Subphrase"; break;
         case 393: return "Subphrase"; break;
         case 400: return "pointer"; break;
         case 406: return "Subphrase"; break;
         case 413: return "Subphrase"; break;
         case 420: return "type_qualifier_list"; break;
         case 425: return "Subphrase"; break;
         case 432: return "parameter_type_list"; break;
         case 437: return "Subphrase"; break;
         case 445: return "parameter_list"; break;
         case 450: return "Subphrase"; break;
         case 458: return "parameter_declaration"; break;
         case 463: return "Subphrase"; break;
         case 471: return "Subphrase"; break;
         case 478: return "identifier_list"; break;
         case 483: return "Subphrase"; break;
         case 491: return "initializer"; break;
         case 502: return "Subphrase"; break;
         case 509: return "initializer_list"; break;
         case 514: return "Subphrase"; break;
         case 522: return "type_name"; break;
         case 527: return "Subphrase"; break;
         case 534: return "abstract_declarator"; break;
         case 543: return "Subphrase"; break;
         case 550: return "direct_abstract_declarator"; break;
         case 561: return "Subphrase"; break;
         case 568: return "Subphrase"; break;
         case 580: return "Subphrase"; break;
         case 587: return "Subphrase"; break;
         case 594: return "typedef_name"; break;
         case 598: return "statement"; break;
         case 602: return "Subphrase"; break;
         case 634: return "labeled_statement"; break;
         case 653: return "expression_statement"; break;
         case 658: return "Subphrase"; break;
         case 665: return "compound_statement"; break;
         case 672: return "Subphrase"; break;
         case 679: return "Subphrase"; break;
         case 686: return "statement_list"; break;
         case 691: return "Subphrase"; break;
         case 699: return "selection_statement"; break;
         case 716: return "Subphrase"; break;
         case 724: return "iteration_statement"; break;
         case 728: return "Subphrase"; break;
         case 758: return "Subphrase"; break;
         case 765: return "Subphrase"; break;
         case 772: return "Subphrase"; break;
         case 779: return "jump_statement"; break;
         case 801: return "Subphrase"; break;
         case 808: return "print_statement"; break;
         case 814: return "input_statement"; break;
         case 821: return "Subphrase"; break;
         case 830: return "expression"; break;
         case 840: return "assignment_expression"; break;
         case 850: return "assignment_operator"; break;
         case 858: return "conditional_expression"; break;
         case 870: return "constant_expression"; break;
         case 874: return "logical_OR_expression"; break;
         case 884: return "logical_AND_expression"; break;
         case 894: return "inclusive_OR_expression"; break;
         case 904: return "exclusive_OR_expression"; break;
         case 914: return "AND_expression"; break;
         case 924: return "equality_expression"; break;
         case 934: return "shift_expression"; break;
         case 944: return "additive_expression"; break;
         case 954: return "Subphrase"; break;
         case 962: return "multiplicative_expression"; break;
         case 972: return "Subphrase"; break;
         case 984: return "cast_expression"; break;
         case 995: return "unary_expression"; break;
         case 1021: return "Subphrase"; break;
         case 1029: return "unary_operator"; break;
         case 1053: return "postfix_expression"; break;
         case 1062: return "Subphrase"; break;
         case 1093: return "Subphrase"; break;
         case 1101: return "Subphrase"; break;
         case 1108: return "primary_expression"; break;
         case 1122: return "argument_expression_list"; break;
         case 1127: return "Subphrase"; break;
         case 1136: return "constant"; break;
         case 1152: return "id"; break;
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
