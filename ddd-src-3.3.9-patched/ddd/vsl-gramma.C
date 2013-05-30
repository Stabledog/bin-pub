// This file was modified for -*- C++ -*-
// using $RCSfile$ $Revision$
extern void vslerror(const char *s);
extern int vsllex();

/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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

/* All symbols defined below should begin with vsl or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
#line 4 "./vsl-gramma.Y"


// Copyright (C) 1995 Technische Universitaet Braunschweig, Germany.
// Copyright (C) 2001 Universitaet des Saarlandes, Germany.
// Written by Andreas Zeller <zeller@gnu.org>.
// 
// This file is part of DDD.
// 
// DDD is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
// 
// DDD is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public
// License along with DDD -- see the file COPYING.
// If not, write to the Free Software Foundation, Inc.,
// 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
// 
// DDD is the data display debugger.
// For details, see the DDD World-Wide-Web page, 
// `http://www.gnu.org/software/ddd/',
// or send a mail to the DDD developers <ddd@gnu.org>.


// Some declarations and utilities

char VSL_yacc_rcsid[] = 
    "$Id$";


// Function calls

// Return appropriate node for function call
VSLNode *VSLLib::_call(const string& func_name, VSLNode *arg)
{
    // Find definition list
    VSLDefList* def = deflist(func_name);
    if (def == 0)
    {
	VSLLib::parse_error("'" + func_name + "(...)' undefined");
	delete arg;
	arg = 0;
    }

    // Return calling node
    if (def && arg)
	return new DefCallNode(def, arg);

    return 0;
}

VSLNode *VSLLib::call(const string& name)
{
    return _call(name, new EmptyListNode);
}

VSLNode *VSLLib::call(const string& name, VSLNode *arg)
{
    if (arg)
	return _call(name, new FixListNode(arg));

    return 0;
}

VSLNode *VSLLib::call(const string& name, VSLNode *arg1, VSLNode *arg2)
{
    if (arg1 && arg2)
	return _call(name, new FixListNode(arg1, arg2));

    return 0;
}

VSLNode *VSLLib::call(const string& name, 
		      VSLNode *arg1, VSLNode *arg2, VSLNode *arg3)
{
    if (arg1 && arg2 && arg3)
	return _call(name, new FixListNode(arg1, arg2, arg3));

    return 0;
}

// Some settings
#define YYERROR_VERBOSE

#ifdef YYERROR_VERBOSE
#define YYDEBUG 1
#endif


/* Line 268 of yacc.c  */
#line 166 "y.tab.c"

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
   enum vsltokentype {
     IDENTIFIER = 258,
     VSL_STRING = 259,
     INTEGER = 260,
     ARROW = 261,
     IF = 262,
     THEN = 263,
     ELSE = 264,
     ELSIF = 265,
     FI = 266,
     OR = 267,
     AND = 268,
     NOT = 269,
     LET = 270,
     IN = 271,
     WHERE = 272,
     OVERRIDE = 273,
     REPLACE = 274,
     EQ = 275,
     NE = 276,
     GT = 277,
     GE = 278,
     LT = 279,
     LE = 280,
     HALIGN = 281,
     VALIGN = 282,
     UALIGN = 283,
     TALIGN = 284,
     APPEND = 285,
     CONS = 286,
     THREEDOTS = 287
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define VSL_STRING 259
#define INTEGER 260
#define ARROW 261
#define IF 262
#define THEN 263
#define ELSE 264
#define ELSIF 265
#define FI 266
#define OR 267
#define AND 268
#define NOT 269
#define LET 270
#define IN 271
#define WHERE 272
#define OVERRIDE 273
#define REPLACE 274
#define EQ 275
#define NE 276
#define GT 277
#define GE 278
#define LT 279
#define LE 280
#define HALIGN 281
#define VALIGN 282
#define UALIGN 283
#define TALIGN 284
#define APPEND 285
#define CONS 286
#define THREEDOTS 287




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef struct _YYSTYPE 
{

/* Line 293 of yacc.c  */
#line 145 "./vsl-gramma.Y"

    // Our special yacctoC program makes this a struct -- 
    // thus we use an anonymous union (does not harm in other cases)
    union {
	VSLNode *node;
	string *str;
	int num;
	double fnum;
	VSLFunctionHeader function_header;
	VSLVarDefinition  var_definition;
    };



/* Line 293 of yacc.c  */
#line 281 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define vslstype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 293 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 vsltype_uint8;
#else
typedef unsigned char vsltype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 vsltype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char vsltype_int8;
#else
typedef short int vsltype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 vsltype_uint16;
#else
typedef unsigned short int vsltype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 vsltype_int16;
#else
typedef short int vsltype_int16;
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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int vsli)
#else
static int
YYID (vsli)
    int vsli;
#endif
{
  return vsli;
}
#endif

#if ! defined vsloverflow || YYERROR_VERBOSE

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
#    include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void delete [] void *; /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined vsloverflow || YYERROR_VERBOSE */


#if (! defined vsloverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union vslalloc
{
  vsltype_int16 vslss_alloc;
  YYSTYPE vslvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union vslalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (vsltype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T vslnewbytes;						\
	YYCOPY (&vslptr->Stack_alloc, Stack, vslsize);			\
	Stack = &vslptr->Stack_alloc;					\
	vslnewbytes = vslstacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	vslptr += vslnewbytes / sizeof (*vslptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
	  YYSIZE_T vsli;				\
	  for (vsli = 0; vsli < (Count); vsli++)	\
	    (To)[vsli] = (From)[vsli];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   575

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  189

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? vsltranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const vsltype_uint8 vsltranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    37,     2,     2,
      39,    40,    35,    33,    41,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const vsltype_uint16 vslprhs[] =
{
       0,     0,     3,     5,     6,     9,    12,    15,    17,    19,
      21,    24,    26,    29,    31,    33,    37,    41,    45,    49,
      53,    57,    61,    65,    69,    73,    77,    81,    85,    89,
      93,    97,   101,   103,   105,   107,   110,   113,   116,   119,
     121,   123,   127,   130,   134,   136,   138,   142,   146,   150,
     154,   156,   158,   160,   162,   164,   166,   168,   171,   175,
     178,   182,   184,   186,   190,   194,   197,   199,   201,   203,
     205,   208,   210,   213,   216,   219,   222,   226,   230,   234,
     238,   242,   246,   250,   254,   258,   262,   266,   270,   274,
     278,   282,   286,   290,   294,   301,   307,   310,   312,   316,
     318,   321,   323,   327,   329,   332,   334,   338
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const vsltype_int8 vslrhs[] =
{
      45,     0,    -1,    46,    -1,    -1,    46,    47,    -1,    48,
      38,    -1,    52,    38,    -1,    77,    -1,    80,    -1,    38,
      -1,     1,    38,    -1,    49,    -1,    50,    75,    -1,    50,
      -1,    51,    -1,    39,    20,    40,    -1,    39,    21,    40,
      -1,    39,    22,    40,    -1,    39,    23,    40,    -1,    39,
      24,    40,    -1,    39,    25,    40,    -1,    39,    26,    40,
      -1,    39,    27,    40,    -1,    39,    28,    40,    -1,    39,
      29,    40,    -1,    39,    33,    40,    -1,    39,    34,    40,
      -1,    39,    35,    40,    -1,    39,    36,    40,    -1,    39,
      37,    40,    -1,    39,    31,    40,    -1,    39,    14,    40,
      -1,     3,    -1,    53,    -1,    55,    -1,    54,    57,    -1,
      49,    20,    -1,    56,    57,    -1,    49,     6,    -1,    58,
      -1,    60,    -1,    15,    62,    59,    -1,    16,    58,    -1,
      41,    62,    59,    -1,    63,    -1,    61,    -1,    60,    17,
      62,    -1,    61,    41,    62,    -1,    63,    20,    63,    -1,
      39,    58,    40,    -1,    64,    -1,    67,    -1,    72,    -1,
      71,    -1,    73,    -1,    70,    -1,    76,    -1,    42,    43,
      -1,    42,    65,    43,    -1,    39,    40,    -1,    39,    66,
      40,    -1,    58,    -1,    66,    -1,    63,    30,    63,    -1,
      63,    41,    65,    -1,    63,    32,    -1,    32,    -1,    68,
      -1,    69,    -1,     4,    -1,    68,     4,    -1,     5,    -1,
      50,    75,    -1,    14,    63,    -1,    33,    63,    -1,    34,
      63,    -1,    63,    20,    63,    -1,    63,    21,    63,    -1,
      63,    22,    63,    -1,    63,    23,    63,    -1,    63,    24,
      63,    -1,    63,    25,    63,    -1,    63,    26,    63,    -1,
      63,    27,    63,    -1,    63,    28,    63,    -1,    63,    29,
      63,    -1,    63,    33,    63,    -1,    63,    34,    63,    -1,
      63,    35,    63,    -1,    63,    36,    63,    -1,    63,    37,
      63,    -1,    63,    31,    63,    -1,    63,    12,    63,    -1,
      63,    13,    63,    -1,     7,    63,     8,    58,    74,    11,
      -1,    10,    63,     8,    58,    74,    -1,     9,    58,    -1,
      64,    -1,    39,    58,    40,    -1,    51,    -1,    18,    78,
      -1,    79,    -1,    78,    41,    79,    -1,    50,    -1,    19,
      81,    -1,    82,    -1,    81,    41,    82,    -1,    50,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const vsltype_uint16 vslrline[] =
{
       0,   175,   175,   177,   178,   180,   181,   182,   183,   184,
     185,   190,   207,   217,   230,   232,   234,   236,   238,   240,
     242,   244,   246,   248,   250,   252,   254,   256,   258,   260,
     262,   264,   267,   270,   271,   273,   293,   312,   330,   345,
     354,   358,   372,   376,   391,   393,   396,   410,   426,   438,
     440,   442,   444,   446,   448,   450,   452,   455,   460,   465,
     470,   476,   483,   488,   496,   504,   508,   514,   525,   531,
     536,   546,   551,   564,   570,   574,   587,   594,   601,   608,
     615,   622,   629,   636,   643,   650,   657,   664,   671,   678,
     685,   692,   699,   709,   720,   734,   746,   751,   755,   763,
     790,   792,   793,   795,   806,   808,   809,   811
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const vsltname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "VSL_STRING", "INTEGER",
  "ARROW", "IF", "THEN", "ELSE", "ELSIF", "FI", "OR", "AND", "NOT", "LET",
  "IN", "WHERE", "OVERRIDE", "REPLACE", "EQ", "NE", "GT", "GE", "LT", "LE",
  "HALIGN", "VALIGN", "UALIGN", "TALIGN", "APPEND", "CONS", "THREEDOTS",
  "'+'", "'-'", "'*'", "'/'", "'%'", "';'", "'('", "')'", "','", "'['",
  "']'", "$accept", "file", "item_list", "item", "function_declaration",
  "function_header", "function_identifier", "identifier",
  "function_definition", "local_definition", "local_header",
  "global_definition", "global_header", "function_body",
  "box_expression_with_defs", "in_box_expression",
  "box_expression_with_wheres", "box_expression_with_where",
  "var_definition", "box_expression", "list_expression",
  "box_expression_list", "multiple_box_expression_list",
  "const_expression", "string_constant", "numeric_constant",
  "function_call", "unary_expression", "binary_expression",
  "cond_expression", "else_expression", "function_argument",
  "argument_or_function", "override_declaration", "override_list",
  "override_identifier", "replace_declaration", "replace_list",
  "replace_identifier", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const vsltype_uint16 vsltoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    43,    45,    42,    47,    37,    59,    40,
      41,    44,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const vsltype_uint8 vslr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      47,    48,    49,    49,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    51,    52,    52,    53,    54,    55,    56,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    64,    64,    64,
      64,    65,    65,    66,    66,    66,    66,    67,    67,    68,
      68,    69,    70,    71,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    73,    74,    74,    75,    75,    76,
      77,    78,    78,    79,    80,    81,    81,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const vsltype_uint8 vslr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     1,     1,     1,
       2,     1,     2,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     3,     2,     3,     1,     1,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     2,
       3,     1,     1,     3,     3,     2,     1,     1,     1,     1,
       2,     1,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     6,     5,     2,     1,     3,     1,
       2,     1,     3,     1,     2,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const vsltype_uint8 vsldefact[] =
{
       3,     0,     0,     1,     0,    32,     0,     0,     9,     0,
       4,     0,    11,    13,    14,     0,    33,     0,    34,     0,
       7,     8,    10,   103,   100,   101,   107,   104,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,    38,    36,     0,
       0,    97,    12,     6,    69,    71,     0,     0,     0,     0,
       0,     0,     0,    99,    35,    39,    40,    45,    44,    50,
      51,    67,    68,    55,    53,    52,    54,    56,    37,     0,
       0,    31,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    30,    25,    26,    27,    28,    29,    66,    59,
       0,    44,     0,    57,    61,     0,    62,     0,    73,     0,
       0,    74,    75,     0,     0,     0,     0,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,   102,
     106,    98,     0,    65,     0,    60,    58,     0,     0,     0,
      41,     0,    49,    46,    47,    92,    93,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    91,    86,    87,
      88,    89,    90,    63,    64,     0,    42,     0,    48,     0,
       0,     0,    43,    96,     0,    94,     0,     0,    95
};

/* YYDEFGOTO[NTERM-NUM].  */
static const vsltype_int16 vsldefgoto[] =
{
      -1,     1,     2,    10,    11,    12,    62,    63,    15,    16,
      17,    18,    19,    64,    65,   150,    66,    67,   109,    68,
      69,   105,   102,    70,    71,    72,    73,    74,    75,    76,
     181,    52,    77,    20,    24,    25,    21,    27,    28
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -93
static const vsltype_int16 vslpact[] =
{
     -93,     6,    16,   -93,   -27,   -93,    22,    22,   -93,   498,
     -93,   -15,     8,   -24,   -93,    -5,   -93,   223,   -93,   223,
     -93,   -93,   -93,   -93,    -1,   -93,   -93,    11,   -93,    18,
      32,    34,    52,    53,    57,    63,    64,    85,    86,    87,
      88,    92,    93,    94,    95,   103,   -93,   -93,   -93,   177,
      17,   -93,   -93,   -93,   -93,   -93,   300,   300,   300,   300,
     300,   137,   -24,     0,   -93,   -93,    24,   104,   409,   -93,
     -93,    90,   -93,   -93,   -93,   -93,   -93,   -93,   -93,    22,
      22,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     114,   323,   115,   -93,   -93,   110,   -93,   353,   -93,    -3,
     435,    54,    54,   236,   276,   288,   116,   -93,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   -93,   -93,
     -93,   -93,   300,   -93,   190,   -93,   -93,   223,   223,   300,
     -93,   300,   -93,   -93,   -93,   480,    42,   514,   514,   218,
     218,   218,   218,    51,   526,   538,   113,   218,    54,    54,
     -93,   -93,   -93,   409,   -93,    20,   -93,    -3,   461,   223,
     300,   164,   -93,   -93,   383,   -93,   223,    20,   -93
};

/* YYPGOTO[NTERM-NUM].  */
static const vsltype_int16 vslpgoto[] =
{
     -93,   -93,   -93,   -93,   -93,   -93,     1,     3,   -93,   -93,
     -93,   -93,   -93,   159,   -49,     9,   -93,   -93,   -92,   -13,
      -9,    39,   -48,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
      -2,   125,   -93,   -93,   -93,   109,   -93,   -93,   118
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -77
static const vsltype_int16 vsltable[] =
{
     100,   104,   106,    13,    51,    14,     3,    23,    26,    14,
      14,    22,   116,   148,    47,    49,    -2,     4,    50,     5,
       5,    54,    55,    46,    56,     5,   153,   154,    48,   179,
     180,    57,    58,    53,     6,     7,   101,   101,   149,   -14,
      79,   118,   -14,   107,   108,   110,   111,   112,   101,    98,
      59,    60,    80,    51,     8,     9,    61,   177,    81,    50,
     103,     9,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    82,   132,    83,   133,   134,   135,   136,   137,
      23,    26,    14,    14,   133,   134,   135,   136,   137,   135,
     136,   137,    84,    85,   138,   104,   106,    86,   175,   176,
     108,   111,   112,    87,    88,   110,   110,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    89,    90,    91,    92,   173,
     183,   101,    93,    94,    95,    96,   110,   187,   178,   128,
       5,    54,    55,    97,    56,   119,   133,   134,   135,   136,
     137,   113,    58,   146,   141,   145,   152,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,   184,    40,    98,
     114,   115,    43,    44,    45,   185,    61,    99,    78,    50,
       5,    54,    55,   174,    56,   188,   182,   117,   139,     0,
       0,    57,    58,     5,    54,    55,     0,    56,   140,     0,
       0,     0,     0,     0,    57,    58,     0,     0,     0,    98,
      59,    60,     0,     0,     0,     0,    61,    99,     0,    50,
       0,     0,    98,    59,    60,     0,     5,    54,    55,    61,
      56,     0,    50,     0,     0,     0,     0,    57,    58,     5,
      54,    55,     0,    56,   128,   129,   130,   131,     0,   132,
      57,   133,   134,   135,   136,   137,    59,    60,     0,     0,
       0,     0,    61,     0,     0,    50,     0,     0,     0,    59,
      60,     0,     0,     0,     0,    61,    81,     0,    50,     5,
      54,    55,     0,    56,     0,     0,     0,     0,     0,     0,
      57,     5,    54,    55,     0,    56,     0,     0,     0,     0,
       0,     0,    57,     5,    54,    55,     0,    56,     0,    59,
      60,     0,     0,     0,    57,    61,    93,     0,    50,     0,
       0,    59,    60,     0,     0,     0,     0,    61,    94,     0,
      50,     0,     0,    59,    60,   120,   121,     0,     0,    61,
       0,     0,    50,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   142,   132,   143,   133,   134,   135,   136,
     137,   147,     0,     0,   144,   120,   121,     0,     0,     0,
       0,     0,     0,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,     0,   132,     0,   133,   134,   135,   136,
     137,   186,     0,     0,     0,   120,   121,     0,     0,     0,
       0,     0,     0,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,     0,   132,     0,   133,   134,   135,   136,
     137,   120,   121,     0,     0,     0,     0,     0,     0,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
     132,     0,   133,   134,   135,   136,   137,   120,   121,     0,
       0,     0,     0,     0,     0,   151,   123,   124,   125,   126,
     127,   128,   129,   130,   131,     0,   132,     0,   133,   134,
     135,   136,   137,   -76,   -76,     0,     0,     0,     0,     0,
       0,   -76,   -76,   124,   125,   126,   127,   128,   129,   130,
     131,     0,   132,   121,   133,   134,   135,   136,   137,     0,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
       0,   132,    29,   133,   134,   135,   136,   137,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     0,    40,
       0,    41,    42,    43,    44,    45,   124,   125,   126,   127,
     128,   129,   130,   131,     0,   132,     0,   133,   134,   135,
     136,   137,   128,     0,   130,   131,     0,     0,     0,   133,
     134,   135,   136,   137,   128,     0,     0,   131,     0,     0,
       0,   133,   134,   135,   136,   137
};

#define vslpact_value_is_default(vslstate) \
  ((vslstate) == (-93))

#define vsltable_value_is_error(vsltable_value) \
  YYID (0)

static const vsltype_int16 vslcheck[] =
{
      49,    50,    50,     2,    13,     2,     0,     6,     7,     6,
       7,    38,    61,    16,     6,    39,     0,     1,    42,     3,
       3,     4,     5,    38,     7,     3,   118,   119,    20,     9,
      10,    14,    15,    38,    18,    19,    49,    50,    41,    39,
      41,    17,    42,    56,    57,    58,    59,    60,    61,    32,
      33,    34,    41,    62,    38,    39,    39,   149,    40,    42,
      43,    39,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    40,    31,    40,    33,    34,    35,    36,    37,
      79,    80,    79,    80,    33,    34,    35,    36,    37,    35,
      36,    37,    40,    40,     4,   144,   144,    40,   147,   148,
     113,   114,   115,    40,    40,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,    40,    40,    40,    40,   142,
     179,   144,    40,    40,    40,    40,   149,   186,   151,    26,
       3,     4,     5,    40,     7,    41,    33,    34,    35,    36,
      37,    14,    15,    43,    40,    40,    40,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,   180,    31,    32,
      33,    34,    35,    36,    37,    11,    39,    40,    19,    42,
       3,     4,     5,   144,     7,   187,   177,    62,    79,    -1,
      -1,    14,    15,     3,     4,     5,    -1,     7,    80,    -1,
      -1,    -1,    -1,    -1,    14,    15,    -1,    -1,    -1,    32,
      33,    34,    -1,    -1,    -1,    -1,    39,    40,    -1,    42,
      -1,    -1,    32,    33,    34,    -1,     3,     4,     5,    39,
       7,    -1,    42,    -1,    -1,    -1,    -1,    14,    15,     3,
       4,     5,    -1,     7,    26,    27,    28,    29,    -1,    31,
      14,    33,    34,    35,    36,    37,    33,    34,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    33,
      34,    -1,    -1,    -1,    -1,    39,    40,    -1,    42,     3,
       4,     5,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      14,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    14,     3,     4,     5,    -1,     7,    -1,    33,
      34,    -1,    -1,    -1,    14,    39,    40,    -1,    42,    -1,
      -1,    33,    34,    -1,    -1,    -1,    -1,    39,    40,    -1,
      42,    -1,    -1,    33,    34,    12,    13,    -1,    -1,    39,
      -1,    -1,    42,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,     8,    -1,    -1,    41,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    -1,    33,    34,    35,    36,
      37,     8,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    -1,    33,    34,    35,    36,
      37,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    -1,    33,    34,    35,    36,    37,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    -1,    33,    34,
      35,    36,    37,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    13,    33,    34,    35,    36,    37,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    14,    33,    34,    35,    36,    37,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      -1,    33,    34,    35,    36,    37,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    -1,    33,    34,    35,
      36,    37,    26,    -1,    28,    29,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    26,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const vsltype_uint8 vslstos[] =
{
       0,    45,    46,     0,     1,     3,    18,    19,    38,    39,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      77,    80,    38,    50,    78,    79,    50,    81,    82,    14,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      31,    33,    34,    35,    36,    37,    38,     6,    20,    39,
      42,    64,    75,    38,     4,     5,     7,    14,    15,    33,
      34,    39,    50,    51,    57,    58,    60,    61,    63,    64,
      67,    68,    69,    70,    71,    72,    73,    76,    57,    41,
      41,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    32,    40,
      58,    63,    66,    43,    58,    65,    66,    63,    63,    62,
      63,    63,    63,    14,    33,    34,    58,    75,    17,    41,
      12,    13,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    31,    33,    34,    35,    36,    37,     4,    79,
      82,    40,    30,    32,    41,    40,    43,     8,    16,    41,
      59,    20,    40,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    65,    58,    58,    62,    63,     9,
      10,    74,    59,    58,    63,    11,     8,    58,    74
};

#define vslerrok		(vslerrstatus = 0)
#define vslclearin	(vslchar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto vslacceptlab
#define YYABORT		goto vslabortlab
#define YYERROR		goto vslerrorlab


/* Like YYERROR except do call vslerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto vslerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!vslerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (vslchar == YYEMPTY && vsllen == 1)				\
    {								\
      vslchar = (Token);						\
      vsllval = (Value);						\
      YYPOPSTACK (1);						\
      goto vslbackup;						\
    }								\
  else								\
    {								\
      vslerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256

// This deletes the "kill" array upon destruction.
// Will be used as automatic variable in vslparse().
// Added by $RCSfile$
struct YYMEMHANDLER {
    YYSTYPE *kill;

    YYMEMHANDLER()
	: kill(0)
    {}

    ~YYMEMHANDLER()
    {
	if (kill != 0)
    	    delete[] kill;
        kill = 0;
    }

private:
    YYMEMHANDLER(const YYMEMHANDLER&);
    YYMEMHANDLER& operator=(const YYMEMHANDLER&);
};



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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `vsllex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX vsllex (YYLEX_PARAM)
#else
# define YYLEX vsllex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (vsldebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (vsldebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      vsl_symbol_print (stderr,						  \
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
vsl_symbol_value_print (FILE *vsloutput, int vsltype, YYSTYPE const * const vslvaluep)
#else
static void
vsl_symbol_value_print (vsloutput, vsltype, vslvaluep)
    FILE *vsloutput;
    int vsltype;
    YYSTYPE const * const vslvaluep;
#endif
{
  if (!vslvaluep)
    return;
# ifdef YYPRINT
  if (vsltype < YYNTOKENS)
    YYPRINT (vsloutput, vsltoknum[vsltype], *vslvaluep);
# else
  YYUSE (vsloutput);
# endif
  switch (vsltype)
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
vsl_symbol_print (FILE *vsloutput, int vsltype, YYSTYPE const * const vslvaluep)
#else
static void
vsl_symbol_print (vsloutput, vsltype, vslvaluep)
    FILE *vsloutput;
    int vsltype;
    YYSTYPE const * const vslvaluep;
#endif
{
  if (vsltype < YYNTOKENS)
    YYFPRINTF (vsloutput, "token %s (", vsltname[vsltype]);
  else
    YYFPRINTF (vsloutput, "nterm %s (", vsltname[vsltype]);

  vsl_symbol_value_print (vsloutput, vsltype, vslvaluep);
  YYFPRINTF (vsloutput, ")");
}

/*------------------------------------------------------------------.
| vsl_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
vsl_stack_print (vsltype_int16 *vslbottom, vsltype_int16 *vsltop)
#else
static void
vsl_stack_print (vslbottom, vsltop)
    vsltype_int16 *vslbottom;
    vsltype_int16 *vsltop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; vslbottom <= vsltop; vslbottom++)
    {
      int vslbot = *vslbottom;
      YYFPRINTF (stderr, " %d", vslbot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (vsldebug)							\
    vsl_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
vsl_reduce_print (YYSTYPE *vslvsp, int vslrule)
#else
static void
vsl_reduce_print (vslvsp, vslrule)
    YYSTYPE *vslvsp;
    int vslrule;
#endif
{
  int vslnrhs = vslr2[vslrule];
  int vsli;
  unsigned long int vsllno = vslrline[vslrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     vslrule - 1, vsllno);
  /* The symbols being reduced.  */
  for (vsli = 0; vsli < vslnrhs; vsli++)
    {
      YYFPRINTF (stderr, "   $%d = ", vsli + 1);
      vsl_symbol_print (stderr, vslrhs[vslprhs[vslrule] + vsli],
		       &(vslvsp[(vsli + 1) - (vslnrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (vsldebug)				\
    vsl_reduce_print (vslvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int vsldebug;
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

# ifndef vslstrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define vslstrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
vslstrlen (const char *vslstr)
#else
static YYSIZE_T
vslstrlen (vslstr)
    const char *vslstr;
#endif
{
  YYSIZE_T vsllen;
  for (vsllen = 0; vslstr[vsllen]; vsllen++)
    continue;
  return vsllen;
}
#  endif
# endif

# ifndef vslstpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define vslstpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
vslstpcpy (char *vsldest, const char *vslsrc)
#else
static char *
vslstpcpy (vsldest, vslsrc)
    char *vsldest;
    const char *vslsrc;
#endif
{
  char *vsld = vsldest;
  const char *vsls = vslsrc;

  while ((*vsld++ = *vsls++) != '\0')
    continue;

  return vsld - 1;
}
#  endif
# endif

# ifndef vsltnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for vslerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from vsltname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
vsltnamerr (char *vslres, const char *vslstr)
{
  if (*vslstr == '"')
    {
      YYSIZE_T vsln = 0;
      char const *vslp = vslstr;

      for (;;)
	switch (*++vslp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++vslp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (vslres)
	      vslres[vsln] = *vslp;
	    vsln++;
	    break;

	  case '"':
	    if (vslres)
	      vslres[vsln] = '\0';
	    return vsln;
	  }
    do_not_strip_quotes: ;
    }

  if (! vslres)
    return vslstrlen (vslstr);

  return vslstpcpy (vslres, vslstr) - vslres;
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
vslsyntax_error (YYSIZE_T *vslmsg_alloc, char **vslmsg,
                vsltype_int16 *vslssp, int vsltoken)
{
  YYSIZE_T vslsize0 = vsltnamerr (0, vsltname[vsltoken]);
  YYSIZE_T vslsize = vslsize0;
  YYSIZE_T vslsize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *vslformat = 0;
  /* Arguments of vslformat. */
  char const *vslarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int vslcount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in vslchar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated vslchar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (vsltoken != YYEMPTY)
    {
      int vsln = vslpact[*vslssp];
      vslarg[vslcount++] = vsltname[vsltoken];
      if (!vslpact_value_is_default (vsln))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int vslxbegin = vsln < 0 ? -vsln : 0;
          /* Stay within bounds of both vslcheck and vsltname.  */
          int vslchecklim = YYLAST - vsln + 1;
          int vslxend = vslchecklim < YYNTOKENS ? vslchecklim : YYNTOKENS;
          int vslx;

          for (vslx = vslxbegin; vslx < vslxend; ++vslx)
            if (vslcheck[vslx + vsln] == vslx && vslx != YYTERROR
                && !vsltable_value_is_error (vsltable[vslx + vsln]))
              {
                if (vslcount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    vslcount = 1;
                    vslsize = vslsize0;
                    break;
                  }
                vslarg[vslcount++] = vsltname[vslx];
                vslsize1 = vslsize + vsltnamerr (0, vsltname[vslx]);
                if (! (vslsize <= vslsize1
                       && vslsize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                vslsize = vslsize1;
              }
        }
    }

  switch (vslcount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        vslformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  vslsize1 = vslsize + vslstrlen (vslformat);
  if (! (vslsize <= vslsize1 && vslsize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  vslsize = vslsize1;

  if (*vslmsg_alloc < vslsize)
    {
      *vslmsg_alloc = 2 * vslsize;
      if (! (vslsize <= *vslmsg_alloc
             && *vslmsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *vslmsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *vslp = *vslmsg;
    int vsli = 0;
    while ((*vslp = *vslformat) != '\0')
      if (*vslp == '%' && vslformat[1] == 's' && vsli < vslcount)
        {
          vslp += vsltnamerr (vslp, vslarg[vsli++]);
          vslformat += 2;
        }
      else
        {
          vslp++;
          vslformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
vsldestruct (const char *vslmsg, int vsltype, YYSTYPE *vslvaluep)
#else
static void
vsldestruct (vslmsg, vsltype, vslvaluep)
    const char *vslmsg;
    int vsltype;
    YYSTYPE *vslvaluep;
#endif
{
  YYUSE (vslvaluep);

  if (!vslmsg)
    vslmsg = "Deleting";
  YY_SYMBOL_PRINT (vslmsg, vsltype, vslvaluep, vsllocationp);

  switch (vsltype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int vslparse (void *YYPARSE_PARAM);
#else
int vslparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int vslparse (void);
#else
int vslparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int vslchar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE vsllval;

/* Number of syntax errors so far.  */
int vslnerrs;


/*----------.
| vslparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
vslparse (void *YYPARSE_PARAM)
#else
int
vslparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
vslparse (void)
#else
int
vslparse ()

#endif
#endif
{
    int vslstate;
    /* Number of tokens to shift before error messages enabled.  */
    int vslerrstatus;

    /* The stacks and their tools:
       `vslss': related to states.
       `vslvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow vsloverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    vsltype_int16 vslssa[YYINITDEPTH];
    vsltype_int16 *vslss;
    vsltype_int16 *vslssp;

    /* The semantic value stack.  */
    YYSTYPE vslvsa[YYINITDEPTH];
    YYSTYPE *vslvs;
    YYSTYPE *vslvsp;

    YYSIZE_T vslstacksize;

  int vsln;
  int vslresult;
  /* Lookahead token as an internal (translated) token number.  */
  int vsltoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE vslval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char vslmsgbuf[128];
  char *vslmsg = vslmsgbuf;
  YYSIZE_T vslmsg_alloc = sizeof vslmsgbuf;
#endif

#define YYPOPSTACK(N)   (vslvsp -= (N), vslssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int vsllen = 0;

  vsltoken = 0;
  vslss = vslssa;
  vslvs = vslvsa;
  vslstacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  vslstate = 0;
  vslerrstatus = 0;
  vslnerrs = 0;
  vslchar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  vslssp = vslss;
  vslvsp = vslvs;

  goto vslsetstate;

/*------------------------------------------------------------.
| vslnewstate -- Push a new state, which is found in vslstate.  |
`------------------------------------------------------------*/
 vslnewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  vslssp++;

 vslsetstate:
  *vslssp = vslstate;

  if (vslss + vslstacksize - 1 <= vslssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T vslsize = vslssp - vslss + 1;

#ifdef vsloverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *vslvs1 = vslvs;
	vsltype_int16 *vslss1 = vslss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if vsloverflow is a macro.  */
	vsloverflow (YY_("memory exhausted"),
		    &vslss1, vslsize * sizeof (*vslssp),
		    &vslvs1, vslsize * sizeof (*vslvsp),
		    &vslstacksize);

	vslss = vslss1;
	vslvs = vslvs1;
      }
#else /* no vsloverflow */
# ifndef YYSTACK_RELOCATE
      goto vslexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= vslstacksize)
	goto vslexhaustedlab;
      vslstacksize *= 2;
      if (YYMAXDEPTH < vslstacksize)
	vslstacksize = YYMAXDEPTH;

      {
	vsltype_int16 *vslss1 = vslss;
	union vslalloc *vslptr =
	  (union vslalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (vslstacksize));
	if (! vslptr)
	  goto vslexhaustedlab;
	YYSTACK_RELOCATE (vslss_alloc, vslss);
	YYSTACK_RELOCATE (vslvs_alloc, vslvs);
#  undef YYSTACK_RELOCATE
	if (vslss1 != vslssa)
	  YYSTACK_FREE (vslss1);
      }
# endif
#endif /* no vsloverflow */

      vslssp = vslss + vslsize - 1;
      vslvsp = vslvs + vslsize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) vslstacksize));

      if (vslss + vslstacksize - 1 <= vslssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", vslstate));

  if (vslstate == YYFINAL)
    YYACCEPT;

  goto vslbackup;

/*-----------.
| vslbackup.  |
`-----------*/
vslbackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  vsln = vslpact[vslstate];
  if (vslpact_value_is_default (vsln))
    goto vsldefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (vslchar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      vslchar = YYLEX;
    }

  if (vslchar <= YYEOF)
    {
      vslchar = vsltoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      vsltoken = YYTRANSLATE (vslchar);
      YY_SYMBOL_PRINT ("Next token is", vsltoken, &vsllval, &vsllloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  vsln += vsltoken;
  if (vsln < 0 || YYLAST < vsln || vslcheck[vsln] != vsltoken)
    goto vsldefault;
  vsln = vsltable[vsln];
  if (vsln <= 0)
    {
      if (vsltable_value_is_error (vsln))
        goto vslerrlab;
      vsln = -vsln;
      goto vslreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (vslerrstatus)
    vslerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", vsltoken, &vsllval, &vsllloc);

  /* Discard the shifted token.  */
  vslchar = YYEMPTY;

  vslstate = vsln;
  *++vslvsp = vsllval;

  goto vslnewstate;


/*-----------------------------------------------------------.
| vsldefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
vsldefault:
  vsln = vsldefact[vslstate];
  if (vsln == 0)
    goto vslerrlab;
  goto vslreduce;


/*-----------------------------.
| vslreduce -- Do a reduction.  |
`-----------------------------*/
vslreduce:
  /* vsln is the number of a rule to reduce with.  */
  vsllen = vslr2[vsln];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  vslval = vslvsp[1-vsllen];


  YY_REDUCE_PRINT (vsln);
  switch (vsln)
    {
        case 11:

/* Line 1806 of yacc.c  */
#line 191 "./vsl-gramma.Y"
    {
				    ASSERT((vslvsp[(1) - (1)].function_header).pattern == 0 || 
					   (vslvsp[(1) - (1)].function_header).pattern->OK());

				    if ((vslvsp[(1) - (1)].function_header).pattern)
				    {
					vsllib->add(*(vslvsp[(1) - (1)].function_header).id,
						    (vslvsp[(1) - (1)].function_header).pattern, 0, false,
						    *(vslvsp[(1) - (1)].function_header).file, (vslvsp[(1) - (1)].function_header).line);
				    }
				    delete (vslvsp[(1) - (1)].function_header).id;
				    (vslvsp[(1) - (1)].function_header).id = 0;
				    delete (vslvsp[(1) - (1)].function_header).file;
				    (vslvsp[(1) - (1)].function_header).file = 0;
				}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 208 "./vsl-gramma.Y"
    {
				    ASSERT((vslvsp[(1) - (2)].str)->OK());
				    ASSERT((vslvsp[(2) - (2)].node) == 0 || (vslvsp[(2) - (2)].node)->OK());

				    (vslval.function_header).id      = (vslvsp[(1) - (2)].str);
				    (vslval.function_header).pattern = (vslvsp[(2) - (2)].node);
				    (vslval.function_header).file    = new string(vslfilename);
				    (vslval.function_header).line    = vsllinenumber;
				}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 218 "./vsl-gramma.Y"
    {
				    ASSERT((vslvsp[(1) - (1)].str)->OK());

				    (vslval.function_header).id      = new string("#" + *(vslvsp[(1) - (1)].str));
				    (vslval.function_header).pattern = new EmptyListNode;
				    (vslval.function_header).file    = new string(vslfilename);
				    (vslval.function_header).line    = vsllinenumber;

				    delete (vslvsp[(1) - (1)].str);
				    (vslvsp[(1) - (1)].str) = 0;
				}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 231 "./vsl-gramma.Y"
    { (vslval.str) = (vslvsp[(1) - (1)].str); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 233 "./vsl-gramma.Y"
    { (vslval.str) = new string("(=)"); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 235 "./vsl-gramma.Y"
    { (vslval.str) = new string("(<>)"); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 237 "./vsl-gramma.Y"
    { (vslval.str) = new string("(>)"); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 239 "./vsl-gramma.Y"
    { (vslval.str) = new string("(>=)"); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 241 "./vsl-gramma.Y"
    { (vslval.str) = new string("(<)"); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 243 "./vsl-gramma.Y"
    { (vslval.str) = new string("(<=)"); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 245 "./vsl-gramma.Y"
    { (vslval.str) = new string("(&)"); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 247 "./vsl-gramma.Y"
    { (vslval.str) = new string("(|)"); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 249 "./vsl-gramma.Y"
    { (vslval.str) = new string("(^)"); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 251 "./vsl-gramma.Y"
    { (vslval.str) = new string("(~)"); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 253 "./vsl-gramma.Y"
    { (vslval.str) = new string("(+)"); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 255 "./vsl-gramma.Y"
    { (vslval.str) = new string("(-)"); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 257 "./vsl-gramma.Y"
    { (vslval.str) = new string("(*)"); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 259 "./vsl-gramma.Y"
    { (vslval.str) = new string("(/)"); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 261 "./vsl-gramma.Y"
    { (vslval.str) = new string("(%)"); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 263 "./vsl-gramma.Y"
    { (vslval.str) = new string("(::)"); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 265 "./vsl-gramma.Y"
    { (vslval.str) = new string("(not)"); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 268 "./vsl-gramma.Y"
    { (vslval.str) = new string((const char *)vsltext); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 274 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (2)].function_header).pattern == 0 || 
					   (vslvsp[(1) - (2)].function_header).pattern->OK());
				    ASSERT((vslvsp[(2) - (2)].node) == 0 || (vslvsp[(2) - (2)].node)->OK());

				    if ((vslvsp[(1) - (2)].function_header).pattern)
				    {
					// Define function
					vsllib->add(*(vslvsp[(1) - (2)].function_header).id,
						    (vslvsp[(1) - (2)].function_header).pattern, (vslvsp[(2) - (2)].node), false,
						    *(vslvsp[(1) - (2)].function_header).file, (vslvsp[(1) - (2)].function_header).line);
				    }

				    delete (vslvsp[(1) - (2)].function_header).id;
				    (vslvsp[(1) - (2)].function_header).id = 0;
				    delete (vslvsp[(1) - (2)].function_header).file;
				    (vslvsp[(1) - (2)].function_header).file = 0;
				}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 294 "./vsl-gramma.Y"
    {
				    ASSERT((vslvsp[(1) - (2)].function_header).pattern == 0 || 
					   (vslvsp[(1) - (2)].function_header).pattern->OK());

				    if ((vslvsp[(1) - (2)].function_header).pattern)
				    {
					// Declare function now
					// (for recursive calls)
					vsllib->add(*(vslvsp[(1) - (2)].function_header).id,
						    (vslvsp[(1) - (2)].function_header).pattern->dup(), 0, 
						    false,
						    vslfilename, 
						    vsllinenumber);
				    }

				    (vslval.function_header) = (vslvsp[(1) - (2)].function_header);
				}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 313 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (2)].function_header).pattern == 0 || 
					   (vslvsp[(1) - (2)].function_header).pattern->OK());
				    ASSERT((vslvsp[(2) - (2)].node) == 0 || (vslvsp[(2) - (2)].node)->OK());

				    if ((vslvsp[(1) - (2)].function_header).pattern)
				    {
					// Define function
					vsllib->add(*(vslvsp[(1) - (2)].function_header).id, 
						    (vslvsp[(1) - (2)].function_header).pattern, (vslvsp[(2) - (2)].node), true,
						    *(vslvsp[(1) - (2)].function_header).file, (vslvsp[(1) - (2)].function_header).line);
				    }

				    delete (vslvsp[(1) - (2)].function_header).id;
				    delete (vslvsp[(1) - (2)].function_header).file;
				}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 331 "./vsl-gramma.Y"
    {
				  if ((vslvsp[(1) - (2)].function_header).pattern)
				  {
				      ASSERT((vslvsp[(1) - (2)].function_header).pattern->OK());

				      // Declare function now
				      // (for recursive calls)
				      vsllib->add(*(vslvsp[(1) - (2)].function_header).id,
						  (vslvsp[(1) - (2)].function_header).pattern->dup(), 0, true,
						  vslfilename, vsllinenumber);
				  }
				  (vslval.function_header) = (vslvsp[(1) - (2)].function_header);
				}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 346 "./vsl-gramma.Y"
    { (vslval.node) = (vslvsp[(1) - (1)].node); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 355 "./vsl-gramma.Y"
    {
				    (vslval.node) = (vslvsp[(1) - (1)].node);
				}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 359 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(2) - (3)].var_definition).pattern == 0 || 
					   (vslvsp[(2) - (3)].var_definition).pattern->OK());
				    ASSERT((vslvsp[(2) - (3)].var_definition).args == 0 || 
					   (vslvsp[(2) - (3)].var_definition).args->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());

				    (vslval.node) = ((vslvsp[(2) - (3)].var_definition).pattern && (vslvsp[(2) - (3)].var_definition).args && (vslvsp[(3) - (3)].node)) ?
					new LetNode((vslvsp[(2) - (3)].var_definition).pattern, (vslvsp[(2) - (3)].var_definition).args, (vslvsp[(3) - (3)].node)) :
					0;
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 373 "./vsl-gramma.Y"
    {
				    (vslval.node) = (vslvsp[(2) - (2)].node);
				}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 377 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(2) - (3)].var_definition).pattern == 0 || 
					   (vslvsp[(2) - (3)].var_definition).pattern->OK());
				    ASSERT((vslvsp[(2) - (3)].var_definition).args == 0 || 
					   (vslvsp[(2) - (3)].var_definition).args->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());

				    (vslval.node) = ((vslvsp[(2) - (3)].var_definition).pattern && (vslvsp[(2) - (3)].var_definition).args && (vslvsp[(3) - (3)].node)) ?
					new LetNode((vslvsp[(2) - (3)].var_definition).pattern, (vslvsp[(2) - (3)].var_definition).args, (vslvsp[(3) - (3)].node)) :
					0;

				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 392 "./vsl-gramma.Y"
    { (vslval.node) = (vslvsp[(1) - (1)].node); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 394 "./vsl-gramma.Y"
    { (vslval.node) = (vslvsp[(1) - (1)].node); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 398 "./vsl-gramma.Y"
    {
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].var_definition).pattern == 0 || 
					   (vslvsp[(3) - (3)].var_definition).pattern->OK());
				    ASSERT((vslvsp[(3) - (3)].var_definition).args == 0 || 
					   (vslvsp[(3) - (3)].var_definition).args->OK());

				    (vslval.node) = ((vslvsp[(3) - (3)].var_definition).pattern && (vslvsp[(3) - (3)].var_definition).args && (vslvsp[(1) - (3)].node)) ?
					new WhereNode((vslvsp[(3) - (3)].var_definition).pattern, (vslvsp[(3) - (3)].var_definition).args, (vslvsp[(1) - (3)].node)):
					0;
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 412 "./vsl-gramma.Y"
    {
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].var_definition).pattern == 0 || 
					   (vslvsp[(3) - (3)].var_definition).pattern->OK());
				    ASSERT((vslvsp[(3) - (3)].var_definition).args == 0 || 
					   (vslvsp[(3) - (3)].var_definition).args->OK());

				    (vslval.node) = ((vslvsp[(3) - (3)].var_definition).pattern && (vslvsp[(3) - (3)].var_definition).args && (vslvsp[(1) - (3)].node)) ?
					new WhereNode((vslvsp[(3) - (3)].var_definition).pattern, (vslvsp[(3) - (3)].var_definition).args, (vslvsp[(1) - (3)].node)):
					0;

				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 427 "./vsl-gramma.Y"
    {
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());

				    (vslval.var_definition).pattern = (vslvsp[(1) - (3)].node);
				    (vslval.var_definition).args    = (vslvsp[(3) - (3)].node);
				}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 439 "./vsl-gramma.Y"
    { (vslval.node) = (vslvsp[(2) - (3)].node); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 441 "./vsl-gramma.Y"
    { (vslval.node) = (vslvsp[(1) - (1)].node); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 443 "./vsl-gramma.Y"
    { (vslval.node) = (vslvsp[(1) - (1)].node); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 445 "./vsl-gramma.Y"
    { (vslval.node) = (vslvsp[(1) - (1)].node); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 447 "./vsl-gramma.Y"
    { (vslval.node) = (vslvsp[(1) - (1)].node); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 449 "./vsl-gramma.Y"
    { (vslval.node) = (vslvsp[(1) - (1)].node); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 451 "./vsl-gramma.Y"
    { (vslval.node) = (vslvsp[(1) - (1)].node); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 453 "./vsl-gramma.Y"
    { (vslval.node) = (vslvsp[(1) - (1)].node); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 456 "./vsl-gramma.Y"
    {
				    (vslval.node) = new EmptyListNode;
				    ASSERT((vslval.node)->OK());
				}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 461 "./vsl-gramma.Y"
    {
				    (vslval.node) = (vslvsp[(2) - (3)].node);
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 466 "./vsl-gramma.Y"
    {
				    (vslval.node) = new EmptyListNode;
				    ASSERT((vslval.node)->OK());
				}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 471 "./vsl-gramma.Y"
    {
				    (vslval.node) = (vslvsp[(2) - (3)].node);
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 477 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (1)].node) == 0 || (vslvsp[(1) - (1)].node)->OK());

				    (vslval.node) = ((vslvsp[(1) - (1)].node)) ? new FixListNode((vslvsp[(1) - (1)].node)) : 0;
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 484 "./vsl-gramma.Y"
    { 
				    (vslval.node) = (vslvsp[(1) - (1)].node); 
				}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 489 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());

				    (vslval.node) = ((vslvsp[(1) - (3)].node) && (vslvsp[(3) - (3)].node)) ? new ListNode((vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node)) : 0;
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 497 "./vsl-gramma.Y"
    {
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());

				    (vslval.node) = ((vslvsp[(1) - (3)].node) && (vslvsp[(3) - (3)].node)) ? new ListNode((vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node)) : 0;
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 505 "./vsl-gramma.Y"
    { 
				    (vslval.node) = (vslvsp[(1) - (2)].node); 
				}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 509 "./vsl-gramma.Y"
    {
				    (vslval.node) = new NameNode("...");
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 515 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (1)].str)->OK());

				    const string& name(*(vslvsp[(1) - (1)].str));
				    (vslval.node) = new StringNode(name);
				    delete (vslvsp[(1) - (1)].str);
				    (vslvsp[(1) - (1)].str) = 0;

				    ASSERT((vslval.node)->OK());
				}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 526 "./vsl-gramma.Y"
    { 
				    (vslval.node) = new NumNode((vslvsp[(1) - (1)].num));
				    ASSERT((vslval.node)->OK());
				}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 532 "./vsl-gramma.Y"
    {
				    (vslval.str) = new string(unquote((const char *)vsltext));
				    ASSERT((vslval.str)->OK());
				}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 537 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (2)].str)->OK());

				    (vslval.str) = (vslvsp[(1) - (2)].str);
				    *(vslval.str) += unquote((const char *)vsltext);

				    ASSERT((vslval.str)->OK());
				}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 547 "./vsl-gramma.Y"
    {
				    (vslval.num) = atoi((const char *)vsltext);
				}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 552 "./vsl-gramma.Y"
    {
				    ASSERT((vslvsp[(1) - (2)].str)->OK());
				    ASSERT((vslvsp[(2) - (2)].node) == 0 || (vslvsp[(2) - (2)].node)->OK());

				    (vslval.node) = ((vslvsp[(2) - (2)].node)) ? 
					vsllib->_call(*(vslvsp[(1) - (2)].str), (vslvsp[(2) - (2)].node)) : 0;
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());

				    delete (vslvsp[(1) - (2)].str);
				    (vslvsp[(1) - (2)].str) = 0;
				}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 565 "./vsl-gramma.Y"
    {
				    ASSERT((vslvsp[(2) - (2)].node) == 0 || (vslvsp[(2) - (2)].node)->OK());
				    (vslval.node) = vsllib->call("(not)", (vslvsp[(2) - (2)].node));
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 571 "./vsl-gramma.Y"
    {
				    (vslval.node) = (vslvsp[(2) - (2)].node);
				}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 575 "./vsl-gramma.Y"
    {
				    // Simulate `-X' by `0-X'
				    ASSERT((vslvsp[(2) - (2)].node) == 0 || (vslvsp[(2) - (2)].node)->OK());
				    (vslval.node) = ((vslvsp[(2) - (2)].node)) ? 
					vsllib->call("(-)", new NullNode, (vslvsp[(2) - (2)].node)) :
					0;
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 588 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());
				    (vslval.node) = vsllib->call("(=)", (vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node)); 
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 595 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());
				    (vslval.node) = vsllib->call("(<>)", (vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node)); 
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 602 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());
				    (vslval.node) = vsllib->call("(>)", (vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node)); 
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 609 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());
				    (vslval.node) = vsllib->call("(>=)", (vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node)); 
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 616 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());
				    (vslval.node) = vsllib->call("(<)", (vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node)); 
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 623 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());
				    (vslval.node) = vsllib->call("(<=)", (vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node)); 
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 630 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());
				    (vslval.node) = vsllib->call("(&)", (vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node)); 
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 637 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());
				    (vslval.node) = vsllib->call("(|)", (vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node)); 
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 644 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());
				    (vslval.node) = vsllib->call("(^)", (vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node)); 
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 651 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());
				    (vslval.node) = vsllib->call("(~)", (vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node)); 
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 658 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());
				    (vslval.node) = vsllib->call("(+)", (vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node)); 
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 665 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());
				    (vslval.node) = vsllib->call("(-)", (vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node)); 
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 672 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());
				    (vslval.node) = vsllib->call("(*)", (vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node)); 
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 679 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());
				    (vslval.node) = vsllib->call("(/)", (vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node)); 
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 686 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());
				    (vslval.node) = vsllib->call("(%)", (vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node)); 
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 693 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());
				    (vslval.node) = vsllib->call("(::)", (vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node)); 
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 700 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());
				    // If EXPR-1 then true else EXPR-2
				    (vslval.node) = ((vslvsp[(1) - (3)].node) && (vslvsp[(3) - (3)].node)) ? 
					new TestNode((vslvsp[(1) - (3)].node), new TrueNode, (vslvsp[(3) - (3)].node)) : 
					0;
				  ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 710 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(1) - (3)].node) == 0 || (vslvsp[(1) - (3)].node)->OK());
				    ASSERT((vslvsp[(3) - (3)].node) == 0 || (vslvsp[(3) - (3)].node)->OK());
				    // If EXPR-1 then EXPR-2 else false
				    (vslval.node) = ((vslvsp[(1) - (3)].node) && (vslvsp[(3) - (3)].node)) ? 
					new TestNode((vslvsp[(1) - (3)].node), (vslvsp[(3) - (3)].node), new FalseNode) : 
					0;
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 724 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(2) - (6)].node) == 0 || (vslvsp[(2) - (6)].node)->OK());
				    ASSERT((vslvsp[(4) - (6)].node) == 0 || (vslvsp[(4) - (6)].node)->OK());
				    ASSERT((vslvsp[(5) - (6)].node) == 0 || (vslvsp[(5) - (6)].node)->OK());

				    (vslval.node) = ((vslvsp[(2) - (6)].node) && (vslvsp[(4) - (6)].node) && (vslvsp[(5) - (6)].node)) ?
					new TestNode((vslvsp[(2) - (6)].node), (vslvsp[(4) - (6)].node), (vslvsp[(5) - (6)].node)) : 0;
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 737 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(2) - (5)].node) == 0 || (vslvsp[(2) - (5)].node)->OK());
				    ASSERT((vslvsp[(4) - (5)].node) == 0 || (vslvsp[(4) - (5)].node)->OK());
				    ASSERT((vslvsp[(5) - (5)].node) == 0 || (vslvsp[(5) - (5)].node)->OK());

				    (vslval.node) = ((vslvsp[(2) - (5)].node) && (vslvsp[(4) - (5)].node) && (vslvsp[(5) - (5)].node)) ?
					new TestNode((vslvsp[(2) - (5)].node), (vslvsp[(4) - (5)].node), (vslvsp[(5) - (5)].node)) : 0;
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 747 "./vsl-gramma.Y"
    {
				    (vslval.node) = (vslvsp[(2) - (2)].node);
				}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 752 "./vsl-gramma.Y"
    {
				    (vslval.node) = (vslvsp[(1) - (1)].node);
				}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 756 "./vsl-gramma.Y"
    { 
				    ASSERT((vslvsp[(2) - (3)].node) == 0 || (vslvsp[(2) - (3)].node)->OK());

				    (vslval.node) = ((vslvsp[(2) - (3)].node)) ? new FixListNode((vslvsp[(2) - (3)].node)) : 0; 
				    ASSERT((vslval.node) == 0 || (vslval.node)->OK());
				}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 764 "./vsl-gramma.Y"
    {
				    ASSERT((vslvsp[(1) - (1)].str)->OK());

				    if (*(vslvsp[(1) - (1)].str) == "_")
				    {
					(vslval.node) = new DummyNode;
				    }
				    else
				    {
					// If function is declared, use it;
					// otherwise create placeholder var
					
					if (vsllib->deflist("#" + *(vslvsp[(1) - (1)].str)))
					    (vslval.node) = vsllib->call("#" + *(vslvsp[(1) - (1)].str));
					else
					    (vslval.node) = new NameNode(*(vslvsp[(1) - (1)].str));
				    }

				    ASSERT((vslval.node)->OK());
				    delete (vslvsp[(1) - (1)].str);
				    (vslvsp[(1) - (1)].str) = 0;
				}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 796 "./vsl-gramma.Y"
    {
				    ASSERT((vslvsp[(1) - (1)].str)->OK());

				    const string& func_name = *(vslvsp[(1) - (1)].str);
				    vsllib->override(func_name);

				    delete (vslvsp[(1) - (1)].str);
				    (vslvsp[(1) - (1)].str) = 0;
				}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 812 "./vsl-gramma.Y"
    {
				    ASSERT((vslvsp[(1) - (1)].str)->OK());

				    const string &func_name = *(vslvsp[(1) - (1)].str);
				    if (vsllib->replace(func_name)
					&& vsllib->replace("#" + func_name))
				    {
					// Don't complain about misspelled
					// functions here -- they will be
					// uncovered with the following
					// (replacing) definition.
					if (false)
					{
					    VSLLib::parse_error(
						"'" + func_name + 
						"(...)' undefined");
					}
				    }

				    delete (vslvsp[(1) - (1)].str);
				    (vslvsp[(1) - (1)].str) = 0;
				}
    break;



/* Line 1806 of yacc.c  */
#line 2798 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter vslchar, and that requires
     that vsltoken be updated with the new translation.  We take the
     approach of translating immediately before every use of vsltoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering vslchar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", vslr1[vsln], &vslval, &vslloc);

  YYPOPSTACK (vsllen);
  vsllen = 0;
  YY_STACK_PRINT (vslss, vslssp);

  *++vslvsp = vslval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  vsln = vslr1[vsln];

  vslstate = vslpgoto[vsln - YYNTOKENS] + *vslssp;
  if (0 <= vslstate && vslstate <= YYLAST && vslcheck[vslstate] == *vslssp)
    vslstate = vsltable[vslstate];
  else
    vslstate = vsldefgoto[vsln - YYNTOKENS];

  goto vslnewstate;


/*------------------------------------.
| vslerrlab -- here on detecting error |
`------------------------------------*/
vslerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  vsltoken = vslchar == YYEMPTY ? YYEMPTY : YYTRANSLATE (vslchar);

  /* If not already recovering from an error, report this error.  */
  if (!vslerrstatus)
    {
      ++vslnerrs;
#if ! YYERROR_VERBOSE
      vslerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR vslsyntax_error (&vslmsg_alloc, &vslmsg, \
                                        vslssp, vsltoken)
      {
        char const *vslmsgp = YY_("syntax error");
        int vslsyntax_error_status;
        vslsyntax_error_status = YYSYNTAX_ERROR;
        if (vslsyntax_error_status == 0)
          vslmsgp = vslmsg;
        else if (vslsyntax_error_status == 1)
          {
            if (vslmsg != vslmsgbuf)
              YYSTACK_FREE (vslmsg);
            vslmsg = (char *) YYSTACK_ALLOC (vslmsg_alloc);
            if (!vslmsg)
              {
                vslmsg = vslmsgbuf;
                vslmsg_alloc = sizeof vslmsgbuf;
                vslsyntax_error_status = 2;
              }
            else
              {
                vslsyntax_error_status = YYSYNTAX_ERROR;
                vslmsgp = vslmsg;
              }
          }
        vslerror (vslmsgp);
        if (vslsyntax_error_status == 2)
          goto vslexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (vslerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (vslchar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (vslchar == YYEOF)
	    YYABORT;
	}
      else
	{
	  vsldestruct ("Error: discarding",
		      vsltoken, &vsllval);
	  vslchar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto vslerrlab1;


/*---------------------------------------------------.
| vslerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
vslerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label vslerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto vslerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (vsllen);
  vsllen = 0;
  YY_STACK_PRINT (vslss, vslssp);
  vslstate = *vslssp;
  goto vslerrlab1;


/*-------------------------------------------------------------.
| vslerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
vslerrlab1:
  vslerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      vsln = vslpact[vslstate];
      if (!vslpact_value_is_default (vsln))
	{
	  vsln += YYTERROR;
	  if (0 <= vsln && vsln <= YYLAST && vslcheck[vsln] == YYTERROR)
	    {
	      vsln = vsltable[vsln];
	      if (0 < vsln)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (vslssp == vslss)
	YYABORT;


      vsldestruct ("Error: popping",
		  vslstos[vslstate], vslvsp);
      YYPOPSTACK (1);
      vslstate = *vslssp;
      YY_STACK_PRINT (vslss, vslssp);
    }

  *++vslvsp = vsllval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", vslstos[vsln], vslvsp, vsllsp);

  vslstate = vsln;
  goto vslnewstate;


/*-------------------------------------.
| vslacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
vslacceptlab:
  vslresult = 0;
  goto vslreturn;

/*-----------------------------------.
| vslabortlab -- YYABORT comes here.  |
`-----------------------------------*/
vslabortlab:
  vslresult = 1;
  goto vslreturn;

#if !defined(vsloverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| vslexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
vslexhaustedlab:
  vslerror (YY_("memory exhausted"));
  vslresult = 2;
  /* Fall through.  */
#endif

vslreturn:
  if (vslchar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      vsltoken = YYTRANSLATE (vslchar);
      vsldestruct ("Cleanup: discarding lookahead",
                  vsltoken, &vsllval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (vsllen);
  YY_STACK_PRINT (vslss, vslssp);
  while (vslssp != vslss)
    {
      vsldestruct ("Cleanup: popping",
		  vslstos[*vslssp], vslvsp);
      YYPOPSTACK (1);
    }
#ifndef vsloverflow
  if (vslss != vslssa)
    YYSTACK_FREE (vslss);
#endif
#if YYERROR_VERBOSE
  if (vslmsg != vslmsgbuf)
    YYSTACK_FREE (vslmsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (vslresult);
}



/* Line 2067 of yacc.c  */
#line 836 "./vsl-gramma.Y"
 /* DO NOT REMOVE THIS COMMENT -- MUNCH-YACC DEPENDS ON IT */

