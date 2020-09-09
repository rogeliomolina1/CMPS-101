/*
 ============================================================================
 Name        : intVec.c
 CruzID: rgmolina
 Name: Rogelio Molina-Marquez
 CMPS 101: Allen Van Gelder
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "intVec.h"

typedef struct IntVecNode {
	int * data;
	int sz;
	int capacity;
} IntVecNode;

/* Access functions
 */

int intTop(IntVec myVec) {
	int top = 0;
	if (myVec->sz > 0) {
		top = myVec->data[myVec->sz - 1]; //go to the last pushed element
	}
	return top;
}

int intData(IntVec myVec, int i) {
	if (i < 0 || i > intSize(myVec) - 1) { //checks precondition is met
		return 0;
	}
	return myVec->data[i];
}

int intSize(IntVec myVec) {
	return myVec->sz;
}

int intCapacity(IntVec myVec) {
	return myVec->capacity;
}

/* Constructors
 */

IntVec intMakeEmptyVec(void) {
	IntVec newVec = malloc(1 * sizeof(struct IntVecNode));
	newVec->data = malloc(intInitCap * sizeof(int));
	newVec->sz = 0;
	newVec->capacity = intInitCap;
	return newVec;
}

IntVec intMakeEmptyVecN(int np1) {
	IntVec newVec = malloc(1 * sizeof(struct IntVecNode));
	newVec->data = malloc(intInitCap * sizeof(int));
	newVec->sz = 0;
	newVec->capacity = np1;
	return newVec;
}

/* Manipulation Procedures
 */

void intVecPush(IntVec myVec, int newE) {
	myVec->sz++;
	if (myVec->sz == myVec->capacity) {
		myVec->capacity = myVec->capacity * 2;
		myVec->data = realloc(myVec->data, myVec->capacity * sizeof(int));
	}
	myVec->data[myVec->sz - 1] = newE;
	assert(intTop(myVec) == newE);
}

void intVecPop(IntVec myVec) {
	myVec->data[myVec->sz - 1] = 0;
	if (myVec->sz > 0) {
		myVec->sz--;
	} else {
		myVec->sz = 0;
	}
}
