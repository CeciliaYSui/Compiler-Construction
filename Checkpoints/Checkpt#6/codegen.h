/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Course ---------------- Compiler Construction
 * Filename -------------- codegen.h
 * Date of Submission ---- November 13, 2019
 * Assignment ------------ Checkpoint #6 
 * Description ----------- Add Code Generator to generate GSTAL code 
 * ----------------------- including assignment statements
 * 
 * Warning --------------- Modulus operator not working !
 * ========================================================================
 */

#ifndef CODE_GEN
#define CODE_GEN
#include "AST.h"

Type getVarType(Node * nodeE);
int addStmts(char *s); 
void insertStmts(int index, char *s);
void replaceStmts(int index, char *s);
void addStmtsInt(char *s, int n);
void addStmtsReal(char *s, float n);
void replaceStmtsInt(int index, char *s, int n);
void replaceStmtsReal(int index, char *s, float n);
void notZero(Type dtype);
void addrGen(Node *nodeE);
Type getType(Node *nodeE, int indexL); 
void exprGen(Node *nodeE); 
void assignmtGen(Node *nodeE); 
void codeGen(); 

#endif