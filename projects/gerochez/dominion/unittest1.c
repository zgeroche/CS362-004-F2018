/*
 * Test for numHandsCards()
 * Include in makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 * 	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
 *
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main()
{
	int i;
	int seed = 1000;
	int numPlayer = 4;
	int p, r, handCount;
	int bonus;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
		    remodel, smithy, village, baron, great_hall};
	struct gameState G;
	int maxHandCount = 5;

	printf("Now testing numHandCards():\n");
	
	//For every player
	for (p = 0; p < numPlayer; p++)
	{
		//For 1 through 5 handCount
		for (handCount = 1; handCount <= maxHandCount; handCount++)
		{
			printf("Testing player %d with %d cards in hand\n", p, handCount);
			memset(&G, 23, sizeof(struct gameState)); //reset game
			r = initializeGame(numPlayer, k, seed, &G); //initialize new game state
			G.handCount[p] = handCount; //assign handcount
			G.whoseTurn = p;

			//assert return val of numHandCards is the assigned number above
			printf("numHandCards(&G) returned %d, expected %d\n", numHandCards(&G), handCount);
			assert(numHandCards(&G) == handCount);
		}
	}

	printf("All tests passed!\n");
	
	return 0;
}
