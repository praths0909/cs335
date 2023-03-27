%{
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
    int linenumber;
    int offset;
    string type;     // identifier,method,record,enum,
    string modifier; // public,private
    string lexeme;
    int size;
    string scope;
    // int level;
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
		if(type == "int"){
			a->size = 4;
		}
		else if(type == "float"){
			a->size = 4;
		}
		else if(type == "double"){
			a->size = 8;
		}
		else if(type == "char"){
			a->size = 2;
		}
		else if(type == "long"){
			a->size = 8;
		}
		else if(type == "short"){
			a->size = 2;
		}
		else if(type == "byte"){
			a->size = 1;
		}
		else if(type == "boolean"){
			a->size = 1;
		}
		else{
			a->size = 0;
		}
		}
		else{
			cout<< "Error: Method is already declared "<<lexeme<<endl;
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
	string type;
	vector<string>variables; //for variable declator list
	vector<string>type_variable; //for variable_types formalparameter declator list
	string name;
	symtable *scope;
	int linep;
};
int flag = 0;
Typeinfo *createstruct(){
	Typeinfo * t = new Typeinfo;
	return t;
};
%}

%union {char* str;struct Node* node; struct Typeinfo* typeinfo;}         /* Yacc definitions */



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

%type <typeinfo> CompactConstructorDeclarationSym RecordDeclarationSym ConstructorDeclaratorLRBSym TryBlockSym TrySym ForSym		OMPSB   PSB   OMAdditionalBound   ReceiverParameterComma   IdentifierDot   OMImportDeclaration   OMTopLevelClassOrInterfaceDeclaration   OMDotIdentifier   OMModuleDirective   OMRequiresModifier   OMCommaModuleName   CommaModuleName   OMCommaTypeName   CommaTypeName   OMClassModifier   OMCommaTypeParameter   CommaTypeParameter   OMCommaInterfaceType   CommaInterfaceType   OMClassBodyDeclaration   EqualVariableInitializer   OMCommaFormalParameter   CommaFormalParameter   OMCommaExceptionType   CommaExceptionType   OMCommaRecordComponent   CommaRecordComponent     OMRecordBodyDeclaration   OMInterfaceMemberDeclaration    OMCommaVariableInitializer   CommaVariableInitializer   OMBlockStatement   OMSwitchRule   OMSwitchBlockStatementGroup   OMSwitchLabelColon   SwitchLabelColon   OMCommaCaseConstant   CommaCaseConstant   OMCommaStatementExpression   CommaStatementExpression   OMCatchClause   OMOrClassType   OrClassType   OMSemicolonResource   SemicolonResource   OMCommaExpression   CommaExpression   OMDimExpr   Modifieropt   UnqualifiedMethodIdentifier   Literal   PrimitiveType   NumericType   IntegralType   FloatingPointType   ReferenceType   TypeParameter   TypeBound   AdditionalBound  ModuleName   ExpressionName   MethodName   CompilationUnit   OrdinaryCompilationUnit   ModularCompilationUnit   PackageDeclaration   ImportDeclaration   SingleTypeImportDeclaration   SingleStaticImportDeclaration   ImportOnDemandDeclaration   StaticImportOnDemandDeclaration   TopLevelClassOrInterfaceDeclaration   ModuleDeclaration   ModuleDirective   ClassDeclaration   NormalClassDeclaration   TypeParameters   TypeParameterList   ClassExtends   ClassImplements   InterfaceTypeList   ClassPermits   ClassBody   ClassBodyDeclaration   ClassMemberDeclaration   FieldDeclaration   VariableDeclaratorList   VariableDeclarator   VariableDeclaratorId   VariableInitializer   UnannType   UnannPrimitiveType   UnannArrayType   MethodDeclaration   MethodHeader   Result   MethodDeclarator   ReceiverParameter   FormalParameterList   FormalParameter   VariableArityParameter   Throws   ExceptionTypeList   ExceptionType   MethodBody   InstanceInitializer   StaticInitializer   ConstructorDeclaration   ConstructorDeclarator   ConstructorBody   ExplicitConstructorInvocation    RecordDeclaration   RecordHeader   RecordComponentList   RecordComponent   VariableArityRecordComponent   RecordBody   RecordBodyDeclaration   CompactConstructorDeclaration   InterfaceDeclaration   NormalInterfaceDeclaration   InterfaceModifier   InterfaceExtends   InterfacePermits   InterfaceBody   InterfaceMemberDeclaration   ConstantDeclaration   InterfaceMethodDeclaration   ArrayInitializer   VariableInitializerList   Block   BlockStatements   BlockStatement   LocalClassOrInterfaceDeclaration   LocalVariableDeclarationStatement   LocalVariableDeclaration   LocalVariableType   Statement   StatementNoShortIf   StatementWithoutTrailingSubstatement   EmptyStatement   LabeledStatement   LabeledStatementNoShortIf   ExpressionStatement   StatementExpression   IfThenStatement   IfThenElseStatement   IfThenElseStatementNoShortIf   AssertStatement   SwitchStatement   SwitchBlock   SwitchRule   SwitchBlockStatementGroup   SwitchLabel   CaseConstant   WhileStatement   WhileStatementNoShortIf   DoStatement   ForStatement   ForStatementNoShortIf   BasicForStatement   BasicForStatementNoShortIf   ForInit   ForUpdate   StatementExpressionList   EnhancedForStatement   EnhancedForStatementNoShortIf   BreakStatement   YieldStatement   ContinueStatement   ReturnStatement   ThrowStatement   SynchronizedStatement   TryStatement   Catches   CatchClause   CatchFormalParameter   CatchType   Finally   TryWithResourcesStatement   ResourceSpecification   ResourceList   Resource   Primary   PrimaryNoNewArray   ClassLiteral   ClassInstanceCreationExpression   UnqualifiedClassInstanceCreationExpression   ClassOrInterfaceTypeToInstantiate   FieldAccess   ArrayAccess   MethodInvocation   ArgumentList   MethodReference   ArrayCreationExpression   DimExpr   Expression   AssignmentExpression   Assignment   LeftHandSide     ConditionalExpression   ConditionalOrExpression   ConditionalAndExpression   InclusiveOrExpression   ExclusiveOrExpression   AndExpression   EqualityExpression   RelationalExpression   InstanceofExpression   ShiftExpression   AdditiveExpression   MultiplicativeExpression   UnaryExpression   PreIncrementExpression   PreDecrementExpression   UnaryExpressionNotPlusMinus   PostfixExpression   PostIncrementExpression   PostDecrementExpression   CastExpression   SwitchExpression   VariableAccess   


%%

OMPSB:  PSB								{$$ = createstruct();($$)->type = ($1)->type ;}										
		|	OMPSB PSB					{$$ = createstruct();($$)->type = ($1)->type + "[]";}										
		;
PSB: LSB RSB		{$$ = createstruct();($$)->type = "[]";}														
		;
OMAdditionalBound:   AdditionalBound										
        |	OMAdditionalBound   AdditionalBound 							
        ;
ReceiverParameterComma: ReceiverParameter COMMA								
        ;
IdentifierDot:  Identifier DOT			{$$ = createstruct();}									
        ;
OMImportDeclaration: ImportDeclaration										
    	|   OMImportDeclaration ImportDeclaration 							
    	;
OMTopLevelClassOrInterfaceDeclaration: TopLevelClassOrInterfaceDeclaration 						
    	|   OMTopLevelClassOrInterfaceDeclaration TopLevelClassOrInterfaceDeclaration 			
    	;
OMDotIdentifier: DOT Identifier					{$$ = createstruct();string p=($2);($$)->name="."+p;}										
    	|  OMDotIdentifier DOT Identifier	    {$$ = createstruct();string p=($3);($$)->name=($1)->name+"."+p;}								
    	;
OMModuleDirective: ModuleDirective											
    	|  OMModuleDirective ModuleDirective 								
    	;
OMRequiresModifier: Modifieropt												
    	| OMRequiresModifier  Modifieropt									
    	;
OMCommaModuleName: CommaModuleName											
    	|  OMCommaModuleName CommaModuleName 								
    	;
CommaModuleName:    COMMA ModuleName						{$$ = createstruct();}				
    	;
OMCommaTypeName: CommaTypeName 												
    	|  OMCommaTypeName CommaTypeName 									
    	;
CommaTypeName:    COMMA Identifier								{$$ = createstruct();}			
    	|  COMMA ExpressionName								{$$ = createstruct();}				
    	;
OMClassModifier:    InterfaceModifier										
        |     OMClassModifier  InterfaceModifier							
        ;
OMCommaTypeParameter:   CommaTypeParameter									
        |      OMCommaTypeParameter CommaTypeParameter 						
        ;	
CommaTypeParameter:     COMMA TypeParameter						{$$ = createstruct();}			
        ;
OMCommaInterfaceType:    CommaInterfaceType									
        |      OMCommaInterfaceType CommaInterfaceType 						
        ;
CommaInterfaceType:     COMMA Identifier								{$$ = createstruct();}	
        ;
OMClassBodyDeclaration:  ClassBodyDeclaration								
        |    OMClassBodyDeclaration   ClassBodyDeclaration 					
        ;
EqualVariableInitializer:   EQUAL VariableInitializer						{$$ = createstruct();($$)->type = ($2)->type;}	
        ;
OMCommaFormalParameter: CommaFormalParameter								{$$ = createstruct();($$)->type_variable = ($1)->type_variable;}
        |      OMCommaFormalParameter CommaFormalParameter 		{$$ = createstruct();vector<string>a=($1)->type_variable;vector<string>b=($2)->type_variable;for(auto z:a){($$)->type_variable.push_back(z);}for(auto z:b){($$)->type_variable.push_back(z);}}				
        ;
CommaFormalParameter:   COMMA FormalParameter								{$$ = createstruct();($$)->type_variable = ($2)->type_variable;}
        ;
OMCommaExceptionType:   CommaExceptionType									
        |     OMCommaExceptionType  CommaExceptionType 						
        ;
CommaExceptionType: COMMA ExceptionType										{$$ = createstruct();}	
        ;
OMCommaRecordComponent: CommaRecordComponent								
        |      OMCommaRecordComponent CommaRecordComponent 					
        ;
CommaRecordComponent:   COMMA RecordComponent								{$$ = createstruct();}	
        ;
OMRecordBodyDeclaration:       RecordBodyDeclaration 						
        |     OMRecordBodyDeclaration  RecordBodyDeclaration   				
        ;
OMInterfaceMemberDeclaration: InterfaceMemberDeclaration					
    	|  OMInterfaceMemberDeclaration InterfaceMemberDeclaration 			
    	;
OMCommaVariableInitializer: CommaVariableInitializer						{$$ = createstruct();($$)->type =  ($1)->type;}
        |     OMCommaVariableInitializer  CommaVariableInitializer 			{$$ = createstruct();($$)->type =  ($2)->type;}
        ;
CommaVariableInitializer:       COMMA VariableInitializer					{$$ = createstruct();($$)->type =  ($2)->type;}	
        ;	
OMBlockStatement: BlockStatement 											
    	|  OMBlockStatement BlockStatement 									
    	;
OMSwitchRule: SwitchRule													
    	|  OMSwitchRule SwitchRule 											
    	;
OMSwitchBlockStatementGroup: SwitchBlockStatementGroup						
    | OMSwitchBlockStatementGroup  SwitchBlockStatementGroup 				
    ;
OMSwitchLabelColon: SwitchLabelColon										
    |  OMSwitchLabelColon SwitchLabelColon 									
    ;
SwitchLabelColon:   SwitchLabel COLON										
    ;
OMCommaCaseConstant: CommaCaseConstant 										
    |   OMCommaCaseConstant CommaCaseConstant 								
    ;
CommaCaseConstant:  COMMA CaseConstant									{$$ = createstruct();}		
    ;
OMCommaStatementExpression: CommaStatementExpression						
    | OMCommaStatementExpression  CommaStatementExpression 					
    ;
CommaStatementExpression:  COMMA StatementExpression				{$$ = createstruct();}			
    ;
OMCatchClause:	CatchClause													
    |  OMCatchClause CatchClause 											
    ;
OMOrClassType: OrClassType													
    |  OMOrClassType OrClassType 											
    ;
OrClassType:   BITOR Identifier												{$$ = createstruct();}	
    ;
OMSemicolonResource: SemicolonResource										
    | OMSemicolonResource  SemicolonResource 								
    ;
SemicolonResource:  Resource SEMICOLON										
    ;
OMCommaExpression:   CommaExpression										
        |  OMCommaExpression CommaExpression 								
        ;
CommaExpression:    COMMA Expression									{$$ = createstruct();}		
        ;
OMDimExpr:      DimExpr														
        |     OMDimExpr  DimExpr 											
        ;
Modifieropt:	PUBLIC									{$$ = createstruct();}						
		| PROTECTED												{$$ = createstruct();}				
		| PRIVATE														{$$ = createstruct();}		
		| ABSTRACT												{$$ = createstruct();}				
		| STATIC														{$$ = createstruct();}		
		| SEALED														{$$ = createstruct();}		
		| STRICTFP													{$$ = createstruct();}			
		| FINAL															{$$ = createstruct();}		
		;
Identifier:	 IDENTIFIERWK			{$$=$1;}										
		;
UnqualifiedMethodIdentifier:	 IDENTIFIERWK			{$$ = createstruct(); string p = $1;($$)->name = p;}		
		| EXPORTS											{$$ = createstruct();}	
		| OPENS												{$$ = createstruct();}	
		| REQUIRES											{$$ = createstruct();}	
		| USES												{$$ = createstruct();}	
		| MODULE											{$$ = createstruct();}	
		| PERMITS										{$$ = createstruct();}	
		| SEALED											{$$ = createstruct();}	
		| VAR												{$$ = createstruct();}	
		| NONSEALED											{$$ = createstruct();}	
		| PROVIDES											{$$ = createstruct();}	
		| TO												{$$ = createstruct();}	
		| WITH												{$$ = createstruct();}	
		| OPEN												{$$ = createstruct();}	
		| RECORD											{$$ = createstruct();}	
		| TRANSITIVE										{$$ = createstruct();}	
		;
Literal:	 INTEGERLITERAL									{($$) = createstruct();($$)->type = "int";}	
		| FLOATINGPOINTLITERAL								{($$) = createstruct();($$)->type = "float";}	
		| BOOLEANLITERAL									{($$) = createstruct();($$)->type = "boolean";}	
		| NULLLITERAL									{($$) = createstruct();($$)->type = "null";}	
		| CHARACTERLITERAL									{($$) = createstruct();($$)->type = "char";}	
		| STRING											{($$) = createstruct();($$)->type = "string";}	
		| TEXTBLOCKS										{($$) = createstruct();($$)->type = "textblock";}	
		;
ASSIGNMENTOPERATOR:	 NEWASSIGNMENTOPERATOR				
		| EQUAL												
		;
PrimitiveType:	 UnannPrimitiveType				{$$ = createstruct();($$)->type = ($1)->type;}							
		;
NumericType:	 IntegralType						{$$ = createstruct();($$)->type = ($1)->type;}		
		| FloatingPointType								{$$ = createstruct();($$)->type = ($1)->type;}	
		;
IntegralType:	 BYTE										{($$) = createstruct();($$)->type = "byte";}	
		| SHORT												{($$) = createstruct();($$)->type = "short";}		
		| INT												{($$) = createstruct();($$)->type = "int";}		
		| LONG												{($$) = createstruct();($$)->type = "long";}		
		| CHAR												{($$) = createstruct();($$)->type = "char";}		
		;
FloatingPointType:	 FLOAT									{($$) = createstruct();($$)->type = "float";}
		| DOUBLE										{($$) = createstruct();($$)->type = "double";}
		;
ReferenceType:	 Identifier									{$$ = createstruct();}
		| UnannArrayType									
		;
TypeParameter:	 Identifier									{$$ = createstruct();}
		| Identifier TypeBound								{$$ = createstruct();}	
		;
TypeBound:	 EXTENDS Identifier								{$$ = createstruct();}
		| EXTENDS Identifier OMAdditionalBound				{$$ = createstruct();}
		;
AdditionalBound:	 BITAND Identifier						{$$ = createstruct();}
		;
ModuleName:	 Identifier										{$$ = createstruct();string p=($1);($$)->type=p;}
		| ModuleName DOT Identifier							{$$ = createstruct();string p=($3);($$)->type=($1)->type+"."+p;}
		;
ExpressionName:	 Identifier DOT Identifier			{$$ = createstruct();string q=($1);string p=($3);($$)->type=q+"."+p;}		
		| ExpressionName DOT Identifier						{$$ = createstruct();string p=($3);($$)->type=($1)->type+"."+p;}
		;
MethodName:	 UnqualifiedMethodIdentifier					{$$ = createstruct(); ;($$)->name = ($1)->name;}
		;
CompilationUnit:	 OrdinaryCompilationUnit				
		| ModularCompilationUnit							
		;
OrdinaryCompilationUnit:																{}
		| OMTopLevelClassOrInterfaceDeclaration											
		| OMImportDeclaration															
		| OMImportDeclaration OMTopLevelClassOrInterfaceDeclaration						
		| PackageDeclaration															
		| PackageDeclaration OMTopLevelClassOrInterfaceDeclaration						
		| PackageDeclaration OMImportDeclaration										
		| PackageDeclaration OMImportDeclaration OMTopLevelClassOrInterfaceDeclaration	
		;
ModularCompilationUnit:	 ModuleDeclaration												
		| OMImportDeclaration ModuleDeclaration											
		;
PackageDeclaration:	 PACKAGE Identifier SEMICOLON				{$$ = createstruct();}						
		| PACKAGE Identifier OMDotIdentifier SEMICOLON				{$$ = createstruct();}											
		;
ImportDeclaration:	 SingleTypeImportDeclaration										
		| SingleStaticImportDeclaration																						
		| StaticImportOnDemandDeclaration											
		|	ImportOnDemandDeclaration													
		;
SingleTypeImportDeclaration:	 IMPORT Identifier SEMICOLON		{$$ = createstruct();}					
    	| IMPORT ExpressionName SEMICOLON											{$$ = createstruct();}	
		;
SingleStaticImportDeclaration:	IMPORT STATIC ExpressionName SEMICOLON		{$$ = createstruct();}			
		;
ImportOnDemandDeclaration:	 IMPORT Identifier DOT MULTIPLY SEMICOLON			{$$ = createstruct();}		
    | IMPORT ExpressionName DOT MULTIPLY SEMICOLON										{$$ = createstruct();}
		;
StaticImportOnDemandDeclaration:	 IMPORT STATIC Identifier DOT MULTIPLY SEMICOLON	{$$ = createstruct();}
    | IMPORT STATIC ExpressionName DOT MULTIPLY SEMICOLON								{$$ = createstruct();}
		;
TopLevelClassOrInterfaceDeclaration:	 ClassDeclaration							
		| InterfaceDeclaration														
		| SEMICOLON																		{$$ = createstruct();}
		;
ModuleDeclaration:	 MODULE Identifier LCB {symtable*a=createtable();string p=($2);insertclass(p,"module","",a,line);   changescope(a);  } RCB		{goparent();}									
		| MODULE Identifier LCB {symtable*a=createtable();string p=($2);insertclass(p,"module","",a,line);   changescope(a);  }   OMModuleDirective RCB			{goparent();}						
		| MODULE Identifier OMDotIdentifier LCB {symtable*a=createtable();string p=($2);insertclass(p+($3)->name,"module","",a,line);changescope(a);} RCB		{goparent();}								
		| MODULE Identifier OMDotIdentifier  LCB {symtable*a=createtable();string p=($2);insertclass(p+($3)->name,"module","",a,line);changescope(a);} OMModuleDirective RCB		{goparent();}			
		| OPEN MODULE Identifier   LCB {symtable*a=createtable();string p=($3);insertclass(p,"module","",a,line);   changescope(a);  } RCB												{goparent();}
		| OPEN MODULE Identifier  LCB {symtable*a=createtable();string p=($3);insertclass(p,"module","",a,line);}  OMModuleDirective RCB			{goparent();}					
		| OPEN MODULE Identifier OMDotIdentifier  LCB {symtable*a=createtable();string p=($3);insertclass(p+($4)->name,"module","",a,line);changescope(a);}  RCB					{goparent();}			
		| OPEN MODULE Identifier OMDotIdentifier  LCB {symtable*a=createtable();string p=($3);insertclass(p+($4)->name,"module","",a,line);changescope(a);} OMModuleDirective RCB	{goparent();}			 
		;
ModuleDirective:	 REQUIRES ModuleName SEMICOLON								{$$ = createstruct();}
		| REQUIRES OMRequiresModifier ModuleName SEMICOLON					{$$ = createstruct();}	
		| EXPORTS Identifier SEMICOLON											{$$ = createstruct();}
		| EXPORTS Identifier TO ModuleName SEMICOLON								{$$ = createstruct();}
		| EXPORTS Identifier TO ModuleName OMCommaModuleName SEMICOLON		{$$ = createstruct();}		
		| OPENS Identifier SEMICOLON												{$$ = createstruct();}
		| OPENS Identifier TO ModuleName SEMICOLON									{$$ = createstruct();}
		| OPENS Identifier TO ModuleName OMCommaModuleName SEMICOLON			{$$ = createstruct();}
		| USES Identifier SEMICOLON													{$$ = createstruct();}
		| PROVIDES Identifier WITH Identifier SEMICOLON							{$$ = createstruct();}
		| PROVIDES Identifier WITH Identifier OMCommaTypeName SEMICOLON			{$$ = createstruct();}	
		| EXPORTS ExpressionName SEMICOLON											{$$ = createstruct();}
		| EXPORTS ExpressionName TO ModuleName SEMICOLON							{$$ = createstruct();}
		| EXPORTS ExpressionName TO ModuleName OMCommaModuleName SEMICOLON		{$$ = createstruct();}
		| OPENS ExpressionName SEMICOLON											{$$ = createstruct();}
		| OPENS ExpressionName TO ModuleName SEMICOLON								{$$ = createstruct();}
		| OPENS ExpressionName TO ModuleName OMCommaModuleName SEMICOLON			{$$ = createstruct();}
		| USES ExpressionName SEMICOLON											{$$ = createstruct();}
		| PROVIDES ExpressionName WITH ExpressionName SEMICOLON						{$$ = createstruct();}
		| PROVIDES ExpressionName WITH ExpressionName OMCommaTypeName SEMICOLON		{$$ = createstruct();}
		| PROVIDES ExpressionName WITH Identifier SEMICOLON							{$$ = createstruct();}
		| PROVIDES Identifier WITH ExpressionName OMCommaTypeName SEMICOLON			{$$ = createstruct();}
		| PROVIDES Identifier WITH ExpressionName SEMICOLON							{$$ = createstruct();}
		| PROVIDES ExpressionName WITH Identifier OMCommaTypeName SEMICOLON			{$$ = createstruct();}
		;
ClassDeclaration:	 NormalClassDeclaration											
		| RecordDeclaration															
		;
NormalClassDeclaration:	 CLASS Identifier 						{symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);   changescope(a);  }   ClassBody	{goparent();}														
		| CLASS Identifier ClassPermits 						{symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();}												
		| CLASS Identifier ClassImplements  					{symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody	{goparent();}												
		| CLASS Identifier ClassImplements ClassPermits 		{ symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();}								
		| CLASS Identifier ClassExtends  						{ symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody			{goparent();}											
		| CLASS Identifier ClassExtends ClassPermits 			{ symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody	{goparent();}										
		| CLASS Identifier ClassExtends ClassImplements 		{ symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody	{goparent();}									
		| CLASS Identifier ClassExtends ClassImplements ClassPermits 	{ symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();}					
		| CLASS Identifier TypeParameters 								{ symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody					{goparent();}									
		| CLASS Identifier TypeParameters ClassPermits 					{symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);     changescope(a);  } ClassBody		{goparent();}								
		| CLASS Identifier TypeParameters ClassImplements 				{symtable*a=createscope("class");string p=($2); insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();}								
		| CLASS Identifier TypeParameters ClassImplements  ClassPermits { symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();}				
		| CLASS Identifier TypeParameters ClassExtends					{symtable*a=createscope("class");string p=($2); insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();}								
		| CLASS Identifier TypeParameters ClassExtends ClassPermits 	{symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);     changescope(a);  } ClassBody		{goparent();}					
		| CLASS Identifier TypeParameters ClassExtends ClassImplements 	{ symtable*a=createscope("class");string p=($2);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody	{goparent();}					
		| CLASS Identifier TypeParameters ClassExtends ClassImplements ClassPermits {symtable*a=createscope("class");string p=($2); insertclass(p,"class","",a,line);    changescope(a);  } ClassBody	{goparent();}		
		| OMClassModifier CLASS Identifier 											{ symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody						{goparent();}							
		| OMClassModifier CLASS Identifier ClassPermits 							{ symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody			{goparent();}							
		| OMClassModifier CLASS Identifier ClassImplements 							{symtable*a=createscope("class");string p=($3); insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();}							
		| OMClassModifier CLASS Identifier ClassImplements ClassPermits 			{ symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  }  ClassBody		{goparent();}				
		| OMClassModifier CLASS Identifier ClassExtends 							{ symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody			{goparent();}							
		| OMClassModifier CLASS Identifier ClassExtends ClassPermits 				{ symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();}					
		| OMClassModifier CLASS Identifier ClassExtends ClassImplements  			{ symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();}				
		| OMClassModifier CLASS Identifier ClassExtends ClassImplements ClassPermits{ symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  }  ClassBody		{goparent();}	
		| OMClassModifier CLASS Identifier TypeParameters  							{symtable*a=createscope("class");string p=($3); insertclass(p,"class","",a,line);    changescope(a);  } ClassBody					{goparent();}					
		| OMClassModifier CLASS Identifier TypeParameters ClassPermits  			{symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody			{goparent();}			
		| OMClassModifier CLASS Identifier TypeParameters ClassImplements  			{symtable*a=createscope("class");string p=($3); insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();}				
		| OMClassModifier CLASS Identifier TypeParameters ClassImplements ClassPermits 		{ symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  }  ClassBody	{goparent();}	
		| OMClassModifier CLASS Identifier TypeParameters ClassExtends 						{symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);     changescope(a);  }  ClassBody					{goparent();}	
		| OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassPermits  		{ symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody		{goparent();}	
		| OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassImplements  	{ symtable*a=createtable();string p=($3);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody	{goparent();}	
		| OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassImplements ClassPermits  { symtable*a=createscope("class");string p=($3);insertclass(p,"class","",a,line);    changescope(a);  } ClassBody	{goparent();}
		;
TypeParameters:	 LT TypeParameterList GT							{$$ = createstruct();}	
		;
TypeParameterList: TypeParameter										
		| TypeParameter OMCommaTypeParameter							
		;
ClassExtends:	EXTENDS Identifier											{$$ = createstruct();}
		;	
ClassImplements: IMPLEMENTS InterfaceTypeList							{$$ = createstruct();}			
		;
InterfaceTypeList:   Identifier											{$$ = createstruct();}
		|	 Identifier OMCommaInterfaceType							{$$ = createstruct();}
		;

ClassPermits:   PERMITS Identifier										{$$ = createstruct();}
		|	 PERMITS ExpressionName										{$$ = createstruct();}
		|	 PERMITS Identifier OMCommaTypeName							{$$ = createstruct();}
		|	 PERMITS ExpressionName OMCommaTypeName						{$$ = createstruct();}
		;
ClassBody:	 LCB RCB													{$$ = createstruct();}
		| LCB OMClassBodyDeclaration RCB							{$$ = createstruct();}	
		;
ClassBodyDeclaration:	 ClassMemberDeclaration							
		| InstanceInitializer											
		| StaticInitializer												
		| ConstructorDeclaration										
		;
ClassMemberDeclaration:	 FieldDeclaration								
		| MethodDeclaration												
		| ClassDeclaration												
		| InterfaceDeclaration											
		| SEMICOLON														{$$ = createstruct();}
		;
FieldDeclaration:	 UnannType VariableDeclaratorList SEMICOLON     	{$$ = createstruct();($$)->variables=($2)->variables;($$)->type=($1)->type+($2)->type;for(auto z:($$)->variables)insertidentifier(z,($$)->type,"",line);}
		| OMClassModifier UnannType VariableDeclaratorList SEMICOLON	{$$ = createstruct();($$)->variables=($3)->variables;($$)->type=($2)->type+($3)->type;for(auto z:($$)->variables)insertidentifier(z,($$)->type,"",line);}
		;
VariableDeclaratorList:	 VariableDeclarator								{$$ = createstruct();($$)->variables = ($1)->variables;($$)->type = ($1)->type;}
		| VariableDeclarator COMMA VariableDeclaratorList				{$$ = createstruct();($$)->type = ($1)->type;vector<string>a=($1)->variables;vector<string>b=($3)->variables;for(auto z:a){($$)->variables.push_back(z);}for(auto z:b){($$)->variables.push_back(z);}}
		;
VariableDeclarator:	 VariableDeclaratorId								{$$ = createstruct();($$)->variables = ($1)->variables;($$)->type = ($1)->type;}
		| VariableDeclaratorId EqualVariableInitializer					{$$ = createstruct();($$)->variables = ($1)->variables; ($$)->type = ($1)->type;}		
		;
VariableDeclaratorId:  Identifier										{$$ = createstruct();string p=($1);($$)->variables.push_back(p);}						
		|	 Identifier OMPSB											{$$ = createstruct();($$)->type = ($2)->type;}
		;

VariableInitializer:	 Expression								{$$ = createstruct();($$)->type = ($1)->type;}	
		| ArrayInitializer												{$$ = createstruct();($$)->type = ($1)->type;}
		;
UnannType:	 UnannPrimitiveType										{$$ = createstruct();($$)->type = ($1)->type;}					
		| Identifier												{$$ = createstruct();string p = $1;($$)->type = p;}
		| UnannArrayType											{$$ = createstruct();($$)->type = ($1)->type;}
		;
UnannPrimitiveType:	 NumericType				{$$ = createstruct();($$)->type = ($1)->type;}						
		| BOOLEAN														{$$ = createstruct();($$)->type = "boolean";}
		;
UnannArrayType:    UnannPrimitiveType OMPSB							{$$ = createstruct();($$)->type = ($1)->type + ($2)->type;;}	
		|	 Identifier OMPSB											{$$ = createstruct();string p = $1;($$)->type = p + ($2)->type;}
		;
MethodDeclaration:	 MethodHeader MethodBody		{goparent();insertmethod(($1)->variables[0],"Method",($1)->type,($1)->type_variable,($1)->scope,"",($1)->linep);}				
		| OMClassModifier MethodHeader MethodBody			{goparent();insertmethod(($2)->variables[0],"Method",($2)->type,($2)->type_variable,($1)->scope,"",($2)->linep);}			
		;
MethodHeader:	 Result MethodDeclarator				{$$ = createstruct();($$)->type = ($1)->type;($$)->variables = ($1)->variables;($$)->type_variable = ($2)->type_variable;($$)->scope =($1)->scope;($$)->linep = ($2)->linep;}				
		| Result MethodDeclarator Throws							
		| TypeParameters Result MethodDeclarator		{$$ = createstruct();($$)->type = ($2)->type;($$)->variables = ($2)->variables;($$)->type_variable = ($3)->type_variable;($$)->scope =($2)->scope;($$)->linep = ($3)->linep;}			
		| TypeParameters Result MethodDeclarator Throws				
		;
Result:    UnannType	Identifier							{$$ = createstruct();symtable*a = createscope("Method");($$)->scope = a; ($$)->type = ($1)->type;string p = $2;($$)->variables.push_back(p); changescope(a);}						
		|	 VOID Identifier								{$$ = createstruct();symtable*a = createscope("Method");($$)->scope = a;($$)->type = "void";string p = $2;($$)->variables.push_back(p); changescope(a);}			
		;

MethodDeclarator: LRB RRB							{$$ = createstruct();($$)->type_variable.push_back("void");($$)->linep = line;}				
		| LRB RRB OMPSB													{$$ = createstruct();}
		| LRB FormalParameterList RRB				{$$ = createstruct();($$)->type_variable = ($2)->type_variable;($$)->linep = line;}					
		| LRB FormalParameterList RRB OMPSB						{$$ = createstruct();}		
		| LRB ReceiverParameterComma RRB						{$$ = createstruct();}
		| LRB ReceiverParameterComma RRB OMPSB				{$$ = createstruct();}		
		| LRB ReceiverParameterComma FormalParameterList RRB			{$$ = createstruct();($$)->type_variable = ($3)->type_variable;($$)->linep = line;}
		| LRB ReceiverParameterComma FormalParameterList RRB OMPSB	{$$ = createstruct();}
		;
ReceiverParameter:	 UnannType THIS									
		| UnannType IdentifierDot THIS								
		;
FormalParameterList: FormalParameter								{$$ = createstruct();($$)->type_variable = ($1)->type_variable;}
		| FormalParameter OMCommaFormalParameter					{$$ = createstruct();vector<string>a=($1)->type_variable;vector<string>b=($2)->type_variable;for(auto z:a){($$)->type_variable.push_back(z);}for(auto z:b){($$)->type_variable.push_back(z);}}	
		;
FormalParameter: UnannType VariableDeclaratorId							{$$ = createstruct();($$)->type_variable.push_back(($1)->type+($2)->type);($$)->type=($1)->type+($2)->type;for(auto z:($2)->variables)insertidentifier(z,($$)->type,"",line);}
		| OMClassModifier UnannType VariableDeclaratorId				{$$ = createstruct();($$)->type_variable.push_back(($2)->type+($3)->type);($$)->type=($2)->type+($3)->type;for(auto z:($3)->variables)insertidentifier(z,($$)->type,"",line);}	
		| VariableArityParameter										{$$ = createstruct();($$)->type_variable = ($1)->type_variable;}
		;
VariableArityParameter:   UnannType THREEDOT Identifier				{$$ = createstruct();($$)->type_variable.push_back(($1)->type);}
		|	 OMClassModifier UnannType THREEDOT Identifier			{$$ = createstruct();($$)->type_variable.push_back(($2)->type);}
		;
Throws:	 THROWS ExceptionTypeList									{$$ = createstruct();}
		;
ExceptionTypeList:	 ExceptionType									
		| ExceptionType OMCommaExceptionType			
		;
ExceptionType:   Identifier										{$$ = createstruct();}
		;

MethodBody:	 Block														
		| SEMICOLON													{$$ = createstruct();}
		;	
InstanceInitializer:	 Block											
		;
StaticInitializer:	 STATIC Block									{$$ = createstruct();}	
		;	
ConstructorDeclaration:	 ConstructorDeclarator ConstructorBody			{goparent();insertmethod(($1)->variables[0],"constructor",($1)->type,($1)->type_variable,($1)->scope,"",($1)->linep);}
		| ConstructorDeclarator Throws ConstructorBody				{goparent();insertmethod(($1)->variables[0],"constructor",($1)->type,($1)->type_variable,($1)->scope,"",($1)->linep);}
		| OMClassModifier ConstructorDeclarator ConstructorBody			{goparent();insertmethod(($2)->variables[0],"constructor",($2)->type,($2)->type_variable,($2)->scope,"",($2)->linep);}
		| OMClassModifier ConstructorDeclarator Throws ConstructorBody	{goparent();insertmethod(($2)->variables[0],"constructor",($2)->type,($2)->type_variable,($2)->scope,"",($2)->linep);}
		;
ConstructorDeclaratorLRBSym: LRB {$$ = createstruct();symtable*a = createscope("constructor");($$)->scope = a; changescope(a);}
		;
ConstructorDeclarator:   Identifier ConstructorDeclaratorLRBSym RRB							{$$ = createstruct();($$)->scope = ($2)->scope; ($$)->type_variable.push_back("void");string p = $1;($$)->variables.push_back(p);($$)->type = "void";($$)->linep = line;}						
		|	 Identifier ConstructorDeclaratorLRBSym FormalParameterList RRB								{$$ = createstruct();($$)->scope = ($2)->scope;($$)->type_variable = ($3)->type_variable;string p = $1;($$)->variables.push_back(p);($$)->type = "void";($$)->linep = line;}				
		|	 Identifier LRB ReceiverParameterComma RRB										{$$ = createstruct();}
		|	 Identifier LRB ReceiverParameterComma FormalParameterList RRB					{$$ = createstruct();}
		|	 TypeParameters Identifier ConstructorDeclaratorLRBSym RRB								{$$ = createstruct();($$)->scope = ($3)->scope;($$)->type_variable.push_back("void");string p = $2; ($$)->variables.push_back(p);($$)->type = "void";($$)->linep = line;}				
		|	 TypeParameters Identifier ConstructorDeclaratorLRBSym FormalParameterList RRB			{$$ = createstruct();($$)->scope = ($3)->scope;($$)->type_variable = ($4)->type_variable;string p = $2;($$)->variables.push_back(p);($$)->type = "void";($$)->linep = line;}					
		|	 TypeParameters Identifier LRB ReceiverParameterComma RRB						
		|	 TypeParameters Identifier LRB ReceiverParameterComma FormalParameterList RRB		
		;

ConstructorBody: LCB RCB												{$$ = createstruct();}
		| LCB BlockStatements RCB									{$$ = createstruct();}
		| LCB ExplicitConstructorInvocation RCB						{$$ = createstruct();}
		| LCB ExplicitConstructorInvocation BlockStatements RCB			{$$ = createstruct();}
		;
ExplicitConstructorInvocation:	 THIS LRB RRB SEMICOLON							{$$ = createstruct();}	
		| THIS LRB ArgumentList RRB SEMICOLON									{$$ = createstruct();}
		| SUPER LRB RRB SEMICOLON													{$$ = createstruct();}
		| SUPER LRB ArgumentList RRB SEMICOLON									{$$ = createstruct();}
		| Identifier DOT SUPER LRB RRB SEMICOLON									{$$ = createstruct();}
		| Identifier DOT SUPER LRB ArgumentList RRB SEMICOLON					{$$ = createstruct();}	
		| ExpressionName DOT SUPER LRB RRB SEMICOLON								{$$ = createstruct();}
		| ExpressionName DOT SUPER LRB ArgumentList RRB SEMICOLON					{$$ = createstruct();}
		| Primary DOT SUPER LRB RRB SEMICOLON										{$$ = createstruct();}
		| Primary DOT SUPER LRB ArgumentList RRB SEMICOLON							{$$ = createstruct();}
		;

RecordDeclarationSym: RECORD Identifier {$$ = createstruct();symtable*a=createscope("record");($$)->scope = a; ($$)->type = "record";string p = $2;($$)->variables.push_back(p); changescope(a);}
		;
RecordDeclaration:    RecordDeclarationSym RecordHeader RecordBody					{goparent();insertmethod(($1)->variables[0],"record",($1)->type,($2)->type_variable,($1)->scope,"",($2)->linep);}										
		|	 RecordDeclarationSym RecordHeader ClassImplements RecordBody					{goparent();insertmethod(($1)->variables[0],"record",($1)->type,($2)->type_variable,($1)->scope,"",($2)->linep);}						
		|	 RecordDeclarationSym TypeParameters RecordHeader RecordBody									{goparent();insertmethod(($1)->variables[0],"record",($1)->type,($3)->type_variable,($1)->scope,"",($3)->linep);}		
		|	 RecordDeclarationSym TypeParameters RecordHeader ClassImplements RecordBody			{goparent();insertmethod(($1)->variables[0],"record",($1)->type,($3)->type_variable,($1)->scope,"",($3)->linep);}				
		|	 OMClassModifier RecordDeclarationSym RecordHeader RecordBody									{goparent();insertmethod(($2)->variables[0],"record",($2)->type,($3)->type_variable,($2)->scope,"",($3)->linep);}		
		|	 OMClassModifier RecordDeclarationSym RecordHeader ClassImplements RecordBody		{goparent();insertmethod(($2)->variables[0],"record",($2)->type,($3)->type_variable,($2)->scope,"",($3)->linep);}					
		|	 OMClassModifier RecordDeclarationSym TypeParameters RecordHeader RecordBody		{goparent();insertmethod(($2)->variables[0],"record",($2)->type,($4)->type_variable,($2)->scope,"",($4)->linep);}					
		|	 OMClassModifier RecordDeclarationSym TypeParameters RecordHeader ClassImplements RecordBody	{goparent();insertmethod(($2)->variables[0],"record",($2)->type,($4)->type_variable,($2)->scope,"",($4)->linep);}		
		;

RecordHeader:	 LRB RRB										{$$ = createstruct();($$)->type_variable.push_back("void");($$)->linep = line;}			
		| LRB RecordComponentList RRB					{$$ = createstruct();($$)->type_variable = ($2)->type_variable;($$)->linep = line;}								
		;
RecordComponentList:  RecordComponent							{$$ = createstruct();($$)->type_variable = ($1)->type_variable;}			
		| RecordComponent OMCommaRecordComponent			{$$ = createstruct();vector<string>a=($1)->type_variable;vector<string>b=($2)->type_variable;for(auto z:a){($$)->type_variable.push_back(z);}for(auto z:b){($$)->type_variable.push_back(z);}}					
		;
RecordComponent:    UnannType Identifier					{$$ = createstruct();($$)->type_variable.push_back(($1)->type);}				
		|	 VariableArityRecordComponent								{$$ = createstruct();($$)->type_variable = ($1)->type_variable;}	
		;

VariableArityRecordComponent:    UnannType THREEDOT Identifier					{$$ = createstruct();($$)->type_variable.push_back(($1)->type);}	
		;
RecordBody:	 LCB RCB													{$$ = createstruct();}
		| LCB OMRecordBodyDeclaration RCB						{$$ = createstruct();}		
		;
RecordBodyDeclaration:	 ClassBodyDeclaration							
		| CompactConstructorDeclaration									
		;
CompactConstructorDeclarationSym: Identifier {vector<string>tec; symtable*a=createscope("compactconstructor");string p=($1);insertmethod(p,"compactconstructor","auto",tec,a,"",line);changescope(a);}
		;
CompactConstructorDeclaration:	CompactConstructorDeclarationSym	ConstructorBody			{goparent();}
		|	 OMClassModifier CompactConstructorDeclarationSym ConstructorBody					{goparent();}
		;

InterfaceDeclaration:	 NormalInterfaceDeclaration						
		;
NormalInterfaceDeclaration:   INTERFACE Identifier    {symtable*a=createscope("interface");string p=($2);insertclass(p,"interface","",a,line);changescope(a);}  InterfaceBody		{goparent();}												
		|	 INTERFACE Identifier InterfacePermits    {symtable*a=createscope("interface");string p=($2);insertclass(p,"interface","",a,line);changescope(a);}    InterfaceBody		{goparent();}								
		|	 INTERFACE Identifier InterfaceExtends   {symtable*a=createscope("interface");string p=($2);insertclass(p,"interface","",a,line);changescope(a);}    InterfaceBody		{goparent();}							
		|	 INTERFACE Identifier InterfaceExtends InterfacePermits  {symtable*a=createscope("interface");string p=($2);insertclass(p,"interface","",a,line);changescope(a);}    InterfaceBody		{goparent();}									
		|	 INTERFACE Identifier TypeParameters    {symtable*a=createscope("interface");string p=($2);insertclass(p,"interface","",a,line);changescope(a);}   InterfaceBody					{goparent();}									
		|	 INTERFACE Identifier TypeParameters InterfacePermits   {symtable*a=createscope("interface");string p=($2);insertclass(p,"interface","",a,line);changescope(a);}    InterfaceBody		{goparent();}										
		|	 INTERFACE Identifier TypeParameters InterfaceExtends    {symtable*a=createscope("interface");string p=($2);insertclass(p,"interface","",a,line);changescope(a);}  InterfaceBody			{goparent();}								
		|	 INTERFACE Identifier TypeParameters InterfaceExtends InterfacePermits    {symtable*a=createscope("interface");string p=($2);insertclass(p,"interface","",a,line);changescope(a);}   InterfaceBody			{goparent();}			
		|	 OMClassModifier INTERFACE Identifier   {symtable*a=createscope("interface");string p=($3);insertclass(p,"interface","",a,line);changescope(a);}  InterfaceBody								{goparent();}						
		|	 OMClassModifier INTERFACE Identifier InterfacePermits    {symtable*a=createscope("interface");string p=($3);insertclass(p,"interface","",a,line);changescope(a);}    InterfaceBody				{goparent();}						
		|	 OMClassModifier INTERFACE Identifier InterfaceExtends   {symtable*a=createscope("interface");string p=($3);insertclass(p,"interface","",a,line);changescope(a);}   InterfaceBody				{goparent();}						
		|	 OMClassModifier INTERFACE Identifier InterfaceExtends InterfacePermits    {symtable*a=createscope("interface");string p=($3);insertclass(p,"interface","",a,line);changescope(a);}   InterfaceBody	{goparent();}						
		|	 OMClassModifier INTERFACE Identifier TypeParameters   {symtable*a=createscope("interface");string p=($3);insertclass(p,"interface","",a,line);changescope(a);}  InterfaceBody			{goparent();}									
		|	 OMClassModifier INTERFACE Identifier TypeParameters InterfacePermits    {symtable*a=createscope("interface");string p=($3);insertclass(p,"interface","",a,line);changescope(a);}   InterfaceBody		{goparent();}	
		|	 OMClassModifier INTERFACE Identifier TypeParameters InterfaceExtends    {symtable*a=createscope("interface");string p=($3);insertclass(p,"interface","",a,line);changescope(a);}   InterfaceBody		{goparent();}					
		|	 OMClassModifier INTERFACE Identifier TypeParameters InterfaceExtends InterfacePermits   {symtable*a=createscope("interface");string p=($3);insertclass(p,"interface","",a,line);changescope(a);}   InterfaceBody		{goparent();}	
		;

InterfaceModifier:	 Modifieropt										
		;
InterfaceExtends:	 EXTENDS InterfaceTypeList					{$$ = createstruct();}		
		;
InterfacePermits:	 PERMITS ExpressionName							{$$ = createstruct();}	
		| PERMITS ExpressionName OMCommaTypeName					{$$ = createstruct();}	
		;
InterfaceBody:	 LCB RCB												{$$ = createstruct();}
		| LCB OMInterfaceMemberDeclaration RCB						{$$ = createstruct();}	
		;
InterfaceMemberDeclaration:	 ConstantDeclaration						
		| InterfaceMethodDeclaration									
		| ClassDeclaration												
		| InterfaceDeclaration										
		| SEMICOLON														{$$ = createstruct();}
		;
ConstantDeclaration:	 UnannType VariableDeclaratorList SEMICOLON		{vector<string>a=($2)->variables;($$)->type=($1)->type+($2)->type;for(auto z:a){insertidentifier(z,($1)->type,"",line);}}
		| OMClassModifier UnannType VariableDeclaratorList SEMICOLON	{vector<string>a=($3)->variables;($$)->type=($2)->type+($3)->type;for(auto z:a){insertidentifier(z,($2)->type,"",line);}}
		;
InterfaceMethodDeclaration:	 MethodHeader MethodBody				
		| OMClassModifier MethodHeader MethodBody						
		;
ArrayInitializer:	 LCB RCB												{$$ = createstruct();($$)->type = "[]";}
		| LCB COMMA RCB														{$$ = createstruct();($$)->type = "[]";}
		| LCB VariableInitializerList RCB								{$$ = createstruct();($$)->type =  ($2)->type + "[]";}	
		;
VariableInitializerList:	 VariableInitializer						{$$ = createstruct();($$)->type =  ($1)->type ;}	
		| VariableInitializer OMCommaVariableInitializer			{$$ = createstruct();($$)->type =  ($1)->type;}		
		;
Block:	 LCB RCB										{$$ = createstruct();}					
		| LCB BlockStatements RCB 		{$$ = createstruct();}								
		;
BlockStatements:	 BlockStatement											
		| BlockStatement OMBlockStatement									
		;
BlockStatement:	 LocalClassOrInterfaceDeclaration							
		| LocalVariableDeclarationStatement									
		| Statement															
		;
LocalClassOrInterfaceDeclaration:	 ClassDeclaration						
		| NormalInterfaceDeclaration										
		;
LocalVariableDeclarationStatement:	 LocalVariableDeclaration SEMICOLON		{
	vector<string>a=($1)->variables;
	for(auto z:a){
		insertidentifier(z,($1)->type,"",line);
	}
}
		;
LocalVariableDeclaration:	 LocalVariableType VariableDeclaratorList		{$$ = createstruct();($$)->variables=($2)->variables;($$)->type=($1)->type+($2)->type;}
		| OMClassModifier LocalVariableType VariableDeclaratorList			{$$ = createstruct();($$)->variables=($3)->variables;($$)->type=($2)->type+($3)->type;}
		;
LocalVariableType:	 UnannType						{$$ = createstruct();($$)->type=($1)->type;}								
		| VAR										{$$ = createstruct();($$)->type="all";}							
		;
Statement:	 StatementWithoutTrailingSubstatement							
		| LabeledStatement													
		| IfThenStatement													
		| IfThenElseStatement												
		| WhileStatement													
		| ForStatement														
		;
StatementNoShortIf:	 StatementWithoutTrailingSubstatement					
		| LabeledStatementNoShortIf											
		| IfThenElseStatementNoShortIf										
		| WhileStatementNoShortIf											
		| ForStatementNoShortIf												
		;
StatementWithoutTrailingSubstatement:	{symtable *a = createscope("statement");insertclass("statement","statement","",a,line); changescope(a);flag = 0;} Block		{goparent();}					
		| EmptyStatement													
		| ExpressionStatement												
		| AssertStatement													
		| SwitchStatement													
		| DoStatement														
		| BreakStatement													
		| ContinueStatement													
		| ReturnStatement													
		| SynchronizedStatement												
		| ThrowStatement													
		| TryStatement														
		| YieldStatement													
		;
EmptyStatement:	 SEMICOLON											{$$ = createstruct();}		
		;
LabeledStatement:   Identifier COLON Statement				{$$ = createstruct();}				
		;
LabeledStatementNoShortIf:   Identifier COLON StatementNoShortIf		{$$ = createstruct();}
		;

ExpressionStatement:  StatementExpression SEMICOLON						
		;
StatementExpression:	 Assignment										
		| PreIncrementExpression											
		| PreDecrementExpression											
		| PostIncrementExpression											
		| PostDecrementExpression											
		| MethodInvocation													
		| ClassInstanceCreationExpression								
		;
IfThenStatement: IF LRB Expression RRB Statement		{}
		;
IfThenElseStatement: IF LRB Expression RRB StatementNoShortIf  ELSE Statement {}
		;
IfThenElseStatementNoShortIf:	 IF LRB Expression RRB StatementNoShortIf  ELSE StatementNoShortIf	{}
		;
AssertStatement:	 ASSERT Expression SEMICOLON							{$$ = createstruct();}	 
		| ASSERT Expression COLON Expression SEMICOLON					{$$ = createstruct();}			
		;
SwitchStatement:	 SWITCH LRB Expression RRB {symtable *a = createscope("switch"); changescope(a);} SwitchBlock		{goparent();}					
		;
SwitchBlock:	 LCB SwitchRule RCB													{$$ = createstruct();}
		| LCB SwitchRule OMSwitchRule RCB											{$$ = createstruct();}
		| LCB RCB																							{$$ = createstruct();}			
		| LCB OMSwitchLabelColon RCB												{$$ = createstruct();}
		| LCB OMSwitchBlockStatementGroup RCB										{$$ = createstruct();}
		| LCB OMSwitchBlockStatementGroup OMSwitchLabelColon RCB			{$$ = createstruct();}		
		;
SwitchRule:	 SwitchLabel IMPLIES Expression SEMICOLON								
		| SwitchLabel IMPLIES Block													
		| SwitchLabel IMPLIES ThrowStatement										
		;
SwitchBlockStatementGroup:	 SwitchLabel COLON BlockStatements						
		| SwitchLabel COLON OMSwitchLabelColon BlockStatements						
		;
SwitchLabel:	 CASE CaseConstant												{$$ = createstruct();}	
		| CASE CaseConstant OMCommaCaseConstant							{$$ = createstruct();}			
		| DEFAULT																	{$$ = createstruct();}
		;
CaseConstant:	 ConditionalExpression												
		;		
WhileStatement:	 WHILE LRB Expression RRB Statement						{$$ = createstruct();}					
		;
WhileStatementNoShortIf:	 WHILE LRB Expression RRB StatementNoShortIf		{$$ = createstruct();}	
		;
DoStatement:	 DO  Statement WHILE LRB Expression RRB SEMICOLON					{$$ = createstruct();}
		;
ForStatement:	 BasicForStatement													
		| EnhancedForStatement														
		;
ForStatementNoShortIf:	 BasicForStatementNoShortIf									
		| EnhancedForStatementNoShortIf												
		;
ForSym:	FOR	{symtable*a=createscope("for");insertclass("for","for","",a,line); changescope(a);}
		;
BasicForStatement:	 ForSym LRB SEMICOLON SEMICOLON RRB Statement		{goparent();}				
		| ForSym LRB SEMICOLON SEMICOLON ForUpdate RRB Statement						{goparent();}		
		| ForSym LRB SEMICOLON Expression SEMICOLON RRB Statement						{goparent();}		
		| ForSym LRB SEMICOLON Expression SEMICOLON ForUpdate RRB Statement		{goparent();}			
		| ForSym LRB ForInit SEMICOLON SEMICOLON RRB Statement							{goparent();}		
		| ForSym LRB ForInit SEMICOLON SEMICOLON ForUpdate RRB Statement				{goparent();}		
		| ForSym LRB ForInit SEMICOLON Expression SEMICOLON RRB Statement				{goparent();}		
		| ForSym LRB ForInit SEMICOLON Expression SEMICOLON ForUpdate RRB Statement	{goparent();}		
		;
BasicForStatementNoShortIf:	 ForSym LRB SEMICOLON SEMICOLON RRB StatementNoShortIf	{goparent();}				
		| ForSym LRB SEMICOLON SEMICOLON ForUpdate RRB StatementNoShortIf						{goparent();}		
		| ForSym LRB SEMICOLON Expression SEMICOLON RRB StatementNoShortIf						{goparent();}		
		| ForSym LRB SEMICOLON Expression SEMICOLON ForUpdate RRB StatementNoShortIf			{goparent();}		
		| ForSym LRB ForInit SEMICOLON SEMICOLON RRB StatementNoShortIf						{goparent();}		
		| ForSym LRB ForInit SEMICOLON SEMICOLON ForUpdate RRB StatementNoShortIf				{goparent();}		
		| ForSym LRB ForInit SEMICOLON Expression SEMICOLON RRB StatementNoShortIf				{goparent();}			
		| ForSym LRB ForInit SEMICOLON Expression SEMICOLON ForUpdate RRB StatementNoShortIf	{goparent();}		
		;
ForInit:	 StatementExpressionList													
		| LocalVariableDeclaration				{vector<string> a = ($1)->variables; for(auto s : a)insertidentifier(s,($1)->type,"",line);}										
		;	
ForUpdate:	 StatementExpressionList													
		;
StatementExpressionList:	 StatementExpression										
		| StatementExpression OMCommaStatementExpression								
		;
EnhancedForStatementSym: ForSym LRB LocalVariableDeclaration {vector<string> a = ($3)->variables; for(auto s : a)insertidentifier(s,($3)->type,"",line);}
		;
EnhancedForStatement:	 EnhancedForStatementSym COLON Expression RRB Statement			{goparent();}					
		;
EnhancedForStatementNoShortIf:	 EnhancedForStatementSym COLON Expression RRB StatementNoShortIf	{goparent();}		
		;
BreakStatement:   		 BREAK SEMICOLON								{$$ = createstruct();}										
		|	 BREAK Identifier SEMICOLON											{$$ = createstruct();}								
		;

YieldStatement:	 YIELD Expression SEMICOLON								{$$ = createstruct();}												
		;
ContinueStatement:   CONTINUE SEMICOLON										{$$ = createstruct();}									
		|	 CONTINUE Identifier SEMICOLON											{$$ = createstruct();}							
		;

ReturnStatement:	 RETURN SEMICOLON												{$$ = createstruct();}	
		| RETURN Expression SEMICOLON												{$$ = createstruct();}
		;	
ThrowStatement:	 THROW Expression SEMICOLON									{$$ = createstruct();}		
		;
SynchronizedStatement:	 SYNCHRONIZED LRB Expression RRB {symtable*a=createscope("synchronized"); changescope(a);} Block		{goparent();}					
		;
TrySym: TRY {symtable*a=createscope("try"); changescope(a);}
		;
TryBlockSym: Block	{goparent();}
		;
TryStatement:	TrySym TryBlockSym Catches													
		| TrySym TryBlockSym Finally																
		| TrySym TryBlockSym Catches Finally														
		| TryWithResourcesStatement													
		;
Catches:	 CatchClause															
		| CatchClause OMCatchClause														
		;
CatchClause:	 CATCH {symtable*a=createscope("catch"); changescope(a);} LRB CatchFormalParameter RRB  Block	{goparent();}								
		;
CatchFormalParameter:	 CatchType VariableDeclaratorId									
		| OMClassModifier CatchType VariableDeclaratorId								
		;
CatchType:   		 Identifier															{$$ = createstruct();}
		|	 Identifier OMOrClassType												{$$ = createstruct();}
		;

Finally:	 FINALLY {symtable*a=createscope("finally"); changescope(a);} Block	{goparent();}																
		;	
TryWithResourcesStatement:	 TrySym ResourceSpecification TryBlockSym						
		| TrySym ResourceSpecification TryBlockSym Finally										
		| TrySym ResourceSpecification TryBlockSym Catches										
		| TrySym ResourceSpecification TryBlockSym Catches Finally								
		;
ResourceSpecification:	 LRB ResourceList RRB						{$$ = createstruct();}					
		;
ResourceList:	 Resource																
		| OMSemicolonResource															
		;
Resource:	 LocalVariableDeclaration													
		| VariableAccess															
		;
Primary:	 PrimaryNoNewArray												{$$ = createstruct();($$)->type = ($1)->type;}			
		| ArrayCreationExpression														
		;
PrimaryNoNewArray:	 Literal													{$$ = createstruct();($$)->type = ($1)->type;}		
		| ClassLiteral																	{$$ = createstruct();($$)->type = ($1)->type;}
		| THIS																			{$$ = createstruct();($$)->type = "class";}
		| Identifier DOT THIS														{$$ = createstruct();($$)->type = "class";}
		| ExpressionName DOT THIS													{$$ = createstruct();($$)->type = "class";}	
		| LRB Expression RRB														{$$ = createstruct();($$)->type = ($2)->type;}
		| ClassInstanceCreationExpression									{$$ = createstruct();($$)->type = ($1)->type;}			
		| FieldAccess																{$$ = createstruct();($$)->type = "look";}	
		| ArrayAccess																{$$ = createstruct();($$)->type = ($1)->type;}	
		| MethodInvocation															{$$ = createstruct();($$)->type = ($1)->type;}		
		| MethodReference															{$$ = createstruct();($$)->type = "look";}	
		;
ClassLiteral:	 Identifier DOT CLASS												{$$ = createstruct();($$)->type = "class";}		
		| ExpressionName DOT CLASS															{$$ = createstruct();($$)->type = "class";}
		| Identifier OMPSB DOT CLASS														{$$ = createstruct();($$)->type = "class";}
		| ExpressionName OMPSB DOT CLASS												{$$ = createstruct();($$)->type = "class";}	
		| UnannPrimitiveType DOT CLASS												{$$ = createstruct();($$)->type = "class";}	
		| VOID DOT CLASS																	{$$ = createstruct();($$)->type = "class";}
		;
ClassInstanceCreationExpression:	 UnqualifiedClassInstanceCreationExpression			{$$ = createstruct();($$)->type = ($1)->type;}	
		| Identifier DOT UnqualifiedClassInstanceCreationExpression							{$$ = createstruct();($$)->type = ($3)->type;}
		| ExpressionName DOT UnqualifiedClassInstanceCreationExpression					{$$ = createstruct();($$)->type = ($3)->type;}	
		| Primary DOT UnqualifiedClassInstanceCreationExpression							{$$ = createstruct();($$)->type = ($3)->type;}
		;
UnqualifiedClassInstanceCreationExpression:	 NEW ClassOrInterfaceTypeToInstantiate LRB RRB 		{$$ = createstruct();($$)->type = ($2)->type;}
		| NEW ClassOrInterfaceTypeToInstantiate LRB RRB ClassBody								{$$ = createstruct();($$)->type = ($2)->type;}
		| NEW ClassOrInterfaceTypeToInstantiate LRB ArgumentList RRB						{$$ = createstruct();($$)->type = ($2)->type;}	
		| NEW ClassOrInterfaceTypeToInstantiate LRB ArgumentList RRB ClassBody		{$$ = createstruct();($$)->type = ($2)->type;}		
		;
ClassOrInterfaceTypeToInstantiate:   Identifier					{$$ = createstruct();string p = $1;if(lookup(p)){($$)->type =  lookup(p)->funcrettype ;}}					
		|	Identifier OMDotIdentifier													{$$ = createstruct();string p = $1;if(lookup(p + ($2)->name)){($$)->type =  lookup(p + ($2)->name)->funcrettype ;}}
		;
FieldAccess:   Primary DOT Identifier								
		|	 SUPER DOT Identifier									{$$ = createstruct();}
		|	 Identifier DOT SUPER DOT Identifier					{$$ = createstruct();}
		|	 ExpressionName DOT SUPER DOT Identifier				
		;
ArrayAccess:   Identifier LSB Expression RSB			{$$ = createstruct();string p = $1;if(lookup(p)){($$)->type =  lookup(p)->type ;}}
		|	 ExpressionName LSB Expression RSB				
		|	 PrimaryNoNewArray LSB Expression RSB			
		;
MethodInvocation:   MethodName LRB ArgumentList RRB							{$$ = createstruct();if(lookup(($1)->name)){($$)->type =  lookup(($1)->name)->funcrettype ;}}		
		|	 MethodName LRB RRB												{$$ = createstruct();if(lookup(($1)->name)){($$)->type =  lookup(($1)->name)->funcrettype ;}}	
		|	 Identifier DOT Identifier LRB RRB								{$$ = createstruct();}
		|	 Identifier DOT Identifier LRB ArgumentList RRB					{$$ = createstruct();}	
		|	 ExpressionName DOT Identifier LRB RRB										
		|	 ExpressionName DOT Identifier LRB ArgumentList RRB							
		|	 Primary DOT Identifier LRB RRB												
		|	 Primary DOT Identifier LRB ArgumentList RRB								
		|	 SUPER DOT Identifier LRB RRB												{$$ = createstruct();}
		|	 SUPER DOT Identifier LRB ArgumentList RRB							{$$ = createstruct();}		
		|	 Identifier DOT SUPER DOT Identifier LRB RRB								{$$ = createstruct();}
		|	 Identifier DOT SUPER DOT Identifier LRB ArgumentList RRB					{$$ = createstruct();}
		|	 ExpressionName DOT SUPER DOT Identifier LRB RRB							
		|	 ExpressionName DOT SUPER DOT Identifier LRB ArgumentList RRB				
		;

ArgumentList:	 Expression												
		| Expression OMCommaExpression									
		;
MethodReference:   Identifier DOUBLECOLON Identifier			{$$ = createstruct();}
		|	 ExpressionName DOUBLECOLON Identifier				
		|	 Primary DOUBLECOLON Identifier							
		|	 UnannArrayType DOUBLECOLON Identifier					
		|	 SUPER DOUBLECOLON Identifier							{$$ = createstruct();}
		|	 Identifier DOT SUPER DOUBLECOLON Identifier			{$$ = createstruct();}
		|	 ExpressionName DOT SUPER DOUBLECOLON Identifier					
		|	 UnannArrayType DOUBLECOLON NEW										
		;
ArrayCreationExpression:   NEW PrimitiveType OMDimExpr				{$$ = createstruct();}			
		|	 NEW PrimitiveType OMDimExpr OMPSB									{$$ = createstruct();}
		|	 NEW Identifier OMDimExpr											{$$ = createstruct();}
		|	 NEW Identifier OMDimExpr OMPSB										{$$ = createstruct();}
		|	 NEW PrimitiveType OMPSB ArrayInitializer							{$$ = createstruct();}
		|	 NEW Identifier OMPSB ArrayInitializer								{$$ = createstruct();}
		;

DimExpr:	 LSB Expression RSB								{$$ = createstruct();}
		;
Expression:	AssignmentExpression							{$$ = createstruct();($$)->type = ($1)->type;}
		;
AssignmentExpression:	 ConditionalExpression				{$$ = createstruct();($$)->type = ($1)->type;}
		| Assignment										{$$ = createstruct();($$)->type = ($1)->type;}
		;
Assignment:	 LeftHandSide AssignmentOperator Expression		{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = ($3)->type;}
		;
LeftHandSide:	 ExpressionName								
   		| Identifier										{$$ = createstruct();string p = $1;if(lookup(p)){($$)->type = lookup(p)->type;}}
		| FieldAccess										
		| ArrayAccess										{($$)->type = ($1)->type;}
		;
AssignmentOperator:	 ASSIGNMENTOPERATOR						
		;
ConditionalExpression:	 ConditionalOrExpression									{$$ = createstruct();($$)->type = ($1)->type;}
		| ConditionalOrExpression QM Expression COLON ConditionalExpression		{$$ = createstruct();type_check(($1)->type,"boolean",line);type_check(($3)->type,($5)->type,line);($$)->type = ($1)->type;}	
		;
ConditionalOrExpression:	 ConditionalAndExpression							{$$ = createstruct();($$)->type = ($1)->type;}				
		| ConditionalOrExpression OR ConditionalAndExpression 				{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = "boolean";}			
		;
ConditionalAndExpression:	 InclusiveOrExpression									{$$ = createstruct();($$)->type = ($1)->type;}
		| ConditionalAndExpression AND InclusiveOrExpression						{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = "boolean";}
		;
InclusiveOrExpression:	 ExclusiveOrExpression								{$$ = createstruct();($$)->type = ($1)->type;}	
		| InclusiveOrExpression BITOR ExclusiveOrExpression				{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = ($1)->type;}			
		;
ExclusiveOrExpression:	 AndExpression											{$$ = createstruct();($$)->type = ($1)->type;}
		| ExclusiveOrExpression BITXOR AndExpression							{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = ($1)->type;}	
		;
AndExpression:	 EqualityExpression													{$$ = createstruct();($$)->type = ($1)->type;}
		| AndExpression BITAND EqualityExpression									{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = ($1)->type;}
		;
EqualityExpression:	 RelationalExpression										{$$ = createstruct();($$)->type = ($1)->type;}	
		| EqualityExpression DOUBLEEQUAL RelationalExpression						{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = "boolean";}	
		| EqualityExpression NE RelationalExpression								{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = "boolean";}
		;
RelationalExpression:	 ShiftExpression											{$$ = createstruct();($$)->type = ($1)->type;}
		| RelationalExpression LT ShiftExpression									{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = "boolean";}
		| RelationalExpression GT ShiftExpression									{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = "boolean";}
		| RelationalExpression LTE ShiftExpression									{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = "boolean";}	
		| RelationalExpression GTE ShiftExpression									{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = "boolean";}	
		| InstanceofExpression														{$$ = createstruct();($$)->type = ($1)->type;}
		;
InstanceofExpression:	 RelationalExpression INSTANCEOF ReferenceType				{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = ($1)->type;}
		;
ShiftExpression:	 AdditiveExpression												{$$ = createstruct();($$)->type = ($1)->type;}
		| ShiftExpression LSHIFT AdditiveExpression									{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = ($1)->type;}
		| ShiftExpression RSHIFT AdditiveExpression								{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = ($1)->type;}	
		| ShiftExpression THREEGT AdditiveExpression								{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = ($1)->type;}
		;
AdditiveExpression:	 MultiplicativeExpression										{$$ = createstruct();($$)->type = ($1)->type;}
		| AdditiveExpression PLUS MultiplicativeExpression			{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = type_change(($1)->type,($3)->type);}			
		| AdditiveExpression MINUS MultiplicativeExpression				{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = type_change(($1)->type,($3)->type);}				
		;
MultiplicativeExpression:	 UnaryExpression										{$$ = createstruct();($$)->type = ($1)->type;}
		| MultiplicativeExpression MULTIPLY UnaryExpression					{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = type_change(($1)->type,($3)->type);}		
		| MultiplicativeExpression DIVIDE UnaryExpression						{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = type_change(($1)->type,($3)->type);}
		| MultiplicativeExpression PERCENT UnaryExpression					{$$ = createstruct();type_check(($1)->type,($3)->type,line);($$)->type = type_change(($1)->type,($3)->type);}		
		;
UnaryExpression:	 PreIncrementExpression							{$$ = createstruct();($$)->type = ($1)->type;}				
		| PreDecrementExpression													{$$ = createstruct();($$)->type = ($1)->type;}
		| PLUS UnaryExpression														{$$ = createstruct();($$)->type = ($2)->type;}
		| MINUS UnaryExpression														{$$ = createstruct();($$)->type = ($2)->type;}
		| UnaryExpressionNotPlusMinus											{$$ = createstruct();($$)->type = ($1)->type;}	
		;
PreIncrementExpression:	 INCREAMENT UnaryExpression						{$$ = createstruct();($$)->type = ($2)->type;}			
		;
PreDecrementExpression:	 DECREAMENT UnaryExpression						{$$ = createstruct();($$)->type = ($2)->type;}			
		;
UnaryExpressionNotPlusMinus:	 PostfixExpression		{$$ = createstruct();($$)->type = ($1)->type;}							
		| TILDA UnaryExpression												{$$ = createstruct();($$)->type = ($2)->type;}	
		| EXCLAM UnaryExpression											{$$ = createstruct();($$)->type = ($2)->type;}		
		| CastExpression															{$$ = createstruct();($$)->type = ($1)->type;}
		| SwitchExpression															{$$ = createstruct();($$)->type = ($1)->type;}
		;
PostfixExpression:	 Primary							{$$ = createstruct();($$)->type = ($1)->type;}							
		| Identifier																{$$ = createstruct();string p = $1;if(lookup(p)){($$)->type = lookup(p)->type;}}
		| ExpressionName														{$$ = createstruct();($$)->type = ($1)->type;}		
		| PostIncrementExpression													{$$ = createstruct();($$)->type = ($1)->type;}
		| PostDecrementExpression												{$$ = createstruct();($$)->type = ($1)->type;}
		;
PostIncrementExpression:	 PostfixExpression INCREAMENT					{$$ = createstruct();($$)->type = ($1)->type;}	
		;
PostDecrementExpression:	 PostfixExpression DECREAMENT					{$$ = createstruct();($$)->type = ($1)->type;}	
		;
CastExpression:	 LRB PrimitiveType RRB UnaryExpression							{$$ = createstruct();($$)->type = ($2)->type; ($4)->type = ($2)->type; type_check(($2)->type,($4)->type,line);}
		| LRB UnannArrayType RRB UnaryExpressionNotPlusMinus						{$$ = createstruct();($$)->type = ($2)->type; ($4)->type = ($2)->type; type_check(($2)->type,($4)->type,line);}
		| LRB UnannArrayType OMAdditionalBound RRB UnaryExpressionNotPlusMinus		{$$ = createstruct();($$)->type = ($2)->type; ($5)->type = ($2)->type; type_check(($2)->type,($5)->type,line);}
		;
SwitchExpression:	 SWITCH LRB Expression RRB {symtable *a = createscope("switch"); changescope(a);} SwitchBlock			{goparent();($$)->type = "switch";}
		;	
VariableAccess:	 ExpressionName										{$$ = createstruct();($$)->type = ($1)->type;}				
    	| Identifier																{$$ = createstruct();}
		| FieldAccess																
		;

%%
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
		for(auto z:c->m){
			csvFile<<z.first<<","<<z.second->type<<","<<z.second->linenumber<<","<<z.second->argcon<<","<<z.second->funcrettype<<","<<z.second->size<<","<<z.second->scope<<"\n";
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