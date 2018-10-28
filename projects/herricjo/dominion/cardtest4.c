/*int outpost_Fn(struct gameState *state, int handPos, int currentPlayer) {
        //set outpost flag
      //state->outpostPlayed++;
      
      //discard card
      discardCard(handPos, currentPlayer, state, 0);
      return 0;
}*/

#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
//#include "structs.h"

void testOutpost() {
  struct gameState gS1;
  int isPlayed;
  int numCards;
  int hand[10] = {adventurer, smithy, great_hall, outpost, council_room, feast, gardens, mine, remodel, village};

  initializeGame(2, hand, 1, &gS1);

  gS1.handCount[0] = 3;
  gS1.hand[0][0] = outpost;

  isPlayed = gS1.outpostPlayed;
  numCards = gS1.handCount[0];

  playCard(0, 1, 0, 0, &gS1);

  if(gS1.outpostPlayed != isPlayed)
    printf("outpost card: PASS when test containing is outpost played as outpost\n");
  else
    printf("outpost card: FAIL when test containing is outpost played as outpost\n");

  if(gS1.handCount[0] == numCards - 1)
    printf("outpost card: PASS when test containing is card discarded as outpost\n");
  else
    printf("outpost card: FAIL when test containing as is card discarded outpost\n");
}

int main() {
  testOutpost();
  return 0;
}