cc = gcc

cflags = -Wall -Wpedantic -g3

baselib = -I$(HOME)/dev/mca/2/dsa/lib/

utilities = util/

structures = struct/

myio = io/

target = sll

all: $(target).o

$(target).o: $(target).c $(target).h
	$(cc) -c $^ $(baselib)$(utilities) $(cflags)

clean:
	$(RM) *.o *.out *.gch

.PHONY: clean
