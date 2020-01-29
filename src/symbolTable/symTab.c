#include "symTab.h"

symbolTable *createSymbolTable(size_t size)
{
    symbolTable *symTab = (symbolTable *)malloc(sizeof(symbolTable));
    // TODO check if symTab is create
    symTab->size = size;

    symTab->symbols = (symbol *)malloc(sizeof(symbol) * size);
    // TODO check if symbols is create

    for (size_t i = 0; i < symTab->size; i++)
        symTab->symbols[i] = NULL;

    return symTab;
}


symbolTable *deleteSymbolTable(symbolTable *symTab)
{
    for (size_t i = 0; i < symTab->size; i++)
        symTab->symbols[i] = deleteSymbol(symTab->symbols[i]); // TODO check if symbols is delete
    return (symbolTable *)freeAndNullify(symTab);
}