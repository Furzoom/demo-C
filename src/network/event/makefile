TARGET 	= test
SRC	 	= $(TARGET).c
OBJ		= $(TARGET).o
CC		= gcc
CFLAGS	= -g3 -W -Wall -std=c99
LOG	    = log
OBJS    = $(OBJ) $(LOG).o

$(TARGET): $(OBJS)

.PHONY: clean

clean:
	$(RM) $(TARGET) $(OBJS)
