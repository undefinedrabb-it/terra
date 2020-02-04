%option noyywrap nodefault yylineno
%{
    #include "terra.tab.h"
    #include "index.h"

    // "let" {	printf("LET ");	}
    // "while" {	printf("WHILE ");	}


// {ID} { yylval.s = atoi(yytext); return NAME;}
%}

DIGIT [0-9]
ID [a-zA-Z][a-zA-Z0-9]*

%%  

"+" { return ADD;   }
"-" { return SUB;   }
"*" { return MUL;   }
"/" { return DIV;   }

"==" {	return EQUAL_TO;	}
"<" {	return LESS_THAN;	}

"if" {	return IF;	}

"print" {   return BUILTIN_PRINT; }

"("     {	return OPEN_BRACKET;	}
")"     {	return CLOSE_BRACKET;	}
"{"     {	return OPEN_CURRLY_BRACKET;	}
"}"     {	return CLOSE_CURRLY_BRACKET; }

{DIGIT}* { yylval.number = atoi(yytext); return NUMBER;	}


";" { return SEMI;  }
"\n" {yylineno += 1; return EOL;}

[ \t] {}

.         { yyerror("Unknown character %d",yylineno);}

%% 


