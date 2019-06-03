#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


//Testing Smithy
int main(){
	srand(NULL);
	int testNum = 1000;
	int result;	
	int seed = 10000;
	int choice1 = 0, choice2 = 0, choice3 = 0;
	int p;
	int irandom = 0, handCount, deckCount, pass = 0, fail = 0;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
			sea_hag, smithy, village, baron, great_hall};
	struct gameState G;
	int i, j;
	for(i = 0; i < testNum; i++)
	{
		printf("Test Number: %d\n", i);
		
		//Random player number
		int numPlayer = (rand() % (5 - 2)) + 2;
		//Set random game seed
		int gseed = rand() % seed + 1;
		initializeGame(numPlayer, k, gseed, &G);
		//set random player to play
		p = numPlayer;
		p = rand() % p;
		
		//Set deck
		G.handCount[p] = (rand() % MAX_HAND) + 1;
		int r = G.handCount[p];
		irandom = rand() % r;
		result = cardEffect(smithy, choice1, choice2, choice3, &G, 0, 0);
		int q = rand() % 4;
	
		if(result == 0 && (r+q) == G.handCount[p])
		{
			pass++;
		}
		else
		{
			fail++;
		}
		
		memset(&G, 0, sizeof(struct gameState));
	}
			
	printf("Test Complete!\n");
	printf("Passed test = %d out of %d\n", pass, testNum);

	return 0;
}
