/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Course ---------------- Compiler Construction
 * Filename -------------- codegen.h
 * Date of Submission ---- December 3, 2019
 * Assignment ------------ Checkpoint #8 
 * Description ----------- Add Code Generator to generate GSTAL code 
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
void checkTrue(Type t); 
void addrGen(Node *nodeE); 
Type getType(Node *nodeE, int i); 
void exprGen(Node *nodeE); 
void assignmtGen(Node *nodeE); 
void printGen(Node *nodeE); 
void readGen(Node *nodeE); 
void ifGen(Node *nodeE); 
void ifelseGen(Node *nodeE); 
void whileGen(Node *nodeE); 
void cntupGen(Node *nodeE); 
void cntdownGen(Node *nodeE); 
void treeGen(Node *root); 
void codeGen(); 

#endif