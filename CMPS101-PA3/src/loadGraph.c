/*
 ============================================================================
 Name        : loadGraph.c
 CruzID: rgmolina
 Name: Rogelio Molina-Marquez
 CMPS 101: Allen Van Gelder
 ============================================================================
 */

#include "loadGraph.h"

typedef struct {
	int from;
	int to;
	double weight;
} Edge;

////gets edge information from line of input
////this code was in the handout.
/////Precondition: Input file opened properly for reading
/////returns and Edge composed of from, to, and weight
Edge parseEdge(char line[]) {
	Edge newE;
	int numFields;
	char junk;
	numFields = sscanf(line, "%d %d %lf %c", &newE.from, &newE.to, &newE.weight,
			&junk);
	if (numFields < 2 || numFields > 3) {
		printf("Bad edge: %s", line);
		exit(1);
	} else if (numFields == 2) {
		newE.weight = 0.0;
	}
	return newE;
}

IntVec* loadGraph(FILE *in, int *n, int *m, char *line) {
	IntVec *myVec;
	int firstLine = 0;
	while (fgets(line, 1024, in) != NULL) {
		if (firstLine == 0) {
			*n = atoi(line);           ///obtain number of vertices first
			myVec = malloc(*n * sizeof(IntVec));
			for (int i = 0; i < *n; i++) {
				myVec[i] = intMakeEmptyVec(); ///make appropriate sized array of IntVecs
				firstLine = 1;
			}
		} else {
			Edge e = parseEdge(line);
			if (e.from > *n || e.from < 0) {
				fprintf(stderr, "Bad vertex: %d\n", e.from);
			} else if (e.to > *n || e.to < 0) {
				fprintf(stderr, "Bad vertex: %d\n", e.to);
			} else {
				intVecPush(myVec[e.from - 1], (e.to - 1)); ///push data into array
				(*m)++;
			}
		}
	}
	return myVec;
}

IntVec* loadGraphU(FILE *in, int *n, int *m, char *line) {
	IntVec *myVec;
	int firstLine = 0;
	while (fgets(line, 1024, in) != NULL) {
		if (firstLine == 0) {
			*n = atoi(line);           ///obtain number of vertices first
			myVec = malloc(*n * sizeof(IntVec));
			for (int i = 0; i < *n; i++) {
				myVec[i] = intMakeEmptyVec(); ///make appropriate sized array of IntVecs
				firstLine = 1;
			}
		} else {
			Edge e = parseEdge(line);
			if (e.from > *n || e.from < 0) {
				fprintf(stderr, "Bad vertex: %d\n", e.from);
			} else {
				intVecPush(myVec[e.from - 1], (e.to - 1)); ///push data into array
				(*m)++;
				intVecPush(myVec[e.to - 1], (e.from - 1));
				(*m)++;
			}
		}
	}
	return myVec;
}

int** makeAdjMatrix(IntVec *myVec, int n) {
	IntVec newVec;
////////Make a 2D array//////////////
	int **adjMatrix = (int **) malloc((n + 1) * sizeof(int *));
	for (int i = 0; i < n + 1; i++) {
		adjMatrix[i] = (int *) malloc((n + 1) * sizeof(int));
	}

/////////Initialize 2D array///////
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			adjMatrix[i][j] = 0;
		}
	}

	for (int j = 0; j < n; j++) {
		newVec = myVec[j];
		if (intSize(newVec) > 0) {
			for (int k = 0; k < intSize(newVec); k++) {
				adjMatrix[j + 1][intData(newVec, k) + 1] = 1;
			}
		}
	}
	return adjMatrix;
}

IntVec* transposeGraph(IntVec* origGraph, int n) {
	IntVec *transposed;
	IntVec tempVec;
	transposed = malloc(n * sizeof(IntVec));
	for (int i = 0; i < n; i++) {
		transposed[i] = intMakeEmptyVec();
	}
	for (int j = 0; j < n; j++) {
		tempVec = origGraph[j];
		for (int k = 0; k < intSize(tempVec); k++) {
			if (intSize(tempVec) > 0) {
				intVecPush(transposed[intData(tempVec, k)], j);
			}
		}
	}
	return transposed;
}

void printAdjVerts(int n, int m, IntVec *myVec) {
	printf("n = %d\n", n);
	printf("m = %d\n", m);
	IntVec newVec;
	for (int j = 0; j < n; j++) {
		newVec = myVec[j];
		printf("%d	", j + 1);
		if (intSize(newVec) > 1) {
			printf("[%d, ", (intTop(newVec) + 1));
		} else if (intSize(newVec) == 1) {
			printf("[%d]", (intTop(newVec) + 1));
		} else {
			printf("[]");
		}
		for (int k = intSize(newVec) - 2; k > 0; k--) {
			printf("%d, ", (intData(newVec, k) + 1));
		}
		if (intSize(newVec) > 1) {
			printf("%d]", (intData(newVec, 0) + 1));
		}
		printf("\n");
	}
}

void printAdjMatrix(int n, int **adjMatrix) {
	if (n > 12) {
		return;
	} else {
		printf("%3s  ", "   ");
		for (int i = 0; i < n; i++) {
			printf("%3d", i + 1);
		}
		printf("\n");
		printf("%3s  ", "   ");
		for (int i = 0; i < n; i++) {

			printf("%3s", "---");
		}
		printf("\n");
		for (int i = 1; i < n + 1; i++) {
			for (int j = 0; j < n + 1; j++) {
				if (j == 0) {
					printf("%3d :", i);
				} else {
					printf("%3d", adjMatrix[i][j]);
				}
			}
			printf("\n");
		}
	}
}
