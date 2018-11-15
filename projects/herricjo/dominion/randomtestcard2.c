/*int great_hall_Fn(struct gameState *state, int handPos, int currentPlayer) {
        //+1 Card
      //drawCard(currentPlayer, state);
      
      //+1 Actions
      state->numActions++;
      
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;
}*/

#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
//#include "structs.h"
#define RUNS 10

void testGreat_Hall() {
  struct gameState gstate;
  int players, player, i, seed, numCards, res, total, total2, actions;
  int hand[10] = {adventurer, smithy, great_hall, outpost, council_room, feast, gardens, mine, remodel, village};
  size_t numElements;
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
    gstate.hand[player][0] = great_hall;

    numElements = sizeof(gstate.supplyCount)/sizeof(gstate.supplyCount[player]);
    numCards = gstate.handCount[player];
    actions = gstate.numActions;

    for(i=0; i<numElements; i++)
      total += gstate.supplyCount[i];

    res = playCard(0,0,0,0,&gstate);

    for(i=0; i<numElements; i++)
      total2 += gstate.supplyCount[i];

    //card2 = gstate.hand[player][gstate.handCount[player]-2];

    if(res == -1) {
      printf("great_hall card: FAIL when playing great hall card\n");  
      fails++;
    }

    if(gstate.handCount[player] != numCards-1) {
      printf("great_hall card: FAIL when test containing is handcount -1 played as great hall\n");
      fails++;
    }

    if(gstate.numActions != actions+1) {
      printf("great_hall card: FAIL when checking if numactions+1 played as great hall\n"); 
      fails++;
    }

    if(total != total2) {
      printf("great_hall card: FAIL when test containing is victory piles same as great hall\n");
      fails ++;
    }
  }

  printf("GREAT_HALL TESTS COMPLETE: %d tests correct out of %d ran\n", RUNS-fails, RUNS);
}

int main() {
  testGreat_Hall();
  return 0;
}