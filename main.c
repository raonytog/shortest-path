#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "utils.h"

int main(int argc, char const *argv[]) {
    // verifyArgc(argc);
    // char path[100];
    // strcpy(path, argv[1]);

    char path[100] = "casos_teste_v3/caso_teste_muito_pequeno_2.txt";
    FILE *input = NULL;
    input = fopen(path, "r");

    clock_t start = clock();
    char sourceName[20];   int sourceIdx = 0, numNodes = 0;
    readSourceName(input, sourceName, &sourceIdx);
    numNodes = readNumNodes(input);
    
    Node **nodes = readNodes(input, numNodes);
    newDijkstraPQ(nodes, numNodes, sourceIdx);
    printDijkstraPathFile(nodes, numNodes, "saida.txt");

    destroyNodes(nodes, numNodes);
    fclose(input);

    clock_t end = clock();
    printf("\n\nTime spent: %lf\n", ((double)end - (double)start)/CLOCKS_PER_SEC);
    return 0;
}
