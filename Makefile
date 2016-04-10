OBJECTS=Test2.o select.o
DEPENDS=${OBJECTS:.o=.d}
CFLAGS=-MMD -Werror -Wall
CC=gcc

test2 : ${OBJECTS}
	${CC} ${CFLAGS} -o $@ $^

-include ${DEPENDS}
