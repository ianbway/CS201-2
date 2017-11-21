# Ian Braudaway
# makefile for assignment 2
TREE_OBJS = scanner.o integer.o real.o string.o cda.o queue.o bst.o rbt.o gt.o trees.o
CDA_OBJS = integer.o real.o string.o cda.o
QUEUE_OBJS = integer.o real.o string.o cda.o queue.o
BST_OBJS = integer.o real.o string.o cda.o queue.o bst.o test-bst.o
GT_OBJS = integer.o real.o string.o cda.o queue.o bst.o gt.o test-gt.o
RBT_OBJS = integer.o real.o string.o cda.o queue.o bst.o rbt.o test-rbt.o
OPTS = -Wall -Wextra -std=c99 -g -c 
LOPTS = -Wall -Wextra -std=c99 -g
CC = gcc

all : trees

trees : $(TREE_OBJS)
	$(CC) $(LOPTS) $(TREE_OBJS) -o trees

test-rbt : $(RBT_OBJS)
	$(CC) $(LOPTS) $(RBT_OBJS) -o test-rbt

test-gt : $(GT_OBJS)
	$(CC) $(LOPTS) $(GT_OBJS) -o test-gt
	
test-bst : $(BST_OBJS)
	$(CC) $(LOPTS) $(BST_OBJS) -o test-bst	

trees.o : trees.c 
	$(CC) $(OPTS) trees.c	
	
test-rbt.o : test-rbt.c 
	$(CC) $(OPTS) test-rbt.c
	
test-gt.o : test-gt.c 
	$(CC) $(OPTS) test-gt.c
	
test-bst.o : test-bst.c 
	$(CC) $(OPTS) test-bst.c

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
	rm -f $(CDA_OBJS) $(QUEUE_OBJS) $(BST_OBJS) $(GT_OBJS) $(RBT_OBJS) $(TREE_OBJS) ./test-bst ./test-gt ./test-rbt ./trees

test :
	./trees -g trees.0 trees.1 trees.2
