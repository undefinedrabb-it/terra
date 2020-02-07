#include "astHelper.h"

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
    case 'L':
        return ListStmt;
    default:
        // TODO handle error
        yyerror("unknown token %c", value);
        break;
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
