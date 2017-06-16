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
#line 1 "parser.ypp" /* yacc.c:339  */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <limits>

#define YYDEBUG 1

extern int yylex(); // Lexic analisys function
extern FILE* yyin; // Extern file, used for reading code from file

#include "logical_expressions.h"
#include "rddl.h"
#include "utils/system_utils.h"
#include "utils/timer.h"

extern void yyerror (std::string message); // Function for syntax error handling

std::string targetDir;
RDDLTask* rddlTask;


#line 92 "parser.tab.cc" /* yacc.c:339  */

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
   by #include "parser.tab.hh".  */
#ifndef YY_YY_PARSER_TAB_HH_INCLUDED
# define YY_YY_PARSER_TAB_HH_INCLUDED
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
    lessOrEqual_token = 258,
    greaterOrEqual_token = 259,
    negative_infinity_token = 260,
    equivalent_token = 261,
    imply_token = 262,
    equal_token = 263,
    nonEqual_token = 264,
    positive_infinity_token = 265,
    forall_token = 266,
    exists_token = 267,
    case_token = 268,
    if_token = 269,
    switch_token = 270,
    then_token = 271,
    else_token = 272,
    otherwise_token = 273,
    sum_token = 274,
    product_token = 275,
    kronDelta_token = 276,
    diracDelta_token = 277,
    uniform_token = 278,
    bernoulli_token = 279,
    discrete_token = 280,
    normal_token = 281,
    poisson_token = 282,
    exponential_token = 283,
    weibull_token = 284,
    gama_token = 285,
    dirichlet_token = 286,
    multinomial_token = 287,
    types_token = 288,
    variables_token = 289,
    cpfs_token = 290,
    cdfs_token = 291,
    reward_token = 292,
    domain_token = 293,
    requirements_token = 294,
    objects_token = 295,
    init_state_token = 296,
    state_action_constraints_token = 297,
    action_preconditions_token = 298,
    state_invariants_token = 299,
    instance_token = 300,
    non_fluents_token = 301,
    discount_token = 302,
    terminate_when_token = 303,
    horizon_token = 304,
    max_nondef_actions_token = 305,
    doubleNum_token = 306,
    id_token = 307,
    variable_token = 308,
    enum_token = 309,
    object_token = 310,
    integer_token = 311,
    real_token = 312,
    bool_token = 313,
    true_token = 314,
    false_token = 315,
    default_token = 316,
    level_token = 317,
    observ_fluent_token = 318,
    action_fluent_token = 319,
    state_fluent_token = 320,
    intermediate_token = 321,
    derived_fluent_token = 322,
    non_fluent_token = 323,
    intNum_token = 324,
    AgregateOperator = 325,
    NEGATIVE = 326
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 27 "parser.ypp" /* yacc.c:355  */

    double d;
    int i;
    std::string* str;
    std::vector<std::string>* strs;

    RDDLTask* rddlTask;
    Parameter* parameter;
    std::vector<Parameter*>* parameters;
    ParameterList* parameterList;
    ParametrizedVariable* parametrizedVariable;
    std::vector<ParametrizedVariable*>* parametrizedVariables;
    LogicalExpression* logicalExpression;
    Type* type;
    std::vector<Type*>* types;
    std::vector<LogicalExpression*>* logicalExpressions;
    ConditionEffectPair* conditionEffect;
    std::vector<ConditionEffectPair*>* conditionEffects;
    DiscreteDistribution* lConstCaseList;

#line 225 "parser.tab.cc" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 240 "parser.tab.cc" /* yacc.c:358  */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1503

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  233
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  744

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   326

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    94,     2,    73,     2,
      92,    93,    79,    77,    86,    78,    88,    80,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    87,    85,
      75,    84,    76,    91,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    89,     2,    90,    72,    95,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    82,    71,    83,    74,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    81
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,   102,   103,   104,   105,   106,   107,   115,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   143,   144,
     147,   148,   154,   157,   158,   162,   163,   164,   168,   169,
     170,   173,   174,   177,   178,   179,   180,   183,   184,   187,
     188,   189,   190,   191,   192,   198,   201,   202,   205,   206,
     207,   208,   209,   210,   211,   212,   215,   216,   219,   220,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   235,
     236,   239,   240,   243,   244,   247,   248,   249,   250,   253,
     254,   261,   264,   265,   268,   269,   272,   275,   289,   302,
     303,   304,   307,   308,   311,   312,   313,   314,   317,   318,
     321,   322,   323,   324,   325,   333,   334,   335,   336,   337,
     339,   340,   341,   342,   343,   344,   345,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   407,   408,   411,   412,   415,   416,
     419,   428,   429,   432,   433,   437,   438,   439,   445,   452,
     453,   456,   457,   460,   466,   467,   470,   471,   474,   480,
     481,   484,   485,   488,   494,   498,   499,   502,   509,   510,
     511,   512,   520,   531,   543,   544,   548,   560,   561,   573,
     574,   586,   589,   590,   600,   610,   619,   628,   636,   645,
     653,   661,   670,   679,   687,   695,   702,   710,   717,   724,
     732,   733,   736,   737
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "lessOrEqual_token",
  "greaterOrEqual_token", "negative_infinity_token", "equivalent_token",
  "imply_token", "equal_token", "nonEqual_token",
  "positive_infinity_token", "forall_token", "exists_token", "case_token",
  "if_token", "switch_token", "then_token", "else_token",
  "otherwise_token", "sum_token", "product_token", "kronDelta_token",
  "diracDelta_token", "uniform_token", "bernoulli_token", "discrete_token",
  "normal_token", "poisson_token", "exponential_token", "weibull_token",
  "gama_token", "dirichlet_token", "multinomial_token", "types_token",
  "variables_token", "cpfs_token", "cdfs_token", "reward_token",
  "domain_token", "requirements_token", "objects_token",
  "init_state_token", "state_action_constraints_token",
  "action_preconditions_token", "state_invariants_token", "instance_token",
  "non_fluents_token", "discount_token", "terminate_when_token",
  "horizon_token", "max_nondef_actions_token", "doubleNum_token",
  "id_token", "variable_token", "enum_token", "object_token",
  "integer_token", "real_token", "bool_token", "true_token", "false_token",
  "default_token", "level_token", "observ_fluent_token",
  "action_fluent_token", "state_fluent_token", "intermediate_token",
  "derived_fluent_token", "non_fluent_token", "intNum_token",
  "AgregateOperator", "'|'", "'^'", "'&'", "'~'", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "NEGATIVE", "'{'", "'}'", "'='", "';'", "','",
  "':'", "'.'", "'['", "']'", "'?'", "'('", "')'", "'$'", "'_'", "$accept",
  "Program", "RddlBlock", "DomainBlock", "DomainList",
  "RequirementsSection", "RequirementsList", "TypeSection", "TypeList",
  "SchematicType", "EnumList", "TypeSpecification", "StructMemberList",
  "LConst", "VarSection", "VarList", "VariableSchematic", "ParametarList",
  "ParametarListTypeSpecs", "RangeConstant", "StructRangeConsant",
  "StructRangeConsantList", "BoolType", "DoubleType", "IntType",
  "CPFSection", "CPFHeader", "CPFList", "CPFSchematic",
  "VariableExpression", "TermList", "Term", "MemberList", "Pterm",
  "Expression", "StructExpressionList", "ExpressionList", "TypedVarList",
  "TypedVariable", "CaseList", "CaseSchematic", "LConstCaseList",
  "RewardsSection", "StateConstraintsSection", "StateConstraintList",
  "StateConstraintSchematic", "ActionPreconditionsSection",
  "ActionPreconditionsList", "ActionPreconditionsSchematic",
  "StateInvariantSection", "StateInvariantList", "StateInvariantSchematic",
  "ObjectsSection", "ObjectsList", "ObjectsSchematic", "ObjectsConstList",
  "NonfluentBlock", "VariablesInstanceList", "VariableInstanceSchematic",
  "LConstList", "InstanceBlock", "HorizonSpecification",
  "PositiveIntOrPositiveInfinity", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   124,    94,    38,   126,    60,    62,    43,    45,    42,
      47,   326,   123,   125,    61,    59,    44,    58,    46,    91,
      93,    63,    40,    41,    36,    95
};
# endif

#define YYPACT_NINF -482

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-482)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -4,   -15,    -5,    20,    67,    -4,  -482,  -482,  -482,     8,
      26,    39,  -482,  -482,  -482,  -482,   282,   103,   118,    78,
     108,  -482,  -482,   101,   116,   111,   137,   139,   147,   121,
     282,   282,   282,   282,   152,   282,   282,   282,   282,   282,
     157,   174,   185,   210,  1006,   189,   224,   694,   770,   846,
    -482,  -482,  -482,  -482,  -482,   230,  -482,  -482,  -482,  -482,
    -482,   231,   236,   203,   208,   185,   -52,   213,   210,   205,
     206,   212,   215,   214,   218,   228,   239,   244,   248,   259,
     261,   262,   -43,   263,   268,   276,   279,  -482,    95,  -482,
    -482,  -482,  -482,  -482,  1006,   298,  1006,  1006,  1006,  1006,
     253,  -482,  1274,   -20,   223,   240,   224,   250,  1285,   245,
    1006,   291,  1296,   294,   292,   303,  1332,   296,   297,    31,
     306,   230,   310,   305,   320,   153,   322,  -482,  -482,   109,
     326,   324,  -482,   331,   337,  1006,   -23,   338,   339,  1006,
    1006,  1006,  1006,   370,  1006,  1006,  1006,  1006,  1006,  1006,
     371,   372,    28,  1006,   -23,  -482,  -482,  -482,  -482,  -482,
    -482,  -482,  -482,   340,  -482,  -482,  -482,   593,    71,  -482,
    1006,  1006,  1006,  1006,  1006,  1006,  1006,  1006,  1006,  1006,
    1006,  1006,  1006,  1006,  1006,  -482,   332,   344,   342,   381,
     363,  -482,  -482,  -482,   367,  -482,  -482,  -482,   385,  1006,
    -482,  -482,   387,  1006,   388,  -482,  1006,   132,   112,   390,
     391,   298,   420,   425,  -482,  -482,  -482,  -482,  -482,   405,
     403,   336,  -482,   444,   444,   188,  -482,  -482,   458,  -482,
     422,   444,   444,   266,   366,   732,   378,   430,   968,   389,
     622,   408,  1112,  1140,   431,   443,  -482,  -482,  -482,   230,
     230,   483,   448,  1158,   449,   451,   459,  1006,  -482,  -482,
     285,   285,  1423,   811,   285,   285,   566,    35,    35,   285,
     285,   127,   127,  -482,  -482,   494,  -482,   464,   -38,  -482,
    -482,  -482,  -482,  -482,  -482,  -482,  1376,   472,   473,   476,
     484,   487,   471,   485,   490,  -482,  -482,   497,   502,    91,
     520,   514,   109,   531,   546,   547,   548,   549,   550,   554,
     560,   565,   563,   567,   635,  -482,   570,   571,   572,  -482,
    -482,  1006,  -482,   298,  1006,  -482,  -482,  -482,  1006,  1006,
    1006,  1006,   568,   564,  -482,   122,  -482,  1006,  -482,   448,
     -23,  1193,  -482,  -482,   573,   601,   577,  -482,   224,   -16,
     604,     0,     1,   614,   224,   -16,   578,   109,   608,   579,
     589,   600,  -482,  -482,   109,   109,   109,   109,   109,   109,
     624,  1006,   444,  1006,  1006,    15,  1006,  1006,   427,   590,
     585,   486,   505,   515,   534,  1239,  -482,  -482,  -482,  -482,
    -482,  1082,   298,   -38,   594,   596,   599,   -24,   627,   602,
     -16,   603,  -482,   592,  -482,  -482,   605,   607,   606,   609,
    -482,   610,   617,  -482,   632,  -482,   613,   628,   621,   641,
     -21,    88,   642,  -482,  1387,  -482,  1387,  1412,   -23,   623,
     646,   644,  1387,  1387,  -482,   930,  -482,  -482,  -482,  -482,
    -482,   298,  -482,  -482,   -38,  -482,   647,   158,  -482,   298,
     595,   648,  -482,   182,  1006,   682,   683,   652,   657,   298,
     660,   662,   659,   689,   690,   667,   693,   671,   695,   697,
    1006,   672,  1006,  -482,    15,  -482,  1251,   668,  -482,    75,
    -482,  -482,  -482,  -482,  -482,  -482,  -482,  -482,   243,   -18,
     685,   687,   712,   680,  -482,  -482,  -482,   681,   673,   298,
     175,   688,   691,   692,   702,   544,   721,   728,   729,   696,
    -482,   731,   109,  -482,   733,   741,  -482,   742,  -482,   743,
     744,  1387,  1006,  1387,  -482,   298,  -482,   698,   747,   748,
     745,   749,   758,  -482,  -482,  -482,   243,   243,  -482,  -482,
     298,   154,   750,   751,   752,   224,   -16,     1,   727,  -482,
     791,   757,   759,  -482,  -482,   766,   158,   158,   158,   158,
     158,  1387,  -482,   -16,     1,   799,   158,   158,  -482,   773,
     774,  -482,   158,  -482,   767,     1,   804,   771,   772,   778,
     795,   796,  -482,   -16,   800,   798,   809,   810,   812,   813,
     818,   817,   819,  -482,   808,   814,   763,   822,  -482,   823,
     825,   826,   827,   682,   859,   862,   831,  -482,   832,   833,
     834,   837,   840,   841,   682,   865,   298,  -482,  -482,  -482,
     682,   876,   104,   195,   843,   845,   847,   848,  -482,  -482,
    -482,  -482,  -482,   204,   849,   851,  -482,   852,   854,   861,
     863,   878,   880,   881,   884,   882,   885,   886,   883,   888,
     899,   887,   931,   896,   -16,     1,   933,     1,   938,   902,
    -482,  -482,  -482,     1,   940,   904,  -482,   907,  -482,   909,
     908,   910,   911,   913,   944,   915,   914,   950,   951,   918,
     682,   955,   682,   958,   925,   682,   960,   927,   928,   207,
     929,   957,   964,   965,   932,   966,   967,   970,   972,   939,
     971,   969,   978,  1015,   980,  -482,  1017,   984,  -482,  -482,
       1,  1021,   985,  -482,   986,  -482,   987,  -482,   988,   990,
    1025,  1026,  1027,   682,  1028,   997,  1000,  1001,  1002,  1003,
     989,  1007,  1008,  1042,  1009,  -482,  -482,  -482,  1033,  -482,
    1048,  1037,  1040,  -482
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     3,     5,     4,     0,
       0,     0,     1,     6,     8,     7,     0,     0,     0,     0,
       0,    92,    93,     0,     0,     0,     0,     0,     0,     0,
      25,    19,    20,    21,     0,    22,    23,    26,    27,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,    16,    10,    11,    12,     0,    13,    14,    17,    18,
      15,     0,     0,     0,     0,    33,     0,     0,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,    97,   115,
     117,   149,   150,   148,     0,     0,     0,     0,     0,     0,
       0,   116,     0,     0,     0,     0,   195,     0,     0,     0,
     181,     0,     0,     0,   186,     0,     0,     0,   191,    97,
       0,    94,     0,     0,     0,     0,     0,    34,    66,     0,
       0,     0,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   144,    49,    51,    54,
      52,    53,    50,     0,   119,   129,   128,     0,     0,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   178,    30,     0,     0,     0,
       0,   196,   180,   183,     0,   182,   185,   188,     0,     0,
     190,   193,     0,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,    32,    43,    44,    45,    46,    68,
       0,     0,    55,     0,     0,     0,   104,   106,     0,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   113,   101,     0,
       0,     0,   108,   166,     0,     0,   102,     0,   140,   139,
     135,   136,   145,   146,   137,   138,   143,   141,   142,   134,
     133,   127,   130,   131,   132,     0,    29,     0,     0,   194,
     179,   184,   187,   189,   192,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    35,     0,     0,    41,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   168,     0,     0,   107,     0,     0,     0,   154,
     156,     0,   153,     0,     0,   160,   152,   151,     0,     0,
       0,     0,     0,     0,   114,     0,   109,     0,   120,    98,
       0,     0,    31,    28,   198,     0,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   112,   111,   167,   100,
     103,   164,     0,     0,   200,     0,     0,     0,     0,     0,
     204,     0,   233,     0,   232,   230,     0,     0,     0,     0,
      40,    47,    41,    42,     0,    37,     0,     0,     0,     0,
       0,     0,     0,   170,   121,   169,   122,     0,     0,     0,
       0,   171,   123,   124,   157,     0,   155,   158,   161,   162,
     159,     0,   165,   199,     0,   197,     0,     0,   207,     0,
     209,     0,   205,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,     0,   176,   175,     0,   201,     0,
      88,    87,    85,    73,    75,    83,    84,    89,     0,     0,
       0,     0,     0,     0,    70,    71,    72,   212,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,    65,     0,     0,    63,     0,    64,     0,
       0,   125,     0,   174,   172,     0,   163,     0,     0,     0,
       0,     0,     0,    80,    86,    90,     0,     0,    74,   211,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   231,
       0,     0,     0,   203,    38,     0,     0,     0,     0,     0,
       0,   173,   177,     0,     0,     0,     0,     0,    76,     0,
       0,   213,     0,   206,     0,     0,     0,     0,     0,     0,
       0,     0,   229,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,    81,     0,     0,     0,   208,     0,
       0,     0,     0,     0,     0,     0,     0,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,    77,   210,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    58,
      61,    62,    59,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,   221,   202,     0,     0,     0,   227,     0,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,     0,     0,   219,   217,
       0,     0,     0,   226,     0,   224,     0,   223,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,   216,   215,     0,   222,
       0,     0,     0,   214
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -482,  -482,  -482,  1119,   495,  -482,   503,  -482,  1060,  -482,
     768,  -342,   669,   -93,  -482,  1059,  -482,  -482,   828,  -473,
    -258,   513,  -482,  -482,  -482,  -482,  -482,  1010,  -482,   -48,
     792,  -130,  -232,  -482,   -44,   746,   802,  -215,  -482,   663,
    -482,  -433,  -482,  -482,  1030,  -482,  -482,   946,  -482,  -482,
     947,  -482,  -482,  -105,  -482,  -380,  1147,  -343,  -482,  -481,
    1148,  -434,  -349
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    29,    30,   188,    31,    64,    65,
     300,   219,   297,   531,    32,    67,    68,   130,   220,   493,
     532,   533,   494,   495,   496,    33,    34,   120,   121,   101,
     255,   256,   155,   252,   108,   164,   254,   311,   312,   430,
     431,   380,    35,    36,   109,   110,    37,   113,   114,    38,
     117,   118,    39,   105,   106,   346,     7,   399,   400,   498,
       8,   292,   405
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     102,   191,   163,   406,   112,   116,   230,   122,   477,   313,
     402,   402,   409,   443,   344,   411,   317,   318,   542,   504,
     336,   506,   417,   418,   419,   420,   421,   422,   428,   119,
     226,   227,   186,   534,     1,   128,   397,     9,   170,   171,
     129,     2,     3,   174,   175,   529,   146,    10,   403,   147,
     156,   535,   165,   166,   167,   168,   345,   452,   398,   571,
     447,   448,   465,   187,   478,   466,   544,    12,   449,   404,
     404,   228,    11,   122,   170,   171,   429,   172,   173,   174,
     175,   246,   247,   585,   586,   587,   588,   589,   229,   248,
      16,   225,   562,   593,   594,   233,   234,   235,   236,   597,
     238,   239,   240,   241,   242,   243,   229,   389,    17,   253,
     179,   180,   181,   182,   183,   184,   527,   249,   298,   152,
     250,    18,   251,   154,   290,   528,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,    40,   176,   177,   178,   639,   179,   180,   181,   182,
     183,   184,   293,   290,   640,   112,    41,   425,   294,   116,
      42,   215,   286,   480,   259,   216,   217,   218,   481,   624,
     555,   467,   287,   288,   468,   246,   247,   358,   289,   359,
     634,   290,   291,   152,   153,    44,   637,   154,   641,   643,
      43,   170,   171,    46,   172,   173,   174,   175,   579,   649,
      45,   332,   333,   578,    50,   209,   183,   184,   210,   482,
     483,   249,   484,   341,   250,   591,   251,   485,   486,    47,
     590,    48,   501,   502,   290,   543,   599,   487,   211,    49,
     379,   290,   503,   488,    55,   212,   489,    63,   572,   573,
     606,    61,   213,   396,   290,   642,   690,   490,   692,   408,
     491,   695,   492,   290,   648,   700,   290,   699,    62,   176,
     177,   178,    66,   179,   180,   181,   182,   183,   184,   170,
     171,   103,   172,   173,   174,   175,   104,   378,   569,   570,
     381,   314,   119,   123,   382,   383,   384,   385,   124,   728,
     125,   126,   229,   253,   157,   158,   131,   159,   471,   163,
     133,   134,   160,   161,   135,   169,   670,   136,   672,   137,
     189,   669,   162,   138,   675,    19,    20,    21,    22,    23,
     139,    24,    25,   190,    26,    27,    28,   424,   194,   426,
     427,   140,   432,   433,   530,   192,   141,   176,   177,   178,
     142,   179,   180,   181,   182,   183,   184,   270,   379,   157,
     158,   143,   159,   144,   145,   148,   497,   160,   161,   319,
     149,   718,   181,   182,   183,   184,   298,   162,   150,   170,
     171,   151,   172,   173,   174,   175,   196,   198,   199,   202,
     229,   170,   171,   203,   172,   173,   174,   175,   200,   204,
     207,   476,   170,   171,   206,   172,   173,   174,   175,   304,
     305,   306,   307,   308,   309,   208,   497,   214,   221,   222,
     505,   170,   171,   223,   172,   173,   174,   175,   275,   224,
     231,   232,   237,   244,   245,   277,   521,   257,   523,   276,
     170,   171,   379,   172,   173,   174,   175,   176,   177,   178,
     577,   179,   180,   181,   182,   183,   184,   497,   279,   176,
     177,   178,   280,   179,   180,   181,   182,   183,   184,   320,
     176,   177,   178,   278,   179,   180,   181,   182,   183,   184,
     281,   322,   283,   285,   299,   295,   296,   301,   561,   176,
     177,   178,   325,   179,   180,   181,   182,   183,   184,   170,
     171,   302,   172,   173,   174,   175,   303,   310,   176,   177,
     178,   327,   179,   180,   181,   182,   183,   184,   170,   171,
     315,   172,   173,   174,   175,   316,   323,   330,   170,   171,
     434,   172,   173,   174,   175,    51,    52,    53,    54,   331,
      56,    57,    58,    59,    60,   334,   335,   170,   171,   338,
     172,   173,   174,   175,   339,   340,   186,   170,   171,   343,
     172,   173,   174,   175,   348,   349,   353,   176,   177,   178,
     350,   179,   180,   181,   182,   183,   184,   354,   351,   170,
     171,   352,   355,   356,   174,   175,   176,   177,   178,   437,
     179,   180,   181,   182,   183,   184,   176,   177,   178,   357,
     179,   180,   181,   182,   183,   184,   170,   171,   438,   172,
     173,   174,   175,   360,   361,   176,   177,   178,   439,   179,
     180,   181,   182,   183,   184,   176,   177,   178,   363,   179,
     180,   181,   182,   183,   184,   170,   171,   440,   172,   173,
     174,   175,   364,   365,   366,   367,   368,   549,   177,   178,
     369,   179,   180,   181,   182,   183,   184,   370,   371,   372,
     373,   374,   375,   394,   376,   377,   401,   387,   386,   393,
     395,   407,   412,   410,   176,   177,   178,   414,   179,   180,
     181,   182,   183,   184,   415,   416,   423,   435,   436,   450,
     444,   445,   446,   258,   454,   451,   460,   499,   453,   457,
     455,   456,   458,   176,   177,   178,   459,   179,   180,   181,
     182,   183,   184,   358,   461,    69,    70,   463,    71,    72,
     472,   462,   326,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,   464,   469,   473,
     474,   290,   479,   500,   507,   170,   171,   508,   172,   173,
     174,   175,   509,   511,   513,    87,    88,    89,    90,   512,
     514,   515,   516,    91,    92,   517,   518,   519,   520,   522,
     536,   526,   537,    93,   538,   539,   541,   540,    94,    95,
     545,    96,    97,   546,   580,   552,   547,   107,   342,   553,
     563,    69,    70,    98,    71,    72,    99,   548,   100,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,   176,   177,   178,   550,   179,   180,   181,
     182,   183,   184,   551,   170,   171,   554,   556,   321,   174,
     175,    87,    88,    89,    90,   557,   558,   559,   560,    91,
      92,   564,   566,   565,   568,   575,   567,   576,   581,    93,
     582,   583,   584,   574,    94,    95,   592,    96,    97,   595,
     596,   600,   598,   111,   601,   602,   618,    69,    70,    98,
      71,    72,    99,   603,   100,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,   604,
     605,   608,   176,   177,   178,   607,   179,   180,   181,   182,
     183,   184,   609,   610,   616,   611,   612,    87,    88,    89,
      90,   613,   614,   615,   617,    91,    92,   619,   620,   621,
     625,   622,   623,   626,   627,    93,   635,   628,   629,   630,
      94,    95,   631,    96,    97,   632,   633,   638,   644,   115,
     645,   659,   646,   647,   650,    98,   651,   652,    99,   653,
     100,    69,    70,   654,    71,    72,   665,   655,   475,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,   656,   657,   660,   658,   663,   661,   662,
     666,   170,   171,   664,   172,   173,   174,   175,   667,   668,
     671,    87,    88,    89,    90,   673,   674,   676,   677,    91,
      92,   678,   679,   680,   681,   684,   682,   683,   686,    93,
     685,   687,   688,   689,    94,    95,   691,    96,    97,   693,
     694,   696,   697,   698,   701,   705,   712,    69,    70,    98,
      71,    72,    99,   710,   100,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,   176,
     177,   178,   702,   179,   180,   181,   182,   183,   184,   703,
     704,   706,   707,   708,   324,   709,   711,    87,    88,    89,
      90,   713,   714,   715,   716,    91,    92,   717,   719,   720,
     721,   722,   735,   723,   724,    93,   725,   726,   727,   729,
      94,    95,   730,    96,    97,   731,   732,   733,   734,   738,
     736,   737,   739,    69,    70,    98,    71,    72,    99,   741,
     100,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,   170,   171,   740,   172,   173,
     174,   175,   742,   743,    13,   127,   413,   132,   510,   636,
     362,   205,   390,    87,    88,    89,    90,   524,   442,   388,
     195,    91,    92,   170,   171,   282,   172,   173,   174,   175,
     284,    93,    14,    15,     0,     0,    94,     0,     0,    96,
      97,   170,   171,     0,   172,   173,   174,   175,     0,     0,
       0,    98,     0,     0,    99,     0,   100,     0,     0,     0,
       0,     0,     0,   176,   177,   178,     0,   179,   180,   181,
     182,   183,   184,     0,     0,     0,   170,   171,   328,   172,
     173,   174,   175,     0,     0,     0,     0,     0,     0,     0,
       0,   176,   177,   178,     0,   179,   180,   181,   182,   183,
     184,     0,     0,     0,     0,     0,   329,     0,     0,   176,
     177,   178,     0,   179,   180,   181,   182,   183,   184,     0,
       0,     0,   170,   171,   337,   172,   173,   174,   175,     0,
       0,     0,     0,     0,   170,   171,     0,   172,   173,   174,
     175,     0,     0,     0,   176,   177,   178,     0,   179,   391,
     181,   182,   183,   184,     0,     0,     0,   170,   171,   392,
     172,   173,   174,   175,     0,     0,     0,     0,   170,   171,
       0,   172,   173,   174,   175,     0,     0,     0,     0,   170,
     171,     0,   172,   173,   174,   175,     0,     0,     0,     0,
     176,   177,   178,     0,   179,   180,   181,   182,   183,   184,
       0,     0,   176,   177,   178,   441,   179,   180,   181,   182,
     183,   184,     0,     0,     0,   170,   171,   525,   172,   173,
     174,   175,     0,     0,     0,   176,   177,   178,     0,   179,
     180,   181,   182,   183,   184,     0,   176,   177,   178,   185,
     179,   180,   181,   182,   183,   184,     0,   176,   177,   178,
     193,   179,   180,   181,   182,   183,   184,     0,     0,   170,
     171,   197,   172,   173,   174,   175,     0,     0,     0,     0,
     170,   171,     0,   172,   173,   174,   175,     0,     0,     0,
       0,     0,     0,   176,   177,   178,     0,   179,   180,   181,
     182,   183,   184,     0,     0,   170,   171,   201,   172,   173,
     174,   175,     0,     0,     0,     0,   170,   171,     0,   470,
     173,   174,   175,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   176,   177,   178,
       0,   179,   180,   181,   182,   183,   184,     0,   176,   177,
     178,   347,   179,   180,   181,   182,   183,   184,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   176,   177,   178,     0,   179,   180,   181,
     182,   183,   184,     0,   176,   177,   178,     0,   179,   180,
     181,   182,   183,   184
};

static const yytype_int16 yycheck[] =
{
      44,   106,    95,   352,    48,    49,   136,    55,   441,   224,
      10,    10,   355,   393,    52,   357,   231,   232,   499,   453,
     252,   455,   364,   365,   366,   367,   368,   369,    13,    52,
      53,    54,    52,    51,    38,    87,    52,    52,     3,     4,
      92,    45,    46,     8,     9,   479,    89,    52,    48,    92,
      94,    69,    96,    97,    98,    99,    94,   400,    74,   540,
      84,    85,    83,    83,   444,    86,   500,     0,    92,    69,
      69,    94,    52,   121,     3,     4,    61,     6,     7,     8,
       9,    53,    54,   556,   557,   558,   559,   560,   136,    61,
      82,   135,   525,   566,   567,   139,   140,   141,   142,   572,
     144,   145,   146,   147,   148,   149,   154,   339,    82,   153,
      75,    76,    77,    78,    79,    80,    41,    89,   211,    88,
      92,    82,    94,    92,    49,    50,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,    38,    71,    72,    73,    41,    75,    76,    77,    78,
      79,    80,    40,    49,    50,   199,    38,   372,    46,   203,
      82,    52,   206,     5,    93,    56,    57,    58,    10,   603,
     512,    83,    40,    41,    86,    53,    54,    86,    46,    88,
     614,    49,    50,    88,    89,    84,   620,    92,   622,   623,
      82,     3,     4,    82,     6,     7,     8,     9,   547,   633,
      84,   249,   250,   546,    83,    52,    79,    80,    55,    51,
      52,    89,    54,   257,    92,   564,    94,    59,    60,    82,
     563,    82,    40,    41,    49,    50,   575,    69,    75,    82,
     323,    49,    50,    75,    82,    82,    78,    52,    84,    85,
     583,    84,    89,   348,    49,    50,   680,    89,   682,   354,
      92,   685,    94,    49,    50,   689,    49,    50,    84,    71,
      72,    73,    52,    75,    76,    77,    78,    79,    80,     3,
       4,    82,     6,     7,     8,     9,    52,   321,   536,   537,
     324,    93,    52,    52,   328,   329,   330,   331,    52,   723,
      87,    83,   340,   337,    51,    52,    83,    54,   428,   392,
      95,    95,    59,    60,    92,    52,   655,    92,   657,    95,
      87,   654,    69,    95,   663,    33,    34,    35,    36,    37,
      92,    39,    40,    83,    42,    43,    44,   371,    83,   373,
     374,    92,   376,   377,    91,    85,    92,    71,    72,    73,
      92,    75,    76,    77,    78,    79,    80,   391,   441,    51,
      52,    92,    54,    92,    92,    92,   449,    59,    60,    93,
      92,   710,    77,    78,    79,    80,   459,    69,    92,     3,
       4,    92,     6,     7,     8,     9,    85,    83,    86,    83,
     428,     3,     4,    86,     6,     7,     8,     9,    85,    83,
      85,   435,     3,     4,    84,     6,     7,     8,     9,    63,
      64,    65,    66,    67,    68,    85,   499,    85,    82,    85,
     454,     3,     4,    82,     6,     7,     8,     9,    86,    82,
      82,    82,    52,    52,    52,    83,   470,    87,   472,    85,
       3,     4,   525,     6,     7,     8,     9,    71,    72,    73,
     545,    75,    76,    77,    78,    79,    80,   540,    85,    71,
      72,    73,    85,    75,    76,    77,    78,    79,    80,    93,
      71,    72,    73,    82,    75,    76,    77,    78,    79,    80,
      85,    93,    85,    85,    54,    85,    85,    52,   522,    71,
      72,    73,    93,    75,    76,    77,    78,    79,    80,     3,
       4,    86,     6,     7,     8,     9,    93,    53,    71,    72,
      73,    93,    75,    76,    77,    78,    79,    80,     3,     4,
      52,     6,     7,     8,     9,    93,    86,    86,     3,     4,
      93,     6,     7,     8,     9,    30,    31,    32,    33,    86,
      35,    36,    37,    38,    39,    52,    88,     3,     4,    90,
       6,     7,     8,     9,    93,    86,    52,     3,     4,    85,
       6,     7,     8,     9,    82,    82,    85,    71,    72,    73,
      84,    75,    76,    77,    78,    79,    80,    82,    84,     3,
       4,    84,    82,    76,     8,     9,    71,    72,    73,    93,
      75,    76,    77,    78,    79,    80,    71,    72,    73,    87,
      75,    76,    77,    78,    79,    80,     3,     4,    93,     6,
       7,     8,     9,    83,    90,    71,    72,    73,    93,    75,
      76,    77,    78,    79,    80,    71,    72,    73,    87,    75,
      76,    77,    78,    79,    80,     3,     4,    93,     6,     7,
       8,     9,    86,    86,    86,    86,    86,    93,    72,    73,
      86,    75,    76,    77,    78,    79,    80,    87,    83,    86,
      83,    16,    82,    52,    83,    83,    52,    93,    90,    86,
      83,    47,    54,    85,    71,    72,    73,    88,    75,    76,
      77,    78,    79,    80,    85,    75,    52,    87,    93,    52,
      86,    85,    83,    90,    92,    83,    54,    92,    85,    83,
      85,    84,    83,    71,    72,    73,    86,    75,    76,    77,
      78,    79,    80,    86,    91,    11,    12,    86,    14,    15,
      87,    83,    90,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    86,    86,    83,
      86,    49,    85,    85,    51,     3,     4,    85,     6,     7,
       8,     9,    85,    83,    85,    51,    52,    53,    54,    87,
      61,    61,    85,    59,    60,    62,    85,    62,    61,    87,
      75,    93,    75,    69,    52,    85,    93,    86,    74,    75,
      82,    77,    78,    82,    47,    46,    84,    83,   275,    83,
      82,    11,    12,    89,    14,    15,    92,    85,    94,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    71,    72,    73,    85,    75,    76,    77,
      78,    79,    80,    85,     3,     4,    85,    84,    86,     8,
       9,    51,    52,    53,    54,    84,    84,    84,    84,    59,
      60,    84,    87,    85,    76,    84,    87,    85,    47,    69,
      83,    82,    76,    93,    74,    75,    47,    77,    78,    76,
      76,    47,    85,    83,    83,    83,    93,    11,    12,    89,
      14,    15,    92,    85,    94,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    84,
      84,    83,    71,    72,    73,    85,    75,    76,    77,    78,
      79,    80,    83,    83,    86,    83,    83,    51,    52,    53,
      54,    83,    85,    84,    90,    59,    60,    85,    85,    84,
      51,    85,    85,    51,    83,    69,    51,    85,    85,    85,
      74,    75,    85,    77,    78,    85,    85,    51,    85,    83,
      85,    47,    85,    85,    85,    89,    85,    85,    92,    85,
      94,    11,    12,    82,    14,    15,    47,    84,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    85,    84,    83,    85,    84,    83,    83,
      83,     3,     4,    85,     6,     7,     8,     9,    47,    83,
      47,    51,    52,    53,    54,    47,    84,    47,    84,    59,
      60,    84,    83,    85,    84,    51,    85,    84,    84,    69,
      85,    51,    51,    85,    74,    75,    51,    77,    78,    51,
      85,    51,    85,    85,    85,    83,    47,    11,    12,    89,
      14,    15,    92,    84,    94,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    71,
      72,    73,    85,    75,    76,    77,    78,    79,    80,    85,
      85,    85,    85,    83,    86,    83,    85,    51,    52,    53,
      54,    83,    47,    83,    47,    59,    60,    83,    47,    84,
      84,    84,    83,    85,    84,    69,    51,    51,    51,    51,
      74,    75,    85,    77,    78,    85,    85,    85,    85,    47,
      83,    83,    83,    11,    12,    89,    14,    15,    92,    51,
      94,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     3,     4,    84,     6,     7,
       8,     9,    85,    83,     5,    65,   358,    68,   459,   616,
     302,   121,   340,    51,    52,    53,    54,   474,   392,   337,
     110,    59,    60,     3,     4,   199,     6,     7,     8,     9,
     203,    69,     5,     5,    -1,    -1,    74,    -1,    -1,    77,
      78,     3,     4,    -1,     6,     7,     8,     9,    -1,    -1,
      -1,    89,    -1,    -1,    92,    -1,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    -1,    75,    76,    77,
      78,    79,    80,    -1,    -1,    -1,     3,     4,    86,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    -1,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    71,
      72,    73,    -1,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,     3,     4,    86,     6,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    -1,    -1,    -1,    71,    72,    73,    -1,    75,    76,
      77,    78,    79,    80,    -1,    -1,    -1,     3,     4,    86,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    -1,    -1,    -1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      71,    72,    73,    -1,    75,    76,    77,    78,    79,    80,
      -1,    -1,    71,    72,    73,    86,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,     3,     4,    86,     6,     7,
       8,     9,    -1,    -1,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    -1,    71,    72,    73,    85,
      75,    76,    77,    78,    79,    80,    -1,    71,    72,    73,
      85,    75,    76,    77,    78,    79,    80,    -1,    -1,     3,
       4,    85,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    -1,    75,    76,    77,
      78,    79,    80,    -1,    -1,     3,     4,    85,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,     3,     4,    -1,    17,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      -1,    75,    76,    77,    78,    79,    80,    -1,    71,    72,
      73,    85,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    -1,    75,    76,    77,
      78,    79,    80,    -1,    71,    72,    73,    -1,    75,    76,
      77,    78,    79,    80
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    45,    46,    97,    98,    99,   152,   156,    52,
      52,    52,     0,    99,   152,   156,    82,    82,    82,    33,
      34,    35,    36,    37,    39,    40,    42,    43,    44,   100,
     101,   103,   110,   121,   122,   138,   139,   142,   145,   148,
      38,    38,    82,    82,    84,    84,    82,    82,    82,    82,
      83,   100,   100,   100,   100,    82,   100,   100,   100,   100,
     100,    84,    84,    52,   104,   105,    52,   111,   112,    11,
      12,    14,    15,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    51,    52,    53,
      54,    59,    60,    69,    74,    75,    77,    78,    89,    92,
      94,   125,   130,    82,    52,   149,   150,    83,   130,   140,
     141,    83,   130,   143,   144,    83,   130,   146,   147,    52,
     123,   124,   125,    52,    52,    87,    83,   104,    87,    92,
     113,    83,   111,    95,    95,    92,    92,    95,    95,    92,
      92,    92,    92,    92,    92,    92,    89,    92,    92,    92,
      92,    92,    88,    89,    92,   128,   130,    51,    52,    54,
      59,    60,    69,   109,   131,   130,   130,   130,   130,    52,
       3,     4,     6,     7,     8,     9,    71,    72,    73,    75,
      76,    77,    78,    79,    80,    85,    52,    83,   102,    87,
      83,   149,    85,    85,    83,   140,    85,    85,    83,    86,
      85,    85,    83,    86,    83,   123,    84,    85,    85,    52,
      55,    75,    82,    89,    85,    52,    56,    57,    58,   107,
     114,    82,    85,    82,    82,   130,    53,    54,    94,   125,
     127,    82,    82,   130,   130,   130,   130,    52,   130,   130,
     130,   130,   130,   130,    52,    52,    53,    54,    61,    89,
      92,    94,   129,   130,   132,   126,   127,    87,    90,    93,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,    86,    85,    83,    82,    85,
      85,    85,   143,    85,   146,    85,   130,    40,    41,    46,
      49,    50,   157,    40,    46,    85,    85,   108,   109,    54,
     106,    52,    86,    93,    63,    64,    65,    66,    67,    68,
      53,   133,   134,   133,    93,    52,    93,   133,   133,    93,
      93,    86,    93,    86,    86,    93,    90,    93,    86,    86,
      86,    86,   125,   125,    52,    88,   128,    86,    90,    93,
      86,   130,   102,    85,    52,    94,   151,    85,    82,    82,
      84,    84,    84,    85,    82,    82,    76,    87,    86,    88,
      83,    90,   114,    87,    86,    86,    86,    86,    86,    86,
      87,    83,    86,    83,    16,    82,    83,    83,   130,   109,
     137,   130,   130,   130,   130,   130,    90,    93,   132,   128,
     126,    76,    86,    86,    52,    83,   149,    52,    74,   153,
     154,    52,    10,    48,    69,   158,   158,    47,   149,   153,
      85,   107,    54,   106,    88,    85,    75,   107,   107,   107,
     107,   107,   107,    52,   130,   133,   130,   130,    13,    61,
     135,   136,   130,   130,    93,    87,    93,    93,    93,    93,
      93,    86,   131,   151,    86,    85,    83,    84,    85,    92,
      52,    83,   153,    85,    92,    85,    84,    83,    83,    86,
      54,    91,    83,    86,    86,    83,    86,    83,    86,    86,
      17,   127,    87,    83,    86,    18,   130,   137,   151,    85,
       5,    10,    51,    52,    54,    59,    60,    69,    75,    78,
      89,    92,    94,   115,   118,   119,   120,   109,   155,    92,
      85,    40,    41,    50,   157,   130,   157,    51,    85,    85,
     108,    83,    87,    85,    61,    61,    85,    62,    85,    62,
      61,   130,    87,   130,   135,    86,    93,    41,    50,   157,
      91,   109,   116,   117,    51,    69,    75,    75,    52,    85,
      86,    93,   155,    50,   157,    82,    82,    84,    85,    93,
      85,    85,    46,    83,    85,   107,    84,    84,    84,    84,
      84,   130,   137,    82,    84,    85,    87,    87,    76,   116,
     116,   155,    84,    85,    93,    84,    85,   149,   153,   158,
      47,    47,    83,    82,    76,   115,   115,   115,   115,   115,
     153,   158,    47,   115,   115,    76,    76,   115,    85,   158,
      47,    83,    83,    85,    84,    84,   153,    85,    83,    83,
      83,    83,    83,    83,    85,    84,    86,    90,    93,    85,
      85,    84,    85,    85,   157,    51,    51,    83,    85,    85,
      85,    85,    85,    85,   157,    51,   117,   157,    51,    41,
      50,   157,    50,   157,    85,    85,    85,    85,    50,   157,
      85,    85,    85,    85,    82,    84,    85,    84,    85,    47,
      83,    83,    83,    84,    85,    47,    83,    47,    83,   153,
     158,    47,   158,    47,    84,   158,    47,    84,    84,    83,
      85,    84,    85,    84,    51,    85,    84,    51,    51,    85,
     157,    51,   157,    51,    85,   157,    51,    85,    85,    50,
     157,    85,    85,    85,    85,    83,    85,    85,    83,    83,
      84,    85,    47,    83,    47,    83,    47,    83,   158,    47,
      84,    84,    84,    85,    84,    51,    51,    51,   157,    51,
      85,    85,    85,    85,    85,    83,    83,    83,    47,    83,
      84,    51,    85,    83
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    96,    97,    98,    98,    98,    98,    98,    98,    99,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   101,   101,
     102,   102,   103,   104,   104,   105,   105,   105,   105,   105,
     105,   106,   106,   107,   107,   107,   107,   108,   108,   109,
     109,   109,   109,   109,   109,   110,   111,   111,   112,   112,
     112,   112,   112,   112,   112,   112,   113,   113,   114,   114,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   116,
     116,   117,   117,   118,   118,   119,   119,   119,   119,   120,
     120,   121,   122,   122,   123,   123,   124,   125,   125,   125,
     125,   125,   126,   126,   127,   127,   127,   127,   128,   128,
     129,   129,   129,   129,   129,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   131,   131,   132,   132,   133,   133,
     134,   135,   135,   136,   136,   137,   137,   137,   138,   139,
     139,   140,   140,   141,   142,   142,   143,   143,   144,   145,
     145,   146,   146,   147,   148,   149,   149,   150,   151,   151,
     151,   151,   152,   152,   153,   153,   154,   154,   154,   154,
     154,   154,   155,   155,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     157,   157,   158,   158
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     2,     5,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     6,     5,
       1,     3,     5,     1,     2,     4,     4,     6,     9,    11,
       6,     1,     3,     1,     1,     1,     1,     3,     5,     1,
       1,     1,     1,     1,     1,     5,     1,     2,    12,    12,
      12,    12,    12,     8,     8,     8,     1,     4,     1,     3,
       1,     1,     1,     1,     2,     1,     3,     5,     5,     3,
       1,     3,     5,     1,     1,     1,     2,     1,     1,     1,
       2,     5,     1,     1,     1,     2,     4,     1,     4,     2,
       5,     3,     1,     3,     1,     1,     1,     2,     2,     3,
       1,     3,     3,     1,     2,     1,     1,     1,     2,     2,
       4,     6,     6,     6,     6,     8,     7,     3,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     1,     1,     1,
       1,     4,     4,     4,     4,     6,     4,     6,     6,     6,
       4,     6,     6,     8,     4,     5,     1,     3,     1,     3,
       3,     1,     3,     4,     3,     3,     3,     5,     4,     5,
       4,     1,     2,     2,     5,     4,     1,     3,     2,     5,
       4,     1,     3,     2,     5,     1,     2,     6,     1,     3,
       2,     4,    18,    13,     1,     2,     5,     2,     6,     2,
       7,     4,     1,     3,    32,    28,    27,    23,    27,    23,
      22,    18,    28,    24,    23,    19,    23,    19,    18,    14,
       3,     6,     1,     1
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
#line 96 "parser.ypp" /* yacc.c:1646  */
    { }
#line 1963 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 102 "parser.ypp" /* yacc.c:1646  */
    { (yyval.rddlTask) = rddlTask; }
#line 1969 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 103 "parser.ypp" /* yacc.c:1646  */
    { (yyval.rddlTask) = rddlTask; }
#line 1975 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 5:
#line 104 "parser.ypp" /* yacc.c:1646  */
    { (yyval.rddlTask) = rddlTask; }
#line 1981 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 6:
#line 105 "parser.ypp" /* yacc.c:1646  */
    { (yyval.rddlTask) = (yyvsp[-1].rddlTask); }
#line 1987 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 106 "parser.ypp" /* yacc.c:1646  */
    { (yyval.rddlTask) = (yyvsp[-1].rddlTask); }
#line 1993 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 107 "parser.ypp" /* yacc.c:1646  */
    { (yyval.rddlTask) = (yyvsp[-1].rddlTask); }
#line 1999 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 115 "parser.ypp" /* yacc.c:1646  */
    {  rddlTask->domainName = *(yyvsp[-3].str); }
#line 2005 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 121 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2011 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 122 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2017 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 123 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2023 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 124 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2029 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 125 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2035 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 126 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2041 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 127 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2047 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 128 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Action precondition section not implemented yet."); }
#line 2053 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 129 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("State invariant section not implemented yet.");  }
#line 2059 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 130 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2065 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 131 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2071 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 132 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2077 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 133 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2083 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 134 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2089 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 135 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2095 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 136 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2101 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 137 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Action precondition section not implemented yet."); }
#line 2107 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 138 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("State invariant section not implemented yet.");  }
#line 2113 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 143 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2119 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 144 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2125 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 147 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2131 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 148 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2137 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 154 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2143 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 157 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2149 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 158 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2155 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 162 "parser.ypp" /* yacc.c:1646  */
    { rddlTask->addType(*(yyvsp[-3].str), *(yyvsp[-1].str)); }
#line 2161 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 163 "parser.ypp" /* yacc.c:1646  */
    { rddlTask->addType(*(yyvsp[-3].str), *(yyvsp[-1].str)); }
#line 2167 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 164 "parser.ypp" /* yacc.c:1646  */
    { rddlTask->addType(*(yyvsp[-5].str));
                                                                                  for (const std::string& s : *(yyvsp[-2].strs)) {
                                                                                      rddlTask->addObject(*(yyvsp[-5].str), s);
                                                                                  }}
#line 2176 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 168 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Defining types using Enum range error. Not implemented yet.") ; }
#line 2182 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 169 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Defining types using TypeSpecification error. Not implemented yet.") ;}
#line 2188 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 170 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Defining types using StructMemberList error. Not implemented yet.") ;}
#line 2194 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 173 "parser.ypp" /* yacc.c:1646  */
    { (yyval.strs) = new std::vector<std::string>(); (yyval.strs)->push_back(*(yyvsp[0].str)); }
#line 2200 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 174 "parser.ypp" /* yacc.c:1646  */
    { (yyval.strs) = (yyvsp[0].strs); (yyval.strs)->insert((yyval.strs)->begin(), *(yyvsp[-2].str)); }
#line 2206 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 177 "parser.ypp" /* yacc.c:1646  */
    { (yyval.type) = rddlTask->getType(*(yyvsp[0].str)); }
#line 2212 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 178 "parser.ypp" /* yacc.c:1646  */
    { (yyval.type) = rddlTask->getType(*(yyvsp[0].str)); }
#line 2218 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 179 "parser.ypp" /* yacc.c:1646  */
    { (yyval.type) = rddlTask->getType(*(yyvsp[0].str)); }
#line 2224 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 180 "parser.ypp" /* yacc.c:1646  */
    { (yyval.type) = rddlTask->getType(*(yyvsp[0].str)); }
#line 2230 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 183 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("StructMemberList not implemented yet."); }
#line 2236 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 184 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("StructMemberList not implemented yet."); }
#line 2242 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 187 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new NumericConstant((yyvsp[0].d));  }
#line 2248 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 188 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new NumericConstant((yyvsp[0].i));  }
#line 2254 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 189 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new Parameter(*(yyvsp[0].str));       }
#line 2260 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 190 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new NumericConstant(1.0); }
#line 2266 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 191 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new NumericConstant(0.0); }
#line 2272 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 192 "parser.ypp" /* yacc.c:1646  */
    { assert(rddlTask->objects.find(*(yyvsp[0].str)) != rddlTask->objects.end()); (yyval.logicalExpression) = rddlTask->objects[*(yyvsp[0].str)]; }
#line 2278 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 198 "parser.ypp" /* yacc.c:1646  */
    { (yyval.parametrizedVariables) = (yyvsp[-2].parametrizedVariables); }
#line 2284 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 201 "parser.ypp" /* yacc.c:1646  */
    { (yyval.parametrizedVariables) = new std::vector<ParametrizedVariable*>(); (yyval.parametrizedVariables)->push_back((yyvsp[0].parametrizedVariable)); }
#line 2290 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 202 "parser.ypp" /* yacc.c:1646  */
    { (yyval.parametrizedVariables) = (yyvsp[0].parametrizedVariables); (yyval.parametrizedVariables)->insert((yyval.parametrizedVariables)->begin(), (yyvsp[-1].parametrizedVariable)); }
#line 2296 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 205 "parser.ypp" /* yacc.c:1646  */
    { (yyval.parametrizedVariable) = new ParametrizedVariable(*(yyvsp[-11].str), *(yyvsp[-10].parameters), ParametrizedVariable::STATE_FLUENT, (yyvsp[-6].type), (yyvsp[-2].d)); rddlTask->addVariableSchematic((yyval.parametrizedVariable)); }
#line 2302 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 206 "parser.ypp" /* yacc.c:1646  */
    { (yyval.parametrizedVariable) = new ParametrizedVariable(*(yyvsp[-11].str), *(yyvsp[-10].parameters), ParametrizedVariable::NON_FLUENT, (yyvsp[-6].type), (yyvsp[-2].d)); rddlTask->addVariableSchematic((yyval.parametrizedVariable)); }
#line 2308 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 207 "parser.ypp" /* yacc.c:1646  */
    { (yyval.parametrizedVariable) = new ParametrizedVariable(*(yyvsp[-11].str), *(yyvsp[-10].parameters), ParametrizedVariable::ACTION_FLUENT, (yyvsp[-6].type),  (yyvsp[-2].d)); rddlTask->addVariableSchematic((yyval.parametrizedVariable)); }
#line 2314 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 208 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("interm-fluent parametrized variables definition not implemented. "); }
#line 2320 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 209 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("derived-fluent parametrized variables definition not implemented. "); }
#line 2326 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 210 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("interm-fluent parametrized variables definition not implemented. "); }
#line 2332 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 211 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("derived-fluent parametrized variables definition not implemented. "); }
#line 2338 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 212 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("observ-fluent parametrized variables definition not implemented. "); }
#line 2344 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 215 "parser.ypp" /* yacc.c:1646  */
    { (yyval.parameters) = new std::vector<Parameter*>(); }
#line 2350 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 216 "parser.ypp" /* yacc.c:1646  */
    { (yyval.parameters) = (yyvsp[-2].parameters); }
#line 2356 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 219 "parser.ypp" /* yacc.c:1646  */
    { (yyval.parameters) = new std::vector<Parameter*>(); (yyval.parameters)->push_back(new Parameter((yyvsp[0].type)->name, (yyvsp[0].type))); }
#line 2362 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 220 "parser.ypp" /* yacc.c:1646  */
    { (yyval.parameters) = (yyvsp[0].parameters); (yyval.parameters)->insert((yyval.parameters)->begin(), new Parameter((yyvsp[-2].type)->name, (yyvsp[-2].type))); }
#line 2368 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 223 "parser.ypp" /* yacc.c:1646  */
    { (yyval.d) = (*(yyvsp[0].str) == "true") ? 1 : 0; }
#line 2374 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 224 "parser.ypp" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 2380 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 225 "parser.ypp" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 2386 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 226 "parser.ypp" /* yacc.c:1646  */
    { Object* obj = rddlTask->getObject(*(yyvsp[0].str)); (yyval.d) = obj->value; }
#line 2392 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 74:
#line 227 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Range constant variable with tag '$' definition implemented yet."); }
#line 2398 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 228 "parser.ypp" /* yacc.c:1646  */
    { assert(rddlTask->objects.find(*(yyvsp[0].str)) != rddlTask->objects.end()); (yyval.d) = rddlTask->objects[*(yyvsp[0].str)]->value; }
#line 2404 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 76:
#line 229 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("< Structured ranged constatnts > not implemented yet."); }
#line 2410 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 77:
#line 230 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("(< Structured ranged constatnts >) not implemented yet."); }
#line 2416 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 78:
#line 231 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("[< Structured ranged constatnts >] not implemented yet."); }
#line 2422 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 235 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("StructRangeConsant not implemented yet."); }
#line 2428 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 80:
#line 236 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("StructRangeConsant not implemented yet."); }
#line 2434 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 81:
#line 239 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("StructRangeConsantList not implemented yet."); }
#line 2440 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 82:
#line 240 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("StructRangeConsantList not implemented yet."); }
#line 2446 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 83:
#line 243 "parser.ypp" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2452 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 84:
#line 244 "parser.ypp" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2458 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 85:
#line 247 "parser.ypp" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 2464 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 86:
#line 248 "parser.ypp" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].d); }
#line 2470 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 87:
#line 249 "parser.ypp" /* yacc.c:1646  */
    { (yyval.d) = std::numeric_limits<double>::infinity(); }
#line 2476 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 88:
#line 250 "parser.ypp" /* yacc.c:1646  */
    { (yyval.d) = -std::numeric_limits<double>::infinity();}
#line 2482 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 89:
#line 253 "parser.ypp" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].i);  }
#line 2488 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 90:
#line 254 "parser.ypp" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].i); }
#line 2494 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 91:
#line 261 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2500 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 92:
#line 264 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2506 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 93:
#line 265 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2512 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 94:
#line 268 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2518 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 95:
#line 269 "parser.ypp" /* yacc.c:1646  */
    { }
#line 2524 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 96:
#line 272 "parser.ypp" /* yacc.c:1646  */
    { rddlTask->addCPF(*(yyvsp[-3].parametrizedVariable), (yyvsp[-1].logicalExpression)); }
#line 2530 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 97:
#line 275 "parser.ypp" /* yacc.c:1646  */
    {
                                                      std::string varName;
                                                      if ((*(yyvsp[0].str))[(yyvsp[0].str)->length() - 1] == '\'')
                                                        varName = (yyvsp[0].str)->substr(0, (yyvsp[0].str)->length() - 1);
                                                      else
                                                        varName = *(yyvsp[0].str);

                                                      if (rddlTask->variableDefinitions.find(varName) != rddlTask->variableDefinitions.end()) {
                                                        (yyval.parametrizedVariable) = rddlTask->variableDefinitions[varName];
                                                      } else {
                                                        SystemUtils::abort("Unknown parametrized variable " + varName + ".");
                                                      }
                                                      (yyval.parametrizedVariable) = new ParametrizedVariable(*(rddlTask->variableDefinitions[varName]), std::vector<Parameter*>());
                                                    }
#line 2549 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 98:
#line 289 "parser.ypp" /* yacc.c:1646  */
    {
                                                      std::string varName;
                                                      if ((*(yyvsp[-3].str))[(yyvsp[-3].str)->length() - 1] == '\'')
                                                        varName = (yyvsp[-3].str)->substr(0, (yyvsp[-3].str)->length() - 1);
                                                      else
                                                        varName = *(yyvsp[-3].str);
                                                      if (rddlTask->variableDefinitions.find(varName) != rddlTask->variableDefinitions.end()) {
                                                        (yyval.parametrizedVariable) = rddlTask->variableDefinitions[varName];
                                                      } else {
                                                        SystemUtils::abort("Unknown parametrized variable " + varName + ".");
                                                      }
                                                      (yyval.parametrizedVariable) = new ParametrizedVariable(*(rddlTask->variableDefinitions[varName]), *(yyvsp[-1].parameters));
                                                    }
#line 2567 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 99:
#line 302 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Undefined variable: " + *(yyvsp[-1].str) + ". Syntax not implemented yet.");     }
#line 2573 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 100:
#line 303 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Undefined variable: " + *(yyvsp[-4].str) + ". Syntax not implemented yet.");     }
#line 2579 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 101:
#line 304 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Undefined variable: " + *(yyvsp[-2].str) + ". Syntax not implemented yet.");     }
#line 2585 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 102:
#line 307 "parser.ypp" /* yacc.c:1646  */
    { (yyval.parameters) = new std::vector<Parameter*>(); (yyval.parameters)->push_back((yyvsp[0].parameter)); }
#line 2591 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 103:
#line 308 "parser.ypp" /* yacc.c:1646  */
    { (yyval.parameters) = (yyvsp[0].parameters); (yyval.parameters)->insert((yyval.parameters)->begin(), (yyvsp[-2].parameter)); }
#line 2597 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 104:
#line 311 "parser.ypp" /* yacc.c:1646  */
    { (yyval.parameter) = new Parameter(*(yyvsp[0].str)); }
#line 2603 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 105:
#line 312 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Definition of Term using parametrized variable not implemented yet."); }
#line 2609 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 106:
#line 313 "parser.ypp" /* yacc.c:1646  */
    { assert(rddlTask->objects.find(*(yyvsp[0].str)) != rddlTask->objects.end()); (yyval.parameter) = rddlTask->objects[*(yyvsp[0].str)]; }
#line 2615 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 107:
#line 314 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Definition of Term using variable with '$' sign not implemented yet."); }
#line 2621 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 108:
#line 317 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("MemberList not implemented yet."); }
#line 2627 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 109:
#line 318 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("MemberList not implemented yet."); }
#line 2633 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 110:
#line 321 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Pterm not implemented yet."); }
#line 2639 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 111:
#line 322 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Pterm not implemented yet."); }
#line 2645 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 112:
#line 323 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Pterm not implemented yet."); }
#line 2651 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 113:
#line 324 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Pterm not implemented yet."); }
#line 2657 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 114:
#line 325 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Pterm not implemented yet."); }
#line 2663 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 115:
#line 333 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new Parameter(*(yyvsp[0].str)); }
#line 2669 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 116:
#line 334 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = (yyvsp[0].parametrizedVariable); }
#line 2675 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 117:
#line 335 "parser.ypp" /* yacc.c:1646  */
    { assert(rddlTask->objects.find(*(yyvsp[0].str)) != rddlTask->objects.end()); (yyval.logicalExpression) = rddlTask->objects[*(yyvsp[0].str)]; }
#line 2681 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 118:
#line 336 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("'$<variable_name>' not implemented yet."); }
#line 2687 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 119:
#line 337 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Structured expression list not implemented yet."); }
#line 2693 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 120:
#line 339 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Unknow special function " + *(yyvsp[-3].str) + " defined as expression. Special functions not implemented yet."); }
#line 2699 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 121:
#line 340 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new UniversalQuantification((yyvsp[-2].parameterList), (yyvsp[0].logicalExpression)); }
#line 2705 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 122:
#line 341 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new ExistentialQuantification((yyvsp[-2].parameterList), (yyvsp[0].logicalExpression));}
#line 2711 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 123:
#line 342 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new Sumation((yyvsp[-2].parameterList), (yyvsp[0].logicalExpression)); }
#line 2717 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 124:
#line 343 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new Product((yyvsp[-2].parameterList), (yyvsp[0].logicalExpression)); }
#line 2723 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 125:
#line 344 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new IfThenElseExpression((yyvsp[-5].logicalExpression), (yyvsp[-2].logicalExpression), (yyvsp[0].logicalExpression)); }
#line 2729 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 126:
#line 345 "parser.ypp" /* yacc.c:1646  */
    { // TODO: Text switch case control
                                                                                                   LogicalExpression* switchVar = rddlTask->getParametrizedVariable((yyvsp[-4].parameter)->name);

                                                                                                    std::vector<LogicalExpression*> conditions;
                                                                                                    std::vector<LogicalExpression*> effects;
                                                                                                    for (ConditionEffectPair* cs : *(yyvsp[-1].conditionEffects)) {
                                                                                                        if (!cs->first) {
                                                                                                            // If we reached the end of switch case and instead of 'case', we have 'default' -> default action
                                                                                                            conditions.push_back(new NumericConstant(1.0));
                                                                                                        }
                                                                                                        else {
                                                                                                            std::vector<LogicalExpression*> switchVarEquality;
                                                                                                            switchVarEquality.push_back(switchVar);
                                                                                                            switchVarEquality.push_back(cs->first);
                                                                                                            conditions.push_back(new EqualsExpression(switchVarEquality));
                                                                                                        }
                                                                                                        effects.push_back(cs->second);
                                                                                                    }
                                                                                                    (yyval.logicalExpression) = new MultiConditionChecker(conditions, effects);
                                                                                                }
#line 2754 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 127:
#line 366 "parser.ypp" /* yacc.c:1646  */
    { std::vector<LogicalExpression*> exprs; exprs.push_back((yyvsp[-2].logicalExpression)); exprs.push_back((yyvsp[0].logicalExpression)); (yyval.logicalExpression) = new Addition(exprs); }
#line 2760 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 128:
#line 367 "parser.ypp" /* yacc.c:1646  */
    { std::vector<LogicalExpression*> exprs; exprs.push_back(new NumericConstant(0.0)); exprs.push_back((yyvsp[0].logicalExpression)); (yyval.logicalExpression) = new Subtraction(exprs); }
#line 2766 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 129:
#line 368 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = (yyvsp[0].logicalExpression); }
#line 2772 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 130:
#line 369 "parser.ypp" /* yacc.c:1646  */
    { std::vector<LogicalExpression*> exprs; exprs.push_back((yyvsp[-2].logicalExpression)); exprs.push_back((yyvsp[0].logicalExpression)); (yyval.logicalExpression) = new Subtraction(exprs); }
#line 2778 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 131:
#line 370 "parser.ypp" /* yacc.c:1646  */
    { std::vector<LogicalExpression*> exprs; exprs.push_back((yyvsp[-2].logicalExpression)); exprs.push_back((yyvsp[0].logicalExpression)); (yyval.logicalExpression) = new Multiplication(exprs); }
#line 2784 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 132:
#line 371 "parser.ypp" /* yacc.c:1646  */
    { std::vector<LogicalExpression*> exprs; exprs.push_back((yyvsp[-2].logicalExpression)); exprs.push_back((yyvsp[0].logicalExpression)); (yyval.logicalExpression) = new Division(exprs); }
#line 2790 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 133:
#line 372 "parser.ypp" /* yacc.c:1646  */
    { std::vector<LogicalExpression*> exprs; exprs.push_back((yyvsp[-2].logicalExpression)); exprs.push_back((yyvsp[0].logicalExpression)); (yyval.logicalExpression) = new GreaterExpression(exprs); }
#line 2796 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 134:
#line 373 "parser.ypp" /* yacc.c:1646  */
    { std::vector<LogicalExpression*> exprs; exprs.push_back((yyvsp[-2].logicalExpression)); exprs.push_back((yyvsp[0].logicalExpression)); (yyval.logicalExpression) = new LowerExpression(exprs); }
#line 2802 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 135:
#line 374 "parser.ypp" /* yacc.c:1646  */
    { std::vector<LogicalExpression*> exprs; exprs.push_back((yyvsp[-2].logicalExpression)); exprs.push_back((yyvsp[0].logicalExpression)); (yyval.logicalExpression) = new LowerEqualsExpression(exprs); }
#line 2808 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 136:
#line 375 "parser.ypp" /* yacc.c:1646  */
    { std::vector<LogicalExpression*> exprs; exprs.push_back((yyvsp[-2].logicalExpression)); exprs.push_back((yyvsp[0].logicalExpression)); (yyval.logicalExpression) = new GreaterEqualsExpression(exprs); }
#line 2814 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 137:
#line 376 "parser.ypp" /* yacc.c:1646  */
    { std::vector<LogicalExpression*> exprs; exprs.push_back((yyvsp[-2].logicalExpression)); exprs.push_back((yyvsp[0].logicalExpression)); (yyval.logicalExpression) = new EqualsExpression(exprs); }
#line 2820 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 138:
#line 377 "parser.ypp" /* yacc.c:1646  */
    { std::vector<LogicalExpression*> exprs; exprs.push_back((yyvsp[-2].logicalExpression)); exprs.push_back((yyvsp[0].logicalExpression)); (yyval.logicalExpression) = new Negation(new EqualsExpression(exprs)); }
#line 2826 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 139:
#line 378 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = (yyvsp[-1].logicalExpression); }
#line 2832 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 140:
#line 379 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = (yyvsp[-1].logicalExpression); }
#line 2838 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 141:
#line 380 "parser.ypp" /* yacc.c:1646  */
    { std::vector<LogicalExpression*> exprs; exprs.push_back((yyvsp[-2].logicalExpression)); exprs.push_back((yyvsp[0].logicalExpression)); (yyval.logicalExpression) = new Conjunction(exprs); }
#line 2844 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 142:
#line 381 "parser.ypp" /* yacc.c:1646  */
    { std::vector<LogicalExpression*> exprs; exprs.push_back((yyvsp[-2].logicalExpression)); exprs.push_back((yyvsp[0].logicalExpression)); (yyval.logicalExpression) = new Conjunction(exprs); }
#line 2850 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 143:
#line 382 "parser.ypp" /* yacc.c:1646  */
    { std::vector<LogicalExpression*> exprs; exprs.push_back((yyvsp[-2].logicalExpression)); exprs.push_back((yyvsp[0].logicalExpression)); (yyval.logicalExpression) = new Disjunction(exprs); }
#line 2856 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 144:
#line 383 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new Negation((yyvsp[0].logicalExpression)); }
#line 2862 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 145:
#line 384 "parser.ypp" /* yacc.c:1646  */
    { std::vector<LogicalExpression*> posExprs, negExprs, exprs; posExprs.push_back((yyvsp[-2].logicalExpression)); negExprs.push_back((yyvsp[0].logicalExpression)); exprs.push_back(new Conjunction(posExprs)); exprs.push_back(new Conjunction(posExprs)); (yyval.logicalExpression) = new Disjunction(exprs); }
#line 2868 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 146:
#line 385 "parser.ypp" /* yacc.c:1646  */
    { std::vector<LogicalExpression*> exprs; exprs.push_back(new Negation((yyvsp[-2].logicalExpression))); exprs.push_back((yyvsp[0].logicalExpression)); (yyval.logicalExpression) = new Disjunction(exprs); }
#line 2874 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 147:
#line 386 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new NumericConstant((yyvsp[0].d)); }
#line 2880 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 148:
#line 387 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new NumericConstant((yyvsp[0].i)); }
#line 2886 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 149:
#line 388 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new NumericConstant(1.0); }
#line 2892 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 150:
#line 389 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new NumericConstant(0.0); }
#line 2898 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 151:
#line 390 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new ExponentialFunction((yyvsp[-1].logicalExpression)); }
#line 2904 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 152:
#line 391 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new ExponentialFunction((yyvsp[-1].logicalExpression)); }
#line 2910 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 153:
#line 394 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new BernoulliDistribution((yyvsp[-1].logicalExpression)); }
#line 2916 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 154:
#line 395 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = new KronDeltaDistribution((yyvsp[-1].logicalExpression)); }
#line 2922 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 155:
#line 396 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpression) = (yyvsp[-1].lConstCaseList); }
#line 2928 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 156:
#line 397 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("DiracDelta not implemtend."); }
#line 2934 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 157:
#line 398 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Uniform not implemtend."); }
#line 2940 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 158:
#line 399 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Normal not implemtend."); }
#line 2946 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 159:
#line 400 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Dirichelt not implemtend."); }
#line 2952 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 160:
#line 401 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Poisson not implemtend."); }
#line 2958 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 161:
#line 402 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Weibull not implemtend."); }
#line 2964 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 162:
#line 403 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Gama not implemtend.");  }
#line 2970 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 163:
#line 404 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Multinomial not implemtend."); }
#line 2976 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 164:
#line 407 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("StructExpressionList not implemented yet."); }
#line 2982 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 165:
#line 408 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("StructExpressionList not implemented yet."); }
#line 2988 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 166:
#line 411 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpressions) = new std::vector<LogicalExpression*>(); (yyval.logicalExpressions)->push_back((yyvsp[0].logicalExpression)); }
#line 2994 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 167:
#line 412 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpressions) = (yyvsp[0].logicalExpressions); (yyval.logicalExpressions)->insert((yyval.logicalExpressions)->begin(), (yyvsp[-2].logicalExpression)); }
#line 3000 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 168:
#line 415 "parser.ypp" /* yacc.c:1646  */
    { (yyval.parameterList) = new ParameterList({}, {}); (yyval.parameterList)->params.push_back(new Parameter((yyvsp[0].parameter)->name, (yyvsp[0].parameter)->type)); (yyval.parameterList)->types.push_back((yyvsp[0].parameter)->type); }
#line 3006 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 169:
#line 416 "parser.ypp" /* yacc.c:1646  */
    { (yyval.parameterList) = (yyvsp[0].parameterList); (yyval.parameterList)->params.insert((yyval.parameterList)->params.begin(), new Parameter((yyvsp[-2].parameter)->name, (yyvsp[-2].parameter)->type)); (yyval.parameterList)->types.insert((yyval.parameterList)->types.begin(), (yyvsp[-2].parameter)->type); }
#line 3012 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 170:
#line 419 "parser.ypp" /* yacc.c:1646  */
    { if (rddlTask->getType(*(yyvsp[0].str))) {
                                     (yyval.parameter) = new Parameter(*(yyvsp[-2].str), rddlTask->getType(*(yyvsp[0].str)));
                                   }
                                   else {
                                        SystemUtils::abort("Type " + *(yyvsp[0].str) + " not defined");
                                   }
                                 }
#line 3024 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 171:
#line 428 "parser.ypp" /* yacc.c:1646  */
    { (yyval.conditionEffects) = new std::vector<ConditionEffectPair*>(); (yyval.conditionEffects)->push_back((yyvsp[0].conditionEffect)); }
#line 3030 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 172:
#line 429 "parser.ypp" /* yacc.c:1646  */
    { (yyval.conditionEffects) = (yyvsp[0].conditionEffects); (yyval.conditionEffects)->insert((yyval.conditionEffects)->begin(), (yyvsp[-2].conditionEffect)); }
#line 3036 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 173:
#line 432 "parser.ypp" /* yacc.c:1646  */
    { LogicalExpression* var = rddlTask->getParametrizedVariable((yyvsp[-2].parameter)->name); (yyval.conditionEffect) = new ConditionEffectPair(var, (yyvsp[0].logicalExpression)); }
#line 3042 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 174:
#line 433 "parser.ypp" /* yacc.c:1646  */
    { (yyval.conditionEffect) = new ConditionEffectPair(nullptr, (yyvsp[0].logicalExpression)); }
#line 3048 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 175:
#line 437 "parser.ypp" /* yacc.c:1646  */
    { (yyval.lConstCaseList) = new DiscreteDistribution(); (yyval.lConstCaseList)->values.push_back((yyvsp[-2].logicalExpression)); (yyval.lConstCaseList)->probabilities.push_back((yyvsp[0].logicalExpression)); }
#line 3054 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 176:
#line 438 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Key word 'otherwise' not supported yet"); }
#line 3060 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 177:
#line 439 "parser.ypp" /* yacc.c:1646  */
    { (yyval.lConstCaseList) = (yyvsp[0].lConstCaseList); (yyval.lConstCaseList)->values.insert((yyval.lConstCaseList)->values.begin(), (yyvsp[-4].logicalExpression)); (yyval.lConstCaseList)->probabilities.insert((yyval.lConstCaseList)->probabilities.begin(), (yyvsp[-2].logicalExpression)); }
#line 3066 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 178:
#line 445 "parser.ypp" /* yacc.c:1646  */
    { rddlTask->setRewardCPF((yyvsp[-1].logicalExpression)); }
#line 3072 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 179:
#line 452 "parser.ypp" /* yacc.c:1646  */
    { }
#line 3078 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 180:
#line 453 "parser.ypp" /* yacc.c:1646  */
    { }
#line 3084 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 181:
#line 456 "parser.ypp" /* yacc.c:1646  */
    { }
#line 3090 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 182:
#line 457 "parser.ypp" /* yacc.c:1646  */
    { }
#line 3096 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 183:
#line 460 "parser.ypp" /* yacc.c:1646  */
    { rddlTask->SACs.push_back((yyvsp[-1].logicalExpression)); }
#line 3102 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 184:
#line 466 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Action prediction not implemented yet."); }
#line 3108 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 185:
#line 467 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Action prediction not implemented yet."); }
#line 3114 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 189:
#line 480 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("State invariant not implemented yet."); }
#line 3120 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 190:
#line 481 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("State invariant not implemented yet."); }
#line 3126 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 194:
#line 494 "parser.ypp" /* yacc.c:1646  */
    { }
#line 3132 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 195:
#line 498 "parser.ypp" /* yacc.c:1646  */
    { }
#line 3138 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 196:
#line 499 "parser.ypp" /* yacc.c:1646  */
    { }
#line 3144 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 197:
#line 502 "parser.ypp" /* yacc.c:1646  */
    {
                                                              for (std::string str : *(yyvsp[-2].strs)) {
                                                                rddlTask->addObject(*(yyvsp[-5].str), str);
                                                              }
                                                         }
#line 3154 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 198:
#line 509 "parser.ypp" /* yacc.c:1646  */
    { (yyval.strs) = new std::vector<std::string>(); (yyval.strs)->push_back(*(yyvsp[0].str)); }
#line 3160 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 199:
#line 510 "parser.ypp" /* yacc.c:1646  */
    { (yyval.strs) = (yyvsp[0].strs); (yyval.strs)->insert((yyval.strs)->begin(), *(yyvsp[-2].str)); }
#line 3166 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 200:
#line 511 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Definition of an object using '$' not implemented yet."); }
#line 3172 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 201:
#line 512 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Definition of an object using '$' not implemented yet."); }
#line 3178 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 202:
#line 524 "parser.ypp" /* yacc.c:1646  */
    {
                    rddlTask->nonFluentsName = *(yyvsp[-16].str);
                    if (rddlTask->domainName != *(yyvsp[-12].str)) {
                        SystemUtils::abort("Unknown domain " + *(yyvsp[-12].str) +
                                           "  defined in Non fluent section");
                    }
                }
#line 3190 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 203:
#line 534 "parser.ypp" /* yacc.c:1646  */
    {
                    rddlTask->nonFluentsName = *(yyvsp[-11].str);
                    if (rddlTask->domainName != *(yyvsp[-7].str)) {
                        SystemUtils::abort("Unknown domain " + *(yyvsp[-7].str) +
                                           "  defined in Non fluent section");
                    }
                }
#line 3202 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 204:
#line 543 "parser.ypp" /* yacc.c:1646  */
    { }
#line 3208 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 205:
#line 544 "parser.ypp" /* yacc.c:1646  */
    { }
#line 3214 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 206:
#line 548 "parser.ypp" /* yacc.c:1646  */
    {
                                                                                ParametrizedVariable* parent = rddlTask->getParametrizedVariable(*(yyvsp[-4].str));
                                                                                std::vector<Parameter*> params;
                                                                                for (LogicalExpression* le : *(yyvsp[-2].logicalExpressions)) {
                                                                                    Parameter* param = dynamic_cast<Parameter*>(le);
                                                                                    if (!param) {
                                                                                        SystemUtils::abort("Passing anything other than Parameter object to ParametrizedVariable is not allowed.");
                                                                                    }
                                                                                    params.push_back(rddlTask->getObject(param->name));
                                                                                }
                                                                                rddlTask->addParametrizedVariable(parent, params, 1);
                                                                              }
#line 3231 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 207:
#line 560 "parser.ypp" /* yacc.c:1646  */
    { ParametrizedVariable* parent = rddlTask->getParametrizedVariable(*(yyvsp[-1].str)); rddlTask->addParametrizedVariable(parent,  {}, 1); }
#line 3237 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 208:
#line 561 "parser.ypp" /* yacc.c:1646  */
    {
                                                                                ParametrizedVariable* parent = rddlTask->getParametrizedVariable(*(yyvsp[-4].str));
                                                                                std::vector<Parameter*> params;
                                                                                for (LogicalExpression* le : *(yyvsp[-2].logicalExpressions)) {
                                                                                    Parameter* param = dynamic_cast<Parameter*>(le);
                                                                                    if (!param) {
                                                                                        SystemUtils::abort("Passing anything other than Parameter object to ParametrizedVariable is not allowed.");
                                                                                    }
                                                                                    params.push_back(rddlTask->getObject(param->name));
                                                                                }
                                                                                rddlTask->addParametrizedVariable(parent, params, 0);
                                                                              }
#line 3254 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 209:
#line 573 "parser.ypp" /* yacc.c:1646  */
    { ParametrizedVariable* parent = rddlTask->getParametrizedVariable(*(yyvsp[0].str)); rddlTask->addParametrizedVariable(parent,  {}, 0); }
#line 3260 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 210:
#line 574 "parser.ypp" /* yacc.c:1646  */
    {
                                                                                ParametrizedVariable* parent = rddlTask->getParametrizedVariable(*(yyvsp[-6].str));
                                                                                std::vector<Parameter*> params;
                                                                                for (LogicalExpression* le : *(yyvsp[-4].logicalExpressions)) {
                                                                                    Parameter* param = dynamic_cast<Parameter*>(le);
                                                                                    if (!param) {
                                                                                        SystemUtils::abort("Passing anything other than Parameter object to ParametrizedVariable is not allowed.");
                                                                                    }
                                                                                    params.push_back(rddlTask->getObject(param->name));
                                                                                }
                                                                                rddlTask->addParametrizedVariable(parent, params, (yyvsp[-1].d));
                                                                              }
#line 3277 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 211:
#line 586 "parser.ypp" /* yacc.c:1646  */
    { ParametrizedVariable* parent = rddlTask->getParametrizedVariable(*(yyvsp[-3].str)); rddlTask->addParametrizedVariable(parent,  {}, (yyvsp[-1].d));}
#line 3283 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 212:
#line 589 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpressions) = new std::vector<LogicalExpression*>(); (yyval.logicalExpressions)->push_back((yyvsp[0].logicalExpression)); }
#line 3289 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 213:
#line 590 "parser.ypp" /* yacc.c:1646  */
    { (yyval.logicalExpressions) = (yyvsp[0].logicalExpressions); (yyval.logicalExpressions)->insert((yyval.logicalExpressions)->begin(), (yyvsp[-2].logicalExpression)); }
#line 3295 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 214:
#line 608 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Definition of instance block with definition of objects not implemented yet."); }
#line 3301 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 215:
#line 617 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Definition of instance block with definition of objects not implemented yet."); }
#line 3307 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 216:
#line 626 "parser.ypp" /* yacc.c:1646  */
    { rddlTask->setInstance(*(yyvsp[-25].str), *(yyvsp[-21].str), *(yyvsp[-17].str), (yyvsp[-8].i), (yyvsp[-6].i), (yyvsp[-2].d)); }
#line 3313 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 217:
#line 634 "parser.ypp" /* yacc.c:1646  */
    { rddlTask->setInstance(*(yyvsp[-21].str), *(yyvsp[-17].str), "", (yyvsp[-8].i), (yyvsp[-6].i), (yyvsp[-2].d)); }
#line 3319 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 218:
#line 643 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Definition of instance block with definition of objects not implemented yet."); }
#line 3325 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 219:
#line 651 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Definition of instance block with definition of objects not implemented yet."); }
#line 3331 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 220:
#line 659 "parser.ypp" /* yacc.c:1646  */
    {  rddlTask->setInstance(*(yyvsp[-20].str), *(yyvsp[-16].str), *(yyvsp[-12].str), (yyvsp[-8].i), (yyvsp[-6].i), (yyvsp[-2].d));  }
#line 3337 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 221:
#line 666 "parser.ypp" /* yacc.c:1646  */
    { rddlTask->setInstance(*(yyvsp[-16].str), *(yyvsp[-12].str), "", (yyvsp[-8].i), (yyvsp[-6].i), (yyvsp[-2].d)); }
#line 3343 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 222:
#line 677 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Definition of instance block with definition of objects not implemented yet."); }
#line 3349 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 223:
#line 685 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Definition of instance block with definition of objects not implemented yet."); }
#line 3355 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 224:
#line 693 "parser.ypp" /* yacc.c:1646  */
    { rddlTask->setInstance(*(yyvsp[-21].str), *(yyvsp[-17].str), *(yyvsp[-13].str), -1, (yyvsp[-6].i), (yyvsp[-2].d)); }
#line 3361 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 225:
#line 700 "parser.ypp" /* yacc.c:1646  */
    { rddlTask->setInstance(*(yyvsp[-17].str), *(yyvsp[-13].str), "", -1, (yyvsp[-6].i), (yyvsp[-2].d)); }
#line 3367 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 226:
#line 708 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Definition of instance block with definition of objects not implemented yet."); }
#line 3373 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 227:
#line 715 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Definition of instance block with definition of objects not implemented yet."); }
#line 3379 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 228:
#line 722 "parser.ypp" /* yacc.c:1646  */
    { rddlTask->setInstance(*(yyvsp[-16].str), *(yyvsp[-12].str), *(yyvsp[-8].str), -1, (yyvsp[-6].i), (yyvsp[-2].d)); }
#line 3385 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 229:
#line 728 "parser.ypp" /* yacc.c:1646  */
    { rddlTask->setInstance(*(yyvsp[-12].str), *(yyvsp[-8].str), "", -1, (yyvsp[-6].i), (yyvsp[-2].d)); }
#line 3391 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 230:
#line 732 "parser.ypp" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3397 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 231:
#line 733 "parser.ypp" /* yacc.c:1646  */
    { SystemUtils::abort("Definition of horizon using 'terminate-when' token not implemented yet."); }
#line 3403 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 232:
#line 736 "parser.ypp" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3409 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 233:
#line 737 "parser.ypp" /* yacc.c:1646  */
    { (yyval.i) = std::numeric_limits<int>::max(); }
#line 3415 "parser.tab.cc" /* yacc.c:1646  */
    break;


#line 3419 "parser.tab.cc" /* yacc.c:1646  */
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
#line 740 "parser.ypp" /* yacc.c:1906  */


bool CheckExtension(std::string s) {
     return ((s.length() > 5) &&  (s.substr(s.length() - 5).compare(".rddl") == 0));
}

int main (int argc, char** argv) {
    // Debuging on/off
    // yydebug = 1;
    if (argc < 4) {
        SystemUtils::abort("Usage: ./rddl_parse <rddlDomain> <rddlProblem> <targetDir>");
    }

    // Checking input file
    if (!CheckExtension(argv[1]) || !CheckExtension(argv[2])) {
        SystemUtils::abort("Invalid file type.\nUsage: ./rddl_parse <rddlDomain> <rddlProblem> <targetDir>");
    }

    std::ifstream domain(argv[1], std::ifstream::in);
    std::ifstream nfAndInst(argv[2], std::ifstream::in);
    std::ofstream combined(".combined", std::ifstream::out);

    targetDir = argv[3];

    if (domain && nfAndInst) {
        combined << domain.rdbuf() << nfAndInst.rdbuf();
        combined.close();
    } else {
        SystemUtils::abort("Error opening files. Check the correctnes of files.");
    }

    // Creating RDDLTask object
    rddlTask = new RDDLTask();

    yyin = fopen(".combined", "r");
    Timer t, totalTime;
    std::cout << "Parsing..." << std::endl;
    yyparse();
    std::cout << "...finished (" << t << ")." << std::endl;
    fclose(yyin);
    combined.close();
    std::remove(".combined");

    rddlTask->execute(targetDir);
    std::cout << "done ... total time: " << totalTime << std::endl;

    return EXIT_SUCCESS;
}
