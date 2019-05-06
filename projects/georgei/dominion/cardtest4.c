#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main() {
    	int i;
    	int seed = 1000;
    	int numPlayer = 2;
    	int choice1 = 0, choice2 = 0, choice3 = 0, bonus =0, handPos = 0;
	int p=0;
    	int handCount = 0;
   	int k[10] = {adventurer, council_room, feast, gardens, mine
               , sea_hag, smithy, village, baron, great_hall};
	struct gameState G, testG;
    	int maxHandCount = 5;

	//Initialize game and make duplicate state to use on for comparison
	initializeGame(numPlayer, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("**TESTING FUNCTION: Adventurer **\n");
	
	printf("PRIOR adventurer call: Player %d has:  \n", testG.handCount[p]);   //Check current cards in hand
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);
	printf("AFTER adventurer call: %d  Cards in hand\n", testG.handCount[p]);   //Check current cards in hand
	printf("Card obtained test: ");	
	assertTrue(testG.handCount[p], G.handCount[p]); 	
//	assertTrue(testG.handCount[p], G.handCount[p]);
	
	return 0;
}

