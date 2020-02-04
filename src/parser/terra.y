%{ 
    #include "index.h"
    int yylex();
    // | LET NAME ASIGN exp SEMI { printf("%s",%2); }
    
    //! %parse-param {}
%}


%union{
    struct astNode *node;
    int number;
};

%token <number> NUMBER // 

%token ADD SUB MUL DIV// operator

%token EQUAL_TO LESS_THAN // comperator

%token IF // condition

%token BUILTIN_PRINT // builtin func

%token OPEN_BRACKET CLOSE_BRACKET OPEN_CURRLY_BRACKET CLOSE_CURRLY_BRACKET // ( ) { }

%token ASIGN // =

%token SEMI EOL // kinda EOL token

// set priority of opeartor lower greater
%right ASIGN EQUAL_TO LESS_THAN
%left ADD SUB
%left MUL DIV

%type <node> exp stmt builtin cmp listStmt ifStmt// 

%start program  // start rule

%%

program:
    | program stmt EOL { eval($2); deleteAST($2); }
    ;

stmt: exp SEMI
    | builtin SEMI
    | ifStmt
    ;

listStmt: stmt
    ;  

ifStmt: IF OPEN_BRACKET cmp CLOSE_BRACKET OPEN_CURRLY_BRACKET listStmt CLOSE_CURRLY_BRACKET { $$ = createASTFlow(toFlowToken("if"),$3, $6, NULL); }
    ;

cmp: exp
    | exp EQUAL_TO exp   { $$ = createASTCmp(toCmpToken("=="),$1, $3);}
    | exp LESS_THAN exp { $$ = createASTCmp(toCmpToken("<"),$1, $3);}
    ;

builtin: BUILTIN_PRINT OPEN_BRACKET exp CLOSE_BRACKET { $$ = createASTBuiltin(toBuiltin("print"),$3); }
    ;

exp: NUMBER       { $$ = createASTIntConst($1); }
    | exp ADD exp { $$ = createAST(toTypeToken('+'),$1, $3); }
    | exp SUB exp { $$ = createAST(toTypeToken('-'),$1, $3); }
    | exp MUL exp { $$ = createAST(toTypeToken('*'),$1, $3); }
    | exp DIV exp { $$ = createAST(toTypeToken('/'),$1, $3); }
    ;

%%