#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"


int main(int argc, char const *argv[]) {
    // verifyArgc(argc);
    // char path[100];
    // strcpy(path, argv[1]);

    char path[100] = "casos_teste_v3/caso_teste_muito_pequeno_1.txt";
    FILE *input = NULL;
    input = fopen(path, "r");

    char source_name[20];   int numNodes = 0;
    readSourceName(input, source_name);
    numNodes = readNumNodes(input);
    
    Node **nodes = readNodes(input, numNodes);
    for(int i = 0; i < numNodes; i++) {
        printNode(nodes[i]);
    }

    fclose(input);

    return 0;
}
