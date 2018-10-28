/*nt getCost(int cardNumber)
{
  switch( cardNumber ) 
    {
    case curse:
      return 0;
    case estate:
      return 2;
    case duchy:
      return 5;
    case province:
      return 8;
    case copper:
      return 0;
    case silver:
      return 3;
    case gold:
      return 6;
    case adventurer:
      return 6;
    case council_room:
      return 5;
    case feast:
      return 4;
    case gardens:
      return 4;
    case mine:
      return 5;
    case remodel:
      return 4;
    case smithy:
      return 4;
    case village:
      return 3;
    case baron:
      return 4;
    case great_hall:
      return 3;
    case minion:
      return 5;
    case steward:
      return 3;
    case tribute:
      return 5;
    case ambassador:
      return 3;
    case cutpurse:
      return 4;
    case embargo: 
      return 2;
    case outpost:
      return 5;
    case salvager:
      return 4;
    case sea_hag:
      return 4;
    case treasure_map:
      return 4;
    }
  
  return -1;
}

*/

#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
//#include "structs.h"

void testGetCost() {
  int wrong_val;

  if(getCost(outpost) == 5)
    printf("getCost(): PASS when test containing outpost as getCost\n");
  else
    printf("getCost(): FAIL when test containing outpost as getCost\n");

  if(getCost(0) == 0)
    printf("getCost(): PASS when test containing 0 as getCost\n");
  else
    printf("getCost(): FAIL when test containing 0 as getCost\n");

  if(getCost(treasure_map) == 4)
    printf("getCost(): PASS when test containing treasure_map as getCost\n");
  else
    printf("getCost(): FAIL when test containing treasure_map as getCost\n");

  if(getCost(wrong_val) == -1)
    printf("getCost(): PASS when test containing wrong_val as getCost\n");
  else
    printf("getCost(): FAIL when test containing wrong_val as getCost\n");
}

int main() {
  testGetCost();
  return 0;
}

