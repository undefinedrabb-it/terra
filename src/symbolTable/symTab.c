#include "symTab.h"

symbolTable *createSymbolTable(size_t size)
{
    symbolTable *symTab = (symbolTable *)malloc(sizeof(symbolTable));
    // TODO check if symTab is create
    symTab->size = size;

    symTab->numOfSymbols = 0;

    symTab->symbols = (symbol **)malloc(sizeof(symbol *) * size);
    // TODO check if symbols is create

    for (size_t i = 0; i < symTab->size; i++)
        symTab->symbols[i] = NULL;

    return symTab;
}

struct symbol *getSymbolByName(symbolTable *symTab, char *name)
{
    for (size_t i = 0; i < symTab->numOfSymbols; i++)
        if (findSymbolByName(symTab->symbols[i], name) != NULL)
            return symTab->symbols[i];

    return NULL;
}

symbol *addToSymbolTable(symbolTable *symTab, char *name, int value)
{
    if (symTab->numOfSymbols + 1 < symTab->size)
        symTab->symbols[symTab->numOfSymbols++] = addSymbol(NULL, name, value);

    return symTab->symbols[symTab->numOfSymbols - 1];
}

symbol *addSymbolToSymbolTable(symbolTable *symTab, symbol *sym)
{
    if (symTab->numOfSymbols + 1 < symTab->size)
        symTab->symbols[symTab->numOfSymbols++] = sym;

    return symTab->symbols[symTab->numOfSymbols - 1];
}

int findSymbolByNameInTable(symbolTable *symTab, char *name)
{
    for (size_t i = 0; i < symTab->numOfSymbols; i++)
        if (findSymbolByName(symTab->symbols[i], name) != NULL)
            return symTab->symbols[i]->value;

    return NULL;
}

symbolTable *deleteSymbolTable(symbolTable *symTab)
{
    for (size_t i = 0; i < symTab->numOfSymbols; i++)
        symTab->symbols[i] = deleteSymbol(symTab->symbols[i]); // TODO check if symbols is delete

    freeAndNullify(symTab->symbols);

    return (symbolTable *)freeAndNullify(symTab);
}

struct symbol *updateSymbolByName(symbolTable *symTab, char *name, int value)
{
    for (size_t i = 0; i < symTab->numOfSymbols; i++)
        if (findSymbolByName(symTab->symbols[i], name) != NULL)
            return updateSymbolValue(symTab->symbols[i], value);

    return NULL;
}