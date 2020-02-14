#include "symbol.h"

symbol *createSymbol(char *name, int value)
{
    symbol *sym = (symbol *)malloc(sizeof(symbol));
    sym->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(sym->name, name);
    sym->value = value;
    // sym->next = NULL;

    return sym;
}

symbol *addSymbol(symbol *root, char *name, int value)
{
    return createSymbol(name, value);
}

// symbol *addSymbol(symbol *root, char *name, int value)
// {
// return addSymbolRec(root, root, name, value);
// }

// symbol *addSymbolRec(symbol *root, symbol *node, char *name, int value)
// {
//     if (node == NULL)
//     {
//         node = createSymbol(name, value);
//         return root;
//     }
//     return addSymbolRec(root, node->next, name, value);
// }

symbol *findSymbolByName(symbol *node, char *name)
{
    // if (node != NULL)
    // {
    if (strcmp(node->name, name) == 0)
        return node;
    // }
    else
        return NULL;
    // return findSymbolByName(node->next, name);
}

symbol *deleteSymbol(symbol *sym)
{
    // if (sym != NULL)
    // {
    //     sym->name = freeAndNullify(sym->name); // TODO check if name is delete
    //     deleteSymbol(sym->next);
    // }
    freeAndNullify(sym->name);

    return (symbol *)freeAndNullify(sym); // TODO check if symbol is delete
}

symbol *updateSymbolValue(symbol *sym, int value)
{
    sym->value = value;
    return sym;
}