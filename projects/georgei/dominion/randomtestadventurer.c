#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"



int main(){
	srand(NULL);
//	int z, drawntreasure = 0;
	int testNum = 10;
	int result;	
	int seed = 10000;
	int p;
	int irandom = 0, handCount, deckCount, pass = 0, fail = 0;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
			sea_hag, smithy, village, baron, great_hall};
	struct gameState G;
	int i, j;
	for(i = 0; i < testNum; i++)
	{
		printf("Test Number: %d\n", i);
		int drawntreasure;
		int z;	
		//Random player number
		int numPlayer = (rand() % (5 - 2)) + 2;
		
		//Set random game seed
		int gseed = rand() % seed + 1;
		initializeGame(numPlayer, k, gseed, &G);
		//set random player to play
		
		p = numPlayer;
		p = rand() % p;
			
		int idrawntreasure = rand() % 3000;	
		z=0;
		//Set deck
		G.handCount[p] = (rand() % 20) + 5;
		int r = G.handCount[p];
		for(int i = 0; i < G.handCount[p]; i++)
		{
		
			if(i > 5)
			{
				G.deck[p][i] = k[0];
			}
			else
			{
				G.deck[p][i] = copper;
			}
		}
		G.deck[p][0] = k[0];
		irandom = rand() % r +5;
		int j = idrawntreasure;
		result = adventurerRefactor(&G, 0, p, z, &idrawntreasure);
		if((result == 0) && (idrawntreasure > j))
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
