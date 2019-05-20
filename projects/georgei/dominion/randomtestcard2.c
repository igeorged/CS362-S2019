#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


//Testing updateCoins
int main(){
	srand(NULL);
	int testNum = 20000;
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
		printf("Test Number: %d  ", i);
		
		//Random player number
		int numPlayer = (rand() % (5 - 2)) + 2;
		//Set random game seed
		int gseed = rand() % seed + 1;
		initializeGame(numPlayer, k, gseed, &G);
		//set random player to play
		p = numPlayer;
		p = rand() % p;
		
		//Set deck
		G.handCount[p] = (rand() % 15) + 1;
		//G.handCount[p] = 5;
		//int r = G.handCount[p];
		
		int v = rand() % 3;
		printf("v : %d", v);
		if (v == 0)
		{
			for(j = 0; j < G.handCount[p]; j++)
			{
				G.hand[p][j] = copper;
			}
		}
		else if(v == 1)
		{
			for(j = 0; j < G.handCount[p]; j++)
			{
				G.hand[p][j] = silver;
			}
		}
		else 
		{
			for(j = 0; j < G.handCount[p]; j++)
			{
				G.hand[p][j] = gold;
			}
		} 
	

		result = updateCoins(p, &G, 0);
		printf("  result: %d  coins: %d  ", result, G.coins);
		if((result == 0) && (v == 0)  && (G.coins == (G.handCount[p] * 1)))
		{
			pass++;
			printf("\tcopper passed\n");
		}
		else if((result == 0) && (v == 1)  && (G.coins == (G.handCount[p] * 2)))
		{
			pass++;
			printf("\tsilver passed\n");
		}
		else if((result == 0) && (v == 2)  && (G.coins == (G.handCount[p] * 3)))
		{
			pass++;
			printf("\tgold   passed\n");
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
