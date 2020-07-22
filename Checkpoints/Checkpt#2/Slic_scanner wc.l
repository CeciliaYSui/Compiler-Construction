%{ 
/*
 * ========================================================================
 * Author -------- Cecilia Y. Sui
 * Filename ------ Slice_scanner.l
 * Assignment ---- Checkpoint #2 
 * Description --- Use flex to write a scanner for SLIC 
 * ========================================================================
 */

#include <stdio.h>

int chars, words, lines = 0; 

%}

%%

#.*                         { printf("COMMENT: %s\n", yytext); lines++; chars += strlen(yytext); }
"+"                         { printf("ADDITION: %s\n", yytext); chars++; }
"-"                         { printf("SUBTRACTION: %s\n", yytext); chars++; }
"*"                         { printf("MULTIPLICATION: %s\n", yytext); chars++; }
"/"                         { printf("DIVISION: %s\n", yytext); chars++; }
"%"                         { printf("MODULUS: %s\n", yytext); chars++; }
"<"                         { printf("LESSTHAN: %s\n", yytext); chars++; }
">"                         { printf("GREATERTHAN: %s\n", yytext); chars++; }
"<="                        { printf("LESSOREQUAL: %s\n", yytext); chars += 2; }
">="                        { printf("GREATEROREQUAL: %s\n", yytext); chars += 2; }
"="                         { printf("EQUAL: %s\n", yytext); chars++; }
"<>"                        { printf("NOTEQUAL: %s\n", yytext); chars += 2; }
"&"                         { printf("BOOLAND: %s\n", yytext); chars++; }
"|"                         { printf("BOOLOR: %s\n", yytext); chars++; }
"~"                         { printf("BOOLNOT: %s\n", yytext); chars++; }
"("                         { printf("LEFTPARENTH: %s\n", yytext); chars++; }
")"                         { printf("RIGHTPARENTH: %s\n", yytext); chars++; }
"["                         { printf("LEFTBRACKET: %s\n", yytext); chars++; }
"]"                         { printf("RIGHTBRACKET: %s\n", yytext); chars++; }
";"                         { printf("SEMICOLON: %s\n", yytext); chars++; }
":"                         { printf("COLON: %s\n", yytext); chars++; }
","                         { printf("COMMA: %s\n", yytext); chars++; }
":="                        { printf("ASSIGN: %s\n", yytext); chars += 2; }
"!"                         { printf("CARRIAGERETURN: %s\n", yytext); chars++; }
[mM][aA][iI][nN]                                { printf("MAIN: %s\n", yytext); }
[eE][nN][dD][ ][mM][aA][iI][nN]                 { printf("ENDMAIN: %s\n", yytext); }
[eE][xX][iI][tT]                                { printf("EXIT: %s\n", yytext); }
[iI][fF]                                        { printf("IF: %s\n", yytext); }
[eE][lL][sS][eE]                                { printf("ELSE: %s\n", yytext); }
[eE][nN][dD][ ][iI][fF]                         { printf("ENDIF: %s\n", yytext); }
[wW][hH][iI][lL][eE]                            { printf("WHILE: %s\n", yytext); }
[eE][nN][dD][ ][wW][hH][iI][lL][eE]             { printf("ENDWHILE: %s\n", yytext); }
[tT][oO]                                        { printf("TO: %s\n", yytext); }
[cC][oO][uU][nN][tT][iI][nN][gG]                { printf("COUNTING: %s\n", yytext); }
[eE][nN][dD][ ][cC][oO][uU][nN][tT][iI][nN][gG] { printf("ENDCOUNTING: %s\n", yytext); }
[uU][pP][wW][aA][rR][dD]                        { printf("UPWARD: %s\n", yytext); }
[dD][oO][wW][nN][wW][aA][rR][dD]                { printf("DOWNWARD: %s\n", yytext); }
[rR][eE][aA][lL]                                { printf("REAL: %s\n", yytext); }
[iI][nN][tT][eE][gG][eE][rR]                    { printf("INTEGER: %s\n", yytext); }
[dD][aA][tT][aA]                                { printf("DATA: %s\n", yytext); }
[aA][lL][gG][oO][rR][iI][tT][hH][mM]            { printf("ALGORITHM: %s\n", yytext); }
[rR][eE][aA][dD]                                { printf("READ: %s\n", yytext); }
[pP][rR][iI][nN][tT]                            { printf("PRINT: %s\n", yytext); }
[a-zA-Z][a-zA-Z0-9]*                            { printf("VARIABLENAME: %s\n", yytext); }
\"(([^"\n"]*)|(\"\"))*["\n]                     { printf("STRING: %s\n", yytext); }
[0-9]+                                          { printf("INTEGERREP: %s\n", yytext); }
[-+]?[0-9]+(.[0-9]+)([eE][-+]?[0-9]+)?          { printf("REALREP: %s\n", yytext); }
[ \t\n\r\f\v]                                   { } //ignore white space 
.                                               { printf("?????: %s\n", yytext); }

%%

/* Main Program to call yylex() */ 
int main()
{
    yylex();
    printf("%8d%8d%8d\n", lines, words, chars); 
    return 0;
}