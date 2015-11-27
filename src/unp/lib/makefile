test=error_test
obj=libunp.a

${obj}:error.o read_write.o
	ar crv ${obj} $^
	ranlib ${obj}

#unp.o:error.c read_write.c unp.h error.h 
#	gcc -Wall -c -o unp.o error.c read_write.c

${test}:error.o read_write.o
	gcc -Wall -g -o ${test} ${test}.c $^

error.o: error.c error.h 
#	gcc -Wall -c error.c

read_write.o: read_write.c unp.h
#	gcc -Wall -c read_write.c

.PHONY:clean
clean:
	-rm ${obj} ${test} error.o read_write.o
	@echo "clean up"
