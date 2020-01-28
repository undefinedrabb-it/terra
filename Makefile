CC = gcc
FLEX = lex
YYAC = bison

SRC = src/
BUILD = build/
OBJ = $(BUILD)obj/
OUT = $(BUILD)out/
GRAPH = $(OUT)graph/

all: cc graph

graph:
	dot -Tpng $(OBJ)terra.dot > $(GRAPH)automatonGraph.png

header:
	cp $(SRC)index.h $(OBJ)
	cp $(SRC)terra.h $(OBJ)

lexer: header $(SRC)terra.l 
	$(FLEX) -o $(OBJ)lex.yy.c  $(SRC)terra.l

parser: header $(SRC)terra.y
	$(YYAC) -g -d -o $(OBJ)terra.tab.c $(SRC)terra.y

cc: parser lexer
	$(CC) $(SRC)terra.c $(OBJ)lex.yy.c $(OBJ)terra.tab.c -o $(OUT)terra -lfl

clean:
	rm $(OBJ)* $(OUT)terra $(GRAPH)*

	