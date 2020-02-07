#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "index.h"
#include "symbol.h"

#define FIXED_SIZE_SYMBOL_TABLE_SIZE 5000

// TODO final form hashTable not a simple table
typedef struct symbolTable
{
    size_t size;      // len of symTab
    symbol **symbols; // symbols
    size_t numOfSymbols; // number of symbols //! temporary
} symbolTable;

symbolTable *createSymbolTable(size_t size);

symbolTable *deleteSymbolTable(symbolTable *symTab);

#endif // SYMBOL_TABLE_H