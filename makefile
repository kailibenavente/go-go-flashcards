program: go-go-flashcards.o getdouble.o
	gcc go-go-flashcards.o getdouble.o -o program -lm

go-go-flashcards.o: go-go-flashcards.c getdouble.h
	gcc -std=c99 -c go-go-flashcards.c

getdouble.o: getdouble.c getdouble.h
	gcc -std=c99 -c getdouble.c
