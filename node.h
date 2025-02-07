#ifndef _NODE_H_
#define _NODE_H_

typedef struct Node Node;

/** basics */
Node *createNode(char *name, int idx, int qtdNodes);

void printNode(Node *node);

void destroyNode(Node *node);

int compare(Node *n, Node *m);

/** getters */
char* getNodeName(Node *node);

Node* getNodeFather(Node *node);

int getNodeDistance(Node *node);

float* getNodeAdjList(Node *node);

/** setters */
void setNodeAdj(Node *node, int idx, float distance);

void setNodeFather(Node *node, Node *father);

void setNodeDistance(Node *node, float distance);

#endif // !_NODE_H_