#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "PQ.h"

#define exch(A, B) { Node *t = A; A = B; B = t; } /* troca os valores de A e B*/
#define compexch(A, B) if (less(B, A)) exch(A, B) /* se B for menor que A, troca os valores */

static void pqPrint(PQ *pq);
static int pqMaxSize(PQ *pq);
static void fix_up(PQ *pq, int N);
static void fix_down(PQ *pq, int size, int N);

struct pq {
    Node **array;
    int max_size;
    int current_size;
};

PQ* pqCreate(int max_N) {
    if (max_N <= 0) return NULL;

    PQ *queue = malloc(sizeof(PQ));
    queue->max_size = max_N + 1;
    queue->current_size = 0;
    queue->array = malloc((max_N + 1) * sizeof(Node*));

    return queue;
}

void pqDestroy(PQ *pq) {
    if (!pq) return;

    for (int i = 0; i < pqSize(pq); i++) { free(pq->array[i]); }
    free(pq->array);
    free(pq);
}

void pqInsert(PQ *pq, Node *e) {
    if (!pq || !e) return;
    if (pqSize(pq) == pqMaxSize(pq)) { printf("PQ is full\n"); return; }

    pq->current_size++;
    pq->array[pq->current_size] = e;
    setNodePQIdx(e, pq->current_size);

    fix_up(pq, pqSize(pq));
}

Node* pqDelmin(PQ *pq) {
    if (!pq || pqSize(pq) == 0) { 
        printf("PQ does not exist or pq size is 0!\n"); 
        return NULL; 
    }

    Node *min = pq->array[1];
    setNodePQIdx(min, -1);
    exch(pq->array[pqSize(pq)], pq->array[1]);
    setNodePQIdx(pq->array[1], 1);

    pq->current_size--;

    fix_down(pq, pqSize(pq), 1);
    
    return min;
}

bool pqIsEmpty(PQ *pq) {
    if (!pq) return false;
    return pq->current_size == 0;
}

int pqSize(PQ *pq) {
    if (!pq) return 0;
    return pq->current_size;
}

/** 
 * Retorna o limite máximo possível da fila 
 */
static int pqMaxSize(PQ *pq) { 
    if (!pq) return 0;
    return pq->max_size;
}

/** 
 * Compara a distancia entre dois nós
 */
static int cmp(Node *a, Node *b) {
    float numA = getNodeDistance(a), numB = getNodeDistance(b);
    if (numA > numB) return 1;
    else if (numA < numB) return -1;
    else return 0;
}

/** 
 * Arruma a heap order, empurrando os nós com maior prioridade para cima
 */
static void fix_up(PQ *pq, int N) {
    if (!pq || N <= 0) return;

    while (N > 1 && cmp(pq->array[N/2], pq->array[N]) > 0) {
        exch(pq->array[N], pq->array[N/2]);

        setNodePQIdx(pq->array[N/2], N/2);
        setNodePQIdx(pq->array[N], N);

        N = N/2;
    }
}

/** 
 * Arruma a heap order, empurrando os nós com menor prioridade para baixo
 */
static void fix_down(PQ *pq, int size, int N) {
    if (!pq || size <= 0 || N <= 0) return;

    int i = 0;
    while (2*N <= size) {
        i = 2*N;
        if (i < size && cmp(pq->array[i+1], pq->array[i]) < 0)
            i++;

        if (cmp(pq->array[N], pq->array[i]) > 0) { exch(pq->array[N], pq->array[i]); }
        else break;

        setNodePQIdx(pq->array[N], N);
        setNodePQIdx(pq->array[i], i);

        N = i;
    }
}

void decreaseKey(PQ *pq, int idx_heap) {
    if (!pq || idx_heap <= 0 || idx_heap > pqSize(pq)) {
        printf("PQ does not exist or i is out of bounds!\n");
        return;
    }

    fix_up(pq, idx_heap);
}

/** 
 * Imprime todo o conteudo da fila de prioridade
*/
static void pqPrint(PQ *pq) {
    if (!pq) return;

    for(int i = 1; i < pq->current_size+1; i++) {
        printNode(pq->array[i]);
    }
}