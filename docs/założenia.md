# Terra - JS subset interpreter

##  Modules
- ###  CORE:
	1. opis:
		* głowny moduł
	2. struct:
	```c
	
	// now idonno possible can be
	
- ### LEXER:
	1. opis:
	   * zamienia src code na słowa
	2. struct:
	```c
	struct lexerList {
		lexerToken token;
		char* value; // or sds type
		lexerList* next;
	} lexerList;
	
 - ### PARSER:
	 1. opis:
	    * łączy słowa w formuły atomowe  
	 2. struct:
	```c
	struct lexerList {
		lexerToken token;
		char* value; // or sds type
		lexerList* next;
	} lexerList;
	
	struct parserTree {
		parserToken type;
		void** value; // (char * or sds) or parserTree
		parserTree* next;
	} parserTree;
	
 - ### COMPILER:
	1. opis:
	   * zmienia formuły atomowe w byte code
	2. struct:
	```c
	struct parserTree {
		parserToken type;
		void** value; // (char * or sds) or parserTree
		parserTree* next;
	} parserTree;
	
	struct compilerList {
		compilerToken type;
		char* value; // or sds
		compilerList* next;
	} compilerList;
	
 - ### INTERPRETER:
	1. opis:
	   * interpretuje byte code
	2. struct:
	```c
	struct compilerList {
		compilerToken type;
		char* value; // or sds
		compilerList* next;
	} compilerList;
	
	struct runtime {
		void* rip;
		void* esp; 
		void** memory;
	} runtime;

## Dependency
- [sds](https://github.com/antirez/sds) string lib
- [greatest](https://github.com/silentbicycle/greatest) unit test lib ( możliwe że zmienię )

## Uwagi
prawdopobnie będę modyfikował struktury czy bibloiteki ale odnotuję co i dlaczego zmieniam 

## Github
- [repo](https://github.com/jjzajac/terra)

