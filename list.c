#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct cell {
    Node *data;
    struct cell *next;
};

struct list {
    Cell *head;
    Cell *tail;
    int size;
};

List *createLista() {
    List *list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void insertNode(List *list, Node *node) {
    if (!list || !node) return;

    Cell *new_cell = malloc(sizeof(Cell));
    new_cell->data = node;
    new_cell->next = NULL;

    if (list->size == 0) {
        list->head = new_cell;
        list->tail = new_cell;
    } else {
        Cell *aux = list->head;
        Cell *prev = NULL;

        while (aux != NULL && getNodeDistance(aux->data) <= getNodeDistance(node)) {
            prev = aux;
            aux = aux->next;
        }

        // Insere no final
        if (aux == NULL) {
            list->tail->next = new_cell;
            list->tail = new_cell;

        } else {
             // Insere no início
            if (aux == list->head) {
                new_cell->next = list->head;
                list->head = new_cell;

            // Insere no meio
            } else {
                prev->next = new_cell;
                new_cell->next = aux;
            }
        }
    }

    list->size++;
}

Node* removeNode(List *list, Node *node) {
    if (!list || !node) return NULL;

    Cell *aux = list->head;
    Cell *prev = NULL;

    while (aux != NULL && aux->data != node) {
        prev = aux;
        aux = aux->next;
    }

    if (aux == NULL) return NULL;

    if (prev == NULL) { list->head = aux->next;
    } else { prev->next = aux->next; }

    if (aux == list->tail) { list->tail = prev; }

    list->size--;
    Node *data = aux->data;
    free(aux);

    return data;
}

Node* popNode(List *list) {
    if (!list || list->size == 0) return NULL;

    Cell *aux = list->head;
    Node *node = aux->data;

    list->head = aux->next;
    free(aux);

    list->size--;

    return node;
}

void destroyList(List *list) {
    if (!list) return;

    Cell *aux = list->head;
    while (aux != NULL) {
        Cell *next = aux->next;
        free(aux);
        aux = next;
    }

    free(list);
}

void decreaseKeyList(List *list, Node *node) {
    if (!list || !node) return;

    Cell *aux = list->head;
    while (aux != NULL && aux->data != node) {
        aux = aux->next;
    }

    removeNode(list, node);
    insertNode(list, node);
}

int getListSize(List *list) {
    if (!list) return 0;

    return list->size;
}

void printList(List *list) {
    if (!list) return;

    Cell *aux = list->head;
    while (aux != NULL) {
        printf("%s %f\n", getNodeName(aux->data), getNodeDistance(aux->data));
        aux = aux->next;
    }
}