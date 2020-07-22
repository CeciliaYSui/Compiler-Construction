%{

/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Course ---------------- Compiler Construction
 * Filename -------------- Slic_parser.y
 * Date of Submission ---- October 20, 2019
 * Assignment ------------ Checkpoint #4  
 * Description ----------- bison parser for SLIC data section 
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

%%

/* ------------------------------------- Grammar Rules ------------------------------------- */ 

/* ------------------------ Main Program ------------------------ */ 

program        : MAIN SEMICOLON data algorithm END MAIN SEMICOLON 
               ; 

/* ------------------------ Data Section ------------------------ */ 

data           : DATA COLON fulldeclaration 
               ; 

fulldeclaration : declaration{}
               |  declaration fulldeclaration 
               | /* empty to allow empty declaration */ 
               ; 

declaration    : datatype COLON varlist SEMICOLON 

datatype       : REAL 
               | INTEGER
               ; 

varlist        : item 
               | item COMMA varlist 
               | /* empty to allow empty varlist */ 
               ; 

item           : VARIABLE 
               | VARIABLE LBRACKET INTCONSTANT RBRACKET 
               ; 

/* ------------------------ Algorithm Section ------------------------ */ 

algorithm      : ALGORITHM COLON body
               ; 

body           : /* empty to allow empty body */ 
               ; 


%%

int yyerror() {
   printf("Called yyerror()\n");
   return  0;
}
