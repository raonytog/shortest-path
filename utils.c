/**
 * T1 TBO, professor: Luis Antonio de Souza Junior
 * Alunos:
 *      Barbara - 2023100254
 *      Raony - 2023102512
 */

#include <math.h>

#include "utils.h"
#include "list.h"
#include "PQ.h"

void verifyArgc(int argc) { 
    if (argc > 1) return;

    printf("ERRO: diretorio de arquivos nao informado\n");
    exit(1);
}

void readSourceName(FILE *input, char *sourceName, int *source_idx) {
    if (!input) return;

    fscanf(input, "%[^_]_%d%*c", sourceName, source_idx);
}

int readNumNodes(FILE *input) {
    if (!input) return -1;

    int count = 0;
    char c;
    while (fscanf(input, "%c", &c) == 1) {
        if (c == ',') count++;
        else if (c == '\n') break;
    }
    count++;
    return count;
}

Node **readNodes(FILE *input, int qtdNode) {
    if (!input || qtdNode < 0) return NULL;

    char name[20] = "\n", bomba[10] = "\n";
    float distance = 0;

    rewind(input);
    fscanf(input, "%[^\n]%*c", name); /* node source, ja lido anteriormente*/

    Node **nodes = malloc(qtdNode * sizeof(Node*));
    if (!nodes) { printf("Nodes nao foram inicializados!\n"); exit(EXIT_FAILURE); }

    for (int i = 0; i < qtdNode; i++) {
        fscanf(input, "%[^,],", name);

        Node *new = createNode(name, i, qtdNode);
        for (int j = 0; j < qtdNode; j++) {
            /** define a distance do node para ele mesmo */
            if (i == j) { setNodeAdj(new, j, 0);
            } else {
                /** tenta ler um numero */
                if (fscanf(input, " %f", &distance) == 1) { setNodeAdj(new, j, distance); }

                /** trata a bomba */
                else { fscanf(input, "%s", bomba); setNodeAdj(new, j, 0); }

                /** ignora as vírgulas e espaços */ 
                fscanf(input, "%*[ \n,]");
            }
        }
        nodes[i] = new;
    }
    return nodes;
}

void destroyNodes(Node **nodes, int numNodes) {
    if (!nodes || numNodes < 0) return;


    for(int i = 0; i < numNodes; i++) {
        destroyNode(nodes[i]);
    }
    free(nodes);
}

void printNodes(Node **nodes, int numNodes) { 
    if (!nodes || numNodes < 0) return;

    for(int i = 0; i < numNodes; i++) {
        printNode(nodes[i]);
    }
}

void printNodeParentChain(Node *node) {
    if (!node) return;
    printf("%s", getNodeName(node));
    if (getNodeFather(node)) printf(" <- ");
    printNodeParentChain(getNodeFather(node));
}

void fprintNodeParentChain(FILE *output, Node *node) {
    if (!node || !output) return;
    fprintf(output, "%s", getNodeName(node));
    if (getNodeFather(node)) fprintf(output, " <- ");
    fprintNodeParentChain(output, getNodeFather(node));
}

void printDijkstraPath(Node **nodes, int numNodes) {
    if (!nodes || numNodes < 0) return;

    qsort(nodes, numNodes, sizeof(Node*), compareFloat);

    /** Source node */
    printf("SHORTEST PATH TO %s: ", getNodeName(nodes[0]));
    printf("%s <- %s (Distance: %.2f)\n", 
        getNodeName(nodes[0]), getNodeName(nodes[0]), getNodeDistance(nodes[0]));

    for (int i = 1; i < numNodes; i++) {
        printf("SHORTEST PATH TO %s: ", getNodeName(nodes[i]));
        printNodeParentChain(nodes[i]);
        printf(" (Distance: %.2f)\n", getNodeDistance(nodes[i]));
    }
}

void printDijkstraPathFile(Node **nodes, int numNodes, char *path) {
    if (!nodes || numNodes < 0) return;

    FILE *output = fopen(path, "w");

    if (!output) {
        printf("Erro ao abrir o arquivo %s\n", path);
        return;
    }
    
    qsort(nodes, numNodes, sizeof(Node*), compareFloat);

    /** Source node */
    fprintf(output, "SHORTEST PATH TO %s: ", getNodeName(nodes[0]));
    fprintf(output, "%s <- %s (Distance: %.2f)\n", 
        getNodeName(nodes[0]), getNodeName(nodes[0]), getNodeDistance(nodes[0]));

    for (int i = 1; i < numNodes; i++) {
        fprintf(output, "SHORTEST PATH TO %s: ", getNodeName(nodes[i]));
        fprintNodeParentChain(output, nodes[i]);
        fprintf(output, " (Distance: %.2f)\n", getNodeDistance(nodes[i]));
    }

    fclose(output);
}