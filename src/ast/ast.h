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
    Builtin,
    Cmp,
    Flow,
} typeToken;

// TODO feature scan
typedef enum builtin
{
    print
} builtin;

// TODO feature <= > >= ! and or
typedef enum cmpToken
{
    Equal,
    Less
} cmpToken;

// TODO feature for{} while{} do{}while
typedef enum flowToken {
    If
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

// builtin toBuiltin(char *name);

astNode *createAST(typeToken type, astNode *left, astNode *right);
astNode *createASTCmp(cmpToken type, astNode *left, astNode *right);
astNode *createASTFlow(flowToken type, astNode *cond, astNode *body, astNode *optional);
astNode *createASTIntConst(int value);
astNode *createASTBuiltin(builtin builtinToken, astNode *left);

// tmp only int because its easier than complex struct
int eval(astNode *node);

astNode *deleteAST(astNode *node);

#endif // AST_H