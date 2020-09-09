/*
 ============================================================================
 Name        : loadWgtGraph.c
 CruzID: rgmolina
 Name: Rogelio Molina-Marquez
 CMPS 101: Allen Van Gelder
 ============================================================================
 */

#include "loadWgtGraph.h"

AdjWgt parseEdge(char line[], int *from) {
	AdjWgt newE;
	int numFields;
	char junk;
	numFields = sscanf(line, "%d %d %lf %c", from, &newE.to, &newE.wgt, &junk);
	if (numFields < 2 || numFields > 3) {
		printf("Bad edge: %s", line);
		exit(1);
	} else if (numFields == 2) {
		newE.wgt = 0.0;
	}
	return newE;
}

AdjWgtVec* loadWgtGraph(FILE *in, int *n, int *m, char *line) {
	AdjWgtVec *myVec;
	int firstLine = 0;
	while (fgets(line, 1024, in) != NULL) {
		if (firstLine == 0) {
			*n = atoi(line);           ///obtain number of vertices first
			myVec = malloc((*n + 1) * sizeof(AdjWgtVec));
			for (int i = 1; i < (*n + 1); i++) {
				myVec[i] = adjWgtMakeEmptyVec(); ///make appropriate sized array of IntVecs
			}
			firstLine = 1;
		} else {
			int from = 0;
			AdjWgt e = parseEdge(line, &from);
			if (from > *n || from < 0) {
				fprintf(stderr, "Bad vertex: %d\n", from);
			} else if (e.to > *n || e.to < 0) {
				fprintf(stderr, "Bad vertex: %d\n", e.to);
			} else {
				adjWgtVecPush(myVec[from], e); ///push data into array
				(*m)++;
			}
		}
	}
	return myVec;
}

AdjWgtVec* loadWgtGraphU(FILE *in, int *n, int *m, char *line) {
	AdjWgtVec *myVec;
	int firstLine = 0;
	while (fgets(line, 1024, in) != NULL) {
		if (firstLine == 0) {
			*n = atoi(line);           ///obtain number of vertices first
			myVec = malloc((*n + 1) * sizeof(AdjWgtVec));
			for (int i = 1; i < (*n + 1); i++) {
				myVec[i] = adjWgtMakeEmptyVec(); ///make appropriate sized array of IntVecs
			}
			firstLine = 1;
		} else {
			int from = 0;
			AdjWgt e = parseEdge(line, &from);
			int temp;
			if (from > *n || from < 0) {
				fprintf(stderr, "Bad vertex: %d\n", from);
			} else if (e.to > *n || e.to < 0) {
				fprintf(stderr, "Bad vertex: %d\n", e.to);
			} else {
				adjWgtVecPush(myVec[from], e); ///push data into array
				(*m)++;
				temp = from;
				from = e.to;
				e.to = temp;
				adjWgtVecPush(myVec[from], e);
				(*m)++;
			}
		}
	}
	return myVec;
}

void printAdjVerts(int n, int m, AdjWgtVec *myVec) {
	printf("n = %d\n", n);
	printf("m = %d\n", m);
	AdjWgtVec newVec;
	for (int j = 1; j < n + 1; j++) {
		newVec = myVec[j];
		printf("%d	", j);
		if (adjWgtSize(newVec) > 1) {
			printf("[%d, ", (adjWgtTop(newVec).to));
		} else if (adjWgtSize(newVec) == 1) {
			printf("[%d]", (adjWgtTop(newVec).to));
		} else {
			printf("[]");
		}
		for (int k = adjWgtSize(newVec) - 1; k > 1; k--) {
			printf("%d, ", (adjWgtData(newVec, k).to));
		}
		if (adjWgtSize(newVec) > 1) {
			printf("%d]", (adjWgtData(newVec, 1).to));
		}
		printf("\n");
	}
}
