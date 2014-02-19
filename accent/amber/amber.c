/*
 *   amber.c
 *
 *   AMBER
 *
 *   An Ambiguity Checker for Context-Free Grammars
 *
 *   Copyright (C) 2001, 2006 Friedrich Wilhelm Schroeer
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 * 
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 * 
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

/*============================================================================*/
#include <stdlib.h>
#include <stdio.h>

#define PRIVATE static
#define PUBLIC

/*============================================================================*/
/* OPTIONS                                                                    */
/*============================================================================*/

#define PRINTTREE 0
#define WALK 0
#define CHECKVIABLE 0
#define LOOKAHEAD 0
#define ERRPOSCORRECTION 1
#define DETECTAMBIGUITY 1
#define DYNAMICCYCLECHECK 1
#define HASHING 1
#define DYNAMICITEMS 0

int ELLIPSIS = 0;
int iteration = 1;

/*============================================================================*/

extern char *yyprintname();
/*============================================================================*/
/* ITEMS                                                                      */
/*============================================================================*/

#if DYNAMICITEMS
int ITEMLIMIT;
#else
#define ITEMLIMIT    285000
#endif

#define ITEMINCR 285000

# if DYNAMICITEMS
long *dot, *back, *left, *sub;
#else
long dot[ITEMLIMIT], back[ITEMLIMIT], left[ITEMLIMIT], sub[ITEMLIMIT];
#endif
/*
 * An "item" is a quadrupel < D, B, L, S > , where
 *
 * D is a rule currently being processed.
 *   A working point ("dot", written as "*")
 *   devides the right hand side into part already being processed (alpha)
 *   and a part that still needs to be processed (beta)
 *      M : alpha * beta
 *
 * B (back-pointer) is a reference to a list of items in which the
 *   processing of rule rule
 *      D  =  M : M : alpha * beta
 *   startet. This list contains a start item
 *      I' =  < D', B', L', S' >
 *   where
 *      D' =  M : * alpha beta
 *
 * L (left-pointer) 
 *
 * S (sub-pointer)
 * 
 * [ documentation to be completed in forthcoming release ....... ]
 *
 * If I is the index of an item < D, B, L, S > then
 *    dot[I]  = D
 *    back[I] = B
 *    left[I] = L
 *    sub[I]  = S
 */

long thislist;
/*
 * current itemlist (index of first item of list)
 */

long last_item;
/*
 * index of last item in item list
 * position last_item+1 is used for sentinel during searching
 * last_item+1 must not exceed ITEMLIMIT-1 (i.e. last_item < ITEMLIMIT-2)
 *
 */

long specialitemadded;
/*
 * an item with index i such that back[i]==thislist
 * has been added to the current item list
 * This requires a rescan of previous items during closure computation
 * (which otherwise is not neccessary)
 */

long lookaheadswitchedoff = 0;

/*============================================================================*/
/* GRAMMAR ENCODING                                                           */
/*============================================================================*/

extern int yygrammar[];
/*
 * encoded grammar
 * defined in 'yygrammar.c'
 *
 *
 * structure of encoding
 *
 * a rule
 *    [r] M0 : M1 ... Mn
 * with number r, lhs M0, and rhs M1 .. M1
 * is encoded as follows
 *
 *   +-- chain<-+
 *   |   M1*-------> first rule for M1
 *   |   ...    |
 *   |   Mn*    |
 *   |   -M0*---+
 *   |   r
 *   +-> next rule for M0
 *
 * chain : index of start of next rule for M0 (or 0)
 *
 * M1*   : encoding of rhs member Mi (1 <= i <= n)
 * ...     Mi nonterminal: index of start of encoding of first rule for Mi
 * Mn*     Mi terminal: see below
 *
 * -M0*  : negative index of start of encoding of first rule for M0
 *
 * r     : rule number
 *
 * The grammar starts with the rule
 *    [0] YYSTART : UserRoot EOF
 * which is encoded as follows:
 *
 *   1: 0     (chain)
 *   2: 6     (first rule of user root) (= STARTUSERGRAMMAR)
 *   3: EOF   (eof token)
 *   4: -1    (points to start of rule)
 *   5: 0     (rule number)
 */

#define STARTUSERGRAMMAR 8

extern int yyannotation[];
/* defined in 'yygrammar.c' */

extern int yycoordinate[];
/* defined in 'yygrammar.c' */

extern int c_length;
 /*
  * length of yygrammar
  * defined in 'yygrammar.c'
  */

# define term_base 50000
# define max_char    255
# define eofsym    term_base

/* nonterminals are encoded as
 *    1 ... term_base-1
 * the eof terminal is encoded as
 *    termbase
 * single character terminals are encoded as
 *    term_base+1 ... term_base+max_char
 * named terminals are encoded as
 *    term_base+max_char+1 ...
 *
 * yylex() returns an original token code
 * that must be incremented by term_base
 */

/*============================================================================*/
/* DIRECTOR SETS                                                              */
/*============================================================================*/

long sym;
/* current input token */

long lookaheadsym;
/* next input token */

extern long yypos;
/* this variable must be set by the scanner */

PRIVATE long lookaheadpos;
PRIVATE char * lookaheadtokenname;

/*============================================================================*/
/* PRINT ROUTINES                                                             */
/*============================================================================*/

PRIVATE print_item(p)
   int p;
/*
 * print the item with index p
 */
{
   int i, b, e, l, k;
   i = dot[p];

   printf(" %d: ", p);
   if (dot[p] == 0 && sub[p] == 0) {
      printf("[ separator-item ]\n");
      return;
   }
   if (i <= 5) {
      b = 1;
   }
   else {
      b = i-1;
      while(yygrammar[b] >= 0) b--;
      b += 2;
   }
   /* b points to the start of the rule */

   e = i;
   while(yygrammar[e] >= 0) e++;
   /* e points to the end of the rule, i.e. the lhscode */

   l = - yygrammar[e];
   /* l is the lhs */

   printf("%s :", yyprintname(l));
   k = b+1;
   /* k points to the first member */
   while(yygrammar[k] > 0) {
      if (k == i) printf(" *");
      /* print member yygrammar[k] */
      if (yygrammar[k] == eofsym) {
	 printf(" <EOF>");
      }
      else if (yygrammar[k] > term_base) {
	 if (yygrammar[k] < term_base+max_char+1) {
	    printf(" '%c'", yygrammar[k]-term_base);
         }
	 else
	    printf(" %s", yyprintname(yygrammar[k]));
      }
      else {
	 printf(" %s", yyprintname(yygrammar[k]));
      }
      k++;
   }
   if (yygrammar[i] <= 0) printf(" *");
   printf(" (back:%d sub:%d left:%d)\n", back[p], sub[p], left[p]);
}

/*----------------------------------------------------------------------------*/

PRIVATE print_coordinate(i)
   int i;
/*
 * print source coordinate (of grammar file) with code i
 * the number encodes both, line and column information
 */
{
   int pos = yycoordinate[i];
   int l = pos / 1000;
   int c = pos % 1000;

   printf("line %d, col %d of grammar", l, c);
}

/*----------------------------------------------------------------------------*/

PRIVATE print_tree(i)
   int i;
/*
 * print tree for item with index i
 */
{
   static int indent = 0;
   int k;

   /* rule number if item at end of rule */
   if (yygrammar[dot[i]] < 0 ) {
      /* end of rule */
      for (k = 1; k <= indent; k++) printf("  ");
      printf("%s alternative at ", yyprintname(-yygrammar[dot[i]]));
      print_coordinate(dot[i]+1);
      printf(" {\n");
      indent++;
   }

   /* left brothers */

   if (left[i]) print_tree(left[i]);

   /* this son */

   if (left[i]) {
      int sym = yygrammar[dot[i]-1];

      if (sym > term_base) {
         for (k = 1; k <= indent; k++) printf("  ");
	 if (sym < term_base+max_char+1)
            printf("'%c'\n", yygrammar[dot[i]-1]-term_base);
	 else
	    printf("%s\n", yyprintname(sym));
      }
      else if (sym > 1 && ! sub[i]) {
         for (k = 1; k <= indent; k++) printf("  ");
	 printf("%s { ... }\n", yyprintname(sym));
      }
   }

   /* subtree for this son */

   if (sub[i])  print_tree(sub[i]);

   if (yygrammar[dot[i]] < 0 ) {
      /* end of rule */
      indent--;
      for (k = 1; k <= indent; k++) printf("  ");
      printf("}\n");
   }
}

/*============================================================================*/
/* DIRECTOR SETS                                                              */
/*============================================================================*/

PRIVATE int lookup_dirset(ruleptr)
   long ruleptr;
/*
 * Let 'rule' be the rule be the rule into which 'ruleptr' points.
 * Let 'tkn' be the code of the next token.
 * Return ('tkn' is in the director set of 'rule').
 */
{
   int p;
   int rule;
   int tkn;

   /* find rule number */
   p = ruleptr;
   while (yygrammar[p] >= 0) p++;
   p++;
   rule = yygrammar[p];

   tkn = lookaheadsym-term_base;

   return yydirset(rule, tkn);
}

/*----------------------------------------------------------------------------*/

PRIVATE int is_viable (d)
   int d;
/*
 * d is a pointer into the encoded grammar
 * Returns true if the the symbol yygrammar[d] (token or nonterminal)
 * is a valid continuation of the parse:
 * can it start with the current lookahead token?
 * If the symbol is a token it is compared with the lookahead token
 * If symbol is a nonterminal it is checked whether the lookahead token
 * appears in the director sets of the rules for the nonterm of the symbol
 *
 * NOTE: the union of the director sets should be computed statically
 */
{ 
   if (yygrammar[d] >= term_base) {
      /* token */
      if (yygrammar[d] == lookaheadsym) {
	 return 1;
      }
      else {
	 return 0;
      }
   }

   else if (yygrammar[d] > 0 ) {
      /* nonterm */

      int start;

      start = yygrammar[d];
      /* start points to the first rule for the nonterm */
      do {
	 int p;
	 int rule;

	 p = start+1;
	 while (yygrammar[p] >= 0) {
	    p++;
	 }
	 /* p now points to negative lhs encoding */
	 rule = yygrammar[p+1];
	 if (yydirset(rule, lookaheadsym-term_base)) {
	    return 1;
	 }
	 start = yygrammar[start];
      } while (start);

      return 0;
   }

   else {
      /* end of rule */
      return 1;
   }
}

/*============================================================================*/
/* ERROR MESSAGES                                                             */
/*============================================================================*/

int posforerrormsg = 0;
PRIVATE syntaxerror()
/*
 * Report syntax error and terminate
 */
{
printf("syntaxerror() should not be called in AMBER\n");
exit(1);
}

/*----------------------------------------------------------------------------*/

PRIVATE Abort(msg)
   char *msg;
/*
 * emit msg and terminate
 */
{
   printf("%s\n", msg);
   exit(1);
}

/*----------------------------------------------------------------------------*/

PRIVATE table_full()
/*
 * item table full
 */
{
#if DYNAMICITEMS
   ITEMLIMIT += ITEMINCR;

   dot = (long *) realloc(dot, ITEMLIMIT* sizeof(long));
   if (! dot) yymallocerror();
   back = (long *) realloc(back, ITEMLIMIT* sizeof(long));
   if (! back) yymallocerror();
   left = (long *) realloc(left, ITEMLIMIT* sizeof(long));
   if (! left) yymallocerror();
   sub = (long *) realloc(sub, ITEMLIMIT* sizeof(long));
   if (! sub) yymallocerror();
#else
   Abort("fatal error: item table overflow [increase ITEMLIMIT in art.c]\n");
#endif
}

/*----------------------------------------------------------------------------*/

PUBLIC yymallocerror()
{
   printf("running out of memory\n");
   exit(1);
}

/*============================================================================*/
/* SEARCH OPTIMISATION                                                        */
/*============================================================================*/

#define HSIZE 1024

#define HASHCODE (b%8+d)%HSIZE

#if HASHING

int hash[HSIZE];
/*
 * hash table to speed up lookup-function
 * if an item with back pointer b and dot d is entered
 * into the current item list
 * an entry with a corresponding hash code is set
 */

/*----------------------------------------------------------------------------*/

PRIVATE int clearhash ()
/*
 * clear hash table
 */
{
   int i;

   for (i = 0; i<HSIZE; i++) hash[i] = 0;
}

/*----------------------------------------------------------------------------*/

PRIVATE int hashed(d, b)
   int d, b;
/*
 * true if there is an entry entry for item with dot d and backpointer b
 */
{
   return hash[HASHCODE];
}

/*----------------------------------------------------------------------------*/

PRIVATE sethash(d, b)
   int d, b;
/*
 * set entry for item with dot d and backpointer b
 */
{
   hash[HASHCODE] = 1;
}
#endif

/*============================================================================*/
/* TOKENS                                                                     */
/*============================================================================*/

PRIVATE readsym ()
/*
 * read next token
 * current token: 'sym'
 * following token: 'lookaheadsym'
 * extend the list of lexical values by calling
 * next_lexval() provided by 'yygrammar.c'
 */
{
printf("readsym() should not be called in AMBER\n");
exit(1);
}

/*============================================================================*/
/* GRAMMAR                                                                    */
/*============================================================================*/

int prioval = 1;
int prioindex;

PRIVATE int getprio(subptr)
   int subptr;

   /* subptr points to an item */
   /* return the prio of corresponding rule */
{
   int i;
   int prio;

   /* find end of rule */
   i = dot[subptr];
   while (yygrammar[i] > 0) i++;
   /* i points to the negative lhs encoding */
   i++;
   /* i now points to the rule number, this is also the index of the prio */

   prio = yyannotation[i];
   prioindex = i;
   if (prio == -1) {
      prioval++;
      yyannotation[i] = prioval;
   }
   return prio;
}

/*----------------------------------------------------------------------------*/

PRIVATE int getmemberannotation(i)
   int i;

   /* i is the index of a member */
   /* return the annotation of the member before the dot */
{
   int grammarindex, annotation;

   grammarindex = dot[i]-1;
   annotation = yyannotation[grammarindex];
   if (annotation != 1 && annotation != 2) {
      yyannotation[grammarindex] = 1;
   }
   return annotation;
}

/*============================================================================*/
/* AMBIGUITY RESOLUTION                                                       */
/*============================================================================*/

PRIVATE int test_for_cycle(subtree, container)
   int subtree;
   int container;
/*
 * return true if
 * the tree to which 'container' (a "subpointer" of an item) points
 * contains the tree to which 'subtree' (also a "subpointer") points
 */
{
   if (container < subtree) {
      /* an earlier item cannot refer a later one */ 
      return 0;
   }
   if (container == subtree) {
      return 1;
   }
   if (sub[container]) {
      if (test_for_cycle(subtree, sub[container]))
         return 1;
   }
   if (left[container]) {
      if (test_for_cycle(subtree, left[container]))
         return 1;
   }
   return 0;
}

/*----------------------------------------------------------------------------*/

int ambiguity_count = 0;

PRIVATE conjunctive_ambiguity(i, d, l, s)
   int i, d, l, s;
/*
 * The item with index i
 * and an item with dot d, leftpointer l, and subpointer s
 * introduce a conjunctive ambiguity
 */
{
   if (left[i] != l) {

      /* Conjunctive Ambiguity */

      int left1, left2, sub1, sub2, annotation;
      int selected_left, selected_sub;

      left1 = left[i];
      sub1 = sub[i];

      left2 = l;
      sub2 = s;

      annotation = getmemberannotation(i);

      if (annotation == 1) {
	 /* %short */

	 if (left1 > left2) {
	    selected_left = left1;
	    selected_sub = sub1;
	 }
	 else {
	    selected_left = left2;
	    selected_sub = sub2;
	 }
      }
      else if (annotation == 2) {
	 /* %long */

	 if (left2 > left1) {
	    selected_left = left1;
	    selected_sub = sub1;
	 }
	 else {
	    selected_left = left2;
	    selected_sub = sub2;
	 }
      }
      else if (annotation == 0) {
	 /* annotation == undef */

	 int old_sub, old_left;

	 printf("\n");
	 printf("GRAMMAR DEBUG INFORMATION\n");
	 printf("\n");
	 printf("Grammar ambiguity detected.\n");

	 {
	    int k;
	    k = dot[i];
	    while (yygrammar[k] > 0) k++;
	    printf("There are two different parses\n");
	    printf("for the beginning of ``%s'', alternative at ",
	       yyprintname(-yygrammar[k]));
	    print_coordinate(k+1);
	    printf(",\n");
	 }
	 printf("upto and containing ``%s'' at ", yyprintname(yygrammar[d-1]));
	 print_coordinate(d-1);
	 printf(".\n");

	 printf("\n");
	 printf("PARSE 1\n");
	 printf("-------\n");
	 printf("\n");
	 print_tree(i);

	 printf("\n");
	 printf("PARSE 2\n");
	 printf("-------\n");
	 printf("\n");
	 print_tree(last_item+1);

	 printf("\n");
	 printf("For ``%s'' at ", yyprintname(yygrammar[d-1]));
	 print_coordinate(d-1);
	 printf(",\n");
	 if (left1 > left2) {
	    printf("use %%short annotation to select first parse,\n");
	    printf("use %%long annotation to select second parse.\n");
	 }
	 else {
	    printf("use %%long annotation to select first parse,\n");
	    printf("use %%short annotation to select second parse.\n");
	 }

	 printf("\nEND OF GRAMMAR DEBUG INFORMATION\n\n");
	 fflush(stdout);

	 ambiguity_count++;

	 selected_left = l;
	 selected_sub = s;
      }
      else {
         /* user -N */
         int r;

	 if (left1 > left2) {
            r = confilter(-annotation, i, last_item+1);

            if (r == 1) {
               /* %short */
               selected_left = left1;
               selected_sub = sub1;
            }
            else if (r == 2) {
               /* %long */
               selected_left = left2;
               selected_sub = sub2;
            }
            else {
               printf("user function `confilter' returns invalid value\n");
               exit(1);
            }
         }
         else {
            r = confilter(-annotation, last_item+1, i);

            if (r == 2) {
               /* %long */
               selected_left = left1;
               selected_sub = sub1;
            }
            else if (r == 1) {
               /* %short */
               selected_left = left2;
               selected_sub = sub2;
            }
            else {
               printf("user function `confilter' returns invalid value\n");
               exit(1);
            }
         }
            
      }

      left[i] = selected_left;
      sub[i] = selected_sub;
   }
}

/*----------------------------------------------------------------------------*/
int disfilter(n1, n2, p1, p2)
   int n1, n2, p1, p2;
/*
 * Called when a disjunctive ambiguity is detected and there are
 * "%disfilter n" annotations instead of "%prio n".
 * p1 and p2 are conflicting items
 * The rule of p1 is labeled with %disfilter n1,
 * the rule of p2 is labeled with %disfilter n2.
 * If the function returns 1, p1 will be selected,
 * if the function returns 2, p2 will be selected,
 */
{
   /* dummy implementation for testing purposes */
   /* should be replaced by user code */
   if (n1 > n2) return 1;
   if (n1 < n2) return 2;
   return 3;
}

int confilter(n, p1, p2)
   int n, p1, p2;
/*
 * Called when a conjunctive ambiguity is detected and there is a
 * "%confilter n" annotation instead of "%long"/"%short".
 * n is the value specified in the annotation.
 * p1 and p2 are conflicting items,
 * where p1 is the item that would be selected if the
 * annotation would be "%short",
 * p2 is the item that would be selected if the
 * annotation would be "%long".
 * If the function returns 1, p1 will be selected ("%short"),
 * if the function returns 2, p2 will be selected ("%long"),
 */
{
   /* dummy implementation for testing purposes */
   /* should be replaced by user code */
   return n;
}
/*----------------------------------------------------------------------------*/

PRIVATE disjunctive_ambiguity(i, d, l, s)
   int i, d, l, s;
/*
 * The item with index i
 * and an item with dot d, leftpointer l, and subpointer s
 * introduce a disjunctive ambiguity
 */
{
   /* Disjunctive Ambiguity */

   int sub1, sub2, rule1, rule2, prio1, prio2;
   int index_a, index_b, tmp;

   sub1 = sub[i];
   sub2 = s;

   prio1 = getprio(sub1);
   index_a = prioindex;
   prio2 = getprio(sub2);
   index_b = prioindex;

   if (prio1 == -1 || prio2 == -1) {
      /* undefined prio */

      printf("\n");
      printf("GRAMMAR DEBUG INFORMATION\n");
      printf("\n");
      printf("Grammar ambiguity detected.\n");
      printf
	 ("Two different ``%s'' derivation trees for the same phrase.\n",
	 yyprintname(yygrammar[d-1]));

      printf("\n");
      printf("TREE 1\n");
      printf("------\n");
      printf("\n");
      print_tree(sub[i]);
      printf("\n");
      printf("TREE 2\n");
      printf("------\n");
      printf("\n");
      print_tree(s);
      printf("\n");

      if (test_for_cycle(s, sub[i])) {
	 /* not possible */
	 printf("Tree 1 contains tree 2 as subtree.\n");
	 printf
	    ("Use %%prio annotation to select the second tree.\n");
	 printf("An annotation selecting the first tree\n");
	 printf("would not resolve the ambiguity.\n");
      }
      else if (test_for_cycle(sub[i], s)) {
	 printf("Tree 2 contains tree 1 as subtree.\n");
	 printf
	    ("Use %%prio annotation to select the first tree.\n");
	 printf("An annotation selecting the second tree\n");
	 printf("would not resolve the ambiguity.\n");
      }
      else {
	 printf("Use %%prio annotation to select an alternative.\n");
      }

      printf("\nEND OF GRAMMAR DEBUG INFORMATION\n\n");


      fflush(stdout);

      ambiguity_count++;
   }
   else if ((prio1 < 0) || (prio2 < 0)) {
      int r;

      r = disfilter(-prio1-1, -prio2-1, sub[i], s);
      if (r == 1) {
         /* use old value */
      } else if (r == 2) {
#if DYNAMICCYCLECHECK
         if (s >= i) {
            if (test_for_cycle(i, s)) {
               printf("\n");
               printf("GRAMMAR DEBUG INFORMATION\n");
               printf("\n");
               printf("Annotation for ``%s'' allows cyclic derivation.\n",
                  yyprintname(yygrammar[d-1]));
               printf("\nEND OF GRAMMAR DEBUG INFORMATION\n\n");
               fflush(stdout);
               tmp = yyannotation[index_a];
               yyannotation[index_a] = yyannotation[index_b];
               yyannotation[index_b] = tmp;
            }
         }
#endif
         sub[i] = s;
      }
      else {
         printf("user function `disfilter' returns invalid value\n");
         exit(1);
      }
   }
   else if (prio1 > prio2) {
   }
   else {
#if DYNAMICCYCLECHECK
      if (s >= i) {
	 if (test_for_cycle(i, s)) {
	    printf("\n");
	    printf("GRAMMAR DEBUG INFORMATION\n");
	    printf("\n");
	    printf("Annotation for ``%s'' allows cyclic derivation.\n",
	       yyprintname(yygrammar[d-1]));
	    printf("\nEND OF GRAMMAR DEBUG INFORMATION\n\n");
	    fflush(stdout);
	    tmp = yyannotation[index_a];
	    yyannotation[index_a] = yyannotation[index_b];
	    yyannotation[index_b] = tmp;
	 }
      }
#endif
      sub[i] = s;
   }
}

/*============================================================================*/
/* EARLEY                                                                     */
/*============================================================================*/

PRIVATE SEARCH(d, b, l, s)
   long d, b, l, s;
/*
 * An item with dot d, backpointer b, leftpointer l, subpointer s
 * has been preliminary added to the current list at position
 * last_item+1 (sentinel)
 * if there is no other item with dot d and backpointer b
 * make this item permanent
 * otherwise, if the old item has a different backpointer/subpointer
 * then an ambiguity is detected
 * if the backpointer/subpointer is the same
 * the new item is already present
 */
{
   register long i;

   i = thislist;

   while ((dot[i]!=d)||(back[i]!=b)) i++;

   if (i==last_item+1) {
      last_item++;
      if (last_item==(ITEMLIMIT-2)) table_full();
#if HASHING
      sethash(d, b);
#endif
   }
   else {

#if DETECTAMBIGUITY
      if (left[i] != l) {
	 conjunctive_ambiguity(i, d, l, s);

      }
      else if (sub[i] != s) {
	 disjunctive_ambiguity(i, d, l, s);
      }
#endif

   }
}

/*----------------------------------------------------------------------------*/

PRIVATE additem ( d, b, l, s)
   long d, b, l, s;
/*
 * add an item with dot d, backpointer b, leftpointer l, and subpointer s
 * to the current item list
 * if there is already an item with dot d and backpointer b
 * then the grammar is ambigous (see 'SEARCH', which actually adds the item)
 *
 * hash optimization:
 * if there is no item with the same hash code for d and b
 * it is not neccessary to invoke SEARCH because the item is unique in the
 * current list
 */
{

   /* sentinel */
   dot [ last_item+1 ] = d;
   back[ last_item+1 ] = b;
   left[ last_item+1 ] = l;
   sub [ last_item+1 ] = s;

#if HASHING
   if (! hashed(d, b)) {
      last_item++; if (last_item==(ITEMLIMIT-2)) table_full();
      sethash(d, b);
   }
   else {
#endif
      SEARCH(d, b, l, s);
#if HASHING
   }
#endif

}

/*----------------------------------------------------------------------------*/

PRIVATE kernel (prevlist)
   long prevlist;
/*
 * compute the kernel of the next item list
 * prevlist points to the previous list
 *
 * KERNEL[i] =
 *    {
 *       < N : alpha yygrammar[i] * beta, B,I,0 >
 *    |
 *       < N : alpha * yygrammar[i] beta, B,_,_ > is in IL[i-1] and has index I
 *    }
 */
{
   long i;
   i = prevlist;
   while (dot[i]) {
      if (ELLIPSIS ?
	 (yygrammar[dot[i]] >= 1 ) :
	 (yygrammar[dot[i]] >= term_base ) )
      {
         if (yygrammar[dot[i]] == sym) {
#if CHECKVIABLE
	    if (is_viable(dot[i]+1) || lookaheadswitchedoff)
#endif
	    {
	       additem(dot[i]+1,back[i],i,0);
	    }
#if CHECKVIABLE
            else {
#if TRACE
               printf("rejected by is_viable (kernel)\n");
#endif
            }
#endif
         }
      }
      i++;
   }
}

/*----------------------------------------------------------------------------*/

PRIVATE predictor (item)
   long item;
/*
 * predictor step for item 'item'
 *
 * PREDICTOR:
 * The dot is before a nonterm
 * add the rules for that nonterm (with the dot at the beginning)
 *
 * If
 *    < N : alpha * M beta, B,L,S >
 * is in IL
 * then add
 *    < M : * gamma, B',0,0 >
 * if there is not yet an an item with the first two components
 * and there is a rule N : gamma
 * B' is a reference to IL[i]
 */
{
   long ruleptr;
  
   ruleptr = yygrammar[dot[item]];
   do {
      int old = last_item;

#if ! LOOKAHEAD
      /* (1) ORIGINAL VERSION */
      additem(ruleptr+1,thislist,0,0);
      if ((back[last_item]==thislist) && (last_item>old)) specialitemadded=1;
#else
      /* (2) IMPROVEMENT
	 add test: is current symbol (lookaheadsym)
	 in director set of that rule ?
      */
         if (lookup_dirset(ruleptr) || lookaheadswitchedoff) {
            additem(ruleptr+1,thislist,0,0);
	    if ((back[last_item]==thislist) && (last_item>old))
	       specialitemadded=1;
	 }
	 else {
	 }
#endif

      ruleptr=yygrammar[ruleptr];

   } while (ruleptr);
}

/*----------------------------------------------------------------------------*/

PRIVATE completer (item)
   long item;
/*
 * completer step for item 'item'
 *
 * COMPLETER
 * The dot is at the end of a rule
 * add the item that triggered this rule to be included
 * where the dot is advanced after the nonterm
 *
 * If
 *    < M : gamma * , B,L,S >
 * is in CL (with index ITEM)
 * and there is an item
 *    < N : alpha * M beta, B',L',S' >
 * in the item list to which the back-pointer B refers (with index I)
 * then add
 *    < N : alpha M * beta, B',I,ITEM >
 * if there is not yet an item with the first two components
 */

{
   long lhs, old;
   register int i;
   int dot_i;
  
   lhs=-yygrammar[dot[item]];
   i=back[item];

   /* loop over all items in earlier item list */
   dot[last_item+1] = 0; /* sentinel */
   while (dot_i = dot[i]) {

      if (yygrammar[/*dot[i]*/dot_i]==lhs) {

#if CHECKVIABLE
	 if (is_viable(/*dot[i]*/dot_i+1) || lookaheadswitchedoff)
#endif
	 {
            old=last_item;
	    additem(/*dot[i]*/dot_i+1,back[i],i,item);
            dot[last_item+1] = 0; /* sentinel */
	    if ((back[i]==thislist) && (last_item>old)) specialitemadded=1;
	 }
#if CHECKVIABLE
         else {
#if TRACE
            printf("rejected by is_viable (completer)\n");
#endif
         }
#endif
      }

      i++;
   }
}

/*----------------------------------------------------------------------------*/

PRIVATE closure ()
/*
 * compute closure for the kernel of the current item list
 *
 * CLOSURE
 * apply PREDICTOR and COMPLETOR
 * as long as there are changes
 */
{
   long i;
   int oldend;

   specialitemadded=0;
   do {
      i=thislist;
      oldend=last_item;
      while (i<=last_item) {
         if (yygrammar[dot[i]]<0) completer(i);
         else if (yygrammar[dot[i]]<term_base) predictor(i);
         i++;
      }
   /*
   } while (specialitemadded && (oldend!=last_item));
   */
   } while ((oldend!=last_item));
}

/*----------------------------------------------------------------------------*/

PRIVATE initial_itemlist()
/*
 * compute initial item list
 * its kernel is given by the item
 *    YYSTART : * UserRoot EOF
 * for which the closure is computed
 *
 */
{
   
#if DYNAMICITEMS
   ITEMLIMIT = ITEMINCR;

   dot = (long *) malloc(ITEMLIMIT* sizeof(long));
   if (! dot) yymallocerror();
   back = (long *) malloc(ITEMLIMIT* sizeof(long));
   if (! back) yymallocerror();
   left = (long *) malloc(ITEMLIMIT* sizeof(long));
   if (! left) yymallocerror();
   sub = (long *) malloc(ITEMLIMIT* sizeof(long));
   if (! sub) yymallocerror();
#endif

  thislist=1;
#if HASHING
  clearhash();
#endif
  additem(2,1,0,0); /*  YYSTART : * UserRoot EOF  */
  closure();
  additem(0,0,0,0); /* terminator */
}


/*----------------------------------------------------------------------------*/

int itemlist_empty;

PRIVATE next_itemlist()
/*
 * compute next item list:
 * kernel and closure
 */
{
   long prevlist;


#if HASHING
   clearhash();
#endif

   itemlist_empty = 0;
   prevlist=thislist;
   thislist=last_item+1;

   kernel(prevlist);
   closure();
   additem(0,0,0,0);
}

/*----------------------------------------------------------------------------*/

PRIVATE itemlist_sequence()
/*
 * compute the sequence of item lists:
 * initial_itemlist
 * and then next_itemlist for each input token
 */
{
#if ERRPOSCORRECTION
   int saved_sym;
   int saved_yypos;
   int saved_thislist;
   int saved_last_item;
   int saved_saved_sym;
   int saved_saved_yypos;
   int saved_saved_thislist;
   int saved_saved_last_item;
   int initial_list;
#endif
   last_item=0;
   initial_itemlist();

#if ERRPOSCORRECTION
   saved_sym = sym;
   saved_yypos = yypos;
   saved_thislist = thislist;
   initial_list = thislist;
   saved_last_item = last_item;
#endif
   do {
      readsym();

#if ERRPOSCORRECTION
      saved_saved_sym = saved_sym;
      saved_saved_yypos = saved_yypos;
      saved_saved_thislist = saved_thislist;
      saved_saved_last_item = saved_last_item;

      saved_sym = sym;
      saved_yypos = yypos;
      saved_thislist = thislist;
      saved_last_item = last_item;
#endif
      next_itemlist();
      if (itemlist_empty) {
         break;
      }
   } while (sym != eofsym);


   if (itemlist_empty) {

#if ERRPOSCORRECTION

      /* switch off lookahead optimization and recompute
       * last item lists
       */

      int p_saved_saved_yypos = saved_saved_yypos;
      int p_saved_yypos = saved_yypos;
      int p_yypos = yypos;
      int p_lookaheadpos = lookaheadpos;

      lookaheadswitchedoff = 1;

      if (saved_thislist == initial_list) {
         thislist = saved_thislist;
         last_item = saved_last_item;
      }
      else {
         thislist = saved_saved_thislist;
         last_item = saved_saved_last_item;
         sym = saved_saved_sym;
         next_itemlist();
         if (itemlist_empty) {
            printf("-1-\n");
            posforerrormsg = p_saved_saved_yypos;
            syntaxerror();
         }
      }

      sym = saved_sym;
      next_itemlist();
      if (itemlist_empty) {
         /*
         printf("-2-\n");
         */
         posforerrormsg = p_saved_saved_yypos;
         syntaxerror();
      }

      sym = lookaheadsym;
      next_itemlist();
      if (itemlist_empty) {
         /*
         printf("-3-\n");
         */
         posforerrormsg = p_saved_yypos;
         syntaxerror();
      }

      printf("PROGRAM ERROR\n"); exit(1);
#else
      syntaxerror();
#endif
   }
}

/*============================================================================*/
/* RETURN LEFTPARSE STEP BY STEP                                              */
/*============================================================================*/

/*
 * when the recognizer has terminated
 * leftpointers and sub pointers represent the parse tree
 * (starting with the item YYSTART : UserRoot EOF * )
 * the function 'yyselect' returns the rule number
 * one after each other in the order of a left derivation
 * as required by the tree walker implemented in yyactions.c
 * it uses a stack to keep track of items that need to be processed later
 */

#define STACKINCR 200
int STACKSIZE;
int *stack;
int stptr = 0;

/*----------------------------------------------------------------------------*/

PRIVATE push(n)
   int n;
/*
 * push item index n onto the stack
 */
{
   if (stptr == STACKSIZE-2) {
      STACKSIZE += STACKINCR;
      stack = (int *) realloc(stack, sizeof(int) * STACKSIZE);
      if (! stack) yymallocerror();
   }
   stack[stptr++] = n;
}

/*----------------------------------------------------------------------------*/

PRIVATE int pop()
/*
 * pop an item index from the stack and return the value
 */
{
   stptr--;
   return stack[stptr];
}

/*----------------------------------------------------------------------------*/

PRIVATE init_stack()
/*
 * Init stack
 * push index of 'item'
 */
{ 
   STACKSIZE = STACKINCR;
   stack = (int *) malloc (sizeof(int) * STACKSIZE);
   if (! stack) yymallocerror();
}

/*----------------------------------------------------------------------------*/

PUBLIC int yyselect()
/*
 * return the next rule number (for the left-derivation)
 *
 * this function is called by the generated tree walker
 *
 * the stack always contains pointers to items that still must be processed
 * to produce a left-derivation
 * the top element must be processed first
 * if the dot appears inside a rule
 *    M : alpha N * beta
 * then the items representing the parse for beta are already on the stack
 * and the items representing alpha N must be pushed
 * they are represented by the sub pointer of the item
 * (corresponding to the parse for N)
 * and the leftpointer of the item
 * (corresponding to the parse for alpha)
 * if the item has the form
 *    M : gamma *
 * (i.e. the rule has been completed)
 * first the items representing gamma are pushed
 * then the rule number is returned
 * subsequent calls will process the items
 * representing gamma
 * 
 */
{
   int i;
   while (1) {
      i = pop();
      if (sub[i])  push(sub[i]);
      if (left[i]) push(left[i]);
      if (yygrammar[dot[i]] < 0 ) {
	    return yygrammar[dot[i]+1];
      }
   }
}


/* parameters to control search space */

int PRINTSOURCETEXT = 0;

int SILENT = 0;
int START_DOLLARS = 10;

#define MAXLENGTH 100

int SELECTION_PERCENTAGE[MAXLENGTH+1];
int SELECTION_MAX[MAXLENGTH+1];
int RANDOMSEARCH[MAXLENGTH+1];

int ITERATE = 0;
int SEARCHLENGTH = MAXLENGTH;
int SEARCH_ALL = 0;
int SEARCH_ONE = 0;
char *to_be_checked;

PRIVATE source[MAXLENGTH+1];

#define MAXVALIDTOKENS 500
int VALID[MAXVALIDTOKENS+1];
int ACTUAL[MAXVALIDTOKENS+1];

#define TICKWIDTH 7
int tick;

int RESOURCES = 0;
int BALANCING = 0;

extern int c_length;



/*----------------------------------------------------------------------------*/


PRIVATE get_list_of_valid_tokens(table, ref_number)
   int table[];
   int *ref_number;
/*
 * store a list of valid tokens in table
 * let *ref_number be the number of valid tokens
 * if an item of the form N : alpha * t beta
 * is in the current item list then t is a valid token
 *
 * as an option a nonterminal may be considered as a token
 */
{
   long count, i, k;

   count = 0;

   i = thislist;
   while (dot[i]) {
      if (ELLIPSIS ?
	 (yygrammar[dot[i]] >= 1 ) :
	 (yygrammar[dot[i]] >= term_base ) )
      {
	 int s;

	 s = yygrammar[dot[i]];
	 table[count+1] = s; /* sentinel */
	 k = 1;
	 while (table[k] != s) {
	    k++;
	 }
	 if (k == count+1) count = k;
	 if (count == MAXVALIDTOKENS) break;
      }
      i++;
   }

   *ref_number = count;
}
/*----------------------------------------------------------------------------*/

PRIVATE set_current_token(tok, n)
   int tok, n;
/*
 * set_current_token (tok, n)
 * defines the variables that were formerly defined by the scanner
 */
{
   sym = tok;
   yypos = n;
}
/*----------------------------------------------------------------------------*/

progress_report(n)
   int n;
{
   tick++;
   fprintf(stderr, "\r");
   if (tick % 1000 == 0) {
      int k;

      for (k = 0; (k < n) && (k < TICKWIDTH); k++) {
	 fprintf(stderr, " %2d/%2d", ACTUAL[k], VALID[k]);
      }
      for (; k < TICKWIDTH; k++) {
	 fprintf(stderr, "      ", ACTUAL[k], VALID[k]);
      }
      if (k < n)
         fprintf(stderr, " ...");
      else
         fprintf(stderr, "    ");
      fprintf(stderr, " [%2d]  %d ex. %d amb.",
         n, tick, ambiguity_count);
   }
}
/*----------------------------------------------------------------------------*/

PRIVATE extend(n, dollars)
   int n;
   int dollars;
/*
 * A phrase of length n has already been constructed
 * Build the possible continuations
 */
{
   int valid_token[MAXVALIDTOKENS+1];
   int number_of_valid_tokens;
   int reset_thislist;
   int reset_last_item;
   int dollar_div;
   int dollar_mod;
   int i;

   if ( (n == SEARCHLENGTH) || (dollars <= 1) )
   {
      if (PRINTSOURCETEXT)
	 print_sourcetext(n-1);
      if (! SILENT)
	 progress_report(n);
      return;
   }

   get_list_of_valid_tokens(valid_token, &number_of_valid_tokens);
   if (number_of_valid_tokens == 0) {
      if (PRINTSOURCETEXT)
	 print_sourcetext(n-1);

      if (! SILENT)
         progress_report(n);
      RESOURCES += dollars-1;
   }
   else {
      if (RANDOMSEARCH[n])
      {
	 {
	    int to_be_selected;
	    int rest;
	    int selected;
	    int k;

	    to_be_selected =
	       (number_of_valid_tokens * SELECTION_PERCENTAGE[n] ) / 100;
	    if (to_be_selected == 0) to_be_selected = 1;
	    if (to_be_selected > SELECTION_MAX[n])
	       to_be_selected = SELECTION_MAX[n];

	    for (k = 1; k <= to_be_selected; k++) {
	       int t;
	       rest = number_of_valid_tokens - k + 1;
	       selected = rand() % rest + k;
	       t = valid_token[k];
	       valid_token[k] = valid_token[selected];
	       valid_token[selected] = t;

	    }
	    number_of_valid_tokens = to_be_selected;

	 }
      }

      reset_thislist = thislist;
      reset_last_item = last_item;


      if (BALANCING) {
	 if (RESOURCES > 0) {
	    dollars += RESOURCES;
	    RESOURCES = 0;
	 }

	 dollar_div = dollars / number_of_valid_tokens;
	 dollar_mod = dollars % number_of_valid_tokens;

	 if (dollar_div == 0) number_of_valid_tokens = dollar_mod;
      }


      VALID[n] = number_of_valid_tokens;

      for (i = 1; i <= number_of_valid_tokens; i++) {

	 int dollar_son;

	 if (BALANCING) {
	    if (i <= dollar_mod)
	       dollar_son = dollar_div+1;
	    else
	       dollar_son = dollar_div;
	 }
	 else
	    dollar_son = 10;

	 ACTUAL[n] = i;
	 set_current_token(valid_token[i], n);
	 source[n] = sym;

	 next_itemlist();

	 extend(n+1, dollar_son);

	 thislist = reset_thislist;
	 last_item = reset_last_item;
      }
   }
}
/*----------------------------------------------------------------------------*/

print_sourcetext(n)
   int n;
{
   int k;

   for (k = 0; k <= n; k++) {
      if (source[k] < term_base)
	 printf(" <%s>", yyprintname(source[k]));
      else if (source[k] == term_base)
	 /* printf(" <EOF>") */;
      else if (source[k] < term_base+max_char+1)
	 printf(" '%c'", source[k]-term_base);
      else
	 printf(" %s", yyprintname(source[k]));
      printf(" ");
   }
   printf("\n");
}
/*----------------------------------------------------------------------------*/

PRIVATE amber()
/*
 * generate and check
 */
{
   last_item=0;
   initial_itemlist();
   tick = 0;
   extend(0, START_DOLLARS);
}

/*----------------------------------------------------------------------------*/


main(argc, argv)
   int argc;
   char **argv;
{

   process_argv(argc, argv);

   /* srand(4711); */

   if (ITERATE) {
      int i = 1;
      while (1) {
	 if (! SILENT)
	    fprintf(stderr, "\n--- ITERATION %d ---\n", i);
         run();
	 i++;
	 iteration++;
      }
   }
   else
      run();

   fprintf(stderr, "\n%d ambiguities detected.\n", ambiguity_count);
   exit(ambiguity_count);
}
/*----------------------------------------------------------------------------*/

run()
{
   if (SEARCH_ALL)
      check_all_nonterms();
   else if (SEARCH_ONE)
      check_nonterm(to_be_checked);
   else {
      amber();
   }
}
/*----------------------------------------------------------------------------*/

check_all_nonterms()
{
   int i;

   yygrammar[2] = 0;
   for (i = STARTUSERGRAMMAR; i <= c_length; i++) {
      if (yygrammar[i] < 0) {
	 if (yygrammar[2] != -yygrammar[i]) {
	    if (! SILENT)
               fprintf(stderr, "\n%d. iteration. ", iteration);
	       fprintf(stderr,
	          "\nchecking %s ...\n", yyprintname(-yygrammar[i]));
	    yygrammar[2] = -yygrammar[i];
	    amber();
	 }
      }
   }
}
/*----------------------------------------------------------------------------*/

check_nonterm(name)
   char *name;
{
   int i;
   for (i = STARTUSERGRAMMAR; i <= c_length; i++) {
      if (yygrammar[i] < 0) {
	 if (strcmp(yyprintname(-yygrammar[i]), name) == 0) {
	    yygrammar[2] = -yygrammar[i];
	    amber();
	    return;
	 }
      }
   }
   fprintf(stderr, "no nonterminal '%s'\n", name);
   exit(1);
}
/*----------------------------------------------------------------------------*/

process_argv(argc, argv)
   int argc;
   char **argv;
{
   int select_all;
   int perc;
   int max;
   int from;
   int enough;
   int i;

   enough = 0;

   from = 1;
   select_all = 1;
   perc = 100;
   max = 9999;

   i = 1;

   while (i <= argc-1) {
      if (strcmp(argv[i], "examples") == 0) {
         i++;
	 START_DOLLARS = get_number(i, argc, argv[i]);
	 BALANCING = 1;
	 enough = 1;
      }
      else if (strcmp(argv[i], "length") == 0) {
         i++;
	 SEARCHLENGTH = get_number(i, argc, argv[i]);
	 if (SEARCHLENGTH > MAXLENGTH)
	  SEARCHLENGTH = MAXLENGTH;
	 enough = 1;
      }
      else if (strcmp(argv[i], "percentage") == 0) {
         i++;
	 perc = get_number(i, argc, argv[i]);
         select_all = 0;
      }
      else if (strcmp(argv[i], "limit") == 0) {
         i++;
	 max = get_number(i, argc, argv[i]);
         select_all = 0;
      }
      else if (strcmp(argv[i], "from") == 0) {
	 int n;

         i++;
	 n = get_number(i, argc, argv[i]);

	 if (n <= from)
	    argerr(i, argv[i], "number too small");
	 fill_group(from, n-1, select_all, perc, max);

	 from = n;
         select_all = 1;
         perc = 100;
         max = 9999;

      }
      else if (strcmp(argv[i], "check") == 0) {
	 SEARCH_ONE = 1;
	 i++;
	 if (i <= argc-1)
	    to_be_checked = argv[i];
	 else
	    err("missing nonterminal after ``check''");
      }
      else if (strcmp(argv[i], "each") == 0) {
	 SEARCH_ALL = 1;
      }
      else if (strcmp(argv[i], "iterate") == 0) {
	 ITERATE = 1;
      }
      else if (strcmp(argv[i], "ellipsis") == 0) {
	 ELLIPSIS = 1;
      }
      else if (strcmp(argv[i], "source") == 0) {
	 PRINTSOURCETEXT = 1;
      }
      else if (strcmp(argv[i], "silent") == 0) {
	 SILENT = 1;
      }
      else
         argerr(i, argv[i], "invalid argument name");

      i++;
   }
   if (! enough)
      err ("at least ``examples n'' or ``length n'' must be specified");

   fill_group(from, SEARCHLENGTH, select_all, perc, max);
}
/*----------------------------------------------------------------------------*/

int get_number(i, argc, str)
   int i;
   char *str;
{
   int p, n;

   if (i >= argc) err("number missing after last argument");

   p = 0;
   while (('0' <= str[p]) && (str[p] <= '9')) {
      p++;
   }
   if ((p == 0) || (str[p] != '\0'))
      argerr(i, str, "invalid number");
   return atoi(str);
}
/*----------------------------------------------------------------------------*/

fill_group(lwb, upb, select_all, perc, max)
   int lwb, upb, select_all, perc, max;
{
   int k;

   for (k = lwb-1; k <= upb; k++) {
      RANDOMSEARCH[k] = ! select_all;
      SELECTION_PERCENTAGE[k] = perc;
      SELECTION_MAX[k] = max;
   }
}
/*----------------------------------------------------------------------------*/

argerr(n, arg, msg)
   int n;
   char *arg;
   char *msg;
{
   fprintf(stderr, "argument %d (%s) : %s\n", n, arg, msg);
   exit(1);
}
/*----------------------------------------------------------------------------*/

err(msg)
   char *msg;
{
   fprintf(stderr, "error: %s\n", msg);
   exit(1);
}
/*================================================================ THE END ===*/
