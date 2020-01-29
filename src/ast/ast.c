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

builtin toBuiltin(char *name)
{
    if (strcmp(name, "print") == 0)
        return print;
    else
    {
        // TODO handle error
        yyerror("unknown builtin %s", name);
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

astNode *createASTIntConst(int value)
{
    astIntConst *node = (astIntConst *)malloc(sizeof(astIntConst));

    // TODO check if node is create

    node->nodeType = Constant;
    node->value = value;

    return (astNode *)node;
}

astNode *createASTBuiltin(builtin builtinToken, astNode *left)
{
    astBuiltin *node = (astBuiltin *)malloc(sizeof(astBuiltin));

    // TODO check if node is create

    node->nodeType = Builtin;
    node->left = left;
    node->builtinToken = builtinToken;

    return (astNode *)node;
}

int callBuiltin(astNode *node)
{
    int value;
    switch (((astBuiltin *)node)->builtinToken)
    {
    case print:
        printf("%d\n", eval(((astBuiltin *)node)->left));
        break;

    default:
        yyerror("unknown builtin func %d", ((astBuiltin *)node)->builtinToken);
        break;
    }

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
    case Builtin:
        value = callBuiltin(node);
    case Constant:
        value = ((astIntConst *)node)->value;
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

    case Builtin:

        deleteAST(node->left);

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
