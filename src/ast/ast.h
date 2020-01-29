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
} typeToken;

typedef enum builtin
{
    print
} builtin;

typedef struct astNode
{
    typeToken nodeType;
    struct astNode *left;
    struct astNode *right;
} astNode;

typedef struct astBuiltin
{
    typeToken nodeType;
    struct astNode *left;
    builtin builtinToken;

} astBuiltin;

typedef struct astIntConst
{
    typeToken nodeType;
    int value;
} astIntConst;

typeToken toTypeToken(int value);

astNode *createAST(typeToken type, astNode *left, astNode *right);
astNode *createASTIntConst(int value);
astNode *createASTBuiltin(builtin builtinToken, astNode *left);

// tmp only int because its easier than complex struct
int eval(astNode *node);

void deleteAST(astNode *node);

#endif // AST_H