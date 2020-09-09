/*
 ============================================================================
 Name        : adjWgtVec.c
 CruzID: rgmolina
 Name: Rogelio Molina-Marquez
 CMPS 101: Allen Van Gelder
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "adjWgtVec.h"

typedef struct AdjWgtVecNode {
	AdjWgt * data;
	int sz;
	int capacity;
} AdjWgtVecNode;

AdjWgt adjWgtTop(AdjWgtVec myVec) {
	AdjWgt top;
	if (myVec->sz > 0) {
		top.to = myVec->data[myVec->sz].to; //go to the last pushed element
		top.wgt = myVec->data[myVec->sz].wgt;
	}
	return top;
}

AdjWgt adjWgtData(AdjWgtVec myVec, int i) {
	if (i < 1 || i > adjWgtSize(myVec)) { //checks precondition is met
		AdjWgt temp;
		temp.to = 0;
		temp.wgt = 0;
		return temp;

	}
	return myVec->data[i];
}

int adjWgtSize(AdjWgtVec myVec) {
	return myVec->sz;
}

int adjWgtCapacity(AdjWgtVec myVec) {
	return myVec->capacity;
}

AdjWgtVec adjWgtMakeEmptyVec(void) {
	AdjWgtVec newVec = malloc(1 * sizeof(struct AdjWgtVecNode));
	newVec->data = malloc(adjWgtInitCap * sizeof(AdjWgt));
	newVec->sz = 0;
	newVec->capacity = adjWgtInitCap;
	return newVec;
}

void adjWgtVecPush(AdjWgtVec myVec, AdjWgt newE) {
	myVec->sz++;
	if (myVec->sz == myVec->capacity) {
		myVec->capacity = myVec->capacity * 2;
		myVec->data = realloc(myVec->data, myVec->capacity * sizeof(AdjWgt));
	}
	myVec->data[myVec->sz].to = newE.to;
	myVec->data[myVec->sz].wgt = newE.wgt;
	return;
}

void adjWgtVecPop(AdjWgtVec myVec) {
	if (adjWgtSize(myVec) > 0) {
		myVec->data[myVec->sz].to = 0;
		myVec->data[myVec->sz].wgt = 0;
		if (myVec->sz > 0) {
			myVec->sz--;
		} else {
			myVec->sz = 0;
		}
	} else {
		return;
	}
	return;
}
