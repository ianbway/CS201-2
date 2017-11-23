SQSO = scanner.o integer.o real.o string.o da.o cda.o stack.o queue.o comparator.o trees.o bst.o rbt.o lettersOnly.o gt.o
#GTESTFILES = 
ALLF = scanner.c scanner.h integer.c integer.h real.c real.h string.c string.h da.c da.h cda.c cda.h stack.c stack.h queue.c queue.h bst.c bst.h rbt.c rbt.h gt.c gt.h trees.c 
GCCE = -Wall -Wextra -g -c -std=c99
TESTC = -Wall -Wextra -g -std=c99
ATEST = trees

all : trees

test : trees
	@echo Testing the Green Tree
	./trees -g ./testFiles/input/onlineExample ./testFiles/commands/onlineExampleCommand ./testFiles/output/gtest0.txt
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/display ./testFiles/output/gtest1.txt
	./trees -g ./testFiles/input/spaces.0 ./testFiles/commands/display ./testFiles/output/gtest2.txt
	./trees -g ./testFiles/input/s9.0 ./testFiles/commands/display ./testFiles/output/gtest3.txt
	./trees -g ./testFiles/input/s10.0 ./testFiles/commands/display ./testFiles/output/gtest4.txt
	./trees -g ./testFiles/input/s11.0 ./testFiles/commands/display ./testFiles/output/gtest5.txt
	./trees -g ./testFiles/input/s12.0 ./testFiles/commands/display ./testFiles/output/gtest6.txt
	./trees -g ./testFiles/input/s13.0 ./testFiles/commands/display ./testFiles/output/gtest7.txt
	./trees -g ./testFiles/input/s14.0 ./testFiles/commands/display ./testFiles/output/gtest8.txt
	./trees -g ./testFiles/input/s15.0 ./testFiles/commands/display ./testFiles/output/gtest9.txt
	./trees -g ./testFiles/input/w16.0 ./testFiles/commands/display ./testFiles/output/gtest10.txt
	./trees -g ./testFiles/input/w17.0 ./testFiles/commands/display ./testFiles/output/gtest11.txt
	./trees -g ./testFiles/input/w18.0 ./testFiles/commands/display ./testFiles/output/gtest12.txt
	./trees -g ./testFiles/input/w19.0 ./testFiles/commands/display ./testFiles/output/gtest13.txt
	./trees -g ./testFiles/input/w20.0 ./testFiles/commands/display ./testFiles/output/gtest14.txt
	./trees -g ./testFiles/input/w21.0 ./testFiles/commands/display ./testFiles/output/gtest15.txt
	./trees -g ./testFiles/input/w22.0 ./testFiles/commands/display ./testFiles/output/gtest16.txt
	./trees -g ./testFiles/input/w23.0 ./testFiles/commands/display ./testFiles/output/gtest17.txt
	./trees -g ./testFiles/input/w24.0 ./testFiles/commands/display ./testFiles/output/gtest18.txt
	@echo Testing the Green Tree with commands
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c25.0 ./testFiles/output/gtest19.txt
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c26.0 ./testFiles/output/gtest20.txt
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c27.0 ./testFiles/output/gtest21.txt
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c28.0 ./testFiles/output/gtest22.txt
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c29.0 ./testFiles/output/gtest23.txt
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c30.0 ./testFiles/output/gtest24.txt
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c31.0 ./testFiles/output/gtest25.txt
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c32.0 ./testFiles/output/gtest26.txt
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c35.0 ./testFiles/output/gtest27.txt
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c36.0 ./testFiles/output/gtest28.txt
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/c37.0 ./testFiles/output/gtest29.txt
	./trees -g ./testFiles/input/empty ./testFiles/commands/commands.0 ./testFiles/output/gtest30.txt
	@echo Starting the Green Tree delete commands
	./trees -g ./testFiles/input/clean.0 ./testFiles/commands/deleteBob ./testFiles/output/gtestd1.txt
	./trees -g ./testFiles/input/spaces.0 ./testFiles/commands/deleteBob ./testFiles/output/gtestd2.txt
	./trees -g ./testFiles/input/clean2.0 ./testFiles/commands/deleteBob ./testFiles/output/gtestd3.txt
	./trees -g ./testFiles/input/spaces2.0 ./testFiles/commands/deleteBob ./testFiles/output/gtestd4.txt
	./trees -g ./testFiles/input/clean2.0 ./testFiles/commands/deleteBob2 ./testFiles/output/gtestd5.txt
	./trees -g ./testFiles/input/spaces2.0 ./testFiles/commands/deleteBob2 ./testFiles/output/gtestd6.txt
	
	@echo Testing the Red-Black Tree
	./trees -r ./testFiles/input/onlineExample ./testFiles/commands/onlineExampleCommand ./testFiles/output/rbtest0.txt
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/display ./testFiles/output/rbtest1.txt
	./trees -r ./testFiles/input/spaces.0 ./testFiles/commands/display ./testFiles/output/rbtest2.txt
	./trees -r ./testFiles/input/s9.0 ./testFiles/commands/display ./testFiles/output/rbtest3.txt
	./trees -r ./testFiles/input/s10.0 ./testFiles/commands/display ./testFiles/output/rbtest4.txt
	./trees -r ./testFiles/input/s11.0 ./testFiles/commands/display ./testFiles/output/rbtest5.txt
	./trees -r ./testFiles/input/s12.0 ./testFiles/commands/display ./testFiles/output/rbtest6.txt
	./trees -r ./testFiles/input/s13.0 ./testFiles/commands/display ./testFiles/output/rbtest7.txt
	./trees -r ./testFiles/input/s14.0 ./testFiles/commands/display ./testFiles/output/rbtest8.txt
	./trees -r ./testFiles/input/s15.0 ./testFiles/commands/display ./testFiles/output/rbtest9.txt
	./trees -r ./testFiles/input/w16.0 ./testFiles/commands/display ./testFiles/output/rbtest10.txt
	./trees -r ./testFiles/input/w17.0 ./testFiles/commands/display ./testFiles/output/rbtest11.txt
	./trees -r ./testFiles/input/w18.0 ./testFiles/commands/display ./testFiles/output/rbtest12.txt
	./trees -r ./testFiles/input/w19.0 ./testFiles/commands/display ./testFiles/output/rbtest13.txt
	./trees -r ./testFiles/input/w20.0 ./testFiles/commands/display ./testFiles/output/rbtest14.txt
	./trees -r ./testFiles/input/w21.0 ./testFiles/commands/display ./testFiles/output/rbtest15.txt
	./trees -r ./testFiles/input/w22.0 ./testFiles/commands/display ./testFiles/output/rbtest16.txt
	./trees -r ./testFiles/input/w23.0 ./testFiles/commands/display ./testFiles/output/rbtest17.txt
	./trees -r ./testFiles/input/w24.0 ./testFiles/commands/display ./testFiles/output/rbtest18.txt
	@echo Testing the Red-Black Tree with commands
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c25.0 ./testFiles/output/rbtest19.txt
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c26.0 ./testFiles/output/rbtest20.txt
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c27.0 ./testFiles/output/rbtest21.txt
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c28.0 ./testFiles/output/rbtest22.txt
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c29.0 ./testFiles/output/rbtest23.txt
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c30.0 ./testFiles/output/rbtest24.txt
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c31.0 ./testFiles/output/rbtest25.txt
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c32.0 ./testFiles/output/rbtest26.txt
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c35.0 ./testFiles/output/rbtest27.txt
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c36.0 ./testFiles/output/rbtest28.txt
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/c37.0 ./testFiles/output/rbtest29.txt
	./trees -r ./testFiles/input/empty ./testFiles/commands/commands.0 ./testFiles/output/rbtest30.txt
	@echo Starting the Red-Black Tree delete commands
	./trees -r ./testFiles/input/clean.0 ./testFiles/commands/deleteBob ./testFiles/output/rbtestd1.txt
	./trees -r ./testFiles/input/spaces.0 ./testFiles/commands/deleteBob ./testFiles/output/rbtestd2.txt
	./trees -r ./testFiles/input/clean2.0 ./testFiles/commands/deleteBob ./testFiles/output/rbtestd3.txt
	./trees -r ./testFiles/input/spaces2.0 ./testFiles/commands/deleteBob ./testFiles/output/rbtestd4.txt
	./trees -r ./testFiles/input/clean2.0 ./testFiles/commands/deleteBob2 ./testFiles/output/rbtestd5.txt
	./trees -r ./testFiles/input/spaces2.0 ./testFiles/commands/deleteBob2 ./testFiles/output/rbtestd6.txt
	
	#diff ./testFiles/output/gtest0.txt ./testFiles/givenOutput/gtest0.txt
	#diff ./testFiles/output/rbtest0.txt ./testFiles/givenOutput/rbtest0.txt
	
	
	@echo dun dun dunnnnn
	@echo Testing with shakespeare
	./trees -g ./testFiles/input/shakespeare.txt ./testFiles/commands/shakespeare.display ./testFiles/output/gtestLong0.txt
	./trees -r ./testFiles/input/shakespeare.txt ./testFiles/commands/shakespeare.display ./testFiles/output/rbtestLong0.txt
	@echo dun dun dunnnnn
	@echo Testing with beowulf
	./trees -g ./testFiles/input/beowulf.txt ./testFiles/commands/display ./testFiles/output/gTestLong1.txt
	./trees -r ./testFiles/input/beowulf.txt ./testFiles/commands/display ./testFiles/output/rbTestLong1.txt
	@echo Testing against existing files
	
	@echo Testing Sequence complete.
	
difftests : trees
	diff btest3.txt test3.txt
	diff btest4.txt test4.txt
	diff btest5.txt test5.txt
	diff btest6.txt test6.txt
	diff btest7.txt test7.txt
	diff btest8.txt test8.txt
	diff btest9.txt test9.txt
	diff btest10.txt test10.txt
	diff btest11.txt test11.txt
	diff btest12.txt test12.txt
	diff btest13.txt test13.txt
	diff btest14.txt test14.txt
	diff btest15.txt test15.txt
	diff btest16.txt test16.txt
	diff btest17.txt test17.txt
	diff btest18.txt test18.txt
	diff btest19.txt test19.txt
	diff btest20.txt test20.txt
	diff btest21.txt test21.txt
	diff btest22.txt test22.txt
	diff btest23.txt test23.txt
	diff btest24.txt test24.txt
	diff btest25.txt test25.txt
	diff btest26.txt test26.txt
	diff btest27.txt test27.txt
	diff btest28.txt test28.txt
	diff btest29.txt test29.txt
	diff btest30.txt test30.txt
	diff btest31.txt test31.txt
	diff btest32.txt test32.txt
	diff btest33.txt test33.txt
	diff btest34.txt test34.txt
	diff btest35.txt test35.txt
	diff btest36.txt test36.txt
	diff btest37.txt test37.txt
	
testv : trees
	./trees -v data.txt cmd.txt
	./trees -v data2.txt cmd.txt

testvFails : trees
	# Test 25
	
testr : trees
	./trees -r data.txt cmd.txt
	./trees -r data2.txt cmd.txt

trees : $(SQSO)
	gcc $(TESTC) -o trees $(SQSO)
	
scanner.o : scanner.c scanner.h
	gcc $(GCCE) scanner.c
	
integer.o : integer.c integer.h
	gcc $(GCCE) integer.c

real.o : real.c real.h
	gcc $(GCCE) real.c	
	
string.o : string.c string.h
	gcc $(GCCE) string.c
	
trees.o : trees.c
	gcc $(GCCE) trees.c	

bst.o : bst.c bst.h
	gcc $(GCCE) bst.c	

rbt.o : rbt.c rbt.h
	gcc $(GCCE) rbt.c	

gt.o : gt.c gt.h
	gcc $(GCCE) gt.c	
	
comparator.o : comparator.c comparator.h
	gcc $(GCCE) comparator.c

lettersOnly.o : lettersOnly.c lettersOnly.h
	gcc $(GCCE) lettersOnly.c
	
da.o :	da.c da.h
	gcc $(GCCE) da.c	
	
cda.o :	cda.c cda.h
	gcc $(GCCE) cda.c
	
stack.o : stack.c stack.h
	gcc $(GCCE) stack.c

queue.o : queue.c queue.h
	gcc $(GCCE) queue.c
	
clean: 
	rm -f $(SQSO) $(TESTFILES) $(ATEST)
