a.out: file_a.o file_b.o test.o
	g++ -o a.out file_a.o file_b.o test.o
file_a.o: file_a.h file_a.cpp
	g++ -c -o file_a.o file_a.cpp
file_b.o: file_b.h file_b.cpp
	g++ -c -o file_b.o file_b.cpp
test.o: file_a.h file_b.h test.cpp
	g++ -c -o test.o test.cpp

.PHONY:clean
clean:
	@rm a.out file_a.o file_b.o test.o
