obj=readlink

${obj}:${obj}.c
	gcc -Wall -o $@ $< -I../lib -L../lib -lunp
	ln -s makefile foo

clean:
	@rm -fv ${obj} foo
