# Macros:
CFlags = -Wall -Wextra
Headers = list.h parser.h processing.h

537ps: main.o list.o parser.o processing.o
	gcc -o 537ps main.o list.o parser.o processing.o $(CFlags)

main.o: main.c $(Headers)
	gcc -c main.c $(CFlags)

list.o: list.c list.h
	gcc -c list.c $(CFlags)

parser.o: parser.c parser.h
	gcc -c parser.c $(CFlags)
	
processing.o: processing.c processing.h
	gcc -c processing.c $(CFlags)

clean:
	rm 537ps *.o
