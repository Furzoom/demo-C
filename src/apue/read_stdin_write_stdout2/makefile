obj=read_stdin_write_stdout2

${obj}:${obj}.c
	gcc -Wall -o ${obj} ${obj}.c -I../lib -L../lib -lunp

clean:
	@rm -fv ${obj}
