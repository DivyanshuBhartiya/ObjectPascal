
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
     ABSOLUTE = 258,
     CONSTRUCT = 259,
     DESTRUCT = 260,
     INHERITED = 261,
     IMPLEMENT = 262,
     INLINE = 263,
     INTERFACE = 264,
     OBJ = 265,
     ON = 266,
     OP = 267,
     REINTRO = 268,
     SELF = 269,
     SHL = 270,
     SHR = 271,
     STRING = 272,
     UNIT = 273,
     USES = 274,
     XOR = 275,
     CLASS = 276,
     EXCEPT = 277,
     EXPORTS = 278,
     FINALIZATION = 279,
     FINALLY = 280,
     OUT = 281,
     PROPERTY = 282,
     RAISE = 283,
     THREADVAR = 284,
     TRY = 285,
     DISPOSE = 286,
     EXIT = 287,
     FALS = 288,
     NEW = 289,
     TRU = 290,
     AND = 291,
     ARRAY = 292,
     CASE = 293,
     CONST = 294,
     DIV = 295,
     DO = 296,
     DOWNTO = 297,
     ELSE = 298,
     END = 299,
     EXTERN = 300,
     FOR = 301,
     FORWARD = 302,
     FUNC = 303,
     GOTO = 304,
     IF = 305,
     LABEL = 306,
     MOD = 307,
     NOT = 308,
     NIL = 309,
     OF = 310,
     OR = 311,
     OTHERWISE = 312,
     PACKED = 313,
     PBEGIN = 314,
     PROCEDURE = 315,
     PFILE = 316,
     PROGRAM = 317,
     RECORD = 318,
     SET = 319,
     REPEAT = 320,
     THEN = 321,
     TO = 322,
     TYPE = 323,
     UNTIL = 324,
     VAR = 325,
     WHILE = 326,
     WITH = 327,
     ABSTRACT = 328,
     ALIAS = 329,
     ASSEMBLER = 330,
     CDECL = 331,
     CPPDECL = 332,
     DEFAULT = 333,
     EXPORT = 334,
     FAR = 335,
     FAR16 = 336,
     INDEX = 337,
     LOCAL = 338,
     NAME = 339,
     NEAR = 340,
     NOSTACKFRAME = 341,
     OLDFPCCALL = 342,
     PASCAL = 343,
     PRIVATE = 344,
     PROTECTED = 345,
     PUBLIC = 346,
     PUBLISHED = 347,
     READ = 348,
     REGISTER = 349,
     SAFECALL = 350,
     SOFTFLOAT = 351,
     STDCALL = 352,
     VIRTUAL = 353,
     WRITE = 354,
     WRITELN = 355,
     ASSIGN = 356,
     COLON = 357,
     COMMA = 358,
     DOT = 359,
     DOTDOT = 360,
     PTRUE = 361,
     PFALSE = 362,
     EQUAL = 363,
     GE = 364,
     GT = 365,
     LE = 366,
     LT = 367,
     LSQBRACK = 368,
     RSQBRACK = 369,
     LPAREN = 370,
     RPAREN = 371,
     MINUS = 372,
     NOTEQUAL = 373,
     PLUS = 374,
     SEMICOLON = 375,
     SLASH = 376,
     STAR = 377,
     STARSTAR = 378,
     UPARROW = 379,
     EXCLA = 380,
     BITNOT = 381,
     BITAND = 382,
     BITOR = 383,
     DOLLAR = 384,
     PERCENT = 385,
     HASH = 386,
     ATTHERATE = 387,
     OVERRIDE = 388,
     IMPLEMENTATION = 389,
     RESOURCESTRING = 390,
     LIBRARY = 391,
     RESIDENT = 392,
     INITIALIZATION = 393,
     PACKAGE = 394,
     REQUIRES = 395,
     CONTAINS = 396,
     ADDROF = 397,
     DISPINTERFACE = 398,
     READONLY = 399,
     WRITEONLY = 400,
     NODEFAULT = 401,
     store_argumentD = 402,
     IMPLEMENTS = 403,
     MESSAGE = 404,
     EXTERNAL = 405,
     ASMBODY = 406,
     AT = 407,
     ASCIICHAR = 408,
     REAL48 = 409,
     SINGLE = 410,
     DOUBLE = 411,
     REALS = 412,
     EXTENDED = 413,
     CURRENCY = 414,
     COMP = 415,
     SHORTINT = 416,
     SMALLINT = 417,
     QWORD = 418,
     BYTE = 419,
     LONGINT = 420,
     INT64 = 421,
     WORD = 422,
     BOOLEAN = 423,
     CHAR = 424,
     WIDECHAR = 425,
     LONGWORD = 426,
     PCHAR = 427,
     CARDINAL = 428,
     OLEVARIANT = 429,
     ANSISTR = 430,
     WIDESTR = 431,
     AUTOMATED = 432,
     DYNAMIC = 433,
     OVERLOAD = 434,
     VARIANT = 435,
     INTEGER = 436,
     IDENT = 437,
     OCTAL = 438,
     BINARY = 439,
     HEXA = 440,
     CHAR_STRING = 441,
     INT = 442,
     FLOAT = 443,
     REAL = 444,
     IFX = 445
   };
#endif
/* Tokens.  */
#define ABSOLUTE 258
#define CONSTRUCT 259
#define DESTRUCT 260
#define INHERITED 261
#define IMPLEMENT 262
#define INLINE 263
#define INTERFACE 264
#define OBJ 265
#define ON 266
#define OP 267
#define REINTRO 268
#define SELF 269
#define SHL 270
#define SHR 271
#define STRING 272
#define UNIT 273
#define USES 274
#define XOR 275
#define CLASS 276
#define EXCEPT 277
#define EXPORTS 278
#define FINALIZATION 279
#define FINALLY 280
#define OUT 281
#define PROPERTY 282
#define RAISE 283
#define THREADVAR 284
#define TRY 285
#define DISPOSE 286
#define EXIT 287
#define FALS 288
#define NEW 289
#define TRU 290
#define AND 291
#define ARRAY 292
#define CASE 293
#define CONST 294
#define DIV 295
#define DO 296
#define DOWNTO 297
#define ELSE 298
#define END 299
#define EXTERN 300
#define FOR 301
#define FORWARD 302
#define FUNC 303
#define GOTO 304
#define IF 305
#define LABEL 306
#define MOD 307
#define NOT 308
#define NIL 309
#define OF 310
#define OR 311
#define OTHERWISE 312
#define PACKED 313
#define PBEGIN 314
#define PROCEDURE 315
#define PFILE 316
#define PROGRAM 317
#define RECORD 318
#define SET 319
#define REPEAT 320
#define THEN 321
#define TO 322
#define TYPE 323
#define UNTIL 324
#define VAR 325
#define WHILE 326
#define WITH 327
#define ABSTRACT 328
#define ALIAS 329
#define ASSEMBLER 330
#define CDECL 331
#define CPPDECL 332
#define DEFAULT 333
#define EXPORT 334
#define FAR 335
#define FAR16 336
#define INDEX 337
#define LOCAL 338
#define NAME 339
#define NEAR 340
#define NOSTACKFRAME 341
#define OLDFPCCALL 342
#define PASCAL 343
#define PRIVATE 344
#define PROTECTED 345
#define PUBLIC 346
#define PUBLISHED 347
#define READ 348
#define REGISTER 349
#define SAFECALL 350
#define SOFTFLOAT 351
#define STDCALL 352
#define VIRTUAL 353
#define WRITE 354
#define WRITELN 355
#define ASSIGN 356
#define COLON 357
#define COMMA 358
#define DOT 359
#define DOTDOT 360
#define PTRUE 361
#define PFALSE 362
#define EQUAL 363
#define GE 364
#define GT 365
#define LE 366
#define LT 367
#define LSQBRACK 368
#define RSQBRACK 369
#define LPAREN 370
#define RPAREN 371
#define MINUS 372
#define NOTEQUAL 373
#define PLUS 374
#define SEMICOLON 375
#define SLASH 376
#define STAR 377
#define STARSTAR 378
#define UPARROW 379
#define EXCLA 380
#define BITNOT 381
#define BITAND 382
#define BITOR 383
#define DOLLAR 384
#define PERCENT 385
#define HASH 386
#define ATTHERATE 387
#define OVERRIDE 388
#define IMPLEMENTATION 389
#define RESOURCESTRING 390
#define LIBRARY 391
#define RESIDENT 392
#define INITIALIZATION 393
#define PACKAGE 394
#define REQUIRES 395
#define CONTAINS 396
#define ADDROF 397
#define DISPINTERFACE 398
#define READONLY 399
#define WRITEONLY 400
#define NODEFAULT 401
#define store_argumentD 402
#define IMPLEMENTS 403
#define MESSAGE 404
#define EXTERNAL 405
#define ASMBODY 406
#define AT 407
#define ASCIICHAR 408
#define REAL48 409
#define SINGLE 410
#define DOUBLE 411
#define REALS 412
#define EXTENDED 413
#define CURRENCY 414
#define COMP 415
#define SHORTINT 416
#define SMALLINT 417
#define QWORD 418
#define BYTE 419
#define LONGINT 420
#define INT64 421
#define WORD 422
#define BOOLEAN 423
#define CHAR 424
#define WIDECHAR 425
#define LONGWORD 426
#define PCHAR 427
#define CARDINAL 428
#define OLEVARIANT 429
#define ANSISTR 430
#define WIDESTR 431
#define AUTOMATED 432
#define DYNAMIC 433
#define OVERLOAD 434
#define VARIANT 435
#define INTEGER 436
#define IDENT 437
#define OCTAL 438
#define BINARY 439
#define HEXA 440
#define CHAR_STRING 441
#define INT 442
#define FLOAT 443
#define REAL 444
#define IFX 445




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 29 "syntacticAnalyzer.y"
     // UNION DEFINITION FOR YYLVAL
  int ival; 
  double dval;
  char name[256];
  Type* type;



/* Line 1676 of yacc.c  */
#line 441 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


