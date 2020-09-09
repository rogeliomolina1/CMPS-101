/*
 ============================================================================
 Name        : loadWgtGraph.h
 CruzID: rgmolina
 Name: Rogelio Molina-Marquez
 CMPS 101: Allen Van Gelder
 ============================================================================
 */

#ifndef LOADWGTGRAPH_H_
#define LOADWGTGRAPH_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "adjWgtVec.h"

/////Precondition: Input file opened properly for reading
/////Postcondition: Returns and IntVec pointer to the graph
AdjWgtVec* loadWgtGraph(FILE *in, int *n, int *m, char *line);

/////Precondition: Input file opened properly for reading
/////Postcondition: Returns and IntVec pointer to the undirected graph
AdjWgtVec* loadWgtGraphU(FILE *in, int *n, int *m, char *line);

/////Precondition: myVec has been constructed
void printAdjVerts(int n, int m, AdjWgtVec *myVec);

#endif /* LOADWGTGRAPH_H_ */
