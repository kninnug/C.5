OPTIONS = -ansi -ggdb
# Needed because flex and it's library is installed in MSYS, not MinGW
MINGWHACKS = -L/usr/lib -DYY_NO_UNISTD_H
ACCENTDIR = accent/

all: ass2

ass1: lex.yy.c
	gcc $(OPTIONS) $(MINGWHACKS) -o ass1 lex.yy.c -lfl

lex.yy.c: ass1.flex
	flex ass1.flex
	
ass2: ass2.acc ass2.yy.c yygrammar.o auxil.o entire.o
	gcc $(OPTIONS) $(MINGWHACKS) -o ass2 ass2.yy.c yygrammar.o auxil.o entire.o -lfl
	
ass2.yy.c: ass2.flex yygrammar.c
	flex -o ass2.yy.c ass2.flex
	
yygrammar.c: ass2.acc
	$(ACCENTDIR)/accent/accent ass2.acc

yygrammar.o: yygrammar.c
	gcc $(OPTIONS) $(MINGWHACKS) -c yygrammar.c

auxil.o:
	gcc $(OPTIONS) $(MINGWHACKS) -c auxil.c
	
entire.o: $(ACCENTDIR)/entire/entire.c
	gcc $(OPTIONS) $(MINGWHACKS) -c $(ACCENTDIR)/entire/entire.c
	
clean:
	rm -rf *.o
	rm -rf *.exe
	rm -rf *.synctex.gz
	rm -rf *.pdf
	rm -rf *.dvi
	rm -rf *.aux
	rm -rf *.log
	rm -rf yygrammar.h
	rm -rf yygrammar.c
	rm -rf *.yy.c