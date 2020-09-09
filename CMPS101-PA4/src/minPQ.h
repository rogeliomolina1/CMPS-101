/*
 ============================================================================
 Name        : minPQ.h
 CruzID: rgmolina
 Name: Rogelio Molina-Marquez
 CMPS 101: Allen Van Gelder
 ============================================================================
 */

/* minPQ.h
 * The purpose of this file is to share declarations with multiple source files
 * and to give the compiler the information it needs about what structures
 * and functions are available.
 */

#ifndef C101MinPQ
#define C101MinPQ
/* Multiple typedefs for the same type are an error in C. */

typedef struct MinPQNode * MinPQ;

#define UNSEEN ('u')
#define FRINGE ('f')
#define INTREE ('t')

/* ***************** Access functions */

/** isEmptyPQ
 * precondition: MinPQ has been constructed.
 */
int isEmptyPQ(MinPQ pq);

/** getMin
 * precondition: MinPQ has been constructed.
 */
int getMin(MinPQ pq);

/** getStatus
 * precondition: MinPQ has been constructed.
 * precondition: 0 < id < numVertices.
 */
int getStatus(MinPQ pq, int id);

/** getParent
 * precondition: MinPQ has been constructed.
 * precondition: 0 < id < numVertices.
 */
int getParent(MinPQ pq, int id);

/** getPriority
 * precondition: MinPQ has been constructed.
 * precondition: 0 < id < numVertices.
 */
double getPriority(MinPQ pq, int id);

/* ***************** Manipulation procedures */

/** delMin
 * precondition: MinPQ has been constructed
 * precondition: numPQ > 0.
 * postcondition: remove element and decrease numPQ.
 */
void delMin(MinPQ pq);

/** insertPQ
 * precondition: MinPQ has been constructed.
 * postcondition: add element and increase numPQ.
 */
void insertPQ(MinPQ pq, int id, double priority, int par);

/** decreaseKey
 * precondition: MinPQ has been constructed.
 */
void decreaseKey(MinPQ pq, int id, double priority, int par);

/* ***************** Constructors */

/** createPQ
 * preconditions: none.
 * postconditions: Let /return be the value returned by createPQ.
 * initialize parent and priority to 0
 * initialize status to UNSEEN
 * numVertiecs = n;
 * numPQ = 0;
 * pq->minVertex = -1;
 * pq->oo = very small number;
 */
MinPQ createPQ(int n, int status[], double priority[], int parent[]);

#endif
