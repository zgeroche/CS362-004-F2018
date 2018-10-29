/*
 * TEST FOR EMBARGO CARD
 * THIS TEST DOES NOT PASS AS THE EMBARGO CARD IS BUGGED, AS PER ASSIGNMENT 2
*/

/*
 * Include the following in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 * 	gcc -o cardtest1 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
 *
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "rngs.h"

#define TESTCARD "embargo"

int main()
{
	int newCards = 0;
	int discarded = 1;
	int extraCoins = 0;
	int shuffledCards = 0;

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
	cardEffect(embargo, choice1, choice2, choice3, &GT, handpos, &bonus);

	//Simulate embargo effect
	extraCoins = 2;
	int addedTokens = 1;

	//Print messages comparing G and GT
	printf("Hand Count = %d, expected %d\n", GT.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	assert(GT.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
	printf("Deck Count = %d, expected %d\n", GT.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	assert(GT.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
	printf("Coins = %d, expected %d\n", GT.coins, G.coins + extraCoins);
	assert(GT.coins == G.coins + extraCoins);
	printf("Embargo tokens on Supply pile %d: %d, expected %d\n", choice1, GT.embargoTokens[choice1], G.embargoTokens[choice1] + addedTokens);
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
