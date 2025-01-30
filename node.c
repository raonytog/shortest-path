#include <stdlib.h>

#include "includes/node.h"

struct Node {
    char *name;
    Node *father;
    int distance;

    Edge **edges;
    int numEdges;
};

Node *createNode() {

}

void destroyNode(Node *node) {
    if (!node) return;

    free(node->name);
    for(int i = 0; i < getNumEdges(node); i++) {
        destroyEdge(node->edges[i]);
    }
}

char* getNodeName(Node *node) {
    if (!node) return;
    return node->name;
}

Node* getNodeFather(Node *node) {
    if (!node) return;
    return node->father;
}

int getNodeDistance(Node *node) {
    if (!node) return;
    return node->distance;
}

Edge** getNodeEdges(Node *node) {
    if (!node) return;
    return node->edges;
}

int getNumEdges(Node *node) {
    if (!node) return;
    return node->numEdges;
}
