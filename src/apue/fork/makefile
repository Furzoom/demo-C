obj=fork
CFLAGS=-Wall -std=c99
all: ${obj}
debug: CFLAGS += -g
debug: ${obj}

${obj}:${obj}.c
	$(CC) $(CFLAGS) -o ${obj} ${obj}.c -I../lib -L../lib -lunp
	@echo -e "Usage: ./fork\n       ./fork > test.txt"

clean:
	@rm -fv ${obj} test.txt
