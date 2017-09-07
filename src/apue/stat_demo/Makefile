OBJ = stat_demo
CFLAGS = -Wall -std=c99
LDFLAGS = -lunp

all: ${OBJ}
debug: CFLAGS += -g
debug: ${OBJ}

${OBJ}:${OBJ}.c
	$(CC) $(CFLAGS) -o $@ $^ -I../lib -L../lib -lunp

clean:
	@rm -fv ${OBJ}