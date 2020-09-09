/*
 ============================================================================
 Name        : digraph01.c
 CruzID: rgmolina
 Name: Rogelio Molina-Marquez
 CMPS 101: Allen Van Gelder
 ============================================================================
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "intVec.h"

typedef struct {
	int from;
	int to;
	double weight;
} Edge;

Edge parseEdge(char line[]) {
	Edge newE;
	int numFields;
	numFields = sscanf(line, "%d %d %lf %*s", &newE.from, &newE.to,
			&newE.weight);
	if (numFields < 2 || numFields > 3) {
		printf("Bad edge: %s", line);
		exit(1);
	}
	if (numFields == 2)
		newE.weight = 0.0;
	return newE;
}

int main(int argc, char * argv[]) {
	IntVec *myVec;
	int n = 0;
	int m = 0;
	FILE *in;
	int firstLine = 0;
	char line[1024];
	if (argc == 1) {
		fprintf(stderr, "Usage: %s <filename.txt> \n", argv[0]);
		exit(0);
	} else {
		in = fopen(argv[1], "r");
		if (in == NULL) {
			fprintf(stderr, "Unable to open %s for reading\n", argv[1]);
			exit(1);
		} else {
			while (fgets(line, 1024, in) != NULL) {
				if (firstLine == 0) {
					n = atoi(line);
					myVec = malloc(n * sizeof(IntVec));
					for (int i = 0; i < n; i++) {
						myVec[i] = intMakeEmptyVec();
						firstLine = 1;
					}
				} else {
					Edge e = parseEdge(line);
					if (e.from > n || e.from < 0) {
						fprintf(stderr, "Bad vertex: %d\n", e.from);
					} else {
						intVecPush(myVec[e.from - 1], e.to);
						m++;
					}
				}
			}
			fclose(in);

			printf("Opened %s for input.\n", argv[1]);
			printf("n = %d\n", n);
			printf("m = %d\n", m);
			IntVec newVec;
			for (int j = 0; j < n; j++) {
				newVec = myVec[j];
				printf("%d      ", j + 1);
				if (intSize(newVec) > 1) {
					printf("[%d,", intData(newVec, 0));
				} else if (intSize(newVec) == 1) {
					printf("[%d]", intData(newVec, 0));
				} else {
					printf("[]");
				}
				for (int k = 1; k < intSize(newVec) - 1; k++) {
					printf("%d,", intData(newVec, k));
				}
				if (intSize(newVec) > 1) {
					printf("%d]", intData(newVec, intSize(newVec) - 1));
				}
				printf("\n");
			}
		}
	}
	return 0;
}
