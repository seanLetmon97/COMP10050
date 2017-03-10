/*
 * implementation_slots.c
 *
 *  Created on: 7 Mar 2017
 *      Author: SK
 */
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"slots.h"
#include"structdefs.h"


/*Function to create slots*/
void slotCreation(struct slots array[],struct players record[], int k){
	int i,j;


	/*This code will get a random number between 0 and 3 including 0
	 * and will then match this number with the correct slot type as listed below,
	 */
	for(i=0;i<k;i++){
		j = rand() % 3;
		if(j==0){
			strcpy(array[i].slot_name,"Level Ground");
		}
		if(j==1){
			strcpy(array[i].slot_name,"Hill");
		}
		if(j==2){
			strcpy(array[i].slot_name,"City");
		}
		array[i].slot_num=i;
	}

	int temp;
	int arrayRand[k];
	//k is the amount of slots which has been passed from the main into this function
	//this creates a simple array counting from 0 to the amount of slots specified
	for(i=0;i<k;i++)
	{
		arrayRand[i]=i;
	}

	/*Randomly sorts the above array*/
	for ( i = k-1; i > 0; i--)
	{
		// Pick a random index from 0 to i
		int j = rand() % (i+1);
		temp=arrayRand[i];
		arrayRand[i]=arrayRand[j];
		arrayRand[j]=temp;


	}

	/*this will take the new randomly arranged digits from the above array,
	 * and will basically copy the first element of arrayRand to the first element of
	 * record[i].slotnum
	 */
	for(i=0;i<record[0].playerAmount;i++)
	{
		record[i].slot_num=arrayRand[i];

	}
	for(i=0;i<record[0].playerAmount;i++){
		printf("%s's slot number is: %d \n",record[i].name, record[i].slot_num);
	}


}

/*function to print out the slot details*/
void SlotPrint(struct slots array[],struct players record[],int k){
	int j,i;

	for(i=0; i<k; i++)
	{


		for(j=0;j<record[0].playerAmount;j++){
			if(record[j].slot_num==array[i].slot_num){
				//printf("     Slot : %d \n", i+1);
				printf(" slot type: %s \n", array[i].slot_name);
				//printf(" slot number: %d \n", array[i].slot_num);
				printf(" Player on  this: %s\n\n",record[j].name);
				printf(" New luck: %d\n\n",record[j].luck);
				printf(" New smart: %d\n\n",record[j].smartness);
				printf("New Dexterity: %d\n\n",record[j].Dexterity);
				printf("New Strength: %d\n\n",record[j].strength);
				printf("New MagicSkills: %d\n\n",record[j].magicSkills);
				printf("Life Points: %d\n\n",record[j].lifePoints);
			}
		}
	}
}
