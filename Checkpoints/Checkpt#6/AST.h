/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Course ---------------- Compiler Construction
 * Filename -------------- AST.h
 * Date of Submission ---- November 7, 2019
 * Assignment ------------ Checkpoint #6
 * Description ----------- Build Abstract Syntax Tree
 * ========================================================================
 */

#ifndef AST_H
#define AST_H
#include "ST.h"

typedef enum{
    ADDITION_OP,
    SUBTRACTION_OP,
    MULTIPLICATION_OP,
    DIVISION_OP,
    MODULUS_OP,
    UMINUS_OP, 
    AND_OP,
    NOT_OP,
    OR_OP,
    LESS_OP,
    GREATER_OP,
    LESSOREQUAL_OP, 
    GREATEROREQUAL_OP,
    NOTEQUAL_OP,
    EQUAL_OP,
    ASSIGNMENT_OP,
    VARIABLE_OP,
    LITERAL_INT,
    LITERAL_REAL, 
    LITERAL_STRING
} OpKind; 

typedef struct Node {
    Type dtype; 
    OpKind kind;
    struct Node *left;
    struct Node *right;
    struct Node *next; 
    int intval;
    float realval; 
    char *sval; 
} Node;

#endif 