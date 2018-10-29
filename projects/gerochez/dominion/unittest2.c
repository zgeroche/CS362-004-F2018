/*
 * Test for supplyCount()
 * Include the following lines in your makefile:
 *
 * unittest2: unittest2.c dominion.o rngs.o
 * 	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
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
	int i, r;
	int seed = 1000;
	int numPlayer = 2;
	int p;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
		     remodel, smithy, village, baron, great_hall};
	struct gameState G;
	int supCount;
	int maxSupCount = 10;

        for (i = 0; i < 10; i++)
	{
		for (supCount = 1; supCount <= maxSupCount; supCount++)
		{
			printf("Testing card %d with supCount %d.\n", i, supCount);
			memset(&G, 23, sizeof(struct gameState));
			r = initializeGame(numPlayer, k, seed, &G);
			G.supplyCount[k[i]] = supCount;
			
			assert(supplyCount(k[i], &G) == supCount);
		}
	}

	printf("All tests passed!\n");
}
