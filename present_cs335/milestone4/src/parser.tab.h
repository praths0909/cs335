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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    ABSTRACT = 258,
    CONTINUE = 259,
    FOR = 260,
    NEW = 261,
    SWITCH = 262,
    ASSERT = 263,
    DEFAULT = 264,
    IF = 265,
    PACKAGE = 266,
    SYNCHRONIZED = 267,
    BOOLEAN = 268,
    DO = 269,
    GOTO = 270,
    PRIVATE = 271,
    THIS = 272,
    BREAK = 273,
    DOUBLE = 274,
    IMPLEMENTS = 275,
    PROTECTED = 276,
    THROW = 277,
    BYTE = 278,
    ELSE = 279,
    IMPORT = 280,
    PUBLIC = 281,
    THROWS = 282,
    CASE = 283,
    ENUM = 284,
    RETURN = 285,
    TRANSIENT = 286,
    CATCH = 287,
    EXTENDS = 288,
    INT = 289,
    SHORT = 290,
    TRY = 291,
    CHAR = 292,
    FINAL = 293,
    INTERFACE = 294,
    STATIC = 295,
    VOID = 296,
    CLASS = 297,
    FINALLY = 298,
    LONG = 299,
    STRICTFP = 300,
    VOLATILE = 301,
    CONST = 302,
    FLOAT = 303,
    NATIVE = 304,
    SUPER = 305,
    WHILE = 306,
    UNDERSCORE = 307,
    EXPORTS = 308,
    OPENS = 309,
    PRINT = 310,
    REQUIRES = 311,
    USES = 312,
    MODULE = 313,
    PERMITS = 314,
    SEALED = 315,
    VAR = 316,
    NONSEALED = 317,
    PROVIDES = 318,
    TO = 319,
    WITH = 320,
    OPEN = 321,
    RECORD = 322,
    TRANSITIVE = 323,
    YIELD = 324,
    INTEGERLITERAL = 325,
    FLOATINGPOINTLITERAL = 326,
    BOOLEANLITERAL = 327,
    NULLLITERAL = 328,
    CHARACTERLITERAL = 329,
    STRING = 330,
    TEXTBLOCKS = 331,
    ESCAPESEQUENCE = 332,
    GT = 333,
    LT = 334,
    EXCLAM = 335,
    TILDA = 336,
    QM = 337,
    COLON = 338,
    IMPLIES = 339,
    DOUBLEEQUAL = 340,
    GTE = 341,
    LTE = 342,
    NE = 343,
    AND = 344,
    OR = 345,
    INCREAMENT = 346,
    DECREAMENT = 347,
    PLUS = 348,
    MINUS = 349,
    MULTIPLY = 350,
    DIVIDE = 351,
    BITAND = 352,
    BITOR = 353,
    BITXOR = 354,
    PERCENT = 355,
    LSHIFT = 356,
    RSHIFT = 357,
    THREEGT = 358,
    EQUAL = 359,
    NEWASSIGNMENTOPERATOR = 360,
    LRB = 361,
    RRB = 362,
    LCB = 363,
    RCB = 364,
    LSB = 365,
    RSB = 366,
    SEMICOLON = 367,
    COMMA = 368,
    DOT = 369,
    THREEDOT = 370,
    AT = 371,
    DOUBLECOLON = 372,
    IDENTIFIERWK = 373,
    INSTANCEOF = 374
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 1283 "parser.y"
char* str; struct Typeinfo* typeinfo;

#line 180 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
