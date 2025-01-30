#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "node.h"

struct Node {
    char *name;
    int idx;

    Node *father;
    int distance;

    int *adj;
    int adjSize;
};

Node *createNode(char *name, int idx, int qtdNodes) {
    if (!name || idx < 0) return NULL;

    Node *new = malloc(sizeof(Node));
    new->name = strdup(name);
    new->idx = idx;
    new->adj = malloc(qtdNodes * sizeof(int));
    new->adjSize = qtdNodes;

    return new;
}

void printNode(Node *node) {
    if (!node) return;
    printf("%s:", getNodeName(node));
    for (int i = 0; i < node->adjSize; i++) {
        if (i == node->idx) printf(" 0");
        else { printf(" %d", node->adj[i]); }
    }
    printf("\n");
}

void destroyNode(Node *node) {
    if (!node) return;

    free(node->name);
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

int* getNodeAdjList(Node *node) {
    if (!node) return 0;
    else return node->adj;
}

void setNodeAdj(Node *node, int idx, int distance) {
    if (!node || idx < 0 || distance < 0) return;
    node->adj[idx] = distance;
}



