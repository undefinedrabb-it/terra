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
} typeToken;

typedef struct astNode
{
    typeToken nodeType;
    struct astNode *left;
    struct astNode *right;
} astNode;

typedef struct intConst
{
    typeToken nodeType;
    int value;
} intConst;

typeToken toTypeToken(int value);

astNode *createAST(typeToken token, astNode *left, astNode *right);
astNode *createIntConst(int value);

// tmp only int because its easier than complex struct
int eval(astNode *node);

void deleteAST(astNode *node);

#endif // AST_H