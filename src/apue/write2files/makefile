obj=write2files

${obj}:${obj}.c
	gcc -Wall -o ${obj} ${obj}.c -I../lib -L../lib -lunp

clean:
	-$(RM) ${obj} test.txt
