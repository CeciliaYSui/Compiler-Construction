/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Course ---------------- Compiler Construction
 * Filename -------------- AST.h
 * Date of Submission ---- December 3, 2019
 * Assignment ------------ Checkpoint #8
 * Description ----------- Build Abstract Syntax Tree
 * 
 * Warning --------------- Modulus operator not working
 * ----------------------- Counting loops not working 
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
    LITERAL_STRING, 
    EXIT_OP, 
    READ_OP, 
    PRINT_OP, 
    COUNTUP_OP, 
    COUNTDOWN_OP, 
    WHILE_OP, 
    IF_OP,
    IFELSE_OP,
    NEWLINE_OP
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

    struct Node *ifelse; 
    struct Node *cnt1; 
    struct Node *cnt2; 
} Node;


#endif 