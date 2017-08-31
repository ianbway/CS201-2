# makefile for assignment 0
DA_OBJS = integer.o da.o test-da.o
#CDA_OBJS = integer.o cda.o test-cda.o
STACK_OBJS = integer.o stack.o test-stack.o
#QUEUE_OBJS = integer.o queue.o test-queue.o
OPTS = -Wall -Wextra -std=c99 -g -c 
LOPTS = -Wall -Wextra -std=c99 -g
CC = gcc

all : test-da test-stack

test-da : $(DA_OBJS)
	$(CC) $(LOPTS) $(DA_OBJS) -o test-da

test-stack : $(STACK_OBJS)
	$(CC) $(LOPTS) $(STACK_OBJS) -o test-stack

da.o : da.c da.h
	$(CC) $(OPTS) da.c

integer.o : integer.c integer.h
	$(CC) $(OPTS) integer.c

#cda.o : cda.c cda.h
#	$(CC) $(OPTS) cda.c

stack.o : stack.c stack.h
	$(CC) $(OPTS) stack.c

#queue.o : queue.c queue.h
#        $(CC) $(OPTS) queue.c

clean :
	rm -f $(DA_OBJS) $(STACK_OBJS)

test :
	./all
