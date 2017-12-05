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

test : kruskal

	@echo Removing previous outputs.
	#rm ./testFiles/submission0/myOutput/*
	
	
	@echo Running submission0 tests. Very quick.
	kruskal ./testFiles/submission0/input/g0 >> ./testFiles/submission0/myOutput/g0
	kruskal ./testFiles/submission0/input/g1 >> ./testFiles/submission0/myOutput/g1
	kruskal ./testFiles/submission0/input/g2 >> ./testFiles/submission0/myOutput/g2
	kruskal ./testFiles/submission0/input/g-0-0 >> ./testFiles/submission0/myOutput/g-0-0
	kruskal ./testFiles/submission0/input/g-0-1 >> ./testFiles/submission0/myOutput/g-0-1
	kruskal ./testFiles/submission0/input/g-0-2 >> ./testFiles/submission0/myOutput/g-0-2
	kruskal ./testFiles/submission0/input/g-0-3 >> ./testFiles/submission0/myOutput/g-0-3
	kruskal ./testFiles/submission0/input/g-0-4 >> ./testFiles/submission0/myOutput/g-0-4
	kruskal ./testFiles/submission0/input/g-0-5 >> ./testFiles/submission0/myOutput/g-0-5
	kruskal ./testFiles/submission0/input/g-0-6 >> ./testFiles/submission0/myOutput/g-0-6
	kruskal ./testFiles/submission0/input/g-0-7 >> ./testFiles/submission0/myOutput/g-0-7
	kruskal ./testFiles/submission0/input/g-0-8 >> ./testFiles/submission0/myOutput/g-0-8
	kruskal ./testFiles/submission0/input/g-0-9 >> ./testFiles/submission0/myOutput/g-0-9
	kruskal ./testFiles/submission0/input/g-0-10 >> ./testFiles/submission0/myOutput/g-0-10
	
	#rm ./testFiles/output/*
	@echo Running online inputs. Very quick.
	kruskal ./testFiles/input/online1.txt >> ./testFiles/output/online1.txt
	kruskal ./testFiles/input/online2.txt >> ./testFiles/output/online2.txt
	kruskal ./testFiles/input/r0.txt >> ./testFiles/output/r0.txt
	
	@echo Running up to 100 node inputs. Very quick.
	kruskal ./testFiles/input/random10Input0.txt >> ./testFiles/output/random10Output0.txt
	kruskal ./testFiles/input/random10Input1.txt >> ./testFiles/output/random10Output1.txt
	kruskal ./testFiles/input/random10Input2.txt >> ./testFiles/output/random10Output2.txt
	kruskal ./testFiles/input/random10Input3.txt >> ./testFiles/output/random10Output3.txt
	kruskal ./testFiles/input/random10Input4.txt >> ./testFiles/output/random10Output4.txt
	kruskal ./testFiles/input/random10Input5.txt >> ./testFiles/output/random10Output5.txt
	kruskal ./testFiles/input/random10Input6.txt >> ./testFiles/output/random10Output6.txt
	kruskal ./testFiles/input/random10Input7.txt >> ./testFiles/output/random10Output7.txt
	kruskal ./testFiles/input/random10Input8.txt >> ./testFiles/output/random10Output8.txt
	kruskal ./testFiles/input/random10Input9.txt >> ./testFiles/output/random10Output9.txt
	
	@echo Running up to 1,000 node inputs. Very quick.
	kruskal ./testFiles/input/random100Input0.txt >> ./testFiles/output/random100Output0.txt
	kruskal ./testFiles/input/random100Input1.txt >> ./testFiles/output/random100Output1.txt
	kruskal ./testFiles/input/random100Input2.txt >> ./testFiles/output/random100Output2.txt
	kruskal ./testFiles/input/random100Input3.txt >> ./testFiles/output/random100Output3.txt
	kruskal ./testFiles/input/random100Input4.txt >> ./testFiles/output/random100Output4.txt
	kruskal ./testFiles/input/random100Input5.txt >> ./testFiles/output/random100Output5.txt
	kruskal ./testFiles/input/random100Input6.txt >> ./testFiles/output/random100Output6.txt
	kruskal ./testFiles/input/random100Input7.txt >> ./testFiles/output/random100Output7.txt
	kruskal ./testFiles/input/random100Input8.txt >> ./testFiles/output/random100Output8.txt
	kruskal ./testFiles/input/random100Input9.txt >> ./testFiles/output/random100Output9.txt
	kruskal ./testFiles/input/random100Input10.txt >> ./testFiles/output/random100Output10.txt
	kruskal ./testFiles/input/random100Input11.txt >> ./testFiles/output/random100Output11.txt
	kruskal ./testFiles/input/random100Input12.txt >> ./testFiles/output/random100Output12.txt
	kruskal ./testFiles/input/random100Input13.txt >> ./testFiles/output/random100Output13.txt
	kruskal ./testFiles/input/random100Input14.txt >> ./testFiles/output/random100Output14.txt
	kruskal ./testFiles/input/random100Input15.txt >> ./testFiles/output/random100Output15.txt
	kruskal ./testFiles/input/random100Input16.txt >> ./testFiles/output/random100Output16.txt
	kruskal ./testFiles/input/random100Input17.txt >> ./testFiles/output/random100Output17.txt
	kruskal ./testFiles/input/random100Input18.txt >> ./testFiles/output/random100Output18.txt
	kruskal ./testFiles/input/random100Input19.txt >> ./testFiles/output/random100Output19.txt
	
	@echo Running up to 10,000 node inputs. Very quick.
	kruskal ./testFiles/input/random1000Input0.txt >> ./testFiles/output/random1000Output0.txt
	kruskal ./testFiles/input/random1000Input1.txt >> ./testFiles/output/random1000Output1.txt
	kruskal ./testFiles/input/random1000Input2.txt >> ./testFiles/output/random1000Output2.txt
	kruskal ./testFiles/input/random1000Input3.txt >> ./testFiles/output/random1000Output3.txt
	kruskal ./testFiles/input/random1000Input4.txt >> ./testFiles/output/random1000Output4.txt
	kruskal ./testFiles/input/random1000Input5.txt >> ./testFiles/output/random1000Output5.txt
	kruskal ./testFiles/input/random1000Input6.txt >> ./testFiles/output/random1000Output6.txt
	kruskal ./testFiles/input/random1000Input7.txt >> ./testFiles/output/random1000Output7.txt
	kruskal ./testFiles/input/random1000Input8.txt >> ./testFiles/output/random1000Output8.txt
	kruskal ./testFiles/input/random1000Input9.txt >> ./testFiles/output/random1000Output9.txt
	kruskal ./testFiles/input/random1000Input10.txt >> ./testFiles/output/random1000Output10.txt
	kruskal ./testFiles/input/random1000Input11.txt >> ./testFiles/output/random1000Output11.txt
	kruskal ./testFiles/input/random1000Input12.txt >> ./testFiles/output/random1000Output12.txt
	kruskal ./testFiles/input/random1000Input13.txt >> ./testFiles/output/random1000Output13.txt
	kruskal ./testFiles/input/random1000Input14.txt >> ./testFiles/output/random1000Output14.txt
	kruskal ./testFiles/input/random1000Input15.txt >> ./testFiles/output/random1000Output15.txt
	kruskal ./testFiles/input/random1000Input16.txt >> ./testFiles/output/random1000Output16.txt
	kruskal ./testFiles/input/random1000Input17.txt >> ./testFiles/output/random1000Output17.txt
	kruskal ./testFiles/input/random1000Input18.txt >> ./testFiles/output/random1000Output18.txt
	kruskal ./testFiles/input/random1000Input19.txt >> ./testFiles/output/random1000Output19.txt
	@echo Added empty weights every 100ish inputs.
	kruskal ./testFiles/input/random1000Input20.txt >> ./testFiles/output/random1000Output20.txt
	kruskal ./testFiles/input/random1000Input21.txt >> ./testFiles/output/random1000Output21.txt
	kruskal ./testFiles/input/random1000Input22.txt >> ./testFiles/output/random1000Output22.txt
	kruskal ./testFiles/input/random1000Input23.txt >> ./testFiles/output/random1000Output23.txt
	kruskal ./testFiles/input/random1000Input24.txt >> ./testFiles/output/random1000Output24.txt
	kruskal ./testFiles/input/random1000Input25.txt >> ./testFiles/output/random1000Output25.txt
	kruskal ./testFiles/input/random1000Input26.txt >> ./testFiles/output/random1000Output26.txt
	kruskal ./testFiles/input/random1000Input27.txt >> ./testFiles/output/random1000Output27.txt
	kruskal ./testFiles/input/random1000Input28.txt >> ./testFiles/output/random1000Output28.txt
	kruskal ./testFiles/input/random1000Input29.txt >> ./testFiles/output/random1000Output29.txt
	@echo Running on sparse inputs which makes them run slightly slower.
	kruskal ./testFiles/input/random1000Input30.txt >> ./testFiles/output/random1000Output30.txt
	kruskal ./testFiles/input/random1000Input31.txt >> ./testFiles/output/random1000Output31.txt
	kruskal ./testFiles/input/random1000Input32.txt >> ./testFiles/output/random1000Output32.txt
	kruskal ./testFiles/input/random1000Input33.txt >> ./testFiles/output/random1000Output33.txt
	kruskal ./testFiles/input/random1000Input34.txt >> ./testFiles/output/random1000Output34.txt
	kruskal ./testFiles/input/random1000Input35.txt >> ./testFiles/output/random1000Output35.txt
	kruskal ./testFiles/input/random1000Input36.txt >> ./testFiles/output/random1000Output36.txt
	kruskal ./testFiles/input/random1000Input37.txt >> ./testFiles/output/random1000Output37.txt
	kruskal ./testFiles/input/random1000Input38.txt >> ./testFiles/output/random1000Output38.txt
	kruskal ./testFiles/input/random1000Input39.txt >> ./testFiles/output/random1000Output39.txt
	
	@echo Running up to 100,000 node inputs. Typically take 1-2 seconds for 100,000 nodes.
	kruskal ./testFiles/input/random10000Input0.txt >> ./testFiles/output/random10000Output0.txt
	kruskal ./testFiles/input/random10000Input1.txt >> ./testFiles/output/random10000Output1.txt
	kruskal ./testFiles/input/random10000Input2.txt >> ./testFiles/output/random10000Output2.txt
	kruskal ./testFiles/input/random10000Input3.txt >> ./testFiles/output/random10000Output3.txt
	kruskal ./testFiles/input/random10000Input4.txt >> ./testFiles/output/random10000Output4.txt
	kruskal ./testFiles/input/random10000Input5.txt >> ./testFiles/output/random10000Output5.txt
	kruskal ./testFiles/input/random10000Input6.txt >> ./testFiles/output/random10000Output6.txt
	kruskal ./testFiles/input/random10000Input7.txt >> ./testFiles/output/random10000Output7.txt
	kruskal ./testFiles/input/random10000Input8.txt >> ./testFiles/output/random10000Output8.txt
	kruskal ./testFiles/input/random10000Input9.txt >> ./testFiles/output/random10000Output9.txt
	kruskal ./testFiles/input/random10000Input10.txt >> ./testFiles/output/random10000Output10.txt
	kruskal ./testFiles/input/random10000Input11.txt >> ./testFiles/output/random10000Output11.txt
	kruskal ./testFiles/input/random10000Input12.txt >> ./testFiles/output/random10000Output12.txt
	kruskal ./testFiles/input/random10000Input13.txt >> ./testFiles/output/random10000Output13.txt
	kruskal ./testFiles/input/random10000Input14.txt >> ./testFiles/output/random10000Output14.txt
	kruskal ./testFiles/input/random10000Input15.txt >> ./testFiles/output/random10000Output15.txt
	
	@echo Running up to 1,000,000 node inputs. These files take a while around 10 seconds each for me.
	@echo 
	@echo They are optional. I included them seperately because they are so large. 10MB each.
	@echo 
	#rm ./largeFiles/largeOutput/*
	#kruskal ./largeFiles/largeInput/random100000Input0.txt >> ./largeFiles/largeOutput/random100000Output0.txt
	#kruskal ./largeFiles/largeInput/random100000Input1.txt >> ./largeFiles/largeOutput/random100000Output1.txt
	#kruskal ./largeFiles/largeInput/random100000Input2.txt >> ./largeFiles/largeOutput/random100000Output2.txt
	#kruskal ./largeFiles/largeInput/random100000Input3.txt >> ./largeFiles/largeOutput/random100000Output3.txt
	
	@echo Comparing your files to Dr. Lusths output
	diff ./testFiles/submission0/hisOutput/g0.expected ./testFiles/submission0/myOutput/g0
	diff ./testFiles/submission0/hisOutput/g1.expected ./testFiles/submission0/myOutput/g1
	diff ./testFiles/submission0/hisOutput/g2.expected ./testFiles/submission0/myOutput/g2
	diff ./testFiles/submission0/hisOutput/g-0-0.expected ./testFiles/submission0/myOutput/g-0-0
	diff ./testFiles/submission0/hisOutput/g-0-1.expected ./testFiles/submission0/myOutput/g-0-1
	diff ./testFiles/submission0/hisOutput/g-0-2.expected ./testFiles/submission0/myOutput/g-0-2
	diff ./testFiles/submission0/hisOutput/g-0-3.expected ./testFiles/submission0/myOutput/g-0-3
	diff ./testFiles/submission0/hisOutput/g-0-4.expected ./testFiles/submission0/myOutput/g-0-4
	diff ./testFiles/submission0/hisOutput/g-0-5.expected ./testFiles/submission0/myOutput/g-0-5
	diff ./testFiles/submission0/hisOutput/g-0-6.expected ./testFiles/submission0/myOutput/g-0-6
	diff ./testFiles/submission0/hisOutput/g-0-7.expected ./testFiles/submission0/myOutput/g-0-7
	diff ./testFiles/submission0/hisOutput/g-0-8.expected ./testFiles/submission0/myOutput/g-0-8
	diff ./testFiles/submission0/hisOutput/g-0-9.expected ./testFiles/submission0/myOutput/g-0-9
	diff ./testFiles/submission0/hisOutput/g-0-10.expected ./testFiles/submission0/myOutput/g-0-10	

	diff ./testFiles/output/random10Output0.txt ./testFiles/givenOutput/random10Output0.txt 
	diff ./testFiles/output/random10Output1.txt ./testFiles/givenOutput/random10Output1.txt 
	diff ./testFiles/output/random10Output2.txt ./testFiles/givenOutput/random10Output2.txt 
	diff ./testFiles/output/random10Output3.txt ./testFiles/givenOutput/random10Output3.txt 
	diff ./testFiles/output/random10Output4.txt ./testFiles/givenOutput/random10Output4.txt 
	diff ./testFiles/output/random10Output5.txt ./testFiles/givenOutput/random10Output5.txt 
	diff ./testFiles/output/random10Output6.txt ./testFiles/givenOutput/random10Output6.txt 
	diff ./testFiles/output/random10Output7.txt ./testFiles/givenOutput/random10Output7.txt 
	diff ./testFiles/output/random10Output8.txt ./testFiles/givenOutput/random10Output8.txt 
	diff ./testFiles/output/random10Output9.txt ./testFiles/givenOutput/random10Output9.txt 
	
	diff ./testFiles/output/random100Output0.txt ./testFiles/givenOutput/random100Output0.txt 
	diff ./testFiles/output/random100Output1.txt ./testFiles/givenOutput/random100Output1.txt 
	diff ./testFiles/output/random100Output2.txt ./testFiles/givenOutput/random100Output2.txt 
	diff ./testFiles/output/random100Output3.txt ./testFiles/givenOutput/random100Output3.txt 
	diff ./testFiles/output/random100Output4.txt ./testFiles/givenOutput/random100Output4.txt 
	diff ./testFiles/output/random100Output5.txt ./testFiles/givenOutput/random100Output5.txt 
	diff ./testFiles/output/random100Output6.txt ./testFiles/givenOutput/random100Output6.txt 
	diff ./testFiles/output/random100Output7.txt ./testFiles/givenOutput/random100Output7.txt 
	diff ./testFiles/output/random100Output8.txt ./testFiles/givenOutput/random100Output8.txt 
	diff ./testFiles/output/random100Output9.txt ./testFiles/givenOutput/random100Output9.txt 
	diff ./testFiles/output/random100Output10.txt ./testFiles/givenOutput/random100Output10.txt 
	diff ./testFiles/output/random100Output11.txt ./testFiles/givenOutput/random100Output11.txt 
	diff ./testFiles/output/random100Output12.txt ./testFiles/givenOutput/random100Output12.txt 
	diff ./testFiles/output/random100Output13.txt ./testFiles/givenOutput/random100Output13.txt 
	diff ./testFiles/output/random100Output14.txt ./testFiles/givenOutput/random100Output14.txt 
	diff ./testFiles/output/random100Output15.txt ./testFiles/givenOutput/random100Output15.txt 
	diff ./testFiles/output/random100Output16.txt ./testFiles/givenOutput/random100Output16.txt 
	diff ./testFiles/output/random100Output17.txt ./testFiles/givenOutput/random100Output17.txt 
	diff ./testFiles/output/random100Output18.txt ./testFiles/givenOutput/random100Output18.txt 
	diff ./testFiles/output/random100Output19.txt ./testFiles/givenOutput/random100Output19.txt 
	
	diff ./testFiles/output/random1000Output0.txt ./testFiles/givenOutput/random1000Output0.txt 
	diff ./testFiles/output/random1000Output1.txt ./testFiles/givenOutput/random1000Output1.txt 
	diff ./testFiles/output/random1000Output2.txt ./testFiles/givenOutput/random1000Output2.txt 
	diff ./testFiles/output/random1000Output3.txt ./testFiles/givenOutput/random1000Output3.txt 
	diff ./testFiles/output/random1000Output4.txt ./testFiles/givenOutput/random1000Output4.txt 
	diff ./testFiles/output/random1000Output5.txt ./testFiles/givenOutput/random1000Output5.txt 
	diff ./testFiles/output/random1000Output6.txt ./testFiles/givenOutput/random1000Output6.txt 
	diff ./testFiles/output/random1000Output7.txt ./testFiles/givenOutput/random1000Output7.txt 
	diff ./testFiles/output/random1000Output8.txt ./testFiles/givenOutput/random1000Output8.txt 
	diff ./testFiles/output/random1000Output9.txt ./testFiles/givenOutput/random1000Output9.txt 
	diff ./testFiles/output/random1000Output10.txt ./testFiles/givenOutput/random1000Output10.txt 
	diff ./testFiles/output/random1000Output11.txt ./testFiles/givenOutput/random1000Output11.txt 
	diff ./testFiles/output/random1000Output12.txt ./testFiles/givenOutput/random1000Output12.txt 
	diff ./testFiles/output/random1000Output13.txt ./testFiles/givenOutput/random1000Output13.txt 
	diff ./testFiles/output/random1000Output14.txt ./testFiles/givenOutput/random1000Output14.txt 
	diff ./testFiles/output/random1000Output15.txt ./testFiles/givenOutput/random1000Output15.txt 
	diff ./testFiles/output/random1000Output16.txt ./testFiles/givenOutput/random1000Output16.txt 
	diff ./testFiles/output/random1000Output17.txt ./testFiles/givenOutput/random1000Output17.txt 
	diff ./testFiles/output/random1000Output18.txt ./testFiles/givenOutput/random1000Output18.txt 
	diff ./testFiles/output/random1000Output19.txt ./testFiles/givenOutput/random1000Output19.txt 
	diff ./testFiles/output/random1000Output20.txt ./testFiles/givenOutput/random1000Output20.txt 
	diff ./testFiles/output/random1000Output21.txt ./testFiles/givenOutput/random1000Output21.txt 
	diff ./testFiles/output/random1000Output22.txt ./testFiles/givenOutput/random1000Output22.txt 
	diff ./testFiles/output/random1000Output23.txt ./testFiles/givenOutput/random1000Output23.txt 
	diff ./testFiles/output/random1000Output24.txt ./testFiles/givenOutput/random1000Output24.txt 
	diff ./testFiles/output/random1000Output25.txt ./testFiles/givenOutput/random1000Output25.txt 
	diff ./testFiles/output/random1000Output26.txt ./testFiles/givenOutput/random1000Output26.txt 
	diff ./testFiles/output/random1000Output27.txt ./testFiles/givenOutput/random1000Output27.txt 
	diff ./testFiles/output/random1000Output28.txt ./testFiles/givenOutput/random1000Output28.txt 
	diff ./testFiles/output/random1000Output29.txt ./testFiles/givenOutput/random1000Output29.txt 
	diff ./testFiles/output/random1000Output30.txt ./testFiles/givenOutput/random1000Output30.txt 
	diff ./testFiles/output/random1000Output31.txt ./testFiles/givenOutput/random1000Output31.txt 
	diff ./testFiles/output/random1000Output32.txt ./testFiles/givenOutput/random1000Output32.txt 
	diff ./testFiles/output/random1000Output33.txt ./testFiles/givenOutput/random1000Output33.txt 
	diff ./testFiles/output/random1000Output34.txt ./testFiles/givenOutput/random1000Output34.txt 
	diff ./testFiles/output/random1000Output35.txt ./testFiles/givenOutput/random1000Output35.txt 
	diff ./testFiles/output/random1000Output36.txt ./testFiles/givenOutput/random1000Output36.txt 
	diff ./testFiles/output/random1000Output37.txt ./testFiles/givenOutput/random1000Output37.txt 
	diff ./testFiles/output/random1000Output38.txt ./testFiles/givenOutput/random1000Output38.txt 
	diff ./testFiles/output/random1000Output39.txt ./testFiles/givenOutput/random1000Output39.txt 
	
	diff ./testFiles/output/random10000Output0.txt ./testFiles/givenOutput/random10000Output0.txt 
	diff ./testFiles/output/random10000Output1.txt ./testFiles/givenOutput/random10000Output1.txt 
	diff ./testFiles/output/random10000Output2.txt ./testFiles/givenOutput/random10000Output2.txt 
	diff ./testFiles/output/random10000Output3.txt ./testFiles/givenOutput/random10000Output3.txt 
	diff ./testFiles/output/random10000Output4.txt ./testFiles/givenOutput/random10000Output4.txt 
	diff ./testFiles/output/random10000Output5.txt ./testFiles/givenOutput/random10000Output5.txt 
	diff ./testFiles/output/random10000Output6.txt ./testFiles/givenOutput/random10000Output6.txt 
	diff ./testFiles/output/random10000Output7.txt ./testFiles/givenOutput/random10000Output7.txt 
	diff ./testFiles/output/random10000Output8.txt ./testFiles/givenOutput/random10000Output8.txt 
	diff ./testFiles/output/random10000Output9.txt ./testFiles/givenOutput/random10000Output9.txt 
	diff ./testFiles/output/random10000Output10.txt ./testFiles/givenOutput/random10000Output10.txt 
	diff ./testFiles/output/random10000Output11.txt ./testFiles/givenOutput/random10000Output11.txt 
	diff ./testFiles/output/random10000Output12.txt ./testFiles/givenOutput/random10000Output12.txt 
	diff ./testFiles/output/random10000Output13.txt ./testFiles/givenOutput/random10000Output13.txt 
	diff ./testFiles/output/random10000Output14.txt ./testFiles/givenOutput/random10000Output14.txt 
	diff ./testFiles/output/random10000Output15.txt ./testFiles/givenOutput/random10000Output15.txt
	
	#diff ./largeFiles/largeOutput/random100000Output0.txt ./largeFiles/givenLargeOutput/random100000Output0.txt
	#diff ./largeFiles/largeOutput/random100000Output1.txt ./largeFiles/givenLargeOutput/random100000Output1.txt
	#diff ./largeFiles/largeOutput/random100000Output2.txt ./largeFiles/givenLargeOutput/random100000Output2.txt
	#diff ./largeFiles/largeOutput/random100000Output3.txt ./largeFiles/givenLargeOutput/random100000Output3.txt
	
	@echo Testing sequence has finished. Your code matches everything.
