CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion. rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)

randomtestcard1result: randomtestcard1 dominion.c rngs.c
	echo "Result for randomtestcard1:" >> randomtestcard1result.out
	echo "randomtestcard1.c:" >> randomtestcard1result.out
	gcc -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> randomtestcard1result.out
	gcov randomtestcard1 >> randomtestcard1result.out

randomtestcard2: randomtestcard2.c dominion. rngs.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)

randomtestcard2result: randomtestcard2 dominion.c rngs.c
	echo "Result for randomtestcard2:" >> randomtestcard2result.out
	echo "randomtestcard2.c:" >> randomtestcard2result.out
	gcc -o randomtestcard2 dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> randomtestcard2result.out
	gcov randomtestcard2 >> randomtestcard2result.out

randomtestcardadventurer: randomtestcardadventurer.c dominion. rngs.o
	gcc -o randomtestcardadenturer -g randomtestcardadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestcardadventurerresult: randomtestcardadventurer dominion.c rngs.c
	echo "Result for randomtestcardadventurer:" >> randomtestcardadventurerresult.out
	echo "randomtestcardadventurer.c:" >> randomtestcardadventurerresult.out
	gcc -o randomtestcardadventurer dominion.c rngs.c randomtestcardadventurer.c $(CFLAGS)
	./randomtestcardadventurer >> randomtestcardadventurerresult.out
	gcov randomtestcardadventurer >> randomtestcardadventurerresult.out

all: playdom player


clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
