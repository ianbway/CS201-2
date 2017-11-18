# Ian Braudaway
# makefile for assignment 3

DA_OBJS = integer.o real.o string.o da.o
CDA_OBJS = integer.o real.o string.o cda.o
QUEUE_OBJS = integer.o real.o string.o cda.o queue.o
BST_OBJS = integer.o real.o string.o cda.o queue.o bst.o
RBT_OBJS = integer.o real.o string.o cda.o queue.o bst.o rbt.o
SET_OBJS = integer.o real.o string.o da.o set.o 
#test-set.o
KRU_OBJS = scanner.o integer.o real.o string.o da.o set.o cda.o queue.o bst.o rbt.o kruskal.o
OPTS = -Wall -Wextra -std=c99 -g -c 
LOPTS = -Wall -Wextra -std=c99 -g
CC = gcc

all : kruskal

#test-set : $(SET_OBJS)
#	$(CC) $(LOPTS) $(SET_OBJS) -o test-set

kruskal : $(KRU_OBJS)
	$(CC) $(LOPTS) $(KRU_OBJS) -lm -o kruskal
	
#test-set.o : test-set.c
#	$(CC) $(OPTS) test-set.c 

kruskal.o : kruskal.c
	$(CC) $(OPTS) -lm kruskal.c 
	
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
	rm -f $(CDA_OBJS) $(QUEUE_OBJS) $(BST_OBJS) $(RBT_OBJS) $(DA_OBJS) $(SET_OBJS) $(KRU_OBJS) ./test-set ./kruskal

test :
	./kruskal
