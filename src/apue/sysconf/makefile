obj=sysconf
CFLAGS=-Wall

$(obj): generate.awk sysconf.conf pathconf.conf
	awk -f generate.awk > $(obj).c < pathconf.conf
	$(CC) $(CFLAGS) -o $(obj) $(obj).c -I../lib -L../lib -lunp

clean:
	$(RM) $(obj) $(obj).c
