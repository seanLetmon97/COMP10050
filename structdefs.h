/*
 * structdefs.h
 *
 *  Created on: 7 Mar 2017
 *      Author: SK
 */

#ifndef STRUCTDEFS_H_
#define STRUCTDEFS_H_


struct players
{
	char name[30];
	char type[30];
	int Player_Num;
	int lifePoints;
	int luck;
	int smartness;
	int Dexterity;
	int strength;
	int magicSkills;
	int playerAmount;
	int slot_num;
};

struct slots
{
	char slot_name[30];
	int slot_num;
};


#endif /* STRUCTDEFS_H_ */
