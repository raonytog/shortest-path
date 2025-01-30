#ifndef _NODE_H_
#define _NODE_H_

typedef struct Node Node;

/** basics */
Node *createNode();

void printNode(Node *node);

void destroyNode(Node *node);

int compare(Node *n, Node *m);

/** getters */
char* getNodeName(Node *node);

Node* getNodeFather(Node *node);

int getNodeDistance(Node *node);

int* getNodeAdjList(Node *node);

/** setters */
void setNodeAdj(Node *node, int idx, int distance);

#endif // !_NODE_H_