/*
 ============================================================================
 Name        : scc03.c
 CruzID: rgmolina
 Name: Rogelio Molina-Marquez
 CMPS 101: Allen Van Gelder
 ============================================================================
 */

#include "loadGraph.h"
#include "dfsPhase2.h"
#include "dfsTrace1.h"
#include "intVec.h"

void findSCCs(IntVec *myVec, int n, int m) {
	IntVec finishStk1;
	IntVec *transpose;
	int **adjMatrixTranspose;
	int dTime1[n];
	int fTime1[n];
	int parent1[n];
	char color1[n];
	int dTime2[n];
	int fTime2[n];
	int parent2[n];
	char color2[n];
	int root[n];
	finishStk1 = intMakeEmptyVecN(n);

	transpose = transposeGraph(myVec, n);
	dfsTrace1(myVec, n, dTime1, fTime1, parent1, color1, &finishStk1);
	printTrace1(n, color1, dTime1, fTime1, parent1, finishStk1);
	printAdjVerts(n, m, transpose);
	printf("\n");
	adjMatrixTranspose = makeAdjMatrix(transpose, n);
	printAdjMatrix(n, adjMatrixTranspose);
	printf("\n");
	dfsPhase2(root, transpose, n, dTime2, fTime2, parent2, color2, &finishStk1);
	printPhase2(n, color2, dTime2, fTime2, parent2, root);
}

int main(int argc, char * argv[]) {
	IntVec *myVec;
	int **adjMatrix;
	int n = 0;
	int m = 0;
	FILE *in;
	char line[1024];
///usage message when no input .txt is provided
	if (argc == 1) {
		fprintf(stderr, "Usage: %s <filename.txt> \n", argv[0]);
		exit(0);
	} else if (argc == 2) {
		in = fopen(argv[1], "r");
		if (in == NULL) {                       ///check if open successful.
			fprintf(stderr, "Unable to open %s for reading\n", argv[1]);
			exit(1);
		} else {
			myVec = loadGraph(in, &n, &m, line);
			fclose(in);
		}
	} else if (argc == 3) {
		in = fopen(argv[2], "r");
		if (in == NULL) {                       ///check if open successful.
			fprintf(stderr, "Unable to open %s for reading\n", argv[1]);
			exit(1);
		} else {
			int flag = strcmp(argv[1], "-U");
			if (flag == 0) {
				myVec = loadGraphU(in, &n, &m, line);
				fclose(in);
			} else {
				fprintf(stderr, "Invalid flag %s\n", argv[1]);
				exit(1);
			}
		}
	}

///Printing the output
	printf("Opened %s for input.\n", argv[2]);
	printAdjVerts(n, m, myVec);
	printf("\n");
	adjMatrix = makeAdjMatrix(myVec, n);
	printAdjMatrix(n, adjMatrix);
	printf("\n");
	findSCCs(myVec, n, m);
	return 0;
}
