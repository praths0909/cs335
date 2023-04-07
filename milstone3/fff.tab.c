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
#line 1 "fff.y"

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
	return "Label"+to_string(labelvariable);
}
string gotolabel(int labelvariable){
	return " goto Label"+to_string(labelvariable);
}
string gotoo(int p){
    return " go to label "+to_string(p);
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
	return pr*4;
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
    string a=" go to label "+q;
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

#line 819 "fff.tab.c"

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

#include "fff.tab.h"
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
  YYSYMBOL_196_1 = 196,                    /* $@1  */
  YYSYMBOL_197_2 = 197,                    /* $@2  */
  YYSYMBOL_198_3 = 198,                    /* $@3  */
  YYSYMBOL_199_4 = 199,                    /* $@4  */
  YYSYMBOL_200_5 = 200,                    /* $@5  */
  YYSYMBOL_201_6 = 201,                    /* $@6  */
  YYSYMBOL_202_7 = 202,                    /* $@7  */
  YYSYMBOL_203_8 = 203,                    /* $@8  */
  YYSYMBOL_ModuleDirective = 204,          /* ModuleDirective  */
  YYSYMBOL_ClassDeclaration = 205,         /* ClassDeclaration  */
  YYSYMBOL_NormalClassDeclaration = 206,   /* NormalClassDeclaration  */
  YYSYMBOL_207_9 = 207,                    /* $@9  */
  YYSYMBOL_208_10 = 208,                   /* $@10  */
  YYSYMBOL_209_11 = 209,                   /* $@11  */
  YYSYMBOL_210_12 = 210,                   /* $@12  */
  YYSYMBOL_211_13 = 211,                   /* $@13  */
  YYSYMBOL_212_14 = 212,                   /* $@14  */
  YYSYMBOL_213_15 = 213,                   /* $@15  */
  YYSYMBOL_214_16 = 214,                   /* $@16  */
  YYSYMBOL_215_17 = 215,                   /* $@17  */
  YYSYMBOL_216_18 = 216,                   /* $@18  */
  YYSYMBOL_217_19 = 217,                   /* $@19  */
  YYSYMBOL_218_20 = 218,                   /* $@20  */
  YYSYMBOL_219_21 = 219,                   /* $@21  */
  YYSYMBOL_220_22 = 220,                   /* $@22  */
  YYSYMBOL_221_23 = 221,                   /* $@23  */
  YYSYMBOL_222_24 = 222,                   /* $@24  */
  YYSYMBOL_223_25 = 223,                   /* $@25  */
  YYSYMBOL_224_26 = 224,                   /* $@26  */
  YYSYMBOL_225_27 = 225,                   /* $@27  */
  YYSYMBOL_226_28 = 226,                   /* $@28  */
  YYSYMBOL_227_29 = 227,                   /* $@29  */
  YYSYMBOL_228_30 = 228,                   /* $@30  */
  YYSYMBOL_229_31 = 229,                   /* $@31  */
  YYSYMBOL_230_32 = 230,                   /* $@32  */
  YYSYMBOL_231_33 = 231,                   /* $@33  */
  YYSYMBOL_232_34 = 232,                   /* $@34  */
  YYSYMBOL_233_35 = 233,                   /* $@35  */
  YYSYMBOL_234_36 = 234,                   /* $@36  */
  YYSYMBOL_235_37 = 235,                   /* $@37  */
  YYSYMBOL_236_38 = 236,                   /* $@38  */
  YYSYMBOL_237_39 = 237,                   /* $@39  */
  YYSYMBOL_238_40 = 238,                   /* $@40  */
  YYSYMBOL_TypeParameters = 239,           /* TypeParameters  */
  YYSYMBOL_TypeParameterList = 240,        /* TypeParameterList  */
  YYSYMBOL_ClassExtends = 241,             /* ClassExtends  */
  YYSYMBOL_ClassImplements = 242,          /* ClassImplements  */
  YYSYMBOL_InterfaceTypeList = 243,        /* InterfaceTypeList  */
  YYSYMBOL_ClassPermits = 244,             /* ClassPermits  */
  YYSYMBOL_ClassBody = 245,                /* ClassBody  */
  YYSYMBOL_ClassBodyDeclaration = 246,     /* ClassBodyDeclaration  */
  YYSYMBOL_ClassMemberDeclaration = 247,   /* ClassMemberDeclaration  */
  YYSYMBOL_FieldDeclaration = 248,         /* FieldDeclaration  */
  YYSYMBOL_VariableDeclaratorList = 249,   /* VariableDeclaratorList  */
  YYSYMBOL_VariableDeclarator = 250,       /* VariableDeclarator  */
  YYSYMBOL_VariableDeclaratorId = 251,     /* VariableDeclaratorId  */
  YYSYMBOL_VariableInitializer = 252,      /* VariableInitializer  */
  YYSYMBOL_UnannType = 253,                /* UnannType  */
  YYSYMBOL_UnannPrimitiveType = 254,       /* UnannPrimitiveType  */
  YYSYMBOL_UnannArrayType = 255,           /* UnannArrayType  */
  YYSYMBOL_MethodDeclaration = 256,        /* MethodDeclaration  */
  YYSYMBOL_MethodHeader = 257,             /* MethodHeader  */
  YYSYMBOL_Result = 258,                   /* Result  */
  YYSYMBOL_MethodDeclarator = 259,         /* MethodDeclarator  */
  YYSYMBOL_ReceiverParameter = 260,        /* ReceiverParameter  */
  YYSYMBOL_FormalParameterList = 261,      /* FormalParameterList  */
  YYSYMBOL_FormalParameter = 262,          /* FormalParameter  */
  YYSYMBOL_VariableArityParameter = 263,   /* VariableArityParameter  */
  YYSYMBOL_Throws = 264,                   /* Throws  */
  YYSYMBOL_ExceptionTypeList = 265,        /* ExceptionTypeList  */
  YYSYMBOL_ExceptionType = 266,            /* ExceptionType  */
  YYSYMBOL_MethodBody = 267,               /* MethodBody  */
  YYSYMBOL_InstanceInitializer = 268,      /* InstanceInitializer  */
  YYSYMBOL_StaticInitializer = 269,        /* StaticInitializer  */
  YYSYMBOL_ConstructorDeclaration = 270,   /* ConstructorDeclaration  */
  YYSYMBOL_ConstructorDeclaratorLRBSym = 271, /* ConstructorDeclaratorLRBSym  */
  YYSYMBOL_ConstructorDeclarator = 272,    /* ConstructorDeclarator  */
  YYSYMBOL_ConstructorBody = 273,          /* ConstructorBody  */
  YYSYMBOL_ExplicitConstructorInvocation = 274, /* ExplicitConstructorInvocation  */
  YYSYMBOL_EnumDeclaration = 275,          /* EnumDeclaration  */
  YYSYMBOL_EnumBody = 276,                 /* EnumBody  */
  YYSYMBOL_EnumConstantList = 277,         /* EnumConstantList  */
  YYSYMBOL_PRB = 278,                      /* PRB  */
  YYSYMBOL_PRBArgumentList = 279,          /* PRBArgumentList  */
  YYSYMBOL_EnumConstant = 280,             /* EnumConstant  */
  YYSYMBOL_EnumBodyDeclarations = 281,     /* EnumBodyDeclarations  */
  YYSYMBOL_RecordDeclarationSym = 282,     /* RecordDeclarationSym  */
  YYSYMBOL_RecordDeclaration = 283,        /* RecordDeclaration  */
  YYSYMBOL_RecordHeader = 284,             /* RecordHeader  */
  YYSYMBOL_RecordComponentList = 285,      /* RecordComponentList  */
  YYSYMBOL_RecordComponent = 286,          /* RecordComponent  */
  YYSYMBOL_VariableArityRecordComponent = 287, /* VariableArityRecordComponent  */
  YYSYMBOL_RecordBody = 288,               /* RecordBody  */
  YYSYMBOL_RecordBodyDeclaration = 289,    /* RecordBodyDeclaration  */
  YYSYMBOL_CompactConstructorDeclarationSym = 290, /* CompactConstructorDeclarationSym  */
  YYSYMBOL_CompactConstructorDeclaration = 291, /* CompactConstructorDeclaration  */
  YYSYMBOL_InterfaceDeclaration = 292,     /* InterfaceDeclaration  */
  YYSYMBOL_NormalInterfaceDeclaration = 293, /* NormalInterfaceDeclaration  */
  YYSYMBOL_294_41 = 294,                   /* $@41  */
  YYSYMBOL_295_42 = 295,                   /* $@42  */
  YYSYMBOL_296_43 = 296,                   /* $@43  */
  YYSYMBOL_297_44 = 297,                   /* $@44  */
  YYSYMBOL_298_45 = 298,                   /* $@45  */
  YYSYMBOL_299_46 = 299,                   /* $@46  */
  YYSYMBOL_300_47 = 300,                   /* $@47  */
  YYSYMBOL_301_48 = 301,                   /* $@48  */
  YYSYMBOL_302_49 = 302,                   /* $@49  */
  YYSYMBOL_303_50 = 303,                   /* $@50  */
  YYSYMBOL_304_51 = 304,                   /* $@51  */
  YYSYMBOL_305_52 = 305,                   /* $@52  */
  YYSYMBOL_306_53 = 306,                   /* $@53  */
  YYSYMBOL_307_54 = 307,                   /* $@54  */
  YYSYMBOL_308_55 = 308,                   /* $@55  */
  YYSYMBOL_309_56 = 309,                   /* $@56  */
  YYSYMBOL_InterfaceModifier = 310,        /* InterfaceModifier  */
  YYSYMBOL_InterfaceExtends = 311,         /* InterfaceExtends  */
  YYSYMBOL_InterfacePermits = 312,         /* InterfacePermits  */
  YYSYMBOL_InterfaceBody = 313,            /* InterfaceBody  */
  YYSYMBOL_InterfaceMemberDeclaration = 314, /* InterfaceMemberDeclaration  */
  YYSYMBOL_ConstantDeclaration = 315,      /* ConstantDeclaration  */
  YYSYMBOL_InterfaceMethodDeclaration = 316, /* InterfaceMethodDeclaration  */
  YYSYMBOL_ArrayInitializer = 317,         /* ArrayInitializer  */
  YYSYMBOL_VariableInitializerList = 318,  /* VariableInitializerList  */
  YYSYMBOL_Block = 319,                    /* Block  */
  YYSYMBOL_BlockStatements = 320,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 321,           /* BlockStatement  */
  YYSYMBOL_LocalClassOrInterfaceDeclaration = 322, /* LocalClassOrInterfaceDeclaration  */
  YYSYMBOL_LocalVariableDeclarationStatement = 323, /* LocalVariableDeclarationStatement  */
  YYSYMBOL_LocalVariableDeclaration = 324, /* LocalVariableDeclaration  */
  YYSYMBOL_LocalVariableType = 325,        /* LocalVariableType  */
  YYSYMBOL_Statement = 326,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 327,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 328, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_329_57 = 329,                   /* $@57  */
  YYSYMBOL_EmptyStatement = 330,           /* EmptyStatement  */
  YYSYMBOL_LabeledStatement = 331,         /* LabeledStatement  */
  YYSYMBOL_LabeledStatementNoShortIf = 332, /* LabeledStatementNoShortIf  */
  YYSYMBOL_ExpressionStatement = 333,      /* ExpressionStatement  */
  YYSYMBOL_StatementExpression = 334,      /* StatementExpression  */
  YYSYMBOL_IfThenStatement = 335,          /* IfThenStatement  */
  YYSYMBOL_IfThenElseStatement = 336,      /* IfThenElseStatement  */
  YYSYMBOL_IfThenElseStatementNoShortIf = 337, /* IfThenElseStatementNoShortIf  */
  YYSYMBOL_AssertStatement = 338,          /* AssertStatement  */
  YYSYMBOL_SwitchStatement = 339,          /* SwitchStatement  */
  YYSYMBOL_340_58 = 340,                   /* $@58  */
  YYSYMBOL_SwitchBlock = 341,              /* SwitchBlock  */
  YYSYMBOL_SwitchRule = 342,               /* SwitchRule  */
  YYSYMBOL_SwitchBlockStatementGroup = 343, /* SwitchBlockStatementGroup  */
  YYSYMBOL_SwitchLabel = 344,              /* SwitchLabel  */
  YYSYMBOL_CaseConstant = 345,             /* CaseConstant  */
  YYSYMBOL_WhileStatement = 346,           /* WhileStatement  */
  YYSYMBOL_WhileStatementNoShortIf = 347,  /* WhileStatementNoShortIf  */
  YYSYMBOL_DoStatement = 348,              /* DoStatement  */
  YYSYMBOL_ForStatement = 349,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 350,    /* ForStatementNoShortIf  */
  YYSYMBOL_ForSym = 351,                   /* ForSym  */
  YYSYMBOL_BasicForStatement = 352,        /* BasicForStatement  */
  YYSYMBOL_BasicForStatementNoShortIf = 353, /* BasicForStatementNoShortIf  */
  YYSYMBOL_ForInit = 354,                  /* ForInit  */
  YYSYMBOL_ForUpdate = 355,                /* ForUpdate  */
  YYSYMBOL_StatementExpressionList = 356,  /* StatementExpressionList  */
  YYSYMBOL_EnhancedForStatementSym = 357,  /* EnhancedForStatementSym  */
  YYSYMBOL_EnhancedForStatement = 358,     /* EnhancedForStatement  */
  YYSYMBOL_EnhancedForStatementNoShortIf = 359, /* EnhancedForStatementNoShortIf  */
  YYSYMBOL_BreakStatement = 360,           /* BreakStatement  */
  YYSYMBOL_YieldStatement = 361,           /* YieldStatement  */
  YYSYMBOL_ContinueStatement = 362,        /* ContinueStatement  */
  YYSYMBOL_ReturnStatement = 363,          /* ReturnStatement  */
  YYSYMBOL_ThrowStatement = 364,           /* ThrowStatement  */
  YYSYMBOL_SynchronizedStatement = 365,    /* SynchronizedStatement  */
  YYSYMBOL_366_59 = 366,                   /* $@59  */
  YYSYMBOL_TrySym = 367,                   /* TrySym  */
  YYSYMBOL_TryBlockSym = 368,              /* TryBlockSym  */
  YYSYMBOL_TryStatement = 369,             /* TryStatement  */
  YYSYMBOL_Catches = 370,                  /* Catches  */
  YYSYMBOL_CatchClause = 371,              /* CatchClause  */
  YYSYMBOL_372_60 = 372,                   /* $@60  */
  YYSYMBOL_CatchFormalParameter = 373,     /* CatchFormalParameter  */
  YYSYMBOL_CatchType = 374,                /* CatchType  */
  YYSYMBOL_Finally = 375,                  /* Finally  */
  YYSYMBOL_376_61 = 376,                   /* $@61  */
  YYSYMBOL_TryWithResourcesStatement = 377, /* TryWithResourcesStatement  */
  YYSYMBOL_ResourceSpecification = 378,    /* ResourceSpecification  */
  YYSYMBOL_ResourceList = 379,             /* ResourceList  */
  YYSYMBOL_Resource = 380,                 /* Resource  */
  YYSYMBOL_Primary = 381,                  /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 382,        /* PrimaryNoNewArray  */
  YYSYMBOL_ClassLiteral = 383,             /* ClassLiteral  */
  YYSYMBOL_ClassInstanceCreationExpression = 384, /* ClassInstanceCreationExpression  */
  YYSYMBOL_UnqualifiedClassInstanceCreationExpression = 385, /* UnqualifiedClassInstanceCreationExpression  */
  YYSYMBOL_ClassOrInterfaceTypeToInstantiate = 386, /* ClassOrInterfaceTypeToInstantiate  */
  YYSYMBOL_FieldAccess = 387,              /* FieldAccess  */
  YYSYMBOL_ArrayAccess = 388,              /* ArrayAccess  */
  YYSYMBOL_MethodInvocation = 389,         /* MethodInvocation  */
  YYSYMBOL_ArgumentList = 390,             /* ArgumentList  */
  YYSYMBOL_MethodReference = 391,          /* MethodReference  */
  YYSYMBOL_ArrayCreationExpression = 392,  /* ArrayCreationExpression  */
  YYSYMBOL_DimExpr = 393,                  /* DimExpr  */
  YYSYMBOL_Expression = 394,               /* Expression  */
  YYSYMBOL_AssignmentExpression = 395,     /* AssignmentExpression  */
  YYSYMBOL_Assignment = 396,               /* Assignment  */
  YYSYMBOL_LeftHandSide = 397,             /* LeftHandSide  */
  YYSYMBOL_AssignmentOperator = 398,       /* AssignmentOperator  */
  YYSYMBOL_ConditionalExpression = 399,    /* ConditionalExpression  */
  YYSYMBOL_ConditionalOrExpression = 400,  /* ConditionalOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 401, /* ConditionalAndExpression  */
  YYSYMBOL_InclusiveOrExpression = 402,    /* InclusiveOrExpression  */
  YYSYMBOL_ExclusiveOrExpression = 403,    /* ExclusiveOrExpression  */
  YYSYMBOL_AndExpression = 404,            /* AndExpression  */
  YYSYMBOL_EqualityExpression = 405,       /* EqualityExpression  */
  YYSYMBOL_RelationalExpression = 406,     /* RelationalExpression  */
  YYSYMBOL_InstanceofExpression = 407,     /* InstanceofExpression  */
  YYSYMBOL_ShiftExpression = 408,          /* ShiftExpression  */
  YYSYMBOL_AdditiveExpression = 409,       /* AdditiveExpression  */
  YYSYMBOL_MultiplicativeExpression = 410, /* MultiplicativeExpression  */
  YYSYMBOL_UnaryExpression = 411,          /* UnaryExpression  */
  YYSYMBOL_PreIncrementExpression = 412,   /* PreIncrementExpression  */
  YYSYMBOL_PreDecrementExpression = 413,   /* PreDecrementExpression  */
  YYSYMBOL_UnaryExpressionNotPlusMinus = 414, /* UnaryExpressionNotPlusMinus  */
  YYSYMBOL_PostfixExpression = 415,        /* PostfixExpression  */
  YYSYMBOL_PostIncrementExpression = 416,  /* PostIncrementExpression  */
  YYSYMBOL_PostDecrementExpression = 417,  /* PostDecrementExpression  */
  YYSYMBOL_CastExpression = 418,           /* CastExpression  */
  YYSYMBOL_SwitchExpression = 419,         /* SwitchExpression  */
  YYSYMBOL_420_62 = 420,                   /* $@62  */
  YYSYMBOL_VariableAccess = 421            /* VariableAccess  */
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
#define YYLAST   7533

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  119
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  303
/* YYNRULES -- Number of rules.  */
#define YYNRULES  745
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1287

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
       0,   790,   790,   791,   793,   795,   796,   798,   800,   802,
     803,   805,   806,   808,   809,   811,   812,   814,   815,   817,
     818,   820,   822,   823,   825,   826,   828,   829,   831,   832,
     834,   836,   837,   839,   841,   842,   844,   845,   847,   849,
     850,   852,   854,   855,   857,   859,   860,   862,   864,   865,
     867,   868,   870,   871,   873,   875,   876,   878,   879,   881,
     882,   884,   885,   887,   889,   890,   892,   894,   895,   897,
     899,   900,   902,   903,   905,   907,   908,   910,   912,   913,
     915,   917,   918,   920,   921,   922,   923,   924,   925,   926,
     927,   929,   931,   932,   933,   934,   935,   936,   937,   938,
     939,   940,   941,   942,   943,   944,   945,   946,   956,   957,
     958,   959,   960,   961,   962,   964,   965,   967,   969,   970,
     972,   973,   974,   975,   976,   978,   979,   981,   982,   984,
     985,   987,   988,   990,   992,   993,   995,   996,   998,  1000,
    1001,  1003,  1004,  1005,  1006,  1007,  1008,  1009,  1010,  1012,
    1013,  1015,  1016,  1018,  1019,  1020,  1021,  1023,  1024,  1026,
    1028,  1029,  1031,  1032,  1034,  1035,  1036,  1038,  1038,  1039,
    1039,  1040,  1040,  1041,  1041,  1042,  1042,  1043,  1043,  1044,
    1044,  1045,  1045,  1047,  1048,  1049,  1050,  1051,  1052,  1053,
    1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,
    1064,  1065,  1066,  1067,  1068,  1069,  1070,  1072,  1073,  1074,
    1076,  1076,  1077,  1077,  1078,  1078,  1079,  1079,  1080,  1080,
    1081,  1081,  1082,  1082,  1083,  1083,  1084,  1084,  1085,  1085,
    1086,  1086,  1087,  1087,  1088,  1088,  1089,  1089,  1090,  1090,
    1091,  1091,  1092,  1092,  1093,  1093,  1094,  1094,  1095,  1095,
    1096,  1096,  1097,  1097,  1098,  1098,  1099,  1099,  1100,  1100,
    1101,  1101,  1102,  1102,  1103,  1103,  1104,  1104,  1105,  1105,
    1106,  1106,  1107,  1107,  1109,  1111,  1112,  1114,  1116,  1118,
    1119,  1122,  1123,  1124,  1125,  1127,  1128,  1130,  1131,  1132,
    1133,  1135,  1136,  1137,  1138,  1139,  1143,  1144,  1146,  1147,
    1149,  1150,  1152,  1153,  1156,  1157,  1159,  1160,  1161,  1163,
    1164,  1166,  1167,  1170,  1171,  1173,  1174,  1175,  1176,  1178,
    1179,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1191,
    1192,  1194,  1195,  1197,  1198,  1199,  1201,  1202,  1204,  1206,
    1207,  1209,  1212,  1213,  1215,  1217,  1220,  1221,  1222,  1223,
    1225,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,  1237,
    1238,  1239,  1240,  1242,  1243,  1244,  1245,  1246,  1247,  1248,
    1249,  1250,  1251,  1253,  1254,  1255,  1256,  1259,  1260,  1261,
    1262,  1263,  1264,  1266,  1267,  1269,  1271,  1273,  1274,  1275,
    1276,  1277,  1278,  1280,  1281,  1283,  1285,  1286,  1287,  1288,
    1289,  1290,  1291,  1292,  1295,  1296,  1298,  1299,  1301,  1302,
    1305,  1307,  1308,  1310,  1311,  1313,  1315,  1316,  1319,  1321,
    1321,  1322,  1322,  1323,  1323,  1324,  1324,  1325,  1325,  1326,
    1326,  1327,  1327,  1328,  1328,  1329,  1329,  1330,  1330,  1331,
    1331,  1332,  1332,  1333,  1333,  1334,  1334,  1335,  1335,  1336,
    1336,  1339,  1341,  1343,  1344,  1346,  1347,  1349,  1350,  1351,
    1352,  1353,  1355,  1356,  1358,  1359,  1361,  1362,  1363,  1365,
    1366,  1368,  1369,  1371,  1372,  1374,  1375,  1376,  1378,  1379,
    1381,  1404,  1405,  1407,  1408,  1410,  1411,  1412,  1413,  1414,
    1415,  1417,  1418,  1419,  1420,  1421,  1423,  1423,  1424,  1425,
    1426,  1427,  1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,
    1437,  1439,  1441,  1444,  1446,  1447,  1448,  1449,  1450,  1451,
    1452,  1454,  1456,  1458,  1460,  1461,  1463,  1463,  1465,  1466,
    1467,  1468,  1469,  1470,  1472,  1473,  1474,  1476,  1477,  1479,
    1480,  1481,  1483,  1485,  1487,  1489,  1491,  1492,  1494,  1495,
    1497,  1499,  1500,  1501,  1502,  1503,  1504,  1505,  1506,  1508,
    1509,  1510,  1511,  1512,  1513,  1514,  1515,  1517,  1518,  1520,
    1522,  1523,  1525,  1527,  1529,  1531,  1532,  1535,  1537,  1538,
    1541,  1542,  1544,  1546,  1546,  1548,  1550,  1552,  1553,  1554,
    1555,  1557,  1558,  1560,  1560,  1562,  1563,  1565,  1566,  1569,
    1569,  1571,  1572,  1573,  1574,  1576,  1578,  1579,  1581,  1582,
    1584,  1585,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,
    1595,  1596,  1597,  1599,  1600,  1601,  1602,  1603,  1604,  1606,
    1607,  1608,  1609,  1615,  1616,  1617,  1618,  1620,  1621,  1623,
    1624,  1625,  1626,  1628,  1629,  1630,  1632,  1633,  1634,  1635,
    1636,  1637,  1638,  1639,  1640,  1641,  1642,  1643,  1644,  1645,
    1648,  1649,  1651,  1652,  1653,  1654,  1655,  1656,  1657,  1658,
    1660,  1661,  1662,  1663,  1664,  1665,  1668,  1670,  1672,  1673,
    1675,  1677,  1678,  1679,  1680,  1682,  1684,  1685,  1687,  1688,
    1690,  1691,  1693,  1694,  1696,  1697,  1699,  1700,  1702,  1703,
    1704,  1706,  1707,  1708,  1709,  1710,  1711,  1716,  1718,  1719,
    1720,  1721,  1723,  1724,  1725,  1727,  1728,  1729,  1730,  1732,
    1733,  1734,  1735,  1736,  1738,  1740,  1742,  1743,  1744,  1745,
    1746,  1748,  1749,  1750,  1751,  1752,  1754,  1756,  1758,  1759,
    1760,  1762,  1762,  1764,  1765,  1766
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

#define YYPACT_NINF (-1110)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-746)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1362, -1110,   -29, -1110, -1110,    31, -1110,   -29, -1110,   -29,
   -1110,   -29, -1110,   -29, -1110,    68,   -29, -1110,  1777,  1513,
    1160, -1110,    97, -1110, -1110,  2005, -1110, -1110, -1110, -1110,
   -1110, -1110, -1110, -1110, -1110, -1110,   259, -1110, -1110, -1110,
   -1110, -1110,   436,   -29,   473,   482,    39,   329,   328,   406,
     -29, -1110,  1513, -1110, -1110, -1110,   -29,   -29,   -29,   259,
   -1110, -1110,  2005,  1513,   -29,   832,   105,    40, -1110,   -29,
     642,    36,   660, -1110,   210, -1110,   230,   -29,   466,   135,
   -1110,   -29,   -29,   111,   187,   305, -1110,   -29,   -29,   225,
     351,   125,   385, -1110,   323,   418,   433,    39,   329,   328,
     105,    40,  1513,   448,   390,   434, -1110, -1110, -1110, -1110,
   -1110, -1110, -1110, -1110, -1110,   450, -1110, -1110, -1110,   355,
     450, -1110,   415,   467, -1110,    40,  3055,   535, -1110, -1110,
   -1110,   -29,   252, -1110,   316,   587, -1110,   597, -1110,   541,
   -1110, -1110,  4335,   595,   -29, -1110,   638,   605,   648,   604,
   -1110, -1110,   692,   420,   187,   305, -1110,  4389, -1110,   187,
   -1110,   187, -1110,   554,   420,  3337, -1110,   225,   125,   385,
   -1110,   225,   385, -1110,   225, -1110,   225,   701,   574,   705,
     717,   444,   135, -1110,   111,   187,   305, -1110,   225,   351,
     125,   385, -1110,    40,   535, -1110,   -29, -1110,   -29,   390,
   -1110, -1110,   731,   450, -1110,   -29, -1110,   450, -1110,  1053,
     467, -1110,   535, -1110,   753,   -29,  3639, -1110, -1110,  3170,
    4220,   487, -1110,   898, -1110, -1110, -1110,   -29, -1110,   169,
     742, -1110, -1110, -1110,   228, -1110,   763, -1110, -1110, -1110,
   -1110, -1110,   762,   776, -1110, -1110,   -29,   541, -1110,  3170,
    4335,   379, -1110, -1110,   775, -1110,   648,  4962, -1110,   225,
     225, -1110,   782, -1110, -1110,   -29,   -29,   -29,   784, -1110,
   -1110,   187, -1110,   187, -1110, -1110,  3170,  4437, -1110,   898,
     -29,   169, -1110, -1110, -1110, -1110, -1110,   187, -1110,   784,
     784, -1110,  4274, -1110,   225,   385, -1110,   225, -1110,   225,
   -1110,   225, -1110,   225, -1110,   225, -1110, -1110,   -29,   -29,
     484,   -29,   -29,   499, -1110,   811,   574,   814,   574,   818,
   -1110,   187,   305, -1110, -1110,   187, -1110,   187, -1110,   225,
     125,   385, -1110,   225,   385, -1110,   225, -1110,   225,   535,
   -1110, -1110,   807, -1110, -1110, -1110, -1110, -1110, -1110, -1110,
   -1110, -1110, -1110,   255, -1110,  1053,   826,  6663,   829,   853,
    4635, -1110,   464,  6663,  5043, -1110,   854,   358,   883, -1110,
   -1110, -1110, -1110, -1110, -1110,   903,   867, -1110, -1110, -1110,
   -1110, -1110,   -29, -1110,  6663, -1110, -1110, -1110, -1110, -1110,
   -1110, -1110,  6663,  6663,  6663, -1110, -1110,   906,  3454,   870,
   -1110, -1110,   432,   911, -1110, -1110,   497,   916, -1110,   914,
    3754, -1110, -1110,   923,   -29, -1110, -1110,   753, -1110, -1110,
   -1110,   925, -1110, -1110, -1110, -1110, -1110, -1110, -1110,   933,
   -1110,   959, -1110, -1110, -1110, -1110, -1110, -1110, -1110,   686,
   -1110, -1110,   626,   940, -1110,   343, -1110,   296,   511,   456,
   -1110, -1110, -1110,   614, -1110, -1110,   691,   809,   850,   -29,
     169,   228,   763, -1110, -1110, -1110,  1421,   503,   -29,   742,
     532,   836, -1110,   949, -1110, -1110, -1110,  1866,  1027,   -29,
    3869,   763, -1110, -1110, -1110, -1110, -1110, -1110, -1110, -1110,
     955, -1110, -1110, -1110,  6663,  6663,  6663,  6663,  6663, -1110,
     740,   497,   916, -1110, -1110,   969,   951, -1110, -1110, -1110,
     359,   977,   992,   993,  1000,   677,   412, -1110,   793,   862,
     600, -1110, -1110, -1110, -1110,   691, -1110, -1110, -1110, -1110,
   -1110, -1110, -1110,   692,   991, -1110, -1110,   187, -1110,   -29,
     169, -1110, -1110,   861, -1110, -1110, -1110, -1110,   225, -1110,
     225, -1110,   225, -1110, -1110,   225, -1110, -1110,   265,   281,
     334,   340,   484, -1110, -1110,   726,   766,   773,    41,    67,
   -1110, -1110, -1110,   510, -1110,   549,   997,   574, -1110,   187,
   -1110,   187, -1110,   187, -1110, -1110,   225,   385, -1110,   225,
   -1110,   225, -1110,   225, -1110,   225, -1110,   225, -1110, -1110,
     -29,   807, -1110, -1110,   995,   542,   999, -1110,  1005,  6663,
      22,  6663,  6663,   695,  1060, -1110,  1002,  1003, -1110,  1004,
    1074,   -29,   -29,  6663,  1006,   272,   570, -1110, -1110, -1110,
   -1110,  1013, -1110,   -29,  4635,  5124,    78,   -29,   555,  5124,
     109,   -29,   565,  5205,  1076,    44, -1110,  3754, -1110, -1110,
     450,  1008, -1110, -1110,  3244,  6663,  4146, -1110,   325,   753,
      45,   -29,  6663, -1110, -1110, -1110,  6663, -1110, -1110,   895,
   -1110,   763, -1110, -1110,  2689,    48,  1009, -1110,  4565,   652,
    1016,  1011, -1110, -1110,  2955, -1110,  1027,   450, -1110,   -29,
    5286,   450,  3116,   110,  1018, -1110, -1110, -1110,  1015,  1023,
     363, -1110,   965,   531,  3984,  1021,   662, -1110,  6663, -1110,
   -1110, -1110, -1110,  1024,   497,   321, -1110,  6663,   951, -1110,
    6663,  6663,  6663,  6663,  6663,  6663,  6663,  6663,  6663,  6663,
    6663,  6663,  1053,  6663,  6663,  6663,  6663,  6663,  6663,  6663,
    6663, -1110,   907, -1110, -1110, -1110,   225, -1110, -1110, -1110,
     -29, -1110,   -29, -1110,   -29, -1110,   -29, -1110, -1110,   805,
   -1110,   -29, -1110, -1110,   -29,   -29, -1110, -1110, -1110,   607,
   -1110,   187, -1110, -1110, -1110,   225, -1110,   225, -1110,   225,
   -1110, -1110,   225, -1110, -1110, -1110, -1110, -1110,  5124,   816,
    1028,   999, -1110,   816,   999,  5367,  1030,  6663, -1110,  1031,
    1033,  1035, -1110, -1110, -1110, -1110,  1037, -1110,  1044, -1110,
   -1110,  1008, -1110,  1041,   -29, -1110, -1110,   690,  1048, -1110,
   -1110,  1112,  1046, -1110, -1110,   694,  1052, -1110, -1110,  1116,
   -1110,  1054, -1110, -1110, -1110, -1110,  5448,  4491,   580,  1077,
    1049,  1051, -1110,  1058,  4146, -1110,   671,   570, -1110,  1061,
    1057,   626,    80, -1110, -1110, -1110,  1128,  1140, -1110,   325,
    1068, -1110, -1110,  1067, -1110, -1110, -1110, -1110,  1072, -1110,
    1162,  1069, -1110,   747,   -29, -1110, -1110,  4565,  1011, -1110,
    4521, -1110,  1079, -1110, -1110,  4800, -1110, -1110, -1110,   450,
     450,  1081,   571,   450,   -29,  1015, -1110,  5529,  5610,   151,
     181, -1110,  1088, -1110,    60,  1091,  6663,  6744,   330, -1110,
   -1110,  1119,   977,   992,   993,  1000,   677,   412,   412,   793,
     793,   793,   793,   450, -1110,   450, -1110,   862,   862,   862,
     600,   600, -1110, -1110, -1110, -1110, -1110,   795,   801,   817,
     852, -1110, -1110,   865,   869,   879,   882, -1110, -1110, -1110,
     225, -1110, -1110, -1110,  1096, -1110,   450, -1110, -1110,   450,
     225,  1101, -1110,  1098,  4725, -1110,  6663,  5691,  4635, -1110,
    1099,   -29,   -29,  5772, -1110, -1110,   -29,   -29,  5853, -1110,
   -1110,  6816,  1100,  7416,  1049, -1110,  5934,  4635, -1110,  1057,
   -1110, -1110,  1105,   753, -1110,  1140, -1110,  1128, -1110,  6015,
   -1110, -1110, -1110, -1110,   -29, -1110, -1110, -1110, -1110, -1110,
    1107, -1110, -1110,  1106,  1103,  1108,   450,   450,   450, -1110,
   -1110,  1111,  1118,  1117,  1121,   404,   410, -1110,  1124, -1110,
   -1110, -1110,  6744,  6663, -1110,   -29,   909, -1110, -1110,   913,
   -1110,   915, -1110,   917, -1110,   934, -1110,   946, -1110,   957,
   -1110,   968, -1110, -1110, -1110,   225,  1110, -1110,  1125,  1127,
     772, -1110,  1209,  1210, -1110, -1110, -1110, -1110,  1130, -1110,
    1154, -1110,   753,  1132, -1110,  1134, -1110,  1138, -1110, -1110,
    1139,  1142, -1110, -1110,  1143,  4635,  1144, -1110,  6891, -1110,
   -1110,  6966,  1133, -1110,   484, -1110, -1110, -1110, -1110,  1145,
   -1110, -1110, -1110,  5286,  1103, -1110, -1110,   450, -1110,  1137,
   -1110,  1141,  6096,  6177,  6258,  1110, -1110, -1110,  1149, -1110,
   -1110, -1110, -1110, -1110, -1110, -1110, -1110, -1110, -1110,    84,
   -1110,  6663,  6663,  4725,  4635,  4065,  6663, -1110,  1146, -1110,
    6339, -1110,  6420, -1110, -1110,  4635,  4635,  1148,  4635,  1150,
    7041,   484,  1158,  1152,   -29, -1110, -1110, -1110, -1110, -1110,
    1157,  1159,  1161,  1164,  1165,  1167, -1110, -1110,  6663, -1110,
     274,   290, -1110,   311, -1110,  1012,  1174,  1175, -1110, -1110,
    6501,  1171,  1178, -1110, -1110,  1179, -1110,  1183, -1110, -1110,
    4635, -1110,  4635,  4635,  1184,   -29,   -29,  1158, -1110,   753,
   -1110, -1110,  1180, -1110,  1182, -1110,  1185,  1151, -1110, -1110,
     312, -1110,  1212, -1110, -1110,  1213, -1110,   317, -1110,  1216,
    3754,  4881,  4725,  4725,  7116,  1189,  6582,  4725, -1110, -1110,
   -1110, -1110, -1110,  4635, -1110, -1110, -1110, -1110, -1110, -1110,
   -1110,  6663,  1151, -1110, -1110, -1110, -1110, -1110,  3524, -1110,
   -1110, -1110,  1192,  1280, -1110,  4725,  1199,  7191,  7266,  1196,
   -1110, -1110, -1110, -1110, -1110, -1110,  4725, -1110,  4725,  4725,
    1202,  4725,  1204,  7341, -1110, -1110, -1110,  4725, -1110,  4725,
    4725,  1205, -1110, -1110, -1110,  4725, -1110
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     141,    86,     0,    85,    84,     0,    83,     0,    90,     0,
      87,     0,    89,     0,    88,     0,     0,   166,   143,   142,
       0,   451,     0,   139,   140,   145,     9,   153,   154,   156,
     155,    11,   149,   164,   207,   208,     0,   209,   165,   418,
      26,    91,     0,     0,     0,     0,     0,   419,   210,     0,
       0,   395,   144,    10,   150,    12,     0,     0,     0,     0,
      27,     1,   147,   146,     0,     0,     0,     0,   151,     0,
       0,     0,     0,   157,     0,   158,     0,     0,     0,     0,
     373,     0,     0,   427,     0,   423,   421,     0,     0,     0,
     226,   218,   214,   212,   169,     0,     0,     0,   435,   242,
       0,     0,   148,   129,   275,     0,   310,   126,   120,   122,
     121,   124,   123,   125,   404,   307,   309,   118,   119,     0,
     306,   308,     0,   406,   409,     0,     0,     0,   396,    13,
     152,     0,     0,   159,     0,     0,   136,     0,   137,   279,
     278,   377,   393,     0,   384,    42,   387,     0,   383,     0,
     374,   452,     0,   453,     0,   431,   429,     0,   420,     0,
     425,     0,   277,   281,   282,     0,   211,     0,   234,   230,
     228,     0,   222,   220,     0,   216,     0,     0,     0,   173,
     177,     0,     0,   375,   443,     0,   439,   437,     0,   258,
     250,   246,   244,     0,     0,   400,     0,   130,     0,   276,
      28,   274,     0,   312,     2,     0,   408,   311,   405,     0,
     407,    45,     0,   398,    87,     0,   496,   411,   295,     0,
       0,   307,   293,     0,   413,   287,   291,     0,   292,     0,
       0,   288,   289,   290,     0,    48,     0,   414,   294,   344,
     397,    14,     0,     0,   160,   161,     0,   280,    31,     0,
     394,   307,    34,   379,     0,    43,     0,     0,   390,   388,
     389,   381,     0,    44,   378,     0,     0,     0,   454,    22,
     428,     0,   433,     0,   455,   461,     0,     0,   459,     0,
       0,     0,   460,    50,   457,   458,   424,     0,   422,   283,
     284,   285,     0,   227,     0,   238,   236,     0,   232,     0,
     219,     0,   224,     0,   215,     0,   213,   168,     0,     0,
       0,     0,     0,     0,    15,     0,     0,     0,     0,   181,
     376,     0,   447,   445,   436,     0,   441,     0,   243,     0,
     266,   262,   260,     0,   254,   252,     0,   248,     0,     0,
     402,   401,   131,    30,    29,     4,     3,   410,    47,    46,
     399,   345,   320,     0,   550,     0,     0,     0,     0,     0,
     496,   614,     0,     0,     0,   585,     0,     0,     0,    93,
      94,    95,    96,    97,    98,    88,   100,   101,   102,   103,
     104,   105,   106,   107,     0,   108,   109,   110,   111,   112,
     113,   114,     0,     0,     0,   471,   510,    91,     0,   682,
     138,   612,   733,     0,   478,   483,   306,   308,   479,     0,
     473,   475,   476,     0,     0,   477,   485,     0,   498,   486,
     499,     0,   487,   488,   500,   501,   489,   502,   490,     0,
     546,     0,   547,   503,   509,   504,   505,   507,   506,     0,
     508,   590,   731,   610,   613,   618,   629,   619,   620,   621,
     622,   611,   514,     0,   515,   516,     0,   517,   518,     0,
       0,     0,     0,   412,    49,   350,     0,   307,     0,     0,
     302,     0,   298,   300,   343,   313,   342,     0,   315,     0,
     496,     0,   346,   416,   162,   163,    33,    32,    35,   380,
       0,    99,   100,   106,     0,     0,     0,     0,     0,   385,
     732,     0,     0,   618,   621,     0,   660,   677,   679,   678,
     686,   688,   690,   692,   694,   696,   698,   706,   701,   708,
     712,   715,   719,   720,   723,   726,   734,   735,   729,   730,
     391,   392,   382,    24,    25,    23,   432,     0,   430,     0,
       0,   456,    51,     0,   464,   426,   286,   235,     0,   240,
       0,   231,     0,   229,   223,     0,   221,   217,     0,     0,
       0,     0,     0,    17,   134,     0,     0,     0,     0,     0,
     170,    16,   172,     0,   176,     0,     0,     0,   444,     0,
     449,     0,   440,     0,   438,   259,     0,   270,   268,     0,
     264,     0,   251,     0,   256,     0,   247,     0,   245,   403,
       0,   132,     5,   578,     0,   637,     0,   117,     0,     0,
       0,     0,     0,   682,     0,   575,     0,     0,   580,     0,
       0,     0,     0,     0,     0,   732,   733,   619,   620,   724,
     725,     0,   484,     0,   496,     0,     0,     0,   312,     0,
       0,     0,     0,     0,     0,     0,   472,   474,    55,   480,
     302,   481,   497,   513,     0,     0,     0,   586,     0,     0,
       0,     0,     0,   116,   115,   685,     0,   736,   737,     0,
     314,     0,   348,   417,     0,     0,     0,   351,     0,     0,
       0,   331,   335,   350,     0,   319,   317,   303,   296,     0,
       0,   321,     0,     0,     0,   316,   341,   338,   339,   614,
       0,   359,   682,   681,   496,     0,   731,   347,     0,   728,
     727,   721,   722,     0,   117,     0,   386,     0,   661,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   434,     0,   465,   462,   239,     0,   237,   233,   225,
       0,   185,     0,   194,     0,   188,     0,   197,    18,     0,
     183,     0,   191,   200,     0,     0,   174,   178,   180,     0,
     448,     0,   446,   442,   267,     0,   272,     0,   263,     0,
     261,   255,     0,   253,   249,   133,     6,   579,     0,     0,
     638,   672,    81,     0,   670,     0,     0,     0,   524,     0,
       0,     0,   576,   582,   581,   628,   640,   666,     0,   577,
     617,   482,   511,     0,     0,   615,   623,     0,   136,   630,
     662,     0,     0,   616,   624,     0,   137,   631,   663,     0,
     647,     0,   627,   669,   665,    56,     0,     0,   682,   568,
     570,     0,   567,     0,   607,    75,   744,   743,   608,     0,
     606,     0,   619,   609,   593,   599,   587,   591,   588,   601,
     639,   632,   664,     0,   680,   297,   349,   353,     0,   329,
       0,     0,     7,     0,     0,   333,   352,     0,   332,    36,
       0,   355,     0,   318,   299,     0,   301,   305,   304,   322,
     325,     0,   302,   323,     0,   340,    39,     0,     0,     0,
       0,   361,     0,   360,     0,     0,     0,     0,     0,    80,
      79,     0,   689,   691,   693,   695,   697,   699,   700,   703,
     702,   705,   704,   127,   707,     0,   128,   709,   710,   711,
     713,   714,   716,   717,   718,   463,   241,     0,     0,     0,
       0,   184,   135,     0,     0,     0,     0,   182,   450,   271,
       0,   269,   265,   257,     0,   675,   673,    82,   674,   671,
     633,     0,   526,     0,   496,   583,     0,     0,   496,   643,
     637,     0,     0,     0,   625,   644,     0,     0,     0,   626,
     646,     0,     0,     0,   571,    67,     0,   496,    76,     0,
     605,    77,     0,     0,   589,   592,    70,   603,   602,     0,
     645,   354,   330,     8,     0,   334,   336,    38,    37,   357,
       0,   356,   466,     0,   469,     0,   326,   327,   324,    41,
      40,     0,     0,     0,     0,     0,     0,   362,     0,   741,
     738,   739,     0,     0,   186,     0,     0,    19,   195,     0,
     189,     0,   198,     0,   192,     0,   205,     0,   203,     0,
     201,     0,   273,   676,   634,   635,     0,   525,     0,     0,
     682,   521,     0,   485,   492,   493,   494,   495,     0,   548,
       0,   549,     0,     0,   654,     0,   543,   641,   667,   648,
       0,   642,   668,   650,     0,   496,     0,   569,     0,    69,
      68,     0,     0,   573,     0,   600,    71,   604,   652,     0,
     337,   358,   467,     0,   470,    52,   468,   328,   363,     0,
     365,     0,     0,     0,     0,     0,   740,   687,    21,   187,
      20,   196,   190,   199,   193,   204,   206,   202,   636,     0,
     527,     0,     0,   496,   496,     0,     0,   584,     0,   655,
       0,   649,     0,   651,   551,   496,   496,     0,   496,     0,
       0,     0,   597,     0,     0,   653,    54,    53,   364,   366,
       0,     0,     0,     0,     0,     0,   742,   541,     0,   530,
       0,     0,    61,     0,    59,     0,     0,     0,   512,   522,
       0,     0,     0,   545,   656,     0,   658,     0,   552,   553,
     496,   555,   496,   496,     0,     0,     0,   598,    72,     0,
     595,   367,     0,   369,     0,   371,     0,   539,   542,   532,
       0,    60,     0,   531,    62,     0,   528,     0,    57,     0,
      63,     0,   496,   496,     0,     0,     0,   496,   657,   659,
     554,   556,   557,   496,   596,    74,    73,   594,   368,   370,
     372,     0,   540,    64,   533,    63,   529,    58,   496,   537,
     535,   536,     0,     0,   544,   496,     0,     0,     0,     0,
     574,   558,    66,    65,   538,   534,   496,   559,   496,   496,
       0,   496,     0,     0,   523,   560,   561,   496,   563,   496,
     496,     0,   562,   564,   565,   496,   566
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1110,  2050,  -180,   599,  -438, -1110,  1287,    52,   287,  -286,
   -1110,     5,  -535,  -144,  -253,   632, -1110,  1120, -1110,  1070,
    1153, -1110,   437, -1110,   425, -1110,  1177, -1110,  1113, -1110,
   -1110, -1110,   221, -1110, -1110, -1110, -1109, -1036, -1110,    85,
   -1110,   342, -1110, -1110,   134, -1110,   488, -1110,   615,   732,
    -276,    -2, -1110, -1110, -1110,   839, -1110, -1110, -1110, -1110,
    1147, -1110,  -583,  -517,    93, -1110, -1110, -1110, -1110, -1110,
     116, -1110, -1110, -1110, -1110,   232,  1321, -1110, -1110, -1110,
   -1110, -1110, -1110, -1110, -1110,  -270,  -113, -1110, -1110, -1110,
   -1110, -1110, -1110, -1110, -1110, -1110, -1110, -1110, -1110, -1110,
   -1110, -1110, -1110, -1110, -1110, -1110, -1110, -1110, -1110, -1110,
   -1110, -1110, -1110, -1110, -1110, -1110, -1110, -1110, -1110, -1110,
      54, -1110,    51,  1502,  1259,    98,  2336,  -107, -1110, -1110,
    -254,   653,  -651,  -860,    73,   491,   794, -1110,  -110,  -183,
     878, -1110,  -413,   471, -1110,  -372, -1110,   457,  -224, -1110,
   -1110, -1110,   886,  -128,  -212, -1110, -1110,     2, -1110, -1110,
   -1110,  1214,   545,    62, -1110,   352, -1110,  1163, -1110,   107,
    1136,  1155, -1110,   308,  -208, -1110, -1110, -1110, -1110, -1110,
   -1110, -1110, -1110, -1110, -1110, -1110, -1110, -1110, -1110, -1110,
   -1110,    -3,    25,   258,   -67,  1082, -1110, -1110,   -88, -1110,
    -198,  -476,  -388, -1110, -1110,  -644,  -396,   216,   502,  -218,
   -1110, -1110, -1110, -1110, -1110,  -608, -1110, -1110, -1110, -1110,
   -1110, -1110,   248, -1095,   196,  -796,   126, -1110, -1110, -1110,
   -1110, -1110,    75, -1110, -1110,   234,  -835,  -653,   277, -1110,
   -1110, -1110, -1110, -1110, -1110,   149, -1110, -1110, -1110,   716,
   -1110,   517,  -819, -1110, -1110,   226,  -740, -1110, -1110, -1110,
   -1110,   536,  -474, -1110, -1110,   430,  -587, -1110,  2294,  2314,
     675,  -543, -1110, -1110,    74,  2289, -1110,   877, -1110, -1110,
   -1012, -1110,   661,   659,   666,   668,   665,   373, -1110,  -105,
     263,   366,  -324,  1026,  1097,  -874,  1273,  1344,  1610, -1110,
   -1110, -1110, -1110
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   638,   204,   601,   674,   870,    18,    19,   790,   313,
     562,  1036,  1037,   268,   269,    20,   199,   200,   247,   248,
     250,   878,   879,   895,   896,   144,   145,   210,   211,   220,
     277,  1104,  1105,   647,  1217,  1170,  1171,  1172,  1242,  1243,
     984,   985,   995,  1197,  1198,   844,   845,   718,   719,   791,
      21,   500,   400,   401,   665,   606,   116,   117,   118,   924,
     104,   197,   602,   565,   402,   403,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,   177,   178,   315,
     316,   317,   318,   576,   577,   314,    33,    34,    89,   176,
     174,   305,   171,   303,   301,   555,   167,   299,   297,   552,
     294,   550,   548,   746,   188,   338,   336,   597,   333,   595,
     593,   782,   329,   591,   589,   779,   586,   777,   775,   950,
     223,   105,    91,    79,   140,    93,   166,   224,   225,   226,
     471,   472,   473,   886,   405,   501,   502,   228,   229,   230,
     478,   676,   680,   681,   682,   481,   697,   698,   475,   231,
     232,   233,   466,   234,   482,   704,    35,    80,   147,   259,
     260,   148,   149,    36,    37,    67,   122,   123,   124,   128,
     235,   236,   237,    38,    39,    84,   161,   159,   287,   154,
     273,   271,   537,   185,   327,   325,   583,   321,   581,   579,
     771,    40,    85,    86,   158,   283,   284,   285,   887,  1015,
     239,   409,   410,   411,   412,   413,   414,   415,  1062,   416,
     417,   418,   419,  1064,   420,   421,   422,   423,  1065,   424,
     425,  1056,  1130,  1173,  1174,  1215,  1207,   426,  1066,   427,
     428,  1067,   429,   430,  1069,   841,  1086,  1087,   431,   432,
    1071,   433,   434,   435,   436,   437,   438,  1072,   439,   658,
     440,   856,   857,   992,  1153,  1154,   858,   993,   441,   659,
     849,   850,   442,   443,   444,   503,   446,   608,   447,   448,
     504,   505,   450,   451,   792,   506,   507,   508,   453,   666,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,  1115,   853
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,   842,   633,    44,   705,    46,   706,    47,   408,    48,
     839,    49,   848,   222,    51,   535,   351,    60,   786,   289,
     290,  1117,   648,   346,   483,  1014,   543,   346,   875,   222,
     573,   476,   575,  1031,   563,   252,   535,   535,   996,   692,
     469,    71,   875,   571,   278,   759,   840,   281,    96,   819,
     833,   814,   222,   827,    97,    98,    99,   544,   252,    77,
      77,  1210,   103,   115,   694,   869,   814,   129,   629,   630,
      52,    43,   136,   861,   138,   139,   146,    63,  1218,   139,
     152,   150,    59,   476,   814,   162,   163,   270,    41,   671,
      66,   461,   286,  1167,   288,   815,   469,    61,    45,   183,
     831,    83,    90,   404,   797,   764,   695,   222,   155,   460,
    1028,  1248,  1168,   100,   102,   814,   994,   206,   324,   998,
     816,   461,  1247,   186,   221,    50,   823,   869,   817,   241,
     136,   765,   138,   798,    53,  1214,    72,   222,   119,   460,
     251,   168,   146,   488,    81,    77,    78,   126,    41,   132,
     190,   824,   184,   189,   265,   115,  1208,   814,  1116,   825,
     651,    41,    41,   251,   278,    41,   540,   281,   815,    82,
     709,   710,   711,   712,  1214,   153,  1096,    41,    53,   222,
     267,   164,   851,    88,   320,   488,  -745,   814,   170,   173,
     175,  -745,  1169,   816,   342,    41,   103,   192,   823,   227,
     848,  1025,   408,   347,   536,   669,   538,   115,   195,   322,
      65,   279,  1214,   352,   399,   227,    60,   221,   221,   652,
     545,   467,  1005,   824,   874,   470,    41,    41,   902,  1208,
     280,  1026,   213,   937,   240,   938,   670,   939,   227,   940,
     330,   657,    78,  1156,   486,   880,    60,   251,   251,   672,
     673,    55,   961,  1147,   578,   479,  1149,  1097,   582,   835,
     584,   868,   476,   136,   533,   138,   296,   298,    41,   707,
     302,   882,   408,    60,   115,   115,   216,   115,   470,   891,
     474,    59,   119,  1167,    55,   742,   758,   332,   335,   337,
     251,   769,   459,   227,   157,    55,   468,   404,    41,  1167,
     340,   341,  1168,   571,   135,   571,   558,   560,   564,   566,
     568,    59,   819,   827,   883,  1194,   743,   861,  1168,   350,
    1167,  1167,   459,   227,   137,   786,  1167,    41,   750,    70,
     279,   279,   165,  1175,    55,   480,    95,    64,    59,  1168,
    1168,   156,   476,   160,   752,  1168,   242,    41,    77,   539,
     280,   604,   468,   605,  1022,  1024,   187,   854,   613,   534,
     616,    87,    81,    82,    65,   227,   603,   404,   855,    41,
     851,    77,    41,   840,  1212,  1089,   751,  1219,   265,   811,
      51,   635,  1209,   181,    87,   636,    88,    82,   637,  1256,
     625,   625,   753,   549,   267,    60,   115,   754,  1213,  -683,
    -683,   559,   561,   756,   567,   569,    64,    64,   399,    88,
     243,   101,   650,   272,   932,   933,   934,   600,   125,  1216,
    1244,  1219,  1270,  1272,  1075,  1246,   600,   907,   588,   590,
    1080,  -167,   594,    41,   238,  1084,  1032,   645,  1281,   408,
     720,   633,   323,    88,   326,   755,   599,   265,   721,  -520,
     238,   757,   193,   267,  -520,  -520,  1099,   470,   346,   866,
      59,   657,   346,   115,   115,   282,   685,  1010,   898,   205,
     741,   621,    41,   238,   622,   115,   621,   696,   702,   622,
     840,   196,   842,   840,   465,   626,   626,     1,   202,   728,
     729,   839,   625,   625,   625,   625,   408,   730,   731,   571,
       3,  1120,   198,  1200,  1120,     4,  1120,   346,  1120,  1112,
       6,   201,   770,    94,   772,  1113,   773,   971,  1118,    69,
     972,   208,     8,   976,    10,   179,   977,   840,   238,    12,
     732,   131,   266,   267,   404,  -681,  -681,   470,   675,   679,
     180,   639,   840,    14,  1234,   640,    69,    68,   641,    69,
     693,   319,   308,   309,   310,   311,   120,   131,   238,   202,
     564,   312,  -519,   308,   309,   310,   311,  -519,  -519,  1161,
    1163,  1165,   312,   703,   141,   615,   614,   142,   143,   209,
     580,    41,  1030,    41,    73,   282,    74,   626,   626,   626,
     626,   404,   465,    75,  -415,    76,   202,  1185,   785,  1187,
     238,    41,   308,   309,   310,   311,   202,   570,   683,   346,
     644,   312,   202,   346,  -684,  -684,   840,   120,   766,   806,
     807,  -733,  -733,   919,   920,   921,   922,   308,   309,   310,
     311,   650,   613,   120,   818,   820,   312,  -319,   826,   828,
     639,   202,   126,   834,   900,   399,   445,   641,   120,   840,
     840,   788,   838,   246,   846,    69,   120,   767,   860,   862,
     308,   309,   310,   311,   202,   840,   266,   265,   821,   312,
    -732,  -732,   115,   871,   202,    60,   115,   650,   829,   639,
     202,   115,   115,   640,  1003,   776,   641,   650,   254,   635,
     115,   892,   262,   636,   738,   739,   637,  -307,   244,   740,
     120,   955,   399,   253,   948,   958,   142,   406,   245,   346,
     120,   120,   264,   261,   120,   947,   142,   663,   664,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     923,   625,   625,   625,   625,   625,   625,   625,   625,   660,
     120,   120,   661,   257,  1249,   165,  1063,   679,   564,   847,
     564,   873,   564,   130,   564,   131,   675,   679,   219,   942,
     263,   726,   943,   945,   727,   679,   874,   120,   120,    41,
     120,   133,  1264,   134,   249,   904,   346,   634,   661,   346,
     635,   667,   668,   120,   636,  -732,  -732,   637,  -307,   276,
     445,   656,   535,   216,   535,  1095,   535,   249,   535,  1045,
    1047,  1049,  1051,   971,   635,   265,   972,   976,   636,   307,
     977,   637,   970,  -171,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,  -175,   626,   626,   626,   626,
     626,   626,   626,   626,    60,   115,   346,   760,   346,   761,
     445,   345,   846,  -682,  -682,   106,   607,   477,   398,   635,
     812,   107,   219,   636,  1133,   108,   637,   944,   946,   121,
     216,  1004,  -732,  -732,    41,   957,   109,   110,   957,   111,
     480,   650,  1006,   484,  1137,   115,   112,   762,   115,   265,
     113,   635,   249,   489,   763,   636,   267,   485,   637,   120,
     532,   449,   696,   733,   734,   735,   266,   818,   826,  -734,
    -734,   406,   860,   600,   625,   625,  1034,  1035,   761,   276,
     445,   106,  1038,  1035,   761,  1063,   941,   107,   761,   572,
     121,   108,   574,   885,   249,   202,  -179,   346,  1040,  1035,
     761,   609,   109,   110,   611,   111,   121,   847,   114,   215,
    -735,  -735,   112,  1039,  1041,  1043,   113,   688,   689,    41,
     679,   121,   634,   679,   736,   737,   120,   120,   612,   121,
    -732,  -732,  1060,  1042,  1035,   761,   613,   620,   120,  1077,
    1078,   406,   744,   689,  1081,  1082,  1044,   266,   265,   635,
    1046,   266,   267,   636,  -484,   613,   637,  -307,   623,   714,
    1048,   266,   265,  1050,   266,   267,   927,   928,   929,   626,
     626,  1237,  1100,   121,  1063,  1063,   865,   689,   -99,  1063,
     407,   -92,   408,   121,   121,    41,   643,   121,   935,   689,
    1119,  1035,   646,  1250,  1121,  1035,  1122,  1035,  1123,  1035,
     625,   625,   645,   564,   649,   449,   653,  1063,   654,  1068,
     408,   655,   398,   121,   121,  1124,   266,   634,  1063,   662,
    1063,  1063,   690,  1063,   479,  -732,  -732,  1125,   266,  1063,
     708,  1063,  1063,   717,   445,   722,   106,  1063,  1126,   266,
     121,   121,   107,   121,   635,   716,   108,   445,   899,  1127,
     266,   637,  -307,   613,   445,   449,   121,   109,   110,   723,
     111,   724,  1152,   452,  1220,  1221,   725,   112,   678,   917,
     918,   113,   930,   931,   267,   768,   787,   404,   788,   678,
     795,   801,   398,   802,   803,   804,   805,   809,   832,   810,
     689,   872,   876,   877,   893,   626,   626,   894,   897,   903,
     906,  1060,   613,   838,   445,   404,   962,   964,   406,   965,
     966,   131,   967,   613,   613,   406,   613,   406,    60,  1152,
     968,   969,   650,   973,   974,   449,   975,   978,   979,  -572,
     980,   983,   986,     1,   987,   120,   625,   990,   991,   120,
      41,   855,   854,   999,   120,   120,     3,  1000,  1001,  1002,
    1061,     4,  1003,   120,  1076,  1011,     6,  1017,   613,    56,
     613,   613,   121,   650,  1235,   406,  1027,  1029,     8,    57,
      10,  1033,    58,  1093,   407,    12,  1053,  1055,  1068,  1057,
    1094,  1088,    69,  1101,  1102,  1103,  1106,  1129,   399,    14,
    1060,  1060,  1108,   925,  1109,  1060,    16,  1111,  1110,  1114,
    1131,   613,  1132,  1134,  -491,  1135,  1136,   452,  1138,   625,
    1139,  1070,   454,  1140,  1150,  1141,   399,  1142,  1158,  1143,
    1145,  1155,  1159,  1060,  1190,  1196,  1192,  1183,  1199,   121,
     121,   626,   761,  1241,  1060,  1202,  1060,  1060,  1201,  1060,
    1204,   121,  1203,  1206,   407,  1060,  1205,  1060,  1060,   398,
    1222,  1223,  1226,  1060,  1227,  1228,   837,   452,   837,  1229,
    1233,  1238,   715,  1239,  1220,  1245,  1240,  1068,  1068,  1221,
    1257,  1144,  1068,  1265,  1266,  1268,   678,  1273,  1277,   449,
    1279,  1285,    62,   455,   908,  1008,   678,   487,   292,   344,
    1020,   255,   449,   349,   678,  1157,  1090,  1263,   120,   449,
    1068,  1236,   988,   910,   626,   406,   398,   713,   794,    54,
     151,  1068,   884,  1068,  1068,   343,  1068,   686,  1007,   812,
    1179,  1019,  1068,   684,  1068,  1068,   464,   452,   256,   542,
    1068,  1188,  1189,  1166,  1191,     1,  1211,  1262,   120,  1181,
    1251,   120,   348,     2,   462,   859,   997,  1195,     3,   449,
     989,   913,   912,     4,     0,     0,   454,     5,     6,   914,
     916,     7,   915,     0,   445,     0,     0,     0,   445,     0,
       8,     9,    10,     0,    11,     0,  1230,    12,  1231,  1232,
    1070,   445,     0,   445,     0,     0,     0,   445,     0,    13,
       0,    14,     0,     0,     1,     0,     0,    15,    16,     0,
       0,     0,     0,     0,   106,     0,   454,     3,  1061,  1076,
     107,   407,     4,  1093,   108,     0,     0,     6,   407,  1261,
     407,     0,     0,     0,     0,   109,   110,   455,   111,     8,
       0,    10,     0,     0,     0,   112,    12,     0,   121,   113,
       0,  1144,   121,    17,     0,     0,   837,   121,   121,     0,
      14,     0,  1179,     0,  1188,  1189,   121,  1191,     0,   456,
       0,     0,     0,  1230,     0,  1231,  1232,     0,   407,  1070,
    1070,  1261,     0,     0,  1070,     0,   454,   455,     0,   678,
       0,   452,   678,     0,     0,   445,     1,     0,   445,     0,
       0,   445,     0,     0,   452,     0,   926,   677,     0,     3,
       0,   452,  1070,     0,     4,     0,     0,     0,    41,     6,
       0,     0,     7,  1070,     0,  1070,  1070,     0,  1070,     0,
      92,     8,     9,    10,  1070,    11,  1070,  1070,    12,     0,
     457,     0,  1070,   445,   445,   445,     0,     0,     0,   127,
       0,     0,    14,     0,     0,   445,   445,   455,   445,    16,
     445,   452,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   172,     0,     0,     0,     0,     0,   182,
       0,   191,     0,   194,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     445,     0,   445,   445,    17,     0,   406,   212,     0,     0,
       0,   121,     0,   456,     0,  1178,     0,     0,   407,   449,
       0,     0,     0,   449,     0,     0,     0,     0,     0,     0,
     445,     0,   445,   445,   445,     0,   449,   445,   449,     0,
     454,     0,   449,   445,     0,     0,     0,     0,     0,     0,
     295,   121,     0,   454,   121,     0,     0,     0,   445,     0,
     454,     0,     0,   456,     0,   445,     0,   445,   445,     0,
       0,   331,   334,     0,     0,   339,   445,     0,   445,   445,
       0,   445,     0,   445,   457,     0,     0,   445,     0,   445,
     445,   406,     0,     0,     0,   445,     0,     0,     0,     0,
       0,     0,     0,     0,  1253,  1254,  1151,     0,     0,  1260,
     454,   455,     0,     0,     0,     0,     0,     0,     0,   406,
       0,     0,     0,     0,   455,     0,     0,     0,     0,     0,
       0,   455,     0,   456,   457,     0,     0,  1267,     0,     0,
     449,     0,     0,   449,     0,     0,   449,   837,  1274,     0,
    1275,  1276,     0,  1278,     0,     0,     0,     0,     0,  1282,
       1,  1283,  1284,     0,     0,     0,     0,  1286,     0,     0,
       0,     0,     0,     3,     0,     0,     0,     0,     4,     0,
       0,   455,     5,     6,     0,     0,     7,     0,   449,   449,
     449,     0,     0,     0,     0,     8,     9,    10,     0,    11,
     449,   449,    12,   449,   457,   449,   458,     0,     0,     0,
       0,     0,   587,     0,    13,     0,    14,     0,     0,     0,
       0,   452,    15,    16,     0,   452,     0,     0,     0,     0,
       0,     0,   398,     0,     0,     0,     0,     0,   452,     0,
     452,     0,     0,     0,   452,   449,     0,   449,   449,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     398,     0,     3,     0,     0,   107,     0,     4,    17,   108,
       0,     0,     6,     0,     0,   449,     0,   449,   449,   449,
     109,   110,   449,   111,     8,     0,    10,   456,   449,     0,
     112,    12,     0,     0,   113,     0,     0,     0,     0,     0,
     456,     0,     0,   449,     0,    14,     0,   456,     0,   407,
     449,     0,   449,   449,     0,     0,     0,     0,     0,     0,
       0,   449,     0,   449,   449,     0,   449,     0,   449,     0,
       0,     0,   449,     0,   449,   449,     0,     0,     0,     0,
     449,     0,   452,     0,     0,   452,     0,     0,   452,     0,
     458,     0,   691,     0,     0,     0,     0,   456,   457,     0,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
     454,   457,     0,     0,   454,     0,     0,     0,   457,     0,
       0,     0,     0,     0,     0,     0,     0,   454,     1,   454,
     452,   452,   452,   454,   407,     0,     0,     0,     0,     0,
     458,     3,   452,   452,     0,   452,     4,   452,     0,     0,
       5,     6,     0,     0,     7,     0,     0,     0,     0,     0,
       0,     0,   407,     8,     9,    10,     0,    11,   457,     0,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   455,     0,     0,    14,   455,     0,   452,     0,   452,
     452,    16,     0,     0,     0,     0,     0,     0,   455,     0,
     455,     0,     0,     0,   455,     0,     0,     0,     0,     0,
     458,     0,     0,     0,     0,     0,     0,   452,     0,   452,
     452,   452,     0,     0,   452,     0,     0,     0,     0,     0,
     452,   454,     0,     0,   454,     0,    17,   454,     0,     0,
       0,     0,     0,     0,     0,   452,     0,     0,     0,     0,
       0,     0,   452,     0,   452,   452,     0,     0,     0,     0,
       0,     0,     0,   452,     0,   452,   452,     0,   452,     0,
     452,     0,     0,     0,   452,     0,   452,   452,     0,   454,
     454,   454,   452,     0,     0,   203,     0,     0,     0,     0,
     207,   454,   454,     0,   454,     0,   454,     0,     0,     0,
       0,     0,   455,     0,     0,   455,     0,     0,   455,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   454,     0,   454,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     455,   455,   455,     0,     0,     0,     0,   456,     0,     0,
       0,   456,   455,   455,   458,   455,   454,   455,   454,   454,
     454,     0,     0,   454,   456,     0,   456,   458,     0,   454,
     456,     0,     0,     0,   458,     0,     0,     0,     0,     0,
       0,   203,     0,     0,   454,     0,     0,     0,     0,     0,
       0,   454,     0,   454,   454,     0,     0,   455,     0,   455,
     455,     0,   454,     0,   454,   454,     0,   454,     0,   454,
       0,   203,     0,   454,     0,   454,   454,     0,   457,     0,
       0,   454,   457,     0,   458,     0,     0,   455,     0,   455,
     455,   455,     0,     0,   455,   457,     0,   457,     0,     0,
     455,   457,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,     0,     0,     0,     0,
       0,     0,   455,     0,   455,   455,     0,     0,   456,     0,
       0,   456,     0,   455,   456,   455,   455,     0,   455,     0,
     455,     0,     0,     0,   455,     0,   455,   455,     0,     0,
       0,     0,   455,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   456,   456,   456,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   456,   456,
       0,   456,     0,   456,     0,     0,     0,     0,     0,   457,
       0,     0,   457,     0,     0,   457,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   642,     0,     0,     0,   207,     0,     0,     0,
       0,     0,     0,   456,     0,   456,   456,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   457,   457,   457,
       0,     0,   258,     0,     0,     0,     0,     0,     0,   457,
     457,     0,   457,   456,   457,   456,   456,   456,     0,     0,
     456,     0,     0,   293,     0,     0,   456,   300,     0,     0,
     304,     0,   306,     0,     0,     0,     0,   203,     0,     0,
     687,   456,     0,     0,   328,     0,     0,     0,   456,     0,
     456,   456,     0,     0,   457,     0,   457,   457,     0,   456,
       0,   456,   456,     0,   456,     0,   456,     0,     0,     0,
     456,   207,   456,   456,     0,     0,     0,     0,   456,     0,
       0,     0,     0,     0,   457,     0,   457,   457,   457,     0,
       0,   457,     0,     0,   458,     0,     0,   457,   458,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   458,   457,   458,     0,   530,   531,   458,     0,   457,
       0,   457,   457,     0,     0,     0,     0,     0,     0,     0,
     457,     0,   457,   457,     0,   457,     0,   457,     0,     0,
       0,   457,     0,   457,   457,     0,     0,     0,     0,   457,
     547,     0,     0,   551,     0,   553,     0,   554,     0,   556,
       0,   557,     0,     0,     0,     0,   610,     0,     0,     0,
       0,     0,   617,   619,     0,   789,   793,     0,     0,     0,
       0,     0,     0,     0,     0,   585,     0,     0,     0,   592,
       0,     0,   596,   624,   598,     0,   642,     0,     0,     0,
       0,     0,     0,   631,     0,     0,   627,   627,     0,     0,
       0,     0,     1,     0,     0,   458,     0,     0,   458,     0,
     687,   458,   106,     0,     0,     3,   628,   628,   107,     0,
       4,     0,   108,     0,     0,     6,     0,     0,     0,     0,
       0,     0,     0,   109,   110,     0,   111,     8,     0,    10,
       0,     0,     0,   112,    12,     0,     0,   113,     0,     0,
       0,   889,     0,   458,   458,   458,     0,     0,    14,     0,
       0,     0,     0,   642,     0,   458,   458,     0,   458,     0,
     458,     0,     0,     0,   207,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   631,   627,   627,
     627,   627,     0,     0,     0,   867,     0,     0,     0,     0,
     458,     0,   458,   458,     0,     0,    41,     0,   628,   628,
     628,   628,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     458,     0,   458,   458,   458,     0,     0,   458,     0,     0,
       0,   956,     0,   458,   959,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   458,     0,
       0,     0,     0,     0,     0,   458,     0,   458,   458,     0,
       0,     0,     0,     0,     0,     0,   458,     0,   458,   458,
       0,   458,     0,   458,   745,     0,   747,   458,   748,   458,
     458,   749,     0,     0,     0,   458,     0,   642,   796,     0,
     799,   800,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   808,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   774,     0,   813,   778,     0,   780,   822,   781,
       0,   783,     0,   784,     0,     0,     0,     0,     0,     0,
    1016,     0,   687,  1018,   843,     0,     0,     0,     0,     0,
     852,   863,     0,     0,     0,   864,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   106,     0,
     628,     3,     0,   203,   107,   207,     4,     0,   108,   888,
       0,     6,     0,     0,     0,     0,     0,     0,     0,   109,
     110,     0,   111,     8,     0,    10,     0,   905,     0,   112,
      12,     0,     0,   113,     0,     0,   909,     0,     0,   911,
       0,     0,     0,     0,    14,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,     0,   627,   627,   627,
     627,   627,   627,   627,   627,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,     0,   628,   628,   628,
     628,   628,   628,   628,   628,     0,     0,     0,     1,     0,
       0,   881,     0,     0,     0,     0,     0,  1107,   106,     0,
       0,     3,    41,     0,   107,     0,     4,   954,   108,     0,
       0,     6,   936,     0,     7,     0,   963,     0,     0,   109,
     110,     0,   111,     8,     9,   214,   215,    11,     0,   112,
      12,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,   949,     0,   951,    14,   952,     0,     0,   953,     1,
       0,    16,     0,     0,     0,   982,     0,     0,     0,   106,
       0,     0,     3,    64,     0,   107,     0,     4,   852,   108,
       0,     0,     6,     0,     0,     0,     0,     0,     0,     0,
     109,   110,     0,   111,     8,     0,    10,     0,   628,     0,
     112,    12,   216,   217,   113,     0,   218,     0,     0,     0,
       0,     0,    41,     1,   888,    14,     0,     0,     0,     0,
       0,     0,     0,   106,     0,     0,     3,     0,     0,   107,
       0,     4,     0,   108,     0,     0,     6,     0,     0,    56,
     627,   627,     0,     0,   109,   110,     0,   111,     8,    57,
      10,   215,    58,     0,   112,    12,     0,     0,   113,     0,
     628,   628,   890,     0,     0,     0,     0,     0,     0,    14,
       0,     0,     0,    41,     0,     0,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,    64,     0,
     355,     0,     0,     0,     0,  1073,     0,   106,     0,     0,
       3,   361,     0,   107,     0,     4,     0,   108,     0,     0,
       6,     0,     0,     0,     0,  1092,     0,     0,   109,   110,
       0,   111,     8,     0,    10,   366,  1052,    41,   112,    12,
       0,     0,   113,     0,   367,     0,  1054,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     493,   383,     0,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,     0,     0,     0,   627,   627,     0,     0,
       0,     0,     0,     0,   392,   393,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,   628,   628,     0,   394,
     106,     0,     0,     3,     0,   836,   107,     0,     4,     0,
     108,   397,     0,     6,     0,     0,     7,     0,     0,     0,
       0,   109,   110,     0,   111,     8,     9,   214,   215,    11,
       0,   112,    12,     0,     0,   113,     0,     0,     0,     0,
       0,  1128,   888,     0,     0,     0,    14,     0,     0,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    64,     0,     0,     0,     0,
    1176,  1177,     0,     0,     0,  1182,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   216,   291,     0,     0,   218,     0,
       0,     0,     0,     0,    41,     0,     0,     1,     0,     0,
       0,     0,   627,     0,     0,     0,     0,   106,     0,  1225,
       3,     0,     0,   107,     0,     4,     0,   108,     0,     0,
       6,     0,   628,    56,     0,     0,     0,     0,   109,   110,
       0,   111,     8,    57,    10,     0,    58,     0,   112,    12,
       0,     0,   113,     0,     0,     0,     0,     0,     0,     0,
    1252,     0,     0,    14,   632,  1259,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,     0,     1,   353,   354,
     355,   356,   357,  1167,   358,   627,   359,   106,   360,     0,
       3,   361,   362,   107,     0,     4,   363,   108,     0,     0,
       6,     0,  1168,     7,   364,   628,     0,     0,   109,   110,
     365,   111,     8,     9,    10,   366,    11,     0,   112,    12,
       0,    41,   113,     0,   367,   368,     0,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   392,   393,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   394,
       0,     0,     0,     0,     0,   396,     0,     0,     0,     0,
       0,   397,     1,   353,   354,   355,   356,   357,     0,   358,
       0,   359,   106,   360,     0,     3,   361,   362,   107,     0,
       4,   363,   108,     0,     0,     6,     0,     0,     7,   364,
       0,     0,     0,   109,   110,   365,   111,     8,     9,    10,
     366,    11,     0,   112,    12,     0,     0,   113,     0,   367,
     368,     0,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   392,
     393,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   394,     0,     0,   395,     0,     0,
     396,     0,     0,     0,     0,     0,   397,     1,   353,   354,
     355,   356,   357,     0,   358,     0,   359,   106,   360,     0,
       3,   361,   362,   107,     0,     4,   363,   108,     0,     0,
       6,     0,     0,     7,   364,     0,     0,     0,   109,   110,
     365,   111,     8,     9,    10,   366,    11,     0,   112,    12,
       0,     0,   113,     0,   367,   368,     0,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   392,   393,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   394,
       0,  -496,     0,     0,     0,   396,     0,     0,     0,     0,
       0,   397,     1,   353,   354,   355,   356,   357,     0,   358,
       0,   359,   106,   360,     0,     3,   699,   362,   107,     0,
       4,   363,   108,     0,     0,     6,     0,     0,     7,   364,
       0,     0,     0,   109,   110,   365,   111,     8,     9,    10,
     366,    11,     0,   112,    12,     0,     0,   113,     0,   700,
     368,     0,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   392,
     393,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   394,     0,     0,   701,     0,     0,
     396,     0,     0,     0,     0,     0,   397,     1,   353,   354,
     355,   356,   357,     0,   358,     0,   359,   106,   360,     0,
       3,   361,   362,   107,     0,     4,   363,   108,     0,     0,
       6,     0,     0,     7,   364,     0,     0,     0,   109,   110,
     365,   111,     8,     9,    10,   366,    11,     0,   112,    12,
       0,     0,   113,     0,   367,   368,     0,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,   355,     0,     0,   392,   393,     0,     0,   106,     0,
       0,     3,   361,     0,   107,     0,     4,     0,   108,   394,
       0,     6,   901,     0,     0,   396,     0,     0,     0,   109,
     110,   397,   111,     8,     0,    10,   366,     0,     0,   112,
      12,     0,     0,   113,     0,   367,     0,     0,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   493,   383,     0,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,   355,     0,     0,   392,   393,     0,     0,   106,
       0,     0,     3,   361,     0,   107,     0,     4,     0,   108,
     394,     0,     6,     0,     0,     0,  1180,     0,     0,     0,
     109,   110,   397,   111,     8,     0,    10,   366,     0,     0,
     112,    12,     0,     0,   113,     0,   367,     0,     0,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   493,   383,     0,   385,   386,   387,   388,   389,
     390,   391,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,     0,     0,     3,     0,     0,   107,
       0,     4,     0,   108,     0,     0,     6,     0,     0,     7,
       0,   394,     0,     0,   109,   110,     0,   111,     8,     9,
     214,   215,    11,   397,   112,    12,     0,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,    14,
       0,     0,     0,     0,     0,     0,    16,   106,     0,     0,
       3,     0,     0,   107,     0,     4,     0,   108,    64,     0,
       6,     0,     0,     7,     0,     0,     0,     0,   109,   110,
       0,   111,     8,     9,   214,   215,    11,     0,   112,    12,
       0,     0,   113,     0,     0,     0,     0,   216,   463,     0,
       0,   218,     0,    14,     0,     0,     0,    41,     1,     0,
      16,     0,     0,     0,     0,     0,     0,     0,   106,     0,
       0,     3,    64,     0,   107,     0,     4,     0,   108,     0,
       0,     6,     0,     0,     7,     0,     0,     0,     0,   109,
     110,     0,   111,     8,     9,   214,   215,    11,     0,   112,
      12,   216,   546,   113,     0,   218,     0,     0,     0,     0,
       0,    41,     1,     0,    14,     0,     0,     0,     0,     0,
       0,    16,   106,     0,     0,     3,     0,     0,   107,     0,
       4,     0,   108,    64,     0,     6,     0,     0,     7,     0,
       0,     0,     0,   109,   110,     0,   111,     8,     9,    10,
     215,    11,     0,   112,    12,     0,     0,   113,     0,     0,
       1,     0,   216,     0,     0,     0,   218,     0,    14,     0,
     106,     0,    41,     3,     0,    16,   107,     0,     4,     0,
     108,     0,     0,     6,     0,     0,     7,    64,     0,     0,
       0,   109,   110,     0,   111,     8,     9,    10,   215,    11,
       0,   112,    12,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,    14,   274,     0,     0,
     275,     0,     0,    16,   106,     0,    41,     3,     0,     0,
     107,     0,     4,     0,   108,    64,     0,     6,     0,     0,
       0,     0,     0,     0,     1,   109,   110,     0,   111,     8,
       0,    10,     0,     0,   106,   112,    12,     3,     0,   113,
     107,     0,     4,     0,   108,   541,     0,     6,   275,     0,
      14,   632,     0,     0,    41,   109,   110,     0,   111,     8,
       0,    10,     0,     0,     0,   112,    12,     0,     1,   113,
       0,     0,     0,     0,     0,     0,     0,     0,   106,     0,
      14,     3,     0,     0,   107,     0,     4,     0,   108,     0,
       0,     6,     0,     0,     0,     0,     0,     0,     0,   109,
     110,     0,   111,     8,     0,    10,     0,     0,    41,   112,
      12,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,  1009,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,   353,
     354,   355,   356,   357,     0,   358,     0,   359,   106,   360,
       0,     0,   361,   362,   107,     0,     0,   363,   108,     0,
       0,     0,     0,     0,     0,   364,     0,     0,     0,   109,
     110,   365,   111,     0,     0,     0,   366,     0,     0,   112,
       0,     0,    41,   113,     0,   367,   368,     0,   369,   370,
     371,   372,   373,   374,   491,   492,   377,   378,   379,   380,
     381,   493,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   392,   393,     0,     0,   353,
     354,   355,   356,   357,     0,  1058,     0,   359,   106,   360,
     394,     0,   361,   362,   107,     0,   396,   363,   108,     0,
       0,     0,   397,     0,     0,   364,     0,     0,     0,   109,
     110,   365,   111,     0,     0,     0,   366,     0,     0,   112,
       0,     0,     0,   113,     0,   367,  1059,     0,   369,   370,
     371,   372,   373,   374,   491,   492,   377,   378,   379,   380,
     381,   493,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,     0,   355,   490,     0,     0,
       0,     0,     0,   106,     0,   392,   393,   361,     0,   107,
       0,     0,     0,   108,     0,     0,     0,     0,     0,     0,
     394,     0,     0,     0,   109,   110,   396,   111,     0,     0,
       0,   366,   397,     0,   112,     0,     0,     0,   113,     0,
     367,     0,     0,   369,   370,   371,   372,   373,   374,   491,
     492,   377,   378,   379,   380,   381,   493,   383,     0,   385,
     386,   387,   388,   389,   390,   391,     0,     0,     0,   494,
     495,     0,     0,     0,     0,     0,     0,   355,   490,     0,
     392,   393,   496,   497,   106,     0,     0,     0,   361,     0,
     107,     0,     0,   363,   108,   498,     0,   885,  1012,     0,
       0,     0,  1013,     0,     0,   109,   110,   397,   111,     0,
       0,     0,   366,     0,     0,   112,     0,     0,     0,   113,
       0,   367,     0,     0,   369,   370,   371,   372,   373,   374,
     491,   492,   377,   378,   379,   380,   381,   493,   383,     0,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
     494,   495,     0,     0,     0,     0,     0,     0,   355,   490,
       0,   392,   393,   496,   497,   106,     0,     0,     0,   361,
       0,   107,     0,     0,     0,   108,   498,     0,   216,     0,
       0,     0,     0,     0,     0,     0,   109,   110,   397,   111,
       0,     0,     0,   366,     0,     0,   112,     0,     0,     0,
     113,     0,   367,     0,     0,   369,   370,   371,   372,   373,
     374,   491,   492,   377,   378,   379,   380,   381,   493,   383,
       0,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,   494,   495,     0,     0,     0,     0,     0,     0,   355,
     490,     0,   392,   393,   496,   497,   106,     0,     0,     0,
     361,     0,   107,     0,     0,     0,   108,   498,   499,     0,
       0,     0,     0,     0,     0,     0,     0,   109,   110,   397,
     111,     0,     0,     0,   366,     0,     0,   112,     0,     0,
       0,   113,     0,   367,     0,     0,   369,   370,   371,   372,
     373,   374,   491,   492,   377,   378,   379,   380,   381,   493,
     383,     0,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,   494,   495,     0,     0,     0,     0,     0,     0,
     355,   490,     0,   392,   393,   496,   497,   106,     0,     0,
       0,   361,     0,   107,     0,     0,     0,   108,   498,     0,
       0,     0,     0,     0,   618,     0,     0,     0,   109,   110,
     397,   111,     0,     0,     0,   366,     0,     0,   112,     0,
       0,     0,   113,     0,   367,     0,     0,   369,   370,   371,
     372,   373,   374,   491,   492,   377,   378,   379,   380,   381,
     493,   383,     0,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,   494,   495,     0,     0,     0,     0,     0,
       0,   355,   490,     0,   392,   393,   496,   497,   106,     0,
       0,     0,   361,     0,   107,     0,     0,     0,   108,   498,
       0,     0,     0,     0,   345,     0,     0,     0,     0,   109,
     110,   397,   111,     0,     0,     0,   366,     0,     0,   112,
       0,     0,     0,   113,     0,   367,     0,     0,   369,   370,
     371,   372,   373,   374,   491,   492,   377,   378,   379,   380,
     381,   493,   383,     0,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,   494,   495,     0,     0,     0,     0,
       0,     0,   355,   490,     0,   392,   393,   496,   497,   106,
       0,     0,     0,   361,     0,   107,     0,     0,     0,   108,
     498,   830,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   397,   111,     0,     0,     0,   366,     0,     0,
     112,     0,     0,     0,   113,     0,   367,     0,     0,   369,
     370,   371,   372,   373,   374,   491,   492,   377,   378,   379,
     380,   381,   493,   383,     0,   385,   386,   387,   388,   389,
     390,   391,     0,     0,     0,   494,   495,     0,     0,     0,
       0,     0,     0,   355,   490,     0,   392,   393,   496,   497,
     106,     0,     0,     0,   361,     0,   107,     0,     0,     0,
     108,   498,     0,   885,     0,     0,     0,     0,     0,     0,
       0,   109,   110,   397,   111,     0,     0,     0,   366,     0,
       0,   112,     0,     0,     0,   113,     0,   367,     0,     0,
     369,   370,   371,   372,   373,   374,   491,   492,   377,   378,
     379,   380,   381,   493,   383,     0,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,   494,   495,     0,     0,
       0,     0,     0,     0,   355,   490,     0,   392,   393,   496,
     497,   106,     0,     0,     0,   361,     0,   107,     0,     0,
       0,   108,   498,   960,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   110,   397,   111,     0,     0,     0,   366,
       0,     0,   112,     0,     0,     0,   113,     0,   367,     0,
       0,   369,   370,   371,   372,   373,   374,   491,   492,   377,
     378,   379,   380,   381,   493,   383,     0,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,   494,   495,     0,
       0,     0,     0,     0,     0,   355,   490,     0,   392,   393,
     496,   497,   106,     0,     0,     0,   361,     0,   107,     0,
       0,     0,   108,   498,     0,     0,     0,     0,     0,   981,
       0,     0,     0,   109,   110,   397,   111,     0,     0,     0,
     366,     0,     0,   112,     0,     0,     0,   113,     0,   367,
       0,     0,   369,   370,   371,   372,   373,   374,   491,   492,
     377,   378,   379,   380,   381,   493,   383,     0,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,   494,   495,
       0,     0,     0,     0,     0,     0,   355,   490,     0,   392,
     393,   496,   497,   106,     0,     0,     0,   361,     0,   107,
       0,     0,     0,   108,   498,  1021,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,   397,   111,     0,     0,
       0,   366,     0,     0,   112,     0,     0,     0,   113,     0,
     367,     0,     0,   369,   370,   371,   372,   373,   374,   491,
     492,   377,   378,   379,   380,   381,   493,   383,     0,   385,
     386,   387,   388,   389,   390,   391,     0,     0,     0,   494,
     495,     0,     0,     0,     0,     0,     0,   355,   490,     0,
     392,   393,   496,   497,   106,     0,     0,     0,   361,     0,
     107,     0,     0,     0,   108,   498,  1023,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,   397,   111,     0,
       0,     0,   366,     0,     0,   112,     0,     0,     0,   113,
       0,   367,     0,     0,   369,   370,   371,   372,   373,   374,
     491,   492,   377,   378,   379,   380,   381,   493,   383,     0,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
     494,   495,     0,     0,     0,     0,     0,     0,   355,   490,
       0,   392,   393,   496,   497,   106,     0,     0,     0,   361,
       0,   107,     0,     0,     0,   108,   498,  1074,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   110,   397,   111,
       0,     0,     0,   366,     0,     0,   112,     0,     0,     0,
     113,     0,   367,     0,     0,   369,   370,   371,   372,   373,
     374,   491,   492,   377,   378,   379,   380,   381,   493,   383,
       0,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,   494,   495,     0,     0,     0,     0,     0,     0,   355,
     490,     0,   392,   393,   496,   497,   106,     0,     0,     0,
     361,     0,   107,     0,     0,     0,   108,   498,  1079,     0,
       0,     0,     0,     0,     0,     0,     0,   109,   110,   397,
     111,     0,     0,     0,   366,     0,     0,   112,     0,     0,
       0,   113,     0,   367,     0,     0,   369,   370,   371,   372,
     373,   374,   491,   492,   377,   378,   379,   380,   381,   493,
     383,     0,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,   494,   495,     0,     0,     0,     0,     0,     0,
     355,   490,     0,   392,   393,   496,   497,   106,     0,     0,
       0,   361,     0,   107,     0,     0,     0,   108,   498,  1083,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     397,   111,     0,     0,     0,   366,     0,     0,   112,     0,
       0,     0,   113,     0,   367,     0,     0,   369,   370,   371,
     372,   373,   374,   491,   492,   377,   378,   379,   380,   381,
     493,   383,     0,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,   494,   495,     0,     0,     0,     0,     0,
       0,   355,   490,     0,   392,   393,   496,   497,   106,     0,
       0,     0,   361,     0,   107,     0,     0,     0,   108,   498,
       0,     0,     0,     0,     0,  1091,     0,     0,     0,   109,
     110,   397,   111,     0,     0,     0,   366,     0,     0,   112,
       0,     0,     0,   113,     0,   367,     0,     0,   369,   370,
     371,   372,   373,   374,   491,   492,   377,   378,   379,   380,
     381,   493,   383,     0,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,   494,   495,     0,     0,     0,     0,
       0,     0,   355,   490,     0,   392,   393,   496,   497,   106,
       0,     0,     0,   361,     0,   107,     0,     0,     0,   108,
     498,  1098,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   397,   111,     0,     0,     0,   366,     0,     0,
     112,     0,     0,     0,   113,     0,   367,     0,     0,   369,
     370,   371,   372,   373,   374,   491,   492,   377,   378,   379,
     380,   381,   493,   383,     0,   385,   386,   387,   388,   389,
     390,   391,     0,     0,     0,   494,   495,     0,     0,     0,
       0,     0,     0,   355,   490,     0,   392,   393,   496,   497,
     106,     0,     0,     0,   361,     0,   107,     0,     0,     0,
     108,   498,  1160,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   110,   397,   111,     0,     0,     0,   366,     0,
       0,   112,     0,     0,     0,   113,     0,   367,     0,     0,
     369,   370,   371,   372,   373,   374,   491,   492,   377,   378,
     379,   380,   381,   493,   383,     0,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,   494,   495,     0,     0,
       0,     0,     0,     0,   355,   490,     0,   392,   393,   496,
     497,   106,     0,     0,     0,   361,     0,   107,     0,     0,
       0,   108,   498,  1162,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   110,   397,   111,     0,     0,     0,   366,
       0,     0,   112,     0,     0,     0,   113,     0,   367,     0,
       0,   369,   370,   371,   372,   373,   374,   491,   492,   377,
     378,   379,   380,   381,   493,   383,     0,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,   494,   495,     0,
       0,     0,     0,     0,     0,   355,   490,     0,   392,   393,
     496,   497,   106,     0,     0,     0,   361,     0,   107,     0,
       0,     0,   108,   498,  1164,     0,     0,     0,     0,     0,
       0,     0,     0,   109,   110,   397,   111,     0,     0,     0,
     366,     0,     0,   112,     0,     0,     0,   113,     0,   367,
       0,     0,   369,   370,   371,   372,   373,   374,   491,   492,
     377,   378,   379,   380,   381,   493,   383,     0,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,   494,   495,
       0,     0,     0,     0,     0,     0,   355,   490,     0,   392,
     393,   496,   497,   106,     0,     0,     0,   361,     0,   107,
       0,     0,     0,   108,   498,  1184,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,   397,   111,     0,     0,
       0,   366,     0,     0,   112,     0,     0,     0,   113,     0,
     367,     0,     0,   369,   370,   371,   372,   373,   374,   491,
     492,   377,   378,   379,   380,   381,   493,   383,     0,   385,
     386,   387,   388,   389,   390,   391,     0,     0,     0,   494,
     495,     0,     0,     0,     0,     0,     0,   355,   490,     0,
     392,   393,   496,   497,   106,     0,     0,     0,   361,     0,
     107,     0,     0,     0,   108,   498,  1186,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,   397,   111,     0,
       0,     0,   366,     0,     0,   112,     0,     0,     0,   113,
       0,   367,     0,     0,   369,   370,   371,   372,   373,   374,
     491,   492,   377,   378,   379,   380,   381,   493,   383,     0,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
     494,   495,     0,     0,     0,     0,     0,     0,   355,   490,
       0,   392,   393,   496,   497,   106,     0,     0,     0,   361,
       0,   107,     0,     0,     0,   108,   498,     0,     0,     0,
       0,     0,  1224,     0,     0,     0,   109,   110,   397,   111,
       0,     0,     0,   366,     0,     0,   112,     0,     0,     0,
     113,     0,   367,     0,     0,   369,   370,   371,   372,   373,
     374,   491,   492,   377,   378,   379,   380,   381,   493,   383,
       0,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,   494,   495,     0,     0,     0,     0,     0,     0,   355,
     490,     0,   392,   393,   496,   497,   106,     0,     0,     0,
     361,     0,   107,     0,     0,     0,   108,   498,     0,     0,
       0,     0,     0,  1258,     0,     0,     0,   109,   110,   397,
     111,     0,     0,     0,   366,     0,     0,   112,     0,     0,
       0,   113,     0,   367,     0,     0,   369,   370,   371,   372,
     373,   374,   491,   492,   377,   378,   379,   380,   381,   493,
     383,     0,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,   494,   495,     0,     0,     0,     0,     0,     0,
     355,   490,     0,   392,   393,   496,   497,   106,     0,     0,
       0,   361,     0,   107,     0,     0,     0,   108,   498,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     397,   111,     0,     0,     0,   366,     0,     0,   112,     0,
       0,     0,   113,     0,   367,     0,     0,   369,   370,   371,
     372,   373,   374,   491,   492,   377,   378,   379,   380,   381,
     493,   383,     0,   385,   386,   387,   388,   389,   390,   391,
       0,     0,   355,   494,   495,     0,     0,     0,     0,   106,
       0,     0,     0,   361,     0,   107,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   498,
     109,   110,     0,   111,     0,     0,     0,   366,     0,     0,
     112,   397,     0,     0,   113,     0,   367,     0,     0,   369,
     370,   371,   372,   373,   374,   491,   492,   377,   378,   379,
     380,   381,   493,   383,     0,   385,   386,   387,   388,   389,
     390,   391,     0,     0,     0,     0,     0,   355,     0,     0,
       0,     0,     0,     0,   106,     0,   392,   393,   361,     0,
     107,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,   394,  1085,     0,     0,   109,   110,     0,   111,     0,
       0,     0,   366,   397,     0,   112,     0,     0,     0,   113,
       0,   367,     0,     0,   369,   370,   371,   372,   373,   374,
     491,   492,   377,   378,   379,   380,   381,   493,   383,     0,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,     0,   106,
       0,   392,   393,   361,     0,   107,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,   394,  1146,     0,     0,
     109,   110,     0,   111,     0,     0,     0,   366,   397,     0,
     112,     0,     0,     0,   113,     0,   367,     0,     0,   369,
     370,   371,   372,   373,   374,   491,   492,   377,   378,   379,
     380,   381,   493,   383,     0,   385,   386,   387,   388,   389,
     390,   391,     0,     0,     0,     0,     0,   355,     0,     0,
       0,     0,     0,     0,   106,     0,   392,   393,   361,     0,
     107,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,   394,  1148,     0,     0,   109,   110,     0,   111,     0,
       0,     0,   366,   397,     0,   112,     0,     0,     0,   113,
       0,   367,     0,     0,   369,   370,   371,   372,   373,   374,
     491,   492,   377,   378,   379,   380,   381,   493,   383,     0,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,     0,   106,
       0,   392,   393,   361,     0,   107,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,   394,  1193,     0,     0,
     109,   110,     0,   111,     0,     0,     0,   366,   397,     0,
     112,     0,     0,     0,   113,     0,   367,     0,     0,   369,
     370,   371,   372,   373,   374,   491,   492,   377,   378,   379,
     380,   381,   493,   383,     0,   385,   386,   387,   388,   389,
     390,   391,     0,     0,     0,     0,     0,   355,     0,     0,
       0,     0,     0,     0,   106,     0,   392,   393,   361,     0,
     107,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,   394,  1255,     0,     0,   109,   110,     0,   111,     0,
       0,     0,   366,   397,     0,   112,     0,     0,     0,   113,
       0,   367,     0,     0,   369,   370,   371,   372,   373,   374,
     491,   492,   377,   378,   379,   380,   381,   493,   383,     0,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,     0,   106,
       0,   392,   393,   361,     0,   107,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,   394,  1269,     0,     0,
     109,   110,     0,   111,     0,     0,     0,   366,   397,     0,
     112,     0,     0,     0,   113,     0,   367,     0,     0,   369,
     370,   371,   372,   373,   374,   491,   492,   377,   378,   379,
     380,   381,   493,   383,     0,   385,   386,   387,   388,   389,
     390,   391,     0,     0,     0,     0,     0,   355,     0,     0,
       0,     0,     0,     0,   106,     0,   392,   393,   361,     0,
     107,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,   394,  1271,     0,     0,   109,   110,     0,   111,     0,
       0,     0,   366,   397,     0,   112,     0,     0,     0,   113,
       0,   367,     0,     0,   369,   370,   371,   372,   373,   374,
     491,   492,   377,   378,   379,   380,   381,   493,   383,     0,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,     0,   106,
       0,   392,   393,   361,     0,   107,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,   394,  1280,     0,     0,
     109,   110,     0,   111,     0,     0,     0,   366,   397,     0,
     112,     0,     0,     0,   113,     0,   367,     0,     0,   369,
     370,   371,   372,   373,   374,   491,   492,   377,   378,   379,
     380,   381,   493,   383,     0,   385,   386,   387,   388,   389,
     390,   391,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   392,   393,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   394,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   397
};

static const yytype_int16 yycheck[] =
{
       2,   654,   398,     5,   480,     7,   480,     9,   216,    11,
     654,    13,   656,   126,    16,   268,   214,    20,   601,   163,
     164,  1033,   410,   203,   236,   885,   280,   207,   679,   142,
     316,   229,   318,   907,   310,   142,   289,   290,   857,   477,
     223,    43,   693,   313,   157,   562,   654,   157,    50,   636,
       6,     6,   165,   640,    56,    57,    58,   281,   165,    20,
      20,  1170,    64,    65,   477,    17,     6,    69,   392,   393,
      18,    40,    74,   660,    76,    77,    78,    25,  1173,    81,
      82,    79,    20,   281,     6,    87,    88,   154,   117,   461,
      36,   219,   159,     9,   161,    17,   279,     0,     5,    97,
     643,    47,    48,   216,    82,    64,   478,   220,    83,   219,
      50,  1220,    28,    59,    62,     6,   856,   119,   185,   859,
      42,   249,  1217,    98,   126,    57,    17,    17,    50,   131,
     132,    64,   134,   111,    18,  1171,    43,   250,    65,   249,
     142,    90,   144,   250,    33,    20,   107,   107,   117,   113,
      99,    42,    98,    99,   113,   157,  1168,     6,  1032,    50,
     414,   117,   117,   165,   277,   117,   276,   277,    17,    58,
     494,   495,   496,   497,  1210,    82,   995,   117,    62,   292,
     113,    88,   656,    58,   182,   292,   106,     6,    90,    91,
      92,   111,   108,    42,   196,   117,   198,    99,    17,   126,
     844,    50,   410,   205,   271,   459,   273,   209,   101,   184,
     105,   157,  1248,   215,   216,   142,   219,   219,   220,   417,
     287,   223,   873,    42,   114,   227,   117,   117,   704,  1241,
     157,    50,   125,   750,   127,   752,   460,   754,   165,   756,
     189,   439,   107,  1103,   246,   683,   249,   249,   250,   461,
     462,    19,   795,  1088,   321,    27,  1091,   997,   325,   647,
     327,   674,   460,   265,   266,   267,   168,   169,   117,   481,
     172,   684,   480,   276,   276,   277,   107,   279,   280,   692,
     111,   219,   209,     9,    52,   539,   562,   189,   190,   191,
     292,   577,   219,   220,   107,    63,   223,   410,   117,     9,
     193,   194,    28,   573,    94,   575,   308,   309,   310,   311,
     312,   249,   899,   900,   686,  1150,   540,   904,    28,   212,
       9,     9,   249,   250,    94,   908,     9,   117,    63,    42,
     276,   277,   107,  1129,   102,   107,    49,    78,   276,    28,
      28,    83,   540,    85,    63,    28,    94,   117,    20,   276,
     277,   353,   279,   355,   897,   898,    98,    32,   360,   266,
     362,    33,    33,    58,   105,   292,   111,   480,    43,   117,
     844,    20,   117,   981,  1170,   983,   111,  1173,   113,   633,
     382,   109,   108,    96,    33,   113,    58,    58,   116,  1224,
     392,   393,   111,   295,   113,   398,   398,    63,   108,   103,
     104,   308,   309,    63,   311,   312,    78,    78,   410,    58,
      94,    59,   414,   155,   738,   739,   740,    96,    66,   108,
     108,  1217,  1257,  1258,   967,   108,    96,   106,   330,   331,
     973,   108,   334,   117,   126,   978,   106,   116,  1273,   647,
      81,   837,   184,    58,   186,   111,   339,   113,    89,   106,
     142,   111,   100,   113,   111,   112,   999,   459,   638,   671,
     398,   659,   642,   465,   466,   157,   468,   880,   105,   114,
     537,   113,   117,   165,   116,   477,   113,   479,   480,   116,
    1088,    33,  1135,  1091,   105,   392,   393,     3,   109,    77,
      78,  1135,   494,   495,   496,   497,   704,    85,    86,   769,
      16,  1036,   112,  1154,  1039,    21,  1041,   687,  1043,   105,
      26,    77,   579,   107,   581,   105,   583,   113,  1035,   113,
     116,   106,    38,   113,    40,   107,   116,  1135,   220,    45,
     118,   113,   112,   113,   647,   103,   104,   539,   465,   466,
     107,   109,  1150,    59,  1195,   113,   113,   111,   116,   113,
     477,   107,    53,    54,    55,    56,    65,   113,   250,   109,
     562,    62,   106,    53,    54,    55,    56,   111,   112,  1112,
    1113,  1114,    62,   480,   108,   111,   360,   111,   112,   112,
     322,   117,   906,   117,   111,   277,   113,   494,   495,   496,
     497,   704,   105,   111,   107,   113,   109,  1140,   600,  1142,
     292,   117,    53,    54,    55,    56,   109,   108,   105,   789,
     113,    62,   109,   793,   103,   104,  1224,   126,   108,   621,
     622,    90,    91,   728,   729,   730,   731,    53,    54,    55,
      56,   633,   634,   142,   636,   637,    62,   105,   640,   641,
     109,   109,   107,   645,   113,   647,   216,   116,   157,  1257,
    1258,   109,   654,   112,   656,   113,   165,   108,   660,   661,
      53,    54,    55,    56,   109,  1273,   112,   113,   113,    62,
      90,    91,   674,   675,   109,   678,   678,   679,   113,   109,
     109,   683,   684,   113,   113,   587,   116,   689,   143,   109,
     692,   693,   147,   113,    94,    95,   116,   117,   111,    99,
     209,   789,   704,   108,   771,   793,   111,   216,   111,   889,
     219,   220,   108,   108,   223,   108,   111,   103,   104,   721,
     722,   723,   724,   725,   726,   727,   728,   729,   730,   731,
     732,   733,   734,   735,   736,   737,   738,   739,   740,   113,
     249,   250,   116,   105,  1220,   107,   964,   674,   750,   656,
     752,   678,   754,   111,   756,   113,   683,   684,   126,   761,
     112,    84,   764,   765,    87,   692,   114,   276,   277,   117,
     279,   111,  1248,   113,   142,   113,   956,    82,   116,   959,
     109,    90,    91,   292,   113,    90,    91,   116,   117,   157,
     360,   105,  1045,   107,  1047,   993,  1049,   165,  1051,   943,
     944,   945,   946,   113,   109,   113,   116,   113,   113,   108,
     116,   116,   814,   108,   721,   722,   723,   724,   725,   726,
     727,   728,   729,   730,   731,   108,   733,   734,   735,   736,
     737,   738,   739,   740,   837,   837,  1016,   111,  1018,   113,
     410,   110,   844,   103,   104,    13,   355,   105,   216,   109,
     634,    19,   220,   113,    82,    23,   116,   764,   765,    65,
     107,   114,    90,    91,   117,   791,    34,    35,   794,    37,
     107,   873,   874,   111,  1072,   877,    44,   111,   880,   113,
      48,   109,   250,   108,   111,   113,   113,   111,   116,   398,
     108,   216,   894,   100,   101,   102,   112,   899,   900,    90,
      91,   410,   904,    96,   906,   907,   111,   112,   113,   277,
     480,    13,   111,   112,   113,  1133,   111,    19,   113,   108,
     126,    23,   108,   107,   292,   109,   108,  1107,   111,   112,
     113,   105,    34,    35,   105,    37,   142,   844,   106,    41,
      90,    91,    44,   938,   939,   940,    48,   111,   112,   117,
     877,   157,    82,   880,    92,    93,   465,   466,   105,   165,
      90,    91,   964,   111,   112,   113,   968,   113,   477,   971,
     972,   480,   111,   112,   976,   977,   111,   112,   113,   109,
     111,   112,   113,   113,   117,   987,   116,   117,   105,   498,
     111,   112,   113,   111,   112,   113,   733,   734,   735,   906,
     907,  1199,  1004,   209,  1222,  1223,   111,   112,   105,  1227,
     216,   105,  1220,   219,   220,   117,   105,   223,   111,   112,
     111,   112,   108,  1221,   111,   112,   111,   112,   111,   112,
    1032,  1033,   116,  1035,   111,   360,   111,  1255,   105,   964,
    1248,    82,   410,   249,   250,   111,   112,    82,  1266,   109,
    1268,  1269,   103,  1271,    27,    90,    91,   111,   112,  1277,
     105,  1279,  1280,   112,   634,    88,    13,  1285,   111,   112,
     276,   277,    19,   279,   109,   106,    23,   647,   113,   111,
     112,   116,   117,  1085,   654,   410,   292,    34,    35,    97,
      37,    98,  1094,   216,    82,    83,    96,    44,   466,   726,
     727,    48,   736,   737,   113,   108,   111,  1220,   109,   477,
     105,    51,   480,   111,   111,   111,    42,   111,    42,   106,
     112,   112,   106,   112,   106,  1032,  1033,   112,   105,   108,
     106,  1133,  1134,  1135,   704,  1248,   106,   106,   647,   106,
     105,   113,   105,  1145,  1146,   654,  1148,   656,  1151,  1151,
     106,   110,  1154,   105,    42,   480,   110,   105,    42,    82,
     106,   112,   111,     3,   106,   674,  1168,   106,   111,   678,
     117,    43,    32,   105,   683,   684,    16,   110,   106,    17,
     964,    21,   113,   692,   968,   106,    26,   106,  1190,    29,
    1192,  1193,   398,  1195,  1196,   704,   108,   106,    38,    39,
      40,    82,    42,   987,   410,    45,   110,   106,  1133,   111,
     105,   111,   113,   106,   108,   112,   108,   107,  1220,    59,
    1222,  1223,   111,   732,   106,  1227,    66,   106,   111,   105,
     105,  1233,   105,    24,    24,   105,    82,   360,   106,  1241,
     106,   964,   216,   105,   111,   106,  1248,   105,   111,   106,
     106,   106,   111,  1255,   106,    97,   106,   111,   106,   465,
     466,  1168,   113,   112,  1266,   106,  1268,  1269,   111,  1271,
     106,   477,   111,   106,   480,  1277,   111,  1279,  1280,   647,
     106,   106,   111,  1285,   106,   106,   654,   410,   656,   106,
     106,   111,   498,   111,    82,    82,   111,  1222,  1223,    83,
     111,  1085,  1227,   111,    24,   106,   674,   111,   106,   634,
     106,   106,    25,   216,   715,   878,   684,   247,   165,   199,
     895,   144,   647,   210,   692,  1104,   984,  1242,   837,   654,
    1255,  1197,   844,   718,  1241,   844,   704,   498,   606,    18,
      81,  1266,   689,  1268,  1269,   198,  1271,   469,   877,  1133,
    1134,   894,  1277,   467,  1279,  1280,   220,   480,   144,   277,
    1285,  1145,  1146,  1115,  1148,     3,  1170,  1241,   877,  1135,
    1221,   880,   209,    11,   219,   659,   859,  1151,    16,   704,
     844,   722,   721,    21,    -1,    -1,   360,    25,    26,   723,
     725,    29,   724,    -1,   964,    -1,    -1,    -1,   968,    -1,
      38,    39,    40,    -1,    42,    -1,  1190,    45,  1192,  1193,
    1133,   981,    -1,   983,    -1,    -1,    -1,   987,    -1,    57,
      -1,    59,    -1,    -1,     3,    -1,    -1,    65,    66,    -1,
      -1,    -1,    -1,    -1,    13,    -1,   410,    16,  1222,  1223,
      19,   647,    21,  1227,    23,    -1,    -1,    26,   654,  1233,
     656,    -1,    -1,    -1,    -1,    34,    35,   360,    37,    38,
      -1,    40,    -1,    -1,    -1,    44,    45,    -1,   674,    48,
      -1,  1255,   678,   111,    -1,    -1,   844,   683,   684,    -1,
      59,    -1,  1266,    -1,  1268,  1269,   692,  1271,    -1,   216,
      -1,    -1,    -1,  1277,    -1,  1279,  1280,    -1,   704,  1222,
    1223,  1285,    -1,    -1,  1227,    -1,   480,   410,    -1,   877,
      -1,   634,   880,    -1,    -1,  1085,     3,    -1,  1088,    -1,
      -1,  1091,    -1,    -1,   647,    -1,   732,   106,    -1,    16,
      -1,   654,  1255,    -1,    21,    -1,    -1,    -1,   117,    26,
      -1,    -1,    29,  1266,    -1,  1268,  1269,    -1,  1271,    -1,
      48,    38,    39,    40,  1277,    42,  1279,  1280,    45,    -1,
     216,    -1,  1285,  1133,  1134,  1135,    -1,    -1,    -1,    67,
      -1,    -1,    59,    -1,    -1,  1145,  1146,   480,  1148,    66,
    1150,   704,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    -1,    -1,    -1,    -1,    -1,    97,
      -1,    99,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1190,    -1,  1192,  1193,   111,    -1,  1135,   125,    -1,    -1,
      -1,   837,    -1,   360,    -1,  1133,    -1,    -1,   844,   964,
      -1,    -1,    -1,   968,    -1,    -1,    -1,    -1,    -1,    -1,
    1220,    -1,  1222,  1223,  1224,    -1,   981,  1227,   983,    -1,
     634,    -1,   987,  1233,    -1,    -1,    -1,    -1,    -1,    -1,
     168,   877,    -1,   647,   880,    -1,    -1,    -1,  1248,    -1,
     654,    -1,    -1,   410,    -1,  1255,    -1,  1257,  1258,    -1,
      -1,   189,   190,    -1,    -1,   193,  1266,    -1,  1268,  1269,
      -1,  1271,    -1,  1273,   360,    -1,    -1,  1277,    -1,  1279,
    1280,  1220,    -1,    -1,    -1,  1285,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1222,  1223,  1094,    -1,    -1,  1227,
     704,   634,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1248,
      -1,    -1,    -1,    -1,   647,    -1,    -1,    -1,    -1,    -1,
      -1,   654,    -1,   480,   410,    -1,    -1,  1255,    -1,    -1,
    1085,    -1,    -1,  1088,    -1,    -1,  1091,  1135,  1266,    -1,
    1268,  1269,    -1,  1271,    -1,    -1,    -1,    -1,    -1,  1277,
       3,  1279,  1280,    -1,    -1,    -1,    -1,  1285,    -1,    -1,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    21,    -1,
      -1,   704,    25,    26,    -1,    -1,    29,    -1,  1133,  1134,
    1135,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,    42,
    1145,  1146,    45,  1148,   480,  1150,   216,    -1,    -1,    -1,
      -1,    -1,   330,    -1,    57,    -1,    59,    -1,    -1,    -1,
      -1,   964,    65,    66,    -1,   968,    -1,    -1,    -1,    -1,
      -1,    -1,  1220,    -1,    -1,    -1,    -1,    -1,   981,    -1,
     983,    -1,    -1,    -1,   987,  1190,    -1,  1192,  1193,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
    1248,    -1,    16,    -1,    -1,    19,    -1,    21,   111,    23,
      -1,    -1,    26,    -1,    -1,  1220,    -1,  1222,  1223,  1224,
      34,    35,  1227,    37,    38,    -1,    40,   634,  1233,    -1,
      44,    45,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
     647,    -1,    -1,  1248,    -1,    59,    -1,   654,    -1,  1135,
    1255,    -1,  1257,  1258,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1266,    -1,  1268,  1269,    -1,  1271,    -1,  1273,    -1,
      -1,    -1,  1277,    -1,  1279,  1280,    -1,    -1,    -1,    -1,
    1285,    -1,  1085,    -1,    -1,  1088,    -1,    -1,  1091,    -1,
     360,    -1,   106,    -1,    -1,    -1,    -1,   704,   634,    -1,
      -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
     964,   647,    -1,    -1,   968,    -1,    -1,    -1,   654,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   981,     3,   983,
    1133,  1134,  1135,   987,  1220,    -1,    -1,    -1,    -1,    -1,
     410,    16,  1145,  1146,    -1,  1148,    21,  1150,    -1,    -1,
      25,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1248,    38,    39,    40,    -1,    42,   704,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   964,    -1,    -1,    59,   968,    -1,  1190,    -1,  1192,
    1193,    66,    -1,    -1,    -1,    -1,    -1,    -1,   981,    -1,
     983,    -1,    -1,    -1,   987,    -1,    -1,    -1,    -1,    -1,
     480,    -1,    -1,    -1,    -1,    -1,    -1,  1220,    -1,  1222,
    1223,  1224,    -1,    -1,  1227,    -1,    -1,    -1,    -1,    -1,
    1233,  1085,    -1,    -1,  1088,    -1,   111,  1091,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1248,    -1,    -1,    -1,    -1,
      -1,    -1,  1255,    -1,  1257,  1258,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1266,    -1,  1268,  1269,    -1,  1271,    -1,
    1273,    -1,    -1,    -1,  1277,    -1,  1279,  1280,    -1,  1133,
    1134,  1135,  1285,    -1,    -1,   115,    -1,    -1,    -1,    -1,
     120,  1145,  1146,    -1,  1148,    -1,  1150,    -1,    -1,    -1,
      -1,    -1,  1085,    -1,    -1,  1088,    -1,    -1,  1091,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1190,    -1,  1192,  1193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1133,  1134,  1135,    -1,    -1,    -1,    -1,   964,    -1,    -1,
      -1,   968,  1145,  1146,   634,  1148,  1220,  1150,  1222,  1223,
    1224,    -1,    -1,  1227,   981,    -1,   983,   647,    -1,  1233,
     987,    -1,    -1,    -1,   654,    -1,    -1,    -1,    -1,    -1,
      -1,   221,    -1,    -1,  1248,    -1,    -1,    -1,    -1,    -1,
      -1,  1255,    -1,  1257,  1258,    -1,    -1,  1190,    -1,  1192,
    1193,    -1,  1266,    -1,  1268,  1269,    -1,  1271,    -1,  1273,
      -1,   251,    -1,  1277,    -1,  1279,  1280,    -1,   964,    -1,
      -1,  1285,   968,    -1,   704,    -1,    -1,  1220,    -1,  1222,
    1223,  1224,    -1,    -1,  1227,   981,    -1,   983,    -1,    -1,
    1233,   987,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1248,    -1,    -1,    -1,    -1,
      -1,    -1,  1255,    -1,  1257,  1258,    -1,    -1,  1085,    -1,
      -1,  1088,    -1,  1266,  1091,  1268,  1269,    -1,  1271,    -1,
    1273,    -1,    -1,    -1,  1277,    -1,  1279,  1280,    -1,    -1,
      -1,    -1,  1285,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1133,  1134,  1135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1145,  1146,
      -1,  1148,    -1,  1150,    -1,    -1,    -1,    -1,    -1,  1085,
      -1,    -1,  1088,    -1,    -1,  1091,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   402,    -1,    -1,    -1,   406,    -1,    -1,    -1,
      -1,    -1,    -1,  1190,    -1,  1192,  1193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1133,  1134,  1135,
      -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,    -1,  1145,
    1146,    -1,  1148,  1220,  1150,  1222,  1223,  1224,    -1,    -1,
    1227,    -1,    -1,   167,    -1,    -1,  1233,   171,    -1,    -1,
     174,    -1,   176,    -1,    -1,    -1,    -1,   467,    -1,    -1,
     470,  1248,    -1,    -1,   188,    -1,    -1,    -1,  1255,    -1,
    1257,  1258,    -1,    -1,  1190,    -1,  1192,  1193,    -1,  1266,
      -1,  1268,  1269,    -1,  1271,    -1,  1273,    -1,    -1,    -1,
    1277,   501,  1279,  1280,    -1,    -1,    -1,    -1,  1285,    -1,
      -1,    -1,    -1,    -1,  1220,    -1,  1222,  1223,  1224,    -1,
      -1,  1227,    -1,    -1,   964,    -1,    -1,  1233,   968,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   981,  1248,   983,    -1,   259,   260,   987,    -1,  1255,
      -1,  1257,  1258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1266,    -1,  1268,  1269,    -1,  1271,    -1,  1273,    -1,    -1,
      -1,  1277,    -1,  1279,  1280,    -1,    -1,    -1,    -1,  1285,
     294,    -1,    -1,   297,    -1,   299,    -1,   301,    -1,   303,
      -1,   305,    -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,
      -1,    -1,   363,   364,    -1,   605,   606,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   329,    -1,    -1,    -1,   333,
      -1,    -1,   336,   384,   338,    -1,   626,    -1,    -1,    -1,
      -1,    -1,    -1,   394,    -1,    -1,   392,   393,    -1,    -1,
      -1,    -1,     3,    -1,    -1,  1085,    -1,    -1,  1088,    -1,
     650,  1091,    13,    -1,    -1,    16,   392,   393,    19,    -1,
      21,    -1,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    -1,    40,
      -1,    -1,    -1,    44,    45,    -1,    -1,    48,    -1,    -1,
      -1,   691,    -1,  1133,  1134,  1135,    -1,    -1,    59,    -1,
      -1,    -1,    -1,   703,    -1,  1145,  1146,    -1,  1148,    -1,
    1150,    -1,    -1,    -1,   714,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,   494,   495,
     496,   497,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
    1190,    -1,  1192,  1193,    -1,    -1,   117,    -1,   494,   495,
     496,   497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1220,    -1,  1222,  1223,  1224,    -1,    -1,  1227,    -1,    -1,
      -1,   791,    -1,  1233,   794,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1248,    -1,
      -1,    -1,    -1,    -1,    -1,  1255,    -1,  1257,  1258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1266,    -1,  1268,  1269,
      -1,  1271,    -1,  1273,   548,    -1,   550,  1277,   552,  1279,
    1280,   555,    -1,    -1,    -1,  1285,    -1,   847,   609,    -1,
     611,   612,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   623,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   586,    -1,   635,   589,    -1,   591,   639,   593,
      -1,   595,    -1,   597,    -1,    -1,    -1,    -1,    -1,    -1,
     890,    -1,   892,   893,   655,    -1,    -1,    -1,    -1,    -1,
     656,   662,    -1,    -1,    -1,   666,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,
     656,    16,    -1,   923,    19,   925,    21,    -1,    23,   690,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    -1,    40,    -1,   708,    -1,    44,
      45,    -1,    -1,    48,    -1,    -1,   717,    -1,    -1,   720,
      -1,    -1,    -1,    -1,    59,   721,   722,   723,   724,   725,
     726,   727,   728,   729,   730,   731,    -1,   733,   734,   735,
     736,   737,   738,   739,   740,   721,   722,   723,   724,   725,
     726,   727,   728,   729,   730,   731,    -1,   733,   734,   735,
     736,   737,   738,   739,   740,    -1,    -1,    -1,     3,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,  1017,    13,    -1,
      -1,    16,   117,    -1,    19,    -1,    21,   788,    23,    -1,
      -1,    26,   746,    -1,    29,    -1,   797,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    -1,    44,
      45,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   775,    -1,   777,    59,   779,    -1,    -1,   782,     3,
      -1,    66,    -1,    -1,    -1,   836,    -1,    -1,    -1,    13,
      -1,    -1,    16,    78,    -1,    19,    -1,    21,   844,    23,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    -1,    40,    -1,   844,    -1,
      44,    45,   107,   108,    48,    -1,   111,    -1,    -1,    -1,
      -1,    -1,   117,     3,   885,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    16,    -1,    -1,    19,
      -1,    21,    -1,    23,    -1,    -1,    26,    -1,    -1,    29,
     906,   907,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    -1,    44,    45,    -1,    -1,    48,    -1,
     906,   907,   106,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,   117,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    78,    -1,
       6,    -1,    -1,    -1,    -1,   966,    -1,    13,    -1,    -1,
      16,    17,    -1,    19,    -1,    21,    -1,    23,    -1,    -1,
      26,    -1,    -1,    -1,    -1,   986,    -1,    -1,    34,    35,
      -1,    37,    38,    -1,    40,    41,   950,   117,    44,    45,
      -1,    -1,    48,    -1,    50,    -1,   960,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,  1032,  1033,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    -1,    -1,    -1,    -1,
       3,    -1,    -1,    -1,    -1,    -1,  1032,  1033,    -1,   105,
      13,    -1,    -1,    16,    -1,   111,    19,    -1,    21,    -1,
      23,   117,    -1,    26,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      -1,    44,    45,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,  1055,  1103,    -1,    -1,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
    1131,  1132,    -1,    -1,    -1,  1136,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,   117,    -1,    -1,     3,    -1,    -1,
      -1,    -1,  1168,    -1,    -1,    -1,    -1,    13,    -1,  1180,
      16,    -1,    -1,    19,    -1,    21,    -1,    23,    -1,    -1,
      26,    -1,  1168,    29,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    -1,    42,    -1,    44,    45,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1221,    -1,    -1,    59,    60,  1226,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,  1241,    12,    13,    14,    -1,
      16,    17,    18,    19,    -1,    21,    22,    23,    -1,    -1,
      26,    -1,    28,    29,    30,  1241,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    44,    45,
      -1,   117,    48,    -1,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,   117,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    19,    -1,
      21,    22,    23,    -1,    -1,    26,    -1,    -1,    29,    30,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,    -1,    48,    -1,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,   117,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    12,    13,    14,    -1,
      16,    17,    18,    19,    -1,    21,    22,    23,    -1,    -1,
      26,    -1,    -1,    29,    30,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    44,    45,
      -1,    -1,    48,    -1,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,   117,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    19,    -1,
      21,    22,    23,    -1,    -1,    26,    -1,    -1,    29,    30,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,    -1,    48,    -1,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,   117,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    12,    13,    14,    -1,
      16,    17,    18,    19,    -1,    21,    22,    23,    -1,    -1,
      26,    -1,    -1,    29,    30,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    44,    45,
      -1,    -1,    48,    -1,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,     6,    -1,    -1,    90,    91,    -1,    -1,    13,    -1,
      -1,    16,    17,    -1,    19,    -1,    21,    -1,    23,   105,
      -1,    26,   108,    -1,    -1,   111,    -1,    -1,    -1,    34,
      35,   117,    37,    38,    -1,    40,    41,    -1,    -1,    44,
      45,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,     6,    -1,    -1,    90,    91,    -1,    -1,    13,
      -1,    -1,    16,    17,    -1,    19,    -1,    21,    -1,    23,
     105,    -1,    26,    -1,    -1,    -1,   111,    -1,    -1,    -1,
      34,    35,   117,    37,    38,    -1,    40,    41,    -1,    -1,
      44,    45,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    16,    -1,    -1,    19,
      -1,    21,    -1,    23,    -1,    -1,    26,    -1,    -1,    29,
      -1,   105,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,   117,    44,    45,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    13,    -1,    -1,
      16,    -1,    -1,    19,    -1,    21,    -1,    23,    78,    -1,
      26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    -1,    44,    45,
      -1,    -1,    48,    -1,    -1,    -1,    -1,   107,   108,    -1,
      -1,   111,    -1,    59,    -1,    -1,    -1,   117,     3,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    16,    78,    -1,    19,    -1,    21,    -1,    23,    -1,
      -1,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    -1,    44,
      45,   107,   108,    48,    -1,   111,    -1,    -1,    -1,    -1,
      -1,   117,     3,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    13,    -1,    -1,    16,    -1,    -1,    19,    -1,
      21,    -1,    23,    78,    -1,    26,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,    -1,    48,    -1,    -1,
       3,    -1,   107,    -1,    -1,    -1,   111,    -1,    59,    -1,
      13,    -1,   117,    16,    -1,    66,    19,    -1,    21,    -1,
      23,    -1,    -1,    26,    -1,    -1,    29,    78,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      -1,    44,    45,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    59,   108,    -1,    -1,
     111,    -1,    -1,    66,    13,    -1,   117,    16,    -1,    -1,
      19,    -1,    21,    -1,    23,    78,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    34,    35,    -1,    37,    38,
      -1,    40,    -1,    -1,    13,    44,    45,    16,    -1,    48,
      19,    -1,    21,    -1,    23,   108,    -1,    26,   111,    -1,
      59,    60,    -1,    -1,   117,    34,    35,    -1,    37,    38,
      -1,    40,    -1,    -1,    -1,    44,    45,    -1,     3,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      59,    16,    -1,    -1,    19,    -1,    21,    -1,    23,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    -1,    40,    -1,    -1,   117,    44,
      45,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,     4,
       5,     6,     7,     8,    -1,    10,    -1,    12,    13,    14,
      -1,    -1,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    36,    37,    -1,    -1,    -1,    41,    -1,    -1,    44,
      -1,    -1,   117,    48,    -1,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    -1,     4,
       5,     6,     7,     8,    -1,    10,    -1,    12,    13,    14,
     105,    -1,    17,    18,    19,    -1,   111,    22,    23,    -1,
      -1,    -1,   117,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    36,    37,    -1,    -1,    -1,    41,    -1,    -1,    44,
      -1,    -1,    -1,    48,    -1,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    90,    91,    17,    -1,    19,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    34,    35,   111,    37,    -1,    -1,
      -1,    41,   117,    -1,    44,    -1,    -1,    -1,    48,    -1,
      50,    -1,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,
      90,    91,    92,    93,    13,    -1,    -1,    -1,    17,    -1,
      19,    -1,    -1,    22,    23,   105,    -1,   107,   108,    -1,
      -1,    -1,   112,    -1,    -1,    34,    35,   117,    37,    -1,
      -1,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,    90,    91,    92,    93,    13,    -1,    -1,    -1,    17,
      -1,    19,    -1,    -1,    -1,    23,   105,    -1,   107,    -1,
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
      -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    34,
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
      23,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    17,    -1,    19,    -1,    -1,    -1,    23,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
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
      -1,    19,    -1,    -1,    -1,    23,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    34,    35,   117,    37,
      -1,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,
      48,    -1,    50,    -1,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,     6,
       7,    -1,    90,    91,    92,    93,    13,    -1,    -1,    -1,
      17,    -1,    19,    -1,    -1,    -1,    23,   105,    -1,    -1,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    34,    35,   117,
      37,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,    -1,    90,    91,    92,    93,    13,    -1,    -1,
      -1,    17,    -1,    19,    -1,    -1,    -1,    23,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
     117,    37,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,
      -1,    -1,    48,    -1,    50,    -1,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,     6,    79,    80,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    17,    -1,    19,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      34,    35,    -1,    37,    -1,    -1,    -1,    41,    -1,    -1,
      44,   117,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    90,    91,    17,    -1,
      19,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,    34,    35,    -1,    37,    -1,
      -1,    -1,    41,   117,    -1,    44,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      -1,    90,    91,    17,    -1,    19,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
      34,    35,    -1,    37,    -1,    -1,    -1,    41,   117,    -1,
      44,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    90,    91,    17,    -1,
      19,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,    34,    35,    -1,    37,    -1,
      -1,    -1,    41,   117,    -1,    44,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      -1,    90,    91,    17,    -1,    19,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
      34,    35,    -1,    37,    -1,    -1,    -1,    41,   117,    -1,
      44,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    90,    91,    17,    -1,
      19,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,    34,    35,    -1,    37,    -1,
      -1,    -1,    41,   117,    -1,    44,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      -1,    90,    91,    17,    -1,    19,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
      34,    35,    -1,    37,    -1,    -1,    -1,    41,   117,    -1,
      44,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    90,    91,    17,    -1,
      19,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,    34,    35,    -1,    37,    -1,
      -1,    -1,    41,   117,    -1,    44,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      -1,    90,    91,    17,    -1,    19,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
      34,    35,    -1,    37,    -1,    -1,    -1,    41,   117,    -1,
      44,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,    11,    16,    21,    25,    26,    29,    38,    39,
      40,    42,    45,    57,    59,    65,    66,   111,   125,   126,
     134,   169,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   205,   206,   275,   282,   283,   292,   293,
     310,   117,   170,    40,   170,   183,   170,   170,   170,   170,
      57,   170,   126,   189,   195,   194,    29,    39,    42,   282,
     310,     0,   125,   126,    78,   105,   239,   284,   111,   113,
     127,   170,   183,   111,   113,   111,   113,    20,   107,   242,
     276,    33,    58,   239,   294,   311,   312,    33,    58,   207,
     239,   241,   242,   244,   107,   127,   170,   170,   170,   170,
     239,   284,   126,   170,   179,   240,    13,    19,    23,    34,
      35,    37,    44,    48,   106,   170,   175,   176,   177,   253,
     254,   255,   285,   286,   287,   284,   107,   242,   288,   170,
     111,   113,   113,   111,   113,    94,   170,    94,   170,   170,
     243,   108,   111,   112,   144,   145,   170,   277,   280,   281,
     276,   243,   170,   183,   298,   311,   312,   107,   313,   296,
     312,   295,   170,   170,   183,   107,   245,   215,   241,   242,
     244,   211,   242,   244,   209,   244,   208,   196,   197,   107,
     107,   127,   242,   276,   239,   302,   311,   312,   223,   239,
     241,   242,   244,   284,   242,   288,    33,   180,   112,   135,
     136,    77,   109,   120,   121,   114,   170,   120,   106,   112,
     146,   147,   242,   288,    40,    41,   107,   108,   111,   134,
     148,   170,   205,   239,   246,   247,   248,   253,   256,   257,
     258,   268,   269,   270,   272,   289,   290,   291,   292,   319,
     288,   170,    94,    94,   111,   111,   112,   137,   138,   134,
     139,   170,   246,   108,   281,   145,   280,   105,   245,   278,
     279,   108,   281,   112,   108,   113,   112,   113,   132,   133,
     313,   300,   312,   299,   108,   111,   134,   149,   205,   239,
     253,   257,   292,   314,   315,   316,   313,   297,   313,   132,
     132,   108,   139,   245,   219,   242,   244,   217,   244,   216,
     245,   213,   244,   212,   245,   210,   245,   108,    53,    54,
      55,    56,    62,   128,   204,   198,   199,   200,   201,   107,
     276,   306,   311,   312,   313,   304,   312,   303,   245,   231,
     241,   242,   244,   227,   242,   244,   225,   244,   224,   242,
     288,   288,   170,   179,   136,   110,   121,   170,   286,   147,
     288,   319,   170,     4,     5,     6,     7,     8,    10,    12,
      14,    17,    18,    22,    30,    36,    41,    50,    51,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    90,    91,   105,   108,   111,   117,   134,   170,
     171,   172,   183,   184,   205,   253,   254,   255,   293,   320,
     321,   322,   323,   324,   325,   326,   328,   329,   330,   331,
     333,   334,   335,   336,   338,   339,   346,   348,   349,   351,
     352,   357,   358,   360,   361,   362,   363,   364,   365,   367,
     369,   377,   381,   382,   383,   384,   385,   387,   388,   389,
     391,   392,   396,   397,   412,   413,   415,   416,   417,   253,
     257,   272,   290,   108,   289,   105,   271,   170,   253,   258,
     170,   249,   250,   251,   111,   267,   319,   105,   259,    27,
     107,   264,   273,   273,   111,   111,   170,   138,   246,   108,
       7,    59,    60,    66,    79,    80,    92,    93,   105,   106,
     170,   254,   255,   384,   389,   390,   394,   395,   396,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     245,   245,   108,   170,   183,   133,   313,   301,   313,   253,
     257,   108,   314,   249,   267,   313,   108,   245,   221,   244,
     220,   245,   218,   245,   245,   214,   245,   245,   170,   183,
     170,   183,   129,   169,   170,   182,   170,   183,   170,   183,
     108,   204,   108,   128,   108,   128,   202,   203,   313,   308,
     312,   307,   313,   305,   313,   245,   235,   242,   244,   233,
     244,   232,   245,   229,   244,   228,   245,   226,   245,   288,
      96,   122,   181,   111,   170,   170,   174,   254,   386,   105,
     394,   105,   105,   170,   326,   111,   170,   394,   111,   394,
     113,   113,   116,   105,   394,   170,   183,   387,   388,   411,
     411,   394,    60,   325,    82,   109,   113,   116,   120,   109,
     113,   116,   120,   105,   113,   116,   108,   152,   321,   111,
     170,   249,   319,   111,   105,    82,   105,   319,   368,   378,
     113,   116,   109,   103,   104,   173,   398,    90,    91,   249,
     267,   264,   273,   273,   123,   253,   260,   106,   134,   253,
     261,   262,   263,   105,   271,   170,   259,   120,   111,   112,
     103,   106,   123,   253,   261,   264,   170,   265,   266,    17,
      50,   108,   170,   183,   274,   320,   381,   273,   105,   411,
     411,   411,   411,   174,   254,   255,   106,   112,   166,   167,
      81,    89,    88,    97,    98,    96,    84,    87,    77,    78,
      85,    86,   118,   100,   101,   102,    92,    93,    94,    95,
      99,   313,   249,   267,   111,   245,   222,   245,   245,   245,
      63,   111,    63,   111,    63,   111,    63,   111,   169,   182,
     111,   113,   111,   111,    64,    64,   108,   108,   108,   128,
     313,   309,   313,   313,   245,   237,   244,   236,   245,   234,
     245,   245,   230,   245,   245,   170,   181,   111,   109,   120,
     127,   168,   393,   120,   168,   105,   394,    82,   111,   394,
     394,    51,   111,   111,   111,    42,   170,   170,   394,   111,
     106,   249,   326,   394,     6,    17,    42,    50,   170,   385,
     170,   113,   394,    17,    42,    50,   170,   385,   170,   113,
     106,   390,    42,     6,   170,   321,   111,   134,   170,   324,
     334,   354,   356,   394,   164,   165,   170,   183,   324,   379,
     380,   381,   387,   421,    32,    43,   370,   371,   375,   368,
     170,   385,   170,   394,   394,   111,   273,   106,   261,    17,
     124,   170,   112,   253,   114,   251,   106,   112,   140,   141,
     123,   106,   261,   264,   250,   107,   252,   317,   394,   120,
     106,   261,   170,   106,   112,   142,   143,   105,   105,   113,
     113,   108,   320,   108,   113,   394,   106,   106,   122,   394,
     167,   394,   401,   402,   403,   404,   405,   406,   406,   408,
     408,   408,   408,   170,   178,   254,   255,   409,   409,   409,
     410,   410,   411,   411,   411,   111,   245,   182,   182,   182,
     182,   111,   170,   170,   183,   170,   183,   108,   313,   245,
     238,   245,   245,   245,   394,   317,   120,   393,   317,   120,
     106,   390,   106,   394,   106,   106,   105,   105,   106,   110,
     170,   113,   116,   105,    42,   110,   113,   116,   105,    42,
     106,   111,   394,   112,   159,   160,   111,   106,   165,   380,
     106,   111,   372,   376,   375,   161,   371,   370,   375,   105,
     110,   106,    17,   113,   114,   251,   170,   262,   141,   106,
     261,   106,   108,   112,   252,   318,   120,   106,   120,   266,
     143,   106,   390,   106,   390,    50,    50,   108,    50,   106,
     411,   414,   106,    82,   111,   112,   130,   131,   111,   130,
     111,   130,   111,   130,   111,   132,   111,   132,   111,   132,
     111,   132,   245,   110,   245,   106,   340,   111,    10,    51,
     170,   326,   327,   328,   332,   337,   347,   350,   351,   353,
     357,   359,   366,   394,   106,   390,   326,   170,   170,   106,
     390,   170,   170,   106,   390,   106,   355,   356,   111,   334,
     160,   111,   394,   326,   105,   319,   371,   375,   106,   390,
     170,   106,   108,   112,   150,   151,   108,   120,   111,   106,
     111,   106,   105,   105,   105,   420,   414,   399,   182,   111,
     131,   111,   111,   111,   111,   111,   111,   111,   245,   107,
     341,   105,   105,    82,    24,   105,    82,   319,   106,   106,
     105,   106,   105,   106,   326,   106,   106,   355,   106,   355,
     111,   134,   170,   373,   374,   106,   252,   151,   111,   111,
     106,   390,   106,   390,   106,   390,   341,     9,    28,   108,
     154,   155,   156,   342,   343,   344,   394,   394,   327,   326,
     111,   354,   394,   111,   106,   390,   106,   390,   326,   326,
     106,   326,   106,   106,   355,   374,    97,   162,   163,   106,
     251,   111,   106,   111,   106,   111,   106,   345,   399,   108,
     155,   343,   344,   108,   156,   344,   108,   153,   342,   344,
      82,    83,   106,   106,   111,   394,   111,   106,   106,   106,
     326,   326,   326,   106,   251,   170,   163,   319,   111,   111,
     111,   112,   157,   158,   108,    82,   108,   342,   155,   320,
     319,   364,   394,   327,   327,   106,   355,   111,   111,   394,
     327,   326,   345,   158,   320,   111,    24,   327,   106,   106,
     355,   106,   355,   111,   327,   327,   327,   106,   327,   106,
     106,   355,   327,   327,   327,   106,   327
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
     192,   192,   193,   193,   194,   194,   194,   196,   195,   197,
     195,   198,   195,   199,   195,   200,   195,   201,   195,   202,
     195,   203,   195,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   205,   205,   205,
     207,   206,   208,   206,   209,   206,   210,   206,   211,   206,
     212,   206,   213,   206,   214,   206,   215,   206,   216,   206,
     217,   206,   218,   206,   219,   206,   220,   206,   221,   206,
     222,   206,   223,   206,   224,   206,   225,   206,   226,   206,
     227,   206,   228,   206,   229,   206,   230,   206,   231,   206,
     232,   206,   233,   206,   234,   206,   235,   206,   236,   206,
     237,   206,   238,   206,   239,   240,   240,   241,   242,   243,
     243,   244,   244,   244,   244,   245,   245,   246,   246,   246,
     246,   247,   247,   247,   247,   247,   248,   248,   249,   249,
     250,   250,   251,   251,   252,   252,   253,   253,   253,   254,
     254,   255,   255,   256,   256,   257,   257,   257,   257,   258,
     258,   259,   259,   259,   259,   259,   259,   259,   259,   260,
     260,   261,   261,   262,   262,   262,   263,   263,   264,   265,
     265,   266,   267,   267,   268,   269,   270,   270,   270,   270,
     271,   272,   272,   272,   272,   272,   272,   272,   272,   273,
     273,   273,   273,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   275,   275,   275,   275,   276,   276,   276,
     276,   276,   276,   277,   277,   278,   279,   280,   280,   280,
     280,   280,   280,   281,   281,   282,   283,   283,   283,   283,
     283,   283,   283,   283,   284,   284,   285,   285,   286,   286,
     287,   288,   288,   289,   289,   290,   291,   291,   292,   294,
     293,   295,   293,   296,   293,   297,   293,   298,   293,   299,
     293,   300,   293,   301,   293,   302,   293,   303,   293,   304,
     293,   305,   293,   306,   293,   307,   293,   308,   293,   309,
     293,   310,   311,   312,   312,   313,   313,   314,   314,   314,
     314,   314,   315,   315,   316,   316,   317,   317,   317,   318,
     318,   319,   319,   320,   320,   321,   321,   321,   322,   322,
     323,   324,   324,   325,   325,   326,   326,   326,   326,   326,
     326,   327,   327,   327,   327,   327,   329,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     330,   331,   332,   333,   334,   334,   334,   334,   334,   334,
     334,   335,   336,   337,   338,   338,   340,   339,   341,   341,
     341,   341,   341,   341,   342,   342,   342,   343,   343,   344,
     344,   344,   345,   346,   347,   348,   349,   349,   350,   350,
     351,   352,   352,   352,   352,   352,   352,   352,   352,   353,
     353,   353,   353,   353,   353,   353,   353,   354,   354,   355,
     356,   356,   357,   358,   359,   360,   360,   361,   362,   362,
     363,   363,   364,   366,   365,   367,   368,   369,   369,   369,
     369,   370,   370,   372,   371,   373,   373,   374,   374,   376,
     375,   377,   377,   377,   377,   378,   379,   379,   380,   380,
     381,   381,   382,   382,   382,   382,   382,   382,   382,   382,
     382,   382,   382,   383,   383,   383,   383,   383,   383,   384,
     384,   384,   384,   385,   385,   385,   385,   386,   386,   387,
     387,   387,   387,   388,   388,   388,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     390,   390,   391,   391,   391,   391,   391,   391,   391,   391,
     392,   392,   392,   392,   392,   392,   393,   394,   395,   395,
     396,   397,   397,   397,   397,   398,   399,   399,   400,   400,
     401,   401,   402,   402,   403,   403,   404,   404,   405,   405,
     405,   406,   406,   406,   406,   406,   406,   407,   408,   408,
     408,   408,   409,   409,   409,   410,   410,   410,   410,   411,
     411,   411,   411,   411,   412,   413,   414,   414,   414,   414,
     414,   415,   415,   415,   415,   415,   416,   417,   418,   418,
     418,   420,   419,   421,   421,   421
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
       5,     5,     6,     6,     1,     1,     1,     0,     5,     0,
       6,     0,     6,     0,     7,     0,     6,     0,     7,     0,
       7,     0,     8,     3,     4,     3,     5,     6,     3,     5,
       6,     3,     5,     6,     3,     5,     6,     3,     5,     6,
       3,     5,     6,     5,     6,     5,     6,     1,     1,     1,
       0,     4,     0,     5,     0,     5,     0,     6,     0,     5,
       0,     6,     0,     6,     0,     7,     0,     5,     0,     6,
       0,     6,     0,     7,     0,     6,     0,     7,     0,     7,
       0,     8,     0,     5,     0,     6,     0,     6,     0,     7,
       0,     6,     0,     7,     0,     7,     0,     8,     0,     6,
       0,     7,     0,     7,     0,     8,     0,     7,     0,     8,
       0,     8,     0,     9,     3,     1,     2,     2,     2,     1,
       2,     2,     2,     3,     3,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     1,     3,
       1,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     3,     2,     3,     3,     4,     2,
       2,     2,     3,     3,     4,     3,     4,     4,     5,     2,
       3,     1,     2,     2,     3,     1,     3,     4,     2,     1,
       2,     1,     1,     1,     1,     2,     2,     3,     3,     4,
       1,     3,     4,     4,     5,     4,     5,     5,     6,     2,
       3,     3,     4,     4,     5,     4,     5,     6,     7,     6,
       7,     6,     7,     3,     4,     4,     5,     2,     3,     3,
       4,     3,     4,     1,     1,     2,     3,     1,     2,     2,
       2,     3,     3,     1,     2,     2,     3,     4,     4,     5,
       4,     5,     5,     6,     2,     3,     1,     2,     2,     1,
       3,     2,     3,     1,     1,     1,     2,     3,     1,     0,
       4,     0,     5,     0,     5,     0,     6,     0,     5,     0,
       6,     0,     6,     0,     7,     0,     5,     0,     6,     0,
       6,     0,     7,     0,     6,     0,     7,     0,     7,     0,
       8,     1,     2,     2,     3,     2,     3,     1,     1,     1,
       1,     1,     3,     4,     2,     3,     2,     3,     3,     1,
       2,     2,     3,     1,     2,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     5,     7,     7,     3,     5,     0,     6,     3,     4,
       2,     3,     3,     4,     4,     3,     3,     3,     4,     2,
       3,     1,     1,     5,     5,     7,     1,     1,     1,     1,
       1,     6,     7,     7,     8,     7,     8,     8,     9,     6,
       7,     7,     8,     7,     8,     8,     9,     1,     1,     1,
       1,     2,     3,     5,     5,     2,     3,     3,     2,     3,
       2,     3,     3,     0,     6,     1,     1,     3,     3,     4,
       1,     1,     2,     0,     6,     2,     3,     1,     2,     0,
       3,     3,     4,     4,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     1,     1,
       1,     1,     1,     3,     3,     4,     4,     3,     3,     1,
       3,     3,     3,     4,     5,     5,     6,     1,     2,     3,
       3,     5,     5,     4,     4,     4,     4,     3,     5,     6,
       5,     6,     5,     6,     5,     6,     7,     8,     7,     8,
       1,     2,     3,     3,     3,     3,     3,     5,     5,     3,
       3,     4,     3,     4,     4,     4,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       1,     2,     2,     1,     2,     2,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     4,     4,
       5,     0,     6,     1,     1,     1
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
#line 790 "fff.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type ;(yyval.typeinfo)->order=1;(yyval.typeinfo)->tac=emptyvector();}
#line 4502 "fff.tab.c"
    break;

  case 3: /* OMPSB: OMPSB PSB  */
#line 791 "fff.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type + "[]";(yyval.typeinfo)->order=(yyvsp[-1].typeinfo)->order+1;(yyval.typeinfo)->tac=emptyvector();}
#line 4508 "fff.tab.c"
    break;

  case 4: /* PSB: LSB RSB  */
#line 793 "fff.y"
                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "[]";(yyval.typeinfo)->tac=emptyvector();}
#line 4514 "fff.tab.c"
    break;

  case 5: /* OMAdditionalBound: AdditionalBound  */
#line 795 "fff.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4520 "fff.tab.c"
    break;

  case 6: /* OMAdditionalBound: OMAdditionalBound AdditionalBound  */
#line 796 "fff.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4526 "fff.tab.c"
    break;

  case 7: /* ReceiverParameterComma: ReceiverParameter COMMA  */
#line 798 "fff.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 4532 "fff.tab.c"
    break;

  case 8: /* IdentifierDot: Identifier DOT  */
#line 800 "fff.y"
                              {         (yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4538 "fff.tab.c"
    break;

  case 9: /* OMImportDeclaration: ImportDeclaration  */
#line 802 "fff.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4544 "fff.tab.c"
    break;

  case 10: /* OMImportDeclaration: OMImportDeclaration ImportDeclaration  */
#line 803 "fff.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4550 "fff.tab.c"
    break;

  case 11: /* OMTopLevelClassOrInterfaceDeclaration: TopLevelClassOrInterfaceDeclaration  */
#line 805 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4556 "fff.tab.c"
    break;

  case 12: /* OMTopLevelClassOrInterfaceDeclaration: OMTopLevelClassOrInterfaceDeclaration TopLevelClassOrInterfaceDeclaration  */
#line 806 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4562 "fff.tab.c"
    break;

  case 13: /* OMDotIdentifier: DOT Identifier  */
#line 808 "fff.y"
                                                                {(yyval.typeinfo) = createstruct();string p=((yyvsp[0].str));((yyval.typeinfo))->name="."+p;(yyval.typeinfo)->tac=emptyvector();}
#line 4568 "fff.tab.c"
    break;

  case 14: /* OMDotIdentifier: OMDotIdentifier DOT Identifier  */
#line 809 "fff.y"
                                                    {(yyval.typeinfo) = createstruct();string p=((yyvsp[0].str));((yyval.typeinfo))->name=((yyvsp[-2].typeinfo))->name+"."+p;(yyval.typeinfo)->tac= (yyvsp[-2].typeinfo)->tac;}
#line 4574 "fff.tab.c"
    break;

  case 15: /* OMModuleDirective: ModuleDirective  */
#line 811 "fff.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4580 "fff.tab.c"
    break;

  case 16: /* OMModuleDirective: OMModuleDirective ModuleDirective  */
#line 812 "fff.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4586 "fff.tab.c"
    break;

  case 17: /* OMRequiresModifier: Modifieropt  */
#line 814 "fff.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4592 "fff.tab.c"
    break;

  case 18: /* OMRequiresModifier: OMRequiresModifier Modifieropt  */
#line 815 "fff.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4598 "fff.tab.c"
    break;

  case 19: /* OMCommaModuleName: CommaModuleName  */
#line 817 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4604 "fff.tab.c"
    break;

  case 20: /* OMCommaModuleName: OMCommaModuleName CommaModuleName  */
#line 818 "fff.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4610 "fff.tab.c"
    break;

  case 21: /* CommaModuleName: COMMA ModuleName  */
#line 820 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4616 "fff.tab.c"
    break;

  case 22: /* OMCommaTypeName: CommaTypeName  */
#line 822 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4622 "fff.tab.c"
    break;

  case 23: /* OMCommaTypeName: OMCommaTypeName CommaTypeName  */
#line 823 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4628 "fff.tab.c"
    break;

  case 24: /* CommaTypeName: COMMA Identifier  */
#line 825 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4634 "fff.tab.c"
    break;

  case 25: /* CommaTypeName: COMMA ExpressionName  */
#line 826 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4640 "fff.tab.c"
    break;

  case 26: /* OMClassModifier: InterfaceModifier  */
#line 828 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4646 "fff.tab.c"
    break;

  case 27: /* OMClassModifier: OMClassModifier InterfaceModifier  */
#line 829 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4652 "fff.tab.c"
    break;

  case 28: /* OMCommaTypeParameter: CommaTypeParameter  */
#line 831 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4658 "fff.tab.c"
    break;

  case 29: /* OMCommaTypeParameter: OMCommaTypeParameter CommaTypeParameter  */
#line 832 "fff.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4664 "fff.tab.c"
    break;

  case 30: /* CommaTypeParameter: COMMA TypeParameter  */
#line 834 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4670 "fff.tab.c"
    break;

  case 31: /* OMCommaInterfaceType: CommaInterfaceType  */
#line 836 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4676 "fff.tab.c"
    break;

  case 32: /* OMCommaInterfaceType: OMCommaInterfaceType CommaInterfaceType  */
#line 837 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4682 "fff.tab.c"
    break;

  case 33: /* CommaInterfaceType: COMMA Identifier  */
#line 839 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4688 "fff.tab.c"
    break;

  case 34: /* OMClassBodyDeclaration: ClassBodyDeclaration  */
#line 841 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 4694 "fff.tab.c"
    break;

  case 35: /* OMClassBodyDeclaration: OMClassBodyDeclaration ClassBodyDeclaration  */
#line 842 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4700 "fff.tab.c"
    break;

  case 36: /* OMCommaFormalParameter: CommaFormalParameter  */
#line 844 "fff.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;(yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4706 "fff.tab.c"
    break;

  case 37: /* OMCommaFormalParameter: OMCommaFormalParameter CommaFormalParameter  */
#line 845 "fff.y"
                                                                        {(yyval.typeinfo) = createstruct();vector<string>a=((yyvsp[-1].typeinfo))->type_variable;vector<string>b=((yyvsp[0].typeinfo))->type_variable;for(auto z:a){((yyval.typeinfo))->type_variable.push_back(z);}for(auto z:b){((yyval.typeinfo))->type_variable.push_back(z);}(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4712 "fff.tab.c"
    break;

  case 38: /* CommaFormalParameter: COMMA FormalParameter  */
#line 847 "fff.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;(yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4718 "fff.tab.c"
    break;

  case 39: /* OMCommaExceptionType: CommaExceptionType  */
#line 849 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4724 "fff.tab.c"
    break;

  case 40: /* OMCommaExceptionType: OMCommaExceptionType CommaExceptionType  */
#line 850 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4730 "fff.tab.c"
    break;

  case 41: /* CommaExceptionType: COMMA ExceptionType  */
#line 852 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4736 "fff.tab.c"
    break;

  case 42: /* OMCommaEnumConstant: CommaEnumConstant  */
#line 854 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4742 "fff.tab.c"
    break;

  case 43: /* OMCommaEnumConstant: OMCommaEnumConstant CommaEnumConstant  */
#line 855 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4748 "fff.tab.c"
    break;

  case 44: /* CommaEnumConstant: EnumConstant COMMA  */
#line 857 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 4754 "fff.tab.c"
    break;

  case 45: /* OMCommaRecordComponent: CommaRecordComponent  */
#line 859 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4760 "fff.tab.c"
    break;

  case 46: /* OMCommaRecordComponent: OMCommaRecordComponent CommaRecordComponent  */
#line 860 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4766 "fff.tab.c"
    break;

  case 47: /* CommaRecordComponent: COMMA RecordComponent  */
#line 862 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4772 "fff.tab.c"
    break;

  case 48: /* OMRecordBodyDeclaration: RecordBodyDeclaration  */
#line 864 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4778 "fff.tab.c"
    break;

  case 49: /* OMRecordBodyDeclaration: OMRecordBodyDeclaration RecordBodyDeclaration  */
#line 865 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4784 "fff.tab.c"
    break;

  case 50: /* OMInterfaceMemberDeclaration: InterfaceMemberDeclaration  */
#line 867 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4790 "fff.tab.c"
    break;

  case 51: /* OMInterfaceMemberDeclaration: OMInterfaceMemberDeclaration InterfaceMemberDeclaration  */
#line 868 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4796 "fff.tab.c"
    break;

  case 52: /* OMCommaVariableInitializer: CommaVariableInitializer  */
#line 870 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type =  ((yyvsp[0].typeinfo))->type; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4802 "fff.tab.c"
    break;

  case 53: /* OMCommaVariableInitializer: OMCommaVariableInitializer CommaVariableInitializer  */
#line 871 "fff.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type =  ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4808 "fff.tab.c"
    break;

  case 54: /* CommaVariableInitializer: COMMA VariableInitializer  */
#line 873 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type =  ((yyvsp[0].typeinfo))->type; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4814 "fff.tab.c"
    break;

  case 55: /* OMBlockStatement: BlockStatement  */
#line 875 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 4820 "fff.tab.c"
    break;

  case 56: /* OMBlockStatement: OMBlockStatement BlockStatement  */
#line 876 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4826 "fff.tab.c"
    break;

  case 57: /* OMSwitchRule: SwitchRule  */
#line 878 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4832 "fff.tab.c"
    break;

  case 58: /* OMSwitchRule: OMSwitchRule SwitchRule  */
#line 879 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4838 "fff.tab.c"
    break;

  case 59: /* OMSwitchBlockStatementGroup: SwitchBlockStatementGroup  */
#line 881 "fff.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4844 "fff.tab.c"
    break;

  case 60: /* OMSwitchBlockStatementGroup: OMSwitchBlockStatementGroup SwitchBlockStatementGroup  */
#line 882 "fff.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4850 "fff.tab.c"
    break;

  case 61: /* OMSwitchLabelColon: SwitchLabelColon  */
#line 884 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4856 "fff.tab.c"
    break;

  case 62: /* OMSwitchLabelColon: OMSwitchLabelColon SwitchLabelColon  */
#line 885 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4862 "fff.tab.c"
    break;

  case 63: /* SwitchLabelColon: SwitchLabel COLON  */
#line 887 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 4868 "fff.tab.c"
    break;

  case 64: /* OMCommaCaseConstant: CommaCaseConstant  */
#line 889 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4874 "fff.tab.c"
    break;

  case 65: /* OMCommaCaseConstant: OMCommaCaseConstant CommaCaseConstant  */
#line 890 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4880 "fff.tab.c"
    break;

  case 66: /* CommaCaseConstant: COMMA CaseConstant  */
#line 892 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4886 "fff.tab.c"
    break;

  case 67: /* OMCommaStatementExpression: CommaStatementExpression  */
#line 894 "fff.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4892 "fff.tab.c"
    break;

  case 68: /* OMCommaStatementExpression: OMCommaStatementExpression CommaStatementExpression  */
#line 895 "fff.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4898 "fff.tab.c"
    break;

  case 69: /* CommaStatementExpression: COMMA StatementExpression  */
#line 897 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4904 "fff.tab.c"
    break;

  case 70: /* OMCatchClause: CatchClause  */
#line 899 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4910 "fff.tab.c"
    break;

  case 71: /* OMCatchClause: OMCatchClause CatchClause  */
#line 900 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4916 "fff.tab.c"
    break;

  case 72: /* OMOrClassType: OrClassType  */
#line 902 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4922 "fff.tab.c"
    break;

  case 73: /* OMOrClassType: OMOrClassType OrClassType  */
#line 903 "fff.y"
                                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4928 "fff.tab.c"
    break;

  case 74: /* OrClassType: BITOR Identifier  */
#line 905 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 4934 "fff.tab.c"
    break;

  case 75: /* OMSemicolonResource: SemicolonResource  */
#line 907 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4940 "fff.tab.c"
    break;

  case 76: /* OMSemicolonResource: OMSemicolonResource SemicolonResource  */
#line 908 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4946 "fff.tab.c"
    break;

  case 77: /* SemicolonResource: Resource SEMICOLON  */
#line 910 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 4952 "fff.tab.c"
    break;

  case 78: /* OMCommaExpression: CommaExpression  */
#line 912 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;for(auto z:(yyvsp[0].typeinfo)->params)(yyval.typeinfo)->params.push_back(z);}
#line 4958 "fff.tab.c"
    break;

  case 79: /* OMCommaExpression: OMCommaExpression CommaExpression  */
#line 913 "fff.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);for(auto z:((yyvsp[-1].typeinfo))->params)((yyval.typeinfo))->params.push_back(z);for(auto z:((yyvsp[0].typeinfo))->params)((yyval.typeinfo))->params.push_back(z);}
#line 4964 "fff.tab.c"
    break;

  case 80: /* CommaExpression: COMMA Expression  */
#line 915 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;string s = ((yyvsp[0].typeinfo))->tempname; (yyval.typeinfo)->params.push_back(s);}
#line 4970 "fff.tab.c"
    break;

  case 81: /* OMDimExpr: DimExpr  */
#line 917 "fff.y"
                                                                                                                {(yyval.typeinfo)=createstruct();int p=(yyvsp[0].typeinfo)->exprvalue;vector<int>q={p};(yyval.typeinfo)->arrdim=q;(yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 4976 "fff.tab.c"
    break;

  case 82: /* OMDimExpr: OMDimExpr DimExpr  */
#line 918 "fff.y"
                                                                                                        {(yyval.typeinfo)=createstruct();int p=(yyvsp[0].typeinfo)->exprvalue;(yyval.typeinfo)->arrdim=(yyvsp[-1].typeinfo)->arrdim;((yyval.typeinfo))->arrdim.push_back(p);(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 4982 "fff.tab.c"
    break;

  case 83: /* Modifieropt: PUBLIC  */
#line 920 "fff.y"
                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4988 "fff.tab.c"
    break;

  case 84: /* Modifieropt: PROTECTED  */
#line 921 "fff.y"
                                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 4994 "fff.tab.c"
    break;

  case 85: /* Modifieropt: PRIVATE  */
#line 922 "fff.y"
                                                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5000 "fff.tab.c"
    break;

  case 86: /* Modifieropt: ABSTRACT  */
#line 923 "fff.y"
                                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5006 "fff.tab.c"
    break;

  case 87: /* Modifieropt: STATIC  */
#line 924 "fff.y"
                                                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5012 "fff.tab.c"
    break;

  case 88: /* Modifieropt: SEALED  */
#line 925 "fff.y"
                                                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5018 "fff.tab.c"
    break;

  case 89: /* Modifieropt: STRICTFP  */
#line 926 "fff.y"
                                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5024 "fff.tab.c"
    break;

  case 90: /* Modifieropt: FINAL  */
#line 927 "fff.y"
                                                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5030 "fff.tab.c"
    break;

  case 91: /* Identifier: IDENTIFIERWK  */
#line 929 "fff.y"
                                                {(yyval.str)=(yyvsp[0].str);}
#line 5036 "fff.tab.c"
    break;

  case 92: /* UnqualifiedMethodIdentifier: IDENTIFIERWK  */
#line 931 "fff.y"
                                                                {(yyval.typeinfo) = createstruct(); string p = (yyvsp[0].str);((yyval.typeinfo))->name = p;(yyval.typeinfo)->tempname=p;}
#line 5042 "fff.tab.c"
    break;

  case 93: /* UnqualifiedMethodIdentifier: EXPORTS  */
#line 932 "fff.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5048 "fff.tab.c"
    break;

  case 94: /* UnqualifiedMethodIdentifier: OPENS  */
#line 933 "fff.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5054 "fff.tab.c"
    break;

  case 95: /* UnqualifiedMethodIdentifier: REQUIRES  */
#line 934 "fff.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5060 "fff.tab.c"
    break;

  case 96: /* UnqualifiedMethodIdentifier: USES  */
#line 935 "fff.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5066 "fff.tab.c"
    break;

  case 97: /* UnqualifiedMethodIdentifier: MODULE  */
#line 936 "fff.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5072 "fff.tab.c"
    break;

  case 98: /* UnqualifiedMethodIdentifier: PERMITS  */
#line 937 "fff.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5078 "fff.tab.c"
    break;

  case 99: /* UnqualifiedMethodIdentifier: SEALED  */
#line 938 "fff.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5084 "fff.tab.c"
    break;

  case 100: /* UnqualifiedMethodIdentifier: VAR  */
#line 939 "fff.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5090 "fff.tab.c"
    break;

  case 101: /* UnqualifiedMethodIdentifier: NONSEALED  */
#line 940 "fff.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5096 "fff.tab.c"
    break;

  case 102: /* UnqualifiedMethodIdentifier: PROVIDES  */
#line 941 "fff.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5102 "fff.tab.c"
    break;

  case 103: /* UnqualifiedMethodIdentifier: TO  */
#line 942 "fff.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5108 "fff.tab.c"
    break;

  case 104: /* UnqualifiedMethodIdentifier: WITH  */
#line 943 "fff.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5114 "fff.tab.c"
    break;

  case 105: /* UnqualifiedMethodIdentifier: OPEN  */
#line 944 "fff.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5120 "fff.tab.c"
    break;

  case 106: /* UnqualifiedMethodIdentifier: RECORD  */
#line 945 "fff.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5126 "fff.tab.c"
    break;

  case 107: /* UnqualifiedMethodIdentifier: TRANSITIVE  */
#line 946 "fff.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5132 "fff.tab.c"
    break;

  case 108: /* Literal: INTEGERLITERAL  */
#line 956 "fff.y"
                                                                                        {string x=(yyvsp[0].str);int p=stoi(x);(yyval.typeinfo)=new Typeinfo;     (yyval.typeinfo)->littype="int";(yyval.typeinfo)->valint=p;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+" = "+x;(yyval.typeinfo)->tac={z};(yyval.typeinfo)->exprvalue=atoi((yyvsp[0].str));((yyval.typeinfo))->type = "int";}
#line 5138 "fff.tab.c"
    break;

  case 109: /* Literal: FLOATINGPOINTLITERAL  */
#line 957 "fff.y"
                                                                                        {string x=(yyvsp[0].str);float p=stof(x);(yyval.typeinfo)=new Typeinfo;   (yyval.typeinfo)->littype="float";(yyval.typeinfo)->valfloat=p;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+" = "+x;(yyval.typeinfo)->tac={z};(yyval.typeinfo)->exprvalue=(int)((yyval.typeinfo)->valfloat);((yyval.typeinfo))->type = "float";}
#line 5144 "fff.tab.c"
    break;

  case 110: /* Literal: BOOLEANLITERAL  */
#line 958 "fff.y"
                                                                                        {string x=(yyvsp[0].str);;(yyval.typeinfo)=new Typeinfo;                  (yyval.typeinfo)->littype="bool";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+" = "+x;(yyval.typeinfo)->tac={z};if(x=="true"){(yyval.typeinfo)->exprvalue=1;}else{(yyval.typeinfo)->exprvalue=0;};((yyval.typeinfo))->type = "bool";}
#line 5150 "fff.tab.c"
    break;

  case 111: /* Literal: NULLLITERAL  */
#line 959 "fff.y"
                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo;                   (yyval.typeinfo)->littype="null";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+" = "+x;(yyval.typeinfo)->tac={z};(yyval.typeinfo)->exprvalue=0;(yyval.typeinfo)->type="null";}
#line 5156 "fff.tab.c"
    break;

  case 112: /* Literal: CHARACTERLITERAL  */
#line 960 "fff.y"
                                                                                            {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo;                   (yyval.typeinfo)->littype="char";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+"="+x;(yyval.typeinfo)->tac={z};(yyval.typeinfo)->exprvalue=x[0]-'\0';((yyval.typeinfo))->type = "char";}
#line 5162 "fff.tab.c"
    break;

  case 113: /* Literal: STRING  */
#line 961 "fff.y"
                                                                                                    {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo;                   (yyval.typeinfo)->littype="string";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+" = "+x;(yyval.typeinfo)->tac={z};((yyval.typeinfo))->type = "string";}
#line 5168 "fff.tab.c"
    break;

  case 114: /* Literal: TEXTBLOCKS  */
#line 962 "fff.y"
                                                                                            {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo;                   (yyval.typeinfo)->littype="textblock";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=y+" = "+x;(yyval.typeinfo)->tac={z};((yyval.typeinfo))->type = "textblock";}
#line 5174 "fff.tab.c"
    break;

  case 115: /* ASSIGNMENTOPERATOR: NEWASSIGNMENTOPERATOR  */
#line 964 "fff.y"
                                                                {(yyval.str)=(yyvsp[0].str);}
#line 5180 "fff.tab.c"
    break;

  case 116: /* ASSIGNMENTOPERATOR: EQUAL  */
#line 965 "fff.y"
                                                                                                        {(yyval.str)=(yyvsp[0].str);}
#line 5186 "fff.tab.c"
    break;

  case 117: /* PrimitiveType: UnannPrimitiveType  */
#line 967 "fff.y"
                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5192 "fff.tab.c"
    break;

  case 118: /* NumericType: IntegralType  */
#line 969 "fff.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=emptyvector();}
#line 5198 "fff.tab.c"
    break;

  case 119: /* NumericType: FloatingPointType  */
#line 970 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=emptyvector();}
#line 5204 "fff.tab.c"
    break;

  case 120: /* IntegralType: BYTE  */
#line 972 "fff.y"
                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "byte";(yyval.typeinfo)->tac=emptyvector();}
#line 5210 "fff.tab.c"
    break;

  case 121: /* IntegralType: SHORT  */
#line 973 "fff.y"
                                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "short";(yyval.typeinfo)->tac=emptyvector();}
#line 5216 "fff.tab.c"
    break;

  case 122: /* IntegralType: INT  */
#line 974 "fff.y"
                                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "int";(yyval.typeinfo)->tac=emptyvector();}
#line 5222 "fff.tab.c"
    break;

  case 123: /* IntegralType: LONG  */
#line 975 "fff.y"
                                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "long";(yyval.typeinfo)->tac=emptyvector();}
#line 5228 "fff.tab.c"
    break;

  case 124: /* IntegralType: CHAR  */
#line 976 "fff.y"
                                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "char";(yyval.typeinfo)->tac=emptyvector();}
#line 5234 "fff.tab.c"
    break;

  case 125: /* FloatingPointType: FLOAT  */
#line 978 "fff.y"
                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "float";(yyval.typeinfo)->tac=emptyvector();}
#line 5240 "fff.tab.c"
    break;

  case 126: /* FloatingPointType: DOUBLE  */
#line 979 "fff.y"
                                                                                                        {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "double";(yyval.typeinfo)->tac=emptyvector();}
#line 5246 "fff.tab.c"
    break;

  case 127: /* ReferenceType: Identifier  */
#line 981 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=emptyvector();}
#line 5252 "fff.tab.c"
    break;

  case 128: /* ReferenceType: UnannArrayType  */
#line 982 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5258 "fff.tab.c"
    break;

  case 129: /* TypeParameter: Identifier  */
#line 984 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5264 "fff.tab.c"
    break;

  case 130: /* TypeParameter: Identifier TypeBound  */
#line 985 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5270 "fff.tab.c"
    break;

  case 131: /* TypeBound: EXTENDS Identifier  */
#line 987 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5276 "fff.tab.c"
    break;

  case 132: /* TypeBound: EXTENDS Identifier OMAdditionalBound  */
#line 988 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5282 "fff.tab.c"
    break;

  case 133: /* AdditionalBound: BITAND Identifier  */
#line 990 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5288 "fff.tab.c"
    break;

  case 134: /* ModuleName: Identifier  */
#line 992 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5294 "fff.tab.c"
    break;

  case 135: /* ModuleName: ModuleName DOT Identifier  */
#line 993 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5300 "fff.tab.c"
    break;

  case 136: /* ExpressionName: Identifier DOT Identifier  */
#line 995 "fff.y"
                                                                {(yyval.typeinfo) = createstruct();string q=((yyvsp[-2].str));string p=((yyvsp[0].str));((yyval.typeinfo))->type=q+"."+p;string x=(yyvsp[-2].str);string r=newtemp(); (yyval.typeinfo)->tempname=r;r=r+" = "+x; (yyval.typeinfo)->tac={r};}
#line 5306 "fff.tab.c"
    break;

  case 137: /* ExpressionName: ExpressionName DOT Identifier  */
#line 996 "fff.y"
                                                                                        {(yyval.typeinfo) = createstruct();string p=((yyvsp[0].str));((yyval.typeinfo))->type=((yyvsp[-2].typeinfo))->type+"."+p; (yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 5312 "fff.tab.c"
    break;

  case 138: /* MethodName: UnqualifiedMethodIdentifier  */
#line 998 "fff.y"
                                                                                {(yyval.typeinfo) = createstruct(); ;((yyval.typeinfo))->name = ((yyvsp[0].typeinfo))->name; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 5318 "fff.tab.c"
    break;

  case 139: /* CompilationUnit: OrdinaryCompilationUnit  */
#line 1000 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac; for(auto z:((yyval.typeinfo)->tac))code<<z<<"\n"; }
#line 5324 "fff.tab.c"
    break;

  case 140: /* CompilationUnit: ModularCompilationUnit  */
#line 1001 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac; for(auto z:((yyval.typeinfo)->tac))code<<z<<"\n"; }
#line 5330 "fff.tab.c"
    break;

  case 141: /* OrdinaryCompilationUnit: %empty  */
#line 1003 "fff.y"
                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5336 "fff.tab.c"
    break;

  case 142: /* OrdinaryCompilationUnit: OMTopLevelClassOrInterfaceDeclaration  */
#line 1004 "fff.y"
                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5342 "fff.tab.c"
    break;

  case 143: /* OrdinaryCompilationUnit: OMImportDeclaration  */
#line 1005 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5348 "fff.tab.c"
    break;

  case 144: /* OrdinaryCompilationUnit: OMImportDeclaration OMTopLevelClassOrInterfaceDeclaration  */
#line 1006 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5354 "fff.tab.c"
    break;

  case 145: /* OrdinaryCompilationUnit: PackageDeclaration  */
#line 1007 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5360 "fff.tab.c"
    break;

  case 146: /* OrdinaryCompilationUnit: PackageDeclaration OMTopLevelClassOrInterfaceDeclaration  */
#line 1008 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5366 "fff.tab.c"
    break;

  case 147: /* OrdinaryCompilationUnit: PackageDeclaration OMImportDeclaration  */
#line 1009 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5372 "fff.tab.c"
    break;

  case 148: /* OrdinaryCompilationUnit: PackageDeclaration OMImportDeclaration OMTopLevelClassOrInterfaceDeclaration  */
#line 1010 "fff.y"
                                                                                                  {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5378 "fff.tab.c"
    break;

  case 149: /* ModularCompilationUnit: ModuleDeclaration  */
#line 1012 "fff.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5384 "fff.tab.c"
    break;

  case 150: /* ModularCompilationUnit: OMImportDeclaration ModuleDeclaration  */
#line 1013 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5390 "fff.tab.c"
    break;

  case 151: /* PackageDeclaration: PACKAGE Identifier SEMICOLON  */
#line 1015 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5396 "fff.tab.c"
    break;

  case 152: /* PackageDeclaration: PACKAGE Identifier OMDotIdentifier SEMICOLON  */
#line 1016 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5402 "fff.tab.c"
    break;

  case 153: /* ImportDeclaration: SingleTypeImportDeclaration  */
#line 1018 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5408 "fff.tab.c"
    break;

  case 154: /* ImportDeclaration: SingleStaticImportDeclaration  */
#line 1019 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5414 "fff.tab.c"
    break;

  case 155: /* ImportDeclaration: StaticImportOnDemandDeclaration  */
#line 1020 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5420 "fff.tab.c"
    break;

  case 156: /* ImportDeclaration: ImportOnDemandDeclaration  */
#line 1021 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5426 "fff.tab.c"
    break;

  case 157: /* SingleTypeImportDeclaration: IMPORT Identifier SEMICOLON  */
#line 1023 "fff.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5432 "fff.tab.c"
    break;

  case 158: /* SingleTypeImportDeclaration: IMPORT ExpressionName SEMICOLON  */
#line 1024 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5438 "fff.tab.c"
    break;

  case 159: /* SingleStaticImportDeclaration: IMPORT STATIC ExpressionName SEMICOLON  */
#line 1026 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5444 "fff.tab.c"
    break;

  case 160: /* ImportOnDemandDeclaration: IMPORT Identifier DOT MULTIPLY SEMICOLON  */
#line 1028 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5450 "fff.tab.c"
    break;

  case 161: /* ImportOnDemandDeclaration: IMPORT ExpressionName DOT MULTIPLY SEMICOLON  */
#line 1029 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5456 "fff.tab.c"
    break;

  case 162: /* StaticImportOnDemandDeclaration: IMPORT STATIC Identifier DOT MULTIPLY SEMICOLON  */
#line 1031 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5462 "fff.tab.c"
    break;

  case 163: /* StaticImportOnDemandDeclaration: IMPORT STATIC ExpressionName DOT MULTIPLY SEMICOLON  */
#line 1032 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5468 "fff.tab.c"
    break;

  case 164: /* TopLevelClassOrInterfaceDeclaration: ClassDeclaration  */
#line 1034 "fff.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5474 "fff.tab.c"
    break;

  case 165: /* TopLevelClassOrInterfaceDeclaration: InterfaceDeclaration  */
#line 1035 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5480 "fff.tab.c"
    break;

  case 166: /* TopLevelClassOrInterfaceDeclaration: SEMICOLON  */
#line 1036 "fff.y"
                                                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5486 "fff.tab.c"
    break;

  case 167: /* $@1: %empty  */
#line 1038 "fff.y"
                                               {symtable*a=createtable();string p=((yyvsp[-1].str));insertclass(p,"module","",a,line);   changescope(a);  }
#line 5492 "fff.tab.c"
    break;

  case 168: /* ModuleDeclaration: MODULE Identifier LCB $@1 RCB  */
#line 1038 "fff.y"
                                                                                                                                                                {goparent();{(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}					}
#line 5498 "fff.tab.c"
    break;

  case 169: /* $@2: %empty  */
#line 1039 "fff.y"
                                        {symtable*a=createtable();string p=((yyvsp[-1].str));insertclass(p,"module","",a,line);   changescope(a);  }
#line 5504 "fff.tab.c"
    break;

  case 170: /* ModuleDeclaration: MODULE Identifier LCB $@2 OMModuleDirective RCB  */
#line 1039 "fff.y"
                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5510 "fff.tab.c"
    break;

  case 171: /* $@3: %empty  */
#line 1040 "fff.y"
                                                        {symtable*a=createtable();string p=((yyvsp[-2].str));insertclass(p+((yyvsp[-1].typeinfo))->name,"module","",a,line);changescope(a);}
#line 5516 "fff.tab.c"
    break;

  case 172: /* ModuleDeclaration: MODULE Identifier OMDotIdentifier LCB $@3 RCB  */
#line 1040 "fff.y"
                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5522 "fff.tab.c"
    break;

  case 173: /* $@4: %empty  */
#line 1041 "fff.y"
                                                         {symtable*a=createtable();string p=((yyvsp[-2].str));insertclass(p+((yyvsp[-1].typeinfo))->name,"module","",a,line);changescope(a);}
#line 5528 "fff.tab.c"
    break;

  case 174: /* ModuleDeclaration: MODULE Identifier OMDotIdentifier LCB $@4 OMModuleDirective RCB  */
#line 1041 "fff.y"
                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5534 "fff.tab.c"
    break;

  case 175: /* $@5: %empty  */
#line 1042 "fff.y"
                                               {symtable*a=createtable();string p=((yyvsp[-1].str));insertclass(p,"module","",a,line);   changescope(a);  }
#line 5540 "fff.tab.c"
    break;

  case 176: /* ModuleDeclaration: OPEN MODULE Identifier LCB $@5 RCB  */
#line 1042 "fff.y"
                                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5546 "fff.tab.c"
    break;

  case 177: /* $@6: %empty  */
#line 1043 "fff.y"
                                              {symtable*a=createtable();string p=((yyvsp[-1].str));insertclass(p,"module","",a,line);}
#line 5552 "fff.tab.c"
    break;

  case 178: /* ModuleDeclaration: OPEN MODULE Identifier LCB $@6 OMModuleDirective RCB  */
#line 1043 "fff.y"
                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5558 "fff.tab.c"
    break;

  case 179: /* $@7: %empty  */
#line 1044 "fff.y"
                                                              {symtable*a=createtable();string p=((yyvsp[-2].str));insertclass(p+((yyvsp[-1].typeinfo))->name,"module","",a,line);changescope(a);}
#line 5564 "fff.tab.c"
    break;

  case 180: /* ModuleDeclaration: OPEN MODULE Identifier OMDotIdentifier LCB $@7 RCB  */
#line 1044 "fff.y"
                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5570 "fff.tab.c"
    break;

  case 181: /* $@8: %empty  */
#line 1045 "fff.y"
                                                              {symtable*a=createtable();string p=((yyvsp[-2].str));insertclass(p+((yyvsp[-1].typeinfo))->name,"module","",a,line);changescope(a);}
#line 5576 "fff.tab.c"
    break;

  case 182: /* ModuleDeclaration: OPEN MODULE Identifier OMDotIdentifier LCB $@8 OMModuleDirective RCB  */
#line 1045 "fff.y"
                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5582 "fff.tab.c"
    break;

  case 183: /* ModuleDirective: REQUIRES ModuleName SEMICOLON  */
#line 1047 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5588 "fff.tab.c"
    break;

  case 184: /* ModuleDirective: REQUIRES OMRequiresModifier ModuleName SEMICOLON  */
#line 1048 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5594 "fff.tab.c"
    break;

  case 185: /* ModuleDirective: EXPORTS Identifier SEMICOLON  */
#line 1049 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5600 "fff.tab.c"
    break;

  case 186: /* ModuleDirective: EXPORTS Identifier TO ModuleName SEMICOLON  */
#line 1050 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5606 "fff.tab.c"
    break;

  case 187: /* ModuleDirective: EXPORTS Identifier TO ModuleName OMCommaModuleName SEMICOLON  */
#line 1051 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5612 "fff.tab.c"
    break;

  case 188: /* ModuleDirective: OPENS Identifier SEMICOLON  */
#line 1052 "fff.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5618 "fff.tab.c"
    break;

  case 189: /* ModuleDirective: OPENS Identifier TO ModuleName SEMICOLON  */
#line 1053 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5624 "fff.tab.c"
    break;

  case 190: /* ModuleDirective: OPENS Identifier TO ModuleName OMCommaModuleName SEMICOLON  */
#line 1054 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5630 "fff.tab.c"
    break;

  case 191: /* ModuleDirective: USES Identifier SEMICOLON  */
#line 1055 "fff.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5636 "fff.tab.c"
    break;

  case 192: /* ModuleDirective: PROVIDES Identifier WITH Identifier SEMICOLON  */
#line 1056 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5642 "fff.tab.c"
    break;

  case 193: /* ModuleDirective: PROVIDES Identifier WITH Identifier OMCommaTypeName SEMICOLON  */
#line 1057 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5648 "fff.tab.c"
    break;

  case 194: /* ModuleDirective: EXPORTS ExpressionName SEMICOLON  */
#line 1058 "fff.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5654 "fff.tab.c"
    break;

  case 195: /* ModuleDirective: EXPORTS ExpressionName TO ModuleName SEMICOLON  */
#line 1059 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-3].typeinfo)->tac;}
#line 5660 "fff.tab.c"
    break;

  case 196: /* ModuleDirective: EXPORTS ExpressionName TO ModuleName OMCommaModuleName SEMICOLON  */
#line 1060 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 5666 "fff.tab.c"
    break;

  case 197: /* ModuleDirective: OPENS ExpressionName SEMICOLON  */
#line 1061 "fff.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5672 "fff.tab.c"
    break;

  case 198: /* ModuleDirective: OPENS ExpressionName TO ModuleName SEMICOLON  */
#line 1062 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-3].typeinfo)->tac;}
#line 5678 "fff.tab.c"
    break;

  case 199: /* ModuleDirective: OPENS ExpressionName TO ModuleName OMCommaModuleName SEMICOLON  */
#line 1063 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 5684 "fff.tab.c"
    break;

  case 200: /* ModuleDirective: USES ExpressionName SEMICOLON  */
#line 1064 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5690 "fff.tab.c"
    break;

  case 201: /* ModuleDirective: PROVIDES ExpressionName WITH ExpressionName SEMICOLON  */
#line 1065 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-3].typeinfo)->tac;}
#line 5696 "fff.tab.c"
    break;

  case 202: /* ModuleDirective: PROVIDES ExpressionName WITH ExpressionName OMCommaTypeName SEMICOLON  */
#line 1066 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 5702 "fff.tab.c"
    break;

  case 203: /* ModuleDirective: PROVIDES ExpressionName WITH Identifier SEMICOLON  */
#line 1067 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-3].typeinfo)->tac;}
#line 5708 "fff.tab.c"
    break;

  case 204: /* ModuleDirective: PROVIDES Identifier WITH ExpressionName OMCommaTypeName SEMICOLON  */
#line 1068 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 5714 "fff.tab.c"
    break;

  case 205: /* ModuleDirective: PROVIDES Identifier WITH ExpressionName SEMICOLON  */
#line 1069 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5720 "fff.tab.c"
    break;

  case 206: /* ModuleDirective: PROVIDES ExpressionName WITH Identifier OMCommaTypeName SEMICOLON  */
#line 1070 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 5726 "fff.tab.c"
    break;

  case 207: /* ClassDeclaration: NormalClassDeclaration  */
#line 1072 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5732 "fff.tab.c"
    break;

  case 208: /* ClassDeclaration: EnumDeclaration  */
#line 1073 "fff.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5738 "fff.tab.c"
    break;

  case 209: /* ClassDeclaration: RecordDeclaration  */
#line 1074 "fff.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5744 "fff.tab.c"
    break;

  case 210: /* $@9: %empty  */
#line 1076 "fff.y"
                                                                                        {symtable*a=createscope("class");string p=((yyvsp[0].str));insertclass(p,"class","",a,line);   changescope(a);  }
#line 5750 "fff.tab.c"
    break;

  case 211: /* NormalClassDeclaration: CLASS Identifier $@9 ClassBody  */
#line 1076 "fff.y"
                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5756 "fff.tab.c"
    break;

  case 212: /* $@10: %empty  */
#line 1077 "fff.y"
                                                                                                {symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5762 "fff.tab.c"
    break;

  case 213: /* NormalClassDeclaration: CLASS Identifier ClassPermits $@10 ClassBody  */
#line 1077 "fff.y"
                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5768 "fff.tab.c"
    break;

  case 214: /* $@11: %empty  */
#line 1078 "fff.y"
                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5774 "fff.tab.c"
    break;

  case 215: /* NormalClassDeclaration: CLASS Identifier ClassImplements $@11 ClassBody  */
#line 1078 "fff.y"
                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5780 "fff.tab.c"
    break;

  case 216: /* $@12: %empty  */
#line 1079 "fff.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5786 "fff.tab.c"
    break;

  case 217: /* NormalClassDeclaration: CLASS Identifier ClassImplements ClassPermits $@12 ClassBody  */
#line 1079 "fff.y"
                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5792 "fff.tab.c"
    break;

  case 218: /* $@13: %empty  */
#line 1080 "fff.y"
                                                                                                { symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5798 "fff.tab.c"
    break;

  case 219: /* NormalClassDeclaration: CLASS Identifier ClassExtends $@13 ClassBody  */
#line 1080 "fff.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5804 "fff.tab.c"
    break;

  case 220: /* $@14: %empty  */
#line 1081 "fff.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5810 "fff.tab.c"
    break;

  case 221: /* NormalClassDeclaration: CLASS Identifier ClassExtends ClassPermits $@14 ClassBody  */
#line 1081 "fff.y"
                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5816 "fff.tab.c"
    break;

  case 222: /* $@15: %empty  */
#line 1082 "fff.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5822 "fff.tab.c"
    break;

  case 223: /* NormalClassDeclaration: CLASS Identifier ClassExtends ClassImplements $@15 ClassBody  */
#line 1082 "fff.y"
                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5828 "fff.tab.c"
    break;

  case 224: /* $@16: %empty  */
#line 1083 "fff.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5834 "fff.tab.c"
    break;

  case 225: /* NormalClassDeclaration: CLASS Identifier ClassExtends ClassImplements ClassPermits $@16 ClassBody  */
#line 1083 "fff.y"
                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5840 "fff.tab.c"
    break;

  case 226: /* $@17: %empty  */
#line 1084 "fff.y"
                                                                                                                { symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5846 "fff.tab.c"
    break;

  case 227: /* NormalClassDeclaration: CLASS Identifier TypeParameters $@17 ClassBody  */
#line 1084 "fff.y"
                                                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5852 "fff.tab.c"
    break;

  case 228: /* $@18: %empty  */
#line 1085 "fff.y"
                                                                                                {symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);     changescope(a);  }
#line 5858 "fff.tab.c"
    break;

  case 229: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassPermits $@18 ClassBody  */
#line 1085 "fff.y"
                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5864 "fff.tab.c"
    break;

  case 230: /* $@19: %empty  */
#line 1086 "fff.y"
                                                                                                {symtable*a=createscope("class");string p=((yyvsp[-2].str)); insertclass(p,"class","",a,line);    changescope(a);  }
#line 5870 "fff.tab.c"
    break;

  case 231: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassImplements $@19 ClassBody  */
#line 1086 "fff.y"
                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5876 "fff.tab.c"
    break;

  case 232: /* $@20: %empty  */
#line 1087 "fff.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5882 "fff.tab.c"
    break;

  case 233: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassImplements ClassPermits $@20 ClassBody  */
#line 1087 "fff.y"
                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5888 "fff.tab.c"
    break;

  case 234: /* $@21: %empty  */
#line 1088 "fff.y"
                                                                                                {symtable*a=createscope("class");string p=((yyvsp[-2].str)); insertclass(p,"class","",a,line);    changescope(a);  }
#line 5894 "fff.tab.c"
    break;

  case 235: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassExtends $@21 ClassBody  */
#line 1088 "fff.y"
                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5900 "fff.tab.c"
    break;

  case 236: /* $@22: %empty  */
#line 1089 "fff.y"
                                                                                {symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);     changescope(a);  }
#line 5906 "fff.tab.c"
    break;

  case 237: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassExtends ClassPermits $@22 ClassBody  */
#line 1089 "fff.y"
                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5912 "fff.tab.c"
    break;

  case 238: /* $@23: %empty  */
#line 1090 "fff.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5918 "fff.tab.c"
    break;

  case 239: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassExtends ClassImplements $@23 ClassBody  */
#line 1090 "fff.y"
                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5924 "fff.tab.c"
    break;

  case 240: /* $@24: %empty  */
#line 1091 "fff.y"
                                                                                            {symtable*a=createscope("class");string p=((yyvsp[-4].str)); insertclass(p,"class","",a,line);    changescope(a);  }
#line 5930 "fff.tab.c"
    break;

  case 241: /* NormalClassDeclaration: CLASS Identifier TypeParameters ClassExtends ClassImplements ClassPermits $@24 ClassBody  */
#line 1091 "fff.y"
                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5936 "fff.tab.c"
    break;

  case 242: /* $@25: %empty  */
#line 1092 "fff.y"
                                                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[0].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5942 "fff.tab.c"
    break;

  case 243: /* NormalClassDeclaration: OMClassModifier CLASS Identifier $@25 ClassBody  */
#line 1092 "fff.y"
                                                                                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5948 "fff.tab.c"
    break;

  case 244: /* $@26: %empty  */
#line 1093 "fff.y"
                                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5954 "fff.tab.c"
    break;

  case 245: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassPermits $@26 ClassBody  */
#line 1093 "fff.y"
                                                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5960 "fff.tab.c"
    break;

  case 246: /* $@27: %empty  */
#line 1094 "fff.y"
                                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-1].str)); insertclass(p,"class","",a,line);    changescope(a);  }
#line 5966 "fff.tab.c"
    break;

  case 247: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassImplements $@27 ClassBody  */
#line 1094 "fff.y"
                                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5972 "fff.tab.c"
    break;

  case 248: /* $@28: %empty  */
#line 1095 "fff.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5978 "fff.tab.c"
    break;

  case 249: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassImplements ClassPermits $@28 ClassBody  */
#line 1095 "fff.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5984 "fff.tab.c"
    break;

  case 250: /* $@29: %empty  */
#line 1096 "fff.y"
                                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 5990 "fff.tab.c"
    break;

  case 251: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassExtends $@29 ClassBody  */
#line 1096 "fff.y"
                                                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5996 "fff.tab.c"
    break;

  case 252: /* $@30: %empty  */
#line 1097 "fff.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 6002 "fff.tab.c"
    break;

  case 253: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassExtends ClassPermits $@30 ClassBody  */
#line 1097 "fff.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6008 "fff.tab.c"
    break;

  case 254: /* $@31: %empty  */
#line 1098 "fff.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 6014 "fff.tab.c"
    break;

  case 255: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassExtends ClassImplements $@31 ClassBody  */
#line 1098 "fff.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6020 "fff.tab.c"
    break;

  case 256: /* $@32: %empty  */
#line 1099 "fff.y"
                                                                                            { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 6026 "fff.tab.c"
    break;

  case 257: /* NormalClassDeclaration: OMClassModifier CLASS Identifier ClassExtends ClassImplements ClassPermits $@32 ClassBody  */
#line 1099 "fff.y"
                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6032 "fff.tab.c"
    break;

  case 258: /* $@33: %empty  */
#line 1100 "fff.y"
                                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-1].str)); insertclass(p,"class","",a,line);    changescope(a);  }
#line 6038 "fff.tab.c"
    break;

  case 259: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters $@33 ClassBody  */
#line 1100 "fff.y"
                                                                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6044 "fff.tab.c"
    break;

  case 260: /* $@34: %empty  */
#line 1101 "fff.y"
                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 6050 "fff.tab.c"
    break;

  case 261: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassPermits $@34 ClassBody  */
#line 1101 "fff.y"
                                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6056 "fff.tab.c"
    break;

  case 262: /* $@35: %empty  */
#line 1102 "fff.y"
                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-2].str)); insertclass(p,"class","",a,line);    changescope(a);  }
#line 6062 "fff.tab.c"
    break;

  case 263: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassImplements $@35 ClassBody  */
#line 1102 "fff.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6068 "fff.tab.c"
    break;

  case 264: /* $@36: %empty  */
#line 1103 "fff.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 6074 "fff.tab.c"
    break;

  case 265: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassImplements ClassPermits $@36 ClassBody  */
#line 1103 "fff.y"
                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6080 "fff.tab.c"
    break;

  case 266: /* $@37: %empty  */
#line 1104 "fff.y"
                                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);     changescope(a);  }
#line 6086 "fff.tab.c"
    break;

  case 267: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassExtends $@37 ClassBody  */
#line 1104 "fff.y"
                                                                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6092 "fff.tab.c"
    break;

  case 268: /* $@38: %empty  */
#line 1105 "fff.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 6098 "fff.tab.c"
    break;

  case 269: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassPermits $@38 ClassBody  */
#line 1105 "fff.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6104 "fff.tab.c"
    break;

  case 270: /* $@39: %empty  */
#line 1106 "fff.y"
                                                                                                        { symtable*a=createtable();string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 6110 "fff.tab.c"
    break;

  case 271: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassImplements $@39 ClassBody  */
#line 1106 "fff.y"
                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6116 "fff.tab.c"
    break;

  case 272: /* $@40: %empty  */
#line 1107 "fff.y"
                                                                                                             { symtable*a=createscope("class");string p=((yyvsp[-4].str));insertclass(p,"class","",a,line);    changescope(a);  }
#line 6122 "fff.tab.c"
    break;

  case 273: /* NormalClassDeclaration: OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassImplements ClassPermits $@40 ClassBody  */
#line 1107 "fff.y"
                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6128 "fff.tab.c"
    break;

  case 274: /* TypeParameters: LT TypeParameterList GT  */
#line 1109 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6134 "fff.tab.c"
    break;

  case 275: /* TypeParameterList: TypeParameter  */
#line 1111 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6140 "fff.tab.c"
    break;

  case 276: /* TypeParameterList: TypeParameter OMCommaTypeParameter  */
#line 1112 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6146 "fff.tab.c"
    break;

  case 277: /* ClassExtends: EXTENDS Identifier  */
#line 1114 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6152 "fff.tab.c"
    break;

  case 278: /* ClassImplements: IMPLEMENTS InterfaceTypeList  */
#line 1116 "fff.y"
                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6158 "fff.tab.c"
    break;

  case 279: /* InterfaceTypeList: Identifier  */
#line 1118 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6164 "fff.tab.c"
    break;

  case 280: /* InterfaceTypeList: Identifier OMCommaInterfaceType  */
#line 1119 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6170 "fff.tab.c"
    break;

  case 281: /* ClassPermits: PERMITS Identifier  */
#line 1122 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6176 "fff.tab.c"
    break;

  case 282: /* ClassPermits: PERMITS ExpressionName  */
#line 1123 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6182 "fff.tab.c"
    break;

  case 283: /* ClassPermits: PERMITS Identifier OMCommaTypeName  */
#line 1124 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6188 "fff.tab.c"
    break;

  case 284: /* ClassPermits: PERMITS ExpressionName OMCommaTypeName  */
#line 1125 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6194 "fff.tab.c"
    break;

  case 285: /* ClassBody: LCB RCB  */
#line 1127 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6200 "fff.tab.c"
    break;

  case 286: /* ClassBody: LCB OMClassBodyDeclaration RCB  */
#line 1128 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6206 "fff.tab.c"
    break;

  case 287: /* ClassBodyDeclaration: ClassMemberDeclaration  */
#line 1130 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6212 "fff.tab.c"
    break;

  case 288: /* ClassBodyDeclaration: InstanceInitializer  */
#line 1131 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6218 "fff.tab.c"
    break;

  case 289: /* ClassBodyDeclaration: StaticInitializer  */
#line 1132 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6224 "fff.tab.c"
    break;

  case 290: /* ClassBodyDeclaration: ConstructorDeclaration  */
#line 1133 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6230 "fff.tab.c"
    break;

  case 291: /* ClassMemberDeclaration: FieldDeclaration  */
#line 1135 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6236 "fff.tab.c"
    break;

  case 292: /* ClassMemberDeclaration: MethodDeclaration  */
#line 1136 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6242 "fff.tab.c"
    break;

  case 293: /* ClassMemberDeclaration: ClassDeclaration  */
#line 1137 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6248 "fff.tab.c"
    break;

  case 294: /* ClassMemberDeclaration: InterfaceDeclaration  */
#line 1138 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6254 "fff.tab.c"
    break;

  case 295: /* ClassMemberDeclaration: SEMICOLON  */
#line 1139 "fff.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6260 "fff.tab.c"
    break;

  case 296: /* FieldDeclaration: UnannType VariableDeclaratorList SEMICOLON  */
#line 1143 "fff.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->variables=((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type=((yyvsp[-2].typeinfo))->type+((yyvsp[-1].typeinfo))->type;for(auto z:((yyval.typeinfo))->variables)insertidentifier(z,((yyval.typeinfo))->type,"",line);((yyval.typeinfo))->puvariables=((yyvsp[-1].typeinfo))->puvariables;vector<string> s = pushlocal(((yyvsp[-1].typeinfo))->puvariables); (yyval.typeinfo)->tac=concvector(s,(yyvsp[-1].typeinfo)->tac);}
#line 6266 "fff.tab.c"
    break;

  case 297: /* FieldDeclaration: OMClassModifier UnannType VariableDeclaratorList SEMICOLON  */
#line 1144 "fff.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->variables=((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type=((yyvsp[-2].typeinfo))->type+((yyvsp[-1].typeinfo))->type;for(auto z:((yyval.typeinfo))->variables)insertidentifier(z,((yyval.typeinfo))->type,"",line);((yyval.typeinfo))->puvariables=((yyvsp[-1].typeinfo))->puvariables;vector<string> s = pushlocal(((yyvsp[-1].typeinfo))->puvariables); (yyval.typeinfo)->tac=concvector(s,(yyvsp[-1].typeinfo)->tac);}
#line 6272 "fff.tab.c"
    break;

  case 298: /* VariableDeclaratorList: VariableDeclarator  */
#line 1146 "fff.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->variables.push_back((yyvsp[0].typeinfo)->variable);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->decorders2.push_back(((yyvsp[0].typeinfo))->decorder2);(yyval.typeinfo)->arrtypes.push_back((yyvsp[0].typeinfo)->arrtype);(yyval.typeinfo)->arrdims.push_back((yyvsp[0].typeinfo)->arrdim);(yyval.typeinfo)->initialdecls.push_back((yyvsp[0].typeinfo)->initialdecl);(yyval.typeinfo)->initvartypes.push_back((yyvsp[0].typeinfo)->initvartype);((yyval.typeinfo))->puvariables = ((yyvsp[0].typeinfo))->puvariables;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6278 "fff.tab.c"
    break;

  case 299: /* VariableDeclaratorList: VariableDeclaratorList COMMA VariableDeclarator  */
#line 1147 "fff.y"
                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-2].typeinfo);((yyval.typeinfo))->variables.push_back((yyvsp[0].typeinfo)->variable);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->decorders2.push_back(((yyvsp[0].typeinfo))->decorder2);(yyval.typeinfo)->arrtypes.push_back((yyvsp[0].typeinfo)->arrtype);(yyval.typeinfo)->arrdims.push_back((yyvsp[0].typeinfo)->arrdim);(yyval.typeinfo)->initialdecls.push_back((yyvsp[0].typeinfo)->initialdecl);(yyval.typeinfo)->initvartypes.push_back((yyvsp[0].typeinfo)->initvartype);vector<string>a=((yyvsp[-2].typeinfo))->puvariables;vector<string>b=((yyvsp[0].typeinfo))->puvariables;for(auto z:a){((yyval.typeinfo))->puvariables.push_back(z);}for(auto z:b){((yyval.typeinfo))->puvariables.push_back(z);} (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6284 "fff.tab.c"
    break;

  case 300: /* VariableDeclarator: VariableDeclaratorId  */
#line 1149 "fff.y"
                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->initialdecl=false;((yyval.typeinfo))->puvariables = ((yyvsp[0].typeinfo))->puvariables;(yyval.typeinfo)->tac=emptyvector();}
#line 6290 "fff.tab.c"
    break;

  case 301: /* VariableDeclarator: VariableDeclaratorId EQUAL VariableInitializer  */
#line 1150 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-2].typeinfo);(yyval.typeinfo)->initialdecl=true;(yyval.typeinfo)->arrtype=(yyvsp[0].typeinfo)->arrtype;(yyval.typeinfo)->arrdim=(yyvsp[0].typeinfo)->arrdim;(yyval.typeinfo)->initvartype=(yyvsp[0].typeinfo)->initvartype;string c=(yyvsp[-2].typeinfo)->tempname+"="+(yyvsp[0].typeinfo)->tempname;((yyval.typeinfo))->puvariables = ((yyvsp[-2].typeinfo))->puvariables;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,c);}
#line 6296 "fff.tab.c"
    break;

  case 302: /* VariableDeclaratorId: Identifier  */
#line 1152 "fff.y"
                                                                                                                {(yyval.typeinfo) = createstruct();string p=((yyvsp[0].str));(yyval.typeinfo)->variable=p;(yyval.typeinfo)->decorder2=0;string x=(yyvsp[0].str);(yyval.typeinfo)->tempname=x;((yyval.typeinfo))->puvariables.push_back(x);}
#line 6302 "fff.tab.c"
    break;

  case 303: /* VariableDeclaratorId: Identifier OMPSB  */
#line 1153 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();string p=((yyvsp[-1].str));(yyval.typeinfo)->variable=p;(yyval.typeinfo)->decorder2=(yyvsp[0].typeinfo)->order;string x=(yyvsp[-1].str);(yyval.typeinfo)->tempname=x;((yyval.typeinfo))->puvariables.push_back(x);}
#line 6308 "fff.tab.c"
    break;

  case 304: /* VariableInitializer: Expression  */
#line 1156 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 6314 "fff.tab.c"
    break;

  case 305: /* VariableInitializer: ArrayInitializer  */
#line 1157 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->arrtype=(yyvsp[0].typeinfo)->arrtype;(yyval.typeinfo)->arrdim=(yyvsp[0].typeinfo)->arrdim;(yyval.typeinfo)->initvartype="";}
#line 6320 "fff.tab.c"
    break;

  case 306: /* UnannType: UnannPrimitiveType  */
#line 1159 "fff.y"
                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->dectype=(yyvsp[0].typeinfo)->type;(yyvsp[0].typeinfo)->decorder1=0;}
#line 6326 "fff.tab.c"
    break;

  case 307: /* UnannType: Identifier  */
#line 1160 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();string p = (yyvsp[0].str);((yyval.typeinfo))->type = p;(yyval.typeinfo)->tempname=p;(yyval.typeinfo)->decorder1=0; (yyval.typeinfo)->dectype="";}
#line 6332 "fff.tab.c"
    break;

  case 308: /* UnannType: UnannArrayType  */
#line 1161 "fff.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type=((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->dectype=(yyvsp[0].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[0].typeinfo)->decorder1;}
#line 6338 "fff.tab.c"
    break;

  case 309: /* UnannPrimitiveType: NumericType  */
#line 1163 "fff.y"
                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=emptyvector();}
#line 6344 "fff.tab.c"
    break;

  case 310: /* UnannPrimitiveType: BOOLEAN  */
#line 1164 "fff.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";(yyval.typeinfo)->tac=emptyvector();}
#line 6350 "fff.tab.c"
    break;

  case 311: /* UnannArrayType: UnannPrimitiveType OMPSB  */
#line 1166 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type + ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->dectype=(yyvsp[-1].typeinfo)->type;(yyval.typeinfo)->decorder1=(yyvsp[0].typeinfo)->order;(yyval.typeinfo)->tac=emptyvector();}
#line 6356 "fff.tab.c"
    break;

  case 312: /* UnannArrayType: Identifier OMPSB  */
#line 1167 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();string p = (yyvsp[-1].str);((yyval.typeinfo))->type = p + ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=emptyvector();}
#line 6362 "fff.tab.c"
    break;

  case 313: /* MethodDeclaration: MethodHeader MethodBody  */
#line 1170 "fff.y"
                                                                {goparent();insertmethod(((yyvsp[-1].typeinfo))->variables[0],"Method",((yyvsp[-1].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-1].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-1].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="function end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z,sv,p);}
#line 6368 "fff.tab.c"
    break;

  case 314: /* MethodDeclaration: OMClassModifier MethodHeader MethodBody  */
#line 1171 "fff.y"
                                                                                {goparent();insertmethod(((yyvsp[-1].typeinfo))->variables[0],"Method",((yyvsp[-1].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-1].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="function end"; stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st); 	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z,sv,p);}
#line 6374 "fff.tab.c"
    break;

  case 315: /* MethodHeader: Result MethodDeclarator  */
#line 1173 "fff.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;((yyval.typeinfo))->variables = ((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;((yyval.typeinfo))->scope =((yyvsp[-1].typeinfo))->scope;((yyval.typeinfo))->linep = ((yyvsp[0].typeinfo))->linep;(yyval.typeinfo)->tempname=((yyvsp[-1].typeinfo))->tempname; string f = ((yyvsp[-1].typeinfo))->tempname; string q=newmethodlabel(f);string p="call "+((yyvsp[-1].typeinfo))->tempname+"\n"+q;(yyval.typeinfo)->tac=concvector(p,(yyvsp[0].typeinfo)->tac);}
#line 6380 "fff.tab.c"
    break;

  case 316: /* MethodHeader: Result MethodDeclarator Throws  */
#line 1174 "fff.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;((yyval.typeinfo))->variables = ((yyvsp[-2].typeinfo))->variables;((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;((yyval.typeinfo))->scope =((yyvsp[-2].typeinfo))->scope;((yyval.typeinfo))->linep = ((yyvsp[-1].typeinfo))->linep;(yyval.typeinfo)->tempname=((yyvsp[-2].typeinfo))->tempname; string f = ((yyvsp[-2].typeinfo))->tempname; string q=newmethodlabel(f);string p="call "+((yyvsp[-2].typeinfo))->tempname+"\n"+q; (yyval.typeinfo)->tac=concvector(p,(yyvsp[-1].typeinfo)->tac);}
#line 6386 "fff.tab.c"
    break;

  case 317: /* MethodHeader: TypeParameters Result MethodDeclarator  */
#line 1175 "fff.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;((yyval.typeinfo))->variables = ((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;((yyval.typeinfo))->scope =((yyvsp[-1].typeinfo))->scope;((yyval.typeinfo))->linep = ((yyvsp[0].typeinfo))->linep;(yyval.typeinfo)->tempname=((yyvsp[-1].typeinfo))->tempname; string f = ((yyvsp[-1].typeinfo))->tempname; string q=newmethodlabel(f);string p="call "+((yyvsp[-1].typeinfo))->tempname+"\n"+q; (yyval.typeinfo)->tac=concvector(p,(yyvsp[0].typeinfo)->tac);}
#line 6392 "fff.tab.c"
    break;

  case 318: /* MethodHeader: TypeParameters Result MethodDeclarator Throws  */
#line 1176 "fff.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;((yyval.typeinfo))->variables = ((yyvsp[-2].typeinfo))->variables;((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;((yyval.typeinfo))->scope =((yyvsp[-2].typeinfo))->scope;((yyval.typeinfo))->linep = ((yyvsp[-1].typeinfo))->linep;(yyval.typeinfo)->tempname=((yyvsp[-2].typeinfo))->tempname; string f = ((yyvsp[-2].typeinfo))->tempname; string q=newmethodlabel(f);string p="call "+((yyvsp[-2].typeinfo))->tempname+"\n"+q; (yyval.typeinfo)->tac=concvector(p,(yyvsp[-1].typeinfo)->tac);}
#line 6398 "fff.tab.c"
    break;

  case 319: /* Result: UnannType Identifier  */
#line 1178 "fff.y"
                                                                                        {(yyval.typeinfo) = createstruct();symtable*a = createscope("Method");((yyval.typeinfo))->scope = a; ((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;string p = (yyvsp[0].str);((yyval.typeinfo))->variables.push_back(p); changescope(a);string x=(yyvsp[0].str); (yyval.typeinfo)->tempname=x;(yyval.typeinfo)->tac=emptyvector();}
#line 6404 "fff.tab.c"
    break;

  case 320: /* Result: VOID Identifier  */
#line 1179 "fff.y"
                                                                                                        {(yyval.typeinfo) = createstruct();symtable*a = createscope("Method");((yyval.typeinfo))->scope = a;((yyval.typeinfo))->type = "void";string p = (yyvsp[0].str);((yyval.typeinfo))->variables.push_back(p); changescope(a);string x=(yyvsp[0].str); (yyval.typeinfo)->tempname=x;(yyval.typeinfo)->tac=emptyvector();}
#line 6410 "fff.tab.c"
    break;

  case 321: /* MethodDeclarator: LRB RRB  */
#line 1182 "fff.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back("void");((yyval.typeinfo))->linep = line; (yyval.typeinfo)->tac=emptyvector();}
#line 6416 "fff.tab.c"
    break;

  case 322: /* MethodDeclarator: LRB RRB OMPSB  */
#line 1183 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct(); (yyval.typeinfo)->tac=emptyvector();}
#line 6422 "fff.tab.c"
    break;

  case 323: /* MethodDeclarator: LRB FormalParameterList RRB  */
#line 1184 "fff.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;((yyval.typeinfo))->linep = line;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6428 "fff.tab.c"
    break;

  case 324: /* MethodDeclarator: LRB FormalParameterList RRB OMPSB  */
#line 1185 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 6434 "fff.tab.c"
    break;

  case 325: /* MethodDeclarator: LRB ReceiverParameterComma RRB  */
#line 1186 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6440 "fff.tab.c"
    break;

  case 326: /* MethodDeclarator: LRB ReceiverParameterComma RRB OMPSB  */
#line 1187 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 6446 "fff.tab.c"
    break;

  case 327: /* MethodDeclarator: LRB ReceiverParameterComma FormalParameterList RRB  */
#line 1188 "fff.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;((yyval.typeinfo))->linep = line;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6452 "fff.tab.c"
    break;

  case 328: /* MethodDeclarator: LRB ReceiverParameterComma FormalParameterList RRB OMPSB  */
#line 1189 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 6458 "fff.tab.c"
    break;

  case 329: /* ReceiverParameter: UnannType THIS  */
#line 1191 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6464 "fff.tab.c"
    break;

  case 330: /* ReceiverParameter: UnannType IdentifierDot THIS  */
#line 1192 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6470 "fff.tab.c"
    break;

  case 331: /* FormalParameterList: FormalParameter  */
#line 1194 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6476 "fff.tab.c"
    break;

  case 332: /* FormalParameterList: FormalParameter OMCommaFormalParameter  */
#line 1195 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();vector<string>a=((yyvsp[-1].typeinfo))->type_variable;vector<string>b=((yyvsp[0].typeinfo))->type_variable;for(auto z:a){((yyval.typeinfo))->type_variable.push_back(z);}for(auto z:b){((yyval.typeinfo))->type_variable.push_back(z);}(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6482 "fff.tab.c"
    break;

  case 333: /* FormalParameter: UnannType VariableDeclaratorId  */
#line 1197 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-1].typeinfo))->type+((yyvsp[0].typeinfo))->type);((yyval.typeinfo))->type=((yyvsp[-1].typeinfo))->type+((yyvsp[0].typeinfo))->type;for(auto z:((yyvsp[0].typeinfo))->variables)insertidentifier(z,((yyval.typeinfo))->type,"",line);(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6488 "fff.tab.c"
    break;

  case 334: /* FormalParameter: OMClassModifier UnannType VariableDeclaratorId  */
#line 1198 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-1].typeinfo))->type+((yyvsp[0].typeinfo))->type);((yyval.typeinfo))->type=((yyvsp[-1].typeinfo))->type+((yyvsp[0].typeinfo))->type;for(auto z:((yyvsp[0].typeinfo))->variables)insertidentifier(z,((yyval.typeinfo))->type,"",line);(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6494 "fff.tab.c"
    break;

  case 335: /* FormalParameter: VariableArityParameter  */
#line 1199 "fff.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6500 "fff.tab.c"
    break;

  case 336: /* VariableArityParameter: UnannType THREEDOT Identifier  */
#line 1201 "fff.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-2].typeinfo))->type);(yyval.typeinfo)->tac=emptyvector();}
#line 6506 "fff.tab.c"
    break;

  case 337: /* VariableArityParameter: OMClassModifier UnannType THREEDOT Identifier  */
#line 1202 "fff.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-2].typeinfo))->type);(yyval.typeinfo)->tac=emptyvector();}
#line 6512 "fff.tab.c"
    break;

  case 338: /* Throws: THROWS ExceptionTypeList  */
#line 1204 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6518 "fff.tab.c"
    break;

  case 339: /* ExceptionTypeList: ExceptionType  */
#line 1206 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6524 "fff.tab.c"
    break;

  case 340: /* ExceptionTypeList: ExceptionType OMCommaExceptionType  */
#line 1207 "fff.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6530 "fff.tab.c"
    break;

  case 341: /* ExceptionType: Identifier  */
#line 1209 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6536 "fff.tab.c"
    break;

  case 342: /* MethodBody: Block  */
#line 1212 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6542 "fff.tab.c"
    break;

  case 343: /* MethodBody: SEMICOLON  */
#line 1213 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6548 "fff.tab.c"
    break;

  case 344: /* InstanceInitializer: Block  */
#line 1215 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6554 "fff.tab.c"
    break;

  case 345: /* StaticInitializer: STATIC Block  */
#line 1217 "fff.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6560 "fff.tab.c"
    break;

  case 346: /* ConstructorDeclaration: ConstructorDeclarator ConstructorBody  */
#line 1220 "fff.y"
                                                                                {goparent();insertmethod(((yyvsp[-1].typeinfo))->variables[0],"constructor",((yyvsp[-1].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-1].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-1].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z,sv,p);}
#line 6566 "fff.tab.c"
    break;

  case 347: /* ConstructorDeclaration: ConstructorDeclarator Throws ConstructorBody  */
#line 1221 "fff.y"
                                                                                        {goparent();insertmethod(((yyvsp[-2].typeinfo))->variables[0],"constructor",((yyvsp[-2].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-2].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z,sv,p);}
#line 6572 "fff.tab.c"
    break;

  case 348: /* ConstructorDeclaration: OMClassModifier ConstructorDeclarator ConstructorBody  */
#line 1222 "fff.y"
                                                                                        {goparent();insertmethod(((yyvsp[-1].typeinfo))->variables[0],"constructor",((yyvsp[-1].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-1].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-1].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z,sv,p);}
#line 6578 "fff.tab.c"
    break;

  case 349: /* ConstructorDeclaration: OMClassModifier ConstructorDeclarator Throws ConstructorBody  */
#line 1223 "fff.y"
                                                                                {goparent();insertmethod(((yyvsp[-2].typeinfo))->variables[0],"constructor",((yyvsp[-2].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-2].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z,sv,p);}
#line 6584 "fff.tab.c"
    break;

  case 350: /* ConstructorDeclaratorLRBSym: LRB  */
#line 1225 "fff.y"
                                 {(yyval.typeinfo) = createstruct();symtable*a = createscope("constructor");((yyval.typeinfo))->scope = a; changescope(a);}
#line 6590 "fff.tab.c"
    break;

  case 351: /* ConstructorDeclarator: Identifier ConstructorDeclaratorLRBSym RRB  */
#line 1227 "fff.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->scope = ((yyvsp[-1].typeinfo))->scope; ((yyval.typeinfo))->type_variable.push_back("void");string p = (yyvsp[-2].str);((yyval.typeinfo))->variables.push_back(p);((yyval.typeinfo))->type = "void";((yyval.typeinfo))->linep = line;string x = (yyvsp[-2].str);(yyval.typeinfo)->tempname=x;  string q=newmethodlabel(x);string g="call "+x+"\n"+q;(yyval.typeinfo)->tac=concvector(g);}
#line 6596 "fff.tab.c"
    break;

  case 352: /* ConstructorDeclarator: Identifier ConstructorDeclaratorLRBSym FormalParameterList RRB  */
#line 1228 "fff.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->scope = ((yyvsp[-2].typeinfo))->scope;((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;string p = (yyvsp[-3].str);((yyval.typeinfo))->variables.push_back(p);((yyval.typeinfo))->type = "void";((yyval.typeinfo))->linep = line;string x = (yyvsp[-3].str);(yyval.typeinfo)->tempname=x;  string q=newmethodlabel(x);string g="call "+x+"\n"+q;(yyval.typeinfo)->tac=concvector(g,(yyvsp[-1].typeinfo)->tac);}
#line 6602 "fff.tab.c"
    break;

  case 353: /* ConstructorDeclarator: Identifier LRB ReceiverParameterComma RRB  */
#line 1229 "fff.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=emptyvector();}
#line 6608 "fff.tab.c"
    break;

  case 354: /* ConstructorDeclarator: Identifier LRB ReceiverParameterComma FormalParameterList RRB  */
#line 1230 "fff.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6614 "fff.tab.c"
    break;

  case 355: /* ConstructorDeclarator: TypeParameters Identifier ConstructorDeclaratorLRBSym RRB  */
#line 1231 "fff.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->scope = ((yyvsp[-1].typeinfo))->scope;((yyval.typeinfo))->type_variable.push_back("void");string p = (yyvsp[-2].str); ((yyval.typeinfo))->variables.push_back(p);((yyval.typeinfo))->type = "void";((yyval.typeinfo))->linep = line;string x = (yyvsp[-2].str);(yyval.typeinfo)->tempname=x;  string q=newmethodlabel(x);string g="call "+x+"\n"+q;(yyval.typeinfo)->tac=concvector(g);}
#line 6620 "fff.tab.c"
    break;

  case 356: /* ConstructorDeclarator: TypeParameters Identifier ConstructorDeclaratorLRBSym FormalParameterList RRB  */
#line 1232 "fff.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->scope = ((yyvsp[-2].typeinfo))->scope;((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;string p = (yyvsp[-3].str);((yyval.typeinfo))->variables.push_back(p);((yyval.typeinfo))->type = "void";((yyval.typeinfo))->linep = line;string x = (yyvsp[-3].str);(yyval.typeinfo)->tempname=x;  string q=newmethodlabel(x);string g="call "+x+"\n"+q;(yyval.typeinfo)->tac=concvector(g,(yyvsp[-1].typeinfo)->tac);}
#line 6626 "fff.tab.c"
    break;

  case 357: /* ConstructorDeclarator: TypeParameters Identifier LRB ReceiverParameterComma RRB  */
#line 1233 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6632 "fff.tab.c"
    break;

  case 358: /* ConstructorDeclarator: TypeParameters Identifier LRB ReceiverParameterComma FormalParameterList RRB  */
#line 1234 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 6638 "fff.tab.c"
    break;

  case 359: /* ConstructorBody: LCB RCB  */
#line 1237 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6644 "fff.tab.c"
    break;

  case 360: /* ConstructorBody: LCB BlockStatements RCB  */
#line 1238 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6650 "fff.tab.c"
    break;

  case 361: /* ConstructorBody: LCB ExplicitConstructorInvocation RCB  */
#line 1239 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6656 "fff.tab.c"
    break;

  case 362: /* ConstructorBody: LCB ExplicitConstructorInvocation BlockStatements RCB  */
#line 1240 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 6662 "fff.tab.c"
    break;

  case 363: /* ExplicitConstructorInvocation: THIS LRB RRB SEMICOLON  */
#line 1242 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters();string s = ((yyvsp[-3].str));((yyval.typeinfo))->tempname = "%rax";string s1 = gotomethod(s);string s2 = newmethodretlabel(s); (yyval.typeinfo)->tac=concvector(pv1,s1,s2,pv2);}
#line 6668 "fff.tab.c"
    break;

  case 364: /* ExplicitConstructorInvocation: THIS LRB ArgumentList RRB SEMICOLON  */
#line 1243 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters(); string s = ((yyvsp[-4].str));((yyval.typeinfo))->tempname = "%rax"; string s1 = gotomethod(s);string s2 = newmethodretlabel(s);vector<string> pushpar = pusharg(((yyvsp[-2].typeinfo))->params);(yyval.typeinfo)->tac=concvector(pv1,(yyvsp[-2].typeinfo)->tac,pushpar,s1,s2,pv2);}
#line 6674 "fff.tab.c"
    break;

  case 365: /* ExplicitConstructorInvocation: SUPER LRB RRB SEMICOLON  */
#line 1244 "fff.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6680 "fff.tab.c"
    break;

  case 366: /* ExplicitConstructorInvocation: SUPER LRB ArgumentList RRB SEMICOLON  */
#line 1245 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 6686 "fff.tab.c"
    break;

  case 367: /* ExplicitConstructorInvocation: Identifier DOT SUPER LRB RRB SEMICOLON  */
#line 1246 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6692 "fff.tab.c"
    break;

  case 368: /* ExplicitConstructorInvocation: Identifier DOT SUPER LRB ArgumentList RRB SEMICOLON  */
#line 1247 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 6698 "fff.tab.c"
    break;

  case 369: /* ExplicitConstructorInvocation: ExpressionName DOT SUPER LRB RRB SEMICOLON  */
#line 1248 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6704 "fff.tab.c"
    break;

  case 370: /* ExplicitConstructorInvocation: ExpressionName DOT SUPER LRB ArgumentList RRB SEMICOLON  */
#line 1249 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 6710 "fff.tab.c"
    break;

  case 371: /* ExplicitConstructorInvocation: Primary DOT SUPER LRB RRB SEMICOLON  */
#line 1250 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6716 "fff.tab.c"
    break;

  case 372: /* ExplicitConstructorInvocation: Primary DOT SUPER LRB ArgumentList RRB SEMICOLON  */
#line 1251 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 6722 "fff.tab.c"
    break;

  case 373: /* EnumDeclaration: ENUM Identifier EnumBody  */
#line 1253 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6728 "fff.tab.c"
    break;

  case 374: /* EnumDeclaration: ENUM Identifier ClassImplements EnumBody  */
#line 1254 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6734 "fff.tab.c"
    break;

  case 375: /* EnumDeclaration: OMClassModifier ENUM Identifier EnumBody  */
#line 1255 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6740 "fff.tab.c"
    break;

  case 376: /* EnumDeclaration: OMClassModifier ENUM Identifier ClassImplements EnumBody  */
#line 1256 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6746 "fff.tab.c"
    break;

  case 377: /* EnumBody: LCB RCB  */
#line 1259 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6752 "fff.tab.c"
    break;

  case 378: /* EnumBody: LCB EnumBodyDeclarations RCB  */
#line 1260 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6758 "fff.tab.c"
    break;

  case 379: /* EnumBody: LCB COMMA RCB  */
#line 1261 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6764 "fff.tab.c"
    break;

  case 380: /* EnumBody: LCB COMMA EnumBodyDeclarations RCB  */
#line 1262 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6770 "fff.tab.c"
    break;

  case 381: /* EnumBody: LCB EnumConstantList RCB  */
#line 1263 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6776 "fff.tab.c"
    break;

  case 382: /* EnumBody: LCB EnumConstantList EnumBodyDeclarations RCB  */
#line 1264 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 6782 "fff.tab.c"
    break;

  case 383: /* EnumConstantList: EnumConstant  */
#line 1266 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6788 "fff.tab.c"
    break;

  case 384: /* EnumConstantList: OMCommaEnumConstant  */
#line 1267 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6794 "fff.tab.c"
    break;

  case 385: /* PRB: LRB RRB  */
#line 1269 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6800 "fff.tab.c"
    break;

  case 386: /* PRBArgumentList: LRB ArgumentList RRB  */
#line 1271 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6806 "fff.tab.c"
    break;

  case 387: /* EnumConstant: Identifier  */
#line 1273 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6812 "fff.tab.c"
    break;

  case 388: /* EnumConstant: Identifier PRB  */
#line 1274 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6818 "fff.tab.c"
    break;

  case 389: /* EnumConstant: Identifier PRBArgumentList  */
#line 1275 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6824 "fff.tab.c"
    break;

  case 390: /* EnumConstant: Identifier ClassBody  */
#line 1276 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6830 "fff.tab.c"
    break;

  case 391: /* EnumConstant: Identifier PRB ClassBody  */
#line 1277 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6836 "fff.tab.c"
    break;

  case 392: /* EnumConstant: Identifier PRBArgumentList ClassBody  */
#line 1278 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6842 "fff.tab.c"
    break;

  case 393: /* EnumBodyDeclarations: SEMICOLON  */
#line 1280 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6848 "fff.tab.c"
    break;

  case 394: /* EnumBodyDeclarations: SEMICOLON OMClassBodyDeclaration  */
#line 1281 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6854 "fff.tab.c"
    break;

  case 395: /* RecordDeclarationSym: RECORD Identifier  */
#line 1283 "fff.y"
                                        {(yyval.typeinfo) = createstruct();symtable*a=createscope("record");((yyval.typeinfo))->scope = a; ((yyval.typeinfo))->type = "record";string p = (yyvsp[0].str);((yyval.typeinfo))->variables.push_back(p); changescope(a);}
#line 6860 "fff.tab.c"
    break;

  case 396: /* RecordDeclaration: RecordDeclarationSym RecordHeader RecordBody  */
#line 1285 "fff.y"
                                                                                                        {goparent();insertmethod(((yyvsp[-2].typeinfo))->variables[0],"record",((yyvsp[-2].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6866 "fff.tab.c"
    break;

  case 397: /* RecordDeclaration: RecordDeclarationSym RecordHeader ClassImplements RecordBody  */
#line 1286 "fff.y"
                                                                                                                        {goparent();insertmethod(((yyvsp[-3].typeinfo))->variables[0],"record",((yyvsp[-3].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-3].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6872 "fff.tab.c"
    break;

  case 398: /* RecordDeclaration: RecordDeclarationSym TypeParameters RecordHeader RecordBody  */
#line 1287 "fff.y"
                                                                                                                                                        {goparent();insertmethod(((yyvsp[-3].typeinfo))->variables[0],"record",((yyvsp[-3].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-3].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6878 "fff.tab.c"
    break;

  case 399: /* RecordDeclaration: RecordDeclarationSym TypeParameters RecordHeader ClassImplements RecordBody  */
#line 1288 "fff.y"
                                                                                                                        {goparent();insertmethod(((yyvsp[-4].typeinfo))->variables[0],"record",((yyvsp[-4].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-4].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6884 "fff.tab.c"
    break;

  case 400: /* RecordDeclaration: OMClassModifier RecordDeclarationSym RecordHeader RecordBody  */
#line 1289 "fff.y"
                                                                                                                                                        {goparent();insertmethod(((yyvsp[-2].typeinfo))->variables[0],"record",((yyvsp[-2].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6890 "fff.tab.c"
    break;

  case 401: /* RecordDeclaration: OMClassModifier RecordDeclarationSym RecordHeader ClassImplements RecordBody  */
#line 1290 "fff.y"
                                                                                                                {goparent();insertmethod(((yyvsp[-3].typeinfo))->variables[0],"record",((yyvsp[-3].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-3].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6896 "fff.tab.c"
    break;

  case 402: /* RecordDeclaration: OMClassModifier RecordDeclarationSym TypeParameters RecordHeader RecordBody  */
#line 1291 "fff.y"
                                                                                                                {goparent();insertmethod(((yyvsp[-3].typeinfo))->variables[0],"record",((yyvsp[-3].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-3].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6902 "fff.tab.c"
    break;

  case 403: /* RecordDeclaration: OMClassModifier RecordDeclarationSym TypeParameters RecordHeader ClassImplements RecordBody  */
#line 1292 "fff.y"
                                                                                                                        {goparent();insertmethod(((yyvsp[-4].typeinfo))->variables[0],"record",((yyvsp[-4].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-4].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6908 "fff.tab.c"
    break;

  case 404: /* RecordHeader: LRB RRB  */
#line 1295 "fff.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back("void");((yyval.typeinfo))->linep = line;(yyval.typeinfo)->tac=emptyvector();}
#line 6914 "fff.tab.c"
    break;

  case 405: /* RecordHeader: LRB RecordComponentList RRB  */
#line 1296 "fff.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;((yyval.typeinfo))->linep = line;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6920 "fff.tab.c"
    break;

  case 406: /* RecordComponentList: RecordComponent  */
#line 1298 "fff.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6926 "fff.tab.c"
    break;

  case 407: /* RecordComponentList: RecordComponent OMCommaRecordComponent  */
#line 1299 "fff.y"
                                                                                {(yyval.typeinfo) = createstruct();vector<string>a=((yyvsp[-1].typeinfo))->type_variable;vector<string>b=((yyvsp[0].typeinfo))->type_variable;for(auto z:a){((yyval.typeinfo))->type_variable.push_back(z);}for(auto z:b){((yyval.typeinfo))->type_variable.push_back(z);}(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 6932 "fff.tab.c"
    break;

  case 408: /* RecordComponent: UnannType Identifier  */
#line 1301 "fff.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-1].typeinfo))->type);}
#line 6938 "fff.tab.c"
    break;

  case 409: /* RecordComponent: VariableArityRecordComponent  */
#line 1302 "fff.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;}
#line 6944 "fff.tab.c"
    break;

  case 410: /* VariableArityRecordComponent: UnannType THREEDOT Identifier  */
#line 1305 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-2].typeinfo))->type);(yyval.typeinfo)->tac=emptyvector();}
#line 6950 "fff.tab.c"
    break;

  case 411: /* RecordBody: LCB RCB  */
#line 1307 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6956 "fff.tab.c"
    break;

  case 412: /* RecordBody: LCB OMRecordBodyDeclaration RCB  */
#line 1308 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6962 "fff.tab.c"
    break;

  case 413: /* RecordBodyDeclaration: ClassBodyDeclaration  */
#line 1310 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6968 "fff.tab.c"
    break;

  case 414: /* RecordBodyDeclaration: CompactConstructorDeclaration  */
#line 1311 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6974 "fff.tab.c"
    break;

  case 415: /* CompactConstructorDeclarationSym: Identifier  */
#line 1313 "fff.y"
                                             {vector<string>tec; symtable*a=createscope("compactconstructor");string p=((yyvsp[0].str));insertmethod(p,"compactconstructor","auto",tec,a,"",line);changescope(a);}
#line 6980 "fff.tab.c"
    break;

  case 416: /* CompactConstructorDeclaration: CompactConstructorDeclarationSym ConstructorBody  */
#line 1315 "fff.y"
                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6986 "fff.tab.c"
    break;

  case 417: /* CompactConstructorDeclaration: OMClassModifier CompactConstructorDeclarationSym ConstructorBody  */
#line 1316 "fff.y"
                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6992 "fff.tab.c"
    break;

  case 418: /* InterfaceDeclaration: NormalInterfaceDeclaration  */
#line 1319 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6998 "fff.tab.c"
    break;

  case 419: /* $@41: %empty  */
#line 1321 "fff.y"
                                                      {symtable*a=createscope("interface");string p=((yyvsp[0].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7004 "fff.tab.c"
    break;

  case 420: /* NormalInterfaceDeclaration: INTERFACE Identifier $@41 InterfaceBody  */
#line 1321 "fff.y"
                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7010 "fff.tab.c"
    break;

  case 421: /* $@42: %empty  */
#line 1322 "fff.y"
                                                                  {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7016 "fff.tab.c"
    break;

  case 422: /* NormalInterfaceDeclaration: INTERFACE Identifier InterfacePermits $@42 InterfaceBody  */
#line 1322 "fff.y"
                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7022 "fff.tab.c"
    break;

  case 423: /* $@43: %empty  */
#line 1323 "fff.y"
                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7028 "fff.tab.c"
    break;

  case 424: /* NormalInterfaceDeclaration: INTERFACE Identifier InterfaceExtends $@43 InterfaceBody  */
#line 1323 "fff.y"
                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7034 "fff.tab.c"
    break;

  case 425: /* $@44: %empty  */
#line 1324 "fff.y"
                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7040 "fff.tab.c"
    break;

  case 426: /* NormalInterfaceDeclaration: INTERFACE Identifier InterfaceExtends InterfacePermits $@44 InterfaceBody  */
#line 1324 "fff.y"
                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7046 "fff.tab.c"
    break;

  case 427: /* $@45: %empty  */
#line 1325 "fff.y"
                                                                {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7052 "fff.tab.c"
    break;

  case 428: /* NormalInterfaceDeclaration: INTERFACE Identifier TypeParameters $@45 InterfaceBody  */
#line 1325 "fff.y"
                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7058 "fff.tab.c"
    break;

  case 429: /* $@46: %empty  */
#line 1326 "fff.y"
                                                                                {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7064 "fff.tab.c"
    break;

  case 430: /* NormalInterfaceDeclaration: INTERFACE Identifier TypeParameters InterfacePermits $@46 InterfaceBody  */
#line 1326 "fff.y"
                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7070 "fff.tab.c"
    break;

  case 431: /* $@47: %empty  */
#line 1327 "fff.y"
                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7076 "fff.tab.c"
    break;

  case 432: /* NormalInterfaceDeclaration: INTERFACE Identifier TypeParameters InterfaceExtends $@47 InterfaceBody  */
#line 1327 "fff.y"
                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7082 "fff.tab.c"
    break;

  case 433: /* $@48: %empty  */
#line 1328 "fff.y"
                                                                                                  {symtable*a=createscope("interface");string p=((yyvsp[-3].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7088 "fff.tab.c"
    break;

  case 434: /* NormalInterfaceDeclaration: INTERFACE Identifier TypeParameters InterfaceExtends InterfacePermits $@48 InterfaceBody  */
#line 1328 "fff.y"
                                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7094 "fff.tab.c"
    break;

  case 435: /* $@49: %empty  */
#line 1329 "fff.y"
                                                                {symtable*a=createscope("interface");string p=((yyvsp[0].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7100 "fff.tab.c"
    break;

  case 436: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier $@49 InterfaceBody  */
#line 1329 "fff.y"
                                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7106 "fff.tab.c"
    break;

  case 437: /* $@50: %empty  */
#line 1330 "fff.y"
                                                                                  {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7112 "fff.tab.c"
    break;

  case 438: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier InterfacePermits $@50 InterfaceBody  */
#line 1330 "fff.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7118 "fff.tab.c"
    break;

  case 439: /* $@51: %empty  */
#line 1331 "fff.y"
                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7124 "fff.tab.c"
    break;

  case 440: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier InterfaceExtends $@51 InterfaceBody  */
#line 1331 "fff.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7130 "fff.tab.c"
    break;

  case 441: /* $@52: %empty  */
#line 1332 "fff.y"
                                                                                                   {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7136 "fff.tab.c"
    break;

  case 442: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier InterfaceExtends InterfacePermits $@52 InterfaceBody  */
#line 1332 "fff.y"
                                                                                                                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7142 "fff.tab.c"
    break;

  case 443: /* $@53: %empty  */
#line 1333 "fff.y"
                                                                               {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7148 "fff.tab.c"
    break;

  case 444: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier TypeParameters $@53 InterfaceBody  */
#line 1333 "fff.y"
                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7154 "fff.tab.c"
    break;

  case 445: /* $@54: %empty  */
#line 1334 "fff.y"
                                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7160 "fff.tab.c"
    break;

  case 446: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier TypeParameters InterfacePermits $@54 InterfaceBody  */
#line 1334 "fff.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7166 "fff.tab.c"
    break;

  case 447: /* $@55: %empty  */
#line 1335 "fff.y"
                                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7172 "fff.tab.c"
    break;

  case 448: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier TypeParameters InterfaceExtends $@55 InterfaceBody  */
#line 1335 "fff.y"
                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7178 "fff.tab.c"
    break;

  case 449: /* $@56: %empty  */
#line 1336 "fff.y"
                                                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-3].str));insertclass(p,"interface","",a,line);changescope(a);}
#line 7184 "fff.tab.c"
    break;

  case 450: /* NormalInterfaceDeclaration: OMClassModifier INTERFACE Identifier TypeParameters InterfaceExtends InterfacePermits $@56 InterfaceBody  */
#line 1336 "fff.y"
                                                                                                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7190 "fff.tab.c"
    break;

  case 451: /* InterfaceModifier: Modifieropt  */
#line 1339 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7196 "fff.tab.c"
    break;

  case 452: /* InterfaceExtends: EXTENDS InterfaceTypeList  */
#line 1341 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7202 "fff.tab.c"
    break;

  case 453: /* InterfacePermits: PERMITS ExpressionName  */
#line 1343 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7208 "fff.tab.c"
    break;

  case 454: /* InterfacePermits: PERMITS ExpressionName OMCommaTypeName  */
#line 1344 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7214 "fff.tab.c"
    break;

  case 455: /* InterfaceBody: LCB RCB  */
#line 1346 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 7220 "fff.tab.c"
    break;

  case 456: /* InterfaceBody: LCB OMInterfaceMemberDeclaration RCB  */
#line 1347 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7226 "fff.tab.c"
    break;

  case 457: /* InterfaceMemberDeclaration: ConstantDeclaration  */
#line 1349 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7232 "fff.tab.c"
    break;

  case 458: /* InterfaceMemberDeclaration: InterfaceMethodDeclaration  */
#line 1350 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7238 "fff.tab.c"
    break;

  case 459: /* InterfaceMemberDeclaration: ClassDeclaration  */
#line 1351 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7244 "fff.tab.c"
    break;

  case 460: /* InterfaceMemberDeclaration: InterfaceDeclaration  */
#line 1352 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7250 "fff.tab.c"
    break;

  case 461: /* InterfaceMemberDeclaration: SEMICOLON  */
#line 1353 "fff.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 7256 "fff.tab.c"
    break;

  case 462: /* ConstantDeclaration: UnannType VariableDeclaratorList SEMICOLON  */
#line 1355 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;((yyval.typeinfo))->puvariables=((yyvsp[-1].typeinfo))->puvariables;vector<string> s = pushlocal(((yyvsp[-1].typeinfo))->puvariables); (yyval.typeinfo)->tac=concvector(s,(yyvsp[-1].typeinfo)->tac);vector<string>a=((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type=((yyvsp[-2].typeinfo))->type+((yyvsp[-1].typeinfo))->type;for(auto z:a){insertidentifier(z,((yyvsp[-2].typeinfo))->type,"",line);}}
#line 7262 "fff.tab.c"
    break;

  case 463: /* ConstantDeclaration: OMClassModifier UnannType VariableDeclaratorList SEMICOLON  */
#line 1356 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;((yyval.typeinfo))->puvariables=((yyvsp[-1].typeinfo))->puvariables;vector<string> s = pushlocal(((yyvsp[-1].typeinfo))->puvariables); (yyval.typeinfo)->tac=concvector(s,(yyvsp[-1].typeinfo)->tac);vector<string>a=((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type=((yyvsp[-2].typeinfo))->type+((yyvsp[-1].typeinfo))->type;for(auto z:a){insertidentifier(z,((yyvsp[-2].typeinfo))->type,"",line);}}
#line 7268 "fff.tab.c"
    break;

  case 464: /* InterfaceMethodDeclaration: MethodHeader MethodBody  */
#line 1358 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-1].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="function end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z,sv,p);}
#line 7274 "fff.tab.c"
    break;

  case 465: /* InterfaceMethodDeclaration: OMClassModifier MethodHeader MethodBody  */
#line 1359 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-1].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="function end"; stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st); 	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z,sv,p);}
#line 7280 "fff.tab.c"
    break;

  case 466: /* ArrayInitializer: LCB RCB  */
#line 1361 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "[]";(yyval.typeinfo)->tac=emptyvector();}
#line 7286 "fff.tab.c"
    break;

  case 467: /* ArrayInitializer: LCB COMMA RCB  */
#line 1362 "fff.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "[]";(yyval.typeinfo)->tac=emptyvector();}
#line 7292 "fff.tab.c"
    break;

  case 468: /* ArrayInitializer: LCB VariableInitializerList RCB  */
#line 1363 "fff.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type =  ((yyvsp[-1].typeinfo))->type + "[]";(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7298 "fff.tab.c"
    break;

  case 469: /* VariableInitializerList: VariableInitializer  */
#line 1365 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type =  ((yyvsp[0].typeinfo))->type ;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7304 "fff.tab.c"
    break;

  case 470: /* VariableInitializerList: VariableInitializer OMCommaVariableInitializer  */
#line 1366 "fff.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type =  ((yyvsp[-1].typeinfo))->type; (yyval.typeinfo)->tac= concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7310 "fff.tab.c"
    break;

  case 471: /* Block: LCB RCB  */
#line 1368 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;vector<string>p={}; (yyval.typeinfo)->tac=p;}
#line 7316 "fff.tab.c"
    break;

  case 472: /* Block: LCB BlockStatements RCB  */
#line 1369 "fff.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 7322 "fff.tab.c"
    break;

  case 473: /* BlockStatements: BlockStatement  */
#line 1371 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7328 "fff.tab.c"
    break;

  case 474: /* BlockStatements: BlockStatement OMBlockStatement  */
#line 1372 "fff.y"
                                                                                                   {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7334 "fff.tab.c"
    break;

  case 475: /* BlockStatement: LocalClassOrInterfaceDeclaration  */
#line 1374 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7340 "fff.tab.c"
    break;

  case 476: /* BlockStatement: LocalVariableDeclarationStatement  */
#line 1375 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7346 "fff.tab.c"
    break;

  case 477: /* BlockStatement: Statement  */
#line 1376 "fff.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7352 "fff.tab.c"
    break;

  case 478: /* LocalClassOrInterfaceDeclaration: ClassDeclaration  */
#line 1378 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7358 "fff.tab.c"
    break;

  case 479: /* LocalClassOrInterfaceDeclaration: NormalInterfaceDeclaration  */
#line 1379 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7364 "fff.tab.c"
    break;

  case 480: /* LocalVariableDeclarationStatement: LocalVariableDeclaration SEMICOLON  */
#line 1381 "fff.y"
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
    (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;
}
#line 7391 "fff.tab.c"
    break;

  case 481: /* LocalVariableDeclaration: LocalVariableType VariableDeclaratorList  */
#line 1404 "fff.y"
                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->dectype=(yyvsp[-1].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[-1].typeinfo)->decorder1;((yyval.typeinfo))->variables=((yyvsp[0].typeinfo))->variables;(yyval.typeinfo)->decorders2=(yyvsp[0].typeinfo)->decorders2;(yyval.typeinfo)->arrtypes=(yyvsp[0].typeinfo)->arrtypes;(yyval.typeinfo)->arrdims=(yyvsp[0].typeinfo)->arrdims;(yyval.typeinfo)->initvartypes=(yyvsp[0].typeinfo)->initvartypes;for(auto yyy:(yyval.typeinfo)->variables)cout<<yyy<<" ";((yyval.typeinfo))->puvariables=((yyvsp[0].typeinfo))->puvariables;vector<string> s = pushlocal(((yyvsp[0].typeinfo))->puvariables); (yyval.typeinfo)->tac=concvector(s,(yyvsp[0].typeinfo)->tac);}
#line 7397 "fff.tab.c"
    break;

  case 482: /* LocalVariableDeclaration: OMClassModifier LocalVariableType VariableDeclaratorList  */
#line 1405 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->dectype=(yyvsp[-1].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[-1].typeinfo)->decorder1;((yyval.typeinfo))->variables=((yyvsp[0].typeinfo))->variables;(yyval.typeinfo)->decorders2=(yyvsp[0].typeinfo)->decorders2;(yyval.typeinfo)->arrtypes=(yyvsp[0].typeinfo)->arrtypes;(yyval.typeinfo)->arrdims=(yyvsp[0].typeinfo)->arrdims;(yyval.typeinfo)->initvartypes=(yyvsp[0].typeinfo)->initvartypes; ((yyval.typeinfo))->puvariables=((yyvsp[0].typeinfo))->puvariables;vector<string> s = pushlocal(((yyvsp[0].typeinfo))->puvariables); (yyval.typeinfo)->tac=concvector(s,(yyvsp[0].typeinfo)->tac);}
#line 7403 "fff.tab.c"
    break;

  case 483: /* LocalVariableType: UnannType  */
#line 1407 "fff.y"
                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;((yyval.typeinfo))->type=((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->dectype=(yyvsp[0].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[0].typeinfo)->decorder1;}
#line 7409 "fff.tab.c"
    break;

  case 484: /* LocalVariableType: VAR  */
#line 1408 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac= emptyvector();((yyval.typeinfo))->type="all";(yyval.typeinfo)->dectype="all";(yyval.typeinfo)->decorder1=0;}
#line 7415 "fff.tab.c"
    break;

  case 485: /* Statement: StatementWithoutTrailingSubstatement  */
#line 1410 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7421 "fff.tab.c"
    break;

  case 486: /* Statement: LabeledStatement  */
#line 1411 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7427 "fff.tab.c"
    break;

  case 487: /* Statement: IfThenStatement  */
#line 1412 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7433 "fff.tab.c"
    break;

  case 488: /* Statement: IfThenElseStatement  */
#line 1413 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7439 "fff.tab.c"
    break;

  case 489: /* Statement: WhileStatement  */
#line 1414 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7445 "fff.tab.c"
    break;

  case 490: /* Statement: ForStatement  */
#line 1415 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7451 "fff.tab.c"
    break;

  case 491: /* StatementNoShortIf: StatementWithoutTrailingSubstatement  */
#line 1417 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7457 "fff.tab.c"
    break;

  case 492: /* StatementNoShortIf: LabeledStatementNoShortIf  */
#line 1418 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7463 "fff.tab.c"
    break;

  case 493: /* StatementNoShortIf: IfThenElseStatementNoShortIf  */
#line 1419 "fff.y"
                                                                            {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7469 "fff.tab.c"
    break;

  case 494: /* StatementNoShortIf: WhileStatementNoShortIf  */
#line 1420 "fff.y"
                                                                            {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7475 "fff.tab.c"
    break;

  case 495: /* StatementNoShortIf: ForStatementNoShortIf  */
#line 1421 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7481 "fff.tab.c"
    break;

  case 496: /* $@57: %empty  */
#line 1423 "fff.y"
                                        {symtable *a = createscope("statement");insertclass("statement","statement","",a,line); changescope(a);flag = 0;}
#line 7487 "fff.tab.c"
    break;

  case 497: /* StatementWithoutTrailingSubstatement: $@57 Block  */
#line 1423 "fff.y"
                                                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7493 "fff.tab.c"
    break;

  case 498: /* StatementWithoutTrailingSubstatement: EmptyStatement  */
#line 1424 "fff.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7499 "fff.tab.c"
    break;

  case 499: /* StatementWithoutTrailingSubstatement: ExpressionStatement  */
#line 1425 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7505 "fff.tab.c"
    break;

  case 500: /* StatementWithoutTrailingSubstatement: AssertStatement  */
#line 1426 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7511 "fff.tab.c"
    break;

  case 501: /* StatementWithoutTrailingSubstatement: SwitchStatement  */
#line 1427 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7517 "fff.tab.c"
    break;

  case 502: /* StatementWithoutTrailingSubstatement: DoStatement  */
#line 1428 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7523 "fff.tab.c"
    break;

  case 503: /* StatementWithoutTrailingSubstatement: BreakStatement  */
#line 1429 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7529 "fff.tab.c"
    break;

  case 504: /* StatementWithoutTrailingSubstatement: ContinueStatement  */
#line 1430 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7535 "fff.tab.c"
    break;

  case 505: /* StatementWithoutTrailingSubstatement: ReturnStatement  */
#line 1431 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7541 "fff.tab.c"
    break;

  case 506: /* StatementWithoutTrailingSubstatement: SynchronizedStatement  */
#line 1432 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7547 "fff.tab.c"
    break;

  case 507: /* StatementWithoutTrailingSubstatement: ThrowStatement  */
#line 1433 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7553 "fff.tab.c"
    break;

  case 508: /* StatementWithoutTrailingSubstatement: TryStatement  */
#line 1434 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7559 "fff.tab.c"
    break;

  case 509: /* StatementWithoutTrailingSubstatement: YieldStatement  */
#line 1435 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7565 "fff.tab.c"
    break;

  case 510: /* EmptyStatement: SEMICOLON  */
#line 1437 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; vector<string>p={}; (yyval.typeinfo)->tac=p;}
#line 7571 "fff.tab.c"
    break;

  case 511: /* LabeledStatement: Identifier COLON Statement  */
#line 1439 "fff.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7577 "fff.tab.c"
    break;

  case 512: /* LabeledStatementNoShortIf: Identifier COLON StatementNoShortIf  */
#line 1441 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7583 "fff.tab.c"
    break;

  case 513: /* ExpressionStatement: StatementExpression SEMICOLON  */
#line 1444 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[-1].typeinfo)->tempname;}
#line 7589 "fff.tab.c"
    break;

  case 514: /* StatementExpression: Assignment  */
#line 1446 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 7595 "fff.tab.c"
    break;

  case 515: /* StatementExpression: PreIncrementExpression  */
#line 1447 "fff.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 7601 "fff.tab.c"
    break;

  case 516: /* StatementExpression: PreDecrementExpression  */
#line 1448 "fff.y"
                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 7607 "fff.tab.c"
    break;

  case 517: /* StatementExpression: PostIncrementExpression  */
#line 1449 "fff.y"
                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 7613 "fff.tab.c"
    break;

  case 518: /* StatementExpression: PostDecrementExpression  */
#line 1450 "fff.y"
                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 7619 "fff.tab.c"
    break;

  case 519: /* StatementExpression: MethodInvocation  */
#line 1451 "fff.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 7625 "fff.tab.c"
    break;

  case 520: /* StatementExpression: ClassInstanceCreationExpression  */
#line 1452 "fff.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 7631 "fff.tab.c"
    break;

  case 521: /* IfThenStatement: IF LRB Expression RRB Statement  */
#line 1454 "fff.y"
                                                                {(yyval.typeinfo)=new Typeinfo;int lv=labelvariable;string a=newlabel();string ret="if zero "+((yyvsp[-2].typeinfo))->tempname+gotoo(lv+1);(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,a);}
#line 7637 "fff.tab.c"
    break;

  case 522: /* IfThenElseStatement: IF LRB Expression RRB StatementNoShortIf ELSE Statement  */
#line 1456 "fff.y"
                                                                              {(yyval.typeinfo)=new Typeinfo;int lv=labelvariable;string a=newlabel();string ret="if zero "+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+1);(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,ret,(yyvsp[-2].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac);}
#line 7643 "fff.tab.c"
    break;

  case 523: /* IfThenElseStatementNoShortIf: IF LRB Expression RRB StatementNoShortIf ELSE StatementNoShortIf  */
#line 1458 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;int lv=labelvariable;string a=newlabel();string ret="if zero "+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+1);(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,ret,(yyvsp[-2].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac);}
#line 7649 "fff.tab.c"
    break;

  case 524: /* AssertStatement: ASSERT Expression SEMICOLON  */
#line 1460 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7655 "fff.tab.c"
    break;

  case 525: /* AssertStatement: ASSERT Expression COLON Expression SEMICOLON  */
#line 1461 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 7661 "fff.tab.c"
    break;

  case 526: /* $@58: %empty  */
#line 1463 "fff.y"
                                                   {symtable *a = createscope("switch"); changescope(a);}
#line 7667 "fff.tab.c"
    break;

  case 527: /* SwitchStatement: SWITCH LRB Expression RRB $@58 SwitchBlock  */
#line 1463 "fff.y"
                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7673 "fff.tab.c"
    break;

  case 528: /* SwitchBlock: LCB SwitchRule RCB  */
#line 1465 "fff.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7679 "fff.tab.c"
    break;

  case 529: /* SwitchBlock: LCB SwitchRule OMSwitchRule RCB  */
#line 1466 "fff.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 7685 "fff.tab.c"
    break;

  case 530: /* SwitchBlock: LCB RCB  */
#line 1467 "fff.y"
                                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7691 "fff.tab.c"
    break;

  case 531: /* SwitchBlock: LCB OMSwitchLabelColon RCB  */
#line 1468 "fff.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7697 "fff.tab.c"
    break;

  case 532: /* SwitchBlock: LCB OMSwitchBlockStatementGroup RCB  */
#line 1469 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7703 "fff.tab.c"
    break;

  case 533: /* SwitchBlock: LCB OMSwitchBlockStatementGroup OMSwitchLabelColon RCB  */
#line 1470 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 7709 "fff.tab.c"
    break;

  case 534: /* SwitchRule: SwitchLabel IMPLIES Expression SEMICOLON  */
#line 1472 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 7715 "fff.tab.c"
    break;

  case 535: /* SwitchRule: SwitchLabel IMPLIES Block  */
#line 1473 "fff.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7721 "fff.tab.c"
    break;

  case 536: /* SwitchRule: SwitchLabel IMPLIES ThrowStatement  */
#line 1474 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7727 "fff.tab.c"
    break;

  case 537: /* SwitchBlockStatementGroup: SwitchLabel COLON BlockStatements  */
#line 1476 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7733 "fff.tab.c"
    break;

  case 538: /* SwitchBlockStatementGroup: SwitchLabel COLON OMSwitchLabelColon BlockStatements  */
#line 1477 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7739 "fff.tab.c"
    break;

  case 539: /* SwitchLabel: CASE CaseConstant  */
#line 1479 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7745 "fff.tab.c"
    break;

  case 540: /* SwitchLabel: CASE CaseConstant OMCommaCaseConstant  */
#line 1480 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7751 "fff.tab.c"
    break;

  case 541: /* SwitchLabel: DEFAULT  */
#line 1481 "fff.y"
                                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7757 "fff.tab.c"
    break;

  case 542: /* CaseConstant: ConditionalExpression  */
#line 1483 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7763 "fff.tab.c"
    break;

  case 543: /* WhileStatement: WHILE LRB Expression RRB Statement  */
#line 1485 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; int c=labelvariable; string a=newlabel();string b=newlabel();string z=gotoo(c+2);string d="if zero "+(((yyvsp[-2].typeinfo))->tempname)+z;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,a,d,(yyvsp[0].typeinfo)->tac,gotoo(c+1),b);}
#line 7769 "fff.tab.c"
    break;

  case 544: /* WhileStatementNoShortIf: WHILE LRB Expression RRB StatementNoShortIf  */
#line 1487 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; int c=labelvariable; string a=newlabel();string z=gotoo(c+2);string b=newlabel();string d="if zero "+(((yyvsp[-2].typeinfo))->tempname)+z;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,a,d,(yyvsp[0].typeinfo)->tac,gotoo(c+1),b);}
#line 7775 "fff.tab.c"
    break;

  case 545: /* DoStatement: DO Statement WHILE LRB Expression RRB SEMICOLON  */
#line 1489 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; string p=gotoo(labelvariable); (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,p);}
#line 7781 "fff.tab.c"
    break;

  case 546: /* ForStatement: BasicForStatement  */
#line 1491 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7787 "fff.tab.c"
    break;

  case 547: /* ForStatement: EnhancedForStatement  */
#line 1492 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7793 "fff.tab.c"
    break;

  case 548: /* ForStatementNoShortIf: BasicForStatementNoShortIf  */
#line 1494 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7799 "fff.tab.c"
    break;

  case 549: /* ForStatementNoShortIf: EnhancedForStatementNoShortIf  */
#line 1495 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 7805 "fff.tab.c"
    break;

  case 550: /* ForSym: FOR  */
#line 1497 "fff.y"
                {symtable*a=createscope("for");insertclass("for","for","",a,line); changescope(a);}
#line 7811 "fff.tab.c"
    break;

  case 551: /* BasicForStatement: ForSym LRB SEMICOLON SEMICOLON RRB Statement  */
#line 1499 "fff.y"
                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector(a,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7817 "fff.tab.c"
    break;

  case 552: /* BasicForStatement: ForSym LRB SEMICOLON SEMICOLON ForUpdate RRB Statement  */
#line 1500 "fff.y"
                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector(a,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 7823 "fff.tab.c"
    break;

  case 553: /* BasicForStatement: ForSym LRB SEMICOLON Expression SEMICOLON RRB Statement  */
#line 1501 "fff.y"
                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-3].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-3].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7829 "fff.tab.c"
    break;

  case 554: /* BasicForStatement: ForSym LRB SEMICOLON Expression SEMICOLON ForUpdate RRB Statement  */
#line 1502 "fff.y"
                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-4].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 7835 "fff.tab.c"
    break;

  case 555: /* BasicForStatement: ForSym LRB ForInit SEMICOLON SEMICOLON RRB Statement  */
#line 1503 "fff.y"
                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7841 "fff.tab.c"
    break;

  case 556: /* BasicForStatement: ForSym LRB ForInit SEMICOLON SEMICOLON ForUpdate RRB Statement  */
#line 1504 "fff.y"
                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 7847 "fff.tab.c"
    break;

  case 557: /* BasicForStatement: ForSym LRB ForInit SEMICOLON Expression SEMICOLON RRB Statement  */
#line 1505 "fff.y"
                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-3].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,a,(yyvsp[-3].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7853 "fff.tab.c"
    break;

  case 558: /* BasicForStatement: ForSym LRB ForInit SEMICOLON Expression SEMICOLON ForUpdate RRB Statement  */
#line 1506 "fff.y"
                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector((yyvsp[-6].typeinfo)->tac,a,(yyvsp[-4].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 7859 "fff.tab.c"
    break;

  case 559: /* BasicForStatementNoShortIf: ForSym LRB SEMICOLON SEMICOLON RRB StatementNoShortIf  */
#line 1508 "fff.y"
                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector(a,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7865 "fff.tab.c"
    break;

  case 560: /* BasicForStatementNoShortIf: ForSym LRB SEMICOLON SEMICOLON ForUpdate RRB StatementNoShortIf  */
#line 1509 "fff.y"
                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector(a,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 7871 "fff.tab.c"
    break;

  case 561: /* BasicForStatementNoShortIf: ForSym LRB SEMICOLON Expression SEMICOLON RRB StatementNoShortIf  */
#line 1510 "fff.y"
                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-3].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-3].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7877 "fff.tab.c"
    break;

  case 562: /* BasicForStatementNoShortIf: ForSym LRB SEMICOLON Expression SEMICOLON ForUpdate RRB StatementNoShortIf  */
#line 1511 "fff.y"
                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-4].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 7883 "fff.tab.c"
    break;

  case 563: /* BasicForStatementNoShortIf: ForSym LRB ForInit SEMICOLON SEMICOLON RRB StatementNoShortIf  */
#line 1512 "fff.y"
                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7889 "fff.tab.c"
    break;

  case 564: /* BasicForStatementNoShortIf: ForSym LRB ForInit SEMICOLON SEMICOLON ForUpdate RRB StatementNoShortIf  */
#line 1513 "fff.y"
                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 7895 "fff.tab.c"
    break;

  case 565: /* BasicForStatementNoShortIf: ForSym LRB ForInit SEMICOLON Expression SEMICOLON RRB StatementNoShortIf  */
#line 1514 "fff.y"
                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-3].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,a,(yyvsp[-3].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7901 "fff.tab.c"
    break;

  case 566: /* BasicForStatementNoShortIf: ForSym LRB ForInit SEMICOLON Expression SEMICOLON ForUpdate RRB StatementNoShortIf  */
#line 1515 "fff.y"
                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector((yyvsp[-6].typeinfo)->tac,a,(yyvsp[-4].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 7907 "fff.tab.c"
    break;

  case 567: /* ForInit: StatementExpressionList  */
#line 1517 "fff.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7913 "fff.tab.c"
    break;

  case 568: /* ForInit: LocalVariableDeclaration  */
#line 1518 "fff.y"
                                                                        {vector<string> a = ((yyvsp[0].typeinfo))->variables; for(auto s : a)insertidentifier(s,((yyvsp[0].typeinfo))->type,"",line);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7919 "fff.tab.c"
    break;

  case 569: /* ForUpdate: StatementExpressionList  */
#line 1520 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7925 "fff.tab.c"
    break;

  case 570: /* StatementExpressionList: StatementExpression  */
#line 1522 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7931 "fff.tab.c"
    break;

  case 571: /* StatementExpressionList: StatementExpression OMCommaStatementExpression  */
#line 1523 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7937 "fff.tab.c"
    break;

  case 572: /* EnhancedForStatementSym: ForSym LRB LocalVariableDeclaration  */
#line 1525 "fff.y"
                                                             {vector<string> a = ((yyvsp[0].typeinfo))->variables; for(auto s : a)insertidentifier(s,((yyvsp[0].typeinfo))->type,"",line);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7943 "fff.tab.c"
    break;

  case 573: /* EnhancedForStatement: EnhancedForStatementSym COLON Expression RRB Statement  */
#line 1527 "fff.y"
                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-2].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-4].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7949 "fff.tab.c"
    break;

  case 574: /* EnhancedForStatementNoShortIf: EnhancedForStatementSym COLON Expression RRB StatementNoShortIf  */
#line 1529 "fff.y"
                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+((yyvsp[-2].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-4].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 7955 "fff.tab.c"
    break;

  case 575: /* BreakStatement: BREAK SEMICOLON  */
#line 1531 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;string p=gotoo(labelvariable+1); (yyval.typeinfo)->tac={p};}
#line 7961 "fff.tab.c"
    break;

  case 576: /* BreakStatement: BREAK Identifier SEMICOLON  */
#line 1532 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;string p=gotoo(labelvariable+1); (yyval.typeinfo)->tac={p};}
#line 7967 "fff.tab.c"
    break;

  case 577: /* YieldStatement: YIELD Expression SEMICOLON  */
#line 1535 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7973 "fff.tab.c"
    break;

  case 578: /* ContinueStatement: CONTINUE SEMICOLON  */
#line 1537 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;string p=gotoo(labelvariable); (yyval.typeinfo)->tac={p};}
#line 7979 "fff.tab.c"
    break;

  case 579: /* ContinueStatement: CONTINUE Identifier SEMICOLON  */
#line 1538 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;string p=gotoo(labelvariable); (yyval.typeinfo)->tac={p};}
#line 7985 "fff.tab.c"
    break;

  case 580: /* ReturnStatement: RETURN SEMICOLON  */
#line 1541 "fff.y"
                                                        {(yyval.typeinfo)=new Typeinfo;string p=gotomethodretlabel(currmethod.top()); (yyval.typeinfo)->tac={p};}
#line 7991 "fff.tab.c"
    break;

  case 581: /* ReturnStatement: RETURN Expression SEMICOLON  */
#line 1542 "fff.y"
                                             {(yyval.typeinfo)=new Typeinfo;string p=gotomethodretlabel(currmethod.top());string s = "%rax = " + (yyvsp[-1].typeinfo)->tempname; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,s,p);}
#line 7997 "fff.tab.c"
    break;

  case 582: /* ThrowStatement: THROW Expression SEMICOLON  */
#line 1544 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 8003 "fff.tab.c"
    break;

  case 583: /* $@59: %empty  */
#line 1546 "fff.y"
                                                         {symtable*a=createscope("synchronized"); changescope(a);}
#line 8009 "fff.tab.c"
    break;

  case 584: /* SynchronizedStatement: SYNCHRONIZED LRB Expression RRB $@59 Block  */
#line 1546 "fff.y"
                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8015 "fff.tab.c"
    break;

  case 585: /* TrySym: TRY  */
#line 1548 "fff.y"
            {symtable*a=createscope("try"); changescope(a);}
#line 8021 "fff.tab.c"
    break;

  case 586: /* TryBlockSym: Block  */
#line 1550 "fff.y"
                        {goparent();(yyval.typeinfo)=createstruct(); (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8027 "fff.tab.c"
    break;

  case 587: /* TryStatement: TrySym TryBlockSym Catches  */
#line 1552 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8033 "fff.tab.c"
    break;

  case 588: /* TryStatement: TrySym TryBlockSym Finally  */
#line 1553 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8039 "fff.tab.c"
    break;

  case 589: /* TryStatement: TrySym TryBlockSym Catches Finally  */
#line 1554 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8045 "fff.tab.c"
    break;

  case 590: /* TryStatement: TryWithResourcesStatement  */
#line 1555 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8051 "fff.tab.c"
    break;

  case 591: /* Catches: CatchClause  */
#line 1557 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8057 "fff.tab.c"
    break;

  case 592: /* Catches: CatchClause OMCatchClause  */
#line 1558 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8063 "fff.tab.c"
    break;

  case 593: /* $@60: %empty  */
#line 1560 "fff.y"
                       {symtable*a=createscope("catch"); changescope(a);}
#line 8069 "fff.tab.c"
    break;

  case 594: /* CatchClause: CATCH $@60 LRB CatchFormalParameter RRB Block  */
#line 1560 "fff.y"
                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8075 "fff.tab.c"
    break;

  case 595: /* CatchFormalParameter: CatchType VariableDeclaratorId  */
#line 1562 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8081 "fff.tab.c"
    break;

  case 596: /* CatchFormalParameter: OMClassModifier CatchType VariableDeclaratorId  */
#line 1563 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8087 "fff.tab.c"
    break;

  case 597: /* CatchType: Identifier  */
#line 1565 "fff.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8093 "fff.tab.c"
    break;

  case 598: /* CatchType: Identifier OMOrClassType  */
#line 1566 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8099 "fff.tab.c"
    break;

  case 599: /* $@61: %empty  */
#line 1569 "fff.y"
                         {symtable*a=createscope("finally"); changescope(a);}
#line 8105 "fff.tab.c"
    break;

  case 600: /* Finally: FINALLY $@61 Block  */
#line 1569 "fff.y"
                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8111 "fff.tab.c"
    break;

  case 601: /* TryWithResourcesStatement: TrySym ResourceSpecification TryBlockSym  */
#line 1571 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8117 "fff.tab.c"
    break;

  case 602: /* TryWithResourcesStatement: TrySym ResourceSpecification TryBlockSym Finally  */
#line 1572 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8123 "fff.tab.c"
    break;

  case 603: /* TryWithResourcesStatement: TrySym ResourceSpecification TryBlockSym Catches  */
#line 1573 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8129 "fff.tab.c"
    break;

  case 604: /* TryWithResourcesStatement: TrySym ResourceSpecification TryBlockSym Catches Finally  */
#line 1574 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8135 "fff.tab.c"
    break;

  case 605: /* ResourceSpecification: LRB ResourceList RRB  */
#line 1576 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 8141 "fff.tab.c"
    break;

  case 606: /* ResourceList: Resource  */
#line 1578 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8147 "fff.tab.c"
    break;

  case 607: /* ResourceList: OMSemicolonResource  */
#line 1579 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8153 "fff.tab.c"
    break;

  case 608: /* Resource: LocalVariableDeclaration  */
#line 1581 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8159 "fff.tab.c"
    break;

  case 609: /* Resource: VariableAccess  */
#line 1582 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8165 "fff.tab.c"
    break;

  case 610: /* Primary: PrimaryNoNewArray  */
#line 1584 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;vector<int>q;(yyval.typeinfo)->arrdim=q;(yyval.typeinfo)->arrtype="";(yyval.typeinfo)->initvartype=(yyvsp[0].typeinfo)->initvartype;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8171 "fff.tab.c"
    break;

  case 611: /* Primary: ArrayCreationExpression  */
#line 1585 "fff.y"
                                                                                                                                {(yyval.typeinfo)=createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->initvartype="";(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8177 "fff.tab.c"
    break;

  case 612: /* PrimaryNoNewArray: Literal  */
#line 1587 "fff.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;(yyval.typeinfo)->initvartype=(yyvsp[0].typeinfo)->type;((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8183 "fff.tab.c"
    break;

  case 613: /* PrimaryNoNewArray: ClassLiteral  */
#line 1588 "fff.y"
                                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8189 "fff.tab.c"
    break;

  case 614: /* PrimaryNoNewArray: THIS  */
#line 1589 "fff.y"
                                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();(yyval.typeinfo)->tempname="this";}
#line 8195 "fff.tab.c"
    break;

  case 615: /* PrimaryNoNewArray: Identifier DOT THIS  */
#line 1590 "fff.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class";string x=(yyvsp[-2].str); (yyval.typeinfo)->tac=emptyvector();(yyval.typeinfo)->tempname=x;}
#line 8201 "fff.tab.c"
    break;

  case 616: /* PrimaryNoNewArray: ExpressionName DOT THIS  */
#line 1591 "fff.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-2].typeinfo);((yyval.typeinfo))->type = "class";}
#line 8207 "fff.tab.c"
    break;

  case 617: /* PrimaryNoNewArray: LRB Expression RRB  */
#line 1592 "fff.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-1].typeinfo);((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;}
#line 8213 "fff.tab.c"
    break;

  case 618: /* PrimaryNoNewArray: ClassInstanceCreationExpression  */
#line 1593 "fff.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8219 "fff.tab.c"
    break;

  case 619: /* PrimaryNoNewArray: FieldAccess  */
#line 1594 "fff.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = "look";}
#line 8225 "fff.tab.c"
    break;

  case 620: /* PrimaryNoNewArray: ArrayAccess  */
#line 1595 "fff.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8231 "fff.tab.c"
    break;

  case 621: /* PrimaryNoNewArray: MethodInvocation  */
#line 1596 "fff.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8237 "fff.tab.c"
    break;

  case 622: /* PrimaryNoNewArray: MethodReference  */
#line 1597 "fff.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = "look";}
#line 8243 "fff.tab.c"
    break;

  case 623: /* ClassLiteral: Identifier DOT CLASS  */
#line 1599 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();}
#line 8249 "fff.tab.c"
    break;

  case 624: /* ClassLiteral: ExpressionName DOT CLASS  */
#line 1600 "fff.y"
                                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();}
#line 8255 "fff.tab.c"
    break;

  case 625: /* ClassLiteral: Identifier OMPSB DOT CLASS  */
#line 1601 "fff.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();}
#line 8261 "fff.tab.c"
    break;

  case 626: /* ClassLiteral: ExpressionName OMPSB DOT CLASS  */
#line 1602 "fff.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();}
#line 8267 "fff.tab.c"
    break;

  case 627: /* ClassLiteral: UnannPrimitiveType DOT CLASS  */
#line 1603 "fff.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();}
#line 8273 "fff.tab.c"
    break;

  case 628: /* ClassLiteral: VOID DOT CLASS  */
#line 1604 "fff.y"
                                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();}
#line 8279 "fff.tab.c"
    break;

  case 629: /* ClassInstanceCreationExpression: UnqualifiedClassInstanceCreationExpression  */
#line 1606 "fff.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8285 "fff.tab.c"
    break;

  case 630: /* ClassInstanceCreationExpression: Identifier DOT UnqualifiedClassInstanceCreationExpression  */
#line 1607 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8291 "fff.tab.c"
    break;

  case 631: /* ClassInstanceCreationExpression: ExpressionName DOT UnqualifiedClassInstanceCreationExpression  */
#line 1608 "fff.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8297 "fff.tab.c"
    break;

  case 632: /* ClassInstanceCreationExpression: Primary DOT UnqualifiedClassInstanceCreationExpression  */
#line 1609 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8303 "fff.tab.c"
    break;

  case 633: /* UnqualifiedClassInstanceCreationExpression: NEW ClassOrInterfaceTypeToInstantiate LRB RRB  */
#line 1615 "fff.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 8309 "fff.tab.c"
    break;

  case 634: /* UnqualifiedClassInstanceCreationExpression: NEW ClassOrInterfaceTypeToInstantiate LRB RRB ClassBody  */
#line 1616 "fff.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-3].typeinfo))->type;(yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8315 "fff.tab.c"
    break;

  case 635: /* UnqualifiedClassInstanceCreationExpression: NEW ClassOrInterfaceTypeToInstantiate LRB ArgumentList RRB  */
#line 1617 "fff.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-3].typeinfo))->type;(yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 8321 "fff.tab.c"
    break;

  case 636: /* UnqualifiedClassInstanceCreationExpression: NEW ClassOrInterfaceTypeToInstantiate LRB ArgumentList RRB ClassBody  */
#line 1618 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-4].typeinfo))->type;(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8327 "fff.tab.c"
    break;

  case 637: /* ClassOrInterfaceTypeToInstantiate: Identifier  */
#line 1620 "fff.y"
                                                                                {(yyval.typeinfo) = createstruct();string p = (yyvsp[0].str);if(lookup(p)){((yyval.typeinfo))->type =  lookup(p)->funcrettype ;}(yyval.typeinfo)->tac=emptyvector();}
#line 8333 "fff.tab.c"
    break;

  case 638: /* ClassOrInterfaceTypeToInstantiate: Identifier OMDotIdentifier  */
#line 1621 "fff.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=emptyvector();string p = (yyvsp[-1].str);if(lookup(p + ((yyvsp[0].typeinfo))->name)){((yyval.typeinfo))->type =  lookup(p + ((yyvsp[0].typeinfo))->name)->funcrettype ;}}
#line 8339 "fff.tab.c"
    break;

  case 639: /* FieldAccess: Primary DOT Identifier  */
#line 1623 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8345 "fff.tab.c"
    break;

  case 640: /* FieldAccess: SUPER DOT Identifier  */
#line 1624 "fff.y"
                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=emptyvector();}
#line 8351 "fff.tab.c"
    break;

  case 641: /* FieldAccess: Identifier DOT SUPER DOT Identifier  */
#line 1625 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=emptyvector();}
#line 8357 "fff.tab.c"
    break;

  case 642: /* FieldAccess: ExpressionName DOT SUPER DOT Identifier  */
#line 1626 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 8363 "fff.tab.c"
    break;

  case 643: /* ArrayAccess: Identifier LSB Expression RSB  */
#line 1628 "fff.y"
                                                                {(yyval.typeinfo)=new Typeinfo; vector<int>v={2,3,4};string x="int"; vector<int>f; for(int 	i=1;i<v.size();i++)f.push_back(v[i]);(yyval.typeinfo)->dimsize=f;(yyval.typeinfo)->arrname="a"; (yyval.typeinfo)->arrtype=x;string y=newtemp();(yyval.typeinfo)->tempname=y;y=y+" = "+((yyvsp[-1].typeinfo))->tempname+" * "+to_string(tellsize(f,x)); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,y);}
#line 8369 "fff.tab.c"
    break;

  case 644: /* ArrayAccess: ExpressionName LSB Expression RSB  */
#line 1629 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 8375 "fff.tab.c"
    break;

  case 645: /* ArrayAccess: PrimaryNoNewArray LSB Expression RSB  */
#line 1630 "fff.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; vector<int>v=((yyvsp[-3].typeinfo))->dimsize;string x=((yyvsp[-3].typeinfo))->arrtype; vector<int>f; for(int i=1;i<v.size();i++)f.push_back(v[i]);(yyval.typeinfo)->dimsize=f; (yyval.typeinfo)->arrtype=x;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=newtemp();y=y+" = "+((yyvsp[-1].typeinfo))->tempname+" + "+z;z=z+" = "+((yyvsp[-1].typeinfo))->tempname+" * "+to_string(tellsize(f,x)); (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,z,y);(yyval.typeinfo)->arrname=(yyvsp[-3].typeinfo)->arrname;}
#line 8381 "fff.tab.c"
    break;

  case 646: /* MethodInvocation: MethodName LRB ArgumentList RRB  */
#line 1632 "fff.y"
                                                                                                        {(yyval.typeinfo) = createstruct();if(lookup(((yyvsp[-3].typeinfo))->name)){((yyval.typeinfo))->type =  lookup(((yyvsp[-3].typeinfo))->name)->funcrettype ;} vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters(); string s = ((yyvsp[-3].typeinfo))->tempname;((yyval.typeinfo))->tempname = "%rax"; string s1 = gotomethod(s);string s2 = newmethodretlabel(s);vector<string> pushpar = pusharg(((yyvsp[-1].typeinfo))->params);(yyval.typeinfo)->tac=concvector(pv1,(yyvsp[-1].typeinfo)->tac,pushpar,s1,(yyvsp[-3].typeinfo)->tac,s2,pv2);}
#line 8387 "fff.tab.c"
    break;

  case 647: /* MethodInvocation: MethodName LRB RRB  */
#line 1633 "fff.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();if(lookup(((yyvsp[-2].typeinfo))->name)){((yyval.typeinfo))->type =  lookup(((yyvsp[-2].typeinfo))->name)->funcrettype ;}vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters();string s = ((yyvsp[-2].typeinfo))->tempname;((yyval.typeinfo))->tempname = "%rax";string s1 = gotomethod(s);string s2 = newmethodretlabel(s); (yyval.typeinfo)->tac=concvector(pv1,s1,(yyvsp[-2].typeinfo)->tac,s2,pv2);}
#line 8393 "fff.tab.c"
    break;

  case 648: /* MethodInvocation: Identifier DOT Identifier LRB RRB  */
#line 1634 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8399 "fff.tab.c"
    break;

  case 649: /* MethodInvocation: Identifier DOT Identifier LRB ArgumentList RRB  */
#line 1635 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 8405 "fff.tab.c"
    break;

  case 650: /* MethodInvocation: ExpressionName DOT Identifier LRB RRB  */
#line 1636 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 8411 "fff.tab.c"
    break;

  case 651: /* MethodInvocation: ExpressionName DOT Identifier LRB ArgumentList RRB  */
#line 1637 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 8417 "fff.tab.c"
    break;

  case 652: /* MethodInvocation: Primary DOT Identifier LRB RRB  */
#line 1638 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 8423 "fff.tab.c"
    break;

  case 653: /* MethodInvocation: Primary DOT Identifier LRB ArgumentList RRB  */
#line 1639 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-5].typeinfo)->tac;}
#line 8429 "fff.tab.c"
    break;

  case 654: /* MethodInvocation: SUPER DOT Identifier LRB RRB  */
#line 1640 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8435 "fff.tab.c"
    break;

  case 655: /* MethodInvocation: SUPER DOT Identifier LRB ArgumentList RRB  */
#line 1641 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8441 "fff.tab.c"
    break;

  case 656: /* MethodInvocation: Identifier DOT SUPER DOT Identifier LRB RRB  */
#line 1642 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8447 "fff.tab.c"
    break;

  case 657: /* MethodInvocation: Identifier DOT SUPER DOT Identifier LRB ArgumentList RRB  */
#line 1643 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 8453 "fff.tab.c"
    break;

  case 658: /* MethodInvocation: ExpressionName DOT SUPER DOT Identifier LRB RRB  */
#line 1644 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-6].typeinfo)->tac;}
#line 8459 "fff.tab.c"
    break;

  case 659: /* MethodInvocation: ExpressionName DOT SUPER DOT Identifier LRB ArgumentList RRB  */
#line 1645 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-7].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 8465 "fff.tab.c"
    break;

  case 660: /* ArgumentList: Expression  */
#line 1648 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;string s = ((yyvsp[0].typeinfo))->tempname; (yyval.typeinfo)->params.push_back(s);}
#line 8471 "fff.tab.c"
    break;

  case 661: /* ArgumentList: Expression OMCommaExpression  */
#line 1649 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);string s = ((yyvsp[-1].typeinfo))->tempname; (yyval.typeinfo)->params.push_back(s); for(auto z:((yyvsp[0].typeinfo))->params)((yyval.typeinfo))->params.push_back(z);}
#line 8477 "fff.tab.c"
    break;

  case 662: /* MethodReference: Identifier DOUBLECOLON Identifier  */
#line 1651 "fff.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8483 "fff.tab.c"
    break;

  case 664: /* MethodReference: Primary DOUBLECOLON Identifier  */
#line 1653 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8489 "fff.tab.c"
    break;

  case 665: /* MethodReference: UnannArrayType DOUBLECOLON Identifier  */
#line 1654 "fff.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8495 "fff.tab.c"
    break;

  case 666: /* MethodReference: SUPER DOUBLECOLON Identifier  */
#line 1655 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8501 "fff.tab.c"
    break;

  case 667: /* MethodReference: Identifier DOT SUPER DOUBLECOLON Identifier  */
#line 1656 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8507 "fff.tab.c"
    break;

  case 669: /* MethodReference: UnannArrayType DOUBLECOLON NEW  */
#line 1658 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8513 "fff.tab.c"
    break;

  case 670: /* ArrayCreationExpression: NEW PrimitiveType OMDimExpr  */
#line 1660 "fff.y"
                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->type=(yyvsp[-1].typeinfo)->type;(yyval.typeinfo)->arrtype=(yyvsp[-1].typeinfo)->type;(yyval.typeinfo)->arrdim=(yyvsp[0].typeinfo)->arrdim;cout<<"hi";for(auto z:(yyvsp[0].typeinfo)->arrdim)cout<<z<<"  "; (yyval.typeinfo)->tac=emptyvector();}
#line 8519 "fff.tab.c"
    break;

  case 671: /* ArrayCreationExpression: NEW PrimitiveType OMDimExpr OMPSB  */
#line 1661 "fff.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8525 "fff.tab.c"
    break;

  case 672: /* ArrayCreationExpression: NEW Identifier OMDimExpr  */
#line 1662 "fff.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8531 "fff.tab.c"
    break;

  case 673: /* ArrayCreationExpression: NEW Identifier OMDimExpr OMPSB  */
#line 1663 "fff.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8537 "fff.tab.c"
    break;

  case 674: /* ArrayCreationExpression: NEW PrimitiveType OMPSB ArrayInitializer  */
#line 1664 "fff.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8543 "fff.tab.c"
    break;

  case 675: /* ArrayCreationExpression: NEW Identifier OMPSB ArrayInitializer  */
#line 1665 "fff.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8549 "fff.tab.c"
    break;

  case 676: /* DimExpr: LSB Expression RSB  */
#line 1668 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();if((yyvsp[-1].typeinfo)->type!="int")cout<<"error coz of nonint array para";(yyval.typeinfo)=(yyvsp[-1].typeinfo);(yyval.typeinfo)->exprvalue=(yyvsp[-1].typeinfo)->exprvalue;(yyval.typeinfo)->type=(yyvsp[-1].typeinfo)->type;}
#line 8555 "fff.tab.c"
    break;

  case 677: /* Expression: AssignmentExpression  */
#line 1670 "fff.y"
                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 8561 "fff.tab.c"
    break;

  case 678: /* AssignmentExpression: ConditionalExpression  */
#line 1672 "fff.y"
                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 8567 "fff.tab.c"
    break;

  case 679: /* AssignmentExpression: Assignment  */
#line 1673 "fff.y"
                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8573 "fff.tab.c"
    break;

  case 680: /* Assignment: LeftHandSide AssignmentOperator Expression  */
#line 1675 "fff.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string p=((yyvsp[-2].typeinfo))->tempname+" = "+((yyvsp[0].typeinfo))->tempname;(yyval.typeinfo)->tempname=((yyvsp[-2].typeinfo))->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,p);}
#line 8579 "fff.tab.c"
    break;

  case 681: /* LeftHandSide: ExpressionName  */
#line 1677 "fff.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 8585 "fff.tab.c"
    break;

  case 682: /* LeftHandSide: Identifier  */
#line 1678 "fff.y"
                                                                                                        {(yyval.typeinfo) = createstruct();string p = (yyvsp[0].str);if(lookup(p)){((yyval.typeinfo))->type = lookup(p)->type;}string x=(yyvsp[0].str); string q=newtemp();(yyval.typeinfo)->tempname=q;q=q+" = "+x; (yyval.typeinfo)->tac={q};}
#line 8591 "fff.tab.c"
    break;

  case 683: /* LeftHandSide: FieldAccess  */
#line 1679 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 8597 "fff.tab.c"
    break;

  case 684: /* LeftHandSide: ArrayAccess  */
#line 1680 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->type=(yyvsp[0].typeinfo)->type;string y=((yyvsp[0].typeinfo))->arrname+"["+((yyvsp[0].typeinfo))->tempname+"]"; (yyval.typeinfo)->tempname=y;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8603 "fff.tab.c"
    break;

  case 685: /* AssignmentOperator: ASSIGNMENTOPERATOR  */
#line 1682 "fff.y"
                                                                                                {(yyval.str)=(yyvsp[0].str);}
#line 8609 "fff.tab.c"
    break;

  case 686: /* ConditionalExpression: ConditionalOrExpression  */
#line 1684 "fff.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 8615 "fff.tab.c"
    break;

  case 687: /* ConditionalExpression: ConditionalOrExpression QM Expression COLON ConditionalExpression  */
#line 1685 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-4].typeinfo))->type;int lv=labelvariable;string a=newlabel();string ret="if zero "+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+1);(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,ret,(yyvsp[-2].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac);}
#line 8621 "fff.tab.c"
    break;

  case 688: /* ConditionalOrExpression: ConditionalAndExpression  */
#line 1687 "fff.y"
                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8627 "fff.tab.c"
    break;

  case 689: /* ConditionalOrExpression: ConditionalOrExpression OR ConditionalAndExpression  */
#line 1688 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" || "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8633 "fff.tab.c"
    break;

  case 690: /* ConditionalAndExpression: InclusiveOrExpression  */
#line 1690 "fff.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8639 "fff.tab.c"
    break;

  case 691: /* ConditionalAndExpression: ConditionalAndExpression AND InclusiveOrExpression  */
#line 1691 "fff.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" && "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8645 "fff.tab.c"
    break;

  case 692: /* InclusiveOrExpression: ExclusiveOrExpression  */
#line 1693 "fff.y"
                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8651 "fff.tab.c"
    break;

  case 693: /* InclusiveOrExpression: InclusiveOrExpression BITOR ExclusiveOrExpression  */
#line 1694 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" | "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8657 "fff.tab.c"
    break;

  case 694: /* ExclusiveOrExpression: AndExpression  */
#line 1696 "fff.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8663 "fff.tab.c"
    break;

  case 695: /* ExclusiveOrExpression: ExclusiveOrExpression BITXOR AndExpression  */
#line 1697 "fff.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" ^ "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8669 "fff.tab.c"
    break;

  case 696: /* AndExpression: EqualityExpression  */
#line 1699 "fff.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8675 "fff.tab.c"
    break;

  case 697: /* AndExpression: AndExpression BITAND EqualityExpression  */
#line 1700 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" & "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8681 "fff.tab.c"
    break;

  case 698: /* EqualityExpression: RelationalExpression  */
#line 1702 "fff.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8687 "fff.tab.c"
    break;

  case 699: /* EqualityExpression: EqualityExpression DOUBLEEQUAL RelationalExpression  */
#line 1703 "fff.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" == "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8693 "fff.tab.c"
    break;

  case 700: /* EqualityExpression: EqualityExpression NE RelationalExpression  */
#line 1704 "fff.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" != "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8699 "fff.tab.c"
    break;

  case 701: /* RelationalExpression: ShiftExpression  */
#line 1706 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8705 "fff.tab.c"
    break;

  case 702: /* RelationalExpression: RelationalExpression LT ShiftExpression  */
#line 1707 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" < "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8711 "fff.tab.c"
    break;

  case 703: /* RelationalExpression: RelationalExpression GT ShiftExpression  */
#line 1708 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" > "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8717 "fff.tab.c"
    break;

  case 704: /* RelationalExpression: RelationalExpression LTE ShiftExpression  */
#line 1709 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" <= "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8723 "fff.tab.c"
    break;

  case 705: /* RelationalExpression: RelationalExpression GTE ShiftExpression  */
#line 1710 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" >= "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8729 "fff.tab.c"
    break;

  case 706: /* RelationalExpression: InstanceofExpression  */
#line 1711 "fff.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8735 "fff.tab.c"
    break;

  case 707: /* InstanceofExpression: RelationalExpression INSTANCEOF ReferenceType  */
#line 1716 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" instanceof "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8741 "fff.tab.c"
    break;

  case 708: /* ShiftExpression: AdditiveExpression  */
#line 1718 "fff.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8747 "fff.tab.c"
    break;

  case 709: /* ShiftExpression: ShiftExpression LSHIFT AdditiveExpression  */
#line 1719 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" << "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8753 "fff.tab.c"
    break;

  case 710: /* ShiftExpression: ShiftExpression RSHIFT AdditiveExpression  */
#line 1720 "fff.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" >> "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8759 "fff.tab.c"
    break;

  case 711: /* ShiftExpression: ShiftExpression THREEGT AdditiveExpression  */
#line 1721 "fff.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" >>> "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8765 "fff.tab.c"
    break;

  case 712: /* AdditiveExpression: MultiplicativeExpression  */
#line 1723 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8771 "fff.tab.c"
    break;

  case 713: /* AdditiveExpression: AdditiveExpression PLUS MultiplicativeExpression  */
#line 1724 "fff.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" + "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8777 "fff.tab.c"
    break;

  case 714: /* AdditiveExpression: AdditiveExpression MINUS MultiplicativeExpression  */
#line 1725 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" - "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8783 "fff.tab.c"
    break;

  case 715: /* MultiplicativeExpression: UnaryExpression  */
#line 1727 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8789 "fff.tab.c"
    break;

  case 716: /* MultiplicativeExpression: MultiplicativeExpression MULTIPLY UnaryExpression  */
#line 1728 "fff.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" * "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8795 "fff.tab.c"
    break;

  case 717: /* MultiplicativeExpression: MultiplicativeExpression DIVIDE UnaryExpression  */
#line 1729 "fff.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" / "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8801 "fff.tab.c"
    break;

  case 718: /* MultiplicativeExpression: MultiplicativeExpression PERCENT UnaryExpression  */
#line 1730 "fff.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-2].typeinfo)->tempname+" % "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);}
#line 8807 "fff.tab.c"
    break;

  case 719: /* UnaryExpression: PreIncrementExpression  */
#line 1732 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8813 "fff.tab.c"
    break;

  case 720: /* UnaryExpression: PreDecrementExpression  */
#line 1733 "fff.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8819 "fff.tab.c"
    break;

  case 721: /* UnaryExpression: PLUS UnaryExpression  */
#line 1734 "fff.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8825 "fff.tab.c"
    break;

  case 722: /* UnaryExpression: MINUS UnaryExpression  */
#line 1735 "fff.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+" - "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);}
#line 8831 "fff.tab.c"
    break;

  case 723: /* UnaryExpression: UnaryExpressionNotPlusMinus  */
#line 1736 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8837 "fff.tab.c"
    break;

  case 724: /* PreIncrementExpression: INCREAMENT UnaryExpression  */
#line 1738 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[0].typeinfo)->tempname+" + 1 ";(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue+1;}
#line 8843 "fff.tab.c"
    break;

  case 725: /* PreDecrementExpression: DECREAMENT UnaryExpression  */
#line 1740 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[0].typeinfo)->tempname+" - 1 ";(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue+1;}
#line 8849 "fff.tab.c"
    break;

  case 726: /* UnaryExpressionNotPlusMinus: PostfixExpression  */
#line 1742 "fff.y"
                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8855 "fff.tab.c"
    break;

  case 727: /* UnaryExpressionNotPlusMinus: TILDA UnaryExpression  */
#line 1743 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+" ~ "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);}
#line 8861 "fff.tab.c"
    break;

  case 728: /* UnaryExpressionNotPlusMinus: EXCLAM UnaryExpression  */
#line 1744 "fff.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+" ! "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);}
#line 8867 "fff.tab.c"
    break;

  case 729: /* UnaryExpressionNotPlusMinus: CastExpression  */
#line 1745 "fff.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8873 "fff.tab.c"
    break;

  case 730: /* UnaryExpressionNotPlusMinus: SwitchExpression  */
#line 1746 "fff.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8879 "fff.tab.c"
    break;

  case 731: /* PostfixExpression: Primary  */
#line 1748 "fff.y"
                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8885 "fff.tab.c"
    break;

  case 732: /* PostfixExpression: Identifier  */
#line 1749 "fff.y"
                                                                                        {(yyval.typeinfo) = createstruct();string p = (yyvsp[0].str);symentry*s=lookup(p); if(lookup(p)){((yyval.typeinfo))->type = s->type;(yyval.typeinfo)->order=s->order;(yyval.typeinfo)->exprvalue=s->exprvalue;}string a=(yyvsp[0].str); string b=newtemp();(yyval.typeinfo)->tempname=b;b=b+" = "+a;(yyval.typeinfo)->tac={b};(yyval.typeinfo)->tac={b};}
#line 8891 "fff.tab.c"
    break;

  case 733: /* PostfixExpression: ExpressionName  */
#line 1750 "fff.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8897 "fff.tab.c"
    break;

  case 734: /* PostfixExpression: PostIncrementExpression  */
#line 1751 "fff.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 8903 "fff.tab.c"
    break;

  case 735: /* PostfixExpression: PostDecrementExpression  */
#line 1752 "fff.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->type = ((yyvsp[0].typeinfo))->type;}
#line 8909 "fff.tab.c"
    break;

  case 736: /* PostIncrementExpression: PostfixExpression INCREAMENT  */
#line 1754 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-1].typeinfo)->tempname+" + 1 ";(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,a);}
#line 8915 "fff.tab.c"
    break;

  case 737: /* PostDecrementExpression: PostfixExpression DECREAMENT  */
#line 1756 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[-1].typeinfo)->tempname+" - 1 ";(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,a);}
#line 8921 "fff.tab.c"
    break;

  case 738: /* CastExpression: LRB PrimitiveType RRB UnaryExpression  */
#line 1758 "fff.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type; ((yyvsp[0].typeinfo))->type = ((yyvsp[-2].typeinfo))->type; string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);}
#line 8927 "fff.tab.c"
    break;

  case 739: /* CastExpression: LRB UnannArrayType RRB UnaryExpressionNotPlusMinus  */
#line 1759 "fff.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type; ((yyvsp[0].typeinfo))->type = ((yyvsp[-2].typeinfo))->type; string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);}
#line 8933 "fff.tab.c"
    break;

  case 740: /* CastExpression: LRB UnannArrayType OMAdditionalBound RRB UnaryExpressionNotPlusMinus  */
#line 1760 "fff.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-3].typeinfo))->type; ((yyvsp[0].typeinfo))->type = ((yyvsp[-3].typeinfo))->type; string a=newtemp();(yyval.typeinfo)->tempname=a;a=a+" = "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);}
#line 8939 "fff.tab.c"
    break;

  case 741: /* $@62: %empty  */
#line 1762 "fff.y"
                                                   {symtable *a = createscope("switch"); changescope(a);}
#line 8945 "fff.tab.c"
    break;

  case 742: /* SwitchExpression: SWITCH LRB Expression RRB $@62 SwitchBlock  */
#line 1762 "fff.y"
                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);((yyval.typeinfo))->type = "switch";}
#line 8951 "fff.tab.c"
    break;

  case 743: /* VariableAccess: ExpressionName  */
#line 1764 "fff.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 8957 "fff.tab.c"
    break;

  case 744: /* VariableAccess: Identifier  */
#line 1765 "fff.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; string a=(yyvsp[0].str); string b=newtemp();(yyval.typeinfo)->tempname=b;b=b+" = "+a;(yyval.typeinfo)->tac={b};(yyval.typeinfo)->tac={b};}
#line 8963 "fff.tab.c"
    break;

  case 745: /* VariableAccess: FieldAccess  */
#line 1766 "fff.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 8969 "fff.tab.c"
    break;


#line 8973 "fff.tab.c"

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

#line 1769 "fff.y"

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
	// ofstream csvFile("symboltable.csv");
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
			// csvFile<<z.first<<","<<z.second->type<<","<<z.second->primtype<<","<<"arraysize:";
             string p="";
            vector<int>q=z.second->arrdims;
            if(q.size()>0){
           for(int i=0;i<q.size()-1;i++)
           p=p+to_string(q[i])+" x ";
           p=p+to_string(q[q.size()-1]);
            }
			csvFile<<z.first<<","<<z.second->type<<","<<z.second->primtype<<","<<z.second<<z.second->linenumber<<","<<z.second->argcon<<","<<z.second->funcrettype<<"arraysize:";
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
