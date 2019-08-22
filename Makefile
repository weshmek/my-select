CC=gcc
CFLAGS=-Werror -Wall -g

test2 : CFLAGS:=${CFLAGS} -Dselect_type=double
test2 : Test2.o select.o
	${CC} ${CFLAGS} -o $@ $^

test3 : CFLAGS:=${CFLAGS} -Dselect_type='unsigned int'
test3 : Test3.o select.o
	${CC} ${CFLAGS} -o $@ $^

select.s : CFALGS=${CFLAGS} -Dselect_tpe=double
select.s : select.c
	${CC} -S -o $@ $^

clean :
	rm -f test2 test3 *.o

.PHONY : clean



