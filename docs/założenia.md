
# Terra
## Wprowadzenie
Terra to interpreter podzbioru jezyka JavaScript napisany w języku C z pomocą flex'a i bison'a.
## Moduły
- ### LEXER
	Moduł realizujący podział danego tekstu na tokeny, które bedą dzielone na kolejne fragmenty składowe programu. W tym module będzie również pierwsza validacja danych - sprawdzenie czy użytkownik użył jedynie poprawnych znaków. Moduł będzie zrealizowany za pomocą generatora flex.
	
 - ### PARSER & INTERPRETER
	 Moduł w interakcji z Lexer'em będzie tworzył AST (abstract syntax tree), które będzie poprawną gramatyką jezyka js. Będzie również sprawdzał czy użytkwonik używa poprawnej składni zadeklarownej w [BNF](https://pl.wikipedia.org/wiki/Notacja_BNF). Następnie redukuje i wyrażenia do oczekiwanego wyniku.

## Struktury danych
- AST (drzewo syntaktyczne) - drzewo, które powstaje w wyniku statycznej analizy, uczestniczy w procesie interpretacji kodu,
- symbol table (tablica z haszowaniem) - służy asocjacji identyfikatora z kodem programu.
## Interakcja
Programu będzie można użyć poprzez wpisanie komendy do terminala:
```bash
./terra nazwaProgramu 
```
## Zależności
- [flex](https://github.com/westes/flex) generator lexer'ów,
- [gnu bison](https://www.gnu.org/software/bison/) generator parser'ów.

## Github
- [repo](https://github.com/jjzajac/terra)
