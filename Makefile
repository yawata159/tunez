default: run

songnode.o : songnode.c 
	gcc -c songnode.c -o songnode.o

main.o: main.c 
	gcc -c main.c -o main.o

tunez: songnode.o main.o
	gcc songnode.o main.o -o tunez

run: tunez
	./tunez

clean:
	rm *~; rm *.o
