/*
 * TEST FOR GREAT HALL CARD
*/

/*
 * Include the following in your makefile:
 *
 * cardtest3: cardtest3.c dominion.o rngs.o
 * 	gcc -o cardtest3 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
 *
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "rngs.h"

#define TESTCARD "great hall"

int main()
{
	int newCards = 0;
	int discarded = 1;
	int extraActions = 0;
	int shuffledCards = 0;
	int extraCoins = 0;

	int i, j, m;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G, GT;
	int k[10] = {adventurer, village, steward, smithy, embargo,
		     gardens, council_room, great_hall, minion, outpost};
	

	//initlialize game state
	initializeGame(numPlayers, k, seed, &G);

	printf("**** TESTING CARD: %s ****\n", TESTCARD);

	//Begin Testing
	memcpy(&GT, &G, sizeof(struct gameState));

	//call card effect 
	cardEffect(great_hall, choice1, choice2, choice3, &GT, handpos, &bonus);

	//Simulate great hall effect
	newCards = 1;
	extraActions = 1;

	//Print messages comparing G and GT
	printf("Hand Count = %d, expected %d\n", GT.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	assert(GT.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
	printf("Deck Count = %d, expected %d\n", GT.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	assert(GT.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
	printf("Coins = %d, expected %d\n", GT.coins, G.coins + extraCoins);
	assert(GT.coins == G.coins + extraCoins);
	printf("Actions = %d, expected %d\n", GT.numActions, G.numActions + extraActions);
	assert(GT.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
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
	assert(GT.handCount[1] == G.handCount[1]);
	assert(GT.discardCount[1] == G.discardCount[1]);
	assert(GT.deckCount[1] == G.deckCount[1]);
	assert(GT.coins == G.coins);

	printf("ALL TESTS PASSED\n");


}
