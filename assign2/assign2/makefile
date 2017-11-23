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
	@echo Cleaning error files 
	rm ./testFiles/error/*
	@echo Running your Green Tree on my input
	./trees -g ./testFiles/input/one.0 ./testFiles/commands/display ./testFiles/output/one.txt
	./trees -g ./testFiles/input/onlineExample ./testFiles/commands/onlineExampleCommand ./testFiles/output/gtest0.txt >> ./testFiles/error/gerror0.error
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/display ./testFiles/output/gtest1.txt >> ./testFiles/error/gerror1.error
	./trees -g ./testFiles/input/spaces.0 ./testFiles/commands/display ./testFiles/output/gtest2.txt >> ./testFiles/error/gerror2.error
	./trees -g ./testFiles/input/s9.0 ./testFiles/commands/display ./testFiles/output/gtest3.txt >> ./testFiles/error/gerror3.error
	./trees -g ./testFiles/input/s10.0 ./testFiles/commands/display ./testFiles/output/gtest4.txt >> ./testFiles/error/gerror4.error
	./trees -g ./testFiles/input/s11.0 ./testFiles/commands/display ./testFiles/output/gtest5.txt >> ./testFiles/error/gerror5.error
	./trees -g ./testFiles/input/s12.0 ./testFiles/commands/display ./testFiles/output/gtest6.txt >> ./testFiles/error/gerror6.error
	./trees -g ./testFiles/input/s13.0 ./testFiles/commands/display ./testFiles/output/gtest7.txt >> ./testFiles/error/gerror7.error
	./trees -g ./testFiles/input/s14.0 ./testFiles/commands/display ./testFiles/output/gtest8.txt >> ./testFiles/error/gerror8.error
	./trees -g ./testFiles/input/s15.0 ./testFiles/commands/display ./testFiles/output/gtest9.txt >> ./testFiles/error/gerror9.error
	./trees -g ./testFiles/input/w16.0 ./testFiles/commands/display ./testFiles/output/gtest10.txt >> ./testFiles/error/gerror10.error
	./trees -g ./testFiles/input/w17.0 ./testFiles/commands/display ./testFiles/output/gtest11.txt >> ./testFiles/error/gerror11.error
	./trees -g ./testFiles/input/w18.0 ./testFiles/commands/display ./testFiles/output/gtest12.txt >> ./testFiles/error/gerror12.error
	./trees -g ./testFiles/input/w19.0 ./testFiles/commands/display ./testFiles/output/gtest13.txt >> ./testFiles/error/gerror13.error
	./trees -g ./testFiles/input/w20.0 ./testFiles/commands/display ./testFiles/output/gtest14.txt >> ./testFiles/error/gerror14.error
	./trees -g ./testFiles/input/w21.0 ./testFiles/commands/display ./testFiles/output/gtest15.txt >> ./testFiles/error/gerror15.error
	./trees -g ./testFiles/input/w22.0 ./testFiles/commands/display ./testFiles/output/gtest16.txt >> ./testFiles/error/gerror16.error
	./trees -g ./testFiles/input/w23.0 ./testFiles/commands/display ./testFiles/output/gtest17.txt >> ./testFiles/error/gerror17.error
	./trees -g ./testFiles/input/w24.0 ./testFiles/commands/display ./testFiles/output/gtest18.txt >> ./testFiles/error/gerror18.error
	@echo Running your Green Tree with my input and commands
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c25.0 ./testFiles/output/gtest19.txt >> ./testFiles/error/gerror19.error
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c26.0 ./testFiles/output/gtest20.txt >> ./testFiles/error/gerror20.error
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c27.0 ./testFiles/output/gtest21.txt >> ./testFiles/error/gerror21.error
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c28.0 ./testFiles/output/gtest22.txt >> ./testFiles/error/gerror22.error
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c29.0 ./testFiles/output/gtest23.txt >> ./testFiles/error/gerror23.error
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c30.0 ./testFiles/output/gtest24.txt >> ./testFiles/error/gerror24.error
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c31.0 ./testFiles/output/gtest25.txt >> ./testFiles/error/gerror25.error
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c32.0 ./testFiles/output/gtest26.txt >> ./testFiles/error/gerror26.error
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c35.0 ./testFiles/output/gtest27.txt >> ./testFiles/error/gerror27.error
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c36.0 ./testFiles/output/gtest28.txt >> ./testFiles/error/gerror28.error
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c37.0 ./testFiles/output/gtest29.txt >> ./testFiles/error/gerror29.error
	./trees -g ./testFiles/input/empty ./testFiles/commands/commands.0 ./testFiles/output/gtest30.txt >> ./testFiles/error/gerror30.error
	@echo Running your Green Tree with my delete commands
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/deleteBob ./testFiles/output/gtestd1.txt >> ./testFiles/error/gerrord1.error
	./trees -g ./testFiles/input/spaces.0 ./testFiles/commands/deleteBob ./testFiles/output/gtestd2.txt >> ./testFiles/error/gerrord2.error
	./trees -g ./testFiles/input/clean2.0 ./testFiles/commands/deleteBob ./testFiles/output/gtestd3.txt >> ./testFiles/error/gerrord3.error
	./trees -g ./testFiles/input/spaces2.0 ./testFiles/commands/deleteBob ./testFiles/output/gtestd4.txt >> ./testFiles/error/gerrord4.error
	./trees -g ./testFiles/input/clean2.0 ./testFiles/commands/deleteBob2 ./testFiles/output/gtestd5.txt >> ./testFiles/error/gerrord5.error
	./trees -g ./testFiles/input/spaces2.0 ./testFiles/commands/deleteBob2 ./testFiles/output/gtestd6.txt >> ./testFiles/error/gerrord6.error
	
	@echo Running your Red-Black Tree with my inputs
	./trees -r ./testFiles/input/onlineExample ./testFiles/commands/onlineExampleCommand ./testFiles/output/rbtest0.txt >> ./testFiles/error/rberror0.error
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/display ./testFiles/output/rbtest1.txt >> ./testFiles/error/rberror1.error
	./trees -r ./testFiles/input/spaces.0 ./testFiles/commands/display ./testFiles/output/rbtest2.txt >> ./testFiles/error/rberror2.error
	./trees -r ./testFiles/input/s9.0 ./testFiles/commands/display ./testFiles/output/rbtest3.txt >> ./testFiles/error/rberror3.error
	./trees -r ./testFiles/input/s10.0 ./testFiles/commands/display ./testFiles/output/rbtest4.txt >> ./testFiles/error/rberror4.error
	./trees -r ./testFiles/input/s11.0 ./testFiles/commands/display ./testFiles/output/rbtest5.txt >> ./testFiles/error/rberror5.error
	./trees -r ./testFiles/input/s12.0 ./testFiles/commands/display ./testFiles/output/rbtest6.txt >> ./testFiles/error/rberror6.error
	./trees -r ./testFiles/input/s13.0 ./testFiles/commands/display ./testFiles/output/rbtest7.txt >> ./testFiles/error/rberror7.error
	./trees -r ./testFiles/input/s14.0 ./testFiles/commands/display ./testFiles/output/rbtest8.txt >> ./testFiles/error/rberror8.error
	./trees -r ./testFiles/input/s15.0 ./testFiles/commands/display ./testFiles/output/rbtest9.txt >> ./testFiles/error/rberror9.error
	./trees -r ./testFiles/input/w16.0 ./testFiles/commands/display ./testFiles/output/rbtest10.txt >> ./testFiles/error/rberror10.error
	./trees -r ./testFiles/input/w17.0 ./testFiles/commands/display ./testFiles/output/rbtest11.txt >> ./testFiles/error/rberror11.error
	./trees -r ./testFiles/input/w18.0 ./testFiles/commands/display ./testFiles/output/rbtest12.txt >> ./testFiles/error/rberror12.error
	./trees -r ./testFiles/input/w19.0 ./testFiles/commands/display ./testFiles/output/rbtest13.txt >> ./testFiles/error/rberror13.error
	./trees -r ./testFiles/input/w20.0 ./testFiles/commands/display ./testFiles/output/rbtest14.txt >> ./testFiles/error/rberror14.error
	./trees -r ./testFiles/input/w21.0 ./testFiles/commands/display ./testFiles/output/rbtest15.txt >> ./testFiles/error/rberror15.error
	./trees -r ./testFiles/input/w22.0 ./testFiles/commands/display ./testFiles/output/rbtest16.txt >> ./testFiles/error/rberror16.error
	./trees -r ./testFiles/input/w23.0 ./testFiles/commands/display ./testFiles/output/rbtest17.txt >> ./testFiles/error/rberror17.error
	./trees -r ./testFiles/input/w24.0 ./testFiles/commands/display ./testFiles/output/rbtest18.txt >> ./testFiles/error/rberror18.error
	@echo Running your Red-Black Tree with my inputs and commands
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c25.0 ./testFiles/output/rbtest19.txt >> ./testFiles/error/rberror19.error
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c26.0 ./testFiles/output/rbtest20.txt >> ./testFiles/error/rberror20.error
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c27.0 ./testFiles/output/rbtest21.txt >> ./testFiles/error/rberror21.error
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c28.0 ./testFiles/output/rbtest22.txt >> ./testFiles/error/rberror22.error
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c29.0 ./testFiles/output/rbtest23.txt >> ./testFiles/error/rberror23.error
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c30.0 ./testFiles/output/rbtest24.txt >> ./testFiles/error/rberror24.error
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c31.0 ./testFiles/output/rbtest25.txt >> ./testFiles/error/rberror25.error
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c32.0 ./testFiles/output/rbtest26.txt >> ./testFiles/error/rberror26.error
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c35.0 ./testFiles/output/rbtest27.txt >> ./testFiles/error/rberror27.error
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c36.0 ./testFiles/output/rbtest28.txt >> ./testFiles/error/rberror28.error
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c37.0 ./testFiles/output/rbtest29.txt >> ./testFiles/error/rberror29.error
	./trees -r ./testFiles/input/empty ./testFiles/commands/commands.0 ./testFiles/output/rbtest30.txt >> ./testFiles/error/rberror30.error
	@echo Running your Red-Black Tree with my delete commands
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/deleteBob ./testFiles/output/rbtestd1.txt >> ./testFiles/error/rberrord1.error
	./trees -r ./testFiles/input/spaces.0 ./testFiles/commands/deleteBob ./testFiles/output/rbtestd2.txt >> ./testFiles/error/rberrord2.error
	./trees -r ./testFiles/input/clean2.0 ./testFiles/commands/deleteBob ./testFiles/output/rbtestd3.txt >> ./testFiles/error/rberrord3.error
	./trees -r ./testFiles/input/spaces2.0 ./testFiles/commands/deleteBob ./testFiles/output/rbtestd4.txt >> ./testFiles/error/rberrord4.error
	./trees -r ./testFiles/input/clean2.0 ./testFiles/commands/deleteBob2 ./testFiles/output/rbtestd5.txt >> ./testFiles/error/rberrord5.error
	./trees -r ./testFiles/input/spaces2.0 ./testFiles/commands/deleteBob2 ./testFiles/output/rbtestd6.txt >> ./testFiles/error/rberrord6.error
	
	@echo dun dun dunnnnn
	@echo Running your code with shakespeare
	./trees -g ./testFiles/input/shakespeare.txt ./testFiles/commands/shakespeare.display ./testFiles/output/gtestLong0.txt >> ./testFiles/error/gerrorLong0.error
	./trees -r ./testFiles/input/shakespeare.txt ./testFiles/commands/shakespeare.display ./testFiles/output/rbtestLong0.txt >> ./testFiles/error/rberrorLong0.error
	@echo dun dun dunnnnn
	@echo Running your code with beowulf
	./trees -g ./testFiles/input/beowulf.txt ./testFiles/commands/display ./testFiles/output/gTestLong1.txt >> ./testFiles/error/gerrorLong1.error
	./trees -r ./testFiles/input/beowulf.txt ./testFiles/commands/display ./testFiles/output/rbTestLong1.txt >> ./testFiles/error/rberrorLong1.error
	
	@echo Running your code on submission 0
	./trees -g ./testFiles/hisTests/trees.0 ./testFiles/hisTests/trees.1 ./testFiles/myOut/test6.txt
	./trees -r ./testFiles/hisTests/trees.0 ./testFiles/hisTests/trees.1 ./testFiles/myOut/test7.txt
	./trees -g ./testFiles/hisTests/trees.0 ./testFiles/hisTests/trees.1 ./testFiles/myOut/test12.txt
	./trees -r ./testFiles/hisTests/trees.0 ./testFiles/hisTests/trees.1 ./testFiles/myOut/test13.txt
	./trees -g ./testFiles/hisTests/test-0-0.corpus ./testFiles/hisTests/test-0-0.go ./testFiles/myOut/test14.txt
	./trees -r ./testFiles/hisTests/test-0-0.corpus ./testFiles/hisTests/test-0-0.go ./testFiles/myOut/test15.txt
	./trees -g ./testFiles/hisTests/test-0-1.corpus ./testFiles/hisTests/test-0-1.go ./testFiles/myOut/test16.txt
	./trees -r ./testFiles/hisTests/test-0-1.corpus ./testFiles/hisTests/test-0-1.go ./testFiles/myOut/test17.txt
	./trees -g ./testFiles/hisTests/test-0-2.corpus ./testFiles/hisTests/test-0-2.go ./testFiles/myOut/test18.txt
	./trees -r ./testFiles/hisTests/test-0-2.corpus ./testFiles/hisTests/test-0-2.go ./testFiles/myOut/test19.txt
	./trees -g ./testFiles/hisTests/test-0-3.corpus ./testFiles/hisTests/test-0-3.go ./testFiles/myOut/test20.txt
	./trees -r ./testFiles/hisTests/test-0-3.corpus ./testFiles/hisTests/test-0-3.go ./testFiles/myOut/test21.txt
	./trees -g ./testFiles/hisTests/test-0-4.corpus ./testFiles/hisTests/test-0-4.go ./testFiles/myOut/test22.txt
	./trees -r ./testFiles/hisTests/test-0-4.corpus ./testFiles/hisTests/test-0-4.go ./testFiles/myOut/test23.txt
	./trees -g ./testFiles/hisTests/test-0-5.corpus ./testFiles/hisTests/test-0-5.go ./testFiles/myOut/test24.txt
	./trees -r ./testFiles/hisTests/test-0-5.corpus ./testFiles/hisTests/test-0-5.go ./testFiles/myOut/test25.txt
	./trees -g ./testFiles/hisTests/test-0-6.corpus ./testFiles/hisTests/test-0-6.go ./testFiles/myOut/test26.txt
	./trees -r ./testFiles/hisTests/test-0-6.corpus ./testFiles/hisTests/test-0-6.go ./testFiles/myOut/test27.txt
	./trees -g ./testFiles/hisTests/test-0-7.corpus ./testFiles/hisTests/test-0-7.go ./testFiles/myOut/test28.txt
	./trees -r ./testFiles/hisTests/test-0-7.corpus ./testFiles/hisTests/test-0-7.go ./testFiles/myOut/test29.txt
	./trees -g ./testFiles/hisTests/test-0-8.corpus ./testFiles/hisTests/test-0-8.go ./testFiles/myOut/test30.txt
	./trees -r ./testFiles/hisTests/test-0-8.corpus ./testFiles/hisTests/test-0-8.go ./testFiles/myOut/test31.txt
	./trees -g ./testFiles/hisTests/test-0-9.corpus ./testFiles/hisTests/test-0-9.go ./testFiles/myOut/test32.txt
	./trees -r ./testFiles/hisTests/test-0-9.corpus ./testFiles/hisTests/test-0-9.go ./testFiles/myOut/test33.txt
	./trees -g ./testFiles/hisTests/test-0-10.corpus ./testFiles/hisTests/test-0-10.go ./testFiles/myOut/test34.txt
	./trees -r ./testFiles/hisTests/test-0-10.corpus ./testFiles/hisTests/test-0-10.go ./testFiles/myOut/test35.txt
	./trees -g ./testFiles/hisTests/test-0-11.corpus ./testFiles/hisTests/test-0-11.go ./testFiles/myOut/test36.txt
	./trees -r ./testFiles/hisTests/test-0-11.corpus ./testFiles/hisTests/test-0-11.go ./testFiles/myOut/test37.txt
	./trees -g ./testFiles/hisTests/test-0-12.corpus ./testFiles/hisTests/test-0-12.go ./testFiles/myOut/test38.txt
	./trees -r ./testFiles/hisTests/test-0-12.corpus ./testFiles/hisTests/test-0-12.go ./testFiles/myOut/test39.txt
	./trees -g ./testFiles/hisTests/test-0-13.corpus ./testFiles/hisTests/test-0-13.go ./testFiles/myOut/test40.txt
	./trees -r ./testFiles/hisTests/test-0-13.corpus ./testFiles/hisTests/test-0-13.go ./testFiles/myOut/test41.txt
	./trees -g ./testFiles/hisTests/test-0-14.corpus ./testFiles/hisTests/test-0-14.go ./testFiles/myOut/test42.txt
	./trees -r ./testFiles/hisTests/test-0-14.corpus ./testFiles/hisTests/test-0-14.go ./testFiles/myOut/test43.txt
	@echo Running large files from Submission 0
	./trees -g ./testFiles/hisTests/beowulf.txt ./testFiles/hisTests/beowulf.go1 ./testFiles/myOut/test44.txt
	./trees -r ./testFiles/hisTests/beowulf.txt ./testFiles/hisTests/beowulf.go1 ./testFiles/myOut/test45.txt
	./trees -g ./testFiles/hisTests/beowulf.txt ./testFiles/hisTests/beowulf.go2 ./testFiles/myOut/test46.txt
	./trees -r ./testFiles/hisTests/beowulf.txt ./testFiles/hisTests/beowulf.go2 ./testFiles/myOut/test47.txt
	./trees -g ./testFiles/hisTests/shakespeare.txt ./testFiles/hisTests/shakespeare.go1 ./testFiles/myOut/test48.txt
	./trees -r ./testFiles/hisTests/shakespeare.txt ./testFiles/hisTests/shakespeare.go1 ./testFiles/myOut/test49.txt
	./trees -g ./testFiles/hisTests/shakespeare.txt ./testFiles/hisTests/shakespeare.go2 ./testFiles/myOut/test50.txt
	./trees -r ./testFiles/hisTests/shakespeare.txt ./testFiles/hisTests/shakespeare.go2 ./testFiles/myOut/test51.txt
	
	@echo Comparing your files against Lusths Outputs
	diff ./testFiles/hisOut/test6.txt ./testFiles/myOut/test6.txt
	diff ./testFiles/hisOut/test7.txt ./testFiles/myOut/test7.txt
	diff ./testFiles/hisOut/test12.txt ./testFiles/myOut/test12.txt
	diff ./testFiles/hisOut/test13.txt ./testFiles/myOut/test13.txt
	diff ./testFiles/hisOut/test14.txt ./testFiles/myOut/test14.txt
	diff ./testFiles/hisOut/test15.txt ./testFiles/myOut/test15.txt
	diff ./testFiles/hisOut/test16.txt ./testFiles/myOut/test16.txt
	diff ./testFiles/hisOut/test17.txt ./testFiles/myOut/test17.txt
	diff ./testFiles/hisOut/test18.txt ./testFiles/myOut/test18.txt
	diff ./testFiles/hisOut/test19.txt ./testFiles/myOut/test19.txt
	diff ./testFiles/hisOut/test20.txt ./testFiles/myOut/test20.txt
	diff ./testFiles/hisOut/test21.txt ./testFiles/myOut/test21.txt
	diff ./testFiles/hisOut/test22.txt ./testFiles/myOut/test22.txt
	diff ./testFiles/hisOut/test23.txt ./testFiles/myOut/test23.txt
	diff ./testFiles/hisOut/test24.txt ./testFiles/myOut/test24.txt
	diff ./testFiles/hisOut/test25.txt ./testFiles/myOut/test25.txt
	diff ./testFiles/hisOut/test26.txt ./testFiles/myOut/test26.txt
	diff ./testFiles/hisOut/test27.txt ./testFiles/myOut/test27.txt
	diff ./testFiles/hisOut/test28.txt ./testFiles/myOut/test28.txt
	diff ./testFiles/hisOut/test29.txt ./testFiles/myOut/test29.txt
	diff ./testFiles/hisOut/test30.txt ./testFiles/myOut/test30.txt
	diff ./testFiles/hisOut/test31.txt ./testFiles/myOut/test31.txt
	diff ./testFiles/hisOut/test32.txt ./testFiles/myOut/test32.txt
	diff ./testFiles/hisOut/test33.txt ./testFiles/myOut/test33.txt
	diff ./testFiles/hisOut/test34.txt ./testFiles/myOut/test34.txt
	diff ./testFiles/hisOut/test35.txt ./testFiles/myOut/test35.txt
	diff ./testFiles/hisOut/test36.txt ./testFiles/myOut/test36.txt
	diff ./testFiles/hisOut/test37.txt ./testFiles/myOut/test37.txt
	diff ./testFiles/hisOut/test38.txt ./testFiles/myOut/test38.txt
	diff ./testFiles/hisOut/test39.txt ./testFiles/myOut/test39.txt
	diff ./testFiles/hisOut/test40.txt ./testFiles/myOut/test40.txt
	diff ./testFiles/hisOut/test41.txt ./testFiles/myOut/test41.txt
	diff ./testFiles/hisOut/test42.txt ./testFiles/myOut/test42.txt
	diff ./testFiles/hisOut/test43.txt ./testFiles/myOut/test43.txt
	diff ./testFiles/hisOut/test44.txt ./testFiles/myOut/test44.txt
	diff ./testFiles/hisOut/test45.txt ./testFiles/myOut/test45.txt
	diff ./testFiles/hisOut/test46.txt ./testFiles/myOut/test46.txt
	diff ./testFiles/hisOut/test47.txt ./testFiles/myOut/test47.txt
	diff ./testFiles/hisOut/test48.txt ./testFiles/myOut/test48.txt
	diff ./testFiles/hisOut/test49.txt ./testFiles/myOut/test49.txt
	diff ./testFiles/hisOut/test50.txt ./testFiles/myOut/test50.txt
	diff ./testFiles/hisOut/test51.txt ./testFiles/myOut/test51.txt
	
	@echo Comparing your green tree outputs against my Outputs
	diff ./testFiles/givenOutput/one.txt ./testFiles/output/one.txt
	diff ./testFiles/givenOutput/gtest0.txt ./testFiles/output/gtest0.txt
	diff ./testFiles/givenOutput/gtest1.txt ./testFiles/output/gtest1.txt
	diff ./testFiles/givenOutput/gtest2.txt ./testFiles/output/gtest2.txt
	diff ./testFiles/givenOutput/gtest3.txt ./testFiles/output/gtest3.txt
	diff ./testFiles/givenOutput/gtest4.txt ./testFiles/output/gtest4.txt
	diff ./testFiles/givenOutput/gtest5.txt ./testFiles/output/gtest5.txt
	diff ./testFiles/givenOutput/gtest6.txt ./testFiles/output/gtest6.txt
	diff ./testFiles/givenOutput/gtest7.txt ./testFiles/output/gtest7.txt
	diff ./testFiles/givenOutput/gtest8.txt ./testFiles/output/gtest8.txt
	diff ./testFiles/givenOutput/gtest9.txt ./testFiles/output/gtest9.txt
	diff ./testFiles/givenOutput/gtest10.txt ./testFiles/output/gtest10.txt
	diff ./testFiles/givenOutput/gtest11.txt ./testFiles/output/gtest11.txt
	diff ./testFiles/givenOutput/gtest12.txt ./testFiles/output/gtest12.txt
	diff ./testFiles/givenOutput/gtest13.txt ./testFiles/output/gtest13.txt
	diff ./testFiles/givenOutput/gtest14.txt ./testFiles/output/gtest14.txt
	diff ./testFiles/givenOutput/gtest15.txt ./testFiles/output/gtest15.txt
	diff ./testFiles/givenOutput/gtest16.txt ./testFiles/output/gtest16.txt
	diff ./testFiles/givenOutput/gtest17.txt ./testFiles/output/gtest17.txt
	diff ./testFiles/givenOutput/gtest18.txt ./testFiles/output/gtest18.txt
	diff ./testFiles/givenOutput/gtest19.txt ./testFiles/output/gtest19.txt
	diff ./testFiles/givenOutput/gtest20.txt ./testFiles/output/gtest20.txt
	diff ./testFiles/givenOutput/gtest21.txt ./testFiles/output/gtest21.txt
	diff ./testFiles/givenOutput/gtest22.txt ./testFiles/output/gtest22.txt
	diff ./testFiles/givenOutput/gtest23.txt ./testFiles/output/gtest23.txt
	diff ./testFiles/givenOutput/gtest24.txt ./testFiles/output/gtest24.txt
	diff ./testFiles/givenOutput/gtest25.txt ./testFiles/output/gtest25.txt
	diff ./testFiles/givenOutput/gtest26.txt ./testFiles/output/gtest26.txt
	diff ./testFiles/givenOutput/gtest27.txt ./testFiles/output/gtest27.txt
	diff ./testFiles/givenOutput/gtest28.txt ./testFiles/output/gtest28.txt
	diff ./testFiles/givenOutput/gtest29.txt ./testFiles/output/gtest29.txt
	diff ./testFiles/givenOutput/gtest30.txt ./testFiles/output/gtest30.txt
	diff ./testFiles/givenOutput/gtestd1.txt ./testFiles/output/gtestd1.txt
	diff ./testFiles/givenOutput/gtestd2.txt ./testFiles/output/gtestd2.txt
	diff ./testFiles/givenOutput/gtestd3.txt ./testFiles/output/gtestd3.txt
	diff ./testFiles/givenOutput/gtestd4.txt ./testFiles/output/gtestd4.txt
	diff ./testFiles/givenOutput/gtestd5.txt ./testFiles/output/gtestd5.txt
	diff ./testFiles/givenOutput/gtestd6.txt ./testFiles/output/gtestd6.txt
	
	@echo Comparing your red black tree outputs against my Outputs
	diff ./testFiles/givenOutput/rbtest0.txt ./testFiles/output/rbtest0.txt
	diff ./testFiles/givenOutput/rbtest1.txt ./testFiles/output/rbtest1.txt
	diff ./testFiles/givenOutput/rbtest2.txt ./testFiles/output/rbtest2.txt
	diff ./testFiles/givenOutput/rbtest3.txt ./testFiles/output/rbtest3.txt
	diff ./testFiles/givenOutput/rbtest4.txt ./testFiles/output/rbtest4.txt
	diff ./testFiles/givenOutput/rbtest5.txt ./testFiles/output/rbtest5.txt
	diff ./testFiles/givenOutput/rbtest6.txt ./testFiles/output/rbtest6.txt
	diff ./testFiles/givenOutput/rbtest7.txt ./testFiles/output/rbtest7.txt
	diff ./testFiles/givenOutput/rbtest8.txt ./testFiles/output/rbtest8.txt
	diff ./testFiles/givenOutput/rbtest9.txt ./testFiles/output/rbtest9.txt
	diff ./testFiles/givenOutput/rbtest10.txt ./testFiles/output/rbtest10.txt
	diff ./testFiles/givenOutput/rbtest11.txt ./testFiles/output/rbtest11.txt
	diff ./testFiles/givenOutput/rbtest12.txt ./testFiles/output/rbtest12.txt
	diff ./testFiles/givenOutput/rbtest13.txt ./testFiles/output/rbtest13.txt
	diff ./testFiles/givenOutput/rbtest14.txt ./testFiles/output/rbtest14.txt
	diff ./testFiles/givenOutput/rbtest15.txt ./testFiles/output/rbtest15.txt
	diff ./testFiles/givenOutput/rbtest16.txt ./testFiles/output/rbtest16.txt
	diff ./testFiles/givenOutput/rbtest17.txt ./testFiles/output/rbtest17.txt
	diff ./testFiles/givenOutput/rbtest18.txt ./testFiles/output/rbtest18.txt
	diff ./testFiles/givenOutput/rbtest19.txt ./testFiles/output/rbtest19.txt
	diff ./testFiles/givenOutput/rbtest20.txt ./testFiles/output/rbtest20.txt
	diff ./testFiles/givenOutput/rbtest21.txt ./testFiles/output/rbtest21.txt
	diff ./testFiles/givenOutput/rbtest22.txt ./testFiles/output/rbtest22.txt
	diff ./testFiles/givenOutput/rbtest23.txt ./testFiles/output/rbtest23.txt
	diff ./testFiles/givenOutput/rbtest24.txt ./testFiles/output/rbtest24.txt
	diff ./testFiles/givenOutput/rbtest25.txt ./testFiles/output/rbtest25.txt
	diff ./testFiles/givenOutput/rbtest26.txt ./testFiles/output/rbtest26.txt
	diff ./testFiles/givenOutput/rbtest27.txt ./testFiles/output/rbtest27.txt
	diff ./testFiles/givenOutput/rbtest28.txt ./testFiles/output/rbtest28.txt
	diff ./testFiles/givenOutput/rbtest29.txt ./testFiles/output/rbtest29.txt
	diff ./testFiles/givenOutput/rbtest30.txt ./testFiles/output/rbtest30.txt
	diff ./testFiles/givenOutput/rbtestd1.txt ./testFiles/output/rbtestd1.txt
	diff ./testFiles/givenOutput/rbtestd2.txt ./testFiles/output/rbtestd2.txt
	diff ./testFiles/givenOutput/rbtestd3.txt ./testFiles/output/rbtestd3.txt
	diff ./testFiles/givenOutput/rbtestd4.txt ./testFiles/output/rbtestd4.txt
	diff ./testFiles/givenOutput/rbtestd5.txt ./testFiles/output/rbtestd5.txt
	diff ./testFiles/givenOutput/rbtestd6.txt ./testFiles/output/rbtestd6.txt
	
	@echo Comparing your green tree errors against my errors
	diff ./testFiles/givenError/gerror0.error ./testFiles/error/gerror0.error
	diff ./testFiles/givenError/gerror1.error ./testFiles/error/gerror1.error
	diff ./testFiles/givenError/gerror2.error ./testFiles/error/gerror2.error
	diff ./testFiles/givenError/gerror3.error ./testFiles/error/gerror3.error
	diff ./testFiles/givenError/gerror4.error ./testFiles/error/gerror4.error
	diff ./testFiles/givenError/gerror5.error ./testFiles/error/gerror5.error
	diff ./testFiles/givenError/gerror6.error ./testFiles/error/gerror6.error
	diff ./testFiles/givenError/gerror7.error ./testFiles/error/gerror7.error
	diff ./testFiles/givenError/gerror8.error ./testFiles/error/gerror8.error
	diff ./testFiles/givenError/gerror9.error ./testFiles/error/gerror9.error
	diff ./testFiles/givenError/gerror10.error ./testFiles/error/gerror10.error
	diff ./testFiles/givenError/gerror11.error ./testFiles/error/gerror11.error
	diff ./testFiles/givenError/gerror12.error ./testFiles/error/gerror12.error
	diff ./testFiles/givenError/gerror13.error ./testFiles/error/gerror13.error
	diff ./testFiles/givenError/gerror14.error ./testFiles/error/gerror14.error
	diff ./testFiles/givenError/gerror15.error ./testFiles/error/gerror15.error
	diff ./testFiles/givenError/gerror16.error ./testFiles/error/gerror16.error
	diff ./testFiles/givenError/gerror17.error ./testFiles/error/gerror17.error
	diff ./testFiles/givenError/gerror18.error ./testFiles/error/gerror18.error
	diff ./testFiles/givenError/gerror19.error ./testFiles/error/gerror19.error
	diff ./testFiles/givenError/gerror20.error ./testFiles/error/gerror20.error
	diff ./testFiles/givenError/gerror21.error ./testFiles/error/gerror21.error
	diff ./testFiles/givenError/gerror22.error ./testFiles/error/gerror22.error
	diff ./testFiles/givenError/gerror23.error ./testFiles/error/gerror23.error
	diff ./testFiles/givenError/gerror24.error ./testFiles/error/gerror24.error
	diff ./testFiles/givenError/gerror25.error ./testFiles/error/gerror25.error
	diff ./testFiles/givenError/gerror26.error ./testFiles/error/gerror26.error
	diff ./testFiles/givenError/gerror27.error ./testFiles/error/gerror27.error
	diff ./testFiles/givenError/gerror28.error ./testFiles/error/gerror28.error
	diff ./testFiles/givenError/gerror29.error ./testFiles/error/gerror29.error
	diff ./testFiles/givenError/gerror30.error ./testFiles/error/gerror30.error
	diff ./testFiles/givenError/gerrord1.error ./testFiles/error/gerrord1.error
	diff ./testFiles/givenError/gerrord2.error ./testFiles/error/gerrord2.error
	diff ./testFiles/givenError/gerrord3.error ./testFiles/error/gerrord3.error
	diff ./testFiles/givenError/gerrord4.error ./testFiles/error/gerrord4.error
	diff ./testFiles/givenError/gerrord5.error ./testFiles/error/gerrord5.error
	diff ./testFiles/givenError/gerrord6.error ./testFiles/error/gerrord6.error
	
	@echo Comparing your red black tree errors against my errors
	diff ./testFiles/givenError/rberror0.error ./testFiles/error/rberror0.error
	diff ./testFiles/givenError/rberror1.error ./testFiles/error/rberror1.error
	diff ./testFiles/givenError/rberror2.error ./testFiles/error/rberror2.error
	diff ./testFiles/givenError/rberror3.error ./testFiles/error/rberror3.error
	diff ./testFiles/givenError/rberror4.error ./testFiles/error/rberror4.error
	diff ./testFiles/givenError/rberror5.error ./testFiles/error/rberror5.error
	diff ./testFiles/givenError/rberror6.error ./testFiles/error/rberror6.error
	diff ./testFiles/givenError/rberror7.error ./testFiles/error/rberror7.error
	diff ./testFiles/givenError/rberror8.error ./testFiles/error/rberror8.error
	diff ./testFiles/givenError/rberror9.error ./testFiles/error/rberror9.error
	diff ./testFiles/givenError/rberror10.error ./testFiles/error/rberror10.error
	diff ./testFiles/givenError/rberror11.error ./testFiles/error/rberror11.error
	diff ./testFiles/givenError/rberror12.error ./testFiles/error/rberror12.error
	diff ./testFiles/givenError/rberror13.error ./testFiles/error/rberror13.error
	diff ./testFiles/givenError/rberror14.error ./testFiles/error/rberror14.error
	diff ./testFiles/givenError/rberror15.error ./testFiles/error/rberror15.error
	diff ./testFiles/givenError/rberror16.error ./testFiles/error/rberror16.error
	diff ./testFiles/givenError/rberror17.error ./testFiles/error/rberror17.error
	diff ./testFiles/givenError/rberror18.error ./testFiles/error/rberror18.error
	diff ./testFiles/givenError/rberror19.error ./testFiles/error/rberror19.error
	diff ./testFiles/givenError/rberror20.error ./testFiles/error/rberror20.error
	diff ./testFiles/givenError/rberror21.error ./testFiles/error/rberror21.error
	diff ./testFiles/givenError/rberror22.error ./testFiles/error/rberror22.error
	diff ./testFiles/givenError/rberror23.error ./testFiles/error/rberror23.error
	diff ./testFiles/givenError/rberror24.error ./testFiles/error/rberror24.error
	diff ./testFiles/givenError/rberror25.error ./testFiles/error/rberror25.error
	diff ./testFiles/givenError/rberror26.error ./testFiles/error/rberror26.error
	diff ./testFiles/givenError/rberror27.error ./testFiles/error/rberror27.error
	diff ./testFiles/givenError/rberror28.error ./testFiles/error/rberror28.error
	diff ./testFiles/givenError/rberror29.error ./testFiles/error/rberror29.error
	diff ./testFiles/givenError/rberror30.error ./testFiles/error/rberror30.error
	diff ./testFiles/givenError/rberrord1.error ./testFiles/error/rberrord1.error
	diff ./testFiles/givenError/rberrord2.error ./testFiles/error/rberrord2.error
	diff ./testFiles/givenError/rberrord3.error ./testFiles/error/rberrord3.error
	diff ./testFiles/givenError/rberrord4.error ./testFiles/error/rberrord4.error
	diff ./testFiles/givenError/rberrord5.error ./testFiles/error/rberrord5.error
	diff ./testFiles/givenError/rberrord6.error ./testFiles/error/rberrord6.error
	@echo Testing Sequence complete.
