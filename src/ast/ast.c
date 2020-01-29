#include "ast.h"

typeToken toTypeToken(int value)
{
    switch (value)
    {
    case '+':
        return Add;
    case '-':
        return Sub;
    case '*':
        return Mul;
    default:
        // TODO handle error 
        yyerror("unknown token %c", value);
        break;
    }
}

astNode *createAST(typeToken type, astNode *left, astNode *right)
{
    astNode *node = (astNode *)malloc(sizeof(astNode));

    // TODO check if node is create

    node->nodeType = type;
    node->left = left;
    node->right = right;

    return node;
}

astNode *createIntConst(int value)
{
    intConst *node = (intConst *)malloc(sizeof(intConst));

    // TODO check if node is create

    node->nodeType = Constant;
    node->value = value;

    return (astNode *)node;
}

int eval(astNode *node)
{
    int value;

    // TODO check if node exist

    switch (node->nodeType)
    {
    case Add:
        value = eval(node->left) + eval(node->right);
        break;
    case Sub:
        value = eval(node->left) - eval(node->right);
        break;
    case Mul:
        value = eval(node->left) * eval(node->right);
        break;
    case Div:
        value = eval(node->left) / eval(node->right);
        break;
    case Constant:
        value = ((intConst *)node)->value;
        break;
    default:
        yyerror("not define node %d", node->nodeType);
        break;
    }

    return value;
}

void deleteAST(astNode *node)
{
    switch (node->nodeType)
    {
    case Add:
    case Sub:
    case Mul:
    case Div:

        deleteAST(node->left);

        deleteAST(node->right);

        break;
    case Constant:
        break;
    default:
        // TODO handle error 
        yyerror("not define node %d", node->nodeType);
        break;
    }

    node = freeAndNullify(node);
    // TODO check if node is free
    
}
