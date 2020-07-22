/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ADDITION = 258,
     SUBTRACTION = 259,
     MULTIPLICATION = 260,
     DIVISION = 261,
     MODULUS = 262,
     LESSTHAN = 263,
     GREATERTHAN = 264,
     LESSOREQUAL = 265,
     GREATEROREQUAL = 266,
     EQUAL = 267,
     NOTEQUAL = 268,
     AND = 269,
     OR = 270,
     NOT = 271,
     LPARENTH = 272,
     RPARENTH = 273,
     LBRACKET = 274,
     RBRACKET = 275,
     SEMICOLON = 276,
     COLON = 277,
     COMMA = 278,
     ASSIGN = 279,
     CARRIAGERETURN = 280,
     MAIN = 281,
     END = 282,
     EXIT = 283,
     IF = 284,
     ELSE = 285,
     WHILE = 286,
     TO = 287,
     COUNTING = 288,
     UPWARD = 289,
     DOWNWARD = 290,
     REAL = 291,
     INTEGER = 292,
     DATA = 293,
     ALGORITHM = 294,
     READ = 295,
     PRINT = 296,
     VARIABLE = 297,
     STRING = 298,
     INTCONSTANT = 299,
     REALCONSTANT = 300,
     NEWLINE = 301,
     TRASH = 302
   };
#endif
/* Tokens.  */
#define ADDITION 258
#define SUBTRACTION 259
#define MULTIPLICATION 260
#define DIVISION 261
#define MODULUS 262
#define LESSTHAN 263
#define GREATERTHAN 264
#define LESSOREQUAL 265
#define GREATEROREQUAL 266
#define EQUAL 267
#define NOTEQUAL 268
#define AND 269
#define OR 270
#define NOT 271
#define LPARENTH 272
#define RPARENTH 273
#define LBRACKET 274
#define RBRACKET 275
#define SEMICOLON 276
#define COLON 277
#define COMMA 278
#define ASSIGN 279
#define CARRIAGERETURN 280
#define MAIN 281
#define END 282
#define EXIT 283
#define IF 284
#define ELSE 285
#define WHILE 286
#define TO 287
#define COUNTING 288
#define UPWARD 289
#define DOWNWARD 290
#define REAL 291
#define INTEGER 292
#define DATA 293
#define ALGORITHM 294
#define READ 295
#define PRINT 296
#define VARIABLE 297
#define STRING 298
#define INTCONSTANT 299
#define REALCONSTANT 300
#define NEWLINE 301
#define TRASH 302




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "Slic_parser.y"
{
   int intval; 
   float realval; 
   char *sval;
}
/* Line 1529 of yacc.c.  */
#line 149 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

