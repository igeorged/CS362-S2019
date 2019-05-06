#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main() {
	int i;
    	int seed = 1000;
    	int numPlayers = 2;
    	int choice1 = 0, choice2 = 0, choice3 = 0, bonus =0, handPos = 0;
    	int p = 0; 
	int o = 1;
    	int handCount = 0;
     	int k[10] = {adventurer, sea_hag, council_room, feast, gardens, mine, smithy, village, baron, great_hall};
    	 struct gameState G, testG;
    	 int maxHandCount = 5;
   
	
	initializeGame(numPlayers, k, seed, &G);
	
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.handCount[o] = 5;
	printf("player 1 cards: %d\n", G.handCount[p]);
	printf("player 2 cards: %d\n", G.handCount[o]);
	

	printf("**TESTING FUNCTION: sea_hagRefactor()**\n   Testing to see if discard pile has curse in it after call.**\n");

	printf("PRIOR to sea_hag call by Player %d...\n", p);
//	printf("Test Player %d has \n%d cards in hand\n%d cards played\n%d cards in discard pile\n", p, testG.handCount[p], testG.playedCardCount, testG.discardCount[p]);   //Check current cards in hand
	if(testG.discard[o][0] == curse)
		printf("Curse FOUND in Player %d discard pile.\n", o);
	else
		printf("No curse found in Player %d discard pile.\n", o);

//	printf("Test Player %d has \n%d cards in hand\n%d cards played\n%d cards in discard pile\n", o, testG.handCount[o], testG.playedCardCount, testG.discardCount[o]);   //Check current cards in hand

	
	//Calling card effect 	
	cardEffect(sea_hag, choice1, choice2, choice3, &testG, handPos, &bonus);
	printf("Curse in discard pile test: ");
	assertTrue(testG.discard[o][0], curse);


	return 0;
}

