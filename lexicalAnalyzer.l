%{
/* This program identifies tokens from a 
 * valid pascal program. Note that pascal is
 * case insensitive for identifiers and keywords.
 * http://www.freepascal.org/ is the reference used.
*/
#include <stdarg.h>
#include "Definitions.h"
#include "y.tab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void yyerror(char * error);
int line_number =1;
unsigned int curScopeId = 0;
unsigned int tempId = 1;
unsigned int labelId = 1;
unsigned int quadId = 0;
int tempArray[1000];
FILE *data,*text;
char tempName[256];
int ifFlag = 0;

int yywrap(void){
return 1;}

%}

ident [a-zA-Z][a-zA-Z0-9_]*

integer [0-9]+
float {integer}"."[0-9]+
real_number {float}[eE][+-][0-9]+
hexa $[0-9a-fA-F]+"."[0-9a-fA-F]+
octal &[0-7]+"."[0-7]+
binary %[0-1]+"."[0-1]+

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]

eol \n

single_quotes [^']

double_quotes [^"]

character .



%%

{A}{B}{S}{O}{L}{U}{T}{E}	return(ABSOLUTE);
{C}{O}{N}{S}{T}{R}{U}{C}{T}{O}{R}	{  curScopeId++; Push(&scopeStack,curScopeId);return(CONSTRUCT);}
{D}{E}{S}{T}{R}{U}{C}{T}{O}{R}	{    curScopeId++; Push(&scopeStack,curScopeId);return(DESTRUCT);}
{I}{M}{L}{E}{M}{E}{N}{T}{A}{T}{I}{O}{N}	return(IMPLEMENT);
{I}{N}{H}{E}{R}{I}{T}{E}{D}	return(INHERITED);
{I}{N}{L}{I}{N}{E}	return(INLINE);
{I}{N}{T}{E}{R}{F}{A}{C}{E}	return(INTERFACE);
{O}{B}{J}{E}{C}{T}	{ curScopeId++; Push(&scopeStack,curScopeId);/*scopeStack = (scopeStack << SCOPE_ID_SIZE) | curScopeId;*/ return(OBJ);}
{O}{N}	return(ON);
{O}{P}{E}{R}{A}{T}{O}{R}	return(OP);
{R}{E}{I}{N}{T}{R}{O}{D}{U}{C}{E}	return(REINTRO);
{S}{E}{L}{F}	return(SELF);
{S}{H}{L}	return(SHL);
{S}{H}{R}	return(SHR);
{S}{T}{R}{I}{N}{G}	return(STRING);
{U}{N}{I}{T}	{ curScopeId++; Push(&scopeStack,curScopeId);/*scopeStack = (scopeStack << SCOPE_ID_SIZE) | curScopeId;*/ return(UNIT);}
{U}{S}{E}{S}	return(USES);
{X}{O}{R}	return(XOR);
{C}{L}{A}{S}{S}	{ curScopeId++; Push(&scopeStack,curScopeId);return(CLASS);}
{E}{X}{C}{E}{P}{T}	return(EXCEPT);
{E}{X}{P}{O}{R}{T}{S}	return(EXPORTS);
{F}{I}{N}{A}{L}{I}{Z}{A}{T}{I}{O}{N}	return(FINALIZATION);
{F}{I}{N}{A}{L}{L}{Y}	return(FINALLY);
{I}{N}{I}{T}{I}{A}{L}{I}{Z}{A}{T}{I}{O}{N}	return(INITIALIZATION);
{L}{I}{B}{R}{A}{R}{Y}	{ curScopeId++; Push(&scopeStack,curScopeId);return(LIBRARY);}
{O}{U}{T}	return(OUT);
{P}{R}{O}{P}{E}{R}{T}{Y}	return(PROPERTY);
{R}{A}{I}{S}{E}	return(RAISE);
{T}{H}{R}{E}{A}{D}{V}{A}{R}	return(THREADVAR);
{T}{R}{Y}	return(TRY);
{D}{I}{S}{P}{O}{S}{E}	return(DISPOSE);
{E}{X}{I}{T}	return(EXIT);
{F}{A}{L}{S}{E}	return(PFALSE);
{N}{E}{W}	return(NEW);
{T}{R}{U}{E}	return(PTRUE);
{A}{N}{D}   {return(AND);}
{A}{R}{R}{A}{Y}   return(ARRAY);
{C}{A}{S}{E}   return(CASE);
{C}{O}{N}{S}{T}   return(CONST);
{D}{I}{V}   return(DIV);
{D}{O}    return(DO);
{D}{O}{W}{N}{T}{O}  {return(DOWNTO);}
{E}{L}{S}{E}   return(ELSE);
{E}{N}{D}   return(END);
{E}{X}{T}{E}{R}{N} |
{E}{X}{T}{E}{R}{N}{A}{L} return(EXTERNAL);
{F}{O}{R}   { ifFlag = 1;return(FOR);}
{F}{O}{R}{W}{A}{R}{D}  return(FORWARD);
{F}{U}{N}{C}{T}{I}{O}{N} {return(FUNC);}
{G}{O}{T}{O}   return(GOTO);
{I}{F}   {ifFlag = 1; return(IF);}
{L}{A}{B}{E}{L}   return(LABEL);
{M}{O}{D}   {return(MOD);}
{N}{I}{L}   return(NIL);
{N}{O}{T}   return(NOT);
{O}{F}    return(OF);
{O}{R}      {return(OR);}
{O}{T}{H}{E}{R}{W}{I}{S}{E} return(OTHERWISE);
{P}{A}{C}{K}{E}{D}  return(PACKED);
{B}{E}{G}{I}{N}   return(PBEGIN);
{F}{I}{L}{E}   return(PFILE);
{P}{R}{O}{C}{E}{D}{U}{R}{E} { return(PROCEDURE); }
{P}{R}{O}{G}{R}{A}{M}  { curScopeId++; Push(&scopeStack,curScopeId);return(PROGRAM);  }
{R}{E}{C}{O}{R}{D}  {curScopeId++; Push(&scopeStack,curScopeId); return(RECORD);}
{R}{E}{P}{E}{A}{T}  return(REPEAT);
{S}{E}{T}   return(SET);
{T}{H}{E}{N}   return(THEN);
{T}{O}    { return(TO);}
{T}{Y}{P}{E}   return(TYPE);
{U}{N}{T}{I}{L}   { ifFlag = 1; return(UNTIL);}
{V}{A}{R}   return(VAR);
{W}{H}{I}{L}{E}   {ifFlag = 1; return(WHILE);}
{W}{I}{T}{H}   return(WITH);

{I}{M}{P}{L}{E}{M}{E}{N}{T}{A}{T}{I}{O}{N}	return(IMPLEMENTATION );
{R}{E}{S}{O}{U}{R}{C}{E}{S}{T}{R}{I}{N}{G}	return(RESOURCESTRING);
{R}{E}{S}{I}{D}{E}{N}{T}	return(RESIDENT);
{P}{A}{C}{K}{A}{G}{E}	return(PACKAGE);
{R}{E}{Q}{U}{I}{R}{E}{S}	return(REQUIRES);
{C}{O}{N}{T}{A}{I}{N}{S}	return(CONTAINS);
{A}{D}{D}{R}{E}{S}{S}{O}{F}	return(ADDROF);
{D}{I}{S}{P}{I}{N}{T}{E}{R}{F}{A}{C}{E}   return(DISPINTERFACE);
{R}{E}{A}{D}{O}{N}{L}{Y}	return(READONLY);
{W}{R}{I}{T}{E}{O}{N}{L}{Y}	return(WRITEONLY);
{N}{O}{D}{E}{F}{A}{U}{L}{T}	return(NODEFAULT);
{S}{T}{O}{R}{E}{D}	return(store_argumentD);
{I}{M}{P}{L}{E}{M}{E}{N}{T}{S}	return(IMPLEMENTS);
{M}{E}{S}{S}{A}{G}{E}	return(MESSAGE);
{A}{T}	return(AT);
{R}{E}{A}{L}48	return(REAL48);
{S}{I}{N}{G}{L}{E}	return(SINGLE);
{D}{O}{U}{B}{L}{E}	return(DOUBLE);
{E}{X}{T}{E}{N}{D}{E}{D}	return(EXTENDED);
{C}{U}{R}{R}{E}{N}{C}{Y}	return(CURRENCY);
{C}{O}{M}{P}	return(COMP);
{S}{H}{O}{R}{T}{I}{N}{T}	return(SHORTINT);
{S}{M}{A}{L}{L}{I}{N}{T}	return(SMALLINT);
{Q}{W}{O}{R}{D}	return(QWORD);
{B}{Y}{T}{E}	return(BYTE);
{L}{O}{N}{G}{I}{N}{T}	return(LONGINT);
{I}{N}{T}64	return(INT64);
{W}{O}{R}{D}	return(WORD);
{B}{O}{O}{L}{E}{A}{N}	return(BOOLEAN);
{C}{H}{A}{R}	return(CHAR);
{W}{I}{D}{E}{C}{H}{A}{R}	return(WIDECHAR);
{L}{O}{N}{G}{W}{O}{R}{D}	return(LONGWORD);
{P}{C}{H}{A}{R}	return(PCHAR);
{C}{A}{R}{D}{I}{N}{A}{L}	return(CARDINAL);
{O}{L}{E}{V}{A}{R}{I}{A}{N}{T}	return(OLEVARIANT);
{A}{N}{S}{I}{S}{T}{R}	return(ANSISTR);	
{W}{I}{D}{E}{S}{T}{R}	return(WIDESTR);
{A}{U}{T}{O}{M}{A}{T}{E}{D}	return(AUTOMATED);
{D}{Y}{N}{A}{M}{I}{C}	return(DYNAMIC);
{O}{V}{E}{R}{L}{O}{A}{D}	return(OVERLOAD);
{V}{A}{R}{I}{A}{N}{T}	return(VARIANT);

{A}{B}{S}{T}{R}{A}{C}{T} return(ABSTRACT);
{A}{L}{I}{A}{S} return(ALIAS);
{A}{S}{S}{E}{M}{B}{L}{E}{R} return(ASSEMBLER);
{C}{D}{E}{C}{L} return(CDECL);
{C}{P}{P}{D}{E}{C}{L} return(CPPDECL);
{D}{E}{F}{A}{U}{L}{T} return(DEFAULT);
{E}{X}{P}{O}{R}{T} return(EXPORT);
{F}{A}{R} return(FAR);
{F}{A}{R}16 return(FAR16);
{I}{N}{D}{E}{X} return(INDEX);
{L}{O}{C}{A}{L} return(LOCAL);
{N}{A}{M}{E} return(NAME);
{N}{E}{A}{R} return(NEAR);
{N}{O}{S}{T}{A}{C}{K}{F}{R}{A}{M}{E} return(NOSTACKFRAME);
{O}{L}{D}{F}{P}{C}{C}{A}{L}{L} return(OLDFPCCALL);
{O}{V}{E}{R}{R}{I}{D}{E} return(OVERRIDE);
{P}{A}{S}{C}{A}{L} return(PASCAL);
{P}{R}{I}{V}{A}{T}{E} return(PRIVATE);
{P}{R}{O}{T}{E}{C}{T}{E}{D} return(PROTECTED);
{P}{U}{B}{L}{I}{C} return(PUBLIC);
{P}{U}{B}{L}{I}{S}{H}{E}{D} return(PUBLISHED);
{R}{E}{A}{D} return(READ);
{R}{E}{G}{I}{S}{T}{E}{R} return(REGISTER);
{S}{A}{F}{E}{C}{A}{L}{L} return(SAFECALL);
{S}{O}{F}{T}{F}{L}{O}{A}{T} return(SOFTFLOAT);
{S}{T}{D}{C}{A}{L}{L} return(STDCALL);
{V}{I}{R}{T}{U}{A}{L} return(VIRTUAL);
{W}{R}{I}{T}{E}{L}{N}	return(WRITELN);
{W}{R}{I}{T}{E}	return(WRITE);
{I}{N}{T}{E}{G}{E}{R} return(INTEGER);
{R}{E}{A}{L}	return(REALS);

{A}{S}{M}  { register int c;
     while ((c = input()))
     {
      if (c == 'E' || c == 'e') {
		c = input();
		if (c == 'N' || c == 'n') {
			c = input();
			if (c == 'D' || c == 'd') {
				return(ASMBODY);
				break;
			}
		}
	}
      else if (c == '\n') {
       line_number++;
	
      }
     }
    }

{ident} 	{ strcpy(yylval.name,yytext); /*NewEntry(yytext,IDENT,line_number,&table[hashKey(yytext)],scopeStack);*/ return(IDENT); }
{integer} 	{  yylval.ival = atoi(yytext);return(INT); }
{float} 	 {   yylval.dval = atof(yytext); return(FLOAT); }
{real_number} 	 { yylval.dval = atof(yytext); return(REAL); }
{octal}		 {  strcpy(yylval.name,yytext); return(OCTAL); }
{binary}	 { strcpy(yylval.name,yytext);return(BINARY); }
{hexa}		 {  strcpy(yylval.name,yytext);return(HEXA); }

"#"{integer}	return(ASCIICHAR);
":="   { return(ASSIGN);}
":"    return(COLON);
","    return(COMMA);
"."    return(DOT);
".."    return(DOTDOT);
"="    {return(EQUAL);}
">="     {return(GE);}
">"    {return(GT);}
"["    return(LSQBRACK);
"<="    {return(LE);}
"("    return(LPAREN);
"<"    {return(LT);}
"-"     {return(MINUS);}
"<>"    {return(NOTEQUAL);}
"+"    {return(PLUS);}
"]"    return(RSQBRACK);
")"    return(RPAREN);
";"    return(SEMICOLON);
"/"    {return(SLASH);}
"*"    {return(STAR);}
"**"   {return(STARSTAR);}
"->"   |
"^"    return(UPARROW);
"~"	return(BITNOT);
"!"	return(EXCLA);
"|"	return(BITOR);
"&"	return(BITAND);
"$"	return(DOLLAR);
"%"	return(PERCENT);
"#"	return(HASH);
"@"	return(ADDROF);

"(*"   |
"{"  |
"//"   { register int c;
     while ((c = input()))
     {
      if (c == '}' && yytext[0] == '{')
       break;
      else if (c == '*' && yytext[0] != '{')
      {
       if ((c = input()) == ')')
        break;
       else
        unput (c);
      }
      else if (c == '\n') {
       line_number++;
	if(yytext[0] == '/')
		break;
      }
     }
    }


'({single_quotes}|'')+'  {  strcpy(yylval.name,yytext);return(CHAR_STRING);}


{eol}		line_number++;
[\t ]+		 /* ignore */

{character}	{printf("\n ** Illegal Character %c at line number %d ** \n",yytext[0],line_number);}

%%
