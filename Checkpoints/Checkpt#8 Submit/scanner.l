%{
/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Filename -------------- scanner.l
 * Assignment ------------ Checkpoint #8
 * Date of Submission ---- December 3, 2019
 * Description ----------- Use flex to write a scanner for SLIC
 * ========================================================================
 */

#include <stdio.h>
#include <string.h>
#include "ST.h"
#include "AST.h"
#include "y.tab.h"
#define DEBUG 0

%}

%%

#.*                         { if (DEBUG) printf("COMMENT:      %s\n", yytext); }

"+"                         { if (DEBUG) printf("ADDITION:     %s\n", yytext);
                              return(ADDITION); }

"-"                         { if (DEBUG) printf("SUBTRACTION:  %s\n", yytext);
                              return(SUBTRACTION); }

"*"                         { if (DEBUG) printf("MULTIPLICATION: %s\n", yytext);
                              return(MULTIPLICATION); }

"/"                         { if (DEBUG) printf("DIVISION:     %s\n", yytext);
                              return(DIVISION); }

"%"                         { if (DEBUG) printf("MODULUS:      %s\n", yytext);
                              return(MODULUS); }

"<"                         { if (DEBUG) printf("LESSTHAN:     %s\n", yytext);
                              return(LESSTHAN); }

">"                         { if (DEBUG) printf("GREATERTHAN:  %s\n", yytext);
                              return(GREATERTHAN); }

"<="                        { if (DEBUG) printf("LESSOREQUAL:  %s\n", yytext);
                              return(LESSOREQUAL); }

">="                        { if (DEBUG) printf("GREATEROREQUAL: %s\n", yytext);
                              return(GREATEROREQUAL); }

"="                         { if (DEBUG) printf("EQUAL:        %s\n", yytext);
                              return(EQUAL); }

"<>"                        { if (DEBUG) printf("NOTEQUAL:     %s\n", yytext);
                              return(NOTEQUAL); }

"&"                         { if (DEBUG) printf("AND:          %s\n", yytext);
                              return(AND); }

"|"                         { if (DEBUG) printf("OR:           %s\n", yytext);
                              return(OR); }

"~"                         { if (DEBUG) printf("NOT:          %s\n", yytext);
                              return(NOT); }

"("                         { if (DEBUG) printf("LPARENTH:     %s\n", yytext);
                              return(LPARENTH); }

")"                         { if (DEBUG) printf("RPARENTH:     %s\n", yytext);
                              return(RPARENTH); }

"["                         { if (DEBUG) printf("LBRACKET:     %s\n", yytext);
                              return(LBRACKET); }

"]"                         { if (DEBUG) printf("RBRACKET:     %s\n", yytext);
                              return(RBRACKET); }

";"                         { if (DEBUG) printf("SEMICOLON:    %s\n", yytext);
                              return(SEMICOLON); }

":"                         { if (DEBUG) printf("COLON:        %s\n", yytext);
                              return(COLON); }

","                         { if (DEBUG) printf("COMMA:        %s\n", yytext);
                              return(COMMA); }

":="                        { if (DEBUG) printf("ASSIGN:       %s\n", yytext);
                              return(ASSIGN); }

"!"                         { if (DEBUG) printf("CARRIAGERETURN: %s\n", yytext);
                              return(CARRIAGERETURN); }

[mM][aA][iI][nN]                                { if (DEBUG) printf("MAIN:         %s\n", yytext);
                                                  return(MAIN); }

[eE][nN][dD]                                    { if (DEBUG) printf("END:          %s\n", yytext);
                                                  return(END); }

[eE][xX][iI][tT]                                { if (DEBUG) printf("EXIT:         %s\n", yytext);
                                                  return(EXIT); }

[iI][fF]                                        { if (DEBUG) printf("IF:           %s\n", yytext);
                                                  return(IF); }

[eE][lL][sS][eE]                                { if (DEBUG) printf("ELSE:         %s\n", yytext);
                                                  return(ELSE); }

[wW][hH][iI][lL][eE]                            { if (DEBUG) printf("WHILE:        %s\n", yytext);
                                                  return(WHILE); }

[tT][oO]                                        { if (DEBUG) printf("TO:           %s\n", yytext);
                                                  return(TO); }

[cC][oO][uU][nN][tT][iI][nN][gG]                { if (DEBUG) printf("COUNTING:     %s\n", yytext);
                                                  return(COUNTING); }

[uU][pP][wW][aA][rR][dD]                        { if (DEBUG) printf("UPWARD:       %s\n", yytext);
                                                  return(UPWARD); }

[dD][oO][wW][nN][wW][aA][rR][dD]                { if (DEBUG) printf("DOWNWARD:     %s\n", yytext);
                                                  return(DOWNWARD); }

[rR][eE][aA][lL]                                { if (DEBUG) printf("REAL:         %s\n", yytext);
                                                  return(REAL); }

[iI][nN][tT][eE][gG][eE][rR]                    { if (DEBUG) printf("INTEGER:      %s\n", yytext);
                                                  return(INTEGER); }

[dD][aA][tT][aA]                                { if (DEBUG) printf("DATA:         %s\n", yytext);
                                                  return(DATA); }

[aA][lL][gG][oO][rR][iI][tT][hH][mM]            { if (DEBUG) printf("ALGORITHM:    %s\n", yytext);
                                                  return(ALGORITHM); }

[rR][eE][aA][dD]                                { if (DEBUG) printf("READ:         %s\n", yytext);
                                                  return(READ); }

[pP][rR][iI][nN][tT]                            { if (DEBUG) printf("PRINT:        %s\n", yytext);
                                                  return(PRINT); }

[a-zA-Z][a-zA-Z0-9]*                            { if (DEBUG) printf("VARIABLE:     %s\n", yytext);
                                                  yylval.sval = strdup(yytext);
                                                  /* yylval: lexical value (union data type) and make it available in bison with $ */
                                                  /* strdup: new duplicate & copy the characters */
                                                  return(VARIABLE); }

\"(([^"\n"]*)|(\"\"))*\"                        { if (DEBUG) printf("STRING:       %s\n", yytext);
                                                  yylval.sval = strdup(yytext);
                                                  return(STRING); }

[0-9]+                                          { if (DEBUG) printf("INTCONSTANT:  %s\n", yytext);
                                                  yylval.intval = atoi(yytext);
                                                  return(INTCONSTANT); }

[0-9]+((\.[0-9]+)|((\.[0-9]+)?[eE][-+]?[0-9]+)) { if (DEBUG) printf("REALCONSTANT: %s\n", yytext);
                                                  yylval.realval = atof(yytext);
                                                  return(REALCONSTANT); }

[ \t]                                           { /* if (DEBUG) printf("WHITESPACE:   %s\n", yytext);*/ }

"\n"|"\r\n"                                     { /* if (DEBUG) printf("NEWLINE:      %s\n", yytext);*/ }

.                                               { if (DEBUG) printf("TRASH:        %s\n", yytext); }

%%
