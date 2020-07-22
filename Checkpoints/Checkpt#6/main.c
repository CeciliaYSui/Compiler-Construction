/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Course ---------------- Compiler Construction
 * Filename -------------- main.c
 * Date of Submission ---- October 20, 2019
 * Assignment ------------ Checkpoint #4 main class written in C
 * Description ----------- bison parser for SLIC 
 * ========================================================================
 */

#include <stdio.h>
#include "ST.h"
#include "AST.h" 
#include "codegen.h"
#include "y.tab.h"

int yyparse(); 

int main()
{
   int n;

   n = yyparse();
   /* flex does not need to be called explicitly yylex() */ 
   /* printf("\nyyparse returns %d\n", n); */ 
   if (n == 0) {
      printf("Parsing Succeeded! \n"); 
      STPrint();
      printf("\n");  
      codeGen(); 
   }
   else {
      printf("Parsing Failed! \n");
   }
   return 0; 
}
