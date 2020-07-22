/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Course ---------------- Compiler Construction
 * Filename -------------- main.c
 * Date of Submission ---- December 3, 2019
 * Assignment ------------ Checkpoint #8 main class written in C
 * Description ----------- fully implemented compiler 
 * ========================================================================
 */

#include <stdio.h>
#include "ST.h"
#include "AST.h" 
#include "codegen.h"
#include "y.tab.h"
#define DEBUG 0 

int yyparse(); 

int main()
{
   int n;

   n = yyparse();
   if (n == 0) {
      if (DEBUG){
         printf("Parsing Succeeded! \n"); 
         STPrint();
         printf("-------------------------------------------------\n");
      }  
      codeGen(); 
   }
   else {
      printf("Parsing Failed! \n");
   }
   return 0; 
}
