/*int adventurer_Fn(struct gameState *state, int currentPlayer, int* drawntreasure, int* cardDrawn, int temphand[], int* z) {
  while(*drawntreasure<1){
    if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
      shuffle(currentPlayer, state);
    }

    drawCard(currentPlayer, state);
  
    *cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
  
    if (*cardDrawn == copper || *cardDrawn == silver || *cardDrawn == gold)
      *drawntreasure = *drawntreasure + 1;
  
    else{
      temphand[*z]=*cardDrawn;
      state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
      *z = *z + 1;
    }
  }
  
  while(*z-1>=0){
    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[*z-1]; // discard all cards in play that have been drawn
    *z=*z-1;
  }

  return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "interface.h"

#define RUNS 500

void testAdventurer() {
  struct gameState gstate;
  int players, player, i, seed, numCards, card1, res;
  int hand[10] = {adventurer, smithy, great_hall, outpost, council_room, feast, gardens, mine, remodel, village};
  
  seed = rand();
  int fails = 0;

  for(i = 0; i < RUNS; i++) {

    players = rand() % MAX_PLAYERS+1;

    initializeGame(players, hand, seed, &gstate);

    player = rand() % players;

    gstate.whoseTurn = player;
    gstate.deckCount[player] = rand() % MAX_DECK;
    gstate.discardCount[player] = rand() % MAX_DECK;
    gstate.handCount[player] = rand() % MAX_HAND;
    gstate.hand[player][0] = adventurer;

    numCards = gstate.handCount[player];

    res = playCard(0,0,0,0,&gstate);

    card1 = gstate.hand[player][gstate.handCount[player]-1];

    //card2 = gstate.hand[player][gstate.handCount[player]-2];

    if(res == -1) {
      printf("adventurer card: FAIL when playing adventurer card\n");  
      fails++;
    }

    if(gstate.handCount[player] != numCards+2) {
      printf("adventurer card: FAIL when test containing is handcount +2 played as adventurer\n");
      fails++;
    }

    if(card1 != copper && card1 != silver && card1 != gold) {
      printf("adventurer card: FAIL when checking if last drawn card is treasure\n"); 
      fails++;
    }
  }

  printf("ADVENTURER TESTS COMPLETE: %d tests correct out of %d ran\n", RUNS-fails, RUNS);

}

int main() {
  testAdventurer();
  return 0;
}

