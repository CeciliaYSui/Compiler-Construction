/*
 * ========================================================================
 * 
 * main.c ------- In-class example of a main program file to be used in
 *                conjunction with a bison parser.
 * 
 * Programmer --- Bryan Crawley
 * 
 * ========================================================================
 */

#include "y.tab.h"
#include <stdio.h>

int main()
{
   int n;

   n = yyparse();
   /* flex does not need to be called explicitly yylex() */ 
   printf("\nyyparse returns %d\n", n);
   /* check if the result is 0 that parsing succeeded */
   return 0; 
}
