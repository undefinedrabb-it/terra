#ifndef LEXER
#define LEXER

#include "../index.h"
// #include "lexerList.h"

typedef enum
{
    Semicon,
    Assigment,
    Braket,
    Label,
    Value,
    Conditon,
    Comment
} lexerToken;

void lexer();

#endif