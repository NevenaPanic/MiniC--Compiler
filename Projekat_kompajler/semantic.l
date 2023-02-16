%option noyywrap yylineno

%{
   #include <string.h>
   #include "semantic.tab.h"
   #include "defs.h"
%}

%%

[ \t\n]+             { /* skip */ }

"int"                { yylval.i = INT;  return _TYPE; }
"unsigned"           { yylval.i = UINT; return _TYPE; }
"void"				 { yylval.i = VOID; return _TYPE; }
"if"                 { return _IF; }
"else"               { return _ELSE; }
"return"             { return _RETURN; }
","					 { return _COMMA; }
"for"				 { return _FOR; }

"branch"			 { return _BRANCH; }
"first"				 { return _FIRST; }
"second"			 { return _SECOND; }
"third"				 { return _THIRD; }
"otherwise"			 { return _OTHERWISE; }
"end_branch"		 { return _END_BRANCH; }

"?"					 { return _Q_MARK; }
":"					 { return _TWO_DOTS; }
"("                  { return _LPAREN; }
")"                  { return _RPAREN; }
"{"                  { return _LBRACKET; }
"}"                  { return _RBRACKET; }
";"                  { return _SEMICOLON; }
"="                  { return _ASSIGN; }

"+"                  { return _ADD; }
"-"                  { return _SUB; }
"*"					 { return _MUL; }
"/"					 { return _DIV; }
"^"					 { return _POW; }
"++"				 { return _INC; }

"<"                  { yylval.i = LT; return _RELOP; }
">"                  { yylval.i = GT; return _RELOP; }
"<="                 { yylval.i = LE; return _RELOP; }
">="                 { yylval.i = GE; return _RELOP; }
"=="                 { yylval.i = EQ; return _RELOP; }
"!="                 { yylval.i = NE; return _RELOP; }

[a-zA-Z][a-zA-Z0-9]* { yylval.s = strdup(yytext); 
                       return _ID; }
[+-]?[0-9]{1,10}     { yylval.s = strdup(yytext); 
                       return _INT_NUMBER;}
[0-9]{1,10}[uU]      { yylval.s = strdup(yytext); 
                       yylval.s[yyleng-1] = 0;
                       return _UINT_NUMBER;}

\/\/.*               { /* skip */ }
"/*"([^*]|"\n"|(\*+([^*/]|"\n")))*"*"+"/" { /* skip */ }

.                    { printf("\nline %d: ERROR: lexycal error on char [%c]\n", yylineno, *yytext);}


%%
