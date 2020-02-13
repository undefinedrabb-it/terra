#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "index.h"
#include "symbol.h"

#define FIXED_SIZE_SYMBOL_TABLE_SIZE 5000

// TODO final form hashTable not a simple table
typedef struct symbolTable
{
    size_t size;             // len of symTab
    struct symbol **symbols; // symbols
    size_t numOfSymbols;     // number of symbols //! temporary
} symbolTable;

symbolTable *createSymbolTable(size_t size);

int findSymbolByNameInTable(symbolTable *symTab, char *name);
struct symbol *GetSymbolByName(symbolTable *symTab, char *name);
struct symbol *addSymbolToSymbolTable(symbolTable *symTab, struct symbol *sym);
struct symbol *addToSymbolTable(symbolTable *symTab, char *name, int value);

symbolTable *deleteSymbolTable(symbolTable *symTab);

#endif // SYMBOL_TABLE_H