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

void testAdventurer() {
  struct gameState gS1;
  int numCards;
  int ret;
  int ret1;
  int ret2;
  char name[MAX_STRING_LENGTH];
  int hand[10] = {adventurer, smithy, great_hall, outpost, council_room, feast, gardens, mine, remodel, village};

  initializeGame(2, hand, 1, &gS1);

  gS1.handCount[0] = 3;
  gS1.hand[0][0] = adventurer;

  numCards = gS1.handCount[0];

  //printHand(0, &gS1);

  playCard(0, 1, 0, 0, &gS1);

  //printHand(0, &gS1);

  cardNumToName(gS1.hand[0][4], name);

  ret = strcmp(name, "Copper");
  ret = strcmp(name, "Silver");
  ret = strcmp(name, "Gold");

  if(gS1.handCount[0] == numCards+2)
    printf("adventurer card: PASS when test containing is handcount +2 played as adventurer\n");
  else
    printf("adventurer card: FAIL when test containing is handcount +2 played as adventurer\n");

  if(ret == 0 || ret1 == 0 || ret2 == 0)
    printf("adventurer card: PASS when test containing does hand contain new treasure played as adventurer\n");
  else
    printf("adventurer card: FAIL when test containing does hand contain new treasure played as adventurer\n");
}

int main() {
  testAdventurer();
  return 0;
}

