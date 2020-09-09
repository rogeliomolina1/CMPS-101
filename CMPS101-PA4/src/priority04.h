/*
 ============================================================================
 Name        : priority04.h
 CruzID: rgmolina
 Name: Rogelio Molina-Marquez
 CMPS 101: Allen Van Gelder
 ============================================================================
 */

#ifndef PRIORITY04_H_
#define PRIORITY04_H_

#include "adjWgtVec.h"
#include "loadWgtGraph.h"
#include "priority04.h"
#include "minPQ.h"

void updateFringeMST(MinPQ pq, AdjWgtVec adjInfoOfV, int v) {
	while (adjWgtSize(adjInfoOfV) > 0) {
		AdjWgt wInfo = adjWgtTop(adjInfoOfV);
		int w = wInfo.to;
		double newWgt = wInfo.wgt;
		if (getStatus(pq, w) == UNSEEN) {
			insertPQ(pq, w, newWgt, v);
		} else if (getStatus(pq, w) == FRINGE) {
			if (newWgt < getPriority(pq, w)) {
				decreaseKey(pq, w, newWgt, v);
			}
		}
		adjWgtVecPop(adjInfoOfV);
	}
	return;
}

void updateFringeSSSP(MinPQ pq, AdjWgtVec adjInfoOfV, int v) {
	double myDist = getPriority(pq, v);
	while (adjWgtSize(adjInfoOfV) > 0) {
		AdjWgt wInfo = adjWgtTop(adjInfoOfV);
		int w = wInfo.to;
		double newDist = myDist + wInfo.wgt;
		if (getStatus(pq, w) == UNSEEN) {
			insertPQ(pq, w, newDist, v);
		} else if (getStatus(pq, w) == FRINGE) {
			if (newDist < getPriority(pq, w)) {
				decreaseKey(pq, w, newDist, v);
			}
		}
		adjWgtVecPop(adjInfoOfV);
	}
	return;
}

void MST(AdjWgtVec *myVec, int n, int s, int *status, int *parent,
		double *priority) {
	MinPQ pq = createPQ(n, status, priority, parent);
	insertPQ(pq, s, 0, -1);
	while (isEmptyPQ(pq) == 0) {
		int v = getMin(pq);
		delMin(pq);
		updateFringeMST(pq, myVec[v], v);
	}
	return;
}

void SSSP(AdjWgtVec *myVec, int n, int s, int *status, int *parent,
		double *priority) {
	MinPQ pq = createPQ(n, status, priority, parent);
	insertPQ(pq, s, 0, -1);
	while (isEmptyPQ(pq) == 0) {
		int v = getMin(pq);
		delMin(pq);
		updateFringeSSSP(pq, myVec[v], v);
	}
	return;
}

void printOutput(AdjWgtVec *myVec, int n, int s, int *status, int *parent,
		double *priority, char task) {
	if (task == 'D') {
		printf("Task: Dijkstra's Algorithm\n");
		printf("Start: %d\n", s);
		printf("%8s	%8s	%8s	%8s\n", "V", "Status", "Cost", "Parent");
		printf("%8s	%8s	%8s	%8s\n", "-", "------", "----", "------");
	}
	if (task == 'P') {
		printf("Task: Prim's Algorithm\n");
		printf("Start: %d\n", s);
		printf("%8s	%8s	%8s	%8s\n", "V", "Status", "Priority", "Parent");
		printf("%8s	%8s	%8s	%8s\n", "-", "------", "--------", "------");
	}
	for (int i = 1; i < n + 1; i++) {
		char temp = status[i];
		printf("%8d:	%8c	%8.2f	%8d\n", i, temp, priority[i], parent[i]);
	}
	printf("\n");
}

void greedyTree(AdjWgtVec *myVec, int n, int s, char task) {
	int *status = malloc((n + 1) * sizeof(int));
	int *parent = malloc((n + 1) * sizeof(int));
	double *priority = malloc((n + 1) * sizeof(double));
	for (int i = 0; i < n + 1; i++) {
		status[i] = UNSEEN;
		parent[i] = 0;
		priority[i] = 0;
	}
	if (task == 'P') {
		MST(myVec, n, s, status, parent, priority);
		printOutput(myVec, n, s, status, parent, priority, task);
	}
	if (task == 'D') {
		SSSP(myVec, n, s, status, parent, priority);
		printOutput(myVec, n, s, status, parent, priority, task);
	}
	return;
}
#endif /* PRIORITY04_H_ */
