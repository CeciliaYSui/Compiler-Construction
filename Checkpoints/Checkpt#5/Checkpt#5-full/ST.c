/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Course ---------------- Compiler Construction
 * Filename -------------- ST.c
 * Date of Submission ---- October 28, 2019
 * Assignment ------------ Checkpoint #5 
 * Description ----------- Add action code to build a symbol table 
 * ========================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ST.h"

SymbolTable ST;

void init() {
		ST.size = 0;
		ST.address = 0; 
}

void STPrint() {
	printf("\n------------------------------------------------------------\n"); 
	printf("Symbol Table: \n");
	printf("Data Type\tVariable\tAddress \tDim \tLength \n"); 
	for ( int i = 0; i < ST.size; i++) {
		Variable v = ST.table[i];
        char* dtype = "REAL    ";
        if (v.dtype == TYPE_INT){
            dtype = "INTEGER";
        }
		char* arr = "scaler"; 
		if (v.isArray != 0){
			arr = "vector"; 
		}
		printf("%s \t%s \t\t@address %d \t%s \tlength:%d \n", dtype, v.varname, v.loc, arr, v.arrlen);
	}
	printf("------------------------------------------------------------\n"); 
}

Variable* STLookup(char* c) {
	for(int i = 0; i < ST.size; i++) {
		if(strcmp(ST.table[i].varname, c) == 0) { // if equals
			return &ST.table[i]; // dereference for values
		}
	}
	return NULL; // if empty ST
}

void STInsert(Type dtype, char* varname, int arrlen, int isArray) {
	Variable* v = malloc(sizeof(Variable)); 
	v->dtype = dtype; 
	v->arrlen = arrlen; 
	v->varname = varname; 
	v->isArray = isArray; 
	// error checking
	if(ST.size > ST_MAX_VAR) {
		printf("ERROR: Exceed memory limits! \n");
		exit(-1);
	}
	if(STLookup(v->varname)) {
		printf("ERROR: Duplicate variable \"%s\"! \n", v->varname);
		exit(-1);
	}
	// update ST
	v->loc = ST.address;
	ST.address += v->arrlen;
	ST.table[ST.size] = *v;
	ST.size++;
}
