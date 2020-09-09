/*
 ============================================================================
 Name        : priority.c
 CruzID: rgmolina
 Name: Rogelio Molina-Marquez
 CMPS 101: Allen Van Gelder
 ============================================================================
 */

#include "adjWgtVec.h"
#include "loadWgtGraph.h"
#include "priority04.h"
#include "minPQ.h"

int main(int argc, char * argv[]) {
	AdjWgtVec *myVec;
	int n = 0;
	int m = 0;
	int s = 0;
	char task;
	FILE *in;
	char line[1024];
///usage message when no input .txt is provided
	if (argc < 4) {
		fprintf(stderr, "Usage: %s <flag> <start> <filename.txt> \n", argv[0]);
		exit(0);
	} else if (argc == 4) {
		s = atoi(argv[2]);
		in = fopen(argv[3], "r");
		if (in == NULL) {                       ///check if open successful.
			fprintf(stderr, "Unable to open %s for reading\n", argv[3]);
			exit(1);
		} else {
			int flagP = strcmp(argv[1], "-P");
			int flagD = strcmp(argv[1], "-D");
			if (flagP == 0) {
				myVec = loadWgtGraphU(in, &n, &m, line);
				task = 'P';
				fclose(in);
			} else if (flagD == 0) {
				myVec = loadWgtGraph(in, &n, &m, line);
				task = 'D';
				fclose(in);
			} else {
				fprintf(stderr, "Invalid flag %s\n", argv[1]);
				exit(1);
			}
		}
	} else {
		fprintf(stderr, "Usage: %s <flag> <start> <filename.txt> \n", argv[0]);
		exit(0);
	}
///Printing the output
	if (s > n || s < 1) {
		fprintf(stderr, "Invalid starting vertex %s\n", argv[1]);
		exit(1);
	} else {
		printf("Opened %s for input.\n", argv[2]);
		printf("\n");
		greedyTree(myVec, n, s, task);
	}
	return 0;
}
