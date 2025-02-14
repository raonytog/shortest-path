#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"

#define exch(A, B) { Node *t = A; A = B; B = t; } /* troca os valores de A e B*/
#define compexch(A, B) if (less(B, A)) exch(A, B) /* se B for menor que A, troca os valores */

static int PQ_max_size(PQ *pq);
static void fix_up(PQ *pq, int N);
static void fix_down(PQ *pq, int size, int N);

struct pq {
    Node **array;
    int max_size;
    int current_size;
};

PQ* PQ_create(int max_N) {
    if (max_N <= 0) return NULL;

    PQ *queue = malloc(sizeof(PQ));
    queue->max_size = max_N + 1;
    queue->current_size = 0;
    queue->array = malloc((max_N + 1) * sizeof(Node**));

    return queue;
}

void PQ_destroy(PQ *pq) {
    if (!pq) return;

    for (int i = 0; i < PQ_size(pq); i++) { free(pq->array[i]); }
    free(pq->array);
    free(pq);
}

void PQ_insert(PQ *pq, Node *e) {
    if (!pq || !e) return;
    if (PQ_size(pq) == PQ_max_size(pq)) { printf("PQ is full\n"); return; }

    pq->current_size++;
    pq->array[pq->current_size] = e;
    setNodePQIdx(e, pq->current_size);
    fix_up(pq, PQ_size(pq));
}

Node* PQ_delmin(PQ *pq) {
    if (!pq || PQ_size(pq) == 0) { 
        printf("PQ does not exist or pq size is 0!\n"); 
        return NULL; 
    }

    Node *min = pq->array[1];
    setNodePQIdx(min, PQ_size(pq));
    exch(pq->array[PQ_size(pq)], pq->array[1]);
    setNodePQIdx(pq->array[1], 1);

    pq->current_size--;

    fix_down(pq, PQ_size(pq), 1);
    
    return min;
}

bool PQ_is_empty(PQ *pq) {
    if (!pq) return false;
    return pq->current_size == 0;
}

int PQ_size(PQ *pq) {
    if (!pq) return 0;
    return pq->current_size;
}

static int PQ_max_size(PQ *pq) { 
    if (!pq) return 0;
    return pq->max_size;
}

static void fix_up(PQ *pq, int N) {
    if (!pq || N <= 0) return;

    while (N > 1 && compare(pq->array[N/2], pq->array[N]) > 0) {
        exch(pq->array[N], pq->array[N/2]);

        setNodePQIdx(pq->array[N/2], N/2);
        setNodePQIdx(pq->array[N], N);

        N = N/2;
    }
}

static void fix_down(PQ *pq, int size, int N) {
    if (!pq || size <= 0 || N <= 0) return;

    int i = 0;
    while (2*N <= size) {
        i = 2*N;
        if (i < size && compare(pq->array[i], pq->array[i+1]) > 0)
            i++;

        if (compare(pq->array[N], pq->array[i]) <= 0) 
            break;

        exch(pq->array[N], pq->array[i]);

        setNodePQIdx(pq->array[N], N);
        setNodePQIdx(pq->array[i], i);

        N = i;
    }
}

void decrease_key(PQ *pq, int i, float new_distance) {
    if (!pq || i <= 0) {
    // if (!pq || i <= 0 || i > PQ_size(pq)) {
        printf("PQ does not exist or i is out of bounds!\n");
        return;
    }

    printf(" %s\n", getNodeName(pq->array[i]));

    //setNodeDistance(pq->array[i], new_distance);

    fix_up(pq, i);
}
