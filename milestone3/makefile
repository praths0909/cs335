Java:
	bison -dv parser.y; \
	flex scanner.l; \
	g++ lex.yy.c parser.tab.c -o parser; 
	

clean:
	rm -rf lex.yy.c parser.tab.c parser.tab.h parser parser.output symboltable.csv output.3ac
	