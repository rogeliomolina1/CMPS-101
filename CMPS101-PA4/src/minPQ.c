/*
 ============================================================================
 Name        : minPQ.c
 CruzID: rgmolina
 Name: Rogelio Molina-Marquez
 CMPS 101: Allen Van Gelder
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "minPQ.h"

typedef struct MinPQNode {
	int numVertiecs, numPQ;
	int minVertex;
	float oo;
	int *status;
	int *parent;
	double *priority;
} MinPQNode;

int isEmptyPQ(MinPQ pq) {
	if (pq->numPQ == 0) {
		return 1;
	} else {
		return 0;
	}
}

int getMin(MinPQ pq) {
	if (pq->minVertex == -1) {
		double minPriority = 0;
		minPriority = pq->oo;
		for (int v = 1; v < pq->numVertiecs + 1; v++) {
			if (pq->status[v] == FRINGE) {
				if (pq->priority[v] < minPriority) {
					pq->minVertex = v;
					minPriority = pq->priority[v];
				}
			}
		}
	}
	return pq->minVertex;
}

int getStatus(MinPQ pq, int id) {
	return pq->status[id];
}

int getParent(MinPQ pq, int id) {
	return pq->parent[id];
}

double getPriority(MinPQ pq, int id) {
	return pq->priority[id];
}

/* ***************** Manipulation procedures */

void delMin(MinPQ pq) {
	int oldMin = getMin(pq);
	pq->status[oldMin] = INTREE;
	pq->minVertex = -1;
	pq->numPQ--;
	return;
}

void insertPQ(MinPQ pq, int id, double priority, int par) {
	pq->parent[id] = par;
	pq->priority[id] = priority;
	pq->status[id] = FRINGE;
	pq->minVertex = -1;
	pq->numPQ++;
	return;
}

void decreaseKey(MinPQ pq, int id, double priority, int par) {
	pq->parent[id] = par;
	pq->priority[id] = priority;
	pq->minVertex = -1;
	return;
}

/* ***************** Constructors */

MinPQ createPQ(int n, int status[], double priority[], int parent[]) {
	MinPQ pq = malloc(1 * sizeof(struct MinPQNode));
	pq->parent = parent;
	pq->priority = priority;
	pq->status = status;
	for (int i = 0; i < n + 1; i++) {
		status[i] = UNSEEN;
	}
	pq->numVertiecs = n;
	pq->numPQ = 0;
	pq->minVertex = -1;
	pq->oo = INFINITY;
	return pq;
}
