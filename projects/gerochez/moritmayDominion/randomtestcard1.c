#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"

int main()
{
	srand(time(NULL));

	int k[10] = {adventurer, village, steward, smithy, embargo,
		    gardens, council_room, great_hall, minion, outpost};

	struct gameState G, GT;
	
	int newCards = 0;
	int discarded = 1;
	int shuffledCards = 0;
	int extraCoins = 0;
	
	int i, j, n, r;
	int seed = 1000;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int numPlayers = 2;
	int thisPlayer, otherPlayer;

	printf("Testing Card: Smithy\n");
	printf("BEGINNING RANDOM TESTS\n");

	for (n = 0; n < 2000; n++)
	{
		
		//initialize game, then set the player randomly
		initializeGame(numPlayers, k, seed, &G);	
		thisPlayer = rand() % 2;

		//set the turn to thisPlayer, then copy to test state
		G.whoseTurn = thisPlayer;
	
		
		//Set other player
		if (thisPlayer == 0)
		{
			otherPlayer = 1;
		}
		else
		{
			otherPlayer = 0;
			
			//Perform some initialization for player 1 since
			//initializeGame defaults to and initializes player 0
			G.handCount[G.whoseTurn] = 0;
			for (i = 0; i < 5; i++)
			{
				drawCard(G.whoseTurn, &G);
			}
		}

		memcpy(&GT, &G, sizeof(struct gameState));

		//call smithy with GT
		r = cardEffect(smithy, choice1, choice2, choice3, &GT, handpos, &bonus);

		newCards = 3;

		//printf("Testing Player: %d\n", thisPlayer);

		printf("Hand Count = %d, expected %d\n", GT.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
		assert(GT.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
		printf("Deck Count = %d, expected %d\n", GT.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
		assert(GT.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
		printf("Coins = %d, expected %d\n", GT.coins, G.coins + extraCoins);
		assert(GT.coins == G.coins + extraCoins);
		printf("Checking Victory card piles...\n");
		assert(GT.supplyCount[estate] == G.supplyCount[estate]);
		assert(GT.supplyCount[duchy] == G.supplyCount[duchy]);
		assert(GT.supplyCount[province] == G.supplyCount[province]);
		printf("Checking Kingdom card piles...\n");
		for (i = 0; i < 10; i++)
		{
			assert(G.supplyCount[k[i]] == GT.supplyCount[k[i]]);
		}
		printf("Checking Hand, Deck, Discard, Coins of other player...\n");
		assert(GT.handCount[otherPlayer] == G.handCount[otherPlayer]);
		assert(GT.discardCount[otherPlayer] == G.discardCount[otherPlayer]);
		assert(GT.deckCount[otherPlayer] == G.deckCount[otherPlayer]);
		assert(GT.coins == G.coins);
	}

	printf("ALL TESTS PASSED\n");

	return 0;
}
