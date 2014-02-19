ACCENT=../accent/accent
ENTIRE=../entire/entire.c
LEX=flex
CC=gcc

calculator: spec.acc
	${ACCENT} spec.acc
	${LEX} spec.lex
	${CC} -o calculator yygrammar.c lex.yy.c auxil.c ${ENTIRE}
clean:
	rm -f *~
	rm -f *.o

demo:   calculator
	./calculator < input
