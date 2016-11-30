obj=unlink

${obj}:${obj}.c
	gcc -Wall -o ${obj} ${obj}.c -I../lib -L../lib -lunp
	touch foo.txt

clean:
	-rm -fv ${obj} foo.txt
