CFlags = -Wall -Wextra

List: list.o
	gcc -o List list.o $(CFlags)
list.o: list.c list.h
	gcc -c list.c $(CFlags)
clean:
	rm List *.o
