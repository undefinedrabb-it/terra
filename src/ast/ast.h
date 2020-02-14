#ifndef AST_H
#define AST_H

#include "index.h"

// so that is basicly shitty idea but for now stay compatible
typedef enum typeToken
{
    Constant,
    Add,
    Sub,
    Mul,
    Div,
    ListStmt,
    Builtin,
    Cmp,
    Flow,
    Assignment,
    Reference
} typeToken;

// TODO feature scan
typedef enum builtin
{
    print,
    scan
} builtin;

// TODO feature <= > >= ! and or
typedef enum cmpToken
{
    Equal,
    Less,
    EqualOrLess
} cmpToken;

// TODO feature for{} do{}while
typedef enum flowToken
{
    If,
    While
} flowToken;

typedef struct astNode
{
    typeToken nodeType;
    struct astNode *left;
    struct astNode *right;
} astNode;

typedef struct astCmp
{
    typeToken nodeType;
    cmpToken cmpType;
    astNode *left;
    astNode *right;
} astCmp;

typedef struct astAssingment
{
    typeToken nodeType;
    struct symbol *left;
    astNode *right;
} astAssingment;

typedef struct astFlow
{
    typeToken nodeType;
    flowToken flowType;
    astNode *cond;
    astNode *body;
    astNode *optional;

} astFlow;

typedef struct astBuiltin
{
    typeToken nodeType;
    builtin builtinToken;
    astNode *left;

} astBuiltin;

typedef struct astIntConst
{
    typeToken nodeType;
    int value;
} astIntConst;

astNode *createAST(typeToken type, astNode *left, astNode *right);
astNode *createASTCmp(cmpToken type, astNode *left, astNode *right);
astNode *createASTFlow(flowToken type, astNode *cond, astNode *body, astNode *optional);
astNode *createASTIntConst(int value);
astNode *createASTBuiltin(builtin builtinToken, astNode *left);
astNode *createASTAssignment(struct symbol *left, astNode *right, struct symbolTable *symTab);
astNode *createASTAssignUpdate(struct symbol *left, astNode *right, struct symbolTable *symTab);
astNode *createASTRef(struct symbol *left, struct symbolTable *symTab);

// tmp only int because its easier than complex struct
int eval(astNode *node, struct symbolTable *symTab);

astNode *deleteAST(astNode *node);

#endif // AST_H