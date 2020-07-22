a.out: parser.y scanner.l ST.c codegen.c main.c
	bison -y -d -v parser.y
	flex scanner.l
	gcc lex.yy.c y.tab.c ST.c codegen.c main.c -ll

clean: 
	rm -f a.out a.exe lex.yy.c y.tab.c y.tab.h y.output