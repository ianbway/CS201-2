# Ian Braudaway
# makefile for assignment 3
DA_OBJS = integer.o real.o string.o da.o
CDA_OBJS = integer.o real.o string.o cda.o
QUEUE_OBJS = integer.o real.o string.o cda.o queue.o
BST_OBJS = integer.o real.o string.o cda.o queue.o bst.o test-bst.o
RBT_OBJS = integer.o real.o string.o cda.o queue.o bst.o rbt.o test-rbt.o
SET_OBJS = integer.o real.o string.o set.o
OPTS = -Wall -Wextra -std=c99 -g -c 
LOPTS = -Wall -Wextra -std=c99 -g
CC = gcc

all : test-rbt

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

queue.o : queue.c queue.h
	$(CC) $(OPTS) queue.c

bst.o : bst.c bst.h
	$(CC) $(OPTS) bst.c

rbt.o : rbt.c rbt.h
	$(CC) $(OPTS) rbt.c
	
set.o : set.c set.h
	$(CC) $(OPTS) set.c
	
clean :
	rm -f $(CDA_OBJS) $(QUEUE_OBJS) $(BST_OBJS) $(RBT_OBJS) 

test :
	./test-rbt
