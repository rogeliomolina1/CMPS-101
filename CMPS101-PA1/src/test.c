///*
// ============================================================================
// Name        : test.c
// CruzID: rgmolina
// Name: Rogelio Molina-Marquez
// CMPS 101: Allen Van Gelder
// ============================================================================
// */
//
//#include <stdlib.h>
//#include <string.h>
//#include <stdio.h>
//#include "intVec.h"
//int main(void) {
//
///////////Making IntVec///////
//	IntVec myVec = intMakeEmptyVec();
//
//////Testing push and displaying size, top, and capacity as elements are added
//	intVecPush(myVec, 10);
//	printf("sz=%d\ntop=%d\ncapacity=%d\n", intSize(myVec), intTop(myVec),
//			intCapacity(myVec));
//	intVecPush(myVec, 34);
//	printf("sz=%d\ntop=%d\ncapacity=%d\n", intSize(myVec), intTop(myVec),
//			intCapacity(myVec));
//	intVecPush(myVec, 150);
//	printf("sz=%d\ntop=%d\ncapacity=%d\n", intSize(myVec), intTop(myVec),
//			intCapacity(myVec));
//	intVecPush(myVec, 1);
//	printf("sz=%d\ntop=%d\ncapacity=%d\n", intSize(myVec), intTop(myVec),
//			intCapacity(myVec));
//	intVecPush(myVec, 5);
//	printf("sz=%d\ntop=%d\ncapacity=%d\n", intSize(myVec), intTop(myVec),
//			intCapacity(myVec));
//	intVecPush(myVec, 8);
//	printf("sz=%d\ntop=%d\ncapacity=%d\n", intSize(myVec), intTop(myVec),
//			intCapacity(myVec));
//	intVecPush(myVec, 3);
//	printf("sz=%d\ntop=%d\ncapacity=%d\n", intSize(myVec), intTop(myVec),
//			intCapacity(myVec));
//	intVecPush(myVec, 8);
//	printf("sz=%d\ntop=%d\ncapacity=%d\n", intSize(myVec), intTop(myVec),
//			intCapacity(myVec));
//	intVecPush(myVec, 0);
//	printf("sz=%d\ntop=%d\ncapacity=%d\n", intSize(myVec), intTop(myVec),
//			intCapacity(myVec));
//	intVecPush(myVec, 3);
//	printf("sz=%d\ntop=%d\ncapacity=%d\n", intSize(myVec), intTop(myVec),
//			intCapacity(myVec));
//	intVecPush(myVec, 1);
//	printf("sz=%d\ntop=%d\ncapacity=%d\n", intSize(myVec), intTop(myVec),
//			intCapacity(myVec));
//
//	//////////Testing looking up data
//	printf("\n\n\ndata at i=10=%d", intData(myVec, 10));
//
//	printf("\n\n\nNow starting pop\n\n\n");
//
//	///////////Testing pop, displaying, size, top, and capacity as elements are popped
//	intVecPop(myVec);
//	printf("sz=%d\ntop=%d\ncapacity=%d\n", intSize(myVec), intTop(myVec),
//			intCapacity(myVec));
//	intVecPop(myVec);
//	printf("sz=%d\ntop=%d\ncapacity=%d\n", intSize(myVec), intTop(myVec),
//			intCapacity(myVec));
//	intVecPop(myVec);
//	printf("sz=%d\ntop=%d\ncapacity=%d\n", intSize(myVec), intTop(myVec),
//			intCapacity(myVec));
//	intVecPop(myVec);
//	printf("sz=%d\ntop=%d\ncapacity=%d\n", intSize(myVec), intTop(myVec),
//			intCapacity(myVec));
//	intVecPop(myVec);
//	printf("sz=%d\ntop=%d\ncapacity=%d\n", intSize(myVec), intTop(myVec),
//			intCapacity(myVec));
//	intVecPop(myVec);
//	printf("sz=%d\ntop=%d\ncapacity=%d\n", intSize(myVec), intTop(myVec),
//			intCapacity(myVec));
//	intVecPop(myVec);
//	printf("sz=%d\ntop=%d\n", intSize(myVec), intTop(myVec));
//	intVecPop(myVec);
//	printf("sz=%d\ntop=%d\n", intSize(myVec), intTop(myVec));
//	intVecPop(myVec);
//	printf("sz=%d\ntop=%d\n", intSize(myVec), intTop(myVec));
//	intVecPop(myVec);
//	printf("sz=%d\ntop=%d\n", intSize(myVec), intTop(myVec));
//	intVecPop(myVec);
//	printf("sz=%d\ntop=%d\n", intSize(myVec), intTop(myVec));
//	intVecPop(myVec);
//	printf("sz=%d\ntop=%d\n", intSize(myVec), intTop(myVec));
//	intVecPop(myVec);
//	printf("sz=%d\ntop=%d\n", intSize(myVec), intTop(myVec));
//
//	return 0;
//}
