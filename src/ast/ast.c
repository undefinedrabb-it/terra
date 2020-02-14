#include "ast.h"

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

astNode *createASTAssignment(struct symbol *left, astNode *right, struct symbolTable *symTab)
{
    astAssingment *node = malloc(sizeof(astAssingment));

    node->nodeType = Assignment;
    node->left = addSymbolToSymbolTable(symTab, left);
    node->right = right;

    return (astNode *)node;
}

astNode *createASTAssignUpdate(struct symbol *left, astNode *right, struct symbolTable *symTab)
{
    astAssingment *node = malloc(sizeof(astAssingment));

    node->nodeType = Assignment;
    char *tmp = (char *)malloc(sizeof(char) * (sizeof(left->name)));
    strcpy(tmp, left->name);
    deleteSymbol(left);
    node->left = getSymbolByName(symTab, tmp);
    freeAndNullify(tmp);
    node->right = right;

    return (astNode *)node;
}

astNode *createASTRef(struct symbol *left, struct symbolTable *symTab)
{
    astAssingment *node = malloc(sizeof(astAssingment));

    node->nodeType = Reference;
    node->left = left;
    node->right = NULL;

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

int callBuiltin(astNode *node, symbolTable *symTab)
{
    int value;
    switch (((astBuiltin *)node)->builtinToken)
    {
    case print:
        printf("%d\n", eval(((astBuiltin *)node)->left, symTab));
        break;
    case scan:
        scanf("%d", &value);
        symbol *tmp = updateSymbolByName(symTab, ((symbol *)((astAssingment *)((astBuiltin *)node)->left)->left)->name,value);
        break;

    default:
        yyerror("unknown builtin func %d", ((astBuiltin *)node)->builtinToken);
        break;
    }
}

int flow(astNode *node, symbolTable *symTab)
{
    switch (((astFlow *)node)->flowType)
    {
    case If:
        if (eval(((astFlow *)node)->cond, symTab))
        {
            eval(((astFlow *)node)->body, symTab);
        }
        // else if (((astFlow *)node)->optional != NULL)
        // {
        //     eval(((astFlow *)node)->optional, symTab);
        // }
        break;

    case While:
        while (eval(((astFlow *)node)->cond, symTab))
        {
            eval(((astFlow *)node)->body, symTab);
        }
        break;

    default:
        yyerror("unknown flow type %d", ((astFlow *)node)->flowType);
        break;
    }
}

int compare(astNode *node, symbolTable *symTab)
{
    int value;
    switch (((astCmp *)node)->cmpType)
    {
    case Equal:
        value = eval(((astCmp *)node)->left, symTab) == eval(((astCmp *)node)->right, symTab);
        break;
    case Less:
        value = eval(((astCmp *)node)->left, symTab) < eval(((astCmp *)node)->right, symTab);
        break;

    default:
        yyerror("unknown comparator  %d", ((astCmp *)node)->cmpType);
        break;
    }
    return value;
}

int eval(astNode *node, symbolTable *symTab)
{
    int value;

    // TODO check if node exist

    switch (node->nodeType)
    {
    case Add:
        value = eval(node->left, symTab) + eval(node->right, symTab);
        break;
    case Sub:
        value = eval(node->left, symTab) - eval(node->right, symTab);
        break;
    case Mul:
        value = eval(node->left, symTab) * eval(node->right, symTab);
        break;
    case Div:
        value = eval(node->left, symTab) / eval(node->right, symTab);
        break;
    case Builtin:
        value = callBuiltin(node, symTab);
        break;
    case Assignment:
        value = ((symbol *)((astAssingment *)node)->left)->value = eval(((astAssingment *)node)->right, symTab);
        break;
    case Reference:
        value = ((symbol *)((astAssingment *)node)->left)->value = findSymbolByNameInTable(symTab, ((symbol *)((astAssingment *)node)->left)->name);
        break;
    case ListStmt:
        eval(node->left, symTab);
        eval(node->right, symTab);
        break;
    case Cmp:
        value = compare(node, symTab);
        break;
    case Flow:
        value = flow(node, symTab);
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

        case ListStmt:

        case Cmp:

            deleteAST(node->left);

            deleteAST(node->right);

            break;

        case Flow:

            deleteAST(((astFlow *)node)->cond);
            deleteAST(((astFlow *)node)->body);
            deleteAST(((astFlow *)node)->optional);

            break;

        case Assignment:

            deleteAST((astNode *)node->right);

            break;

        case Builtin:

            deleteAST(node->left);

            break;

        case Reference:

            deleteSymbol(((astAssingment *)node)->left);

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
