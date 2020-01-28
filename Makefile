CC = gcc
FLEX = lex
YYAC = bison

SRC = src/
BUILD = build/
OBJ = $(BUILD)obj/
OUT = $(BUILD)out/

all: cc

lexer: $(SRC)terra.l
	$(FLEX) -I -o $(OBJ)lex.yy.c  $(SRC)terra.l 

parser: $(SRC)terra.y
	$(YYAC) -d -o $(OBJ)terra.tab.c $(SRC)terra.y

cc: parser lexer
	$(CC) $(SRC)terra.c $(OBJ)lex.yy.c $(OBJ)terra.tab.c -o $(OUT)terra -lfl

clean:
	rm $(OBJ)* $(OUT)terra