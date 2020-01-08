#include "index.h"
#include "lexer/lexer.h"
#include "lexer/lexerList.h"

#include "../dependency/sds/sds.h"
//lexer

// typedef enum
// {
//     Comment,
//     Loop,
//     Assigment,
//     Conditon,

// } ParserToken;

// typedef struct ParserNode
// {
//     ParserToken token;
// } ParserNode;

int main(int argc, char **argv)
{
    char *str = "//aaaaaaaa\na=5;\nif(a<6)\n{\n    print(a);\n};";
    //lexer
    // lexer(str);
    lexerList *head = createHead();
    // head = pushBack(head, Assigment, "=");
    // showList(head);
    sds a = sdsnew("abc");
    //parser

    //compiler

    //interpreterr

    // sprzątanko
    deleteList(head);
    return 0;
}