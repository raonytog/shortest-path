#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void verifyArgc(int argc);

void readSourceName(FILE *input, char *s, int *source_idx);

int readNumNodes(FILE *input);

Node **readNodes(FILE *input, int qtdNode);

void destroyNodes(Node **nodes, int numNodes);

void printNodes(Node **nodes, int numNodes);

void dijkstraPQ(Node **nodes, int numNodes, int sourceIdx);

void dijkstraLL(Node **nodes, int numNodes, int sourceIdx);

void printDijkstraPath(Node **nodes, int numNodes);


#endif