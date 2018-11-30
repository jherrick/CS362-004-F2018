/*
int isGameOver(struct gameState *state) {
  int i;
  int j;
	
  //if stack of Province cards is empty, the game ends
  if (state->supplyCount[province] == 0)
    {
      return 1;
    }

  //if three supply pile are at 0, the game ends
  j = 0;
  for (i = 0; i < 25; i++)
    {
      if (state->supplyCount[i] == 0)
	{
	  j++;
	}
    }
  if ( j >= 3)
    {
      return 1;
    }

  return 0;
}*/

#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
//#include "structs.h"

void testIsGameOver() {
  struct gameState gS1; // province cards empty -- game over
  struct gameState gS2; // province cards not empty -- no game over
  struct gameState gS3; // 2 supply piles at 0 not game over
  struct gameState gS4; // 3 supply piles at 0 game over
  struct gameState gS5; // 4 supply piles at 0 game over
  struct gameState gS6; // 0 supply piles at 0 not game over
  struct gameState gS7; // all supply piles at 0 game over
  //int province = 0;
  int i;

  gS1.supplyCount[province] = 0;
  for (i = 0; i< 25; i++) {
    gS2.supplyCount[i] = 10;
  }
  gS2.supplyCount[province] = 1;

  for (i = 0; i< 25; i++) {
    gS3.supplyCount[i] = 10;
  }
  gS3.supplyCount[6] = 0;
  gS3.supplyCount[7] = 0;

  for (i = 0; i< 25; i++) {
    gS4.supplyCount[i] = 10;
  }
  gS4.supplyCount[6] = 0;
  gS4.supplyCount[7] = 0;
  gS4.supplyCount[8] = 0;
  
  for (i = 0; i< 25; i++) {
    gS5.supplyCount[i] = 10;
  }
  gS5.supplyCount[6] = 0;
  gS5.supplyCount[7] = 0;
  gS5.supplyCount[8] = 0;
  gS5.supplyCount[9] = 0;

  for (i = 0; i< 25; i++) {
    gS6.supplyCount[i] = 10;
  }  

  for (i = 0; i< 25; i++) {
    gS7.supplyCount[i] = 0;
  }  

  if(isGameOver(&gS1) == 1)
    printf("isGameOver(): PASS when test containing empty province as isGameOver\n");
  else
    printf("isGameOver(): FAIL when test containing empty province as isGameOver\n");

  if(isGameOver(&gS2) == 0)
    printf("isGameOver(): PASS when test containing province as isGameOver\n");
  else
    printf("isGameOver(): FAIL when test containing province as isGameOver\n");

  if(isGameOver(&gS3) == 0)
    printf("isGameOver(): PASS when test containing two empty supply piles as isGameOver\n");
  else
    printf("isGameOver(): FAIL when test containing two empty supply piles as isGameOver\n");

  if(isGameOver(&gS4) == 1)
    printf("isGameOver(): PASS when test containing three empty supply piles as isGameOver\n");
  else
    printf("isGameOver(): FAIL when test containing three empty supply piles as isGameOver\n");

  if(isGameOver(&gS5) == 1)
    printf("isGameOver(): PASS when test containing four empty supply piles as isGameOver\n");
  else
    printf("isGameOver(): FAIL when test containing four empty supply piles as isGameOver\n");

  if(isGameOver(&gS6) == 0)
    printf("isGameOver(): PASS when test containing zero empty supply piles as isGameOver\n");
  else
    printf("isGameOver(): FAIL when test containing zero empty supply piles as isGameOver\n");

  if(isGameOver(&gS7) == 1)
    printf("isGameOver(): PASS when test containing all empty supply piles as isGameOver\n");
  else
    printf("isGameOver(): FAIL when test containing all empty supply piles as isGameOver\n");

}

int main() {
  testIsGameOver();
  return 0;
}
