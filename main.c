#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

int main(int argc, char const *argv[]) {
    // verifyArgc(argc);
    // char path[100], saida[100];
    // strcpy(path, argv[1]);
    // strcpy(saida, argv[2]);

    char path[100] = "casos_teste_v3/caso_teste_muito_pequeno_2.txt";
    char saida[100] = "saida.txt";
    FILE *input = fopen(path, "r");

    char sourceName[20];   int sourceIdx = 0, numNodes = 0;
    readSourceName(input, sourceName, &sourceIdx);
    numNodes = readNumNodes(input);
    
    Node **nodes = readNodes(input, numNodes);
    dijkstraPQ(nodes, numNodes, sourceIdx);
    printDijkstraPathFile(nodes, numNodes, saida);

    destroyNodes(nodes, numNodes);
    fclose(input);

    return 0;
}
