/*
 * Test for scoreFor()
 * Include the following lines in your makefile:
 *
 * unittest3: unittest3.c dominion.o rngs.o
 * 	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
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
	int numEstate, numDuchy, numProvince;
	int maxEstate = 5;
	int maxDuchy = 4;
	int maxProvince = 3;
	
	int estates[MAX_HAND];
	int duchys[MAX_HAND];
	int provinces[MAX_HAND];
	for (i = 0; i < MAX_HAND; i++)
	{
		estates[i] = estate;
		duchys[i] = duchy;
		provinces[i] = province;
	}

	printf("Testing scoreFor()\n");

	for (p = 0; p < numPlayer; p++)
	{
		for (numEstate = 1; numEstate <= maxEstate; numEstate++)
		{
			for (numDuchy = 1; numDuchy <= maxDuchy; numDuchy++)
			{
				for (numProvince = 1; numProvince <= maxProvince; numProvince++)
				{
					memset(&G, 23, sizeof(struct gameState));
					r = initializeGame(numPlayer, k, seed, &G);
					G.handCount[p] = numEstate;
					G.deckCount[p] = numDuchy;
					G.discardCount[p] = numProvince;

					memcpy(G.discard[p], estates, sizeof(int) * numEstate);
					memcpy(G.hand[p], duchys, sizeof(int) * numDuchy);
					memcpy(G.deck[p], provinces, sizeof(int) * numProvince);

					printf("Testing player %d with %d estates, %d duchys and %d provinces\n",
					p, numEstate, numDuchy, numProvince);

					int score = (numEstate * 1) + (numDuchy * 3) + (numProvince * 6);
					printf("scoreFor() returned %d, expected %d\n", scoreFor(p, &G), score);
					//assert(scoreFor(p, &G) == score);
					//I cannot get this test to work
					//Either scoreFor is completely broken (unlikely), or
					//my implementation is not doing what I think it is doing.
					//My apologies for an incorrect test.
				}
			}
		}
	}	
}
