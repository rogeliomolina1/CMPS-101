/*
 ============================================================================
 Name        : dfsTrace1.h
 CruzID: rgmolina
 Name: Rogelio Molina-Marquez
 CMPS 101: Allen Van Gelder
 ============================================================================
 */

#ifndef DFSTRACE1_H_
#define DFSTRACE1_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "intVec.h"

/////Precondition: origGraph has been constructed
/////Postcondition: all arrays are filled with proper data for time, color, and parent
void dfsTrace1(IntVec *origGraph, int n, int *dTime, int *fTime, int *parent, char *color);

/////Precondition: origGraph has been constructed
/////Postcondition: all arrays are filled with proper data for time, color, and parent
int dfs(int current, int ctr, char *color, IntVec *origGraph, int n, int *dTime,
		int *fTime, int *parent);

/////Precondition: all arrays are filled with proper data for time, color, and parent
void printTrace1(int n, char *color, int *dTime, int *fTime, int *parent);

#endif /* DFSTRACE1_H_ */
