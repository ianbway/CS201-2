# Ian Braudaway
# makefile for assignment 1
DA_OBJS = integer.o real.o string.o da.o
CDA_OBJS = integer.o real.o string.o cda.o
STACK_OBJS = integer.o real.o string.o da.o stack.o
QUEUE_OBJS = integer.o real.o string.o cda.o queue.o
BST_OBJS = integer.o real.o string.o bst.o test-bst.o
MATILDA_OBJS = integer.o real.o string.o scanner.o da.o cda.o stack.o queue.o bst.o matilda.o 
OPTS = -Wall -Wextra -std=c99 -g -c 
LOPTS = -Wall -Wextra -std=c99 -g
CC = gcc

all : matilda

matilda : $(MATILDA_OBJS)
	$(CC) $(LOPTS) $(MATILDA_OBJS) -lm -o matilda

test-bst : $(BST_OBJS)
	$(CC) $(LOPTS) $(BST_OBJS) -o test-bst

matilda.o : matilda.c
	$(CC) $(OPTS) -lm matilda.c

scanner.o : scanner.c scanner.h
	$(CC) $(OPTS) scanner.c

real.o : real.c real.h
	$(CC) $(OPTS) real.c 
	
integer.o : integer.c integer.h
	$(CC) $(OPTS) integer.c

string.o : string.c string.h
	$(CC) $(OPTS) string.c

da.o : da.c da.h
	$(CC) $(OPTS) da.c

cda.o : cda.c cda.h
	$(CC) $(OPTS) cda.c

stack.o : stack.c stack.h
	$(CC) $(OPTS) stack.c

queue.o : queue.c queue.h
	$(CC) $(OPTS) queue.c

bst.o : bst.c bst.h
	$(CC) $(OPTS) bst.c

clean :
	rm -f $(DA_OBJS) $(STACK_OBJS) $(CDA_OBJS) $(QUEUE_OBJS) $(BST_OBJS) $(MATILDA_OBJS) ./test-bst ./matilda ./matilda.o

test :
	./matilda -i -p -b input.txt
