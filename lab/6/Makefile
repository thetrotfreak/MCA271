run: all
	./a.out in.txt \|

all : main.c 6.o domain.o
	gcc $^ -g3 -I../../lib/util 

6.o : 6.c 
	gcc -c $^ -g3 -I../../lib/util 

domain.o : ../../lib/util/domain.c
	gcc -c $^ -g3 -I../../lib/util

clean :
	rm -f *.o *.out *.gch

.PHONY : all clean run
.SILENT: run
