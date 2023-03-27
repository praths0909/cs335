%{
    #include<bits/stdc++.h>
    using namespace std;   
    #include "parser2.tab.h"
    void yyerror (char *s);
    long long int line = 1;
%}

Whitespace [ \t\f]
LineTerminator "\r"|"\n"|"\r\n"

NonZeroDigit [1-9]
Digit 0|{NonZeroDigit}
ZeroToThree [0-3]
OctalDigit [0-7]
HexDigit [0-9a-fA-F]

OctalEscape [\\]{OctalDigit}|[\\]{OctalDigit}{OctalDigit}|[\\]{ZeroToThree}{OctalDigit}{OctalDigit}
EscapeSequence [\\][n]|[\\][b]|[\\][s]|[\\][t]|[\\][f]|[\\][r]|[\\]{LineTerminator}|[\\]["]|[\\][']|[\\][\\]|{OctalEscape}

StringCharacter [^\\"]|{EscapeSequence}
String ["]({StringCharacter})*["]

CharacterLiteral [']([^\\']|{EscapeSequence})[']

Underscores _[_]*
IntegerTypeSuffix [lL] 
DigitOrUnderscore {Digit}|_
DigitsAndUnderscores {DigitOrUnderscore}({DigitOrUnderscore})* 
Digits {Digit}|{Digit}({DigitsAndUnderscores})?{Digit}
DecimalNumeral 0|{NonZeroDigit}({Digits})?|{NonZeroDigit}{Underscores}{Digits}
DecimalIntegerLiteral {DecimalNumeral}({IntegerTypeSuffix})?


HexDigitOrUnderscore {HexDigit}|[_]
HexDigitsAndUnderscores {HexDigitOrUnderscore}({HexDigitOrUnderscore})* 
HexDigits {HexDigit}|{HexDigit}({HexDigitsAndUnderscores})?{HexDigit}
HexNumeral 0[xX]{HexDigits}
HexIntegerLiteral {HexNumeral}({IntegerTypeSuffix})?


OctalDigitOrUnderscore {OctalDigit}|[_]
OctalDigitsAndUnderscores {OctalDigitOrUnderscore}({OctalDigitOrUnderscore})*
OctalDigits {OctalDigit}|{OctalDigit}({OctalDigitsAndUnderscores})?{OctalDigit}
OctalNumeral 0{OctalDigits}|0{Underscores}{OctalDigits}
OctalIntegerLiteral {OctalNumeral}({IntegerTypeSuffix})? 

BinaryDigit [01]
BinaryDigitOrUnderscore {BinaryDigit}|[_]
BinaryDigitsAndUnderscores {BinaryDigitOrUnderscore}({BinaryDigitOrUnderscore})*
BinaryDigits {BinaryDigit}|{BinaryDigit}({BinaryDigitsAndUnderscores})?{BinaryDigit}
BinaryNumeral 0b{BinaryDigits}|0B{BinaryDigits}
BinaryIntegerLiteral {BinaryNumeral}({IntegerTypeSuffix})?

IntegerLiteral {DecimalIntegerLiteral}|{OctalIntegerLiteral}|{BinaryIntegerLiteral}|{HexIntegerLiteral}

FloatTypeSuffix [fFdD]
Sign [+-]
ExponentIndicator [eE]
SignedInteger ({Sign})?{Digits}
ExponentPart {ExponentIndicator}{SignedInteger}
DecimalFloatingPointLiteral {Digits}[.]({Digits})?({ExponentPart})?({FloatTypeSuffix})?|[.]{Digits}({ExponentPart})?({FloatTypeSuffix})?|{Digits}{ExponentPart}({FloatTypeSuffix})?|{Digits}({ExponentPart})?{FloatTypeSuffix}

BinaryExponentIndicator [pP]
HexSignificand {HexNumeral}([.])?|0x({HexDigits})?[.]{HexDigits}|0X({HexDigits})?[.]{HexDigits}
BinaryExponent {BinaryExponentIndicator}{SignedInteger}
HexadecimalFloatingPointLiteral {HexSignificand}{BinaryExponent}({FloatTypeSuffix})?

FloatingPointLiteral {DecimalFloatingPointLiteral}|{HexadecimalFloatingPointLiteral}

BooleanLiteral true|false

NullLiteral null

TextBlocks ["]["]["]{Whitespace}*{LineTerminator}+[^"]*(["]["]?([^"])+)*["]["]["]



SingleLineComment "//".*{LineTerminator}
MultiLineComment [/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]

%%

"abstract" {yylval.str=strdup(yytext);  return ABSTRACT;}
"continue" {yylval.str=strdup(yytext); return CONTINUE;}
"for" {yylval.str=strdup(yytext); return FOR;}
"new" {yylval.str=strdup(yytext); return NEW;}
"switch" {yylval.str=strdup(yytext); return SWITCH;}
"assert" {yylval.str=strdup(yytext); return ASSERT;}
"default" {yylval.str=strdup(yytext); return DEFAULT;}
"if" {yylval.str=strdup(yytext); return IF;}
"package" {yylval.str=strdup(yytext); return PACKAGE;}
"synchronized" {yylval.str=strdup(yytext); return SYNCHRONIZED;}
"boolean" {yylval.str=strdup(yytext); return BOOLEAN;}
"do" {yylval.str=strdup(yytext); return DO;}
"goto" {yylval.str=strdup(yytext); return GOTO;}
"private" {yylval.str=strdup(yytext); return PRIVATE;}
"this" {yylval.str=strdup(yytext); return THIS;}
"break" {yylval.str=strdup(yytext); return BREAK;}
"double" {yylval.str=strdup(yytext); return DOUBLE;}
"implements" {yylval.str=strdup(yytext); return IMPLEMENTS;}
"protected" {yylval.str=strdup(yytext); return PROTECTED;}
"throw" {yylval.str=strdup(yytext); return THROW;}
"byte" {yylval.str=strdup(yytext); return BYTE;}
"else" {yylval.str=strdup(yytext); return ELSE;}
"import" {yylval.str=strdup(yytext); return IMPORT;}
"public" {yylval.str=strdup(yytext); return PUBLIC;}
"throws" {yylval.str=strdup(yytext); return THROWS;}
"case" {yylval.str=strdup(yytext); return CASE;}
"enum" {yylval.str=strdup(yytext); return ENUM;}
"instanceof" {yylval.str=strdup(yytext); return INSTANCEOF;}
"return" {yylval.str=strdup(yytext); return RETURN;}
"transient" {yylval.str=strdup(yytext); return TRANSIENT;}
"catch" {yylval.str=strdup(yytext); return CATCH;}
"extends" {yylval.str=strdup(yytext); return EXTENDS;}
"int" {yylval.str=strdup(yytext); return INT;}
"short" {yylval.str=strdup(yytext); return SHORT;}
"try" {yylval.str=strdup(yytext); return TRY;}
"char" {yylval.str=strdup(yytext); return CHAR;}
"final" {yylval.str=strdup(yytext); return FINAL;}
"interface" {yylval.str=strdup(yytext); return INTERFACE;}
"static" {yylval.str=strdup(yytext); return STATIC;}
"void" {yylval.str=strdup(yytext); return VOID;}
"class" {yylval.str=strdup(yytext); return CLASS;}
"finally" {yylval.str=strdup(yytext); return FINALLY;}
"long" {yylval.str=strdup(yytext); return LONG;}
"strictfp" {yylval.str=strdup(yytext); return STRICTFP;}
"volatile" {yylval.str=strdup(yytext); return VOLATILE;}
"const" {yylval.str=strdup(yytext); return CONST;}
"float" {yylval.str=strdup(yytext); return FLOAT;}
"native" {yylval.str=strdup(yytext); return NATIVE;}
"super" {yylval.str=strdup(yytext); return SUPER;}
"while" {yylval.str=strdup(yytext); return WHILE;}
"_" {yylval.str=strdup(yytext); return UNDERSCORE;}



"permits" {yylval.str=strdup(yytext); return PERMITS;}
"sealed" {yylval.str=strdup(yytext); return SEALED;}
"var" {yylval.str=strdup(yytext); return VAR;}
"yield" {yylval.str=strdup(yytext); return YIELD;}
"record" {yylval.str=strdup(yytext); return RECORD;}
"exports" {yylval.str=strdup(yytext); return EXPORTS;}
"opens" {yylval.str=strdup(yytext); return OPENS;}
"requires" {yylval.str=strdup(yytext); return REQUIRES;}
"uses" {yylval.str=strdup(yytext); return USES;}
"module" {yylval.str=strdup(yytext); return MODULE;}
"non-sealed" {yylval.str=strdup(yytext); return NONSEALED;}
"provides" {yylval.str=strdup(yytext); return PROVIDES;}
"to" {yylval.str=strdup(yytext); return TO;}
"with" {yylval.str=strdup(yytext); return WITH;}
"open" {yylval.str=strdup(yytext); return OPEN;}
"transitive" {yylval.str=strdup(yytext); return TRANSITIVE;}




{IntegerLiteral} {yylval.str=strdup(yytext); return INTEGERLITERAL;}
{FloatingPointLiteral} {yylval.str=strdup(yytext); return FLOATINGPOINTLITERAL;}
{BooleanLiteral} {yylval.str=strdup(yytext); return BOOLEANLITERAL;}
{NullLiteral} {yylval.str=strdup(yytext); return NULLLITERAL;}
{CharacterLiteral} {yylval.str=strdup(yytext); return CHARACTERLITERAL;}
{String} {yylval.str=strdup(yytext); return STRING;}
{TextBlocks} {yylval.str=strdup(yytext); return TEXTBLOCKS;}
{EscapeSequence} {yylval.str=strdup(yytext); return ESCAPESEQUENCE;}




">"    {yylval.str=strdup(yytext); return GT;}
"<"    {yylval.str=strdup(yytext); return LT;}
"!"    {yylval.str=strdup(yytext); return EXCLAM;}
"~"    {yylval.str=strdup(yytext); return TILDA;}
"?"    {yylval.str=strdup(yytext); return QM;}
":"    {yylval.str=strdup(yytext); return COLON;}
"->"   {yylval.str=strdup(yytext); return IMPLIES;}
"=="   {yylval.str=strdup(yytext); return DOUBLEEQUAL;}
">="   {yylval.str=strdup(yytext);return GTE;}
"<="   {yylval.str=strdup(yytext);return LTE;}
"!="   {yylval.str=strdup(yytext);return NE;}
"&&"   {yylval.str=strdup(yytext);return AND;}
"||"   {yylval.str=strdup(yytext);return OR;}
"++"   {yylval.str=strdup(yytext);return INCREAMENT;}
"--"   {yylval.str=strdup(yytext);return DECREAMENT;}
"+"    {yylval.str=strdup(yytext);return PLUS;}
"-"    {yylval.str=strdup(yytext);return MINUS;}
"*"    {yylval.str=strdup(yytext);return MULTIPLY;}
"/"    {yylval.str=strdup(yytext);return DIVIDE;}
"&"    {yylval.str=strdup(yytext);return BITAND;}
"|"    {yylval.str=strdup(yytext);return BITOR;}
"^"    {yylval.str=strdup(yytext);return BITXOR;}
"%"    {yylval.str=strdup(yytext);return PERCENT;}
"<<"   {yylval.str=strdup(yytext);return LSHIFT;}
">>"   {yylval.str=strdup(yytext);return RSHIFT;}
">>>"  {yylval.str=strdup(yytext);return THREEGT;}
"="    {yylval.str=strdup(yytext);return EQUAL;}
"*="|"/="|"%="|"+="|"-="|"<<="|">>="|">>>="|"&="|"^="|"|=" {yylval.str=strdup(yytext);return NEWASSIGNMENTOPERATOR;}



"("   {yylval.str=strdup(yytext);return LRB;}
")"   {yylval.str=strdup(yytext);return RRB;}
"{"   {yylval.str=strdup(yytext);return LCB;}
"}"   {yylval.str=strdup(yytext);return RCB;}
"["   {yylval.str=strdup(yytext);return LSB;}
"]"   {yylval.str=strdup(yytext);return RSB;}
";"   {yylval.str=strdup(yytext);return SEMICOLON;}
","   {yylval.str=strdup(yytext);return COMMA;}
"."   {yylval.str=strdup(yytext);return DOT;}
"..." {yylval.str=strdup(yytext);return THREEDOT;}
"@"   {yylval.str=strdup(yytext);return AT;}
"::"  {yylval.str=strdup(yytext);return DOUBLECOLON;}


[_a-zA-Z$][_a-zA-Z0-9$]* {yylval.str=strdup(yytext);return IDENTIFIERWK;}

{LineTerminator} {line++;}

{Whitespace} {}

{SingleLineComment} {line++; /*comments , meant to be ignored*/}
{MultiLineComment} { for(int i = 0; i<yyleng; ++i) if(yytext[i] == '\n') line++; /* comments, meant to be ignored */}

. {cout<<"Error character is "<<yytext<<" Error is on line number"<<line<<endl;}


%%
int yywrap(){
    return 1;
}