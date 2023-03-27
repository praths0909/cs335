%{
#include <iostream>
#include <string>
#include <vector>
#include<cstring>
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

Node *root = NULL;

Node *createNode(string label, string value, vector <Node *> children) {

    Node *newNode = new Node;
    newNode->label = label;
    newNode->value = value;
    newNode->children = children;
    newNode->expressionLabel = "";
    return newNode;
}

%}

%union {char* str;struct Node* node;}         /* Yacc definitions */


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

%type <node> DotOMAnnotationIdentifier   OMDotOMAnnotationIdentifier   OMAnnotation   OMPSB   PSB   OMTypeParameterModifier   OMAdditionalBound   CommaTypeArgument   OMCommaTypeArgument   ReceiverParameterComma   IdentifierDot   OMImportDeclaration   OMTopLevelClassOrInterfaceDeclaration   OMDotIdentifier   OMModuleDirective   OMRequiresModifier   OMCommaModuleName   CommaModuleName   OMCommaTypeName   CommaTypeName   OMClassModifier   OMCommaTypeParameter   CommaTypeParameter   OMCommaInterfaceType   CommaInterfaceType   OMClassBodyDeclaration   EqualVariableInitializer   OMCommaFormalParameter   CommaFormalParameter   OMCommaExceptionType   CommaExceptionType   OMCommaEnumConstant   CommaEnumConstant   OMEnumConstantModifier   OMCommaRecordComponent   CommaRecordComponent   OMRecordComponentModifier   OMRecordBodyDeclaration   OMInterfaceMemberDeclaration   OMAnnotationInterfaceMemberDeclaration   OMCommaElementValuePair   CommaElementValuePair   OMCommaElementValue   CommaElementValue   OMCommaVariableInitializer   CommaVariableInitializer   OMBlockStatement   OMSwitchRule   OMSwitchBlockStatementGroup   OMSwitchLabelColon   SwitchLabelColon   OMCommaCaseConstant   CommaCaseConstant   OMCommaStatementExpression   CommaStatementExpression   OMCatchClause   OMOrClassType   OrClassType   OMSemicolonResource   SemicolonResource   OMCommaExpression   CommaExpression   OMDimExpr   Modifieropt   UnqualifiedMethodIdentifier   Literal   PrimitiveType   NumericType   IntegralType   FloatingPointType   ReferenceType   TypeParameter   TypeBound   AdditionalBound   TypeArguments   TypeArgumentList   TypeArgument   Wildcard   WildcardBounds   ModuleName   ExpressionName   MethodName   CompilationUnit   OrdinaryCompilationUnit   ModularCompilationUnit   PackageDeclaration   ImportDeclaration   SingleTypeImportDeclaration   SingleStaticImportDeclaration   ImportOnDemandDeclaration   StaticImportOnDemandDeclaration   TopLevelClassOrInterfaceDeclaration   ModuleDeclaration   ModuleDirective   ClassDeclaration   NormalClassDeclaration   TypeParameters   TypeParameterList   ClassExtends   ClassImplements   InterfaceTypeList   ClassPermits   ClassBody   ClassBodyDeclaration   ClassMemberDeclaration   FieldDeclaration   VariableDeclaratorList   VariableDeclarator   VariableDeclaratorId   VariableInitializer   UnannType   UnannPrimitiveType   UnannArrayType   MethodDeclaration   MethodHeader   Result   MethodDeclarator   ReceiverParameter   FormalParameterList   FormalParameter   VariableArityParameter   Throws   ExceptionTypeList   ExceptionType   MethodBody   InstanceInitializer   StaticInitializer   ConstructorDeclaration   ConstructorDeclarator   ConstructorBody   ExplicitConstructorInvocation   EnumDeclaration   EnumBody   EnumConstantList   PRB   PRBArgumentList   EnumConstant   EnumConstantModifier   EnumBodyDeclarations   RecordDeclaration   RecordHeader   RecordComponentList   RecordComponent   VariableArityRecordComponent   RecordComponentModifier   RecordBody   RecordBodyDeclaration   CompactConstructorDeclaration   InterfaceDeclaration   NormalInterfaceDeclaration   InterfaceModifier   InterfaceExtends   InterfacePermits   InterfaceBody   InterfaceMemberDeclaration   ConstantDeclaration   InterfaceMethodDeclaration   AnnotationInterfaceDeclaration   AnnotationInterfaceBody   AnnotationInterfaceMemberDeclaration   AnnotationInterfaceElementDeclaration   DefaultValue   Annotation   NormalAnnotation   ElementValuePairList   ElementValuePair   ElementValue   ElementValueArrayInitializer   ElementValueList   MarkerAnnotation   SingleElementAnnotation   ArrayInitializer   VariableInitializerList   Block   BlockStatements   BlockStatement   LocalClassOrInterfaceDeclaration   LocalVariableDeclarationStatement   LocalVariableDeclaration   LocalVariableType   Statement   StatementNoShortIf   StatementWithoutTrailingSubstatement   EmptyStatement   LabeledStatement   LabeledStatementNoShortIf   ExpressionStatement   StatementExpression   IfThenStatement   IfThenElseStatement   IfThenElseStatementNoShortIf   AssertStatement   SwitchStatement   SwitchBlock   SwitchRule   SwitchBlockStatementGroup   SwitchLabel   CaseConstant   WhileStatement   WhileStatementNoShortIf   DoStatement   ForStatement   ForStatementNoShortIf   BasicForStatement   BasicForStatementNoShortIf   ForInit   ForUpdate   StatementExpressionList   EnhancedForStatement   EnhancedForStatementNoShortIf   BreakStatement   YieldStatement   ContinueStatement   ReturnStatement   ThrowStatement   SynchronizedStatement   TryStatement   Catches   CatchClause   CatchFormalParameter   CatchType   Finally   TryWithResourcesStatement   ResourceSpecification   ResourceList   Resource   Primary   PrimaryNoNewArray   ClassLiteral   ClassInstanceCreationExpression   UnqualifiedClassInstanceCreationExpression   ClassOrInterfaceTypeToInstantiate   TypeArgumentsOrDiamond   FieldAccess   ArrayAccess   MethodInvocation   ArgumentList   MethodReference   ArrayCreationExpression   DimExpr   Expression   AssignmentExpression   Assignment   LeftHandSide     ConditionalExpression   ConditionalOrExpression   ConditionalAndExpression   InclusiveOrExpression   ExclusiveOrExpression   AndExpression   EqualityExpression   RelationalExpression   InstanceofExpression   ShiftExpression   AdditiveExpression   MultiplicativeExpression   UnaryExpression   PreIncrementExpression   PreDecrementExpression   UnaryExpressionNotPlusMinus   PostfixExpression   PostIncrementExpression   PostDecrementExpression   CastExpression   SwitchExpression   VariableAccess   


%%

DotOMAnnotationIdentifier: DOT OMAnnotation Identifier						{Node*lexeme=createNode("ID",$3,{});$$ = createNode("DotOMAnnotationIdentifier",$1,{$2,lexeme});}	
		;
OMDotOMAnnotationIdentifier: DotOMAnnotationIdentifier 						{$$=createNode("OMDotOMAnnotationIdentifier","",{$1});}
		|	OMDotOMAnnotationIdentifier DotOMAnnotationIdentifier			{$$=$1;$$->children.push_back($2);}
		;
OMAnnotation: Annotation													{$$=createNode("OMAnnotation","",{$1});}
        |	OMAnnotation Annotation 										{$$=$1;$$->children.push_back($2);}
        ;
OMPSB:  PSB																	{$$=createNode("OMPSB","[]",{$1});}
		|	OMPSB PSB														{$$=$1;$$->children.push_back($2);}
		;
PSB: LSB RSB																{$$=createNode("PSB","[]",{});}
		;
OMTypeParameterModifier: Annotation											{$$=createNode("OMTypeParameterModifier","",{$1});}
        |	OMTypeParameterModifier Annotation								{$$=$1;$$->children.push_back($2);}
        ;
OMAdditionalBound:   AdditionalBound										{$$=createNode("OMAdditionalBound","",{$1});}
        |	OMAdditionalBound   AdditionalBound 							{$$=$1;$$->children.push_back($2);}
        ;
CommaTypeArgument: COMMA TypeArgument										{$$=createNode("CommaTypeArgument",$1,{$2});}
        ;
OMCommaTypeArgument: CommaTypeArgument										{$$=createNode("OMCommaTypeArgument","",{$1});}
        |OMCommaTypeArgument CommaTypeArgument 								{$$=$1;$$->children.push_back($2);}
        ;
ReceiverParameterComma: ReceiverParameter COMMA								{$$=createNode("ReceiverParameterComma",$2,{$1});}
        ;
IdentifierDot:  Identifier DOT												{Node*lexeme=createNode("ID",$1,{});$$ = createNode("IdentifierDot",$2,{lexeme});}
        ;
OMImportDeclaration: ImportDeclaration										{$$=createNode("OMImportDeclaration","",{$1});}
    	|   OMImportDeclaration ImportDeclaration 							{$$=$1;$$->children.push_back($2);}
    	;
OMTopLevelClassOrInterfaceDeclaration: TopLevelClassOrInterfaceDeclaration 						{$$=createNode("OMTopLevelClassOrInterfaceDeclaration","",{$1});}
    	|   OMTopLevelClassOrInterfaceDeclaration TopLevelClassOrInterfaceDeclaration 			{$$=$1;$$->children.push_back($2);}
    	;
OMDotIdentifier: DOT Identifier												{Node*lexeme=createNode("ID",$2,{});$$ = createNode("IdentifierDot",$1,{lexeme});}
    	|  OMDotIdentifier DOT Identifier									{Node*lexeme=createNode("ID",$3,{});$$=$1;$$->children.push_back(lexeme);}
    	;
OMModuleDirective: ModuleDirective											{$$=createNode("OMModuleDirective","",{$1});}
    	|  OMModuleDirective ModuleDirective 								{$$=$1;$$->children.push_back($2);}
    	;
OMRequiresModifier: Modifieropt												{$$=createNode("OMRequiresModifier","",{$1});}
    	| OMRequiresModifier  Modifieropt									{$$=$1;$$->children.push_back($2);}
    	;
OMCommaModuleName: CommaModuleName											{$$=createNode("OMCommaModuleName","",{$1});}
    	|  OMCommaModuleName CommaModuleName 								{$$=$1;$$->children.push_back($2);}
    	;
CommaModuleName:    COMMA ModuleName										{$$=createNode("CommaModuleName",$1,{$2});}
    	;
OMCommaTypeName: CommaTypeName 												{$$=createNode("OMCommaTypeName","",{$1});}
    	|  OMCommaTypeName CommaTypeName 									{$$=$1;$$->children.push_back($2);}
    	;
CommaTypeName:    COMMA Identifier											{Node*lexeme=createNode("ID",$2,{});$$ = createNode("CommaTypeName",$1,{lexeme});}
    	|  COMMA ExpressionName												{$$=createNode("CommaTypeName",$1,{$2});}
    	;
OMClassModifier:    InterfaceModifier										{$$=createNode("OMClassModifier","",{$1});}
        |     OMClassModifier  InterfaceModifier							{$$=$1;$$->children.push_back($2);}
        ;
OMCommaTypeParameter:   CommaTypeParameter									{$$=createNode("OMCommaTypeParameter","",{$1});}
        |      OMCommaTypeParameter CommaTypeParameter 						{$$=$1;$$->children.push_back($2);}
        ;	
CommaTypeParameter:     COMMA TypeParameter									{$$=createNode("CommaTypeParameter",$1,{$2});}
        ;
OMCommaInterfaceType:    CommaInterfaceType									{$$=createNode("OMCommaInterfaceType","",{$1});}
        |      OMCommaInterfaceType CommaInterfaceType 						{$$=$1;$$->children.push_back($2);}
        ;
CommaInterfaceType:     COMMA Identifier									{Node*lexeme=createNode("ID",$2,{});$$ = createNode("CommaTypeName",$1,{lexeme});}
        ;
OMClassBodyDeclaration:  ClassBodyDeclaration								{$$=createNode("OMClassBodyDeclaration","",{$1});}
        |    OMClassBodyDeclaration   ClassBodyDeclaration 					{$$=$1;$$->children.push_back($2);}
        ;
EqualVariableInitializer:   EQUAL VariableInitializer						{$$=createNode("EqualVariableInitializer",$1,{$2});}
        ;
OMCommaFormalParameter: CommaFormalParameter								{$$=createNode("OMCommaFormalParameter","",{$1});}
        |      OMCommaFormalParameter CommaFormalParameter 					{$$=$1;$$->children.push_back($2);}
        ;
CommaFormalParameter:   COMMA FormalParameter								{$$=createNode("CommaFormalParameter",$1,{$2});}
        ;
OMCommaExceptionType:   CommaExceptionType									{$$=createNode("OMCommaExceptionType","",{$1});}
        |     OMCommaExceptionType  CommaExceptionType 						{$$=$1;$$->children.push_back($2);}
        ;
CommaExceptionType: COMMA ExceptionType										{$$=createNode("CommaExceptionType",$1,{$2});}
        ;
OMCommaEnumConstant:   CommaEnumConstant 									{$$=createNode("OMCommaEnumConstant","",{$1});}
        |     OMCommaEnumConstant  CommaEnumConstant 						{$$=$1;$$->children.push_back($2);}
        ;
CommaEnumConstant:      EnumConstant COMMA									{$$=createNode("CommaEnumConstant",$2,{$1});}	
        ;	
OMEnumConstantModifier: EnumConstantModifier								{$$=createNode("OMEnumConstantModifier","",{$1});}
        |     OMEnumConstantModifier  EnumConstantModifier 					{$$=$1;$$->children.push_back($2);}
        ;
OMCommaRecordComponent: CommaRecordComponent								{$$=createNode("OMCommaRecordComponent","",{$1});}	
        |      OMCommaRecordComponent CommaRecordComponent 					{$$=$1;$$->children.push_back($2);}
        ;
CommaRecordComponent:   COMMA RecordComponent								{$$=createNode("CommaRecordComponent",$1,{$2});}	
        ;
OMRecordComponentModifier:    RecordComponentModifier 						{$$=createNode("OMRecordComponentModifier","",{$1});} 
        |      OMRecordComponentModifier RecordComponentModifier 			{$$=$1;$$->children.push_back($2);}
        ;
OMRecordBodyDeclaration:       RecordBodyDeclaration 						{$$=createNode("OMRecordBodyDeclaration","",{$1});}
        |     OMRecordBodyDeclaration  RecordBodyDeclaration   				{$$=$1;$$->children.push_back($2);}
        ;
OMInterfaceMemberDeclaration: InterfaceMemberDeclaration					{$$=createNode("OMInterfaceMemberDeclaration","",{$1});}
    	|  OMInterfaceMemberDeclaration InterfaceMemberDeclaration 			{$$=$1;$$->children.push_back($2);}
    	;
OMAnnotationInterfaceMemberDeclaration:  AnnotationInterfaceMemberDeclaration					{$$=createNode("OMAnnotationInterfaceMemberDeclaration","",{$1});}
    	|  OMAnnotationInterfaceMemberDeclaration AnnotationInterfaceMemberDeclaration 			{$$=$1;$$->children.push_back($2);}
    	;
OMCommaElementValuePair: CommaElementValuePair													{$$=createNode("OMCommaElementValuePair","",{$1});}
    	|  OMCommaElementValuePair CommaElementValuePair 										{$$=$1;$$->children.push_back($2);}
    	;
CommaElementValuePair:   COMMA ElementValuePair								{$$=createNode("CommaElementValuePair",$1,{$2});}
    	;
OMCommaElementValue: CommaElementValue										{$$=createNode("OMCommaElementValue","",{$1});}
    	|  OMCommaElementValue CommaElementValue 							{$$=$1;$$->children.push_back($2);}
    	;
CommaElementValue:   COMMA ElementValue 									{$$=createNode("CommaElementValue",$1,{$2});}
    	;	
OMCommaVariableInitializer: CommaVariableInitializer						{$$=createNode("OMCommaVariableInitializer","",{$1});}
        |     OMCommaVariableInitializer  CommaVariableInitializer 			{$$=$1;$$->children.push_back($2);}
        ;
CommaVariableInitializer:       COMMA VariableInitializer					{$$=createNode("CommaVariableInitializer",$1,{$2});}
        ;	
OMBlockStatement: BlockStatement 											{$$=createNode("OMBlockStatement","",{$1});}
    	|  OMBlockStatement BlockStatement 									{$$=$1;$$->children.push_back($2);}
    	;
OMSwitchRule: SwitchRule													{$$=createNode("OMSwitchRule","",{$1});}
    	|  OMSwitchRule SwitchRule 											{$$=$1;$$->children.push_back($2);}
    	;
OMSwitchBlockStatementGroup: SwitchBlockStatementGroup						{$$=createNode("OMSwitchBlockStatementGroup","",{$1});}
    | OMSwitchBlockStatementGroup  SwitchBlockStatementGroup 				{$$=$1;$$->children.push_back($2);}
    ;
OMSwitchLabelColon: SwitchLabelColon										{$$=createNode("OMSwitchLabelColon","",{$1});}
    |  OMSwitchLabelColon SwitchLabelColon 									{$$=$1;$$->children.push_back($2);}
    ;
SwitchLabelColon:   SwitchLabel COLON										{$$=createNode("SwitchLabelColon",$2,{$1});}
    ;
OMCommaCaseConstant: CommaCaseConstant 										{$$=createNode("OMCommaCaseConstant","",{$1});}
    |   OMCommaCaseConstant CommaCaseConstant 								{$$=$1;$$->children.push_back($2);}
    ;
CommaCaseConstant:  COMMA CaseConstant										{$$=createNode("CommaCaseConstant",$1,{$2});}
    ;
OMCommaStatementExpression: CommaStatementExpression						{$$=createNode("OMCommaStatementExpression","",{$1});}
    | OMCommaStatementExpression  CommaStatementExpression 					{$$=$1;$$->children.push_back($2);}
    ;
CommaStatementExpression:  COMMA StatementExpression						{$$=createNode("CommaStatementExpression",$1,{$2});}
    ;
OMCatchClause:	CatchClause													{$$=createNode("OMCatchClause","",{$1});}
    |  OMCatchClause CatchClause 											{$$=$1;$$->children.push_back($2);}
    ;
OMOrClassType: OrClassType													{$$=createNode("OMOrClassType","",{$1});}
    |  OMOrClassType OrClassType 											{$$=$1;$$->children.push_back($2);}
    ;
OrClassType:   BITOR Identifier												{Node*lexeme=createNode("ID",$2,{});$$=createNode("OrClassType",$1,{lexeme});}
    ;
OMSemicolonResource: SemicolonResource										{$$=createNode("OMSemicolonResource","",{$1});}
    | OMSemicolonResource  SemicolonResource 								{$$=$1;$$->children.push_back($2);}
    ;
SemicolonResource:  Resource SEMICOLON										{$$=createNode("SemicolonResource",$2,{$1});}
    ;
OMCommaExpression:   CommaExpression										{$$=createNode("OMCommaExpression","",{$1});}
        |  OMCommaExpression CommaExpression 								{$$=$1;$$->children.push_back($2);}
        ;
CommaExpression:    COMMA Expression										{$$=createNode("CommaExpression",$1,{$2});}
        ;
OMDimExpr:      DimExpr														{$$=createNode("OMDimExpr","",{$1});}
        |     OMDimExpr  DimExpr 											{$$=$1;$$->children.push_back($2);}
        ;
Modifieropt:	PUBLIC														{$$ = createNode("Modifier",$1,{});}
		| PROTECTED															{$$ = createNode("Modifier",$1,{});}
		| PRIVATE															{$$ = createNode("Modifier",$1,{});}
		| ABSTRACT															{$$ = createNode("Modifier",$1,{});}
		| STATIC															{$$ = createNode("Modifier",$1,{});}
		| SEALED															{$$ = createNode("Modifier",$1,{});}
		| STRICTFP															{$$ = createNode("Modifier",$1,{});}
		| FINAL																{$$ = createNode("Modifier",$1,{});}
		;
Identifier:	 IDENTIFIERWK													{$$ = $1;}
		;
UnqualifiedMethodIdentifier:	 IDENTIFIERWK				{Node * lexeme=createNode("ID",$1,{}); $$ = createNode("MethodIdentifier",$1,{lexeme});}
		| EXPORTS											{$$ = createNode("MethodIdentifier",$1,{});}
		| OPENS												{$$ = createNode("MethodIdentifier",$1,{});}
		| REQUIRES											{$$ = createNode("MethodIdentifier",$1,{});}
		| USES												{$$ = createNode("MethodIdentifier",$1,{});}
		| MODULE											{$$ = createNode("MethodIdentifier",$1,{});}
		| PERMITS											{$$ = createNode("MethodIdentifier",$1,{});}
		| SEALED											{$$ = createNode("MethodIdentifier",$1,{});}
		| VAR												{$$ = createNode("MethodIdentifier",$1,{});}
		| NONSEALED											{$$ = createNode("MethodIdentifier",$1,{});}
		| PROVIDES											{$$ = createNode("MethodIdentifier",$1,{});}
		| TO												{$$ = createNode("MethodIdentifier",$1,{});}
		| WITH												{$$ = createNode("MethodIdentifier",$1,{});}
		| OPEN												{$$ = createNode("MethodIdentifier",$1,{});}
		| RECORD											{$$ = createNode("MethodIdentifier",$1,{});}
		| TRANSITIVE										{$$ = createNode("MethodIdentifier",$1,{});}
		;
Literal:	 INTEGERLITERAL									{Node * lexeme=createNode("Integer",$1,{}); $$ = createNode("Literal",$1,{lexeme});}
		| FLOATINGPOINTLITERAL								{Node * lexeme=createNode("Float",$1,{}); $$ = createNode("Literal",$1,{lexeme});}
		| BOOLEANLITERAL									{Node * lexeme=createNode("Boolean",$1,{}); $$ = createNode("Literal",$1,{lexeme});}
		| NULLLITERAL										{Node * lexeme=createNode("Null",$1,{}); $$ = createNode("Literal",$1,{lexeme});}
		| CHARACTERLITERAL									{Node * lexeme=createNode("Character",$1,{}); $$ = createNode("Literal",$1,{lexeme});}
		| STRING											{Node * lexeme=createNode("String",$1,{}); $$ = createNode("Literal",$1,{lexeme});}
		| TEXTBLOCKS										{Node * lexeme=createNode("Textblock",$1,{}); $$ = createNode("Literal",$1,{lexeme});}
		;
ASSIGNMENTOPERATOR:	 NEWASSIGNMENTOPERATOR					{$$ = $1;}
		| EQUAL												{$$ = $1;}
		;
PrimitiveType:	 UnannPrimitiveType							{$$ = createNode("PrimitiveType","",{$1});}
		| OMAnnotation UnannPrimitiveType					{$$ = createNode("PrimitiveType","",{$1,$2});}
		;
NumericType:	 IntegralType								{$$= $1;}
		| FloatingPointType									{$$=$1;}
		;
IntegralType:	 BYTE										{$$ = createNode("IntegralType",$1,{});}
		| SHORT												{$$ = createNode("IntegralType",$1,{});}
		| INT												{$$ = createNode("IntegralType",$1,{});}
		| LONG												{$$ = createNode("IntegralType",$1,{});}
		| CHAR												{$$ = createNode("IntegralType",$1,{});}
		;
FloatingPointType:	 FLOAT									{$$ = createNode("FloatType",$1,{});}
		| DOUBLE											{$$ = createNode("FloatType",$1,{});}
		;
ReferenceType:	 Identifier									{Node * lexeme=createNode("ID",$1,{}); $$ = createNode("ReferenceType","",{lexeme});}
		| UnannArrayType									{$$=$1;}
		;
TypeParameter:	 Identifier									{Node * lexeme=createNode("ID",$1,{}); $$ = createNode("Typeparameter","",{lexeme});}
		| Identifier TypeBound								{Node * lexeme=createNode("ID",$1,{}); $$ = createNode("Typeparameter","",{lexeme,$2});}
		| OMTypeParameterModifier Identifier				{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("Typeparameter","",{$1,lexeme});}
		| OMTypeParameterModifier Identifier TypeBound		{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("Typeparameter","",{$1,lexeme,$3});}
		;
TypeBound:	 EXTENDS Identifier								{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("Typebound",$1,{lexeme});}	
		| EXTENDS Identifier OMAdditionalBound				{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("Typebound",$1,{lexeme,$3});}
		;
AdditionalBound:	 BITAND Identifier						{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("AdditionalBound",$1,{lexeme});}
		;
TypeArguments:	 LT TypeArgumentList GT						{$$ = createNode("TypeArguments","<>",{$2});}	
		;
TypeArgumentList:	 TypeArgument							{$$ = createNode("TypeArgumentsList","",{$1});}	
		| TypeArgument OMCommaTypeArgument					{$$ = createNode("TypeArgumentsList","",{$1,$2});}	
		;
TypeArgument:	 ReferenceType								{$$=$1;}
		| Wildcard											{$$=$1;}
		;
Wildcard:	 QM												{$$ = createNode("Wildcard",$1,{});}			
		| QM WildcardBounds									{$$ = createNode("Wildcard",$1,{$2});}
		| OMAnnotation QM									{$$ = createNode("Wildcard",$2,{$1});}
		| OMAnnotation QM WildcardBounds					{$$ = createNode("Wildcard",$2,{$1,$3});}
		;
WildcardBounds:	 EXTENDS ReferenceType						{$$ = createNode("WildcardBounds",$1,{$2});}
		| SUPER ReferenceType								{$$ = createNode("WildcardBounds",$1,{$2});}
		;
ModuleName:	 Identifier										{Node * lexeme=createNode("ID",$1,{}); $$ = createNode("ModuleName","",{lexeme});}
		| ModuleName DOT Identifier							{ Node* lexeme = createNode("ID", $3, {}); $1->children.push_back(lexeme); $$ = $1; }
		;
ExpressionName:	 Identifier DOT Identifier					{Node * lexeme1=createNode("ID",$1,{});Node * lexeme2=createNode("ID",$3,{}); $$ = createNode("ExpressionName",$2,{lexeme1,lexeme2});}
		| ExpressionName DOT Identifier						{ Node* lexeme = createNode("ID", $3, {}); $1->children.push_back(lexeme); $$ = $1; }
		;
MethodName:	 UnqualifiedMethodIdentifier					{$$=$1;}
		;
CompilationUnit:	 OrdinaryCompilationUnit				{root= createNode("PROGRAM","",{$1});}
		| ModularCompilationUnit							{root= createNode("PROGRAM","",{$1});}
		;
OrdinaryCompilationUnit:																{$$ = createNode("OrdinaryProgram","EmptyProgram",{});}
		| OMTopLevelClassOrInterfaceDeclaration											{$$ = createNode("OrdinaryProgram","",{$1});}
		| OMImportDeclaration															{$$ = createNode("OrdinaryProgram","",{$1});}
		| OMImportDeclaration OMTopLevelClassOrInterfaceDeclaration						{$$ = createNode("OrdinaryProgram","",{$1,$2});}
		| PackageDeclaration															{$$ = createNode("OrdinaryProgram","",{$1});}				
		| PackageDeclaration OMTopLevelClassOrInterfaceDeclaration						{$$ = createNode("OrdinaryProgram","",{$1,$2});}
		| PackageDeclaration OMImportDeclaration										{$$ = createNode("OrdinaryProgram","",{$1,$2});}
		| PackageDeclaration OMImportDeclaration OMTopLevelClassOrInterfaceDeclaration	{$$ = createNode("OrdinaryProgram","",{$1,$2,$3});}
		;
ModularCompilationUnit:	 ModuleDeclaration												{$$ = createNode("ModularProgram","",{$1});}					
		| OMImportDeclaration ModuleDeclaration											{$$ = createNode("ModularProgram","",{$1,$2});}
		;
PackageDeclaration:	 PACKAGE Identifier SEMICOLON										{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("PackageDeclaration",$1,{lexeme});}
		| PACKAGE Identifier OMDotIdentifier SEMICOLON									{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("PackageDeclaration",$1,{lexeme,$3});}	
		| OMAnnotation PACKAGE Identifier SEMICOLON										{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("PackageDeclaration",$2,{$1,lexeme});}
		| OMAnnotation PACKAGE Identifier OMDotIdentifier SEMICOLON						{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("PackageDeclaration",$2,{$1,lexeme,$4});}
		;
ImportDeclaration:	 SingleTypeImportDeclaration										{$$=$1;}
		| SingleStaticImportDeclaration													{$$ =$1;}												
		| StaticImportOnDemandDeclaration												{$$ =$1;}
		|	ImportOnDemandDeclaration													{$$ =$1;}
		;
SingleTypeImportDeclaration:	 IMPORT Identifier SEMICOLON							{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("Import",$1,{lexeme});}							
    	| IMPORT ExpressionName SEMICOLON												{$$=createNode("Import",$1,{$2});}
		;
SingleStaticImportDeclaration:	IMPORT STATIC ExpressionName SEMICOLON					{$$=createNode("StaticImport","import static;",{$3});}
		;
ImportOnDemandDeclaration:	 IMPORT Identifier DOT MULTIPLY SEMICOLON					{Node * lexeme=createNode("ID",$2,{});Node *temp = createNode("OP", $4, {} ); $$ = createNode("Import_Static", $1 , {lexeme, temp}); }
    | IMPORT ExpressionName DOT MULTIPLY SEMICOLON										{Node *temp = createNode("OP", $4, {} ); $$ = createNode("Import_Static", $1 , {$2, temp}); }
		;
StaticImportOnDemandDeclaration:	 IMPORT STATIC Identifier DOT MULTIPLY SEMICOLON	{Node * lexeme=createNode("ID",$3,{});Node *temp = createNode("OP", $5, {} ); $$ = createNode("Import_Static", $1 , {lexeme, temp}); }
    | IMPORT STATIC ExpressionName DOT MULTIPLY SEMICOLON								{Node *temp = createNode("OP", $5, {} ); $$ = createNode("Import_Static", $1 , {$3, temp}); }
		;
TopLevelClassOrInterfaceDeclaration:	 ClassDeclaration								{$$=$1;}
		| InterfaceDeclaration															{$$=$1;}
		| SEMICOLON																		{$$ = createNode("Empty",$1,{});}
		;
ModuleDeclaration:	 MODULE Identifier LCB RCB											{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("ModuleDeclaration",$1,{lexeme});}
		| MODULE Identifier LCB OMModuleDirective RCB									{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("ModuleDeclaration",$1,{lexeme,$4});}
		| MODULE Identifier OMDotIdentifier LCB RCB										{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("ModuleDeclaration",$1,{lexeme,$3});}
		| MODULE Identifier OMDotIdentifier LCB OMModuleDirective RCB					{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("ModuleDeclaration",$1,{lexeme,$3,$5});}
		| OPEN MODULE Identifier LCB RCB												{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("ModuleDeclaration","open module{}",{lexeme});}
		| OPEN MODULE Identifier LCB OMModuleDirective RCB								{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("ModuleDeclaration","open module{}",{lexeme,$5});}
		| OPEN MODULE Identifier OMDotIdentifier LCB RCB								{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("ModuleDeclaration","open module{}",{lexeme,$4});}
		| OPEN MODULE Identifier OMDotIdentifier LCB OMModuleDirective RCB				{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("ModuleDeclaration","open module{}",{lexeme,$4,$6});}
		| OMAnnotation MODULE Identifier LCB RCB										{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("ModuleDeclaration",$2,{$1,lexeme});}
		| OMAnnotation MODULE Identifier LCB OMModuleDirective RCB						{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("ModuleDeclaration",$2,{$1,lexeme,$5});}
		| OMAnnotation MODULE Identifier OMDotIdentifier LCB RCB						{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("ModuleDeclaration",$2,{$1,lexeme,$4});}
		| OMAnnotation MODULE Identifier OMDotIdentifier LCB OMModuleDirective RCB		{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("ModuleDeclaration",$2,{$1,lexeme,$4,$6});}
		| OMAnnotation OPEN MODULE Identifier LCB RCB									{Node * lexeme=createNode("ID",$4,{}); $$ = createNode("ModuleDeclaration","open module{}",{$1,lexeme});}
		| OMAnnotation OPEN MODULE Identifier LCB OMModuleDirective RCB					{Node * lexeme=createNode("ID",$4,{}); $$ = createNode("ModuleDeclaration","open module{}",{$1,lexeme,$6});}
		| OMAnnotation OPEN MODULE Identifier OMDotIdentifier LCB RCB					{Node * lexeme=createNode("ID",$4,{}); $$ = createNode("ModuleDeclaration","open module{}",{$1,lexeme,$5});}
		| OMAnnotation OPEN MODULE Identifier OMDotIdentifier LCB OMModuleDirective RCB	 {Node * lexeme=createNode("ID",$4,{}); $$ = createNode("ModuleDeclaration","open module{}",{$1,lexeme,$5,$7});}
		;
ModuleDirective:	 REQUIRES ModuleName SEMICOLON									{$$=createNode("ModuleDirective",$1,{$2});}
		| REQUIRES OMRequiresModifier ModuleName SEMICOLON							{$$=createNode("ModuleDirective",$1,{$2,$3});}
		| EXPORTS Identifier SEMICOLON												{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("ModuleDirective",$1,{lexeme});}
		| EXPORTS Identifier TO ModuleName SEMICOLON								{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("ModuleDirective",$1,{lexeme,$4});}
		| EXPORTS Identifier TO ModuleName OMCommaModuleName SEMICOLON				{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("ModuleDirective",$1,{lexeme,$4,$5});}
		| OPENS Identifier SEMICOLON												{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("ModuleDirective",$1,{lexeme});}
		| OPENS Identifier TO ModuleName SEMICOLON									{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("ModuleDirective",$1,{lexeme,$4});}
		| OPENS Identifier TO ModuleName OMCommaModuleName SEMICOLON				{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("ModuleDirective",$1,{lexeme,$4,$5});}
		| USES Identifier SEMICOLON													{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("ModuleDirective",$1,{lexeme});}
		| PROVIDES Identifier WITH Identifier SEMICOLON								{Node * lexeme=createNode("ID",$2,{}); Node * lexeme1=createNode("ID",$4,{});$$ = createNode("ModuleDirective",$1,{lexeme,lexeme1});}
		| PROVIDES Identifier WITH Identifier OMCommaTypeName SEMICOLON				{Node * lexeme=createNode("ID",$2,{});Node * lexeme1=createNode("ID",$4,{}); $$ = createNode("ModuleDirective",$1,{lexeme,lexeme1,$5});}
		| EXPORTS ExpressionName SEMICOLON											{$$=createNode("ModuleDirective",$1,{$2});}
		| EXPORTS ExpressionName TO ModuleName SEMICOLON							{$$=createNode("ModuleDirective",$1,{$2,$4});}
		| EXPORTS ExpressionName TO ModuleName OMCommaModuleName SEMICOLON			{$$=createNode("ModuleDirective",$1,{$2,$4,$5});}
		| OPENS ExpressionName SEMICOLON											{$$=createNode("ModuleDirective",$1,{$2});}
		| OPENS ExpressionName TO ModuleName SEMICOLON								{$$=createNode("ModuleDirective",$1,{$2,$4});}
		| OPENS ExpressionName TO ModuleName OMCommaModuleName SEMICOLON			{$$=createNode("ModuleDirective",$1,{$2,$4,$5});}
		| USES ExpressionName SEMICOLON												{$$=createNode("ModuleDirective",$1,{$2});}
		| PROVIDES ExpressionName WITH ExpressionName SEMICOLON						{$$=createNode("ModuleDirective",$1,{$2,$4});}
		| PROVIDES ExpressionName WITH ExpressionName OMCommaTypeName SEMICOLON		{$$=createNode("ModuleDirective",$1,{$2,$4,$5});}
		| PROVIDES ExpressionName WITH Identifier SEMICOLON							{Node * lexeme=createNode("ID",$4,{}); $$ = createNode("ModuleDirective",$1,{$2,lexeme});}
		| PROVIDES Identifier WITH ExpressionName OMCommaTypeName SEMICOLON			{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("ModuleDirective",$1,{lexeme,$4,$5});}
		| PROVIDES Identifier WITH ExpressionName SEMICOLON							{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("ModuleDirective",$1,{lexeme,$4});}
		| PROVIDES ExpressionName WITH Identifier OMCommaTypeName SEMICOLON			{Node * lexeme=createNode("ID",$4,{}); $$ = createNode("ModuleDirective",$1,{$2,lexeme,$5});}
		;
ClassDeclaration:	 NormalClassDeclaration											{$$=$1;}
		| EnumDeclaration															{$$=$1;}
		| RecordDeclaration															{$$=$1;}
		;
NormalClassDeclaration:	 CLASS Identifier ClassBody														{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("NormalClassDeclr",$1,{lexeme,$3});}
		| CLASS Identifier ClassPermits ClassBody														{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("NormalClassDeclr",$1,{lexeme,$3,$4});}
		| CLASS Identifier ClassImplements ClassBody													{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("NormalClassDeclr",$1,{lexeme,$3,$4});}
		| CLASS Identifier ClassImplements ClassPermits ClassBody										{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("NormalClassDeclr",$1,{lexeme,$3,$4,$5});}
		| CLASS Identifier ClassExtends ClassBody														{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("NormalClassDeclr",$1,{lexeme,$3,$4});}
		| CLASS Identifier ClassExtends ClassPermits ClassBody											{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("NormalClassDeclr",$1,{lexeme,$3,$4,$5});}
		| CLASS Identifier ClassExtends ClassImplements ClassBody										{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("NormalClassDeclr",$1,{lexeme,$3,$4,$5});}
		| CLASS Identifier ClassExtends ClassImplements ClassPermits ClassBody							{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("NormalClassDeclr",$1,{lexeme,$3,$4,$5,$6});}
		| CLASS Identifier TypeParameters ClassBody														{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("NormalClassDeclr",$1,{lexeme,$3,$4});}
		| CLASS Identifier TypeParameters ClassPermits ClassBody										{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("NormalClassDeclr",$1,{lexeme,$3,$4,$5});}
		| CLASS Identifier TypeParameters ClassImplements ClassBody										{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("NormalClassDeclr",$1,{lexeme,$3,$4,$5});}
		| CLASS Identifier TypeParameters ClassImplements ClassPermits ClassBody						{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("NormalClassDeclr",$1,{lexeme,$3,$4,$5,$6});}
		| CLASS Identifier TypeParameters ClassExtends ClassBody										{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("NormalClassDeclr",$1,{lexeme,$3,$4,$5});}
		| CLASS Identifier TypeParameters ClassExtends ClassPermits ClassBody							{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("NormalClassDeclr",$1,{lexeme,$3,$4,$5,$6});}
		| CLASS Identifier TypeParameters ClassExtends ClassImplements ClassBody						{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("NormalClassDeclr",$1,{lexeme,$3,$4,$5,$6});}
		| CLASS Identifier TypeParameters ClassExtends ClassImplements ClassPermits ClassBody			{Node * lexeme=createNode("ID",$2,{}); $$ = createNode("NormalClassDeclr",$1,{lexeme,$3,$4,$5,$6,$7});}
		| OMClassModifier CLASS Identifier ClassBody													{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("NormalClassDeclr",$2,{$1,lexeme,$4});}
		| OMClassModifier CLASS Identifier ClassPermits ClassBody										{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("NormalClassDeclr",$2,{$1,lexeme,$4,$5});}
		| OMClassModifier CLASS Identifier ClassImplements ClassBody									{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("NormalClassDeclr",$2,{$1,lexeme,$4,$5});}
		| OMClassModifier CLASS Identifier ClassImplements ClassPermits ClassBody						{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("NormalClassDeclr",$2,{$1,lexeme,$4,$5,$6});}
		| OMClassModifier CLASS Identifier ClassExtends ClassBody										{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("NormalClassDeclr",$2,{$1,lexeme,$4,$5});}
		| OMClassModifier CLASS Identifier ClassExtends ClassPermits ClassBody							{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("NormalClassDeclr",$2,{$1,lexeme,$4,$5,$6});}
		| OMClassModifier CLASS Identifier ClassExtends ClassImplements ClassBody						{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("NormalClassDeclr",$2,{$1,lexeme,$4,$5,$6});}
		| OMClassModifier CLASS Identifier ClassExtends ClassImplements ClassPermits ClassBody			{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("NormalClassDeclr",$2,{$1,lexeme,$4,$5,$6,$7});}
		| OMClassModifier CLASS Identifier TypeParameters ClassBody										{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("NormalClassDeclr",$2,{$1,lexeme,$4,$5});}
		| OMClassModifier CLASS Identifier TypeParameters ClassPermits ClassBody						{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("NormalClassDeclr",$2,{$1,lexeme,$4,$5,$6});}
		| OMClassModifier CLASS Identifier TypeParameters ClassImplements ClassBody						{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("NormalClassDeclr",$2,{$1,lexeme,$4,$5,$6});}
		| OMClassModifier CLASS Identifier TypeParameters ClassImplements ClassPermits ClassBody		{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("NormalClassDeclr",$2,{$1,lexeme,$4,$5,$6,$7});}
		| OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassBody						{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("NormalClassDeclr",$2,{$1,lexeme,$4,$5,$6});}
		| OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassPermits ClassBody			{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("NormalClassDeclr",$2,{$1,lexeme,$4,$5,$6,$7});}
		| OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassImplements ClassBody		{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("NormalClassDeclr",$2,{$1,lexeme,$4,$5,$6,$7});}
		| OMClassModifier CLASS Identifier TypeParameters ClassExtends ClassImplements ClassPermits ClassBody	{Node * lexeme=createNode("ID",$3,{}); $$ = createNode("NormalClassDeclr",$2,{$1,lexeme,$4,$5,$6,$7,$8});}
		;
TypeParameters:	 LT TypeParameterList GT								{$$=createNode("Typeparameters","< >",{$2});}
		;
TypeParameterList: TypeParameter										{$$=createNode("TypeparameterList","",{$1});}
		| TypeParameter OMCommaTypeParameter							{$$=createNode("TypeparameterList","",{$1,$2});}
		;
ClassExtends:	EXTENDS Identifier										{Node* lexeme1 = createNode("ID",$2,{}); $$=createNode("ClassExtends",$1,{lexeme1});}		
		;	
ClassImplements: IMPLEMENTS InterfaceTypeList							{$$=createNode("ClassImplements",$1,{$2});}					
		;
InterfaceTypeList:   Identifier											{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("InterfaceTypeList","",{lexeme1});}
		|	 Identifier OMCommaInterfaceType							{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("InterfaceTypeList","",{lexeme1,$2});}
		;

ClassPermits:   PERMITS Identifier										{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("ClassPermits",$1,{lexeme1});}
		|	 PERMITS ExpressionName										{$$ = createNode("ClassPermits",$1,{$2});}
		|	 PERMITS Identifier OMCommaTypeName							{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("ClassPermits",$1,{lexeme1,$3});}
		|	 PERMITS ExpressionName OMCommaTypeName						{$$ = createNode("ClassPermits",$1,{$2,$3});}
		;

ClassBody:	 LCB RCB													{$$=createNode("ClassBody","{}",{});}
		| LCB OMClassBodyDeclaration RCB								{$$=createNode("ClassBody","{}",{$2});}
		;
ClassBodyDeclaration:	 ClassMemberDeclaration							{$$=$1;}
		| InstanceInitializer											{$$=$1;}
		| StaticInitializer												{$$=$1;}
		| ConstructorDeclaration										{$$=$1;}
		;
ClassMemberDeclaration:	 FieldDeclaration								{$$=$1;}
		| MethodDeclaration												{$$=$1;}
		| ClassDeclaration												{$$=$1;}
		| InterfaceDeclaration											{$$=$1;}
		| SEMICOLON														{$$ = createNode("EmptyClass",$1,{});}
		;
FieldDeclaration:	 UnannType VariableDeclaratorList SEMICOLON     	{$$=createNode("FieldDeclaration","",{$1,$2});}
		| OMClassModifier UnannType VariableDeclaratorList SEMICOLON	{$$=createNode("FieldDeclaration","",{$1,$2,$3});}
		;
VariableDeclaratorList:	 VariableDeclarator								{$$=createNode("VariableDeclaratorList","",{$1});}						
		| VariableDeclarator COMMA VariableDeclaratorList				{$$=createNode("VariableDeclaratorList",",",{$1,$3});}	
		;
VariableDeclarator:	 VariableDeclaratorId								{$$=createNode("VariableDeclarator","",{$1});}	
		| VariableDeclaratorId EqualVariableInitializer					{$$=createNode("VariableDeclarator","",{$1,$2});}	
		;
VariableDeclaratorId:  Identifier										{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("VariableDeclaratorId","",{lexeme1});}
		|	 Identifier OMPSB											{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("VariableDeclaratorId","",{lexeme1,$2});}
		;

VariableInitializer:	 Expression										{$$=$1;}
		| ArrayInitializer												{$$=$1;}
		;
UnannType:	 UnannPrimitiveType											{$$=$1;}
		| Identifier													{Node * lexeme=createNode("ID",$1,{}); $$ = createNode("UnannType","",{lexeme});}
		| UnannArrayType												{$$=$1;}
		;
UnannPrimitiveType:	 NumericType										{$$=$1;}
		| BOOLEAN														{$$ = createNode("UnannPrimitiveType",$1,{});}
		;
UnannArrayType:    UnannPrimitiveType OMPSB								{$$ = createNode("UnannArrayType","",{$1,$2});}
		|	 Identifier OMPSB											{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("UnannArrayType","",{lexeme1,$2});}
		;

MethodDeclaration:	 MethodHeader MethodBody							{$$=createNode("MethodDeclaration","",{$1,$2});}
		| OMClassModifier MethodHeader MethodBody						{$$=createNode("MethodDeclaration","",{$1,$2,$3});}
		;
MethodHeader:	 Result MethodDeclarator								{$$=createNode("MethodHeader","",{$1,$2});}
		| Result MethodDeclarator Throws								{$$=createNode("MethodHeader","",{$1,$2,$3});}
		| TypeParameters Result MethodDeclarator						{$$=createNode("MethodHeader","",{$1,$2,$3});}
		| TypeParameters Result MethodDeclarator Throws					{$$=createNode("MethodHeader","",{$1,$2,$3,$4});}
		| TypeParameters OMAnnotation Result MethodDeclarator			{$$=createNode("MethodHeader","",{$1,$2,$3,$4});}
		| TypeParameters OMAnnotation Result MethodDeclarator Throws	{$$=createNode("MethodHeader","",{$1,$2,$3,$4,$5});}
		;
Result:    UnannType	Identifier										{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("Result","",{$1,lexeme1});}
		|	 VOID Identifier											{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("Result",$1,{lexeme1});}
		;

MethodDeclarator: LRB RRB												{$$=createNode("MethodDeclarator","()",{});}
		| LRB RRB OMPSB													{$$=createNode("MethodDeclarator","()",{$3});}
		| LRB FormalParameterList RRB									{$$=createNode("MethodDeclarator","()",{$2});}
		| LRB FormalParameterList RRB OMPSB								{$$=createNode("MethodDeclarator","()",{$2,$4});}
		| LRB ReceiverParameterComma RRB								{$$=createNode("MethodDeclarator","()",{$2});}
		| LRB ReceiverParameterComma RRB OMPSB							{$$=createNode("MethodDeclarator","()",{$2,$4});}
		| LRB ReceiverParameterComma FormalParameterList RRB			{$$=createNode("MethodDeclarator","()",{$2,$3});}
		| LRB ReceiverParameterComma FormalParameterList RRB OMPSB		{$$=createNode("MethodDeclarator","()",{$2,$3,$5});}
		;
ReceiverParameter:	 UnannType THIS										{$$=createNode("ReceiverParameter","this",{$1});}
		| UnannType IdentifierDot THIS									{$$=createNode("ReceiverParameter","this",{$1,$2});}
		| OMAnnotation UnannType THIS									{$$=createNode("ReceiverParameter","this",{$1,$2});}
		| OMAnnotation UnannType IdentifierDot THIS						{$$=createNode("ReceiverParameter","this",{$1,$2,$3});}
		;
FormalParameterList: FormalParameter									{$$=createNode("FormalParameterList","",{$1});}		
		| FormalParameter OMCommaFormalParameter						{$$=createNode("FormalParameterList","",{$1,$2});}	
		;
FormalParameter: UnannType VariableDeclaratorId							{$$=createNode("FormalParameter","",{$1,$2});}	
		| OMClassModifier UnannType VariableDeclaratorId				{$$=createNode("FormalParameter","",{$1,$2,$3});}	
		| VariableArityParameter										{$$=$1;}
		;
VariableArityParameter:   UnannType THREEDOT Identifier					{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("VariableArityParameter",$2,{$1,lexeme1});}
		|	 UnannType OMAnnotation THREEDOT Identifier					{Node* lexeme1 = createNode("ID",$4,{}); $$ = createNode("VariableArityParameter",$3,{$1,$2,lexeme1});}
		|	 OMClassModifier UnannType THREEDOT Identifier				{Node* lexeme1 = createNode("ID",$4,{}); $$ = createNode("VariableArityParameter",$3,{$1,$2,lexeme1});}
		|	 OMClassModifier UnannType OMAnnotation THREEDOT Identifier	{Node* lexeme1 = createNode("ID",$5,{}); $$ = createNode("VariableArityParameter",$4,{$1,$2,$3,lexeme1});}
		;

Throws:	 THROWS ExceptionTypeList										{$$=createNode("Throws",$1,{$2});}	
		;
ExceptionTypeList:	 ExceptionType										{$$=createNode("ExceptionTypeList","",{$1});}	
		| ExceptionType OMCommaExceptionType							{$$=createNode("ExceptionTypeList","",{$1,$2});}	
		;
ExceptionType:   Identifier												{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("ExceptionType","",{lexeme1});}
		;

MethodBody:	 Block														{$$=$1;}
		| SEMICOLON														{$$ = createNode("EmptyMethodbody",$1,{});}
		;	
InstanceInitializer:	 Block											{$$=$1;}
		;
StaticInitializer:	 STATIC Block										{$$=createNode("StaticInitializer",$1,{$2});}	
		;	
ConstructorDeclaration:	 ConstructorDeclarator ConstructorBody			{$$=createNode("ConstructorDeclaration","",{$1,$2});}	
		| ConstructorDeclarator Throws ConstructorBody					{$$=createNode("ConstructorDeclaration","",{$1,$2,$3});}	
		| OMClassModifier ConstructorDeclarator ConstructorBody			{$$=createNode("ConstructorDeclaration","",{$1,$2,$3});}	
		| OMClassModifier ConstructorDeclarator Throws ConstructorBody	{$$=createNode("ConstructorDeclaration","",{$1,$2,$3,$4});}	
		;
ConstructorDeclarator:   Identifier LRB RRB														{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("ConstructorDeclarator","()",{lexeme1});}
		|	 Identifier LRB FormalParameterList RRB												{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("ConstructorDeclarator","()",{lexeme1,$3});}
		|	 Identifier LRB ReceiverParameterComma RRB											{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("ConstructorDeclarator","()",{lexeme1,$3});}
		|	 Identifier LRB ReceiverParameterComma FormalParameterList RRB						{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("ConstructorDeclarator","()",{lexeme1,$3,$4});}
		|	 TypeParameters Identifier LRB RRB													{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("ConstructorDeclarator","()",{$1,lexeme1});}
		|	 TypeParameters Identifier LRB FormalParameterList RRB								{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("ConstructorDeclarator","()",{$1,lexeme1,$4});}
		|	 TypeParameters Identifier LRB ReceiverParameterComma RRB							{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("ConstructorDeclarator","()",{$1,lexeme1,$4});}
		|	 TypeParameters Identifier LRB ReceiverParameterComma FormalParameterList RRB		{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("ConstructorDeclarator","()",{$1,lexeme1,$4,$5});}
		;

ConstructorBody: LCB RCB												{$$=createNode("ConstructorBody","{}",{});}
		| LCB BlockStatements RCB										{$$=createNode("ConstructorBody","{}",{$2});}
		| LCB ExplicitConstructorInvocation RCB							{$$=createNode("ConstructorBody","{}",{$2});}
		| LCB ExplicitConstructorInvocation BlockStatements RCB			{$$=createNode("ConstructorBody","{}",{$2,$3});}
		;
ExplicitConstructorInvocation:	 THIS LRB RRB SEMICOLON								{$$=createNode("ExplicitConstructorInvocation","this();",{});}
		| THIS LRB ArgumentList RRB SEMICOLON										{$$=createNode("ExplicitConstructorInvocation","this();",{$3});}
		| TypeArguments THIS LRB RRB SEMICOLON										{$$=createNode("ExplicitConstructorInvocation","this();",{$1});}
		| TypeArguments THIS LRB ArgumentList RRB SEMICOLON							{$$=createNode("ExplicitConstructorInvocation","this();",{$1,$4});}
		| SUPER LRB RRB SEMICOLON													{$$=createNode("ExplicitConstructorInvocation","super();",{});}
		| SUPER LRB ArgumentList RRB SEMICOLON										{$$=createNode("ExplicitConstructorInvocation","super();",{$3});}
		| TypeArguments SUPER LRB RRB SEMICOLON										{$$=createNode("ExplicitConstructorInvocation","super();",{$1});}
		| TypeArguments SUPER LRB ArgumentList RRB SEMICOLON						{$$=createNode("ExplicitConstructorInvocation","super();",{$1,$4});}
		| Identifier DOT SUPER LRB RRB SEMICOLON									{Node* lexeme = createNode("ID",$1,{}); $$=createNode("ExplicitConstructorInvocation",".super();",{lexeme});}
		| Identifier DOT SUPER LRB ArgumentList RRB SEMICOLON						{Node* lexeme = createNode("ID",$1,{}); $$=createNode("ExplicitConstructorInvocation",".super();",{lexeme,$5});}
		| Identifier DOT TypeArguments SUPER LRB RRB SEMICOLON						{Node* lexeme = createNode("ID",$1,{}); $$=createNode("ExplicitConstructorInvocation",".super();",{lexeme,$3});}
		| Identifier DOT TypeArguments SUPER LRB ArgumentList RRB SEMICOLON			{Node* lexeme= createNode("ID",$1,{}); $$=createNode("ExplicitConstructorInvocation",".super();",{lexeme,$3,$6});}
		| ExpressionName DOT SUPER LRB RRB SEMICOLON								{$$=createNode("ExplicitConstructorInvocation",".super();",{$1});}
		| ExpressionName DOT SUPER LRB ArgumentList RRB SEMICOLON					{$$=createNode("ExplicitConstructorInvocation",".super();",{$1,$5});}
		| ExpressionName DOT TypeArguments SUPER LRB RRB SEMICOLON					{$$=createNode("ExplicitConstructorInvocation",".super();",{$1,$3});}
		| ExpressionName DOT TypeArguments SUPER LRB ArgumentList RRB SEMICOLON		{$$=createNode("ExplicitConstructorInvocation",".super();",{$1,$3,$6});}
		| Primary DOT SUPER LRB RRB SEMICOLON										{$$=createNode("ExplicitConstructorInvocation",".super();",{$1});}
		| Primary DOT SUPER LRB ArgumentList RRB SEMICOLON							{$$=createNode("ExplicitConstructorInvocation",".super();",{$1,$5});}
		| Primary DOT TypeArguments SUPER LRB RRB SEMICOLON							{$$=createNode("ExplicitConstructorInvocation",".super();",{$1,$3});}
		| Primary DOT TypeArguments SUPER LRB ArgumentList RRB SEMICOLON			{$$=createNode("ExplicitConstructorInvocation",".super();",{$1,$3,$6});}
		;
EnumDeclaration:    ENUM Identifier EnumBody								{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("EnumDeclaration",$1,{lexeme1,$3});}
		|	 ENUM Identifier ClassImplements EnumBody						{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("EnumDeclaration",$1,{lexeme1,$3,$4});}
		|	 OMClassModifier ENUM Identifier EnumBody						{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("EnumDeclaration",$2,{$1,lexeme1,$4});}
		|	 OMClassModifier ENUM Identifier ClassImplements EnumBody		{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("EnumDeclaration",$2,{$1,lexeme1,$4,$5});}
		;

EnumBody:	 LCB RCB													{$$=createNode("EnumBody","{}",{});}
		| LCB EnumBodyDeclarations RCB									{$$=createNode("EnumBody","{}",{$2});}
		| LCB COMMA RCB													{$$=createNode("EnumBody","{,}",{});}
		| LCB COMMA EnumBodyDeclarations RCB							{$$=createNode("EnumBody","{,}",{$3});}
		| LCB EnumConstantList RCB										{$$=createNode("EnumBody","{}",{$2});}
		| LCB EnumConstantList EnumBodyDeclarations RCB					{$$=createNode("EnumBody","{}",{$2,$3});}
		;
EnumConstantList:	 EnumConstant										{$$=$1;}
		| OMCommaEnumConstant											{$$=$1;}
		;
PRB:	LRB RRB															{$$=createNode("PRB","()",{});}
		;
PRBArgumentList: LRB ArgumentList RRB									{$$=createNode("PRBArgumentList","()",{$2});}
		;
EnumConstant:  Identifier													{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("EnumConstant","",{lexeme1});}
		|	 Identifier PRB													{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("EnumConstant","",{lexeme1});}
		|	 Identifier PRBArgumentList										{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("EnumConstant","",{lexeme1,$2});}
		|	 Identifier ClassBody											{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("EnumConstant","",{lexeme1,$2});}
		|	 Identifier PRB ClassBody										{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("EnumConstant","",{lexeme1,$3});}
		|	 Identifier PRBArgumentList ClassBody							{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("EnumConstant","",{lexeme1,$2,$3});}
		|	 OMEnumConstantModifier Identifier								{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("EnumConstant","",{$1,lexeme1});}
		|	 OMEnumConstantModifier Identifier PRB							{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("EnumConstant","",{$1,lexeme1});}
		|	 OMEnumConstantModifier Identifier PRBArgumentList				{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("EnumConstant","",{$1,lexeme1,$3});}
		|	 OMEnumConstantModifier Identifier ClassBody					{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("EnumConstant","",{$1,lexeme1,$3});}
		|	 OMEnumConstantModifier Identifier PRB ClassBody				{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("EnumConstant","",{$1,lexeme1,$4});}
		|	 OMEnumConstantModifier Identifier PRBArgumentList ClassBody	{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("EnumConstant","",{$1,lexeme1,$3,$4});}
		;

EnumConstantModifier: Annotation											{$$=$1;}
		;
EnumBodyDeclarations: SEMICOLON												{$$ = createNode("EnumBodyDeclarations",$1,{});}
		| SEMICOLON OMClassBodyDeclaration									{$$ = createNode("EnumBodyDeclarations",$1,{$2});}
		;
RecordDeclaration:    RECORD Identifier RecordHeader RecordBody											{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("RecordDeclaration",$1,{lexeme1,$3,$4});}
		|	 RECORD Identifier RecordHeader ClassImplements RecordBody									{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("RecordDeclaration",$1,{lexeme1,$3,$4,$5});}
		|	 RECORD Identifier TypeParameters RecordHeader RecordBody									{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("RecordDeclaration",$1,{lexeme1,$3,$4,$5});}
		|	 RECORD Identifier TypeParameters RecordHeader ClassImplements RecordBody					{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("RecordDeclaration",$1,{lexeme1,$3,$4,$5,$6});}
		|	 OMClassModifier RECORD Identifier RecordHeader RecordBody									{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("RecordDeclaration",$2,{$1,lexeme1,$4,$5});}
		|	 OMClassModifier RECORD Identifier RecordHeader ClassImplements RecordBody					{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("RecordDeclaration",$2,{$1,lexeme1,$4,$5,$6});}
		|	 OMClassModifier RECORD Identifier TypeParameters RecordHeader RecordBody					{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("RecordDeclaration",$2,{$1,lexeme1,$4,$5,$6});}
		|	 OMClassModifier RECORD Identifier TypeParameters RecordHeader ClassImplements RecordBody	{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("RecordDeclaration",$2,{$1,lexeme1,$4,$5,$6,$7});}
		;

RecordHeader:	 LRB RRB													{$$=createNode("RecordHeader","()",{});}
		| LRB RecordComponentList RRB										{$$=createNode("RecordHeader","()",{$2});}
		;
RecordComponentList:  RecordComponent										{$$=createNode("RecordComponentList","",{$1});}
		| RecordComponent OMCommaRecordComponent							{$$=createNode("RecordComponentList","",{$1,$2});}
		;
RecordComponent:    UnannType Identifier									{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("RecordComponent","",{$1,lexeme1});}
		|	 OMRecordComponentModifier UnannType Identifier					{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("RecordComponent","",{$1,$2,lexeme1});}
		|	 VariableArityRecordComponent									{$$=$1;}
		;

VariableArityRecordComponent:    UnannType THREEDOT Identifier						{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("VariableArityRecordComponent",$2,{$1,lexeme1});}
		|	 UnannType OMAnnotation THREEDOT Identifier								{Node* lexeme1 = createNode("ID",$4,{}); $$ = createNode("VariableArityRecordComponent",$3,{$1,$2,lexeme1});}
		|	 OMRecordComponentModifier UnannType THREEDOT Identifier				{Node* lexeme1 = createNode("ID",$4,{}); $$ = createNode("VariableArityRecordComponent",$3,{$1,$2,lexeme1});}
		|	 OMRecordComponentModifier UnannType OMAnnotation THREEDOT Identifier	{Node* lexeme1 = createNode("ID",$5,{}); $$ = createNode("VariableArityRecordComponent",$4,{$1,$2,$3,lexeme1});}
		;

RecordComponentModifier:	 Annotation									{$$=$1;}
		;
RecordBody:	 LCB RCB													{$$=createNode("RecordBody","{}",{});}
		| LCB OMRecordBodyDeclaration RCB								{$$=createNode("RecordBody","{}",{$2});}
		;
RecordBodyDeclaration:	 ClassBodyDeclaration							{$$=$1;}
		| CompactConstructorDeclaration									{$$=$1;}
		;
CompactConstructorDeclaration:    Identifier ConstructorBody			{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("CompactConstructorDeclaration","",{lexeme1,$2});}
		|	 OMClassModifier Identifier ConstructorBody					{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("CompactConstructorDeclaration","",{$1,lexeme1,$3});}
		;

InterfaceDeclaration:	 NormalInterfaceDeclaration						{$$=$1;}
		| AnnotationInterfaceDeclaration								{$$=$1;}
		;
NormalInterfaceDeclaration:   INTERFACE Identifier InterfaceBody														{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("NormalInterfaceDeclaration",$1,{lexeme1,$3});}
		|	 INTERFACE Identifier InterfacePermits InterfaceBody														{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("NormalInterfaceDeclaration",$1,{lexeme1,$3,$4});}
		|	 INTERFACE Identifier InterfaceExtends InterfaceBody														{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("NormalInterfaceDeclaration",$1,{lexeme1,$3,$4});}
		|	 INTERFACE Identifier InterfaceExtends InterfacePermits InterfaceBody										{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("NormalInterfaceDeclaration",$1,{lexeme1,$3,$4,$5});}
		|	 INTERFACE Identifier TypeParameters InterfaceBody															{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("NormalInterfaceDeclaration",$1,{lexeme1,$3,$4});}
		|	 INTERFACE Identifier TypeParameters InterfacePermits InterfaceBody											{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("NormalInterfaceDeclaration",$1,{lexeme1,$3,$4,$5});}
		|	 INTERFACE Identifier TypeParameters InterfaceExtends InterfaceBody											{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("NormalInterfaceDeclaration",$1,{lexeme1,$3,$4,$5});}
		|	 INTERFACE Identifier TypeParameters InterfaceExtends InterfacePermits InterfaceBody						{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("NormalInterfaceDeclaration",$1,{lexeme1,$3,$4,$5,$6});}
		|	 OMClassModifier INTERFACE Identifier InterfaceBody															{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("NormalInterfaceDeclaration",$2,{$1,lexeme1,$4});}
		|	 OMClassModifier INTERFACE Identifier InterfacePermits InterfaceBody										{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("NormalInterfaceDeclaration",$2,{$1,lexeme1,$4,$5});}
		|	 OMClassModifier INTERFACE Identifier InterfaceExtends InterfaceBody										{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("NormalInterfaceDeclaration",$2,{$1,lexeme1,$4,$5});}
		|	 OMClassModifier INTERFACE Identifier InterfaceExtends InterfacePermits InterfaceBody						{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("NormalInterfaceDeclaration",$2,{$1,lexeme1,$4,$5,$6});}
		|	 OMClassModifier INTERFACE Identifier TypeParameters InterfaceBody											{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("NormalInterfaceDeclaration",$2,{$1,lexeme1,$4,$5});}
		|	 OMClassModifier INTERFACE Identifier TypeParameters InterfacePermits InterfaceBody							{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("NormalInterfaceDeclaration",$2,{$1,lexeme1,$4,$5,$6});}
		|	 OMClassModifier INTERFACE Identifier TypeParameters InterfaceExtends InterfaceBody							{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("NormalInterfaceDeclaration",$2,{$1,lexeme1,$4,$5,$6});}
		|	 OMClassModifier INTERFACE Identifier TypeParameters InterfaceExtends InterfacePermits InterfaceBody		{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("NormalInterfaceDeclaration",$2,{$1,lexeme1,$4,$5,$6,$7});}
		;

InterfaceModifier:	 Modifieropt										{$$=$1;}
		;
InterfaceExtends:	 EXTENDS InterfaceTypeList							{$$=createNode("InterfaceExtends",$1,{$2});}
		;
InterfacePermits:	 PERMITS ExpressionName								{$$=createNode("InterfacePermits",$1,{$2});}
		| PERMITS ExpressionName OMCommaTypeName						{$$=createNode("InterfacePermits",$1,{$2,$3});}
		;
InterfaceBody:	 LCB RCB												{$$=createNode("InterfaceBody","{}",{});}
		| LCB OMInterfaceMemberDeclaration RCB							{$$=createNode("InterfaceBody","{}",{$2});}
		;
InterfaceMemberDeclaration:	 ConstantDeclaration						{$$=$1;}
		| InterfaceMethodDeclaration									{$$=$1;}
		| ClassDeclaration												{$$=$1;}
		| InterfaceDeclaration											{$$=$1;}
		| SEMICOLON														{$$ = createNode("InterfaceMemberDeclaration",$1,{});}
		;
ConstantDeclaration:	 UnannType VariableDeclaratorList SEMICOLON		{$$=createNode("ConstantDeclaration","",{$1,$2});}
		| OMClassModifier UnannType VariableDeclaratorList SEMICOLON	{$$=createNode("ConstantDeclaration","",{$1,$2,$3});}
		;
InterfaceMethodDeclaration:	 MethodHeader MethodBody					{$$=createNode("InterfaceMethodDeclaration","",{$1,$2});}
		| OMClassModifier MethodHeader MethodBody						{$$=createNode("InterfaceMethodDeclaration","",{$1,$2,$3});}
		;
AnnotationInterfaceDeclaration:	 AT INTERFACE Identifier AnnotationInterfaceBody	{Node* lexeme1 = createNode("ID",$3,{}); $$=createNode("AnnotationInterfaceDeclaration","@interface",{lexeme1,$4});}
		| OMClassModifier AT INTERFACE Identifier AnnotationInterfaceBody			{Node* lexeme1 = createNode("ID",$4,{});$$=createNode("AnnotationInterfaceDeclaration","@interface",{$1,lexeme1,$5});}
		;
AnnotationInterfaceBody:	 LCB RCB									{$$=createNode("AnnotationInterfaceBody","{}",{});}
		| LCB OMAnnotationInterfaceMemberDeclaration RCB				{$$=createNode("AnnotationInterfaceBody","{}",{$2});}
		;
AnnotationInterfaceMemberDeclaration:	 AnnotationInterfaceElementDeclaration		{$$=$1;}
		| ConstantDeclaration														{$$=$1;}
		| ClassDeclaration															{$$=$1;}
		| InterfaceDeclaration														{$$=$1;}
		| SEMICOLON																	{$$ = createNode("AnnotationInterfaceMemberDeclaration",$1,{});}
		;
AnnotationInterfaceElementDeclaration:   UnannType Identifier LRB RRB SEMICOLON		{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("AnnotationInterfaceElementDeclaration","()",{$1,lexeme1});}
		|	 UnannType Identifier LRB RRB DefaultValue SEMICOLON					{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("AnnotationInterfaceElementDeclaration","()",{$1,lexeme1,$5});}
		|	 UnannType Identifier LRB RRB OMPSB SEMICOLON							{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("AnnotationInterfaceElementDeclaration","()",{$1,lexeme1,$5});}
		|	 UnannType Identifier LRB RRB OMPSB DefaultValue SEMICOLON				{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("AnnotationInterfaceElementDeclaration","()",{$1,lexeme1,$5,$6});}
		|	 OMClassModifier UnannType Identifier LRB RRB SEMICOLON					{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("AnnotationInterfaceElementDeclaration","()",{$1,$2,lexeme1});}
		|	 OMClassModifier UnannType Identifier LRB RRB DefaultValue SEMICOLON	{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("AnnotationInterfaceElementDeclaration","()",{$1,$2,lexeme1,$6});}
		|	 OMClassModifier UnannType Identifier LRB RRB OMPSB SEMICOLON			{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("AnnotationInterfaceElementDeclaration","()",{$1,$2,lexeme1,$6});}
		|	 OMClassModifier UnannType Identifier LRB RRB OMPSB DefaultValue SEMICOLON		{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("AnnotationInterfaceElementDeclaration","()",{$1,$2,lexeme1,$6,$7});}
		;

DefaultValue:	 DEFAULT ElementValue												{$$=createNode("DefaultValue",$1,{$2});}
		;
Annotation:	 NormalAnnotation														{$$=$1;}
		| MarkerAnnotation															{$$=$1;}
		| SingleElementAnnotation													{$$=$1;}
		;
NormalAnnotation:    AT Identifier LRB RRB								{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("NormalAnnotation","@()",{lexeme1});}
		|	 AT ExpressionName LRB RRB									{$$ = createNode("NormalAnnotation","@()",{$2});}
		|	 AT Identifier LRB ElementValuePairList RRB					{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("NormalAnnotation","@()",{lexeme1,$4});}
		|	 AT ExpressionName LRB ElementValuePairList RRB				{$$ = createNode("NormalAnnotation","@()",{$2,$4});}
		;

ElementValuePairList:	 ElementValuePair								{$$=createNode("ElementValuePairList","",{$1});}
		| ElementValuePair OMCommaElementValuePair						{$$=createNode("ElementValuePairList","",{$1,$2});}
		;
ElementValuePair:  Identifier EQUAL ElementValue						{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("ElementValuePair",$2,{lexeme1,$3});}
		;

ElementValue:	 ConditionalExpression										{$$=$1;}
		| ElementValueArrayInitializer										{$$=$1;}
		| Annotation														{$$=$1;}
		;
ElementValueArrayInitializer:	 LCB RCB									{$$=createNode("ElementValueArrayInitializer","{}",{});}		
		| LCB COMMA RCB														{$$=createNode("ElementValueArrayInitializer","{,}",{});}
		| LCB ElementValueList RCB											{$$=createNode("ElementValueArrayInitializer","{}",{$2});}
		;
ElementValueList:	 ElementValue											{$$=$1;}
		| OMCommaElementValue												{$$=$1;}
		;
MarkerAnnotation:    AT Identifier											{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("MarkerAnnotation",$1,{lexeme1});}
		|	 AT ExpressionName												{$$ = createNode("MarkerAnnotation",$1,{$2});}
		;

SingleElementAnnotation:   AT Identifier LRB ElementValue RRB				{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("SingleElementAnnotation","@()",{lexeme1,$4});}
		|	 AT ExpressionName LRB ElementValue RRB							{$$ = createNode("SingleElementAnnotation","@()",{$2,$4});}
		;

ArrayInitializer:	 LCB RCB												{$$=createNode("ArrayInitializer","{}",{});}
		| LCB COMMA RCB														{$$=createNode("ArrayInitializer","{,}",{});}
		| LCB VariableInitializerList RCB									{$$=createNode("ArrayInitializer","{}",{$2});}
		;
VariableInitializerList:	 VariableInitializer							{$$=createNode("VariableInitializerList","",{$1});}
		| VariableInitializer OMCommaVariableInitializer					{$$=createNode("VariableInitializerList","",{$1,$2});}
		;
Block:	 LCB RCB															{$$=createNode("Block","{}",{});}
		| LCB BlockStatements RCB											{$$=createNode("Block","{}",{$2});}
		;
BlockStatements:	 BlockStatement											{$$=createNode("BlockStatements","",{$1});}
		| BlockStatement OMBlockStatement									{$$=createNode("BlockStatements","",{$1,$2});}
		;
BlockStatement:	 LocalClassOrInterfaceDeclaration							{$$=$1;}
		| LocalVariableDeclarationStatement									{$$=$1;}
		| Statement															{$$ = createNode("BlockStatement","",{$1});}
		;
LocalClassOrInterfaceDeclaration:	 ClassDeclaration						{$$=$1;}
		| NormalInterfaceDeclaration										{$$=$1;}
		;
LocalVariableDeclarationStatement:	 LocalVariableDeclaration SEMICOLON		{$$ = createNode("LocalVariableDeclarationStatement","",{$1});}
		;
LocalVariableDeclaration:	 LocalVariableType VariableDeclaratorList		{$$ = createNode("LocalVariableDeclaration","",{$1,$2});}
		| OMClassModifier LocalVariableType VariableDeclaratorList			{$$ = createNode("LocalVariableDeclaration","",{$1,$2,$3});}
		;
LocalVariableType:	 UnannType												{$$=$1;}
		| VAR																{$$ = createNode("LocalVariableType",$1,{});}
		;
Statement:	 StatementWithoutTrailingSubstatement							{$$=$1;}
		| LabeledStatement													{$$=$1;}
		| IfThenStatement													{$$=$1;}
		| IfThenElseStatement												{$$=$1;}
		| WhileStatement													{$$=$1;}
		| ForStatement														{$$=$1;}
		;
StatementNoShortIf:	 StatementWithoutTrailingSubstatement					{$$=$1;}
		| LabeledStatementNoShortIf											{$$=$1;}
		| IfThenElseStatementNoShortIf										{$$=$1;}
		| WhileStatementNoShortIf											{$$=$1;}
		| ForStatementNoShortIf												{$$=$1;}
		;
StatementWithoutTrailingSubstatement:	 Block								{$$=$1;}
		| EmptyStatement													{$$=$1;}
		| ExpressionStatement												{$$=$1;}
		| AssertStatement													{$$=$1;}
		| SwitchStatement													{$$=$1;}
		| DoStatement														{$$=$1;}
		| BreakStatement													{$$=$1;}
		| ContinueStatement													{$$=$1;}
		| ReturnStatement													{$$=$1;}
		| SynchronizedStatement												{$$=$1;}
		| ThrowStatement													{$$=$1;}
		| TryStatement														{$$=$1;}
		| YieldStatement													{$$=$1;}
		;
EmptyStatement:	 SEMICOLON													{$$ = createNode("EmptyStatement",$1,{});}
		;
LabeledStatement:   Identifier COLON Statement								{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("LabeledStatement",$2,{lexeme1,$3});}
		;
LabeledStatementNoShortIf:   Identifier COLON StatementNoShortIf			{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("LabeledStatementNoShortIf",$2,{lexeme1,$3});}
		;

ExpressionStatement:  StatementExpression SEMICOLON							{$$ = createNode("ExpressionStatement",$2,{$1});}
		;
StatementExpression:	 Assignment											{$$=$1;}
		| PreIncrementExpression											{$$=$1;}
		| PreDecrementExpression											{$$=$1;}
		| PostIncrementExpression											{$$=$1;}
		| PostDecrementExpression											{$$=$1;}
		| MethodInvocation													{$$=$1;}
		| ClassInstanceCreationExpression									{$$=$1;}
		;
IfThenStatement: IF LRB Expression RRB Statement							{$5->expressionLabel="true";$3->expressionLabel="condition";$$=createNode("IFTHEN","if()",{$3,$5});}
		;
IfThenElseStatement: IF LRB Expression RRB StatementNoShortIf ELSE Statement{$5->expressionLabel="true";$7->expressionLabel="false";$3->expressionLabel="condition";$$=createNode("IFTHENELSE","if()else",{$3,$5,$7});}
		;
IfThenElseStatementNoShortIf:	 IF LRB Expression RRB StatementNoShortIf ELSE StatementNoShortIf	{$5->expressionLabel="true";$7->expressionLabel="false";$3->expressionLabel="condition";$$=createNode("IFTHENELSE","if()else",{$3,$5,$7});}
		;
AssertStatement:	 ASSERT Expression SEMICOLON								 	{$$=createNode("ASSERT",$1,{$2});}
		| ASSERT Expression COLON Expression SEMICOLON								{$4->expressionLabel="MESSAGE";$$=createNode("ASSERT","assert :",{$2,$4});}
		;
SwitchStatement:	 SWITCH LRB Expression RRB SwitchBlock							{$$=createNode("SWITCH",$1,{$3,$5});}
		;
SwitchBlock:	 LCB SwitchRule RCB													{$$=createNode("SwitchBlock","{}",{$2});}
		| LCB SwitchRule OMSwitchRule RCB											{$$=createNode("SwitchBlock","{}",{$2,$3});}
		| LCB RCB																	{$$=createNode("SwitchBlock","{}",{});}										
		| LCB OMSwitchLabelColon RCB												{$$=createNode("SwitchBlock","{}",{$2});}
		| LCB OMSwitchBlockStatementGroup RCB										{$$=createNode("SwitchBlock","{}",{$2});}
		| LCB OMSwitchBlockStatementGroup OMSwitchLabelColon RCB					{$$=createNode("SwitchBlock","{}",{$2,$3});}
		;
SwitchRule:	 SwitchLabel IMPLIES Expression SEMICOLON								{$$=createNode("SwitchRule",$2,{$1,$3});}
		| SwitchLabel IMPLIES Block													{$$=createNode("SwitchRule",$2,{$1,$3});}
		| SwitchLabel IMPLIES ThrowStatement										{$$=createNode("SwitchRule",$2,{$1,$3});}
		;
SwitchBlockStatementGroup:	 SwitchLabel COLON BlockStatements						{$$=createNode("SwitSwitchBlockStatementGroupchRule",$2,{$1,$3});}
		| SwitchLabel COLON OMSwitchLabelColon BlockStatements						{$$=createNode("SwitcSwitchBlockStatementGrouphRule",$2,{$1,$3,$4});}
		;
SwitchLabel:	 CASE CaseConstant													{$$=createNode("SwitchLabel",$1,{$2});}
		| CASE CaseConstant OMCommaCaseConstant										{$$=createNode("SwitchLabel",$1,{$2,$3});}
		| DEFAULT																	{$$=createNode("SwitchLabel",$1,{});}
		;
CaseConstant:	 ConditionalExpression												{$$=$1;}
		;		
WhileStatement:	 WHILE LRB Expression RRB Statement									{$$=createNode("WhileStatement",$1,{$3,$5});}		
		;
WhileStatementNoShortIf:	 WHILE LRB Expression RRB StatementNoShortIf			{$$=createNode("WhileStatementNoShortIf",$1,{$3,$5});}	
		;
DoStatement:	 DO Statement WHILE LRB Expression RRB SEMICOLON					{$$=createNode("DoStatement","do while",{$2,$5});}	
		;
ForStatement:	 BasicForStatement													{$$=$1;}
		| EnhancedForStatement														{$$=$1;}
		;
ForStatementNoShortIf:	 BasicForStatementNoShortIf									{$$=$1;}
		| EnhancedForStatementNoShortIf												{$$=$1;}
		;
BasicForStatement:	 FOR LRB SEMICOLON SEMICOLON RRB Statement						{$$=createNode("BasicForStatement",$1,{$6});}	
		| FOR LRB SEMICOLON SEMICOLON ForUpdate RRB Statement						{$$=createNode("BasicForStatement",$1,{$5,$7});}	
		| FOR LRB SEMICOLON Expression SEMICOLON RRB Statement						{$$=createNode("BasicForStatement",$1,{$4,$7});}	
		| FOR LRB SEMICOLON Expression SEMICOLON ForUpdate RRB Statement			{$$=createNode("BasicForStatement",$1,{$4,$6,$8});}	
		| FOR LRB ForInit SEMICOLON SEMICOLON RRB Statement							{$$=createNode("BasicForStatement",$1,{$3,$7});}	
		| FOR LRB ForInit SEMICOLON SEMICOLON ForUpdate RRB Statement				{$$=createNode("BasicForStatement",$1,{$3,$6,$8});}	
		| FOR LRB ForInit SEMICOLON Expression SEMICOLON RRB Statement				{$$=createNode("BasicForStatement",$1,{$3,$5,$8});}	
		| FOR LRB ForInit SEMICOLON Expression SEMICOLON ForUpdate RRB Statement	{$$=createNode("BasicForStatement",$1,{$3,$5,$7,$9});}	
		;
BasicForStatementNoShortIf:	 FOR LRB SEMICOLON SEMICOLON RRB StatementNoShortIf				{$$=createNode("BasicForStatementNoShortIf",$1,{$6});}
		| FOR LRB SEMICOLON SEMICOLON ForUpdate RRB StatementNoShortIf						{$$=createNode("BasicForStatementNoShortIf",$1,{$5,$7});}	
		| FOR LRB SEMICOLON Expression SEMICOLON RRB StatementNoShortIf						{$$=createNode("BasicForStatementNoShortIf",$1,{$4,$7});}
		| FOR LRB SEMICOLON Expression SEMICOLON ForUpdate RRB StatementNoShortIf			{$$=createNode("BasicForStatementNoShortIf",$1,{$4,$6,$8});}	
		| FOR LRB ForInit SEMICOLON SEMICOLON RRB StatementNoShortIf						{$$=createNode("BasicForStatementNoShortIf",$1,{$3,$7});}	
		| FOR LRB ForInit SEMICOLON SEMICOLON ForUpdate RRB StatementNoShortIf				{$$=createNode("BasicForStatementNoShortIf",$1,{$3,$6,$8});}	
		| FOR LRB ForInit SEMICOLON Expression SEMICOLON RRB StatementNoShortIf				{$$=createNode("BasicForStatementNoShortIf",$1,{$3,$5,$8});}	
		| FOR LRB ForInit SEMICOLON Expression SEMICOLON ForUpdate RRB StatementNoShortIf	{$$=createNode("BasicForStatementNoShortIf",$1,{$3,$5,$7,$9});}
		;
ForInit:	 StatementExpressionList													{$$=$1;}
		| LocalVariableDeclaration														{$$=$1;}
		;	
ForUpdate:	 StatementExpressionList													{$$=$1;}
		;
StatementExpressionList:	 StatementExpression										{$$=createNode("StatementExpressionList","",{$1});}
		| StatementExpression OMCommaStatementExpression								{$$=createNode("StatementExpressionList","",{$1,$2});}
		;
EnhancedForStatement:	 FOR LRB LocalVariableDeclaration COLON Expression RRB Statement						{$$=createNode("EnhancedForStatement","for :",{$3,$5,$7});}
		;
EnhancedForStatementNoShortIf:	 FOR LRB LocalVariableDeclaration COLON Expression RRB StatementNoShortIf		{$$=createNode("EnhancedForStatementNoShortIf","for :",{$3,$5,$7});}
		;
BreakStatement:   		 BREAK SEMICOLON																		{$$ = createNode("BreakStatement",$1,{});}
		|	 BREAK Identifier SEMICOLON																			{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("BreakStatement",$1,{lexeme1});}
		;

YieldStatement:	 YIELD Expression SEMICOLON																		{$$=createNode("YieldStatement",$1,{$2});}			
		;
ContinueStatement:   CONTINUE SEMICOLON																			{$$ = createNode("ContinueStatement",$1,{});}
		|	 CONTINUE Identifier SEMICOLON																		{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("ContinueStatement",$1,{lexeme1});}
		;

ReturnStatement:	 RETURN SEMICOLON													{$$=createNode("ReturnStatement",$1,{});}
		| RETURN Expression SEMICOLON													{$$=createNode("ReturnStatement",$1,{$2});}
		;	
ThrowStatement:	 THROW Expression SEMICOLON												{$$=createNode("ThrowStatement",$1,{$2});}
		;
SynchronizedStatement:	 SYNCHRONIZED LRB Expression RRB Block							{$$=createNode("SynchronizedStatement",$1,{$3,$5});}
		;
TryStatement:	 TRY Block Catches														{$$=createNode("TryStatement",$1,{$2,$3});}
		| TRY Block Finally																{$$=createNode("TryStatement",$1,{$2,$3});}
		| TRY Block Catches Finally														{$$=createNode("TryStatement",$1,{$2,$3,$4});}
		| TryWithResourcesStatement														{$$=$1;}
		;
Catches:	 CatchClause																{$$=createNode("Catches","",{$1});}
		| CatchClause OMCatchClause														{$$=createNode("Catches","",{$1,$2});}
		;
CatchClause:	 CATCH LRB CatchFormalParameter RRB Block								{$$=createNode("CatchClause",$1,{$3,$5});}
		;
CatchFormalParameter:	 CatchType VariableDeclaratorId									{$$=createNode("CatchFormalParameter","",{$1,$2});}
		| OMClassModifier CatchType VariableDeclaratorId								{$$=createNode("CatchFormalParameter","",{$1,$2,$3});}
		;
CatchType:   		 Identifier															{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("CatchType","",{lexeme1});}
		|	 Identifier OMOrClassType													{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("CatchType","",{lexeme1,$2});}
		;

Finally:	 FINALLY Block																{$$=createNode("Finally",$1,{$2});}
		;	
TryWithResourcesStatement:	 TRY ResourceSpecification Block							{$$=createNode("TryWithResourcesStatement",$1,{$2,$3});}
		| TRY ResourceSpecification Block Finally										{$$=createNode("TryWithResourcesStatement",$1,{$2,$3,$4});}	
		| TRY ResourceSpecification Block Catches										{$$=createNode("TryWithResourcesStatement",$1,{$2,$3,$4});}
		| TRY ResourceSpecification Block Catches Finally								{$$=createNode("TryWithResourcesStatement",$1,{$2,$3,$4,$5});}
		;
ResourceSpecification:	 LRB ResourceList RRB											{$$=createNode("ResourceSpecification","()",{$2});}
		;
ResourceList:	 Resource																{$$=$1;}
		| OMSemicolonResource															{$$=$1;}
		;
Resource:	 LocalVariableDeclaration													{$$=$1;}
		| VariableAccess																{$$=$1;}
		;
Primary:	 PrimaryNoNewArray															{$$=$1;}
		| ArrayCreationExpression														{$$=$1;}
		;
PrimaryNoNewArray:	 Literal															{$$=$1;}
		| ClassLiteral																	{$$=$1;}
		| THIS																			{$$=createNode("PrimaryNoNewArray",$1,{});}
		| Identifier DOT THIS															{Node*lexeme=createNode("ID",$1,{});$$=createNode("PrimaryNoNewArray",". this",{lexeme});}
		| ExpressionName DOT THIS														{$$=createNode("PrimaryNoNewArray",". this",{$1});}
		| LRB Expression RRB															{$$=createNode("PrimaryNoNewArray","()",{$2});}
		| ClassInstanceCreationExpression												{$$=$1;}
		| FieldAccess																	{$$=$1;}
		| ArrayAccess																	{$$=$1;}
		| MethodInvocation																{$$=$1;}
		| MethodReference																{$$=$1;}
		;
ClassLiteral:	 Identifier DOT CLASS														{Node*lexeme=createNode("ID",$1,{});$$=createNode("ClassLiteral",".class",{lexeme});}
		| ExpressionName DOT CLASS															{$$=createNode("ClassLiteral",".class",{$1});}
		| Identifier OMPSB DOT CLASS														{Node* lexeme1 = createNode("ID",$1,{});$$=createNode("ClassLiteral",".class",{lexeme1,$2});}
		| ExpressionName OMPSB DOT CLASS													{$$=createNode("ClassLiteral",".class",{$1,$2});}
		| UnannPrimitiveType DOT CLASS														{$$=createNode("ClassLiteral",".class",{$1});}
		| VOID DOT CLASS																	{$$=createNode("ClassLiteral","void . class",{});}
		;
ClassInstanceCreationExpression:	 UnqualifiedClassInstanceCreationExpression				{$$=$1;}
		| Identifier DOT UnqualifiedClassInstanceCreationExpression							{Node*lexeme=createNode("ID",$1,{});$$=createNode("ClassInstanceCreationExpression",".",{lexeme,$3});}
		| ExpressionName DOT UnqualifiedClassInstanceCreationExpression						{$$=createNode("ClassInstanceCreationExpression",".",{$1,$3});}
		| Primary DOT UnqualifiedClassInstanceCreationExpression							{$$=createNode("ClassInstanceCreationExpression",".",{$1,$3});}
		;
UnqualifiedClassInstanceCreationExpression:	 NEW ClassOrInterfaceTypeToInstantiate LRB RRB 		{$$=createNode("UnqualifiedClassInstanceCreationExpression",$1,{$2});}
		| NEW ClassOrInterfaceTypeToInstantiate LRB RRB ClassBody								{$$=createNode("UnqualifiedClassInstanceCreationExpression",$1,{$2,$5});}
		| NEW ClassOrInterfaceTypeToInstantiate LRB ArgumentList RRB							{$$=createNode("UnqualifiedClassInstanceCreationExpression",$1,{$2,$4});}
		| NEW ClassOrInterfaceTypeToInstantiate LRB ArgumentList RRB ClassBody					{$$=createNode("UnqualifiedClassInstanceCreationExpression",$1,{$2,$4,$6});}
		| NEW TypeArguments ClassOrInterfaceTypeToInstantiate LRB RRB							{$$=createNode("UnqualifiedClassInstanceCreationExpression",$1,{$2,$3});}
		| NEW TypeArguments ClassOrInterfaceTypeToInstantiate LRB RRB ClassBody					{$$=createNode("UnqualifiedClassInstanceCreationExpression",$1,{$2,$3,$6});}
		| NEW TypeArguments ClassOrInterfaceTypeToInstantiate LRB ArgumentList RRB				{$$=createNode("UnqualifiedClassInstanceCreationExpression",$1,{$2,$3,$5});}
		| NEW TypeArguments ClassOrInterfaceTypeToInstantiate LRB ArgumentList RRB ClassBody	{$$=createNode("UnqualifiedClassInstanceCreationExpression",$1,{$2,$3,$5,$7});}
		;
ClassOrInterfaceTypeToInstantiate:   Identifier											{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("ClassOrInterfaceTypeToInstantiate","",{lexeme1});}
		|	 Identifier TypeArgumentsOrDiamond											{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("ClassOrInterfaceTypeToInstantiate","",{lexeme1,$2});}
		|	Identifier OMDotOMAnnotationIdentifier 										{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("ClassOrInterfaceTypeToInstantiate","",{lexeme1,$2});}
		|	Identifier OMDotOMAnnotationIdentifier TypeArgumentsOrDiamond				{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("ClassOrInterfaceTypeToInstantiate","",{lexeme1,$2,$3});}
		|	Identifier OMDotIdentifier													{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("ClassOrInterfaceTypeToInstantiate","",{lexeme1,$2});}
		|	Identifier OMDotIdentifier TypeArgumentsOrDiamond							{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("ClassOrInterfaceTypeToInstantiate","",{lexeme1,$2,$3});}
		|	OMAnnotation Identifier														{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("ClassOrInterfaceTypeToInstantiate","",{$1,lexeme1});}
		|	OMAnnotation Identifier TypeArgumentsOrDiamond								{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("ClassOrInterfaceTypeToInstantiate","",{$1,lexeme1,$3});}
		|	OMAnnotation Identifier OMDotOMAnnotationIdentifier 						{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("ClassOrInterfaceTypeToInstantiate","",{$1,lexeme1,$3});}
		|	OMAnnotation Identifier OMDotOMAnnotationIdentifier TypeArgumentsOrDiamond	{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("ClassOrInterfaceTypeToInstantiate","",{$1,lexeme1,$3,$4});}
		|	OMAnnotation Identifier OMDotIdentifier										{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("ClassOrInterfaceTypeToInstantiate","",{$1,lexeme1,$3});}
		|	OMAnnotation Identifier OMDotIdentifier TypeArgumentsOrDiamond				{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("ClassOrInterfaceTypeToInstantiate","",{$1,lexeme1,$3,$4});}
		;

TypeArgumentsOrDiamond: TypeArguments													{$$=$1;}
		| LT GT																			{$$=createNode("TypeArgumentsOrDiamond","<>",{});}			
		;
FieldAccess:   Primary DOT Identifier								{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("FieldAccess",$2,{$1,lexeme1});}
		|	 SUPER DOT Identifier									{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("FieldAccess","super .",{lexeme1});}
		|	 Identifier DOT SUPER DOT Identifier					{Node* lexeme1 = createNode("ID",$1,{}); Node* lexeme2 = createNode("ID",$5,{}); $$ = createNode("FieldAccess",". super .",{lexeme1,lexeme2});}
		|	 ExpressionName DOT SUPER DOT Identifier				{Node* lexeme1 = createNode("ID",$5,{}); $$ = createNode("FieldAccess",". super .",{$1,lexeme1});}
		;
ArrayAccess:   Identifier LSB Expression RSB				{Node* lexeme1 = createNode("ID",$1,{}); $$ = createNode("ArrayAccess","[]",{lexeme1,$3});}
		|	 ExpressionName LSB Expression RSB				{$$ = createNode("ArrayAccess","[]",{$1,$3});}
		|	 PrimaryNoNewArray LSB Expression RSB			{$$ = createNode("ArrayAccess","[]",{$1,$3});}
		;
MethodInvocation:   MethodName LRB ArgumentList RRB								{$$ = createNode("MethodInvocation","()",{$1,$3});}
		|	 MethodName LRB RRB													{$$ = createNode("MethodInvocation","()",{$1});}
		|	 Identifier DOT Identifier LRB RRB									{Node* lexeme1 = createNode("ID",$1,{}); Node* lexeme2 = createNode("ID",$3,{}); $$ = createNode("MethodInvocation",$2,{lexeme1,lexeme2});}
		|	 Identifier DOT Identifier LRB ArgumentList RRB						{Node* lexeme1 = createNode("ID",$1,{}); Node* lexeme2 = createNode("ID",$3,{}); $$ = createNode("MethodInvocation",$2,{lexeme1,lexeme2,$5});}
		|	 Identifier DOT TypeArguments Identifier LRB RRB					{Node* lexeme1 = createNode("ID",$1,{}); Node* lexeme2 = createNode("ID",$4,{}); $$ = createNode("MethodInvocation",$2,{lexeme1,$3,lexeme2});}
		|	 Identifier DOT TypeArguments Identifier LRB ArgumentList RRB		{Node* lexeme1 = createNode("ID",$1,{}); Node* lexeme2 = createNode("ID",$4,{}); $$ = createNode("MethodInvocation",$2,{lexeme1,$3,lexeme2,$6});}
		|	 ExpressionName DOT Identifier LRB RRB										{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("MethodInvocation",$2,{$1,lexeme1});}
		|	 ExpressionName DOT Identifier LRB ArgumentList RRB							{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("MethodInvocation",$2,{$1,lexeme1,$5});}
		|	 ExpressionName DOT TypeArguments Identifier LRB RRB						{Node* lexeme1 = createNode("ID",$4,{}); $$ = createNode("MethodInvocation",$2,{$1,$3,lexeme1});}
		|	 ExpressionName DOT TypeArguments Identifier LRB ArgumentList RRB			{Node* lexeme1 = createNode("ID",$4,{}); $$ = createNode("MethodInvocation",$2,{$1,$3,lexeme1,$6});}
		|	 Primary DOT Identifier LRB RRB												{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("MethodInvocation",$2,{$1,lexeme1});}
		|	 Primary DOT Identifier LRB ArgumentList RRB								{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("MethodInvocation",$2,{$1,lexeme1,$5});}
		|	 Primary DOT TypeArguments Identifier LRB RRB								{Node* lexeme1 = createNode("ID",$4,{}); $$ = createNode("MethodInvocation",$2,{$1,$3,lexeme1});}
		|	 Primary DOT TypeArguments Identifier LRB ArgumentList RRB					{Node* lexeme1 = createNode("ID",$4,{}); $$ = createNode("MethodInvocation","super . ( )",{$1,$3,lexeme1,$6});}
		|	 SUPER DOT Identifier LRB RRB												{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("MethodInvocation","super . ( )",{lexeme1});}
		|	 SUPER DOT Identifier LRB ArgumentList RRB									{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("MethodInvocation","super . ( )",{lexeme1,$5});}
		|	 SUPER DOT TypeArguments Identifier LRB RRB									{Node* lexeme1 = createNode("ID",$4,{}); $$ = createNode("MethodInvocation","super . ( )",{$3,lexeme1});}
		|	 SUPER DOT TypeArguments Identifier LRB ArgumentList RRB					{Node* lexeme1 = createNode("ID",$4,{}); $$ = createNode("MethodInvocation","super . ( )",{$3,lexeme1,$6});}
		|	 Identifier DOT SUPER DOT Identifier LRB RRB								{Node* lexeme1 = createNode("ID",$1,{}); Node* lexeme2 = createNode("ID",$5,{}); $$ = createNode("MethodInvocation",". super . ( )",{lexeme1,lexeme2});}
		|	 Identifier DOT SUPER DOT Identifier LRB ArgumentList RRB					{Node* lexeme1 = createNode("ID",$1,{}); Node* lexeme2 = createNode("ID",$5,{}); $$ = createNode("MethodInvocation",". super . ( )",{lexeme1,lexeme2,$7});}
		|	 Identifier DOT SUPER DOT TypeArguments Identifier LRB RRB					{Node* lexeme1 = createNode("ID",$1,{}); Node* lexeme2 = createNode("ID",$6,{}); $$ = createNode("MethodInvocation",". super . ( )",{lexeme1,$5,lexeme2});}
		|	 Identifier DOT SUPER DOT TypeArguments Identifier LRB ArgumentList RRB		{Node* lexeme1 = createNode("ID",$1,{}); Node* lexeme2 = createNode("ID",$6,{}); $$ = createNode("MethodInvocation",". super . ( )",{lexeme1,$5,lexeme2,$8});}
		|	 ExpressionName DOT SUPER DOT Identifier LRB RRB							{Node* lexeme1 = createNode("ID",$5,{}); $$ = createNode("MethodInvocation",". super . ( )",{$1,lexeme1});}
		|	 ExpressionName DOT SUPER DOT Identifier LRB ArgumentList RRB				{Node* lexeme1 = createNode("ID",$5,{}); $$ = createNode("MethodInvocation",". super . ( )",{$1,lexeme1,$7});}
		|	 ExpressionName DOT SUPER DOT TypeArguments Identifier LRB RRB				{Node* lexeme1 = createNode("ID",$6,{}); $$ = createNode("MethodInvocation",". super . ( )",{$1,$5,lexeme1});}
		|	 ExpressionName DOT SUPER DOT TypeArguments Identifier LRB ArgumentList RRB	{Node* lexeme1 = createNode("ID",$6,{}); $$ = createNode("MethodInvocation",". super . ( )",{$1,$5,lexeme1,$8});}
		;

ArgumentList:	 Expression												{$$=createNode("ArgumentList","",{$1});}
		| Expression OMCommaExpression									{$$=createNode("ArgumentList","",{$1,$2});}
		;
MethodReference:   Identifier DOUBLECOLON Identifier			{Node* lexeme1 = createNode("ID",$1,{}); Node* lexeme2 = createNode("ID",$3,{}); $$ = createNode("MethodReference",$2,{lexeme1,lexeme2});}
		|	 ExpressionName DOUBLECOLON Identifier				{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("MethodReference",$2,{$1,lexeme1});}
		|	 Identifier DOUBLECOLON TypeArguments Identifier	{Node* lexeme1 = createNode("ID",$1,{}); Node* lexeme2 = createNode("ID",$4,{}); $$ = createNode("MethodReference",$2,{lexeme1,$3,lexeme2});}
		|	 ExpressionName DOUBLECOLON TypeArguments Identifier	{Node* lexeme1 = createNode("ID",$4,{}); $$ = createNode("MethodReference",$2,{$1,$3,lexeme1});}
		|	 Primary DOUBLECOLON Identifier							{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("MethodReference",$2,{$1,lexeme1});}
		|	 Primary DOUBLECOLON TypeArguments Identifier			{Node* lexeme1 = createNode("ID",$4,{}); $$ = createNode("MethodReference",$2,{$1,$3,lexeme1});}
		|	 UnannArrayType DOUBLECOLON Identifier					{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("MethodReference",$2,{$1,lexeme1});}
		|	 UnannArrayType DOUBLECOLON TypeArguments Identifier	{Node* lexeme1 = createNode("ID",$4,{}); $$ = createNode("MethodReference",":",{$1,$3,lexeme1});}
		|	 SUPER DOUBLECOLON Identifier							{Node* lexeme1 = createNode("ID",$3,{}); $$ = createNode("MethodReference","super :",{lexeme1});}
		|	 SUPER DOUBLECOLON TypeArguments Identifier				{Node* lexeme1 = createNode("ID",$4,{}); $$ = createNode("MethodReference","super :",{$3,lexeme1});}
		|	 Identifier DOT SUPER DOUBLECOLON Identifier			{Node* lexeme1 = createNode("ID",$1,{}); Node* lexeme2 = createNode("ID",$5,{}); $$ = createNode("MethodReference",". super :",{lexeme1,lexeme2});}
		|	 Identifier DOT SUPER DOUBLECOLON TypeArguments Identifier	{Node* lexeme1 = createNode("ID",$1,{}); Node* lexeme2 = createNode("ID",$6,{}); $$ = createNode("MethodReference",". super :",{lexeme1,$5,lexeme2});}
		|	 ExpressionName DOT SUPER DOUBLECOLON Identifier					{Node* lexeme1 = createNode("ID",$5,{}); $$ = createNode("MethodReference",". super :",{$1,lexeme1});}
		|	 ExpressionName DOT SUPER DOUBLECOLON TypeArguments Identifier		{Node* lexeme1 = createNode("ID",$6,{}); $$ = createNode("MethodReference",". super :",{$1,$5,lexeme1});}
		|	 UnannArrayType DOUBLECOLON NEW										{$$ = createNode("MethodReference",$2,{$1});}
		|	 UnannArrayType DOUBLECOLON TypeArguments NEW						{$$ = createNode("MethodReference",$2,{$1,$3});}
		;
ArrayCreationExpression:   NEW PrimitiveType OMDimExpr							{$$ = createNode("ArrayCreationExpression",$1,{$2,$3});}
		|	 NEW PrimitiveType OMDimExpr OMPSB									{$$ = createNode("ArrayCreationExpression",$1,{$2,$3,$4});}
		|	 NEW Identifier OMDimExpr											{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("ArrayCreationExpression",$1,{lexeme1,$3});}
		|	 NEW Identifier OMDimExpr OMPSB										{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("ArrayCreationExpression",$1,{lexeme1,$3,$4});}
		|	 NEW PrimitiveType OMPSB ArrayInitializer							{$$ = createNode("ArrayCreationExpression",$1,{$2,$3,$4});}
		|	 NEW Identifier OMPSB ArrayInitializer								{Node* lexeme1 = createNode("ID",$2,{}); $$ = createNode("ArrayCreationExpression",$1,{lexeme1,$3,$4});}
		;

DimExpr:	 LSB Expression RSB								{$$=createNode("DimExpr","[]",{$2});}
		| OMAnnotation LSB Expression RSB					{$$=createNode("DimExpr","[]",{$1,$3});}
		;
Expression:	AssignmentExpression							{$$=$1;}
		;
AssignmentExpression:	 ConditionalExpression				{$$=$1;}
		| Assignment										{$$=$1;}
		;
Assignment:	 LeftHandSide AssignmentOperator Expression		{$$=createNode("Assignment",$2,{$1,$3});}
		;
LeftHandSide:	 ExpressionName								{$$=$1;}
   		| Identifier										{Node*lexeme=createNode("ID",$1,{});$$=createNode("LeftHandSide","",{lexeme});}
		| FieldAccess										{$$=$1;}
		| ArrayAccess										{$$=$1;}
		;
AssignmentOperator:	 ASSIGNMENTOPERATOR						{$$=$1;}
		;
ConditionalExpression:	 ConditionalOrExpression									{$$=$1;}
		| ConditionalOrExpression QM Expression COLON ConditionalExpression			{$$=createNode("ConditionalExpression","? :",{$1,$3,$5});}
		;
ConditionalOrExpression:	 ConditionalAndExpression								{$$=$1;}									
		| ConditionalOrExpression OR ConditionalAndExpression 						{$$=createNode("ConditionalOrExpression",$2,{$1,$3});}		
		;
ConditionalAndExpression:	 InclusiveOrExpression									{$$=$1;}
		| ConditionalAndExpression AND InclusiveOrExpression						{$$=createNode("ConditionalAndExpression",$2,{$1,$3});}	
		;
InclusiveOrExpression:	 ExclusiveOrExpression										{$$=$1;}
		| InclusiveOrExpression BITOR ExclusiveOrExpression							{$$=createNode("InclusiveOrExpression",$2,{$1,$3});}	
		;
ExclusiveOrExpression:	 AndExpression												{$$=$1;}
		| ExclusiveOrExpression BITXOR AndExpression								{$$=createNode("ExclusiveOrExpression",$2,{$1,$3});}	
		;
AndExpression:	 EqualityExpression													{$$=$1;}
		| AndExpression BITAND EqualityExpression									{$$=createNode("AndExpression",$2,{$1,$3});}	
		;
EqualityExpression:	 RelationalExpression											{$$=$1;}
		| EqualityExpression DOUBLEEQUAL RelationalExpression						{$$=createNode("EqualityExpression",$2,{$1,$3});}	
		| EqualityExpression NE RelationalExpression								{$$=createNode("EqualityExpression",$2,{$1,$3});}	
		;
RelationalExpression:	 ShiftExpression											{$$=$1;}
		| RelationalExpression LT ShiftExpression									{$$=createNode("RelationalExpression",$2,{$1,$3});}	
		| RelationalExpression GT ShiftExpression									{$$=createNode("RelationalExpression",$2,{$1,$3});}	
		| RelationalExpression LTE ShiftExpression									{$$=createNode("RelationalExpression",$2,{$1,$3});}	
		| RelationalExpression GTE ShiftExpression									{$$=createNode("RelationalExpression",$2,{$1,$3});}	
		| InstanceofExpression														{$$=$1;}
		;
InstanceofExpression:	 RelationalExpression INSTANCEOF ReferenceType				{$$=createNode("InstanceofExpression",$2,{$1,$3});}	
		;
ShiftExpression:	 AdditiveExpression												{$$=$1;}
		| ShiftExpression LSHIFT AdditiveExpression									{$$=createNode("ShiftExpression",$2,{$1,$3});}		
		| ShiftExpression RSHIFT AdditiveExpression									{$$=createNode("ShiftExpression",$2,{$1,$3});}	
		| ShiftExpression THREEGT AdditiveExpression								{$$=createNode("ShiftExpression",$2,{$1,$3});}	
		;
AdditiveExpression:	 MultiplicativeExpression										{$$=$1;}
		| AdditiveExpression PLUS MultiplicativeExpression							{$$=createNode("AdditiveExpression",$2,{$1,$3});}	
		| AdditiveExpression MINUS MultiplicativeExpression							{$$=createNode("AdditiveExpression",$2,{$1,$3});}	
		;
MultiplicativeExpression:	 UnaryExpression										{$$=$1;}
		| MultiplicativeExpression MULTIPLY UnaryExpression							{$$=createNode("MultiplicativeExpression",$2,{$1,$3});}	
		| MultiplicativeExpression DIVIDE UnaryExpression							{$$=createNode("MultiplicativeExpression",$2,{$1,$3});}	
		| MultiplicativeExpression PERCENT UnaryExpression							{$$=createNode("MultiplicativeExpression",$2,{$1,$3});}	
		;
UnaryExpression:	 PreIncrementExpression											{$$=$1;}
		| PreDecrementExpression													{$$=$1;}
		| PLUS UnaryExpression														{$$=createNode("UnaryExpression",$1,{$2});}
		| MINUS UnaryExpression														{$$=createNode("UnaryExpression",$1,{$2});}
		| UnaryExpressionNotPlusMinus												{$$=$1;}
		;
PreIncrementExpression:	 INCREAMENT UnaryExpression									{$$=createNode("PreIncrementExpression",$1,{$2});}
		;
PreDecrementExpression:	 DECREAMENT UnaryExpression									{$$=createNode("PreDecrementExpression",$1,{$2});}
		;
UnaryExpressionNotPlusMinus:	 PostfixExpression									{$$=$1;}
		| TILDA UnaryExpression														{$$=createNode("UnaryExpressionNotPlusMinus",$1,{$2});}
		| EXCLAM UnaryExpression													{$$=createNode("UnaryExpressionNotPlusMinus",$1,{$2});}
		| CastExpression															{$$=$1;}
		| SwitchExpression															{$$=$1;}
		;
PostfixExpression:	 Primary														{$$=$1;}
		| Identifier																{Node*lexeme=createNode("ID",$1,{});$$=createNode("PostfixExpression","",{lexeme});}
		| ExpressionName															{$$=$1;}
		| PostIncrementExpression													{$$=$1;}
		| PostDecrementExpression													{$$=$1;}
		;
PostIncrementExpression:	 PostfixExpression INCREAMENT							{$$=createNode("PostIncrementExpression",$2,{$1});}
		;
PostDecrementExpression:	 PostfixExpression DECREAMENT							{$$=createNode("PostDecrementExpression",$2,{$1});}
		;
CastExpression:	 LRB PrimitiveType RRB UnaryExpression								{$$=createNode("CastExpression","()",{$2,$4});}
		| LRB UnannArrayType RRB UnaryExpressionNotPlusMinus						{$$=createNode("CastExpression","()",{$2,$4});}
		| LRB UnannArrayType OMAdditionalBound RRB UnaryExpressionNotPlusMinus		{$$=createNode("CastExpression","()",{$2,$3,$5});}
		;
SwitchExpression:	 SWITCH LRB Expression RRB SwitchBlock							{$$=createNode("SwitchExpression",$1,{$3,$5});}
		;	
VariableAccess:	 ExpressionName														{$$=$1;}
    	| Identifier																{Node*lexeme=createNode("ID",$1,{});$$=createNode("PostfixExpression","",{lexeme});}
		| FieldAccess																{$$=$1;}
		;
%%
int counter=2;
void dfs(Node* head, int num){
	
    for(Node* child:head->children){
		string temp,val,shape,color;
		if((child->value)[0]=='"'){
			temp="\\"+(child->value).substr(0,(child->value).size()-1)+"\\\"";
		}
		else{
			temp=child->value;
		}
		if((child->value).empty()){
			shape=",shape = box";
			val=child->label;
			color="";
			}
			else{
			shape="";
			val=child->label+"("+temp+")";
			color=", color=lightblue, style=filled";
			}
        fprintf(dotfile,"%d [label = \"%s\"%s%s];\n",counter,val.c_str(),shape.c_str(),color.c_str());

        fprintf(dotfile,"%d->%d [ label = \"%s\"];\n",num,counter,(child->expressionLabel).c_str());

        counter++;
        dfs(child,counter-1);
	}
}


void dotGenerator(){
    if(root==NULL)  return;
    fprintf(dotfile,"digraph G { \nsize=\"10,12\"; center = true; bgcolor=\"lightyellow\"");

	string temp,val,shape,color;
		if((root->value)[0]=='"'){
			temp="\\"+(root->value).substr(0,(root->value).size()-1)+"\\\"";
		}
		else{
			temp=root->value;
		}
		if((root->value).empty()){
			shape=",shape = box";
			val=root->label;
			color="";
			}
			else{
			shape="";
			val=root->label+"("+temp+")";
			color=", color=lightblue, style=filled";
			}
        fprintf(dotfile,"1 [label = \"%s\"%s%s];\n",val.c_str(),shape.c_str(),color.c_str());
        dfs(root,1);
        fprintf(dotfile, "}\n");

}

int main (int argc,char*argv[]) {
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
        dotfile = fopen("output.dot", "w");
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
	yyparse();
    if(verbose){
        cout<<"Parsing finished\n";
        cout<<"DOT file generation started\n";
        cout<<"DOT file generating....\n";
    }
    dotGenerator();
    if(verbose){
        cout<<"DOT file generated\n";
        cout<<"Enter following command: dot -Tps <outputfilename> -o graph.ps for further generating ps file\n";
    }
	return 0;
}

void yyerror (const char *s) {cerr<<"Error on Line "<<line<<endl;}

