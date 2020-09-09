# Rogelio Molina-Marquez
# CruzID: rgmolina
# CMPS101-Allen Van Gelder
# The following is the make file for pa4. 

CC     = gcc
CFLAGS = -g -Wall -O0 -std=c99 -D_SVID_SOURCE

priority04:	priority04.o  minPQ.o  adjWgtVec.o loadWgtGraph.o
	${CC}  -o priority04  ${CFLAGS} priority04.o  minPQ.o  adjWgtVec.o loadWgtGraph.o

priority04.o:	priority04.c  priority04.h  minPQ.h  adjWgtVec.h loadWgtGraph.h
	${CC}  -c  ${CFLAGS}  priority04.c
	
minPQ.o:	minPQ.c  minPQ.h
	${CC}  -c  ${CFLAGS}  minPQ.c
	
adjWgtVec.o:	adjWgtVec.c  adjWgtVec.h
	${CC}  -c  ${CFLAGS}  adjWgtVec.c
	
loadWgtGraph.o:	loadWgtGraph.c  loadWgtGraph.h  adjWgtVec.h
	${CC}  -c  ${CFLAGS}  loadWgtGraph.c
