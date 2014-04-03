#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct identifier{
  char* lexeme;
  struct identifier * next;

} identifier;


typedef struct stack{
  identifier * symboltable[100];
  struct stack * next;
} stack;


stack * symbols = NULL;

unsigned int PJWHash(char* str, unsigned int len)
{
   const unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
   const unsigned int ThreeQuarters     = (unsigned int)((BitsInUnsignedInt  * 3) / 4);
   const unsigned int OneEighth         = (unsigned int)(BitsInUnsignedInt / 8);
   const unsigned int HighBits          = (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
   unsigned int hash              = 0;
   unsigned int test              = 0;
   unsigned int i                 = 0;

   for(i = 0; i < len; str++, i++)
   {
      hash = (hash << OneEighth) + (*str);

      if((test = hash & HighBits)  != 0)
      {
         hash = (( hash ^ (test >> ThreeQuarters)) & (~HighBits));
      }
   }

   return hash;
}
/* End Of  P. J. Weinberger Hash Function */


stack * newStack(){

  int i;

  stack * s = malloc(sizeof(stack));
  for(i=0;i < 100;i++) s->symboltable[i] = NULL;
  s->next = symbols;
  symbols = s;

  return s;
  
}

identifier* addSymbol(char * in){

  identifier * id = malloc(sizeof(identifier));
  id->lexeme = in;
  id->next = NULL;

  return id;

}

identifier * addToTable(char * in){

  identifier ** symboltable = symbols->symboltable, **lexemeAt, *current;

  size_t len = strlen(in);
  int hash = PJWHash(in, len);
  lexemeAt = &symboltable[hash % 100]; 
  if(*lexemeAt == NULL){
    *lexemeAt = addSymbol(in);
    return *lexemeAt;
  }

  current = *lexemeAt;
  while(current->next != NULL){
    if(strcmp(current->lexeme, in) == 0) return current;
    current = current->next;

  }

  return current->next = addSymbol(in);
}

identifier * lookupTable(char * in, stack * s){

  identifier * lexemeAt;

  size_t len = strlen(in);
  int hash = PJWHash(in, len);
  
  if (s == NULL) return NULL;

  lexemeAt = s->symboltable[hash % 100]; 

  if(lexemeAt == NULL) return lookupTable(in,s->next);

  while(lexemeAt->next != NULL){
    if(strcmp(lexemeAt->lexeme, in) == 0) return lexemeAt;
    lexemeAt = lexemeAt->next;
  
  }
  return lookupTable(in,s->next);

}


void printTable(){

  stack * current;
  int i, depth = 0;
  char * lex;
  identifier * id;

  if(symbols == NULL){
    printf("Nothing");
    return;
  }

  current = symbols;
  while(current != NULL){
    printf("%d\n",depth);
    for(i=0;i<100;i++){
      id = current->symboltable[i];
      lex = (id == NULL) ? "Empty" : id->lexeme;
      printf("%d %s\n",i,lex);

    }
    current = current->next;
    depth++;
  }

}

int main(int argc, char ** args){

  printTable();

  newStack();

  addToTable("First insert"); printf("done;\n");
  addToTable("Second insert");printf("done;\n");
 
  printTable();

 newStack();printf("done;\n");
  addToTable("Second First insert");printf("done;\n");
  lookupTable("First insert", symbols);printf("done;\n");
  lookupTable("Second First insert",symbols);printf("done;\n");

  printTable();

  return 0;



}
