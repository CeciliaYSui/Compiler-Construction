%{ 

/*
 * ========================================================================
 * 
 * sample.l ----- In-class example of flex input file. This project parses
 *                Boolean expressions
 * 
 * Programmer --- Bryan Crawley
 * 
 * ========================================================================
 */

#define  DEBUG 0
#include "y.tab.h"
#include <stdio.h>
#include <string.h>

%}

%%
"&"                     {
                          if (DEBUG) printf("and ");
                          return(AND);
                        } 

"|"                     {
                          if (DEBUG) printf("or ");
                          return(OR);
                        }

"~"                     {
                          if (DEBUG) printf("not ");
                          return(NOT);
                        }

"("                     { 
                          if (DEBUG) printf("lparen ");
                          return(LPAREN);
                        }

")"                     {
                          if (DEBUG) printf("rparen ");
                          return(RPAREN);
                        }

[A-Za-z][A-Za-z0-9]*    {
                          if (DEBUG) printf("variable(%s) ", yytext);
                          yylval.sval = strdup(yytext);
                          /* yylval: lexical value (union data type) and make it available in bison with $ */
                          /* strdup: new duplicate & copy the characters */
                          return(VARIABLE);
                     	}

\n                   	{
                          if (DEBUG) printf("newline\n\n");
                          return(NEWLINE);
                        }

[\t ]+                  {
                          if (DEBUG) printf("whitespace ");
                        }
%%

