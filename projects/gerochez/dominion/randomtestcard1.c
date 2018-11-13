#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "rngs.h"

void testSmithy(struct gameState* G)
{
	struct gameState GT;
	memcpy(&GT, G, sizeof(struct gameState));

	int newCards = 0;
	int discarded = 1;
	int shuffledCards = 0;
	
	int i, j, m, r;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed = 1000;
	//int numPlayers = floor(Random() * 4);
	int thisPlayer = 0;

	//call smithy with the passed in gameState
	r = cardEffect(smithy, choice1, choice2, choice3, G, handpos, &bonus);

	newCards = 3;

	//printf("Hand Count = %d, expected %d\n", GT.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	assert(GT.handCount[thisPlayer] == G->handCount[thisPlayer] + newCards - discarded);
	//printf("Deck Count = %d, expected %d\n", GT.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	assert(GT.deckCount[thisPlayer] == G->deckCount[thisPlayer] - newCards + shuffledCards);
	//printf("Coins = %d, expected %d\n", GT.coins, G.coins + extraCoins);
	assert(GT.coins[thisPlayer] == G->coins[thisPlayer] + extra coins);
	//printf("Checking Victory card piles...\n");
	assert(GT.supplyCount[estate] == G->supplyCount[estate]);
	assert(GT.supplyCount[duchy] == G->supplyCount[duchy]);
	assert(GT.supplyCount[province] == G->supplyCount[province]);
	//printf("Checking Kingdom card piles...\n");
	for (i = 0; i < 10; i++)
	{
		assert(G->supplyCount[k[i]] == GT.supplyCount[k[i]]);
	}
	//printf("Checking Hand, Deck, Discard, Coins of other player...\n");
	assert(GT.handCount[1] == G->handCount[1]);
	assert(GT.discardCount[1] == G->discardCount[1]);
	assert(GT.deckCount[1] == G->deckCount[1]);
	assert(GT.coins[1] == G->coins[1]);	
}

int main()
{
	int i, n, r, p, deckCount, discardCount, handCount, choice1, choice2, choice3, bonus;

	int k[10] = {adventurer, village, steward, smithy, embargo,
		    gardens, council_room, great_hall, minion, outpost};

	struct gameState G;

	

	for (n = 0; n < 2000; n++)
	{
		for (i = 0; i < sizeof(struct gameState); i++)
		{
			((char*)&G[i] = floor(Random() * 256);
		}

		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.handCount[p] = floor(Random() * MAX_HAND);
		testSmithy(&G);
	}

	printf("ALL TESTS PASSED\n");

	return 0;
}
