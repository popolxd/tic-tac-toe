output: main.o print.o game.o
	gcc main.o print.o game.o -o output

main.o: main.c
	gcc -c main.c

print.o: print.c print.h
	gcc -c print.c

game.o: game.c game.h
	gcc -c game.c

clean:
	rm *.o output