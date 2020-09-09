/*
 ============================================================================
 Name        : dfsPhase2.h
 CruzID: rgmolina
 Name: Rogelio Molina-Marquez
 CMPS 101: Allen Van Gelder
 ============================================================================
 */

#ifndef DFSPHASE2_H_
#define DFSPHASE2_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "intVec.h"

// Pre: all arrays are declared, origGraph != NULL, n > 0
// Post: DFS and findRoot are run, and array values are printed
void dfsPhase2(int *root, IntVec *origGraph, int n, int *dTime, int *fTime,
		int *parent, char *color, IntVec *finishStk1);

// Pre: non-null arrays and variables
// Post: returns the timer of the current visit call, adds discover times, finish times
//       and parents accordingly
int dfsTrace2(int current, int ctr, char *color, IntVec *origGraph, int n,
		int *dTime, int *fTime, int *parent, IntVec *finishStk1);

// Pre: non-null arrays and variables
// Post: returns the root
int findRoot(int v, int *parent);

// Pre: non-null arrays and variables
// Post: arrays printed to console
void printPhase2(int n, char *color, int *dTime, int *fTime, int *parent,
		int *root);

#endif /* DFSPHASE2_H_ */
