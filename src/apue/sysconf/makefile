obj=sysconf
CFLAGS=-Wall

$(obj): generate.awk sysconf.conf
	awk -f generate.awk > $(obj).c
	$(CC) $(CFLAGS) -o $(obj) $(obj).c -I../lib -L../lib -lunp

clean:
	$(RM) $(obj) $(obj).c
