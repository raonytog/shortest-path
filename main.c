#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "utils.h"

extern void djikstra(Node **nodes, int numNodes, int sourceIdx);

int main(int argc, char const *argv[]) {
    verifyArgc(argc);
    char path[100], saida[100];
    strcpy(path, argv[1]);
    strcpy(saida, argv[2]);

    clock_t start = clock();
    FILE *input = fopen(path, "r");

    char sourceName[20];   int sourceIdx = 0, numNodes = 0;
    readSourceName(input, sourceName, &sourceIdx);
    numNodes = readNumNodes(input);
    
    Node **nodes = readNodes(input, numNodes);
    djikstra(nodes, numNodes, sourceIdx);
    printDijkstraPathFile(nodes, numNodes, saida);

    destroyNodes(nodes, numNodes);
    fclose(input);

    clock_t end = clock();
    printf("Time spent: %.2f\n", ((double)end - (double)start)/CLOCKS_PER_SEC);
    return 0;
}
