#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"



int main(){
	srand(time(0));
	int testNum = 105000;
	struct gameState G;
	int result, rando = 0, player = 1, handCount, deckCount, good = 0, bad =0;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy};
	printf("Beginning Running Random Test Card for adventurer.\n");
	for(int j = 0; j < 4; j++){
		printf("Running round %d\n", j+1);
		for(int i = 0; i < testNum; i++){
			printf("Run #%d\n", i);
			int numPlayers = rand() % 4;
			int gameSeed = rand() % 70000 + 1;
			initializeGame(numPlayers, k, gameSeed, &G);
			rando = rand() % 10;
			if(rando == 5){
				G.deckCount[player] = 0;
				deckCount = 0;
			}	
			else{
				rando = rand() % MAX_DECK;
				G.deckCount[player] = rando;
				deckCount = rando;
			}
			
			rando = rand() % MAX_DECK;
			G.handCount[player] = rand() % MAX_HAND;
			handCount = rando;
			G.discardCount[player] = rand() % MAX_DECK;
			result = cardEffect(adventurer, 1, 1, 1, &G, 1, 0);
			if(result == 0){
				good++;
			}

		}
	}		
	printf("Test Complete!\n");
	printf("good: %d of %d\n", good, testNum);
	return 0;
	
}	
/*

int main(){
	int testNum = 10;
	int result;	
	int seed = 8000;
	int numPlayer;
	int p;
	int rando = 0, handCount, deckCount, good = 0, bad = 0, post_count, pre_count;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
			sea_hag, smithy, village, baron, great_hall};
	struct gameState G;
	int i, j, deck_treasures = 0;
	for(i = 0; i < testNum; i++)
	{	
		int result = 0, r=0;
		
		printf("Test Number: %d\n", i);
		int gseed = rand() % (seed + 1 - 1) + 1;
		numPlayer = rand() % 4;
		initializeGame(numPlayer, k, gseed, &G);
		
		p = rand() % numPlayer;
		G.numActions = 1;
		G.deckCount[p] = rand() % MAX_HAND;
		G.handCount[p] = 5; 
		G.discardCount[p] = 0;
		G.whoseTurn = p;

		for(j = 0; j < G.deckCount[p]; j++)
		{
			G.hand[p][j] = rand()% CARD_COUNT;
			if(G.deck[p] >= copper && G.hand[p][j] <=gold)
			{
				deck_treasures++;
			}
		}

		for(j = 0; j < G.handCount[p]; j++)
		{
			G.hand[p][j] = rand() % CARD_COUNT;
			if(G.hand[p][j] >= copper && G.hand[p][j] <= gold)
			{
				pre_count++;
			}
		}
		
		G.hand[p][0] = adventurer;
		r = G.handCount[p];	
		printf("BEFORE: G.numActions = %d\nG.deckCount[p] = %d\nG.handCount[p] = %d\nG.discardCount[p] = %d\nG.whoseTurn = %d\nnumPlayer = %d\n", G.numActions, G.deckCount[p], G.handCount[p], G.discardCount[p], G.whoseTurn, numPlayer);
		playCard(0, 0, 0, 0, &G);
		
		printf("AFTER: G.numActions = %d\nG.deckCount[p] = %d\nG.handCount[p] = %d\nG.discardCount[p] = %d\nG.whoseTurn = %d\n\n", G.numActions, G.deckCount[p], G.handCount[p], G.discardCount[p], G.whoseTurn);
		if(result == 0 && G.handCount[p] == (r + 1))
		{
			good++;
		}
		memset(&G, 0, sizeof(struct gameState));	
	}																											
		return 0;
}*/
