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

void testSmithy() {
  struct gameState gS1;
  int numCards;
  int hand[10] = {adventurer, smithy, great_hall, outpost, council_room, feast, gardens, mine, remodel, village};

  initializeGame(2, hand, 1, &gS1);

  gS1.handCount[0] = 3;
  gS1.hand[0][0] = smithy;

  numCards = gS1.handCount[0];

  playCard(0, 1, 0, 0, &gS1);

  if(gS1.handCount[0] == numCards+2)
    printf("smithy card: PASS when test containing is handcount +2 played as smithy\n");
  else
    printf("smithy card: FAIL when test containing is handcount +2 played as smithy\n");
}

int main() {
  testSmithy();
  return 0;
}