%option noyywrap nodefault yylineno
%{
    #include "terra.tab.h"
    #include "index.h"

    // "while" {	printf("WHILE ");	}

%}

DIGIT [0-9]
ID [a-zA-Z][a-zA-Z0-9]*

%%  

"$$START$$PROGRAM"  { return START_TOKEN;   }
"$$END$$PROGRAM"    { return END_TOKEN;     }

"+"     {  return ADD;   }
"-"     {  return SUB;   }
"*"     {  return MUL;   }
"/"     {  return DIV;   }

"=="    { 	return EQUAL_TO;	}
"<"     {	return LESS_THAN;	}

"if"    {	return IF;	}
"while" {	return WHILE;	}
"let"   {	return LET;	}
"="     {	return ASSIGN; }

"print" {   return BUILTIN_PRINT; }
"scan" {   return BUILTIN_SCAN; }

"("     {	return OPEN_BRACKET;	}
")"     {	return CLOSE_BRACKET;	}
"{"     {	return OPEN_CURRLY_BRACKET;	}
"}"     {	return CLOSE_CURRLY_BRACKET; }

{DIGIT}* { yylval.number = atoi(yytext); return NUMBER;	}
{ID}     { yylval.symbol = createSymbol(yytext,0); return NAME; }


";" { return SEMI;  }
"\n" {yylineno += 1;}

[ \t] {}

.         { yyerror("Unknown character %d %s |",yylineno,yytext);}

%% 


