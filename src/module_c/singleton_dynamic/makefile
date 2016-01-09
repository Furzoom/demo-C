module = singleton
obj = test_$(module).o $(module).o
all = test_$(module)


$(all): $(obj)
	gcc -o $@ $^
#$(module).o: $(module).h $(module).c
#	gcc -c $(module).c
#test_$(module).o: $(module).h test_$(module).c
#	gcc -c test_$(module).c
.PHONY: clean
clean:
	@rm $(all) $(obj)
