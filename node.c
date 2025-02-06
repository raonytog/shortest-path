#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "node.h"
#include "PQ.h"

struct Node {
    char *name;
    int idx;

    Node *father;
    float distance;

    float *adj;
    int adjSize;
};

Node *createNode(char *name, int idx, int qtdNodes) {
    if (!name || idx < 0) return NULL;

    Node *new = malloc(sizeof(Node));
    new->name = strdup(name);
    new->idx = idx;

    new->father = NULL;
    new->distance = 0;

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

void destroyNode(Node *node) {
    if (!node) return;

    free(node->name);
    free(node->adj);
    free(node);
}

int compare(Node *n, Node *m) {
    return n->distance - m->distance;
}

char* getNodeName(Node *node) {
    if (!node) return NULL;
    return node->name;
}

Node* getNodeFather(Node *node) {
    if (!node) return NULL;
    return node->father;
}

int getNodeDistance(Node *node) {
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

