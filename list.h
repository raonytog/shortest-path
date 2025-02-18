#include "node.h"

typedef struct cell Cell;

typedef struct list List;

List *createLista();

void insertNode(List *list, Node *node);

Node* popNode(List *list);

void destroyList(List *list);

void decreaseKeyList(List *list, Node *node);

int getListSize(List *list);

void printList(List *list);