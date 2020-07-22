/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Course ---------------- Compiler Construction
 * Filename -------------- ST.h
 * Date of Submission ---- December 3, 2019
 * Assignment ------------ Checkpoint #8
 * Description ----------- Add action code to build a symbol table 
 * 
 * Warning --------------- Modulus operator not working
 * ----------------------- Counting loops not working 
 * ========================================================================
 */

#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE
#define ST_MAX_VAR 1000

typedef enum  {
    TYPE_INT = 0,
    TYPE_REAL = 1
} Type;

typedef struct Variable Variable; 

struct Variable{
	Type dtype;
	char* varname;
	int loc; // address location start at 0
	int arrlen; // 1 for non-array vars 
	int isArray; // 0 F 1 T
};

typedef struct  {
	Variable table[ST_MAX_VAR];  //1000 chosen arbitrarily
	int size;
	int address; 
} SymbolTable;

void init();
void STPrint();
Variable* STLookup(char* c);
void STInsert(Type dtype, char* varname, int arrlen, int isArray);
int STSize(); 

#endif
