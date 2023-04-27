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
int positiveoffset = 8;
int negativeoffset = 0;
stack<pair<int,int>> offs;
stack<int> fieldoffs;
void incoff(string x,bool fir);
void inserttemp(string lexeme,int offse);
string identwithoff(string id);
struct symentry;
struct symtable;
symentry *lookup(string a);
struct symentry
{
    string maintype;
    int linenumber;
    int offset = 0;
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
	string tet = "t"+to_string(tempvariables) + "{"+to_string(offs.top().second)+"}";
	inserttemp(tet,offs.top().second);
	incoff("temper",false);
	return tet;
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
	return 8;
	else if(x=="float")
	return 8;
	else if(x=="double")
	return 8;
	else if(x== "char")
	return 8;
	else if(x=="long")
	return 8;
	else if(x=="short")
	return 8;
	else if(x=="byte")
	return 8;
	else if(x=="boolean")
	return 8;
	else
	return 0;
}
void pushoff(){
	pair<int,int> p = {16,-8};
	offs.push(p);
}
void popoff(){
	if(!offs.empty()){
		offs.pop();
	}
}
void fieldpushoff(){
	fieldoffs.push(0);
}
void fieldpopoff(){
	if(!offs.empty()){
		fieldoffs.pop();
	}
}
void fieldincoff(){
	if(!fieldoffs.empty()){
		int t = fieldoffs.top();
		t = t;
		fieldoffs.pop();
		fieldoffs.push(t);
	}
}
void incoff(string x,bool fir){
	if(!offs.empty()){
		if(fir){
			if(x=="int"){
				pair<int,int> t;
				t.first = offs.top().first + 8;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
			else if(x=="float"){
				pair<int,int> t;
				t.first = offs.top().first + 8;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
			else if(x=="double"){
				pair<int,int> t;
				t.first = offs.top().first + 8;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
			else if(x== "char"){
				pair<int,int> t;
				t.first = offs.top().first + 8;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
			else if(x=="long"){
				pair<int,int> t;
				t.first = offs.top().first + 8;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
			else if(x=="short"){
				pair<int,int> t;
				t.first = offs.top().first + 8;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
			else if(x=="byte"){
				pair<int,int> t;
				t.first = offs.top().first + 8;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
			else if(x=="boolean"){
				pair<int,int> t;
				t.first = offs.top().first + 8;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
			else if(x=="temper"){
				pair<int,int> t;
				t.first = offs.top().first + 8;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
			else{
				pair<int,int> t;
				t.first = offs.top().first + 0;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
		}
		else{
			if(x=="int"){
				pair<int,int> t;
				t.first = offs.top().first;
				t.second = offs.top().second - 8;
				offs.pop();
				offs.push(t);
			}
			else if(x=="float"){
				pair<int,int> t;
				t.first = offs.top().first;
				t.second = offs.top().second - 8;
				offs.pop();
				offs.push(t);
			}
			else if(x=="double"){
				pair<int,int> t;
				t.first = offs.top().first;
				t.second = offs.top().second - 8;
				offs.pop();
				offs.push(t);
			}
			else if(x== "char"){
				pair<int,int> t;
				t.first = offs.top().first;
				t.second = offs.top().second - 8;
				offs.pop();
				offs.push(t);
			}
			else if(x=="long"){
				pair<int,int> t;
				t.first = offs.top().first;
				t.second = offs.top().second - 8;
				offs.pop();
				offs.push(t);
			}
			else if(x=="short"){
				pair<int,int> t;
				t.first = offs.top().first;
				t.second = offs.top().second - 8;
				offs.pop();
				offs.push(t);
			}
			else if(x=="byte"){
				pair<int,int> t;
				t.first = offs.top().first;
				t.second = offs.top().second - 8;
				offs.pop();
				offs.push(t);
			}
			else if(x=="boolean"){
				pair<int,int> t;
				t.first = offs.top().first;
				t.second = offs.top().second - 8;
				offs.pop();
				offs.push(t);
			}
			else if(x=="temper"){
				pair<int,int> t;
				t.first = offs.top().first;
				t.second = offs.top().second - 8;
				offs.pop();
				offs.push(t);
			}
			else{
				pair<int,int> t;
				t.first = offs.top().first;
				t.second = offs.top().second - 0;
				offs.pop();
				offs.push(t);
			}
		}
	}
}
void incoff(string x,bool fir,vector<int> dim){
	if(!offs.empty()){
		if(fir){
			if(x=="int"){
				pair<int,int> t;
				int tem = 1;
				for(auto a:dim)
				tem = tem*a;
				t.first = offs.top().first + 8*tem;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
			else if(x=="float"){
				pair<int,int> t;
				int tem = 1;
				for(auto a:dim)
				tem = tem*a;
				t.first = offs.top().first + 8*tem;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
			else if(x=="double"){
				pair<int,int> t;
				int tem = 1;
				for(auto a:dim)
				tem = tem*a;
				t.first = offs.top().first + 8*tem;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
			else if(x== "char"){
				pair<int,int> t;
				int tem = 1;
				for(auto a:dim)
				tem = tem*a;
				t.first = offs.top().first + 8*tem;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
			else if(x=="long"){
				pair<int,int> t;
				int tem = 1;
				for(auto a:dim)
				tem = tem*a;
				t.first = offs.top().first + 8*tem;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
			else if(x=="short"){
				pair<int,int> t;
				int tem = 1;
				for(auto a:dim)
				tem = tem*a;
				t.first = offs.top().first + 8*tem;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
			else if(x=="byte"){
				pair<int,int> t;
				int tem = 1;
				for(auto a:dim)
				tem = tem*a;
				t.first = offs.top().first + 8*tem;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
			else if(x=="boolean"){
				pair<int,int> t;
				int tem = 1;
				for(auto a:dim)
				tem = tem*a;
				t.first = offs.top().first + 8*tem;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
			else{
				pair<int,int> t;
				int tem = 1;
				for(auto a:dim)
				tem = tem*a;
				t.first = offs.top().first + 0*tem;
				t.second = offs.top().second;
				offs.pop();
				offs.push(t);
			}
		}
		else{
			if(x=="int"){
				pair<int,int> t;
				int tem = 1;
				for(auto a:dim)
				tem = tem*a;
				t.first = offs.top().first;
				t.second = offs.top().second - 8*tem;
				offs.pop();
				offs.push(t);
			}
			else if(x=="float"){
				pair<int,int> t;
				int tem = 1;
				for(auto a:dim)
				tem = tem*a;
				t.first = offs.top().first;
				t.second = offs.top().second - 8*tem;
				offs.pop();
				offs.push(t);
			}
			else if(x=="double"){
				pair<int,int> t;
				int tem = 1;
				for(auto a:dim)
				tem = tem*a;
				t.first = offs.top().first;
				t.second = offs.top().second - 8*tem;
				offs.pop();
				offs.push(t);
			}
			else if(x== "char"){
				pair<int,int> t;
				int tem = 1;
				for(auto a:dim)
				tem = tem*a;
				t.first = offs.top().first;
				t.second = offs.top().second - 8*tem;
				offs.pop();
				offs.push(t);
			}
			else if(x=="long"){
				pair<int,int> t;
				int tem = 1;
				for(auto a:dim)
				tem = tem*a;
				t.first = offs.top().first;
				t.second = offs.top().second - 8*tem;
				offs.pop();
				offs.push(t);
			}
			else if(x=="short"){
				pair<int,int> t;
				int tem = 1;
				for(auto a:dim)
				tem = tem*a;
				t.first = offs.top().first;
				t.second = offs.top().second - 8*tem;
				offs.pop();
				offs.push(t);
			}
			else if(x=="byte"){
				pair<int,int> t;
				int tem = 1;
				for(auto a:dim)
				tem = tem*a;
				t.first = offs.top().first;
				t.second = offs.top().second - 8*tem;
				offs.pop();
				offs.push(t);
			}
			else if(x=="boolean"){
				pair<int,int> t;
				int tem = 1;
				for(auto a:dim)
				tem = tem*a;
				t.first = offs.top().first;
				t.second = offs.top().second - 8*tem;
				offs.pop();
				offs.push(t);
			}
			else{
				pair<int,int> t;
				int tem = 1;
				for(auto a:dim)
				tem = tem*a;
				t.first = offs.top().first;
				t.second = offs.top().second - 0*tem;
				offs.pop();
				offs.push(t);
			}
		}
	}
}
string newmethodlabel(string i){
	stack<string> st;
	currmethodlocals.push(st);
	currmethod.push(i);
	return i+":";
}
string newmethodretlabel(string i){
	return "";
}
string gotomethod(string i,int n){
	return "methodgo to " + i+" "+to_string(n);
}
string gotomethodretlabel(string i){
	// return "go to " + i+"ret:";
	return "";
}
vector<string> pusharg(vector<string> s){
	vector<string> r;
	for(auto k:s){
		string temp = "pushparam " + k;
		r.push_back(temp);
	}
	reverse(r.begin(),r.end());
	return r;
}
vector<string> pushlocal(vector<string> s){
	vector<string> r;
	for(auto k:s){
		string temp = "pushlocal " + identwithoff(k);
		// currmethodlocals.top().push(k);
		if(!currmethodlocals.empty()){
		stack<string>p=currmethodlocals.top();
		currmethodlocals.pop();
		p.push(k);
		currmethodlocals.push(p);
		}
		else{
			stack<string>p;
			p.push(k);
			currmethodlocals.push(p);
		}
		r.push_back(temp);
	}
	// cerr<<"ferugfyre";
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

string identwithoff(string id){
	string r = "";
	if(lookup(id))
	if(lookup(id)->offset==0){
		r = "FIELD " + id+"{"+to_string(lookup(id)->offset)+"}";
	}
	else{
		r = id+"{"+to_string(lookup(id)->offset)+"}";
	}
	else{
		cerr<<"Error: variable not decleared"<<endl;
	}
	// cout<<r<<endl;
	return r;
}

vector<string> concvector(string a,vector<string> &vb,vector<string>&va){
    vector<string>r={a};
		// r.push_back(b);
		for(auto z:va)
    r.push_back(z);
		for(auto z:vb)
    r.push_back(z);
    return r;
}
vector<string> concvector(vector<string> va,string z,vector<string>&vb,string a,string b,vector<string>&vc,string c){
	vector<string>s = va;
	s.push_back(z);
    for(auto z:vb)
	s.push_back(z);
	s.push_back(a);
	s.push_back(b);
    for(auto z:vc)
	s.push_back(z);
	s.push_back(c);
	return s;
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

vector<string> contemp(vector<string> &va,vector<string> &vb){
	vector<string>s = va;
		for(auto z:vb)
    s.push_back(z);
		return s;
}
vector<string> contemp(vector<string> &va,vector<string> &vb,vector<string> &vc){
	vector<string>s = va;
		for(auto z:vb)
    s.push_back(z);
		for(auto z:vc)
    s.push_back(z);
		return s;
}
vector<string> contemp(vector<string> &va,vector<string> &vb,string a){
	vector<string>s = va;
		for(auto z:vb)
    s.push_back(z);
    s.push_back(a);
		return s;
}
vector<string> contemp(vector<string> &va,string a){
	vector<string>s = va;
    s.push_back(a);
		return s;
}
vector<string> contemp(vector<string> &va,string a,string b){
	vector<string>s = va;
    s.push_back(a);
    s.push_back(b);
		return s;
}
vector<string> contemp(string a){
	vector<string>s;
    s.push_back(a);
		return s;
}

void printte(vector<string> vs){
	cout<<"-----------"<<endl;
	for(auto z:vs){
		cout<<z<<endl;
	}
	cout<<"-----------"<<endl;
}

vector<string> funcstart86(string id,int sub){
	vector<string> vs;
	vs.push_back("function is starting");
	string temo = "_xv86 .globl	"+ id;
	vs.push_back(temo);
	temo = "_xv86 .type	"+id+", @function";
	vs.push_back(temo);
	temo = "_xv86 " + id+":";
	vs.push_back(temo);
	temo = "_xv86 endbr64";
	vs.push_back(temo);
	temo = "_xv86 pushq	%rbp";
	vs.push_back(temo);
	temo = "_xv86 movq	%rsp, %rbp";
	vs.push_back(temo);
	temo = "_xv86 pushq %rdi";
	vs.push_back(temo);
	temo="enter required subq";
	vs.push_back(temo);
	temo = "_xv86 subq  $"+to_string(sub)+", %rsp";
	vs.push_back(temo);
	return vs;
}
vector<string> funcend86(){
	vector<string> vs;
	string temo = "_xv86 popq %rdi";
	vs.push_back(temo);
	temo = "_xv86 leave";
	vs.push_back(temo);
	temo = "_xv86 ret";
	vs.push_back(temo);
	return vs;
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

void addclasssize(string name,int negsize){
		int s = -negsize;
    if (curr)
    {
        curr->m[name]->size = s;
    }
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
		if(!samelookup(lexeme) || lexeme == "for"|| lexeme == "while"){
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
		if(!samelookup(lexeme)|| lexeme == "for"|| lexeme == "statement"|| lexeme == "while"){
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
		vector<int>tt ;
		tt.push_back(sizeoftype(type));
		a->arrdims = tt;
		
		
}

void insertidentifier(string lexeme,string type,string primtype,string modifier,int linen,int order,vector<int>dims,int offse)
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
		a->offset = offse;
		}
		else{
			cout<< "Error: identifier is already declared "<<lexeme<<endl;
		}
}
void inserttemp(string lexeme,int offse)
{
    symentry *a = new symentry;
		if(!samelookup(lexeme)){
    curr->m[lexeme] = a;
    a->lexeme=lexeme;
    // a->primtype=primtype;
    a->type= "temp";
    // a->modifier=modifier;
		a->scope=curr->scope;
		// a->linenumber = linen;
        // a->order=order;
        // a->arrdims=dims;
		// a->size=sizeoftype(primtype);
		a->offset = offse;
		}
		else{
			cout<< "Error: temp is already declared "<<lexeme<<endl;
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
		vector<string>temporarystore;
		vector<string>method_argvari;

    vector<string>tac;
    string tempname;
    string arrname;
    vector<int>dimsize;


    string post;//for postinc
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

#line 1352 "parser.tab.c"

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

#line 1527 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   7609

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  120
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  303
/* YYNRULES -- Number of rules.  */
#define YYNRULES  745
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1291

#define YYUNDEFTOK  2
#define YYMAXUTOK   374


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,  1324,  1324,  1325,  1327,  1329,  1330,  1332,  1334,  1336,
    1337,  1339,  1340,  1342,  1343,  1345,  1346,  1348,  1349,  1351,
    1352,  1354,  1356,  1357,  1359,  1360,  1362,  1363,  1365,  1366,
    1368,  1370,  1371,  1373,  1375,  1376,  1378,  1379,  1381,  1383,
    1384,  1386,  1388,  1389,  1391,  1393,  1394,  1396,  1398,  1399,
    1401,  1402,  1409,  1410,  1412,  1413,  1415,  1416,  1418,  1419,
    1421,  1423,  1424,  1426,  1428,  1429,  1431,  1433,  1434,  1436,
    1437,  1439,  1441,  1442,  1444,  1446,  1447,  1449,  1451,  1452,
    1454,  1455,  1456,  1457,  1458,  1459,  1460,  1461,  1463,  1465,
    1466,  1467,  1468,  1469,  1470,  1471,  1472,  1473,  1474,  1475,
    1476,  1477,  1478,  1479,  1480,  1490,  1491,  1492,  1493,  1494,
    1495,  1496,  1497,  1498,  1500,  1502,  1503,  1505,  1506,  1507,
    1508,  1509,  1511,  1512,  1514,  1515,  1517,  1518,  1520,  1521,
    1523,  1525,  1526,  1528,  1529,  1531,  1533,  1534,  1536,  1537,
    1538,  1539,  1540,  1541,  1542,  1543,  1545,  1546,  1548,  1549,
    1551,  1552,  1553,  1554,  1556,  1557,  1559,  1561,  1562,  1564,
    1565,  1567,  1568,  1569,  1571,  1571,  1572,  1572,  1573,  1573,
    1574,  1574,  1575,  1575,  1576,  1576,  1577,  1577,  1578,  1578,
    1580,  1581,  1582,  1583,  1584,  1585,  1586,  1587,  1588,  1589,
    1590,  1591,  1592,  1593,  1594,  1595,  1596,  1597,  1598,  1599,
    1600,  1601,  1602,  1603,  1605,  1606,  1607,  1609,  1609,  1610,
    1610,  1611,  1611,  1612,  1612,  1613,  1613,  1614,  1614,  1615,
    1615,  1616,  1616,  1617,  1617,  1618,  1618,  1619,  1619,  1620,
    1620,  1621,  1621,  1622,  1622,  1623,  1623,  1624,  1624,  1625,
    1625,  1626,  1626,  1627,  1627,  1628,  1628,  1629,  1629,  1630,
    1630,  1631,  1631,  1632,  1632,  1633,  1633,  1634,  1634,  1635,
    1635,  1636,  1636,  1637,  1637,  1638,  1638,  1639,  1639,  1640,
    1640,  1642,  1644,  1645,  1647,  1649,  1651,  1652,  1655,  1656,
    1657,  1658,  1660,  1661,  1663,  1664,  1665,  1666,  1668,  1669,
    1670,  1671,  1672,  1677,  1723,  1772,  1773,  1775,  1776,  1778,
    1779,  1781,  1782,  1784,  1785,  1786,  1788,  1789,  1791,  1792,
    1795,  1796,  1798,  1799,  1800,  1801,  1803,  1804,  1806,  1807,
    1808,  1809,  1810,  1811,  1812,  1813,  1815,  1816,  1818,  1819,
    1821,  1838,  1855,  1857,  1858,  1860,  1862,  1863,  1865,  1868,
    1869,  1871,  1873,  1876,  1877,  1878,  1879,  1881,  1883,  1884,
    1885,  1886,  1887,  1888,  1889,  1890,  1893,  1894,  1895,  1896,
    1898,  1899,  1900,  1901,  1902,  1903,  1904,  1905,  1906,  1907,
    1909,  1910,  1911,  1912,  1915,  1916,  1917,  1918,  1919,  1920,
    1922,  1923,  1925,  1927,  1929,  1930,  1931,  1932,  1933,  1934,
    1936,  1937,  1939,  1941,  1942,  1943,  1944,  1945,  1946,  1947,
    1948,  1951,  1952,  1954,  1955,  1957,  1958,  1961,  1963,  1964,
    1966,  1967,  1969,  1971,  1972,  1974,  1976,  1976,  1977,  1977,
    1978,  1978,  1979,  1979,  1980,  1980,  1981,  1981,  1982,  1982,
    1983,  1983,  1984,  1984,  1985,  1985,  1986,  1986,  1987,  1987,
    1988,  1988,  1989,  1989,  1990,  1990,  1991,  1991,  1994,  1996,
    1998,  1999,  2001,  2002,  2004,  2005,  2006,  2007,  2008,  2010,
    2068,  2127,  2128,  2130,  2131,  2132,  2137,  2138,  2140,  2141,
    2143,  2144,  2146,  2147,  2148,  2150,  2151,  2153,  2158,  2216,
    2276,  2277,  2279,  2280,  2281,  2282,  2283,  2284,  2285,  2287,
    2289,  2290,  2291,  2292,  2293,  2295,  2295,  2296,  2297,  2298,
    2299,  2300,  2301,  2302,  2303,  2304,  2305,  2306,  2307,  2309,
    2311,  2313,  2316,  2318,  2319,  2320,  2321,  2322,  2323,  2324,
    2326,  2328,  2330,  2332,  2333,  2335,  2335,  2337,  2338,  2339,
    2340,  2341,  2342,  2344,  2345,  2346,  2348,  2349,  2351,  2352,
    2353,  2355,  2357,  2359,  2361,  2363,  2365,  2366,  2368,  2369,
    2371,  2373,  2374,  2375,  2376,  2377,  2378,  2379,  2380,  2382,
    2383,  2384,  2385,  2386,  2387,  2388,  2389,  2391,  2392,  2394,
    2396,  2397,  2399,  2401,  2403,  2405,  2406,  2409,  2411,  2412,
    2415,  2416,  2418,  2420,  2420,  2422,  2424,  2426,  2427,  2428,
    2429,  2431,  2432,  2434,  2434,  2436,  2437,  2439,  2440,  2443,
    2443,  2445,  2446,  2447,  2448,  2450,  2452,  2453,  2455,  2456,
    2458,  2459,  2461,  2462,  2463,  2464,  2465,  2466,  2467,  2468,
    2469,  2470,  2471,  2473,  2474,  2475,  2476,  2477,  2478,  2480,
    2481,  2482,  2483,  2487,  2488,  2489,  2490,  2492,  2493,  2495,
    2496,  2497,  2498,  2500,  2501,  2502,  2504,  2505,  2506,  2507,
    2508,  2509,  2510,  2511,  2512,  2513,  2514,  2515,  2516,  2517,
    2520,  2521,  2523,  2524,  2525,  2526,  2527,  2528,  2529,  2530,
    2532,  2533,  2534,  2535,  2536,  2537,  2540,  2542,  2544,  2545,
    2547,  2549,  2551,  2552,  2553,  2555,  2557,  2558,  2560,  2561,
    2563,  2564,  2566,  2567,  2569,  2570,  2572,  2573,  2575,  2576,
    2577,  2579,  2580,  2581,  2582,  2583,  2584,  2589,  2591,  2592,
    2593,  2594,  2596,  2597,  2598,  2600,  2601,  2602,  2603,  2605,
    2606,  2607,  2608,  2609,  2611,  2613,  2615,  2616,  2617,  2618,
    2619,  2621,  2622,  2623,  2624,  2625,  2627,  2629,  2631,  2632,
    2633,  2635,  2635,  2637,  2638,  2639
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ABSTRACT", "CONTINUE", "FOR", "NEW",
  "SWITCH", "ASSERT", "DEFAULT", "IF", "PACKAGE", "SYNCHRONIZED",
  "BOOLEAN", "DO", "GOTO", "PRIVATE", "THIS", "BREAK", "DOUBLE",
  "IMPLEMENTS", "PROTECTED", "THROW", "BYTE", "ELSE", "IMPORT", "PUBLIC",
  "THROWS", "CASE", "ENUM", "RETURN", "TRANSIENT", "CATCH", "EXTENDS",
  "INT", "SHORT", "TRY", "CHAR", "FINAL", "INTERFACE", "STATIC", "VOID",
  "CLASS", "FINALLY", "LONG", "STRICTFP", "VOLATILE", "CONST", "FLOAT",
  "NATIVE", "SUPER", "WHILE", "UNDERSCORE", "EXPORTS", "OPENS", "PRINT",
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
  "PrintStatement", "StatementNoShortIf",
  "StatementWithoutTrailingSubstatement", "$@57", "EmptyStatement",
  "LabeledStatement", "LabeledStatementNoShortIf", "ExpressionStatement",
  "StatementExpression", "IfThenStatement", "IfThenElseStatement",
  "IfThenElseStatementNoShortIf", "AssertStatement", "SwitchStatement",
  "$@58", "SwitchBlock", "SwitchRule", "SwitchBlockStatementGroup",
  "SwitchLabel", "CaseConstant", "Whilesym", "WhileStatement",
  "WhileStatementNoShortIf", "DoStatement", "ForStatement",
  "ForStatementNoShortIf", "ForSym", "BasicForStatement",
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374
};
# endif

#define YYPACT_NINF (-1087)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-746)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1323, -1087,    25, -1087, -1087,    43, -1087,    25, -1087,    25,
   -1087,    25, -1087,    25, -1087,   107,    25, -1087,  1953,  1675,
    1188, -1087,   177, -1087, -1087,  1371, -1087, -1087, -1087, -1087,
   -1087, -1087, -1087, -1087, -1087, -1087,   218, -1087, -1087, -1087,
   -1087, -1087,   147,    25,   425,   531,    71,    89,   454,   306,
      25, -1087,  1675, -1087, -1087, -1087,    25,    25,    25,   218,
   -1087, -1087,  1371,  1675,    25,   816,    91,    73, -1087,    25,
     692,    88,   774, -1087,   220, -1087,   247,    25,   604,   122,
   -1087,    25,    25,    87,   146,   257, -1087,    25,    25,   246,
     203,   271,   267, -1087,   273,   324,   401,    71,    89,   454,
      91,    73,  1675,   356,   286,   347, -1087, -1087, -1087, -1087,
   -1087, -1087, -1087, -1087, -1087,   326, -1087, -1087, -1087,   451,
     326, -1087,   350,   362, -1087,    73,  3472,   337, -1087, -1087,
   -1087,    25,   346, -1087,   354,   390, -1087,   408, -1087,   448,
   -1087, -1087,  2759,   545,    25, -1087,   811,   592,   464,   479,
   -1087, -1087,   486,   435,   146,   257, -1087,  4287, -1087,   146,
   -1087,   146, -1087,   601,   435,  4146, -1087,   246,   271,   267,
   -1087,   246,   267, -1087,   246, -1087,   246,   484,   842,   520,
     557,   457,   122, -1087,    87,   146,   257, -1087,   246,   203,
     271,   267, -1087,    73,   337, -1087,    25, -1087,    25,   286,
   -1087, -1087,   591,   326, -1087,    25, -1087,   326, -1087,  1072,
     362, -1087,   337, -1087,   564,    25,  3368, -1087, -1087,  4385,
    4189,   582, -1087,   905, -1087, -1087, -1087,    25, -1087,   316,
     615, -1087, -1087, -1087,   101, -1087,   643, -1087, -1087, -1087,
   -1087, -1087,   657,   670, -1087, -1087,    25,   448, -1087,  4385,
    2759,   417, -1087, -1087,   686, -1087,   464,  5006, -1087,   246,
     246, -1087,   712, -1087, -1087,    25,    25,    25,   697, -1087,
   -1087,   146, -1087,   146, -1087, -1087,  4385,  4342, -1087,   905,
      25,   316, -1087, -1087, -1087, -1087, -1087,   146, -1087,   697,
     697, -1087,  4244, -1087,   246,   267, -1087,   246, -1087,   246,
   -1087,   246, -1087,   246, -1087,   246, -1087, -1087,    25,    25,
      66,    25,    25,   561, -1087,   717,   842,   736,   842,   743,
   -1087,   146,   257, -1087, -1087,   146, -1087,   146, -1087,   246,
     271,   267, -1087,   246,   267, -1087,   246, -1087,   246,   337,
   -1087, -1087,   718, -1087, -1087, -1087, -1087, -1087, -1087, -1087,
   -1087, -1087, -1087,   492, -1087,  1072,   750,  6728,   773,   788,
    4675, -1087,   543,  6728,  5088, -1087,   748,   664, -1087, -1087,
   -1087,   800, -1087, -1087, -1087, -1087,   805,   803, -1087, -1087,
   -1087, -1087, -1087,    25, -1087,  6728, -1087, -1087, -1087, -1087,
   -1087, -1087, -1087,  6728,  6728,  6728, -1087, -1087,   808,  3025,
     325, -1087, -1087,   579,   831, -1087, -1087,   418,   810, -1087,
     838,  3593, -1087, -1087,   840,    25, -1087, -1087, -1087,   564,
   -1087, -1087, -1087,   857, -1087, -1087, -1087, -1087,   875, -1087,
   -1087, -1087,   891, -1087,   932, -1087, -1087, -1087, -1087, -1087,
   -1087, -1087,   837, -1087, -1087,   666,   901, -1087,   701, -1087,
     641,   732,   742, -1087, -1087, -1087,   796, -1087, -1087,   668,
     841,   866,    25,   316,   101,   643, -1087, -1087, -1087,  1756,
     475,    25,   615,   506,   860, -1087,   914, -1087, -1087, -1087,
    4440,   995,    25,  3709,   643, -1087, -1087, -1087, -1087, -1087,
   -1087, -1087, -1087,   920, -1087, -1087, -1087,  6728,  6728,  6728,
    6728,  6728, -1087,   593,   418,   810, -1087, -1087,   925,   935,
   -1087, -1087, -1087,   230,   962,   964,   965,   970,   745,   541,
   -1087,   859,   913,   404, -1087, -1087, -1087, -1087,   668, -1087,
   -1087, -1087, -1087, -1087, -1087, -1087,   486,   955, -1087, -1087,
     146, -1087,    25,   316, -1087, -1087,   876, -1087, -1087, -1087,
   -1087,   246, -1087,   246, -1087,   246, -1087, -1087,   246, -1087,
   -1087,   380,   394,   424,   477,    66, -1087, -1087,   836,   854,
     921,    60,    74, -1087, -1087, -1087,   596, -1087,   611,   963,
     842, -1087,   146, -1087,   146, -1087,   146, -1087, -1087,   246,
     267, -1087,   246, -1087,   246, -1087,   246, -1087,   246, -1087,
     246, -1087, -1087,    25,   718, -1087, -1087,   969,   530,   986,
   -1087,  1004,  6728,   144,  6728,  6728,   775,  1024, -1087,  1000,
    1022, -1087,  1025,  1086,    25,    25,  6728,  1033,   516,   565,
   -1087, -1087, -1087, -1087,  1043, -1087,    25,  4675,  5170,   110,
      25,   559,  5170,   338,    25,   634,  5252,  1111,    44, -1087,
    3593, -1087, -1087,   326,  1046, -1087, -1087,  6728,  3907,  6728,
    4071, -1087,   332,   564,    52,    25,  6728, -1087, -1087, -1087,
    6728, -1087, -1087,   971, -1087,   643, -1087, -1087,  4470,    64,
    1060, -1087,  1502,   726,  1049,  1063, -1087, -1087,  4506, -1087,
     995,   326, -1087,    25,  5334,   326,  4536,    49,  1071, -1087,
   -1087, -1087,  1069,  1078,   397, -1087,   751,   895,  3825,  1076,
     756, -1087,  6728, -1087, -1087, -1087, -1087,  1080,   418,   314,
   -1087,  6728,   935, -1087,  6728,  6728,  6728,  6728,  6728,  6728,
    6728,  6728,  6728,  6728,  6728,  6728,  1072,  6728,  6728,  6728,
    6728,  6728,  6728,  6728,  6728, -1087,   981, -1087, -1087, -1087,
     246, -1087, -1087, -1087,    25, -1087,    25, -1087,    25, -1087,
      25, -1087, -1087,   928, -1087,    25, -1087, -1087,    25,    25,
   -1087, -1087, -1087,   655, -1087,   146, -1087, -1087, -1087,   246,
   -1087,   246, -1087,   246, -1087, -1087,   246, -1087, -1087, -1087,
   -1087, -1087,  5170,   937,  1074,   986, -1087,   937,   986,  5416,
    1089,  6728, -1087,  1092,  1093,  1095, -1087, -1087, -1087, -1087,
    1096, -1087,  1099, -1087, -1087,  1046, -1087,  1097,    25, -1087,
   -1087,   758,  1104, -1087, -1087,  1161,  1100, -1087, -1087,   764,
    1106, -1087, -1087,  1171, -1087,  1108, -1087, -1087, -1087, -1087,
    1109,  5498,  4566,   936,  1135,  1107,  1122, -1087,  1112,  4071,
   -1087,   450,   565, -1087,  1114,  1124,   666,     1, -1087, -1087,
   -1087,  1180,  1205, -1087,   332,  1132, -1087, -1087,  1128, -1087,
   -1087, -1087, -1087,  1133, -1087,  1224,  1130, -1087,   769,    25,
   -1087, -1087,  1502,  1063, -1087,  4596, -1087,  1138, -1087, -1087,
    4842, -1087, -1087, -1087,   326,   326,  1139,   651,   326,    25,
    1069, -1087,  5580,  5662,   373,   413, -1087,  1140, -1087,    83,
    1144,  6728,  6810,     8, -1087, -1087,  1159,   962,   964,   965,
     970,   745,   541,   541,   859,   859,   859,   859,   326, -1087,
     326, -1087,   913,   913,   913,   404,   404, -1087, -1087, -1087,
   -1087, -1087,   851,   864,   880,   887, -1087, -1087,   917,   943,
     966,   975, -1087, -1087, -1087,   246, -1087, -1087, -1087,  1136,
   -1087,   326, -1087, -1087,   326,   246,  1145, -1087,  1147,  4766,
   -1087,  6728,  5744,  1148, -1087,  1142,    25,    25,  5826, -1087,
   -1087,    25,    25,  5908, -1087, -1087,  4675,  6883,  1149,  7491,
    1107, -1087,  5990,  4675, -1087,  1124, -1087, -1087,  1158,   564,
   -1087,  1205, -1087,  1180, -1087,  6072, -1087, -1087, -1087, -1087,
      25, -1087, -1087, -1087, -1087, -1087,  1162, -1087, -1087,  1156,
    1153,  1163,   326,   326,   326, -1087, -1087,  1164,  1168,  1166,
    1176,   429,   489, -1087,  1178, -1087, -1087, -1087,  6810,  6728,
   -1087,    25,   991, -1087, -1087,  1013, -1087,  1018, -1087,  1020,
   -1087,  1027, -1087,  1029, -1087,  1031, -1087,  1053, -1087, -1087,
   -1087,   246,  1177, -1087,  1183,   821, -1087,  1266,  1267, -1087,
   -1087,  1186, -1087, -1087,  1187, -1087,  1211, -1087,   564,  1189,
   -1087,  1191, -1087,  1195, -1087, -1087,  1196,  1199, -1087, -1087,
    1200, -1087,  4675,  1202, -1087,  6959, -1087, -1087,  7035,  1201,
   -1087,    66, -1087, -1087, -1087, -1087,  1207, -1087, -1087, -1087,
    5334, -1087,   326, -1087,  1203, -1087,  1206,  6154,  6236,  6318,
    1177, -1087, -1087,  1198, -1087, -1087, -1087, -1087, -1087, -1087,
   -1087, -1087, -1087, -1087,    81, -1087,  6728,  4766,  4675,  6728,
    3989,  6728, -1087,  1208, -1087,  6400, -1087,  6482, -1087, -1087,
    4675,  4675,  1210,  4675,  1212,  7111,    66,  1223,  1215,    25,
   -1087, -1087, -1087, -1087,  1213,  1216,  1217,  1220,  1218,  1221,
   -1087, -1087,  6728, -1087,   243,   276, -1087,   285, -1087,  1084,
    1225, -1087, -1087,  1226,  6564,  1219,  1228, -1087, -1087,  1229,
   -1087,  1233, -1087, -1087,  4675, -1087,  4675,  4675,  1234,    25,
      25,  1223, -1087,   564, -1087, -1087,  1230, -1087,  1231, -1087,
    1235,  1232, -1087, -1087,   289, -1087,  1241, -1087, -1087,  1263,
   -1087,   309, -1087,  1269,  3593,  4924,  4766,  4766,  7187,  1239,
    6646,  4766, -1087, -1087, -1087, -1087, -1087,  4675, -1087, -1087,
   -1087, -1087, -1087, -1087, -1087,  6728,  1232, -1087, -1087, -1087,
   -1087, -1087,  3210, -1087, -1087, -1087,  1242,  1331, -1087,  4766,
    1252,  7263,  7339,  1248, -1087, -1087, -1087, -1087, -1087, -1087,
    4766, -1087,  4766,  4766,  1260,  4766,  1262,  7415, -1087, -1087,
   -1087,  4766, -1087,  4766,  4766,  1264, -1087, -1087, -1087,  4766,
   -1087
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
     404,    45,     0,   395,    84,     0,   495,   408,   292,     0,
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
     396,   342,   317,     0,   550,     0,     0,     0,     0,     0,
     495,   614,     0,     0,     0,   585,     0,     0,   542,    90,
      91,     0,    92,    93,    94,    95,    85,    97,    98,    99,
     100,   101,   102,   103,   104,     0,   105,   106,   107,   108,
     109,   110,   111,     0,     0,     0,   468,   509,    88,     0,
     682,   135,   612,   733,     0,   475,   480,   303,   305,   476,
       0,   470,   472,   473,     0,     0,   474,   488,   482,     0,
     497,   483,   498,     0,   484,   485,   499,   500,     0,   486,
     501,   487,     0,   546,     0,   547,   502,   508,   503,   504,
     506,   505,     0,   507,   590,   731,   610,   613,   618,   629,
     619,   620,   621,   622,   611,   513,     0,   514,   515,     0,
     516,   517,     0,     0,     0,     0,   409,    49,   347,     0,
     304,     0,     0,   299,     0,   295,   297,   340,   310,   339,
       0,   312,     0,   495,     0,   343,   413,   159,   160,    33,
      32,    35,   377,     0,    96,    97,   103,     0,     0,     0,
       0,     0,   382,   732,     0,     0,   618,   621,     0,   660,
     677,   679,   678,   686,   688,   690,   692,   694,   696,   698,
     706,   701,   708,   712,   715,   719,   720,   723,   726,   734,
     735,   729,   730,   388,   389,   379,    24,    25,    23,   429,
       0,   427,     0,     0,   453,    51,     0,   461,   423,   283,
     232,     0,   237,     0,   228,     0,   226,   220,     0,   218,
     214,     0,     0,     0,     0,     0,    17,   131,     0,     0,
       0,     0,     0,   167,    16,   169,     0,   173,     0,     0,
       0,   441,     0,   446,     0,   437,     0,   435,   256,     0,
     267,   265,     0,   261,     0,   248,     0,   253,     0,   244,
       0,   242,   400,     0,   129,     5,   578,     0,   637,     0,
     114,     0,     0,     0,     0,     0,   682,     0,   575,     0,
       0,   580,     0,     0,     0,     0,     0,     0,   732,   733,
     619,   620,   724,   725,     0,   481,     0,   495,     0,     0,
       0,   309,     0,     0,     0,     0,     0,     0,     0,   469,
     471,    52,   477,   299,   478,   496,   512,     0,     0,     0,
       0,   586,     0,     0,     0,     0,     0,   113,   112,   685,
       0,   736,   737,     0,   311,     0,   345,   414,     0,     0,
       0,   348,     0,     0,     0,   328,   332,   347,     0,   316,
     314,   300,   293,     0,     0,   318,     0,     0,     0,   313,
     338,   335,   336,   614,     0,   356,   682,   681,   495,     0,
     731,   344,     0,   728,   727,   721,   722,     0,   114,     0,
     383,     0,   661,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   431,     0,   462,   459,   236,
       0,   234,   230,   222,     0,   182,     0,   191,     0,   185,
       0,   194,    18,     0,   180,     0,   188,   197,     0,     0,
     171,   175,   177,     0,   445,     0,   443,   439,   264,     0,
     269,     0,   260,     0,   258,   252,     0,   250,   246,   130,
       6,   579,     0,     0,   638,   672,    78,     0,   670,     0,
       0,     0,   523,     0,     0,     0,   576,   582,   581,   628,
     640,   666,     0,   577,   617,   479,   510,     0,     0,   615,
     623,     0,   133,   630,   662,     0,     0,   616,   624,     0,
     134,   631,   663,     0,   647,     0,   627,   669,   665,    53,
       0,     0,     0,   682,   568,   570,     0,   567,     0,   607,
      72,   744,   743,   608,     0,   606,     0,   619,   609,   593,
     599,   587,   591,   588,   601,   639,   632,   664,     0,   680,
     294,   346,   350,     0,   326,     0,     0,     7,     0,     0,
     330,   349,     0,   329,    36,     0,   352,     0,   315,   296,
       0,   298,   302,   301,   319,   322,     0,   299,   320,     0,
     337,    39,     0,     0,     0,     0,   358,     0,   357,     0,
       0,     0,     0,     0,    77,    76,     0,   689,   691,   693,
     695,   697,   699,   700,   703,   702,   705,   704,   124,   707,
       0,   125,   709,   710,   711,   713,   714,   716,   717,   718,
     460,   238,     0,     0,     0,     0,   181,   132,     0,     0,
       0,     0,   179,   447,   268,     0,   266,   262,   254,     0,
     675,   673,    79,   674,   671,   633,     0,   525,     0,   495,
     583,     0,     0,     0,   643,   637,     0,     0,     0,   625,
     644,     0,     0,     0,   626,   646,   495,     0,     0,     0,
     571,    64,     0,   495,    73,     0,   605,    74,     0,     0,
     589,   592,    67,   603,   602,     0,   645,   351,   327,     8,
       0,   331,   333,    38,    37,   354,     0,   353,   463,     0,
     466,     0,   323,   324,   321,    41,    40,     0,     0,     0,
       0,     0,     0,   359,     0,   741,   738,   739,     0,     0,
     183,     0,     0,    19,   192,     0,   186,     0,   195,     0,
     189,     0,   202,     0,   200,     0,   198,     0,   270,   676,
     634,   635,     0,   524,     0,   682,   520,     0,   482,   491,
     492,     0,   493,   494,     0,   548,     0,   549,     0,     0,
     654,     0,   489,   641,   667,   648,     0,   642,   668,   650,
       0,   543,   495,     0,   569,     0,    66,    65,     0,     0,
     573,     0,   600,    68,   604,   652,     0,   334,   355,   464,
       0,   465,   325,   360,     0,   362,     0,     0,     0,     0,
       0,   740,   687,    21,   184,    20,   193,   187,   196,   190,
     201,   203,   199,   636,     0,   526,     0,   495,   495,     0,
       0,     0,   584,     0,   655,     0,   649,     0,   651,   551,
     495,   495,     0,   495,     0,     0,     0,   597,     0,     0,
     653,   467,   361,   363,     0,     0,     0,     0,     0,     0,
     742,   540,     0,   529,     0,     0,    58,     0,    56,     0,
       0,   511,   521,     0,     0,     0,     0,   545,   656,     0,
     658,     0,   552,   553,   495,   555,   495,   495,     0,     0,
       0,   598,    69,     0,   595,   364,     0,   366,     0,   368,
       0,   538,   541,   531,     0,    57,     0,   530,    59,     0,
     527,     0,    54,     0,    60,     0,   495,   495,     0,     0,
       0,   495,   657,   659,   554,   556,   557,   495,   596,    71,
      70,   594,   365,   367,   369,     0,   539,    61,   532,    60,
     528,    55,   495,   536,   534,   535,     0,     0,   544,   495,
       0,     0,     0,     0,   574,   558,    63,    62,   537,   533,
     495,   559,   495,   495,     0,   495,     0,     0,   522,   560,
     561,   495,   563,   495,   495,     0,   562,   564,   565,   495,
     566
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1087,  2239,   -20,   653,  -454, -1087,  1345,   322,   297,  -281,
   -1087,   157,  -292,  -131,  -246,  -106, -1087,  1174, -1087,  1131,
    1214, -1087,   494, -1087,   480, -1087,  1238, -1087,  1165, -1087,
   -1087, -1087, -1087, -1087, -1086, -1080, -1087,   139, -1087,   396,
   -1087, -1087,   194, -1087,   549, -1087,   677,   792,  -295,    -2,
   -1087, -1087, -1087,   902, -1087, -1087, -1087, -1087,  1209, -1087,
    -592,  -534,    59, -1087, -1087, -1087, -1087, -1087,   239, -1087,
   -1087, -1087, -1087,   410,  1386, -1087, -1087, -1087, -1087, -1087,
   -1087, -1087, -1087,  -294,   -97, -1087, -1087, -1087, -1087, -1087,
   -1087, -1087, -1087, -1087, -1087, -1087, -1087, -1087, -1087, -1087,
   -1087, -1087, -1087, -1087, -1087, -1087, -1087, -1087, -1087, -1087,
   -1087, -1087, -1087, -1087, -1087, -1087, -1087, -1087,   423, -1087,
      46,   244,  1324,   159,  2396,   -58, -1087, -1087,  -209,   713,
    -673,   721,  1352,   706,   794, -1087,    19,  -125,   940, -1087,
    -459,   536, -1087,  -403, -1087,   521,  -224, -1087, -1087, -1087,
     949,  -118,  -198, -1087, -1087,   -32, -1087, -1087, -1087,  1277,
     625,    -3, -1087,   222, -1087,  1227, -1087,    48,  1204,  1222,
   -1087,   359,  -203, -1087, -1087, -1087, -1087, -1087, -1087, -1087,
   -1087, -1087, -1087, -1087, -1087, -1087, -1087, -1087, -1087,    -4,
      20,    14,  -136,  1146, -1087, -1087,   -23,   312,  -187,  -477,
    -381, -1087, -1087,  -656,  -391,  1351, -1087,  -697,  -676, -1087,
   -1087, -1087, -1087, -1087,  -630, -1087, -1087, -1087, -1087, -1087,
   -1087,   305,  -898,   252,  -845,   183,  -207, -1087, -1087, -1087,
   -1087, -1087,  -112, -1087, -1087,   290,  -855,  -657,    27, -1087,
   -1087, -1087, -1087, -1087, -1087,   207, -1087, -1087, -1087,   770,
   -1087,   570,  -823, -1087, -1087,   281,  -791, -1087, -1087, -1087,
   -1087,   590,  -449, -1087, -1087,   471,  -543, -1087,  1649,  2376,
     630,  -600, -1087, -1087,    95,  2363, -1087,   700, -1087, -1087,
    -962, -1087,   720,   722,   716,   719,   724,   328, -1087,    90,
     385,   440,  -341,   946,  1016,  -872,  1175,  1377,  1626, -1087,
   -1087, -1087, -1087
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   641,   204,   604,   678,   875,    18,    19,   794,   313,
     565,  1042,  1043,   268,   269,    20,   199,   200,   247,   248,
     250,   883,   884,   900,   901,   144,   145,   210,   211,   220,
     277,   650,  1221,  1174,  1175,  1176,  1246,  1247,   990,   991,
    1001,  1201,  1202,   849,   850,   722,   723,   795,    21,   503,
     401,   402,   669,   609,   116,   117,   118,   929,   104,   197,
     605,   568,   403,   404,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   177,   178,   315,   316,   317,
     318,   579,   580,   314,    33,    34,    89,   176,   174,   305,
     171,   303,   301,   558,   167,   299,   297,   555,   294,   553,
     551,   750,   188,   338,   336,   600,   333,   598,   596,   786,
     329,   594,   592,   783,   589,   781,   779,   955,   223,   105,
      91,    79,   140,    93,   166,   224,   225,   226,   474,   475,
     476,  1020,   406,   504,   505,   228,   229,   230,   481,   680,
     684,   685,   686,   484,   701,   702,   478,   231,   232,   233,
     469,   234,   485,   708,    35,    80,   147,   259,   260,   148,
     149,    36,    37,    67,   122,   123,   124,   128,   235,   236,
     237,    38,    39,    84,   161,   159,   287,   154,   273,   271,
     540,   185,   327,   325,   586,   321,   584,   582,   775,    40,
      85,    86,   158,   283,   284,   285,   892,  1021,   239,   410,
     411,   412,   413,   414,   415,   416,   417,  1067,   418,   419,
     420,   421,  1069,   422,   423,   424,   425,  1070,   426,   427,
    1062,  1135,  1177,  1178,  1219,  1211,   428,   429,  1072,   430,
     431,  1073,   432,   433,  1075,   846,  1093,  1094,   434,   435,
    1077,   436,   437,   438,   439,   440,   441,  1078,   442,   662,
     443,   861,   862,   998,  1158,  1159,   863,   999,   444,   663,
     854,   855,   445,   446,   447,   506,   449,   611,   450,   451,
     507,   508,   453,   454,   796,   509,   510,   511,   456,   670,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,  1120,   858
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,   847,   844,    44,   853,    46,   709,    47,   636,    48,
     880,    49,   790,   409,    51,   566,    60,    59,   270,   574,
     219,   698,   538,   286,   880,   288,   696,   351,   845,   222,
     651,   763,   289,   290,   710,   576,   249,   578,   486,  1002,
    1037,    71,   479,   538,   538,   222,   835,   150,    96,   324,
     837,   276,   632,   633,    97,    98,    99,   547,   818,   249,
     278,   675,   103,   115,    45,   183,   874,   129,   222,     1,
    1000,   546,   136,  1004,   138,   139,   146,  1122,   699,   139,
     152,   874,     3,    43,   252,   162,   163,     4,  1214,   818,
    1171,    77,     6,    77,   479,  1218,   823,   156,   472,   160,
     831,   464,    72,   155,     8,   603,    10,   252,  -745,  1172,
     399,    12,   187,  -745,   219,  1038,   818,   206,   186,   405,
      81,   866,    81,   222,   221,   768,    14,   819,   482,   241,
     136,   464,   138,  1034,  1218,   539,   168,   541,  1252,   769,
     251,   153,   146,    41,   249,   190,    82,   164,    82,   195,
     320,   548,   820,   222,   472,   115,   713,   714,   715,   716,
     821,    41,    41,   251,   879,    50,  1121,    41,    64,   272,
      41,   276,  1218,   213,   265,   240,   281,    61,  1103,    78,
     278,   126,    41,   346,    41,   581,   249,   346,   267,   585,
    1173,   587,   491,   853,   342,   222,   103,    65,   323,   966,
     326,    41,   132,   347,   322,  1011,   654,   115,   409,   483,
    1212,   856,  1104,   352,   400,    60,    59,   221,   221,   873,
     942,   470,   943,    77,   944,   473,   945,   801,    41,   887,
      78,   907,   655,   885,   491,   330,    87,   896,   463,   674,
    1152,   340,   341,  1154,   489,    60,    59,   251,   251,   170,
     173,   175,  1171,   673,   157,   661,   802,    53,   192,    68,
     350,    69,    88,   136,   536,   138,   676,   677,   463,   839,
     762,  1172,    60,    59,   115,   115,   479,   115,   473,  1222,
     409,   101,   574,  1212,   574,  1171,   711,   888,   125,  1179,
     251,    77,    92,  1068,  1171,   543,   281,    64,  1171,   773,
    1198,    53,  1028,  1030,  1172,   399,   561,   563,   567,   569,
     571,   127,   724,  1172,   405,   135,    82,  1172,  1171,   747,
     725,   790,   193,  1251,    65,   537,    88,   296,   298,  1216,
      88,   302,  1223,   746,   169,   172,   583,  1172,    41,    70,
      52,   182,   137,   191,   818,   194,    95,    63,   332,   335,
     337,   607,  1213,   608,   165,   827,   479,   845,   616,  1096,
     619,   823,   831,   682,   859,    41,   866,   562,   564,   212,
     570,   572,  1081,  1260,   682,   860,  1223,   399,  1086,   818,
     828,    51,  -164,  1090,   102,  1217,   405,   602,   829,   196,
     819,   628,   628,   181,  1220,    60,    59,   115,  1248,   198,
     856,   937,   938,   939,   745,  1106,  1274,  1276,   637,   400,
     805,   603,   295,   653,    94,   820,  -732,  -732,  1250,   818,
      69,   912,  1285,  1031,   216,   201,  1016,   815,   477,    55,
     827,   648,   179,   331,   334,   638,   202,   339,   131,   639,
    1181,   242,   640,  -304,   754,   126,   774,   409,   776,   243,
     777,   636,   629,   629,   552,   828,    41,   208,   756,    66,
     473,  1068,    55,  1032,    41,   845,   115,   115,   845,   689,
      83,    90,    41,    55,    77,   209,   661,   871,   115,   574,
     700,   706,   100,   847,   844,   238,  1204,    87,   758,   591,
     593,    41,   755,   597,   265,   628,   628,   628,   628,   742,
     743,   238,   244,   903,   744,   409,   757,  1123,   267,   180,
     845,   624,    55,    88,   625,    69,   282,  1165,  1167,  1169,
     245,   184,   189,   468,   238,   845,  1238,   202,   202,  1257,
    1258,    41,   647,    64,  1264,  1117,   759,    73,   265,    74,
     473,   760,   707,   976,   399,  1189,   977,  1191,   266,   267,
    1068,  1068,   842,   405,   842,  1068,   629,   629,   629,   629,
     638,   246,  1271,   567,   639,   319,   205,   640,  -304,    41,
    1036,   131,   682,  1278,   590,  1279,  1280,   263,  1282,   238,
     279,   687,   682,  1068,  1286,   202,  1287,  1288,   264,   761,
     682,   267,  1290,   307,  1068,  1118,  1068,  1068,   845,  1068,
     265,   789,   399,   981,   606,  1068,   982,  1068,  1068,   238,
      41,   405,  -316,  1068,   308,   309,   202,   310,   311,   732,
     733,   346,   810,   811,   312,   346,   638,   734,   735,  -168,
     639,   845,   845,   640,   653,   616,   282,   822,   824,   953,
     792,   830,   832,    75,    69,    76,   838,   845,   400,   308,
     309,   238,   310,   311,   253,   618,   843,   142,   851,   312,
     736,    41,   865,   867,   308,   309,  -172,   310,   311,   202,
     573,   346,   216,   825,   312,   642,   115,   876,    60,   643,
     115,   653,   644,  -681,  -681,   115,   115,   448,   468,   642,
    -412,   653,   202,   643,   115,   897,   644,  -682,  -682,   279,
     279,   261,   345,   638,   142,   770,   400,   639,   308,   309,
     640,   310,   311,   141,   266,   265,   142,   143,   312,   852,
     771,   480,    41,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   928,   628,   628,   628,   628,   628,
     628,   628,   628,   842,   202,  -683,  -683,  1253,   833,   780,
    1125,   483,   567,  1125,   567,  1125,   567,  1125,   567,   671,
     672,   202,  1071,   947,   952,  1009,   948,   950,   254,   487,
     960,   120,   262,   346,   963,  1268,   682,   346,   624,   682,
     664,   625,   488,   665,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   492,   629,   629,   629,   629,
     629,   629,   629,   629,   130,   538,   131,   538,  -519,   538,
     266,   538,  1102,  -519,  -519,   603,   975,  1051,  1053,  1055,
    1057,   535,   924,   925,   926,   927,   575,   949,   951,   106,
     730,   448,   120,   731,   637,   107,  -684,  -684,    60,   108,
     115,   879,  -732,  -732,    41,   577,   452,   851,   120,  -518,
     109,   110,  -176,   111,  -518,  -518,   612,  1074,   637,   121,
     112,   638,   623,   120,   113,   904,  -732,  -732,   640,  -304,
     909,   120,   976,   665,   346,   977,   653,  1012,   981,   614,
     115,   982,   448,   115,  1010,   638,   133,    41,   134,   639,
     962,  1142,   640,   962,   615,   308,   309,   700,   310,   311,
     667,   668,   822,   830,  1137,   312,   626,   865,   852,   628,
     628,   -96,  -732,  -732,   -89,   120,   455,   257,   106,   165,
     121,  -481,   407,   114,   107,   120,   120,   648,   108,   120,
    1071,   638,  -734,  -734,    41,   639,   121,   646,   640,   109,
     110,   346,   111,   660,   346,   216,   215,   649,   764,   112,
     765,   121,   652,   113,   448,   120,   120,  -735,  -735,   121,
     737,   738,   739,  1040,  1041,   765,   766,  1065,   265,   656,
     629,   629,   692,   693,  1083,  1084,  1044,  1041,   765,  1087,
    1088,   657,   120,   120,   616,   120,  -733,  -733,   748,   693,
     452,   616,  1046,  1041,   765,  1156,  1076,   658,   120,  1048,
    1041,   765,   346,   121,   346,   642,   740,   741,  1107,   905,
     408,   666,   644,   121,   121,   659,  1241,   121,   694,  1071,
    1071,   409,   482,    41,  1071,  1074,   712,  -732,  -732,  1050,
     266,   265,   720,   767,   842,   267,   628,   628,  1254,   567,
     946,   452,   765,   121,   121,   890,   638,   202,   721,   409,
     639,   726,  1071,   640,  -304,  1052,   266,   267,   922,   923,
     455,   610,   727,  1071,   728,  1071,  1071,   729,  1071,   267,
     121,   121,   772,   121,  1071,   368,  1071,  1071,  1054,   266,
     265,   791,  1071,   870,   693,   106,   121,  1056,   266,   267,
     616,   107,   346,   940,   693,   108,   792,   629,   629,  1157,
    1045,  1047,  1049,  1124,  1041,   120,   109,   110,   448,   111,
     799,   455,   806,   452,  1074,  1074,   112,   407,   399,  1074,
     113,   448,   932,   933,   934,  1126,  1041,   405,   809,   448,
    1127,  1041,  1128,  1041,   807,  1065,   616,   808,   843,  1129,
     266,  1130,   266,  1131,   266,   813,   399,  1074,   616,   616,
     814,   616,    60,   836,  1157,   405,   881,   653,  1074,   693,
    1074,  1074,   457,  1074,  1076,  1132,   266,  1224,  1225,  1074,
     628,  1074,  1074,   877,   120,   120,   882,  1074,   898,   448,
     935,   936,   899,   455,   902,   908,   120,   911,   131,   407,
      41,     1,   616,   121,   616,   616,   967,   653,  1239,   969,
     970,   971,   972,   979,     3,   408,   973,   718,   974,     4,
     978,   980,   983,   984,     6,   985,   986,    56,  -572,   993,
     989,   996,   400,   860,  1065,  1065,     8,    57,    10,  1065,
      58,   629,   458,    12,   992,   616,   997,   859,  1005,  1006,
    1007,  1008,  1039,   628,  1009,  1017,  1023,  1059,    14,  1033,
     400,  1035,  1061,  1076,  1076,    16,    69,  1065,  1076,  1063,
    1082,  1095,   121,   121,  1101,  1109,  1110,   452,  1065,  1108,
    1065,  1065,  1111,  1065,   121,  1114,  1113,   408,  1115,  1065,
     452,  1065,  1065,  1116,  1119,  1134,  1076,  1065,   452,  1136,
    1138,  -490,  1139,  1140,  1141,   719,  1143,  1076,  1144,  1076,
    1076,  1145,  1076,  1146,   629,  1147,   457,  1148,  1076,  1150,
    1076,  1076,   765,  1155,  1160,  1162,  1076,  1194,  1163,  1196,
    1187,  1200,  1203,  1206,  1224,  1205,     1,  1208,  1210,  1207,
    1209,  1230,  1226,  1227,     2,  1231,  1232,   455,   452,     3,
    1233,  1237,  1242,  1243,     4,  1245,  1249,  1244,     5,     6,
     455,  1261,     7,  1225,  1269,  1270,   407,   457,   455,  1272,
    1277,     8,     9,    10,   407,    11,   407,  1281,    12,  1283,
      62,  1289,   913,   344,     1,   349,   458,  1014,   490,   292,
    1026,    13,   255,    14,   120,  1267,  1097,     3,   120,    15,
      16,   459,     4,   120,   120,  1240,     5,     6,   994,   915,
       7,   798,   120,   717,    54,   151,   889,   343,   455,     8,
       9,    10,   690,    11,   407,   891,    12,   119,  1013,   688,
    1025,   256,  1161,   545,   467,  1170,  1215,   458,  1266,   457,
    1185,    14,  1255,   864,  1003,    17,   348,  1199,    16,   995,
     448,   465,   930,   919,   408,   917,     0,   920,   918,     0,
       0,     0,   408,   921,   408,     0,     0,   448,   448,     0,
     448,     0,     0,     0,   448,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   121,     0,   227,     0,
       0,   121,   121,    17,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   227,     0,     0,     0,     0,   458,
       0,     0,   408,     0,     0,     1,     0,     0,     0,   280,
       0,     0,     0,     0,     0,   106,     0,   227,     3,     0,
       0,   107,     0,     4,     0,   108,     0,     0,     6,     0,
     931,     0,     0,     0,     0,   459,   109,   110,     0,   111,
       8,     0,    10,     0,     0,     0,   112,    12,   120,     0,
     113,     0,     0,     0,     0,   407,     0,     0,     0,     0,
       0,   119,    14,   448,     0,     0,   448,     0,     0,   448,
       0,   462,   227,     0,     0,   471,     0,     0,     0,     0,
       0,     0,     0,   457,     0,     0,   459,     0,   120,     0,
       0,   120,     0,   460,     0,     0,   457,     0,     0,   452,
       0,   462,   227,     0,   457,     0,     0,     0,   448,   448,
       0,   448,     0,     0,     0,     0,   452,   452,     0,   452,
      41,   448,   448,   452,   448,     0,   448,     0,   542,   280,
       0,   471,     0,     0,     0,     0,   121,     0,     0,     0,
       0,     0,     0,   408,   227,     0,     0,     0,     0,     0,
       0,     0,     0,   458,   457,     0,     0,     0,   459,     0,
       0,     0,     0,     0,     0,   448,   458,   448,   448,   455,
       0,     0,     0,     0,   458,     0,   121,     0,     1,   121,
       0,     0,     0,     0,     0,     0,   455,   455,     0,   455,
       0,     3,     0,   455,     0,   448,     4,   448,   448,   448,
       0,     6,   448,     0,     7,     0,     0,     0,   448,     0,
       0,   617,     0,     8,     9,    10,     0,    11,     0,     0,
      12,     0,   452,   448,   458,   452,     0,     0,   452,     0,
     448,     0,   448,   448,     0,    14,     0,   460,     0,     0,
       0,   448,    16,   448,   448,     0,   448,     0,   448,     0,
       0,     0,   448,     0,   448,   448,     0,     0,     0,     1,
     448,     0,     0,     0,     0,     0,     0,   452,   452,   106,
     452,     0,     3,     0,     0,   107,     0,     4,     0,   108,
     452,   452,     6,   452,     0,   452,     0,    17,   460,     0,
     109,   110,   455,   111,     8,   455,    10,     0,   455,     0,
     112,    12,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,   459,     0,     0,     0,    14,     0,     0,     0,
     679,   683,     0,     0,   452,   459,   452,   452,     0,     0,
       0,     0,   697,   459,     0,     0,     0,   455,   455,     0,
     455,     0,   461,     0,     0,     0,   407,     0,     0,     0,
     455,   455,     0,   455,   452,   455,   452,   452,   452,     0,
     460,   452,     0,   681,     0,     0,     0,   452,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,     0,   452,   459,     0,     0,     0,     0,     0,   452,
       0,   452,   452,     0,   455,     0,   455,   455,     0,     0,
     452,     0,   452,   452,     0,   452,     0,   452,     0,     0,
       0,   452,     0,   452,   452,   457,     0,     0,     0,   452,
       0,     0,     0,     0,   455,     0,   455,   455,   455,     0,
     407,   455,   457,   457,   408,   457,     0,   455,     0,   457,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   455,     0,     0,     0,     1,     0,   407,   455,
       0,   455,   455,     0,     0,     0,     0,     0,     0,     3,
     455,     0,   455,   455,     4,   455,     0,   455,     5,     6,
       0,   455,     7,   455,   455,   458,   461,     0,   816,   455,
       0,     8,     9,    10,     0,    11,     0,     0,    12,     0,
       0,     0,   458,   458,     0,   458,     0,     0,     0,   458,
       0,    13,     0,    14,   460,     0,     0,     0,   408,    15,
      16,     0,     0,     0,     0,     0,     0,   460,     0,     0,
     683,     0,     0,     0,   878,   460,     0,   461,   457,   679,
     683,   457,   630,   630,   457,     0,   408,     0,   683,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   457,   457,   460,   457,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   457,   457,     0,   457,
       0,   457,     0,     0,     0,     0,     0,     0,   458,   461,
       0,   458,     0,     0,   458,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     457,     0,   457,   457,   459,     0,   630,   630,   630,   630,
       0,     0,     0,   458,   458,     0,   458,     0,     0,     0,
       0,   459,   459,     0,   459,     0,   458,   458,   459,   458,
     457,   458,   457,   457,   457,     0,     0,   457,     0,     0,
       0,     0,     0,   457,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   457,     0,
       0,     0,     0,     0,     0,   457,     0,   457,   457,     0,
     458,     0,   458,   458,     0,     0,   457,     0,   457,   457,
       0,   457,     0,   457,     0,     0,     0,   457,     0,   457,
     457,     0,     0,     0,   683,   457,     0,   683,     0,     0,
     458,     0,   458,   458,   458,     0,     0,   458,     0,     0,
       0,     0,     0,   458,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   461,     0,     0,     0,   459,   458,     0,
     459,     0,     0,   459,     0,   458,   461,   458,   458,     0,
       0,     0,     0,     0,   461,     0,   458,     0,   458,   458,
       0,   458,     0,   458,     0,     0,     0,   458,     0,   458,
     458,     0,     0,     0,     0,   458,     0,     0,     0,   857,
       0,     0,   459,   459,     0,   459,     0,     0,     0,     0,
    1066,     0,     0,     0,     0,   459,   459,     0,   459,     0,
     459,     0,     0,     0,   461,     0,     0,  1091,     0,     0,
       0,     0,     0,     0,  1100,     0,   460,     0,     0,     0,
       0,     0,     0,     0,   203,     0,     0,     0,     0,   207,
       0,     0,     0,   460,   460,     0,   460,     0,     0,   459,
     460,   459,   459,     0,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,     0,   630,   630,   630,   630,
     630,   630,   630,   630,     0,     0,     0,     0,     0,   459,
       0,   459,   459,   459,     0,     0,   459,     0,     0,     0,
       0,     0,   459,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   459,     0,     0,
       0,     0,     0,     0,   459,     0,   459,   459,     0,     0,
       0,     0,     0,  1149,     0,   459,     0,   459,   459,     0,
     459,     0,   459,     0,     0,     0,   459,     0,   459,   459,
     203,     0,     0,     0,   459,     0,     0,     0,     0,   460,
       0,     0,   460,     0,     0,   460,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   816,  1182,
     203,     0,     0,     0,     0,     0,     0,     0,   857,     0,
       0,  1192,  1193,     0,  1195,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   460,   460,     0,   460,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   460,   460,     0,
     460,     0,   460,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   258,     0,     0,  1234,     0,  1235,  1236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     630,   630,     0,   293,     0,     0,     0,   300,     0,     0,
     304,   460,   306,   460,   460,     0,     0,  1066,  1091,     0,
       0,     0,  1100,     0,   328,     0,     0,     0,  1265,     0,
       0,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,   460,     0,   460,   460,   460,     0,     0,   460,     0,
    1149,     0,   461,   461,   460,   461,     0,     0,     0,   461,
       0,  1182,     0,  1192,  1193,     0,  1195,     0,     0,   460,
       0,     0,  1234,     0,  1235,  1236,   460,     0,   460,   460,
    1265,     0,   645,     0,     0,     0,   207,   460,     0,   460,
     460,     0,   460,     0,   460,   533,   534,     0,   460,     0,
     460,   460,     0,     0,     0,     0,   460,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   630,   630,     0,
     550,     0,     0,   554,     0,   556,     0,   557,     0,   559,
       0,   560,     0,     0,     0,     0,     0,     0,     0,   203,
       0,     0,   691,     0,     0,     0,     0,     0,   461,     0,
     613,   461,     0,     0,   461,   588,   620,   622,     0,   595,
       0,     0,   599,     0,   601,     0,     0,     0,     0,     0,
       0,     0,     0,   207,     0,     0,     0,     0,   627,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   634,     0,
       0,     0,     1,   461,   461,     0,   461,     0,     0,   631,
     631,     0,   106,     0,     0,     3,   461,   461,   107,   461,
       4,   461,   108,     0,     0,     6,     0,     0,     7,     0,
       0,     0,     0,   109,   110,     0,   111,     8,     9,   214,
     215,    11,     0,   112,    12,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
     461,   630,   461,   461,     0,     0,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,     0,
       0,     0,     0,     0,     0,     0,     0,   793,   797,     0,
     461,     0,   461,   461,   461,     0,     0,   461,     0,     0,
       0,     0,     0,   461,   634,     0,     0,   216,   645,     0,
       0,   218,     0,   631,   631,   631,   631,    41,   461,     0,
       0,     0,     0,     0,     0,   461,     0,   461,   461,     0,
       0,     0,   691,     0,   630,     0,   461,     0,   461,   461,
       0,   461,     0,   461,     0,     0,     0,   461,     0,   461,
     461,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   894,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   645,   749,     0,   751,
       0,   752,     0,     0,   753,     0,     0,   207,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   800,     0,   803,   804,     0,
       0,     0,     0,     0,     0,   778,     0,     0,   782,   812,
     784,     0,   785,     0,   787,     0,   788,     0,     0,     0,
       0,   817,     0,     0,     0,   826,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     840,     0,   848,     0,     0,     0,     0,     0,     1,   868,
       0,     0,     0,   869,   961,     0,   631,   964,   106,     0,
       0,     3,     0,     0,   107,     0,     4,     0,   108,     0,
       0,     6,     0,     0,    56,     0,     0,   893,     0,   109,
     110,     0,   111,     8,    57,    10,     0,    58,     0,   112,
      12,     0,     0,   113,     0,   910,     0,     0,     0,     0,
       0,     0,     0,     0,   914,    14,   635,   916,     0,     0,
       0,   645,    16,     0,     0,     0,     0,     0,     0,     0,
       0,   631,   631,   631,   631,   631,   631,   631,   631,   631,
     631,   631,     0,   631,   631,   631,   631,   631,   631,   631,
     631,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1022,     0,   691,  1024,     0,     0,
       0,     0,     0,    41,     0,     0,   941,     0,     0,     0,
       0,     0,     0,     0,     0,   959,     0,     0,     0,     0,
       0,     0,     0,     0,   968,     0,     0,   203,     0,   207,
       0,     0,     0,     0,     0,   954,     0,   956,     0,   957,
       0,     0,   958,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   988,     0,     0,     0,     0,     0,
       0,     0,     0,     1,   353,   354,   355,   356,   357,  1171,
     358,     0,   359,   106,   360,   631,     3,   361,   362,   107,
       0,     4,   363,   108,     0,     0,     6,     0,  1172,     7,
     364,     0,     0,     0,   109,   110,   365,   111,     8,     9,
      10,   366,    11,   893,   112,    12,     0,     0,   113,     0,
     367,   368,  1112,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   631,   631,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   393,   394,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   395,     0,     0,     0,
       0,     0,   397,     0,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,  1079,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1058,     0,     0,     0,  1099,     0,     0,     0,     0,
       0,  1060,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,   353,   354,   355,   356,   357,     0,   358,     0,
     359,   106,   360,     0,     3,   361,   362,   107,     0,     4,
     363,   108,     0,     0,     6,     0,     0,     7,   364,     0,
       0,     0,   109,   110,   365,   111,     8,     9,    10,   366,
      11,     0,   112,    12,   631,   631,   113,     0,   367,   368,
       0,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1133,     0,   393,
     394,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   893,   395,     1,     0,   396,     0,     0,
     397,     0,     0,     0,     0,   106,   398,     0,     3,     0,
       0,   107,     0,     4,     0,   108,     0,     0,     6,  1180,
       0,     7,  1183,     0,  1186,     0,   109,   110,     0,   111,
       8,     9,   214,   215,    11,     0,   112,    12,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     0,     0,     0,     0,     0,     0,    16,
       0,     0,     0,     0,     0,     0,     0,  1229,   631,     0,
       0,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     216,   217,     0,     0,   218,     0,     0,     0,  1256,     0,
      41,     0,     0,  1263,     0,     0,     1,   353,   354,   355,
     356,   357,     0,   358,     0,   359,   106,   360,     0,     3,
     361,   362,   107,     0,     4,   363,   108,     0,     0,     6,
       0,   631,     7,   364,     0,     0,     0,   109,   110,   365,
     111,     8,     9,    10,   366,    11,     0,   112,    12,     0,
       0,   113,     0,   367,   368,     0,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   393,   394,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   395,
       0,  -495,     0,     0,     0,   397,     0,     0,     0,     0,
       0,   398,     1,   353,   354,   355,   356,   357,     0,   358,
       0,   359,   106,   360,     0,     3,   703,   362,   107,     0,
       4,   363,   108,     0,     0,     6,     0,     0,     7,   364,
       0,     0,     0,   109,   110,   365,   111,     8,     9,    10,
     366,    11,     0,   112,    12,     0,     0,   113,     0,   704,
     368,     0,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     393,   394,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   395,     0,     0,   705,     0,
       0,   397,     0,     0,     0,     0,     0,   398,     1,   353,
     354,   355,   356,   357,     0,   358,     0,   359,   106,   360,
       0,     3,   361,   362,   107,     0,     4,   363,   108,     0,
       0,     6,     0,     0,     7,   364,     0,     0,     0,   109,
     110,   365,   111,     8,     9,    10,   366,    11,     0,   112,
      12,     0,     0,   113,     0,   367,   368,     0,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,   355,     0,     0,   393,   394,     0,     0,
     106,     0,     0,     3,   361,     0,   107,     0,     4,     0,
     108,   395,     0,     6,   906,     0,     0,   397,     0,     0,
       0,   109,   110,   398,   111,     8,     0,    10,   366,     0,
       0,   112,    12,     0,     0,   113,     0,   367,     0,     0,
     369,   370,     0,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   496,   384,     0,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,   355,     0,     0,   393,   394,
       0,     0,   106,     0,     0,     3,   361,     0,   107,     0,
       4,     0,   108,   395,     0,     6,     0,     0,     0,   841,
       0,     0,     0,   109,   110,   398,   111,     8,     0,    10,
     366,     0,     0,   112,    12,     0,     0,   113,     0,   367,
       0,     0,   369,   370,     0,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   496,   384,     0,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,   355,     0,     0,
     393,   394,     0,     0,   106,     0,     0,     3,   361,     0,
     107,     0,     4,     0,   108,   395,     0,     6,     0,     0,
       0,  1184,     0,     0,     0,   109,   110,   398,   111,     8,
       0,    10,   366,     0,     0,   112,    12,     0,     0,   113,
       0,   367,     0,     0,   369,   370,     0,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   496,   384,
       0,   386,   387,   388,   389,   390,   391,   392,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
       0,     0,     3,     0,     0,   107,     0,     4,     0,   108,
       0,     0,     6,     0,     0,     7,     0,   395,     0,     0,
     109,   110,     0,   111,     8,     9,   214,   215,    11,   398,
     112,    12,     1,     0,   113,     0,     0,     0,     0,     0,
       0,     0,   106,     0,     0,     3,    14,     0,   107,     0,
       4,     0,   108,    16,     0,     6,     0,     0,     7,     0,
       0,     0,     0,   109,   110,    64,   111,     8,     9,   214,
     215,    11,     0,   112,    12,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,    14,
       0,     0,     0,     0,   216,   291,    16,   106,   218,     0,
       3,     0,     0,   107,    41,     4,     0,   108,    64,     0,
       6,     0,     0,     7,     0,     0,     0,     0,   109,   110,
       0,   111,     8,     9,   214,   215,    11,     0,   112,    12,
       1,     0,   113,     0,     0,     0,     0,   216,   466,     0,
     106,   218,     0,     3,    14,     0,   107,    41,     4,     0,
     108,    16,     0,     6,     0,     0,     7,     0,     0,     0,
       0,   109,   110,    64,   111,     8,     9,    10,   215,    11,
       0,   112,    12,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,    14,     0,     0,
       0,     0,   216,   549,    16,   106,   218,     0,     3,     0,
       0,   107,    41,     4,     0,   108,    64,     0,     6,     0,
       0,     7,     0,     0,     0,     0,   109,   110,     0,   111,
       8,     9,    10,   215,    11,     0,   112,    12,     1,     0,
     113,     0,     0,     0,     0,     0,   274,     0,   106,   275,
       0,     3,    14,     0,   107,    41,     4,     0,   108,    16,
       0,     6,     0,     0,    56,     0,     0,     0,     0,   109,
     110,    64,   111,     8,    57,    10,   215,    58,     0,   112,
      12,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,    14,     0,     0,     0,     0,
       0,   544,    16,   106,   275,     0,     3,     0,     0,   107,
      41,     4,     0,   108,    64,     0,     6,     0,     0,     0,
       0,     0,     0,     1,   109,   110,     0,   111,     8,     0,
      10,     0,     0,   106,   112,    12,     3,     0,   113,   107,
       0,     4,     0,   108,     0,     0,     6,     0,     0,     0,
      14,     0,     0,    41,   109,   110,     0,   111,     8,     1,
      10,     0,     0,     0,   112,    12,     0,     0,   113,   106,
       0,     0,     3,     0,     0,   107,     0,     4,     0,   108,
      14,     0,     6,     0,     0,     0,     0,     0,     0,     1,
     109,   110,     0,   111,     8,     0,    10,   695,     0,   106,
     112,    12,     3,     0,   113,   107,     0,     4,    41,   108,
       0,     0,     6,     0,     0,     0,    14,     0,     0,     1,
     109,   110,     0,   111,     8,     0,    10,   872,     0,   106,
     112,    12,     3,     0,   113,   107,     0,     4,    41,   108,
       0,     0,     6,     0,     0,     0,    14,     0,     0,     1,
     109,   110,     0,   111,     8,     0,    10,     0,     0,   106,
     112,    12,     3,   886,   113,   107,     0,     4,     0,   108,
       0,     0,     6,     0,    41,     0,    14,   635,     0,     0,
     109,   110,     0,   111,     8,     0,    10,     0,     0,     0,
     112,    12,     0,   895,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   353,
     354,   355,   356,   357,    41,   358,     0,   359,   106,   360,
       0,     0,   361,   362,   107,     0,     0,   363,   108,     0,
       0,     0,     0,  1015,     0,   364,     0,     0,     0,   109,
     110,   365,   111,     0,    41,     0,   366,     0,     0,   112,
       0,     0,     0,   113,     0,   367,   368,     0,   369,   370,
     371,   372,   373,   374,   375,   494,   495,   378,   379,   380,
     381,   382,   496,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   393,   394,     0,     0,
     353,   354,   355,   356,   357,     0,  1064,     0,   359,   106,
     360,   395,     0,   361,   362,   107,     0,   397,   363,   108,
       0,     0,     0,   398,     0,     0,   364,     0,     0,     0,
     109,   110,   365,   111,     0,     0,     0,   366,     0,     0,
     112,     0,     0,     0,   113,     0,   367,   368,     0,   369,
     370,   371,   372,   373,   374,   375,   494,   495,   378,   379,
     380,   381,   382,   496,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,     0,   355,   493,
       0,     0,     0,     0,     0,   106,     0,   393,   394,   361,
       0,   107,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,   395,     0,     0,     0,   109,   110,   397,   111,
       0,     0,     0,   366,   398,     0,   112,     0,     0,     0,
     113,     0,   367,     0,     0,   369,   370,     0,   372,   373,
     374,   375,   494,   495,   378,   379,   380,   381,   382,   496,
     384,     0,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,   497,   498,     0,     0,     0,     0,     0,     0,
     355,   493,     0,   393,   394,   499,   500,   106,     0,     0,
       0,   361,     0,   107,     0,     0,   363,   108,   501,     0,
     890,  1018,     0,     0,     0,  1019,     0,     0,   109,   110,
     398,   111,     0,     0,     0,   366,     0,     0,   112,     0,
       0,     0,   113,     0,   367,     0,     0,   369,   370,     0,
     372,   373,   374,   375,   494,   495,   378,   379,   380,   381,
     382,   496,   384,     0,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,   497,   498,     0,     0,     0,     0,
       0,     0,   355,   493,     0,   393,   394,   499,   500,   106,
       0,     0,     0,   361,     0,   107,     0,     0,     0,   108,
     501,     0,   216,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   398,   111,     0,     0,     0,   366,     0,     0,
     112,     0,     0,     0,   113,     0,   367,     0,     0,   369,
     370,     0,   372,   373,   374,   375,   494,   495,   378,   379,
     380,   381,   382,   496,   384,     0,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,   497,   498,     0,     0,
       0,     0,     0,     0,   355,   493,     0,   393,   394,   499,
     500,   106,     0,     0,     0,   361,     0,   107,     0,     0,
       0,   108,   501,   502,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   110,   398,   111,     0,     0,     0,   366,
       0,     0,   112,     0,     0,     0,   113,     0,   367,     0,
       0,   369,   370,     0,   372,   373,   374,   375,   494,   495,
     378,   379,   380,   381,   382,   496,   384,     0,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,   497,   498,
       0,     0,     0,     0,     0,     0,   355,   493,     0,   393,
     394,   499,   500,   106,     0,     0,     0,   361,     0,   107,
       0,     0,     0,   108,   501,     0,     0,     0,     0,     0,
     621,     0,     0,     0,   109,   110,   398,   111,     0,     0,
       0,   366,     0,     0,   112,     0,     0,     0,   113,     0,
     367,     0,     0,   369,   370,     0,   372,   373,   374,   375,
     494,   495,   378,   379,   380,   381,   382,   496,   384,     0,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
     497,   498,     0,     0,     0,     0,     0,     0,   355,   493,
       0,   393,   394,   499,   500,   106,     0,     0,     0,   361,
       0,   107,     0,     0,     0,   108,   501,     0,     0,     0,
       0,   345,     0,     0,     0,     0,   109,   110,   398,   111,
       0,     0,     0,   366,     0,     0,   112,     0,     0,     0,
     113,     0,   367,     0,     0,   369,   370,     0,   372,   373,
     374,   375,   494,   495,   378,   379,   380,   381,   382,   496,
     384,     0,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,   497,   498,     0,     0,     0,     0,     0,     0,
     355,   493,     0,   393,   394,   499,   500,   106,     0,     0,
       0,   361,     0,   107,     0,     0,     0,   108,   501,   834,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     398,   111,     0,     0,     0,   366,     0,     0,   112,     0,
       0,     0,   113,     0,   367,     0,     0,   369,   370,     0,
     372,   373,   374,   375,   494,   495,   378,   379,   380,   381,
     382,   496,   384,     0,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,   497,   498,     0,     0,     0,     0,
       0,     0,   355,   493,     0,   393,   394,   499,   500,   106,
       0,     0,     0,   361,     0,   107,     0,     0,     0,   108,
     501,     0,   890,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   398,   111,     0,     0,     0,   366,     0,     0,
     112,     0,     0,     0,   113,     0,   367,     0,     0,   369,
     370,     0,   372,   373,   374,   375,   494,   495,   378,   379,
     380,   381,   382,   496,   384,     0,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,   497,   498,     0,     0,
       0,     0,     0,     0,   355,   493,     0,   393,   394,   499,
     500,   106,     0,     0,     0,   361,     0,   107,     0,     0,
       0,   108,   501,   965,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   110,   398,   111,     0,     0,     0,   366,
       0,     0,   112,     0,     0,     0,   113,     0,   367,     0,
       0,   369,   370,     0,   372,   373,   374,   375,   494,   495,
     378,   379,   380,   381,   382,   496,   384,     0,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,   497,   498,
       0,     0,     0,     0,     0,     0,   355,   493,     0,   393,
     394,   499,   500,   106,     0,     0,     0,   361,     0,   107,
       0,     0,     0,   108,   501,     0,     0,     0,     0,     0,
     987,     0,     0,     0,   109,   110,   398,   111,     0,     0,
       0,   366,     0,     0,   112,     0,     0,     0,   113,     0,
     367,     0,     0,   369,   370,     0,   372,   373,   374,   375,
     494,   495,   378,   379,   380,   381,   382,   496,   384,     0,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
     497,   498,     0,     0,     0,     0,     0,     0,   355,   493,
       0,   393,   394,   499,   500,   106,     0,     0,     0,   361,
       0,   107,     0,     0,     0,   108,   501,  1027,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   110,   398,   111,
       0,     0,     0,   366,     0,     0,   112,     0,     0,     0,
     113,     0,   367,     0,     0,   369,   370,     0,   372,   373,
     374,   375,   494,   495,   378,   379,   380,   381,   382,   496,
     384,     0,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,   497,   498,     0,     0,     0,     0,     0,     0,
     355,   493,     0,   393,   394,   499,   500,   106,     0,     0,
       0,   361,     0,   107,     0,     0,     0,   108,   501,  1029,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     398,   111,     0,     0,     0,   366,     0,     0,   112,     0,
       0,     0,   113,     0,   367,     0,     0,   369,   370,     0,
     372,   373,   374,   375,   494,   495,   378,   379,   380,   381,
     382,   496,   384,     0,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,   497,   498,     0,     0,     0,     0,
       0,     0,   355,   493,     0,   393,   394,   499,   500,   106,
       0,     0,     0,   361,     0,   107,     0,     0,     0,   108,
     501,  1080,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   398,   111,     0,     0,     0,   366,     0,     0,
     112,     0,     0,     0,   113,     0,   367,     0,     0,   369,
     370,     0,   372,   373,   374,   375,   494,   495,   378,   379,
     380,   381,   382,   496,   384,     0,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,   497,   498,     0,     0,
       0,     0,     0,     0,   355,   493,     0,   393,   394,   499,
     500,   106,     0,     0,     0,   361,     0,   107,     0,     0,
       0,   108,   501,  1085,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   110,   398,   111,     0,     0,     0,   366,
       0,     0,   112,     0,     0,     0,   113,     0,   367,     0,
       0,   369,   370,     0,   372,   373,   374,   375,   494,   495,
     378,   379,   380,   381,   382,   496,   384,     0,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,   497,   498,
       0,     0,     0,     0,     0,     0,   355,   493,     0,   393,
     394,   499,   500,   106,     0,     0,     0,   361,     0,   107,
       0,     0,     0,   108,   501,  1089,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,   398,   111,     0,     0,
       0,   366,     0,     0,   112,     0,     0,     0,   113,     0,
     367,     0,     0,   369,   370,     0,   372,   373,   374,   375,
     494,   495,   378,   379,   380,   381,   382,   496,   384,     0,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
     497,   498,     0,     0,     0,     0,     0,     0,   355,   493,
       0,   393,   394,   499,   500,   106,     0,     0,     0,   361,
       0,   107,     0,     0,     0,   108,   501,     0,     0,     0,
       0,     0,  1098,     0,     0,     0,   109,   110,   398,   111,
       0,     0,     0,   366,     0,     0,   112,     0,     0,     0,
     113,     0,   367,     0,     0,   369,   370,     0,   372,   373,
     374,   375,   494,   495,   378,   379,   380,   381,   382,   496,
     384,     0,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,   497,   498,     0,     0,     0,     0,     0,     0,
     355,   493,     0,   393,   394,   499,   500,   106,     0,     0,
       0,   361,     0,   107,     0,     0,     0,   108,   501,  1105,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     398,   111,     0,     0,     0,   366,     0,     0,   112,     0,
       0,     0,   113,     0,   367,     0,     0,   369,   370,     0,
     372,   373,   374,   375,   494,   495,   378,   379,   380,   381,
     382,   496,   384,     0,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,   497,   498,     0,     0,     0,     0,
       0,     0,   355,   493,     0,   393,   394,   499,   500,   106,
       0,     0,     0,   361,     0,   107,     0,     0,     0,   108,
     501,  1164,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   398,   111,     0,     0,     0,   366,     0,     0,
     112,     0,     0,     0,   113,     0,   367,     0,     0,   369,
     370,     0,   372,   373,   374,   375,   494,   495,   378,   379,
     380,   381,   382,   496,   384,     0,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,   497,   498,     0,     0,
       0,     0,     0,     0,   355,   493,     0,   393,   394,   499,
     500,   106,     0,     0,     0,   361,     0,   107,     0,     0,
       0,   108,   501,  1166,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   110,   398,   111,     0,     0,     0,   366,
       0,     0,   112,     0,     0,     0,   113,     0,   367,     0,
       0,   369,   370,     0,   372,   373,   374,   375,   494,   495,
     378,   379,   380,   381,   382,   496,   384,     0,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,   497,   498,
       0,     0,     0,     0,     0,     0,   355,   493,     0,   393,
     394,   499,   500,   106,     0,     0,     0,   361,     0,   107,
       0,     0,     0,   108,   501,  1168,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,   398,   111,     0,     0,
       0,   366,     0,     0,   112,     0,     0,     0,   113,     0,
     367,     0,     0,   369,   370,     0,   372,   373,   374,   375,
     494,   495,   378,   379,   380,   381,   382,   496,   384,     0,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
     497,   498,     0,     0,     0,     0,     0,     0,   355,   493,
       0,   393,   394,   499,   500,   106,     0,     0,     0,   361,
       0,   107,     0,     0,     0,   108,   501,  1188,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   110,   398,   111,
       0,     0,     0,   366,     0,     0,   112,     0,     0,     0,
     113,     0,   367,     0,     0,   369,   370,     0,   372,   373,
     374,   375,   494,   495,   378,   379,   380,   381,   382,   496,
     384,     0,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,   497,   498,     0,     0,     0,     0,     0,     0,
     355,   493,     0,   393,   394,   499,   500,   106,     0,     0,
       0,   361,     0,   107,     0,     0,     0,   108,   501,  1190,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     398,   111,     0,     0,     0,   366,     0,     0,   112,     0,
       0,     0,   113,     0,   367,     0,     0,   369,   370,     0,
     372,   373,   374,   375,   494,   495,   378,   379,   380,   381,
     382,   496,   384,     0,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,   497,   498,     0,     0,     0,     0,
       0,     0,   355,   493,     0,   393,   394,   499,   500,   106,
       0,     0,     0,   361,     0,   107,     0,     0,     0,   108,
     501,     0,     0,     0,     0,     0,  1228,     0,     0,     0,
     109,   110,   398,   111,     0,     0,     0,   366,     0,     0,
     112,     0,     0,     0,   113,     0,   367,     0,     0,   369,
     370,     0,   372,   373,   374,   375,   494,   495,   378,   379,
     380,   381,   382,   496,   384,     0,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,   497,   498,     0,     0,
       0,     0,     0,     0,   355,   493,     0,   393,   394,   499,
     500,   106,     0,     0,     0,   361,     0,   107,     0,     0,
       0,   108,   501,     0,     0,     0,     0,     0,  1262,     0,
       0,     0,   109,   110,   398,   111,     0,     0,     0,   366,
       0,     0,   112,     0,     0,     0,   113,     0,   367,     0,
       0,   369,   370,     0,   372,   373,   374,   375,   494,   495,
     378,   379,   380,   381,   382,   496,   384,     0,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,   497,   498,
       0,     0,     0,     0,     0,     0,   355,   493,     0,   393,
     394,   499,   500,   106,     0,     0,     0,   361,     0,   107,
       0,     0,     0,   108,   501,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,   398,   111,     0,     0,
       0,   366,     0,     0,   112,     0,     0,     0,   113,     0,
     367,     0,     0,   369,   370,     0,   372,   373,   374,   375,
     494,   495,   378,   379,   380,   381,   382,   496,   384,     0,
     386,   387,   388,   389,   390,   391,   392,     0,     0,   355,
     497,   498,     0,     0,     0,     0,   106,     0,     0,     0,
     361,     0,   107,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   501,   109,   110,     0,
     111,     0,     0,     0,   366,     0,     0,   112,   398,     0,
       0,   113,     0,   367,     0,     0,   369,   370,     0,   372,
     373,   374,   375,   494,   495,   378,   379,   380,   381,   382,
     496,   384,     0,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,     0,   355,     0,     0,     0,     0,
       0,     0,   106,     0,   393,   394,   361,     0,   107,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,   395,
    1092,     0,     0,   109,   110,     0,   111,     0,     0,     0,
     366,   398,     0,   112,     0,     0,     0,   113,     0,   367,
       0,     0,   369,   370,     0,   372,   373,   374,   375,   494,
     495,   378,   379,   380,   381,   382,   496,   384,     0,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
       0,   355,     0,     0,     0,     0,     0,     0,   106,     0,
     393,   394,   361,     0,   107,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,   395,  1151,     0,     0,   109,
     110,     0,   111,     0,     0,     0,   366,   398,     0,   112,
       0,     0,     0,   113,     0,   367,     0,     0,   369,   370,
       0,   372,   373,   374,   375,   494,   495,   378,   379,   380,
     381,   382,   496,   384,     0,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,     0,   355,     0,     0,
       0,     0,     0,     0,   106,     0,   393,   394,   361,     0,
     107,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,   395,  1153,     0,     0,   109,   110,     0,   111,     0,
       0,     0,   366,   398,     0,   112,     0,     0,     0,   113,
       0,   367,     0,     0,   369,   370,     0,   372,   373,   374,
     375,   494,   495,   378,   379,   380,   381,   382,   496,   384,
       0,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,     0,   355,     0,     0,     0,     0,     0,     0,
     106,     0,   393,   394,   361,     0,   107,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,   395,  1197,     0,
       0,   109,   110,     0,   111,     0,     0,     0,   366,   398,
       0,   112,     0,     0,     0,   113,     0,   367,     0,     0,
     369,   370,     0,   372,   373,   374,   375,   494,   495,   378,
     379,   380,   381,   382,   496,   384,     0,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,     0,   355,
       0,     0,     0,     0,     0,     0,   106,     0,   393,   394,
     361,     0,   107,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,   395,  1259,     0,     0,   109,   110,     0,
     111,     0,     0,     0,   366,   398,     0,   112,     0,     0,
       0,   113,     0,   367,     0,     0,   369,   370,     0,   372,
     373,   374,   375,   494,   495,   378,   379,   380,   381,   382,
     496,   384,     0,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,     0,   355,     0,     0,     0,     0,
       0,     0,   106,     0,   393,   394,   361,     0,   107,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,   395,
    1273,     0,     0,   109,   110,     0,   111,     0,     0,     0,
     366,   398,     0,   112,     0,     0,     0,   113,     0,   367,
       0,     0,   369,   370,     0,   372,   373,   374,   375,   494,
     495,   378,   379,   380,   381,   382,   496,   384,     0,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
       0,   355,     0,     0,     0,     0,     0,     0,   106,     0,
     393,   394,   361,     0,   107,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,   395,  1275,     0,     0,   109,
     110,     0,   111,     0,     0,     0,   366,   398,     0,   112,
       0,     0,     0,   113,     0,   367,     0,     0,   369,   370,
       0,   372,   373,   374,   375,   494,   495,   378,   379,   380,
     381,   382,   496,   384,     0,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,     0,   355,     0,     0,
       0,     0,     0,     0,   106,     0,   393,   394,   361,     0,
     107,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,   395,  1284,     0,     0,   109,   110,     0,   111,     0,
       0,     0,   366,   398,     0,   112,     0,     0,     0,   113,
       0,   367,     0,     0,   369,   370,     0,   372,   373,   374,
     375,   494,   495,   378,   379,   380,   381,   382,   496,   384,
       0,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   393,   394,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   395,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   398
};

static const yytype_int16 yycheck[] =
{
       2,   658,   658,     5,   660,     7,   483,     9,   399,    11,
     683,    13,   604,   216,    16,   310,    20,    20,   154,   313,
     126,   480,   268,   159,   697,   161,   480,   214,   658,   126,
     411,   565,   163,   164,   483,   316,   142,   318,   236,   862,
     912,    43,   229,   289,   290,   142,   646,    79,    50,   185,
       6,   157,   393,   394,    56,    57,    58,   281,     6,   165,
     157,   464,    64,    65,     5,    97,    17,    69,   165,     3,
     861,   280,    74,   864,    76,    77,    78,  1039,   481,    81,
      82,    17,    16,    40,   142,    87,    88,    21,  1174,     6,
       9,    20,    26,    20,   281,  1175,   639,    83,   223,    85,
     643,   219,    43,    83,    38,    97,    40,   165,   107,    28,
     216,    45,    98,   112,   220,   107,     6,   119,    98,   216,
      33,   664,    33,   220,   126,    65,    60,    17,    27,   131,
     132,   249,   134,    50,  1214,   271,    90,   273,  1224,    65,
     142,    82,   144,   118,   250,    99,    59,    88,    59,   101,
     182,   287,    42,   250,   279,   157,   497,   498,   499,   500,
      50,   118,   118,   165,   115,    58,  1038,   118,    79,   155,
     118,   277,  1252,   125,   114,   127,   157,     0,  1001,   108,
     277,   108,   118,   203,   118,   321,   292,   207,   114,   325,
     109,   327,   250,   849,   196,   292,   198,   106,   184,   799,
     186,   118,   114,   205,   184,   878,   415,   209,   411,   108,
    1172,   660,  1003,   215,   216,   219,   219,   219,   220,   678,
     754,   223,   756,    20,   758,   227,   760,    83,   118,   688,
     108,   708,   419,   687,   292,   189,    33,   696,   219,   463,
    1095,   193,   194,  1098,   246,   249,   249,   249,   250,    90,
      91,    92,     9,   462,   108,   442,   112,    18,    99,   112,
     212,   114,    59,   265,   266,   267,   464,   465,   249,   650,
     565,    28,   276,   276,   276,   277,   463,   279,   280,  1177,
     483,    59,   576,  1245,   578,     9,   484,   690,    66,  1134,
     292,    20,    48,   969,     9,   276,   277,    79,     9,   580,
    1155,    62,   902,   903,    28,   411,   308,   309,   310,   311,
     312,    67,    82,    28,   411,    95,    59,    28,     9,   543,
      90,   913,   100,  1221,   106,   266,    59,   168,   169,  1174,
      59,   172,  1177,   542,    90,    91,   322,    28,   118,    42,
      18,    97,    95,    99,     6,   101,    49,    25,   189,   190,
     191,   353,   109,   355,   108,    17,   543,   987,   360,   989,
     362,   904,   905,   469,    32,   118,   909,   308,   309,   125,
     311,   312,   972,  1228,   480,    43,  1221,   483,   978,     6,
      42,   383,   109,   983,    62,   109,   483,   339,    50,    33,
      17,   393,   394,    96,   109,   399,   399,   399,   109,   113,
     849,   742,   743,   744,   540,  1005,  1261,  1262,    83,   411,
     617,    97,   168,   415,   108,    42,    91,    92,   109,     6,
     114,   107,  1277,    50,   108,    78,   885,   636,   112,    19,
      17,   117,   108,   189,   190,   110,   110,   193,   114,   114,
    1137,    95,   117,   118,    64,   108,   582,   650,   584,    95,
     586,   842,   393,   394,   295,    42,   118,   107,    64,    36,
     462,  1137,    52,    50,   118,  1095,   468,   469,  1098,   471,
      47,    48,   118,    63,    20,   113,   663,   675,   480,   773,
     482,   483,    59,  1140,  1140,   126,  1159,    33,    64,   330,
     331,   118,   112,   334,   114,   497,   498,   499,   500,    95,
      96,   142,   112,   106,   100,   708,   112,  1041,   114,   108,
    1140,   114,   102,    59,   117,   114,   157,  1117,  1118,  1119,
     112,    98,    99,   106,   165,  1155,  1199,   110,   110,  1226,
    1227,   118,   114,    79,  1231,   106,   112,   112,   114,   114,
     542,    64,   483,   114,   650,  1145,   117,  1147,   113,   114,
    1226,  1227,   658,   650,   660,  1231,   497,   498,   499,   500,
     110,   113,  1259,   565,   114,   108,   115,   117,   118,   118,
     911,   114,   678,  1270,   330,  1272,  1273,   113,  1275,   220,
     157,   106,   688,  1259,  1281,   110,  1283,  1284,   109,   112,
     696,   114,  1289,   109,  1270,   106,  1272,  1273,  1228,  1275,
     114,   603,   708,   114,   112,  1281,   117,  1283,  1284,   250,
     118,   708,   106,  1289,    53,    54,   110,    56,    57,    78,
      79,   641,   624,   625,    63,   645,   110,    86,    87,   109,
     114,  1261,  1262,   117,   636,   637,   277,   639,   640,   775,
     110,   643,   644,   112,   114,   114,   648,  1277,   650,    53,
      54,   292,    56,    57,   109,   112,   658,   112,   660,    63,
     119,   118,   664,   665,    53,    54,   109,    56,    57,   110,
     109,   691,   108,   114,    63,   110,   678,   679,   682,   114,
     682,   683,   117,   104,   105,   687,   688,   216,   106,   110,
     108,   693,   110,   114,   696,   697,   117,   104,   105,   276,
     277,   109,   111,   110,   112,   109,   708,   114,    53,    54,
     117,    56,    57,   109,   113,   114,   112,   113,    63,   660,
     109,   106,   118,   725,   726,   727,   728,   729,   730,   731,
     732,   733,   734,   735,   736,   737,   738,   739,   740,   741,
     742,   743,   744,   849,   110,   104,   105,  1224,   114,   590,
    1042,   108,   754,  1045,   756,  1047,   758,  1049,   760,    91,
      92,   110,   969,   765,   109,   114,   768,   769,   143,   112,
     793,    65,   147,   793,   797,  1252,   882,   797,   114,   885,
     114,   117,   112,   117,   725,   726,   727,   728,   729,   730,
     731,   732,   733,   734,   735,   109,   737,   738,   739,   740,
     741,   742,   743,   744,   112,  1051,   114,  1053,   107,  1055,
     113,  1057,   999,   112,   113,    97,   818,   948,   949,   950,
     951,   109,   732,   733,   734,   735,   109,   768,   769,    13,
      85,   360,   126,    88,    83,    19,   104,   105,   842,    23,
     842,   115,    91,    92,   118,   109,   216,   849,   142,   107,
      34,    35,   109,    37,   112,   113,   106,   969,    83,    65,
      44,   110,   114,   157,    48,   114,    91,    92,   117,   118,
     114,   165,   114,   117,   894,   117,   878,   879,   114,   106,
     882,   117,   411,   885,   115,   110,   112,   118,   114,   114,
     795,  1078,   117,   798,   106,    53,    54,   899,    56,    57,
     104,   105,   904,   905,    83,    63,   106,   909,   849,   911,
     912,   106,    91,    92,   106,   209,   216,   106,    13,   108,
     126,   118,   216,   107,    19,   219,   220,   117,    23,   223,
    1137,   110,    91,    92,   118,   114,   142,   106,   117,    34,
      35,   961,    37,   106,   964,   108,    41,   109,   112,    44,
     114,   157,   112,    48,   483,   249,   250,    91,    92,   165,
     101,   102,   103,   112,   113,   114,   112,   969,   114,   112,
     911,   912,   112,   113,   976,   977,   112,   113,   114,   981,
     982,   106,   276,   277,   986,   279,    91,    92,   112,   113,
     360,   993,   112,   113,   114,  1101,   969,   106,   292,   112,
     113,   114,  1022,   209,  1024,   110,    93,    94,  1010,   114,
     216,   110,   117,   219,   220,    83,  1203,   223,   104,  1226,
    1227,  1224,    27,   118,  1231,  1137,   106,    91,    92,   112,
     113,   114,   107,   112,  1140,   114,  1038,  1039,  1225,  1041,
     112,   411,   114,   249,   250,   108,   110,   110,   113,  1252,
     114,    89,  1259,   117,   118,   112,   113,   114,   730,   731,
     360,   355,    98,  1270,    99,  1272,  1273,    97,  1275,   114,
     276,   277,   109,   279,  1281,    51,  1283,  1284,   112,   113,
     114,   112,  1289,   112,   113,    13,   292,   112,   113,   114,
    1092,    19,  1112,   112,   113,    23,   110,  1038,  1039,  1101,
     943,   944,   945,   112,   113,   399,    34,    35,   637,    37,
     106,   411,   112,   483,  1226,  1227,    44,   411,  1224,  1231,
      48,   650,   737,   738,   739,   112,   113,  1224,    42,   658,
     112,   113,   112,   113,   112,  1137,  1138,   112,  1140,   112,
     113,   112,   113,   112,   113,   112,  1252,  1259,  1150,  1151,
     107,  1153,  1156,    42,  1156,  1252,   107,  1159,  1270,   113,
    1272,  1273,   216,  1275,  1137,   112,   113,    83,    84,  1281,
    1172,  1283,  1284,   113,   468,   469,   113,  1289,   107,   708,
     740,   741,   113,   483,   106,   109,   480,   107,   114,   483,
     118,     3,  1194,   399,  1196,  1197,   107,  1199,  1200,   107,
     107,   106,   106,    42,    16,   411,   107,   501,   111,    21,
     106,   111,   106,    42,    26,   107,   107,    29,    83,   107,
     113,   107,  1224,    43,  1226,  1227,    38,    39,    40,  1231,
      42,  1172,   216,    45,   112,  1237,   112,    32,   106,   111,
     107,    17,    83,  1245,   114,   107,   107,   111,    60,   109,
    1252,   107,   107,  1226,  1227,    67,   114,  1259,  1231,   112,
     112,   112,   468,   469,   106,   109,   113,   637,  1270,   107,
    1272,  1273,   109,  1275,   480,   107,   112,   483,   112,  1281,
     650,  1283,  1284,   107,   106,   108,  1259,  1289,   658,   106,
      24,    24,   106,   106,    83,   501,   107,  1270,   107,  1272,
    1273,   106,  1275,   107,  1245,   106,   360,   107,  1281,   107,
    1283,  1284,   114,   112,   107,   112,  1289,   107,   112,   107,
     112,    98,   107,   107,    83,   112,     3,   107,   107,   112,
     112,   112,   107,   107,    11,   107,   107,   637,   708,    16,
     107,   107,   112,   112,    21,   113,    83,   112,    25,    26,
     650,   112,    29,    84,   112,    24,   650,   411,   658,   107,
     112,    38,    39,    40,   658,    42,   660,   107,    45,   107,
      25,   107,   719,   199,     3,   210,   360,   883,   247,   165,
     900,    58,   144,    60,   678,  1246,   990,    16,   682,    66,
      67,   216,    21,   687,   688,  1201,    25,    26,   849,   722,
      29,   609,   696,   501,    18,    81,   693,   198,   708,    38,
      39,    40,   472,    42,   708,   694,    45,    65,   882,   470,
     899,   144,  1110,   277,   220,  1120,  1174,   411,  1245,   483,
    1140,    60,  1225,   663,   864,   112,   209,  1156,    67,   849,
     969,   219,   736,   727,   650,   725,    -1,   728,   726,    -1,
      -1,    -1,   658,   729,   660,    -1,    -1,   986,   987,    -1,
     989,    -1,    -1,    -1,   993,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   678,    -1,    -1,    -1,   682,    -1,   126,    -1,
      -1,   687,   688,   112,    -1,    -1,    -1,    -1,    -1,    -1,
     696,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,   483,
      -1,    -1,   708,    -1,    -1,     3,    -1,    -1,    -1,   157,
      -1,    -1,    -1,    -1,    -1,    13,    -1,   165,    16,    -1,
      -1,    19,    -1,    21,    -1,    23,    -1,    -1,    26,    -1,
     736,    -1,    -1,    -1,    -1,   360,    34,    35,    -1,    37,
      38,    -1,    40,    -1,    -1,    -1,    44,    45,   842,    -1,
      48,    -1,    -1,    -1,    -1,   849,    -1,    -1,    -1,    -1,
      -1,   209,    60,  1092,    -1,    -1,  1095,    -1,    -1,  1098,
      -1,   219,   220,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   637,    -1,    -1,   411,    -1,   882,    -1,
      -1,   885,    -1,   216,    -1,    -1,   650,    -1,    -1,   969,
      -1,   249,   250,    -1,   658,    -1,    -1,    -1,  1137,  1138,
      -1,  1140,    -1,    -1,    -1,    -1,   986,   987,    -1,   989,
     118,  1150,  1151,   993,  1153,    -1,  1155,    -1,   276,   277,
      -1,   279,    -1,    -1,    -1,    -1,   842,    -1,    -1,    -1,
      -1,    -1,    -1,   849,   292,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   637,   708,    -1,    -1,    -1,   483,    -1,
      -1,    -1,    -1,    -1,    -1,  1194,   650,  1196,  1197,   969,
      -1,    -1,    -1,    -1,   658,    -1,   882,    -1,     3,   885,
      -1,    -1,    -1,    -1,    -1,    -1,   986,   987,    -1,   989,
      -1,    16,    -1,   993,    -1,  1224,    21,  1226,  1227,  1228,
      -1,    26,  1231,    -1,    29,    -1,    -1,    -1,  1237,    -1,
      -1,   360,    -1,    38,    39,    40,    -1,    42,    -1,    -1,
      45,    -1,  1092,  1252,   708,  1095,    -1,    -1,  1098,    -1,
    1259,    -1,  1261,  1262,    -1,    60,    -1,   360,    -1,    -1,
      -1,  1270,    67,  1272,  1273,    -1,  1275,    -1,  1277,    -1,
      -1,    -1,  1281,    -1,  1283,  1284,    -1,    -1,    -1,     3,
    1289,    -1,    -1,    -1,    -1,    -1,    -1,  1137,  1138,    13,
    1140,    -1,    16,    -1,    -1,    19,    -1,    21,    -1,    23,
    1150,  1151,    26,  1153,    -1,  1155,    -1,   112,   411,    -1,
      34,    35,  1092,    37,    38,  1095,    40,    -1,  1098,    -1,
      44,    45,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   637,    -1,    -1,    -1,    60,    -1,    -1,    -1,
     468,   469,    -1,    -1,  1194,   650,  1196,  1197,    -1,    -1,
      -1,    -1,   480,   658,    -1,    -1,    -1,  1137,  1138,    -1,
    1140,    -1,   216,    -1,    -1,    -1,  1140,    -1,    -1,    -1,
    1150,  1151,    -1,  1153,  1224,  1155,  1226,  1227,  1228,    -1,
     483,  1231,    -1,   107,    -1,    -1,    -1,  1237,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1252,   708,    -1,    -1,    -1,    -1,    -1,  1259,
      -1,  1261,  1262,    -1,  1194,    -1,  1196,  1197,    -1,    -1,
    1270,    -1,  1272,  1273,    -1,  1275,    -1,  1277,    -1,    -1,
      -1,  1281,    -1,  1283,  1284,   969,    -1,    -1,    -1,  1289,
      -1,    -1,    -1,    -1,  1224,    -1,  1226,  1227,  1228,    -1,
    1224,  1231,   986,   987,  1140,   989,    -1,  1237,    -1,   993,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1252,    -1,    -1,    -1,     3,    -1,  1252,  1259,
      -1,  1261,  1262,    -1,    -1,    -1,    -1,    -1,    -1,    16,
    1270,    -1,  1272,  1273,    21,  1275,    -1,  1277,    25,    26,
      -1,  1281,    29,  1283,  1284,   969,   360,    -1,   637,  1289,
      -1,    38,    39,    40,    -1,    42,    -1,    -1,    45,    -1,
      -1,    -1,   986,   987,    -1,   989,    -1,    -1,    -1,   993,
      -1,    58,    -1,    60,   637,    -1,    -1,    -1,  1224,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,   650,    -1,    -1,
     678,    -1,    -1,    -1,   682,   658,    -1,   411,  1092,   687,
     688,  1095,   393,   394,  1098,    -1,  1252,    -1,   696,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1137,  1138,   708,  1140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1150,  1151,    -1,  1153,
      -1,  1155,    -1,    -1,    -1,    -1,    -1,    -1,  1092,   483,
      -1,  1095,    -1,    -1,  1098,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1194,    -1,  1196,  1197,   969,    -1,   497,   498,   499,   500,
      -1,    -1,    -1,  1137,  1138,    -1,  1140,    -1,    -1,    -1,
      -1,   986,   987,    -1,   989,    -1,  1150,  1151,   993,  1153,
    1224,  1155,  1226,  1227,  1228,    -1,    -1,  1231,    -1,    -1,
      -1,    -1,    -1,  1237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1252,    -1,
      -1,    -1,    -1,    -1,    -1,  1259,    -1,  1261,  1262,    -1,
    1194,    -1,  1196,  1197,    -1,    -1,  1270,    -1,  1272,  1273,
      -1,  1275,    -1,  1277,    -1,    -1,    -1,  1281,    -1,  1283,
    1284,    -1,    -1,    -1,   882,  1289,    -1,   885,    -1,    -1,
    1224,    -1,  1226,  1227,  1228,    -1,    -1,  1231,    -1,    -1,
      -1,    -1,    -1,  1237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   637,    -1,    -1,    -1,  1092,  1252,    -1,
    1095,    -1,    -1,  1098,    -1,  1259,   650,  1261,  1262,    -1,
      -1,    -1,    -1,    -1,   658,    -1,  1270,    -1,  1272,  1273,
      -1,  1275,    -1,  1277,    -1,    -1,    -1,  1281,    -1,  1283,
    1284,    -1,    -1,    -1,    -1,  1289,    -1,    -1,    -1,   660,
      -1,    -1,  1137,  1138,    -1,  1140,    -1,    -1,    -1,    -1,
     969,    -1,    -1,    -1,    -1,  1150,  1151,    -1,  1153,    -1,
    1155,    -1,    -1,    -1,   708,    -1,    -1,   986,    -1,    -1,
      -1,    -1,    -1,    -1,   993,    -1,   969,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,   986,   987,    -1,   989,    -1,    -1,  1194,
     993,  1196,  1197,    -1,   725,   726,   727,   728,   729,   730,
     731,   732,   733,   734,   735,    -1,   737,   738,   739,   740,
     741,   742,   743,   744,    -1,    -1,    -1,    -1,    -1,  1224,
      -1,  1226,  1227,  1228,    -1,    -1,  1231,    -1,    -1,    -1,
      -1,    -1,  1237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1252,    -1,    -1,
      -1,    -1,    -1,    -1,  1259,    -1,  1261,  1262,    -1,    -1,
      -1,    -1,    -1,  1092,    -1,  1270,    -1,  1272,  1273,    -1,
    1275,    -1,  1277,    -1,    -1,    -1,  1281,    -1,  1283,  1284,
     221,    -1,    -1,    -1,  1289,    -1,    -1,    -1,    -1,  1092,
      -1,    -1,  1095,    -1,    -1,  1098,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1137,  1138,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   849,    -1,
      -1,  1150,  1151,    -1,  1153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1137,  1138,    -1,  1140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1150,  1151,    -1,
    1153,    -1,  1155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   146,    -1,    -1,  1194,    -1,  1196,  1197,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     911,   912,    -1,   167,    -1,    -1,    -1,   171,    -1,    -1,
     174,  1194,   176,  1196,  1197,    -1,    -1,  1226,  1227,    -1,
      -1,    -1,  1231,    -1,   188,    -1,    -1,    -1,  1237,    -1,
      -1,    -1,    -1,    -1,    -1,   969,    -1,    -1,    -1,    -1,
      -1,  1224,    -1,  1226,  1227,  1228,    -1,    -1,  1231,    -1,
    1259,    -1,   986,   987,  1237,   989,    -1,    -1,    -1,   993,
      -1,  1270,    -1,  1272,  1273,    -1,  1275,    -1,    -1,  1252,
      -1,    -1,  1281,    -1,  1283,  1284,  1259,    -1,  1261,  1262,
    1289,    -1,   403,    -1,    -1,    -1,   407,  1270,    -1,  1272,
    1273,    -1,  1275,    -1,  1277,   259,   260,    -1,  1281,    -1,
    1283,  1284,    -1,    -1,    -1,    -1,  1289,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1038,  1039,    -1,
     294,    -1,    -1,   297,    -1,   299,    -1,   301,    -1,   303,
      -1,   305,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,
      -1,    -1,   473,    -1,    -1,    -1,    -1,    -1,  1092,    -1,
     357,  1095,    -1,    -1,  1098,   329,   363,   364,    -1,   333,
      -1,    -1,   336,    -1,   338,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   504,    -1,    -1,    -1,    -1,   385,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   395,    -1,
      -1,    -1,     3,  1137,  1138,    -1,  1140,    -1,    -1,   393,
     394,    -1,    13,    -1,    -1,    16,  1150,  1151,    19,  1153,
      21,  1155,    23,    -1,    -1,    26,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
    1194,  1172,  1196,  1197,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   608,   609,    -1,
    1224,    -1,  1226,  1227,  1228,    -1,    -1,  1231,    -1,    -1,
      -1,    -1,    -1,  1237,   501,    -1,    -1,   108,   629,    -1,
      -1,   112,    -1,   497,   498,   499,   500,   118,  1252,    -1,
      -1,    -1,    -1,    -1,    -1,  1259,    -1,  1261,  1262,    -1,
      -1,    -1,   653,    -1,  1245,    -1,  1270,    -1,  1272,  1273,
      -1,  1275,    -1,  1277,    -1,    -1,    -1,  1281,    -1,  1283,
    1284,    -1,    -1,    -1,    -1,  1289,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   695,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   707,   551,    -1,   553,
      -1,   555,    -1,    -1,   558,    -1,    -1,   718,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   612,    -1,   614,   615,    -1,
      -1,    -1,    -1,    -1,    -1,   589,    -1,    -1,   592,   626,
     594,    -1,   596,    -1,   598,    -1,   600,    -1,    -1,    -1,
      -1,   638,    -1,    -1,    -1,   642,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     657,    -1,   659,    -1,    -1,    -1,    -1,    -1,     3,   666,
      -1,    -1,    -1,   670,   795,    -1,   660,   798,    13,    -1,
      -1,    16,    -1,    -1,    19,    -1,    21,    -1,    23,    -1,
      -1,    26,    -1,    -1,    29,    -1,    -1,   694,    -1,    34,
      35,    -1,    37,    38,    39,    40,    -1,    42,    -1,    44,
      45,    -1,    -1,    48,    -1,   712,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   721,    60,    61,   724,    -1,    -1,
      -1,   852,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   725,   726,   727,   728,   729,   730,   731,   732,   733,
     734,   735,    -1,   737,   738,   739,   740,   741,   742,   743,
     744,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   895,    -1,   897,   898,    -1,    -1,
      -1,    -1,    -1,   118,    -1,    -1,   750,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   792,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   801,    -1,    -1,   928,    -1,   930,
      -1,    -1,    -1,    -1,    -1,   779,    -1,   781,    -1,   783,
      -1,    -1,   786,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   841,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,   849,    16,    17,    18,    19,
      -1,    21,    22,    23,    -1,    -1,    26,    -1,    28,    29,
      30,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   890,    44,    45,    -1,    -1,    48,    -1,
      50,    51,  1023,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,   911,   912,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,   118,    -1,
      -1,    -1,    -1,    -1,   971,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   955,    -1,    -1,    -1,   992,    -1,    -1,    -1,    -1,
      -1,   965,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      12,    13,    14,    -1,    16,    17,    18,    19,    -1,    21,
      22,    23,    -1,    -1,    26,    -1,    -1,    29,    30,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    44,    45,  1038,  1039,    48,    -1,    50,    51,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1061,    -1,    91,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1110,   106,     3,    -1,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    13,   118,    -1,    16,    -1,
      -1,    19,    -1,    21,    -1,    23,    -1,    -1,    26,  1136,
      -1,    29,  1139,    -1,  1141,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    -1,    44,    45,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1184,  1172,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,    -1,    -1,   112,    -1,    -1,    -1,  1225,    -1,
     118,    -1,    -1,  1230,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    12,    13,    14,    -1,    16,
      17,    18,    19,    -1,    21,    22,    23,    -1,    -1,    26,
      -1,  1245,    29,    30,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    44,    45,    -1,
      -1,    48,    -1,    50,    51,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,   108,    -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,
      -1,   118,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    19,    -1,
      21,    22,    23,    -1,    -1,    26,    -1,    -1,    29,    30,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,    -1,    48,    -1,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,   109,    -1,
      -1,   112,    -1,    -1,    -1,    -1,    -1,   118,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    12,    13,    14,
      -1,    16,    17,    18,    19,    -1,    21,    22,    23,    -1,
      -1,    26,    -1,    -1,    29,    30,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    44,
      45,    -1,    -1,    48,    -1,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    -1,     6,    -1,    -1,    91,    92,    -1,    -1,
      13,    -1,    -1,    16,    17,    -1,    19,    -1,    21,    -1,
      23,   106,    -1,    26,   109,    -1,    -1,   112,    -1,    -1,
      -1,    34,    35,   118,    37,    38,    -1,    40,    41,    -1,
      -1,    44,    45,    -1,    -1,    48,    -1,    50,    -1,    -1,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,     6,    -1,    -1,    91,    92,
      -1,    -1,    13,    -1,    -1,    16,    17,    -1,    19,    -1,
      21,    -1,    23,   106,    -1,    26,    -1,    -1,    -1,   112,
      -1,    -1,    -1,    34,    35,   118,    37,    38,    -1,    40,
      41,    -1,    -1,    44,    45,    -1,    -1,    48,    -1,    50,
      -1,    -1,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,     6,    -1,    -1,
      91,    92,    -1,    -1,    13,    -1,    -1,    16,    17,    -1,
      19,    -1,    21,    -1,    23,   106,    -1,    26,    -1,    -1,
      -1,   112,    -1,    -1,    -1,    34,    35,   118,    37,    38,
      -1,    40,    41,    -1,    -1,    44,    45,    -1,    -1,    48,
      -1,    50,    -1,    -1,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    16,    -1,    -1,    19,    -1,    21,    -1,    23,
      -1,    -1,    26,    -1,    -1,    29,    -1,   106,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,   118,
      44,    45,     3,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    16,    60,    -1,    19,    -1,
      21,    -1,    23,    67,    -1,    26,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    34,    35,    79,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    60,
      -1,    -1,    -1,    -1,   108,   109,    67,    13,   112,    -1,
      16,    -1,    -1,    19,   118,    21,    -1,    23,    79,    -1,
      26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    -1,    44,    45,
       3,    -1,    48,    -1,    -1,    -1,    -1,   108,   109,    -1,
      13,   112,    -1,    16,    60,    -1,    19,   118,    21,    -1,
      23,    67,    -1,    26,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    34,    35,    79,    37,    38,    39,    40,    41,    42,
      -1,    44,    45,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    60,    -1,    -1,
      -1,    -1,   108,   109,    67,    13,   112,    -1,    16,    -1,
      -1,    19,   118,    21,    -1,    23,    79,    -1,    26,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    -1,    44,    45,     3,    -1,
      48,    -1,    -1,    -1,    -1,    -1,   109,    -1,    13,   112,
      -1,    16,    60,    -1,    19,   118,    21,    -1,    23,    67,
      -1,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,
      35,    79,    37,    38,    39,    40,    41,    42,    -1,    44,
      45,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    60,    -1,    -1,    -1,    -1,
      -1,   109,    67,    13,   112,    -1,    16,    -1,    -1,    19,
     118,    21,    -1,    23,    79,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    34,    35,    -1,    37,    38,    -1,
      40,    -1,    -1,    13,    44,    45,    16,    -1,    48,    19,
      -1,    21,    -1,    23,    -1,    -1,    26,    -1,    -1,    -1,
      60,    -1,    -1,   118,    34,    35,    -1,    37,    38,     3,
      40,    -1,    -1,    -1,    44,    45,    -1,    -1,    48,    13,
      -1,    -1,    16,    -1,    -1,    19,    -1,    21,    -1,    23,
      60,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      34,    35,    -1,    37,    38,    -1,    40,   107,    -1,    13,
      44,    45,    16,    -1,    48,    19,    -1,    21,   118,    23,
      -1,    -1,    26,    -1,    -1,    -1,    60,    -1,    -1,     3,
      34,    35,    -1,    37,    38,    -1,    40,   107,    -1,    13,
      44,    45,    16,    -1,    48,    19,    -1,    21,   118,    23,
      -1,    -1,    26,    -1,    -1,    -1,    60,    -1,    -1,     3,
      34,    35,    -1,    37,    38,    -1,    40,    -1,    -1,    13,
      44,    45,    16,   107,    48,    19,    -1,    21,    -1,    23,
      -1,    -1,    26,    -1,   118,    -1,    60,    61,    -1,    -1,
      34,    35,    -1,    37,    38,    -1,    40,    -1,    -1,    -1,
      44,    45,    -1,   107,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,     6,     7,     8,   118,    10,    -1,    12,    13,    14,
      -1,    -1,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,   107,    -1,    30,    -1,    -1,    -1,    34,
      35,    36,    37,    -1,   118,    -1,    41,    -1,    -1,    44,
      -1,    -1,    -1,    48,    -1,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    -1,    -1,
       4,     5,     6,     7,     8,    -1,    10,    -1,    12,    13,
      14,   106,    -1,    17,    18,    19,    -1,   112,    22,    23,
      -1,    -1,    -1,   118,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    36,    37,    -1,    -1,    -1,    41,    -1,    -1,
      44,    -1,    -1,    -1,    48,    -1,    50,    51,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    91,    92,    17,
      -1,    19,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,   106,    -1,    -1,    -1,    34,    35,   112,    37,
      -1,    -1,    -1,    41,   118,    -1,    44,    -1,    -1,    -1,
      48,    -1,    50,    -1,    -1,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,    -1,    91,    92,    93,    94,    13,    -1,    -1,
      -1,    17,    -1,    19,    -1,    -1,    22,    23,   106,    -1,
     108,   109,    -1,    -1,    -1,   113,    -1,    -1,    34,    35,
     118,    37,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,
      -1,    -1,    48,    -1,    50,    -1,    -1,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,    -1,    91,    92,    93,    94,    13,
      -1,    -1,    -1,    17,    -1,    19,    -1,    -1,    -1,    23,
     106,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,   118,    37,    -1,    -1,    -1,    41,    -1,    -1,
      44,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,    -1,    91,    92,    93,
      94,    13,    -1,    -1,    -1,    17,    -1,    19,    -1,    -1,
      -1,    23,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,   118,    37,    -1,    -1,    -1,    41,
      -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,    91,
      92,    93,    94,    13,    -1,    -1,    -1,    17,    -1,    19,
      -1,    -1,    -1,    23,   106,    -1,    -1,    -1,    -1,    -1,
     112,    -1,    -1,    -1,    34,    35,   118,    37,    -1,    -1,
      -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,
      50,    -1,    -1,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,    91,    92,    93,    94,    13,    -1,    -1,    -1,    17,
      -1,    19,    -1,    -1,    -1,    23,   106,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    34,    35,   118,    37,
      -1,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,
      48,    -1,    50,    -1,    -1,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,    -1,    91,    92,    93,    94,    13,    -1,    -1,
      -1,    17,    -1,    19,    -1,    -1,    -1,    23,   106,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
     118,    37,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,
      -1,    -1,    48,    -1,    50,    -1,    -1,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,    -1,    91,    92,    93,    94,    13,
      -1,    -1,    -1,    17,    -1,    19,    -1,    -1,    -1,    23,
     106,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,   118,    37,    -1,    -1,    -1,    41,    -1,    -1,
      44,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,    -1,    91,    92,    93,
      94,    13,    -1,    -1,    -1,    17,    -1,    19,    -1,    -1,
      -1,    23,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,   118,    37,    -1,    -1,    -1,    41,
      -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,    91,
      92,    93,    94,    13,    -1,    -1,    -1,    17,    -1,    19,
      -1,    -1,    -1,    23,   106,    -1,    -1,    -1,    -1,    -1,
     112,    -1,    -1,    -1,    34,    35,   118,    37,    -1,    -1,
      -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,
      50,    -1,    -1,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,    91,    92,    93,    94,    13,    -1,    -1,    -1,    17,
      -1,    19,    -1,    -1,    -1,    23,   106,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,   118,    37,
      -1,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,
      48,    -1,    50,    -1,    -1,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,    -1,    91,    92,    93,    94,    13,    -1,    -1,
      -1,    17,    -1,    19,    -1,    -1,    -1,    23,   106,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
     118,    37,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,
      -1,    -1,    48,    -1,    50,    -1,    -1,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,    -1,    91,    92,    93,    94,    13,
      -1,    -1,    -1,    17,    -1,    19,    -1,    -1,    -1,    23,
     106,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,   118,    37,    -1,    -1,    -1,    41,    -1,    -1,
      44,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,    -1,    91,    92,    93,
      94,    13,    -1,    -1,    -1,    17,    -1,    19,    -1,    -1,
      -1,    23,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,   118,    37,    -1,    -1,    -1,    41,
      -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,    91,
      92,    93,    94,    13,    -1,    -1,    -1,    17,    -1,    19,
      -1,    -1,    -1,    23,   106,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,   118,    37,    -1,    -1,
      -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,
      50,    -1,    -1,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,    91,    92,    93,    94,    13,    -1,    -1,    -1,    17,
      -1,    19,    -1,    -1,    -1,    23,   106,    -1,    -1,    -1,
      -1,    -1,   112,    -1,    -1,    -1,    34,    35,   118,    37,
      -1,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,
      48,    -1,    50,    -1,    -1,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,    -1,    91,    92,    93,    94,    13,    -1,    -1,
      -1,    17,    -1,    19,    -1,    -1,    -1,    23,   106,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
     118,    37,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,
      -1,    -1,    48,    -1,    50,    -1,    -1,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,    -1,    91,    92,    93,    94,    13,
      -1,    -1,    -1,    17,    -1,    19,    -1,    -1,    -1,    23,
     106,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,   118,    37,    -1,    -1,    -1,    41,    -1,    -1,
      44,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,    -1,    91,    92,    93,
      94,    13,    -1,    -1,    -1,    17,    -1,    19,    -1,    -1,
      -1,    23,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,   118,    37,    -1,    -1,    -1,    41,
      -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,    91,
      92,    93,    94,    13,    -1,    -1,    -1,    17,    -1,    19,
      -1,    -1,    -1,    23,   106,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,   118,    37,    -1,    -1,
      -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,
      50,    -1,    -1,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,    91,    92,    93,    94,    13,    -1,    -1,    -1,    17,
      -1,    19,    -1,    -1,    -1,    23,   106,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,   118,    37,
      -1,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,
      48,    -1,    50,    -1,    -1,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,    -1,    91,    92,    93,    94,    13,    -1,    -1,
      -1,    17,    -1,    19,    -1,    -1,    -1,    23,   106,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
     118,    37,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,
      -1,    -1,    48,    -1,    50,    -1,    -1,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,    -1,    91,    92,    93,    94,    13,
      -1,    -1,    -1,    17,    -1,    19,    -1,    -1,    -1,    23,
     106,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,
      34,    35,   118,    37,    -1,    -1,    -1,    41,    -1,    -1,
      44,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,    -1,    91,    92,    93,
      94,    13,    -1,    -1,    -1,    17,    -1,    19,    -1,    -1,
      -1,    23,   106,    -1,    -1,    -1,    -1,    -1,   112,    -1,
      -1,    -1,    34,    35,   118,    37,    -1,    -1,    -1,    41,
      -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,    91,
      92,    93,    94,    13,    -1,    -1,    -1,    17,    -1,    19,
      -1,    -1,    -1,    23,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,   118,    37,    -1,    -1,
      -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,
      50,    -1,    -1,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,     6,
      80,    81,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,
      17,    -1,    19,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    34,    35,    -1,
      37,    -1,    -1,    -1,    41,    -1,    -1,    44,   118,    -1,
      -1,    48,    -1,    50,    -1,    -1,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    91,    92,    17,    -1,    19,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,   106,
     107,    -1,    -1,    34,    35,    -1,    37,    -1,    -1,    -1,
      41,   118,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,
      -1,    -1,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      91,    92,    17,    -1,    19,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,   106,   107,    -1,    -1,    34,
      35,    -1,    37,    -1,    -1,    -1,    41,   118,    -1,    44,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    91,    92,    17,    -1,
      19,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,   106,   107,    -1,    -1,    34,    35,    -1,    37,    -1,
      -1,    -1,    41,   118,    -1,    44,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    91,    92,    17,    -1,    19,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,    -1,
      -1,    34,    35,    -1,    37,    -1,    -1,    -1,    41,   118,
      -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    91,    92,
      17,    -1,    19,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,   106,   107,    -1,    -1,    34,    35,    -1,
      37,    -1,    -1,    -1,    41,   118,    -1,    44,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    91,    92,    17,    -1,    19,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,   106,
     107,    -1,    -1,    34,    35,    -1,    37,    -1,    -1,    -1,
      41,   118,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,
      -1,    -1,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      91,    92,    17,    -1,    19,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,   106,   107,    -1,    -1,    34,
      35,    -1,    37,    -1,    -1,    -1,    41,   118,    -1,    44,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    91,    92,    17,    -1,
      19,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,   106,   107,    -1,    -1,    34,    35,    -1,    37,    -1,
      -1,    -1,    41,   118,    -1,    44,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,    11,    16,    21,    25,    26,    29,    38,    39,
      40,    42,    45,    58,    60,    66,    67,   112,   126,   127,
     135,   168,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   204,   205,   274,   281,   282,   291,   292,
     309,   118,   169,    40,   169,   182,   169,   169,   169,   169,
      58,   169,   127,   188,   194,   193,    29,    39,    42,   281,
     309,     0,   126,   127,    79,   106,   238,   283,   112,   114,
     128,   169,   182,   112,   114,   112,   114,    20,   108,   241,
     275,    33,    59,   238,   293,   310,   311,    33,    59,   206,
     238,   240,   241,   243,   108,   128,   169,   169,   169,   169,
     238,   283,   127,   169,   178,   239,    13,    19,    23,    34,
      35,    37,    44,    48,   107,   169,   174,   175,   176,   252,
     253,   254,   284,   285,   286,   283,   108,   241,   287,   169,
     112,   114,   114,   112,   114,    95,   169,    95,   169,   169,
     242,   109,   112,   113,   145,   146,   169,   276,   279,   280,
     275,   242,   169,   182,   297,   310,   311,   108,   312,   295,
     311,   294,   169,   169,   182,   108,   244,   214,   240,   241,
     243,   210,   241,   243,   208,   243,   207,   195,   196,   108,
     108,   128,   241,   275,   238,   301,   310,   311,   222,   238,
     240,   241,   243,   283,   241,   287,    33,   179,   113,   136,
     137,    78,   110,   121,   122,   115,   169,   121,   107,   113,
     147,   148,   241,   287,    40,    41,   108,   109,   112,   135,
     149,   169,   204,   238,   245,   246,   247,   252,   255,   256,
     257,   267,   268,   269,   271,   288,   289,   290,   291,   318,
     287,   169,    95,    95,   112,   112,   113,   138,   139,   135,
     140,   169,   245,   109,   280,   146,   279,   106,   244,   277,
     278,   109,   280,   113,   109,   114,   113,   114,   133,   134,
     312,   299,   311,   298,   109,   112,   135,   150,   204,   238,
     252,   256,   291,   313,   314,   315,   312,   296,   312,   133,
     133,   109,   140,   244,   218,   241,   243,   216,   243,   215,
     244,   212,   243,   211,   244,   209,   244,   109,    53,    54,
      56,    57,    63,   129,   203,   197,   198,   199,   200,   108,
     275,   305,   310,   311,   312,   303,   311,   302,   244,   230,
     240,   241,   243,   226,   241,   243,   224,   243,   223,   241,
     287,   287,   169,   178,   137,   111,   122,   169,   285,   148,
     287,   318,   169,     4,     5,     6,     7,     8,    10,    12,
      14,    17,    18,    22,    30,    36,    41,    50,    51,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    91,    92,   106,   109,   112,   118,   135,
     169,   170,   171,   182,   183,   204,   252,   253,   254,   292,
     319,   320,   321,   322,   323,   324,   325,   326,   328,   329,
     330,   331,   333,   334,   335,   336,   338,   339,   346,   347,
     349,   350,   352,   353,   358,   359,   361,   362,   363,   364,
     365,   366,   368,   370,   378,   382,   383,   384,   385,   386,
     388,   389,   390,   392,   393,   397,   398,   413,   414,   416,
     417,   418,   252,   256,   271,   289,   109,   288,   106,   270,
     169,   252,   257,   169,   248,   249,   250,   112,   266,   318,
     106,   258,    27,   108,   263,   272,   272,   112,   112,   169,
     139,   245,   109,     7,    60,    61,    67,    80,    81,    93,
      94,   106,   107,   169,   253,   254,   385,   390,   391,   395,
     396,   397,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   244,   244,   109,   169,   182,   134,   312,
     300,   312,   252,   256,   109,   313,   248,   266,   312,   109,
     244,   220,   243,   219,   244,   217,   244,   244,   213,   244,
     244,   169,   182,   169,   182,   130,   168,   169,   181,   169,
     182,   169,   182,   109,   203,   109,   129,   109,   129,   201,
     202,   312,   307,   311,   306,   312,   304,   312,   244,   234,
     241,   243,   232,   243,   231,   244,   228,   243,   227,   244,
     225,   244,   287,    97,   123,   180,   112,   169,   169,   173,
     253,   387,   106,   395,   106,   106,   169,   325,   112,   169,
     395,   112,   395,   114,   114,   117,   106,   395,   169,   182,
     388,   389,   412,   412,   395,    61,   324,    83,   110,   114,
     117,   121,   110,   114,   117,   121,   106,   114,   117,   109,
     151,   320,   112,   169,   248,   318,   112,   106,   106,    83,
     106,   318,   369,   379,   114,   117,   110,   104,   105,   172,
     399,    91,    92,   248,   266,   263,   272,   272,   124,   252,
     259,   107,   135,   252,   260,   261,   262,   106,   270,   169,
     258,   121,   112,   113,   104,   107,   124,   252,   260,   263,
     169,   264,   265,    17,    50,   109,   169,   182,   273,   319,
     382,   272,   106,   412,   412,   412,   412,   173,   253,   254,
     107,   113,   165,   166,    82,    90,    89,    98,    99,    97,
      85,    88,    78,    79,    86,    87,   119,   101,   102,   103,
      93,    94,    95,    96,   100,   312,   248,   266,   112,   244,
     221,   244,   244,   244,    64,   112,    64,   112,    64,   112,
      64,   112,   168,   181,   112,   114,   112,   112,    65,    65,
     109,   109,   109,   129,   312,   308,   312,   312,   244,   236,
     243,   235,   244,   233,   244,   244,   229,   244,   244,   169,
     180,   112,   110,   121,   128,   167,   394,   121,   167,   106,
     395,    83,   112,   395,   395,   346,   112,   112,   112,    42,
     169,   169,   395,   112,   107,   248,   325,   395,     6,    17,
      42,    50,   169,   386,   169,   114,   395,    17,    42,    50,
     169,   386,   169,   114,   107,   391,    42,     6,   169,   320,
     395,   112,   135,   169,   323,   334,   355,   357,   395,   163,
     164,   169,   182,   323,   380,   381,   382,   388,   422,    32,
      43,   371,   372,   376,   369,   169,   386,   169,   395,   395,
     112,   272,   107,   260,    17,   125,   169,   113,   252,   115,
     250,   107,   113,   141,   142,   124,   107,   260,   263,   249,
     108,   251,   316,   395,   121,   107,   260,   169,   107,   113,
     143,   144,   106,   106,   114,   114,   109,   319,   109,   114,
     395,   107,   107,   123,   395,   166,   395,   402,   403,   404,
     405,   406,   407,   407,   409,   409,   409,   409,   169,   177,
     253,   254,   410,   410,   410,   411,   411,   412,   412,   412,
     112,   244,   181,   181,   181,   181,   112,   169,   169,   182,
     169,   182,   109,   312,   244,   237,   244,   244,   244,   395,
     316,   121,   394,   316,   121,   107,   391,   107,   395,   107,
     107,   106,   106,   107,   111,   169,   114,   117,   106,    42,
     111,   114,   117,   106,    42,   107,   107,   112,   395,   113,
     158,   159,   112,   107,   164,   381,   107,   112,   373,   377,
     376,   160,   372,   371,   376,   106,   111,   107,    17,   114,
     115,   250,   169,   261,   142,   107,   260,   107,   109,   113,
     251,   317,   121,   107,   121,   265,   144,   107,   391,   107,
     391,    50,    50,   109,    50,   107,   412,   415,   107,    83,
     112,   113,   131,   132,   112,   131,   112,   131,   112,   131,
     112,   133,   112,   133,   112,   133,   112,   133,   244,   111,
     244,   107,   340,   112,    10,   169,   325,   327,   328,   332,
     337,   346,   348,   351,   352,   354,   358,   360,   367,   395,
     107,   391,   112,   169,   169,   107,   391,   169,   169,   107,
     391,   325,   107,   356,   357,   112,   334,   159,   112,   395,
     325,   106,   318,   372,   376,   107,   391,   169,   107,   109,
     113,   109,   121,   112,   107,   112,   107,   106,   106,   106,
     421,   415,   400,   181,   112,   132,   112,   112,   112,   112,
     112,   112,   112,   244,   108,   341,   106,    83,    24,   106,
     106,    83,   318,   107,   107,   106,   107,   106,   107,   325,
     107,   107,   356,   107,   356,   112,   135,   169,   374,   375,
     107,   317,   112,   112,   107,   391,   107,   391,   107,   391,
     341,     9,    28,   109,   153,   154,   155,   342,   343,   344,
     395,   327,   325,   395,   112,   355,   395,   112,   107,   391,
     107,   391,   325,   325,   107,   325,   107,   107,   356,   375,
      98,   161,   162,   107,   250,   112,   107,   112,   107,   112,
     107,   345,   400,   109,   154,   343,   344,   109,   155,   344,
     109,   152,   342,   344,    83,    84,   107,   107,   112,   395,
     112,   107,   107,   107,   325,   325,   325,   107,   250,   169,
     162,   318,   112,   112,   112,   113,   156,   157,   109,    83,
     109,   342,   154,   319,   318,   365,   395,   327,   327,   107,
     356,   112,   112,   395,   327,   325,   345,   157,   319,   112,
      24,   327,   107,   107,   356,   107,   356,   112,   327,   327,
     327,   107,   327,   107,   107,   356,   327,   327,   327,   107,
     327
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   120,   121,   121,   122,   123,   123,   124,   125,   126,
     126,   127,   127,   128,   128,   129,   129,   130,   130,   131,
     131,   132,   133,   133,   134,   134,   135,   135,   136,   136,
     137,   138,   138,   139,   140,   140,   141,   141,   142,   143,
     143,   144,   145,   145,   146,   147,   147,   148,   149,   149,
     150,   150,   151,   151,   152,   152,   153,   153,   154,   154,
     155,   156,   156,   157,   158,   158,   159,   160,   160,   161,
     161,   162,   163,   163,   164,   165,   165,   166,   167,   167,
     168,   168,   168,   168,   168,   168,   168,   168,   169,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   171,   171,   171,   171,   171,
     171,   171,   172,   172,   173,   174,   174,   175,   175,   175,
     175,   175,   176,   176,   177,   177,   178,   178,   179,   179,
     180,   181,   181,   182,   182,   183,   184,   184,   185,   185,
     185,   185,   185,   185,   185,   185,   186,   186,   187,   187,
     188,   188,   188,   188,   189,   189,   190,   191,   191,   192,
     192,   193,   193,   193,   195,   194,   196,   194,   197,   194,
     198,   194,   199,   194,   200,   194,   201,   194,   202,   194,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   204,   204,   204,   206,   205,   207,
     205,   208,   205,   209,   205,   210,   205,   211,   205,   212,
     205,   213,   205,   214,   205,   215,   205,   216,   205,   217,
     205,   218,   205,   219,   205,   220,   205,   221,   205,   222,
     205,   223,   205,   224,   205,   225,   205,   226,   205,   227,
     205,   228,   205,   229,   205,   230,   205,   231,   205,   232,
     205,   233,   205,   234,   205,   235,   205,   236,   205,   237,
     205,   238,   239,   239,   240,   241,   242,   242,   243,   243,
     243,   243,   244,   244,   245,   245,   245,   245,   246,   246,
     246,   246,   246,   247,   247,   248,   248,   249,   249,   250,
     250,   251,   251,   252,   252,   252,   253,   253,   254,   254,
     255,   255,   256,   256,   256,   256,   257,   257,   258,   258,
     258,   258,   258,   258,   258,   258,   259,   259,   260,   260,
     261,   261,   261,   262,   262,   263,   264,   264,   265,   266,
     266,   267,   268,   269,   269,   269,   269,   270,   271,   271,
     271,   271,   271,   271,   271,   271,   272,   272,   272,   272,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     274,   274,   274,   274,   275,   275,   275,   275,   275,   275,
     276,   276,   277,   278,   279,   279,   279,   279,   279,   279,
     280,   280,   281,   282,   282,   282,   282,   282,   282,   282,
     282,   283,   283,   284,   284,   285,   285,   286,   287,   287,
     288,   288,   289,   290,   290,   291,   293,   292,   294,   292,
     295,   292,   296,   292,   297,   292,   298,   292,   299,   292,
     300,   292,   301,   292,   302,   292,   303,   292,   304,   292,
     305,   292,   306,   292,   307,   292,   308,   292,   309,   310,
     311,   311,   312,   312,   313,   313,   313,   313,   313,   314,
     314,   315,   315,   316,   316,   316,   317,   317,   318,   318,
     319,   319,   320,   320,   320,   321,   321,   322,   323,   323,
     324,   324,   325,   325,   325,   325,   325,   325,   325,   326,
     327,   327,   327,   327,   327,   329,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   330,
     331,   332,   333,   334,   334,   334,   334,   334,   334,   334,
     335,   336,   337,   338,   338,   340,   339,   341,   341,   341,
     341,   341,   341,   342,   342,   342,   343,   343,   344,   344,
     344,   345,   346,   347,   348,   349,   350,   350,   351,   351,
     352,   353,   353,   353,   353,   353,   353,   353,   353,   354,
     354,   354,   354,   354,   354,   354,   354,   355,   355,   356,
     357,   357,   358,   359,   360,   361,   361,   362,   363,   363,
     364,   364,   365,   367,   366,   368,   369,   370,   370,   370,
     370,   371,   371,   373,   372,   374,   374,   375,   375,   377,
     376,   378,   378,   378,   378,   379,   380,   380,   381,   381,
     382,   382,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   384,   384,   384,   384,   384,   384,   385,
     385,   385,   385,   386,   386,   386,   386,   387,   387,   388,
     388,   388,   388,   389,   389,   389,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     391,   391,   392,   392,   392,   392,   392,   392,   392,   392,
     393,   393,   393,   393,   393,   393,   394,   395,   396,   396,
     397,   398,   398,   398,   398,   399,   400,   400,   401,   401,
     402,   402,   403,   403,   404,   404,   405,   405,   406,   406,
     406,   407,   407,   407,   407,   407,   407,   408,   409,   409,
     409,   409,   410,   410,   410,   411,   411,   411,   411,   412,
     412,   412,   412,   412,   413,   414,   415,   415,   415,   415,
     415,   416,   416,   416,   416,   416,   417,   418,   419,   419,
     419,   421,   420,   422,   422,   422
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       1,     1,     1,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       5,     7,     7,     3,     5,     0,     6,     3,     4,     2,
       3,     3,     4,     4,     3,     3,     3,     4,     2,     3,
       1,     1,     1,     5,     5,     7,     1,     1,     1,     1,
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
#line 1324 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type ;(yyval.typeinfo)->order=1;(yyval.typeinfo)->tac=emptyvector();}
#line 5006 "parser.tab.c"
    break;

  case 3:
#line 1325 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type + "[]";(yyval.typeinfo)->order=(yyvsp[-1].typeinfo)->order+1;(yyval.typeinfo)->tac=emptyvector();}
#line 5012 "parser.tab.c"
    break;

  case 4:
#line 1327 "parser.y"
                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "[]";(yyval.typeinfo)->tac=emptyvector();}
#line 5018 "parser.tab.c"
    break;

  case 5:
#line 1329 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5024 "parser.tab.c"
    break;

  case 6:
#line 1330 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5030 "parser.tab.c"
    break;

  case 7:
#line 1332 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 5036 "parser.tab.c"
    break;

  case 8:
#line 1334 "parser.y"
                              {         (yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5042 "parser.tab.c"
    break;

  case 9:
#line 1336 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5048 "parser.tab.c"
    break;

  case 10:
#line 1337 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5054 "parser.tab.c"
    break;

  case 11:
#line 1339 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5060 "parser.tab.c"
    break;

  case 12:
#line 1340 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5066 "parser.tab.c"
    break;

  case 13:
#line 1342 "parser.y"
                                                                {(yyval.typeinfo) = createstruct();string p=((yyvsp[0].str));((yyval.typeinfo))->name="."+p;(yyval.typeinfo)->tac=emptyvector();}
#line 5072 "parser.tab.c"
    break;

  case 14:
#line 1343 "parser.y"
                                                    {(yyval.typeinfo) = createstruct();string p=((yyvsp[0].str));((yyval.typeinfo))->name=((yyvsp[-2].typeinfo))->name+"."+p;(yyval.typeinfo)->tac= (yyvsp[-2].typeinfo)->tac;}
#line 5078 "parser.tab.c"
    break;

  case 15:
#line 1345 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5084 "parser.tab.c"
    break;

  case 16:
#line 1346 "parser.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5090 "parser.tab.c"
    break;

  case 17:
#line 1348 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5096 "parser.tab.c"
    break;

  case 18:
#line 1349 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5102 "parser.tab.c"
    break;

  case 19:
#line 1351 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5108 "parser.tab.c"
    break;

  case 20:
#line 1352 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5114 "parser.tab.c"
    break;

  case 21:
#line 1354 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5120 "parser.tab.c"
    break;

  case 22:
#line 1356 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5126 "parser.tab.c"
    break;

  case 23:
#line 1357 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5132 "parser.tab.c"
    break;

  case 24:
#line 1359 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5138 "parser.tab.c"
    break;

  case 25:
#line 1360 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5144 "parser.tab.c"
    break;

  case 26:
#line 1362 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5150 "parser.tab.c"
    break;

  case 27:
#line 1363 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5156 "parser.tab.c"
    break;

  case 28:
#line 1365 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5162 "parser.tab.c"
    break;

  case 29:
#line 1366 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5168 "parser.tab.c"
    break;

  case 30:
#line 1368 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5174 "parser.tab.c"
    break;

  case 31:
#line 1370 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5180 "parser.tab.c"
    break;

  case 32:
#line 1371 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5186 "parser.tab.c"
    break;

  case 33:
#line 1373 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5192 "parser.tab.c"
    break;

  case 34:
#line 1375 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5198 "parser.tab.c"
    break;

  case 35:
#line 1376 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5204 "parser.tab.c"
    break;

  case 36:
#line 1378 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;(yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->method_argvari = (yyvsp[0].typeinfo)->method_argvari;}
#line 5210 "parser.tab.c"
    break;

  case 37:
#line 1379 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();vector<string>a=((yyvsp[-1].typeinfo))->type_variable;vector<string>b=((yyvsp[0].typeinfo))->type_variable;for(auto z:a){((yyval.typeinfo))->type_variable.push_back(z);}for(auto z:b){((yyval.typeinfo))->type_variable.push_back(z);}vector<string>c=((yyvsp[-1].typeinfo))->method_argvari;vector<string>d=((yyvsp[0].typeinfo))->method_argvari;for(auto z:c){((yyval.typeinfo))->method_argvari.push_back(z);}for(auto z:d){((yyval.typeinfo))->method_argvari.push_back(z);}(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5216 "parser.tab.c"
    break;

  case 38:
#line 1381 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;(yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->method_argvari = (yyvsp[0].typeinfo)->method_argvari;}
#line 5222 "parser.tab.c"
    break;

  case 39:
#line 1383 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5228 "parser.tab.c"
    break;

  case 40:
#line 1384 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5234 "parser.tab.c"
    break;

  case 41:
#line 1386 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5240 "parser.tab.c"
    break;

  case 42:
#line 1388 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5246 "parser.tab.c"
    break;

  case 43:
#line 1389 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5252 "parser.tab.c"
    break;

  case 44:
#line 1391 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 5258 "parser.tab.c"
    break;

  case 45:
#line 1393 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5264 "parser.tab.c"
    break;

  case 46:
#line 1394 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5270 "parser.tab.c"
    break;

  case 47:
#line 1396 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5276 "parser.tab.c"
    break;

  case 48:
#line 1398 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5282 "parser.tab.c"
    break;

  case 49:
#line 1399 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5288 "parser.tab.c"
    break;

  case 50:
#line 1401 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5294 "parser.tab.c"
    break;

  case 51:
#line 1402 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5300 "parser.tab.c"
    break;

  case 52:
#line 1409 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);}
#line 5306 "parser.tab.c"
    break;

  case 53:
#line 1410 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5312 "parser.tab.c"
    break;

  case 54:
#line 1412 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5318 "parser.tab.c"
    break;

  case 55:
#line 1413 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5324 "parser.tab.c"
    break;

  case 56:
#line 1415 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5330 "parser.tab.c"
    break;

  case 57:
#line 1416 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5336 "parser.tab.c"
    break;

  case 58:
#line 1418 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5342 "parser.tab.c"
    break;

  case 59:
#line 1419 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5348 "parser.tab.c"
    break;

  case 60:
#line 1421 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 5354 "parser.tab.c"
    break;

  case 61:
#line 1423 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5360 "parser.tab.c"
    break;

  case 62:
#line 1424 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5366 "parser.tab.c"
    break;

  case 63:
#line 1426 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5372 "parser.tab.c"
    break;

  case 64:
#line 1428 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5378 "parser.tab.c"
    break;

  case 65:
#line 1429 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5384 "parser.tab.c"
    break;

  case 66:
#line 1431 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5390 "parser.tab.c"
    break;

  case 67:
#line 1433 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5396 "parser.tab.c"
    break;

  case 68:
#line 1434 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5402 "parser.tab.c"
    break;

  case 69:
#line 1436 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5408 "parser.tab.c"
    break;

  case 70:
#line 1437 "parser.y"
                                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5414 "parser.tab.c"
    break;

  case 71:
#line 1439 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5420 "parser.tab.c"
    break;

  case 72:
#line 1441 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 5426 "parser.tab.c"
    break;

  case 73:
#line 1442 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5432 "parser.tab.c"
    break;

  case 74:
#line 1444 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 5438 "parser.tab.c"
    break;

  case 75:
#line 1446 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;for(auto z:(yyvsp[0].typeinfo)->params)(yyval.typeinfo)->params.push_back(z);(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 5444 "parser.tab.c"
    break;

  case 76:
#line 1447 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);for(auto z:((yyvsp[-1].typeinfo))->params)((yyval.typeinfo))->params.push_back(z);for(auto z:((yyvsp[0].typeinfo))->params)((yyval.typeinfo))->params.push_back(z);(yyval.typeinfo)->temporarystore = contemp((yyvsp[-1].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore);}
#line 5450 "parser.tab.c"
    break;

  case 77:
#line 1449 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;string s = ((yyvsp[0].typeinfo))->tempname; (yyval.typeinfo)->params.push_back(s);(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 5456 "parser.tab.c"
    break;

  case 78:
#line 1451 "parser.y"
                                                                                                                {(yyval.typeinfo)=createstruct();int p=(yyvsp[0].typeinfo)->exprvalue;vector<int>q={p};(yyval.typeinfo)->arrdim=q;(yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 5462 "parser.tab.c"
    break;

  case 79:
#line 1452 "parser.y"
                                                                                                        {(yyval.typeinfo)=createstruct();int p=(yyvsp[0].typeinfo)->exprvalue;(yyval.typeinfo)->arrdim=(yyvsp[-1].typeinfo)->arrdim;((yyval.typeinfo))->arrdim.push_back(p);(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);(yyval.typeinfo)->temporarystore = contemp((yyvsp[-1].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore);}
#line 5468 "parser.tab.c"
    break;

  case 80:
#line 1454 "parser.y"
                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5474 "parser.tab.c"
    break;

  case 81:
#line 1455 "parser.y"
                                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5480 "parser.tab.c"
    break;

  case 82:
#line 1456 "parser.y"
                                                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5486 "parser.tab.c"
    break;

  case 83:
#line 1457 "parser.y"
                                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5492 "parser.tab.c"
    break;

  case 84:
#line 1458 "parser.y"
                                                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5498 "parser.tab.c"
    break;

  case 85:
#line 1459 "parser.y"
                                                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5504 "parser.tab.c"
    break;

  case 86:
#line 1460 "parser.y"
                                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5510 "parser.tab.c"
    break;

  case 87:
#line 1461 "parser.y"
                                                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5516 "parser.tab.c"
    break;

  case 88:
#line 1463 "parser.y"
                                                {(yyval.str)=(yyvsp[0].str);}
#line 5522 "parser.tab.c"
    break;

  case 89:
#line 1465 "parser.y"
                                                                {(yyval.typeinfo) = createstruct(); string p = (yyvsp[0].str);((yyval.typeinfo))->name = p;(yyval.typeinfo)->tempname=p;}
#line 5528 "parser.tab.c"
    break;

  case 90:
#line 1466 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5534 "parser.tab.c"
    break;

  case 91:
#line 1467 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5540 "parser.tab.c"
    break;

  case 92:
#line 1468 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5546 "parser.tab.c"
    break;

  case 93:
#line 1469 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5552 "parser.tab.c"
    break;

  case 94:
#line 1470 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5558 "parser.tab.c"
    break;

  case 95:
#line 1471 "parser.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5564 "parser.tab.c"
    break;

  case 96:
#line 1472 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5570 "parser.tab.c"
    break;

  case 97:
#line 1473 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5576 "parser.tab.c"
    break;

  case 98:
#line 1474 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5582 "parser.tab.c"
    break;

  case 99:
#line 1475 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5588 "parser.tab.c"
    break;

  case 100:
#line 1476 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5594 "parser.tab.c"
    break;

  case 101:
#line 1477 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5600 "parser.tab.c"
    break;

  case 102:
#line 1478 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5606 "parser.tab.c"
    break;

  case 103:
#line 1479 "parser.y"
                                                                                                                {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5612 "parser.tab.c"
    break;

  case 104:
#line 1480 "parser.y"
                                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tempname=x;}
#line 5618 "parser.tab.c"
    break;

  case 105:
#line 1490 "parser.y"
                                                                                        {string x=(yyvsp[0].str);int p=stoi(x);(yyval.typeinfo)=new Typeinfo;     (yyval.typeinfo)->littype="int";(yyval.typeinfo)->valint=p;string y=newtemp();(yyval.typeinfo)->temporarystore = contemp(y);string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->tempname=y;string z=no + y+" = "+x;(yyval.typeinfo)->tac={z};(yyval.typeinfo)->exprvalue=atoi((yyvsp[0].str));((yyval.typeinfo))->type = "int";}
#line 5624 "parser.tab.c"
    break;

  case 106:
#line 1491 "parser.y"
                                                                                        {string x=(yyvsp[0].str);float p=stof(x);(yyval.typeinfo)=new Typeinfo;   (yyval.typeinfo)->littype="float";(yyval.typeinfo)->valfloat=p;string y=newtemp();(yyval.typeinfo)->temporarystore = contemp(y);string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->tempname=y;string z=no + y+" = "+x;(yyval.typeinfo)->tac={z};(yyval.typeinfo)->exprvalue=(int)((yyval.typeinfo)->valfloat);((yyval.typeinfo))->type = "float";}
#line 5630 "parser.tab.c"
    break;

  case 107:
#line 1492 "parser.y"
                                                                                        {string x=(yyvsp[0].str);;(yyval.typeinfo)=new Typeinfo;                  (yyval.typeinfo)->littype="bool";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->temporarystore = contemp(y);string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->tempname=y;string z=no + y+" = "+x;(yyval.typeinfo)->tac={z};if(x=="true"){(yyval.typeinfo)->exprvalue=1;}else{(yyval.typeinfo)->exprvalue=0;};((yyval.typeinfo))->type = "bool";}
#line 5636 "parser.tab.c"
    break;

  case 108:
#line 1493 "parser.y"
                                                                                        {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo;                   (yyval.typeinfo)->littype="null";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->temporarystore = contemp(y);string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->tempname=y;string z=no + y+" = "+x;(yyval.typeinfo)->tac={z};(yyval.typeinfo)->exprvalue=0;(yyval.typeinfo)->type="null";}
#line 5642 "parser.tab.c"
    break;

  case 109:
#line 1494 "parser.y"
                                                                                            {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo;                   (yyval.typeinfo)->littype="char";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->temporarystore = contemp(y);string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->tempname=y;string z=no + y+" = "+x;(yyval.typeinfo)->tac={z};(yyval.typeinfo)->exprvalue=x[0]-'\0';((yyval.typeinfo))->type = "char";}
#line 5648 "parser.tab.c"
    break;

  case 110:
#line 1495 "parser.y"
                                                                                                    {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo;                   (yyval.typeinfo)->littype="string";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->temporarystore = contemp(y);string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->tempname=y;string z=no + y+" = "+x;(yyval.typeinfo)->tac={z};((yyval.typeinfo))->type = "string";}
#line 5654 "parser.tab.c"
    break;

  case 111:
#line 1496 "parser.y"
                                                                                            {string x=(yyvsp[0].str);(yyval.typeinfo)=new Typeinfo;                   (yyval.typeinfo)->littype="textblock";(yyval.typeinfo)->valstr=x;string y=newtemp();(yyval.typeinfo)->temporarystore = contemp(y);string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->tempname=y;string z=no + y+" = "+x;(yyval.typeinfo)->tac={z};((yyval.typeinfo))->type = "textblock";}
#line 5660 "parser.tab.c"
    break;

  case 112:
#line 1497 "parser.y"
                                                                {(yyval.str)=(yyvsp[0].str);}
#line 5666 "parser.tab.c"
    break;

  case 113:
#line 1498 "parser.y"
                                                                                                        {(yyval.str)=(yyvsp[0].str);}
#line 5672 "parser.tab.c"
    break;

  case 114:
#line 1500 "parser.y"
                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5678 "parser.tab.c"
    break;

  case 115:
#line 1502 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=emptyvector();}
#line 5684 "parser.tab.c"
    break;

  case 116:
#line 1503 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=emptyvector();}
#line 5690 "parser.tab.c"
    break;

  case 117:
#line 1505 "parser.y"
                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "byte";(yyval.typeinfo)->tac=emptyvector();}
#line 5696 "parser.tab.c"
    break;

  case 118:
#line 1506 "parser.y"
                                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "short";(yyval.typeinfo)->tac=emptyvector();}
#line 5702 "parser.tab.c"
    break;

  case 119:
#line 1507 "parser.y"
                                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "int";(yyval.typeinfo)->tac=emptyvector();}
#line 5708 "parser.tab.c"
    break;

  case 120:
#line 1508 "parser.y"
                                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "long";(yyval.typeinfo)->tac=emptyvector();}
#line 5714 "parser.tab.c"
    break;

  case 121:
#line 1509 "parser.y"
                                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "char";(yyval.typeinfo)->tac=emptyvector();}
#line 5720 "parser.tab.c"
    break;

  case 122:
#line 1511 "parser.y"
                                                                                                {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "float";(yyval.typeinfo)->tac=emptyvector();}
#line 5726 "parser.tab.c"
    break;

  case 123:
#line 1512 "parser.y"
                                                                                                        {((yyval.typeinfo)) = createstruct();((yyval.typeinfo))->type = "double";(yyval.typeinfo)->tac=emptyvector();}
#line 5732 "parser.tab.c"
    break;

  case 124:
#line 1514 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=emptyvector();}
#line 5738 "parser.tab.c"
    break;

  case 125:
#line 1515 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5744 "parser.tab.c"
    break;

  case 126:
#line 1517 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5750 "parser.tab.c"
    break;

  case 127:
#line 1518 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5756 "parser.tab.c"
    break;

  case 128:
#line 1520 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5762 "parser.tab.c"
    break;

  case 129:
#line 1521 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5768 "parser.tab.c"
    break;

  case 130:
#line 1523 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5774 "parser.tab.c"
    break;

  case 131:
#line 1525 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5780 "parser.tab.c"
    break;

  case 132:
#line 1526 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5786 "parser.tab.c"
    break;

  case 133:
#line 1528 "parser.y"
                                                                {(yyval.typeinfo) = createstruct();string q=((yyvsp[-2].str));string p=((yyvsp[0].str));((yyval.typeinfo))->type=q+"."+p;string x=(yyvsp[-2].str);string r=newtemp();(yyval.typeinfo)->temporarystore = contemp(r);string no = "_xv86 subq $8, %rsp\n"; (yyval.typeinfo)->tempname=r;r=no + r+" = "+x; (yyval.typeinfo)->tac={r};}
#line 5792 "parser.tab.c"
    break;

  case 134:
#line 1529 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();string p=((yyvsp[0].str));((yyval.typeinfo))->type=((yyvsp[-2].typeinfo))->type+"."+p; (yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[-2].typeinfo)->temporarystore;}
#line 5798 "parser.tab.c"
    break;

  case 135:
#line 1531 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct(); ;((yyval.typeinfo))->name = ((yyvsp[0].typeinfo))->name; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 5804 "parser.tab.c"
    break;

  case 136:
#line 1533 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac; for(auto z:((yyval.typeinfo)->tac)) fprintf(dotfile,"%s\n",z.c_str()); }
#line 5810 "parser.tab.c"
    break;

  case 137:
#line 1534 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac; for(auto z:((yyval.typeinfo)->tac)) fprintf(dotfile,"%s\n",z.c_str()); }
#line 5816 "parser.tab.c"
    break;

  case 138:
#line 1536 "parser.y"
                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5822 "parser.tab.c"
    break;

  case 139:
#line 1537 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5828 "parser.tab.c"
    break;

  case 140:
#line 1538 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5834 "parser.tab.c"
    break;

  case 141:
#line 1539 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5840 "parser.tab.c"
    break;

  case 142:
#line 1540 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5846 "parser.tab.c"
    break;

  case 143:
#line 1541 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5852 "parser.tab.c"
    break;

  case 144:
#line 1542 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5858 "parser.tab.c"
    break;

  case 145:
#line 1543 "parser.y"
                                                                                                  {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5864 "parser.tab.c"
    break;

  case 146:
#line 1545 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5870 "parser.tab.c"
    break;

  case 147:
#line 1546 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 5876 "parser.tab.c"
    break;

  case 148:
#line 1548 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5882 "parser.tab.c"
    break;

  case 149:
#line 1549 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5888 "parser.tab.c"
    break;

  case 150:
#line 1551 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5894 "parser.tab.c"
    break;

  case 151:
#line 1552 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5900 "parser.tab.c"
    break;

  case 152:
#line 1553 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5906 "parser.tab.c"
    break;

  case 153:
#line 1554 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5912 "parser.tab.c"
    break;

  case 154:
#line 1556 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5918 "parser.tab.c"
    break;

  case 155:
#line 1557 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5924 "parser.tab.c"
    break;

  case 156:
#line 1559 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5930 "parser.tab.c"
    break;

  case 157:
#line 1561 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5936 "parser.tab.c"
    break;

  case 158:
#line 1562 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5942 "parser.tab.c"
    break;

  case 159:
#line 1564 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5948 "parser.tab.c"
    break;

  case 160:
#line 1565 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 5954 "parser.tab.c"
    break;

  case 161:
#line 1567 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5960 "parser.tab.c"
    break;

  case 162:
#line 1568 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 5966 "parser.tab.c"
    break;

  case 163:
#line 1569 "parser.y"
                                                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 5972 "parser.tab.c"
    break;

  case 164:
#line 1571 "parser.y"
                                               {symtable*a=createtable();string p=((yyvsp[-1].str));insertclass(p,"module","",a,line); pushoff();  changescope(a);  }
#line 5978 "parser.tab.c"
    break;

  case 165:
#line 1571 "parser.y"
                                                                                                                                                                        {goparent();string p=((yyvsp[-3].str));addclasssize(p,offs.top().second); popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();				}
#line 5984 "parser.tab.c"
    break;

  case 166:
#line 1572 "parser.y"
                                        {symtable*a=createtable();string p=((yyvsp[-1].str));insertclass(p,"module","",a,line); pushoff();  changescope(a);  }
#line 5990 "parser.tab.c"
    break;

  case 167:
#line 1572 "parser.y"
                                                                                                                                                                                                {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 5996 "parser.tab.c"
    break;

  case 168:
#line 1573 "parser.y"
                                                        {symtable*a=createtable();string p=((yyvsp[-2].str));insertclass(p+((yyvsp[-1].typeinfo))->name,"module","",a,line); pushoff();changescope(a);}
#line 6002 "parser.tab.c"
    break;

  case 169:
#line 1573 "parser.y"
                                                                                                                                                                                        {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6008 "parser.tab.c"
    break;

  case 170:
#line 1574 "parser.y"
                                                         {symtable*a=createtable();string p=((yyvsp[-2].str));insertclass(p+((yyvsp[-1].typeinfo))->name,"module","",a,line);pushoff(); changescope(a);}
#line 6014 "parser.tab.c"
    break;

  case 171:
#line 1574 "parser.y"
                                                                                                                                                                                                        {goparent();string p=((yyvsp[-5].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6020 "parser.tab.c"
    break;

  case 172:
#line 1575 "parser.y"
                                               {symtable*a=createtable();string p=((yyvsp[-1].str));insertclass(p,"module","",a,line); pushoff();  changescope(a);  }
#line 6026 "parser.tab.c"
    break;

  case 173:
#line 1575 "parser.y"
                                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-3].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6032 "parser.tab.c"
    break;

  case 174:
#line 1576 "parser.y"
                                              {symtable*a=createtable();string p=((yyvsp[-1].str));insertclass(p,"module","",a,line);pushoff();changescope(a);}
#line 6038 "parser.tab.c"
    break;

  case 175:
#line 1576 "parser.y"
                                                                                                                                                                                                {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6044 "parser.tab.c"
    break;

  case 176:
#line 1577 "parser.y"
                                                              {symtable*a=createtable();string p=((yyvsp[-2].str));insertclass(p+((yyvsp[-1].typeinfo))->name,"module","",a,line);pushoff();changescope(a);}
#line 6050 "parser.tab.c"
    break;

  case 177:
#line 1577 "parser.y"
                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6056 "parser.tab.c"
    break;

  case 178:
#line 1578 "parser.y"
                                                              {symtable*a=createtable();string p=((yyvsp[-2].str));insertclass(p+((yyvsp[-1].typeinfo))->name,"module","",a,line);pushoff();changescope(a);}
#line 6062 "parser.tab.c"
    break;

  case 179:
#line 1578 "parser.y"
                                                                                                                                                                                                        {goparent();string p=((yyvsp[-5].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6068 "parser.tab.c"
    break;

  case 180:
#line 1580 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6074 "parser.tab.c"
    break;

  case 181:
#line 1581 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6080 "parser.tab.c"
    break;

  case 182:
#line 1582 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6086 "parser.tab.c"
    break;

  case 183:
#line 1583 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6092 "parser.tab.c"
    break;

  case 184:
#line 1584 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6098 "parser.tab.c"
    break;

  case 185:
#line 1585 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6104 "parser.tab.c"
    break;

  case 186:
#line 1586 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6110 "parser.tab.c"
    break;

  case 187:
#line 1587 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6116 "parser.tab.c"
    break;

  case 188:
#line 1588 "parser.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6122 "parser.tab.c"
    break;

  case 189:
#line 1589 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6128 "parser.tab.c"
    break;

  case 190:
#line 1590 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 6134 "parser.tab.c"
    break;

  case 191:
#line 1591 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6140 "parser.tab.c"
    break;

  case 192:
#line 1592 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-3].typeinfo)->tac;}
#line 6146 "parser.tab.c"
    break;

  case 193:
#line 1593 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 6152 "parser.tab.c"
    break;

  case 194:
#line 1594 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6158 "parser.tab.c"
    break;

  case 195:
#line 1595 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-3].typeinfo)->tac;}
#line 6164 "parser.tab.c"
    break;

  case 196:
#line 1596 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 6170 "parser.tab.c"
    break;

  case 197:
#line 1597 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6176 "parser.tab.c"
    break;

  case 198:
#line 1598 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-3].typeinfo)->tac;}
#line 6182 "parser.tab.c"
    break;

  case 199:
#line 1599 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 6188 "parser.tab.c"
    break;

  case 200:
#line 1600 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-3].typeinfo)->tac;}
#line 6194 "parser.tab.c"
    break;

  case 201:
#line 1601 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 6200 "parser.tab.c"
    break;

  case 202:
#line 1602 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6206 "parser.tab.c"
    break;

  case 203:
#line 1603 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 6212 "parser.tab.c"
    break;

  case 204:
#line 1605 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6218 "parser.tab.c"
    break;

  case 205:
#line 1606 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6224 "parser.tab.c"
    break;

  case 206:
#line 1607 "parser.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6230 "parser.tab.c"
    break;

  case 207:
#line 1609 "parser.y"
                                                                                        {symtable*a=createscope("class");string p=((yyvsp[0].str));insertclass(p,"class","",a,line); pushoff(); fieldpushoff(); changescope(a);  }
#line 6236 "parser.tab.c"
    break;

  case 208:
#line 1609 "parser.y"
                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-2].str));addclasssize(p,offs.top().second); popoff();fieldpopoff(); (yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6242 "parser.tab.c"
    break;

  case 209:
#line 1610 "parser.y"
                                                                                                {symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line); pushoff(); fieldpushoff();  changescope(a);  }
#line 6248 "parser.tab.c"
    break;

  case 210:
#line 1610 "parser.y"
                                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-3].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6254 "parser.tab.c"
    break;

  case 211:
#line 1611 "parser.y"
                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line); pushoff();  fieldpushoff(); changescope(a);  }
#line 6260 "parser.tab.c"
    break;

  case 212:
#line 1611 "parser.y"
                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-3].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6266 "parser.tab.c"
    break;

  case 213:
#line 1612 "parser.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);  pushoff(); fieldpushoff(); changescope(a);  }
#line 6272 "parser.tab.c"
    break;

  case 214:
#line 1612 "parser.y"
                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6278 "parser.tab.c"
    break;

  case 215:
#line 1613 "parser.y"
                                                                                                { symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);  pushoff(); fieldpushoff(); changescope(a);  }
#line 6284 "parser.tab.c"
    break;

  case 216:
#line 1613 "parser.y"
                                                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-3].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6290 "parser.tab.c"
    break;

  case 217:
#line 1614 "parser.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);  pushoff();  fieldpushoff();changescope(a);  }
#line 6296 "parser.tab.c"
    break;

  case 218:
#line 1614 "parser.y"
                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6302 "parser.tab.c"
    break;

  case 219:
#line 1615 "parser.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);  pushoff(); fieldpushoff(); changescope(a);  }
#line 6308 "parser.tab.c"
    break;

  case 220:
#line 1615 "parser.y"
                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6314 "parser.tab.c"
    break;

  case 221:
#line 1616 "parser.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line); fieldpushoff(); pushoff();  changescope(a);  }
#line 6320 "parser.tab.c"
    break;

  case 222:
#line 1616 "parser.y"
                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-5].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6326 "parser.tab.c"
    break;

  case 223:
#line 1617 "parser.y"
                                                                                                                { symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);  pushoff(); fieldpushoff(); changescope(a);  }
#line 6332 "parser.tab.c"
    break;

  case 224:
#line 1617 "parser.y"
                                                                                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-3].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6338 "parser.tab.c"
    break;

  case 225:
#line 1618 "parser.y"
                                                                                                {symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);   pushoff(); fieldpushoff(); changescope(a);  }
#line 6344 "parser.tab.c"
    break;

  case 226:
#line 1618 "parser.y"
                                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6350 "parser.tab.c"
    break;

  case 227:
#line 1619 "parser.y"
                                                                                                {symtable*a=createscope("class");string p=((yyvsp[-2].str)); insertclass(p,"class","",a,line);  pushoff(); fieldpushoff(); changescope(a);  }
#line 6356 "parser.tab.c"
    break;

  case 228:
#line 1619 "parser.y"
                                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6362 "parser.tab.c"
    break;

  case 229:
#line 1620 "parser.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);  pushoff(); fieldpushoff(); changescope(a);  }
#line 6368 "parser.tab.c"
    break;

  case 230:
#line 1620 "parser.y"
                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-5].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6374 "parser.tab.c"
    break;

  case 231:
#line 1621 "parser.y"
                                                                                                {symtable*a=createscope("class");string p=((yyvsp[-2].str)); insertclass(p,"class","",a,line);  pushoff(); fieldpushoff(); changescope(a);  }
#line 6380 "parser.tab.c"
    break;

  case 232:
#line 1621 "parser.y"
                                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6386 "parser.tab.c"
    break;

  case 233:
#line 1622 "parser.y"
                                                                                {symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);  pushoff();  fieldpushoff(); changescope(a);  }
#line 6392 "parser.tab.c"
    break;

  case 234:
#line 1622 "parser.y"
                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-5].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6398 "parser.tab.c"
    break;

  case 235:
#line 1623 "parser.y"
                                                                                { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);  pushoff();fieldpushoff();  changescope(a);  }
#line 6404 "parser.tab.c"
    break;

  case 236:
#line 1623 "parser.y"
                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-5].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6410 "parser.tab.c"
    break;

  case 237:
#line 1624 "parser.y"
                                                                                            {symtable*a=createscope("class");string p=((yyvsp[-4].str)); insertclass(p,"class","",a,line);  pushoff(); fieldpushoff(); changescope(a);  }
#line 6416 "parser.tab.c"
    break;

  case 238:
#line 1624 "parser.y"
                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-6].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6422 "parser.tab.c"
    break;

  case 239:
#line 1625 "parser.y"
                                                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[0].str));insertclass(p,"class","",a,line);  pushoff(); fieldpushoff(); changescope(a);  }
#line 6428 "parser.tab.c"
    break;

  case 240:
#line 1625 "parser.y"
                                                                                                                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-2].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6434 "parser.tab.c"
    break;

  case 241:
#line 1626 "parser.y"
                                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);  pushoff(); fieldpushoff(); changescope(a);  }
#line 6440 "parser.tab.c"
    break;

  case 242:
#line 1626 "parser.y"
                                                                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-3].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6446 "parser.tab.c"
    break;

  case 243:
#line 1627 "parser.y"
                                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-1].str)); insertclass(p,"class","",a,line);  pushoff(); fieldpushoff(); changescope(a);  }
#line 6452 "parser.tab.c"
    break;

  case 244:
#line 1627 "parser.y"
                                                                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-3].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6458 "parser.tab.c"
    break;

  case 245:
#line 1628 "parser.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);  pushoff(); fieldpushoff(); changescope(a);  }
#line 6464 "parser.tab.c"
    break;

  case 246:
#line 1628 "parser.y"
                                                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6470 "parser.tab.c"
    break;

  case 247:
#line 1629 "parser.y"
                                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-1].str));insertclass(p,"class","",a,line);  pushoff();  fieldpushoff();changescope(a);  }
#line 6476 "parser.tab.c"
    break;

  case 248:
#line 1629 "parser.y"
                                                                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-3].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6482 "parser.tab.c"
    break;

  case 249:
#line 1630 "parser.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);  pushoff();fieldpushoff();  changescope(a);  }
#line 6488 "parser.tab.c"
    break;

  case 250:
#line 1630 "parser.y"
                                                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6494 "parser.tab.c"
    break;

  case 251:
#line 1631 "parser.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);  pushoff();fieldpushoff();  changescope(a);  }
#line 6500 "parser.tab.c"
    break;

  case 252:
#line 1631 "parser.y"
                                                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6506 "parser.tab.c"
    break;

  case 253:
#line 1632 "parser.y"
                                                                                            { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);  pushoff();fieldpushoff();  changescope(a);  }
#line 6512 "parser.tab.c"
    break;

  case 254:
#line 1632 "parser.y"
                                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-5].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6518 "parser.tab.c"
    break;

  case 255:
#line 1633 "parser.y"
                                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-1].str)); insertclass(p,"class","",a,line);  pushoff(); fieldpushoff(); changescope(a);  }
#line 6524 "parser.tab.c"
    break;

  case 256:
#line 1633 "parser.y"
                                                                                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-3].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6530 "parser.tab.c"
    break;

  case 257:
#line 1634 "parser.y"
                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);   pushoff(); fieldpushoff();changescope(a);  }
#line 6536 "parser.tab.c"
    break;

  case 258:
#line 1634 "parser.y"
                                                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6542 "parser.tab.c"
    break;

  case 259:
#line 1635 "parser.y"
                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-2].str)); insertclass(p,"class","",a,line);  pushoff(); fieldpushoff(); changescope(a);  }
#line 6548 "parser.tab.c"
    break;

  case 260:
#line 1635 "parser.y"
                                                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6554 "parser.tab.c"
    break;

  case 261:
#line 1636 "parser.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);  pushoff();fieldpushoff();  changescope(a);  }
#line 6560 "parser.tab.c"
    break;

  case 262:
#line 1636 "parser.y"
                                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-5].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6566 "parser.tab.c"
    break;

  case 263:
#line 1637 "parser.y"
                                                                                                                        {symtable*a=createscope("class");string p=((yyvsp[-2].str));insertclass(p,"class","",a,line);  pushoff(); fieldpushoff();  changescope(a);  }
#line 6572 "parser.tab.c"
    break;

  case 264:
#line 1637 "parser.y"
                                                                                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6578 "parser.tab.c"
    break;

  case 265:
#line 1638 "parser.y"
                                                                                                        { symtable*a=createscope("class");string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);  pushoff(); fieldpushoff(); changescope(a);  }
#line 6584 "parser.tab.c"
    break;

  case 266:
#line 1638 "parser.y"
                                                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-5].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6590 "parser.tab.c"
    break;

  case 267:
#line 1639 "parser.y"
                                                                                                        { symtable*a=createtable();string p=((yyvsp[-3].str));insertclass(p,"class","",a,line);  pushoff();fieldpushoff();  changescope(a);  }
#line 6596 "parser.tab.c"
    break;

  case 268:
#line 1639 "parser.y"
                                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-5].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6602 "parser.tab.c"
    break;

  case 269:
#line 1640 "parser.y"
                                                                                                             { symtable*a=createscope("class");string p=((yyvsp[-4].str));insertclass(p,"class","",a,line);  pushoff();fieldpushoff();  changescope(a);  }
#line 6608 "parser.tab.c"
    break;

  case 270:
#line 1640 "parser.y"
                                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-6].str));addclasssize(p,offs.top().second);popoff();fieldpopoff();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6614 "parser.tab.c"
    break;

  case 271:
#line 1642 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6620 "parser.tab.c"
    break;

  case 272:
#line 1644 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6626 "parser.tab.c"
    break;

  case 273:
#line 1645 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6632 "parser.tab.c"
    break;

  case 274:
#line 1647 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6638 "parser.tab.c"
    break;

  case 275:
#line 1649 "parser.y"
                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6644 "parser.tab.c"
    break;

  case 276:
#line 1651 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6650 "parser.tab.c"
    break;

  case 277:
#line 1652 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6656 "parser.tab.c"
    break;

  case 278:
#line 1655 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6662 "parser.tab.c"
    break;

  case 279:
#line 1656 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6668 "parser.tab.c"
    break;

  case 280:
#line 1657 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6674 "parser.tab.c"
    break;

  case 281:
#line 1658 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6680 "parser.tab.c"
    break;

  case 282:
#line 1660 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6686 "parser.tab.c"
    break;

  case 283:
#line 1661 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 6692 "parser.tab.c"
    break;

  case 284:
#line 1663 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6698 "parser.tab.c"
    break;

  case 285:
#line 1664 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6704 "parser.tab.c"
    break;

  case 286:
#line 1665 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6710 "parser.tab.c"
    break;

  case 287:
#line 1666 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6716 "parser.tab.c"
    break;

  case 288:
#line 1668 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6722 "parser.tab.c"
    break;

  case 289:
#line 1669 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6728 "parser.tab.c"
    break;

  case 290:
#line 1670 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6734 "parser.tab.c"
    break;

  case 291:
#line 1671 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 6740 "parser.tab.c"
    break;

  case 292:
#line 1672 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 6746 "parser.tab.c"
    break;

  case 293:
#line 1677 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-1].typeinfo);(yyval.typeinfo)->dectype=(yyvsp[-2].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[-2].typeinfo)->decorder1;((yyval.typeinfo))->variables=((yyvsp[-1].typeinfo))->variables;(yyval.typeinfo)->decorders2=(yyvsp[-1].typeinfo)->decorders2;(yyval.typeinfo)->arrtypes=(yyvsp[-1].typeinfo)->arrtypes;(yyval.typeinfo)->arrdims=(yyvsp[-1].typeinfo)->arrdims;(yyval.typeinfo)->initvartypes=(yyvsp[-1].typeinfo)->initvartypes;((yyval.typeinfo))->puvariables=((yyvsp[-1].typeinfo))->puvariables;
 int n=((yyval.typeinfo))->variables.size();
    for(int i=0;i<n;i++){
        int order=(yyval.typeinfo)->decorder1+((yyval.typeinfo)->decorders2)[i];
        string x;
        if(order)
        x="array";
        else
        x="identifier";
					if(((yyval.typeinfo)->initialdecls)[i]){
							// cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
							insertidentifier((yyval.typeinfo)->variables[i],x,(yyval.typeinfo)->dectype,"",0,order,(yyval.typeinfo)->arrdims[i],fieldoffs.top());
							fieldincoff();
					}
					else{
							vector<int>p(order,0);
							// cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
							insertidentifier((yyval.typeinfo)->variables[i],x,(yyval.typeinfo)->dectype,"",0,order,p,fieldoffs.top());
							fieldincoff();
					}
				
    }vector<string> s = pushlocal(((yyvsp[-1].typeinfo))->puvariables);
    
		int sub = 0;
		for(auto l:((yyval.typeinfo)->variables)){
			if(lookup(l)){
				if(lookup(l)->type == "array"){
					vector<int> arrd = lookup(l)->arrdims;
					int mul = 8;
					for(auto cu:arrd){
						mul = mul*cu;
					}
					sub = sub+ mul;
				}
				else{
					sub = sub + 8;
				}
			}
		}
		// printte($$->temporarystore);
		// printte($$->variables);
		// cout<<"subq  $"<<sub<<", %rsp";
		string subq = "_xv86 subq  $"+to_string(sub)+", %rsp";
		(yyval.typeinfo)->tac=concvector(subq,s,(yyvsp[-1].typeinfo)->tac);
		(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;
	}
#line 6797 "parser.tab.c"
    break;

  case 294:
#line 1723 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-1].typeinfo);(yyval.typeinfo)->dectype=(yyvsp[-2].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[-2].typeinfo)->decorder1;((yyval.typeinfo))->variables=((yyvsp[-1].typeinfo))->variables;(yyval.typeinfo)->decorders2=(yyvsp[-1].typeinfo)->decorders2;(yyval.typeinfo)->arrtypes=(yyvsp[-1].typeinfo)->arrtypes;(yyval.typeinfo)->arrdims=(yyvsp[-1].typeinfo)->arrdims;(yyval.typeinfo)->initvartypes=(yyvsp[-1].typeinfo)->initvartypes;((yyval.typeinfo))->puvariables=((yyvsp[-1].typeinfo))->puvariables;
 	int n=((yyval.typeinfo))->variables.size();
    for(int i=0;i<n;i++){
        int order=(yyval.typeinfo)->decorder1+((yyval.typeinfo)->decorders2)[i];
        string x;
        if(order)
        x="array";
        else
        x="identifier";

					if(((yyval.typeinfo)->initialdecls)[i]){
							// cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
							insertidentifier((yyval.typeinfo)->variables[i],x,(yyval.typeinfo)->dectype,"",0,order,(yyval.typeinfo)->arrdims[i],fieldoffs.top());
							fieldincoff();
					}
					else{
							vector<int>p(order,0);
							// cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
							insertidentifier((yyval.typeinfo)->variables[i],x,(yyval.typeinfo)->dectype,"",0,order,p,fieldoffs.top());
							fieldincoff();
					}
				}
		vector<string> s = pushlocal(((yyvsp[-1].typeinfo))->puvariables);
    // $$->tac=concvector(s,$2->tac);
		// $$->temporarystore = $3->temporarystore;
		int sub = 0;
		for(auto l:((yyval.typeinfo)->variables)){
			if(lookup(l)){
				if(lookup(l)->type == "array"){
					vector<int> arrd = lookup(l)->arrdims;
					int mul = 8;
					for(auto cu:arrd){
						mul = mul*cu;
					}
					sub = sub+ mul;
				}
				else{
					sub = sub + 8;
				}
			}
		}
		// printte($$->temporarystore);
		// printte($$->variables);
		// cout<<"subq  $"<<sub<<", %rsp";
		string subq = "_xv86 subq  $"+to_string(sub)+", %rsp";
		(yyval.typeinfo)->tac=concvector(subq,s,(yyvsp[-1].typeinfo)->tac);
		(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;
	}
#line 6850 "parser.tab.c"
    break;

  case 295:
#line 1772 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->variables.push_back((yyvsp[0].typeinfo)->variable);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->decorders2.push_back(((yyvsp[0].typeinfo))->decorder2);(yyval.typeinfo)->arrtypes.push_back((yyvsp[0].typeinfo)->arrtype);(yyval.typeinfo)->arrdims.push_back((yyvsp[0].typeinfo)->arrdim);(yyval.typeinfo)->initialdecls.push_back((yyvsp[0].typeinfo)->initialdecl);(yyval.typeinfo)->initvartypes.push_back((yyvsp[0].typeinfo)->initvartype);((yyval.typeinfo))->puvariables = ((yyvsp[0].typeinfo))->puvariables;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 6856 "parser.tab.c"
    break;

  case 296:
#line 1773 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-2].typeinfo);((yyval.typeinfo))->variables.push_back((yyvsp[0].typeinfo)->variable);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->decorders2.push_back(((yyvsp[0].typeinfo))->decorder2);(yyval.typeinfo)->arrtypes.push_back((yyvsp[0].typeinfo)->arrtype);(yyval.typeinfo)->arrdims.push_back((yyvsp[0].typeinfo)->arrdim);(yyval.typeinfo)->initialdecls.push_back((yyvsp[0].typeinfo)->initialdecl);(yyval.typeinfo)->initvartypes.push_back((yyvsp[0].typeinfo)->initvartype);vector<string>a=((yyvsp[-2].typeinfo))->puvariables;vector<string>b=((yyvsp[0].typeinfo))->puvariables;for(auto z:b){((yyval.typeinfo))->puvariables.push_back(z);} (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore);}
#line 6862 "parser.tab.c"
    break;

  case 297:
#line 1775 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->initialdecl=false;((yyval.typeinfo))->puvariables = ((yyvsp[0].typeinfo))->puvariables;(yyval.typeinfo)->tac=emptyvector();(yyval.typeinfo)->temporarystore = emptyvector();}
#line 6868 "parser.tab.c"
    break;

  case 298:
#line 1776 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-2].typeinfo);(yyval.typeinfo)->initialdecl=true;(yyval.typeinfo)->arrtype=(yyvsp[0].typeinfo)->arrtype;(yyval.typeinfo)->arrdim=(yyvsp[0].typeinfo)->arrdim;(yyval.typeinfo)->initvartype=(yyvsp[0].typeinfo)->initvartype;string c=(yyvsp[-2].typeinfo)->tempname+" = "+(yyvsp[0].typeinfo)->tempname;((yyval.typeinfo))->puvariables = ((yyvsp[-2].typeinfo))->puvariables;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,c);(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 6874 "parser.tab.c"
    break;

  case 299:
#line 1778 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();string p=((yyvsp[0].str));(yyval.typeinfo)->variable=p;(yyval.typeinfo)->decorder2=0;string x=(yyvsp[0].str);(yyval.typeinfo)->tempname=x;((yyval.typeinfo))->puvariables.push_back(x);}
#line 6880 "parser.tab.c"
    break;

  case 300:
#line 1779 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();string p=((yyvsp[-1].str));(yyval.typeinfo)->variable=p;(yyval.typeinfo)->decorder2=(yyvsp[0].typeinfo)->order;string x=(yyvsp[-1].str);(yyval.typeinfo)->tempname=x;((yyval.typeinfo))->puvariables.push_back(x);}
#line 6886 "parser.tab.c"
    break;

  case 301:
#line 1781 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 6892 "parser.tab.c"
    break;

  case 302:
#line 1782 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->arrtype=(yyvsp[0].typeinfo)->arrtype;(yyval.typeinfo)->arrdim=(yyvsp[0].typeinfo)->arrdim;(yyval.typeinfo)->initvartype="";}
#line 6898 "parser.tab.c"
    break;

  case 303:
#line 1784 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->dectype=(yyvsp[0].typeinfo)->type;(yyvsp[0].typeinfo)->decorder1=0;}
#line 6904 "parser.tab.c"
    break;

  case 304:
#line 1785 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();string p = (yyvsp[0].str);((yyval.typeinfo))->type = p;(yyval.typeinfo)->dectype=p;(yyval.typeinfo)->tempname=p;(yyval.typeinfo)->decorder1=0;}
#line 6910 "parser.tab.c"
    break;

  case 305:
#line 1786 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type=((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->dectype=(yyvsp[0].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[0].typeinfo)->decorder1;}
#line 6916 "parser.tab.c"
    break;

  case 306:
#line 1788 "parser.y"
                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=emptyvector();}
#line 6922 "parser.tab.c"
    break;

  case 307:
#line 1789 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";(yyval.typeinfo)->tac=emptyvector();}
#line 6928 "parser.tab.c"
    break;

  case 308:
#line 1791 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type + ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->dectype=(yyvsp[-1].typeinfo)->type;(yyval.typeinfo)->decorder1=(yyvsp[0].typeinfo)->order;(yyval.typeinfo)->tac=emptyvector();}
#line 6934 "parser.tab.c"
    break;

  case 309:
#line 1792 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();string p = (yyvsp[-1].str);((yyval.typeinfo))->type = p + ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->dectype="";(yyval.typeinfo)->decorder1=(yyvsp[0].typeinfo)->order;(yyval.typeinfo)->tac=emptyvector();}
#line 6940 "parser.tab.c"
    break;

  case 310:
#line 1795 "parser.y"
                                                                {goparent(); popoff(); insertmethod(((yyvsp[-1].typeinfo))->variables[0],"Method",((yyvsp[-1].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-1].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-1].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="function end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->method_argvari = (yyvsp[-1].typeinfo)->method_argvari; vector<string> xs = funcstart86((yyvsp[-1].typeinfo)->variables[0],((yyval.typeinfo)->method_argvari).size()*8);vector<string> xe = funcend86();(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,xs,(yyvsp[0].typeinfo)->tac,z,sv,p,xe);}
#line 6946 "parser.tab.c"
    break;

  case 311:
#line 1796 "parser.y"
                                                                                {goparent(); popoff(); insertmethod(((yyvsp[-1].typeinfo))->variables[0],"Method",((yyvsp[-1].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-1].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="function end"; stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st); 	currmethod.pop(); currmethodlocals.pop();(yyval.typeinfo)->method_argvari = (yyvsp[-1].typeinfo)->method_argvari; vector<string> xs = funcstart86((yyvsp[-1].typeinfo)->variables[0],((yyval.typeinfo)->method_argvari).size()*8);vector<string> xe = funcend86(); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,xs,(yyvsp[0].typeinfo)->tac,z,sv,p,xe);}
#line 6952 "parser.tab.c"
    break;

  case 312:
#line 1798 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;((yyval.typeinfo))->variables = ((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;((yyval.typeinfo))->scope =((yyvsp[-1].typeinfo))->scope;((yyval.typeinfo))->linep = ((yyvsp[0].typeinfo))->linep;(yyval.typeinfo)->tempname=((yyvsp[-1].typeinfo))->tempname; string f = ((yyvsp[-1].typeinfo))->tempname; string q=newmethodlabel(f);string p="call "+((yyvsp[-1].typeinfo))->tempname+"\n"+q;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->method_argvari = (yyvsp[0].typeinfo)->method_argvari;}
#line 6958 "parser.tab.c"
    break;

  case 313:
#line 1799 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;((yyval.typeinfo))->variables = ((yyvsp[-2].typeinfo))->variables;((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;((yyval.typeinfo))->scope =((yyvsp[-2].typeinfo))->scope;((yyval.typeinfo))->linep = ((yyvsp[-1].typeinfo))->linep;(yyval.typeinfo)->tempname=((yyvsp[-2].typeinfo))->tempname; string f = ((yyvsp[-2].typeinfo))->tempname; string q=newmethodlabel(f);string p="call "+((yyvsp[-2].typeinfo))->tempname+"\n"+q; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;(yyval.typeinfo)->method_argvari = (yyvsp[-1].typeinfo)->method_argvari;}
#line 6964 "parser.tab.c"
    break;

  case 314:
#line 1800 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;((yyval.typeinfo))->variables = ((yyvsp[-1].typeinfo))->variables;((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;((yyval.typeinfo))->scope =((yyvsp[-1].typeinfo))->scope;((yyval.typeinfo))->linep = ((yyvsp[0].typeinfo))->linep;(yyval.typeinfo)->tempname=((yyvsp[-1].typeinfo))->tempname; string f = ((yyvsp[-1].typeinfo))->tempname; string q=newmethodlabel(f);string p="call "+((yyvsp[-1].typeinfo))->tempname+"\n"+q; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->method_argvari = (yyvsp[0].typeinfo)->method_argvari;}
#line 6970 "parser.tab.c"
    break;

  case 315:
#line 1801 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;((yyval.typeinfo))->variables = ((yyvsp[-2].typeinfo))->variables;((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;((yyval.typeinfo))->scope =((yyvsp[-2].typeinfo))->scope;((yyval.typeinfo))->linep = ((yyvsp[-1].typeinfo))->linep;(yyval.typeinfo)->tempname=((yyvsp[-2].typeinfo))->tempname; string f = ((yyvsp[-2].typeinfo))->tempname; string q=newmethodlabel(f);string p="call "+((yyvsp[-2].typeinfo))->tempname+"\n"+q; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;(yyval.typeinfo)->method_argvari = (yyvsp[-1].typeinfo)->method_argvari;}
#line 6976 "parser.tab.c"
    break;

  case 316:
#line 1803 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();symtable*a = createscope("Method");((yyval.typeinfo))->scope = a; ((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;string p = (yyvsp[0].str);((yyval.typeinfo))->variables.push_back(p); pushoff(); changescope(a);string x=(yyvsp[0].str); (yyval.typeinfo)->tempname=x;(yyval.typeinfo)->tac=emptyvector();}
#line 6982 "parser.tab.c"
    break;

  case 317:
#line 1804 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();symtable*a = createscope("Method");((yyval.typeinfo))->scope = a;((yyval.typeinfo))->type = "void";string p = (yyvsp[0].str);((yyval.typeinfo))->variables.push_back(p); pushoff(); changescope(a);string x=(yyvsp[0].str); (yyval.typeinfo)->tempname=x;(yyval.typeinfo)->tac=emptyvector();}
#line 6988 "parser.tab.c"
    break;

  case 318:
#line 1806 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back("void");((yyval.typeinfo))->linep = line; (yyval.typeinfo)->tac=emptyvector();}
#line 6994 "parser.tab.c"
    break;

  case 319:
#line 1807 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct(); (yyval.typeinfo)->tac=emptyvector();}
#line 7000 "parser.tab.c"
    break;

  case 320:
#line 1808 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;((yyval.typeinfo))->linep = line;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;(yyval.typeinfo)->method_argvari = (yyvsp[-1].typeinfo)->method_argvari;}
#line 7006 "parser.tab.c"
    break;

  case 321:
#line 1809 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 7012 "parser.tab.c"
    break;

  case 322:
#line 1810 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7018 "parser.tab.c"
    break;

  case 323:
#line 1811 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 7024 "parser.tab.c"
    break;

  case 324:
#line 1812 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;((yyval.typeinfo))->linep = line;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;(yyval.typeinfo)->method_argvari = (yyvsp[-1].typeinfo)->method_argvari;}
#line 7030 "parser.tab.c"
    break;

  case 325:
#line 1813 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 7036 "parser.tab.c"
    break;

  case 326:
#line 1815 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7042 "parser.tab.c"
    break;

  case 327:
#line 1816 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7048 "parser.tab.c"
    break;

  case 328:
#line 1818 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->method_argvari = (yyvsp[0].typeinfo)->method_argvari;}
#line 7054 "parser.tab.c"
    break;

  case 329:
#line 1819 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();vector<string>a=((yyvsp[-1].typeinfo))->type_variable;vector<string>b=((yyvsp[0].typeinfo))->type_variable;for(auto z:a){((yyval.typeinfo))->type_variable.push_back(z);}for(auto z:b){((yyval.typeinfo))->type_variable.push_back(z);}vector<string>c=((yyvsp[-1].typeinfo))->method_argvari;vector<string>d=((yyvsp[0].typeinfo))->method_argvari;for(auto z:c){((yyval.typeinfo))->method_argvari.push_back(z);}for(auto z:d){((yyval.typeinfo))->method_argvari.push_back(z);}(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7060 "parser.tab.c"
    break;

  case 330:
#line 1821 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-1].typeinfo))->type+((yyvsp[0].typeinfo))->type);((yyval.typeinfo))->type=((yyvsp[-1].typeinfo))->type+((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->method_argvari.push_back((yyvsp[0].typeinfo)->variable);
						 int order=(yyvsp[-1].typeinfo)->decorder1+(yyvsp[0].typeinfo)->decorder2;
						string x;
						if(order)
						x="array";
						else
						x="identifier";
						vector<int>p(order,0);
            // cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
            insertidentifier((yyvsp[0].typeinfo)->variable,x,(yyvsp[-1].typeinfo)->dectype,"",0,order,p,offs.top().first);
						if(x=="identifier"){
							incoff((yyvsp[-1].typeinfo)->dectype,true);
						}
						else{
							incoff((yyvsp[-1].typeinfo)->dectype,true,p);
						}
						(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7082 "parser.tab.c"
    break;

  case 331:
#line 1838 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-1].typeinfo))->type+((yyvsp[0].typeinfo))->type);((yyval.typeinfo))->type=((yyvsp[-1].typeinfo))->type+((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->method_argvari.push_back((yyvsp[0].typeinfo)->variable);
						 int order=(yyvsp[-1].typeinfo)->decorder1+(yyvsp[0].typeinfo)->decorder2;
						string x;
						if(order)
						x="array";
						else
						x="identifier";
						vector<int>p(order,0);
            // cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
            insertidentifier((yyvsp[0].typeinfo)->variable,x,(yyvsp[-1].typeinfo)->dectype,"",0,order,p,offs.top().first);
						if(x=="identifier"){
							incoff((yyvsp[-1].typeinfo)->dectype,true);
						}
						else{
							incoff((yyvsp[-1].typeinfo)->dectype,true,p);
						}
						(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7104 "parser.tab.c"
    break;

  case 332:
#line 1855 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7110 "parser.tab.c"
    break;

  case 333:
#line 1857 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-2].typeinfo))->type);(yyval.typeinfo)->tac=emptyvector();}
#line 7116 "parser.tab.c"
    break;

  case 334:
#line 1858 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-2].typeinfo))->type);(yyval.typeinfo)->tac=emptyvector();}
#line 7122 "parser.tab.c"
    break;

  case 335:
#line 1860 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7128 "parser.tab.c"
    break;

  case 336:
#line 1862 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7134 "parser.tab.c"
    break;

  case 337:
#line 1863 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7140 "parser.tab.c"
    break;

  case 338:
#line 1865 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7146 "parser.tab.c"
    break;

  case 339:
#line 1868 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7152 "parser.tab.c"
    break;

  case 340:
#line 1869 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7158 "parser.tab.c"
    break;

  case 341:
#line 1871 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7164 "parser.tab.c"
    break;

  case 342:
#line 1873 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7170 "parser.tab.c"
    break;

  case 343:
#line 1876 "parser.y"
                                                                                {goparent(); popoff(); insertmethod(((yyvsp[-1].typeinfo))->variables[0],"constructor",((yyvsp[-1].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-1].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-1].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop();(yyval.typeinfo)->method_argvari = (yyvsp[-1].typeinfo)->method_argvari; vector<string> xs = funcstart86((yyvsp[-1].typeinfo)->variables[0],((yyval.typeinfo)->method_argvari).size()*8);vector<string> xe = funcend86(); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,xs,(yyvsp[0].typeinfo)->tac,z,sv,p,xe);}
#line 7176 "parser.tab.c"
    break;

  case 344:
#line 1877 "parser.y"
                                                                                        {goparent(); popoff();insertmethod(((yyvsp[-2].typeinfo))->variables[0],"constructor",((yyvsp[-2].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-2].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->method_argvari = (yyvsp[-2].typeinfo)->method_argvari;vector<string> xs = funcstart86((yyvsp[-2].typeinfo)->variables[0],((yyval.typeinfo)->method_argvari).size()*8);vector<string> xe = funcend86();(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,xs,(yyvsp[0].typeinfo)->tac,z,sv,p,xe);}
#line 7182 "parser.tab.c"
    break;

  case 345:
#line 1878 "parser.y"
                                                                                        {goparent();popoff();insertmethod(((yyvsp[-1].typeinfo))->variables[0],"constructor",((yyvsp[-1].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-1].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-1].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->method_argvari = (yyvsp[-1].typeinfo)->method_argvari; vector<string> xs = funcstart86((yyvsp[-1].typeinfo)->variables[0],((yyval.typeinfo)->method_argvari).size()*8);vector<string> xe = funcend86();(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,xs,(yyvsp[0].typeinfo)->tac,z,sv,p,xe);}
#line 7188 "parser.tab.c"
    break;

  case 346:
#line 1879 "parser.y"
                                                                                {goparent();popoff();insertmethod(((yyvsp[-2].typeinfo))->variables[0],"constructor",((yyvsp[-2].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-2].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop();(yyval.typeinfo)->method_argvari = (yyvsp[-2].typeinfo)->method_argvari; vector<string> xs = funcstart86((yyvsp[-2].typeinfo)->variables[0],((yyval.typeinfo)->method_argvari).size()*8);vector<string> xe = funcend86(); (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,xs,(yyvsp[0].typeinfo)->tac,z,sv,p,xe);}
#line 7194 "parser.tab.c"
    break;

  case 347:
#line 1881 "parser.y"
                                 {(yyval.typeinfo) = createstruct();symtable*a = createscope("constructor");((yyval.typeinfo))->scope = a; pushoff(); changescope(a);}
#line 7200 "parser.tab.c"
    break;

  case 348:
#line 1883 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->scope = ((yyvsp[-1].typeinfo))->scope; ((yyval.typeinfo))->type_variable.push_back("void");string p = (yyvsp[-2].str);((yyval.typeinfo))->variables.push_back(p);((yyval.typeinfo))->type = "void";((yyval.typeinfo))->linep = line;string x = (yyvsp[-2].str);(yyval.typeinfo)->tempname=x;  string q=newmethodlabel(x);string g="call "+x+"\n"+q;(yyval.typeinfo)->tac=concvector(g);}
#line 7206 "parser.tab.c"
    break;

  case 349:
#line 1884 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->scope = ((yyvsp[-2].typeinfo))->scope;((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;string p = (yyvsp[-3].str);((yyval.typeinfo))->variables.push_back(p);((yyval.typeinfo))->type = "void";((yyval.typeinfo))->linep = line;string x = (yyvsp[-3].str);(yyval.typeinfo)->tempname=x;  string q=newmethodlabel(x);string g="call "+x+"\n"+q;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;(yyval.typeinfo)->method_argvari = (yyvsp[-1].typeinfo)->method_argvari;}
#line 7212 "parser.tab.c"
    break;

  case 350:
#line 1885 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=emptyvector();}
#line 7218 "parser.tab.c"
    break;

  case 351:
#line 1886 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7224 "parser.tab.c"
    break;

  case 352:
#line 1887 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->scope = ((yyvsp[-1].typeinfo))->scope;((yyval.typeinfo))->type_variable.push_back("void");string p = (yyvsp[-2].str); ((yyval.typeinfo))->variables.push_back(p);((yyval.typeinfo))->type = "void";((yyval.typeinfo))->linep = line;string x = (yyvsp[-2].str);(yyval.typeinfo)->tempname=x;  string q=newmethodlabel(x);string g="call "+x+"\n"+q;(yyval.typeinfo)->tac=concvector(g);}
#line 7230 "parser.tab.c"
    break;

  case 353:
#line 1888 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->scope = ((yyvsp[-2].typeinfo))->scope;((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;string p = (yyvsp[-3].str);((yyval.typeinfo))->variables.push_back(p);((yyval.typeinfo))->type = "void";((yyval.typeinfo))->linep = line;string x = (yyvsp[-3].str);(yyval.typeinfo)->tempname=x;  string q=newmethodlabel(x);string g="call "+x+"\n"+q;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;(yyval.typeinfo)->method_argvari = (yyvsp[-1].typeinfo)->method_argvari;}
#line 7236 "parser.tab.c"
    break;

  case 354:
#line 1889 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7242 "parser.tab.c"
    break;

  case 355:
#line 1890 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;}
#line 7248 "parser.tab.c"
    break;

  case 356:
#line 1893 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7254 "parser.tab.c"
    break;

  case 357:
#line 1894 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7260 "parser.tab.c"
    break;

  case 358:
#line 1895 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7266 "parser.tab.c"
    break;

  case 359:
#line 1896 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 7272 "parser.tab.c"
    break;

  case 360:
#line 1898 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters();string s = ((yyvsp[-3].str));((yyval.typeinfo))->tempname = "%rax";string s1 = gotomethod(s,0);string s2 = newmethodretlabel(s); (yyval.typeinfo)->tac=concvector(pv1,s1,s2,pv2);}
#line 7278 "parser.tab.c"
    break;

  case 361:
#line 1899 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters(); string s = ((yyvsp[-4].str));((yyval.typeinfo))->tempname = "%rax"; string s1 = gotomethod(s,(yyvsp[-2].typeinfo)->params.size());string s2 = newmethodretlabel(s);vector<string> pushpar = pusharg(((yyvsp[-2].typeinfo))->params);(yyval.typeinfo)->tac=concvector(pv1,(yyvsp[-2].typeinfo)->tac,pushpar,s1,s2,pv2);(yyval.typeinfo)->temporarystore = (yyvsp[-2].typeinfo)->temporarystore;}
#line 7284 "parser.tab.c"
    break;

  case 362:
#line 1900 "parser.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7290 "parser.tab.c"
    break;

  case 363:
#line 1901 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[-2].typeinfo)->temporarystore;}
#line 7296 "parser.tab.c"
    break;

  case 364:
#line 1902 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7302 "parser.tab.c"
    break;

  case 365:
#line 1903 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[-2].typeinfo)->temporarystore;}
#line 7308 "parser.tab.c"
    break;

  case 366:
#line 1904 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7314 "parser.tab.c"
    break;

  case 367:
#line 1905 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[-2].typeinfo)->temporarystore;}
#line 7320 "parser.tab.c"
    break;

  case 368:
#line 1906 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7326 "parser.tab.c"
    break;

  case 369:
#line 1907 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-2].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[-2].typeinfo)->temporarystore;}
#line 7332 "parser.tab.c"
    break;

  case 370:
#line 1909 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7338 "parser.tab.c"
    break;

  case 371:
#line 1910 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7344 "parser.tab.c"
    break;

  case 372:
#line 1911 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7350 "parser.tab.c"
    break;

  case 373:
#line 1912 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7356 "parser.tab.c"
    break;

  case 374:
#line 1915 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7362 "parser.tab.c"
    break;

  case 375:
#line 1916 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7368 "parser.tab.c"
    break;

  case 376:
#line 1917 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7374 "parser.tab.c"
    break;

  case 377:
#line 1918 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7380 "parser.tab.c"
    break;

  case 378:
#line 1919 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7386 "parser.tab.c"
    break;

  case 379:
#line 1920 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 7392 "parser.tab.c"
    break;

  case 380:
#line 1922 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7398 "parser.tab.c"
    break;

  case 381:
#line 1923 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7404 "parser.tab.c"
    break;

  case 382:
#line 1925 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 7410 "parser.tab.c"
    break;

  case 383:
#line 1927 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;}
#line 7416 "parser.tab.c"
    break;

  case 384:
#line 1929 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7422 "parser.tab.c"
    break;

  case 385:
#line 1930 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7428 "parser.tab.c"
    break;

  case 386:
#line 1931 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 7434 "parser.tab.c"
    break;

  case 387:
#line 1932 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7440 "parser.tab.c"
    break;

  case 388:
#line 1933 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7446 "parser.tab.c"
    break;

  case 389:
#line 1934 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;}
#line 7452 "parser.tab.c"
    break;

  case 390:
#line 1936 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 7458 "parser.tab.c"
    break;

  case 391:
#line 1937 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7464 "parser.tab.c"
    break;

  case 392:
#line 1939 "parser.y"
                                        {(yyval.typeinfo) = createstruct();symtable*a=createscope("record");((yyval.typeinfo))->scope = a; ((yyval.typeinfo))->type = "record";string p = (yyvsp[0].str);((yyval.typeinfo))->variables.push_back(p); pushoff(); changescope(a);}
#line 7470 "parser.tab.c"
    break;

  case 393:
#line 1941 "parser.y"
                                                                                                        {goparent(); popoff(); insertmethod(((yyvsp[-2].typeinfo))->variables[0],"record",((yyvsp[-2].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7476 "parser.tab.c"
    break;

  case 394:
#line 1942 "parser.y"
                                                                                                                        {goparent();popoff();insertmethod(((yyvsp[-3].typeinfo))->variables[0],"record",((yyvsp[-3].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-3].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7482 "parser.tab.c"
    break;

  case 395:
#line 1943 "parser.y"
                                                                                                                                                        {goparent();popoff();insertmethod(((yyvsp[-3].typeinfo))->variables[0],"record",((yyvsp[-3].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-3].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7488 "parser.tab.c"
    break;

  case 396:
#line 1944 "parser.y"
                                                                                                                        {goparent();popoff();insertmethod(((yyvsp[-4].typeinfo))->variables[0],"record",((yyvsp[-4].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-4].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7494 "parser.tab.c"
    break;

  case 397:
#line 1945 "parser.y"
                                                                                                                                                        {goparent();popoff();insertmethod(((yyvsp[-2].typeinfo))->variables[0],"record",((yyvsp[-2].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-2].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7500 "parser.tab.c"
    break;

  case 398:
#line 1946 "parser.y"
                                                                                                                {goparent();popoff();insertmethod(((yyvsp[-3].typeinfo))->variables[0],"record",((yyvsp[-3].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-3].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7506 "parser.tab.c"
    break;

  case 399:
#line 1947 "parser.y"
                                                                                                                {goparent();popoff();insertmethod(((yyvsp[-3].typeinfo))->variables[0],"record",((yyvsp[-3].typeinfo))->type,((yyvsp[-1].typeinfo))->type_variable,((yyvsp[-3].typeinfo))->scope,"",((yyvsp[-1].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7512 "parser.tab.c"
    break;

  case 400:
#line 1948 "parser.y"
                                                                                                                        {goparent();popoff();insertmethod(((yyvsp[-4].typeinfo))->variables[0],"record",((yyvsp[-4].typeinfo))->type,((yyvsp[-2].typeinfo))->type_variable,((yyvsp[-4].typeinfo))->scope,"",((yyvsp[-2].typeinfo))->linep);(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7518 "parser.tab.c"
    break;

  case 401:
#line 1951 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back("void");((yyval.typeinfo))->linep = line;(yyval.typeinfo)->tac=emptyvector();}
#line 7524 "parser.tab.c"
    break;

  case 402:
#line 1952 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[-1].typeinfo))->type_variable;((yyval.typeinfo))->linep = line;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7530 "parser.tab.c"
    break;

  case 403:
#line 1954 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7536 "parser.tab.c"
    break;

  case 404:
#line 1955 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();vector<string>a=((yyvsp[-1].typeinfo))->type_variable;vector<string>b=((yyvsp[0].typeinfo))->type_variable;for(auto z:a){((yyval.typeinfo))->type_variable.push_back(z);}for(auto z:b){((yyval.typeinfo))->type_variable.push_back(z);}(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7542 "parser.tab.c"
    break;

  case 405:
#line 1957 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-1].typeinfo))->type);}
#line 7548 "parser.tab.c"
    break;

  case 406:
#line 1958 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable = ((yyvsp[0].typeinfo))->type_variable;}
#line 7554 "parser.tab.c"
    break;

  case 407:
#line 1961 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type_variable.push_back(((yyvsp[-2].typeinfo))->type);(yyval.typeinfo)->tac=emptyvector();}
#line 7560 "parser.tab.c"
    break;

  case 408:
#line 1963 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 7566 "parser.tab.c"
    break;

  case 409:
#line 1964 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7572 "parser.tab.c"
    break;

  case 410:
#line 1966 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7578 "parser.tab.c"
    break;

  case 411:
#line 1967 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7584 "parser.tab.c"
    break;

  case 412:
#line 1969 "parser.y"
                                             { vector<string>tec; symtable*a=createscope("compactconstructor");string p=((yyvsp[0].str));((yyval.typeinfo))->tempname = p;insertmethod(p,"compactconstructor","auto",tec,a,"",line);pushoff();changescope(a);}
#line 7590 "parser.tab.c"
    break;

  case 413:
#line 1971 "parser.y"
                                                                                                        {goparent(); popoff(); (yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7596 "parser.tab.c"
    break;

  case 414:
#line 1972 "parser.y"
                                                                                                                                {goparent();popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7602 "parser.tab.c"
    break;

  case 415:
#line 1974 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7608 "parser.tab.c"
    break;

  case 416:
#line 1976 "parser.y"
                                                      {symtable*a=createscope("interface");string p=((yyvsp[0].str));insertclass(p,"interface","",a,line); pushoff(); changescope(a);}
#line 7614 "parser.tab.c"
    break;

  case 417:
#line 1976 "parser.y"
                                                                                                                                                                                                        {goparent();string p=((yyvsp[-2].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7620 "parser.tab.c"
    break;

  case 418:
#line 1977 "parser.y"
                                                                  {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);pushoff();changescope(a);}
#line 7626 "parser.tab.c"
    break;

  case 419:
#line 1977 "parser.y"
                                                                                                                                                                                                                {goparent();string p=((yyvsp[-3].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7632 "parser.tab.c"
    break;

  case 420:
#line 1978 "parser.y"
                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);pushoff();changescope(a);}
#line 7638 "parser.tab.c"
    break;

  case 421:
#line 1978 "parser.y"
                                                                                                                                                                                                                {goparent();string p=((yyvsp[-3].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7644 "parser.tab.c"
    break;

  case 422:
#line 1979 "parser.y"
                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);pushoff();changescope(a);}
#line 7650 "parser.tab.c"
    break;

  case 423:
#line 1979 "parser.y"
                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7656 "parser.tab.c"
    break;

  case 424:
#line 1980 "parser.y"
                                                                {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);pushoff();changescope(a);}
#line 7662 "parser.tab.c"
    break;

  case 425:
#line 1980 "parser.y"
                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-3].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7668 "parser.tab.c"
    break;

  case 426:
#line 1981 "parser.y"
                                                                                {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);pushoff();changescope(a);}
#line 7674 "parser.tab.c"
    break;

  case 427:
#line 1981 "parser.y"
                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7680 "parser.tab.c"
    break;

  case 428:
#line 1982 "parser.y"
                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);pushoff();changescope(a);}
#line 7686 "parser.tab.c"
    break;

  case 429:
#line 1982 "parser.y"
                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7692 "parser.tab.c"
    break;

  case 430:
#line 1983 "parser.y"
                                                                                                  {symtable*a=createscope("interface");string p=((yyvsp[-3].str));insertclass(p,"interface","",a,line);pushoff();changescope(a);}
#line 7698 "parser.tab.c"
    break;

  case 431:
#line 1983 "parser.y"
                                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-5].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7704 "parser.tab.c"
    break;

  case 432:
#line 1984 "parser.y"
                                                                {symtable*a=createscope("interface");string p=((yyvsp[0].str));insertclass(p,"interface","",a,line);pushoff();changescope(a);}
#line 7710 "parser.tab.c"
    break;

  case 433:
#line 1984 "parser.y"
                                                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-2].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7716 "parser.tab.c"
    break;

  case 434:
#line 1985 "parser.y"
                                                                                  {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);pushoff();changescope(a);}
#line 7722 "parser.tab.c"
    break;

  case 435:
#line 1985 "parser.y"
                                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-3].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7728 "parser.tab.c"
    break;

  case 436:
#line 1986 "parser.y"
                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);pushoff();changescope(a);}
#line 7734 "parser.tab.c"
    break;

  case 437:
#line 1986 "parser.y"
                                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-3].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7740 "parser.tab.c"
    break;

  case 438:
#line 1987 "parser.y"
                                                                                                   {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);pushoff();changescope(a);}
#line 7746 "parser.tab.c"
    break;

  case 439:
#line 1987 "parser.y"
                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7752 "parser.tab.c"
    break;

  case 440:
#line 1988 "parser.y"
                                                                               {symtable*a=createscope("interface");string p=((yyvsp[-1].str));insertclass(p,"interface","",a,line);pushoff();changescope(a);}
#line 7758 "parser.tab.c"
    break;

  case 441:
#line 1988 "parser.y"
                                                                                                                                                                                                                                        {goparent();string p=((yyvsp[-3].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7764 "parser.tab.c"
    break;

  case 442:
#line 1989 "parser.y"
                                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);pushoff();changescope(a);}
#line 7770 "parser.tab.c"
    break;

  case 443:
#line 1989 "parser.y"
                                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7776 "parser.tab.c"
    break;

  case 444:
#line 1990 "parser.y"
                                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-2].str));insertclass(p,"interface","",a,line);pushoff();changescope(a);}
#line 7782 "parser.tab.c"
    break;

  case 445:
#line 1990 "parser.y"
                                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-4].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7788 "parser.tab.c"
    break;

  case 446:
#line 1991 "parser.y"
                                                                                                                 {symtable*a=createscope("interface");string p=((yyvsp[-3].str));insertclass(p,"interface","",a,line);pushoff();changescope(a);}
#line 7794 "parser.tab.c"
    break;

  case 447:
#line 1991 "parser.y"
                                                                                                                                                                                                                                                                {goparent();string p=((yyvsp[-5].str));addclasssize(p,offs.top().second);popoff();(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7800 "parser.tab.c"
    break;

  case 448:
#line 1994 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7806 "parser.tab.c"
    break;

  case 449:
#line 1996 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7812 "parser.tab.c"
    break;

  case 450:
#line 1998 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7818 "parser.tab.c"
    break;

  case 451:
#line 1999 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 7824 "parser.tab.c"
    break;

  case 452:
#line 2001 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 7830 "parser.tab.c"
    break;

  case 453:
#line 2002 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 7836 "parser.tab.c"
    break;

  case 454:
#line 2004 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7842 "parser.tab.c"
    break;

  case 455:
#line 2005 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7848 "parser.tab.c"
    break;

  case 456:
#line 2006 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7854 "parser.tab.c"
    break;

  case 457:
#line 2007 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 7860 "parser.tab.c"
    break;

  case 458:
#line 2008 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo;(yyval.typeinfo)->tac=emptyvector();}
#line 7866 "parser.tab.c"
    break;

  case 459:
#line 2010 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-1].typeinfo);(yyval.typeinfo)->dectype=(yyvsp[-2].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[-2].typeinfo)->decorder1;((yyval.typeinfo))->variables=((yyvsp[-1].typeinfo))->variables;(yyval.typeinfo)->decorders2=(yyvsp[-1].typeinfo)->decorders2;(yyval.typeinfo)->arrtypes=(yyvsp[-1].typeinfo)->arrtypes;(yyval.typeinfo)->arrdims=(yyvsp[-1].typeinfo)->arrdims;(yyval.typeinfo)->initvartypes=(yyvsp[-1].typeinfo)->initvartypes;((yyval.typeinfo))->puvariables=((yyvsp[-1].typeinfo))->puvariables;
 int n=((yyval.typeinfo))->variables.size();
    for(int i=0;i<n;i++){
        int order=(yyval.typeinfo)->decorder1+((yyval.typeinfo)->decorders2)[i];
        string x;
        if(order)
        x="array";
        else
        x="identifier";

        if(((yyval.typeinfo)->initialdecls)[i]){
            // cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
            insertidentifier((yyval.typeinfo)->variables[i],x,(yyval.typeinfo)->dectype,"",0,order,(yyval.typeinfo)->arrdims[i],offs.top().second);
						if(x=="identifier"){
							incoff((yyval.typeinfo)->dectype,false);
						}
						else{
							incoff((yyval.typeinfo)->dectype,false,(yyval.typeinfo)->arrdims[i]);
						}
        }
        else{
            vector<int>p(order,0);
            // cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
            insertidentifier((yyval.typeinfo)->variables[i],x,(yyval.typeinfo)->dectype,"",0,order,p,offs.top().second);
						if(x=="identifier"){
							incoff((yyval.typeinfo)->dectype,false);
						}
						else{
							incoff((yyval.typeinfo)->dectype,false,p);
						}
        }
    }
		vector<string> s = pushlocal(((yyvsp[-1].typeinfo))->puvariables);
    // $$->tac=concvector(s,$2->tac);
		// $$->temporarystore = $2->temporarystore;
		int sub = 0;
		for(auto l:((yyval.typeinfo)->variables)){
			if(lookup(l)){
				if(lookup(l)->type == "array"){
					vector<int> arrd = lookup(l)->arrdims;
					int mul = 8;
					for(auto cu:arrd){
						mul = mul*cu;
					}
					sub = sub+ mul;
				}
				else{
					sub = sub + 8;
				}
			}
		}
		// printte($$->temporarystore);
		// printte($$->variables);
		// cout<<"subq  $"<<sub<<", %rsp";
		string subq = "_xv86 subq  $"+to_string(sub)+", %rsp";
		(yyval.typeinfo)->tac=concvector(subq,s,(yyvsp[-1].typeinfo)->tac);
		(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;
	}
#line 7929 "parser.tab.c"
    break;

  case 460:
#line 2068 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-1].typeinfo);(yyval.typeinfo)->dectype=(yyvsp[-2].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[-2].typeinfo)->decorder1;((yyval.typeinfo))->variables=((yyvsp[-1].typeinfo))->variables;(yyval.typeinfo)->decorders2=(yyvsp[-1].typeinfo)->decorders2;(yyval.typeinfo)->arrtypes=(yyvsp[-1].typeinfo)->arrtypes;(yyval.typeinfo)->arrdims=(yyvsp[-1].typeinfo)->arrdims;(yyval.typeinfo)->initvartypes=(yyvsp[-1].typeinfo)->initvartypes;((yyval.typeinfo))->puvariables=((yyvsp[-1].typeinfo))->puvariables;
 	int n=((yyval.typeinfo))->variables.size();
    for(int i=0;i<n;i++){
        int order=(yyval.typeinfo)->decorder1+((yyval.typeinfo)->decorders2)[i];
        string x;
        if(order)
        x="array";
        else
        x="identifier";

        if(((yyval.typeinfo)->initialdecls)[i]){
            // cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
            insertidentifier((yyval.typeinfo)->variables[i],x,(yyval.typeinfo)->dectype,"",0,order,(yyval.typeinfo)->arrdims[i],offs.top().second);
						if(x=="identifier"){
							incoff((yyval.typeinfo)->dectype,false);
						}
						else{
							incoff((yyval.typeinfo)->dectype,false,(yyval.typeinfo)->arrdims[i]);
						}
        }
        else{
            vector<int>p(order,0);
            // cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
            insertidentifier((yyval.typeinfo)->variables[i],x,(yyval.typeinfo)->dectype,"",0,order,p,offs.top().second);
						if(x=="identifier"){
							incoff((yyval.typeinfo)->dectype,false);
						}
						else{
							incoff((yyval.typeinfo)->dectype,false,p);
						}
        }
    }
		vector<string> s = pushlocal(((yyvsp[-1].typeinfo))->puvariables);
    // $$->tac=concvector(s,$3->tac);
		// $$->temporarystore = $3->temporarystore;
		int sub = 0;
		for(auto l:((yyval.typeinfo)->variables)){
			if(lookup(l)){
				if(lookup(l)->type == "array"){
					vector<int> arrd = lookup(l)->arrdims;
					int mul = 8;
					for(auto cu:arrd){
						mul = mul*cu;
					}
					sub = sub+ mul;
				}
				else{
					sub = sub + 8;
				}
			}
		}
		// printte($$->temporarystore);
		// printte($$->variables);
		// cout<<"subq  $"<<sub<<", %rsp";
		string subq = "_xv86 subq  $"+to_string(sub)+", %rsp";
		(yyval.typeinfo)->tac=concvector(subq,s,(yyvsp[-1].typeinfo)->tac);
		(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;
	}
#line 7992 "parser.tab.c"
    break;

  case 461:
#line 2127 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-1].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="function end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z,sv,p);}
#line 7998 "parser.tab.c"
    break;

  case 462:
#line 2128 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo;string f = ((yyvsp[-1].typeinfo))->tempname;string p=gotomethodretlabel(f); string z="function end"; stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st); 	currmethod.pop(); currmethodlocals.pop(); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,z,sv,p);}
#line 8004 "parser.tab.c"
    break;

  case 463:
#line 2130 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "[]";(yyval.typeinfo)->tac=emptyvector();}
#line 8010 "parser.tab.c"
    break;

  case 464:
#line 2131 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "[]";(yyval.typeinfo)->tac=emptyvector();}
#line 8016 "parser.tab.c"
    break;

  case 465:
#line 2132 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type =  ((yyvsp[-1].typeinfo))->type + "[]";(yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 8022 "parser.tab.c"
    break;

  case 466:
#line 2137 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type =  ((yyvsp[0].typeinfo))->type ;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8028 "parser.tab.c"
    break;

  case 467:
#line 2138 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type =  ((yyvsp[-2].typeinfo))->type; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8034 "parser.tab.c"
    break;

  case 468:
#line 2140 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo;vector<string>p={}; (yyval.typeinfo)->tac=p;}
#line 8040 "parser.tab.c"
    break;

  case 469:
#line 2141 "parser.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[-1].typeinfo)->tac;}
#line 8046 "parser.tab.c"
    break;

  case 470:
#line 2143 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8052 "parser.tab.c"
    break;

  case 471:
#line 2144 "parser.y"
                                                                                                   {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8058 "parser.tab.c"
    break;

  case 472:
#line 2146 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8064 "parser.tab.c"
    break;

  case 473:
#line 2147 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8070 "parser.tab.c"
    break;

  case 474:
#line 2148 "parser.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8076 "parser.tab.c"
    break;

  case 475:
#line 2150 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8082 "parser.tab.c"
    break;

  case 476:
#line 2151 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8088 "parser.tab.c"
    break;

  case 477:
#line 2153 "parser.y"
                                                                                        {(yyval.typeinfo)=createstruct();(yyval.typeinfo)=(yyvsp[-1].typeinfo);
	
    (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;
}
#line 8097 "parser.tab.c"
    break;

  case 478:
#line 2158 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo); (yyval.typeinfo)->dectype=(yyvsp[-1].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[-1].typeinfo)->decorder1;((yyval.typeinfo))->variables=((yyvsp[0].typeinfo))->variables;(yyval.typeinfo)->decorders2=(yyvsp[0].typeinfo)->decorders2;(yyval.typeinfo)->arrtypes=(yyvsp[0].typeinfo)->arrtypes;(yyval.typeinfo)->arrdims=(yyvsp[0].typeinfo)->arrdims;(yyval.typeinfo)->initvartypes=(yyvsp[0].typeinfo)->initvartypes;((yyval.typeinfo))->puvariables=((yyvsp[0].typeinfo))->puvariables;
 int n=((yyval.typeinfo))->variables.size();
    for(int i=0;i<n;i++){
        int order=(yyval.typeinfo)->decorder1+((yyval.typeinfo)->decorders2)[i];
        string x;
        if(order)
        x="array";
        else
        x="identifier";

        if(((yyval.typeinfo)->initialdecls)[i]){
            // cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
            insertidentifier((yyval.typeinfo)->variables[i],x,(yyval.typeinfo)->dectype,"",0,order,(yyval.typeinfo)->arrdims[i],offs.top().second);
						if(x=="identifier"){
							incoff((yyval.typeinfo)->dectype,false);
						}
						else{
							incoff((yyval.typeinfo)->dectype,false,(yyval.typeinfo)->arrdims[i]);
						}
        }
        else{
            vector<int>p(order,0);
            // cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
            insertidentifier((yyval.typeinfo)->variables[i],x,(yyval.typeinfo)->dectype,"",0,order,p,offs.top().second);
						if(x=="identifier"){
							incoff((yyval.typeinfo)->dectype,false);
						}
						else{
							incoff((yyval.typeinfo)->dectype,false,p);
						}
        }
    }
		vector<string> s = pushlocal(((yyvsp[0].typeinfo))->puvariables);
    // $$->tac=concvector(s,$2->tac);
		// $$->temporarystore = $2->temporarystore;
		int sub = 0;
		for(auto l:((yyval.typeinfo)->variables)){
			if(lookup(l)){
				if(lookup(l)->type == "array"){
					vector<int> arrd = lookup(l)->arrdims;
					int mul = 8;
					for(auto cu:arrd){
						mul = mul*cu;
					}
					sub = sub+ mul;
				}
				else{
					sub = sub + 8;
				}
			}
		}
		// printte($$->temporarystore);
		// printte($$->variables);
		// cout<<"subq  $"<<sub<<", %rsp";
		string subq = "_xv86 subq  $"+to_string(sub)+", %rsp";
		(yyval.typeinfo)->tac=concvector(subq,s,(yyvsp[0].typeinfo)->tac);
		(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;
		}
#line 8160 "parser.tab.c"
    break;

  case 479:
#line 2216 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->dectype=(yyvsp[-1].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[-1].typeinfo)->decorder1;((yyval.typeinfo))->variables=((yyvsp[0].typeinfo))->variables;(yyval.typeinfo)->decorders2=(yyvsp[0].typeinfo)->decorders2;(yyval.typeinfo)->arrtypes=(yyvsp[0].typeinfo)->arrtypes;(yyval.typeinfo)->arrdims=(yyvsp[0].typeinfo)->arrdims;(yyval.typeinfo)->initvartypes=(yyvsp[0].typeinfo)->initvartypes; ((yyval.typeinfo))->puvariables=((yyvsp[0].typeinfo))->puvariables;
        int n=((yyval.typeinfo))->variables.size();
    for(int i=0;i<n;i++){
        int order=(yyval.typeinfo)->decorder1+((yyval.typeinfo)->decorders2)[i];
        string x;
        if(order)
        x="array";
        else
        x="identifier";

        if(((yyval.typeinfo)->initialdecls)[i]){
            // cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
            insertidentifier((yyval.typeinfo)->variables[i],x,(yyval.typeinfo)->dectype,"",0,order,(yyval.typeinfo)->arrdims[i],offs.top().second);
						if(x=="identifier"){
							incoff((yyval.typeinfo)->dectype,false);
						}
						else{
							incoff((yyval.typeinfo)->dectype,false,(yyval.typeinfo)->arrdims[i]);
						}
        }
        else{
            vector<int>p(order,0);
            // cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
            insertidentifier((yyval.typeinfo)->variables[i],x,(yyval.typeinfo)->dectype,"",0,order,p,offs.top().second);
						if(x=="identifier"){
							incoff((yyval.typeinfo)->dectype,false);

						}
						else{
							incoff((yyval.typeinfo)->dectype,false,p);
						}
        }
    }
		vector<string> s = pushlocal(((yyvsp[0].typeinfo))->puvariables);
    //  $$->tac=concvector(s,$3->tac);
		//  $$->temporarystore = $3->temporarystore;
		 int sub = 0;
		for(auto l:((yyval.typeinfo)->variables)){
			if(lookup(l)){
				if(lookup(l)->type == "array"){
					vector<int> arrd = lookup(l)->arrdims;
					int mul = 8;
					for(auto cu:arrd){
						mul = mul*cu;
					}
					sub = sub+ mul;
				}
				else{
					sub = sub + 8;
				}
			}
		}
		// printte($$->temporarystore);
		// printte($$->variables);
		// cout<<"subq  $"<<sub<<", %rsp";
		string subq = "_xv86 subq  $"+to_string(sub)+", %rsp";
		(yyval.typeinfo)->tac=concvector(subq,s,(yyvsp[0].typeinfo)->tac);
		(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;
		 }
#line 8224 "parser.tab.c"
    break;

  case 480:
#line 2276 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;((yyval.typeinfo))->type=((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->dectype=(yyvsp[0].typeinfo)->dectype;(yyval.typeinfo)->decorder1=(yyvsp[0].typeinfo)->decorder1;}
#line 8230 "parser.tab.c"
    break;

  case 481:
#line 2277 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac= emptyvector();((yyval.typeinfo))->type="all";(yyval.typeinfo)->dectype="all";(yyval.typeinfo)->decorder1=0;}
#line 8236 "parser.tab.c"
    break;

  case 482:
#line 2279 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8242 "parser.tab.c"
    break;

  case 483:
#line 2280 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8248 "parser.tab.c"
    break;

  case 484:
#line 2281 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8254 "parser.tab.c"
    break;

  case 485:
#line 2282 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8260 "parser.tab.c"
    break;

  case 486:
#line 2283 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8266 "parser.tab.c"
    break;

  case 487:
#line 2284 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8272 "parser.tab.c"
    break;

  case 488:
#line 2285 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8278 "parser.tab.c"
    break;

  case 489:
#line 2287 "parser.y"
                                                   {(yyval.typeinfo)=new Typeinfo;string x = (yyvsp[-2].typeinfo)->tempname; string p = "print " + x; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,p);}
#line 8284 "parser.tab.c"
    break;

  case 490:
#line 2289 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8290 "parser.tab.c"
    break;

  case 491:
#line 2290 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8296 "parser.tab.c"
    break;

  case 492:
#line 2291 "parser.y"
                                                                            {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8302 "parser.tab.c"
    break;

  case 493:
#line 2292 "parser.y"
                                                                            {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8308 "parser.tab.c"
    break;

  case 494:
#line 2293 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8314 "parser.tab.c"
    break;

  case 495:
#line 2295 "parser.y"
                                        {flag = 0;}
#line 8320 "parser.tab.c"
    break;

  case 496:
#line 2295 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8326 "parser.tab.c"
    break;

  case 497:
#line 2296 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8332 "parser.tab.c"
    break;

  case 498:
#line 2297 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8338 "parser.tab.c"
    break;

  case 499:
#line 2298 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8344 "parser.tab.c"
    break;

  case 500:
#line 2299 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8350 "parser.tab.c"
    break;

  case 501:
#line 2300 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8356 "parser.tab.c"
    break;

  case 502:
#line 2301 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8362 "parser.tab.c"
    break;

  case 503:
#line 2302 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8368 "parser.tab.c"
    break;

  case 504:
#line 2303 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8374 "parser.tab.c"
    break;

  case 505:
#line 2304 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8380 "parser.tab.c"
    break;

  case 506:
#line 2305 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8386 "parser.tab.c"
    break;

  case 507:
#line 2306 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8392 "parser.tab.c"
    break;

  case 508:
#line 2307 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8398 "parser.tab.c"
    break;

  case 509:
#line 2309 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; vector<string>p={}; (yyval.typeinfo)->tac=p;}
#line 8404 "parser.tab.c"
    break;

  case 510:
#line 2311 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8410 "parser.tab.c"
    break;

  case 511:
#line 2313 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8416 "parser.tab.c"
    break;

  case 512:
#line 2316 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[-1].typeinfo)->tempname;}
#line 8422 "parser.tab.c"
    break;

  case 513:
#line 2318 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 8428 "parser.tab.c"
    break;

  case 514:
#line 2319 "parser.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 8434 "parser.tab.c"
    break;

  case 515:
#line 2320 "parser.y"
                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 8440 "parser.tab.c"
    break;

  case 516:
#line 2321 "parser.y"
                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 8446 "parser.tab.c"
    break;

  case 517:
#line 2322 "parser.y"
                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 8452 "parser.tab.c"
    break;

  case 518:
#line 2323 "parser.y"
                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 8458 "parser.tab.c"
    break;

  case 519:
#line 2324 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->tempname=(yyvsp[0].typeinfo)->tempname;}
#line 8464 "parser.tab.c"
    break;

  case 520:
#line 2326 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo;int lv=labelvariable;string a=newlabel();string ret="if zero "+((yyvsp[-2].typeinfo))->tempname+gotoo(lv+1);(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,a);}
#line 8470 "parser.tab.c"
    break;

  case 521:
#line 2328 "parser.y"
                                                                              {(yyval.typeinfo)=new Typeinfo;int lv=labelvariable;string a=newlabel();string b=newlabel();string ret="if zero "+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+1);string ret2=gotoo(lv+2);(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,ret,(yyvsp[-2].typeinfo)->tac,ret2,a,(yyvsp[0].typeinfo)->tac,b);}
#line 8476 "parser.tab.c"
    break;

  case 522:
#line 2330 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo;int lv=labelvariable;string a=newlabel();string b=newlabel();string ret="if zero "+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+1);string ret2=gotoo(lv+2);(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,ret,(yyvsp[-2].typeinfo)->tac,ret2,a,(yyvsp[0].typeinfo)->tac,b);}
#line 8482 "parser.tab.c"
    break;

  case 523:
#line 2332 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 8488 "parser.tab.c"
    break;

  case 524:
#line 2333 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 8494 "parser.tab.c"
    break;

  case 525:
#line 2335 "parser.y"
                                                   {symtable *a = createscope("switch"); changescope(a);}
#line 8500 "parser.tab.c"
    break;

  case 526:
#line 2335 "parser.y"
                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8506 "parser.tab.c"
    break;

  case 527:
#line 2337 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 8512 "parser.tab.c"
    break;

  case 528:
#line 2338 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 8518 "parser.tab.c"
    break;

  case 529:
#line 2339 "parser.y"
                                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8524 "parser.tab.c"
    break;

  case 530:
#line 2340 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 8530 "parser.tab.c"
    break;

  case 531:
#line 2341 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 8536 "parser.tab.c"
    break;

  case 532:
#line 2342 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 8542 "parser.tab.c"
    break;

  case 533:
#line 2344 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);}
#line 8548 "parser.tab.c"
    break;

  case 534:
#line 2345 "parser.y"
                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8554 "parser.tab.c"
    break;

  case 535:
#line 2346 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8560 "parser.tab.c"
    break;

  case 536:
#line 2348 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8566 "parser.tab.c"
    break;

  case 537:
#line 2349 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8572 "parser.tab.c"
    break;

  case 538:
#line 2351 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8578 "parser.tab.c"
    break;

  case 539:
#line 2352 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8584 "parser.tab.c"
    break;

  case 540:
#line 2353 "parser.y"
                                                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8590 "parser.tab.c"
    break;

  case 541:
#line 2355 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8596 "parser.tab.c"
    break;

  case 542:
#line 2357 "parser.y"
                 {symtable*a=createscope("while");insertclass("while","while","",a,line); changescope(a);}
#line 8602 "parser.tab.c"
    break;

  case 543:
#line 2359 "parser.y"
                                                                                                {goparent(); (yyval.typeinfo)=new Typeinfo; int c=labelvariable; string a=newlabel();string b=newlabel();string z=gotoo(c+2);string d="if zero "+(((yyvsp[-2].typeinfo))->tempname)+z;(yyval.typeinfo)->tac=concvector(a,(yyvsp[-2].typeinfo)->tac,d,(yyvsp[0].typeinfo)->tac,gotoo(c+1),b);}
#line 8608 "parser.tab.c"
    break;

  case 544:
#line 2361 "parser.y"
                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int c=labelvariable; string a=newlabel();string z=gotoo(c+2);string b=newlabel();string d="if zero "+(((yyvsp[-2].typeinfo))->tempname)+z;(yyval.typeinfo)->tac=concvector(a,(yyvsp[-2].typeinfo)->tac,d,(yyvsp[0].typeinfo)->tac,gotoo(c+1),b);}
#line 8614 "parser.tab.c"
    break;

  case 545:
#line 2363 "parser.y"
                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable;string l1=newlabel();string l2=newlabel();string p=gotoo(lv+1);string z="if nonzero "+(yyvsp[-2].typeinfo)->tempname+" "+p;(yyval.typeinfo)->tac=concvector(l1,(yyvsp[-5].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,z,l2);}
#line 8620 "parser.tab.c"
    break;

  case 546:
#line 2365 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8626 "parser.tab.c"
    break;

  case 547:
#line 2366 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8632 "parser.tab.c"
    break;

  case 548:
#line 2368 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8638 "parser.tab.c"
    break;

  case 549:
#line 2369 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac= (yyvsp[0].typeinfo)->tac;}
#line 8644 "parser.tab.c"
    break;

  case 550:
#line 2371 "parser.y"
                {symtable*a=createscope("for");insertclass("for","for","",a,line); changescope(a);}
#line 8650 "parser.tab.c"
    break;

  case 551:
#line 2373 "parser.y"
                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector(a,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 8656 "parser.tab.c"
    break;

  case 552:
#line 2374 "parser.y"
                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector(a,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 8662 "parser.tab.c"
    break;

  case 553:
#line 2375 "parser.y"
                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero "+((yyvsp[-3].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-3].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);(yyval.typeinfo)->temporarystore = (yyvsp[-3].typeinfo)->temporarystore;}
#line 8668 "parser.tab.c"
    break;

  case 554:
#line 2376 "parser.y"
                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero "+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-4].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);(yyval.typeinfo)->temporarystore = (yyvsp[-4].typeinfo)->temporarystore;}
#line 8674 "parser.tab.c"
    break;

  case 555:
#line 2377 "parser.y"
                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 8680 "parser.tab.c"
    break;

  case 556:
#line 2378 "parser.y"
                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 8686 "parser.tab.c"
    break;

  case 557:
#line 2379 "parser.y"
                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero "+((yyvsp[-3].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,a,(yyvsp[-3].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);(yyval.typeinfo)->temporarystore = (yyvsp[-3].typeinfo)->temporarystore;}
#line 8692 "parser.tab.c"
    break;

  case 558:
#line 2380 "parser.y"
                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero "+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector((yyvsp[-6].typeinfo)->tac,a,(yyvsp[-4].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);(yyval.typeinfo)->temporarystore = (yyvsp[-4].typeinfo)->temporarystore;}
#line 8698 "parser.tab.c"
    break;

  case 559:
#line 2382 "parser.y"
                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector(a,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 8704 "parser.tab.c"
    break;

  case 560:
#line 2383 "parser.y"
                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector(a,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 8710 "parser.tab.c"
    break;

  case 561:
#line 2384 "parser.y"
                                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero "+((yyvsp[-3].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-3].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);(yyval.typeinfo)->temporarystore = (yyvsp[-3].typeinfo)->temporarystore;}
#line 8716 "parser.tab.c"
    break;

  case 562:
#line 2385 "parser.y"
                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero "+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-4].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);(yyval.typeinfo)->temporarystore = (yyvsp[-4].typeinfo)->temporarystore;}
#line 8722 "parser.tab.c"
    break;

  case 563:
#line 2386 "parser.y"
                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);}
#line 8728 "parser.tab.c"
    break;

  case 564:
#line 2387 "parser.y"
                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();(yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);}
#line 8734 "parser.tab.c"
    break;

  case 565:
#line 2388 "parser.y"
                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero "+((yyvsp[-3].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,a,(yyvsp[-3].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);(yyval.typeinfo)->temporarystore = (yyvsp[-3].typeinfo)->temporarystore;}
#line 8740 "parser.tab.c"
    break;

  case 566:
#line 2389 "parser.y"
                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero "+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector((yyvsp[-6].typeinfo)->tac,a,(yyvsp[-4].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,gotoo(lv+1),b);(yyval.typeinfo)->temporarystore = (yyvsp[-4].typeinfo)->temporarystore;}
#line 8746 "parser.tab.c"
    break;

  case 567:
#line 2391 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8752 "parser.tab.c"
    break;

  case 568:
#line 2392 "parser.y"
                                                                        {vector<string> a = ((yyvsp[0].typeinfo))->variables; (yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8758 "parser.tab.c"
    break;

  case 569:
#line 2394 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8764 "parser.tab.c"
    break;

  case 570:
#line 2396 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8770 "parser.tab.c"
    break;

  case 571:
#line 2397 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8776 "parser.tab.c"
    break;

  case 572:
#line 2399 "parser.y"
                                                             {vector<string> a = ((yyvsp[0].typeinfo))->variables; (yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8782 "parser.tab.c"
    break;

  case 573:
#line 2401 "parser.y"
                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero "+((yyvsp[-2].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-4].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);(yyval.typeinfo)->temporarystore = (yyvsp[-2].typeinfo)->temporarystore;}
#line 8788 "parser.tab.c"
    break;

  case 574:
#line 2403 "parser.y"
                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero "+((yyvsp[-2].typeinfo))->tempname+gotoo(lv+2);(yyval.typeinfo)->tac=concvector(a,(yyvsp[-4].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,ret,(yyvsp[0].typeinfo)->tac,gotoo(lv+1),b);(yyval.typeinfo)->temporarystore = (yyvsp[-2].typeinfo)->temporarystore;}
#line 8794 "parser.tab.c"
    break;

  case 575:
#line 2405 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;string p=gotoo(labelvariable+1); (yyval.typeinfo)->tac={p};}
#line 8800 "parser.tab.c"
    break;

  case 576:
#line 2406 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;string p=gotoo(labelvariable+1); (yyval.typeinfo)->tac={p};}
#line 8806 "parser.tab.c"
    break;

  case 577:
#line 2409 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;}
#line 8812 "parser.tab.c"
    break;

  case 578:
#line 2411 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo;string p=gotoo(labelvariable); (yyval.typeinfo)->tac={p};}
#line 8818 "parser.tab.c"
    break;

  case 579:
#line 2412 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo;string p=gotoo(labelvariable); (yyval.typeinfo)->tac={p};}
#line 8824 "parser.tab.c"
    break;

  case 580:
#line 2415 "parser.y"
                                                        {(yyval.typeinfo)=new Typeinfo;string p=gotomethodretlabel(currmethod.top()); (yyval.typeinfo)->tac={p};}
#line 8830 "parser.tab.c"
    break;

  case 581:
#line 2416 "parser.y"
                                             {(yyval.typeinfo)=new Typeinfo;string p=gotomethodretlabel(currmethod.top());string s = "%rax = " + (yyvsp[-1].typeinfo)->tempname; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,s,p);(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;}
#line 8836 "parser.tab.c"
    break;

  case 582:
#line 2418 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;}
#line 8842 "parser.tab.c"
    break;

  case 583:
#line 2420 "parser.y"
                                                         {symtable*a=createscope("synchronized"); changescope(a);}
#line 8848 "parser.tab.c"
    break;

  case 584:
#line 2420 "parser.y"
                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);(yyval.typeinfo)->temporarystore = (yyvsp[-3].typeinfo)->temporarystore;}
#line 8854 "parser.tab.c"
    break;

  case 585:
#line 2422 "parser.y"
            {symtable*a=createscope("try"); changescope(a);}
#line 8860 "parser.tab.c"
    break;

  case 586:
#line 2424 "parser.y"
                        {goparent();(yyval.typeinfo)=createstruct(); (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8866 "parser.tab.c"
    break;

  case 587:
#line 2426 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8872 "parser.tab.c"
    break;

  case 588:
#line 2427 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8878 "parser.tab.c"
    break;

  case 589:
#line 2428 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8884 "parser.tab.c"
    break;

  case 590:
#line 2429 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8890 "parser.tab.c"
    break;

  case 591:
#line 2431 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8896 "parser.tab.c"
    break;

  case 592:
#line 2432 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8902 "parser.tab.c"
    break;

  case 593:
#line 2434 "parser.y"
                       {symtable*a=createscope("catch"); changescope(a);}
#line 8908 "parser.tab.c"
    break;

  case 594:
#line 2434 "parser.y"
                                                                                                                {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8914 "parser.tab.c"
    break;

  case 595:
#line 2436 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8920 "parser.tab.c"
    break;

  case 596:
#line 2437 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8926 "parser.tab.c"
    break;

  case 597:
#line 2439 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 8932 "parser.tab.c"
    break;

  case 598:
#line 2440 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8938 "parser.tab.c"
    break;

  case 599:
#line 2443 "parser.y"
                         {symtable*a=createscope("finally"); changescope(a);}
#line 8944 "parser.tab.c"
    break;

  case 600:
#line 2443 "parser.y"
                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8950 "parser.tab.c"
    break;

  case 601:
#line 2445 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8956 "parser.tab.c"
    break;

  case 602:
#line 2446 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8962 "parser.tab.c"
    break;

  case 603:
#line 2447 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8968 "parser.tab.c"
    break;

  case 604:
#line 2448 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-2].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);}
#line 8974 "parser.tab.c"
    break;

  case 605:
#line 2450 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;}
#line 8980 "parser.tab.c"
    break;

  case 606:
#line 2452 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8986 "parser.tab.c"
    break;

  case 607:
#line 2453 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8992 "parser.tab.c"
    break;

  case 608:
#line 2455 "parser.y"
                                                                                                    {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 8998 "parser.tab.c"
    break;

  case 609:
#line 2456 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 9004 "parser.tab.c"
    break;

  case 610:
#line 2458 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;vector<int>q;(yyval.typeinfo)->arrdim=q;(yyval.typeinfo)->arrtype="";(yyval.typeinfo)->initvartype=(yyvsp[0].typeinfo)->initvartype;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9010 "parser.tab.c"
    break;

  case 611:
#line 2459 "parser.y"
                                                                                                                                {(yyval.typeinfo)=createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->initvartype="";(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9016 "parser.tab.c"
    break;

  case 612:
#line 2461 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;(yyval.typeinfo)->initvartype=(yyvsp[0].typeinfo)->type;((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9022 "parser.tab.c"
    break;

  case 613:
#line 2462 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 9028 "parser.tab.c"
    break;

  case 614:
#line 2463 "parser.y"
                                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();(yyval.typeinfo)->tempname="this";}
#line 9034 "parser.tab.c"
    break;

  case 615:
#line 2464 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class";string x=(yyvsp[-2].str); (yyval.typeinfo)->tac=emptyvector();(yyval.typeinfo)->tempname=x;}
#line 9040 "parser.tab.c"
    break;

  case 616:
#line 2465 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-2].typeinfo);((yyval.typeinfo))->type = "class";}
#line 9046 "parser.tab.c"
    break;

  case 617:
#line 2466 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-1].typeinfo);((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;}
#line 9052 "parser.tab.c"
    break;

  case 618:
#line 2467 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 9058 "parser.tab.c"
    break;

  case 619:
#line 2468 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = "look";}
#line 9064 "parser.tab.c"
    break;

  case 620:
#line 2469 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string y=((yyvsp[0].typeinfo))->arrname+"["+((yyvsp[0].typeinfo))->tempname+"]"; (yyval.typeinfo)->tempname=y;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9070 "parser.tab.c"
    break;

  case 621:
#line 2470 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;}
#line 9076 "parser.tab.c"
    break;

  case 622:
#line 2471 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = "look";}
#line 9082 "parser.tab.c"
    break;

  case 623:
#line 2473 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();}
#line 9088 "parser.tab.c"
    break;

  case 624:
#line 2474 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();}
#line 9094 "parser.tab.c"
    break;

  case 625:
#line 2475 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();}
#line 9100 "parser.tab.c"
    break;

  case 626:
#line 2476 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();}
#line 9106 "parser.tab.c"
    break;

  case 627:
#line 2477 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();}
#line 9112 "parser.tab.c"
    break;

  case 628:
#line 2478 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "class"; (yyval.typeinfo)->tac=emptyvector();}
#line 9118 "parser.tab.c"
    break;

  case 629:
#line 2480 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 9124 "parser.tab.c"
    break;

  case 630:
#line 2481 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 9130 "parser.tab.c"
    break;

  case 631:
#line 2482 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 9136 "parser.tab.c"
    break;

  case 632:
#line 2483 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 9142 "parser.tab.c"
    break;

  case 633:
#line 2487 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->dectype = ((yyvsp[-2].typeinfo))->type ;vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters();string s = ((yyvsp[-2].typeinfo))->tempname;((yyval.typeinfo))->tempname = "%rax";string s1 = gotomethod(s,0);string s2 = newmethodretlabel(s); (yyval.typeinfo)->tac=concvector(pv1,s1,(yyvsp[-2].typeinfo)->tac,s2,pv2);}
#line 9148 "parser.tab.c"
    break;

  case 634:
#line 2488 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->dectype = ((yyvsp[-3].typeinfo))->type ;vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters();string s = ((yyvsp[-3].typeinfo))->tempname;((yyval.typeinfo))->tempname = "%rax";string s1 = gotomethod(s,0);string s2 = newmethodretlabel(s); (yyval.typeinfo)->tac=concvector(pv1,s1,(yyvsp[-3].typeinfo)->tac,s2,pv2);}
#line 9154 "parser.tab.c"
    break;

  case 635:
#line 2489 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->dectype = ((yyvsp[-3].typeinfo))->type ; vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters(); string s = ((yyvsp[-3].typeinfo))->tempname;((yyval.typeinfo))->tempname = "%rax"; string s1 = gotomethod(s,(yyvsp[-1].typeinfo)->params.size());string s2 = newmethodretlabel(s);vector<string> pushpar = pusharg(((yyvsp[-1].typeinfo))->params);(yyval.typeinfo)->tac=concvector(pv1,(yyvsp[-1].typeinfo)->tac,pushpar,s1,(yyvsp[-3].typeinfo)->tac,s2,pv2);(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;}
#line 9160 "parser.tab.c"
    break;

  case 636:
#line 2490 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->dectype = ((yyvsp[-4].typeinfo))->type ; vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters(); string s = ((yyvsp[-4].typeinfo))->tempname;((yyval.typeinfo))->tempname = "%rax"; string s1 = gotomethod(s,(yyvsp[-2].typeinfo)->params.size());string s2 = newmethodretlabel(s);vector<string> pushpar = pusharg(((yyvsp[-2].typeinfo))->params);(yyval.typeinfo)->tac=concvector(pv1,(yyvsp[-2].typeinfo)->tac,pushpar,s1,(yyvsp[-4].typeinfo)->tac,s2,pv2);(yyval.typeinfo)->temporarystore = (yyvsp[-2].typeinfo)->temporarystore;}
#line 9166 "parser.tab.c"
    break;

  case 637:
#line 2492 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();string p = (yyvsp[0].str);((yyval.typeinfo))->type =  p;(yyval.typeinfo)->tempname = p; (yyval.typeinfo)->tac=emptyvector();}
#line 9172 "parser.tab.c"
    break;

  case 638:
#line 2493 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=emptyvector();string p = (yyvsp[-1].str);((yyval.typeinfo))->type =  p + ((yyvsp[0].typeinfo))->name;(yyval.typeinfo)->tempname = p;}
#line 9178 "parser.tab.c"
    break;

  case 639:
#line 2495 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 9184 "parser.tab.c"
    break;

  case 640:
#line 2496 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=emptyvector();}
#line 9190 "parser.tab.c"
    break;

  case 641:
#line 2497 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->tac=emptyvector();}
#line 9196 "parser.tab.c"
    break;

  case 642:
#line 2498 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 9202 "parser.tab.c"
    break;

  case 643:
#line 2500 "parser.y"
                                                                {(yyval.typeinfo)=new Typeinfo;string yy=(yyvsp[-3].str); symentry* entry=lookup(yy); vector<int>v=entry->arrdims;string x=entry->primtype; vector<int>f; for(int 	i=1;i<v.size();i++)f.push_back(v[i]);(yyval.typeinfo)->dimsize=f;(yyval.typeinfo)->arrname=identwithoff(yy); (yyval.typeinfo)->arrtype=x;string y=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-1].typeinfo)->temporarystore,y); (yyval.typeinfo)->tempname=y;y=no + y+" = "+((yyvsp[-1].typeinfo))->tempname+" * "+to_string(tellsize(f,x)); (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,y);}
#line 9208 "parser.tab.c"
    break;

  case 644:
#line 2501 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);(yyval.typeinfo)->temporarystore = contemp((yyvsp[-3].typeinfo)->temporarystore,(yyvsp[-1].typeinfo)->temporarystore);}
#line 9214 "parser.tab.c"
    break;

  case 645:
#line 2502 "parser.y"
                                                                                {(yyval.typeinfo)=new Typeinfo; vector<int>v=((yyvsp[-3].typeinfo))->dimsize;string x=((yyvsp[-3].typeinfo))->arrtype; vector<int>f; for(int i=1;i<v.size();i++)f.push_back(v[i]);(yyval.typeinfo)->dimsize=f; (yyval.typeinfo)->arrtype=x;string y=newtemp();(yyval.typeinfo)->tempname=y;string z=newtemp();string no = "_xv86 subq $16, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-1].typeinfo)->temporarystore,z,y);y=y+" = "+((yyvsp[-1].typeinfo))->tempname+" + "+z;z=no + z+" = "+((yyvsp[-1].typeinfo))->tempname+" * "+to_string(tellsize(f,x)); (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac,z,y);(yyval.typeinfo)->arrname=(yyvsp[-3].typeinfo)->arrname;}
#line 9220 "parser.tab.c"
    break;

  case 646:
#line 2504 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();if(lookup(((yyvsp[-3].typeinfo))->name)){((yyval.typeinfo))->type =  lookup(((yyvsp[-3].typeinfo))->name)->funcrettype ;} vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters(); string s = ((yyvsp[-3].typeinfo))->tempname;((yyval.typeinfo))->tempname = "%rax"; string s1 = gotomethod(s,(yyvsp[-1].typeinfo)->params.size());string s2 = newmethodretlabel(s);vector<string> pushpar = pusharg(((yyvsp[-1].typeinfo))->params);(yyval.typeinfo)->tac=concvector(pv1,(yyvsp[-1].typeinfo)->tac,pushpar,s1,(yyvsp[-3].typeinfo)->tac,s2,pv2);(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;}
#line 9226 "parser.tab.c"
    break;

  case 647:
#line 2505 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();if(lookup(((yyvsp[-2].typeinfo))->name)){((yyval.typeinfo))->type =  lookup(((yyvsp[-2].typeinfo))->name)->funcrettype ;}vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters();string s = ((yyvsp[-2].typeinfo))->tempname;((yyval.typeinfo))->tempname = "%rax";string s1 = gotomethod(s,0);string s2 = newmethodretlabel(s); (yyval.typeinfo)->tac=concvector(pv1,s1,(yyvsp[-2].typeinfo)->tac,s2,pv2);}
#line 9232 "parser.tab.c"
    break;

  case 648:
#line 2506 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 9238 "parser.tab.c"
    break;

  case 649:
#line 2507 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;}
#line 9244 "parser.tab.c"
    break;

  case 650:
#line 2508 "parser.y"
                                                                                                            {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 9250 "parser.tab.c"
    break;

  case 651:
#line 2509 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-5].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;}
#line 9256 "parser.tab.c"
    break;

  case 652:
#line 2510 "parser.y"
                                                                                                                    {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-4].typeinfo)->tac;}
#line 9262 "parser.tab.c"
    break;

  case 653:
#line 2511 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-5].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;}
#line 9268 "parser.tab.c"
    break;

  case 654:
#line 2512 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 9274 "parser.tab.c"
    break;

  case 655:
#line 2513 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;}
#line 9280 "parser.tab.c"
    break;

  case 656:
#line 2514 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 9286 "parser.tab.c"
    break;

  case 657:
#line 2515 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;}
#line 9292 "parser.tab.c"
    break;

  case 658:
#line 2516 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-6].typeinfo)->tac;}
#line 9298 "parser.tab.c"
    break;

  case 659:
#line 2517 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-7].typeinfo)->tac,(yyvsp[-1].typeinfo)->tac);(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;}
#line 9304 "parser.tab.c"
    break;

  case 660:
#line 2520 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;string s = ((yyvsp[0].typeinfo))->tempname; (yyval.typeinfo)->params.push_back(s);(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9310 "parser.tab.c"
    break;

  case 661:
#line 2521 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);string s = ((yyvsp[-1].typeinfo))->tempname; (yyval.typeinfo)->params.push_back(s); for(auto z:((yyvsp[0].typeinfo))->params)((yyval.typeinfo))->params.push_back(z);(yyval.typeinfo)->temporarystore = contemp((yyvsp[-1].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore);}
#line 9316 "parser.tab.c"
    break;

  case 662:
#line 2523 "parser.y"
                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 9322 "parser.tab.c"
    break;

  case 664:
#line 2525 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 9328 "parser.tab.c"
    break;

  case 665:
#line 2526 "parser.y"
                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 9334 "parser.tab.c"
    break;

  case 666:
#line 2527 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 9340 "parser.tab.c"
    break;

  case 667:
#line 2528 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 9346 "parser.tab.c"
    break;

  case 669:
#line 2530 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=emptyvector();}
#line 9352 "parser.tab.c"
    break;

  case 670:
#line 2532 "parser.y"
                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)->type=(yyvsp[-1].typeinfo)->type;(yyval.typeinfo)->arrtype=(yyvsp[-1].typeinfo)->type;(yyval.typeinfo)->arrdim=(yyvsp[0].typeinfo)->arrdim; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9358 "parser.tab.c"
    break;

  case 671:
#line 2533 "parser.y"
                                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;}
#line 9364 "parser.tab.c"
    break;

  case 672:
#line 2534 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9370 "parser.tab.c"
    break;

  case 673:
#line 2535 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[-1].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;}
#line 9376 "parser.tab.c"
    break;

  case 674:
#line 2536 "parser.y"
                                                                                                                {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 9382 "parser.tab.c"
    break;

  case 675:
#line 2537 "parser.y"
                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;}
#line 9388 "parser.tab.c"
    break;

  case 676:
#line 2540 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[-1].typeinfo);(yyval.typeinfo)->exprvalue=(yyvsp[-1].typeinfo)->exprvalue;(yyval.typeinfo)->type=(yyvsp[-1].typeinfo)->type;(yyval.typeinfo)->temporarystore = (yyvsp[-1].typeinfo)->temporarystore;}
#line 9394 "parser.tab.c"
    break;

  case 677:
#line 2542 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9400 "parser.tab.c"
    break;

  case 678:
#line 2544 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9406 "parser.tab.c"
    break;

  case 679:
#line 2545 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9412 "parser.tab.c"
    break;

  case 680:
#line 2547 "parser.y"
                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string p=((yyvsp[-2].typeinfo))->tempname+" = "+((yyvsp[0].typeinfo))->tempname;(yyval.typeinfo)->tempname=((yyvsp[-2].typeinfo))->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,p);(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore);}
#line 9418 "parser.tab.c"
    break;

  case 681:
#line 2549 "parser.y"
                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9424 "parser.tab.c"
    break;

  case 682:
#line 2551 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();string p = (yyvsp[0].str);if(lookup(p)){((yyval.typeinfo))->type = lookup(p)->type;}string x=(yyvsp[0].str);(yyval.typeinfo)->tempname=identwithoff(x);(yyval.typeinfo)->tac=emptyvector();(yyval.typeinfo)->temporarystore = emptyvector();}
#line 9430 "parser.tab.c"
    break;

  case 683:
#line 2552 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9436 "parser.tab.c"
    break;

  case 684:
#line 2553 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->type=(yyvsp[0].typeinfo)->type;string y=((yyvsp[0].typeinfo))->arrname+"["+((yyvsp[0].typeinfo))->tempname+"]"; (yyval.typeinfo)->tempname=y;(yyval.typeinfo)->tac=(yyvsp[0].typeinfo)->tac;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9442 "parser.tab.c"
    break;

  case 685:
#line 2555 "parser.y"
                                                                                                {(yyval.str)=(yyvsp[0].str);}
#line 9448 "parser.tab.c"
    break;

  case 686:
#line 2557 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9454 "parser.tab.c"
    break;

  case 687:
#line 2558 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-4].typeinfo))->type;int lv=labelvariable;string a=newlabel();string ret="if zero "+((yyvsp[-4].typeinfo))->tempname+gotoo(lv+1);(yyval.typeinfo)->tac=concvector((yyvsp[-4].typeinfo)->tac,ret,(yyvsp[-2].typeinfo)->tac,a,(yyvsp[0].typeinfo)->tac);(yyval.typeinfo)->temporarystore = contemp((yyvsp[-4].typeinfo)->temporarystore,(yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore);}
#line 9460 "parser.tab.c"
    break;

  case 688:
#line 2560 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9466 "parser.tab.c"
    break;

  case 689:
#line 2561 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();string no = "_xv86 subq $8, %rsp";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;string l1=newlabel();string l2=newlabel();vector<string>p;p.push_back(no);string x="if nonzero "+(yyvsp[-2].typeinfo)->tempname+" go to "+l1;p.push_back(x);x="if nonzero "+(yyvsp[0].typeinfo)->tempname+" go to "+l1;p.push_back(x);x="a = 0";p.push_back(x);x="go to "+l2;p.push_back(x);p.push_back(l1);p.push_back("a = 1");p.push_back(l2);(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,p);(yyval.typeinfo)->exprvalue=(yyvsp[-2].typeinfo)->exprvalue||(yyvsp[0].typeinfo)->exprvalue;}
#line 9472 "parser.tab.c"
    break;

  case 690:
#line 2563 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9478 "parser.tab.c"
    break;

  case 691:
#line 2564 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();string no = "_xv86 subq $8, %rsp";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;string l1=newlabel();string l2=newlabel();vector<string>p;p.push_back(no);string x="if zero "+(yyvsp[-2].typeinfo)->tempname+" go to "+l1;p.push_back(x);x="if zero "+(yyvsp[0].typeinfo)->tempname+" go to "+l1;p.push_back(x);x="a = 1";p.push_back(x);x="go to "+l2;p.push_back(x);p.push_back(l1);p.push_back("a = 0");p.push_back(l2);(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,p);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)&&((yyvsp[0].typeinfo)->exprvalue));}
#line 9484 "parser.tab.c"
    break;

  case 692:
#line 2566 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9490 "parser.tab.c"
    break;

  case 693:
#line 2567 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[-2].typeinfo)->tempname+" | "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)|((yyvsp[0].typeinfo)->exprvalue));}
#line 9496 "parser.tab.c"
    break;

  case 694:
#line 2569 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9502 "parser.tab.c"
    break;

  case 695:
#line 2570 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[-2].typeinfo)->tempname+" ^ "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)^((yyvsp[0].typeinfo)->exprvalue));}
#line 9508 "parser.tab.c"
    break;

  case 696:
#line 2572 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9514 "parser.tab.c"
    break;

  case 697:
#line 2573 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[-2].typeinfo)->tempname+" & "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)&((yyvsp[0].typeinfo)->exprvalue));}
#line 9520 "parser.tab.c"
    break;

  case 698:
#line 2575 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9526 "parser.tab.c"
    break;

  case 699:
#line 2576 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[-2].typeinfo)->tempname+" == "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)==((yyvsp[0].typeinfo)->exprvalue));}
#line 9532 "parser.tab.c"
    break;

  case 700:
#line 2577 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[-2].typeinfo)->tempname+" != "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)!=((yyvsp[0].typeinfo)->exprvalue));}
#line 9538 "parser.tab.c"
    break;

  case 701:
#line 2579 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9544 "parser.tab.c"
    break;

  case 702:
#line 2580 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[-2].typeinfo)->tempname+" < "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)<((yyvsp[0].typeinfo)->exprvalue));}
#line 9550 "parser.tab.c"
    break;

  case 703:
#line 2581 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[-2].typeinfo)->tempname+" > "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)>((yyvsp[0].typeinfo)->exprvalue));}
#line 9556 "parser.tab.c"
    break;

  case 704:
#line 2582 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[-2].typeinfo)->tempname+" <= "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)<=((yyvsp[0].typeinfo)->exprvalue));}
#line 9562 "parser.tab.c"
    break;

  case 705:
#line 2583 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = "boolean";string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[-2].typeinfo)->tempname+" >= "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)>=((yyvsp[0].typeinfo)->exprvalue));}
#line 9568 "parser.tab.c"
    break;

  case 706:
#line 2584 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9574 "parser.tab.c"
    break;

  case 707:
#line 2589 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[-2].typeinfo)->tempname+" instanceof "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[-2].typeinfo)->exprvalue;}
#line 9580 "parser.tab.c"
    break;

  case 708:
#line 2591 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9586 "parser.tab.c"
    break;

  case 709:
#line 2592 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[-2].typeinfo)->tempname+" << "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)<<((yyvsp[0].typeinfo)->exprvalue));}
#line 9592 "parser.tab.c"
    break;

  case 710:
#line 2593 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[-2].typeinfo)->tempname+" >> "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)>>((yyvsp[0].typeinfo)->exprvalue));}
#line 9598 "parser.tab.c"
    break;

  case 711:
#line 2594 "parser.y"
                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type;string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[-2].typeinfo)->tempname+" >>> "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)>>((yyvsp[0].typeinfo)->exprvalue));}
#line 9604 "parser.tab.c"
    break;

  case 712:
#line 2596 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9610 "parser.tab.c"
    break;

  case 713:
#line 2597 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[-2].typeinfo)->tempname+" + "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)+((yyvsp[0].typeinfo)->exprvalue));}
#line 9616 "parser.tab.c"
    break;

  case 714:
#line 2598 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[-2].typeinfo)->tempname+" - "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)-((yyvsp[0].typeinfo)->exprvalue));}
#line 9622 "parser.tab.c"
    break;

  case 715:
#line 2600 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9628 "parser.tab.c"
    break;

  case 716:
#line 2601 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[-2].typeinfo)->tempname+" * "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[-2].typeinfo)->exprvalue)*((yyvsp[0].typeinfo)->exprvalue));}
#line 9634 "parser.tab.c"
    break;

  case 717:
#line 2602 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[-2].typeinfo)->tempname+" / "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);int p=(yyvsp[-2].typeinfo)->exprvalue;int q=(yyvsp[0].typeinfo)->exprvalue;if(q==0)q=1;(yyval.typeinfo)->exprvalue=p/q;}
#line 9640 "parser.tab.c"
    break;

  case 718:
#line 2603 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = type_change(((yyvsp[-2].typeinfo))->type,((yyvsp[0].typeinfo))->type);string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-2].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[-2].typeinfo)->tempname+" % "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[-2].typeinfo)->tac,(yyvsp[0].typeinfo)->tac,a);int p=(yyvsp[-2].typeinfo)->exprvalue;int q=(yyvsp[0].typeinfo)->exprvalue;if(q==0)q=1;(yyval.typeinfo)->exprvalue=p%q;}
#line 9646 "parser.tab.c"
    break;

  case 719:
#line 2605 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;string a = newtemp();string b = a + " = "+(yyvsp[0].typeinfo)->post;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;(yyval.typeinfo)->tac = {b};(yyval.typeinfo)->tempname = a;}
#line 9652 "parser.tab.c"
    break;

  case 720:
#line 2606 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;string a = newtemp();string b = a + " = "+(yyvsp[0].typeinfo)->post;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;(yyval.typeinfo)->tac = {b};(yyval.typeinfo)->tempname = a;}
#line 9658 "parser.tab.c"
    break;

  case 721:
#line 2607 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(1+((yyvsp[0].typeinfo)->exprvalue));(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9664 "parser.tab.c"
    break;

  case 722:
#line 2608 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+" - "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(((yyvsp[0].typeinfo)->exprvalue)-1);}
#line 9670 "parser.tab.c"
    break;

  case 723:
#line 2609 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9676 "parser.tab.c"
    break;

  case 724:
#line 2611 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string a=(yyvsp[0].typeinfo)->tempname;string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;string k1 = newtemp();string k = newtemp();string no2 = k1 + " = 1";string no3 = (yyvsp[0].typeinfo)->post +" = "+k;a=no+no2+"\n"+k+" = "+(yyvsp[0].typeinfo)->tempname+" + "+ k1+"\n"+no3;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue+1;(yyval.typeinfo)->post = (yyvsp[0].typeinfo)->post;}
#line 9682 "parser.tab.c"
    break;

  case 725:
#line 2613 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string a=(yyvsp[0].typeinfo)->tempname;string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;string k1 = newtemp();string k = newtemp();string no2 = k1 + " = 1";string no3 = (yyvsp[0].typeinfo)->post +" = "+k;a=no+no2+"\n"+k+" = "+(yyvsp[0].typeinfo)->tempname+" - "+ k1+"\n"+no3;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue-1;(yyval.typeinfo)->post = (yyvsp[0].typeinfo)->post;}
#line 9688 "parser.tab.c"
    break;

  case 726:
#line 2615 "parser.y"
                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;(yyval.typeinfo)->tempname = (yyvsp[0].typeinfo)->tempname;}
#line 9694 "parser.tab.c"
    break;

  case 727:
#line 2616 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+" ~ "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 9700 "parser.tab.c"
    break;

  case 728:
#line 2617 "parser.y"
                                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+" ! "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=!((yyvsp[0].typeinfo)->exprvalue);}
#line 9706 "parser.tab.c"
    break;

  case 729:
#line 2618 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9712 "parser.tab.c"
    break;

  case 730:
#line 2619 "parser.y"
                                                                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9718 "parser.tab.c"
    break;

  case 731:
#line 2621 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9724 "parser.tab.c"
    break;

  case 732:
#line 2622 "parser.y"
                                                                                        {(yyval.typeinfo) = createstruct();string p = (yyvsp[0].str);(yyval.typeinfo)->post =identwithoff(p);symentry*s=lookup(p); if(lookup(p)){((yyval.typeinfo))->type = s->type;(yyval.typeinfo)->order=s->order;(yyval.typeinfo)->exprvalue=s->exprvalue;}string a=(yyvsp[0].str); string b=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp(b);(yyval.typeinfo)->tempname=b;b=no+b+" = "+identwithoff(a);(yyval.typeinfo)->tac={b};(yyval.typeinfo)->tac={b};}
#line 9730 "parser.tab.c"
    break;

  case 733:
#line 2623 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9736 "parser.tab.c"
    break;

  case 734:
#line 2624 "parser.y"
                                                                                                                                                {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);((yyval.typeinfo))->type = ((yyvsp[0].typeinfo))->type;string a = newtemp();string b = a + " = "+(yyvsp[0].typeinfo)->post;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;(yyval.typeinfo)->tac = {b};(yyval.typeinfo)->tempname = a;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 9742 "parser.tab.c"
    break;

  case 735:
#line 2625 "parser.y"
                                                                                                                                        {(yyval.typeinfo) = createstruct();(yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->type = ((yyvsp[0].typeinfo))->type;string a = newtemp();string b = a + " = "+(yyvsp[0].typeinfo)->post;(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;(yyval.typeinfo)->tac = {b};(yyval.typeinfo)->tempname = a;(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 9748 "parser.tab.c"
    break;

  case 736:
#line 2627 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;string a=(yyvsp[-1].typeinfo)->tempname;string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-1].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;string k1 = newtemp();string k = newtemp();string no2 = k1 + " = 1";string no3 = (yyvsp[-1].typeinfo)->post +" = "+k;a=no+no2+"\n"+k+" = "+(yyvsp[-1].typeinfo)->tempname+" + "+ k1+"\n"+no3;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[-1].typeinfo)->exprvalue+1;(yyval.typeinfo)->post = (yyvsp[-1].typeinfo)->post;}
#line 9754 "parser.tab.c"
    break;

  case 737:
#line 2629 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-1].typeinfo))->type;string a=(yyvsp[-1].typeinfo)->tempname;string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[-1].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;string k1 = newtemp();string k = newtemp();string no2 = k1 + " = 1";string no3 = (yyvsp[-1].typeinfo)->post +" = "+k;a=no+no2+"\n"+k+" = "+(yyvsp[-1].typeinfo)->tempname+" - "+ k1+"\n"+no3;(yyval.typeinfo)->tac=concvector((yyvsp[-1].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[-1].typeinfo)->exprvalue-1;(yyval.typeinfo)->post = (yyvsp[-1].typeinfo)->post;}
#line 9760 "parser.tab.c"
    break;

  case 738:
#line 2631 "parser.y"
                                                                                                        {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type; ((yyvsp[0].typeinfo))->type = ((yyvsp[-2].typeinfo))->type; string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 9766 "parser.tab.c"
    break;

  case 739:
#line 2632 "parser.y"
                                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-2].typeinfo))->type; ((yyvsp[0].typeinfo))->type = ((yyvsp[-2].typeinfo))->type; string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 9772 "parser.tab.c"
    break;

  case 740:
#line 2633 "parser.y"
                                                                                                {(yyval.typeinfo) = createstruct();((yyval.typeinfo))->type = ((yyvsp[-3].typeinfo))->type; ((yyvsp[0].typeinfo))->type = ((yyvsp[-3].typeinfo))->type; string a=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp((yyvsp[0].typeinfo)->temporarystore,a);(yyval.typeinfo)->tempname=a;a=no+a+" = "+(yyvsp[0].typeinfo)->tempname;(yyval.typeinfo)->tac=concvector((yyvsp[0].typeinfo)->tac,a);(yyval.typeinfo)->exprvalue=(yyvsp[0].typeinfo)->exprvalue;}
#line 9778 "parser.tab.c"
    break;

  case 741:
#line 2635 "parser.y"
                                                   {symtable *a = createscope("switch"); changescope(a);}
#line 9784 "parser.tab.c"
    break;

  case 742:
#line 2635 "parser.y"
                                                                                                                                        {goparent();(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)->tac=concvector((yyvsp[-3].typeinfo)->tac,(yyvsp[0].typeinfo)->tac);((yyval.typeinfo))->type = "switch";(yyval.typeinfo)->exprvalue=1;(yyval.typeinfo)->temporarystore = contemp((yyvsp[-3].typeinfo)->temporarystore,(yyvsp[0].typeinfo)->temporarystore);}
#line 9790 "parser.tab.c"
    break;

  case 743:
#line 2637 "parser.y"
                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9796 "parser.tab.c"
    break;

  case 744:
#line 2638 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; string a=(yyvsp[0].str); string b=newtemp();string no = "_xv86 subq $8, %rsp\n";(yyval.typeinfo)->temporarystore = contemp(b);(yyval.typeinfo)->tempname=b;b=no+b+" = "+identwithoff(a);(yyval.typeinfo)->tac={b};(yyval.typeinfo)->tac={b};}
#line 9802 "parser.tab.c"
    break;

  case 745:
#line 2639 "parser.y"
                                                                                                                                        {(yyval.typeinfo)=new Typeinfo; (yyval.typeinfo)=(yyvsp[0].typeinfo);(yyval.typeinfo)->temporarystore = (yyvsp[0].typeinfo)->temporarystore;}
#line 9808 "parser.tab.c"
    break;


#line 9812 "parser.tab.c"

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
#line 2642 "parser.y"

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
	csvFile << "Name, Type, primtive type,size/ArrayDimensions,Function Input Type, Function Output Type, Scope,Offset" << "\n";
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
			if(z.second->type=="array"){
			csvFile<<z.first<<","<<z.second->type<<","<<z.second->primtype<<","<<p<<","<<z.second->argcon<<","<<z.second->funcrettype<<","<<z.second->scope<<","<<z.second->offset<<"\n";
			}
			else{
			csvFile<<z.first<<","<<z.second->type<<","<<z.second->primtype<<","<<z.second->size<<","<<z.second->argcon<<","<<z.second->funcrettype<<","<<z.second->scope<<","<<z.second->offset<<"\n";
			}
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
