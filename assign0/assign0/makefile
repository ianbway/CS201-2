# makefile for assignment 0
TARGET = test-da
OBJS = *.o
OPTS = -Wall -Wextra -std=c99 -g -c
LOPTS = -Wall -Wextra -g
CC = gcc

$(TARGET) : $(TARGET).o da.o integer.o
	$(CC)  $(LOPTS)  $(OBJS) -o $(TARGET)

$(TARGET).o : $(TARGET).c
	$(CC) $(OPTS) -c $(TARGET).c

da.o : da.c da.h
	$(CC) $(OPTS) -c da.c

integer.o : integer.c integer.h
	$(CC) $(OPTS) -c integer.c

#cda.o : cda.c cda.h
#	$(CC) $(OPTS) -c cda.c

#stack.o : stack.c stack.h
#	$(CC) $(OPTS) -c stack.c

#queue.o : queue.c queue.h
#        $(CC) $(OPTS) -c queue.c

clean :
	rm -f $(OBJS) $(TARGET)

test :
	./$(TARGET)
