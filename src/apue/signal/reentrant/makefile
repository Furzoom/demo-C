obj=reentrant
CFLAGS=-Wall -std=c99
LIBS=../../lib
INCLUDES=../../lib

all: ${obj}
debug: CFLAGS += -g
debug: ${obj}

${obj}:${obj}.c
	$(CC) $(CFLAGS) -o ${obj} ${obj}.c -I${INCLUDES} -L${LIBS} -lunp

clean:
	@rm -fv ${obj}
