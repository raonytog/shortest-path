
/**
 * T1 TBO, professor: Luis Antonio de Souza Junior
 * Alunos:
 *      Barbara - 2023100254
 *      Raony - 2023102512
 */

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

    FILE *input = fopen(path, "r");
    if (!input) { printf("Error while trying to open input file!\nAborting..."); exit(EXIT_FAILURE); }

    char sourceName[20];   int sourceIdx = 0, numNodes = 0;
    readSourceName(input, sourceName, &sourceIdx);
    numNodes = readNumNodes(input);
    
    Node **nodes = readNodes(input, numNodes);
    djikstra(nodes, numNodes, sourceIdx);
    printDijkstraPathFile(nodes, numNodes, saida);

    destroyNodes(nodes, numNodes);
    fclose(input);
    return 0;
}
