Java:
	bison -dv parser1.y; \
	flex scanner1.l; \
	g++ lex.yy.c parser1.tab.c -o parser1; \
	bison -dv parser2.y; \
	flex scanner2.l; \
	g++ lex.yy.c parser2.tab.c -o parser2

clean:
	rm -rf lex.yy.c parser.tab.c parser.tab.h parser graph.ps output.dot parser.output
	rm -rf lex.yy.c parser1.tab.c parser1.tab.h parser1 parser1.output
	rm -rf lex.yy.c parser2.tab.c parser2.tab.h parser2 parser2.output