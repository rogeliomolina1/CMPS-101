/*
 ============================================================================
 Name        : dfs03.c
 CruzID: rgmolina
 Name: Rogelio Molina-Marquez
 CMPS 101: Allen Van Gelder
 ============================================================================
 */

#include "loadGraph.h"

int main(int argc, char * argv[]) {
	IntVec *myVec;
	IntVec *transpose;
	int **adjMatrix;
	int **adjMatrixTranspose;
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

	int dTime[n];
	int fTime[n];
	int parent[n];
	char color[n];
///Printing the output
	printf("Opened %s for input.\n", argv[1]);
	printAdjVerts(n, m, myVec);
	printf("\n");
	adjMatrix = makeAdjMatrix(myVec, n);
	printAdjMatrix(n, adjMatrix);
	printf("\n");
	transpose = transposeGraph(myVec, n);
	printAdjVerts(n, m, transpose);
	printf("\n");
	adjMatrixTranspose = makeAdjMatrix(transpose, n);
	printAdjMatrix(n, adjMatrixTranspose);
	printf("\n");
	dfsTrace1(myVec, n, dTime, fTime, parent, color);
	printTrace1(n, color, dTime, fTime, parent);
	return 0;
}
