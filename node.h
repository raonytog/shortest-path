#ifndef _NODE_H_
#define _NODE_H_

#include "edge.h"

typedef struct Node Node;

/** basics */
Node *createNode();

void destroyNode(Node *node);

int compare(Node *n, Node *m);

/** getters */
char* getNodeName(Node *node);

Node* getNodeFather(Node *node);

int getNodeDistance(Node *node);

Edge** getNodeEdges(Node *node);

int getNumEdges(Node *node);

#endif // !_NODE_H_