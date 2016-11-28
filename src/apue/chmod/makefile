obj=chmod

${obj}:${obj}.c
	gcc -Wall -o ${obj} ${obj}.c -I../lib -L../lib -lunp
	touch bar foo
	ls -l

clean:
	@rm -fv ${obj} bar foo
