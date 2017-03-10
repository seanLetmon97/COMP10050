/*
 * player_turns.h
 *
 *  Created on: 7 Mar 2017
 *      Author: Admin
 */

#ifndef PLAYER_TURNS_H_
#define PLAYER_TURNS_H_

#include"structdefs.h"

int Movement(struct slots array[],struct players record[],int k,int i);

void attack(struct slots array[],struct players record[],int k,int i);

void FinalResult(struct slots array[],struct players record[],int k);

#endif /* PLAYER_TURNS_H_ */
