test_module: test_module.o module.o
	gcc -o $@ $^
test_module.o: module.h test_module.c
	gcc -c test_module.c
module.o: module.h module.c
	gcc -c module.c
.PHONY: clean
clean:
	@rm test_module test_module.o module.o
