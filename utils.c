#include "utils.h"

void verifyArgc(int argc) { 
    if (argc > 1) return;
    printf("ERRO: diretorio de arquivos nao informado\n");
    exit(1);
}

void readSourceName(FILE *input, char *s) {
    if (!input) return;
    fscanf(input, "%[^\n]%*c", s);
}

int readNumNodes(FILE *input) {
    if (!input) return -1;

    int count = 0;
    char buffer[1023];

    while (fscanf(input, "%[^\n]%*c", buffer) == 1) {
        count++;
    }

    return count;
}

Node **readNodes(FILE *input, int qtdNode) {
    if (!input || qtdNode < 0) return NULL;

    char name[20]; int distance;
    rewind(input);
    fscanf(input, "%[^\n]%*c", name);

    Node **nodes = malloc(qtdNode * sizeof(Node*));
    for (int i = 0; i < qtdNode; i++) {
        fscanf(input, "%[^,],", name);
        
        Node *new = createNode(name, i, qtdNode);
        for (int j = 0; j < qtdNode; j++) {
            if (i == j) setNodeAdj(new, j, 0);
            else {
                fscanf(input, " %d%*c", &distance);
                setNodeAdj(new, j, distance);
            }
        }
        nodes[i] = new;
    }
    return nodes;
}