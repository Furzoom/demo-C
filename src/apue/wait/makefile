obj=wait
CFLAGS=-Wall -std=c99
all: ${obj}
debug: CFLAGS += -g
debug: ${obj}

${obj}:${obj}.c
	$(CC) $(CFLAGS) -o ${obj} ${obj}.c -I../lib -L../lib -lunp

clean:
	@rm -fv ${obj} core.*
