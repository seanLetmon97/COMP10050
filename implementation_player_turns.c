/*
 * implementation_player_turns.c
 *
 *  Created on: 7 Mar 2017
 *      Author: Admin
 */
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"player_turns.h"
#include"structdefs.h"



/*function for players to move during there turn*/
int Movement(struct slots array[],struct players record[],int k,int i){

	/*the values passed into this function are: k == the number of slots
	 *
	 * i=the players number e.g player 1 and at the start I assign t the value of i
	 */
	int choice;
	int t=i;

	printf("Press to move 1 space forward or 2 to go backwards, or 3 to restart your turn\n");
	scanf("%d",&choice);
	int j;
	if(choice==1){

		/*This is a check to see if there is any player in front the current player
		 * as you cant proceed to a slot if another player is on that slot
		 */
		for(j=0;j<record[0].playerAmount;j++){
			if(record[i].slot_num==k || record[i].slot_num+1==record[j].slot_num ){
				printf("Invalid move you can not move forward, please restart your turn\n");
				choice=0;
				return i-1;//returns i-1 which will go to the for loop in the main and basically restart this players turn
			}
		}
		//will place the current player onto the next slot
		//also makes sure that this player is not on the last slot
		if(record[i].slot_num<k && record[i].slot_num+1 != record[i+1].slot_num){
			record[i].slot_num=record[i].slot_num+1;
			printf("%s's new slot number: %d \n",record[i].name,record[i].slot_num);

		}
	}

	/*This is a check to see if there is any player in behind the current player
	 * as you cant proceed to a slot if another player is on that slot
	 */

	if(choice==2){
		for(j=0;j<record[0].playerAmount;j++){
			if(record[i].slot_num==0 || record[i].slot_num-1==record[j].slot_num){
				printf("Invalid move you can not move backward, please restart your turn\n");
				choice=0;
				return i-1;
			}
		}

		//will place the current player onto the previous slot
		//also makes sure that this player is not on the very first slot
		if(record[i].slot_num>0 && record[i].slot_num-1 != record[i-1].slot_num) {
			record[i].slot_num=record[i].slot_num-1;
			printf("%s's new slot number: %d \n ",record[i].name,record[i].slot_num);

		}
	}

	/*Will restart this players turn*/
	if(choice==3){
		return i-1;
	}

	/* if the player has moved the following changes are applied to the
	 * players ability based on the slot
	 * type the player has moved to.
	 */
	if(choice==1 || choice==2){
		j=i;

		for(i=0;i<k;i++){
			//compares if the array[i].slot_num==record[j].slot_num meaning it compares the two different variables from the two different structs
			if(array[i].slot_num==record[j].slot_num){

				if (strncmp(array[i].slot_name,"LevelGround",2)==0){
					//no changes applied for this slot type
				}

				if (strncmp(array[i].slot_name,"Hill",2)==0){
					if(record[j].Dexterity<50){
						record[j].strength=record[j].strength-10;
					}
					if(record[j].Dexterity>=60){
						record[j].strength=record[j].strength+10;
					}

					if(record[j].strength<0){
						record[j].strength=0;
					}
					if(record[j].strength>100){
						record[j].strength=100;
					}
				}

				if (strncmp(array[i].slot_name,"City",2)==0){
					if(record[j].smartness>60){
						record[j].magicSkills=record[j].magicSkills+10;
					}
					if(record[j].smartness<=50){
						record[j].Dexterity=record[j].Dexterity-10;
					}

					//this is to cap the abbilities so they dont go above 100 or below 0
					if(record[j].Dexterity<0){

						record[j].Dexterity=0;
					}
					if(record[j].magicSkills>100){

						record[j].magicSkills=100;
					}
				}

			}
		}
	}
	return t;
}

/*Function for the players attack turn*/
void attack(struct slots array[],struct players record[],int k,int i){

	/*the values passed into this function are: k == the number of slots
	 *
	 * i=the players number e.g player 1 and at the start I assign t the value of i
	 */
	int j,min=i,min2=i,temp=k,temp2=k,choice,value=k,value2=k;

	/*what this for loop will do is get the first closest slot number, that a player is on,
	 *to the current player, it does this by getting the absolute value of the difference
	 *between the two slot numbers and when it records which player was closest by getting the
	 *minimum absolute value. it will also not record the value when compared to itself
	 *as that would give an absolute value of 0*/
	for ( j = 0 ; j < record[0].playerAmount ; j++ )
	{
		temp=record[i].slot_num-record[j].slot_num;
		temp=abs(temp);
		if(i!=j){

			if ( temp < k )
			{
				k=temp;
				value=temp;
				min=j;//Assigns player slot number of player who is currently closest to player i.
			}
		}
	}

	/*what this for loop will do is get the second closest slot number, that a player is on,
	 *to the current player, it does this by getting the absolute value of the difference
	 *between the two slot numbers and when it records which player was closest by getting the
	 *minimum absolute value. it will also not record the value when compared to itself
	 *as that would give an absolute value of 0 and it will also ignore the previous result
	 *so this would allow the the loop to get the second closest*/
	k=value2;
	for ( j = 0 ; j < record[0].playerAmount ; j++ )
	{
		temp2=record[i].slot_num-record[j].slot_num;
		temp2=abs(temp2);
		if(i!=j && j!=min){

			if ( temp2 < k )
			{
				value2=temp2;
				k=temp2;
				min2=j;//Same as above however we are now finding the second closest player to player i.
			}
		}
	}

	//if the closest value and the next closest value are not equal, then it will attack the closest player

	if(value!=value2){

		if(record[min].strength<=70){
			record[min].lifePoints=record[min].lifePoints-(.5*record[min].strength);
		}
		if(record[min].strength>70){
			record[i].lifePoints=record[min].lifePoints-(.3*record[min].strength);
		}

	}

	//if the closest value and the next closest value are equal, then it will attack whoever the user chooses, the player in front or behind them

	if(value==value2 && min!=min2){
		printf("you have two possible targets the same distance away.\n");
		printf("Press 1 to attack in front and press 2 to attack behind\n");
		scanf("%d",&choice);

		if(choice<=1){
			if(record[min].strength<=70){
				record[min].lifePoints=record[min].lifePoints-(.5*record[min].strength);
			}
			if(record[min].strength>70){
				record[i].lifePoints=record[min].lifePoints-(.3*record[min].strength);
			}

		}

		if(choice>=2){
			if(record[min2].strength<=70){
				record[min2].lifePoints=record[min2].lifePoints-(.5*record[min2].strength);
			}
			if(record[min2].strength>70){
				record[i].lifePoints=record[min2].lifePoints-(.3*record[min2].strength);
			}

		}




	}

}

/*function which prints in the format given in the assignment*/
void FinalResult(struct slots array[],struct players record[],int k){
	int i=0;
	for(i=0;i<record[0].playerAmount;i++){
		printf("%s  (%s, %d)\n",record[i].name,record[i].type,record[i].lifePoints);
	}

}


