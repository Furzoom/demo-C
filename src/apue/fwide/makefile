obj=fwide
CFLAGS=-Wall
all: ${obj}
debug: CFLAGS += -g
debug: ${obj}

${obj}:${obj}.c
	$(CC) $(CFLAGS) -o ${obj} ${obj}.c -I../lib -L../lib -lunp

clean:
	@rm -fv ${obj}
