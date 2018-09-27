# Macros:
CFlags = -Wall -Wextra
Headers = list.h parser.h

537ps: main.o list.o parser.o
	gcc -o 537ps main.o list.o parser.o $(CFlags)

main.o: main.c $(Headers)
	gcc -c main.c $(CFlags)

list.o: list.c list.h
	gcc -c list.c $(CFlags)

parser.o: parser.c parser.h
	gcc -c parser.c $(CFlags)

clean:
	rm 537ps *.o
