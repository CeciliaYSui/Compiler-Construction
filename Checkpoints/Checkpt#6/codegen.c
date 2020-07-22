/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Course ---------------- Compiler Construction
 * Filename -------------- codegen.c
 * Date of Submission ---- November 13, 2019
 * Assignment ------------ Checkpoint #6 
 * Description ----------- Add Code Generator to generate GSTAL code 
 * ----------------------- including assignment statements
 * 
 * Warning --------------- Modulus operator not working !
 * ========================================================================
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ST.h"
#include "AST.h"
#define DEBUG 0

void exprGen(Node *nodeE); 

Node *root; 
char **statements; // ptr to ptr to char -- array of instructions 
int size = 10000; // arbitrary no. 
int stmtsCnt = -1; // statements start at zero in slic 

// function to get the variable data type (int or real)
Type getVarType(Node * nodeE){
    Variable *v = STLookup(nodeE->sval); // lookup function 
    if (v == NULL){
        printf("ERROR: Variable %s Not Found. \n", nodeE->sval); 
    }
    if (DEBUG){
        printf("TEST: got variable data type successfully! \n");
    }
    return v->dtype;  // 0 for TYPE_INT 1 for TYPE_REAL
}

int addStmts(char *s) {
    stmtsCnt += 1; 
    statements[stmtsCnt] = strdup(s); 
    if (DEBUG){
        printf("TEST: added staments successfully! \n"); // check 
        printf("TEST: ADDED: %s \n", s);
    } 
    return stmtsCnt; 
}

void insertStmts(int i, char *s){
    stmtsCnt += 1; 
    for (int j = stmtsCnt; j > i; j--){ 
        statements[j] = statements[j-1];  
    }
    statements[i] = s; // insert statement at index 
}

// replace or backpatching statments 
void replaceStmts(int i, char *s){
    free(statements[i]); 
    statements[i] = strdup(s); 
}

void addStmtsInt(char *s, int n){ // allow for adding instruction with address / int 
    char c[50]; 
    sprintf(c, "%s %d", s, n); 
    addStmts(c); 
}

void addStmtsReal(char *s, float n){ // allow for adding instructions with real no. 
    char c[50]; 
    sprintf(c, "%s %f", s, n); 
    addStmts(c); 
}

void replaceStmtsInt(int i, char *s, int n){
    char c[50]; 
    sprintf(c, "%s %d", s, n); 
    replaceStmts(i, c); 
}

void replaceStmtsReal(int i, char *s, float n){
    char c[50]; 
    sprintf(c, "%s %f", s, n); 
    replaceStmts(i, c); 
}

void notZero(Type dtype){ // check if value is zero used in logical operators 
    if (dtype == TYPE_INT){
        addStmtsInt("LLI", 0); 
        addStmts("NEI"); // not equal to 
        if (DEBUG){
            printf("TEST: checked nonzero type int successfully! \n");
        }
    }
    else {
        addStmtsReal("LLF", 0.0f); 
        addStmts("NEF"); 
        if (DEBUG){
            printf("TEST: checked nonzero type real successfully! \n");
        }
    }
}

// generate address  
void addrGen(Node *nodeE){
    if (DEBUG){
        printf("TEST: RUNNING addrGen() ----------------------- \n"); 
    }
    Variable *var = STLookup(nodeE->sval); // lookup function 
    if (var == NULL){
        printf("ERROR: Variable %s Not Found. \n", nodeE->sval); 
        exit(-1); 
    }
    if (var->isArray){
        exprGen(nodeE->left); 
        if (nodeE->left->dtype == TYPE_REAL){ // seg fault here!!!!!! 
            addStmts("FTI"); // convert to int 
        }
        addStmtsInt("LRA", var->loc); 
        addStmts("ADI"); 
    }
    else {
        addStmtsInt("LRA", var->loc); 
    }
    if (DEBUG){
        printf("TEST: generated address successfully! \n");
    }
}

// get data type for the node (resolve for real & int computation)
Type getType(Node *nodeE, int i){
    Type t = nodeE->left->dtype;  
    if (nodeE->left->dtype == TYPE_INT && nodeE->right->dtype == TYPE_REAL){
        insertStmts(i+1, "ITF"); // convert int to float 
        t = TYPE_REAL; 
    }
    else if (nodeE->left->dtype == TYPE_REAL && nodeE->right->dtype == TYPE_INT){
        addStmts("ITF"); 
        t = TYPE_REAL; 
    }
    return t; 
}

void exprGen(Node *nodeE){
    if (DEBUG){
        printf("TEST: start running exprGen() \n"); 
    }
    switch (nodeE->kind)
    {
    // logic operators 
    case NOT_OP: 
        nodeE->dtype = TYPE_INT; 
        exprGen(nodeE->left);
        notZero(nodeE->left->dtype); 
        addStmts("LLI 0"); 
        addStmts("EQI"); 
        break; 
    case AND_OP:
        nodeE->dtype = TYPE_INT; 
        exprGen(nodeE->left); 
        notZero(nodeE->left->dtype); 
        exprGen(nodeE->right); 
        notZero(nodeE->right->dtype); 
        addStmts("MLI"); 
        break;
    case OR_OP: 
        nodeE->dtype = TYPE_INT; 
        exprGen(nodeE->left); 
        notZero(nodeE->left->dtype); 
        exprGen(nodeE->right); 
        notZero(nodeE->right->dtype); 
        addStmts("ADI"); 
        notZero(TYPE_INT);
        break;
    // arithematic operators  
    case ADDITION_OP: 
        exprGen(nodeE->left);  
        exprGen(nodeE->right); 
        nodeE->dtype = getType(nodeE, stmtsCnt); 
        if (getType(nodeE, stmtsCnt) == TYPE_INT){
            addStmts("ADI"); 
        }
        else {
            addStmts("ADF"); 
        }
        break; 
    case SUBTRACTION_OP: 
        exprGen(nodeE->left); 
        exprGen(nodeE->right); 
        nodeE->dtype = getType(nodeE, stmtsCnt); 
        if (getType(nodeE, stmtsCnt) == TYPE_INT){
            addStmts("SBI"); 
        }
        else {
            addStmts("SBF"); 
        }
        break; 
    case MULTIPLICATION_OP: 
        exprGen(nodeE->left); 
        exprGen(nodeE->right); 
        nodeE->dtype = getType(nodeE, stmtsCnt); 
        if (getType(nodeE, stmtsCnt) == TYPE_INT){
            addStmts("MLI"); 
        }
        else {
            addStmts("MLF"); 
        }
        break; 
    case DIVISION_OP: 
        exprGen(nodeE->left); 
        exprGen(nodeE->right); 
        nodeE->dtype = getType(nodeE, stmtsCnt); 
        if (getType(nodeE, stmtsCnt) == TYPE_INT){
            addStmts("DVI"); 
        }
        else {
            addStmts("DVF"); 
        }
        break; 
    case UMINUS_OP: 
        exprGen(nodeE->left); 
        if (nodeE->left->dtype == TYPE_INT){
            addStmtsInt("LLI", 0); 
            addStmts("SBI"); 
        }
        else{
            addStmtsInt("LLF", 0.0); 
            addStmts("SBF"); 
        }
        nodeE->dtype = nodeE->left->dtype; 
        break; 
    // comparison operators:    
    case LESS_OP: 
        exprGen(nodeE->left); 
        exprGen(nodeE->right); 
        nodeE->dtype = TYPE_INT; 
        if (getType(nodeE, stmtsCnt) == TYPE_INT){
            addStmts("LTI");  
        }
        else {
            addStmts("LTF"); 
        }
        break; 
    case GREATER_OP: 
        exprGen(nodeE->left);  
        exprGen(nodeE->right); 
        nodeE->dtype = TYPE_INT; 
        if (getType(nodeE, stmtsCnt) == TYPE_INT){
            addStmts("GTI");  
        }
        else {
            addStmts("GTF"); 
        }
        break; 
    case LESSOREQUAL_OP: 
        exprGen(nodeE->left); 
        exprGen(nodeE->right); 
        nodeE->dtype = TYPE_INT; 
        if (getType(nodeE, stmtsCnt) == TYPE_INT){
            addStmts("LEI");  
        }
        else {
            addStmts("LEF"); 
        }
        break; 
    case GREATEROREQUAL_OP: 
        exprGen(nodeE->left); 
        exprGen(nodeE->right); 
        nodeE->dtype = TYPE_INT; 
        if (getType(nodeE, stmtsCnt) == TYPE_INT){
            addStmts("GEI");  
        }
        else {
            addStmts("GEF"); 
        }
        break; 
    case NOTEQUAL_OP:
        exprGen(nodeE->left); 
        exprGen(nodeE->right); 
        nodeE->dtype = TYPE_INT; 
        if (getType(nodeE, stmtsCnt) == TYPE_INT){
            addStmts("NEI");  
        }
        else {
            addStmts("NEF"); 
        }
        break; 
    case EQUAL_OP: 
        exprGen(nodeE->left); 
        exprGen(nodeE->right); 
        nodeE->dtype = TYPE_INT; 
        if (getType(nodeE, stmtsCnt) == TYPE_INT){
            addStmts("EQI");  
        }
        else {
            addStmts("EQF"); 
        }
        break; 
    case VARIABLE_OP: 
        addrGen(nodeE); 
        addStmts("LOD"); 
        Variable *v = STLookup(nodeE->sval); 
        nodeE->dtype = v->dtype; 
        break; 
    case LITERAL_INT: 
        addStmtsInt("LLI", nodeE->intval); 
        nodeE->dtype = TYPE_INT; 
        break; 
    case LITERAL_REAL: 
        addStmtsReal("LLF", nodeE->realval); 
        nodeE->dtype = TYPE_REAL; 
        break; 
    default:
        break;
    }
    if (DEBUG){
        printf("TEST: generated expression statements successfully! \n");
    }
}

// generate code for assignment statements 
void assignmtGen(Node *nodeE){
    if (DEBUG){
        printf("TEST: started running assignmtGen () ------------------------ \n");
    }
    addrGen(nodeE->left); 
    exprGen(nodeE->right); 
    Variable *v = STLookup(nodeE->left->sval); 
    if (v->dtype == TYPE_INT && nodeE->right->dtype == TYPE_REAL){
        addStmts("FTI"); 
    }
    if (v->dtype == TYPE_REAL && nodeE->right->dtype == TYPE_INT){
        addStmts("ITF"); 
    }
    addStmts("STO"); 
    if (DEBUG){
        printf("TEST: generated assignment statements successfully! -------------\n"); 
    }
}

void codeGen() {
	statements = (char **)malloc(size * sizeof(char *));
	addStmts("NOP"); // Reserve spot for allocate space for vars ISP replace 
    while(root != NULL) {
        switch (root->kind)
        {
        case ASSIGNMENT_OP:
            assignmtGen(root); 
            break;
        default:
            break;
        }
        root = root->next; 
    }
	addStmts("HLT");
    replaceStmtsInt(0, "ISP", STSize()); 
	// Print out code
    if(DEBUG){
        printf("TEST: printing out GSTAL statments: ************************ \n"); 
    }
	for(int i = 0; i <= stmtsCnt; i++) {
		printf("%s\n", statements[i]);
	}
    free(statements); // free malloc 
    if (DEBUG){
        printf("TEST: generated CODE successfully! \n");
    }
}
