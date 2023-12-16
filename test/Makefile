all: main

main: main.c patient.o
	gcc $^ -g3 -std=c11

patient.o: patient.c patient.h
	gcc -c $^ -g3 -std=c11

clean:
	rm -f *.o *.out *.gch

.PHONY: all clean main
