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

%token NAME

%token BUILTIN_PRINT // builtin func

%token OPEN_BRACKET CLOSE_BRACKET // ( )

%token ADD SUB MUL // operator

%token ASIGN

%token SEMI // kinda EOL token

// set priority of opeartor lower greater
%right ASIGN
%left ADD SUB
%left MUL DIV

%type <node> exp stmt builtin// 

%start program  // start rule

%%

program:
    | program stmt SEMI { eval($2); deleteAST($2); }
    ;

stmt: exp
    | builtin
    ;

builtin: BUILTIN_PRINT OPEN_BRACKET exp CLOSE_BRACKET { $$ = createASTBuiltin(toBuiltin("print"),$3); }
    ;

exp: NUMBER       { $$ = createASTIntConst($1); }
    | exp ADD exp { $$ = createAST(toTypeToken('+'),$1,$3); }
    | exp SUB exp { $$ = createAST(toTypeToken('-'),$1,$3); }
    | exp MUL exp { $$ = createAST(toTypeToken('*'),$1,$3); }
    ;

%%