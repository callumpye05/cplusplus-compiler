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
#line 11 "src/parser.yxx"

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


#line 89 "build/gen/parser.cpp"

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
#ifndef YY_YY_BUILD_GEN_PARSER_HPP_INCLUDED
# define YY_YY_BUILD_GEN_PARSER_HPP_INCLUDED
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
    TOUT = 277,
    DANS = 278,
    AFFECTATION = 279,
    PT_VIRGULE = 280,
    DEUX_POINTS = 281,
    PARENTHESE_G = 282,
    PARENTHESE_D = 283,
    CROCHET_G = 284,
    CROCHET_D = 285,
    VIRGULE = 286,
    PLUS = 287,
    MOINS = 288,
    MULTIPLIE = 289,
    ET = 290,
    OU = 291,
    EGAL = 292,
    INFERIEUR = 293,
    LITTERAL = 294,
    ID = 295,
    ECRIRE = 296,
    LONGUEUR = 297,
    LIRE = 298,
    NON = 299,
    TABLEAU_TYPE = 300,
    TABLEAU_CTOR = 301,
    FONCTION = 302,
    PROCEDURE = 303,
    RETOURNER = 304,
    FERMETURE_LONGUEUR = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 53 "src/parser.yxx"

    Instruction* instruction;
    Expression* expression;
    Sequence* sequence;
    algo_types* type;
    std::string* identifier;
    std::vector<Declaration*>* declaration;
    std::vector<Expression*>* expression_list;
    std::vector<std::pair<Expression*, Sequence*>>* elseIfList;  
    std::vector<Parameter>* param_list;

#line 204 "build/gen/parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BUILD_GEN_PARSER_HPP_INCLUDED  */



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
#define YYLAST   368

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

#define YYUNDEFTOK  2
#define YYMAXUTOK   305


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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    88,    88,    98,    99,   122,   127,   128,   134,   135,
     139,   140,   144,   152,   159,   160,   164,   165,   169,   176,
     183,   184,   188,   193,   201,   209,   221,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   248,
     253,   258,   268,   273,   277,   288,   289,   290,   291,   294,
     295,   298,   299,   302,   303,   306,   307,   308,   311,   312,
     313,   316,   317,   320,   321,   326,   327,   328,   329,   330
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ALGORITHME", "VARIABLES", "TYPE",
  "DEBUT", "FIN", "SI", "ALORS", "SINON", "TANT", "QUE", "POUR", "FAIRE",
  "ALLANT", "DE", "AVEC", "UN", "PAS", "A", "SINONSI", "TOUT", "DANS",
  "AFFECTATION", "PT_VIRGULE", "DEUX_POINTS", "PARENTHESE_G",
  "PARENTHESE_D", "CROCHET_G", "CROCHET_D", "VIRGULE", "PLUS", "MOINS",
  "MULTIPLIE", "ET", "OU", "EGAL", "INFERIEUR", "LITTERAL", "ID", "ECRIRE",
  "LONGUEUR", "LIRE", "NON", "TABLEAU_TYPE", "TABLEAU_CTOR", "FONCTION",
  "PROCEDURE", "RETOURNER", "FERMETURE_LONGUEUR", "$accept", "algo",
  "var_declaration", "primitive_type", "type", "sequence",
  "expression_list", "autres_conditions", "opt_autres_conditions",
  "opt_sinon", "fonction_definition", "procedure_definition", "param_list",
  "param_list_nonvide", "retour", "commande", "longueur_expr",
  "longueur_terme", "array_creation", "array_dimensions", "array_access",
  "expression", "disjonction", "conjonction", "negation", "comparison",
  "somme", "produit", "oppose", "terme", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF (-73)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-70)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      46,    53,    37,   -73,   -73,     1,   -73,    44,   139,     3,
     -73,    34,    70,    -6,    34,    34,   -73,    77,    57,    75,
      64,    34,    78,    66,    67,    34,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,    14,    79,    74,    76,   -73,   -73,    27,
      80,   -73,   -73,   -73,     3,   -73,   -73,   -73,    86,     0,
      34,    73,   101,     2,    -3,    34,    34,    34,   100,   -17,
      34,    99,   103,    33,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,   -73,   -73,     7,   104,   112,   -73,
     106,    50,    55,    79,    40,   105,   -73,   107,    79,    92,
      92,   -73,   109,    52,    60,    62,    76,   -73,    80,    80,
      27,    27,   -73,   301,   -73,    96,    34,   -73,   -73,   113,
      34,   -73,   -73,   -73,   115,   111,   117,   114,   -73,   -73,
     -73,   -73,    34,   -73,   133,   162,   135,    22,   -73,    79,
       3,   125,   119,   147,     4,   -73,   148,   143,   -73,    34,
     -73,     3,   131,   -73,   -73,   319,   152,   149,   185,     6,
     157,     3,   208,   301,   -73,   -73,   151,   -73,   153,   -73,
     -73,   126,   -73,   -73,   231,   146,   254,   -73,   154,   160,
     130,   -73,    34,   -73,    10,   -73,   277,   171,   -73
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     3,     1,     0,     8,     0,     0,     0,
       2,     0,     0,     0,     0,     0,    65,    66,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    28,    29,     9,
      48,    67,    46,    69,     0,    45,    50,    52,    54,    57,
      60,    62,    64,     5,     0,     6,     4,    66,    47,     0,
       0,     0,     0,     0,    62,     0,     0,     0,     0,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,    68,
      46,     0,     0,    10,     0,    64,    32,     0,    42,    20,
      20,    24,    46,     0,     0,     0,    49,    51,    58,    59,
      55,    56,    61,    15,     8,     0,     0,    38,    30,     0,
       0,    39,    40,    41,     0,     0,    21,     0,    25,    26,
      44,    43,     0,    14,    17,     0,     0,     0,    31,    11,
       0,     0,     0,     0,     0,     8,     0,     0,     8,     0,
      22,     0,     0,     8,     8,    16,     0,     0,     0,     0,
       0,     0,     0,    13,    33,    34,     0,     8,     0,     8,
      23,     0,    12,    36,     0,     0,     0,    19,     0,     0,
       0,    37,     0,    18,     0,     8,     0,     0,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   -73,   -73,   -42,   -72,   -73,    38,   -73,   -73,
     -73,   -73,   110,   -73,   -73,   -73,   -73,   -73,   -11,   -73,
      -8,   -10,   -73,   123,   -16,   -73,    26,    24,   179,   -47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    45,    46,     8,    82,   123,   124,   136,
      26,    27,   115,   116,    28,    29,    30,    31,    32,    87,
      48,    34,    35,    36,    37,    38,    39,    40,    41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,    49,    74,   103,    53,    59,   -63,     6,    43,    75,
      85,   -63,   -52,   144,   -63,    63,    51,   -63,   -52,   -52,
     157,   104,   -63,   158,   175,   -63,   102,   -63,   -63,    66,
      79,    66,   125,    66,    52,    66,    66,     4,    64,    66,
      76,     7,   139,    65,    80,    81,    83,    84,    44,     1,
      88,    66,    97,    92,    93,    94,    95,     3,    91,    69,
      70,    14,    66,   145,    71,    72,   148,    15,   111,    66,
       9,   152,   153,    16,    47,   108,    19,   119,    21,    66,
      22,    66,    50,   109,    56,   164,   110,   166,   140,    66,
     120,    66,   121,    98,    99,    33,   127,   100,   101,   150,
     129,    55,    57,   176,    58,    60,    61,    62,    66,   160,
      67,    68,   134,    77,    73,    65,    78,    33,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,    86,    89,   105,   106,   149,
      90,   107,   114,   112,   118,   113,   126,    33,   128,   131,
      33,   130,   133,   135,    33,    33,    10,    11,   132,   138,
      12,   141,    13,   143,   147,   146,    33,   151,    33,   142,
     154,   155,   174,   159,   163,   169,    14,   171,    33,   137,
      11,   165,    15,    12,   167,    13,   172,   173,    16,    17,
      18,    19,    20,    21,   178,    22,    23,    24,    25,    14,
      96,   162,   156,    11,    54,    15,    12,     0,    13,     0,
     117,    16,    17,    18,    19,    20,    21,     0,    22,    23,
      24,    25,    14,     0,     0,   161,    11,     0,    15,    12,
       0,    13,     0,     0,    16,    17,    18,    19,    20,    21,
       0,    22,    23,    24,    25,    14,     0,     0,   168,    11,
       0,    15,    12,     0,    13,     0,     0,    16,    17,    18,
      19,    20,    21,     0,    22,    23,    24,    25,    14,     0,
       0,   170,    11,     0,    15,    12,     0,    13,     0,     0,
      16,    17,    18,    19,    20,    21,     0,    22,    23,    24,
      25,    14,     0,     0,   177,    11,     0,    15,    12,     0,
      13,     0,     0,    16,    17,    18,    19,    20,    21,     0,
      22,    23,    24,    25,    14,     0,     0,     0,     0,    11,
      15,     0,    12,     0,    13,     0,    16,    17,    18,    19,
      20,    21,   122,    22,    23,    24,    25,    11,    14,     0,
      12,     0,    13,     0,    15,     0,     0,     0,     0,     0,
      16,    17,    18,    19,    20,    21,    14,    22,    23,    24,
      25,     0,    15,     0,     0,     0,     0,     0,    16,    17,
      18,    19,    20,    21,     0,    22,    23,    24,    25
};

static const yytype_int16 yycheck[] =
{
       8,    11,    44,    75,    14,    21,     9,     6,     5,     9,
      57,    14,    29,     9,    17,    25,    22,    20,    35,    36,
      14,    14,    25,    17,    14,    28,    73,    30,    31,    29,
      28,    29,   104,    29,    40,    29,    29,     0,    24,    29,
      50,    40,    20,    29,    55,    55,    56,    57,    45,     3,
      60,    29,    68,    64,    64,    65,    66,     4,    25,    32,
      33,    27,    29,   135,    37,    38,   138,    33,    28,    29,
      26,   143,   144,    39,    40,    25,    42,    25,    44,    29,
      46,    29,    12,    28,    27,   157,    31,   159,   130,    29,
      30,    29,    30,    69,    70,   103,   106,    71,    72,   141,
     110,    24,    27,   175,    40,    27,    40,    40,    29,   151,
      36,    35,   122,    40,    34,    29,    15,   125,    32,    33,
      34,    35,    36,    37,    38,    25,    27,    23,    16,   139,
      27,    25,    40,    28,    25,    28,    40,   145,    25,    28,
     148,    26,    28,    10,   152,   153,     7,     8,    31,    14,
      11,    26,    13,     6,    11,     7,   164,    26,   166,    40,
       8,    12,   172,     6,    13,    19,    27,    13,   176,     7,
       8,    18,    33,    11,    48,    13,    16,    47,    39,    40,
      41,    42,    43,    44,    13,    46,    47,    48,    49,    27,
      67,   153,     7,     8,    15,    33,    11,    -1,    13,    -1,
      90,    39,    40,    41,    42,    43,    44,    -1,    46,    47,
      48,    49,    27,    -1,    -1,     7,     8,    -1,    33,    11,
      -1,    13,    -1,    -1,    39,    40,    41,    42,    43,    44,
      -1,    46,    47,    48,    49,    27,    -1,    -1,     7,     8,
      -1,    33,    11,    -1,    13,    -1,    -1,    39,    40,    41,
      42,    43,    44,    -1,    46,    47,    48,    49,    27,    -1,
      -1,     7,     8,    -1,    33,    11,    -1,    13,    -1,    -1,
      39,    40,    41,    42,    43,    44,    -1,    46,    47,    48,
      49,    27,    -1,    -1,     7,     8,    -1,    33,    11,    -1,
      13,    -1,    -1,    39,    40,    41,    42,    43,    44,    -1,
      46,    47,    48,    49,    27,    -1,    -1,    -1,    -1,     8,
      33,    -1,    11,    -1,    13,    -1,    39,    40,    41,    42,
      43,    44,    21,    46,    47,    48,    49,     8,    27,    -1,
      11,    -1,    13,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    27,    46,    47,    48,
      49,    -1,    33,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    -1,    46,    47,    48,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    52,     4,     0,    53,     6,    40,    56,    26,
       7,     8,    11,    13,    27,    33,    39,    40,    41,    42,
      43,    44,    46,    47,    48,    49,    61,    62,    65,    66,
      67,    68,    69,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,     5,    45,    54,    55,    40,    71,    72,
      12,    22,    40,    72,    79,    24,    27,    27,    40,    75,
      27,    40,    40,    72,    24,    29,    29,    36,    35,    32,
      33,    37,    38,    34,    55,     9,    72,    40,    15,    28,
      69,    72,    57,    72,    72,    80,    25,    70,    72,    27,
      27,    25,    69,    72,    72,    72,    74,    75,    78,    78,
      77,    77,    80,    56,    14,    23,    16,    25,    25,    28,
      31,    28,    28,    28,    40,    63,    64,    63,    25,    25,
      30,    30,    21,    58,    59,    56,    40,    72,    25,    72,
      26,    28,    31,    28,    72,    10,    60,     7,    14,    20,
      55,    26,    40,     6,     9,    56,     7,    11,    56,    72,
      55,    26,    56,    56,     8,    12,     7,    14,    17,     6,
      55,     7,    58,    13,    56,    18,    56,    48,     7,    19,
       7,    13,    16,    47,    72,    14,    56,     7,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    55,    55,    56,    56,
      57,    57,    58,    58,    59,    59,    60,    60,    61,    62,
      63,    63,    64,    64,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    67,
      68,    69,    70,    71,    71,    72,    72,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    76,    77,    77,
      77,    78,    78,    79,    79,    80,    80,    80,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     0,     4,     1,     1,     2,     0,     2,
       1,     3,     5,     4,     1,     0,     2,     0,    11,     9,
       0,     1,     3,     5,     3,     4,     4,     1,     1,     1,
       4,     5,     3,     8,     8,    16,     9,    11,     4,     4,
       4,     4,     1,     4,     4,     1,     1,     1,     1,     3,
       1,     3,     1,     2,     1,     3,     3,     1,     3,     3,
       1,     3,     1,     2,     1,     1,     1,     1,     3,     1
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
#line 88 "src/parser.yxx"
                                                                        { program = new Program(*(yyvsp[-3].declaration), (yyvsp[-1].sequence)); delete (yyvsp[-3].declaration); }
#line 1534 "build/gen/parser.cpp"
    break;

  case 3:
#line 98 "src/parser.yxx"
    { (yyval.declaration) = new std::vector<Declaration*>(); }
#line 1540 "build/gen/parser.cpp"
    break;

  case 4:
#line 99 "src/parser.yxx"
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
#line 1565 "build/gen/parser.cpp"
    break;

  case 5:
#line 122 "src/parser.yxx"
         { (yyval.type) = (yyvsp[0].type); }
#line 1571 "build/gen/parser.cpp"
    break;

  case 6:
#line 127 "src/parser.yxx"
                   { (yyval.type) = (yyvsp[0].type); }
#line 1577 "build/gen/parser.cpp"
    break;

  case 7:
#line 128 "src/parser.yxx"
                        { 
          (yyval.type) = new algo_types(algo_types::ARRAY, {*(yyvsp[0].type)});
          delete (yyvsp[0].type);
      }
#line 1586 "build/gen/parser.cpp"
    break;

  case 8:
#line 134 "src/parser.yxx"
                                                                        { (yyval.sequence) = new Sequence(); }
#line 1592 "build/gen/parser.cpp"
    break;

  case 9:
#line 135 "src/parser.yxx"
                                                                        { (yyval.sequence) = (yyvsp[-1].sequence); (yyval.sequence)->instructions.push_back((yyvsp[0].instruction)); }
#line 1598 "build/gen/parser.cpp"
    break;

  case 10:
#line 139 "src/parser.yxx"
                                            { (yyval.expression_list) = new std::vector<Expression*>(); (yyval.expression_list)->push_back((yyvsp[0].expression)); }
#line 1604 "build/gen/parser.cpp"
    break;

  case 11:
#line 140 "src/parser.yxx"
                                            { (yyval.expression_list) = (yyvsp[-2].expression_list); (yyval.expression_list)->push_back((yyvsp[0].expression)); }
#line 1610 "build/gen/parser.cpp"
    break;

  case 12:
#line 145 "src/parser.yxx"
    { 
        if ((yyvsp[0].elseIfList) == nullptr) {
            (yyvsp[0].elseIfList) = new std::vector<std::pair<Expression*, Sequence*>>();
        }
        (yyvsp[0].elseIfList)->push_back(std::make_pair((yyvsp[-3].expression), (yyvsp[-1].sequence)));
        (yyval.elseIfList) = (yyvsp[0].elseIfList);
    }
#line 1622 "build/gen/parser.cpp"
    break;

  case 13:
#line 153 "src/parser.yxx"
    { 
        (yyval.elseIfList) = new std::vector<std::pair<Expression*, Sequence*>>();
        (yyval.elseIfList)->push_back(std::make_pair((yyvsp[-2].expression), (yyvsp[0].sequence)));
    }
#line 1631 "build/gen/parser.cpp"
    break;

  case 14:
#line 159 "src/parser.yxx"
                      { (yyval.elseIfList) = (yyvsp[0].elseIfList); }
#line 1637 "build/gen/parser.cpp"
    break;

  case 15:
#line 160 "src/parser.yxx"
                      { (yyval.elseIfList) = new std::vector<std::pair<Expression*, Sequence*>>(); }
#line 1643 "build/gen/parser.cpp"
    break;

  case 16:
#line 164 "src/parser.yxx"
                   { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1649 "build/gen/parser.cpp"
    break;

  case 17:
#line 165 "src/parser.yxx"
                   { (yyval.sequence) = nullptr; }
#line 1655 "build/gen/parser.cpp"
    break;

  case 18:
#line 169 "src/parser.yxx"
                                                                                                  {
        (yyval.instruction) = new FunctionDefinition(*(yyvsp[-9].identifier), *(yyvsp[-7].param_list), *(yyvsp[-4].type), (yyvsp[-2].sequence));
        delete (yyvsp[-9].identifier); delete (yyvsp[-7].param_list); delete (yyvsp[-4].type);
    }
#line 1664 "build/gen/parser.cpp"
    break;

  case 19:
#line 176 "src/parser.yxx"
                                                                                   {
        (yyval.instruction) = new ProcedureDefinition(*(yyvsp[-7].identifier), *(yyvsp[-5].param_list), (yyvsp[-2].sequence));
        delete (yyvsp[-7].identifier); delete (yyvsp[-5].param_list);
    }
#line 1673 "build/gen/parser.cpp"
    break;

  case 20:
#line 183 "src/parser.yxx"
               { (yyval.param_list) = new std::vector<Parameter>(); }
#line 1679 "build/gen/parser.cpp"
    break;

  case 21:
#line 184 "src/parser.yxx"
                         { (yyval.param_list) = (yyvsp[0].param_list); }
#line 1685 "build/gen/parser.cpp"
    break;

  case 22:
#line 188 "src/parser.yxx"
                        {
        (yyval.param_list) = new std::vector<Parameter>();
        (yyval.param_list)->push_back(Parameter(*(yyvsp[-2].identifier), *(yyvsp[0].type)));
        delete (yyvsp[-2].identifier); delete (yyvsp[0].type);
    }
#line 1695 "build/gen/parser.cpp"
    break;

  case 23:
#line 193 "src/parser.yxx"
                                                     {
        (yyval.param_list) = (yyvsp[-4].param_list);
        (yyval.param_list)->push_back(Parameter(*(yyvsp[-2].identifier), *(yyvsp[0].type)));
        delete (yyvsp[-2].identifier); delete (yyvsp[0].type);
    }
#line 1705 "build/gen/parser.cpp"
    break;

  case 24:
#line 201 "src/parser.yxx"
                                    {
        (yyval.instruction) = new Return((yyvsp[-1].expression));
    }
#line 1713 "build/gen/parser.cpp"
    break;

  case 25:
#line 209 "src/parser.yxx"
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
#line 1730 "build/gen/parser.cpp"
    break;

  case 26:
#line 221 "src/parser.yxx"
                                                     {
    	ArrayAccess* aa = static_cast<ArrayAccess*>((yyvsp[-3].expression));
    	(yyval.instruction) = new ArrayAssignment(aa->array, aa->indices, (yyvsp[-1].expression));
    	aa->array = nullptr;
    	aa->indices.clear();
    	delete aa;
}
#line 1742 "build/gen/parser.cpp"
    break;

  case 30:
#line 231 "src/parser.yxx"
                                                          { (yyval.instruction) = new Assignment(*(yyvsp[-3].identifier), (yyvsp[-1].expression)); delete (yyvsp[-3].identifier); }
#line 1748 "build/gen/parser.cpp"
    break;

  case 31:
#line 232 "src/parser.yxx"
                                                                   { (yyval.instruction) = new Write(*(yyvsp[-2].expression_list)); }
#line 1754 "build/gen/parser.cpp"
    break;

  case 32:
#line 233 "src/parser.yxx"
                                                       { (yyval.instruction) = new Read(*(yyvsp[-1].identifier)); delete (yyvsp[-1].identifier); }
#line 1760 "build/gen/parser.cpp"
    break;

  case 33:
#line 234 "src/parser.yxx"
                                                                          { (yyval.instruction) = new If((yyvsp[-6].expression), (yyvsp[-4].sequence), convertElseIf(*(yyvsp[-3].elseIfList)), (yyvsp[-2].sequence)); }
#line 1766 "build/gen/parser.cpp"
    break;

  case 34:
#line 235 "src/parser.yxx"
                                                        { (yyval.instruction) = new While((yyvsp[-5].expression), (yyvsp[-3].sequence)); }
#line 1772 "build/gen/parser.cpp"
    break;

  case 35:
#line 236 "src/parser.yxx"
                                                                                                  { (yyval.instruction) = new For(*(yyvsp[-14].identifier), (yyvsp[-11].expression), (yyvsp[-9].expression), (yyvsp[-4].expression), (yyvsp[-2].sequence)); }
#line 1778 "build/gen/parser.cpp"
    break;

  case 36:
#line 237 "src/parser.yxx"
                                                   { (yyval.instruction) = new ForEach(*(yyvsp[-6].identifier), *(yyvsp[-4].identifier), (yyvsp[-2].sequence)); delete (yyvsp[-6].identifier); delete (yyvsp[-4].identifier); }
#line 1784 "build/gen/parser.cpp"
    break;

  case 37:
#line 238 "src/parser.yxx"
                                                                        { (yyval.instruction) = new For(*(yyvsp[-9].identifier), (yyvsp[-6].expression), (yyvsp[-4].expression), new Literal(algo_types::INTEGER, "1") , (yyvsp[-2].sequence)); }
#line 1790 "build/gen/parser.cpp"
    break;

  case 38:
#line 239 "src/parser.yxx"
                                               {
      	// look up T’s declared type in your var_declaration list:
      ArrayCreation* ac = static_cast<ArrayCreation*>((yyvsp[-1].expression));
       (yyval.instruction) = new Assignment(*(yyvsp[-3].identifier), ac);
        delete (yyvsp[-3].identifier);
    }
#line 1801 "build/gen/parser.cpp"
    break;

  case 39:
#line 249 "src/parser.yxx"
        { (yyval.expression) = new UnaryOperation(UnaryOperation::LONGUEUR, (yyvsp[-1].expression)); }
#line 1807 "build/gen/parser.cpp"
    break;

  case 40:
#line 253 "src/parser.yxx"
                                                                                { (yyval.expression) = new UnaryOperation(UnaryOperation::LONGUEUR, (yyvsp[-1].expression)); }
#line 1813 "build/gen/parser.cpp"
    break;

  case 41:
#line 259 "src/parser.yxx"
    { 
        algo_types array_type = algo_types(algo_types::INTEGER);  // default, adjust according to context later!
        (yyval.expression) = new ArrayCreation(array_type, *(yyvsp[-1].expression_list));
        delete (yyvsp[-1].expression_list); 
    }
#line 1823 "build/gen/parser.cpp"
    break;

  case 42:
#line 268 "src/parser.yxx"
               { (yyval.expression_list) = new std::vector<Expression*>(); (yyval.expression_list)->push_back((yyvsp[0].expression)); }
#line 1829 "build/gen/parser.cpp"
    break;

  case 43:
#line 274 "src/parser.yxx"
    { 
        (yyval.expression) = new ArrayAccess((yyvsp[-3].expression), std::vector<Expression*>{ (yyvsp[-1].expression) });
    }
#line 1837 "build/gen/parser.cpp"
    break;

  case 44:
#line 278 "src/parser.yxx"
    { 
        // Cast $1 to ArrayAccess* to access the 'indices' field.
        ArrayAccess* aa = static_cast<ArrayAccess*>((yyvsp[-3].expression));
        aa->indices.push_back((yyvsp[-1].expression));
        (yyval.expression) = (yyvsp[-3].expression); 
    }
#line 1848 "build/gen/parser.cpp"
    break;

  case 45:
#line 288 "src/parser.yxx"
                        { std::cerr << "Parser: Processing expression\n" ; (yyval.expression) = (yyvsp[0].expression); }
#line 1854 "build/gen/parser.cpp"
    break;

  case 49:
#line 294 "src/parser.yxx"
                                        { std::cerr << "Parser: Processing OU\n"; (yyval.expression) = new BinaryOperation(BinaryOperation::OU, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1860 "build/gen/parser.cpp"
    break;

  case 50:
#line 295 "src/parser.yxx"
                         { std::cerr << "Parser: Processing conjonction\n"; (yyval.expression) = (yyvsp[0].expression); }
#line 1866 "build/gen/parser.cpp"
    break;

  case 51:
#line 298 "src/parser.yxx"
                                     { std::cerr << "Parser: Processing ET\n"; (yyval.expression) = new BinaryOperation(BinaryOperation::ET, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1872 "build/gen/parser.cpp"
    break;

  case 52:
#line 299 "src/parser.yxx"
                      { std::cerr << "Parser: Processing negation\n"; (yyval.expression) = (yyvsp[0].expression); }
#line 1878 "build/gen/parser.cpp"
    break;

  case 53:
#line 302 "src/parser.yxx"
                       { std::cerr << "Parser: Processing NON\n"; (yyval.expression) = new UnaryOperation(UnaryOperation::NON, (yyvsp[0].expression)); }
#line 1884 "build/gen/parser.cpp"
    break;

  case 54:
#line 303 "src/parser.yxx"
                     { std::cerr << "Parser: Processing comparison\n"; (yyval.expression) = (yyvsp[0].expression); }
#line 1890 "build/gen/parser.cpp"
    break;

  case 55:
#line 306 "src/parser.yxx"
                                                                        { (yyval.expression) = new BinaryOperation(BinaryOperation::EGAL, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1896 "build/gen/parser.cpp"
    break;

  case 56:
#line 307 "src/parser.yxx"
                                                                        { (yyval.expression) = new BinaryOperation(BinaryOperation::INFERIEUR, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1902 "build/gen/parser.cpp"
    break;

  case 57:
#line 308 "src/parser.yxx"
                                                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 1908 "build/gen/parser.cpp"
    break;

  case 58:
#line 311 "src/parser.yxx"
                                                                        { (yyval.expression) = new BinaryOperation(BinaryOperation::PLUS, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1914 "build/gen/parser.cpp"
    break;

  case 59:
#line 312 "src/parser.yxx"
                                                                        { (yyval.expression) = new BinaryOperation(BinaryOperation::MOINS, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1920 "build/gen/parser.cpp"
    break;

  case 60:
#line 313 "src/parser.yxx"
                                                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 1926 "build/gen/parser.cpp"
    break;

  case 61:
#line 316 "src/parser.yxx"
                                                                        { (yyval.expression) = new BinaryOperation(BinaryOperation::FOIS, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1932 "build/gen/parser.cpp"
    break;

  case 62:
#line 317 "src/parser.yxx"
                                                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 1938 "build/gen/parser.cpp"
    break;

  case 63:
#line 320 "src/parser.yxx"
                                                                        { (yyval.expression) = new UnaryOperation(UnaryOperation::MOINS, (yyvsp[0].expression)); }
#line 1944 "build/gen/parser.cpp"
    break;

  case 64:
#line 321 "src/parser.yxx"
                                                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 1950 "build/gen/parser.cpp"
    break;

  case 65:
#line 326 "src/parser.yxx"
                                                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 1956 "build/gen/parser.cpp"
    break;

  case 66:
#line 327 "src/parser.yxx"
                                                                        { (yyval.expression) = new Identifier(*(yyvsp[0].identifier)); delete (yyvsp[0].identifier);}
#line 1962 "build/gen/parser.cpp"
    break;

  case 68:
#line 329 "src/parser.yxx"
                                                                        { (yyval.expression) = (yyvsp[-1].expression); }
#line 1968 "build/gen/parser.cpp"
    break;


#line 1972 "build/gen/parser.cpp"

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
#line 333 "src/parser.yxx"


void yyerror(const char *s) {
  printf("%s\n",s);
}

int main(int, char *argv[]) {
  //extern int yydebug;
  //yydebug = 1;
  yyin=fopen(argv[1],"r");
  yyparse();

  if(program && program->validate()) {
      std::cout << program->cpp_code();
      return 0;
  } else return 1;
}
