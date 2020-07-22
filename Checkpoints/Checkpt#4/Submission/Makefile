a.out: Slic_parser.y Slic_scanner.l main.c
	bison -y -d Slic_parser.y
	flex Slic_scanner.l
	gcc lex.yy.c y.tab.c main.c -ll

clean: 
	rm -f a.out a.exe lex.yy.c y.tab.c y.tab.h 