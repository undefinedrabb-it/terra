CC = gcc
FLEX = lex
YYAC = bison

YYFLAG = -L c -g -d
CCFLAG = -Wall -Wextra -pedantic -std=c11 -Wfloat-equal -Winit-self -g3
SANITAZE = 
a = -Wuninitialized -fsanitize=leak -fno-common -fno-omit-frame-pointer -fsanitize=address -fsanitize=undefined -fstack-protector-all

SRC = src/
CORE = $(SRC)core/
LEXER = $(SRC)lexer/
PARSER = $(SRC)parser/
UTILS = $(SRC)utils/
AST = $(SRC)ast/

BUILD = build/
OBJ = $(BUILD)obj/
OUT = $(BUILD)out/
GRAPH = $(OUT)graph/

all: cc graph

graph:
	dot -Tpng $(OBJ)terra.dot > $(GRAPH)automatonGraph.png

header:
	cp $(SRC)index.h $(OBJ)
	cp $(CORE)terra.h $(OBJ)
	cp $(UTILS)utils.h $(OBJ)
	cp $(AST)ast.h $(OBJ)

lexer: header
	$(FLEX) -o $(OBJ)lex.yy.c $(LEXER)terra.l

parser: header
	$(YYAC) $(YYFLAG) -o $(OBJ)terra.tab.c $(PARSER)terra.y

utils: header
	$(CC) -Ibuild/obj $(CCFLAG) $(SANITAZE) -c -o $(OBJ)utils.o $(UTILS)utils.c

ast: header
	$(CC) -Ibuild/obj $(CCFLAG) $(SANITAZE) -c -o $(OBJ)ast.o $(AST)ast.c

core: header
	$(CC) -Ibuild/obj $(CCFLAG) $(SANITAZE) -c -o $(OBJ)core.o $(CORE)terra.c

cc: parser lexer utils ast core
	$(CC) -Ibuild/obj -w $(SANITAZE) $(OBJ)core.o $(OBJ)lex.yy.c $(OBJ)terra.tab.c $(OBJ)utils.o $(OBJ)ast.o -o $(OUT)terra

clean:
	rm $(OBJ)* $(OUT)terra $(GRAPH)*