/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "Final.y" /* yacc.c:339  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
char code[1024];
char allFunction[512];
char buffer[128];
struct varible{
	struct varible* next;
	int typeFlag;
	char name[];
};
struct varible* Begin = NULL;
struct function{
	struct function* next;
	struct varible* parameter;
	int paraNum;
	int stage;
	char name[10];
};
struct function* Fbegin = NULL;
struct functionStack{
	struct function* nowFun;
	struct functionStack* previous;
};
struct functionStack* top = NULL;
char funCounter = 'A';
int defineFlag = 0;

void yyerror(const char* message);
void creatVarible(char* varName, char* varValue);
void checkRedefined(char* varName);
void creatFunction(char* funName);
void addParam(char* parName);
void setFun();
void loadFunction(char* funName);
void checkParaNum();
void pushFun(struct function* fun, int sta);
void popFun(int sta);

#line 108 "Final.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Final.tab.h".  */
#ifndef YY_YY_FINAL_TAB_H_INCLUDED
# define YY_YY_FINAL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    ID = 259,
    PRINT_NUM = 260,
    PRINT_BOOL = 261,
    DEF_HEADER = 262,
    BOOLEAN = 263,
    MODOP = 264,
    LR = 265,
    ANDOP = 266,
    OROP = 267,
    NOTOP = 268,
    FUNLR = 269,
    IF = 270
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 42 "Final.y" /* yacc.c:355  */

	char* word;

#line 168 "Final.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_FINAL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 183 "Final.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   153

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  24
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    16,    19,    17,     2,    18,     2,    20,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      22,    23,    21,     2,     2,     2,     2,     2,     2,     2,
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
      15
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   105,   105,   106,   109,   110,   111,   114,   115,   117,
     118,   118,   120,   123,   124,   125,   126,   127,   128,   129,
     130,   133,   134,   135,   136,   137,   139,   140,   141,   143,
     144,   145,   148,   149,   151,   152,   154,   155,   157,   158,
     160,   161,   164,   166,   168,   170,   172,   175,   177,   179,
     182,   184,   186,   189,   191,   193,   195,   198,   198,   199,
     200,   202,   203,   205,   206,   208,   209,   211,   211,   212,
     212,   213,   213,   214,   214,   216,   217,   219
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ID", "PRINT_NUM",
  "PRINT_BOOL", "DEF_HEADER", "BOOLEAN", "MODOP", "LR", "ANDOP", "OROP",
  "NOTOP", "FUNLR", "IF", "')'", "'+'", "'-'", "'*'", "'/'", "'>'", "'<'",
  "'='", "$accept", "PROGRAM", "STMT", "PRINT_STMT", "DEF_STMT", "$@1",
  "VARIBLE", "EXP", "NUM_OP", "COMPARE_OP", "LOGICAL_OP", "ADDEXP",
  "MULTIPLYEXP", "ANDEXP", "OREXP", "EQUALEXP", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "MODULUS", "GREATER", "SMALLER", "EQUAL", "AND",
  "OR", "NOT", "IF_EXP", "TEST_EXP", "THEN_EXP", "ELSE_EXP", "FUN_EXP",
  "$@2", "FUN_IDS", "IDS", "ALLDEF", "FUN_BODY", "FUN_CALL", "$@3", "$@4",
  "$@5", "$@6", "PARAM", "FUN_NAME", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    41,    43,    45,    42,
      47,    62,    60,    61
};
# endif

#define YYPACT_NINF -80

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-80)))

#define YYTABLE_NINF -78

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      60,   -80,   -80,   -80,    68,   132,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   135,   135,
      -2,   135,   135,   135,   135,   -80,   135,   135,   135,   135,
     135,   135,   135,   135,     2,     6,   -80,   -80,   108,     9,
      11,    21,   135,   -80,   135,   -80,   135,   -80,   135,    22,
      33,   -80,   135,   -80,   135,   135,   -80,   135,   135,   135,
     135,   -80,   135,   135,    30,   135,    34,   -80,   -80,    35,
      38,    40,    41,    43,   -80,    15,   143,   -80,   135,    46,
      49,    50,    51,    62,    77,    78,   -80,    13,   -80,    45,
     -80,   -80,    80,   -80,   -80,   -80,   -80,   -80,    16,    88,
     -80,   -80,   143,    82,   -80,    97,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    13,    12,    14,     0,     0,     2,     5,     6,    15,
       4,    16,    17,    18,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    19,    20,    77,     0,     0,
       0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    71,     1,     3,     0,     0,
       0,    12,     0,    10,     0,    36,     0,    38,     0,     0,
       0,    54,     0,    32,     0,     0,    34,     0,     0,     0,
       0,    40,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,    37,    39,    52,     0,     0,    55,     0,    33,
       0,    35,     0,     0,     0,    41,    75,     0,    70,     0,
      74,     9,     0,    46,    50,    51,    61,    60,     0,     0,
      63,    65,     0,     0,    56,     0,    42,    43,    44,    45,
      47,    48,    49,    68,    76,    72,    11,    62,    59,    64,
      66,    58,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,   -80,    71,   -80,   -79,   -80,    24,   -28,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,    36,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,    29,    84
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    80,     9,    10,    11,    12,
      13,    64,    67,    56,    58,    72,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    62,    88,
     115,    44,    60,    86,   108,   112,   113,    26,    73,    74,
      75,    76,    97,    45
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    50,    51,    54,    55,    57,    59,   110,    61,    63,
      65,    66,    68,    69,    70,    71,     1,     2,   -69,   106,
     127,     3,   -73,    48,    79,    77,    81,    78,    82,   123,
      83,   107,   128,   129,    87,   -77,    89,    90,    84,    91,
      92,    93,    94,    85,    95,    96,    98,    96,     1,     2,
     100,   101,    35,     3,    52,    48,   103,   104,   111,   105,
     114,   125,   116,     1,     2,   117,   118,   119,     3,   124,
       4,   124,    27,    28,    29,    30,    47,    31,   120,    32,
      33,    34,    35,    36,   130,    37,    38,    39,    40,    41,
      42,    43,    27,   121,   122,    30,   126,    31,   131,    32,
      33,    34,    35,    36,    99,    37,    38,    39,    40,    41,
      42,    43,    27,   132,    53,     0,   102,    31,     0,    32,
      33,    34,    35,    36,     0,    37,    38,    39,    40,    41,
      42,    43,    46,     0,     0,     1,     2,     0,     1,     2,
       3,     0,     4,     3,     0,    48,     1,     2,     0,     0,
       0,     3,     0,   109
};

static const yytype_int8 yycheck[] =
{
      28,    29,     4,    31,    32,    33,    34,    86,    36,    37,
      38,    39,    40,    41,    42,    43,     3,     4,    16,     4,
       4,     8,    16,    10,    52,    16,    54,    16,    56,    16,
      58,    16,    16,   112,    62,    14,    64,    65,    16,    67,
      68,    69,    70,    10,    72,    73,    16,    75,     3,     4,
      16,    16,    14,     8,    30,    10,    16,    16,    86,    16,
      88,    16,    16,     3,     4,    16,    16,    16,     8,    97,
      10,    99,     4,     5,     6,     7,     5,     9,    16,    11,
      12,    13,    14,    15,   112,    17,    18,    19,    20,    21,
      22,    23,     4,    16,    16,     7,    16,     9,    16,    11,
      12,    13,    14,    15,    75,    17,    18,    19,    20,    21,
      22,    23,     4,    16,    30,    -1,    80,     9,    -1,    11,
      12,    13,    14,    15,    -1,    17,    18,    19,    20,    21,
      22,    23,     0,    -1,    -1,     3,     4,    -1,     3,     4,
       8,    -1,    10,     8,    -1,    10,     3,     4,    -1,    -1,
      -1,     8,    -1,    10
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     8,    10,    25,    26,    27,    28,    30,
      31,    32,    33,    34,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    61,     4,     5,     6,
       7,     9,    11,    12,    13,    14,    15,    17,    18,    19,
      20,    21,    22,    23,    55,    67,     0,    26,    10,    31,
      31,     4,    30,    67,    31,    31,    37,    31,    38,    31,
      56,    31,    52,    31,    35,    31,    31,    36,    31,    31,
      31,    31,    39,    62,    63,    64,    65,    16,    16,    31,
      29,    31,    31,    31,    16,    10,    57,    31,    53,    31,
      31,    31,    31,    31,    31,    31,    31,    66,    16,    66,
      16,    16,    55,    16,    16,    16,     4,    16,    58,    10,
      28,    31,    59,    60,    31,    54,    16,    16,    16,    16,
      16,    16,    16,    16,    31,    16,    16,     4,    16,    28,
      31,    16,    16
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    24,    25,    25,    26,    26,    26,    27,    27,    28,
      29,    28,    30,    31,    31,    31,    31,    31,    31,    31,
      31,    32,    32,    32,    32,    32,    33,    33,    33,    34,
      34,    34,    35,    35,    36,    36,    37,    37,    38,    38,
      39,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    56,    55,    57,
      57,    58,    58,    59,    59,    60,    60,    62,    61,    63,
      61,    64,    61,    65,    61,    66,    66,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     4,     4,     5,
       0,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     4,     6,     1,     1,     1,     0,     5,     3,
       2,     1,     2,     1,     2,     1,     2,     0,     5,     0,
       4,     0,     5,     0,     4,     1,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 105 "Final.y" /* yacc.c:1646  */
    {}
#line 1358 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 106 "Final.y" /* yacc.c:1646  */
    {}
#line 1364 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 109 "Final.y" /* yacc.c:1646  */
    {sprintf(code, "%s%s;\n ", code, (yyvsp[0].word));}
#line 1370 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 110 "Final.y" /* yacc.c:1646  */
    {sprintf(code, "%s%s;\n", code, buffer); memset(buffer, 0, strlen(buffer));}
#line 1376 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 111 "Final.y" /* yacc.c:1646  */
    {sprintf(code, "%s%s;\n", code, (yyvsp[0].word));}
#line 1382 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 114 "Final.y" /* yacc.c:1646  */
    {sprintf(buffer, "cout << %s << endl", (yyvsp[-1].word));}
#line 1388 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 115 "Final.y" /* yacc.c:1646  */
    {sprintf(buffer, "printBool(%s)", (yyvsp[-1].word));}
#line 1394 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 117 "Final.y" /* yacc.c:1646  */
    {creatVarible((yyvsp[-2].word), (yyvsp[-1].word)); sprintf((yyval.word), "int %s = %s", (yyvsp[-2].word), (yyvsp[-1].word));}
#line 1400 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 118 "Final.y" /* yacc.c:1646  */
    {creatFunction((yyvsp[0].word));defineFlag = 1;}
#line 1406 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 118 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", buffer);memset(buffer, 0, sizeof(buffer));}
#line 1412 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 120 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1418 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 123 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1424 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 124 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1430 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 125 "Final.y" /* yacc.c:1646  */
    {checkRedefined((yyvsp[0].word)); sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1436 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 126 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1442 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 127 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1448 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 128 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1454 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 129 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1460 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 130 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1466 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 133 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1472 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 134 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1478 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 135 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1484 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 136 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1490 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 137 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1496 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 139 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1502 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 140 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1508 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 141 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1514 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 143 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1520 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 144 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1526 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 145 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1532 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 148 "Final.y" /* yacc.c:1646  */
    {char temp[64]; sprintf(temp, "(%s", (yyvsp[0].word)); sprintf((yyval.word), "%s", temp);}
#line 1538 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 149 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s+%s", (yyvsp[-1].word), (yyvsp[0].word));}
#line 1544 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 151 "Final.y" /* yacc.c:1646  */
    {char temp[64]; sprintf(temp, "(%s", (yyvsp[0].word)); sprintf((yyval.word), "%s", temp);}
#line 1550 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 152 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s*%s", (yyvsp[-1].word), (yyvsp[0].word));}
#line 1556 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 154 "Final.y" /* yacc.c:1646  */
    {char temp[64]; sprintf(temp, "(%s", (yyvsp[0].word)); sprintf((yyval.word), "%s", temp);}
#line 1562 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 155 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s&%s", (yyvsp[-1].word), (yyvsp[0].word));}
#line 1568 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 157 "Final.y" /* yacc.c:1646  */
    {char temp[64]; sprintf(temp, "(%s", (yyvsp[0].word)); sprintf((yyval.word), "%s", temp);}
#line 1574 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 158 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s|%s", (yyvsp[-1].word), (yyvsp[0].word));}
#line 1580 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 160 "Final.y" /* yacc.c:1646  */
    {char temp[64]; sprintf(temp, "(%s", (yyvsp[0].word)); sprintf((yyval.word), "%s", temp);}
#line 1586 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 161 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s==%s", (yyvsp[-1].word), (yyvsp[0].word));}
#line 1592 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 164 "Final.y" /* yacc.c:1646  */
    {char temp[64]; sprintf(temp, "%s+%s)", (yyvsp[-2].word), (yyvsp[-1].word)); (yyval.word) = strdup(temp);}
#line 1598 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 166 "Final.y" /* yacc.c:1646  */
    {char temp[64]; sprintf(temp, "(%s-%s)", (yyvsp[-2].word), (yyvsp[-1].word)); (yyval.word) = strdup(temp);}
#line 1604 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 168 "Final.y" /* yacc.c:1646  */
    {char temp[64]; sprintf(temp, "%s*%s)", (yyvsp[-2].word), (yyvsp[-1].word)); (yyval.word) = strdup(temp);}
#line 1610 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 170 "Final.y" /* yacc.c:1646  */
    {char temp[64]; sprintf(temp, "(%s/%s)", (yyvsp[-2].word), (yyvsp[-1].word)); (yyval.word) = strdup(temp);}
#line 1616 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 172 "Final.y" /* yacc.c:1646  */
    {char temp[64]; sprintf(temp, "(%s%%%s)", (yyvsp[-2].word), (yyvsp[-1].word)); (yyval.word) = strdup(temp);}
#line 1622 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 175 "Final.y" /* yacc.c:1646  */
    {char temp[64]; sprintf(temp, "(%s>%s)", (yyvsp[-2].word), (yyvsp[-1].word)); (yyval.word) = strdup(temp);}
#line 1628 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 177 "Final.y" /* yacc.c:1646  */
    {char temp[64]; sprintf(temp, "(%s<%s)", (yyvsp[-2].word), (yyvsp[-1].word)); (yyval.word) = strdup(temp);}
#line 1634 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 179 "Final.y" /* yacc.c:1646  */
    {char temp[64]; sprintf(temp, "%s==%s)", (yyvsp[-2].word), (yyvsp[-1].word)); (yyval.word) = strdup(temp);}
#line 1640 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 182 "Final.y" /* yacc.c:1646  */
    {char temp[64]; sprintf(temp, "%s&%s)", (yyvsp[-2].word), (yyvsp[-1].word)); (yyval.word) = strdup(temp);}
#line 1646 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 184 "Final.y" /* yacc.c:1646  */
    {char temp[64]; sprintf(temp, "%s|%s)", (yyvsp[-2].word), (yyvsp[-1].word)); (yyval.word) = strdup(temp);}
#line 1652 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 186 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "(!%s)", (yyvsp[-1].word));}
#line 1658 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 189 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "(%s ? %s : %s)", (yyvsp[-3].word), (yyvsp[-2].word), (yyvsp[-1].word));}
#line 1664 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 191 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1670 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 193 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1676 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 195 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1682 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 198 "Final.y" /* yacc.c:1646  */
    {if(!defineFlag){char temp[20]; sprintf(temp, "_%c", funCounter); funCounter++; creatFunction(temp);}defineFlag = 0;}
#line 1688 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 198 "Final.y" /* yacc.c:1646  */
    {setFun();}
#line 1694 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 202 "Final.y" /* yacc.c:1646  */
    {addParam((yyvsp[0].word));}
#line 1700 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 203 "Final.y" /* yacc.c:1646  */
    {addParam((yyvsp[0].word));}
#line 1706 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 205 "Final.y" /* yacc.c:1646  */
    {sprintf(buffer, "%s%s;\n", buffer, (yyvsp[0].word));}
#line 1712 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 206 "Final.y" /* yacc.c:1646  */
    {sprintf(buffer, "%s%s;\n ", buffer, (yyvsp[0].word));}
#line 1718 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 208 "Final.y" /* yacc.c:1646  */
    {sprintf(buffer, "%sreturn %s;\n", buffer, (yyvsp[0].word));}
#line 1724 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 209 "Final.y" /* yacc.c:1646  */
    {sprintf(buffer, "%sreturn %s;\n", buffer, (yyvsp[0].word));}
#line 1730 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 211 "Final.y" /* yacc.c:1646  */
    {sprintf(code, "%s%s;\n ", code, buffer); memset(buffer, 0, sizeof(buffer));}
#line 1736 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 211 "Final.y" /* yacc.c:1646  */
    {checkParaNum(); char temp[64]; sprintf(temp, "%s)", (yyvsp[-1].word)); (yyval.word) = strdup(temp); popFun(1);}
#line 1742 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 212 "Final.y" /* yacc.c:1646  */
    {sprintf(code, "%s%s;\n ", code, buffer); memset(buffer, 0, sizeof(buffer));}
#line 1748 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 212 "Final.y" /* yacc.c:1646  */
    {checkParaNum(); char temp[64]; sprintf(temp, "%s()", top->nowFun->name); (yyval.word) = strdup(temp); popFun(1);}
#line 1754 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 213 "Final.y" /* yacc.c:1646  */
    {loadFunction((yyvsp[0].word));}
#line 1760 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 213 "Final.y" /* yacc.c:1646  */
    {checkParaNum(); sprintf((yyval.word), "%s)", (yyvsp[-1].word)); popFun(1);}
#line 1766 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 214 "Final.y" /* yacc.c:1646  */
    {loadFunction((yyvsp[0].word));}
#line 1772 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 214 "Final.y" /* yacc.c:1646  */
    {checkParaNum(); sprintf((yyval.word), "%s()", top->nowFun->name); popFun(1);}
#line 1778 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 216 "Final.y" /* yacc.c:1646  */
    {top->nowFun->paraNum--; char temp[64]; sprintf(temp, "%s", (yyvsp[0].word)); sprintf((yyval.word), "%s(%s", top->nowFun->name, temp);}
#line 1784 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 217 "Final.y" /* yacc.c:1646  */
    {top->nowFun->paraNum--; char temp[64]; sprintf(temp, "%s, %s", (yyvsp[-1].word), (yyvsp[0].word)); (yyval.word) = strdup(temp);}
#line 1790 "Final.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 219 "Final.y" /* yacc.c:1646  */
    {sprintf((yyval.word), "%s", (yyvsp[0].word));}
#line 1796 "Final.tab.c" /* yacc.c:1646  */
    break;


#line 1800 "Final.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 221 "Final.y" /* yacc.c:1906  */

void yyerror(const char* message){
	printf("%s\n", message);
	exit(1);
}

void creatVarible(char* varName, char* varValue){
	struct varible* temp = NULL;
	struct varible* regist = NULL;
	if(top == NULL){
		temp = Begin;
	}
	else{
		temp = top->nowFun->parameter;
	}
	while(temp != NULL){
		if(strcmp(temp->name, varName) == 0){
			printf("varible \'%s\' have been declared", varName);
			yyerror("");
		}
		if(temp->next == NULL){
			regist = temp;
		}
		temp = temp->next;
	}
	
	temp = (struct varible*)malloc(sizeof(struct varible));
	temp->next = NULL;
	sprintf(temp->name, "%s", varName);
	if(top == NULL){
		if(Begin == NULL){
			Begin = temp;
		}
		else{
			regist->next = temp;
		}
	}
	else{
		if(top->nowFun->parameter == NULL){
			top->nowFun->parameter = temp;
		}
		else{
			regist->next = temp;
		}
	}
}

void checkRedefined(char* varName){
	if(top == NULL){
		struct varible* temp = Begin;
		while(temp != NULL){
			printf("%s\n", temp->name);
			if(strcmp(temp->name, varName) == 0){
				return;
			}
			temp = temp->next;
		}

		printf("varible \'%s\' was not defined", varName);
		yyerror("");
	}
	else if(top->nowFun->stage == 0){
		
		struct functionStack* Ftemp = top;
		while(Ftemp != NULL){
			struct varible* temp = Ftemp->nowFun->parameter;
			while(temp != NULL){
				if(strcmp(temp->name, varName) == 0){
					return;
				}
				temp = temp->next;
			}
			Ftemp = Ftemp->previous;
		}

		printf("argument \'%s\' was not defined in this scope", varName);
		yyerror("");
	}
	else if(top->nowFun->stage == 1){
		struct functionStack* Ftemp = top->previous;
		while(Ftemp != NULL){
			struct varible* temp = Ftemp->nowFun->parameter;
			while(temp != NULL){
				if(strcmp(temp->name, varName) == 0){
					return;
				}
				temp = temp->next;
			}
			Ftemp = Ftemp->previous;
		}
		struct varible* temp = Begin;
		while(temp != NULL){
			//printf("%s\n", temp->name);
			if(strcmp(temp->name, varName) == 0){
				return;
			}
			temp = temp->next;
		}

		printf("argument \'%s\' was not defined in this scope", varName);
		yyerror("");
	}
}

void creatFunction(char* funName){
	struct function* temp = Fbegin;
	struct function* regist = NULL;
	while(temp != NULL){
		if(strcmp(temp->name, funName) == 0){
			printf("function \'%s\' has been defined", funName);
			yyerror("");
		}
		if(temp->next == NULL){
			regist = temp;
		}
		temp = temp->next;
	}
	
	temp = (struct function*)malloc(sizeof(struct function));
	temp->next = NULL;
	temp->parameter = NULL;
	temp->paraNum = 0;
	temp->stage = 0;
	sprintf(temp->name, "%s", funName);
	if(Fbegin == NULL){
		Fbegin = temp;
	}
	else{
		regist->next = temp;
	}
	
	pushFun(temp, 0);
}

void loadFunction(char* funName){
	struct function* temp = Fbegin;
	while(temp != NULL){
		/*if(temp->name[strlen(temp->name)-1] == '!'){
			temp->name[strlen(temp->name)-1] = 0;
		}*/
		//printf("%s %zu\n", temp->name, strlen(temp->name));
		if(strcmp(temp->name, funName) == 0){
			pushFun(temp, 1);
			return;
		}
		temp = temp->next;
	}
	
	printf("function \'%s\' was not defined", funName);
	yyerror("");
}

void addParam(char* parName){
	struct varible* temp = top->nowFun->parameter;
	struct varible* regist = NULL;
	while(temp != NULL){
		if(strcmp(temp->name, parName) == 0){
			printf("redefined of \'%s\'", parName);
			yyerror("");
		}
		if(temp->next == NULL){
			regist = temp;
		}
		temp = temp->next;
	}
	
	top->nowFun->paraNum++;
	//printf("%d\n", top->nowFun->paraNum);
	temp = (struct varible*)malloc(sizeof(struct varible));
	temp->next = NULL;
	sprintf(temp->name, "%s", parName);
	if(top->nowFun->parameter == NULL){
		top->nowFun->parameter = temp;
	}
	else{
		regist->next = temp;
	}
}

void setFun(){
	char funDef[128];
	sprintf(funDef, "int %s(", top->nowFun->name);
	struct varible* temp = top->nowFun->parameter;
	if(temp == NULL){
		sprintf(funDef, "%s){\n ", funDef);
	}
	else{
		sprintf(funDef, "%sint %s", funDef, temp->name);
		temp = temp->next;
		while(temp != NULL){
			sprintf(funDef, "%s, int %s", funDef, temp->name);
			temp = temp->next;
		}
		sprintf(funDef, "%s){\n ", funDef);
	}
	sprintf(allFunction, "%s%s%s}\n\n", allFunction, funDef, buffer);
	sprintf(buffer, "%s", funDef);
	buffer[strlen(funDef)-3] = 0;
	top->nowFun->stage = 1;
	if(top->nowFun->name[0] != '_'){
		popFun(0);
	}
}

void checkParaNum(){
	//printf("%d\n", top->nowFun->paraNum);
	if(top->nowFun->paraNum < 0){
		printf("too many arguments to function");
		yyerror("");
	}
	if(top->nowFun->paraNum > 0){
		printf("too few arguments to function");
		yyerror("");
	}
	
	struct varible* temp = top->nowFun->parameter;
	while(temp != NULL){
		top->nowFun->paraNum++;
		temp = temp->next;
	}
}

void pushFun(struct function* fun, int sta){
	struct functionStack* temp = (struct functionStack*)malloc(sizeof(struct functionStack));
	if(sta == 0){
		temp->nowFun = fun;
	}
	else{
		temp->nowFun = (struct function*)malloc(sizeof(struct function));
		temp->nowFun->paraNum = fun->paraNum;
		temp->nowFun->parameter = fun->parameter;
		temp->nowFun->stage = 1;
		sprintf(temp->nowFun->name, "%s", fun->name);
		temp->nowFun->next = NULL;
	}
	
	temp->previous = top;
	top = temp;
	//printf("%d\n", sta);
	//printf("%d\n", top->nowFun->paraNum);
	//printf("%s %d push\n", top->nowFun->name, sta);
}

void popFun(int sta){
	//printf("%s %d pop\n", top->nowFun->name, sta);
	struct functionStack* temp = top;
	/*if(sta == 1){
		free(temp->nowFun);
	}*/
	top = top->previous;
	free(temp);
}

int main(int argc, char* argv[]){
	sprintf(code, "#include<iostream>\n\nusing namespace std;\nvoid printBool(int b);\n\nint main(){\n ");
	sprintf(allFunction, "void printBool(int b){\n if(b == 1){\n  cout << \"#t\" << endl;\n }else if(b == 0){\n  cout << \"#f\" << endl;\n }else{\n  cout << \"type error\" << endl;\n }\n}\n\n");
	yyparse();
	sprintf(code, "%s\n return 0;\n}", code);
	FILE* Fout;
	Fout = fopen("out.cpp", "w+t");
	//printf("%s\n\n%s\n", code, allFunction);
	fprintf(Fout, "%s\n\n%s\n", code, allFunction);
	fclose(Fout);
	return(0);
}
