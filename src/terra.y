%{
    #include <stdio.h>
    #include <terra.h>
    int yylex();
%}
%union{
    int number;
};
%token <number> NUMBER

%token ADD SUB MUL

%token SEMI

%left ADD SUB
%left MUL DIV

%type <number> exp

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