CC = gcc

CFLAGS = -Wall -Wpedantic -g3

INCLUDES = -I/home/bivas/dev/mca/2/dsa/lib/struct -I/home/bivas/dev/mca/2/dsa/lib/util

4: 4.o sll.o
	$(CC) main.c $^ -o 4 $(INCLUDES)

4.o: 4.c 4.h
	$(CC) -c $^ $(CFLAGS) $(INCLUDES)

sll.o: ../../lib/struct/sll.c ../../lib/struct/sll.h
	$(CC) -c $^ $(CFLAGS) $(INCLUDES)

clean:
	$(RM) *.o *.out *.gch 4

.PHONY: clean
