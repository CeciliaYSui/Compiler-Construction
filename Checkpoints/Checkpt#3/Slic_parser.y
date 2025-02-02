%{

/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Course ---------------- Compiler Construction
 * Filename -------------- Slic_parser.y
 * Date of Submission ---- October 7, 2019
 * Assignment ------------ Checkpoint #3 SLIC Context-Free Grammar 
 * Description ----------- Using bison to write a SLIC parser 
 * ========================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int yyerror();
int yylex();

%}

/* C union declaration */ 
%union {
   int intval; 
   float realval; 
   char *sval;
}

/* Declare Tokens */
%token ADDITION SUBTRACTION MULTIPLICATION DIVISION MODULUS
%token LESSTHAN GREATERTHAN LESSOREQUAL GREATEROREQUAL EQUAL NOTEQUAL
%token AND OR NOT 
%token LPARENTH RPARENTH
%token LBRACKET RBRACKET
%token SEMICOLON
%token COLON
%token COMMA 
%token ASSIGN 
%token CARRIAGERETURN
%token MAIN
%token END
%token EXIT
%token IF ELSE
%token WHILE
%token TO
%token COUNTING UPWARD DOWNWARD
%token REAL INTEGER
%token DATA ALGORITHM
%token READ PRINT
%token <sval>     VARIABLE 
%token <sval>     STRING
%token <intval>   INTCONSTANT
%token <realval>  REALCONSTANT
%token NEWLINE
%token WHITESPACE
%token TRASH

%%

/* ------------------------------------- Grammar Rules ------------------------------------- */ 

/* ------------------------ Main Program ------------------------ */ 

program        : MAIN SEMICOLON data algorithm END MAIN SEMICOLON {}
               ; 

/* ------------------------ Data Section ------------------------ */ 

data           : DATA COLON fulldeclaration {}
               ; 

fulldeclaration : declaration{}
               | declaration fulldeclaration {}
               ; 

declaration    : REAL COLON varlist SEMICOLON {}
               | INTEGER COLON varlist SEMICOLON {}
               ; 

varlist        : arrayvar {}
               | arrayvar COMMA varlist {}
               ; 

arrayvar       : VARIABLE {}
               | VARIABLE LBRACKET INTCONSTANT RBRACKET {}
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

counting       : COUNTING variable UPWARD fullexpression TO fullexpression SEMICOLON body END COUNTING {}
               | COUNTING variable DOWNWARD fullexpression TO fullexpression SEMICOLON body END COUNTING {}
               ; 

ifstatement    : IF fullexpression SEMICOLON body END IF SEMICOLON {}
               | IF fullexpression SEMICOLON body ELSE SEMICOLON body END IF SEMICOLON {}
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

assignment     : VARIABLE ASSIGN fullexpression {}
               ; 

%%

int yyerror() {
   printf("Called yyerror()\n");
   return  0;
}