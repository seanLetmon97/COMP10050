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


void PlayerCreation(struct players record[],int k){
	int i,j;
	int type_num,Capabilities;
	char temp[50];
	for(i=0; i<k; i++){
		// 1st players record
		printf("Player %d\n",i+1);
		record[i].Player_Num=i;
		record[i].lifePoints=100;
		printf("Please enter the players name\n");
		scanf("%s",temp);
		strcpy(record[i].name, temp);
		printf("Please press 1 to be an Elf\n");
		printf("Please press 2 to be an Human\n");
		printf("Please press 3 to be an Ogre\n");
		printf("Please press 4 to be an Wizard\n");

		scanf("%d",&type_num);

		Capabilities=0;
		if(type_num==1){
			strcpy(record[i].type, "Elf");

			record[i].luck = rand() % (100-60+1)+60;
			record[i].smartness = rand() % (100-70+1)+70;
			record[i].Dexterity = rand() % 100+1;
			record[i].strength = rand() % 50+1;
			record[i].magicSkills = rand() % (79-51+1)+50;


		}

		if(type_num==2){
			strcpy(record[i].type, "Human");
			for(j=-1;j<1;++j){
				record[i].luck = rand() % 100+1;
				record[i].smartness = rand() % 100+1;
				record[i].Dexterity = rand() % 100+1;
				record[i].strength = rand() % 100+1;
				record[i].magicSkills = rand() % 100+1;
				Capabilities = Capabilities+record[i].luck + record[i].smartness + record[i].Dexterity + record[i].strength + record[i].magicSkills;
				if(Capabilities>=300){
					j=-1;
					Capabilities=0;
				}
			}
		}

		if(type_num==3){
			strcpy(record[i].type, "Ogre");
			for(j=0;j<1;j++){

				record[i].luck = rand() % 51;
				record[i].smartness = rand() % 21;
				if(record[i].luck + record[i].smartness>50){
				j=j-1;
				}
				}
				record[i].Dexterity = rand() % (100-80+1)+80;
				record[i].strength = rand() % ((100-80+1))+80;
				record[i].magicSkills =0;
				Capabilities=record[i].luck+record[i].smartness;


		}

		if(type_num==4){
			strcpy(record[i].type, "Wizard");
			record[i].luck = rand() % (100-50+1)+50;
			record[i].smartness = rand() % (100-90+1)+90;
			record[i].Dexterity = rand() % 100+1;
			record[i].strength = rand() % 20+1;
			record[i].magicSkills =rand() % (100-80+1)+80;
		}

		if(type_num>4||type_num<1){
			printf("Invalid number, please enter this players details again\n");
			i=i-1;
		}
	}

}

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

