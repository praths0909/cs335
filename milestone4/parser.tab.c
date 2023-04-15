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

#include<bits/stdc++.h>
using namespace std;

#define YYERROR_VERBOSE

void yyerror (const char *s);
FILE* dotfile;
extern long long int line;
extern int yylex();
extern int yyrestart(FILE*);
extern FILE* yyin;
ofstream code("TAC.txt");
ofstream csvFile("symboltable.csv");

stack<string> currmethod;
stack<stack<string>> currmethodlocals;
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
int tempvariables=0;
int labelvariable=0;

string newtemp(){
	tempvariables++;
	return "t"+to_string(tempvariables);
}
string newlabel(){
	labelvariable++;
	return "LABEL"+to_string(labelvariable);
}
string gotolabel(int labelvariable){
	return " go to LABEL"+to_string(labelvariable);
}
string gotoo(int p){
    return " go to LABEL"+to_string(p);
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

string newmethodlabel(string i){
	stack<string> st;
	currmethodlocals.push(st);
	currmethod.push(i);
	return i+":";
}
string newmethodretlabel(string i){
	return i+"ret:";
}
string gotomethod(string i){
	return "go to " + i+":";
}
string gotomethodretlabel(string i){
	return "go to " + i+"ret:";
}
vector<string> pusharg(vector<string> s){
	vector<string> r;
	for(auto k:s){
		string temp = "pushparam " + k;
		r.push_back(temp);
	}
	return r;
}
vector<string> pushlocal(vector<string> s){
	vector<string> r;
	for(auto k:s){
		string temp = "pushlocal " + k;
		currmethodlocals.top().push(k);
		r.push_back(temp);
	}
	return r;
}
vector<string> poplocal(stack<string> s){
	vector<string> r;
	while(!s.empty()){
		string temp = "poplocal " + s.top();
		s.pop();
		r.push_back(temp);
	}
	return r;
}
vector<string> pushregisters(){
	vector<string> r;
		string temp = "push ";
		temp = temp + "%rbp";
		r.push_back(temp);
		temp = "push ";
		temp = temp + "%rbx";
		r.push_back(temp);
		temp = "push ";
		temp = temp + "%rsp";
		r.push_back(temp);
		temp = "push ";
		temp = temp + "%r12";
		r.push_back(temp);
		temp = "push ";
		temp = temp + "%r13";
		r.push_back(temp);
		temp = "push ";
		temp = temp + "%r14";
		r.push_back(temp);
		temp = "push ";
		temp = temp + "%r15";
		r.push_back(temp);
	return r;
}
vector<string> popregisters(){
	vector<string> r;
		string temp = "pop " ;
		temp = temp + "%r15";
		r.push_back(temp);
		temp = "pop " ;
		temp = temp + "%r14";
		r.push_back(temp);
		temp = "pop " ;
		temp = temp + "%r13";
		r.push_back(temp);
		temp = "pop " ;
		temp = temp + "%r12";
		r.push_back(temp);
		temp = "pop " ;
		temp = temp + "%rsp";
		r.push_back(temp);
		temp = "pop " ;
		temp = temp + "%rax";
		r.push_back(temp);
		temp = "pop " ;
		temp = temp + "%rbp";
		r.push_back(temp);
	return r;
} 
int tellsize(vector<int>a,string p){
	int pr=1;
	for(auto x:a){
		pr=pr*x;
	}
	return pr*sizeoftype(p);
}

int offsetcalcid(string type,int order,vector<int>dims){
    int p=sizeof(type);
    int product=1;
    for(auto x:dims)
    product*=x;
    if(order)
    return p*product;
    else
    return p;
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

vector<string> concvector(vector<string> p1,string a,string b,vector<string> p2){
	vector<string>s = p1;
	s.push_back(a);
	s.push_back(b);
    for(auto z:p2)
	s.push_back(z);
	return s;
}
vector<string> concvector(vector<string> p1,vector<string>&va,vector<string>&vb,string a,vector<string>&vc,string b,vector<string> p2){
	vector<string>s = p1;
    for(auto z:va)
	s.push_back(z);
    for(auto z:vb)
	s.push_back(z);
	s.push_back(a);
    for(auto z:vc)
	s.push_back(z);
	s.push_back(b);
    for(auto z:p2)
	s.push_back(z);
	return s;
}
vector<string> concvector(vector<string>&va,vector<string>&vb,vector<string>&vd,string a,string b,vector<string>&vc){
	vector<string>s=va;
    for(auto z:vb)
	s.push_back(z);
    for(auto z:vd)
	s.push_back(z);
	s.push_back(a);
	s.push_back(b);
    for(auto z:vc)
	s.push_back(z);
	return s;
}
vector<string> concvector(vector<string>&va,string a,string b){
	vector<string>s=va;
	s.push_back(a);
	s.push_back(b);
	return s;
}
vector<string> concvector(vector<string>&va,vector<string>&vb,string a,vector<string>&vc,string b){
	vector<string>s=va;
		for(auto z:vb)
	s.push_back(z);
	s.push_back(a);
		for(auto z:vc)
	s.push_back(z);
	s.push_back(b);
	return s;
}
////////////////////////////
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
vector<string> concvector(vector<string>&va,vector<string>&vb,string a,string b){
    vector<string>ret;
    for(auto z:va)
    ret.push_back(z);
	for(auto z:vb)
    ret.push_back(z);
    ret.push_back(a);
    ret.push_back(b);
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
string golabel(int p){
    string q=to_string(p);
    string a=" go to LABEL"+q;
    return a;
}
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

void insertidentifier(string lexeme,string type,string modifier,int linen)
{
    symentry *a = new symentry;
		
    curr->m[lexeme] = a;
    a->lexeme=lexeme;
    a->type=type;
    a->modifier=modifier;
		a->scope=curr->scope;
		a->linenumber = linen;
		a->size=sizeoftype(type);
		
		
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


    vector<string>tac;
    string tempname;
    string arrname;
    vector<int>dimsize;


    vector<string>puvariables; //for variable declator list
	vector<string>params; 



    int valint;
    float valfloat;
    string valstr;
    char valchar;
    bool valbool;
    string littype;
    string exprtype;
};
int flag = 0;
Typeinfo *createstruct(){
	Typeinfo * t = new Typeinfo;
	return t;
};

#line 817 "parser.tab.c"

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
  YYSYMBOL_OMCommaEnumConstant = 144,      /* OMCommaEnumConstant  */
  YYSYMBOL_CommaEnumConstant = 145,        /* CommaEnumConstant  */
  YYSYMBOL_OMCommaRecordComponent = 146,   /* OMCommaRecordComponent  */
  YYSYMBOL_CommaRecordComponent = 147,     /* CommaRecordComponent  */
  YYSYMBOL_OMRecordBodyDeclaration = 148,  /* OMRecordBodyDeclaration  */
  YYSYMBOL_OMInterfaceMemberDeclaration = 149, /* OMInterfaceMemberDeclaration  */
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
  YYSYMBOL_EnumDeclaration = 273,          /* EnumDeclaration  */
  YYSYMBOL_EnumBody = 274,                 /* EnumBody  */
  YYSYMBOL_EnumConstantList = 275,         /* EnumConstantList  */
  YYSYMBOL_PRB = 276,                      /* PRB  */
  YYSYMBOL_PRBArgumentList = 277,          /* PRBArgumentList  */
  YYSYMBOL_EnumConstant = 278,             /* EnumConstant  */
  YYSYMBOL_EnumBodyDeclarations = 279,     /* EnumBodyDeclarations  */
  YYSYMBOL_RecordDeclarationSym = 280,     /* RecordDeclarationSym  */
  YYSYMBOL_RecordDeclaration = 281,        /* RecordDeclaration  */
  YYSYMBOL_RecordHeader = 282,             /* RecordHeader  */
  YYSYMBOL_RecordComponentList = 283,      /* RecordComponentList  */
  YYSYMBOL_RecordComponent = 284,          /* RecordComponent  */
  YYSYMBOL_VariableArityRecordComponent = 285, /* VariableArityRecordComponent  */
  YYSYMBOL_RecordBody = 286,               /* RecordBody  */
  YYSYMBOL_RecordBodyDeclaration = 287,    /* RecordBodyDeclaration  */
  YYSYMBOL_CompactConstructorDeclarationSym = 288, /* CompactConstructorDeclarationSym  */
  YYSYMBOL_CompactConstructorDeclaration = 289, /* CompactConstructorDeclaration  */
  YYSYMBOL_InterfaceDeclaration = 290,     /* InterfaceDeclaration  */
  YYSYMBOL_NormalInterfaceDeclaration = 291, /* NormalInterfaceDeclaration  */
  YYSYMBOL_292_41 = 292,                   /* $@41  */
  YYSYMBOL_293_42 = 293,                   /* $@42  */
  YYSYMBOL_294_43 = 294,                   /* $@43  */
  YYSYMBOL_295_44 = 295,                   /* $@44  */
  YYSYMBOL_296_45 = 296,                   /* $@45  */
  YYSYMBOL_297_46 = 297,                   /* $@46  */
  YYSYMBOL_298_47 = 298,                   /* $@47  */
  YYSYMBOL_299_48 = 299,                   /* $@48  */
  YYSYMBOL_300_49 = 300,                   /* $@49  */
  YYSYMBOL_301_50 = 301,                   /* $@50  */
  YYSYMBOL_302_51 = 302,                   /* $@51  */
  YYSYMBOL_303_52 = 303,                   /* $@52  */
  YYSYMBOL_304_53 = 304,                   /* $@53  */
  YYSYMBOL_305_54 = 305,                   /* $@54  */
  YYSYMBOL_306_55 = 306,                   /* $@55  */
  YYSYMBOL_307_56 = 307,                   /* $@56  */
  YYSYMBOL_InterfaceModifier = 308,        /* InterfaceModifier  */
  YYSYMBOL_InterfaceExtends = 309,         /* InterfaceExtends  */
  YYSYMBOL_InterfacePermits = 310,         /* InterfacePermits  */
  YYSYMBOL_InterfaceBody = 311,            /* InterfaceBody  */
  YYSYMBOL_InterfaceMemberDeclaration = 312, /* InterfaceMemberDeclaration  */
  YYSYMBOL_ConstantDeclaration = 313,      /* ConstantDeclaration  */
  YYSYMBOL_InterfaceMethodDeclaration = 314, /* InterfaceMethodDeclaration  */
  YYSYMBOL_ArrayInitializer = 315,         /* ArrayInitializer  */
  YYSYMBOL_VariableInitializerList = 316,  /* VariableInitializerList  */
  YYSYMBOL_Block = 317,                    /* Block  */
  YYSYMBOL_BlockStatements = 318,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 319,           /* BlockStatement  */
  YYSYMBOL_LocalClassOrInterfaceDeclaration = 320, /* LocalClassOrInterfaceDeclaration  */
  YYSYMBOL_LocalVariableDeclarationStatement = 321, /* LocalVariableDeclarationStatement  */
  YYSYMBOL_LocalVariableDeclaration = 322, /* LocalVariableDeclaration  */
  YYSYMBOL_LocalVariableType = 323,        /* LocalVariableType  */
  YYSYMBOL_Statement = 324,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 325,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 326, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_327_57 = 327,                   /* $@57  */
  YYSYMBOL_EmptyStatement = 328,           /* EmptyStatement  */
  YYSYMBOL_LabeledStatement = 329,         /* LabeledStatement  */
  YYSYMBOL_LabeledStatementNoShortIf = 330, /* LabeledStatementNoShortIf  */
  YYSYMBOL_ExpressionStatement = 331,      /* ExpressionStatement  */
  YYSYMBOL_StatementExpression = 332,      /* StatementExpression  */
  YYSYMBOL_IfThenStatement = 333,          /* IfThenStatement  */
  YYSYMBOL_IfThenElseStatement = 334,      /* IfThenElseStatement  */
  YYSYMBOL_IfThenElseStatementNoShortIf = 335, /* IfThenElseStatementNoShortIf  */
  YYSYMBOL_AssertStatement = 336,          /* AssertStatement  */
  YYSYMBOL_SwitchStatement = 337,          /* SwitchStatement  */
  YYSYMBOL_338_58 = 338,                   /* $@58  */
  YYSYMBOL_SwitchBlock = 339,              /* SwitchBlock  */
  YYSYMBOL_SwitchRule = 340,               /* SwitchRule  */
  YYSYMBOL_SwitchBlockStatementGroup = 341, /* SwitchBlockStatementGroup  */
  YYSYMBOL_SwitchLabel = 342,              /* SwitchLabel  */
  YYSYMBOL_CaseConstant = 343,             /* CaseConstant  */
  YYSYMBOL_WhileStatement = 344,           /* WhileStatement  */
  YYSYMBOL_WhileStatementNoShortIf = 345,  /* WhileStatementNoShortIf  */
  YYSYMBOL_DoStatement = 346,              /* DoStatement  */
  YYSYMBOL_ForStatement = 347,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 348,    /* ForStatementNoShortIf  */
  YYSYMBOL_ForSym = 349,                   /* ForSym  */
  YYSYMBOL_BasicForStatement = 350,        /* BasicForStatement  */
  YYSYMBOL_BasicForStatementNoShortIf = 351, /* BasicForStatementNoShortIf  */
  YYSYMBOL_ForInit = 352,                  /* ForInit  */
  YYSYMBOL_ForUpdate = 353,                /* ForUpdate  */
  YYSYMBOL_StatementExpressionList = 354,  /* StatementExpressionList  */
  YYSYMBOL_EnhancedForStatementSym = 355,  /* EnhancedForStatementSym  */
  YYSYMBOL_EnhancedForStatement = 356,     /* EnhancedForStatement  */
  YYSYMBOL_EnhancedForStatementNoShortIf = 357, /* EnhancedForStatementNoShortIf  */
  YYSYMBOL_BreakStatement = 358,           /* BreakStatement  */
  YYSYMBOL_YieldStatement = 359,           /* YieldStatement  */
  YYSYMBOL_ContinueStatement = 360,        /* ContinueStatement  */
  YYSYMBOL_ReturnStatement = 361,          /* ReturnStatement  */
  YYSYMBOL_ThrowStatement = 362,           /* ThrowStatement  */
  YYSYMBOL_SynchronizedStatement = 363,    /* SynchronizedStatement  */
  YYSYMBOL_364_59 = 364,                   /* $@59  */
  YYSYMBOL_TrySym = 365,                   /* TrySym  */
  YYSYMBOL_TryBlockSym = 366,              /* TryBlockSym  */
  YYSYMBOL_TryStatement = 367,             /* TryStatement  */
  YYSYMBOL_Catches = 368,                  /* Catches  */
  YYSYMBOL_CatchClause = 369,              /* CatchClause  */
  YYSYMBOL_370_60 = 370,                   /* $@60  */
  YYSYMBOL_CatchFormalParameter = 371,     /* CatchFormalParameter  */
  YYSYMBOL_CatchType = 372,                /* CatchType  */
  YYSYMBOL_Finally = 373,                  /* Finally  */
  YYSYMBOL_374_61 = 374,                   /* $@61  */
  YYSYMBOL_TryWithResourcesStatement = 375, /* TryWithResourcesStatement  */
  YYSYMBOL_ResourceSpecification = 376,    /* ResourceSpecification  */
  YYSYMBOL_ResourceList = 377,             /* ResourceList  */
  YYSYMBOL_Resource = 378,                 /* Resource  */
  YYSYMBOL_Primary = 379,                  /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 380,        /* PrimaryNoNewArray  */
  YYSYMBOL_ClassLiteral = 381,             /* ClassLiteral  */
  YYSYMBOL_ClassInstanceCreationExpression = 382, /* ClassInstanceCreationExpression  */
  YYSYMBOL_UnqualifiedClassInstanceCreationExpression = 383, /* UnqualifiedClassInstanceCreationExpression  */
  YYSYMBOL_ClassOrInterfaceTypeToInstantiate = 384, /* ClassOrInterfaceTypeToInstantiate  */
  YYSYMBOL_FieldAccess = 385,              /* FieldAccess  */
  YYSYMBOL_ArrayAccess = 386,              /* ArrayAccess  */
  YYSYMBOL_MethodInvocation = 387,         /* MethodInvocation  */
  YYSYMBOL_ArgumentList = 388,             /* ArgumentList  */
  YYSYMBOL_MethodReference = 389,          /* MethodReference  */
  YYSYMBOL_ArrayCreationExpression = 390,  /* ArrayCreationExpression  */
  YYSYMBOL_DimExpr = 391,                  /* DimExpr  */
  YYSYMBOL_Expression = 392,               /* Expression  */
  YYSYMBOL_AssignmentExpression = 393,     /* AssignmentExpression  */
  YYSYMBOL_Assignment = 394,               /* Assignment  */
  YYSYMBOL_LeftHandSide = 395,             /* LeftHandSide  */
  YYSYMBOL_AssignmentOperator = 396,       /* AssignmentOperator  */
  YYSYMBOL_ConditionalExpression = 397,    /* ConditionalExpression  */
  YYSYMBOL_ConditionalOrExpression = 398,  /* ConditionalOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 399, /* ConditionalAndExpression  */
  YYSYMBOL_InclusiveOrExpression = 400,    /* InclusiveOrExpression  */
  YYSYMBOL_ExclusiveOrExpression = 401,    /* ExclusiveOrExpression  */
  YYSYMBOL_AndExpression = 402,            /* AndExpression  */
  YYSYMBOL_EqualityExpression = 403,       /* EqualityExpression  */
  YYSYMBOL_RelationalExpression = 404,     /* RelationalExpression  */
  YYSYMBOL_InstanceofExpression = 405,     /* InstanceofExpression  */
  YYSYMBOL_ShiftExpression = 406,          /* ShiftExpression  */
  YYSYMBOL_AdditiveExpression = 407,       /* AdditiveExpression  */
  YYSYMBOL_MultiplicativeExpression = 408, /* MultiplicativeExpression  */
  YYSYMBOL_UnaryExpression = 409,          /* UnaryExpression  */
  YYSYMBOL_PreIncrementExpression = 410,   /* PreIncrementExpression  */
  YYSYMBOL_PreDecrementExpression = 411,   /* PreDecrementExpression  */
  YYSYMBOL_UnaryExpressionNotPlusMinus = 412, /* UnaryExpressionNotPlusMinus  */
  YYSYMBOL_PostfixExpression = 413,        /* PostfixExpression  */
  YYSYMBOL_PostIncrementExpression = 414,  /* PostIncrementExpression  */
  YYSYMBOL_PostDecrementExpression = 415,  /* PostDecrementExpression  */
  YYSYMBOL_CastExpression = 416,           /* CastExpression  */
  YYSYMBOL_SwitchExpression = 417,         /* SwitchExpression  */
  YYSYMBOL_418_62 = 418,                   /* $@62  */
  YYSYMBOL_VariableAccess = 419            /* VariableAccess  */
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
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   7540

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  119
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  301
/* YYNRULES -- Number of rules.  */
#define YYNRULES  742
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1284

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
       0,   788,   788,   789,   791,   793,   794,   796,   798,   800,
     801,   803,   804,   806,   807,   809,   810,   812,   813,   815,
     816,   818,   820,   821,   823,   824,   826,   827,   829,   830,
     832,   834,   835,   837,   839,   840,   842,   843,   845,   847,
     848,   850,   852,   853,   855,   857,   858,   860,   862,   863,
     865,   866,   873,   874,   876,   877,   879,   880,   882,   883,
     885,   887,   888,   890,   892,   893,   895,   897,   898,   900,
     901,   903,   905,   906,   908,   910,   911,   913,   915,   916,
     918,   919,   920,   921,   922,   923,   924,   925,   927,   929,
     930,   931,   932,   933,   934,   935,   936,   937,   938,   939,
     940,   941,   942,   943,   944,   954,   955,   956,   957,   958,
     959,   960,   961,   962,   964,   966,   967,   969,   970,   971,
     972,   973,   975,   976,   978,   979,   981,   982,   984,   985,
     987,   989,   990,   992,   993,   995,   997,   998,  1000,  1001,
    1002,  1003,  1004,  1005,  1006,  1007,  1009,  1010,  1012,  1013,
    1015,  1016,  1017,  1018,  1020,  1021,  1023,  1025,  1026,  1028,
    1029,  1031,  1032,  1033,  1035,  1035,  1036,  1036,  1037,  1037,
    1038,  1038,  1039,  1039,  1040,  1040,  1041,  1041,  1042,  1042,
    1044,  1045,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,
    1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,
    1064,  1065,  1066,  1067,  1069,  1070,  1071,  1073,  1073,  1074,
    1074,  1075,  1075,  1076,  1076,  1077,  1077,  1078,  1078,  1079,
    1079,  1080,  1080,  1081,  1081,  1082,  1082,  1083,  1083,  1084,
    1084,  1085,  1085,  1086,  1086,  1087,  1087,  1088,  1088,  1089,
    1089,  1090,  1090,  1091,  1091,  1092,  1092,  1093,  1093,  1094,
    1094,  1095,  1095,  1096,  1096,  1097,  1097,  1098,  1098,  1099,
    1099,  1100,  1100,  1101,  1101,  1102,  1102,  1103,  1103,  1104,
    1104,  1106,  1108,  1109,  1111,  1113,  1115,  1116,  1119,  1120,
    1121,  1122,  1124,  1125,  1127,  1128,  1129,  1130,  1132,  1133,
    1134,  1135,  1136,  1140,  1141,  1143,  1144,  1146,  1147,  1149,
    1150,  1153,  1154,  1156,  1157,  1158,  1160,  1161,  1163,  1164,
    1167,  1168,  1170,  1171,  1172,  1173,  1175,  1176,  1179,  1180,
    1181,  1182,  1183,  1184,  1185,  1186,  1188,  1189,  1191,  1192,
    1194,  1195,  1196,  1198,  1199,  1201,  1203,  1204,  1206,  1209,
    1210,  1212,  1214,  1217,  1218,  1219,  1220,  1222,  1224,  1225,
    1226,  1227,  1228,  1229,  1230,  1231,  1234,  1235,  1236,  1237,
    1239,  1240,  1241,  1242,  1243,  1244,  1245,  1246,  1247,  1248,
    1250,  1251,  1252,  1253,  1256,  1257,  1258,  1259,  1260,  1261,
    1263,  1264,  1266,  1268,  1270,  1271,  1272,  1273,  1274,  1275,
    1277,  1278,  1280,  1282,  1283,  1284,  1285,  1286,  1287,  1288,
    1289,  1292,  1293,  1295,  1296,  1298,  1299,  1302,  1304,  1305,
    1307,  1308,  1310,  1312,  1313,  1316,  1318,  1318,  1319,  1319,
    1320,  1320,  1321,  1321,  1322,  1322,  1323,  1323,  1324,  1324,
    1325,  1325,  1326,  1326,  1327,  1327,  1328,  1328,  1329,  1329,
    1330,  1330,  1331,  1331,  1332,  1332,  1333,  1333,  1336,  1338,
    1340,  1341,  1343,  1344,  1346,  1347,  1348,  1349,  1350,  1352,
    1353,  1355,  1356,  1358,  1359,  1360,  1365,  1366,  1368,  1369,
    1371,  1372,  1374,  1375,  1376,  1378,  1379,  1381,  1386,  1407,
    1429,  1430,  1432,  1433,  1434,  1435,  1436,  1437,  1439,  1440,
    1441,  1442,  1443,  1445,  1445,  1446,  1447,  1448,  1449,  1450,
    1451,  1452,  1453,  1454,  1455,  1456,  1457,  1459,  1461,  1463,
    1466,  1468,  1469,  1470,  1471,  1472,  1473,  1474,  1476,  1478,
    1480,  1482,  1483,  1485,  1485,  1487,  1488,  1489,  1490,  1491,
    1492,  1494,  1495,  1496,  1498,  1499,  1501,  1502,  1503,  1505,
    1507,  1509,  1511,  1513,  1514,  1516,  1517,  1519,  1521,  1522,
    1523,  1524,  1525,  1526,  1527,  1528,  1530,  1531,  1532,  1533,
    1534,  1535,  1536,  1537,  1539,  1540,  1542,  1544,  1545,  1547,
    1549,  1551,  1553,  1554,  1557,  1559,  1560,  1563,  1564,  1566,
    1568,  1568,  1570,  1572,  1574,  1575,  1576,  1577,  1579,  1580,
    1582,  1582,  1584,  1585,  1587,  1588,  1591,  1591,  1593,  1594,
    1595,  1596,  1598,  1600,  1601,  1603,  1604,  1606,  1607,  1609,
    1610,  1611,  1612,  1613,  1614,  1615,  1616,  1617,  1618,  1619,
    1621,  1622,  1623,  1624,  1625,  1626,  1628,  1629,  1630,  1631,
    1637,  1638,  1639,  1640,  1642,  1643,  1645,  1646,  1647,  1648,
    1650,  1651,  1652,  1654,  1655,  1656,  1657,  1658,  1659,  1660,
    1661,  1662,  1663,  1664,  1665,  1666,  1667,  1670,  1671,  1673,
    1674,  1675,  1676,  1677,  1678,  1679,  1680,  1682,  1683,  1684,
    1685,  1686,  1687,  1690,  1692,  1694,  1695,  1697,  1699,  1700,
    1701,  1702,  1704,  1706,  1707,  1709,  1710,  1712,  1713,  1715,
    1716,  1718,  1719,  1721,  1722,  1724,  1725,  1726,  1728,  1729,
    1730,  1731,  1732,  1733,  1738,  1740,  1741,  1742,  1743,  1745,
    1746,  1747,  1749,  1750,  1751,  1752,  1754,  1755,  1756,  1757,
    1758,  1760,  1762,  1764,  1765,  1766,  1767,  1768,  1770,  1771,
    1772,  1773,  1774,  1776,  1778,  1780,  1781,  1782,  1784,  1784,
    1786,  1787,  1788
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
  "OMInterfaceMemberDeclaration", "OMBlockStatement", "OMSwitchRule",
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
  "ConstructorBody", "ExplicitConstructorInvocation", "EnumDeclaration",
  "EnumBody", "EnumConstantList", "PRB", "PRBArgumentList", "EnumConstant",
  "EnumBodyDeclarations", "RecordDeclarationSym", "RecordDeclaration",
  "RecordHeader", "RecordComponentList", "RecordComponent",
  "VariableArityRecordComponent", "RecordBody", "RecordBodyDeclaration",
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

#define YYPACT_NINF (-1074)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-743)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2545, -1074,   -11, -1074, -1074,    24, -1074,   -11, -1074,   -11,
   -1074,   -11, -1074,   -11, -1074,    82,   -11, -1074,  2347,  1340,
    1154, -1074,   210, -1074, -1074,  1793, -1074, -1074, -1074, -1074,
   -1074, -1074, -1074, -1074, -1074, -1074,    26, -1074, -1074, -1074,
   -1074, -1074,    73,   -11,   171,   391,    91,   319,   291,   342,
     -11, -1074,  1340, -1074, -1074, -1074,   -11,   -11,   -11,    26,
   -1074, -1074,  1793,  1340,   -11,  1373,   163,   126, -1074,   -11,
     440,   118,   456, -1074,     2, -1074,   211,   -11,   491,   233,
   -1074,   -11,   -11,   296,   261,   341, -1074,   -11,   -11,   299,
     313,    68,   362, -1074,   326,   361,   396,    91,   319,   291,
     163,   126,  1340,   426,   330,   411, -1074, -1074, -1074, -1074,
   -1074, -1074, -1074, -1074, -1074,   421, -1074, -1074, -1074,   643,
     421, -1074,   455,   405, -1074,   126,  4029,   432, -1074, -1074,
   -1074,   -11,   268, -1074,   309,   484, -1074,   490, -1074,   511,
   -1074, -1074,  2292,   310,   -11, -1074,   478,   645,   525,   536,
   -1074, -1074,   565,   359,   261,   341, -1074,  4259, -1074,   261,
   -1074,   261, -1074,   553,   359,  4083, -1074,   299,    68,   362,
   -1074,   299,   362, -1074,   299, -1074,   299,   589,   689,   604,
     638,   408,   233, -1074,   296,   261,   341, -1074,   299,   313,
      68,   362, -1074,   126,   432, -1074,   -11, -1074,   -11,   330,
   -1074, -1074,   579,   421, -1074,   -11, -1074,   421, -1074,  1130,
     405, -1074,   432, -1074,   648,   -11,  3339, -1074, -1074,  2486,
    4144,   608, -1074,   581, -1074, -1074, -1074,   -11, -1074,   189,
     656, -1074, -1074, -1074,    66, -1074,   691, -1074, -1074, -1074,
   -1074, -1074,   683,   714, -1074, -1074,   -11,   511, -1074,  2486,
    2292,   209, -1074, -1074,   731, -1074,   525,  4969, -1074,   299,
     299, -1074,   740, -1074, -1074,   -11,   -11,   -11,   741, -1074,
   -1074,   261, -1074,   261, -1074, -1074,  2486,  4307, -1074,   581,
     -11,   189, -1074, -1074, -1074, -1074, -1074,   261, -1074,   741,
     741, -1074,  4198, -1074,   299,   362, -1074,   299, -1074,   299,
   -1074,   299, -1074,   299, -1074,   299, -1074, -1074,   -11,   -11,
     507,   -11,   -11,   398, -1074,   761,   689,   775,   689,   780,
   -1074,   261,   341, -1074, -1074,   261, -1074,   261, -1074,   299,
      68,   362, -1074,   299,   362, -1074,   299, -1074,   299,   432,
   -1074, -1074,   795, -1074, -1074, -1074, -1074, -1074, -1074, -1074,
   -1074, -1074, -1074,   327, -1074,  1130,   796,  6670,   798,   815,
    4642, -1074,   429,  6670,  5050, -1074,   813,   667,   828, -1074,
   -1074, -1074, -1074, -1074, -1074,   833,   863, -1074, -1074, -1074,
   -1074, -1074,   -11, -1074,  6670, -1074, -1074, -1074, -1074, -1074,
   -1074, -1074,  6670,  6670,  6670, -1074, -1074,   843,  3249,   551,
   -1074, -1074,   446,   878, -1074, -1074,   418,   873, -1074,   842,
    3479, -1074, -1074,   880,   -11, -1074, -1074,   648, -1074, -1074,
   -1074,   883, -1074, -1074, -1074, -1074, -1074, -1074, -1074,   896,
   -1074,   924, -1074, -1074, -1074, -1074, -1074, -1074, -1074,   601,
   -1074, -1074,   686,   888, -1074,   499, -1074,   637,   770,   550,
   -1074, -1074, -1074,   773, -1074, -1074,   816,   823,   832,   -11,
     189,    66,   691, -1074, -1074, -1074,  2229,   433,   -11,   656,
     470,   834, -1074,   920, -1074, -1074, -1074,  4358,  1002,   -11,
    3597,   691, -1074, -1074, -1074, -1074, -1074, -1074, -1074, -1074,
     927, -1074, -1074, -1074,  6670,  6670,  6670,  6670,  6670, -1074,
     461,   418,   873, -1074, -1074,   935,   937, -1074, -1074, -1074,
     297,   951,   958,   962,   966,   726,   458, -1074,   794,   837,
     498, -1074, -1074, -1074, -1074,   816, -1074, -1074, -1074, -1074,
   -1074, -1074, -1074,   565,   953, -1074, -1074,   261, -1074,   -11,
     189, -1074, -1074,   845, -1074, -1074, -1074, -1074,   299, -1074,
     299, -1074,   299, -1074, -1074,   299, -1074, -1074,    47,   259,
     271,   298,   507, -1074, -1074,   605,   661,   675,    44,   188,
   -1074, -1074, -1074,   639, -1074,   831,   972,   689, -1074,   261,
   -1074,   261, -1074,   261, -1074, -1074,   299,   362, -1074,   299,
   -1074,   299, -1074,   299, -1074,   299, -1074,   299, -1074, -1074,
     -11,   795, -1074, -1074,   971,   508,   984, -1074,   982,  6670,
      32,  6670,  6670,   409,  1052, -1074,  1004,  1005, -1074,  1008,
    1080,   -11,   -11,  6670,  1012,   374,   570, -1074, -1074, -1074,
   -1074,  1018, -1074,   -11,  4642,  5131,   277,   -11,   517,  5131,
     331,   -11,   527,  5212,  1085,    31, -1074,  3479, -1074, -1074,
     421,  1021, -1074, -1074,  3793,  6670,  3955, -1074,   207,   648,
      52,   -11,  6670, -1074, -1074, -1074,  6670, -1074, -1074,   865,
   -1074,   691, -1074, -1074,  4388,    60,  1023, -1074,  4574,   723,
    1022,  1024, -1074, -1074,  4418, -1074,  1002,   421, -1074,   -11,
    5293,   421,  4466,    53,  1031, -1074, -1074, -1074,  1028,  1047,
     320, -1074,   687,   537,  3712,  1046,   728, -1074,  6670, -1074,
   -1074, -1074, -1074,  1049,   418,   311, -1074,  6670,   937, -1074,
    6670,  6670,  6670,  6670,  6670,  6670,  6670,  6670,  6670,  6670,
    6670,  6670,  1130,  6670,  6670,  6670,  6670,  6670,  6670,  6670,
    6670, -1074,   875, -1074, -1074, -1074,   299, -1074, -1074, -1074,
     -11, -1074,   -11, -1074,   -11, -1074,   -11, -1074, -1074,   679,
   -1074,   -11, -1074, -1074,   -11,   -11, -1074, -1074, -1074,   899,
   -1074,   261, -1074, -1074, -1074,   299, -1074,   299, -1074,   299,
   -1074, -1074,   299, -1074, -1074, -1074, -1074, -1074,  5131,   759,
    1043,   984, -1074,   759,   984,  5374,  1053,  6670, -1074,  1054,
    1060,  1063, -1074, -1074, -1074, -1074,  1064, -1074,  1065, -1074,
   -1074,  1021, -1074,  1048,   -11, -1074, -1074,   730,  1067, -1074,
   -1074,  1131,  1066, -1074, -1074,   739,  1072, -1074, -1074,  1137,
   -1074,  1076, -1074, -1074, -1074, -1074,  5455,  4496,   952,  1104,
    1083,  1086, -1074,  1095,  3955, -1074,   594,   570, -1074,  1098,
    1094,   686,   501, -1074, -1074, -1074,  1163,  1176, -1074,   207,
    1105, -1074, -1074,  1099, -1074, -1074, -1074, -1074,  1110, -1074,
    1202,  1111, -1074,   747,   -11, -1074, -1074,  4574,  1024, -1074,
    4526, -1074,  1117, -1074, -1074,  4807, -1074, -1074, -1074,   421,
     421,  1119,   542,   421,   -11,  1028, -1074,  5536,  5617,   333,
     381, -1074,  1118, -1074,   106,  1121,  6670,  6751,     9, -1074,
   -1074,  1147,   951,   958,   962,   966,   726,   458,   458,   794,
     794,   794,   794,   421, -1074,   421, -1074,   837,   837,   837,
     498,   498, -1074, -1074, -1074, -1074, -1074,   799,   830,   852,
     860, -1074, -1074,   892,   915,   933,   946, -1074, -1074, -1074,
     299, -1074, -1074, -1074,  1120, -1074,   421, -1074, -1074,   421,
     299,  1125, -1074,  1122,  4732, -1074,  6670,  5698,  4642, -1074,
    1127,   -11,   -11,  5779, -1074, -1074,   -11,   -11,  5860, -1074,
   -1074,  6823,  1123,  7423,  1083, -1074,  5941,  4642, -1074,  1094,
   -1074, -1074,  1133,   648, -1074,  1176, -1074,  1163, -1074,  6022,
   -1074, -1074, -1074, -1074,   -11, -1074, -1074, -1074, -1074, -1074,
    1135, -1074, -1074,  1136,  1140,  1145,   421,   421,   421, -1074,
   -1074,  1134,  1148,  1144,  1150,   360,   392, -1074,  1157, -1074,
   -1074, -1074,  6751,  6670, -1074,   -11,   904, -1074, -1074,   908,
   -1074,   923, -1074,   965, -1074,   978, -1074,   985, -1074,   988,
   -1074,   990, -1074, -1074, -1074,   299,  1162, -1074,  1165,  1166,
     818, -1074,  1249,  1252, -1074, -1074, -1074, -1074,  1172, -1074,
    1196, -1074,   648,  1177, -1074,  1178, -1074,  1180, -1074, -1074,
    1183,  1185, -1074, -1074,  1186,  4642,  1187, -1074,  6898, -1074,
   -1074,  6973,  1188, -1074,   507, -1074, -1074, -1074, -1074,  1191,
   -1074, -1074, -1074,  5293, -1074,   421, -1074,  1193, -1074,  1194,
    6103,  6184,  6265,  1162, -1074, -1074,  1197, -1074, -1074, -1074,
   -1074, -1074, -1074, -1074, -1074, -1074, -1074,   100, -1074,  6670,
    6670,  4732,  4642,  3874,  6670, -1074,  1195, -1074,  6346, -1074,
    6427, -1074, -1074,  4642,  4642,  1192,  4642,  1203,  7048,   507,
    1214,  1206,   -11, -1074, -1074, -1074, -1074,  1204,  1207,  1205,
    1213,  1209,  1215, -1074, -1074,  6670, -1074,   116,   173, -1074,
     227, -1074,  1025,  1216,  1219, -1074, -1074,  6508,  1217,  1220,
   -1074, -1074,  1221, -1074,  1223, -1074, -1074,  4642, -1074,  4642,
    4642,  1224,   -11,   -11,  1214, -1074,   648, -1074, -1074,  1222,
   -1074,  1225, -1074,  1226,  1179, -1074, -1074,   308, -1074,  1235,
   -1074, -1074,  1257, -1074,   329, -1074,  1251,  3479,  4888,  4732,
    4732,  7123,  1231,  6589,  4732, -1074, -1074, -1074, -1074, -1074,
    4642, -1074, -1074, -1074, -1074, -1074, -1074, -1074,  6670,  1179,
   -1074, -1074, -1074, -1074, -1074,  3149, -1074, -1074, -1074,  1234,
    1323, -1074,  4732,  1244,  7198,  7273,  1241, -1074, -1074, -1074,
   -1074, -1074, -1074,  4732, -1074,  4732,  4732,  1247,  4732,  1256,
    7348, -1074, -1074, -1074,  4732, -1074,  4732,  4732,  1258, -1074,
   -1074, -1074,  4732, -1074
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     138,    83,     0,    82,    81,     0,    80,     0,    87,     0,
      84,     0,    86,     0,    85,     0,     0,   163,   140,   139,
       0,   448,     0,   136,   137,   142,     9,   150,   151,   153,
     152,    11,   146,   161,   204,   205,     0,   206,   162,   415,
      26,    88,     0,     0,     0,     0,     0,   416,   207,     0,
       0,   392,   141,    10,   147,    12,     0,     0,     0,     0,
      27,     1,   144,   143,     0,     0,     0,     0,   148,     0,
       0,     0,     0,   154,     0,   155,     0,     0,     0,     0,
     370,     0,     0,   424,     0,   420,   418,     0,     0,     0,
     223,   215,   211,   209,   166,     0,     0,     0,   432,   239,
       0,     0,   145,   126,   272,     0,   307,   123,   117,   119,
     118,   121,   120,   122,   401,   304,   306,   115,   116,     0,
     303,   305,     0,   403,   406,     0,     0,     0,   393,    13,
     149,     0,     0,   156,     0,     0,   133,     0,   134,   276,
     275,   374,   390,     0,   381,    42,   384,     0,   380,     0,
     371,   449,     0,   450,     0,   428,   426,     0,   417,     0,
     422,     0,   274,   278,   279,     0,   208,     0,   231,   227,
     225,     0,   219,   217,     0,   213,     0,     0,     0,   170,
     174,     0,     0,   372,   440,     0,   436,   434,     0,   255,
     247,   243,   241,     0,     0,   397,     0,   127,     0,   273,
      28,   271,     0,   309,     2,     0,   405,   308,   402,     0,
     404,    45,     0,   395,    84,     0,   493,   408,   292,     0,
       0,   304,   290,     0,   410,   284,   288,     0,   289,     0,
       0,   285,   286,   287,     0,    48,     0,   411,   291,   341,
     394,    14,     0,     0,   157,   158,     0,   277,    31,     0,
     391,   304,    34,   376,     0,    43,     0,     0,   387,   385,
     386,   378,     0,    44,   375,     0,     0,     0,   451,    22,
     425,     0,   430,     0,   452,   458,     0,     0,   456,     0,
       0,     0,   457,    50,   454,   455,   421,     0,   419,   280,
     281,   282,     0,   224,     0,   235,   233,     0,   229,     0,
     216,     0,   221,     0,   212,     0,   210,   165,     0,     0,
       0,     0,     0,     0,    15,     0,     0,     0,     0,   178,
     373,     0,   444,   442,   433,     0,   438,     0,   240,     0,
     263,   259,   257,     0,   251,   249,     0,   245,     0,     0,
     399,   398,   128,    30,    29,     4,     3,   407,    47,    46,
     396,   342,   317,     0,   547,     0,     0,     0,     0,     0,
     493,   611,     0,     0,     0,   582,     0,     0,     0,    90,
      91,    92,    93,    94,    95,    85,    97,    98,    99,   100,
     101,   102,   103,   104,     0,   105,   106,   107,   108,   109,
     110,   111,     0,     0,     0,   468,   507,    88,     0,   679,
     135,   609,   730,     0,   475,   480,   303,   305,   476,     0,
     470,   472,   473,     0,     0,   474,   482,     0,   495,   483,
     496,     0,   484,   485,   497,   498,   486,   499,   487,     0,
     543,     0,   544,   500,   506,   501,   502,   504,   503,     0,
     505,   587,   728,   607,   610,   615,   626,   616,   617,   618,
     619,   608,   511,     0,   512,   513,     0,   514,   515,     0,
       0,     0,     0,   409,    49,   347,     0,   304,     0,     0,
     299,     0,   295,   297,   340,   310,   339,     0,   312,     0,
     493,     0,   343,   413,   159,   160,    33,    32,    35,   377,
       0,    96,    97,   103,     0,     0,     0,     0,     0,   382,
     729,     0,     0,   615,   618,     0,   657,   674,   676,   675,
     683,   685,   687,   689,   691,   693,   695,   703,   698,   705,
     709,   712,   716,   717,   720,   723,   731,   732,   726,   727,
     388,   389,   379,    24,    25,    23,   429,     0,   427,     0,
       0,   453,    51,     0,   461,   423,   283,   232,     0,   237,
       0,   228,     0,   226,   220,     0,   218,   214,     0,     0,
       0,     0,     0,    17,   131,     0,     0,     0,     0,     0,
     167,    16,   169,     0,   173,     0,     0,     0,   441,     0,
     446,     0,   437,     0,   435,   256,     0,   267,   265,     0,
     261,     0,   248,     0,   253,     0,   244,     0,   242,   400,
       0,   129,     5,   575,     0,   634,     0,   114,     0,     0,
       0,     0,     0,   679,     0,   572,     0,     0,   577,     0,
       0,     0,     0,     0,     0,   729,   730,   616,   617,   721,
     722,     0,   481,     0,   493,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,     0,   469,   471,    52,   477,
     299,   478,   494,   510,     0,     0,     0,   583,     0,     0,
       0,     0,     0,   113,   112,   682,     0,   733,   734,     0,
     311,     0,   345,   414,     0,     0,     0,   348,     0,     0,
       0,   328,   332,   347,     0,   316,   314,   300,   293,     0,
       0,   318,     0,     0,     0,   313,   338,   335,   336,   611,
       0,   356,   679,   678,   493,     0,   728,   344,     0,   725,
     724,   718,   719,     0,   114,     0,   383,     0,   658,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   431,     0,   462,   459,   236,     0,   234,   230,   222,
       0,   182,     0,   191,     0,   185,     0,   194,    18,     0,
     180,     0,   188,   197,     0,     0,   171,   175,   177,     0,
     445,     0,   443,   439,   264,     0,   269,     0,   260,     0,
     258,   252,     0,   250,   246,   130,     6,   576,     0,     0,
     635,   669,    78,     0,   667,     0,     0,     0,   521,     0,
       0,     0,   573,   579,   578,   625,   637,   663,     0,   574,
     614,   479,   508,     0,     0,   612,   620,     0,   133,   627,
     659,     0,     0,   613,   621,     0,   134,   628,   660,     0,
     644,     0,   624,   666,   662,    53,     0,     0,   679,   565,
     567,     0,   564,     0,   604,    72,   741,   740,   605,     0,
     603,     0,   616,   606,   590,   596,   584,   588,   585,   598,
     636,   629,   661,     0,   677,   294,   346,   350,     0,   326,
       0,     0,     7,     0,     0,   330,   349,     0,   329,    36,
       0,   352,     0,   315,   296,     0,   298,   302,   301,   319,
     322,     0,   299,   320,     0,   337,    39,     0,     0,     0,
       0,   358,     0,   357,     0,     0,     0,     0,     0,    77,
      76,     0,   686,   688,   690,   692,   694,   696,   697,   700,
     699,   702,   701,   124,   704,     0,   125,   706,   707,   708,
     710,   711,   713,   714,   715,   460,   238,     0,     0,     0,
       0,   181,   132,     0,     0,     0,     0,   179,   447,   268,
       0,   266,   262,   254,     0,   672,   670,    79,   671,   668,
     630,     0,   523,     0,   493,   580,     0,     0,   493,   640,
     634,     0,     0,     0,   622,   641,     0,     0,     0,   623,
     643,     0,     0,     0,   568,    64,     0,   493,    73,     0,
     602,    74,     0,     0,   586,   589,    67,   600,   599,     0,
     642,   351,   327,     8,     0,   331,   333,    38,    37,   354,
       0,   353,   463,     0,   466,     0,   323,   324,   321,    41,
      40,     0,     0,     0,     0,     0,     0,   359,     0,   738,
     735,   736,     0,     0,   183,     0,     0,    19,   192,     0,
     186,     0,   195,     0,   189,     0,   202,     0,   200,     0,
     198,     0,   270,   673,   631,   632,     0,   522,     0,     0,
     679,   518,     0,   482,   489,   490,   491,   492,     0,   545,
       0,   546,     0,     0,   651,     0,   540,   638,   664,   645,
       0,   639,   665,   647,     0,   493,     0,   566,     0,    66,
      65,     0,     0,   570,     0,   597,    68,   601,   649,     0,
     334,   355,   464,     0,   465,   325,   360,     0,   362,     0,
       0,     0,     0,     0,   737,   684,    21,   184,    20,   193,
     187,   196,   190,   201,   203,   199,   633,     0,   524,     0,
       0,   493,   493,     0,     0,   581,     0,   652,     0,   646,
       0,   648,   548,   493,   493,     0,   493,     0,     0,     0,
     594,     0,     0,   650,   467,   361,   363,     0,     0,     0,
       0,     0,     0,   739,   538,     0,   527,     0,     0,    58,
       0,    56,     0,     0,     0,   509,   519,     0,     0,     0,
     542,   653,     0,   655,     0,   549,   550,   493,   552,   493,
     493,     0,     0,     0,   595,    69,     0,   592,   364,     0,
     366,     0,   368,     0,   536,   539,   529,     0,    57,     0,
     528,    59,     0,   525,     0,    54,     0,    60,     0,   493,
     493,     0,     0,     0,   493,   654,   656,   551,   553,   554,
     493,   593,    71,    70,   591,   365,   367,   369,     0,   537,
      61,   530,    60,   526,    55,   493,   534,   532,   533,     0,
       0,   541,   493,     0,     0,     0,     0,   571,   555,    63,
      62,   535,   531,   493,   556,   493,   493,     0,   493,     0,
       0,   520,   557,   558,   493,   560,   493,   493,     0,   559,
     561,   562,   493,   563
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1074,   448,  -180,   653,  -456, -1074,  1330,   338,   180,  -273,
   -1074,   133,  -268,   -64,  -258,   304, -1074,  1164, -1074,  1128,
    1212, -1074,   492, -1074,   479, -1074,  1237, -1074,  1173, -1074,
   -1074, -1074, -1074, -1074, -1018, -1073, -1074,   145, -1074,   404,
   -1074, -1074,   195, -1074,   546, -1074,   673,   787,  -282,    -2,
   -1074, -1074, -1074,   897, -1074, -1074, -1074, -1074,  1199, -1074,
    -585,  -522,    93, -1074, -1074, -1074, -1074, -1074,   153, -1074,
   -1074, -1074, -1074,    64,  1376, -1074, -1074, -1074, -1074, -1074,
   -1074, -1074, -1074,  -280,  -113, -1074, -1074, -1074, -1074, -1074,
   -1074, -1074, -1074, -1074, -1074, -1074, -1074, -1074, -1074, -1074,
   -1074, -1074, -1074, -1074, -1074, -1074, -1074, -1074, -1074, -1074,
   -1074, -1074, -1074, -1074, -1074, -1074, -1074, -1074,    54, -1074,
     -21,   481,  1319,    98,  2544,  -112, -1074, -1074,  -219,   712,
    -673,   713,  1289,   640,   802, -1074,   -84,  -132,   942, -1074,
    -439,   535, -1074,  -427, -1074,   510,  -255, -1074, -1074, -1074,
     947,    30,  -224, -1074, -1074,   -37, -1074, -1074, -1074,  1269,
     541,    37, -1074,   356, -1074,  1210, -1074,    49,  1182,  1201,
   -1074,   190,  -208, -1074, -1074, -1074, -1074, -1074, -1074, -1074,
   -1074, -1074, -1074, -1074, -1074, -1074, -1074, -1074, -1074,    -3,
     -33,    -1,   -67,  1139, -1074, -1074,   -93,   315,  -148,  -478,
    -385, -1074, -1074,  -632,  -394,   861,   328,  -284, -1074, -1074,
   -1074, -1074, -1074,  -607, -1074, -1074, -1074, -1074, -1074, -1074,
     312,  -899,   256,  -825,   191, -1074, -1074, -1074, -1074, -1074,
     -17, -1074, -1074,   300,  -929,  -653,    83, -1074, -1074, -1074,
   -1074, -1074, -1074,   212, -1074, -1074, -1074,   777, -1074,   573,
    -808, -1074, -1074,   285,  -788, -1074, -1074, -1074, -1074,   595,
    -465, -1074, -1074,   441,  -601, -1074,  2199,  2338,   654,  -554,
   -1074, -1074,    71,   401, -1074,   801, -1074, -1074,  -987, -1074,
     717,   718,   719,   720,   716,   384, -1074,    78,   351,   376,
    -374,  1016,  1211,  -871,  1407,  1554,  1771, -1074, -1074, -1074,
   -1074
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   638,   204,   601,   674,   870,    18,    19,   790,   313,
     562,  1036,  1037,   268,   269,    20,   199,   200,   247,   248,
     250,   878,   879,   895,   896,   144,   145,   210,   211,   220,
     277,   647,  1214,  1167,  1168,  1169,  1239,  1240,   984,   985,
     995,  1194,  1195,   844,   845,   718,   719,   791,    21,   500,
     400,   401,   665,   606,   116,   117,   118,   924,   104,   197,
     602,   565,   402,   403,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   177,   178,   315,   316,   317,
     318,   576,   577,   314,    33,    34,    89,   176,   174,   305,
     171,   303,   301,   555,   167,   299,   297,   552,   294,   550,
     548,   746,   188,   338,   336,   597,   333,   595,   593,   782,
     329,   591,   589,   779,   586,   777,   775,   950,   223,   105,
      91,    79,   140,    93,   166,   224,   225,   226,   471,   472,
     473,  1014,   405,   501,   502,   228,   229,   230,   478,   676,
     680,   681,   682,   481,   697,   698,   475,   231,   232,   233,
     466,   234,   482,   704,    35,    80,   147,   259,   260,   148,
     149,    36,    37,    67,   122,   123,   124,   128,   235,   236,
     237,    38,    39,    84,   161,   159,   287,   154,   273,   271,
     537,   185,   327,   325,   583,   321,   581,   579,   771,    40,
      85,    86,   158,   283,   284,   285,   887,  1015,   239,   409,
     410,   411,   412,   413,   414,   415,  1062,   416,   417,   418,
     419,  1064,   420,   421,   422,   423,  1065,   424,   425,  1056,
    1128,  1170,  1171,  1212,  1204,   426,  1066,   427,   428,  1067,
     429,   430,  1069,   841,  1086,  1087,   431,   432,  1071,   433,
     434,   435,   436,   437,   438,  1072,   439,   658,   440,   856,
     857,   992,  1151,  1152,   858,   993,   441,   659,   849,   850,
     442,   443,   444,   503,   446,   608,   447,   448,   504,   505,
     450,   451,   792,   506,   507,   508,   453,   666,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,  1113,
     853
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,   842,   705,    44,   633,    46,   875,    47,   408,    48,
     535,    49,   483,   222,    51,   706,   786,    60,   629,   630,
     875,   692,   839,   346,   848,   648,   544,   346,   563,   222,
     252,   535,   535,   571,   671,   819,  1031,   833,   694,   827,
     759,    71,   150,   573,   278,   575,  1115,   840,    96,   996,
     155,   695,   222,   252,    97,    98,    99,    59,   814,   861,
     183,   543,   103,   115,    43,   186,   351,   129,   994,   168,
     869,   998,   136,   281,   138,   139,   146,   869,   190,   139,
     152,   476,   156,    55,   160,   162,   163,   270,    77,   831,
      66,   469,   286,   479,   288,  1211,   135,   187,    45,   289,
     290,    83,    90,   404,    64,   600,    41,   222,   764,  1164,
     750,    77,   814,   100,   797,  1032,    55,   206,   324,    41,
     709,   710,   711,   712,   221,  1164,    88,    55,  1165,   241,
     136,    65,   138,   476,  1211,   460,    72,   222,   488,    50,
     251,    41,   146,   798,  1165,   320,    77,   469,    41,  1207,
     195,   322,   184,   189,   272,   115,  1028,   265,   751,  1145,
     265,  1114,  1147,   251,   278,   460,    55,   874,   330,    41,
      41,    53,  1211,   480,   213,   153,   240,    41,  1205,   222,
     488,   164,  1164,   323,    68,   326,    69,  1096,   170,   173,
     175,   851,   540,   281,   342,   651,   103,   192,    78,  1245,
    1005,  1165,   408,   347,   536,   670,   538,   115,  1166,  1097,
      61,   279,   848,   352,   399,    53,    60,   221,   221,  1191,
     545,   467,    70,    41,  1206,   470,   902,   880,   937,    95,
     938,   132,   939,   126,   940,   868,  1164,   672,   673,   854,
     669,   961,   340,   341,   486,   882,    60,   251,   251,   461,
     855,  1205,   765,   891,   578,  1165,    59,   707,   582,   883,
     584,   350,   835,   136,   533,   138,   296,   298,    65,   652,
     302,  1215,   408,    60,   115,   115,   181,   115,   470,   461,
     758,  1210,    73,   814,    74,   743,    59,   332,   335,   337,
     251,   657,  1253,   571,   815,   571,   216,   404,   819,   827,
     474,   267,  1172,   861,   769,   137,   558,   560,   564,   566,
     568,    77,   476,    59,   465,  1244,   238,  1164,   202,   816,
     742,   580,   752,   786,    87,  1267,  1269,   817,    41,    81,
     279,   279,   238,    77,   754,  1213,  1165,   814,  1164,   814,
      78,  1278,  1209,  1022,  1024,  1216,    87,   282,   823,    88,
     815,   604,    81,   605,    82,   238,    52,  1165,   613,   534,
     616,   756,   242,    63,   932,   933,   934,   404,   157,    64,
     753,    88,   267,   824,   840,   816,  1089,    82,   720,   851,
      51,   825,   755,  1025,   265,    41,   721,   814,   599,  1216,
     625,   625,   476,   549,    41,    60,   115,    64,   823,    82,
     102,   559,   561,   243,   567,   569,   165,   600,   399,   757,
     238,   267,   650,  1075,   811,   101,  1241,   907,   253,  1080,
      88,   142,   125,   824,  1084,   898,    41,   645,   588,   590,
     219,  1026,   594,   621,  -164,    59,   622,  1243,   603,   408,
     238,  1010,   198,   633,    41,  1099,   249,   866,    41,    94,
      41,   308,   309,   310,   311,    69,   193,   470,   346,   196,
     312,   276,   346,   115,   115,  1110,   685,   282,   179,   249,
     741,   266,   267,   971,   131,   115,   972,   696,   702,  1197,
     842,   840,   238,   635,   840,   626,   626,   636,   201,   571,
     637,   634,   625,   625,   625,   625,   408,  1111,    41,  -729,
    -729,   839,    75,   180,    76,   976,   570,   346,   977,    69,
       1,   657,   770,  1116,   772,   319,   773,   209,   635,  1231,
     398,   131,   636,     3,   219,   637,   840,   202,     4,    92,
     202,   644,  1030,     6,   404,   728,   729,   470,   683,   126,
     615,   840,   202,   730,   731,     8,    41,    10,   127,  -678,
    -678,   130,    12,   131,   249,   639,  1158,  1160,  1162,   640,
     564,   208,   641,   203,  -679,  -679,    14,   133,   207,   134,
     635,   169,   172,   703,   636,  -316,   732,   637,   182,   202,
     191,   276,   194,   257,  1182,   165,  1184,   626,   626,   626,
     626,   404,   738,   739,   106,   244,   249,   740,   785,   141,
     107,   245,   142,   143,   108,  -517,   212,  -742,    41,   346,
    -517,  -517,  -742,   346,   840,   109,   110,   788,   111,   806,
     807,    69,   215,   246,    41,   112,   202,  -730,  -730,   113,
     821,   650,   613,   634,   818,   820,   202,   263,   826,   828,
     829,  -729,  -729,   834,   264,   399,   639,   840,   840,   295,
     900,   202,   838,   641,   846,  1003,  -516,   445,   860,   862,
     635,  -516,  -516,   840,   636,   266,   265,   637,  -304,   203,
     331,   334,   115,   871,   339,    60,   115,   650,   265,   639,
    1063,   115,   115,   640,   254,   776,   641,   650,   262,   345,
     115,   892,   308,   309,   310,   311,   955,   307,    41,   203,
     958,   312,   399,   635,   948,   120,   656,   636,   216,   346,
     637,  -304,  -168,   465,   398,  -412,   760,   202,   761,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     923,   625,   625,   625,   625,   625,   625,   625,   625,  1246,
    -680,  -680,   308,   309,   310,   311,  -172,   766,   564,   847,
     564,   312,   564,   261,   564,   216,   142,   205,   610,   942,
      41,   477,   943,   945,   617,   619,   120,  1261,  1118,   634,
     678,  1118,   762,  1118,   265,  1118,   346,  -729,  -729,   346,
     621,   678,   120,   622,   398,   624,   763,   535,   267,   535,
     941,   535,   761,   535,   484,   631,   635,   120,   480,   660,
     899,   445,   661,   637,  -304,   120,   919,   920,   921,   922,
     726,   587,   970,   727,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   485,   626,   626,   626,   626,
     626,   626,   626,   626,    60,   115,   346,   874,   346,   489,
      41,   904,   846,   971,   661,  1095,   972,  1063,   532,   120,
     642,   445,   976,   266,   207,   977,   406,   944,   946,   120,
     120,  1004,   957,   120,    41,   957,   885,   121,   202,   572,
     449,   650,  1006,  -681,  -681,   115,   663,   664,   115,  1045,
    1047,  1049,  1051,   574,   308,   309,   310,   311,  -176,   120,
     120,   600,   696,   312,   733,   734,   735,   818,   826,   631,
    1131,   609,   860,   611,   625,   625,   667,   668,  -729,  -729,
    1034,  1035,   761,  -731,  -731,   203,   120,   120,   687,   120,
     612,   445,  -732,  -732,  1135,   346,   620,   635,   121,   736,
     737,   636,   120,   623,   637,  1063,  1063,   847,   -96,   767,
    1063,  1038,  1035,   761,   121,   688,   689,  1068,   -89,   207,
     646,   398,   308,   309,   310,   311,   744,   689,   837,   121,
     837,   312,  1060,  1040,  1035,   761,   613,   121,  1063,  1077,
    1078,  1042,  1035,   761,  1081,  1082,   865,   689,   678,  1063,
    -481,  1063,  1063,   643,  1063,   613,   935,   689,   678,   645,
    1063,   649,  1063,  1063,   653,   607,   678,   662,  1063,   626,
     626,   654,  1100,  1044,   266,   265,   655,   947,   398,   408,
     796,   121,   799,   800,   449,  1117,  1035,   452,   407,  1119,
    1035,   121,   121,   690,   808,   121,  1046,   266,   267,   479,
     625,   625,   708,   564,  1120,  1035,   813,   408,   120,   722,
     822,   716,  -729,  -729,  1048,   266,   265,  1070,  1234,   717,
     406,   121,   121,   789,   793,   723,   843,  1050,   266,   267,
     724,   635,   725,   863,   449,   636,   267,   864,   637,  -304,
    1247,  1039,  1041,  1043,   642,   445,  1121,  1035,   121,   121,
     768,   121,   787,   613,   927,   928,   929,   795,   445,  1122,
     266,   888,  1150,   788,   121,   445,  1123,   266,   687,  1124,
     266,  1125,   266,   801,   404,   120,   120,  1217,  1218,   905,
     917,   918,   930,   931,  1068,   802,   803,   120,   909,   804,
     406,   911,   805,   809,   810,   626,   626,   832,   876,  1060,
     613,   838,   404,   689,   449,   872,   877,   893,   714,   889,
     894,   613,   613,   106,   613,   445,    60,  1150,   837,   107,
     650,   642,   897,   108,   903,   906,   131,     1,   969,   962,
     964,   452,   207,   625,   109,   110,   965,   111,   966,   967,
       3,   968,   973,   974,   112,     4,   975,   978,   113,   979,
       6,   678,   980,    56,   678,   613,  -569,   613,   613,   954,
     650,  1232,     8,    57,    10,   983,    58,   986,   963,    12,
     121,   987,  1068,  1068,   990,   991,   855,  1068,   854,  1000,
     999,   452,   407,    14,  1070,   399,  1001,  1060,  1060,  1002,
      16,   614,  1060,  1011,  1003,  1017,  1027,  1029,   613,  1033,
    1053,  1055,   454,  1057,  1088,  1068,   625,   982,  1094,   956,
      69,  1101,   959,   399,  1102,  1106,  1068,    41,  1068,  1068,
    1060,  1068,  1103,  1104,  1107,  1108,  1109,  1068,   626,  1068,
    1068,  1060,  1112,  1060,  1060,  1068,  1060,   121,   121,  1127,
    1129,  1130,  1060,  1132,  1060,  1060,  -488,  1133,  1134,   121,
    1060,   452,   407,  1136,  1137,  1138,   888,   406,   449,  1139,
    1140,  1238,  1141,  1143,   406,   642,   406,  1153,  1187,  1148,
     715,   449,  1070,  1070,  1155,  1156,  1180,  1070,   449,  1189,
     761,  1193,  1196,  1199,   120,  1198,  1200,  1217,   120,  1201,
    1202,  1203,  1219,   120,   120,  1220,  1224,  1225,  1223,  1226,
    1230,   626,   120,  1235,  1218,  1070,  1236,  1237,  1016,  1242,
     687,  1018,  1254,     1,   406,  1262,  1070,  1263,  1070,  1070,
    1265,  1070,  1270,  1274,   119,    62,     3,  1070,   449,  1070,
    1070,     4,  1276,   344,  1282,  1070,     6,  1073,   908,     7,
    1008,   203,   925,   207,  1020,   487,   454,   292,     8,     9,
      10,   255,    11,   349,  1260,    12,   106,  1092,  1090,  1233,
     988,   910,   107,   794,    54,   713,   108,   343,  1149,    14,
     151,   884,   464,   886,  1019,   445,    16,   109,   110,   445,
     111,   686,  1007,   256,   684,   227,   542,   112,  1154,   348,
     462,   113,   445,  1208,   445,  1163,   454,   455,   445,  1259,
    1248,   227,   997,  1178,  1192,   452,   859,   837,   912,   989,
     913,   916,   914,     0,   915,     0,   280,     0,   452,   407,
       0,    17,     0,     0,   227,   452,   407,     0,   407,  1175,
       0,     0,     0,     0,     0,  1105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,   120,     0,   114,
     121,     0,     0,     0,   406,   121,   121,     0,     0,     0,
      41,     0,     0,     0,   121,   812,   454,     0,   119,     0,
       0,     0,     0,     0,   888,   452,   407,     0,   459,   227,
       0,     0,   468,     0,     0,     0,     0,   120,     0,     0,
     120,   398,     0,     0,     0,     0,   445,     0,     0,   445,
    1173,  1174,   445,     0,   926,  1179,     0,     0,   459,   227,
       0,     0,     0,     0,     0,     0,     0,  1250,  1251,   398,
       0,     0,  1257,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   539,   280,     0,   468,     0,
       0,   455,   445,   445,   445,     0,     0,     0,  1222,     0,
    1264,   227,     0,     0,   445,   445,     0,   445,     0,   445,
       0,  1271,     0,  1272,  1273,     0,  1275,     0,     0,     0,
       0,     0,  1279,     0,  1280,  1281,     0,     0,     0,     0,
    1283,     0,     0,     0,     0,     0,     0,     0,   449,  1249,
       0,   455,   449,   456,  1256,     0,     0,     0,   445,     0,
     445,   445,     0,     0,     0,   449,     0,   449,     0,   121,
       0,   449,     0,     0,     0,     0,   407,     0,     0,     0,
     454,     0,     0,     0,     0,     0,     0,     0,   445,     0,
     445,   445,   445,   454,     0,   445,     0,     0,     0,     0,
     454,   445,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,   121,     0,     0,     0,   445,     0,     0,     0,
       0,   455,     0,   445,     0,   445,   445,     0,     0,     0,
       0,     0,     0,     0,   445,     0,   445,   445,     0,   445,
       0,   445,     0,     0,     0,   445,     0,   445,   445,     0,
     454,     0,     0,   445,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   449,
       0,     0,   449,     0,     0,   449,     0,     0,     0,     0,
       0,     0,     0,     0,   675,   679,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   452,   693,   456,     0,   452,
     457,     0,     0,   406,     0,     0,     0,     0,     0,     0,
       0,     0,   452,     0,   452,   449,   449,   449,   452,     0,
       0,     0,     0,     0,     0,     0,     1,   449,   449,     0,
     449,     0,   449,     0,     0,     0,     0,     0,     0,     3,
       0,     0,     0,     0,     4,     0,     0,   456,     5,     6,
       0,     0,     7,     0,     0,  1061,     0,     0,     0,  1076,
       0,     8,     9,    10,     0,    11,     0,     0,    12,     0,
       0,   449,     0,   449,   449,   455,     0,     0,  1093,     0,
       0,     0,    14,     0,     0,     0,     0,   406,   455,    16,
       0,     0,     0,     0,     0,   455,     0,     0,     0,     0,
       0,   449,     0,   449,   449,   449,     0,     0,   449,     0,
       0,     0,     0,     0,   449,   406,   452,   456,     0,   452,
       0,     0,   452,     0,     0,     0,     0,     0,     0,   449,
       0,     0,     0,     0,    17,     0,   449,     0,   449,   449,
       0,     0,     0,     0,   457,   455,     0,   449,     0,   449,
     449,     0,   449,     0,   449,     0,     0,     0,   449,     0,
     449,   449,   452,   452,   452,   407,   449,     0,     0,     0,
       0,     0,     0,     0,   452,   452,  1142,   452,     0,   452,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   679,   457,     0,     0,   873,     0,     0,
       0,     0,   675,   679,     0,     0,     0,     0,     0,     0,
     454,   679,     0,     0,   454,     0,     0,   458,   452,     0,
     452,   452,   812,  1176,     0,     0,     0,   454,     0,   454,
       0,     0,     0,   454,  1185,  1186,     0,  1188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   452,   407,
     452,   452,   452,     0,     0,   452,     0,     0,     0,     0,
       0,   452,     0,     0,   457,     0,     0,     0,     0,     0,
       0,   456,     0,     0,     0,     0,   452,   407,  1227,     0,
    1228,  1229,     0,   452,   456,   452,   452,     0,     0,     0,
       0,   456,     0,     0,   452,     0,   452,   452,     0,   452,
       0,   452,     0,     0,     0,   452,     0,   452,   452,     0,
    1061,  1076,     0,   452,     0,  1093,     0,     0,     0,     0,
       0,  1258,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   454,     0,     0,   454,     0,     0,   454,     0,     0,
       0,   456,     0,  1142,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1176,     0,  1185,  1186,     0,  1188,
       0,   458,     0,     0,     0,  1227,     0,  1228,  1229,     0,
       0,     0,     0,  1258,     0,     0,     0,   454,   454,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   454,
     454,     0,   454,     0,   454,     0,   679,     0,     0,   679,
       0,     0,     0,     0,     0,   455,     0,     0,     0,   455,
       0,   458,     0,     0,     0,     0,     0,     0,   457,     0,
       0,     0,   455,     0,   455,     0,     0,     0,   455,     0,
       0,   457,     0,   454,     0,   454,   454,     0,   457,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,   454,     0,   454,   454,   454,     0,     0,
     454,     0,   106,     0,     0,     3,   454,     0,   107,     0,
       4,   458,   108,     0,     0,     6,     0,     0,   457,     0,
       0,   454,     0,   109,   110,     0,   111,     8,   454,    10,
     454,   454,     0,   112,    12,     0,     0,   113,     0,   454,
       0,   454,   454,     0,   454,     0,   454,     0,    14,     0,
     454,     0,   454,   454,     0,     1,   455,     0,   454,   455,
       0,     0,   455,     0,     0,   106,     0,     0,     3,     0,
       0,   107,     0,     4,     0,   108,     0,     0,     6,     0,
       0,     7,     0,     0,     0,     0,   109,   110,     0,   111,
       8,     9,   214,   215,    11,   677,   112,    12,     0,     0,
     113,     0,   455,   455,   455,     0,    41,     0,     0,     0,
       1,    14,     0,     0,   455,   455,     0,   455,    16,   455,
       0,     0,     0,     3,     0,     0,     0,     0,     4,     0,
      64,   456,     5,     6,     0,   456,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     9,    10,   456,    11,
     456,     0,    12,     0,   456,     0,     0,     0,   455,   216,
     455,   455,     0,   218,    13,   458,    14,     0,     0,    41,
       0,     0,    15,    16,     0,     0,     0,     0,   458,     0,
       0,     0,     0,     0,     0,   458,     0,     0,   455,     0,
     455,   455,   455,     0,     0,   455,     0,     0,     0,     0,
       0,   455,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   455,     0,    17,     0,
       0,     0,     0,   455,     0,   455,   455,     0,     0,     0,
       0,     0,     0,     0,   455,   458,   455,   455,     0,   455,
       0,   455,     0,     0,     0,   455,     0,   455,   455,     1,
       0,     0,   456,   455,     0,   456,     0,     0,   456,   106,
       0,     0,     3,     0,     0,   107,     0,     4,     0,   108,
       0,     0,     6,     0,     0,    56,     0,     0,   457,     0,
     109,   110,   457,   111,     8,    57,    10,   215,    58,     0,
     112,    12,     0,     0,   113,   457,     0,   457,   456,   456,
     456,   457,     0,     0,     0,    14,     0,     0,     1,     0,
     456,   456,    16,   456,     0,   456,     2,     0,     0,     0,
       0,     3,     0,     0,    64,     0,     4,     0,     0,     0,
       5,     6,     0,     0,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     9,    10,     0,    11,     0,     0,
      12,   627,   627,     0,   456,     0,   456,   456,     0,     0,
       0,     0,    13,    41,    14,     0,     0,     0,     0,     0,
      15,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   456,     0,   456,   456,   456,     0,
       0,   456,     0,     0,     0,     0,     0,   456,     0,   457,
       0,     0,   457,     0,     0,   457,     0,     0,     0,     0,
       0,     0,   456,     0,     0,     0,    17,     0,     0,   456,
       0,   456,   456,     0,     0,     0,     0,     0,     0,     0,
     456,     0,   456,   456,     0,   456,     0,   456,     0,     0,
       0,   456,     0,   456,   456,   457,   457,   457,     0,   456,
     258,     0,     0,   627,   627,   627,   627,   457,   457,     0,
     457,     0,   457,     0,     0,     0,     0,     0,     0,     0,
       0,   293,     0,     0,     0,   300,     0,     0,   304,     0,
     306,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     628,   628,   328,     0,     0,   458,     0,     0,     0,   458,
       0,   457,     0,   457,   457,     0,     0,     0,     0,     0,
       0,     0,   458,     0,   458,     0,     0,     0,   458,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   457,     0,   457,   457,   457,     0,     0,   457,     0,
       0,     0,     0,     0,   457,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   457,
       0,     0,     0,   530,   531,     0,   457,     0,   457,   457,
       0,     0,     0,     0,     0,     0,     0,   457,     0,   457,
     457,     0,   457,     0,   457,     0,     0,     0,   457,     0,
     457,   457,   628,   628,   628,   628,   457,     0,   547,     0,
       0,   551,     0,   553,     0,   554,     0,   556,     0,   557,
       0,     0,     0,     0,     0,   852,   458,     0,     0,   458,
       0,     0,   458,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   585,     0,     0,     0,   592,     0,     0,
     596,     0,   598,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   458,   458,   458,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   458,   458,     0,   458,     0,   458,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,     0,   627,   627,   627,   627,   627,   627,   627,   627,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   458,     0,
     458,   458,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   458,     0,
     458,   458,   458,     0,   628,   458,     0,     0,     0,     0,
       0,   458,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   458,     0,     0,     0,
       0,     0,     0,   458,     0,   458,   458,     0,     0,     0,
       0,     0,     0,     0,   458,     0,   458,   458,     0,   458,
       0,   458,     0,   852,     0,   458,     0,   458,   458,     0,
       0,     0,     0,   458,     0,     0,     0,     0,     0,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
       0,   628,   628,   628,   628,   628,   628,   628,   628,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   745,     0,   747,     0,   748,     0,     0,   749,
       0,     0,     0,     0,     0,   627,   627,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     774,     0,     0,   778,     0,   780,     0,   781,     0,   783,
       0,   784,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,   353,   354,   355,   356,   357,  1164,   358,
       0,   359,   106,   360,     0,     3,   361,   362,   107,     0,
       4,   363,   108,     0,     0,     6,     0,  1165,     7,   364,
       0,     0,   628,   109,   110,   365,   111,     8,     9,    10,
     366,    11,     0,   112,    12,     0,     0,   113,     0,   367,
     368,     0,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,     0,
       0,   627,   627,     0,     0,     0,     0,     0,     0,   392,
     393,     0,     0,     0,   628,   628,     0,     0,     0,     0,
       0,     0,     1,     0,   394,     0,     0,     0,     0,     0,
     396,     0,   106,     0,     0,     3,   397,     0,   107,     0,
       4,     0,   108,     0,     0,     6,     0,     0,    56,     0,
       0,     0,     0,   109,   110,     0,   111,     8,    57,    10,
     936,    58,     0,   112,    12,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,   632,
       0,     0,     0,     0,     0,    16,     0,     0,     0,   949,
       0,   951,     0,   952,     0,     0,   953,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,   353,   354,   355,   356,   357,     0,   358,
       0,   359,   106,   360,     0,     3,   361,   362,   107,     0,
       4,   363,   108,     0,   627,     6,    41,     0,     7,   364,
     628,   628,     0,   109,   110,   365,   111,     8,     9,    10,
     366,    11,     0,   112,    12,     0,     0,   113,     0,   367,
     368,     0,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   392,
     393,     0,     0,     0,     0,     0,     0,   627,     0,     0,
       0,     0,     0,     0,   394,     0,     0,   395,     0,     0,
     396,     0,     0,     0,     0,     0,   397,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,   353,   354,   355,   356,   357,     0,   358,
       0,   359,   106,   360,  1052,     3,   361,   362,   107,     0,
       4,   363,   108,   628,  1054,     6,     0,     0,     7,   364,
       0,     0,     0,   109,   110,   365,   111,     8,     9,    10,
     366,    11,     0,   112,    12,     0,     0,   113,     0,   367,
     368,     0,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   392,
     393,     0,     0,     0,     0,     0,   628,     0,     0,     0,
       0,     0,     0,     0,   394,     0,  -493,     0,     0,     0,
     396,     0,     0,     0,     0,     0,   397,     0,     0,  1126,
       1,   353,   354,   355,   356,   357,     0,   358,     0,   359,
     106,   360,     0,     3,   699,   362,   107,     0,     4,   363,
     108,     0,     0,     6,     0,     0,     7,   364,     0,     0,
       0,   109,   110,   365,   111,     8,     9,    10,   366,    11,
       0,   112,    12,     0,     0,   113,     0,   700,   368,     0,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   392,   393,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   394,     0,     0,   701,     0,     0,   396,     0,
       0,     0,     0,     0,   397,     1,   353,   354,   355,   356,
     357,     0,   358,     0,   359,   106,   360,     0,     3,   361,
     362,   107,     0,     4,   363,   108,     0,     0,     6,     0,
       0,     7,   364,     0,     0,     0,   109,   110,   365,   111,
       8,     9,    10,   366,    11,     0,   112,    12,     0,     0,
     113,     0,   367,   368,     0,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,   355,
       0,     0,   392,   393,     0,     0,   106,     0,     0,     3,
     361,     0,   107,     0,     4,     0,   108,   394,     0,     6,
     901,     0,     0,   396,     0,     0,     0,   109,   110,   397,
     111,     8,     0,    10,   366,     0,     0,   112,    12,     0,
       0,   113,     0,   367,     0,     0,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   493,
     383,     0,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
     355,     0,     0,   392,   393,     0,     0,   106,     0,     0,
       3,   361,     0,   107,     0,     4,     0,   108,   394,     0,
       6,     0,     0,     0,   836,     0,     0,     0,   109,   110,
     397,   111,     8,     0,    10,   366,     0,     0,   112,    12,
       0,     0,   113,     0,   367,     0,     0,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     493,   383,     0,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,   355,     0,     0,   392,   393,     0,     0,   106,     0,
       0,     3,   361,     0,   107,     0,     4,     0,   108,   394,
       0,     6,     0,     0,     0,  1177,     0,     0,     0,   109,
     110,   397,   111,     8,     0,    10,   366,     0,     0,   112,
      12,     0,     0,   113,     0,   367,     0,     0,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   493,   383,     0,   385,   386,   387,   388,   389,   390,
     391,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   106,     0,     0,     3,     0,     0,   107,     0,
       4,     0,   108,     0,     0,     6,     0,     0,     7,     0,
     394,     0,     0,   109,   110,     0,   111,     8,     9,   214,
     215,    11,   397,   112,    12,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,    14,     0,
       0,     0,     0,     0,     0,    16,   106,     0,     0,     3,
       0,     0,   107,     0,     4,     0,   108,    64,     0,     6,
       0,     0,     7,     0,     0,     0,     0,   109,   110,     0,
     111,     8,     9,   214,   215,    11,     0,   112,    12,     0,
       0,   113,     0,     0,     0,     0,   216,   217,     0,     0,
     218,     0,    14,     0,     0,     0,    41,     1,     0,    16,
       0,     0,     0,     0,     0,     0,     0,   106,     0,     0,
       3,    64,     0,   107,     0,     4,     0,   108,     0,     0,
       6,     0,     0,     7,     0,     0,     0,     0,   109,   110,
       0,   111,     8,     9,   214,   215,    11,     0,   112,    12,
     216,   291,   113,     0,   218,     0,     0,     0,     0,     0,
      41,     1,     0,    14,     0,     0,     0,     0,     0,     0,
      16,   106,     0,     0,     3,     0,     0,   107,     0,     4,
       0,   108,    64,     0,     6,     0,     0,     7,     0,     0,
       0,     0,   109,   110,     0,   111,     8,     9,   214,   215,
      11,     0,   112,    12,     0,     0,   113,     0,     0,     0,
       0,   216,   463,     0,     0,   218,     0,    14,     0,     0,
       0,    41,     1,     0,    16,     0,     0,     0,     0,     0,
       0,     0,   106,     0,     0,     3,    64,     0,   107,     0,
       4,     0,   108,     0,     0,     6,     0,     0,     7,     0,
       0,     0,     0,   109,   110,     0,   111,     8,     9,    10,
     215,    11,     0,   112,    12,   216,   546,   113,     0,   218,
       1,     0,     0,     0,     0,    41,     0,     0,    14,     0,
     106,     0,     0,     3,     0,    16,   107,     0,     4,     0,
     108,     0,     0,     6,     0,     0,     7,    64,     0,     0,
       0,   109,   110,     0,   111,     8,     9,    10,   215,    11,
       0,   112,    12,     0,     0,   113,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,    14,   274,     0,     0,
     275,   106,     0,    16,     3,     0,    41,   107,     0,     4,
       0,   108,     0,     0,     6,    64,     0,     0,     0,     0,
       0,     1,   109,   110,     0,   111,     8,     0,    10,     0,
       0,   106,   112,    12,     3,     0,   113,   107,     0,     4,
       0,   108,     0,     0,     6,   541,     0,    14,   275,     0,
       0,     1,   109,   110,    41,   111,     8,     0,    10,     0,
       0,   106,   112,    12,     3,     0,   113,   107,     0,     4,
       0,   108,     0,     0,     6,     0,     0,    14,     0,     0,
       0,     0,   109,   110,     0,   111,     8,     0,    10,     0,
       0,     0,   112,    12,   691,     0,   113,     0,     0,     1,
       0,     0,     0,     0,     0,    41,     0,    14,     0,   106,
       0,     0,     3,     0,     0,   107,     0,     4,     0,   108,
       0,     0,     6,     0,   867,     0,     0,     0,     0,     1,
     109,   110,     0,   111,     8,    41,    10,     0,     0,   106,
     112,    12,     3,     0,   113,   107,     0,     4,     0,   108,
       0,     0,     6,     0,   881,    14,     0,     0,     0,     1,
     109,   110,     0,   111,     8,    41,    10,     0,     0,   106,
     112,    12,     3,     0,   113,   107,     0,     4,     0,   108,
       0,     0,     6,     0,     0,    14,   632,     0,     0,     0,
     109,   110,     0,   111,     8,     0,    10,     0,     0,     0,
     112,    12,   890,     0,   113,     0,     0,     1,     0,     0,
       0,     0,     0,    41,     0,    14,     0,   106,     0,     0,
       3,     0,     0,   107,     0,     4,     0,   108,     0,     0,
       6,     0,     0,     0,     0,     0,     0,     0,   109,   110,
       0,   111,     8,    41,    10,     0,     0,     0,   112,    12,
       0,     0,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1009,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,   353,   354,   355,   356,
     357,     0,   358,     0,   359,   106,   360,     0,     0,   361,
     362,   107,     0,     0,   363,   108,     0,     0,     0,     0,
       0,     0,   364,     0,     0,     0,   109,   110,   365,   111,
       0,     0,     0,   366,     0,     0,   112,     0,     0,     0,
     113,    41,   367,   368,     0,   369,   370,   371,   372,   373,
     374,   491,   492,   377,   378,   379,   380,   381,   493,   383,
     384,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   392,   393,     0,     0,   353,   354,   355,   356,
     357,     0,  1058,     0,   359,   106,   360,   394,     0,   361,
     362,   107,     0,   396,   363,   108,     0,     0,     0,   397,
       0,     0,   364,     0,     0,     0,   109,   110,   365,   111,
       0,     0,     0,   366,     0,     0,   112,     0,     0,     0,
     113,     0,   367,  1059,     0,   369,   370,   371,   372,   373,
     374,   491,   492,   377,   378,   379,   380,   381,   493,   383,
     384,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,     0,     0,   355,   490,     0,     0,     0,     0,     0,
     106,     0,   392,   393,   361,     0,   107,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,   394,     0,     0,
       0,   109,   110,   396,   111,     0,     0,     0,   366,   397,
       0,   112,     0,     0,     0,   113,     0,   367,     0,     0,
     369,   370,   371,   372,   373,   374,   491,   492,   377,   378,
     379,   380,   381,   493,   383,     0,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,   494,   495,     0,     0,
       0,     0,     0,     0,   355,   490,     0,   392,   393,   496,
     497,   106,     0,     0,     0,   361,     0,   107,     0,     0,
     363,   108,   498,     0,   885,  1012,     0,     0,     0,  1013,
       0,     0,   109,   110,   397,   111,     0,     0,     0,   366,
       0,     0,   112,     0,     0,     0,   113,     0,   367,     0,
       0,   369,   370,   371,   372,   373,   374,   491,   492,   377,
     378,   379,   380,   381,   493,   383,     0,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,   494,   495,     0,
       0,     0,     0,     0,     0,   355,   490,     0,   392,   393,
     496,   497,   106,     0,     0,     0,   361,     0,   107,     0,
       0,     0,   108,   498,     0,   216,     0,     0,     0,     0,
       0,     0,     0,   109,   110,   397,   111,     0,     0,     0,
     366,     0,     0,   112,     0,     0,     0,   113,     0,   367,
       0,     0,   369,   370,   371,   372,   373,   374,   491,   492,
     377,   378,   379,   380,   381,   493,   383,     0,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,   494,   495,
       0,     0,     0,     0,     0,     0,   355,   490,     0,   392,
     393,   496,   497,   106,     0,     0,     0,   361,     0,   107,
       0,     0,     0,   108,   498,   499,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,   397,   111,     0,     0,
       0,   366,     0,     0,   112,     0,     0,     0,   113,     0,
     367,     0,     0,   369,   370,   371,   372,   373,   374,   491,
     492,   377,   378,   379,   380,   381,   493,   383,     0,   385,
     386,   387,   388,   389,   390,   391,     0,     0,     0,   494,
     495,     0,     0,     0,     0,     0,     0,   355,   490,     0,
     392,   393,   496,   497,   106,     0,     0,     0,   361,     0,
     107,     0,     0,     0,   108,   498,     0,     0,     0,     0,
       0,   618,     0,     0,     0,   109,   110,   397,   111,     0,
       0,     0,   366,     0,     0,   112,     0,     0,     0,   113,
       0,   367,     0,     0,   369,   370,   371,   372,   373,   374,
     491,   492,   377,   378,   379,   380,   381,   493,   383,     0,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
     494,   495,     0,     0,     0,     0,     0,     0,   355,   490,
       0,   392,   393,   496,   497,   106,     0,     0,     0,   361,
       0,   107,     0,     0,     0,   108,   498,     0,     0,     0,
       0,   345,     0,     0,     0,     0,   109,   110,   397,   111,
       0,     0,     0,   366,     0,     0,   112,     0,     0,     0,
     113,     0,   367,     0,     0,   369,   370,   371,   372,   373,
     374,   491,   492,   377,   378,   379,   380,   381,   493,   383,
       0,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,   494,   495,     0,     0,     0,     0,     0,     0,   355,
     490,     0,   392,   393,   496,   497,   106,     0,     0,     0,
     361,     0,   107,     0,     0,     0,   108,   498,   830,     0,
       0,     0,     0,     0,     0,     0,     0,   109,   110,   397,
     111,     0,     0,     0,   366,     0,     0,   112,     0,     0,
       0,   113,     0,   367,     0,     0,   369,   370,   371,   372,
     373,   374,   491,   492,   377,   378,   379,   380,   381,   493,
     383,     0,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,   494,   495,     0,     0,     0,     0,     0,     0,
     355,   490,     0,   392,   393,   496,   497,   106,     0,     0,
       0,   361,     0,   107,     0,     0,     0,   108,   498,     0,
     885,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     397,   111,     0,     0,     0,   366,     0,     0,   112,     0,
       0,     0,   113,     0,   367,     0,     0,   369,   370,   371,
     372,   373,   374,   491,   492,   377,   378,   379,   380,   381,
     493,   383,     0,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,   494,   495,     0,     0,     0,     0,     0,
       0,   355,   490,     0,   392,   393,   496,   497,   106,     0,
       0,     0,   361,     0,   107,     0,     0,     0,   108,   498,
     960,     0,     0,     0,     0,     0,     0,     0,     0,   109,
     110,   397,   111,     0,     0,     0,   366,     0,     0,   112,
       0,     0,     0,   113,     0,   367,     0,     0,   369,   370,
     371,   372,   373,   374,   491,   492,   377,   378,   379,   380,
     381,   493,   383,     0,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,   494,   495,     0,     0,     0,     0,
       0,     0,   355,   490,     0,   392,   393,   496,   497,   106,
       0,     0,     0,   361,     0,   107,     0,     0,     0,   108,
     498,     0,     0,     0,     0,     0,   981,     0,     0,     0,
     109,   110,   397,   111,     0,     0,     0,   366,     0,     0,
     112,     0,     0,     0,   113,     0,   367,     0,     0,   369,
     370,   371,   372,   373,   374,   491,   492,   377,   378,   379,
     380,   381,   493,   383,     0,   385,   386,   387,   388,   389,
     390,   391,     0,     0,     0,   494,   495,     0,     0,     0,
       0,     0,     0,   355,   490,     0,   392,   393,   496,   497,
     106,     0,     0,     0,   361,     0,   107,     0,     0,     0,
     108,   498,  1021,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   110,   397,   111,     0,     0,     0,   366,     0,
       0,   112,     0,     0,     0,   113,     0,   367,     0,     0,
     369,   370,   371,   372,   373,   374,   491,   492,   377,   378,
     379,   380,   381,   493,   383,     0,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,   494,   495,     0,     0,
       0,     0,     0,     0,   355,   490,     0,   392,   393,   496,
     497,   106,     0,     0,     0,   361,     0,   107,     0,     0,
       0,   108,   498,  1023,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   110,   397,   111,     0,     0,     0,   366,
       0,     0,   112,     0,     0,     0,   113,     0,   367,     0,
       0,   369,   370,   371,   372,   373,   374,   491,   492,   377,
     378,   379,   380,   381,   493,   383,     0,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,   494,   495,     0,
       0,     0,     0,     0,     0,   355,   490,     0,   392,   393,
     496,   497,   106,     0,     0,     0,   361,     0,   107,     0,
       0,     0,   108,   498,  1074,     0,     0,     0,     0,     0,
       0,     0,     0,   109,   110,   397,   111,     0,     0,     0,
     366,     0,     0,   112,     0,     0,     0,   113,     0,   367,
       0,     0,   369,   370,   371,   372,   373,   374,   491,   492,
     377,   378,   379,   380,   381,   493,   383,     0,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,   494,   495,
       0,     0,     0,     0,     0,     0,   355,   490,     0,   392,
     393,   496,   497,   106,     0,     0,     0,   361,     0,   107,
       0,     0,     0,   108,   498,  1079,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,   397,   111,     0,     0,
       0,   366,     0,     0,   112,     0,     0,     0,   113,     0,
     367,     0,     0,   369,   370,   371,   372,   373,   374,   491,
     492,   377,   378,   379,   380,   381,   493,   383,     0,   385,
     386,   387,   388,   389,   390,   391,     0,     0,     0,   494,
     495,     0,     0,     0,     0,     0,     0,   355,   490,     0,
     392,   393,   496,   497,   106,     0,     0,     0,   361,     0,
     107,     0,     0,     0,   108,   498,  1083,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,   397,   111,     0,
       0,     0,   366,     0,     0,   112,     0,     0,     0,   113,
       0,   367,     0,     0,   369,   370,   371,   372,   373,   374,
     491,   492,   377,   378,   379,   380,   381,   493,   383,     0,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
     494,   495,     0,     0,     0,     0,     0,     0,   355,   490,
       0,   392,   393,   496,   497,   106,     0,     0,     0,   361,
       0,   107,     0,     0,     0,   108,   498,     0,     0,     0,
       0,     0,  1091,     0,     0,     0,   109,   110,   397,   111,
       0,     0,     0,   366,     0,     0,   112,     0,     0,     0,
     113,     0,   367,     0,     0,   369,   370,   371,   372,   373,
     374,   491,   492,   377,   378,   379,   380,   381,   493,   383,
       0,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,   494,   495,     0,     0,     0,     0,     0,     0,   355,
     490,     0,   392,   393,   496,   497,   106,     0,     0,     0,
     361,     0,   107,     0,     0,     0,   108,   498,  1098,     0,
       0,     0,     0,     0,     0,     0,     0,   109,   110,   397,
     111,     0,     0,     0,   366,     0,     0,   112,     0,     0,
       0,   113,     0,   367,     0,     0,   369,   370,   371,   372,
     373,   374,   491,   492,   377,   378,   379,   380,   381,   493,
     383,     0,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,   494,   495,     0,     0,     0,     0,     0,     0,
     355,   490,     0,   392,   393,   496,   497,   106,     0,     0,
       0,   361,     0,   107,     0,     0,     0,   108,   498,  1157,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     397,   111,     0,     0,     0,   366,     0,     0,   112,     0,
       0,     0,   113,     0,   367,     0,     0,   369,   370,   371,
     372,   373,   374,   491,   492,   377,   378,   379,   380,   381,
     493,   383,     0,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,   494,   495,     0,     0,     0,     0,     0,
       0,   355,   490,     0,   392,   393,   496,   497,   106,     0,
       0,     0,   361,     0,   107,     0,     0,     0,   108,   498,
    1159,     0,     0,     0,     0,     0,     0,     0,     0,   109,
     110,   397,   111,     0,     0,     0,   366,     0,     0,   112,
       0,     0,     0,   113,     0,   367,     0,     0,   369,   370,
     371,   372,   373,   374,   491,   492,   377,   378,   379,   380,
     381,   493,   383,     0,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,   494,   495,     0,     0,     0,     0,
       0,     0,   355,   490,     0,   392,   393,   496,   497,   106,
       0,     0,     0,   361,     0,   107,     0,     0,     0,   108,
     498,  1161,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   397,   111,     0,     0,     0,   366,     0,     0,
     112,     0,     0,     0,   113,     0,   367,     0,     0,   369,
     370,   371,   372,   373,   374,   491,   492,   377,   378,   379,
     380,   381,   493,   383,     0,   385,   386,   387,   388,   389,
     390,   391,     0,     0,     0,   494,   495,     0,     0,     0,
       0,     0,     0,   355,   490,     0,   392,   393,   496,   497,
     106,     0,     0,     0,   361,     0,   107,     0,     0,     0,
     108,   498,  1181,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   110,   397,   111,     0,     0,     0,   366,     0,
       0,   112,     0,     0,     0,   113,     0,   367,     0,     0,
     369,   370,   371,   372,   373,   374,   491,   492,   377,   378,
     379,   380,   381,   493,   383,     0,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,   494,   495,     0,     0,
       0,     0,     0,     0,   355,   490,     0,   392,   393,   496,
     497,   106,     0,     0,     0,   361,     0,   107,     0,     0,
       0,   108,   498,  1183,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   110,   397,   111,     0,     0,     0,   366,
       0,     0,   112,     0,     0,     0,   113,     0,   367,     0,
       0,   369,   370,   371,   372,   373,   374,   491,   492,   377,
     378,   379,   380,   381,   493,   383,     0,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,   494,   495,     0,
       0,     0,     0,     0,     0,   355,   490,     0,   392,   393,
     496,   497,   106,     0,     0,     0,   361,     0,   107,     0,
       0,     0,   108,   498,     0,     0,     0,     0,     0,  1221,
       0,     0,     0,   109,   110,   397,   111,     0,     0,     0,
     366,     0,     0,   112,     0,     0,     0,   113,     0,   367,
       0,     0,   369,   370,   371,   372,   373,   374,   491,   492,
     377,   378,   379,   380,   381,   493,   383,     0,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,   494,   495,
       0,     0,     0,     0,     0,     0,   355,   490,     0,   392,
     393,   496,   497,   106,     0,     0,     0,   361,     0,   107,
       0,     0,     0,   108,   498,     0,     0,     0,     0,     0,
    1255,     0,     0,     0,   109,   110,   397,   111,     0,     0,
       0,   366,     0,     0,   112,     0,     0,     0,   113,     0,
     367,     0,     0,   369,   370,   371,   372,   373,   374,   491,
     492,   377,   378,   379,   380,   381,   493,   383,     0,   385,
     386,   387,   388,   389,   390,   391,     0,     0,     0,   494,
     495,     0,     0,     0,     0,     0,     0,   355,   490,     0,
     392,   393,   496,   497,   106,     0,     0,     0,   361,     0,
     107,     0,     0,     0,   108,   498,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,   397,   111,     0,
       0,     0,   366,     0,     0,   112,     0,     0,     0,   113,
       0,   367,     0,     0,   369,   370,   371,   372,   373,   374,
     491,   492,   377,   378,   379,   380,   381,   493,   383,     0,
     385,   386,   387,   388,   389,   390,   391,     0,     0,   355,
     494,   495,     0,     0,     0,     0,   106,     0,     0,     0,
     361,     0,   107,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   498,   109,   110,     0,
     111,     0,     0,     0,   366,     0,     0,   112,   397,     0,
       0,   113,     0,   367,     0,     0,   369,   370,   371,   372,
     373,   374,   491,   492,   377,   378,   379,   380,   381,   493,
     383,     0,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,     0,   355,     0,     0,     0,     0,     0,
       0,   106,     0,   392,   393,   361,     0,   107,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,   394,  1085,
       0,     0,   109,   110,     0,   111,     0,     0,     0,   366,
     397,     0,   112,     0,     0,     0,   113,     0,   367,     0,
       0,   369,   370,   371,   372,   373,   374,   491,   492,   377,
     378,   379,   380,   381,   493,   383,     0,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,     0,     0,   355,
       0,     0,     0,     0,     0,     0,   106,     0,   392,   393,
     361,     0,   107,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,   394,  1144,     0,     0,   109,   110,     0,
     111,     0,     0,     0,   366,   397,     0,   112,     0,     0,
       0,   113,     0,   367,     0,     0,   369,   370,   371,   372,
     373,   374,   491,   492,   377,   378,   379,   380,   381,   493,
     383,     0,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,     0,   355,     0,     0,     0,     0,     0,
       0,   106,     0,   392,   393,   361,     0,   107,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,   394,  1146,
       0,     0,   109,   110,     0,   111,     0,     0,     0,   366,
     397,     0,   112,     0,     0,     0,   113,     0,   367,     0,
       0,   369,   370,   371,   372,   373,   374,   491,   492,   377,
     378,   379,   380,   381,   493,   383,     0,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,     0,     0,   355,
       0,     0,     0,     0,     0,     0,   106,     0,   392,   393,
     361,     0,   107,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,   394,  1190,     0,     0,   109,   110,     0,
     111,     0,     0,     0,   366,   397,     0,   112,     0,     0,
       0,   113,     0,   367,     0,     0,   369,   370,   371,   372,
     373,   374,   491,   492,   377,   378,   379,   380,   381,   493,
     383,     0,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,     0,   355,     0,     0,     0,     0,     0,
       0,   106,     0,   392,   393,   361,     0,   107,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,   394,  1252,
       0,     0,   109,   110,     0,   111,     0,     0,     0,   366,
     397,     0,   112,     0,     0,     0,   113,     0,   367,     0,
       0,   369,   370,   371,   372,   373,   374,   491,   492,   377,
     378,   379,   380,   381,   493,   383,     0,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,     0,     0,   355,
       0,     0,     0,     0,     0,     0,   106,     0,   392,   393,
     361,     0,   107,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,   394,  1266,     0,     0,   109,   110,     0,
     111,     0,     0,     0,   366,   397,     0,   112,     0,     0,
       0,   113,     0,   367,     0,     0,   369,   370,   371,   372,
     373,   374,   491,   492,   377,   378,   379,   380,   381,   493,
     383,     0,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,     0,   355,     0,     0,     0,     0,     0,
       0,   106,     0,   392,   393,   361,     0,   107,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,   394,  1268,
       0,     0,   109,   110,     0,   111,     0,     0,     0,   366,
     397,     0,   112,     0,     0,     0,   113,     0,   367,     0,
       0,   369,   370,   371,   372,   373,   374,   491,   492,   377,
     378,   379,   380,   381,   493,   383,     0,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,     0,     0,   355,
       0,     0,     0,     0,     0,     0,   106,     0,   392,   393,
     361,     0,   107,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,   394,  1277,     0,     0,   109,   110,     0,
     111,     0,     0,     0,   366,   397,     0,   112,     0,     0,
       0,   113,     0,   367,     0,     0,   369,   370,   371,   372,
     373,   374,   491,   492,   377,   378,   379,   380,   381,   493,
     383,     0,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   392,   393,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   394,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     397
};

static const yytype_int16 yycheck[] =
{
       2,   654,   480,     5,   398,     7,   679,     9,   216,    11,
     268,    13,   236,   126,    16,   480,   601,    20,   392,   393,
     693,   477,   654,   203,   656,   410,   281,   207,   310,   142,
     142,   289,   290,   313,   461,   636,   907,     6,   477,   640,
     562,    43,    79,   316,   157,   318,  1033,   654,    50,   857,
      83,   478,   165,   165,    56,    57,    58,    20,     6,   660,
      97,   280,    64,    65,    40,    98,   214,    69,   856,    90,
      17,   859,    74,   157,    76,    77,    78,    17,    99,    81,
      82,   229,    83,    19,    85,    87,    88,   154,    20,   643,
      36,   223,   159,    27,   161,  1168,    94,    98,     5,   163,
     164,    47,    48,   216,    78,    96,   117,   220,    64,     9,
      63,    20,     6,    59,    82,   106,    52,   119,   185,   117,
     494,   495,   496,   497,   126,     9,    58,    63,    28,   131,
     132,   105,   134,   281,  1207,   219,    43,   250,   250,    57,
     142,   117,   144,   111,    28,   182,    20,   279,   117,  1167,
     101,   184,    98,    99,   155,   157,    50,   113,   111,  1088,
     113,  1032,  1091,   165,   277,   249,   102,   114,   189,   117,
     117,    18,  1245,   107,   125,    82,   127,   117,  1165,   292,
     292,    88,     9,   184,   111,   186,   113,   995,    90,    91,
      92,   656,   276,   277,   196,   414,   198,    99,   107,  1217,
     873,    28,   410,   205,   271,   460,   273,   209,   108,   997,
       0,   157,   844,   215,   216,    62,   219,   219,   220,  1148,
     287,   223,    42,   117,   108,   227,   704,   683,   750,    49,
     752,   113,   754,   107,   756,   674,     9,   461,   462,    32,
     459,   795,   193,   194,   246,   684,   249,   249,   250,   219,
      43,  1238,    64,   692,   321,    28,   219,   481,   325,   686,
     327,   212,   647,   265,   266,   267,   168,   169,   105,   417,
     172,  1170,   480,   276,   276,   277,    96,   279,   280,   249,
     562,   108,   111,     6,   113,   540,   249,   189,   190,   191,
     292,   439,  1221,   573,    17,   575,   107,   410,   899,   900,
     111,   113,  1127,   904,   577,    94,   308,   309,   310,   311,
     312,    20,   460,   276,   105,  1214,   126,     9,   109,    42,
     539,   322,    63,   908,    33,  1254,  1255,    50,   117,    33,
     276,   277,   142,    20,    63,   108,    28,     6,     9,     6,
     107,  1270,  1167,   897,   898,  1170,    33,   157,    17,    58,
      17,   353,    33,   355,    58,   165,    18,    28,   360,   266,
     362,    63,    94,    25,   738,   739,   740,   480,   107,    78,
     111,    58,   113,    42,   981,    42,   983,    58,    81,   844,
     382,    50,   111,    50,   113,   117,    89,     6,   339,  1214,
     392,   393,   540,   295,   117,   398,   398,    78,    17,    58,
      62,   308,   309,    94,   311,   312,   107,    96,   410,   111,
     220,   113,   414,   967,   633,    59,   108,   106,   108,   973,
      58,   111,    66,    42,   978,   105,   117,   116,   330,   331,
     126,    50,   334,   113,   108,   398,   116,   108,   111,   647,
     250,   880,   112,   837,   117,   999,   142,   671,   117,   107,
     117,    53,    54,    55,    56,   113,   100,   459,   638,    33,
      62,   157,   642,   465,   466,   105,   468,   277,   107,   165,
     537,   112,   113,   113,   113,   477,   116,   479,   480,  1152,
    1133,  1088,   292,   109,  1091,   392,   393,   113,    77,   769,
     116,    82,   494,   495,   496,   497,   704,   105,   117,    90,
      91,  1133,   111,   107,   113,   113,   108,   687,   116,   113,
       3,   659,   579,  1035,   581,   107,   583,   112,   109,  1192,
     216,   113,   113,    16,   220,   116,  1133,   109,    21,    48,
     109,   113,   906,    26,   647,    77,    78,   539,   105,   107,
     111,  1148,   109,    85,    86,    38,   117,    40,    67,   103,
     104,   111,    45,   113,   250,   109,  1110,  1111,  1112,   113,
     562,   106,   116,   115,   103,   104,    59,   111,   120,   113,
     109,    90,    91,   480,   113,   105,   118,   116,    97,   109,
      99,   277,   101,   105,  1138,   107,  1140,   494,   495,   496,
     497,   704,    94,    95,    13,   111,   292,    99,   600,   108,
      19,   111,   111,   112,    23,   106,   125,   106,   117,   789,
     111,   112,   111,   793,  1221,    34,    35,   109,    37,   621,
     622,   113,    41,   112,   117,    44,   109,    90,    91,    48,
     113,   633,   634,    82,   636,   637,   109,   112,   640,   641,
     113,    90,    91,   645,   108,   647,   109,  1254,  1255,   168,
     113,   109,   654,   116,   656,   113,   106,   216,   660,   661,
     109,   111,   112,  1270,   113,   112,   113,   116,   117,   221,
     189,   190,   674,   675,   193,   678,   678,   679,   113,   109,
     964,   683,   684,   113,   143,   587,   116,   689,   147,   110,
     692,   693,    53,    54,    55,    56,   789,   108,   117,   251,
     793,    62,   704,   109,   771,    65,   105,   113,   107,   889,
     116,   117,   108,   105,   410,   107,   111,   109,   113,   721,
     722,   723,   724,   725,   726,   727,   728,   729,   730,   731,
     732,   733,   734,   735,   736,   737,   738,   739,   740,  1217,
     103,   104,    53,    54,    55,    56,   108,   108,   750,   656,
     752,    62,   754,   108,   756,   107,   111,   114,   357,   761,
     117,   105,   764,   765,   363,   364,   126,  1245,  1036,    82,
     466,  1039,   111,  1041,   113,  1043,   956,    90,    91,   959,
     113,   477,   142,   116,   480,   384,   111,  1045,   113,  1047,
     111,  1049,   113,  1051,   111,   394,   109,   157,   107,   113,
     113,   360,   116,   116,   117,   165,   728,   729,   730,   731,
      84,   330,   814,    87,   721,   722,   723,   724,   725,   726,
     727,   728,   729,   730,   731,   111,   733,   734,   735,   736,
     737,   738,   739,   740,   837,   837,  1016,   114,  1018,   108,
     117,   113,   844,   113,   116,   993,   116,  1131,   108,   209,
     402,   410,   113,   112,   406,   116,   216,   764,   765,   219,
     220,   114,   791,   223,   117,   794,   107,    65,   109,   108,
     216,   873,   874,   103,   104,   877,   103,   104,   880,   943,
     944,   945,   946,   108,    53,    54,    55,    56,   108,   249,
     250,    96,   894,    62,   100,   101,   102,   899,   900,   498,
      82,   105,   904,   105,   906,   907,    90,    91,    90,    91,
     111,   112,   113,    90,    91,   467,   276,   277,   470,   279,
     105,   480,    90,    91,  1072,  1105,   113,   109,   126,    92,
      93,   113,   292,   105,   116,  1219,  1220,   844,   105,   108,
    1224,   111,   112,   113,   142,   111,   112,   964,   105,   501,
     108,   647,    53,    54,    55,    56,   111,   112,   654,   157,
     656,    62,   964,   111,   112,   113,   968,   165,  1252,   971,
     972,   111,   112,   113,   976,   977,   111,   112,   674,  1263,
     117,  1265,  1266,   105,  1268,   987,   111,   112,   684,   116,
    1274,   111,  1276,  1277,   111,   355,   692,   109,  1282,   906,
     907,   105,  1004,   111,   112,   113,    82,   108,   704,  1217,
     609,   209,   611,   612,   360,   111,   112,   216,   216,   111,
     112,   219,   220,   103,   623,   223,   111,   112,   113,    27,
    1032,  1033,   105,  1035,   111,   112,   635,  1245,   398,    88,
     639,   106,    90,    91,   111,   112,   113,   964,  1196,   112,
     410,   249,   250,   605,   606,    97,   655,   111,   112,   113,
      98,   109,    96,   662,   410,   113,   113,   666,   116,   117,
    1218,   938,   939,   940,   626,   634,   111,   112,   276,   277,
     108,   279,   111,  1085,   733,   734,   735,   105,   647,   111,
     112,   690,  1094,   109,   292,   654,   111,   112,   650,   111,
     112,   111,   112,    51,  1217,   465,   466,    82,    83,   708,
     726,   727,   736,   737,  1131,   111,   111,   477,   717,   111,
     480,   720,    42,   111,   106,  1032,  1033,    42,   106,  1131,
    1132,  1133,  1245,   112,   480,   112,   112,   106,   498,   691,
     112,  1143,  1144,    13,  1146,   704,  1149,  1149,   844,    19,
    1152,   703,   105,    23,   108,   106,   113,     3,   110,   106,
     106,   360,   714,  1165,    34,    35,   106,    37,   105,   105,
      16,   106,   105,    42,    44,    21,   110,   105,    48,    42,
      26,   877,   106,    29,   880,  1187,    82,  1189,  1190,   788,
    1192,  1193,    38,    39,    40,   112,    42,   111,   797,    45,
     398,   106,  1219,  1220,   106,   111,    43,  1224,    32,   110,
     105,   410,   410,    59,  1131,  1217,   106,  1219,  1220,    17,
      66,   360,  1224,   106,   113,   106,   108,   106,  1230,    82,
     110,   106,   216,   111,   111,  1252,  1238,   836,   105,   791,
     113,   106,   794,  1245,   108,   111,  1263,   117,  1265,  1266,
    1252,  1268,   112,   108,   106,   111,   106,  1274,  1165,  1276,
    1277,  1263,   105,  1265,  1266,  1282,  1268,   465,   466,   107,
     105,   105,  1274,    24,  1276,  1277,    24,   105,    82,   477,
    1282,   480,   480,   106,   106,   105,   885,   647,   634,   106,
     105,   112,   106,   106,   654,   847,   656,   106,   106,   111,
     498,   647,  1219,  1220,   111,   111,   111,  1224,   654,   106,
     113,    97,   106,   106,   674,   111,   111,    82,   678,   106,
     111,   106,   106,   683,   684,   106,   106,   106,   111,   106,
     106,  1238,   692,   111,    83,  1252,   111,   111,   890,    82,
     892,   893,   111,     3,   704,   111,  1263,    24,  1265,  1266,
     106,  1268,   111,   106,    65,    25,    16,  1274,   704,  1276,
    1277,    21,   106,   199,   106,  1282,    26,   966,   715,    29,
     878,   923,   732,   925,   895,   247,   360,   165,    38,    39,
      40,   144,    42,   210,  1239,    45,    13,   986,   984,  1194,
     844,   718,    19,   606,    18,   498,    23,   198,  1094,    59,
      81,   689,   220,   690,   894,   964,    66,    34,    35,   968,
      37,   469,   877,   144,   467,   126,   277,    44,  1103,   209,
     219,    48,   981,  1167,   983,  1113,   410,   216,   987,  1238,
    1218,   142,   859,  1133,  1149,   634,   659,  1133,   721,   844,
     722,   725,   723,    -1,   724,    -1,   157,    -1,   647,   647,
      -1,   111,    -1,    -1,   165,   654,   654,    -1,   656,  1131,
      -1,    -1,    -1,    -1,    -1,  1017,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   674,   837,    -1,   106,
     678,    -1,    -1,    -1,   844,   683,   684,    -1,    -1,    -1,
     117,    -1,    -1,    -1,   692,   634,   480,    -1,   209,    -1,
      -1,    -1,    -1,    -1,  1103,   704,   704,    -1,   219,   220,
      -1,    -1,   223,    -1,    -1,    -1,    -1,   877,    -1,    -1,
     880,  1217,    -1,    -1,    -1,    -1,  1085,    -1,    -1,  1088,
    1129,  1130,  1091,    -1,   732,  1134,    -1,    -1,   249,   250,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1219,  1220,  1245,
      -1,    -1,  1224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   276,   277,    -1,   279,    -1,
      -1,   360,  1131,  1132,  1133,    -1,    -1,    -1,  1177,    -1,
    1252,   292,    -1,    -1,  1143,  1144,    -1,  1146,    -1,  1148,
      -1,  1263,    -1,  1265,  1266,    -1,  1268,    -1,    -1,    -1,
      -1,    -1,  1274,    -1,  1276,  1277,    -1,    -1,    -1,    -1,
    1282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   964,  1218,
      -1,   410,   968,   216,  1223,    -1,    -1,    -1,  1187,    -1,
    1189,  1190,    -1,    -1,    -1,   981,    -1,   983,    -1,   837,
      -1,   987,    -1,    -1,    -1,    -1,   844,    -1,    -1,    -1,
     634,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1217,    -1,
    1219,  1220,  1221,   647,    -1,  1224,    -1,    -1,    -1,    -1,
     654,  1230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   877,
      -1,    -1,   880,    -1,    -1,    -1,  1245,    -1,    -1,    -1,
      -1,   480,    -1,  1252,    -1,  1254,  1255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1263,    -1,  1265,  1266,    -1,  1268,
      -1,  1270,    -1,    -1,    -1,  1274,    -1,  1276,  1277,    -1,
     704,    -1,    -1,  1282,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1085,
      -1,    -1,  1088,    -1,    -1,  1091,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   465,   466,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   964,   477,   360,    -1,   968,
     216,    -1,    -1,  1133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   981,    -1,   983,  1131,  1132,  1133,   987,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,  1143,  1144,    -1,
    1146,    -1,  1148,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    21,    -1,    -1,   410,    25,    26,
      -1,    -1,    29,    -1,    -1,   964,    -1,    -1,    -1,   968,
      -1,    38,    39,    40,    -1,    42,    -1,    -1,    45,    -1,
      -1,  1187,    -1,  1189,  1190,   634,    -1,    -1,   987,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,  1217,   647,    66,
      -1,    -1,    -1,    -1,    -1,   654,    -1,    -1,    -1,    -1,
      -1,  1217,    -1,  1219,  1220,  1221,    -1,    -1,  1224,    -1,
      -1,    -1,    -1,    -1,  1230,  1245,  1085,   480,    -1,  1088,
      -1,    -1,  1091,    -1,    -1,    -1,    -1,    -1,    -1,  1245,
      -1,    -1,    -1,    -1,   111,    -1,  1252,    -1,  1254,  1255,
      -1,    -1,    -1,    -1,   360,   704,    -1,  1263,    -1,  1265,
    1266,    -1,  1268,    -1,  1270,    -1,    -1,    -1,  1274,    -1,
    1276,  1277,  1131,  1132,  1133,  1133,  1282,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1143,  1144,  1085,  1146,    -1,  1148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   674,   410,    -1,    -1,   678,    -1,    -1,
      -1,    -1,   683,   684,    -1,    -1,    -1,    -1,    -1,    -1,
     964,   692,    -1,    -1,   968,    -1,    -1,   216,  1187,    -1,
    1189,  1190,  1131,  1132,    -1,    -1,    -1,   981,    -1,   983,
      -1,    -1,    -1,   987,  1143,  1144,    -1,  1146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1217,  1217,
    1219,  1220,  1221,    -1,    -1,  1224,    -1,    -1,    -1,    -1,
      -1,  1230,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,
      -1,   634,    -1,    -1,    -1,    -1,  1245,  1245,  1187,    -1,
    1189,  1190,    -1,  1252,   647,  1254,  1255,    -1,    -1,    -1,
      -1,   654,    -1,    -1,  1263,    -1,  1265,  1266,    -1,  1268,
      -1,  1270,    -1,    -1,    -1,  1274,    -1,  1276,  1277,    -1,
    1219,  1220,    -1,  1282,    -1,  1224,    -1,    -1,    -1,    -1,
      -1,  1230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1085,    -1,    -1,  1088,    -1,    -1,  1091,    -1,    -1,
      -1,   704,    -1,  1252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1263,    -1,  1265,  1266,    -1,  1268,
      -1,   360,    -1,    -1,    -1,  1274,    -1,  1276,  1277,    -1,
      -1,    -1,    -1,  1282,    -1,    -1,    -1,  1131,  1132,  1133,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1143,
    1144,    -1,  1146,    -1,  1148,    -1,   877,    -1,    -1,   880,
      -1,    -1,    -1,    -1,    -1,   964,    -1,    -1,    -1,   968,
      -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,   634,    -1,
      -1,    -1,   981,    -1,   983,    -1,    -1,    -1,   987,    -1,
      -1,   647,    -1,  1187,    -1,  1189,  1190,    -1,   654,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,  1217,    -1,  1219,  1220,  1221,    -1,    -1,
    1224,    -1,    13,    -1,    -1,    16,  1230,    -1,    19,    -1,
      21,   480,    23,    -1,    -1,    26,    -1,    -1,   704,    -1,
      -1,  1245,    -1,    34,    35,    -1,    37,    38,  1252,    40,
    1254,  1255,    -1,    44,    45,    -1,    -1,    48,    -1,  1263,
      -1,  1265,  1266,    -1,  1268,    -1,  1270,    -1,    59,    -1,
    1274,    -1,  1276,  1277,    -1,     3,  1085,    -1,  1282,  1088,
      -1,    -1,  1091,    -1,    -1,    13,    -1,    -1,    16,    -1,
      -1,    19,    -1,    21,    -1,    23,    -1,    -1,    26,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,   106,    44,    45,    -1,    -1,
      48,    -1,  1131,  1132,  1133,    -1,   117,    -1,    -1,    -1,
       3,    59,    -1,    -1,  1143,  1144,    -1,  1146,    66,  1148,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    21,    -1,
      78,   964,    25,    26,    -1,   968,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,   981,    42,
     983,    -1,    45,    -1,   987,    -1,    -1,    -1,  1187,   107,
    1189,  1190,    -1,   111,    57,   634,    59,    -1,    -1,   117,
      -1,    -1,    65,    66,    -1,    -1,    -1,    -1,   647,    -1,
      -1,    -1,    -1,    -1,    -1,   654,    -1,    -1,  1217,    -1,
    1219,  1220,  1221,    -1,    -1,  1224,    -1,    -1,    -1,    -1,
      -1,  1230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1245,    -1,   111,    -1,
      -1,    -1,    -1,  1252,    -1,  1254,  1255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1263,   704,  1265,  1266,    -1,  1268,
      -1,  1270,    -1,    -1,    -1,  1274,    -1,  1276,  1277,     3,
      -1,    -1,  1085,  1282,    -1,  1088,    -1,    -1,  1091,    13,
      -1,    -1,    16,    -1,    -1,    19,    -1,    21,    -1,    23,
      -1,    -1,    26,    -1,    -1,    29,    -1,    -1,   964,    -1,
      34,    35,   968,    37,    38,    39,    40,    41,    42,    -1,
      44,    45,    -1,    -1,    48,   981,    -1,   983,  1131,  1132,
    1133,   987,    -1,    -1,    -1,    59,    -1,    -1,     3,    -1,
    1143,  1144,    66,  1146,    -1,  1148,    11,    -1,    -1,    -1,
      -1,    16,    -1,    -1,    78,    -1,    21,    -1,    -1,    -1,
      25,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    -1,    42,    -1,    -1,
      45,   392,   393,    -1,  1187,    -1,  1189,  1190,    -1,    -1,
      -1,    -1,    57,   117,    59,    -1,    -1,    -1,    -1,    -1,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1217,    -1,  1219,  1220,  1221,    -1,
      -1,  1224,    -1,    -1,    -1,    -1,    -1,  1230,    -1,  1085,
      -1,    -1,  1088,    -1,    -1,  1091,    -1,    -1,    -1,    -1,
      -1,    -1,  1245,    -1,    -1,    -1,   111,    -1,    -1,  1252,
      -1,  1254,  1255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1263,    -1,  1265,  1266,    -1,  1268,    -1,  1270,    -1,    -1,
      -1,  1274,    -1,  1276,  1277,  1131,  1132,  1133,    -1,  1282,
     146,    -1,    -1,   494,   495,   496,   497,  1143,  1144,    -1,
    1146,    -1,  1148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   167,    -1,    -1,    -1,   171,    -1,    -1,   174,    -1,
     176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     392,   393,   188,    -1,    -1,   964,    -1,    -1,    -1,   968,
      -1,  1187,    -1,  1189,  1190,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   981,    -1,   983,    -1,    -1,    -1,   987,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1217,    -1,  1219,  1220,  1221,    -1,    -1,  1224,    -1,
      -1,    -1,    -1,    -1,  1230,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1245,
      -1,    -1,    -1,   259,   260,    -1,  1252,    -1,  1254,  1255,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1263,    -1,  1265,
    1266,    -1,  1268,    -1,  1270,    -1,    -1,    -1,  1274,    -1,
    1276,  1277,   494,   495,   496,   497,  1282,    -1,   294,    -1,
      -1,   297,    -1,   299,    -1,   301,    -1,   303,    -1,   305,
      -1,    -1,    -1,    -1,    -1,   656,  1085,    -1,    -1,  1088,
      -1,    -1,  1091,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   329,    -1,    -1,    -1,   333,    -1,    -1,
     336,    -1,   338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1131,  1132,  1133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1143,  1144,    -1,  1146,    -1,  1148,
     721,   722,   723,   724,   725,   726,   727,   728,   729,   730,
     731,    -1,   733,   734,   735,   736,   737,   738,   739,   740,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1187,    -1,
    1189,  1190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1217,    -1,
    1219,  1220,  1221,    -1,   656,  1224,    -1,    -1,    -1,    -1,
      -1,  1230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1245,    -1,    -1,    -1,
      -1,    -1,    -1,  1252,    -1,  1254,  1255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1263,    -1,  1265,  1266,    -1,  1268,
      -1,  1270,    -1,   844,    -1,  1274,    -1,  1276,  1277,    -1,
      -1,    -1,    -1,  1282,    -1,    -1,    -1,    -1,    -1,   721,
     722,   723,   724,   725,   726,   727,   728,   729,   730,   731,
      -1,   733,   734,   735,   736,   737,   738,   739,   740,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   548,    -1,   550,    -1,   552,    -1,    -1,   555,
      -1,    -1,    -1,    -1,    -1,   906,   907,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     586,    -1,    -1,   589,    -1,   591,    -1,   593,    -1,   595,
      -1,   597,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    19,    -1,
      21,    22,    23,    -1,    -1,    26,    -1,    28,    29,    30,
      -1,    -1,   844,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,    -1,    48,    -1,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,  1032,  1033,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    -1,    -1,    -1,   906,   907,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,   105,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    13,    -1,    -1,    16,   117,    -1,    19,    -1,
      21,    -1,    23,    -1,    -1,    26,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
     746,    42,    -1,    44,    45,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,   775,
      -1,   777,    -1,   779,    -1,    -1,   782,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    19,    -1,
      21,    22,    23,    -1,  1165,    26,   117,    -1,    29,    30,
    1032,  1033,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,    -1,    48,    -1,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    -1,    -1,    -1,    -1,    -1,    -1,  1238,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    12,    13,    14,   950,    16,    17,    18,    19,    -1,
      21,    22,    23,  1165,   960,    26,    -1,    -1,    29,    30,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,    -1,    48,    -1,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    -1,    -1,    -1,    -1,    -1,  1238,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,  1055,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    19,    -1,    21,    22,
      23,    -1,    -1,    26,    -1,    -1,    29,    30,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    44,    45,    -1,    -1,    48,    -1,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,   117,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    12,    13,    14,    -1,    16,    17,
      18,    19,    -1,    21,    22,    23,    -1,    -1,    26,    -1,
      -1,    29,    30,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    44,    45,    -1,    -1,
      48,    -1,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,     6,
      -1,    -1,    90,    91,    -1,    -1,    13,    -1,    -1,    16,
      17,    -1,    19,    -1,    21,    -1,    23,   105,    -1,    26,
     108,    -1,    -1,   111,    -1,    -1,    -1,    34,    35,   117,
      37,    38,    -1,    40,    41,    -1,    -1,    44,    45,    -1,
      -1,    48,    -1,    50,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,
       6,    -1,    -1,    90,    91,    -1,    -1,    13,    -1,    -1,
      16,    17,    -1,    19,    -1,    21,    -1,    23,   105,    -1,
      26,    -1,    -1,    -1,   111,    -1,    -1,    -1,    34,    35,
     117,    37,    38,    -1,    40,    41,    -1,    -1,    44,    45,
      -1,    -1,    48,    -1,    50,    -1,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,     6,    -1,    -1,    90,    91,    -1,    -1,    13,    -1,
      -1,    16,    17,    -1,    19,    -1,    21,    -1,    23,   105,
      -1,    26,    -1,    -1,    -1,   111,    -1,    -1,    -1,    34,
      35,   117,    37,    38,    -1,    40,    41,    -1,    -1,    44,
      45,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    16,    -1,    -1,    19,    -1,
      21,    -1,    23,    -1,    -1,    26,    -1,    -1,    29,    -1,
     105,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,   117,    44,    45,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    13,    -1,    -1,    16,
      -1,    -1,    19,    -1,    21,    -1,    23,    78,    -1,    26,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    -1,    44,    45,    -1,
      -1,    48,    -1,    -1,    -1,    -1,   107,   108,    -1,    -1,
     111,    -1,    59,    -1,    -1,    -1,   117,     3,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      16,    78,    -1,    19,    -1,    21,    -1,    23,    -1,    -1,
      26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    -1,    44,    45,
     107,   108,    48,    -1,   111,    -1,    -1,    -1,    -1,    -1,
     117,     3,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    13,    -1,    -1,    16,    -1,    -1,    19,    -1,    21,
      -1,    23,    78,    -1,    26,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    -1,    44,    45,    -1,    -1,    48,    -1,    -1,    -1,
      -1,   107,   108,    -1,    -1,   111,    -1,    59,    -1,    -1,
      -1,   117,     3,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    16,    78,    -1,    19,    -1,
      21,    -1,    23,    -1,    -1,    26,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,   107,   108,    48,    -1,   111,
       3,    -1,    -1,    -1,    -1,   117,    -1,    -1,    59,    -1,
      13,    -1,    -1,    16,    -1,    66,    19,    -1,    21,    -1,
      23,    -1,    -1,    26,    -1,    -1,    29,    78,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      -1,    44,    45,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    59,   108,    -1,    -1,
     111,    13,    -1,    66,    16,    -1,   117,    19,    -1,    21,
      -1,    23,    -1,    -1,    26,    78,    -1,    -1,    -1,    -1,
      -1,     3,    34,    35,    -1,    37,    38,    -1,    40,    -1,
      -1,    13,    44,    45,    16,    -1,    48,    19,    -1,    21,
      -1,    23,    -1,    -1,    26,   108,    -1,    59,   111,    -1,
      -1,     3,    34,    35,   117,    37,    38,    -1,    40,    -1,
      -1,    13,    44,    45,    16,    -1,    48,    19,    -1,    21,
      -1,    23,    -1,    -1,    26,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    -1,    40,    -1,
      -1,    -1,    44,    45,   106,    -1,    48,    -1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,   117,    -1,    59,    -1,    13,
      -1,    -1,    16,    -1,    -1,    19,    -1,    21,    -1,    23,
      -1,    -1,    26,    -1,   106,    -1,    -1,    -1,    -1,     3,
      34,    35,    -1,    37,    38,   117,    40,    -1,    -1,    13,
      44,    45,    16,    -1,    48,    19,    -1,    21,    -1,    23,
      -1,    -1,    26,    -1,   106,    59,    -1,    -1,    -1,     3,
      34,    35,    -1,    37,    38,   117,    40,    -1,    -1,    13,
      44,    45,    16,    -1,    48,    19,    -1,    21,    -1,    23,
      -1,    -1,    26,    -1,    -1,    59,    60,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    -1,    40,    -1,    -1,    -1,
      44,    45,   106,    -1,    48,    -1,    -1,     3,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    59,    -1,    13,    -1,    -1,
      16,    -1,    -1,    19,    -1,    21,    -1,    23,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,   117,    40,    -1,    -1,    -1,    44,    45,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   106,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    -1,     4,     5,     6,     7,
       8,    -1,    10,    -1,    12,    13,    14,    -1,    -1,    17,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    36,    37,
      -1,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,
      48,   117,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    -1,    -1,     4,     5,     6,     7,
       8,    -1,    10,    -1,    12,    13,    14,   105,    -1,    17,
      18,    19,    -1,   111,    22,    23,    -1,    -1,    -1,   117,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    36,    37,
      -1,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,
      48,    -1,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    90,    91,    17,    -1,    19,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    34,    35,   111,    37,    -1,    -1,    -1,    41,   117,
      -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,    -1,    90,    91,    92,
      93,    13,    -1,    -1,    -1,    17,    -1,    19,    -1,    -1,
      22,    23,   105,    -1,   107,   108,    -1,    -1,    -1,   112,
      -1,    -1,    34,    35,   117,    37,    -1,    -1,    -1,    41,
      -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,    -1,    90,    91,
      92,    93,    13,    -1,    -1,    -1,    17,    -1,    19,    -1,
      -1,    -1,    23,   105,    -1,   107,    -1,    -1,    -1,    -1,
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
       0,     3,    11,    16,    21,    25,    26,    29,    38,    39,
      40,    42,    45,    57,    59,    65,    66,   111,   125,   126,
     134,   167,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   203,   204,   273,   280,   281,   290,   291,
     308,   117,   168,    40,   168,   181,   168,   168,   168,   168,
      57,   168,   126,   187,   193,   192,    29,    39,    42,   280,
     308,     0,   125,   126,    78,   105,   237,   282,   111,   113,
     127,   168,   181,   111,   113,   111,   113,    20,   107,   240,
     274,    33,    58,   237,   292,   309,   310,    33,    58,   205,
     237,   239,   240,   242,   107,   127,   168,   168,   168,   168,
     237,   282,   126,   168,   177,   238,    13,    19,    23,    34,
      35,    37,    44,    48,   106,   168,   173,   174,   175,   251,
     252,   253,   283,   284,   285,   282,   107,   240,   286,   168,
     111,   113,   113,   111,   113,    94,   168,    94,   168,   168,
     241,   108,   111,   112,   144,   145,   168,   275,   278,   279,
     274,   241,   168,   181,   296,   309,   310,   107,   311,   294,
     310,   293,   168,   168,   181,   107,   243,   213,   239,   240,
     242,   209,   240,   242,   207,   242,   206,   194,   195,   107,
     107,   127,   240,   274,   237,   300,   309,   310,   221,   237,
     239,   240,   242,   282,   240,   286,    33,   178,   112,   135,
     136,    77,   109,   120,   121,   114,   168,   120,   106,   112,
     146,   147,   240,   286,    40,    41,   107,   108,   111,   134,
     148,   168,   203,   237,   244,   245,   246,   251,   254,   255,
     256,   266,   267,   268,   270,   287,   288,   289,   290,   317,
     286,   168,    94,    94,   111,   111,   112,   137,   138,   134,
     139,   168,   244,   108,   279,   145,   278,   105,   243,   276,
     277,   108,   279,   112,   108,   113,   112,   113,   132,   133,
     311,   298,   310,   297,   108,   111,   134,   149,   203,   237,
     251,   255,   290,   312,   313,   314,   311,   295,   311,   132,
     132,   108,   139,   243,   217,   240,   242,   215,   242,   214,
     243,   211,   242,   210,   243,   208,   243,   108,    53,    54,
      55,    56,    62,   128,   202,   196,   197,   198,   199,   107,
     274,   304,   309,   310,   311,   302,   310,   301,   243,   229,
     239,   240,   242,   225,   240,   242,   223,   242,   222,   240,
     286,   286,   168,   177,   136,   110,   121,   168,   284,   147,
     286,   317,   168,     4,     5,     6,     7,     8,    10,    12,
      14,    17,    18,    22,    30,    36,    41,    50,    51,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    90,    91,   105,   108,   111,   117,   134,   168,
     169,   170,   181,   182,   203,   251,   252,   253,   291,   318,
     319,   320,   321,   322,   323,   324,   326,   327,   328,   329,
     331,   332,   333,   334,   336,   337,   344,   346,   347,   349,
     350,   355,   356,   358,   359,   360,   361,   362,   363,   365,
     367,   375,   379,   380,   381,   382,   383,   385,   386,   387,
     389,   390,   394,   395,   410,   411,   413,   414,   415,   251,
     255,   270,   288,   108,   287,   105,   269,   168,   251,   256,
     168,   247,   248,   249,   111,   265,   317,   105,   257,    27,
     107,   262,   271,   271,   111,   111,   168,   138,   244,   108,
       7,    59,    60,    66,    79,    80,    92,    93,   105,   106,
     168,   252,   253,   382,   387,   388,   392,   393,   394,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     243,   243,   108,   168,   181,   133,   311,   299,   311,   251,
     255,   108,   312,   247,   265,   311,   108,   243,   219,   242,
     218,   243,   216,   243,   243,   212,   243,   243,   168,   181,
     168,   181,   129,   167,   168,   180,   168,   181,   168,   181,
     108,   202,   108,   128,   108,   128,   200,   201,   311,   306,
     310,   305,   311,   303,   311,   243,   233,   240,   242,   231,
     242,   230,   243,   227,   242,   226,   243,   224,   243,   286,
      96,   122,   179,   111,   168,   168,   172,   252,   384,   105,
     392,   105,   105,   168,   324,   111,   168,   392,   111,   392,
     113,   113,   116,   105,   392,   168,   181,   385,   386,   409,
     409,   392,    60,   323,    82,   109,   113,   116,   120,   109,
     113,   116,   120,   105,   113,   116,   108,   150,   319,   111,
     168,   247,   317,   111,   105,    82,   105,   317,   366,   376,
     113,   116,   109,   103,   104,   171,   396,    90,    91,   247,
     265,   262,   271,   271,   123,   251,   258,   106,   134,   251,
     259,   260,   261,   105,   269,   168,   257,   120,   111,   112,
     103,   106,   123,   251,   259,   262,   168,   263,   264,    17,
      50,   108,   168,   181,   272,   318,   379,   271,   105,   409,
     409,   409,   409,   172,   252,   253,   106,   112,   164,   165,
      81,    89,    88,    97,    98,    96,    84,    87,    77,    78,
      85,    86,   118,   100,   101,   102,    92,    93,    94,    95,
      99,   311,   247,   265,   111,   243,   220,   243,   243,   243,
      63,   111,    63,   111,    63,   111,    63,   111,   167,   180,
     111,   113,   111,   111,    64,    64,   108,   108,   108,   128,
     311,   307,   311,   311,   243,   235,   242,   234,   243,   232,
     243,   243,   228,   243,   243,   168,   179,   111,   109,   120,
     127,   166,   391,   120,   166,   105,   392,    82,   111,   392,
     392,    51,   111,   111,   111,    42,   168,   168,   392,   111,
     106,   247,   324,   392,     6,    17,    42,    50,   168,   383,
     168,   113,   392,    17,    42,    50,   168,   383,   168,   113,
     106,   388,    42,     6,   168,   319,   111,   134,   168,   322,
     332,   352,   354,   392,   162,   163,   168,   181,   322,   377,
     378,   379,   385,   419,    32,    43,   368,   369,   373,   366,
     168,   383,   168,   392,   392,   111,   271,   106,   259,    17,
     124,   168,   112,   251,   114,   249,   106,   112,   140,   141,
     123,   106,   259,   262,   248,   107,   250,   315,   392,   120,
     106,   259,   168,   106,   112,   142,   143,   105,   105,   113,
     113,   108,   318,   108,   113,   392,   106,   106,   122,   392,
     165,   392,   399,   400,   401,   402,   403,   404,   404,   406,
     406,   406,   406,   168,   176,   252,   253,   407,   407,   407,
     408,   408,   409,   409,   409,   111,   243,   180,   180,   180,
     180,   111,   168,   168,   181,   168,   181,   108,   311,   243,
     236,   243,   243,   243,   392,   315,   120,   391,   315,   120,
     106,   388,   106,   392,   106,   106,   105,   105,   106,   110,
     168,   113,   116,   105,    42,   110,   113,   116,   105,    42,
     106,   111,   392,   112,   157,   158,   111,   106,   163,   378,
     106,   111,   370,   374,   373,   159,   369,   368,   373,   105,
     110,   106,    17,   113,   114,   249,   168,   260,   141,   106,
     259,   106,   108,   112,   250,   316,   120,   106,   120,   264,
     143,   106,   388,   106,   388,    50,    50,   108,    50,   106,
     409,   412,   106,    82,   111,   112,   130,   131,   111,   130,
     111,   130,   111,   130,   111,   132,   111,   132,   111,   132,
     111,   132,   243,   110,   243,   106,   338,   111,    10,    51,
     168,   324,   325,   326,   330,   335,   345,   348,   349,   351,
     355,   357,   364,   392,   106,   388,   324,   168,   168,   106,
     388,   168,   168,   106,   388,   106,   353,   354,   111,   332,
     158,   111,   392,   324,   105,   317,   369,   373,   106,   388,
     168,   106,   108,   112,   108,   120,   111,   106,   111,   106,
     105,   105,   105,   418,   412,   397,   180,   111,   131,   111,
     111,   111,   111,   111,   111,   111,   243,   107,   339,   105,
     105,    82,    24,   105,    82,   317,   106,   106,   105,   106,
     105,   106,   324,   106,   106,   353,   106,   353,   111,   134,
     168,   371,   372,   106,   316,   111,   111,   106,   388,   106,
     388,   106,   388,   339,     9,    28,   108,   152,   153,   154,
     340,   341,   342,   392,   392,   325,   324,   111,   352,   392,
     111,   106,   388,   106,   388,   324,   324,   106,   324,   106,
     106,   353,   372,    97,   160,   161,   106,   249,   111,   106,
     111,   106,   111,   106,   343,   397,   108,   153,   341,   342,
     108,   154,   342,   108,   151,   340,   342,    82,    83,   106,
     106,   111,   392,   111,   106,   106,   106,   324,   324,   324,
     106,   249,   168,   161,   317,   111,   111,   111,   112,   155,
     156,   108,    82,   108,   340,   153,   318,   317,   362,   392,
     325,   325,   106,   353,   111,   111,   392,   325,   324,   343,
     156,   318,   111,    24,   325,   106,   106,   353,   106,   353,
     111,   325,   325,   325,   106,   325,   106,   106,   353,   325,
     325,   325,   106,   325
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   119,   120,   120,   121,   122,   122,   123,   124,   125,
     125,   126,   126,   127,   127,   128,   128,   129,   129,   130,
     130,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     136,   137,   137,   138,   139,   139,   140,   140,   141,   142,
     142,   143,   144,   144,   145,   146,   146,   147,   148,   148,
     149,   149,   150,   150,   151,   151,   152,   152,   153,   153,
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
     202,   202,   202,   202,   203,   203,   203,   205,   204,   206,
     204,   207,   204,   208,   204,   209,   204,   210,   204,   211,
     204,   212,   204,   213,   204,   214,   204,   215,   204,   216,
     204,   217,   204,   218,   204,   219,   204,   220,   204,   221,
     204,   222,   204,   223,   204,   224,   204,   225,   204,   226,
     204,   227,   204,   228,   204,   229,   204,   230,   204,   231,
     204,   232,   204,   233,   204,   234,   204,   235,   204,   236,
     204,   237,   238,   238,   239,   240,   241,   241,   242,   242,
     242,   242,   243,   243,   244,   244,   244,   244,   245,   245,
     245,   245,   245,   246,   246,   247,   247,   248,   248,   249,
     249,   250,   250,   251,   251,   251,   252,   252,   253,   253,
     254,   254,   255,   255,   255,   255,   256,   256,   257,   257,
     257,   257,   257,   257,   257,   257,   258,   258,   259,   259,
     260,   260,   260,   261,   261,   262,   263,   263,   264,   265,
     265,   266,   267,   268,   268,   268,   268,   269,   270,   270,
     270,   270,   270,   270,   270,   270,   271,   271,   271,   271,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     273,   273,   273,   273,   274,   274,   274,   274,   274,   274,
     275,   275,   276,   277,   278,   278,   278,   278,   278,   278,
     279,   279,   280,   281,   281,   281,   281,   281,   281,   281,
     281,   282,   282,   283,   283,   284,   284,   285,   286,   286,
     287,   287,   288,   289,   289,   290,   292,   291,   293,   291,
     294,   291,   295,   291,   296,   291,   297,   291,   298,   291,
     299,   291,   300,   291,   301,   291,   302,   291,   303,   291,
     304,   291,   305,   291,   306,   291,   307,   291,   308,   309,
     310,   310,   311,   311,   312,   312,   312,   312,   312,   313,
     313,   314,   314,   315,   315,   315,   316,   316,   317,   317,
     318,   318,   319,   319,   319,   320,   320,   321,   322,   322,
     323,   323,   324,   324,   324,   324,   324,   324,   325,   325,
     325,   325,   325,   327,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   328,   329,   330,
     331,   332,   332,   332,   332,   332,   332,   332,   333,   334,
     335,   336,   336,   338,   337,   339,   339,   339,   339,   339,
     339,   340,   340,   340,   341,   341,   342,   342,   342,   343,
     344,   345,   346,   347,   347,   348,   348,   349,   350,   350,
     350,   350,   350,   350,   350,   350,   351,   351,   351,   351,
     351,   351,   351,   351,   352,   352,   353,   354,   354,   355,
     356,   357,   358,   358,   359,   360,   360,   361,   361,   362,
     364,   363,   365,   366,   367,   367,   367,   367,   368,   368,
     370,   369,   371,   371,   372,   372,   374,   373,   375,   375,
     375,   375,   376,   377,   377,   378,   378,   379,   379,   380,
     380,   380,   380,   380,   380,   380,   380,   380,   380,   380,
     381,   381,   381,   381,   381,   381,   382,   382,   382,   382,
     383,   383,   383,   383,   384,   384,   385,   385,   385,   385,
     386,   386,   386,   387,   387,   387,   387,   387,   387,   387,
     387,   387,   387,   387,   387,   387,   387,   388,   388,   389,
     389,   389,   389,   389,   389,   389,   389,   390,   390,   390,
     390,   390,   390,   391,   392,   393,   393,   394,   395,   395,
     395,   395,   396,   397,   397,   398,   398,   399,   399,   400,
     400,   401,   401,   402,   402,   403,   403,   403,   404,   404,
     404,   404,   404,   404,   405,   406,   406,   406,   406,   407,
     407,   407,   408,   408,   408,   408,   409,   409,   409,   409,
     409,   410,   411,   412,   412,   412,   412,   412,   413,   413,
     413,   413,   413,   414,   415,   416,   416,   416,   418,   417,
     419,   419,   419
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     2,     2,     2,     1,
       2,     1,     2,     2,     3,     1,     2,     1,     2,     1,
       2,     2,     1,     2,     2,     2,     1,     2,     1,     2,
       2,     1,     2,     2,     1,     2,     1,     2,     2,     1,
       2,     2,     1,     2,     2,     1,     2,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
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
       5,     6,     5,     6,     1,     1,     1,     0,     4,     0,
       5,     0,     5,     0,     6,     0,     5,     0,     6,     0,
       6,     0,     7,     0,     5,     0,     6,     0,     6,     0,
       7,     0,     6,     0,     7,     0,     7,     0,     8,     0,
       5,     0,     6,     0,     6,     0,     7,     0,     6,     0,
       7,     0,     7,     0,     8,     0,     6,     0,     7,     0,
       7,     0,     8,     0,     7,     0,     8,     0,     8,     0,
       9,     3,     1,     2,     2,     2,     1,     2,     2,     2,
       3,     3,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     1,     3,     1,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     3,     2,     3,     3,     4,     2,     2,     2,     3,
       3,     4,     3,     4,     4,     5,     2,     3,     1,     2,
       2,     3,     1,     3,     4,     2,     1,     2,     1,     1,
       1,     1,     2,     2,     3,     3,     4,     1,     3,     4,
       4,     5,     4,     5,     5,     6,     2,     3,     3,     4,
       4,     5,     4,     5,     6,     7,     6,     7,     6,     7,
       3,     4,     4,     5,     2,     3,     3,     4,     3,     4,
       1,     1,     2,     3,     1,     2,     2,     2,     3,     3,
       1,     2,     2,     3,     4,     4,     5,     4,     5,     5,
       6,     2,     3,     1,     2,     2,     1,     3,     2,     3,
       1,     1,     1,     2,     3,     1,     0,     4,     0,     5,
       0,     5,     0,     6,     0,     5,     0,     6,     0,     6,
       0,     7,     0,     5,     0,     6,     0,     6,     0,     7,
       0,     6,     0,     7,     0,     7,     0,     8,     1,     2,
       2,     3,     2,     3,     1,     1,     1,     1,     1,     3,
       4,     2,     3,     2,     3,     3,     1,     3,     2,     3,
       1,     2,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     5,     7,
       7,     3,     5,     0,     6,     3,     4,     2,     3,     3,
       4,     4,     3,     3,     3,     4,     2,     3,     1,     1,
       5,     5,     7,     1,     1,     1,     1,     1,     6,     7,
       7,     8,     7,     8,     8,     9,     6,     7,     7,     8,
       7,     8,     8,     9,     1,     1,     1,     1,     2,     3,
       5,     5,     2,     3,     3,     2,     3,     2,     3,     3,
       0,     6,     1,     1,     3,     3,     4,     1,     1,     2,
       0,     6,     2,     3,     1,     2,     0,     3,     3,     4,
       4,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     1,     1,     1,     1,     1,
       3,     3,     4,     4,     3,     3,     1,     3,     3,     3,
       4,     5,     5,     6,     1,     2,     3,     3,     5,     5,
       4,     4,     4,     4,     3,     5,     6,     5,     6,     5,
       6,     5,     6,     7,     8,     7,     8,     1,     2,     3,
       3,     3,     3,     3,     5,     5,     3,     3,     4,     3,
       4,     4,     4,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     5,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     1,     2,     2,
       1,     2,     2,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     4,     4,     5,     0,     6,
       1,     1,     1
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
#line 788 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type ;(yyval.typeinfo)->order=1;(yyval.typeinfo)->tac=emptyvector();}
#line 4499 "parser.tab.c"
    break;

  case 3: /* OMPSB: OMPSB PSB  */
#line 789 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type + "[]";(yyval.typeinfo)->order=(yyvsp[-1].typeinfo)->order+1;(yyval.typeinfo)->tac=emptyvector();}
#line 4505 "parser.tab.c"
    break;

  case 4: /* PSB: LSB RSB  */
#line 791 "parser.y"
                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "[]";(yyval.typeinfo)->tac=emptyvector();}
#line 4511 "parser.tab.c"
    break;

  case 5: /* OMAdditionalBound: AdditionalBound  */
#line 793 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4517 "parser.tab.c"
    break;

  case 6: /* OMAdditionalBound: OMAdditionalBound AdditionalBound  */
#line 794 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4523 "parser.tab.c"
    break;

  case 7: /* ReceiverParameterComma: ReceiverParameter COMMA  */
#line 796 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 4529 "parser.tab.c"
    break;

  case 8: /* IdentifierDot: Identifier DOT  */
#line 798 "parser.y"
                              {         (yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4535 "parser.tab.c"
    break;

  case 9: /* OMImportDeclaration: ImportDeclaration  */
#line 800 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4541 "parser.tab.c"
    break;

  case 10: /* OMImportDeclaration: OMImportDeclaration ImportDeclaration  */
#line 801 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4547 "parser.tab.c"
    break;

  case 11: /* OMTopLevelClassOrInterfaceDeclaration: TopLevelClassOrInterfaceDeclaration  */
#line 803 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4553 "parser.tab.c"
    break;

  case 12: /* OMTopLevelClassOrInterfaceDeclaration: OMTopLevelClassOrInterfaceDeclaration TopLevelClassOrInterfaceDeclaration  */
#line 804 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4559 "parser.tab.c"
    break;

  case 13: /* OMDotIdentifier: DOT Identifier  */
#line 806 "parser.y"
                                                                {(yyval.typeinfo) = createstruct();string p=((yyvsp[0].str));((yyval.typeinfo))->name="."+p;(yyval.typeinfo)->tac=emptyvector();}
#line 4565 "parser.tab.c"
    break;

  case 14: /* OMDotIdentifier: OMDotIdentifier DOT Identifier  */
#line 807 "parser.y"
                                                    {(yyval.typeinfo) = createstruct();string p=((yyvsp[0].str));((yyval.typeinfo))->name=((yyvsp[-2].typeinfo))->name+"."+p;(yyval.typeinfo)->tac= (yyvsp[-2].typeinfo)->tac;}
#line 4571 "parser.tab.c"
    break;

  case 15: /* OMModuleDirective: ModuleDirective  */
#line 809 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4577 "parser.tab.c"
    break;

  case 16: /* OMModuleDirective: OMModuleDirective ModuleDirective  */
#line 810 "parser.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4583 "parser.tab.c"
    break;

  case 17: /* OMRequiresModifier: Modifieropt  */
#line 812 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4589 "parser.tab.c"
    break;

  case 18: /* OMRequiresModifier: OMRequiresModifier Modifieropt  */
#line 813 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4595 "parser.tab.c"
    break;

  case 19: /* OMCommaModuleName: CommaModuleName  */
#line 815 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4601 "parser.tab.c"
    break;

  case 20: /* OMCommaModuleName: OMCommaModuleName CommaModuleName  */
#line 816 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4607 "parser.tab.c"
    break;

  case 21: /* CommaModuleName: COMMA ModuleName  */
#line 818 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4613 "parser.tab.c"
    break;

  case 22: /* OMCommaTypeName: CommaTypeName  */
#line 820 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4619 "parser.tab.c"
    break;

  case 23: /* OMCommaTypeName: OMCommaTypeName CommaTypeName  */
#line 821 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4625 "parser.tab.c"
    break;

  case 24: /* CommaTypeName: COMMA Identifier  */
#line 823 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4631 "parser.tab.c"
    break;

  case 25: /* CommaTypeName: COMMA ExpressionName  */
#line 824 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4637 "parser.tab.c"
    break;

  case 26: /* OMClassModifier: InterfaceModifier  */
#line 826 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4643 "parser.tab.c"
    break;

  case 27: /* OMClassModifier: OMClassModifier InterfaceModifier  */
#line 827 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4649 "parser.tab.c"
    break;

  case 28: /* OMCommaTypeParameter: CommaTypeParameter  */
#line 829 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4655 "parser.tab.c"
    break;

  case 29: /* OMCommaTypeParameter: OMCommaTypeParameter CommaTypeParameter  */
#line 830 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4661 "parser.tab.c"
    break;

  case 30: /* CommaTypeParameter: COMMA TypeParameter  */
#line 832 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4667 "parser.tab.c"
    break;

  case 31: /* OMCommaInterfaceType: CommaInterfaceType  */
#line 834 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4673 "parser.tab.c"
    break;

  case 32: /* OMCommaInterfaceType: OMCommaInterfaceType CommaInterfaceType  */
#line 835 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4679 "parser.tab.c"
    break;

  case 33: /* CommaInterfaceType: COMMA Identifier  */
#line 837 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4685 "parser.tab.c"
    break;

  case 34: /* OMClassBodyDeclaration: ClassBodyDeclaration  */
#line 839 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4691 "parser.tab.c"
    break;

  case 35: /* OMClassBodyDeclaration: OMClassBodyDeclaration ClassBodyDeclaration  */
#line 840 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4697 "parser.tab.c"
    break;

  case 36: /* OMCommaFormalParameter: CommaFormalParameter  */
#line 842 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;(yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4703 "parser.tab.c"
    break;

  case 37: /* OMCommaFormalParameter: OMCommaFormalParameter CommaFormalParameter  */
#line 843 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();vector<string>a=((yyvsp[-1].typeinfo))->type_variable;vector<string>b=((yyvsp[0].typeinfo))->type_variable;for(auto z:a){((yyval.typeinfo))->type_variable.push_back(z);}for(auto z:b){((yyval.typeinfo))->type_variable.push_back(z);}(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4709 "parser.tab.c"
    break;

  case 38: /* CommaFormalParameter: COMMA FormalParameter  */
#line 845 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;(yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4715 "parser.tab.c"
    break;

  case 39: /* OMCommaExceptionType: CommaExceptionType  */
#line 847 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4721 "parser.tab.c"
    break;

  case 40: /* OMCommaExceptionType: OMCommaExceptionType CommaExceptionType  */
#line 848 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4727 "parser.tab.c"
    break;

  case 41: /* CommaExceptionType: COMMA ExceptionType  */
#line 850 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4733 "parser.tab.c"
    break;

  case 42: /* OMCommaEnumConstant: CommaEnumConstant  */
#line 852 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4739 "parser.tab.c"
    break;

  case 43: /* OMCommaEnumConstant: OMCommaEnumConstant CommaEnumConstant  */
#line 853 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4745 "parser.tab.c"
    break;

  case 44: /* CommaEnumConstant: EnumConstant COMMA  */
#line 855 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 4751 "parser.tab.c"
    break;

  case 45: /* OMCommaRecordComponent: CommaRecordComponent  */
#line 857 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4757 "parser.tab.c"
    break;

  case 46: /* OMCommaRecordComponent: OMCommaRecordComponent CommaRecordComponent  */
#line 858 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4763 "parser.tab.c"
    break;

  case 47: /* CommaRecordComponent: COMMA RecordComponent  */
#line 860 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4769 "parser.tab.c"
    break;

  case 48: /* OMRecordBodyDeclaration: RecordBodyDeclaration  */
#line 862 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4775 "parser.tab.c"
    break;

  case 49: /* OMRecordBodyDeclaration: OMRecordBodyDeclaration RecordBodyDeclaration  */
#line 863 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4781 "parser.tab.c"
    break;

  case 50: /* OMInterfaceMemberDeclaration: InterfaceMemberDeclaration  */
#line 865 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4787 "parser.tab.c"
    break;

  case 51: /* OMInterfaceMemberDeclaration: OMInterfaceMemberDeclaration InterfaceMemberDeclaration  */
#line 866 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4793 "parser.tab.c"
    break;

  case 52: /* OMBlockStatement: BlockStatement  */
#line 873 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 4799 "parser.tab.c"
    break;

  case 53: /* OMBlockStatement: OMBlockStatement BlockStatement  */
#line 874 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4805 "parser.tab.c"
    break;

  case 54: /* OMSwitchRule: SwitchRule  */
#line 876 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4811 "parser.tab.c"
    break;

  case 55: /* OMSwitchRule: OMSwitchRule SwitchRule  */
#line 877 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4817 "parser.tab.c"
    break;

  case 56: /* OMSwitchBlockStatementGroup: SwitchBlockStatementGroup  */
#line 879 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4823 "parser.tab.c"
    break;

  case 57: /* OMSwitchBlockStatementGroup: OMSwitchBlockStatementGroup SwitchBlockStatementGroup  */
#line 880 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4829 "parser.tab.c"
    break;

  case 58: /* OMSwitchLabelColon: SwitchLabelColon  */
#line 882 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4835 "parser.tab.c"
    break;

  case 59: /* OMSwitchLabelColon: OMSwitchLabelColon SwitchLabelColon  */
#line 883 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4841 "parser.tab.c"
    break;

  case 60: /* SwitchLabelColon: SwitchLabel COLON  */
#line 885 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 4847 "parser.tab.c"
    break;

  case 61: /* OMCommaCaseConstant: CommaCaseConstant  */
#line 887 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4853 "parser.tab.c"
    break;

  case 62: /* OMCommaCaseConstant: OMCommaCaseConstant CommaCaseConstant  */
#line 888 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4859 "parser.tab.c"
    break;

  case 63: /* CommaCaseConstant: COMMA CaseConstant  */
#line 890 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4865 "parser.tab.c"
    break;

  case 64: /* OMCommaStatementExpression: CommaStatementExpression  */
#line 892 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4871 "parser.tab.c"
    break;

  case 65: /* OMCommaStatementExpression: OMCommaStatementExpression CommaStatementExpression  */
#line 893 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4877 "parser.tab.c"
    break;

  case 66: /* CommaStatementExpression: COMMA StatementExpression  */
#line 895 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4883 "parser.tab.c"
    break;

  case 67: /* OMCatchClause: CatchClause  */
#line 897 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4889 "parser.tab.c"
    break;

  case 68: /* OMCatchClause: OMCatchClause CatchClause  */
#line 898 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4895 "parser.tab.c"
    break;

  case 69: /* OMOrClassType: OrClassType  */
#line 900 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4901 "parser.tab.c"
    break;

  case 70: /* OMOrClassType: OMOrClassType OrClassType  */
#line 901 "parser.y"
                                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4907 "parser.tab.c"
    break;

  case 71: /* OrClassType: BITOR Identifier  */
#line 903 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4913 "parser.tab.c"
    break;

  case 72: /* OMSemicolonResource: SemicolonResource  */
#line 905 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4919 "parser.tab.c"
    break;

  case 73: /* OMSemicolonResource: OMSemicolonResource SemicolonResource  */
#line 906 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4925 "parser.tab.c"
    break;

  case 74: /* SemicolonResource: Resource SEMICOLON  */
#line 908 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 4931 "parser.tab.c"
    break;

  case 75: /* OMCommaExpression: CommaExpression  */
#line 910 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;for(auto z:(yyvsp[0].typeinfo)->params)(yyval.typeinfo)->params.push_back(z);}
#line 4937 "parser.tab.c"
    break;

  case 76: /* OMCommaExpression: OMCommaExpression CommaExpression  */
#line 911 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);for(auto z:((yyvsp[-1].typeinfo))->params)((yyval.typeinfo))->params.push_back(z);for(auto z:((yyvsp[0].typeinfo))->params)((yyval.typeinfo))->params.push_back(z);}
#line 4943 "parser.tab.c"
    break;

  case 77: /* CommaExpression: COMMA Expression  */
#line 913 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;string s = ((yyvsp[0].typeinfo))->tempname; (yyval.typeinfo)->params.push_back(s);}
#line 4949 "parser.tab.c"
    break;

  case 78: /* OMDimExpr: DimExpr  */
#line 915 "parser.y"
                                                                                                                {(yyval.typeinfo)=createstruct();int p=(yyvsp[0].typeinfo)->exprvalue;vector<int>q={p};(yyval.typeinfo)->arrdim=q;(yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4955 "parser.tab.c"
    break;

  case 79: /* OMDimExpr: OMDimExpr DimExpr  */
#line 916 "parser.y"
                                                                                                        {(yyval.typeinfo)=createstruct();int p=(yyvsp[0].typeinfo)->exprvalue;(yyval.typeinfo)->arrdim=(yyvsp[-1].typeinfo)->arrdim;((yyval.typeinfo))->arrdim.push_back(p);(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4961 "parser.tab.c"
    break;

  case 80: /* Modifieropt: PUBLIC  */
#line 918 "parser.y"
                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4967 "parser.tab.c"
    break;

  case 81: /* Modifieropt: PROTECTED  */
#line 919 "parser.y"
                                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4973 "parser.tab.c"
    break;

  case 82: /* Modifieropt: PRIVATE  */
#line 920 "parser.y"
                                                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4979 "parser.tab.c"
    break;

  case 83: /* Modifieropt: ABSTRACT  */
#line 921 "parser.y"
                                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4985 "parser.tab.c"
    break;

  case 84: /* Modifieropt: STATIC  */
#line 922 "parser.y"
                                                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4991 "parser.tab.c"
    break;

  case 85: /* Modifieropt: SEALED  */
#line 923 "parser.y"
                                                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4997 "parser.tab.c"
    break;

  case 86: /* Modifieropt: STRICTFP  */
#line 924 "parser.y"
                                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5003 "parser.tab.c"
    break;

  case 87: /* Modifieropt: FINAL  */
#line 925 "parser.y"
                                                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5009 "parser.tab.c"
    break;

  case 88: /* Identifier: IDENTIFIERWK  */
#line 927 "parser.y"
                                                {(yyval.str)=(yyvsp[0].str);}
#line 5015 "parser.tab.c"
    break;

  case 89: /* UnqualifiedMethodIdentifier: IDENTIFIERWK  */
#line 929 "parser.y"
                                                                {(yyval.typeinfo) = createstruct(); string p = (yyvsp[0].str);((yyval.typeinfo))->name = p;(yyval.typeinfo)->tempname=p;}
#line 5021 "parser.tab.c"
    break;

  case 90: /* UnqualifiedMethodIdentifier: EXPORTS  */
#line 930 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5027 "parser.tab.c"
    break;

  case 91: /* UnqualifiedMethodIdentifier: OPENS  */
#line 931 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5033 "parser.tab.c"
    break;

  case 92: /* UnqualifiedMethodIdentifier: REQUIRES  */
#line 932 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5039 "parser.tab.c"
    break;

  case 93: /* UnqualifiedMethodIdentifier: USES  */
#line 933 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5045 "parser.tab.c"
    break;

  case 94: /* UnqualifiedMethodIdentifier: MODULE  */
#line 934 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5051 "parser.tab.c"
    break;

  case 95: /* UnqualifiedMethodIdentifier: PERMITS  */
#line 935 "parser.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5057 "parser.tab.c"
    break;

  case 96: /* UnqualifiedMethodIdentifier: SEALED  */
#line 936 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5063 "parser.tab.c"
    break;

  case 97: /* UnqualifiedMethodIdentifier: VAR  */
#line 937 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5069 "parser.tab.c"
    break;

  case 98: /* UnqualifiedMethodIdentifier: NONSEALED  */
#line 938 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5075 "parser.tab.c"
    break;

  case 99: /* UnqualifiedMethodIdentifier: PROVIDES  */
#line 939 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5081 "parser.tab.c"
    break;

  case 100: /* UnqualifiedMethodIdentifier: TO  */
#line 940 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5087 "parser.tab.c"
    break;

  case 101: /* UnqualifiedMethodIdentifier: WITH  */
#line 941 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5093 "parser.tab.c"
    break;

  case 102: /* UnqualifiedMethodIdentifier: OPEN  */
#line 942 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5099 "parser.tab.c"
    break;

  case 103: /* UnqualifiedMethodIdentifier: RECORD  */
#line 943 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5105 "parser.tab.c"
    break;

  case 104: /* UnqualifiedMethodIdentifier: TRANSITIVE  */
#line 944 "parser.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5111 "parser.tab.c"
    break;

  case 105: /* Literal: INTEGERLITERAL  */
#line 954 "parser.y"
                                                                                        {string x=(yyvsp[0].str);int p=stoi(x);(yyval.typeinfo)=new Typeinfo;     (yyval.typeinfo)->littype="int";(yyval.typeinfo)->valint=p;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+" = "+x;(yyval.typeinfo)->tac={z};(yyval.typeinfo)->exprvalue=atoi((yyvsp[0].str));((yyval.typeinfo))->type = "int";}
#line 5117 "parser.tab.c"
    break;

  case 106: /* Literal: FLOATINGPOINTLITERAL  */
#line 955 "parser.y"
                                                                                        {string x=(yyvsp[0].str);float p=stof(x);(yyval.typeinfo)=new Typeinfo;   (yyval.typeinfo)->littype="float";(yyval.typeinfo)->valfloat=p;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+" = "+x;(yyval.typeinfo)->tac={z};(yyval.typeinfo)->exprvalue=(int)((yyval.typeinfo)->valfloat);((yyval.typeinfo))->type = "float";}
#line 5123 "parser.tab.c"
    break;

  case 107: /* Literal: BOOLEANLITERAL  */
#line 956 "parser.y"
                                                                                        {string x=(yyvsp[0].str);;(yyval.typeinfo)=new Typeinfo;                  (yyval.typeinfo)->littype="bool";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+" = "+x;(yyval.typeinfo)->tac={z};if(x=="true"){(yyval.typeinfo)->exprvalue=1;}else{(yyval.typeinfo)->exprvalue=0;};((yyval.typeinfo))->type = "bool";}
#line 5129 "parser.tab.c"
    break;

  case 108: /* Literal: NULLLITERAL  */
#line 957 "parser.y"
                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo;                   (yyval.typeinfo)->littype="null";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+" = "+x;(yyval.typeinfo)->tac={z};(yyval.typeinfo)->exprvalue=0;(yyval.typeinfo)->type="null";}
#line 5135 "parser.tab.c"
    break;

  case 109: /* Literal: CHARACTERLITERAL  */
#line 958 "parser.y"
                                                                                            {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo;                   (yyval.typeinfo)->littype="char";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+"="+x;(yyval.typeinfo)->tac={z};(yyval.typeinfo)->exprvalue=x[0]-'\0';((yyval.typeinfo))->type = "char";}
#line 5141 "parser.tab.c"
    break;

  case 110: /* Literal: STRING  */
#line 959 "parser.y"
                                                                                                    {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo;                   (yyval.typeinfo)->littype="string";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+" = "+x;(yyval.typeinfo)->tac={z};((yyval.typeinfo))->type = "string";}
#line 5147 "parser.tab.c"
    break;

  case 111: /* Literal: TEXTBLOCKS  */
#line 960 "parser.y"
                                                                                            {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo;                   (yyval.typeinfo)->littype="textblock";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+" = "+x;(yyval.typeinfo)->tac={z};((yyval.typeinfo))->type = "textblock";}
#line 5153 "parser.tab.c"
    break;

  case 112: /* ASSIGNMENTOPERATOR: NEWASSIGNMENTOPERATOR  */
#line 961 "parser.y"
                                                                {(yyval.str)=(yyvsp[0].str);}
#line 5159 "parser.tab.c"
    break;

  case 113: /* ASSIGNMENTOPERATOR: EQUAL  */
#line 962 "parser.y"
                                                                                                        {(yyval.str)=(yyvsp[0].str);}
#line 5165 "parser.tab.c"
    break;

  case 114: /* PrimitiveType: UnannPrimitiveType  */
#line 964 "parser.y"
                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5171 "parser.tab.c"
    break;

  case 115: /* NumericType: IntegralType  */
#line 966 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=emptyvector();}
#line 5177 "parser.tab.c"
    break;

  case 116: /* NumericType: FloatingPointType  */
#line 967 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=emptyvector();}
#line 5183 "parser.tab.c"
    break;

  case 117: /* IntegralType: BYTE  */
#line 969 "parser.y"
                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "byte";(yyval.typeinfo)->tac=emptyvector();}
#line 5189 "parser.tab.c"
    break;

  case 118: /* IntegralType: SHORT  */
#line 970 "parser.y"
                                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "short";(yyval.typeinfo)->tac=emptyvector();}
#line 5195 "parser.tab.c"
    break;

  case 119: /* IntegralType: INT  */
#line 971 "parser.y"
                                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "int";(yyval.typeinfo)->tac=emptyvector();}
#line 5201 "parser.tab.c"
    break;

  case 120: /* IntegralType: LONG  */
#line 972 "parser.y"
                                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "long";(yyval.typeinfo)->tac=emptyvector();}
#line 5207 "parser.tab.c"
    break;

  case 121: /* IntegralType: CHAR  */
#line 973 "parser.y"
                                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "char";(yyval.typeinfo)->tac=emptyvector();}
#line 5213 "parser.tab.c"
    break;

  case 122: /* FloatingPointType: FLOAT  */
#line 975 "parser.y"
                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "float";(yyval.typeinfo)->tac=emptyvector();}
#line 5219 "parser.tab.c"
    break;

  case 123: /* FloatingPointType: DOUBLE  */
#line 976 "parser.y"
                                                                                                        {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "double";(yyval.typeinfo)->tac=emptyvector();}
#line 5225 "parser.tab.c"
    break;

  case 124: /* ReferenceType: Identifier  */
#line 978 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=emptyvector();}
#line 5231 "parser.tab.c"
    break;

  case 125: /* ReferenceType: UnannArrayType  */
#line 979 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5237 "parser.tab.c"
    break;

  case 126: /* TypeParameter: Identifier  */
#line 981 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5243 "parser.tab.c"
    break;

  case 127: /* TypeParameter: Identifier TypeBound  */
#line 982 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5249 "parser.tab.c"
    break;

  case 128: /* TypeBound: EXTENDS Identifier  */
#line 984 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5255 "parser.tab.c"
    break;

  case 129: /* TypeBound: EXTENDS Identifier OMAdditionalBound  */
#line 985 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5261 "parser.tab.c"
    break;

  case 130: /* AdditionalBound: BITAND Identifier  */
#line 987 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5267 "parser.tab.c"
    break;

  case 131: /* ModuleName: Identifier  */
#line 989 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5273 "parser.tab.c"
    break;

  case 132: /* ModuleName: ModuleName DOT Identifier  */
#line 990 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5279 "parser.tab.c"
    break;

  case 133: /* ExpressionName: Identifier DOT Identifier  */
#line 992 "parser.y"
                                                                {(yyval.typeinfo) = createstruct();string q=((yyvsp[-2].str));string p=((yyvsp[0].str));((yyval.typeinfo))->type=q+"."+p;string x=(yyvsp[-2].str);string r=newtemp(); (yyval.typeinfo)->tempname=r;r=r+" = "+x; (yyval.typeinfo)->tac={r};}
#line 5285 "parser.tab.c"
    break;

  case 134: /* ExpressionName: ExpressionName DOT Identifier  */
#line 993 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();string p=((yyvsp[0].str));((yyval.typeinfo))->type=((yyvsp[-2].typeinfo))->type+"."+p; (yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 5291 "parser.tab.c"
    break;

  case 135: /* MethodName: UnqualifiedMethodIdentifier  */
#line 995 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct(); ;((yyval.typeinfo))->name = ((yyvsp[0].typeinfo))->name; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 5297 "parser.tab.c"
    break;

  case 136: /* CompilationUnit: OrdinaryCompilationUnit  */
#line 997 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac; for(auto z:((yyval.typeinfo)->tac)) fprintf(dotfile,"%s\n",z.c_str()); }
#line 5303 "parser.tab.c"
    break;

  case 137: /* CompilationUnit: ModularCompilationUnit  */
#line 998 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac; for(auto z:((yyval.typeinfo)->tac)) fprintf(dotfile,"%s\n",z.c_str()); }
#line 5309 "parser.tab.c"
    break;

  case 138: /* OrdinaryCompilationUnit: %empty  */
#line 1000 "parser.y"
                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5315 "parser.tab.c"
    break;

  case 139: /* OrdinaryCompilationUnit: OMTopLevelClassOrInterfaceDeclaration  */
#line 1001 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5321 "parser.tab.c"
    break;

  case 140: /* OrdinaryCompilationUnit: OMImportDeclaration  */
#line 1002 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5327 "parser.tab.c"
    break;

  case 141: /* OrdinaryCompilationUnit: OMImportDeclaration OMTopLevelClassOrInterfaceDeclaration  */
#line 1003 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5333 "parser.tab.c"
    break;

  case 142: /* OrdinaryCompilationUnit: PackageDeclaration  */
#line 1004 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5339 "parser.tab.c"
    break;

  case 143: /* OrdinaryCompilationUnit: PackageDeclaration OMTopLevelClassOrInterfaceDeclaration  */
#line 1005 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5345 "parser.tab.c"
    break;

  case 144: /* OrdinaryCompilationUnit: PackageDeclaration OMImportDeclaration  */
#line 1006 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5351 "parser.tab.c"
    break;

  case 145: /* OrdinaryCompilationUnit: PackageDeclaration OMImportDeclaration OMTopLevelClassOrInterfaceDeclaration  */
#line 1007 "parser.y"
                                                                                                  {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5357 "parser.tab.c"
    break;

  case 146: /* ModularCompilationUnit: ModuleDeclaration  */
#line 1009 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5363 "parser.tab.c"
    break;

  case 147: /* ModularCompilationUnit: OMImportDeclaration ModuleDeclaration  */
#line 1010 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5369 "parser.tab.c"
    break;

  case 148: /* PackageDeclaration: PACKAGE Identifier SEMICOLON  */
#line 1012 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5375 "parser.tab.c"
    break;

  case 149: /* PackageDeclaration: PACKAGE Identifier OMDotIdentifier SEMICOLON  */
#line 1013 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5381 "parser.tab.c"
    break;

  case 150: /* ImportDeclaration: SingleTypeImportDeclaration  */
#line 1015 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5387 "parser.tab.c"
    break;

  case 151: /* ImportDeclaration: SingleStaticImportDeclaration  */
#line 1016 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5393 "parser.tab.c"
    break;

  case 152: /* ImportDeclaration: StaticImportOnDemandDeclaration  */
#line 1017 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5399 "parser.tab.c"
    break;

  case 153: /* ImportDeclaration: ImportOnDemandDeclaration  */
#line 1018 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5405 "parser.tab.c"
    break;

  case 154: /* SingleTypeImportDeclaration: IMPORT Identifier SEMICOLON  */
#line 1020 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5411 "parser.tab.c"
    break;

  case 155: /* SingleTypeImportDeclaration: IMPORT ExpressionName SEMICOLON  */
#line 1021 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5417 "parser.tab.c"
    break;

  case 156: /* SingleStaticImportDeclaration: IMPORT STATIC ExpressionName SEMICOLON  */
#line 1023 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5423 "parser.tab.c"
    break;

  case 157: /* ImportOnDemandDeclaration: IMPORT Identifier DOT MULTIPLY SEMICOLON  */
#line 1025 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5429 "parser.tab.c"
    break;

  case 158: /* ImportOnDemandDeclaration: IMPORT ExpressionName DOT MULTIPLY SEMICOLON  */
#line 1026 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5435 "parser.tab.c"
    break;

  case 159: /* StaticImportOnDemandDeclaration: IMPORT STATIC Identifier DOT MULTIPLY SEMICOLON  */
#line 1028 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5441 "parser.tab.c"
    break;

  case 160: /* StaticImportOnDemandDeclaration: IMPORT STATIC ExpressionName DOT MULTIPLY SEMICOLON  */
#line 1029 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5447 "parser.tab.c"
    break;

  case 161: /* TopLevelClassOrInterfaceDeclaration: ClassDeclaration  */
#line 1031 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5453 "parser.tab.c"
    break;

  case 162: /* TopLevelClassOrInterfaceDeclaration: InterfaceDeclaration  */
#line 1032 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5459 "parser.tab.c"
    break;

  case 163: /* TopLevelClassOrInterfaceDeclaration: SEMICOLON  */
#line 1033 "parser.y"
                                                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5465 "parser.tab.c"
    break;

  case 164: /* $@1: %empty  */
#line 1035 "parser.y"
                                               {symtable*a=createtable();string p=((yyvsp[-1].str));insertclass(p,"module","",a,line);   changescope(a);  }
#line 5471 "parser.tab.c"
    break;

  case 165: /* ModuleDeclaration: MODULE Identifier LCB $@1 RCB  */
#line 1035 "parser.y"
                                                                                                                                                                {goparent();{(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}					}
#line 5477 "parser.tab.c"
    break;

  case 166: /* $@2: %empty  */
#line 1036 "parser.y"
                                        {symtable*a=createtable();string p=((yyvsp[-1].str));insertclass(p,"module","",a,line);   changescope(a);  }
#line 5483 "parser.tab.c"
    break;

  case 167: /* ModuleDeclaration: MODULE Identifier LCB $@2 OMModuleDirective RCB  */
#line 1036 "parser.y"
                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5489 "parser.tab.c"
    break;

  case 168: /* $@3: %empty  */
#line 1037 "parser.y"
                                                        {symtable*a=createtable();string p=((yyvsp[-2].str));insertclass(p+((yyvsp[-1].typeinfo))->name,"module","",a,line);changescope(a);}
#line 5495 "parser.tab.c"
    break;

  case 169: /* ModuleDeclaration: MODULE Identifier OMDotIdentifier LCB $@3 RCB  */
#line 1037 "parser.y"
                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5501 "parser.tab.c"
    break;

  case 170: /* $@4: %empty  */
#line 1038 "parser.y"
                                                         {symtable*a=createtable();string p=((yyvsp[-2].str));insertclass(p+((yyvsp[-1].typeinfo))->name,"module","",a,line);changescope(a);}
#line 5507 "parser.tab.c"
    break;

  case 171: /* ModuleDeclaration: MODULE Identifier OMDotIdentifier LCB $@4 OMModuleDirective RCB  */
#line 1038 "parser.y"
                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5513 "parser.tab.c"
    break;

  case 172: /* $@5: %empty  */
#line 1039 "parser.y"
                                               {symtable*a=createtable();string p=((yyvsp[-1].str));insertclass(p,"module","",a,line);   changescope(a);  }
#line 5519 "parser.tab.c"
    break;

  case 173: /* ModuleDeclaration: OPEN MODULE Identifier LCB $@5 RCB  */
#line 1039 "parser.y"
                                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5525 "parser.tab.c"
    break;

  case 174: /* $@6: %empty  */
#line 1040 "parser.y"
                                              {symtable*a=createtable();string p=((yyvsp[-1].str));insertclass(p,"module","",a,line);}
#line 5531 "parser.tab.c"
    break;

  case 175: /* ModuleDeclaration: OPEN MODULE Identifier LCB $@6 OMModuleDirective RCB  */
#line 1040 "parser.y"
                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5537 "parser.tab.c"
    break;

  case 176: /* $@7: %empty  */
#line 1041 "parser.y"
                                                              {symtable*a=createtable();string p=((yyvsp[-2].str));insertclass(p+((yyvsp[-1].typeinfo))->name,"module","",a,line);changescope(a);}
#line 5543 "parser.tab.c"
    break;

  case 177: /* ModuleDeclaration: OPEN MODULE Identifier OMDotIdentifier LCB $@7 RCB  */
#line 1041 "parser.y"
                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5549 "parser.tab.c"
    break;

  case 178: /* $@8: %empty  */
#line 1042 "parser.y"
                                                              {symtable*a=createtable();string p=((yyvsp[-2].str));insertclass(p+((yyvsp[-1].typeinfo))->name,"module","",a,line);changescope(a);}
#line 5555 "parser.tab.c"
    break;

  case 179: /* ModuleDeclaration: OPEN MODULE Identifier OMDotIdentifier LCB $@8 OMModuleDirective RCB  */
#line 1042 "parser.y"
                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5561 "parser.tab.c"
    break;

  case 180: /* ModuleDirective: REQUIRES ModuleName SEMICOLON  */
#line 1044 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5567 "parser.tab.c"
    break;

  case 181: /* ModuleDirective: REQUIRES OMRequiresModifier ModuleName SEMICOLON  */
#line 1045 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5573 "parser.tab.c"
    break;

  case 182: /* ModuleDirective: EXPORTS Identifier SEMICOLON  */
#line 1046 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5579 "parser.tab.c"
    break;

  case 183: /* ModuleDirective: EXPORTS Identifier TO ModuleName SEMICOLON  */
#line 1047 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5585 "parser.tab.c"
    break;

  case 184: /* ModuleDirective: EXPORTS Identifier TO ModuleName OMCommaModuleName SEMICOLON  */
#line 1048 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5591 "parser.tab.c"
    break;

  case 185: /* ModuleDirective: OPENS Identifier SEMICOLON  */
#line 1049 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5597 "parser.tab.c"
    break;

  case 186: /* ModuleDirective: OPENS Identifier TO ModuleName SEMICOLON  */
#line 1050 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5603 "parser.tab.c"
    break;

  case 187: /* ModuleDirective: OPENS Identifier TO ModuleName OMCommaModuleName SEMICOLON  */
#line 1051 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5609 "parser.tab.c"
    break;

  case 188: /* ModuleDirective: USES Identifier SEMICOLON  */
#line 1052 "parser.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5615 "parser.tab.c"
    break;

  case 189: /* ModuleDirective: PROVIDES Identifier WITH Identifier SEMICOLON  */
#line 1053 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5621 "parser.tab.c"
    break;

  case 190: /* ModuleDirective: PROVIDES Identifier WITH Identifier OMCommaTypeName SEMICOLON  */
#line 1054 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5627 "parser.tab.c"
    break;

  case 191: /* ModuleDirective: EXPORTS ExpressionName SEMICOLON  */
#line 1055 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5633 "parser.tab.c"
    break;

  case 192: /* ModuleDirective: EXPORTS ExpressionName TO ModuleName SEMICOLON  */
#line 1056 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-3].typeinfo)->tac;}
#line 5639 "parser.tab.c"
    break;

  case 193: /* ModuleDirective: EXPORTS ExpressionName TO ModuleName OMCommaModuleName SEMICOLON  */
#line 1057 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 5645 "parser.tab.c"
    break;

  case 194: /* ModuleDirective: OPENS ExpressionName SEMICOLON  */
#line 1058 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5651 "parser.tab.c"
    break;

  case 195: /* ModuleDirective: OPENS ExpressionName TO ModuleName SEMICOLON  */
#line 1059 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-3].typeinfo)->tac;}
#line 5657 "parser.tab.c"
    break;

  case 196: /* ModuleDirective: OPENS ExpressionName TO ModuleName OMCommaModuleName SEMICOLON  */
#line 1060 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 5663 "parser.tab.c"
    break;

  case 197: /* ModuleDirective: USES ExpressionName SEMICOLON  */
#line 1061 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5669 "parser.tab.c"
    break;

  case 198: /* ModuleDirective: PROVIDES ExpressionName WITH ExpressionName SEMICOLON  */
#line 1062 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-3].typeinfo)->tac;}
#line 5675 "parser.tab.c"
    break;

  case 199: /* ModuleDirective: PROVIDES ExpressionName WITH ExpressionName OMCommaTypeName SEMICOLON  */
#line 1063 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 5681 "parser.tab.c"
    break;

  case 200: /* ModuleDirective: PROVIDES ExpressionName WITH Identifier SEMICOLON  */
#line 1064 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-3].typeinfo)->tac;}
#line 5687 "parser.tab.c"
    break;

  case 201: /* ModuleDirective: PROVIDES Identifier WITH ExpressionName OMCommaTypeName SEMICOLON  */
#line 1065 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 5693 "parser.tab.c"
    break;

  case 202: /* ModuleDirective: PROVIDES Identifier WITH ExpressionName SEMICOLON  */
#line 1066 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5699 "parser.tab.c"
    break;

  case 203: /* ModuleDirective: PROVIDES ExpressionName WITH Identifier OMCommaTypeName SEMICOLON  */
#line 1067 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 5705 "parser.tab.c"
    break;

  case 204: /* ClassDeclaration: NormalClassDeclaration  */
#line 1069 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5711 "parser.tab.c"
    break;

  case 205: /* ClassDeclaration: EnumDeclaration  */
#line 1070 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5717 "parser.tab.c"
    break;

  case 206: /* ClassDeclaration: RecordDeclaration  */
#line 1071 "parser.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5723 "parser.tab.c"
    break;

  case 207: /* $@9: %empty  */
#line 1073 "parser.y"
                                                                                        {symtable*a=createscope("class");string p=((yyvsp[0].str));insertclass(p,"class","",a,line);   changescope(a);  }
#line 5729 "parser.tab.c"
    break;

  case 208: /* NormalClassDeclaration: CLASS Identifier $@9 ClassBody  */
#line 1073 "parser.y"
                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5735 "parser.tab.c"
    break;

  case 209: /* $@10: %empty  */
#line 1074 "parser.y"
                                                                                                {symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5741 "parser.tab.c"
    break;

  case 210: /* NormalClassDeclaration: CLASS Identifier ClassPermits $@10 ClassBody  */
#line 1074 "parser.y"
                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5747 "parser.tab.c"
    break;

  case 211: /* $@11: %empty  */
#line 1075 "parser.y"
                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5753 "parser.tab.c"
    break;

  case 212: /* NormalClassDeclaration: CLASS Identifier ClassImplements $@11 ClassBody  */
#line 1075 "parser.y"
                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5759 "parser.tab.c"
    break;

  case 213: /* $@12: %empty  */
#line 1076 "parser.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5765 "parser.tab.c"
    break;

  case 214: /* NormalClassDeclaration: CLASS Identifier ClassImplements ClassPermits $@12 ClassBody  */
#line 1076 "parser.y"
                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5771 "parser.tab.c"
    break;

  case 215: /* $@13: %empty  */
#line 1077 "parser.y"
                                                                                                { symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5777 "parser.tab.c"
    break;

  case 216: /* NormalClassDeclaration: CLASS Identifier ClassExtends $@13 ClassBody  */
#line 1077 "parser.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5783 "parser.tab.c"
    break;

  case 217: /* $@14: %empty  */
#line 1078 "parser.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5789 "parser.tab.c"
    break;

  case 218: /* NormalClassDeclaration: CLASS Identifier ClassExtends ClassPermits $@14 ClassBody  */
#line 1078 "parser.y"
                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5795 "parser.tab.c"
    break;

  case 219: /* $@15: %empty  */
#line 1079 "parser.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5801 "parser.tab.c"
    break;

  case 220: /* NormalClassDeclaration: CLASS Identifier ClassExtends ClassImplements $@15 ClassBody  */
#line 1079 "parser.y"
                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5807 "parser.tab.c"
    break;

  case 221: /* $@16: %empty  */
#line 1080 "parser.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5813 "parser.tab.c"
    break;

  case 222: /* NormalClassDeclaration: CLASS Identifier ClassExtends ClassImplements ClassPermits $@16 ClassBody  */
#line 1080 "parser.y"
                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5819 "parser.tab.c"
    break;

  case 223: /* $@17: %empty  */
#line 1081 "parser.y"
                                                                                                                { symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5825 "parser.tab.c"
    break;

  case 224: /* NormalClassDeclaration: CLASS Identifier TypeParameters $@17 ClassBody  */
#line 1081 "parser.y"
                                                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5831 "parser.tab.c"
    break;

  case 225: /* $@18: %empty  */
#line 1082 "parser.y"
                                                                                                {symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);     changescope(a);  }
#line 5837 "parser.tab.c"
    break;

  case 226: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassPermits $@18 ClassBody  */
#line 1082 "parser.y"
                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5843 "parser.tab.c"
    break;

  case 227: /* $@19: %empty  */
#line 1083 "parser.y"
                                                                                                {symtable*a=createscope("class");string p=((yyvsp[-2].str)); insertclass(p,"class","",a,line);    changescope(a);  }
#line 5849 "parser.tab.c"
    break;

  case 228: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassImplements $@19 ClassBody  */
#line 1083 "parser.y"
                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5855 "parser.tab.c"
    break;

  case 229: /* $@20: %empty  */
#line 1084 "parser.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5861 "parser.tab.c"
    break;

  case 230: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassImplements ClassPermits $@20 ClassBody  */
#line 1084 "parser.y"
                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5867 "parser.tab.c"
    break;

  case 231: /* $@21: %empty  */
#line 1085 "parser.y"
                                                                                                {symtable*a=createscope("class");string p=((yyvsp[-2].str)); insertclass(p,"class","",a,line);    changescope(a);  }
#line 5873 "parser.tab.c"
    break;

  case 232: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassExtends $@21 ClassBody  */
#line 1085 "parser.y"
                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5879 "parser.tab.c"
    break;

  case 233: /* $@22: %empty  */
#line 1086 "parser.y"
                                                                                {symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);     changescope(a);  }
#line 5885 "parser.tab.c"
    break;

  case 234: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassExtends ClassPermits $@22 ClassBody  */
#line 1086 "parser.y"
                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5891 "parser.tab.c"
    break;

  case 235: /* $@23: %empty  */
#line 1087 "parser.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5897 "parser.tab.c"
    break;

  case 236: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassExtends ClassImplements $@23 ClassBody  */
#line 1087 "parser.y"
                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5903 "parser.tab.c"
    break;

  case 237: /* $@24: %empty  */
#line 1088 "parser.y"
                                                                                            {symtable*a=createscope("class");string p=((yyvsp[-4].str)); insertclass(p,"class","",a,line);    changescope(a);  }
#line 5909 "parser.tab.c"
    break;

  case 238: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassExtends ClassImplements ClassPermits $@24 ClassBody  */
#line 1088 "parser.y"
                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5915 "parser.tab.c"
    break;

  case 239: /* $@25: %empty  */
#line 1089 "parser.y"
                                                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[0].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5921 "parser.tab.c"
    break;

  case 240: /* NormalClassDeclaration: OMClassModifier CLASS Identifier $@25 ClassBody  */
#line 1089 "parser.y"
                                                                                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5927 "parser.tab.c"
    break;

  case 241: /* $@26: %empty  */
#line 1090 "parser.y"
                                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5933 "parser.tab.c"
    break;

  case 242: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassPermits $@26 ClassBody  */
#line 1090 "parser.y"
                                                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5939 "parser.tab.c"
    break;

  case 243: /* $@27: %empty  */
#line 1091 "parser.y"
                                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-1].str)); insertclass(p,"class","",a,line);    changescope(a);  }
#line 5945 "parser.tab.c"
    break;

  case 244: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassImplements $@27 ClassBody  */
#line 1091 "parser.y"
                                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5951 "parser.tab.c"
    break;

  case 245: /* $@28: %empty  */
#line 1092 "parser.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5957 "parser.tab.c"
    break;

  case 246: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassImplements ClassPermits $@28 ClassBody  */
#line 1092 "parser.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5963 "parser.tab.c"
    break;

  case 247: /* $@29: %empty  */
#line 1093 "parser.y"
                                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5969 "parser.tab.c"
    break;

  case 248: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassExtends $@29 ClassBody  */
#line 1093 "parser.y"
                                                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5975 "parser.tab.c"
    break;

  case 249: /* $@30: %empty  */
#line 1094 "parser.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5981 "parser.tab.c"
    break;

  case 250: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassExtends ClassPermits $@30 ClassBody  */
#line 1094 "parser.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5987 "parser.tab.c"
    break;

  case 251: /* $@31: %empty  */
#line 1095 "parser.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5993 "parser.tab.c"
    break;

  case 252: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassExtends ClassImplements $@31 ClassBody  */
#line 1095 "parser.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5999 "parser.tab.c"
    break;

  case 253: /* $@32: %empty  */
#line 1096 "parser.y"
                                                                                            { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 6005 "parser.tab.c"
    break;

  case 254: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassExtends ClassImplements ClassPermits $@32 ClassBody  */
#line 1096 "parser.y"
                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6011 "parser.tab.c"
    break;

  case 255: /* $@33: %empty  */
#line 1097 "parser.y"
                                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-1].str)); insertclass(p,"class","",a,line);    changescope(a);  }
#line 6017 "parser.tab.c"
    break;

  case 256: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters $@33 ClassBody  */
#line 1097 "parser.y"
                                                                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6023 "parser.tab.c"
    break;

  case 257: /* $@34: %empty  */
#line 1098 "parser.y"
                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 6029 "parser.tab.c"
    break;

  case 258: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassPermits $@34 ClassBody  */
#line 1098 "parser.y"
                                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6035 "parser.tab.c"
    break;

  case 259: /* $@35: %empty  */
#line 1099 "parser.y"
                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-2].str)); insertclass(p,"class","",a,line);    changescope(a);  }
#line 6041 "parser.tab.c"
    break;

  case 260: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassImplements $@35 ClassBody  */
#line 1099 "parser.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6047 "parser.tab.c"
    break;

  case 261: /* $@36: %empty  */
#line 1100 "parser.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 6053 "parser.tab.c"
    break;

  case 262: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassImplements ClassPermits $@36 ClassBody  */
#line 1100 "parser.y"
                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6059 "parser.tab.c"
    break;

  case 263: /* $@37: %empty  */
#line 1101 "parser.y"
                                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);     changescope(a);  }
#line 6065 "parser.tab.c"
    break;

  case 264: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassExtends $@37 ClassBody  */
#line 1101 "parser.y"
                                                                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6071 "parser.tab.c"
    break;

  case 265: /* $@38: %empty  */
#line 1102 "parser.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 6077 "parser.tab.c"
    break;

  case 266: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassPermits $@38 ClassBody  */
#line 1102 "parser.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6083 "parser.tab.c"
    break;

  case 267: /* $@39: %empty  */
#line 1103 "parser.y"
                                                                                                        { symtable*a=createtable();string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 6089 "parser.tab.c"
    break;

  case 268: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassImplements $@39 ClassBody  */
#line 1103 "parser.y"
                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6095 "parser.tab.c"
    break;

  case 269: /* $@40: %empty  */
#line 1104 "parser.y"
                                                                                                             { symtable*a=createscope("class");string p=((yyvsp[-4].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 6101 "parser.tab.c"
    break;

  case 270: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassImplements ClassPermits $@40 ClassBody  */
#line 1104 "parser.y"
                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6107 "parser.tab.c"
    break;

  case 271: /* TypeParameters: LT TypeParameterList GT  */
#line 1106 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6113 "parser.tab.c"
    break;

  case 272: /* TypeParameterList: TypeParameter  */
#line 1108 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6119 "parser.tab.c"
    break;

  case 273: /* TypeParameterList: TypeParameter OMCommaTypeParameter  */
#line 1109 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6125 "parser.tab.c"
    break;

  case 274: /* ClassExtends: EXTENDS Identifier  */
#line 1111 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6131 "parser.tab.c"
    break;

  case 275: /* ClassImplements: IMPLEMENTS InterfaceTypeList  */
#line 1113 "parser.y"
                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6137 "parser.tab.c"
    break;

  case 276: /* InterfaceTypeList: Identifier  */
#line 1115 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6143 "parser.tab.c"
    break;

  case 277: /* InterfaceTypeList: Identifier OMCommaInterfaceType  */
#line 1116 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6149 "parser.tab.c"
    break;

  case 278: /* ClassPermits: PERMITS Identifier  */
#line 1119 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6155 "parser.tab.c"
    break;

  case 279: /* ClassPermits: PERMITS ExpressionName  */
#line 1120 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6161 "parser.tab.c"
    break;

  case 280: /* ClassPermits: PERMITS Identifier OMCommaTypeName  */
#line 1121 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6167 "parser.tab.c"
    break;

  case 281: /* ClassPermits: PERMITS ExpressionName OMCommaTypeName  */
#line 1122 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6173 "parser.tab.c"
    break;

  case 282: /* ClassBody: LCB RCB  */
#line 1124 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6179 "parser.tab.c"
    break;

  case 283: /* ClassBody: LCB OMClassBodyDeclaration RCB  */
#line 1125 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6185 "parser.tab.c"
    break;

  case 284: /* ClassBodyDeclaration: ClassMemberDeclaration  */
#line 1127 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6191 "parser.tab.c"
    break;

  case 285: /* ClassBodyDeclaration: InstanceInitializer  */
#line 1128 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6197 "parser.tab.c"
    break;

  case 286: /* ClassBodyDeclaration: StaticInitializer  */
#line 1129 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6203 "parser.tab.c"
    break;

  case 287: /* ClassBodyDeclaration: ConstructorDeclaration  */
#line 1130 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6209 "parser.tab.c"
    break;

  case 288: /* ClassMemberDeclaration: FieldDeclaration  */
#line 1132 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6215 "parser.tab.c"
    break;

  case 289: /* ClassMemberDeclaration: MethodDeclaration  */
#line 1133 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6221 "parser.tab.c"
    break;

  case 290: /* ClassMemberDeclaration: ClassDeclaration  */
#line 1134 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6227 "parser.tab.c"
    break;

  case 291: /* ClassMemberDeclaration: InterfaceDeclaration  */
#line 1135 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6233 "parser.tab.c"
    break;

  case 292: /* ClassMemberDeclaration: SEMICOLON  */
#line 1136 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6239 "parser.tab.c"
    break;

  case 293: /* FieldDeclaration: UnannType VariableDeclaratorList SEMICOLON  */
#line 1140 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->variables=((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type=((yyvsp[-2].typeinfo))->type+((yyvsp[-1].typeinfo))->type;for(auto z:((yyval.typeinfo))->variables)insertidentifier(z,((yyval.typeinfo))->type,"",line);((yyval.typeinfo))->puvariables=((yyvsp[-1].typeinfo))->puvariables;vector<string> s = pushlocal(((yyvsp[-1].typeinfo))->puvariables); (yyval.typeinfo)->tac=concvector(s,(yyvsp[-1].typeinfo)->tac);}
#line 6245 "parser.tab.c"
    break;

  case 294: /* FieldDeclaration: OMClassModifier UnannType VariableDeclaratorList SEMICOLON  */
#line 1141 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->variables=((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type=((yyvsp[-2].typeinfo))->type+((yyvsp[-1].typeinfo))->type;for(auto z:((yyval.typeinfo))->variables)insertidentifier(z,((yyval.typeinfo))->type,"",line);((yyval.typeinfo))->puvariables=((yyvsp[-1].typeinfo))->puvariables;vector<string> s = pushlocal(((yyvsp[-1].typeinfo))->puvariables); (yyval.typeinfo)->tac=concvector(s,(yyvsp[-1].typeinfo)->tac);}
#line 6251 "parser.tab.c"
    break;

  case 295: /* VariableDeclaratorList: VariableDeclarator  */
#line 1143 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->variables.push_back((yyvsp[0].typeinfo)->variable);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->decorders2.push_back(((yyvsp[0].typeinfo))->decorder2);(yyval.typeinfo)->arrtypes.push_back((yyvsp[0].typeinfo)->arrtype);(yyval.typeinfo)->arrdims.push_back((yyvsp[0].typeinfo)->arrdim);(yyval.typeinfo)->initialdecls.push_back((yyvsp[0].typeinfo)->initialdecl);(yyval.typeinfo)->initvartypes.push_back((yyvsp[0].typeinfo)->initvartype);((yyval.typeinfo))->puvariables = ((yyvsp[0].typeinfo))->puvariables;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6257 "parser.tab.c"
    break;

  case 296: /* VariableDeclaratorList: VariableDeclaratorList COMMA VariableDeclarator  */
#line 1144 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-2].typeinfo);((yyval.typeinfo))->variables.push_back((yyvsp[0].typeinfo)->variable);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->decorders2.push_back(((yyvsp[0].typeinfo))->decorder2);(yyval.typeinfo)->arrtypes.push_back((yyvsp[0].typeinfo)->arrtype);(yyval.typeinfo)->arrdims.push_back((yyvsp[0].typeinfo)->arrdim);(yyval.typeinfo)->initialdecls.push_back((yyvsp[0].typeinfo)->initialdecl);(yyval.typeinfo)->initvartypes.push_back((yyvsp[0].typeinfo)->initvartype);vector<string>a=((yyvsp[-2].typeinfo))->puvariables;vector<string>b=((yyvsp[0].typeinfo))->puvariables;for(auto z:a){((yyval.typeinfo))->puvariables.push_back(z);}for(auto z:b){((yyval.typeinfo))->puvariables.push_back(z);} (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6263 "parser.tab.c"
    break;

  case 297: /* VariableDeclarator: VariableDeclaratorId  */
#line 1146 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->initialdecl=false;((yyval.typeinfo))->puvariables = ((yyvsp[0].typeinfo))->puvariables;(yyval.typeinfo)->tac=emptyvector();}
#line 6269 "parser.tab.c"
    break;

  case 298: /* VariableDeclarator: VariableDeclaratorId EQUAL VariableInitializer  */
#line 1147 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-2].typeinfo);(yyval.typeinfo)->initialdecl=true;(yyval.typeinfo)->arrtype=(yyvsp[0].typeinfo)->arrtype;(yyval.typeinfo)->arrdim=(yyvsp[0].typeinfo)->arrdim;(yyval.typeinfo)->initvartype=(yyvsp[0].typeinfo)->initvartype;string c=(yyvsp[-2].typeinfo)->tempname+"="+(yyvsp[0].typeinfo)->tempname;((yyval.typeinfo))->puvariables = ((yyvsp[-2].typeinfo))->puvariables;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,c);}
#line 6275 "parser.tab.c"
    break;

  case 299: /* VariableDeclaratorId: Identifier  */
#line 1149 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();string p=((yyvsp[0].str));(yyval.typeinfo)->variable=p;(yyval.typeinfo)->decorder2=0;string x=(yyvsp[0].str);(yyval.typeinfo)->tempname=x;((yyval.typeinfo))->puvariables.push_back(x);}
#line 6281 "parser.tab.c"
    break;

  case 300: /* VariableDeclaratorId: Identifier OMPSB  */
#line 1150 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();string p=((yyvsp[-1].str));(yyval.typeinfo)->variable=p;(yyval.typeinfo)->decorder2=(yyvsp[0].typeinfo)->order;string x=(yyvsp[-1].str);(yyval.typeinfo)->tempname=x;((yyval.typeinfo))->puvariables.push_back(x);}
#line 6287 "parser.tab.c"
    break;

  case 301: /* VariableInitializer: Expression  */
#line 1153 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 6293 "parser.tab.c"
    break;

  case 302: /* VariableInitializer: ArrayInitializer  */
#line 1154 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->arrtype=(yyvsp[0].typeinfo)->arrtype;(yyval.typeinfo)->arrdim=(yyvsp[0].typeinfo)->arrdim;(yyval.typeinfo)->initvartype="";}
#line 6299 "parser.tab.c"
    break;

  case 303: /* UnannType: UnannPrimitiveType  */
#line 1156 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->dectype=(yyvsp[0].typeinfo)->type;(yyvsp[0].typeinfo)->decorder1=0;}
#line 6305 "parser.tab.c"
    break;

  case 304: /* UnannType: Identifier  */
#line 1157 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();string p = (yyvsp[0].str);((yyval.typeinfo))->type = p;(yyval.typeinfo)->tempname=p;(yyval.typeinfo)->decorder1=0; (yyval.typeinfo)->dectype="";}
#line 6311 "parser.tab.c"
    break;

  case 305: /* UnannType: UnannArrayType  */
#line 1158 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type=((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->dectype=(yyvsp[0].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[0].typeinfo)->decorder1;}
#line 6317 "parser.tab.c"
    break;

  case 306: /* UnannPrimitiveType: NumericType  */
#line 1160 "parser.y"
                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=emptyvector();}
#line 6323 "parser.tab.c"
    break;

  case 307: /* UnannPrimitiveType: BOOLEAN  */
#line 1161 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";(yyval.typeinfo)->tac=emptyvector();}
#line 6329 "parser.tab.c"
    break;

  case 308: /* UnannArrayType: UnannPrimitiveType OMPSB  */
#line 1163 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type + ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->dectype=(yyvsp[-1].typeinfo)->type;(yyval.typeinfo)->decorder1=(yyvsp[0].typeinfo)->order;(yyval.typeinfo)->tac=emptyvector();}
#line 6335 "parser.tab.c"
    break;

  case 309: /* UnannArrayType: Identifier OMPSB  */
#line 1164 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();string p = (yyvsp[-1].str);((yyval.typeinfo))->type = p + ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->dectype="";(yyval.typeinfo)->decorder1=(yyvsp[0].typeinfo)->order;(yyval.typeinfo)->tac=emptyvector();}
#line 6341 "parser.tab.c"
    break;

  case 310: /* MethodDeclaration: MethodHeader MethodBody  */
#line 1167 "parser.y"
                                                                {goparent();insertmethod(((yyvsp[-1].typeinfo))->variables[0],"Method",((yyvsp[-1].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-1].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-1].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="function end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z,sv,p);}
#line 6347 "parser.tab.c"
    break;

  case 311: /* MethodDeclaration: OMClassModifier MethodHeader MethodBody  */
#line 1168 "parser.y"
                                                                                {goparent();insertmethod(((yyvsp[-1].typeinfo))->variables[0],"Method",((yyvsp[-1].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-1].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="function end"; stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st); 	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z,sv,p);}
#line 6353 "parser.tab.c"
    break;

  case 312: /* MethodHeader: Result MethodDeclarator  */
#line 1170 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;((yyval.typeinfo))->variables = ((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;((yyval.typeinfo))->scope =((yyvsp[-1].typeinfo))->scope;((yyval.typeinfo))->linep = ((yyvsp[0].typeinfo))->linep;(yyval.typeinfo)->tempname=((yyvsp[-1].typeinfo))->tempname; string f = ((yyvsp[-1].typeinfo))->tempname; string q=newmethodlabel(f);string p="call "+((yyvsp[-1].typeinfo))->tempname+"\n"+q;(yyval.typeinfo)->tac=concvector(p,(yyvsp[0].typeinfo)->tac);}
#line 6359 "parser.tab.c"
    break;

  case 313: /* MethodHeader: Result MethodDeclarator Throws  */
#line 1171 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;((yyval.typeinfo))->variables = ((yyvsp[-2].typeinfo))->variables;((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;((yyval.typeinfo))->scope =((yyvsp[-2].typeinfo))->scope;((yyval.typeinfo))->linep = ((yyvsp[-1].typeinfo))->linep;(yyval.typeinfo)->tempname=((yyvsp[-2].typeinfo))->tempname; string f = ((yyvsp[-2].typeinfo))->tempname; string q=newmethodlabel(f);string p="call "+((yyvsp[-2].typeinfo))->tempname+"\n"+q; (yyval.typeinfo)->tac=concvector(p,(yyvsp[-1].typeinfo)->tac);}
#line 6365 "parser.tab.c"
    break;

  case 314: /* MethodHeader: TypeParameters Result MethodDeclarator  */
#line 1172 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;((yyval.typeinfo))->variables = ((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;((yyval.typeinfo))->scope =((yyvsp[-1].typeinfo))->scope;((yyval.typeinfo))->linep = ((yyvsp[0].typeinfo))->linep;(yyval.typeinfo)->tempname=((yyvsp[-1].typeinfo))->tempname; string f = ((yyvsp[-1].typeinfo))->tempname; string q=newmethodlabel(f);string p="call "+((yyvsp[-1].typeinfo))->tempname+"\n"+q; (yyval.typeinfo)->tac=concvector(p,(yyvsp[0].typeinfo)->tac);}
#line 6371 "parser.tab.c"
    break;

  case 315: /* MethodHeader: TypeParameters Result MethodDeclarator Throws  */
#line 1173 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;((yyval.typeinfo))->variables = ((yyvsp[-2].typeinfo))->variables;((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;((yyval.typeinfo))->scope =((yyvsp[-2].typeinfo))->scope;((yyval.typeinfo))->linep = ((yyvsp[-1].typeinfo))->linep;(yyval.typeinfo)->tempname=((yyvsp[-2].typeinfo))->tempname; string f = ((yyvsp[-2].typeinfo))->tempname; string q=newmethodlabel(f);string p="call "+((yyvsp[-2].typeinfo))->tempname+"\n"+q; (yyval.typeinfo)->tac=concvector(p,(yyvsp[-1].typeinfo)->tac);}
#line 6377 "parser.tab.c"
    break;

  case 316: /* Result: UnannType Identifier  */
#line 1175 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();symtable*a = createscope("Method");((yyval.typeinfo))->scope = a; ((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;string p = (yyvsp[0].str);((yyval.typeinfo))->variables.push_back(p); changescope(a);string x=(yyvsp[0].str); (yyval.typeinfo)->tempname=x;(yyval.typeinfo)->tac=emptyvector();}
#line 6383 "parser.tab.c"
    break;

  case 317: /* Result: VOID Identifier  */
#line 1176 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();symtable*a = createscope("Method");((yyval.typeinfo))->scope = a;((yyval.typeinfo))->type = "void";string p = (yyvsp[0].str);((yyval.typeinfo))->variables.push_back(p); changescope(a);string x=(yyvsp[0].str); (yyval.typeinfo)->tempname=x;(yyval.typeinfo)->tac=emptyvector();}
#line 6389 "parser.tab.c"
    break;

  case 318: /* MethodDeclarator: LRB RRB  */
#line 1179 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back("void");((yyval.typeinfo))->linep = line; (yyval.typeinfo)->tac=emptyvector();}
#line 6395 "parser.tab.c"
    break;

  case 319: /* MethodDeclarator: LRB RRB OMPSB  */
#line 1180 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct(); (yyval.typeinfo)->tac=emptyvector();}
#line 6401 "parser.tab.c"
    break;

  case 320: /* MethodDeclarator: LRB FormalParameterList RRB  */
#line 1181 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;((yyval.typeinfo))->linep = line;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6407 "parser.tab.c"
    break;

  case 321: /* MethodDeclarator: LRB FormalParameterList RRB OMPSB  */
#line 1182 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 6413 "parser.tab.c"
    break;

  case 322: /* MethodDeclarator: LRB ReceiverParameterComma RRB  */
#line 1183 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6419 "parser.tab.c"
    break;

  case 323: /* MethodDeclarator: LRB ReceiverParameterComma RRB OMPSB  */
#line 1184 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 6425 "parser.tab.c"
    break;

  case 324: /* MethodDeclarator: LRB ReceiverParameterComma FormalParameterList RRB  */
#line 1185 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;((yyval.typeinfo))->linep = line;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6431 "parser.tab.c"
    break;

  case 325: /* MethodDeclarator: LRB ReceiverParameterComma FormalParameterList RRB OMPSB  */
#line 1186 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 6437 "parser.tab.c"
    break;

  case 326: /* ReceiverParameter: UnannType THIS  */
#line 1188 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6443 "parser.tab.c"
    break;

  case 327: /* ReceiverParameter: UnannType IdentifierDot THIS  */
#line 1189 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6449 "parser.tab.c"
    break;

  case 328: /* FormalParameterList: FormalParameter  */
#line 1191 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6455 "parser.tab.c"
    break;

  case 329: /* FormalParameterList: FormalParameter OMCommaFormalParameter  */
#line 1192 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();vector<string>a=((yyvsp[-1].typeinfo))->type_variable;vector<string>b=((yyvsp[0].typeinfo))->type_variable;for(auto z:a){((yyval.typeinfo))->type_variable.push_back(z);}for(auto z:b){((yyval.typeinfo))->type_variable.push_back(z);}(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6461 "parser.tab.c"
    break;

  case 330: /* FormalParameter: UnannType VariableDeclaratorId  */
#line 1194 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-1].typeinfo))->type+((yyvsp[0].typeinfo))->type);((yyval.typeinfo))->type=((yyvsp[-1].typeinfo))->type+((yyvsp[0].typeinfo))->type;for(auto z:((yyvsp[0].typeinfo))->variables)insertidentifier(z,((yyval.typeinfo))->type,"",line);(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6467 "parser.tab.c"
    break;

  case 331: /* FormalParameter: OMClassModifier UnannType VariableDeclaratorId  */
#line 1195 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-1].typeinfo))->type+((yyvsp[0].typeinfo))->type);((yyval.typeinfo))->type=((yyvsp[-1].typeinfo))->type+((yyvsp[0].typeinfo))->type;for(auto z:((yyvsp[0].typeinfo))->variables)insertidentifier(z,((yyval.typeinfo))->type,"",line);(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6473 "parser.tab.c"
    break;

  case 332: /* FormalParameter: VariableArityParameter  */
#line 1196 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6479 "parser.tab.c"
    break;

  case 333: /* VariableArityParameter: UnannType THREEDOT Identifier  */
#line 1198 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-2].typeinfo))->type);(yyval.typeinfo)->tac=emptyvector();}
#line 6485 "parser.tab.c"
    break;

  case 334: /* VariableArityParameter: OMClassModifier UnannType THREEDOT Identifier  */
#line 1199 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-2].typeinfo))->type);(yyval.typeinfo)->tac=emptyvector();}
#line 6491 "parser.tab.c"
    break;

  case 335: /* Throws: THROWS ExceptionTypeList  */
#line 1201 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6497 "parser.tab.c"
    break;

  case 336: /* ExceptionTypeList: ExceptionType  */
#line 1203 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6503 "parser.tab.c"
    break;

  case 337: /* ExceptionTypeList: ExceptionType OMCommaExceptionType  */
#line 1204 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6509 "parser.tab.c"
    break;

  case 338: /* ExceptionType: Identifier  */
#line 1206 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6515 "parser.tab.c"
    break;

  case 339: /* MethodBody: Block  */
#line 1209 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6521 "parser.tab.c"
    break;

  case 340: /* MethodBody: SEMICOLON  */
#line 1210 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6527 "parser.tab.c"
    break;

  case 341: /* InstanceInitializer: Block  */
#line 1212 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6533 "parser.tab.c"
    break;

  case 342: /* StaticInitializer: STATIC Block  */
#line 1214 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6539 "parser.tab.c"
    break;

  case 343: /* ConstructorDeclaration: ConstructorDeclarator ConstructorBody  */
#line 1217 "parser.y"
                                                                                {goparent();insertmethod(((yyvsp[-1].typeinfo))->variables[0],"constructor",((yyvsp[-1].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-1].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-1].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z,sv,p);}
#line 6545 "parser.tab.c"
    break;

  case 344: /* ConstructorDeclaration: ConstructorDeclarator Throws ConstructorBody  */
#line 1218 "parser.y"
                                                                                        {goparent();insertmethod(((yyvsp[-2].typeinfo))->variables[0],"constructor",((yyvsp[-2].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-2].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z,sv,p);}
#line 6551 "parser.tab.c"
    break;

  case 345: /* ConstructorDeclaration: OMClassModifier ConstructorDeclarator ConstructorBody  */
#line 1219 "parser.y"
                                                                                        {goparent();insertmethod(((yyvsp[-1].typeinfo))->variables[0],"constructor",((yyvsp[-1].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-1].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-1].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z,sv,p);}
#line 6557 "parser.tab.c"
    break;

  case 346: /* ConstructorDeclaration: OMClassModifier ConstructorDeclarator Throws ConstructorBody  */
#line 1220 "parser.y"
                                                                                {goparent();insertmethod(((yyvsp[-2].typeinfo))->variables[0],"constructor",((yyvsp[-2].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-2].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z,sv,p);}
#line 6563 "parser.tab.c"
    break;

  case 347: /* ConstructorDeclaratorLRBSym: LRB  */
#line 1222 "parser.y"
                                 {(yyval.typeinfo) = createstruct();symtable*a = createscope("constructor");((yyval.typeinfo))->scope = a; changescope(a);}
#line 6569 "parser.tab.c"
    break;

  case 348: /* ConstructorDeclarator: Identifier ConstructorDeclaratorLRBSym RRB  */
#line 1224 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->scope = ((yyvsp[-1].typeinfo))->scope; ((yyval.typeinfo))->type_variable.push_back("void");string p = (yyvsp[-2].str);((yyval.typeinfo))->variables.push_back(p);((yyval.typeinfo))->type = "void";((yyval.typeinfo))->linep = line;string x = (yyvsp[-2].str);(yyval.typeinfo)->tempname=x;  string q=newmethodlabel(x);string g="call "+x+"\n"+q;(yyval.typeinfo)->tac=concvector(g);}
#line 6575 "parser.tab.c"
    break;

  case 349: /* ConstructorDeclarator: Identifier ConstructorDeclaratorLRBSym FormalParameterList RRB  */
#line 1225 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->scope = ((yyvsp[-2].typeinfo))->scope;((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;string p = (yyvsp[-3].str);((yyval.typeinfo))->variables.push_back(p);((yyval.typeinfo))->type = "void";((yyval.typeinfo))->linep = line;string x = (yyvsp[-3].str);(yyval.typeinfo)->tempname=x;  string q=newmethodlabel(x);string g="call "+x+"\n"+q;(yyval.typeinfo)->tac=concvector(g,(yyvsp[-1].typeinfo)->tac);}
#line 6581 "parser.tab.c"
    break;

  case 350: /* ConstructorDeclarator: Identifier LRB ReceiverParameterComma RRB  */
#line 1226 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=emptyvector();}
#line 6587 "parser.tab.c"
    break;

  case 351: /* ConstructorDeclarator: Identifier LRB ReceiverParameterComma FormalParameterList RRB  */
#line 1227 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6593 "parser.tab.c"
    break;

  case 352: /* ConstructorDeclarator: TypeParameters Identifier ConstructorDeclaratorLRBSym RRB  */
#line 1228 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->scope = ((yyvsp[-1].typeinfo))->scope;((yyval.typeinfo))->type_variable.push_back("void");string p = (yyvsp[-2].str); ((yyval.typeinfo))->variables.push_back(p);((yyval.typeinfo))->type = "void";((yyval.typeinfo))->linep = line;string x = (yyvsp[-2].str);(yyval.typeinfo)->tempname=x;  string q=newmethodlabel(x);string g="call "+x+"\n"+q;(yyval.typeinfo)->tac=concvector(g);}
#line 6599 "parser.tab.c"
    break;

  case 353: /* ConstructorDeclarator: TypeParameters Identifier ConstructorDeclaratorLRBSym FormalParameterList RRB  */
#line 1229 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->scope = ((yyvsp[-2].typeinfo))->scope;((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;string p = (yyvsp[-3].str);((yyval.typeinfo))->variables.push_back(p);((yyval.typeinfo))->type = "void";((yyval.typeinfo))->linep = line;string x = (yyvsp[-3].str);(yyval.typeinfo)->tempname=x;  string q=newmethodlabel(x);string g="call "+x+"\n"+q;(yyval.typeinfo)->tac=concvector(g,(yyvsp[-1].typeinfo)->tac);}
#line 6605 "parser.tab.c"
    break;

  case 354: /* ConstructorDeclarator: TypeParameters Identifier LRB ReceiverParameterComma RRB  */
#line 1230 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6611 "parser.tab.c"
    break;

  case 355: /* ConstructorDeclarator: TypeParameters Identifier LRB ReceiverParameterComma FormalParameterList RRB  */
#line 1231 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 6617 "parser.tab.c"
    break;

  case 356: /* ConstructorBody: LCB RCB  */
#line 1234 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6623 "parser.tab.c"
    break;

  case 357: /* ConstructorBody: LCB BlockStatements RCB  */
#line 1235 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6629 "parser.tab.c"
    break;

  case 358: /* ConstructorBody: LCB ExplicitConstructorInvocation RCB  */
#line 1236 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6635 "parser.tab.c"
    break;

  case 359: /* ConstructorBody: LCB ExplicitConstructorInvocation BlockStatements RCB  */
#line 1237 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 6641 "parser.tab.c"
    break;

  case 360: /* ExplicitConstructorInvocation: THIS LRB RRB SEMICOLON  */
#line 1239 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters();string s = ((yyvsp[-3].str));((yyval.typeinfo))->tempname = "%rax";string s1 = gotomethod(s);string s2 = newmethodretlabel(s); (yyval.typeinfo)->tac=concvector(pv1,s1,s2,pv2);}
#line 6647 "parser.tab.c"
    break;

  case 361: /* ExplicitConstructorInvocation: THIS LRB ArgumentList RRB SEMICOLON  */
#line 1240 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters(); string s = ((yyvsp[-4].str));((yyval.typeinfo))->tempname = "%rax"; string s1 = gotomethod(s);string s2 = newmethodretlabel(s);vector<string> pushpar = pusharg(((yyvsp[-2].typeinfo))->params);(yyval.typeinfo)->tac=concvector(pv1,(yyvsp[-2].typeinfo)->tac,pushpar,s1,s2,pv2);}
#line 6653 "parser.tab.c"
    break;

  case 362: /* ExplicitConstructorInvocation: SUPER LRB RRB SEMICOLON  */
#line 1241 "parser.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6659 "parser.tab.c"
    break;

  case 363: /* ExplicitConstructorInvocation: SUPER LRB ArgumentList RRB SEMICOLON  */
#line 1242 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 6665 "parser.tab.c"
    break;

  case 364: /* ExplicitConstructorInvocation: Identifier DOT SUPER LRB RRB SEMICOLON  */
#line 1243 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6671 "parser.tab.c"
    break;

  case 365: /* ExplicitConstructorInvocation: Identifier DOT SUPER LRB ArgumentList RRB SEMICOLON  */
#line 1244 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 6677 "parser.tab.c"
    break;

  case 366: /* ExplicitConstructorInvocation: ExpressionName DOT SUPER LRB RRB SEMICOLON  */
#line 1245 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6683 "parser.tab.c"
    break;

  case 367: /* ExplicitConstructorInvocation: ExpressionName DOT SUPER LRB ArgumentList RRB SEMICOLON  */
#line 1246 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 6689 "parser.tab.c"
    break;

  case 368: /* ExplicitConstructorInvocation: Primary DOT SUPER LRB RRB SEMICOLON  */
#line 1247 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6695 "parser.tab.c"
    break;

  case 369: /* ExplicitConstructorInvocation: Primary DOT SUPER LRB ArgumentList RRB SEMICOLON  */
#line 1248 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 6701 "parser.tab.c"
    break;

  case 370: /* EnumDeclaration: ENUM Identifier EnumBody  */
#line 1250 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6707 "parser.tab.c"
    break;

  case 371: /* EnumDeclaration: ENUM Identifier ClassImplements EnumBody  */
#line 1251 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6713 "parser.tab.c"
    break;

  case 372: /* EnumDeclaration: OMClassModifier ENUM Identifier EnumBody  */
#line 1252 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6719 "parser.tab.c"
    break;

  case 373: /* EnumDeclaration: OMClassModifier ENUM Identifier ClassImplements EnumBody  */
#line 1253 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6725 "parser.tab.c"
    break;

  case 374: /* EnumBody: LCB RCB  */
#line 1256 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6731 "parser.tab.c"
    break;

  case 375: /* EnumBody: LCB EnumBodyDeclarations RCB  */
#line 1257 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6737 "parser.tab.c"
    break;

  case 376: /* EnumBody: LCB COMMA RCB  */
#line 1258 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6743 "parser.tab.c"
    break;

  case 377: /* EnumBody: LCB COMMA EnumBodyDeclarations RCB  */
#line 1259 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6749 "parser.tab.c"
    break;

  case 378: /* EnumBody: LCB EnumConstantList RCB  */
#line 1260 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6755 "parser.tab.c"
    break;

  case 379: /* EnumBody: LCB EnumConstantList EnumBodyDeclarations RCB  */
#line 1261 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 6761 "parser.tab.c"
    break;

  case 380: /* EnumConstantList: EnumConstant  */
#line 1263 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6767 "parser.tab.c"
    break;

  case 381: /* EnumConstantList: OMCommaEnumConstant  */
#line 1264 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6773 "parser.tab.c"
    break;

  case 382: /* PRB: LRB RRB  */
#line 1266 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6779 "parser.tab.c"
    break;

  case 383: /* PRBArgumentList: LRB ArgumentList RRB  */
#line 1268 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6785 "parser.tab.c"
    break;

  case 384: /* EnumConstant: Identifier  */
#line 1270 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6791 "parser.tab.c"
    break;

  case 385: /* EnumConstant: Identifier PRB  */
#line 1271 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6797 "parser.tab.c"
    break;

  case 386: /* EnumConstant: Identifier PRBArgumentList  */
#line 1272 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6803 "parser.tab.c"
    break;

  case 387: /* EnumConstant: Identifier ClassBody  */
#line 1273 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6809 "parser.tab.c"
    break;

  case 388: /* EnumConstant: Identifier PRB ClassBody  */
#line 1274 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6815 "parser.tab.c"
    break;

  case 389: /* EnumConstant: Identifier PRBArgumentList ClassBody  */
#line 1275 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6821 "parser.tab.c"
    break;

  case 390: /* EnumBodyDeclarations: SEMICOLON  */
#line 1277 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6827 "parser.tab.c"
    break;

  case 391: /* EnumBodyDeclarations: SEMICOLON OMClassBodyDeclaration  */
#line 1278 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6833 "parser.tab.c"
    break;

  case 392: /* RecordDeclarationSym: RECORD Identifier  */
#line 1280 "parser.y"
                                        {(yyval.typeinfo) = createstruct();symtable*a=createscope("record");((yyval.typeinfo))->scope = a; ((yyval.typeinfo))->type = "record";string p = (yyvsp[0].str);((yyval.typeinfo))->variables.push_back(p); changescope(a);}
#line 6839 "parser.tab.c"
    break;

  case 393: /* RecordDeclaration: RecordDeclarationSym RecordHeader RecordBody  */
#line 1282 "parser.y"
                                                                                                        {goparent();insertmethod(((yyvsp[-2].typeinfo))->variables[0],"record",((yyvsp[-2].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6845 "parser.tab.c"
    break;

  case 394: /* RecordDeclaration: RecordDeclarationSym RecordHeader ClassImplements RecordBody  */
#line 1283 "parser.y"
                                                                                                                        {goparent();insertmethod(((yyvsp[-3].typeinfo))->variables[0],"record",((yyvsp[-3].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-3].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6851 "parser.tab.c"
    break;

  case 395: /* RecordDeclaration: RecordDeclarationSym TypeParameters RecordHeader RecordBody  */
#line 1284 "parser.y"
                                                                                                                                                        {goparent();insertmethod(((yyvsp[-3].typeinfo))->variables[0],"record",((yyvsp[-3].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-3].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6857 "parser.tab.c"
    break;

  case 396: /* RecordDeclaration: RecordDeclarationSym TypeParameters RecordHeader ClassImplements RecordBody  */
#line 1285 "parser.y"
                                                                                                                        {goparent();insertmethod(((yyvsp[-4].typeinfo))->variables[0],"record",((yyvsp[-4].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-4].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6863 "parser.tab.c"
    break;

  case 397: /* RecordDeclaration: OMClassModifier RecordDeclarationSym RecordHeader RecordBody  */
#line 1286 "parser.y"
                                                                                                                                                        {goparent();insertmethod(((yyvsp[-2].typeinfo))->variables[0],"record",((yyvsp[-2].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6869 "parser.tab.c"
    break;

  case 398: /* RecordDeclaration: OMClassModifier RecordDeclarationSym RecordHeader ClassImplements RecordBody  */
#line 1287 "parser.y"
                                                                                                                {goparent();insertmethod(((yyvsp[-3].typeinfo))->variables[0],"record",((yyvsp[-3].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-3].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6875 "parser.tab.c"
    break;

  case 399: /* RecordDeclaration: OMClassModifier RecordDeclarationSym TypeParameters RecordHeader RecordBody  */
#line 1288 "parser.y"
                                                                                                                {goparent();insertmethod(((yyvsp[-3].typeinfo))->variables[0],"record",((yyvsp[-3].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-3].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6881 "parser.tab.c"
    break;

  case 400: /* RecordDeclaration: OMClassModifier RecordDeclarationSym TypeParameters RecordHeader ClassImplements RecordBody  */
#line 1289 "parser.y"
                                                                                                                        {goparent();insertmethod(((yyvsp[-4].typeinfo))->variables[0],"record",((yyvsp[-4].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-4].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6887 "parser.tab.c"
    break;

  case 401: /* RecordHeader: LRB RRB  */
#line 1292 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back("void");((yyval.typeinfo))->linep = line;(yyval.typeinfo)->tac=emptyvector();}
#line 6893 "parser.tab.c"
    break;

  case 402: /* RecordHeader: LRB RecordComponentList RRB  */
#line 1293 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;((yyval.typeinfo))->linep = line;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6899 "parser.tab.c"
    break;

  case 403: /* RecordComponentList: RecordComponent  */
#line 1295 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6905 "parser.tab.c"
    break;

  case 404: /* RecordComponentList: RecordComponent OMCommaRecordComponent  */
#line 1296 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();vector<string>a=((yyvsp[-1].typeinfo))->type_variable;vector<string>b=((yyvsp[0].typeinfo))->type_variable;for(auto z:a){((yyval.typeinfo))->type_variable.push_back(z);}for(auto z:b){((yyval.typeinfo))->type_variable.push_back(z);}(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6911 "parser.tab.c"
    break;

  case 405: /* RecordComponent: UnannType Identifier  */
#line 1298 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-1].typeinfo))->type);}
#line 6917 "parser.tab.c"
    break;

  case 406: /* RecordComponent: VariableArityRecordComponent  */
#line 1299 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;}
#line 6923 "parser.tab.c"
    break;

  case 407: /* VariableArityRecordComponent: UnannType THREEDOT Identifier  */
#line 1302 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-2].typeinfo))->type);(yyval.typeinfo)->tac=emptyvector();}
#line 6929 "parser.tab.c"
    break;

  case 408: /* RecordBody: LCB RCB  */
#line 1304 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6935 "parser.tab.c"
    break;

  case 409: /* RecordBody: LCB OMRecordBodyDeclaration RCB  */
#line 1305 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6941 "parser.tab.c"
    break;

  case 410: /* RecordBodyDeclaration: ClassBodyDeclaration  */
#line 1307 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6947 "parser.tab.c"
    break;

  case 411: /* RecordBodyDeclaration: CompactConstructorDeclaration  */
#line 1308 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6953 "parser.tab.c"
    break;

  case 412: /* CompactConstructorDeclarationSym: Identifier  */
#line 1310 "parser.y"
                                             {vector<string>tec; symtable*a=createscope("compactconstructor");string p=((yyvsp[0].str));insertmethod(p,"compactconstructor","auto",tec,a,"",line);changescope(a);}
#line 6959 "parser.tab.c"
    break;

  case 413: /* CompactConstructorDeclaration: CompactConstructorDeclarationSym ConstructorBody  */
#line 1312 "parser.y"
                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6965 "parser.tab.c"
    break;

  case 414: /* CompactConstructorDeclaration: OMClassModifier CompactConstructorDeclarationSym ConstructorBody  */
#line 1313 "parser.y"
                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6971 "parser.tab.c"
    break;

  case 415: /* InterfaceDeclaration: NormalInterfaceDeclaration  */
#line 1316 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6977 "parser.tab.c"
    break;

  case 416: /* $@41: %empty  */
#line 1318 "parser.y"
                                                      {symtable*a=createscope("interface");string p=((yyvsp[0].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 6983 "parser.tab.c"
    break;

  case 417: /* NormalInterfaceDeclaration: INTERFACE Identifier $@41 InterfaceBody  */
#line 1318 "parser.y"
                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6989 "parser.tab.c"
    break;

  case 418: /* $@42: %empty  */
#line 1319 "parser.y"
                                                                  {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 6995 "parser.tab.c"
    break;

  case 419: /* NormalInterfaceDeclaration: INTERFACE Identifier InterfacePermits $@42 InterfaceBody  */
#line 1319 "parser.y"
                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7001 "parser.tab.c"
    break;

  case 420: /* $@43: %empty  */
#line 1320 "parser.y"
                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7007 "parser.tab.c"
    break;

  case 421: /* NormalInterfaceDeclaration: INTERFACE Identifier InterfaceExtends $@43 InterfaceBody  */
#line 1320 "parser.y"
                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7013 "parser.tab.c"
    break;

  case 422: /* $@44: %empty  */
#line 1321 "parser.y"
                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7019 "parser.tab.c"
    break;

  case 423: /* NormalInterfaceDeclaration: INTERFACE Identifier InterfaceExtends InterfacePermits $@44 InterfaceBody  */
#line 1321 "parser.y"
                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7025 "parser.tab.c"
    break;

  case 424: /* $@45: %empty  */
#line 1322 "parser.y"
                                                                {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7031 "parser.tab.c"
    break;

  case 425: /* NormalInterfaceDeclaration: INTERFACE Identifier TypeParameters $@45 InterfaceBody  */
#line 1322 "parser.y"
                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7037 "parser.tab.c"
    break;

  case 426: /* $@46: %empty  */
#line 1323 "parser.y"
                                                                                {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7043 "parser.tab.c"
    break;

  case 427: /* NormalInterfaceDeclaration: INTERFACE Identifier TypeParameters InterfacePermits $@46 InterfaceBody  */
#line 1323 "parser.y"
                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7049 "parser.tab.c"
    break;

  case 428: /* $@47: %empty  */
#line 1324 "parser.y"
                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7055 "parser.tab.c"
    break;

  case 429: /* NormalInterfaceDeclaration: INTERFACE Identifier TypeParameters InterfaceExtends $@47 InterfaceBody  */
#line 1324 "parser.y"
                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7061 "parser.tab.c"
    break;

  case 430: /* $@48: %empty  */
#line 1325 "parser.y"
                                                                                                  {symtable*a=createscope("interface");string p=((yyvsp[-3].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7067 "parser.tab.c"
    break;

  case 431: /* NormalInterfaceDeclaration: INTERFACE Identifier TypeParameters InterfaceExtends InterfacePermits $@48 InterfaceBody  */
#line 1325 "parser.y"
                                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7073 "parser.tab.c"
    break;

  case 432: /* $@49: %empty  */
#line 1326 "parser.y"
                                                                {symtable*a=createscope("interface");string p=((yyvsp[0].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7079 "parser.tab.c"
    break;

  case 433: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier $@49 InterfaceBody  */
#line 1326 "parser.y"
                                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7085 "parser.tab.c"
    break;

  case 434: /* $@50: %empty  */
#line 1327 "parser.y"
                                                                                  {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7091 "parser.tab.c"
    break;

  case 435: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier InterfacePermits $@50 InterfaceBody  */
#line 1327 "parser.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7097 "parser.tab.c"
    break;

  case 436: /* $@51: %empty  */
#line 1328 "parser.y"
                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7103 "parser.tab.c"
    break;

  case 437: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier InterfaceExtends $@51 InterfaceBody  */
#line 1328 "parser.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7109 "parser.tab.c"
    break;

  case 438: /* $@52: %empty  */
#line 1329 "parser.y"
                                                                                                   {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7115 "parser.tab.c"
    break;

  case 439: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier InterfaceExtends InterfacePermits $@52 InterfaceBody  */
#line 1329 "parser.y"
                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7121 "parser.tab.c"
    break;

  case 440: /* $@53: %empty  */
#line 1330 "parser.y"
                                                                               {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7127 "parser.tab.c"
    break;

  case 441: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier TypeParameters $@53 InterfaceBody  */
#line 1330 "parser.y"
                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7133 "parser.tab.c"
    break;

  case 442: /* $@54: %empty  */
#line 1331 "parser.y"
                                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7139 "parser.tab.c"
    break;

  case 443: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier TypeParameters InterfacePermits $@54 InterfaceBody  */
#line 1331 "parser.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7145 "parser.tab.c"
    break;

  case 444: /* $@55: %empty  */
#line 1332 "parser.y"
                                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7151 "parser.tab.c"
    break;

  case 445: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier TypeParameters InterfaceExtends $@55 InterfaceBody  */
#line 1332 "parser.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7157 "parser.tab.c"
    break;

  case 446: /* $@56: %empty  */
#line 1333 "parser.y"
                                                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-3].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7163 "parser.tab.c"
    break;

  case 447: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier TypeParameters InterfaceExtends InterfacePermits $@56 InterfaceBody  */
#line 1333 "parser.y"
                                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7169 "parser.tab.c"
    break;

  case 448: /* InterfaceModifier: Modifieropt  */
#line 1336 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7175 "parser.tab.c"
    break;

  case 449: /* InterfaceExtends: EXTENDS InterfaceTypeList  */
#line 1338 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7181 "parser.tab.c"
    break;

  case 450: /* InterfacePermits: PERMITS ExpressionName  */
#line 1340 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7187 "parser.tab.c"
    break;

  case 451: /* InterfacePermits: PERMITS ExpressionName OMCommaTypeName  */
#line 1341 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7193 "parser.tab.c"
    break;

  case 452: /* InterfaceBody: LCB RCB  */
#line 1343 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 7199 "parser.tab.c"
    break;

  case 453: /* InterfaceBody: LCB OMInterfaceMemberDeclaration RCB  */
#line 1344 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7205 "parser.tab.c"
    break;

  case 454: /* InterfaceMemberDeclaration: ConstantDeclaration  */
#line 1346 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7211 "parser.tab.c"
    break;

  case 455: /* InterfaceMemberDeclaration: InterfaceMethodDeclaration  */
#line 1347 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7217 "parser.tab.c"
    break;

  case 456: /* InterfaceMemberDeclaration: ClassDeclaration  */
#line 1348 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7223 "parser.tab.c"
    break;

  case 457: /* InterfaceMemberDeclaration: InterfaceDeclaration  */
#line 1349 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7229 "parser.tab.c"
    break;

  case 458: /* InterfaceMemberDeclaration: SEMICOLON  */
#line 1350 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 7235 "parser.tab.c"
    break;

  case 459: /* ConstantDeclaration: UnannType VariableDeclaratorList SEMICOLON  */
#line 1352 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;((yyval.typeinfo))->puvariables=((yyvsp[-1].typeinfo))->puvariables;vector<string> s = pushlocal(((yyvsp[-1].typeinfo))->puvariables); (yyval.typeinfo)->tac=concvector(s,(yyvsp[-1].typeinfo)->tac);vector<string>a=((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type=((yyvsp[-2].typeinfo))->type+((yyvsp[-1].typeinfo))->type;for(auto z:a){insertidentifier(z,((yyvsp[-2].typeinfo))->type,"",line);}}
#line 7241 "parser.tab.c"
    break;

  case 460: /* ConstantDeclaration: OMClassModifier UnannType VariableDeclaratorList SEMICOLON  */
#line 1353 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;((yyval.typeinfo))->puvariables=((yyvsp[-1].typeinfo))->puvariables;vector<string> s = pushlocal(((yyvsp[-1].typeinfo))->puvariables); (yyval.typeinfo)->tac=concvector(s,(yyvsp[-1].typeinfo)->tac);vector<string>a=((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type=((yyvsp[-2].typeinfo))->type+((yyvsp[-1].typeinfo))->type;for(auto z:a){insertidentifier(z,((yyvsp[-2].typeinfo))->type,"",line);}}
#line 7247 "parser.tab.c"
    break;

  case 461: /* InterfaceMethodDeclaration: MethodHeader MethodBody  */
#line 1355 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-1].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="function end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z,sv,p);}
#line 7253 "parser.tab.c"
    break;

  case 462: /* InterfaceMethodDeclaration: OMClassModifier MethodHeader MethodBody  */
#line 1356 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-1].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="function end"; stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st); 	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z,sv,p);}
#line 7259 "parser.tab.c"
    break;

  case 463: /* ArrayInitializer: LCB RCB  */
#line 1358 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "[]";(yyval.typeinfo)->tac=emptyvector();}
#line 7265 "parser.tab.c"
    break;

  case 464: /* ArrayInitializer: LCB COMMA RCB  */
#line 1359 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "[]";(yyval.typeinfo)->tac=emptyvector();}
#line 7271 "parser.tab.c"
    break;

  case 465: /* ArrayInitializer: LCB VariableInitializerList RCB  */
#line 1360 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type =  ((yyvsp[-1].typeinfo))->type + "[]";(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7277 "parser.tab.c"
    break;

  case 466: /* VariableInitializerList: VariableInitializer  */
#line 1365 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type =  ((yyvsp[0].typeinfo))->type ;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7283 "parser.tab.c"
    break;

  case 467: /* VariableInitializerList: VariableInitializer COMMA VariableInitializerList  */
#line 1366 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type =  ((yyvsp[-2].typeinfo))->type; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7289 "parser.tab.c"
    break;

  case 468: /* Block: LCB RCB  */
#line 1368 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;vector<string>p={}; (yyval.typeinfo)->tac=p;}
#line 7295 "parser.tab.c"
    break;

  case 469: /* Block: LCB BlockStatements RCB  */
#line 1369 "parser.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 7301 "parser.tab.c"
    break;

  case 470: /* BlockStatements: BlockStatement  */
#line 1371 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7307 "parser.tab.c"
    break;

  case 471: /* BlockStatements: BlockStatement OMBlockStatement  */
#line 1372 "parser.y"
                                                                                                   {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7313 "parser.tab.c"
    break;

  case 472: /* BlockStatement: LocalClassOrInterfaceDeclaration  */
#line 1374 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7319 "parser.tab.c"
    break;

  case 473: /* BlockStatement: LocalVariableDeclarationStatement  */
#line 1375 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7325 "parser.tab.c"
    break;

  case 474: /* BlockStatement: Statement  */
#line 1376 "parser.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7331 "parser.tab.c"
    break;

  case 475: /* LocalClassOrInterfaceDeclaration: ClassDeclaration  */
#line 1378 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7337 "parser.tab.c"
    break;

  case 476: /* LocalClassOrInterfaceDeclaration: NormalInterfaceDeclaration  */
#line 1379 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7343 "parser.tab.c"
    break;

  case 477: /* LocalVariableDeclarationStatement: LocalVariableDeclaration SEMICOLON  */
#line 1381 "parser.y"
                                                                                        {(yyval.typeinfo)=createstruct();(yyval.typeinfo)=(yyvsp[-1].typeinfo);
	
    (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;
}
#line 7352 "parser.tab.c"
    break;

  case 478: /* LocalVariableDeclaration: LocalVariableType VariableDeclaratorList  */
#line 1386 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->dectype=(yyvsp[-1].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[-1].typeinfo)->decorder1;((yyval.typeinfo))->variables=((yyvsp[0].typeinfo))->variables;(yyval.typeinfo)->decorders2=(yyvsp[0].typeinfo)->decorders2;(yyval.typeinfo)->arrtypes=(yyvsp[0].typeinfo)->arrtypes;(yyval.typeinfo)->arrdims=(yyvsp[0].typeinfo)->arrdims;(yyval.typeinfo)->initvartypes=(yyvsp[0].typeinfo)->initvartypes;((yyval.typeinfo))->puvariables=((yyvsp[0].typeinfo))->puvariables;vector<string> s = pushlocal(((yyvsp[0].typeinfo))->puvariables);
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
            // cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
        }
        else{
            vector<int>p(order,0);
            insertidentifier((yyval.typeinfo)->variables[i],x,(yyval.typeinfo)->dectype,"",0,order,p);
            // cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
        }
    }
    (yyval.typeinfo)->tac=concvector(s,(yyvsp[0].typeinfo)->tac);}
#line 7378 "parser.tab.c"
    break;

  case 479: /* LocalVariableDeclaration: OMClassModifier LocalVariableType VariableDeclaratorList  */
#line 1407 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->dectype=(yyvsp[-1].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[-1].typeinfo)->decorder1;((yyval.typeinfo))->variables=((yyvsp[0].typeinfo))->variables;(yyval.typeinfo)->decorders2=(yyvsp[0].typeinfo)->decorders2;(yyval.typeinfo)->arrtypes=(yyvsp[0].typeinfo)->arrtypes;(yyval.typeinfo)->arrdims=(yyvsp[0].typeinfo)->arrdims;(yyval.typeinfo)->initvartypes=(yyvsp[0].typeinfo)->initvartypes; ((yyval.typeinfo))->puvariables=((yyvsp[0].typeinfo))->puvariables;vector<string> s = pushlocal(((yyvsp[0].typeinfo))->puvariables);
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
            // cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
        }
        else{
            vector<int>p(order,0);
            insertidentifier((yyval.typeinfo)->variables[i],x,(yyval.typeinfo)->dectype,"",0,order,p);
            // cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
        }
    }
     (yyval.typeinfo)->tac=concvector(s,(yyvsp[0].typeinfo)->tac);}
#line 7404 "parser.tab.c"
    break;

  case 480: /* LocalVariableType: UnannType  */
#line 1429 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;((yyval.typeinfo))->type=((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->dectype=(yyvsp[0].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[0].typeinfo)->decorder1;}
#line 7410 "parser.tab.c"
    break;

  case 481: /* LocalVariableType: VAR  */
#line 1430 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac= emptyvector();((yyval.typeinfo))->type="all";(yyval.typeinfo)->dectype="all";(yyval.typeinfo)->decorder1=0;}
#line 7416 "parser.tab.c"
    break;

  case 482: /* Statement: StatementWithoutTrailingSubstatement  */
#line 1432 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7422 "parser.tab.c"
    break;

  case 483: /* Statement: LabeledStatement  */
#line 1433 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7428 "parser.tab.c"
    break;

  case 484: /* Statement: IfThenStatement  */
#line 1434 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7434 "parser.tab.c"
    break;

  case 485: /* Statement: IfThenElseStatement  */
#line 1435 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7440 "parser.tab.c"
    break;

  case 486: /* Statement: WhileStatement  */
#line 1436 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7446 "parser.tab.c"
    break;

  case 487: /* Statement: ForStatement  */
#line 1437 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7452 "parser.tab.c"
    break;

  case 488: /* StatementNoShortIf: StatementWithoutTrailingSubstatement  */
#line 1439 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7458 "parser.tab.c"
    break;

  case 489: /* StatementNoShortIf: LabeledStatementNoShortIf  */
#line 1440 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7464 "parser.tab.c"
    break;

  case 490: /* StatementNoShortIf: IfThenElseStatementNoShortIf  */
#line 1441 "parser.y"
                                                                            {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7470 "parser.tab.c"
    break;

  case 491: /* StatementNoShortIf: WhileStatementNoShortIf  */
#line 1442 "parser.y"
                                                                            {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7476 "parser.tab.c"
    break;

  case 492: /* StatementNoShortIf: ForStatementNoShortIf  */
#line 1443 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7482 "parser.tab.c"
    break;

  case 493: /* $@57: %empty  */
#line 1445 "parser.y"
                                        {symtable *a = createscope("statement");insertclass("statement","statement","",a,line); changescope(a);flag = 0;}
#line 7488 "parser.tab.c"
    break;

  case 494: /* StatementWithoutTrailingSubstatement: $@57 Block  */
#line 1445 "parser.y"
                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7494 "parser.tab.c"
    break;

  case 495: /* StatementWithoutTrailingSubstatement: EmptyStatement  */
#line 1446 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7500 "parser.tab.c"
    break;

  case 496: /* StatementWithoutTrailingSubstatement: ExpressionStatement  */
#line 1447 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7506 "parser.tab.c"
    break;

  case 497: /* StatementWithoutTrailingSubstatement: AssertStatement  */
#line 1448 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7512 "parser.tab.c"
    break;

  case 498: /* StatementWithoutTrailingSubstatement: SwitchStatement  */
#line 1449 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7518 "parser.tab.c"
    break;

  case 499: /* StatementWithoutTrailingSubstatement: DoStatement  */
#line 1450 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7524 "parser.tab.c"
    break;

  case 500: /* StatementWithoutTrailingSubstatement: BreakStatement  */
#line 1451 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7530 "parser.tab.c"
    break;

  case 501: /* StatementWithoutTrailingSubstatement: ContinueStatement  */
#line 1452 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7536 "parser.tab.c"
    break;

  case 502: /* StatementWithoutTrailingSubstatement: ReturnStatement  */
#line 1453 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7542 "parser.tab.c"
    break;

  case 503: /* StatementWithoutTrailingSubstatement: SynchronizedStatement  */
#line 1454 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7548 "parser.tab.c"
    break;

  case 504: /* StatementWithoutTrailingSubstatement: ThrowStatement  */
#line 1455 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7554 "parser.tab.c"
    break;

  case 505: /* StatementWithoutTrailingSubstatement: TryStatement  */
#line 1456 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7560 "parser.tab.c"
    break;

  case 506: /* StatementWithoutTrailingSubstatement: YieldStatement  */
#line 1457 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7566 "parser.tab.c"
    break;

  case 507: /* EmptyStatement: SEMICOLON  */
#line 1459 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; vector<string>p={}; (yyval.typeinfo)->tac=p;}
#line 7572 "parser.tab.c"
    break;

  case 508: /* LabeledStatement: Identifier COLON Statement  */
#line 1461 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7578 "parser.tab.c"
    break;

  case 509: /* LabeledStatementNoShortIf: Identifier COLON StatementNoShortIf  */
#line 1463 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7584 "parser.tab.c"
    break;

  case 510: /* ExpressionStatement: StatementExpression SEMICOLON  */
#line 1466 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[-1].typeinfo)->tempname;}
#line 7590 "parser.tab.c"
    break;

  case 511: /* StatementExpression: Assignment  */
#line 1468 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 7596 "parser.tab.c"
    break;

  case 512: /* StatementExpression: PreIncrementExpression  */
#line 1469 "parser.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 7602 "parser.tab.c"
    break;

  case 513: /* StatementExpression: PreDecrementExpression  */
#line 1470 "parser.y"
                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 7608 "parser.tab.c"
    break;

  case 514: /* StatementExpression: PostIncrementExpression  */
#line 1471 "parser.y"
                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 7614 "parser.tab.c"
    break;

  case 515: /* StatementExpression: PostDecrementExpression  */
#line 1472 "parser.y"
                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 7620 "parser.tab.c"
    break;

  case 516: /* StatementExpression: MethodInvocation  */
#line 1473 "parser.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 7626 "parser.tab.c"
    break;

  case 517: /* StatementExpression: ClassInstanceCreationExpression  */
#line 1474 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 7632 "parser.tab.c"
    break;

  case 518: /* IfThenStatement: IF LRB Expression RRB Statement  */
#line 1476 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo;int lv=labelvariable;string a=newlabel();string ret="if zero "+((yyvsp[-2].typeinfo))->tempname+gotoo(lv+1);(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,a);}
#line 7638 "parser.tab.c"
    break;

  case 519: /* IfThenElseStatement: IF LRB Expression RRB StatementNoShortIf ELSE Statement  */
#line 1478 "parser.y"
                                                                              {(yyval.typeinfo)=new Typeinfo;int lv=labelvariable;string a=newlabel();string ret="if zero "+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+1);(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,ret,(yyvsp[-2].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac);}
#line 7644 "parser.tab.c"
    break;

  case 520: /* IfThenElseStatementNoShortIf: IF LRB Expression RRB StatementNoShortIf ELSE StatementNoShortIf  */
#line 1480 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;int lv=labelvariable;string a=newlabel();string ret="if zero "+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+1);(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,ret,(yyvsp[-2].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac);}
#line 7650 "parser.tab.c"
    break;

  case 521: /* AssertStatement: ASSERT Expression SEMICOLON  */
#line 1482 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7656 "parser.tab.c"
    break;

  case 522: /* AssertStatement: ASSERT Expression COLON Expression SEMICOLON  */
#line 1483 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 7662 "parser.tab.c"
    break;

  case 523: /* $@58: %empty  */
#line 1485 "parser.y"
                                                   {symtable *a = createscope("switch"); changescope(a);}
#line 7668 "parser.tab.c"
    break;

  case 524: /* SwitchStatement: SWITCH LRB Expression RRB $@58 SwitchBlock  */
#line 1485 "parser.y"
                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7674 "parser.tab.c"
    break;

  case 525: /* SwitchBlock: LCB SwitchRule RCB  */
#line 1487 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7680 "parser.tab.c"
    break;

  case 526: /* SwitchBlock: LCB SwitchRule OMSwitchRule RCB  */
#line 1488 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 7686 "parser.tab.c"
    break;

  case 527: /* SwitchBlock: LCB RCB  */
#line 1489 "parser.y"
                                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7692 "parser.tab.c"
    break;

  case 528: /* SwitchBlock: LCB OMSwitchLabelColon RCB  */
#line 1490 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7698 "parser.tab.c"
    break;

  case 529: /* SwitchBlock: LCB OMSwitchBlockStatementGroup RCB  */
#line 1491 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7704 "parser.tab.c"
    break;

  case 530: /* SwitchBlock: LCB OMSwitchBlockStatementGroup OMSwitchLabelColon RCB  */
#line 1492 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 7710 "parser.tab.c"
    break;

  case 531: /* SwitchRule: SwitchLabel IMPLIES Expression SEMICOLON  */
#line 1494 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 7716 "parser.tab.c"
    break;

  case 532: /* SwitchRule: SwitchLabel IMPLIES Block  */
#line 1495 "parser.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7722 "parser.tab.c"
    break;

  case 533: /* SwitchRule: SwitchLabel IMPLIES ThrowStatement  */
#line 1496 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7728 "parser.tab.c"
    break;

  case 534: /* SwitchBlockStatementGroup: SwitchLabel COLON BlockStatements  */
#line 1498 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7734 "parser.tab.c"
    break;

  case 535: /* SwitchBlockStatementGroup: SwitchLabel COLON OMSwitchLabelColon BlockStatements  */
#line 1499 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7740 "parser.tab.c"
    break;

  case 536: /* SwitchLabel: CASE CaseConstant  */
#line 1501 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7746 "parser.tab.c"
    break;

  case 537: /* SwitchLabel: CASE CaseConstant OMCommaCaseConstant  */
#line 1502 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7752 "parser.tab.c"
    break;

  case 538: /* SwitchLabel: DEFAULT  */
#line 1503 "parser.y"
                                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7758 "parser.tab.c"
    break;

  case 539: /* CaseConstant: ConditionalExpression  */
#line 1505 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7764 "parser.tab.c"
    break;

  case 540: /* WhileStatement: WHILE LRB Expression RRB Statement  */
#line 1507 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; int c=labelvariable; string a=newlabel();string b=newlabel();string z=gotoo(c+2);string d="if zero "+(((yyvsp[-2].typeinfo))->tempname)+z;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,a,d,(yyvsp[0].typeinfo)->tac,gotoo(c+1),b);}
#line 7770 "parser.tab.c"
    break;

  case 541: /* WhileStatementNoShortIf: WHILE LRB Expression RRB StatementNoShortIf  */
#line 1509 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; int c=labelvariable; string a=newlabel();string z=gotoo(c+2);string b=newlabel();string d="if zero "+(((yyvsp[-2].typeinfo))->tempname)+z;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,a,d,(yyvsp[0].typeinfo)->tac,gotoo(c+1),b);}
#line 7776 "parser.tab.c"
    break;

  case 542: /* DoStatement: DO Statement WHILE LRB Expression RRB SEMICOLON  */
#line 1511 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; string p=gotoo(labelvariable); (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,p);}
#line 7782 "parser.tab.c"
    break;

  case 543: /* ForStatement: BasicForStatement  */
#line 1513 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7788 "parser.tab.c"
    break;

  case 544: /* ForStatement: EnhancedForStatement  */
#line 1514 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7794 "parser.tab.c"
    break;

  case 545: /* ForStatementNoShortIf: BasicForStatementNoShortIf  */
#line 1516 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7800 "parser.tab.c"
    break;

  case 546: /* ForStatementNoShortIf: EnhancedForStatementNoShortIf  */
#line 1517 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7806 "parser.tab.c"
    break;

  case 547: /* ForSym: FOR  */
#line 1519 "parser.y"
                {symtable*a=createscope("for");insertclass("for","for","",a,line); changescope(a);}
#line 7812 "parser.tab.c"
    break;

  case 548: /* BasicForStatement: ForSym LRB SEMICOLON SEMICOLON RRB Statement  */
#line 1521 "parser.y"
                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector(a,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7818 "parser.tab.c"
    break;

  case 549: /* BasicForStatement: ForSym LRB SEMICOLON SEMICOLON ForUpdate RRB Statement  */
#line 1522 "parser.y"
                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector(a,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 7824 "parser.tab.c"
    break;

  case 550: /* BasicForStatement: ForSym LRB SEMICOLON Expression SEMICOLON RRB Statement  */
#line 1523 "parser.y"
                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-3].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-3].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7830 "parser.tab.c"
    break;

  case 551: /* BasicForStatement: ForSym LRB SEMICOLON Expression SEMICOLON ForUpdate RRB Statement  */
#line 1524 "parser.y"
                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-4].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 7836 "parser.tab.c"
    break;

  case 552: /* BasicForStatement: ForSym LRB ForInit SEMICOLON SEMICOLON RRB Statement  */
#line 1525 "parser.y"
                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7842 "parser.tab.c"
    break;

  case 553: /* BasicForStatement: ForSym LRB ForInit SEMICOLON SEMICOLON ForUpdate RRB Statement  */
#line 1526 "parser.y"
                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 7848 "parser.tab.c"
    break;

  case 554: /* BasicForStatement: ForSym LRB ForInit SEMICOLON Expression SEMICOLON RRB Statement  */
#line 1527 "parser.y"
                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-3].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,a,(yyvsp[-3].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7854 "parser.tab.c"
    break;

  case 555: /* BasicForStatement: ForSym LRB ForInit SEMICOLON Expression SEMICOLON ForUpdate RRB Statement  */
#line 1528 "parser.y"
                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector((yyvsp[-6].typeinfo)->tac,a,(yyvsp[-4].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 7860 "parser.tab.c"
    break;

  case 556: /* BasicForStatementNoShortIf: ForSym LRB SEMICOLON SEMICOLON RRB StatementNoShortIf  */
#line 1530 "parser.y"
                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector(a,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7866 "parser.tab.c"
    break;

  case 557: /* BasicForStatementNoShortIf: ForSym LRB SEMICOLON SEMICOLON ForUpdate RRB StatementNoShortIf  */
#line 1531 "parser.y"
                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector(a,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 7872 "parser.tab.c"
    break;

  case 558: /* BasicForStatementNoShortIf: ForSym LRB SEMICOLON Expression SEMICOLON RRB StatementNoShortIf  */
#line 1532 "parser.y"
                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-3].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-3].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7878 "parser.tab.c"
    break;

  case 559: /* BasicForStatementNoShortIf: ForSym LRB SEMICOLON Expression SEMICOLON ForUpdate RRB StatementNoShortIf  */
#line 1533 "parser.y"
                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-4].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 7884 "parser.tab.c"
    break;

  case 560: /* BasicForStatementNoShortIf: ForSym LRB ForInit SEMICOLON SEMICOLON RRB StatementNoShortIf  */
#line 1534 "parser.y"
                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7890 "parser.tab.c"
    break;

  case 561: /* BasicForStatementNoShortIf: ForSym LRB ForInit SEMICOLON SEMICOLON ForUpdate RRB StatementNoShortIf  */
#line 1535 "parser.y"
                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 7896 "parser.tab.c"
    break;

  case 562: /* BasicForStatementNoShortIf: ForSym LRB ForInit SEMICOLON Expression SEMICOLON RRB StatementNoShortIf  */
#line 1536 "parser.y"
                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-3].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,a,(yyvsp[-3].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7902 "parser.tab.c"
    break;

  case 563: /* BasicForStatementNoShortIf: ForSym LRB ForInit SEMICOLON Expression SEMICOLON ForUpdate RRB StatementNoShortIf  */
#line 1537 "parser.y"
                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector((yyvsp[-6].typeinfo)->tac,a,(yyvsp[-4].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 7908 "parser.tab.c"
    break;

  case 564: /* ForInit: StatementExpressionList  */
#line 1539 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7914 "parser.tab.c"
    break;

  case 565: /* ForInit: LocalVariableDeclaration  */
#line 1540 "parser.y"
                                                                        {vector<string> a = ((yyvsp[0].typeinfo))->variables; for(auto s : a)insertidentifier(s,((yyvsp[0].typeinfo))->type,"",line);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7920 "parser.tab.c"
    break;

  case 566: /* ForUpdate: StatementExpressionList  */
#line 1542 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7926 "parser.tab.c"
    break;

  case 567: /* StatementExpressionList: StatementExpression  */
#line 1544 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7932 "parser.tab.c"
    break;

  case 568: /* StatementExpressionList: StatementExpression OMCommaStatementExpression  */
#line 1545 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7938 "parser.tab.c"
    break;

  case 569: /* EnhancedForStatementSym: ForSym LRB LocalVariableDeclaration  */
#line 1547 "parser.y"
                                                             {vector<string> a = ((yyvsp[0].typeinfo))->variables; for(auto s : a)insertidentifier(s,((yyvsp[0].typeinfo))->type,"",line);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7944 "parser.tab.c"
    break;

  case 570: /* EnhancedForStatement: EnhancedForStatementSym COLON Expression RRB Statement  */
#line 1549 "parser.y"
                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-2].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-4].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7950 "parser.tab.c"
    break;

  case 571: /* EnhancedForStatementNoShortIf: EnhancedForStatementSym COLON Expression RRB StatementNoShortIf  */
#line 1551 "parser.y"
                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-2].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-4].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7956 "parser.tab.c"
    break;

  case 572: /* BreakStatement: BREAK SEMICOLON  */
#line 1553 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;string p=gotoo(labelvariable+1); (yyval.typeinfo)->tac={p};}
#line 7962 "parser.tab.c"
    break;

  case 573: /* BreakStatement: BREAK Identifier SEMICOLON  */
#line 1554 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;string p=gotoo(labelvariable+1); (yyval.typeinfo)->tac={p};}
#line 7968 "parser.tab.c"
    break;

  case 574: /* YieldStatement: YIELD Expression SEMICOLON  */
#line 1557 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7974 "parser.tab.c"
    break;

  case 575: /* ContinueStatement: CONTINUE SEMICOLON  */
#line 1559 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;string p=gotoo(labelvariable); (yyval.typeinfo)->tac={p};}
#line 7980 "parser.tab.c"
    break;

  case 576: /* ContinueStatement: CONTINUE Identifier SEMICOLON  */
#line 1560 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;string p=gotoo(labelvariable); (yyval.typeinfo)->tac={p};}
#line 7986 "parser.tab.c"
    break;

  case 577: /* ReturnStatement: RETURN SEMICOLON  */
#line 1563 "parser.y"
                                                        {(yyval.typeinfo)=new Typeinfo;string p=gotomethodretlabel(currmethod.top()); (yyval.typeinfo)->tac={p};}
#line 7992 "parser.tab.c"
    break;

  case 578: /* ReturnStatement: RETURN Expression SEMICOLON  */
#line 1564 "parser.y"
                                             {(yyval.typeinfo)=new Typeinfo;string p=gotomethodretlabel(currmethod.top());string s = "%rax = " + (yyvsp[-1].typeinfo)->tempname; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,s,p);}
#line 7998 "parser.tab.c"
    break;

  case 579: /* ThrowStatement: THROW Expression SEMICOLON  */
#line 1566 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 8004 "parser.tab.c"
    break;

  case 580: /* $@59: %empty  */
#line 1568 "parser.y"
                                                         {symtable*a=createscope("synchronized"); changescope(a);}
#line 8010 "parser.tab.c"
    break;

  case 581: /* SynchronizedStatement: SYNCHRONIZED LRB Expression RRB $@59 Block  */
#line 1568 "parser.y"
                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8016 "parser.tab.c"
    break;

  case 582: /* TrySym: TRY  */
#line 1570 "parser.y"
            {symtable*a=createscope("try"); changescope(a);}
#line 8022 "parser.tab.c"
    break;

  case 583: /* TryBlockSym: Block  */
#line 1572 "parser.y"
                        {goparent();(yyval.typeinfo)=createstruct(); (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8028 "parser.tab.c"
    break;

  case 584: /* TryStatement: TrySym TryBlockSym Catches  */
#line 1574 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8034 "parser.tab.c"
    break;

  case 585: /* TryStatement: TrySym TryBlockSym Finally  */
#line 1575 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8040 "parser.tab.c"
    break;

  case 586: /* TryStatement: TrySym TryBlockSym Catches Finally  */
#line 1576 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8046 "parser.tab.c"
    break;

  case 587: /* TryStatement: TryWithResourcesStatement  */
#line 1577 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8052 "parser.tab.c"
    break;

  case 588: /* Catches: CatchClause  */
#line 1579 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8058 "parser.tab.c"
    break;

  case 589: /* Catches: CatchClause OMCatchClause  */
#line 1580 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8064 "parser.tab.c"
    break;

  case 590: /* $@60: %empty  */
#line 1582 "parser.y"
                       {symtable*a=createscope("catch"); changescope(a);}
#line 8070 "parser.tab.c"
    break;

  case 591: /* CatchClause: CATCH $@60 LRB CatchFormalParameter RRB Block  */
#line 1582 "parser.y"
                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8076 "parser.tab.c"
    break;

  case 592: /* CatchFormalParameter: CatchType VariableDeclaratorId  */
#line 1584 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8082 "parser.tab.c"
    break;

  case 593: /* CatchFormalParameter: OMClassModifier CatchType VariableDeclaratorId  */
#line 1585 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8088 "parser.tab.c"
    break;

  case 594: /* CatchType: Identifier  */
#line 1587 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8094 "parser.tab.c"
    break;

  case 595: /* CatchType: Identifier OMOrClassType  */
#line 1588 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8100 "parser.tab.c"
    break;

  case 596: /* $@61: %empty  */
#line 1591 "parser.y"
                         {symtable*a=createscope("finally"); changescope(a);}
#line 8106 "parser.tab.c"
    break;

  case 597: /* Finally: FINALLY $@61 Block  */
#line 1591 "parser.y"
                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8112 "parser.tab.c"
    break;

  case 598: /* TryWithResourcesStatement: TrySym ResourceSpecification TryBlockSym  */
#line 1593 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8118 "parser.tab.c"
    break;

  case 599: /* TryWithResourcesStatement: TrySym ResourceSpecification TryBlockSym Finally  */
#line 1594 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8124 "parser.tab.c"
    break;

  case 600: /* TryWithResourcesStatement: TrySym ResourceSpecification TryBlockSym Catches  */
#line 1595 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8130 "parser.tab.c"
    break;

  case 601: /* TryWithResourcesStatement: TrySym ResourceSpecification TryBlockSym Catches Finally  */
#line 1596 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8136 "parser.tab.c"
    break;

  case 602: /* ResourceSpecification: LRB ResourceList RRB  */
#line 1598 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 8142 "parser.tab.c"
    break;

  case 603: /* ResourceList: Resource  */
#line 1600 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8148 "parser.tab.c"
    break;

  case 604: /* ResourceList: OMSemicolonResource  */
#line 1601 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8154 "parser.tab.c"
    break;

  case 605: /* Resource: LocalVariableDeclaration  */
#line 1603 "parser.y"
                                                                                                    {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8160 "parser.tab.c"
    break;

  case 606: /* Resource: VariableAccess  */
#line 1604 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8166 "parser.tab.c"
    break;

  case 607: /* Primary: PrimaryNoNewArray  */
#line 1606 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;vector<int>q;(yyval.typeinfo)->arrdim=q;(yyval.typeinfo)->arrtype="";(yyval.typeinfo)->initvartype=(yyvsp[0].typeinfo)->initvartype;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8172 "parser.tab.c"
    break;

  case 608: /* Primary: ArrayCreationExpression  */
#line 1607 "parser.y"
                                                                                                                                {(yyval.typeinfo)=createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->initvartype="";(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8178 "parser.tab.c"
    break;

  case 609: /* PrimaryNoNewArray: Literal  */
#line 1609 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;(yyval.typeinfo)->initvartype=(yyvsp[0].typeinfo)->type;((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8184 "parser.tab.c"
    break;

  case 610: /* PrimaryNoNewArray: ClassLiteral  */
#line 1610 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8190 "parser.tab.c"
    break;

  case 611: /* PrimaryNoNewArray: THIS  */
#line 1611 "parser.y"
                                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();(yyval.typeinfo)->tempname="this";}
#line 8196 "parser.tab.c"
    break;

  case 612: /* PrimaryNoNewArray: Identifier DOT THIS  */
#line 1612 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class";string x=(yyvsp[-2].str); (yyval.typeinfo)->tac=emptyvector();(yyval.typeinfo)->tempname=x;}
#line 8202 "parser.tab.c"
    break;

  case 613: /* PrimaryNoNewArray: ExpressionName DOT THIS  */
#line 1613 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-2].typeinfo);((yyval.typeinfo))->type = "class";}
#line 8208 "parser.tab.c"
    break;

  case 614: /* PrimaryNoNewArray: LRB Expression RRB  */
#line 1614 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-1].typeinfo);((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;}
#line 8214 "parser.tab.c"
    break;

  case 615: /* PrimaryNoNewArray: ClassInstanceCreationExpression  */
#line 1615 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8220 "parser.tab.c"
    break;

  case 616: /* PrimaryNoNewArray: FieldAccess  */
#line 1616 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = "look";}
#line 8226 "parser.tab.c"
    break;

  case 617: /* PrimaryNoNewArray: ArrayAccess  */
#line 1617 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8232 "parser.tab.c"
    break;

  case 618: /* PrimaryNoNewArray: MethodInvocation  */
#line 1618 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8238 "parser.tab.c"
    break;

  case 619: /* PrimaryNoNewArray: MethodReference  */
#line 1619 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = "look";}
#line 8244 "parser.tab.c"
    break;

  case 620: /* ClassLiteral: Identifier DOT CLASS  */
#line 1621 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();}
#line 8250 "parser.tab.c"
    break;

  case 621: /* ClassLiteral: ExpressionName DOT CLASS  */
#line 1622 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();}
#line 8256 "parser.tab.c"
    break;

  case 622: /* ClassLiteral: Identifier OMPSB DOT CLASS  */
#line 1623 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();}
#line 8262 "parser.tab.c"
    break;

  case 623: /* ClassLiteral: ExpressionName OMPSB DOT CLASS  */
#line 1624 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();}
#line 8268 "parser.tab.c"
    break;

  case 624: /* ClassLiteral: UnannPrimitiveType DOT CLASS  */
#line 1625 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();}
#line 8274 "parser.tab.c"
    break;

  case 625: /* ClassLiteral: VOID DOT CLASS  */
#line 1626 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();}
#line 8280 "parser.tab.c"
    break;

  case 626: /* ClassInstanceCreationExpression: UnqualifiedClassInstanceCreationExpression  */
#line 1628 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8286 "parser.tab.c"
    break;

  case 627: /* ClassInstanceCreationExpression: Identifier DOT UnqualifiedClassInstanceCreationExpression  */
#line 1629 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8292 "parser.tab.c"
    break;

  case 628: /* ClassInstanceCreationExpression: ExpressionName DOT UnqualifiedClassInstanceCreationExpression  */
#line 1630 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8298 "parser.tab.c"
    break;

  case 629: /* ClassInstanceCreationExpression: Primary DOT UnqualifiedClassInstanceCreationExpression  */
#line 1631 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8304 "parser.tab.c"
    break;

  case 630: /* UnqualifiedClassInstanceCreationExpression: NEW ClassOrInterfaceTypeToInstantiate LRB RRB  */
#line 1637 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 8310 "parser.tab.c"
    break;

  case 631: /* UnqualifiedClassInstanceCreationExpression: NEW ClassOrInterfaceTypeToInstantiate LRB RRB ClassBody  */
#line 1638 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-3].typeinfo))->type;(yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8316 "parser.tab.c"
    break;

  case 632: /* UnqualifiedClassInstanceCreationExpression: NEW ClassOrInterfaceTypeToInstantiate LRB ArgumentList RRB  */
#line 1639 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-3].typeinfo))->type;(yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 8322 "parser.tab.c"
    break;

  case 633: /* UnqualifiedClassInstanceCreationExpression: NEW ClassOrInterfaceTypeToInstantiate LRB ArgumentList RRB ClassBody  */
#line 1640 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-4].typeinfo))->type;(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8328 "parser.tab.c"
    break;

  case 634: /* ClassOrInterfaceTypeToInstantiate: Identifier  */
#line 1642 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();string p = (yyvsp[0].str);if(lookup(p)){((yyval.typeinfo))->type =  lookup(p)->funcrettype ;}(yyval.typeinfo)->tac=emptyvector();}
#line 8334 "parser.tab.c"
    break;

  case 635: /* ClassOrInterfaceTypeToInstantiate: Identifier OMDotIdentifier  */
#line 1643 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=emptyvector();string p = (yyvsp[-1].str);if(lookup(p + ((yyvsp[0].typeinfo))->name)){((yyval.typeinfo))->type =  lookup(p + ((yyvsp[0].typeinfo))->name)->funcrettype ;}}
#line 8340 "parser.tab.c"
    break;

  case 636: /* FieldAccess: Primary DOT Identifier  */
#line 1645 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8346 "parser.tab.c"
    break;

  case 637: /* FieldAccess: SUPER DOT Identifier  */
#line 1646 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=emptyvector();}
#line 8352 "parser.tab.c"
    break;

  case 638: /* FieldAccess: Identifier DOT SUPER DOT Identifier  */
#line 1647 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=emptyvector();}
#line 8358 "parser.tab.c"
    break;

  case 639: /* FieldAccess: ExpressionName DOT SUPER DOT Identifier  */
#line 1648 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 8364 "parser.tab.c"
    break;

  case 640: /* ArrayAccess: Identifier LSB Expression RSB  */
#line 1650 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo;string yy=(yyvsp[-3].str);symentry* entry=lookup(yy); vector<int>v=entry->arrdims;string x=entry->primtype; vector<int>f; for(int 	i=1;i<v.size();i++)f.push_back(v[i]);(yyval.typeinfo)->dimsize=f;(yyval.typeinfo)->arrname="a"; (yyval.typeinfo)->arrtype=x;string y=newtemp();(yyval.typeinfo)->tempname=y;y=y+" = "+((yyvsp[-1].typeinfo))->tempname+" * "+to_string(tellsize(f,x)); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,y);}
#line 8370 "parser.tab.c"
    break;

  case 641: /* ArrayAccess: ExpressionName LSB Expression RSB  */
#line 1651 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 8376 "parser.tab.c"
    break;

  case 642: /* ArrayAccess: PrimaryNoNewArray LSB Expression RSB  */
#line 1652 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; vector<int>v=((yyvsp[-3].typeinfo))->dimsize;string x=((yyvsp[-3].typeinfo))->arrtype; vector<int>f; for(int i=1;i<v.size();i++)f.push_back(v[i]);(yyval.typeinfo)->dimsize=f; (yyval.typeinfo)->arrtype=x;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=newtemp();y=y+" = "+((yyvsp[-1].typeinfo))->tempname+" + "+z;z=z+" = "+((yyvsp[-1].typeinfo))->tempname+" * "+to_string(tellsize(f,x)); (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,z,y);(yyval.typeinfo)->arrname=(yyvsp[-3].typeinfo)->arrname;}
#line 8382 "parser.tab.c"
    break;

  case 643: /* MethodInvocation: MethodName LRB ArgumentList RRB  */
#line 1654 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();if(lookup(((yyvsp[-3].typeinfo))->name)){((yyval.typeinfo))->type =  lookup(((yyvsp[-3].typeinfo))->name)->funcrettype ;} vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters(); string s = ((yyvsp[-3].typeinfo))->tempname;((yyval.typeinfo))->tempname = "%rax"; string s1 = gotomethod(s);string s2 = newmethodretlabel(s);vector<string> pushpar = pusharg(((yyvsp[-1].typeinfo))->params);(yyval.typeinfo)->tac=concvector(pv1,(yyvsp[-1].typeinfo)->tac,pushpar,s1,(yyvsp[-3].typeinfo)->tac,s2,pv2);}
#line 8388 "parser.tab.c"
    break;

  case 644: /* MethodInvocation: MethodName LRB RRB  */
#line 1655 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();if(lookup(((yyvsp[-2].typeinfo))->name)){((yyval.typeinfo))->type =  lookup(((yyvsp[-2].typeinfo))->name)->funcrettype ;}vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters();string s = ((yyvsp[-2].typeinfo))->tempname;((yyval.typeinfo))->tempname = "%rax";string s1 = gotomethod(s);string s2 = newmethodretlabel(s); (yyval.typeinfo)->tac=concvector(pv1,s1,(yyvsp[-2].typeinfo)->tac,s2,pv2);}
#line 8394 "parser.tab.c"
    break;

  case 645: /* MethodInvocation: Identifier DOT Identifier LRB RRB  */
#line 1656 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8400 "parser.tab.c"
    break;

  case 646: /* MethodInvocation: Identifier DOT Identifier LRB ArgumentList RRB  */
#line 1657 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 8406 "parser.tab.c"
    break;

  case 647: /* MethodInvocation: ExpressionName DOT Identifier LRB RRB  */
#line 1658 "parser.y"
                                                                                                            {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 8412 "parser.tab.c"
    break;

  case 648: /* MethodInvocation: ExpressionName DOT Identifier LRB ArgumentList RRB  */
#line 1659 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 8418 "parser.tab.c"
    break;

  case 649: /* MethodInvocation: Primary DOT Identifier LRB RRB  */
#line 1660 "parser.y"
                                                                                                                    {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 8424 "parser.tab.c"
    break;

  case 650: /* MethodInvocation: Primary DOT Identifier LRB ArgumentList RRB  */
#line 1661 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-5].typeinfo)->tac;}
#line 8430 "parser.tab.c"
    break;

  case 651: /* MethodInvocation: SUPER DOT Identifier LRB RRB  */
#line 1662 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8436 "parser.tab.c"
    break;

  case 652: /* MethodInvocation: SUPER DOT Identifier LRB ArgumentList RRB  */
#line 1663 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8442 "parser.tab.c"
    break;

  case 653: /* MethodInvocation: Identifier DOT SUPER DOT Identifier LRB RRB  */
#line 1664 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8448 "parser.tab.c"
    break;

  case 654: /* MethodInvocation: Identifier DOT SUPER DOT Identifier LRB ArgumentList RRB  */
#line 1665 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 8454 "parser.tab.c"
    break;

  case 655: /* MethodInvocation: ExpressionName DOT SUPER DOT Identifier LRB RRB  */
#line 1666 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-6].typeinfo)->tac;}
#line 8460 "parser.tab.c"
    break;

  case 656: /* MethodInvocation: ExpressionName DOT SUPER DOT Identifier LRB ArgumentList RRB  */
#line 1667 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-7].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 8466 "parser.tab.c"
    break;

  case 657: /* ArgumentList: Expression  */
#line 1670 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;string s = ((yyvsp[0].typeinfo))->tempname; (yyval.typeinfo)->params.push_back(s);}
#line 8472 "parser.tab.c"
    break;

  case 658: /* ArgumentList: Expression OMCommaExpression  */
#line 1671 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);string s = ((yyvsp[-1].typeinfo))->tempname; (yyval.typeinfo)->params.push_back(s); for(auto z:((yyvsp[0].typeinfo))->params)((yyval.typeinfo))->params.push_back(z);}
#line 8478 "parser.tab.c"
    break;

  case 659: /* MethodReference: Identifier DOUBLECOLON Identifier  */
#line 1673 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8484 "parser.tab.c"
    break;

  case 661: /* MethodReference: Primary DOUBLECOLON Identifier  */
#line 1675 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8490 "parser.tab.c"
    break;

  case 662: /* MethodReference: UnannArrayType DOUBLECOLON Identifier  */
#line 1676 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8496 "parser.tab.c"
    break;

  case 663: /* MethodReference: SUPER DOUBLECOLON Identifier  */
#line 1677 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8502 "parser.tab.c"
    break;

  case 664: /* MethodReference: Identifier DOT SUPER DOUBLECOLON Identifier  */
#line 1678 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8508 "parser.tab.c"
    break;

  case 666: /* MethodReference: UnannArrayType DOUBLECOLON NEW  */
#line 1680 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8514 "parser.tab.c"
    break;

  case 667: /* ArrayCreationExpression: NEW PrimitiveType OMDimExpr  */
#line 1682 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->type=(yyvsp[-1].typeinfo)->type;(yyval.typeinfo)->arrtype=(yyvsp[-1].typeinfo)->type;(yyval.typeinfo)->arrdim=(yyvsp[0].typeinfo)->arrdim; (yyval.typeinfo)->tac=emptyvector();}
#line 8520 "parser.tab.c"
    break;

  case 668: /* ArrayCreationExpression: NEW PrimitiveType OMDimExpr OMPSB  */
#line 1683 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8526 "parser.tab.c"
    break;

  case 669: /* ArrayCreationExpression: NEW Identifier OMDimExpr  */
#line 1684 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8532 "parser.tab.c"
    break;

  case 670: /* ArrayCreationExpression: NEW Identifier OMDimExpr OMPSB  */
#line 1685 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8538 "parser.tab.c"
    break;

  case 671: /* ArrayCreationExpression: NEW PrimitiveType OMPSB ArrayInitializer  */
#line 1686 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8544 "parser.tab.c"
    break;

  case 672: /* ArrayCreationExpression: NEW Identifier OMPSB ArrayInitializer  */
#line 1687 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8550 "parser.tab.c"
    break;

  case 673: /* DimExpr: LSB Expression RSB  */
#line 1690 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();if((yyvsp[-1].typeinfo)->type!="int")cout<<"error coz of nonint array para";(yyval.typeinfo)=(yyvsp[-1].typeinfo);(yyval.typeinfo)->exprvalue=(yyvsp[-1].typeinfo)->exprvalue;(yyval.typeinfo)->type=(yyvsp[-1].typeinfo)->type;}
#line 8556 "parser.tab.c"
    break;

  case 674: /* Expression: AssignmentExpression  */
#line 1692 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 8562 "parser.tab.c"
    break;

  case 675: /* AssignmentExpression: ConditionalExpression  */
#line 1694 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 8568 "parser.tab.c"
    break;

  case 676: /* AssignmentExpression: Assignment  */
#line 1695 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8574 "parser.tab.c"
    break;

  case 677: /* Assignment: LeftHandSide AssignmentOperator Expression  */
#line 1697 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string p=((yyvsp[-2].typeinfo))->tempname+" = "+((yyvsp[0].typeinfo))->tempname;(yyval.typeinfo)->tempname=((yyvsp[-2].typeinfo))->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,p);}
#line 8580 "parser.tab.c"
    break;

  case 678: /* LeftHandSide: ExpressionName  */
#line 1699 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 8586 "parser.tab.c"
    break;

  case 679: /* LeftHandSide: Identifier  */
#line 1700 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();string p = (yyvsp[0].str);if(lookup(p)){((yyval.typeinfo))->type = lookup(p)->type;}string x=(yyvsp[0].str); string q=newtemp();(yyval.typeinfo)->tempname=q;q=q+" = "+x; (yyval.typeinfo)->tac={q};}
#line 8592 "parser.tab.c"
    break;

  case 680: /* LeftHandSide: FieldAccess  */
#line 1701 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 8598 "parser.tab.c"
    break;

  case 681: /* LeftHandSide: ArrayAccess  */
#line 1702 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->type=(yyvsp[0].typeinfo)->type;string y=((yyvsp[0].typeinfo))->arrname+"["+((yyvsp[0].typeinfo))->tempname+"]"; (yyval.typeinfo)->tempname=y;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8604 "parser.tab.c"
    break;

  case 682: /* AssignmentOperator: ASSIGNMENTOPERATOR  */
#line 1704 "parser.y"
                                                                                                {(yyval.str)=(yyvsp[0].str);}
#line 8610 "parser.tab.c"
    break;

  case 683: /* ConditionalExpression: ConditionalOrExpression  */
#line 1706 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 8616 "parser.tab.c"
    break;

  case 684: /* ConditionalExpression: ConditionalOrExpression QM Expression COLON ConditionalExpression  */
#line 1707 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-4].typeinfo))->type;int lv=labelvariable;string a=newlabel();string ret="if zero "+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+1);(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,ret,(yyvsp[-2].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac);}
#line 8622 "parser.tab.c"
    break;

  case 685: /* ConditionalOrExpression: ConditionalAndExpression  */
#line 1709 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 8628 "parser.tab.c"
    break;

  case 686: /* ConditionalOrExpression: ConditionalOrExpression OR ConditionalAndExpression  */
#line 1710 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" || "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[-2].typeinfo)->exprvalue||(yyvsp[0].typeinfo)->exprvalue;}
#line 8634 "parser.tab.c"
    break;

  case 687: /* ConditionalAndExpression: InclusiveOrExpression  */
#line 1712 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8640 "parser.tab.c"
    break;

  case 688: /* ConditionalAndExpression: ConditionalAndExpression AND InclusiveOrExpression  */
#line 1713 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" && "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)&&((yyvsp[0].typeinfo)->exprvalue));}
#line 8646 "parser.tab.c"
    break;

  case 689: /* InclusiveOrExpression: ExclusiveOrExpression  */
#line 1715 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8652 "parser.tab.c"
    break;

  case 690: /* InclusiveOrExpression: InclusiveOrExpression BITOR ExclusiveOrExpression  */
#line 1716 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" | "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)|((yyvsp[0].typeinfo)->exprvalue));}
#line 8658 "parser.tab.c"
    break;

  case 691: /* ExclusiveOrExpression: AndExpression  */
#line 1718 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8664 "parser.tab.c"
    break;

  case 692: /* ExclusiveOrExpression: ExclusiveOrExpression BITXOR AndExpression  */
#line 1719 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" ^ "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)^((yyvsp[0].typeinfo)->exprvalue));}
#line 8670 "parser.tab.c"
    break;

  case 693: /* AndExpression: EqualityExpression  */
#line 1721 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8676 "parser.tab.c"
    break;

  case 694: /* AndExpression: AndExpression BITAND EqualityExpression  */
#line 1722 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" & "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)&((yyvsp[0].typeinfo)->exprvalue));}
#line 8682 "parser.tab.c"
    break;

  case 695: /* EqualityExpression: RelationalExpression  */
#line 1724 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8688 "parser.tab.c"
    break;

  case 696: /* EqualityExpression: EqualityExpression DOUBLEEQUAL RelationalExpression  */
#line 1725 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" == "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)==((yyvsp[0].typeinfo)->exprvalue));}
#line 8694 "parser.tab.c"
    break;

  case 697: /* EqualityExpression: EqualityExpression NE RelationalExpression  */
#line 1726 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" != "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)!=((yyvsp[0].typeinfo)->exprvalue));}
#line 8700 "parser.tab.c"
    break;

  case 698: /* RelationalExpression: ShiftExpression  */
#line 1728 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8706 "parser.tab.c"
    break;

  case 699: /* RelationalExpression: RelationalExpression LT ShiftExpression  */
#line 1729 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" < "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)<((yyvsp[0].typeinfo)->exprvalue));}
#line 8712 "parser.tab.c"
    break;

  case 700: /* RelationalExpression: RelationalExpression GT ShiftExpression  */
#line 1730 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" > "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)>((yyvsp[0].typeinfo)->exprvalue));}
#line 8718 "parser.tab.c"
    break;

  case 701: /* RelationalExpression: RelationalExpression LTE ShiftExpression  */
#line 1731 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" <= "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)<=((yyvsp[0].typeinfo)->exprvalue));}
#line 8724 "parser.tab.c"
    break;

  case 702: /* RelationalExpression: RelationalExpression GTE ShiftExpression  */
#line 1732 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" >= "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)>=((yyvsp[0].typeinfo)->exprvalue));}
#line 8730 "parser.tab.c"
    break;

  case 703: /* RelationalExpression: InstanceofExpression  */
#line 1733 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8736 "parser.tab.c"
    break;

  case 704: /* InstanceofExpression: RelationalExpression INSTANCEOF ReferenceType  */
#line 1738 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" instanceof "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[-2].typeinfo)->exprvalue;}
#line 8742 "parser.tab.c"
    break;

  case 705: /* ShiftExpression: AdditiveExpression  */
#line 1740 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 8748 "parser.tab.c"
    break;

  case 706: /* ShiftExpression: ShiftExpression LSHIFT AdditiveExpression  */
#line 1741 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" << "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)<<((yyvsp[0].typeinfo)->exprvalue));}
#line 8754 "parser.tab.c"
    break;

  case 707: /* ShiftExpression: ShiftExpression RSHIFT AdditiveExpression  */
#line 1742 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" >> "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)>>((yyvsp[0].typeinfo)->exprvalue));}
#line 8760 "parser.tab.c"
    break;

  case 708: /* ShiftExpression: ShiftExpression THREEGT AdditiveExpression  */
#line 1743 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" >>> "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)>>((yyvsp[0].typeinfo)->exprvalue));}
#line 8766 "parser.tab.c"
    break;

  case 709: /* AdditiveExpression: MultiplicativeExpression  */
#line 1745 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8772 "parser.tab.c"
    break;

  case 710: /* AdditiveExpression: AdditiveExpression PLUS MultiplicativeExpression  */
#line 1746 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" + "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)+((yyvsp[0].typeinfo)->exprvalue));}
#line 8778 "parser.tab.c"
    break;

  case 711: /* AdditiveExpression: AdditiveExpression MINUS MultiplicativeExpression  */
#line 1747 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" - "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)-((yyvsp[0].typeinfo)->exprvalue));}
#line 8784 "parser.tab.c"
    break;

  case 712: /* MultiplicativeExpression: UnaryExpression  */
#line 1749 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8790 "parser.tab.c"
    break;

  case 713: /* MultiplicativeExpression: MultiplicativeExpression MULTIPLY UnaryExpression  */
#line 1750 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" * "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)*((yyvsp[0].typeinfo)->exprvalue));}
#line 8796 "parser.tab.c"
    break;

  case 714: /* MultiplicativeExpression: MultiplicativeExpression DIVIDE UnaryExpression  */
#line 1751 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" / "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)/((yyvsp[0].typeinfo)->exprvalue));}
#line 8802 "parser.tab.c"
    break;

  case 715: /* MultiplicativeExpression: MultiplicativeExpression PERCENT UnaryExpression  */
#line 1752 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" % "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)%((yyvsp[0].typeinfo)->exprvalue));}
#line 8808 "parser.tab.c"
    break;

  case 716: /* UnaryExpression: PreIncrementExpression  */
#line 1754 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 8814 "parser.tab.c"
    break;

  case 717: /* UnaryExpression: PreDecrementExpression  */
#line 1755 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8820 "parser.tab.c"
    break;

  case 718: /* UnaryExpression: PLUS UnaryExpression  */
#line 1756 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(1+((yyvsp[0].typeinfo)->exprvalue));}
#line 8826 "parser.tab.c"
    break;

  case 719: /* UnaryExpression: MINUS UnaryExpression  */
#line 1757 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+" - "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[0].typeinfo)->exprvalue)-1);}
#line 8832 "parser.tab.c"
    break;

  case 720: /* UnaryExpression: UnaryExpressionNotPlusMinus  */
#line 1758 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8838 "parser.tab.c"
    break;

  case 721: /* PreIncrementExpression: INCREAMENT UnaryExpression  */
#line 1760 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[0].typeinfo)->tempname+" + 1 ";(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue+1;(yyval.typeinfo)->exprvalue=(((yyvsp[0].typeinfo)->exprvalue)+1);}
#line 8844 "parser.tab.c"
    break;

  case 722: /* PreDecrementExpression: DECREAMENT UnaryExpression  */
#line 1762 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[0].typeinfo)->tempname+" - 1 ";(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue+1;(yyval.typeinfo)->exprvalue=(((yyvsp[0].typeinfo)->exprvalue)-1);}
#line 8850 "parser.tab.c"
    break;

  case 723: /* UnaryExpressionNotPlusMinus: PostfixExpression  */
#line 1764 "parser.y"
                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8856 "parser.tab.c"
    break;

  case 724: /* UnaryExpressionNotPlusMinus: TILDA UnaryExpression  */
#line 1765 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+" ~ "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 8862 "parser.tab.c"
    break;

  case 725: /* UnaryExpressionNotPlusMinus: EXCLAM UnaryExpression  */
#line 1766 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+" ! "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=!((yyvsp[0].typeinfo)->exprvalue);}
#line 8868 "parser.tab.c"
    break;

  case 726: /* UnaryExpressionNotPlusMinus: CastExpression  */
#line 1767 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 8874 "parser.tab.c"
    break;

  case 727: /* UnaryExpressionNotPlusMinus: SwitchExpression  */
#line 1768 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 8880 "parser.tab.c"
    break;

  case 728: /* PostfixExpression: Primary  */
#line 1770 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8886 "parser.tab.c"
    break;

  case 729: /* PostfixExpression: Identifier  */
#line 1771 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();string p = (yyvsp[0].str);symentry*s=lookup(p); if(lookup(p)){((yyval.typeinfo))->type = s->type;(yyval.typeinfo)->order=s->order;(yyval.typeinfo)->exprvalue=s->exprvalue;}string a=(yyvsp[0].str); string b=newtemp();(yyval.typeinfo)->tempname=b;b=b+" = "+a;(yyval.typeinfo)->tac={b};(yyval.typeinfo)->tac={b};}
#line 8892 "parser.tab.c"
    break;

  case 730: /* PostfixExpression: ExpressionName  */
#line 1772 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8898 "parser.tab.c"
    break;

  case 731: /* PostfixExpression: PostIncrementExpression  */
#line 1773 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8904 "parser.tab.c"
    break;

  case 732: /* PostfixExpression: PostDecrementExpression  */
#line 1774 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->type = ((yyvsp[0].typeinfo))->type;}
#line 8910 "parser.tab.c"
    break;

  case 733: /* PostIncrementExpression: PostfixExpression INCREAMENT  */
#line 1776 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-1].typeinfo)->tempname+" + 1 ";(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[-1].typeinfo)->exprvalue+1;}
#line 8916 "parser.tab.c"
    break;

  case 734: /* PostDecrementExpression: PostfixExpression DECREAMENT  */
#line 1778 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-1].typeinfo)->tempname+" - 1 ";(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[-1].typeinfo)->exprvalue-1;}
#line 8922 "parser.tab.c"
    break;

  case 735: /* CastExpression: LRB PrimitiveType RRB UnaryExpression  */
#line 1780 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type; ((yyvsp[0].typeinfo))->type = ((yyvsp[-2].typeinfo))->type; string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 8928 "parser.tab.c"
    break;

  case 736: /* CastExpression: LRB UnannArrayType RRB UnaryExpressionNotPlusMinus  */
#line 1781 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type; ((yyvsp[0].typeinfo))->type = ((yyvsp[-2].typeinfo))->type; string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 8934 "parser.tab.c"
    break;

  case 737: /* CastExpression: LRB UnannArrayType OMAdditionalBound RRB UnaryExpressionNotPlusMinus  */
#line 1782 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-3].typeinfo))->type; ((yyvsp[0].typeinfo))->type = ((yyvsp[-3].typeinfo))->type; string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 8940 "parser.tab.c"
    break;

  case 738: /* $@62: %empty  */
#line 1784 "parser.y"
                                                   {symtable *a = createscope("switch"); changescope(a);}
#line 8946 "parser.tab.c"
    break;

  case 739: /* SwitchExpression: SWITCH LRB Expression RRB $@62 SwitchBlock  */
#line 1784 "parser.y"
                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);((yyval.typeinfo))->type = "switch";(yyval.typeinfo)->exprvalue=1;}
#line 8952 "parser.tab.c"
    break;

  case 740: /* VariableAccess: ExpressionName  */
#line 1786 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 8958 "parser.tab.c"
    break;

  case 741: /* VariableAccess: Identifier  */
#line 1787 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; string a=(yyvsp[0].str); string b=newtemp();(yyval.typeinfo)->tempname=b;b=b+" = "+a;(yyval.typeinfo)->tac={b};(yyval.typeinfo)->tac={b};}
#line 8964 "parser.tab.c"
    break;

  case 742: /* VariableAccess: FieldAccess  */
#line 1788 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 8970 "parser.tab.c"
    break;


#line 8974 "parser.tab.c"

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

#line 1791 "parser.y"

// bool visited[100000]={false};

int main(int argc,char*argv[]){
	


// if(argc <= 1){
// 		cerr<<"Error: no input files\n";
// 		return -1;
// 	}
//     bool inputtaken=false,verbose=false;
//     int inputindex;
// 	for(int i=1;i<argc;i++)
//     {
//          if(!strcmp(argv[i],"--input"))
//          {
//             if(!inputtaken)
//             {
//                 inputindex=i+1;
//                 inputtaken=true;
//                 i++;
//             }
//             else{
//                 cerr<<" You can't give two input files\n";
//                 return 0;
//             }
//          }
//          else if(!strcmp(argv[i],"--verbose"))
//          {
//             verbose=true;
//          }
//          else if((!strcmp(argv[i],"--h"))||(!strcmp(argv[i],"--help")))
//          {
//             cout<<"Use following commands\n";
//             cout<<"to give inputfile name : --input <inputfilename>\n";
//             cout<<"to give verbose : --verbose \n";
//             cout<<"to seek help : --h or --help\n";
//             cout<<"Input file is .java and output file is .csv\n";

//          }
//          else{
//             cerr<<"Invalid Arguments\n";
//             cout<<"Use following commands\n";
//             cout<<"to give inputfile name : --input <inputfilename>\n";
//             cout<<"to give verbose : --verbose \n";
//             cout<<"to seek help : --h or --help\n";
//             cout<<"Input file is .java and output file is .csv\n";
//          }
//     }
//     if(!inputtaken){
//         cerr<<"You must enter input filename\n";
//         cerr<<"Type --help\n";
//     }
//     yyin = fopen(argv[inputindex], "r");
		
// 	if(yyin == NULL){
// 		cerr<<"Error: cannot open file "<<argv[inputindex]<<"\n";
// 	}
//     if(verbose)
//     {
//         cout<<"Parse started\n";
//         cout<<"Parsing file.....\n";
//     }

if(argc <= 1){
		cerr<<"Error: no input files\n";
		return -1;
	}
    bool inputtaken=false,outputtaken=false,verbose=false;
    int inputindex,outputindex;
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
         else if(!strcmp(argv[i],"--output")){
            if(!outputtaken)
            {
                outputindex=i+1;
                outputtaken=true;
                i++;
            }
            else{
                cerr<<" You can't give two output files\n";
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
            cout<<"to give outfile name : --output <outputfilename>\n";
            cout<<"to give verbose : --verbose \n";
            cout<<"to seek help : --h or --help\n";
            cout<<"Input file is .java and output file is .dot\n";

         }
         else{
            cerr<<"Invalid Arguments\n";
            cout<<"Use following commands\n";
            cout<<"to give inputfile name : --input <inputfilename>\n";
            cout<<"to give outfile name : --output <outputfilename>\n";
            cout<<"to give verbose : --verbose \n";
            cout<<"to seek help : --h or --help\n";
            cout<<"Input file is .java and output file is .dot\n";
         }
    }
    if(!inputtaken){
        cerr<<"You must enter input filename\n";
        cerr<<"Type --help\n";
    }
    if(outputtaken){
        dotfile = fopen(argv[outputindex], "w");
    }
    else{
        dotfile = fopen("output.3ac", "w");
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
	csvFile << "Name, Type, primtive type, ArrayDimensions,Function Input Type, Function Output Type, Scope" << "\n";
	// dfs(curr);
	while(!q.empty()){
		symtable* c=q.front();
		if(c)
		// prints(c);
		// for(auto z:c->m){
		// 	csvFile<<z.first<<","<<z.second->type<<","<<z.second->linenumber<<","<<z.second->argcon<<","<<z.second->funcrettype<<","<<z.second->size<<","<<z.second->scope<<"\n";
		// }
        for(auto z:c->m){
            string p="";
            vector<int>q=z.second->arrdims;
			if(q.size()>0){
           for(int i=0;i<q.size()-1;i++)
           p=p+to_string(q[i])+" x ";
           p=p+to_string(q[q.size()-1]);
			}
			// csvFile<<z.first<<","<<z.second->type<<","<<z.second->primtype<<","<<z.second<<z.second->linenumber<<","<<z.second->argcon<<","<<z.second->funcrettype<<"arraysize:";
			// for(auto y:z.second->arrdims)
			// csvFile<<y<<"x";
			// csvFile<<"\n";
			csvFile<<z.first<<","<<z.second->type<<","<<z.second->primtype<<","<<p<<","<<z.second->argcon<<","<<z.second->funcrettype<<","<<z.second->scope<<"\n";
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
