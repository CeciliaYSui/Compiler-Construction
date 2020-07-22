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
               ; 


%%

int yyerror(const char * msg) {
   printf("%s \n", msg); 
   printf("Called yyerror()\n");
   return  0;
}
