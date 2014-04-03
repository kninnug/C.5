#line 6 "ass3.acc"

	#include <stdio.h>
	#include <stdlib.h>
	
	#include "parser.h"

# line 9 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 103: {
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
         case 104: {
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
      case 105: {
         declaration_specifiers();
         } break;
      default: ;
      }
      declarator();
      switch (yyselect()) {
      case 106: {
         declaration_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 107: {
         get_lexval();
         } break;
      case 108: {
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
      case 109: {
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
         case 110: {
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
   int c;
   int q;
   switch(yyselect()) {
   case 7: {
      switch (yyselect()) {
      case 111: {
         storage_class_specifier(&c);
         } break;
      case 112: {
         type_specifier();
         } break;
      case 113: {
         type_qualifier(&q);
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 114: {
         declaration_specifiers();
         } break;
      default: ;
      }
      } break;
   }
}

storage_class_specifier (c)
   int *c;
{
   switch(yyselect()) {
   case 8: {
      get_lexval();
#line 47 "ass3.acc"
 *c = 1; 
# line 155 "yygrammar.c"
      } break;
   case 9: {
      get_lexval();
#line 48 "ass3.acc"
 *c = 2; 
# line 161 "yygrammar.c"
      } break;
   case 10: {
      get_lexval();
#line 49 "ass3.acc"
 *c = 4; 
# line 167 "yygrammar.c"
      } break;
   case 11: {
      get_lexval();
#line 50 "ass3.acc"
 *c = 8; 
# line 173 "yygrammar.c"
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
   }
}

type_qualifier (q)
   int *q;
{
   switch(yyselect()) {
   case 21: {
      get_lexval();
#line 68 "ass3.acc"
 *q = 1; 
# line 219 "yygrammar.c"
      } break;
   case 22: {
      get_lexval();
#line 69 "ass3.acc"
 *q = 2; 
# line 225 "yygrammar.c"
      } break;
   }
}

init_declarator_list ()
{
   switch(yyselect()) {
   case 23: {
      switch (yyselect()) {
      case 115: {
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
   initializer_pt iz;
   switch(yyselect()) {
   case 24: {
      declarator();
      switch (yyselect()) {
      case 116: {
         get_lexval();
         initializer(&iz);
#line 77 "ass3.acc"
 printInitializer(iz); 
# line 258 "yygrammar.c"
         } break;
      default: ;
      }
      } break;
   }
}

specifier_qualifier_list ()
{
   int q;
   switch(yyselect()) {
   case 25: {
      switch (yyselect()) {
      case 117: {
         type_specifier();
         } break;
      case 118: {
         type_qualifier(&q);
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 119: {
         specifier_qualifier_list();
         } break;
      default: ;
      }
      } break;
   }
}

declarator ()
{
   constant_pt i;
   expression_pt e;
   identlist_pt il;
   switch(yyselect()) {
   case 26: {
      id(&i);
      } break;
   case 27: {
      get_lexval();
      declarator();
      get_lexval();
      } break;
   case 28: {
      declarator();
      switch (yyselect()) {
      case 121: {
         get_lexval();
         switch (yyselect()) {
         case 120: {
            expression(&e);
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 122: {
         get_lexval();
         parameter_type_list();
         get_lexval();
         } break;
      case 124: {
         get_lexval();
         switch (yyselect()) {
         case 123: {
            identifier_list(&il);
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

type_qualifier_list (qq)
   int *qq;
{
   int q;
   int q2;
   switch(yyselect()) {
   case 29: {
      type_qualifier(&q);
#line 95 "ass3.acc"
 *qq |= q; 
# line 348 "yygrammar.c"
      while (1) {
         switch (yyselect()) {
         case 125: {
            type_qualifier(&q2);
#line 95 "ass3.acc"
 *qq |= q2; 
# line 355 "yygrammar.c"
            } break;
         default: goto yy3;
         }
      }
      yy3: ;
      } break;
   }
}

parameter_type_list ()
{
   switch(yyselect()) {
   case 30: {
      parameter_list();
      switch (yyselect()) {
      case 126: {
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
   case 31: {
      while (1) {
         switch (yyselect()) {
         case 127: {
            parameter_declaration();
            get_lexval();
            } break;
         default: goto yy4;
         }
      }
      yy4: ;
      parameter_declaration();
      } break;
   }
}

parameter_declaration ()
{
   switch(yyselect()) {
   case 32: {
      declaration_specifiers();
      switch (yyselect()) {
      case 128: {
         declarator();
         } break;
      case 129: {
         abstract_declarator();
         } break;
      default: ;
      }
      } break;
   }
}

identifier_list (il)
   identlist_pt *il;
{
   constant_pt i;
   constant_pt i2;
   switch(yyselect()) {
   case 33: {
#line 111 "ass3.acc"
 *il = makeIdentlist(); 
# line 427 "yygrammar.c"
      while (1) {
         switch (yyselect()) {
         case 130: {
            id(&i);
#line 111 "ass3.acc"
 growIdentlist(*il, i); 
# line 434 "yygrammar.c"
            get_lexval();
            } break;
         default: goto yy5;
         }
      }
      yy5: ;
      id(&i2);
#line 111 "ass3.acc"
 growIdentlist(*il, i2); 
# line 444 "yygrammar.c"
      } break;
   }
}

initializer (i)
   initializer_pt *i;
{
   expression_pt ae;
   switch(yyselect()) {
   case 34: {
#line 115 "ass3.acc"
 *i = makeInitializer(); fprintf(stderr, "Initializate!\n"); 
# line 457 "yygrammar.c"
      switch (yyselect()) {
      case 131: {
         assignment_expression(&ae);
#line 116 "ass3.acc"
 growInitializera(*i, ae); 
# line 463 "yygrammar.c"
         } break;
      case 133: {
         get_lexval();
         initializer_list(*i);
         switch (yyselect()) {
         case 132: {
            get_lexval();
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

initializer_list (i)
   initializer_pt i;
{
   initializer_pt iz;
   switch(yyselect()) {
   case 35: {
      switch (yyselect()) {
      case 134: {
         initializer_list(i);
         get_lexval();
         } break;
      default: ;
      }
      initializer(&iz);
#line 121 "ass3.acc"
 growInitializeri(i, iz); 
# line 498 "yygrammar.c"
      } break;
   }
}

type_name ()
{
   switch(yyselect()) {
   case 36: {
      specifier_qualifier_list();
      switch (yyselect()) {
      case 135: {
         abstract_declarator();
         } break;
      default: ;
      }
      } break;
   }
}

abstract_declarator ()
{
   expression_pt e;
   switch(yyselect()) {
   case 37: {
      get_lexval();
      abstract_declarator();
      get_lexval();
      } break;
   case 38: {
      switch (yyselect()) {
      case 136: {
         abstract_declarator();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 138: {
         get_lexval();
         switch (yyselect()) {
         case 137: {
            expression(&e);
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 140: {
         get_lexval();
         switch (yyselect()) {
         case 139: {
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

statement (ret)
   statement_pt *ret;
{
   expstatement_pt es;
   compstatement_pt cs;
   statement_pt s;
   switch(yyselect()) {
   case 39: {
#line 135 "ass3.acc"
 *ret = makeStatement(); (*ret)->type = 0; 
# line 571 "yygrammar.c"
      switch (yyselect()) {
      case 141: {
         labeled_statement();
#line 136 "ass3.acc"
 fprintf(stderr, "Label!\n"); 
# line 577 "yygrammar.c"
         } break;
      case 142: {
         expression_statement(&es);
#line 137 "ass3.acc"
 fprintf(stderr, "Express!\n"); (*ret)->type = 'e'; (*ret)->exps = es; 
# line 583 "yygrammar.c"
         } break;
      case 143: {
         compound_statement(&cs);
#line 138 "ass3.acc"
 fprintf(stderr, "Confound!\n"); (*ret)->type = 'c'; (*ret)->comps = cs; printStatement(*ret); 
# line 589 "yygrammar.c"
         } break;
      case 144: {
         selection_statement(&s);
#line 139 "ass3.acc"
 fprintf(stderr, "Select!\n"); *ret = s; printStatement(*ret); 
# line 595 "yygrammar.c"
         } break;
      case 145: {
         iteration_statement(&s);
#line 140 "ass3.acc"
 fprintf(stderr, "Iterate!\n"); *ret = s; printStatement(*ret); 
# line 601 "yygrammar.c"
         } break;
      case 146: {
         jump_statement(&s);
#line 141 "ass3.acc"
 fprintf(stderr, "Jump!\n"); 
# line 607 "yygrammar.c"
         } break;
      case 147: {
         print_statement();
#line 142 "ass3.acc"
 fprintf(stderr, "Print!\n"); 
# line 613 "yygrammar.c"
         } break;
      case 148: {
         input_statement();
#line 143 "ass3.acc"
 fprintf(stderr, "Input!\n"); 
# line 619 "yygrammar.c"
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
   case 40: {
      id(&i);
      get_lexval();
      statement(&s);
      } break;
   case 41: {
      get_lexval();
      constant_expression(&ce);
      get_lexval();
      statement(&s);
      } break;
   case 42: {
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
   case 43: {
#line 154 "ass3.acc"
 *ret = NULL; 
# line 660 "yygrammar.c"
      switch (yyselect()) {
      case 149: {
         expression(&e);
#line 154 "ass3.acc"
 printExpression(e, 0); *ret = makeExpStmt(e); 
# line 666 "yygrammar.c"
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
   case 44: {
#line 158 "ass3.acc"
 *cs = makeCompStmt(); 
# line 682 "yygrammar.c"
      get_lexval();
      switch (yyselect()) {
      case 150: {
         declaration_list();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 151: {
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
   case 45: {
      while (1) {
         switch (yyselect()) {
         case 152: {
            statement(&s);
#line 167 "ass3.acc"
 growCompStmt(cs, s); 
# line 713 "yygrammar.c"
            } break;
         default: goto yy6;
         }
      }
      yy6: ;
      statement(&s);
#line 167 "ass3.acc"
 growCompStmt(cs, s); 
# line 722 "yygrammar.c"
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
   case 46: {
      get_lexval();
      get_lexval();
      expression(&e);
      get_lexval();
      statement(&s);
#line 171 "ass3.acc"
 *ss = makeStatement(); (*ss)->type = 'i'; (*ss)->ifs = makeIfStmt(e, s); 
# line 742 "yygrammar.c"
      switch (yyselect()) {
      case 153: {
         get_lexval();
         statement(&se);
#line 172 "ass3.acc"
 (*ss)->ifs->otherwise = se; 
# line 749 "yygrammar.c"
         } break;
      default: ;
      }
      } break;
   case 47: {
      get_lexval();
      get_lexval();
      expression(&e);
      get_lexval();
      statement(&s);
#line 173 "ass3.acc"
 *ss = makeStatement(); (*ss)->type = 's'; (*ss)->switchs = makeSwitchStmt(e, s); 
# line 762 "yygrammar.c"
      } break;
   }
}

iteration_statement (is)
   statement_pt *is;
{
   expression_pt e;
   statement_pt s;
   switch(yyselect()) {
   case 48: {
#line 177 "ass3.acc"
 *is = makeStatement(); 
# line 776 "yygrammar.c"
      switch (yyselect()) {
      case 154: {
         get_lexval();
         get_lexval();
         expression(&e);
         get_lexval();
         statement(&s);
#line 178 "ass3.acc"
 (*is)->type = 'w'; (*is)->whiles = makeWhileStmt(e, s); 
# line 786 "yygrammar.c"
         } break;
      case 155: {
         get_lexval();
         statement(&s);
         get_lexval();
         get_lexval();
         expression(&e);
         get_lexval();
         get_lexval();
#line 179 "ass3.acc"
 (*is)->type = 'w'; (*is)->whiles = makeWhileStmt(e, s); (*is)->whiles->dowhile = 1; 
# line 798 "yygrammar.c"
         } break;
      case 159: {
         get_lexval();
#line 180 "ass3.acc"
 (*is)->type = 'f'; (*is)->fors = makeForStmt(); 
# line 804 "yygrammar.c"
         get_lexval();
         switch (yyselect()) {
         case 156: {
            expression(&e);
#line 180 "ass3.acc"
 (*is)->fors->exp1= e; 
# line 811 "yygrammar.c"
            } break;
         default: ;
         }
         get_lexval();
         switch (yyselect()) {
         case 157: {
            expression(&e);
#line 180 "ass3.acc"
 (*is)->fors->exp2= e; 
# line 821 "yygrammar.c"
            } break;
         default: ;
         }
         get_lexval();
         switch (yyselect()) {
         case 158: {
            expression(&e);
#line 180 "ass3.acc"
 (*is)->fors->exp3= e; 
# line 831 "yygrammar.c"
            } break;
         default: ;
         }
         get_lexval();
         statement(&s);
#line 180 "ass3.acc"
  { (*is)->fors->body= s; } 
# line 839 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

jump_statement (js)
   statement_pt *js;
{
   constant_pt i;
   expression_pt e;
   switch(yyselect()) {
   case 49: {
#line 184 "ass3.acc"
 *js = makeStatement(); 
# line 856 "yygrammar.c"
      switch (yyselect()) {
      case 160: {
         get_lexval();
         id(&i);
         get_lexval();
#line 185 "ass3.acc"
 (*js)->type = 'g'; (*js)->gotos = makeGotoStmt(0, i); 
# line 864 "yygrammar.c"
         } break;
      case 161: {
         get_lexval();
         get_lexval();
#line 186 "ass3.acc"
 (*js)->type = 'g'; (*js)->gotos = makeGotoStmt(0, NULL); 
# line 871 "yygrammar.c"
         } break;
      case 162: {
         get_lexval();
         get_lexval();
#line 187 "ass3.acc"
 (*js)->type = 'g'; (*js)->gotos = makeGotoStmt(1, NULL); 
# line 878 "yygrammar.c"
         } break;
      case 164: {
         get_lexval();
         switch (yyselect()) {
         case 163: {
            expression(&e);
#line 188 "ass3.acc"
 printExpression(e, 0); 
# line 887 "yygrammar.c"
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

print_statement ()
{
   expression_pt ae;
   switch(yyselect()) {
   case 50: {
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
   case 51: {
      get_lexval();
      while (1) {
         switch (yyselect()) {
         case 165: {
            id(&i);
            get_lexval();
            } break;
         default: goto yy7;
         }
      }
      yy7: ;
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
   case 52: {
      assignment_expression(&ae);
#line 200 "ass3.acc"
 *ret = ae; 
# line 943 "yygrammar.c"
      } break;
   case 53: {
      expression(&e);
      get_lexval();
      assignment_expression(&ae);
#line 201 "ass3.acc"
 *ret = makeExpression(1, 2, ',', e, ae); 
# line 951 "yygrammar.c"
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
   case 54: {
      conditional_expression(&ce);
#line 205 "ass3.acc"
 *ret = ce; 
# line 968 "yygrammar.c"
      } break;
   case 55: {
      unary_expression(&ue);
      assignment_operator(&ao);
      assignment_expression(&ae);
#line 206 "ass3.acc"
 *ret = makeExpression(1, 2, ao, ue, ae); 
# line 976 "yygrammar.c"
      } break;
   }
}

assignment_operator (ret)
   int *ret;
{
   switch(yyselect()) {
   case 56: {
      get_lexval();
#line 210 "ass3.acc"
 *ret = yylval.subtype; 
# line 989 "yygrammar.c"
      } break;
   case 57: {
      get_lexval();
#line 211 "ass3.acc"
 *ret = '='; 
# line 995 "yygrammar.c"
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
   case 58: {
      logical_OR_expression(&loe);
#line 215 "ass3.acc"
 *ret = loe; 
# line 1011 "yygrammar.c"
      } break;
   case 59: {
      logical_OR_expression(&loe);
      get_lexval();
      expression(&e);
      get_lexval();
      conditional_expression(&ce);
#line 216 "ass3.acc"
 *ret = makeExpression(1, 3, '?', loe, e, ce); 
# line 1021 "yygrammar.c"
      } break;
   }
}

constant_expression (ret)
   expression_pt *ret;
{
   expression_pt ce;
   switch(yyselect()) {
   case 60: {
      conditional_expression(&ce);
#line 220 "ass3.acc"
 *ret = ce; 
# line 1035 "yygrammar.c"
      } break;
   }
}

logical_OR_expression (ret)
   expression_pt *ret;
{
   expression_pt lae;
   expression_pt loe;
   switch(yyselect()) {
   case 61: {
      logical_AND_expression(&lae);
#line 224 "ass3.acc"
 *ret = lae; 
# line 1050 "yygrammar.c"
      } break;
   case 62: {
      logical_OR_expression(&loe);
      get_lexval();
      logical_AND_expression(&lae);
#line 225 "ass3.acc"
 *ret = makeExpression(1, 2, '||', loe, lae); 
# line 1058 "yygrammar.c"
      } break;
   }
}

logical_AND_expression (ret)
   expression_pt *ret;
{
   expression_pt ioe;
   expression_pt lae;
   switch(yyselect()) {
   case 63: {
      inclusive_OR_expression(&ioe);
#line 229 "ass3.acc"
 *ret = ioe; 
# line 1073 "yygrammar.c"
      } break;
   case 64: {
      logical_AND_expression(&lae);
      get_lexval();
      inclusive_OR_expression(&ioe);
#line 230 "ass3.acc"
 *ret = makeExpression(1, 2, '&&', lae, ioe); 
# line 1081 "yygrammar.c"
      } break;
   }
}

inclusive_OR_expression (ret)
   expression_pt *ret;
{
   expression_pt eoe;
   expression_pt ioe;
   switch(yyselect()) {
   case 65: {
      exclusive_OR_expression(&eoe);
#line 234 "ass3.acc"
 *ret = eoe; 
# line 1096 "yygrammar.c"
      } break;
   case 66: {
      inclusive_OR_expression(&ioe);
      get_lexval();
      exclusive_OR_expression(&eoe);
#line 235 "ass3.acc"
 *ret = makeExpression(1, 2, '|', ioe, eoe); 
# line 1104 "yygrammar.c"
      } break;
   }
}

exclusive_OR_expression (ret)
   expression_pt *ret;
{
   expression_pt ae;
   expression_pt eoe;
   switch(yyselect()) {
   case 67: {
      AND_expression(&ae);
#line 239 "ass3.acc"
 *ret = ae; 
# line 1119 "yygrammar.c"
      } break;
   case 68: {
      exclusive_OR_expression(&eoe);
      get_lexval();
      AND_expression(&ae);
#line 240 "ass3.acc"
 *ret = makeExpression(1, 2, '^', eoe, ae); 
# line 1127 "yygrammar.c"
      } break;
   }
}

AND_expression (ret)
   expression_pt *ret;
{
   expression_pt ee;
   expression_pt ae;
   switch(yyselect()) {
   case 69: {
      equality_expression(&ee);
#line 244 "ass3.acc"
 *ret = ee; 
# line 1142 "yygrammar.c"
      } break;
   case 70: {
      AND_expression(&ae);
      get_lexval();
      equality_expression(&ee);
#line 245 "ass3.acc"
 *ret = makeExpression(1, 2, '&', ae, ee); 
# line 1150 "yygrammar.c"
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
   case 71: {
      shift_expression(&se);
#line 249 "ass3.acc"
 *ret = se; 
# line 1166 "yygrammar.c"
      } break;
   case 72: {
      equality_expression(&ee);
      get_lexval();
      c = yylval;
      shift_expression(&se);
#line 250 "ass3.acc"
 *ret = makeExpression(1, 2, c.subtype, ee, se); 
# line 1175 "yygrammar.c"
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
   case 73: {
      additive_expression(&ae);
#line 254 "ass3.acc"
 *ret = ae; 
# line 1191 "yygrammar.c"
      } break;
   case 74: {
      shift_expression(&se);
      get_lexval();
      s = yylval;
      additive_expression(&ae);
#line 255 "ass3.acc"
 *ret = makeExpression(1, 2, s.subtype, se, ae); 
# line 1200 "yygrammar.c"
      } break;
   }
}

additive_expression (ret)
   expression_pt *ret;
{
   expression_pt me;
   expression_pt ae;
   switch(yyselect()) {
   case 75: {
      multiplicative_expression(&me);
#line 259 "ass3.acc"
 *ret = me; 
# line 1215 "yygrammar.c"
      } break;
   case 76: {
#line 260 "ass3.acc"
 int op = '+'; 
# line 1220 "yygrammar.c"
      additive_expression(&ae);
      switch (yyselect()) {
      case 166: {
         get_lexval();
         } break;
      case 167: {
         get_lexval();
#line 260 "ass3.acc"
 op = '-'; 
# line 1230 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      multiplicative_expression(&me);
#line 260 "ass3.acc"
 *ret = makeExpression(1, 2, op, ae, me); 
# line 1237 "yygrammar.c"
      } break;
   }
}

multiplicative_expression (ret)
   expression_pt *ret;
{
   expression_pt ce;
   expression_pt me;
   switch(yyselect()) {
   case 77: {
      cast_expression(&ce);
#line 264 "ass3.acc"
 *ret = ce; 
# line 1252 "yygrammar.c"
      } break;
   case 78: {
#line 265 "ass3.acc"
 int op = '*'; 
# line 1257 "yygrammar.c"
      multiplicative_expression(&me);
      switch (yyselect()) {
      case 168: {
         get_lexval();
         } break;
      case 169: {
         get_lexval();
#line 265 "ass3.acc"
 op = '/'; 
# line 1267 "yygrammar.c"
         } break;
      case 170: {
         get_lexval();
#line 265 "ass3.acc"
 op = '%'; 
# line 1273 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      cast_expression(&ce);
#line 265 "ass3.acc"
 *ret = makeExpression(1, 2, op, me, ce); 
# line 1280 "yygrammar.c"
      } break;
   }
}

cast_expression (ret)
   expression_pt *ret;
{
   expression_pt ue;
   expression_pt ce;
   switch(yyselect()) {
   case 79: {
      unary_expression(&ue);
#line 269 "ass3.acc"
 *ret =  ue; 
# line 1295 "yygrammar.c"
      } break;
   case 80: {
      get_lexval();
      type_name();
      get_lexval();
      cast_expression(&ce);
#line 270 "ass3.acc"
 *ret = ce; 
# line 1304 "yygrammar.c"
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
   case 81: {
      postfix_expression(&pe);
#line 274 "ass3.acc"
 *ret = pe; 
# line 1321 "yygrammar.c"
      } break;
   case 82: {
#line 275 "ass3.acc"
 int t; 
# line 1326 "yygrammar.c"
      switch (yyselect()) {
      case 171: {
         get_lexval();
#line 275 "ass3.acc"
t = '++x';
# line 1332 "yygrammar.c"
         } break;
      case 172: {
         get_lexval();
#line 275 "ass3.acc"
t = '--x'; 
# line 1338 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      unary_expression(&ue);
#line 275 "ass3.acc"
 *ret = makeExpression(1, 1, t, ue); 
# line 1345 "yygrammar.c"
      } break;
   case 83: {
      unary_operator(&op);
      cast_expression(&ce);
#line 276 "ass3.acc"
 *ret = makeExpression(1, 1, op, ce); 
# line 1352 "yygrammar.c"
      } break;
   case 84: {
      get_lexval();
      unary_expression(&ue);
#line 277 "ass3.acc"
 *ret = ue; 
# line 1359 "yygrammar.c"
      } break;
   case 85: {
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
   case 86: {
      get_lexval();
#line 282 "ass3.acc"
 *op = '&'; 
# line 1378 "yygrammar.c"
      } break;
   case 87: {
      get_lexval();
#line 283 "ass3.acc"
 *op = '*'; 
# line 1384 "yygrammar.c"
      } break;
   case 88: {
      get_lexval();
#line 284 "ass3.acc"
 *op = '+'; 
# line 1390 "yygrammar.c"
      } break;
   case 89: {
      get_lexval();
#line 285 "ass3.acc"
 *op = '-'; 
# line 1396 "yygrammar.c"
      } break;
   case 90: {
      get_lexval();
#line 286 "ass3.acc"
 *op = '~'; 
# line 1402 "yygrammar.c"
      } break;
   case 91: {
      get_lexval();
#line 287 "ass3.acc"
 *op = '!'; 
# line 1408 "yygrammar.c"
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
   case 92: {
      primary_expression(&pe);
#line 291 "ass3.acc"
 *ret = pe; 
# line 1425 "yygrammar.c"
      } break;
   case 93: {
      postfix_expression(&pe);
#line 292 "ass3.acc"
 *ret = makeExpression(1, 1, 0, pe); fprintf(stderr, "@ PE: "); printExpression(*ret, 0); 
# line 1431 "yygrammar.c"
      switch (yyselect()) {
      case 174: {
         get_lexval();
         expression(&e);
#line 293 "ass3.acc"
 appendExpression(*ret, e); 
# line 1438 "yygrammar.c"
         switch (yyselect()) {
         case 173: {
            get_lexval();
            expression(&e);
#line 293 "ass3.acc"
 appendExpression(*ret, e); 
# line 1445 "yygrammar.c"
            } break;
         default: ;
         }
         get_lexval();
#line 293 "ass3.acc"
 (*ret)->operator = '[]'; 
# line 1452 "yygrammar.c"
         } break;
      case 176: {
         get_lexval();
         switch (yyselect()) {
         case 175: {
            argument_expression_list(&ae);
#line 294 "ass3.acc"
 appendExpression(*ret, ae); 
# line 1461 "yygrammar.c"
            } break;
         default: ;
         }
         get_lexval();
#line 294 "ass3.acc"
 (*ret)->operator = '()'; 
# line 1468 "yygrammar.c"
         } break;
      case 177: {
         get_lexval();
         id(&i);
#line 295 "ass3.acc"
 appendExpression(*ret, makeExpression(0, 1, 0, i)); (*ret)->operator = '.'; 
# line 1475 "yygrammar.c"
         } break;
      case 178: {
         get_lexval();
         id(&i);
#line 296 "ass3.acc"
 appendExpression(*ret, makeExpression(0, 1, 0, i)); (*ret)->operator = '->'; 
# line 1482 "yygrammar.c"
         } break;
      case 179: {
         get_lexval();
#line 297 "ass3.acc"
 (*ret)->operator = 'x++'; 
# line 1488 "yygrammar.c"
         } break;
      case 180: {
         get_lexval();
#line 298 "ass3.acc"
 (*ret)->operator = 'x--'; 
# line 1494 "yygrammar.c"
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
   case 94: {
      id(&i);
#line 303 "ass3.acc"
 *ret = makeExpression(0, 1, 0, i); 
# line 1513 "yygrammar.c"
      } break;
   case 95: {
      constant(&c);
#line 304 "ass3.acc"
 *ret = makeExpression(0, 1, 0, c); 
# line 1519 "yygrammar.c"
      } break;
   case 96: {
      get_lexval();
      expression(&e);
      get_lexval();
#line 305 "ass3.acc"
 *ret = e; 
# line 1527 "yygrammar.c"
      } break;
   }
}

argument_expression_list (ret)
   expression_pt *ret;
{
   expression_pt ae;
   expression_pt ae2;
   switch(yyselect()) {
   case 97: {
#line 309 "ass3.acc"
 *ret = makeExpression(1, 0, '(,)'); 
# line 1541 "yygrammar.c"
      while (1) {
         switch (yyselect()) {
         case 181: {
            assignment_expression(&ae);
#line 309 "ass3.acc"
 appendExpression(*ret, ae); 
# line 1548 "yygrammar.c"
            get_lexval();
            } break;
         default: goto yy8;
         }
      }
      yy8: ;
      assignment_expression(&ae2);
#line 309 "ass3.acc"
 appendExpression(*ret, ae2); 
# line 1558 "yygrammar.c"
      } break;
   }
}

constant (ret)
   constant_pt *ret;
{
   switch(yyselect()) {
   case 98: {
      get_lexval();
#line 313 "ass3.acc"
 *ret = makeIntConst(yylval.i); 
# line 1571 "yygrammar.c"
      } break;
   case 99: {
      get_lexval();
#line 314 "ass3.acc"
 *ret = makeIntConst(yylval.i); 
# line 1577 "yygrammar.c"
      } break;
   case 100: {
      get_lexval();
#line 315 "ass3.acc"
 *ret = makeFloatConst(yylval.d); 
# line 1583 "yygrammar.c"
      } break;
   case 101: {
      get_lexval();
#line 316 "ass3.acc"
 *ret = makeStringConst(yylval.s); 
# line 1589 "yygrammar.c"
      } break;
   }
}

id (ret)
   constant_pt *ret;
{
   switch(yyselect()) {
   case 102: {
      get_lexval();
#line 321 "ass3.acc"
 *ret = makeStringConst(yylval.s); (*ret)->type = IDCONST; 
# line 1602 "yygrammar.c"
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
int c_length = 980;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 103,
/* 6 */ 0,
/* 7 */ 10,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 15,
/* 11 */ 18,
/* 12 */ 10,
/* 13 */ -10,
/* 14 */ 104,
/* 15 */ 0,
/* 16 */ -10,
/* 17 */ 182,
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
/* 28 */ 211,
/* 29 */ 40,
/* 30 */ 47,
/* 31 */ -26,
/* 32 */ 4,
/* 33 */ 37,
/* 34 */ 81,
/* 35 */ -33,
/* 36 */ 105,
/* 37 */ 0,
/* 38 */ -33,
/* 39 */ 183,
/* 40 */ 44,
/* 41 */ 68,
/* 42 */ -40,
/* 43 */ 106,
/* 44 */ 0,
/* 45 */ -40,
/* 46 */ 184,
/* 47 */ 51,
/* 48 */ 50059,
/* 49 */ -47,
/* 50 */ 107,
/* 51 */ 0,
/* 52 */ 486,
/* 53 */ -47,
/* 54 */ 108,
/* 55 */ 0,
/* 56 */ 81,
/* 57 */ 61,
/* 58 */ 50059,
/* 59 */ -55,
/* 60 */ 5,
/* 61 */ 65,
/* 62 */ 165,
/* 63 */ -61,
/* 64 */ 109,
/* 65 */ 0,
/* 66 */ -61,
/* 67 */ 185,
/* 68 */ 0,
/* 69 */ 73,
/* 70 */ 55,
/* 71 */ -68,
/* 72 */ 6,
/* 73 */ 78,
/* 74 */ 55,
/* 75 */ 73,
/* 76 */ -73,
/* 77 */ 110,
/* 78 */ 0,
/* 79 */ -73,
/* 80 */ 186,
/* 81 */ 0,
/* 82 */ 86,
/* 83 */ 98,
/* 84 */ -81,
/* 85 */ 7,
/* 86 */ 90,
/* 87 */ 105,
/* 88 */ -86,
/* 89 */ 111,
/* 90 */ 94,
/* 91 */ 121,
/* 92 */ -86,
/* 93 */ 112,
/* 94 */ 0,
/* 95 */ 157,
/* 96 */ -86,
/* 97 */ 113,
/* 98 */ 102,
/* 99 */ 81,
/* 100 */ -98,
/* 101 */ 114,
/* 102 */ 0,
/* 103 */ -98,
/* 104 */ 187,
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
/* 153 */ 0,
/* 154 */ 50264,
/* 155 */ -121,
/* 156 */ 20,
/* 157 */ 161,
/* 158 */ 50260,
/* 159 */ -157,
/* 160 */ 21,
/* 161 */ 0,
/* 162 */ 50286,
/* 163 */ -157,
/* 164 */ 22,
/* 165 */ 0,
/* 166 */ 170,
/* 167 */ 178,
/* 168 */ -165,
/* 169 */ 23,
/* 170 */ 175,
/* 171 */ 165,
/* 172 */ 50044,
/* 173 */ -170,
/* 174 */ 115,
/* 175 */ 0,
/* 176 */ -170,
/* 177 */ 188,
/* 178 */ 0,
/* 179 */ 211,
/* 180 */ 183,
/* 181 */ -178,
/* 182 */ 24,
/* 183 */ 188,
/* 184 */ 50061,
/* 185 */ 328,
/* 186 */ -183,
/* 187 */ 116,
/* 188 */ 0,
/* 189 */ -183,
/* 190 */ 189,
/* 191 */ 0,
/* 192 */ 196,
/* 193 */ 204,
/* 194 */ -191,
/* 195 */ 25,
/* 196 */ 200,
/* 197 */ 121,
/* 198 */ -196,
/* 199 */ 117,
/* 200 */ 0,
/* 201 */ 157,
/* 202 */ -196,
/* 203 */ 118,
/* 204 */ 208,
/* 205 */ 191,
/* 206 */ -204,
/* 207 */ 119,
/* 208 */ 0,
/* 209 */ -204,
/* 210 */ 190,
/* 211 */ 215,
/* 212 */ 977,
/* 213 */ -211,
/* 214 */ 26,
/* 215 */ 221,
/* 216 */ 50040,
/* 217 */ 211,
/* 218 */ 50041,
/* 219 */ -211,
/* 220 */ 27,
/* 221 */ 0,
/* 222 */ 211,
/* 223 */ 226,
/* 224 */ -211,
/* 225 */ 28,
/* 226 */ 232,
/* 227 */ 50091,
/* 228 */ 244,
/* 229 */ 50093,
/* 230 */ -226,
/* 231 */ 121,
/* 232 */ 238,
/* 233 */ 50040,
/* 234 */ 271,
/* 235 */ 50041,
/* 236 */ -226,
/* 237 */ 122,
/* 238 */ 0,
/* 239 */ 50040,
/* 240 */ 251,
/* 241 */ 50041,
/* 242 */ -226,
/* 243 */ 124,
/* 244 */ 248,
/* 245 */ 655,
/* 246 */ -244,
/* 247 */ 120,
/* 248 */ 0,
/* 249 */ -244,
/* 250 */ 191,
/* 251 */ 255,
/* 252 */ 314,
/* 253 */ -251,
/* 254 */ 123,
/* 255 */ 0,
/* 256 */ -251,
/* 257 */ 192,
/* 258 */ 0,
/* 259 */ 157,
/* 260 */ 263,
/* 261 */ -258,
/* 262 */ 29,
/* 263 */ 268,
/* 264 */ 157,
/* 265 */ 263,
/* 266 */ -263,
/* 267 */ 125,
/* 268 */ 0,
/* 269 */ -263,
/* 270 */ 193,
/* 271 */ 0,
/* 272 */ 284,
/* 273 */ 276,
/* 274 */ -271,
/* 275 */ 30,
/* 276 */ 281,
/* 277 */ 50044,
/* 278 */ 50290,
/* 279 */ -276,
/* 280 */ 126,
/* 281 */ 0,
/* 282 */ -276,
/* 283 */ 194,
/* 284 */ 0,
/* 285 */ 289,
/* 286 */ 298,
/* 287 */ -284,
/* 288 */ 31,
/* 289 */ 295,
/* 290 */ 298,
/* 291 */ 50044,
/* 292 */ 289,
/* 293 */ -289,
/* 294 */ 127,
/* 295 */ 0,
/* 296 */ -289,
/* 297 */ 195,
/* 298 */ 0,
/* 299 */ 81,
/* 300 */ 303,
/* 301 */ -298,
/* 302 */ 32,
/* 303 */ 307,
/* 304 */ 211,
/* 305 */ -303,
/* 306 */ 128,
/* 307 */ 311,
/* 308 */ 375,
/* 309 */ -303,
/* 310 */ 129,
/* 311 */ 0,
/* 312 */ -303,
/* 313 */ 196,
/* 314 */ 0,
/* 315 */ 319,
/* 316 */ 977,
/* 317 */ -314,
/* 318 */ 33,
/* 319 */ 325,
/* 320 */ 977,
/* 321 */ 50044,
/* 322 */ 319,
/* 323 */ -319,
/* 324 */ 130,
/* 325 */ 0,
/* 326 */ -319,
/* 327 */ 197,
/* 328 */ 0,
/* 329 */ 332,
/* 330 */ -328,
/* 331 */ 34,
/* 332 */ 336,
/* 333 */ 665,
/* 334 */ -332,
/* 335 */ 131,
/* 336 */ 0,
/* 337 */ 50123,
/* 338 */ 350,
/* 339 */ 343,
/* 340 */ 50125,
/* 341 */ -332,
/* 342 */ 133,
/* 343 */ 347,
/* 344 */ 50044,
/* 345 */ -343,
/* 346 */ 132,
/* 347 */ 0,
/* 348 */ -343,
/* 349 */ 198,
/* 350 */ 0,
/* 351 */ 355,
/* 352 */ 328,
/* 353 */ -350,
/* 354 */ 35,
/* 355 */ 360,
/* 356 */ 350,
/* 357 */ 50044,
/* 358 */ -355,
/* 359 */ 134,
/* 360 */ 0,
/* 361 */ -355,
/* 362 */ 199,
/* 363 */ 0,
/* 364 */ 191,
/* 365 */ 368,
/* 366 */ -363,
/* 367 */ 36,
/* 368 */ 372,
/* 369 */ 375,
/* 370 */ -368,
/* 371 */ 135,
/* 372 */ 0,
/* 373 */ -368,
/* 374 */ 200,
/* 375 */ 381,
/* 376 */ 50040,
/* 377 */ 375,
/* 378 */ 50041,
/* 379 */ -375,
/* 380 */ 37,
/* 381 */ 0,
/* 382 */ 386,
/* 383 */ 393,
/* 384 */ -375,
/* 385 */ 38,
/* 386 */ 390,
/* 387 */ 375,
/* 388 */ -386,
/* 389 */ 136,
/* 390 */ 0,
/* 391 */ -386,
/* 392 */ 201,
/* 393 */ 399,
/* 394 */ 50091,
/* 395 */ 405,
/* 396 */ 50093,
/* 397 */ -393,
/* 398 */ 138,
/* 399 */ 0,
/* 400 */ 50040,
/* 401 */ 412,
/* 402 */ 50041,
/* 403 */ -393,
/* 404 */ 140,
/* 405 */ 409,
/* 406 */ 655,
/* 407 */ -405,
/* 408 */ 137,
/* 409 */ 0,
/* 410 */ -405,
/* 411 */ 202,
/* 412 */ 416,
/* 413 */ 271,
/* 414 */ -412,
/* 415 */ 139,
/* 416 */ 0,
/* 417 */ -412,
/* 418 */ 203,
/* 419 */ 0,
/* 420 */ 423,
/* 421 */ -419,
/* 422 */ 39,
/* 423 */ 427,
/* 424 */ 455,
/* 425 */ -423,
/* 426 */ 141,
/* 427 */ 431,
/* 428 */ 474,
/* 429 */ -423,
/* 430 */ 142,
/* 431 */ 435,
/* 432 */ 486,
/* 433 */ -423,
/* 434 */ 143,
/* 435 */ 439,
/* 436 */ 520,
/* 437 */ -423,
/* 438 */ 144,
/* 439 */ 443,
/* 440 */ 545,
/* 441 */ -423,
/* 442 */ 145,
/* 443 */ 447,
/* 444 */ 600,
/* 445 */ -423,
/* 446 */ 146,
/* 447 */ 451,
/* 448 */ 633,
/* 449 */ -423,
/* 450 */ 147,
/* 451 */ 0,
/* 452 */ 639,
/* 453 */ -423,
/* 454 */ 148,
/* 455 */ 461,
/* 456 */ 977,
/* 457 */ 50058,
/* 458 */ 419,
/* 459 */ -455,
/* 460 */ 40,
/* 461 */ 468,
/* 462 */ 50258,
/* 463 */ 695,
/* 464 */ 50058,
/* 465 */ 419,
/* 466 */ -455,
/* 467 */ 41,
/* 468 */ 0,
/* 469 */ 50262,
/* 470 */ 50058,
/* 471 */ 419,
/* 472 */ -455,
/* 473 */ 42,
/* 474 */ 0,
/* 475 */ 479,
/* 476 */ 50059,
/* 477 */ -474,
/* 478 */ 43,
/* 479 */ 483,
/* 480 */ 655,
/* 481 */ -479,
/* 482 */ 149,
/* 483 */ 0,
/* 484 */ -479,
/* 485 */ 204,
/* 486 */ 0,
/* 487 */ 50123,
/* 488 */ 493,
/* 489 */ 500,
/* 490 */ 50125,
/* 491 */ -486,
/* 492 */ 44,
/* 493 */ 497,
/* 494 */ 68,
/* 495 */ -493,
/* 496 */ 150,
/* 497 */ 0,
/* 498 */ -493,
/* 499 */ 205,
/* 500 */ 504,
/* 501 */ 507,
/* 502 */ -500,
/* 503 */ 151,
/* 504 */ 0,
/* 505 */ -500,
/* 506 */ 206,
/* 507 */ 0,
/* 508 */ 512,
/* 509 */ 419,
/* 510 */ -507,
/* 511 */ 45,
/* 512 */ 517,
/* 513 */ 419,
/* 514 */ 512,
/* 515 */ -512,
/* 516 */ 152,
/* 517 */ 0,
/* 518 */ -512,
/* 519 */ 207,
/* 520 */ 529,
/* 521 */ 50271,
/* 522 */ 50040,
/* 523 */ 655,
/* 524 */ 50041,
/* 525 */ 419,
/* 526 */ 537,
/* 527 */ -520,
/* 528 */ 46,
/* 529 */ 0,
/* 530 */ 50281,
/* 531 */ 50040,
/* 532 */ 655,
/* 533 */ 50041,
/* 534 */ 419,
/* 535 */ -520,
/* 536 */ 47,
/* 537 */ 542,
/* 538 */ 50265,
/* 539 */ 419,
/* 540 */ -537,
/* 541 */ 153,
/* 542 */ 0,
/* 543 */ -537,
/* 544 */ 208,
/* 545 */ 0,
/* 546 */ 549,
/* 547 */ -545,
/* 548 */ 48,
/* 549 */ 557,
/* 550 */ 50287,
/* 551 */ 50040,
/* 552 */ 655,
/* 553 */ 50041,
/* 554 */ 419,
/* 555 */ -549,
/* 556 */ 154,
/* 557 */ 567,
/* 558 */ 50263,
/* 559 */ 419,
/* 560 */ 50287,
/* 561 */ 50040,
/* 562 */ 655,
/* 563 */ 50041,
/* 564 */ 50059,
/* 565 */ -549,
/* 566 */ 155,
/* 567 */ 0,
/* 568 */ 50269,
/* 569 */ 50040,
/* 570 */ 579,
/* 571 */ 50059,
/* 572 */ 586,
/* 573 */ 50059,
/* 574 */ 593,
/* 575 */ 50041,
/* 576 */ 419,
/* 577 */ -549,
/* 578 */ 159,
/* 579 */ 583,
/* 580 */ 655,
/* 581 */ -579,
/* 582 */ 156,
/* 583 */ 0,
/* 584 */ -579,
/* 585 */ 209,
/* 586 */ 590,
/* 587 */ 655,
/* 588 */ -586,
/* 589 */ 157,
/* 590 */ 0,
/* 591 */ -586,
/* 592 */ 210,
/* 593 */ 597,
/* 594 */ 655,
/* 595 */ -593,
/* 596 */ 158,
/* 597 */ 0,
/* 598 */ -593,
/* 599 */ 211,
/* 600 */ 0,
/* 601 */ 604,
/* 602 */ -600,
/* 603 */ 49,
/* 604 */ 610,
/* 605 */ 50270,
/* 606 */ 977,
/* 607 */ 50059,
/* 608 */ -604,
/* 609 */ 160,
/* 610 */ 615,
/* 611 */ 50261,
/* 612 */ 50059,
/* 613 */ -604,
/* 614 */ 161,
/* 615 */ 620,
/* 616 */ 50257,
/* 617 */ 50059,
/* 618 */ -604,
/* 619 */ 162,
/* 620 */ 0,
/* 621 */ 50275,
/* 622 */ 626,
/* 623 */ 50059,
/* 624 */ -604,
/* 625 */ 164,
/* 626 */ 630,
/* 627 */ 655,
/* 628 */ -626,
/* 629 */ 163,
/* 630 */ 0,
/* 631 */ -626,
/* 632 */ 212,
/* 633 */ 0,
/* 634 */ 50305,
/* 635 */ 947,
/* 636 */ 50059,
/* 637 */ -633,
/* 638 */ 50,
/* 639 */ 0,
/* 640 */ 50306,
/* 641 */ 646,
/* 642 */ 977,
/* 643 */ 50059,
/* 644 */ -639,
/* 645 */ 51,
/* 646 */ 652,
/* 647 */ 977,
/* 648 */ 50044,
/* 649 */ 646,
/* 650 */ -646,
/* 651 */ 165,
/* 652 */ 0,
/* 653 */ -646,
/* 654 */ 213,
/* 655 */ 659,
/* 656 */ 665,
/* 657 */ -655,
/* 658 */ 52,
/* 659 */ 0,
/* 660 */ 655,
/* 661 */ 50044,
/* 662 */ 665,
/* 663 */ -655,
/* 664 */ 53,
/* 665 */ 669,
/* 666 */ 683,
/* 667 */ -665,
/* 668 */ 54,
/* 669 */ 0,
/* 670 */ 820,
/* 671 */ 675,
/* 672 */ 665,
/* 673 */ -665,
/* 674 */ 55,
/* 675 */ 679,
/* 676 */ 50291,
/* 677 */ -675,
/* 678 */ 56,
/* 679 */ 0,
/* 680 */ 50061,
/* 681 */ -675,
/* 682 */ 57,
/* 683 */ 687,
/* 684 */ 699,
/* 685 */ -683,
/* 686 */ 58,
/* 687 */ 0,
/* 688 */ 699,
/* 689 */ 50063,
/* 690 */ 655,
/* 691 */ 50058,
/* 692 */ 683,
/* 693 */ -683,
/* 694 */ 59,
/* 695 */ 0,
/* 696 */ 683,
/* 697 */ -695,
/* 698 */ 60,
/* 699 */ 703,
/* 700 */ 709,
/* 701 */ -699,
/* 702 */ 61,
/* 703 */ 0,
/* 704 */ 699,
/* 705 */ 50297,
/* 706 */ 709,
/* 707 */ -699,
/* 708 */ 62,
/* 709 */ 713,
/* 710 */ 719,
/* 711 */ -709,
/* 712 */ 63,
/* 713 */ 0,
/* 714 */ 709,
/* 715 */ 50298,
/* 716 */ 719,
/* 717 */ -709,
/* 718 */ 64,
/* 719 */ 723,
/* 720 */ 729,
/* 721 */ -719,
/* 722 */ 65,
/* 723 */ 0,
/* 724 */ 719,
/* 725 */ 50124,
/* 726 */ 729,
/* 727 */ -719,
/* 728 */ 66,
/* 729 */ 733,
/* 730 */ 739,
/* 731 */ -729,
/* 732 */ 67,
/* 733 */ 0,
/* 734 */ 729,
/* 735 */ 50094,
/* 736 */ 739,
/* 737 */ -729,
/* 738 */ 68,
/* 739 */ 743,
/* 740 */ 749,
/* 741 */ -739,
/* 742 */ 69,
/* 743 */ 0,
/* 744 */ 739,
/* 745 */ 50038,
/* 746 */ 749,
/* 747 */ -739,
/* 748 */ 70,
/* 749 */ 753,
/* 750 */ 759,
/* 751 */ -749,
/* 752 */ 71,
/* 753 */ 0,
/* 754 */ 749,
/* 755 */ 50292,
/* 756 */ 759,
/* 757 */ -749,
/* 758 */ 72,
/* 759 */ 763,
/* 760 */ 769,
/* 761 */ -759,
/* 762 */ 73,
/* 763 */ 0,
/* 764 */ 759,
/* 765 */ 50300,
/* 766 */ 769,
/* 767 */ -759,
/* 768 */ 74,
/* 769 */ 773,
/* 770 */ 787,
/* 771 */ -769,
/* 772 */ 75,
/* 773 */ 0,
/* 774 */ 769,
/* 775 */ 779,
/* 776 */ 787,
/* 777 */ -769,
/* 778 */ 76,
/* 779 */ 783,
/* 780 */ 50043,
/* 781 */ -779,
/* 782 */ 166,
/* 783 */ 0,
/* 784 */ 50045,
/* 785 */ -779,
/* 786 */ 167,
/* 787 */ 791,
/* 788 */ 809,
/* 789 */ -787,
/* 790 */ 77,
/* 791 */ 0,
/* 792 */ 787,
/* 793 */ 797,
/* 794 */ 809,
/* 795 */ -787,
/* 796 */ 78,
/* 797 */ 801,
/* 798 */ 50042,
/* 799 */ -797,
/* 800 */ 168,
/* 801 */ 805,
/* 802 */ 50047,
/* 803 */ -797,
/* 804 */ 169,
/* 805 */ 0,
/* 806 */ 50037,
/* 807 */ -797,
/* 808 */ 170,
/* 809 */ 813,
/* 810 */ 820,
/* 811 */ -809,
/* 812 */ 79,
/* 813 */ 0,
/* 814 */ 50040,
/* 815 */ 363,
/* 816 */ 50041,
/* 817 */ 809,
/* 818 */ -809,
/* 819 */ 80,
/* 820 */ 824,
/* 821 */ 878,
/* 822 */ -820,
/* 823 */ 81,
/* 824 */ 829,
/* 825 */ 846,
/* 826 */ 820,
/* 827 */ -820,
/* 828 */ 82,
/* 829 */ 834,
/* 830 */ 854,
/* 831 */ 809,
/* 832 */ -820,
/* 833 */ 83,
/* 834 */ 839,
/* 835 */ 50278,
/* 836 */ 820,
/* 837 */ -820,
/* 838 */ 84,
/* 839 */ 0,
/* 840 */ 50278,
/* 841 */ 50040,
/* 842 */ 363,
/* 843 */ 50041,
/* 844 */ -820,
/* 845 */ 85,
/* 846 */ 850,
/* 847 */ 50294,
/* 848 */ -846,
/* 849 */ 171,
/* 850 */ 0,
/* 851 */ 50295,
/* 852 */ -846,
/* 853 */ 172,
/* 854 */ 858,
/* 855 */ 50038,
/* 856 */ -854,
/* 857 */ 86,
/* 858 */ 862,
/* 859 */ 50042,
/* 860 */ -854,
/* 861 */ 87,
/* 862 */ 866,
/* 863 */ 50043,
/* 864 */ -854,
/* 865 */ 88,
/* 866 */ 870,
/* 867 */ 50045,
/* 868 */ -854,
/* 869 */ 89,
/* 870 */ 874,
/* 871 */ 50126,
/* 872 */ -854,
/* 873 */ 90,
/* 874 */ 0,
/* 875 */ 50033,
/* 876 */ -854,
/* 877 */ 91,
/* 878 */ 882,
/* 879 */ 933,
/* 880 */ -878,
/* 881 */ 92,
/* 882 */ 0,
/* 883 */ 878,
/* 884 */ 887,
/* 885 */ -878,
/* 886 */ 93,
/* 887 */ 894,
/* 888 */ 50091,
/* 889 */ 655,
/* 890 */ 918,
/* 891 */ 50093,
/* 892 */ -887,
/* 893 */ 174,
/* 894 */ 900,
/* 895 */ 50040,
/* 896 */ 926,
/* 897 */ 50041,
/* 898 */ -887,
/* 899 */ 176,
/* 900 */ 905,
/* 901 */ 50046,
/* 902 */ 977,
/* 903 */ -887,
/* 904 */ 177,
/* 905 */ 910,
/* 906 */ 50296,
/* 907 */ 977,
/* 908 */ -887,
/* 909 */ 178,
/* 910 */ 914,
/* 911 */ 50294,
/* 912 */ -887,
/* 913 */ 179,
/* 914 */ 0,
/* 915 */ 50295,
/* 916 */ -887,
/* 917 */ 180,
/* 918 */ 923,
/* 919 */ 50058,
/* 920 */ 655,
/* 921 */ -918,
/* 922 */ 173,
/* 923 */ 0,
/* 924 */ -918,
/* 925 */ 214,
/* 926 */ 930,
/* 927 */ 947,
/* 928 */ -926,
/* 929 */ 175,
/* 930 */ 0,
/* 931 */ -926,
/* 932 */ 215,
/* 933 */ 937,
/* 934 */ 977,
/* 935 */ -933,
/* 936 */ 94,
/* 937 */ 941,
/* 938 */ 961,
/* 939 */ -933,
/* 940 */ 95,
/* 941 */ 0,
/* 942 */ 50040,
/* 943 */ 655,
/* 944 */ 50041,
/* 945 */ -933,
/* 946 */ 96,
/* 947 */ 0,
/* 948 */ 952,
/* 949 */ 665,
/* 950 */ -947,
/* 951 */ 97,
/* 952 */ 958,
/* 953 */ 665,
/* 954 */ 50044,
/* 955 */ 952,
/* 956 */ -952,
/* 957 */ 181,
/* 958 */ 0,
/* 959 */ -952,
/* 960 */ 216,
/* 961 */ 965,
/* 962 */ 50304,
/* 963 */ -961,
/* 964 */ 98,
/* 965 */ 969,
/* 966 */ 50302,
/* 967 */ -961,
/* 968 */ 99,
/* 969 */ 973,
/* 970 */ 50303,
/* 971 */ -961,
/* 972 */ 100,
/* 973 */ 0,
/* 974 */ 50289,
/* 975 */ -961,
/* 976 */ 101,
/* 977 */ 0,
/* 978 */ 50299,
/* 979 */ -977,
/* 980 */ 102,
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
/* 153 */ 0,
/* 154 */ 50264,
/* 155 */ -121,
/* 156 */ 9,
/* 157 */ 161,
/* 158 */ 50260,
/* 159 */ -157,
/* 160 */ 1,
/* 161 */ 0,
/* 162 */ 50286,
/* 163 */ -157,
/* 164 */ 2,
/* 165 */ 0,
/* 166 */ 1,
/* 167 */ 1,
/* 168 */ -165,
/* 169 */ 1,
/* 170 */ 175,
/* 171 */ 1,
/* 172 */ 50044,
/* 173 */ -170,
/* 174 */ 1,
/* 175 */ 0,
/* 176 */ -170,
/* 177 */ 2,
/* 178 */ 0,
/* 179 */ 1,
/* 180 */ 1,
/* 181 */ -178,
/* 182 */ 1,
/* 183 */ 188,
/* 184 */ 50061,
/* 185 */ 1,
/* 186 */ -183,
/* 187 */ 1,
/* 188 */ 0,
/* 189 */ -183,
/* 190 */ 2,
/* 191 */ 0,
/* 192 */ 1,
/* 193 */ 1,
/* 194 */ -191,
/* 195 */ 1,
/* 196 */ 200,
/* 197 */ 1,
/* 198 */ -196,
/* 199 */ 1,
/* 200 */ 0,
/* 201 */ 1,
/* 202 */ -196,
/* 203 */ 2,
/* 204 */ 208,
/* 205 */ 1,
/* 206 */ -204,
/* 207 */ 1,
/* 208 */ 0,
/* 209 */ -204,
/* 210 */ 2,
/* 211 */ 215,
/* 212 */ 1,
/* 213 */ -211,
/* 214 */ 1,
/* 215 */ 221,
/* 216 */ 50040,
/* 217 */ 1,
/* 218 */ 50041,
/* 219 */ -211,
/* 220 */ 2,
/* 221 */ 0,
/* 222 */ 1,
/* 223 */ 1,
/* 224 */ -211,
/* 225 */ 3,
/* 226 */ 232,
/* 227 */ 50091,
/* 228 */ 1,
/* 229 */ 50093,
/* 230 */ -226,
/* 231 */ 1,
/* 232 */ 238,
/* 233 */ 50040,
/* 234 */ 1,
/* 235 */ 50041,
/* 236 */ -226,
/* 237 */ 2,
/* 238 */ 0,
/* 239 */ 50040,
/* 240 */ 1,
/* 241 */ 50041,
/* 242 */ -226,
/* 243 */ 3,
/* 244 */ 248,
/* 245 */ 1,
/* 246 */ -244,
/* 247 */ 1,
/* 248 */ 0,
/* 249 */ -244,
/* 250 */ 2,
/* 251 */ 255,
/* 252 */ 1,
/* 253 */ -251,
/* 254 */ 1,
/* 255 */ 0,
/* 256 */ -251,
/* 257 */ 2,
/* 258 */ 0,
/* 259 */ 1,
/* 260 */ 1,
/* 261 */ -258,
/* 262 */ 1,
/* 263 */ 268,
/* 264 */ 1,
/* 265 */ 1,
/* 266 */ -263,
/* 267 */ 1,
/* 268 */ 0,
/* 269 */ -263,
/* 270 */ 2,
/* 271 */ 0,
/* 272 */ 1,
/* 273 */ 1,
/* 274 */ -271,
/* 275 */ 1,
/* 276 */ 281,
/* 277 */ 50044,
/* 278 */ 50290,
/* 279 */ -276,
/* 280 */ 1,
/* 281 */ 0,
/* 282 */ -276,
/* 283 */ 2,
/* 284 */ 0,
/* 285 */ 1,
/* 286 */ 1,
/* 287 */ -284,
/* 288 */ 1,
/* 289 */ 295,
/* 290 */ 1,
/* 291 */ 50044,
/* 292 */ 1,
/* 293 */ -289,
/* 294 */ 1,
/* 295 */ 0,
/* 296 */ -289,
/* 297 */ 2,
/* 298 */ 0,
/* 299 */ 1,
/* 300 */ 1,
/* 301 */ -298,
/* 302 */ 1,
/* 303 */ 307,
/* 304 */ 1,
/* 305 */ -303,
/* 306 */ 1,
/* 307 */ 311,
/* 308 */ 1,
/* 309 */ -303,
/* 310 */ 2,
/* 311 */ 0,
/* 312 */ -303,
/* 313 */ 3,
/* 314 */ 0,
/* 315 */ 1,
/* 316 */ 1,
/* 317 */ -314,
/* 318 */ 1,
/* 319 */ 325,
/* 320 */ 1,
/* 321 */ 50044,
/* 322 */ 1,
/* 323 */ -319,
/* 324 */ 1,
/* 325 */ 0,
/* 326 */ -319,
/* 327 */ 2,
/* 328 */ 0,
/* 329 */ 1,
/* 330 */ -328,
/* 331 */ 1,
/* 332 */ 336,
/* 333 */ 1,
/* 334 */ -332,
/* 335 */ 1,
/* 336 */ 0,
/* 337 */ 50123,
/* 338 */ 1,
/* 339 */ 1,
/* 340 */ 50125,
/* 341 */ -332,
/* 342 */ 2,
/* 343 */ 347,
/* 344 */ 50044,
/* 345 */ -343,
/* 346 */ 1,
/* 347 */ 0,
/* 348 */ -343,
/* 349 */ 2,
/* 350 */ 0,
/* 351 */ 1,
/* 352 */ 1,
/* 353 */ -350,
/* 354 */ 1,
/* 355 */ 360,
/* 356 */ 1,
/* 357 */ 50044,
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
/* 375 */ 381,
/* 376 */ 50040,
/* 377 */ 1,
/* 378 */ 50041,
/* 379 */ -375,
/* 380 */ 1,
/* 381 */ 0,
/* 382 */ 1,
/* 383 */ 1,
/* 384 */ -375,
/* 385 */ 2,
/* 386 */ 390,
/* 387 */ 1,
/* 388 */ -386,
/* 389 */ 1,
/* 390 */ 0,
/* 391 */ -386,
/* 392 */ 2,
/* 393 */ 399,
/* 394 */ 50091,
/* 395 */ 1,
/* 396 */ 50093,
/* 397 */ -393,
/* 398 */ 1,
/* 399 */ 0,
/* 400 */ 50040,
/* 401 */ 1,
/* 402 */ 50041,
/* 403 */ -393,
/* 404 */ 2,
/* 405 */ 409,
/* 406 */ 1,
/* 407 */ -405,
/* 408 */ 1,
/* 409 */ 0,
/* 410 */ -405,
/* 411 */ 2,
/* 412 */ 416,
/* 413 */ 1,
/* 414 */ -412,
/* 415 */ 1,
/* 416 */ 0,
/* 417 */ -412,
/* 418 */ 2,
/* 419 */ 0,
/* 420 */ 1,
/* 421 */ -419,
/* 422 */ 1,
/* 423 */ 427,
/* 424 */ 1,
/* 425 */ -423,
/* 426 */ 1,
/* 427 */ 431,
/* 428 */ 1,
/* 429 */ -423,
/* 430 */ 2,
/* 431 */ 435,
/* 432 */ 1,
/* 433 */ -423,
/* 434 */ 3,
/* 435 */ 439,
/* 436 */ 1,
/* 437 */ -423,
/* 438 */ 4,
/* 439 */ 443,
/* 440 */ 1,
/* 441 */ -423,
/* 442 */ 5,
/* 443 */ 447,
/* 444 */ 1,
/* 445 */ -423,
/* 446 */ 6,
/* 447 */ 451,
/* 448 */ 1,
/* 449 */ -423,
/* 450 */ 7,
/* 451 */ 0,
/* 452 */ 1,
/* 453 */ -423,
/* 454 */ 8,
/* 455 */ 461,
/* 456 */ 1,
/* 457 */ 50058,
/* 458 */ 1,
/* 459 */ -455,
/* 460 */ 1,
/* 461 */ 468,
/* 462 */ 50258,
/* 463 */ 1,
/* 464 */ 50058,
/* 465 */ 1,
/* 466 */ -455,
/* 467 */ 2,
/* 468 */ 0,
/* 469 */ 50262,
/* 470 */ 50058,
/* 471 */ 1,
/* 472 */ -455,
/* 473 */ 3,
/* 474 */ 0,
/* 475 */ 1,
/* 476 */ 50059,
/* 477 */ -474,
/* 478 */ 1,
/* 479 */ 483,
/* 480 */ 1,
/* 481 */ -479,
/* 482 */ 1,
/* 483 */ 0,
/* 484 */ -479,
/* 485 */ 2,
/* 486 */ 0,
/* 487 */ 50123,
/* 488 */ 1,
/* 489 */ 1,
/* 490 */ 50125,
/* 491 */ -486,
/* 492 */ 1,
/* 493 */ 497,
/* 494 */ 1,
/* 495 */ -493,
/* 496 */ 1,
/* 497 */ 0,
/* 498 */ -493,
/* 499 */ 2,
/* 500 */ 504,
/* 501 */ 1,
/* 502 */ -500,
/* 503 */ 1,
/* 504 */ 0,
/* 505 */ -500,
/* 506 */ 2,
/* 507 */ 0,
/* 508 */ 1,
/* 509 */ 1,
/* 510 */ -507,
/* 511 */ 1,
/* 512 */ 517,
/* 513 */ 1,
/* 514 */ 1,
/* 515 */ -512,
/* 516 */ 1,
/* 517 */ 0,
/* 518 */ -512,
/* 519 */ 2,
/* 520 */ 529,
/* 521 */ 50271,
/* 522 */ 50040,
/* 523 */ 1,
/* 524 */ 50041,
/* 525 */ 1,
/* 526 */ 1,
/* 527 */ -520,
/* 528 */ 1,
/* 529 */ 0,
/* 530 */ 50281,
/* 531 */ 50040,
/* 532 */ 1,
/* 533 */ 50041,
/* 534 */ 1,
/* 535 */ -520,
/* 536 */ 2,
/* 537 */ 542,
/* 538 */ 50265,
/* 539 */ 1,
/* 540 */ -537,
/* 541 */ 1,
/* 542 */ 0,
/* 543 */ -537,
/* 544 */ 2,
/* 545 */ 0,
/* 546 */ 1,
/* 547 */ -545,
/* 548 */ 1,
/* 549 */ 557,
/* 550 */ 50287,
/* 551 */ 50040,
/* 552 */ 1,
/* 553 */ 50041,
/* 554 */ 1,
/* 555 */ -549,
/* 556 */ 1,
/* 557 */ 567,
/* 558 */ 50263,
/* 559 */ 1,
/* 560 */ 50287,
/* 561 */ 50040,
/* 562 */ 1,
/* 563 */ 50041,
/* 564 */ 50059,
/* 565 */ -549,
/* 566 */ 2,
/* 567 */ 0,
/* 568 */ 50269,
/* 569 */ 50040,
/* 570 */ 1,
/* 571 */ 50059,
/* 572 */ 1,
/* 573 */ 50059,
/* 574 */ 1,
/* 575 */ 50041,
/* 576 */ 1,
/* 577 */ -549,
/* 578 */ 3,
/* 579 */ 583,
/* 580 */ 1,
/* 581 */ -579,
/* 582 */ 1,
/* 583 */ 0,
/* 584 */ -579,
/* 585 */ 2,
/* 586 */ 590,
/* 587 */ 1,
/* 588 */ -586,
/* 589 */ 1,
/* 590 */ 0,
/* 591 */ -586,
/* 592 */ 2,
/* 593 */ 597,
/* 594 */ 1,
/* 595 */ -593,
/* 596 */ 1,
/* 597 */ 0,
/* 598 */ -593,
/* 599 */ 2,
/* 600 */ 0,
/* 601 */ 1,
/* 602 */ -600,
/* 603 */ 1,
/* 604 */ 610,
/* 605 */ 50270,
/* 606 */ 1,
/* 607 */ 50059,
/* 608 */ -604,
/* 609 */ 1,
/* 610 */ 615,
/* 611 */ 50261,
/* 612 */ 50059,
/* 613 */ -604,
/* 614 */ 2,
/* 615 */ 620,
/* 616 */ 50257,
/* 617 */ 50059,
/* 618 */ -604,
/* 619 */ 3,
/* 620 */ 0,
/* 621 */ 50275,
/* 622 */ 1,
/* 623 */ 50059,
/* 624 */ -604,
/* 625 */ 4,
/* 626 */ 630,
/* 627 */ 1,
/* 628 */ -626,
/* 629 */ 1,
/* 630 */ 0,
/* 631 */ -626,
/* 632 */ 2,
/* 633 */ 0,
/* 634 */ 50305,
/* 635 */ 1,
/* 636 */ 50059,
/* 637 */ -633,
/* 638 */ 1,
/* 639 */ 0,
/* 640 */ 50306,
/* 641 */ 1,
/* 642 */ 1,
/* 643 */ 50059,
/* 644 */ -639,
/* 645 */ 1,
/* 646 */ 652,
/* 647 */ 1,
/* 648 */ 50044,
/* 649 */ 1,
/* 650 */ -646,
/* 651 */ 1,
/* 652 */ 0,
/* 653 */ -646,
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
/* 665 */ 669,
/* 666 */ 1,
/* 667 */ -665,
/* 668 */ 1,
/* 669 */ 0,
/* 670 */ 1,
/* 671 */ 1,
/* 672 */ 1,
/* 673 */ -665,
/* 674 */ 2,
/* 675 */ 679,
/* 676 */ 50291,
/* 677 */ -675,
/* 678 */ 1,
/* 679 */ 0,
/* 680 */ 50061,
/* 681 */ -675,
/* 682 */ 2,
/* 683 */ 687,
/* 684 */ 1,
/* 685 */ -683,
/* 686 */ 1,
/* 687 */ 0,
/* 688 */ 1,
/* 689 */ 50063,
/* 690 */ 1,
/* 691 */ 50058,
/* 692 */ 1,
/* 693 */ -683,
/* 694 */ 2,
/* 695 */ 0,
/* 696 */ 1,
/* 697 */ -695,
/* 698 */ 1,
/* 699 */ 703,
/* 700 */ 1,
/* 701 */ -699,
/* 702 */ 1,
/* 703 */ 0,
/* 704 */ 1,
/* 705 */ 50297,
/* 706 */ 1,
/* 707 */ -699,
/* 708 */ 2,
/* 709 */ 713,
/* 710 */ 1,
/* 711 */ -709,
/* 712 */ 1,
/* 713 */ 0,
/* 714 */ 1,
/* 715 */ 50298,
/* 716 */ 1,
/* 717 */ -709,
/* 718 */ 2,
/* 719 */ 723,
/* 720 */ 1,
/* 721 */ -719,
/* 722 */ 1,
/* 723 */ 0,
/* 724 */ 1,
/* 725 */ 50124,
/* 726 */ 1,
/* 727 */ -719,
/* 728 */ 2,
/* 729 */ 733,
/* 730 */ 1,
/* 731 */ -729,
/* 732 */ 1,
/* 733 */ 0,
/* 734 */ 1,
/* 735 */ 50094,
/* 736 */ 1,
/* 737 */ -729,
/* 738 */ 2,
/* 739 */ 743,
/* 740 */ 1,
/* 741 */ -739,
/* 742 */ 1,
/* 743 */ 0,
/* 744 */ 1,
/* 745 */ 50038,
/* 746 */ 1,
/* 747 */ -739,
/* 748 */ 2,
/* 749 */ 753,
/* 750 */ 1,
/* 751 */ -749,
/* 752 */ 1,
/* 753 */ 0,
/* 754 */ 1,
/* 755 */ 50292,
/* 756 */ 1,
/* 757 */ -749,
/* 758 */ 2,
/* 759 */ 763,
/* 760 */ 1,
/* 761 */ -759,
/* 762 */ 1,
/* 763 */ 0,
/* 764 */ 1,
/* 765 */ 50300,
/* 766 */ 1,
/* 767 */ -759,
/* 768 */ 2,
/* 769 */ 773,
/* 770 */ 1,
/* 771 */ -769,
/* 772 */ 1,
/* 773 */ 0,
/* 774 */ 1,
/* 775 */ 1,
/* 776 */ 1,
/* 777 */ -769,
/* 778 */ 2,
/* 779 */ 783,
/* 780 */ 50043,
/* 781 */ -779,
/* 782 */ 1,
/* 783 */ 0,
/* 784 */ 50045,
/* 785 */ -779,
/* 786 */ 2,
/* 787 */ 791,
/* 788 */ 1,
/* 789 */ -787,
/* 790 */ 1,
/* 791 */ 0,
/* 792 */ 1,
/* 793 */ 1,
/* 794 */ 1,
/* 795 */ -787,
/* 796 */ 2,
/* 797 */ 801,
/* 798 */ 50042,
/* 799 */ -797,
/* 800 */ 1,
/* 801 */ 805,
/* 802 */ 50047,
/* 803 */ -797,
/* 804 */ 2,
/* 805 */ 0,
/* 806 */ 50037,
/* 807 */ -797,
/* 808 */ 3,
/* 809 */ 813,
/* 810 */ 1,
/* 811 */ -809,
/* 812 */ 1,
/* 813 */ 0,
/* 814 */ 50040,
/* 815 */ 1,
/* 816 */ 50041,
/* 817 */ 1,
/* 818 */ -809,
/* 819 */ 2,
/* 820 */ 824,
/* 821 */ 1,
/* 822 */ -820,
/* 823 */ 1,
/* 824 */ 829,
/* 825 */ 1,
/* 826 */ 1,
/* 827 */ -820,
/* 828 */ 2,
/* 829 */ 834,
/* 830 */ 1,
/* 831 */ 1,
/* 832 */ -820,
/* 833 */ 3,
/* 834 */ 839,
/* 835 */ 50278,
/* 836 */ 1,
/* 837 */ -820,
/* 838 */ 4,
/* 839 */ 0,
/* 840 */ 50278,
/* 841 */ 50040,
/* 842 */ 1,
/* 843 */ 50041,
/* 844 */ -820,
/* 845 */ 5,
/* 846 */ 850,
/* 847 */ 50294,
/* 848 */ -846,
/* 849 */ 1,
/* 850 */ 0,
/* 851 */ 50295,
/* 852 */ -846,
/* 853 */ 2,
/* 854 */ 858,
/* 855 */ 50038,
/* 856 */ -854,
/* 857 */ 1,
/* 858 */ 862,
/* 859 */ 50042,
/* 860 */ -854,
/* 861 */ 2,
/* 862 */ 866,
/* 863 */ 50043,
/* 864 */ -854,
/* 865 */ 3,
/* 866 */ 870,
/* 867 */ 50045,
/* 868 */ -854,
/* 869 */ 4,
/* 870 */ 874,
/* 871 */ 50126,
/* 872 */ -854,
/* 873 */ 5,
/* 874 */ 0,
/* 875 */ 50033,
/* 876 */ -854,
/* 877 */ 6,
/* 878 */ 882,
/* 879 */ 1,
/* 880 */ -878,
/* 881 */ 1,
/* 882 */ 0,
/* 883 */ 1,
/* 884 */ 1,
/* 885 */ -878,
/* 886 */ 2,
/* 887 */ 894,
/* 888 */ 50091,
/* 889 */ 1,
/* 890 */ 1,
/* 891 */ 50093,
/* 892 */ -887,
/* 893 */ 1,
/* 894 */ 900,
/* 895 */ 50040,
/* 896 */ 1,
/* 897 */ 50041,
/* 898 */ -887,
/* 899 */ 2,
/* 900 */ 905,
/* 901 */ 50046,
/* 902 */ 1,
/* 903 */ -887,
/* 904 */ 3,
/* 905 */ 910,
/* 906 */ 50296,
/* 907 */ 1,
/* 908 */ -887,
/* 909 */ 4,
/* 910 */ 914,
/* 911 */ 50294,
/* 912 */ -887,
/* 913 */ 5,
/* 914 */ 0,
/* 915 */ 50295,
/* 916 */ -887,
/* 917 */ 6,
/* 918 */ 923,
/* 919 */ 50058,
/* 920 */ 1,
/* 921 */ -918,
/* 922 */ 1,
/* 923 */ 0,
/* 924 */ -918,
/* 925 */ 2,
/* 926 */ 930,
/* 927 */ 1,
/* 928 */ -926,
/* 929 */ 1,
/* 930 */ 0,
/* 931 */ -926,
/* 932 */ 2,
/* 933 */ 937,
/* 934 */ 1,
/* 935 */ -933,
/* 936 */ 1,
/* 937 */ 941,
/* 938 */ 1,
/* 939 */ -933,
/* 940 */ 2,
/* 941 */ 0,
/* 942 */ 50040,
/* 943 */ 1,
/* 944 */ 50041,
/* 945 */ -933,
/* 946 */ 3,
/* 947 */ 0,
/* 948 */ 1,
/* 949 */ 1,
/* 950 */ -947,
/* 951 */ 1,
/* 952 */ 958,
/* 953 */ 1,
/* 954 */ 50044,
/* 955 */ 1,
/* 956 */ -952,
/* 957 */ 1,
/* 958 */ 0,
/* 959 */ -952,
/* 960 */ 2,
/* 961 */ 965,
/* 962 */ 50304,
/* 963 */ -961,
/* 964 */ 1,
/* 965 */ 969,
/* 966 */ 50302,
/* 967 */ -961,
/* 968 */ 2,
/* 969 */ 973,
/* 970 */ 50303,
/* 971 */ -961,
/* 972 */ 3,
/* 973 */ 0,
/* 974 */ 50289,
/* 975 */ -961,
/* 976 */ 4,
/* 977 */ 0,
/* 978 */ 50299,
/* 979 */ -977,
/* 980 */ 1,
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
/* 83 */ 43072,
/* 84 */ 9999,
/* 85 */ 43004,
/* 86 */ 9999,
/* 87 */ 43006,
/* 88 */ 9999,
/* 89 */ 43028,
/* 90 */ 9999,
/* 91 */ 43035,
/* 92 */ 9999,
/* 93 */ 43048,
/* 94 */ 9999,
/* 95 */ 43052,
/* 96 */ 9999,
/* 97 */ 43065,
/* 98 */ 9999,
/* 99 */ 43074,
/* 100 */ 9999,
/* 101 */ 43095,
/* 102 */ 9999,
/* 103 */ 9999,
/* 104 */ 43095,
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
/* 158 */ 9999,
/* 159 */ 9999,
/* 160 */ 68008,
/* 161 */ 9999,
/* 162 */ 9999,
/* 163 */ 9999,
/* 164 */ 69011,
/* 165 */ 9999,
/* 166 */ 73004,
/* 167 */ 73034,
/* 168 */ 9999,
/* 169 */ 73004,
/* 170 */ 9999,
/* 171 */ 73006,
/* 172 */ 9999,
/* 173 */ 9999,
/* 174 */ 73025,
/* 175 */ 9999,
/* 176 */ 9999,
/* 177 */ 73025,
/* 178 */ 9999,
/* 179 */ 77004,
/* 180 */ 77015,
/* 181 */ 9999,
/* 182 */ 77013,
/* 183 */ 9999,
/* 184 */ 9999,
/* 185 */ 77021,
/* 186 */ 9999,
/* 187 */ 77017,
/* 188 */ 9999,
/* 189 */ 9999,
/* 190 */ 77017,
/* 191 */ 9999,
/* 192 */ 81004,
/* 193 */ 81043,
/* 194 */ 9999,
/* 195 */ 81004,
/* 196 */ 9999,
/* 197 */ 81006,
/* 198 */ 9999,
/* 199 */ 81019,
/* 200 */ 9999,
/* 201 */ 81023,
/* 202 */ 9999,
/* 203 */ 81036,
/* 204 */ 9999,
/* 205 */ 81045,
/* 206 */ 9999,
/* 207 */ 81068,
/* 208 */ 9999,
/* 209 */ 9999,
/* 210 */ 81068,
/* 211 */ 9999,
/* 212 */ 85004,
/* 213 */ 9999,
/* 214 */ 85005,
/* 215 */ 9999,
/* 216 */ 9999,
/* 217 */ 86008,
/* 218 */ 9999,
/* 219 */ 9999,
/* 220 */ 86004,
/* 221 */ 9999,
/* 222 */ 87004,
/* 223 */ 88003,
/* 224 */ 9999,
/* 225 */ 87013,
/* 226 */ 9999,
/* 227 */ 9999,
/* 228 */ 88009,
/* 229 */ 9999,
/* 230 */ 9999,
/* 231 */ 88005,
/* 232 */ 9999,
/* 233 */ 9999,
/* 234 */ 89009,
/* 235 */ 9999,
/* 236 */ 9999,
/* 237 */ 89005,
/* 238 */ 9999,
/* 239 */ 9999,
/* 240 */ 90009,
/* 241 */ 9999,
/* 242 */ 9999,
/* 243 */ 90005,
/* 244 */ 9999,
/* 245 */ 88011,
/* 246 */ 9999,
/* 247 */ 88020,
/* 248 */ 9999,
/* 249 */ 9999,
/* 250 */ 88020,
/* 251 */ 9999,
/* 252 */ 90011,
/* 253 */ 9999,
/* 254 */ 90025,
/* 255 */ 9999,
/* 256 */ 9999,
/* 257 */ 90025,
/* 258 */ 9999,
/* 259 */ 95004,
/* 260 */ 95036,
/* 261 */ 9999,
/* 262 */ 95017,
/* 263 */ 9999,
/* 264 */ 95038,
/* 265 */ 95051,
/* 266 */ 9999,
/* 267 */ 95051,
/* 268 */ 9999,
/* 269 */ 9999,
/* 270 */ 95051,
/* 271 */ 9999,
/* 272 */ 99004,
/* 273 */ 99019,
/* 274 */ 9999,
/* 275 */ 99017,
/* 276 */ 9999,
/* 277 */ 9999,
/* 278 */ 9999,
/* 279 */ 9999,
/* 280 */ 99021,
/* 281 */ 9999,
/* 282 */ 9999,
/* 283 */ 99021,
/* 284 */ 9999,
/* 285 */ 103004,
/* 286 */ 103035,
/* 287 */ 9999,
/* 288 */ 103004,
/* 289 */ 9999,
/* 290 */ 103006,
/* 291 */ 9999,
/* 292 */ 103026,
/* 293 */ 9999,
/* 294 */ 103026,
/* 295 */ 9999,
/* 296 */ 9999,
/* 297 */ 103026,
/* 298 */ 9999,
/* 299 */ 107004,
/* 300 */ 107027,
/* 301 */ 9999,
/* 302 */ 107025,
/* 303 */ 9999,
/* 304 */ 107029,
/* 305 */ 9999,
/* 306 */ 107038,
/* 307 */ 9999,
/* 308 */ 107042,
/* 309 */ 9999,
/* 310 */ 107060,
/* 311 */ 9999,
/* 312 */ 9999,
/* 313 */ 107060,
/* 314 */ 9999,
/* 315 */ 111030,
/* 316 */ 111072,
/* 317 */ 9999,
/* 318 */ 111004,
/* 319 */ 9999,
/* 320 */ 111032,
/* 321 */ 9999,
/* 322 */ 111033,
/* 323 */ 9999,
/* 324 */ 111033,
/* 325 */ 9999,
/* 326 */ 9999,
/* 327 */ 111033,
/* 328 */ 9999,
/* 329 */ 116002,
/* 330 */ 9999,
/* 331 */ 115004,
/* 332 */ 9999,
/* 333 */ 116004,
/* 334 */ 9999,
/* 335 */ 116024,
/* 336 */ 9999,
/* 337 */ 9999,
/* 338 */ 117008,
/* 339 */ 117028,
/* 340 */ 9999,
/* 341 */ 9999,
/* 342 */ 117004,
/* 343 */ 9999,
/* 344 */ 9999,
/* 345 */ 9999,
/* 346 */ 117030,
/* 347 */ 9999,
/* 348 */ 9999,
/* 349 */ 117030,
/* 350 */ 9999,
/* 351 */ 121004,
/* 352 */ 121033,
/* 353 */ 9999,
/* 354 */ 121004,
/* 355 */ 9999,
/* 356 */ 121006,
/* 357 */ 9999,
/* 358 */ 9999,
/* 359 */ 121021,
/* 360 */ 9999,
/* 361 */ 9999,
/* 362 */ 121021,
/* 363 */ 9999,
/* 364 */ 125004,
/* 365 */ 125029,
/* 366 */ 9999,
/* 367 */ 125027,
/* 368 */ 9999,
/* 369 */ 125031,
/* 370 */ 9999,
/* 371 */ 125049,
/* 372 */ 9999,
/* 373 */ 9999,
/* 374 */ 125049,
/* 375 */ 9999,
/* 376 */ 9999,
/* 377 */ 129008,
/* 378 */ 9999,
/* 379 */ 9999,
/* 380 */ 129004,
/* 381 */ 9999,
/* 382 */ 130004,
/* 383 */ 130029,
/* 384 */ 9999,
/* 385 */ 130004,
/* 386 */ 9999,
/* 387 */ 130006,
/* 388 */ 9999,
/* 389 */ 130024,
/* 390 */ 9999,
/* 391 */ 9999,
/* 392 */ 130024,
/* 393 */ 9999,
/* 394 */ 9999,
/* 395 */ 130035,
/* 396 */ 9999,
/* 397 */ 9999,
/* 398 */ 130031,
/* 399 */ 9999,
/* 400 */ 9999,
/* 401 */ 131009,
/* 402 */ 9999,
/* 403 */ 9999,
/* 404 */ 131005,
/* 405 */ 9999,
/* 406 */ 130037,
/* 407 */ 9999,
/* 408 */ 130046,
/* 409 */ 9999,
/* 410 */ 9999,
/* 411 */ 130046,
/* 412 */ 9999,
/* 413 */ 131011,
/* 414 */ 9999,
/* 415 */ 131029,
/* 416 */ 9999,
/* 417 */ 9999,
/* 418 */ 131029,
/* 419 */ 9999,
/* 420 */ 136002,
/* 421 */ 9999,
/* 422 */ 135004,
/* 423 */ 9999,
/* 424 */ 136004,
/* 425 */ 9999,
/* 426 */ 136020,
/* 427 */ 9999,
/* 428 */ 137004,
/* 429 */ 9999,
/* 430 */ 137023,
/* 431 */ 9999,
/* 432 */ 138004,
/* 433 */ 9999,
/* 434 */ 138021,
/* 435 */ 9999,
/* 436 */ 139004,
/* 437 */ 9999,
/* 438 */ 139022,
/* 439 */ 9999,
/* 440 */ 140004,
/* 441 */ 9999,
/* 442 */ 140022,
/* 443 */ 9999,
/* 444 */ 141004,
/* 445 */ 9999,
/* 446 */ 141017,
/* 447 */ 9999,
/* 448 */ 142004,
/* 449 */ 9999,
/* 450 */ 142018,
/* 451 */ 9999,
/* 452 */ 143004,
/* 453 */ 9999,
/* 454 */ 143018,
/* 455 */ 9999,
/* 456 */ 148004,
/* 457 */ 9999,
/* 458 */ 148014,
/* 459 */ 9999,
/* 460 */ 148005,
/* 461 */ 9999,
/* 462 */ 9999,
/* 463 */ 149009,
/* 464 */ 9999,
/* 465 */ 149037,
/* 466 */ 9999,
/* 467 */ 149007,
/* 468 */ 9999,
/* 469 */ 9999,
/* 470 */ 9999,
/* 471 */ 150016,
/* 472 */ 9999,
/* 473 */ 150010,
/* 474 */ 9999,
/* 475 */ 154021,
/* 476 */ 9999,
/* 477 */ 9999,
/* 478 */ 154004,
/* 479 */ 9999,
/* 480 */ 154023,
/* 481 */ 9999,
/* 482 */ 154032,
/* 483 */ 9999,
/* 484 */ 9999,
/* 485 */ 154032,
/* 486 */ 9999,
/* 487 */ 9999,
/* 488 */ 158033,
/* 489 */ 158055,
/* 490 */ 9999,
/* 491 */ 9999,
/* 492 */ 158004,
/* 493 */ 9999,
/* 494 */ 158035,
/* 495 */ 9999,
/* 496 */ 158050,
/* 497 */ 9999,
/* 498 */ 9999,
/* 499 */ 158050,
/* 500 */ 9999,
/* 501 */ 158057,
/* 502 */ 9999,
/* 503 */ 158070,
/* 504 */ 9999,
/* 505 */ 9999,
/* 506 */ 158070,
/* 507 */ 9999,
/* 508 */ 167004,
/* 509 */ 167047,
/* 510 */ 9999,
/* 511 */ 167004,
/* 512 */ 9999,
/* 513 */ 167006,
/* 514 */ 167014,
/* 515 */ 9999,
/* 516 */ 167014,
/* 517 */ 9999,
/* 518 */ 9999,
/* 519 */ 167014,
/* 520 */ 9999,
/* 521 */ 9999,
/* 522 */ 9999,
/* 523 */ 171011,
/* 524 */ 9999,
/* 525 */ 171029,
/* 526 */ 172003,
/* 527 */ 9999,
/* 528 */ 171005,
/* 529 */ 9999,
/* 530 */ 9999,
/* 531 */ 9999,
/* 532 */ 173015,
/* 533 */ 9999,
/* 534 */ 173033,
/* 535 */ 9999,
/* 536 */ 173009,
/* 537 */ 9999,
/* 538 */ 9999,
/* 539 */ 172010,
/* 540 */ 9999,
/* 541 */ 172008,
/* 542 */ 9999,
/* 543 */ 9999,
/* 544 */ 172008,
/* 545 */ 9999,
/* 546 */ 178002,
/* 547 */ 9999,
/* 548 */ 177004,
/* 549 */ 9999,
/* 550 */ 9999,
/* 551 */ 9999,
/* 552 */ 178014,
/* 553 */ 9999,
/* 554 */ 178032,
/* 555 */ 9999,
/* 556 */ 178008,
/* 557 */ 9999,
/* 558 */ 9999,
/* 559 */ 179007,
/* 560 */ 9999,
/* 561 */ 9999,
/* 562 */ 179030,
/* 563 */ 9999,
/* 564 */ 9999,
/* 565 */ 9999,
/* 566 */ 179005,
/* 567 */ 9999,
/* 568 */ 9999,
/* 569 */ 9999,
/* 570 */ 180064,
/* 571 */ 9999,
/* 572 */ 180113,
/* 573 */ 9999,
/* 574 */ 180162,
/* 575 */ 9999,
/* 576 */ 180211,
/* 577 */ 9999,
/* 578 */ 180006,
/* 579 */ 9999,
/* 580 */ 180066,
/* 581 */ 9999,
/* 582 */ 180075,
/* 583 */ 9999,
/* 584 */ 9999,
/* 585 */ 180075,
/* 586 */ 9999,
/* 587 */ 180115,
/* 588 */ 9999,
/* 589 */ 180124,
/* 590 */ 9999,
/* 591 */ 9999,
/* 592 */ 180124,
/* 593 */ 9999,
/* 594 */ 180164,
/* 595 */ 9999,
/* 596 */ 180173,
/* 597 */ 9999,
/* 598 */ 9999,
/* 599 */ 180173,
/* 600 */ 9999,
/* 601 */ 185002,
/* 602 */ 9999,
/* 603 */ 184004,
/* 604 */ 9999,
/* 605 */ 9999,
/* 606 */ 185009,
/* 607 */ 9999,
/* 608 */ 9999,
/* 609 */ 185007,
/* 610 */ 9999,
/* 611 */ 9999,
/* 612 */ 9999,
/* 613 */ 9999,
/* 614 */ 186011,
/* 615 */ 9999,
/* 616 */ 9999,
/* 617 */ 9999,
/* 618 */ 9999,
/* 619 */ 187008,
/* 620 */ 9999,
/* 621 */ 9999,
/* 622 */ 188011,
/* 623 */ 9999,
/* 624 */ 9999,
/* 625 */ 188009,
/* 626 */ 9999,
/* 627 */ 188013,
/* 628 */ 9999,
/* 629 */ 188022,
/* 630 */ 9999,
/* 631 */ 9999,
/* 632 */ 188022,
/* 633 */ 9999,
/* 634 */ 9999,
/* 635 */ 192010,
/* 636 */ 9999,
/* 637 */ 9999,
/* 638 */ 192008,
/* 639 */ 9999,
/* 640 */ 9999,
/* 641 */ 196010,
/* 642 */ 196025,
/* 643 */ 9999,
/* 644 */ 9999,
/* 645 */ 196008,
/* 646 */ 9999,
/* 647 */ 196012,
/* 648 */ 9999,
/* 649 */ 196013,
/* 650 */ 9999,
/* 651 */ 196013,
/* 652 */ 9999,
/* 653 */ 9999,
/* 654 */ 196013,
/* 655 */ 9999,
/* 656 */ 200004,
/* 657 */ 9999,
/* 658 */ 200024,
/* 659 */ 9999,
/* 660 */ 201004,
/* 661 */ 9999,
/* 662 */ 201022,
/* 663 */ 9999,
/* 664 */ 201013,
/* 665 */ 9999,
/* 666 */ 205004,
/* 667 */ 9999,
/* 668 */ 205025,
/* 669 */ 9999,
/* 670 */ 206004,
/* 671 */ 206025,
/* 672 */ 206049,
/* 673 */ 9999,
/* 674 */ 206019,
/* 675 */ 9999,
/* 676 */ 9999,
/* 677 */ 9999,
/* 678 */ 210009,
/* 679 */ 9999,
/* 680 */ 9999,
/* 681 */ 9999,
/* 682 */ 211004,
/* 683 */ 9999,
/* 684 */ 215004,
/* 685 */ 9999,
/* 686 */ 215024,
/* 687 */ 9999,
/* 688 */ 216004,
/* 689 */ 9999,
/* 690 */ 216035,
/* 691 */ 9999,
/* 692 */ 216053,
/* 693 */ 9999,
/* 694 */ 216024,
/* 695 */ 9999,
/* 696 */ 220004,
/* 697 */ 9999,
/* 698 */ 220025,
/* 699 */ 9999,
/* 700 */ 224004,
/* 701 */ 9999,
/* 702 */ 224025,
/* 703 */ 9999,
/* 704 */ 225004,
/* 705 */ 9999,
/* 706 */ 225042,
/* 707 */ 9999,
/* 708 */ 225024,
/* 709 */ 9999,
/* 710 */ 229004,
/* 711 */ 9999,
/* 712 */ 229026,
/* 713 */ 9999,
/* 714 */ 230004,
/* 715 */ 9999,
/* 716 */ 230044,
/* 717 */ 9999,
/* 718 */ 230025,
/* 719 */ 9999,
/* 720 */ 234004,
/* 721 */ 9999,
/* 722 */ 234026,
/* 723 */ 9999,
/* 724 */ 235004,
/* 725 */ 9999,
/* 726 */ 235037,
/* 727 */ 9999,
/* 728 */ 235026,
/* 729 */ 9999,
/* 730 */ 239004,
/* 731 */ 9999,
/* 732 */ 239017,
/* 733 */ 9999,
/* 734 */ 240004,
/* 735 */ 9999,
/* 736 */ 240037,
/* 737 */ 9999,
/* 738 */ 240026,
/* 739 */ 9999,
/* 740 */ 244004,
/* 741 */ 9999,
/* 742 */ 244022,
/* 743 */ 9999,
/* 744 */ 245004,
/* 745 */ 9999,
/* 746 */ 245027,
/* 747 */ 9999,
/* 748 */ 245017,
/* 749 */ 9999,
/* 750 */ 249004,
/* 751 */ 9999,
/* 752 */ 249019,
/* 753 */ 9999,
/* 754 */ 250004,
/* 755 */ 9999,
/* 756 */ 250039,
/* 757 */ 9999,
/* 758 */ 250022,
/* 759 */ 9999,
/* 760 */ 254004,
/* 761 */ 9999,
/* 762 */ 254022,
/* 763 */ 9999,
/* 764 */ 255004,
/* 765 */ 9999,
/* 766 */ 255034,
/* 767 */ 9999,
/* 768 */ 255019,
/* 769 */ 9999,
/* 770 */ 259004,
/* 771 */ 9999,
/* 772 */ 259028,
/* 773 */ 9999,
/* 774 */ 260022,
/* 775 */ 260046,
/* 776 */ 260074,
/* 777 */ 9999,
/* 778 */ 260004,
/* 779 */ 9999,
/* 780 */ 9999,
/* 781 */ 9999,
/* 782 */ 260048,
/* 783 */ 9999,
/* 784 */ 9999,
/* 785 */ 9999,
/* 786 */ 260054,
/* 787 */ 9999,
/* 788 */ 264004,
/* 789 */ 9999,
/* 790 */ 264018,
/* 791 */ 9999,
/* 792 */ 265022,
/* 793 */ 265052,
/* 794 */ 265099,
/* 795 */ 9999,
/* 796 */ 265004,
/* 797 */ 9999,
/* 798 */ 9999,
/* 799 */ 9999,
/* 800 */ 265054,
/* 801 */ 9999,
/* 802 */ 9999,
/* 803 */ 9999,
/* 804 */ 265060,
/* 805 */ 9999,
/* 806 */ 9999,
/* 807 */ 9999,
/* 808 */ 265080,
/* 809 */ 9999,
/* 810 */ 269004,
/* 811 */ 9999,
/* 812 */ 269019,
/* 813 */ 9999,
/* 814 */ 9999,
/* 815 */ 270008,
/* 816 */ 9999,
/* 817 */ 270022,
/* 818 */ 9999,
/* 819 */ 270004,
/* 820 */ 9999,
/* 821 */ 274004,
/* 822 */ 9999,
/* 823 */ 274021,
/* 824 */ 9999,
/* 825 */ 275015,
/* 826 */ 275062,
/* 827 */ 9999,
/* 828 */ 275004,
/* 829 */ 9999,
/* 830 */ 276004,
/* 831 */ 276023,
/* 832 */ 9999,
/* 833 */ 276017,
/* 834 */ 9999,
/* 835 */ 9999,
/* 836 */ 277011,
/* 837 */ 9999,
/* 838 */ 277009,
/* 839 */ 9999,
/* 840 */ 9999,
/* 841 */ 9999,
/* 842 */ 278015,
/* 843 */ 9999,
/* 844 */ 9999,
/* 845 */ 278009,
/* 846 */ 9999,
/* 847 */ 9999,
/* 848 */ 9999,
/* 849 */ 275022,
/* 850 */ 9999,
/* 851 */ 9999,
/* 852 */ 9999,
/* 853 */ 275044,
/* 854 */ 9999,
/* 855 */ 9999,
/* 856 */ 9999,
/* 857 */ 282004,
/* 858 */ 9999,
/* 859 */ 9999,
/* 860 */ 9999,
/* 861 */ 283004,
/* 862 */ 9999,
/* 863 */ 9999,
/* 864 */ 9999,
/* 865 */ 284004,
/* 866 */ 9999,
/* 867 */ 9999,
/* 868 */ 9999,
/* 869 */ 285004,
/* 870 */ 9999,
/* 871 */ 9999,
/* 872 */ 9999,
/* 873 */ 286004,
/* 874 */ 9999,
/* 875 */ 9999,
/* 876 */ 9999,
/* 877 */ 287004,
/* 878 */ 9999,
/* 879 */ 291004,
/* 880 */ 9999,
/* 881 */ 291021,
/* 882 */ 9999,
/* 883 */ 292004,
/* 884 */ 293003,
/* 885 */ 9999,
/* 886 */ 292021,
/* 887 */ 9999,
/* 888 */ 9999,
/* 889 */ 293009,
/* 890 */ 293054,
/* 891 */ 9999,
/* 892 */ 9999,
/* 893 */ 293005,
/* 894 */ 9999,
/* 895 */ 9999,
/* 896 */ 294009,
/* 897 */ 9999,
/* 898 */ 9999,
/* 899 */ 294005,
/* 900 */ 9999,
/* 901 */ 9999,
/* 902 */ 295009,
/* 903 */ 9999,
/* 904 */ 295005,
/* 905 */ 9999,
/* 906 */ 9999,
/* 907 */ 296012,
/* 908 */ 9999,
/* 909 */ 296010,
/* 910 */ 9999,
/* 911 */ 9999,
/* 912 */ 9999,
/* 913 */ 297010,
/* 914 */ 9999,
/* 915 */ 9999,
/* 916 */ 9999,
/* 917 */ 298010,
/* 918 */ 9999,
/* 919 */ 9999,
/* 920 */ 293060,
/* 921 */ 9999,
/* 922 */ 293056,
/* 923 */ 9999,
/* 924 */ 9999,
/* 925 */ 293056,
/* 926 */ 9999,
/* 927 */ 294011,
/* 928 */ 9999,
/* 929 */ 294034,
/* 930 */ 9999,
/* 931 */ 9999,
/* 932 */ 294034,
/* 933 */ 9999,
/* 934 */ 303004,
/* 935 */ 9999,
/* 936 */ 303005,
/* 937 */ 9999,
/* 938 */ 304004,
/* 939 */ 9999,
/* 940 */ 304011,
/* 941 */ 9999,
/* 942 */ 9999,
/* 943 */ 305008,
/* 944 */ 9999,
/* 945 */ 9999,
/* 946 */ 305004,
/* 947 */ 9999,
/* 948 */ 309044,
/* 949 */ 309111,
/* 950 */ 9999,
/* 951 */ 309004,
/* 952 */ 9999,
/* 953 */ 309046,
/* 954 */ 9999,
/* 955 */ 309066,
/* 956 */ 9999,
/* 957 */ 309066,
/* 958 */ 9999,
/* 959 */ 9999,
/* 960 */ 309066,
/* 961 */ 9999,
/* 962 */ 9999,
/* 963 */ 9999,
/* 964 */ 313011,
/* 965 */ 9999,
/* 966 */ 9999,
/* 967 */ 9999,
/* 968 */ 314012,
/* 969 */ 9999,
/* 970 */ 9999,
/* 971 */ 9999,
/* 972 */ 315013,
/* 973 */ 9999,
/* 974 */ 9999,
/* 975 */ 9999,
/* 976 */ 316009,
/* 977 */ 9999,
/* 978 */ 9999,
/* 979 */ 9999,
/* 980 */ 321013,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[982];
*/
int TABLE[217][308];
init_dirsets() {
TABLE[103][0] = 1;
TABLE[103][40] = 1;
TABLE[103][299] = 1;
TABLE[103][260] = 1;
TABLE[103][286] = 1;
TABLE[103][285] = 1;
TABLE[103][277] = 1;
TABLE[103][284] = 1;
TABLE[103][276] = 1;
TABLE[103][273] = 1;
TABLE[103][272] = 1;
TABLE[103][259] = 1;
TABLE[103][268] = 1;
TABLE[103][264] = 1;
TABLE[103][256] = 1;
TABLE[103][274] = 1;
TABLE[103][279] = 1;
TABLE[103][267] = 1;
TABLE[1][0] = 1;
TABLE[1][40] = 1;
TABLE[1][299] = 1;
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
TABLE[104][0] = 1;
TABLE[104][40] = 1;
TABLE[104][299] = 1;
TABLE[104][260] = 1;
TABLE[104][286] = 1;
TABLE[104][285] = 1;
TABLE[104][277] = 1;
TABLE[104][284] = 1;
TABLE[104][276] = 1;
TABLE[104][273] = 1;
TABLE[104][272] = 1;
TABLE[104][259] = 1;
TABLE[104][268] = 1;
TABLE[104][264] = 1;
TABLE[104][256] = 1;
TABLE[104][274] = 1;
TABLE[104][279] = 1;
TABLE[104][267] = 1;
TABLE[182][0] = 1;
TABLE[2][0] = 1;
TABLE[2][40] = 1;
TABLE[2][299] = 1;
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
TABLE[4][40] = 1;
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
TABLE[105][260] = 1;
TABLE[105][286] = 1;
TABLE[105][285] = 1;
TABLE[105][277] = 1;
TABLE[105][284] = 1;
TABLE[105][276] = 1;
TABLE[105][273] = 1;
TABLE[105][272] = 1;
TABLE[105][259] = 1;
TABLE[105][268] = 1;
TABLE[105][264] = 1;
TABLE[105][256] = 1;
TABLE[105][274] = 1;
TABLE[105][279] = 1;
TABLE[105][267] = 1;
TABLE[183][40] = 1;
TABLE[183][299] = 1;
TABLE[106][59] = 1;
TABLE[106][123] = 1;
TABLE[106][260] = 1;
TABLE[106][286] = 1;
TABLE[106][285] = 1;
TABLE[106][277] = 1;
TABLE[106][284] = 1;
TABLE[106][276] = 1;
TABLE[106][273] = 1;
TABLE[106][272] = 1;
TABLE[106][259] = 1;
TABLE[106][268] = 1;
TABLE[106][264] = 1;
TABLE[106][256] = 1;
TABLE[106][274] = 1;
TABLE[106][279] = 1;
TABLE[106][267] = 1;
TABLE[184][59] = 1;
TABLE[184][123] = 1;
TABLE[107][59] = 1;
TABLE[108][123] = 1;
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
TABLE[109][59] = 1;
TABLE[109][44] = 1;
TABLE[109][40] = 1;
TABLE[109][299] = 1;
TABLE[185][59] = 1;
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
TABLE[110][267] = 1;
TABLE[110][279] = 1;
TABLE[110][274] = 1;
TABLE[110][256] = 1;
TABLE[110][264] = 1;
TABLE[110][268] = 1;
TABLE[110][259] = 1;
TABLE[110][272] = 1;
TABLE[110][273] = 1;
TABLE[110][276] = 1;
TABLE[110][284] = 1;
TABLE[110][277] = 1;
TABLE[110][285] = 1;
TABLE[110][286] = 1;
TABLE[110][260] = 1;
TABLE[186][267] = 1;
TABLE[186][279] = 1;
TABLE[186][274] = 1;
TABLE[186][256] = 1;
TABLE[186][264] = 1;
TABLE[186][268] = 1;
TABLE[186][259] = 1;
TABLE[186][272] = 1;
TABLE[186][273] = 1;
TABLE[186][276] = 1;
TABLE[186][284] = 1;
TABLE[186][277] = 1;
TABLE[186][285] = 1;
TABLE[186][286] = 1;
TABLE[186][260] = 1;
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
TABLE[111][256] = 1;
TABLE[111][274] = 1;
TABLE[111][279] = 1;
TABLE[111][267] = 1;
TABLE[112][285] = 1;
TABLE[112][277] = 1;
TABLE[112][284] = 1;
TABLE[112][276] = 1;
TABLE[112][273] = 1;
TABLE[112][272] = 1;
TABLE[112][259] = 1;
TABLE[112][268] = 1;
TABLE[112][264] = 1;
TABLE[113][260] = 1;
TABLE[113][286] = 1;
TABLE[114][260] = 1;
TABLE[114][286] = 1;
TABLE[114][285] = 1;
TABLE[114][277] = 1;
TABLE[114][284] = 1;
TABLE[114][276] = 1;
TABLE[114][273] = 1;
TABLE[114][272] = 1;
TABLE[114][259] = 1;
TABLE[114][268] = 1;
TABLE[114][264] = 1;
TABLE[114][256] = 1;
TABLE[114][274] = 1;
TABLE[114][279] = 1;
TABLE[114][267] = 1;
TABLE[187][40] = 1;
TABLE[187][299] = 1;
TABLE[187][44] = 1;
TABLE[187][59] = 1;
TABLE[187][91] = 1;
TABLE[187][41] = 1;
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
TABLE[21][260] = 1;
TABLE[22][286] = 1;
TABLE[23][44] = 1;
TABLE[23][40] = 1;
TABLE[23][299] = 1;
TABLE[115][44] = 1;
TABLE[115][40] = 1;
TABLE[115][299] = 1;
TABLE[188][40] = 1;
TABLE[188][299] = 1;
TABLE[24][40] = 1;
TABLE[24][299] = 1;
TABLE[116][61] = 1;
TABLE[189][59] = 1;
TABLE[189][44] = 1;
TABLE[25][264] = 1;
TABLE[25][268] = 1;
TABLE[25][259] = 1;
TABLE[25][272] = 1;
TABLE[25][273] = 1;
TABLE[25][276] = 1;
TABLE[25][284] = 1;
TABLE[25][277] = 1;
TABLE[25][285] = 1;
TABLE[25][286] = 1;
TABLE[25][260] = 1;
TABLE[117][285] = 1;
TABLE[117][277] = 1;
TABLE[117][284] = 1;
TABLE[117][276] = 1;
TABLE[117][273] = 1;
TABLE[117][272] = 1;
TABLE[117][259] = 1;
TABLE[117][268] = 1;
TABLE[117][264] = 1;
TABLE[118][260] = 1;
TABLE[118][286] = 1;
TABLE[119][260] = 1;
TABLE[119][286] = 1;
TABLE[119][285] = 1;
TABLE[119][277] = 1;
TABLE[119][284] = 1;
TABLE[119][276] = 1;
TABLE[119][273] = 1;
TABLE[119][272] = 1;
TABLE[119][259] = 1;
TABLE[119][268] = 1;
TABLE[119][264] = 1;
TABLE[190][40] = 1;
TABLE[190][91] = 1;
TABLE[190][41] = 1;
TABLE[26][299] = 1;
TABLE[27][40] = 1;
TABLE[28][40] = 1;
TABLE[28][299] = 1;
TABLE[121][91] = 1;
TABLE[122][40] = 1;
TABLE[124][40] = 1;
TABLE[120][278] = 1;
TABLE[120][295] = 1;
TABLE[120][294] = 1;
TABLE[120][33] = 1;
TABLE[120][126] = 1;
TABLE[120][45] = 1;
TABLE[120][43] = 1;
TABLE[120][42] = 1;
TABLE[120][38] = 1;
TABLE[120][40] = 1;
TABLE[120][299] = 1;
TABLE[120][289] = 1;
TABLE[120][303] = 1;
TABLE[120][302] = 1;
TABLE[120][304] = 1;
TABLE[191][93] = 1;
TABLE[123][41] = 1;
TABLE[123][299] = 1;
TABLE[192][41] = 1;
TABLE[29][260] = 1;
TABLE[29][286] = 1;
TABLE[125][260] = 1;
TABLE[125][286] = 1;
TABLE[30][41] = 1;
TABLE[30][44] = 1;
TABLE[30][260] = 1;
TABLE[30][286] = 1;
TABLE[30][285] = 1;
TABLE[30][277] = 1;
TABLE[30][284] = 1;
TABLE[30][276] = 1;
TABLE[30][273] = 1;
TABLE[30][272] = 1;
TABLE[30][259] = 1;
TABLE[30][268] = 1;
TABLE[30][264] = 1;
TABLE[30][256] = 1;
TABLE[30][274] = 1;
TABLE[30][279] = 1;
TABLE[30][267] = 1;
TABLE[126][44] = 1;
TABLE[194][41] = 1;
TABLE[31][260] = 1;
TABLE[31][286] = 1;
TABLE[31][285] = 1;
TABLE[31][277] = 1;
TABLE[31][284] = 1;
TABLE[31][276] = 1;
TABLE[31][273] = 1;
TABLE[31][272] = 1;
TABLE[31][259] = 1;
TABLE[31][268] = 1;
TABLE[31][264] = 1;
TABLE[31][256] = 1;
TABLE[31][274] = 1;
TABLE[31][279] = 1;
TABLE[31][267] = 1;
TABLE[127][267] = 1;
TABLE[127][279] = 1;
TABLE[127][274] = 1;
TABLE[127][256] = 1;
TABLE[127][264] = 1;
TABLE[127][268] = 1;
TABLE[127][259] = 1;
TABLE[127][272] = 1;
TABLE[127][273] = 1;
TABLE[127][276] = 1;
TABLE[127][284] = 1;
TABLE[127][277] = 1;
TABLE[127][285] = 1;
TABLE[127][286] = 1;
TABLE[127][260] = 1;
TABLE[195][267] = 1;
TABLE[195][279] = 1;
TABLE[195][274] = 1;
TABLE[195][256] = 1;
TABLE[195][264] = 1;
TABLE[195][268] = 1;
TABLE[195][259] = 1;
TABLE[195][272] = 1;
TABLE[195][273] = 1;
TABLE[195][276] = 1;
TABLE[195][284] = 1;
TABLE[195][277] = 1;
TABLE[195][285] = 1;
TABLE[195][286] = 1;
TABLE[195][260] = 1;
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
TABLE[32][256] = 1;
TABLE[32][274] = 1;
TABLE[32][279] = 1;
TABLE[32][267] = 1;
TABLE[128][40] = 1;
TABLE[128][299] = 1;
TABLE[129][44] = 1;
TABLE[129][41] = 1;
TABLE[129][40] = 1;
TABLE[129][91] = 1;
TABLE[196][44] = 1;
TABLE[196][41] = 1;
TABLE[33][299] = 1;
TABLE[130][299] = 1;
TABLE[197][299] = 1;
TABLE[34][123] = 1;
TABLE[34][278] = 1;
TABLE[34][295] = 1;
TABLE[34][294] = 1;
TABLE[34][33] = 1;
TABLE[34][126] = 1;
TABLE[34][45] = 1;
TABLE[34][43] = 1;
TABLE[34][42] = 1;
TABLE[34][38] = 1;
TABLE[34][40] = 1;
TABLE[34][299] = 1;
TABLE[34][289] = 1;
TABLE[34][303] = 1;
TABLE[34][302] = 1;
TABLE[34][304] = 1;
TABLE[131][278] = 1;
TABLE[131][38] = 1;
TABLE[131][42] = 1;
TABLE[131][43] = 1;
TABLE[131][45] = 1;
TABLE[131][126] = 1;
TABLE[131][33] = 1;
TABLE[131][294] = 1;
TABLE[131][295] = 1;
TABLE[131][40] = 1;
TABLE[131][304] = 1;
TABLE[131][302] = 1;
TABLE[131][303] = 1;
TABLE[131][289] = 1;
TABLE[131][299] = 1;
TABLE[133][123] = 1;
TABLE[132][44] = 1;
TABLE[198][125] = 1;
TABLE[35][44] = 1;
TABLE[35][123] = 1;
TABLE[35][278] = 1;
TABLE[35][38] = 1;
TABLE[35][42] = 1;
TABLE[35][43] = 1;
TABLE[35][45] = 1;
TABLE[35][126] = 1;
TABLE[35][33] = 1;
TABLE[35][294] = 1;
TABLE[35][295] = 1;
TABLE[35][40] = 1;
TABLE[35][304] = 1;
TABLE[35][302] = 1;
TABLE[35][303] = 1;
TABLE[35][289] = 1;
TABLE[35][299] = 1;
TABLE[134][44] = 1;
TABLE[134][123] = 1;
TABLE[134][278] = 1;
TABLE[134][295] = 1;
TABLE[134][294] = 1;
TABLE[134][33] = 1;
TABLE[134][126] = 1;
TABLE[134][45] = 1;
TABLE[134][43] = 1;
TABLE[134][42] = 1;
TABLE[134][38] = 1;
TABLE[134][40] = 1;
TABLE[134][299] = 1;
TABLE[134][289] = 1;
TABLE[134][303] = 1;
TABLE[134][302] = 1;
TABLE[134][304] = 1;
TABLE[199][123] = 1;
TABLE[199][278] = 1;
TABLE[199][38] = 1;
TABLE[199][42] = 1;
TABLE[199][43] = 1;
TABLE[199][45] = 1;
TABLE[199][126] = 1;
TABLE[199][33] = 1;
TABLE[199][294] = 1;
TABLE[199][295] = 1;
TABLE[199][40] = 1;
TABLE[199][304] = 1;
TABLE[199][302] = 1;
TABLE[199][303] = 1;
TABLE[199][289] = 1;
TABLE[199][299] = 1;
TABLE[36][260] = 1;
TABLE[36][286] = 1;
TABLE[36][285] = 1;
TABLE[36][277] = 1;
TABLE[36][284] = 1;
TABLE[36][276] = 1;
TABLE[36][273] = 1;
TABLE[36][272] = 1;
TABLE[36][259] = 1;
TABLE[36][268] = 1;
TABLE[36][264] = 1;
TABLE[135][41] = 1;
TABLE[135][40] = 1;
TABLE[135][91] = 1;
TABLE[200][41] = 1;
TABLE[37][40] = 1;
TABLE[38][40] = 1;
TABLE[38][91] = 1;
TABLE[136][40] = 1;
TABLE[136][91] = 1;
TABLE[201][91] = 1;
TABLE[201][40] = 1;
TABLE[138][91] = 1;
TABLE[140][40] = 1;
TABLE[137][278] = 1;
TABLE[137][295] = 1;
TABLE[137][294] = 1;
TABLE[137][33] = 1;
TABLE[137][126] = 1;
TABLE[137][45] = 1;
TABLE[137][43] = 1;
TABLE[137][42] = 1;
TABLE[137][38] = 1;
TABLE[137][40] = 1;
TABLE[137][299] = 1;
TABLE[137][289] = 1;
TABLE[137][303] = 1;
TABLE[137][302] = 1;
TABLE[137][304] = 1;
TABLE[202][93] = 1;
TABLE[139][41] = 1;
TABLE[139][44] = 1;
TABLE[139][267] = 1;
TABLE[139][279] = 1;
TABLE[139][274] = 1;
TABLE[139][256] = 1;
TABLE[139][264] = 1;
TABLE[139][268] = 1;
TABLE[139][259] = 1;
TABLE[139][272] = 1;
TABLE[139][273] = 1;
TABLE[139][276] = 1;
TABLE[139][284] = 1;
TABLE[139][277] = 1;
TABLE[139][285] = 1;
TABLE[139][286] = 1;
TABLE[139][260] = 1;
TABLE[203][41] = 1;
TABLE[39][125] = 1;
TABLE[39][265] = 1;
TABLE[39][262] = 1;
TABLE[39][258] = 1;
TABLE[39][59] = 1;
TABLE[39][123] = 1;
TABLE[39][281] = 1;
TABLE[39][271] = 1;
TABLE[39][305] = 1;
TABLE[39][306] = 1;
TABLE[39][299] = 1;
TABLE[39][287] = 1;
TABLE[39][263] = 1;
TABLE[39][269] = 1;
TABLE[39][270] = 1;
TABLE[39][261] = 1;
TABLE[39][257] = 1;
TABLE[39][275] = 1;
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
TABLE[141][258] = 1;
TABLE[141][262] = 1;
TABLE[141][299] = 1;
TABLE[142][125] = 1;
TABLE[142][306] = 1;
TABLE[142][305] = 1;
TABLE[142][271] = 1;
TABLE[142][281] = 1;
TABLE[142][123] = 1;
TABLE[142][258] = 1;
TABLE[142][262] = 1;
TABLE[142][275] = 1;
TABLE[142][257] = 1;
TABLE[142][261] = 1;
TABLE[142][270] = 1;
TABLE[142][269] = 1;
TABLE[142][263] = 1;
TABLE[142][287] = 1;
TABLE[142][265] = 1;
TABLE[142][59] = 1;
TABLE[142][278] = 1;
TABLE[142][295] = 1;
TABLE[142][294] = 1;
TABLE[142][33] = 1;
TABLE[142][126] = 1;
TABLE[142][45] = 1;
TABLE[142][43] = 1;
TABLE[142][42] = 1;
TABLE[142][38] = 1;
TABLE[142][40] = 1;
TABLE[142][299] = 1;
TABLE[142][289] = 1;
TABLE[142][303] = 1;
TABLE[142][302] = 1;
TABLE[142][304] = 1;
TABLE[143][123] = 1;
TABLE[144][271] = 1;
TABLE[144][281] = 1;
TABLE[145][269] = 1;
TABLE[145][263] = 1;
TABLE[145][287] = 1;
TABLE[146][275] = 1;
TABLE[146][257] = 1;
TABLE[146][261] = 1;
TABLE[146][270] = 1;
TABLE[147][305] = 1;
TABLE[148][306] = 1;
TABLE[40][299] = 1;
TABLE[41][258] = 1;
TABLE[42][262] = 1;
TABLE[43][59] = 1;
TABLE[43][278] = 1;
TABLE[43][38] = 1;
TABLE[43][42] = 1;
TABLE[43][43] = 1;
TABLE[43][45] = 1;
TABLE[43][126] = 1;
TABLE[43][33] = 1;
TABLE[43][294] = 1;
TABLE[43][295] = 1;
TABLE[43][40] = 1;
TABLE[43][304] = 1;
TABLE[43][302] = 1;
TABLE[43][303] = 1;
TABLE[43][289] = 1;
TABLE[43][299] = 1;
TABLE[149][278] = 1;
TABLE[149][295] = 1;
TABLE[149][294] = 1;
TABLE[149][33] = 1;
TABLE[149][126] = 1;
TABLE[149][45] = 1;
TABLE[149][43] = 1;
TABLE[149][42] = 1;
TABLE[149][38] = 1;
TABLE[149][40] = 1;
TABLE[149][299] = 1;
TABLE[149][289] = 1;
TABLE[149][303] = 1;
TABLE[149][302] = 1;
TABLE[149][304] = 1;
TABLE[204][59] = 1;
TABLE[44][123] = 1;
TABLE[150][306] = 1;
TABLE[150][305] = 1;
TABLE[150][271] = 1;
TABLE[150][281] = 1;
TABLE[150][123] = 1;
TABLE[150][59] = 1;
TABLE[150][258] = 1;
TABLE[150][262] = 1;
TABLE[150][275] = 1;
TABLE[150][257] = 1;
TABLE[150][261] = 1;
TABLE[150][270] = 1;
TABLE[150][269] = 1;
TABLE[150][263] = 1;
TABLE[150][287] = 1;
TABLE[150][299] = 1;
TABLE[150][278] = 1;
TABLE[150][295] = 1;
TABLE[150][294] = 1;
TABLE[150][33] = 1;
TABLE[150][126] = 1;
TABLE[150][45] = 1;
TABLE[150][43] = 1;
TABLE[150][42] = 1;
TABLE[150][38] = 1;
TABLE[150][40] = 1;
TABLE[150][289] = 1;
TABLE[150][303] = 1;
TABLE[150][302] = 1;
TABLE[150][304] = 1;
TABLE[150][125] = 1;
TABLE[150][260] = 1;
TABLE[150][286] = 1;
TABLE[150][285] = 1;
TABLE[150][277] = 1;
TABLE[150][284] = 1;
TABLE[150][276] = 1;
TABLE[150][273] = 1;
TABLE[150][272] = 1;
TABLE[150][259] = 1;
TABLE[150][268] = 1;
TABLE[150][264] = 1;
TABLE[150][256] = 1;
TABLE[150][274] = 1;
TABLE[150][279] = 1;
TABLE[150][267] = 1;
TABLE[205][306] = 1;
TABLE[205][305] = 1;
TABLE[205][271] = 1;
TABLE[205][281] = 1;
TABLE[205][123] = 1;
TABLE[205][59] = 1;
TABLE[205][258] = 1;
TABLE[205][262] = 1;
TABLE[205][275] = 1;
TABLE[205][257] = 1;
TABLE[205][261] = 1;
TABLE[205][270] = 1;
TABLE[205][269] = 1;
TABLE[205][263] = 1;
TABLE[205][287] = 1;
TABLE[205][299] = 1;
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
TABLE[205][289] = 1;
TABLE[205][303] = 1;
TABLE[205][302] = 1;
TABLE[205][304] = 1;
TABLE[205][125] = 1;
TABLE[151][125] = 1;
TABLE[151][262] = 1;
TABLE[151][258] = 1;
TABLE[151][59] = 1;
TABLE[151][123] = 1;
TABLE[151][281] = 1;
TABLE[151][271] = 1;
TABLE[151][305] = 1;
TABLE[151][306] = 1;
TABLE[151][299] = 1;
TABLE[151][287] = 1;
TABLE[151][263] = 1;
TABLE[151][269] = 1;
TABLE[151][270] = 1;
TABLE[151][261] = 1;
TABLE[151][257] = 1;
TABLE[151][275] = 1;
TABLE[151][278] = 1;
TABLE[151][38] = 1;
TABLE[151][42] = 1;
TABLE[151][43] = 1;
TABLE[151][45] = 1;
TABLE[151][126] = 1;
TABLE[151][33] = 1;
TABLE[151][294] = 1;
TABLE[151][295] = 1;
TABLE[151][40] = 1;
TABLE[151][304] = 1;
TABLE[151][302] = 1;
TABLE[151][303] = 1;
TABLE[151][289] = 1;
TABLE[206][125] = 1;
TABLE[45][125] = 1;
TABLE[45][262] = 1;
TABLE[45][258] = 1;
TABLE[45][59] = 1;
TABLE[45][123] = 1;
TABLE[45][281] = 1;
TABLE[45][271] = 1;
TABLE[45][305] = 1;
TABLE[45][306] = 1;
TABLE[45][299] = 1;
TABLE[45][287] = 1;
TABLE[45][263] = 1;
TABLE[45][269] = 1;
TABLE[45][270] = 1;
TABLE[45][261] = 1;
TABLE[45][257] = 1;
TABLE[45][275] = 1;
TABLE[45][278] = 1;
TABLE[45][38] = 1;
TABLE[45][42] = 1;
TABLE[45][43] = 1;
TABLE[45][45] = 1;
TABLE[45][126] = 1;
TABLE[45][33] = 1;
TABLE[45][294] = 1;
TABLE[45][295] = 1;
TABLE[45][40] = 1;
TABLE[45][304] = 1;
TABLE[45][302] = 1;
TABLE[45][303] = 1;
TABLE[45][289] = 1;
TABLE[152][125] = 1;
TABLE[152][306] = 1;
TABLE[152][305] = 1;
TABLE[152][271] = 1;
TABLE[152][281] = 1;
TABLE[152][123] = 1;
TABLE[152][59] = 1;
TABLE[152][258] = 1;
TABLE[152][262] = 1;
TABLE[152][275] = 1;
TABLE[152][257] = 1;
TABLE[152][261] = 1;
TABLE[152][270] = 1;
TABLE[152][269] = 1;
TABLE[152][263] = 1;
TABLE[152][287] = 1;
TABLE[152][299] = 1;
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
TABLE[152][289] = 1;
TABLE[152][303] = 1;
TABLE[152][302] = 1;
TABLE[152][304] = 1;
TABLE[207][306] = 1;
TABLE[207][305] = 1;
TABLE[207][271] = 1;
TABLE[207][281] = 1;
TABLE[207][123] = 1;
TABLE[207][59] = 1;
TABLE[207][258] = 1;
TABLE[207][262] = 1;
TABLE[207][275] = 1;
TABLE[207][257] = 1;
TABLE[207][261] = 1;
TABLE[207][270] = 1;
TABLE[207][269] = 1;
TABLE[207][263] = 1;
TABLE[207][287] = 1;
TABLE[207][299] = 1;
TABLE[207][278] = 1;
TABLE[207][295] = 1;
TABLE[207][294] = 1;
TABLE[207][33] = 1;
TABLE[207][126] = 1;
TABLE[207][45] = 1;
TABLE[207][43] = 1;
TABLE[207][42] = 1;
TABLE[207][38] = 1;
TABLE[207][40] = 1;
TABLE[207][289] = 1;
TABLE[207][303] = 1;
TABLE[207][302] = 1;
TABLE[207][304] = 1;
TABLE[207][125] = 1;
TABLE[46][271] = 1;
TABLE[47][281] = 1;
TABLE[153][265] = 1;
TABLE[208][125] = 1;
TABLE[208][306] = 1;
TABLE[208][305] = 1;
TABLE[208][271] = 1;
TABLE[208][281] = 1;
TABLE[208][123] = 1;
TABLE[208][59] = 1;
TABLE[208][258] = 1;
TABLE[208][262] = 1;
TABLE[208][275] = 1;
TABLE[208][257] = 1;
TABLE[208][261] = 1;
TABLE[208][270] = 1;
TABLE[208][269] = 1;
TABLE[208][263] = 1;
TABLE[208][287] = 1;
TABLE[208][299] = 1;
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
TABLE[208][289] = 1;
TABLE[208][303] = 1;
TABLE[208][302] = 1;
TABLE[208][304] = 1;
TABLE[208][265] = 1;
TABLE[48][287] = 1;
TABLE[48][263] = 1;
TABLE[48][269] = 1;
TABLE[154][287] = 1;
TABLE[155][263] = 1;
TABLE[159][269] = 1;
TABLE[156][278] = 1;
TABLE[156][295] = 1;
TABLE[156][294] = 1;
TABLE[156][33] = 1;
TABLE[156][126] = 1;
TABLE[156][45] = 1;
TABLE[156][43] = 1;
TABLE[156][42] = 1;
TABLE[156][38] = 1;
TABLE[156][40] = 1;
TABLE[156][299] = 1;
TABLE[156][289] = 1;
TABLE[156][303] = 1;
TABLE[156][302] = 1;
TABLE[156][304] = 1;
TABLE[209][59] = 1;
TABLE[157][278] = 1;
TABLE[157][295] = 1;
TABLE[157][294] = 1;
TABLE[157][33] = 1;
TABLE[157][126] = 1;
TABLE[157][45] = 1;
TABLE[157][43] = 1;
TABLE[157][42] = 1;
TABLE[157][38] = 1;
TABLE[157][40] = 1;
TABLE[157][299] = 1;
TABLE[157][289] = 1;
TABLE[157][303] = 1;
TABLE[157][302] = 1;
TABLE[157][304] = 1;
TABLE[210][59] = 1;
TABLE[158][278] = 1;
TABLE[158][295] = 1;
TABLE[158][294] = 1;
TABLE[158][33] = 1;
TABLE[158][126] = 1;
TABLE[158][45] = 1;
TABLE[158][43] = 1;
TABLE[158][42] = 1;
TABLE[158][38] = 1;
TABLE[158][40] = 1;
TABLE[158][299] = 1;
TABLE[158][289] = 1;
TABLE[158][303] = 1;
TABLE[158][302] = 1;
TABLE[158][304] = 1;
TABLE[211][41] = 1;
TABLE[49][270] = 1;
TABLE[49][261] = 1;
TABLE[49][257] = 1;
TABLE[49][275] = 1;
TABLE[160][270] = 1;
TABLE[161][261] = 1;
TABLE[162][257] = 1;
TABLE[164][275] = 1;
TABLE[163][278] = 1;
TABLE[163][295] = 1;
TABLE[163][294] = 1;
TABLE[163][33] = 1;
TABLE[163][126] = 1;
TABLE[163][45] = 1;
TABLE[163][43] = 1;
TABLE[163][42] = 1;
TABLE[163][38] = 1;
TABLE[163][40] = 1;
TABLE[163][299] = 1;
TABLE[163][289] = 1;
TABLE[163][303] = 1;
TABLE[163][302] = 1;
TABLE[163][304] = 1;
TABLE[212][59] = 1;
TABLE[50][305] = 1;
TABLE[51][306] = 1;
TABLE[165][299] = 1;
TABLE[213][299] = 1;
TABLE[52][278] = 1;
TABLE[52][38] = 1;
TABLE[52][42] = 1;
TABLE[52][43] = 1;
TABLE[52][45] = 1;
TABLE[52][126] = 1;
TABLE[52][33] = 1;
TABLE[52][294] = 1;
TABLE[52][295] = 1;
TABLE[52][40] = 1;
TABLE[52][304] = 1;
TABLE[52][302] = 1;
TABLE[52][303] = 1;
TABLE[52][289] = 1;
TABLE[52][299] = 1;
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
TABLE[54][40] = 1;
TABLE[54][278] = 1;
TABLE[54][38] = 1;
TABLE[54][42] = 1;
TABLE[54][43] = 1;
TABLE[54][45] = 1;
TABLE[54][126] = 1;
TABLE[54][33] = 1;
TABLE[54][294] = 1;
TABLE[54][295] = 1;
TABLE[54][304] = 1;
TABLE[54][302] = 1;
TABLE[54][303] = 1;
TABLE[54][289] = 1;
TABLE[54][299] = 1;
TABLE[55][278] = 1;
TABLE[55][295] = 1;
TABLE[55][294] = 1;
TABLE[55][33] = 1;
TABLE[55][126] = 1;
TABLE[55][45] = 1;
TABLE[55][43] = 1;
TABLE[55][42] = 1;
TABLE[55][38] = 1;
TABLE[55][40] = 1;
TABLE[55][299] = 1;
TABLE[55][289] = 1;
TABLE[55][303] = 1;
TABLE[55][302] = 1;
TABLE[55][304] = 1;
TABLE[56][291] = 1;
TABLE[57][61] = 1;
TABLE[58][40] = 1;
TABLE[58][278] = 1;
TABLE[58][295] = 1;
TABLE[58][294] = 1;
TABLE[58][33] = 1;
TABLE[58][126] = 1;
TABLE[58][45] = 1;
TABLE[58][43] = 1;
TABLE[58][42] = 1;
TABLE[58][38] = 1;
TABLE[58][299] = 1;
TABLE[58][289] = 1;
TABLE[58][303] = 1;
TABLE[58][302] = 1;
TABLE[58][304] = 1;
TABLE[59][40] = 1;
TABLE[59][278] = 1;
TABLE[59][295] = 1;
TABLE[59][294] = 1;
TABLE[59][33] = 1;
TABLE[59][126] = 1;
TABLE[59][45] = 1;
TABLE[59][43] = 1;
TABLE[59][42] = 1;
TABLE[59][38] = 1;
TABLE[59][299] = 1;
TABLE[59][289] = 1;
TABLE[59][303] = 1;
TABLE[59][302] = 1;
TABLE[59][304] = 1;
TABLE[60][40] = 1;
TABLE[60][278] = 1;
TABLE[60][38] = 1;
TABLE[60][42] = 1;
TABLE[60][43] = 1;
TABLE[60][45] = 1;
TABLE[60][126] = 1;
TABLE[60][33] = 1;
TABLE[60][294] = 1;
TABLE[60][295] = 1;
TABLE[60][304] = 1;
TABLE[60][302] = 1;
TABLE[60][303] = 1;
TABLE[60][289] = 1;
TABLE[60][299] = 1;
TABLE[61][40] = 1;
TABLE[61][278] = 1;
TABLE[61][38] = 1;
TABLE[61][42] = 1;
TABLE[61][43] = 1;
TABLE[61][45] = 1;
TABLE[61][126] = 1;
TABLE[61][33] = 1;
TABLE[61][294] = 1;
TABLE[61][295] = 1;
TABLE[61][304] = 1;
TABLE[61][302] = 1;
TABLE[61][303] = 1;
TABLE[61][289] = 1;
TABLE[61][299] = 1;
TABLE[62][40] = 1;
TABLE[62][278] = 1;
TABLE[62][295] = 1;
TABLE[62][294] = 1;
TABLE[62][33] = 1;
TABLE[62][126] = 1;
TABLE[62][45] = 1;
TABLE[62][43] = 1;
TABLE[62][42] = 1;
TABLE[62][38] = 1;
TABLE[62][299] = 1;
TABLE[62][289] = 1;
TABLE[62][303] = 1;
TABLE[62][302] = 1;
TABLE[62][304] = 1;
TABLE[63][40] = 1;
TABLE[63][278] = 1;
TABLE[63][295] = 1;
TABLE[63][294] = 1;
TABLE[63][33] = 1;
TABLE[63][126] = 1;
TABLE[63][45] = 1;
TABLE[63][43] = 1;
TABLE[63][42] = 1;
TABLE[63][38] = 1;
TABLE[63][299] = 1;
TABLE[63][289] = 1;
TABLE[63][303] = 1;
TABLE[63][302] = 1;
TABLE[63][304] = 1;
TABLE[64][40] = 1;
TABLE[64][278] = 1;
TABLE[64][38] = 1;
TABLE[64][42] = 1;
TABLE[64][43] = 1;
TABLE[64][45] = 1;
TABLE[64][126] = 1;
TABLE[64][33] = 1;
TABLE[64][294] = 1;
TABLE[64][295] = 1;
TABLE[64][304] = 1;
TABLE[64][302] = 1;
TABLE[64][303] = 1;
TABLE[64][289] = 1;
TABLE[64][299] = 1;
TABLE[65][40] = 1;
TABLE[65][278] = 1;
TABLE[65][38] = 1;
TABLE[65][42] = 1;
TABLE[65][43] = 1;
TABLE[65][45] = 1;
TABLE[65][126] = 1;
TABLE[65][33] = 1;
TABLE[65][294] = 1;
TABLE[65][295] = 1;
TABLE[65][304] = 1;
TABLE[65][302] = 1;
TABLE[65][303] = 1;
TABLE[65][289] = 1;
TABLE[65][299] = 1;
TABLE[66][40] = 1;
TABLE[66][278] = 1;
TABLE[66][295] = 1;
TABLE[66][294] = 1;
TABLE[66][33] = 1;
TABLE[66][126] = 1;
TABLE[66][45] = 1;
TABLE[66][43] = 1;
TABLE[66][42] = 1;
TABLE[66][38] = 1;
TABLE[66][299] = 1;
TABLE[66][289] = 1;
TABLE[66][303] = 1;
TABLE[66][302] = 1;
TABLE[66][304] = 1;
TABLE[67][40] = 1;
TABLE[67][278] = 1;
TABLE[67][295] = 1;
TABLE[67][294] = 1;
TABLE[67][33] = 1;
TABLE[67][126] = 1;
TABLE[67][45] = 1;
TABLE[67][43] = 1;
TABLE[67][42] = 1;
TABLE[67][38] = 1;
TABLE[67][299] = 1;
TABLE[67][289] = 1;
TABLE[67][303] = 1;
TABLE[67][302] = 1;
TABLE[67][304] = 1;
TABLE[68][40] = 1;
TABLE[68][278] = 1;
TABLE[68][38] = 1;
TABLE[68][42] = 1;
TABLE[68][43] = 1;
TABLE[68][45] = 1;
TABLE[68][126] = 1;
TABLE[68][33] = 1;
TABLE[68][294] = 1;
TABLE[68][295] = 1;
TABLE[68][304] = 1;
TABLE[68][302] = 1;
TABLE[68][303] = 1;
TABLE[68][289] = 1;
TABLE[68][299] = 1;
TABLE[69][40] = 1;
TABLE[69][278] = 1;
TABLE[69][38] = 1;
TABLE[69][42] = 1;
TABLE[69][43] = 1;
TABLE[69][45] = 1;
TABLE[69][126] = 1;
TABLE[69][33] = 1;
TABLE[69][294] = 1;
TABLE[69][295] = 1;
TABLE[69][304] = 1;
TABLE[69][302] = 1;
TABLE[69][303] = 1;
TABLE[69][289] = 1;
TABLE[69][299] = 1;
TABLE[70][40] = 1;
TABLE[70][278] = 1;
TABLE[70][295] = 1;
TABLE[70][294] = 1;
TABLE[70][33] = 1;
TABLE[70][126] = 1;
TABLE[70][45] = 1;
TABLE[70][43] = 1;
TABLE[70][42] = 1;
TABLE[70][38] = 1;
TABLE[70][299] = 1;
TABLE[70][289] = 1;
TABLE[70][303] = 1;
TABLE[70][302] = 1;
TABLE[70][304] = 1;
TABLE[71][40] = 1;
TABLE[71][278] = 1;
TABLE[71][295] = 1;
TABLE[71][294] = 1;
TABLE[71][33] = 1;
TABLE[71][126] = 1;
TABLE[71][45] = 1;
TABLE[71][43] = 1;
TABLE[71][42] = 1;
TABLE[71][38] = 1;
TABLE[71][299] = 1;
TABLE[71][289] = 1;
TABLE[71][303] = 1;
TABLE[71][302] = 1;
TABLE[71][304] = 1;
TABLE[72][40] = 1;
TABLE[72][278] = 1;
TABLE[72][38] = 1;
TABLE[72][42] = 1;
TABLE[72][43] = 1;
TABLE[72][45] = 1;
TABLE[72][126] = 1;
TABLE[72][33] = 1;
TABLE[72][294] = 1;
TABLE[72][295] = 1;
TABLE[72][304] = 1;
TABLE[72][302] = 1;
TABLE[72][303] = 1;
TABLE[72][289] = 1;
TABLE[72][299] = 1;
TABLE[73][40] = 1;
TABLE[73][278] = 1;
TABLE[73][38] = 1;
TABLE[73][42] = 1;
TABLE[73][43] = 1;
TABLE[73][45] = 1;
TABLE[73][126] = 1;
TABLE[73][33] = 1;
TABLE[73][294] = 1;
TABLE[73][295] = 1;
TABLE[73][304] = 1;
TABLE[73][302] = 1;
TABLE[73][303] = 1;
TABLE[73][289] = 1;
TABLE[73][299] = 1;
TABLE[74][40] = 1;
TABLE[74][278] = 1;
TABLE[74][295] = 1;
TABLE[74][294] = 1;
TABLE[74][33] = 1;
TABLE[74][126] = 1;
TABLE[74][45] = 1;
TABLE[74][43] = 1;
TABLE[74][42] = 1;
TABLE[74][38] = 1;
TABLE[74][299] = 1;
TABLE[74][289] = 1;
TABLE[74][303] = 1;
TABLE[74][302] = 1;
TABLE[74][304] = 1;
TABLE[75][40] = 1;
TABLE[75][278] = 1;
TABLE[75][295] = 1;
TABLE[75][294] = 1;
TABLE[75][33] = 1;
TABLE[75][126] = 1;
TABLE[75][45] = 1;
TABLE[75][43] = 1;
TABLE[75][42] = 1;
TABLE[75][38] = 1;
TABLE[75][299] = 1;
TABLE[75][289] = 1;
TABLE[75][303] = 1;
TABLE[75][302] = 1;
TABLE[75][304] = 1;
TABLE[76][40] = 1;
TABLE[76][278] = 1;
TABLE[76][38] = 1;
TABLE[76][42] = 1;
TABLE[76][43] = 1;
TABLE[76][45] = 1;
TABLE[76][126] = 1;
TABLE[76][33] = 1;
TABLE[76][294] = 1;
TABLE[76][295] = 1;
TABLE[76][304] = 1;
TABLE[76][302] = 1;
TABLE[76][303] = 1;
TABLE[76][289] = 1;
TABLE[76][299] = 1;
TABLE[166][43] = 1;
TABLE[167][45] = 1;
TABLE[77][40] = 1;
TABLE[77][278] = 1;
TABLE[77][38] = 1;
TABLE[77][42] = 1;
TABLE[77][43] = 1;
TABLE[77][45] = 1;
TABLE[77][126] = 1;
TABLE[77][33] = 1;
TABLE[77][294] = 1;
TABLE[77][295] = 1;
TABLE[77][304] = 1;
TABLE[77][302] = 1;
TABLE[77][303] = 1;
TABLE[77][289] = 1;
TABLE[77][299] = 1;
TABLE[78][40] = 1;
TABLE[78][278] = 1;
TABLE[78][295] = 1;
TABLE[78][294] = 1;
TABLE[78][33] = 1;
TABLE[78][126] = 1;
TABLE[78][45] = 1;
TABLE[78][43] = 1;
TABLE[78][42] = 1;
TABLE[78][38] = 1;
TABLE[78][299] = 1;
TABLE[78][289] = 1;
TABLE[78][303] = 1;
TABLE[78][302] = 1;
TABLE[78][304] = 1;
TABLE[168][42] = 1;
TABLE[169][47] = 1;
TABLE[170][37] = 1;
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
TABLE[80][40] = 1;
TABLE[81][40] = 1;
TABLE[81][304] = 1;
TABLE[81][302] = 1;
TABLE[81][303] = 1;
TABLE[81][289] = 1;
TABLE[81][299] = 1;
TABLE[82][294] = 1;
TABLE[82][295] = 1;
TABLE[83][38] = 1;
TABLE[83][42] = 1;
TABLE[83][43] = 1;
TABLE[83][45] = 1;
TABLE[83][126] = 1;
TABLE[83][33] = 1;
TABLE[84][278] = 1;
TABLE[85][278] = 1;
TABLE[171][294] = 1;
TABLE[172][295] = 1;
TABLE[86][38] = 1;
TABLE[87][42] = 1;
TABLE[88][43] = 1;
TABLE[89][45] = 1;
TABLE[90][126] = 1;
TABLE[91][33] = 1;
TABLE[92][40] = 1;
TABLE[92][299] = 1;
TABLE[92][289] = 1;
TABLE[92][303] = 1;
TABLE[92][302] = 1;
TABLE[92][304] = 1;
TABLE[93][40] = 1;
TABLE[93][304] = 1;
TABLE[93][302] = 1;
TABLE[93][303] = 1;
TABLE[93][289] = 1;
TABLE[93][299] = 1;
TABLE[174][91] = 1;
TABLE[176][40] = 1;
TABLE[177][46] = 1;
TABLE[178][296] = 1;
TABLE[179][294] = 1;
TABLE[180][295] = 1;
TABLE[173][58] = 1;
TABLE[214][93] = 1;
TABLE[175][41] = 1;
TABLE[175][278] = 1;
TABLE[175][295] = 1;
TABLE[175][294] = 1;
TABLE[175][33] = 1;
TABLE[175][126] = 1;
TABLE[175][45] = 1;
TABLE[175][43] = 1;
TABLE[175][42] = 1;
TABLE[175][38] = 1;
TABLE[175][40] = 1;
TABLE[175][299] = 1;
TABLE[175][289] = 1;
TABLE[175][303] = 1;
TABLE[175][302] = 1;
TABLE[175][304] = 1;
TABLE[215][41] = 1;
TABLE[94][299] = 1;
TABLE[95][304] = 1;
TABLE[95][302] = 1;
TABLE[95][303] = 1;
TABLE[95][289] = 1;
TABLE[96][40] = 1;
TABLE[97][278] = 1;
TABLE[97][295] = 1;
TABLE[97][294] = 1;
TABLE[97][33] = 1;
TABLE[97][126] = 1;
TABLE[97][45] = 1;
TABLE[97][43] = 1;
TABLE[97][42] = 1;
TABLE[97][38] = 1;
TABLE[97][40] = 1;
TABLE[97][299] = 1;
TABLE[97][289] = 1;
TABLE[97][303] = 1;
TABLE[97][302] = 1;
TABLE[97][304] = 1;
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
TABLE[216][278] = 1;
TABLE[216][38] = 1;
TABLE[216][42] = 1;
TABLE[216][43] = 1;
TABLE[216][45] = 1;
TABLE[216][126] = 1;
TABLE[216][33] = 1;
TABLE[216][294] = 1;
TABLE[216][295] = 1;
TABLE[216][40] = 1;
TABLE[216][304] = 1;
TABLE[216][302] = 1;
TABLE[216][303] = 1;
TABLE[216][289] = 1;
TABLE[216][299] = 1;
TABLE[98][304] = 1;
TABLE[99][302] = 1;
TABLE[100][303] = 1;
TABLE[101][289] = 1;
TABLE[102][299] = 1;
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
      case 157: return 0; break;
      case 165: return 1; break;
      case 170: return 1; break;
      case 178: return 0; break;
      case 183: return 1; break;
      case 191: return 0; break;
      case 196: return 0; break;
      case 204: return 1; break;
      case 211: return 0; break;
      case 226: return 0; break;
      case 244: return 1; break;
      case 251: return 1; break;
      case 258: return 0; break;
      case 263: return 1; break;
      case 271: return 1; break;
      case 276: return 1; break;
      case 284: return 1; break;
      case 289: return 1; break;
      case 298: return 0; break;
      case 303: return 1; break;
      case 314: return 1; break;
      case 319: return 1; break;
      case 328: return 0; break;
      case 332: return 0; break;
      case 343: return 1; break;
      case 350: return 1; break;
      case 355: return 1; break;
      case 363: return 0; break;
      case 368: return 1; break;
      case 375: return 1; break;
      case 386: return 1; break;
      case 393: return 0; break;
      case 405: return 1; break;
      case 412: return 1; break;
      case 419: return 1; break;
      case 423: return 1; break;
      case 455: return 0; break;
      case 474: return 1; break;
      case 479: return 1; break;
      case 486: return 0; break;
      case 493: return 1; break;
      case 500: return 1; break;
      case 507: return 1; break;
      case 512: return 1; break;
      case 520: return 0; break;
      case 537: return 1; break;
      case 545: return 0; break;
      case 549: return 0; break;
      case 579: return 1; break;
      case 586: return 1; break;
      case 593: return 1; break;
      case 600: return 0; break;
      case 604: return 0; break;
      case 626: return 1; break;
      case 633: return 0; break;
      case 639: return 0; break;
      case 646: return 1; break;
      case 655: return 0; break;
      case 665: return 0; break;
      case 675: return 0; break;
      case 683: return 0; break;
      case 695: return 0; break;
      case 699: return 0; break;
      case 709: return 0; break;
      case 719: return 0; break;
      case 729: return 0; break;
      case 739: return 0; break;
      case 749: return 0; break;
      case 759: return 0; break;
      case 769: return 0; break;
      case 779: return 0; break;
      case 787: return 0; break;
      case 797: return 0; break;
      case 809: return 0; break;
      case 820: return 0; break;
      case 846: return 0; break;
      case 854: return 0; break;
      case 878: return 0; break;
      case 887: return 0; break;
      case 918: return 1; break;
      case 926: return 1; break;
      case 933: return 0; break;
      case 947: return 1; break;
      case 952: return 1; break;
      case 961: return 0; break;
      case 977: return 0; break;
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
         case 157: return "type_qualifier"; break;
         case 165: return "init_declarator_list"; break;
         case 170: return "Subphrase"; break;
         case 178: return "init_declarator"; break;
         case 183: return "Subphrase"; break;
         case 191: return "specifier_qualifier_list"; break;
         case 196: return "Subphrase"; break;
         case 204: return "Subphrase"; break;
         case 211: return "declarator"; break;
         case 226: return "Subphrase"; break;
         case 244: return "Subphrase"; break;
         case 251: return "Subphrase"; break;
         case 258: return "type_qualifier_list"; break;
         case 263: return "Subphrase"; break;
         case 271: return "parameter_type_list"; break;
         case 276: return "Subphrase"; break;
         case 284: return "parameter_list"; break;
         case 289: return "Subphrase"; break;
         case 298: return "parameter_declaration"; break;
         case 303: return "Subphrase"; break;
         case 314: return "identifier_list"; break;
         case 319: return "Subphrase"; break;
         case 328: return "initializer"; break;
         case 332: return "Subphrase"; break;
         case 343: return "Subphrase"; break;
         case 350: return "initializer_list"; break;
         case 355: return "Subphrase"; break;
         case 363: return "type_name"; break;
         case 368: return "Subphrase"; break;
         case 375: return "abstract_declarator"; break;
         case 386: return "Subphrase"; break;
         case 393: return "Subphrase"; break;
         case 405: return "Subphrase"; break;
         case 412: return "Subphrase"; break;
         case 419: return "statement"; break;
         case 423: return "Subphrase"; break;
         case 455: return "labeled_statement"; break;
         case 474: return "expression_statement"; break;
         case 479: return "Subphrase"; break;
         case 486: return "compound_statement"; break;
         case 493: return "Subphrase"; break;
         case 500: return "Subphrase"; break;
         case 507: return "statement_list"; break;
         case 512: return "Subphrase"; break;
         case 520: return "selection_statement"; break;
         case 537: return "Subphrase"; break;
         case 545: return "iteration_statement"; break;
         case 549: return "Subphrase"; break;
         case 579: return "Subphrase"; break;
         case 586: return "Subphrase"; break;
         case 593: return "Subphrase"; break;
         case 600: return "jump_statement"; break;
         case 604: return "Subphrase"; break;
         case 626: return "Subphrase"; break;
         case 633: return "print_statement"; break;
         case 639: return "input_statement"; break;
         case 646: return "Subphrase"; break;
         case 655: return "expression"; break;
         case 665: return "assignment_expression"; break;
         case 675: return "assignment_operator"; break;
         case 683: return "conditional_expression"; break;
         case 695: return "constant_expression"; break;
         case 699: return "logical_OR_expression"; break;
         case 709: return "logical_AND_expression"; break;
         case 719: return "inclusive_OR_expression"; break;
         case 729: return "exclusive_OR_expression"; break;
         case 739: return "AND_expression"; break;
         case 749: return "equality_expression"; break;
         case 759: return "shift_expression"; break;
         case 769: return "additive_expression"; break;
         case 779: return "Subphrase"; break;
         case 787: return "multiplicative_expression"; break;
         case 797: return "Subphrase"; break;
         case 809: return "cast_expression"; break;
         case 820: return "unary_expression"; break;
         case 846: return "Subphrase"; break;
         case 854: return "unary_operator"; break;
         case 878: return "postfix_expression"; break;
         case 887: return "Subphrase"; break;
         case 918: return "Subphrase"; break;
         case 926: return "Subphrase"; break;
         case 933: return "primary_expression"; break;
         case 947: return "argument_expression_list"; break;
         case 952: return "Subphrase"; break;
         case 961: return "constant"; break;
         case 977: return "id"; break;
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
