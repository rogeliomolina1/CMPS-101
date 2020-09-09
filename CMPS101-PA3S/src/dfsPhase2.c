/*
 ============================================================================
 Name        : dfsPhase2.c
 CruzID: rgmolina
 Name: Rogelio Molina-Marquez
 CMPS 101: Allen Van Gelder
 ============================================================================
 */
#include "dfsPhase2.h"

void dfsPhase2(int *root, IntVec *origGraph, int n, int *dTime, int *fTime,
		int *parent, char *color, IntVec *finishStk1) {
	int ctr = 1;
	for (int k = 0; k < n; k++) {
		color[k] = 'W';
		dTime[k] = 0;
		fTime[k] = 0;
		parent[k] = -1;
		root[k] = -1;
	}
	while (intSize(*finishStk1) > 0) {
		if (color[intTop(*finishStk1) - 1] == 'W') {
			ctr = dfsTrace2(intTop(*finishStk1) - 1, ctr, color, origGraph, n,
					dTime, fTime, parent, finishStk1);
		}
		intVecPop(*finishStk1);
	}

	for (int i = 0; i < n; i++) {
		root[i] = findRoot(i, parent);

	}
}

int dfsTrace2(int current, int ctr, char *color, IntVec *origGraph, int n,
		int *dTime, int *fTime, int *parent, IntVec *finishStk1) {
	color[current] = 'G';
	dTime[current] = ctr;
	ctr++;
	while (intSize(origGraph[current]) > 0) {
		if (color[intTop(origGraph[current])] == 'W') {
			parent[intTop(origGraph[current])] = (current + 1);
			ctr = dfsTrace2(intTop(origGraph[current]), ctr, color, origGraph,
					n, dTime, fTime, parent, finishStk1);
		} else {
			intVecPop(origGraph[current]);
		}
	}
	color[current] = 'B';
	fTime[current] = ctr;
	ctr++;
	return ctr;
}

int findRoot(int vertex, int *parent) {
	if (parent[vertex] == -1) {
		return vertex + 1;
	} else {
		return (findRoot(parent[vertex - 1], parent));
	}
}

void printPhase2(int n, char *color, int *dTime, int *fTime, int *parent,
		int *root) {
	printf("\n");
	printf("%5s	%5s	%5s	%5s	%5s %5s\n", "V", "color2", "dTime2", "fTime2",
			"parent2", "dfstRoot2");
	for (int i = 0; i < n; i++) {
		printf("%5d	%5c	%5d	%5d	%5d %5d\n", i + 1, color[i], dTime[i], fTime[i],
				parent[i], root[i]);
	}
	printf("\n");
}
