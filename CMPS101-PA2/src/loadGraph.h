/*
 ============================================================================
 Name        : loadGraph.h
 CruzID: rgmolina
 Name: Rogelio Molina-Marquez
 CMPS 101: Allen Van Gelder
 ============================================================================
 */

#ifndef LOADGRAPH_H_
#define LOADGRAPH_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "intVec.h"

typedef struct {
	int from;
	int to;
	double weight;
} Edge;

/////Precondition: Input file opened properly for reading
/////returns and Edge composed of from, to, and weight
Edge parseEdge(char line[]);

/////Precondition: Input file opened properly for reading
/////Postcondition: Returns and IntVec pointer to the graph
IntVec* loadGraph(FILE *in, int *n, int *m, char *line);

/////Precondition: Input file opened properly for reading
/////Postcondition: Returns and IntVec pointer to the undirected graph
IntVec* loadGraphU(FILE *in, int *n, int *m, char *line);

/////Precondition: myVec has been constructed
/////Postcondition returns a double array that makes the Adjacency matrix
int** makeAdjMatrix(IntVec*myVec, int n);

/////Precondition: origGraph has been constructed
/////Postcondition: returns a transposed origGraph
IntVec* transposeGraph(IntVec* origGraph, int n);

/////Precondition: myVec has been constructed
void printAdjVerts(int n, int m, IntVec *myVec);

/////Precondition: adjMatrix has been constructed and n<=12
void printAdjMatrix(int n, int **adjMatrix);

#endif /* LOADGRAPH_H_ */
