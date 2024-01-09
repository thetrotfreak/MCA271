CC = clang
CLFAGS = -fsanitize=address -fno-omit-frame-pointer -g3 -Wall -Werror -Wpedantic
INCLUDES = ../../lib/util
TARGET = main

all: 7
	./$(TARGET)

7: main.c 7.o domain.o
	$(CC) -o $(TARGET) $^ -I. -I$(INCLUDES) $(CFLAGS) 

7.o: 7.c 7.h
	$(CC) -c $^ -I. -I$(INCLUDES) $(CFLAGS) 

domain.o: $(INCLUDES)/domain.c $(INCLUDES)/domain.h
	$(CC) -c $^ -I$(INCLUDES) $(CFLAGS) 

clean:
	rm *.o
	rm *.h.gch
	fdfind . --type=executable --exec-batch=rm

.PHONY: all 7 clean
.SILENT: clean
