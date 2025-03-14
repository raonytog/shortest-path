/**
 * T1 TBO, professor: Luis Antonio de Souza Junior
 * Alunos:
 *      Barbara - 2023100254
 *      Raony - 2023102512
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "node.h"
#include "PQ.h"
#include <math.h>

struct Node {
    char *name;
    int idx;         /** respectivo ao indice presente no nome */

    Node *father;
    float distance;  /** distancia com respeito ao nó fonte */

    float *adj;      /** lista de adjacencia */
    int adjSize;

    int PQ_idx;      /** caso não esteja na fila, representado com -1 */
};

Node *createNode(char *name, int idx, int qtdNodes) {
    if (!name || idx < 0) return NULL;

    Node *new = malloc(sizeof(Node));
    new->name = strdup(name);
    new->idx = idx;

    new->father = NULL;
    new->distance = INFINITY;
    new->PQ_idx = -1;

    new->adj = malloc(qtdNodes * sizeof(float));
    new->adjSize = qtdNodes;

    return new;
}

void printNode(Node *node) {
    if (!node) return;

    printf("%s,", getNodeName(node));

    int count = 0; 

    for (int i = 0; i < node->adjSize; i++) {
        if (i == node->idx) continue;
        if (count > 0) printf(",");

        printf(" %.2f", node->adj[i]);
        count++;
    }

    printf("\n");
}

void setNodePQIdx(Node *node, int idx) {
    if (!node) return;
    node->PQ_idx = idx;
}

int getNodePQIdx(Node *node) {
    if (!node) return -1;
    return node->PQ_idx;
}

void destroyNode(Node *node) {
    if (!node) return;

    free(node->name);
    free(node->adj);
    free(node);
}

int compareFloat(const void *n, const void *m) {
    if (!n || !m) exit(EXIT_FAILURE);

    Node *a = *(Node **)n;
    Node *b = *(Node **)m;

    float numA = getNodeDistance(a), numB = getNodeDistance(b);
    if (numA > numB) return 1;
    else if (numA < numB) return -1;
    else return 0;
}

char* getNodeName(Node *node) {
    if (!node) return NULL;
    return node->name;
}

Node* getNodeFather(Node *node) {
    if (!node) return NULL;
    return node->father;
}

float getNodeDistance(Node *node) {
    if (!node) return 0;
    return node->distance;
}

float* getNodeAdjList(Node *node) {
    if (!node) return 0;
    return node->adj;
}

void setNodeAdj(Node *node, int idx, float distance) {
    if (!node || idx < 0 || distance < 0) return;
    node->adj[idx] = distance;
}

void setNodeFather(Node *node, Node *father) {
    if (!node || !father) return;
    node->father = father;
}

void setNodeDistance(Node *node, float distance) {
    if (!node || distance < 0) return;
    node->distance = distance;
}

