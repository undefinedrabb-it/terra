%{ 
    #include "index.h"
    int yylex();
%}

%union{
    struct astNode *node;
    int number;
};

%token <number> NUMBER // 

%token ADD SUB MUL // operator

%token SEMI // kinda EOL token

// set priority of opeartor lower greater
%left ADD SUB
%left MUL DIV

%type <node> exp // 

%start program  // start rule

%%

program:
    | program exp SEMI { printf("%d\n", eval($2)); }
    ;

exp: NUMBER       { $$ = createIntConst($1); }
    | exp ADD exp { $$ = createAST(toTypeToken('+'),$1,$3); }
    | exp SUB exp { $$ = createAST(toTypeToken('-'),$1,$3); }
    | exp MUL exp { $$ = createAST(toTypeToken('*'),$1,$3); }
    ;

%%