%{
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
%}

%union {char* str; struct Typeinfo* typeinfo;}         /* Yacc definitions */



%token ABSTRACT CONTINUE FOR NEW SWITCH ASSERT DEFAULT IF PACKAGE SYNCHRONIZED BOOLEAN DO GOTO PRIVATE THIS BREAK DOUBLE IMPLEMENTS PROTECTED THROW BYTE ELSE IMPORT PUBLIC THROWS CASE ENUM  RETURN TRANSIENT CATCH EXTENDS INT SHORT TRY CHAR FINAL INTERFACE STATIC VOID CLASS FINALLY LONG STRICTFP VOLATILE CONST FLOAT NATIVE SUPER WHILE UNDERSCORE EXPORTS OPENS REQUIRES USES MODULE PERMITS SEALED VAR NONSEALED PROVIDES TO WITH OPEN RECORD TRANSITIVE YIELD

%token <str> INTEGERLITERAL FLOATINGPOINTLITERAL BOOLEANLITERAL NULLLITERAL CHARACTERLITERAL STRING TEXTBLOCKS ESCAPESEQUENCE
%token GT LT EXCLAM TILDA QM COLON IMPLIES DOUBLEEQUAL GTE LTE NE AND OR INCREAMENT DECREAMENT PLUS MINUS MULTIPLY DIVIDE BITAND BITOR BITXOR PERCENT LSHIFT RSHIFT THREEGT
%token EQUAL NEWASSIGNMENTOPERATOR
%token LRB RRB LCB RCB LSB RSB SEMICOLON COMMA DOT THREEDOT AT DOUBLECOLON 
%token IDENTIFIERWK


%start CompilationUnit

%right <str> ABSTRACT CONTINUE FOR SWITCH ASSERT DEFAULT IF PACKAGE SYNCHRONIZED DO GOTO PRIVATE THIS BREAK IMPLEMENTS PROTECTED THROW ELSE IMPORT PUBLIC THROWS CASE ENUM  RETURN TRANSIENT CATCH EXTENDS TRY FINAL INTERFACE STATIC VOID CLASS FINALLY STRICTFP VOLATILE CONST NATIVE SUPER WHILE UNDERSCORE 
%right <str> BOOLEAN DOUBLE BYTE INT SHORT CHAR LONG FLOAT EXPORTS OPENS REQUIRES USES MODULE PERMITS SEALED VAR NONSEALED PROVIDES TO WITH OPEN RECORD TRANSITIVE YIELD  IDENTIFIERWK
%right <str> EQUAL NEWASSIGNMENTOPERATOR
%right <str> QM COLON
%left  <str> OR
%left  <str> AND
%left  <str> BITOR
%left  <str> BITXOR
%left  <str> BITAND
%left  <str> NE DOUBLEEQUAL
%nonassoc <str> LT GT GTE LTE INSTANCEOF AT
%left  <str> LSHIFT RSHIFT THREEGT
%left  <str> PLUS MINUS
%left  <str> MULTIPLY DIVIDE PERCENT
%right <str> NEW
%right <str> INCREAMENT DECREAMENT EXCLAM TILDA
%right <str> LRB RRB LCB RCB LSB RSB DOT COMMA SEMICOLON THREEDOT DOUBLECOLON IMPLIES


%type <str> Identifier ASSIGNMENTOPERATOR AssignmentOperator

%type <typeinfo> CompactConstructorDeclarationSym RecordDeclarationSym ConstructorDeclaratorLRBSym TryBlockSym TrySym ForSym		OMPSB   PSB   OMAdditionalBound   ReceiverParameterComma   IdentifierDot   OMImportDeclaration   OMTopLevelClassOrInterfaceDeclaration   OMDotIdentifier   OMModuleDirective   OMRequiresModifier   OMCommaModuleName   CommaModuleName   OMCommaTypeName   CommaTypeName   OMClassModifier   OMCommaTypeParameter   CommaTypeParameter   OMCommaInterfaceType   CommaInterfaceType   OMClassBodyDeclaration     OMCommaFormalParameter   CommaFormalParameter   OMCommaExceptionType   CommaExceptionType   OMCommaRecordComponent   CommaRecordComponent     OMRecordBodyDeclaration   OMInterfaceMemberDeclaration     OMBlockStatement   OMSwitchRule   OMSwitchBlockStatementGroup   OMSwitchLabelColon   SwitchLabelColon   OMCommaCaseConstant   CommaCaseConstant   OMCommaStatementExpression   CommaStatementExpression   OMCatchClause   OMOrClassType   OrClassType   OMSemicolonResource   SemicolonResource   OMCommaExpression   CommaExpression   OMDimExpr   Modifieropt   UnqualifiedMethodIdentifier   Literal   PrimitiveType   NumericType   IntegralType   FloatingPointType   ReferenceType   TypeParameter   TypeBound   AdditionalBound  ModuleName   ExpressionName   MethodName   CompilationUnit   OrdinaryCompilationUnit   ModularCompilationUnit   PackageDeclaration   ImportDeclaration   SingleTypeImportDeclaration   SingleStaticImportDeclaration   ImportOnDemandDeclaration   StaticImportOnDemandDeclaration   TopLevelClassOrInterfaceDeclaration   ModuleDeclaration   ModuleDirective   ClassDeclaration   NormalClassDeclaration   TypeParameters   TypeParameterList   ClassExtends   ClassImplements   InterfaceTypeList   ClassPermits   ClassBody   ClassBodyDeclaration   ClassMemberDeclaration   FieldDeclaration   VariableDeclaratorList   VariableDeclarator   VariableDeclaratorId   VariableInitializer   UnannType   UnannPrimitiveType   UnannArrayType   MethodDeclaration   MethodHeader   Result   MethodDeclarator   ReceiverParameter   FormalParameterList   FormalParameter   VariableArityParameter   Throws   ExceptionTypeList   ExceptionType   MethodBody   InstanceInitializer   StaticInitializer   ConstructorDeclaration   ConstructorDeclarator   ConstructorBody   ExplicitConstructorInvocation    RecordDeclaration   RecordHeader   RecordComponentList   RecordComponent   VariableArityRecordComponent   RecordBody   RecordBodyDeclaration   CompactConstructorDeclaration   InterfaceDeclaration   NormalInterfaceDeclaration   InterfaceModifier   InterfaceExtends   InterfacePermits   InterfaceBody   InterfaceMemberDeclaration   ConstantDeclaration   InterfaceMethodDeclaration   ArrayInitializer   VariableInitializerList   Block   BlockStatements   BlockStatement   LocalClassOrInterfaceDeclaration   LocalVariableDeclarationStatement   LocalVariableDeclaration   LocalVariableType   Statement   StatementNoShortIf   StatementWithoutTrailingSubstatement   EmptyStatement   LabeledStatement   LabeledStatementNoShortIf   ExpressionStatement   StatementExpression   IfThenStatement   IfThenElseStatement   IfThenElseStatementNoShortIf   AssertStatement   SwitchStatement   SwitchBlock   SwitchRule   SwitchBlockStatementGroup   SwitchLabel   CaseConstant   WhileStatement   WhileStatementNoShortIf   DoStatement   ForStatement   ForStatementNoShortIf   BasicForStatement   BasicForStatementNoShortIf   ForInit   ForUpdate   StatementExpressionList   EnhancedForStatement   EnhancedForStatementNoShortIf   BreakStatement   YieldStatement   ContinueStatement   ReturnStatement   ThrowStatement   SynchronizedStatement   TryStatement   Catches   CatchClause   CatchFormalParameter   CatchType   Finally   TryWithResourcesStatement   ResourceSpecification   ResourceList   Resource   Primary   PrimaryNoNewArray   ClassLiteral   ClassInstanceCreationExpression   UnqualifiedClassInstanceCreationExpression   ClassOrInterfaceTypeToInstantiate   FieldAccess   ArrayAccess   MethodInvocation   ArgumentList   MethodReference   ArrayCreationExpression   DimExpr   Expression   AssignmentExpression   Assignment   LeftHandSide     ConditionalExpression   ConditionalOrExpression   ConditionalAndExpression   InclusiveOrExpression   ExclusiveOrExpression   AndExpression   EqualityExpression   RelationalExpression   InstanceofExpression   ShiftExpression   AdditiveExpression   MultiplicativeExpression   UnaryExpression   PreIncrementExpression   PreDecrementExpression   UnaryExpressionNotPlusMinus   PostfixExpression   PostIncrementExpression   PostDecrementExpression   CastExpression   SwitchExpression   VariableAccess    OMCommaEnumConstant CommaEnumConstant EnumDeclaration EnumBody EnumBodyDeclarations EnumConstantList EnumConstant  PRB PRBArgumentList  EnhancedForStatementSym


%%

OMPSB:  PSB								{$$ = createstruct();($$)->type = ($1)->type ;$$->order=1;$$->tac=emptyvector();}										
		|	OMPSB PSB					{$$ = createstruct();($$)->type = ($1)->type + "[]";$$->order=$1->order+1;$$->tac=emptyvector();}										
		;
PSB: LSB RSB		{$$ = createstruct();($$)->type = "[]";$$->tac=emptyvector();}														
		;
OMAdditionalBound:  AdditionalBound					{$$=new Typeinfo; $$->tac=$1->tac;}										
        |	OMAdditionalBound   AdditionalBound 		{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}										
        ;
ReceiverParameterComma: ReceiverParameter COMMA			{$$=new Typeinfo; $$->tac= $1->tac;}							
        ;
IdentifierDot:  Identifier DOT{         $$=new Typeinfo; $$->tac=emptyvector();}											
        ;
OMImportDeclaration: ImportDeclaration				{$$=new Typeinfo; $$->tac= $1->tac;}								
    	|   OMImportDeclaration ImportDeclaration 		{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}						
    	;
OMTopLevelClassOrInterfaceDeclaration: TopLevelClassOrInterfaceDeclaration 		{$$=new Typeinfo;$$->tac=$1->tac;}							
    	|   OMTopLevelClassOrInterfaceDeclaration TopLevelClassOrInterfaceDeclaration 		{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}		
    	;
OMDotIdentifier: DOT Identifier					{$$ = createstruct();string p=($2);($$)->name="."+p;$$->tac=emptyvector();}										
    	|  OMDotIdentifier DOT Identifier	    {$$ = createstruct();string p=($3);($$)->name=($1)->name+"."+p;$$->tac= $1->tac;}								
    	;
OMModuleDirective: ModuleDirective				{$$=new Typeinfo; $$->tac=$1->tac;}												
    	|  OMModuleDirective ModuleDirective 		{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}										
    	;
OMRequiresModifier: Modifieropt						{$$=new Typeinfo; $$->tac=$1->tac;}										
    	| OMRequiresModifier  Modifieropt			{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}										
    	;
OMCommaModuleName: CommaModuleName						{$$=new Typeinfo; $$->tac= $1->tac;}								
    	|  OMCommaModuleName CommaModuleName 			{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}								
    	;
CommaModuleName:    COMMA ModuleName						{$$=new Typeinfo; $$->tac= $2->tac;}						
    	;
OMCommaTypeName: CommaTypeName 									{$$=new Typeinfo; $$->tac= $1->tac;}							
    	|  OMCommaTypeName CommaTypeName 					{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}								
    	;
CommaTypeName:    COMMA Identifier								{$$=new Typeinfo; $$->tac=emptyvector();}			
    	|  COMMA ExpressionName								{$$=new Typeinfo; $$->tac= $2->tac;}		
    	;
OMClassModifier:    InterfaceModifier						{$$=new Typeinfo; $$->tac= $1->tac;}						
        |     OMClassModifier  InterfaceModifier				{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}						
        ;
OMCommaTypeParameter:   CommaTypeParameter						{$$=new Typeinfo; $$->tac=emptyvector();}
        |      OMCommaTypeParameter CommaTypeParameter 			{$$=new Typeinfo; $$->tac=emptyvector();}
        ;	
CommaTypeParameter:     COMMA TypeParameter						{$$=new Typeinfo; $$->tac= $2->tac;}
        ;
OMCommaInterfaceType:    CommaInterfaceType						{$$=new Typeinfo; $$->tac= $1->tac;}					
        |      OMCommaInterfaceType CommaInterfaceType 				{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}				
        ;
CommaInterfaceType:     COMMA Identifier								{$$=new Typeinfo; $$->tac=emptyvector();}		
        ;
OMClassBodyDeclaration:  ClassBodyDeclaration							{$$=new Typeinfo; $$->tac=$1->tac;}				
        |    OMClassBodyDeclaration   ClassBodyDeclaration 				{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}			
        ;
OMCommaFormalParameter: CommaFormalParameter								{$$ = createstruct();($$)->type_variable = ($1)->type_variable;$$->tac= $1->tac;}
        |      OMCommaFormalParameter CommaFormalParameter 		{$$ = createstruct();vector<string>a=($1)->type_variable;vector<string>b=($2)->type_variable;for(auto z:a){($$)->type_variable.push_back(z);}for(auto z:b){($$)->type_variable.push_back(z);}$$->tac=concvector($1->tac,$2->tac);}				
        ;
CommaFormalParameter:   COMMA FormalParameter								{$$ = createstruct();($$)->type_variable = ($2)->type_variable;$$->tac= $2->tac;}
        ;
OMCommaExceptionType:   CommaExceptionType								{$$=new Typeinfo; $$->tac= $1->tac;}			
        |     OMCommaExceptionType  CommaExceptionType 					{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}			
        ;
CommaExceptionType: COMMA ExceptionType										{$$=new Typeinfo; $$->tac= $2->tac;}		
        ;
OMCommaEnumConstant:   CommaEnumConstant 							{$$=new Typeinfo; $$->tac= $1->tac;}		
        |     OMCommaEnumConstant  CommaEnumConstant 				{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}		
        ;
CommaEnumConstant:      EnumConstant COMMA									{$$=new Typeinfo; $$->tac= $1->tac;}
        ;	
OMCommaRecordComponent: CommaRecordComponent							{$$=new Typeinfo; $$->tac= $1->tac;}		
        |      OMCommaRecordComponent CommaRecordComponent 			{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}			
        ;
CommaRecordComponent:   COMMA RecordComponent								{$$=new Typeinfo; $$->tac= $2->tac;}
        ;
OMRecordBodyDeclaration:       RecordBodyDeclaration 						{$$=new Typeinfo; $$->tac= $1->tac;}	
        |     OMRecordBodyDeclaration  RecordBodyDeclaration   				{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}	
        ;
OMInterfaceMemberDeclaration: InterfaceMemberDeclaration					{$$=new Typeinfo; $$->tac= $1->tac;}	
    	|  OMInterfaceMemberDeclaration InterfaceMemberDeclaration 			{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}	
    	;
// OMCommaVariableInitializer: CommaVariableInitializer						{$$ = createstruct();($$)->type =  ($1)->type; $$->tac= $1->tac;}
//         |     OMCommaVariableInitializer  CommaVariableInitializer 			{$$ = createstruct();($$)->type =  ($2)->type;$$->tac=concvector($1->tac,$2->tac);}
//         ;
// CommaVariableInitializer:       COMMA VariableInitializer					{$$ = createstruct();($$)->type =  ($2)->type; $$->tac= $2->tac;}	
//         ;	
OMBlockStatement: BlockStatement 								{$$=new Typeinfo; $$=$1;}							
    	|  OMBlockStatement BlockStatement 						{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}			
    	;
OMSwitchRule: SwitchRule										{$$=new Typeinfo; $$->tac= $1->tac;}				
    	|  OMSwitchRule SwitchRule 								{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}			
    	;
OMSwitchBlockStatementGroup: SwitchBlockStatementGroup			{$$=new Typeinfo; $$->tac= $1->tac;}							
    | OMSwitchBlockStatementGroup  SwitchBlockStatementGroup 		{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}			
    ;
OMSwitchLabelColon: SwitchLabelColon							{$$=new Typeinfo; $$->tac= $1->tac;}				
    |  OMSwitchLabelColon SwitchLabelColon 						{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}				
    ;
SwitchLabelColon:   SwitchLabel COLON							{$$=new Typeinfo; $$->tac= $1->tac;}				
    ;
OMCommaCaseConstant: CommaCaseConstant 							{$$=new Typeinfo; $$->tac= $1->tac;}					
    |   OMCommaCaseConstant CommaCaseConstant 					{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}					
    ;
CommaCaseConstant:  COMMA CaseConstant									{$$=new Typeinfo; $$->tac= $2->tac;}			
    ;
OMCommaStatementExpression: CommaStatementExpression			{$$=new Typeinfo; $$->tac= $1->tac;}					
    | OMCommaStatementExpression  CommaStatementExpression 		{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}			
    ;
CommaStatementExpression:  COMMA StatementExpression				{$$=new Typeinfo; $$->tac= $2->tac;}			
    ;
OMCatchClause:	CatchClause									{$$=new Typeinfo; $$->tac= $1->tac;}							
    |  OMCatchClause CatchClause 						{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}						
    ;
OMOrClassType: OrClassType							{$$=new Typeinfo; $$->tac= $1->tac;}						
    |  OMOrClassType OrClassType 					 										{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}							
    ;
OrClassType:   BITOR Identifier												{$$=new Typeinfo; $$->tac=emptyvector();}	
    ;
OMSemicolonResource: SemicolonResource							{$$=new Typeinfo; $$->tac= $1->tac;}			
    | OMSemicolonResource  SemicolonResource 					{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}				
    ;
SemicolonResource:  Resource SEMICOLON						{$$=new Typeinfo; $$->tac= $1->tac;}				
    ;
OMCommaExpression:   CommaExpression						{$$=new Typeinfo; $$->tac= $1->tac;for(auto z:$1->params)$$->params.push_back(z);}					
        |  OMCommaExpression CommaExpression 				{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);for(auto z:($1)->params)($$)->params.push_back(z);for(auto z:($2)->params)($$)->params.push_back(z);}					
        ;
CommaExpression:    COMMA Expression									{$$=new Typeinfo; $$->tac= $2->tac;string s = ($2)->tempname; $$->params.push_back(s);}
        ;
OMDimExpr:      DimExpr												{$$=createstruct();int p=$1->exprvalue;vector<int>q={p};$$->arrdim=q;$$->tac= $1->tac;}		
        |     OMDimExpr  DimExpr 									{$$=createstruct();int p=$2->exprvalue;$$->arrdim=$1->arrdim;($$)->arrdim.push_back(p);$$->tac=concvector($1->tac,$2->tac);}		
        ;
Modifieropt:	PUBLIC									{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| PROTECTED												{string x=$1;$$=new Typeinfo; $$->tempname=x;}					
		| PRIVATE														{string x=$1;$$=new Typeinfo; $$->tempname=x;}					
		| ABSTRACT												{string x=$1;$$=new Typeinfo; $$->tempname=x;}					
		| STATIC														{string x=$1;$$=new Typeinfo; $$->tempname=x;}					
		| SEALED														{string x=$1;$$=new Typeinfo; $$->tempname=x;}					
		| STRICTFP													{string x=$1;$$=new Typeinfo; $$->tempname=x;}					
		| FINAL															{string x=$1;$$=new Typeinfo; $$->tempname=x;}					
		;
Identifier:	 IDENTIFIERWK			{$$=$1;}										
		;
UnqualifiedMethodIdentifier:	 IDENTIFIERWK			{$$ = createstruct(); string p = $1;($$)->name = p;$$->tempname=p;}		
		| EXPORTS											{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| OPENS												{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| REQUIRES											{string x=$1;$$=new Typeinfo; $$->tempname=x;}		
		| USES												{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| MODULE											{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| PERMITS										{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| SEALED											{string x=$1;$$=new Typeinfo; $$->tempname=x;}		
		| VAR												{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| NONSEALED											{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| PROVIDES											{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| TO												{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| WITH												{string x=$1;$$=new Typeinfo; $$->tempname=x;}		
		| OPEN												{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| RECORD											{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| TRANSITIVE										{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		;
// Literal:	 INTEGERLITERAL								{string x=$1;int p=stoi(x);$$=new Typeinfo;     $$->littype="int";$$->valint=p;string y=newtemp();$$->tempname=y;string z=y+" = "+x;$$->tac={z};$$->exprvalue=atoi($1);($$)->type = "int";}				
// 		| FLOATINGPOINTLITERAL							{string x=$1;float p=stof(x);$$=new Typeinfo;   $$->littype="float";$$->valfloat=p;string y=newtemp();$$->tempname=y;string z=y+" = "+x;$$->tac={z};$$->exprvalue=(int)($$->valfloat);($$)->type = "float";}						
// 		| BOOLEANLITERAL						        {string x=$1;;$$=new Typeinfo;                  $$->littype="bool";$$->valstr=x;string y=newtemp();$$->tempname=y;string z=y+" = "+x;$$->tac={z};if(x=="true"){$$->exprvalue=1;}else{$$->exprvalue=0;};($$)->type = "bool";}									
// 		| NULLLITERAL							        {string x=$1;$$=new Typeinfo;                   $$->littype="null";$$->valstr=x;string y=newtemp();$$->tempname=y;string z=y+" = "+x;$$->tac={z};$$->exprvalue=0;$$->type="null";}								
// 		| CHARACTERLITERAL							    {string x=$1;$$=new Typeinfo;                   $$->littype="char";$$->valstr=x;string y=newtemp();$$->tempname=y;string z=y+"="+x;$$->tac={z};$$->exprvalue=x[0]-'\0';($$)->type = "char";}								
// 		| STRING									    {string x=$1;$$=new Typeinfo;                   $$->littype="string";$$->valstr=x;string y=newtemp();$$->tempname=y;string z=y+" = "+x;$$->tac={z};($$)->type = "string";}								
// 		| TEXTBLOCKS								    {string x=$1;$$=new Typeinfo;                   $$->littype="textblock";$$->valstr=x;string y=newtemp();$$->tempname=y;string z=y+" = "+x;$$->tac={z};($$)->type = "textblock";}						
// 		;
Literal:	 INTEGERLITERAL								{string x=$1;int p=stoi(x);$$=new Typeinfo;     $$->littype="int";$$->valint=p;string y=newtemp();$$->tempname=y;string z=y+" = "+x;$$->tac={z};$$->exprvalue=atoi($1);($$)->type = "int";}				
		| FLOATINGPOINTLITERAL							{string x=$1;float p=stof(x);$$=new Typeinfo;   $$->littype="float";$$->valfloat=p;string y=newtemp();$$->tempname=y;string z=y+" = "+x;$$->tac={z};$$->exprvalue=(int)($$->valfloat);($$)->type = "float";}						
		| BOOLEANLITERAL						        {string x=$1;;$$=new Typeinfo;                  $$->littype="bool";$$->valstr=x;string y=newtemp();$$->tempname=y;string z=y+" = "+x;$$->tac={z};if(x=="true"){$$->exprvalue=1;}else{$$->exprvalue=0;};($$)->type = "bool";}									
		| NULLLITERAL							        {string x=$1;$$=new Typeinfo;                   $$->littype="null";$$->valstr=x;string y=newtemp();$$->tempname=y;string z=y+" = "+x;$$->tac={z};$$->exprvalue=0;$$->type="null";}								
		| CHARACTERLITERAL							    {string x=$1;$$=new Typeinfo;                   $$->littype="char";$$->valstr=x;string y=newtemp();$$->tempname=y;string z=y+"="+x;$$->tac={z};$$->exprvalue=x[0]-'\0';($$)->type = "char";}								
		| STRING									    {string x=$1;$$=new Typeinfo;                   $$->littype="string";$$->valstr=x;string y=newtemp();$$->tempname=y;string z=y+" = "+x;$$->tac={z};($$)->type = "string";}								
		| TEXTBLOCKS								    {string x=$1;$$=new Typeinfo;                   $$->littype="textblock";$$->valstr=x;string y=newtemp();$$->tempname=y;string z=y+" = "+x;$$->tac={z};($$)->type = "textblock";}	
ASSIGNMENTOPERATOR:	 NEWASSIGNMENTOPERATOR			{$$=$1;}	
		| EQUAL											{$$=$1;}			
		;
PrimitiveType:	 UnannPrimitiveType				{$$ = createstruct();($$)->type = ($1)->type;$$->tac=$1->tac;}							
		;
NumericType:	 IntegralType						{$$ = createstruct();($$)->type = ($1)->type;$$->tac=emptyvector();}		
		| FloatingPointType								{$$ = createstruct();($$)->type = ($1)->type;$$->tac=emptyvector();}	
		;
IntegralType:	 BYTE										{($$) = createstruct();($$)->type = "byte";$$->tac=emptyvector();}	
		| SHORT												{($$) = createstruct();($$)->type = "short";$$->tac=emptyvector();}		
		| INT												{($$) = createstruct();($$)->type = "int";$$->tac=emptyvector();}		
		| LONG												{($$) = createstruct();($$)->type = "long";$$->tac=emptyvector();}		
		| CHAR												{($$) = createstruct();($$)->type = "char";$$->tac=emptyvector();}		
		;
FloatingPointType:	 FLOAT									{($$) = createstruct();($$)->type = "float";$$->tac=emptyvector();}
		| DOUBLE										{($$) = createstruct();($$)->type = "double";$$->tac=emptyvector();}
		;
ReferenceType:	 Identifier									{$$ = createstruct();$$->tac=emptyvector();}
		| UnannArrayType									{$$=new Typeinfo; $$->tac=emptyvector();}				
		;
TypeParameter:	 Identifier									{$$=new Typeinfo; $$->tac=emptyvector();}				
		| Identifier TypeBound								{$$=new Typeinfo; $$->tac=emptyvector();}		
		;
TypeBound:	 EXTENDS Identifier								{$$=new Typeinfo; $$->tac=emptyvector();}				
		| EXTENDS Identifier OMAdditionalBound				{$$=new Typeinfo; $$->tac=emptyvector();}		
		;
AdditionalBound:	 BITAND Identifier						{$$=new Typeinfo; $$->tac=emptyvector();}		
		;
ModuleName:	 Identifier										{$$=new Typeinfo; $$->tac=emptyvector();}	
		| ModuleName DOT Identifier							{$$=new Typeinfo; $$->tac=emptyvector();}	
		;
ExpressionName:	 Identifier DOT Identifier			{$$ = createstruct();string q=($1);string p=($3);($$)->type=q+"."+p;string x=$1;string r=newtemp(); $$->tempname=r;r=r+" = "+x; $$->tac={r};}		
		| ExpressionName DOT Identifier						{$$ = createstruct();string p=($3);($$)->type=($1)->type+"."+p; $$->tac=$1->tac;}
		;
MethodName:	 UnqualifiedMethodIdentifier					{$$ = createstruct(); ;($$)->name = ($1)->name; $$->tac=$1->tac;$$->tempname=$1->tempname;}
		;
CompilationUnit:	 OrdinaryCompilationUnit				{$$=new Typeinfo;$$->tac=$1->tac; for(auto z:($$->tac)) fprintf(dotfile,"%s\n",z.c_str()); }
		| ModularCompilationUnit						{$$=new Typeinfo;$$->tac=$1->tac; for(auto z:($$->tac)) fprintf(dotfile,"%s\n",z.c_str()); }	
		;
OrdinaryCompilationUnit:				{$$=new Typeinfo;$$->tac=emptyvector();}							
		| OMTopLevelClassOrInterfaceDeclaration		{$$=new Typeinfo;$$->tac=$1->tac;}																		
		| OMImportDeclaration							{$$=new Typeinfo;$$->tac=$1->tac;}																
		| OMImportDeclaration OMTopLevelClassOrInterfaceDeclaration			{$$=new Typeinfo;$$->tac=concvector($1->tac,$2->tac);}							
		| PackageDeclaration									{$$=new Typeinfo;$$->tac=$1->tac;}														
		| PackageDeclaration OMTopLevelClassOrInterfaceDeclaration		{$$=new Typeinfo;$$->tac=concvector($1->tac,$2->tac);}						
		| PackageDeclaration OMImportDeclaration			{$$=new Typeinfo;$$->tac=concvector($1->tac,$2->tac);}										
		| PackageDeclaration OMImportDeclaration OMTopLevelClassOrInterfaceDeclaration	  {$$=new Typeinfo;$$->tac=concvector($1->tac,$2->tac,$3->tac);}
		;
ModularCompilationUnit:	 ModuleDeclaration				{$$=new Typeinfo;$$->tac=$1->tac;}																
		| OMImportDeclaration ModuleDeclaration				{$$=new Typeinfo;$$->tac=concvector($1->tac,$2->tac);}																
		;
PackageDeclaration:	 PACKAGE Identifier SEMICOLON				{$$=new Typeinfo; $$->tac=emptyvector();}							
		| PACKAGE Identifier OMDotIdentifier SEMICOLON				{$$=new Typeinfo; $$->tac=emptyvector();}			
		;
ImportDeclaration:	 SingleTypeImportDeclaration					{$$=new Typeinfo;$$->tac=$1->tac;}											
		| SingleStaticImportDeclaration								{$$=new Typeinfo;$$->tac=$1->tac;}																									
		| StaticImportOnDemandDeclaration							{$$=new Typeinfo;$$->tac=$1->tac;}									
		|	ImportOnDemandDeclaration								{$$=new Typeinfo;$$->tac=$1->tac;}											
		;
SingleTypeImportDeclaration:	 IMPORT Identifier SEMICOLON		{$$=new Typeinfo; $$->tac=emptyvector();}						
    	| IMPORT ExpressionName SEMICOLON											{$$=new Typeinfo; $$->tac=emptyvector();}						
		;
SingleStaticImportDeclaration:	IMPORT STATIC ExpressionName SEMICOLON		{$$=new Typeinfo; $$->tac=emptyvector();}			
		;
ImportOnDemandDeclaration:	 IMPORT Identifier DOT MULTIPLY SEMICOLON			{$$=new Typeinfo; $$->tac=emptyvector();}			
    | IMPORT ExpressionName DOT MULTIPLY SEMICOLON										{$$=new Typeinfo; $$->tac=emptyvector();}			
		;
StaticImportOnDemandDeclaration:	 IMPORT STATIC Identifier DOT MULTIPLY SEMICOLON	{$$=new Typeinfo; $$->tac=emptyvector();}
    | IMPORT STATIC ExpressionName DOT MULTIPLY SEMICOLON								{$$=new Typeinfo; $$->tac=emptyvector();}
		;
TopLevelClassOrInterfaceDeclaration:	 ClassDeclaration		{$$=new Typeinfo;$$->tac=$1->tac;}									
		| InterfaceDeclaration								{$$=new Typeinfo;$$->tac=$1->tac;}										
		| SEMICOLON																		{$$=new Typeinfo;$$->tac=emptyvector();}					
		;
ModuleDeclaration:	 MODULE Identifier LCB {symtable*a=createtable();string p=($2);insertclass(p,"module","",a,line);   changescope(a);  } RCB		{goparent();{$$=new Typeinfo;$$->tac=emptyvector();}					}									
		| MODULE Identifier LCB {symtable*a=createtable();string p=($2);insertclass(p,"module","",a,line);   changescope(a);  }   OMModuleDirective RCB			{goparent();$$=new Typeinfo;$$->tac=$5->tac;}						
		| MODULE Identifier OMDotIdentifier LCB {symtable*a=createtable();string p=($2);insertclass(p+($3)->name,"module","",a,line);changescope(a);} RCB		{goparent();$$=new Typeinfo;$$->tac=emptyvector();}								
		| MODULE Identifier OMDotIdentifier  LCB {symtable*a=createtable();string p=($2);insertclass(p+($3)->name,"module","",a,line);changescope(a);} OMModuleDirective RCB		{goparent();$$=new Typeinfo;$$->tac=$6->tac;}			
		| OPEN MODULE Identifier   LCB {symtable*a=createtable();string p=($3);insertclass(p,"module","",a,line);   changescope(a);  } RCB												{goparent();$$=new Typeinfo;$$->tac=emptyvector();}
		| OPEN MODULE Identifier  LCB {symtable*a=createtable();string p=($3);insertclass(p,"module","",a,line);}  OMModuleDirective RCB			{goparent();$$=new Typeinfo;$$->tac=$6->tac;}					
		| OPEN MODULE Identifier OMDotIdentifier  LCB {symtable*a=createtable();string p=($3);insertclass(p+($4)->name,"module","",a,line);changescope(a);}  RCB					{goparent();$$=new Typeinfo;$$->tac=emptyvector();}			
		| OPEN MODULE Identifier OMDotIdentifier  LCB {symtable*a=createtable();string p=($3);insertclass(p+($4)->name,"module","",a,line);changescope(a);} OMModuleDirective RCB	{goparent();$$=new Typeinfo;$$->tac=$7->tac;}			 
		;
ModuleDirective:	 REQUIRES ModuleName SEMICOLON								{$$=new Typeinfo;$$->tac=emptyvector();}
		| REQUIRES OMRequiresModifier ModuleName SEMICOLON					{$$=new Typeinfo;$$->tac=emptyvector();}
		| EXPORTS Identifier SEMICOLON											{$$=new Typeinfo;$$->tac=emptyvector();}
		| EXPORTS Identifier TO ModuleName SEMICOLON								{$$=new Typeinfo;$$->tac=emptyvector();}
		| EXPORTS Identifier TO ModuleName OMCommaModuleName SEMICOLON		{$$=new Typeinfo;$$->tac=emptyvector();}
		| OPENS Identifier SEMICOLON												{$$=new Typeinfo;$$->tac=emptyvector();}
		| OPENS Identifier TO ModuleName SEMICOLON									{$$=new Typeinfo;$$->tac=emptyvector();}
		| OPENS Identifier TO ModuleName OMCommaModuleName SEMICOLON			{$$=new Typeinfo;$$->tac=emptyvector();}
		| USES Identifier SEMICOLON													{$$=new Typeinfo;$$->tac=emptyvector();}
		| PROVIDES Identifier WITH Identifier SEMICOLON							{$$=new Typeinfo;$$->tac=emptyvector();}
		| PROVIDES Identifier WITH Identifier OMCommaTypeName SEMICOLON			{$$=new Typeinfo;$$->tac=emptyvector();}
		| EXPORTS ExpressionName SEMICOLON											{$$=new Typeinfo;$$->tac=$2->tac;}	
		| EXPORTS ExpressionName TO ModuleName SEMICOLON							{$$=new Typeinfo;$$->tac=$2->tac;}	
		| EXPORTS ExpressionName TO ModuleName OMCommaModuleName SEMICOLON		{$$=new Typeinfo;$$->tac=$2->tac;}	
		| OPENS ExpressionName SEMICOLON											{$$=new Typeinfo;$$->tac=$2->tac;}	
		| OPENS ExpressionName TO ModuleName SEMICOLON								{$$=new Typeinfo;$$->tac=$2->tac;}	
		| OPENS ExpressionName TO ModuleName OMCommaModuleName SEMICOLON			{$$=new Typeinfo;$$->tac=$2->tac;}	
		| USES ExpressionName SEMICOLON											{$$=new Typeinfo;$$->tac=$2->tac;}	
		| PROVIDES ExpressionName WITH ExpressionName SEMICOLON						{$$=new Typeinfo;$$->tac=$2->tac;}	
		| PROVIDES ExpressionName WITH ExpressionName OMCommaTypeName SEMICOLON		{$$=new Typeinfo;$$->tac=$2->tac;}	
		| PROVIDES ExpressionName WITH Identifier SEMICOLON							{$$=new Typeinfo;$$->tac=$2->tac;}	
		| PROVIDES Identifier WITH ExpressionName OMCommaTypeName SEMICOLON			{$$=new Typeinfo;$$->tac=$4->tac;}	
		| PROVIDES Identifier WITH ExpressionName SEMICOLON							{$$=new Typeinfo;$$->tac=$4->tac;}	
		| PROVIDES ExpressionName WITH Identifier OMCommaTypeName SEMICOLON			{$$=new Typeinfo;$$->tac=$2->tac;}	
		;
ClassDeclaration:	 NormalClassDeclaration										{$$=new Typeinfo; $$->tac=$1->tac;}		
        | EnumDeclaration						{$$=new Typeinfo; $$->tac=$1->tac;}
		| RecordDeclaration														{$$=new Typeinfo; $$->tac=$1->tac;}		
		;
NormalClassDeclaration:	 CLASS Identifier 						{symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);   changescope(a);  }   ClassBody	{goparent();$$=new Typeinfo; $$->tac=$4->tac;}														
		| CLASS Identifier ClassPermits 						{symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();$$=new Typeinfo; $$->tac=$5->tac;}												
		| CLASS Identifier ClassImplements  					{symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody	{goparent();$$=new Typeinfo; $$->tac=$5->tac;}												
		| CLASS Identifier ClassImplements ClassPermits 		{ symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();$$=new Typeinfo; $$->tac=$6->tac;}								
		| CLASS Identifier ClassExtends  						{ symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody			{goparent();$$=new Typeinfo; $$->tac=$5->tac;}											
		| CLASS Identifier ClassExtends ClassPermits 			{ symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody	{goparent();$$=new Typeinfo; $$->tac=$6->tac;}										
		| CLASS Identifier ClassExtends ClassImplements 		{ symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody	{goparent();$$=new Typeinfo; $$->tac=$6->tac;}									
		| CLASS Identifier ClassExtends ClassImplements ClassPermits 	{ symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();$$=new Typeinfo; $$->tac=$7->tac;}					
		| CLASS Identifier TypeParameters 								{ symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody					{goparent();$$=new Typeinfo; $$->tac=$5->tac;}									
		| CLASS Identifier TypeParameters ClassPermits 					{symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);     changescope(a);  } ClassBody		{goparent();$$=new Typeinfo; $$->tac=$6->tac;}								
		| CLASS Identifier TypeParameters ClassImplements 				{symtable*a=createscope("class");string p=($2); insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();$$=new Typeinfo; $$->tac=$6->tac;}								
		| CLASS Identifier TypeParameters ClassImplements  ClassPermits { symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();$$=new Typeinfo; $$->tac=$7->tac;}				
		| CLASS Identifier TypeParameters ClassExtends					{symtable*a=createscope("class");string p=($2); insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();$$=new Typeinfo; $$->tac=$6->tac;}								
		| CLASS Identifier TypeParameters ClassExtends ClassPermits 	{symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);     changescope(a);  } ClassBody		{goparent();$$=new Typeinfo; $$->tac=$7->tac;}					
		| CLASS Identifier TypeParameters ClassExtends ClassImplements 	{ symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody	{goparent();$$=new Typeinfo; $$->tac=$7->tac;}					
		| CLASS Identifier TypeParameters ClassExtends ClassImplements ClassPermits {symtable*a=createscope("class");string p=($2); insertclass(p,"class","",a,line);    changescope(a);  } ClassBody	{goparent();$$=new Typeinfo; $$->tac=$8->tac;}		
		| OMClassModifier CLASS Identifier 											{ symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody						{goparent();$$=new Typeinfo; $$->tac=$5->tac;}							
		| OMClassModifier CLASS Identifier ClassPermits 							{ symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody			{goparent();$$=new Typeinfo; $$->tac=$6->tac;}							
		| OMClassModifier CLASS Identifier ClassImplements 							{symtable*a=createscope("class");string p=($3); insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();$$=new Typeinfo; $$->tac=$6->tac;}							
		| OMClassModifier CLASS Identifier ClassImplements ClassPermits 			{ symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  }  ClassBody		{goparent();$$=new Typeinfo; $$->tac=$7->tac;}				
		| OMClassModifier CLASS Identifier ClassExtends 							{ symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody			{goparent();$$=new Typeinfo; $$->tac=$6->tac;}							
		| OMClassModifier CLASS Identifier ClassExtends ClassPermits 				{ symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();$$=new Typeinfo; $$->tac=$7->tac;}					
		| OMClassModifier CLASS Identifier ClassExtends ClassImplements  			{ symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();$$=new Typeinfo; $$->tac=$7->tac;}				
		| OMClassModifier CLASS Identifier ClassExtends ClassImplements ClassPermits{ symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  }  ClassBody		{goparent();$$=new Typeinfo; $$->tac=$8->tac;}	
		| OMClassModifier CLASS Identifier TypeParameters  							{symtable*a=createscope("class");string p=($3); insertclass(p,"class","",a,line);    changescope(a);  } ClassBody					{goparent();$$=new Typeinfo; $$->tac=$6->tac;}					
		| OMClassModifier CLASS Identifier TypeParameters ClassPermits  			{symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody			{goparent();$$=new Typeinfo; $$->tac=$7->tac;}			
		| OMClassModifier CLASS Identifier TypeParameters ClassImplements  			{symtable*a=createscope("class");string p=($3); insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();$$=new Typeinfo; $$->tac=$7->tac;}				
		| OMClassModifier CLASS Identifier TypeParameters ClassImplements ClassPermits 		{ symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  }  ClassBody	{goparent();$$=new Typeinfo; $$->tac=$8->tac;}	
		| OMClassModifier CLASS Identifier TypeParameters ClassExtends 						{symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);     changescope(a);  }  ClassBody					{goparent();$$=new Typeinfo; $$->tac=$7->tac;}	
		| OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassPermits  		{ symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();$$=new Typeinfo; $$->tac=$8->tac;}	
		| OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassImplements  	{ symtable*a=createtable();string p=($3);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody	{goparent();$$=new Typeinfo; $$->tac=$8->tac;}	
		| OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassImplements ClassPermits  { symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody	{goparent();$$=new Typeinfo; $$->tac=$9->tac;}
		;
TypeParameters:	 LT TypeParameterList GT						{$$=new Typeinfo; $$->tac=emptyvector();}	
		;
TypeParameterList: TypeParameter								{$$=new Typeinfo; $$->tac=emptyvector();}			
		| TypeParameter OMCommaTypeParameter					{$$=new Typeinfo; $$->tac=emptyvector();}			
		;
ClassExtends:	EXTENDS Identifier										{$$=new Typeinfo; $$->tac=emptyvector();}	
		;	
ClassImplements: IMPLEMENTS InterfaceTypeList   {$$=new Typeinfo; $$->tac=emptyvector();}		
		;
InterfaceTypeList:   Identifier										{$$=new Typeinfo; $$->tac=emptyvector();}	
		|	 Identifier OMCommaInterfaceType							{$$=new Typeinfo; $$->tac=emptyvector();}	
		;

ClassPermits:   PERMITS Identifier										{$$=new Typeinfo; $$->tac=emptyvector();}	
		|	 PERMITS ExpressionName										{$$=new Typeinfo; $$->tac=emptyvector();}	
		|	 PERMITS Identifier OMCommaTypeName							{$$=new Typeinfo; $$->tac=emptyvector();}	
		|	 PERMITS ExpressionName OMCommaTypeName						{$$=new Typeinfo; $$->tac=emptyvector();}	
		;
ClassBody:	 LCB RCB													{$$=new Typeinfo; $$->tac=emptyvector();}	
		| LCB OMClassBodyDeclaration RCB							{$$=new Typeinfo; $$->tac=$2->tac;}	
		;
ClassBodyDeclaration:	 ClassMemberDeclaration							{$$=new Typeinfo; $$->tac=$1->tac;}	
		| InstanceInitializer											{$$=new Typeinfo; $$->tac=$1->tac;}	
		| StaticInitializer												{$$=new Typeinfo; $$->tac=$1->tac;}	
		| ConstructorDeclaration										{$$=new Typeinfo; $$->tac=$1->tac;}	
		;
ClassMemberDeclaration:	 FieldDeclaration								{$$=new Typeinfo; $$->tac=$1->tac;}	
		| MethodDeclaration												{$$=new Typeinfo; $$->tac=$1->tac;}	
		| ClassDeclaration												{$$=new Typeinfo; $$->tac=$1->tac;}	
		| InterfaceDeclaration											{$$=new Typeinfo; $$->tac=$1->tac;}	
		| SEMICOLON														{$$=new Typeinfo; $$->tac=emptyvector();}	
		;


FieldDeclaration:	 UnannType VariableDeclaratorList SEMICOLON     	{$$ = createstruct();($$)->variables=($2)->variables;($$)->type=($1)->type+($2)->type;for(auto z:($$)->variables)insertidentifier(z,($$)->type,"",line);($$)->puvariables=($2)->puvariables;vector<string> s = pushlocal(($2)->puvariables); $$->tac=concvector(s,$2->tac);}
		| OMClassModifier UnannType VariableDeclaratorList SEMICOLON	{$$ = createstruct();($$)->variables=($3)->variables;($$)->type=($2)->type+($3)->type;for(auto z:($$)->variables)insertidentifier(z,($$)->type,"",line);($$)->puvariables=($3)->puvariables;vector<string> s = pushlocal(($3)->puvariables); $$->tac=concvector(s,$3->tac);}
		;
VariableDeclaratorList:	 VariableDeclarator								{$$ = createstruct();($$)->variables.push_back($1->variable);($$)->type = ($1)->type;$$->decorders2.push_back(($1)->decorder2);$$->arrtypes.push_back($1->arrtype);$$->arrdims.push_back($1->arrdim);$$->initialdecls.push_back($1->initialdecl);$$->initvartypes.push_back($1->initvartype);($$)->puvariables = ($1)->puvariables;$$->tac=$1->tac;}
		| VariableDeclaratorList COMMA 	VariableDeclarator		        {$$ = createstruct();$$=$1;($$)->variables.push_back($3->variable);($$)->type = ($3)->type;$$->decorders2.push_back(($3)->decorder2);$$->arrtypes.push_back($3->arrtype);$$->arrdims.push_back($3->arrdim);$$->initialdecls.push_back($3->initialdecl);$$->initvartypes.push_back($3->initvartype);vector<string>a=($1)->puvariables;vector<string>b=($3)->puvariables;for(auto z:a){($$)->puvariables.push_back(z);}for(auto z:b){($$)->puvariables.push_back(z);} $$->tac=concvector($1->tac,$3->tac);}
		;
VariableDeclarator:	 VariableDeclaratorId								{$$ = createstruct();$$=$1;$$->initialdecl=false;($$)->puvariables = ($1)->puvariables;$$->tac=emptyvector();}
		| VariableDeclaratorId EQUAL VariableInitializer				{$$ = createstruct();$$=$1;$$->initialdecl=true;$$->arrtype=$3->arrtype;$$->arrdim=$3->arrdim;$$->initvartype=$3->initvartype;string c=$1->tempname+"="+$3->tempname;($$)->puvariables = ($1)->puvariables;$$->tac=concvector($1->tac,$3->tac,c);}		
		;
VariableDeclaratorId:  Identifier										{$$ = createstruct();string p=($1);$$->variable=p;$$->decorder2=0;string x=$1;$$->tempname=x;($$)->puvariables.push_back(x);}						
		|	 Identifier OMPSB											{$$ = createstruct();string p=($1);$$->variable=p;$$->decorder2=$2->order;string x=$1;$$->tempname=x;($$)->puvariables.push_back(x);}
		;

VariableInitializer:	 Expression								{$$ = createstruct();$$=$1;}	
		| ArrayInitializer												{$$ = createstruct();$$=$1;($$)->type = ($1)->type;$$->arrtype=$1->arrtype;$$->arrdim=$1->arrdim;$$->initvartype="";}
		;
UnannType:	 UnannPrimitiveType										{$$ = createstruct();$$=$1;($$)->type = ($1)->type;$$->dectype=$1->type;$1->decorder1=0;}					
		| Identifier												{$$ = createstruct();string p = $1;($$)->type = p;$$->tempname=p;$$->decorder1=0; $$->dectype="";}
		| UnannArrayType											{$$ = createstruct();$$=$1;($$)->type=($1)->type;$$->dectype=$1->dectype;$$->decorder1=$1->decorder1;}
		;
UnannPrimitiveType:	 NumericType				{$$ = createstruct();($$)->type = ($1)->type;$$->tac=emptyvector();}						
		| BOOLEAN														{$$ = createstruct();($$)->type = "boolean";$$->tac=emptyvector();}
		;
UnannArrayType:    UnannPrimitiveType OMPSB							{$$ = createstruct();($$)->type = ($1)->type + ($2)->type;$$->dectype=$1->type;$$->decorder1=$2->order;$$->tac=emptyvector();}	
		|	 Identifier OMPSB											{$$ = createstruct();string p = $1;($$)->type = p + ($2)->type;$$->dectype="";$$->decorder1=$2->order;$$->tac=emptyvector();}
		;

MethodDeclaration:	 MethodHeader MethodBody		{goparent();insertmethod(($1)->variables[0],"Method",($1)->type,($1)->type_variable,($1)->scope,"",($1)->linep);$$=new Typeinfo;string f = ($1)->tempname;string p=gotomethodretlabel(f); string z="function end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); $$->tac=concvector($1->tac,$2->tac,z,sv,p);}				
		| OMClassModifier MethodHeader MethodBody			{goparent();insertmethod(($2)->variables[0],"Method",($2)->type,($2)->type_variable,($1)->scope,"",($2)->linep);$$=new Typeinfo;string f = ($2)->tempname;string p=gotomethodretlabel(f); string z="function end"; stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st); 	currmethod.pop(); currmethodlocals.pop(); $$->tac=concvector($2->tac,$3->tac,z,sv,p);}			
		;
MethodHeader:	 Result MethodDeclarator				{$$ = createstruct();($$)->type = ($1)->type;($$)->variables = ($1)->variables;($$)->type_variable = ($2)->type_variable;($$)->scope =($1)->scope;($$)->linep = ($2)->linep;$$->tempname=($1)->tempname; string f = ($1)->tempname; string q=newmethodlabel(f);string p="call "+($1)->tempname+"\n"+q;$$->tac=concvector(p,$2->tac);}				
		| Result MethodDeclarator Throws				{$$ = createstruct();($$)->type = ($1)->type;($$)->variables = ($1)->variables;($$)->type_variable = ($2)->type_variable;($$)->scope =($1)->scope;($$)->linep = ($2)->linep;$$->tempname=($1)->tempname; string f = ($1)->tempname; string q=newmethodlabel(f);string p="call "+($1)->tempname+"\n"+q; $$->tac=concvector(p,$2->tac);}				
		| TypeParameters Result MethodDeclarator		{$$ = createstruct();($$)->type = ($2)->type;($$)->variables = ($2)->variables;($$)->type_variable = ($3)->type_variable;($$)->scope =($2)->scope;($$)->linep = ($3)->linep;$$->tempname=($2)->tempname; string f = ($2)->tempname; string q=newmethodlabel(f);string p="call "+($2)->tempname+"\n"+q; $$->tac=concvector(p,$3->tac);}			
		| TypeParameters Result MethodDeclarator Throws			{$$ = createstruct();($$)->type = ($2)->type;($$)->variables = ($2)->variables;($$)->type_variable = ($3)->type_variable;($$)->scope =($2)->scope;($$)->linep = ($3)->linep;$$->tempname=($2)->tempname; string f = ($2)->tempname; string q=newmethodlabel(f);string p="call "+($2)->tempname+"\n"+q; $$->tac=concvector(p,$3->tac);}		
		;
Result:    UnannType	Identifier							{$$ = createstruct();symtable*a = createscope("Method");($$)->scope = a; ($$)->type = ($1)->type;string p = $2;($$)->variables.push_back(p); changescope(a);string x=$2; $$->tempname=x;$$->tac=emptyvector();}						
		|	 VOID Identifier								{$$ = createstruct();symtable*a = createscope("Method");($$)->scope = a;($$)->type = "void";string p = $2;($$)->variables.push_back(p); changescope(a);string x=$2; $$->tempname=x;$$->tac=emptyvector();}			
		;

MethodDeclarator: LRB RRB							{$$ = createstruct();($$)->type_variable.push_back("void");($$)->linep = line; $$->tac=emptyvector();}				
		| LRB RRB OMPSB													{$$ = createstruct(); $$->tac=emptyvector();}
		| LRB FormalParameterList RRB				{$$ = createstruct();($$)->type_variable = ($2)->type_variable;($$)->linep = line;$$->tac=$2->tac;}					
		| LRB FormalParameterList RRB OMPSB						{$$ = createstruct();$$->tac=$2->tac;}		
		| LRB ReceiverParameterComma RRB						{$$=new Typeinfo;$$->tac=$2->tac;}
		| LRB ReceiverParameterComma RRB OMPSB				{$$=new Typeinfo;$$->tac=$2->tac;}	
		| LRB ReceiverParameterComma FormalParameterList RRB			{$$ = createstruct();($$)->type_variable = ($3)->type_variable;($$)->linep = line;$$->tac=$3->tac;}
		| LRB ReceiverParameterComma FormalParameterList RRB OMPSB	{$$=new Typeinfo;$$->tac=$3->tac;}
		;
ReceiverParameter:	 UnannType THIS									{$$=new Typeinfo; $$->tac=emptyvector();}		
		| UnannType IdentifierDot THIS								{$$=new Typeinfo; $$->tac=emptyvector();}		
		;
FormalParameterList: FormalParameter								{$$ = createstruct();($$)->type_variable = ($1)->type_variable;$$->tac=$1->tac;}
		| FormalParameter OMCommaFormalParameter					{$$ = createstruct();vector<string>a=($1)->type_variable;vector<string>b=($2)->type_variable;for(auto z:a){($$)->type_variable.push_back(z);}for(auto z:b){($$)->type_variable.push_back(z);}$$->tac=concvector($1->tac,$2->tac);}	
		;
FormalParameter: UnannType VariableDeclaratorId							{$$ = createstruct();($$)->type_variable.push_back(($1)->type+($2)->type);($$)->type=($1)->type+($2)->type;for(auto z:($2)->variables)insertidentifier(z,($$)->type,"",line);$$->tac=$2->tac;}
		| OMClassModifier UnannType VariableDeclaratorId				{$$ = createstruct();($$)->type_variable.push_back(($2)->type+($3)->type);($$)->type=($2)->type+($3)->type;for(auto z:($3)->variables)insertidentifier(z,($$)->type,"",line);$$->tac=$3->tac;}	
		| VariableArityParameter										{$$ = createstruct();($$)->type_variable = ($1)->type_variable;$$->tac=$1->tac;}
		;
VariableArityParameter:   UnannType THREEDOT Identifier				{$$ = createstruct();($$)->type_variable.push_back(($1)->type);$$->tac=emptyvector();}
		|	 OMClassModifier UnannType THREEDOT Identifier			{$$ = createstruct();($$)->type_variable.push_back(($2)->type);$$->tac=emptyvector();}
		;
Throws:	 THROWS ExceptionTypeList									{$$=new Typeinfo; $$->tac=emptyvector();}	
		;
ExceptionTypeList:	 ExceptionType									{$$=new Typeinfo; $$->tac=emptyvector();}
		| ExceptionType OMCommaExceptionType			{$$=new Typeinfo; $$->tac=emptyvector();}
		;
ExceptionType:   Identifier										{$$=new Typeinfo; $$->tac=emptyvector();}
		;

MethodBody:	 Block													{$$=new Typeinfo; $$->tac=$1->tac;}		
		| SEMICOLON													{$$=new Typeinfo; $$->tac=emptyvector();}	
		;	
InstanceInitializer:	 Block										{$$=new Typeinfo; $$->tac=$1->tac;}		
		;
StaticInitializer:	 STATIC Block                           {$$=new Typeinfo; $$->tac=$2->tac;}	
		;	

ConstructorDeclaration:	 ConstructorDeclarator ConstructorBody			{goparent();insertmethod(($1)->variables[0],"constructor",($1)->type,($1)->type_variable,($1)->scope,"",($1)->linep);$$=new Typeinfo;string f = ($1)->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); $$->tac=concvector($1->tac,$2->tac,z,sv,p);}
		| ConstructorDeclarator Throws ConstructorBody				{goparent();insertmethod(($1)->variables[0],"constructor",($1)->type,($1)->type_variable,($1)->scope,"",($1)->linep);$$=new Typeinfo;string f = ($1)->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); $$->tac=concvector($1->tac,$3->tac,z,sv,p);}
		| OMClassModifier ConstructorDeclarator ConstructorBody			{goparent();insertmethod(($2)->variables[0],"constructor",($2)->type,($2)->type_variable,($2)->scope,"",($2)->linep);$$=new Typeinfo;string f = ($2)->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); $$->tac=concvector($2->tac,$3->tac,z,sv,p);}
		| OMClassModifier ConstructorDeclarator Throws ConstructorBody	{goparent();insertmethod(($2)->variables[0],"constructor",($2)->type,($2)->type_variable,($2)->scope,"",($2)->linep);$$=new Typeinfo;string f = ($2)->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); $$->tac=concvector($2->tac,$4->tac,z,sv,p);}
		;
ConstructorDeclaratorLRBSym: LRB {$$ = createstruct();symtable*a = createscope("constructor");($$)->scope = a; changescope(a);}
		;
ConstructorDeclarator:   Identifier ConstructorDeclaratorLRBSym RRB							{$$ = createstruct();($$)->scope = ($2)->scope; ($$)->type_variable.push_back("void");string p = $1;($$)->variables.push_back(p);($$)->type = "void";($$)->linep = line;string x = $1;$$->tempname=x;  string q=newmethodlabel(x);string g="call "+x+"\n"+q;$$->tac=concvector(g);}						
		|	 Identifier ConstructorDeclaratorLRBSym FormalParameterList RRB								{$$ = createstruct();($$)->scope = ($2)->scope;($$)->type_variable = ($3)->type_variable;string p = $1;($$)->variables.push_back(p);($$)->type = "void";($$)->linep = line;string x = $1;$$->tempname=x;  string q=newmethodlabel(x);string g="call "+x+"\n"+q;$$->tac=concvector(g,$3->tac);}				
		|	 Identifier LRB ReceiverParameterComma RRB										{$$ = createstruct();$$->tac=emptyvector();}
		|	 Identifier LRB ReceiverParameterComma FormalParameterList RRB					{$$ = createstruct();$$->tac=$4->tac;}
		|	 TypeParameters Identifier ConstructorDeclaratorLRBSym RRB								{$$ = createstruct();($$)->scope = ($3)->scope;($$)->type_variable.push_back("void");string p = $2; ($$)->variables.push_back(p);($$)->type = "void";($$)->linep = line;string x = $2;$$->tempname=x;  string q=newmethodlabel(x);string g="call "+x+"\n"+q;$$->tac=concvector(g);}				
		|	 TypeParameters Identifier ConstructorDeclaratorLRBSym FormalParameterList RRB			{$$ = createstruct();($$)->scope = ($3)->scope;($$)->type_variable = ($4)->type_variable;string p = $2;($$)->variables.push_back(p);($$)->type = "void";($$)->linep = line;string x = $2;$$->tempname=x;  string q=newmethodlabel(x);string g="call "+x+"\n"+q;$$->tac=concvector(g,$4->tac);}					
		|	 TypeParameters Identifier LRB ReceiverParameterComma RRB						{$$=new Typeinfo; $$->tac=emptyvector();}	
		|	 TypeParameters Identifier LRB ReceiverParameterComma FormalParameterList RRB		{$$=new Typeinfo;$$->tac=$4->tac;}	
		;

ConstructorBody: LCB RCB												{$$=new Typeinfo; $$->tac=emptyvector();}	
		| LCB BlockStatements RCB									{$$=new Typeinfo;$$->tac=$2->tac;}	
		| LCB ExplicitConstructorInvocation RCB						{$$=new Typeinfo;$$->tac=$2->tac;}	
		| LCB ExplicitConstructorInvocation BlockStatements RCB			{$$=new Typeinfo; $$->tac=concvector($2->tac,$3->tac);}	
		;
ExplicitConstructorInvocation:	 THIS LRB RRB SEMICOLON							{$$=new Typeinfo;vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters();string s = ($1);($$)->tempname = "%rax";string s1 = gotomethod(s);string s2 = newmethodretlabel(s); $$->tac=concvector(pv1,s1,s2,pv2);}			
		| THIS LRB ArgumentList RRB SEMICOLON								{$$=new Typeinfo;vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters(); string s = ($1);($$)->tempname = "%rax"; string s1 = gotomethod(s);string s2 = newmethodretlabel(s);vector<string> pushpar = pusharg(($3)->params);$$->tac=concvector(pv1,$3->tac,pushpar,s1,s2,pv2);}	
		| SUPER LRB RRB SEMICOLON													{$$=new Typeinfo; $$->tac=emptyvector();}	
		| SUPER LRB ArgumentList RRB SEMICOLON									{$$=new Typeinfo;$$->tac=$3->tac;}
		| Identifier DOT SUPER LRB RRB SEMICOLON									{$$=new Typeinfo; $$->tac=emptyvector();}	
		| Identifier DOT SUPER LRB ArgumentList RRB SEMICOLON					{$$=new Typeinfo;$$->tac=$5->tac;}	
		| ExpressionName DOT SUPER LRB RRB SEMICOLON								{$$=new Typeinfo; $$->tac=emptyvector();}	
		| ExpressionName DOT SUPER LRB ArgumentList RRB SEMICOLON					{$$=new Typeinfo;$$->tac=$5->tac;}	
		| Primary DOT SUPER LRB RRB SEMICOLON										{$$=new Typeinfo; $$->tac=emptyvector();}	
		| Primary DOT SUPER LRB ArgumentList RRB SEMICOLON							{$$=new Typeinfo;$$->tac=$5->tac;}	
		;
EnumDeclaration:    ENUM Identifier    EnumBody								{$$=new Typeinfo;$$->tac=$3->tac;}	
		|	 ENUM Identifier ClassImplements     EnumBody					{$$=new Typeinfo;$$->tac=$4->tac;}		
		|	 OMClassModifier ENUM Identifier     EnumBody					{$$=new Typeinfo;$$->tac=$4->tac;}		
		|	 OMClassModifier ENUM Identifier ClassImplements    EnumBody		{$$=new Typeinfo;$$->tac=$5->tac;}	
		;

EnumBody:	 LCB RCB											{$$=new Typeinfo; $$->tac=emptyvector();}			
		| LCB EnumBodyDeclarations RCB							{$$=new Typeinfo;$$->tac=$2->tac;}		
		| LCB COMMA RCB											{$$=new Typeinfo; $$->tac=emptyvector();}			
		| LCB COMMA EnumBodyDeclarations RCB					{$$=new Typeinfo;$$->tac=$3->tac;}		
		| LCB EnumConstantList RCB									{$$=new Typeinfo;$$->tac=$2->tac;}		
		| LCB EnumConstantList EnumBodyDeclarations RCB				{$$=new Typeinfo;$$->tac=concvector($2->tac,$3->tac);}	
		;
EnumConstantList:	 EnumConstant									{$$=new Typeinfo;$$->tac=$1->tac;}	
		| OMCommaEnumConstant											{$$=new Typeinfo;$$->tac=$1->tac;}
		;
PRB:	LRB RRB															{$$=new Typeinfo;$$->tac=emptyvector();}
		;
PRBArgumentList: LRB ArgumentList RRB									{$$=new Typeinfo;$$->tac=$2->tac;}
		;
EnumConstant:  Identifier												{$$=new Typeinfo; $$->tac=emptyvector();}	
		|	 Identifier PRB												{$$=new Typeinfo; $$->tac=emptyvector();}	
		|	 Identifier PRBArgumentList									{$$=new Typeinfo;$$->tac=$2->tac;}	
		|	 Identifier ClassBody										{$$=new Typeinfo;$$->tac=$2->tac;}	
		|	 Identifier PRB ClassBody									{$$=new Typeinfo;$$->tac=$3->tac;}	
		|	 Identifier PRBArgumentList ClassBody						{$$=new Typeinfo;$$->tac=concvector($2->tac,$3->tac);}		
		;
EnumBodyDeclarations: SEMICOLON											{$$=new Typeinfo; $$->tac=emptyvector();}	
		| SEMICOLON OMClassBodyDeclaration									{$$=new Typeinfo;$$->tac=$2->tac;}	
		;
RecordDeclarationSym: RECORD Identifier {$$ = createstruct();symtable*a=createscope("record");($$)->scope = a; ($$)->type = "record";string p = $2;($$)->variables.push_back(p); changescope(a);}
		;
RecordDeclaration:    RecordDeclarationSym RecordHeader RecordBody					{goparent();insertmethod(($1)->variables[0],"record",($1)->type,($2)->type_variable,($1)->scope,"",($2)->linep);$$=new Typeinfo;$$->tac=concvector($2->tac,$3->tac);}										
		|	 RecordDeclarationSym RecordHeader ClassImplements RecordBody					{goparent();insertmethod(($1)->variables[0],"record",($1)->type,($2)->type_variable,($1)->scope,"",($2)->linep);$$=new Typeinfo;$$->tac=concvector($2->tac,$4->tac);}						
		|	 RecordDeclarationSym TypeParameters RecordHeader RecordBody									{goparent();insertmethod(($1)->variables[0],"record",($1)->type,($3)->type_variable,($1)->scope,"",($3)->linep);$$=new Typeinfo;$$->tac=concvector($3->tac,$4->tac);}		
		|	 RecordDeclarationSym TypeParameters RecordHeader ClassImplements RecordBody			{goparent();insertmethod(($1)->variables[0],"record",($1)->type,($3)->type_variable,($1)->scope,"",($3)->linep);$$=new Typeinfo;$$->tac=concvector($3->tac,$5->tac);}				
		|	 OMClassModifier RecordDeclarationSym RecordHeader RecordBody									{goparent();insertmethod(($2)->variables[0],"record",($2)->type,($3)->type_variable,($2)->scope,"",($3)->linep);$$=new Typeinfo;$$->tac=concvector($3->tac,$4->tac);}		
		|	 OMClassModifier RecordDeclarationSym RecordHeader ClassImplements RecordBody		{goparent();insertmethod(($2)->variables[0],"record",($2)->type,($3)->type_variable,($2)->scope,"",($3)->linep);$$=new Typeinfo;$$->tac=concvector($3->tac,$5->tac);}					
		|	 OMClassModifier RecordDeclarationSym TypeParameters RecordHeader RecordBody		{goparent();insertmethod(($2)->variables[0],"record",($2)->type,($4)->type_variable,($2)->scope,"",($4)->linep);$$=new Typeinfo;$$->tac=concvector($4->tac,$5->tac);}					
		|	 OMClassModifier RecordDeclarationSym TypeParameters RecordHeader ClassImplements RecordBody	{goparent();insertmethod(($2)->variables[0],"record",($2)->type,($4)->type_variable,($2)->scope,"",($4)->linep);$$=new Typeinfo;$$->tac=concvector($4->tac,$6->tac);}		
		;

RecordHeader:	 LRB RRB										{$$ = createstruct();($$)->type_variable.push_back("void");($$)->linep = line;$$->tac=emptyvector();}			
		| LRB RecordComponentList RRB					{$$ = createstruct();($$)->type_variable = ($2)->type_variable;($$)->linep = line;$$->tac=$2->tac;}								
		;
RecordComponentList:  RecordComponent							{$$ = createstruct();($$)->type_variable = ($1)->type_variable;$$->tac=$1->tac;}			
		| RecordComponent OMCommaRecordComponent			{$$ = createstruct();vector<string>a=($1)->type_variable;vector<string>b=($2)->type_variable;for(auto z:a){($$)->type_variable.push_back(z);}for(auto z:b){($$)->type_variable.push_back(z);}$$->tac=concvector($1->tac,$2->tac);}					
		;
RecordComponent:    UnannType Identifier					{$$ = createstruct();($$)->type_variable.push_back(($1)->type);}				
		|	 VariableArityRecordComponent								{$$ = createstruct();($$)->type_variable = ($1)->type_variable;}	
		;

VariableArityRecordComponent:    UnannType THREEDOT Identifier					{$$ = createstruct();($$)->type_variable.push_back(($1)->type);$$->tac=emptyvector();}	
		;
RecordBody:	 LCB RCB													{$$=new Typeinfo;$$->tac=emptyvector();}
		| LCB OMRecordBodyDeclaration RCB						{$$=new Typeinfo;$$->tac=$2->tac;}	
		;
RecordBodyDeclaration:	 ClassBodyDeclaration							{$$=new Typeinfo;$$->tac=$1->tac;}		
		| CompactConstructorDeclaration									{$$=new Typeinfo;$$->tac=$1->tac;}		
		;
CompactConstructorDeclarationSym: Identifier {vector<string>tec; symtable*a=createscope("compactconstructor");string p=($1);insertmethod(p,"compactconstructor","auto",tec,a,"",line);changescope(a);}
		;
CompactConstructorDeclaration:	CompactConstructorDeclarationSym	ConstructorBody			{goparent();$$=new Typeinfo;$$->tac=$2->tac;}
		|	 OMClassModifier CompactConstructorDeclarationSym ConstructorBody					{goparent();$$=new Typeinfo;$$->tac=$3->tac;}
		;

InterfaceDeclaration:	 NormalInterfaceDeclaration						{$$=new Typeinfo;$$->tac=$1->tac;}	
		;
NormalInterfaceDeclaration:   INTERFACE Identifier    {symtable*a=createscope("interface");string p=($2);insertclass(p,"interface","",a,line);changescope(a);}  InterfaceBody		{goparent();$$=new Typeinfo;$$->tac=$4->tac;}												
		|	 INTERFACE Identifier InterfacePermits    {symtable*a=createscope("interface");string p=($2);insertclass(p,"interface","",a,line);changescope(a);}    InterfaceBody		{goparent();$$=new Typeinfo;$$->tac=$5->tac;}								
		|	 INTERFACE Identifier InterfaceExtends   {symtable*a=createscope("interface");string p=($2);insertclass(p,"interface","",a,line);changescope(a);}    InterfaceBody		{goparent();$$=new Typeinfo;$$->tac=$5->tac;}							
		|	 INTERFACE Identifier InterfaceExtends InterfacePermits  {symtable*a=createscope("interface");string p=($2);insertclass(p,"interface","",a,line);changescope(a);}    InterfaceBody		{goparent();$$=new Typeinfo;$$->tac=$6->tac;}									
		|	 INTERFACE Identifier TypeParameters    {symtable*a=createscope("interface");string p=($2);insertclass(p,"interface","",a,line);changescope(a);}   InterfaceBody					{goparent();$$=new Typeinfo;$$->tac=$5->tac;}									
		|	 INTERFACE Identifier TypeParameters InterfacePermits   {symtable*a=createscope("interface");string p=($2);insertclass(p,"interface","",a,line);changescope(a);}    InterfaceBody		{goparent();$$=new Typeinfo;$$->tac=$6->tac;}										
		|	 INTERFACE Identifier TypeParameters InterfaceExtends    {symtable*a=createscope("interface");string p=($2);insertclass(p,"interface","",a,line);changescope(a);}  InterfaceBody			{goparent();$$=new Typeinfo;$$->tac=$6->tac;}								
		|	 INTERFACE Identifier TypeParameters InterfaceExtends InterfacePermits    {symtable*a=createscope("interface");string p=($2);insertclass(p,"interface","",a,line);changescope(a);}   InterfaceBody			{goparent();$$=new Typeinfo;$$->tac=$7->tac;}			
		|	 OMClassModifier INTERFACE Identifier   {symtable*a=createscope("interface");string p=($3);insertclass(p,"interface","",a,line);changescope(a);}  InterfaceBody								{goparent();$$=new Typeinfo;$$->tac=$5->tac;}						
		|	 OMClassModifier INTERFACE Identifier InterfacePermits    {symtable*a=createscope("interface");string p=($3);insertclass(p,"interface","",a,line);changescope(a);}    InterfaceBody				{goparent();$$=new Typeinfo;$$->tac=$6->tac;}						
		|	 OMClassModifier INTERFACE Identifier InterfaceExtends   {symtable*a=createscope("interface");string p=($3);insertclass(p,"interface","",a,line);changescope(a);}   InterfaceBody				{goparent();$$=new Typeinfo;$$->tac=$6->tac;}						
		|	 OMClassModifier INTERFACE Identifier InterfaceExtends InterfacePermits    {symtable*a=createscope("interface");string p=($3);insertclass(p,"interface","",a,line);changescope(a);}   InterfaceBody	{goparent();$$=new Typeinfo;$$->tac=$7->tac;}						
		|	 OMClassModifier INTERFACE Identifier TypeParameters   {symtable*a=createscope("interface");string p=($3);insertclass(p,"interface","",a,line);changescope(a);}  InterfaceBody			{goparent();$$=new Typeinfo;$$->tac=$6->tac;}									
		|	 OMClassModifier INTERFACE Identifier TypeParameters InterfacePermits    {symtable*a=createscope("interface");string p=($3);insertclass(p,"interface","",a,line);changescope(a);}   InterfaceBody		{goparent();$$=new Typeinfo;$$->tac=$7->tac;}	
		|	 OMClassModifier INTERFACE Identifier TypeParameters InterfaceExtends    {symtable*a=createscope("interface");string p=($3);insertclass(p,"interface","",a,line);changescope(a);}   InterfaceBody		{goparent();$$=new Typeinfo;$$->tac=$7->tac;}					
		|	 OMClassModifier INTERFACE Identifier TypeParameters InterfaceExtends InterfacePermits   {symtable*a=createscope("interface");string p=($3);insertclass(p,"interface","",a,line);changescope(a);}   InterfaceBody		{goparent();$$=new Typeinfo;$$->tac=$8->tac;}	
		;

InterfaceModifier:	 Modifieropt							{$$=new Typeinfo;$$->tac=$1->tac;}			
		;
InterfaceExtends:	 EXTENDS InterfaceTypeList					{$$=new Typeinfo;$$->tac=$2->tac;}		
		;
InterfacePermits:	 PERMITS ExpressionName							{$$=new Typeinfo;$$->tac=$2->tac;}
		| PERMITS ExpressionName OMCommaTypeName					{$$=new Typeinfo;$$->tac=concvector($2->tac,$3->tac);}	
		;
InterfaceBody:	 LCB RCB												{$$=new Typeinfo;$$->tac=emptyvector();}
		| LCB OMInterfaceMemberDeclaration RCB							{$$=new Typeinfo;$$->tac=$2->tac;}
		;
InterfaceMemberDeclaration:	 ConstantDeclaration						{$$=new Typeinfo;$$->tac=$1->tac;}	
		| InterfaceMethodDeclaration									{$$=new Typeinfo;$$->tac=$1->tac;}	
		| ClassDeclaration												{$$=new Typeinfo;$$->tac=$1->tac;}	
		| InterfaceDeclaration										{$$=new Typeinfo;$$->tac=$1->tac;}	
		| SEMICOLON														{$$=new Typeinfo;$$->tac=emptyvector();}
		;
ConstantDeclaration:	 UnannType VariableDeclaratorList SEMICOLON		{$$=new Typeinfo;($$)->puvariables=($2)->puvariables;vector<string> s = pushlocal(($2)->puvariables); $$->tac=concvector(s,$2->tac);vector<string>a=($2)->variables;($$)->type=($1)->type+($2)->type;for(auto z:a){insertidentifier(z,($1)->type,"",line);}}
		| OMClassModifier UnannType VariableDeclaratorList SEMICOLON	{$$=new Typeinfo;($$)->puvariables=($3)->puvariables;vector<string> s = pushlocal(($3)->puvariables); $$->tac=concvector(s,$3->tac);vector<string>a=($3)->variables;($$)->type=($2)->type+($3)->type;for(auto z:a){insertidentifier(z,($2)->type,"",line);}}
		;
InterfaceMethodDeclaration:	 MethodHeader MethodBody			{$$=new Typeinfo;string f = ($1)->tempname;string p=gotomethodretlabel(f); string z="function end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); $$->tac=concvector($1->tac,$2->tac,z,sv,p);}
		| OMClassModifier MethodHeader MethodBody			{$$=new Typeinfo;string f = ($2)->tempname;string p=gotomethodretlabel(f); string z="function end"; stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st); 	currmethod.pop(); currmethodlocals.pop(); $$->tac=concvector($2->tac,$3->tac,z,sv,p);}
		;
ArrayInitializer:	 LCB RCB												{$$ = createstruct();($$)->type = "[]";$$->tac=emptyvector();}
		| LCB COMMA RCB														{$$ = createstruct();($$)->type = "[]";$$->tac=emptyvector();}
		| LCB VariableInitializerList RCB								{$$ = createstruct();($$)->type =  ($2)->type + "[]";$$->tac=$2->tac;}	
		;
// VariableInitializerList:	 VariableInitializer						{$$ = createstruct();($$)->type =  ($1)->type ;$$->tac=$1->tac;}	
// 		| VariableInitializer OMCommaVariableInitializer			{$$ = createstruct();($$)->type =  ($1)->type; $$->tac= concvector($1->tac,$2->tac);}		
// 		;
VariableInitializerList: VariableInitializer								{$$ = createstruct();($$)->type =  ($1)->type ;$$->tac=$1->tac;}
		| VariableInitializer COMMA VariableInitializerList					{$$ = createstruct();($$)->type =  ($1)->type; $$->tac= concvector($1->tac,$3->tac);}
		;
Block:	 LCB RCB										{$$=new Typeinfo;vector<string>p={}; $$->tac=p;}				
		| LCB BlockStatements RCB 		{$$=new Typeinfo; $$->tac= $2->tac;}							
		;
BlockStatements:	 BlockStatement							{$$=new Typeinfo; $$->tac= $1->tac;}					
		| BlockStatement OMBlockStatement						   {$$=new Typeinfo; $$->tac= concvector($1->tac,$2->tac);}				
		;
BlockStatement:	 LocalClassOrInterfaceDeclaration					{$$=new Typeinfo; $$->tac= $1->tac;}			
		| LocalVariableDeclarationStatement									{$$=new Typeinfo; $$->tac= $1->tac;}	
		| Statement															{$$=new Typeinfo; $$->tac= $1->tac;}	
		;
LocalClassOrInterfaceDeclaration:	 ClassDeclaration						{$$=new Typeinfo; $$->tac= $1->tac;}	
		| NormalInterfaceDeclaration										{$$=new Typeinfo; $$->tac= $1->tac;}	
		;
LocalVariableDeclarationStatement:	 LocalVariableDeclaration SEMICOLON		{$$=createstruct();$$=$1;
	
    $$->tac=$1->tac;
}
		;
LocalVariableDeclaration:	 LocalVariableType VariableDeclaratorList		{$$ = createstruct();$$=$2;$$->dectype=$1->dectype;$$->decorder1=$1->decorder1;($$)->variables=($2)->variables;$$->decorders2=$2->decorders2;$$->arrtypes=$2->arrtypes;$$->arrdims=$2->arrdims;$$->initvartypes=$2->initvartypes;($$)->puvariables=($2)->puvariables;vector<string> s = pushlocal(($2)->puvariables);
 int n=($$)->variables.size();
    for(int i=0;i<n;i++){
        int order=$$->decorder1+($$->decorders2)[i];
        string x;
        if(order)
        x="array";
        else
        x="identifier";

        if(($$->initialdecls)[i]){
            insertidentifier($$->variables[i],x,$$->dectype,"",0,order,$$->arrdims[i]);
            // cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
        }
        else{
            vector<int>p(order,0);
            insertidentifier($$->variables[i],x,$$->dectype,"",0,order,p);
            // cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
        }
    }
    $$->tac=concvector(s,$2->tac);}
		| OMClassModifier LocalVariableType VariableDeclaratorList			{$$ = createstruct();$$=$3;$$->dectype=$2->dectype;$$->decorder1=$2->decorder1;($$)->variables=($3)->variables;$$->decorders2=$3->decorders2;$$->arrtypes=$3->arrtypes;$$->arrdims=$3->arrdims;$$->initvartypes=$3->initvartypes; ($$)->puvariables=($3)->puvariables;vector<string> s = pushlocal(($3)->puvariables);
        int n=($$)->variables.size();
    for(int i=0;i<n;i++){
        int order=$$->decorder1+($$->decorders2)[i];
        string x;
        if(order)
        x="array";
        else
        x="identifier";

        if(($$->initialdecls)[i]){
            insertidentifier($$->variables[i],x,$$->dectype,"",0,order,$$->arrdims[i]);
            // cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
        }
        else{
            vector<int>p(order,0);
            insertidentifier($$->variables[i],x,$$->dectype,"",0,order,p);
            // cout<<$$->variables[i]<<x<<$$->dectype<<""<<0<<order;
        }
    }
     $$->tac=concvector(s,$3->tac);}
		;
LocalVariableType:	 UnannType						{$$ = createstruct();$$->tac= $1->tac;($$)->type=($1)->type;$$->dectype=$1->dectype;$$->decorder1=$1->decorder1;}								
		| VAR										{$$ = createstruct();$$->tac= emptyvector();($$)->type="all";$$->dectype="all";$$->decorder1=0;}							
		;
Statement:	 StatementWithoutTrailingSubstatement					{$$=new Typeinfo; $$->tac= $1->tac;}		
		| LabeledStatement											{$$=new Typeinfo; $$->tac= $1->tac;}		
		| IfThenStatement											{$$=new Typeinfo; $$->tac= $1->tac;}		
		| IfThenElseStatement										{$$=new Typeinfo; $$->tac= $1->tac;}		
		| WhileStatement											{$$=new Typeinfo; $$->tac= $1->tac;}		
		| ForStatement												{$$=new Typeinfo; $$->tac= $1->tac;}		
		;
StatementNoShortIf:	 StatementWithoutTrailingSubstatement			{$$=new Typeinfo; $$->tac= $1->tac;}		
		| LabeledStatementNoShortIf									{$$=new Typeinfo; $$->tac= $1->tac;}		
		| IfThenElseStatementNoShortIf                              {$$=new Typeinfo; $$->tac= $1->tac;}
		| WhileStatementNoShortIf                                   {$$=new Typeinfo; $$->tac= $1->tac;}
		| ForStatementNoShortIf											{$$=new Typeinfo; $$->tac= $1->tac;}
		;
StatementWithoutTrailingSubstatement:	{symtable *a = createscope("statement");insertclass("statement","statement","",a,line); changescope(a);flag = 0;} Block		{goparent();$$=new Typeinfo; $$->tac= $2->tac;}					
		| EmptyStatement				{$$=new Typeinfo; $$->tac= $1->tac;}									
		| ExpressionStatement						{$$=new Typeinfo; $$->tac= $1->tac;}
		| AssertStatement							{$$=new Typeinfo; $$->tac= $1->tac;}
		| SwitchStatement							{$$=new Typeinfo; $$->tac= $1->tac;}
		| DoStatement								{$$=new Typeinfo; $$->tac= $1->tac;}
		| BreakStatement							{$$=new Typeinfo; $$->tac= $1->tac;}
		| ContinueStatement							{$$=new Typeinfo; $$->tac= $1->tac;}
		| ReturnStatement							{$$=new Typeinfo; $$->tac= $1->tac;}
		| SynchronizedStatement						{$$=new Typeinfo; $$->tac= $1->tac;}
		| ThrowStatement							{$$=new Typeinfo; $$->tac= $1->tac;}
		| TryStatement								{$$=new Typeinfo; $$->tac= $1->tac;}
		| YieldStatement							{$$=new Typeinfo; $$->tac= $1->tac;}
		;
EmptyStatement:	 SEMICOLON											{$$=new Typeinfo; vector<string>p={}; $$->tac=p;}	
		;
LabeledStatement:   Identifier COLON Statement				{$$=new Typeinfo; $$->tac= $3->tac;}		
		;
LabeledStatementNoShortIf:   Identifier COLON StatementNoShortIf		{$$=new Typeinfo; $$->tac= $3->tac;}
		;

ExpressionStatement:  StatementExpression SEMICOLON					{$$=new Typeinfo; $$->tac=$1->tac;$$->tempname=$1->tempname;}			
		;
StatementExpression:	 Assignment								{$$=new Typeinfo; $$->tac=$1->tac;$$->tempname=$1->tempname;}		
		| PreIncrementExpression		{$$=new Typeinfo; $$->tac=$1->tac;$$->tempname=$1->tempname;}									
		| PreDecrementExpression	{$$=new Typeinfo; $$->tac=$1->tac;$$->tempname=$1->tempname;}										
		| PostIncrementExpression	{$$=new Typeinfo; $$->tac=$1->tac;$$->tempname=$1->tempname;}										
		| PostDecrementExpression	{$$=new Typeinfo; $$->tac=$1->tac;$$->tempname=$1->tempname;}										
		| MethodInvocation			{$$=new Typeinfo; $$->tac=$1->tac;$$->tempname=$1->tempname;}										
		| ClassInstanceCreationExpression		{$$=new Typeinfo; $$->tac=$1->tac;$$->tempname=$1->tempname;}						
		;
IfThenStatement: IF LRB Expression RRB Statement		{$$=new Typeinfo;int lv=labelvariable;string a=newlabel();string ret="if zero "+($3)->tempname+gotoo(lv+1);$$->tac=concvector($3->tac,ret,$5->tac,a);}
		;
IfThenElseStatement: IF LRB Expression RRB StatementNoShortIf  ELSE Statement {$$=new Typeinfo;int lv=labelvariable;string a=newlabel();string ret="if zero "+($3)->tempname+gotoo(lv+1);$$->tac=concvector($3->tac,ret,$5->tac,a,$7->tac);}
		;
IfThenElseStatementNoShortIf:	 IF LRB Expression RRB StatementNoShortIf  ELSE StatementNoShortIf	{$$=new Typeinfo;int lv=labelvariable;string a=newlabel();string ret="if zero "+($3)->tempname+gotoo(lv+1);$$->tac=concvector($3->tac,ret,$5->tac,a,$7->tac);}
		;
AssertStatement:	 ASSERT Expression SEMICOLON							{$$=new Typeinfo; $$->tac=$2->tac;}	
		| ASSERT Expression COLON Expression SEMICOLON					{$$=new Typeinfo; $$->tac= concvector($2->tac,$4->tac);}			
		;
SwitchStatement:	 SWITCH LRB Expression RRB {symtable *a = createscope("switch"); changescope(a);} SwitchBlock		{goparent();$$=new Typeinfo; $$->tac= concvector($3->tac,$6->tac);}					
		;
SwitchBlock:	 LCB SwitchRule RCB													{$$=new Typeinfo; $$->tac=$2->tac;}		
		| LCB SwitchRule OMSwitchRule RCB											{$$=new Typeinfo; $$->tac= concvector($2->tac,$3->tac);}
		| LCB RCB																	{$$=new Typeinfo; $$->tac=emptyvector();}											
		| LCB OMSwitchLabelColon RCB												{$$=new Typeinfo; $$->tac=$2->tac;}	
		| LCB OMSwitchBlockStatementGroup RCB										{$$=new Typeinfo; $$->tac=$2->tac;}	
		| LCB OMSwitchBlockStatementGroup OMSwitchLabelColon RCB			{$$=new Typeinfo; $$->tac= concvector($2->tac,$3->tac);}	
		;
SwitchRule:	 SwitchLabel IMPLIES Expression SEMICOLON								{$$=new Typeinfo; $$->tac= concvector($1->tac,$3->tac);}
		| SwitchLabel IMPLIES Block													{$$=new Typeinfo; $$->tac= concvector($1->tac,$3->tac);}
		| SwitchLabel IMPLIES ThrowStatement										{$$=new Typeinfo; $$->tac= concvector($1->tac,$3->tac);}
		;
SwitchBlockStatementGroup:	 SwitchLabel COLON BlockStatements						{$$=new Typeinfo; $$->tac= concvector($1->tac,$3->tac);}
		| SwitchLabel COLON OMSwitchLabelColon BlockStatements					{$$=new Typeinfo; $$->tac= concvector($1->tac,$3->tac,$4->tac);}
		;
SwitchLabel:	 CASE CaseConstant												{$$=new Typeinfo; $$->tac=$2->tac;}		
		| CASE CaseConstant OMCommaCaseConstant							{$$=new Typeinfo; $$->tac= concvector($2->tac,$3->tac);}			
		| DEFAULT																	{$$=new Typeinfo; $$->tac=emptyvector();}	
		;
CaseConstant:	 ConditionalExpression									{$$=new Typeinfo; $$->tac=$1->tac;}					
		;		
WhileStatement:	 WHILE LRB Expression RRB Statement						{$$=new Typeinfo; int c=labelvariable; string a=newlabel();string b=newlabel();string z=gotoo(c+2);string d="if zero "+(($3)->tempname)+z;$$->tac=concvector($3->tac,a,d,$5->tac,gotoo(c+1),b);}													
		;
WhileStatementNoShortIf:	 WHILE LRB Expression RRB StatementNoShortIf		{$$=new Typeinfo; int c=labelvariable; string a=newlabel();string z=gotoo(c+2);string b=newlabel();string d="if zero "+(($3)->tempname)+z;$$->tac=concvector($3->tac,a,d,$5->tac,gotoo(c+1),b);}
		;
DoStatement:	 DO  Statement WHILE LRB Expression RRB SEMICOLON				{$$=new Typeinfo; string p=gotoo(labelvariable); $$->tac=concvector($5->tac,p);}		
		;
ForStatement:	 BasicForStatement									{$$=new Typeinfo; $$->tac= $1->tac;}					
		| EnhancedForStatement										{$$=new Typeinfo; $$->tac= $1->tac;}	
		;
ForStatementNoShortIf:	 BasicForStatementNoShortIf					{$$=new Typeinfo; $$->tac= $1->tac;}	
		| EnhancedForStatementNoShortIf								{$$=new Typeinfo; $$->tac= $1->tac;}	
		;
ForSym:	FOR	{symtable*a=createscope("for");insertclass("for","for","",a,line); changescope(a);}
		;
BasicForStatement:	 ForSym LRB SEMICOLON SEMICOLON RRB Statement		{goparent();$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();$$->tac=concvector(a,$6->tac,gotoo(lv+1),b);}				
		| ForSym LRB SEMICOLON SEMICOLON ForUpdate RRB Statement						{goparent();$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();$$->tac=concvector(a,$7->tac,$5->tac,gotoo(lv+1),b);}		
		| ForSym LRB SEMICOLON Expression SEMICOLON RRB Statement						{goparent();$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($4)->tempname+gotoo(lv+2);$$->tac=concvector(a,$4->tac,ret,$7->tac,gotoo(lv+1),b);}		
		| ForSym LRB SEMICOLON Expression SEMICOLON ForUpdate RRB Statement		{goparent();$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($4)->tempname+gotoo(lv+2);$$->tac=concvector(a,$4->tac,ret,$8->tac,$6->tac,gotoo(lv+1),b);}			
		| ForSym LRB ForInit SEMICOLON SEMICOLON RRB Statement							{goparent();$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();$$->tac=concvector($3->tac,a,$7->tac,gotoo(lv+1),b);}		
		| ForSym LRB ForInit SEMICOLON SEMICOLON ForUpdate RRB Statement				{goparent();$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();$$->tac=concvector($3->tac,a,$8->tac,$6->tac,gotoo(lv+1),b);}		
		| ForSym LRB ForInit SEMICOLON Expression SEMICOLON RRB Statement				{goparent();$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($5)->tempname+gotoo(lv+2);$$->tac=concvector($3->tac,a,$5->tac,ret,$8->tac,gotoo(lv+1),b);}		
		| ForSym LRB ForInit SEMICOLON Expression SEMICOLON ForUpdate RRB Statement	{goparent();$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($5)->tempname+gotoo(lv+2);$$->tac=concvector($3->tac,a,$5->tac,ret,$9->tac,$7->tac,gotoo(lv+1),b);}		
		;
BasicForStatementNoShortIf:	 ForSym LRB SEMICOLON SEMICOLON RRB StatementNoShortIf	{goparent();$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();$$->tac=concvector(a,$6->tac,gotoo(lv+1),b);}				
		| ForSym LRB SEMICOLON SEMICOLON ForUpdate RRB StatementNoShortIf						{goparent();$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();$$->tac=concvector(a,$7->tac,$5->tac,gotoo(lv+1),b);}		
		| ForSym LRB SEMICOLON Expression SEMICOLON RRB StatementNoShortIf						{goparent();$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($4)->tempname+gotoo(lv+2);$$->tac=concvector(a,$4->tac,ret,$7->tac,gotoo(lv+1),b);}		
		| ForSym LRB SEMICOLON Expression SEMICOLON ForUpdate RRB StatementNoShortIf			{goparent();$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($4)->tempname+gotoo(lv+2);$$->tac=concvector(a,$4->tac,ret,$8->tac,$6->tac,gotoo(lv+1),b);}		
		| ForSym LRB ForInit SEMICOLON SEMICOLON RRB StatementNoShortIf						{goparent();$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();$$->tac=concvector($3->tac,a,$7->tac,gotoo(lv+1),b);}		
		| ForSym LRB ForInit SEMICOLON SEMICOLON ForUpdate RRB StatementNoShortIf				{goparent();$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();$$->tac=concvector($3->tac,a,$8->tac,$6->tac,gotoo(lv+1),b);}		
		| ForSym LRB ForInit SEMICOLON Expression SEMICOLON RRB StatementNoShortIf				{goparent();$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($5)->tempname+gotoo(lv+2);$$->tac=concvector($3->tac,a,$5->tac,ret,$8->tac,gotoo(lv+1),b);}			
		| ForSym LRB ForInit SEMICOLON Expression SEMICOLON ForUpdate RRB StatementNoShortIf	{goparent();$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($5)->tempname+gotoo(lv+2);$$->tac=concvector($3->tac,a,$5->tac,ret,$9->tac,$7->tac,gotoo(lv+1),b);}		
		;
ForInit:	 StatementExpressionList			{$$=new Typeinfo; $$->tac=$1->tac;}											
		| LocalVariableDeclaration				{vector<string> a = ($1)->variables; for(auto s : a)insertidentifier(s,($1)->type,"",line);$$=new Typeinfo; $$->tac=$1->tac;}										
		;	
ForUpdate:	 StatementExpressionList						{$$=new Typeinfo; $$->tac=$1->tac;}								
		;
StatementExpressionList:	 StatementExpression				{$$=new Typeinfo; $$->tac=$1->tac;}							
		| StatementExpression OMCommaStatementExpression		{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}							
		;
EnhancedForStatementSym: ForSym LRB LocalVariableDeclaration {vector<string> a = ($3)->variables; for(auto s : a)insertidentifier(s,($3)->type,"",line);$$=new Typeinfo; $$->tac=$3->tac;}
		;
EnhancedForStatement:	 EnhancedForStatementSym COLON Expression RRB Statement			{goparent();$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($3)->tempname+gotoo(lv+2);$$->tac=concvector(a,$1->tac,$3->tac,ret,$5->tac,gotoo(lv+1),b);}					
		;
EnhancedForStatementNoShortIf:	 EnhancedForStatementSym COLON Expression RRB StatementNoShortIf	{goparent();$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($3)->tempname+gotoo(lv+2);$$->tac=concvector(a,$1->tac,$3->tac,ret,$5->tac,gotoo(lv+1),b);}		
		;
BreakStatement:   		 BREAK SEMICOLON								{$$=new Typeinfo;string p=gotoo(labelvariable+1); $$->tac={p};}												
		|	 BREAK Identifier SEMICOLON										{$$=new Typeinfo;string p=gotoo(labelvariable+1); $$->tac={p};}										
		;

YieldStatement:	 YIELD Expression SEMICOLON								{$$=new Typeinfo; $$->tac=$2->tac;}													
		;
ContinueStatement:   CONTINUE SEMICOLON										{$$=new Typeinfo;string p=gotoo(labelvariable); $$->tac={p};}											
		|	 CONTINUE Identifier SEMICOLON										{$$=new Typeinfo;string p=gotoo(labelvariable); $$->tac={p};}											
		;

ReturnStatement:	 RETURN SEMICOLON		{$$=new Typeinfo;string p=gotomethodretlabel(currmethod.top()); $$->tac={p};}					
		| RETURN Expression SEMICOLON{$$=new Typeinfo;string p=gotomethodretlabel(currmethod.top());string s = "%rax = " + $2->tempname; $$->tac=concvector($2->tac,s,p);}				
		;	
ThrowStatement:	 THROW Expression SEMICOLON										{$$=new Typeinfo; $$->tac=$2->tac;}		
		;
SynchronizedStatement:	 SYNCHRONIZED LRB Expression RRB {symtable*a=createscope("synchronized"); changescope(a);} Block		{goparent();$$=new Typeinfo; $$->tac=concvector($3->tac,$6->tac);}					
		;
TrySym: TRY {symtable*a=createscope("try"); changescope(a);}
		;
TryBlockSym: Block	{goparent();$$=createstruct(); $$->tac=$1->tac;}
		;
TryStatement:	TrySym TryBlockSym Catches						{$$=new Typeinfo; $$->tac=concvector($2->tac,$3->tac);}								
		| TrySym TryBlockSym Finally							{$$=new Typeinfo; $$->tac=concvector($2->tac,$3->tac);}										
		| TrySym TryBlockSym Catches Finally					{$$=new Typeinfo; $$->tac=concvector($2->tac,$3->tac,$4->tac);}													
		| TryWithResourcesStatement									{$$=new Typeinfo; $$->tac=$1->tac;}												
		;
Catches:	 CatchClause									{$$=new Typeinfo; $$->tac=$1->tac;}			
		| CatchClause OMCatchClause							{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}			
        ;
CatchClause:	 CATCH {symtable*a=createscope("catch"); changescope(a);} LRB CatchFormalParameter RRB  Block	{goparent();$$=new Typeinfo; $$->tac=concvector($4->tac,$6->tac);}								
		;
CatchFormalParameter:	 CatchType VariableDeclaratorId						{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}					
		| OMClassModifier CatchType VariableDeclaratorId		{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac,$3->tac);}					
		;
CatchType:   		 Identifier					{$$=new Typeinfo; $$->tac=emptyvector();}	
		|	 Identifier OMOrClassType									{$$=new Typeinfo; $$->tac=$2->tac;}			
		;

Finally:	 FINALLY {symtable*a=createscope("finally"); changescope(a);} Block	{goparent();$$=new Typeinfo; $$->tac=$3->tac;}																
		;	
TryWithResourcesStatement:	 TrySym ResourceSpecification TryBlockSym					{$$=new Typeinfo; $$->tac=concvector($2->tac,$3->tac);}				
		| TrySym ResourceSpecification TryBlockSym Finally			{$$=new Typeinfo; $$->tac=concvector($2->tac,$3->tac,$4->tac);}													
		| TrySym ResourceSpecification TryBlockSym Catches						{$$=new Typeinfo; $$->tac=concvector($2->tac,$3->tac,$4->tac);}										
		| TrySym ResourceSpecification TryBlockSym Catches Finally				{$$=new Typeinfo; $$->tac=concvector($2->tac,$3->tac,$4->tac,$5->tac);}									
		;
ResourceSpecification:	 LRB ResourceList RRB					{$$=new Typeinfo; $$->tac=$2->tac;}					
		;
ResourceList:	 Resource									{$$=new Typeinfo; $$->tac=$1->tac;}								
		| OMSemicolonResource								{$$=new Typeinfo; $$->tac=$1->tac;}									
		;
Resource:	 LocalVariableDeclaration							    {$$=new Typeinfo; $$->tac=$1->tac;}										
		| VariableAccess											{$$=new Typeinfo; $$->tac=$1->tac;}						
		;
Primary:	 PrimaryNoNewArray												{$$ = createstruct();$$=$1;($$)->type = ($1)->type;$$->exprvalue=$1->exprvalue;vector<int>q;$$->arrdim=q;$$->arrtype="";$$->initvartype=$1->initvartype;$$->tac=$1->tac;}			
		| ArrayCreationExpression											{$$=createstruct();$$=$1;$$->initvartype="";$$->tac=$1->tac;}			
		;
PrimaryNoNewArray:	 Literal												    	{$$ = createstruct();$$=$1;$$->exprvalue=$1->exprvalue;$$->initvartype=$1->type;($$)->type = ($1)->type;}		
		| ClassLiteral																{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}
		| THIS																		{$$ = createstruct();($$)->type = "class"; $$->tac=emptyvector();$$->tempname="this";}
		| Identifier DOT THIS														{$$ = createstruct();($$)->type = "class";string x=$1; $$->tac=emptyvector();$$->tempname=x;}
		| ExpressionName DOT THIS													{$$ = createstruct();$$=$1;($$)->type = "class";}	
		| LRB Expression RRB														{$$ = createstruct();$$=$2;($$)->type = ($2)->type;}
		| ClassInstanceCreationExpression									        {$$ = createstruct();$$=$1;($$)->type = ($1)->type;}			
		| FieldAccess																{$$ = createstruct();$$=$1;($$)->type = "look";}	
		| ArrayAccess																{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}	
		| MethodInvocation															{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}		
		| MethodReference															{$$ = createstruct();$$=$1;($$)->type = "look";}	
		;
ClassLiteral:	 Identifier DOT CLASS												{$$ = createstruct();($$)->type = "class"; $$->tac=emptyvector();}		
		| ExpressionName DOT CLASS													{$$ = createstruct();($$)->type = "class"; $$->tac=emptyvector();}
		| Identifier OMPSB DOT CLASS												{$$ = createstruct();($$)->type = "class"; $$->tac=emptyvector();}
		| ExpressionName OMPSB DOT CLASS											{$$ = createstruct();($$)->type = "class"; $$->tac=emptyvector();}	
		| UnannPrimitiveType DOT CLASS												{$$ = createstruct();($$)->type = "class"; $$->tac=emptyvector();}	
		| VOID DOT CLASS															{$$ = createstruct();($$)->type = "class"; $$->tac=emptyvector();}
		;
ClassInstanceCreationExpression:	 UnqualifiedClassInstanceCreationExpression			{$$ = createstruct();($$)->type = ($1)->type;$$->tac=$1->tac;}	
		| Identifier DOT UnqualifiedClassInstanceCreationExpression						{$$ = createstruct();($$)->type = ($3)->type;$$->tac=$3->tac;}
		| ExpressionName DOT UnqualifiedClassInstanceCreationExpression					{$$ = createstruct();($$)->type = ($3)->type;$$->tac=$3->tac;}	
		| Primary DOT UnqualifiedClassInstanceCreationExpression						{$$ = createstruct();($$)->type = ($3)->type;$$->tac=$3->tac;}
		;




UnqualifiedClassInstanceCreationExpression:	 NEW ClassOrInterfaceTypeToInstantiate LRB RRB 		{$$ = createstruct();($$)->type = ($2)->type;$$->tac=$2->tac;}
		| NEW ClassOrInterfaceTypeToInstantiate LRB RRB ClassBody								{$$ = createstruct();($$)->type = ($2)->type;$$->tac=concvector($2->tac,$5->tac);}
		| NEW ClassOrInterfaceTypeToInstantiate LRB ArgumentList RRB						{$$ = createstruct();($$)->type = ($2)->type;$$->tac=concvector($2->tac,$4->tac);}	
		| NEW ClassOrInterfaceTypeToInstantiate LRB ArgumentList RRB ClassBody		{$$ = createstruct();($$)->type = ($2)->type;$$->tac=concvector($2->tac,$4->tac,$6->tac);}		
		;
ClassOrInterfaceTypeToInstantiate:   Identifier					{$$ = createstruct();string p = $1;if(lookup(p)){($$)->type =  lookup(p)->funcrettype ;}$$->tac=emptyvector();}					
		|	Identifier OMDotIdentifier													{$$ = createstruct();$$->tac=emptyvector();string p = $1;if(lookup(p + ($2)->name)){($$)->type =  lookup(p + ($2)->name)->funcrettype ;}}
		;
FieldAccess:   Primary DOT Identifier								{$$=new Typeinfo; $$->tac=emptyvector();}
		|	 SUPER DOT Identifier									{$$ = createstruct();$$->tac=emptyvector();}
		|	 Identifier DOT SUPER DOT Identifier					{$$ = createstruct();$$->tac=emptyvector();}
		|	 ExpressionName DOT SUPER DOT Identifier				{$$=new Typeinfo; $$->tac=$1->tac;}
		;
ArrayAccess:   Identifier LSB Expression RSB			{$$=new Typeinfo;string yy=$1;symentry* entry=lookup(yy); vector<int>v=entry->arrdims;string x=entry->primtype; vector<int>f; for(int 	i=1;i<v.size();i++)f.push_back(v[i]);$$->dimsize=f;$$->arrname="a"; $$->arrtype=x;string y=newtemp();$$->tempname=y;y=y+" = "+($3)->tempname+" * "+to_string(tellsize(f,x)); $$->tac=concvector($3->tac,y);}
		|	 ExpressionName LSB Expression RSB				{$$=new Typeinfo; $$->tac=concvector($1->tac,$3->tac);}
		|	 PrimaryNoNewArray LSB Expression RSB			{$$=new Typeinfo; vector<int>v=($1)->dimsize;string x=($1)->arrtype; vector<int>f; for(int i=1;i<v.size();i++)f.push_back(v[i]);$$->dimsize=f; $$->arrtype=x;string y=newtemp();$$->tempname=y;string z=newtemp();y=y+" = "+($3)->tempname+" + "+z;z=z+" = "+($3)->tempname+" * "+to_string(tellsize(f,x)); $$->tac=concvector($1->tac,$3->tac,z,y);$$->arrname=$1->arrname;}
		;
MethodInvocation:   MethodName LRB ArgumentList RRB							{$$ = createstruct();if(lookup(($1)->name)){($$)->type =  lookup(($1)->name)->funcrettype ;} vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters(); string s = ($1)->tempname;($$)->tempname = "%rax"; string s1 = gotomethod(s);string s2 = newmethodretlabel(s);vector<string> pushpar = pusharg(($3)->params);$$->tac=concvector(pv1,$3->tac,pushpar,s1,$1->tac,s2,pv2);}		
		|	 MethodName LRB RRB												{$$ = createstruct();if(lookup(($1)->name)){($$)->type =  lookup(($1)->name)->funcrettype ;}vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters();string s = ($1)->tempname;($$)->tempname = "%rax";string s1 = gotomethod(s);string s2 = newmethodretlabel(s); $$->tac=concvector(pv1,s1,$1->tac,s2,pv2);}	
		|	 Identifier DOT Identifier LRB RRB						        {$$=new Typeinfo; $$->tac=emptyvector();}	
		|	 Identifier DOT Identifier LRB ArgumentList RRB					{$$=new Typeinfo; $$->tac=$5->tac;}	
		|	 ExpressionName DOT Identifier LRB RRB						    {$$=new Typeinfo; $$->tac=$1->tac;}								
		|	 ExpressionName DOT Identifier LRB ArgumentList RRB				{$$=new Typeinfo; $$->tac=concvector($1->tac,$5->tac);}									
		|	 Primary DOT Identifier LRB RRB								    {$$=new Typeinfo; $$->tac=$1->tac;}										
		|	 Primary DOT Identifier LRB ArgumentList RRB					{$$=new Typeinfo; $$->tac=$1->tac;}										
		|	 SUPER DOT Identifier LRB RRB									{$$=new Typeinfo; $$->tac=emptyvector();}			
		|	 SUPER DOT Identifier LRB ArgumentList RRB						{$$=new Typeinfo; $$->tac=emptyvector();}			
		|	 Identifier DOT SUPER DOT Identifier LRB RRB					{$$=new Typeinfo; $$->tac=emptyvector();}		
		|	 Identifier DOT SUPER DOT Identifier LRB ArgumentList RRB		{$$=new Typeinfo; $$->tac=$7->tac;}			
		|	 ExpressionName DOT SUPER DOT Identifier LRB RRB				{$$=new Typeinfo; $$->tac=$1->tac;}								
		|	 ExpressionName DOT SUPER DOT Identifier LRB ArgumentList RRB	{$$=new Typeinfo; $$->tac=concvector($1->tac,$7->tac);}				
		;

ArgumentList:	 Expression										{$$=new Typeinfo; $$->tac=$1->tac;string s = ($1)->tempname; $$->params.push_back(s);}	
		| Expression OMCommaExpression							{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);string s = ($1)->tempname; $$->params.push_back(s); for(auto z:($2)->params)($$)->params.push_back(z);}	
		;
MethodReference:   Identifier DOUBLECOLON Identifier			{$$=new Typeinfo; $$->tac=emptyvector();}	
		|	 ExpressionName DOUBLECOLON Identifier				
		|	 Primary DOUBLECOLON Identifier						{$$=new Typeinfo; $$->tac=emptyvector();}		
		|	 UnannArrayType DOUBLECOLON Identifier					{$$=new Typeinfo; $$->tac=emptyvector();}	
		|	 SUPER DOUBLECOLON Identifier							{$$=new Typeinfo; $$->tac=emptyvector();}	
		|	 Identifier DOT SUPER DOUBLECOLON Identifier			{$$=new Typeinfo; $$->tac=emptyvector();}	
		|	 ExpressionName DOT SUPER DOUBLECOLON Identifier					
		|	 UnannArrayType DOUBLECOLON NEW							{$$=new Typeinfo; $$->tac=emptyvector();}				
		;
ArrayCreationExpression:   NEW PrimitiveType OMDimExpr				{$$ = createstruct();$$->type=$2->type;$$->arrtype=$2->type;$$->arrdim=$3->arrdim; $$->tac=emptyvector();}			
		|	 NEW PrimitiveType OMDimExpr OMPSB									{$$=new Typeinfo; $$->tac=emptyvector();}				
		|	 NEW Identifier OMDimExpr											{$$=new Typeinfo; $$->tac=emptyvector();}				
		|	 NEW Identifier OMDimExpr OMPSB											{$$=new Typeinfo; $$->tac=emptyvector();}			
		|	 NEW PrimitiveType OMPSB ArrayInitializer						{$$=new Typeinfo; $$->tac=$4->tac;}	
		|	 NEW Identifier OMPSB ArrayInitializer								{$$=new Typeinfo; $$->tac=$4->tac;}	
		;

DimExpr:	 LSB Expression RSB								{$$ = createstruct();if($2->type!="int")cout<<"error coz of nonint array para";$$=$2;$$->exprvalue=$2->exprvalue;$$->type=$2->type;}
		;
Expression:	AssignmentExpression							{$$ = createstruct();$$=$1;($$)->type = ($1)->type;$$->exprvalue=$1->exprvalue;}
		;
AssignmentExpression:	 ConditionalExpression				{$$ = createstruct();$$=$1;($$)->type = ($1)->type;$$->exprvalue=$1->exprvalue;}
		| Assignment										{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}
		;
Assignment:	 LeftHandSide AssignmentOperator Expression		{$$ = createstruct();($$)->type = ($3)->type;string p=($1)->tempname+" = "+($3)->tempname;$$->tempname=($1)->tempname;$$->tac=concvector($1->tac,$3->tac,p);}
		;
LeftHandSide:	 ExpressionName								{$$=new Typeinfo; $$=$1;}	
   		// | Identifier										{$$ = createstruct();string p = $1;if(lookup(p)){($$)->type = lookup(p)->type;}string x=$1; string q=newtemp();$$->tempname=q;q=q+" = "+x; $$->tac={q};}
		|Identifier											{$$ = createstruct();string p = $1;if(lookup(p)){($$)->type = lookup(p)->type;}string x=$1;$$->tempname=x;$$->tac=emptyvector();}
		| FieldAccess										{$$=new Typeinfo; $$=$1;}	
		| ArrayAccess										{$$=new Typeinfo; $$->type=$1->type;string y=($1)->arrname+"["+($1)->tempname+"]"; $$->tempname=y;$$->tac=$1->tac;}				
		;
AssignmentOperator:	 ASSIGNMENTOPERATOR							{$$=$1;}
		;
ConditionalExpression:	 ConditionalOrExpression									{$$ = createstruct();$$=$1;($$)->type = ($1)->type;$$->exprvalue=$1->exprvalue;}
		| ConditionalOrExpression QM Expression COLON ConditionalExpression		{$$ = createstruct();($$)->type = ($1)->type;int lv=labelvariable;string a=newlabel();string ret="if zero "+($1)->tempname+gotoo(lv+1);$$->tac=concvector($1->tac,ret,$3->tac,a,$5->tac);}	
		;
ConditionalOrExpression:	 ConditionalAndExpression							{$$ = createstruct();$$=$1;($$)->type = ($1)->type;$$->exprvalue=$1->exprvalue;}				
		| ConditionalOrExpression OR ConditionalAndExpression 				{$$ = createstruct();($$)->type = "boolean";string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" || "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=$1->exprvalue||$3->exprvalue;}			
		;
ConditionalAndExpression:	 InclusiveOrExpression									{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}
		| ConditionalAndExpression AND InclusiveOrExpression						{$$ = createstruct();($$)->type = "boolean";string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" && "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=(($1->exprvalue)&&($3->exprvalue));}
		;
InclusiveOrExpression:	 ExclusiveOrExpression								{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}	
		| InclusiveOrExpression BITOR ExclusiveOrExpression				{$$ = createstruct();($$)->type = ($1)->type;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" | "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=(($1->exprvalue)|($3->exprvalue));}			
		;
ExclusiveOrExpression:	 AndExpression											{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}
		| ExclusiveOrExpression BITXOR AndExpression							{$$ = createstruct();($$)->type = ($1)->type;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" ^ "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=(($1->exprvalue)^($3->exprvalue));}	
		;
AndExpression:	 EqualityExpression													{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}
		| AndExpression BITAND EqualityExpression									{$$ = createstruct();($$)->type = ($1)->type;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" & "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=(($1->exprvalue)&($3->exprvalue));}
		;
EqualityExpression:	 RelationalExpression										{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}	
		| EqualityExpression DOUBLEEQUAL RelationalExpression						{$$ = createstruct();($$)->type = "boolean";string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" == "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=(($1->exprvalue)==($3->exprvalue));}	
		| EqualityExpression NE RelationalExpression								{$$ = createstruct();($$)->type = "boolean";string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" != "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=(($1->exprvalue)!=($3->exprvalue));}
		;
RelationalExpression:	 ShiftExpression											{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}
		| RelationalExpression LT ShiftExpression									{$$ = createstruct();($$)->type = "boolean";string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" < "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=(($1->exprvalue)<($3->exprvalue));}
		| RelationalExpression GT ShiftExpression									{$$ = createstruct();($$)->type = "boolean";string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" > "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=(($1->exprvalue)>($3->exprvalue));}
		| RelationalExpression LTE ShiftExpression									{$$ = createstruct();($$)->type = "boolean";string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" <= "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=(($1->exprvalue)<=($3->exprvalue));}	
		| RelationalExpression GTE ShiftExpression									{$$ = createstruct();($$)->type = "boolean";string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" >= "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=(($1->exprvalue)>=($3->exprvalue));}	
		| InstanceofExpression														{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}
		;



InstanceofExpression:	 RelationalExpression INSTANCEOF ReferenceType				{$$ = createstruct();($$)->type = ($1)->type;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" instanceof "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=$1->exprvalue;}
		;
ShiftExpression:	 AdditiveExpression												{$$ = createstruct();$$=$1;($$)->type = ($1)->type;$$->exprvalue=$1->exprvalue;}
		| ShiftExpression LSHIFT AdditiveExpression									{$$ = createstruct();($$)->type = ($1)->type;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" << "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=(($1->exprvalue)<<($3->exprvalue));}
		| ShiftExpression RSHIFT AdditiveExpression								{$$ = createstruct();($$)->type = ($1)->type;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" >> "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=(($1->exprvalue)>>($3->exprvalue));}	
		| ShiftExpression THREEGT AdditiveExpression								{$$ = createstruct();($$)->type = ($1)->type;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" >>> "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=(($1->exprvalue)>>($3->exprvalue));}
		;
AdditiveExpression:	 MultiplicativeExpression										{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}
		| AdditiveExpression PLUS MultiplicativeExpression			{$$ = createstruct();($$)->type = type_change(($1)->type,($3)->type);string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" + "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=(($1->exprvalue)+($3->exprvalue));}			
		| AdditiveExpression MINUS MultiplicativeExpression				{$$ = createstruct();($$)->type = type_change(($1)->type,($3)->type);string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" - "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=(($1->exprvalue)-($3->exprvalue));}				
		;
MultiplicativeExpression:	 UnaryExpression										{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}
		| MultiplicativeExpression MULTIPLY UnaryExpression					{$$ = createstruct();($$)->type = type_change(($1)->type,($3)->type);string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" * "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=(($1->exprvalue)*($3->exprvalue));}		
		| MultiplicativeExpression DIVIDE UnaryExpression						{$$ = createstruct();($$)->type = type_change(($1)->type,($3)->type);string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" / "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=(($1->exprvalue)/($3->exprvalue));}
		| MultiplicativeExpression PERCENT UnaryExpression					{$$ = createstruct();($$)->type = type_change(($1)->type,($3)->type);string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" % "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);$$->exprvalue=(($1->exprvalue)%($3->exprvalue));}		
		;
UnaryExpression:	 PreIncrementExpression							{$$ = createstruct();$$=$1;($$)->type = ($1)->type;$$->exprvalue=$1->exprvalue;}				
		| PreDecrementExpression													{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}
		| PLUS UnaryExpression														{$$ = createstruct();$$=$2;($$)->type = ($2)->type;$$->exprvalue=(1+($2->exprvalue));}
		| MINUS UnaryExpression														{$$ = createstruct();($$)->type = ($2)->type;string a=newtemp();$$->tempname=a;a=a+" = "+" - "+$2->tempname;$$->tac=concvector($2->tac,a);$$->exprvalue=(($2->exprvalue)-1);}
		| UnaryExpressionNotPlusMinus											{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}	
		;
PreIncrementExpression:	 INCREAMENT UnaryExpression						{$$ = createstruct();($$)->type = ($2)->type;string a=newtemp();$$->tempname=a;a=a+" = "+$2->tempname+" + 1 ";$$->tac=concvector($2->tac,a);$$->exprvalue=$2->exprvalue+1;$$->exprvalue=(($2->exprvalue)+1);}			
		;
PreDecrementExpression:	 DECREAMENT UnaryExpression						{$$ = createstruct();($$)->type = ($2)->type;string a=newtemp();$$->tempname=a;a=a+" = "+$2->tempname+" - 1 ";$$->tac=concvector($2->tac,a);$$->exprvalue=$2->exprvalue+1;$$->exprvalue=(($2->exprvalue)-1);}			
		;
UnaryExpressionNotPlusMinus:	 PostfixExpression		{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}							
		| TILDA UnaryExpression												{$$ = createstruct();($$)->type = ($2)->type;string a=newtemp();$$->tempname=a;a=a+" = "+" ~ "+$2->tempname;$$->tac=concvector($2->tac,a);$$->exprvalue=$2->exprvalue;}	
		| EXCLAM UnaryExpression											{$$ = createstruct();($$)->type = ($2)->type;string a=newtemp();$$->tempname=a;a=a+" = "+" ! "+$2->tempname;$$->tac=concvector($2->tac,a);$$->exprvalue=!($2->exprvalue);}		
		| CastExpression															{$$ = createstruct();($$)->type = ($1)->type;$$->exprvalue=$1->exprvalue;}
		| SwitchExpression															{$$ = createstruct();($$)->type = ($1)->type;$$->exprvalue=$1->exprvalue;}
		;
PostfixExpression:	 Primary							{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}							
		| Identifier								{$$ = createstruct();string p = $1;symentry*s=lookup(p); if(lookup(p)){($$)->type = s->type;$$->order=s->order;$$->exprvalue=s->exprvalue;}string a=$1; string b=newtemp();$$->tempname=b;b=b+" = "+a;$$->tac={b};$$->tac={b};}
		| ExpressionName														{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}		
		| PostIncrementExpression													{$$ = createstruct();$$=$1;($$)->type = ($1)->type;}
		| PostDecrementExpression												{$$ = createstruct();$$=$1;$$->type = ($1)->type;}
		;
PostIncrementExpression:	 PostfixExpression INCREAMENT					{$$ = createstruct();($$)->type = ($1)->type;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" + 1 ";$$->tac=concvector($1->tac,a);$$->exprvalue=$1->exprvalue+1;}	
		;
PostDecrementExpression:	 PostfixExpression DECREAMENT					{$$ = createstruct();($$)->type = ($1)->type;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" - 1 ";$$->tac=concvector($1->tac,a);$$->exprvalue=$1->exprvalue-1;}	
		;
CastExpression:	 LRB PrimitiveType RRB UnaryExpression							{$$ = createstruct();($$)->type = ($2)->type; ($4)->type = ($2)->type; string a=newtemp();$$->tempname=a;a=a+" = "+$4->tempname;$$->tac=concvector($4->tac,a);$$->exprvalue=$4->exprvalue;}
		| LRB UnannArrayType RRB UnaryExpressionNotPlusMinus						{$$ = createstruct();($$)->type = ($2)->type; ($4)->type = ($2)->type; string a=newtemp();$$->tempname=a;a=a+" = "+$4->tempname;$$->tac=concvector($4->tac,a);$$->exprvalue=$4->exprvalue;}
		| LRB UnannArrayType OMAdditionalBound RRB UnaryExpressionNotPlusMinus		{$$ = createstruct();($$)->type = ($2)->type; ($5)->type = ($2)->type; string a=newtemp();$$->tempname=a;a=a+" = "+$5->tempname;$$->tac=concvector($5->tac,a);$$->exprvalue=$5->exprvalue;}
		;
SwitchExpression:	 SWITCH LRB Expression RRB {symtable *a = createscope("switch"); changescope(a);} SwitchBlock			{goparent();$$=new Typeinfo; $$->tac=concvector($3->tac,$6->tac);($$)->type = "switch";$$->exprvalue=1;}
		;	
VariableAccess:	 ExpressionName										{$$=new Typeinfo; $$=$1;}			
    	| Identifier															{$$=new Typeinfo; string a=$1; string b=newtemp();$$->tempname=b;b=b+" = "+a;$$->tac={b};$$->tac={b};}		
		| FieldAccess														{$$=new Typeinfo; $$=$1;}			
		;

%%
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