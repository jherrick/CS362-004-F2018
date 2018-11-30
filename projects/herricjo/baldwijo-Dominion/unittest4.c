/*
int numHandCards(struct gameState *state) {
  return state->handCount[ whoseTurn(state) ];
}
*/

#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
//#include "structs.h"

void testNumHandCards() {
	struct gameState gS1;
	struct gameState gS2;

	gS1.whoseTurn = 0;
	gS1.handCount[gS1.whoseTurn] = 10;

	gS2.whoseTurn = 1;
	gS2.handCount[gS2.whoseTurn] = 0;
	
	if(numHandCards(&gS1) == 10)
		printf("numHandCards(): PASS when test containing 10 as whoseTurn\n");
	else
		printf("numHandCards(): FAIL when test containing 10 as whoseTurn\n");


	if(numHandCards(&gS2) == 0)
		printf("numHandCards(): PASS when test containing 0 as whoseTurn\n");
	else
		printf("numHandCards(): FAIL when test containing 0 as whoseTurn\n");
}

int main() {
  testNumHandCards();
  return 0;
}
