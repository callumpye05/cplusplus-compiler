/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 120 "build/gen/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BUILD_GEN_PARSER_HPP_INCLUDED  */
