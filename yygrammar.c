#line 1 "ass2.acc"

	#include <stdio.h>
	#include <stdlib.h>
	
	#include "parser.h"
	
	extern FILE * f;

# line 11 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 111: {
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
      case 112: {
         declaration_specifiers();
         } break;
      default: ;
      }
      declarator();
      switch (yyselect()) {
      case 113: {
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
      case 114: {
         init_declarator_list();
         } break;
      default: ;
      }
      get_lexval();
#line 33 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 85 "yygrammar.c"
      } break;
   }
}

declaration_list ()
{
   switch(yyselect()) {
   case 7: {
      switch (yyselect()) {
      case 115: {
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
      case 116: {
         storage_class_specifier();
         } break;
      case 117: {
         type_specifier();
         } break;
      case 118: {
         type_qualifier();
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 119: {
         declaration_specifiers();
         } break;
      default: ;
      }
      } break;
   }
}

storage_class_specifier ()
{
   YYSTYPE s;
   switch(yyselect()) {
   case 9: {
      switch (yyselect()) {
      case 120: {
         get_lexval();
         s = yylval;
         } break;
      case 121: {
         get_lexval();
         s = yylval;
         } break;
      case 122: {
         get_lexval();
         s = yylval;
         } break;
      case 123: {
         get_lexval();
         s = yylval;
         } break;
      case 124: {
         get_lexval();
         s = yylval;
         } break;
      default: printf("???\n"); exit(1);
      }
#line 49 "ass2.acc"
 fprintf(f, "{\\bf %s}", s.s); 
# line 161 "yygrammar.c"
      } break;
   }
}

type_specifier ()
{
   YYSTYPE s;
   switch(yyselect()) {
   case 10: {
      switch (yyselect()) {
      case 125: {
         get_lexval();
         s = yylval;
         } break;
      case 126: {
         get_lexval();
         s = yylval;
         } break;
      case 127: {
         get_lexval();
         s = yylval;
         } break;
      case 128: {
         get_lexval();
         s = yylval;
         } break;
      case 129: {
         get_lexval();
         s = yylval;
         } break;
      case 130: {
         get_lexval();
         s = yylval;
         } break;
      case 131: {
         get_lexval();
         s = yylval;
         } break;
      case 132: {
         get_lexval();
         s = yylval;
         } break;
      case 133: {
         get_lexval();
         s = yylval;
         } break;
      default: printf("???\n"); exit(1);
      }
#line 61 "ass2.acc"
 fprintf(f, "{\\bf %s}", s.s); 
# line 212 "yygrammar.c"
      } break;
   case 11: {
      struct_or_union_specifier();
      } break;
   case 12: {
      enum_specifier();
      } break;
   }
}

type_qualifier ()
{
   switch(yyselect()) {
   case 13: {
      get_lexval();
#line 66 "ass2.acc"
 fputs("{\\bf const}", f); 
# line 230 "yygrammar.c"
      } break;
   case 14: {
      get_lexval();
#line 67 "ass2.acc"
 fputs("{\\bf volatile}", f); 
# line 236 "yygrammar.c"
      } break;
   }
}

struct_or_union_specifier ()
{
   switch(yyselect()) {
   case 15: {
      struct_or_union();
      switch (yyselect()) {
      case 134: {
         get_lexval();
         } break;
      default: ;
      }
      get_lexval();
#line 71 "ass2.acc"
 fputs("\\{\\\\\n", f); 
# line 255 "yygrammar.c"
      struct_declaration_list();
      get_lexval();
#line 71 "ass2.acc"
 fputs("\\}\\\\\n", f); 
# line 260 "yygrammar.c"
      } break;
   case 16: {
      struct_or_union();
      get_lexval();
      } break;
   }
}

struct_or_union ()
{
   switch(yyselect()) {
   case 17: {
      get_lexval();
      } break;
   case 18: {
      get_lexval();
      } break;
   }
}

struct_declaration_list ()
{
   switch(yyselect()) {
   case 19: {
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
   case 20: {
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
   case 21: {
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
   case 22: {
      specifier_qualifier_list();
      struct_declarator_list();
      get_lexval();
#line 92 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 337 "yygrammar.c"
      } break;
   }
}

specifier_qualifier_list ()
{
   switch(yyselect()) {
   case 23: {
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
   case 24: {
      switch (yyselect()) {
      case 141: {
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
   case 25: {
      declarator();
      } break;
   case 26: {
      switch (yyselect()) {
      case 142: {
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
   case 27: {
      get_lexval();
      switch (yyselect()) {
      case 143: {
         get_lexval();
         } break;
      default: ;
      }
#line 109 "ass2.acc"
 fputs("\\{\\\\\n", f); 
# line 413 "yygrammar.c"
      get_lexval();
      enumerator_list();
      get_lexval();
#line 109 "ass2.acc"
 fputs("\\}\\\\\n", f); 
# line 419 "yygrammar.c"
      } break;
   case 28: {
      get_lexval();
      get_lexval();
      } break;
   }
}

enumerator_list ()
{
   switch(yyselect()) {
   case 29: {
      switch (yyselect()) {
      case 144: {
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
   case 30: {
      get_lexval();
      switch (yyselect()) {
      case 145: {
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
   case 31: {
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
   case 32: {
      get_lexval();
#line 126 "ass2.acc"
printf("Identifier within declarator: %s\n", yylval.s);
# line 482 "yygrammar.c"
      } break;
   case 33: {
      get_lexval();
      declarator();
      get_lexval();
#line 127 "ass2.acc"
printf("iets met haakjes\n");
# line 490 "yygrammar.c"
      } break;
   case 34: {
      direct_declarator();
      switch (yyselect()) {
      case 148: {
         get_lexval();
         switch (yyselect()) {
         case 147: {
            constant_expression();
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 149: {
         get_lexval();
         parameter_type_list();
         get_lexval();
         } break;
      case 151: {
         get_lexval();
         switch (yyselect()) {
         case 150: {
            identifier_list();
            } break;
         default: ;
         }
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
#line 128 "ass2.acc"
printf("nog iets met haakjes\n");
# line 524 "yygrammar.c"
      } break;
   }
}

pointer ()
{
   switch(yyselect()) {
   case 35: {
      get_lexval();
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
   case 36: {
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
   case 37: {
      parameter_list();
      switch (yyselect()) {
      case 155: {
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
   case 38: {
      switch (yyselect()) {
      case 156: {
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
   case 39: {
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
   case 40: {
      switch (yyselect()) {
      case 160: {
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
   case 41: {
      assignment_expression();
      } break;
   case 42: {
      get_lexval();
#line 157 "ass2.acc"
 fputs("\\{\\\\\n", f); 
# line 646 "yygrammar.c"
      initializer_list();
      switch (yyselect()) {
      case 161: {
         get_lexval();
         } break;
      default: ;
      }
      get_lexval();
#line 157 "ass2.acc"
 fputs("\\}\\\\\n", f); 
# line 657 "yygrammar.c"
      } break;
   }
}

initializer_list ()
{
   switch(yyselect()) {
   case 43: {
      switch (yyselect()) {
      case 162: {
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
   case 44: {
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
   case 45: {
      pointer();
      } break;
   case 46: {
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
   case 47: {
      get_lexval();
      abstract_declarator();
      get_lexval();
      } break;
   case 48: {
      switch (yyselect()) {
      case 165: {
         direct_abstract_declarator();
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 167: {
         get_lexval();
         switch (yyselect()) {
         case 166: {
            constant_expression();
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 169: {
         get_lexval();
         switch (yyselect()) {
         case 168: {
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
   case 49: {
      get_lexval();
      } break;
   }
}

statement ()
{
   switch(yyselect()) {
   case 50: {
      labeled_statement();
      } break;
   case 51: {
      expression_statement();
      } break;
   case 52: {
      compound_statement();
      } break;
   case 53: {
      selection_statement();
      } break;
   case 54: {
      iteration_statement();
      } break;
   case 55: {
      jump_statement();
      } break;
   }
}

labeled_statement ()
{
   switch(yyselect()) {
   case 56: {
      get_lexval();
      get_lexval();
      statement();
      } break;
   case 57: {
      get_lexval();
      constant_expression();
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
   switch(yyselect()) {
   case 59: {
      switch (yyselect()) {
      case 170: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 198 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 821 "yygrammar.c"
      } break;
   }
}

compound_statement ()
{
   switch(yyselect()) {
   case 60: {
      get_lexval();
#line 202 "ass2.acc"
 fputs("\\{\\\\\n", f); 
# line 833 "yygrammar.c"
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
#line 202 "ass2.acc"
 fputs("\\}\\\\\n", f); 
# line 849 "yygrammar.c"
      } break;
   }
}

statement_list ()
{
   switch(yyselect()) {
   case 61: {
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
   case 62: {
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      statement();
      switch (yyselect()) {
      case 174: {
         get_lexval();
         statement();
         } break;
      default: ;
      }
      } break;
   case 63: {
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
   case 64: {
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      statement();
      } break;
   case 65: {
      get_lexval();
      statement();
      get_lexval();
      get_lexval();
      expression();
      get_lexval();
      get_lexval();
#line 216 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 916 "yygrammar.c"
      } break;
   case 66: {
      get_lexval();
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
      switch (yyselect()) {
      case 177: {
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
   case 67: {
      get_lexval();
      get_lexval();
      get_lexval();
#line 221 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 956 "yygrammar.c"
      } break;
   case 68: {
      get_lexval();
      get_lexval();
#line 222 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 963 "yygrammar.c"
      } break;
   case 69: {
      get_lexval();
      get_lexval();
#line 223 "ass2.acc"
 fputs(";\\\\\n", f); 
# line 970 "yygrammar.c"
      } break;
   case 70: {
      get_lexval();
      switch (yyselect()) {
      case 178: {
         expression();
         } break;
      default: ;
      }
      get_lexval();
#line 224 "ass2.acc"
 printf("Return\n"); fputs(";\\\\\n", f); 
# line 983 "yygrammar.c"
      } break;
   }
}

expression ()
{
   switch(yyselect()) {
   case 71: {
      switch (yyselect()) {
      case 179: {
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
   case 72: {
      conditional_expression();
      } break;
   case 73: {
      unary_expression();
      assignment_operator();
      assignment_expression();
      } break;
   }
}

assignment_operator ()
{
   switch(yyselect()) {
   case 74: {
      get_lexval();
      } break;
   case 75: {
      get_lexval();
      } break;
   }
}

conditional_expression ()
{
   switch(yyselect()) {
   case 76: {
      logical_OR_expression();
      switch (yyselect()) {
      case 180: {
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
   case 77: {
      conditional_expression();
      } break;
   }
}

logical_OR_expression ()
{
   switch(yyselect()) {
   case 78: {
      switch (yyselect()) {
      case 181: {
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
   case 79: {
      switch (yyselect()) {
      case 182: {
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
   case 80: {
      switch (yyselect()) {
      case 183: {
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
   case 81: {
      switch (yyselect()) {
      case 184: {
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
   case 82: {
      switch (yyselect()) {
      case 185: {
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
   case 83: {
      switch (yyselect()) {
      case 186: {
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
   case 84: {
      switch (yyselect()) {
      case 187: {
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
   case 85: {
      switch (yyselect()) {
      case 190: {
         additive_expression();
         switch (yyselect()) {
         case 188: {
            get_lexval();
            } break;
         case 189: {
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
   case 86: {
      switch (yyselect()) {
      case 194: {
         multiplicative_expression();
         switch (yyselect()) {
         case 191: {
            get_lexval();
            } break;
         case 192: {
            get_lexval();
            } break;
         case 193: {
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
   case 87: {
      unary_expression();
      } break;
   case 88: {
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
   case 89: {
      postfix_expression();
      } break;
   case 90: {
      switch (yyselect()) {
      case 195: {
         get_lexval();
         } break;
      case 196: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
      unary_expression();
      } break;
   case 91: {
      unary_operator();
      cast_expression();
      } break;
   case 92: {
      get_lexval();
      unary_expression();
      } break;
   case 93: {
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
   case 94: {
      get_lexval();
      } break;
   case 95: {
      get_lexval();
      } break;
   case 96: {
      get_lexval();
      } break;
   case 97: {
      get_lexval();
      } break;
   case 98: {
      get_lexval();
      } break;
   case 99: {
      get_lexval();
      } break;
   }
}

postfix_expression ()
{
   switch(yyselect()) {
   case 100: {
      primary_expression();
      } break;
   case 101: {
      postfix_expression();
      switch (yyselect()) {
      case 197: {
         get_lexval();
         expression();
         get_lexval();
         } break;
      case 199: {
         get_lexval();
         switch (yyselect()) {
         case 198: {
            argument_expression_list();
            } break;
         default: ;
         }
         get_lexval();
         } break;
      case 200: {
         get_lexval();
         get_lexval();
         } break;
      case 201: {
         get_lexval();
         get_lexval();
         } break;
      case 202: {
         get_lexval();
         } break;
      case 203: {
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
   case 102: {
      get_lexval();
      } break;
   case 103: {
      constant();
      } break;
   case 104: {
      get_lexval();
#line 310 "ass2.acc"
 fprintf(f, "\"%s\"\n", yylval.s); 
# line 1351 "yygrammar.c"
      } break;
   case 105: {
      get_lexval();
      expression();
      get_lexval();
      } break;
   }
}

argument_expression_list ()
{
   switch(yyselect()) {
   case 106: {
      switch (yyselect()) {
      case 204: {
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
   case 107: {
      get_lexval();
#line 319 "ass2.acc"
printf("intconst: %lu\n", yylval.i); fprintf(f, "$ %u $\n", yylval.i); 
# line 1384 "yygrammar.c"
      } break;
   case 108: {
      get_lexval();
      } break;
   case 109: {
      get_lexval();
      } break;
   case 110: {
      get_lexval();
#line 322 "ass2.acc"
 printf("Constant\n"); 
# line 1396 "yygrammar.c"
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
int c_length = 1139;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 111,
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
/* 25 */ 341,
/* 26 */ 37,
/* 27 */ 653,
/* 28 */ -23,
/* 29 */ 5,
/* 30 */ 34,
/* 31 */ 69,
/* 32 */ -30,
/* 33 */ 112,
/* 34 */ 0,
/* 35 */ -30,
/* 36 */ 205,
/* 37 */ 41,
/* 38 */ 57,
/* 39 */ -37,
/* 40 */ 113,
/* 41 */ 0,
/* 42 */ -37,
/* 43 */ 206,
/* 44 */ 0,
/* 45 */ 69,
/* 46 */ 50,
/* 47 */ 50059,
/* 48 */ -44,
/* 49 */ 6,
/* 50 */ 54,
/* 51 */ 213,
/* 52 */ -50,
/* 53 */ 114,
/* 54 */ 0,
/* 55 */ -50,
/* 56 */ 207,
/* 57 */ 0,
/* 58 */ 62,
/* 59 */ 44,
/* 60 */ -57,
/* 61 */ 7,
/* 62 */ 66,
/* 63 */ 57,
/* 64 */ -62,
/* 65 */ 115,
/* 66 */ 0,
/* 67 */ -62,
/* 68 */ 208,
/* 69 */ 0,
/* 70 */ 74,
/* 71 */ 86,
/* 72 */ -69,
/* 73 */ 8,
/* 74 */ 78,
/* 75 */ 93,
/* 76 */ -74,
/* 77 */ 116,
/* 78 */ 82,
/* 79 */ 117,
/* 80 */ -74,
/* 81 */ 117,
/* 82 */ 0,
/* 83 */ 165,
/* 84 */ -74,
/* 85 */ 118,
/* 86 */ 90,
/* 87 */ 69,
/* 88 */ -86,
/* 89 */ 119,
/* 90 */ 0,
/* 91 */ -86,
/* 92 */ 209,
/* 93 */ 0,
/* 94 */ 97,
/* 95 */ -93,
/* 96 */ 9,
/* 97 */ 101,
/* 98 */ 50256,
/* 99 */ -97,
/* 100 */ 120,
/* 101 */ 105,
/* 102 */ 50274,
/* 103 */ -97,
/* 104 */ 121,
/* 105 */ 109,
/* 106 */ 50279,
/* 107 */ -97,
/* 108 */ 122,
/* 109 */ 113,
/* 110 */ 50267,
/* 111 */ -97,
/* 112 */ 123,
/* 113 */ 0,
/* 114 */ 50282,
/* 115 */ -97,
/* 116 */ 124,
/* 117 */ 121,
/* 118 */ 129,
/* 119 */ -117,
/* 120 */ 10,
/* 121 */ 125,
/* 122 */ 173,
/* 123 */ -117,
/* 124 */ 11,
/* 125 */ 0,
/* 126 */ 295,
/* 127 */ -117,
/* 128 */ 12,
/* 129 */ 133,
/* 130 */ 50285,
/* 131 */ -129,
/* 132 */ 125,
/* 133 */ 137,
/* 134 */ 50259,
/* 135 */ -129,
/* 136 */ 126,
/* 137 */ 141,
/* 138 */ 50276,
/* 139 */ -129,
/* 140 */ 127,
/* 141 */ 145,
/* 142 */ 50272,
/* 143 */ -129,
/* 144 */ 128,
/* 145 */ 149,
/* 146 */ 50273,
/* 147 */ -129,
/* 148 */ 129,
/* 149 */ 153,
/* 150 */ 50268,
/* 151 */ -129,
/* 152 */ 130,
/* 153 */ 157,
/* 154 */ 50264,
/* 155 */ -129,
/* 156 */ 131,
/* 157 */ 161,
/* 158 */ 50277,
/* 159 */ -129,
/* 160 */ 132,
/* 161 */ 0,
/* 162 */ 50284,
/* 163 */ -129,
/* 164 */ 133,
/* 165 */ 169,
/* 166 */ 50260,
/* 167 */ -165,
/* 168 */ 13,
/* 169 */ 0,
/* 170 */ 50286,
/* 171 */ -165,
/* 172 */ 14,
/* 173 */ 181,
/* 174 */ 193,
/* 175 */ 186,
/* 176 */ 50123,
/* 177 */ 201,
/* 178 */ 50125,
/* 179 */ -173,
/* 180 */ 15,
/* 181 */ 0,
/* 182 */ 193,
/* 183 */ 50299,
/* 184 */ -173,
/* 185 */ 16,
/* 186 */ 190,
/* 187 */ 50299,
/* 188 */ -186,
/* 189 */ 134,
/* 190 */ 0,
/* 191 */ -186,
/* 192 */ 210,
/* 193 */ 197,
/* 194 */ 50280,
/* 195 */ -193,
/* 196 */ 17,
/* 197 */ 0,
/* 198 */ 50283,
/* 199 */ -193,
/* 200 */ 18,
/* 201 */ 0,
/* 202 */ 206,
/* 203 */ 239,
/* 204 */ -201,
/* 205 */ 19,
/* 206 */ 210,
/* 207 */ 201,
/* 208 */ -206,
/* 209 */ 135,
/* 210 */ 0,
/* 211 */ -206,
/* 212 */ 211,
/* 213 */ 0,
/* 214 */ 218,
/* 215 */ 226,
/* 216 */ -213,
/* 217 */ 20,
/* 218 */ 223,
/* 219 */ 213,
/* 220 */ 50044,
/* 221 */ -218,
/* 222 */ 136,
/* 223 */ 0,
/* 224 */ -218,
/* 225 */ 212,
/* 226 */ 0,
/* 227 */ 231,
/* 228 */ 491,
/* 229 */ -226,
/* 230 */ 21,
/* 231 */ 236,
/* 232 */ 341,
/* 233 */ 50061,
/* 234 */ -231,
/* 235 */ 137,
/* 236 */ 0,
/* 237 */ -231,
/* 238 */ 213,
/* 239 */ 0,
/* 240 */ 245,
/* 241 */ 265,
/* 242 */ 50059,
/* 243 */ -239,
/* 244 */ 22,
/* 245 */ 0,
/* 246 */ 250,
/* 247 */ 258,
/* 248 */ -245,
/* 249 */ 23,
/* 250 */ 254,
/* 251 */ 117,
/* 252 */ -250,
/* 253 */ 138,
/* 254 */ 0,
/* 255 */ 165,
/* 256 */ -250,
/* 257 */ 139,
/* 258 */ 262,
/* 259 */ 245,
/* 260 */ -258,
/* 261 */ 140,
/* 262 */ 0,
/* 263 */ -258,
/* 264 */ 214,
/* 265 */ 0,
/* 266 */ 270,
/* 267 */ 278,
/* 268 */ -265,
/* 269 */ 24,
/* 270 */ 275,
/* 271 */ 265,
/* 272 */ 50044,
/* 273 */ -270,
/* 274 */ 141,
/* 275 */ 0,
/* 276 */ -270,
/* 277 */ 215,
/* 278 */ 282,
/* 279 */ 341,
/* 280 */ -278,
/* 281 */ 25,
/* 282 */ 0,
/* 283 */ 288,
/* 284 */ 50058,
/* 285 */ 837,
/* 286 */ -278,
/* 287 */ 26,
/* 288 */ 292,
/* 289 */ 341,
/* 290 */ -288,
/* 291 */ 142,
/* 292 */ 0,
/* 293 */ -288,
/* 294 */ 216,
/* 295 */ 303,
/* 296 */ 50266,
/* 297 */ 308,
/* 298 */ 50123,
/* 299 */ 315,
/* 300 */ 50125,
/* 301 */ -295,
/* 302 */ 27,
/* 303 */ 0,
/* 304 */ 50266,
/* 305 */ 50299,
/* 306 */ -295,
/* 307 */ 28,
/* 308 */ 312,
/* 309 */ 50299,
/* 310 */ -308,
/* 311 */ 143,
/* 312 */ 0,
/* 313 */ -308,
/* 314 */ 217,
/* 315 */ 0,
/* 316 */ 320,
/* 317 */ 328,
/* 318 */ -315,
/* 319 */ 29,
/* 320 */ 325,
/* 321 */ 315,
/* 322 */ 50044,
/* 323 */ -320,
/* 324 */ 144,
/* 325 */ 0,
/* 326 */ -320,
/* 327 */ 218,
/* 328 */ 0,
/* 329 */ 50299,
/* 330 */ 333,
/* 331 */ -328,
/* 332 */ 30,
/* 333 */ 338,
/* 334 */ 50061,
/* 335 */ 837,
/* 336 */ -333,
/* 337 */ 145,
/* 338 */ 0,
/* 339 */ -333,
/* 340 */ 219,
/* 341 */ 0,
/* 342 */ 346,
/* 343 */ 353,
/* 344 */ -341,
/* 345 */ 31,
/* 346 */ 350,
/* 347 */ 400,
/* 348 */ -346,
/* 349 */ 146,
/* 350 */ 0,
/* 351 */ -346,
/* 352 */ 220,
/* 353 */ 357,
/* 354 */ 50299,
/* 355 */ -353,
/* 356 */ 32,
/* 357 */ 363,
/* 358 */ 50040,
/* 359 */ 341,
/* 360 */ 50041,
/* 361 */ -353,
/* 362 */ 33,
/* 363 */ 0,
/* 364 */ 353,
/* 365 */ 368,
/* 366 */ -353,
/* 367 */ 34,
/* 368 */ 374,
/* 369 */ 50091,
/* 370 */ 386,
/* 371 */ 50093,
/* 372 */ -368,
/* 373 */ 148,
/* 374 */ 380,
/* 375 */ 50040,
/* 376 */ 432,
/* 377 */ 50041,
/* 378 */ -368,
/* 379 */ 149,
/* 380 */ 0,
/* 381 */ 50040,
/* 382 */ 393,
/* 383 */ 50041,
/* 384 */ -368,
/* 385 */ 151,
/* 386 */ 390,
/* 387 */ 837,
/* 388 */ -386,
/* 389 */ 147,
/* 390 */ 0,
/* 391 */ -386,
/* 392 */ 221,
/* 393 */ 397,
/* 394 */ 478,
/* 395 */ -393,
/* 396 */ 150,
/* 397 */ 0,
/* 398 */ -393,
/* 399 */ 222,
/* 400 */ 0,
/* 401 */ 50042,
/* 402 */ 406,
/* 403 */ 413,
/* 404 */ -400,
/* 405 */ 35,
/* 406 */ 410,
/* 407 */ 420,
/* 408 */ -406,
/* 409 */ 152,
/* 410 */ 0,
/* 411 */ -406,
/* 412 */ 223,
/* 413 */ 417,
/* 414 */ 400,
/* 415 */ -413,
/* 416 */ 153,
/* 417 */ 0,
/* 418 */ -413,
/* 419 */ 224,
/* 420 */ 0,
/* 421 */ 425,
/* 422 */ 165,
/* 423 */ -420,
/* 424 */ 36,
/* 425 */ 429,
/* 426 */ 420,
/* 427 */ -425,
/* 428 */ 154,
/* 429 */ 0,
/* 430 */ -425,
/* 431 */ 225,
/* 432 */ 0,
/* 433 */ 445,
/* 434 */ 437,
/* 435 */ -432,
/* 436 */ 37,
/* 437 */ 442,
/* 438 */ 50044,
/* 439 */ 50290,
/* 440 */ -437,
/* 441 */ 155,
/* 442 */ 0,
/* 443 */ -437,
/* 444 */ 226,
/* 445 */ 0,
/* 446 */ 450,
/* 447 */ 458,
/* 448 */ -445,
/* 449 */ 38,
/* 450 */ 455,
/* 451 */ 445,
/* 452 */ 50044,
/* 453 */ -450,
/* 454 */ 156,
/* 455 */ 0,
/* 456 */ -450,
/* 457 */ 227,
/* 458 */ 0,
/* 459 */ 69,
/* 460 */ 463,
/* 461 */ -458,
/* 462 */ 39,
/* 463 */ 467,
/* 464 */ 341,
/* 465 */ -463,
/* 466 */ 157,
/* 467 */ 0,
/* 468 */ 471,
/* 469 */ -463,
/* 470 */ 159,
/* 471 */ 475,
/* 472 */ 534,
/* 473 */ -471,
/* 474 */ 158,
/* 475 */ 0,
/* 476 */ -471,
/* 477 */ 228,
/* 478 */ 0,
/* 479 */ 483,
/* 480 */ 50299,
/* 481 */ -478,
/* 482 */ 40,
/* 483 */ 488,
/* 484 */ 478,
/* 485 */ 50044,
/* 486 */ -483,
/* 487 */ 160,
/* 488 */ 0,
/* 489 */ -483,
/* 490 */ 229,
/* 491 */ 495,
/* 492 */ 804,
/* 493 */ -491,
/* 494 */ 41,
/* 495 */ 0,
/* 496 */ 50123,
/* 497 */ 509,
/* 498 */ 502,
/* 499 */ 50125,
/* 500 */ -491,
/* 501 */ 42,
/* 502 */ 506,
/* 503 */ 50044,
/* 504 */ -502,
/* 505 */ 161,
/* 506 */ 0,
/* 507 */ -502,
/* 508 */ 230,
/* 509 */ 0,
/* 510 */ 514,
/* 511 */ 491,
/* 512 */ -509,
/* 513 */ 43,
/* 514 */ 519,
/* 515 */ 509,
/* 516 */ 50044,
/* 517 */ -514,
/* 518 */ 162,
/* 519 */ 0,
/* 520 */ -514,
/* 521 */ 231,
/* 522 */ 0,
/* 523 */ 245,
/* 524 */ 527,
/* 525 */ -522,
/* 526 */ 44,
/* 527 */ 531,
/* 528 */ 534,
/* 529 */ -527,
/* 530 */ 163,
/* 531 */ 0,
/* 532 */ -527,
/* 533 */ 232,
/* 534 */ 538,
/* 535 */ 400,
/* 536 */ -534,
/* 537 */ 45,
/* 538 */ 0,
/* 539 */ 543,
/* 540 */ 550,
/* 541 */ -534,
/* 542 */ 46,
/* 543 */ 547,
/* 544 */ 400,
/* 545 */ -543,
/* 546 */ 164,
/* 547 */ 0,
/* 548 */ -543,
/* 549 */ 233,
/* 550 */ 556,
/* 551 */ 50040,
/* 552 */ 534,
/* 553 */ 50041,
/* 554 */ -550,
/* 555 */ 47,
/* 556 */ 0,
/* 557 */ 561,
/* 558 */ 568,
/* 559 */ -550,
/* 560 */ 48,
/* 561 */ 565,
/* 562 */ 550,
/* 563 */ -561,
/* 564 */ 165,
/* 565 */ 0,
/* 566 */ -561,
/* 567 */ 234,
/* 568 */ 574,
/* 569 */ 50091,
/* 570 */ 580,
/* 571 */ 50093,
/* 572 */ -568,
/* 573 */ 167,
/* 574 */ 0,
/* 575 */ 50040,
/* 576 */ 587,
/* 577 */ 50041,
/* 578 */ -568,
/* 579 */ 169,
/* 580 */ 584,
/* 581 */ 837,
/* 582 */ -580,
/* 583 */ 166,
/* 584 */ 0,
/* 585 */ -580,
/* 586 */ 235,
/* 587 */ 591,
/* 588 */ 432,
/* 589 */ -587,
/* 590 */ 168,
/* 591 */ 0,
/* 592 */ -587,
/* 593 */ 236,
/* 594 */ 0,
/* 595 */ 50299,
/* 596 */ -594,
/* 597 */ 49,
/* 598 */ 602,
/* 599 */ 622,
/* 600 */ -598,
/* 601 */ 50,
/* 602 */ 606,
/* 603 */ 641,
/* 604 */ -598,
/* 605 */ 51,
/* 606 */ 610,
/* 607 */ 653,
/* 608 */ -598,
/* 609 */ 52,
/* 610 */ 614,
/* 611 */ 686,
/* 612 */ -598,
/* 613 */ 53,
/* 614 */ 618,
/* 615 */ 711,
/* 616 */ -598,
/* 617 */ 54,
/* 618 */ 0,
/* 619 */ 762,
/* 620 */ -598,
/* 621 */ 55,
/* 622 */ 628,
/* 623 */ 50299,
/* 624 */ 50058,
/* 625 */ 598,
/* 626 */ -622,
/* 627 */ 56,
/* 628 */ 635,
/* 629 */ 50258,
/* 630 */ 837,
/* 631 */ 50058,
/* 632 */ 598,
/* 633 */ -622,
/* 634 */ 57,
/* 635 */ 0,
/* 636 */ 50262,
/* 637 */ 50058,
/* 638 */ 598,
/* 639 */ -622,
/* 640 */ 58,
/* 641 */ 0,
/* 642 */ 646,
/* 643 */ 50059,
/* 644 */ -641,
/* 645 */ 59,
/* 646 */ 650,
/* 647 */ 791,
/* 648 */ -646,
/* 649 */ 170,
/* 650 */ 0,
/* 651 */ -646,
/* 652 */ 237,
/* 653 */ 0,
/* 654 */ 50123,
/* 655 */ 660,
/* 656 */ 667,
/* 657 */ 50125,
/* 658 */ -653,
/* 659 */ 60,
/* 660 */ 664,
/* 661 */ 57,
/* 662 */ -660,
/* 663 */ 171,
/* 664 */ 0,
/* 665 */ -660,
/* 666 */ 238,
/* 667 */ 671,
/* 668 */ 674,
/* 669 */ -667,
/* 670 */ 172,
/* 671 */ 0,
/* 672 */ -667,
/* 673 */ 239,
/* 674 */ 0,
/* 675 */ 679,
/* 676 */ 598,
/* 677 */ -674,
/* 678 */ 61,
/* 679 */ 683,
/* 680 */ 674,
/* 681 */ -679,
/* 682 */ 173,
/* 683 */ 0,
/* 684 */ -679,
/* 685 */ 240,
/* 686 */ 695,
/* 687 */ 50271,
/* 688 */ 50040,
/* 689 */ 791,
/* 690 */ 50041,
/* 691 */ 598,
/* 692 */ 703,
/* 693 */ -686,
/* 694 */ 62,
/* 695 */ 0,
/* 696 */ 50281,
/* 697 */ 50040,
/* 698 */ 791,
/* 699 */ 50041,
/* 700 */ 598,
/* 701 */ -686,
/* 702 */ 63,
/* 703 */ 708,
/* 704 */ 50265,
/* 705 */ 598,
/* 706 */ -703,
/* 707 */ 174,
/* 708 */ 0,
/* 709 */ -703,
/* 710 */ 241,
/* 711 */ 719,
/* 712 */ 50287,
/* 713 */ 50040,
/* 714 */ 791,
/* 715 */ 50041,
/* 716 */ 598,
/* 717 */ -711,
/* 718 */ 64,
/* 719 */ 729,
/* 720 */ 50263,
/* 721 */ 598,
/* 722 */ 50287,
/* 723 */ 50040,
/* 724 */ 791,
/* 725 */ 50041,
/* 726 */ 50059,
/* 727 */ -711,
/* 728 */ 65,
/* 729 */ 0,
/* 730 */ 50269,
/* 731 */ 50040,
/* 732 */ 741,
/* 733 */ 50059,
/* 734 */ 748,
/* 735 */ 50059,
/* 736 */ 755,
/* 737 */ 50041,
/* 738 */ 598,
/* 739 */ -711,
/* 740 */ 66,
/* 741 */ 745,
/* 742 */ 791,
/* 743 */ -741,
/* 744 */ 175,
/* 745 */ 0,
/* 746 */ -741,
/* 747 */ 242,
/* 748 */ 752,
/* 749 */ 791,
/* 750 */ -748,
/* 751 */ 176,
/* 752 */ 0,
/* 753 */ -748,
/* 754 */ 243,
/* 755 */ 759,
/* 756 */ 791,
/* 757 */ -755,
/* 758 */ 177,
/* 759 */ 0,
/* 760 */ -755,
/* 761 */ 244,
/* 762 */ 768,
/* 763 */ 50270,
/* 764 */ 50299,
/* 765 */ 50059,
/* 766 */ -762,
/* 767 */ 67,
/* 768 */ 773,
/* 769 */ 50261,
/* 770 */ 50059,
/* 771 */ -762,
/* 772 */ 68,
/* 773 */ 778,
/* 774 */ 50257,
/* 775 */ 50059,
/* 776 */ -762,
/* 777 */ 69,
/* 778 */ 0,
/* 779 */ 50275,
/* 780 */ 784,
/* 781 */ 50059,
/* 782 */ -762,
/* 783 */ 70,
/* 784 */ 788,
/* 785 */ 791,
/* 786 */ -784,
/* 787 */ 178,
/* 788 */ 0,
/* 789 */ -784,
/* 790 */ 245,
/* 791 */ 0,
/* 792 */ 796,
/* 793 */ 804,
/* 794 */ -791,
/* 795 */ 71,
/* 796 */ 801,
/* 797 */ 791,
/* 798 */ 50044,
/* 799 */ -796,
/* 800 */ 179,
/* 801 */ 0,
/* 802 */ -796,
/* 803 */ 246,
/* 804 */ 808,
/* 805 */ 822,
/* 806 */ -804,
/* 807 */ 72,
/* 808 */ 0,
/* 809 */ 989,
/* 810 */ 814,
/* 811 */ 804,
/* 812 */ -804,
/* 813 */ 73,
/* 814 */ 818,
/* 815 */ 50291,
/* 816 */ -814,
/* 817 */ 74,
/* 818 */ 0,
/* 819 */ 50061,
/* 820 */ -814,
/* 821 */ 75,
/* 822 */ 0,
/* 823 */ 841,
/* 824 */ 827,
/* 825 */ -822,
/* 826 */ 76,
/* 827 */ 834,
/* 828 */ 50063,
/* 829 */ 791,
/* 830 */ 50058,
/* 831 */ 822,
/* 832 */ -827,
/* 833 */ 180,
/* 834 */ 0,
/* 835 */ -827,
/* 836 */ 247,
/* 837 */ 0,
/* 838 */ 822,
/* 839 */ -837,
/* 840 */ 77,
/* 841 */ 0,
/* 842 */ 846,
/* 843 */ 854,
/* 844 */ -841,
/* 845 */ 78,
/* 846 */ 851,
/* 847 */ 841,
/* 848 */ 50297,
/* 849 */ -846,
/* 850 */ 181,
/* 851 */ 0,
/* 852 */ -846,
/* 853 */ 248,
/* 854 */ 0,
/* 855 */ 859,
/* 856 */ 867,
/* 857 */ -854,
/* 858 */ 79,
/* 859 */ 864,
/* 860 */ 854,
/* 861 */ 50298,
/* 862 */ -859,
/* 863 */ 182,
/* 864 */ 0,
/* 865 */ -859,
/* 866 */ 249,
/* 867 */ 0,
/* 868 */ 872,
/* 869 */ 880,
/* 870 */ -867,
/* 871 */ 80,
/* 872 */ 877,
/* 873 */ 867,
/* 874 */ 50301,
/* 875 */ -872,
/* 876 */ 183,
/* 877 */ 0,
/* 878 */ -872,
/* 879 */ 250,
/* 880 */ 0,
/* 881 */ 885,
/* 882 */ 893,
/* 883 */ -880,
/* 884 */ 81,
/* 885 */ 890,
/* 886 */ 880,
/* 887 */ 50303,
/* 888 */ -885,
/* 889 */ 184,
/* 890 */ 0,
/* 891 */ -885,
/* 892 */ 251,
/* 893 */ 0,
/* 894 */ 898,
/* 895 */ 906,
/* 896 */ -893,
/* 897 */ 82,
/* 898 */ 903,
/* 899 */ 893,
/* 900 */ 50302,
/* 901 */ -898,
/* 902 */ 185,
/* 903 */ 0,
/* 904 */ -898,
/* 905 */ 252,
/* 906 */ 0,
/* 907 */ 911,
/* 908 */ 919,
/* 909 */ -906,
/* 910 */ 83,
/* 911 */ 916,
/* 912 */ 906,
/* 913 */ 50292,
/* 914 */ -911,
/* 915 */ 186,
/* 916 */ 0,
/* 917 */ -911,
/* 918 */ 253,
/* 919 */ 0,
/* 920 */ 924,
/* 921 */ 932,
/* 922 */ -919,
/* 923 */ 84,
/* 924 */ 929,
/* 925 */ 919,
/* 926 */ 50304,
/* 927 */ -924,
/* 928 */ 187,
/* 929 */ 0,
/* 930 */ -924,
/* 931 */ 254,
/* 932 */ 0,
/* 933 */ 937,
/* 934 */ 953,
/* 935 */ -932,
/* 936 */ 85,
/* 937 */ 942,
/* 938 */ 932,
/* 939 */ 945,
/* 940 */ -937,
/* 941 */ 190,
/* 942 */ 0,
/* 943 */ -937,
/* 944 */ 255,
/* 945 */ 949,
/* 946 */ 50043,
/* 947 */ -945,
/* 948 */ 188,
/* 949 */ 0,
/* 950 */ 50045,
/* 951 */ -945,
/* 952 */ 189,
/* 953 */ 0,
/* 954 */ 958,
/* 955 */ 978,
/* 956 */ -953,
/* 957 */ 86,
/* 958 */ 963,
/* 959 */ 953,
/* 960 */ 966,
/* 961 */ -958,
/* 962 */ 194,
/* 963 */ 0,
/* 964 */ -958,
/* 965 */ 256,
/* 966 */ 970,
/* 967 */ 50042,
/* 968 */ -966,
/* 969 */ 191,
/* 970 */ 974,
/* 971 */ 50047,
/* 972 */ -966,
/* 973 */ 192,
/* 974 */ 0,
/* 975 */ 50037,
/* 976 */ -966,
/* 977 */ 193,
/* 978 */ 982,
/* 979 */ 989,
/* 980 */ -978,
/* 981 */ 87,
/* 982 */ 0,
/* 983 */ 50040,
/* 984 */ 522,
/* 985 */ 50041,
/* 986 */ 978,
/* 987 */ -978,
/* 988 */ 88,
/* 989 */ 993,
/* 990 */ 1047,
/* 991 */ -989,
/* 992 */ 89,
/* 993 */ 998,
/* 994 */ 1015,
/* 995 */ 989,
/* 996 */ -989,
/* 997 */ 90,
/* 998 */ 1003,
/* 999 */ 1023,
/* 1000 */ 978,
/* 1001 */ -989,
/* 1002 */ 91,
/* 1003 */ 1008,
/* 1004 */ 50278,
/* 1005 */ 989,
/* 1006 */ -989,
/* 1007 */ 92,
/* 1008 */ 0,
/* 1009 */ 50278,
/* 1010 */ 50040,
/* 1011 */ 522,
/* 1012 */ 50041,
/* 1013 */ -989,
/* 1014 */ 93,
/* 1015 */ 1019,
/* 1016 */ 50294,
/* 1017 */ -1015,
/* 1018 */ 195,
/* 1019 */ 0,
/* 1020 */ 50295,
/* 1021 */ -1015,
/* 1022 */ 196,
/* 1023 */ 1027,
/* 1024 */ 50038,
/* 1025 */ -1023,
/* 1026 */ 94,
/* 1027 */ 1031,
/* 1028 */ 50042,
/* 1029 */ -1023,
/* 1030 */ 95,
/* 1031 */ 1035,
/* 1032 */ 50043,
/* 1033 */ -1023,
/* 1034 */ 96,
/* 1035 */ 1039,
/* 1036 */ 50045,
/* 1037 */ -1023,
/* 1038 */ 97,
/* 1039 */ 1043,
/* 1040 */ 50126,
/* 1041 */ -1023,
/* 1042 */ 98,
/* 1043 */ 0,
/* 1044 */ 50033,
/* 1045 */ -1023,
/* 1046 */ 99,
/* 1047 */ 1051,
/* 1048 */ 1093,
/* 1049 */ -1047,
/* 1050 */ 100,
/* 1051 */ 0,
/* 1052 */ 1047,
/* 1053 */ 1056,
/* 1054 */ -1047,
/* 1055 */ 101,
/* 1056 */ 1062,
/* 1057 */ 50091,
/* 1058 */ 791,
/* 1059 */ 50093,
/* 1060 */ -1056,
/* 1061 */ 197,
/* 1062 */ 1068,
/* 1063 */ 50040,
/* 1064 */ 1086,
/* 1065 */ 50041,
/* 1066 */ -1056,
/* 1067 */ 199,
/* 1068 */ 1073,
/* 1069 */ 50046,
/* 1070 */ 50299,
/* 1071 */ -1056,
/* 1072 */ 200,
/* 1073 */ 1078,
/* 1074 */ 50296,
/* 1075 */ 50299,
/* 1076 */ -1056,
/* 1077 */ 201,
/* 1078 */ 1082,
/* 1079 */ 50294,
/* 1080 */ -1056,
/* 1081 */ 202,
/* 1082 */ 0,
/* 1083 */ 50295,
/* 1084 */ -1056,
/* 1085 */ 203,
/* 1086 */ 1090,
/* 1087 */ 1111,
/* 1088 */ -1086,
/* 1089 */ 198,
/* 1090 */ 0,
/* 1091 */ -1086,
/* 1092 */ 257,
/* 1093 */ 1097,
/* 1094 */ 50299,
/* 1095 */ -1093,
/* 1096 */ 102,
/* 1097 */ 1101,
/* 1098 */ 1124,
/* 1099 */ -1093,
/* 1100 */ 103,
/* 1101 */ 1105,
/* 1102 */ 50289,
/* 1103 */ -1093,
/* 1104 */ 104,
/* 1105 */ 0,
/* 1106 */ 50040,
/* 1107 */ 791,
/* 1108 */ 50041,
/* 1109 */ -1093,
/* 1110 */ 105,
/* 1111 */ 0,
/* 1112 */ 1116,
/* 1113 */ 804,
/* 1114 */ -1111,
/* 1115 */ 106,
/* 1116 */ 1121,
/* 1117 */ 1111,
/* 1118 */ 50044,
/* 1119 */ -1116,
/* 1120 */ 204,
/* 1121 */ 0,
/* 1122 */ -1116,
/* 1123 */ 258,
/* 1124 */ 1128,
/* 1125 */ 50308,
/* 1126 */ -1124,
/* 1127 */ 107,
/* 1128 */ 1132,
/* 1129 */ 50306,
/* 1130 */ -1124,
/* 1131 */ 108,
/* 1132 */ 1136,
/* 1133 */ 50307,
/* 1134 */ -1124,
/* 1135 */ 109,
/* 1136 */ 0,
/* 1137 */ 50299,
/* 1138 */ -1124,
/* 1139 */ 110,
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
/* 93 */ 0,
/* 94 */ 1,
/* 95 */ -93,
/* 96 */ 1,
/* 97 */ 101,
/* 98 */ 50256,
/* 99 */ -97,
/* 100 */ 1,
/* 101 */ 105,
/* 102 */ 50274,
/* 103 */ -97,
/* 104 */ 2,
/* 105 */ 109,
/* 106 */ 50279,
/* 107 */ -97,
/* 108 */ 3,
/* 109 */ 113,
/* 110 */ 50267,
/* 111 */ -97,
/* 112 */ 4,
/* 113 */ 0,
/* 114 */ 50282,
/* 115 */ -97,
/* 116 */ 5,
/* 117 */ 121,
/* 118 */ 1,
/* 119 */ -117,
/* 120 */ 1,
/* 121 */ 125,
/* 122 */ 1,
/* 123 */ -117,
/* 124 */ 2,
/* 125 */ 0,
/* 126 */ 1,
/* 127 */ -117,
/* 128 */ 3,
/* 129 */ 133,
/* 130 */ 50285,
/* 131 */ -129,
/* 132 */ 1,
/* 133 */ 137,
/* 134 */ 50259,
/* 135 */ -129,
/* 136 */ 2,
/* 137 */ 141,
/* 138 */ 50276,
/* 139 */ -129,
/* 140 */ 3,
/* 141 */ 145,
/* 142 */ 50272,
/* 143 */ -129,
/* 144 */ 4,
/* 145 */ 149,
/* 146 */ 50273,
/* 147 */ -129,
/* 148 */ 5,
/* 149 */ 153,
/* 150 */ 50268,
/* 151 */ -129,
/* 152 */ 6,
/* 153 */ 157,
/* 154 */ 50264,
/* 155 */ -129,
/* 156 */ 7,
/* 157 */ 161,
/* 158 */ 50277,
/* 159 */ -129,
/* 160 */ 8,
/* 161 */ 0,
/* 162 */ 50284,
/* 163 */ -129,
/* 164 */ 9,
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
/* 183 */ 50299,
/* 184 */ -173,
/* 185 */ 2,
/* 186 */ 190,
/* 187 */ 50299,
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
/* 305 */ 50299,
/* 306 */ -295,
/* 307 */ 2,
/* 308 */ 312,
/* 309 */ 50299,
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
/* 329 */ 50299,
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
/* 354 */ 50299,
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
/* 480 */ 50299,
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
/* 595 */ 50299,
/* 596 */ -594,
/* 597 */ 1,
/* 598 */ 602,
/* 599 */ 1,
/* 600 */ -598,
/* 601 */ 1,
/* 602 */ 606,
/* 603 */ 1,
/* 604 */ -598,
/* 605 */ 2,
/* 606 */ 610,
/* 607 */ 1,
/* 608 */ -598,
/* 609 */ 3,
/* 610 */ 614,
/* 611 */ 1,
/* 612 */ -598,
/* 613 */ 4,
/* 614 */ 618,
/* 615 */ 1,
/* 616 */ -598,
/* 617 */ 5,
/* 618 */ 0,
/* 619 */ 1,
/* 620 */ -598,
/* 621 */ 6,
/* 622 */ 628,
/* 623 */ 50299,
/* 624 */ 50058,
/* 625 */ 1,
/* 626 */ -622,
/* 627 */ 1,
/* 628 */ 635,
/* 629 */ 50258,
/* 630 */ 1,
/* 631 */ 50058,
/* 632 */ 1,
/* 633 */ -622,
/* 634 */ 2,
/* 635 */ 0,
/* 636 */ 50262,
/* 637 */ 50058,
/* 638 */ 1,
/* 639 */ -622,
/* 640 */ 3,
/* 641 */ 0,
/* 642 */ 1,
/* 643 */ 50059,
/* 644 */ -641,
/* 645 */ 1,
/* 646 */ 650,
/* 647 */ 1,
/* 648 */ -646,
/* 649 */ 1,
/* 650 */ 0,
/* 651 */ -646,
/* 652 */ 2,
/* 653 */ 0,
/* 654 */ 50123,
/* 655 */ 1,
/* 656 */ 1,
/* 657 */ 50125,
/* 658 */ -653,
/* 659 */ 1,
/* 660 */ 664,
/* 661 */ 1,
/* 662 */ -660,
/* 663 */ 1,
/* 664 */ 0,
/* 665 */ -660,
/* 666 */ 2,
/* 667 */ 671,
/* 668 */ 1,
/* 669 */ -667,
/* 670 */ 1,
/* 671 */ 0,
/* 672 */ -667,
/* 673 */ 2,
/* 674 */ 0,
/* 675 */ 1,
/* 676 */ 1,
/* 677 */ -674,
/* 678 */ 1,
/* 679 */ 683,
/* 680 */ 1,
/* 681 */ -679,
/* 682 */ 1,
/* 683 */ 0,
/* 684 */ -679,
/* 685 */ 2,
/* 686 */ 695,
/* 687 */ 50271,
/* 688 */ 50040,
/* 689 */ 1,
/* 690 */ 50041,
/* 691 */ 1,
/* 692 */ 1,
/* 693 */ -686,
/* 694 */ 1,
/* 695 */ 0,
/* 696 */ 50281,
/* 697 */ 50040,
/* 698 */ 1,
/* 699 */ 50041,
/* 700 */ 1,
/* 701 */ -686,
/* 702 */ 2,
/* 703 */ 708,
/* 704 */ 50265,
/* 705 */ 1,
/* 706 */ -703,
/* 707 */ 1,
/* 708 */ 0,
/* 709 */ -703,
/* 710 */ 2,
/* 711 */ 719,
/* 712 */ 50287,
/* 713 */ 50040,
/* 714 */ 1,
/* 715 */ 50041,
/* 716 */ 1,
/* 717 */ -711,
/* 718 */ 1,
/* 719 */ 729,
/* 720 */ 50263,
/* 721 */ 1,
/* 722 */ 50287,
/* 723 */ 50040,
/* 724 */ 1,
/* 725 */ 50041,
/* 726 */ 50059,
/* 727 */ -711,
/* 728 */ 2,
/* 729 */ 0,
/* 730 */ 50269,
/* 731 */ 50040,
/* 732 */ 1,
/* 733 */ 50059,
/* 734 */ 1,
/* 735 */ 50059,
/* 736 */ 1,
/* 737 */ 50041,
/* 738 */ 1,
/* 739 */ -711,
/* 740 */ 3,
/* 741 */ 745,
/* 742 */ 1,
/* 743 */ -741,
/* 744 */ 1,
/* 745 */ 0,
/* 746 */ -741,
/* 747 */ 2,
/* 748 */ 752,
/* 749 */ 1,
/* 750 */ -748,
/* 751 */ 1,
/* 752 */ 0,
/* 753 */ -748,
/* 754 */ 2,
/* 755 */ 759,
/* 756 */ 1,
/* 757 */ -755,
/* 758 */ 1,
/* 759 */ 0,
/* 760 */ -755,
/* 761 */ 2,
/* 762 */ 768,
/* 763 */ 50270,
/* 764 */ 50299,
/* 765 */ 50059,
/* 766 */ -762,
/* 767 */ 1,
/* 768 */ 773,
/* 769 */ 50261,
/* 770 */ 50059,
/* 771 */ -762,
/* 772 */ 2,
/* 773 */ 778,
/* 774 */ 50257,
/* 775 */ 50059,
/* 776 */ -762,
/* 777 */ 3,
/* 778 */ 0,
/* 779 */ 50275,
/* 780 */ 1,
/* 781 */ 50059,
/* 782 */ -762,
/* 783 */ 4,
/* 784 */ 788,
/* 785 */ 1,
/* 786 */ -784,
/* 787 */ 1,
/* 788 */ 0,
/* 789 */ -784,
/* 790 */ 2,
/* 791 */ 0,
/* 792 */ 1,
/* 793 */ 1,
/* 794 */ -791,
/* 795 */ 1,
/* 796 */ 801,
/* 797 */ 1,
/* 798 */ 50044,
/* 799 */ -796,
/* 800 */ 1,
/* 801 */ 0,
/* 802 */ -796,
/* 803 */ 2,
/* 804 */ 808,
/* 805 */ 1,
/* 806 */ -804,
/* 807 */ 1,
/* 808 */ 0,
/* 809 */ 1,
/* 810 */ 1,
/* 811 */ 1,
/* 812 */ -804,
/* 813 */ 2,
/* 814 */ 818,
/* 815 */ 50291,
/* 816 */ -814,
/* 817 */ 1,
/* 818 */ 0,
/* 819 */ 50061,
/* 820 */ -814,
/* 821 */ 2,
/* 822 */ 0,
/* 823 */ 1,
/* 824 */ 1,
/* 825 */ -822,
/* 826 */ 1,
/* 827 */ 834,
/* 828 */ 50063,
/* 829 */ 1,
/* 830 */ 50058,
/* 831 */ 1,
/* 832 */ -827,
/* 833 */ 1,
/* 834 */ 0,
/* 835 */ -827,
/* 836 */ 2,
/* 837 */ 0,
/* 838 */ 1,
/* 839 */ -837,
/* 840 */ 1,
/* 841 */ 0,
/* 842 */ 1,
/* 843 */ 1,
/* 844 */ -841,
/* 845 */ 1,
/* 846 */ 851,
/* 847 */ 1,
/* 848 */ 50297,
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
/* 861 */ 50298,
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
/* 874 */ 50301,
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
/* 887 */ 50303,
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
/* 900 */ 50302,
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
/* 913 */ 50292,
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
/* 926 */ 50304,
/* 927 */ -924,
/* 928 */ 1,
/* 929 */ 0,
/* 930 */ -924,
/* 931 */ 2,
/* 932 */ 0,
/* 933 */ 1,
/* 934 */ 1,
/* 935 */ -932,
/* 936 */ 1,
/* 937 */ 942,
/* 938 */ 1,
/* 939 */ 1,
/* 940 */ -937,
/* 941 */ 1,
/* 942 */ 0,
/* 943 */ -937,
/* 944 */ 2,
/* 945 */ 949,
/* 946 */ 50043,
/* 947 */ -945,
/* 948 */ 1,
/* 949 */ 0,
/* 950 */ 50045,
/* 951 */ -945,
/* 952 */ 2,
/* 953 */ 0,
/* 954 */ 1,
/* 955 */ 1,
/* 956 */ -953,
/* 957 */ 1,
/* 958 */ 963,
/* 959 */ 1,
/* 960 */ 1,
/* 961 */ -958,
/* 962 */ 1,
/* 963 */ 0,
/* 964 */ -958,
/* 965 */ 2,
/* 966 */ 970,
/* 967 */ 50042,
/* 968 */ -966,
/* 969 */ 1,
/* 970 */ 974,
/* 971 */ 50047,
/* 972 */ -966,
/* 973 */ 2,
/* 974 */ 0,
/* 975 */ 50037,
/* 976 */ -966,
/* 977 */ 3,
/* 978 */ 982,
/* 979 */ 1,
/* 980 */ -978,
/* 981 */ 1,
/* 982 */ 0,
/* 983 */ 50040,
/* 984 */ 1,
/* 985 */ 50041,
/* 986 */ 1,
/* 987 */ -978,
/* 988 */ 2,
/* 989 */ 993,
/* 990 */ 1,
/* 991 */ -989,
/* 992 */ 1,
/* 993 */ 998,
/* 994 */ 1,
/* 995 */ 1,
/* 996 */ -989,
/* 997 */ 2,
/* 998 */ 1003,
/* 999 */ 1,
/* 1000 */ 1,
/* 1001 */ -989,
/* 1002 */ 3,
/* 1003 */ 1008,
/* 1004 */ 50278,
/* 1005 */ 1,
/* 1006 */ -989,
/* 1007 */ 4,
/* 1008 */ 0,
/* 1009 */ 50278,
/* 1010 */ 50040,
/* 1011 */ 1,
/* 1012 */ 50041,
/* 1013 */ -989,
/* 1014 */ 5,
/* 1015 */ 1019,
/* 1016 */ 50294,
/* 1017 */ -1015,
/* 1018 */ 1,
/* 1019 */ 0,
/* 1020 */ 50295,
/* 1021 */ -1015,
/* 1022 */ 2,
/* 1023 */ 1027,
/* 1024 */ 50038,
/* 1025 */ -1023,
/* 1026 */ 1,
/* 1027 */ 1031,
/* 1028 */ 50042,
/* 1029 */ -1023,
/* 1030 */ 2,
/* 1031 */ 1035,
/* 1032 */ 50043,
/* 1033 */ -1023,
/* 1034 */ 3,
/* 1035 */ 1039,
/* 1036 */ 50045,
/* 1037 */ -1023,
/* 1038 */ 4,
/* 1039 */ 1043,
/* 1040 */ 50126,
/* 1041 */ -1023,
/* 1042 */ 5,
/* 1043 */ 0,
/* 1044 */ 50033,
/* 1045 */ -1023,
/* 1046 */ 6,
/* 1047 */ 1051,
/* 1048 */ 1,
/* 1049 */ -1047,
/* 1050 */ 1,
/* 1051 */ 0,
/* 1052 */ 1,
/* 1053 */ 1,
/* 1054 */ -1047,
/* 1055 */ 2,
/* 1056 */ 1062,
/* 1057 */ 50091,
/* 1058 */ 1,
/* 1059 */ 50093,
/* 1060 */ -1056,
/* 1061 */ 1,
/* 1062 */ 1068,
/* 1063 */ 50040,
/* 1064 */ 1,
/* 1065 */ 50041,
/* 1066 */ -1056,
/* 1067 */ 2,
/* 1068 */ 1073,
/* 1069 */ 50046,
/* 1070 */ 50299,
/* 1071 */ -1056,
/* 1072 */ 3,
/* 1073 */ 1078,
/* 1074 */ 50296,
/* 1075 */ 50299,
/* 1076 */ -1056,
/* 1077 */ 4,
/* 1078 */ 1082,
/* 1079 */ 50294,
/* 1080 */ -1056,
/* 1081 */ 5,
/* 1082 */ 0,
/* 1083 */ 50295,
/* 1084 */ -1056,
/* 1085 */ 6,
/* 1086 */ 1090,
/* 1087 */ 1,
/* 1088 */ -1086,
/* 1089 */ 1,
/* 1090 */ 0,
/* 1091 */ -1086,
/* 1092 */ 2,
/* 1093 */ 1097,
/* 1094 */ 50299,
/* 1095 */ -1093,
/* 1096 */ 1,
/* 1097 */ 1101,
/* 1098 */ 1,
/* 1099 */ -1093,
/* 1100 */ 2,
/* 1101 */ 1105,
/* 1102 */ 50289,
/* 1103 */ -1093,
/* 1104 */ 3,
/* 1105 */ 0,
/* 1106 */ 50040,
/* 1107 */ 1,
/* 1108 */ 50041,
/* 1109 */ -1093,
/* 1110 */ 4,
/* 1111 */ 0,
/* 1112 */ 1,
/* 1113 */ 1,
/* 1114 */ -1111,
/* 1115 */ 1,
/* 1116 */ 1121,
/* 1117 */ 1,
/* 1118 */ 50044,
/* 1119 */ -1116,
/* 1120 */ 1,
/* 1121 */ 0,
/* 1122 */ -1116,
/* 1123 */ 2,
/* 1124 */ 1128,
/* 1125 */ 50308,
/* 1126 */ -1124,
/* 1127 */ 1,
/* 1128 */ 1132,
/* 1129 */ 50306,
/* 1130 */ -1124,
/* 1131 */ 2,
/* 1132 */ 1136,
/* 1133 */ 50307,
/* 1134 */ -1124,
/* 1135 */ 3,
/* 1136 */ 0,
/* 1137 */ 50299,
/* 1138 */ -1124,
/* 1139 */ 4,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 19002,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 19002,
/* 6 */ 9999,
/* 7 */ 19004,
/* 8 */ 9999,
/* 9 */ 19023,
/* 10 */ 9999,
/* 11 */ 20004,
/* 12 */ 20021,
/* 13 */ 9999,
/* 14 */ 20019,
/* 15 */ 9999,
/* 16 */ 24004,
/* 17 */ 9999,
/* 18 */ 24022,
/* 19 */ 9999,
/* 20 */ 25004,
/* 21 */ 9999,
/* 22 */ 25014,
/* 23 */ 9999,
/* 24 */ 29004,
/* 25 */ 29032,
/* 26 */ 29043,
/* 27 */ 29065,
/* 28 */ 9999,
/* 29 */ 29004,
/* 30 */ 9999,
/* 31 */ 29006,
/* 32 */ 9999,
/* 33 */ 29027,
/* 34 */ 9999,
/* 35 */ 9999,
/* 36 */ 29027,
/* 37 */ 9999,
/* 38 */ 29045,
/* 39 */ 9999,
/* 40 */ 29060,
/* 41 */ 9999,
/* 42 */ 9999,
/* 43 */ 29060,
/* 44 */ 9999,
/* 45 */ 33004,
/* 46 */ 33027,
/* 47 */ 9999,
/* 48 */ 9999,
/* 49 */ 33025,
/* 50 */ 9999,
/* 51 */ 33029,
/* 52 */ 9999,
/* 53 */ 33048,
/* 54 */ 9999,
/* 55 */ 9999,
/* 56 */ 33048,
/* 57 */ 9999,
/* 58 */ 37004,
/* 59 */ 37026,
/* 60 */ 9999,
/* 61 */ 37004,
/* 62 */ 9999,
/* 63 */ 37006,
/* 64 */ 9999,
/* 65 */ 37021,
/* 66 */ 9999,
/* 67 */ 9999,
/* 68 */ 37021,
/* 69 */ 9999,
/* 70 */ 41004,
/* 71 */ 41066,
/* 72 */ 9999,
/* 73 */ 41004,
/* 74 */ 9999,
/* 75 */ 41006,
/* 76 */ 9999,
/* 77 */ 41028,
/* 78 */ 9999,
/* 79 */ 41032,
/* 80 */ 9999,
/* 81 */ 41045,
/* 82 */ 9999,
/* 83 */ 41049,
/* 84 */ 9999,
/* 85 */ 41062,
/* 86 */ 9999,
/* 87 */ 41068,
/* 88 */ 9999,
/* 89 */ 41089,
/* 90 */ 9999,
/* 91 */ 9999,
/* 92 */ 41089,
/* 93 */ 9999,
/* 94 */ 45004,
/* 95 */ 9999,
/* 96 */ 45004,
/* 97 */ 9999,
/* 98 */ 9999,
/* 99 */ 9999,
/* 100 */ 45009,
/* 101 */ 9999,
/* 102 */ 9999,
/* 103 */ 9999,
/* 104 */ 46011,
/* 105 */ 9999,
/* 106 */ 9999,
/* 107 */ 9999,
/* 108 */ 47009,
/* 109 */ 9999,
/* 110 */ 9999,
/* 111 */ 9999,
/* 112 */ 48009,
/* 113 */ 9999,
/* 114 */ 9999,
/* 115 */ 9999,
/* 116 */ 49010,
/* 117 */ 9999,
/* 118 */ 53004,
/* 119 */ 9999,
/* 120 */ 53004,
/* 121 */ 9999,
/* 122 */ 62004,
/* 123 */ 9999,
/* 124 */ 62028,
/* 125 */ 9999,
/* 126 */ 62032,
/* 127 */ 9999,
/* 128 */ 62045,
/* 129 */ 9999,
/* 130 */ 9999,
/* 131 */ 9999,
/* 132 */ 53009,
/* 133 */ 9999,
/* 134 */ 9999,
/* 135 */ 9999,
/* 136 */ 54007,
/* 137 */ 9999,
/* 138 */ 9999,
/* 139 */ 9999,
/* 140 */ 55008,
/* 141 */ 9999,
/* 142 */ 9999,
/* 143 */ 9999,
/* 144 */ 56006,
/* 145 */ 9999,
/* 146 */ 9999,
/* 147 */ 9999,
/* 148 */ 57007,
/* 149 */ 9999,
/* 150 */ 9999,
/* 151 */ 9999,
/* 152 */ 58008,
/* 153 */ 9999,
/* 154 */ 9999,
/* 155 */ 9999,
/* 156 */ 59009,
/* 157 */ 9999,
/* 158 */ 9999,
/* 159 */ 9999,
/* 160 */ 60009,
/* 161 */ 9999,
/* 162 */ 9999,
/* 163 */ 9999,
/* 164 */ 61011,
/* 165 */ 9999,
/* 166 */ 9999,
/* 167 */ 9999,
/* 168 */ 66008,
/* 169 */ 9999,
/* 170 */ 9999,
/* 171 */ 9999,
/* 172 */ 67011,
/* 173 */ 9999,
/* 174 */ 71004,
/* 175 */ 71020,
/* 176 */ 9999,
/* 177 */ 71067,
/* 178 */ 9999,
/* 179 */ 9999,
/* 180 */ 71018,
/* 181 */ 9999,
/* 182 */ 72004,
/* 183 */ 9999,
/* 184 */ 9999,
/* 185 */ 72018,
/* 186 */ 9999,
/* 187 */ 9999,
/* 188 */ 9999,
/* 189 */ 71031,
/* 190 */ 9999,
/* 191 */ 9999,
/* 192 */ 71031,
/* 193 */ 9999,
/* 194 */ 9999,
/* 195 */ 9999,
/* 196 */ 76009,
/* 197 */ 9999,
/* 198 */ 9999,
/* 199 */ 9999,
/* 200 */ 76017,
/* 201 */ 9999,
/* 202 */ 80004,
/* 203 */ 80033,
/* 204 */ 9999,
/* 205 */ 80004,
/* 206 */ 9999,
/* 207 */ 80006,
/* 208 */ 9999,
/* 209 */ 80028,
/* 210 */ 9999,
/* 211 */ 9999,
/* 212 */ 80028,
/* 213 */ 9999,
/* 214 */ 84004,
/* 215 */ 84034,
/* 216 */ 9999,
/* 217 */ 84004,
/* 218 */ 9999,
/* 219 */ 84006,
/* 220 */ 9999,
/* 221 */ 9999,
/* 222 */ 84025,
/* 223 */ 9999,
/* 224 */ 9999,
/* 225 */ 84025,
/* 226 */ 9999,
/* 227 */ 88004,
/* 228 */ 88024,
/* 229 */ 9999,
/* 230 */ 88004,
/* 231 */ 9999,
/* 232 */ 88006,
/* 233 */ 9999,
/* 234 */ 9999,
/* 235 */ 88015,
/* 236 */ 9999,
/* 237 */ 9999,
/* 238 */ 88015,
/* 239 */ 9999,
/* 240 */ 92004,
/* 241 */ 92029,
/* 242 */ 9999,
/* 243 */ 9999,
/* 244 */ 92027,
/* 245 */ 9999,
/* 246 */ 96004,
/* 247 */ 96040,
/* 248 */ 9999,
/* 249 */ 96004,
/* 250 */ 9999,
/* 251 */ 96006,
/* 252 */ 9999,
/* 253 */ 96019,
/* 254 */ 9999,
/* 255 */ 96023,
/* 256 */ 9999,
/* 257 */ 96036,
/* 258 */ 9999,
/* 259 */ 96042,
/* 260 */ 9999,
/* 261 */ 96065,
/* 262 */ 9999,
/* 263 */ 9999,
/* 264 */ 96065,
/* 265 */ 9999,
/* 266 */ 100004,
/* 267 */ 100036,
/* 268 */ 9999,
/* 269 */ 100004,
/* 270 */ 9999,
/* 271 */ 100006,
/* 272 */ 9999,
/* 273 */ 9999,
/* 274 */ 100027,
/* 275 */ 9999,
/* 276 */ 9999,
/* 277 */ 100027,
/* 278 */ 9999,
/* 279 */ 104004,
/* 280 */ 9999,
/* 281 */ 104013,
/* 282 */ 9999,
/* 283 */ 105004,
/* 284 */ 9999,
/* 285 */ 105024,
/* 286 */ 9999,
/* 287 */ 105004,
/* 288 */ 9999,
/* 289 */ 105006,
/* 290 */ 9999,
/* 291 */ 105015,
/* 292 */ 9999,
/* 293 */ 9999,
/* 294 */ 105015,
/* 295 */ 9999,
/* 296 */ 9999,
/* 297 */ 109009,
/* 298 */ 9999,
/* 299 */ 109056,
/* 300 */ 9999,
/* 301 */ 9999,
/* 302 */ 109007,
/* 303 */ 9999,
/* 304 */ 9999,
/* 305 */ 9999,
/* 306 */ 9999,
/* 307 */ 110007,
/* 308 */ 9999,
/* 309 */ 9999,
/* 310 */ 9999,
/* 311 */ 109020,
/* 312 */ 9999,
/* 313 */ 9999,
/* 314 */ 109020,
/* 315 */ 9999,
/* 316 */ 114004,
/* 317 */ 114029,
/* 318 */ 9999,
/* 319 */ 114004,
/* 320 */ 9999,
/* 321 */ 114006,
/* 322 */ 9999,
/* 323 */ 9999,
/* 324 */ 114020,
/* 325 */ 9999,
/* 326 */ 9999,
/* 327 */ 114020,
/* 328 */ 9999,
/* 329 */ 9999,
/* 330 */ 118015,
/* 331 */ 9999,
/* 332 */ 118013,
/* 333 */ 9999,
/* 334 */ 9999,
/* 335 */ 118021,
/* 336 */ 9999,
/* 337 */ 118017,
/* 338 */ 9999,
/* 339 */ 9999,
/* 340 */ 118017,
/* 341 */ 9999,
/* 342 */ 122004,
/* 343 */ 122017,
/* 344 */ 9999,
/* 345 */ 122004,
/* 346 */ 9999,
/* 347 */ 122006,
/* 348 */ 9999,
/* 349 */ 122012,
/* 350 */ 9999,
/* 351 */ 9999,
/* 352 */ 122012,
/* 353 */ 9999,
/* 354 */ 9999,
/* 355 */ 9999,
/* 356 */ 126013,
/* 357 */ 9999,
/* 358 */ 9999,
/* 359 */ 127008,
/* 360 */ 9999,
/* 361 */ 9999,
/* 362 */ 127004,
/* 363 */ 9999,
/* 364 */ 128004,
/* 365 */ 128022,
/* 366 */ 9999,
/* 367 */ 128020,
/* 368 */ 9999,
/* 369 */ 9999,
/* 370 */ 128028,
/* 371 */ 9999,
/* 372 */ 9999,
/* 373 */ 128024,
/* 374 */ 9999,
/* 375 */ 9999,
/* 376 */ 128063,
/* 377 */ 9999,
/* 378 */ 9999,
/* 379 */ 128059,
/* 380 */ 9999,
/* 381 */ 9999,
/* 382 */ 128093,
/* 383 */ 9999,
/* 384 */ 9999,
/* 385 */ 128089,
/* 386 */ 9999,
/* 387 */ 128030,
/* 388 */ 9999,
/* 389 */ 128048,
/* 390 */ 9999,
/* 391 */ 9999,
/* 392 */ 128048,
/* 393 */ 9999,
/* 394 */ 128095,
/* 395 */ 9999,
/* 396 */ 128109,
/* 397 */ 9999,
/* 398 */ 9999,
/* 399 */ 128109,
/* 400 */ 9999,
/* 401 */ 9999,
/* 402 */ 132008,
/* 403 */ 132033,
/* 404 */ 9999,
/* 405 */ 132004,
/* 406 */ 9999,
/* 407 */ 132010,
/* 408 */ 9999,
/* 409 */ 132028,
/* 410 */ 9999,
/* 411 */ 9999,
/* 412 */ 132028,
/* 413 */ 9999,
/* 414 */ 132035,
/* 415 */ 9999,
/* 416 */ 132041,
/* 417 */ 9999,
/* 418 */ 9999,
/* 419 */ 132041,
/* 420 */ 9999,
/* 421 */ 136004,
/* 422 */ 136029,
/* 423 */ 9999,
/* 424 */ 136004,
/* 425 */ 9999,
/* 426 */ 136006,
/* 427 */ 9999,
/* 428 */ 136024,
/* 429 */ 9999,
/* 430 */ 9999,
/* 431 */ 136024,
/* 432 */ 9999,
/* 433 */ 140004,
/* 434 */ 140019,
/* 435 */ 9999,
/* 436 */ 140017,
/* 437 */ 9999,
/* 438 */ 9999,
/* 439 */ 9999,
/* 440 */ 9999,
/* 441 */ 140021,
/* 442 */ 9999,
/* 443 */ 9999,
/* 444 */ 140021,
/* 445 */ 9999,
/* 446 */ 144004,
/* 447 */ 144028,
/* 448 */ 9999,
/* 449 */ 144004,
/* 450 */ 9999,
/* 451 */ 144006,
/* 452 */ 9999,
/* 453 */ 9999,
/* 454 */ 144019,
/* 455 */ 9999,
/* 456 */ 9999,
/* 457 */ 144019,
/* 458 */ 9999,
/* 459 */ 148004,
/* 460 */ 148027,
/* 461 */ 9999,
/* 462 */ 148025,
/* 463 */ 9999,
/* 464 */ 148029,
/* 465 */ 9999,
/* 466 */ 148038,
/* 467 */ 9999,
/* 468 */ 148042,
/* 469 */ 9999,
/* 470 */ 148042,
/* 471 */ 9999,
/* 472 */ 148044,
/* 473 */ 9999,
/* 474 */ 148062,
/* 475 */ 9999,
/* 476 */ 9999,
/* 477 */ 148062,
/* 478 */ 9999,
/* 479 */ 152004,
/* 480 */ 9999,
/* 481 */ 9999,
/* 482 */ 152004,
/* 483 */ 9999,
/* 484 */ 152006,
/* 485 */ 9999,
/* 486 */ 9999,
/* 487 */ 152020,
/* 488 */ 9999,
/* 489 */ 9999,
/* 490 */ 152020,
/* 491 */ 9999,
/* 492 */ 156004,
/* 493 */ 9999,
/* 494 */ 156024,
/* 495 */ 9999,
/* 496 */ 9999,
/* 497 */ 157035,
/* 498 */ 157052,
/* 499 */ 9999,
/* 500 */ 9999,
/* 501 */ 157004,
/* 502 */ 9999,
/* 503 */ 9999,
/* 504 */ 9999,
/* 505 */ 157054,
/* 506 */ 9999,
/* 507 */ 9999,
/* 508 */ 157054,
/* 509 */ 9999,
/* 510 */ 161004,
/* 511 */ 161030,
/* 512 */ 9999,
/* 513 */ 161004,
/* 514 */ 9999,
/* 515 */ 161006,
/* 516 */ 9999,
/* 517 */ 9999,
/* 518 */ 161021,
/* 519 */ 9999,
/* 520 */ 9999,
/* 521 */ 161021,
/* 522 */ 9999,
/* 523 */ 165004,
/* 524 */ 165029,
/* 525 */ 9999,
/* 526 */ 165027,
/* 527 */ 9999,
/* 528 */ 165031,
/* 529 */ 9999,
/* 530 */ 165049,
/* 531 */ 9999,
/* 532 */ 9999,
/* 533 */ 165049,
/* 534 */ 9999,
/* 535 */ 169004,
/* 536 */ 9999,
/* 537 */ 169010,
/* 538 */ 9999,
/* 539 */ 170004,
/* 540 */ 170017,
/* 541 */ 9999,
/* 542 */ 170004,
/* 543 */ 9999,
/* 544 */ 170006,
/* 545 */ 9999,
/* 546 */ 170012,
/* 547 */ 9999,
/* 548 */ 9999,
/* 549 */ 170012,
/* 550 */ 9999,
/* 551 */ 9999,
/* 552 */ 174008,
/* 553 */ 9999,
/* 554 */ 9999,
/* 555 */ 174004,
/* 556 */ 9999,
/* 557 */ 175004,
/* 558 */ 175036,
/* 559 */ 9999,
/* 560 */ 175004,
/* 561 */ 9999,
/* 562 */ 175006,
/* 563 */ 9999,
/* 564 */ 175031,
/* 565 */ 9999,
/* 566 */ 9999,
/* 567 */ 175031,
/* 568 */ 9999,
/* 569 */ 9999,
/* 570 */ 175042,
/* 571 */ 9999,
/* 572 */ 9999,
/* 573 */ 175038,
/* 574 */ 9999,
/* 575 */ 9999,
/* 576 */ 175077,
/* 577 */ 9999,
/* 578 */ 9999,
/* 579 */ 175073,
/* 580 */ 9999,
/* 581 */ 175044,
/* 582 */ 9999,
/* 583 */ 175062,
/* 584 */ 9999,
/* 585 */ 9999,
/* 586 */ 175062,
/* 587 */ 9999,
/* 588 */ 175079,
/* 589 */ 9999,
/* 590 */ 175097,
/* 591 */ 9999,
/* 592 */ 9999,
/* 593 */ 175097,
/* 594 */ 9999,
/* 595 */ 9999,
/* 596 */ 9999,
/* 597 */ 179013,
/* 598 */ 9999,
/* 599 */ 183004,
/* 600 */ 9999,
/* 601 */ 183020,
/* 602 */ 9999,
/* 603 */ 184004,
/* 604 */ 9999,
/* 605 */ 184023,
/* 606 */ 9999,
/* 607 */ 185004,
/* 608 */ 9999,
/* 609 */ 185021,
/* 610 */ 9999,
/* 611 */ 186004,
/* 612 */ 9999,
/* 613 */ 186022,
/* 614 */ 9999,
/* 615 */ 187004,
/* 616 */ 9999,
/* 617 */ 187022,
/* 618 */ 9999,
/* 619 */ 188004,
/* 620 */ 9999,
/* 621 */ 188017,
/* 622 */ 9999,
/* 623 */ 9999,
/* 624 */ 9999,
/* 625 */ 192019,
/* 626 */ 9999,
/* 627 */ 192013,
/* 628 */ 9999,
/* 629 */ 9999,
/* 630 */ 193009,
/* 631 */ 9999,
/* 632 */ 193033,
/* 633 */ 9999,
/* 634 */ 193007,
/* 635 */ 9999,
/* 636 */ 9999,
/* 637 */ 9999,
/* 638 */ 194016,
/* 639 */ 9999,
/* 640 */ 194010,
/* 641 */ 9999,
/* 642 */ 198004,
/* 643 */ 9999,
/* 644 */ 9999,
/* 645 */ 198004,
/* 646 */ 9999,
/* 647 */ 198006,
/* 648 */ 9999,
/* 649 */ 198015,
/* 650 */ 9999,
/* 651 */ 9999,
/* 652 */ 198015,
/* 653 */ 9999,
/* 654 */ 9999,
/* 655 */ 202035,
/* 656 */ 202057,
/* 657 */ 9999,
/* 658 */ 9999,
/* 659 */ 202004,
/* 660 */ 9999,
/* 661 */ 202037,
/* 662 */ 9999,
/* 663 */ 202052,
/* 664 */ 9999,
/* 665 */ 9999,
/* 666 */ 202052,
/* 667 */ 9999,
/* 668 */ 202059,
/* 669 */ 9999,
/* 670 */ 202072,
/* 671 */ 9999,
/* 672 */ 9999,
/* 673 */ 202072,
/* 674 */ 9999,
/* 675 */ 206004,
/* 676 */ 206024,
/* 677 */ 9999,
/* 678 */ 206004,
/* 679 */ 9999,
/* 680 */ 206006,
/* 681 */ 9999,
/* 682 */ 206019,
/* 683 */ 9999,
/* 684 */ 9999,
/* 685 */ 206019,
/* 686 */ 9999,
/* 687 */ 9999,
/* 688 */ 9999,
/* 689 */ 210011,
/* 690 */ 9999,
/* 691 */ 210026,
/* 692 */ 210036,
/* 693 */ 9999,
/* 694 */ 210005,
/* 695 */ 9999,
/* 696 */ 9999,
/* 697 */ 9999,
/* 698 */ 211015,
/* 699 */ 9999,
/* 700 */ 211030,
/* 701 */ 9999,
/* 702 */ 211009,
/* 703 */ 9999,
/* 704 */ 9999,
/* 705 */ 210043,
/* 706 */ 9999,
/* 707 */ 210041,
/* 708 */ 9999,
/* 709 */ 9999,
/* 710 */ 210041,
/* 711 */ 9999,
/* 712 */ 9999,
/* 713 */ 9999,
/* 714 */ 215014,
/* 715 */ 9999,
/* 716 */ 215029,
/* 717 */ 9999,
/* 718 */ 215008,
/* 719 */ 9999,
/* 720 */ 9999,
/* 721 */ 216007,
/* 722 */ 9999,
/* 723 */ 9999,
/* 724 */ 216027,
/* 725 */ 9999,
/* 726 */ 9999,
/* 727 */ 9999,
/* 728 */ 216005,
/* 729 */ 9999,
/* 730 */ 9999,
/* 731 */ 9999,
/* 732 */ 217012,
/* 733 */ 9999,
/* 734 */ 217032,
/* 735 */ 9999,
/* 736 */ 217052,
/* 737 */ 9999,
/* 738 */ 217072,
/* 739 */ 9999,
/* 740 */ 217006,
/* 741 */ 9999,
/* 742 */ 217014,
/* 743 */ 9999,
/* 744 */ 217023,
/* 745 */ 9999,
/* 746 */ 9999,
/* 747 */ 217023,
/* 748 */ 9999,
/* 749 */ 217034,
/* 750 */ 9999,
/* 751 */ 217043,
/* 752 */ 9999,
/* 753 */ 9999,
/* 754 */ 217043,
/* 755 */ 9999,
/* 756 */ 217054,
/* 757 */ 9999,
/* 758 */ 217063,
/* 759 */ 9999,
/* 760 */ 9999,
/* 761 */ 217063,
/* 762 */ 9999,
/* 763 */ 9999,
/* 764 */ 9999,
/* 765 */ 9999,
/* 766 */ 9999,
/* 767 */ 221007,
/* 768 */ 9999,
/* 769 */ 9999,
/* 770 */ 9999,
/* 771 */ 9999,
/* 772 */ 222011,
/* 773 */ 9999,
/* 774 */ 9999,
/* 775 */ 9999,
/* 776 */ 9999,
/* 777 */ 223008,
/* 778 */ 9999,
/* 779 */ 9999,
/* 780 */ 224011,
/* 781 */ 9999,
/* 782 */ 9999,
/* 783 */ 224009,
/* 784 */ 9999,
/* 785 */ 224013,
/* 786 */ 9999,
/* 787 */ 224022,
/* 788 */ 9999,
/* 789 */ 9999,
/* 790 */ 224022,
/* 791 */ 9999,
/* 792 */ 228004,
/* 793 */ 228024,
/* 794 */ 9999,
/* 795 */ 228004,
/* 796 */ 9999,
/* 797 */ 228006,
/* 798 */ 9999,
/* 799 */ 9999,
/* 800 */ 228015,
/* 801 */ 9999,
/* 802 */ 9999,
/* 803 */ 228015,
/* 804 */ 9999,
/* 805 */ 232004,
/* 806 */ 9999,
/* 807 */ 232025,
/* 808 */ 9999,
/* 809 */ 233004,
/* 810 */ 233021,
/* 811 */ 233041,
/* 812 */ 9999,
/* 813 */ 233019,
/* 814 */ 9999,
/* 815 */ 9999,
/* 816 */ 9999,
/* 817 */ 237009,
/* 818 */ 9999,
/* 819 */ 9999,
/* 820 */ 9999,
/* 821 */ 238004,
/* 822 */ 9999,
/* 823 */ 242004,
/* 824 */ 242026,
/* 825 */ 9999,
/* 826 */ 242024,
/* 827 */ 9999,
/* 828 */ 9999,
/* 829 */ 242032,
/* 830 */ 9999,
/* 831 */ 242047,
/* 832 */ 9999,
/* 833 */ 242028,
/* 834 */ 9999,
/* 835 */ 9999,
/* 836 */ 242028,
/* 837 */ 9999,
/* 838 */ 246004,
/* 839 */ 9999,
/* 840 */ 246025,
/* 841 */ 9999,
/* 842 */ 250004,
/* 843 */ 250042,
/* 844 */ 9999,
/* 845 */ 250004,
/* 846 */ 9999,
/* 847 */ 250006,
/* 848 */ 9999,
/* 849 */ 9999,
/* 850 */ 250026,
/* 851 */ 9999,
/* 852 */ 9999,
/* 853 */ 250026,
/* 854 */ 9999,
/* 855 */ 254004,
/* 856 */ 254044,
/* 857 */ 9999,
/* 858 */ 254004,
/* 859 */ 9999,
/* 860 */ 254006,
/* 861 */ 9999,
/* 862 */ 9999,
/* 863 */ 254027,
/* 864 */ 9999,
/* 865 */ 9999,
/* 866 */ 254027,
/* 867 */ 9999,
/* 868 */ 258004,
/* 869 */ 258040,
/* 870 */ 9999,
/* 871 */ 258004,
/* 872 */ 9999,
/* 873 */ 258006,
/* 874 */ 9999,
/* 875 */ 9999,
/* 876 */ 258028,
/* 877 */ 9999,
/* 878 */ 9999,
/* 879 */ 258028,
/* 880 */ 9999,
/* 881 */ 262004,
/* 882 */ 262041,
/* 883 */ 9999,
/* 884 */ 262004,
/* 885 */ 9999,
/* 886 */ 262006,
/* 887 */ 9999,
/* 888 */ 9999,
/* 889 */ 262028,
/* 890 */ 9999,
/* 891 */ 9999,
/* 892 */ 262028,
/* 893 */ 9999,
/* 894 */ 266004,
/* 895 */ 266031,
/* 896 */ 9999,
/* 897 */ 266004,
/* 898 */ 9999,
/* 899 */ 266005,
/* 900 */ 9999,
/* 901 */ 9999,
/* 902 */ 266018,
/* 903 */ 9999,
/* 904 */ 9999,
/* 905 */ 266018,
/* 906 */ 9999,
/* 907 */ 270004,
/* 908 */ 270037,
/* 909 */ 9999,
/* 910 */ 270004,
/* 911 */ 9999,
/* 912 */ 270006,
/* 913 */ 9999,
/* 914 */ 9999,
/* 915 */ 270024,
/* 916 */ 9999,
/* 917 */ 9999,
/* 918 */ 270024,
/* 919 */ 9999,
/* 920 */ 274004,
/* 921 */ 274031,
/* 922 */ 9999,
/* 923 */ 274004,
/* 924 */ 9999,
/* 925 */ 274005,
/* 926 */ 9999,
/* 927 */ 9999,
/* 928 */ 274020,
/* 929 */ 9999,
/* 930 */ 9999,
/* 931 */ 274020,
/* 932 */ 9999,
/* 933 */ 278004,
/* 934 */ 278043,
/* 935 */ 9999,
/* 936 */ 278004,
/* 937 */ 9999,
/* 938 */ 278006,
/* 939 */ 278026,
/* 940 */ 9999,
/* 941 */ 278024,
/* 942 */ 9999,
/* 943 */ 9999,
/* 944 */ 278024,
/* 945 */ 9999,
/* 946 */ 9999,
/* 947 */ 9999,
/* 948 */ 278028,
/* 949 */ 9999,
/* 950 */ 9999,
/* 951 */ 9999,
/* 952 */ 278034,
/* 953 */ 9999,
/* 954 */ 282004,
/* 955 */ 282055,
/* 956 */ 9999,
/* 957 */ 282004,
/* 958 */ 9999,
/* 959 */ 282006,
/* 960 */ 282032,
/* 961 */ 9999,
/* 962 */ 282030,
/* 963 */ 9999,
/* 964 */ 9999,
/* 965 */ 282030,
/* 966 */ 9999,
/* 967 */ 9999,
/* 968 */ 9999,
/* 969 */ 282034,
/* 970 */ 9999,
/* 971 */ 9999,
/* 972 */ 9999,
/* 973 */ 282040,
/* 974 */ 9999,
/* 975 */ 9999,
/* 976 */ 9999,
/* 977 */ 282046,
/* 978 */ 9999,
/* 979 */ 286004,
/* 980 */ 9999,
/* 981 */ 286019,
/* 982 */ 9999,
/* 983 */ 9999,
/* 984 */ 287008,
/* 985 */ 9999,
/* 986 */ 287022,
/* 987 */ 9999,
/* 988 */ 287004,
/* 989 */ 9999,
/* 990 */ 291004,
/* 991 */ 9999,
/* 992 */ 291021,
/* 993 */ 9999,
/* 994 */ 292004,
/* 995 */ 292024,
/* 996 */ 9999,
/* 997 */ 292004,
/* 998 */ 9999,
/* 999 */ 293004,
/* 1000 */ 293019,
/* 1001 */ 9999,
/* 1002 */ 293017,
/* 1003 */ 9999,
/* 1004 */ 9999,
/* 1005 */ 294011,
/* 1006 */ 9999,
/* 1007 */ 294009,
/* 1008 */ 9999,
/* 1009 */ 9999,
/* 1010 */ 9999,
/* 1011 */ 295015,
/* 1012 */ 9999,
/* 1013 */ 9999,
/* 1014 */ 295009,
/* 1015 */ 9999,
/* 1016 */ 9999,
/* 1017 */ 9999,
/* 1018 */ 292011,
/* 1019 */ 9999,
/* 1020 */ 9999,
/* 1021 */ 9999,
/* 1022 */ 292020,
/* 1023 */ 9999,
/* 1024 */ 9999,
/* 1025 */ 9999,
/* 1026 */ 299004,
/* 1027 */ 9999,
/* 1028 */ 9999,
/* 1029 */ 9999,
/* 1030 */ 299010,
/* 1031 */ 9999,
/* 1032 */ 9999,
/* 1033 */ 9999,
/* 1034 */ 299016,
/* 1035 */ 9999,
/* 1036 */ 9999,
/* 1037 */ 9999,
/* 1038 */ 299022,
/* 1039 */ 9999,
/* 1040 */ 9999,
/* 1041 */ 9999,
/* 1042 */ 299028,
/* 1043 */ 9999,
/* 1044 */ 9999,
/* 1045 */ 9999,
/* 1046 */ 299034,
/* 1047 */ 9999,
/* 1048 */ 303004,
/* 1049 */ 9999,
/* 1050 */ 303021,
/* 1051 */ 9999,
/* 1052 */ 304004,
/* 1053 */ 304023,
/* 1054 */ 9999,
/* 1055 */ 304021,
/* 1056 */ 9999,
/* 1057 */ 9999,
/* 1058 */ 304029,
/* 1059 */ 9999,
/* 1060 */ 9999,
/* 1061 */ 304025,
/* 1062 */ 9999,
/* 1063 */ 9999,
/* 1064 */ 304050,
/* 1065 */ 9999,
/* 1066 */ 9999,
/* 1067 */ 304046,
/* 1068 */ 9999,
/* 1069 */ 9999,
/* 1070 */ 9999,
/* 1071 */ 9999,
/* 1072 */ 304086,
/* 1073 */ 9999,
/* 1074 */ 9999,
/* 1075 */ 9999,
/* 1076 */ 9999,
/* 1077 */ 304108,
/* 1078 */ 9999,
/* 1079 */ 9999,
/* 1080 */ 9999,
/* 1081 */ 304128,
/* 1082 */ 9999,
/* 1083 */ 9999,
/* 1084 */ 9999,
/* 1085 */ 304137,
/* 1086 */ 9999,
/* 1087 */ 304052,
/* 1088 */ 9999,
/* 1089 */ 304075,
/* 1090 */ 9999,
/* 1091 */ 9999,
/* 1092 */ 304075,
/* 1093 */ 9999,
/* 1094 */ 9999,
/* 1095 */ 9999,
/* 1096 */ 308013,
/* 1097 */ 9999,
/* 1098 */ 309004,
/* 1099 */ 9999,
/* 1100 */ 309011,
/* 1101 */ 9999,
/* 1102 */ 9999,
/* 1103 */ 9999,
/* 1104 */ 310009,
/* 1105 */ 9999,
/* 1106 */ 9999,
/* 1107 */ 311008,
/* 1108 */ 9999,
/* 1109 */ 9999,
/* 1110 */ 311004,
/* 1111 */ 9999,
/* 1112 */ 315004,
/* 1113 */ 315038,
/* 1114 */ 9999,
/* 1115 */ 315004,
/* 1116 */ 9999,
/* 1117 */ 315006,
/* 1118 */ 9999,
/* 1119 */ 9999,
/* 1120 */ 315029,
/* 1121 */ 9999,
/* 1122 */ 9999,
/* 1123 */ 315029,
/* 1124 */ 9999,
/* 1125 */ 9999,
/* 1126 */ 9999,
/* 1127 */ 319011,
/* 1128 */ 9999,
/* 1129 */ 9999,
/* 1130 */ 9999,
/* 1131 */ 320012,
/* 1132 */ 9999,
/* 1133 */ 9999,
/* 1134 */ 9999,
/* 1135 */ 321013,
/* 1136 */ 9999,
/* 1137 */ 9999,
/* 1138 */ 9999,
/* 1139 */ 322013,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[1141];
*/
int TABLE[259][309];
init_dirsets() {
TABLE[111][0] = 1;
TABLE[111][123] = 1;
TABLE[111][299] = 1;
TABLE[111][40] = 1;
TABLE[111][286] = 1;
TABLE[111][260] = 1;
TABLE[111][42] = 1;
TABLE[111][256] = 1;
TABLE[111][274] = 1;
TABLE[111][279] = 1;
TABLE[111][267] = 1;
TABLE[111][282] = 1;
TABLE[111][266] = 1;
TABLE[111][285] = 1;
TABLE[111][259] = 1;
TABLE[111][276] = 1;
TABLE[111][272] = 1;
TABLE[111][273] = 1;
TABLE[111][268] = 1;
TABLE[111][264] = 1;
TABLE[111][277] = 1;
TABLE[111][284] = 1;
TABLE[111][283] = 1;
TABLE[111][280] = 1;
TABLE[1][0] = 1;
TABLE[1][123] = 1;
TABLE[1][40] = 1;
TABLE[1][299] = 1;
TABLE[1][42] = 1;
TABLE[1][260] = 1;
TABLE[1][286] = 1;
TABLE[1][284] = 1;
TABLE[1][277] = 1;
TABLE[1][264] = 1;
TABLE[1][268] = 1;
TABLE[1][273] = 1;
TABLE[1][272] = 1;
TABLE[1][276] = 1;
TABLE[1][259] = 1;
TABLE[1][285] = 1;
TABLE[1][266] = 1;
TABLE[1][282] = 1;
TABLE[1][267] = 1;
TABLE[1][279] = 1;
TABLE[1][274] = 1;
TABLE[1][256] = 1;
TABLE[1][280] = 1;
TABLE[1][283] = 1;
TABLE[2][0] = 1;
TABLE[2][123] = 1;
TABLE[2][299] = 1;
TABLE[2][40] = 1;
TABLE[2][286] = 1;
TABLE[2][260] = 1;
TABLE[2][42] = 1;
TABLE[2][256] = 1;
TABLE[2][274] = 1;
TABLE[2][279] = 1;
TABLE[2][267] = 1;
TABLE[2][282] = 1;
TABLE[2][266] = 1;
TABLE[2][285] = 1;
TABLE[2][259] = 1;
TABLE[2][276] = 1;
TABLE[2][272] = 1;
TABLE[2][273] = 1;
TABLE[2][268] = 1;
TABLE[2][264] = 1;
TABLE[2][277] = 1;
TABLE[2][284] = 1;
TABLE[2][283] = 1;
TABLE[2][280] = 1;
TABLE[3][0] = 1;
TABLE[3][123] = 1;
TABLE[3][299] = 1;
TABLE[3][40] = 1;
TABLE[3][42] = 1;
TABLE[3][260] = 1;
TABLE[3][286] = 1;
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
TABLE[3][282] = 1;
TABLE[3][267] = 1;
TABLE[3][279] = 1;
TABLE[3][274] = 1;
TABLE[3][256] = 1;
TABLE[3][280] = 1;
TABLE[3][283] = 1;
TABLE[4][286] = 1;
TABLE[4][260] = 1;
TABLE[4][256] = 1;
TABLE[4][274] = 1;
TABLE[4][279] = 1;
TABLE[4][267] = 1;
TABLE[4][282] = 1;
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
TABLE[4][283] = 1;
TABLE[4][280] = 1;
TABLE[5][123] = 1;
TABLE[5][40] = 1;
TABLE[5][299] = 1;
TABLE[5][42] = 1;
TABLE[5][286] = 1;
TABLE[5][260] = 1;
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
TABLE[5][283] = 1;
TABLE[5][280] = 1;
TABLE[112][260] = 1;
TABLE[112][286] = 1;
TABLE[112][284] = 1;
TABLE[112][277] = 1;
TABLE[112][264] = 1;
TABLE[112][268] = 1;
TABLE[112][273] = 1;
TABLE[112][272] = 1;
TABLE[112][276] = 1;
TABLE[112][259] = 1;
TABLE[112][285] = 1;
TABLE[112][266] = 1;
TABLE[112][282] = 1;
TABLE[112][267] = 1;
TABLE[112][279] = 1;
TABLE[112][274] = 1;
TABLE[112][256] = 1;
TABLE[112][280] = 1;
TABLE[112][283] = 1;
TABLE[205][40] = 1;
TABLE[205][299] = 1;
TABLE[205][42] = 1;
TABLE[205][286] = 1;
TABLE[205][260] = 1;
TABLE[205][256] = 1;
TABLE[205][274] = 1;
TABLE[205][279] = 1;
TABLE[205][267] = 1;
TABLE[205][282] = 1;
TABLE[205][266] = 1;
TABLE[205][285] = 1;
TABLE[205][259] = 1;
TABLE[205][276] = 1;
TABLE[205][272] = 1;
TABLE[205][273] = 1;
TABLE[205][268] = 1;
TABLE[205][264] = 1;
TABLE[205][277] = 1;
TABLE[205][284] = 1;
TABLE[205][283] = 1;
TABLE[205][280] = 1;
TABLE[205][123] = 1;
TABLE[113][123] = 1;
TABLE[113][260] = 1;
TABLE[113][286] = 1;
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
TABLE[113][282] = 1;
TABLE[113][267] = 1;
TABLE[113][279] = 1;
TABLE[113][274] = 1;
TABLE[113][256] = 1;
TABLE[113][280] = 1;
TABLE[113][283] = 1;
TABLE[206][123] = 1;
TABLE[6][260] = 1;
TABLE[6][286] = 1;
TABLE[6][284] = 1;
TABLE[6][277] = 1;
TABLE[6][264] = 1;
TABLE[6][268] = 1;
TABLE[6][273] = 1;
TABLE[6][272] = 1;
TABLE[6][276] = 1;
TABLE[6][259] = 1;
TABLE[6][285] = 1;
TABLE[6][266] = 1;
TABLE[6][282] = 1;
TABLE[6][267] = 1;
TABLE[6][279] = 1;
TABLE[6][274] = 1;
TABLE[6][256] = 1;
TABLE[6][280] = 1;
TABLE[6][283] = 1;
TABLE[114][59] = 1;
TABLE[114][44] = 1;
TABLE[114][123] = 1;
TABLE[114][61] = 1;
TABLE[114][278] = 1;
TABLE[114][299] = 1;
TABLE[114][40] = 1;
TABLE[114][295] = 1;
TABLE[114][294] = 1;
TABLE[114][33] = 1;
TABLE[114][126] = 1;
TABLE[114][45] = 1;
TABLE[114][43] = 1;
TABLE[114][38] = 1;
TABLE[114][63] = 1;
TABLE[114][42] = 1;
TABLE[114][289] = 1;
TABLE[114][297] = 1;
TABLE[114][307] = 1;
TABLE[114][306] = 1;
TABLE[114][308] = 1;
TABLE[114][298] = 1;
TABLE[114][301] = 1;
TABLE[114][303] = 1;
TABLE[114][302] = 1;
TABLE[114][292] = 1;
TABLE[114][304] = 1;
TABLE[114][37] = 1;
TABLE[114][47] = 1;
TABLE[207][59] = 1;
TABLE[7][286] = 1;
TABLE[7][260] = 1;
TABLE[7][256] = 1;
TABLE[7][274] = 1;
TABLE[7][279] = 1;
TABLE[7][267] = 1;
TABLE[7][282] = 1;
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
TABLE[7][283] = 1;
TABLE[7][280] = 1;
TABLE[115][260] = 1;
TABLE[115][286] = 1;
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
TABLE[115][280] = 1;
TABLE[115][283] = 1;
TABLE[208][286] = 1;
TABLE[208][260] = 1;
TABLE[208][256] = 1;
TABLE[208][274] = 1;
TABLE[208][279] = 1;
TABLE[208][267] = 1;
TABLE[208][282] = 1;
TABLE[208][266] = 1;
TABLE[208][285] = 1;
TABLE[208][259] = 1;
TABLE[208][276] = 1;
TABLE[208][272] = 1;
TABLE[208][273] = 1;
TABLE[208][268] = 1;
TABLE[208][264] = 1;
TABLE[208][277] = 1;
TABLE[208][284] = 1;
TABLE[208][283] = 1;
TABLE[208][280] = 1;
TABLE[8][286] = 1;
TABLE[8][260] = 1;
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
TABLE[8][283] = 1;
TABLE[8][280] = 1;
TABLE[116][282] = 1;
TABLE[116][267] = 1;
TABLE[116][279] = 1;
TABLE[116][274] = 1;
TABLE[116][256] = 1;
TABLE[117][284] = 1;
TABLE[117][277] = 1;
TABLE[117][264] = 1;
TABLE[117][268] = 1;
TABLE[117][273] = 1;
TABLE[117][272] = 1;
TABLE[117][276] = 1;
TABLE[117][259] = 1;
TABLE[117][285] = 1;
TABLE[117][266] = 1;
TABLE[117][280] = 1;
TABLE[117][283] = 1;
TABLE[118][260] = 1;
TABLE[118][286] = 1;
TABLE[119][260] = 1;
TABLE[119][286] = 1;
TABLE[119][284] = 1;
TABLE[119][277] = 1;
TABLE[119][264] = 1;
TABLE[119][268] = 1;
TABLE[119][273] = 1;
TABLE[119][272] = 1;
TABLE[119][276] = 1;
TABLE[119][259] = 1;
TABLE[119][285] = 1;
TABLE[119][266] = 1;
TABLE[119][282] = 1;
TABLE[119][267] = 1;
TABLE[119][279] = 1;
TABLE[119][274] = 1;
TABLE[119][256] = 1;
TABLE[119][280] = 1;
TABLE[119][283] = 1;
TABLE[209][40] = 1;
TABLE[209][299] = 1;
TABLE[209][42] = 1;
TABLE[209][286] = 1;
TABLE[209][260] = 1;
TABLE[209][256] = 1;
TABLE[209][274] = 1;
TABLE[209][279] = 1;
TABLE[209][267] = 1;
TABLE[209][282] = 1;
TABLE[209][266] = 1;
TABLE[209][285] = 1;
TABLE[209][259] = 1;
TABLE[209][276] = 1;
TABLE[209][272] = 1;
TABLE[209][273] = 1;
TABLE[209][268] = 1;
TABLE[209][264] = 1;
TABLE[209][277] = 1;
TABLE[209][284] = 1;
TABLE[209][283] = 1;
TABLE[209][280] = 1;
TABLE[209][123] = 1;
TABLE[209][44] = 1;
TABLE[209][61] = 1;
TABLE[209][278] = 1;
TABLE[209][63] = 1;
TABLE[209][38] = 1;
TABLE[209][43] = 1;
TABLE[209][45] = 1;
TABLE[209][126] = 1;
TABLE[209][33] = 1;
TABLE[209][294] = 1;
TABLE[209][295] = 1;
TABLE[209][297] = 1;
TABLE[209][289] = 1;
TABLE[209][298] = 1;
TABLE[209][308] = 1;
TABLE[209][306] = 1;
TABLE[209][307] = 1;
TABLE[209][301] = 1;
TABLE[209][303] = 1;
TABLE[209][302] = 1;
TABLE[209][292] = 1;
TABLE[209][304] = 1;
TABLE[209][47] = 1;
TABLE[209][37] = 1;
TABLE[209][59] = 1;
TABLE[209][91] = 1;
TABLE[209][41] = 1;
TABLE[9][256] = 1;
TABLE[9][274] = 1;
TABLE[9][279] = 1;
TABLE[9][267] = 1;
TABLE[9][282] = 1;
TABLE[120][256] = 1;
TABLE[121][274] = 1;
TABLE[122][279] = 1;
TABLE[123][267] = 1;
TABLE[124][282] = 1;
TABLE[10][285] = 1;
TABLE[10][259] = 1;
TABLE[10][276] = 1;
TABLE[10][272] = 1;
TABLE[10][273] = 1;
TABLE[10][268] = 1;
TABLE[10][264] = 1;
TABLE[10][277] = 1;
TABLE[10][284] = 1;
TABLE[11][283] = 1;
TABLE[11][280] = 1;
TABLE[12][266] = 1;
TABLE[125][285] = 1;
TABLE[126][259] = 1;
TABLE[127][276] = 1;
TABLE[128][272] = 1;
TABLE[129][273] = 1;
TABLE[130][268] = 1;
TABLE[131][264] = 1;
TABLE[132][277] = 1;
TABLE[133][284] = 1;
TABLE[13][260] = 1;
TABLE[14][286] = 1;
TABLE[15][280] = 1;
TABLE[15][283] = 1;
TABLE[16][280] = 1;
TABLE[16][283] = 1;
TABLE[134][299] = 1;
TABLE[210][123] = 1;
TABLE[17][280] = 1;
TABLE[18][283] = 1;
TABLE[19][286] = 1;
TABLE[19][260] = 1;
TABLE[19][266] = 1;
TABLE[19][285] = 1;
TABLE[19][259] = 1;
TABLE[19][276] = 1;
TABLE[19][272] = 1;
TABLE[19][273] = 1;
TABLE[19][268] = 1;
TABLE[19][264] = 1;
TABLE[19][277] = 1;
TABLE[19][284] = 1;
TABLE[19][283] = 1;
TABLE[19][280] = 1;
TABLE[135][260] = 1;
TABLE[135][286] = 1;
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
TABLE[135][280] = 1;
TABLE[135][283] = 1;
TABLE[211][286] = 1;
TABLE[211][260] = 1;
TABLE[211][266] = 1;
TABLE[211][285] = 1;
TABLE[211][259] = 1;
TABLE[211][276] = 1;
TABLE[211][272] = 1;
TABLE[211][273] = 1;
TABLE[211][268] = 1;
TABLE[211][264] = 1;
TABLE[211][277] = 1;
TABLE[211][284] = 1;
TABLE[211][283] = 1;
TABLE[211][280] = 1;
TABLE[20][59] = 1;
TABLE[20][44] = 1;
TABLE[20][61] = 1;
TABLE[20][123] = 1;
TABLE[20][40] = 1;
TABLE[20][299] = 1;
TABLE[20][278] = 1;
TABLE[20][42] = 1;
TABLE[20][63] = 1;
TABLE[20][38] = 1;
TABLE[20][43] = 1;
TABLE[20][45] = 1;
TABLE[20][126] = 1;
TABLE[20][33] = 1;
TABLE[20][294] = 1;
TABLE[20][295] = 1;
TABLE[20][297] = 1;
TABLE[20][289] = 1;
TABLE[20][298] = 1;
TABLE[20][308] = 1;
TABLE[20][306] = 1;
TABLE[20][307] = 1;
TABLE[20][301] = 1;
TABLE[20][303] = 1;
TABLE[20][302] = 1;
TABLE[20][292] = 1;
TABLE[20][304] = 1;
TABLE[20][47] = 1;
TABLE[20][37] = 1;
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
TABLE[212][61] = 1;
TABLE[212][123] = 1;
TABLE[212][40] = 1;
TABLE[212][299] = 1;
TABLE[212][278] = 1;
TABLE[212][42] = 1;
TABLE[212][63] = 1;
TABLE[212][38] = 1;
TABLE[212][43] = 1;
TABLE[212][45] = 1;
TABLE[212][126] = 1;
TABLE[212][33] = 1;
TABLE[212][294] = 1;
TABLE[212][295] = 1;
TABLE[212][297] = 1;
TABLE[212][289] = 1;
TABLE[212][298] = 1;
TABLE[212][308] = 1;
TABLE[212][306] = 1;
TABLE[212][307] = 1;
TABLE[212][301] = 1;
TABLE[212][303] = 1;
TABLE[212][302] = 1;
TABLE[212][292] = 1;
TABLE[212][304] = 1;
TABLE[212][47] = 1;
TABLE[212][37] = 1;
TABLE[212][59] = 1;
TABLE[212][44] = 1;
TABLE[21][59] = 1;
TABLE[21][44] = 1;
TABLE[21][123] = 1;
TABLE[21][278] = 1;
TABLE[21][295] = 1;
TABLE[21][294] = 1;
TABLE[21][33] = 1;
TABLE[21][126] = 1;
TABLE[21][45] = 1;
TABLE[21][43] = 1;
TABLE[21][38] = 1;
TABLE[21][63] = 1;
TABLE[21][289] = 1;
TABLE[21][297] = 1;
TABLE[21][307] = 1;
TABLE[21][306] = 1;
TABLE[21][308] = 1;
TABLE[21][298] = 1;
TABLE[21][301] = 1;
TABLE[21][303] = 1;
TABLE[21][302] = 1;
TABLE[21][292] = 1;
TABLE[21][304] = 1;
TABLE[21][37] = 1;
TABLE[21][47] = 1;
TABLE[21][61] = 1;
TABLE[21][299] = 1;
TABLE[21][40] = 1;
TABLE[21][42] = 1;
TABLE[137][61] = 1;
TABLE[137][40] = 1;
TABLE[137][299] = 1;
TABLE[137][42] = 1;
TABLE[213][123] = 1;
TABLE[213][278] = 1;
TABLE[213][295] = 1;
TABLE[213][294] = 1;
TABLE[213][33] = 1;
TABLE[213][126] = 1;
TABLE[213][45] = 1;
TABLE[213][43] = 1;
TABLE[213][42] = 1;
TABLE[213][38] = 1;
TABLE[213][63] = 1;
TABLE[213][299] = 1;
TABLE[213][289] = 1;
TABLE[213][40] = 1;
TABLE[213][297] = 1;
TABLE[213][307] = 1;
TABLE[213][306] = 1;
TABLE[213][308] = 1;
TABLE[213][298] = 1;
TABLE[213][301] = 1;
TABLE[213][303] = 1;
TABLE[213][302] = 1;
TABLE[213][292] = 1;
TABLE[213][304] = 1;
TABLE[213][37] = 1;
TABLE[213][47] = 1;
TABLE[213][59] = 1;
TABLE[213][44] = 1;
TABLE[22][260] = 1;
TABLE[22][286] = 1;
TABLE[22][284] = 1;
TABLE[22][277] = 1;
TABLE[22][264] = 1;
TABLE[22][268] = 1;
TABLE[22][273] = 1;
TABLE[22][272] = 1;
TABLE[22][276] = 1;
TABLE[22][259] = 1;
TABLE[22][285] = 1;
TABLE[22][266] = 1;
TABLE[22][280] = 1;
TABLE[22][283] = 1;
TABLE[23][286] = 1;
TABLE[23][260] = 1;
TABLE[23][266] = 1;
TABLE[23][285] = 1;
TABLE[23][259] = 1;
TABLE[23][276] = 1;
TABLE[23][272] = 1;
TABLE[23][273] = 1;
TABLE[23][268] = 1;
TABLE[23][264] = 1;
TABLE[23][277] = 1;
TABLE[23][284] = 1;
TABLE[23][283] = 1;
TABLE[23][280] = 1;
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
TABLE[138][280] = 1;
TABLE[138][283] = 1;
TABLE[139][260] = 1;
TABLE[139][286] = 1;
TABLE[140][260] = 1;
TABLE[140][286] = 1;
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
TABLE[140][280] = 1;
TABLE[140][283] = 1;
TABLE[214][44] = 1;
TABLE[214][58] = 1;
TABLE[214][40] = 1;
TABLE[214][299] = 1;
TABLE[214][42] = 1;
TABLE[214][59] = 1;
TABLE[214][91] = 1;
TABLE[214][41] = 1;
TABLE[24][59] = 1;
TABLE[24][44] = 1;
TABLE[24][58] = 1;
TABLE[24][299] = 1;
TABLE[24][40] = 1;
TABLE[24][42] = 1;
TABLE[141][44] = 1;
TABLE[141][58] = 1;
TABLE[141][40] = 1;
TABLE[141][299] = 1;
TABLE[141][42] = 1;
TABLE[215][58] = 1;
TABLE[215][299] = 1;
TABLE[215][40] = 1;
TABLE[215][42] = 1;
TABLE[215][59] = 1;
TABLE[215][44] = 1;
TABLE[25][59] = 1;
TABLE[25][44] = 1;
TABLE[25][40] = 1;
TABLE[25][299] = 1;
TABLE[25][42] = 1;
TABLE[26][58] = 1;
TABLE[26][299] = 1;
TABLE[26][40] = 1;
TABLE[26][42] = 1;
TABLE[142][58] = 1;
TABLE[142][40] = 1;
TABLE[142][299] = 1;
TABLE[142][42] = 1;
TABLE[216][58] = 1;
TABLE[27][266] = 1;
TABLE[28][266] = 1;
TABLE[143][299] = 1;
TABLE[217][123] = 1;
TABLE[29][44] = 1;
TABLE[29][299] = 1;
TABLE[144][44] = 1;
TABLE[144][299] = 1;
TABLE[218][299] = 1;
TABLE[30][299] = 1;
TABLE[145][61] = 1;
TABLE[219][125] = 1;
TABLE[219][44] = 1;
TABLE[31][299] = 1;
TABLE[31][40] = 1;
TABLE[31][42] = 1;
TABLE[146][42] = 1;
TABLE[220][299] = 1;
TABLE[220][40] = 1;
TABLE[32][299] = 1;
TABLE[33][40] = 1;
TABLE[34][299] = 1;
TABLE[34][40] = 1;
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
TABLE[147][33] = 1;
TABLE[147][126] = 1;
TABLE[147][38] = 1;
TABLE[147][299] = 1;
TABLE[147][289] = 1;
TABLE[147][307] = 1;
TABLE[147][306] = 1;
TABLE[147][308] = 1;
TABLE[221][93] = 1;
TABLE[150][41] = 1;
TABLE[150][299] = 1;
TABLE[150][44] = 1;
TABLE[222][41] = 1;
TABLE[35][42] = 1;
TABLE[152][42] = 1;
TABLE[152][299] = 1;
TABLE[152][40] = 1;
TABLE[152][44] = 1;
TABLE[152][41] = 1;
TABLE[152][91] = 1;
TABLE[152][286] = 1;
TABLE[152][260] = 1;
TABLE[223][42] = 1;
TABLE[223][299] = 1;
TABLE[223][40] = 1;
TABLE[223][44] = 1;
TABLE[223][41] = 1;
TABLE[223][91] = 1;
TABLE[153][42] = 1;
TABLE[224][299] = 1;
TABLE[224][40] = 1;
TABLE[224][44] = 1;
TABLE[224][41] = 1;
TABLE[224][91] = 1;
TABLE[36][260] = 1;
TABLE[36][286] = 1;
TABLE[154][286] = 1;
TABLE[154][260] = 1;
TABLE[225][260] = 1;
TABLE[225][286] = 1;
TABLE[37][41] = 1;
TABLE[37][44] = 1;
TABLE[37][260] = 1;
TABLE[37][286] = 1;
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
TABLE[37][282] = 1;
TABLE[37][267] = 1;
TABLE[37][279] = 1;
TABLE[37][274] = 1;
TABLE[37][256] = 1;
TABLE[37][280] = 1;
TABLE[37][283] = 1;
TABLE[155][44] = 1;
TABLE[226][41] = 1;
TABLE[38][44] = 1;
TABLE[38][286] = 1;
TABLE[38][260] = 1;
TABLE[38][256] = 1;
TABLE[38][274] = 1;
TABLE[38][279] = 1;
TABLE[38][267] = 1;
TABLE[38][282] = 1;
TABLE[38][266] = 1;
TABLE[38][285] = 1;
TABLE[38][259] = 1;
TABLE[38][276] = 1;
TABLE[38][272] = 1;
TABLE[38][273] = 1;
TABLE[38][268] = 1;
TABLE[38][264] = 1;
TABLE[38][277] = 1;
TABLE[38][284] = 1;
TABLE[38][283] = 1;
TABLE[38][280] = 1;
TABLE[156][44] = 1;
TABLE[156][260] = 1;
TABLE[156][286] = 1;
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
TABLE[156][280] = 1;
TABLE[156][283] = 1;
TABLE[227][286] = 1;
TABLE[227][260] = 1;
TABLE[227][256] = 1;
TABLE[227][274] = 1;
TABLE[227][279] = 1;
TABLE[227][267] = 1;
TABLE[227][282] = 1;
TABLE[227][266] = 1;
TABLE[227][285] = 1;
TABLE[227][259] = 1;
TABLE[227][276] = 1;
TABLE[227][272] = 1;
TABLE[227][273] = 1;
TABLE[227][268] = 1;
TABLE[227][264] = 1;
TABLE[227][277] = 1;
TABLE[227][284] = 1;
TABLE[227][283] = 1;
TABLE[227][280] = 1;
TABLE[39][260] = 1;
TABLE[39][286] = 1;
TABLE[39][284] = 1;
TABLE[39][277] = 1;
TABLE[39][264] = 1;
TABLE[39][268] = 1;
TABLE[39][273] = 1;
TABLE[39][272] = 1;
TABLE[39][276] = 1;
TABLE[39][259] = 1;
TABLE[39][285] = 1;
TABLE[39][266] = 1;
TABLE[39][282] = 1;
TABLE[39][267] = 1;
TABLE[39][279] = 1;
TABLE[39][274] = 1;
TABLE[39][256] = 1;
TABLE[39][280] = 1;
TABLE[39][283] = 1;
TABLE[157][44] = 1;
TABLE[157][41] = 1;
TABLE[157][40] = 1;
TABLE[157][299] = 1;
TABLE[157][42] = 1;
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
TABLE[228][44] = 1;
TABLE[228][41] = 1;
TABLE[40][299] = 1;
TABLE[40][44] = 1;
TABLE[160][299] = 1;
TABLE[160][44] = 1;
TABLE[229][299] = 1;
TABLE[41][59] = 1;
TABLE[41][44] = 1;
TABLE[41][125] = 1;
TABLE[41][278] = 1;
TABLE[41][63] = 1;
TABLE[41][38] = 1;
TABLE[41][42] = 1;
TABLE[41][43] = 1;
TABLE[41][45] = 1;
TABLE[41][126] = 1;
TABLE[41][33] = 1;
TABLE[41][294] = 1;
TABLE[41][295] = 1;
TABLE[41][297] = 1;
TABLE[41][40] = 1;
TABLE[41][289] = 1;
TABLE[41][299] = 1;
TABLE[41][298] = 1;
TABLE[41][308] = 1;
TABLE[41][306] = 1;
TABLE[41][307] = 1;
TABLE[41][301] = 1;
TABLE[41][303] = 1;
TABLE[41][302] = 1;
TABLE[41][292] = 1;
TABLE[41][304] = 1;
TABLE[41][47] = 1;
TABLE[41][37] = 1;
TABLE[42][123] = 1;
TABLE[161][44] = 1;
TABLE[230][125] = 1;
TABLE[43][125] = 1;
TABLE[43][123] = 1;
TABLE[43][44] = 1;
TABLE[43][278] = 1;
TABLE[43][295] = 1;
TABLE[43][294] = 1;
TABLE[43][33] = 1;
TABLE[43][126] = 1;
TABLE[43][45] = 1;
TABLE[43][43] = 1;
TABLE[43][42] = 1;
TABLE[43][38] = 1;
TABLE[43][63] = 1;
TABLE[43][299] = 1;
TABLE[43][289] = 1;
TABLE[43][40] = 1;
TABLE[43][297] = 1;
TABLE[43][307] = 1;
TABLE[43][306] = 1;
TABLE[43][308] = 1;
TABLE[43][298] = 1;
TABLE[43][301] = 1;
TABLE[43][303] = 1;
TABLE[43][302] = 1;
TABLE[43][292] = 1;
TABLE[43][304] = 1;
TABLE[43][37] = 1;
TABLE[43][47] = 1;
TABLE[162][123] = 1;
TABLE[162][44] = 1;
TABLE[162][278] = 1;
TABLE[162][63] = 1;
TABLE[162][38] = 1;
TABLE[162][42] = 1;
TABLE[162][43] = 1;
TABLE[162][45] = 1;
TABLE[162][126] = 1;
TABLE[162][33] = 1;
TABLE[162][294] = 1;
TABLE[162][295] = 1;
TABLE[162][297] = 1;
TABLE[162][40] = 1;
TABLE[162][289] = 1;
TABLE[162][299] = 1;
TABLE[162][298] = 1;
TABLE[162][308] = 1;
TABLE[162][306] = 1;
TABLE[162][307] = 1;
TABLE[162][301] = 1;
TABLE[162][303] = 1;
TABLE[162][302] = 1;
TABLE[162][292] = 1;
TABLE[162][304] = 1;
TABLE[162][47] = 1;
TABLE[162][37] = 1;
TABLE[231][123] = 1;
TABLE[231][278] = 1;
TABLE[231][295] = 1;
TABLE[231][294] = 1;
TABLE[231][33] = 1;
TABLE[231][126] = 1;
TABLE[231][45] = 1;
TABLE[231][43] = 1;
TABLE[231][42] = 1;
TABLE[231][38] = 1;
TABLE[231][63] = 1;
TABLE[231][299] = 1;
TABLE[231][289] = 1;
TABLE[231][40] = 1;
TABLE[231][297] = 1;
TABLE[231][307] = 1;
TABLE[231][306] = 1;
TABLE[231][308] = 1;
TABLE[231][298] = 1;
TABLE[231][301] = 1;
TABLE[231][303] = 1;
TABLE[231][302] = 1;
TABLE[231][292] = 1;
TABLE[231][304] = 1;
TABLE[231][37] = 1;
TABLE[231][47] = 1;
TABLE[231][44] = 1;
TABLE[231][125] = 1;
TABLE[44][260] = 1;
TABLE[44][286] = 1;
TABLE[44][284] = 1;
TABLE[44][277] = 1;
TABLE[44][264] = 1;
TABLE[44][268] = 1;
TABLE[44][273] = 1;
TABLE[44][272] = 1;
TABLE[44][276] = 1;
TABLE[44][259] = 1;
TABLE[44][285] = 1;
TABLE[44][266] = 1;
TABLE[44][280] = 1;
TABLE[44][283] = 1;
TABLE[163][41] = 1;
TABLE[163][42] = 1;
TABLE[163][40] = 1;
TABLE[163][91] = 1;
TABLE[232][41] = 1;
TABLE[45][42] = 1;
TABLE[46][44] = 1;
TABLE[46][41] = 1;
TABLE[46][40] = 1;
TABLE[46][91] = 1;
TABLE[46][42] = 1;
TABLE[164][42] = 1;
TABLE[233][40] = 1;
TABLE[233][91] = 1;
TABLE[233][44] = 1;
TABLE[233][41] = 1;
TABLE[47][40] = 1;
TABLE[48][40] = 1;
TABLE[48][91] = 1;
TABLE[165][40] = 1;
TABLE[165][91] = 1;
TABLE[234][91] = 1;
TABLE[234][40] = 1;
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
TABLE[166][33] = 1;
TABLE[166][126] = 1;
TABLE[166][38] = 1;
TABLE[166][299] = 1;
TABLE[166][289] = 1;
TABLE[166][307] = 1;
TABLE[166][306] = 1;
TABLE[166][308] = 1;
TABLE[235][93] = 1;
TABLE[168][41] = 1;
TABLE[168][44] = 1;
TABLE[168][286] = 1;
TABLE[168][260] = 1;
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
TABLE[168][283] = 1;
TABLE[168][280] = 1;
TABLE[236][41] = 1;
TABLE[49][299] = 1;
TABLE[50][299] = 1;
TABLE[50][258] = 1;
TABLE[50][262] = 1;
TABLE[51][125] = 1;
TABLE[51][265] = 1;
TABLE[51][287] = 1;
TABLE[51][262] = 1;
TABLE[51][258] = 1;
TABLE[51][123] = 1;
TABLE[51][281] = 1;
TABLE[51][271] = 1;
TABLE[51][269] = 1;
TABLE[51][263] = 1;
TABLE[51][275] = 1;
TABLE[51][257] = 1;
TABLE[51][261] = 1;
TABLE[51][270] = 1;
TABLE[51][59] = 1;
TABLE[51][44] = 1;
TABLE[51][278] = 1;
TABLE[51][295] = 1;
TABLE[51][294] = 1;
TABLE[51][33] = 1;
TABLE[51][126] = 1;
TABLE[51][45] = 1;
TABLE[51][43] = 1;
TABLE[51][42] = 1;
TABLE[51][38] = 1;
TABLE[51][63] = 1;
TABLE[51][299] = 1;
TABLE[51][289] = 1;
TABLE[51][40] = 1;
TABLE[51][297] = 1;
TABLE[51][307] = 1;
TABLE[51][306] = 1;
TABLE[51][308] = 1;
TABLE[51][298] = 1;
TABLE[51][301] = 1;
TABLE[51][303] = 1;
TABLE[51][302] = 1;
TABLE[51][292] = 1;
TABLE[51][304] = 1;
TABLE[51][37] = 1;
TABLE[51][47] = 1;
TABLE[52][123] = 1;
TABLE[53][271] = 1;
TABLE[53][281] = 1;
TABLE[54][287] = 1;
TABLE[54][263] = 1;
TABLE[54][269] = 1;
TABLE[55][270] = 1;
TABLE[55][261] = 1;
TABLE[55][257] = 1;
TABLE[55][275] = 1;
TABLE[56][299] = 1;
TABLE[57][258] = 1;
TABLE[58][262] = 1;
TABLE[59][59] = 1;
TABLE[59][44] = 1;
TABLE[59][278] = 1;
TABLE[59][63] = 1;
TABLE[59][38] = 1;
TABLE[59][42] = 1;
TABLE[59][43] = 1;
TABLE[59][45] = 1;
TABLE[59][126] = 1;
TABLE[59][33] = 1;
TABLE[59][294] = 1;
TABLE[59][295] = 1;
TABLE[59][297] = 1;
TABLE[59][40] = 1;
TABLE[59][289] = 1;
TABLE[59][299] = 1;
TABLE[59][298] = 1;
TABLE[59][308] = 1;
TABLE[59][306] = 1;
TABLE[59][307] = 1;
TABLE[59][301] = 1;
TABLE[59][303] = 1;
TABLE[59][302] = 1;
TABLE[59][292] = 1;
TABLE[59][304] = 1;
TABLE[59][47] = 1;
TABLE[59][37] = 1;
TABLE[170][59] = 1;
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
TABLE[170][299] = 1;
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
TABLE[237][59] = 1;
TABLE[60][123] = 1;
TABLE[171][262] = 1;
TABLE[171][258] = 1;
TABLE[171][299] = 1;
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
TABLE[171][44] = 1;
TABLE[171][278] = 1;
TABLE[171][63] = 1;
TABLE[171][38] = 1;
TABLE[171][42] = 1;
TABLE[171][43] = 1;
TABLE[171][45] = 1;
TABLE[171][126] = 1;
TABLE[171][33] = 1;
TABLE[171][294] = 1;
TABLE[171][295] = 1;
TABLE[171][297] = 1;
TABLE[171][40] = 1;
TABLE[171][289] = 1;
TABLE[171][298] = 1;
TABLE[171][308] = 1;
TABLE[171][306] = 1;
TABLE[171][307] = 1;
TABLE[171][301] = 1;
TABLE[171][303] = 1;
TABLE[171][302] = 1;
TABLE[171][292] = 1;
TABLE[171][304] = 1;
TABLE[171][47] = 1;
TABLE[171][37] = 1;
TABLE[171][125] = 1;
TABLE[171][260] = 1;
TABLE[171][286] = 1;
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
TABLE[171][280] = 1;
TABLE[171][283] = 1;
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
TABLE[239][125] = 1;
TABLE[61][125] = 1;
TABLE[61][262] = 1;
TABLE[61][258] = 1;
TABLE[61][299] = 1;
TABLE[61][59] = 1;
TABLE[61][123] = 1;
TABLE[61][281] = 1;
TABLE[61][271] = 1;
TABLE[61][269] = 1;
TABLE[61][263] = 1;
TABLE[61][287] = 1;
TABLE[61][275] = 1;
TABLE[61][257] = 1;
TABLE[61][261] = 1;
TABLE[61][270] = 1;
TABLE[61][44] = 1;
TABLE[61][278] = 1;
TABLE[61][63] = 1;
TABLE[61][38] = 1;
TABLE[61][42] = 1;
TABLE[61][43] = 1;
TABLE[61][45] = 1;
TABLE[61][126] = 1;
TABLE[61][33] = 1;
TABLE[61][294] = 1;
TABLE[61][295] = 1;
TABLE[61][297] = 1;
TABLE[61][40] = 1;
TABLE[61][289] = 1;
TABLE[61][298] = 1;
TABLE[61][308] = 1;
TABLE[61][306] = 1;
TABLE[61][307] = 1;
TABLE[61][301] = 1;
TABLE[61][303] = 1;
TABLE[61][302] = 1;
TABLE[61][292] = 1;
TABLE[61][304] = 1;
TABLE[61][47] = 1;
TABLE[61][37] = 1;
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
TABLE[173][299] = 1;
TABLE[173][258] = 1;
TABLE[173][262] = 1;
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
TABLE[240][262] = 1;
TABLE[240][258] = 1;
TABLE[240][299] = 1;
TABLE[240][59] = 1;
TABLE[240][123] = 1;
TABLE[240][281] = 1;
TABLE[240][271] = 1;
TABLE[240][269] = 1;
TABLE[240][263] = 1;
TABLE[240][287] = 1;
TABLE[240][275] = 1;
TABLE[240][257] = 1;
TABLE[240][261] = 1;
TABLE[240][270] = 1;
TABLE[240][44] = 1;
TABLE[240][278] = 1;
TABLE[240][63] = 1;
TABLE[240][38] = 1;
TABLE[240][42] = 1;
TABLE[240][43] = 1;
TABLE[240][45] = 1;
TABLE[240][126] = 1;
TABLE[240][33] = 1;
TABLE[240][294] = 1;
TABLE[240][295] = 1;
TABLE[240][297] = 1;
TABLE[240][40] = 1;
TABLE[240][289] = 1;
TABLE[240][298] = 1;
TABLE[240][308] = 1;
TABLE[240][306] = 1;
TABLE[240][307] = 1;
TABLE[240][301] = 1;
TABLE[240][303] = 1;
TABLE[240][302] = 1;
TABLE[240][292] = 1;
TABLE[240][304] = 1;
TABLE[240][47] = 1;
TABLE[240][37] = 1;
TABLE[240][125] = 1;
TABLE[62][271] = 1;
TABLE[63][281] = 1;
TABLE[174][265] = 1;
TABLE[241][125] = 1;
TABLE[241][265] = 1;
TABLE[241][287] = 1;
TABLE[241][262] = 1;
TABLE[241][258] = 1;
TABLE[241][299] = 1;
TABLE[241][59] = 1;
TABLE[241][123] = 1;
TABLE[241][281] = 1;
TABLE[241][271] = 1;
TABLE[241][269] = 1;
TABLE[241][263] = 1;
TABLE[241][275] = 1;
TABLE[241][257] = 1;
TABLE[241][261] = 1;
TABLE[241][270] = 1;
TABLE[241][44] = 1;
TABLE[241][278] = 1;
TABLE[241][63] = 1;
TABLE[241][38] = 1;
TABLE[241][42] = 1;
TABLE[241][43] = 1;
TABLE[241][45] = 1;
TABLE[241][126] = 1;
TABLE[241][33] = 1;
TABLE[241][294] = 1;
TABLE[241][295] = 1;
TABLE[241][297] = 1;
TABLE[241][40] = 1;
TABLE[241][289] = 1;
TABLE[241][298] = 1;
TABLE[241][308] = 1;
TABLE[241][306] = 1;
TABLE[241][307] = 1;
TABLE[241][301] = 1;
TABLE[241][303] = 1;
TABLE[241][302] = 1;
TABLE[241][292] = 1;
TABLE[241][304] = 1;
TABLE[241][47] = 1;
TABLE[241][37] = 1;
TABLE[64][287] = 1;
TABLE[65][263] = 1;
TABLE[66][269] = 1;
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
TABLE[242][59] = 1;
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
TABLE[177][41] = 1;
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
TABLE[244][41] = 1;
TABLE[67][270] = 1;
TABLE[68][261] = 1;
TABLE[69][257] = 1;
TABLE[70][275] = 1;
TABLE[178][59] = 1;
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
TABLE[245][59] = 1;
TABLE[71][59] = 1;
TABLE[71][41] = 1;
TABLE[71][58] = 1;
TABLE[71][93] = 1;
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
TABLE[179][44] = 1;
TABLE[179][278] = 1;
TABLE[179][295] = 1;
TABLE[179][294] = 1;
TABLE[179][33] = 1;
TABLE[179][126] = 1;
TABLE[179][45] = 1;
TABLE[179][43] = 1;
TABLE[179][42] = 1;
TABLE[179][38] = 1;
TABLE[179][63] = 1;
TABLE[179][299] = 1;
TABLE[179][289] = 1;
TABLE[179][40] = 1;
TABLE[179][297] = 1;
TABLE[179][307] = 1;
TABLE[179][306] = 1;
TABLE[179][308] = 1;
TABLE[179][298] = 1;
TABLE[179][301] = 1;
TABLE[179][303] = 1;
TABLE[179][302] = 1;
TABLE[179][292] = 1;
TABLE[179][304] = 1;
TABLE[179][37] = 1;
TABLE[179][47] = 1;
TABLE[246][278] = 1;
TABLE[246][63] = 1;
TABLE[246][38] = 1;
TABLE[246][42] = 1;
TABLE[246][43] = 1;
TABLE[246][45] = 1;
TABLE[246][126] = 1;
TABLE[246][33] = 1;
TABLE[246][294] = 1;
TABLE[246][295] = 1;
TABLE[246][297] = 1;
TABLE[246][40] = 1;
TABLE[246][289] = 1;
TABLE[246][299] = 1;
TABLE[246][298] = 1;
TABLE[246][308] = 1;
TABLE[246][306] = 1;
TABLE[246][307] = 1;
TABLE[246][301] = 1;
TABLE[246][303] = 1;
TABLE[246][302] = 1;
TABLE[246][292] = 1;
TABLE[246][304] = 1;
TABLE[246][47] = 1;
TABLE[246][37] = 1;
TABLE[246][59] = 1;
TABLE[246][41] = 1;
TABLE[246][44] = 1;
TABLE[246][58] = 1;
TABLE[246][93] = 1;
TABLE[72][59] = 1;
TABLE[72][41] = 1;
TABLE[72][44] = 1;
TABLE[72][125] = 1;
TABLE[72][58] = 1;
TABLE[72][93] = 1;
TABLE[72][63] = 1;
TABLE[72][297] = 1;
TABLE[72][298] = 1;
TABLE[72][301] = 1;
TABLE[72][303] = 1;
TABLE[72][302] = 1;
TABLE[72][292] = 1;
TABLE[72][304] = 1;
TABLE[72][43] = 1;
TABLE[72][45] = 1;
TABLE[72][40] = 1;
TABLE[72][278] = 1;
TABLE[72][37] = 1;
TABLE[72][47] = 1;
TABLE[72][42] = 1;
TABLE[72][38] = 1;
TABLE[72][126] = 1;
TABLE[72][33] = 1;
TABLE[72][294] = 1;
TABLE[72][295] = 1;
TABLE[72][289] = 1;
TABLE[72][299] = 1;
TABLE[72][308] = 1;
TABLE[72][306] = 1;
TABLE[72][307] = 1;
TABLE[73][278] = 1;
TABLE[73][295] = 1;
TABLE[73][294] = 1;
TABLE[73][33] = 1;
TABLE[73][126] = 1;
TABLE[73][45] = 1;
TABLE[73][43] = 1;
TABLE[73][42] = 1;
TABLE[73][38] = 1;
TABLE[73][299] = 1;
TABLE[73][289] = 1;
TABLE[73][40] = 1;
TABLE[73][307] = 1;
TABLE[73][306] = 1;
TABLE[73][308] = 1;
TABLE[74][291] = 1;
TABLE[75][61] = 1;
TABLE[76][59] = 1;
TABLE[76][41] = 1;
TABLE[76][125] = 1;
TABLE[76][93] = 1;
TABLE[76][58] = 1;
TABLE[76][44] = 1;
TABLE[76][63] = 1;
TABLE[76][297] = 1;
TABLE[76][298] = 1;
TABLE[76][301] = 1;
TABLE[76][303] = 1;
TABLE[76][302] = 1;
TABLE[76][292] = 1;
TABLE[76][304] = 1;
TABLE[76][40] = 1;
TABLE[76][45] = 1;
TABLE[76][43] = 1;
TABLE[76][42] = 1;
TABLE[76][47] = 1;
TABLE[76][37] = 1;
TABLE[76][278] = 1;
TABLE[76][295] = 1;
TABLE[76][294] = 1;
TABLE[76][33] = 1;
TABLE[76][126] = 1;
TABLE[76][38] = 1;
TABLE[76][299] = 1;
TABLE[76][289] = 1;
TABLE[76][307] = 1;
TABLE[76][306] = 1;
TABLE[76][308] = 1;
TABLE[180][63] = 1;
TABLE[247][59] = 1;
TABLE[247][41] = 1;
TABLE[247][125] = 1;
TABLE[247][93] = 1;
TABLE[247][58] = 1;
TABLE[247][44] = 1;
TABLE[77][59] = 1;
TABLE[77][125] = 1;
TABLE[77][93] = 1;
TABLE[77][58] = 1;
TABLE[77][44] = 1;
TABLE[77][63] = 1;
TABLE[77][297] = 1;
TABLE[77][298] = 1;
TABLE[77][301] = 1;
TABLE[77][303] = 1;
TABLE[77][302] = 1;
TABLE[77][292] = 1;
TABLE[77][304] = 1;
TABLE[77][43] = 1;
TABLE[77][45] = 1;
TABLE[77][40] = 1;
TABLE[77][278] = 1;
TABLE[77][37] = 1;
TABLE[77][47] = 1;
TABLE[77][42] = 1;
TABLE[77][38] = 1;
TABLE[77][126] = 1;
TABLE[77][33] = 1;
TABLE[77][294] = 1;
TABLE[77][295] = 1;
TABLE[77][289] = 1;
TABLE[77][299] = 1;
TABLE[77][308] = 1;
TABLE[77][306] = 1;
TABLE[77][307] = 1;
TABLE[78][63] = 1;
TABLE[78][59] = 1;
TABLE[78][41] = 1;
TABLE[78][125] = 1;
TABLE[78][93] = 1;
TABLE[78][58] = 1;
TABLE[78][44] = 1;
TABLE[78][297] = 1;
TABLE[78][298] = 1;
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
TABLE[78][38] = 1;
TABLE[78][126] = 1;
TABLE[78][33] = 1;
TABLE[78][294] = 1;
TABLE[78][295] = 1;
TABLE[78][289] = 1;
TABLE[78][299] = 1;
TABLE[78][308] = 1;
TABLE[78][306] = 1;
TABLE[78][307] = 1;
TABLE[181][297] = 1;
TABLE[181][298] = 1;
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
TABLE[248][298] = 1;
TABLE[248][301] = 1;
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
TABLE[248][297] = 1;
TABLE[248][125] = 1;
TABLE[248][93] = 1;
TABLE[248][58] = 1;
TABLE[248][44] = 1;
TABLE[79][63] = 1;
TABLE[79][59] = 1;
TABLE[79][41] = 1;
TABLE[79][297] = 1;
TABLE[79][125] = 1;
TABLE[79][93] = 1;
TABLE[79][58] = 1;
TABLE[79][44] = 1;
TABLE[79][298] = 1;
TABLE[79][301] = 1;
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
TABLE[79][33] = 1;
TABLE[79][126] = 1;
TABLE[79][38] = 1;
TABLE[79][299] = 1;
TABLE[79][289] = 1;
TABLE[79][307] = 1;
TABLE[79][306] = 1;
TABLE[79][308] = 1;
TABLE[182][298] = 1;
TABLE[182][301] = 1;
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
TABLE[249][301] = 1;
TABLE[249][303] = 1;
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
TABLE[249][298] = 1;
TABLE[249][297] = 1;
TABLE[249][125] = 1;
TABLE[249][93] = 1;
TABLE[249][58] = 1;
TABLE[249][44] = 1;
TABLE[80][63] = 1;
TABLE[80][59] = 1;
TABLE[80][41] = 1;
TABLE[80][298] = 1;
TABLE[80][297] = 1;
TABLE[80][125] = 1;
TABLE[80][93] = 1;
TABLE[80][58] = 1;
TABLE[80][44] = 1;
TABLE[80][301] = 1;
TABLE[80][303] = 1;
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
TABLE[80][38] = 1;
TABLE[80][126] = 1;
TABLE[80][33] = 1;
TABLE[80][294] = 1;
TABLE[80][295] = 1;
TABLE[80][289] = 1;
TABLE[80][299] = 1;
TABLE[80][308] = 1;
TABLE[80][306] = 1;
TABLE[80][307] = 1;
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
TABLE[183][33] = 1;
TABLE[183][126] = 1;
TABLE[183][38] = 1;
TABLE[183][299] = 1;
TABLE[183][289] = 1;
TABLE[183][307] = 1;
TABLE[183][306] = 1;
TABLE[183][308] = 1;
TABLE[250][303] = 1;
TABLE[250][302] = 1;
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
TABLE[250][301] = 1;
TABLE[250][298] = 1;
TABLE[250][297] = 1;
TABLE[250][125] = 1;
TABLE[250][93] = 1;
TABLE[250][58] = 1;
TABLE[250][44] = 1;
TABLE[81][63] = 1;
TABLE[81][59] = 1;
TABLE[81][41] = 1;
TABLE[81][301] = 1;
TABLE[81][298] = 1;
TABLE[81][297] = 1;
TABLE[81][125] = 1;
TABLE[81][93] = 1;
TABLE[81][58] = 1;
TABLE[81][44] = 1;
TABLE[81][303] = 1;
TABLE[81][302] = 1;
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
TABLE[81][33] = 1;
TABLE[81][126] = 1;
TABLE[81][38] = 1;
TABLE[81][299] = 1;
TABLE[81][289] = 1;
TABLE[81][307] = 1;
TABLE[81][306] = 1;
TABLE[81][308] = 1;
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
TABLE[251][302] = 1;
TABLE[251][292] = 1;
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
TABLE[251][303] = 1;
TABLE[251][301] = 1;
TABLE[251][298] = 1;
TABLE[251][297] = 1;
TABLE[251][125] = 1;
TABLE[251][93] = 1;
TABLE[251][58] = 1;
TABLE[251][44] = 1;
TABLE[82][63] = 1;
TABLE[82][59] = 1;
TABLE[82][41] = 1;
TABLE[82][303] = 1;
TABLE[82][301] = 1;
TABLE[82][298] = 1;
TABLE[82][297] = 1;
TABLE[82][125] = 1;
TABLE[82][93] = 1;
TABLE[82][58] = 1;
TABLE[82][44] = 1;
TABLE[82][302] = 1;
TABLE[82][292] = 1;
TABLE[82][304] = 1;
TABLE[82][43] = 1;
TABLE[82][45] = 1;
TABLE[82][40] = 1;
TABLE[82][278] = 1;
TABLE[82][37] = 1;
TABLE[82][47] = 1;
TABLE[82][42] = 1;
TABLE[82][38] = 1;
TABLE[82][126] = 1;
TABLE[82][33] = 1;
TABLE[82][294] = 1;
TABLE[82][295] = 1;
TABLE[82][289] = 1;
TABLE[82][299] = 1;
TABLE[82][308] = 1;
TABLE[82][306] = 1;
TABLE[82][307] = 1;
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
TABLE[185][33] = 1;
TABLE[185][126] = 1;
TABLE[185][38] = 1;
TABLE[185][299] = 1;
TABLE[185][289] = 1;
TABLE[185][307] = 1;
TABLE[185][306] = 1;
TABLE[185][308] = 1;
TABLE[252][292] = 1;
TABLE[252][304] = 1;
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
TABLE[252][302] = 1;
TABLE[252][303] = 1;
TABLE[252][301] = 1;
TABLE[252][298] = 1;
TABLE[252][297] = 1;
TABLE[252][125] = 1;
TABLE[252][93] = 1;
TABLE[252][58] = 1;
TABLE[252][44] = 1;
TABLE[83][63] = 1;
TABLE[83][59] = 1;
TABLE[83][41] = 1;
TABLE[83][302] = 1;
TABLE[83][303] = 1;
TABLE[83][301] = 1;
TABLE[83][298] = 1;
TABLE[83][297] = 1;
TABLE[83][125] = 1;
TABLE[83][93] = 1;
TABLE[83][58] = 1;
TABLE[83][44] = 1;
TABLE[83][292] = 1;
TABLE[83][304] = 1;
TABLE[83][40] = 1;
TABLE[83][45] = 1;
TABLE[83][43] = 1;
TABLE[83][42] = 1;
TABLE[83][47] = 1;
TABLE[83][37] = 1;
TABLE[83][278] = 1;
TABLE[83][295] = 1;
TABLE[83][294] = 1;
TABLE[83][33] = 1;
TABLE[83][126] = 1;
TABLE[83][38] = 1;
TABLE[83][299] = 1;
TABLE[83][289] = 1;
TABLE[83][307] = 1;
TABLE[83][306] = 1;
TABLE[83][308] = 1;
TABLE[186][292] = 1;
TABLE[186][304] = 1;
TABLE[186][43] = 1;
TABLE[186][45] = 1;
TABLE[186][40] = 1;
TABLE[186][278] = 1;
TABLE[186][37] = 1;
TABLE[186][47] = 1;
TABLE[186][42] = 1;
TABLE[186][38] = 1;
TABLE[186][126] = 1;
TABLE[186][33] = 1;
TABLE[186][294] = 1;
TABLE[186][295] = 1;
TABLE[186][289] = 1;
TABLE[186][299] = 1;
TABLE[186][308] = 1;
TABLE[186][306] = 1;
TABLE[186][307] = 1;
TABLE[253][304] = 1;
TABLE[253][40] = 1;
TABLE[253][45] = 1;
TABLE[253][43] = 1;
TABLE[253][42] = 1;
TABLE[253][47] = 1;
TABLE[253][37] = 1;
TABLE[253][278] = 1;
TABLE[253][295] = 1;
TABLE[253][294] = 1;
TABLE[253][33] = 1;
TABLE[253][126] = 1;
TABLE[253][38] = 1;
TABLE[253][299] = 1;
TABLE[253][289] = 1;
TABLE[253][307] = 1;
TABLE[253][306] = 1;
TABLE[253][308] = 1;
TABLE[253][63] = 1;
TABLE[253][59] = 1;
TABLE[253][41] = 1;
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
TABLE[84][63] = 1;
TABLE[84][59] = 1;
TABLE[84][41] = 1;
TABLE[84][292] = 1;
TABLE[84][302] = 1;
TABLE[84][303] = 1;
TABLE[84][301] = 1;
TABLE[84][298] = 1;
TABLE[84][297] = 1;
TABLE[84][125] = 1;
TABLE[84][93] = 1;
TABLE[84][58] = 1;
TABLE[84][44] = 1;
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
TABLE[187][33] = 1;
TABLE[187][126] = 1;
TABLE[187][38] = 1;
TABLE[187][299] = 1;
TABLE[187][289] = 1;
TABLE[187][307] = 1;
TABLE[187][306] = 1;
TABLE[187][308] = 1;
TABLE[254][43] = 1;
TABLE[254][45] = 1;
TABLE[254][40] = 1;
TABLE[254][278] = 1;
TABLE[254][37] = 1;
TABLE[254][47] = 1;
TABLE[254][42] = 1;
TABLE[254][38] = 1;
TABLE[254][126] = 1;
TABLE[254][33] = 1;
TABLE[254][294] = 1;
TABLE[254][295] = 1;
TABLE[254][289] = 1;
TABLE[254][299] = 1;
TABLE[254][308] = 1;
TABLE[254][306] = 1;
TABLE[254][307] = 1;
TABLE[254][63] = 1;
TABLE[254][59] = 1;
TABLE[254][41] = 1;
TABLE[254][304] = 1;
TABLE[254][292] = 1;
TABLE[254][302] = 1;
TABLE[254][303] = 1;
TABLE[254][301] = 1;
TABLE[254][298] = 1;
TABLE[254][297] = 1;
TABLE[254][125] = 1;
TABLE[254][93] = 1;
TABLE[254][58] = 1;
TABLE[254][44] = 1;
TABLE[85][63] = 1;
TABLE[85][59] = 1;
TABLE[85][41] = 1;
TABLE[85][304] = 1;
TABLE[85][292] = 1;
TABLE[85][302] = 1;
TABLE[85][303] = 1;
TABLE[85][301] = 1;
TABLE[85][298] = 1;
TABLE[85][297] = 1;
TABLE[85][125] = 1;
TABLE[85][93] = 1;
TABLE[85][58] = 1;
TABLE[85][44] = 1;
TABLE[85][45] = 1;
TABLE[85][43] = 1;
TABLE[85][40] = 1;
TABLE[85][42] = 1;
TABLE[85][47] = 1;
TABLE[85][37] = 1;
TABLE[85][278] = 1;
TABLE[85][295] = 1;
TABLE[85][294] = 1;
TABLE[85][33] = 1;
TABLE[85][126] = 1;
TABLE[85][38] = 1;
TABLE[85][299] = 1;
TABLE[85][289] = 1;
TABLE[85][307] = 1;
TABLE[85][306] = 1;
TABLE[85][308] = 1;
TABLE[190][43] = 1;
TABLE[190][45] = 1;
TABLE[190][40] = 1;
TABLE[190][278] = 1;
TABLE[190][37] = 1;
TABLE[190][47] = 1;
TABLE[190][42] = 1;
TABLE[190][38] = 1;
TABLE[190][126] = 1;
TABLE[190][33] = 1;
TABLE[190][294] = 1;
TABLE[190][295] = 1;
TABLE[190][289] = 1;
TABLE[190][299] = 1;
TABLE[190][308] = 1;
TABLE[190][306] = 1;
TABLE[190][307] = 1;
TABLE[255][40] = 1;
TABLE[255][42] = 1;
TABLE[255][47] = 1;
TABLE[255][37] = 1;
TABLE[255][278] = 1;
TABLE[255][295] = 1;
TABLE[255][294] = 1;
TABLE[255][33] = 1;
TABLE[255][126] = 1;
TABLE[255][45] = 1;
TABLE[255][43] = 1;
TABLE[255][38] = 1;
TABLE[255][299] = 1;
TABLE[255][289] = 1;
TABLE[255][307] = 1;
TABLE[255][306] = 1;
TABLE[255][308] = 1;
TABLE[255][63] = 1;
TABLE[255][59] = 1;
TABLE[255][41] = 1;
TABLE[255][304] = 1;
TABLE[255][292] = 1;
TABLE[255][302] = 1;
TABLE[255][303] = 1;
TABLE[255][301] = 1;
TABLE[255][298] = 1;
TABLE[255][297] = 1;
TABLE[255][125] = 1;
TABLE[255][93] = 1;
TABLE[255][58] = 1;
TABLE[255][44] = 1;
TABLE[188][43] = 1;
TABLE[189][45] = 1;
TABLE[86][40] = 1;
TABLE[86][37] = 1;
TABLE[86][47] = 1;
TABLE[86][42] = 1;
TABLE[86][278] = 1;
TABLE[86][38] = 1;
TABLE[86][43] = 1;
TABLE[86][45] = 1;
TABLE[86][126] = 1;
TABLE[86][33] = 1;
TABLE[86][294] = 1;
TABLE[86][295] = 1;
TABLE[86][289] = 1;
TABLE[86][299] = 1;
TABLE[86][308] = 1;
TABLE[86][306] = 1;
TABLE[86][307] = 1;
TABLE[194][40] = 1;
TABLE[194][42] = 1;
TABLE[194][47] = 1;
TABLE[194][37] = 1;
TABLE[194][278] = 1;
TABLE[194][295] = 1;
TABLE[194][294] = 1;
TABLE[194][33] = 1;
TABLE[194][126] = 1;
TABLE[194][45] = 1;
TABLE[194][43] = 1;
TABLE[194][38] = 1;
TABLE[194][299] = 1;
TABLE[194][289] = 1;
TABLE[194][307] = 1;
TABLE[194][306] = 1;
TABLE[194][308] = 1;
TABLE[256][40] = 1;
TABLE[256][278] = 1;
TABLE[256][38] = 1;
TABLE[256][42] = 1;
TABLE[256][43] = 1;
TABLE[256][45] = 1;
TABLE[256][126] = 1;
TABLE[256][33] = 1;
TABLE[256][294] = 1;
TABLE[256][295] = 1;
TABLE[256][289] = 1;
TABLE[256][299] = 1;
TABLE[256][308] = 1;
TABLE[256][306] = 1;
TABLE[256][307] = 1;
TABLE[191][42] = 1;
TABLE[192][47] = 1;
TABLE[193][37] = 1;
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
TABLE[88][40] = 1;
TABLE[89][40] = 1;
TABLE[89][289] = 1;
TABLE[89][299] = 1;
TABLE[89][308] = 1;
TABLE[89][306] = 1;
TABLE[89][307] = 1;
TABLE[90][294] = 1;
TABLE[90][295] = 1;
TABLE[91][38] = 1;
TABLE[91][42] = 1;
TABLE[91][43] = 1;
TABLE[91][45] = 1;
TABLE[91][126] = 1;
TABLE[91][33] = 1;
TABLE[92][278] = 1;
TABLE[93][278] = 1;
TABLE[195][294] = 1;
TABLE[196][295] = 1;
TABLE[94][38] = 1;
TABLE[95][42] = 1;
TABLE[96][43] = 1;
TABLE[97][45] = 1;
TABLE[98][126] = 1;
TABLE[99][33] = 1;
TABLE[100][299] = 1;
TABLE[100][289] = 1;
TABLE[100][40] = 1;
TABLE[100][307] = 1;
TABLE[100][306] = 1;
TABLE[100][308] = 1;
TABLE[101][40] = 1;
TABLE[101][289] = 1;
TABLE[101][299] = 1;
TABLE[101][308] = 1;
TABLE[101][306] = 1;
TABLE[101][307] = 1;
TABLE[197][91] = 1;
TABLE[199][40] = 1;
TABLE[200][46] = 1;
TABLE[201][296] = 1;
TABLE[202][294] = 1;
TABLE[203][295] = 1;
TABLE[198][41] = 1;
TABLE[198][44] = 1;
TABLE[198][278] = 1;
TABLE[198][295] = 1;
TABLE[198][294] = 1;
TABLE[198][33] = 1;
TABLE[198][126] = 1;
TABLE[198][45] = 1;
TABLE[198][43] = 1;
TABLE[198][42] = 1;
TABLE[198][38] = 1;
TABLE[198][63] = 1;
TABLE[198][299] = 1;
TABLE[198][289] = 1;
TABLE[198][40] = 1;
TABLE[198][297] = 1;
TABLE[198][307] = 1;
TABLE[198][306] = 1;
TABLE[198][308] = 1;
TABLE[198][298] = 1;
TABLE[198][301] = 1;
TABLE[198][303] = 1;
TABLE[198][302] = 1;
TABLE[198][292] = 1;
TABLE[198][304] = 1;
TABLE[198][37] = 1;
TABLE[198][47] = 1;
TABLE[257][41] = 1;
TABLE[102][299] = 1;
TABLE[103][308] = 1;
TABLE[103][306] = 1;
TABLE[103][307] = 1;
TABLE[103][299] = 1;
TABLE[104][289] = 1;
TABLE[105][40] = 1;
TABLE[106][41] = 1;
TABLE[106][44] = 1;
TABLE[106][278] = 1;
TABLE[106][63] = 1;
TABLE[106][38] = 1;
TABLE[106][42] = 1;
TABLE[106][43] = 1;
TABLE[106][45] = 1;
TABLE[106][126] = 1;
TABLE[106][33] = 1;
TABLE[106][294] = 1;
TABLE[106][295] = 1;
TABLE[106][297] = 1;
TABLE[106][40] = 1;
TABLE[106][289] = 1;
TABLE[106][299] = 1;
TABLE[106][298] = 1;
TABLE[106][308] = 1;
TABLE[106][306] = 1;
TABLE[106][307] = 1;
TABLE[106][301] = 1;
TABLE[106][303] = 1;
TABLE[106][302] = 1;
TABLE[106][292] = 1;
TABLE[106][304] = 1;
TABLE[106][47] = 1;
TABLE[106][37] = 1;
TABLE[204][44] = 1;
TABLE[204][278] = 1;
TABLE[204][295] = 1;
TABLE[204][294] = 1;
TABLE[204][33] = 1;
TABLE[204][126] = 1;
TABLE[204][45] = 1;
TABLE[204][43] = 1;
TABLE[204][42] = 1;
TABLE[204][38] = 1;
TABLE[204][63] = 1;
TABLE[204][299] = 1;
TABLE[204][289] = 1;
TABLE[204][40] = 1;
TABLE[204][297] = 1;
TABLE[204][307] = 1;
TABLE[204][306] = 1;
TABLE[204][308] = 1;
TABLE[204][298] = 1;
TABLE[204][301] = 1;
TABLE[204][303] = 1;
TABLE[204][302] = 1;
TABLE[204][292] = 1;
TABLE[204][304] = 1;
TABLE[204][37] = 1;
TABLE[204][47] = 1;
TABLE[258][278] = 1;
TABLE[258][63] = 1;
TABLE[258][38] = 1;
TABLE[258][42] = 1;
TABLE[258][43] = 1;
TABLE[258][45] = 1;
TABLE[258][126] = 1;
TABLE[258][33] = 1;
TABLE[258][294] = 1;
TABLE[258][295] = 1;
TABLE[258][297] = 1;
TABLE[258][40] = 1;
TABLE[258][289] = 1;
TABLE[258][299] = 1;
TABLE[258][298] = 1;
TABLE[258][308] = 1;
TABLE[258][306] = 1;
TABLE[258][307] = 1;
TABLE[258][301] = 1;
TABLE[258][303] = 1;
TABLE[258][302] = 1;
TABLE[258][292] = 1;
TABLE[258][304] = 1;
TABLE[258][47] = 1;
TABLE[258][37] = 1;
TABLE[258][41] = 1;
TABLE[258][44] = 1;
TABLE[107][308] = 1;
TABLE[108][306] = 1;
TABLE[109][307] = 1;
TABLE[110][299] = 1;
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
      case 97: return 0; break;
      case 117: return 0; break;
      case 129: return 0; break;
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
      case 491: return 1; break;
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
      case 622: return 0; break;
      case 641: return 1; break;
      case 646: return 1; break;
      case 653: return 0; break;
      case 660: return 1; break;
      case 667: return 1; break;
      case 674: return 1; break;
      case 679: return 1; break;
      case 686: return 0; break;
      case 703: return 1; break;
      case 711: return 0; break;
      case 741: return 1; break;
      case 748: return 1; break;
      case 755: return 1; break;
      case 762: return 0; break;
      case 784: return 1; break;
      case 791: return 1; break;
      case 796: return 1; break;
      case 804: return 1; break;
      case 814: return 0; break;
      case 822: return 1; break;
      case 827: return 1; break;
      case 837: return 1; break;
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
      case 932: return 1; break;
      case 937: return 1; break;
      case 945: return 0; break;
      case 953: return 1; break;
      case 958: return 1; break;
      case 966: return 0; break;
      case 978: return 0; break;
      case 989: return 0; break;
      case 1015: return 0; break;
      case 1023: return 0; break;
      case 1047: return 0; break;
      case 1056: return 0; break;
      case 1086: return 1; break;
      case 1093: return 0; break;
      case 1111: return 1; break;
      case 1116: return 1; break;
      case 1124: return 0; break;
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
         case 97: return "Subphrase"; break;
         case 117: return "type_specifier"; break;
         case 129: return "Subphrase"; break;
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
         case 622: return "labeled_statement"; break;
         case 641: return "expression_statement"; break;
         case 646: return "Subphrase"; break;
         case 653: return "compound_statement"; break;
         case 660: return "Subphrase"; break;
         case 667: return "Subphrase"; break;
         case 674: return "statement_list"; break;
         case 679: return "Subphrase"; break;
         case 686: return "selection_statement"; break;
         case 703: return "Subphrase"; break;
         case 711: return "iteration_statement"; break;
         case 741: return "Subphrase"; break;
         case 748: return "Subphrase"; break;
         case 755: return "Subphrase"; break;
         case 762: return "jump_statement"; break;
         case 784: return "Subphrase"; break;
         case 791: return "expression"; break;
         case 796: return "Subphrase"; break;
         case 804: return "assignment_expression"; break;
         case 814: return "assignment_operator"; break;
         case 822: return "conditional_expression"; break;
         case 827: return "Subphrase"; break;
         case 837: return "constant_expression"; break;
         case 841: return "logical_OR_expression"; break;
         case 846: return "Subphrase"; break;
         case 854: return "logical_AND_expression"; break;
         case 859: return "Subphrase"; break;
         case 867: return "inclusive_OR_expression"; break;
         case 872: return "Subphrase"; break;
         case 880: return "exclusive_OR_expression"; break;
         case 885: return "Subphrase"; break;
         case 893: return "AND_expression"; break;
         case 898: return "Subphrase"; break;
         case 906: return "equality_expression"; break;
         case 911: return "Subphrase"; break;
         case 919: return "shift_expression"; break;
         case 924: return "Subphrase"; break;
         case 932: return "additive_expression"; break;
         case 937: return "Subphrase"; break;
         case 945: return "Subphrase"; break;
         case 953: return "multiplicative_expression"; break;
         case 958: return "Subphrase"; break;
         case 966: return "Subphrase"; break;
         case 978: return "cast_expression"; break;
         case 989: return "unary_expression"; break;
         case 1015: return "Subphrase"; break;
         case 1023: return "unary_operator"; break;
         case 1047: return "postfix_expression"; break;
         case 1056: return "Subphrase"; break;
         case 1086: return "Subphrase"; break;
         case 1093: return "primary_expression"; break;
         case 1111: return "argument_expression_list"; break;
         case 1116: return "Subphrase"; break;
         case 1124: return "constant"; break;
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
