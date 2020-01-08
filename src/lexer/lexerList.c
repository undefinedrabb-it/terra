#include "lexerList.h"

lexerList *createHead() { return NULL; }

lexerList *createNode(lexerToken token, char *value)
{
    lexerList *tmp = (lexerList *)malloc(sizeof(lexerList));
    tmp->token = token;
    tmp->value = calloc(strlen(value) + 1, sizeof(char));
    strcpy(tmp->value, value);
    tmp->next = NULL;
    return tmp;
}

void deleteNode(lexerList *el)
{
    free(el->value);
    free(el);
}
lexerList *pushFront(lexerList *list, lexerToken token, char *value)
{
    lexerList *tmp = createNode(token, value);
    if (list == NULL)
        return tmp;
    tmp->next = list;
    return tmp;
}

lexerList *popFront(lexerList *list, int *value)
{
    if (list == NULL)
        return NULL;
    lexerList *tmp = list;
    list = list->next;
    *value = tmp->value;
    deleteNode(tmp);
    return list;
}

lexerList *pushBack(lexerList *list, lexerToken token, char *value)
{
    lexerList *tmp = createNode(token, value);
    lexerList *head = list;
    if (list == NULL)
        return tmp;
    while (list->next != NULL)
        list = list->next;
    list->next = tmp;
    return head;
}

void removeNode(lexerList *previous, lexerList *next)
{
    deleteNode(previous->next);
    previous->next = next;
}

lexerList *popBack(lexerList *list, int *value)
{
    if (list == NULL)
        return NULL;
    lexerList *head = list;
    lexerList *previousNode = list;
    while (list->next != NULL)
    {
        previousNode = list;
        list = list->next;
    }
    *value = list->value;
    if (head == previousNode && head->next == NULL)
    {
        removeNode(head, NULL);
        return NULL;
    }
    removeNode(previousNode, NULL);
    return head;
}

void showList(lexerList *list)
{
    while (list->next != NULL)
    {
        printf("%d|%s->", list->token, list->value);
        list = list->next;
    }
    printf("%d|%s\n", list->token, list->value);
}

void deleteList(lexerList *list)
{
    lexerList *tmp;
    if (list == NULL)
        return;
    while (list->next != NULL)
    {
        tmp = list;
        list = list->next;
        deleteNode(tmp);
    }
    deleteNode(list);
}

// lexerList *filter(lexerList *list, predicate predicate)
// {
//     lexerList *head = createHead();
//     while (list != NULL)
//     {
//         if (!predicate(list->value))
//             head = pushBack(head, list->value);
//         list = list->next;
//     }
//     return head;
// }
