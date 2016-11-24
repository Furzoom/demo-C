obj=sysconf
CFLAGS=-Wall

$(obj): generate.awk sysconf.conf pathconf.conf
	awk -f $< > $@.c < pathconf.conf
	$(CC) $(CFLAGS) -o $@ $@.c -I../lib -L../lib -lunp

clean:
	$(RM) $(obj) $(obj).c
