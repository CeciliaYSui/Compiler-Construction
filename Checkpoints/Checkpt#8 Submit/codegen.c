/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Course ---------------- Compiler Construction
 * Filename -------------- codegen.c
 * Date of Submission ---- December 3, 2019
 * Assignment ------------ Checkpoint #8
 * Description ----------- Code Generator to generate GSTAL code 
 * 
 * ========================================================================
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ST.h"
#include "AST.h"
#define DEBUG 0

void exprGen(Node *nodeE);
void treeGen(Node *root); 

Node *root; 
char **statements; // ptr to ptr to char -- array of instructions 
int size = 10000; // arbitrary no. subject to changes
int stmtsCnt = -1; // statements start at zero in slic 
static int cntID = 0; // remain value through function calls 

//--------------------------------------------------------------
// function to get the variable data type (int or real)
//--------------------------------------------------------------
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

//--------------------------------------------------------------
// function to add statements to the array to printout 
//--------------------------------------------------------------
int addStmts(char *s) {
    stmtsCnt += 1; 
    statements[stmtsCnt] = strdup(s); 
    if (DEBUG){
        printf("TEST: added staments successfully! \n"); // check 
        printf("TEST: ADDED: %s \n", s);
    } 
    return stmtsCnt; 
}

//--------------------------------------------------------------
// function to insert statements at certain index in the array
//--------------------------------------------------------------
void insertStmts(int i, char *s){
    stmtsCnt += 1; 
    for (int j = stmtsCnt; j > i; j--){ 
        statements[j] = statements[j-1];  
    }
    statements[i] = s; // insert statement at index 
}

//--------------------------------------------------------------
// funciton to replace/backpatch statments  ** VERY SLOW **
//--------------------------------------------------------------
void replaceStmts(int i, char *s){
    free(statements[i]); 
    statements[i] = strdup(s); 
}

//--------------------------------------------------------------
// function to add instruction with address / int 
//--------------------------------------------------------------
void addStmtsInt(char *s, int n){ 
    char c[50]; 
    sprintf(c, "%s %d", s, n); 
    addStmts(c); 
}

//--------------------------------------------------------------
// function to add instructions with real numbers / floats 
//--------------------------------------------------------------
void addStmtsReal(char *s, float n){  
    char c[50]; 
    sprintf(c, "%s %f", s, n); 
    addStmts(c); 
}

//--------------------------------------------------------------
// function to replace statements with integers 
//--------------------------------------------------------------
void replaceStmtsInt(int i, char *s, int n){
    char c[50]; 
    sprintf(c, "%s %d", s, n); 
    replaceStmts(i, c); 
}

//--------------------------------------------------------------
// function to replace statements with real numbers / floats  
//--------------------------------------------------------------
void replaceStmtsReal(int i, char *s, float n){
    char c[50]; 
    sprintf(c, "%s %f", s, n); 
    replaceStmts(i, c); 
}

//--------------------------------------------------------------
// check if value is zero (i.e. False) used in logical operators 
//--------------------------------------------------------------
void checkTrue(Type t){
    if (t == TYPE_INT){
        addStmts("LLI 0"); 
        addStmts("NEI"); // not equal to 
        if (DEBUG){
            printf("TEST: checked nonzero type int successfully! \n");
        }
    }
    else if (t == TYPE_REAL){
        addStmts("LLF 0.0"); 
        addStmts("NEF"); 
        if (DEBUG){
            printf("TEST: checked nonzero type real successfully! \n");
        }
    }
    else {
        printf("ERROR: Cannot check nonzero values. \n"); 
        exit(-1); 
    }
}

//--------------------------------------------------------------
// function to generate address (relative addr is used here)
//--------------------------------------------------------------
void addrGen(Node *nodeE){
    if (DEBUG){
        printf("TEST: RUNNING addrGen() ----------------------- \n"); 
    }
    Variable *var = STLookup(nodeE->sval); 
    if (var == NULL){
        printf("ERROR: Variable %s Not Found. \n", nodeE->sval); 
        exit(-1); 
    }
    if (var->isArray){
        exprGen(nodeE->left); 
        if (nodeE->left->dtype == TYPE_REAL){ 
            addStmts("FTI"); 
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

//----------------------------------------------------------------------------------
// function to get data type for the node (resolve for real & int computation)
//----------------------------------------------------------------------------------
Type getType(Node *nodeE, int i){
    Type t = nodeE->left->dtype; 
    if (nodeE->left->dtype == TYPE_INT && nodeE->right->dtype == TYPE_REAL){
        insertStmts(i-1, "ITF"); 
        t = TYPE_REAL; 
    }
    else if (nodeE->left->dtype == TYPE_REAL && nodeE->right->dtype == TYPE_INT){
        addStmts("ITF"); 
        t = TYPE_REAL; 
    }
    return t; 
}

//-------------------------------------------------------------------
// function to evaluate full-expressions 
//-------------------------------------------------------------------
void exprGen(Node *nodeE){
    if (DEBUG){
        printf("TEST: start running exprGen() \n"); 
    }
    switch (nodeE->kind)
    {
    // logic operators 
    case NOT_OP: {
        nodeE->dtype = TYPE_INT; 
        exprGen(nodeE->left);
        checkTrue(nodeE->left->dtype); 
        addStmts("LLI 0"); 
        addStmts("EQI"); 
        break; 
    }
    case AND_OP: {
        nodeE->dtype = TYPE_INT; 
        exprGen(nodeE->left); 
        checkTrue(nodeE->left->dtype); 
        exprGen(nodeE->right); 
        checkTrue(nodeE->right->dtype); 
        addStmts("MLI"); 
        break;
    }
    case OR_OP: {
        nodeE->dtype = TYPE_INT; 
        exprGen(nodeE->left); 
        checkTrue(nodeE->left->dtype); 
        exprGen(nodeE->right); 
        checkTrue(nodeE->right->dtype); 
        addStmts("ADI"); 
        checkTrue(TYPE_INT);
        break;
    }
    // arithematic operators 
    case ADDITION_OP: {
        exprGen(nodeE->left);  
        exprGen(nodeE->right); 
        nodeE->dtype = getType(nodeE, stmtsCnt); 
        if (nodeE->dtype == TYPE_INT){
            addStmts("ADI"); 
        }
        else {
            addStmts("ADF"); 
        }
        break;
    }
    case SUBTRACTION_OP: {
        exprGen(nodeE->left); 
        exprGen(nodeE->right); 
        nodeE->dtype = getType(nodeE, stmtsCnt);
        if (nodeE->dtype == TYPE_INT){
            addStmts("SBI"); 
        }
        else {
            addStmts("SBF"); 
        }
        break; 
    }
    case MULTIPLICATION_OP: {
        exprGen(nodeE->left); 
        exprGen(nodeE->right); 
        nodeE->dtype = getType(nodeE, stmtsCnt); 
        if (nodeE->dtype == TYPE_INT){
            addStmts("MLI"); 
        }
        else {
            addStmts("MLF"); 
        }
        break; 
    }
    case DIVISION_OP: {
        exprGen(nodeE->left);
        exprGen(nodeE->right); 
        nodeE->dtype = getType(nodeE, stmtsCnt); 
        if (nodeE->dtype == TYPE_INT){
            addStmts("DVI"); 
        }
        else {
            addStmts("DVF"); 
        }
        break; 
    }
    case UMINUS_OP: {
        exprGen(nodeE->left); 
        if (nodeE->left->dtype == TYPE_INT){
            addStmts("LLI -1"); 
            addStmts("MLI"); 
        }
        else{
            addStmts("LLF -1.0"); 
            addStmts("MLF"); 
        }
        nodeE->dtype = nodeE->left->dtype; 
        break; 
    }
    // comparison operators:    
    case LESS_OP: {
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
    }
    case GREATER_OP: {
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
    }
    case LESSOREQUAL_OP: {
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
    }
    case GREATEROREQUAL_OP: {
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
    }
    case NOTEQUAL_OP: {
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
    }
    case EQUAL_OP: {
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
    }
    case LITERAL_INT: {
        addStmtsInt("LLI", nodeE->intval); 
        nodeE->dtype = TYPE_INT; 
        break; 
    }
    case LITERAL_REAL: {
        addStmtsReal("LLF", nodeE->realval); 
        nodeE->dtype = TYPE_REAL; 
        break; 
    }
    case VARIABLE_OP: {
        addrGen(nodeE); 
        addStmts("LOD"); 
        Variable *v = STLookup(nodeE->sval); 
        nodeE->dtype = v->dtype; 
        break; 
    }
    case MODULUS_OP: {
        Variable *aMod = STLookup("$aMod"); 
        Variable *bMod = STLookup("$bMod"); 
        addStmtsInt("LRA", aMod->loc); 
        exprGen(nodeE->left); 
        addStmts("STO"); 
        addStmtsInt("LRA", bMod->loc); 
        exprGen(nodeE->right); 
        addStmts("STO"); 
        if(nodeE->left->dtype == TYPE_REAL){
            addStmtsInt("LRA", aMod->loc); 
            addStmts("LOD"); 
            addStmts("FTI"); 
            addStmtsInt("LRA", aMod->loc); 
            addStmts("STO"); 
        }
        if(nodeE->right->dtype == TYPE_REAL){
            addStmtsInt("LRA", bMod->loc); 
            addStmts("LOD"); 
            addStmts("FTI"); 
            addStmtsInt("LRA", bMod->loc); 
            addStmts("STO"); 
        }
        addStmtsInt("LRA", aMod->loc); 
        addStmts("LOD"); 
        addStmtsInt("LRA", bMod->loc); 
        addStmts("LOD"); 
        addStmtsInt("LRA", aMod->loc); 
        addStmts("LOD"); 
        addStmtsInt("LRA", bMod->loc); 
        addStmts("LOD"); 
        addStmts("DVI"); 
        addStmts("MLI"); 
        addStmts("SBI"); 
        break; 
    }
        default: 
            break; 
    }
    if (DEBUG){
        printf("TEST: generated expression statements successfully! \n");
    }
}

//----------------------------------------------------------------------------------
// function to generate code for assignment statements 
//----------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------
// function to generate code for print statements: PTC, PTL, PTI, PTF
//----------------------------------------------------------------------------------
void printGen(Node *nodeE){
    Node *list = nodeE->left; 
    while (list != NULL){
        if(list->kind == NEWLINE_OP){
            addStmts("PTL"); 
        }
        else if (list->kind == LITERAL_STRING){
            for (int i=1; i < strlen(list->sval)-1; i++){
                int c = (int) list->sval[i]; 
                if(c == (int)'"') {
                    i++; 
                }
                addStmtsInt("LLI", c); 
                addStmts("PTC"); 
            }
        }
        else {
            exprGen(list); 
            if(list->dtype == TYPE_INT){
                addStmts("PTI"); 
            }
            else{
                addStmts("PTF"); 
            }
        }
        list = list->next; 
    }
}

//----------------------------------------------------------------------------------
// function to generate code for read statements: INI, INF
//----------------------------------------------------------------------------------
void readGen(Node *nodeE){
    addrGen(nodeE->left); 
    Type t = getVarType(nodeE->left); 
    if(t == TYPE_INT){
        addStmts("INI"); 
    }
    else if (t == TYPE_REAL){
        addStmts("INF"); 
    }
    else {
        printf("ERROR: getVarType() generated error on TYPE returned. \n"); 
        exit(-1); 
    }
    addStmts("STO"); 
}

//----------------------------------------------------------------------------------
// function to generate code for if statements 
//----------------------------------------------------------------------------------
void ifGen(Node *nodeE){
    exprGen(nodeE->left); 
    checkTrue(nodeE->left->dtype); 
    addStmts("NOP"); 
    int jmpTo = stmtsCnt; 
    treeGen(nodeE->right); 
    replaceStmtsInt(jmpTo, "JPF", stmtsCnt+1); 
}

//----------------------------------------------------------------------------------
// function to generate code for if-else statements 
//----------------------------------------------------------------------------------
void ifelseGen(Node *nodeE){
    exprGen(nodeE->left); 
    checkTrue(nodeE->left->dtype); 
    addStmts("NOP"); 
    int jmp = stmtsCnt; 
    treeGen(nodeE->right); 
    addStmts("NOP"); 
    int skip = stmtsCnt; 
    treeGen(nodeE->ifelse); 
    replaceStmtsInt(jmp, "JPF", skip+1); 
    replaceStmtsInt(skip, "JMP", stmtsCnt+1); 
}

//----------------------------------------------------------------------------------
// function to generate code for while loops 
//----------------------------------------------------------------------------------
void whileGen(Node *nodeE){
    int jmp1 = stmtsCnt+1; 
    exprGen(nodeE->left); 
    checkTrue(nodeE->left->dtype);
    addStmts("NOP"); 
    int jmp2 = stmtsCnt; 
    treeGen(nodeE->right);  
    addStmtsInt("JMP", jmp1); 
    replaceStmtsInt(jmp2, "JPF", stmtsCnt+1); 
}

//----------------------------------------------------------------------------------
// function to generate code for counting upward loops  
//----------------------------------------------------------------------------------
void cntupGen(Node *nodeE){
    if (getVarType(nodeE->left) != TYPE_INT){
        printf("ERROR: The counting loop control variable must be an integer.\n"); 
        exit(-1); 
    }
    addrGen(nodeE->left); // get ctrl var addr
    exprGen(nodeE->cnt1); 
    if (nodeE->cnt1->dtype != TYPE_INT){
        addStmts("FTI"); 
    }
    addStmts("STO"); 
    char cntVar[100]; 
    cntID++; 
    sprintf(cntVar, "$cnt_%d", cntID); 
    STInsert(TYPE_INT, strdup(cntVar), 1, 0); // synthesize variable declaration 
    int endAddr = STLookup(cntVar)->loc; 
    addStmtsInt("LRA", endAddr); 
    exprGen(nodeE->cnt2); 
    if (nodeE->cnt2->dtype != TYPE_INT){
        addStmts("FTI"); 
    }
    addStmts("STO"); 
    int cntStart = stmtsCnt + 1; 
    addrGen(nodeE->left); 
    addStmts("LOD"); 
    addStmtsInt("LRA", endAddr); 
    addStmts("LOD"); 
    addStmts("LEI"); 
    addStmts("NOP"); 
    int jmpToEnd = stmtsCnt; 
    treeGen(nodeE->right);
    addrGen(nodeE->left); 
    addrGen(nodeE->left); 
    addStmts("LOD"); 
    addStmts("LLI 1"); 
    addStmts("ADI"); 
    addStmts("STO"); 
    addStmtsInt("JMP", cntStart); 
    replaceStmtsInt(jmpToEnd, "JPF", stmtsCnt+1); 
}

//----------------------------------------------------------------------------------
// function to generate code for counting downward loops     
//----------------------------------------------------------------------------------
void cntdownGen(Node *nodeE){
    if (getVarType(nodeE->left) != TYPE_INT){
        printf("ERROR: The counting loop control variable must be an integer.\n"); 
        exit(-1); 
    }
    addrGen(nodeE->left); // get ctrl var addr
    exprGen(nodeE->cnt1); 
    if (nodeE->cnt1->dtype != TYPE_INT){
        addStmts("FTI"); 
    }
    addStmts("STO"); 
    char cntVar[100]; 
    cntID++; 
    sprintf(cntVar, "$cnt_%d", cntID); 
    STInsert(TYPE_INT, strdup(cntVar), 1, 0); // synthesize variable declaration 
    int endAddr = STLookup(cntVar)->loc; 
    addStmtsInt("LRA", endAddr); 
    exprGen(nodeE->cnt2); 
    if (nodeE->cnt2->dtype != TYPE_INT){
        addStmts("FTI"); 
    }
    addStmts("STO"); 
    int cntStart = stmtsCnt + 1; 
    addrGen(nodeE->left); 
    addStmts("LOD"); 
    addStmtsInt("LRA", endAddr); 
    addStmts("LOD"); 
    addStmts("GEI"); 
    addStmts("NOP"); 
    int jmpToEnd = stmtsCnt; 
    treeGen(nodeE->right);
    addrGen(nodeE->left); 
    addrGen(nodeE->left); 
    addStmts("LOD"); 
    addStmts("LLI 1"); 
    addStmts("SBI"); 
    addStmts("STO"); 
    addStmtsInt("JMP", cntStart); 
    replaceStmtsInt(jmpToEnd, "JPF", stmtsCnt+1); 
}

//----------------------------------------------------------------------------------
// function to generate code for each node in the tree (from root node)
//----------------------------------------------------------------------------------
void treeGen(Node *root){
    if(DEBUG){
        printf("TEST: treeGen() started: --------------- \n"); 
    }
    while(root != NULL) {
        switch (root->kind)
        {
        case ASSIGNMENT_OP:
            assignmtGen(root); 
            break;
        case EXIT_OP: 
            addStmts("HLT"); 
            break; 
        case PRINT_OP:
            printGen(root); 
            break; 
        case READ_OP:
            readGen(root); 
            break; 
        case IF_OP:
            ifGen(root); 
            break; 
        case IFELSE_OP: 
            ifelseGen(root); 
            break; 
        case WHILE_OP: 
            whileGen(root); 
            break; 
        case COUNTUP_OP: 
            cntupGen(root); 
            break; 
        case COUNTDOWN_OP: 
            cntdownGen(root); 
            break; 
        default:
            break;
        }
        root = root->next; 
    }
    if(DEBUG){
        printf("TEST: treeGen() finished: --------------- \n"); 
    }
}

//----------------------------------------------------------------------------------
// function for code generation (starting at the root global node from parser)
//----------------------------------------------------------------------------------
void codeGen() {
	statements = (char **)malloc(size * sizeof(char *));
	addStmts("NOP"); // Reserve spot for allocate space for vars ISP replace 
    treeGen(root); 
	addStmts("HLT");
    replaceStmtsInt(0, "ISP", STSize()); 
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
