/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER2_TAB_H_INCLUDED
# define YY_YY_PARSER2_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ABSTRACT = 258,                /* ABSTRACT  */
    CONTINUE = 259,                /* CONTINUE  */
    FOR = 260,                     /* FOR  */
    NEW = 261,                     /* NEW  */
    SWITCH = 262,                  /* SWITCH  */
    ASSERT = 263,                  /* ASSERT  */
    DEFAULT = 264,                 /* DEFAULT  */
    IF = 265,                      /* IF  */
    PACKAGE = 266,                 /* PACKAGE  */
    SYNCHRONIZED = 267,            /* SYNCHRONIZED  */
    BOOLEAN = 268,                 /* BOOLEAN  */
    DO = 269,                      /* DO  */
    GOTO = 270,                    /* GOTO  */
    PRIVATE = 271,                 /* PRIVATE  */
    THIS = 272,                    /* THIS  */
    BREAK = 273,                   /* BREAK  */
    DOUBLE = 274,                  /* DOUBLE  */
    IMPLEMENTS = 275,              /* IMPLEMENTS  */
    PROTECTED = 276,               /* PROTECTED  */
    THROW = 277,                   /* THROW  */
    BYTE = 278,                    /* BYTE  */
    ELSE = 279,                    /* ELSE  */
    IMPORT = 280,                  /* IMPORT  */
    PUBLIC = 281,                  /* PUBLIC  */
    THROWS = 282,                  /* THROWS  */
    CASE = 283,                    /* CASE  */
    ENUM = 284,                    /* ENUM  */
    RETURN = 285,                  /* RETURN  */
    TRANSIENT = 286,               /* TRANSIENT  */
    CATCH = 287,                   /* CATCH  */
    EXTENDS = 288,                 /* EXTENDS  */
    INT = 289,                     /* INT  */
    SHORT = 290,                   /* SHORT  */
    TRY = 291,                     /* TRY  */
    CHAR = 292,                    /* CHAR  */
    FINAL = 293,                   /* FINAL  */
    INTERFACE = 294,               /* INTERFACE  */
    STATIC = 295,                  /* STATIC  */
    VOID = 296,                    /* VOID  */
    CLASS = 297,                   /* CLASS  */
    FINALLY = 298,                 /* FINALLY  */
    LONG = 299,                    /* LONG  */
    STRICTFP = 300,                /* STRICTFP  */
    VOLATILE = 301,                /* VOLATILE  */
    CONST = 302,                   /* CONST  */
    FLOAT = 303,                   /* FLOAT  */
    NATIVE = 304,                  /* NATIVE  */
    SUPER = 305,                   /* SUPER  */
    WHILE = 306,                   /* WHILE  */
    UNDERSCORE = 307,              /* UNDERSCORE  */
    EXPORTS = 308,                 /* EXPORTS  */
    OPENS = 309,                   /* OPENS  */
    REQUIRES = 310,                /* REQUIRES  */
    USES = 311,                    /* USES  */
    MODULE = 312,                  /* MODULE  */
    PERMITS = 313,                 /* PERMITS  */
    SEALED = 314,                  /* SEALED  */
    VAR = 315,                     /* VAR  */
    NONSEALED = 316,               /* NONSEALED  */
    PROVIDES = 317,                /* PROVIDES  */
    TO = 318,                      /* TO  */
    WITH = 319,                    /* WITH  */
    OPEN = 320,                    /* OPEN  */
    RECORD = 321,                  /* RECORD  */
    TRANSITIVE = 322,              /* TRANSITIVE  */
    YIELD = 323,                   /* YIELD  */
    INTEGERLITERAL = 324,          /* INTEGERLITERAL  */
    FLOATINGPOINTLITERAL = 325,    /* FLOATINGPOINTLITERAL  */
    BOOLEANLITERAL = 326,          /* BOOLEANLITERAL  */
    NULLLITERAL = 327,             /* NULLLITERAL  */
    CHARACTERLITERAL = 328,        /* CHARACTERLITERAL  */
    STRING = 329,                  /* STRING  */
    TEXTBLOCKS = 330,              /* TEXTBLOCKS  */
    ESCAPESEQUENCE = 331,          /* ESCAPESEQUENCE  */
    GT = 332,                      /* GT  */
    LT = 333,                      /* LT  */
    EXCLAM = 334,                  /* EXCLAM  */
    TILDA = 335,                   /* TILDA  */
    QM = 336,                      /* QM  */
    COLON = 337,                   /* COLON  */
    IMPLIES = 338,                 /* IMPLIES  */
    DOUBLEEQUAL = 339,             /* DOUBLEEQUAL  */
    GTE = 340,                     /* GTE  */
    LTE = 341,                     /* LTE  */
    NE = 342,                      /* NE  */
    AND = 343,                     /* AND  */
    OR = 344,                      /* OR  */
    INCREAMENT = 345,              /* INCREAMENT  */
    DECREAMENT = 346,              /* DECREAMENT  */
    PLUS = 347,                    /* PLUS  */
    MINUS = 348,                   /* MINUS  */
    MULTIPLY = 349,                /* MULTIPLY  */
    DIVIDE = 350,                  /* DIVIDE  */
    BITAND = 351,                  /* BITAND  */
    BITOR = 352,                   /* BITOR  */
    BITXOR = 353,                  /* BITXOR  */
    PERCENT = 354,                 /* PERCENT  */
    LSHIFT = 355,                  /* LSHIFT  */
    RSHIFT = 356,                  /* RSHIFT  */
    THREEGT = 357,                 /* THREEGT  */
    EQUAL = 358,                   /* EQUAL  */
    NEWASSIGNMENTOPERATOR = 359,   /* NEWASSIGNMENTOPERATOR  */
    LRB = 360,                     /* LRB  */
    RRB = 361,                     /* RRB  */
    LCB = 362,                     /* LCB  */
    RCB = 363,                     /* RCB  */
    LSB = 364,                     /* LSB  */
    RSB = 365,                     /* RSB  */
    SEMICOLON = 366,               /* SEMICOLON  */
    COMMA = 367,                   /* COMMA  */
    DOT = 368,                     /* DOT  */
    THREEDOT = 369,                /* THREEDOT  */
    AT = 370,                      /* AT  */
    DOUBLECOLON = 371,             /* DOUBLECOLON  */
    IDENTIFIERWK = 372,            /* IDENTIFIERWK  */
    INSTANCEOF = 373               /* INSTANCEOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 354 "parser2.y"
char* str; struct Typeinfo* typeinfo;

#line 185 "parser2.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER2_TAB_H_INCLUDED  */
