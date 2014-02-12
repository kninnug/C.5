OPTIONS = -Wall -pedantic -ansi
# Needed because flex and it's library is installed in MSYS, not MinGW
MINGWHACKS = -L/usr/lib -DYY_NO_UNISTD_H

all: ass1

ass1: lex.yy.c
	gcc $(OPTIONS) $(MINGWHACKS) -o ass1 lex.yy.c -lfl

lex.yy.c: ass1.flex
	flex ass1.flex