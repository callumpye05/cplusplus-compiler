/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 9 "parser.yxx"

#include "ast.hpp"
extern FILE *yyin;
Program* program;
int yyparse();
int yylex (void);
void yyerror (char const *);
std::vector<std::pair<const Expression*, const Instruction*>>
convertElseIf(const std::vector<std::pair<Expression*, Sequence*>>& vec) {
    std::vector<std::pair<const Expression*, const Instruction*>> result;
    for (const auto& p : vec) {
        // Assuming Sequence is convertible to Instruction
        result.push_back({ p.first, p.second });
    }
    return result;
}


#line 89 "parser.tab.cxx"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_HXX_INCLUDED
# define YY_YY_PARSER_TAB_HXX_INCLUDED
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
    ALGORITHME = 258,
    VARIABLES = 259,
    TYPE = 260,
    DEBUT = 261,
    FIN = 262,
    SI = 263,
    ALORS = 264,
    SINON = 265,
    TANT = 266,
    QUE = 267,
    POUR = 268,
    FAIRE = 269,
    ALLANT = 270,
    DE = 271,
    AVEC = 272,
    UN = 273,
    PAS = 274,
    A = 275,
    SINONSI = 276,
    AFFECTATION = 277,
    PT_VIRGULE = 278,
    DEUX_POINTS = 279,
    PARENTHESE_G = 280,
    PARENTHESE_D = 281,
    CROCHET_G = 282,
    CROCHET_D = 283,
    VIRGULE = 284,
    PLUS = 285,
    MOINS = 286,
    MULTIPLIE = 287,
    ET = 288,
    OU = 289,
    EGAL = 290,
    INFERIEUR = 291,
    LITTERAL = 292,
    ID = 293,
    ECRIRE = 294,
    LONGUEUR = 295,
    LIRE = 296,
    NON = 297,
    TABLEAU_TYPE = 298,
    TABLEAU_CTOR = 299,
    FERMETURE_LONGUEUR = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 47 "parser.yxx"

    Instruction* instruction;
    Expression* expression;
    Sequence* sequence;
    algo_types* type;
    std::string* identifier;
    std::vector<Declaration*>* declaration;
    std::vector<Expression*>* expression_list;
    std::vector<std::pair<Expression*, Sequence*>>* elseIfList;  

#line 198 "parser.tab.cxx"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HXX_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   236

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

#define YYUNDEFTOK  2
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    78,    78,    88,    89,   112,   117,   118,   124,   125,
     129,   130,   134,   142,   149,   150,   154,   155,   159,   160,
     161,   162,   163,   164,   165,   166,   172,   187,   192,   197,
     207,   212,   216,   227,   228,   229,   230,   233,   234,   237,
     238,   241,   242,   245,   246,   247,   250,   251,   252,   255,
     256,   259,   260,   263,   264,   268,   269,   270,   271
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ALGORITHME", "VARIABLES", "TYPE",
  "DEBUT", "FIN", "SI", "ALORS", "SINON", "TANT", "QUE", "POUR", "FAIRE",
  "ALLANT", "DE", "AVEC", "UN", "PAS", "A", "SINONSI", "AFFECTATION",
  "PT_VIRGULE", "DEUX_POINTS", "PARENTHESE_G", "PARENTHESE_D", "CROCHET_G",
  "CROCHET_D", "VIRGULE", "PLUS", "MOINS", "MULTIPLIE", "ET", "OU", "EGAL",
  "INFERIEUR", "LITTERAL", "ID", "ECRIRE", "LONGUEUR", "LIRE", "NON",
  "TABLEAU_TYPE", "TABLEAU_CTOR", "FERMETURE_LONGUEUR", "$accept", "algo",
  "var_declaration", "primitive_type", "type", "sequence",
  "expression_list", "autres_conditions", "opt_autres_conditions",
  "opt_sinon", "commande", "longueur_expr", "longueur_terme",
  "array_creation", "array_dimensions", "array_access", "expression",
  "disjonction", "conjonction", "negation", "comparison", "somme",
  "produit", "oppose", "indice", "terme", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      23,    34,    10,   -66,   -66,     7,   -66,    30,    67,     1,
     -66,   -17,    56,    32,   -17,    22,   -66,    50,    58,    77,
      55,    -3,    87,   -66,   -66,   -66,   -66,    57,    89,    85,
      93,   -66,   -66,    46,    98,   -66,   -66,   110,   -66,     1,
     -66,   -66,   -66,   113,     3,   -17,   127,    61,   118,   -66,
     -17,   -17,   -17,   129,   -66,   -17,   106,   -17,   -17,    -3,
      -3,    22,    22,    22,    22,    27,   -17,   -66,   -66,     4,
     138,   -66,    27,   132,   -16,    40,    89,    63,    68,   -66,
     135,    89,   140,    69,    73,    93,   -66,    98,    98,    91,
      91,   -66,    97,   171,   -66,   -17,   145,   -66,   -66,   141,
     -17,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -17,   -66,
     148,   107,   -11,   -66,    89,     6,   -66,   166,   164,   -17,
     -66,   192,   168,   165,    44,   171,   -66,   -66,   -66,   160,
     -66,   128,   162,   170,   169,   -66,   -17,     5,   -66,   149,
     181,   -66
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     3,     1,     0,     8,     0,     0,     0,
       2,     0,     0,     0,     0,     0,    55,    56,     0,     0,
       0,     0,     0,     9,    36,    57,    34,     0,     0,    33,
      38,    40,    42,    45,    48,    50,    52,    54,     5,     0,
       6,     4,    56,    35,     0,     0,     0,     0,     0,    51,
       0,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,    58,     0,    34,     0,     0,    10,     0,    54,    20,
       0,    30,     0,     0,     0,    37,    39,    46,    47,    43,
      44,    49,     0,    15,     8,     0,     0,    25,    18,     0,
       0,    27,    28,    29,    26,    32,    31,    53,     0,    14,
      17,     0,     0,    19,    11,     0,     8,     0,     0,     0,
       8,    16,     0,     0,     0,    13,    21,    22,     8,     0,
      12,     0,     0,     0,     0,    24,     0,     0,     8,     0,
       0,    23
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,   -66,   -66,   156,   -65,   -66,    74,   -66,   -66,
     -66,   -66,   -66,     0,   -66,    -8,    -9,   -66,   139,   -20,
     -66,    65,    72,   182,   -66,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     5,    40,    41,     8,    75,   109,   110,   117,
      23,    24,    25,    26,    80,    43,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      27,    54,    44,    93,    78,    47,    38,    98,    14,   119,
       4,    58,    68,     6,    15,   120,    58,    91,    94,   138,
      16,    42,    14,    19,    96,    21,     1,    22,    15,   111,
      58,    58,    58,    58,    16,    42,    69,    48,     3,    21,
      86,    74,    76,    77,    39,     7,    81,    14,    83,    84,
      73,   121,    14,    15,     9,   125,    82,    92,   128,    16,
      42,   129,    48,   131,    16,    42,    99,    48,    45,   100,
      46,    58,    50,   139,    10,    11,    61,    62,    12,    56,
      13,    63,    64,    51,    57,    27,   112,    71,    58,   101,
      58,   114,    14,    53,   102,    66,    58,   105,    15,   115,
      58,   106,    52,    27,    16,    17,    18,    19,    20,    21,
     124,    22,    55,    27,   118,    11,    58,    27,    12,    59,
      13,    61,    62,    27,    58,   107,    60,   137,    89,    90,
      65,    27,    14,    87,    88,   133,    11,    66,    15,    12,
      57,    13,    70,    72,    16,    17,    18,    19,    20,    21,
      22,    22,    79,    14,    95,    97,   140,    11,   116,    15,
      12,   103,    13,   104,   113,    16,    17,    18,    19,    20,
      21,   102,    22,   122,    14,   123,   126,   127,   132,    11,
      15,   134,    12,   135,    13,   136,    16,    17,    18,    19,
      20,    21,   108,    22,   141,    67,    14,    49,    85,   130,
      11,     0,    15,    12,     0,    13,     0,     0,    16,    17,
      18,    19,    20,    21,     0,    22,     0,    14,     0,     0,
       0,     0,     0,    15,     0,     0,     0,     0,     0,    16,
      17,    18,    19,    20,    21,     0,    22
};

static const yytype_int16 yycheck[] =
{
       8,    21,    11,    68,    52,    14,     5,    23,    25,    20,
       0,    27,     9,     6,    31,     9,    27,    65,    14,    14,
      37,    38,    25,    40,    72,    42,     3,    44,    31,    94,
      27,    27,    27,    27,    37,    38,    45,    40,     4,    42,
      60,    50,    51,    52,    43,    38,    55,    25,    57,    58,
      50,   116,    25,    31,    24,   120,    56,    66,    14,    37,
      38,    17,    40,   128,    37,    38,    26,    40,    12,    29,
      38,    27,    22,   138,     7,     8,    30,    31,    11,    22,
      13,    35,    36,    25,    27,    93,    95,    26,    27,    26,
      27,   100,    25,    38,    26,    27,    27,    28,    31,   108,
      27,    28,    25,   111,    37,    38,    39,    40,    41,    42,
     119,    44,    25,   121,     7,     8,    27,   125,    11,    34,
      13,    30,    31,   131,    27,    28,    33,   136,    63,    64,
      32,   139,    25,    61,    62,     7,     8,    27,    31,    11,
      27,    13,    15,    25,    37,    38,    39,    40,    41,    42,
      44,    44,    23,    25,    16,    23,     7,     8,    10,    31,
      11,    26,    13,    23,    23,    37,    38,    39,    40,    41,
      42,    26,    44,     7,    25,    11,     8,    12,    18,     8,
      31,    19,    11,    13,    13,    16,    37,    38,    39,    40,
      41,    42,    21,    44,    13,    39,    25,    15,    59,   125,
       8,    -1,    31,    11,    -1,    13,    -1,    -1,    37,    38,
      39,    40,    41,    42,    -1,    44,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    -1,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    47,     4,     0,    48,     6,    38,    51,    24,
       7,     8,    11,    13,    25,    31,    37,    38,    39,    40,
      41,    42,    44,    56,    57,    58,    59,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     5,    43,
      49,    50,    38,    61,    62,    12,    38,    62,    40,    69,
      22,    25,    25,    38,    65,    25,    22,    27,    27,    34,
      33,    30,    31,    35,    36,    32,    27,    50,     9,    62,
      15,    26,    25,    59,    62,    52,    62,    62,    71,    23,
      60,    62,    59,    62,    62,    64,    65,    68,    68,    67,
      67,    71,    62,    51,    14,    16,    71,    23,    23,    26,
      29,    26,    26,    26,    23,    28,    28,    28,    21,    53,
      54,    51,    62,    23,    62,    62,    10,    55,     7,    20,
       9,    51,     7,    11,    62,    51,     8,    12,    14,    17,
      53,    51,    18,     7,    19,    13,    16,    62,    14,    51,
       7,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    54,    54,    55,    55,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    58,    59,
      60,    61,    61,    62,    62,    62,    62,    63,    63,    64,
      64,    65,    65,    66,    66,    66,    67,    67,    67,    68,
      68,    69,    69,    70,    70,    71,    71,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     0,     4,     1,     1,     2,     0,     2,
       1,     3,     5,     4,     1,     0,     2,     0,     4,     5,
       3,     8,     8,    16,    11,     4,     4,     4,     4,     4,
       1,     4,     4,     1,     1,     1,     1,     3,     1,     3,
       1,     2,     1,     3,     3,     1,     3,     3,     1,     3,
       1,     2,     1,     4,     1,     1,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 78 "parser.yxx"
                                                                        { program = new Program(*(yyvsp[-3].declaration), (yyvsp[-1].sequence)); delete (yyvsp[-3].declaration); }
#line 1487 "parser.tab.cxx"
    break;

  case 3:
#line 88 "parser.yxx"
    { (yyval.declaration) = new std::vector<Declaration*>(); }
#line 1493 "parser.tab.cxx"
    break;

  case 4:
#line 89 "parser.yxx"
                                          {
        std::cerr << "parser: Declaring " << *(yyvsp[-2].identifier) << " as ";
        if ((yyvsp[0].type)->kind == algo_types::ARRAY) {
            std::cerr << "array of ";
            // Recursive type printing for nested arrays
            const algo_types* current = (yyvsp[0].type);
            while (current->kind == algo_types::ARRAY && !current->parameters.empty()) {
                current = &current->parameters[0];
            }
            std::cerr << current->to_string();  // Implement this method
        } else {
            std::cerr << (yyvsp[0].type)->to_string();
        }
        std::cerr << "\n";

        (yyval.declaration) = (yyvsp[-3].declaration);
        (yyval.declaration)->push_back(new Declaration(*(yyvsp[-2].identifier), *(yyvsp[0].type)));
        delete (yyvsp[-2].identifier);
        delete (yyvsp[0].type);
    }
#line 1518 "parser.tab.cxx"
    break;

  case 5:
#line 112 "parser.yxx"
         { (yyval.type) = (yyvsp[0].type); }
#line 1524 "parser.tab.cxx"
    break;

  case 6:
#line 117 "parser.yxx"
                   { (yyval.type) = (yyvsp[0].type); }
#line 1530 "parser.tab.cxx"
    break;

  case 7:
#line 118 "parser.yxx"
                        { 
          (yyval.type) = new algo_types(algo_types::ARRAY, {*(yyvsp[0].type)});
          delete (yyvsp[0].type);
      }
#line 1539 "parser.tab.cxx"
    break;

  case 8:
#line 124 "parser.yxx"
                                                                        { (yyval.sequence) = new Sequence(); }
#line 1545 "parser.tab.cxx"
    break;

  case 9:
#line 125 "parser.yxx"
                                                                        { (yyval.sequence) = (yyvsp[-1].sequence); (yyval.sequence)->instructions.push_back((yyvsp[0].instruction)); }
#line 1551 "parser.tab.cxx"
    break;

  case 10:
#line 129 "parser.yxx"
                                            { (yyval.expression_list) = new std::vector<Expression*>(); (yyval.expression_list)->push_back((yyvsp[0].expression)); }
#line 1557 "parser.tab.cxx"
    break;

  case 11:
#line 130 "parser.yxx"
                                            { (yyval.expression_list) = (yyvsp[-2].expression_list); (yyval.expression_list)->push_back((yyvsp[0].expression)); }
#line 1563 "parser.tab.cxx"
    break;

  case 12:
#line 135 "parser.yxx"
    { 
        if ((yyvsp[0].elseIfList) == nullptr) {
            (yyvsp[0].elseIfList) = new std::vector<std::pair<Expression*, Sequence*>>();
        }
        (yyvsp[0].elseIfList)->push_back(std::make_pair((yyvsp[-3].expression), (yyvsp[-1].sequence)));
        (yyval.elseIfList) = (yyvsp[0].elseIfList);
    }
#line 1575 "parser.tab.cxx"
    break;

  case 13:
#line 143 "parser.yxx"
    { 
        (yyval.elseIfList) = new std::vector<std::pair<Expression*, Sequence*>>();
        (yyval.elseIfList)->push_back(std::make_pair((yyvsp[-2].expression), (yyvsp[0].sequence)));
    }
#line 1584 "parser.tab.cxx"
    break;

  case 14:
#line 149 "parser.yxx"
                      { (yyval.elseIfList) = (yyvsp[0].elseIfList); }
#line 1590 "parser.tab.cxx"
    break;

  case 15:
#line 150 "parser.yxx"
                      { (yyval.elseIfList) = new std::vector<std::pair<Expression*, Sequence*>>(); }
#line 1596 "parser.tab.cxx"
    break;

  case 16:
#line 154 "parser.yxx"
                   { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1602 "parser.tab.cxx"
    break;

  case 17:
#line 155 "parser.yxx"
                   { (yyval.sequence) = nullptr; }
#line 1608 "parser.tab.cxx"
    break;

  case 18:
#line 159 "parser.yxx"
                                                        { (yyval.instruction) = new Assignment(*(yyvsp[-3].identifier), (yyvsp[-1].expression)); delete (yyvsp[-3].identifier); }
#line 1614 "parser.tab.cxx"
    break;

  case 19:
#line 160 "parser.yxx"
                                                                   { (yyval.instruction) = new Write(*(yyvsp[-2].expression_list)); }
#line 1620 "parser.tab.cxx"
    break;

  case 20:
#line 161 "parser.yxx"
                                                       { (yyval.instruction) = new Read(*(yyvsp[-1].identifier)); delete (yyvsp[-1].identifier); }
#line 1626 "parser.tab.cxx"
    break;

  case 21:
#line 162 "parser.yxx"
                                                                          { (yyval.instruction) = new If((yyvsp[-6].expression), (yyvsp[-4].sequence), convertElseIf(*(yyvsp[-3].elseIfList)), (yyvsp[-2].sequence)); }
#line 1632 "parser.tab.cxx"
    break;

  case 22:
#line 163 "parser.yxx"
                                                        { (yyval.instruction) = new While((yyvsp[-5].expression), (yyvsp[-3].sequence)); }
#line 1638 "parser.tab.cxx"
    break;

  case 23:
#line 164 "parser.yxx"
                                                                                                  { (yyval.instruction) = new For(*(yyvsp[-14].identifier), (yyvsp[-11].expression), (yyvsp[-9].expression), (yyvsp[-4].expression), (yyvsp[-2].sequence)); }
#line 1644 "parser.tab.cxx"
    break;

  case 24:
#line 165 "parser.yxx"
                                                                        { (yyval.instruction) = new For(*(yyvsp[-9].identifier), (yyvsp[-6].expression), (yyvsp[-4].expression), new Literal(algo_types::INTEGER, "1") , (yyvsp[-2].sequence)); }
#line 1650 "parser.tab.cxx"
    break;

  case 25:
#line 166 "parser.yxx"
                                               {
      	// look up T’s declared type in your var_declaration list:
      ArrayCreation* ac = static_cast<ArrayCreation*>((yyvsp[-1].expression));
       (yyval.instruction) = new Assignment(*(yyvsp[-3].identifier), ac);
        delete (yyvsp[-3].identifier);
    }
#line 1661 "parser.tab.cxx"
    break;

  case 26:
#line 172 "parser.yxx"
                                                         {
    // build the AST node—no program calls here!
      ArrayAccess* aa = static_cast<ArrayAccess*>((yyvsp[-3].expression));
      ArrayCreation* ac = static_cast<ArrayCreation*>((yyvsp[-1].expression));

      (yyval.instruction) = new ArrayAssignment(aa->array, aa->indices, ac);

      // avoid double‑free of the ArrayAccess shell
      aa->array = nullptr;
      aa->indices.clear();
      delete aa;
    }
#line 1678 "parser.tab.cxx"
    break;

  case 27:
#line 188 "parser.yxx"
        { (yyval.expression) = new UnaryOperation(UnaryOperation::LONGUEUR, (yyvsp[-1].expression)); }
#line 1684 "parser.tab.cxx"
    break;

  case 28:
#line 192 "parser.yxx"
                                                                                { (yyval.expression) = new UnaryOperation(UnaryOperation::LONGUEUR, (yyvsp[-1].expression)); }
#line 1690 "parser.tab.cxx"
    break;

  case 29:
#line 198 "parser.yxx"
    { 
        algo_types array_type = algo_types(algo_types::INTEGER);  // default, adjust according to context later!
        (yyval.expression) = new ArrayCreation(array_type, *(yyvsp[-1].expression_list));
        delete (yyvsp[-1].expression_list); 
    }
#line 1700 "parser.tab.cxx"
    break;

  case 30:
#line 207 "parser.yxx"
               { (yyval.expression_list) = new std::vector<Expression*>(); (yyval.expression_list)->push_back((yyvsp[0].expression)); }
#line 1706 "parser.tab.cxx"
    break;

  case 31:
#line 213 "parser.yxx"
    { 
        (yyval.expression) = new ArrayAccess((yyvsp[-3].expression), std::vector<Expression*>{ (yyvsp[-1].expression) });
    }
#line 1714 "parser.tab.cxx"
    break;

  case 32:
#line 217 "parser.yxx"
    { 
        // Cast $1 to ArrayAccess* to access the 'indices' field.
        ArrayAccess* aa = static_cast<ArrayAccess*>((yyvsp[-3].expression));
        aa->indices.push_back((yyvsp[-1].expression));
        (yyval.expression) = (yyvsp[-3].expression); 
    }
#line 1725 "parser.tab.cxx"
    break;

  case 33:
#line 227 "parser.yxx"
                        { std::cerr << "Parser: Processing expression\n" ; (yyval.expression) = (yyvsp[0].expression); }
#line 1731 "parser.tab.cxx"
    break;

  case 37:
#line 233 "parser.yxx"
                                        { std::cerr << "Parser: Processing OU\n"; (yyval.expression) = new BinaryOperation(BinaryOperation::OU, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1737 "parser.tab.cxx"
    break;

  case 38:
#line 234 "parser.yxx"
                         { std::cerr << "Parser: Processing conjonction\n"; (yyval.expression) = (yyvsp[0].expression); }
#line 1743 "parser.tab.cxx"
    break;

  case 39:
#line 237 "parser.yxx"
                                     { std::cerr << "Parser: Processing ET\n"; (yyval.expression) = new BinaryOperation(BinaryOperation::ET, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1749 "parser.tab.cxx"
    break;

  case 40:
#line 238 "parser.yxx"
                      { std::cerr << "Parser: Processing negation\n"; (yyval.expression) = (yyvsp[0].expression); }
#line 1755 "parser.tab.cxx"
    break;

  case 41:
#line 241 "parser.yxx"
                       { std::cerr << "Parser: Processing NON\n"; (yyval.expression) = new UnaryOperation(UnaryOperation::NON, (yyvsp[0].expression)); }
#line 1761 "parser.tab.cxx"
    break;

  case 42:
#line 242 "parser.yxx"
                     { std::cerr << "Parser: Processing comparison\n"; (yyval.expression) = (yyvsp[0].expression); }
#line 1767 "parser.tab.cxx"
    break;

  case 43:
#line 245 "parser.yxx"
                                                                        { (yyval.expression) = new BinaryOperation(BinaryOperation::EGAL, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1773 "parser.tab.cxx"
    break;

  case 44:
#line 246 "parser.yxx"
                                                                        { (yyval.expression) = new BinaryOperation(BinaryOperation::INFERIEUR, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1779 "parser.tab.cxx"
    break;

  case 45:
#line 247 "parser.yxx"
                                                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 1785 "parser.tab.cxx"
    break;

  case 46:
#line 250 "parser.yxx"
                                                                        { (yyval.expression) = new BinaryOperation(BinaryOperation::PLUS, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1791 "parser.tab.cxx"
    break;

  case 47:
#line 251 "parser.yxx"
                                                                        { (yyval.expression) = new BinaryOperation(BinaryOperation::MOINS, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1797 "parser.tab.cxx"
    break;

  case 48:
#line 252 "parser.yxx"
                                                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 1803 "parser.tab.cxx"
    break;

  case 49:
#line 255 "parser.yxx"
                                                                        { (yyval.expression) = new BinaryOperation(BinaryOperation::FOIS, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1809 "parser.tab.cxx"
    break;

  case 50:
#line 256 "parser.yxx"
                                                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 1815 "parser.tab.cxx"
    break;

  case 51:
#line 259 "parser.yxx"
                                                                        { (yyval.expression) = new UnaryOperation(UnaryOperation::MOINS, (yyvsp[0].expression)); }
#line 1821 "parser.tab.cxx"
    break;

  case 52:
#line 260 "parser.yxx"
                                                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 1827 "parser.tab.cxx"
    break;

  case 53:
#line 263 "parser.yxx"
                                                                        { (yyval.expression) = new BinaryOperation(BinaryOperation::INDICE, (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1833 "parser.tab.cxx"
    break;

  case 54:
#line 264 "parser.yxx"
                                                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 1839 "parser.tab.cxx"
    break;

  case 55:
#line 268 "parser.yxx"
                                                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 1845 "parser.tab.cxx"
    break;

  case 56:
#line 269 "parser.yxx"
                                                                        { (yyval.expression) = new Identifier(*(yyvsp[0].identifier)); delete (yyvsp[0].identifier);}
#line 1851 "parser.tab.cxx"
    break;

  case 58:
#line 271 "parser.yxx"
                                                                        { (yyval.expression) = (yyvsp[-1].expression); }
#line 1857 "parser.tab.cxx"
    break;


#line 1861 "parser.tab.cxx"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 274 "parser.yxx"


void yyerror(const char *s) {
  printf("%s\n",s);
}

int main(int, char *argv[]) {
  yyin=fopen(argv[1],"r");
  yyparse();

  if(program && program->validate()) {
      std::cout << program->cpp_code();
      return 0;
  } else return 1;
}
