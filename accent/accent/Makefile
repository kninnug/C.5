CC=gcc
CFLAGS=-O3
OBJECTS=actions.o ana.o auxil.o bnf.o code.o encode.o flatten.o \
        yylex.o verbose.o lexinfo.o main.o output.o sets.o yytab.o \
        idents.o errmsg.o strings.o grts.o

accent: ${OBJECTS}
	${CC} -o accent ${OBJECTS}
clean:
	rm -f *~
	rm -f *.o
