/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser2.y"

#include <iostream>
#include <string>
#include <vector>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

#define YYERROR_VERBOSE

void yyerror (const char *s);
FILE* dotfile;
extern long long int line;
extern int yylex();
extern int yyrestart(FILE*);
extern FILE* yyin;

int tempvariables=0;
int labelvariable=0;


string newtemp(){
	tempvariables++;
	return "t"+to_string(tempvariables);
}
string newlabel(){
	labelvariable++;
	return "Label"+to_string(labelvariable);
}
string gotolabel(int labelvariable){
	return " goto Label"+to_string(labelvariable);
}
string gotoo(int p){
    return " go to label "+to_string(p);
}
vector<string> concvector(string a){
    vector<string>b={a};
    return b;
}

vector<string> concvector(vector<string>&va,string p){
	vector<string>s=va;
	s.push_back(p);
	return s;
}
vector<string> emptyvector(){
    vector<string>v;
    return v;
}
vector<string> concvector(vector<string>&va,vector<string>&vb){
    vector<string>s=va;
    for(auto z:vb)
    s.push_back(z);
    return s;
}
vector<string> concvector(vector<string>&va,vector<string>&vb,vector<string>&vc){
    vector<string>s=va;
    for(auto z:vb)
    s.push_back(z);
    for(auto z:vc)
    s.push_back(z);
    return s;
}
vector<string> concvector(vector<string>&va,vector<string>&vb,string p){
	vector<string>s=va;
	for(auto z:vb)
	s.push_back(z);
	s.push_back(p);
	return s;
}

vector<string> concvector(vector<string>&va,string a,vector<string>&vb,string b){
	vector<string>s=va;
	s.push_back(a);
    for(auto z:vb)
	s.push_back(z);
	s.push_back(b);
	return s;
}

vector<string> concvector(string p,vector<string>&a){
    vector<string>s;
    s.push_back(p);
    for(auto z:a)
    s.push_back(z);
    return s;
}
vector<string> concvector(vector<string>&va,string a,vector<string>&vb,string b,vector<string>&vc){
	vector<string>s=va;
	s.push_back(a);
    for(auto z:vb)
	s.push_back(z);
	s.push_back(b);
    for(auto z:vc)
	s.push_back(z);
	return s;
}

vector<string> concvector(vector<string>&va,string a,string b,vector<string>&vb,string c){
    vector<string>ret;
    ret=va;
    ret.push_back(a);
    ret.push_back(b);
    for(auto z:vb)
    ret.push_back(z);
    ret.push_back(c);
    return ret;
}

vector<string> concvector(vector<string>&va,string a,string b,vector<string>&vb,string c,string d){
    vector<string>ret;
    ret=va;
    ret.push_back(a);
    ret.push_back(b);
    for(auto z:vb)
    ret.push_back(z);
    ret.push_back(c);
    ret.push_back(d);
    return ret;
}

vector<string> concvector(vector<string>&va,string a,vector<string>&vb,string c,string d){
    vector<string>ret;
    for(auto z:va)
    ret.push_back(z);
	ret.push_back(a);
	for(auto z:vb)
    ret.push_back(z);
    ret.push_back(c);
    ret.push_back(d);
    return ret;
}

vector<string> concvector(vector<string>&va,string a,vector<string>&vb,vector<string>&vc,string c,string d){
    vector<string>ret;
    for(auto z:va)
    ret.push_back(z);
	ret.push_back(a);
	for(auto z:vb)
    ret.push_back(z);
	for(auto z:vc)
    ret.push_back(z);
    ret.push_back(c);
    ret.push_back(d);
    return ret;
}

vector<string> concvector(vector<string>&va,string a,vector<string>&vb,string b,vector<string>&vc,string c,string d){
    vector<string>ret;
    for(auto z:va)
    ret.push_back(z);
	ret.push_back(a);
	for(auto z:vb)
    ret.push_back(z);
	ret.push_back(b);
	for(auto z:vc)
    ret.push_back(z);
    ret.push_back(c);
    ret.push_back(d);
    return ret;
}
vector<string> concvector(string a,vector<string>&va,vector<string>&vb,string b,vector<string>&vc,string c,string d){
    vector<string>ret;
	ret.push_back(a);
    for(auto z:va)
    ret.push_back(z);
	for(auto z:vb)
    ret.push_back(z);
	ret.push_back(b);
	for(auto z:vc)
    ret.push_back(z);
    ret.push_back(c);
    ret.push_back(d);
    return ret;
}

vector<string> concvector(vector<string>&va,string a,vector<string>&vb,string b,vector<string>&vc,vector<string>&vd,string c,string d){
    vector<string>ret;
    for(auto z:va)
    ret.push_back(z);
	ret.push_back(a);
	for(auto z:vb)
    ret.push_back(z);
	ret.push_back(b);
	for(auto z:vc)
    ret.push_back(z);
	for(auto z:vd)
    ret.push_back(z);
    ret.push_back(c);
    ret.push_back(d);
    return ret;
}
vector<string> concvector(vector<string>&va,vector<string>&vb,vector<string>&vc,vector<string>&vd){
    vector<string>ret;
    
    for(auto z:va)
    ret.push_back(z);
    for(auto z:vb)
    ret.push_back(z);
    for(auto z:vc)
    ret.push_back(z);
     for(auto z:vd)
    ret.push_back(z);
 
    return ret;
}
vector<string> concvector(string a,vector<string>&va,string c,string d){
    vector<string>ret;
    ret.push_back(a);
    for(auto z:va)
    ret.push_back(z);
    ret.push_back(c);
    ret.push_back(d);
    return ret;
}
vector<string> concvector(string a,vector<string>&va,string c){
    vector<string>ret;
    ret.push_back(a);
    for(auto z:va)
    ret.push_back(z);
    ret.push_back(c);
    // ret.push_back(d);
    return ret;
}

vector<string> concvector(string a,vector<string>&va,vector<string>&vb,string c,string d){
    vector<string>ret;
    ret.push_back(a);
    for(auto z:va)
    ret.push_back(z);
	for(auto z:vb)
    ret.push_back(z);
    ret.push_back(c);
    ret.push_back(d);
    return ret;
}

vector<string> concvector(string a,vector<string>&va,string b,vector<string>&vb,string c,string d){
    vector<string>ret;
    ret.push_back(a);
    for(auto z:va)
    ret.push_back(z);
    ret.push_back(b);
    for(auto z:vb)
    ret.push_back(z);
    ret.push_back(c);
    ret.push_back(d);
    return ret;
}

vector<string> concvector(string a,vector<string>&va,string b,vector<string>&vb,vector<string>&vc,string c,string d){
    vector<string>ret;
    ret.push_back(a);
    for(auto z:va)
    ret.push_back(z);
	ret.push_back(b);
	for(auto z:vb)
    ret.push_back(z);
	for(auto z:vc)
    ret.push_back(z);
    ret.push_back(c);
    ret.push_back(d);
    return ret;
}
vector<string>  concvector(string a,vector<string>&va,vector<string>&vb,string b){
    vector<string>s;
    s.push_back(a);
    for(auto z:va)
    s.push_back(z);
    for(auto z:vb)
    s.push_back(z);
    s.push_back(b);
    return s;
}
// vector<string> concvector(vector<string>&a,vector<string>&b){
//     vector<string>s=a;
//     for(auto z:b)
//     s.push_back(z);
//     return s;
// }
// vector<string> concvector(string a,vector<string>&va,string b,vector<string>&vb,string c,string d){
//     vector<string>ret;
//     ret.push_back(a);
//     for(auto z:va)
//     ret.push_back(z);
//     ret.push_back(b);
//     for(auto z:vb)
//     ret.push_back(z);
//     ret.push_back(c);
//     ret.push_back(d);
//     return ret;
// }
// vector<string> concvector(vector<string>&va,string a,string b,vector<string>&vb,string c){
//     vector<string>ret;
//     ret=va;
//     ret.push_back(a);
//     ret.push_back(b);
//     for(auto z:vb)
//     ret.push_back(z);
//     ret.push_back(c);
//     return ret;
// }
// vector<string> concvector(vector<string>&va,string a,string b,vector<string>&vb,string c,string d){
//     vector<string>ret;
//     ret=va;
//     ret.push_back(a);
//     ret.push_back(b);
//     for(auto z:vb)
//     ret.push_back(z);
//     ret.push_back(c);
//     ret.push_back(d);
//     return ret;
// }
// vector<string> concvector(string a){
//     vector<string>b={a};
//     return b;
// }
// vector<string> concvector(vector<string>&a,string p){
// 	vector<string>s=a;
// 	s.push_back(p);
// 	return s;
// }
// vector<string> concvector(vector<string>&a,vector<string>&b,string p){
// 	vector<string>s=a;
// 	for(auto z:b)
// 	s.push_back(z);
// 	s.push_back(p);
// 	return s;
// }
string golabel(int p){
    string q=to_string(p);
    string a=" go to label "+q;
    return a;
}

struct Typeinfo{
	string type;                //literal,identifer

	vector<string>variables; //for variable declator list
	string name;

	vector<string>tac;
	string tempname;

    float valfloat;
    string valstr;
    char valchar;
    bool valbool;
    string littype;

};

#line 424 "parser2.tab.c"

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

#include "parser2.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ABSTRACT = 3,                   /* ABSTRACT  */
  YYSYMBOL_CONTINUE = 4,                   /* CONTINUE  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_NEW = 6,                        /* NEW  */
  YYSYMBOL_SWITCH = 7,                     /* SWITCH  */
  YYSYMBOL_ASSERT = 8,                     /* ASSERT  */
  YYSYMBOL_DEFAULT = 9,                    /* DEFAULT  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_PACKAGE = 11,                   /* PACKAGE  */
  YYSYMBOL_SYNCHRONIZED = 12,              /* SYNCHRONIZED  */
  YYSYMBOL_BOOLEAN = 13,                   /* BOOLEAN  */
  YYSYMBOL_DO = 14,                        /* DO  */
  YYSYMBOL_GOTO = 15,                      /* GOTO  */
  YYSYMBOL_PRIVATE = 16,                   /* PRIVATE  */
  YYSYMBOL_THIS = 17,                      /* THIS  */
  YYSYMBOL_BREAK = 18,                     /* BREAK  */
  YYSYMBOL_DOUBLE = 19,                    /* DOUBLE  */
  YYSYMBOL_IMPLEMENTS = 20,                /* IMPLEMENTS  */
  YYSYMBOL_PROTECTED = 21,                 /* PROTECTED  */
  YYSYMBOL_THROW = 22,                     /* THROW  */
  YYSYMBOL_BYTE = 23,                      /* BYTE  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_IMPORT = 25,                    /* IMPORT  */
  YYSYMBOL_PUBLIC = 26,                    /* PUBLIC  */
  YYSYMBOL_THROWS = 27,                    /* THROWS  */
  YYSYMBOL_CASE = 28,                      /* CASE  */
  YYSYMBOL_ENUM = 29,                      /* ENUM  */
  YYSYMBOL_RETURN = 30,                    /* RETURN  */
  YYSYMBOL_TRANSIENT = 31,                 /* TRANSIENT  */
  YYSYMBOL_CATCH = 32,                     /* CATCH  */
  YYSYMBOL_EXTENDS = 33,                   /* EXTENDS  */
  YYSYMBOL_INT = 34,                       /* INT  */
  YYSYMBOL_SHORT = 35,                     /* SHORT  */
  YYSYMBOL_TRY = 36,                       /* TRY  */
  YYSYMBOL_CHAR = 37,                      /* CHAR  */
  YYSYMBOL_FINAL = 38,                     /* FINAL  */
  YYSYMBOL_INTERFACE = 39,                 /* INTERFACE  */
  YYSYMBOL_STATIC = 40,                    /* STATIC  */
  YYSYMBOL_VOID = 41,                      /* VOID  */
  YYSYMBOL_CLASS = 42,                     /* CLASS  */
  YYSYMBOL_FINALLY = 43,                   /* FINALLY  */
  YYSYMBOL_LONG = 44,                      /* LONG  */
  YYSYMBOL_STRICTFP = 45,                  /* STRICTFP  */
  YYSYMBOL_VOLATILE = 46,                  /* VOLATILE  */
  YYSYMBOL_CONST = 47,                     /* CONST  */
  YYSYMBOL_FLOAT = 48,                     /* FLOAT  */
  YYSYMBOL_NATIVE = 49,                    /* NATIVE  */
  YYSYMBOL_SUPER = 50,                     /* SUPER  */
  YYSYMBOL_WHILE = 51,                     /* WHILE  */
  YYSYMBOL_UNDERSCORE = 52,                /* UNDERSCORE  */
  YYSYMBOL_EXPORTS = 53,                   /* EXPORTS  */
  YYSYMBOL_OPENS = 54,                     /* OPENS  */
  YYSYMBOL_REQUIRES = 55,                  /* REQUIRES  */
  YYSYMBOL_USES = 56,                      /* USES  */
  YYSYMBOL_MODULE = 57,                    /* MODULE  */
  YYSYMBOL_PERMITS = 58,                   /* PERMITS  */
  YYSYMBOL_SEALED = 59,                    /* SEALED  */
  YYSYMBOL_VAR = 60,                       /* VAR  */
  YYSYMBOL_NONSEALED = 61,                 /* NONSEALED  */
  YYSYMBOL_PROVIDES = 62,                  /* PROVIDES  */
  YYSYMBOL_TO = 63,                        /* TO  */
  YYSYMBOL_WITH = 64,                      /* WITH  */
  YYSYMBOL_OPEN = 65,                      /* OPEN  */
  YYSYMBOL_RECORD = 66,                    /* RECORD  */
  YYSYMBOL_TRANSITIVE = 67,                /* TRANSITIVE  */
  YYSYMBOL_YIELD = 68,                     /* YIELD  */
  YYSYMBOL_INTEGERLITERAL = 69,            /* INTEGERLITERAL  */
  YYSYMBOL_FLOATINGPOINTLITERAL = 70,      /* FLOATINGPOINTLITERAL  */
  YYSYMBOL_BOOLEANLITERAL = 71,            /* BOOLEANLITERAL  */
  YYSYMBOL_NULLLITERAL = 72,               /* NULLLITERAL  */
  YYSYMBOL_CHARACTERLITERAL = 73,          /* CHARACTERLITERAL  */
  YYSYMBOL_STRING = 74,                    /* STRING  */
  YYSYMBOL_TEXTBLOCKS = 75,                /* TEXTBLOCKS  */
  YYSYMBOL_ESCAPESEQUENCE = 76,            /* ESCAPESEQUENCE  */
  YYSYMBOL_GT = 77,                        /* GT  */
  YYSYMBOL_LT = 78,                        /* LT  */
  YYSYMBOL_EXCLAM = 79,                    /* EXCLAM  */
  YYSYMBOL_TILDA = 80,                     /* TILDA  */
  YYSYMBOL_QM = 81,                        /* QM  */
  YYSYMBOL_COLON = 82,                     /* COLON  */
  YYSYMBOL_IMPLIES = 83,                   /* IMPLIES  */
  YYSYMBOL_DOUBLEEQUAL = 84,               /* DOUBLEEQUAL  */
  YYSYMBOL_GTE = 85,                       /* GTE  */
  YYSYMBOL_LTE = 86,                       /* LTE  */
  YYSYMBOL_NE = 87,                        /* NE  */
  YYSYMBOL_AND = 88,                       /* AND  */
  YYSYMBOL_OR = 89,                        /* OR  */
  YYSYMBOL_INCREAMENT = 90,                /* INCREAMENT  */
  YYSYMBOL_DECREAMENT = 91,                /* DECREAMENT  */
  YYSYMBOL_PLUS = 92,                      /* PLUS  */
  YYSYMBOL_MINUS = 93,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 94,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 95,                    /* DIVIDE  */
  YYSYMBOL_BITAND = 96,                    /* BITAND  */
  YYSYMBOL_BITOR = 97,                     /* BITOR  */
  YYSYMBOL_BITXOR = 98,                    /* BITXOR  */
  YYSYMBOL_PERCENT = 99,                   /* PERCENT  */
  YYSYMBOL_LSHIFT = 100,                   /* LSHIFT  */
  YYSYMBOL_RSHIFT = 101,                   /* RSHIFT  */
  YYSYMBOL_THREEGT = 102,                  /* THREEGT  */
  YYSYMBOL_EQUAL = 103,                    /* EQUAL  */
  YYSYMBOL_NEWASSIGNMENTOPERATOR = 104,    /* NEWASSIGNMENTOPERATOR  */
  YYSYMBOL_LRB = 105,                      /* LRB  */
  YYSYMBOL_RRB = 106,                      /* RRB  */
  YYSYMBOL_LCB = 107,                      /* LCB  */
  YYSYMBOL_RCB = 108,                      /* RCB  */
  YYSYMBOL_LSB = 109,                      /* LSB  */
  YYSYMBOL_RSB = 110,                      /* RSB  */
  YYSYMBOL_SEMICOLON = 111,                /* SEMICOLON  */
  YYSYMBOL_COMMA = 112,                    /* COMMA  */
  YYSYMBOL_DOT = 113,                      /* DOT  */
  YYSYMBOL_THREEDOT = 114,                 /* THREEDOT  */
  YYSYMBOL_AT = 115,                       /* AT  */
  YYSYMBOL_DOUBLECOLON = 116,              /* DOUBLECOLON  */
  YYSYMBOL_IDENTIFIERWK = 117,             /* IDENTIFIERWK  */
  YYSYMBOL_INSTANCEOF = 118,               /* INSTANCEOF  */
  YYSYMBOL_YYACCEPT = 119,                 /* $accept  */
  YYSYMBOL_OMPSB = 120,                    /* OMPSB  */
  YYSYMBOL_PSB = 121,                      /* PSB  */
  YYSYMBOL_OMAdditionalBound = 122,        /* OMAdditionalBound  */
  YYSYMBOL_ReceiverParameterComma = 123,   /* ReceiverParameterComma  */
  YYSYMBOL_IdentifierDot = 124,            /* IdentifierDot  */
  YYSYMBOL_OMImportDeclaration = 125,      /* OMImportDeclaration  */
  YYSYMBOL_OMTopLevelClassOrInterfaceDeclaration = 126, /* OMTopLevelClassOrInterfaceDeclaration  */
  YYSYMBOL_OMDotIdentifier = 127,          /* OMDotIdentifier  */
  YYSYMBOL_OMModuleDirective = 128,        /* OMModuleDirective  */
  YYSYMBOL_OMRequiresModifier = 129,       /* OMRequiresModifier  */
  YYSYMBOL_OMCommaModuleName = 130,        /* OMCommaModuleName  */
  YYSYMBOL_CommaModuleName = 131,          /* CommaModuleName  */
  YYSYMBOL_OMCommaTypeName = 132,          /* OMCommaTypeName  */
  YYSYMBOL_CommaTypeName = 133,            /* CommaTypeName  */
  YYSYMBOL_OMClassModifier = 134,          /* OMClassModifier  */
  YYSYMBOL_OMCommaTypeParameter = 135,     /* OMCommaTypeParameter  */
  YYSYMBOL_CommaTypeParameter = 136,       /* CommaTypeParameter  */
  YYSYMBOL_OMCommaInterfaceType = 137,     /* OMCommaInterfaceType  */
  YYSYMBOL_CommaInterfaceType = 138,       /* CommaInterfaceType  */
  YYSYMBOL_OMClassBodyDeclaration = 139,   /* OMClassBodyDeclaration  */
  YYSYMBOL_OMCommaFormalParameter = 140,   /* OMCommaFormalParameter  */
  YYSYMBOL_CommaFormalParameter = 141,     /* CommaFormalParameter  */
  YYSYMBOL_OMCommaExceptionType = 142,     /* OMCommaExceptionType  */
  YYSYMBOL_CommaExceptionType = 143,       /* CommaExceptionType  */
  YYSYMBOL_OMCommaEnumConstant = 144,      /* OMCommaEnumConstant  */
  YYSYMBOL_CommaEnumConstant = 145,        /* CommaEnumConstant  */
  YYSYMBOL_OMCommaRecordComponent = 146,   /* OMCommaRecordComponent  */
  YYSYMBOL_CommaRecordComponent = 147,     /* CommaRecordComponent  */
  YYSYMBOL_OMRecordBodyDeclaration = 148,  /* OMRecordBodyDeclaration  */
  YYSYMBOL_OMInterfaceMemberDeclaration = 149, /* OMInterfaceMemberDeclaration  */
  YYSYMBOL_OMCommaVariableInitializer = 150, /* OMCommaVariableInitializer  */
  YYSYMBOL_CommaVariableInitializer = 151, /* CommaVariableInitializer  */
  YYSYMBOL_OMBlockStatement = 152,         /* OMBlockStatement  */
  YYSYMBOL_OMSwitchRule = 153,             /* OMSwitchRule  */
  YYSYMBOL_OMSwitchBlockStatementGroup = 154, /* OMSwitchBlockStatementGroup  */
  YYSYMBOL_OMSwitchLabelColon = 155,       /* OMSwitchLabelColon  */
  YYSYMBOL_SwitchLabelColon = 156,         /* SwitchLabelColon  */
  YYSYMBOL_OMCommaCaseConstant = 157,      /* OMCommaCaseConstant  */
  YYSYMBOL_CommaCaseConstant = 158,        /* CommaCaseConstant  */
  YYSYMBOL_OMCommaStatementExpression = 159, /* OMCommaStatementExpression  */
  YYSYMBOL_CommaStatementExpression = 160, /* CommaStatementExpression  */
  YYSYMBOL_OMCatchClause = 161,            /* OMCatchClause  */
  YYSYMBOL_OMOrClassType = 162,            /* OMOrClassType  */
  YYSYMBOL_OrClassType = 163,              /* OrClassType  */
  YYSYMBOL_OMSemicolonResource = 164,      /* OMSemicolonResource  */
  YYSYMBOL_SemicolonResource = 165,        /* SemicolonResource  */
  YYSYMBOL_OMCommaExpression = 166,        /* OMCommaExpression  */
  YYSYMBOL_CommaExpression = 167,          /* CommaExpression  */
  YYSYMBOL_OMDimExpr = 168,                /* OMDimExpr  */
  YYSYMBOL_Modifieropt = 169,              /* Modifieropt  */
  YYSYMBOL_Identifier = 170,               /* Identifier  */
  YYSYMBOL_UnqualifiedMethodIdentifier = 171, /* UnqualifiedMethodIdentifier  */
  YYSYMBOL_Literal = 172,                  /* Literal  */
  YYSYMBOL_ASSIGNMENTOPERATOR = 173,       /* ASSIGNMENTOPERATOR  */
  YYSYMBOL_PrimitiveType = 174,            /* PrimitiveType  */
  YYSYMBOL_NumericType = 175,              /* NumericType  */
  YYSYMBOL_IntegralType = 176,             /* IntegralType  */
  YYSYMBOL_FloatingPointType = 177,        /* FloatingPointType  */
  YYSYMBOL_ReferenceType = 178,            /* ReferenceType  */
  YYSYMBOL_TypeParameter = 179,            /* TypeParameter  */
  YYSYMBOL_TypeBound = 180,                /* TypeBound  */
  YYSYMBOL_AdditionalBound = 181,          /* AdditionalBound  */
  YYSYMBOL_ModuleName = 182,               /* ModuleName  */
  YYSYMBOL_ExpressionName = 183,           /* ExpressionName  */
  YYSYMBOL_MethodName = 184,               /* MethodName  */
  YYSYMBOL_CompilationUnit = 185,          /* CompilationUnit  */
  YYSYMBOL_OrdinaryCompilationUnit = 186,  /* OrdinaryCompilationUnit  */
  YYSYMBOL_ModularCompilationUnit = 187,   /* ModularCompilationUnit  */
  YYSYMBOL_PackageDeclaration = 188,       /* PackageDeclaration  */
  YYSYMBOL_ImportDeclaration = 189,        /* ImportDeclaration  */
  YYSYMBOL_SingleTypeImportDeclaration = 190, /* SingleTypeImportDeclaration  */
  YYSYMBOL_SingleStaticImportDeclaration = 191, /* SingleStaticImportDeclaration  */
  YYSYMBOL_ImportOnDemandDeclaration = 192, /* ImportOnDemandDeclaration  */
  YYSYMBOL_StaticImportOnDemandDeclaration = 193, /* StaticImportOnDemandDeclaration  */
  YYSYMBOL_TopLevelClassOrInterfaceDeclaration = 194, /* TopLevelClassOrInterfaceDeclaration  */
  YYSYMBOL_ModuleDeclaration = 195,        /* ModuleDeclaration  */
  YYSYMBOL_ModuleDirective = 196,          /* ModuleDirective  */
  YYSYMBOL_ClassDeclaration = 197,         /* ClassDeclaration  */
  YYSYMBOL_NormalClassDeclaration = 198,   /* NormalClassDeclaration  */
  YYSYMBOL_TypeParameters = 199,           /* TypeParameters  */
  YYSYMBOL_TypeParameterList = 200,        /* TypeParameterList  */
  YYSYMBOL_ClassExtends = 201,             /* ClassExtends  */
  YYSYMBOL_ClassImplements = 202,          /* ClassImplements  */
  YYSYMBOL_InterfaceTypeList = 203,        /* InterfaceTypeList  */
  YYSYMBOL_ClassPermits = 204,             /* ClassPermits  */
  YYSYMBOL_ClassBody = 205,                /* ClassBody  */
  YYSYMBOL_ClassBodyDeclaration = 206,     /* ClassBodyDeclaration  */
  YYSYMBOL_ClassMemberDeclaration = 207,   /* ClassMemberDeclaration  */
  YYSYMBOL_FieldDeclaration = 208,         /* FieldDeclaration  */
  YYSYMBOL_VariableDeclaratorList = 209,   /* VariableDeclaratorList  */
  YYSYMBOL_VariableDeclarator = 210,       /* VariableDeclarator  */
  YYSYMBOL_VariableDeclaratorId = 211,     /* VariableDeclaratorId  */
  YYSYMBOL_VariableInitializer = 212,      /* VariableInitializer  */
  YYSYMBOL_UnannType = 213,                /* UnannType  */
  YYSYMBOL_UnannPrimitiveType = 214,       /* UnannPrimitiveType  */
  YYSYMBOL_UnannArrayType = 215,           /* UnannArrayType  */
  YYSYMBOL_MethodDeclaration = 216,        /* MethodDeclaration  */
  YYSYMBOL_MethodHeader = 217,             /* MethodHeader  */
  YYSYMBOL_Result = 218,                   /* Result  */
  YYSYMBOL_MethodDeclarator = 219,         /* MethodDeclarator  */
  YYSYMBOL_ReceiverParameter = 220,        /* ReceiverParameter  */
  YYSYMBOL_FormalParameterList = 221,      /* FormalParameterList  */
  YYSYMBOL_FormalParameter = 222,          /* FormalParameter  */
  YYSYMBOL_VariableArityParameter = 223,   /* VariableArityParameter  */
  YYSYMBOL_Throws = 224,                   /* Throws  */
  YYSYMBOL_ExceptionTypeList = 225,        /* ExceptionTypeList  */
  YYSYMBOL_ExceptionType = 226,            /* ExceptionType  */
  YYSYMBOL_MethodBody = 227,               /* MethodBody  */
  YYSYMBOL_InstanceInitializer = 228,      /* InstanceInitializer  */
  YYSYMBOL_StaticInitializer = 229,        /* StaticInitializer  */
  YYSYMBOL_ConstructorDeclaration = 230,   /* ConstructorDeclaration  */
  YYSYMBOL_ConstructorDeclarator = 231,    /* ConstructorDeclarator  */
  YYSYMBOL_ConstructorBody = 232,          /* ConstructorBody  */
  YYSYMBOL_ExplicitConstructorInvocation = 233, /* ExplicitConstructorInvocation  */
  YYSYMBOL_EnumDeclaration = 234,          /* EnumDeclaration  */
  YYSYMBOL_EnumBody = 235,                 /* EnumBody  */
  YYSYMBOL_EnumConstantList = 236,         /* EnumConstantList  */
  YYSYMBOL_PRB = 237,                      /* PRB  */
  YYSYMBOL_PRBArgumentList = 238,          /* PRBArgumentList  */
  YYSYMBOL_EnumConstant = 239,             /* EnumConstant  */
  YYSYMBOL_EnumBodyDeclarations = 240,     /* EnumBodyDeclarations  */
  YYSYMBOL_RecordDeclaration = 241,        /* RecordDeclaration  */
  YYSYMBOL_RecordHeader = 242,             /* RecordHeader  */
  YYSYMBOL_RecordComponentList = 243,      /* RecordComponentList  */
  YYSYMBOL_RecordComponent = 244,          /* RecordComponent  */
  YYSYMBOL_VariableArityRecordComponent = 245, /* VariableArityRecordComponent  */
  YYSYMBOL_RecordBody = 246,               /* RecordBody  */
  YYSYMBOL_RecordBodyDeclaration = 247,    /* RecordBodyDeclaration  */
  YYSYMBOL_CompactConstructorDeclaration = 248, /* CompactConstructorDeclaration  */
  YYSYMBOL_InterfaceDeclaration = 249,     /* InterfaceDeclaration  */
  YYSYMBOL_NormalInterfaceDeclaration = 250, /* NormalInterfaceDeclaration  */
  YYSYMBOL_InterfaceModifier = 251,        /* InterfaceModifier  */
  YYSYMBOL_InterfaceExtends = 252,         /* InterfaceExtends  */
  YYSYMBOL_InterfacePermits = 253,         /* InterfacePermits  */
  YYSYMBOL_InterfaceBody = 254,            /* InterfaceBody  */
  YYSYMBOL_InterfaceMemberDeclaration = 255, /* InterfaceMemberDeclaration  */
  YYSYMBOL_ConstantDeclaration = 256,      /* ConstantDeclaration  */
  YYSYMBOL_InterfaceMethodDeclaration = 257, /* InterfaceMethodDeclaration  */
  YYSYMBOL_ArrayInitializer = 258,         /* ArrayInitializer  */
  YYSYMBOL_VariableInitializerList = 259,  /* VariableInitializerList  */
  YYSYMBOL_Block = 260,                    /* Block  */
  YYSYMBOL_BlockStatements = 261,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 262,           /* BlockStatement  */
  YYSYMBOL_LocalClassOrInterfaceDeclaration = 263, /* LocalClassOrInterfaceDeclaration  */
  YYSYMBOL_LocalVariableDeclarationStatement = 264, /* LocalVariableDeclarationStatement  */
  YYSYMBOL_LocalVariableDeclaration = 265, /* LocalVariableDeclaration  */
  YYSYMBOL_LocalVariableType = 266,        /* LocalVariableType  */
  YYSYMBOL_Statement = 267,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 268,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 269, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_EmptyStatement = 270,           /* EmptyStatement  */
  YYSYMBOL_LabeledStatement = 271,         /* LabeledStatement  */
  YYSYMBOL_LabeledStatementNoShortIf = 272, /* LabeledStatementNoShortIf  */
  YYSYMBOL_ExpressionStatement = 273,      /* ExpressionStatement  */
  YYSYMBOL_StatementExpression = 274,      /* StatementExpression  */
  YYSYMBOL_IfThenStatement = 275,          /* IfThenStatement  */
  YYSYMBOL_IfThenElseStatement = 276,      /* IfThenElseStatement  */
  YYSYMBOL_IfThenElseStatementNoShortIf = 277, /* IfThenElseStatementNoShortIf  */
  YYSYMBOL_AssertStatement = 278,          /* AssertStatement  */
  YYSYMBOL_SwitchStatement = 279,          /* SwitchStatement  */
  YYSYMBOL_SwitchBlock = 280,              /* SwitchBlock  */
  YYSYMBOL_SwitchRule = 281,               /* SwitchRule  */
  YYSYMBOL_SwitchBlockStatementGroup = 282, /* SwitchBlockStatementGroup  */
  YYSYMBOL_SwitchLabel = 283,              /* SwitchLabel  */
  YYSYMBOL_CaseConstant = 284,             /* CaseConstant  */
  YYSYMBOL_WhileStatement = 285,           /* WhileStatement  */
  YYSYMBOL_WhileStatementNoShortIf = 286,  /* WhileStatementNoShortIf  */
  YYSYMBOL_DoStatement = 287,              /* DoStatement  */
  YYSYMBOL_ForStatement = 288,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 289,    /* ForStatementNoShortIf  */
  YYSYMBOL_BasicForStatement = 290,        /* BasicForStatement  */
  YYSYMBOL_BasicForStatementNoShortIf = 291, /* BasicForStatementNoShortIf  */
  YYSYMBOL_ForInit = 292,                  /* ForInit  */
  YYSYMBOL_ForUpdate = 293,                /* ForUpdate  */
  YYSYMBOL_StatementExpressionList = 294,  /* StatementExpressionList  */
  YYSYMBOL_EnhancedForStatement = 295,     /* EnhancedForStatement  */
  YYSYMBOL_EnhancedForStatementNoShortIf = 296, /* EnhancedForStatementNoShortIf  */
  YYSYMBOL_BreakStatement = 297,           /* BreakStatement  */
  YYSYMBOL_YieldStatement = 298,           /* YieldStatement  */
  YYSYMBOL_ContinueStatement = 299,        /* ContinueStatement  */
  YYSYMBOL_ReturnStatement = 300,          /* ReturnStatement  */
  YYSYMBOL_ThrowStatement = 301,           /* ThrowStatement  */
  YYSYMBOL_SynchronizedStatement = 302,    /* SynchronizedStatement  */
  YYSYMBOL_TryStatement = 303,             /* TryStatement  */
  YYSYMBOL_Catches = 304,                  /* Catches  */
  YYSYMBOL_CatchClause = 305,              /* CatchClause  */
  YYSYMBOL_CatchFormalParameter = 306,     /* CatchFormalParameter  */
  YYSYMBOL_CatchType = 307,                /* CatchType  */
  YYSYMBOL_Finally = 308,                  /* Finally  */
  YYSYMBOL_TryWithResourcesStatement = 309, /* TryWithResourcesStatement  */
  YYSYMBOL_ResourceSpecification = 310,    /* ResourceSpecification  */
  YYSYMBOL_ResourceList = 311,             /* ResourceList  */
  YYSYMBOL_Resource = 312,                 /* Resource  */
  YYSYMBOL_Primary = 313,                  /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 314,        /* PrimaryNoNewArray  */
  YYSYMBOL_ClassLiteral = 315,             /* ClassLiteral  */
  YYSYMBOL_ClassInstanceCreationExpression = 316, /* ClassInstanceCreationExpression  */
  YYSYMBOL_UnqualifiedClassInstanceCreationExpression = 317, /* UnqualifiedClassInstanceCreationExpression  */
  YYSYMBOL_ClassOrInterfaceTypeToInstantiate = 318, /* ClassOrInterfaceTypeToInstantiate  */
  YYSYMBOL_FieldAccess = 319,              /* FieldAccess  */
  YYSYMBOL_ArrayAccess = 320,              /* ArrayAccess  */
  YYSYMBOL_MethodInvocation = 321,         /* MethodInvocation  */
  YYSYMBOL_ArgumentList = 322,             /* ArgumentList  */
  YYSYMBOL_MethodReference = 323,          /* MethodReference  */
  YYSYMBOL_ArrayCreationExpression = 324,  /* ArrayCreationExpression  */
  YYSYMBOL_DimExpr = 325,                  /* DimExpr  */
  YYSYMBOL_Expression = 326,               /* Expression  */
  YYSYMBOL_AssignmentExpression = 327,     /* AssignmentExpression  */
  YYSYMBOL_Assignment = 328,               /* Assignment  */
  YYSYMBOL_LeftHandSide = 329,             /* LeftHandSide  */
  YYSYMBOL_AssignmentOperator = 330,       /* AssignmentOperator  */
  YYSYMBOL_ConditionalExpression = 331,    /* ConditionalExpression  */
  YYSYMBOL_ConditionalOrExpression = 332,  /* ConditionalOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 333, /* ConditionalAndExpression  */
  YYSYMBOL_InclusiveOrExpression = 334,    /* InclusiveOrExpression  */
  YYSYMBOL_ExclusiveOrExpression = 335,    /* ExclusiveOrExpression  */
  YYSYMBOL_AndExpression = 336,            /* AndExpression  */
  YYSYMBOL_EqualityExpression = 337,       /* EqualityExpression  */
  YYSYMBOL_RelationalExpression = 338,     /* RelationalExpression  */
  YYSYMBOL_InstanceofExpression = 339,     /* InstanceofExpression  */
  YYSYMBOL_ShiftExpression = 340,          /* ShiftExpression  */
  YYSYMBOL_AdditiveExpression = 341,       /* AdditiveExpression  */
  YYSYMBOL_MultiplicativeExpression = 342, /* MultiplicativeExpression  */
  YYSYMBOL_UnaryExpression = 343,          /* UnaryExpression  */
  YYSYMBOL_PreIncrementExpression = 344,   /* PreIncrementExpression  */
  YYSYMBOL_PreDecrementExpression = 345,   /* PreDecrementExpression  */
  YYSYMBOL_UnaryExpressionNotPlusMinus = 346, /* UnaryExpressionNotPlusMinus  */
  YYSYMBOL_PostfixExpression = 347,        /* PostfixExpression  */
  YYSYMBOL_PostIncrementExpression = 348,  /* PostIncrementExpression  */
  YYSYMBOL_PostDecrementExpression = 349,  /* PostDecrementExpression  */
  YYSYMBOL_CastExpression = 350,           /* CastExpression  */
  YYSYMBOL_SwitchExpression = 351,         /* SwitchExpression  */
  YYSYMBOL_VariableAccess = 352            /* VariableAccess  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int16 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   7505

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  119
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  234
/* YYNRULES -- Number of rules.  */
#define YYNRULES  676
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1216

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   373


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   395,   395,   396,   398,   401,   402,   405,   407,   409,
     410,   412,   413,   415,   416,   418,   419,   421,   422,   424,
     425,   427,   429,   430,   432,   433,   435,   436,   438,   439,
     441,   443,   444,   446,   448,   449,   451,   452,   454,   456,
     457,   459,   461,   462,   464,   467,   468,   470,   473,   474,
     476,   477,   480,   481,   483,   485,   486,   488,   489,   491,
     492,   494,   495,   497,   499,   500,   502,   504,   505,   507,
     509,   510,   512,   513,   515,   517,   518,   520,   522,   523,
     525,   527,   528,   530,   531,   532,   533,   534,   535,   536,
     537,   539,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   558,   559,
     560,   561,   562,   563,   564,   566,   567,   569,   571,   572,
     574,   575,   576,   577,   578,   580,   581,   583,   584,   586,
     587,   589,   590,   592,   594,   595,   597,   598,   600,   602,
     603,   605,   606,   607,   608,   609,   610,   611,   612,   614,
     615,   617,   618,   620,   621,   622,   623,   625,   626,   628,
     630,   631,   633,   634,   636,   637,   638,   640,   641,   642,
     643,   644,   645,   646,   647,   649,   650,   651,   652,   653,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
     664,   665,   666,   667,   668,   669,   670,   671,   672,   674,
     675,   676,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   690,   691,   692,   693,   694,   695,
     696,   697,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   709,   711,   713,   714,   716,   718,   720,
     721,   724,   725,   726,   727,   730,   731,   733,   734,   735,
     736,   738,   739,   740,   741,   742,   744,   745,   747,   748,
     750,   751,   753,   754,   757,   758,   760,   761,   762,   764,
     765,   767,   768,   771,   772,   774,   775,   776,   777,   779,
     780,   783,   784,   785,   786,   787,   788,   789,   790,   792,
     793,   795,   796,   798,   799,   800,   802,   803,   806,   808,
     809,   811,   814,   815,   817,   819,   821,   822,   823,   824,
     826,   827,   828,   829,   830,   831,   832,   833,   836,   837,
     838,   839,   841,   842,   843,   844,   845,   846,   847,   848,
     849,   850,   852,   853,   854,   855,   858,   859,   860,   861,
     862,   863,   865,   866,   868,   870,   872,   873,   874,   875,
     876,   877,   879,   880,   882,   883,   884,   885,   886,   887,
     888,   889,   892,   893,   895,   896,   898,   899,   902,   905,
     906,   908,   909,   911,   912,   915,   917,   918,   919,   920,
     921,   922,   923,   924,   925,   926,   927,   928,   929,   930,
     931,   932,   935,   937,   939,   940,   942,   943,   945,   946,
     947,   948,   949,   951,   952,   954,   955,   957,   958,   959,
     961,   962,   964,   965,   967,   968,   970,   971,   972,   974,
     975,   977,   979,   980,   982,   983,   985,   986,   987,   988,
     989,   990,   992,   993,   994,   995,   996,   998,   999,  1000,
    1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,  1009,  1010,
    1012,  1014,  1016,  1019,  1021,  1022,  1023,  1024,  1025,  1026,
    1027,  1029,  1031,  1033,  1035,  1036,  1038,  1040,  1041,  1042,
    1043,  1044,  1045,  1047,  1048,  1049,  1051,  1052,  1054,  1055,
    1056,  1058,  1060,  1062,  1064,  1066,  1067,  1069,  1070,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1090,  1091,  1093,  1095,  1096,
    1098,  1100,  1102,  1103,  1106,  1108,  1109,  1112,  1113,  1115,
    1117,  1119,  1120,  1121,  1122,  1124,  1125,  1127,  1129,  1130,
    1132,  1133,  1136,  1138,  1139,  1140,  1141,  1143,  1145,  1146,
    1148,  1149,  1151,  1152,  1154,  1155,  1156,  1157,  1158,  1159,
    1160,  1161,  1162,  1163,  1164,  1166,  1167,  1168,  1169,  1170,
    1171,  1173,  1174,  1175,  1176,  1178,  1179,  1180,  1181,  1183,
    1184,  1186,  1187,  1188,  1189,  1191,  1192,  1193,  1195,  1196,
    1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,  1206,
    1207,  1208,  1211,  1212,  1214,  1215,  1216,  1217,  1218,  1219,
    1220,  1221,  1223,  1224,  1225,  1226,  1227,  1228,  1231,  1233,
    1235,  1236,  1238,  1240,  1241,  1242,  1243,  1245,  1247,  1248,
    1250,  1251,  1253,  1254,  1256,  1257,  1259,  1260,  1262,  1263,
    1265,  1266,  1267,  1269,  1270,  1271,  1272,  1273,  1274,  1276,
    1278,  1279,  1280,  1281,  1283,  1284,  1285,  1287,  1288,  1289,
    1290,  1292,  1293,  1294,  1295,  1296,  1298,  1300,  1302,  1303,
    1304,  1305,  1306,  1308,  1309,  1310,  1311,  1312,  1314,  1316,
    1318,  1319,  1320,  1322,  1324,  1325,  1326
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ABSTRACT", "CONTINUE",
  "FOR", "NEW", "SWITCH", "ASSERT", "DEFAULT", "IF", "PACKAGE",
  "SYNCHRONIZED", "BOOLEAN", "DO", "GOTO", "PRIVATE", "THIS", "BREAK",
  "DOUBLE", "IMPLEMENTS", "PROTECTED", "THROW", "BYTE", "ELSE", "IMPORT",
  "PUBLIC", "THROWS", "CASE", "ENUM", "RETURN", "TRANSIENT", "CATCH",
  "EXTENDS", "INT", "SHORT", "TRY", "CHAR", "FINAL", "INTERFACE", "STATIC",
  "VOID", "CLASS", "FINALLY", "LONG", "STRICTFP", "VOLATILE", "CONST",
  "FLOAT", "NATIVE", "SUPER", "WHILE", "UNDERSCORE", "EXPORTS", "OPENS",
  "REQUIRES", "USES", "MODULE", "PERMITS", "SEALED", "VAR", "NONSEALED",
  "PROVIDES", "TO", "WITH", "OPEN", "RECORD", "TRANSITIVE", "YIELD",
  "INTEGERLITERAL", "FLOATINGPOINTLITERAL", "BOOLEANLITERAL",
  "NULLLITERAL", "CHARACTERLITERAL", "STRING", "TEXTBLOCKS",
  "ESCAPESEQUENCE", "GT", "LT", "EXCLAM", "TILDA", "QM", "COLON",
  "IMPLIES", "DOUBLEEQUAL", "GTE", "LTE", "NE", "AND", "OR", "INCREAMENT",
  "DECREAMENT", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "BITAND", "BITOR",
  "BITXOR", "PERCENT", "LSHIFT", "RSHIFT", "THREEGT", "EQUAL",
  "NEWASSIGNMENTOPERATOR", "LRB", "RRB", "LCB", "RCB", "LSB", "RSB",
  "SEMICOLON", "COMMA", "DOT", "THREEDOT", "AT", "DOUBLECOLON",
  "IDENTIFIERWK", "INSTANCEOF", "$accept", "OMPSB", "PSB",
  "OMAdditionalBound", "ReceiverParameterComma", "IdentifierDot",
  "OMImportDeclaration", "OMTopLevelClassOrInterfaceDeclaration",
  "OMDotIdentifier", "OMModuleDirective", "OMRequiresModifier",
  "OMCommaModuleName", "CommaModuleName", "OMCommaTypeName",
  "CommaTypeName", "OMClassModifier", "OMCommaTypeParameter",
  "CommaTypeParameter", "OMCommaInterfaceType", "CommaInterfaceType",
  "OMClassBodyDeclaration", "OMCommaFormalParameter",
  "CommaFormalParameter", "OMCommaExceptionType", "CommaExceptionType",
  "OMCommaEnumConstant", "CommaEnumConstant", "OMCommaRecordComponent",
  "CommaRecordComponent", "OMRecordBodyDeclaration",
  "OMInterfaceMemberDeclaration", "OMCommaVariableInitializer",
  "CommaVariableInitializer", "OMBlockStatement", "OMSwitchRule",
  "OMSwitchBlockStatementGroup", "OMSwitchLabelColon", "SwitchLabelColon",
  "OMCommaCaseConstant", "CommaCaseConstant", "OMCommaStatementExpression",
  "CommaStatementExpression", "OMCatchClause", "OMOrClassType",
  "OrClassType", "OMSemicolonResource", "SemicolonResource",
  "OMCommaExpression", "CommaExpression", "OMDimExpr", "Modifieropt",
  "Identifier", "UnqualifiedMethodIdentifier", "Literal",
  "ASSIGNMENTOPERATOR", "PrimitiveType", "NumericType", "IntegralType",
  "FloatingPointType", "ReferenceType", "TypeParameter", "TypeBound",
  "AdditionalBound", "ModuleName", "ExpressionName", "MethodName",
  "CompilationUnit", "OrdinaryCompilationUnit", "ModularCompilationUnit",
  "PackageDeclaration", "ImportDeclaration", "SingleTypeImportDeclaration",
  "SingleStaticImportDeclaration", "ImportOnDemandDeclaration",
  "StaticImportOnDemandDeclaration", "TopLevelClassOrInterfaceDeclaration",
  "ModuleDeclaration", "ModuleDirective", "ClassDeclaration",
  "NormalClassDeclaration", "TypeParameters", "TypeParameterList",
  "ClassExtends", "ClassImplements", "InterfaceTypeList", "ClassPermits",
  "ClassBody", "ClassBodyDeclaration", "ClassMemberDeclaration",
  "FieldDeclaration", "VariableDeclaratorList", "VariableDeclarator",
  "VariableDeclaratorId", "VariableInitializer", "UnannType",
  "UnannPrimitiveType", "UnannArrayType", "MethodDeclaration",
  "MethodHeader", "Result", "MethodDeclarator", "ReceiverParameter",
  "FormalParameterList", "FormalParameter", "VariableArityParameter",
  "Throws", "ExceptionTypeList", "ExceptionType", "MethodBody",
  "InstanceInitializer", "StaticInitializer", "ConstructorDeclaration",
  "ConstructorDeclarator", "ConstructorBody",
  "ExplicitConstructorInvocation", "EnumDeclaration", "EnumBody",
  "EnumConstantList", "PRB", "PRBArgumentList", "EnumConstant",
  "EnumBodyDeclarations", "RecordDeclaration", "RecordHeader",
  "RecordComponentList", "RecordComponent", "VariableArityRecordComponent",
  "RecordBody", "RecordBodyDeclaration", "CompactConstructorDeclaration",
  "InterfaceDeclaration", "NormalInterfaceDeclaration",
  "InterfaceModifier", "InterfaceExtends", "InterfacePermits",
  "InterfaceBody", "InterfaceMemberDeclaration", "ConstantDeclaration",
  "InterfaceMethodDeclaration", "ArrayInitializer",
  "VariableInitializerList", "Block", "BlockStatements", "BlockStatement",
  "LocalClassOrInterfaceDeclaration", "LocalVariableDeclarationStatement",
  "LocalVariableDeclaration", "LocalVariableType", "Statement",
  "StatementNoShortIf", "StatementWithoutTrailingSubstatement",
  "EmptyStatement", "LabeledStatement", "LabeledStatementNoShortIf",
  "ExpressionStatement", "StatementExpression", "IfThenStatement",
  "IfThenElseStatement", "IfThenElseStatementNoShortIf", "AssertStatement",
  "SwitchStatement", "SwitchBlock", "SwitchRule",
  "SwitchBlockStatementGroup", "SwitchLabel", "CaseConstant",
  "WhileStatement", "WhileStatementNoShortIf", "DoStatement",
  "ForStatement", "ForStatementNoShortIf", "BasicForStatement",
  "BasicForStatementNoShortIf", "ForInit", "ForUpdate",
  "StatementExpressionList", "EnhancedForStatement",
  "EnhancedForStatementNoShortIf", "BreakStatement", "YieldStatement",
  "ContinueStatement", "ReturnStatement", "ThrowStatement",
  "SynchronizedStatement", "TryStatement", "Catches", "CatchClause",
  "CatchFormalParameter", "CatchType", "Finally",
  "TryWithResourcesStatement", "ResourceSpecification", "ResourceList",
  "Resource", "Primary", "PrimaryNoNewArray", "ClassLiteral",
  "ClassInstanceCreationExpression",
  "UnqualifiedClassInstanceCreationExpression",
  "ClassOrInterfaceTypeToInstantiate", "FieldAccess", "ArrayAccess",
  "MethodInvocation", "ArgumentList", "MethodReference",
  "ArrayCreationExpression", "DimExpr", "Expression",
  "AssignmentExpression", "Assignment", "LeftHandSide",
  "AssignmentOperator", "ConditionalExpression", "ConditionalOrExpression",
  "ConditionalAndExpression", "InclusiveOrExpression",
  "ExclusiveOrExpression", "AndExpression", "EqualityExpression",
  "RelationalExpression", "InstanceofExpression", "ShiftExpression",
  "AdditiveExpression", "MultiplicativeExpression", "UnaryExpression",
  "PreIncrementExpression", "PreDecrementExpression",
  "UnaryExpressionNotPlusMinus", "PostfixExpression",
  "PostIncrementExpression", "PostDecrementExpression", "CastExpression",
  "SwitchExpression", "VariableAccess", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-965)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-677)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1445,  -965,   -51,  -965,  -965,    25,  -965,   -51,  -965,   -51,
    -965,   -51,  -965,   -51,  -965,    37,   -51,  -965,  2087,  1791,
    2196,  -965,    87,  -965,  -965,  1357,  -965,  -965,  -965,  -965,
    -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,
    -965,   502,   -51,   848,   854,    99,   332,   264,   100,   -51,
     272,  1791,  -965,  -965,  -965,   -51,   -51,   -51,   -51,  -965,
    -965,  1357,  1791,  -965,   -51,   891,   -14,   927,  -965,   127,
    -965,   249,   -51,   692,    44,  -965,   -51,   -51,   -51,  4145,
     349,   108,    61,  -965,   -51,   -51,  3149,    97,    30,   185,
     201,  -965,   460,   276,   308,  1113,   216,   152,    99,   332,
     264,   272,  1791,  -965,  -965,   -51,   286,  -965,   353,   329,
    -965,   334,  -965,   302,  -965,  -965,  4193,   554,   -51,  -965,
     937,   559,   316,   370,  -965,  -965,   281,   246,   424,   354,
     432,  -965,  -965,  -965,  -965,  -965,  -965,   -51,  -965,  -965,
    -965,  -965,  1662,  4247,   412,  -965,  -965,  -965,  -965,   929,
     -51,   412,  -965,   175,   426,  -965,  -965,  -965,  -965,   108,
      61,  -965,    61,  -965,  -965,  -965,   482,   246,   433,  3288,
    -965,  -965,  1662,  3976,   118,  -965,   929,  -965,  -965,  -965,
     -51,  -965,   175,  -965,  -965,  -965,     0,  -965,  -965,    30,
     185,   201,  -965,   185,   201,  -965,   201,  -965,  -965,   -51,
     -51,  1036,   -51,   -51,  -965,   518,  -965,   555,   693,   452,
    -965,   646,   449,   464,  -965,   152,  4030,   477,  -965,    44,
    -965,   349,   108,    61,  -965,    97,    30,   185,   201,  -965,
     216,   152,  -965,   511,   527,  -965,  -965,   -51,   302,  -965,
    4193,  -965,   535,  -965,   316,  4934,  -965,   201,   201,  -965,
     564,  -965,  -965,   -51,   -51,   -51,   544,  -965,   -51,  -965,
     -51,   354,  -965,  -965,  -965,   -51,   175,  -965,  -965,   570,
     412,  -965,   -51,   426,   421,   601,   606,   627,   412,  -965,
    -965,  -965,  4295,   725,    61,  -965,  -965,  -965,   544,   544,
    -965,   458,   673,   839,   686,  6635,   705,   712,  4601,  -965,
     466,  6635,  5015,   994,   719,   655,   720,  -965,  -965,  -965,
    -965,  -965,  -965,   790,   744,  -965,  -965,  -965,  -965,  -965,
     -51,  -965,  6635,  -965,  -965,  -965,  -965,  -965,  -965,  -965,
    6635,  6635,  6635,  -965,  -965,   853,  2961,   775,  -965,  -965,
     548,   900,  -965,  -965,   493,   783,  -965,  -965,   888,  3647,
    -965,  -965,   857,   -51,  -965,  -965,  -965,  -965,  -965,   897,
    -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,
    -965,  -965,  -965,  -965,  -965,  -965,  -965,   787,   912,  -965,
     324,  -965,   546,   740,   701,  -965,  -965,  -965,   810,  -965,
    -965,   845,   859,   898,   -51,   175,     0,  -965,  -965,  4325,
     525,   960,  -965,   -51,  3414,   972,  -965,   185,   201,  -965,
     201,  -965,  -965,   201,  -965,  -965,  -965,   257,   342,   360,
     361,  1036,  -965,  -965,   989,   992,   993,    36,   223,  -965,
    -965,  -965,   703,  -965,   728,   786,   -51,  -965,  -965,   839,
     464,  -965,   477,  -965,  -965,  1662,  4091,   820,  -965,  -965,
    -965,  -965,  -965,   108,    61,  -965,    61,  -965,  -965,    30,
     185,   201,  -965,   185,   201,  -965,   201,  -965,  -965,   152,
     477,  -965,  -965,  -965,  -965,  -965,  -965,   940,  -965,  -965,
    -965,  6635,  6635,  6635,  6635,  6635,  -965,   565,   493,   783,
    -965,  -965,   976,   973,  -965,  -965,  -965,   283,  1022,  1016,
    1023,  1029,   822,   390,  -965,   697,   938,   621,  -965,  -965,
    -965,  -965,   845,  -965,  -965,  -965,  -965,  -965,  -965,  -965,
     281,  1024,  -965,  1035,  -965,  -965,  1038,  -965,  -965,  -965,
    -965,   725,   412,  -965,   -51,  5096,   412,  4369,  4531,    42,
    1034,  1046,  1044,  -965,  -965,  -965,  -965,  1055,  3740,   628,
    1026,  -965,  1074,  6635,    72,  6635,  6635,   653,  1130,  -965,
    1071,  1076,  -965,  1079,  3902,   101,   433,  1143,   -51,   -51,
    6635,  1080,   394,   516,  -965,  -965,  -965,  -965,  1088,  -965,
     -51,  4601,  5177,   261,   -51,   707,  5177,   296,   -51,   737,
    5258,  1155,    43,  -965,  3647,  -965,  -965,   412,  -965,  -965,
      52,   -51,  6635,  -965,  -965,  -965,  6635,  -965,  -965,  1087,
    -965,   972,  -965,  -965,  4413,  1097,  4443,  -965,  -965,  -965,
    1092,  1102,   407,  -965,   934,   434,  3532,  1103,   794,  -965,
     201,  -965,  -965,  -965,  -965,   -51,  -965,   -51,  -965,   -51,
    -965,   -51,  -965,  -965,   996,  -965,   -51,  -965,  -965,   -51,
     -51,  -965,  -965,  -965,   864,  -965,  -965,  -965,  -965,   820,
    -965,  -965,  -965,    61,  -965,  -965,  -965,   185,   201,  -965,
     201,  -965,  -965,   201,  -965,  -965,  -965,   477,  -965,  -965,
    6635,  -965,  -965,  -965,  -965,  1104,   493,   346,  -965,  6635,
     973,  -965,  6635,  6635,  6635,  6635,  6635,  6635,  6635,  6635,
    6635,  6635,  6635,  6635,   839,  6635,  6635,  6635,  6635,  6635,
    6635,  6635,  6635,   -51,  1035,  -965,  -965,  -965,  -965,  4772,
    -965,  -965,  -965,   412,   412,   814,  1107,   823,  -965,   -51,
    1198,   746,  -965,  -965,   412,  4531,  1044,  -965,  -965,  5339,
    1977,   623,  1134,  1105,  1109,  -965,  5177,  1013,  1108,  1026,
    -965,  1013,  1026,  5420,  1116,  6635,  -965,  1119,  1120,  1122,
    -965,  -965,  -965,  3902,  -965,   663,   516,  -965,  1123,  1117,
     787,   -38,  -965,  1126,   433,  1189,  1201,  -965,   101,  -965,
    1129,  -965,  1131,  -965,  -965,  -965,  -965,  1128,   -51,  -965,
    -965,   828,  1137,  -965,  -965,  1197,  1133,  -965,  -965,   830,
    1150,  -965,  -965,  1223,  -965,  1163,  -965,  -965,  -965,  -965,
    1165,  -965,  -965,  1161,  -965,  -965,  -965,  -965,  1166,  -965,
    -965,  4487,  1167,   -51,  1092,  -965,  5501,  5582,   331,   343,
    -965,  1170,  -965,    75,  -965,   756,   863,   881,   887,  -965,
    -965,   906,   943,   957,   977,  -965,  -965,  -965,   201,  -965,
    -965,  -965,  -965,  -965,  1168,  6635,  6716,   116,  -965,  -965,
    1193,  1022,  1016,  1023,  1029,   822,   390,   390,   697,   697,
     697,   697,   412,  -965,   412,  -965,   938,   938,   938,   621,
     621,  -965,  -965,  -965,  -965,  -965,  -965,  1171,  1172,  1177,
     412,   412,   -51,  -965,  -965,  -965,  -965,   412,  -965,  -965,
    6788,  1169,  6635,  7388,  1105,  -965,  5663,  1176,  -965,   412,
    -965,  -965,   412,   201,  1182,  1184,  1178,  4697,   433,  6635,
    -965,  1117,  -965,  -965,  1036,  -965,  -965,  1201,  -965,  1189,
    -965,  5744,  4601,  -965,  1179,   -51,   -51,  5825,  -965,  -965,
     -51,   -51,  5906,  -965,  -965,  5987,  -965,  -965,  -965,  1188,
    -965,  -965,  -965,  1187,  1194,  1190,  1196,   484,   566,  -965,
    1185,  -965,   -51,   915,  -965,  -965,  1012,  -965,  1018,  -965,
    1028,  -965,  1031,  -965,  1033,  -965,  1048,  -965,  1052,  -965,
    1184,  -965,  -965,  6716,  6635,  -965,  5096,  1172,  -965,  -965,
     412,  -965,  4601,  1200,  -965,  6863,  1203,  -965,  -965,  6938,
    1192,  -965,  -965,   201,   134,  -965,  -965,  1199,  1202,  1205,
     795,  -965,  1271,  1275,  -965,  -965,  -965,  -965,  -965,  -965,
    -965,  1206,  1036,  1214,  1213,   -51,  -965,  -965,  -965,  1219,
    -965,  1221,  -965,  -965,  1226,  1224,  -965,  -965,  1227,  -965,
    1228,  -965,  -965,  1225,  -965,  1229,  6068,  6149,  6230,  1222,
    -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,
    -965,  -965,  -965,  -965,  -965,  4601,  4601,  1232,  4601,  4601,
    1233,  7013,  -965,  -965,  6635,  -965,   182,   211,  -965,   222,
    -965,   966,  3821,  6635,  6635,  4697,  4601,  1230,   -51,   -51,
    1214,  -965,   433,  -965,  -965,  6311,  -965,  6392,  -965,  -965,
    -965,  -965,  1231,  1238,  1235,  1242,  1240,  1243,  -965,  -965,
    4601,  -965,  -965,  4601,  4601,  1246,  1241,  -965,  -965,   303,
    -965,  1272,  -965,  -965,  1276,  -965,   317,  -965,  1274,  3647,
    4853,  6473,  1277,  1250,  1259,  1260,  -965,  -965,  -965,  -965,
    -965,  -965,  -965,  -965,  1261,  -965,  1262,  -965,  1258,  -965,
    1266,  -965,  1269,  -965,  -965,  -965,  4601,  6635,  1241,  -965,
    -965,  -965,  -965,  -965,  3046,  -965,  -965,  -965,  1270,  7088,
    1273,  6635,  6554,  4697,  4697,  -965,  -965,  -965,  -965,  -965,
    -965,  -965,  -965,  -965,  -965,  4697,  1264,  7163,  1265,  7238,
    1280,  1348,  -965,  -965,  4697,  4697,  1281,  4697,  4697,  1282,
    7313,  4697,  -965,  -965,  4697,  -965,  -965,  4697,  4697,  1286,
    -965,  -965,  -965,  -965,  4697,  -965
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     141,    86,     0,    85,    84,     0,    83,     0,    90,     0,
      87,     0,    89,     0,    88,     0,     0,   166,   143,   142,
       0,   392,     0,   139,   140,   145,     9,   153,   154,   156,
     155,    11,   149,   164,   199,   200,   201,   165,   375,    26,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   144,    10,   150,    12,     0,     0,     0,     0,    27,
       1,   147,   146,   151,     0,     0,     0,     0,   157,     0,
     158,     0,     0,     0,     0,   332,     0,     0,     0,     0,
       0,     0,     0,   376,     0,     0,     0,     0,     0,     0,
       0,   202,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,    13,   152,     0,     0,   159,     0,     0,
     136,     0,   137,   239,   238,   336,   352,     0,   343,    42,
     346,     0,   342,     0,   333,   393,     0,   394,   129,   235,
       0,   270,   126,   120,   122,   121,   124,     0,   123,   125,
     396,   402,     0,     0,   267,   269,   118,   119,   400,     0,
       0,   266,   268,     0,     0,   401,    50,   398,   399,     0,
       0,   380,     0,   378,   377,   237,   241,   242,    87,     0,
     245,   255,     0,     0,   267,   253,     0,    34,   247,   251,
       0,   252,     0,   248,   249,   250,     0,   254,   304,     0,
       0,     0,   210,     0,     0,   206,     0,   204,   203,     0,
       0,     0,     0,     0,   167,     0,    15,     0,     0,     0,
     362,     0,     0,   364,   367,     0,     0,     0,   354,     0,
     334,     0,     0,     0,   384,     0,     0,     0,     0,   218,
       0,     0,    14,     0,     0,   160,   161,     0,   240,    31,
     353,   338,     0,    43,     0,     0,   349,   347,   348,   340,
       0,    44,   337,     0,     0,     0,   395,    22,     0,   130,
       0,   236,    28,   234,   280,     0,     0,   397,    51,     0,
     272,     2,     0,     0,   262,     0,   258,   260,   271,   303,
     405,   302,     0,   275,     0,   382,   381,   379,   243,   244,
     305,     0,     0,     0,     0,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,     0,     0,    93,    94,    95,
      96,    97,    98,    88,   100,   101,   102,   103,   104,   105,
     106,   107,     0,   108,   109,   110,   111,   112,   113,   114,
       0,     0,     0,   412,   450,    91,     0,   614,   138,   544,
     665,     0,   419,   424,   266,   268,   420,   437,     0,   414,
     416,   417,     0,     0,   418,   426,   438,   427,   439,     0,
     428,   429,   440,   441,   430,   442,   431,   485,   486,   443,
     449,   444,   445,   447,   446,   448,   524,   663,   542,   545,
     550,   561,   551,   552,   553,   554,   543,   454,     0,   455,
     456,     0,   457,   458,     0,     0,     0,   246,    35,     0,
     267,     0,   273,     0,     0,     0,   306,     0,     0,   214,
       0,   212,   211,     0,   208,   207,   205,     0,     0,     0,
       0,     0,    17,   134,     0,     0,     0,     0,     0,   168,
      16,   169,     0,   171,     0,     0,     0,   366,   363,     0,
     365,    45,     0,   356,   369,     0,     0,   267,   371,    48,
     372,   355,   335,     0,     0,   388,     0,   386,   385,     0,
       0,     0,   226,     0,     0,   222,     0,   220,   219,     0,
       0,   358,   162,   163,    33,    32,   339,     0,    99,   100,
     106,     0,     0,     0,     0,     0,   344,   664,     0,     0,
     550,   553,     0,   592,   609,   611,   610,   618,   620,   622,
     624,   626,   628,   630,   638,   633,   640,   644,   647,   651,
     652,   655,   658,   666,   667,   661,   662,   350,   351,   341,
      24,    25,    23,   131,    30,    29,     0,   406,     4,     3,
     279,   277,   263,   403,     0,     0,   281,     0,     0,     0,
       0,     0,   291,   295,   276,   383,   515,     0,     0,   569,
       0,   117,     0,     0,     0,     0,     0,   614,     0,   512,
       0,     0,   517,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   664,   665,   551,   552,   656,   657,     0,   425,
       0,     0,     0,     0,     0,   272,     0,     0,     0,     0,
       0,     0,     0,   413,   415,    55,   421,   262,   422,   453,
       0,     0,     0,   116,   115,   617,     0,   668,   669,     0,
     274,     0,   308,   310,     0,     0,     0,   256,   301,   298,
     299,   546,     0,   318,   614,   613,     0,     0,   663,   307,
       0,   216,   215,   213,   209,     0,   177,     0,   186,     0,
     180,     0,   189,    18,     0,   175,     0,   183,   192,     0,
       0,   170,   172,   173,     0,   368,    47,    46,   357,   267,
     370,    49,   373,     0,   390,   389,   387,     0,     0,   230,
       0,   228,   227,     0,   224,   223,   221,     0,   360,   359,
       0,   660,   659,   653,   654,     0,   117,     0,   345,     0,
     593,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,     5,   404,   278,   259,     0,
     261,   265,   264,   282,   285,     0,     0,     0,   289,     0,
       0,   262,   293,     7,   283,     0,   292,    36,   516,     0,
       0,   614,   506,   508,     0,   505,     0,     0,   570,   604,
      81,     0,   602,     0,     0,     0,   464,     0,     0,     0,
     513,   519,   518,   539,    75,   675,   674,   540,     0,   538,
       0,   551,   541,     0,     0,   521,   525,   522,   533,   560,
     572,   598,     0,   514,   549,   423,   451,     0,     0,   547,
     555,     0,   136,   562,   594,     0,     0,   548,   556,     0,
     137,   563,   595,     0,   579,     0,   559,   601,   597,    56,
     571,   564,   596,     0,   612,   257,   309,   312,     0,   311,
     314,     0,     0,     0,   300,    39,     0,     0,     0,     0,
     320,     0,   319,     0,   217,     0,     0,     0,     0,   176,
     135,     0,     0,     0,     0,   174,   374,   391,     0,   232,
     231,   229,   225,   361,     0,     0,     0,     0,    80,    79,
       0,   621,   623,   625,   627,   629,   631,   632,   635,   634,
     637,   636,   127,   639,     0,   128,   641,   642,   643,   645,
     646,   648,   649,   650,   133,     6,   407,     0,   410,     0,
     286,   287,     0,   294,   296,   290,     8,   284,    38,    37,
       0,     0,     0,     0,   509,    67,     0,     0,   607,   605,
      82,   606,   603,   565,     0,     0,     0,     0,     0,     0,
      76,     0,   537,    77,     0,   532,   523,   526,    70,   535,
     534,     0,     0,   575,   569,     0,     0,     0,   557,   576,
       0,     0,     0,   558,   578,     0,   577,   313,   316,     0,
     315,    41,    40,     0,     0,     0,     0,     0,     0,   321,
       0,   178,     0,     0,    19,   187,     0,   181,     0,   190,
       0,   184,     0,   197,     0,   195,     0,   193,     0,   233,
       0,   670,   671,     0,     0,   408,     0,   411,    52,   409,
     288,   297,     0,     0,   507,     0,     0,    69,    68,     0,
       0,   608,   566,   567,     0,   466,   465,     0,     0,     0,
     614,   461,     0,   426,   433,   434,   435,   436,   487,   488,
     520,     0,     0,   530,     0,     0,    71,   536,   586,     0,
     482,   573,   599,   580,     0,   574,   600,   582,     0,   584,
       0,   317,   322,     0,   324,     0,     0,     0,     0,    21,
     179,    20,   188,   182,   191,   185,   196,   198,   194,   673,
     672,   619,    54,    53,   489,     0,     0,     0,     0,     0,
       0,     0,   568,   480,     0,   469,     0,     0,    61,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     531,    72,     0,   528,   587,     0,   581,     0,   583,   585,
     323,   325,     0,     0,     0,     0,     0,     0,   490,   491,
       0,   510,   493,     0,     0,     0,   478,   481,   471,     0,
      60,     0,   470,    62,     0,   467,     0,    57,     0,    63,
       0,     0,   506,     0,     0,     0,   452,   462,   484,   529,
      74,    73,   527,   588,     0,   590,     0,   326,     0,   328,
       0,   330,     0,   492,   494,   495,     0,     0,   479,    64,
     472,    63,   468,    58,     0,   476,   474,   475,     0,     0,
       0,     0,     0,     0,     0,   589,   591,   327,   329,   331,
     496,    66,    65,   477,   473,     0,     0,     0,     0,     0,
       0,     0,   483,   497,     0,     0,     0,     0,     0,     0,
       0,     0,   498,   499,     0,   511,   501,     0,     0,     0,
     463,   500,   502,   503,     0,   504
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -965,   840,  -120,   706,  -375,  -965,  1369,   314,   275,  -173,
    -965,   256,  -133,  -154,  -250,    59,  -965,  1139,  -965,  1160,
    1289,  -965,   674,  -965,   585,  -965,  1294,  -965,   975,  -965,
    -965,  -965,   430,  -965,  -965,  -965,  -964,  -809,  -965,   260,
    -965,   515,  -965,  -965,   330,  -965,   658,  -965,   732,   874,
    -172,    -2,  -965,  -965,  -965,   941,  -965,  -965,  -965,  -965,
    1174,  -965,  -684,  -358,   551,  -965,  -965,  -965,  -965,  -965,
     291,  -965,  -965,  -965,  -965,   282,  1407,  -177,    60,  -965,
     541,  -965,     5,   207,  1351,    -9,  2581,  -131,  -965,  -965,
    -134,  -965,  -531,  -701,  2797,   729,   837,  -965,   -46,   230,
    1156,  -965,  -380,   695,  -965,  -262,  -965,   605,  -130,  -965,
    -965,  -965,  -152,  -345,  -965,  -965,   -26,  -965,  -965,  -965,
    1314,   758,  -965,    -6,  -965,   997,  -965,  -107,   998,  -965,
     288,  -167,   -19,   -35,   -58,   165,  1292,  -965,  -965,   142,
    -965,   -55,  -400,  -306,  -965,  -965,  -538,  -320,  1183,   123,
    -656,  -965,  -965,  -965,  -965,  -340,  -965,  -965,  -965,  -965,
    -965,   463,  -773,   362,  -947,   290,  -965,  -965,  -965,  -965,
    -965,  -965,  -965,   363,  -394,  -533,  -965,  -965,  -965,  -965,
    -965,  -965,   310,  -965,  -965,   671,  -732,  -965,   428,  -689,
    -965,  -965,  -965,   689,  -387,  -965,  -965,   447,  -472,  -965,
    -210,  2159,   687,    70,  -965,  -965,   205,   232,  -965,   860,
    -965,  -965,  -952,  -965,   762,   763,   764,   766,   761,   471,
    -965,   358,   391,   469,  -294,  1007,  1245,  -831,  1400,  1547,
    1734,  -965,  -965,  -965
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   585,   271,   714,   537,   730,    18,    19,   748,   205,
     421,   963,   964,   256,   257,    20,   261,   262,   238,   239,
     173,   736,   737,   824,   825,   118,   119,   440,   441,   446,
     143,   987,   988,   594,  1126,  1076,  1077,  1078,  1158,  1159,
     904,   905,   927,  1090,  1091,   763,   764,   690,   691,   749,
      21,   487,   338,   339,   605,   550,   145,   146,   147,   873,
     129,   259,   715,   424,   340,   341,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,   206,    33,    34,
     176,   130,    88,    74,   114,    90,    91,   177,   178,   179,
     275,   276,   277,   720,   343,   488,   489,   181,   182,   154,
     283,   540,   541,   542,   543,   405,   619,   620,   280,   183,
     184,   185,   186,   406,   626,    35,    75,   121,   247,   248,
     122,   123,    36,    97,   212,   213,   214,   218,   449,   450,
      37,    38,    39,    81,    82,    83,   156,   157,   158,   721,
     889,   347,   348,   349,   350,   351,   352,   353,   354,  1012,
     355,   356,   357,  1014,   358,   359,   360,   361,  1015,   362,
     363,  1005,  1079,  1080,  1124,  1116,   364,  1016,   365,   366,
    1017,   367,  1018,   744,   993,   994,   368,  1019,   369,   370,
     371,   372,   373,   374,   375,   775,   776,  1024,  1025,   777,
     376,   566,   768,   769,   377,   378,   379,   490,   381,   552,
     382,   383,   491,   492,   385,   386,   750,   493,   494,   495,
     388,   606,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   772
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    59,   346,    43,   627,    45,   522,    46,   732,    47,
     742,    48,   288,   289,    50,   745,   580,   628,   888,   615,
     396,   544,   160,   162,   614,   982,   767,   403,   430,   422,
     885,   188,  1061,   153,   432,   434,   576,   577,   522,   522,
      66,   223,   398,   595,   928,   159,   401,    94,   124,   807,
      72,   612,   402,    98,    99,   100,   101,  1081,   788,   728,
     629,   188,   103,   644,   222,    42,    40,   110,  -676,   112,
     113,   120,   220,  -676,   113,   126,   128,   144,   191,   194,
     196,   788,   165,   166,   174,   448,   926,    60,    85,   930,
     215,   228,   189,   144,    49,   231,   266,   153,   281,   106,
     649,   284,   662,   232,   110,   226,   112,   404,   443,   398,
     451,   793,  1119,   290,   174,   801,   120,    72,   188,    72,
     574,   574,  1117,    59,   471,   960,   395,   281,   811,  1121,
      84,   526,  1128,   773,   611,   264,   527,    86,   142,   148,
     144,   144,    40,  1073,   774,   172,   175,   144,   274,   253,
     529,    73,  1060,    59,   755,    85,   729,   726,   529,    40,
      40,   188,  1074,   454,   456,  1164,    77,   337,    79,    40,
     174,   174,    72,   885,   400,   172,   175,   770,   274,  1128,
     408,   410,   346,   756,   413,   188,   453,   681,   682,   683,
     684,  1073,    40,   452,   732,  1026,   893,   417,   419,   423,
     425,   427,   142,   148,    86,  1117,    73,    92,   743,   437,
    1074,   281,   713,    64,   447,    79,   461,   464,   466,   598,
    1073,   109,   983,   399,   469,   767,   831,   269,   336,   342,
     459,  1073,   172,   175,   818,   474,   822,   346,   174,  1074,
    1027,   821,  1075,    85,    40,   161,   163,   164,   565,   643,
    1074,   110,   520,   112,    89,   430,   523,   430,   128,   216,
     609,  1013,   654,   274,   224,   610,   816,   788,  1123,   717,
     530,   574,   574,   574,   574,   445,   175,   835,   789,   836,
     144,   837,   169,   838,    72,  1062,   279,   650,   809,   547,
    1118,   549,    86,   396,   190,   193,   557,    84,   560,   172,
     175,    54,   788,   790,   217,   219,  1127,   227,    86,    52,
    1123,   791,  1073,   797,   846,   448,    65,    59,    50,  1122,
     635,    95,    85,    93,   285,   286,  1073,   287,   572,   572,
    1125,  1074,    51,    54,   144,   658,   255,   788,   798,    62,
     281,   538,    78,   111,    54,  1074,   799,   337,   789,   788,
      78,   597,    52,  1163,   771,  1123,   793,   801,   254,   255,
     797,   811,   678,   679,   692,    76,    40,   155,   636,   209,
     253,    86,   693,   790,   187,   102,   770,    95,    40,   273,
     233,   957,    76,   207,    54,   798,   455,   457,   458,   105,
      77,   188,   274,   958,   253,   663,   407,   144,   630,   395,
     718,   618,   624,    40,   187,   637,   273,    77,   336,   342,
      78,  1160,   529,    40,   237,   208,   881,   882,   883,   423,
     580,    64,   442,   639,   641,  1162,    59,   346,   251,  1013,
    -460,   155,   460,   463,   655,  -460,  -460,   144,   470,    79,
     235,   949,   713,   659,   447,   236,   785,   234,    40,   545,
     668,   670,   856,   638,   673,   255,    79,   258,   538,   346,
      40,   187,   592,   336,   342,   529,   260,   700,   701,   529,
      40,   640,   642,   253,   255,   702,   703,   430,   252,   572,
     572,   572,   572,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,  1093,   574,   574,   574,   574,   574,
     574,   574,   574,   582,   187,   445,   175,   583,   704,   263,
     584,   778,   827,   199,   200,   201,   202,  1013,  1013,    59,
     568,   269,   203,   569,  -665,  -665,  -279,   554,   187,  1013,
     269,   282,   597,   561,   563,   144,   144,   731,  1013,  1013,
     169,  1013,  1013,   586,  1132,  1013,   741,   829,  1013,   745,
     588,  1013,  1013,   771,   571,   438,    44,  1139,  1013,   435,
     743,   981,   765,   997,   578,   105,   780,   781,   204,   546,
     853,   199,   200,   201,   202,    40,   439,   559,   597,   557,
     203,   792,   794,    40,   216,   800,   802,    80,    87,  1046,
     808,    96,   337,    67,   254,   253,   538,   935,   810,   812,
     936,  1067,   269,   529,  1049,  1070,   591,   740,   199,   200,
     201,   202,   144,    63,   144,    64,   380,   203,   664,   665,
     149,   666,   472,   740,   337,   586,   429,   529,   127,   587,
     616,   529,   588,   423,   269,   423,   167,   423,   473,   423,
     221,   225,   230,   476,   840,   574,   574,   841,   843,  -615,
    -615,  -613,  -613,   336,   342,   743,   254,   586,   848,   743,
     805,   587,   241,   431,   588,   116,   667,   249,  -614,  -614,
     116,  1047,   519,   538,   582,   538,   677,  1115,   583,   940,
     528,   584,   941,   149,   149,   336,   342,   972,   974,   976,
     978,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   872,   572,   572,   572,   572,   572,   572,   572,
     572,   884,   533,  -664,  -664,   710,   711,   578,   534,   925,
     712,    59,   522,   597,   522,   597,   522,   894,   522,  1165,
     535,   743,   582,   144,   187,   581,   583,   746,   144,   584,
    -267,    64,   743,  -664,  -664,   380,   199,   200,   201,   202,
     418,   420,   403,   426,   428,   203,   199,   200,   201,   202,
     436,   765,   582,    40,  1183,   203,   583,   722,   568,   584,
     529,   569,   582,   574,   574,  1186,   583,   529,   548,   584,
    -267,   199,   200,   201,   202,   754,   934,   757,   758,   529,
     203,   553,   529,  1196,   538,  1199,   380,   705,   706,   707,
     115,   433,   782,   116,   117,   521,  1209,  -459,   151,    40,
     555,   651,  -459,  -459,   787,   151,   269,   556,   796,   144,
     795,   618,   740,   914,   151,   570,   792,   800,   847,   743,
    1051,   810,   567,  1051,   813,  1051,   652,  1051,   814,   199,
     200,   201,   202,  -616,  -616,   151,   269,   743,   203,   743,
     803,   380,   131,   572,   572,   269,   384,   581,   132,   896,
     743,  -425,   133,  1020,   574,  -664,  -664,   961,   962,   646,
     529,   151,   151,   134,   135,   242,   136,  1085,   151,   250,
     538,   573,   573,   138,   582,  -664,  -664,   139,   583,   908,
     991,   584,  -267,   911,   653,   -99,   954,   956,   344,   592,
     600,   151,   151,   601,   582,   151,   698,   833,   583,   699,
     601,   584,   854,   603,   604,  1010,   152,   199,   200,   201,
     202,   858,  1023,   152,   860,   399,   203,   404,   729,   269,
     557,    40,   152,  1031,  1032,   607,   608,   892,  1035,  1036,
      40,   935,   131,   940,   936,   151,   941,   574,   132,  -666,
    -666,   722,   133,   152,   910,   625,    40,   910,   -92,    68,
     423,    69,   346,   134,   135,    70,   136,    71,   596,   151,
     137,   901,   845,   138,   965,   962,   646,   139,   907,   152,
     152,   572,   572,  1022,   270,   384,   152,   916,  -667,  -667,
     557,   278,   967,   962,   646,   380,   593,   346,   969,   962,
     646,  1029,   104,    59,   105,   590,   345,  1034,   599,   152,
     152,   151,  1038,   152,   270,  1040,   581,   971,   254,   253,
    1023,   602,   551,   597,  -664,  -664,  1050,   962,   380,   387,
     708,   709,   573,   573,   573,   573,   384,  1142,   107,     1,
     108,   380,   245,   582,    86,   680,    40,   828,  1129,  1130,
     584,  -267,     3,   152,   973,   254,   255,     4,   868,   869,
     870,   871,     6,   557,   557,   151,   557,   557,   975,   254,
     253,   617,   572,   380,     8,  1166,    10,   152,   344,   404,
     741,    12,   688,  1010,   557,   689,   597,  1140,   977,   254,
     255,   384,   966,   968,   970,    14,   876,   877,   878,   564,
     645,   169,   646,   647,   648,   253,   255,   839,   557,   646,
     694,   557,   557,   695,   532,   766,  1103,  1105,  1107,   152,
     719,   696,   269,  1052,   962,   697,   131,   337,   151,  1053,
     962,   713,   132,   344,   996,   746,   133,   255,  1000,  1054,
     962,   740,  1055,   254,  1056,   254,   733,   134,   135,   716,
     136,  1021,   734,    40,   557,   572,   735,   138,   387,  1057,
     254,   139,   337,  1058,   254,  1144,   738,  1146,   151,   866,
     867,  1010,  1010,   152,   151,   151,   389,   879,   880,   753,
     589,   759,   760,  1010,   278,   779,   345,   761,   336,   342,
     762,   783,  1010,  1010,   784,  1010,  1010,   806,   815,  1010,
     842,   844,  1010,   819,   823,  1010,  1010,   826,  1136,   387,
     855,   832,  1010,   891,   686,   895,   902,   903,   722,   210,
     906,   105,   915,   336,   342,   917,   918,   919,   923,   922,
      40,   924,   774,   773,   931,   384,   152,   932,   933,   938,
     270,   345,   937,   939,   573,   573,   573,   573,   573,   573,
     573,   573,   573,   573,   573,   942,   573,   573,   573,   573,
     573,   573,   573,   573,   387,   943,   151,   151,   384,   944,
     945,   946,   947,   950,   980,   984,   152,   344,   959,   985,
     995,   384,   152,   152,   986,   989,  1001,   270,  1003,  1006,
    1048,  1004,    64,   344,  1041,  1086,  1191,  1192,  1042,  -432,
    1043,  1044,  1045,  1071,  1082,   389,  1065,  1083,  1193,  1068,
    1084,  1089,  1087,   384,   766,  1134,  1135,  1202,  1203,  1092,
    1205,  1206,   687,   344,  1210,  1094,  1095,  1211,   278,  1097,
    1212,  1213,  1096,  1098,  1099,   646,  1100,  1215,  1110,  1113,
    1101,  1138,  1147,   151,  1148,   151,  1149,   380,  1150,  1152,
     380,  1151,  1156,  1157,  1129,   344,   389,  1130,  1161,  1171,
       1,  1172,  1168,  1170,   380,  1173,  1174,  1175,  1176,  1177,
    1194,  1197,  1201,     3,   152,   152,   723,  1178,     4,   380,
    1179,  1184,     5,     6,  1187,   345,     7,  1204,  1207,   747,
     751,  1200,  1214,   857,    61,     8,     9,    10,   475,    11,
     525,   345,    12,  1188,  1190,   240,   573,   573,   387,   952,
     899,   389,   243,   589,   390,   657,    14,  1063,  1182,   998,
    1141,   920,   859,    16,   752,    53,   685,   125,   951,   531,
     898,   345,   244,   874,   524,   268,   656,   532,  1120,   380,
    1167,   387,   380,  1059,   661,  1133,   380,  1181,     1,   929,
    1088,   152,   921,   152,   387,   861,     2,   862,   865,   863,
       0,     3,   864,   345,   151,   589,     4,     0,    17,   151,
       5,     6,     0,     0,     7,     0,     0,     0,     0,     0,
       0,   558,     0,     8,     9,    10,   387,    11,     0,     0,
      12,     0,   344,     0,     0,     0,     0,     0,     0,   270,
       0,     0,    13,     0,    14,     0,     0,     0,     0,     0,
      15,    16,   380,   380,     0,   380,   380,     0,   380,     0,
       0,     0,     0,     0,     0,     0,   278,     0,     0,   380,
       0,     0,   380,   380,   573,   573,     0,     0,     0,     0,
       0,   875,     0,   390,     0,     0,     0,     0,     0,     0,
     151,     0,     0,     0,     0,   389,    17,   380,     0,     0,
     380,   380,     0,     0,   890,     0,     0,     0,     0,   391,
       0,   532,   152,     0,   897,     0,   380,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   384,   389,   909,
     384,     0,   912,     0,   390,     0,     0,     0,     0,     0,
     345,   389,     0,   380,   384,     0,   589,     0,     0,     0,
       0,   380,     0,     0,     0,     0,   380,     0,     0,   384,
     380,   380,     0,     0,     0,   573,     0,     0,     0,     0,
       0,     0,   380,   389,   380,     0,   380,     0,     0,     0,
       0,   380,   380,     0,   380,   380,     0,   380,   380,   390,
       0,   380,     0,     0,   380,   380,     0,     0,   152,     0,
       0,   380,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131,     0,     0,     3,   384,
       0,   132,   384,     4,     0,   133,   384,     0,     6,     0,
       0,    55,     0,     0,     0,     0,   134,   135,   391,   136,
       8,    56,    10,   137,    57,     0,   138,    12,   573,     0,
     139,     0,   270,     0,   278,     0,   392,     0,     0,     0,
       0,    14,     0,     0,     0,     0,     0,     0,    58,     0,
       0,   990,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,     0,     0,     0,     0,     0,     0,   391,
       0,     0,   384,   384,     0,   384,   384,     0,   384,     0,
     387,     0,     0,   387,   786,     0,     0,     0,     0,   384,
       0,     0,   384,   384,     0,     0,     0,   387,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   387,   390,     1,     0,     0,   384,     0,     0,
     384,   384,     0,     0,   391,     0,     0,     3,     0,     0,
       0,   344,     4,     0,     0,     0,   384,     6,     0,     0,
       7,     0,     0,     0,     0,     0,   390,     0,     0,     8,
       9,    10,     0,    11,     0,     0,    12,     0,     0,   390,
       0,     0,     0,   384,     0,   392,     0,     0,     0,     0,
      14,   384,   387,     0,     0,   387,   384,    16,   344,   387,
     384,   384,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   390,   384,     0,   384,     0,   384,     0,     0,     0,
       0,   384,   384,     0,   384,   384,     0,   384,   384,     0,
       0,   384,     0,   344,   384,   384,   392,     0,     0,     0,
       0,   384,    17,   393,     0,     0,     0,   389,     0,     0,
     389,     0,     0,     0,     0,     0,     0,     0,     0,   345,
       0,     0,     0,     0,   389,   387,   387,     0,   387,   387,
       0,   387,     0,     0,     0,     0,     0,     0,     0,   389,
       0,     0,   387,     0,     0,   387,   387,     0,   391,     0,
       0,   392,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   345,     0,     0,     0,
     387,     0,     0,   387,   387,     0,     0,     0,     0,     0,
       1,   391,     0,     0,     0,     0,     0,     0,     0,   387,
     131,     0,     0,     3,   391,     0,   132,     0,     4,   389,
     133,   345,   389,     6,     0,     0,   389,     0,     0,     0,
       0,   134,   135,     0,   136,     8,   387,    10,     0,     0,
       0,   138,    12,     0,   387,   139,   391,     0,     0,   387,
       0,     0,   393,   387,   387,     0,    14,   579,     0,     0,
       0,     0,     0,     0,     0,   387,     0,   387,     0,   387,
       0,     0,     0,     0,   387,   387,     0,   387,   387,     0,
     387,   387,     0,     0,   387,     0,     0,   387,   387,     0,
       0,     0,   389,   389,   387,   389,   389,     0,   389,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,   389,
       1,     0,   389,   389,    40,   392,     0,     0,     0,     0,
    1011,     0,     0,     3,     0,     0,     0,     0,     4,     0,
       0,     0,     5,     6,     0,  1030,     7,   389,     0,     0,
     389,   389,     0,     0,     0,     8,     9,    10,   392,    11,
       0,     0,    12,     0,     0,     0,   389,     0,   393,     0,
       0,   392,     0,     0,    13,   390,    14,     0,   390,     0,
       0,     0,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     0,   390,   389,     0,     0,     0,     0,     0,     0,
       0,   389,     0,   392,     0,  1064,   389,   390,     0,     0,
     389,   389,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   389,     0,   389,     0,   389,     0,    17,     1,
       0,   389,   389,     0,   389,   389,     0,   389,   389,     0,
       0,   389,     3,     0,   389,   389,     0,     4,     0,     0,
       0,   389,     6,     0,     0,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     8,    56,    10,   390,    57,     0,
     390,    12,     0,     0,   390,     0,     0,     0,  1108,  1109,
       0,  1111,  1112,     0,     0,    14,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,   786,  1137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1153,     0,     0,  1154,  1155,     0,     0,
     391,     0,     0,   391,     0,     0,     0,     0,     0,     0,
     390,   390,     0,   390,   390,   393,   390,   391,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   390,   393,     0,
     390,   390,   391,     0,     0,     0,     0,     0,     0,  1180,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   390,  1011,  1030,   390,   390,
     393,     0,     0,     0,     0,     0,     0,     0,  1064,     0,
       0,     0,     0,     0,   390,     0,     0,  1108,  1109,     0,
    1111,  1112,     0,     0,  1137,     0,     0,  1153,     0,     0,
    1154,  1155,   391,     0,     0,   391,     0,  1180,     0,   391,
       0,   390,     0,     0,     0,     0,     0,     0,     0,   390,
       0,     0,     0,     0,   390,     0,     0,     0,   390,   390,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     390,     0,   390,     0,   390,     0,     0,     0,     0,   390,
     390,     0,   390,   390,     0,   390,   390,   392,     0,   390,
     392,     0,   390,   390,     0,     0,     0,     0,     0,   390,
       0,     0,     0,     0,   392,   391,   391,     0,   391,   391,
       0,   391,     0,     0,     0,     0,     0,     0,     0,   392,
       0,     0,   391,     0,     0,   391,   391,     0,     0,   575,
     575,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     391,     0,     0,   391,   391,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   391,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   392,
       0,     0,   392,     0,     0,     0,   392,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   391,     0,     0,     0,
       0,     0,     0,     0,   391,     0,     0,     0,     0,   391,
       0,     0,     0,   391,   391,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   391,     0,   391,     0,   391,
       0,     0,     0,     0,   391,   391,     0,   391,   391,     0,
     391,   391,     0,     0,   391,     0,     0,   391,   391,     0,
       0,     0,   392,   392,   391,   392,   392,     0,   392,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   392,
       0,     0,   392,   392,   393,     0,     0,   393,     0,     0,
     575,   575,   575,   575,     0,     0,     0,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,   392,     0,     0,
     392,   392,     0,     0,     0,     0,   393,     0,   192,   195,
     197,   198,     0,     0,     0,     0,   392,     0,     0,     0,
       0,   229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   246,     0,   392,     0,     0,     0,     0,     0,     0,
       0,   392,     0,     0,     0,     0,   392,     0,     0,     0,
     392,   392,     0,   575,     0,     0,   393,     0,     0,   393,
       0,     0,   392,   393,   392,     0,   392,     0,     0,     0,
       0,   392,   392,     0,   392,   392,     0,   392,   392,     0,
       0,   392,     0,     0,   392,   392,     0,     0,     0,     0,
       0,   392,     0,     0,     0,     0,     0,     0,     0,     0,
     409,   411,   412,     0,   414,   415,     0,   416,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   393,
     393,     0,   393,   393,     0,   393,   462,   465,   467,   468,
       0,     0,     0,     0,     0,     0,   393,     0,     0,   393,
     393,     0,     0,     0,     0,     0,     0,     0,   517,   518,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   393,     0,     0,   393,   393,     0,
       0,     0,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   393,   575,   575,   575,   575,   575,   575,
     575,   575,     0,     0,     0,     0,   150,     0,     0,     0,
       0,     0,     0,   180,     0,     0,     0,     0,     0,     0,
     393,     0,   211,     0,     0,     0,     0,     0,   393,     0,
       0,     0,     0,   393,     0,     0,     0,   393,   393,     0,
       0,     0,     0,   180,     0,     0,     0,     0,     0,   393,
       0,   393,   575,   393,     0,     0,     0,     0,   393,   393,
       0,   393,   393,     0,   393,   393,     0,     0,   393,   265,
     150,   393,   393,     0,     0,     0,   272,     0,   393,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,   394,
     180,     0,     0,   272,   131,     0,     0,     3,     0,     0,
     132,     0,     4,     0,   133,     0,     0,     6,   631,   632,
      55,   633,     0,     0,   634,   134,   135,     0,   136,     8,
      56,    10,     0,    57,     0,   138,    12,     0,     0,   139,
       0,     0,     0,   180,   575,   575,     0,     0,     0,     0,
      14,   579,     0,     0,     0,     0,     0,    58,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   180,     0,     0,
     669,   671,   672,     0,   674,   675,     0,   676,     0,     1,
     291,   292,   293,   294,   295,  1073,   296,     0,   297,   131,
     298,     0,     3,   299,   300,   132,     0,     4,   301,   133,
       0,     0,     6,     0,  1074,     7,   302,     0,    40,   539,
     134,   135,   303,   136,     8,     9,    10,   304,    11,     0,
     138,    12,     0,     0,   139,     0,   305,   306,     0,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   330,   331,     0,     0,
       0,     0,   575,   575,     0,     0,     0,     0,     0,     0,
       0,   332,     1,   169,     0,     0,     0,   334,     0,     0,
       0,     0,   131,   335,     0,     3,     0,     0,   132,     0,
       4,     0,   133,     0,     0,     6,     0,     0,     7,     0,
       0,     0,     0,   134,   135,     0,   136,     8,     9,   168,
     137,    11,     0,   138,    12,     0,   539,   139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,     0,
       0,   834,     0,     0,     0,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,   575,     0,     0,   211,     0,     0,     0,
       0,     0,   394,   180,     0,     0,     0,     0,   849,   850,
       0,   851,     0,     0,   852,     0,   169,   170,     0,     0,
     171,     0,     0,     0,     0,     0,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,   291,   292,   293,   294,   295,     0,   296,     0,
     297,   131,   298,     0,     3,   299,   300,   132,     0,     4,
     301,   133,     0,     0,     6,     0,   575,     7,   302,     0,
       0,     0,   134,   135,   303,   136,     8,     9,    10,   304,
      11,     0,   138,    12,   725,   727,   139,     0,   305,   306,
       0,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   330,   331,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   332,     0,   169,   333,     0,     0,   334,
       0,     0,     0,     0,     0,   335,     0,     0,     0,     0,
       0,   725,     0,   539,     0,     0,     0,     1,   291,   292,
     293,   294,   295,     0,   296,     0,   297,   131,   298,   979,
       3,   621,   300,   132,     0,     4,   301,   133,     0,     0,
       6,     0,     0,     7,   302,     0,     0,     0,   134,   135,
     303,   136,     8,     9,    10,   304,    11,     0,   138,    12,
       0,     0,   139,     0,   622,   306,     0,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
       0,     0,     0,     0,  1002,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   330,   331,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   332,
       0,   169,   623,     0,     0,   334,     0,     0,     0,     0,
       0,   335,   725,     0,     0,     1,   291,   292,   293,   294,
     295,     0,   296,     0,   297,   131,   298,     0,     3,   299,
     300,   132,     0,     4,   301,   133,     0,     0,     6,     0,
       0,     7,   302,     0,     0,     0,   134,   135,   303,   136,
       8,     9,    10,   304,    11,     0,   138,    12,     0,     0,
     139,     0,   305,   306,  1072,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   725,     0,
       0,     0,   330,   331,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   332,     0,   169,
     830,     0,     0,   334,     0,     0,     0,     0,     0,   335,
       1,   291,   292,   293,   294,   295,     0,   296,     0,   297,
     131,   298,     0,     3,   299,   300,   132,     0,     4,   301,
     133,     0,     0,     6,     0,     0,     7,   302,     0,     0,
       0,   134,   135,   303,   136,     8,     9,    10,   304,    11,
       0,   138,    12,     0,     0,   139,     0,   305,   306,     0,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   330,   331,     0,
       0,     0,     0,     1,     0,     0,   293,     0,     0,     0,
       0,     0,   332,   131,   169,     0,     3,   299,   334,   132,
       0,     4,     0,   133,   335,     0,     6,     0,     0,     0,
       0,     0,     0,     0,   134,   135,     0,   136,     8,     0,
      10,   304,     0,     0,   138,    12,     0,     0,   139,     0,
     305,     0,     0,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   480,   321,     0,   323,
     324,   325,   326,   327,   328,   329,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,   293,     0,     0,
     330,   331,     0,     0,   131,     0,     0,     3,   299,     0,
     132,     0,     4,     0,   133,   332,     0,     6,     0,     0,
       0,   739,     0,     0,     0,   134,   135,   335,   136,     8,
       0,    10,   304,     0,     0,   138,    12,     0,     0,   139,
       0,   305,     0,     0,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   480,   321,     0,
     323,   324,   325,   326,   327,   328,   329,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,   293,     0,
       0,   330,   331,     0,     0,   131,     0,     0,     3,   299,
       0,   132,     0,     4,     0,   133,   332,     0,     6,     0,
       0,     0,  1131,     0,     0,     0,   134,   135,   335,   136,
       8,     0,    10,   304,     0,     0,   138,    12,     0,     0,
     139,     0,   305,     0,     0,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   480,   321,
       0,   323,   324,   325,   326,   327,   328,   329,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
       0,     0,     3,     0,     0,   132,     0,     4,     0,   133,
       0,     0,     6,     0,     0,     7,     0,   332,     0,     0,
     134,   135,     0,   136,     8,     9,   168,   137,    11,   335,
     138,    12,     0,     0,   139,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,    14,     0,     0,     0,     0,
       0,     0,    16,   131,     0,     0,     3,     0,     0,   132,
       0,     4,     0,   133,    78,     0,     6,     0,     0,     7,
       0,     0,     0,     0,   134,   135,     0,   136,     8,     9,
     168,   137,    11,     0,   138,    12,     0,     0,   139,     0,
       0,     0,     0,   169,   397,     0,     0,   171,     0,    14,
       0,     0,     0,    40,     1,     0,    16,     0,     0,     0,
       0,     0,     0,     0,   131,     0,     0,     3,    78,     0,
     132,     0,     4,     0,   133,     0,     0,     6,     0,     0,
       7,     0,     0,     0,     0,   134,   135,     0,   136,     8,
       9,   168,   137,    11,     0,   138,    12,   169,   444,   139,
       0,   171,     0,     0,     0,     0,     0,    40,     1,     0,
      14,     0,     0,     0,     0,     0,     0,    16,   131,     0,
       0,     3,     0,     0,   132,     0,     4,     0,   133,    78,
       0,     6,     0,     0,     7,     0,     0,     0,     0,   134,
     135,     0,   136,     8,     9,    10,   137,    11,     0,   138,
      12,     0,     0,   139,     0,     0,     1,     0,   169,   660,
       0,     0,   171,     0,    14,     0,   131,     0,    40,     3,
       0,    16,   132,     0,     4,     0,   133,     0,     0,     6,
       0,     0,     7,    78,     0,     0,     0,   134,   135,     0,
     136,     8,     9,   168,   137,    11,     0,   138,    12,     0,
       0,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,    14,   140,     0,     0,   141,     0,     0,    16,
     131,     0,    40,     3,     0,     0,   132,     0,     4,     0,
     133,    78,     0,     6,     0,     0,     7,     0,     0,     0,
       0,   134,   135,     0,   136,     8,     9,    10,   137,    11,
       0,   138,    12,     0,     0,   139,     0,     0,     1,     0,
     169,     0,     0,     0,   171,     0,    14,     0,   131,     0,
      40,     3,     0,    16,   132,     0,     4,     0,   133,     0,
       0,     6,     0,     0,     0,    78,     0,     0,     1,   134,
     135,     0,   136,     8,     0,    10,     0,     0,   131,   138,
      12,     3,     0,   139,   132,     0,     4,     0,   133,     0,
       0,     6,     0,     0,    14,   267,     0,     0,   141,   134,
     135,     0,   136,     8,    40,    10,     0,     0,     0,   138,
      12,     0,     1,   139,     0,     0,     0,     0,     0,     0,
       0,     0,   131,     0,    14,     3,     0,     0,   132,     0,
       4,     0,   133,     0,     0,     6,     0,     0,     0,     0,
       0,   536,     0,   134,   135,     0,   136,     8,     0,    10,
       0,     0,    40,   138,    12,     0,     1,   139,     0,     0,
       0,     0,     0,     0,     0,     0,   131,     0,    14,     3,
       0,   613,   132,     0,     4,     0,   133,     0,     0,     6,
       0,     0,    40,     0,     0,     0,     1,   134,   135,     0,
     136,     8,     0,    10,     0,     0,   131,   138,    12,     3,
       0,   139,   132,     0,     4,     0,   133,     0,     0,     6,
       0,     0,    14,     0,     0,   724,     0,   134,   135,     0,
     136,     8,     0,    10,     0,     0,    40,   138,    12,     0,
       1,   139,     0,     0,     0,     0,     0,     0,     0,     0,
     131,     0,    14,     3,     0,     0,   132,     0,     4,     0,
     133,     0,     0,     6,     0,     0,     0,     0,     0,   817,
       0,   134,   135,     0,   136,     8,     0,    10,     0,     0,
      40,   138,    12,     0,     1,   139,     0,     0,     0,     0,
       0,     0,     0,     0,   131,     0,    14,     3,     0,   820,
     132,     0,     4,     0,   133,     0,     0,     6,     0,     0,
      40,     0,     0,     0,     0,   134,   135,     0,   136,     8,
       0,    10,     0,     0,     0,   138,    12,     0,     0,   139,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     0,   948,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    40,   291,   292,   293,   294,   295,
       0,   296,     0,   297,   131,   298,     0,     0,   299,   300,
     132,     0,     0,   301,   133,     0,     0,     0,     0,     0,
       0,   302,     0,     0,     0,   134,   135,   303,   136,     0,
       0,     0,   304,     0,     0,   138,     0,     0,    40,   139,
       0,   305,   306,     0,   307,   308,   309,   310,   311,   312,
     478,   479,   315,   316,   317,   318,   319,   480,   321,   322,
     323,   324,   325,   326,   327,   328,   329,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   330,   331,     0,     0,     0,     0,     0,     0,     0,
       0,   291,  1007,   293,   294,   295,   332,  1008,   169,   297,
     131,   298,   334,     0,   299,   300,   132,     0,   335,   301,
     133,     0,     0,     0,     0,     0,     0,   302,     0,     0,
       0,   134,   135,   303,   136,     0,     0,     0,   304,     0,
       0,   138,     0,     0,     0,   139,     0,   305,  1009,     0,
     307,   308,   309,   310,   311,   312,   478,   479,   315,   316,
     317,   318,   319,   480,   321,   322,   323,   324,   325,   326,
     327,   328,   329,     0,     0,     0,     0,     0,   293,   477,
       0,     0,     0,     0,     0,   131,     0,   330,   331,   299,
       0,   132,     0,     0,     0,   133,     0,     0,     0,     0,
       0,     0,   332,     0,   169,     0,   134,   135,   334,   136,
       0,     0,     0,   304,   335,     0,   138,     0,     0,     0,
     139,     0,   305,     0,     0,   307,   308,   309,   310,   311,
     312,   478,   479,   315,   316,   317,   318,   319,   480,   321,
       0,   323,   324,   325,   326,   327,   328,   329,     0,     0,
       0,   481,   482,     0,     0,     0,     0,     0,     0,   293,
     477,     0,   330,   331,   483,   484,   131,     0,     0,     0,
     299,     0,   132,     0,     0,   301,   133,   485,     0,   719,
     886,     0,     0,     0,   887,     0,     0,   134,   135,   335,
     136,     0,     0,     0,   304,     0,     0,   138,     0,     0,
       0,   139,     0,   305,     0,     0,   307,   308,   309,   310,
     311,   312,   478,   479,   315,   316,   317,   318,   319,   480,
     321,     0,   323,   324,   325,   326,   327,   328,   329,     0,
       0,     0,   481,   482,     0,     0,     0,     0,     0,     0,
     293,   477,     0,   330,   331,   483,   484,   131,     0,     0,
       0,   299,     0,   132,     0,     0,     0,   133,   485,     0,
     169,     0,     0,     0,     0,     0,     0,     0,   134,   135,
     335,   136,     0,     0,     0,   304,     0,     0,   138,     0,
       0,     0,   139,     0,   305,     0,     0,   307,   308,   309,
     310,   311,   312,   478,   479,   315,   316,   317,   318,   319,
     480,   321,     0,   323,   324,   325,   326,   327,   328,   329,
       0,     0,     0,   481,   482,     0,     0,     0,     0,     0,
       0,   293,   477,     0,   330,   331,   483,   484,   131,     0,
       0,     0,   299,     0,   132,     0,     0,     0,   133,   485,
     486,     0,     0,     0,     0,     0,     0,     0,     0,   134,
     135,   335,   136,     0,     0,     0,   304,     0,     0,   138,
       0,     0,     0,   139,     0,   305,     0,     0,   307,   308,
     309,   310,   311,   312,   478,   479,   315,   316,   317,   318,
     319,   480,   321,     0,   323,   324,   325,   326,   327,   328,
     329,     0,     0,     0,   481,   482,     0,     0,     0,     0,
       0,     0,   293,   477,     0,   330,   331,   483,   484,   131,
       0,     0,     0,   299,     0,   132,     0,     0,     0,   133,
     485,     0,     0,     0,     0,     0,   562,     0,     0,     0,
     134,   135,   335,   136,     0,     0,     0,   304,     0,     0,
     138,     0,     0,     0,   139,     0,   305,     0,     0,   307,
     308,   309,   310,   311,   312,   478,   479,   315,   316,   317,
     318,   319,   480,   321,     0,   323,   324,   325,   326,   327,
     328,   329,     0,     0,     0,   481,   482,     0,     0,     0,
       0,     0,     0,   293,   477,     0,   330,   331,   483,   484,
     131,     0,     0,     0,   299,     0,   132,     0,     0,     0,
     133,   485,     0,   719,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   335,   136,     0,     0,     0,   304,     0,
       0,   138,     0,     0,     0,   139,     0,   305,     0,     0,
     307,   308,   309,   310,   311,   312,   478,   479,   315,   316,
     317,   318,   319,   480,   321,     0,   323,   324,   325,   326,
     327,   328,   329,     0,     0,     0,   481,   482,     0,     0,
       0,     0,     0,     0,   293,   477,     0,   330,   331,   483,
     484,   131,     0,     0,     0,   299,     0,   132,     0,     0,
       0,   133,   485,     0,     0,     0,     0,   528,     0,     0,
       0,     0,   134,   135,   335,   136,     0,     0,     0,   304,
       0,     0,   138,     0,     0,     0,   139,     0,   305,     0,
       0,   307,   308,   309,   310,   311,   312,   478,   479,   315,
     316,   317,   318,   319,   480,   321,     0,   323,   324,   325,
     326,   327,   328,   329,     0,     0,     0,   481,   482,     0,
       0,     0,     0,     0,     0,   293,   477,     0,   330,   331,
     483,   484,   131,     0,     0,     0,   299,     0,   132,     0,
       0,     0,   133,   485,   804,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   135,   335,   136,     0,     0,     0,
     304,     0,     0,   138,     0,     0,     0,   139,     0,   305,
       0,     0,   307,   308,   309,   310,   311,   312,   478,   479,
     315,   316,   317,   318,   319,   480,   321,     0,   323,   324,
     325,   326,   327,   328,   329,     0,     0,     0,   481,   482,
       0,     0,     0,     0,     0,     0,   293,   477,     0,   330,
     331,   483,   484,   131,     0,     0,     0,   299,     0,   132,
       0,     0,     0,   133,   485,     0,     0,     0,     0,     0,
     900,     0,     0,     0,   134,   135,   335,   136,     0,     0,
       0,   304,     0,     0,   138,     0,     0,     0,   139,     0,
     305,     0,     0,   307,   308,   309,   310,   311,   312,   478,
     479,   315,   316,   317,   318,   319,   480,   321,     0,   323,
     324,   325,   326,   327,   328,   329,     0,     0,     0,   481,
     482,     0,     0,     0,     0,     0,     0,   293,   477,     0,
     330,   331,   483,   484,   131,     0,     0,     0,   299,     0,
     132,     0,     0,     0,   133,   485,   913,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   135,   335,   136,     0,
       0,     0,   304,     0,     0,   138,     0,     0,     0,   139,
       0,   305,     0,     0,   307,   308,   309,   310,   311,   312,
     478,   479,   315,   316,   317,   318,   319,   480,   321,     0,
     323,   324,   325,   326,   327,   328,   329,     0,     0,     0,
     481,   482,     0,     0,     0,     0,     0,     0,   293,   477,
       0,   330,   331,   483,   484,   131,     0,     0,     0,   299,
       0,   132,     0,     0,     0,   133,   485,   953,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   335,   136,
       0,     0,     0,   304,     0,     0,   138,     0,     0,     0,
     139,     0,   305,     0,     0,   307,   308,   309,   310,   311,
     312,   478,   479,   315,   316,   317,   318,   319,   480,   321,
       0,   323,   324,   325,   326,   327,   328,   329,     0,     0,
       0,   481,   482,     0,     0,     0,     0,     0,     0,   293,
     477,     0,   330,   331,   483,   484,   131,     0,     0,     0,
     299,     0,   132,     0,     0,     0,   133,   485,   955,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   335,
     136,     0,     0,     0,   304,     0,     0,   138,     0,     0,
       0,   139,     0,   305,     0,     0,   307,   308,   309,   310,
     311,   312,   478,   479,   315,   316,   317,   318,   319,   480,
     321,     0,   323,   324,   325,   326,   327,   328,   329,     0,
       0,     0,   481,   482,     0,     0,     0,     0,     0,     0,
     293,   477,     0,   330,   331,   483,   484,   131,     0,     0,
       0,   299,     0,   132,     0,     0,     0,   133,   485,     0,
       0,     0,     0,     0,   999,     0,     0,     0,   134,   135,
     335,   136,     0,     0,     0,   304,     0,     0,   138,     0,
       0,     0,   139,     0,   305,     0,     0,   307,   308,   309,
     310,   311,   312,   478,   479,   315,   316,   317,   318,   319,
     480,   321,     0,   323,   324,   325,   326,   327,   328,   329,
       0,     0,     0,   481,   482,     0,     0,     0,     0,     0,
       0,   293,   477,     0,   330,   331,   483,   484,   131,     0,
       0,     0,   299,     0,   132,     0,     0,     0,   133,   485,
    1028,     0,     0,     0,     0,     0,     0,     0,     0,   134,
     135,   335,   136,     0,     0,     0,   304,     0,     0,   138,
       0,     0,     0,   139,     0,   305,     0,     0,   307,   308,
     309,   310,   311,   312,   478,   479,   315,   316,   317,   318,
     319,   480,   321,     0,   323,   324,   325,   326,   327,   328,
     329,     0,     0,     0,   481,   482,     0,     0,     0,     0,
       0,     0,   293,   477,     0,   330,   331,   483,   484,   131,
       0,     0,     0,   299,     0,   132,     0,     0,     0,   133,
     485,  1033,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   335,   136,     0,     0,     0,   304,     0,     0,
     138,     0,     0,     0,   139,     0,   305,     0,     0,   307,
     308,   309,   310,   311,   312,   478,   479,   315,   316,   317,
     318,   319,   480,   321,     0,   323,   324,   325,   326,   327,
     328,   329,     0,     0,     0,   481,   482,     0,     0,     0,
       0,     0,     0,   293,   477,     0,   330,   331,   483,   484,
     131,     0,     0,     0,   299,     0,   132,     0,     0,     0,
     133,   485,  1037,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   335,   136,     0,     0,     0,   304,     0,
       0,   138,     0,     0,     0,   139,     0,   305,     0,     0,
     307,   308,   309,   310,   311,   312,   478,   479,   315,   316,
     317,   318,   319,   480,   321,     0,   323,   324,   325,   326,
     327,   328,   329,     0,     0,     0,   481,   482,     0,     0,
       0,     0,     0,     0,   293,   477,     0,   330,   331,   483,
     484,   131,     0,     0,     0,   299,     0,   132,     0,     0,
       0,   133,   485,  1039,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   335,   136,     0,     0,     0,   304,
       0,     0,   138,     0,     0,     0,   139,     0,   305,     0,
       0,   307,   308,   309,   310,   311,   312,   478,   479,   315,
     316,   317,   318,   319,   480,   321,     0,   323,   324,   325,
     326,   327,   328,   329,     0,     0,     0,   481,   482,     0,
       0,     0,     0,     0,     0,   293,   477,     0,   330,   331,
     483,   484,   131,     0,     0,     0,   299,     0,   132,     0,
       0,     0,   133,   485,  1102,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   135,   335,   136,     0,     0,     0,
     304,     0,     0,   138,     0,     0,     0,   139,     0,   305,
       0,     0,   307,   308,   309,   310,   311,   312,   478,   479,
     315,   316,   317,   318,   319,   480,   321,     0,   323,   324,
     325,   326,   327,   328,   329,     0,     0,     0,   481,   482,
       0,     0,     0,     0,     0,     0,   293,   477,     0,   330,
     331,   483,   484,   131,     0,     0,     0,   299,     0,   132,
       0,     0,     0,   133,   485,  1104,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   335,   136,     0,     0,
       0,   304,     0,     0,   138,     0,     0,     0,   139,     0,
     305,     0,     0,   307,   308,   309,   310,   311,   312,   478,
     479,   315,   316,   317,   318,   319,   480,   321,     0,   323,
     324,   325,   326,   327,   328,   329,     0,     0,     0,   481,
     482,     0,     0,     0,     0,     0,     0,   293,   477,     0,
     330,   331,   483,   484,   131,     0,     0,     0,   299,     0,
     132,     0,     0,     0,   133,   485,  1106,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   135,   335,   136,     0,
       0,     0,   304,     0,     0,   138,     0,     0,     0,   139,
       0,   305,     0,     0,   307,   308,   309,   310,   311,   312,
     478,   479,   315,   316,   317,   318,   319,   480,   321,     0,
     323,   324,   325,   326,   327,   328,   329,     0,     0,     0,
     481,   482,     0,     0,     0,     0,     0,     0,   293,   477,
       0,   330,   331,   483,   484,   131,     0,     0,     0,   299,
       0,   132,     0,     0,     0,   133,   485,  1143,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   335,   136,
       0,     0,     0,   304,     0,     0,   138,     0,     0,     0,
     139,     0,   305,     0,     0,   307,   308,   309,   310,   311,
     312,   478,   479,   315,   316,   317,   318,   319,   480,   321,
       0,   323,   324,   325,   326,   327,   328,   329,     0,     0,
       0,   481,   482,     0,     0,     0,     0,     0,     0,   293,
     477,     0,   330,   331,   483,   484,   131,     0,     0,     0,
     299,     0,   132,     0,     0,     0,   133,   485,  1145,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   335,
     136,     0,     0,     0,   304,     0,     0,   138,     0,     0,
       0,   139,     0,   305,     0,     0,   307,   308,   309,   310,
     311,   312,   478,   479,   315,   316,   317,   318,   319,   480,
     321,     0,   323,   324,   325,   326,   327,   328,   329,     0,
       0,     0,   481,   482,     0,     0,     0,     0,     0,     0,
     293,   477,     0,   330,   331,   483,   484,   131,     0,     0,
       0,   299,     0,   132,     0,     0,     0,   133,   485,     0,
       0,     0,     0,     0,  1169,     0,     0,     0,   134,   135,
     335,   136,     0,     0,     0,   304,     0,     0,   138,     0,
       0,     0,   139,     0,   305,     0,     0,   307,   308,   309,
     310,   311,   312,   478,   479,   315,   316,   317,   318,   319,
     480,   321,     0,   323,   324,   325,   326,   327,   328,   329,
       0,     0,     0,   481,   482,     0,     0,     0,     0,     0,
       0,   293,   477,     0,   330,   331,   483,   484,   131,     0,
       0,     0,   299,     0,   132,     0,     0,     0,   133,   485,
       0,     0,     0,     0,     0,  1189,     0,     0,     0,   134,
     135,   335,   136,     0,     0,     0,   304,     0,     0,   138,
       0,     0,     0,   139,     0,   305,     0,     0,   307,   308,
     309,   310,   311,   312,   478,   479,   315,   316,   317,   318,
     319,   480,   321,     0,   323,   324,   325,   326,   327,   328,
     329,     0,     0,     0,   481,   482,     0,     0,     0,     0,
       0,     0,   293,   477,     0,   330,   331,   483,   484,   131,
       0,     0,     0,   299,     0,   132,     0,     0,     0,   133,
     485,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   335,   136,     0,     0,     0,   304,     0,     0,
     138,     0,     0,     0,   139,     0,   305,     0,     0,   307,
     308,   309,   310,   311,   312,   478,   479,   315,   316,   317,
     318,   319,   480,   321,     0,   323,   324,   325,   326,   327,
     328,   329,     0,     0,   293,   481,   482,     0,     0,     0,
       0,   131,     0,     0,     0,   299,     0,   132,     0,     0,
       0,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   485,   134,   135,     0,   136,     0,     0,     0,   304,
       0,     0,   138,   335,     0,     0,   139,     0,   305,     0,
       0,   307,   308,   309,   310,   311,   312,   478,   479,   315,
     316,   317,   318,   319,   480,   321,     0,   323,   324,   325,
     326,   327,   328,   329,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,     0,     0,   131,     0,   330,   331,
     299,     0,   132,     0,     0,     0,   133,     0,     0,     0,
       0,     0,     0,   332,   992,     0,     0,   134,   135,     0,
     136,     0,     0,     0,   304,   335,     0,   138,     0,     0,
       0,   139,     0,   305,     0,     0,   307,   308,   309,   310,
     311,   312,   478,   479,   315,   316,   317,   318,   319,   480,
     321,     0,   323,   324,   325,   326,   327,   328,   329,     0,
       0,     0,     0,     0,   293,     0,     0,     0,     0,     0,
       0,   131,     0,   330,   331,   299,     0,   132,     0,     0,
       0,   133,     0,     0,     0,     0,     0,     0,   332,  1066,
       0,     0,   134,   135,     0,   136,     0,     0,     0,   304,
     335,     0,   138,     0,     0,     0,   139,     0,   305,     0,
       0,   307,   308,   309,   310,   311,   312,   478,   479,   315,
     316,   317,   318,   319,   480,   321,     0,   323,   324,   325,
     326,   327,   328,   329,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,     0,     0,   131,     0,   330,   331,
     299,     0,   132,     0,     0,     0,   133,     0,     0,     0,
       0,     0,     0,   332,  1069,     0,     0,   134,   135,     0,
     136,     0,     0,     0,   304,   335,     0,   138,     0,     0,
       0,   139,     0,   305,     0,     0,   307,   308,   309,   310,
     311,   312,   478,   479,   315,   316,   317,   318,   319,   480,
     321,     0,   323,   324,   325,   326,   327,   328,   329,     0,
       0,     0,     0,     0,   293,     0,     0,     0,     0,     0,
       0,   131,     0,   330,   331,   299,     0,   132,     0,     0,
       0,   133,     0,     0,     0,     0,     0,     0,   332,  1114,
       0,     0,   134,   135,     0,   136,     0,     0,     0,   304,
     335,     0,   138,     0,     0,     0,   139,     0,   305,     0,
       0,   307,   308,   309,   310,   311,   312,   478,   479,   315,
     316,   317,   318,   319,   480,   321,     0,   323,   324,   325,
     326,   327,   328,   329,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,     0,     0,   131,     0,   330,   331,
     299,     0,   132,     0,     0,     0,   133,     0,     0,     0,
       0,     0,     0,   332,  1185,     0,     0,   134,   135,     0,
     136,     0,     0,     0,   304,   335,     0,   138,     0,     0,
       0,   139,     0,   305,     0,     0,   307,   308,   309,   310,
     311,   312,   478,   479,   315,   316,   317,   318,   319,   480,
     321,     0,   323,   324,   325,   326,   327,   328,   329,     0,
       0,     0,     0,     0,   293,     0,     0,     0,     0,     0,
       0,   131,     0,   330,   331,   299,     0,   132,     0,     0,
       0,   133,     0,     0,     0,     0,     0,     0,   332,  1195,
       0,     0,   134,   135,     0,   136,     0,     0,     0,   304,
     335,     0,   138,     0,     0,     0,   139,     0,   305,     0,
       0,   307,   308,   309,   310,   311,   312,   478,   479,   315,
     316,   317,   318,   319,   480,   321,     0,   323,   324,   325,
     326,   327,   328,   329,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,     0,     0,   131,     0,   330,   331,
     299,     0,   132,     0,     0,     0,   133,     0,     0,     0,
       0,     0,     0,   332,  1198,     0,     0,   134,   135,     0,
     136,     0,     0,     0,   304,   335,     0,   138,     0,     0,
       0,   139,     0,   305,     0,     0,   307,   308,   309,   310,
     311,   312,   478,   479,   315,   316,   317,   318,   319,   480,
     321,     0,   323,   324,   325,   326,   327,   328,   329,     0,
       0,     0,     0,     0,   293,     0,     0,     0,     0,     0,
       0,   131,     0,   330,   331,   299,     0,   132,     0,     0,
       0,   133,     0,     0,     0,     0,     0,     0,   332,  1208,
       0,     0,   134,   135,     0,   136,     0,     0,     0,   304,
     335,     0,   138,     0,     0,     0,   139,     0,   305,     0,
       0,   307,   308,   309,   310,   311,   312,   478,   479,   315,
     316,   317,   318,   319,   480,   321,     0,   323,   324,   325,
     326,   327,   328,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   330,   331,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   332,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   335
};

static const yytype_int16 yycheck[] =
{
       2,    20,   169,     5,   404,     7,   256,     9,   539,    11,
     548,    13,   166,   167,    16,   548,   336,   404,   719,   399,
     172,   283,    80,    81,   399,   856,   564,    27,   205,   201,
     714,    86,   984,    79,   207,   208,   330,   331,   288,   289,
      42,    99,   173,   349,   776,    80,   180,    49,    74,     6,
      20,   396,   182,    55,    56,    57,    58,  1004,     6,    17,
     405,   116,    64,   421,    99,    40,   117,    69,   106,    71,
      72,    73,    98,   111,    76,    77,    78,    79,    87,    88,
      89,     6,    84,    85,    86,   216,   775,     0,    58,   778,
      96,   100,    87,    95,    57,   101,   142,   143,   153,   113,
      64,   159,   447,   105,   106,   100,   108,   107,   215,   240,
     217,   583,  1076,   168,   116,   587,   118,    20,   173,    20,
     330,   331,  1074,   142,   231,    50,   172,   182,   600,  1076,
      33,   265,  1079,    32,   396,   137,   266,   107,    79,    79,
     142,   143,   117,     9,    43,    86,    86,   149,   150,   113,
     270,   107,   983,   172,    82,    58,   114,   537,   278,   117,
     117,   216,    28,   221,   222,  1129,    58,   169,   107,   117,
     172,   173,    20,   857,   176,   116,   116,   564,   180,  1126,
     189,   190,   349,   111,   193,   240,   221,   481,   482,   483,
     484,     9,   117,   219,   725,   927,   727,   199,   200,   201,
     202,   203,   143,   143,   107,  1157,   107,   107,   548,   211,
      28,   266,    96,   113,   216,   107,   225,   226,   227,   353,
       9,    94,   106,   105,   230,   763,   626,   109,   169,   169,
     225,     9,   173,   173,   614,   237,   616,   404,   240,    28,
     929,   616,   108,    58,   117,    80,    81,    82,   303,   421,
      28,   253,   254,   255,    47,   432,   258,   434,   260,   107,
     394,   917,   435,   265,    99,   395,   611,     6,  1077,   531,
     272,   481,   482,   483,   484,   216,   216,   635,    17,   637,
     282,   639,   107,   641,    20,   986,   111,    64,   594,   291,
     108,   293,   107,   445,    87,    88,   298,    33,   300,   240,
     240,    19,     6,    42,    97,    98,  1079,   100,   107,    18,
    1119,    50,     9,    17,   659,   446,    41,   336,   320,   108,
      63,   105,    58,    48,   159,   160,     9,   162,   330,   331,
     108,    28,    18,    51,   336,   442,   113,     6,    42,    25,
     395,   282,    78,    94,    62,    28,    50,   349,    17,     6,
      78,   353,    61,  1126,   564,  1164,   828,   829,   112,   113,
      17,   833,   469,   470,    81,    33,   117,    79,   111,    94,
     113,   107,    89,    42,    86,    61,   763,   105,   117,   149,
      94,    50,    33,   107,   102,    42,   221,   222,   223,   113,
      58,   446,   394,    50,   113,   453,   189,   399,   407,   445,
     534,   403,   404,   117,   116,    63,   176,    58,   349,   349,
      78,   108,   532,   117,   112,   107,   710,   711,   712,   421,
     740,   113,   215,    63,    63,   108,   445,   594,   112,  1085,
     106,   143,   225,   226,   436,   111,   112,   439,   231,   107,
     111,   821,    96,   445,   446,   111,   580,    94,   117,   284,
     459,   460,   106,   111,   463,   113,   107,    33,   399,   626,
     117,   173,   116,   404,   404,   585,   112,    77,    78,   589,
     117,   111,   111,   113,   113,    85,    86,   654,   108,   481,
     482,   483,   484,   693,   694,   695,   696,   697,   698,   699,
     700,   701,   702,   703,  1025,   705,   706,   707,   708,   709,
     710,   711,   712,   109,   216,   446,   446,   113,   118,    77,
     116,   566,   105,    53,    54,    55,    56,  1173,  1174,   538,
     113,   109,    62,   116,    90,    91,   105,   295,   240,  1185,
     109,   105,   534,   301,   302,   537,   538,   539,  1194,  1195,
     107,  1197,  1198,   109,  1082,  1201,   548,   113,  1204,  1082,
     116,  1207,  1208,   763,   322,   106,     5,  1088,  1214,   107,
     900,   855,   564,   903,   332,   113,   568,   569,   108,   111,
     677,    53,    54,    55,    56,   117,   112,   111,   580,   581,
      62,   583,   584,   117,   107,   587,   588,    46,    47,   105,
     592,    50,   594,    42,   112,   113,   537,   113,   600,   601,
     116,   995,   109,   723,   962,   999,   113,   548,    53,    54,
      55,    56,   614,   111,   616,   113,   169,    62,   453,   454,
      79,   456,   111,   564,   626,   109,   108,   747,    77,   113,
     105,   751,   116,   635,   109,   637,    85,   639,   111,   641,
      99,   100,   101,   108,   646,   855,   856,   649,   650,   103,
     104,   103,   104,   594,   594,   995,   112,   109,   667,   999,
     590,   113,   108,   108,   116,   111,   459,   108,   103,   104,
     111,   105,   108,   614,   109,   616,   469,  1071,   113,   113,
     110,   116,   116,   142,   143,   626,   626,   841,   842,   843,
     844,   693,   694,   695,   696,   697,   698,   699,   700,   701,
     702,   703,   704,   705,   706,   707,   708,   709,   710,   711,
     712,   713,   111,    90,    91,    94,    95,   485,   112,   774,
      99,   740,   972,   725,   974,   727,   976,   729,   978,  1129,
     103,  1071,   109,   735,   446,    82,   113,   109,   740,   116,
     117,   113,  1082,    90,    91,   298,    53,    54,    55,    56,
     199,   200,    27,   202,   203,    62,    53,    54,    55,    56,
     114,   763,   109,   117,  1164,    62,   113,   535,   113,   116,
     890,   116,   109,   983,   984,  1169,   113,   897,   105,   116,
     117,    53,    54,    55,    56,   553,   788,   555,   556,   909,
      62,   105,   912,  1187,   735,  1189,   349,   100,   101,   102,
     108,   108,   570,   111,   112,   254,  1200,   106,    79,   117,
     105,   108,   111,   112,   582,    86,   109,   105,   586,   821,
     113,   823,   763,   753,    95,   105,   828,   829,   663,  1169,
     963,   833,   113,   966,   602,   968,   108,   970,   606,    53,
      54,    55,    56,   103,   104,   116,   109,  1187,    62,  1189,
     113,   404,    13,   855,   856,   109,   169,    82,    19,   113,
    1200,   117,    23,   918,  1074,    90,    91,   111,   112,   113,
     990,   142,   143,    34,    35,   117,    37,    82,   149,   121,
     821,   330,   331,    44,   109,    90,    91,    48,   113,   747,
     892,   116,   117,   751,   108,   105,   826,   827,   169,   116,
     113,   172,   173,   116,   109,   176,    84,   113,   113,    87,
     116,   116,   680,   103,   104,   917,    79,    53,    54,    55,
      56,   689,   924,    86,   692,   105,    62,   107,   114,   109,
     932,   117,    95,   935,   936,    90,    91,   114,   940,   941,
     117,   113,    13,   113,   116,   216,   116,  1157,    19,    90,
      91,   719,    23,   116,   749,   404,   117,   752,   105,   111,
     962,   113,  1129,    34,    35,   111,    37,   113,   111,   240,
      41,   739,   108,    44,   111,   112,   113,    48,   746,   142,
     143,   983,   984,   924,   144,   298,   149,   755,    90,    91,
     992,   151,   111,   112,   113,   548,   108,  1164,   111,   112,
     113,   931,   111,  1022,   113,   105,   169,   937,   111,   172,
     173,   282,   942,   176,   174,   945,    82,   111,   112,   113,
    1022,   109,   293,  1025,    90,    91,   111,   112,   581,   169,
      92,    93,   481,   482,   483,   484,   349,  1092,   111,     3,
     113,   594,   105,   109,   107,   105,   117,   113,    82,    83,
     116,   117,    16,   216,   111,   112,   113,    21,   700,   701,
     702,   703,    26,  1065,  1066,   336,  1068,  1069,   111,   112,
     113,   111,  1074,   626,    38,  1130,    40,   240,   349,   107,
    1082,    45,   106,  1085,  1086,   112,  1088,  1089,   111,   112,
     113,   404,   836,   837,   838,    59,   705,   706,   707,   105,
     111,   107,   113,   111,   111,   113,   113,   111,  1110,   113,
      88,  1113,  1114,    97,   274,   564,  1046,  1047,  1048,   282,
     107,    98,   109,   111,   112,    96,    13,  1129,   399,   111,
     112,    96,    19,   404,   902,   109,    23,   113,   906,   111,
     112,  1082,   111,   112,   111,   112,   112,    34,    35,   111,
      37,   919,   106,   117,  1156,  1157,   112,    44,   298,   111,
     112,    48,  1164,   111,   112,  1095,   111,  1097,   439,   698,
     699,  1173,  1174,   336,   445,   446,   169,   708,   709,   105,
     340,    51,   111,  1185,   344,    42,   349,   111,  1129,  1129,
     111,   111,  1194,  1195,   106,  1197,  1198,    42,   111,  1201,
     649,   650,  1204,   106,   112,  1207,  1208,   105,  1085,   349,
     106,   108,  1214,   106,   485,    17,    82,   112,   986,   106,
     111,   113,   106,  1164,  1164,   106,   106,   105,   111,   106,
     117,   105,    43,    32,   105,   548,   399,   106,   110,    42,
     400,   404,   105,   110,   693,   694,   695,   696,   697,   698,
     699,   700,   701,   702,   703,   105,   705,   706,   707,   708,
     709,   710,   711,   712,   404,    42,   537,   538,   581,   106,
     105,   110,   106,   106,   106,    82,   439,   548,   108,   108,
     111,   594,   445,   446,   112,   108,   110,   447,   106,   111,
     105,   107,   113,   564,   106,    24,  1173,  1174,   111,    24,
     106,   111,   106,   111,   105,   298,   106,   105,  1185,   106,
     105,    97,   106,   626,   763,  1083,  1084,  1194,  1195,   106,
    1197,  1198,   485,   594,  1201,   106,   105,  1204,   488,   105,
    1207,  1208,   106,   106,   106,   113,   111,  1214,   106,   106,
     111,   111,   111,   614,   106,   616,   111,   900,   106,   106,
     903,   111,   106,   112,    82,   626,   349,    83,    82,    82,
       3,   111,  1130,  1131,   917,   106,   106,   106,   106,   111,
     106,   106,    24,    16,   537,   538,   536,   111,    21,   932,
     111,   111,    25,    26,   111,   548,    29,   106,   106,   549,
     550,   111,   106,   687,    25,    38,    39,    40,   238,    42,
     261,   564,    45,  1171,  1172,   116,   855,   856,   548,   824,
     736,   404,   118,   573,   169,   440,    59,   987,  1158,   904,
    1090,   763,   690,    66,   550,    18,   485,    76,   823,   273,
     735,   594,   118,   704,   260,   143,   439,   597,  1076,   992,
    1130,   581,   995,   980,   446,  1082,   999,  1157,     3,   778,
    1022,   614,   763,   616,   594,   693,    11,   694,   697,   695,
      -1,    16,   696,   626,   735,   625,    21,    -1,   111,   740,
      25,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,   298,    -1,    38,    39,    40,   626,    42,    -1,    -1,
      45,    -1,   763,    -1,    -1,    -1,    -1,    -1,    -1,   659,
      -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      65,    66,  1065,  1066,    -1,  1068,  1069,    -1,  1071,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   686,    -1,    -1,  1082,
      -1,    -1,  1085,  1086,   983,   984,    -1,    -1,    -1,    -1,
      -1,   704,    -1,   298,    -1,    -1,    -1,    -1,    -1,    -1,
     821,    -1,    -1,    -1,    -1,   548,   111,  1110,    -1,    -1,
    1113,  1114,    -1,    -1,   724,    -1,    -1,    -1,    -1,   169,
      -1,   731,   735,    -1,   734,    -1,  1129,   740,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   900,   581,   749,
     903,    -1,   752,    -1,   349,    -1,    -1,    -1,    -1,    -1,
     763,   594,    -1,  1156,   917,    -1,   766,    -1,    -1,    -1,
      -1,  1164,    -1,    -1,    -1,    -1,  1169,    -1,    -1,   932,
    1173,  1174,    -1,    -1,    -1,  1074,    -1,    -1,    -1,    -1,
      -1,    -1,  1185,   626,  1187,    -1,  1189,    -1,    -1,    -1,
      -1,  1194,  1195,    -1,  1197,  1198,    -1,  1200,  1201,   404,
      -1,  1204,    -1,    -1,  1207,  1208,    -1,    -1,   821,    -1,
      -1,  1214,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    16,   992,
      -1,    19,   995,    21,    -1,    23,   999,    -1,    26,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    34,    35,   298,    37,
      38,    39,    40,    41,    42,    -1,    44,    45,  1157,    -1,
      48,    -1,   872,    -1,   874,    -1,   169,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,   891,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   349,
      -1,    -1,  1065,  1066,    -1,  1068,  1069,    -1,  1071,    -1,
     900,    -1,    -1,   903,   581,    -1,    -1,    -1,    -1,  1082,
      -1,    -1,  1085,  1086,    -1,    -1,    -1,   917,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   932,   548,     3,    -1,    -1,  1110,    -1,    -1,
    1113,  1114,    -1,    -1,   404,    -1,    -1,    16,    -1,    -1,
      -1,  1082,    21,    -1,    -1,    -1,  1129,    26,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,    38,
      39,    40,    -1,    42,    -1,    -1,    45,    -1,    -1,   594,
      -1,    -1,    -1,  1156,    -1,   298,    -1,    -1,    -1,    -1,
      59,  1164,   992,    -1,    -1,   995,  1169,    66,  1129,   999,
    1173,  1174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   626,  1185,    -1,  1187,    -1,  1189,    -1,    -1,    -1,
      -1,  1194,  1195,    -1,  1197,  1198,    -1,  1200,  1201,    -1,
      -1,  1204,    -1,  1164,  1207,  1208,   349,    -1,    -1,    -1,
      -1,  1214,   111,   169,    -1,    -1,    -1,   900,    -1,    -1,
     903,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1082,
      -1,    -1,    -1,    -1,   917,  1065,  1066,    -1,  1068,  1069,
      -1,  1071,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   932,
      -1,    -1,  1082,    -1,    -1,  1085,  1086,    -1,   548,    -1,
      -1,   404,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1129,    -1,    -1,    -1,
    1110,    -1,    -1,  1113,  1114,    -1,    -1,    -1,    -1,    -1,
       3,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1129,
      13,    -1,    -1,    16,   594,    -1,    19,    -1,    21,   992,
      23,  1164,   995,    26,    -1,    -1,   999,    -1,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,  1156,    40,    -1,    -1,
      -1,    44,    45,    -1,  1164,    48,   626,    -1,    -1,  1169,
      -1,    -1,   298,  1173,  1174,    -1,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1185,    -1,  1187,    -1,  1189,
      -1,    -1,    -1,    -1,  1194,  1195,    -1,  1197,  1198,    -1,
    1200,  1201,    -1,    -1,  1204,    -1,    -1,  1207,  1208,    -1,
      -1,    -1,  1065,  1066,  1214,  1068,  1069,    -1,  1071,    -1,
      -1,    -1,    -1,   349,    -1,    -1,    -1,    -1,    -1,  1082,
       3,    -1,  1085,  1086,   117,   548,    -1,    -1,    -1,    -1,
     917,    -1,    -1,    16,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    25,    26,    -1,   932,    29,  1110,    -1,    -1,
    1113,  1114,    -1,    -1,    -1,    38,    39,    40,   581,    42,
      -1,    -1,    45,    -1,    -1,    -1,  1129,    -1,   404,    -1,
      -1,   594,    -1,    -1,    57,   900,    59,    -1,   903,    -1,
      -1,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   917,  1156,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1164,    -1,   626,    -1,   992,  1169,   932,    -1,    -1,
    1173,  1174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1185,    -1,  1187,    -1,  1189,    -1,   111,     3,
      -1,  1194,  1195,    -1,  1197,  1198,    -1,  1200,  1201,    -1,
      -1,  1204,    16,    -1,  1207,  1208,    -1,    21,    -1,    -1,
      -1,  1214,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,   992,    42,    -1,
     995,    45,    -1,    -1,   999,    -1,    -1,    -1,  1065,  1066,
      -1,  1068,  1069,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,  1085,  1086,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1110,    -1,    -1,  1113,  1114,    -1,    -1,
     900,    -1,    -1,   903,    -1,    -1,    -1,    -1,    -1,    -1,
    1065,  1066,    -1,  1068,  1069,   581,  1071,   917,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1082,   594,    -1,
    1085,  1086,   932,    -1,    -1,    -1,    -1,    -1,    -1,  1156,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1110,  1173,  1174,  1113,  1114,
     626,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1185,    -1,
      -1,    -1,    -1,    -1,  1129,    -1,    -1,  1194,  1195,    -1,
    1197,  1198,    -1,    -1,  1201,    -1,    -1,  1204,    -1,    -1,
    1207,  1208,   992,    -1,    -1,   995,    -1,  1214,    -1,   999,
      -1,  1156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1164,
      -1,    -1,    -1,    -1,  1169,    -1,    -1,    -1,  1173,  1174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1185,    -1,  1187,    -1,  1189,    -1,    -1,    -1,    -1,  1194,
    1195,    -1,  1197,  1198,    -1,  1200,  1201,   900,    -1,  1204,
     903,    -1,  1207,  1208,    -1,    -1,    -1,    -1,    -1,  1214,
      -1,    -1,    -1,    -1,   917,  1065,  1066,    -1,  1068,  1069,
      -1,  1071,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   932,
      -1,    -1,  1082,    -1,    -1,  1085,  1086,    -1,    -1,   330,
     331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1110,    -1,    -1,  1113,  1114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   992,
      -1,    -1,   995,    -1,    -1,    -1,   999,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1156,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1164,    -1,    -1,    -1,    -1,  1169,
      -1,    -1,    -1,  1173,  1174,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1185,    -1,  1187,    -1,  1189,
      -1,    -1,    -1,    -1,  1194,  1195,    -1,  1197,  1198,    -1,
    1200,  1201,    -1,    -1,  1204,    -1,    -1,  1207,  1208,    -1,
      -1,    -1,  1065,  1066,  1214,  1068,  1069,    -1,  1071,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1082,
      -1,    -1,  1085,  1086,   900,    -1,    -1,   903,    -1,    -1,
     481,   482,   483,   484,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   917,    -1,    -1,    -1,    -1,    -1,  1110,    -1,    -1,
    1113,  1114,    -1,    -1,    -1,    -1,   932,    -1,    87,    88,
      89,    90,    -1,    -1,    -1,    -1,  1129,    -1,    -1,    -1,
      -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,  1156,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1164,    -1,    -1,    -1,    -1,  1169,    -1,    -1,    -1,
    1173,  1174,    -1,   564,    -1,    -1,   992,    -1,    -1,   995,
      -1,    -1,  1185,   999,  1187,    -1,  1189,    -1,    -1,    -1,
      -1,  1194,  1195,    -1,  1197,  1198,    -1,  1200,  1201,    -1,
      -1,  1204,    -1,    -1,  1207,  1208,    -1,    -1,    -1,    -1,
      -1,  1214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,   191,    -1,   193,   194,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1065,
    1066,    -1,  1068,  1069,    -1,  1071,   225,   226,   227,   228,
      -1,    -1,    -1,    -1,    -1,    -1,  1082,    -1,    -1,  1085,
    1086,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1110,    -1,    -1,  1113,  1114,    -1,
      -1,    -1,   693,   694,   695,   696,   697,   698,   699,   700,
     701,   702,   703,  1129,   705,   706,   707,   708,   709,   710,
     711,   712,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
    1156,    -1,    95,    -1,    -1,    -1,    -1,    -1,  1164,    -1,
      -1,    -1,    -1,  1169,    -1,    -1,    -1,  1173,  1174,    -1,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,  1185,
      -1,  1187,   763,  1189,    -1,    -1,    -1,    -1,  1194,  1195,
      -1,  1197,  1198,    -1,  1200,  1201,    -1,    -1,  1204,   142,
     143,  1207,  1208,    -1,    -1,    -1,   149,    -1,  1214,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,   172,
     173,    -1,    -1,   176,    13,    -1,    -1,    16,    -1,    -1,
      19,    -1,    21,    -1,    23,    -1,    -1,    26,   407,   408,
      29,   410,    -1,    -1,   413,    34,    35,    -1,    37,    38,
      39,    40,    -1,    42,    -1,    44,    45,    -1,    -1,    48,
      -1,    -1,    -1,   216,   855,   856,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,
     459,   460,   461,    -1,   463,   464,    -1,   466,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    17,    18,    19,    -1,    21,    22,    23,
      -1,    -1,    26,    -1,    28,    29,    30,    -1,   117,   282,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      44,    45,    -1,    -1,    48,    -1,    50,    51,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    -1,
      -1,    -1,   983,   984,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,     3,   107,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    13,   117,    -1,    16,    -1,    -1,    19,    -1,
      21,    -1,    23,    -1,    -1,    26,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,   399,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,   630,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,  1074,    -1,    -1,   439,    -1,    -1,    -1,
      -1,    -1,   445,   446,    -1,    -1,    -1,    -1,   667,   668,
      -1,   670,    -1,    -1,   673,    -1,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      12,    13,    14,    -1,    16,    17,    18,    19,    -1,    21,
      22,    23,    -1,    -1,    26,    -1,  1157,    29,    30,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    44,    45,   537,   538,    48,    -1,    50,    51,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,    -1,   107,   108,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,
      -1,   614,    -1,   616,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    12,    13,    14,   848,
      16,    17,    18,    19,    -1,    21,    22,    23,    -1,    -1,
      26,    -1,    -1,    29,    30,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    44,    45,
      -1,    -1,    48,    -1,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,   913,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,   117,   735,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    12,    13,    14,    -1,    16,    17,
      18,    19,    -1,    21,    22,    23,    -1,    -1,    26,    -1,
      -1,    29,    30,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    44,    45,    -1,    -1,
      48,    -1,    50,    51,  1003,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   821,    -1,
      -1,    -1,    90,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,   107,
     108,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,   117,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    19,    -1,    21,    22,
      23,    -1,    -1,    26,    -1,    -1,    29,    30,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    44,    45,    -1,    -1,    48,    -1,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    -1,
      -1,    -1,    -1,     3,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,   105,    13,   107,    -1,    16,    17,   111,    19,
      -1,    21,    -1,    23,   117,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    -1,
      40,    41,    -1,    -1,    44,    45,    -1,    -1,    48,    -1,
      50,    -1,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,     6,    -1,    -1,
      90,    91,    -1,    -1,    13,    -1,    -1,    16,    17,    -1,
      19,    -1,    21,    -1,    23,   105,    -1,    26,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    34,    35,   117,    37,    38,
      -1,    40,    41,    -1,    -1,    44,    45,    -1,    -1,    48,
      -1,    50,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,     6,    -1,
      -1,    90,    91,    -1,    -1,    13,    -1,    -1,    16,    17,
      -1,    19,    -1,    21,    -1,    23,   105,    -1,    26,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    34,    35,   117,    37,
      38,    -1,    40,    41,    -1,    -1,    44,    45,    -1,    -1,
      48,    -1,    50,    -1,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    16,    -1,    -1,    19,    -1,    21,    -1,    23,
      -1,    -1,    26,    -1,    -1,    29,    -1,   105,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,   117,
      44,    45,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    13,    -1,    -1,    16,    -1,    -1,    19,
      -1,    21,    -1,    23,    78,    -1,    26,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    -1,    44,    45,    -1,    -1,    48,    -1,
      -1,    -1,    -1,   107,   108,    -1,    -1,   111,    -1,    59,
      -1,    -1,    -1,   117,     3,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    16,    78,    -1,
      19,    -1,    21,    -1,    23,    -1,    -1,    26,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    -1,    44,    45,   107,   108,    48,
      -1,   111,    -1,    -1,    -1,    -1,    -1,   117,     3,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    66,    13,    -1,
      -1,    16,    -1,    -1,    19,    -1,    21,    -1,    23,    78,
      -1,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    -1,    44,
      45,    -1,    -1,    48,    -1,    -1,     3,    -1,   107,   108,
      -1,    -1,   111,    -1,    59,    -1,    13,    -1,   117,    16,
      -1,    66,    19,    -1,    21,    -1,    23,    -1,    -1,    26,
      -1,    -1,    29,    78,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    -1,    44,    45,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    59,   108,    -1,    -1,   111,    -1,    -1,    66,
      13,    -1,   117,    16,    -1,    -1,    19,    -1,    21,    -1,
      23,    78,    -1,    26,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      -1,    44,    45,    -1,    -1,    48,    -1,    -1,     3,    -1,
     107,    -1,    -1,    -1,   111,    -1,    59,    -1,    13,    -1,
     117,    16,    -1,    66,    19,    -1,    21,    -1,    23,    -1,
      -1,    26,    -1,    -1,    -1,    78,    -1,    -1,     3,    34,
      35,    -1,    37,    38,    -1,    40,    -1,    -1,    13,    44,
      45,    16,    -1,    48,    19,    -1,    21,    -1,    23,    -1,
      -1,    26,    -1,    -1,    59,   108,    -1,    -1,   111,    34,
      35,    -1,    37,    38,   117,    40,    -1,    -1,    -1,    44,
      45,    -1,     3,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    59,    16,    -1,    -1,    19,    -1,
      21,    -1,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    34,    35,    -1,    37,    38,    -1,    40,
      -1,    -1,   117,    44,    45,    -1,     3,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    59,    16,
      -1,   106,    19,    -1,    21,    -1,    23,    -1,    -1,    26,
      -1,    -1,   117,    -1,    -1,    -1,     3,    34,    35,    -1,
      37,    38,    -1,    40,    -1,    -1,    13,    44,    45,    16,
      -1,    48,    19,    -1,    21,    -1,    23,    -1,    -1,    26,
      -1,    -1,    59,    -1,    -1,   106,    -1,    34,    35,    -1,
      37,    38,    -1,    40,    -1,    -1,   117,    44,    45,    -1,
       3,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    59,    16,    -1,    -1,    19,    -1,    21,    -1,
      23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    34,    35,    -1,    37,    38,    -1,    40,    -1,    -1,
     117,    44,    45,    -1,     3,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    59,    16,    -1,   106,
      19,    -1,    21,    -1,    23,    -1,    -1,    26,    -1,    -1,
     117,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      -1,    40,    -1,    -1,    -1,    44,    45,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,     4,     5,     6,     7,     8,
      -1,    10,    -1,    12,    13,    14,    -1,    -1,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    36,    37,    -1,
      -1,    -1,    41,    -1,    -1,    44,    -1,    -1,   117,    48,
      -1,    50,    51,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,     6,     7,     8,   105,    10,   107,    12,
      13,    14,   111,    -1,    17,    18,    19,    -1,   117,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    34,    35,    36,    37,    -1,    -1,    -1,    41,    -1,
      -1,    44,    -1,    -1,    -1,    48,    -1,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    90,    91,    17,
      -1,    19,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,   107,    -1,    34,    35,   111,    37,
      -1,    -1,    -1,    41,   117,    -1,    44,    -1,    -1,    -1,
      48,    -1,    50,    -1,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,     6,
       7,    -1,    90,    91,    92,    93,    13,    -1,    -1,    -1,
      17,    -1,    19,    -1,    -1,    22,    23,   105,    -1,   107,
     108,    -1,    -1,    -1,   112,    -1,    -1,    34,    35,   117,
      37,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,    -1,    90,    91,    92,    93,    13,    -1,    -1,
      -1,    17,    -1,    19,    -1,    -1,    -1,    23,   105,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
     117,    37,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,
      -1,    -1,    48,    -1,    50,    -1,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,     6,     7,    -1,    90,    91,    92,    93,    13,    -1,
      -1,    -1,    17,    -1,    19,    -1,    -1,    -1,    23,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,   117,    37,    -1,    -1,    -1,    41,    -1,    -1,    44,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,    -1,    90,    91,    92,    93,    13,
      -1,    -1,    -1,    17,    -1,    19,    -1,    -1,    -1,    23,
     105,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,
      34,    35,   117,    37,    -1,    -1,    -1,    41,    -1,    -1,
      44,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,    -1,    90,    91,    92,    93,
      13,    -1,    -1,    -1,    17,    -1,    19,    -1,    -1,    -1,
      23,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,   117,    37,    -1,    -1,    -1,    41,    -1,
      -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,    -1,    90,    91,    92,
      93,    13,    -1,    -1,    -1,    17,    -1,    19,    -1,    -1,
      -1,    23,   105,    -1,    -1,    -1,    -1,   110,    -1,    -1,
      -1,    -1,    34,    35,   117,    37,    -1,    -1,    -1,    41,
      -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,    -1,    90,    91,
      92,    93,    13,    -1,    -1,    -1,    17,    -1,    19,    -1,
      -1,    -1,    23,   105,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,   117,    37,    -1,    -1,    -1,
      41,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,
      -1,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,    90,
      91,    92,    93,    13,    -1,    -1,    -1,    17,    -1,    19,
      -1,    -1,    -1,    23,   105,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    34,    35,   117,    37,    -1,    -1,
      -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,
      50,    -1,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,
      90,    91,    92,    93,    13,    -1,    -1,    -1,    17,    -1,
      19,    -1,    -1,    -1,    23,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,   117,    37,    -1,
      -1,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,    90,    91,    92,    93,    13,    -1,    -1,    -1,    17,
      -1,    19,    -1,    -1,    -1,    23,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,   117,    37,
      -1,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,
      48,    -1,    50,    -1,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,     6,
       7,    -1,    90,    91,    92,    93,    13,    -1,    -1,    -1,
      17,    -1,    19,    -1,    -1,    -1,    23,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,   117,
      37,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,    -1,    90,    91,    92,    93,    13,    -1,    -1,
      -1,    17,    -1,    19,    -1,    -1,    -1,    23,   105,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    34,    35,
     117,    37,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,
      -1,    -1,    48,    -1,    50,    -1,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,     6,     7,    -1,    90,    91,    92,    93,    13,    -1,
      -1,    -1,    17,    -1,    19,    -1,    -1,    -1,    23,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,   117,    37,    -1,    -1,    -1,    41,    -1,    -1,    44,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,    -1,    90,    91,    92,    93,    13,
      -1,    -1,    -1,    17,    -1,    19,    -1,    -1,    -1,    23,
     105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,   117,    37,    -1,    -1,    -1,    41,    -1,    -1,
      44,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,    -1,    90,    91,    92,    93,
      13,    -1,    -1,    -1,    17,    -1,    19,    -1,    -1,    -1,
      23,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,   117,    37,    -1,    -1,    -1,    41,    -1,
      -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,    -1,    90,    91,    92,
      93,    13,    -1,    -1,    -1,    17,    -1,    19,    -1,    -1,
      -1,    23,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,   117,    37,    -1,    -1,    -1,    41,
      -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,    -1,    90,    91,
      92,    93,    13,    -1,    -1,    -1,    17,    -1,    19,    -1,
      -1,    -1,    23,   105,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,   117,    37,    -1,    -1,    -1,
      41,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,
      -1,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,    90,
      91,    92,    93,    13,    -1,    -1,    -1,    17,    -1,    19,
      -1,    -1,    -1,    23,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,   117,    37,    -1,    -1,
      -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,
      50,    -1,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,
      90,    91,    92,    93,    13,    -1,    -1,    -1,    17,    -1,
      19,    -1,    -1,    -1,    23,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,   117,    37,    -1,
      -1,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,    90,    91,    92,    93,    13,    -1,    -1,    -1,    17,
      -1,    19,    -1,    -1,    -1,    23,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,   117,    37,
      -1,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,
      48,    -1,    50,    -1,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,     6,
       7,    -1,    90,    91,    92,    93,    13,    -1,    -1,    -1,
      17,    -1,    19,    -1,    -1,    -1,    23,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,   117,
      37,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,    -1,    90,    91,    92,    93,    13,    -1,    -1,
      -1,    17,    -1,    19,    -1,    -1,    -1,    23,   105,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    34,    35,
     117,    37,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,
      -1,    -1,    48,    -1,    50,    -1,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,     6,     7,    -1,    90,    91,    92,    93,    13,    -1,
      -1,    -1,    17,    -1,    19,    -1,    -1,    -1,    23,   105,
      -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    34,
      35,   117,    37,    -1,    -1,    -1,    41,    -1,    -1,    44,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,    -1,    90,    91,    92,    93,    13,
      -1,    -1,    -1,    17,    -1,    19,    -1,    -1,    -1,    23,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,   117,    37,    -1,    -1,    -1,    41,    -1,    -1,
      44,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,     6,    79,    80,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    -1,    17,    -1,    19,    -1,    -1,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    34,    35,    -1,    37,    -1,    -1,    -1,    41,
      -1,    -1,    44,   117,    -1,    -1,    48,    -1,    50,    -1,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    90,    91,
      17,    -1,    19,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,    -1,    -1,    34,    35,    -1,
      37,    -1,    -1,    -1,    41,   117,    -1,    44,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    90,    91,    17,    -1,    19,    -1,    -1,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,    34,    35,    -1,    37,    -1,    -1,    -1,    41,
     117,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    90,    91,
      17,    -1,    19,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,    -1,    -1,    34,    35,    -1,
      37,    -1,    -1,    -1,    41,   117,    -1,    44,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    90,    91,    17,    -1,    19,    -1,    -1,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,    34,    35,    -1,    37,    -1,    -1,    -1,    41,
     117,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    90,    91,
      17,    -1,    19,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,    -1,    -1,    34,    35,    -1,
      37,    -1,    -1,    -1,    41,   117,    -1,    44,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    90,    91,    17,    -1,    19,    -1,    -1,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,    34,    35,    -1,    37,    -1,    -1,    -1,    41,
     117,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    90,    91,
      17,    -1,    19,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,    -1,    -1,    34,    35,    -1,
      37,    -1,    -1,    -1,    41,   117,    -1,    44,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    90,    91,    17,    -1,    19,    -1,    -1,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,    34,    35,    -1,    37,    -1,    -1,    -1,    41,
     117,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,    11,    16,    21,    25,    26,    29,    38,    39,
      40,    42,    45,    57,    59,    65,    66,   111,   125,   126,
     134,   169,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   197,   198,   234,   241,   249,   250,   251,
     117,   170,    40,   170,   183,   170,   170,   170,   170,    57,
     170,   126,   189,   195,   194,    29,    39,    42,    66,   251,
       0,   125,   126,   111,   113,   127,   170,   183,   111,   113,
     111,   113,    20,   107,   202,   235,    33,    58,    78,   107,
     199,   252,   253,   254,    33,    58,   107,   199,   201,   202,
     204,   205,   107,   127,   170,   105,   199,   242,   170,   170,
     170,   170,   126,   170,   111,   113,   113,   111,   113,    94,
     170,    94,   170,   170,   203,   108,   111,   112,   144,   145,
     170,   236,   239,   240,   235,   203,   170,   183,   170,   179,
     200,    13,    19,    23,    34,    35,    37,    41,    44,    48,
     108,   111,   134,   149,   170,   175,   176,   177,   197,   199,
     213,   214,   215,   217,   218,   249,   255,   256,   257,   252,
     253,   254,   253,   254,   254,   170,   170,   183,    40,   107,
     108,   111,   134,   139,   170,   197,   199,   206,   207,   208,
     213,   216,   217,   228,   229,   230,   231,   249,   260,   201,
     202,   204,   205,   202,   204,   205,   204,   205,   205,    53,
      54,    55,    56,    62,   108,   128,   196,   107,   107,   127,
     106,   213,   243,   244,   245,   242,   107,   202,   246,   202,
     235,   199,   252,   253,   254,   199,   201,   202,   204,   205,
     199,   242,   170,    94,    94,   111,   111,   112,   137,   138,
     139,   108,   240,   145,   239,   105,   205,   237,   238,   108,
     240,   112,   108,   113,   112,   113,   132,   133,    33,   180,
     112,   135,   136,    77,   170,   213,   217,   108,   255,   109,
     120,   121,   213,   218,   170,   209,   210,   211,   120,   111,
     227,   260,   105,   219,   253,   254,   254,   254,   132,   132,
     260,     4,     5,     6,     7,     8,    10,    12,    14,    17,
      18,    22,    30,    36,    41,    50,    51,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      90,    91,   105,   108,   111,   117,   134,   170,   171,   172,
     183,   184,   197,   213,   214,   215,   250,   260,   261,   262,
     263,   264,   265,   266,   267,   269,   270,   271,   273,   274,
     275,   276,   278,   279,   285,   287,   288,   290,   295,   297,
     298,   299,   300,   301,   302,   303,   309,   313,   314,   315,
     316,   317,   319,   320,   321,   323,   324,   328,   329,   344,
     345,   347,   348,   349,   213,   217,   231,   108,   206,   105,
     170,   209,   227,    27,   107,   224,   232,   202,   204,   205,
     204,   205,   205,   204,   205,   205,   205,   170,   183,   170,
     183,   129,   169,   170,   182,   170,   183,   170,   183,   108,
     196,   108,   128,   108,   128,   107,   114,   170,   106,   112,
     146,   147,   202,   246,   108,   134,   148,   170,   206,   247,
     248,   246,   235,   252,   253,   254,   253,   254,   254,   201,
     202,   204,   205,   202,   204,   205,   204,   205,   205,   242,
     202,   246,   111,   111,   170,   138,   108,     7,    59,    60,
      66,    79,    80,    92,    93,   105,   106,   170,   214,   215,
     316,   321,   322,   326,   327,   328,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   205,   205,   108,
     170,   183,   133,   170,   179,   136,   209,   227,   110,   121,
     170,   219,   120,   111,   112,   103,   106,   123,   134,   213,
     220,   221,   222,   223,   224,   254,   111,   170,   105,   170,
     174,   214,   318,   105,   326,   105,   105,   170,   267,   111,
     170,   326,   111,   326,   105,   260,   310,   113,   113,   116,
     105,   326,   170,   183,   319,   320,   343,   343,   326,    60,
     266,    82,   109,   113,   116,   120,   109,   113,   116,   120,
     105,   113,   116,   108,   152,   262,   111,   170,   209,   111,
     113,   116,   109,   103,   104,   173,   330,    90,    91,   209,
     227,   224,   232,   106,   123,   221,   105,   111,   170,   225,
     226,    17,    50,   108,   170,   183,   233,   261,   313,   232,
     204,   205,   205,   205,   205,    63,   111,    63,   111,    63,
     111,    63,   111,   169,   182,   111,   113,   111,   111,    64,
      64,   108,   108,   108,   128,   170,   244,   147,   246,   170,
     108,   247,   232,   253,   254,   254,   254,   202,   204,   205,
     204,   205,   205,   204,   205,   205,   205,   202,   246,   246,
     105,   343,   343,   343,   343,   174,   214,   215,   106,   112,
     166,   167,    81,    89,    88,    97,    98,    96,    84,    87,
      77,    78,    85,    86,   118,   100,   101,   102,    92,    93,
      94,    95,    99,    96,   122,   181,   111,   224,   209,   107,
     212,   258,   326,   120,   106,   213,   221,   213,    17,   114,
     124,   170,   211,   112,   106,   112,   140,   141,   111,   111,
     134,   170,   265,   274,   292,   294,   109,   120,   127,   168,
     325,   120,   168,   105,   326,    82,   111,   326,   326,    51,
     111,   111,   111,   164,   165,   170,   183,   265,   311,   312,
     313,   319,   352,    32,    43,   304,   305,   308,   260,    42,
     170,   170,   326,   111,   106,   209,   267,   326,     6,    17,
      42,    50,   170,   317,   170,   113,   326,    17,    42,    50,
     170,   317,   170,   113,   106,   322,    42,     6,   170,   262,
     170,   317,   170,   326,   326,   111,   232,   106,   221,   106,
     106,   123,   221,   112,   142,   143,   105,   105,   113,   113,
     108,   261,   108,   113,   205,   182,   182,   182,   182,   111,
     170,   170,   183,   170,   183,   108,   232,   254,   204,   205,
     205,   205,   205,   246,   326,   106,   106,   122,   326,   167,
     326,   333,   334,   335,   336,   337,   338,   338,   340,   340,
     340,   340,   170,   178,   214,   215,   341,   341,   341,   342,
     342,   343,   343,   343,   170,   181,   108,   112,   212,   259,
     120,   106,   114,   211,   170,    17,   113,   120,   222,   141,
     111,   326,    82,   112,   159,   160,   111,   326,   258,   120,
     325,   258,   120,   106,   322,   106,   326,   106,   106,   105,
     165,   312,   106,   111,   105,   260,   308,   161,   305,   304,
     308,   105,   106,   110,   170,   113,   116,   105,    42,   110,
     113,   116,   105,    42,   106,   105,   110,   106,   106,   221,
     106,   226,   143,   106,   322,   106,   322,    50,    50,   108,
      50,   111,   112,   130,   131,   111,   130,   111,   130,   111,
     130,   111,   132,   111,   132,   111,   132,   111,   132,   205,
     106,   343,   346,   106,    82,   108,   112,   150,   151,   108,
     120,   170,   106,   293,   294,   111,   326,   274,   160,   111,
     326,   110,   205,   106,   107,   280,   111,     5,    10,    51,
     170,   267,   268,   269,   272,   277,   286,   289,   291,   296,
     260,   326,   134,   170,   306,   307,   305,   308,   106,   322,
     267,   170,   170,   106,   322,   170,   170,   106,   322,   106,
     322,   106,   111,   106,   111,   106,   105,   105,   105,   182,
     111,   131,   111,   111,   111,   111,   111,   111,   111,   280,
     346,   331,   212,   151,   267,   106,   106,   293,   106,   106,
     293,   111,   205,     9,    28,   108,   154,   155,   156,   281,
     282,   283,   105,   105,   105,    82,    24,   106,   307,    97,
     162,   163,   106,   211,   106,   105,   106,   105,   106,   106,
     111,   111,   106,   322,   106,   322,   106,   322,   267,   267,
     106,   267,   267,   106,   106,   293,   284,   331,   108,   155,
     282,   283,   108,   156,   283,   108,   153,   281,   283,    82,
      83,   111,   265,   292,   326,   326,   268,   267,   111,   211,
     170,   163,   260,   106,   322,   106,   322,   111,   106,   111,
     106,   111,   106,   267,   267,   267,   106,   112,   157,   158,
     108,    82,   108,   281,   155,   261,   260,   301,   326,   111,
     326,    82,   111,   106,   106,   106,   106,   111,   111,   111,
     267,   284,   158,   261,   111,   106,   293,   111,   326,   111,
     326,   268,   268,   268,   106,   106,   293,   106,   106,   293,
     111,    24,   268,   268,   106,   268,   268,   106,   106,   293,
     268,   268,   268,   268,   106,   268
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   119,   120,   120,   121,   122,   122,   123,   124,   125,
     125,   126,   126,   127,   127,   128,   128,   129,   129,   130,
     130,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     136,   137,   137,   138,   139,   139,   140,   140,   141,   142,
     142,   143,   144,   144,   145,   146,   146,   147,   148,   148,
     149,   149,   150,   150,   151,   152,   152,   153,   153,   154,
     154,   155,   155,   156,   157,   157,   158,   159,   159,   160,
     161,   161,   162,   162,   163,   164,   164,   165,   166,   166,
     167,   168,   168,   169,   169,   169,   169,   169,   169,   169,
     169,   170,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   172,   172,
     172,   172,   172,   172,   172,   173,   173,   174,   175,   175,
     176,   176,   176,   176,   176,   177,   177,   178,   178,   179,
     179,   180,   180,   181,   182,   182,   183,   183,   184,   185,
     185,   186,   186,   186,   186,   186,   186,   186,   186,   187,
     187,   188,   188,   189,   189,   189,   189,   190,   190,   191,
     192,   192,   193,   193,   194,   194,   194,   195,   195,   195,
     195,   195,   195,   195,   195,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   197,
     197,   197,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   199,   200,   200,   201,   202,   203,
     203,   204,   204,   204,   204,   205,   205,   206,   206,   206,
     206,   207,   207,   207,   207,   207,   208,   208,   209,   209,
     210,   210,   211,   211,   212,   212,   213,   213,   213,   214,
     214,   215,   215,   216,   216,   217,   217,   217,   217,   218,
     218,   219,   219,   219,   219,   219,   219,   219,   219,   220,
     220,   221,   221,   222,   222,   222,   223,   223,   224,   225,
     225,   226,   227,   227,   228,   229,   230,   230,   230,   230,
     231,   231,   231,   231,   231,   231,   231,   231,   232,   232,
     232,   232,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   234,   234,   234,   234,   235,   235,   235,   235,
     235,   235,   236,   236,   237,   238,   239,   239,   239,   239,
     239,   239,   240,   240,   241,   241,   241,   241,   241,   241,
     241,   241,   242,   242,   243,   243,   244,   244,   245,   246,
     246,   247,   247,   248,   248,   249,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   251,   252,   253,   253,   254,   254,   255,   255,
     255,   255,   255,   256,   256,   257,   257,   258,   258,   258,
     259,   259,   260,   260,   261,   261,   262,   262,   262,   263,
     263,   264,   265,   265,   266,   266,   267,   267,   267,   267,
     267,   267,   268,   268,   268,   268,   268,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     270,   271,   272,   273,   274,   274,   274,   274,   274,   274,
     274,   275,   276,   277,   278,   278,   279,   280,   280,   280,
     280,   280,   280,   281,   281,   281,   282,   282,   283,   283,
     283,   284,   285,   286,   287,   288,   288,   289,   289,   290,
     290,   290,   290,   290,   290,   290,   290,   291,   291,   291,
     291,   291,   291,   291,   291,   292,   292,   293,   294,   294,
     295,   296,   297,   297,   298,   299,   299,   300,   300,   301,
     302,   303,   303,   303,   303,   304,   304,   305,   306,   306,
     307,   307,   308,   309,   309,   309,   309,   310,   311,   311,
     312,   312,   313,   313,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   315,   315,   315,   315,   315,
     315,   316,   316,   316,   316,   317,   317,   317,   317,   318,
     318,   319,   319,   319,   319,   320,   320,   320,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   322,   322,   323,   323,   323,   323,   323,   323,
     323,   323,   324,   324,   324,   324,   324,   324,   325,   326,
     327,   327,   328,   329,   329,   329,   329,   330,   331,   331,
     332,   332,   333,   333,   334,   334,   335,   335,   336,   336,
     337,   337,   337,   338,   338,   338,   338,   338,   338,   339,
     340,   340,   340,   340,   341,   341,   341,   342,   342,   342,
     342,   343,   343,   343,   343,   343,   344,   345,   346,   346,
     346,   346,   346,   347,   347,   347,   347,   347,   348,   349,
     350,   350,   350,   351,   352,   352,   352
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     2,     2,     2,     1,
       2,     1,     2,     2,     3,     1,     2,     1,     2,     1,
       2,     2,     1,     2,     2,     2,     1,     2,     1,     2,
       2,     1,     2,     2,     1,     2,     1,     2,     2,     1,
       2,     2,     1,     2,     2,     1,     2,     2,     1,     2,
       1,     2,     1,     2,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     2,     1,     2,     2,     1,     2,     2,
       1,     2,     1,     2,     2,     1,     2,     2,     1,     2,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     2,     1,     3,     3,     3,     1,     1,
       1,     0,     1,     1,     2,     1,     2,     2,     3,     1,
       2,     3,     4,     1,     1,     1,     1,     3,     3,     4,
       5,     5,     6,     6,     1,     1,     1,     4,     5,     5,
       6,     5,     6,     6,     7,     3,     4,     3,     5,     6,
       3,     5,     6,     3,     5,     6,     3,     5,     6,     3,
       5,     6,     3,     5,     6,     5,     6,     5,     6,     1,
       1,     1,     3,     4,     4,     5,     4,     5,     5,     6,
       4,     5,     5,     6,     5,     6,     6,     7,     4,     5,
       5,     6,     5,     6,     6,     7,     5,     6,     6,     7,
       6,     7,     7,     8,     3,     1,     2,     2,     2,     1,
       2,     2,     2,     3,     3,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     1,     3,
       1,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     3,     2,     3,     3,     4,     2,
       2,     2,     3,     3,     4,     3,     4,     4,     5,     2,
       3,     1,     2,     2,     3,     1,     3,     4,     2,     1,
       2,     1,     1,     1,     1,     2,     2,     3,     3,     4,
       3,     4,     4,     5,     4,     5,     5,     6,     2,     3,
       3,     4,     4,     5,     4,     5,     6,     7,     6,     7,
       6,     7,     3,     4,     4,     5,     2,     3,     3,     4,
       3,     4,     1,     1,     2,     3,     1,     2,     2,     2,
       3,     3,     1,     2,     4,     5,     5,     6,     5,     6,
       6,     7,     2,     3,     1,     2,     2,     1,     3,     2,
       3,     1,     1,     2,     3,     1,     3,     4,     4,     5,
       4,     5,     5,     6,     4,     5,     5,     6,     5,     6,
       6,     7,     1,     2,     2,     3,     2,     3,     1,     1,
       1,     1,     1,     3,     4,     2,     3,     2,     3,     3,
       1,     2,     2,     3,     1,     2,     1,     1,     1,     1,
       1,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     5,     7,     7,     3,     5,     5,     3,     4,     2,
       3,     3,     4,     4,     3,     3,     3,     4,     2,     3,
       1,     1,     5,     5,     7,     1,     1,     1,     1,     6,
       7,     7,     8,     7,     8,     8,     9,     6,     7,     7,
       8,     7,     8,     8,     9,     1,     1,     1,     1,     2,
       7,     7,     2,     3,     3,     2,     3,     2,     3,     3,
       5,     3,     3,     4,     1,     1,     2,     5,     2,     3,
       1,     2,     2,     3,     4,     4,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       1,     1,     1,     1,     1,     3,     3,     4,     4,     3,
       3,     1,     3,     3,     3,     4,     5,     5,     6,     1,
       2,     3,     3,     5,     5,     4,     4,     4,     4,     3,
       5,     6,     5,     6,     5,     6,     5,     6,     7,     8,
       7,     8,     1,     2,     3,     3,     3,     3,     3,     5,
       5,     3,     3,     4,     3,     4,     4,     4,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     5,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     1,     2,     2,     1,     2,     2,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       4,     4,     5,     5,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* OMPSB: PSB  */
#line 395 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 3968 "parser2.tab.c"
    break;

  case 3: /* OMPSB: OMPSB PSB  */
#line 396 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 3974 "parser2.tab.c"
    break;

  case 4: /* PSB: LSB RSB  */
#line 398 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 3980 "parser2.tab.c"
    break;

  case 5: /* OMAdditionalBound: AdditionalBound  */
#line 401 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 3986 "parser2.tab.c"
    break;

  case 6: /* OMAdditionalBound: OMAdditionalBound AdditionalBound  */
#line 402 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 3992 "parser2.tab.c"
    break;

  case 7: /* ReceiverParameterComma: ReceiverParameter COMMA  */
#line 405 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 3998 "parser2.tab.c"
    break;

  case 8: /* IdentifierDot: Identifier DOT  */
#line 407 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4004 "parser2.tab.c"
    break;

  case 9: /* OMImportDeclaration: ImportDeclaration  */
#line 409 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4010 "parser2.tab.c"
    break;

  case 10: /* OMImportDeclaration: OMImportDeclaration ImportDeclaration  */
#line 410 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4016 "parser2.tab.c"
    break;

  case 11: /* OMTopLevelClassOrInterfaceDeclaration: TopLevelClassOrInterfaceDeclaration  */
#line 412 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4022 "parser2.tab.c"
    break;

  case 12: /* OMTopLevelClassOrInterfaceDeclaration: OMTopLevelClassOrInterfaceDeclaration TopLevelClassOrInterfaceDeclaration  */
#line 413 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4028 "parser2.tab.c"
    break;

  case 13: /* OMDotIdentifier: DOT Identifier  */
#line 415 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4034 "parser2.tab.c"
    break;

  case 14: /* OMDotIdentifier: OMDotIdentifier DOT Identifier  */
#line 416 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-2].typeinfo)->tac;}
#line 4040 "parser2.tab.c"
    break;

  case 15: /* OMModuleDirective: ModuleDirective  */
#line 418 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4046 "parser2.tab.c"
    break;

  case 16: /* OMModuleDirective: OMModuleDirective ModuleDirective  */
#line 419 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4052 "parser2.tab.c"
    break;

  case 17: /* OMRequiresModifier: Modifieropt  */
#line 421 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4058 "parser2.tab.c"
    break;

  case 18: /* OMRequiresModifier: OMRequiresModifier Modifieropt  */
#line 422 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4064 "parser2.tab.c"
    break;

  case 19: /* OMCommaModuleName: CommaModuleName  */
#line 424 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4070 "parser2.tab.c"
    break;

  case 20: /* OMCommaModuleName: OMCommaModuleName CommaModuleName  */
#line 425 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4076 "parser2.tab.c"
    break;

  case 21: /* CommaModuleName: COMMA ModuleName  */
#line 427 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4082 "parser2.tab.c"
    break;

  case 22: /* OMCommaTypeName: CommaTypeName  */
#line 429 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4088 "parser2.tab.c"
    break;

  case 23: /* OMCommaTypeName: OMCommaTypeName CommaTypeName  */
#line 430 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4094 "parser2.tab.c"
    break;

  case 24: /* CommaTypeName: COMMA Identifier  */
#line 432 "parser2.y"
                                                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4100 "parser2.tab.c"
    break;

  case 25: /* CommaTypeName: COMMA ExpressionName  */
#line 433 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4106 "parser2.tab.c"
    break;

  case 26: /* OMClassModifier: InterfaceModifier  */
#line 435 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4112 "parser2.tab.c"
    break;

  case 27: /* OMClassModifier: OMClassModifier InterfaceModifier  */
#line 436 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4118 "parser2.tab.c"
    break;

  case 28: /* OMCommaTypeParameter: CommaTypeParameter  */
#line 438 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4124 "parser2.tab.c"
    break;

  case 29: /* OMCommaTypeParameter: OMCommaTypeParameter CommaTypeParameter  */
#line 439 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4130 "parser2.tab.c"
    break;

  case 30: /* CommaTypeParameter: COMMA TypeParameter  */
#line 441 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4136 "parser2.tab.c"
    break;

  case 31: /* OMCommaInterfaceType: CommaInterfaceType  */
#line 443 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4142 "parser2.tab.c"
    break;

  case 32: /* OMCommaInterfaceType: OMCommaInterfaceType CommaInterfaceType  */
#line 444 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4148 "parser2.tab.c"
    break;

  case 33: /* CommaInterfaceType: COMMA Identifier  */
#line 446 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4154 "parser2.tab.c"
    break;

  case 34: /* OMClassBodyDeclaration: ClassBodyDeclaration  */
#line 448 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4160 "parser2.tab.c"
    break;

  case 35: /* OMClassBodyDeclaration: OMClassBodyDeclaration ClassBodyDeclaration  */
#line 449 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4166 "parser2.tab.c"
    break;

  case 36: /* OMCommaFormalParameter: CommaFormalParameter  */
#line 451 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4172 "parser2.tab.c"
    break;

  case 37: /* OMCommaFormalParameter: OMCommaFormalParameter CommaFormalParameter  */
#line 452 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4178 "parser2.tab.c"
    break;

  case 38: /* CommaFormalParameter: COMMA FormalParameter  */
#line 454 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4184 "parser2.tab.c"
    break;

  case 39: /* OMCommaExceptionType: CommaExceptionType  */
#line 456 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4190 "parser2.tab.c"
    break;

  case 40: /* OMCommaExceptionType: OMCommaExceptionType CommaExceptionType  */
#line 457 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4196 "parser2.tab.c"
    break;

  case 41: /* CommaExceptionType: COMMA ExceptionType  */
#line 459 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4202 "parser2.tab.c"
    break;

  case 42: /* OMCommaEnumConstant: CommaEnumConstant  */
#line 461 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4208 "parser2.tab.c"
    break;

  case 43: /* OMCommaEnumConstant: OMCommaEnumConstant CommaEnumConstant  */
#line 462 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4214 "parser2.tab.c"
    break;

  case 44: /* CommaEnumConstant: EnumConstant COMMA  */
#line 464 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 4220 "parser2.tab.c"
    break;

  case 45: /* OMCommaRecordComponent: CommaRecordComponent  */
#line 467 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4226 "parser2.tab.c"
    break;

  case 46: /* OMCommaRecordComponent: OMCommaRecordComponent CommaRecordComponent  */
#line 468 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4232 "parser2.tab.c"
    break;

  case 47: /* CommaRecordComponent: COMMA RecordComponent  */
#line 470 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4238 "parser2.tab.c"
    break;

  case 48: /* OMRecordBodyDeclaration: RecordBodyDeclaration  */
#line 473 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4244 "parser2.tab.c"
    break;

  case 49: /* OMRecordBodyDeclaration: OMRecordBodyDeclaration RecordBodyDeclaration  */
#line 474 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4250 "parser2.tab.c"
    break;

  case 50: /* OMInterfaceMemberDeclaration: InterfaceMemberDeclaration  */
#line 476 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4256 "parser2.tab.c"
    break;

  case 51: /* OMInterfaceMemberDeclaration: OMInterfaceMemberDeclaration InterfaceMemberDeclaration  */
#line 477 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4262 "parser2.tab.c"
    break;

  case 52: /* OMCommaVariableInitializer: CommaVariableInitializer  */
#line 480 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4268 "parser2.tab.c"
    break;

  case 53: /* OMCommaVariableInitializer: OMCommaVariableInitializer CommaVariableInitializer  */
#line 481 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4274 "parser2.tab.c"
    break;

  case 54: /* CommaVariableInitializer: COMMA VariableInitializer  */
#line 483 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4280 "parser2.tab.c"
    break;

  case 55: /* OMBlockStatement: BlockStatement  */
#line 485 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 4286 "parser2.tab.c"
    break;

  case 56: /* OMBlockStatement: OMBlockStatement BlockStatement  */
#line 486 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4292 "parser2.tab.c"
    break;

  case 57: /* OMSwitchRule: SwitchRule  */
#line 488 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4298 "parser2.tab.c"
    break;

  case 58: /* OMSwitchRule: OMSwitchRule SwitchRule  */
#line 489 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4304 "parser2.tab.c"
    break;

  case 60: /* OMSwitchBlockStatementGroup: OMSwitchBlockStatementGroup SwitchBlockStatementGroup  */
#line 492 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4310 "parser2.tab.c"
    break;

  case 61: /* OMSwitchLabelColon: SwitchLabelColon  */
#line 494 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4316 "parser2.tab.c"
    break;

  case 62: /* OMSwitchLabelColon: OMSwitchLabelColon SwitchLabelColon  */
#line 495 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4322 "parser2.tab.c"
    break;

  case 63: /* SwitchLabelColon: SwitchLabel COLON  */
#line 497 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 4328 "parser2.tab.c"
    break;

  case 64: /* OMCommaCaseConstant: CommaCaseConstant  */
#line 499 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4334 "parser2.tab.c"
    break;

  case 65: /* OMCommaCaseConstant: OMCommaCaseConstant CommaCaseConstant  */
#line 500 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4340 "parser2.tab.c"
    break;

  case 66: /* CommaCaseConstant: COMMA CaseConstant  */
#line 502 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4346 "parser2.tab.c"
    break;

  case 67: /* OMCommaStatementExpression: CommaStatementExpression  */
#line 504 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4352 "parser2.tab.c"
    break;

  case 68: /* OMCommaStatementExpression: OMCommaStatementExpression CommaStatementExpression  */
#line 505 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4358 "parser2.tab.c"
    break;

  case 69: /* CommaStatementExpression: COMMA StatementExpression  */
#line 507 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4364 "parser2.tab.c"
    break;

  case 70: /* OMCatchClause: CatchClause  */
#line 509 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4370 "parser2.tab.c"
    break;

  case 71: /* OMCatchClause: OMCatchClause CatchClause  */
#line 510 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4376 "parser2.tab.c"
    break;

  case 72: /* OMOrClassType: OrClassType  */
#line 512 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4382 "parser2.tab.c"
    break;

  case 73: /* OMOrClassType: OMOrClassType OrClassType  */
#line 513 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4388 "parser2.tab.c"
    break;

  case 74: /* OrClassType: BITOR Identifier  */
#line 515 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4394 "parser2.tab.c"
    break;

  case 75: /* OMSemicolonResource: SemicolonResource  */
#line 517 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4400 "parser2.tab.c"
    break;

  case 76: /* OMSemicolonResource: OMSemicolonResource SemicolonResource  */
#line 518 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4406 "parser2.tab.c"
    break;

  case 77: /* SemicolonResource: Resource SEMICOLON  */
#line 520 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 4412 "parser2.tab.c"
    break;

  case 78: /* OMCommaExpression: CommaExpression  */
#line 522 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4418 "parser2.tab.c"
    break;

  case 79: /* OMCommaExpression: OMCommaExpression CommaExpression  */
#line 523 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4424 "parser2.tab.c"
    break;

  case 80: /* CommaExpression: COMMA Expression  */
#line 525 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4430 "parser2.tab.c"
    break;

  case 81: /* OMDimExpr: DimExpr  */
#line 527 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4436 "parser2.tab.c"
    break;

  case 82: /* OMDimExpr: OMDimExpr DimExpr  */
#line 528 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4442 "parser2.tab.c"
    break;

  case 83: /* Modifieropt: PUBLIC  */
#line 530 "parser2.y"
                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4448 "parser2.tab.c"
    break;

  case 84: /* Modifieropt: PROTECTED  */
#line 531 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4454 "parser2.tab.c"
    break;

  case 85: /* Modifieropt: PRIVATE  */
#line 532 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4460 "parser2.tab.c"
    break;

  case 86: /* Modifieropt: ABSTRACT  */
#line 533 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4466 "parser2.tab.c"
    break;

  case 87: /* Modifieropt: STATIC  */
#line 534 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4472 "parser2.tab.c"
    break;

  case 88: /* Modifieropt: SEALED  */
#line 535 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4478 "parser2.tab.c"
    break;

  case 89: /* Modifieropt: STRICTFP  */
#line 536 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4484 "parser2.tab.c"
    break;

  case 90: /* Modifieropt: FINAL  */
#line 537 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4490 "parser2.tab.c"
    break;

  case 91: /* Identifier: IDENTIFIERWK  */
#line 539 "parser2.y"
                                                                                                {(yyval.str)=(yyvsp[0].str);}
#line 4496 "parser2.tab.c"
    break;

  case 92: /* UnqualifiedMethodIdentifier: IDENTIFIERWK  */
#line 541 "parser2.y"
                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4502 "parser2.tab.c"
    break;

  case 93: /* UnqualifiedMethodIdentifier: EXPORTS  */
#line 542 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4508 "parser2.tab.c"
    break;

  case 94: /* UnqualifiedMethodIdentifier: OPENS  */
#line 543 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4514 "parser2.tab.c"
    break;

  case 95: /* UnqualifiedMethodIdentifier: REQUIRES  */
#line 544 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4520 "parser2.tab.c"
    break;

  case 96: /* UnqualifiedMethodIdentifier: USES  */
#line 545 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4526 "parser2.tab.c"
    break;

  case 97: /* UnqualifiedMethodIdentifier: MODULE  */
#line 546 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4532 "parser2.tab.c"
    break;

  case 98: /* UnqualifiedMethodIdentifier: PERMITS  */
#line 547 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4538 "parser2.tab.c"
    break;

  case 99: /* UnqualifiedMethodIdentifier: SEALED  */
#line 548 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4544 "parser2.tab.c"
    break;

  case 100: /* UnqualifiedMethodIdentifier: VAR  */
#line 549 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4550 "parser2.tab.c"
    break;

  case 101: /* UnqualifiedMethodIdentifier: NONSEALED  */
#line 550 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4556 "parser2.tab.c"
    break;

  case 102: /* UnqualifiedMethodIdentifier: PROVIDES  */
#line 551 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4562 "parser2.tab.c"
    break;

  case 103: /* UnqualifiedMethodIdentifier: TO  */
#line 552 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4568 "parser2.tab.c"
    break;

  case 104: /* UnqualifiedMethodIdentifier: WITH  */
#line 553 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4574 "parser2.tab.c"
    break;

  case 105: /* UnqualifiedMethodIdentifier: OPEN  */
#line 554 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4580 "parser2.tab.c"
    break;

  case 106: /* UnqualifiedMethodIdentifier: RECORD  */
#line 555 "parser2.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4586 "parser2.tab.c"
    break;

  case 107: /* UnqualifiedMethodIdentifier: TRANSITIVE  */
#line 556 "parser2.y"
                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4592 "parser2.tab.c"
    break;

  case 108: /* Literal: INTEGERLITERAL  */
#line 558 "parser2.y"
                                                                {string x=(yyvsp[0].str);int p=stoi(x);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->littype="int";(yyval.typeinfo)->valfloat=p;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+" = "+x;(yyval.typeinfo)->tac={z};}
#line 4598 "parser2.tab.c"
    break;

  case 109: /* Literal: FLOATINGPOINTLITERAL  */
#line 559 "parser2.y"
                                                                {string x=(yyvsp[0].str);float p=stof(x);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->littype="float";(yyval.typeinfo)->valfloat=p;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+" = "+x;(yyval.typeinfo)->tac={z};}
#line 4604 "parser2.tab.c"
    break;

  case 110: /* Literal: BOOLEANLITERAL  */
#line 560 "parser2.y"
                                                                        {string x=(yyvsp[0].str);;(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->littype="bool";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+" = "+x;(yyval.typeinfo)->tac={z};}
#line 4610 "parser2.tab.c"
    break;

  case 111: /* Literal: NULLLITERAL  */
#line 561 "parser2.y"
                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->littype="null";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+" = "+x;(yyval.typeinfo)->tac={z};}
#line 4616 "parser2.tab.c"
    break;

  case 112: /* Literal: CHARACTERLITERAL  */
#line 562 "parser2.y"
                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->littype="char";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+"="+x;(yyval.typeinfo)->tac={z};}
#line 4622 "parser2.tab.c"
    break;

  case 113: /* Literal: STRING  */
#line 563 "parser2.y"
                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->littype="string";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+" = "+x;(yyval.typeinfo)->tac={z};}
#line 4628 "parser2.tab.c"
    break;

  case 114: /* Literal: TEXTBLOCKS  */
#line 564 "parser2.y"
                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->littype="textblock";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+" = "+x;(yyval.typeinfo)->tac={z};}
#line 4634 "parser2.tab.c"
    break;

  case 115: /* ASSIGNMENTOPERATOR: NEWASSIGNMENTOPERATOR  */
#line 566 "parser2.y"
                                                                {(yyval.str)=(yyvsp[0].str);}
#line 4640 "parser2.tab.c"
    break;

  case 116: /* ASSIGNMENTOPERATOR: EQUAL  */
#line 567 "parser2.y"
                                                                                                {(yyval.str)=(yyvsp[0].str);}
#line 4646 "parser2.tab.c"
    break;

  case 117: /* PrimitiveType: UnannPrimitiveType  */
#line 569 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4652 "parser2.tab.c"
    break;

  case 118: /* NumericType: IntegralType  */
#line 571 "parser2.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4658 "parser2.tab.c"
    break;

  case 119: /* NumericType: FloatingPointType  */
#line 572 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4664 "parser2.tab.c"
    break;

  case 120: /* IntegralType: BYTE  */
#line 574 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4670 "parser2.tab.c"
    break;

  case 121: /* IntegralType: SHORT  */
#line 575 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4676 "parser2.tab.c"
    break;

  case 122: /* IntegralType: INT  */
#line 576 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4682 "parser2.tab.c"
    break;

  case 123: /* IntegralType: LONG  */
#line 577 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4688 "parser2.tab.c"
    break;

  case 124: /* IntegralType: CHAR  */
#line 578 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4694 "parser2.tab.c"
    break;

  case 125: /* FloatingPointType: FLOAT  */
#line 580 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4700 "parser2.tab.c"
    break;

  case 126: /* FloatingPointType: DOUBLE  */
#line 581 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4706 "parser2.tab.c"
    break;

  case 127: /* ReferenceType: Identifier  */
#line 583 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4712 "parser2.tab.c"
    break;

  case 128: /* ReferenceType: UnannArrayType  */
#line 584 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4718 "parser2.tab.c"
    break;

  case 129: /* TypeParameter: Identifier  */
#line 586 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4724 "parser2.tab.c"
    break;

  case 130: /* TypeParameter: Identifier TypeBound  */
#line 587 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4730 "parser2.tab.c"
    break;

  case 131: /* TypeBound: EXTENDS Identifier  */
#line 589 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4736 "parser2.tab.c"
    break;

  case 132: /* TypeBound: EXTENDS Identifier OMAdditionalBound  */
#line 590 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4742 "parser2.tab.c"
    break;

  case 133: /* AdditionalBound: BITAND Identifier  */
#line 592 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4748 "parser2.tab.c"
    break;

  case 134: /* ModuleName: Identifier  */
#line 594 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4754 "parser2.tab.c"
    break;

  case 135: /* ModuleName: ModuleName DOT Identifier  */
#line 595 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4760 "parser2.tab.c"
    break;

  case 136: /* ExpressionName: Identifier DOT Identifier  */
#line 597 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;string x=(yyvsp[-2].str);string p=newtemp(); (yyval.typeinfo)->tempname=p;p=p+" = "+x; (yyval.typeinfo)->tac={p};}
#line 4766 "parser2.tab.c"
    break;

  case 137: /* ExpressionName: ExpressionName DOT Identifier  */
#line 598 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 4772 "parser2.tab.c"
    break;

  case 138: /* MethodName: UnqualifiedMethodIdentifier  */
#line 600 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4778 "parser2.tab.c"
    break;

  case 139: /* CompilationUnit: OrdinaryCompilationUnit  */
#line 602 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac; for(auto z:((yyval.typeinfo)->tac)) fprintf(dotfile,"%s\n",z.c_str());}
#line 4784 "parser2.tab.c"
    break;

  case 140: /* CompilationUnit: ModularCompilationUnit  */
#line 603 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac; for(auto z:((yyval.typeinfo)->tac)) fprintf(dotfile,"%s\n",z.c_str());}
#line 4790 "parser2.tab.c"
    break;

  case 141: /* OrdinaryCompilationUnit: %empty  */
#line 605 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 4796 "parser2.tab.c"
    break;

  case 142: /* OrdinaryCompilationUnit: OMTopLevelClassOrInterfaceDeclaration  */
#line 606 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4802 "parser2.tab.c"
    break;

  case 143: /* OrdinaryCompilationUnit: OMImportDeclaration  */
#line 607 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4808 "parser2.tab.c"
    break;

  case 144: /* OrdinaryCompilationUnit: OMImportDeclaration OMTopLevelClassOrInterfaceDeclaration  */
#line 608 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4814 "parser2.tab.c"
    break;

  case 145: /* OrdinaryCompilationUnit: PackageDeclaration  */
#line 609 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4820 "parser2.tab.c"
    break;

  case 146: /* OrdinaryCompilationUnit: PackageDeclaration OMTopLevelClassOrInterfaceDeclaration  */
#line 610 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4826 "parser2.tab.c"
    break;

  case 147: /* OrdinaryCompilationUnit: PackageDeclaration OMImportDeclaration  */
#line 611 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4832 "parser2.tab.c"
    break;

  case 148: /* OrdinaryCompilationUnit: PackageDeclaration OMImportDeclaration OMTopLevelClassOrInterfaceDeclaration  */
#line 612 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4838 "parser2.tab.c"
    break;

  case 149: /* ModularCompilationUnit: ModuleDeclaration  */
#line 614 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4844 "parser2.tab.c"
    break;

  case 150: /* ModularCompilationUnit: OMImportDeclaration ModuleDeclaration  */
#line 615 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4850 "parser2.tab.c"
    break;

  case 151: /* PackageDeclaration: PACKAGE Identifier SEMICOLON  */
#line 617 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4856 "parser2.tab.c"
    break;

  case 152: /* PackageDeclaration: PACKAGE Identifier OMDotIdentifier SEMICOLON  */
#line 618 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4862 "parser2.tab.c"
    break;

  case 153: /* ImportDeclaration: SingleTypeImportDeclaration  */
#line 620 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4868 "parser2.tab.c"
    break;

  case 154: /* ImportDeclaration: SingleStaticImportDeclaration  */
#line 621 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4874 "parser2.tab.c"
    break;

  case 155: /* ImportDeclaration: StaticImportOnDemandDeclaration  */
#line 622 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4880 "parser2.tab.c"
    break;

  case 156: /* ImportDeclaration: ImportOnDemandDeclaration  */
#line 623 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4886 "parser2.tab.c"
    break;

  case 157: /* SingleTypeImportDeclaration: IMPORT Identifier SEMICOLON  */
#line 625 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4892 "parser2.tab.c"
    break;

  case 158: /* SingleTypeImportDeclaration: IMPORT ExpressionName SEMICOLON  */
#line 626 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4898 "parser2.tab.c"
    break;

  case 159: /* SingleStaticImportDeclaration: IMPORT STATIC ExpressionName SEMICOLON  */
#line 628 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4904 "parser2.tab.c"
    break;

  case 160: /* ImportOnDemandDeclaration: IMPORT Identifier DOT MULTIPLY SEMICOLON  */
#line 630 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4910 "parser2.tab.c"
    break;

  case 161: /* ImportOnDemandDeclaration: IMPORT ExpressionName DOT MULTIPLY SEMICOLON  */
#line 631 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4916 "parser2.tab.c"
    break;

  case 162: /* StaticImportOnDemandDeclaration: IMPORT STATIC Identifier DOT MULTIPLY SEMICOLON  */
#line 633 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4922 "parser2.tab.c"
    break;

  case 163: /* StaticImportOnDemandDeclaration: IMPORT STATIC ExpressionName DOT MULTIPLY SEMICOLON  */
#line 634 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4928 "parser2.tab.c"
    break;

  case 164: /* TopLevelClassOrInterfaceDeclaration: ClassDeclaration  */
#line 636 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4934 "parser2.tab.c"
    break;

  case 165: /* TopLevelClassOrInterfaceDeclaration: InterfaceDeclaration  */
#line 637 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4940 "parser2.tab.c"
    break;

  case 166: /* TopLevelClassOrInterfaceDeclaration: SEMICOLON  */
#line 638 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 4946 "parser2.tab.c"
    break;

  case 167: /* ModuleDeclaration: MODULE Identifier LCB RCB  */
#line 640 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 4952 "parser2.tab.c"
    break;

  case 168: /* ModuleDeclaration: MODULE Identifier LCB OMModuleDirective RCB  */
#line 641 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 4958 "parser2.tab.c"
    break;

  case 169: /* ModuleDeclaration: MODULE Identifier OMDotIdentifier LCB RCB  */
#line 642 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 4964 "parser2.tab.c"
    break;

  case 170: /* ModuleDeclaration: MODULE Identifier OMDotIdentifier LCB OMModuleDirective RCB  */
#line 643 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 4970 "parser2.tab.c"
    break;

  case 171: /* ModuleDeclaration: OPEN MODULE Identifier LCB RCB  */
#line 644 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 4976 "parser2.tab.c"
    break;

  case 172: /* ModuleDeclaration: OPEN MODULE Identifier LCB OMModuleDirective RCB  */
#line 645 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 4982 "parser2.tab.c"
    break;

  case 173: /* ModuleDeclaration: OPEN MODULE Identifier OMDotIdentifier LCB RCB  */
#line 646 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 4988 "parser2.tab.c"
    break;

  case 174: /* ModuleDeclaration: OPEN MODULE Identifier OMDotIdentifier LCB OMModuleDirective RCB  */
#line 647 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 4994 "parser2.tab.c"
    break;

  case 175: /* ModuleDirective: REQUIRES ModuleName SEMICOLON  */
#line 649 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5000 "parser2.tab.c"
    break;

  case 176: /* ModuleDirective: REQUIRES OMRequiresModifier ModuleName SEMICOLON  */
#line 650 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5006 "parser2.tab.c"
    break;

  case 177: /* ModuleDirective: EXPORTS Identifier SEMICOLON  */
#line 651 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5012 "parser2.tab.c"
    break;

  case 178: /* ModuleDirective: EXPORTS Identifier TO ModuleName SEMICOLON  */
#line 652 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5018 "parser2.tab.c"
    break;

  case 179: /* ModuleDirective: EXPORTS Identifier TO ModuleName OMCommaModuleName SEMICOLON  */
#line 653 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5024 "parser2.tab.c"
    break;

  case 180: /* ModuleDirective: OPENS Identifier SEMICOLON  */
#line 654 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5030 "parser2.tab.c"
    break;

  case 181: /* ModuleDirective: OPENS Identifier TO ModuleName SEMICOLON  */
#line 655 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5036 "parser2.tab.c"
    break;

  case 182: /* ModuleDirective: OPENS Identifier TO ModuleName OMCommaModuleName SEMICOLON  */
#line 656 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5042 "parser2.tab.c"
    break;

  case 183: /* ModuleDirective: USES Identifier SEMICOLON  */
#line 657 "parser2.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5048 "parser2.tab.c"
    break;

  case 184: /* ModuleDirective: PROVIDES Identifier WITH Identifier SEMICOLON  */
#line 658 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5054 "parser2.tab.c"
    break;

  case 185: /* ModuleDirective: PROVIDES Identifier WITH Identifier OMCommaTypeName SEMICOLON  */
#line 659 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5060 "parser2.tab.c"
    break;

  case 186: /* ModuleDirective: EXPORTS ExpressionName SEMICOLON  */
#line 660 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5066 "parser2.tab.c"
    break;

  case 187: /* ModuleDirective: EXPORTS ExpressionName TO ModuleName SEMICOLON  */
#line 661 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-3].typeinfo)->tac;}
#line 5072 "parser2.tab.c"
    break;

  case 188: /* ModuleDirective: EXPORTS ExpressionName TO ModuleName OMCommaModuleName SEMICOLON  */
#line 662 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 5078 "parser2.tab.c"
    break;

  case 189: /* ModuleDirective: OPENS ExpressionName SEMICOLON  */
#line 663 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5084 "parser2.tab.c"
    break;

  case 190: /* ModuleDirective: OPENS ExpressionName TO ModuleName SEMICOLON  */
#line 664 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-3].typeinfo)->tac;}
#line 5090 "parser2.tab.c"
    break;

  case 191: /* ModuleDirective: OPENS ExpressionName TO ModuleName OMCommaModuleName SEMICOLON  */
#line 665 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 5096 "parser2.tab.c"
    break;

  case 192: /* ModuleDirective: USES ExpressionName SEMICOLON  */
#line 666 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5102 "parser2.tab.c"
    break;

  case 193: /* ModuleDirective: PROVIDES ExpressionName WITH ExpressionName SEMICOLON  */
#line 667 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-3].typeinfo)->tac;}
#line 5108 "parser2.tab.c"
    break;

  case 194: /* ModuleDirective: PROVIDES ExpressionName WITH ExpressionName OMCommaTypeName SEMICOLON  */
#line 668 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 5114 "parser2.tab.c"
    break;

  case 195: /* ModuleDirective: PROVIDES ExpressionName WITH Identifier SEMICOLON  */
#line 669 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-3].typeinfo)->tac;}
#line 5120 "parser2.tab.c"
    break;

  case 196: /* ModuleDirective: PROVIDES Identifier WITH ExpressionName OMCommaTypeName SEMICOLON  */
#line 670 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 5126 "parser2.tab.c"
    break;

  case 197: /* ModuleDirective: PROVIDES Identifier WITH ExpressionName SEMICOLON  */
#line 671 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5132 "parser2.tab.c"
    break;

  case 198: /* ModuleDirective: PROVIDES ExpressionName WITH Identifier OMCommaTypeName SEMICOLON  */
#line 672 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 5138 "parser2.tab.c"
    break;

  case 199: /* ClassDeclaration: NormalClassDeclaration  */
#line 674 "parser2.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5144 "parser2.tab.c"
    break;

  case 200: /* ClassDeclaration: EnumDeclaration  */
#line 675 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5150 "parser2.tab.c"
    break;

  case 201: /* ClassDeclaration: RecordDeclaration  */
#line 676 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5156 "parser2.tab.c"
    break;

  case 202: /* NormalClassDeclaration: CLASS Identifier ClassBody  */
#line 678 "parser2.y"
                                                                                            {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5162 "parser2.tab.c"
    break;

  case 203: /* NormalClassDeclaration: CLASS Identifier ClassPermits ClassBody  */
#line 679 "parser2.y"
                                                                                                             {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5168 "parser2.tab.c"
    break;

  case 204: /* NormalClassDeclaration: CLASS Identifier ClassImplements ClassBody  */
#line 680 "parser2.y"
                                                                                                     {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5174 "parser2.tab.c"
    break;

  case 205: /* NormalClassDeclaration: CLASS Identifier ClassImplements ClassPermits ClassBody  */
#line 681 "parser2.y"
                                                                                                    {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5180 "parser2.tab.c"
    break;

  case 206: /* NormalClassDeclaration: CLASS Identifier ClassExtends ClassBody  */
#line 682 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5186 "parser2.tab.c"
    break;

  case 207: /* NormalClassDeclaration: CLASS Identifier ClassExtends ClassPermits ClassBody  */
#line 683 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5192 "parser2.tab.c"
    break;

  case 208: /* NormalClassDeclaration: CLASS Identifier ClassExtends ClassImplements ClassBody  */
#line 684 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5198 "parser2.tab.c"
    break;

  case 209: /* NormalClassDeclaration: CLASS Identifier ClassExtends ClassImplements ClassPermits ClassBody  */
#line 685 "parser2.y"
                                                                                               {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5204 "parser2.tab.c"
    break;

  case 210: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassBody  */
#line 686 "parser2.y"
                                                                                                                       {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5210 "parser2.tab.c"
    break;

  case 211: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassPermits ClassBody  */
#line 687 "parser2.y"
                                                                                                                 {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5216 "parser2.tab.c"
    break;

  case 212: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassImplements ClassBody  */
#line 688 "parser2.y"
                                                                                                                 {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5222 "parser2.tab.c"
    break;

  case 213: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassImplements ClassPermits ClassBody  */
#line 689 "parser2.y"
                                                                                                         {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5228 "parser2.tab.c"
    break;

  case 214: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassExtends ClassBody  */
#line 690 "parser2.y"
                                                                                                                         {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5234 "parser2.tab.c"
    break;

  case 215: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassExtends ClassPermits ClassBody  */
#line 691 "parser2.y"
                                                                                                         {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5240 "parser2.tab.c"
    break;

  case 216: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassExtends ClassImplements ClassBody  */
#line 692 "parser2.y"
                                                                                                                     {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5246 "parser2.tab.c"
    break;

  case 217: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassExtends ClassImplements ClassPermits ClassBody  */
#line 693 "parser2.y"
                                                                                                                         {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5252 "parser2.tab.c"
    break;

  case 218: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassBody  */
#line 694 "parser2.y"
                                                                                                                                                                 {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5258 "parser2.tab.c"
    break;

  case 219: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassPermits ClassBody  */
#line 695 "parser2.y"
                                                                                                                                                         {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5264 "parser2.tab.c"
    break;

  case 220: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassImplements ClassBody  */
#line 696 "parser2.y"
                                                                                                                                                 {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5270 "parser2.tab.c"
    break;

  case 221: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassImplements ClassPermits ClassBody  */
#line 697 "parser2.y"
                                                                                                                                         {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5276 "parser2.tab.c"
    break;

  case 222: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassExtends ClassBody  */
#line 698 "parser2.y"
                                                                                                                                                         {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5282 "parser2.tab.c"
    break;

  case 223: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassExtends ClassPermits ClassBody  */
#line 699 "parser2.y"
                                                                                                                                         {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5288 "parser2.tab.c"
    break;

  case 224: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassExtends ClassImplements ClassBody  */
#line 700 "parser2.y"
                                                                                                                                         {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5294 "parser2.tab.c"
    break;

  case 225: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassExtends ClassImplements ClassPermits ClassBody  */
#line 701 "parser2.y"
                                                                                                                                 {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5300 "parser2.tab.c"
    break;

  case 226: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassBody  */
#line 702 "parser2.y"
                                                                                                                                                         {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5306 "parser2.tab.c"
    break;

  case 227: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassPermits ClassBody  */
#line 703 "parser2.y"
                                                                                                                                         {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5312 "parser2.tab.c"
    break;

  case 228: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassImplements ClassBody  */
#line 704 "parser2.y"
                                                                                                                                         {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5318 "parser2.tab.c"
    break;

  case 229: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassImplements ClassPermits ClassBody  */
#line 705 "parser2.y"
                                                                                                                         {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5324 "parser2.tab.c"
    break;

  case 230: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassBody  */
#line 706 "parser2.y"
                                                                                                                                         {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5330 "parser2.tab.c"
    break;

  case 231: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassPermits ClassBody  */
#line 707 "parser2.y"
                                                                                                                         {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5336 "parser2.tab.c"
    break;

  case 232: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassImplements ClassBody  */
#line 708 "parser2.y"
                                                                                                                         {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5342 "parser2.tab.c"
    break;

  case 233: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassImplements ClassPermits ClassBody  */
#line 709 "parser2.y"
                                                                                                                                     {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5348 "parser2.tab.c"
    break;

  case 234: /* TypeParameters: LT TypeParameterList GT  */
#line 711 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5354 "parser2.tab.c"
    break;

  case 235: /* TypeParameterList: TypeParameter  */
#line 713 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5360 "parser2.tab.c"
    break;

  case 236: /* TypeParameterList: TypeParameter OMCommaTypeParameter  */
#line 714 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5366 "parser2.tab.c"
    break;

  case 237: /* ClassExtends: EXTENDS Identifier  */
#line 716 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5372 "parser2.tab.c"
    break;

  case 238: /* ClassImplements: IMPLEMENTS InterfaceTypeList  */
#line 718 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5378 "parser2.tab.c"
    break;

  case 239: /* InterfaceTypeList: Identifier  */
#line 720 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5384 "parser2.tab.c"
    break;

  case 240: /* InterfaceTypeList: Identifier OMCommaInterfaceType  */
#line 721 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5390 "parser2.tab.c"
    break;

  case 241: /* ClassPermits: PERMITS Identifier  */
#line 724 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5396 "parser2.tab.c"
    break;

  case 242: /* ClassPermits: PERMITS ExpressionName  */
#line 725 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5402 "parser2.tab.c"
    break;

  case 243: /* ClassPermits: PERMITS Identifier OMCommaTypeName  */
#line 726 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5408 "parser2.tab.c"
    break;

  case 244: /* ClassPermits: PERMITS ExpressionName OMCommaTypeName  */
#line 727 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5414 "parser2.tab.c"
    break;

  case 245: /* ClassBody: LCB RCB  */
#line 730 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5420 "parser2.tab.c"
    break;

  case 246: /* ClassBody: LCB OMClassBodyDeclaration RCB  */
#line 731 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5426 "parser2.tab.c"
    break;

  case 247: /* ClassBodyDeclaration: ClassMemberDeclaration  */
#line 733 "parser2.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5432 "parser2.tab.c"
    break;

  case 248: /* ClassBodyDeclaration: InstanceInitializer  */
#line 734 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5438 "parser2.tab.c"
    break;

  case 249: /* ClassBodyDeclaration: StaticInitializer  */
#line 735 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5444 "parser2.tab.c"
    break;

  case 250: /* ClassBodyDeclaration: ConstructorDeclaration  */
#line 736 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5450 "parser2.tab.c"
    break;

  case 251: /* ClassMemberDeclaration: FieldDeclaration  */
#line 738 "parser2.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5456 "parser2.tab.c"
    break;

  case 252: /* ClassMemberDeclaration: MethodDeclaration  */
#line 739 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5462 "parser2.tab.c"
    break;

  case 253: /* ClassMemberDeclaration: ClassDeclaration  */
#line 740 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5468 "parser2.tab.c"
    break;

  case 254: /* ClassMemberDeclaration: InterfaceDeclaration  */
#line 741 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5474 "parser2.tab.c"
    break;

  case 255: /* ClassMemberDeclaration: SEMICOLON  */
#line 742 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5480 "parser2.tab.c"
    break;

  case 256: /* FieldDeclaration: UnannType VariableDeclaratorList SEMICOLON  */
#line 744 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5486 "parser2.tab.c"
    break;

  case 257: /* FieldDeclaration: OMClassModifier UnannType VariableDeclaratorList SEMICOLON  */
#line 745 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5492 "parser2.tab.c"
    break;

  case 258: /* VariableDeclaratorList: VariableDeclarator  */
#line 747 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5498 "parser2.tab.c"
    break;

  case 259: /* VariableDeclaratorList: VariableDeclarator COMMA VariableDeclaratorList  */
#line 748 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5504 "parser2.tab.c"
    break;

  case 260: /* VariableDeclarator: VariableDeclaratorId  */
#line 750 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5510 "parser2.tab.c"
    break;

  case 261: /* VariableDeclarator: VariableDeclaratorId EQUAL VariableInitializer  */
#line 751 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string c=(yyvsp[-2].typeinfo)->tempname+"="+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,c);}
#line 5516 "parser2.tab.c"
    break;

  case 262: /* VariableDeclaratorId: Identifier  */
#line 753 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;string x=(yyvsp[0].str);(yyval.typeinfo)->tempname=x;}
#line 5522 "parser2.tab.c"
    break;

  case 263: /* VariableDeclaratorId: Identifier OMPSB  */
#line 754 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;string x=(yyvsp[-1].str);(yyval.typeinfo)->tempname=x;}
#line 5528 "parser2.tab.c"
    break;

  case 264: /* VariableInitializer: Expression  */
#line 757 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 5534 "parser2.tab.c"
    break;

  case 265: /* VariableInitializer: ArrayInitializer  */
#line 758 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 5540 "parser2.tab.c"
    break;

  case 266: /* UnannType: UnannPrimitiveType  */
#line 760 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 5546 "parser2.tab.c"
    break;

  case 267: /* UnannType: Identifier  */
#line 761 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;string x=(yyvsp[0].str);(yyval.typeinfo)->tempname=x;}
#line 5552 "parser2.tab.c"
    break;

  case 268: /* UnannType: UnannArrayType  */
#line 762 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 5558 "parser2.tab.c"
    break;

  case 269: /* UnannPrimitiveType: NumericType  */
#line 764 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5564 "parser2.tab.c"
    break;

  case 270: /* UnannPrimitiveType: BOOLEAN  */
#line 765 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5570 "parser2.tab.c"
    break;

  case 271: /* UnannArrayType: UnannPrimitiveType OMPSB  */
#line 767 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5576 "parser2.tab.c"
    break;

  case 272: /* UnannArrayType: Identifier OMPSB  */
#line 768 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5582 "parser2.tab.c"
    break;

  case 273: /* MethodDeclaration: MethodHeader MethodBody  */
#line 771 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;string p=newlabel(); string z="function end\n"+p; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z);}
#line 5588 "parser2.tab.c"
    break;

  case 274: /* MethodDeclaration: OMClassModifier MethodHeader MethodBody  */
#line 772 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;string p=newlabel(); string z="function end\n"+p; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z);}
#line 5594 "parser2.tab.c"
    break;

  case 275: /* MethodHeader: Result MethodDeclarator  */
#line 774 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;string q=newlabel();string p="call "+((yyvsp[-1].typeinfo))->tempname+"\n"+q;(yyval.typeinfo)->tac=concvector(p,(yyvsp[0].typeinfo)->tac);}
#line 5600 "parser2.tab.c"
    break;

  case 276: /* MethodHeader: Result MethodDeclarator Throws  */
#line 775 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;string q=newlabel();string p="call "+((yyvsp[-2].typeinfo))->tempname+"\n"+q; (yyval.typeinfo)->tac=concvector(p,(yyvsp[-1].typeinfo)->tac);}
#line 5606 "parser2.tab.c"
    break;

  case 277: /* MethodHeader: TypeParameters Result MethodDeclarator  */
#line 776 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;string q=newlabel();string p="call "+((yyvsp[-1].typeinfo))->tempname+"\n"+q; (yyval.typeinfo)->tac=concvector(p,(yyvsp[0].typeinfo)->tac);}
#line 5612 "parser2.tab.c"
    break;

  case 278: /* MethodHeader: TypeParameters Result MethodDeclarator Throws  */
#line 777 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string q=newlabel();string p="call "+((yyvsp[-2].typeinfo))->tempname+"\n"+q; (yyval.typeinfo)->tac=concvector(p,(yyvsp[-1].typeinfo)->tac);}
#line 5618 "parser2.tab.c"
    break;

  case 279: /* Result: UnannType Identifier  */
#line 779 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;string x=(yyvsp[0].str); (yyval.typeinfo)->tempname=x;(yyval.typeinfo)->tac=emptyvector();}
#line 5624 "parser2.tab.c"
    break;

  case 280: /* Result: VOID Identifier  */
#line 780 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;string x=(yyvsp[0].str); (yyval.typeinfo)->tempname=x; (yyval.typeinfo)->tac=emptyvector();}
#line 5630 "parser2.tab.c"
    break;

  case 281: /* MethodDeclarator: LRB RRB  */
#line 783 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5636 "parser2.tab.c"
    break;

  case 282: /* MethodDeclarator: LRB RRB OMPSB  */
#line 784 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5642 "parser2.tab.c"
    break;

  case 283: /* MethodDeclarator: LRB FormalParameterList RRB  */
#line 785 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5648 "parser2.tab.c"
    break;

  case 284: /* MethodDeclarator: LRB FormalParameterList RRB OMPSB  */
#line 786 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 5654 "parser2.tab.c"
    break;

  case 285: /* MethodDeclarator: LRB ReceiverParameterComma RRB  */
#line 787 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5660 "parser2.tab.c"
    break;

  case 286: /* MethodDeclarator: LRB ReceiverParameterComma RRB OMPSB  */
#line 788 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 5666 "parser2.tab.c"
    break;

  case 287: /* MethodDeclarator: LRB ReceiverParameterComma FormalParameterList RRB  */
#line 789 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5672 "parser2.tab.c"
    break;

  case 288: /* MethodDeclarator: LRB ReceiverParameterComma FormalParameterList RRB OMPSB  */
#line 790 "parser2.y"
                                                                                    {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 5678 "parser2.tab.c"
    break;

  case 289: /* ReceiverParameter: UnannType THIS  */
#line 792 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5684 "parser2.tab.c"
    break;

  case 290: /* ReceiverParameter: UnannType IdentifierDot THIS  */
#line 793 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5690 "parser2.tab.c"
    break;

  case 291: /* FormalParameterList: FormalParameter  */
#line 795 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5696 "parser2.tab.c"
    break;

  case 292: /* FormalParameterList: FormalParameter OMCommaFormalParameter  */
#line 796 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5702 "parser2.tab.c"
    break;

  case 293: /* FormalParameter: UnannType VariableDeclaratorId  */
#line 798 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5708 "parser2.tab.c"
    break;

  case 294: /* FormalParameter: OMClassModifier UnannType VariableDeclaratorId  */
#line 799 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5714 "parser2.tab.c"
    break;

  case 295: /* FormalParameter: VariableArityParameter  */
#line 800 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5720 "parser2.tab.c"
    break;

  case 296: /* VariableArityParameter: UnannType THREEDOT Identifier  */
#line 802 "parser2.y"
                                                                                    {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5726 "parser2.tab.c"
    break;

  case 297: /* VariableArityParameter: OMClassModifier UnannType THREEDOT Identifier  */
#line 803 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5732 "parser2.tab.c"
    break;

  case 298: /* Throws: THROWS ExceptionTypeList  */
#line 806 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5738 "parser2.tab.c"
    break;

  case 299: /* ExceptionTypeList: ExceptionType  */
#line 808 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5744 "parser2.tab.c"
    break;

  case 300: /* ExceptionTypeList: ExceptionType OMCommaExceptionType  */
#line 809 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5750 "parser2.tab.c"
    break;

  case 301: /* ExceptionType: Identifier  */
#line 811 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5756 "parser2.tab.c"
    break;

  case 302: /* MethodBody: Block  */
#line 814 "parser2.y"
                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5762 "parser2.tab.c"
    break;

  case 303: /* MethodBody: SEMICOLON  */
#line 815 "parser2.y"
                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5768 "parser2.tab.c"
    break;

  case 304: /* InstanceInitializer: Block  */
#line 817 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5774 "parser2.tab.c"
    break;

  case 305: /* StaticInitializer: STATIC Block  */
#line 819 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5780 "parser2.tab.c"
    break;

  case 306: /* ConstructorDeclaration: ConstructorDeclarator ConstructorBody  */
#line 821 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string z="constructor called";string zz="constructor end"; (yyval.typeinfo)->tac=concvector(z,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,zz);}
#line 5786 "parser2.tab.c"
    break;

  case 307: /* ConstructorDeclaration: ConstructorDeclarator Throws ConstructorBody  */
#line 822 "parser2.y"
                                                                                            {(yyval.typeinfo)=new Typeinfo;string z="constructor called";string zz="constructor end"; (yyval.typeinfo)->tac=concvector(z,(yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,zz);}
#line 5792 "parser2.tab.c"
    break;

  case 308: /* ConstructorDeclaration: OMClassModifier ConstructorDeclarator ConstructorBody  */
#line 823 "parser2.y"
                                                                                            {(yyval.typeinfo)=new Typeinfo;string z="constructor called";string zz="constructor end"; (yyval.typeinfo)->tac=concvector(z,(yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,zz);}
#line 5798 "parser2.tab.c"
    break;

  case 309: /* ConstructorDeclaration: OMClassModifier ConstructorDeclarator Throws ConstructorBody  */
#line 824 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string z="constructor called";string zz="constructor end"; (yyval.typeinfo)->tac=concvector(z,(yyvsp[-3].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,zz);}
#line 5804 "parser2.tab.c"
    break;

  case 310: /* ConstructorDeclarator: Identifier LRB RRB  */
#line 826 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5810 "parser2.tab.c"
    break;

  case 311: /* ConstructorDeclarator: Identifier LRB FormalParameterList RRB  */
#line 827 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5816 "parser2.tab.c"
    break;

  case 312: /* ConstructorDeclarator: Identifier LRB ReceiverParameterComma RRB  */
#line 828 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5822 "parser2.tab.c"
    break;

  case 313: /* ConstructorDeclarator: Identifier LRB ReceiverParameterComma FormalParameterList RRB  */
#line 829 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5828 "parser2.tab.c"
    break;

  case 314: /* ConstructorDeclarator: TypeParameters Identifier LRB RRB  */
#line 830 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5834 "parser2.tab.c"
    break;

  case 315: /* ConstructorDeclarator: TypeParameters Identifier LRB FormalParameterList RRB  */
#line 831 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5840 "parser2.tab.c"
    break;

  case 316: /* ConstructorDeclarator: TypeParameters Identifier LRB ReceiverParameterComma RRB  */
#line 832 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5846 "parser2.tab.c"
    break;

  case 317: /* ConstructorDeclarator: TypeParameters Identifier LRB ReceiverParameterComma FormalParameterList RRB  */
#line 833 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 5852 "parser2.tab.c"
    break;

  case 318: /* ConstructorBody: LCB RCB  */
#line 836 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5858 "parser2.tab.c"
    break;

  case 319: /* ConstructorBody: LCB BlockStatements RCB  */
#line 837 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5864 "parser2.tab.c"
    break;

  case 320: /* ConstructorBody: LCB ExplicitConstructorInvocation RCB  */
#line 838 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5870 "parser2.tab.c"
    break;

  case 321: /* ConstructorBody: LCB ExplicitConstructorInvocation BlockStatements RCB  */
#line 839 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 5876 "parser2.tab.c"
    break;

  case 322: /* ExplicitConstructorInvocation: THIS LRB RRB SEMICOLON  */
#line 841 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5882 "parser2.tab.c"
    break;

  case 323: /* ExplicitConstructorInvocation: THIS LRB ArgumentList RRB SEMICOLON  */
#line 842 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 5888 "parser2.tab.c"
    break;

  case 324: /* ExplicitConstructorInvocation: SUPER LRB RRB SEMICOLON  */
#line 843 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5894 "parser2.tab.c"
    break;

  case 325: /* ExplicitConstructorInvocation: SUPER LRB ArgumentList RRB SEMICOLON  */
#line 844 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 5900 "parser2.tab.c"
    break;

  case 326: /* ExplicitConstructorInvocation: Identifier DOT SUPER LRB RRB SEMICOLON  */
#line 845 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5906 "parser2.tab.c"
    break;

  case 327: /* ExplicitConstructorInvocation: Identifier DOT SUPER LRB ArgumentList RRB SEMICOLON  */
#line 846 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 5912 "parser2.tab.c"
    break;

  case 328: /* ExplicitConstructorInvocation: ExpressionName DOT SUPER LRB RRB SEMICOLON  */
#line 847 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5918 "parser2.tab.c"
    break;

  case 329: /* ExplicitConstructorInvocation: ExpressionName DOT SUPER LRB ArgumentList RRB SEMICOLON  */
#line 848 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 5924 "parser2.tab.c"
    break;

  case 330: /* ExplicitConstructorInvocation: Primary DOT SUPER LRB RRB SEMICOLON  */
#line 849 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5930 "parser2.tab.c"
    break;

  case 331: /* ExplicitConstructorInvocation: Primary DOT SUPER LRB ArgumentList RRB SEMICOLON  */
#line 850 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 5936 "parser2.tab.c"
    break;

  case 332: /* EnumDeclaration: ENUM Identifier EnumBody  */
#line 852 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5942 "parser2.tab.c"
    break;

  case 333: /* EnumDeclaration: ENUM Identifier ClassImplements EnumBody  */
#line 853 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5948 "parser2.tab.c"
    break;

  case 334: /* EnumDeclaration: OMClassModifier ENUM Identifier EnumBody  */
#line 854 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5954 "parser2.tab.c"
    break;

  case 335: /* EnumDeclaration: OMClassModifier ENUM Identifier ClassImplements EnumBody  */
#line 855 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5960 "parser2.tab.c"
    break;

  case 336: /* EnumBody: LCB RCB  */
#line 858 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5966 "parser2.tab.c"
    break;

  case 337: /* EnumBody: LCB EnumBodyDeclarations RCB  */
#line 859 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5972 "parser2.tab.c"
    break;

  case 338: /* EnumBody: LCB COMMA RCB  */
#line 860 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5978 "parser2.tab.c"
    break;

  case 339: /* EnumBody: LCB COMMA EnumBodyDeclarations RCB  */
#line 861 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5984 "parser2.tab.c"
    break;

  case 340: /* EnumBody: LCB EnumConstantList RCB  */
#line 862 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5990 "parser2.tab.c"
    break;

  case 341: /* EnumBody: LCB EnumConstantList EnumBodyDeclarations RCB  */
#line 863 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 5996 "parser2.tab.c"
    break;

  case 342: /* EnumConstantList: EnumConstant  */
#line 865 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6002 "parser2.tab.c"
    break;

  case 343: /* EnumConstantList: OMCommaEnumConstant  */
#line 866 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6008 "parser2.tab.c"
    break;

  case 344: /* PRB: LRB RRB  */
#line 868 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6014 "parser2.tab.c"
    break;

  case 345: /* PRBArgumentList: LRB ArgumentList RRB  */
#line 870 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6020 "parser2.tab.c"
    break;

  case 346: /* EnumConstant: Identifier  */
#line 872 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6026 "parser2.tab.c"
    break;

  case 347: /* EnumConstant: Identifier PRB  */
#line 873 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6032 "parser2.tab.c"
    break;

  case 348: /* EnumConstant: Identifier PRBArgumentList  */
#line 874 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6038 "parser2.tab.c"
    break;

  case 349: /* EnumConstant: Identifier ClassBody  */
#line 875 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6044 "parser2.tab.c"
    break;

  case 350: /* EnumConstant: Identifier PRB ClassBody  */
#line 876 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6050 "parser2.tab.c"
    break;

  case 351: /* EnumConstant: Identifier PRBArgumentList ClassBody  */
#line 877 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6056 "parser2.tab.c"
    break;

  case 352: /* EnumBodyDeclarations: SEMICOLON  */
#line 879 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6062 "parser2.tab.c"
    break;

  case 353: /* EnumBodyDeclarations: SEMICOLON OMClassBodyDeclaration  */
#line 880 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6068 "parser2.tab.c"
    break;

  case 354: /* RecordDeclaration: RECORD Identifier RecordHeader RecordBody  */
#line 882 "parser2.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6074 "parser2.tab.c"
    break;

  case 355: /* RecordDeclaration: RECORD Identifier RecordHeader ClassImplements RecordBody  */
#line 883 "parser2.y"
                                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6080 "parser2.tab.c"
    break;

  case 356: /* RecordDeclaration: RECORD Identifier TypeParameters RecordHeader RecordBody  */
#line 884 "parser2.y"
                                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6086 "parser2.tab.c"
    break;

  case 357: /* RecordDeclaration: RECORD Identifier TypeParameters RecordHeader ClassImplements RecordBody  */
#line 885 "parser2.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6092 "parser2.tab.c"
    break;

  case 358: /* RecordDeclaration: OMClassModifier RECORD Identifier RecordHeader RecordBody  */
#line 886 "parser2.y"
                                                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6098 "parser2.tab.c"
    break;

  case 359: /* RecordDeclaration: OMClassModifier RECORD Identifier RecordHeader ClassImplements RecordBody  */
#line 887 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6104 "parser2.tab.c"
    break;

  case 360: /* RecordDeclaration: OMClassModifier RECORD Identifier TypeParameters RecordHeader RecordBody  */
#line 888 "parser2.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6110 "parser2.tab.c"
    break;

  case 361: /* RecordDeclaration: OMClassModifier RECORD Identifier TypeParameters RecordHeader ClassImplements RecordBody  */
#line 889 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6116 "parser2.tab.c"
    break;

  case 362: /* RecordHeader: LRB RRB  */
#line 892 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6122 "parser2.tab.c"
    break;

  case 363: /* RecordHeader: LRB RecordComponentList RRB  */
#line 893 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6128 "parser2.tab.c"
    break;

  case 364: /* RecordComponentList: RecordComponent  */
#line 895 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6134 "parser2.tab.c"
    break;

  case 365: /* RecordComponentList: RecordComponent OMCommaRecordComponent  */
#line 896 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6140 "parser2.tab.c"
    break;

  case 366: /* RecordComponent: UnannType Identifier  */
#line 898 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6146 "parser2.tab.c"
    break;

  case 367: /* RecordComponent: VariableArityRecordComponent  */
#line 899 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6152 "parser2.tab.c"
    break;

  case 368: /* VariableArityRecordComponent: UnannType THREEDOT Identifier  */
#line 902 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6158 "parser2.tab.c"
    break;

  case 369: /* RecordBody: LCB RCB  */
#line 905 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6164 "parser2.tab.c"
    break;

  case 370: /* RecordBody: LCB OMRecordBodyDeclaration RCB  */
#line 906 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6170 "parser2.tab.c"
    break;

  case 371: /* RecordBodyDeclaration: ClassBodyDeclaration  */
#line 908 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6176 "parser2.tab.c"
    break;

  case 372: /* RecordBodyDeclaration: CompactConstructorDeclaration  */
#line 909 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6182 "parser2.tab.c"
    break;

  case 373: /* CompactConstructorDeclaration: Identifier ConstructorBody  */
#line 911 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6188 "parser2.tab.c"
    break;

  case 374: /* CompactConstructorDeclaration: OMClassModifier Identifier ConstructorBody  */
#line 912 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6194 "parser2.tab.c"
    break;

  case 375: /* InterfaceDeclaration: NormalInterfaceDeclaration  */
#line 915 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6200 "parser2.tab.c"
    break;

  case 376: /* NormalInterfaceDeclaration: INTERFACE Identifier InterfaceBody  */
#line 917 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6206 "parser2.tab.c"
    break;

  case 377: /* NormalInterfaceDeclaration: INTERFACE Identifier InterfacePermits InterfaceBody  */
#line 918 "parser2.y"
                                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6212 "parser2.tab.c"
    break;

  case 378: /* NormalInterfaceDeclaration: INTERFACE Identifier InterfaceExtends InterfaceBody  */
#line 919 "parser2.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6218 "parser2.tab.c"
    break;

  case 379: /* NormalInterfaceDeclaration: INTERFACE Identifier InterfaceExtends InterfacePermits InterfaceBody  */
#line 920 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6224 "parser2.tab.c"
    break;

  case 380: /* NormalInterfaceDeclaration: INTERFACE Identifier TypeParameters InterfaceBody  */
#line 921 "parser2.y"
                                                                                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6230 "parser2.tab.c"
    break;

  case 381: /* NormalInterfaceDeclaration: INTERFACE Identifier TypeParameters InterfacePermits InterfaceBody  */
#line 922 "parser2.y"
                                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6236 "parser2.tab.c"
    break;

  case 382: /* NormalInterfaceDeclaration: INTERFACE Identifier TypeParameters InterfaceExtends InterfaceBody  */
#line 923 "parser2.y"
                                                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6242 "parser2.tab.c"
    break;

  case 383: /* NormalInterfaceDeclaration: INTERFACE Identifier TypeParameters InterfaceExtends InterfacePermits InterfaceBody  */
#line 924 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6248 "parser2.tab.c"
    break;

  case 384: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier InterfaceBody  */
#line 925 "parser2.y"
                                                                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6254 "parser2.tab.c"
    break;

  case 385: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier InterfacePermits InterfaceBody  */
#line 926 "parser2.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6260 "parser2.tab.c"
    break;

  case 386: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier InterfaceExtends InterfaceBody  */
#line 927 "parser2.y"
                                                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6266 "parser2.tab.c"
    break;

  case 387: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier InterfaceExtends InterfacePermits InterfaceBody  */
#line 928 "parser2.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6272 "parser2.tab.c"
    break;

  case 388: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier TypeParameters InterfaceBody  */
#line 929 "parser2.y"
                                                                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6278 "parser2.tab.c"
    break;

  case 389: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier TypeParameters InterfacePermits InterfaceBody  */
#line 930 "parser2.y"
                                                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6284 "parser2.tab.c"
    break;

  case 390: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier TypeParameters InterfaceExtends InterfaceBody  */
#line 931 "parser2.y"
                                                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6290 "parser2.tab.c"
    break;

  case 391: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier TypeParameters InterfaceExtends InterfacePermits InterfaceBody  */
#line 932 "parser2.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6296 "parser2.tab.c"
    break;

  case 392: /* InterfaceModifier: Modifieropt  */
#line 935 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6302 "parser2.tab.c"
    break;

  case 393: /* InterfaceExtends: EXTENDS InterfaceTypeList  */
#line 937 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6308 "parser2.tab.c"
    break;

  case 394: /* InterfacePermits: PERMITS ExpressionName  */
#line 939 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6314 "parser2.tab.c"
    break;

  case 395: /* InterfacePermits: PERMITS ExpressionName OMCommaTypeName  */
#line 940 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6320 "parser2.tab.c"
    break;

  case 396: /* InterfaceBody: LCB RCB  */
#line 942 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6326 "parser2.tab.c"
    break;

  case 397: /* InterfaceBody: LCB OMInterfaceMemberDeclaration RCB  */
#line 943 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6332 "parser2.tab.c"
    break;

  case 398: /* InterfaceMemberDeclaration: ConstantDeclaration  */
#line 945 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6338 "parser2.tab.c"
    break;

  case 399: /* InterfaceMemberDeclaration: InterfaceMethodDeclaration  */
#line 946 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6344 "parser2.tab.c"
    break;

  case 400: /* InterfaceMemberDeclaration: ClassDeclaration  */
#line 947 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6350 "parser2.tab.c"
    break;

  case 401: /* InterfaceMemberDeclaration: InterfaceDeclaration  */
#line 948 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6356 "parser2.tab.c"
    break;

  case 402: /* InterfaceMemberDeclaration: SEMICOLON  */
#line 949 "parser2.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6362 "parser2.tab.c"
    break;

  case 403: /* ConstantDeclaration: UnannType VariableDeclaratorList SEMICOLON  */
#line 951 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6368 "parser2.tab.c"
    break;

  case 404: /* ConstantDeclaration: OMClassModifier UnannType VariableDeclaratorList SEMICOLON  */
#line 952 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6374 "parser2.tab.c"
    break;

  case 405: /* InterfaceMethodDeclaration: MethodHeader MethodBody  */
#line 954 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6380 "parser2.tab.c"
    break;

  case 406: /* InterfaceMethodDeclaration: OMClassModifier MethodHeader MethodBody  */
#line 955 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6386 "parser2.tab.c"
    break;

  case 407: /* ArrayInitializer: LCB RCB  */
#line 957 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6392 "parser2.tab.c"
    break;

  case 408: /* ArrayInitializer: LCB COMMA RCB  */
#line 958 "parser2.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6398 "parser2.tab.c"
    break;

  case 409: /* ArrayInitializer: LCB VariableInitializerList RCB  */
#line 959 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6404 "parser2.tab.c"
    break;

  case 410: /* VariableInitializerList: VariableInitializer  */
#line 961 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6410 "parser2.tab.c"
    break;

  case 411: /* VariableInitializerList: VariableInitializer OMCommaVariableInitializer  */
#line 962 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6416 "parser2.tab.c"
    break;

  case 412: /* Block: LCB RCB  */
#line 964 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;vector<string>p={}; (yyval.typeinfo)->tac=p;}
#line 6422 "parser2.tab.c"
    break;

  case 413: /* Block: LCB BlockStatements RCB  */
#line 965 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 6428 "parser2.tab.c"
    break;

  case 414: /* BlockStatements: BlockStatement  */
#line 967 "parser2.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6434 "parser2.tab.c"
    break;

  case 415: /* BlockStatements: BlockStatement OMBlockStatement  */
#line 968 "parser2.y"
                                                                            {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6440 "parser2.tab.c"
    break;

  case 416: /* BlockStatement: LocalClassOrInterfaceDeclaration  */
#line 970 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6446 "parser2.tab.c"
    break;

  case 417: /* BlockStatement: LocalVariableDeclarationStatement  */
#line 971 "parser2.y"
                                                                            {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6452 "parser2.tab.c"
    break;

  case 418: /* BlockStatement: Statement  */
#line 972 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6458 "parser2.tab.c"
    break;

  case 419: /* LocalClassOrInterfaceDeclaration: ClassDeclaration  */
#line 974 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6464 "parser2.tab.c"
    break;

  case 420: /* LocalClassOrInterfaceDeclaration: NormalInterfaceDeclaration  */
#line 975 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6470 "parser2.tab.c"
    break;

  case 421: /* LocalVariableDeclarationStatement: LocalVariableDeclaration SEMICOLON  */
#line 977 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 6476 "parser2.tab.c"
    break;

  case 422: /* LocalVariableDeclaration: LocalVariableType VariableDeclaratorList  */
#line 979 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6482 "parser2.tab.c"
    break;

  case 423: /* LocalVariableDeclaration: OMClassModifier LocalVariableType VariableDeclaratorList  */
#line 980 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6488 "parser2.tab.c"
    break;

  case 424: /* LocalVariableType: UnannType  */
#line 982 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6494 "parser2.tab.c"
    break;

  case 425: /* LocalVariableType: VAR  */
#line 983 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= emptyvector();}
#line 6500 "parser2.tab.c"
    break;

  case 426: /* Statement: StatementWithoutTrailingSubstatement  */
#line 985 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6506 "parser2.tab.c"
    break;

  case 427: /* Statement: LabeledStatement  */
#line 986 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6512 "parser2.tab.c"
    break;

  case 428: /* Statement: IfThenStatement  */
#line 987 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6518 "parser2.tab.c"
    break;

  case 429: /* Statement: IfThenElseStatement  */
#line 988 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6524 "parser2.tab.c"
    break;

  case 430: /* Statement: WhileStatement  */
#line 989 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6530 "parser2.tab.c"
    break;

  case 431: /* Statement: ForStatement  */
#line 990 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6536 "parser2.tab.c"
    break;

  case 432: /* StatementNoShortIf: StatementWithoutTrailingSubstatement  */
#line 992 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6542 "parser2.tab.c"
    break;

  case 433: /* StatementNoShortIf: LabeledStatementNoShortIf  */
#line 993 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6548 "parser2.tab.c"
    break;

  case 434: /* StatementNoShortIf: IfThenElseStatementNoShortIf  */
#line 994 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6554 "parser2.tab.c"
    break;

  case 435: /* StatementNoShortIf: WhileStatementNoShortIf  */
#line 995 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6560 "parser2.tab.c"
    break;

  case 436: /* StatementNoShortIf: ForStatementNoShortIf  */
#line 996 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6566 "parser2.tab.c"
    break;

  case 437: /* StatementWithoutTrailingSubstatement: Block  */
#line 998 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6572 "parser2.tab.c"
    break;

  case 438: /* StatementWithoutTrailingSubstatement: EmptyStatement  */
#line 999 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6578 "parser2.tab.c"
    break;

  case 439: /* StatementWithoutTrailingSubstatement: ExpressionStatement  */
#line 1000 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6584 "parser2.tab.c"
    break;

  case 440: /* StatementWithoutTrailingSubstatement: AssertStatement  */
#line 1001 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6590 "parser2.tab.c"
    break;

  case 441: /* StatementWithoutTrailingSubstatement: SwitchStatement  */
#line 1002 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6596 "parser2.tab.c"
    break;

  case 442: /* StatementWithoutTrailingSubstatement: DoStatement  */
#line 1003 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6602 "parser2.tab.c"
    break;

  case 443: /* StatementWithoutTrailingSubstatement: BreakStatement  */
#line 1004 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6608 "parser2.tab.c"
    break;

  case 444: /* StatementWithoutTrailingSubstatement: ContinueStatement  */
#line 1005 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6614 "parser2.tab.c"
    break;

  case 445: /* StatementWithoutTrailingSubstatement: ReturnStatement  */
#line 1006 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6620 "parser2.tab.c"
    break;

  case 446: /* StatementWithoutTrailingSubstatement: SynchronizedStatement  */
#line 1007 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6626 "parser2.tab.c"
    break;

  case 447: /* StatementWithoutTrailingSubstatement: ThrowStatement  */
#line 1008 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6632 "parser2.tab.c"
    break;

  case 448: /* StatementWithoutTrailingSubstatement: TryStatement  */
#line 1009 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6638 "parser2.tab.c"
    break;

  case 449: /* StatementWithoutTrailingSubstatement: YieldStatement  */
#line 1010 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6644 "parser2.tab.c"
    break;

  case 450: /* EmptyStatement: SEMICOLON  */
#line 1012 "parser2.y"
                                                {(yyval.typeinfo)=new Typeinfo; vector<string>p={}; (yyval.typeinfo)->tac=p;}
#line 6650 "parser2.tab.c"
    break;

  case 451: /* LabeledStatement: Identifier COLON Statement  */
#line 1014 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6656 "parser2.tab.c"
    break;

  case 452: /* LabeledStatementNoShortIf: Identifier COLON StatementNoShortIf  */
#line 1016 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6662 "parser2.tab.c"
    break;

  case 453: /* ExpressionStatement: StatementExpression SEMICOLON  */
#line 1019 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[-1].typeinfo)->tempname;}
#line 6668 "parser2.tab.c"
    break;

  case 454: /* StatementExpression: Assignment  */
#line 1021 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 6674 "parser2.tab.c"
    break;

  case 455: /* StatementExpression: PreIncrementExpression  */
#line 1022 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 6680 "parser2.tab.c"
    break;

  case 456: /* StatementExpression: PreDecrementExpression  */
#line 1023 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 6686 "parser2.tab.c"
    break;

  case 457: /* StatementExpression: PostIncrementExpression  */
#line 1024 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 6692 "parser2.tab.c"
    break;

  case 458: /* StatementExpression: PostDecrementExpression  */
#line 1025 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 6698 "parser2.tab.c"
    break;

  case 459: /* StatementExpression: MethodInvocation  */
#line 1026 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 6704 "parser2.tab.c"
    break;

  case 460: /* StatementExpression: ClassInstanceCreationExpression  */
#line 1027 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 6710 "parser2.tab.c"
    break;

  case 461: /* IfThenStatement: IF LRB Expression RRB Statement  */
#line 1029 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;int lv=labelvariable;string a=newlabel();string ret="if zero "+((yyvsp[-2].typeinfo))->tempname+gotoo(lv+1);(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,a);}
#line 6716 "parser2.tab.c"
    break;

  case 462: /* IfThenElseStatement: IF LRB Expression RRB StatementNoShortIf ELSE Statement  */
#line 1031 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;int lv=labelvariable;string a=newlabel();string ret="if zero "+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+1);(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,ret,(yyvsp[-2].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac);}
#line 6722 "parser2.tab.c"
    break;

  case 463: /* IfThenElseStatementNoShortIf: IF LRB Expression RRB StatementNoShortIf ELSE StatementNoShortIf  */
#line 1033 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;int lv=labelvariable;string a=newlabel();string ret="if zero "+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+1);(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,ret,(yyvsp[-2].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac);}
#line 6728 "parser2.tab.c"
    break;

  case 464: /* AssertStatement: ASSERT Expression SEMICOLON  */
#line 1035 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6734 "parser2.tab.c"
    break;

  case 465: /* AssertStatement: ASSERT Expression COLON Expression SEMICOLON  */
#line 1036 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 6740 "parser2.tab.c"
    break;

  case 466: /* SwitchStatement: SWITCH LRB Expression RRB SwitchBlock  */
#line 1038 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6746 "parser2.tab.c"
    break;

  case 467: /* SwitchBlock: LCB SwitchRule RCB  */
#line 1040 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6752 "parser2.tab.c"
    break;

  case 468: /* SwitchBlock: LCB SwitchRule OMSwitchRule RCB  */
#line 1041 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 6758 "parser2.tab.c"
    break;

  case 469: /* SwitchBlock: LCB RCB  */
#line 1042 "parser2.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6764 "parser2.tab.c"
    break;

  case 470: /* SwitchBlock: LCB OMSwitchLabelColon RCB  */
#line 1043 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6770 "parser2.tab.c"
    break;

  case 471: /* SwitchBlock: LCB OMSwitchBlockStatementGroup RCB  */
#line 1044 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6776 "parser2.tab.c"
    break;

  case 472: /* SwitchBlock: LCB OMSwitchBlockStatementGroup OMSwitchLabelColon RCB  */
#line 1045 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 6782 "parser2.tab.c"
    break;

  case 473: /* SwitchRule: SwitchLabel IMPLIES Expression SEMICOLON  */
#line 1047 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 6788 "parser2.tab.c"
    break;

  case 474: /* SwitchRule: SwitchLabel IMPLIES Block  */
#line 1048 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6794 "parser2.tab.c"
    break;

  case 475: /* SwitchRule: SwitchLabel IMPLIES ThrowStatement  */
#line 1049 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6800 "parser2.tab.c"
    break;

  case 476: /* SwitchBlockStatementGroup: SwitchLabel COLON BlockStatements  */
#line 1051 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6806 "parser2.tab.c"
    break;

  case 477: /* SwitchBlockStatementGroup: SwitchLabel COLON OMSwitchLabelColon BlockStatements  */
#line 1052 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6812 "parser2.tab.c"
    break;

  case 478: /* SwitchLabel: CASE CaseConstant  */
#line 1054 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6818 "parser2.tab.c"
    break;

  case 479: /* SwitchLabel: CASE CaseConstant OMCommaCaseConstant  */
#line 1055 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6824 "parser2.tab.c"
    break;

  case 480: /* SwitchLabel: DEFAULT  */
#line 1056 "parser2.y"
                                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6830 "parser2.tab.c"
    break;

  case 481: /* CaseConstant: ConditionalExpression  */
#line 1058 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6836 "parser2.tab.c"
    break;

  case 482: /* WhileStatement: WHILE LRB Expression RRB Statement  */
#line 1060 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; int c=labelvariable; string a=newlabel();string b=newlabel();string z=gotoo(c+2);string d="if zero "+(((yyvsp[-2].typeinfo))->tempname)+z;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,a,d,(yyvsp[0].typeinfo)->tac,gotoo(c+1),b);}
#line 6842 "parser2.tab.c"
    break;

  case 483: /* WhileStatementNoShortIf: WHILE LRB Expression RRB StatementNoShortIf  */
#line 1062 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; int c=labelvariable; string a=newlabel();string z=gotoo(c+2);string b=newlabel();string d="if zero "+(((yyvsp[-2].typeinfo))->tempname)+z;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,a,d,(yyvsp[0].typeinfo)->tac,gotoo(c+1),b);}
#line 6848 "parser2.tab.c"
    break;

  case 484: /* DoStatement: DO Statement WHILE LRB Expression RRB SEMICOLON  */
#line 1064 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; string p=gotoo(labelvariable); (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,p);}
#line 6854 "parser2.tab.c"
    break;

  case 485: /* ForStatement: BasicForStatement  */
#line 1066 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6860 "parser2.tab.c"
    break;

  case 486: /* ForStatement: EnhancedForStatement  */
#line 1067 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6866 "parser2.tab.c"
    break;

  case 487: /* ForStatementNoShortIf: BasicForStatementNoShortIf  */
#line 1069 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6872 "parser2.tab.c"
    break;

  case 488: /* ForStatementNoShortIf: EnhancedForStatementNoShortIf  */
#line 1070 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 6878 "parser2.tab.c"
    break;

  case 489: /* BasicForStatement: FOR LRB SEMICOLON SEMICOLON RRB Statement  */
#line 1072 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector(a,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 6884 "parser2.tab.c"
    break;

  case 490: /* BasicForStatement: FOR LRB SEMICOLON SEMICOLON ForUpdate RRB Statement  */
#line 1073 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector(a,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 6890 "parser2.tab.c"
    break;

  case 491: /* BasicForStatement: FOR LRB SEMICOLON Expression SEMICOLON RRB Statement  */
#line 1074 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-3].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-3].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 6896 "parser2.tab.c"
    break;

  case 492: /* BasicForStatement: FOR LRB SEMICOLON Expression SEMICOLON ForUpdate RRB Statement  */
#line 1075 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-4].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 6902 "parser2.tab.c"
    break;

  case 493: /* BasicForStatement: FOR LRB ForInit SEMICOLON SEMICOLON RRB Statement  */
#line 1076 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 6908 "parser2.tab.c"
    break;

  case 494: /* BasicForStatement: FOR LRB ForInit SEMICOLON SEMICOLON ForUpdate RRB Statement  */
#line 1077 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 6914 "parser2.tab.c"
    break;

  case 495: /* BasicForStatement: FOR LRB ForInit SEMICOLON Expression SEMICOLON RRB Statement  */
#line 1078 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-3].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,a,(yyvsp[-3].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 6920 "parser2.tab.c"
    break;

  case 496: /* BasicForStatement: FOR LRB ForInit SEMICOLON Expression SEMICOLON ForUpdate RRB Statement  */
#line 1079 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector((yyvsp[-6].typeinfo)->tac,a,(yyvsp[-4].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 6926 "parser2.tab.c"
    break;

  case 497: /* BasicForStatementNoShortIf: FOR LRB SEMICOLON SEMICOLON RRB StatementNoShortIf  */
#line 1081 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector(a,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 6932 "parser2.tab.c"
    break;

  case 498: /* BasicForStatementNoShortIf: FOR LRB SEMICOLON SEMICOLON ForUpdate RRB StatementNoShortIf  */
#line 1082 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector(a,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 6938 "parser2.tab.c"
    break;

  case 499: /* BasicForStatementNoShortIf: FOR LRB SEMICOLON Expression SEMICOLON RRB StatementNoShortIf  */
#line 1083 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-3].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-3].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 6944 "parser2.tab.c"
    break;

  case 500: /* BasicForStatementNoShortIf: FOR LRB SEMICOLON Expression SEMICOLON ForUpdate RRB StatementNoShortIf  */
#line 1084 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-4].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 6950 "parser2.tab.c"
    break;

  case 501: /* BasicForStatementNoShortIf: FOR LRB ForInit SEMICOLON SEMICOLON RRB StatementNoShortIf  */
#line 1085 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 6956 "parser2.tab.c"
    break;

  case 502: /* BasicForStatementNoShortIf: FOR LRB ForInit SEMICOLON SEMICOLON ForUpdate RRB StatementNoShortIf  */
#line 1086 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 6962 "parser2.tab.c"
    break;

  case 503: /* BasicForStatementNoShortIf: FOR LRB ForInit SEMICOLON Expression SEMICOLON RRB StatementNoShortIf  */
#line 1087 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-3].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,a,(yyvsp[-3].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 6968 "parser2.tab.c"
    break;

  case 504: /* BasicForStatementNoShortIf: FOR LRB ForInit SEMICOLON Expression SEMICOLON ForUpdate RRB StatementNoShortIf  */
#line 1088 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector((yyvsp[-6].typeinfo)->tac,a,(yyvsp[-4].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 6974 "parser2.tab.c"
    break;

  case 505: /* ForInit: StatementExpressionList  */
#line 1090 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6980 "parser2.tab.c"
    break;

  case 506: /* ForInit: LocalVariableDeclaration  */
#line 1091 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6986 "parser2.tab.c"
    break;

  case 507: /* ForUpdate: StatementExpressionList  */
#line 1093 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6992 "parser2.tab.c"
    break;

  case 508: /* StatementExpressionList: StatementExpression  */
#line 1095 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6998 "parser2.tab.c"
    break;

  case 509: /* StatementExpressionList: StatementExpression OMCommaStatementExpression  */
#line 1096 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7004 "parser2.tab.c"
    break;

  case 510: /* EnhancedForStatement: FOR LRB LocalVariableDeclaration COLON Expression RRB Statement  */
#line 1098 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-2].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-4].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7010 "parser2.tab.c"
    break;

  case 511: /* EnhancedForStatementNoShortIf: FOR LRB LocalVariableDeclaration COLON Expression RRB StatementNoShortIf  */
#line 1100 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-2].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-4].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7016 "parser2.tab.c"
    break;

  case 512: /* BreakStatement: BREAK SEMICOLON  */
#line 1102 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;string p=gotoo(labelvariable+1); (yyval.typeinfo)->tac={p};}
#line 7022 "parser2.tab.c"
    break;

  case 513: /* BreakStatement: BREAK Identifier SEMICOLON  */
#line 1103 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;string p=gotoo(labelvariable+1); (yyval.typeinfo)->tac={p};}
#line 7028 "parser2.tab.c"
    break;

  case 514: /* YieldStatement: YIELD Expression SEMICOLON  */
#line 1106 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7034 "parser2.tab.c"
    break;

  case 515: /* ContinueStatement: CONTINUE SEMICOLON  */
#line 1108 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;string p=gotoo(labelvariable); (yyval.typeinfo)->tac={p};}
#line 7040 "parser2.tab.c"
    break;

  case 516: /* ContinueStatement: CONTINUE Identifier SEMICOLON  */
#line 1109 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;string p=gotoo(labelvariable); (yyval.typeinfo)->tac={p};}
#line 7046 "parser2.tab.c"
    break;

  case 517: /* ReturnStatement: RETURN SEMICOLON  */
#line 1112 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo;string p=gotoo(labelvariable+1); (yyval.typeinfo)->tac={p};}
#line 7052 "parser2.tab.c"
    break;

  case 518: /* ReturnStatement: RETURN Expression SEMICOLON  */
#line 1113 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;string p=gotoo(labelvariable+1); (yyval.typeinfo)->tac=concvector(p,(yyvsp[-1].typeinfo)->tac);}
#line 7058 "parser2.tab.c"
    break;

  case 519: /* ThrowStatement: THROW Expression SEMICOLON  */
#line 1115 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7064 "parser2.tab.c"
    break;

  case 520: /* SynchronizedStatement: SYNCHRONIZED LRB Expression RRB Block  */
#line 1117 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7070 "parser2.tab.c"
    break;

  case 521: /* TryStatement: TRY Block Catches  */
#line 1119 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7076 "parser2.tab.c"
    break;

  case 522: /* TryStatement: TRY Block Finally  */
#line 1120 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7082 "parser2.tab.c"
    break;

  case 523: /* TryStatement: TRY Block Catches Finally  */
#line 1121 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7088 "parser2.tab.c"
    break;

  case 524: /* TryStatement: TryWithResourcesStatement  */
#line 1122 "parser2.y"
                                                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7094 "parser2.tab.c"
    break;

  case 525: /* Catches: CatchClause  */
#line 1124 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7100 "parser2.tab.c"
    break;

  case 526: /* Catches: CatchClause OMCatchClause  */
#line 1125 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7106 "parser2.tab.c"
    break;

  case 527: /* CatchClause: CATCH LRB CatchFormalParameter RRB Block  */
#line 1127 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7112 "parser2.tab.c"
    break;

  case 528: /* CatchFormalParameter: CatchType VariableDeclaratorId  */
#line 1129 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7118 "parser2.tab.c"
    break;

  case 529: /* CatchFormalParameter: OMClassModifier CatchType VariableDeclaratorId  */
#line 1130 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7124 "parser2.tab.c"
    break;

  case 530: /* CatchType: Identifier  */
#line 1132 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7130 "parser2.tab.c"
    break;

  case 531: /* CatchType: Identifier OMOrClassType  */
#line 1133 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7136 "parser2.tab.c"
    break;

  case 532: /* Finally: FINALLY Block  */
#line 1136 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7142 "parser2.tab.c"
    break;

  case 533: /* TryWithResourcesStatement: TRY ResourceSpecification Block  */
#line 1138 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7148 "parser2.tab.c"
    break;

  case 534: /* TryWithResourcesStatement: TRY ResourceSpecification Block Finally  */
#line 1139 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7154 "parser2.tab.c"
    break;

  case 535: /* TryWithResourcesStatement: TRY ResourceSpecification Block Catches  */
#line 1140 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7160 "parser2.tab.c"
    break;

  case 536: /* TryWithResourcesStatement: TRY ResourceSpecification Block Catches Finally  */
#line 1141 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7166 "parser2.tab.c"
    break;

  case 537: /* ResourceSpecification: LRB ResourceList RRB  */
#line 1143 "parser2.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7172 "parser2.tab.c"
    break;

  case 538: /* ResourceList: Resource  */
#line 1145 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7178 "parser2.tab.c"
    break;

  case 539: /* ResourceList: OMSemicolonResource  */
#line 1146 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7184 "parser2.tab.c"
    break;

  case 540: /* Resource: LocalVariableDeclaration  */
#line 1148 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7190 "parser2.tab.c"
    break;

  case 541: /* Resource: VariableAccess  */
#line 1149 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7196 "parser2.tab.c"
    break;

  case 542: /* Primary: PrimaryNoNewArray  */
#line 1151 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7202 "parser2.tab.c"
    break;

  case 543: /* Primary: ArrayCreationExpression  */
#line 1152 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7208 "parser2.tab.c"
    break;

  case 544: /* PrimaryNoNewArray: Literal  */
#line 1154 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7214 "parser2.tab.c"
    break;

  case 545: /* PrimaryNoNewArray: ClassLiteral  */
#line 1155 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7220 "parser2.tab.c"
    break;

  case 546: /* PrimaryNoNewArray: THIS  */
#line 1156 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();(yyval.typeinfo)->tempname="this";}
#line 7226 "parser2.tab.c"
    break;

  case 547: /* PrimaryNoNewArray: Identifier DOT THIS  */
#line 1157 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string x=(yyvsp[-2].str); (yyval.typeinfo)->tac=emptyvector();(yyval.typeinfo)->tempname=x;}
#line 7232 "parser2.tab.c"
    break;

  case 548: /* PrimaryNoNewArray: ExpressionName DOT THIS  */
#line 1158 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[-2].typeinfo);}
#line 7238 "parser2.tab.c"
    break;

  case 549: /* PrimaryNoNewArray: LRB Expression RRB  */
#line 1159 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[-1].typeinfo);}
#line 7244 "parser2.tab.c"
    break;

  case 550: /* PrimaryNoNewArray: ClassInstanceCreationExpression  */
#line 1160 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7250 "parser2.tab.c"
    break;

  case 551: /* PrimaryNoNewArray: FieldAccess  */
#line 1161 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7256 "parser2.tab.c"
    break;

  case 552: /* PrimaryNoNewArray: ArrayAccess  */
#line 1162 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7262 "parser2.tab.c"
    break;

  case 553: /* PrimaryNoNewArray: MethodInvocation  */
#line 1163 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7268 "parser2.tab.c"
    break;

  case 554: /* PrimaryNoNewArray: MethodReference  */
#line 1164 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7274 "parser2.tab.c"
    break;

  case 555: /* ClassLiteral: Identifier DOT CLASS  */
#line 1166 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7280 "parser2.tab.c"
    break;

  case 556: /* ClassLiteral: ExpressionName DOT CLASS  */
#line 1167 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7286 "parser2.tab.c"
    break;

  case 557: /* ClassLiteral: Identifier OMPSB DOT CLASS  */
#line 1168 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7292 "parser2.tab.c"
    break;

  case 558: /* ClassLiteral: ExpressionName OMPSB DOT CLASS  */
#line 1169 "parser2.y"
                                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7298 "parser2.tab.c"
    break;

  case 559: /* ClassLiteral: UnannPrimitiveType DOT CLASS  */
#line 1170 "parser2.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7304 "parser2.tab.c"
    break;

  case 560: /* ClassLiteral: VOID DOT CLASS  */
#line 1171 "parser2.y"
                                                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7310 "parser2.tab.c"
    break;

  case 561: /* ClassInstanceCreationExpression: UnqualifiedClassInstanceCreationExpression  */
#line 1173 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7316 "parser2.tab.c"
    break;

  case 562: /* ClassInstanceCreationExpression: Identifier DOT UnqualifiedClassInstanceCreationExpression  */
#line 1174 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7322 "parser2.tab.c"
    break;

  case 563: /* ClassInstanceCreationExpression: ExpressionName DOT UnqualifiedClassInstanceCreationExpression  */
#line 1175 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7328 "parser2.tab.c"
    break;

  case 564: /* ClassInstanceCreationExpression: Primary DOT UnqualifiedClassInstanceCreationExpression  */
#line 1176 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7334 "parser2.tab.c"
    break;

  case 565: /* UnqualifiedClassInstanceCreationExpression: NEW ClassOrInterfaceTypeToInstantiate LRB RRB  */
#line 1178 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 7340 "parser2.tab.c"
    break;

  case 566: /* UnqualifiedClassInstanceCreationExpression: NEW ClassOrInterfaceTypeToInstantiate LRB RRB ClassBody  */
#line 1179 "parser2.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7346 "parser2.tab.c"
    break;

  case 567: /* UnqualifiedClassInstanceCreationExpression: NEW ClassOrInterfaceTypeToInstantiate LRB ArgumentList RRB  */
#line 1180 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 7352 "parser2.tab.c"
    break;

  case 568: /* UnqualifiedClassInstanceCreationExpression: NEW ClassOrInterfaceTypeToInstantiate LRB ArgumentList RRB ClassBody  */
#line 1181 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7358 "parser2.tab.c"
    break;

  case 569: /* ClassOrInterfaceTypeToInstantiate: Identifier  */
#line 1183 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7364 "parser2.tab.c"
    break;

  case 570: /* ClassOrInterfaceTypeToInstantiate: Identifier OMDotIdentifier  */
#line 1184 "parser2.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7370 "parser2.tab.c"
    break;

  case 571: /* FieldAccess: Primary DOT Identifier  */
#line 1186 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7376 "parser2.tab.c"
    break;

  case 572: /* FieldAccess: SUPER DOT Identifier  */
#line 1187 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7382 "parser2.tab.c"
    break;

  case 573: /* FieldAccess: Identifier DOT SUPER DOT Identifier  */
#line 1188 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7388 "parser2.tab.c"
    break;

  case 574: /* FieldAccess: ExpressionName DOT SUPER DOT Identifier  */
#line 1189 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 7394 "parser2.tab.c"
    break;

  case 575: /* ArrayAccess: Identifier LSB Expression RSB  */
#line 1191 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7400 "parser2.tab.c"
    break;

  case 576: /* ArrayAccess: ExpressionName LSB Expression RSB  */
#line 1192 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 7406 "parser2.tab.c"
    break;

  case 577: /* ArrayAccess: PrimaryNoNewArray LSB Expression RSB  */
#line 1193 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 7412 "parser2.tab.c"
    break;

  case 578: /* MethodInvocation: MethodName LRB ArgumentList RRB  */
#line 1195 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 7418 "parser2.tab.c"
    break;

  case 579: /* MethodInvocation: MethodName LRB RRB  */
#line 1196 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 7424 "parser2.tab.c"
    break;

  case 580: /* MethodInvocation: Identifier DOT Identifier LRB RRB  */
#line 1197 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7430 "parser2.tab.c"
    break;

  case 581: /* MethodInvocation: Identifier DOT Identifier LRB ArgumentList RRB  */
#line 1198 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7436 "parser2.tab.c"
    break;

  case 582: /* MethodInvocation: ExpressionName DOT Identifier LRB RRB  */
#line 1199 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 7442 "parser2.tab.c"
    break;

  case 583: /* MethodInvocation: ExpressionName DOT Identifier LRB ArgumentList RRB  */
#line 1200 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 7448 "parser2.tab.c"
    break;

  case 584: /* MethodInvocation: Primary DOT Identifier LRB RRB  */
#line 1201 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 7454 "parser2.tab.c"
    break;

  case 585: /* MethodInvocation: Primary DOT Identifier LRB ArgumentList RRB  */
#line 1202 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-5].typeinfo)->tac;}
#line 7460 "parser2.tab.c"
    break;

  case 586: /* MethodInvocation: SUPER DOT Identifier LRB RRB  */
#line 1203 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7466 "parser2.tab.c"
    break;

  case 587: /* MethodInvocation: SUPER DOT Identifier LRB ArgumentList RRB  */
#line 1204 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7472 "parser2.tab.c"
    break;

  case 588: /* MethodInvocation: Identifier DOT SUPER DOT Identifier LRB RRB  */
#line 1205 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7478 "parser2.tab.c"
    break;

  case 589: /* MethodInvocation: Identifier DOT SUPER DOT Identifier LRB ArgumentList RRB  */
#line 1206 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7484 "parser2.tab.c"
    break;

  case 590: /* MethodInvocation: ExpressionName DOT SUPER DOT Identifier LRB RRB  */
#line 1207 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-6].typeinfo)->tac;}
#line 7490 "parser2.tab.c"
    break;

  case 591: /* MethodInvocation: ExpressionName DOT SUPER DOT Identifier LRB ArgumentList RRB  */
#line 1208 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-7].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 7496 "parser2.tab.c"
    break;

  case 592: /* ArgumentList: Expression  */
#line 1211 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7502 "parser2.tab.c"
    break;

  case 593: /* ArgumentList: Expression OMCommaExpression  */
#line 1212 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7508 "parser2.tab.c"
    break;

  case 594: /* MethodReference: Identifier DOUBLECOLON Identifier  */
#line 1214 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7514 "parser2.tab.c"
    break;

  case 595: /* MethodReference: ExpressionName DOUBLECOLON Identifier  */
#line 1215 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 7520 "parser2.tab.c"
    break;

  case 596: /* MethodReference: Primary DOUBLECOLON Identifier  */
#line 1216 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7526 "parser2.tab.c"
    break;

  case 597: /* MethodReference: UnannArrayType DOUBLECOLON Identifier  */
#line 1217 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7532 "parser2.tab.c"
    break;

  case 598: /* MethodReference: SUPER DOUBLECOLON Identifier  */
#line 1218 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7538 "parser2.tab.c"
    break;

  case 599: /* MethodReference: Identifier DOT SUPER DOUBLECOLON Identifier  */
#line 1219 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7544 "parser2.tab.c"
    break;

  case 600: /* MethodReference: ExpressionName DOT SUPER DOUBLECOLON Identifier  */
#line 1220 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 7550 "parser2.tab.c"
    break;

  case 601: /* MethodReference: UnannArrayType DOUBLECOLON NEW  */
#line 1221 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7556 "parser2.tab.c"
    break;

  case 602: /* ArrayCreationExpression: NEW PrimitiveType OMDimExpr  */
#line 1223 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7562 "parser2.tab.c"
    break;

  case 603: /* ArrayCreationExpression: NEW PrimitiveType OMDimExpr OMPSB  */
#line 1224 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7568 "parser2.tab.c"
    break;

  case 604: /* ArrayCreationExpression: NEW Identifier OMDimExpr  */
#line 1225 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7574 "parser2.tab.c"
    break;

  case 605: /* ArrayCreationExpression: NEW Identifier OMDimExpr OMPSB  */
#line 1226 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7580 "parser2.tab.c"
    break;

  case 606: /* ArrayCreationExpression: NEW PrimitiveType OMPSB ArrayInitializer  */
#line 1227 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7586 "parser2.tab.c"
    break;

  case 607: /* ArrayCreationExpression: NEW Identifier OMPSB ArrayInitializer  */
#line 1228 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7592 "parser2.tab.c"
    break;

  case 608: /* DimExpr: LSB Expression RSB  */
#line 1231 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[-1].typeinfo);}
#line 7598 "parser2.tab.c"
    break;

  case 609: /* Expression: AssignmentExpression  */
#line 1233 "parser2.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7604 "parser2.tab.c"
    break;

  case 610: /* AssignmentExpression: ConditionalExpression  */
#line 1235 "parser2.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7610 "parser2.tab.c"
    break;

  case 611: /* AssignmentExpression: Assignment  */
#line 1236 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7616 "parser2.tab.c"
    break;

  case 612: /* Assignment: LeftHandSide AssignmentOperator Expression  */
#line 1238 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string p=((yyvsp[-2].typeinfo))->tempname+" = "+((yyvsp[0].typeinfo))->tempname;(yyval.typeinfo)->tempname=((yyvsp[-2].typeinfo))->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,p);}
#line 7622 "parser2.tab.c"
    break;

  case 613: /* LeftHandSide: ExpressionName  */
#line 1240 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7628 "parser2.tab.c"
    break;

  case 614: /* LeftHandSide: Identifier  */
#line 1241 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; string x=(yyvsp[0].str); string p=newtemp();(yyval.typeinfo)->tempname=p;p=p+" = "+x; (yyval.typeinfo)->tac={p};}
#line 7634 "parser2.tab.c"
    break;

  case 615: /* LeftHandSide: FieldAccess  */
#line 1242 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7640 "parser2.tab.c"
    break;

  case 616: /* LeftHandSide: ArrayAccess  */
#line 1243 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7646 "parser2.tab.c"
    break;

  case 617: /* AssignmentOperator: ASSIGNMENTOPERATOR  */
#line 1245 "parser2.y"
                                                                                {(yyval.str)=(yyvsp[0].str);}
#line 7652 "parser2.tab.c"
    break;

  case 618: /* ConditionalExpression: ConditionalOrExpression  */
#line 1247 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7658 "parser2.tab.c"
    break;

  case 619: /* ConditionalExpression: ConditionalOrExpression QM Expression COLON ConditionalExpression  */
#line 1248 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;int lv=labelvariable;string a=newlabel();string ret="if zero "+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+1);(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,ret,(yyvsp[-2].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac);}
#line 7664 "parser2.tab.c"
    break;

  case 620: /* ConditionalOrExpression: ConditionalAndExpression  */
#line 1250 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7670 "parser2.tab.c"
    break;

  case 621: /* ConditionalOrExpression: ConditionalOrExpression OR ConditionalAndExpression  */
#line 1251 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" || "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7676 "parser2.tab.c"
    break;

  case 622: /* ConditionalAndExpression: InclusiveOrExpression  */
#line 1253 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7682 "parser2.tab.c"
    break;

  case 623: /* ConditionalAndExpression: ConditionalAndExpression AND InclusiveOrExpression  */
#line 1254 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" && "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7688 "parser2.tab.c"
    break;

  case 624: /* InclusiveOrExpression: ExclusiveOrExpression  */
#line 1256 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7694 "parser2.tab.c"
    break;

  case 625: /* InclusiveOrExpression: InclusiveOrExpression BITOR ExclusiveOrExpression  */
#line 1257 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" | "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7700 "parser2.tab.c"
    break;

  case 626: /* ExclusiveOrExpression: AndExpression  */
#line 1259 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7706 "parser2.tab.c"
    break;

  case 627: /* ExclusiveOrExpression: ExclusiveOrExpression BITXOR AndExpression  */
#line 1260 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" ^ "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7712 "parser2.tab.c"
    break;

  case 628: /* AndExpression: EqualityExpression  */
#line 1262 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7718 "parser2.tab.c"
    break;

  case 629: /* AndExpression: AndExpression BITAND EqualityExpression  */
#line 1263 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" & "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7724 "parser2.tab.c"
    break;

  case 630: /* EqualityExpression: RelationalExpression  */
#line 1265 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7730 "parser2.tab.c"
    break;

  case 631: /* EqualityExpression: EqualityExpression DOUBLEEQUAL RelationalExpression  */
#line 1266 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" == "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7736 "parser2.tab.c"
    break;

  case 632: /* EqualityExpression: EqualityExpression NE RelationalExpression  */
#line 1267 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" != "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7742 "parser2.tab.c"
    break;

  case 633: /* RelationalExpression: ShiftExpression  */
#line 1269 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7748 "parser2.tab.c"
    break;

  case 634: /* RelationalExpression: RelationalExpression LT ShiftExpression  */
#line 1270 "parser2.y"
                                                                                         {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" < "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7754 "parser2.tab.c"
    break;

  case 635: /* RelationalExpression: RelationalExpression GT ShiftExpression  */
#line 1271 "parser2.y"
                                                                                         {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" > "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7760 "parser2.tab.c"
    break;

  case 636: /* RelationalExpression: RelationalExpression LTE ShiftExpression  */
#line 1272 "parser2.y"
                                                                                         {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" <= "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7766 "parser2.tab.c"
    break;

  case 637: /* RelationalExpression: RelationalExpression GTE ShiftExpression  */
#line 1273 "parser2.y"
                                                                                         {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" >= "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7772 "parser2.tab.c"
    break;

  case 638: /* RelationalExpression: InstanceofExpression  */
#line 1274 "parser2.y"
                                                                                                         {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7778 "parser2.tab.c"
    break;

  case 639: /* InstanceofExpression: RelationalExpression INSTANCEOF ReferenceType  */
#line 1276 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" instanceof "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7784 "parser2.tab.c"
    break;

  case 640: /* ShiftExpression: AdditiveExpression  */
#line 1278 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7790 "parser2.tab.c"
    break;

  case 641: /* ShiftExpression: ShiftExpression LSHIFT AdditiveExpression  */
#line 1279 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" << "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7796 "parser2.tab.c"
    break;

  case 642: /* ShiftExpression: ShiftExpression RSHIFT AdditiveExpression  */
#line 1280 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" >> "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7802 "parser2.tab.c"
    break;

  case 643: /* ShiftExpression: ShiftExpression THREEGT AdditiveExpression  */
#line 1281 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" >>> "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7808 "parser2.tab.c"
    break;

  case 644: /* AdditiveExpression: MultiplicativeExpression  */
#line 1283 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7814 "parser2.tab.c"
    break;

  case 645: /* AdditiveExpression: AdditiveExpression PLUS MultiplicativeExpression  */
#line 1284 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" + "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7820 "parser2.tab.c"
    break;

  case 646: /* AdditiveExpression: AdditiveExpression MINUS MultiplicativeExpression  */
#line 1285 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" - "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7826 "parser2.tab.c"
    break;

  case 647: /* MultiplicativeExpression: UnaryExpression  */
#line 1287 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7832 "parser2.tab.c"
    break;

  case 648: /* MultiplicativeExpression: MultiplicativeExpression MULTIPLY UnaryExpression  */
#line 1288 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" * "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7838 "parser2.tab.c"
    break;

  case 649: /* MultiplicativeExpression: MultiplicativeExpression DIVIDE UnaryExpression  */
#line 1289 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" / "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7844 "parser2.tab.c"
    break;

  case 650: /* MultiplicativeExpression: MultiplicativeExpression PERCENT UnaryExpression  */
#line 1290 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" % "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 7850 "parser2.tab.c"
    break;

  case 651: /* UnaryExpression: PreIncrementExpression  */
#line 1292 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7856 "parser2.tab.c"
    break;

  case 652: /* UnaryExpression: PreDecrementExpression  */
#line 1293 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7862 "parser2.tab.c"
    break;

  case 653: /* UnaryExpression: PLUS UnaryExpression  */
#line 1294 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7868 "parser2.tab.c"
    break;

  case 654: /* UnaryExpression: MINUS UnaryExpression  */
#line 1295 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+" - "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);}
#line 7874 "parser2.tab.c"
    break;

  case 655: /* UnaryExpression: UnaryExpressionNotPlusMinus  */
#line 1296 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7880 "parser2.tab.c"
    break;

  case 656: /* PreIncrementExpression: INCREAMENT UnaryExpression  */
#line 1298 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[0].typeinfo)->tempname+" + 1 ";(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);}
#line 7886 "parser2.tab.c"
    break;

  case 657: /* PreDecrementExpression: DECREAMENT UnaryExpression  */
#line 1300 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[0].typeinfo)->tempname+" - 1 ";(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);}
#line 7892 "parser2.tab.c"
    break;

  case 658: /* UnaryExpressionNotPlusMinus: PostfixExpression  */
#line 1302 "parser2.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7898 "parser2.tab.c"
    break;

  case 659: /* UnaryExpressionNotPlusMinus: TILDA UnaryExpression  */
#line 1303 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+" ~ "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);}
#line 7904 "parser2.tab.c"
    break;

  case 660: /* UnaryExpressionNotPlusMinus: EXCLAM UnaryExpression  */
#line 1304 "parser2.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+" ! "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);}
#line 7910 "parser2.tab.c"
    break;

  case 661: /* UnaryExpressionNotPlusMinus: CastExpression  */
#line 1305 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7916 "parser2.tab.c"
    break;

  case 662: /* UnaryExpressionNotPlusMinus: SwitchExpression  */
#line 1306 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7922 "parser2.tab.c"
    break;

  case 663: /* PostfixExpression: Primary  */
#line 1308 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7928 "parser2.tab.c"
    break;

  case 664: /* PostfixExpression: Identifier  */
#line 1309 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; string a=(yyvsp[0].str); string b=newtemp();(yyval.typeinfo)->tempname=b;b=b+" = "+a;(yyval.typeinfo)->tac={b};(yyval.typeinfo)->tac={b};}
#line 7934 "parser2.tab.c"
    break;

  case 665: /* PostfixExpression: ExpressionName  */
#line 1310 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7940 "parser2.tab.c"
    break;

  case 666: /* PostfixExpression: PostIncrementExpression  */
#line 1311 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7946 "parser2.tab.c"
    break;

  case 667: /* PostfixExpression: PostDecrementExpression  */
#line 1312 "parser2.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7952 "parser2.tab.c"
    break;

  case 668: /* PostIncrementExpression: PostfixExpression INCREAMENT  */
#line 1314 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-1].typeinfo)->tempname+" + 1 ";(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,a);}
#line 7958 "parser2.tab.c"
    break;

  case 669: /* PostDecrementExpression: PostfixExpression DECREAMENT  */
#line 1316 "parser2.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-1].typeinfo)->tempname+" - 1 ";(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,a);}
#line 7964 "parser2.tab.c"
    break;

  case 670: /* CastExpression: LRB PrimitiveType RRB UnaryExpression  */
#line 1318 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);}
#line 7970 "parser2.tab.c"
    break;

  case 671: /* CastExpression: LRB UnannArrayType RRB UnaryExpressionNotPlusMinus  */
#line 1319 "parser2.y"
                                                                                                    {(yyval.typeinfo)=new Typeinfo; string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);}
#line 7976 "parser2.tab.c"
    break;

  case 672: /* CastExpression: LRB UnannArrayType OMAdditionalBound RRB UnaryExpressionNotPlusMinus  */
#line 1320 "parser2.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);}
#line 7982 "parser2.tab.c"
    break;

  case 673: /* SwitchExpression: SWITCH LRB Expression RRB SwitchBlock  */
#line 1322 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7988 "parser2.tab.c"
    break;

  case 674: /* VariableAccess: ExpressionName  */
#line 1324 "parser2.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 7994 "parser2.tab.c"
    break;

  case 675: /* VariableAccess: Identifier  */
#line 1325 "parser2.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; string a=(yyvsp[0].str); string b=newtemp();(yyval.typeinfo)->tempname=b;b=b+" = "+a;(yyval.typeinfo)->tac={b};(yyval.typeinfo)->tac={b};}
#line 8000 "parser2.tab.c"
    break;

  case 676: /* VariableAccess: FieldAccess  */
#line 1326 "parser2.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 8006 "parser2.tab.c"
    break;


#line 8010 "parser2.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1328 "parser2.y"

int main (int argc,char*argv[]) {
if(argc <= 1){
		cerr<<"Error: no input files\n";
		return -1;
	}
    bool inputtaken=false,verbose=false;
    int inputindex;
	for(int i=1;i<argc;i++)
    {
         if(!strcmp(argv[i],"--input"))
         {
            if(!inputtaken)
            {
                inputindex=i+1;
                inputtaken=true;
                i++;
            }
            else{
                cerr<<" You can't give two input files\n";
                return 0;
            }
         }
         else if(!strcmp(argv[i],"--verbose"))
         {
            verbose=true;
         }
         else if((!strcmp(argv[i],"--h"))||(!strcmp(argv[i],"--help")))
         {
            cerr<<"Use following commands\n";
            cout<<"to give inputfile name : --input <inputfilename>\n";
            cout<<"to give verbose : --verbose \n";
            cout<<"to seek help : --h or --help\n";
            cout<<"Input file is .java and output file is .csv\n";

         }
         else{
            cerr<<"Invalid Arguments\n";
            cout<<"Use following commands\n";
            cout<<"to give inputfile name : --input <inputfilename>\n";
            cout<<"to give verbose : --verbose \n";
            cout<<"to seek help : --h or --help\n";
            cout<<"Input file is .java and output file is .csv\n";
         }
    }
    if(!inputtaken){
        cerr<<"You must enter input filename\n";
        cerr<<"Type --help\n";
    }
    yyin = fopen(argv[inputindex], "r");
    dotfile = fopen("TAC.txt", "w");
		
	if(yyin == NULL){
		cerr<<"Error: cannot open file "<<argv[inputindex]<<"\n";
	}
    if(verbose)
    {
        cout<<"Parse started\n";
        cout<<"Parsing file.....\n";
    }




    yyparse();

}
void yyerror (const char *s) {cerr<<"Error on Line "<<line<<endl;}
