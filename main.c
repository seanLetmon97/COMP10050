/*
 * main.c
 *
 *  Created on: 10 Mar 2017
 *      Author: SK
 */
/*24 Feb 2017
 *Admin
 *15:33:56
 *Comp10050project
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "slots.h"
#include "player_turns.h"
#include "players.h"
#include "structdefs.h"


int main()
{
	setvbuf(stdout, NULL, _IOLBF, 0);
	srand(time(NULL));

	int k,i,input;
	printf("Please enter the number of players\n");
	scanf("%d",&k);

	if(k<=1 || k>6){
		printf("error too many or not enough players\n");
		return (0);
	}
	struct players record[k]; //Initializes the struct players record array
	record[0].playerAmount=k;
	PlayerCreation(record,k);//passes are players array and the variable k which in this case is equal to the number of players
	printf("\n");
	playerPrint(record,k);//passes are players array and the variable k which in this case is equal to the number of players
	printf("\n");
	printf("Please enter the number of slots\n");
	scanf("%d",&k);//k is now equal to the number of slots
	if(k<record[0].playerAmount || k>20){
		printf("error too many or not enough slots chosen\n");
		return (0);
	}
	struct slots array[k]; //Initializes the struct slots array Array
	slotCreation(array,record,k);//passes the slots array and the players array and the variable k which in this case is equal to the number of slots

	/* this for loop will give each player, 1 turn to either attack or move*/
	for(i=0;i<record[0].playerAmount;i++){
		printf("%s's turn:\n",record[i].name);
		printf("Press 1 to move or press 2 to attack\n");
		scanf("%d",&input);

		if(input==1){

			i=Movement(array,record,k,i);//passes the slots array and the players array and the variable k which in this case is equal to the number of slots and i is equal to the players number
		}

		if(input==2){
			attack(array,record,k,i);//passes the slots array and the players array and the variable k which in this case is equal to the number of slots and i is equal to the players number
		}

		if(input>2||input<1){
			printf("Incorrect choice,Try again\n");
			i=i-1;
		}
	}


	SlotPrint(array,record,k);//passes the slots array and the players array and the variable k which in this case is equal to the number of slots
	printf("\n\n");
	FinalResult(array,record,k);//passes the slots array and the players array and the variable k which in this case is equal to the number of slots
	return 0;
}


