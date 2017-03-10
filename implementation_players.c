/*
 * implementation_players.c
 *
 *  Created on: 7 Mar 2017
 *      Author: SK
 */
/*
 * implementation_players.c
 *
 *  Created on: 7 Mar 2017
 *      Author: SK
 */
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"players.h"
#include"structdefs.h"

/*player creation function*/
void PlayerCreation(struct players record[],int k){
	int i,j;
	int type_num,Capabilities;
	char temp[50];
	for(i=0; i<k; i++){
		// 1st players record
		printf("Player %d\n",i+1);
		record[i].Player_Num=i;   //sets the players number e.g. Player 1, Player2
		record[i].lifePoints=100; //sets the players life points to 100
		printf("Please enter the players name\n");
		scanf("%s",temp);

		/*For some reason,we found that we couldn't scan user input straight into a struct array
		 thus we had to create a temporary array,scan user input into this array then copy it into
		 our struct array */

		strcpy(record[i].name, temp);
		printf("Please press 1 to be an Elf\n");
		printf("Please press 2 to be an Human\n");
		printf("Please press 3 to be an Ogre\n");
		printf("Please press 4 to be an Wizard\n");

		scanf("%d",&type_num);
		/* this takes the user input and correlates the number to the specified character type you want*/
		Capabilities=0;
		if(type_num==1){
			strcpy(record[i].type, "Elf");

			record[i].luck = rand() % (100-60+1)+60;//random number from 60-100
			record[i].smartness = rand() % (100-70+1)+70;//random number from 70-100
			record[i].Dexterity = rand() % 100+1;//random number from 1-100
			record[i].strength = rand() % 50+1;//random number from 1-50
			record[i].magicSkills = rand() % (79-51+1)+50;//random number from 50-79


		}

		if(type_num==2){
			strcpy(record[i].type, "Human");
			for(j=0;j<1;++j){
				record[i].luck = rand() % 100+1;//random number from 1-100
				record[i].smartness = rand() % 100+1;//random number from 1-100
				record[i].Dexterity = rand() % 100+1;//random number between 1-100
				record[i].strength = rand() % 100+1;//random number between 1-100
				record[i].magicSkills = rand() % 100+1;//random number between 1-100
				Capabilities = Capabilities+record[i].luck + record[i].smartness + record[i].Dexterity + record[i].strength + record[i].magicSkills;
				/*if the capabilities of all the humans abilities is greater than 300 it will basically redo the
				 * abilities until the sum is less then 300*/
				if(Capabilities>=300){
					j=-1;
					Capabilities=0;
				}
			}
		}

		if(type_num==3){
			strcpy(record[i].type, "Ogre");
			for(j=0;j<1;j++){

				record[i].luck = rand() % 51;//random number from 0-50
				record[i].smartness = rand() % 21;//random number from 0-20

				/*If the sum of a human's luck and smartness abilities is greater than 50 this loop will iterate until
				 *until the sum is less then or equal to 50*/
				if(record[i].luck+record[i].smartness>50){
					j=j-1;
				}
			}

			record[i].Dexterity = rand() % (100-80+1)+80;//random number from 80-100
			record[i].strength = rand() % ((100-80+1))+80;//random number from 80-100
			record[i].magicSkills =0;


		}

		if(type_num==4){
			strcpy(record[i].type, "Wizard");
			record[i].luck = rand() % (100-50+1)+50;//random number from 50-100
			record[i].smartness = rand() % (100-90+1)+90;//random number from 90-100
			record[i].Dexterity = rand() % 100+1;//random number from 1-100
			record[i].strength = rand() % 20+1;//random number from 1-20
			record[i].magicSkills =rand() % (100-80+1)+80;//random number from 80-100
		}

		if(type_num>4||type_num<1){
			printf("Invalid number, please enter this players details again\n");
			i=i-1;
		}
	}

}

/*Function to print the players details */
void playerPrint(struct players record[],int k){
	int i;

	for(i=0; i<k; i++)
	{
		printf("     Records of player : %d \n", i+1);
		printf(" Name is: %s \n", record[i].name);
		printf(" Player type is: %s\n\n",record[i].type);
		printf(" luck: %d\n\n",record[i].luck);
		printf(" smart: %d\n\n",record[i].smartness);
		printf(" Dexterity: %d\n\n",record[i].Dexterity);
		printf(" Strength: %d\n\n",record[i].strength);
		printf(" MagicSkills: %d\n\n",record[i].magicSkills);
	}
}

