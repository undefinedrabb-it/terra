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


    // "=" {	printf("ASSIGNMENT ");	}

    // "(" {	printf("OPEN_BRACKET ");	}
    // ")" {	printf("CLOSE_BRACKET ");	}

    // "{" {	printf("OPEN_CURRLY_BRACKET ");	}
    // "}" {	printf("CLOSE_CURRLY_BRACKET ");	}

    // {ID}+ {		printf("ID ");	}


    // [ \t\r\f]+

    // "//".*"\n" {lineno += 1; }

    // "\n" {	printf("\n");lineno += 1; }

    // .	{ yyerror("Unrecognized character"); }

    // ID [a-zA-Z][a-zA-Z0-9]*

%}

DIGIT [0-9]

%%  

"+" { return ADD;   }
"-" { return SUB;   }
"*" { return MUL;   }
"/" { return DIV;   }

[1-9]{DIGIT}* { yylval.number = atoi(yytext); return NUMBER;	}

";" { return SEMI;  }
"\n" {yylineno += 1;}

[ \t] {}

.         { yyerror("Unknown character %d",yylineno);}

%% 


