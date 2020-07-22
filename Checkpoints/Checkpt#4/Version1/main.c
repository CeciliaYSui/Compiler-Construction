/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Course ---------------- Compiler Construction
 * Filename -------------- main.c
 * Date of Submission ---- October 21, 2019
 * Assignment ------------ Checkpoint #4 main class written in C
 * Description ----------- bison parser for SLIC 
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
