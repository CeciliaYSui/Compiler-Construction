%{
/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Course ---------------- Compiler Construction
 * Filename -------------- parser.y
 * Date of Submission ---- December 3, 2019
 * Assignment ------------ Checkpoint #8 
 * Description ----------- Fully implemented parser 
 *
 * Warning --------------- Modulus operator not working
 * ----------------------- Counting loops not working 
 * ========================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "AST.h" 
#include "ST.h"

int yyerror();
int yylex();
int yyparse(); 

Type currType; 
Node *root; 

%}


/* C union declaration */ 
%union {
   int intval; 
   float realval; 
   char *sval;
   Node *node; 
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

/* Declare Types */
%type <node> algorithm
%type <node> body
%type <node> statement
%type <node> assignment
%type <node> countup
%type <node> countdown
%type <node> ifstatement
%type <node> ifesle
%type <node> whileloop
%type <node> read
%type <node> print
%type <node> printlist
%type <node> printitem
%type <node> exit
%type <node> fullexpression
%type <node> comparison
%type <node> expression
%type <node> term
%type <node> factor
%type <node> atom
%type <node> variable

/* Declare start variable */
%start program

%%

/* ------------------------------------- Grammar Rules ------------------------------------- */ 

/* ------------------------ Main Program ------------------------ */ 

program        : MAIN SEMICOLON data algorithm END MAIN SEMICOLON { root = $4; }
               ; 

/* ------------------------ Data Section ------------------------ */ 

data           : DATA COLON fulldeclaration 
               | DATA COLON 
               ; 

fulldeclaration : declaration
               |  declaration fulldeclaration 
               ; 

declaration    : datatype COLON varlist SEMICOLON 

datatype       : REAL { currType = TYPE_REAL; }
               | INTEGER { currType = TYPE_INT; }
               ; 

varlist        : item 
               | item COMMA varlist 
               | /* empty */ 
               ; 

item           : VARIABLE { if (STLookup($1)!=NULL) { 
                                 yyerror("Duplicate Declaration! "); 
                                 YYERROR; 
                            }
                            else {
                                 STInsert(currType, $1, 1, 0); 
                                 } 
                           }
               | VARIABLE LBRACKET INTCONSTANT RBRACKET { if (STLookup($1) != NULL) {
                                                               yyerror("Duplicate Declaration! ");
                                                               YYERROR; 
                                                         }
                                                         else {STInsert(currType, $1, $3, 1);}
                                                         }
               ; 

/* ------------------------ Algorithm Section ------------------------ */ 

algorithm      : ALGORITHM COLON body { $$ = $3; 
                                        STInsert(TYPE_INT, "$aMod", 1, 0); 
                                        STInsert(TYPE_INT, "$bMod", 1, 0); }
               ; 

body           : statement body { $$ = $1; 
                                  $$->next = $2; }
               | /* empty */    {$$ = NULL; }
               ; 

statement      : assignment { $$ = $1; }
               | countup { $$ = $1; }
               | countdown { $$ = $1; }
               | ifstatement { $$ = $1; }
               | ifesle { $$ = $1; }
               | whileloop { $$ = $1; }
               | read { $$ = $1; }
               | print { $$ = $1; }
               | exit { $$ = $1; }
               ; 

assignment     : variable ASSIGN fullexpression SEMICOLON { $$ = (Node *)malloc(sizeof(Node)); 
                                                            $$->left = $1; 
                                                            $$->right = $3; 
                                                            $$->kind = ASSIGNMENT_OP; }
               ; 


ifstatement    : IF fullexpression SEMICOLON body END IF SEMICOLON { $$ = (Node *)malloc(sizeof(Node)); 
                                                                     $$->left = $2; 
                                                                     $$->right = $4; 
                                                                     $$->kind = IF_OP;}
               ; 

ifesle         : IF fullexpression SEMICOLON body ELSE SEMICOLON body END IF SEMICOLON { $$ = (Node *)malloc(sizeof(Node)); 
                                                                                         $$->left = $2; 
                                                                                         $$->right = $4; 
                                                                                         $$->ifelse = $7; 
                                                                                         $$->kind = IFELSE_OP;}
               ; 

whileloop      : WHILE fullexpression SEMICOLON body END WHILE SEMICOLON { $$ = (Node *)malloc(sizeof(Node)); 
                                                                           $$->left = $2; 
                                                                           $$->right = $4; 
                                                                           $$->kind = WHILE_OP;}
               ; 

countup        : COUNTING variable UPWARD fullexpression TO fullexpression SEMICOLON body END COUNTING SEMICOLON{ 
                           $$ = (Node *)malloc(sizeof(Node)); 
                           $$->left = $2; 
                           $$->cnt1 = $4; 
                           $$->cnt2 = $6; 
                           $$->right = $8; 
                           $$->kind = COUNTUP_OP; }
               ; 

countdown      : COUNTING variable DOWNWARD fullexpression TO fullexpression SEMICOLON body END COUNTING SEMICOLON{
                           $$ = (Node *)malloc(sizeof(Node)); 
                           $$->left = $2; 
                           $$->cnt1 = $4; 
                           $$->cnt2 = $6; 
                           $$->right = $8; 
                           $$->kind = COUNTDOWN_OP; }
               ; 

/* ------------------------ read & print & exit ------------------------ */ 

exit           : EXIT SEMICOLON { $$ = (Node *)malloc(sizeof(Node)); 
                                  $$->kind = EXIT_OP; }
               ; 

read           : READ variable SEMICOLON { $$ = (Node *)malloc(sizeof(Node)); 
                                           $$->left = $2; 
                                           $$->kind = READ_OP; }
               ; 

print          : PRINT printlist SEMICOLON { $$ = (Node *)malloc(sizeof(Node)); 
                                             $$->left = $2; 
                                             $$->kind = PRINT_OP; }
               ; 

printlist      : printitem { $$ = $1; }
               | printitem COMMA printlist { $$ = $1; 
                                             $$->next = $3; }
               ; 
      
printitem      : fullexpression { $$ = $1; }
               | STRING { $$ = (Node *)malloc(sizeof(Node)); 
                          $$->sval = $1; 
                          $$->kind = LITERAL_STRING; }
               | CARRIAGERETURN { $$ = (Node *)malloc(sizeof(Node)); 
                                  $$->kind = NEWLINE_OP; }
               ; 

/* ------------------------ variable --> fullexpression ------------------------ */ 

fullexpression : comparison { $$ = $1; }
               | NOT fullexpression { $$ = (Node *)malloc(sizeof(Node));
                                      $$->left = $2; 
                                      $$->kind = NOT_OP; }
               | comparison AND fullexpression { $$ = (Node *)malloc(sizeof(Node));
                                                 $$->left = $3;
                                                 $$->right = $1; 
                                                 $$->kind = AND_OP; } 
               | comparison OR fullexpression { $$ = (Node *)malloc(sizeof(Node));
                                                $$->left = $3; 
                                                $$->right = $1; 
                                                $$->kind = OR_OP; }
               ; 

comparison     : expression { $$ = $1; }
               | comparison LESSTHAN expression { $$ = (Node *)malloc(sizeof(Node));
                                                  $$->left = $1;  
                                                  $$->right = $3; 
                                                  $$->kind = LESS_OP; }
               | comparison GREATERTHAN expression { $$ = (Node *)malloc(sizeof(Node)); 
                                                     $$->left = $1;  
                                                     $$->right = $3; 
                                                     $$->kind = GREATER_OP; }
               | comparison LESSOREQUAL expression { $$ = (Node *)malloc(sizeof(Node)); 
                                                     $$->left = $1;  
                                                     $$->right = $3; 
                                                     $$->kind = LESSOREQUAL_OP; }
               | comparison GREATEROREQUAL expression { $$ = (Node *)malloc(sizeof(Node)); 
                                                        $$->left = $1;  
                                                        $$->right = $3; 
                                                        $$->kind = GREATEROREQUAL_OP; }
               | comparison EQUAL expression { $$ = (Node *)malloc(sizeof(Node)); 
                                               $$->left = $1;  
                                               $$->right = $3; 
                                               $$->kind = EQUAL_OP; }
               | comparison NOTEQUAL expression { $$ = (Node *)malloc(sizeof(Node));
                                                  $$->left = $1;  
                                                  $$->right = $3; 
                                                  $$->kind = NOTEQUAL_OP; }
               ; 

expression     : term { $$ = $1; }
               | expression ADDITION term { $$ = (Node *)malloc(sizeof(Node));
                                            $$->left = $1; 
                                            $$->right = $3; 
                                            $$->kind = ADDITION_OP; }
               | expression SUBTRACTION term { $$ = (Node *)malloc(sizeof(Node));
                                               $$->left = $1; 
                                               $$->right = $3; 
                                               $$->kind = SUBTRACTION_OP; }
               | SUBTRACTION term { $$ = (Node *)malloc(sizeof(Node));
                                    $$->left = $2; 
                                    $$->kind = UMINUS_OP; }
               ;

term           : factor { $$ = $1; }
               | term MULTIPLICATION factor { $$ = (Node *)malloc(sizeof(Node)); 
                                              $$->left = $1; 
                                              $$->right = $3; 
                                              $$->kind = MULTIPLICATION_OP; } 
               | term DIVISION factor { $$ = (Node *)malloc(sizeof(Node)); 
                                        $$->left = $1; 
                                        $$->right = $3; 
                                        $$->kind = DIVISION_OP; }
               | term MODULUS factor { $$ = (Node *)malloc(sizeof(Node)); 
                                       $$->left = $1; 
                                       $$->right = $3; 
                                       $$->kind = MODULUS_OP; }
               ;

factor         : atom { $$ = $1; }
               | LPARENTH fullexpression RPARENTH { $$ = $2; }
               ;

atom           : variable { $$ = $1; }
               | INTCONSTANT { $$ = (Node *)malloc(sizeof(Node));
                               $$->intval = $1; 
                               $$->kind = LITERAL_INT; 
                               $$->dtype = TYPE_INT; }
               | REALCONSTANT { $$ = (Node *)malloc(sizeof(Node));
                                $$->realval = $1; 
                                $$->kind = LITERAL_REAL; 
                                $$->dtype = TYPE_REAL; }
               ; 

variable       : VARIABLE { $$ = (Node *)malloc(sizeof(Node));
                            $$->sval = $1; 
                            $$->kind = VARIABLE_OP; }
               | VARIABLE LBRACKET fullexpression RBRACKET { $$ = (Node *)malloc(sizeof(Node)); 
                                                             $$->sval = $1; 
                                                             $$->left = $3; 
                                                             $$->kind = VARIABLE_OP; }
               ;


%%

int yyerror(const char * msg) {
   printf("%s \n", msg); 
   printf("Called yyerror()\n");
   return  0;
}
