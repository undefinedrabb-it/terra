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
    case '/':
        return Div;
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

cmpToken toCmpToken(char *name)
{
    if (strcmp(name, "==") == 0)
        return Equal;
    if (strcmp(name, "<") == 0)
        return Less;
    else
    {
        // TODO handle error
        yyerror("unknown comparator %s", name);
    }
}

flowToken toFlowToken(char *name)
{
    if (strcmp(name, "if") == 0)
        return If;
    else
    {
        // TODO handle error
        yyerror("unknown flow func %s", name);
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

astNode *createASTCmp(cmpToken type, astNode *left, astNode *right)
{
    astCmp *node = (astCmp *)malloc(sizeof(astCmp));

    // TODO check if node is create

    node->nodeType = Cmp;
    node->cmpType = type;
    node->left = left;
    node->right = right;

    return (astNode *)node;
}

astNode *createASTIntConst(int value)
{
    astIntConst *node = (astIntConst *)malloc(sizeof(astIntConst));

    // TODO check if node is create

    node->nodeType = Constant;
    node->value = value;

    return (astNode *)node;
}

astNode *createASTFlow(flowToken type, astNode *cond, astNode *body, astNode *optional)
{
    astFlow *node = (astFlow *)malloc(sizeof(astFlow));

    // TODO check if node is create

    node->nodeType = Flow;
    node->flowType = type;
    node->cond = cond;
    node->body = body;
    node->optional = optional;

    return (astNode *)node;
}

astNode *createASTBuiltin(builtin builtinToken, astNode *left)
{
    astBuiltin *node = (astBuiltin *)malloc(sizeof(astBuiltin));

    // TODO check if node is create

    node->nodeType = Builtin;
    node->builtinToken = builtinToken;
    node->left = left;

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

int compare(astNode *node)
{
    int value;
    switch (((astCmp *)node)->cmpType)
    {
    case Equal:
        value = eval(((astCmp *)node)->left) == eval(((astCmp *)node)->right);
        break;
    case Less:
        value = eval(((astCmp *)node)->left) < eval(((astCmp *)node)->right);
        break;

    default:
        yyerror("unknown comperator  %d", ((astCmp *)node)->cmpType);
        break;
    }
    return value;
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
        break;
    case Cmp:
        value = compare(node);
        break;
    case Flow:
        if (eval(((astFlow *)node)->cond))
        {
            eval(((astFlow *)node)->body);
        }
        else if (((astFlow *)node)->optional != NULL)
        {
            eval(((astFlow *)node)->optional);
        }
        break;
    case Constant:
        value = ((astIntConst *)node)->value;
        break;

    default:
        yyerror("not define node %d", node->nodeType);
        break;
    }

    return value;
}

astNode *deleteAST(astNode *node)
{
    if (node != NULL)
        switch (node->nodeType)
        {
        case Add:
        case Sub:
        case Mul:
        case Div:

        case Cmp:

            deleteAST(node->left);

            deleteAST(node->right);

            break;

        case Flow:

            deleteAST(((astFlow *)node)->cond);
            deleteAST(((astFlow *)node)->body);
            deleteAST(((astFlow *)node)->optional);

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

    return (astNode *)freeAndNullify(node);
    // TODO check if node is free
}
