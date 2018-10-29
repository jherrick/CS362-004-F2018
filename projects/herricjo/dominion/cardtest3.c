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

void testGreat_Hall() {
  struct gameState gS1;
  int numCards;
  int numCards2;
  int actions;
  int hand[10] = {adventurer, smithy, great_hall, outpost, council_room, feast, gardens, mine, remodel, village};
  size_t numElements;
  int i;
  int total;
  int total2;

  initializeGame(2, hand, 1, &gS1);

  gS1.handCount[0] = 3;
  gS1.handCount[1] = 3;  
  gS1.hand[0][0] = great_hall;
  numElements = sizeof(gS1.supplyCount)/sizeof(gS1.supplyCount[0]);

  for(i=0; i<numElements; i++) {
    total += gS1.supplyCount[i];
  }

  actions = gS1.numActions;
  numCards = gS1.handCount[0];
  numCards2 = gS1.handCount[1];

  playCard(0, 1, 0, 0, &gS1);

  for(i=0; i<numElements; i++) {
    total2 += gS1.supplyCount[i];
  }

  if(gS1.numActions == actions+1)
    printf("great_hall card: PASS when test containing is actions++ as great_hall\n");
  else
    printf("great_hall card: FAIL when test containing is actions++ as great_hall\n");

  if(gS1.handCount[0] == numCards-1)
    printf("great_hall card: PASS when test containing is handcount -1 as great_hall\n");
  else
    printf("great_hall card: FAIL when test containing is handcount -1 as great_hall\n");

  if(gS1.handCount[1] == numCards2)
    printf("great_hall card: PASS when test containing is handcount the same for p2 as great_hall\n");
  else
    printf("great_hall card: FAIL when test containing is handcount the same for p2 as great_hall\n");

  if(total == total2)
    printf("great_hall card: PASS when test containing is victory piles same as great_hall\n");
  else
    printf("great_hall card: FAIL when test containing is victory piles same as great_hall\n");


}

int main() {
  testGreat_Hall();
  return 0;
}