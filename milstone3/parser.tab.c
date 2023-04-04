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
#line 1 "parser.y"

#include <iostream>
#include <string>
#include <vector>
#include<cstring>
#include<bits/stdc++.h>
// #include "sym.h"
using namespace std;

#define YYERROR_VERBOSE

void yyerror (const char *s);
FILE* dotfile;
extern long long int line;
extern int yylex();
extern int yyrestart(FILE*);
extern FILE* yyin;
struct Node {

    string label, value, expressionLabel;
    vector< Node* > children;
};




struct symentry;
struct symtable;
struct symentry
{
    string maintype;
    int linenumber;
    int offset;
    string type;     // identifier,method,record,enum,
    string modifier; // public,private
    string lexeme;
    int size;
    string scope;
    // int level;

	vector<int>arrdims;
    int order;
    string primtype;
    int exprvalue;

    vector<string> funcargtype;
		string argcon;
    string funcrettype;
    symtable *name; // for method,record,class,...
};
struct symtable
{
    symtable *parent;
    map<string, symentry* > m;
    vector< symtable* > childscope;
    string type;
    string scope; //1a
};

symtable *curr;
symtable *createtable()
{
    symtable *a = new symtable;
    return a;
}
symentry *lookup(string a)
{
    symtable *c = curr;
    while (c && c->m.find(a) == c->m.end())
        c = c->parent;
    if (c)
    {
        return c->m[a];
    }
    return NULL;
}

symentry *samelookup(string a)
{
    symtable *c = curr;
    if (c && c->m.find(a) != c->m.end())
    {
        return c->m[a];
    }
    return NULL;
}

void insertmethod(string lexeme, string type, string returntype, vector<string> argtype,symtable* name,string modifier,int linen) // type=method,record,constructorconstructor
{

    symentry *a = new symentry;
		if(!samelookup(lexeme) || lexeme == "for"){
			curr->m[lexeme] = a;
			a->type=type;
			a->funcrettype=returntype;
			a->funcargtype=argtype;
			int i;
			for(i =0;i<argtype.size()-1;i++){
				a->argcon = a->argcon + argtype[i] + ",";
			}
			a->argcon = a->argcon + argtype[i];
			a->lexeme=lexeme;
			a->modifier = modifier;
			a->name=name;
			a->scope=curr->scope;
			a->linenumber = linen;
		}
		else{
			cout<< "Error: Method is already declared "<<lexeme<<endl;
		}
}
void insertclass(string lexeme,string type,string modifier,symtable*name,int linen)
{
    symentry *a = new symentry;
		if(!samelookup(lexeme)|| lexeme == "for"|| lexeme == "statement"){
			curr->m[lexeme] = a;
			a->type=type;
			a->lexeme=lexeme;
			a->modifier=modifier;
			a->name=name;
			a->scope=curr->scope;
			a->linenumber = linen;
		}
		else{
			cout<< "Error: Method is already declared "<<lexeme<<endl;
		}
}
int sizeoftype(string x){
	if(x=="int")
	return 4;
	else if(x=="float")
	return 4;
	else if(x=="double")
	return 8;
	else if(x== "char")
	return 1;
	else if(x=="long")
	return 8;
	else if(x=="short")
	return 2;
	else if(x=="byte")
	return 1;
	else if(x=="boolean")
	return 1;
	else
	return 0;
}
void insertidentifier(string lexeme,string type,string modifier,int linen)
{
    symentry *a = new symentry;
		if(!samelookup(lexeme)){
    curr->m[lexeme] = a;
    a->lexeme=lexeme;
    a->type=type;
    a->modifier=modifier;
		a->scope=curr->scope;
		a->linenumber = linen;
		a->size=sizeoftype(type);
		}
		else{
			cout<< "Error: Method is already declared "<<lexeme<<endl;
		}
}

void insertidentifier(string lexeme,string type,string primtype,string modifier,int linen,int order,vector<int>dims)
{
    symentry *a = new symentry;
		if(!samelookup(lexeme)){
    curr->m[lexeme] = a;
    a->lexeme=lexeme;
    a->primtype=primtype;
    a->type=type;
    a->modifier=modifier;
		a->scope=curr->scope;
		a->linenumber = linen;
        a->order=order;
        a->arrdims=dims;
		a->size=sizeoftype(primtype);
		}
		else{
			cout<< "Error: identifier is already declared "<<lexeme<<endl;
		}
}

void goparent()
{
    curr = curr->parent;
}
symtable *createscope(string type)
{
    symtable *a = new symtable;
    curr->childscope.push_back(a);
    a->parent = curr;
    a->type=type;
		a->scope = curr->scope+"_"+type;
    return a;
}
void changescope(symtable *a)
{
    curr = a;
}
string type_change(string a,string b){
	if(a=="double" || b=="double"){
        return "double";
    }
    else if(a=="float" || b=="float"){
        return "float";
    }
    else if(a=="long" || b=="long"){
        return "long";
    }
    else if(a=="int" || b=="int"){
        return "int";
    }
    else if(a=="short" || b=="short"){
        return "short";
    }
    else if(a=="byte" || b=="byte"){
        return "byte";
    }
    else if(a=="string" || b=="string"){
        return "string";
    }
    else{
        return "NULL";
    }
}

void type_check(string a,string b,int line){
	if(a == b){
		return ;
	}
	if(a=="class"||b=="class"){
		return;
	}
	if((a=="int"&&(b=="char"||b=="boolean"||b=="double"||b=="float"||b=="byte"||b=="short"))||(b=="int"&&(a=="char"||a=="boolean"||a=="double"||a=="float"||a=="byte"||a=="short"))){
		return;
	}
	if(a=="string"||b=="string"){
		return;
	}
	else{
		cout<<"Error: incompatible type "<<a <<" and "<<b <<" in Line no."<<line;
		return;
	}
}

void prints(symtable* s){
	for(auto z:s->m){
		cout<<z.first<<" "<<z.second->type<<" "<<z.second->funcrettype<<" "<<z.second->argcon<<" "<<z.second->scope<<" "<<z.second->linenumber<<" "<<z.second->size<<"\n";
	}
}
// void dfs(symtable* u)
// {
// 		if(u)
// 		{
// 			// prints(u);
// 			for(auto z:u->m){
// 				symtable* temp = z.second->name;
// 				cout<<z.first<<" "<<z.second->type<<" "<<z.second->funcrettype<<" "<<z.second->argcon<<" "<<z.second->scope<<" "<<z.second->linenumber<<" "<<z.second->size<<"\n";
// 				if(temp)
// 				{
// 					dfs(temp);
// 				}
// 			}
// 		}
// 		return;
// }



Node *root = NULL;

Node *createNode(string label, string value, vector <Node *> children) {

    Node *newNode = new Node;
    newNode->label = label;
    newNode->value = value;
    newNode->children = children;
    newNode->expressionLabel = "";
    return newNode;
}

struct Typeinfo{
	vector<string>type_variable; //for variable_types formalparameter declator list
	string name="";
	symtable *scope;
	int linep=0;

	string type="";
    int exprvalue=0;
    int order=0;

    string dectype="";
    int decorder1=0;
    string variable="";
    vector<string>variables;
    int decorder2=0;
    vector<int>decorders2;
    string arrtype="";
    vector<string>arrtypes;
    vector<int>arrdim;
    vector<vector<int>>arrdims;
    string initvartype="";
    vector<string>initvartypes;
    bool initialdecl=false;
    vector<bool>initialdecls;
};
int flag = 0;
Typeinfo *createstruct(){
	Typeinfo * t = new Typeinfo;
	return t;
};

#line 386 "parser.tab.c"

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

#include "parser.tab.h"
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
  YYSYMBOL_OMCommaRecordComponent = 144,   /* OMCommaRecordComponent  */
  YYSYMBOL_CommaRecordComponent = 145,     /* CommaRecordComponent  */
  YYSYMBOL_OMRecordBodyDeclaration = 146,  /* OMRecordBodyDeclaration  */
  YYSYMBOL_OMInterfaceMemberDeclaration = 147, /* OMInterfaceMemberDeclaration  */
  YYSYMBOL_OMCommaVariableInitializer = 148, /* OMCommaVariableInitializer  */
  YYSYMBOL_CommaVariableInitializer = 149, /* CommaVariableInitializer  */
  YYSYMBOL_OMBlockStatement = 150,         /* OMBlockStatement  */
  YYSYMBOL_OMSwitchRule = 151,             /* OMSwitchRule  */
  YYSYMBOL_OMSwitchBlockStatementGroup = 152, /* OMSwitchBlockStatementGroup  */
  YYSYMBOL_OMSwitchLabelColon = 153,       /* OMSwitchLabelColon  */
  YYSYMBOL_SwitchLabelColon = 154,         /* SwitchLabelColon  */
  YYSYMBOL_OMCommaCaseConstant = 155,      /* OMCommaCaseConstant  */
  YYSYMBOL_CommaCaseConstant = 156,        /* CommaCaseConstant  */
  YYSYMBOL_OMCommaStatementExpression = 157, /* OMCommaStatementExpression  */
  YYSYMBOL_CommaStatementExpression = 158, /* CommaStatementExpression  */
  YYSYMBOL_OMCatchClause = 159,            /* OMCatchClause  */
  YYSYMBOL_OMOrClassType = 160,            /* OMOrClassType  */
  YYSYMBOL_OrClassType = 161,              /* OrClassType  */
  YYSYMBOL_OMSemicolonResource = 162,      /* OMSemicolonResource  */
  YYSYMBOL_SemicolonResource = 163,        /* SemicolonResource  */
  YYSYMBOL_OMCommaExpression = 164,        /* OMCommaExpression  */
  YYSYMBOL_CommaExpression = 165,          /* CommaExpression  */
  YYSYMBOL_OMDimExpr = 166,                /* OMDimExpr  */
  YYSYMBOL_Modifieropt = 167,              /* Modifieropt  */
  YYSYMBOL_Identifier = 168,               /* Identifier  */
  YYSYMBOL_UnqualifiedMethodIdentifier = 169, /* UnqualifiedMethodIdentifier  */
  YYSYMBOL_Literal = 170,                  /* Literal  */
  YYSYMBOL_ASSIGNMENTOPERATOR = 171,       /* ASSIGNMENTOPERATOR  */
  YYSYMBOL_PrimitiveType = 172,            /* PrimitiveType  */
  YYSYMBOL_NumericType = 173,              /* NumericType  */
  YYSYMBOL_IntegralType = 174,             /* IntegralType  */
  YYSYMBOL_FloatingPointType = 175,        /* FloatingPointType  */
  YYSYMBOL_ReferenceType = 176,            /* ReferenceType  */
  YYSYMBOL_TypeParameter = 177,            /* TypeParameter  */
  YYSYMBOL_TypeBound = 178,                /* TypeBound  */
  YYSYMBOL_AdditionalBound = 179,          /* AdditionalBound  */
  YYSYMBOL_ModuleName = 180,               /* ModuleName  */
  YYSYMBOL_ExpressionName = 181,           /* ExpressionName  */
  YYSYMBOL_MethodName = 182,               /* MethodName  */
  YYSYMBOL_CompilationUnit = 183,          /* CompilationUnit  */
  YYSYMBOL_OrdinaryCompilationUnit = 184,  /* OrdinaryCompilationUnit  */
  YYSYMBOL_ModularCompilationUnit = 185,   /* ModularCompilationUnit  */
  YYSYMBOL_PackageDeclaration = 186,       /* PackageDeclaration  */
  YYSYMBOL_ImportDeclaration = 187,        /* ImportDeclaration  */
  YYSYMBOL_SingleTypeImportDeclaration = 188, /* SingleTypeImportDeclaration  */
  YYSYMBOL_SingleStaticImportDeclaration = 189, /* SingleStaticImportDeclaration  */
  YYSYMBOL_ImportOnDemandDeclaration = 190, /* ImportOnDemandDeclaration  */
  YYSYMBOL_StaticImportOnDemandDeclaration = 191, /* StaticImportOnDemandDeclaration  */
  YYSYMBOL_TopLevelClassOrInterfaceDeclaration = 192, /* TopLevelClassOrInterfaceDeclaration  */
  YYSYMBOL_ModuleDeclaration = 193,        /* ModuleDeclaration  */
  YYSYMBOL_194_1 = 194,                    /* $@1  */
  YYSYMBOL_195_2 = 195,                    /* $@2  */
  YYSYMBOL_196_3 = 196,                    /* $@3  */
  YYSYMBOL_197_4 = 197,                    /* $@4  */
  YYSYMBOL_198_5 = 198,                    /* $@5  */
  YYSYMBOL_199_6 = 199,                    /* $@6  */
  YYSYMBOL_200_7 = 200,                    /* $@7  */
  YYSYMBOL_201_8 = 201,                    /* $@8  */
  YYSYMBOL_ModuleDirective = 202,          /* ModuleDirective  */
  YYSYMBOL_ClassDeclaration = 203,         /* ClassDeclaration  */
  YYSYMBOL_NormalClassDeclaration = 204,   /* NormalClassDeclaration  */
  YYSYMBOL_205_9 = 205,                    /* $@9  */
  YYSYMBOL_206_10 = 206,                   /* $@10  */
  YYSYMBOL_207_11 = 207,                   /* $@11  */
  YYSYMBOL_208_12 = 208,                   /* $@12  */
  YYSYMBOL_209_13 = 209,                   /* $@13  */
  YYSYMBOL_210_14 = 210,                   /* $@14  */
  YYSYMBOL_211_15 = 211,                   /* $@15  */
  YYSYMBOL_212_16 = 212,                   /* $@16  */
  YYSYMBOL_213_17 = 213,                   /* $@17  */
  YYSYMBOL_214_18 = 214,                   /* $@18  */
  YYSYMBOL_215_19 = 215,                   /* $@19  */
  YYSYMBOL_216_20 = 216,                   /* $@20  */
  YYSYMBOL_217_21 = 217,                   /* $@21  */
  YYSYMBOL_218_22 = 218,                   /* $@22  */
  YYSYMBOL_219_23 = 219,                   /* $@23  */
  YYSYMBOL_220_24 = 220,                   /* $@24  */
  YYSYMBOL_221_25 = 221,                   /* $@25  */
  YYSYMBOL_222_26 = 222,                   /* $@26  */
  YYSYMBOL_223_27 = 223,                   /* $@27  */
  YYSYMBOL_224_28 = 224,                   /* $@28  */
  YYSYMBOL_225_29 = 225,                   /* $@29  */
  YYSYMBOL_226_30 = 226,                   /* $@30  */
  YYSYMBOL_227_31 = 227,                   /* $@31  */
  YYSYMBOL_228_32 = 228,                   /* $@32  */
  YYSYMBOL_229_33 = 229,                   /* $@33  */
  YYSYMBOL_230_34 = 230,                   /* $@34  */
  YYSYMBOL_231_35 = 231,                   /* $@35  */
  YYSYMBOL_232_36 = 232,                   /* $@36  */
  YYSYMBOL_233_37 = 233,                   /* $@37  */
  YYSYMBOL_234_38 = 234,                   /* $@38  */
  YYSYMBOL_235_39 = 235,                   /* $@39  */
  YYSYMBOL_236_40 = 236,                   /* $@40  */
  YYSYMBOL_TypeParameters = 237,           /* TypeParameters  */
  YYSYMBOL_TypeParameterList = 238,        /* TypeParameterList  */
  YYSYMBOL_ClassExtends = 239,             /* ClassExtends  */
  YYSYMBOL_ClassImplements = 240,          /* ClassImplements  */
  YYSYMBOL_InterfaceTypeList = 241,        /* InterfaceTypeList  */
  YYSYMBOL_ClassPermits = 242,             /* ClassPermits  */
  YYSYMBOL_ClassBody = 243,                /* ClassBody  */
  YYSYMBOL_ClassBodyDeclaration = 244,     /* ClassBodyDeclaration  */
  YYSYMBOL_ClassMemberDeclaration = 245,   /* ClassMemberDeclaration  */
  YYSYMBOL_FieldDeclaration = 246,         /* FieldDeclaration  */
  YYSYMBOL_VariableDeclaratorList = 247,   /* VariableDeclaratorList  */
  YYSYMBOL_VariableDeclarator = 248,       /* VariableDeclarator  */
  YYSYMBOL_VariableDeclaratorId = 249,     /* VariableDeclaratorId  */
  YYSYMBOL_VariableInitializer = 250,      /* VariableInitializer  */
  YYSYMBOL_UnannType = 251,                /* UnannType  */
  YYSYMBOL_UnannPrimitiveType = 252,       /* UnannPrimitiveType  */
  YYSYMBOL_UnannArrayType = 253,           /* UnannArrayType  */
  YYSYMBOL_MethodDeclaration = 254,        /* MethodDeclaration  */
  YYSYMBOL_MethodHeader = 255,             /* MethodHeader  */
  YYSYMBOL_Result = 256,                   /* Result  */
  YYSYMBOL_MethodDeclarator = 257,         /* MethodDeclarator  */
  YYSYMBOL_ReceiverParameter = 258,        /* ReceiverParameter  */
  YYSYMBOL_FormalParameterList = 259,      /* FormalParameterList  */
  YYSYMBOL_FormalParameter = 260,          /* FormalParameter  */
  YYSYMBOL_VariableArityParameter = 261,   /* VariableArityParameter  */
  YYSYMBOL_Throws = 262,                   /* Throws  */
  YYSYMBOL_ExceptionTypeList = 263,        /* ExceptionTypeList  */
  YYSYMBOL_ExceptionType = 264,            /* ExceptionType  */
  YYSYMBOL_MethodBody = 265,               /* MethodBody  */
  YYSYMBOL_InstanceInitializer = 266,      /* InstanceInitializer  */
  YYSYMBOL_StaticInitializer = 267,        /* StaticInitializer  */
  YYSYMBOL_ConstructorDeclaration = 268,   /* ConstructorDeclaration  */
  YYSYMBOL_ConstructorDeclaratorLRBSym = 269, /* ConstructorDeclaratorLRBSym  */
  YYSYMBOL_ConstructorDeclarator = 270,    /* ConstructorDeclarator  */
  YYSYMBOL_ConstructorBody = 271,          /* ConstructorBody  */
  YYSYMBOL_ExplicitConstructorInvocation = 272, /* ExplicitConstructorInvocation  */
  YYSYMBOL_RecordDeclarationSym = 273,     /* RecordDeclarationSym  */
  YYSYMBOL_RecordDeclaration = 274,        /* RecordDeclaration  */
  YYSYMBOL_RecordHeader = 275,             /* RecordHeader  */
  YYSYMBOL_RecordComponentList = 276,      /* RecordComponentList  */
  YYSYMBOL_RecordComponent = 277,          /* RecordComponent  */
  YYSYMBOL_VariableArityRecordComponent = 278, /* VariableArityRecordComponent  */
  YYSYMBOL_RecordBody = 279,               /* RecordBody  */
  YYSYMBOL_RecordBodyDeclaration = 280,    /* RecordBodyDeclaration  */
  YYSYMBOL_CompactConstructorDeclarationSym = 281, /* CompactConstructorDeclarationSym  */
  YYSYMBOL_CompactConstructorDeclaration = 282, /* CompactConstructorDeclaration  */
  YYSYMBOL_InterfaceDeclaration = 283,     /* InterfaceDeclaration  */
  YYSYMBOL_NormalInterfaceDeclaration = 284, /* NormalInterfaceDeclaration  */
  YYSYMBOL_285_41 = 285,                   /* $@41  */
  YYSYMBOL_286_42 = 286,                   /* $@42  */
  YYSYMBOL_287_43 = 287,                   /* $@43  */
  YYSYMBOL_288_44 = 288,                   /* $@44  */
  YYSYMBOL_289_45 = 289,                   /* $@45  */
  YYSYMBOL_290_46 = 290,                   /* $@46  */
  YYSYMBOL_291_47 = 291,                   /* $@47  */
  YYSYMBOL_292_48 = 292,                   /* $@48  */
  YYSYMBOL_293_49 = 293,                   /* $@49  */
  YYSYMBOL_294_50 = 294,                   /* $@50  */
  YYSYMBOL_295_51 = 295,                   /* $@51  */
  YYSYMBOL_296_52 = 296,                   /* $@52  */
  YYSYMBOL_297_53 = 297,                   /* $@53  */
  YYSYMBOL_298_54 = 298,                   /* $@54  */
  YYSYMBOL_299_55 = 299,                   /* $@55  */
  YYSYMBOL_300_56 = 300,                   /* $@56  */
  YYSYMBOL_InterfaceModifier = 301,        /* InterfaceModifier  */
  YYSYMBOL_InterfaceExtends = 302,         /* InterfaceExtends  */
  YYSYMBOL_InterfacePermits = 303,         /* InterfacePermits  */
  YYSYMBOL_InterfaceBody = 304,            /* InterfaceBody  */
  YYSYMBOL_InterfaceMemberDeclaration = 305, /* InterfaceMemberDeclaration  */
  YYSYMBOL_ConstantDeclaration = 306,      /* ConstantDeclaration  */
  YYSYMBOL_InterfaceMethodDeclaration = 307, /* InterfaceMethodDeclaration  */
  YYSYMBOL_ArrayInitializer = 308,         /* ArrayInitializer  */
  YYSYMBOL_VariableInitializerList = 309,  /* VariableInitializerList  */
  YYSYMBOL_Block = 310,                    /* Block  */
  YYSYMBOL_BlockStatements = 311,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 312,           /* BlockStatement  */
  YYSYMBOL_LocalClassOrInterfaceDeclaration = 313, /* LocalClassOrInterfaceDeclaration  */
  YYSYMBOL_LocalVariableDeclarationStatement = 314, /* LocalVariableDeclarationStatement  */
  YYSYMBOL_LocalVariableDeclaration = 315, /* LocalVariableDeclaration  */
  YYSYMBOL_LocalVariableType = 316,        /* LocalVariableType  */
  YYSYMBOL_Statement = 317,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 318,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 319, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_320_57 = 320,                   /* $@57  */
  YYSYMBOL_EmptyStatement = 321,           /* EmptyStatement  */
  YYSYMBOL_LabeledStatement = 322,         /* LabeledStatement  */
  YYSYMBOL_LabeledStatementNoShortIf = 323, /* LabeledStatementNoShortIf  */
  YYSYMBOL_ExpressionStatement = 324,      /* ExpressionStatement  */
  YYSYMBOL_StatementExpression = 325,      /* StatementExpression  */
  YYSYMBOL_IfThenStatement = 326,          /* IfThenStatement  */
  YYSYMBOL_IfThenElseStatement = 327,      /* IfThenElseStatement  */
  YYSYMBOL_IfThenElseStatementNoShortIf = 328, /* IfThenElseStatementNoShortIf  */
  YYSYMBOL_AssertStatement = 329,          /* AssertStatement  */
  YYSYMBOL_SwitchStatement = 330,          /* SwitchStatement  */
  YYSYMBOL_331_58 = 331,                   /* $@58  */
  YYSYMBOL_SwitchBlock = 332,              /* SwitchBlock  */
  YYSYMBOL_SwitchRule = 333,               /* SwitchRule  */
  YYSYMBOL_SwitchBlockStatementGroup = 334, /* SwitchBlockStatementGroup  */
  YYSYMBOL_SwitchLabel = 335,              /* SwitchLabel  */
  YYSYMBOL_CaseConstant = 336,             /* CaseConstant  */
  YYSYMBOL_WhileStatement = 337,           /* WhileStatement  */
  YYSYMBOL_WhileStatementNoShortIf = 338,  /* WhileStatementNoShortIf  */
  YYSYMBOL_DoStatement = 339,              /* DoStatement  */
  YYSYMBOL_ForStatement = 340,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 341,    /* ForStatementNoShortIf  */
  YYSYMBOL_ForSym = 342,                   /* ForSym  */
  YYSYMBOL_BasicForStatement = 343,        /* BasicForStatement  */
  YYSYMBOL_BasicForStatementNoShortIf = 344, /* BasicForStatementNoShortIf  */
  YYSYMBOL_ForInit = 345,                  /* ForInit  */
  YYSYMBOL_ForUpdate = 346,                /* ForUpdate  */
  YYSYMBOL_StatementExpressionList = 347,  /* StatementExpressionList  */
  YYSYMBOL_EnhancedForStatementSym = 348,  /* EnhancedForStatementSym  */
  YYSYMBOL_EnhancedForStatement = 349,     /* EnhancedForStatement  */
  YYSYMBOL_EnhancedForStatementNoShortIf = 350, /* EnhancedForStatementNoShortIf  */
  YYSYMBOL_BreakStatement = 351,           /* BreakStatement  */
  YYSYMBOL_YieldStatement = 352,           /* YieldStatement  */
  YYSYMBOL_ContinueStatement = 353,        /* ContinueStatement  */
  YYSYMBOL_ReturnStatement = 354,          /* ReturnStatement  */
  YYSYMBOL_ThrowStatement = 355,           /* ThrowStatement  */
  YYSYMBOL_SynchronizedStatement = 356,    /* SynchronizedStatement  */
  YYSYMBOL_357_59 = 357,                   /* $@59  */
  YYSYMBOL_TrySym = 358,                   /* TrySym  */
  YYSYMBOL_TryBlockSym = 359,              /* TryBlockSym  */
  YYSYMBOL_TryStatement = 360,             /* TryStatement  */
  YYSYMBOL_Catches = 361,                  /* Catches  */
  YYSYMBOL_CatchClause = 362,              /* CatchClause  */
  YYSYMBOL_363_60 = 363,                   /* $@60  */
  YYSYMBOL_CatchFormalParameter = 364,     /* CatchFormalParameter  */
  YYSYMBOL_CatchType = 365,                /* CatchType  */
  YYSYMBOL_Finally = 366,                  /* Finally  */
  YYSYMBOL_367_61 = 367,                   /* $@61  */
  YYSYMBOL_TryWithResourcesStatement = 368, /* TryWithResourcesStatement  */
  YYSYMBOL_ResourceSpecification = 369,    /* ResourceSpecification  */
  YYSYMBOL_ResourceList = 370,             /* ResourceList  */
  YYSYMBOL_Resource = 371,                 /* Resource  */
  YYSYMBOL_Primary = 372,                  /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 373,        /* PrimaryNoNewArray  */
  YYSYMBOL_ClassLiteral = 374,             /* ClassLiteral  */
  YYSYMBOL_ClassInstanceCreationExpression = 375, /* ClassInstanceCreationExpression  */
  YYSYMBOL_UnqualifiedClassInstanceCreationExpression = 376, /* UnqualifiedClassInstanceCreationExpression  */
  YYSYMBOL_ClassOrInterfaceTypeToInstantiate = 377, /* ClassOrInterfaceTypeToInstantiate  */
  YYSYMBOL_FieldAccess = 378,              /* FieldAccess  */
  YYSYMBOL_ArrayAccess = 379,              /* ArrayAccess  */
  YYSYMBOL_MethodInvocation = 380,         /* MethodInvocation  */
  YYSYMBOL_ArgumentList = 381,             /* ArgumentList  */
  YYSYMBOL_MethodReference = 382,          /* MethodReference  */
  YYSYMBOL_ArrayCreationExpression = 383,  /* ArrayCreationExpression  */
  YYSYMBOL_DimExpr = 384,                  /* DimExpr  */
  YYSYMBOL_Expression = 385,               /* Expression  */
  YYSYMBOL_AssignmentExpression = 386,     /* AssignmentExpression  */
  YYSYMBOL_Assignment = 387,               /* Assignment  */
  YYSYMBOL_LeftHandSide = 388,             /* LeftHandSide  */
  YYSYMBOL_AssignmentOperator = 389,       /* AssignmentOperator  */
  YYSYMBOL_ConditionalExpression = 390,    /* ConditionalExpression  */
  YYSYMBOL_ConditionalOrExpression = 391,  /* ConditionalOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 392, /* ConditionalAndExpression  */
  YYSYMBOL_InclusiveOrExpression = 393,    /* InclusiveOrExpression  */
  YYSYMBOL_ExclusiveOrExpression = 394,    /* ExclusiveOrExpression  */
  YYSYMBOL_AndExpression = 395,            /* AndExpression  */
  YYSYMBOL_EqualityExpression = 396,       /* EqualityExpression  */
  YYSYMBOL_RelationalExpression = 397,     /* RelationalExpression  */
  YYSYMBOL_InstanceofExpression = 398,     /* InstanceofExpression  */
  YYSYMBOL_ShiftExpression = 399,          /* ShiftExpression  */
  YYSYMBOL_AdditiveExpression = 400,       /* AdditiveExpression  */
  YYSYMBOL_MultiplicativeExpression = 401, /* MultiplicativeExpression  */
  YYSYMBOL_UnaryExpression = 402,          /* UnaryExpression  */
  YYSYMBOL_PreIncrementExpression = 403,   /* PreIncrementExpression  */
  YYSYMBOL_PreDecrementExpression = 404,   /* PreDecrementExpression  */
  YYSYMBOL_UnaryExpressionNotPlusMinus = 405, /* UnaryExpressionNotPlusMinus  */
  YYSYMBOL_PostfixExpression = 406,        /* PostfixExpression  */
  YYSYMBOL_PostIncrementExpression = 407,  /* PostIncrementExpression  */
  YYSYMBOL_PostDecrementExpression = 408,  /* PostDecrementExpression  */
  YYSYMBOL_CastExpression = 409,           /* CastExpression  */
  YYSYMBOL_SwitchExpression = 410,         /* SwitchExpression  */
  YYSYMBOL_411_62 = 411,                   /* $@62  */
  YYSYMBOL_VariableAccess = 412            /* VariableAccess  */
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
#define YYFINAL  57
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   7450

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  119
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  294
/* YYNRULES -- Number of rules.  */
#define YYNRULES  719
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1246

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
       0,   357,   357,   358,   360,   362,   363,   365,   367,   369,
     370,   372,   373,   375,   376,   378,   379,   381,   382,   384,
     385,   387,   389,   390,   392,   393,   395,   396,   398,   399,
     401,   403,   404,   406,   408,   409,   411,   412,   414,   416,
     417,   419,   421,   422,   424,   426,   427,   429,   430,   432,
     433,   435,   437,   438,   440,   441,   443,   444,   446,   447,
     449,   451,   452,   454,   456,   457,   459,   461,   462,   464,
     465,   467,   469,   470,   472,   474,   475,   477,   479,   480,
     482,   483,   484,   485,   486,   487,   488,   489,   491,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   510,   511,   512,   513,   514,
     515,   516,   518,   519,   521,   523,   524,   526,   527,   528,
     529,   530,   532,   533,   535,   536,   538,   539,   541,   542,
     544,   546,   547,   549,   550,   552,   554,   555,   557,   558,
     559,   560,   561,   562,   563,   564,   566,   567,   569,   570,
     572,   573,   574,   575,   577,   578,   580,   582,   583,   585,
     586,   588,   589,   590,   592,   592,   593,   593,   594,   594,
     595,   595,   596,   596,   597,   597,   598,   598,   599,   599,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   626,   627,   629,   629,   630,   630,
     631,   631,   632,   632,   633,   633,   634,   634,   635,   635,
     636,   636,   637,   637,   638,   638,   639,   639,   640,   640,
     641,   641,   642,   642,   643,   643,   644,   644,   645,   645,
     646,   646,   647,   647,   648,   648,   649,   649,   650,   650,
     651,   651,   652,   652,   653,   653,   654,   654,   655,   655,
     656,   656,   657,   657,   658,   658,   659,   659,   660,   660,
     662,   664,   665,   667,   669,   671,   672,   675,   676,   677,
     678,   680,   681,   683,   684,   685,   686,   688,   689,   690,
     691,   692,   694,   695,   697,   698,   700,   701,   703,   704,
     707,   708,   710,   711,   712,   714,   715,   717,   718,   720,
     721,   723,   724,   725,   726,   728,   729,   732,   733,   734,
     735,   736,   737,   738,   739,   741,   742,   744,   745,   747,
     748,   749,   751,   752,   754,   756,   757,   759,   762,   763,
     765,   767,   769,   770,   771,   772,   774,   776,   777,   778,
     779,   780,   781,   782,   783,   786,   787,   788,   789,   791,
     792,   793,   794,   795,   796,   797,   798,   799,   800,   803,
     805,   806,   807,   808,   809,   810,   811,   812,   815,   816,
     818,   819,   821,   822,   825,   827,   828,   830,   831,   833,
     835,   836,   839,   841,   841,   842,   842,   843,   843,   844,
     844,   845,   845,   846,   846,   847,   847,   848,   848,   849,
     849,   850,   850,   851,   851,   852,   852,   853,   853,   854,
     854,   855,   855,   856,   856,   859,   861,   863,   864,   866,
     867,   869,   870,   871,   872,   873,   875,   876,   878,   879,
     881,   882,   883,   885,   886,   888,   889,   891,   892,   894,
     895,   896,   898,   899,   901,   923,   924,   926,   927,   929,
     930,   931,   932,   933,   934,   936,   937,   938,   939,   940,
     942,   942,   943,   944,   945,   946,   947,   948,   949,   950,
     951,   952,   953,   954,   956,   958,   960,   963,   965,   966,
     967,   968,   969,   970,   971,   973,   975,   977,   979,   980,
     982,   982,   984,   985,   986,   987,   988,   989,   991,   992,
     993,   995,   996,   998,   999,  1000,  1002,  1004,  1006,  1008,
    1010,  1011,  1013,  1014,  1016,  1018,  1019,  1020,  1021,  1022,
    1023,  1024,  1025,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1036,  1037,  1039,  1041,  1042,  1044,  1046,  1048,  1050,
    1051,  1054,  1056,  1057,  1060,  1061,  1063,  1065,  1065,  1067,
    1069,  1071,  1072,  1073,  1074,  1076,  1077,  1079,  1079,  1081,
    1082,  1084,  1085,  1088,  1088,  1090,  1091,  1092,  1093,  1095,
    1097,  1098,  1100,  1101,  1103,  1104,  1106,  1107,  1108,  1109,
    1110,  1111,  1112,  1113,  1114,  1115,  1116,  1118,  1119,  1120,
    1121,  1122,  1123,  1125,  1126,  1127,  1128,  1130,  1131,  1132,
    1133,  1135,  1136,  1138,  1139,  1140,  1141,  1143,  1144,  1145,
    1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,
    1157,  1158,  1159,  1160,  1163,  1164,  1166,  1167,  1168,  1169,
    1170,  1171,  1172,  1173,  1175,  1176,  1177,  1178,  1179,  1180,
    1183,  1185,  1187,  1188,  1190,  1192,  1193,  1194,  1195,  1197,
    1199,  1200,  1202,  1203,  1205,  1206,  1208,  1209,  1211,  1212,
    1214,  1215,  1217,  1218,  1219,  1221,  1222,  1223,  1224,  1225,
    1226,  1228,  1230,  1231,  1232,  1233,  1235,  1236,  1237,  1239,
    1240,  1241,  1242,  1244,  1245,  1246,  1247,  1248,  1250,  1252,
    1254,  1255,  1256,  1257,  1258,  1260,  1261,  1262,  1263,  1264,
    1266,  1268,  1270,  1271,  1272,  1274,  1274,  1276,  1277,  1278
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
  "OMCommaRecordComponent", "CommaRecordComponent",
  "OMRecordBodyDeclaration", "OMInterfaceMemberDeclaration",
  "OMCommaVariableInitializer", "CommaVariableInitializer",
  "OMBlockStatement", "OMSwitchRule", "OMSwitchBlockStatementGroup",
  "OMSwitchLabelColon", "SwitchLabelColon", "OMCommaCaseConstant",
  "CommaCaseConstant", "OMCommaStatementExpression",
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
  "ModuleDeclaration", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7",
  "$@8", "ModuleDirective", "ClassDeclaration", "NormalClassDeclaration",
  "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15", "$@16", "$@17",
  "$@18", "$@19", "$@20", "$@21", "$@22", "$@23", "$@24", "$@25", "$@26",
  "$@27", "$@28", "$@29", "$@30", "$@31", "$@32", "$@33", "$@34", "$@35",
  "$@36", "$@37", "$@38", "$@39", "$@40", "TypeParameters",
  "TypeParameterList", "ClassExtends", "ClassImplements",
  "InterfaceTypeList", "ClassPermits", "ClassBody", "ClassBodyDeclaration",
  "ClassMemberDeclaration", "FieldDeclaration", "VariableDeclaratorList",
  "VariableDeclarator", "VariableDeclaratorId", "VariableInitializer",
  "UnannType", "UnannPrimitiveType", "UnannArrayType", "MethodDeclaration",
  "MethodHeader", "Result", "MethodDeclarator", "ReceiverParameter",
  "FormalParameterList", "FormalParameter", "VariableArityParameter",
  "Throws", "ExceptionTypeList", "ExceptionType", "MethodBody",
  "InstanceInitializer", "StaticInitializer", "ConstructorDeclaration",
  "ConstructorDeclaratorLRBSym", "ConstructorDeclarator",
  "ConstructorBody", "ExplicitConstructorInvocation",
  "RecordDeclarationSym", "RecordDeclaration", "RecordHeader",
  "RecordComponentList", "RecordComponent", "VariableArityRecordComponent",
  "RecordBody", "RecordBodyDeclaration",
  "CompactConstructorDeclarationSym", "CompactConstructorDeclaration",
  "InterfaceDeclaration", "NormalInterfaceDeclaration", "$@41", "$@42",
  "$@43", "$@44", "$@45", "$@46", "$@47", "$@48", "$@49", "$@50", "$@51",
  "$@52", "$@53", "$@54", "$@55", "$@56", "InterfaceModifier",
  "InterfaceExtends", "InterfacePermits", "InterfaceBody",
  "InterfaceMemberDeclaration", "ConstantDeclaration",
  "InterfaceMethodDeclaration", "ArrayInitializer",
  "VariableInitializerList", "Block", "BlockStatements", "BlockStatement",
  "LocalClassOrInterfaceDeclaration", "LocalVariableDeclarationStatement",
  "LocalVariableDeclaration", "LocalVariableType", "Statement",
  "StatementNoShortIf", "StatementWithoutTrailingSubstatement", "$@57",
  "EmptyStatement", "LabeledStatement", "LabeledStatementNoShortIf",
  "ExpressionStatement", "StatementExpression", "IfThenStatement",
  "IfThenElseStatement", "IfThenElseStatementNoShortIf", "AssertStatement",
  "SwitchStatement", "$@58", "SwitchBlock", "SwitchRule",
  "SwitchBlockStatementGroup", "SwitchLabel", "CaseConstant",
  "WhileStatement", "WhileStatementNoShortIf", "DoStatement",
  "ForStatement", "ForStatementNoShortIf", "ForSym", "BasicForStatement",
  "BasicForStatementNoShortIf", "ForInit", "ForUpdate",
  "StatementExpressionList", "EnhancedForStatementSym",
  "EnhancedForStatement", "EnhancedForStatementNoShortIf",
  "BreakStatement", "YieldStatement", "ContinueStatement",
  "ReturnStatement", "ThrowStatement", "SynchronizedStatement", "$@59",
  "TrySym", "TryBlockSym", "TryStatement", "Catches", "CatchClause",
  "$@60", "CatchFormalParameter", "CatchType", "Finally", "$@61",
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
  "SwitchExpression", "$@62", "VariableAccess", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-1027)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-720)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1478, -1027,     3, -1027, -1027,    25, -1027, -1027,     3, -1027,
       3, -1027,     3, -1027,    70,     3, -1027,  1784,   841,  1607,
   -1027,   282, -1027, -1027,  1005, -1027, -1027, -1027, -1027, -1027,
   -1027, -1027, -1027, -1027,    33, -1027, -1027, -1027, -1027, -1027,
     366,     3,   406,   515,   382,   269,   276,     3, -1027,   841,
   -1027, -1027, -1027,     3,     3,    33, -1027, -1027,  1005,   841,
       3,  1091,   102,    24, -1027,     3,   564,   178,   587, -1027,
      20, -1027,   219,     3,     3,    82,   128,   240, -1027,     3,
       3,     3,   218,   436,    99,   283, -1027,   260,   379,   451,
     382,   269,   102,    24,   841,   371,   383,   358, -1027, -1027,
   -1027, -1027, -1027, -1027, -1027, -1027, -1027,   460, -1027, -1027,
   -1027,   351,   460, -1027,   481,   484, -1027,    24,  2289,   503,
   -1027, -1027, -1027,     3,   235, -1027,   264,   492, -1027,   504,
   -1027,   553, -1027,   557,   109,   128,   240, -1027,  4237, -1027,
     128, -1027,   128, -1027, -1027,   442,   109,  2948, -1027,   218,
      99,   283, -1027,   218,   283, -1027,   218, -1027,   218,   576,
     699,   585,   603,   458,    82,   128,   240, -1027,   218,   436,
      99,   283, -1027,    24,   503, -1027,     3, -1027,     3,   383,
   -1027, -1027,   595,   460, -1027,     3, -1027,   460, -1027,  1138,
     484, -1027,   503, -1027,   609,     3,  3615, -1027, -1027,  4339,
    4122,   344, -1027,  1289, -1027, -1027, -1027,     3, -1027,   294,
     664, -1027, -1027, -1027,    42, -1027,   670, -1027, -1027, -1027,
   -1027, -1027,   649,   722, -1027, -1027,     3,   553, -1027,     3,
       3,     3,   675, -1027, -1027,   128, -1027,   128, -1027, -1027,
    4339,  4285, -1027,  1289,     3,   294, -1027, -1027, -1027, -1027,
   -1027,   128, -1027,   675,   675, -1027,  4339,  4176,   490, -1027,
   -1027,   218,   283, -1027,   218, -1027,   218, -1027,   218, -1027,
     218, -1027,   218, -1027, -1027,     3,     3,   754,     3,     3,
     354, -1027,   709,   699,   753,   699,   788,   128,   240, -1027,
   -1027,   128, -1027,   128, -1027,   218,    99,   283, -1027,   218,
     283, -1027,   218, -1027,   218,   503, -1027, -1027,   777, -1027,
   -1027, -1027, -1027, -1027, -1027, -1027, -1027, -1027, -1027,   316,
   -1027,  1138,   817,  6580,   853,   867,  4633, -1027,   508,  6580,
    4960, -1027,   792,   394,   879, -1027, -1027, -1027, -1027, -1027,
   -1027,   891,   802, -1027, -1027, -1027, -1027, -1027,     3, -1027,
    6580, -1027, -1027, -1027, -1027, -1027, -1027, -1027,  6580,  6580,
    6580, -1027, -1027,   898,  4387,   691, -1027, -1027,   429,   915,
   -1027, -1027,   583,   909, -1027,   901,  3730, -1027, -1027,   921,
       3, -1027, -1027,   609, -1027, -1027, -1027,   930, -1027, -1027,
   -1027, -1027, -1027, -1027, -1027,   941, -1027,   975, -1027, -1027,
   -1027, -1027, -1027, -1027, -1027,   688, -1027, -1027,   428,   949,
   -1027,   418, -1027,   544,   551,   596, -1027, -1027, -1027,   620,
   -1027, -1027,   548,   640,   734,     3,   294,    42,   670, -1027,
   -1027, -1027,  1343,   653,     3,   664,   680,   729, -1027,   956,
   -1027, -1027, -1027,  1526,  1033,     3,  3845,   670, -1027, -1027,
   -1027, -1027, -1027, -1027,   557,   948, -1027, -1027,   128, -1027,
       3,   294, -1027, -1027,   773, -1027, -1027, -1027, -1027, -1027,
     218, -1027,   218, -1027,   218, -1027, -1027,   218, -1027, -1027,
      39,    54,   279,   286,   754, -1027, -1027,   736,   739,   765,
     231,   248, -1027, -1027, -1027,   435, -1027,   552,   955,   699,
   -1027,   128, -1027,   128, -1027,   128, -1027, -1027,   218,   283,
   -1027,   218, -1027,   218, -1027,   218, -1027,   218, -1027,   218,
   -1027, -1027,     3,   777, -1027, -1027,   954,   677,   958, -1027,
     964,  6580,   965, -1027, -1027, -1027,  6580,  6580,  6580,  6580,
    6580,   761,   583,   909, -1027, -1027,    28, -1027, -1027, -1027,
     207,   984,   976,   977,   980,   580,   462, -1027,   285,   776,
     535, -1027, -1027, -1027, -1027,   548, -1027, -1027, -1027, -1027,
    6580,  6580,   747,  1026, -1027,   967,   968, -1027,   969,  1040,
       3,     3,  6580,   972,   444,   550, -1027, -1027, -1027, -1027,
     978, -1027,     3,  4633,  5041,    91,     3,   693,  5041,   106,
       3,   696,  5122,  1045,    75, -1027,  3730, -1027, -1027,   460,
     981, -1027, -1027,  3130,  6580,  3270, -1027,   254,   609,    83,
       3,  6580, -1027, -1027, -1027,  6580, -1027, -1027,   839, -1027,
     670, -1027, -1027,  3418,    44,   983, -1027,  4555,   569,   990,
     985, -1027, -1027,  4417, -1027,  1033,   460, -1027,     3,  5203,
     460,  4447,    56,   992, -1027, -1027, -1027,   987,   996,    13,
   -1027,   706,   730,  3960,   998,   597, -1027, -1027,   893, -1027,
   -1027, -1027,   218, -1027, -1027, -1027,     3, -1027,     3, -1027,
       3, -1027,     3, -1027, -1027,   882, -1027,     3, -1027, -1027,
       3,     3, -1027, -1027, -1027,   589, -1027,   128, -1027, -1027,
   -1027,   218, -1027,   218, -1027,   218, -1027, -1027,   218, -1027,
   -1027, -1027, -1027, -1027,  5041,   892,   994,   958, -1027,   892,
     958,  5284,  1003,  6580, -1027, -1027, -1027, -1027,  1007,   583,
     234,  6580, -1027,  6580,  6580,  6580,  6580,  6580,  6580,  6580,
    6580,  6580,  6580,  6580,  6580,  1138,  6580,  6580,  6580,  6580,
    6580,  6580,  6580,  6580,  1009,  1014,  1018, -1027, -1027, -1027,
   -1027,  1022, -1027,  1025, -1027, -1027,   981, -1027,   979,     3,
   -1027, -1027,   605,  1027, -1027, -1027,  1070,  1024, -1027, -1027,
     655,  1031, -1027, -1027,  1095, -1027,  1034,  1030, -1027, -1027,
   -1027, -1027,  5365,  4477,   578,  1061,  1036,  1035, -1027,  1039,
    3270, -1027,   507,   550, -1027,  1048,  1044,   428,   471, -1027,
   -1027, -1027,  1113,  1126, -1027,   254,  1054, -1027, -1027,  1052,
   -1027, -1027, -1027, -1027,  1059, -1027,  1149,  1055, -1027,   697,
       3, -1027, -1027,  4555,   985, -1027,  4525, -1027,  1063, -1027,
   -1027,  4798, -1027, -1027, -1027,   460,   460,  1064,   717,   460,
       3,   987, -1027,  5446,  5527,   243,   353, -1027,  1066, -1027,
      49, -1027, -1027,   797,   800,   814,   819, -1027, -1027,   823,
     832,   836,   870, -1027, -1027, -1027,   218, -1027, -1027, -1027,
    1057, -1027,   460, -1027, -1027,   460,   218,  1065, -1027,  1072,
    6580,  6661,    29,  1074,  1094,   984,   976,   977,   980,   580,
     462,   462,   285,   285,   285,   285,   460, -1027,   460, -1027,
     776,   776,   776,   535,   535, -1027, -1027, -1027,  4723, -1027,
    6580,  5608,  4633, -1027,  1068,     3,     3,  5689, -1027, -1027,
       3,     3,  5770, -1027, -1027,  6580,  1030, -1027,  6733,  1076,
    7333,  1036, -1027,  5851,  4633, -1027,  1044, -1027, -1027,  1078,
     609, -1027,  1126, -1027,  1113, -1027,  5932, -1027, -1027, -1027,
   -1027,     3, -1027, -1027, -1027, -1027, -1027,  1085, -1027, -1027,
    1084,  1081,  1086,   460,   460,   460, -1027, -1027,  1088,  1089,
    1090,  1098,   368,   496, -1027,  1101, -1027,     3,   895, -1027,
   -1027,   904, -1027,   906, -1027,   912, -1027,   917, -1027,   924,
   -1027,   926, -1027,   928, -1027, -1027, -1027,   218,  1100, -1027,
   -1027, -1027,  6661, -1027,  6580,  1104,  1105,   824, -1027,  1172,
    1187, -1027, -1027, -1027, -1027,  1108, -1027,  1133, -1027,   609,
    1110, -1027,  1111, -1027,  1114, -1027, -1027,  1112,  1115, -1027,
   -1027,  1116, -1027, -1027,  4633,  1118, -1027,  6808, -1027, -1027,
    6883,  1119, -1027,   754, -1027, -1027, -1027, -1027,  1121, -1027,
   -1027, -1027,  5203,  1081, -1027, -1027,   460, -1027,  1120, -1027,
    1122,  6013,  6094,  6175,  1127, -1027, -1027, -1027, -1027, -1027,
   -1027, -1027, -1027, -1027, -1027,   255, -1027,  1100, -1027, -1027,
    6580,  6580,  4723,  4633,  4041,  6580, -1027,  1124, -1027,  6256,
   -1027,  6337, -1027, -1027,  4633,  4633,  1123,  4633,  1137,  6958,
     754,  1135,  1140,     3, -1027, -1027, -1027, -1027, -1027,  1136,
    1142,  1139,  1143,  1145,  1148, -1027,  6580, -1027,   256,   272,
   -1027,   311, -1027,   966, -1027,  1152,  1153, -1027, -1027,  6418,
    1150,  1154, -1027, -1027,  1156, -1027,  1161, -1027, -1027,  4633,
   -1027,  4633,  4633,  1162,     3,     3,  1135, -1027,   609, -1027,
   -1027,  1159, -1027,  1160, -1027,  1163,  1109, -1027, -1027,   323,
   -1027,  1169, -1027, -1027,  1190, -1027,   339, -1027,  1192,  3730,
    4879,  4723,  4723,  7033,  1165,  6499,  4723, -1027, -1027, -1027,
   -1027, -1027,  4633, -1027, -1027, -1027, -1027, -1027, -1027, -1027,
    6580,  1109, -1027, -1027, -1027, -1027, -1027,  3492, -1027, -1027,
   -1027,  1166,  1220, -1027,  4723,  1173,  7108,  7183,  1167, -1027,
   -1027, -1027, -1027, -1027, -1027,  4723, -1027,  4723,  4723,  1174,
    4723,  1175,  7258, -1027, -1027, -1027,  4723, -1027,  4723,  4723,
    1177, -1027, -1027, -1027,  4723, -1027
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     138,    83,     0,    82,    81,     0,    80,    87,     0,    84,
       0,    86,     0,    85,     0,     0,   163,   140,   139,     0,
     425,     0,   136,   137,   142,     9,   150,   151,   153,   152,
      11,   146,   161,   204,     0,   205,   162,   392,    26,    88,
       0,     0,     0,     0,   393,   206,     0,     0,   369,   141,
      10,   147,    12,     0,     0,     0,    27,     1,   144,   143,
       0,     0,     0,     0,   148,     0,     0,     0,     0,   154,
       0,   155,     0,     0,     0,   401,     0,   397,   395,     0,
       0,     0,     0,   222,   214,   210,   208,   166,     0,     0,
     409,   238,     0,     0,   145,   126,   271,     0,   306,   123,
     117,   119,   118,   121,   120,   122,   378,   303,   305,   115,
     116,     0,   302,   304,     0,   380,   383,     0,     0,     0,
     370,    13,   149,     0,     0,   156,     0,     0,   133,     0,
     134,   275,   426,     0,   427,     0,   405,   403,     0,   394,
       0,   399,     0,   274,   273,   277,   278,     0,   207,     0,
     230,   226,   224,     0,   218,   216,     0,   212,     0,     0,
       0,   170,   174,     0,   417,     0,   413,   411,     0,   254,
     246,   242,   240,     0,     0,   374,     0,   127,     0,   272,
      28,   270,     0,   308,     2,     0,   382,   307,   379,     0,
     381,    42,     0,   372,    84,     0,   470,   385,   291,     0,
       0,   303,   289,     0,   387,   283,   287,     0,   288,     0,
       0,   284,   285,   286,     0,    45,     0,   388,   290,   340,
     371,    14,     0,     0,   157,   158,     0,   276,    31,     0,
       0,     0,   428,    22,   402,     0,   407,     0,   429,   435,
       0,     0,   433,     0,     0,     0,   434,    47,   431,   432,
     398,     0,   396,   279,   280,   281,     0,     0,   303,    34,
     223,     0,   234,   232,     0,   228,     0,   215,     0,   220,
       0,   211,     0,   209,   165,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,   178,     0,   421,   419,
     410,     0,   415,     0,   239,     0,   262,   258,   256,     0,
     250,   248,     0,   244,     0,     0,   376,   375,   128,    30,
      29,     4,     3,   384,    44,    43,   373,   341,   316,     0,
     524,     0,     0,     0,     0,     0,   470,   588,     0,     0,
       0,   559,     0,     0,     0,    90,    91,    92,    93,    94,
      95,    85,    97,    98,    99,   100,   101,   102,   103,   104,
       0,   105,   106,   107,   108,   109,   110,   111,     0,     0,
       0,   445,   484,    88,     0,   656,   135,   586,   707,     0,
     452,   457,   302,   304,   453,     0,   447,   449,   450,     0,
       0,   451,   459,     0,   472,   460,   473,     0,   461,   462,
     474,   475,   463,   476,   464,     0,   520,     0,   521,   477,
     483,   478,   479,   481,   480,     0,   482,   564,   705,   584,
     587,   592,   603,   593,   594,   595,   596,   585,   488,     0,
     489,   490,     0,   491,   492,     0,     0,     0,     0,   386,
      46,   346,     0,   303,     0,     0,   298,     0,   294,   296,
     339,   309,   338,     0,   311,     0,   470,     0,   342,   390,
     159,   160,    33,    32,    24,    25,    23,   406,     0,   404,
       0,     0,   430,    48,     0,   438,   400,   282,    35,   231,
       0,   236,     0,   227,     0,   225,   219,     0,   217,   213,
       0,     0,     0,     0,     0,    17,   131,     0,     0,     0,
       0,     0,   167,    16,   169,     0,   173,     0,     0,     0,
     418,     0,   423,     0,   414,     0,   412,   255,     0,   266,
     264,     0,   260,     0,   247,     0,   252,     0,   243,     0,
     241,   377,     0,   129,     5,   552,     0,   611,     0,   114,
       0,     0,     0,    96,    97,   103,     0,     0,     0,     0,
       0,   706,     0,     0,   592,   595,     0,   651,   653,   652,
     660,   662,   664,   666,   668,   670,   672,   680,   675,   682,
     686,   689,   693,   694,   697,   700,   708,   709,   703,   704,
       0,     0,   656,     0,   549,     0,     0,   554,     0,     0,
       0,     0,     0,     0,   706,   707,   593,   594,   698,   699,
       0,   458,     0,   470,     0,     0,     0,   308,     0,     0,
       0,     0,     0,     0,     0,   446,   448,    52,   454,   298,
     455,   471,   487,     0,     0,     0,   560,     0,     0,     0,
       0,     0,   113,   112,   659,     0,   710,   711,     0,   310,
       0,   344,   391,     0,     0,     0,   347,     0,     0,     0,
     327,   331,   346,     0,   315,   313,   299,   292,     0,     0,
     317,     0,     0,     0,   312,   337,   334,   335,   588,     0,
     355,   656,   655,   470,     0,   705,   343,   408,     0,   439,
     436,   235,     0,   233,   229,   221,     0,   182,     0,   191,
       0,   185,     0,   194,    18,     0,   180,     0,   188,   197,
       0,     0,   171,   175,   177,     0,   422,     0,   420,   416,
     263,     0,   268,     0,   259,     0,   257,   251,     0,   249,
     245,   130,     6,   553,     0,     0,   612,   646,    78,     0,
     644,     0,     0,     0,   702,   701,   695,   696,     0,   114,
       0,     0,   498,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   550,   556,   555,
     602,   614,   640,     0,   551,   591,   456,   485,     0,     0,
     589,   597,     0,   133,   604,   636,     0,     0,   590,   598,
       0,   134,   605,   637,     0,   621,     0,   634,   601,   643,
     639,    53,     0,     0,   656,   542,   544,     0,   541,     0,
     581,    72,   718,   717,   582,     0,   580,     0,   593,   583,
     567,   573,   561,   565,   562,   575,   613,   606,   638,     0,
     654,   293,   345,   349,     0,   325,     0,     0,     7,     0,
       0,   329,   348,     0,   328,    36,     0,   351,     0,   314,
     295,     0,   297,   301,   300,   318,   321,     0,   298,   319,
       0,   336,    39,     0,     0,     0,     0,   357,     0,   356,
       0,   437,   237,     0,     0,     0,     0,   181,   132,     0,
       0,     0,     0,   179,   424,   267,     0,   265,   261,   253,
       0,   649,   647,    79,   648,   645,   607,     0,   500,     0,
       0,     0,     0,     0,     0,   663,   665,   667,   669,   671,
     673,   674,   677,   676,   679,   678,   124,   681,     0,   125,
     683,   684,   685,   687,   688,   690,   691,   692,   470,   557,
       0,     0,   470,   617,   611,     0,     0,     0,   599,   618,
       0,     0,     0,   600,   620,     0,   635,    75,     0,     0,
       0,   545,    64,     0,   470,    73,     0,   579,    74,     0,
       0,   563,   566,    67,   577,   576,     0,   619,   350,   326,
       8,     0,   330,   332,    38,    37,   353,     0,   352,   440,
       0,   443,     0,   322,   323,   320,    41,    40,     0,     0,
       0,     0,     0,     0,   358,     0,   183,     0,     0,    19,
     192,     0,   186,     0,   195,     0,   189,     0,   202,     0,
     200,     0,   198,     0,   269,   650,   608,   609,     0,   715,
     712,   713,     0,   499,     0,     0,     0,   656,   495,     0,
     459,   466,   467,   468,   469,     0,   522,     0,   523,     0,
       0,   628,     0,   517,   615,   641,   622,     0,   616,   642,
     624,     0,    77,    76,   470,     0,   543,     0,    66,    65,
       0,     0,   547,     0,   574,    68,   578,   626,     0,   333,
     354,   441,     0,   444,    49,   442,   324,   359,     0,   361,
       0,     0,     0,     0,    21,   184,    20,   193,   187,   196,
     190,   201,   203,   199,   610,     0,   501,     0,   714,   661,
       0,     0,   470,   470,     0,     0,   558,     0,   629,     0,
     623,     0,   625,   525,   470,   470,     0,   470,     0,     0,
       0,   571,     0,     0,   627,    51,    50,   360,   362,     0,
       0,     0,     0,     0,     0,   515,     0,   504,     0,     0,
      58,     0,    56,     0,   716,     0,     0,   486,   496,     0,
       0,     0,   519,   630,     0,   632,     0,   526,   527,   470,
     529,   470,   470,     0,     0,     0,   572,    69,     0,   569,
     363,     0,   365,     0,   367,     0,   513,   516,   506,     0,
      57,     0,   505,    59,     0,   502,     0,    54,     0,    60,
       0,   470,   470,     0,     0,     0,   470,   631,   633,   528,
     530,   531,   470,   570,    71,    70,   568,   364,   366,   368,
       0,   514,    61,   507,    60,   503,    55,   470,   511,   509,
     510,     0,     0,   518,   470,     0,     0,     0,     0,   548,
     532,    63,    62,   512,   508,   470,   533,   470,   470,     0,
     470,     0,     0,   497,   534,   535,   470,   537,   470,   470,
       0,   536,   538,   539,   470,   540
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1027,  1639,  -163,   556,  -395, -1027,  1263,   396,    45,  -243,
   -1027,   122,  -480,  -144,  -225,    66, -1027,  1141, -1027,  1067,
   -1027, -1027,   454, -1027,   439, -1027,  1102, -1027, -1027, -1027,
     228, -1027, -1027, -1027, -1024, -1026, -1027,    92, -1027,   359,
   -1027, -1027,   139, -1027,   505, -1027,   367,   778,  -231,    -2,
   -1027, -1027, -1027,   774, -1027, -1027, -1027, -1027,  1144, -1027,
    -504,  -462,   227, -1027, -1027, -1027, -1027, -1027,   214, -1027,
   -1027, -1027, -1027,   320,  1299, -1027, -1027, -1027, -1027, -1027,
   -1027, -1027, -1027,  -247,  -113, -1027, -1027, -1027, -1027, -1027,
   -1027, -1027, -1027, -1027, -1027, -1027, -1027, -1027, -1027, -1027,
   -1027, -1027, -1027, -1027, -1027, -1027, -1027, -1027, -1027, -1027,
   -1027, -1027, -1027, -1027, -1027, -1027, -1027, -1027,   321, -1027,
      -1,   483,  1238,     9,  2598,   -72, -1027, -1027,  -208,   671,
    -626,  -803,  2781,   698,   757, -1027,    81,   -90,   883, -1027,
    -400,   488, -1027,  -378, -1027,   477,  -192, -1027, -1027, -1027,
     896,   -92,  -202, -1027,    38, -1027,   384, -1027,  1147, -1027,
     199,  1125,  1129, -1027,   -42,  -185, -1027, -1027, -1027, -1027,
   -1027, -1027, -1027, -1027, -1027, -1027, -1027, -1027, -1027, -1027,
   -1027, -1027,   -10,     5,    11,  -105,  1093, -1027, -1027,   140,
   -1027,  -147,  -423,  -349, -1027, -1027,  -598,  -348,  1581,  -655,
    -764, -1027, -1027, -1027, -1027, -1027,  -595, -1027, -1027, -1027,
   -1027, -1027, -1027,   251, -1025,   215,  -841,   144, -1027, -1027,
   -1027, -1027, -1027,  -524, -1027, -1027,   253,  -716,  -609,    71,
   -1027, -1027, -1027, -1027, -1027, -1027,   165, -1027, -1027, -1027,
     732, -1027,   533,  -757, -1027, -1027,   241,  -748, -1027, -1027,
   -1027, -1027,   554,  -425, -1027, -1027,   475,  -545, -1027,   727,
    1522,   676,  -550, -1027, -1027,   115,  2309, -1027,  2287, -1027,
   -1027,  -930, -1027,   618,   622,   619,   621,   627,   314, -1027,
     149,   244,   306,  -327,   838,  1006,  -850,  1202,  1360,  1558,
   -1027, -1027, -1027, -1027
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   597,   184,   523,   633,   826,    17,    18,   716,   280,
     484,   988,   989,   232,   233,    19,   179,   180,   227,   228,
     257,   834,   835,   851,   852,   190,   191,   200,   241,  1063,
    1064,   606,  1176,  1128,  1129,  1130,  1201,  1202,   941,   942,
     952,  1156,  1157,   800,   801,   936,   937,   717,    20,   541,
     366,   367,   624,   528,   108,   109,   110,   907,    96,   177,
     524,   487,   368,   369,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,   159,   160,   282,   283,   284,
     285,   498,   499,   281,    32,    33,    82,   158,   156,   272,
     153,   270,   268,   477,   149,   266,   264,   474,   261,   472,
     470,   672,   168,   304,   302,   519,   299,   517,   515,   708,
     295,   513,   511,   705,   508,   703,   701,   876,   203,    97,
      84,    85,   132,    86,   148,   204,   205,   206,   437,   438,
     439,   842,   371,   542,   543,   208,   209,   210,   444,   635,
     639,   640,   641,   447,   656,   657,   441,   211,   212,   213,
     432,   214,   448,   663,    34,    35,    63,   114,   115,   116,
     120,   215,   216,   217,    36,    37,    76,   142,   140,   251,
     135,   237,   235,   458,   165,   293,   291,   505,   287,   503,
     501,   697,    38,    77,    78,   139,   247,   248,   249,   843,
     972,   219,   375,   376,   377,   378,   379,   380,   381,  1019,
     382,   383,   384,   385,  1021,   386,   387,   388,   389,  1022,
     390,   391,  1008,  1086,  1131,  1132,  1174,  1166,   392,  1023,
     393,   394,  1024,   395,   396,  1026,   797,  1045,  1046,   397,
     398,  1028,   399,   400,   401,   402,   403,   404,  1029,   405,
     617,   406,   812,   813,   949,  1112,  1113,   814,   950,   407,
     618,   805,   806,   408,   409,   410,   544,   412,   530,   413,
     414,   545,   786,   416,   417,   718,   787,   547,   418,   419,
     625,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,  1087,   809
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,   253,   254,    42,   798,   202,    44,   456,    45,    56,
      46,   374,   831,    48,   449,   795,   592,   804,   796,   712,
     312,   665,   685,   664,   312,   242,   831,   607,   456,   456,
     234,   588,   589,   493,   202,   250,   464,   252,   971,    67,
     495,  1011,   497,   653,    79,    89,   485,   317,   651,   630,
     774,    90,    91,   465,   782,   769,   953,    55,    95,   107,
     290,   825,   442,   121,   951,    41,   654,   955,   128,   445,
     130,   131,   133,   825,   817,   259,   218,   131,   144,   145,
     136,   789,   150,   370,  1089,    66,   137,   202,   141,   769,
     170,    88,   152,   155,   157,   166,   246,   769,   442,   985,
     172,   167,   676,  1173,  1169,   218,  1177,   427,   770,   186,
     731,    60,   769,   435,   127,    73,   201,   678,   854,    79,
      39,   221,   128,   778,   130,   522,   580,    47,   242,   581,
     457,   118,   459,   771,   163,  1012,   107,    39,    61,   732,
      74,   772,    39,  1173,   202,   258,   466,   236,   779,   446,
     677,  1206,   229,   435,  1020,  1207,   780,    81,   218,   263,
     265,    39,  1088,   269,   427,   679,    39,   231,   296,   288,
     830,   887,   610,    39,   308,   289,    95,   292,   298,   301,
     303,  1173,   500,   313,   199,   468,   504,   107,   506,    56,
     807,   374,    39,   318,   365,  1055,  1167,   201,   201,   246,
      39,   433,   804,   962,   240,   436,  1056,    61,    39,   724,
     725,   726,   727,   256,   863,   218,   864,   628,   865,   245,
     866,   230,   231,    39,   452,   631,   632,   128,   454,   130,
      56,    50,    43,   824,   629,   138,   611,    55,   107,   107,
     858,   107,   436,   838,  1133,   666,    56,   836,   493,   769,
     493,   847,   668,   684,   258,   258,   695,   791,   616,  1115,
     770,   374,   364,   370,  1125,  1125,   199,   839,    68,   669,
    1167,   471,    50,   480,   482,   486,   488,   490,    55,   442,
     426,  1125,    57,  1126,  1126,   771,   810,  1171,   733,    79,
    1178,   124,   175,   982,    55,   690,   734,   811,    74,   502,
    1126,   134,    80,   979,   981,   510,   512,   240,   146,   516,
     774,   782,   691,   129,   442,   817,   193,   526,   220,   527,
    1125,   461,   245,   256,   572,   147,   575,    81,  1020,   222,
     522,  1106,  1125,   370,  1108,  1178,    39,   426,    52,  1126,
     891,    81,   680,   796,   229,  1048,    48,    60,  1125,   682,
     604,  1126,    39,   667,    56,    62,   584,   584,   223,   769,
      39,   231,   107,  1127,  1168,    75,    83,  1126,  -164,    52,
     778,  1032,   306,   307,   365,   807,    92,  1037,   609,    52,
    1172,    39,  1041,    87,   766,   746,   747,   748,   712,    65,
     681,   316,   229,  1153,  1025,   779,   696,   683,   698,   231,
     699,   196,    55,   983,   176,   440,  1058,   275,   276,   277,
     278,   164,   169,    49,    52,    73,   279,  1020,  1020,  1175,
      59,   374,  1020,   436,   915,   916,   917,   525,   822,   107,
     107,  1203,   644,    39,   312,   181,   967,  1137,   312,    93,
      74,   107,   364,   655,   661,   592,   117,  1205,   493,   431,
    1020,  -389,   796,   182,    94,   796,    79,   455,   436,   243,
      60,  1020,   492,  1020,  1020,   185,  1020,  1215,    39,    80,
      39,   616,  1020,  1071,  1020,  1020,   173,    64,   374,    65,
    1020,   925,   486,   312,   926,   798,   161,  1159,   275,   276,
     277,   278,   123,   370,    81,   178,   795,   279,   637,   796,
    1229,  1231,   481,   483,   521,   489,   491,   580,  1076,   637,
     581,  1076,   364,  1076,   796,  1076,  1240,    69,   702,    70,
     711,  1120,  1122,  1124,  -494,  1074,  1212,  1213,  1193,  -494,
    -494,  1219,  -655,  -655,   584,   584,   584,   584,   598,   741,
     742,   619,   599,   692,   620,   600,   119,   743,   744,  1144,
     370,  1146,   312,   594,   230,   229,   312,   595,   162,  1226,
     596,   243,   243,  1010,    65,   286,   151,   154,  1025,   182,
    1233,   123,  1234,  1235,   171,  1237,   174,  -719,   761,   762,
     745,  1241,  -719,  1242,  1243,   585,   585,   188,   796,  1245,
     609,   572,   874,   773,   775,   431,   189,   781,   783,   182,
     192,  1072,   790,   224,   365,   275,   276,   277,   278,   930,
     118,   794,   931,   802,   279,   225,   594,   816,   818,   574,
     595,   796,   796,   596,  -303,    39,    71,    56,    72,   751,
     752,   107,   827,   262,   753,   107,   609,   796,   626,   627,
     107,   107,   275,   276,   277,   278,   609,  -657,  -657,   107,
     848,   279,   297,   300,  -658,  -658,   305,  1025,  1025,   598,
     693,   365,  1025,   599,   739,   226,   600,   740,  -706,  -706,
     229,   411,   364,   662,   486,   122,   486,   123,   486,   793,
     486,   793,   312,   830,   274,   868,    39,   594,   869,   871,
    1025,   595,   182,  -168,   596,  -303,   603,   873,   125,   637,
     126,  1025,  -493,  1025,  1025,   311,  1025,  -493,  -493,   637,
     860,  -172,  1025,   620,  1025,  1025,   196,   637,   925,   312,
    1025,   926,   312,   622,   623,   997,   999,  1001,  1003,   364,
    -708,  -708,   584,   584,   584,   584,   584,   584,   584,   584,
     584,   584,   584,   906,   584,   584,   584,   584,   584,   584,
     584,   584,   275,   276,   277,   278,  1208,     1,   642,   112,
     450,   279,   182,   585,   585,   585,   585,   924,   930,   443,
       3,   931,   456,   593,   456,     4,   456,   446,   456,   509,
       6,  -706,  -706,    56,  1223,  -315,   714,   230,   593,   182,
      65,   107,     7,   615,     9,   196,  -706,  -706,   802,    11,
     594,   411,   182,  1054,   595,   182,   776,   596,  -303,   784,
     312,   961,   312,    13,    39,   594,   112,   494,   113,   855,
    -707,  -707,   596,  -303,  -709,  -709,   182,   609,   963,   593,
     960,   107,   883,   451,   107,   883,   112,  -706,  -706,   598,
     647,   648,   803,   856,     1,   112,   600,   686,   655,   687,
     688,   411,   229,   773,   781,   881,   594,     3,   816,   884,
     595,   496,     4,   596,  -656,  -656,   793,     6,   749,   750,
     594,    39,   415,   522,   595,   113,   689,   596,   231,     7,
       8,     9,  1096,    10,   670,   648,    11,   112,   584,   584,
     902,   903,   904,   905,   372,   113,  -176,   112,   112,   637,
      13,   112,   637,   312,   113,   579,  1092,    15,   986,   987,
     687,   990,   987,   687,  -706,  -706,  1017,   870,   872,  -458,
     572,   411,   531,  1034,  1035,   992,   987,   687,  1038,  1039,
     994,   987,   687,   594,   996,   230,   229,   595,   112,   112,
     596,   112,   572,   998,   230,   231,   113,  1000,   230,   229,
     821,   648,    16,   373,   112,   112,   113,   113,   570,  1059,
     113,   585,   585,   585,   585,   585,   585,   585,   585,   585,
     585,   585,   571,   585,   585,   585,   585,   585,   585,   585,
     585,  1002,   230,   231,   582,   486,   991,   993,   995,  1027,
     910,   911,   912,   867,   374,   687,   -96,   113,   113,   841,
     113,   182,   415,   -89,   861,   648,  1075,   987,     1,   605,
     584,  1196,   584,   113,   113,  1077,   987,  1078,   987,   529,
     602,     3,   374,  1079,   987,   604,     4,   803,  1080,   230,
       5,     6,   608,  1209,   420,  1081,   230,  1082,   230,  1083,
     230,   612,   572,     7,     8,     9,   613,    10,  1179,  1180,
      11,  1111,   415,   900,   901,   913,   914,   614,   621,   649,
     445,   231,   112,   694,    13,   713,   370,   714,   411,   721,
     723,    15,   735,   736,   372,   737,   738,   756,   757,   758,
     759,   411,   760,   764,   765,   586,   586,   788,   411,   923,
    1017,   572,   794,   648,   370,   828,   832,   833,   849,   850,
      56,   853,   572,   572,    98,   572,   859,   123,  1111,   888,
      99,   609,   928,   890,   100,   918,    16,   585,   585,  1110,
     919,   113,   415,   920,   584,   101,   102,   921,   103,   112,
     112,   922,   927,   373,   929,   104,   932,   933,   411,   105,
     934,   112,   935,  -546,   372,   944,   943,   572,   940,   572,
     572,    98,   609,  1194,   947,   948,   811,    99,   810,   956,
     793,   100,   957,  1027,   420,   958,   959,  1005,   960,   968,
     974,  1007,   101,   102,   984,   103,  1014,   365,  1009,  1017,
    1017,    65,   104,  1053,  1017,  1013,   105,  1047,   113,   113,
     572,  1060,  1061,  1062,  1065,  1068,  1093,   106,   584,  1067,
     113,  1069,   421,   373,  1070,   365,  1073,  1085,    39,  1090,
    1091,  -465,  1017,  1094,   420,  1095,  1097,  1098,  1100,  1099,
    1101,  1200,  1102,  1017,  1104,  1017,  1017,  1114,  1017,  1149,
    1109,  1117,  1155,  1118,  1017,  1142,  1017,  1017,   729,   585,
     687,   585,  1017,  1151,  1225,   364,  1158,  1160,  1161,  1163,
    1162,  1179,  1027,  1027,  1165,    39,  1164,  1027,  1181,  1182,
    1186,  1185,  1187,   586,   586,   586,   586,  1188,  1192,   415,
    1197,  1198,  1204,   364,  1199,  1180,  1216,  1224,  1232,  1227,
    1236,  1238,   415,  1244,   420,  1027,   892,    58,   965,   415,
     977,  1116,   315,  1222,   453,  1195,  1027,   730,  1027,  1027,
    1049,  1027,    98,  1043,   372,   945,   720,  1027,    99,  1027,
    1027,   372,   100,   372,   728,  1027,    51,   143,   645,   840,
     310,   964,   309,   101,   102,   430,   103,   976,   428,   643,
     195,   112,   421,   104,   463,   112,   314,   105,  1134,   415,
     112,   112,   808,  1170,  1221,  1210,     1,  1140,   954,   112,
     815,  1154,   895,   585,   946,   897,    98,   896,   898,     3,
       0,   372,    99,   373,     4,   899,   100,     0,     0,     6,
     373,     0,   373,     0,     0,     0,     0,   101,   102,     0,
     103,     7,   421,     9,     0,     0,     0,   104,    11,     0,
     113,   105,     0,   411,   113,     0,     0,   411,   422,   113,
     113,     0,    13,     0,     0,     0,    39,     0,   113,     0,
       0,     0,     0,   411,     0,   411,     0,     0,     0,   411,
     373,     0,     0,     0,     0,     0,     0,   585,     0,     0,
       0,   420,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   908,   420,     0,     0,     0,     0,   636,
       0,   420,   421,     0,     0,     0,     0,     0,     0,     0,
      39,   586,   586,   586,   586,   586,   586,   586,   586,   586,
     586,   586,     0,   586,   586,   586,   586,   586,   586,   586,
     586,     1,     0,     0,     0,     0,     0,     0,     0,     2,
       0,   112,     0,     0,     3,     0,     0,     0,   372,     4,
       0,   420,   909,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     9,   411,
      10,     0,   411,    11,     0,   411,     0,   808,   422,     1,
       0,   112,     0,     0,   112,    12,     0,    13,     0,    98,
       0,     0,     3,    14,    15,    99,     0,     4,     0,   100,
     113,     0,     6,     0,     0,     0,   423,   373,     0,     0,
     101,   102,     0,   103,     7,     0,     9,   411,   411,   411,
     104,    11,     0,     0,   105,     0,     0,     0,   422,   411,
     411,     0,   411,     0,   411,    13,     0,     0,     0,    16,
     113,     0,     0,   113,   415,     0,     0,     0,   415,   421,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,   421,     0,   415,     0,   415,   586,   586,   421,
     415,     0,     0,     3,   411,     0,   411,   411,     4,     0,
       0,     0,   650,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,     0,     7,    53,     9,   422,    54,
       0,     0,    11,     0,   411,     0,   411,   411,   411,     0,
       0,   411,     0,     0,     0,     0,    13,   411,     0,   421,
       0,     0,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,   411,     0,     0,     0,   423,     0,     0,   411,
       0,   411,   411,     0,     0,     0,     0,     0,     0,     0,
     411,     0,   411,   411,     0,   411,     0,   411,     0,     0,
       0,   411,     0,   411,   411,     0,     0,     0,     0,   411,
     415,     0,     0,   415,     0,     0,   415,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   423,     0,     0,   586,
       0,   586,     0,     0,     0,     0,   183,     0,     0,     0,
       0,   187,     0,     0,   424,     0,   420,     0,     0,     0,
     420,     0,     0,     0,     0,     0,     0,     0,   415,   415,
     415,     0,     0,     0,     0,     0,   420,     0,   420,     0,
     415,   415,   420,   415,     0,   415,     0,     1,     0,     0,
       0,     0,   372,     0,     0,   422,     0,     0,     0,     0,
       3,     0,     0,     0,     0,     4,   423,     0,   422,     5,
       6,     0,     0,     0,     0,   422,     0,     0,     0,     0,
       0,     0,     7,     8,     9,   415,    10,   415,   415,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     183,    12,     0,    13,     0,     0,     0,     0,     0,    14,
      15,   373,     0,   586,     0,   415,     0,   415,   415,   415,
       0,     0,   415,     0,     0,   422,     0,     0,   415,     0,
       0,     0,     0,     0,     0,     0,     0,   372,     0,     0,
     587,   587,   420,   415,   424,   420,     0,     0,   420,     0,
     415,     0,   415,   415,     0,    16,     0,   183,     0,     0,
       0,   415,     0,   415,   415,   372,   415,   573,   415,     0,
       0,     0,   415,     0,   415,   415,     0,     0,     0,     0,
     415,     0,     0,     0,   421,     0,     0,   586,   421,     0,
     420,   420,   420,     0,   424,     0,   373,     0,     0,     0,
       0,     0,   420,   420,   421,   420,   421,   420,     0,     0,
     421,     0,     0,   423,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   373,     0,   423,     0,     0,     0,
       0,     0,     0,   423,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   420,     0,   420,
     420,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   424,     0,     0,   601,     0,     0,
       0,   187,     0,     0,     0,     0,     0,   420,     0,   420,
     420,   420,     0,   423,   420,     0,     0,     0,     0,     0,
     420,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   420,     0,     0,     0,     0,
     421,     0,   420,   421,   420,   420,   421,     0,   587,   587,
     587,   587,     0,   420,     0,   420,   420,     0,   420,     0,
     420,     0,   183,     0,   420,   646,   420,   420,     0,     0,
       0,     0,   420,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   421,   421,
     421,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     421,   421,     0,   421,     0,   421,     0,     0,     0,     0,
     422,     0,     0,     0,   422,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   587,     0,     0,
     422,     0,   422,     0,     0,     0,   422,     0,     0,     0,
       0,   424,     0,     0,     0,   421,     0,   421,   421,     0,
       0,     0,     0,     0,   424,     0,   715,   719,     0,     0,
       0,   424,     0,     0,   767,     0,     0,     0,     0,     0,
       0,   187,     0,     0,     0,   421,     0,   421,   421,   421,
       0,     0,   421,     0,     0,     0,     0,     0,   421,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   421,     0,     0,     0,     0,     0,     0,
     421,   424,   421,   421,   601,     0,     0,     0,     0,     0,
       0,   421,     0,   421,   421,     0,   421,     0,   421,     0,
       0,     0,   421,     0,   421,   421,   422,     0,   646,   422,
     421,     0,   422,     0,     0,     0,   587,   587,   587,   587,
     587,   587,   587,   587,   587,   587,   587,     0,   587,   587,
     587,   587,   587,   587,   587,   587,     0,     0,   423,     0,
       0,     0,   423,     0,     0,     0,     0,     0,     0,   845,
       0,     0,     1,     0,   422,   422,   422,     0,   423,     0,
     423,   601,    98,     0,   423,     3,   422,   422,    99,   422,
       4,   422,   100,     0,     0,     6,     0,     0,     0,     0,
       0,     0,   587,   101,   102,     0,   103,     7,     8,   194,
     195,    10,     0,   104,    11,     0,     0,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,   422,     0,   422,   422,    15,   882,     0,     0,   885,
       0,     0,     0,     0,     0,     0,     0,    60,   187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   422,     0,   422,   422,   422,     0,     0,   422,     0,
       0,     0,     0,     0,   422,     0,   196,   197,     0,     0,
     198,     0,     0,     0,   423,     0,    39,   423,     0,   422,
     423,     0,   587,   587,     0,     0,   422,     0,   422,   422,
       0,     0,     0,     0,     0,     0,     0,   422,     0,   422,
     422,     0,   422,     0,   422,     0,     0,     0,   422,     0,
     422,   422,   601,     0,     0,     0,   422,     0,     0,     0,
       0,     0,   423,   423,   423,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   423,   423,     0,   423,     0,   423,
       0,     0,     0,     0,     0,     0,   424,     0,     0,     0,
     424,     0,     0,     0,     0,   973,     0,   646,   975,     0,
       0,     0,     0,     0,     0,     0,   424,     0,   424,  1018,
       0,     0,   424,  1033,     0,     0,     0,     0,     0,   423,
       0,   423,   423,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1052,     0,     0,     0,     0,
       0,     0,     0,     0,   587,     0,   587,     0,     0,   423,
       0,   423,   423,   423,     0,   183,   423,   187,     0,     0,
       0,     0,   423,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   423,     0,     0,
       0,     0,     0,     0,   423,     0,   423,   423,     0,     0,
       0,     0,     0,     0,     0,   423,     0,   423,   423,     0,
     423,     0,   423,     0,     0,     0,   423,     0,   423,   423,
       0,     0,   424,     0,   423,   424,     0,     0,   424,     0,
     548,     0,     0,  1066,     0,     0,   548,   548,     0,     0,
       0,     0,     0,     0,     0,  1103,     0,     0,     0,     0,
       0,     0,   546,     0,     0,     0,     0,   548,   576,   578,
       0,     0,     0,     0,     0,     0,     0,   548,   587,     0,
     424,   424,   424,     0,     0,     0,     0,     0,     0,   583,
       0,     0,   424,   424,     0,   424,     0,   424,     0,   590,
       0,     0,     0,   767,  1138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1147,  1148,     0,  1150,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   424,     0,   424,
     424,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,     0,     0,
    1189,     0,  1190,  1191,     0,     0,     0,   424,     0,   424,
     424,   424,     0,     0,   424,     0,     0,   260,     0,     0,
     424,   267,     0,     0,   271,     0,   273,     0,     0,     0,
       0,     0,  1018,  1033,     0,   424,   294,  1052,     0,     0,
       0,     0,   424,  1220,   424,   424,     0,     0,     0,     0,
       0,     0,     0,   424,     0,   424,   424,     0,   424,     0,
     424,     0,     0,     0,   424,  1103,   424,   424,     0,     0,
       0,     0,   424,     0,     0,     0,  1138,     0,  1147,  1148,
       0,  1150,     0,     0,     0,     0,     0,  1189,   548,  1190,
    1191,     0,     0,     0,     0,  1220,     0,   548,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     722,     0,   111,     0,     0,     0,     0,     0,     0,   590,
       0,     0,     0,     0,     0,     0,     0,   548,   548,   469,
       0,     0,   473,     0,   475,     0,   476,     0,   478,   548,
     479,     0,     0,     0,     0,     0,     0,     0,     0,   754,
     755,   548,     0,     0,     0,   548,     0,     0,     0,   548,
       0,   763,     0,   507,     0,     0,     0,   514,     0,   207,
     518,   548,   520,   768,     0,     0,     0,   777,   548,     0,
       0,     0,   548,     0,     0,     0,     0,     0,     0,   244,
       0,     0,     0,   799,     0,     0,     0,     0,   207,     0,
     819,     0,     0,     0,   820,     0,   548,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     0,   844,     0,
       0,    98,     0,     0,     3,     0,     0,    99,     0,     4,
     111,   100,     0,     0,     6,     0,     0,     0,     0,     0,
     425,   207,   101,   102,   434,   103,     7,     8,   194,   195,
      10,     0,   104,    11,     0,     0,   105,     0,     0,     0,
       0,   548,     0,     0,     0,     0,     0,    13,   548,     0,
     548,     0,     0,     0,    15,     0,     0,     0,   548,     0,
     548,   460,   244,   880,   434,     0,    60,     0,     0,     0,
       0,     0,   889,     0,     0,     0,     0,   425,   207,     0,
     893,     0,   894,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   196,   255,     0,     0,   198,
       0,     0,     0,     0,     0,    39,     0,     0,   671,     0,
     673,     0,   674,     0,     0,   675,     0,     0,     0,   548,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   939,     0,     0,     0,     0,   700,     0,     0,   704,
       0,   706,     0,   707,     0,   709,     0,   710,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     1,     0,     0,   321,     0,     0,     0,
     548,   548,     0,    98,     0,     0,     3,   327,     0,    99,
     844,     4,     0,   100,     0,     0,     6,     0,     0,     0,
       0,     0,     0,     0,   101,   102,     0,   103,     7,     0,
       9,   332,     0,     0,   104,    11,     0,     0,   105,     0,
     333,     0,     0,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   535,   349,     0,   351,
     352,   353,   354,   355,   356,   357,     0,   548,   548,     0,
       0,     0,   634,   638,   548,     0,     0,     0,     0,   548,
     358,   359,   548,     0,   652,     0,     0,     0,     0,  1030,
     548,     0,     0,     0,     0,   360,     0,     0,     0,     0,
       0,   792,     0,   548,  1042,     0,     0,   363,     0,     0,
       0,     0,  1051,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     862,     0,     0,     1,     0,     0,   321,     0,     0,     0,
       0,     0,     0,    98,     0,     0,     3,   327,     0,    99,
       0,     4,     0,   100,     0,     0,     6,     0,     0,   875,
       0,   877,     0,   878,   101,   102,   879,   103,     7,     0,
       9,   332,     0,     0,   104,    11,     0,     0,   105,     0,
     333,     0,     0,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   535,   349,     0,   351,
     352,   353,   354,   355,   356,   357,     0,     0,     0,   548,
       0,     0,     0,     0,     0,     0,     0,     0,   548,   548,
     548,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   844,     0,     0,     0,   360,     0,   548,   548,     0,
       0,     0,   548,     0,     0,     0,   548,   363,   548,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1135,
    1136,     0,     0,     0,  1141,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   638,     0,     0,     0,   829,     0,
       0,     1,     0,   634,   638,     0,   548,     0,     0,     0,
       0,    98,   638,     0,     3,     0,     0,    99,     0,     4,
       0,   100,     0,     0,     6,     0,     0,     0,  1184,     0,
       0,     0,   101,   102,     0,   103,     7,     0,     9,     0,
       0,     0,   104,    11,     0,     0,   105,   548,     0,     0,
       0,     0,   548,     0,  1004,     0,     0,    13,     0,     0,
       0,     0,     0,     0,  1006,     0,     0,     0,     0,  1211,
       0,     0,     0,     0,  1218,     1,   319,   320,   321,   322,
     323,  1125,   324,     0,   325,    98,   326,     0,     3,   327,
     328,    99,     0,     4,   329,   100,     0,     0,     6,     0,
    1126,     0,   330,     0,   823,     0,   101,   102,   331,   103,
       7,     8,     9,   332,    10,    39,   104,    11,     0,     0,
     105,     0,   333,   334,     0,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   358,   359,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   360,     0,     0,
       0,     0,     0,   362,     0,  1084,     0,     0,     0,   363,
       0,     0,     0,     0,   638,     0,     0,   638,     1,   319,
     320,   321,   322,   323,     0,   324,     0,   325,    98,   326,
       0,     3,   327,   328,    99,     0,     4,   329,   100,     0,
       0,     6,     0,     0,     0,   330,     0,     0,     0,   101,
     102,   331,   103,     7,     8,     9,   332,    10,     0,   104,
      11,     0,     0,   105,     0,   333,   334,     0,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   358,   359,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     360,     0,     0,   361,     0,     0,   362,     0,     0,     0,
       0,     0,   363,     1,   319,   320,   321,   322,   323,     0,
     324,     0,   325,    98,   326,     0,     3,   327,   328,    99,
       0,     4,   329,   100,     0,     0,     6,     0,     0,     0,
     330,     0,     0,     0,   101,   102,   331,   103,     7,     8,
       9,   332,    10,     0,   104,    11,     0,     0,   105,     0,
     333,   334,     0,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     358,   359,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   360,     0,  -470,     0,     0,
       0,   362,     0,     0,     0,     0,     0,   363,     1,   319,
     320,   321,   322,   323,     0,   324,     0,   325,    98,   326,
       0,     3,   658,   328,    99,     0,     4,   329,   100,     0,
       0,     6,     0,     0,     0,   330,     0,     0,     0,   101,
     102,   331,   103,     7,     8,     9,   332,    10,     0,   104,
      11,     0,     0,   105,     0,   659,   334,     0,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   358,   359,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     360,     0,     0,   660,     0,     0,   362,     0,     0,     0,
       0,     0,   363,     1,   319,   320,   321,   322,   323,     0,
     324,     0,   325,    98,   326,     0,     3,   327,   328,    99,
       0,     4,   329,   100,     0,     0,     6,     0,     0,     0,
     330,     0,     0,     0,   101,   102,   331,   103,     7,     8,
       9,   332,    10,     0,   104,    11,     0,     0,   105,     0,
     333,   334,     0,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,   321,     0,     0,
     358,   359,     0,     0,    98,     0,     0,     3,   327,     0,
      99,     0,     4,     0,   100,   360,     0,     6,   857,     0,
       0,   362,     0,     0,     0,   101,   102,   363,   103,     7,
       0,     9,   332,     0,     0,   104,    11,     0,     0,   105,
       0,   333,     0,     0,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   535,   349,     0,
     351,   352,   353,   354,   355,   356,   357,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,   358,   359,     0,     0,    98,     0,     0,     3,     0,
       0,    99,     0,     4,     0,   100,   360,     0,     6,     0,
       0,     0,  1139,     0,     0,     0,   101,   102,   363,   103,
       7,     8,   194,   195,    10,     0,   104,    11,     0,     0,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,    13,     0,     0,     0,     0,     0,     0,    15,    98,
       0,     0,     3,     0,     0,    99,     0,     4,     0,   100,
      60,     0,     6,     0,     0,     0,     0,     0,     0,     0,
     101,   102,     0,   103,     7,     8,   194,   195,    10,     0,
     104,    11,     0,     0,   105,     0,     0,     0,     0,   196,
     429,     0,     0,   198,     0,    13,     0,     0,     0,    39,
       1,     0,    15,     0,     0,     0,     0,     0,     0,     0,
      98,     0,     0,     3,    60,     0,    99,     0,     4,     0,
     100,     0,     0,     6,     0,     0,     0,     0,     0,     0,
       0,   101,   102,     0,   103,     7,     8,     9,   195,    10,
       0,   104,    11,   196,   467,   105,     0,   198,     1,     0,
       0,     0,     0,    39,     0,     0,    13,     0,    98,     0,
       0,     3,     0,    15,    99,     0,     4,     0,   100,     0,
       0,     6,     0,     0,     0,    60,     0,     0,     0,   101,
     102,     0,   103,     7,     8,     9,   195,    10,     0,   104,
      11,     0,     0,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,    13,   238,     0,     0,   239,     0,
       0,    15,    98,     0,    39,     3,     0,     0,    99,     0,
       4,     0,   100,    60,     0,     6,     0,     0,     0,     0,
       0,     0,     0,   101,   102,     0,   103,     7,    53,     9,
     195,    54,     0,   104,    11,     0,     0,   105,     0,     0,
       1,     0,     0,   462,     0,     0,   239,     0,    13,     0,
      98,     0,    39,     3,     0,    15,    99,     0,     4,     0,
     100,     0,     0,     6,     0,     0,     0,    60,     0,     0,
       1,   101,   102,     0,   103,     7,    53,     9,     0,    54,
      98,   104,    11,     3,     0,   105,    99,     0,     4,     0,
     100,     0,     0,     6,     0,     0,    13,   591,     0,     0,
       1,   101,   102,    15,   103,     7,    39,     9,     0,     0,
      98,   104,    11,     3,     0,   105,    99,     0,     4,     0,
     100,     0,     0,     6,     0,     0,    13,     0,     0,     0,
       1,   101,   102,     0,   103,     7,     0,     9,     0,     0,
      98,   104,    11,     3,     0,   105,    99,     0,     4,     0,
     100,     0,     0,     6,    39,     0,    13,     0,     0,     0,
       0,   101,   102,     0,   103,     7,     0,     9,     0,     0,
       0,   104,    11,   837,     0,   105,     0,     0,     1,     0,
       0,     0,     0,     0,    39,     0,    13,   591,    98,     0,
       0,     3,     0,     0,    99,     0,     4,     0,   100,     0,
       0,     6,     0,   846,     0,     0,     0,     0,     1,   101,
     102,     0,   103,     7,    39,     9,     0,     0,    98,   104,
      11,     3,     0,   105,    99,     0,     4,     0,   100,     0,
       0,     6,     0,     0,    13,     0,     0,     0,     0,   101,
     102,     0,   103,     7,    39,     9,     0,     0,     0,   104,
      11,     0,     0,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   966,     0,     0,     0,     0,     0,   319,   320,   321,
     322,   323,    39,   324,     0,   325,    98,   326,     0,     0,
     327,   328,    99,     0,     0,   329,   100,     0,     0,     0,
       0,     0,     0,   330,     0,     0,     0,   101,   102,   331,
     103,     0,    39,     0,   332,     0,     0,   104,     0,     0,
       0,   105,     0,   333,   334,     0,   335,   336,   337,   338,
     339,   340,   533,   534,   343,   344,   345,   346,   347,   535,
     349,   350,   351,   352,   353,   354,   355,   356,   357,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   358,   359,     0,     0,   319,   320,   321,
     322,   323,     0,  1015,     0,   325,    98,   326,   360,     0,
     327,   328,    99,     0,   362,   329,   100,     0,     0,     0,
     363,     0,     0,   330,     0,     0,     0,   101,   102,   331,
     103,     0,     0,     0,   332,     0,     0,   104,     0,     0,
       0,   105,     0,   333,  1016,     0,   335,   336,   337,   338,
     339,   340,   533,   534,   343,   344,   345,   346,   347,   535,
     349,   350,   351,   352,   353,   354,   355,   356,   357,     0,
       0,     0,     0,     0,   321,   532,     0,     0,     0,     0,
       0,    98,     0,   358,   359,   327,     0,    99,     0,     0,
       0,   100,     0,     0,     0,     0,     0,     0,   360,     0,
       0,     0,   101,   102,   362,   103,     0,     0,     0,   332,
     363,     0,   104,     0,     0,     0,   105,     0,   333,     0,
       0,   335,   336,   337,   338,   339,   340,   533,   534,   343,
     344,   345,   346,   347,   535,   349,     0,   351,   352,   353,
     354,   355,   356,   357,     0,     0,     0,   536,   537,     0,
       0,     0,     0,     0,     0,   321,   532,     0,   358,   359,
     538,   539,    98,     0,     0,     0,   327,     0,    99,     0,
       0,   329,   100,   540,     0,   841,   969,     0,     0,     0,
     970,     0,     0,   101,   102,   363,   103,     0,     0,     0,
     332,     0,     0,   104,     0,     0,     0,   105,     0,   333,
       0,     0,   335,   336,   337,   338,   339,   340,   533,   534,
     343,   344,   345,   346,   347,   535,   349,     0,   351,   352,
     353,   354,   355,   356,   357,     0,     0,     0,   536,   537,
       0,     0,     0,     0,     0,     0,   321,   532,     0,   358,
     359,   538,   539,    98,     0,     0,     0,   327,     0,    99,
       0,     0,     0,   100,   540,     0,   196,     0,     0,     0,
       0,     0,     0,     0,   101,   102,   363,   103,     0,     0,
       0,   332,     0,     0,   104,     0,     0,     0,   105,     0,
     333,     0,     0,   335,   336,   337,   338,   339,   340,   533,
     534,   343,   344,   345,   346,   347,   535,   349,     0,   351,
     352,   353,   354,   355,   356,   357,     0,     0,     0,   536,
     537,     0,     0,     0,     0,     0,     0,   321,   532,     0,
     358,   359,   538,   539,    98,     0,     0,     0,   327,     0,
      99,     0,     0,     0,   100,   540,     0,     0,     0,     0,
       0,   577,     0,     0,     0,   101,   102,   363,   103,     0,
       0,     0,   332,     0,     0,   104,     0,     0,     0,   105,
       0,   333,     0,     0,   335,   336,   337,   338,   339,   340,
     533,   534,   343,   344,   345,   346,   347,   535,   349,     0,
     351,   352,   353,   354,   355,   356,   357,     0,     0,     0,
     536,   537,     0,     0,     0,     0,     0,     0,   321,   532,
       0,   358,   359,   538,   539,    98,     0,     0,     0,   327,
       0,    99,     0,     0,     0,   100,   540,     0,     0,     0,
       0,   311,     0,     0,     0,     0,   101,   102,   363,   103,
       0,     0,     0,   332,     0,     0,   104,     0,     0,     0,
     105,     0,   333,     0,     0,   335,   336,   337,   338,   339,
     340,   533,   534,   343,   344,   345,   346,   347,   535,   349,
       0,   351,   352,   353,   354,   355,   356,   357,     0,     0,
       0,   536,   537,     0,     0,     0,     0,     0,     0,   321,
     532,     0,   358,   359,   538,   539,    98,     0,     0,     0,
     327,     0,    99,     0,     0,     0,   100,   540,   785,     0,
       0,     0,     0,     0,     0,     0,     0,   101,   102,   363,
     103,     0,     0,     0,   332,     0,     0,   104,     0,     0,
       0,   105,     0,   333,     0,     0,   335,   336,   337,   338,
     339,   340,   533,   534,   343,   344,   345,   346,   347,   535,
     349,     0,   351,   352,   353,   354,   355,   356,   357,     0,
       0,     0,   536,   537,     0,     0,     0,     0,     0,     0,
     321,   532,     0,   358,   359,   538,   539,    98,     0,     0,
       0,   327,     0,    99,     0,     0,     0,   100,   540,     0,
     841,     0,     0,     0,     0,     0,     0,     0,   101,   102,
     363,   103,     0,     0,     0,   332,     0,     0,   104,     0,
       0,     0,   105,     0,   333,     0,     0,   335,   336,   337,
     338,   339,   340,   533,   534,   343,   344,   345,   346,   347,
     535,   349,     0,   351,   352,   353,   354,   355,   356,   357,
       0,     0,     0,   536,   537,     0,     0,     0,     0,     0,
       0,   321,   532,     0,   358,   359,   538,   539,    98,     0,
       0,     0,   327,     0,    99,     0,     0,     0,   100,   540,
     886,     0,     0,     0,     0,     0,     0,     0,     0,   101,
     102,   363,   103,     0,     0,     0,   332,     0,     0,   104,
       0,     0,     0,   105,     0,   333,     0,     0,   335,   336,
     337,   338,   339,   340,   533,   534,   343,   344,   345,   346,
     347,   535,   349,     0,   351,   352,   353,   354,   355,   356,
     357,     0,     0,     0,   536,   537,     0,     0,     0,     0,
       0,     0,   321,   532,     0,   358,   359,   538,   539,    98,
       0,     0,     0,   327,     0,    99,     0,     0,     0,   100,
     540,     0,     0,     0,     0,     0,   938,     0,     0,     0,
     101,   102,   363,   103,     0,     0,     0,   332,     0,     0,
     104,     0,     0,     0,   105,     0,   333,     0,     0,   335,
     336,   337,   338,   339,   340,   533,   534,   343,   344,   345,
     346,   347,   535,   349,     0,   351,   352,   353,   354,   355,
     356,   357,     0,     0,     0,   536,   537,     0,     0,     0,
       0,     0,     0,   321,   532,     0,   358,   359,   538,   539,
      98,     0,     0,     0,   327,     0,    99,     0,     0,     0,
     100,   540,   978,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   102,   363,   103,     0,     0,     0,   332,     0,
       0,   104,     0,     0,     0,   105,     0,   333,     0,     0,
     335,   336,   337,   338,   339,   340,   533,   534,   343,   344,
     345,   346,   347,   535,   349,     0,   351,   352,   353,   354,
     355,   356,   357,     0,     0,     0,   536,   537,     0,     0,
       0,     0,     0,     0,   321,   532,     0,   358,   359,   538,
     539,    98,     0,     0,     0,   327,     0,    99,     0,     0,
       0,   100,   540,   980,     0,     0,     0,     0,     0,     0,
       0,     0,   101,   102,   363,   103,     0,     0,     0,   332,
       0,     0,   104,     0,     0,     0,   105,     0,   333,     0,
       0,   335,   336,   337,   338,   339,   340,   533,   534,   343,
     344,   345,   346,   347,   535,   349,     0,   351,   352,   353,
     354,   355,   356,   357,     0,     0,     0,   536,   537,     0,
       0,     0,     0,     0,     0,   321,   532,     0,   358,   359,
     538,   539,    98,     0,     0,     0,   327,     0,    99,     0,
       0,     0,   100,   540,  1031,     0,     0,     0,     0,     0,
       0,     0,     0,   101,   102,   363,   103,     0,     0,     0,
     332,     0,     0,   104,     0,     0,     0,   105,     0,   333,
       0,     0,   335,   336,   337,   338,   339,   340,   533,   534,
     343,   344,   345,   346,   347,   535,   349,     0,   351,   352,
     353,   354,   355,   356,   357,     0,     0,     0,   536,   537,
       0,     0,     0,     0,     0,     0,   321,   532,     0,   358,
     359,   538,   539,    98,     0,     0,     0,   327,     0,    99,
       0,     0,     0,   100,   540,  1036,     0,     0,     0,     0,
       0,     0,     0,     0,   101,   102,   363,   103,     0,     0,
       0,   332,     0,     0,   104,     0,     0,     0,   105,     0,
     333,     0,     0,   335,   336,   337,   338,   339,   340,   533,
     534,   343,   344,   345,   346,   347,   535,   349,     0,   351,
     352,   353,   354,   355,   356,   357,     0,     0,     0,   536,
     537,     0,     0,     0,     0,     0,     0,   321,   532,     0,
     358,   359,   538,   539,    98,     0,     0,     0,   327,     0,
      99,     0,     0,     0,   100,   540,  1040,     0,     0,     0,
       0,     0,     0,     0,     0,   101,   102,   363,   103,     0,
       0,     0,   332,     0,     0,   104,     0,     0,     0,   105,
       0,   333,     0,     0,   335,   336,   337,   338,   339,   340,
     533,   534,   343,   344,   345,   346,   347,   535,   349,     0,
     351,   352,   353,   354,   355,   356,   357,     0,     0,     0,
     536,   537,     0,     0,     0,     0,     0,     0,   321,   532,
       0,   358,   359,   538,   539,    98,     0,     0,     0,   327,
       0,    99,     0,     0,     0,   100,   540,     0,     0,     0,
       0,     0,  1050,     0,     0,     0,   101,   102,   363,   103,
       0,     0,     0,   332,     0,     0,   104,     0,     0,     0,
     105,     0,   333,     0,     0,   335,   336,   337,   338,   339,
     340,   533,   534,   343,   344,   345,   346,   347,   535,   349,
       0,   351,   352,   353,   354,   355,   356,   357,     0,     0,
       0,   536,   537,     0,     0,     0,     0,     0,     0,   321,
     532,     0,   358,   359,   538,   539,    98,     0,     0,     0,
     327,     0,    99,     0,     0,     0,   100,   540,  1057,     0,
       0,     0,     0,     0,     0,     0,     0,   101,   102,   363,
     103,     0,     0,     0,   332,     0,     0,   104,     0,     0,
       0,   105,     0,   333,     0,     0,   335,   336,   337,   338,
     339,   340,   533,   534,   343,   344,   345,   346,   347,   535,
     349,     0,   351,   352,   353,   354,   355,   356,   357,     0,
       0,     0,   536,   537,     0,     0,     0,     0,     0,     0,
     321,   532,     0,   358,   359,   538,   539,    98,     0,     0,
       0,   327,     0,    99,     0,     0,     0,   100,   540,  1119,
       0,     0,     0,     0,     0,     0,     0,     0,   101,   102,
     363,   103,     0,     0,     0,   332,     0,     0,   104,     0,
       0,     0,   105,     0,   333,     0,     0,   335,   336,   337,
     338,   339,   340,   533,   534,   343,   344,   345,   346,   347,
     535,   349,     0,   351,   352,   353,   354,   355,   356,   357,
       0,     0,     0,   536,   537,     0,     0,     0,     0,     0,
       0,   321,   532,     0,   358,   359,   538,   539,    98,     0,
       0,     0,   327,     0,    99,     0,     0,     0,   100,   540,
    1121,     0,     0,     0,     0,     0,     0,     0,     0,   101,
     102,   363,   103,     0,     0,     0,   332,     0,     0,   104,
       0,     0,     0,   105,     0,   333,     0,     0,   335,   336,
     337,   338,   339,   340,   533,   534,   343,   344,   345,   346,
     347,   535,   349,     0,   351,   352,   353,   354,   355,   356,
     357,     0,     0,     0,   536,   537,     0,     0,     0,     0,
       0,     0,   321,   532,     0,   358,   359,   538,   539,    98,
       0,     0,     0,   327,     0,    99,     0,     0,     0,   100,
     540,  1123,     0,     0,     0,     0,     0,     0,     0,     0,
     101,   102,   363,   103,     0,     0,     0,   332,     0,     0,
     104,     0,     0,     0,   105,     0,   333,     0,     0,   335,
     336,   337,   338,   339,   340,   533,   534,   343,   344,   345,
     346,   347,   535,   349,     0,   351,   352,   353,   354,   355,
     356,   357,     0,     0,     0,   536,   537,     0,     0,     0,
       0,     0,     0,   321,   532,     0,   358,   359,   538,   539,
      98,     0,     0,     0,   327,     0,    99,     0,     0,     0,
     100,   540,  1143,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   102,   363,   103,     0,     0,     0,   332,     0,
       0,   104,     0,     0,     0,   105,     0,   333,     0,     0,
     335,   336,   337,   338,   339,   340,   533,   534,   343,   344,
     345,   346,   347,   535,   349,     0,   351,   352,   353,   354,
     355,   356,   357,     0,     0,     0,   536,   537,     0,     0,
       0,     0,     0,     0,   321,   532,     0,   358,   359,   538,
     539,    98,     0,     0,     0,   327,     0,    99,     0,     0,
       0,   100,   540,  1145,     0,     0,     0,     0,     0,     0,
       0,     0,   101,   102,   363,   103,     0,     0,     0,   332,
       0,     0,   104,     0,     0,     0,   105,     0,   333,     0,
       0,   335,   336,   337,   338,   339,   340,   533,   534,   343,
     344,   345,   346,   347,   535,   349,     0,   351,   352,   353,
     354,   355,   356,   357,     0,     0,     0,   536,   537,     0,
       0,     0,     0,     0,     0,   321,   532,     0,   358,   359,
     538,   539,    98,     0,     0,     0,   327,     0,    99,     0,
       0,     0,   100,   540,     0,     0,     0,     0,     0,  1183,
       0,     0,     0,   101,   102,   363,   103,     0,     0,     0,
     332,     0,     0,   104,     0,     0,     0,   105,     0,   333,
       0,     0,   335,   336,   337,   338,   339,   340,   533,   534,
     343,   344,   345,   346,   347,   535,   349,     0,   351,   352,
     353,   354,   355,   356,   357,     0,     0,     0,   536,   537,
       0,     0,     0,     0,     0,     0,   321,   532,     0,   358,
     359,   538,   539,    98,     0,     0,     0,   327,     0,    99,
       0,     0,     0,   100,   540,     0,     0,     0,     0,     0,
    1217,     0,     0,     0,   101,   102,   363,   103,     0,     0,
       0,   332,     0,     0,   104,     0,     0,     0,   105,     0,
     333,     0,     0,   335,   336,   337,   338,   339,   340,   533,
     534,   343,   344,   345,   346,   347,   535,   349,     0,   351,
     352,   353,   354,   355,   356,   357,     0,     0,     0,   536,
     537,     0,     0,     0,     0,     0,     0,   321,   532,     0,
     358,   359,   538,   539,    98,     0,     0,     0,   327,     0,
      99,     0,     0,     0,   100,   540,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,   102,   363,   103,     0,
       0,     0,   332,     0,     0,   104,     0,     0,     0,   105,
       0,   333,     0,     0,   335,   336,   337,   338,   339,   340,
     533,   534,   343,   344,   345,   346,   347,   535,   349,     0,
     351,   352,   353,   354,   355,   356,   357,     0,     0,   321,
     536,   537,     0,     0,     0,     0,    98,     0,     0,     0,
     327,     0,    99,     0,     0,     0,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   540,   101,   102,     0,
     103,     0,     0,     0,   332,     0,     0,   104,   363,     0,
       0,   105,     0,   333,     0,     0,   335,   336,   337,   338,
     339,   340,   533,   534,   343,   344,   345,   346,   347,   535,
     349,     0,   351,   352,   353,   354,   355,   356,   357,     0,
       0,     0,     0,     0,   321,     0,     0,     0,     0,     0,
       0,    98,     0,   358,   359,   327,     0,    99,     0,     0,
       0,   100,     0,     0,     0,     0,     0,     0,   360,  1044,
       0,     0,   101,   102,     0,   103,     0,     0,     0,   332,
     363,     0,   104,     0,     0,     0,   105,     0,   333,     0,
       0,   335,   336,   337,   338,   339,   340,   533,   534,   343,
     344,   345,   346,   347,   535,   349,     0,   351,   352,   353,
     354,   355,   356,   357,     0,     0,     0,     0,     0,   321,
       0,     0,     0,     0,     0,     0,    98,     0,   358,   359,
     327,     0,    99,     0,     0,     0,   100,     0,     0,     0,
       0,     0,     0,   360,  1105,     0,     0,   101,   102,     0,
     103,     0,     0,     0,   332,   363,     0,   104,     0,     0,
       0,   105,     0,   333,     0,     0,   335,   336,   337,   338,
     339,   340,   533,   534,   343,   344,   345,   346,   347,   535,
     349,     0,   351,   352,   353,   354,   355,   356,   357,     0,
       0,     0,     0,     0,   321,     0,     0,     0,     0,     0,
       0,    98,     0,   358,   359,   327,     0,    99,     0,     0,
       0,   100,     0,     0,     0,     0,     0,     0,   360,  1107,
       0,     0,   101,   102,     0,   103,     0,     0,     0,   332,
     363,     0,   104,     0,     0,     0,   105,     0,   333,     0,
       0,   335,   336,   337,   338,   339,   340,   533,   534,   343,
     344,   345,   346,   347,   535,   349,     0,   351,   352,   353,
     354,   355,   356,   357,     0,     0,     0,     0,     0,   321,
       0,     0,     0,     0,     0,     0,    98,     0,   358,   359,
     327,     0,    99,     0,     0,     0,   100,     0,     0,     0,
       0,     0,     0,   360,  1152,     0,     0,   101,   102,     0,
     103,     0,     0,     0,   332,   363,     0,   104,     0,     0,
       0,   105,     0,   333,     0,     0,   335,   336,   337,   338,
     339,   340,   533,   534,   343,   344,   345,   346,   347,   535,
     349,     0,   351,   352,   353,   354,   355,   356,   357,     0,
       0,     0,     0,     0,   321,     0,     0,     0,     0,     0,
       0,    98,     0,   358,   359,   327,     0,    99,     0,     0,
       0,   100,     0,     0,     0,     0,     0,     0,   360,  1214,
       0,     0,   101,   102,     0,   103,     0,     0,     0,   332,
     363,     0,   104,     0,     0,     0,   105,     0,   333,     0,
       0,   335,   336,   337,   338,   339,   340,   533,   534,   343,
     344,   345,   346,   347,   535,   349,     0,   351,   352,   353,
     354,   355,   356,   357,     0,     0,     0,     0,     0,   321,
       0,     0,     0,     0,     0,     0,    98,     0,   358,   359,
     327,     0,    99,     0,     0,     0,   100,     0,     0,     0,
       0,     0,     0,   360,  1228,     0,     0,   101,   102,     0,
     103,     0,     0,     0,   332,   363,     0,   104,     0,     0,
       0,   105,     0,   333,     0,     0,   335,   336,   337,   338,
     339,   340,   533,   534,   343,   344,   345,   346,   347,   535,
     349,     0,   351,   352,   353,   354,   355,   356,   357,     0,
       0,     0,     0,     0,   321,     0,     0,     0,     0,     0,
       0,    98,     0,   358,   359,   327,     0,    99,     0,     0,
       0,   100,     0,     0,     0,     0,     0,     0,   360,  1230,
       0,     0,   101,   102,     0,   103,     0,     0,     0,   332,
     363,     0,   104,     0,     0,     0,   105,     0,   333,     0,
       0,   335,   336,   337,   338,   339,   340,   533,   534,   343,
     344,   345,   346,   347,   535,   349,     0,   351,   352,   353,
     354,   355,   356,   357,     0,     0,     0,     0,     0,   321,
       0,     0,     0,     0,     0,     0,    98,     0,   358,   359,
     327,     0,    99,     0,     0,     0,   100,     0,     0,     0,
       0,     0,     0,   360,  1239,     0,     0,   101,   102,     0,
     103,     0,     0,     0,   332,   363,     0,   104,     0,     0,
       0,   105,     0,   333,     0,     0,   335,   336,   337,   338,
     339,   340,   533,   534,   343,   344,   345,   346,   347,   535,
     349,     0,   351,   352,   353,   354,   355,   356,   357,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   358,   359,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   360,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     363
};

static const yytype_int16 yycheck[] =
{
       2,   145,   146,     5,   613,   118,     8,   232,    10,    19,
      12,   196,   638,    15,   216,   613,   364,   615,   613,   523,
     183,   446,   484,   446,   187,   138,   652,   376,   253,   254,
     135,   358,   359,   280,   147,   140,   244,   142,   841,    41,
     283,   891,   285,   443,    20,    47,   277,   194,   443,   427,
     595,    53,    54,   245,   599,     6,   813,    19,    60,    61,
     165,    17,   209,    65,   812,    40,   444,   815,    70,    27,
      72,    73,    74,    17,   619,   147,   118,    79,    80,    81,
      75,     6,    83,   196,  1014,    40,    75,   200,    77,     6,
      91,    46,    83,    84,    85,    90,   138,     6,   245,    50,
      91,    90,    63,  1129,  1128,   147,  1131,   199,    17,   111,
      82,    78,     6,   203,    94,    33,   118,    63,   105,    20,
     117,   123,   124,    17,   126,    96,   113,    57,   241,   116,
     235,   107,   237,    42,    89,   106,   138,   117,   105,   111,
      58,    50,   117,  1169,   257,   147,   251,   136,    42,   107,
     111,  1176,   113,   243,   918,  1179,    50,    58,   200,   150,
     151,   117,  1012,   154,   256,   111,   117,   113,   169,   164,
     114,   721,   380,   117,   176,   164,   178,   166,   169,   170,
     171,  1207,   287,   185,   118,   257,   291,   189,   293,   199,
     615,   376,   117,   195,   196,   952,  1126,   199,   200,   241,
     117,   203,   800,   829,   138,   207,   954,   105,   117,   536,
     537,   538,   539,   147,   676,   257,   678,   425,   680,   138,
     682,   112,   113,   117,   226,   427,   428,   229,   230,   231,
     240,    17,     5,   633,   426,   107,   383,   199,   240,   241,
     663,   243,   244,   643,  1085,   447,   256,   642,   495,     6,
     497,   651,   460,   484,   256,   257,   499,   606,   405,  1062,
      17,   446,   196,   376,     9,     9,   200,   645,    41,   461,
    1200,   262,    58,   275,   276,   277,   278,   279,   240,   426,
     199,     9,     0,    28,    28,    42,    32,  1128,    81,    20,
    1131,   113,    93,    50,   256,    64,    89,    43,    58,   288,
      28,    74,    33,   853,   854,   296,   297,   241,    81,   300,
     855,   856,    64,    94,   461,   860,   117,   319,   119,   321,
       9,   240,   241,   257,   326,   107,   328,    58,  1092,    94,
      96,  1047,     9,   446,  1050,  1176,   117,   256,    18,    28,
     106,    58,    63,   938,   113,   940,   348,    78,     9,    63,
     116,    28,   117,   458,   364,    34,   358,   359,    94,     6,
     117,   113,   364,   108,   108,    44,    45,    28,   108,    49,
      17,   921,   173,   174,   376,   800,    55,   927,   380,    59,
     108,   117,   932,   107,   592,   100,   101,   102,   892,   113,
     111,   192,   113,  1109,   918,    42,   501,   111,   503,   113,
     505,   107,   364,    50,    33,   111,   956,    53,    54,    55,
      56,    90,    91,    17,    94,    33,    62,  1181,  1182,   108,
      24,   606,  1186,   425,   751,   752,   753,   111,   630,   431,
     432,   108,   434,   117,   597,    77,   836,  1092,   601,    55,
      58,   443,   376,   445,   446,   793,    62,   108,   695,   105,
    1214,   107,  1047,   109,    58,  1050,    20,   230,   460,   138,
      78,  1225,   108,  1227,  1228,   114,  1230,  1183,   117,    33,
     117,   618,  1236,   105,  1238,  1239,    92,   111,   663,   113,
    1244,   113,   484,   646,   116,  1094,   107,  1113,    53,    54,
      55,    56,   113,   606,    58,   112,  1094,    62,   432,  1094,
    1216,  1217,   275,   276,   305,   278,   279,   113,   988,   443,
     116,   991,   446,   993,  1109,   995,  1232,   111,   509,   113,
     522,  1071,  1072,  1073,   106,   987,  1181,  1182,  1154,   111,
     112,  1186,   103,   104,   536,   537,   538,   539,   109,    77,
      78,   113,   113,   108,   116,   116,    63,    85,    86,  1099,
     663,  1101,   715,   109,   112,   113,   719,   113,   107,  1214,
     116,   240,   241,   890,   113,   107,    83,    84,  1092,   109,
    1225,   113,  1227,  1228,    91,  1230,    93,   106,   580,   581,
     118,  1236,   111,  1238,  1239,   358,   359,   106,  1183,  1244,
     592,   593,   697,   595,   596,   105,   112,   599,   600,   109,
     117,   105,   604,   111,   606,    53,    54,    55,    56,   113,
     107,   613,   116,   615,    62,   111,   109,   619,   620,   111,
     113,  1216,  1217,   116,   117,   117,   111,   637,   113,    94,
      95,   633,   634,   150,    99,   637,   638,  1232,    90,    91,
     642,   643,    53,    54,    55,    56,   648,   103,   104,   651,
     652,    62,   169,   170,   103,   104,   173,  1181,  1182,   109,
     108,   663,  1186,   113,    84,   112,   116,    87,    90,    91,
     113,   196,   606,   446,   676,   111,   678,   113,   680,   613,
     682,   615,   845,   114,   108,   687,   117,   109,   690,   691,
    1214,   113,   109,   108,   116,   117,   113,   108,   111,   633,
     113,  1225,   106,  1227,  1228,   110,  1230,   111,   112,   643,
     113,   108,  1236,   116,  1238,  1239,   107,   651,   113,   882,
    1244,   116,   885,   103,   104,   869,   870,   871,   872,   663,
      90,    91,   734,   735,   736,   737,   738,   739,   740,   741,
     742,   743,   744,   745,   746,   747,   748,   749,   750,   751,
     752,   753,    53,    54,    55,    56,  1179,     3,   105,    61,
     111,    62,   109,   536,   537,   538,   539,   769,   113,   105,
      16,   116,   997,    82,   999,    21,  1001,   107,  1003,   296,
      26,    90,    91,   793,  1207,   105,   109,   112,    82,   109,
     113,   793,    38,   105,    40,   107,    90,    91,   800,    45,
     109,   326,   109,   950,   113,   109,   113,   116,   117,   113,
     973,   114,   975,    59,   117,   109,   118,   108,    61,   113,
      90,    91,   116,   117,    90,    91,   109,   829,   830,    82,
     113,   833,   717,   111,   836,   720,   138,    90,    91,   109,
     111,   112,   615,   113,     3,   147,   116,   111,   850,   113,
     111,   376,   113,   855,   856,   715,   109,    16,   860,   719,
     113,   108,    21,   116,   103,   104,   800,    26,    92,    93,
     109,   117,   196,    96,   113,   118,   111,   116,   113,    38,
      39,    40,  1029,    42,   111,   112,    45,   189,   890,   891,
     741,   742,   743,   744,   196,   138,   108,   199,   200,   833,
      59,   203,   836,  1066,   147,   113,    82,    66,   111,   112,
     113,   111,   112,   113,    90,    91,   918,   690,   691,   117,
     922,   446,   105,   925,   926,   111,   112,   113,   930,   931,
     111,   112,   113,   109,   111,   112,   113,   113,   240,   241,
     116,   243,   944,   111,   112,   113,   189,   111,   112,   113,
     111,   112,   111,   196,   256,   257,   199,   200,   105,   961,
     203,   734,   735,   736,   737,   738,   739,   740,   741,   742,
     743,   744,   105,   746,   747,   748,   749,   750,   751,   752,
     753,   111,   112,   113,   105,   987,   864,   865,   866,   918,
     746,   747,   748,   111,  1179,   113,   105,   240,   241,   107,
     243,   109,   326,   105,   111,   112,   111,   112,     3,   108,
    1012,  1158,  1014,   256,   257,   111,   112,   111,   112,   321,
     105,    16,  1207,   111,   112,   116,    21,   800,   111,   112,
      25,    26,   111,  1180,   196,   111,   112,   111,   112,   111,
     112,   111,  1044,    38,    39,    40,   105,    42,    82,    83,
      45,  1053,   376,   739,   740,   749,   750,    82,   109,   103,
      27,   113,   364,   108,    59,   111,  1179,   109,   593,   105,
     105,    66,    88,    97,   376,    98,    96,    51,   111,   111,
     111,   606,    42,   111,   106,   358,   359,    42,   613,   110,
    1092,  1093,  1094,   112,  1207,   112,   106,   112,   106,   112,
    1110,   105,  1104,  1105,    13,  1107,   108,   113,  1110,   106,
      19,  1113,    42,   106,    23,   106,   111,   890,   891,  1053,
     106,   364,   446,   105,  1126,    34,    35,   105,    37,   431,
     432,   106,   105,   376,   110,    44,   105,    42,   663,    48,
     106,   443,   112,    82,   446,   106,   111,  1149,   112,  1151,
    1152,    13,  1154,  1155,   106,   111,    43,    19,    32,   105,
    1094,    23,   110,  1092,   326,   106,    17,   110,   113,   106,
     106,   106,    34,    35,   108,    37,    82,  1179,   106,  1181,
    1182,   113,    44,   105,  1186,   111,    48,   111,   431,   432,
    1192,   106,   108,   112,   108,   106,    24,   106,  1200,   111,
     443,   111,   196,   446,   106,  1207,   105,   107,   117,   105,
     105,    24,  1214,   105,   376,    82,   106,   106,   106,   105,
     105,   112,   106,  1225,   106,  1227,  1228,   106,  1230,   106,
     111,   111,    97,   111,  1236,   111,  1238,  1239,   540,  1012,
     113,  1014,  1244,   106,    24,  1179,   106,   111,   106,   106,
     111,    82,  1181,  1182,   106,   117,   111,  1186,   106,   106,
     106,   111,   106,   536,   537,   538,   539,   106,   106,   593,
     111,   111,    82,  1207,   111,    83,   111,   111,   111,   106,
     106,   106,   606,   106,   446,  1214,   730,    24,   834,   613,
     851,  1063,   190,  1201,   227,  1156,  1225,   540,  1227,  1228,
     941,  1230,    13,   936,   606,   800,   528,  1236,    19,  1238,
    1239,   613,    23,   615,   540,  1244,    17,    79,   435,   648,
     179,   833,   178,    34,    35,   200,    37,   850,   199,   433,
      41,   633,   326,    44,   241,   637,   189,    48,  1087,   663,
     642,   643,   615,  1128,  1200,  1180,     3,  1094,   815,   651,
     618,  1110,   734,  1126,   800,   736,    13,   735,   737,    16,
      -1,   663,    19,   606,    21,   738,    23,    -1,    -1,    26,
     613,    -1,   615,    -1,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,   376,    40,    -1,    -1,    -1,    44,    45,    -1,
     633,    48,    -1,   918,   637,    -1,    -1,   922,   196,   642,
     643,    -1,    59,    -1,    -1,    -1,   117,    -1,   651,    -1,
      -1,    -1,    -1,   938,    -1,   940,    -1,    -1,    -1,   944,
     663,    -1,    -1,    -1,    -1,    -1,    -1,  1200,    -1,    -1,
      -1,   593,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   745,   606,    -1,    -1,    -1,    -1,   106,
      -1,   613,   446,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   734,   735,   736,   737,   738,   739,   740,   741,   742,
     743,   744,    -1,   746,   747,   748,   749,   750,   751,   752,
     753,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      -1,   793,    -1,    -1,    16,    -1,    -1,    -1,   800,    21,
      -1,   663,   745,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,  1044,
      42,    -1,  1047,    45,    -1,  1050,    -1,   800,   326,     3,
      -1,   833,    -1,    -1,   836,    57,    -1,    59,    -1,    13,
      -1,    -1,    16,    65,    66,    19,    -1,    21,    -1,    23,
     793,    -1,    26,    -1,    -1,    -1,   196,   800,    -1,    -1,
      34,    35,    -1,    37,    38,    -1,    40,  1092,  1093,  1094,
      44,    45,    -1,    -1,    48,    -1,    -1,    -1,   376,  1104,
    1105,    -1,  1107,    -1,  1109,    59,    -1,    -1,    -1,   111,
     833,    -1,    -1,   836,   918,    -1,    -1,    -1,   922,   593,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,   606,    -1,   938,    -1,   940,   890,   891,   613,
     944,    -1,    -1,    16,  1149,    -1,  1151,  1152,    21,    -1,
      -1,    -1,   106,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    38,    39,    40,   446,    42,
      -1,    -1,    45,    -1,  1179,    -1,  1181,  1182,  1183,    -1,
      -1,  1186,    -1,    -1,    -1,    -1,    59,  1192,    -1,   663,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1207,    -1,    -1,    -1,   326,    -1,    -1,  1214,
      -1,  1216,  1217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1225,    -1,  1227,  1228,    -1,  1230,    -1,  1232,    -1,    -1,
      -1,  1236,    -1,  1238,  1239,    -1,    -1,    -1,    -1,  1244,
    1044,    -1,    -1,  1047,    -1,    -1,  1050,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   376,    -1,    -1,  1012,
      -1,  1014,    -1,    -1,    -1,    -1,   107,    -1,    -1,    -1,
      -1,   112,    -1,    -1,   196,    -1,   918,    -1,    -1,    -1,
     922,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1092,  1093,
    1094,    -1,    -1,    -1,    -1,    -1,   938,    -1,   940,    -1,
    1104,  1105,   944,  1107,    -1,  1109,    -1,     3,    -1,    -1,
      -1,    -1,  1094,    -1,    -1,   593,    -1,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    -1,    21,   446,    -1,   606,    25,
      26,    -1,    -1,    -1,    -1,   613,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,  1149,    42,  1151,  1152,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    65,
      66,  1094,    -1,  1126,    -1,  1179,    -1,  1181,  1182,  1183,
      -1,    -1,  1186,    -1,    -1,   663,    -1,    -1,  1192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1179,    -1,    -1,
     358,   359,  1044,  1207,   326,  1047,    -1,    -1,  1050,    -1,
    1214,    -1,  1216,  1217,    -1,   111,    -1,   258,    -1,    -1,
      -1,  1225,    -1,  1227,  1228,  1207,  1230,   326,  1232,    -1,
      -1,    -1,  1236,    -1,  1238,  1239,    -1,    -1,    -1,    -1,
    1244,    -1,    -1,    -1,   918,    -1,    -1,  1200,   922,    -1,
    1092,  1093,  1094,    -1,   376,    -1,  1179,    -1,    -1,    -1,
      -1,    -1,  1104,  1105,   938,  1107,   940,  1109,    -1,    -1,
     944,    -1,    -1,   593,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1207,    -1,   606,    -1,    -1,    -1,
      -1,    -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1149,    -1,  1151,
    1152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   446,    -1,    -1,   368,    -1,    -1,
      -1,   372,    -1,    -1,    -1,    -1,    -1,  1179,    -1,  1181,
    1182,  1183,    -1,   663,  1186,    -1,    -1,    -1,    -1,    -1,
    1192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1207,    -1,    -1,    -1,    -1,
    1044,    -1,  1214,  1047,  1216,  1217,  1050,    -1,   536,   537,
     538,   539,    -1,  1225,    -1,  1227,  1228,    -1,  1230,    -1,
    1232,    -1,   433,    -1,  1236,   436,  1238,  1239,    -1,    -1,
      -1,    -1,  1244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1092,  1093,
    1094,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1104,  1105,    -1,  1107,    -1,  1109,    -1,    -1,    -1,    -1,
     918,    -1,    -1,    -1,   922,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   615,    -1,    -1,
     938,    -1,   940,    -1,    -1,    -1,   944,    -1,    -1,    -1,
      -1,   593,    -1,    -1,    -1,  1149,    -1,  1151,  1152,    -1,
      -1,    -1,    -1,    -1,   606,    -1,   527,   528,    -1,    -1,
      -1,   613,    -1,    -1,   593,    -1,    -1,    -1,    -1,    -1,
      -1,   542,    -1,    -1,    -1,  1179,    -1,  1181,  1182,  1183,
      -1,    -1,  1186,    -1,    -1,    -1,    -1,    -1,  1192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1207,    -1,    -1,    -1,    -1,    -1,    -1,
    1214,   663,  1216,  1217,   585,    -1,    -1,    -1,    -1,    -1,
      -1,  1225,    -1,  1227,  1228,    -1,  1230,    -1,  1232,    -1,
      -1,    -1,  1236,    -1,  1238,  1239,  1044,    -1,   609,  1047,
    1244,    -1,  1050,    -1,    -1,    -1,   734,   735,   736,   737,
     738,   739,   740,   741,   742,   743,   744,    -1,   746,   747,
     748,   749,   750,   751,   752,   753,    -1,    -1,   918,    -1,
      -1,    -1,   922,    -1,    -1,    -1,    -1,    -1,    -1,   650,
      -1,    -1,     3,    -1,  1092,  1093,  1094,    -1,   938,    -1,
     940,   662,    13,    -1,   944,    16,  1104,  1105,    19,  1107,
      21,  1109,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,   800,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,  1149,    -1,  1151,  1152,    66,   717,    -1,    -1,   720,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,   729,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1179,    -1,  1181,  1182,  1183,    -1,    -1,  1186,    -1,
      -1,    -1,    -1,    -1,  1192,    -1,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,  1044,    -1,   117,  1047,    -1,  1207,
    1050,    -1,   890,   891,    -1,    -1,  1214,    -1,  1216,  1217,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1225,    -1,  1227,
    1228,    -1,  1230,    -1,  1232,    -1,    -1,    -1,  1236,    -1,
    1238,  1239,   803,    -1,    -1,    -1,  1244,    -1,    -1,    -1,
      -1,    -1,  1092,  1093,  1094,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1104,  1105,    -1,  1107,    -1,  1109,
      -1,    -1,    -1,    -1,    -1,    -1,   918,    -1,    -1,    -1,
     922,    -1,    -1,    -1,    -1,   846,    -1,   848,   849,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   938,    -1,   940,   918,
      -1,    -1,   944,   922,    -1,    -1,    -1,    -1,    -1,  1149,
      -1,  1151,  1152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   944,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1012,    -1,  1014,    -1,    -1,  1179,
      -1,  1181,  1182,  1183,    -1,   906,  1186,   908,    -1,    -1,
      -1,    -1,  1192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1207,    -1,    -1,
      -1,    -1,    -1,    -1,  1214,    -1,  1216,  1217,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1225,    -1,  1227,  1228,    -1,
    1230,    -1,  1232,    -1,    -1,    -1,  1236,    -1,  1238,  1239,
      -1,    -1,  1044,    -1,  1244,  1047,    -1,    -1,  1050,    -1,
     323,    -1,    -1,   974,    -1,    -1,   329,   330,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1044,    -1,    -1,    -1,    -1,
      -1,    -1,   323,    -1,    -1,    -1,    -1,   350,   329,   330,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   360,  1126,    -1,
    1092,  1093,  1094,    -1,    -1,    -1,    -1,    -1,    -1,   350,
      -1,    -1,  1104,  1105,    -1,  1107,    -1,  1109,    -1,   360,
      -1,    -1,    -1,  1092,  1093,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1104,  1105,    -1,  1107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1149,    -1,  1151,
    1152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1149,    -1,  1151,  1152,    -1,    -1,    -1,  1179,    -1,  1181,
    1182,  1183,    -1,    -1,  1186,    -1,    -1,   149,    -1,    -1,
    1192,   153,    -1,    -1,   156,    -1,   158,    -1,    -1,    -1,
      -1,    -1,  1181,  1182,    -1,  1207,   168,  1186,    -1,    -1,
      -1,    -1,  1214,  1192,  1216,  1217,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1225,    -1,  1227,  1228,    -1,  1230,    -1,
    1232,    -1,    -1,    -1,  1236,  1214,  1238,  1239,    -1,    -1,
      -1,    -1,  1244,    -1,    -1,    -1,  1225,    -1,  1227,  1228,
      -1,  1230,    -1,    -1,    -1,    -1,    -1,  1236,   531,  1238,
    1239,    -1,    -1,    -1,    -1,  1244,    -1,   540,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     531,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,   540,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   570,   571,   261,
      -1,    -1,   264,    -1,   266,    -1,   268,    -1,   270,   582,
     272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   570,
     571,   594,    -1,    -1,    -1,   598,    -1,    -1,    -1,   602,
      -1,   582,    -1,   295,    -1,    -1,    -1,   299,    -1,   118,
     302,   614,   304,   594,    -1,    -1,    -1,   598,   621,    -1,
      -1,    -1,   625,    -1,    -1,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,   614,    -1,    -1,    -1,    -1,   147,    -1,
     621,    -1,    -1,    -1,   625,    -1,   649,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,   649,    -1,
      -1,    13,    -1,    -1,    16,    -1,    -1,    19,    -1,    21,
     189,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
     199,   200,    34,    35,   203,    37,    38,    39,    40,    41,
      42,    -1,    44,    45,    -1,    -1,    48,    -1,    -1,    -1,
      -1,   714,    -1,    -1,    -1,    -1,    -1,    59,   721,    -1,
     723,    -1,    -1,    -1,    66,    -1,    -1,    -1,   731,    -1,
     733,   240,   241,   714,   243,    -1,    78,    -1,    -1,    -1,
      -1,    -1,   723,    -1,    -1,    -1,    -1,   256,   257,    -1,
     731,    -1,   733,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,   470,    -1,
     472,    -1,   474,    -1,    -1,   477,    -1,    -1,    -1,   792,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   792,    -1,    -1,    -1,    -1,   508,    -1,    -1,   511,
      -1,   513,    -1,   515,    -1,   517,    -1,   519,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   841,    -1,
      -1,    -1,    -1,     3,    -1,    -1,     6,    -1,    -1,    -1,
     853,   854,    -1,    13,    -1,    -1,    16,    17,    -1,    19,
     841,    21,    -1,    23,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    -1,
      40,    41,    -1,    -1,    44,    45,    -1,    -1,    48,    -1,
      50,    -1,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    -1,   920,   921,    -1,
      -1,    -1,   431,   432,   927,    -1,    -1,    -1,    -1,   932,
      90,    91,   935,    -1,   443,    -1,    -1,    -1,    -1,   920,
     943,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,    -1,   956,   935,    -1,    -1,   117,    -1,    -1,
      -1,    -1,   943,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     672,    -1,    -1,     3,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    16,    17,    -1,    19,
      -1,    21,    -1,    23,    -1,    -1,    26,    -1,    -1,   701,
      -1,   703,    -1,   705,    34,    35,   708,    37,    38,    -1,
      40,    41,    -1,    -1,    44,    45,    -1,    -1,    48,    -1,
      50,    -1,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,  1062,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1071,  1072,
    1073,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1062,    -1,    -1,    -1,   105,    -1,  1090,  1091,    -1,
      -1,    -1,  1095,    -1,    -1,    -1,  1099,   117,  1101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1090,
    1091,    -1,    -1,    -1,  1095,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   633,    -1,    -1,    -1,   637,    -1,
      -1,     3,    -1,   642,   643,    -1,  1139,    -1,    -1,    -1,
      -1,    13,   651,    -1,    16,    -1,    -1,    19,    -1,    21,
      -1,    23,    -1,    -1,    26,    -1,    -1,    -1,  1139,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    -1,    40,    -1,
      -1,    -1,    44,    45,    -1,    -1,    48,  1180,    -1,    -1,
      -1,    -1,  1185,    -1,   876,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,   886,    -1,    -1,    -1,    -1,  1180,
      -1,    -1,    -1,    -1,  1185,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    17,
      18,    19,    -1,    21,    22,    23,    -1,    -1,    26,    -1,
      28,    -1,    30,    -1,   106,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   117,    44,    45,    -1,    -1,
      48,    -1,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,   111,    -1,  1007,    -1,    -1,    -1,   117,
      -1,    -1,    -1,    -1,   833,    -1,    -1,   836,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    12,    13,    14,
      -1,    16,    17,    18,    19,    -1,    21,    22,    23,    -1,
      -1,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    44,
      45,    -1,    -1,    48,    -1,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,   108,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,   117,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    19,
      -1,    21,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    44,    45,    -1,    -1,    48,    -1,
      50,    51,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,   117,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    12,    13,    14,
      -1,    16,    17,    18,    19,    -1,    21,    22,    23,    -1,
      -1,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    44,
      45,    -1,    -1,    48,    -1,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,   108,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,   117,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    19,
      -1,    21,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    44,    45,    -1,    -1,    48,    -1,
      50,    51,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,     6,    -1,    -1,
      90,    91,    -1,    -1,    13,    -1,    -1,    16,    17,    -1,
      19,    -1,    21,    -1,    23,   105,    -1,    26,   108,    -1,
      -1,   111,    -1,    -1,    -1,    34,    35,   117,    37,    38,
      -1,    40,    41,    -1,    -1,    44,    45,    -1,    -1,    48,
      -1,    50,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    90,    91,    -1,    -1,    13,    -1,    -1,    16,    -1,
      -1,    19,    -1,    21,    -1,    23,   105,    -1,    26,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    34,    35,   117,    37,
      38,    39,    40,    41,    42,    -1,    44,    45,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    66,    13,
      -1,    -1,    16,    -1,    -1,    19,    -1,    21,    -1,    23,
      78,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    -1,
      44,    45,    -1,    -1,    48,    -1,    -1,    -1,    -1,   107,
     108,    -1,    -1,   111,    -1,    59,    -1,    -1,    -1,   117,
       3,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    16,    78,    -1,    19,    -1,    21,    -1,
      23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      -1,    44,    45,   107,   108,    48,    -1,   111,     3,    -1,
      -1,    -1,    -1,   117,    -1,    -1,    59,    -1,    13,    -1,
      -1,    16,    -1,    66,    19,    -1,    21,    -1,    23,    -1,
      -1,    26,    -1,    -1,    -1,    78,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    -1,    44,
      45,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    59,   108,    -1,    -1,   111,    -1,
      -1,    66,    13,    -1,   117,    16,    -1,    -1,    19,    -1,
      21,    -1,    23,    78,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,    -1,    48,    -1,    -1,
       3,    -1,    -1,   108,    -1,    -1,   111,    -1,    59,    -1,
      13,    -1,   117,    16,    -1,    66,    19,    -1,    21,    -1,
      23,    -1,    -1,    26,    -1,    -1,    -1,    78,    -1,    -1,
       3,    34,    35,    -1,    37,    38,    39,    40,    -1,    42,
      13,    44,    45,    16,    -1,    48,    19,    -1,    21,    -1,
      23,    -1,    -1,    26,    -1,    -1,    59,    60,    -1,    -1,
       3,    34,    35,    66,    37,    38,   117,    40,    -1,    -1,
      13,    44,    45,    16,    -1,    48,    19,    -1,    21,    -1,
      23,    -1,    -1,    26,    -1,    -1,    59,    -1,    -1,    -1,
       3,    34,    35,    -1,    37,    38,    -1,    40,    -1,    -1,
      13,    44,    45,    16,    -1,    48,    19,    -1,    21,    -1,
      23,    -1,    -1,    26,   117,    -1,    59,    -1,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    -1,    40,    -1,    -1,
      -1,    44,    45,   106,    -1,    48,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,   117,    -1,    59,    60,    13,    -1,
      -1,    16,    -1,    -1,    19,    -1,    21,    -1,    23,    -1,
      -1,    26,    -1,   106,    -1,    -1,    -1,    -1,     3,    34,
      35,    -1,    37,    38,   117,    40,    -1,    -1,    13,    44,
      45,    16,    -1,    48,    19,    -1,    21,    -1,    23,    -1,
      -1,    26,    -1,    -1,    59,    -1,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,   117,    40,    -1,    -1,    -1,    44,
      45,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,
       7,     8,   117,    10,    -1,    12,    13,    14,    -1,    -1,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    36,
      37,    -1,   117,    -1,    41,    -1,    -1,    44,    -1,    -1,
      -1,    48,    -1,    50,    51,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    -1,    -1,     4,     5,     6,
       7,     8,    -1,    10,    -1,    12,    13,    14,   105,    -1,
      17,    18,    19,    -1,   111,    22,    23,    -1,    -1,    -1,
     117,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    36,
      37,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,
      -1,    48,    -1,    50,    51,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    90,    91,    17,    -1,    19,    -1,    -1,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    34,    35,   111,    37,    -1,    -1,    -1,    41,
     117,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,    -1,    90,    91,
      92,    93,    13,    -1,    -1,    -1,    17,    -1,    19,    -1,
      -1,    22,    23,   105,    -1,   107,   108,    -1,    -1,    -1,
     112,    -1,    -1,    34,    35,   117,    37,    -1,    -1,    -1,
      41,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,
      -1,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,    90,
      91,    92,    93,    13,    -1,    -1,    -1,    17,    -1,    19,
      -1,    -1,    -1,    23,   105,    -1,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,   117,    37,    -1,    -1,
      -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,
      50,    -1,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,
      90,    91,    92,    93,    13,    -1,    -1,    -1,    17,    -1,
      19,    -1,    -1,    -1,    23,   105,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    34,    35,   117,    37,    -1,
      -1,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,    90,    91,    92,    93,    13,    -1,    -1,    -1,    17,
      -1,    19,    -1,    -1,    -1,    23,   105,    -1,    -1,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    34,    35,   117,    37,
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
      -1,    19,    -1,    -1,    -1,    23,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    34,    35,   117,    37,
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
      -1,    17,    -1,    19,    -1,    -1,    -1,    23,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
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
      -1,    -1,    23,   105,    -1,    -1,    -1,    -1,    -1,   111,
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
      19,    -1,    -1,    -1,    23,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,   117,    37,    -1,
      -1,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,     6,
      79,    80,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,
      17,    -1,    19,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    34,    35,    -1,
      37,    -1,    -1,    -1,    41,    -1,    -1,    44,   117,    -1,
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
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    90,    91,
      17,    -1,    19,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,    -1,    -1,    34,    35,    -1,
      37,    -1,    -1,    -1,    41,   117,    -1,    44,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,    11,    16,    21,    25,    26,    38,    39,    40,
      42,    45,    57,    59,    65,    66,   111,   125,   126,   134,
     167,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   203,   204,   273,   274,   283,   284,   301,   117,
     168,    40,   168,   181,   168,   168,   168,    57,   168,   126,
     187,   193,   192,    39,    42,   273,   301,     0,   125,   126,
      78,   105,   237,   275,   111,   113,   127,   168,   181,   111,
     113,   111,   113,    33,    58,   237,   285,   302,   303,    20,
      33,    58,   205,   237,   239,   240,   242,   107,   127,   168,
     168,   168,   237,   275,   126,   168,   177,   238,    13,    19,
      23,    34,    35,    37,    44,    48,   106,   168,   173,   174,
     175,   251,   252,   253,   276,   277,   278,   275,   107,   240,
     279,   168,   111,   113,   113,   111,   113,    94,   168,    94,
     168,   168,   241,   168,   181,   289,   302,   303,   107,   304,
     287,   303,   286,   241,   168,   168,   181,   107,   243,   213,
     239,   240,   242,   209,   240,   242,   207,   242,   206,   194,
     195,   107,   107,   127,   237,   293,   302,   303,   221,   237,
     239,   240,   242,   275,   240,   279,    33,   178,   112,   135,
     136,    77,   109,   120,   121,   114,   168,   120,   106,   112,
     144,   145,   240,   279,    40,    41,   107,   108,   111,   134,
     146,   168,   203,   237,   244,   245,   246,   251,   254,   255,
     256,   266,   267,   268,   270,   280,   281,   282,   283,   310,
     279,   168,    94,    94,   111,   111,   112,   137,   138,   113,
     112,   113,   132,   133,   304,   291,   303,   290,   108,   111,
     134,   147,   203,   237,   251,   255,   283,   305,   306,   307,
     304,   288,   304,   132,   132,   108,   134,   139,   168,   244,
     243,   217,   240,   242,   215,   242,   214,   243,   211,   242,
     210,   243,   208,   243,   108,    53,    54,    55,    56,    62,
     128,   202,   196,   197,   198,   199,   107,   297,   302,   303,
     304,   295,   303,   294,   243,   229,   239,   240,   242,   225,
     240,   242,   223,   242,   222,   240,   279,   279,   168,   177,
     136,   110,   121,   168,   277,   145,   279,   310,   168,     4,
       5,     6,     7,     8,    10,    12,    14,    17,    18,    22,
      30,    36,    41,    50,    51,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    90,    91,
     105,   108,   111,   117,   134,   168,   169,   170,   181,   182,
     203,   251,   252,   253,   284,   311,   312,   313,   314,   315,
     316,   317,   319,   320,   321,   322,   324,   325,   326,   327,
     329,   330,   337,   339,   340,   342,   343,   348,   349,   351,
     352,   353,   354,   355,   356,   358,   360,   368,   372,   373,
     374,   375,   376,   378,   379,   380,   382,   383,   387,   388,
     403,   404,   406,   407,   408,   251,   255,   270,   281,   108,
     280,   105,   269,   168,   251,   256,   168,   247,   248,   249,
     111,   265,   310,   105,   257,    27,   107,   262,   271,   271,
     111,   111,   168,   138,   168,   181,   133,   304,   292,   304,
     251,   255,   108,   305,   247,   265,   304,   108,   244,   243,
     219,   242,   218,   243,   216,   243,   243,   212,   243,   243,
     168,   181,   168,   181,   129,   167,   168,   180,   168,   181,
     168,   181,   108,   202,   108,   128,   108,   128,   200,   201,
     304,   299,   303,   298,   304,   296,   304,   243,   233,   240,
     242,   231,   242,   230,   243,   227,   242,   226,   243,   224,
     243,   279,    96,   122,   179,   111,   168,   168,   172,   252,
     377,   105,     7,    59,    60,    66,    79,    80,    92,    93,
     105,   168,   252,   253,   375,   380,   385,   386,   387,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     105,   105,   168,   317,   111,   168,   385,   111,   385,   113,
     113,   116,   105,   385,   168,   181,   378,   379,   402,   402,
     385,    60,   316,    82,   109,   113,   116,   120,   109,   113,
     116,   120,   105,   113,   116,   108,   150,   312,   111,   168,
     247,   310,   111,   105,    82,   105,   310,   359,   369,   113,
     116,   109,   103,   104,   171,   389,    90,    91,   247,   265,
     262,   271,   271,   123,   251,   258,   106,   134,   251,   259,
     260,   261,   105,   269,   168,   257,   120,   111,   112,   103,
     106,   123,   251,   259,   262,   168,   263,   264,    17,    50,
     108,   168,   181,   272,   311,   372,   271,   304,   247,   265,
     111,   243,   220,   243,   243,   243,    63,   111,    63,   111,
      63,   111,    63,   111,   167,   180,   111,   113,   111,   111,
      64,    64,   108,   108,   108,   128,   304,   300,   304,   304,
     243,   235,   242,   234,   243,   232,   243,   243,   228,   243,
     243,   168,   179,   111,   109,   120,   127,   166,   384,   120,
     166,   105,   385,   105,   402,   402,   402,   402,   172,   252,
     253,    82,   111,    81,    89,    88,    97,    98,    96,    84,
      87,    77,    78,    85,    86,   118,   100,   101,   102,    92,
      93,    94,    95,    99,   385,   385,    51,   111,   111,   111,
      42,   168,   168,   385,   111,   106,   247,   317,   385,     6,
      17,    42,    50,   168,   376,   168,   113,   385,    17,    42,
      50,   168,   376,   168,   113,   106,   381,   385,    42,     6,
     168,   312,   111,   134,   168,   315,   325,   345,   347,   385,
     162,   163,   168,   181,   315,   370,   371,   372,   378,   412,
      32,    43,   361,   362,   366,   359,   168,   376,   168,   385,
     385,   111,   271,   106,   259,    17,   124,   168,   112,   251,
     114,   249,   106,   112,   140,   141,   123,   106,   259,   262,
     248,   107,   250,   308,   385,   120,   106,   259,   168,   106,
     112,   142,   143,   105,   105,   113,   113,   108,   311,   108,
     113,   111,   243,   180,   180,   180,   180,   111,   168,   168,
     181,   168,   181,   108,   304,   243,   236,   243,   243,   243,
     385,   308,   120,   384,   308,   120,   106,   381,   106,   385,
     106,   106,   122,   385,   385,   392,   393,   394,   395,   396,
     397,   397,   399,   399,   399,   399,   168,   176,   252,   253,
     400,   400,   400,   401,   401,   402,   402,   402,   106,   106,
     105,   105,   106,   110,   168,   113,   116,   105,    42,   110,
     113,   116,   105,    42,   106,   112,   164,   165,   111,   385,
     112,   157,   158,   111,   106,   163,   371,   106,   111,   363,
     367,   366,   159,   362,   361,   366,   105,   110,   106,    17,
     113,   114,   249,   168,   260,   141,   106,   259,   106,   108,
     112,   250,   309,   120,   106,   120,   264,   143,   106,   381,
     106,   381,    50,    50,   108,    50,   111,   112,   130,   131,
     111,   130,   111,   130,   111,   130,   111,   132,   111,   132,
     111,   132,   111,   132,   243,   110,   243,   106,   331,   106,
     402,   405,   106,   111,    82,    10,    51,   168,   317,   318,
     319,   323,   328,   338,   341,   342,   344,   348,   350,   357,
     385,   106,   381,   317,   168,   168,   106,   381,   168,   168,
     106,   381,   385,   165,   106,   346,   347,   111,   325,   158,
     111,   385,   317,   105,   310,   362,   366,   106,   381,   168,
     106,   108,   112,   148,   149,   108,   120,   111,   106,   111,
     106,   105,   105,   105,   180,   111,   131,   111,   111,   111,
     111,   111,   111,   111,   243,   107,   332,   411,   405,   390,
     105,   105,    82,    24,   105,    82,   310,   106,   106,   105,
     106,   105,   106,   317,   106,   106,   346,   106,   346,   111,
     134,   168,   364,   365,   106,   250,   149,   111,   111,   106,
     381,   106,   381,   106,   381,     9,    28,   108,   152,   153,
     154,   333,   334,   335,   332,   385,   385,   318,   317,   111,
     345,   385,   111,   106,   381,   106,   381,   317,   317,   106,
     317,   106,   106,   346,   365,    97,   160,   161,   106,   249,
     111,   106,   111,   106,   111,   106,   336,   390,   108,   153,
     334,   335,   108,   154,   335,   108,   151,   333,   335,    82,
      83,   106,   106,   111,   385,   111,   106,   106,   106,   317,
     317,   317,   106,   249,   168,   161,   310,   111,   111,   111,
     112,   155,   156,   108,    82,   108,   333,   153,   311,   310,
     355,   385,   318,   318,   106,   346,   111,   111,   385,   318,
     317,   336,   156,   311,   111,    24,   318,   106,   106,   346,
     106,   346,   111,   318,   318,   318,   106,   318,   106,   106,
     346,   318,   318,   318,   106,   318
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   119,   120,   120,   121,   122,   122,   123,   124,   125,
     125,   126,   126,   127,   127,   128,   128,   129,   129,   130,
     130,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     136,   137,   137,   138,   139,   139,   140,   140,   141,   142,
     142,   143,   144,   144,   145,   146,   146,   147,   147,   148,
     148,   149,   150,   150,   151,   151,   152,   152,   153,   153,
     154,   155,   155,   156,   157,   157,   158,   159,   159,   160,
     160,   161,   162,   162,   163,   164,   164,   165,   166,   166,
     167,   167,   167,   167,   167,   167,   167,   167,   168,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   170,   170,   170,   170,   170,
     170,   170,   171,   171,   172,   173,   173,   174,   174,   174,
     174,   174,   175,   175,   176,   176,   177,   177,   178,   178,
     179,   180,   180,   181,   181,   182,   183,   183,   184,   184,
     184,   184,   184,   184,   184,   184,   185,   185,   186,   186,
     187,   187,   187,   187,   188,   188,   189,   190,   190,   191,
     191,   192,   192,   192,   194,   193,   195,   193,   196,   193,
     197,   193,   198,   193,   199,   193,   200,   193,   201,   193,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   203,   203,   205,   204,   206,   204,
     207,   204,   208,   204,   209,   204,   210,   204,   211,   204,
     212,   204,   213,   204,   214,   204,   215,   204,   216,   204,
     217,   204,   218,   204,   219,   204,   220,   204,   221,   204,
     222,   204,   223,   204,   224,   204,   225,   204,   226,   204,
     227,   204,   228,   204,   229,   204,   230,   204,   231,   204,
     232,   204,   233,   204,   234,   204,   235,   204,   236,   204,
     237,   238,   238,   239,   240,   241,   241,   242,   242,   242,
     242,   243,   243,   244,   244,   244,   244,   245,   245,   245,
     245,   245,   246,   246,   247,   247,   248,   248,   249,   249,
     250,   250,   251,   251,   251,   252,   252,   253,   253,   254,
     254,   255,   255,   255,   255,   256,   256,   257,   257,   257,
     257,   257,   257,   257,   257,   258,   258,   259,   259,   260,
     260,   260,   261,   261,   262,   263,   263,   264,   265,   265,
     266,   267,   268,   268,   268,   268,   269,   270,   270,   270,
     270,   270,   270,   270,   270,   271,   271,   271,   271,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   273,
     274,   274,   274,   274,   274,   274,   274,   274,   275,   275,
     276,   276,   277,   277,   278,   279,   279,   280,   280,   281,
     282,   282,   283,   285,   284,   286,   284,   287,   284,   288,
     284,   289,   284,   290,   284,   291,   284,   292,   284,   293,
     284,   294,   284,   295,   284,   296,   284,   297,   284,   298,
     284,   299,   284,   300,   284,   301,   302,   303,   303,   304,
     304,   305,   305,   305,   305,   305,   306,   306,   307,   307,
     308,   308,   308,   309,   309,   310,   310,   311,   311,   312,
     312,   312,   313,   313,   314,   315,   315,   316,   316,   317,
     317,   317,   317,   317,   317,   318,   318,   318,   318,   318,
     320,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   321,   322,   323,   324,   325,   325,
     325,   325,   325,   325,   325,   326,   327,   328,   329,   329,
     331,   330,   332,   332,   332,   332,   332,   332,   333,   333,
     333,   334,   334,   335,   335,   335,   336,   337,   338,   339,
     340,   340,   341,   341,   342,   343,   343,   343,   343,   343,
     343,   343,   343,   344,   344,   344,   344,   344,   344,   344,
     344,   345,   345,   346,   347,   347,   348,   349,   350,   351,
     351,   352,   353,   353,   354,   354,   355,   357,   356,   358,
     359,   360,   360,   360,   360,   361,   361,   363,   362,   364,
     364,   365,   365,   367,   366,   368,   368,   368,   368,   369,
     370,   370,   371,   371,   372,   372,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   374,   374,   374,
     374,   374,   374,   375,   375,   375,   375,   376,   376,   376,
     376,   377,   377,   378,   378,   378,   378,   379,   379,   379,
     380,   380,   380,   380,   380,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   381,   381,   382,   382,   382,   382,
     382,   382,   382,   382,   383,   383,   383,   383,   383,   383,
     384,   385,   386,   386,   387,   388,   388,   388,   388,   389,
     390,   390,   391,   391,   392,   392,   393,   393,   394,   394,
     395,   395,   396,   396,   396,   397,   397,   397,   397,   397,
     397,   398,   399,   399,   399,   399,   400,   400,   400,   401,
     401,   401,   401,   402,   402,   402,   402,   402,   403,   404,
     405,   405,   405,   405,   405,   406,   406,   406,   406,   406,
     407,   408,   409,   409,   409,   411,   410,   412,   412,   412
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     2,     2,     2,     1,
       2,     1,     2,     2,     3,     1,     2,     1,     2,     1,
       2,     2,     1,     2,     2,     2,     1,     2,     1,     2,
       2,     1,     2,     2,     1,     2,     1,     2,     2,     1,
       2,     2,     1,     2,     2,     1,     2,     1,     2,     1,
       2,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       2,     1,     2,     2,     1,     2,     2,     1,     2,     1,
       2,     2,     1,     2,     2,     1,     2,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       2,     1,     3,     3,     3,     1,     1,     1,     0,     1,
       1,     2,     1,     2,     2,     3,     1,     2,     3,     4,
       1,     1,     1,     1,     3,     3,     4,     5,     5,     6,
       6,     1,     1,     1,     0,     5,     0,     6,     0,     6,
       0,     7,     0,     6,     0,     7,     0,     7,     0,     8,
       3,     4,     3,     5,     6,     3,     5,     6,     3,     5,
       6,     3,     5,     6,     3,     5,     6,     3,     5,     6,
       5,     6,     5,     6,     1,     1,     0,     4,     0,     5,
       0,     5,     0,     6,     0,     5,     0,     6,     0,     6,
       0,     7,     0,     5,     0,     6,     0,     6,     0,     7,
       0,     6,     0,     7,     0,     7,     0,     8,     0,     5,
       0,     6,     0,     6,     0,     7,     0,     6,     0,     7,
       0,     7,     0,     8,     0,     6,     0,     7,     0,     7,
       0,     8,     0,     7,     0,     8,     0,     8,     0,     9,
       3,     1,     2,     2,     2,     1,     2,     2,     2,     3,
       3,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     1,     3,     1,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       3,     2,     3,     3,     4,     2,     2,     2,     3,     3,
       4,     3,     4,     4,     5,     2,     3,     1,     2,     2,
       3,     1,     3,     4,     2,     1,     2,     1,     1,     1,
       1,     2,     2,     3,     3,     4,     1,     3,     4,     4,
       5,     4,     5,     5,     6,     2,     3,     3,     4,     4,
       5,     4,     5,     6,     7,     6,     7,     6,     7,     2,
       3,     4,     4,     5,     4,     5,     5,     6,     2,     3,
       1,     2,     2,     1,     3,     2,     3,     1,     1,     1,
       2,     3,     1,     0,     4,     0,     5,     0,     5,     0,
       6,     0,     5,     0,     6,     0,     6,     0,     7,     0,
       5,     0,     6,     0,     6,     0,     7,     0,     6,     0,
       7,     0,     7,     0,     8,     1,     2,     2,     3,     2,
       3,     1,     1,     1,     1,     1,     3,     4,     2,     3,
       2,     3,     3,     1,     2,     2,     3,     1,     2,     1,
       1,     1,     1,     1,     2,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     5,     7,     7,     3,     5,
       0,     6,     3,     4,     2,     3,     3,     4,     4,     3,
       3,     3,     4,     2,     3,     1,     1,     5,     5,     7,
       1,     1,     1,     1,     1,     6,     7,     7,     8,     7,
       8,     8,     9,     6,     7,     7,     8,     7,     8,     8,
       9,     1,     1,     1,     1,     2,     3,     5,     5,     2,
       3,     3,     2,     3,     2,     3,     3,     0,     6,     1,
       1,     3,     3,     4,     1,     1,     2,     0,     6,     2,
       3,     1,     2,     0,     3,     3,     4,     4,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     1,     1,     1,     1,     1,     3,     3,     4,
       4,     3,     3,     1,     3,     3,     3,     4,     5,     5,
       6,     1,     2,     3,     3,     5,     5,     4,     4,     4,
       4,     3,     5,     6,     5,     6,     5,     6,     5,     6,
       7,     8,     7,     8,     1,     2,     3,     3,     3,     3,
       3,     5,     5,     3,     3,     4,     3,     4,     4,     4,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     5,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     1,     2,     2,     1,     2,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     4,     4,     5,     0,     6,     1,     1,     1
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
#line 357 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type ;(yyval.typeinfo)->order=1;}
#line 4020 "parser.tab.c"
    break;

  case 3: /* OMPSB: OMPSB PSB  */
#line 358 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type + "[]";(yyval.typeinfo)->order=(yyvsp[-1].typeinfo)->order+1;}
#line 4026 "parser.tab.c"
    break;

  case 4: /* PSB: LSB RSB  */
#line 360 "parser.y"
                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "[]";}
#line 4032 "parser.tab.c"
    break;

  case 8: /* IdentifierDot: Identifier DOT  */
#line 367 "parser.y"
                                                {(yyval.typeinfo) = createstruct();}
#line 4038 "parser.tab.c"
    break;

  case 13: /* OMDotIdentifier: DOT Identifier  */
#line 375 "parser.y"
                                                                {(yyval.typeinfo) = createstruct();string p=((yyvsp[0].str));((yyval.typeinfo))->name="."+p;}
#line 4044 "parser.tab.c"
    break;

  case 14: /* OMDotIdentifier: OMDotIdentifier DOT Identifier  */
#line 376 "parser.y"
                                                    {(yyval.typeinfo) = createstruct();string p=((yyvsp[0].str));((yyval.typeinfo))->name=((yyvsp[-2].typeinfo))->name+"."+p;}
#line 4050 "parser.tab.c"
    break;

  case 21: /* CommaModuleName: COMMA ModuleName  */
#line 387 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();}
#line 4056 "parser.tab.c"
    break;

  case 24: /* CommaTypeName: COMMA Identifier  */
#line 392 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4062 "parser.tab.c"
    break;

  case 25: /* CommaTypeName: COMMA ExpressionName  */
#line 393 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4068 "parser.tab.c"
    break;

  case 30: /* CommaTypeParameter: COMMA TypeParameter  */
#line 401 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4074 "parser.tab.c"
    break;

  case 33: /* CommaInterfaceType: COMMA Identifier  */
#line 406 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4080 "parser.tab.c"
    break;

  case 36: /* OMCommaFormalParameter: CommaFormalParameter  */
#line 411 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;}
#line 4086 "parser.tab.c"
    break;

  case 37: /* OMCommaFormalParameter: OMCommaFormalParameter CommaFormalParameter  */
#line 412 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();vector<string>a=((yyvsp[-1].typeinfo))->type_variable;vector<string>b=((yyvsp[0].typeinfo))->type_variable;for(auto z:a){((yyval.typeinfo))->type_variable.push_back(z);}for(auto z:b){((yyval.typeinfo))->type_variable.push_back(z);}}
#line 4092 "parser.tab.c"
    break;

  case 38: /* CommaFormalParameter: COMMA FormalParameter  */
#line 414 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;}
#line 4098 "parser.tab.c"
    break;

  case 41: /* CommaExceptionType: COMMA ExceptionType  */
#line 419 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4104 "parser.tab.c"
    break;

  case 44: /* CommaRecordComponent: COMMA RecordComponent  */
#line 424 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4110 "parser.tab.c"
    break;

  case 49: /* OMCommaVariableInitializer: CommaVariableInitializer  */
#line 432 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type =  ((yyvsp[0].typeinfo))->type;}
#line 4116 "parser.tab.c"
    break;

  case 50: /* OMCommaVariableInitializer: OMCommaVariableInitializer CommaVariableInitializer  */
#line 433 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type =  ((yyvsp[0].typeinfo))->type;}
#line 4122 "parser.tab.c"
    break;

  case 51: /* CommaVariableInitializer: COMMA VariableInitializer  */
#line 435 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type =  ((yyvsp[0].typeinfo))->type;}
#line 4128 "parser.tab.c"
    break;

  case 63: /* CommaCaseConstant: COMMA CaseConstant  */
#line 454 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4134 "parser.tab.c"
    break;

  case 66: /* CommaStatementExpression: COMMA StatementExpression  */
#line 459 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();}
#line 4140 "parser.tab.c"
    break;

  case 71: /* OrClassType: BITOR Identifier  */
#line 467 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4146 "parser.tab.c"
    break;

  case 77: /* CommaExpression: COMMA Expression  */
#line 477 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4152 "parser.tab.c"
    break;

  case 78: /* OMDimExpr: DimExpr  */
#line 479 "parser.y"
                                                                                                                {(yyval.typeinfo)=createstruct();int p=(yyvsp[0].typeinfo)->exprvalue;vector<int>q={p};(yyval.typeinfo)->arrdim=q;}
#line 4158 "parser.tab.c"
    break;

  case 79: /* OMDimExpr: OMDimExpr DimExpr  */
#line 480 "parser.y"
                                                                                                        {(yyval.typeinfo)=createstruct();int p=(yyvsp[0].typeinfo)->exprvalue;(yyval.typeinfo)->arrdim=(yyvsp[-1].typeinfo)->arrdim;((yyval.typeinfo))->arrdim.push_back(p);}
#line 4164 "parser.tab.c"
    break;

  case 80: /* Modifieropt: PUBLIC  */
#line 482 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4170 "parser.tab.c"
    break;

  case 81: /* Modifieropt: PROTECTED  */
#line 483 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4176 "parser.tab.c"
    break;

  case 82: /* Modifieropt: PRIVATE  */
#line 484 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4182 "parser.tab.c"
    break;

  case 83: /* Modifieropt: ABSTRACT  */
#line 485 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4188 "parser.tab.c"
    break;

  case 84: /* Modifieropt: STATIC  */
#line 486 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4194 "parser.tab.c"
    break;

  case 85: /* Modifieropt: SEALED  */
#line 487 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4200 "parser.tab.c"
    break;

  case 86: /* Modifieropt: STRICTFP  */
#line 488 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4206 "parser.tab.c"
    break;

  case 87: /* Modifieropt: FINAL  */
#line 489 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4212 "parser.tab.c"
    break;

  case 88: /* Identifier: IDENTIFIERWK  */
#line 491 "parser.y"
                                                {(yyval.str)=(yyvsp[0].str);}
#line 4218 "parser.tab.c"
    break;

  case 89: /* UnqualifiedMethodIdentifier: IDENTIFIERWK  */
#line 493 "parser.y"
                                                                {(yyval.typeinfo) = createstruct(); string p = (yyvsp[0].str);((yyval.typeinfo))->name = p;}
#line 4224 "parser.tab.c"
    break;

  case 90: /* UnqualifiedMethodIdentifier: EXPORTS  */
#line 494 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4230 "parser.tab.c"
    break;

  case 91: /* UnqualifiedMethodIdentifier: OPENS  */
#line 495 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4236 "parser.tab.c"
    break;

  case 92: /* UnqualifiedMethodIdentifier: REQUIRES  */
#line 496 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4242 "parser.tab.c"
    break;

  case 93: /* UnqualifiedMethodIdentifier: USES  */
#line 497 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4248 "parser.tab.c"
    break;

  case 94: /* UnqualifiedMethodIdentifier: MODULE  */
#line 498 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4254 "parser.tab.c"
    break;

  case 95: /* UnqualifiedMethodIdentifier: PERMITS  */
#line 499 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4260 "parser.tab.c"
    break;

  case 96: /* UnqualifiedMethodIdentifier: SEALED  */
#line 500 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4266 "parser.tab.c"
    break;

  case 97: /* UnqualifiedMethodIdentifier: VAR  */
#line 501 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4272 "parser.tab.c"
    break;

  case 98: /* UnqualifiedMethodIdentifier: NONSEALED  */
#line 502 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4278 "parser.tab.c"
    break;

  case 99: /* UnqualifiedMethodIdentifier: PROVIDES  */
#line 503 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4284 "parser.tab.c"
    break;

  case 100: /* UnqualifiedMethodIdentifier: TO  */
#line 504 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4290 "parser.tab.c"
    break;

  case 101: /* UnqualifiedMethodIdentifier: WITH  */
#line 505 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4296 "parser.tab.c"
    break;

  case 102: /* UnqualifiedMethodIdentifier: OPEN  */
#line 506 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4302 "parser.tab.c"
    break;

  case 103: /* UnqualifiedMethodIdentifier: RECORD  */
#line 507 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4308 "parser.tab.c"
    break;

  case 104: /* UnqualifiedMethodIdentifier: TRANSITIVE  */
#line 508 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4314 "parser.tab.c"
    break;

  case 105: /* Literal: INTEGERLITERAL  */
#line 510 "parser.y"
                                                                                                {((yyval.typeinfo)) = createstruct();(yyval.typeinfo)->exprvalue=atoi((yyvsp[0].str));((yyval.typeinfo))->type = "int";}
#line 4320 "parser.tab.c"
    break;

  case 106: /* Literal: FLOATINGPOINTLITERAL  */
#line 511 "parser.y"
                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "float";}
#line 4326 "parser.tab.c"
    break;

  case 107: /* Literal: BOOLEANLITERAL  */
#line 512 "parser.y"
                                                                                                        {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "boolean";}
#line 4332 "parser.tab.c"
    break;

  case 108: /* Literal: NULLLITERAL  */
#line 513 "parser.y"
                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "null";}
#line 4338 "parser.tab.c"
    break;

  case 109: /* Literal: CHARACTERLITERAL  */
#line 514 "parser.y"
                                                                                                        {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "char";}
#line 4344 "parser.tab.c"
    break;

  case 110: /* Literal: STRING  */
#line 515 "parser.y"
                                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "string";}
#line 4350 "parser.tab.c"
    break;

  case 111: /* Literal: TEXTBLOCKS  */
#line 516 "parser.y"
                                                                                                        {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "textblock";}
#line 4356 "parser.tab.c"
    break;

  case 114: /* PrimitiveType: UnannPrimitiveType  */
#line 521 "parser.y"
                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 4362 "parser.tab.c"
    break;

  case 115: /* NumericType: IntegralType  */
#line 523 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 4368 "parser.tab.c"
    break;

  case 116: /* NumericType: FloatingPointType  */
#line 524 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 4374 "parser.tab.c"
    break;

  case 117: /* IntegralType: BYTE  */
#line 526 "parser.y"
                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "byte";}
#line 4380 "parser.tab.c"
    break;

  case 118: /* IntegralType: SHORT  */
#line 527 "parser.y"
                                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "short";}
#line 4386 "parser.tab.c"
    break;

  case 119: /* IntegralType: INT  */
#line 528 "parser.y"
                                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "int";}
#line 4392 "parser.tab.c"
    break;

  case 120: /* IntegralType: LONG  */
#line 529 "parser.y"
                                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "long";}
#line 4398 "parser.tab.c"
    break;

  case 121: /* IntegralType: CHAR  */
#line 530 "parser.y"
                                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "char";}
#line 4404 "parser.tab.c"
    break;

  case 122: /* FloatingPointType: FLOAT  */
#line 532 "parser.y"
                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "float";}
#line 4410 "parser.tab.c"
    break;

  case 123: /* FloatingPointType: DOUBLE  */
#line 533 "parser.y"
                                                                                                        {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "double";}
#line 4416 "parser.tab.c"
    break;

  case 124: /* ReferenceType: Identifier  */
#line 535 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4422 "parser.tab.c"
    break;

  case 126: /* TypeParameter: Identifier  */
#line 538 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4428 "parser.tab.c"
    break;

  case 127: /* TypeParameter: Identifier TypeBound  */
#line 539 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4434 "parser.tab.c"
    break;

  case 128: /* TypeBound: EXTENDS Identifier  */
#line 541 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4440 "parser.tab.c"
    break;

  case 129: /* TypeBound: EXTENDS Identifier OMAdditionalBound  */
#line 542 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();}
#line 4446 "parser.tab.c"
    break;

  case 130: /* AdditionalBound: BITAND Identifier  */
#line 544 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4452 "parser.tab.c"
    break;

  case 131: /* ModuleName: Identifier  */
#line 546 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();string p=((yyvsp[0].str));((yyval.typeinfo))->type=p;}
#line 4458 "parser.tab.c"
    break;

  case 132: /* ModuleName: ModuleName DOT Identifier  */
#line 547 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();string p=((yyvsp[0].str));((yyval.typeinfo))->type=((yyvsp[-2].typeinfo))->type+"."+p;}
#line 4464 "parser.tab.c"
    break;

  case 133: /* ExpressionName: Identifier DOT Identifier  */
#line 549 "parser.y"
                                                                {(yyval.typeinfo) = createstruct();string q=((yyvsp[-2].str));string p=((yyvsp[0].str));((yyval.typeinfo))->type=q+"."+p;}
#line 4470 "parser.tab.c"
    break;

  case 134: /* ExpressionName: ExpressionName DOT Identifier  */
#line 550 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();string p=((yyvsp[0].str));((yyval.typeinfo))->type=((yyvsp[-2].typeinfo))->type+"."+p;}
#line 4476 "parser.tab.c"
    break;

  case 135: /* MethodName: UnqualifiedMethodIdentifier  */
#line 552 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct(); ;((yyval.typeinfo))->name = ((yyvsp[0].typeinfo))->name;}
#line 4482 "parser.tab.c"
    break;

  case 138: /* OrdinaryCompilationUnit: %empty  */
#line 557 "parser.y"
                                                                                                                                                        {}
#line 4488 "parser.tab.c"
    break;

  case 148: /* PackageDeclaration: PACKAGE Identifier SEMICOLON  */
#line 569 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();}
#line 4494 "parser.tab.c"
    break;

  case 149: /* PackageDeclaration: PACKAGE Identifier OMDotIdentifier SEMICOLON  */
#line 570 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4500 "parser.tab.c"
    break;

  case 154: /* SingleTypeImportDeclaration: IMPORT Identifier SEMICOLON  */
#line 577 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();}
#line 4506 "parser.tab.c"
    break;

  case 155: /* SingleTypeImportDeclaration: IMPORT ExpressionName SEMICOLON  */
#line 578 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4512 "parser.tab.c"
    break;

  case 156: /* SingleStaticImportDeclaration: IMPORT STATIC ExpressionName SEMICOLON  */
#line 580 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();}
#line 4518 "parser.tab.c"
    break;

  case 157: /* ImportOnDemandDeclaration: IMPORT Identifier DOT MULTIPLY SEMICOLON  */
#line 582 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4524 "parser.tab.c"
    break;

  case 158: /* ImportOnDemandDeclaration: IMPORT ExpressionName DOT MULTIPLY SEMICOLON  */
#line 583 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4530 "parser.tab.c"
    break;

  case 159: /* StaticImportOnDemandDeclaration: IMPORT STATIC Identifier DOT MULTIPLY SEMICOLON  */
#line 585 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4536 "parser.tab.c"
    break;

  case 160: /* StaticImportOnDemandDeclaration: IMPORT STATIC ExpressionName DOT MULTIPLY SEMICOLON  */
#line 586 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4542 "parser.tab.c"
    break;

  case 163: /* TopLevelClassOrInterfaceDeclaration: SEMICOLON  */
#line 590 "parser.y"
                                                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4548 "parser.tab.c"
    break;

  case 164: /* $@1: %empty  */
#line 592 "parser.y"
                                               {symtable*a=createtable();string p=((yyvsp[-1].str));insertclass(p,"module","",a,line);   changescope(a);  }
#line 4554 "parser.tab.c"
    break;

  case 165: /* ModuleDeclaration: MODULE Identifier LCB $@1 RCB  */
#line 592 "parser.y"
                                                                                                                                                                {goparent();}
#line 4560 "parser.tab.c"
    break;

  case 166: /* $@2: %empty  */
#line 593 "parser.y"
                                        {symtable*a=createtable();string p=((yyvsp[-1].str));insertclass(p,"module","",a,line);   changescope(a);  }
#line 4566 "parser.tab.c"
    break;

  case 167: /* ModuleDeclaration: MODULE Identifier LCB $@2 OMModuleDirective RCB  */
#line 593 "parser.y"
                                                                                                                                                                                {goparent();}
#line 4572 "parser.tab.c"
    break;

  case 168: /* $@3: %empty  */
#line 594 "parser.y"
                                                        {symtable*a=createtable();string p=((yyvsp[-2].str));insertclass(p+((yyvsp[-1].typeinfo))->name,"module","",a,line);changescope(a);}
#line 4578 "parser.tab.c"
    break;

  case 169: /* ModuleDeclaration: MODULE Identifier OMDotIdentifier LCB $@3 RCB  */
#line 594 "parser.y"
                                                                                                                                                                                {goparent();}
#line 4584 "parser.tab.c"
    break;

  case 170: /* $@4: %empty  */
#line 595 "parser.y"
                                                         {symtable*a=createtable();string p=((yyvsp[-2].str));insertclass(p+((yyvsp[-1].typeinfo))->name,"module","",a,line);changescope(a);}
#line 4590 "parser.tab.c"
    break;

  case 171: /* ModuleDeclaration: MODULE Identifier OMDotIdentifier LCB $@4 OMModuleDirective RCB  */
#line 595 "parser.y"
                                                                                                                                                                                                {goparent();}
#line 4596 "parser.tab.c"
    break;

  case 172: /* $@5: %empty  */
#line 596 "parser.y"
                                               {symtable*a=createtable();string p=((yyvsp[-1].str));insertclass(p,"module","",a,line);   changescope(a);  }
#line 4602 "parser.tab.c"
    break;

  case 173: /* ModuleDeclaration: OPEN MODULE Identifier LCB $@5 RCB  */
#line 596 "parser.y"
                                                                                                                                                                                                                                                {goparent();}
#line 4608 "parser.tab.c"
    break;

  case 174: /* $@6: %empty  */
#line 597 "parser.y"
                                              {symtable*a=createtable();string p=((yyvsp[-1].str));insertclass(p,"module","",a,line);}
#line 4614 "parser.tab.c"
    break;

  case 175: /* ModuleDeclaration: OPEN MODULE Identifier LCB $@6 OMModuleDirective RCB  */
#line 597 "parser.y"
                                                                                                                                                                        {goparent();}
#line 4620 "parser.tab.c"
    break;

  case 176: /* $@7: %empty  */
#line 598 "parser.y"
                                                              {symtable*a=createtable();string p=((yyvsp[-2].str));insertclass(p+((yyvsp[-1].typeinfo))->name,"module","",a,line);changescope(a);}
#line 4626 "parser.tab.c"
    break;

  case 177: /* ModuleDeclaration: OPEN MODULE Identifier OMDotIdentifier LCB $@7 RCB  */
#line 598 "parser.y"
                                                                                                                                                                                                                {goparent();}
#line 4632 "parser.tab.c"
    break;

  case 178: /* $@8: %empty  */
#line 599 "parser.y"
                                                              {symtable*a=createtable();string p=((yyvsp[-2].str));insertclass(p+((yyvsp[-1].typeinfo))->name,"module","",a,line);changescope(a);}
#line 4638 "parser.tab.c"
    break;

  case 179: /* ModuleDeclaration: OPEN MODULE Identifier OMDotIdentifier LCB $@8 OMModuleDirective RCB  */
#line 599 "parser.y"
                                                                                                                                                                                                {goparent();}
#line 4644 "parser.tab.c"
    break;

  case 180: /* ModuleDirective: REQUIRES ModuleName SEMICOLON  */
#line 601 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4650 "parser.tab.c"
    break;

  case 181: /* ModuleDirective: REQUIRES OMRequiresModifier ModuleName SEMICOLON  */
#line 602 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4656 "parser.tab.c"
    break;

  case 182: /* ModuleDirective: EXPORTS Identifier SEMICOLON  */
#line 603 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4662 "parser.tab.c"
    break;

  case 183: /* ModuleDirective: EXPORTS Identifier TO ModuleName SEMICOLON  */
#line 604 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4668 "parser.tab.c"
    break;

  case 184: /* ModuleDirective: EXPORTS Identifier TO ModuleName OMCommaModuleName SEMICOLON  */
#line 605 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4674 "parser.tab.c"
    break;

  case 185: /* ModuleDirective: OPENS Identifier SEMICOLON  */
#line 606 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4680 "parser.tab.c"
    break;

  case 186: /* ModuleDirective: OPENS Identifier TO ModuleName SEMICOLON  */
#line 607 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4686 "parser.tab.c"
    break;

  case 187: /* ModuleDirective: OPENS Identifier TO ModuleName OMCommaModuleName SEMICOLON  */
#line 608 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4692 "parser.tab.c"
    break;

  case 188: /* ModuleDirective: USES Identifier SEMICOLON  */
#line 609 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4698 "parser.tab.c"
    break;

  case 189: /* ModuleDirective: PROVIDES Identifier WITH Identifier SEMICOLON  */
#line 610 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4704 "parser.tab.c"
    break;

  case 190: /* ModuleDirective: PROVIDES Identifier WITH Identifier OMCommaTypeName SEMICOLON  */
#line 611 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4710 "parser.tab.c"
    break;

  case 191: /* ModuleDirective: EXPORTS ExpressionName SEMICOLON  */
#line 612 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4716 "parser.tab.c"
    break;

  case 192: /* ModuleDirective: EXPORTS ExpressionName TO ModuleName SEMICOLON  */
#line 613 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4722 "parser.tab.c"
    break;

  case 193: /* ModuleDirective: EXPORTS ExpressionName TO ModuleName OMCommaModuleName SEMICOLON  */
#line 614 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4728 "parser.tab.c"
    break;

  case 194: /* ModuleDirective: OPENS ExpressionName SEMICOLON  */
#line 615 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4734 "parser.tab.c"
    break;

  case 195: /* ModuleDirective: OPENS ExpressionName TO ModuleName SEMICOLON  */
#line 616 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4740 "parser.tab.c"
    break;

  case 196: /* ModuleDirective: OPENS ExpressionName TO ModuleName OMCommaModuleName SEMICOLON  */
#line 617 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4746 "parser.tab.c"
    break;

  case 197: /* ModuleDirective: USES ExpressionName SEMICOLON  */
#line 618 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4752 "parser.tab.c"
    break;

  case 198: /* ModuleDirective: PROVIDES ExpressionName WITH ExpressionName SEMICOLON  */
#line 619 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4758 "parser.tab.c"
    break;

  case 199: /* ModuleDirective: PROVIDES ExpressionName WITH ExpressionName OMCommaTypeName SEMICOLON  */
#line 620 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 4764 "parser.tab.c"
    break;

  case 200: /* ModuleDirective: PROVIDES ExpressionName WITH Identifier SEMICOLON  */
#line 621 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4770 "parser.tab.c"
    break;

  case 201: /* ModuleDirective: PROVIDES Identifier WITH ExpressionName OMCommaTypeName SEMICOLON  */
#line 622 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4776 "parser.tab.c"
    break;

  case 202: /* ModuleDirective: PROVIDES Identifier WITH ExpressionName SEMICOLON  */
#line 623 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4782 "parser.tab.c"
    break;

  case 203: /* ModuleDirective: PROVIDES ExpressionName WITH Identifier OMCommaTypeName SEMICOLON  */
#line 624 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 4788 "parser.tab.c"
    break;

  case 206: /* $@9: %empty  */
#line 629 "parser.y"
                                                                                        {symtable*a=createscope("class");string p=((yyvsp[0].str));insertclass(p,"class","",a,line);   changescope(a);  }
#line 4794 "parser.tab.c"
    break;

  case 207: /* NormalClassDeclaration: CLASS Identifier $@9 ClassBody  */
#line 629 "parser.y"
                                                                                                                                                                                                                {goparent();}
#line 4800 "parser.tab.c"
    break;

  case 208: /* $@10: %empty  */
#line 630 "parser.y"
                                                                                                {symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 4806 "parser.tab.c"
    break;

  case 209: /* NormalClassDeclaration: CLASS Identifier ClassPermits $@10 ClassBody  */
#line 630 "parser.y"
                                                                                                                                                                                                                                {goparent();}
#line 4812 "parser.tab.c"
    break;

  case 210: /* $@11: %empty  */
#line 631 "parser.y"
                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 4818 "parser.tab.c"
    break;

  case 211: /* NormalClassDeclaration: CLASS Identifier ClassImplements $@11 ClassBody  */
#line 631 "parser.y"
                                                                                                                                                                                                                {goparent();}
#line 4824 "parser.tab.c"
    break;

  case 212: /* $@12: %empty  */
#line 632 "parser.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 4830 "parser.tab.c"
    break;

  case 213: /* NormalClassDeclaration: CLASS Identifier ClassImplements ClassPermits $@12 ClassBody  */
#line 632 "parser.y"
                                                                                                                                                                                                                {goparent();}
#line 4836 "parser.tab.c"
    break;

  case 214: /* $@13: %empty  */
#line 633 "parser.y"
                                                                                                { symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 4842 "parser.tab.c"
    break;

  case 215: /* NormalClassDeclaration: CLASS Identifier ClassExtends $@13 ClassBody  */
#line 633 "parser.y"
                                                                                                                                                                                                                                        {goparent();}
#line 4848 "parser.tab.c"
    break;

  case 216: /* $@14: %empty  */
#line 634 "parser.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 4854 "parser.tab.c"
    break;

  case 217: /* NormalClassDeclaration: CLASS Identifier ClassExtends ClassPermits $@14 ClassBody  */
#line 634 "parser.y"
                                                                                                                                                                                                        {goparent();}
#line 4860 "parser.tab.c"
    break;

  case 218: /* $@15: %empty  */
#line 635 "parser.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 4866 "parser.tab.c"
    break;

  case 219: /* NormalClassDeclaration: CLASS Identifier ClassExtends ClassImplements $@15 ClassBody  */
#line 635 "parser.y"
                                                                                                                                                                                                        {goparent();}
#line 4872 "parser.tab.c"
    break;

  case 220: /* $@16: %empty  */
#line 636 "parser.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 4878 "parser.tab.c"
    break;

  case 221: /* NormalClassDeclaration: CLASS Identifier ClassExtends ClassImplements ClassPermits $@16 ClassBody  */
#line 636 "parser.y"
                                                                                                                                                                                                                {goparent();}
#line 4884 "parser.tab.c"
    break;

  case 222: /* $@17: %empty  */
#line 637 "parser.y"
                                                                                                                { symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 4890 "parser.tab.c"
    break;

  case 223: /* NormalClassDeclaration: CLASS Identifier TypeParameters $@17 ClassBody  */
#line 637 "parser.y"
                                                                                                                                                                                                                                                                        {goparent();}
#line 4896 "parser.tab.c"
    break;

  case 224: /* $@18: %empty  */
#line 638 "parser.y"
                                                                                                {symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);     changescope(a);  }
#line 4902 "parser.tab.c"
    break;

  case 225: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassPermits $@18 ClassBody  */
#line 638 "parser.y"
                                                                                                                                                                                                                                {goparent();}
#line 4908 "parser.tab.c"
    break;

  case 226: /* $@19: %empty  */
#line 639 "parser.y"
                                                                                                {symtable*a=createscope("class");string p=((yyvsp[-2].str)); insertclass(p,"class","",a,line);    changescope(a);  }
#line 4914 "parser.tab.c"
    break;

  case 227: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassImplements $@19 ClassBody  */
#line 639 "parser.y"
                                                                                                                                                                                                                                {goparent();}
#line 4920 "parser.tab.c"
    break;

  case 228: /* $@20: %empty  */
#line 640 "parser.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 4926 "parser.tab.c"
    break;

  case 229: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassImplements ClassPermits $@20 ClassBody  */
#line 640 "parser.y"
                                                                                                                                                                                                                {goparent();}
#line 4932 "parser.tab.c"
    break;

  case 230: /* $@21: %empty  */
#line 641 "parser.y"
                                                                                                {symtable*a=createscope("class");string p=((yyvsp[-2].str)); insertclass(p,"class","",a,line);    changescope(a);  }
#line 4938 "parser.tab.c"
    break;

  case 231: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassExtends $@21 ClassBody  */
#line 641 "parser.y"
                                                                                                                                                                                                                                {goparent();}
#line 4944 "parser.tab.c"
    break;

  case 232: /* $@22: %empty  */
#line 642 "parser.y"
                                                                                {symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);     changescope(a);  }
#line 4950 "parser.tab.c"
    break;

  case 233: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassExtends ClassPermits $@22 ClassBody  */
#line 642 "parser.y"
                                                                                                                                                                                                                {goparent();}
#line 4956 "parser.tab.c"
    break;

  case 234: /* $@23: %empty  */
#line 643 "parser.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 4962 "parser.tab.c"
    break;

  case 235: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassExtends ClassImplements $@23 ClassBody  */
#line 643 "parser.y"
                                                                                                                                                                                                        {goparent();}
#line 4968 "parser.tab.c"
    break;

  case 236: /* $@24: %empty  */
#line 644 "parser.y"
                                                                                            {symtable*a=createscope("class");string p=((yyvsp[-4].str)); insertclass(p,"class","",a,line);    changescope(a);  }
#line 4974 "parser.tab.c"
    break;

  case 237: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassExtends ClassImplements ClassPermits $@24 ClassBody  */
#line 644 "parser.y"
                                                                                                                                                                                                                {goparent();}
#line 4980 "parser.tab.c"
    break;

  case 238: /* $@25: %empty  */
#line 645 "parser.y"
                                                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[0].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 4986 "parser.tab.c"
    break;

  case 239: /* NormalClassDeclaration: OMClassModifier CLASS Identifier $@25 ClassBody  */
#line 645 "parser.y"
                                                                                                                                                                                                                                                                                                        {goparent();}
#line 4992 "parser.tab.c"
    break;

  case 240: /* $@26: %empty  */
#line 646 "parser.y"
                                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 4998 "parser.tab.c"
    break;

  case 241: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassPermits $@26 ClassBody  */
#line 646 "parser.y"
                                                                                                                                                                                                                                                                {goparent();}
#line 5004 "parser.tab.c"
    break;

  case 242: /* $@27: %empty  */
#line 647 "parser.y"
                                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-1].str)); insertclass(p,"class","",a,line);    changescope(a);  }
#line 5010 "parser.tab.c"
    break;

  case 243: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassImplements $@27 ClassBody  */
#line 647 "parser.y"
                                                                                                                                                                                                                                                        {goparent();}
#line 5016 "parser.tab.c"
    break;

  case 244: /* $@28: %empty  */
#line 648 "parser.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5022 "parser.tab.c"
    break;

  case 245: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassImplements ClassPermits $@28 ClassBody  */
#line 648 "parser.y"
                                                                                                                                                                                                                                        {goparent();}
#line 5028 "parser.tab.c"
    break;

  case 246: /* $@29: %empty  */
#line 649 "parser.y"
                                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5034 "parser.tab.c"
    break;

  case 247: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassExtends $@29 ClassBody  */
#line 649 "parser.y"
                                                                                                                                                                                                                                                                {goparent();}
#line 5040 "parser.tab.c"
    break;

  case 248: /* $@30: %empty  */
#line 650 "parser.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5046 "parser.tab.c"
    break;

  case 249: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassExtends ClassPermits $@30 ClassBody  */
#line 650 "parser.y"
                                                                                                                                                                                                                                        {goparent();}
#line 5052 "parser.tab.c"
    break;

  case 250: /* $@31: %empty  */
#line 651 "parser.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5058 "parser.tab.c"
    break;

  case 251: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassExtends ClassImplements $@31 ClassBody  */
#line 651 "parser.y"
                                                                                                                                                                                                                                        {goparent();}
#line 5064 "parser.tab.c"
    break;

  case 252: /* $@32: %empty  */
#line 652 "parser.y"
                                                                                            { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5070 "parser.tab.c"
    break;

  case 253: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassExtends ClassImplements ClassPermits $@32 ClassBody  */
#line 652 "parser.y"
                                                                                                                                                                                                                        {goparent();}
#line 5076 "parser.tab.c"
    break;

  case 254: /* $@33: %empty  */
#line 653 "parser.y"
                                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-1].str)); insertclass(p,"class","",a,line);    changescope(a);  }
#line 5082 "parser.tab.c"
    break;

  case 255: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters $@33 ClassBody  */
#line 653 "parser.y"
                                                                                                                                                                                                                                                                                {goparent();}
#line 5088 "parser.tab.c"
    break;

  case 256: /* $@34: %empty  */
#line 654 "parser.y"
                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5094 "parser.tab.c"
    break;

  case 257: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassPermits $@34 ClassBody  */
#line 654 "parser.y"
                                                                                                                                                                                                                                                {goparent();}
#line 5100 "parser.tab.c"
    break;

  case 258: /* $@35: %empty  */
#line 655 "parser.y"
                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-2].str)); insertclass(p,"class","",a,line);    changescope(a);  }
#line 5106 "parser.tab.c"
    break;

  case 259: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassImplements $@35 ClassBody  */
#line 655 "parser.y"
                                                                                                                                                                                                                                        {goparent();}
#line 5112 "parser.tab.c"
    break;

  case 260: /* $@36: %empty  */
#line 656 "parser.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5118 "parser.tab.c"
    break;

  case 261: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassImplements ClassPermits $@36 ClassBody  */
#line 656 "parser.y"
                                                                                                                                                                                                                                {goparent();}
#line 5124 "parser.tab.c"
    break;

  case 262: /* $@37: %empty  */
#line 657 "parser.y"
                                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);     changescope(a);  }
#line 5130 "parser.tab.c"
    break;

  case 263: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassExtends $@37 ClassBody  */
#line 657 "parser.y"
                                                                                                                                                                                                                                                                                {goparent();}
#line 5136 "parser.tab.c"
    break;

  case 264: /* $@38: %empty  */
#line 658 "parser.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5142 "parser.tab.c"
    break;

  case 265: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassPermits $@38 ClassBody  */
#line 658 "parser.y"
                                                                                                                                                                                                                                        {goparent();}
#line 5148 "parser.tab.c"
    break;

  case 266: /* $@39: %empty  */
#line 659 "parser.y"
                                                                                                        { symtable*a=createtable();string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5154 "parser.tab.c"
    break;

  case 267: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassImplements $@39 ClassBody  */
#line 659 "parser.y"
                                                                                                                                                                                                                        {goparent();}
#line 5160 "parser.tab.c"
    break;

  case 268: /* $@40: %empty  */
#line 660 "parser.y"
                                                                                                             { symtable*a=createscope("class");string p=((yyvsp[-4].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5166 "parser.tab.c"
    break;

  case 269: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassImplements ClassPermits $@40 ClassBody  */
#line 660 "parser.y"
                                                                                                                                                                                                                                {goparent();}
#line 5172 "parser.tab.c"
    break;

  case 270: /* TypeParameters: LT TypeParameterList GT  */
#line 662 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5178 "parser.tab.c"
    break;

  case 273: /* ClassExtends: EXTENDS Identifier  */
#line 667 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5184 "parser.tab.c"
    break;

  case 274: /* ClassImplements: IMPLEMENTS InterfaceTypeList  */
#line 669 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5190 "parser.tab.c"
    break;

  case 275: /* InterfaceTypeList: Identifier  */
#line 671 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5196 "parser.tab.c"
    break;

  case 276: /* InterfaceTypeList: Identifier OMCommaInterfaceType  */
#line 672 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5202 "parser.tab.c"
    break;

  case 277: /* ClassPermits: PERMITS Identifier  */
#line 675 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5208 "parser.tab.c"
    break;

  case 278: /* ClassPermits: PERMITS ExpressionName  */
#line 676 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5214 "parser.tab.c"
    break;

  case 279: /* ClassPermits: PERMITS Identifier OMCommaTypeName  */
#line 677 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5220 "parser.tab.c"
    break;

  case 280: /* ClassPermits: PERMITS ExpressionName OMCommaTypeName  */
#line 678 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5226 "parser.tab.c"
    break;

  case 281: /* ClassBody: LCB RCB  */
#line 680 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5232 "parser.tab.c"
    break;

  case 282: /* ClassBody: LCB OMClassBodyDeclaration RCB  */
#line 681 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5238 "parser.tab.c"
    break;

  case 291: /* ClassMemberDeclaration: SEMICOLON  */
#line 692 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5244 "parser.tab.c"
    break;

  case 292: /* FieldDeclaration: UnannType VariableDeclaratorList SEMICOLON  */
#line 694 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->variables=((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type=((yyvsp[-2].typeinfo))->type+((yyvsp[-1].typeinfo))->type;for(auto z:((yyval.typeinfo))->variables)insertidentifier(z,((yyval.typeinfo))->type,"",line);}
#line 5250 "parser.tab.c"
    break;

  case 293: /* FieldDeclaration: OMClassModifier UnannType VariableDeclaratorList SEMICOLON  */
#line 695 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->variables=((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type=((yyvsp[-2].typeinfo))->type+((yyvsp[-1].typeinfo))->type;for(auto z:((yyval.typeinfo))->variables)insertidentifier(z,((yyval.typeinfo))->type,"",line);}
#line 5256 "parser.tab.c"
    break;

  case 294: /* VariableDeclaratorList: VariableDeclarator  */
#line 697 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->variables.push_back((yyvsp[0].typeinfo)->variable);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->decorders2.push_back(((yyvsp[0].typeinfo))->decorder2);(yyval.typeinfo)->arrtypes.push_back((yyvsp[0].typeinfo)->arrtype);(yyval.typeinfo)->arrdims.push_back((yyvsp[0].typeinfo)->arrdim);(yyval.typeinfo)->initialdecls.push_back((yyvsp[0].typeinfo)->initialdecl);(yyval.typeinfo)->initvartypes.push_back((yyvsp[0].typeinfo)->initvartype);}
#line 5262 "parser.tab.c"
    break;

  case 295: /* VariableDeclaratorList: VariableDeclaratorList COMMA VariableDeclarator  */
#line 698 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-2].typeinfo);((yyval.typeinfo))->variables.push_back((yyvsp[0].typeinfo)->variable);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->decorders2.push_back(((yyvsp[0].typeinfo))->decorder2);(yyval.typeinfo)->arrtypes.push_back((yyvsp[0].typeinfo)->arrtype);(yyval.typeinfo)->arrdims.push_back((yyvsp[0].typeinfo)->arrdim);(yyval.typeinfo)->initialdecls.push_back((yyvsp[0].typeinfo)->initialdecl);(yyval.typeinfo)->initvartypes.push_back((yyvsp[0].typeinfo)->initvartype);}
#line 5268 "parser.tab.c"
    break;

  case 296: /* VariableDeclarator: VariableDeclaratorId  */
#line 700 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->initialdecl=false;}
#line 5274 "parser.tab.c"
    break;

  case 297: /* VariableDeclarator: VariableDeclaratorId EQUAL VariableInitializer  */
#line 701 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-2].typeinfo);(yyval.typeinfo)->initialdecl=true;(yyval.typeinfo)->arrtype=(yyvsp[0].typeinfo)->arrtype;(yyval.typeinfo)->arrdim=(yyvsp[0].typeinfo)->arrdim;(yyval.typeinfo)->initvartype=(yyvsp[0].typeinfo)->initvartype;}
#line 5280 "parser.tab.c"
    break;

  case 298: /* VariableDeclaratorId: Identifier  */
#line 703 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();string p=((yyvsp[0].str));(yyval.typeinfo)->variable=p;(yyval.typeinfo)->decorder2=0;}
#line 5286 "parser.tab.c"
    break;

  case 299: /* VariableDeclaratorId: Identifier OMPSB  */
#line 704 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();string p=((yyvsp[-1].str));(yyval.typeinfo)->variable=p;(yyval.typeinfo)->decorder2=(yyvsp[0].typeinfo)->order;}
#line 5292 "parser.tab.c"
    break;

  case 300: /* VariableInitializer: Expression  */
#line 707 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 5298 "parser.tab.c"
    break;

  case 301: /* VariableInitializer: ArrayInitializer  */
#line 708 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->arrtype=(yyvsp[0].typeinfo)->arrtype;(yyval.typeinfo)->arrdim=(yyvsp[0].typeinfo)->arrdim;(yyval.typeinfo)->initvartype="";}
#line 5304 "parser.tab.c"
    break;

  case 302: /* UnannType: UnannPrimitiveType  */
#line 710 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->dectype=(yyvsp[0].typeinfo)->type;(yyvsp[0].typeinfo)->decorder1=0;}
#line 5310 "parser.tab.c"
    break;

  case 303: /* UnannType: Identifier  */
#line 711 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();string p = (yyvsp[0].str);((yyval.typeinfo))->type = p;}
#line 5316 "parser.tab.c"
    break;

  case 304: /* UnannType: UnannArrayType  */
#line 712 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type=((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->dectype=(yyvsp[0].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[0].typeinfo)->decorder1;}
#line 5322 "parser.tab.c"
    break;

  case 305: /* UnannPrimitiveType: NumericType  */
#line 714 "parser.y"
                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 5328 "parser.tab.c"
    break;

  case 306: /* UnannPrimitiveType: BOOLEAN  */
#line 715 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";}
#line 5334 "parser.tab.c"
    break;

  case 307: /* UnannArrayType: UnannPrimitiveType OMPSB  */
#line 717 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type + ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->dectype=(yyvsp[-1].typeinfo)->type;(yyval.typeinfo)->decorder1=(yyvsp[0].typeinfo)->order;}
#line 5340 "parser.tab.c"
    break;

  case 308: /* UnannArrayType: Identifier OMPSB  */
#line 718 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();string p = (yyvsp[-1].str);((yyval.typeinfo))->type = p + ((yyvsp[0].typeinfo))->type;}
#line 5346 "parser.tab.c"
    break;

  case 309: /* MethodDeclaration: MethodHeader MethodBody  */
#line 720 "parser.y"
                                                                {goparent();insertmethod(((yyvsp[-1].typeinfo))->variables[0],"Method",((yyvsp[-1].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-1].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);}
#line 5352 "parser.tab.c"
    break;

  case 310: /* MethodDeclaration: OMClassModifier MethodHeader MethodBody  */
#line 721 "parser.y"
                                                                                {goparent();insertmethod(((yyvsp[-1].typeinfo))->variables[0],"Method",((yyvsp[-1].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);}
#line 5358 "parser.tab.c"
    break;

  case 311: /* MethodHeader: Result MethodDeclarator  */
#line 723 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;((yyval.typeinfo))->variables = ((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;((yyval.typeinfo))->scope =((yyvsp[-1].typeinfo))->scope;((yyval.typeinfo))->linep = ((yyvsp[0].typeinfo))->linep;}
#line 5364 "parser.tab.c"
    break;

  case 313: /* MethodHeader: TypeParameters Result MethodDeclarator  */
#line 725 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;((yyval.typeinfo))->variables = ((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;((yyval.typeinfo))->scope =((yyvsp[-1].typeinfo))->scope;((yyval.typeinfo))->linep = ((yyvsp[0].typeinfo))->linep;}
#line 5370 "parser.tab.c"
    break;

  case 315: /* Result: UnannType Identifier  */
#line 728 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();symtable*a = createscope("Method");((yyval.typeinfo))->scope = a; ((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;string p = (yyvsp[0].str);((yyval.typeinfo))->variables.push_back(p); changescope(a);}
#line 5376 "parser.tab.c"
    break;

  case 316: /* Result: VOID Identifier  */
#line 729 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();symtable*a = createscope("Method");((yyval.typeinfo))->scope = a;((yyval.typeinfo))->type = "void";string p = (yyvsp[0].str);((yyval.typeinfo))->variables.push_back(p); changescope(a);}
#line 5382 "parser.tab.c"
    break;

  case 317: /* MethodDeclarator: LRB RRB  */
#line 732 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back("void");((yyval.typeinfo))->linep = line;}
#line 5388 "parser.tab.c"
    break;

  case 318: /* MethodDeclarator: LRB RRB OMPSB  */
#line 733 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5394 "parser.tab.c"
    break;

  case 319: /* MethodDeclarator: LRB FormalParameterList RRB  */
#line 734 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;((yyval.typeinfo))->linep = line;}
#line 5400 "parser.tab.c"
    break;

  case 320: /* MethodDeclarator: LRB FormalParameterList RRB OMPSB  */
#line 735 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5406 "parser.tab.c"
    break;

  case 321: /* MethodDeclarator: LRB ReceiverParameterComma RRB  */
#line 736 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5412 "parser.tab.c"
    break;

  case 322: /* MethodDeclarator: LRB ReceiverParameterComma RRB OMPSB  */
#line 737 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();}
#line 5418 "parser.tab.c"
    break;

  case 323: /* MethodDeclarator: LRB ReceiverParameterComma FormalParameterList RRB  */
#line 738 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;((yyval.typeinfo))->linep = line;}
#line 5424 "parser.tab.c"
    break;

  case 324: /* MethodDeclarator: LRB ReceiverParameterComma FormalParameterList RRB OMPSB  */
#line 739 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();}
#line 5430 "parser.tab.c"
    break;

  case 327: /* FormalParameterList: FormalParameter  */
#line 744 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;}
#line 5436 "parser.tab.c"
    break;

  case 328: /* FormalParameterList: FormalParameter OMCommaFormalParameter  */
#line 745 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();vector<string>a=((yyvsp[-1].typeinfo))->type_variable;vector<string>b=((yyvsp[0].typeinfo))->type_variable;for(auto z:a){((yyval.typeinfo))->type_variable.push_back(z);}for(auto z:b){((yyval.typeinfo))->type_variable.push_back(z);}}
#line 5442 "parser.tab.c"
    break;

  case 329: /* FormalParameter: UnannType VariableDeclaratorId  */
#line 747 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-1].typeinfo))->type+((yyvsp[0].typeinfo))->type);((yyval.typeinfo))->type=((yyvsp[-1].typeinfo))->type+((yyvsp[0].typeinfo))->type;for(auto z:((yyvsp[0].typeinfo))->variables)insertidentifier(z,((yyval.typeinfo))->type,"",line);}
#line 5448 "parser.tab.c"
    break;

  case 330: /* FormalParameter: OMClassModifier UnannType VariableDeclaratorId  */
#line 748 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-1].typeinfo))->type+((yyvsp[0].typeinfo))->type);((yyval.typeinfo))->type=((yyvsp[-1].typeinfo))->type+((yyvsp[0].typeinfo))->type;for(auto z:((yyvsp[0].typeinfo))->variables)insertidentifier(z,((yyval.typeinfo))->type,"",line);}
#line 5454 "parser.tab.c"
    break;

  case 331: /* FormalParameter: VariableArityParameter  */
#line 749 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;}
#line 5460 "parser.tab.c"
    break;

  case 332: /* VariableArityParameter: UnannType THREEDOT Identifier  */
#line 751 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-2].typeinfo))->type);}
#line 5466 "parser.tab.c"
    break;

  case 333: /* VariableArityParameter: OMClassModifier UnannType THREEDOT Identifier  */
#line 752 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-2].typeinfo))->type);}
#line 5472 "parser.tab.c"
    break;

  case 334: /* Throws: THROWS ExceptionTypeList  */
#line 754 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5478 "parser.tab.c"
    break;

  case 337: /* ExceptionType: Identifier  */
#line 759 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5484 "parser.tab.c"
    break;

  case 339: /* MethodBody: SEMICOLON  */
#line 763 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5490 "parser.tab.c"
    break;

  case 341: /* StaticInitializer: STATIC Block  */
#line 767 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5496 "parser.tab.c"
    break;

  case 342: /* ConstructorDeclaration: ConstructorDeclarator ConstructorBody  */
#line 769 "parser.y"
                                                                                {goparent();insertmethod(((yyvsp[-1].typeinfo))->variables[0],"constructor",((yyvsp[-1].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-1].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);}
#line 5502 "parser.tab.c"
    break;

  case 343: /* ConstructorDeclaration: ConstructorDeclarator Throws ConstructorBody  */
#line 770 "parser.y"
                                                                                        {goparent();insertmethod(((yyvsp[-2].typeinfo))->variables[0],"constructor",((yyvsp[-2].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);}
#line 5508 "parser.tab.c"
    break;

  case 344: /* ConstructorDeclaration: OMClassModifier ConstructorDeclarator ConstructorBody  */
#line 771 "parser.y"
                                                                                        {goparent();insertmethod(((yyvsp[-1].typeinfo))->variables[0],"constructor",((yyvsp[-1].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-1].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);}
#line 5514 "parser.tab.c"
    break;

  case 345: /* ConstructorDeclaration: OMClassModifier ConstructorDeclarator Throws ConstructorBody  */
#line 772 "parser.y"
                                                                                {goparent();insertmethod(((yyvsp[-2].typeinfo))->variables[0],"constructor",((yyvsp[-2].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);}
#line 5520 "parser.tab.c"
    break;

  case 346: /* ConstructorDeclaratorLRBSym: LRB  */
#line 774 "parser.y"
                                 {(yyval.typeinfo) = createstruct();symtable*a = createscope("constructor");((yyval.typeinfo))->scope = a; changescope(a);}
#line 5526 "parser.tab.c"
    break;

  case 347: /* ConstructorDeclarator: Identifier ConstructorDeclaratorLRBSym RRB  */
#line 776 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->scope = ((yyvsp[-1].typeinfo))->scope; ((yyval.typeinfo))->type_variable.push_back("void");string p = (yyvsp[-2].str);((yyval.typeinfo))->variables.push_back(p);((yyval.typeinfo))->type = "void";((yyval.typeinfo))->linep = line;}
#line 5532 "parser.tab.c"
    break;

  case 348: /* ConstructorDeclarator: Identifier ConstructorDeclaratorLRBSym FormalParameterList RRB  */
#line 777 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->scope = ((yyvsp[-2].typeinfo))->scope;((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;string p = (yyvsp[-3].str);((yyval.typeinfo))->variables.push_back(p);((yyval.typeinfo))->type = "void";((yyval.typeinfo))->linep = line;}
#line 5538 "parser.tab.c"
    break;

  case 349: /* ConstructorDeclarator: Identifier LRB ReceiverParameterComma RRB  */
#line 778 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5544 "parser.tab.c"
    break;

  case 350: /* ConstructorDeclarator: Identifier LRB ReceiverParameterComma FormalParameterList RRB  */
#line 779 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5550 "parser.tab.c"
    break;

  case 351: /* ConstructorDeclarator: TypeParameters Identifier ConstructorDeclaratorLRBSym RRB  */
#line 780 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->scope = ((yyvsp[-1].typeinfo))->scope;((yyval.typeinfo))->type_variable.push_back("void");string p = (yyvsp[-2].str); ((yyval.typeinfo))->variables.push_back(p);((yyval.typeinfo))->type = "void";((yyval.typeinfo))->linep = line;}
#line 5556 "parser.tab.c"
    break;

  case 352: /* ConstructorDeclarator: TypeParameters Identifier ConstructorDeclaratorLRBSym FormalParameterList RRB  */
#line 781 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->scope = ((yyvsp[-2].typeinfo))->scope;((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;string p = (yyvsp[-3].str);((yyval.typeinfo))->variables.push_back(p);((yyval.typeinfo))->type = "void";((yyval.typeinfo))->linep = line;}
#line 5562 "parser.tab.c"
    break;

  case 355: /* ConstructorBody: LCB RCB  */
#line 786 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5568 "parser.tab.c"
    break;

  case 356: /* ConstructorBody: LCB BlockStatements RCB  */
#line 787 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5574 "parser.tab.c"
    break;

  case 357: /* ConstructorBody: LCB ExplicitConstructorInvocation RCB  */
#line 788 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5580 "parser.tab.c"
    break;

  case 358: /* ConstructorBody: LCB ExplicitConstructorInvocation BlockStatements RCB  */
#line 789 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5586 "parser.tab.c"
    break;

  case 359: /* ExplicitConstructorInvocation: THIS LRB RRB SEMICOLON  */
#line 791 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5592 "parser.tab.c"
    break;

  case 360: /* ExplicitConstructorInvocation: THIS LRB ArgumentList RRB SEMICOLON  */
#line 792 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5598 "parser.tab.c"
    break;

  case 361: /* ExplicitConstructorInvocation: SUPER LRB RRB SEMICOLON  */
#line 793 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5604 "parser.tab.c"
    break;

  case 362: /* ExplicitConstructorInvocation: SUPER LRB ArgumentList RRB SEMICOLON  */
#line 794 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5610 "parser.tab.c"
    break;

  case 363: /* ExplicitConstructorInvocation: Identifier DOT SUPER LRB RRB SEMICOLON  */
#line 795 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5616 "parser.tab.c"
    break;

  case 364: /* ExplicitConstructorInvocation: Identifier DOT SUPER LRB ArgumentList RRB SEMICOLON  */
#line 796 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5622 "parser.tab.c"
    break;

  case 365: /* ExplicitConstructorInvocation: ExpressionName DOT SUPER LRB RRB SEMICOLON  */
#line 797 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5628 "parser.tab.c"
    break;

  case 366: /* ExplicitConstructorInvocation: ExpressionName DOT SUPER LRB ArgumentList RRB SEMICOLON  */
#line 798 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5634 "parser.tab.c"
    break;

  case 367: /* ExplicitConstructorInvocation: Primary DOT SUPER LRB RRB SEMICOLON  */
#line 799 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5640 "parser.tab.c"
    break;

  case 368: /* ExplicitConstructorInvocation: Primary DOT SUPER LRB ArgumentList RRB SEMICOLON  */
#line 800 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5646 "parser.tab.c"
    break;

  case 369: /* RecordDeclarationSym: RECORD Identifier  */
#line 803 "parser.y"
                                        {(yyval.typeinfo) = createstruct();symtable*a=createscope("record");((yyval.typeinfo))->scope = a; ((yyval.typeinfo))->type = "record";string p = (yyvsp[0].str);((yyval.typeinfo))->variables.push_back(p); changescope(a);}
#line 5652 "parser.tab.c"
    break;

  case 370: /* RecordDeclaration: RecordDeclarationSym RecordHeader RecordBody  */
#line 805 "parser.y"
                                                                                                        {goparent();insertmethod(((yyvsp[-2].typeinfo))->variables[0],"record",((yyvsp[-2].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);}
#line 5658 "parser.tab.c"
    break;

  case 371: /* RecordDeclaration: RecordDeclarationSym RecordHeader ClassImplements RecordBody  */
#line 806 "parser.y"
                                                                                                                        {goparent();insertmethod(((yyvsp[-3].typeinfo))->variables[0],"record",((yyvsp[-3].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-3].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);}
#line 5664 "parser.tab.c"
    break;

  case 372: /* RecordDeclaration: RecordDeclarationSym TypeParameters RecordHeader RecordBody  */
#line 807 "parser.y"
                                                                                                                                                        {goparent();insertmethod(((yyvsp[-3].typeinfo))->variables[0],"record",((yyvsp[-3].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-3].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);}
#line 5670 "parser.tab.c"
    break;

  case 373: /* RecordDeclaration: RecordDeclarationSym TypeParameters RecordHeader ClassImplements RecordBody  */
#line 808 "parser.y"
                                                                                                                        {goparent();insertmethod(((yyvsp[-4].typeinfo))->variables[0],"record",((yyvsp[-4].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-4].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);}
#line 5676 "parser.tab.c"
    break;

  case 374: /* RecordDeclaration: OMClassModifier RecordDeclarationSym RecordHeader RecordBody  */
#line 809 "parser.y"
                                                                                                                                                        {goparent();insertmethod(((yyvsp[-2].typeinfo))->variables[0],"record",((yyvsp[-2].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);}
#line 5682 "parser.tab.c"
    break;

  case 375: /* RecordDeclaration: OMClassModifier RecordDeclarationSym RecordHeader ClassImplements RecordBody  */
#line 810 "parser.y"
                                                                                                                {goparent();insertmethod(((yyvsp[-3].typeinfo))->variables[0],"record",((yyvsp[-3].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-3].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);}
#line 5688 "parser.tab.c"
    break;

  case 376: /* RecordDeclaration: OMClassModifier RecordDeclarationSym TypeParameters RecordHeader RecordBody  */
#line 811 "parser.y"
                                                                                                                {goparent();insertmethod(((yyvsp[-3].typeinfo))->variables[0],"record",((yyvsp[-3].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-3].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);}
#line 5694 "parser.tab.c"
    break;

  case 377: /* RecordDeclaration: OMClassModifier RecordDeclarationSym TypeParameters RecordHeader ClassImplements RecordBody  */
#line 812 "parser.y"
                                                                                                                        {goparent();insertmethod(((yyvsp[-4].typeinfo))->variables[0],"record",((yyvsp[-4].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-4].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);}
#line 5700 "parser.tab.c"
    break;

  case 378: /* RecordHeader: LRB RRB  */
#line 815 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back("void");((yyval.typeinfo))->linep = line;}
#line 5706 "parser.tab.c"
    break;

  case 379: /* RecordHeader: LRB RecordComponentList RRB  */
#line 816 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;((yyval.typeinfo))->linep = line;}
#line 5712 "parser.tab.c"
    break;

  case 380: /* RecordComponentList: RecordComponent  */
#line 818 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;}
#line 5718 "parser.tab.c"
    break;

  case 381: /* RecordComponentList: RecordComponent OMCommaRecordComponent  */
#line 819 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();vector<string>a=((yyvsp[-1].typeinfo))->type_variable;vector<string>b=((yyvsp[0].typeinfo))->type_variable;for(auto z:a){((yyval.typeinfo))->type_variable.push_back(z);}for(auto z:b){((yyval.typeinfo))->type_variable.push_back(z);}}
#line 5724 "parser.tab.c"
    break;

  case 382: /* RecordComponent: UnannType Identifier  */
#line 821 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-1].typeinfo))->type);}
#line 5730 "parser.tab.c"
    break;

  case 383: /* RecordComponent: VariableArityRecordComponent  */
#line 822 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;}
#line 5736 "parser.tab.c"
    break;

  case 384: /* VariableArityRecordComponent: UnannType THREEDOT Identifier  */
#line 825 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-2].typeinfo))->type);}
#line 5742 "parser.tab.c"
    break;

  case 385: /* RecordBody: LCB RCB  */
#line 827 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5748 "parser.tab.c"
    break;

  case 386: /* RecordBody: LCB OMRecordBodyDeclaration RCB  */
#line 828 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5754 "parser.tab.c"
    break;

  case 389: /* CompactConstructorDeclarationSym: Identifier  */
#line 833 "parser.y"
                                             {vector<string>tec; symtable*a=createscope("compactconstructor");string p=((yyvsp[0].str));insertmethod(p,"compactconstructor","auto",tec,a,"",line);changescope(a);}
#line 5760 "parser.tab.c"
    break;

  case 390: /* CompactConstructorDeclaration: CompactConstructorDeclarationSym ConstructorBody  */
#line 835 "parser.y"
                                                                                                        {goparent();}
#line 5766 "parser.tab.c"
    break;

  case 391: /* CompactConstructorDeclaration: OMClassModifier CompactConstructorDeclarationSym ConstructorBody  */
#line 836 "parser.y"
                                                                                                                                {goparent();}
#line 5772 "parser.tab.c"
    break;

  case 393: /* $@41: %empty  */
#line 841 "parser.y"
                                                      {symtable*a=createscope("interface");string p=((yyvsp[0].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 5778 "parser.tab.c"
    break;

  case 394: /* NormalInterfaceDeclaration: INTERFACE Identifier $@41 InterfaceBody  */
#line 841 "parser.y"
                                                                                                                                                                                        {goparent();}
#line 5784 "parser.tab.c"
    break;

  case 395: /* $@42: %empty  */
#line 842 "parser.y"
                                                                  {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 5790 "parser.tab.c"
    break;

  case 396: /* NormalInterfaceDeclaration: INTERFACE Identifier InterfacePermits $@42 InterfaceBody  */
#line 842 "parser.y"
                                                                                                                                                                                                        {goparent();}
#line 5796 "parser.tab.c"
    break;

  case 397: /* $@43: %empty  */
#line 843 "parser.y"
                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 5802 "parser.tab.c"
    break;

  case 398: /* NormalInterfaceDeclaration: INTERFACE Identifier InterfaceExtends $@43 InterfaceBody  */
#line 843 "parser.y"
                                                                                                                                                                                                        {goparent();}
#line 5808 "parser.tab.c"
    break;

  case 399: /* $@44: %empty  */
#line 844 "parser.y"
                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 5814 "parser.tab.c"
    break;

  case 400: /* NormalInterfaceDeclaration: INTERFACE Identifier InterfaceExtends InterfacePermits $@44 InterfaceBody  */
#line 844 "parser.y"
                                                                                                                                                                                                                        {goparent();}
#line 5820 "parser.tab.c"
    break;

  case 401: /* $@45: %empty  */
#line 845 "parser.y"
                                                                {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 5826 "parser.tab.c"
    break;

  case 402: /* NormalInterfaceDeclaration: INTERFACE Identifier TypeParameters $@45 InterfaceBody  */
#line 845 "parser.y"
                                                                                                                                                                                                                                {goparent();}
#line 5832 "parser.tab.c"
    break;

  case 403: /* $@46: %empty  */
#line 846 "parser.y"
                                                                                {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 5838 "parser.tab.c"
    break;

  case 404: /* NormalInterfaceDeclaration: INTERFACE Identifier TypeParameters InterfacePermits $@46 InterfaceBody  */
#line 846 "parser.y"
                                                                                                                                                                                                                        {goparent();}
#line 5844 "parser.tab.c"
    break;

  case 405: /* $@47: %empty  */
#line 847 "parser.y"
                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 5850 "parser.tab.c"
    break;

  case 406: /* NormalInterfaceDeclaration: INTERFACE Identifier TypeParameters InterfaceExtends $@47 InterfaceBody  */
#line 847 "parser.y"
                                                                                                                                                                                                                                {goparent();}
#line 5856 "parser.tab.c"
    break;

  case 407: /* $@48: %empty  */
#line 848 "parser.y"
                                                                                                  {symtable*a=createscope("interface");string p=((yyvsp[-3].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 5862 "parser.tab.c"
    break;

  case 408: /* NormalInterfaceDeclaration: INTERFACE Identifier TypeParameters InterfaceExtends InterfacePermits $@48 InterfaceBody  */
#line 848 "parser.y"
                                                                                                                                                                                                                                                {goparent();}
#line 5868 "parser.tab.c"
    break;

  case 409: /* $@49: %empty  */
#line 849 "parser.y"
                                                                {symtable*a=createscope("interface");string p=((yyvsp[0].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 5874 "parser.tab.c"
    break;

  case 410: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier $@49 InterfaceBody  */
#line 849 "parser.y"
                                                                                                                                                                                                                                                {goparent();}
#line 5880 "parser.tab.c"
    break;

  case 411: /* $@50: %empty  */
#line 850 "parser.y"
                                                                                  {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 5886 "parser.tab.c"
    break;

  case 412: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier InterfacePermits $@50 InterfaceBody  */
#line 850 "parser.y"
                                                                                                                                                                                                                                        {goparent();}
#line 5892 "parser.tab.c"
    break;

  case 413: /* $@51: %empty  */
#line 851 "parser.y"
                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 5898 "parser.tab.c"
    break;

  case 414: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier InterfaceExtends $@51 InterfaceBody  */
#line 851 "parser.y"
                                                                                                                                                                                                                                        {goparent();}
#line 5904 "parser.tab.c"
    break;

  case 415: /* $@52: %empty  */
#line 852 "parser.y"
                                                                                                   {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 5910 "parser.tab.c"
    break;

  case 416: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier InterfaceExtends InterfacePermits $@52 InterfaceBody  */
#line 852 "parser.y"
                                                                                                                                                                                                                                {goparent();}
#line 5916 "parser.tab.c"
    break;

  case 417: /* $@53: %empty  */
#line 853 "parser.y"
                                                                               {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 5922 "parser.tab.c"
    break;

  case 418: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier TypeParameters $@53 InterfaceBody  */
#line 853 "parser.y"
                                                                                                                                                                                                                        {goparent();}
#line 5928 "parser.tab.c"
    break;

  case 419: /* $@54: %empty  */
#line 854 "parser.y"
                                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 5934 "parser.tab.c"
    break;

  case 420: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier TypeParameters InterfacePermits $@54 InterfaceBody  */
#line 854 "parser.y"
                                                                                                                                                                                                                                        {goparent();}
#line 5940 "parser.tab.c"
    break;

  case 421: /* $@55: %empty  */
#line 855 "parser.y"
                                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 5946 "parser.tab.c"
    break;

  case 422: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier TypeParameters InterfaceExtends $@55 InterfaceBody  */
#line 855 "parser.y"
                                                                                                                                                                                                                                        {goparent();}
#line 5952 "parser.tab.c"
    break;

  case 423: /* $@56: %empty  */
#line 856 "parser.y"
                                                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-3].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 5958 "parser.tab.c"
    break;

  case 424: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier TypeParameters InterfaceExtends InterfacePermits $@56 InterfaceBody  */
#line 856 "parser.y"
                                                                                                                                                                                                                                                        {goparent();}
#line 5964 "parser.tab.c"
    break;

  case 426: /* InterfaceExtends: EXTENDS InterfaceTypeList  */
#line 861 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5970 "parser.tab.c"
    break;

  case 427: /* InterfacePermits: PERMITS ExpressionName  */
#line 863 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5976 "parser.tab.c"
    break;

  case 428: /* InterfacePermits: PERMITS ExpressionName OMCommaTypeName  */
#line 864 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5982 "parser.tab.c"
    break;

  case 429: /* InterfaceBody: LCB RCB  */
#line 866 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 5988 "parser.tab.c"
    break;

  case 430: /* InterfaceBody: LCB OMInterfaceMemberDeclaration RCB  */
#line 867 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 5994 "parser.tab.c"
    break;

  case 435: /* InterfaceMemberDeclaration: SEMICOLON  */
#line 873 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6000 "parser.tab.c"
    break;

  case 436: /* ConstantDeclaration: UnannType VariableDeclaratorList SEMICOLON  */
#line 875 "parser.y"
                                                                                {vector<string>a=((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type=((yyvsp[-2].typeinfo))->type+((yyvsp[-1].typeinfo))->type;for(auto z:a){insertidentifier(z,((yyvsp[-2].typeinfo))->type,"",line);}}
#line 6006 "parser.tab.c"
    break;

  case 437: /* ConstantDeclaration: OMClassModifier UnannType VariableDeclaratorList SEMICOLON  */
#line 876 "parser.y"
                                                                                {vector<string>a=((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type=((yyvsp[-2].typeinfo))->type+((yyvsp[-1].typeinfo))->type;for(auto z:a){insertidentifier(z,((yyvsp[-2].typeinfo))->type,"",line);}}
#line 6012 "parser.tab.c"
    break;

  case 440: /* ArrayInitializer: LCB RCB  */
#line 881 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "[]";}
#line 6018 "parser.tab.c"
    break;

  case 441: /* ArrayInitializer: LCB COMMA RCB  */
#line 882 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "[]";}
#line 6024 "parser.tab.c"
    break;

  case 442: /* ArrayInitializer: LCB VariableInitializerList RCB  */
#line 883 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type =  ((yyvsp[-1].typeinfo))->type + "[]";}
#line 6030 "parser.tab.c"
    break;

  case 443: /* VariableInitializerList: VariableInitializer  */
#line 885 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type =  ((yyvsp[0].typeinfo))->type ;}
#line 6036 "parser.tab.c"
    break;

  case 444: /* VariableInitializerList: VariableInitializer OMCommaVariableInitializer  */
#line 886 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type =  ((yyvsp[-1].typeinfo))->type;}
#line 6042 "parser.tab.c"
    break;

  case 445: /* Block: LCB RCB  */
#line 888 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6048 "parser.tab.c"
    break;

  case 446: /* Block: LCB BlockStatements RCB  */
#line 889 "parser.y"
                                                        {(yyval.typeinfo) = createstruct();}
#line 6054 "parser.tab.c"
    break;

  case 454: /* LocalVariableDeclarationStatement: LocalVariableDeclaration SEMICOLON  */
#line 901 "parser.y"
                                                                                        {(yyval.typeinfo)=createstruct();(yyval.typeinfo)=(yyvsp[-1].typeinfo);
	int n=((yyval.typeinfo))->variables.size();
    for(int i=0;i<n;i++){
        int order=(yyval.typeinfo)->decorder1+((yyval.typeinfo)->decorders2)[i];
        string x;
        if(order)
        x="array";
        else
        x="identifier";

        if(((yyval.typeinfo)->initialdecls)[i]){
            insertidentifier((yyval.typeinfo)->variables[i],x,(yyval.typeinfo)->dectype,"",0,order,(yyval.typeinfo)->arrdims[i]);
            cout<<(yyval.typeinfo)->variables[i]<<x<<(yyval.typeinfo)->dectype<<""<<0<<order;
        }
        else{
            vector<int>p(order,0);
            insertidentifier((yyval.typeinfo)->variables[i],x,(yyval.typeinfo)->dectype,"",0,order,p);
            cout<<(yyval.typeinfo)->variables[i]<<x<<(yyval.typeinfo)->dectype<<""<<0<<order;
        }
    }
}
#line 6080 "parser.tab.c"
    break;

  case 455: /* LocalVariableDeclaration: LocalVariableType VariableDeclaratorList  */
#line 923 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->dectype=(yyvsp[-1].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[-1].typeinfo)->decorder1;((yyval.typeinfo))->variables=((yyvsp[0].typeinfo))->variables;(yyval.typeinfo)->decorders2=(yyvsp[0].typeinfo)->decorders2;(yyval.typeinfo)->arrtypes=(yyvsp[0].typeinfo)->arrtypes;(yyval.typeinfo)->arrdims=(yyvsp[0].typeinfo)->arrdims;(yyval.typeinfo)->initvartypes=(yyvsp[0].typeinfo)->initvartypes;for(auto yyy:(yyval.typeinfo)->variables)cout<<yyy<<" ";}
#line 6086 "parser.tab.c"
    break;

  case 456: /* LocalVariableDeclaration: OMClassModifier LocalVariableType VariableDeclaratorList  */
#line 924 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->dectype=(yyvsp[-1].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[-1].typeinfo)->decorder1;((yyval.typeinfo))->variables=((yyvsp[0].typeinfo))->variables;(yyval.typeinfo)->decorders2=(yyvsp[0].typeinfo)->decorders2;(yyval.typeinfo)->arrtypes=(yyvsp[0].typeinfo)->arrtypes;(yyval.typeinfo)->arrdims=(yyvsp[0].typeinfo)->arrdims;(yyval.typeinfo)->initvartypes=(yyvsp[0].typeinfo)->initvartypes;}
#line 6092 "parser.tab.c"
    break;

  case 457: /* LocalVariableType: UnannType  */
#line 926 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type=((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->dectype=(yyvsp[0].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[0].typeinfo)->decorder1;}
#line 6098 "parser.tab.c"
    break;

  case 458: /* LocalVariableType: VAR  */
#line 927 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type="all";(yyval.typeinfo)->dectype="all";(yyval.typeinfo)->decorder1=0;}
#line 6104 "parser.tab.c"
    break;

  case 470: /* $@57: %empty  */
#line 942 "parser.y"
                                        {symtable *a = createscope("statement");insertclass("statement","statement","",a,line); changescope(a);flag = 0;}
#line 6110 "parser.tab.c"
    break;

  case 471: /* StatementWithoutTrailingSubstatement: $@57 Block  */
#line 942 "parser.y"
                                                                                                                                                                        {goparent();}
#line 6116 "parser.tab.c"
    break;

  case 484: /* EmptyStatement: SEMICOLON  */
#line 956 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6122 "parser.tab.c"
    break;

  case 485: /* LabeledStatement: Identifier COLON Statement  */
#line 958 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();}
#line 6128 "parser.tab.c"
    break;

  case 486: /* LabeledStatementNoShortIf: Identifier COLON StatementNoShortIf  */
#line 960 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();}
#line 6134 "parser.tab.c"
    break;

  case 495: /* IfThenStatement: IF LRB Expression RRB Statement  */
#line 973 "parser.y"
                                                                {}
#line 6140 "parser.tab.c"
    break;

  case 496: /* IfThenElseStatement: IF LRB Expression RRB StatementNoShortIf ELSE Statement  */
#line 975 "parser.y"
                                                                              {}
#line 6146 "parser.tab.c"
    break;

  case 497: /* IfThenElseStatementNoShortIf: IF LRB Expression RRB StatementNoShortIf ELSE StatementNoShortIf  */
#line 977 "parser.y"
                                                                                                        {}
#line 6152 "parser.tab.c"
    break;

  case 498: /* AssertStatement: ASSERT Expression SEMICOLON  */
#line 979 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6158 "parser.tab.c"
    break;

  case 499: /* AssertStatement: ASSERT Expression COLON Expression SEMICOLON  */
#line 980 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6164 "parser.tab.c"
    break;

  case 500: /* $@58: %empty  */
#line 982 "parser.y"
                                                   {symtable *a = createscope("switch"); changescope(a);}
#line 6170 "parser.tab.c"
    break;

  case 501: /* SwitchStatement: SWITCH LRB Expression RRB $@58 SwitchBlock  */
#line 982 "parser.y"
                                                                                                                                {goparent();}
#line 6176 "parser.tab.c"
    break;

  case 502: /* SwitchBlock: LCB SwitchRule RCB  */
#line 984 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6182 "parser.tab.c"
    break;

  case 503: /* SwitchBlock: LCB SwitchRule OMSwitchRule RCB  */
#line 985 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6188 "parser.tab.c"
    break;

  case 504: /* SwitchBlock: LCB RCB  */
#line 986 "parser.y"
                                                                                                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6194 "parser.tab.c"
    break;

  case 505: /* SwitchBlock: LCB OMSwitchLabelColon RCB  */
#line 987 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6200 "parser.tab.c"
    break;

  case 506: /* SwitchBlock: LCB OMSwitchBlockStatementGroup RCB  */
#line 988 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6206 "parser.tab.c"
    break;

  case 507: /* SwitchBlock: LCB OMSwitchBlockStatementGroup OMSwitchLabelColon RCB  */
#line 989 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6212 "parser.tab.c"
    break;

  case 513: /* SwitchLabel: CASE CaseConstant  */
#line 998 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6218 "parser.tab.c"
    break;

  case 514: /* SwitchLabel: CASE CaseConstant OMCommaCaseConstant  */
#line 999 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6224 "parser.tab.c"
    break;

  case 515: /* SwitchLabel: DEFAULT  */
#line 1000 "parser.y"
                                                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6230 "parser.tab.c"
    break;

  case 517: /* WhileStatement: WHILE LRB Expression RRB Statement  */
#line 1004 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6236 "parser.tab.c"
    break;

  case 518: /* WhileStatementNoShortIf: WHILE LRB Expression RRB StatementNoShortIf  */
#line 1006 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6242 "parser.tab.c"
    break;

  case 519: /* DoStatement: DO Statement WHILE LRB Expression RRB SEMICOLON  */
#line 1008 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6248 "parser.tab.c"
    break;

  case 524: /* ForSym: FOR  */
#line 1016 "parser.y"
                {symtable*a=createscope("for");insertclass("for","for","",a,line); changescope(a);}
#line 6254 "parser.tab.c"
    break;

  case 525: /* BasicForStatement: ForSym LRB SEMICOLON SEMICOLON RRB Statement  */
#line 1018 "parser.y"
                                                                                {goparent();}
#line 6260 "parser.tab.c"
    break;

  case 526: /* BasicForStatement: ForSym LRB SEMICOLON SEMICOLON ForUpdate RRB Statement  */
#line 1019 "parser.y"
                                                                                                                        {goparent();}
#line 6266 "parser.tab.c"
    break;

  case 527: /* BasicForStatement: ForSym LRB SEMICOLON Expression SEMICOLON RRB Statement  */
#line 1020 "parser.y"
                                                                                                                        {goparent();}
#line 6272 "parser.tab.c"
    break;

  case 528: /* BasicForStatement: ForSym LRB SEMICOLON Expression SEMICOLON ForUpdate RRB Statement  */
#line 1021 "parser.y"
                                                                                                {goparent();}
#line 6278 "parser.tab.c"
    break;

  case 529: /* BasicForStatement: ForSym LRB ForInit SEMICOLON SEMICOLON RRB Statement  */
#line 1022 "parser.y"
                                                                                                                        {goparent();}
#line 6284 "parser.tab.c"
    break;

  case 530: /* BasicForStatement: ForSym LRB ForInit SEMICOLON SEMICOLON ForUpdate RRB Statement  */
#line 1023 "parser.y"
                                                                                                                {goparent();}
#line 6290 "parser.tab.c"
    break;

  case 531: /* BasicForStatement: ForSym LRB ForInit SEMICOLON Expression SEMICOLON RRB Statement  */
#line 1024 "parser.y"
                                                                                                                {goparent();}
#line 6296 "parser.tab.c"
    break;

  case 532: /* BasicForStatement: ForSym LRB ForInit SEMICOLON Expression SEMICOLON ForUpdate RRB Statement  */
#line 1025 "parser.y"
                                                                                                {goparent();}
#line 6302 "parser.tab.c"
    break;

  case 533: /* BasicForStatementNoShortIf: ForSym LRB SEMICOLON SEMICOLON RRB StatementNoShortIf  */
#line 1027 "parser.y"
                                                                                        {goparent();}
#line 6308 "parser.tab.c"
    break;

  case 534: /* BasicForStatementNoShortIf: ForSym LRB SEMICOLON SEMICOLON ForUpdate RRB StatementNoShortIf  */
#line 1028 "parser.y"
                                                                                                                                {goparent();}
#line 6314 "parser.tab.c"
    break;

  case 535: /* BasicForStatementNoShortIf: ForSym LRB SEMICOLON Expression SEMICOLON RRB StatementNoShortIf  */
#line 1029 "parser.y"
                                                                                                                                {goparent();}
#line 6320 "parser.tab.c"
    break;

  case 536: /* BasicForStatementNoShortIf: ForSym LRB SEMICOLON Expression SEMICOLON ForUpdate RRB StatementNoShortIf  */
#line 1030 "parser.y"
                                                                                                                {goparent();}
#line 6326 "parser.tab.c"
    break;

  case 537: /* BasicForStatementNoShortIf: ForSym LRB ForInit SEMICOLON SEMICOLON RRB StatementNoShortIf  */
#line 1031 "parser.y"
                                                                                                                        {goparent();}
#line 6332 "parser.tab.c"
    break;

  case 538: /* BasicForStatementNoShortIf: ForSym LRB ForInit SEMICOLON SEMICOLON ForUpdate RRB StatementNoShortIf  */
#line 1032 "parser.y"
                                                                                                                        {goparent();}
#line 6338 "parser.tab.c"
    break;

  case 539: /* BasicForStatementNoShortIf: ForSym LRB ForInit SEMICOLON Expression SEMICOLON RRB StatementNoShortIf  */
#line 1033 "parser.y"
                                                                                                                        {goparent();}
#line 6344 "parser.tab.c"
    break;

  case 540: /* BasicForStatementNoShortIf: ForSym LRB ForInit SEMICOLON Expression SEMICOLON ForUpdate RRB StatementNoShortIf  */
#line 1034 "parser.y"
                                                                                                        {goparent();}
#line 6350 "parser.tab.c"
    break;

  case 542: /* ForInit: LocalVariableDeclaration  */
#line 1037 "parser.y"
                                                                        {vector<string> a = ((yyvsp[0].typeinfo))->variables; for(auto s : a)insertidentifier(s,((yyvsp[0].typeinfo))->type,"",line);}
#line 6356 "parser.tab.c"
    break;

  case 546: /* EnhancedForStatementSym: ForSym LRB LocalVariableDeclaration  */
#line 1044 "parser.y"
                                                             {vector<string> a = ((yyvsp[0].typeinfo))->variables; for(auto s : a)insertidentifier(s,((yyvsp[0].typeinfo))->type,"",line);}
#line 6362 "parser.tab.c"
    break;

  case 547: /* EnhancedForStatement: EnhancedForStatementSym COLON Expression RRB Statement  */
#line 1046 "parser.y"
                                                                                                {goparent();}
#line 6368 "parser.tab.c"
    break;

  case 548: /* EnhancedForStatementNoShortIf: EnhancedForStatementSym COLON Expression RRB StatementNoShortIf  */
#line 1048 "parser.y"
                                                                                                        {goparent();}
#line 6374 "parser.tab.c"
    break;

  case 549: /* BreakStatement: BREAK SEMICOLON  */
#line 1050 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6380 "parser.tab.c"
    break;

  case 550: /* BreakStatement: BREAK Identifier SEMICOLON  */
#line 1051 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6386 "parser.tab.c"
    break;

  case 551: /* YieldStatement: YIELD Expression SEMICOLON  */
#line 1054 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6392 "parser.tab.c"
    break;

  case 552: /* ContinueStatement: CONTINUE SEMICOLON  */
#line 1056 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6398 "parser.tab.c"
    break;

  case 553: /* ContinueStatement: CONTINUE Identifier SEMICOLON  */
#line 1057 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6404 "parser.tab.c"
    break;

  case 554: /* ReturnStatement: RETURN SEMICOLON  */
#line 1060 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6410 "parser.tab.c"
    break;

  case 555: /* ReturnStatement: RETURN Expression SEMICOLON  */
#line 1061 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6416 "parser.tab.c"
    break;

  case 556: /* ThrowStatement: THROW Expression SEMICOLON  */
#line 1063 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6422 "parser.tab.c"
    break;

  case 557: /* $@59: %empty  */
#line 1065 "parser.y"
                                                         {symtable*a=createscope("synchronized"); changescope(a);}
#line 6428 "parser.tab.c"
    break;

  case 558: /* SynchronizedStatement: SYNCHRONIZED LRB Expression RRB $@59 Block  */
#line 1065 "parser.y"
                                                                                                                                        {goparent();}
#line 6434 "parser.tab.c"
    break;

  case 559: /* TrySym: TRY  */
#line 1067 "parser.y"
            {symtable*a=createscope("try"); changescope(a);}
#line 6440 "parser.tab.c"
    break;

  case 560: /* TryBlockSym: Block  */
#line 1069 "parser.y"
                        {goparent();}
#line 6446 "parser.tab.c"
    break;

  case 567: /* $@60: %empty  */
#line 1079 "parser.y"
                       {symtable*a=createscope("catch"); changescope(a);}
#line 6452 "parser.tab.c"
    break;

  case 568: /* CatchClause: CATCH $@60 LRB CatchFormalParameter RRB Block  */
#line 1079 "parser.y"
                                                                                                                {goparent();}
#line 6458 "parser.tab.c"
    break;

  case 571: /* CatchType: Identifier  */
#line 1084 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6464 "parser.tab.c"
    break;

  case 572: /* CatchType: Identifier OMOrClassType  */
#line 1085 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6470 "parser.tab.c"
    break;

  case 573: /* $@61: %empty  */
#line 1088 "parser.y"
                         {symtable*a=createscope("finally"); changescope(a);}
#line 6476 "parser.tab.c"
    break;

  case 574: /* Finally: FINALLY $@61 Block  */
#line 1088 "parser.y"
                                                                                        {goparent();}
#line 6482 "parser.tab.c"
    break;

  case 579: /* ResourceSpecification: LRB ResourceList RRB  */
#line 1095 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6488 "parser.tab.c"
    break;

  case 584: /* Primary: PrimaryNoNewArray  */
#line 1103 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;vector<int>q;(yyval.typeinfo)->arrdim=q;(yyval.typeinfo)->arrtype="";(yyval.typeinfo)->initvartype=(yyvsp[0].typeinfo)->initvartype;}
#line 6494 "parser.tab.c"
    break;

  case 585: /* Primary: ArrayCreationExpression  */
#line 1104 "parser.y"
                                                                                                                                {(yyval.typeinfo)=createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->initvartype="";}
#line 6500 "parser.tab.c"
    break;

  case 586: /* PrimaryNoNewArray: Literal  */
#line 1106 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;(yyval.typeinfo)->initvartype=(yyvsp[0].typeinfo)->type;((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6506 "parser.tab.c"
    break;

  case 587: /* PrimaryNoNewArray: ClassLiteral  */
#line 1107 "parser.y"
                                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6512 "parser.tab.c"
    break;

  case 588: /* PrimaryNoNewArray: THIS  */
#line 1108 "parser.y"
                                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class";}
#line 6518 "parser.tab.c"
    break;

  case 589: /* PrimaryNoNewArray: Identifier DOT THIS  */
#line 1109 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class";}
#line 6524 "parser.tab.c"
    break;

  case 590: /* PrimaryNoNewArray: ExpressionName DOT THIS  */
#line 1110 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class";}
#line 6530 "parser.tab.c"
    break;

  case 591: /* PrimaryNoNewArray: LRB Expression RRB  */
#line 1111 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;}
#line 6536 "parser.tab.c"
    break;

  case 592: /* PrimaryNoNewArray: ClassInstanceCreationExpression  */
#line 1112 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6542 "parser.tab.c"
    break;

  case 593: /* PrimaryNoNewArray: FieldAccess  */
#line 1113 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "look";}
#line 6548 "parser.tab.c"
    break;

  case 594: /* PrimaryNoNewArray: ArrayAccess  */
#line 1114 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6554 "parser.tab.c"
    break;

  case 595: /* PrimaryNoNewArray: MethodInvocation  */
#line 1115 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6560 "parser.tab.c"
    break;

  case 596: /* PrimaryNoNewArray: MethodReference  */
#line 1116 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "look";}
#line 6566 "parser.tab.c"
    break;

  case 597: /* ClassLiteral: Identifier DOT CLASS  */
#line 1118 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class";}
#line 6572 "parser.tab.c"
    break;

  case 598: /* ClassLiteral: ExpressionName DOT CLASS  */
#line 1119 "parser.y"
                                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class";}
#line 6578 "parser.tab.c"
    break;

  case 599: /* ClassLiteral: Identifier OMPSB DOT CLASS  */
#line 1120 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class";}
#line 6584 "parser.tab.c"
    break;

  case 600: /* ClassLiteral: ExpressionName OMPSB DOT CLASS  */
#line 1121 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class";}
#line 6590 "parser.tab.c"
    break;

  case 601: /* ClassLiteral: UnannPrimitiveType DOT CLASS  */
#line 1122 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class";}
#line 6596 "parser.tab.c"
    break;

  case 602: /* ClassLiteral: VOID DOT CLASS  */
#line 1123 "parser.y"
                                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class";}
#line 6602 "parser.tab.c"
    break;

  case 603: /* ClassInstanceCreationExpression: UnqualifiedClassInstanceCreationExpression  */
#line 1125 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6608 "parser.tab.c"
    break;

  case 604: /* ClassInstanceCreationExpression: Identifier DOT UnqualifiedClassInstanceCreationExpression  */
#line 1126 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6614 "parser.tab.c"
    break;

  case 605: /* ClassInstanceCreationExpression: ExpressionName DOT UnqualifiedClassInstanceCreationExpression  */
#line 1127 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6620 "parser.tab.c"
    break;

  case 606: /* ClassInstanceCreationExpression: Primary DOT UnqualifiedClassInstanceCreationExpression  */
#line 1128 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6626 "parser.tab.c"
    break;

  case 607: /* UnqualifiedClassInstanceCreationExpression: NEW ClassOrInterfaceTypeToInstantiate LRB RRB  */
#line 1130 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;}
#line 6632 "parser.tab.c"
    break;

  case 608: /* UnqualifiedClassInstanceCreationExpression: NEW ClassOrInterfaceTypeToInstantiate LRB RRB ClassBody  */
#line 1131 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-3].typeinfo))->type;}
#line 6638 "parser.tab.c"
    break;

  case 609: /* UnqualifiedClassInstanceCreationExpression: NEW ClassOrInterfaceTypeToInstantiate LRB ArgumentList RRB  */
#line 1132 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-3].typeinfo))->type;}
#line 6644 "parser.tab.c"
    break;

  case 610: /* UnqualifiedClassInstanceCreationExpression: NEW ClassOrInterfaceTypeToInstantiate LRB ArgumentList RRB ClassBody  */
#line 1133 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-4].typeinfo))->type;}
#line 6650 "parser.tab.c"
    break;

  case 611: /* ClassOrInterfaceTypeToInstantiate: Identifier  */
#line 1135 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();string p = (yyvsp[0].str);if(lookup(p)){((yyval.typeinfo))->type =  lookup(p)->funcrettype ;}}
#line 6656 "parser.tab.c"
    break;

  case 612: /* ClassOrInterfaceTypeToInstantiate: Identifier OMDotIdentifier  */
#line 1136 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();string p = (yyvsp[-1].str);if(lookup(p + ((yyvsp[0].typeinfo))->name)){((yyval.typeinfo))->type =  lookup(p + ((yyvsp[0].typeinfo))->name)->funcrettype ;}}
#line 6662 "parser.tab.c"
    break;

  case 614: /* FieldAccess: SUPER DOT Identifier  */
#line 1139 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6668 "parser.tab.c"
    break;

  case 615: /* FieldAccess: Identifier DOT SUPER DOT Identifier  */
#line 1140 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6674 "parser.tab.c"
    break;

  case 617: /* ArrayAccess: Identifier LSB Expression RSB  */
#line 1143 "parser.y"
                                                                {(yyval.typeinfo) = createstruct();string p = (yyvsp[-3].str);if(lookup(p)){((yyval.typeinfo))->type =  lookup(p)->type ;}}
#line 6680 "parser.tab.c"
    break;

  case 620: /* MethodInvocation: MethodName LRB ArgumentList RRB  */
#line 1147 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();if(lookup(((yyvsp[-3].typeinfo))->name)){((yyval.typeinfo))->type =  lookup(((yyvsp[-3].typeinfo))->name)->funcrettype ;}}
#line 6686 "parser.tab.c"
    break;

  case 621: /* MethodInvocation: MethodName LRB RRB  */
#line 1148 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();if(lookup(((yyvsp[-2].typeinfo))->name)){((yyval.typeinfo))->type =  lookup(((yyvsp[-2].typeinfo))->name)->funcrettype ;}}
#line 6692 "parser.tab.c"
    break;

  case 622: /* MethodInvocation: Identifier DOT Identifier LRB RRB  */
#line 1149 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6698 "parser.tab.c"
    break;

  case 623: /* MethodInvocation: Identifier DOT Identifier LRB ArgumentList RRB  */
#line 1150 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6704 "parser.tab.c"
    break;

  case 628: /* MethodInvocation: SUPER DOT Identifier LRB RRB  */
#line 1155 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6710 "parser.tab.c"
    break;

  case 629: /* MethodInvocation: SUPER DOT Identifier LRB ArgumentList RRB  */
#line 1156 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6716 "parser.tab.c"
    break;

  case 630: /* MethodInvocation: Identifier DOT SUPER DOT Identifier LRB RRB  */
#line 1157 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6722 "parser.tab.c"
    break;

  case 631: /* MethodInvocation: Identifier DOT SUPER DOT Identifier LRB ArgumentList RRB  */
#line 1158 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6728 "parser.tab.c"
    break;

  case 636: /* MethodReference: Identifier DOUBLECOLON Identifier  */
#line 1166 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();}
#line 6734 "parser.tab.c"
    break;

  case 640: /* MethodReference: SUPER DOUBLECOLON Identifier  */
#line 1170 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6740 "parser.tab.c"
    break;

  case 641: /* MethodReference: Identifier DOT SUPER DOUBLECOLON Identifier  */
#line 1171 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6746 "parser.tab.c"
    break;

  case 644: /* ArrayCreationExpression: NEW PrimitiveType OMDimExpr  */
#line 1175 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->type=(yyvsp[-1].typeinfo)->type;(yyval.typeinfo)->arrtype=(yyvsp[-1].typeinfo)->type;(yyval.typeinfo)->arrdim=(yyvsp[0].typeinfo)->arrdim;cout<<"hi";for(auto z:(yyvsp[0].typeinfo)->arrdim)cout<<z<<"  ";}
#line 6752 "parser.tab.c"
    break;

  case 645: /* ArrayCreationExpression: NEW PrimitiveType OMDimExpr OMPSB  */
#line 1176 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6758 "parser.tab.c"
    break;

  case 646: /* ArrayCreationExpression: NEW Identifier OMDimExpr  */
#line 1177 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6764 "parser.tab.c"
    break;

  case 647: /* ArrayCreationExpression: NEW Identifier OMDimExpr OMPSB  */
#line 1178 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 6770 "parser.tab.c"
    break;

  case 648: /* ArrayCreationExpression: NEW PrimitiveType OMPSB ArrayInitializer  */
#line 1179 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6776 "parser.tab.c"
    break;

  case 649: /* ArrayCreationExpression: NEW Identifier OMPSB ArrayInitializer  */
#line 1180 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();}
#line 6782 "parser.tab.c"
    break;

  case 650: /* DimExpr: LSB Expression RSB  */
#line 1183 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();if((yyvsp[-1].typeinfo)->type!="int")cout<<"error coz of nonint array para";(yyval.typeinfo)->exprvalue=(yyvsp[-1].typeinfo)->exprvalue;(yyval.typeinfo)->type=(yyvsp[-1].typeinfo)->type;}
#line 6788 "parser.tab.c"
    break;

  case 651: /* Expression: AssignmentExpression  */
#line 1185 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 6794 "parser.tab.c"
    break;

  case 652: /* AssignmentExpression: ConditionalExpression  */
#line 1187 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 6800 "parser.tab.c"
    break;

  case 653: /* AssignmentExpression: Assignment  */
#line 1188 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6806 "parser.tab.c"
    break;

  case 654: /* Assignment: LeftHandSide AssignmentOperator Expression  */
#line 1190 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6812 "parser.tab.c"
    break;

  case 656: /* LeftHandSide: Identifier  */
#line 1193 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();string p = (yyvsp[0].str);if(lookup(p)){((yyval.typeinfo))->type = lookup(p)->type;}}
#line 6818 "parser.tab.c"
    break;

  case 658: /* LeftHandSide: ArrayAccess  */
#line 1195 "parser.y"
                                                                                                        {((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6824 "parser.tab.c"
    break;

  case 660: /* ConditionalExpression: ConditionalOrExpression  */
#line 1199 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 6830 "parser.tab.c"
    break;

  case 661: /* ConditionalExpression: ConditionalOrExpression QM Expression COLON ConditionalExpression  */
#line 1200 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-4].typeinfo))->type,"boolean",line);type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = ((yyvsp[-4].typeinfo))->type;}
#line 6836 "parser.tab.c"
    break;

  case 662: /* ConditionalOrExpression: ConditionalAndExpression  */
#line 1202 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6842 "parser.tab.c"
    break;

  case 663: /* ConditionalOrExpression: ConditionalOrExpression OR ConditionalAndExpression  */
#line 1203 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = "boolean";}
#line 6848 "parser.tab.c"
    break;

  case 664: /* ConditionalAndExpression: InclusiveOrExpression  */
#line 1205 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6854 "parser.tab.c"
    break;

  case 665: /* ConditionalAndExpression: ConditionalAndExpression AND InclusiveOrExpression  */
#line 1206 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = "boolean";}
#line 6860 "parser.tab.c"
    break;

  case 666: /* InclusiveOrExpression: ExclusiveOrExpression  */
#line 1208 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6866 "parser.tab.c"
    break;

  case 667: /* InclusiveOrExpression: InclusiveOrExpression BITOR ExclusiveOrExpression  */
#line 1209 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;}
#line 6872 "parser.tab.c"
    break;

  case 668: /* ExclusiveOrExpression: AndExpression  */
#line 1211 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6878 "parser.tab.c"
    break;

  case 669: /* ExclusiveOrExpression: ExclusiveOrExpression BITXOR AndExpression  */
#line 1212 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;}
#line 6884 "parser.tab.c"
    break;

  case 670: /* AndExpression: EqualityExpression  */
#line 1214 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6890 "parser.tab.c"
    break;

  case 671: /* AndExpression: AndExpression BITAND EqualityExpression  */
#line 1215 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;}
#line 6896 "parser.tab.c"
    break;

  case 672: /* EqualityExpression: RelationalExpression  */
#line 1217 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6902 "parser.tab.c"
    break;

  case 673: /* EqualityExpression: EqualityExpression DOUBLEEQUAL RelationalExpression  */
#line 1218 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = "boolean";}
#line 6908 "parser.tab.c"
    break;

  case 674: /* EqualityExpression: EqualityExpression NE RelationalExpression  */
#line 1219 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = "boolean";}
#line 6914 "parser.tab.c"
    break;

  case 675: /* RelationalExpression: ShiftExpression  */
#line 1221 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6920 "parser.tab.c"
    break;

  case 676: /* RelationalExpression: RelationalExpression LT ShiftExpression  */
#line 1222 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = "boolean";}
#line 6926 "parser.tab.c"
    break;

  case 677: /* RelationalExpression: RelationalExpression GT ShiftExpression  */
#line 1223 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = "boolean";}
#line 6932 "parser.tab.c"
    break;

  case 678: /* RelationalExpression: RelationalExpression LTE ShiftExpression  */
#line 1224 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = "boolean";}
#line 6938 "parser.tab.c"
    break;

  case 679: /* RelationalExpression: RelationalExpression GTE ShiftExpression  */
#line 1225 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = "boolean";}
#line 6944 "parser.tab.c"
    break;

  case 680: /* RelationalExpression: InstanceofExpression  */
#line 1226 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6950 "parser.tab.c"
    break;

  case 681: /* InstanceofExpression: RelationalExpression INSTANCEOF ReferenceType  */
#line 1228 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;}
#line 6956 "parser.tab.c"
    break;

  case 682: /* ShiftExpression: AdditiveExpression  */
#line 1230 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6962 "parser.tab.c"
    break;

  case 683: /* ShiftExpression: ShiftExpression LSHIFT AdditiveExpression  */
#line 1231 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;}
#line 6968 "parser.tab.c"
    break;

  case 684: /* ShiftExpression: ShiftExpression RSHIFT AdditiveExpression  */
#line 1232 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;}
#line 6974 "parser.tab.c"
    break;

  case 685: /* ShiftExpression: ShiftExpression THREEGT AdditiveExpression  */
#line 1233 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;}
#line 6980 "parser.tab.c"
    break;

  case 686: /* AdditiveExpression: MultiplicativeExpression  */
#line 1235 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 6986 "parser.tab.c"
    break;

  case 687: /* AdditiveExpression: AdditiveExpression PLUS MultiplicativeExpression  */
#line 1236 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);}
#line 6992 "parser.tab.c"
    break;

  case 688: /* AdditiveExpression: AdditiveExpression MINUS MultiplicativeExpression  */
#line 1237 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);}
#line 6998 "parser.tab.c"
    break;

  case 689: /* MultiplicativeExpression: UnaryExpression  */
#line 1239 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 7004 "parser.tab.c"
    break;

  case 690: /* MultiplicativeExpression: MultiplicativeExpression MULTIPLY UnaryExpression  */
#line 1240 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);}
#line 7010 "parser.tab.c"
    break;

  case 691: /* MultiplicativeExpression: MultiplicativeExpression DIVIDE UnaryExpression  */
#line 1241 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);}
#line 7016 "parser.tab.c"
    break;

  case 692: /* MultiplicativeExpression: MultiplicativeExpression PERCENT UnaryExpression  */
#line 1242 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);}
#line 7022 "parser.tab.c"
    break;

  case 693: /* UnaryExpression: PreIncrementExpression  */
#line 1244 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 7028 "parser.tab.c"
    break;

  case 694: /* UnaryExpression: PreDecrementExpression  */
#line 1245 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 7034 "parser.tab.c"
    break;

  case 695: /* UnaryExpression: PLUS UnaryExpression  */
#line 1246 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 7040 "parser.tab.c"
    break;

  case 696: /* UnaryExpression: MINUS UnaryExpression  */
#line 1247 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 7046 "parser.tab.c"
    break;

  case 697: /* UnaryExpression: UnaryExpressionNotPlusMinus  */
#line 1248 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 7052 "parser.tab.c"
    break;

  case 698: /* PreIncrementExpression: INCREAMENT UnaryExpression  */
#line 1250 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 7058 "parser.tab.c"
    break;

  case 699: /* PreDecrementExpression: DECREAMENT UnaryExpression  */
#line 1252 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 7064 "parser.tab.c"
    break;

  case 700: /* UnaryExpressionNotPlusMinus: PostfixExpression  */
#line 1254 "parser.y"
                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 7070 "parser.tab.c"
    break;

  case 701: /* UnaryExpressionNotPlusMinus: TILDA UnaryExpression  */
#line 1255 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 7076 "parser.tab.c"
    break;

  case 702: /* UnaryExpressionNotPlusMinus: EXCLAM UnaryExpression  */
#line 1256 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 7082 "parser.tab.c"
    break;

  case 703: /* UnaryExpressionNotPlusMinus: CastExpression  */
#line 1257 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 7088 "parser.tab.c"
    break;

  case 704: /* UnaryExpressionNotPlusMinus: SwitchExpression  */
#line 1258 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 7094 "parser.tab.c"
    break;

  case 705: /* PostfixExpression: Primary  */
#line 1260 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 7100 "parser.tab.c"
    break;

  case 706: /* PostfixExpression: Identifier  */
#line 1261 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();string p = (yyvsp[0].str);symentry*s=lookup(p); if(lookup(p)){((yyval.typeinfo))->type = s->type;(yyval.typeinfo)->order=s->order;(yyval.typeinfo)->exprvalue=s->exprvalue;}}
#line 7106 "parser.tab.c"
    break;

  case 707: /* PostfixExpression: ExpressionName  */
#line 1262 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 7112 "parser.tab.c"
    break;

  case 708: /* PostfixExpression: PostIncrementExpression  */
#line 1263 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 7118 "parser.tab.c"
    break;

  case 709: /* PostfixExpression: PostDecrementExpression  */
#line 1264 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 7124 "parser.tab.c"
    break;

  case 710: /* PostIncrementExpression: PostfixExpression INCREAMENT  */
#line 1266 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;}
#line 7130 "parser.tab.c"
    break;

  case 711: /* PostDecrementExpression: PostfixExpression DECREAMENT  */
#line 1268 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;}
#line 7136 "parser.tab.c"
    break;

  case 712: /* CastExpression: LRB PrimitiveType RRB UnaryExpression  */
#line 1270 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type; ((yyvsp[0].typeinfo))->type = ((yyvsp[-2].typeinfo))->type; type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);}
#line 7142 "parser.tab.c"
    break;

  case 713: /* CastExpression: LRB UnannArrayType RRB UnaryExpressionNotPlusMinus  */
#line 1271 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type; ((yyvsp[0].typeinfo))->type = ((yyvsp[-2].typeinfo))->type; type_check(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);}
#line 7148 "parser.tab.c"
    break;

  case 714: /* CastExpression: LRB UnannArrayType OMAdditionalBound RRB UnaryExpressionNotPlusMinus  */
#line 1272 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-3].typeinfo))->type; ((yyvsp[0].typeinfo))->type = ((yyvsp[-3].typeinfo))->type; type_check(((yyvsp[-3].typeinfo))->type,((yyvsp[0].typeinfo))->type,line);}
#line 7154 "parser.tab.c"
    break;

  case 715: /* $@62: %empty  */
#line 1274 "parser.y"
                                                   {symtable *a = createscope("switch"); changescope(a);}
#line 7160 "parser.tab.c"
    break;

  case 716: /* SwitchExpression: SWITCH LRB Expression RRB $@62 SwitchBlock  */
#line 1274 "parser.y"
                                                                                                                                        {goparent();((yyval.typeinfo))->type = "switch";}
#line 7166 "parser.tab.c"
    break;

  case 717: /* VariableAccess: ExpressionName  */
#line 1276 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 7172 "parser.tab.c"
    break;

  case 718: /* VariableAccess: Identifier  */
#line 1277 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();}
#line 7178 "parser.tab.c"
    break;


#line 7182 "parser.tab.c"

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

#line 1281 "parser.y"

// bool visited[100000]={false};

int main(int argc,char*argv[]){


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
            cout<<"Use following commands\n";
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
		
	if(yyin == NULL){
		cerr<<"Error: cannot open file "<<argv[inputindex]<<"\n";
	}
    if(verbose)
    {
        cout<<"Parse started\n";
        cout<<"Parsing file.....\n";
    }




	curr=new symtable;
	curr->scope = "global";
	queue<symtable*>q;
	q.push(curr);
	yyparse();
	    if(verbose){
        cout<<"Parsing finished\n";
    }
	ofstream csvFile("symboltable.csv");
	csvFile << "Name, Type, Line number, Function Input Type, Function Output Type, Size, Scope" << "\n";
	// dfs(curr);
	while(!q.empty()){
		symtable* c=q.front();
		if(c)
		// prints(c);
		// for(auto z:c->m){
		// 	csvFile<<z.first<<","<<z.second->type<<","<<z.second->linenumber<<","<<z.second->argcon<<","<<z.second->funcrettype<<","<<z.second->size<<","<<z.second->scope<<"\n";
		// }
        for(auto z:c->m){
			csvFile<<z.first<<","<<z.second->type<<","<<z.second->primtype<<","<<"arraysize:";
			for(auto y:z.second->arrdims)
			csvFile<<y<<"x";
			csvFile<<"\n";
		}
		q.pop();
		vector<symtable*>v=c->childscope;
		for(auto s:v)
		if(s){
			q.push(s);

		}
	}


}
void yyerror (const char *s) {cerr<<"Error on Line "<<line<<endl;}
