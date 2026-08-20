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
#line 1 "semantic.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"
  
  #define MAX_SIZE 50
  #define MAX_CASES 10

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int gvar_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
  int var_type = -1;
  int int_par_num = 0;
  int uint_par_num = 0;
  
  int num = 0;
  int param_num = 0;
  
  // help struct for 10-th assignement
  struct paramData{
  	unsigned fun_id; // key to search struct
  	unsigned fun_types[MAX_SIZE]; // za sad sam  ga ogranicila na 50 parametara po funkciji, dok ne smislim nesto pametnije
	unsigned count_param;
  };
  
  struct paramData Fun_params[100]; // 100 functions per program
  
  unsigned num_of_args = 0;
  unsigned type_of_arg = 0;
  int ArgsArray[50]; // stavila sam da f-ja moze da ima 50 argumenata

  bool return_flag = FALSE;
  
  int lab_num = -1;
  int con_num = -1;
  int for_num = -1;
  int for_num_u = 0; // num of multipl fors 
  int max_for_num = -1;
  int var_num_f = 0;
  
  FILE *output;
  
  int branch_num = 0;
  int pow_num = 0;
  
  int switch_num = 0;
  int case_num = 0;
  int switch_exp_id = -1;
  int cases[MAX_CASES];
  bool default_case = FALSE;
  
  

#line 137 "semantic.tab.c"

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
#ifndef YY_YY_SEMANTIC_TAB_H_INCLUDED
# define YY_YY_SEMANTIC_TAB_H_INCLUDED
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
    _TYPE = 258,
    _IF = 259,
    _ELSE = 260,
    _RETURN = 261,
    _ID = 262,
    _INT_NUMBER = 263,
    _UINT_NUMBER = 264,
    _LPAREN = 265,
    _RPAREN = 266,
    _LBRACKET = 267,
    _RBRACKET = 268,
    _ASSIGN = 269,
    _SEMICOLON = 270,
    _AROP = 271,
    _ADD = 272,
    _SUB = 273,
    _MUL = 274,
    _DIV = 275,
    _RELOP = 276,
    _COMMA = 277,
    _INC = 278,
    _FOR = 279,
    _Q_MARK = 280,
    _TWO_DOTS = 281,
    _BRANCH = 282,
    _FIRST = 283,
    _SECOND = 284,
    _THIRD = 285,
    _OTHERWISE = 286,
    _END_BRANCH = 287,
    _SWITCH = 288,
    _CASE = 289,
    _BREAK = 290,
    _DEFAULT = 291,
    _POW = 292,
    ONLY_IF = 293,
    PRIORITY = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 69 "semantic.y"

  int i;
  char *s;

#line 234 "semantic.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SEMANTIC_TAB_H_INCLUDED  */



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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

#define YYUNDEFTOK  2
#define YYMAXUTOK   294


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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   127,   127,   135,   136,   140,   153,   154,   159,   158,
     198,   202,   206,   236,   269,   268,   278,   279,   283,   283,
     285,   297,   312,   313,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   329,   333,   348,   373,   347,   404,   428,
     429,   430,   431,   432,   433,   434,   403,   444,   443,   484,
     483,   506,   507,   511,   512,   519,   521,   520,   529,   553,
     554,   564,   569,   570,   576,   581,   583,   598,   600,   619,
     638,   657,   676,   703,   777,   780,   785,   801,   814,   813,
     839,   838,   861,   862,   874,   905,   929,   931,   937,   942,
     936,   955,   965,   971
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_TYPE", "_IF", "_ELSE", "_RETURN",
  "_ID", "_INT_NUMBER", "_UINT_NUMBER", "_LPAREN", "_RPAREN", "_LBRACKET",
  "_RBRACKET", "_ASSIGN", "_SEMICOLON", "_AROP", "_ADD", "_SUB", "_MUL",
  "_DIV", "_RELOP", "_COMMA", "_INC", "_FOR", "_Q_MARK", "_TWO_DOTS",
  "_BRANCH", "_FIRST", "_SECOND", "_THIRD", "_OTHERWISE", "_END_BRANCH",
  "_SWITCH", "_CASE", "_BREAK", "_DEFAULT", "_POW", "ONLY_IF", "PRIORITY",
  "$accept", "program", "global_variable_list", "global_variable",
  "function_list", "function", "$@1", "parameter", "parameters", "body",
  "$@2", "variable_list", "variable", "$@3", "vars", "statement_list",
  "statement", "compound_statement", "assignment_statement",
  "for_statement", "$@4", "$@5", "branch_statement", "$@6", "$@7", "$@8",
  "$@9", "$@10", "$@11", "$@12", "$@13", "switch_statement", "$@14",
  "case", "$@15", "cases", "break", "default", "$@16", "conditional_exp",
  "con_exp", "num_exp", "exp", "literal", "increment_statement",
  "increment", "void_function_call", "$@17", "function_call", "$@18",
  "argument", "arguments", "if_statement", "if_part", "@19", "$@20",
  "rel_exp", "return_statement", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF (-110)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-81)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -110,    26,    36,  -110,    40,  -110,    46,  -110,    28,    52,
    -110,  -110,    43,  -110,    58,    56,    62,    45,  -110,    71,
      81,  -110,  -110,    67,    83,  -110,  -110,  -110,  -110,    82,
       5,  -110,    42,    78,     6,    -4,  -110,  -110,    84,    86,
      87,  -110,  -110,  -110,  -110,  -110,  -110,  -110,    76,  -110,
    -110,    93,  -110,  -110,    85,  -110,    -3,  -110,  -110,   108,
    -110,   108,  -110,    89,    94,  -110,  -110,  -110,   108,  -110,
      90,    38,    98,    95,   103,  -110,    48,  -110,   108,   109,
      19,   110,    91,  -110,   108,   108,   108,   108,   108,   105,
     108,  -110,   115,   112,  -110,  -110,   102,  -110,   108,  -110,
     108,   104,   -14,   -14,    91,    91,    91,  -110,  -110,   121,
     111,   119,    61,   125,   126,   127,  -110,    69,   124,   108,
    -110,   120,   129,    48,  -110,  -110,   117,  -110,  -110,  -110,
     108,    61,   113,  -110,    69,  -110,   123,    69,  -110,     1,
    -110,   131,    61,  -110,  -110,  -110,   136,   143,   140,   128,
     130,  -110,   132,  -110,    48,    48,   141,   133,   118,  -110,
      48,  -110,   142,  -110,  -110,    48,  -110,  -110,   134,  -110,
      48,  -110,   135,  -110,    48,  -110,   137,  -110,    48,   138,
    -110
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     4,     2,     6,     8,     0,
       7,     5,     0,     8,    10,     0,     0,    11,    12,     0,
       0,    16,     9,     0,    14,    13,    18,    22,    17,     0,
       0,    20,     0,     0,     0,    78,    22,    15,     0,     0,
       0,    23,    24,    25,    29,    30,    32,    28,     0,    31,
      26,    86,    27,    19,     0,    88,    63,    74,    75,     0,
      92,     0,    67,     0,    61,    62,    66,    64,     0,    77,
       0,     0,     0,     0,     0,    76,     0,    21,     0,     0,
       0,     0,    72,    93,     0,     0,     0,     0,     0,     0,
      82,    33,     0,     0,    47,    87,     0,    89,    82,    65,
       0,     0,    68,    69,    70,    71,    73,    34,    84,     0,
      83,     0,     0,     0,     0,     0,    91,     0,     0,     0,
      35,     0,     0,     0,    81,    60,     0,    59,    79,    85,
       0,     0,     0,    90,     0,    36,     0,     0,    51,    55,
      58,     0,     0,    49,    56,    52,     0,     0,     0,     0,
       0,    48,     0,    38,     0,     0,     0,     0,    53,    57,
       0,    39,     0,    50,    37,     0,    54,    40,     0,    41,
       0,    42,     0,    43,     0,    44,     0,    45,     0,     0,
      46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,  -110,  -110,  -110,   152,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,   139,   -75,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,    20,  -110,  -110,  -110,  -110,  -110,  -110,
    -103,   -32,    21,  -109,  -110,   -30,  -110,  -110,  -110,  -110,
      64,  -110,  -110,  -110,  -110,  -110,   -74,  -110
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     6,     7,    12,    16,    17,    22,
      27,    24,    28,    29,    32,    30,    41,    42,    43,    44,
     130,   141,    45,   157,   165,   168,   170,   172,   174,   176,
     178,    46,   113,   138,   149,   139,   163,   146,   150,    62,
     126,    96,    64,    65,    47,    66,    49,    70,    67,    79,
     109,   110,    50,    51,    78,   114,    81,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    95,    63,   121,    97,    86,    87,   -80,   127,    33,
      68,    34,    35,    56,    57,    58,    59,    36,    37,    69,
      69,    60,   136,    88,    61,   127,     3,    80,   127,    38,
      99,   140,    39,   148,   143,   137,    89,   144,    40,     4,
     100,    48,    33,    11,    34,    35,    48,     8,   133,     9,
      36,    91,    33,    14,    34,    35,   135,    53,   108,    13,
      36,    15,    38,    18,    54,    39,   108,    20,   116,    57,
      58,    40,    38,    19,    25,    39,   125,    57,    58,   158,
     159,    40,    82,    21,    23,   164,    26,   129,    55,    31,
     167,    75,    77,    48,    72,   171,    73,    74,    76,   175,
      90,    92,    93,   179,    83,   102,   103,   104,   105,   106,
      94,    84,    85,    86,    87,    56,    57,    58,    59,    98,
     107,   101,   111,   100,    48,    48,    61,   112,    88,   117,
      48,    88,   118,   119,   120,    48,   122,   123,   124,   128,
      48,   132,   131,   134,    48,   142,   147,   137,    48,   151,
     152,   153,   160,   162,   154,   156,   155,   166,    10,   145,
       0,   161,   115,   169,     0,   173,     0,     0,   177,     0,
     180,     0,     0,     0,     0,    71
};

static const yytype_int16 yycheck[] =
{
      30,    76,    34,   112,    78,    19,    20,    10,   117,     4,
      14,     6,     7,     7,     8,     9,    10,    12,    13,    23,
      23,    15,   131,    37,    18,   134,     0,    59,   137,    24,
      11,   134,    27,   142,   137,    34,    68,    36,    33,     3,
      21,    71,     4,    15,     6,     7,    76,     7,   123,     3,
      12,    13,     4,    10,     6,     7,   130,    15,    90,     7,
      12,     3,    24,     7,    22,    27,    98,    22,   100,     8,
       9,    33,    24,    11,     7,    27,     7,     8,     9,   154,
     155,    33,    61,    12,     3,   160,     3,   119,    10,     7,
     165,    15,     7,   123,    10,   170,    10,    10,     5,   174,
      10,     3,     7,   178,    15,    84,    85,    86,    87,    88,
       7,    17,    18,    19,    20,     7,     8,     9,    10,    10,
      15,    11,     7,    21,   154,   155,    18,    15,    37,    25,
     160,    37,    11,    22,    15,   165,    11,    11,    11,    15,
     170,    12,    22,    26,   174,    22,    15,    34,   178,    13,
       7,    11,    11,    35,    26,    23,    26,    15,     6,   139,
      -1,    28,    98,    29,    -1,    30,    -1,    -1,    31,    -1,
      32,    -1,    -1,    -1,    -1,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    41,    42,     0,     3,    43,    44,    45,     7,     3,
      45,    15,    46,     7,    10,     3,    47,    48,     7,    11,
      22,    12,    49,     3,    51,     7,     3,    50,    52,    53,
      55,     7,    54,     4,     6,     7,    12,    13,    24,    27,
      33,    56,    57,    58,    59,    62,    71,    84,    85,    86,
      92,    93,    97,    15,    22,    10,     7,     8,     9,    10,
      15,    18,    79,    81,    82,    83,    85,    88,    14,    23,
      87,    55,    10,    10,    10,    15,     5,     7,    94,    89,
      81,    96,    82,    15,    17,    18,    19,    20,    37,    81,
      10,    13,     3,     7,     7,    56,    81,    96,    10,    11,
      21,    11,    82,    82,    82,    82,    82,    15,    81,    90,
      91,     7,    15,    72,    95,    90,    81,    25,    11,    22,
      15,    83,    11,    11,    11,     7,    80,    83,    15,    81,
      60,    22,    12,    56,    26,    96,    83,    34,    73,    75,
      80,    61,    22,    80,    36,    73,    77,    15,    83,    74,
      78,    13,     7,    11,    26,    26,    23,    63,    56,    56,
      11,    28,    35,    76,    56,    64,    15,    56,    65,    29,
      66,    56,    67,    30,    68,    56,    69,    31,    70,    56,
      32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    44,    44,    46,    45,
      47,    47,    48,    48,    50,    49,    51,    51,    53,    52,
      54,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    58,    60,    61,    59,    63,    64,
      65,    66,    67,    68,    69,    70,    62,    72,    71,    74,
      73,    75,    75,    76,    76,    77,    78,    77,    79,    80,
      80,    81,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    83,    83,    84,    85,    87,    86,
      89,    88,    90,    90,    91,    91,    92,    92,    94,    95,
      93,    96,    97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     3,     1,     2,     0,     7,
       0,     1,     2,     4,     0,     5,     0,     2,     0,     4,
       1,     3,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     0,     0,    13,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     9,     0,
       6,     1,     2,     0,     2,     0,     0,     4,     7,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     3,     3,
       3,     3,     2,     3,     1,     1,     2,     2,     0,     6,
       0,     5,     0,     1,     1,     3,     1,     3,     0,     0,
       7,     3,     2,     3
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
#line 128 "semantic.y"
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
#line 1546 "semantic.tab.c"
    break;

  case 5:
#line 141 "semantic.y"
          {
		if(lookup_symbol((yyvsp[-1].s), GVAR) == NO_INDEX)
		{
           insert_symbol((yyvsp[-1].s), GVAR, (yyvsp[-2].i), NO_ATR, NO_ATR, NO_ATR, NO_ATR); 
           code("\n%s:\n\t\tWORD\t1", (yyvsp[-1].s));
        }
        else 
           err("redefinition of global '%s'", (yyvsp[-1].s));
	  }
#line 1560 "semantic.tab.c"
    break;

  case 8:
#line 159 "semantic.y"
      {
        fun_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fun_idx == NO_INDEX)
        {
          fun_idx = insert_symbol((yyvsp[0].s), FUN, (yyvsp[-1].i), NO_ATR, NO_ATR, NO_ATR, NO_ATR);
          Fun_params[num].fun_id = fun_idx;  //  i need this to find it again
        }
        else 
          err("redefinition of function '%s'", (yyvsp[0].s));
          
        code("\n%s:", (yyvsp[0].s));
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
#line 1579 "semantic.tab.c"
    break;

  case 9:
#line 174 "semantic.y"
      {
      	if(get_type(fun_idx) != VOID && return_flag == FALSE)
      		warn("Function %s should return value!", get_name(fun_idx));
      	
      	// print_symtab();	
      	Fun_params[num].count_param = param_num;
      		
        clear_symbols(fun_idx + 1);
        var_num = 0;
        num++;
        param_num = 0;
        return_flag = FALSE;
        int_par_num = 0;
        uint_par_num = 0;
        
        code("\n@%s_exit:", (yyvsp[-5].s));
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
#line 1604 "semantic.tab.c"
    break;

  case 10:
#line 198 "semantic.y"
      {
      	 set_atr1(fun_idx, 0);
      	 set_atr3(fun_idx, 0);
      }
#line 1613 "semantic.tab.c"
    break;

  case 12:
#line 207 "semantic.y"
      {
      	if ((yyvsp[-1].i) == VOID)
      		err("Parametar can't be void type, redefine %s!", (yyvsp[0].s));
    	
    	if(lookup_symbol((yyvsp[0].s), PAR) == NO_INDEX)
    	{
      		if( (yyvsp[-1].i) == INT ) // This is for one par type int
      		{
      			Fun_params[num].fun_types[param_num] = (yyvsp[-1].i);
      			++int_par_num;
				insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), int_par_num + uint_par_num, NO_ATR, NO_ATR, NO_ATR);
				set_atr1(fun_idx, int_par_num);
				set_atr2(fun_idx, (yyvsp[-1].i));

			}
		    else if ( (yyvsp[-1].i) == UINT ) // this is for one par type unsigned
		    {
		    	Fun_params[num].fun_types[param_num] = (yyvsp[-1].i);
		    	++uint_par_num;
		    	insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), int_par_num + uint_par_num, NO_ATR, NO_ATR, NO_ATR);
				set_atr3(fun_idx, uint_par_num);
				set_atr4(fun_idx, (yyvsp[-1].i));
		    }
		    
		    param_num++;
        }
        else
        	err("Parameter already exist in function %s, change parametar %s!", get_name(fun_idx), (yyvsp[0].s));
      }
#line 1647 "semantic.tab.c"
    break;

  case 13:
#line 237 "semantic.y"
                {
		  	if ((yyvsp[-1].i) == VOID)
		  		err("Parametar can't be void type, redefine %s!", (yyvsp[0].s));
		  	if (lookup_symbol((yyvsp[0].s), PAR) == NO_INDEX)
		  	{
			  	if ( (yyvsp[-1].i) == INT)
			  	{	
			  		Fun_params[num].fun_types[param_num] = (yyvsp[-1].i);
			  		++int_par_num;
					insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), int_par_num + uint_par_num, NO_ATR, NO_ATR, NO_ATR);
					set_atr1(fun_idx, int_par_num);
					set_atr2(fun_idx, INT);
				}
				else if ( (yyvsp[-1].i) == UINT )
				{	
					Fun_params[num].fun_types[param_num] = (yyvsp[-1].i);
					++uint_par_num;
					insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), int_par_num + uint_par_num, NO_ATR, NO_ATR, NO_ATR);
					set_atr3(fun_idx, uint_par_num);
					set_atr4(fun_idx, UINT);
				}
				
				param_num++;
			}
			else
				err("Parametar %s already exist in function %s!", (yyvsp[0].s), get_name(fun_idx));

      }
#line 1680 "semantic.tab.c"
    break;

  case 14:
#line 269 "semantic.y"
          {
        if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
      }
#line 1690 "semantic.tab.c"
    break;

  case 18:
#line 283 "semantic.y"
                { var_type = (yyvsp[0].i); }
#line 1696 "semantic.tab.c"
    break;

  case 20:
#line 286 "semantic.y"
                {
        if(lookup_symbol((yyvsp[0].s), VAR|PAR) == NO_INDEX && var_type != VOID)
           insert_symbol((yyvsp[0].s), VAR, var_type, ++var_num, NO_ATR, NO_ATR, NO_ATR);
        else 
      	{
      		if(var_type == VOID)
      			err("Can't be void type: '%s'", (yyvsp[0].s));
      		else
      			err("Redefinition of '%s'", (yyvsp[0].s));
      	}
      }
#line 1712 "semantic.tab.c"
    break;

  case 21:
#line 298 "semantic.y"
                {
        if(lookup_symbol((yyvsp[0].s), VAR|PAR) == NO_INDEX && var_type != VOID)
           insert_symbol((yyvsp[0].s), VAR, var_type, ++var_num, NO_ATR, NO_ATR, NO_ATR);
        else 
         {
      		if(var_type == VOID)
      			err("Can't be void type: '%s'", (yyvsp[0].s));
      		else
      			err("Redefinition of '%s'", (yyvsp[0].s));
      	}
      }
#line 1728 "semantic.tab.c"
    break;

  case 34:
#line 334 "semantic.y"
      {
        int idx = lookup_symbol((yyvsp[-3].s), VAR|PAR|GVAR);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", (yyvsp[-3].s));
        else
          if(get_type(idx) != get_type((yyvsp[-1].i)))
            err("incompatible types in assignment");
        
        gen_mov((yyvsp[-1].i), idx);
      }
#line 1743 "semantic.tab.c"
    break;

  case 35:
#line 348 "semantic.y"
        {
  		if(lookup_symbol((yyvsp[-1].s), VAR|PAR|GVAR) == NO_INDEX) // dodala sam gvar, brojac mora biti jedinstven za svaku for petlju
  			{ 
  				insert_symbol((yyvsp[-1].s), VAR, (yyvsp[-2].i), ++var_num, NO_ATR, NO_ATR, NO_ATR);
  				/*for_index = lookup_symbol($4, VAR);
  				for_reg = take_reg();
  				code("\n\t\tMOV\t");
  				code("$1");
  				code(",");
  				gen_sym_name(for_reg);
  				*/
  				var_num_f = var_num;
  				++for_num;
  				++for_num_u;
  				if(for_num > max_for_num)
  					max_for_num = for_num;
  				// stavljam iterator petlje na stack
  				code("\n\t\tSUBS\t%%15,$4,%%15");
  				code("\n\t\tMOV $1, %d(%%14)", -var_num_f*4); 
  				code("\n@for_begins%d:", for_num );
  			}
  		else 
  			err("Already exists '%s' can't use it for iteration through for loop, change it!", (yyvsp[-1].s));
  	}
#line 1772 "semantic.tab.c"
    break;

  case 36:
#line 373 "semantic.y"
        { code("\n\t\t%s\t@for_end%d", opp_jumps[(yyvsp[0].i)], for_num);  }
#line 1778 "semantic.tab.c"
    break;

  case 37:
#line 375 "semantic.y"
      {
      	
      	if(get_type((yyvsp[-10].i)) == INT)
			code("\n\t\tADDS\t");	
		else
			code("\n\t\tADDU\t");	
			
			code("%d(%%14)", -var_num_f*4); 
			code(",");
			code("$1");
			code(",");
			code("%d(%%14)", -var_num_f*4); 
		
		code("\n\t\tJMP\t\t@for_begins%d", for_num);
		code("\n@for_end%d:", for_num);
		code("\n\t\tADDS\t%%15,$4,%%15");
	
		// code za numerisanje labela
		if(--for_num_u)
			--for_num;
		else
			for_num = max_for_num;
		--var_num_f;
		
      }
#line 1808 "semantic.tab.c"
    break;

  case 38:
#line 404 "semantic.y"
        {
  		int id_index = lookup_symbol((yyvsp[-7].s), VAR|PAR|GVAR);
  		if( id_index == NO_INDEX)
  			err("Variable '%s' have to be declared beforhand, to bu used in baranch statement! ", (yyvsp[-7].s));
  			
  		if(get_type(id_index) != get_type((yyvsp[-5].i)) || get_type(id_index) != get_type((yyvsp[-3].i)) || get_type(id_index) != get_type((yyvsp[-1].i)))
  			err("Incompatible types in branch statement, all numbers have to be the same type as %s !" , (yyvsp[-7].s));
  		
  		// generisanje koda za branch

  		gen_cmp(id_index, (yyvsp[-5].i));
  		code("\n\t\tJEQ\t@first%d", branch_num);
  		

  		gen_cmp(id_index, (yyvsp[-3].i));
  		code("\n\t\tJEQ\t@second%d", branch_num);
  		

  		gen_cmp(id_index, (yyvsp[-1].i));
  		code("\n\t\tJEQ\t@third%d", branch_num);
  		code("\n\t\tJMP\t@otherwise%d", branch_num);  
  		
  	}
#line 1836 "semantic.tab.c"
    break;

  case 39:
#line 428 "semantic.y"
               { code("\n@first%d:", branch_num); }
#line 1842 "semantic.tab.c"
    break;

  case 40:
#line 429 "semantic.y"
                           { code("\n\t\tJMP\t@end_branch%d", branch_num);}
#line 1848 "semantic.tab.c"
    break;

  case 41:
#line 430 "semantic.y"
                { code("\n@second%d:", branch_num); }
#line 1854 "semantic.tab.c"
    break;

  case 42:
#line 431 "semantic.y"
                           { code("\n\t\tJMP\t@end_branch%d", branch_num);}
#line 1860 "semantic.tab.c"
    break;

  case 43:
#line 432 "semantic.y"
               { code("\n@third%d:", branch_num); }
#line 1866 "semantic.tab.c"
    break;

  case 44:
#line 433 "semantic.y"
                           { code("\n\t\tJMP\t@end_branch%d", branch_num);}
#line 1872 "semantic.tab.c"
    break;

  case 45:
#line 434 "semantic.y"
                   { code("\n@otherwise%d:", branch_num); }
#line 1878 "semantic.tab.c"
    break;

  case 46:
#line 436 "semantic.y"
                    { code("\n@end_branch%d:", branch_num); 
  	
  	branch_num++;
  	}
#line 1887 "semantic.tab.c"
    break;

  case 47:
#line 444 "semantic.y"
        {
  		int id_index = lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR);
  		if(id_index == NO_INDEX)
  			err("Variable '%s' have to be declared beforhand, to bu used in baranch statement! ", (yyvsp[0].s));
  			
		switch_exp_id = id_index;
		
		code("\n@switch_%d:\n", ++switch_num);
		code("\n\t\tJMP @switch_check_%d\n", switch_num);
    }
#line 1902 "semantic.tab.c"
    break;

  case 48:
#line 455 "semantic.y"
         {
	    code("\n\t\tJMP @switch_end_%d\n", switch_num);
		code("\n@switch_check_%d:\n", switch_num);
	    for(int i = 0; i < case_num; i++)
	    {
	        gen_cmp(switch_exp_id, cases[i]);
	        code("\n\t\tJEQ @case_%d_%d", switch_num, i);
        }
        
        if(default_case == TRUE)
        {
            code("\n\t\tJMP @default_%d", switch_num);
        }
        
	    code("\n@switch_end_%d:\n", switch_num);
	    
		// clean up
	    for(int i = 0; i < MAX_CASES; i++)
	    {
	        cases[i] = NO_INDEX;
	    }
	          
        case_num = 0;
	    default_case = FALSE;
	 }
#line 1932 "semantic.tab.c"
    break;

  case 49:
#line 484 "semantic.y"
    {
    	if(get_type((yyvsp[0].i)) != get_type(switch_exp_id))
   		    err("Case value is not the same type as switch expression!");
   		
   		if(case_num == MAX_CASES)
   		{
	        err("Max number of cases is 10.");
   		}
        
        for(int i = 0; i <= case_num; i++)
            if(cases[i] == (yyvsp[0].i))
                err("Case expressions must be unique!");
        
        cases[case_num] = (yyvsp[0].i);
        code("\n@case_%d_%d:", switch_num, case_num);
        ++case_num;
	   
    }
#line 1955 "semantic.tab.c"
    break;

  case 54:
#line 513 "semantic.y"
   {
        code("\n\t\tJMP @switch_end_%d\n", switch_num);
   }
#line 1963 "semantic.tab.c"
    break;

  case 56:
#line 521 "semantic.y"
    {
        default_case = TRUE;
        code("\n@default_%d:\n", switch_num);
    }
#line 1972 "semantic.tab.c"
    break;

  case 58:
#line 530 "semantic.y"
                {	
			if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
				err("\nOperands are different types in conditional expression!");
			
			//  cmp  je izgenerisao rel_exp
			++con_num;
			code("\n\t\t%s\t@con_false%d", opp_jumps[(yyvsp[-5].i)], con_num); 
			code("\n@con_true%d:", con_num);
			
			int reg = take_reg();

			gen_mov((yyvsp[-2].i), reg);
			code("\n\t\tJMP \t@con_exit%d", con_num);

			code("\n@con_false%d:", con_num);
			gen_mov((yyvsp[0].i) , reg);

			(yyval.i) = reg;
		    	code("\n@con_exit%d:", con_num);
		}
#line 1997 "semantic.tab.c"
    break;

  case 60:
#line 555 "semantic.y"
         {
		int index = lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR);
		if(index == NO_INDEX)
			err("\nId %s is not declared!", get_name(index));
		(yyval.i) = index;
	 }
#line 2008 "semantic.tab.c"
    break;

  case 61:
#line 565 "semantic.y"
        { (yyval.i) = (yyvsp[0].i); }
#line 2014 "semantic.tab.c"
    break;

  case 63:
#line 571 "semantic.y"
          {
	    (yyval.i) = lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR);
	    if((yyval.i) == NO_INDEX)
	    	err("[%s] undeclared", (yyvsp[0].s));
	  }
#line 2024 "semantic.tab.c"
    break;

  case 64:
#line 577 "semantic.y"
      {
      	(yyval.i) = take_reg();
      	gen_mov(FUN_REG, (yyval.i));
      }
#line 2033 "semantic.tab.c"
    break;

  case 65:
#line 582 "semantic.y"
          { (yyval.i) = (yyvsp[-1].i); }
#line 2039 "semantic.tab.c"
    break;

  case 66:
#line 584 "semantic.y"
          { 
  	  	int t1 = get_type((yyvsp[0].i));
  	  	(yyval.i) = take_reg();
  	  	set_type((yyval.i), t1);
  	  	gen_mov((yyvsp[0].i), (yyval.i));
  	  	if(t1 == INT)
			code("\n\t\tADDS\t");
		else
			code("\n\t\tADDU\t");
		gen_sym_name((yyvsp[0].i));
		code(", $1, ");
		gen_sym_name((yyvsp[0].i));
		free_if_reg((yyvsp[0].i));
  	  }
#line 2058 "semantic.tab.c"
    break;

  case 67:
#line 599 "semantic.y"
          { (yyval.i) = (yyvsp[0].i); }
#line 2064 "semantic.tab.c"
    break;

  case 68:
#line 601 "semantic.y"
      {		
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("Invalid operands: arithmetic operation!");
        int t1 = get_type((yyvsp[-2].i));  
        if(get_type((yyvsp[-2].i)) == INT)
			code("\n\t\tADDS\t");
		else
			code("\n\t\tADDU\t");
        gen_sym_name((yyvsp[-2].i));
        code(",");
        gen_sym_name((yyvsp[0].i));
        code(",");
        free_if_reg((yyvsp[0].i));
        free_if_reg((yyvsp[-2].i));
        (yyval.i) = take_reg();
        gen_sym_name((yyval.i));
        set_type((yyval.i), t1);
      }
#line 2087 "semantic.tab.c"
    break;

  case 69:
#line 620 "semantic.y"
      {		
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("Invalid operands: arithmetic operation!");
        int t1 = get_type((yyvsp[-2].i));  
        if(get_type((yyvsp[-2].i)) == INT)
			code("\n\t\tSUBS\t");
		else
			code("\n\t\tSUBU\t");
        gen_sym_name((yyvsp[-2].i));
        code(",");
        gen_sym_name((yyvsp[0].i));
        code(",");
        free_if_reg((yyvsp[0].i));
        free_if_reg((yyvsp[-2].i));
        (yyval.i) = take_reg();
        gen_sym_name((yyval.i));
        set_type((yyval.i), t1);
      }
#line 2110 "semantic.tab.c"
    break;

  case 70:
#line 639 "semantic.y"
      {		
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("Invalid operands: arithmetic operation!");
        int t1 = get_type((yyvsp[-2].i));  
        if(get_type((yyvsp[-2].i)) == INT)
			code("\n\t\tMULS\t");
		else
			code("\n\t\tMULU\t");
        gen_sym_name((yyvsp[-2].i));
        code(",");
        gen_sym_name((yyvsp[0].i));
        code(",");
        free_if_reg((yyvsp[0].i));
        free_if_reg((yyvsp[-2].i));
        (yyval.i) = take_reg();
        gen_sym_name((yyval.i));
        set_type((yyval.i), t1);
      }
#line 2133 "semantic.tab.c"
    break;

  case 71:
#line 658 "semantic.y"
      {		
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("Invalid operands: arithmetic operation!");
        int t1 = get_type((yyvsp[-2].i));  
        if(get_type((yyvsp[-2].i)) == INT)
			code("\n\t\tDIVS\t");
		else
			code("\n\t\tDIVU\t");
        gen_sym_name((yyvsp[-2].i));
        code(",");
        gen_sym_name((yyvsp[0].i));
        code(",");
        free_if_reg((yyvsp[0].i));
        free_if_reg((yyvsp[-2].i));
        (yyval.i) = take_reg();
        gen_sym_name((yyval.i));
        set_type((yyval.i), t1);
      }
#line 2156 "semantic.tab.c"
    break;

  case 72:
#line 677 "semantic.y"
          { 
  	  	int t1 = get_type((yyvsp[0].i));  
        int pom_reg = take_reg();
        set_type(pom_reg, t1);
        if(t1 == INT)
        	code("\n\t\tSUBS\t");
        else
        	code("\n\t\tSUBU\t");
        gen_sym_name(pom_reg);
        code(" , ");
        gen_sym_name(pom_reg);
        code(" , ");
        gen_sym_name(pom_reg); 
        if(t1 == INT)
			code("\n\t\tSUBS\t");
		else
			code("\n\t\tSUBU\t");
        gen_sym_name(pom_reg);
        code(",");
        gen_sym_name((yyvsp[0].i));
        code(",");
        free_if_reg((yyvsp[0].i));
        (yyval.i) = pom_reg;
        gen_sym_name((yyval.i));

  	  }
#line 2187 "semantic.tab.c"
    break;

  case 73:
#line 704 "semantic.y"
      {
         if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("Invalid operands in power operation");
        int t1 = get_type((yyvsp[-2].i));  
        int idx = take_reg();          // reg_rezultat_stepena;
        int br = take_reg();		  // reg_brojac;
        gen_mov((yyvsp[-2].i), idx);				// reg_rezultat_stepena =  5;
        gen_mov((yyvsp[0].i), br);				// reg_brojac = 3;
        
        // provera da li je stepen nula
        if(get_type((yyvsp[0].i)) == INT)
            code("\n\t\tCMPS\t");
        else
            code("\n\t\tCMPU\t");
        gen_sym_name(br);
        code(", $0");
        code("\n\t\tJEQ\t@pow_is_zero%d" , pow_num);
        
        // dekrement, umanjujemo brojac za jedan  -> reg_brojac = 2; zato sto mi se u rez vec nalazi vrednost osnove stepena
        if(get_type((yyvsp[0].i)) == INT)
            code("\n\t\tSUBS\t");
        else					
            code("\n\t\tSUBU\t");
        gen_sym_name(br);
        code(", $1, ");
        gen_sym_name(br);
        // pocinje petlja stepena ako je stepen veci od 1
        code("\n@pow_loop%d:" , pow_num);
        // provera da li mi je brojac = 0
        if(get_type((yyvsp[-2].i)) == INT)
            code("\n\t\tCMPS\t");
        else
            code("\n\t\tCMPU\t");
        gen_sym_name(br);
        code(", $0");
        // ako jeste, skaci na kraj
        code("\n\t\tJEQ\t@pow_exit%d" , pow_num);
        // ako nije mnozi rezultat osnovom stepena
        if(get_type((yyvsp[-2].i)) == INT)
            code("\n\t\tMULS\t");
        else
            code("\n\t\tMULU\t");
        gen_sym_name((yyvsp[-2].i));
        code(",");
        gen_sym_name(idx);
        code(",");
        gen_sym_name(idx);
        // smanjim brojac
        if(get_type((yyvsp[0].i)) == INT)
            code("\n\t\tSUBS\t");
        else
            code("\n\t\tSUBU\t");
        gen_sym_name(br);
        code(", $1, ");
        gen_sym_name(br);
        // bezuslovno skocim na pocetak radi provere brojaca
        code("\n\t\tJMP\t@pow_loop%d" , pow_num);
        // na ovu labelu ce doci samo kad je stepen nula , npr. 5^0 ili a^0 i tada je rezultat uvek 1
        code("\n@pow_is_zero%d:", pow_num);
        code("\n\t\tMOV\t$1,");
        gen_sym_name(idx);
        code("\n@pow_exit%d:", pow_num);
        free_if_reg((yyvsp[0].i));
        free_if_reg((yyvsp[-2].i));
        free_if_reg(br);
        (yyval.i) = idx;
        set_type(idx, t1);
        pow_num++;
      }
#line 2261 "semantic.tab.c"
    break;

  case 74:
#line 778 "semantic.y"
      { (yyval.i) = insert_literal((yyvsp[0].s), INT); }
#line 2267 "semantic.tab.c"
    break;

  case 75:
#line 781 "semantic.y"
      { (yyval.i) = insert_literal((yyvsp[0].s), UINT); }
#line 2273 "semantic.tab.c"
    break;

  case 76:
#line 786 "semantic.y"
                {
			if(get_type((yyvsp[-1].i)) == INT)
				code("\n\t\tADDS\t");
			else
				code("\n\t\tADDU\t");
			gen_sym_name((yyvsp[-1].i));
			code(",");
			code("$1");
			code(",");
			gen_sym_name((yyvsp[-1].i));
			free_if_reg((yyvsp[-1].i));
		}
#line 2290 "semantic.tab.c"
    break;

  case 77:
#line 802 "semantic.y"
                {
			if(lookup_symbol((yyvsp[-1].s), FUN) != NO_INDEX)
				err("Function can't be incremented '%s'!", (yyvsp[-1].s) );
			else if(lookup_symbol((yyvsp[-1].s), VAR|PAR|GVAR) == NO_INDEX)
				err("Not defined variable or parametar, can't use increment on '%s'! \n", (yyvsp[-1].s) );
			else
				(yyval.i) = lookup_symbol((yyvsp[-1].s), VAR|PAR|GVAR);
		}
#line 2303 "semantic.tab.c"
    break;

  case 78:
#line 814 "semantic.y"
      {
        fcall_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", (yyvsp[0].s));
        if(get_type(fcall_idx) != VOID)
        	err("Function '%s' is not void function, can't call it like this!", (yyvsp[0].s));
      }
#line 2315 "semantic.tab.c"
    break;

  case 79:
#line 822 "semantic.y"
      {
        if((get_atr1(fcall_idx) + get_atr3(fcall_idx)) != (yyvsp[-2].i))  // count of all atributs == atributes entered
          err("Wrong number of arguments to function '%s'", get_name(fcall_idx));
        
        code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if((yyvsp[-2].i) > 0)
        code("\n\t\t\tADDS\t%%15,$%d,%%15", (yyvsp[-2].i) * 4);
        
        set_type(FUN_REG, get_type(fcall_idx));
        num_of_args = 0;
        (yyval.i) = FUN_REG;
      }
#line 2332 "semantic.tab.c"
    break;

  case 80:
#line 839 "semantic.y"
      {
        fcall_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", (yyvsp[0].s));
      }
#line 2342 "semantic.tab.c"
    break;

  case 81:
#line 845 "semantic.y"
      {
        if((get_atr1(fcall_idx) + get_atr3(fcall_idx)) != (yyvsp[-1].i))  // count of all atributs == atributes entered
          err("Wrong number of arguments to function '%s'", get_name(fcall_idx));
        
        code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if((yyvsp[-1].i) > 0)
        code("\n\t\t\tADDS\t%%15,$%d,%%15", (yyvsp[-1].i) * 4);
          
        set_type(FUN_REG, get_type(fcall_idx));
        num_of_args = 0;
        (yyval.i) = FUN_REG;
      }
#line 2359 "semantic.tab.c"
    break;

  case 82:
#line 861 "semantic.y"
    { (yyval.i) = 0; }
#line 2365 "semantic.tab.c"
    break;

  case 83:
#line 863 "semantic.y"
        {
  		(yyval.i) = (yyvsp[0].i);
  		for(int i = num_of_args; i >= 0; i--)
  		{
  			code("\n\t\t\tPUSH\t");
        	gen_sym_name(ArgsArray[i]);
  		}
  	}
#line 2378 "semantic.tab.c"
    break;

  case 84:
#line 875 "semantic.y"
    { 

      type_of_arg = get_type((yyvsp[0].i));
      for(int i = 0; i < get_last_element(); i++)
      {
      	if(fcall_idx == Fun_params[i].fun_id)
      	{
      		if(Fun_params[i].fun_types[num_of_args] == type_of_arg)
			{}
      		else
      			err("Wrong arguments in function call '%s'", get_name(fcall_idx));     	
      	}
      }

      if(get_type((yyvsp[0].i)) == INT)
      {
      	if(get_atr2(fcall_idx) != get_type((yyvsp[0].i)))
      		err("Incompatible type for argument in function call '%s' ", get_name(fcall_idx));
      } else
      {
      	if(get_atr4(fcall_idx) != get_type((yyvsp[0].i)))
      		err("Incompatible type for argument in function call '%s' ", get_name(fcall_idx));
      }
	  
	  free_if_reg((yyvsp[0].i));
	  ArgsArray[num_of_args] = (yyvsp[0].i);
	  
      num_of_args++;
      (yyval.i) = num_of_args;
    }
#line 2413 "semantic.tab.c"
    break;

  case 85:
#line 906 "semantic.y"
        {	
  	  type_of_arg = get_type((yyvsp[0].i));
      for(int i = 0; i < get_last_element(); i++)
      {
      	if(fcall_idx == Fun_params[i].fun_id)
      	{
      		if(Fun_params[i].fun_types[num_of_args] == type_of_arg)
      			{}
      		else
      			err("Wrong arguments in function call '%s'", get_name(fcall_idx)); 
	
      	}
      }
      	
      	free_if_reg((yyvsp[0].i));
      	ArgsArray[num_of_args] = (yyvsp[0].i);
      	
  		num_of_args++;
  		(yyval.i) = num_of_args;
  	}
#line 2438 "semantic.tab.c"
    break;

  case 86:
#line 930 "semantic.y"
        { code("\n@exit%d:", (yyvsp[0].i)); }
#line 2444 "semantic.tab.c"
    break;

  case 87:
#line 932 "semantic.y"
        { code("\n@exit%d:", (yyvsp[-2].i)); }
#line 2450 "semantic.tab.c"
    break;

  case 88:
#line 937 "semantic.y"
        {
        (yyval.i) = ++lab_num;
        code("\n@if%d:", lab_num);
    }
#line 2459 "semantic.tab.c"
    break;

  case 89:
#line 942 "semantic.y"
     {
        code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[0].i)], (yyvsp[-1].i)); 
        code("\n@true%d:", (yyvsp[-1].i));
     }
#line 2468 "semantic.tab.c"
    break;

  case 90:
#line 947 "semantic.y"
      {
        code("\n\t\tJMP \t@exit%d", (yyvsp[-4].i));
        code("\n@false%d:", (yyvsp[-4].i));
        (yyval.i) = (yyvsp[-4].i);
      }
#line 2478 "semantic.tab.c"
    break;

  case 91:
#line 956 "semantic.y"
      {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: relational operator");
        (yyval.i) = (yyvsp[-1].i) + ((get_type((yyvsp[-2].i)) - 1) * RELOP_NUMBER);
        gen_cmp((yyvsp[-2].i), (yyvsp[0].i));
      }
#line 2489 "semantic.tab.c"
    break;

  case 92:
#line 966 "semantic.y"
        {	
  		return_flag = TRUE;
  		if(get_type(fun_idx) != VOID)
          warn("This function returns value! Missing return expression!");
  	}
#line 2499 "semantic.tab.c"
    break;

  case 93:
#line 972 "semantic.y"
      {
      	return_flag = TRUE;
        if(get_type(fun_idx) != get_type((yyvsp[-1].i)))
          err("incompatible types in return");
        else if (get_type(fun_idx) == VOID)
        	err("Void function can't have return value!");
        gen_mov((yyvsp[-1].i), FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));
          
      }
#line 2514 "semantic.tab.c"
    break;


#line 2518 "semantic.tab.c"

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
#line 984 "semantic.y"


int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();
  fclose(output);
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count) {
    remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;  //syntax error
  else if(error_count)
    return error_count & 127; //semantic errors
  else if(warning_count)
    return (warning_count & 127) + 127; //warnings
  else
    return 0; //OK
}

