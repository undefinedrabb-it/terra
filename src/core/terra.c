#include "terra.h"

extern FILE *yyin;
int yylex();
int yyparse();

#define VERSION "v1.0.0"

FILE *prepFile(const char *inName)
{
    FILE *in = fopen(inName, "r");

    if (in == NULL)
        perror("Error");

    FILE *out = tmpfile();

    fprintf(out, "%s\n", START_PROGRAM);

    fseek(in, 0, SEEK_END);
    long size = ftell(in);
    fseek(in, 0, SEEK_SET);

    char *buffer = (char *)malloc(sizeof(char) * size);
    // TODO check if buffer is create
    size_t result = fread(buffer, sizeof(char), size, in);
    // TODO check result
    result = fwrite(buffer, sizeof(char), size, out);
    // TODO check result
    buffer = freeAndNullify(buffer);
    // TODO check if is delete

    fprintf(out, "\n%s", END_PROGRAM);

    rewind(out);

    return out;
}

int main(int argc, const char **argv)
{
    const char *url = "path/to/file";
    flag_str(&url, "input", "Input file");
    flag_parse(argc, argv, VERSION);

    yyin = prepFile(url);
    // yyin = prepFile("test/fib.js");
    symbolTable *symTab = createSymbolTable(500);
    yyparse(symTab);

    fclose(yyin);

    deleteSymbolTable(symTab);

    return 0;
}
