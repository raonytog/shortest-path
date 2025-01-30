#ifndef _EDGE_H_
#define _EDEGE_H_

typedef struct Node Node;
#include "node.h"

typedef struct Edge Edge;

/** basics */
Edge* createEdge(Node *source, Node *destine, int weight);

void destroyEdge(Edge *e);

#endif // !_EDGE_H_
