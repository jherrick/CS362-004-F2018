/*int whoseTurn(struct gameState *state) {
  return state->whoseTurn;
}
struct gameState {
  int numPlayers; //number of players
  int supplyCount[treasure_map+1];  //this is the amount of a specific type of card given a specific number.
  int embargoTokens[treasure_map+1];
  int outpostPlayed;
  int outpostTurn;
  int whoseTurn;
  int phase;
  int numActions; Starts at 1 each turn
  int coins; Use as you see fit! 
  int numBuys; Starts at 1 each turn
  int hand[MAX_PLAYERS][MAX_HAND];
  int handCount[MAX_PLAYERS];
  int deck[MAX_PLAYERS][MAX_DECK];
  int deckCount[MAX_PLAYERS];
  int discard[MAX_PLAYERS][MAX_DECK];
  int discardCount[MAX_PLAYERS];
  int playedCards[MAX_DECK];
  int playedCardCount;

*/

#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
//#include "structs.h"

void testWhoseTurn() {
	struct gameState gS1;
	struct gameState gS2;

	gS1.whoseTurn = 0;
	gS2.whoseTurn = 1;

	if(whoseTurn(&gS1) == 0)
		printf("whoseTurn(): PASS when test containing 0 as whoseTurn\n");
	else
		printf("whoseTurn(): FAIL when test containing 0 as whoseTurn\n");

	if(whoseTurn(&gS2) == 1)
		printf("whoseTurn(): PASS when test containing 1 as whoseTurn\n");
	else
		printf("whoseTurn(): FAIL when test containing 1 as whoseTurn\n");
}

int main() {
  testWhoseTurn();
  return 0;
}
