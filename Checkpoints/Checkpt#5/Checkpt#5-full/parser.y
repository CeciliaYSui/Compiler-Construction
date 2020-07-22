%{
/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Course ---------------- Compiler Construction
 * Filename -------------- parser.y
 * Date of Submission ---- October 28, 2019
 * Assignment ------------ Checkpoint #5 
 * Description ----------- Add action code to build a symbol table 
 * ========================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ST.h"
 
int yyerror();
int yylex();
int yyparse(); 

Type currType; 

%}


/* C union declaration */ 
%union {
   int intval; 
   float realval; 
   char *sval;
}


/* Declare Tokens */
%token ADDITION 
%token SUBTRACTION 
%token MULTIPLICATION 
%token DIVISION 
%token MODULUS
%token LESSTHAN 
%token GREATERTHAN 
%token LESSOREQUAL 
%token GREATEROREQUAL 
%token EQUAL 
%token NOTEQUAL
%token AND 
%token OR 
%token NOT 
%token LPARENTH 
%token RPARENTH
%token LBRACKET 
%token RBRACKET
%token SEMICOLON
%token COLON
%token COMMA 
%token ASSIGN 
%token CARRIAGERETURN
%token MAIN
%token END
%token EXIT
%token IF 
%token ELSE
%token WHILE
%token TO
%token COUNTING 
%token UPWARD 
%token DOWNWARD
%token REAL 
%token INTEGER
%token DATA 
%token ALGORITHM
%token READ 
%token PRINT
%token <sval>     VARIABLE 
%token <sval>     STRING
%token <intval>   INTCONSTANT
%token <realval>  REALCONSTANT
%token NEWLINE
%token TRASH

%start program



%%

/* ------------------------------------- Grammar Rules ------------------------------------- */ 

/* ------------------------ Main Program ------------------------ */ 

program        : MAIN SEMICOLON data algorithm END MAIN SEMICOLON {}
               ; 

/* ------------------------ Data Section ------------------------ */ 

data           : DATA COLON fulldeclaration {}
               ; 

fulldeclaration : declaration{}
               |  declaration fulldeclaration 
               | /* empty to allow empty declaration */ 
               ; 

declaration    : datatype COLON varlist SEMICOLON 

datatype       : REAL { currType = TYPE_REAL; }
               | INTEGER { currType = TYPE_INT; }
               ; 

varlist        : item {}
               | item COMMA varlist {}
               | /* empty to allow empty varlist */ 
               ; 

item           : VARIABLE { STInsert(currType, $1, 1, 0); }
               | VARIABLE LBRACKET INTCONSTANT RBRACKET {STInsert(currType, $1, $3, 1);}
               ; 

/* ------------------------ Algorithm Section ------------------------ */ 

algorithm      : ALGORITHM COLON body {}
               ; 

body           : /* empty */ {}
               | statement body {}
               ; 

statement      : assignment {}
               | counting {}
               | ifstatement {}
               | ifesle {}
               | whileloop {}
               | read {}
               | print {}
               | exit {}
               ; 

assignment     : variable ASSIGN fullexpression SEMICOLON {}
               ; 

exit           : EXIT SEMICOLON {}
               ; 

/* ------------------------ control structures ------------------------ */ 

counting       : COUNTING variable UPWARD fullexpression TO fullexpression SEMICOLON body END COUNTING SEMICOLON{}
               | COUNTING variable DOWNWARD fullexpression TO fullexpression SEMICOLON body END COUNTING SEMICOLON{}
               ; 

ifstatement    : IF fullexpression SEMICOLON body END IF SEMICOLON {}
               ; 

ifesle         : IF fullexpression SEMICOLON body ELSE SEMICOLON body END IF SEMICOLON {}
               ; 

whileloop      : WHILE fullexpression SEMICOLON body END WHILE SEMICOLON {}
               ; 

/* ------------------------ variable --> fullexpression ------------------------ */ 

fullexpression : comparison {}
               | NOT fullexpression {}
               | fullexpression AND comparison {}
               | fullexpression OR comparison {}
               ; 

comparison     : expression {}
               | comparison LESSTHAN expression {}
               | comparison GREATERTHAN expression {}
               | comparison LESSOREQUAL expression {}
               | comparison GREATEROREQUAL expression {}
               | comparison EQUAL expression {}
               | comparison NOTEQUAL expression {}
               ; 

expression     : term {}
               | expression ADDITION term {}
               | expression SUBTRACTION term {}
               ;

term           : factor {}
               | term MULTIPLICATION factor {}
               | term DIVISION factor {}
               | term MODULUS factor {}
               ;

factor         : atom {}
               | LPARENTH expression RPARENTH {}
               | SUBTRACTION factor { /* used for unary minus */ }
               ;

atom           : variable {}
               | INTCONSTANT {}
               | REALCONSTANT {}
               ; 

variable       : VARIABLE {} 
               | VARIABLE LBRACKET expression RBRACKET {} 
               ;

/* ------------------------ read & print ------------------------ */ 

read           : READ variable SEMICOLON {}
               ; 

print          : PRINT printlist SEMICOLON {}
               ; 

printlist      : printitem {}
               | printitem COMMA printlist {}
               ; 
      
printitem      : fullexpression {}
               | STRING {}
               | CARRIAGERETURN {}
               ; 

%%

int yyerror(const char * msg) {
   printf("%s \n", msg); 
   printf("Called yyerror()\n");
   return  0;
}
