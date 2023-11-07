CC = gcc

DS_H = /home/bivas/dev/mca/2/dsa/ds

1_C = student.c \
	misc.c

1_H = student.h \
	misc.h

1:
	$(CC) $(1_C) $(1_H) -I$(DS_H) -o 1

clean:
	find . -maxdepth 1 -type f -executable -delete
	rm cscope.*

cscope:
	cscope -q -R -b

.SILENT:cscope

.PHONY:all clean
