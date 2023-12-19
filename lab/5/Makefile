all : main.c 5.o
	gcc $^ -g3 -I$(HOME)/dev/mca/2/dsa/lib/util 

5.o : 5.c 5.h
	gcc -c $^ -g3 -I$(HOME)/dev/mca/2/dsa/lib/util 

clean :
	rm -f *.o *.out *.gch

.PHONY : all clean
