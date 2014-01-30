
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syntacticAnalyzer.y"

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "Definitions.h"

extern char *yytext;
extern int yyleng;
extern int line_number;
extern unsigned int curScopeId;
extern unsigned int quadId;
extern int ifFlag;
extern FILE *data,*text;

void yyerror(char * error);

int errorFree = 1;
int errorFreeType = 1;
int flag = 1,counter = 0;
int numError = 0;
int numTypeError=0;
int i;
char tempName[256];
void errorLog();


/* Line 189 of yacc.c  */
#line 102 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 29 "syntacticAnalyzer.y"
     // UNION DEFINITION FOR YYLVAL
  int ival; 
  double dval;
  char name[256];
  Type* type;



/* Line 214 of yacc.c  */
#line 527 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 539 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2764

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  191
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  138
/* YYNRULES -- Number of rules.  */
#define YYNRULES  350
/* YYNRULES -- Number of states.  */
#define YYNSTATES  529

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   445

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    33,    34,    38,    40,
      45,    47,    49,    53,    55,    59,    61,    62,    65,    67,
      69,    71,    73,    75,    78,    81,    84,    87,    90,    93,
      98,   105,   108,   110,   114,   116,   118,   120,   122,   124,
     126,   128,   133,   135,   137,   139,   141,   143,   148,   150,
     152,   154,   156,   158,   160,   162,   164,   166,   168,   170,
     173,   177,   180,   183,   186,   188,   190,   192,   194,   196,
     199,   202,   204,   208,   210,   214,   216,   218,   220,   225,
     228,   230,   233,   235,   237,   239,   241,   243,   245,   247,
     249,   251,   255,   257,   262,   264,   269,   271,   273,   276,
     278,   283,   287,   289,   292,   294,   297,   299,   301,   308,
     312,   314,   318,   320,   322,   325,   327,   331,   335,   337,
     341,   343,   345,   350,   352,   354,   358,   361,   366,   368,
     374,   375,   378,   379,   381,   384,   386,   390,   391,   393,
     395,   398,   403,   405,   409,   411,   413,   416,   418,   420,
     422,   424,   426,   431,   436,   441,   448,   452,   454,   456,
     460,   462,   465,   468,   469,   474,   479,   481,   483,   487,
     491,   498,   502,   507,   509,   511,   513,   517,   521,   523,
     525,   527,   529,   534,   539,   540,   544,   545,   547,   551,
     555,   557,   562,   565,   570,   573,   578,   581,   583,   587,
     589,   591,   593,   597,   599,   600,   602,   604,   606,   608,
     610,   612,   614,   616,   618,   622,   624,   626,   630,   632,
     637,   643,   653,   655,   657,   664,   666,   670,   671,   675,
     677,   681,   683,   687,   688,   691,   698,   705,   710,   716,
     722,   724,   726,   730,   732,   736,   738,   740,   742,   744,
     746,   748,   750,   755,   757,   759,   761,   763,   765,   770,
     772,   774,   776,   778,   780,   782,   784,   786,   788,   790,
     794,   797,   800,   803,   805,   807,   809,   810,   811,   814,
     816,   818,   821,   823,   826,   830,   833,   836,   840,   843,
     847,   850,   853,   855,   857,   861,   863,   865,   868,   871,
     873,   875,   877,   879,   881,   883,   885,   887,   889,   891,
     893,   895,   897,   899,   901,   903,   905,   907,   909,   911,
     913,   915,   917,   919,   921,   923,   925,   927,   929,   931,
     933,   935,   937,   939,   941,   943,   945,   947,   949,   951,
     953
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     192,     0,    -1,   194,    -1,     9,    -1,   134,    -1,    70,
      -1,    39,    -1,    68,    -1,   135,    -1,    10,    -1,    48,
      -1,    60,    -1,    59,    -1,   120,    -1,    44,    -1,   195,
     200,   104,    -1,    -1,    62,   197,   196,    -1,   120,    -1,
     115,   198,   116,   120,    -1,   182,    -1,   199,    -1,   198,
     103,   199,    -1,   182,    -1,   201,   267,   289,    -1,   202,
      -1,    -1,   202,   203,    -1,   204,    -1,   205,    -1,   206,
      -1,   265,    -1,   266,    -1,    39,   207,    -1,   204,   207,
      -1,    68,   221,    -1,   205,   221,    -1,    70,   261,    -1,
     206,   261,    -1,   182,   108,   208,   120,    -1,   182,   102,
     223,   108,   220,   120,    -1,     1,   193,    -1,   210,    -1,
     210,   209,   210,    -1,   108,    -1,   118,    -1,   112,    -1,
     110,    -1,   111,    -1,   109,    -1,   212,    -1,   210,   211,
     313,   212,    -1,   119,    -1,   117,    -1,    56,    -1,    20,
      -1,   214,    -1,   212,   213,   313,   214,    -1,   122,    -1,
     121,    -1,    40,    -1,    52,    -1,    15,    -1,    16,    -1,
      36,    -1,   216,    -1,   219,    -1,   320,    -1,    54,    -1,
     142,   214,    -1,   115,   208,   116,    -1,    53,   214,    -1,
     215,   214,    -1,   124,   214,    -1,   106,    -1,   107,    -1,
     119,    -1,   117,    -1,   328,    -1,   216,   217,    -1,   104,
     328,    -1,   124,    -1,   115,   218,   116,    -1,   208,    -1,
     208,   103,   208,    -1,   187,    -1,   188,    -1,   208,    -1,
     182,   108,   222,   120,    -1,     1,   193,    -1,   223,    -1,
      68,   223,    -1,   246,    -1,   224,    -1,   242,    -1,   229,
      -1,   230,    -1,   243,    -1,   322,    -1,   321,    -1,   228,
      -1,   225,   105,   225,    -1,   226,    -1,   225,   211,   313,
     226,    -1,   227,    -1,   226,   213,   313,   227,    -1,   328,
      -1,   219,    -1,   215,   227,    -1,   320,    -1,   328,   115,
     208,   116,    -1,   115,   208,   116,    -1,   182,    -1,   124,
     328,    -1,   231,    -1,    58,   231,    -1,   232,    -1,   235,
      -1,    37,   113,   233,   114,    55,   223,    -1,   234,   105,
     234,    -1,   187,    -1,    63,   236,    44,    -1,   237,    -1,
     238,    -1,   238,   120,    -1,   239,    -1,   238,   120,   239,
      -1,   240,   102,   223,    -1,   241,    -1,   241,   103,   240,
      -1,   182,    -1,   323,    -1,    17,   113,   208,   114,    -1,
     244,    -1,   245,    -1,   245,    55,    10,    -1,    60,   278,
      -1,    48,   278,   102,   283,    -1,   247,    -1,    10,   250,
     249,   248,    44,    -1,    -1,    89,   249,    -1,    -1,   252,
      -1,   252,   256,    -1,   256,    -1,   115,   251,   116,    -1,
      -1,   328,    -1,   253,    -1,   252,   253,    -1,   254,   102,
     223,   120,    -1,   255,    -1,   255,   103,   254,    -1,   182,
      -1,   257,    -1,   257,   256,    -1,   258,    -1,   268,    -1,
     270,    -1,   259,    -1,   260,    -1,     4,   269,   278,   271,
      -1,     5,   269,   278,   271,    -1,   263,   102,   223,   120,
      -1,   263,   102,   223,   108,   262,   120,    -1,   263,     1,
     193,    -1,   220,    -1,   264,    -1,   264,   103,   263,    -1,
     182,    -1,   268,   273,    -1,   270,   274,    -1,    -1,    60,
     269,   278,   271,    -1,    60,   269,     1,   193,    -1,   182,
      -1,   326,    -1,   269,   104,   328,    -1,   269,   104,   326,
      -1,    48,   272,   278,   102,   283,   271,    -1,    48,   272,
     271,    -1,    48,   272,     1,   193,    -1,   120,    -1,   182,
      -1,   326,    -1,   272,   104,   328,    -1,   272,   104,   326,
      -1,   275,    -1,   275,    -1,   277,    -1,   276,    -1,   202,
     267,   151,   120,    -1,   202,   267,   289,   120,    -1,    -1,
     115,   279,   116,    -1,    -1,   280,    -1,   279,   120,   280,
      -1,   281,   102,   284,    -1,   281,    -1,    70,   281,   102,
     284,    -1,    70,   281,    -1,    26,   281,   102,   284,    -1,
      26,   281,    -1,    39,   281,   102,   284,    -1,    39,   281,
      -1,   282,    -1,   282,   103,   281,    -1,   182,    -1,   328,
      -1,   283,    -1,   283,   108,   208,    -1,   286,    -1,    -1,
     287,    -1,   288,    -1,   289,    -1,   291,    -1,   294,    -1,
     300,    -1,   301,    -1,   302,    -1,   304,    -1,   315,   101,
     306,    -1,     1,    -1,   315,    -1,    59,   290,    44,    -1,
     285,    -1,   290,   120,   313,   285,    -1,    50,   306,    66,
     313,   292,    -1,    50,   306,    66,   313,   292,    43,   314,
     313,   293,    -1,   285,    -1,   285,    -1,    38,   306,    55,
     295,   299,    44,    -1,   296,    -1,   296,   120,   295,    -1,
      -1,   297,   102,   285,    -1,   298,    -1,   297,   103,   298,
      -1,   208,    -1,   208,   105,   208,    -1,    -1,    43,   290,
      -1,    65,   313,   290,    69,   313,   306,    -1,    71,   313,
     306,    41,   313,   285,    -1,    46,   303,    41,   285,    -1,
     328,   101,   306,    67,   306,    -1,   328,   101,   306,    42,
     306,    -1,   151,    -1,   306,    -1,   306,   103,   305,    -1,
     308,    -1,   308,   307,   308,    -1,   108,    -1,   118,    -1,
     112,    -1,   110,    -1,   111,    -1,   109,    -1,   310,    -1,
     308,   309,   313,   310,    -1,   119,    -1,   117,    -1,    56,
      -1,    20,    -1,   312,    -1,   310,   311,   313,   312,    -1,
     122,    -1,   121,    -1,    40,    -1,    52,    -1,    15,    -1,
      16,    -1,    36,    -1,   219,    -1,   320,    -1,    54,    -1,
     113,   319,   114,    -1,    53,   312,    -1,   215,   312,    -1,
     124,   312,    -1,   315,    -1,   106,    -1,   107,    -1,    -1,
      -1,   316,   317,    -1,   317,    -1,   142,    -1,   316,   142,
      -1,   328,    -1,     6,   328,    -1,   115,   306,   116,    -1,
     115,   116,    -1,   317,   318,    -1,   113,   305,   114,    -1,
     113,   114,    -1,   115,   305,   116,    -1,   115,   116,    -1,
     104,   328,    -1,   124,    -1,   306,    -1,   306,   105,   306,
      -1,   186,    -1,   153,    -1,   186,   320,    -1,   153,   320,
      -1,   157,    -1,   155,    -1,   156,    -1,   181,    -1,   168,
      -1,   169,    -1,    17,    -1,    78,    -1,    93,    -1,   100,
      -1,    99,    -1,   147,    -1,   146,    -1,   148,    -1,   145,
      -1,   144,    -1,   152,    -1,     3,    -1,    11,    -1,    84,
      -1,    82,    -1,   149,    -1,   141,    -1,   140,    -1,    47,
      -1,    26,    -1,    92,    -1,    91,    -1,    90,    -1,    89,
      -1,   139,    -1,    18,    -1,   136,    -1,    62,    -1,   150,
      -1,   182,    -1,   321,    -1,   322,    -1,   323,    -1,   324,
      -1,   325,    -1,   327,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    80,    83,    84,    87,    88,
      92,    98,    99,   103,   109,   115,   119,   120,   123,   124,
     125,   126,   127,   130,   131,   135,   136,   139,   140,   143,
     157,   172,   175,   179,   208,   209,   210,   211,   212,   213,
     216,   220,   268,   269,   270,   271,   274,   278,   356,   357,
     358,   359,   360,   361,   362,   365,   366,   367,   368,   369,
     370,   371,   379,   380,   381,   391,   403,   404,   407,   408,
     415,   416,   417,   420,   421,   424,   431,   439,   442,   447,
     450,   451,   452,   455,   456,   457,   458,   459,   462,   463,
     464,   465,   477,   478,   524,   525,   602,   603,   604,   605,
     606,   607,   610,   636,   639,   640,   643,   644,   647,   664,
     672,   675,   685,   688,   689,   692,   693,   696,   716,   717,
     720,   728,   729,   732,   735,   736,   739,   751,   767,   770,
     790,   791,   805,   806,   807,   808,   811,   829,   832,   835,
     836,   839,   860,   867,   875,   883,   890,   898,   901,   902,
     903,   904,   907,   910,   913,   931,   980,   993,   996,   997,
    1000,  1008,  1016,  1025,  1030,  1067,  1070,  1095,  1096,  1119,
    1122,  1161,  1162,  1165,  1167,  1191,  1192,  1214,  1217,  1220,
    1223,  1224,  1227,  1230,  1233,  1234,  1237,  1238,  1239,  1248,
    1269,  1270,  1291,  1292,  1313,  1314,  1336,  1339,  1346,  1354,
    1362,  1365,  1366,  1374,  1377,  1378,  1379,  1380,  1381,  1382,
    1383,  1384,  1385,  1386,  1389,  1413,  1416,  1570,  1576,  1581,
    1595,  1611,  1630,  1633,  1636,  1661,  1662,  1665,  1666,  1669,
    1670,  1683,  1684,  1697,  1698,  1701,  1720,  1741,  1777,  1798,
    1821,  1824,  1830,  1840,  1849,  1885,  1886,  1887,  1888,  1889,
    1890,  1893,  1900,  1948,  1949,  1950,  1951,  1954,  1963,  2048,
    2049,  2050,  2051,  2052,  2053,  2054,  2057,  2058,  2059,  2065,
    2066,  2074,  2080,  2087,  2207,  2217,  2230,  2236,  2242,  2247,
    2255,  2256,  2259,  2260,  2261,  2262,  2263,  2381,  2399,  2405,
    2413,  2418,  2425,  2433,  2434,  2450,  2460,  2461,  2462,  2465,
    2466,  2467,  2470,  2471,  2472,  2475,  2478,  2484,  2490,  2496,
    2502,  2508,  2514,  2520,  2526,  2535,  2536,  2537,  2538,  2539,
    2540,  2541,  2542,  2543,  2544,  2548,  2549,  2550,  2551,  2554,
    2555,  2556,  2557,  2558,  2561,  2583,  2584,  2585,  2586,  2587,
    2588
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ABSOLUTE", "CONSTRUCT", "DESTRUCT",
  "INHERITED", "IMPLEMENT", "INLINE", "INTERFACE", "OBJ", "ON", "OP",
  "REINTRO", "SELF", "SHL", "SHR", "STRING", "UNIT", "USES", "XOR",
  "CLASS", "EXCEPT", "EXPORTS", "FINALIZATION", "FINALLY", "OUT",
  "PROPERTY", "RAISE", "THREADVAR", "TRY", "DISPOSE", "EXIT", "FALS",
  "NEW", "TRU", "AND", "ARRAY", "CASE", "CONST", "DIV", "DO", "DOWNTO",
  "ELSE", "END", "EXTERN", "FOR", "FORWARD", "FUNC", "GOTO", "IF", "LABEL",
  "MOD", "NOT", "NIL", "OF", "OR", "OTHERWISE", "PACKED", "PBEGIN",
  "PROCEDURE", "PFILE", "PROGRAM", "RECORD", "SET", "REPEAT", "THEN", "TO",
  "TYPE", "UNTIL", "VAR", "WHILE", "WITH", "ABSTRACT", "ALIAS",
  "ASSEMBLER", "CDECL", "CPPDECL", "DEFAULT", "EXPORT", "FAR", "FAR16",
  "INDEX", "LOCAL", "NAME", "NEAR", "NOSTACKFRAME", "OLDFPCCALL", "PASCAL",
  "PRIVATE", "PROTECTED", "PUBLIC", "PUBLISHED", "READ", "REGISTER",
  "SAFECALL", "SOFTFLOAT", "STDCALL", "VIRTUAL", "WRITE", "WRITELN",
  "ASSIGN", "COLON", "COMMA", "DOT", "DOTDOT", "PTRUE", "PFALSE", "EQUAL",
  "GE", "GT", "LE", "LT", "LSQBRACK", "RSQBRACK", "LPAREN", "RPAREN",
  "MINUS", "NOTEQUAL", "PLUS", "SEMICOLON", "SLASH", "STAR", "STARSTAR",
  "UPARROW", "EXCLA", "BITNOT", "BITAND", "BITOR", "DOLLAR", "PERCENT",
  "HASH", "ATTHERATE", "OVERRIDE", "IMPLEMENTATION", "RESOURCESTRING",
  "LIBRARY", "RESIDENT", "INITIALIZATION", "PACKAGE", "REQUIRES",
  "CONTAINS", "ADDROF", "DISPINTERFACE", "READONLY", "WRITEONLY",
  "NODEFAULT", "store_argumentD", "IMPLEMENTS", "MESSAGE", "EXTERNAL",
  "ASMBODY", "AT", "ASCIICHAR", "REAL48", "SINGLE", "DOUBLE", "REALS",
  "EXTENDED", "CURRENCY", "COMP", "SHORTINT", "SMALLINT", "QWORD", "BYTE",
  "LONGINT", "INT64", "WORD", "BOOLEAN", "CHAR", "WIDECHAR", "LONGWORD",
  "PCHAR", "CARDINAL", "OLEVARIANT", "ANSISTR", "WIDESTR", "AUTOMATED",
  "DYNAMIC", "OVERLOAD", "VARIANT", "INTEGER", "IDENT", "OCTAL", "BINARY",
  "HEXA", "CHAR_STRING", "INT", "FLOAT", "REAL", "IFX", "$accept", "Goal",
  "error_recovery_token", "program_file", "program_heading",
  "program_heading_2", "program_name", "program_param_list",
  "program_param", "program_block", "program_decl_sect_list",
  "impl_decl_sect_list", "impl_decl_sect", "const_decl_sect",
  "type_decl_sect", "var_decl_sect", "const_decl", "const_expr",
  "const_relop", "const_simple_expr", "const_addop", "const_term",
  "const_mulop", "const_factor", "sign", "const_variable",
  "const_variable_2", "const_func_expr_list", "unsigned_number",
  "typed_const", "type_decl", "type_decl_type", "type_ref", "simple_type",
  "range_expr", "range_term", "range_factor", "simple_type_identifier",
  "pointer_type", "structured_type", "unpacked_structured_type",
  "array_type", "arr_simple_type", "arr_factor", "record_type",
  "field_list", "fixed_part", "fixed_part_2", "record_section",
  "record_section_id_list", "record_section_id", "string_type",
  "procedural_type", "procedural_type_kind", "procedural_type_decl",
  "object_type", "old_object_type", "oot_privat_list",
  "oot_component_list", "oot_successor", "oot_typeidentifier",
  "oot_field_list", "oot_field", "oot_id_list", "oot_field_identifier",
  "oot_method_list", "oot_method", "oot_method_head",
  "oot_constructor_head", "oot_destructor_head", "var_decl",
  "var_init_value", "var_name_list", "var_name", "proc_decl", "func_decl",
  "Marker3", "proc_heading", "proc_name", "func_heading", "fp_directives",
  "func_name", "proc_block", "func_block", "proc_block_decl", "asm_block",
  "block", "fp_list", "fp_sect_list", "fp_sect", "param_name_list",
  "param_name", "fptype", "fptype_new", "stmt", "unlabelled_stmt",
  "assignment", "proc_call", "compound_stmt", "stmt_list", "if_stmt",
  "then_branch", "else_branch", "case_stmt", "case_list", "case_item",
  "case_label_list", "case_label", "else_case", "repeat_stmt",
  "while_stmt", "for_stmt", "for_special", "asm_stmt", "expr_list", "expr",
  "relop", "simple_expr", "addop", "term", "mulop", "factor", "Marker",
  "Marker2", "var_reference", "var_address", "variable", "var_specifiers",
  "elem", "literal", "real_type_name", "ord_type_name", "string_type_name",
  "property_specifier_directives", "non_reserved", "visibility_specifier",
  "other", "identifier", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   191,   192,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   194,   195,   195,   196,   196,
     197,   198,   198,   199,   200,   201,   202,   202,   203,   203,
     203,   203,   203,   204,   204,   205,   205,   206,   206,   207,
     207,   207,   208,   208,   209,   209,   209,   209,   209,   209,
     210,   210,   211,   211,   211,   211,   212,   212,   213,   213,
     213,   213,   213,   213,   213,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   215,   215,   216,   216,
     217,   217,   217,   218,   218,   219,   219,   220,   221,   221,
     222,   222,   222,   223,   223,   223,   223,   223,   224,   224,
     224,   224,   225,   225,   226,   226,   227,   227,   227,   227,
     227,   227,   228,   229,   230,   230,   231,   231,   232,   233,
     234,   235,   236,   237,   237,   238,   238,   239,   240,   240,
     241,   242,   242,   243,   244,   244,   245,   245,   246,   247,
     248,   248,   249,   249,   249,   249,   250,   250,   251,   252,
     252,   253,   254,   254,   255,   256,   256,   257,   258,   258,
     258,   258,   259,   260,   261,   261,   261,   262,   263,   263,
     264,   265,   266,   267,   268,   268,   269,   269,   269,   269,
     270,   270,   270,   271,   272,   272,   272,   272,   273,   274,
     275,   275,   276,   277,   278,   278,   279,   279,   279,   280,
     280,   280,   280,   280,   280,   280,   280,   281,   281,   282,
     283,   284,   284,   285,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   287,   287,   288,   289,   290,   290,
     291,   291,   292,   293,   294,   295,   295,   296,   296,   297,
     297,   298,   298,   299,   299,   300,   301,   302,   303,   303,
     304,   305,   305,   306,   306,   307,   307,   307,   307,   307,
     307,   308,   308,   309,   309,   309,   309,   310,   310,   311,
     311,   311,   311,   311,   311,   311,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   313,   314,   315,   315,
     316,   316,   317,   317,   317,   317,   317,   318,   318,   318,
     318,   318,   318,   319,   319,   320,   320,   320,   320,   321,
     321,   321,   322,   322,   322,   323,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   326,   326,   326,   326,   327,
     327,   327,   327,   327,   328,   328,   328,   328,   328,   328,
     328
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     3,     1,     4,
       1,     1,     3,     1,     3,     1,     0,     2,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     4,
       6,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     2,     2,     2,     1,     1,     1,     1,     1,     2,
       2,     1,     3,     1,     3,     1,     1,     1,     4,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     4,     1,     4,     1,     1,     2,     1,
       4,     3,     1,     2,     1,     2,     1,     1,     6,     3,
       1,     3,     1,     1,     2,     1,     3,     3,     1,     3,
       1,     1,     4,     1,     1,     3,     2,     4,     1,     5,
       0,     2,     0,     1,     2,     1,     3,     0,     1,     1,
       2,     4,     1,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     4,     4,     4,     6,     3,     1,     1,     3,
       1,     2,     2,     0,     4,     4,     1,     1,     3,     3,
       6,     3,     4,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     4,     4,     0,     3,     0,     1,     3,     3,
       1,     4,     2,     4,     2,     4,     2,     1,     3,     1,
       1,     1,     3,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     3,     1,     4,
       5,     9,     1,     1,     6,     1,     3,     0,     3,     1,
       3,     1,     3,     0,     2,     6,     6,     4,     5,     5,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     2,     2,     1,     1,     1,     0,     0,     2,     1,
       1,     2,     1,     2,     3,     2,     2,     3,     2,     3,
       2,     2,     1,     1,     3,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
      16,     0,     0,     2,    26,    20,     0,     1,     0,   173,
      25,     0,    18,    17,    15,     0,     0,     0,     0,     0,
       0,    27,     0,     0,    30,    31,    32,    26,    26,    23,
       0,    21,     0,    24,     0,     0,    33,   338,   337,   336,
     335,   184,     0,   185,   176,     0,   177,     0,     0,    35,
     170,    37,     0,   168,    34,    36,    38,   173,   171,   188,
     191,   190,   172,   189,     0,     0,   225,   326,     0,   327,
     315,   340,   334,     0,     0,   333,     0,   342,   286,   286,
     316,   329,   328,   317,   319,   318,     0,   341,   339,   332,
     331,   290,   324,   323,   321,   320,   322,   330,   343,   250,
     325,   310,   311,   309,   313,   314,   312,   344,   228,   213,
     215,   216,   217,     0,   218,   219,   220,   221,   222,   223,
     226,     0,   289,   345,   346,   347,   348,   349,   350,   292,
       3,     9,     6,    14,    10,    12,    11,     7,     5,    13,
       4,     8,    41,     0,     0,     0,     0,   196,   183,   181,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
      22,    19,   293,     0,   278,   284,   285,     0,    77,    76,
       0,   306,   305,    85,    86,     0,   276,     0,   253,   261,
     267,   283,   277,     0,     0,     0,     0,     0,   295,     0,
     227,   286,     0,   291,   288,     0,     0,     0,   302,   296,
     315,     0,   194,     0,   194,     0,     0,     0,   344,     0,
     107,     0,    93,     0,   102,   104,   100,    95,    96,   114,
     116,   117,    94,    97,   133,   134,   109,   345,   346,   347,
     106,     0,    68,    74,    75,     0,     0,     0,     0,    42,
      50,    56,     0,    65,    66,    67,    78,   182,   187,   186,
       0,     0,     0,   209,     0,   197,   200,   207,     0,   175,
     179,   178,   174,   147,     0,     0,    90,    92,   138,   166,
       0,   169,     0,     0,   280,   303,     0,   282,   308,   307,
     281,   237,   266,   265,   255,   260,   258,   259,   257,   264,
     256,   263,     0,   286,   273,   274,   275,   271,   272,   270,
     269,   286,     0,     0,   286,     0,     0,   294,     0,   224,
     301,   298,     0,   251,   300,     0,     0,     0,     0,   115,
     136,   130,     0,   122,   123,   125,     0,   128,     0,   113,
     108,     0,    55,    54,     0,    53,    52,   286,    62,    63,
      64,    60,    61,    59,    58,   286,     0,     0,    71,     0,
      73,    69,    39,    44,    49,    47,    48,    46,    45,     0,
     286,   286,    72,     0,     0,    81,    79,   204,   206,   202,
     195,     0,     0,     0,     0,   210,     0,   142,    91,    88,
       0,   164,   192,   193,     0,   279,   241,   243,   235,     0,
     239,   254,     0,     0,   247,     0,     0,   286,   286,   229,
     297,     0,   299,     0,   120,     0,     0,     0,   121,   124,
       0,     0,   111,    87,     0,   101,     0,     0,   135,     0,
      70,    43,     0,     0,    80,    83,     0,     0,     0,     0,
     198,   211,   199,   208,   180,     0,   148,     0,     0,   154,
     140,   143,   149,     0,   152,   145,   155,   157,   160,   161,
     158,   159,   167,     0,   304,     0,     0,     0,   237,     0,
       0,   262,   268,     0,     0,   232,   230,     0,     0,   252,
     132,     0,     0,   137,   126,   127,   129,    40,   103,   105,
     110,    51,    57,     0,    82,   203,   205,   201,     0,   146,
     194,   194,   142,     0,   150,   144,     0,     0,   156,   165,
     242,   244,   234,   236,   238,   240,   249,   248,   287,   245,
     246,     0,   119,    84,   212,     0,     0,   141,   139,     0,
     153,   286,   118,   162,   163,   151,     0,   233,   231
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   142,     3,     4,    13,     6,    30,    31,     8,
       9,    57,    21,    22,    23,    24,    36,   386,   359,   239,
     337,   240,   345,   241,   242,   243,   366,   426,   244,   414,
      49,   265,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   405,   406,   221,   322,   323,   324,   325,   326,
     327,   222,   223,   224,   225,   267,   268,   493,   440,   377,
     435,   441,   442,   443,   444,   445,   446,   447,   448,   449,
      51,   453,    52,    53,    25,    26,    15,   450,    45,   451,
     149,    42,    58,    62,    59,    60,    61,   150,   254,   255,
     256,   257,   431,   432,   108,   109,   110,   111,   112,   113,
     114,   466,   528,   115,   387,   388,   389,   390,   457,   116,
     117,   118,   183,   119,   312,   313,   292,   178,   293,   179,
     301,   180,   186,   521,   181,   121,   122,   199,   276,   245,
     123,   124,   125,   126,   127,    46,   128,   129
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -313
static const yytype_int16 yypact[] =
{
      31,  -107,   126,  -313,  -313,  -313,    24,  -313,    32,  -313,
     243,   -40,  -313,  -313,  -313,   125,     3,   -27,   -23,    27,
       8,  -313,    22,   268,     8,  -313,  -313,  -313,  -313,  -313,
     -29,  -313,  2090,  -313,   143,     1,  -313,  -313,  -313,  -313,
    -313,  -313,    47,  -313,  -313,    41,  -313,   143,    87,  -313,
    -313,  -313,    45,    94,  -313,  -313,  -313,   243,  -313,  -313,
    -313,  -313,  -313,  -313,   -40,    81,  -313,  -313,  2582,  -313,
    -313,  -313,  -313,   998,  2582,  -313,   998,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,   647,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,    44,  -313,  -313,  -313,  -313,  -313,  -313,
     106,  2471,    -2,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  1232,  1343,   143,  2360,     6,  -313,  -313,
     115,   143,  2360,    99,  -313,  1115,   143,  1232,     8,   -19,
    -313,  -313,  -313,   998,  -313,  -313,  -313,   998,  -313,  -313,
     998,   -74,   -74,  -313,  -313,   998,  -313,   172,   413,   422,
    -313,  -313,  -313,   193,   148,   173,  2249,   998,  -313,   139,
    -313,  -313,   998,  -313,    -2,  2582,   764,   881,  -313,  -313,
     141,   144,   146,    21,   146,    74,  1343,  2582,    11,  1454,
    -313,   150,  -313,   279,   424,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,   204,  -313,    13,    15,    60,
     151,  1343,  -313,  -313,  -313,  1343,  1343,  1343,   147,   446,
     424,  -313,  1343,   138,  -313,  -313,  -313,  -313,  -313,  -313,
      89,    89,    89,  -313,    73,  -313,   177,   180,  2582,  -313,
    -313,  -313,  -313,   160,  1232,   164,  -313,  -313,  -313,  -313,
     -25,  -313,   165,   166,  -313,   185,   181,  -313,  -313,  -313,
    -313,  1343,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,   998,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  1613,   998,  -313,   -22,   253,  -313,  1772,  -313,
    -313,  -313,   186,   198,  -313,   188,  1343,   121,   203,  -313,
    -313,  -313,   273,  -313,   192,  -313,   217,   215,   205,  -313,
    -313,  1343,  -313,  -313,  1454,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,   313,  1343,  -313,   210,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  1343,
    -313,  -313,  -313,  2582,  1343,  -313,  -313,   227,   228,   229,
    -313,     6,  2582,    89,    99,  -313,  2582,    48,  -313,  -313,
    1343,  -313,  -313,  -313,   998,  -313,   232,   289,   213,   130,
    -313,    29,   998,   998,  -313,    30,  1613,  -313,  -313,  -313,
    -313,   998,  -313,   220,  -313,   225,   235,  2582,  -313,    74,
    1232,    74,  -313,  -313,   222,   118,  1454,  1454,  -313,   230,
    -313,   118,  1343,  1343,  -313,   242,   231,  2582,  2582,  2582,
    -313,   241,  -313,  -313,  -313,   236,  -313,   -23,   -23,  -313,
     266,    48,  -313,   256,   262,  -313,    46,  -313,  -313,  -313,
    -313,  -313,  -313,   247,  -313,  1343,  2090,   324,  1343,  1931,
    1343,   422,  -313,   998,   998,  -313,   326,   998,  1613,  -313,
    -313,   315,   121,  -313,  -313,  -313,  -313,  -313,   424,  -313,
    -313,   424,  -313,  1343,  -313,  -313,  -313,  -313,  1343,  -313,
      -5,    -5,    48,   328,  -313,  -313,  1232,   194,  -313,  -313,
    -313,   254,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  1232,  -313,  -313,  -313,    99,    99,  -313,  -313,   260,
    -313,  -313,  -313,  -313,  -313,  -313,  1613,  -313,  -313
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -313,  -313,    54,  -313,  -313,  -313,  -313,  -313,   323,  -313,
    -313,   384,  -313,  -313,  -313,  -313,   368,  -135,  -313,    34,
    -221,   -18,  -235,  -198,   216,  -313,  -313,  -313,   342,    19,
     377,  -313,  -101,  -313,    72,    -9,  -193,  -313,  -313,  -313,
     206,  -313,  -313,   -61,  -313,  -313,  -313,  -313,     5,     9,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,   -76,  -313,
    -313,  -313,   -20,   -71,  -313,  -263,  -313,  -313,  -313,  -313,
     399,  -313,   271,  -313,  -313,  -313,   374,    50,  -186,    63,
    -138,  -313,  -313,  -313,   404,  -313,  -313,   -44,  -313,    70,
    -216,  -313,  -228,  -312,  -282,  -313,  -313,  -313,    16,  -183,
    -313,  -313,  -313,  -313,   -24,  -313,  -313,   -11,  -313,  -313,
    -313,  -313,  -313,  -313,  -185,   -62,  -313,   159,  -313,    61,
    -313,  -153,   -73,  -313,   -32,  -313,   321,  -313,  -313,    51,
    -136,  -130,  -114,  -313,  -313,    20,  -313,   -66
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -215
static const yytype_int16 yytable[] =
{
     120,   153,   162,   305,    34,   361,   187,   227,   184,   238,
     274,   177,   315,   228,   185,   262,   330,   277,   360,   227,
     394,   227,   280,    34,   189,   228,   399,   228,    47,   229,
     374,    33,   250,   348,   367,   368,   369,    43,   350,   351,
      32,   229,   151,   229,   362,   251,   156,   397,   145,   282,
     437,   438,   437,   438,   266,  -112,   270,   -99,   201,   -98,
      27,   -28,    37,    38,    39,    40,    37,    38,    39,    40,
     -28,   328,   463,    28,    64,     5,   252,   230,   246,   171,
     249,   -28,   -28,   380,   205,   283,   261,    65,   190,   230,
     -28,   230,   -28,     1,    17,   381,    17,   464,   191,   152,
     349,   154,   195,   143,  -131,   275,    18,    27,    18,   144,
     147,   196,   172,   197,   465,   485,   486,   487,   308,  -112,
      28,   -99,   198,   -98,   182,   306,     7,   182,   227,   310,
     309,  -112,   272,   -99,   228,   -98,    14,   182,   332,    11,
     246,   329,    29,   230,    12,   152,   289,   157,   291,  -194,
     229,   146,   130,   131,   120,    41,   147,   433,   318,    44,
     320,  -194,   147,   378,   191,   246,   248,   148,  -131,   246,
     246,   246,   260,   -28,   333,   273,   246,   504,   495,   473,
    -131,   403,   132,   498,    32,    35,   510,   133,   253,   370,
      50,   134,   375,   371,   226,   155,   413,   158,   230,   247,
     360,   161,   135,   136,    35,   259,   226,   192,   226,    48,
     269,   137,   419,   138,   182,   246,   469,   258,   182,   148,
     392,   182,   278,   279,   479,   482,   182,   281,   393,   425,
     439,   396,   459,   460,   302,   335,   434,   336,   182,   304,
     462,   395,   363,   182,   527,   413,   361,   182,   182,   303,
     246,   490,   491,   364,   316,   307,   321,   317,   331,   346,
     226,   147,   365,   139,   416,   246,   347,   352,   230,    47,
     120,   253,   417,   501,   227,   376,   120,   140,   141,   372,
     228,   246,    16,   373,   379,   382,   383,   422,   423,   175,
     384,    17,   175,   246,   398,   385,   229,   424,   246,   332,
     400,   401,   175,    18,   402,   407,   375,   -29,   404,   475,
     436,    19,   409,    20,   246,   226,   -29,   408,   411,   410,
     500,   412,   454,   418,   467,   468,   420,   -29,   -29,   427,
     428,   429,   456,   458,   470,   333,   -29,   455,   -29,   471,
     472,   375,   477,   182,   230,   483,   480,   484,   513,   488,
     230,   230,   489,   514,   182,   492,   246,   246,   496,   209,
     227,   375,   375,   375,   120,   497,   228,   499,   502,   508,
     511,   209,   518,   209,   191,   227,   439,   523,   524,   175,
     525,   228,   229,   175,   334,   226,   175,   160,    10,   246,
      54,   175,   246,   421,   246,   519,   335,   229,   336,   452,
      55,   506,   507,   175,   481,   509,   415,   478,   175,   319,
     522,   512,   175,   175,   474,   176,   517,   246,   176,   -29,
     476,   494,   246,    56,   120,   209,   520,   120,   176,   271,
     230,   159,    63,   282,   503,   182,   120,   294,   295,   338,
     339,   430,   194,   182,   182,   230,   515,   516,   526,   505,
      48,   391,   182,   461,     0,     0,     0,     0,   296,     0,
     340,   226,   297,     0,   341,     0,   332,   226,   226,   283,
       0,     0,     0,     0,   298,     0,   342,     0,     0,     0,
     209,     0,     0,     0,     0,   210,     0,     0,     0,     0,
       0,     0,     0,     0,   120,     0,     0,   210,     0,   210,
       0,     0,   333,     0,     0,   176,     0,     0,   175,   176,
       0,     0,   176,     0,   182,   182,     0,   176,   182,   175,
       0,   284,   285,   286,   287,   288,     0,     0,     0,   176,
     289,   290,   291,     0,   176,     0,     0,     0,   176,   176,
       0,     0,     0,   299,   300,   343,   344,   226,     0,     0,
     209,   210,     0,     0,   353,   354,   355,   356,   357,     0,
       0,     0,   226,   335,   358,   336,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     175,     0,     0,     0,     0,     0,   210,     0,   175,   175,
       0,     0,     0,     0,     0,     0,     0,   175,     0,     0,
       0,     0,     0,     0,     0,     0,   209,     0,     0,     0,
       0,     0,   209,   209,   176,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   176,     0,     0,     0,     0,
      67,     0,     0,    68,     0,     0,     0,     0,    69,     0,
       0,     0,     0,     0,    70,    71,     0,     0,     0,     0,
       0,     0,     0,    72,     0,     0,   210,     0,     0,   175,
     175,     0,     0,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,     0,     0,     0,     0,     0,
     163,   164,     0,     0,     0,     0,     0,     0,     0,    77,
       0,     0,   209,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,   176,   209,     0,    81,
       0,    82,     0,     0,   176,   176,     0,     0,     0,     0,
      83,     0,     0,   176,     0,     0,    84,    85,     0,     0,
       0,     0,   210,   165,   166,     0,     0,     0,   210,   210,
     167,     0,    86,   188,   168,     0,   169,    67,     0,     0,
      68,   170,     0,     0,     0,    69,     0,     0,     0,     0,
       0,    70,    71,    87,     0,     0,    88,    89,    90,    91,
      72,    92,    93,    94,    95,    96,    97,    98,     0,   100,
     171,     0,   101,   102,   103,   176,   176,     0,     0,   176,
       0,    75,     0,     0,     0,   104,   105,   163,   164,     0,
       0,     0,     0,     0,     0,     0,    77,     0,   106,   107,
       0,     0,     0,   172,   173,   174,     0,     0,   210,     0,
       0,     0,    80,     0,     0,     0,    81,     0,    82,     0,
       0,     0,     0,   210,     0,     0,     0,    83,     0,     0,
       0,     0,     0,    84,    85,     0,     0,     0,     0,     0,
     165,   166,     0,     0,     0,     0,     0,   167,   311,    86,
       0,   168,     0,   169,    67,     0,     0,    68,   170,     0,
       0,     0,    69,     0,     0,     0,     0,     0,    70,    71,
      87,     0,     0,    88,    89,    90,    91,    72,    92,    93,
      94,    95,    96,    97,    98,     0,   100,   171,     0,   101,
     102,   103,     0,     0,     0,     0,     0,     0,    75,     0,
       0,     0,   104,   105,   163,   164,     0,     0,     0,     0,
       0,     0,     0,    77,     0,   106,   107,     0,     0,     0,
     172,   173,   174,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,    81,     0,    82,     0,     0,     0,     0,
       0,     0,     0,     0,    83,     0,     0,     0,     0,     0,
      84,    85,     0,     0,     0,     0,     0,   165,   166,     0,
       0,     0,     0,     0,   167,     0,    86,   314,   168,     0,
     169,    67,     0,     0,    68,   170,     0,     0,     0,    69,
       0,     0,     0,     0,     0,    70,    71,    87,     0,     0,
      88,    89,    90,    91,    72,    92,    93,    94,    95,    96,
      97,    98,     0,   100,   171,     0,   101,   102,   103,     0,
       0,     0,     0,     0,     0,    75,     0,     0,     0,   104,
     105,   163,   164,     0,     0,     0,     0,     0,     0,     0,
      77,     0,   106,   107,     0,     0,     0,   172,   173,   174,
       0,     0,     0,     0,     0,     0,    80,     0,     0,     0,
      81,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,    83,     0,     0,     0,     0,     0,    84,    85,     0,
       0,     0,     0,     0,   165,   166,     0,     0,     0,     0,
       0,   167,     0,    86,     0,   168,     0,   169,    67,     0,
       0,     0,   170,     0,     0,   263,    69,     0,     0,     0,
       0,     0,   200,    71,    87,     0,     0,    88,    89,    90,
      91,    72,    92,    93,    94,    95,    96,    97,    98,     0,
     100,   171,   201,   101,   102,   103,     0,     0,     0,     0,
       0,     0,    75,   202,     0,     0,   104,   105,     0,     0,
       0,     0,     0,   203,     0,   204,     0,    77,   205,   106,
     107,     0,     0,   264,   172,   173,   174,     0,     0,     0,
       0,     0,     0,    80,     0,     0,     0,    81,     0,    82,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
       0,     0,     0,     0,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     206,     0,   168,     0,   169,    67,     0,     0,     0,   207,
       0,     0,     0,    69,     0,     0,     0,     0,     0,   200,
      71,    87,     0,     0,    88,    89,    90,     0,    72,    92,
      93,    94,    95,    96,    97,    98,     0,   100,   171,   201,
     101,   102,   103,     0,     0,     0,     0,     0,     0,    75,
     202,     0,     0,   104,   105,     0,     0,     0,     0,     0,
     203,     0,   204,     0,    77,   205,   106,   208,     0,     0,
       0,   172,   173,   174,     0,     0,     0,     0,     0,     0,
      80,     0,     0,     0,    81,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,   206,     0,   168,
       0,   169,     0,     0,    69,     0,   207,     0,     0,     0,
      70,    71,     0,     0,     0,     0,     0,     0,    87,    72,
       0,    88,    89,    90,     0,     0,    92,    93,    94,    95,
      96,    97,    98,     0,   100,   171,     0,   101,   102,   103,
      75,     0,     0,     0,     0,     0,   231,   232,     0,     0,
     104,   105,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,   106,   208,     0,     0,     0,   172,   173,
     174,    80,     0,     0,     0,    81,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,     0,     0,
       0,     0,    84,    85,     0,     0,     0,     0,     0,   233,
     234,     0,     0,     0,     0,     0,     0,    67,   235,     0,
     168,     0,   169,     0,     0,    69,     0,   236,     0,     0,
       0,    70,    71,     0,     0,     0,     0,     0,     0,    87,
      72,     0,    88,    89,    90,   237,     0,    92,    93,    94,
      95,    96,    97,    98,     0,   100,   171,     0,   101,   102,
     103,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   105,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,   172,
     173,   174,    80,     0,     0,     0,    81,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,    83,     0,     0,
       0,     0,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   206,
       0,   168,     0,   169,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      87,     0,     0,    88,    89,    90,     0,     0,    92,    93,
      94,    95,    96,    97,    98,     0,   100,   171,     0,   101,
     102,   103,     0,     0,    66,     0,    67,     0,     0,    68,
       0,     0,   104,   105,    69,     0,     0,     0,     0,     0,
      70,    71,     0,     0,     0,   106,   107,     0,     0,    72,
     172,   173,   174,     0,     0,     0,     0,     0,     0,     0,
       0,    73,     0,     0,     0,     0,  -214,  -214,     0,    74,
      75,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,     0,    32,     0,     0,    77,     0,     0,    78,     0,
       0,     0,  -214,     0,    79,     0,     0,     0,     0,     0,
       0,    80,     0,     0,     0,    81,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,     0,     0,
       0,     0,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,     0,
       0,     0,     0,  -214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
       0,     0,    88,    89,    90,    91,     0,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,     0,   101,   102,
     103,     0,     0,    66,     0,    67,     0,     0,    68,     0,
       0,   104,   105,    69,     0,     0,     0,     0,     0,    70,
      71,     0,     0,     0,   106,   107,     0,     0,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,     0,     0,     0,     0,     0,  -214,     0,    74,    75,
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
       0,    32,     0,     0,    77,     0,     0,    78,     0,     0,
       0,  -214,     0,    79,     0,     0,     0,     0,     0,     0,
      80,     0,     0,     0,    81,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,     0,     0,
       0,     0,  -214,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
       0,    88,    89,    90,    91,     0,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,     0,   101,   102,   103,
       0,     0,    66,     0,    67,     0,     0,    68,     0,     0,
     104,   105,    69,     0,     0,     0,     0,     0,    70,    71,
       0,     0,     0,   106,   107,     0,     0,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
       0,     0,     0,     0,  -214,  -214,     0,    74,    75,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,     0,
      32,     0,     0,    77,     0,     0,    78,     0,     0,     0,
       0,     0,    79,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,    81,     0,    82,     0,     0,     0,     0,
       0,     0,     0,     0,    83,     0,     0,     0,     0,     0,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,     0,     0,     0,
       0,  -214,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,     0,     0,
      88,    89,    90,    91,     0,    92,    93,    94,    95,    96,
      97,    98,    99,   100,     0,     0,   101,   102,   103,     0,
       0,    66,     0,    67,     0,     0,    68,     0,     0,   104,
     105,    69,     0,     0,     0,     0,     0,    70,    71,     0,
       0,     0,   106,   107,     0,     0,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,     0,
       0,     0,     0,     0,  -214,     0,    74,    75,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,     0,    77,     0,     0,    78,     0,     0,     0,     0,
       0,    79,     0,     0,     0,     0,     0,     0,    80,     0,
       0,     0,    81,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,     0,     0,     0,     0,
    -214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,     0,     0,    88,
      89,    90,    91,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     0,     0,   101,   102,   103,     0,     0,
      66,     0,    67,     0,     0,    68,     0,     0,   104,   105,
      69,     0,     0,     0,     0,     0,    70,    71,     0,     0,
       0,   106,   107,     0,     0,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,     0,     0,
       0,     0,     0,     0,     0,    74,    75,     0,     0,    76,
       0,     0,     0,     0,     0,     0,     0,     0,    32,     0,
       0,    77,     0,     0,    78,     0,     0,     0,  -214,     0,
      79,     0,     0,     0,     0,     0,     0,    80,     0,     0,
       0,    81,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,    86,     0,     0,     0,     0,  -214,
       0,    69,     0,     0,     0,     0,     0,    70,    71,     0,
       0,     0,     0,     0,     0,    87,    72,     0,    88,    89,
      90,    91,     0,    92,    93,    94,    95,    96,    97,    98,
      99,   100,     0,     0,   101,   102,   103,    75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   105,     0,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,     0,     0,    80,     0,
       0,     0,    81,     0,    82,     0,     0,     0,     0,    37,
      38,    39,    40,    83,     0,     0,     0,     0,     0,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,     0,     0,    68,     0,     0,
       0,     0,    69,     0,     0,     0,     0,     0,    70,    71,
       0,     0,     0,     0,     0,     0,    87,    72,     0,    88,
      89,    90,     0,     0,    92,    93,    94,    95,    96,    97,
      98,     0,   100,     0,     0,   101,   102,   103,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
       0,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,    81,     0,    82,     0,     0,     0,     0,
       0,     0,     0,     0,    83,     0,     0,     0,     0,     0,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    86,     0,     0,     0,
       0,     0,     0,    69,     0,     0,     0,     0,     0,    70,
      71,     0,     0,     0,     0,     0,     0,    87,    72,     0,
      88,    89,    90,   193,     0,    92,    93,    94,    95,    96,
      97,    98,     0,   100,     0,     0,   101,   102,   103,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
     105,     0,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,     0,     0,
      80,     0,     0,     0,    81,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
       0,    88,    89,    90,     0,     0,    92,    93,    94,    95,
      96,    97,    98,     0,   100,     0,     0,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107
};

static const yytype_int16 yycheck[] =
{
      32,    45,    68,   186,     1,   240,    79,   143,    74,   144,
     163,    73,   197,   143,    76,   153,   209,   170,   239,   155,
     302,   157,   175,     1,    86,   155,   308,   157,     1,   143,
     258,    15,    26,   231,   250,   251,   252,    17,   236,   237,
      59,   155,     1,   157,   242,    39,     1,    69,     1,    20,
       4,     5,     4,     5,   155,    44,   157,    44,    37,    44,
      10,    39,    89,    90,    91,    92,    89,    90,    91,    92,
      48,   206,    42,    10,   103,   182,    70,   143,   144,   153,
     146,    59,    60,   108,    63,    56,   152,   116,    44,   155,
      68,   157,    70,    62,    48,   120,    48,    67,   120,   104,
     235,    47,   104,   102,    44,   167,    60,    57,    60,   108,
     115,   113,   186,   115,   396,   427,   428,   429,   191,   108,
      57,   108,   124,   108,    73,   187,     0,    76,   264,   195,
     192,   120,   151,   120,   264,   120,   104,    86,    20,   115,
     206,   207,   182,   209,   120,   104,   117,   102,   119,   102,
     264,   104,     9,    10,   186,   182,   115,   373,   202,   182,
     204,   120,   115,   264,   120,   231,   146,   120,   108,   235,
     236,   237,   152,   151,    56,   159,   242,   459,   441,   407,
     120,   316,    39,   446,    59,   182,   468,    44,   182,   116,
     182,    48,   258,   120,   143,   108,   331,   103,   264,   145,
     421,   120,    59,    60,   182,   151,   155,   101,   157,   182,
     156,    68,   347,    70,   163,   281,   401,   102,   167,   120,
     293,   170,   171,   172,   417,   423,   175,    55,   301,   364,
     182,   304,   102,   103,    41,   117,   374,   119,   187,    66,
     393,   303,   104,   192,   526,   380,   481,   196,   197,   101,
     316,   437,   438,   115,   113,   116,   182,   113,   108,    55,
     209,   115,   124,   120,   337,   331,   115,   120,   334,     1,
     302,   182,   345,   456,   410,   115,   308,   134,   135,   102,
     410,   347,    39,   103,   120,   120,   120,   360,   361,    73,
     105,    48,    76,   359,    41,   114,   410,   363,   364,    20,
     114,   103,    86,    60,   116,   102,   372,    39,   187,   410,
     376,    68,   120,    70,   380,   264,    48,    44,   103,   102,
     455,   116,   384,    10,   397,   398,   116,    59,    60,   102,
     102,   102,    43,   120,   114,    56,    68,   105,    70,   114,
     105,   407,   120,   292,   410,   103,   116,   116,   483,   108,
     416,   417,   116,   488,   303,    89,   422,   423,   102,   143,
     496,   427,   428,   429,   396,   103,   496,   120,    44,    43,
      55,   155,    44,   157,   120,   511,   182,   515,   516,   163,
     120,   511,   496,   167,   105,   334,   170,    64,     4,   455,
      22,   175,   458,   359,   460,   496,   117,   511,   119,   380,
      23,   463,   464,   187,   422,   467,   334,   416,   192,   203,
     511,   472,   196,   197,   409,    73,   492,   483,    76,   151,
     411,   441,   488,    24,   456,   209,   497,   459,    86,   158,
     496,    57,    28,    20,   458,   384,   468,    15,    16,    15,
      16,   371,   121,   392,   393,   511,   490,   491,   521,   460,
     182,   292,   401,   392,    -1,    -1,    -1,    -1,    36,    -1,
      36,   410,    40,    -1,    40,    -1,    20,   416,   417,    56,
      -1,    -1,    -1,    -1,    52,    -1,    52,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   526,    -1,    -1,   155,    -1,   157,
      -1,    -1,    56,    -1,    -1,   163,    -1,    -1,   292,   167,
      -1,    -1,   170,    -1,   463,   464,    -1,   175,   467,   303,
      -1,   108,   109,   110,   111,   112,    -1,    -1,    -1,   187,
     117,   118,   119,    -1,   192,    -1,    -1,    -1,   196,   197,
      -1,    -1,    -1,   121,   122,   121,   122,   496,    -1,    -1,
     334,   209,    -1,    -1,   108,   109,   110,   111,   112,    -1,
      -1,    -1,   511,   117,   118,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     384,    -1,    -1,    -1,    -1,    -1,   264,    -1,   392,   393,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   410,    -1,    -1,    -1,
      -1,    -1,   416,   417,   292,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,
       3,    -1,    -1,     6,    -1,    -1,    -1,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,   334,    -1,    -1,   463,
     464,    -1,    -1,   467,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,   496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,   384,   511,    -1,    82,
      -1,    84,    -1,    -1,   392,   393,    -1,    -1,    -1,    -1,
      93,    -1,    -1,   401,    -1,    -1,    99,   100,    -1,    -1,
      -1,    -1,   410,   106,   107,    -1,    -1,    -1,   416,   417,
     113,    -1,   115,   116,   117,    -1,   119,     3,    -1,    -1,
       6,   124,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,   136,    -1,    -1,   139,   140,   141,   142,
      26,   144,   145,   146,   147,   148,   149,   150,    -1,   152,
     153,    -1,   155,   156,   157,   463,   464,    -1,    -1,   467,
      -1,    47,    -1,    -1,    -1,   168,   169,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,   181,   182,
      -1,    -1,    -1,   186,   187,   188,    -1,    -1,   496,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    82,    -1,    84,    -1,
      -1,    -1,    -1,   511,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,
      -1,   117,    -1,   119,     3,    -1,    -1,     6,   124,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
     136,    -1,    -1,   139,   140,   141,   142,    26,   144,   145,
     146,   147,   148,   149,   150,    -1,   152,   153,    -1,   155,
     156,   157,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,   168,   169,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    -1,   181,   182,    -1,    -1,    -1,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,
      99,   100,    -1,    -1,    -1,    -1,    -1,   106,   107,    -1,
      -1,    -1,    -1,    -1,   113,    -1,   115,   116,   117,    -1,
     119,     3,    -1,    -1,     6,   124,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    17,    18,   136,    -1,    -1,
     139,   140,   141,   142,    26,   144,   145,   146,   147,   148,
     149,   150,    -1,   152,   153,    -1,   155,   156,   157,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,   168,
     169,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,   181,   182,    -1,    -1,    -1,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,
      -1,    -1,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
      -1,   113,    -1,   115,    -1,   117,    -1,   119,     3,    -1,
      -1,    -1,   124,    -1,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,   136,    -1,    -1,   139,   140,   141,
     142,    26,   144,   145,   146,   147,   148,   149,   150,    -1,
     152,   153,    37,   155,   156,   157,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    -1,    -1,   168,   169,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    60,    -1,    62,    63,   181,
     182,    -1,    -1,    68,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    82,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,    -1,   117,    -1,   119,     3,    -1,    -1,    -1,   124,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,   136,    -1,    -1,   139,   140,   141,    -1,    26,   144,
     145,   146,   147,   148,   149,   150,    -1,   152,   153,    37,
     155,   156,   157,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,   168,   169,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    60,    -1,    62,    63,   181,   182,    -1,    -1,
      -1,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,   115,    -1,   117,
      -1,   119,    -1,    -1,    11,    -1,   124,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,   136,    26,
      -1,   139,   140,   141,    -1,    -1,   144,   145,   146,   147,
     148,   149,   150,    -1,   152,   153,    -1,   155,   156,   157,
      47,    -1,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,
     168,   169,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,    -1,    -1,    -1,   186,   187,
     188,    78,    -1,    -1,    -1,    82,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      -1,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,   106,
     107,    -1,    -1,    -1,    -1,    -1,    -1,     3,   115,    -1,
     117,    -1,   119,    -1,    -1,    11,    -1,   124,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      26,    -1,   139,   140,   141,   142,    -1,   144,   145,   146,
     147,   148,   149,   150,    -1,   152,   153,    -1,   155,   156,
     157,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   168,   169,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   182,    -1,    -1,    -1,   186,
     187,   188,    78,    -1,    -1,    -1,    82,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
      -1,   117,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,    -1,   139,   140,   141,    -1,    -1,   144,   145,
     146,   147,   148,   149,   150,    -1,   152,   153,    -1,   155,
     156,   157,    -1,    -1,     1,    -1,     3,    -1,    -1,     6,
      -1,    -1,   168,   169,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,   181,   182,    -1,    -1,    26,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    43,    44,    -1,    46,
      47,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    62,    -1,    -1,    65,    -1,
      -1,    -1,    69,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    82,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      -1,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,   139,   140,   141,   142,    -1,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,   155,   156,
     157,    -1,    -1,     1,    -1,     3,    -1,    -1,     6,    -1,
      -1,   168,   169,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,   181,   182,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    44,    -1,    46,    47,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    62,    -1,    -1,    65,    -1,    -1,
      -1,    69,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,
      -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
      -1,   139,   140,   141,   142,    -1,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,   155,   156,   157,
      -1,    -1,     1,    -1,     3,    -1,    -1,     6,    -1,    -1,
     168,   169,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,   181,   182,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    43,    44,    -1,    46,    47,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    62,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,
      99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,    -1,
     139,   140,   141,   142,    -1,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,   155,   156,   157,    -1,
      -1,     1,    -1,     3,    -1,    -1,     6,    -1,    -1,   168,
     169,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,   181,   182,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    46,    47,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    62,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    99,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,    -1,   139,
     140,   141,   142,    -1,   144,   145,   146,   147,   148,   149,
     150,   151,   152,    -1,    -1,   155,   156,   157,    -1,    -1,
       1,    -1,     3,    -1,    -1,     6,    -1,    -1,   168,   169,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,   181,   182,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    62,    -1,    -1,    65,    -1,    -1,    -1,    69,    -1,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,   115,    -1,    -1,    -1,    -1,   120,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    26,    -1,   139,   140,
     141,   142,    -1,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,   155,   156,   157,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     181,   182,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,    89,
      90,    91,    92,    93,    -1,    -1,    -1,    -1,    -1,    99,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    26,    -1,   139,
     140,   141,    -1,    -1,   144,   145,   146,   147,   148,   149,
     150,    -1,   152,    -1,    -1,   155,   156,   157,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   181,   182,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,
      99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,   136,    26,    -1,
     139,   140,   141,   142,    -1,   144,   145,   146,   147,   148,
     149,   150,    -1,   152,    -1,    -1,   155,   156,   157,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,
     169,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   182,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
      -1,   139,   140,   141,    -1,    -1,   144,   145,   146,   147,
     148,   149,   150,    -1,   152,    -1,    -1,   155,   156,   157,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     168,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    62,   192,   194,   195,   182,   197,     0,   200,   201,
     202,   115,   120,   196,   104,   267,    39,    48,    60,    68,
      70,   203,   204,   205,   206,   265,   266,   268,   270,   182,
     198,   199,    59,   289,     1,   182,   207,    89,    90,    91,
      92,   182,   272,   326,   182,   269,   326,     1,   182,   221,
     182,   261,   263,   264,   207,   221,   261,   202,   273,   275,
     276,   277,   274,   275,   103,   116,     1,     3,     6,    11,
      17,    18,    26,    38,    46,    47,    50,    62,    65,    71,
      78,    82,    84,    93,    99,   100,   115,   136,   139,   140,
     141,   142,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   155,   156,   157,   168,   169,   181,   182,   285,   286,
     287,   288,   289,   290,   291,   294,   300,   301,   302,   304,
     315,   316,   317,   321,   322,   323,   324,   325,   327,   328,
       9,    10,    39,    44,    48,    59,    60,    68,    70,   120,
     134,   135,   193,   102,   108,     1,   104,   115,   120,   271,
     278,     1,   104,   278,   193,   108,     1,   102,   103,   267,
     199,   120,   328,    53,    54,   106,   107,   113,   117,   119,
     124,   153,   186,   187,   188,   215,   219,   306,   308,   310,
     312,   315,   320,   303,   328,   306,   313,   313,   116,   306,
      44,   120,   101,   142,   317,   104,   113,   115,   124,   318,
      17,    37,    48,    58,    60,    63,   115,   124,   182,   215,
     219,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   235,   242,   243,   244,   245,   320,   321,   322,   323,
     328,    53,    54,   106,   107,   115,   124,   142,   208,   210,
     212,   214,   215,   216,   219,   320,   328,   193,   326,   328,
      26,    39,    70,   182,   279,   280,   281,   282,   102,   193,
     326,   328,   271,    10,    68,   222,   223,   246,   247,   193,
     223,   263,   151,   289,   312,   306,   319,   312,   320,   320,
     312,    55,    20,    56,   108,   109,   110,   111,   112,   117,
     118,   119,   307,   309,    15,    16,    36,    40,    52,   121,
     122,   311,    41,   101,    66,   290,   306,   116,   313,   306,
     328,   114,   305,   306,   116,   305,   113,   113,   278,   231,
     278,   182,   236,   237,   238,   239,   240,   241,   208,   328,
     227,   108,    20,    56,   105,   117,   119,   211,    15,    16,
      36,    40,    52,   121,   122,   213,    55,   115,   214,   208,
     214,   214,   120,   108,   109,   110,   111,   112,   118,   209,
     211,   213,   214,   104,   115,   124,   217,   281,   281,   281,
     116,   120,   102,   103,   283,   328,   115,   250,   223,   120,
     108,   120,   120,   120,   105,   114,   208,   295,   296,   297,
     298,   308,   313,   313,   285,   306,   313,    69,    41,   285,
     114,   103,   116,   208,   187,   233,   234,   102,    44,   120,
     102,   103,   116,   208,   220,   225,   313,   313,    10,   208,
     116,   210,   313,   313,   328,   208,   218,   102,   102,   102,
     280,   283,   284,   281,   271,   251,   328,     4,     5,   182,
     249,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     268,   270,   220,   262,   306,   105,    43,   299,   120,   102,
     103,   310,   312,    42,    67,   285,   292,   313,   313,   305,
     114,   114,   105,   283,   239,   223,   240,   120,   226,   227,
     116,   212,   214,   103,   116,   284,   284,   284,   108,   116,
     269,   269,    89,   248,   253,   256,   102,   103,   256,   120,
     208,   290,    44,   295,   285,   298,   306,   306,    43,   306,
     285,    55,   234,   208,   208,   278,   278,   249,    44,   223,
     254,   314,   223,   271,   271,   120,   313,   285,   293
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 63 "syntacticAnalyzer.y"
    { if(errorFree == 1 && errorFreeType==1) printf(" **** compiled  %d lines successfully\n",line_number); else errorLog();	}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 93 "syntacticAnalyzer.y"
    {
		NewEntry((yyvsp[(1) - (1)].name), IDENT, line_number, &table[hashKey((yyvsp[(1) - (1)].name))], scopeStack, setBasicType(DT_VOID));
	}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 104 "syntacticAnalyzer.y"
    {
		NewEntry((yyvsp[(1) - (1)].name),IDENT,line_number,&table[hashKey((yyvsp[(1) - (1)].name))],scopeStack,setBasicType(DT_VOID));Add(scopeStack->val,SIZE_VOID);
	}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 110 "syntacticAnalyzer.y"
    {
		ChangeLabel("main",(yyvsp[(2) - (3)].ival));
	}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 139 "syntacticAnalyzer.y"
    {}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 144 "syntacticAnalyzer.y"
    {
		if((yyvsp[(3) - (4)].type)->dataType == DT_ERROR )   // if error then make errorfreetype flag to zero 
		{ 
			NewEntry((yyvsp[(1) - (4)].name),CONST,line_number,&table[hashKey((yyvsp[(1) - (4)].name))],scopeStack,(yyvsp[(3) - (4)].type)); 
			errorFreeType = 0;
		}
		else  // adding entry to sym table , making token to const if variable found again, adding size of scope
		{ 
			NewEntry((yyvsp[(1) - (4)].name),CONST,line_number,&table[hashKey((yyvsp[(1) - (4)].name))],scopeStack,(yyvsp[(3) - (4)].type));
		 	getEntry((yyvsp[(1) - (4)].name),scopeStack)->token = CONST; 
			Add(scopeStack->val,(yyvsp[(3) - (4)].type)->width);
		} 
	}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 158 "syntacticAnalyzer.y"
    {
		NewEntry((yyvsp[(1) - (6)].name),CONST,line_number,&table[hashKey((yyvsp[(1) - (6)].name))],scopeStack,NULL); 	//adding entry to sym table
		if (typeCheck(getEntry((yyvsp[(1) - (6)].name),scopeStack)->type,(yyvsp[(3) - (6)].type)) == 0) {		//if type check fails
			if(conversionTypeCheck(getEntry((yyvsp[(1) - (6)].name),scopeStack)->type,(yyvsp[(3) - (6)].type)) == 0)		//if type conversion fails
				{ getEntry((yyvsp[(1) - (6)].name),scopeStack)->type = setBasicType(DT_ERROR); errorFreeType = 0; }	///Error
			else
				{ getEntry((yyvsp[(1) - (6)].name),scopeStack)->type = (yyvsp[(3) - (6)].type); augmentType(&(getEntry((yyvsp[(1) - (6)].name),scopeStack)->type),DT_CONST); Add(scopeStack->val,(yyvsp[(3) - (6)].type)->width);  }	//changing type to const
		} 
		else {	//changing type to const
			 getEntry((yyvsp[(1) - (6)].name),scopeStack)->type = (yyvsp[(3) - (6)].type); 
			augmentType(&(getEntry((yyvsp[(1) - (6)].name),scopeStack)->type),DT_CONST); 		
			Add(scopeStack->val,(yyvsp[(3) - (6)].type)->width);
   		}
	}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 176 "syntacticAnalyzer.y"
    {
		(yyval.type) = (yyvsp[(1) - (1)].type);
	}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 180 "syntacticAnalyzer.y"
    {
		 flag = 1; 
		if ((yyvsp[(1) - (3)].type)->dataType == DT_ERROR || (yyvsp[(1) - (3)].type)->dataType == DT_ERROR) { flag =0;  }		//erroroneous data types
		else 
		{	
				if( Club((yyvsp[(1) - (3)].type)) != Club((yyvsp[(3) - (3)].type)) || Club((yyvsp[(1) - (3)].type)) == DT_VOID )			//if not comparable
				 {
					flag = 0; printf("(Line %d) Incompatible types in relop const_expr\n",line_number);
				 	printType((yyvsp[(1) - (3)].type)); printType((yyvsp[(3) - (3)].type)); 
				}
	 	}
		if(flag == 0)		//if error found
		{
			(yyval.type) = setBasicType(DT_ERROR);
			numTypeError++;errorFreeType = 0;
		}
		else 		//making bool type and calculating the boolean value
		{
			(yyval.type) = setBasicType(DT_BOOL);
			(yyval.type)->truelist = create_new_list(quadId);
			(yyval.type)->falselist = create_new_list(quadId+1);
			sprintf(tempName,"if %s %s %s",(yyvsp[(1) - (3)].type)->place,(yyvsp[(2) - (3)].type)->entry,(yyvsp[(3) - (3)].type)->place);
			emitcode("Cgoto",NULL,"---",tempName); // special case for emit
			emitcode("goto",NULL,"---",NULL);
		}
}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 208 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "=";}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 209 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "<>";}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 210 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "<";}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 211 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = ">";}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 212 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "<=";}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 213 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = ">=";}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 217 "syntacticAnalyzer.y"
    {
		(yyval.type)=(yyvsp[(1) - (1)].type);
	}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 221 "syntacticAnalyzer.y"
    {
		if(strcmp((yyvsp[(2) - (4)].type)->entry,"OR")==0 && (yyvsp[(1) - (4)].type)->dataType == DT_BOOL && (yyvsp[(4) - (4)].type)->dataType == DT_BOOL) 	//if operator is OR then set type to bool
		{
			(yyval.type) = setBasicType(DT_BOOL);
			BackPatch((yyvsp[(1) - (4)].type)->falselist,(yyvsp[(3) - (4)].ival));
			(yyval.type)->truelist = merge((yyvsp[(1) - (4)].type)->truelist,(yyvsp[(4) - (4)].type)->truelist);
			(yyval.type)->falselist = (yyvsp[(4) - (4)].type)->falselist;
		}
		else if(ClubTypeCheck((yyvsp[(1) - (4)].type),(yyvsp[(4) - (4)].type)) == 0)			//if types incomparable then error
		{
			(yyval.type) = setBasicType(DT_ERROR); 
			numTypeError++;errorFreeType = 0;
			printf("(Line %d) Type Error in constant expression\n",line_number);
		}
		else
		{
			(yyval.type) =setType(getArithType((yyvsp[(1) - (4)].type),(yyvsp[(4) - (4)].type))); 		//find type of resulting expression
			(yyval.type)->place = get_new_temp(scopeStack->val);		//setting a temporary variable to store_argument the value of expression
			Add(scopeStack->val,(yyval.type)->width);  // for $$->place 's get_new_temp
			if((yyvsp[(1) - (4)].type)->dataType == DT_INT && (yyvsp[(4) - (4)].type)->dataType == DT_INT) 
			{
				sprintf(tempName,"%s%s","int",(yyvsp[(2) - (4)].type)->entry);
				emitcode(tempName,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,(yyvsp[(4) - (4)].type)->place);
			}
			else if((yyvsp[(1) - (4)].type)->dataType == DT_REAL && (yyvsp[(4) - (4)].type)->dataType == DT_REAL) 
			{
				sprintf(tempName,"%s%s","real",(yyvsp[(2) - (4)].type)->entry);
				emitcode(tempName,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,(yyvsp[(4) - (4)].type)->place);
			}
			if((yyvsp[(1) - (4)].type)->dataType == DT_INT && (yyvsp[(4) - (4)].type)->dataType == DT_REAL) 
			{
				char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);		//creating a temporary variable for type conversion
				emitcode("<IntToReal>",u,(yyvsp[(1) - (4)].type)->place,NULL);
				sprintf(tempName,"%s%s","real",(yyvsp[(2) - (4)].type)->entry);
				emitcode(tempName,(yyval.type)->place,u,(yyvsp[(4) - (4)].type)->place);
			}
			if((yyvsp[(1) - (4)].type)->dataType == DT_REAL && (yyvsp[(4) - (4)].type)->dataType == DT_INT) 
			{
				char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);
				emitcode("<IntToReal>",u,(yyvsp[(4) - (4)].type)->place,NULL);
				sprintf(tempName,"%s%s","real",(yyvsp[(2) - (4)].type)->entry);
				emitcode(tempName,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,u);
			}	
		}
	}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 268 "syntacticAnalyzer.y"
    { (yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "+";}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 269 "syntacticAnalyzer.y"
    { (yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "-";}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 270 "syntacticAnalyzer.y"
    { (yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "OR";}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 271 "syntacticAnalyzer.y"
    { (yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "XOR";}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 275 "syntacticAnalyzer.y"
    {
		(yyval.type)=(yyvsp[(1) - (1)].type);
	}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 279 "syntacticAnalyzer.y"
    {
		flag=1;
		if(strcmp((yyvsp[(2) - (4)].type)->entry,"AND")==0 && (yyvsp[(1) - (4)].type)->dataType == DT_BOOL && (yyvsp[(4) - (4)].type)->dataType == DT_BOOL)		//if boolean
		 {
			(yyval.type) = setBasicType(DT_BOOL);
			BackPatch((yyvsp[(1) - (4)].type)->truelist,(yyvsp[(3) - (4)].ival));
			(yyval.type)->truelist = (yyvsp[(4) - (4)].type)->truelist;
			(yyval.type)->falselist = merge((yyvsp[(1) - (4)].type)->falselist,(yyvsp[(4) - (4)].type)->falselist);
		}
		else if(ClubTypeCheck((yyvsp[(1) - (4)].type),(yyvsp[(4) - (4)].type))== 0)		//if error
		{
			printf("(Line %d) Type Error in constant expression\n",line_number); flag =0 ;
		}
		else 
		{
			if((yyvsp[(2) - (4)].type)->counter ==STAR ||  (yyvsp[(2) - (4)].type)->counter == SLASH || (yyvsp[(2) - (4)].type)->counter == DIV) 		//if arithmetic operator
			{ 
				(yyval.type) = setType(getArithType((yyvsp[(1) - (4)].type),(yyvsp[(4) - (4)].type))); 
				(yyval.type)->place = get_new_temp(scopeStack->val);			//create temp variable for storing result of expression
				Add(scopeStack->val,(yyval.type)->width); 					// for get_new_temp of $$
				if((yyvsp[(1) - (4)].type)->dataType == DT_INT && (yyvsp[(4) - (4)].type)->dataType == DT_INT) 
				{
					sprintf(tempName,"%s%s","int",(yyvsp[(2) - (4)].type)->entry);
					emitcode(tempName,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,(yyvsp[(4) - (4)].type)->place);
				}
				else if((yyvsp[(1) - (4)].type)->dataType == DT_REAL && (yyvsp[(4) - (4)].type)->dataType == DT_REAL) {
					sprintf(tempName,"%s%s","real",(yyvsp[(2) - (4)].type)->entry);
					emitcode(tempName,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,(yyvsp[(4) - (4)].type)->place);
				}
				if((yyvsp[(1) - (4)].type)->dataType == DT_INT && (yyvsp[(4) - (4)].type)->dataType == DT_REAL) 
				{
					char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);		//temporary variable for type casting
					emitcode("<IntToReal>",u,(yyvsp[(1) - (4)].type)->place,NULL);
					sprintf(tempName,"%s%s","real",(yyvsp[(2) - (4)].type)->entry);
					emitcode(tempName,(yyval.type)->place,u,(yyvsp[(4) - (4)].type)->place);
				}
				if((yyvsp[(1) - (4)].type)->dataType == DT_REAL && (yyvsp[(4) - (4)].type)->dataType == DT_INT) 
				{
					char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);		//temporary variable for type casting
					emitcode("<IntToReal>",u,(yyvsp[(4) - (4)].type)->place,NULL);
					sprintf(tempName,"%s%s","real",(yyvsp[(2) - (4)].type)->entry);
					emitcode(tempName,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,u);
				}			
			} 
			else if((yyvsp[(2) - (4)].type)->counter == MOD || (yyvsp[(2) - (4)].type)->counter== SHR || (yyvsp[(2) - (4)].type)->counter == SHL) 		//if bit operators
			{
				if(strictClub((yyvsp[(1) - (4)].type)) == DT_INT && strictClub((yyvsp[(4) - (4)].type)) == DT_INT ) 		//if type checked strictly
				{
					(yyval.type) = setBasicType(DT_INT);
					(yyval.type)->place = get_new_temp(scopeStack->val);
					Add(scopeStack->val,(yyval.type)->width); // for get_new_temp of $$
					emitcode((yyvsp[(2) - (4)].type)->entry,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,(yyvsp[(4) - (4)].type)->place);
				}
				 else 
				{ 
					flag =0; printf("(Line %d) Type Error in constant expression\n",line_number);
				}
			} 
			else if((yyvsp[(2) - (4)].type)->counter == AND)
			 { 
				if((yyvsp[(1) - (4)].type)->dataType == DT_INT && (typeCheck((yyvsp[(1) - (4)].type),(yyvsp[(4) - (4)].type)) ==1)) 
				{
					(yyval.type) = setBasicType(DT_INT);
					(yyval.type)->place = get_new_temp(scopeStack->val);
					Add(scopeStack->val,(yyval.type)->width); // for get_new_temp of $$
					emitcode("AND",(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,(yyvsp[(4) - (4)].type)->place);
				}
				else
				{
					printf("(Line %d) Type Error in constant expression\n",line_number); flag = 0; 
				} 
			}
			if (flag == 0) { (yyval.type) = setBasicType(DT_ERROR);  numTypeError++;errorFreeType = 0; }
		} 	
	}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 356 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "*"; (yyval.type)->counter = STAR;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 357 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "/"; (yyval.type)->counter = SLASH;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 358 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "/"; (yyval.type)->counter = DIV;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 359 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "MOD"; (yyval.type)->counter = MOD;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 360 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "SHL"; (yyval.type)->counter = SHL;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 361 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "SHR"; (yyval.type)->counter = SHR;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 362 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "AND"; (yyval.type)->counter = AND;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 365 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 366 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 367 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 368 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 369 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(2) - (2)].type); augmentType(&(yyval.type),DT_PTR);}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 370 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(2) - (3)].type);}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 372 "syntacticAnalyzer.y"
    {
		(yyval.type) = setType((yyvsp[(2) - (2)].type));
		(yyval.type)->truelist = (yyvsp[(2) - (2)].type)->falselist;
		(yyval.type)->falselist = (yyvsp[(2) - (2)].type)->truelist; 
		sprintf(tempName,"%s %s","NOT",(yyvsp[(2) - (2)].type)->place);
		(yyval.type)->place = tempName;
	}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 379 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(2) - (2)].type);}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 380 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(2) - (2)].type); augmentType(&(yyval.type),DT_PTR); }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 382 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_BOOL); 
		(yyval.type)->place = "TRUE";
		if(ifFlag == 1) 
		{
			(yyval.type)->truelist = create_new_list(quadId); 
			emitcode("goto",NULL,"---",NULL); 
		}
	}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 392 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_BOOL); 
		(yyval.type)->place = "FALSE";
		if(ifFlag == 1) 
		{
			(yyval.type)->truelist = create_new_list(quadId); 
			emitcode("goto",NULL,"---",NULL); 
		}
	}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 403 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID); (yyval.type)->code= "+";}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 404 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID); (yyval.type)->code = "-"; }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 407 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 409 "syntacticAnalyzer.y"
    {
		if((yyvsp[(2) - (2)].type)->dataType == DT_VOID) (yyval.type) = getSubType((yyvsp[(1) - (2)].type));		//find the sub type if dereferenced or parameter 
 		else (yyval.type) = (yyvsp[(2) - (2)].type); 		//find the type of field
	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 415 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(2) - (2)].type);}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 416 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 417 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 425 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_INT); 
		(yyval.type)->code = ""; 
		(yyval.type)->place = (char *)malloc(10*sizeof(char)); 
		sprintf((yyval.type)->place,"%d",(yyvsp[(1) - (1)].ival)); 		//saving value of number in place
	}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 432 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_INT); 
		(yyval.type)->place = (char *)malloc(10); 
		sprintf((yyval.type)->place,"%f",(yyvsp[(1) - (1)].dval)); 
	}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 439 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 443 "syntacticAnalyzer.y"
    {
		NewEntry((yyvsp[(1) - (4)].name),TYPE,line_number,&table[hashKey((yyvsp[(1) - (4)].name))],scopeStack,(yyvsp[(3) - (4)].type)); /*Add(scopeStack->val,$3->width);*/
		(yyval.type) = setBasicType(DT_VOID);  
	}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 447 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 450 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 451 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(2) - (2)].type);}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 452 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 455 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 456 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 457 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 458 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 459 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 462 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 463 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 464 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 466 "syntacticAnalyzer.y"
    {
		if(strictClub((yyvsp[(1) - (3)].type)) == strictClub((yyvsp[(3) - (3)].type))) 
			(yyval.type) = (yyvsp[(1) - (3)].type); 
		else 
		{ 
			(yyval.type) = setBasicType(DT_ERROR);  
			numTypeError++;errorFreeType = 0;  
		}
	}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 477 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 479 "syntacticAnalyzer.y"
    {
		if(strcmp((yyvsp[(2) - (4)].type)->entry,"OR")==0 && (yyvsp[(1) - (4)].type)->dataType == DT_BOOL && (yyvsp[(4) - (4)].type)->dataType == DT_BOOL)
		 {
			(yyval.type) = setBasicType(DT_BOOL);
			BackPatch((yyvsp[(1) - (4)].type)->falselist,(yyvsp[(3) - (4)].ival));
			(yyval.type)->truelist = merge((yyvsp[(1) - (4)].type)->truelist,(yyvsp[(4) - (4)].type)->truelist);
			(yyval.type)->falselist = (yyvsp[(4) - (4)].type)->falselist;
		}
		else if(ClubTypeCheck((yyvsp[(1) - (4)].type),(yyvsp[(4) - (4)].type)) == 0)
		{ 
			 numTypeError++;errorFreeType = 0;  (yyval.type) = setBasicType(DT_ERROR); printf("(Line %d) Type Error in constant expression\n",line_number);
		}
		else
		{
			(yyval.type) =setType(getArithType((yyvsp[(1) - (4)].type),(yyvsp[(4) - (4)].type))); 
			(yyval.type)->place = get_new_temp(scopeStack->val);
			Add(scopeStack->val,(yyval.type)->width);  // for $$->place 's get_new_temp
			if((yyvsp[(1) - (4)].type)->dataType == DT_INT && (yyvsp[(4) - (4)].type)->dataType == DT_INT) 
			{
				sprintf(tempName,"%s%s","int",(yyvsp[(2) - (4)].type)->entry);
				emitcode(tempName,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,(yyvsp[(4) - (4)].type)->place);
			}
			else if((yyvsp[(1) - (4)].type)->dataType == DT_REAL && (yyvsp[(4) - (4)].type)->dataType == DT_REAL) 
			{
				sprintf(tempName,"%s%s","real",(yyvsp[(2) - (4)].type)->entry);
				emitcode(tempName,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,(yyvsp[(4) - (4)].type)->place);
			}
			if((yyvsp[(1) - (4)].type)->dataType == DT_INT && (yyvsp[(4) - (4)].type)->dataType == DT_REAL) 
			{
				char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);
				emitcode("<IntToReal>",u,(yyvsp[(1) - (4)].type)->place,NULL);
				sprintf(tempName,"%s%s","real",(yyvsp[(2) - (4)].type)->entry);
				emitcode(tempName,(yyval.type)->place,u,(yyvsp[(4) - (4)].type)->place);
			}
			if((yyvsp[(1) - (4)].type)->dataType == DT_REAL && (yyvsp[(4) - (4)].type)->dataType == DT_INT) 
			{
				char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);
				emitcode("<IntToReal>",u,(yyvsp[(4) - (4)].type)->place,NULL);
				sprintf(tempName,"%s%s","real",(yyvsp[(2) - (4)].type)->entry);
				emitcode(tempName,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,u);
			}			
		} 
	}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 524 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 526 "syntacticAnalyzer.y"
    {
		flag=1;
		if(strcmp((yyvsp[(2) - (4)].type)->entry,"AND")==0 && (yyvsp[(1) - (4)].type)->dataType == DT_BOOL && (yyvsp[(4) - (4)].type)->dataType == DT_BOOL) {
			(yyval.type) = setBasicType(DT_BOOL);
			BackPatch((yyvsp[(1) - (4)].type)->truelist,(yyvsp[(3) - (4)].ival));
			(yyval.type)->truelist = (yyvsp[(4) - (4)].type)->truelist;
			(yyval.type)->falselist = merge((yyvsp[(1) - (4)].type)->falselist,(yyvsp[(4) - (4)].type)->falselist);
		}	
		else if(ClubTypeCheck((yyvsp[(1) - (4)].type),(yyvsp[(4) - (4)].type))== 0){
			printf("(Line %d) Type Error in constant expression\n",line_number); flag =0 ;
		}
		else 
		{
			if((yyvsp[(2) - (4)].type)->counter ==STAR ||  (yyvsp[(2) - (4)].type)->counter == SLASH || (yyvsp[(2) - (4)].type)->counter == DIV) 
			{ 
				(yyval.type) = setType(getArithType((yyvsp[(1) - (4)].type),(yyvsp[(4) - (4)].type))); 
				(yyval.type)->place = get_new_temp(scopeStack->val);
				Add(scopeStack->val,(yyval.type)->width); // for get_new_temp of $$
				if((yyvsp[(1) - (4)].type)->dataType == DT_INT && (yyvsp[(4) - (4)].type)->dataType == DT_INT)
				{
					sprintf(tempName,"%s%s","int",(yyvsp[(2) - (4)].type)->entry);
					emitcode(tempName,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,(yyvsp[(4) - (4)].type)->place);
				}
				else if((yyvsp[(1) - (4)].type)->dataType == DT_REAL && (yyvsp[(4) - (4)].type)->dataType == DT_REAL) 
				{
					sprintf(tempName,"%s%s","real",(yyvsp[(2) - (4)].type)->entry);
					emitcode(tempName,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,(yyvsp[(4) - (4)].type)->place);				
				}
				if((yyvsp[(1) - (4)].type)->dataType == DT_INT && (yyvsp[(4) - (4)].type)->dataType == DT_REAL) 
				{
					char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);
					emitcode("<IntToReal>",u,(yyvsp[(1) - (4)].type)->place,NULL);
					sprintf(tempName,"%s%s","real",(yyvsp[(2) - (4)].type)->entry);
					emitcode(tempName,(yyval.type)->place,u,(yyvsp[(4) - (4)].type)->place);
				}
				if((yyvsp[(1) - (4)].type)->dataType == DT_REAL && (yyvsp[(4) - (4)].type)->dataType == DT_INT) 
				{
					char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);
					emitcode("<IntToReal>",u,(yyvsp[(4) - (4)].type)->place,NULL);
					sprintf(tempName,"%s%s","real",(yyvsp[(2) - (4)].type)->entry);
					emitcode(tempName,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,u);
				}		
			} 
			else if((yyvsp[(2) - (4)].type)->counter == MOD || (yyvsp[(2) - (4)].type)->counter== SHR || (yyvsp[(2) - (4)].type)->counter == SHL) 
			{
				if(strictClub((yyvsp[(1) - (4)].type)) == DT_INT && strictClub((yyvsp[(4) - (4)].type)) == DT_INT ) 
				{
					(yyval.type) = setBasicType(DT_INT);
					(yyval.type)->place = get_new_temp(scopeStack->val);
					Add(scopeStack->val,(yyval.type)->width); // for get_new_temp of $$
					emitcode((yyvsp[(2) - (4)].type)->entry,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,(yyvsp[(4) - (4)].type)->place);
				}
				else 
				{ 
					flag =0; printf("(Line %d) Type Error in constant expression\n",line_number);
				}
			} 
			else if((yyvsp[(2) - (4)].type)->counter == AND) 
			{ 
				if((yyvsp[(1) - (4)].type)->dataType == DT_INT && (typeCheck((yyvsp[(1) - (4)].type),(yyvsp[(4) - (4)].type)) ==1)) 
				{
					(yyval.type) = setBasicType(DT_INT);
					(yyval.type)->place = get_new_temp(scopeStack->val);
					Add(scopeStack->val,(yyval.type)->width); // for get_new_temp of $$
					emitcode("AND",(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,(yyvsp[(4) - (4)].type)->place);
				}
				else 	
				{
					printf("(Line %d) Type Error in constant expression\n",line_number); flag = 0; 
				} 
			}
			if (flag == 0) { (yyval.type) = setBasicType(DT_ERROR);  numTypeError++;errorFreeType = 0; }
		} 
	}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 602 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 603 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 604 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (2)].type);}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 605 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 606 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (4)].type);}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 607 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(2) - (3)].type);}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 611 "syntacticAnalyzer.y"
    {
		flag =0;
		sym* temp;
	 	temp = getEntry((yyvsp[(1) - (1)].name),scopeStack);
		if(temp == NULL)
		{
			(yyval.type) = setBasicType(DT_ERROR);  
			numTypeError++;errorFreeType = 0;  
			printf("(Line %d) Type Error : Not a type\n", line_number);
		}
		else	
		{
			if( temp->token == TYPE) 
			{ 
				(yyval.type) = temp->type; 
			}
			else 
			{ 
				printf("(Line %d) Type error : %s is not a type \n",line_number, temp->lexeme);
				(yyval.type) = setBasicType(DT_ERROR);  numTypeError++;errorFreeType = 0; 
			}
		}
	}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 636 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(2) - (2)].type); augmentType(&(yyval.type),DT_PTR); }
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 639 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 640 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(2) - (2)].type);}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 643 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 644 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 648 "syntacticAnalyzer.y"
    {
		(yyval.type) = CopyType((yyvsp[(6) - (6)].type)); 
		augmentType(&(yyval.type),DT_ARR); 
		(yyval.type)->width = (yyvsp[(6) - (6)].type)->width * (yyvsp[(3) - (6)].type)->maxIndex;	//type width times maximum index store_argumentd in width, width contains size
		(yyval.type)->low = (yyvsp[(3) - (6)].type)->low;		//low index
		(yyval.type)->maxIndex = (yyvsp[(3) - (6)].type)->maxIndex;		//max index
		(yyval.type)->next = (yyvsp[(6) - (6)].type);		//mext type referrence
		Type* temp;
		temp = (yyval.type);
		while(temp!=NULL)
		{
			temp = temp->next;
		}
	}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 665 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_VOID);
		(yyval.type)->maxIndex = (yyvsp[(3) - (3)].ival)-(yyvsp[(1) - (3)].ival) + 1;
		(yyval.type)->low = (yyvsp[(1) - (3)].ival);
	}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 672 "syntacticAnalyzer.y"
    {(yyval.ival)=(yyvsp[(1) - (1)].ival);}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 676 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_REC); 		//next store_arguments the field list in record
		(yyval.type)->width = SizeOf(scopeStack->val);
		(yyval.type)->next = (yyvsp[(2) - (3)].type);	
		(yyval.type)->attScope = scopeStack->val;
		Pop(&scopeStack);		//popping scope to return out of record
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 685 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 688 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 689 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (2)].type);}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 692 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 693 "syntacticAnalyzer.y"
    { append_to_list((yyvsp[(1) - (3)].type),&(yyvsp[(3) - (3)].type)); (yyval.type) = (yyvsp[(3) - (3)].type); }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 697 "syntacticAnalyzer.y"
    {
		Type* head; 
		head = (Type *)malloc(sizeof(Type));
		Type* temp;
		sym* tempEntry;
		temp = (yyvsp[(1) - (3)].type); 
		for(i = 1; i<= (yyvsp[(1) - (3)].type)->counter;i++) 	//adding record identifiers in next, counter holds the number of identifiers
		{
			tempEntry = getEntry((temp->entry),scopeStack);
 			tempEntry->type = (yyvsp[(3) - (3)].type);
			tempEntry->offset = SizeOf(scopeStack->val);		//size of returns the size of scope from scope headers and hence getting the offset
			Add(scopeStack->val,(yyvsp[(3) - (3)].type)->width);					//adding width to size of scope
			make_new_list((yyvsp[(3) - (3)].type),&head);		//adding type to identifiers
			temp = temp->next;
		}
		(yyval.type) = head;
	}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 716 "syntacticAnalyzer.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); (yyval.type)->counter = 1;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 717 "syntacticAnalyzer.y"
    { (yyvsp[(1) - (3)].type)-> next = (yyvsp[(3) - (3)].type); (yyval.type) = (yyvsp[(1) - (3)].type);   (yyval.type)->counter = (yyvsp[(3) - (3)].type)->counter + 1;  }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 721 "syntacticAnalyzer.y"
    {
		NewEntry((yyvsp[(1) - (1)].name),IDENT,line_number,&table[hashKey((yyvsp[(1) - (1)].name))],scopeStack,NULL); 
		(yyval.type) = setBasicType(DT_VOID);   
		(yyval.type)->entry = getEntry((yyvsp[(1) - (1)].name),scopeStack)->lexeme; 
	}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 728 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 729 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_STRING);}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 732 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 735 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 736 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (3)].type);}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 740 "syntacticAnalyzer.y"
    {
		if((yyvsp[(2) - (2)].type)->dataType == DT_ERROR) 
		{ 
			(yyval.type) = setBasicType(DT_ERROR);  
			numTypeError++;errorFreeType = 0;  
		}
		else 
		{ 
			(yyval.type) = setBasicType(DT_PROC);		
		}
	}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 752 "syntacticAnalyzer.y"
    {
		 if((yyvsp[(2) - (4)].type)->dataType == DT_ERROR) 
		{
			(yyval.type) = setBasicType(DT_ERROR);  
			numTypeError++;errorFreeType = 0;  
		}
		else 
		{ 
			(yyval.type) = setBasicType(DT_FUNCTION);
			(yyvsp[(4) - (4)].type)->next = (yyvsp[(2) - (4)].type); 
			(yyval.type)->next = (yyvsp[(4) - (4)].type);
		}
	}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 767 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 771 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_OBJ);  
		(yyval.type)->width = SizeOf(scopeStack->val);
		(yyval.type)->attScope = scopeStack->val ;
		if((yyvsp[(2) - (5)].type) != NULL) 		//appending next's info
		{ 
			append_to_list((yyvsp[(3) - (5)].type),&(yyvsp[(2) - (5)].type)); 
			append_to_list((yyvsp[(4) - (5)].type),&(yyvsp[(2) - (5)].type)); 
			(yyval.type)->next = (yyvsp[(2) - (5)].type); 
		}
		else if((yyvsp[(3) - (5)].type) != NULL) 
		{
			append_to_list((yyvsp[(4) - (5)].type),&(yyvsp[(3) - (5)].type)); (yyval.type)->next = (yyvsp[(3) - (5)].type);
		}
		else (yyval.type)->next = (yyvsp[(4) - (5)].type);
		Pop(&scopeStack);
	}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 790 "syntacticAnalyzer.y"
    {(yyval.type)=NULL;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 792 "syntacticAnalyzer.y"
    {
		Type* temp;
		temp = (yyvsp[(2) - (2)].type);
		while(temp != NULL) 
		{
			if(getEntry(temp->entry,scopeStack) != NULL) 
				getEntry(temp->entry,scopeStack)->token = PRIVATE;
			temp=temp->next;
		}
		(yyval.type) = (yyvsp[(2) - (2)].type);
	}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 805 "syntacticAnalyzer.y"
    {(yyval.type) = NULL;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 806 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 807 "syntacticAnalyzer.y"
    { append_to_list((yyvsp[(2) - (2)].type),&(yyvsp[(1) - (2)].type)); (yyval.type) = (yyvsp[(1) - (2)].type);}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 808 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 812 "syntacticAnalyzer.y"
    {
		Type* temp = (yyvsp[(2) - (3)].type)->next;
		sym* symEntry;
		stack* tempStack;
		Push(&tempStack,(yyvsp[(2) - (3)].type)->attScope);
		while(temp!= NULL) 
		{		
			symEntry = getEntry(temp->entry,tempStack);
			if(symEntry != NULL) 
			{
				NewEntry(symEntry->lexeme,symEntry->token,symEntry->line,&table[hashKey(symEntry->lexeme)],scopeStack,symEntry->type);
				Add(scopeStack->val,symEntry->type->width);
			}
			temp = temp->next;
		}
		(yyval.type) = (yyvsp[(2) - (3)].type)->next;
	}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 829 "syntacticAnalyzer.y"
    {(yyval.type)=NULL;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 832 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 835 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 836 "syntacticAnalyzer.y"
    { append_to_list((yyvsp[(2) - (2)].type),&(yyvsp[(1) - (2)].type)); (yyval.type) = (yyvsp[(1) - (2)].type); }
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 840 "syntacticAnalyzer.y"
    {
		Type* head; 
		head = (Type *)malloc(sizeof(Type));
		Type* temp;
		sym* tempEntry;
		temp = (yyvsp[(1) - (4)].type); 
		for(i = 1; i<= (yyvsp[(1) - (4)].type)->counter;i++) 
		{
			tempEntry = getEntry((temp->entry),scopeStack);
			tempEntry->type = setType((yyvsp[(3) - (4)].type));
			tempEntry->offset = SizeOf(scopeStack->val);
			Add(scopeStack->val,(yyvsp[(3) - (4)].type)->width);
			make_new_list((yyvsp[(3) - (4)].type),&head);
			temp = temp->next;
		}
		(yyval.type) = head;
		(yyval.type) -> next = (yyvsp[(1) - (4)].type);
	}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 861 "syntacticAnalyzer.y"
    {
		(yyval.type) = setType((yyvsp[(1) - (1)].type)); 
		(yyval.type)->next = NULL; 
		(yyval.type) = (yyvsp[(1) - (1)].type); 
		(yyval.type)->counter = 1; 
	}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 868 "syntacticAnalyzer.y"
    {
		(yyvsp[(1) - (3)].type)->next = (yyvsp[(3) - (3)].type); 
		(yyval.type) = (yyvsp[(1) - (3)].type); 
		(yyval.type)->counter = (yyvsp[(3) - (3)].type)->counter + 1;  
	}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 876 "syntacticAnalyzer.y"
    {
		NewEntry((yyvsp[(1) - (1)].name),IDENT,line_number,&table[hashKey((yyvsp[(1) - (1)].name))],scopeStack,NULL); 
		(yyval.type) = setBasicType(DT_VOID); 
		(yyval.type)->entry = getEntry((yyvsp[(1) - (1)].name),scopeStack)->lexeme; 
	}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 884 "syntacticAnalyzer.y"
    {
		(yyval.type) = setType((yyvsp[(1) - (1)].type)); 
		(yyval.type)->next = NULL; 
		(yyval.type) = (yyvsp[(1) - (1)].type); 
		(yyval.type)->counter = 1;
	}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 891 "syntacticAnalyzer.y"
    {
		(yyvsp[(1) - (2)].type)-> next = (yyvsp[(2) - (2)].type); 
		(yyval.type) = (yyvsp[(1) - (2)].type);   
		(yyval.type)->counter = (yyvsp[(2) - (2)].type)->counter + 1; 
	}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 898 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 901 "syntacticAnalyzer.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type);Pop(&scopeStack);}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 902 "syntacticAnalyzer.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); Pop(&scopeStack);}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 903 "syntacticAnalyzer.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); Pop(&scopeStack);}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 904 "syntacticAnalyzer.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); Pop(&scopeStack);}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 907 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(2) - (4)].type);}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 910 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(2) - (4)].type);}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 914 "syntacticAnalyzer.y"
    {
		Type *temp; temp = (yyvsp[(1) - (4)].type);
		while(temp !=NULL) 
		{
			temp->dataType = (yyvsp[(3) - (4)].type)->dataType;
			temp->leftEnd = (yyvsp[(3) - (4)].type)->leftEnd;
			temp->attScope = (yyvsp[(3) - (4)].type)->attScope;
			if(temp->entry != NULL) 
			{
				getEntry(temp->entry,scopeStack)->type = (yyvsp[(3) - (4)].type);
				getEntry(temp->entry,scopeStack)->type->attScope = (yyvsp[(3) - (4)].type)->attScope;
				getEntry(temp->entry,scopeStack)->offset = SizeOf(scopeStack->val);
				Add(scopeStack->val,(yyvsp[(3) - (4)].type)->width);
			}
			temp = temp->next;
		}
	}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 932 "syntacticAnalyzer.y"
    {
		sym* tempEntry;
		if(typeCheck((yyvsp[(3) - (6)].type),(yyvsp[(5) - (6)].type))== 0) 
		{ 
			Type *temp; temp = (yyvsp[(1) - (6)].type); 
		       printf("(Line %d) Type error in var_decl \n",line_number);
			if(conversionTypeCheck((yyvsp[(3) - (6)].type),(yyvsp[(5) - (6)].type)) == 0 ) 
			{
			       while(temp !=NULL) 
				{
					temp->dataType = DT_ERROR; temp->leftEnd = TYPE_SIZE_IN_BITS;
					temp = temp->next;
					 numTypeError++;errorFreeType = 0; 
				}
  			}
			else 
			{
				while(temp !=NULL) 
				{
					if(temp->entry != NULL)
					 {
						tempEntry = getEntry(temp->entry,scopeStack);
						tempEntry->type = setType((yyvsp[(3) - (6)].type));
						tempEntry->type->attScope = (yyvsp[(3) - (6)].type)->attScope;
						tempEntry->offset = SizeOf(scopeStack->val);
						Add(scopeStack->val,(yyvsp[(3) - (6)].type)->width);
					}
					temp = temp->next; 
				}		
			}
 		} 
		else 
		{ 
			Type *temp; temp = (yyvsp[(1) - (6)].type); 
			while(temp !=NULL) 
			{
				if(temp->entry != NULL) 
				{
					tempEntry = getEntry(temp->entry,scopeStack);
					tempEntry->type = setType((yyvsp[(3) - (6)].type));
					tempEntry->type->attScope = (yyvsp[(3) - (6)].type)->attScope;
					tempEntry->offset = SizeOf(scopeStack->val);
					Add(scopeStack->val,(yyvsp[(3) - (6)].type)->width);
				}
				temp = temp->next; 
			}
 		}
	}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 981 "syntacticAnalyzer.y"
    {
		Type* temp; temp = (yyvsp[(1) - (3)].type); 
		while(temp !=NULL) 
		{
			temp->dataType = DT_ERROR; 
			temp->leftEnd = TYPE_SIZE_IN_BITS ;
			temp = temp->next; 
			numTypeError++;errorFreeType = 0;
		} 
	}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 993 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 996 "syntacticAnalyzer.y"
    {(yyvsp[(1) - (1)].type)->next=NULL; (yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 997 "syntacticAnalyzer.y"
    {(yyvsp[(1) - (3)].type)->next=(yyvsp[(3) - (3)].type); (yyval.type)=(yyvsp[(1) - (3)].type);}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1001 "syntacticAnalyzer.y"
    {
		NewEntry((yyvsp[(1) - (1)].name),IDENT,line_number,&table[hashKey((yyvsp[(1) - (1)].name))],scopeStack,NULL); 
		(yyval.type) = setBasicType(DT_VOID);
  		(yyval.type)->entry = getEntry((yyvsp[(1) - (1)].name),scopeStack)->lexeme; 
	}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1009 "syntacticAnalyzer.y"
    {
		Pop(&scopeStack);			//popping scope since out of procedure
		emitcode("RETURN",(yyvsp[(1) - (2)].type)->place,NULL,NULL); 
		ChangeLabel((yyvsp[(1) - (2)].type)->place,(yyvsp[(2) - (2)].ival));		//making the label of procedure body to proc name
	}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1017 "syntacticAnalyzer.y"
    {
		Pop(&scopeStack);
		emitcode("RETURN",(yyvsp[(1) - (2)].type)->place,NULL,NULL); 
		ChangeLabel((yyvsp[(1) - (2)].type)->place,(yyvsp[(2) - (2)].ival));
	}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1025 "syntacticAnalyzer.y"
    {
		(yyval.ival) = quadId;	
		emitcode("START",NULL,NULL,NULL);		//starting code since matched at start of program
	}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1031 "syntacticAnalyzer.y"
    {
		if((yyvsp[(2) - (4)].type)->counter == -1)			//error in heading
		 {
			(yyval.type) = setBasicType(DT_ERROR);  
			numTypeError++;errorFreeType = 0; 	
		}
		else if((yyvsp[(2) - (4)].type)->counter == -2) 		//correct heading
		{ 
			getEntry((yyvsp[(2) - (4)].type)->entry,scopeStack)->type->next = (yyvsp[(3) - (4)].type);
			(yyvsp[(2) - (4)].type)->next = (yyvsp[(3) - (4)].type);			//making proc parameters append to name list
			getEntry((yyvsp[(2) - (4)].type)->entry,scopeStack)->type->attScope = scopeStack->val;
			(yyvsp[(2) - (4)].type)->attScope = scopeStack->val;		//scope of proc 
			Type* temp = (yyvsp[(2) - (4)].type);
			while(temp != NULL)
			{
				temp = temp->next;
			}
			(yyval.type) = setBasicType(DT_PROC);		//setting type to proc
		}
		else 		//forward declaration of object's function
		{
			stack *tempStack;
			Push(&tempStack,(yyvsp[(2) - (4)].type)->counter);		//push temp stack to find the ident of object, counter store_arguments the scope of object's declaration
			getEntry((yyvsp[(2) - (4)].type)->entry,tempStack)->type->next = (yyvsp[(3) - (4)].type);
			(yyvsp[(2) - (4)].type)->attScope = getEntry((yyvsp[(2) - (4)].type)->entry,tempStack)->type->attScope;	//adding scope of list to proc name
			(yyvsp[(2) - (4)].type)->next = (yyvsp[(3) - (4)].type);			//appending proc parameters to name
			Type* temp = (yyvsp[(2) - (4)].type);	
			while(temp != NULL)
			{
				temp = temp->next;
			}
			(yyval.type) = setBasicType(DT_PROC);
		}
		(yyval.type)->entry = (yyvsp[(2) - (4)].type)->entry;			//storing lexeme of proc name to  proc heading
		(yyval.type)->place = (yyvsp[(2) - (4)].type)->place;			//storing address of proc name to proc heading
	}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1067 "syntacticAnalyzer.y"
    {}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1071 "syntacticAnalyzer.y"
    {
		sym *temp;	
		stack *tempStack;
		Push(&tempStack,scopeStack->val);
		if(getEntry((yyvsp[(1) - (1)].name),tempStack) == NULL)			//if function name not declared
		{
	  		NewEntry((yyvsp[(1) - (1)].name),IDENT,line_number,&table[hashKey((yyvsp[(1) - (1)].name))],scopeStack,setBasicType(DT_PROC));			//creating a entry of type procedure
			Add(scopeStack->val,SIZE_PTR);				//adding size of ptr to scope
	 		curScopeId++;
			Push(&scopeStack,curScopeId);		//pushing scope since moving in proc body
	 		 (yyval.type) = setBasicType(DT_PROC);
	  		(yyval.type)->entry = getEntry((yyvsp[(1) - (1)].name),scopeStack)->lexeme; 
			(yyval.type)-> counter = -2;		//flag to indicate correct proc declaration
			(yyval.type)->place = (char*)malloc(strlen((yyval.type)->entry)+5);
			sprintf((yyval.type)->place,"%s@%d",(yyval.type)->entry,getEntry((yyvsp[(1) - (1)].name),scopeStack)->myScope);			//putting proc name along with scope to place indicating address	
		}
		else
		{
			(yyval.type) = getEntry((yyvsp[(1) - (1)].name),tempStack)->type;		//func name already declared
			(yyval.type)->entry = getEntry((yyvsp[(1) - (1)].name),scopeStack)->lexeme;		//lexeme copied
			(yyval.type)->place = (char*)malloc(strlen((yyval.type)->entry)+5);	
			sprintf((yyval.type)->place,"%s@%d",(yyval.type)->entry,tempStack->val);		//putting proc name with scope to place
		}
	}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1097 "syntacticAnalyzer.y"
    {
		sym *temp;	
		stack *tempStack;
		Push(&tempStack,(yyvsp[(1) - (3)].type)->attScope);		//creating a temporary stack
		temp = getEntry((yyvsp[(3) - (3)].type)->entry,tempStack);			//finding field in temporary stack
		if(temp != NULL)
		{	
			(yyval.type) = temp->type;
			(yyval.type)->counter = (yyvsp[(1) - (3)].type)->attScope; 			//storing  sscope to counter to indicate function for object
			Push(&scopeStack,temp->type->attScope); 		// pushing filed's scope to scope stack
			(yyval.type)->entry = temp->lexeme;						//name of procedure equals matched name in temp stack
			(yyval.type)->place = (char*)malloc(strlen((yyvsp[(1) - (3)].type)->place)+strlen((yyvsp[(3) - (3)].type)->entry)+10);		
			sprintf((yyval.type)->place,"%s.%s@%d",(yyvsp[(1) - (3)].type)->place,(yyvsp[(3) - (3)].type)->entry,tempStack->val);		//putting object's name , field's name along with scope value to proc's name place
		}
		else
		{		
			(yyval.type) = setBasicType(DT_ERROR);		//else error
			numTypeError++;errorFreeType = 0; 
			(yyval.type)-> counter = -1;
			(yyval.type)->entry = (yyvsp[(3) - (3)].type)->entry;
		}
	}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1123 "syntacticAnalyzer.y"
    {
		if((yyvsp[(2) - (6)].type)->counter == -1)
		 {
			(yyval.type) = setBasicType(DT_ERROR);
			numTypeError++;errorFreeType = 0;
		}
		else if((yyvsp[(2) - (6)].type)->counter == -2)
		 { 
			NewEntry("Result",IDENT,line_number,&table[hashKey("Result")],scopeStack,(yyvsp[(5) - (6)].type));				// ?? RESULT  ??
			Add(scopeStack->val,(yyvsp[(5) - (6)].type)->width);
			getEntry((yyvsp[(2) - (6)].type)->entry,scopeStack)->type->next = (yyvsp[(3) - (6)].type);
			getEntry((yyvsp[(2) - (6)].type)->entry,scopeStack)->type->attScope = scopeStack->val;
			(yyvsp[(2) - (6)].type)->next = (yyvsp[(3) - (6)].type);
			(yyvsp[(2) - (6)].type)->attScope = scopeStack->val;
			Type* temp = (yyvsp[(2) - (6)].type);
			while(temp != NULL)
			{
				temp = temp->next;
			}
			(yyval.type) = setBasicType(DT_FUNCTION);
		}
		else 
		{
			stack *tempStack;
			Push(&tempStack,(yyvsp[(2) - (6)].type)->counter);
			getEntry((yyvsp[(2) - (6)].type)->entry,tempStack)->type->next = (yyvsp[(3) - (6)].type);
			(yyvsp[(2) - (6)].type)->next = (yyvsp[(3) - (6)].type);
			(yyvsp[(2) - (6)].type)->attScope = getEntry((yyvsp[(2) - (6)].type)->entry,tempStack)->type->attScope;
			Type* temp = (yyvsp[(2) - (6)].type);
			while(temp != NULL)
			{
				temp = temp->next;
			}
			(yyval.type) = setBasicType(DT_FUNCTION);
		}
		(yyval.type)->entry = (yyvsp[(2) - (6)].type)->entry;
		(yyval.type)->place = (yyvsp[(2) - (6)].type)->place;
	}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1161 "syntacticAnalyzer.y"
    {}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1162 "syntacticAnalyzer.y"
    {}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1168 "syntacticAnalyzer.y"
    {
		sym *temp;	
		stack *tempStack;
		Push(&tempStack,scopeStack->val);
		if(getEntry((yyvsp[(1) - (1)].name),tempStack) == NULL)
		{
	  		NewEntry((yyvsp[(1) - (1)].name),IDENT,line_number,&table[hashKey((yyvsp[(1) - (1)].name))],scopeStack,setBasicType(DT_FUNCTION));
			Add(scopeStack->val,SIZE_PTR);
			curScopeId++; Push(&scopeStack,curScopeId);
			(yyval.type) = setBasicType(DT_FUNCTION);
			(yyval.type)->entry = getEntry((yyvsp[(1) - (1)].name),scopeStack)->lexeme; 
			(yyval.type)-> counter = -2;
			(yyval.type)->place = (char*)malloc(strlen((yyval.type)->entry)+5);
			sprintf((yyval.type)->place,"%s@%d",(yyval.type)->entry,getEntry((yyvsp[(1) - (1)].name),scopeStack)->myScope);
		}
		else
		{
			(yyval.type) = getEntry((yyvsp[(1) - (1)].name),tempStack)->type;
			(yyval.type)->entry = getEntry((yyvsp[(1) - (1)].name),scopeStack)->lexeme;
			(yyval.type)->place = (char*)malloc(strlen((yyval.type)->entry)+5);
			sprintf((yyval.type)->place,"%s@%d",(yyval.type)->entry,tempStack->val);
		}
	}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1193 "syntacticAnalyzer.y"
    {
		sym *temp;	
		stack *tempStack;
		Push(&tempStack,(yyvsp[(1) - (3)].type)->attScope);
		temp = getEntry((yyvsp[(3) - (3)].type)->entry,tempStack);
		if(temp != NULL)
		{	
			(yyval.type) = temp->type;
			(yyval.type)->counter = (yyvsp[(1) - (3)].type)->attScope; // jugaad check
			Push(&scopeStack,temp->type->attScope); 
			(yyval.type)->entry = temp->lexeme;
			(yyval.type)->place = (char*)malloc(strlen((yyvsp[(1) - (3)].type)->place)+strlen((yyvsp[(3) - (3)].type)->entry)+10);
			sprintf((yyval.type)->place,"%s.%s@%d",(yyvsp[(1) - (3)].type)->place,(yyvsp[(3) - (3)].type)->entry,tempStack->val);
		}
		else
		{
			(yyval.type) = setBasicType(DT_ERROR);	
			(yyval.type)-> counter = -1;
			(yyval.type)-> entry = (yyvsp[(3) - (3)].type)->entry;
		}
	}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1217 "syntacticAnalyzer.y"
    {(yyval.ival)=(yyvsp[(1) - (1)].ival);}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1220 "syntacticAnalyzer.y"
    {(yyval.ival)=(yyvsp[(1) - (1)].ival);}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1223 "syntacticAnalyzer.y"
    {(yyval.ival)=(yyvsp[(1) - (1)].ival);}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1224 "syntacticAnalyzer.y"
    {(yyval.ival)=(yyvsp[(1) - (1)].ival);}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1227 "syntacticAnalyzer.y"
    {(yyval.ival)=(yyvsp[(2) - (4)].ival);}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1230 "syntacticAnalyzer.y"
    {(yyval.ival)=(yyvsp[(2) - (4)].ival);}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1233 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID); (yyval.type)->next = NULL; }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1234 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID); (yyval.type)-> next = (yyvsp[(2) - (3)].type); }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1237 "syntacticAnalyzer.y"
    {(yyval.type)=NULL;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1238 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1240 "syntacticAnalyzer.y"
    {
		 (yyval.type) = setType((yyvsp[(1) - (3)].type)); 			//set type of $1 to $$
		 (yyval.type)->next = (yyvsp[(1) - (3)].type)->next; 		// ?? $$->NEXT=$1; ??  since one section will be missed
		 append_to_list((yyvsp[(3) - (3)].type),&(yyval.type));		//appendig $3 to result
	}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1249 "syntacticAnalyzer.y"
    {
		Type* head; 
		sym* tempEntry;
		head = (Type *)malloc(sizeof(Type));
		Type* temp;
		temp = (yyvsp[(1) - (3)].type);
		for(i = 1; i<= (yyvsp[(1) - (3)].type)->counter;i++) 
		{
			if(temp->flag == 1) 		//if there is symbol entry in table
			{
				tempEntry = getEntry((temp->entry),scopeStack);	
				tempEntry->type = (yyvsp[(3) - (3)].type);		//setting type 
				tempEntry->offset = SizeOf(scopeStack->val);	
				Add(scopeStack->val,(yyvsp[(3) - (3)].type)->width);
			}
			make_new_list((yyvsp[(3) - (3)].type),&head);	//adding parameters in a list pointed by head
			temp = temp->next;
		}
		(yyval.type) = head->next;
	}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1269 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1271 "syntacticAnalyzer.y"
    {
		Type* head; 
		head = (Type *)malloc(sizeof(Type));
		Type* temp;
		sym* tempEntry;
		temp = (yyvsp[(2) - (4)].type);
		for(i = 1; i<= (yyvsp[(2) - (4)].type)->counter;i++) 
		{
			if(temp->flag == 1) 
			{
				tempEntry = getEntry((temp->entry),scopeStack);
				tempEntry->type = (yyvsp[(4) - (4)].type);
				tempEntry->offset = SizeOf(scopeStack->val);
				Add(scopeStack->val,(yyvsp[(4) - (4)].type)->width);
			}
			make_new_list((yyvsp[(4) - (4)].type),&head);
			temp = temp->next;
		}
		(yyval.type) = head->next;
	}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1291 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(2) - (2)].type);}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1293 "syntacticAnalyzer.y"
    {
		Type* head; 
		sym* tempEntry;
		head = (Type *)malloc(sizeof(Type));
		Type* temp;
		temp = (yyvsp[(2) - (4)].type); 
		for(i = 1; i<= (yyvsp[(2) - (4)].type)->counter;i++) 
		{
			if(temp->flag == 1) 
			{
				tempEntry = getEntry((temp->entry),scopeStack);
				tempEntry->type = (yyvsp[(4) - (4)].type);
				tempEntry->offset = SizeOf(scopeStack->val);
				Add(scopeStack->val,(yyvsp[(4) - (4)].type)->width);
			}
			make_new_list((yyvsp[(4) - (4)].type),&head);
			temp = temp->next;
		}
		(yyval.type) = head->next;
	}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1313 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(2) - (2)].type);}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1315 "syntacticAnalyzer.y"
    {
		Type* head; 
		sym* tempEntry;
		head = (Type *)malloc(sizeof(Type));
		Type* temp;
		temp = (yyvsp[(2) - (4)].type); 
		for(i = 1; i<= (yyvsp[(2) - (4)].type)->counter;i++) 
		{
			if(temp->flag == 1) 
			{
				tempEntry = getEntry((temp->entry),scopeStack);
				tempEntry->type = (yyvsp[(4) - (4)].type);
				tempEntry->offset = SizeOf(scopeStack->val);
				Add(scopeStack->val,(yyvsp[(4) - (4)].type)->width);
				tempEntry->token  = CONST;
			}
			make_new_list((yyvsp[(4) - (4)].type),&head);
			temp = temp->next;
		}
		(yyval.type) = head->next;
	}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1336 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(2) - (2)].type);}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1340 "syntacticAnalyzer.y"
    {
		(yyval.type) = setType((yyvsp[(1) - (1)].type)); 
		(yyval.type)->next = NULL;
		(yyval.type) = (yyvsp[(1) - (1)].type); 
		(yyval.type)->counter = 1; 
	}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1347 "syntacticAnalyzer.y"
    {
		(yyvsp[(1) - (3)].type)->next = (yyvsp[(3) - (3)].type); 
		(yyval.type) = (yyvsp[(1) - (3)].type); 
		(yyval.type)->counter = (yyvsp[(3) - (3)].type)->counter + 1;
	}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1355 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_VOID);   
  		(yyval.type)->flag= NewEntry( (yyvsp[(1) - (1)].name),IDENT,line_number,&table[hashKey((yyvsp[(1) - (1)].name))],scopeStack,NULL);  
		(yyval.type)->entry = getEntry((yyvsp[(1) - (1)].name),scopeStack)->lexeme; 
	}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1362 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1365 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1367 "syntacticAnalyzer.y"
    {
		(yyval.type) = (yyvsp[(1) - (3)].type); 
		if(typeCheck((yyvsp[(1) - (3)].type),(yyvsp[(3) - (3)].type))==0) 
			printf("(Line %d) Type error in parameter list\n",line_number);  
	}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1377 "syntacticAnalyzer.y"
    { (yyval.type) = setBasicType(DT_VOID); (yyval.type)->nextlist = malloc(sizeof(List)); (yyval.type)->nextlist = NULL;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1378 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1379 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1380 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1381 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1382 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1383 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1384 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1385 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1386 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1390 "syntacticAnalyzer.y"
    {
		if(typeCheck((yyvsp[(1) - (3)].type),(yyvsp[(3) - (3)].type)) == 0) 
		{
			if(assignTypeCheck((yyvsp[(1) - (3)].type),(yyvsp[(3) - (3)].type)) == 1) 
			{ 
				(yyval.type) = setBasicType(DT_VOID); 
			}
			else	
			{
				printf("(Line %d) Incompatible Types in Assignment. Found ",line_number); 
				printType((yyvsp[(3) - (3)].type)); 
				printf(" required "); 
				printType((yyvsp[(1) - (3)].type)); 
				printf("\n"); 
				(yyval.type) = setBasicType(DT_ERROR); 
				numTypeError++;errorFreeType = 0;
			}
		}
		else	
			(yyval.type) = setBasicType(DT_VOID);
		 emitcode(":=",(yyvsp[(1) - (3)].type)->place,(yyvsp[(3) - (3)].type)->place,NULL);
		 (yyval.type)->nextlist = (List *)malloc(sizeof(List)); (yyval.type)->nextlist = NULL;	
	}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1413 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1417 "syntacticAnalyzer.y"
    {
		sym* temp;
	 	flag = 0;
	  	if((yyvsp[(1) - (1)].type)->next == NULL)
		 	(yyvsp[(1) - (1)].type)->next = setBasicType(DT_VOID);
		temp = getEntry((yyvsp[(1) - (1)].type)->entry,scopeStack);
		if(((yyvsp[(1) - (1)].type)->entry!=NULL)&&(strcmp((yyvsp[(1) - (1)].type)->entry,"WRITE")==0 || strcmp((yyvsp[(1) - (1)].type)->entry,"READ")==0 || strcmp((yyvsp[(1) - (1)].type)->entry,"WRITELN")==0 || strcmp((yyvsp[(1) - (1)].type)->entry,"READLN")==0 ))
		{
			int isRead = 1;
			if(strcmp((yyvsp[(1) - (1)].type)->entry,"WRITE")==0 || strcmp((yyvsp[(1) - (1)].type)->entry,"WRITELN")==0)
			{
				isRead = 0;
			}
			counter = 0;
			Type *temp2 = (yyvsp[(1) - (1)].type);
			while(temp2!=NULL)
			{
				if(counter>=2) 
				{
					if(isRead == 1)
					{
						if(temp2->dataType == DT_INT)
							emitcode("paramRI",temp2->place,NULL,NULL);
						else if(temp2->dataType == DT_REAL)
							emitcode("paramRF",temp2->place,NULL,NULL);
						else if(temp2->dataType == DT_BOOL)
							emitcode("paramRB",temp2->place,NULL,NULL);
						else if(temp2->dataType == DT_STRING)
							emitcode("paramRS",temp2->place,NULL,NULL);
						else
							emitcode("paramRI",temp2->place,NULL,NULL);
					}
					else
					{
						if(temp2->dataType == DT_INT)
							emitcode("paramWI",temp2->place,NULL,NULL);
						else if(temp2->dataType == DT_REAL)
							emitcode("paramWF",temp2->place,NULL,NULL);
						else if(temp2->dataType == DT_BOOL)
							emitcode("paramWB",temp2->place,NULL,NULL);
						else if(temp2->dataType == DT_STRING)
							emitcode("paramWS",temp2->place,NULL,NULL);
						else
							emitcode("paramWI",temp2->place,NULL,NULL);
					}
				}
				counter++;
				temp2 = temp2->next;
			}
			char* cnt;
			cnt=(char*) malloc(50*sizeof(char));
			counter = counter-2;
			sprintf(cnt,"%d",counter);
			emitcode("call",NULL,(yyvsp[(1) - (1)].type)->entry,cnt);
			
		}
		else if(temp == NULL || temp->type == NULL) 
		{
			(yyval.type) = setBasicType(DT_ERROR);
			numTypeError++;errorFreeType = 0;
		}
		else	
		{
				 
			if(temp->type->dataType == DT_PROC)
			{	
				flag = 0;
				counter = 0;
				Type	*tempCall,*tempDef;
				tempCall = (yyvsp[(1) - (1)].type);
				tempDef = temp->type;
				
				while(tempDef !=NULL && tempCall != NULL)
				{
					if(typeCheck(tempCall,tempDef) == 0/*strictClub($1)  != strictClub($3)*/) 
					{
						if(assignTypeCheck(tempDef,tempCall) == 1) 
						{ 
							if(counter>=2) 
							{
								if(tempCall->dataType == DT_INT)
									emitcode("paramI",tempCall->place,NULL,NULL);
								else if(tempCall->dataType == DT_REAL)
									emitcode("paramF",tempCall->place,NULL,NULL);
								else if(tempCall->dataType == DT_BOOL)
									emitcode("paramB",tempCall->place,NULL,NULL);
								else if(tempCall->dataType == DT_STRING)
									emitcode("paramS",tempCall->place,NULL,NULL);
								else
									emitcode("paramI",tempCall->place,NULL,NULL);
							}
						}
						else	
						{
							flag = 1;
							printf("\n(Line %d) Incompatible types in Procedure Call. Found ",line_number); 
							printType(tempCall); 
							printf(" required "); 
							printType(tempDef); 
							(yyval.type) = setBasicType(DT_ERROR); 
							numTypeError++;errorFreeType = 0;
							break;
						}
					}
					if(counter>=2) 
					{ 
						if(tempCall->dataType == DT_INT)
							emitcode("paramI",tempCall->place,NULL,NULL);
						else if(tempCall->dataType == DT_REAL)
							emitcode("paramF",tempCall->place,NULL,NULL);
						else if(tempCall->dataType == DT_BOOL)
							emitcode("paramB",tempCall->place,NULL,NULL);
						else if(tempCall->dataType == DT_STRING)
							emitcode("paramS",tempCall->place,NULL,NULL);
						else
							emitcode("paramI",tempCall->place,NULL,NULL);
					}
					tempCall = tempCall->next;
					tempDef = tempDef->next;
					counter++;
				}
				if((tempDef==NULL && tempCall != NULL) || (tempDef!=NULL && tempCall == NULL)) 
				{	
					flag =1;
					printf("\n(Line %d) Unexpected number of arguments\n",line_number);
				}
				char* cnt ;
				cnt = (char *)malloc(5*sizeof(char));
				counter = counter-2;
				sprintf(cnt,"%d",counter);
				sprintf(tempName,"%s@%d",(yyvsp[(1) - (1)].type)->entry,getEntry((yyvsp[(1) - (1)].type)->entry,scopeStack)->myScope);
				emitcode("call",NULL,tempName,cnt); 
			}
			else
			{	
				printf("\n(Line %d) Error in Procedure Call\n",line_number);
				(yyval.type) = setBasicType(DT_ERROR);
				numTypeError++;errorFreeType = 0;
			}		
			if(flag == 0)
			{
				(yyval.type) = setBasicType(DT_VOID);
			}	
			else
			{
				printf("\n(Line %d) Error in Procedure Call\n",line_number);
				(yyval.type) = setBasicType(DT_ERROR);
				numTypeError++;errorFreeType = 0;
			}
		}
	}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1571 "syntacticAnalyzer.y"
    {
		(yyval.type) = (yyvsp[(2) - (3)].type);  
	}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1577 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_VOID); 
		(yyval.type)->nextlist = (yyvsp[(1) - (1)].type)->nextlist; 
	}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1582 "syntacticAnalyzer.y"
    {
		if((yyvsp[(1) - (4)].type)->dataType == DT_ERROR || (yyvsp[(4) - (4)].type)->dataType == DT_ERROR)
		{
			(yyval.type) = setBasicType(DT_ERROR); 
			numTypeError++;errorFreeType = 0;
		}
		else 
			(yyval.type) = setBasicType(DT_VOID);
		BackPatch((yyvsp[(1) - (4)].type)->nextlist,(yyvsp[(3) - (4)].ival));
		(yyval.type)->nextlist = (yyvsp[(4) - (4)].type)->nextlist;
	}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1596 "syntacticAnalyzer.y"
    {
		if((yyvsp[(2) - (5)].type)->dataType != DT_BOOL) 
		{
			 printf("(Line %d) Error in test condition of IF \n ",line_number);
			 (yyval.type) = setBasicType(DT_ERROR); 
			numTypeError++;errorFreeType = 0;
		}  
	 	else 
		{
			(yyval.type) = setBasicType(DT_VOID);
			BackPatch((yyvsp[(2) - (5)].type)->truelist,(yyvsp[(4) - (5)].ival));
			(yyval.type)->nextlist = merge((yyvsp[(2) - (5)].type)->falselist,(yyvsp[(5) - (5)].type)->nextlist);		
		}  
		ifFlag = 0;
	}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1612 "syntacticAnalyzer.y"
    {
		if((yyvsp[(2) - (9)].type)->dataType != DT_BOOL) 
		{ 
			printf("(Line %d) Error in test condition of IF \n ",line_number); 
			(yyval.type) = setBasicType(DT_ERROR); 
			numTypeError++;errorFreeType = 0;
		}  
 		else 
		{
			(yyval.type) = setBasicType(DT_VOID);
			BackPatch((yyvsp[(2) - (9)].type)->truelist,(yyvsp[(4) - (9)].ival));
			BackPatch((yyvsp[(2) - (9)].type)->falselist,(yyvsp[(8) - (9)].ival));
			List* temp = merge((yyvsp[(5) - (9)].type)->nextlist,(yyvsp[(7) - (9)].type)->nextlist);
			(yyval.type)->nextlist = merge(temp,(yyvsp[(9) - (9)].type)->nextlist);
		} 
		ifFlag = 0; 
	}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1630 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1633 "syntacticAnalyzer.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1637 "syntacticAnalyzer.y"
    {
		flag = 1;
		Type* temp; 
		temp = (yyvsp[(4) - (6)].type);
		 while(temp!=NULL) 
		{
			if((yyvsp[(2) - (6)].type)->dataType != DT_VOID && typeCheck(temp,(yyvsp[(2) - (6)].type))==0) 
			{
				 flag = 0; 
				 break; 
			}
			temp = temp->next;
		}
		if(flag == 0)	
		{ 
			(yyval.type) = setBasicType(DT_ERROR); 
			printf("(Line %d) Type Error in case stmt\n",line_number);
			numTypeError++;errorFreeType = 0;
		}
		else
			(yyval.type) = setBasicType(DT_VOID);
	}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1661 "syntacticAnalyzer.y"
    { (yyvsp[(1) - (1)].type)->next = NULL; (yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1662 "syntacticAnalyzer.y"
    { (yyvsp[(1) - (3)].type)->next = (yyvsp[(3) - (3)].type); (yyval.type) = (yyvsp[(1) - (3)].type); }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1665 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1666 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (3)].type);}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1669 "syntacticAnalyzer.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1671 "syntacticAnalyzer.y"
    {
		if(typeCheck((yyvsp[(1) - (3)].type),(yyvsp[(3) - (3)].type))==1) 
			(yyval.type) = (yyvsp[(1) - (3)].type); 
		else 
		{ 
			(yyval.type) = setBasicType(DT_ERROR); 
			printf("(Line %d) Type Error in case label list \n",line_number); 
			numTypeError++;errorFreeType = 0;
		}
	}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1683 "syntacticAnalyzer.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1685 "syntacticAnalyzer.y"
    {
		if((yyvsp[(1) - (3)].type)->dataType == DT_INT && (yyvsp[(3) - (3)].type)->dataType == DT_INT) 
			(yyval.type) = setBasicType(DT_INT); 
		else 
		{ 
			(yyval.type) = setBasicType(DT_ERROR); 
			printf("(Line %d) Error in case label subrange type\n",line_number);
			numTypeError++;errorFreeType = 0; 
		} 
	}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1697 "syntacticAnalyzer.y"
    {(yyval.type)=NULL;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1698 "syntacticAnalyzer.y"
    {(yyval.type)=NULL;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1702 "syntacticAnalyzer.y"
    {
		if((yyvsp[(6) - (6)].type)->dataType != DT_BOOL) 
		{ 
			(yyval.type) = setBasicType(DT_ERROR); 
			printf("(Line %d) Error in test condition of REPEAT \n",line_number);
			numTypeError++;errorFreeType = 0;
		} 
		else 
		{
			(yyval.type) = setBasicType(DT_VOID);		
			BackPatch((yyvsp[(3) - (6)].type)->nextlist,(yyvsp[(5) - (6)].ival));
			BackPatch((yyvsp[(6) - (6)].type)->falselist,(yyvsp[(2) - (6)].ival));
			(yyval.type)->nextlist = (yyvsp[(6) - (6)].type)->truelist;
		} 
		ifFlag = 0;
	}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1721 "syntacticAnalyzer.y"
    {
		if((yyvsp[(3) - (6)].type)->dataType != DT_BOOL) 
		{ 
			(yyval.type) = setBasicType(DT_ERROR); 
			printf("(Line %d) Error in test condition of WHILE loop \n",line_number); 
			numTypeError++;errorFreeType = 0;
		} 
		else 
		{ 
			(yyval.type) = setBasicType(DT_VOID);
			BackPatch((yyvsp[(6) - (6)].type)->nextlist,(yyvsp[(2) - (6)].ival));
			BackPatch((yyvsp[(3) - (6)].type)->truelist,(yyvsp[(5) - (6)].ival));
			(yyval.type)->nextlist = (yyvsp[(3) - (6)].type)->falselist;
			sprintf(tempName,"%d",(yyvsp[(2) - (6)].ival));
			emitcode("goto",NULL,tempName,NULL); 
			ifFlag = 0;       
		}
	}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1742 "syntacticAnalyzer.y"
    {
		if((yyvsp[(2) - (4)].type)->dataType == DT_ERROR) 
		{
			(yyval.type) = setBasicType(DT_ERROR);
			numTypeError++;errorFreeType = 0;
			printf("(Line %d) Error in assign condition of FOR loop\n",line_number);
		}
		else 
		{ 
			(yyval.type) = setBasicType(DT_VOID); 		
			BackPatch((yyvsp[(4) - (4)].type)->nextlist,quadId);
			if((yyvsp[(2) - (4)].type)->flag == 1) 
			{
				if((yyvsp[(2) - (4)].type)->dataType == DT_INT)
					emitcode("int+",(yyvsp[(2) - (4)].type)->place,(yyvsp[(2) - (4)].type)->place,"1");
				else
					emitcode("real+",(yyvsp[(2) - (4)].type)->place,(yyvsp[(2) - (4)].type)->place,"1");
			}
			else 
			{
				if((yyvsp[(2) - (4)].type)->dataType == DT_INT)
					emitcode("int-",(yyvsp[(2) - (4)].type)->place,(yyvsp[(2) - (4)].type)->place,"1");
				else
					emitcode("real-",(yyvsp[(2) - (4)].type)->place,(yyvsp[(2) - (4)].type)->place,"1");
			}
			sprintf(tempName,"%d",(yyvsp[(2) - (4)].type)->counter-1);
			emitcode("goto",NULL,tempName,NULL);
			sprintf(tempName,"%d",quadId);
			codelist[(yyvsp[(2) - (4)].type)->counter]->arg1 = strdup(tempName);
			BackPatch((yyval.type)->nextlist,quadId);		
		}
		ifFlag = 0;
	}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1778 "syntacticAnalyzer.y"
    {
		if((typeCheck((yyvsp[(1) - (5)].type),(yyvsp[(3) - (5)].type)) == 0 && conversionTypeCheck((yyvsp[(1) - (5)].type),(yyvsp[(3) - (5)].type)) == 0)||(typeCheck((yyvsp[(1) - (5)].type),(yyvsp[(5) - (5)].type))==0 && conversionTypeCheck((yyvsp[(1) - (5)].type),(yyvsp[(5) - (5)].type))== 0)) 
		{
			(yyval.type) = setBasicType(DT_ERROR);
			numTypeError++;errorFreeType = 0;
			printf("(Line %d) Error in assign condition of FOR loop\n",line_number);
		}
		else 
		{
			emitcode(":=",(yyvsp[(1) - (5)].type)->place,(yyvsp[(3) - (5)].type)->place,NULL);
			sprintf(tempName,"if %s <= %s",(yyvsp[(1) - (5)].type)->place,(yyvsp[(5) - (5)].type)->place);
			char* temp = (char *)malloc(sizeof(char)*5);
			sprintf(temp,"%d",quadId+2);
			emitcode("Cgoto",NULL,temp,tempName);
			emitcode("goto",NULL,"---",NULL);
			(yyval.type) = (yyvsp[(1) - (5)].type);
			(yyval.type)->counter = quadId-1;
			(yyval.type)->flag = 1;		
		}
	}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1799 "syntacticAnalyzer.y"
    {
		if((typeCheck((yyvsp[(1) - (5)].type),(yyvsp[(3) - (5)].type)) == 0 && conversionTypeCheck((yyvsp[(1) - (5)].type),(yyvsp[(3) - (5)].type)) == 0)||(typeCheck((yyvsp[(1) - (5)].type),(yyvsp[(5) - (5)].type))==0 && conversionTypeCheck((yyvsp[(1) - (5)].type),(yyvsp[(5) - (5)].type))== 0)) 
		{
			(yyval.type) = setBasicType(DT_ERROR);
			numTypeError++;errorFreeType = 0;
			printf("(Line %d) Error in assign condition of FOR loop\n",line_number);
		}
		else 
		{
			emitcode(":=",(yyvsp[(1) - (5)].type)->place,(yyvsp[(3) - (5)].type)->place,NULL);
			sprintf(tempName,"if %s >= %s",(yyvsp[(1) - (5)].type)->place,(yyvsp[(5) - (5)].type)->place);
			char* temp = (char *)malloc(sizeof(char)*5);
			sprintf(temp,"%d",quadId+2);
			emitcode("Cgoto",NULL,temp,tempName);
			emitcode("goto",NULL,"---",NULL);
			(yyval.type) = (yyvsp[(1) - (5)].type);
			(yyval.type)->counter = quadId-1;
			(yyval.type)->flag = 0;
		}
	}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1821 "syntacticAnalyzer.y"
    {}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1825 "syntacticAnalyzer.y"
    {
		(yyval.type) = (yyvsp[(1) - (1)].type); 
		(yyval.type)->next = NULL; 
		(yyval.type)->counter = 1; 
	}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1831 "syntacticAnalyzer.y"
    {
		(yyval.type) = (yyvsp[(1) - (3)].type); 
		(yyval.type)->next = (yyvsp[(3) - (3)].type); 
		(yyval.type)->counter = (yyvsp[(3) - (3)].type)->counter + 1;
 		Type* temp;
	  	temp = (yyval.type);	
	}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1841 "syntacticAnalyzer.y"
    {
		(yyval.type) = setType((yyvsp[(1) - (1)].type)); 
		(yyval.type)->truelist = (yyvsp[(1) - (1)].type)->truelist;
		(yyval.type)->falselist = (yyvsp[(1) - (1)].type)->falselist;
		(yyval.type)->place = (yyvsp[(1) - (1)].type)->place; 
		if((yyvsp[(1) - (1)].type) != NULL) 
			(yyval.type)->next=NULL;
	}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1850 "syntacticAnalyzer.y"
    {
		flag = 1; 	
		if ((yyvsp[(1) - (3)].type)->dataType == DT_ERROR || (yyvsp[(3) - (3)].type)->dataType == DT_ERROR) 
		{ 
			flag =0; 
			numTypeError++;errorFreeType = 0;
		}
		else 
		{ 		
			if( Club((yyvsp[(1) - (3)].type)) != Club((yyvsp[(3) - (3)].type)) || Club((yyvsp[(1) - (3)].type)) == DT_VOID ) 
			{
				flag = 0; 
				printf("(Line %d) Incompatible types in relop const_expr. \n",line_number); 
				printType((yyvsp[(1) - (3)].type)); 
				printType((yyvsp[(3) - (3)].type));
			}	
		 }
		if(flag == 0) 
		{
			(yyval.type) = setBasicType(DT_ERROR);
			numTypeError++;errorFreeType = 0; 
		}
		else 
		{
			(yyval.type) = setBasicType(DT_BOOL);
			(yyval.type)->truelist = create_new_list(quadId);
			(yyval.type)->falselist = create_new_list(quadId+1);
			(yyval.type)->place = "";
			sprintf(tempName,"if %s %s %s",(yyvsp[(1) - (3)].type)->place,(yyvsp[(2) - (3)].type)->entry,(yyvsp[(3) - (3)].type)->place);
			emitcode("Cgoto",NULL,"---",tempName); 
			emitcode("goto",NULL,"---",NULL);
		}
	}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1885 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "=";}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1886 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "<>";}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1887 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "<";}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1888 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = ">";}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1889 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "<=";}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1890 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = ">=";}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1894 "syntacticAnalyzer.y"
    {
		(yyval.type) = setType((yyvsp[(1) - (1)].type)); 
		(yyval.type)->truelist = (yyvsp[(1) - (1)].type)->truelist;
		(yyval.type)->falselist = (yyvsp[(1) - (1)].type)->falselist;
		(yyval.type)->place = (yyvsp[(1) - (1)].type)->place; 
	}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1901 "syntacticAnalyzer.y"
    {
		if(strcmp((yyvsp[(2) - (4)].type)->entry,"OR")==0 && (yyvsp[(1) - (4)].type)->dataType == DT_BOOL && (yyvsp[(4) - (4)].type)->dataType == DT_BOOL) 
		{
			(yyval.type) = setBasicType(DT_BOOL);
			BackPatch((yyvsp[(1) - (4)].type)->falselist,(yyvsp[(3) - (4)].ival));
			(yyval.type)->truelist = merge((yyvsp[(1) - (4)].type)->truelist,(yyvsp[(4) - (4)].type)->truelist);
			(yyval.type)->falselist = (yyvsp[(4) - (4)].type)->falselist;
		}
		else if(ClubTypeCheck((yyvsp[(1) - (4)].type),(yyvsp[(4) - (4)].type)) == 0)
		{ 
			numTypeError++;errorFreeType = 0; 
			(yyval.type) = setBasicType(DT_ERROR); 
			printf("(Line %d) Type Error in constant expression\n",line_number);
		}
		else
		{
			(yyval.type) =setType(getArithType((yyvsp[(1) - (4)].type),(yyvsp[(4) - (4)].type))); 
			(yyval.type)->place = get_new_temp(scopeStack->val);
			Add(scopeStack->val,(yyval.type)->width);  // for $$->place 's get_new_temp
			if((yyvsp[(1) - (4)].type)->dataType == DT_INT && (yyvsp[(4) - (4)].type)->dataType == DT_INT) 
			{
				sprintf(tempName,"%s%s","int",(yyvsp[(2) - (4)].type)->entry);
				emitcode(tempName,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,(yyvsp[(4) - (4)].type)->place);
			}
			else if((yyvsp[(1) - (4)].type)->dataType == DT_REAL && (yyvsp[(4) - (4)].type)->dataType == DT_REAL) 
			{
				sprintf(tempName,"%s%s","real",(yyvsp[(2) - (4)].type)->entry);
				emitcode(tempName,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,(yyvsp[(4) - (4)].type)->place);
			}
			if((yyvsp[(1) - (4)].type)->dataType == DT_INT && (yyvsp[(4) - (4)].type)->dataType == DT_REAL) 
			{
				char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);
				emitcode("<IntToReal>",u,(yyvsp[(1) - (4)].type)->place,NULL);
				sprintf(tempName,"%s%s","real",(yyvsp[(2) - (4)].type)->entry);
				emitcode(tempName,(yyval.type)->place,u,(yyvsp[(4) - (4)].type)->place);
			}
			if((yyvsp[(1) - (4)].type)->dataType == DT_REAL && (yyvsp[(4) - (4)].type)->dataType == DT_INT) 
			{
				char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);
				emitcode("<IntToReal>",u,(yyvsp[(4) - (4)].type)->place,NULL);
				sprintf(tempName,"%s%s","real",(yyvsp[(2) - (4)].type)->entry);
				emitcode(tempName,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,u);
			}		
		}
	}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1948 "syntacticAnalyzer.y"
    { (yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "+";}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1949 "syntacticAnalyzer.y"
    { (yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "-";}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1950 "syntacticAnalyzer.y"
    { (yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "OR";}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1951 "syntacticAnalyzer.y"
    { (yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "XOR";}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1955 "syntacticAnalyzer.y"
    {
		(yyval.type) = (yyvsp[(1) - (1)].type); 
		(yyval.type) = setType((yyvsp[(1) - (1)].type)); 
		(yyval.type)->truelist = (yyvsp[(1) - (1)].type)->truelist;
		(yyval.type)->falselist = (yyvsp[(1) - (1)].type)->falselist;
		(yyval.type)->place = (yyvsp[(1) - (1)].type)->place; 
		//printf("\n...............$$->place in 2 = %s ........\n",$$->place);
	}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1964 "syntacticAnalyzer.y"
    {
		flag=1;
		if(strcmp((yyvsp[(2) - (4)].type)->entry,"AND")==0 && (yyvsp[(1) - (4)].type)->dataType == DT_BOOL && (yyvsp[(4) - (4)].type)->dataType == DT_BOOL) 
		{
			(yyval.type) = setBasicType(DT_BOOL);
			BackPatch((yyvsp[(1) - (4)].type)->truelist,(yyvsp[(3) - (4)].ival));
			(yyval.type)->truelist = (yyvsp[(4) - (4)].type)->truelist;
			(yyval.type)->falselist = merge((yyvsp[(1) - (4)].type)->falselist,(yyvsp[(4) - (4)].type)->falselist);
		}
		else if(ClubTypeCheck((yyvsp[(1) - (4)].type),(yyvsp[(4) - (4)].type))== 0)
		{
			printf("(Line %d) Type Error in constant expression\n",line_number); flag =0 ;
		}
		else 
		{
			if((yyvsp[(2) - (4)].type)->counter ==STAR ||  (yyvsp[(2) - (4)].type)->counter == SLASH || (yyvsp[(2) - (4)].type)->counter == DIV) 
			{ 
				(yyval.type) = setType(getArithType((yyvsp[(1) - (4)].type),(yyvsp[(4) - (4)].type))); 
				(yyval.type)->place = get_new_temp(scopeStack->val);
				Add(scopeStack->val,(yyval.type)->width); // for get_new_temp of $$
				if((yyvsp[(1) - (4)].type)->dataType == DT_INT && (yyvsp[(4) - (4)].type)->dataType == DT_INT) 
				{
					sprintf(tempName,"%s%s","int",(yyvsp[(2) - (4)].type)->entry);
					emitcode(tempName,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,(yyvsp[(4) - (4)].type)->place);
				}
				else if((yyvsp[(1) - (4)].type)->dataType == DT_REAL && (yyvsp[(4) - (4)].type)->dataType == DT_REAL) 
				{
					sprintf(tempName,"%s%s","real",(yyvsp[(2) - (4)].type)->entry);
					emitcode(tempName,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,(yyvsp[(4) - (4)].type)->place);			
				}
				if((yyvsp[(1) - (4)].type)->dataType == DT_INT && (yyvsp[(4) - (4)].type)->dataType == DT_REAL) 
				{
					char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);
					emitcode("<IntToReal>",u,(yyvsp[(1) - (4)].type)->place,NULL);
					sprintf(tempName,"%s%s","real",(yyvsp[(2) - (4)].type)->entry);
					emitcode(tempName,(yyval.type)->place,u,(yyvsp[(4) - (4)].type)->place);
				}
				if((yyvsp[(1) - (4)].type)->dataType == DT_REAL && (yyvsp[(4) - (4)].type)->dataType == DT_INT) 
				{
					char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);
					emitcode("<IntToReal>",u,(yyvsp[(4) - (4)].type)->place,NULL);
					sprintf(tempName,"%s%s","real",(yyvsp[(2) - (4)].type)->entry);
					emitcode(tempName,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,u);
				}			
			} 
			else if((yyvsp[(2) - (4)].type)->counter == MOD || (yyvsp[(2) - (4)].type)->counter== SHR || (yyvsp[(2) - (4)].type)->counter == SHL) 
			{
				if(strictClub((yyvsp[(1) - (4)].type)) == DT_INT && strictClub((yyvsp[(4) - (4)].type)) == DT_INT ) 
				{
					(yyval.type) = setBasicType(DT_INT);
					(yyval.type)->place = get_new_temp(scopeStack->val);
					Add(scopeStack->val,(yyval.type)->width); // for get_new_temp of $$
					emitcode((yyvsp[(2) - (4)].type)->entry,(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,(yyvsp[(4) - (4)].type)->place);
				}
				else 
				{ 
					flag =0; 
					printf("(Line %d) Type Error in constant expression\n",line_number);
				}
			} 
			else if((yyvsp[(2) - (4)].type)->counter == AND) 
			{ 
				if((yyvsp[(1) - (4)].type)->dataType == DT_INT && (typeCheck((yyvsp[(1) - (4)].type),(yyvsp[(4) - (4)].type)) ==1)) 
				{
					(yyval.type) = setBasicType(DT_INT);
					(yyval.type)->place = get_new_temp(scopeStack->val);
					Add(scopeStack->val,(yyval.type)->width); // for get_new_temp of $$
					emitcode("AND",(yyval.type)->place,(yyvsp[(1) - (4)].type)->place,(yyvsp[(4) - (4)].type)->place);
				}
				else 	
				{
					printf("(Line %d) Type Error in constant expression\n",line_number); 
					flag = 0; 
				} 
			}
			if (flag == 0) 
			{ 
				(yyval.type) = setBasicType(DT_ERROR);
				numTypeError++;errorFreeType = 0; 
			}	
		} 
	}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 2048 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "*"; (yyval.type)->counter = STAR;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 2049 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "/"; (yyval.type)->counter = SLASH;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 2050 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "/";  (yyval.type)->counter = DIV;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 2051 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "MOD";  (yyval.type)->counter = MOD;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 2052 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "SHL";  (yyval.type)->counter = SHL;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 2053 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "SHR";  (yyval.type)->counter = SHR;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 2054 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);	(yyval.type)->entry = "AND";  (yyval.type)->counter = AND;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 2057 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 2058 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 2060 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_VOID); 
		(yyval.type)->place = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_INT);
		emitcode("NIL",(yyval.type)->place,NULL,NULL);
	}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 2065 "syntacticAnalyzer.y"
    { (yyval.type)=(yyvsp[(2) - (3)].type);}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 2067 "syntacticAnalyzer.y"
    {
		(yyval.type) = setType((yyvsp[(2) - (2)].type));
		(yyval.type)->truelist = (yyvsp[(2) - (2)].type)->falselist;
		(yyval.type)->falselist = (yyvsp[(2) - (2)].type)->truelist; 
		sprintf(tempName,"%s %s","NOT",(yyvsp[(2) - (2)].type)->place);
		(yyval.type)->place = tempName;
	}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 2075 "syntacticAnalyzer.y"
    {
		(yyval.type) = setType((yyvsp[(2) - (2)].type));
		(yyval.type)->place = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_INT);
		emitcode((yyvsp[(1) - (2)].type)->code,(yyval.type)->place,(yyvsp[(2) - (2)].type)->place,NULL);
	}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 2081 "syntacticAnalyzer.y"
    {
		 (yyval.type) = (yyvsp[(2) - (2)].type); 
		augmentType(&(yyval.type),DT_PTR);
		 (yyval.type)->place = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_PTR);
		 emitcode("^",(yyval.type)->place,(yyvsp[(2) - (2)].type)->place,NULL);
	}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 2088 "syntacticAnalyzer.y"
    {
		if((yyvsp[(1) - (1)].type)->entry != NULL)	
		{
			if((yyvsp[(1) - (1)].type)->dataType == DT_FUNCTION)
	 		{
				if((yyvsp[(1) - (1)].type)->next == NULL)		//no arguments
					(yyvsp[(1) - (1)].type)->next = setBasicType(DT_VOID);
				sym* temp;
				flag = 0;
				if((yyvsp[(1) - (1)].type)->flag == 1)		//object attributes
				{
					stack* tempStack;
					Push(&tempStack,(yyvsp[(1) - (1)].type)->funcAttScope);
					temp = getEntry((yyvsp[(1) - (1)].type)->entry,tempStack);
				}				
				else				//find variable from scope stack
					temp = getEntry((yyvsp[(1) - (1)].type)->entry,scopeStack);
				if(temp == NULL || temp->type == NULL) 		//error
				{
					(yyval.type) = setBasicType(DT_ERROR);
					numTypeError++;errorFreeType = 0; 
				}
				else	
				{
					if(temp->type->dataType == DT_FUNCTION)
					{	
						flag = 0;
						counter = 0;
						Type	*tempCall,*tempDef;
						tempCall = (yyvsp[(1) - (1)].type);
						tempDef = temp->type;
						stack* tempStack;
						Push(&tempStack,temp->type->attScope);
						(yyval.type)->place = get_new_temp(scopeStack->val); 
						Add(scopeStack->val,getEntry("Result",tempStack)->type->width); 
						while(tempDef !=NULL && tempCall != NULL)				//types for actual parameters and formal parameters
						{
							if(typeCheck(tempCall,tempDef) == 0) 
							{
								if(assignTypeCheck(tempDef,tempCall) == 1) 
								{
									if(counter>=2) 
									{ 
										if(tempCall->dataType == DT_INT)
											emitcode("paramI",tempCall->place,NULL,NULL);
										else if(tempCall->dataType == DT_REAL)
											emitcode("paramF",tempCall->place,NULL,NULL);
										else if(tempCall->dataType == DT_BOOL)
											emitcode("paramB",tempCall->place,NULL,NULL);
										else if(tempCall->dataType == DT_STRING)
											emitcode("paramS",tempCall->place,NULL,NULL);
										else
											emitcode("paramI",tempCall->place,NULL,NULL);
									}
								}
								else	
								{
									flag = 1;
									printf("(Line %d) Incompatible types in Function Call. Found ",line_number); printType(tempCall); printf(" required "); printType(tempDef); (yyval.type) = setBasicType(DT_ERROR); 
									numTypeError++;errorFreeType = 0;
									break;
								}
							}			
							if(counter>=2) 
							{ 
								if(tempCall->dataType == DT_INT)
									emitcode("paramI",tempCall->place,NULL,NULL);
								else if(tempCall->dataType == DT_REAL)
									emitcode("paramF",tempCall->place,NULL,NULL);
								else if(tempCall->dataType == DT_BOOL)
									emitcode("paramB",tempCall->place,NULL,NULL);
								else if(tempCall->dataType == DT_STRING)
									emitcode("paramS",tempCall->place,NULL,NULL);
								else
									emitcode("paramI",tempCall->place,NULL,NULL);
							}
							tempCall = tempCall->next;
							tempDef = tempDef->next;
							counter++;
						}
						if((tempDef==NULL && tempCall != NULL) || (tempDef!=NULL && tempCall == NULL)) 
						{	
							flag =1;
							printf("\n(Line %d) Unexpected number of arguments\n",line_number);
						}
						char* cnt = (char*) malloc(10);
						counter = counter - 2;
						sprintf(cnt,"%d",counter);
						if((yyvsp[(1) - (1)].type)->flag == 1)
							sprintf(tempName,"%s@%d",(yyvsp[(1) - (1)].type)->entry,(yyvsp[(1) - (1)].type)->funcAttScope);
						else
							sprintf(tempName,"%s@%d",(yyvsp[(1) - (1)].type)->entry,getEntry((yyvsp[(1) - (1)].type)->entry,scopeStack)->myScope);
						emitcode("call",(yyval.type)->place,tempName,cnt); 
					}
					else
					{
						printf("\nError in Function Call\n");
						(yyval.type) = setBasicType(DT_ERROR);
						numTypeError++;errorFreeType = 0;
					}
					if(flag == 0)
					{
						stack* tempStack;
						Push(&tempStack, temp->type->attScope);
						(yyval.type) = getEntry("Result",tempStack)->type;
					}
					else
					{
						printf("\n(Line %d) Error in Function Call\n",line_number);
						(yyval.type) = setBasicType(DT_ERROR);
						numTypeError++;errorFreeType = 0; 
					}
				}
			}
			else
				(yyval.type) =(yyvsp[(1) - (1)].type);
		}
		(yyval.type)->place = (yyvsp[(1) - (1)].type)->place;
	}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 2208 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_BOOL); 
		(yyval.type)->place = "TRUE";
		if(ifFlag == 1) 
		{
			(yyval.type)->truelist = create_new_list(quadId); 
			emitcode("goto",NULL,"---",NULL);
		}
	}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 2218 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_BOOL); 
		(yyval.type)->place = "FALSE";
		if(ifFlag == 1) 
		{
			(yyval.type)->falselist = create_new_list(quadId); 
			emitcode("goto",NULL,"---",NULL);
		}
	}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 2230 "syntacticAnalyzer.y"
    {
		(yyval.ival) = quadId; 
	}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 2236 "syntacticAnalyzer.y"
    {
		(yyval.type)->nextlist = create_new_list(quadId);
		emitcode("goto",NULL,"---",NULL);
	}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 2243 "syntacticAnalyzer.y"
    {
		(yyval.type) = (yyvsp[(2) - (2)].type);  
		for(i = (yyvsp[(1) - (2)].ival);i>=1;i--)  augmentType(&(yyval.type),DT_PTR); 
	}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 2248 "syntacticAnalyzer.y"
    {
		(yyval.type) = CopyType2((yyvsp[(1) - (1)].type)); 
		(yyval.type)->place = (char *)malloc(100); // for place in 3 address code
		if((yyvsp[(1) - (1)].type)->place!=NULL) sprintf((yyval.type)->place,"%s",(yyvsp[(1) - (1)].type)->place);
	}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 2255 "syntacticAnalyzer.y"
    { (yyval.ival)=1;}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 2256 "syntacticAnalyzer.y"
    {  (yyval.ival) = (yyvsp[(1) - (2)].ival) + 1; }
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 2259 "syntacticAnalyzer.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); (yyval.type)->next = NULL; (yyval.type)->flag=0;}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 2260 "syntacticAnalyzer.y"
    { (yyval.type) = (yyvsp[(2) - (2)].type); }
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 2261 "syntacticAnalyzer.y"
    { (yyval.type) = (yyvsp[(2) - (3)].type); }
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 2262 "syntacticAnalyzer.y"
    { (yyval.type) = setBasicType(DT_VOID); (yyval.type)->next = NULL; (yyval.type)->code = "";}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 2264 "syntacticAnalyzer.y"
    {
		flag =0;
		sym* temp;
		if((yyvsp[(2) - (2)].type)->counter == -2)
		{
			(yyval.type) = getSubType((yyvsp[(1) - (2)].type));
			sym *tempE = getEntry((yyvsp[(1) - (2)].type)->entry,scopeStack);
			if(tempE != NULL)
			{	
				Type *temp2 = tempE->type;		
				char* tempName2= (char*)malloc(10);
				char* temp = (yyvsp[(2) - (2)].type)->code;		
				sprintf(tempName,"%s",get_new_temp(scopeStack->val)); Add(scopeStack->val,SIZE_INT);
				sprintf(tempName2,"%d",temp2->low);
				emitcode("int-",tempName,strtok(temp,","),tempName2);
				while(temp2->next->next!=NULL )
				{
					sprintf(tempName2,"%d",temp2->next->maxIndex);
					emitcode("int*",tempName,tempName,tempName2);
					emitcode("int+",tempName,tempName,strtok(NULL,","));
					sprintf(tempName2,"%d",temp2->next->low);
					emitcode("int-",tempName,tempName,tempName2);
					temp2 = temp2->next;
					(yyval.type) = getSubType((yyval.type));
				}
			}
			(yyval.type)->place = (char *)malloc(100);
			sprintf((yyval.type)->place,"%s[%s]",(yyvsp[(1) - (2)].type)->place,tempName);
			(yyval.type)->counter = -3;
		}
		else if((yyvsp[(2) - (2)].type)->counter == -1)
		{	
			stack *tempStack;
			Push(&tempStack, (yyvsp[(1) - (2)].type)->attScope);
			temp = getEntry((yyvsp[(2) - (2)].type)->entry,tempStack);
			if(temp != NULL) 
			{
				(yyval.type) = temp->type;
				/* For function in object*/
				if(temp->type->dataType == DT_PROC || temp->type->dataType == DT_FUNCTION)
				{
					(yyval.type)->flag = 1;
					(yyval.type)->funcAttScope = (yyvsp[(1) - (2)].type)->attScope;
				}
				else
				{
					if(temp->token==PRIVATE) 
					{
						printf("(Error) :%s is private \n",temp->lexeme);
						numTypeError++;errorFreeType = 0; 
						(yyval.type)=setBasicType(DT_ERROR);
					}	
					(yyval.type)->flag=0;
				}
				(yyval.type)->place = (char *)malloc(100);
				sprintf((yyval.type)->place,"%s%s@%d",(yyvsp[(1) - (2)].type)->place,(yyvsp[(2) - (2)].type)->code,tempStack->val);
			}
			else
			{
				(yyval.type) = setBasicType(DT_ERROR);
				numTypeError++;errorFreeType = 0;
				printf("\n(Line %d) %s not found in scope of %s \n",line_number,(yyvsp[(2) - (2)].type)->entry,(yyvsp[(1) - (2)].type)->entry);
			}
		}
		else if((yyvsp[(1) - (2)].type)->entry != NULL)
		{
			if((yyvsp[(1) - (2)].type)->flag == 1)
			{
				stack *tempStack;
				Push(&tempStack, (yyvsp[(1) - (2)].type)->funcAttScope);
				temp = getEntry((yyvsp[(1) - (2)].type)->entry,tempStack);
			}
			else
				temp = getEntry((yyvsp[(1) - (2)].type)->entry,scopeStack);
			if(temp == NULL || temp->type == NULL)
			{
				(yyval.type) = setBasicType(DT_ERROR);
			}
			else	
			{
				if(temp->type->dataType == DT_PROC || temp->type->dataType == DT_FUNCTION )
				{	(yyvsp[(1) - (2)].type)->next = (yyvsp[(2) - (2)].type);
					(yyval.type) = (yyvsp[(1) - (2)].type);
					(yyval.type)->counter = (yyvsp[(2) - (2)].type)->counter+1;
					Type* temp1 = (yyval.type);
					for(i=1;i<=(yyval.type)->counter;i++)
					{
						temp1 = temp1->next;
					}
					if((yyvsp[(1) - (2)].type)->flag == 0)
					(yyval.type)->place = (char *)malloc(100);
					sprintf((yyval.type)->place,"%s%s",(yyvsp[(1) - (2)].type)->place,(yyvsp[(2) - (2)].type)->code);
				}
				else
				{
					(yyval.type) = setBasicType(DT_ERROR);
					numTypeError++;errorFreeType = 0; 
					 (yyval.type)->next = NULL;
				}
			}
		}
		else
		{
			(yyval.type) = setBasicType(DT_ERROR); numTypeError++;errorFreeType = 0; 
			 (yyval.type)->next = NULL; 
		}
		if(strcmp((yyvsp[(1) - (2)].type)->entry,"WRITE")==0 || strcmp((yyvsp[(1) - (2)].type)->entry,"READ")==0 || strcmp((yyvsp[(1) - (2)].type)->entry,"WRITELN")==0 || strcmp((yyvsp[(1) - (2)].type)->entry,"READLN")==0 )
		{
				(yyvsp[(1) - (2)].type)->next = (yyvsp[(2) - (2)].type);
				(yyval.type) =(yyvsp[(1) - (2)].type);
				(yyval.type)->counter = (yyvsp[(2) - (2)].type)->counter+1;
		}
	
	}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 2382 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_VOID);
		(yyval.type)->counter = -2;
		Type* temp;
		temp = (yyvsp[(2) - (3)].type);
		(yyval.type)->code = malloc(strlen((yyvsp[(2) - (3)].type)->place)+(yyvsp[(2) - (3)].type)->counter*5+3);
		char *tempPlace1 = (char*)malloc(strlen((yyvsp[(2) - (3)].type)->place)+(yyvsp[(2) - (3)].type)->counter*5+3);
		char *tempPlace2 = (char*)malloc(strlen((yyvsp[(2) - (3)].type)->place)+(yyvsp[(2) - (3)].type)->counter*5+3);
		while(temp!=NULL)	//appending expressions in tempPlace1
		{
			sprintf(tempPlace2,"%s,%s",tempPlace1,temp->place);
			strcpy(tempPlace1,tempPlace2);
			temp= temp->next;
		}
		sprintf((yyval.type)->code,"%s",tempPlace1+1);
		//sprintf($$->code,"[%s]",$2->place);
	}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 2400 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_VOID); 
		(yyval.type)->counter = -2;
		 (yyval.type)->code = "[]";
	}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 2406 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_VOID); 
		(yyval.type)->next = (yyvsp[(2) - (3)].type); 		//stroing the expr list in next
		(yyval.type)->counter = (yyvsp[(2) - (3)].type)->counter + 1; 
		(yyval.type)->code = malloc(strlen((yyvsp[(2) - (3)].type)->place)+10);
		sprintf((yyval.type)->code,"");
	}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 2414 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_VOID); 
		(yyval.type)->code = "";
	}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 2419 "syntacticAnalyzer.y"
    {
		(yyval.type) = (yyvsp[(2) - (2)].type); 
		(yyval.type) -> counter = -1; 
		(yyval.type)->code = malloc(strlen((yyvsp[(2) - (2)].type)->place)+10) ; 
		sprintf((yyval.type)->code,".%s",(yyvsp[(2) - (2)].type)->place);	
	}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 2426 "syntacticAnalyzer.y"
    { 
		(yyval.type) = setBasicType(DT_VOID); 
		(yyval.type)->counter = -2; 
		(yyval.type)->code = "^"; 
	}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 2433 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 2435 "syntacticAnalyzer.y"
    {
		 if((yyvsp[(1) - (3)].type)->dataType == DT_INT && (yyvsp[(3) - (3)].type)->dataType == DT_INT) 
		{
			 (yyval.type) = setBasicType(DT_SUBR); 
			 (yyval.type)->place = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_INT);
			// emitcode("DOTDOT",$$->place,$1->place,$3->place);
		} 
		else 
		{ 
			(yyval.type) = setBasicType(DT_ERROR); 
			numTypeError++;errorFreeType = 0;  
		}
	}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 2451 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_STRING); 
		(yyval.type)->width = strlen((yyvsp[(1) - (1)].name)); 		//width to store_argument the string
		(yyval.type)->entry = (char*) malloc(strlen((yyvsp[(1) - (1)].name))+1);
		sprintf((yyval.type)->entry,"%s",(yyvsp[(1) - (1)].name));
		(yyval.type)->next = NULL;
		(yyval.type)->flag = CHAR_STRING;
		(yyval.type)->place = (yyval.type)->entry;
	}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 2460 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_STRING); }
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 2461 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_STRING); }
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 2462 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_STRING); }
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 2465 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_REAL);}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 2466 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_REAL);}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 2467 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_REAL);}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 2470 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_INT);}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 2471 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_BOOL);}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 2472 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_CHAR);}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 2475 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_STRING);}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 2479 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_VOID); 
		(yyval.type)->entry = "DEFAULT";
		(yyval.type)->place = "DEFAULT";
	}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 2485 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_PROC);
		(yyval.type)->entry = "READ"; 
		(yyval.type)->place = "READ";
	}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 2491 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_PROC); 
		(yyval.type)->entry = "WRITELN";
		(yyval.type)->place = "WRITELN";
	}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 2497 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_PROC); 
		(yyval.type)->entry = "WRITE"; 
		(yyval.type)->place = "WRITE";
	}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 2503 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_VOID); 
		(yyval.type)->entry = "store_argumentD"; 
		(yyval.type)->place = "store_argumentD";
	}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 2509 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_VOID); 
		(yyval.type)->entry = "NODEFAULT"; 
		(yyval.type)->place = "NODEFAULT";
	}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 2515 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_VOID); 
		(yyval.type)->entry = "IMPLEMENTS";
		(yyval.type)->place = "IMPLEMENTS";
	}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 2521 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_VOID);
		(yyval.type)->entry = "WRITEONLY";
		(yyval.type)->place = "WRITEONLY";
	}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 2527 "syntacticAnalyzer.y"
    {
		(yyval.type) = setBasicType(DT_VOID);
		(yyval.type)->entry = "READONLY";
		(yyval.type)->place = "READONLY"; 
	}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 2535 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 2536 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 2537 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 2538 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 2539 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 2540 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 2541 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 2542 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 2543 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 2544 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 2548 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 2549 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 2550 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 2551 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 2554 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 2555 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 2556 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 2557 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 2558 "syntacticAnalyzer.y"
    {(yyval.type) = setBasicType(DT_VOID);}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 2562 "syntacticAnalyzer.y"
    {
		sym* temp;
		temp = getEntry((yyvsp[(1) - (1)].name),scopeStack);
		if(temp == NULL || temp->type == NULL) 	//entry will be created during variable declaration (var_name)
		{
			(yyval.type) = setBasicType(DT_ERROR);
			(yyval.type)->entry = yytext;
			(yyval.type)->code = "";
			(yyval.type)->place = (yyval.type)->entry;	
		}
		else	
		{
			(yyval.type) = setType(temp->type);
			(yyval.type)->attScope = temp->type->attScope;
			(yyval.type)->entry = getEntry((yyvsp[(1) - (1)].name),scopeStack)->lexeme;
			(yyval.type)->next =  temp->type->next;	//if ident list
			(yyval.type)->code = "";
			(yyval.type)->place = (char*)malloc (strlen((yyval.type)->entry));
			sprintf((yyval.type)->place,"%s@%d",(yyval.type)->entry,temp->myScope);	//putting variable name along with scope as place
		}
	}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 2583 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 2584 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 2585 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 2586 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 2587 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 2588 "syntacticAnalyzer.y"
    {(yyval.type)=(yyvsp[(1) - (1)].type);}
    break;



/* Line 1455 of yacc.c  */
#line 6726 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 2591 "syntacticAnalyzer.y"

void errorLog(){
if (numError>1 && numTypeError==0)printf(" \n ** Your program was erroneous. %d syntax errors found. ** \n\n",numError);
else if (numError==0 && numTypeError>0)printf(" \n ** Your program was erroneous.  ** \n\n");
if (numError>0 && numTypeError>0)printf(" \n ** Your program was erroneous. ** \n\n");
}

void yyerror(char *s) {
   errorFree = 0;
numError = numError + 1;
printf("(Line %d) Syntax Error, Unexpected token : %s \n",line_number,yytext);

}

int main()
{
	char *file_name;
	file_name=(char*)malloc(40*sizeof(char));
	yyparse();
	Print();
	PrintHeader();
	if(errorFreeType == 1 && errorFree == 1)
	{
		printCode();
		strcpy(file_name,"output.s");	
		data = fopen("data","w+");
		text = fopen("text","w+");
		fprintf(data,".data\n");
		fprintf(data,"\tstr: .asciiz \" Program ended. \\n\" \n");
		fprintf(data,"\tnewLine: .asciiz \"\\n\" \n");
		
		for(i=0;i<MAX_SCOPES;i++)
		{
			if(scopeHeader[i] != NULL)
				fprintf(data,"\tscope%d: .space 4\n",i);
		}
		
		fprintf(text,"\n.text\n");
		Codegen();
		fclose(data);
		fclose(text);
		data = fopen("data","r");
		text = fopen("text","r");
		FILE *out = fopen(file_name,"w+");
		char* d = (char*)malloc(20000*sizeof(char));
		char* t = (char*)malloc(20000*sizeof(char));
		int dataFile = fread((void*)d,sizeof(char),20000,data);
		int textFile = fread((void*)t,sizeof(char),20000,text);
		strcat(d,t);
		fwrite(d,sizeof(char), textFile+dataFile,out);
		fclose(data);
		fclose(text);
		fclose(out);
}
}

