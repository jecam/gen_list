CC=gcc
CFLAGS=-Wall -pedantic -Wextra -ansi

all: gen_llist

gen_llist: gen_llist.o main.o util.o
	$(CC) $(CFLAGS) gen_llist.o main.o util.o -o gen_llist -g

gen_llist.o: gen_llist.c gen_llist.h util.h
	$(CC) $(CFLAGS) gen_llist.c -o gen_llist.o -c -g

main.o: main.c gen_llist.h
	$(CC) $(CFLAGS) main.c -o main.o -c -g

util.o: util.c
	$(CC) $(CFLAGS) util.c -o util.o -c -g

test: all
	./gen_llist

memtest: all
	valgrind ./gen_llist

clean:
	-rm -f *.o
	-rm -f gen_llist
	-rm -f *~

.PHONY: clean all test memtest
