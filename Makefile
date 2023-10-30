CC = gcc

1_C = student.c \
	misc.c

1_H = student.h \
	misc.h

1:
	$(CC) $(1_C) $(1_H) -o 1

clean:
	find . -maxdepth 1 -type f -executable -delete

.PHONY:all clean
