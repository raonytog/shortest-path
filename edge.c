#include <stdlib.h>

#include "edge.h"

struct Edge {
    Node* source, *destine;
    int weight;
};

Edge* createEdge(Node *source, Node *destine, int weight) {
    if (!source || !destine || weight < 0) return NULL;

    Edge *new = malloc(sizeof(Edge));
    new->source = source;
    new->destine = destine;
    new->weight = weight;

    return new;
}

void destroyEdge(Edge *e) {
    if (!e) return;
    free(e);
}