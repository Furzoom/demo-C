OBJ = dup
CFLAGS = -Wall -std=c99
LDFLAGS = -lunp

all: ${OBJ}
debug: CFLAGS += -g
debug: ${OBJ}

${OBJ}:${OBJ}.c
	$(CC) $(CFLAGS) -o $@ $^ -I../lib -L../lib -lunp
	echo "Hello" >test.txt

clean:
	@rm -fv ${OBJ} test.txt