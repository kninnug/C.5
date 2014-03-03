OPTIONS = -Wall -pedantic -ansi
# Needed because flex and it's library is installed in MSYS, not MinGW
MINGWHACKS = -L/usr/lib -DYY_NO_UNISTD_H

all: ass1

ass1: lex.yy.c
	gcc $(OPTIONS) $(MINGWHACKS) -o ass1 lex.yy.c -lfl

lex.yy.c: ass1.flex
	flex ass1.flex

ass2: ass2.y
	accent/accent/accent ass2.acc
	flex -o ass2.yy.c ass2.flex
	gcc $(OPTIONS) $(MINGWHACKS) -o ass2 ass2.yy.c yygrammar.c parser.c accent/entire/entire.c -lfl
