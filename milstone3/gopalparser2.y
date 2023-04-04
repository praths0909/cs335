%{
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
stack<string> currmethod;
stack<stack<string>> currmethodlocals;

string newtemp(){
	tempvariables++;
	return "t"+to_string(tempvariables);
}
string newlabel(){
	labelvariable++;
	return "Label"+to_string(labelvariable);
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
/////////////////////////////////////
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

///////////////////
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
	vector<string>puvariables; //for variable declator list
	vector<string>params; 
	string name;

	vector<string>tac;
	string tempname;

    float valfloat;
    string valstr;
    char valchar;
    bool valbool;
    string littype;
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

%type <typeinfo> OMPSB   PSB   OMAdditionalBound   ReceiverParameterComma   IdentifierDot   OMImportDeclaration   OMTopLevelClassOrInterfaceDeclaration   OMDotIdentifier   OMModuleDirective   OMRequiresModifier   OMCommaModuleName   CommaModuleName   OMCommaTypeName   CommaTypeName   OMClassModifier   OMCommaTypeParameter   CommaTypeParameter   OMCommaInterfaceType   CommaInterfaceType   OMClassBodyDeclaration    OMCommaFormalParameter   CommaFormalParameter   OMCommaExceptionType   CommaExceptionType   OMCommaEnumConstant   CommaEnumConstant   OMCommaRecordComponent   CommaRecordComponent     OMRecordBodyDeclaration   OMInterfaceMemberDeclaration    OMCommaVariableInitializer   CommaVariableInitializer   OMBlockStatement   OMSwitchRule   OMSwitchBlockStatementGroup   OMSwitchLabelColon   SwitchLabelColon   OMCommaCaseConstant   CommaCaseConstant   OMCommaStatementExpression   CommaStatementExpression   OMCatchClause   OMOrClassType   OrClassType   OMSemicolonResource   SemicolonResource   OMCommaExpression   CommaExpression   OMDimExpr   Modifieropt   UnqualifiedMethodIdentifier   Literal   PrimitiveType   NumericType   IntegralType   FloatingPointType   ReferenceType   TypeParameter   TypeBound   AdditionalBound  ModuleName   ExpressionName   MethodName   CompilationUnit   OrdinaryCompilationUnit   ModularCompilationUnit   PackageDeclaration   ImportDeclaration   SingleTypeImportDeclaration   SingleStaticImportDeclaration   ImportOnDemandDeclaration   StaticImportOnDemandDeclaration   TopLevelClassOrInterfaceDeclaration   ModuleDeclaration   ModuleDirective   ClassDeclaration   NormalClassDeclaration   TypeParameters   TypeParameterList   ClassExtends   ClassImplements   InterfaceTypeList   ClassPermits   ClassBody   ClassBodyDeclaration   ClassMemberDeclaration   FieldDeclaration   VariableDeclaratorList   VariableDeclarator   VariableDeclaratorId   VariableInitializer   UnannType   UnannPrimitiveType   UnannArrayType   MethodDeclaration   MethodHeader   Result   MethodDeclarator   ReceiverParameter   FormalParameterList   FormalParameter   VariableArityParameter   Throws   ExceptionTypeList   ExceptionType   MethodBody   InstanceInitializer   StaticInitializer   ConstructorDeclaration   ConstructorDeclarator   ConstructorBody   ExplicitConstructorInvocation   EnumDeclaration   EnumBody   EnumConstantList   PRB   PRBArgumentList   EnumConstant    EnumBodyDeclarations   RecordDeclaration   RecordHeader   RecordComponentList   RecordComponent   VariableArityRecordComponent   RecordBody   RecordBodyDeclaration   CompactConstructorDeclaration   InterfaceDeclaration   NormalInterfaceDeclaration   InterfaceModifier   InterfaceExtends   InterfacePermits   InterfaceBody   InterfaceMemberDeclaration   ConstantDeclaration   InterfaceMethodDeclaration   ArrayInitializer   VariableInitializerList   Block   BlockStatements   BlockStatement   LocalClassOrInterfaceDeclaration   LocalVariableDeclarationStatement   LocalVariableDeclaration   LocalVariableType   Statement   StatementNoShortIf   StatementWithoutTrailingSubstatement   EmptyStatement   LabeledStatement   LabeledStatementNoShortIf   ExpressionStatement   StatementExpression   IfThenStatement   IfThenElseStatement   IfThenElseStatementNoShortIf   AssertStatement   SwitchStatement   SwitchBlock   SwitchRule   SwitchBlockStatementGroup   SwitchLabel   CaseConstant   WhileStatement   WhileStatementNoShortIf   DoStatement   ForStatement   ForStatementNoShortIf   BasicForStatement   BasicForStatementNoShortIf   ForInit   ForUpdate   StatementExpressionList   EnhancedForStatement   EnhancedForStatementNoShortIf   BreakStatement   YieldStatement   ContinueStatement   ReturnStatement   ThrowStatement   SynchronizedStatement   TryStatement   Catches   CatchClause   CatchFormalParameter   CatchType   Finally   TryWithResourcesStatement   ResourceSpecification   ResourceList   Resource   Primary   PrimaryNoNewArray   ClassLiteral   ClassInstanceCreationExpression   UnqualifiedClassInstanceCreationExpression   ClassOrInterfaceTypeToInstantiate   FieldAccess   ArrayAccess   MethodInvocation   ArgumentList   MethodReference   ArrayCreationExpression   DimExpr   Expression   AssignmentExpression   Assignment   LeftHandSide     ConditionalExpression   ConditionalOrExpression   ConditionalAndExpression   InclusiveOrExpression   ExclusiveOrExpression   AndExpression   EqualityExpression   RelationalExpression   InstanceofExpression   ShiftExpression   AdditiveExpression   MultiplicativeExpression   UnaryExpression   PreIncrementExpression   PreDecrementExpression   UnaryExpressionNotPlusMinus   PostfixExpression   PostIncrementExpression   PostDecrementExpression   CastExpression   SwitchExpression   VariableAccess   


%%

OMPSB:  PSB													{$$=new Typeinfo; $$->tac=emptyvector();}					
		|	OMPSB PSB										{$$=new Typeinfo; $$->tac=emptyvector();}					
		;
PSB: LSB RSB												{$$=new Typeinfo; $$->tac=emptyvector();}					
		;

OMAdditionalBound:   AdditionalBound					{$$=new Typeinfo; $$->tac=$1->tac;}					
        |	OMAdditionalBound   AdditionalBound 			{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}					
        ;

ReceiverParameterComma: ReceiverParameter COMMA						{$$=new Typeinfo; $$->tac= $1->tac;}		
        ;
IdentifierDot:  Identifier DOT										{$$=new Typeinfo; $$->tac=emptyvector();}			
        ;
OMImportDeclaration: ImportDeclaration								{$$=new Typeinfo; $$->tac= $1->tac;}		
    	|   OMImportDeclaration ImportDeclaration 							{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}	
    	;
OMTopLevelClassOrInterfaceDeclaration: TopLevelClassOrInterfaceDeclaration 			{$$=new Typeinfo;$$->tac=$1->tac;}			
    	|   OMTopLevelClassOrInterfaceDeclaration TopLevelClassOrInterfaceDeclaration 			{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}	
    	;
OMDotIdentifier: DOT Identifier							{$$=new Typeinfo; $$->tac=emptyvector();}									
    	|  OMDotIdentifier DOT Identifier	   								{$$=new Typeinfo; $$->tac= $1->tac;}	
    	;
OMModuleDirective: ModuleDirective						{$$=new Typeinfo; $$->tac=$1->tac;}					
    	|  OMModuleDirective ModuleDirective 				{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}				
    	;
OMRequiresModifier: Modifieropt								{$$=new Typeinfo; $$->tac=$1->tac;}				
    	| OMRequiresModifier  Modifieropt					{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}				
    	;
OMCommaModuleName: CommaModuleName								{$$=new Typeinfo; $$->tac= $1->tac;}			
    	|  OMCommaModuleName CommaModuleName 					{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}			
    	;
CommaModuleName:    COMMA ModuleName						{$$=new Typeinfo; $$->tac= $2->tac;}				
    	;
OMCommaTypeName: CommaTypeName 								{$$=new Typeinfo; $$->tac= $1->tac;}				
    	|  OMCommaTypeName CommaTypeName 					{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}				
    	;
CommaTypeName:    COMMA Identifier																		{$$=new Typeinfo; $$->tac=emptyvector();}		
    	|  COMMA ExpressionName												{$$=new Typeinfo; $$->tac= $2->tac;}
    	;
OMClassModifier:    InterfaceModifier							{$$=new Typeinfo; $$->tac= $1->tac;}		
        |     OMClassModifier  InterfaceModifier				{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}			
        ;
OMCommaTypeParameter:   CommaTypeParameter									{$$=new Typeinfo; $$->tac=emptyvector();}
        |      OMCommaTypeParameter CommaTypeParameter 						{$$=new Typeinfo; $$->tac=emptyvector();}
        ;	
CommaTypeParameter:     COMMA TypeParameter									{$$=new Typeinfo; $$->tac= $2->tac;}
        ;
OMCommaInterfaceType:    CommaInterfaceType							{$$=new Typeinfo; $$->tac= $1->tac;}		
        |      OMCommaInterfaceType CommaInterfaceType 				{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}		
        ;
CommaInterfaceType:     COMMA Identifier							{$$=new Typeinfo; $$->tac=emptyvector();}		
        ;
OMClassBodyDeclaration:  ClassBodyDeclaration					{$$=new Typeinfo; $$->tac=$1->tac;}			
        |    OMClassBodyDeclaration   ClassBodyDeclaration 			{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}		
        ;
OMCommaFormalParameter: CommaFormalParameter						{$$=new Typeinfo; $$->tac= $1->tac;}		
        |      OMCommaFormalParameter CommaFormalParameter 			{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}		
        ;
CommaFormalParameter:   COMMA FormalParameter						{$$=new Typeinfo; $$->tac= $2->tac;}		
        ;
OMCommaExceptionType:   CommaExceptionType							{$$=new Typeinfo; $$->tac= $1->tac;}		
        |     OMCommaExceptionType  CommaExceptionType 				{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}		
        ;
CommaExceptionType: COMMA ExceptionType								{$$=new Typeinfo; $$->tac= $2->tac;}		
        ;
OMCommaEnumConstant:   CommaEnumConstant 							{$$=new Typeinfo; $$->tac= $1->tac;}		
        |     OMCommaEnumConstant  CommaEnumConstant 				{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}		
        ;
CommaEnumConstant:      EnumConstant COMMA									{$$=new Typeinfo; $$->tac= $1->tac;}
        ;	

OMCommaRecordComponent: CommaRecordComponent							{$$=new Typeinfo; $$->tac= $1->tac;}	
        |      OMCommaRecordComponent CommaRecordComponent 				{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}	
        ;
CommaRecordComponent:   COMMA RecordComponent								{$$=new Typeinfo; $$->tac= $2->tac;}
        ;
OMRecordBodyDeclaration:       RecordBodyDeclaration 					{$$=new Typeinfo; $$->tac= $1->tac;}	
        |     OMRecordBodyDeclaration  RecordBodyDeclaration   			{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}	
        ;
OMInterfaceMemberDeclaration: InterfaceMemberDeclaration				{$$=new Typeinfo; $$->tac= $1->tac;}	
    	|  OMInterfaceMemberDeclaration InterfaceMemberDeclaration 		{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}	
    	;
	
OMCommaVariableInitializer: CommaVariableInitializer					{$$=new Typeinfo; $$->tac= $1->tac;}	
        |     OMCommaVariableInitializer  CommaVariableInitializer 		{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}	
        ;
CommaVariableInitializer:       COMMA VariableInitializer				{$$=new Typeinfo; $$->tac= $2->tac;}	
        ;	
OMBlockStatement: BlockStatement 							{$$=new Typeinfo; $$=$1;}				
    	|  OMBlockStatement BlockStatement 					{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}
    	;
OMSwitchRule: SwitchRule												{$$=new Typeinfo; $$->tac= $1->tac;}	
    	|  OMSwitchRule SwitchRule 										{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}
    	;
OMSwitchBlockStatementGroup: SwitchBlockStatementGroup						
    | OMSwitchBlockStatementGroup  SwitchBlockStatementGroup 			{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}	
    ;
OMSwitchLabelColon: SwitchLabelColon									{$$=new Typeinfo; $$->tac= $1->tac;}	
    |  OMSwitchLabelColon SwitchLabelColon 								{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}	
    ;
SwitchLabelColon:   SwitchLabel COLON										{$$=new Typeinfo; $$->tac= $1->tac;}	
    ;
OMCommaCaseConstant: CommaCaseConstant 								{$$=new Typeinfo; $$->tac= $1->tac;}		
    |   OMCommaCaseConstant CommaCaseConstant 						{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}		
    ;
CommaCaseConstant:  COMMA CaseConstant								{$$=new Typeinfo; $$->tac= $2->tac;}			
    ;
OMCommaStatementExpression: CommaStatementExpression				{$$=new Typeinfo; $$->tac= $1->tac;}		
    | OMCommaStatementExpression  CommaStatementExpression 			{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}
    ;
CommaStatementExpression:  COMMA StatementExpression				{$$=new Typeinfo; $$->tac= $2->tac;}			
    ;
OMCatchClause:	CatchClause											{$$=new Typeinfo; $$->tac= $1->tac;}			
    |  OMCatchClause CatchClause 										{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}	
    ;
OMOrClassType: OrClassType													{$$=new Typeinfo; $$->tac= $1->tac;}
    |  OMOrClassType OrClassType 										{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}	
    ;
OrClassType:   BITOR Identifier											{$$=new Typeinfo; $$->tac=emptyvector();}	
    ;
OMSemicolonResource: SemicolonResource										{$$=new Typeinfo; $$->tac= $1->tac;}
    | OMSemicolonResource  SemicolonResource 							{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}	
    ;
SemicolonResource:  Resource SEMICOLON										{$$=new Typeinfo; $$->tac= $1->tac;}
    ;
OMCommaExpression:   CommaExpression									{$$=new Typeinfo; $$->tac= $1->tac;for(auto z:($1)->params)($$)->params.push_back(z);}	
        |  OMCommaExpression CommaExpression 							{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);for(auto z:($1)->params)($$)->params.push_back(z);for(auto z:($2)->params)($$)->params.push_back(z);}	
        ;
CommaExpression:    COMMA Expression										{$$=new Typeinfo; $$->tac= $2->tac;string s = ($2)->tempname; $$->params.push_back(s);}
        ;
OMDimExpr:      DimExpr														{$$=new Typeinfo; $$->tac= $1->tac;}
        |     OMDimExpr  DimExpr 											{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}
        ;
Modifieropt:	PUBLIC				   					{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| PROTECTED										{string x=$1;$$=new Typeinfo; $$->tempname=x;}					
		| PRIVATE										{string x=$1;$$=new Typeinfo; $$->tempname=x;}					
		| ABSTRACT										{string x=$1;$$=new Typeinfo; $$->tempname=x;}					
		| STATIC										{string x=$1;$$=new Typeinfo; $$->tempname=x;}					
		| SEALED										{string x=$1;$$=new Typeinfo; $$->tempname=x;}					
		| STRICTFP										{string x=$1;$$=new Typeinfo; $$->tempname=x;}					
		| FINAL											{string x=$1;$$=new Typeinfo; $$->tempname=x;}					
		;
Identifier:	 IDENTIFIERWK									{$$=$1;}			
		;
UnqualifiedMethodIdentifier:	 IDENTIFIERWK			{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| EXPORTS										{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| OPENS											{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| REQUIRES										{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| USES											{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| MODULE										{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| PERMITS										{string x=$1;$$=new Typeinfo; $$->tempname=x;}
		| SEALED										{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| VAR											{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| NONSEALED										{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| PROVIDES										{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| TO											{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| WITH											{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| OPEN											{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| RECORD										{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		| TRANSITIVE									{string x=$1;$$=new Typeinfo; $$->tempname=x;}	
		;
Literal:	 INTEGERLITERAL					{string x=$1;int p=stoi(x);$$=new Typeinfo;$$->littype="int";$$->valfloat=p;string y=newtemp();$$->tempname=y;string z=y+" = "+x;$$->tac={z};}		
		| FLOATINGPOINTLITERAL				{string x=$1;float p=stof(x);$$=new Typeinfo;$$->littype="float";$$->valfloat=p;string y=newtemp();$$->tempname=y;string z=y+" = "+x;$$->tac={z};}				
		| BOOLEANLITERAL					{string x=$1;;$$=new Typeinfo;$$->littype="bool";$$->valstr=x;string y=newtemp();$$->tempname=y;string z=y+" = "+x;$$->tac={z};}						
		| NULLLITERAL						{string x=$1;$$=new Typeinfo;$$->littype="null";$$->valstr=x;string y=newtemp();$$->tempname=y;string z=y+" = "+x;$$->tac={z};}					
		| CHARACTERLITERAL					{string x=$1;$$=new Typeinfo;$$->littype="char";$$->valstr=x;string y=newtemp();$$->tempname=y;string z=y+"="+x;$$->tac={z};}						
		| STRING							{string x=$1;$$=new Typeinfo;$$->littype="string";$$->valstr=x;string y=newtemp();$$->tempname=y;string z=y+" = "+x;$$->tac={z};}						
		| TEXTBLOCKS						{string x=$1;$$=new Typeinfo;$$->littype="textblock";$$->valstr=x;string y=newtemp();$$->tempname=y;string z=y+" = "+x;$$->tac={z};}						
		;
ASSIGNMENTOPERATOR:	 NEWASSIGNMENTOPERATOR			{$$=$1;}
		| EQUAL										{$$=$1;}	
		;
PrimitiveType:	 UnannPrimitiveType				{$$=new Typeinfo; $$->tac=$1->tac;}				
		;
NumericType:	 IntegralType				{$$=new Typeinfo; $$->tac=emptyvector();}				
		| FloatingPointType					{$$=new Typeinfo; $$->tac=emptyvector();}				
		;
IntegralType:	 BYTE						{$$=new Typeinfo; $$->tac=emptyvector();}				
		| SHORT								{$$=new Typeinfo; $$->tac=emptyvector();}				
		| INT								{$$=new Typeinfo; $$->tac=emptyvector();}				
		| LONG								{$$=new Typeinfo; $$->tac=emptyvector();}				
		| CHAR								{$$=new Typeinfo; $$->tac=emptyvector();}				
		;
FloatingPointType:	 FLOAT					{$$=new Typeinfo; $$->tac=emptyvector();}				
		| DOUBLE							{$$=new Typeinfo; $$->tac=emptyvector();}			
		;
ReferenceType:	 Identifier					{$$=new Typeinfo; $$->tac=emptyvector();}				
		| UnannArrayType					{$$=new Typeinfo; $$->tac=emptyvector();}				
		;
TypeParameter:	 Identifier					{$$=new Typeinfo; $$->tac=emptyvector();}				
		| Identifier TypeBound				{$$=new Typeinfo; $$->tac=emptyvector();}			
		;
TypeBound:	 EXTENDS Identifier				{$$=new Typeinfo; $$->tac=emptyvector();}				
		| EXTENDS Identifier OMAdditionalBound		{$$=new Typeinfo; $$->tac=emptyvector();}		
		;
AdditionalBound:	 BITAND Identifier				{$$=new Typeinfo; $$->tac=emptyvector();}		
		;
ModuleName:	 Identifier									{$$=new Typeinfo; $$->tac=emptyvector();}	
		| ModuleName DOT Identifier						{$$=new Typeinfo; $$->tac=emptyvector();}	
		;
ExpressionName:	 Identifier DOT Identifier				{$$=new Typeinfo;string x=$1;string p=newtemp(); $$->tempname=p;p=p+" = "+x; $$->tac={p};}	
		| ExpressionName DOT Identifier					{$$=new Typeinfo;$$->tac=$1->tac;}	
		;
MethodName:	 UnqualifiedMethodIdentifier				{$$=new Typeinfo; $$->tac=$1->tac;$$->tempname = ($1)->tempname;}	
		;
CompilationUnit:	 OrdinaryCompilationUnit				{$$=new Typeinfo;$$->tac=$1->tac; for(auto z:($$->tac)) fprintf(dotfile,"%s\n",z.c_str());}
		| ModularCompilationUnit							{$$=new Typeinfo;$$->tac=$1->tac; for(auto z:($$->tac)) fprintf(dotfile,"%s\n",z.c_str());}
		;
OrdinaryCompilationUnit:								{$$=new Typeinfo;$$->tac=emptyvector();}							
		| OMTopLevelClassOrInterfaceDeclaration			{$$=new Typeinfo;$$->tac=$1->tac;}									
		| OMImportDeclaration							{$$=new Typeinfo;$$->tac=$1->tac;}								
		| OMImportDeclaration OMTopLevelClassOrInterfaceDeclaration		{$$=new Typeinfo;$$->tac=concvector($1->tac,$2->tac);}				
		| PackageDeclaration							{$$=new Typeinfo;$$->tac=$1->tac;}								
		| PackageDeclaration OMTopLevelClassOrInterfaceDeclaration				{$$=new Typeinfo;$$->tac=concvector($1->tac,$2->tac);}		
		| PackageDeclaration OMImportDeclaration							{$$=new Typeinfo;$$->tac=concvector($1->tac,$2->tac);}			
		| PackageDeclaration OMImportDeclaration OMTopLevelClassOrInterfaceDeclaration	{$$=new Typeinfo;$$->tac=concvector($1->tac,$2->tac,$3->tac);}
		;
ModularCompilationUnit:	 ModuleDeclaration				{$$=new Typeinfo;$$->tac=$1->tac;}								
		| OMImportDeclaration ModuleDeclaration			{$$=new Typeinfo;$$->tac=concvector($1->tac,$2->tac);}									
		;
PackageDeclaration:	 PACKAGE Identifier SEMICOLON			{$$=new Typeinfo; $$->tac=emptyvector();}							
		| PACKAGE Identifier OMDotIdentifier SEMICOLON		{$$=new Typeinfo; $$->tac=emptyvector();}			
		;
ImportDeclaration:	 SingleTypeImportDeclaration				{$$=new Typeinfo;$$->tac=$1->tac;}						
		| SingleStaticImportDeclaration							{$$=new Typeinfo;$$->tac=$1->tac;}															
		| StaticImportOnDemandDeclaration						{$$=new Typeinfo;$$->tac=$1->tac;}					
		|	ImportOnDemandDeclaration							{$$=new Typeinfo;$$->tac=$1->tac;}						
		;
SingleTypeImportDeclaration:	 IMPORT Identifier SEMICOLON	{$$=new Typeinfo; $$->tac=emptyvector();}						
    	| IMPORT ExpressionName SEMICOLON						{$$=new Typeinfo; $$->tac=emptyvector();}						
		;
SingleStaticImportDeclaration:	IMPORT STATIC ExpressionName SEMICOLON		{$$=new Typeinfo; $$->tac=emptyvector();}			
		;
ImportOnDemandDeclaration:	 IMPORT Identifier DOT MULTIPLY SEMICOLON		{$$=new Typeinfo; $$->tac=emptyvector();}			
    | IMPORT ExpressionName DOT MULTIPLY SEMICOLON							{$$=new Typeinfo; $$->tac=emptyvector();}			
		;
StaticImportOnDemandDeclaration:	 IMPORT STATIC Identifier DOT MULTIPLY SEMICOLON	{$$=new Typeinfo; $$->tac=emptyvector();}
    | IMPORT STATIC ExpressionName DOT MULTIPLY SEMICOLON								{$$=new Typeinfo; $$->tac=emptyvector();}
		;
TopLevelClassOrInterfaceDeclaration:	 ClassDeclaration			{$$=new Typeinfo;$$->tac=$1->tac;}				
		| InterfaceDeclaration										{$$=new Typeinfo;$$->tac=$1->tac;}				
		| SEMICOLON													{$$=new Typeinfo;$$->tac=emptyvector();}					
		;
ModuleDeclaration:	 MODULE Identifier  LCB RCB						{$$=new Typeinfo;$$->tac=emptyvector();}					
		| MODULE Identifier   LCB OMModuleDirective RCB							{$$=new Typeinfo;$$->tac=$4->tac;}			
		| MODULE Identifier OMDotIdentifier   LCB RCB							{$$=new Typeinfo;$$->tac=emptyvector();}			
		| MODULE Identifier OMDotIdentifier   LCB OMModuleDirective RCB				{$$=new Typeinfo;$$->tac=$5->tac;}		
		| OPEN MODULE Identifier   LCB RCB									{$$=new Typeinfo;$$->tac=emptyvector();}			
		| OPEN MODULE Identifier   LCB OMModuleDirective RCB					{$$=new Typeinfo;$$->tac=$5->tac;}				
		| OPEN MODULE Identifier OMDotIdentifier   LCB RCB					{$$=new Typeinfo;$$->tac=emptyvector();}			
		| OPEN MODULE Identifier OMDotIdentifier   LCB OMModuleDirective RCB		{$$=new Typeinfo;$$->tac=$6->tac;}			 
		;
ModuleDirective:	 REQUIRES ModuleName SEMICOLON								{$$=new Typeinfo;$$->tac=emptyvector();}
		| REQUIRES OMRequiresModifier ModuleName SEMICOLON						{$$=new Typeinfo;$$->tac=emptyvector();}
		| EXPORTS Identifier SEMICOLON											{$$=new Typeinfo;$$->tac=emptyvector();}
		| EXPORTS Identifier TO ModuleName SEMICOLON							{$$=new Typeinfo;$$->tac=emptyvector();}	
		| EXPORTS Identifier TO ModuleName OMCommaModuleName SEMICOLON			{$$=new Typeinfo;$$->tac=emptyvector();}	
		| OPENS Identifier SEMICOLON											{$$=new Typeinfo;$$->tac=emptyvector();}	
		| OPENS Identifier TO ModuleName SEMICOLON								{$$=new Typeinfo;$$->tac=emptyvector();}	
		| OPENS Identifier TO ModuleName OMCommaModuleName SEMICOLON			{$$=new Typeinfo;$$->tac=emptyvector();}
		| USES Identifier SEMICOLON												{$$=new Typeinfo;$$->tac=emptyvector();}	
		| PROVIDES Identifier WITH Identifier SEMICOLON							{$$=new Typeinfo;$$->tac=emptyvector();}
		| PROVIDES Identifier WITH Identifier OMCommaTypeName SEMICOLON			{$$=new Typeinfo;$$->tac=emptyvector();}	
		| EXPORTS ExpressionName SEMICOLON										{$$=new Typeinfo;$$->tac=$2->tac;}	
		| EXPORTS ExpressionName TO ModuleName SEMICOLON						{$$=new Typeinfo;$$->tac=$2->tac;}	
		| EXPORTS ExpressionName TO ModuleName OMCommaModuleName SEMICOLON		{$$=new Typeinfo;$$->tac=$2->tac;}	
		| OPENS ExpressionName SEMICOLON										{$$=new Typeinfo;$$->tac=$2->tac;}	
		| OPENS ExpressionName TO ModuleName SEMICOLON							{$$=new Typeinfo;$$->tac=$2->tac;}	
		| OPENS ExpressionName TO ModuleName OMCommaModuleName SEMICOLON		{$$=new Typeinfo;$$->tac=$2->tac;}	
		| USES ExpressionName SEMICOLON											{$$=new Typeinfo;$$->tac=$2->tac;}
		| PROVIDES ExpressionName WITH ExpressionName SEMICOLON					{$$=new Typeinfo;$$->tac=$2->tac;}	
		| PROVIDES ExpressionName WITH ExpressionName OMCommaTypeName SEMICOLON	{$$=new Typeinfo;$$->tac=$2->tac;}	
		| PROVIDES ExpressionName WITH Identifier SEMICOLON						{$$=new Typeinfo;$$->tac=$2->tac;}	
		| PROVIDES Identifier WITH ExpressionName OMCommaTypeName SEMICOLON		{$$=new Typeinfo;$$->tac=$4->tac;}	
		| PROVIDES Identifier WITH ExpressionName SEMICOLON						{$$=new Typeinfo;$$->tac=$4->tac;}	
		| PROVIDES ExpressionName WITH Identifier OMCommaTypeName SEMICOLON		{$$=new Typeinfo;$$->tac=$2->tac;}	
		;
ClassDeclaration:	 NormalClassDeclaration		{$$=new Typeinfo; $$->tac=$1->tac;}									
		| EnumDeclaration						{$$=new Typeinfo; $$->tac=$1->tac;}									
		| RecordDeclaration						{$$=new Typeinfo; $$->tac=$1->tac;}									
		;
NormalClassDeclaration:	 CLASS Identifier    ClassBody			                    {$$=new Typeinfo; $$->tac=$3->tac;}										
		| CLASS Identifier ClassPermits  ClassBody				                     {$$=new Typeinfo; $$->tac=$4->tac;}										
		| CLASS Identifier ClassImplements   ClassBody			                     {$$=new Typeinfo; $$->tac=$4->tac;}										
		| CLASS Identifier ClassImplements ClassPermits   ClassBody		            {$$=new Typeinfo; $$->tac=$5->tac;}								
		| CLASS Identifier ClassExtends   ClassBody							        {$$=new Typeinfo; $$->tac=$4->tac;}								
		| CLASS Identifier ClassExtends ClassPermits  ClassBody				        {$$=new Typeinfo; $$->tac=$5->tac;}								
		| CLASS Identifier ClassExtends ClassImplements  ClassBody			        {$$=new Typeinfo; $$->tac=$5->tac;}								
		| CLASS Identifier ClassExtends ClassImplements ClassPermits  ClassBody	       {$$=new Typeinfo; $$->tac=$6->tac;}							
		| CLASS Identifier TypeParameters  ClassBody							       {$$=new Typeinfo; $$->tac=$4->tac;}								
		| CLASS Identifier TypeParameters ClassPermits  ClassBody			        	 {$$=new Typeinfo; $$->tac=$5->tac;}						
		| CLASS Identifier TypeParameters ClassImplements  ClassBody					 {$$=new Typeinfo; $$->tac=$5->tac;}					
		| CLASS Identifier TypeParameters ClassImplements  ClassPermits  ClassBody		 {$$=new Typeinfo; $$->tac=$6->tac;}
		| CLASS Identifier TypeParameters ClassExtends  ClassBody						 {$$=new Typeinfo; $$->tac=$5->tac;}
		| CLASS Identifier TypeParameters ClassExtends ClassPermits  ClassBody			 {$$=new Typeinfo; $$->tac=$6->tac;}
		| CLASS Identifier TypeParameters ClassExtends ClassImplements  ClassBody		             {$$=new Typeinfo; $$->tac=$6->tac;}
		| CLASS Identifier TypeParameters ClassExtends ClassImplements ClassPermits  ClassBody			 {$$=new Typeinfo; $$->tac=$7->tac;}
		| OMClassModifier CLASS Identifier  ClassBody													 {$$=new Typeinfo; $$->tac=$4->tac;}
		| OMClassModifier CLASS Identifier ClassPermits  ClassBody										 {$$=new Typeinfo; $$->tac=$5->tac;}
		| OMClassModifier CLASS Identifier ClassImplements  ClassBody									 {$$=new Typeinfo; $$->tac=$5->tac;}
		| OMClassModifier CLASS Identifier ClassImplements ClassPermits   ClassBody						 {$$=new Typeinfo; $$->tac=$6->tac;}
		| OMClassModifier CLASS Identifier ClassExtends  ClassBody										 {$$=new Typeinfo; $$->tac=$5->tac;}
		| OMClassModifier CLASS Identifier ClassExtends ClassPermits  ClassBody							 {$$=new Typeinfo; $$->tac=$6->tac;}
		| OMClassModifier CLASS Identifier ClassExtends ClassImplements   ClassBody						 {$$=new Typeinfo; $$->tac=$6->tac;}
		| OMClassModifier CLASS Identifier ClassExtends ClassImplements ClassPermits   ClassBody			 {$$=new Typeinfo; $$->tac=$7->tac;}
		| OMClassModifier CLASS Identifier TypeParameters   ClassBody										 {$$=new Typeinfo; $$->tac=$5->tac;}
		| OMClassModifier CLASS Identifier TypeParameters ClassPermits   ClassBody						 {$$=new Typeinfo; $$->tac=$6->tac;}
		| OMClassModifier CLASS Identifier TypeParameters ClassImplements   ClassBody						 {$$=new Typeinfo; $$->tac=$6->tac;}
		| OMClassModifier CLASS Identifier TypeParameters ClassImplements ClassPermits   ClassBody		 {$$=new Typeinfo; $$->tac=$7->tac;}
		| OMClassModifier CLASS Identifier TypeParameters ClassExtends   ClassBody						 {$$=new Typeinfo; $$->tac=$6->tac;}
		| OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassPermits   ClassBody			 {$$=new Typeinfo; $$->tac=$7->tac;}
		| OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassImplements   ClassBody		 {$$=new Typeinfo; $$->tac=$7->tac;}
		| OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassImplements ClassPermits   ClassBody	             {$$=new Typeinfo; $$->tac=$8->tac;}
		;
TypeParameters:	 LT TypeParameterList GT				{$$=new Typeinfo; $$->tac=emptyvector();}				
		;
TypeParameterList: TypeParameter							{$$=new Typeinfo; $$->tac=emptyvector();}			
		| TypeParameter OMCommaTypeParameter				{$$=new Typeinfo; $$->tac=emptyvector();}			
		;
ClassExtends:	EXTENDS Identifier							{$$=new Typeinfo; $$->tac=emptyvector();}				
		;	
ClassImplements: IMPLEMENTS InterfaceTypeList				{$$=new Typeinfo; $$->tac=emptyvector();}						
		;
InterfaceTypeList:   Identifier								{$$=new Typeinfo; $$->tac=emptyvector();}			
		|	 Identifier OMCommaInterfaceType				{$$=new Typeinfo; $$->tac=emptyvector();}			
		;

ClassPermits:   PERMITS Identifier					{$$=new Typeinfo; $$->tac=emptyvector();}					
		|	 PERMITS ExpressionName						{$$=new Typeinfo; $$->tac=emptyvector();}				
		|	 PERMITS Identifier OMCommaTypeName			{$$=new Typeinfo; $$->tac=emptyvector();}				
		|	 PERMITS ExpressionName OMCommaTypeName		{$$=new Typeinfo; $$->tac=emptyvector();}				
		;

ClassBody:	 LCB RCB							{$$=new Typeinfo; $$->tac=emptyvector();}						
		| LCB OMClassBodyDeclaration RCB		{$$=new Typeinfo; $$->tac=$2->tac;}				
		;
ClassBodyDeclaration:	 ClassMemberDeclaration		{$$=new Typeinfo; $$->tac=$1->tac;}					
		| InstanceInitializer						{$$=new Typeinfo; $$->tac=$1->tac;}						
		| StaticInitializer							{$$=new Typeinfo; $$->tac=$1->tac;}						
		| ConstructorDeclaration					{$$=new Typeinfo; $$->tac=$1->tac;}						
		;
ClassMemberDeclaration:	 FieldDeclaration		{$$=new Typeinfo; $$->tac=$1->tac;}							
		| MethodDeclaration						{$$=new Typeinfo; $$->tac=$1->tac;}							
		| ClassDeclaration						{$$=new Typeinfo; $$->tac=$1->tac;}							
		| InterfaceDeclaration					{$$=new Typeinfo; $$->tac=$1->tac;}							
		| SEMICOLON								{$$=new Typeinfo; $$->tac=emptyvector();}						
		;
FieldDeclaration:	 UnannType VariableDeclaratorList SEMICOLON     	{$$=new Typeinfo; ($$)->puvariables=($2)->puvariables;vector<string> s = pushlocal(($2)->puvariables); $$->tac=concvector(s,$2->tac);}	
		| OMClassModifier UnannType VariableDeclaratorList SEMICOLON	{$$=new Typeinfo; ($$)->puvariables=($3)->puvariables;vector<string> s = pushlocal(($3)->puvariables); $$->tac=concvector(s,$3->tac);}	
		;
VariableDeclaratorList:	 VariableDeclarator				{$$=new Typeinfo;($$)->puvariables = ($1)->puvariables;$$->tac=$1->tac;}				
		| VariableDeclarator COMMA VariableDeclaratorList		{$$=new Typeinfo; vector<string>a=($1)->puvariables;vector<string>b=($3)->puvariables;for(auto z:a){($$)->puvariables.push_back(z);}for(auto z:b){($$)->puvariables.push_back(z);} $$->tac=concvector($1->tac,$3->tac);}
		;





















































































































































































































































VariableDeclarator:	 VariableDeclaratorId						{$$=new Typeinfo;($$)->puvariables = ($1)->puvariables; $$->tac=emptyvector();}	
		| VariableDeclaratorId EQUAL VariableInitializer		{$$=new Typeinfo;($$)->puvariables = ($1)->puvariables;string c=$1->tempname+"="+$3->tempname;$$->tac=concvector($1->tac,$3->tac,c);}
		;
VariableDeclaratorId:  Identifier							{$$=new Typeinfo;string x=$1;$$->tempname=x;($$)->puvariables.push_back(x);}			
		|	 Identifier OMPSB								{$$=new Typeinfo;string x=$1;$$->tempname=x;($$)->puvariables.push_back(x);}						
		;

VariableInitializer:	 Expression							{$$=new Typeinfo; $$=$1;}	
		| ArrayInitializer									{$$=new Typeinfo; $$=$1;}			
		;
UnannType:	 UnannPrimitiveType								{$$=new Typeinfo; $$=$1;}			
		| Identifier										{$$=new Typeinfo;string x=$1;$$->tempname=x;}		
		| UnannArrayType									{$$=new Typeinfo; $$=$1;}			
		;
UnannPrimitiveType:	 NumericType							{$$=new Typeinfo; $$->tac=emptyvector();}			
		| BOOLEAN											{$$=new Typeinfo; $$->tac=emptyvector();}			
		;
UnannArrayType:    UnannPrimitiveType OMPSB					{$$=new Typeinfo; $$->tac=emptyvector();}			
		|	 Identifier OMPSB								{$$=new Typeinfo; $$->tac=emptyvector();}			
		;

MethodDeclaration:	 MethodHeader MethodBody					{$$=new Typeinfo;string f = ($1)->tempname;string p=gotomethodretlabel(f); string z="function end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); $$->tac=concvector($1->tac,$2->tac,z,sv,p);}		
		| OMClassModifier MethodHeader MethodBody				{$$=new Typeinfo;string f = ($2)->tempname;string p=gotomethodretlabel(f); string z="function end"; stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st); 	currmethod.pop(); currmethodlocals.pop(); $$->tac=concvector($2->tac,$3->tac,z,sv,p);}	
		;
MethodHeader:	 Result MethodDeclarator		                {$$=new Typeinfo;$$->tempname=($1)->tempname; string f = ($1)->tempname; string q=newmethodlabel(f);string p="call "+($1)->tempname+"\n"+q;$$->tac=concvector(p,$2->tac);}	
		| Result MethodDeclarator Throws						{$$=new Typeinfo;$$->tempname=($1)->tempname; string f = ($1)->tempname; string q=newmethodlabel(f);string p="call "+($1)->tempname+"\n"+q; $$->tac=concvector(p,$2->tac);}		
		| TypeParameters Result MethodDeclarator				{$$=new Typeinfo;$$->tempname=($2)->tempname; string f = ($2)->tempname; string q=newmethodlabel(f);string p="call "+($2)->tempname+"\n"+q; $$->tac=concvector(p,$3->tac);}		
		| TypeParameters Result MethodDeclarator Throws			{$$=new Typeinfo;$$->tempname=($2)->tempname; string f = ($2)->tempname; string q=newmethodlabel(f);string p="call "+($2)->tempname+"\n"+q; $$->tac=concvector(p,$3->tac);}		
		;
Result:    UnannType	Identifier								{$$=new Typeinfo;string x=$2; $$->tempname=x;$$->tac=emptyvector();}			
		|	 VOID Identifier									{$$=new Typeinfo;string x=$2; $$->tempname=x; $$->tac=emptyvector();}		
		;

MethodDeclarator: LRB RRB										{$$=new Typeinfo; $$->tac=emptyvector();}	
		| LRB RRB OMPSB											{$$=new Typeinfo; $$->tac=emptyvector();}		
		| LRB FormalParameterList RRB							{$$=new Typeinfo;$$->tac=$2->tac;}		
		| LRB FormalParameterList RRB OMPSB							{$$=new Typeinfo;$$->tac=$2->tac;}	
		| LRB ReceiverParameterComma RRB						{$$=new Typeinfo;$$->tac=$2->tac;}
		| LRB ReceiverParameterComma RRB OMPSB						{$$=new Typeinfo;$$->tac=$2->tac;}
		| LRB ReceiverParameterComma FormalParameterList RRB		{$$=new Typeinfo;$$->tac=$3->tac;}
		| LRB ReceiverParameterComma FormalParameterList RRB OMPSB	    {$$=new Typeinfo;$$->tac=$3->tac;}
		;
ReceiverParameter:	 UnannType THIS							{$$=new Typeinfo; $$->tac=emptyvector();}			
		| UnannType IdentifierDot THIS						{$$=new Typeinfo; $$->tac=emptyvector();}	
		;
FormalParameterList: FormalParameter							{$$=new Typeinfo;$$->tac=$1->tac;}	
		| FormalParameter OMCommaFormalParameter				{$$=new Typeinfo;$$->tac=concvector($1->tac,$2->tac);}	
		;
FormalParameter: UnannType VariableDeclaratorId                         {$$=new Typeinfo;$$->tac=$2->tac;}	
		| OMClassModifier UnannType VariableDeclaratorId		        {$$=new Typeinfo;$$->tac=$3->tac;}		
		| VariableArityParameter								        {$$=new Typeinfo;$$->tac=$1->tac;}			
		;
VariableArityParameter:   UnannType THREEDOT Identifier				    {$$=new Typeinfo; $$->tac=emptyvector();}
		|	 OMClassModifier UnannType THREEDOT Identifier			{$$=new Typeinfo; $$->tac=emptyvector();}
		;

Throws:	 THROWS ExceptionTypeList								{$$=new Typeinfo; $$->tac=emptyvector();}	
		;
ExceptionTypeList:	 ExceptionType								{$$=new Typeinfo; $$->tac=emptyvector();}	
		| ExceptionType OMCommaExceptionType			{$$=new Typeinfo; $$->tac=emptyvector();}
		;
ExceptionType:   Identifier										{$$=new Typeinfo; $$->tac=emptyvector();}
		;

MethodBody:	 Block			{$$=new Typeinfo; $$->tac=$1->tac;}											
		| SEMICOLON			{$$=new Typeinfo; $$->tac=emptyvector();}										
		;	
InstanceInitializer:	 Block					{$$=new Typeinfo; $$->tac=$1->tac;}							
		;
StaticInitializer:	 STATIC Block				{$$=new Typeinfo; $$->tac=$2->tac;}							
		;
ConstructorDeclaration:	 ConstructorDeclarator ConstructorBody			{$$=new Typeinfo;string f = ($1)->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); $$->tac=concvector($1->tac,$2->tac,z,sv,p);}
		| ConstructorDeclarator Throws ConstructorBody				    {$$=new Typeinfo;string f = ($1)->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); $$->tac=concvector($1->tac,$3->tac,z,sv,p);}
		| OMClassModifier ConstructorDeclarator ConstructorBody			    {$$=new Typeinfo;string f = ($2)->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); $$->tac=concvector($2->tac,$3->tac,z,sv,p);}
		| OMClassModifier ConstructorDeclarator Throws ConstructorBody	{$$=new Typeinfo;string f = ($2)->tempname;string p=gotomethodretlabel(f); string z="constructor end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); $$->tac=concvector($2->tac,$4->tac,z,sv,p);}
		;
ConstructorDeclarator:   Identifier LRB RRB									{$$=new Typeinfo;string x = $1;$$->tempname=x;  string q=newmethodlabel(x);string p="call "+x+"\n"+q;$$->tac=concvector(p);}					
		|	 Identifier LRB FormalParameterList RRB								{$$=new Typeinfo;string x = $1;$$->tempname=x;  string q=newmethodlabel(x);string p="call "+x+"\n"+q;$$->tac=concvector(p,$3->tac);}						
		|	 Identifier LRB ReceiverParameterComma RRB							{$$=new Typeinfo; $$->tac=emptyvector();}			
		|	 Identifier LRB ReceiverParameterComma FormalParameterList RRB			{$$=new Typeinfo;$$->tac=$4->tac;}			
		|	 TypeParameters Identifier LRB RRB								{$$=new Typeinfo;string x = $2;$$->tempname=x;  string q=newmethodlabel(x);string p="call "+x+"\n"+q;$$->tac=concvector(p);}			
		|	 TypeParameters Identifier LRB FormalParameterList RRB						{$$=new Typeinfo;string x = $2;$$->tempname=x;  string q=newmethodlabel(x);string p="call "+x+"\n"+q;$$->tac=concvector(p,$4->tac);}			
		|	 TypeParameters Identifier LRB ReceiverParameterComma RRB		{$$=new Typeinfo; $$->tac=emptyvector();}				
		|	 TypeParameters Identifier LRB ReceiverParameterComma FormalParameterList RRB		{$$=new Typeinfo;$$->tac=$4->tac;}	
		;

ConstructorBody: LCB RCB											{$$=new Typeinfo; $$->tac=emptyvector();}	
		| LCB BlockStatements RCB									{$$=new Typeinfo;$$->tac=$2->tac;}		
		| LCB ExplicitConstructorInvocation RCB						{$$=new Typeinfo;$$->tac=$2->tac;}		
		| LCB ExplicitConstructorInvocation BlockStatements RCB			{$$=new Typeinfo; $$->tac=concvector($2->tac,$3->tac);}	
		;
ExplicitConstructorInvocation:	 THIS LRB RRB SEMICOLON					{$$=new Typeinfo;vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters();string s = ($1);($$)->tempname = "%rax";string s1 = gotomethod(s);string s2 = newmethodretlabel(s); $$->tac=concvector(pv1,s1,s2,pv2);}			
		| THIS LRB ArgumentList RRB SEMICOLON							{$$=new Typeinfo;vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters(); string s = ($1);($$)->tempname = "%rax"; string s1 = gotomethod(s);string s2 = newmethodretlabel(s);vector<string> pushpar = pusharg(($3)->params);$$->tac=concvector(pv1,$3->tac,pushpar,s1,s2,pv2);}	
		| SUPER LRB RRB SEMICOLON										{$$=new Typeinfo;$$->tac=emptyvector();}			
		| SUPER LRB ArgumentList RRB SEMICOLON							{$$=new Typeinfo;$$->tac=$3->tac;}		
		| Identifier DOT SUPER LRB RRB SEMICOLON						{$$=new Typeinfo;$$->tac=emptyvector();}			
		| Identifier DOT SUPER LRB ArgumentList RRB SEMICOLON			{$$=new Typeinfo;$$->tac=$5->tac;}			
		| ExpressionName DOT SUPER LRB RRB SEMICOLON					{$$=new Typeinfo;$$->tac=emptyvector();}			
		| ExpressionName DOT SUPER LRB ArgumentList RRB SEMICOLON		{$$=new Typeinfo;$$->tac=$5->tac;}			
		| Primary DOT SUPER LRB RRB SEMICOLON							{$$=new Typeinfo;$$->tac=emptyvector();}			
		| Primary DOT SUPER LRB ArgumentList RRB SEMICOLON				{$$=new Typeinfo;$$->tac=$5->tac;}			
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
RecordDeclaration:    RECORD Identifier RecordHeader RecordBody											{$$=new Typeinfo;$$->tac=concvector($3->tac,$4->tac);}
		|	 RECORD Identifier RecordHeader ClassImplements RecordBody									{$$=new Typeinfo;$$->tac=concvector($3->tac,$5->tac);}
		|	 RECORD Identifier TypeParameters RecordHeader RecordBody									{$$=new Typeinfo;$$->tac=concvector($4->tac,$5->tac);}
		|	 RECORD Identifier TypeParameters RecordHeader ClassImplements RecordBody					{$$=new Typeinfo;$$->tac=concvector($4->tac,$6->tac);}
		|	 OMClassModifier RECORD Identifier RecordHeader RecordBody										{$$=new Typeinfo;$$->tac=concvector($4->tac,$5->tac);}
		|	 OMClassModifier RECORD Identifier RecordHeader ClassImplements RecordBody				{$$=new Typeinfo;$$->tac=concvector($4->tac,$6->tac);}		
		|	 OMClassModifier RECORD Identifier TypeParameters RecordHeader RecordBody						{$$=new Typeinfo;$$->tac=concvector($5->tac,$6->tac);}
		|	 OMClassModifier RECORD Identifier TypeParameters RecordHeader ClassImplements RecordBody		{$$=new Typeinfo;$$->tac=concvector($5->tac,$7->tac);}
		;

RecordHeader:	 LRB RRB												{$$=new Typeinfo;$$->tac=emptyvector();}
		| LRB RecordComponentList RRB									{$$=new Typeinfo;$$->tac=$2->tac;}	
		;
RecordComponentList:  RecordComponent										{$$=new Typeinfo;$$->tac=$1->tac;}
		| RecordComponent OMCommaRecordComponent							{$$=new Typeinfo;$$->tac=concvector($1->tac,$2->tac);}	
		;
RecordComponent:    UnannType Identifier									{$$=new Typeinfo;$$->tac=emptyvector();}
		|	 VariableArityRecordComponent									{$$=new Typeinfo;$$->tac=$1->tac;}
		;

VariableArityRecordComponent:    UnannType THREEDOT Identifier							{$$=new Typeinfo;$$->tac=emptyvector();}
		;

RecordBody:	 LCB RCB													{$$=new Typeinfo;$$->tac=emptyvector();}
		| LCB OMRecordBodyDeclaration RCB								{$$=new Typeinfo;$$->tac=$2->tac;}	
		;
RecordBodyDeclaration:	 ClassBodyDeclaration						{$$=new Typeinfo;$$->tac=$1->tac;}		
		| CompactConstructorDeclaration									{$$=new Typeinfo;$$->tac=$1->tac;}	
		;
CompactConstructorDeclaration:    Identifier ConstructorBody			{$$=new Typeinfo;$$->tac=$2->tac;}	
		|	 OMClassModifier Identifier ConstructorBody					{$$=new Typeinfo;$$->tac=$3->tac;}	
		;

InterfaceDeclaration:	 NormalInterfaceDeclaration						{$$=new Typeinfo;$$->tac=$1->tac;}	
		;
NormalInterfaceDeclaration:   INTERFACE Identifier    InterfaceBody						{$$=new Typeinfo;$$->tac=$3->tac;}									
		|	 INTERFACE Identifier InterfacePermits       InterfaceBody									{$$=new Typeinfo;$$->tac=$4->tac;}	
		|	 INTERFACE Identifier InterfaceExtends        InterfaceBody								{$$=new Typeinfo;$$->tac=$4->tac;}
		|	 INTERFACE Identifier InterfaceExtends InterfacePermits       InterfaceBody				{$$=new Typeinfo;$$->tac=$5->tac;}						
		|	 INTERFACE Identifier TypeParameters       InterfaceBody														{$$=new Typeinfo;$$->tac=$4->tac;}
		|	 INTERFACE Identifier TypeParameters InterfacePermits       InterfaceBody							{$$=new Typeinfo;$$->tac=$5->tac;}				
		|	 INTERFACE Identifier TypeParameters InterfaceExtends      InterfaceBody									{$$=new Typeinfo;$$->tac=$5->tac;}		
		|	 INTERFACE Identifier TypeParameters InterfaceExtends InterfacePermits       InterfaceBody		{$$=new Typeinfo;$$->tac=$6->tac;}			
		|	 OMClassModifier INTERFACE Identifier     InterfaceBody														{$$=new Typeinfo;$$->tac=$4->tac;}
		|	 OMClassModifier INTERFACE Identifier InterfacePermits        InterfaceBody					{$$=new Typeinfo;$$->tac=$5->tac;}					
		|	 OMClassModifier INTERFACE Identifier InterfaceExtends      InterfaceBody									{$$=new Typeinfo;$$->tac=$5->tac;}
		|	 OMClassModifier INTERFACE Identifier InterfaceExtends InterfacePermits       InterfaceBody				{$$=new Typeinfo;$$->tac=$6->tac;}		
		|	 OMClassModifier INTERFACE Identifier TypeParameters     InterfaceBody											{$$=new Typeinfo;$$->tac=$5->tac;}
		|	 OMClassModifier INTERFACE Identifier TypeParameters InterfacePermits       InterfaceBody						{$$=new Typeinfo;$$->tac=$6->tac;}
		|	 OMClassModifier INTERFACE Identifier TypeParameters InterfaceExtends       InterfaceBody							{$$=new Typeinfo;$$->tac=$6->tac;}
		|	 OMClassModifier INTERFACE Identifier TypeParameters InterfaceExtends InterfacePermits      InterfaceBody		{$$=new Typeinfo;$$->tac=$7->tac;}
		;

InterfaceModifier:	 Modifieropt									{$$=new Typeinfo;$$->tac=$1->tac;}
		;
InterfaceExtends:	 EXTENDS InterfaceTypeList				{$$=new Typeinfo;$$->tac=$2->tac;}			
		;
InterfacePermits:	 PERMITS ExpressionName								{$$=new Typeinfo;$$->tac=$2->tac;}
		| PERMITS ExpressionName OMCommaTypeName						{$$=new Typeinfo;$$->tac=concvector($2->tac,$3->tac);}	
		;
InterfaceBody:	 LCB RCB												{$$=new Typeinfo;$$->tac=emptyvector();}
		| LCB OMInterfaceMemberDeclaration RCB							{$$=new Typeinfo;$$->tac=$2->tac;}
		;
InterfaceMemberDeclaration:	 ConstantDeclaration					{$$=new Typeinfo;$$->tac=$1->tac;}	
		| InterfaceMethodDeclaration									{$$=new Typeinfo;$$->tac=$1->tac;}
		| ClassDeclaration												{$$=new Typeinfo;$$->tac=$1->tac;}
		| InterfaceDeclaration										{$$=new Typeinfo;$$->tac=$1->tac;}
		| SEMICOLON															{$$=new Typeinfo;$$->tac=emptyvector();}
		;
ConstantDeclaration:	 UnannType VariableDeclaratorList SEMICOLON			{$$=new Typeinfo;($$)->puvariables=($2)->puvariables;vector<string> s = pushlocal(($2)->puvariables); $$->tac=concvector(s,$2->tac);}
		| OMClassModifier UnannType VariableDeclaratorList SEMICOLON		{$$=new Typeinfo;($$)->puvariables=($3)->puvariables;vector<string> s = pushlocal(($3)->puvariables); $$->tac=concvector(s,$3->tac);}
		;
InterfaceMethodDeclaration:	 MethodHeader MethodBody			{$$=new Typeinfo;string f = ($1)->tempname;string p=gotomethodretlabel(f); string z="function end";stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st);	currmethod.pop(); currmethodlocals.pop(); $$->tac=concvector($1->tac,$2->tac,z,sv,p);}
		| OMClassModifier MethodHeader MethodBody					{$$=new Typeinfo;string f = ($2)->tempname;string p=gotomethodretlabel(f); string z="function end"; stack<string>st = currmethodlocals.top(); vector<string>sv = poplocal(st); 	currmethod.pop(); currmethodlocals.pop(); $$->tac=concvector($2->tac,$3->tac,z,sv,p);}
		;
ArrayInitializer:	 LCB RCB												{$$=new Typeinfo;$$->tac=emptyvector();}
		| LCB COMMA RCB														{$$=new Typeinfo;$$->tac=emptyvector();}
		| LCB VariableInitializerList RCB							{$$=new Typeinfo;$$->tac=$2->tac;}		
		;
VariableInitializerList:	 VariableInitializer			{$$=new Typeinfo; $$->tac= $1->tac;}				
		| VariableInitializer OMCommaVariableInitializer	{$$=new Typeinfo; $$->tac= concvector($1->tac,$2->tac);}				
		;
Block:	 LCB RCB							{$$=new Typeinfo;vector<string>p={}; $$->tac=p;}									
		| LCB BlockStatements RCB			{$$=new Typeinfo; $$->tac= $2->tac;}							
		;
BlockStatements:	 BlockStatement			{$$=new Typeinfo; $$->tac= $1->tac;}								
		| BlockStatement OMBlockStatement			    {$$=new Typeinfo; $$->tac= concvector($1->tac,$2->tac);}					
		;
BlockStatement:	 LocalClassOrInterfaceDeclaration		{$$=new Typeinfo; $$->tac= $1->tac;}				
		| LocalVariableDeclarationStatement			    {$$=new Typeinfo; $$->tac= $1->tac;}						
		| Statement										{$$=new Typeinfo; $$->tac= $1->tac;}					
		;
LocalClassOrInterfaceDeclaration:	 ClassDeclaration			{$$=new Typeinfo; $$->tac= $1->tac;}			
		| NormalInterfaceDeclaration							{$$=new Typeinfo; $$->tac= $1->tac;}			
		;
LocalVariableDeclarationStatement:	 LocalVariableDeclaration SEMICOLON		{$$=new Typeinfo; $$->tac= $1->tac;}
		;
LocalVariableDeclaration:	 LocalVariableType VariableDeclaratorList		{$$=new Typeinfo; ($$)->puvariables=($2)->puvariables;vector<string> s = pushlocal(($2)->puvariables); $$->tac=concvector(s,$2->tac);}
		| OMClassModifier LocalVariableType VariableDeclaratorList			{$$=new Typeinfo; ($$)->puvariables=($3)->puvariables;vector<string> s = pushlocal(($3)->puvariables); $$->tac=concvector(s,$3->tac);}
		;
LocalVariableType:	 UnannType					{$$=new Typeinfo; $$->tac= $1->tac;}						
		| VAR												{$$=new Typeinfo; $$->tac= emptyvector();}			
		;
Statement:	 StatementWithoutTrailingSubstatement			{$$=new Typeinfo; $$->tac= $1->tac;}				
		| LabeledStatement								{$$=new Typeinfo; $$->tac= $1->tac;}					
		| IfThenStatement								{$$=new Typeinfo; $$->tac= $1->tac;}					
		| IfThenElseStatement							{$$=new Typeinfo; $$->tac= $1->tac;}					
		| WhileStatement						{$$=new Typeinfo; $$->tac= $1->tac;}							
		| ForStatement								{$$=new Typeinfo; $$->tac= $1->tac;}						
		;
StatementNoShortIf:	 StatementWithoutTrailingSubstatement		{$$=new Typeinfo; $$->tac= $1->tac;}			
		| LabeledStatementNoShortIf								{$$=new Typeinfo; $$->tac= $1->tac;}			
		| IfThenElseStatementNoShortIf							{$$=new Typeinfo; $$->tac= $1->tac;}			
		| WhileStatementNoShortIf				{$$=new Typeinfo; $$->tac= $1->tac;}							
		| ForStatementNoShortIf								{$$=new Typeinfo; $$->tac= $1->tac;}				
		;
StatementWithoutTrailingSubstatement:	 Block				{$$=new Typeinfo; $$->tac= $1->tac;}			    
		| EmptyStatement									{$$=new Typeinfo; $$->tac=$1->tac;}					
		| ExpressionStatement								{$$=new Typeinfo; $$->tac=$1->tac;}				
		| AssertStatement									{$$=new Typeinfo; $$->tac=$1->tac;}				
		| SwitchStatement									{$$=new Typeinfo; $$->tac=$1->tac;}				
		| DoStatement										{$$=new Typeinfo; $$->tac=$1->tac;}				
		| BreakStatement									{$$=new Typeinfo; $$->tac=$1->tac;}				
		| ContinueStatement									{$$=new Typeinfo; $$->tac=$1->tac;}				
		| ReturnStatement									{$$=new Typeinfo; $$->tac=$1->tac;}				
		| SynchronizedStatement								{$$=new Typeinfo; $$->tac=$1->tac;}				
		| ThrowStatement									{$$=new Typeinfo; $$->tac=$1->tac;}				
		| TryStatement										{$$=new Typeinfo; $$->tac=$1->tac;}				
		| YieldStatement									{$$=new Typeinfo; $$->tac=$1->tac;}				
		;
EmptyStatement:	 SEMICOLON			{$$=new Typeinfo; vector<string>p={}; $$->tac=p;}									   
		;
LabeledStatement:   Identifier COLON Statement					{$$=new Typeinfo; $$->tac= $3->tac;}	
		;
LabeledStatementNoShortIf:   Identifier COLON StatementNoShortIf		{$$=new Typeinfo; $$->tac= $3->tac;}	
		;

ExpressionStatement:  StatementExpression SEMICOLON		{$$=new Typeinfo; $$->tac=$1->tac;$$->tempname=$1->tempname;}		
		;
StatementExpression:	 Assignment				{$$=new Typeinfo; $$->tac=$1->tac;$$->tempname=$1->tempname;}						
		| PreIncrementExpression				{$$=new Typeinfo; $$->tac=$1->tac;$$->tempname=$1->tempname;}								
		| PreDecrementExpression				{$$=new Typeinfo; $$->tac=$1->tac;$$->tempname=$1->tempname;}								
		| PostIncrementExpression				{$$=new Typeinfo; $$->tac=$1->tac;$$->tempname=$1->tempname;}								
		| PostDecrementExpression				{$$=new Typeinfo; $$->tac=$1->tac;$$->tempname=$1->tempname;}								
		| MethodInvocation						{$$=new Typeinfo; $$->tac=$1->tac;$$->tempname=$1->tempname;}								
		| ClassInstanceCreationExpression		{$$=new Typeinfo; $$->tac=$1->tac;$$->tempname=$1->tempname;}							
		;
IfThenStatement: IF LRB Expression RRB Statement							{$$=new Typeinfo;int lv=labelvariable;string a=newlabel();string ret="if zero "+($3)->tempname+gotoo(lv+1);$$->tac=concvector($3->tac,ret,$5->tac,a);}
		;
IfThenElseStatement: IF LRB Expression RRB StatementNoShortIf ELSE Statement		{$$=new Typeinfo;int lv=labelvariable;string a=newlabel();string ret="if zero "+($3)->tempname+gotoo(lv+1);$$->tac=concvector($3->tac,ret,$5->tac,a,$7->tac);}
		;
IfThenElseStatementNoShortIf:	 IF LRB Expression RRB StatementNoShortIf ELSE StatementNoShortIf	{$$=new Typeinfo;int lv=labelvariable;string a=newlabel();string ret="if zero "+($3)->tempname+gotoo(lv+1);$$->tac=concvector($3->tac,ret,$5->tac,a,$7->tac);}
		;
AssertStatement:	 ASSERT Expression SEMICOLON					{$$=new Typeinfo; $$->tac=$2->tac;}				 
		| ASSERT Expression COLON Expression SEMICOLON					{$$=new Typeinfo; $$->tac= concvector($2->tac,$4->tac);}			
		;
SwitchStatement:	 SWITCH LRB Expression RRB SwitchBlock					{$$=new Typeinfo; $$->tac= concvector($3->tac,$5->tac);}	
		;
SwitchBlock:	 LCB SwitchRule RCB									{$$=new Typeinfo; $$->tac=$2->tac;}					
		| LCB SwitchRule OMSwitchRule RCB										{$$=new Typeinfo; $$->tac= concvector($2->tac,$3->tac);}	
		| LCB RCB															{$$=new Typeinfo; $$->tac=emptyvector();}											
		| LCB OMSwitchLabelColon RCB									{$$=new Typeinfo; $$->tac=$2->tac;}				
		| LCB OMSwitchBlockStatementGroup RCB								{$$=new Typeinfo; $$->tac=$2->tac;}			
		| LCB OMSwitchBlockStatementGroup OMSwitchLabelColon RCB		{$$=new Typeinfo; $$->tac= concvector($2->tac,$3->tac);}			
		;
SwitchRule:	 SwitchLabel IMPLIES Expression SEMICOLON					{$$=new Typeinfo; $$->tac= concvector($1->tac,$3->tac);}			
		| SwitchLabel IMPLIES Block										{$$=new Typeinfo; $$->tac= concvector($1->tac,$3->tac);}			
		| SwitchLabel IMPLIES ThrowStatement										{$$=new Typeinfo; $$->tac= concvector($1->tac,$3->tac);}
		;
SwitchBlockStatementGroup:	 SwitchLabel COLON BlockStatements						{$$=new Typeinfo; $$->tac= concvector($1->tac,$3->tac);}
		| SwitchLabel COLON OMSwitchLabelColon BlockStatements						{$$=new Typeinfo; $$->tac= concvector($1->tac,$3->tac,$4->tac);}
		;
SwitchLabel:	 CASE CaseConstant												{$$=new Typeinfo; $$->tac=$2->tac;}		
		| CASE CaseConstant OMCommaCaseConstant									{$$=new Typeinfo; $$->tac= concvector($2->tac,$3->tac);}	
		| DEFAULT																{$$=new Typeinfo; $$->tac=emptyvector();}		
		;
CaseConstant:	 ConditionalExpression										{$$=new Typeinfo; $$->tac=$1->tac;}			
		;		
WhileStatement:	 WHILE LRB Expression RRB Statement				{$$=new Typeinfo; int c=labelvariable; string a=newlabel();string b=newlabel();string z=gotoo(c+2);string d="if zero "+(($3)->tempname)+z;$$->tac=concvector($3->tac,a,d,$5->tac,gotoo(c+1),b);}										
		;
WhileStatementNoShortIf:	 WHILE LRB Expression RRB StatementNoShortIf		{$$=new Typeinfo; int c=labelvariable; string a=newlabel();string z=gotoo(c+2);string b=newlabel();string d="if zero "+(($3)->tempname)+z;$$->tac=concvector($3->tac,a,d,$5->tac,gotoo(c+1),b);}
		;
DoStatement:	 DO Statement WHILE LRB Expression RRB SEMICOLON			{$$=new Typeinfo; string p=gotoo(labelvariable); $$->tac=concvector($5->tac,p);}		
		;
ForStatement:	 BasicForStatement						{$$=new Typeinfo; $$->tac= $1->tac;}							
		| EnhancedForStatement							{$$=new Typeinfo; $$->tac= $1->tac;}								
		;
ForStatementNoShortIf:	 BasicForStatementNoShortIf		{$$=new Typeinfo; $$->tac= $1->tac;}								
		| EnhancedForStatementNoShortIf					{$$=new Typeinfo; $$->tac= $1->tac;}								
		;
BasicForStatement:	 FOR LRB SEMICOLON SEMICOLON RRB Statement						{$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();$$->tac=concvector(a,$6->tac,gotoo(lv+1),b);}
		| FOR LRB SEMICOLON SEMICOLON ForUpdate RRB Statement						{$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();$$->tac=concvector(a,$7->tac,$5->tac,gotoo(lv+1),b);}
		| FOR LRB SEMICOLON Expression SEMICOLON RRB Statement						{$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($4)->tempname+gotoo(lv+2);$$->tac=concvector(a,$4->tac,ret,$7->tac,gotoo(lv+1),b);}
		| FOR LRB SEMICOLON Expression SEMICOLON ForUpdate RRB Statement			{$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($4)->tempname+gotoo(lv+2);$$->tac=concvector(a,$4->tac,ret,$8->tac,$6->tac,gotoo(lv+1),b);}
		| FOR LRB ForInit SEMICOLON SEMICOLON RRB Statement							{$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();$$->tac=concvector($3->tac,a,$7->tac,gotoo(lv+1),b);}
		| FOR LRB ForInit SEMICOLON SEMICOLON ForUpdate RRB Statement				{$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();$$->tac=concvector($3->tac,a,$8->tac,$6->tac,gotoo(lv+1),b);}
		| FOR LRB ForInit SEMICOLON Expression SEMICOLON RRB Statement				{$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($5)->tempname+gotoo(lv+2);$$->tac=concvector($3->tac,a,$5->tac,ret,$8->tac,gotoo(lv+1),b);}
		| FOR LRB ForInit SEMICOLON Expression SEMICOLON ForUpdate RRB Statement	{$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($5)->tempname+gotoo(lv+2);$$->tac=concvector($3->tac,a,$5->tac,ret,$9->tac,$7->tac,gotoo(lv+1),b);}
		;
BasicForStatementNoShortIf:	 FOR LRB SEMICOLON SEMICOLON RRB StatementNoShortIf			{$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();$$->tac=concvector(a,$6->tac,gotoo(lv+1),b);}
		| FOR LRB SEMICOLON SEMICOLON ForUpdate RRB StatementNoShortIf					{$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();$$->tac=concvector(a,$7->tac,$5->tac,gotoo(lv+1),b);}	
		| FOR LRB SEMICOLON Expression SEMICOLON RRB StatementNoShortIf					{$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($4)->tempname+gotoo(lv+2);$$->tac=concvector(a,$4->tac,ret,$7->tac,gotoo(lv+1),b);}	
		| FOR LRB SEMICOLON Expression SEMICOLON ForUpdate RRB StatementNoShortIf		{$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($4)->tempname+gotoo(lv+2);$$->tac=concvector(a,$4->tac,ret,$8->tac,$6->tac,gotoo(lv+1),b);}	
		| FOR LRB ForInit SEMICOLON SEMICOLON RRB StatementNoShortIf					{$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();$$->tac=concvector($3->tac,a,$7->tac,gotoo(lv+1),b);}	
		| FOR LRB ForInit SEMICOLON SEMICOLON ForUpdate RRB StatementNoShortIf			{$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();$$->tac=concvector($3->tac,a,$8->tac,$6->tac,gotoo(lv+1),b);}	
		| FOR LRB ForInit SEMICOLON Expression SEMICOLON RRB StatementNoShortIf			{$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($5)->tempname+gotoo(lv+2);$$->tac=concvector($3->tac,a,$5->tac,ret,$8->tac,gotoo(lv+1),b);}		
		| FOR LRB ForInit SEMICOLON Expression SEMICOLON ForUpdate RRB StatementNoShortIf	{$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($5)->tempname+gotoo(lv+2);$$->tac=concvector($3->tac,a,$5->tac,ret,$9->tac,$7->tac,gotoo(lv+1),b);}
		;
ForInit:	 StatementExpressionList								{$$=new Typeinfo; $$->tac=$1->tac;}					
		| LocalVariableDeclaration									{$$=new Typeinfo; $$->tac=$1->tac;}						
		;	
ForUpdate:	 StatementExpressionList								{$$=new Typeinfo; $$->tac=$1->tac;}						
		;
StatementExpressionList:	 StatementExpression					{$$=new Typeinfo; $$->tac=$1->tac;}					
		| StatementExpression OMCommaStatementExpression			{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}					
		;
EnhancedForStatement:	 FOR LRB LocalVariableDeclaration COLON Expression RRB Statement		{$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($5)->tempname+gotoo(lv+2);$$->tac=concvector(a,$3->tac,$5->tac,ret,$7->tac,gotoo(lv+1),b);}				
		;
EnhancedForStatementNoShortIf:	 FOR LRB LocalVariableDeclaration COLON Expression RRB StatementNoShortIf	{$$=new Typeinfo; int lv=labelvariable; string a=newlabel();string b=newlabel();string ret="if zero"+($5)->tempname+gotoo(lv+2);$$->tac=concvector(a,$3->tac,$5->tac,ret,$7->tac,gotoo(lv+1),b);}	
		;
BreakStatement:   		 BREAK SEMICOLON							{$$=new Typeinfo;string p=gotoo(labelvariable+1); $$->tac={p};}												
		|	 BREAK Identifier SEMICOLON								{$$=new Typeinfo;string p=gotoo(labelvariable+1); $$->tac={p};}										
		;

YieldStatement:	 YIELD Expression SEMICOLON								{$$=new Typeinfo; $$->tac=$2->tac;}													
		;
ContinueStatement:   CONTINUE SEMICOLON									{$$=new Typeinfo;string p=gotoo(labelvariable); $$->tac={p};}											
		|	 CONTINUE Identifier SEMICOLON								{$$=new Typeinfo;string p=gotoo(labelvariable); $$->tac={p};}											
		;

ReturnStatement:	 RETURN SEMICOLON			{$$=new Typeinfo;string p=gotomethodretlabel(currmethod.top()); $$->tac={p};}									
		| RETURN Expression SEMICOLON				{$$=new Typeinfo;string p=gotomethodretlabel(currmethod.top());string s = "%rax = " + $2->tempname; $$->tac=concvector($2->tac,s,p);}									
		;	
ThrowStatement:	 THROW Expression SEMICOLON									{$$=new Typeinfo; $$->tac=$2->tac;}		
		;
SynchronizedStatement:	 SYNCHRONIZED LRB Expression RRB Block					{$$=new Typeinfo; $$->tac=concvector($3->tac,$5->tac);}			
		;
TryStatement:	 TRY Block Catches										{$$=new Typeinfo; $$->tac=concvector($2->tac,$3->tac);}				
		| TRY Block Finally												{$$=new Typeinfo; $$->tac=concvector($2->tac,$3->tac);}					
		| TRY Block Catches Finally											{$$=new Typeinfo; $$->tac=concvector($2->tac,$3->tac,$4->tac);}				
		| TryWithResourcesStatement																	{$$=new Typeinfo; $$->tac=$1->tac;}							
		;
Catches:	 CatchClause									{$$=new Typeinfo; $$->tac=$1->tac;}							
		| CatchClause OMCatchClause							{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}							
		;
CatchClause:	 CATCH LRB CatchFormalParameter RRB Block			{$$=new Typeinfo; $$->tac=concvector($3->tac,$5->tac);}						
		;
CatchFormalParameter:	 CatchType VariableDeclaratorId					{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);}				
		| OMClassModifier CatchType VariableDeclaratorId				{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac,$3->tac);}					
		;
CatchType:   		 Identifier									{$$=new Typeinfo; $$->tac=emptyvector();}							
		|	 Identifier OMOrClassType							{$$=new Typeinfo; $$->tac=$2->tac;}						
		;

Finally:	 FINALLY Block											{$$=new Typeinfo; $$->tac=$2->tac;}						
		;	
TryWithResourcesStatement:	 TRY ResourceSpecification Block			{$$=new Typeinfo; $$->tac=concvector($2->tac,$3->tac);}				
		| TRY ResourceSpecification Block Finally						{$$=new Typeinfo; $$->tac=concvector($2->tac,$3->tac,$4->tac);}					
		| TRY ResourceSpecification Block Catches					{$$=new Typeinfo; $$->tac=concvector($2->tac,$3->tac,$4->tac);}						
		| TRY ResourceSpecification Block Catches Finally				{$$=new Typeinfo; $$->tac=concvector($2->tac,$3->tac,$4->tac,$5->tac);}					
		;
ResourceSpecification:	 LRB ResourceList RRB		{$$=new Typeinfo; $$->tac=$2->tac;}										
		;
ResourceList:	 Resource							{$$=new Typeinfo; $$->tac=$1->tac;}										
		| OMSemicolonResource						{$$=new Typeinfo; $$->tac=$1->tac;}										
		;
Resource:	 LocalVariableDeclaration						{$$=new Typeinfo; $$->tac=$1->tac;}								
		| VariableAccess										{$$=new Typeinfo; $$->tac=$1->tac;}						
		;
Primary:	 PrimaryNoNewArray									{$$=new Typeinfo; $$=$1;}					
		| ArrayCreationExpression								{$$=new Typeinfo; $$->tac=$1->tac;}							
		;
PrimaryNoNewArray:	 Literal						{$$=new Typeinfo; $$=$1;}
		| ClassLiteral								{$$=new Typeinfo; $$=$1;}									
		| THIS										{$$=new Typeinfo; $$->tac=emptyvector();$$->tempname="this";}									
		| Identifier DOT THIS						{$$=new Typeinfo;string x=$1; $$->tac=emptyvector();$$->tempname=x;}							
		| ExpressionName DOT THIS					{$$=new Typeinfo; $$=$1;}								
		| LRB Expression RRB						{$$=new Typeinfo; $$=$2;}								
		| ClassInstanceCreationExpression			{$$=new Typeinfo; $$=$1;}									
		| FieldAccess								{$$=new Typeinfo; $$=$1;}								
		| ArrayAccess								{$$=new Typeinfo; $$=$1;}								
		| MethodInvocation							{$$=new Typeinfo; $$=$1;}									
		| MethodReference							{$$=new Typeinfo; $$=$1;}								
		;
ClassLiteral:	 Identifier DOT CLASS					{$$=new Typeinfo; $$->tac=emptyvector();}										
		| ExpressionName DOT CLASS						{$$=new Typeinfo; $$->tac=emptyvector();}										
		| Identifier OMPSB DOT CLASS					{$$=new Typeinfo; $$->tac=emptyvector();}										
		| ExpressionName OMPSB DOT CLASS													{$$=new Typeinfo; $$->tac=emptyvector();}	
		| UnannPrimitiveType DOT CLASS													{$$=new Typeinfo; $$->tac=emptyvector();}	
		| VOID DOT CLASS																	{$$=new Typeinfo; $$->tac=emptyvector();}	
		;
ClassInstanceCreationExpression:	 UnqualifiedClassInstanceCreationExpression			{$$=new Typeinfo; $$->tac=$1->tac;}	
		| Identifier DOT UnqualifiedClassInstanceCreationExpression						{$$=new Typeinfo; $$->tac=$3->tac;}	
		| ExpressionName DOT UnqualifiedClassInstanceCreationExpression					{$$=new Typeinfo; $$->tac=$3->tac;}	
		| Primary DOT UnqualifiedClassInstanceCreationExpression						{$$=new Typeinfo; $$->tac=$3->tac;}	
		;
UnqualifiedClassInstanceCreationExpression:	 NEW ClassOrInterfaceTypeToInstantiate LRB RRB 		{$$=new Typeinfo; $$->tac=$2->tac;}	
		| NEW ClassOrInterfaceTypeToInstantiate LRB RRB ClassBody								{$$=new Typeinfo; $$->tac=concvector($2->tac,$5->tac);}	
		| NEW ClassOrInterfaceTypeToInstantiate LRB ArgumentList RRB							{$$=new Typeinfo; $$->tac=concvector($2->tac,$4->tac);}	
		| NEW ClassOrInterfaceTypeToInstantiate LRB ArgumentList RRB ClassBody				{$$=new Typeinfo; $$->tac=concvector($2->tac,$4->tac,$6->tac);}	
		;
ClassOrInterfaceTypeToInstantiate:   Identifier										{$$=new Typeinfo; $$->tac=emptyvector();}	
		|	Identifier OMDotIdentifier												{$$=new Typeinfo; $$->tac=emptyvector();}	
		;
FieldAccess:   Primary DOT Identifier								{$$=new Typeinfo; $$->tac=emptyvector();}
		|	 SUPER DOT Identifier									{$$=new Typeinfo; $$->tac=emptyvector();}
		|	 Identifier DOT SUPER DOT Identifier					{$$=new Typeinfo; $$->tac=emptyvector();}
		|	 ExpressionName DOT SUPER DOT Identifier				{$$=new Typeinfo; $$->tac=$1->tac;}
		;
ArrayAccess:   Identifier LSB Expression RSB			{$$=new Typeinfo; $$->tac=$3->tac;}
		|	 ExpressionName LSB Expression RSB				{$$=new Typeinfo; $$->tac=concvector($1->tac,$3->tac);}
		|	 PrimaryNoNewArray LSB Expression RSB			{$$=new Typeinfo; $$->tac=concvector($1->tac,$3->tac);}
		;
MethodInvocation:   MethodName LRB ArgumentList RRB				{$$=new Typeinfo;vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters(); string s = ($1)->tempname;($$)->tempname = "%rax"; string s1 = gotomethod(s);string s2 = newmethodretlabel(s);vector<string> pushpar = pusharg(($3)->params);$$->tac=concvector(pv1,$3->tac,pushpar,s1,$1->tac,s2,pv2);}				
		|	 MethodName LRB RRB									{$$=new Typeinfo;vector<string>pv1 = pushregisters();vector<string>pv2 = popregisters();string s = ($1)->tempname;($$)->tempname = "%rax";string s1 = gotomethod(s);string s2 = newmethodretlabel(s); $$->tac=concvector(pv1,s1,$1->tac,s2,pv2);}			
		|	 Identifier DOT Identifier LRB RRB					{$$=new Typeinfo; $$->tac=emptyvector();}			
		|	 Identifier DOT Identifier LRB ArgumentList RRB					{$$=new Typeinfo; $$->tac=$5->tac;}		
		|	 ExpressionName DOT Identifier LRB RRB							{$$=new Typeinfo; $$->tac=$1->tac;}				
		|	 ExpressionName DOT Identifier LRB ArgumentList RRB				{$$=new Typeinfo; $$->tac=concvector($1->tac,$5->tac);}				
		|	 Primary DOT Identifier LRB RRB									{$$=new Typeinfo; $$->tac=$1->tac;}				
		|	 Primary DOT Identifier LRB ArgumentList RRB					{$$=new Typeinfo; $$->tac=$1->tac;}				
		|	 SUPER DOT Identifier LRB RRB									{$$=new Typeinfo; $$->tac=emptyvector();}			
		|	 SUPER DOT Identifier LRB ArgumentList RRB						{$$=new Typeinfo; $$->tac=emptyvector();}			
		|	 Identifier DOT SUPER DOT Identifier LRB RRB						{$$=new Typeinfo; $$->tac=emptyvector();}		
		|	 Identifier DOT SUPER DOT Identifier LRB ArgumentList RRB			{$$=new Typeinfo; $$->tac=$7->tac;}			
		|	 ExpressionName DOT SUPER DOT Identifier LRB RRB					{$$=new Typeinfo; $$->tac=$1->tac;}			
		|	 ExpressionName DOT SUPER DOT Identifier LRB ArgumentList RRB			{$$=new Typeinfo; $$->tac=concvector($1->tac,$7->tac);}		
		;

ArgumentList:	 Expression												{$$=new Typeinfo; $$->tac=$1->tac;string s = ($1)->tempname; $$->params.push_back(s);}	
		| Expression OMCommaExpression									{$$=new Typeinfo; $$->tac=concvector($1->tac,$2->tac);string s = ($1)->tempname; $$->params.push_back(s); for(auto z:($2)->params)($$)->params.push_back(z);}	
		;
MethodReference:   Identifier DOUBLECOLON Identifier			{$$=new Typeinfo; $$->tac=emptyvector();}	
		|	 ExpressionName DOUBLECOLON Identifier				{$$=new Typeinfo; $$->tac=$1->tac;}	
		|	 Primary DOUBLECOLON Identifier						{$$=new Typeinfo; $$->tac=emptyvector();}		
		|	 UnannArrayType DOUBLECOLON Identifier				{$$=new Typeinfo; $$->tac=emptyvector();}		
		|	 SUPER DOUBLECOLON Identifier							{$$=new Typeinfo; $$->tac=emptyvector();}	
		|	 Identifier DOT SUPER DOUBLECOLON Identifier			{$$=new Typeinfo; $$->tac=emptyvector();}	
		|	 ExpressionName DOT SUPER DOUBLECOLON Identifier			{$$=new Typeinfo; $$->tac=$1->tac;}			
		|	 UnannArrayType DOUBLECOLON NEW							{$$=new Typeinfo; $$->tac=emptyvector();}				
		;
ArrayCreationExpression:   NEW PrimitiveType OMDimExpr				{$$=new Typeinfo; $$->tac=emptyvector();}				
		|	 NEW PrimitiveType OMDimExpr OMPSB						{$$=new Typeinfo; $$->tac=emptyvector();}				
		|	 NEW Identifier OMDimExpr								{$$=new Typeinfo; $$->tac=emptyvector();}				
		|	 NEW Identifier OMDimExpr OMPSB								{$$=new Typeinfo; $$->tac=emptyvector();}			
		|	 NEW PrimitiveType OMPSB ArrayInitializer					{$$=new Typeinfo; $$->tac=$4->tac;}			
		|	 NEW Identifier OMPSB ArrayInitializer							{$$=new Typeinfo; $$->tac=$4->tac;}		
		;

DimExpr:	 LSB Expression RSB				{$$=new Typeinfo; $$=$2;}				
		;
Expression:	AssignmentExpression				{$$=new Typeinfo; $$=$1;}			    
		;
AssignmentExpression:	 ConditionalExpression		{$$=new Typeinfo; $$=$1;}			
		| Assignment								{$$=new Typeinfo; $$=$1;}		
		;
Assignment:	 LeftHandSide AssignmentOperator Expression			{$$=new Typeinfo;string p=($1)->tempname+" = "+($3)->tempname;$$->tempname=($1)->tempname;$$->tac=concvector($1->tac,$3->tac,p);}					
		;
LeftHandSide:	 ExpressionName								{$$=new Typeinfo; $$=$1;}					
   		| Identifier										{$$=new Typeinfo; string x=$1; string p=newtemp();$$->tempname=p;p=p+" = "+x; $$->tac={p};}					
		| FieldAccess											{$$=new Typeinfo; $$=$1;}				
		| ArrayAccess											{$$=new Typeinfo; $$=$1;}				
		;
AssignmentOperator:	 ASSIGNMENTOPERATOR					{$$=$1;}
		;
ConditionalExpression:	 ConditionalOrExpression				{$$=new Typeinfo; $$=$1;}
		| ConditionalOrExpression QM Expression COLON ConditionalExpression		{$$=new Typeinfo;int lv=labelvariable;string a=newlabel();string ret="if zero "+($1)->tempname+gotoo(lv+1);$$->tac=concvector($1->tac,ret,$3->tac,a,$5->tac);}
		;
ConditionalOrExpression:	 ConditionalAndExpression			{$$=new Typeinfo; $$=$1;}
		| ConditionalOrExpression OR ConditionalAndExpression 	{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" || "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);}						
		;
ConditionalAndExpression:	 InclusiveOrExpression				{$$=new Typeinfo; $$=$1;}	
		| ConditionalAndExpression AND InclusiveOrExpression	{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" && "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);}					
		;
InclusiveOrExpression:	 ExclusiveOrExpression					{$$=new Typeinfo; $$=$1;}	
		| InclusiveOrExpression BITOR ExclusiveOrExpression		{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" | "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);}				
		;
ExclusiveOrExpression:	 AndExpression							{$$=new Typeinfo; $$=$1;}					
		| ExclusiveOrExpression BITXOR AndExpression			{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" ^ "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);}				
		;
AndExpression:	 EqualityExpression								{$$=new Typeinfo; $$=$1;}				
		| AndExpression BITAND EqualityExpression				{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" & "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);}				
		;
EqualityExpression:	 RelationalExpression						 	{$$=new Typeinfo; $$=$1;}			
		| EqualityExpression DOUBLEEQUAL RelationalExpression	  	{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" == "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);}			
		| EqualityExpression NE RelationalExpression			  	{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" != "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);}		
		;
RelationalExpression:	 ShiftExpression						{$$=new Typeinfo; $$=$1;}
		| RelationalExpression LT ShiftExpression				 {$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" < "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);} 				
		| RelationalExpression GT ShiftExpression				 {$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" > "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);} 			
		| RelationalExpression LTE ShiftExpression				 {$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" <= "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);} 				
		| RelationalExpression GTE ShiftExpression				 {$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" >= "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);} 				
		| InstanceofExpression									 {$$=new Typeinfo; $$=$1;}				
		;
InstanceofExpression:	 RelationalExpression INSTANCEOF ReferenceType			{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" instanceof "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);}	
		;
ShiftExpression:	 AdditiveExpression							{$$=new Typeinfo; $$=$1;}			
		| ShiftExpression LSHIFT AdditiveExpression				{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" << "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);}			
		| ShiftExpression RSHIFT AdditiveExpression				{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" >> "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);}				
		| ShiftExpression THREEGT AdditiveExpression			{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" >>> "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);}				
		;
AdditiveExpression:	 MultiplicativeExpression					{$$=new Typeinfo; $$=$1;}		
		| AdditiveExpression PLUS MultiplicativeExpression		{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" + "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);}								
		| AdditiveExpression MINUS MultiplicativeExpression		{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" - "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);}										
		;
MultiplicativeExpression:	 UnaryExpression					{$$=new Typeinfo; $$=$1;}	
		| MultiplicativeExpression MULTIPLY UnaryExpression		{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" * "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);}											
		| MultiplicativeExpression DIVIDE UnaryExpression		{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" / "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);}										
		| MultiplicativeExpression PERCENT UnaryExpression		{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" % "+$3->tempname;$$->tac=concvector($1->tac,$3->tac,a);}											
		;
UnaryExpression:	 PreIncrementExpression						{$$=new Typeinfo; $$=$1;}		
		| PreDecrementExpression								{$$=new Typeinfo; $$=$1;}		
		| PLUS UnaryExpression									{$$=new Typeinfo; $$=$2;}									
		| MINUS UnaryExpression									{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+" - "+$2->tempname;$$->tac=concvector($2->tac,a);}						
		| UnaryExpressionNotPlusMinus							{$$=new Typeinfo; $$=$1;}		
		;
PreIncrementExpression:	 INCREAMENT UnaryExpression				{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$2->tempname+" + 1 ";$$->tac=concvector($2->tac,a);}	
		;
PreDecrementExpression:	 DECREAMENT UnaryExpression				{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$2->tempname+" - 1 ";$$->tac=concvector($2->tac,a);}	
		;
UnaryExpressionNotPlusMinus:	 PostfixExpression				{$$=new Typeinfo; $$=$1;}		
		| TILDA UnaryExpression									{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+" ~ "+$2->tempname;$$->tac=concvector($2->tac,a);}		
		| EXCLAM UnaryExpression								{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+" ! "+$2->tempname;$$->tac=concvector($2->tac,a);}		
		| CastExpression										{$$=new Typeinfo; $$=$1;}		
		| SwitchExpression										{$$=new Typeinfo; $$=$1;}		
		;
PostfixExpression:	 Primary							{$$=new Typeinfo; $$=$1;}			
		| Identifier									{$$=new Typeinfo; string a=$1; string b=newtemp();$$->tempname=b;b=b+" = "+a;$$->tac={b};$$->tac={b};}			
		| ExpressionName								{$$=new Typeinfo; $$=$1;}				
		| PostIncrementExpression						{$$=new Typeinfo; $$=$1;}				
		| PostDecrementExpression						{$$=new Typeinfo; $$=$1;}				
		;
PostIncrementExpression:	 PostfixExpression INCREAMENT		{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" + 1 ";$$->tac=concvector($1->tac,a);}	
		;
PostDecrementExpression:	 PostfixExpression DECREAMENT		{$$=new Typeinfo;string a=newtemp();$$->tempname=a;a=a+" = "+$1->tempname+" - 1 ";$$->tac=concvector($1->tac,a);}	
		;
CastExpression:	 LRB PrimitiveType RRB UnaryExpression				                {$$=new Typeinfo; string a=newtemp();$$->tempname=a;a=a+" = "+$4->tempname;$$->tac=concvector($4->tac,a);}						
		| LRB UnannArrayType RRB UnaryExpressionNotPlusMinus			            {$$=new Typeinfo; string a=newtemp();$$->tempname=a;a=a+" = "+$4->tempname;$$->tac=concvector($4->tac,a);}				
		| LRB UnannArrayType OMAdditionalBound RRB UnaryExpressionNotPlusMinus		{$$=new Typeinfo; string a=newtemp();$$->tempname=a;a=a+" = "+$5->tempname;$$->tac=concvector($5->tac,a);}
		;
SwitchExpression:	 SWITCH LRB Expression RRB SwitchBlock							{$$=new Typeinfo; $$->tac=concvector($3->tac,$5->tac);}
		;	
VariableAccess:	 ExpressionName											{$$=new Typeinfo; $$=$1;}				
    	| Identifier													{$$=new Typeinfo; string a=$1; string b=newtemp();$$->tempname=b;b=b+" = "+a;$$->tac={b};$$->tac={b};}		
		| FieldAccess													{$$=new Typeinfo; $$=$1;}				
		;
%%
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