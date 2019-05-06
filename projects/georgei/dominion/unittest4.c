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
    	int choice1 = 2, choice2 = 0, choice3 = 0, bonus =0, handPos = 0;
	int p=0;
    	int handCount = 0;
   	int k[10] = {adventurer, council_room, feast, gardens, mine
               , sea_hag, smithy, steward, baron, great_hall};
	struct gameState G, testG;
    	int maxHandCount = 5;

	//Initialize game and make duplicate state to use on for comparison
	initializeGame(numPlayer, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("Player1 hand size = %d\n", testG.handCount[1]);
	printf("**TESTING FUNCTION: stewardRefactor**\n   Testing to see if coins gained (option 2).**\n");//   actions spent and gained and card played number increases**\n");
	
	printf("\nPRIOR steward call: Test Player %d has: \n%d coins\n", p, testG.coins);   //Check current cards in hand
	cardEffect(steward, choice1, choice2, choice3, &testG, handPos, &bonus);
	printf("AFTER steward call: Test Player %d has: %d coins\n", p, testG.coins);   //Check current cards in hand
	assertTrue(testG.coins, (G.coins +2));
	return 0;
}

