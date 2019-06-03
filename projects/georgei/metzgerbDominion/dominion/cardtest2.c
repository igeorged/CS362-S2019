/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

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
     	int k[10] = {adventurer, council_room, feast, gardens, mine, sea_hag, smithy, village, baron, great_hall};
    	 struct gameState G, testG;
    	 int maxHandCount = 5;
   
	
	initializeGame(numPlayers, k, seed, &G);
	
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.handCount[o] = 5;
	G.handCount[o] = 5;
//	printf("player 1 cards: %d\n", G.handCount[p]);
//	printf("player 2 cards: %d\n", testG.handCount[o]);
	

	printf("**TESTING CARD: council_room**\n");

	printf("PRIOR to council_room call Player %d has \n%d cards in hand\n%d number of buys\n%d cards in discard pile\n", p, testG.handCount[p], testG.numBuys, testG.discardCount[p]);   //Check current cards in hand
//	printf("Test Player %d has \n%d cards in hand\n", o, testG.handCount[o]);

	
	//Calling card effect 	
	cardEffect(council_room, choice1, choice2, choice3, &testG, handPos, &bonus);
	printf("AFTER council_room call Player %d has \n%d cards in hand\n%d number of buys\n%d cards in discard pile\n", p, testG.handCount[p], testG.numBuys, testG.playedCardCount);   //Check current cards in handi
//	printf("Test Player %d has \n%d cards in hand\n%d number of buys\n%d cards in discard pile\n", p, testG.handCount[p], testG.numBuys, testG.discardCount[p]);   //Check current cards in hand
//	printf("Test Player %d has \n%d cards in hand\n", o, testG.handCount[o]);
	printf("4 Cards draw test: ");
	assertTrue(testG.handCount[p], G.handCount[p] + 3);
	printf("Discard test: ");
	assertTrue(testG.discardCount[p], (G.discardCount[p] + 1));
	printf("Other player hand count test: ");
	assertTrue(testG.handCount[o], (G.handCount[o] + 1));	
	printf("Buy number test: ");
	assertTrue(testG.numBuys, (G.numBuys + 1));
/*
	if(testG.discardCount[p] == (G.discardCount[p] + 1))
	{	
		printf("Player %d discard count is correct -- TEST PASSED\n", p);
	}
	else
	{	
		printf("Player %d discard count is incorrect -- TEST FAILED\n", p);
	}		
	
	if(testG.discardCount[o] == (G.discardCount[o] + 1))
	{
		printf("Player %d discard count is correct -- TEST PASSED\n", o);
	}
	else
	{
		printf("Player %d discard count is incorrect -- TEST FAILED\n", o);
	}
	if(testG.discard[o][0] == curse)
	{
		printf("Player %d top of discard pile equals curse -- TEST PASSED\n", o);
	}
	else
	{
		printf("Player %d top of discard pile does not equal curese\n TEST FAILED\n", o);
	}

	//assert(testG.discard[o][0] == curse);
	
	
	if(testG.handCount[o] == (G.handCount[o] - 1))
	{
		printf("Player %d hand count is correct -- TEST PASSED\n", o);
	}
	else
	{
		printf("Player %d hand count is incorrect -- TEST FAILED\n", o);
	}
		
	if(testG.handCount[p] == (G.handCount[p] - 1))
	{
		printf("Player %d hand count is correct -- TEST PASSED\n", p);
	}
	else
	{
		printf("Player %d hand count is incorrect -- TEST FAILED\n", p);
	}
	
	if(testG.playedCardCount == (G.playedCardCount + 1))
	{
		printf("Card number played fof Player %d is correct -- TEST PASSED\n", p);
	}
	else
	{
		printf("Card number played for Plater %d is incorrect -- TEST FAILED\n", p);
	}
	
	// Reset	
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("\nTesting with sea_hagRefactor() call...\n");
	printf("PRIOR to sea_hag call by Player %d...\n", p);
	printf("Test Player %d has \n%d cards in hand\n%d cards played\n%d cards in discard pile\n", p, testG.handCount[p], testG.playedCardCount, testG.discardCount[p]);   //Check current cards in hand
	printf("Test Player %d has \n%d cards in hand\n%d cards played\n%d cards in discard pile\n", o, testG.handCount[o], testG.playedCardCount, testG.discardCount[o]);   //Check current cards in hand

	sea_hagRefactor(&testG, handPos, p, choice1, choice2, choice3);
	printf("AFTER sea_hag call by Player %d...\n", p);
	printf("Test Player %d has \n%d cards in hand\n%d cards played\n%d cards in discard pile\n", p, testG.handCount[p], testG.playedCardCount, testG.discardCount[p]);   //Check current cards in hand
	printf("Test Player %d has \n%d cards in hand\n%d cards played\n%d cards in discard pile\n", o, testG.handCount[o], testG.playedCardCount, testG.discardCount[o]);   //Check current cards in hand
	
	if(testG.discardCount[p] == (G.discardCount[p] + 1))
	{	
		printf("Player %d discard count is correct -- TEST PASSED\n", p);
	}
	else
	{	
		printf("Player %d discard count is incorrect -- TEST FAILED\n", p);
	}		
	
	if(testG.discardCount[o] == (G.discardCount[o] + 1))
	{
		printf("Player %d discard count is correct -- TEST PASSED\n", o);
	}
	else
	{
		printf("Player %d discard count is incorrect -- TEST FAILED\n", o);
	}
	if(testG.discard[o][0] == curse)
	{
		printf("Player %d top of discard pile equals curse -- TEST PASSED\n", o);
	}
	else
	{
		printf("Player %d top of discard pile does not equal curese\n TEST FAILED\n", o);
	}

	//assert(testG.discard[o][0] == curse);
	
	
	if(testG.handCount[o] == (G.handCount[o] - 1))
	{
		printf("Player %d hand count is correct -- TEST PASSED\n", o);
	}
	else
	{
		printf("Player %d hand count is incorrect -- TEST FAILED\n", o);
	}
		
	if(testG.handCount[p] == (G.handCount[p] - 1))
	{
		printf("Player %d hand count is correct -- TEST PASSED\n", p);
	}
	else
	{
		printf("Player %d hand count is incorrect -- TEST FAILED\n", p);
	}
	
	if(testG.playedCardCount == (G.playedCardCount + 1))
	{
		printf("Card number played fof Player %d is correct -- TEST PASSED\n", p);
	}
	else
	{
		printf("Card number played for Plater %d is incorrect -- TEST FAILED\n", p);
	}
	
	printf("\n\n");
*/

	return 0;
}

    	
/*

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

	printf("**TESTING FUNCTION: smithyRefactor()**\n   Testing to see if card number gained is correct,\n   and cards played number increases**\n");
	
	printf("\nTesting With cardEffect() call...");
	printf("\nPRIOR smithy call: Test Player %d has: \n%d cards in hand\n%d cards played\n", p, testG.handCount[p], testG.playedCardCount);   //Check current cards in hand
	cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus);
	printf("AFTER great_hall call: Test Player %d has: \n%d cards in hand\n%d cards played\n", p, testG.handCount[p], testG.playedCardCount, testG.numActions);   //Check current cards in hand
	
	if((testG.handCount[p] == (G.handCount[p] + 2)) && (testG.playedCardCount == (G.playedCardCount + 1)))
	{
		printf("TEST PASSED\n");
	}
	else
	{
		printf("TEST FAILED\n");
 	}

	// Check if function worked properly
	assert(testG.handCount[p] == (G.handCount[p] + 2));
	assert(testG.playedCardCount == (G.playedCardCount + 1));
		
	// Reset gameState to orginal state
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("\nTesting With smithyRefactor() call...");
	printf("\nPRIOR smithy call: Test Player %d has: \n%d cards in hand\n%d cards played\n", p, testG.handCount[p], testG.playedCardCount);   //Check current cards in hand
	cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus);
	printf("AFTER great_hall call: Test Player %d has: \n%d cards in hand\n%d cards played\n", p, testG.handCount[p], testG.playedCardCount, testG.numActions);   //Check current cards in hand
	
	if((testG.handCount[p] == (G.handCount[p] + 2)) && (testG.playedCardCount == (G.playedCardCount + 1)))
	{
		printf("TEST PASSED\n");
	}
	else
	{
		printf("TEST FAILED\n");
 	}

	// Check if function worked properly
	assert(testG.handCount[p] == (G.handCount[p] + 2));
	assert(testG.playedCardCount == (G.playedCardCount + 1));
	
	printf("\n\n");

	return 0;

}
*/
