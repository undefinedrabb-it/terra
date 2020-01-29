%option noyywrap nodefault yylineno
%{
    #include "terra.tab.h"
    #include "index.h"

    // "let" {	printf("LET ");	}
    // "if" {	printf("IF ");	}
    // "while" {	printf("WHILE ");	}

    // "print" {printf("PRINT ");}

    // ";" {	printf("SEMICOLON ");	}

    // "==" {	printf("EQUAL_TO ");	}
    // "<=" {	printf("LESS_THAN_OR_EQUAL_TO ");	}


    // "{" {	printf("OPEN_CURRLY_BRACKET ");	}
    // "}" {	printf("CLOSE_CURRLY_BRACKET ");	}

// {ID} { yylval.s = atoi(yytext); return NAME;}
%}

DIGIT [0-9]
ID [a-zA-Z][a-zA-Z0-9]*

%%  

"+" { return ADD;   }
"-" { return SUB;   }
"*" { return MUL;   }
"/" { return DIV;   }

"print" {   return BUILTIN_PRINT; }
"("     {	return OPEN_BRACKET;	}
")"     {	return CLOSE_BRACKET;	}

[1-9]{DIGIT}* { yylval.number = atoi(yytext); return NUMBER;	}


";" { return SEMI;  }
"\n" {yylineno += 1;}

[ \t] {}

.         { yyerror("Unknown character %d",yylineno);}

%% 


