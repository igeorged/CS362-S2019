#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main(){
	int testNum = 10000;
	int result;	
	int seed = 8000;
	int numPlayer = 2;
	int p = 1;
	int rando = 0, handCount, deckCount, good = 0, bad = 0;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
			sea_hag, smithy, village, baron, great_hall};
	struct gameState G;
	int i, j;
	for(i = 0; i < testNum; i++)
	{
		printf("Test Number: %d\n", i);
		int gseed = rand() % seed + 1;
		initializeGame(numPlayer, k, gseed, &G);
		
		rando = rand() % MAX_DECK;
		G.handCount[p] = rand() % MAX_HAND;
		handCount = rando;
		int r = G.handCount[p];
		G.discardCount[p] = rand() % MAX_DECK;
		printf("r = %d, ", r);
		result = smithyRefactor(&G, 1, p);
		printf("HandCount = %d\n", G.handCount[p]); 
		if(result == 0 && G.handCount[p] == (r + 2))
		{
			good++;
		}

	}
			
	printf("Test Complete!\n");
	printf("Good = %d\n out of %d", good, testNum);

	return 0;
}
