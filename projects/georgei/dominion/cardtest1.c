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

	printf("**TESTING FUNCTION: smithy**\n");
	
	//printf("\nTesting With cardEffect() call...");
	printf("\nPRIOR smithy call: Test Player %d has: \n%d cards in hand\n%d dicarded cards\n%d Actions\n", p, testG.handCount[p], testG.discardCount[p], testG.numActions);   //Check current cards in hand
	cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus);
	printf("\nAFTER smithy call: Test Player %d has: \n%d cards in hand\n%d dicarded cards\n%d Actions\n", p, testG.handCount[p], testG.discardCount[p], testG.numActions);   //Check current cards in hand
	printf("Cards in hand test: ");
	assertTrue(testG.handCount[p], (G.handCount[p] + 2));
	printf("Cards in discard test: ");
	assertTrue(testG.discardCount[p], (G.discardCount[p] + 1));

	return 0;

}


