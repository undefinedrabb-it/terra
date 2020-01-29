#ifndef SYMBOL_H
#define SYMBOL_H

#include "index.h"

typedef struct symbol
{
    char *name;
    int value; // temporary value
    // astNode* func; // TODO this <== its means aaaaa function
    struct symbol *next;
} symbol;

symbol *createSymbol(char *name, int value);

symbol *addSymbol(symbol *root, char *name, int value);

symbol *findSymbolByName(symbol *node, char *name);

symbol *deleteSymbol(symbol *sym);


#endif // SYMBOL_H