default: tunez

link_list.o : link_list.c 
	gcc -o link_list.o -c link_list.c 

library.o: library.c 
	gcc -o library.o -c library.c 

main.o: main.c
	gcc -o main.o -c main.c

tunez: link_list.o library.o main.o
	gcc -o tunez link_list.o library.o main.o 

clean:
	rm *~; rm *.o
