%{ 
    #include "index.h"
    int yylex();
%}

%union{
    int number;
};

%token <number> NUMBER // 

%token ADD SUB MUL // operator

%token SEMI // kinda EOL token

// set priority of opeartor lower greater
%left ADD SUB
%left MUL DIV

%type <number> exp // 

%start program  // start rule

%%

program:
    | program exp SEMI { printf("%d\n", $2); }
    ;

exp: NUMBER
    | exp ADD exp { $$ = $1 + $3 ; }
    | exp SUB exp { $$ = $1 - $3 ; }
    | exp MUL exp { $$ = $1 * $3 ; }
    ;

%%