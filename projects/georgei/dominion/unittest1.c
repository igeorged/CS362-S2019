
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main() {
    	int seed = 1000;
    	int numPlayer = 2;
    	int choice1 = 0, choice2 = 0, choice3 = 0, bonus =0, handPos = 0;
	int p=0;
   	int k[10] = {adventurer, council_room, feast, gardens, mine
               , sea_hag, smithy, village, baron, great_hall};
	struct gameState G, testG;


	//Initialize game and make duplicate state to use on for comparison
	initializeGame(numPlayer, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("**TESTING FUNCTION: smithyRefactor()**\n");
	
	//printf("\nTesting With cardEffect() call...");
	printf("PRIOR smithy call: Test Player %d has: \n%d cards in hand.\n", p, testG.handCount[p]);   //Check current cards in hand
	cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus);
	printf("AFTER great_hall call: Test Player %d has: \n%d cards in hand.\n", p, testG.handCount[p]);   //Check current cards in hand
	assertTrue(testG.handCount[p],(G.handCount[p] + 2));

	return 0;

}


