# USR DOCS
## KEYWORD
 ```
 + - * / == < if while let = print scan $$START$$PROGRAM $$END$$PROGRAM
 ```
 ## GRAMMAR
 ```
program: START_TOKEN listStmt END_TOKEN
;
assignment: LET NAME ASSIGN exp
;
stmt: builtin SEMI
| ifStmt
| assignment SEMI
| loop
| NAME ASSIGN exp SEMI
;
ref: NAME
;
loop: WHILE OPEN_BRACKET cmp CLOSE_BRACKET OPEN_CURRLY_BRACKET listStmt CLOSE_CURRLY_BRACKET
;
listStmt:
| stmt listStmt
;
ifStmt: IF OPEN_BRACKET cmp CLOSE_BRACKET OPEN_CURRLY_BRACKET listStmt CLOSE_CURRLY_BRACKET
;
cmp: exp
| exp EQUAL_TO exp 
| exp LESS_THAN exp
;
builtin: BUILTIN_PRINT OPEN_BRACKET exp CLOSE_BRACKET
| BUILTIN_SCAN OPEN_BRACKET ref CLOSE_BRACKET
;
exp: ref
| NUMBER
| exp ADD exp
| exp SUB exp
| exp MUL exp 
| exp DIV exp 
;
```
 
