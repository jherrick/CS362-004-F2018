/*int smithy_Fn(struct gameState *state, int handPos, int currentPlayer) {
      //+3 Cards
      int i;
      for (i = 0; i < 3; i++)
  {
    drawCard(currentPlayer, state);
  }
      
      //discard card from hand
      //discardCard(handPos, currentPlayer, state, 0);
      return 0;
}*/

#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
//#include "structs.h"
#define RUNS 10

void testSmithy() {
  struct gameState gstate;
  int players, player, i, seed, numCards, res, deckSize, total, total2;
  int hand[10] = {adventurer, smithy, great_hall, outpost, council_room, feast, gardens, mine, remodel, village};
  size_t numElements;
  int deckFlag = 0;
  int fails = 0;

  seed = rand();

  for(i = 0; i < RUNS; i++) {
    players = rand() % MAX_PLAYERS+1;

    initializeGame(players, hand, seed, &gstate);

    player = rand() % players;

    gstate.whoseTurn = player;
    gstate.deckCount[player] = rand() % MAX_DECK;
    gstate.discardCount[player] = rand() % MAX_DECK;
    gstate.handCount[player] = rand() % MAX_HAND;
    gstate.hand[player][0] = smithy;

    numElements = sizeof(gstate.supplyCount)/sizeof(gstate.supplyCount[player]);
    numCards = gstate.handCount[player];
    deckSize = gstate.deckCount[player];

    if(deckSize > 3)
      deckFlag = 1;

    for(i=0; i<numElements; i++)
      total += gstate.supplyCount[i];

    res = playCard(0,0,0,0,&gstate);

    for(i=0; i<numElements; i++)
      total2 += gstate.supplyCount[i];

    //card2 = gstate.hand[player][gstate.handCount[player]-2];

    if(res == -1) {
      printf("smithy card: FAIL when playing smithy card\n");  
      fails++;
    }

    if(gstate.handCount[player] != numCards+3) {
      printf("smithy card: FAIL when test containing is handcount +3 played as smithy\n");
      fails++;
    }

    if(deckFlag == 1 && gstate.deckCount[player] != deckSize-3) {
      printf("smithy card: FAIL when checking if decksize -3 played as smithy\n"); 
      fails++;
    }

    if(total != total2) {
      printf("smithy card: FAIL when test containing is victory piles same as smithy\n");
      fails ++;
    }
  }

  printf("SMITHY TESTS COMPLETE: %d tests correct out of %d ran\n", RUNS-fails, RUNS);
}

int main() {
  testSmithy();
  return 0;
}