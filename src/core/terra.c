#include "terra.h"

extern FILE *yyin;
int yylex();
int yyparse();


int main()
{
    yyin = fopen("test/easy", "r");
    
    if (yyin == NULL)
        perror("Error");

    yyparse();
    fclose(yyin);

    return 0;
}