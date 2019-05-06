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
//	printf("Player1 hand size = %d\n", testG.handCount[1]);
	printf("**TESTING FUNCTION: GREAT_HALLREFACTOR**\n   Testing to see if card is played and gained.**\n");//   actions spent and gained and card played number increases**\n");
	
	printf("\nPRIOR great_hall call: Test Player %d has: \n%d cards in hand\n%d cards played \n%d actions\n", p, testG.handCount[p], testG.playedCardCount, testG.numActions);   //Check current cards in hand
	cardEffect(great_hall, choice1, choice2, choice3, &testG, handPos, &bonus);
	printf("AFTER great_hall call: Test Player %d has: \n%d cards in hand\n%d cards played \n%d actions\n", p, testG.handCount[p], testG.playedCardCount, testG.numActions);   //Check current cards in hand

	assertTrue(testG.handCount[p], G.handCount[p]);
	return 0;
}

