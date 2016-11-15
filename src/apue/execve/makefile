obj=myecho execve

all: ${obj}

myecho: myecho.c
	gcc -Wall -o $@ $< -I../lib -L../lib -lunp
execve: execve.c
	gcc -Wall -o $@ $< -I../lib -L../lib -lunp

clean:
	@rm -fv ${obj}
