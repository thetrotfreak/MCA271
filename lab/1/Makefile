CC = gcc

CFLAGS = -g3 -Wall -Wpedantic

ROOT = $(HOME)/dev/mca/2/dsa

TARGET = 1

all: $(TARGET)

$(TARGET): 1.o main.o misc.o
	$(CC) $(CFLAGS) -o $@ $^ -I$(ROOT)

1.o: 1.c 1.h
	$(CC) $(CFLAGS) -c $^ -I$(ROOT)

main.o: main.c
	$(CC) $(CFLAGS) -c $^ -I$(ROOT)

misc.o: $(ROOT)/misc.c $(ROOT)/misc.h
	$(CC) $(CFLAGS) -c $^ -I$(ROOT)

clean:
	$(RM) *.o
	$(RM) *.out
	$(RM) *.gch
	fd . --max-depth=1 --type=executable --exec="$(RM)"

.PHONY: all clean
