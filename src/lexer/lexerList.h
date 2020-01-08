// singleLinkList
#ifndef SINGLE_LINK_LIST_H
#define SINGLE_LINK_LIST_H

#include "../index.h"
#include "lexer.h"

typedef struct lexerList
{
    char *value;
    lexerToken token;
    struct lexerList *next;
} lexerList;

lexerList *createHead();

lexerList *createNode(lexerToken token, char *value);

void deleteNode(lexerList *el);

lexerList *pushFront(lexerList *list, lexerToken token, char *value);

lexerList *popFront(lexerList *list, int *value);

lexerList *pushBack(lexerList *list, lexerToken token, char *value);

void removeNode(lexerList *previous, lexerList *next);

lexerList *popBack(lexerList *list, int *value);

void showList(lexerList *list);

void deleteList(lexerList *list);

// typedef bool predicate(int);
// lexerList *filter(lexerList *list, predicate predicate);

#endif
