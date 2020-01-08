CC = gcc 
FLAG = -std=c11 -Wall -Wextra -pedantic -Wfloat-equal -Winit-self -Wuninitialized $(DEBUG) 
DEBUG = -g3
OPTMIZE = -O3
SANITIZE = -fsanitize=leak -fno-common -fno-omit-frame-pointer -fsanitize=address -fsanitize=undefined -fstack-protector-all

BUILD = build/
OUT = $(BUILD)out/
OBJ = $(BUILD)obj/

SRC = src/
LEXER = $(SRC)lexer/
DEP = dependency/
SDS = $(DEP)sds/



all:  main.o

main.o: sds.o lexer.o lexerList.o $(SRC)main.c $(SRC)index.h
	$(CC) $(OBJ)sds.o $(OBJ)lexer.o $(OBJ)lexerList.o $(SRC)main.c -o $(OUT)terra $(FLAG) $(SANITIZE)

# LEXER

lexer.o: $(LEXER)lexer.c $(SRC)index.h $(LEXER)lexer.h 
	$(CC) $(LEXER)lexer.c -c -o $(OBJ)lexer.o $(FLAG) $(SANITIZE)

lexerList.o: $(LEXER)lexerList.c $(SRC)index.h $(LEXER)lexerList.h $(LEXER)lexer.h 
	$(CC) $(LEXER)lexerList.c -c -o $(OBJ)lexerList.o $(FLAG) $(SANITIZE)

# dependency

sds.o: $(SDS)sds.c $(SDS)sdsalloc.h $(SDS)sds.h
	$(CC) $(SDS)sds.c -c -o $(OBJ)sds.o
	
# utils

clear:
	rm -f build/obj/* build/out/*