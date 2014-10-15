

all: gen_llist

gen_llist: gen_llist.c gen_llist.h util.h
	gcc -Wall -pedantic -Wextra -ansi gen_llist.c -o gen_llist -g

test: all
	./gen_llist

memtest: all
	valgrind ./gen_llist

clean:
	-rm -f gen_llist
	-rm -f *~

.PHONY: clean all test memtest
