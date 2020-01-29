#ifndef UTILS_H
#define UTILS_H

#include "index.h"

extern int yylineno; 

void* freeAndNullify(void*ptr);

void yyerror(char *s, ...);

#endif // UTILS_H