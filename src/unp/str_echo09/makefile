serv=str_echo09
cli=str_cli09
obj=$(serv) $(cli)

all:${obj}
#all:tcpserv01
.PHONY:all

$(cli): $(cli).o | ../lib/libunp.a
	gcc -Wall -o $(cli) $(cli).o -I../lib -L../lib -lunp

$(cli).o: $(cli).c ../lib/unp.h
	gcc -Wall -c $(cli).c -I../lib
#${cli}:${cli}.c
#	gcc -Wall -o ${cli} ${cli}.c -I../lib -L../lib -lunp

$(serv):$(serv).o | ../lib/libunp.a
	gcc -Wall -o $(serv) $(serv).o -I../lib -L../lib -lunp

$(serv).o: $(serv).c ../lib/unp.h
	gcc -Wall -c $(serv).c -I../lib

clean:
	@rm -fv $(obj) $(serv).o $(cli).o
