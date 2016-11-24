obj=open_file

${obj}:${obj}.c
	gcc -Wall -o ${obj} ${obj}.c -I../lib -L../lib -lunp

clean:
	-$(RM) ${obj} test.txt
