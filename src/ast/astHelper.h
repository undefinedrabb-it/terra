#ifndef AST_HELPER_H
#define AST_HELPER_H

#include "ast.h"

builtin toBuiltin(char *name);
typeToken toTypeToken(int value);
cmpToken toCmpToken(char *name);
flowToken toFlowToken(char*name);


#endif // AST_HELPER_H