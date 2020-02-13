%{ 
    #include "index.h"
    int yylex();
    // | LET NAME ASIGN exp SEMI { printf("%s",%2); }
    
%}

%parse-param {struct symbolTable *symTab}


%union{
    struct astNode *node;
    struct symbol *symbol;
    int number;
};

%token START_TOKEN END_TOKEN

%token LET 

%token <symbol> NAME

%token <number> NUMBER // 

%token ADD SUB MUL DIV// operator

%token EQUAL_TO LESS_THAN // comperator

%token IF // condition

%token WHILE // while loop

%token BUILTIN_PRINT // builtin func

%token OPEN_BRACKET CLOSE_BRACKET OPEN_CURRLY_BRACKET CLOSE_CURRLY_BRACKET // ( ) { }

%token ASSIGN // =

%token SEMI // kinda EOL token

// set priority of opeartor lower greater
%right ASIGN EQUAL_TO LESS_THAN
%left ADD SUB
%left MUL DIV

%type <node> exp stmt builtin cmp listStmt ifStmt assignment loop // 

%start program  // start rule

%%

program: START_TOKEN listStmt END_TOKEN { eval($2,symTab); deleteAST($2); }
    ;

assignment: LET NAME ASSIGN exp { $$ = createASTAssignment($2,$4,symTab); }
    ;

stmt: builtin SEMI
    | ifStmt
    | assignment SEMI 
    | loop
    | NAME ASSIGN exp SEMI { $$ = createASTAssignUpdate($1,$3,symTab); }
    ;

loop: WHILE OPEN_BRACKET cmp CLOSE_BRACKET OPEN_CURRLY_BRACKET listStmt CLOSE_CURRLY_BRACKET { $$ = createASTFlow(toFlowToken("while"), $3, $6, NULL); }

listStmt:               { $$= NULL; }
        | stmt listStmt { if($2==NULL)
                                $$=$1;
                            else 
                                $$=createAST(toTypeToken('L'),$1,$2); 
                        }
    ;  

ifStmt: IF OPEN_BRACKET cmp CLOSE_BRACKET OPEN_CURRLY_BRACKET listStmt CLOSE_CURRLY_BRACKET { $$ = createASTFlow(toFlowToken("if"), $3, $6, NULL); }
    ;

cmp: exp
    | exp EQUAL_TO exp   { $$ = createASTCmp(toCmpToken("=="),$1, $3);}
    | exp LESS_THAN exp { $$ = createASTCmp(toCmpToken("<"),$1, $3);}
    ;

builtin: BUILTIN_PRINT OPEN_BRACKET exp CLOSE_BRACKET { $$ = createASTBuiltin(toBuiltin("print"),$3); }
    ;

exp: NAME         { $$ = createASTRef($1,symTab); }
    | NUMBER      { $$ = createASTIntConst($1); }
    | exp ADD exp { $$ = createAST(toTypeToken('+'),$1, $3); }
    | exp SUB exp { $$ = createAST(toTypeToken('-'),$1, $3); }
    | exp MUL exp { $$ = createAST(toTypeToken('*'),$1, $3); }
    | exp DIV exp { $$ = createAST(toTypeToken('/'),$1, $3); }
    ;

%%