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
  int numCards2;
  int hand[10] = {adventurer, smithy, great_hall, outpost, council_room, feast, gardens, mine, remodel, village};
  size_t numElements;
  int i;
  int total;
  int total2;

  initializeGame(2, hand, 1, &gS1);

  gS1.handCount[0] = 3;
  gS1.handCount[1] = 3;
  gS1.hand[0][0] = outpost;
  numElements = sizeof(gS1.supplyCount)/sizeof(gS1.supplyCount[0]);

  for(i=0; i<numElements; i++) {
    total += gS1.supplyCount[i];
  }

  isPlayed = gS1.outpostPlayed;
  numCards = gS1.handCount[0];
  numCards2 = gS1.handCount[1];

  playCard(0, 1, 0, 0, &gS1);

  for(i=0; i<numElements; i++) {
    total2 += gS1.supplyCount[i];
  }

  if(gS1.outpostPlayed != isPlayed)
    printf("outpost card: PASS when test containing is outpost played as outpost\n");
  else
    printf("outpost card: FAIL when test containing is outpost played as outpost\n");

  if(gS1.handCount[0] == numCards - 1)
    printf("outpost card: PASS when test containing is card discarded as outpost\n");
  else
    printf("outpost card: FAIL when test containing as is card discarded outpost\n");

  if(gS1.handCount[1] == numCards2)
    printf("outpost card: PASS when test containing is handcount same for p2 as outpost\n");
  else
    printf("outpost card: FAIL when test containing is handcount same for p2 as outpost\n"); 

  if(total == total2)
    printf("outpost card: PASS when test containing is victory piles same as outpost\n");
  else
    printf("outpost card: FAIL when test containing is victory piles same as outpost\n");

}

int main() {
  testOutpost();
  return 0;
}