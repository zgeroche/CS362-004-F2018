//card test 1
//check adventurer card implementation

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

int main(){
  struct gameState state;
  int k[10] = {adventurer, gardens, embargo, village, great_hall, mine, cutpurse,
	       sea_hag, tribute, smithy};
  int p;
  srand(time(0));
  
  //randomize number of players from 2-4
  p = (rand()%3) + 2;
  initializeGame(p, k, rand(), &state);
  
  int c = 0;
  int s = 0;
  int g = 0;
  int currentPlayer = 0;
  int drawnTreasure = 0;
  int cardDrawn = state.hand[currentPlayer][state.handCount[currentPlayer]-1];
  
  while (drawnTreasure <2){
      for (currentPlayer = 0; currentPlayer <5; currentPlayer++){
         for (int i = 0; i < 25; i++){
            if (cardDrawn == copper){
                c++;
                drawnTreasure++;
            }
            else if (cardDrawn == silver){
                s++;
                drawnTreasure++;
            } 
            else if (cardDrawn == gold){
                g++;
                drawnTreasure++;
            }
        }
     }
  }
    if ((c + s + g) > 2) {
        printf("adventurer test failed\n");
        }
    else{
        printf("adventurer test passed\n");
    }
  return 0;
}
