#include <stdlib.h>

#include "node.h"

struct Node {
    char *name;
    Node *father;
    int distance;

    Edge **edges;
    int numEdges;
};

Node *createNode() {
    return NULL;
}

void destroyNode(Node *node) {
    if (!node) return;

    free(node->name);
    for(int i = 0; i < getNumEdges(node); i++) {
        destroyEdge(node->edges[i]);
    }
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

Edge** getNodeEdges(Node *node) {
    if (!node) return NULL;
    return node->edges;
}

int getNumEdges(Node *node) {
    if (!node) return 0;
    return node->numEdges;
}
