/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Course ---------------- Compiler Construction
 * Filename -------------- main.c
 * Date of Submission ---- December 3, 2019
 * Assignment ------------ Checkpoint #8 main class written in C
 * Description ----------- fully implemented compiler 
 * 
 * Warning --------------- Modulus operator not working
 * ----------------------- Counting loops not working 
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
   if (n == 0) {
      //printf("Parsing Succeeded! \n"); 
      //STPrint();
      //printf("\n");  
      codeGen(); 
   }
   else {
      printf("Parsing Failed! \n");
   }
   return 0; 
}
