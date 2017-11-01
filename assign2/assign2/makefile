# Ian Braudaway
# makefile for assignment 2
CDA_OBJS = integer.o real.o string.o cda.o
QUEUE_OBJS = integer.o real.o string.o cda.o queue.o
BST_OBJS = integer.o real.o string.o bst.o
GT_OBJS = integer.o real.o string.o bst.o gt.o
RBT_OBJS = integer.o real.o string.o bst.o rbt.o
OPTS = -Wall -Wextra -std=c99 -g -c 
LOPTS = -Wall -Wextra -std=c99 -g
CC = gcc

all : 

scanner.o : scanner.c scanner.h
	$(CC) $(OPTS) scanner.c

real.o : real.c real.h
	$(CC) $(OPTS) real.c 
	
integer.o : integer.c integer.h
	$(CC) $(OPTS) integer.c

string.o : string.c string.h
	$(CC) $(OPTS) string.c

cda.o : cda.c cda.h
	$(CC) $(OPTS) cda.c

queue.o : queue.c queue.h
	$(CC) $(OPTS) queue.c

bst.o : bst.c bst.h
	$(CC) $(OPTS) bst.c

gt.o : gt.c gt.h
	$(CC) $(OPTS) gt.c	
	
rbt.o : rbt.c rbt.h
	$(CC) $(OPTS) rbt.c
	
clean :
	rm -f $(CDA_OBJS) $(QUEUE_OBJS) $(BST_OBJS) $(GT_OBJS) $(RBT_OBJS)

test :
