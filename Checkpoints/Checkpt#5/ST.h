/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Course ---------------- Compiler Construction
 * Filename -------------- ST.h
 * Date of Submission ---- October 28, 2019
 * Assignment ------------ Checkpoint #5 
 * Description ----------- Add action code to build a symbol table 
 * ========================================================================
 */

#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE
#define ST_MAX_VAR 1000

typedef enum  {
    TYPE_INT = 0,
    TYPE_REAL = 1
} Type;

typedef struct  {
	Type dtype;
	char* varname;
	int loc; // address location start at 0
	int arrlen; // 1 for non-array vars 
	int isArray; // 0 F 1 T
} Variable;

typedef struct  {
	Variable table[ST_MAX_VAR];  //1000 chosen arbitrarily
	int size;
} SymbolTable;

void init();
void STPrint();
Variable* STSearch(char* c);
void STInsert(Type dtype, char* varname, int arrlen, int isArray);

#endif
