/*
 ============================================================================
 Name        : dfsTrace1.c
 CruzID: rgmolina
 Name: Rogelio Molina-Marquez
 CMPS 101: Allen Van Gelder
 ============================================================================
 */

#include "dfsTrace1.h"
#include "loadGraph.h"

void dfsTrace1(IntVec *origGraph, int n, int *dTime, int *fTime, int *parent,
		char *color, IntVec *finishStk1) {
	int ctr = 1;
	for (int k = 0; k < n; k++) {
		color[k] = 'W';
		dTime[k] = 0;
		fTime[k] = 0;
		parent[k] = -1;
	}
	for (int i = 0; i < n; i++) {
		if (color[i] == 'W') {
			ctr = dfs(i, ctr, color, origGraph, n, dTime, fTime, parent,
					finishStk1);
		}
	}
}

int dfs(int current, int ctr, char *color, IntVec *origGraph, int n, int *dTime,
		int *fTime, int *parent, IntVec *finishStk1) {
	color[current] = 'G';
	dTime[current] = ctr;
	ctr++;
	while (intSize(origGraph[current]) > 0) {
		if (color[intTop(origGraph[current])] == 'W') {
			parent[intTop(origGraph[current])] = (current + 1);
			ctr = dfs(intTop(origGraph[current]), ctr, color, origGraph, n,
					dTime, fTime, parent, finishStk1);
		} else {
			intVecPop(origGraph[current]);
		}
	}
	color[current] = 'B';
	intVecPush(*finishStk1, current + 1);
	fTime[current] = ctr;
	ctr++;
	return ctr;
}

void printTrace1(int n, char *color, int *dTime, int *fTime, int *parent,
		IntVec finishStk1) {
	printf("\n");
	printf("%5s	%5s	%5s	%5s	%5s\n", "V", "color", "dTime", "fTime", "parent");
	for (int i = 0; i < n; i++) {
		printf("%5d	%5c	%5d	%5d	%5d\n", i + 1, color[i], dTime[i], fTime[i],
				parent[i]);
	}
	printf("\n");

	printf("FSTK: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", intData(finishStk1, i));
	}
	printf("\n\n");
}
