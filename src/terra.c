#include "index.h"

extern FILE *yyin;
int yylex();
int yyparse();

void yyerror(char *s, ...)
{
    va_list ap;
    va_start(ap, s);

    fprintf(stderr, "%d: error: ", yylineno);
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");
};

int main()
{
    yyin = fopen("test/easy", "r");
    if (yyin == NULL)
        perror("Error");

    yyparse();
    fclose(yyin);

    return 0;
}