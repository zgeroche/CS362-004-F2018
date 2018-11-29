/*
 * Test for whoseTurn()
 * Include the following lines in your makefile:
 *
 * unittest4: unittest4.c dominion.o rngs.o
 * 	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
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
	int i, p, r;
	int seed = 1000;
	int numPlayers = 4;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
		     remodel, smithy, village, baron, great_hall};
	struct gameState G;

	printf("Testing whoseTurn()\n");


	for (p = 0; p < numPlayers; p++)
	{
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayers, k, seed, &G);
		G.whoseTurn = p;

		printf("whoseTurn() returned %d, expected %d\n", whoseTurn(&G), p);
		assert(whoseTurn(&G) == p);
	}
	printf("All tests passed!\n");
}
