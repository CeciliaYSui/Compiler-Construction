%{ 
/*
 * ========================================================================
 * Author -------- Cecilia Y. Sui
 * Filename ------ Slice_scanner.l
 * Assignment ---- Checkpoint #2 
 * Description --- Use flex to write a scanner for SLIC 
 * 
 * Version ------- This version prints out whitespace tokens
 * ========================================================================
 */

#include <stdio.h>

%}

%%

#.*                         { printf("COMMENT:      %s\n", yytext); }
"+"                         { printf("ADDITION:     %s\n", yytext); }
"-"                         { printf("SUBTRACTION:  %s\n", yytext); }
"*"                         { printf("MULTIPLICATION: %s\n", yytext); }
"/"                         { printf("DIVISION:     %s\n", yytext); }
"%"                         { printf("MODULUS:      %s\n", yytext); }
"<"                         { printf("LESSTHAN:     %s\n", yytext); }
">"                         { printf("GREATERTHAN:  %s\n", yytext); }
"<="                        { printf("LESSOREQUAL:  %s\n", yytext); }
">="                        { printf("GREATEROREQUAL: %s\n", yytext); }
"="                         { printf("EQUAL:        %s\n", yytext); }
"<>"                        { printf("NOTEQUAL:     %s\n", yytext); }
"&"                         { printf("BOOLAND:      %s\n", yytext); }
"|"                         { printf("BOOLOR:       %s\n", yytext); }
"~"                         { printf("BOOLNOT:      %s\n", yytext); }
"("                         { printf("LEFTPARENTH:  %s\n", yytext); }
")"                         { printf("RIGHTPARENTH: %s\n", yytext); }
"["                         { printf("LEFTBRACKET:  %s\n", yytext); }
"]"                         { printf("RIGHTBRACKET: %s\n", yytext); }
";"                         { printf("SEMICOLON:    %s\n", yytext); }
":"                         { printf("COLON:        %s\n", yytext); }
","                         { printf("COMMA:        %s\n", yytext); }
":="                        { printf("ASSIGN:       %s\n", yytext); }
"!"                         { printf("CARRIAGERETURN: %s\n", yytext); }
[mM][aA][iI][nN]                                { printf("MAIN:         %s\n", yytext); }
[eE][nN][dD][ ][mM][aA][iI][nN]                 { printf("ENDMAIN:      %s\n", yytext); }
[eE][xX][iI][tT]                                { printf("EXIT:         %s\n", yytext); }
[iI][fF]                                        { printf("IF:           %s\n", yytext); }
[eE][lL][sS][eE]                                { printf("ELSE:         %s\n", yytext); }
[eE][nN][dD][ ][iI][fF]                         { printf("ENDIF:        %s\n", yytext); }
[wW][hH][iI][lL][eE]                            { printf("WHILE:        %s\n", yytext); }
[eE][nN][dD][ ][wW][hH][iI][lL][eE]             { printf("ENDWHILE:     %s\n", yytext); }
[tT][oO]                                        { printf("TO:           %s\n", yytext); }
[cC][oO][uU][nN][tT][iI][nN][gG]                { printf("COUNTING:     %s\n", yytext); }
[eE][nN][dD][ ][cC][oO][uU][nN][tT][iI][nN][gG] { printf("ENDCOUNTING:  %s\n", yytext); }
[uU][pP][wW][aA][rR][dD]                        { printf("UPWARD:       %s\n", yytext); }
[dD][oO][wW][nN][wW][aA][rR][dD]                { printf("DOWNWARD:     %s\n", yytext); }
[rR][eE][aA][lL]                                { printf("REAL:         %s\n", yytext); }
[iI][nN][tT][eE][gG][eE][rR]                    { printf("INTEGER:      %s\n", yytext); }
[dD][aA][tT][aA]                                { printf("DATA:         %s\n", yytext); }
[aA][lL][gG][oO][rR][iI][tT][hH][mM]            { printf("ALGORITHM:    %s\n", yytext); }
[rR][eE][aA][dD]                                { printf("READ:         %s\n", yytext); }
[pP][rR][iI][nN][tT]                            { printf("PRINT:        %s\n", yytext); }
[a-zA-Z][a-zA-Z0-9]*                            { printf("VARIABLENAME: %s\n", yytext); }
\"(([^"\n"]*)|(\"\"))*\"                        { printf("STRING:       %s\n", yytext); }
[0-9]+                                          { printf("INTEGERREP:   %s\n", yytext); }
[-+]?[0-9]+(("."[0-9]+)|(("."[0-9]+)?[eE][-+]?[0-9]+)) { printf("REALREP:      %s\n", yytext); }
[ \t\n\r\f\v]                                   { /* printf("WHITESPACE:   %s\n", yytext);*/ }  
.                                               { printf("TRASH:        %s\n", yytext); }

%%

/* Main Program to call yylex() */ 

int main()
{
    yylex();
    return 0;
}