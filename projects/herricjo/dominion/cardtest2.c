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
  int numCards2;
  int deckSize;
  int deckSize2;
  int hand[10] = {adventurer, smithy, great_hall, outpost, council_room, feast, gardens, mine, remodel, village};
  size_t numElements;
  int i;
  int total;
  int total2;

  initializeGame(2, hand, 1, &gS1);

  gS1.handCount[0] = 3;
  gS1.handCount[1] = 3;
  gS1.deckCount[0] = 10;
  gS1.deckCount[1] = 10;  
  gS1.hand[0][0] = smithy;
  numElements = sizeof(gS1.supplyCount)/sizeof(gS1.supplyCount[0]);

  for(i=0; i<numElements; i++) {
    total += gS1.supplyCount[i];
  }

  numCards = gS1.handCount[0];
  numCards2 = gS1.handCount[1];
  deckSize = gS1.deckCount[0];
  deckSize2 = gS1.deckCount[1];  

  playCard(0, 1, 0, 0, &gS1);

  for(i=0; i<numElements; i++) {
    total2 += gS1.supplyCount[i];
  }

  if(gS1.handCount[0] == numCards+3)
    printf("smithy card: PASS when test containing is handcount +2 played as smithy\n");
  else
    printf("smithy card: FAIL when test containing is handcount +2 played as smithy\n");

  if(gS1.handCount[1] == numCards2)
    printf("smithy card: PASS when test containing is handcount same for p2 as smithy\n");
  else
    printf("smithy card: FAIL when test containing is handcount same for p2 as smithy\n");  

  if(gS1.deckCount[0] == deckSize-3)
    printf("smithy card: PASS when test containing is deckcount -3 as smithy\n");
  else
    printf("smithy card: FAIL when test containing is deckcount -3 as smithy\n");

  if(gS1.deckCount[1] == deckSize2)
    printf("smithy card: PASS when test containing is deckcount same for np as smithy\n");
  else
    printf("smithy card: FAIL when test containing is deckcount same for p2 as smithy\n");

  if(total == total2)
    printf("smithy card: PASS when test containing is victory piles same as smithy\n");
  else
    printf("smithy card: FAIL when test containing is victory piles same as smithy\n");

}

int main() {
  testSmithy();
  return 0;
}