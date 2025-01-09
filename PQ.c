#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "PQ.h"

#define exch(A, B) { Event *t = A; A = B; B = t; } /* troca os valores de A e B*/
#define compexch(A, B) if (less(B, A)) exch(A, B) /* se B for menor que A, troca os valores */

static int PQ_max_size(PQ *pq);
static void fix_up(PQ *pq, int N);
static void fix_down(PQ *pq, int size, int N);

// TODO: Aqui você deve implementar uma fila com prioridade mínima para
//       ordenar os eventos por tempo, isto é, o evento com o menor tempo tem
//       a maior prioridade. Veja as funções definidas em 'event.h' para
//       a manipulação das estruturas de evento. A princípio, as funções já
//       existentes em 'event.h' são suficientes para implementar a simulação,
//       isto é, você não precisa implementar mais nada lá.
//
//       Você é livre para implementar a fila com prioridade da forma que quiser
//       mas é recomendado usar um min-heap para obter um bom desempenho. As
//       simulações maiores geram uma quantidade grande de eventos: um
//       limite superior frouxo (mas seguro) para o número máximo simultâneo de
//       eventos é N^3, aonde N é o número de partículas.

// TODO: Crie a struct pq.
struct pq {
    Event **array;
    int max_size;
    int current_size;
};

/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado
 *   // TODO: Implemente a criação da fila que suporta no máximo o número de
 *   //       de eventos informados no parâmetro.
 */
PQ* PQ_create(int max_N) {
    if (max_N <= 0) return NULL;

    PQ *queue = malloc(sizeof(PQ));
    queue->max_size = max_N;
    queue->current_size = 0;
    queue->array = malloc(max_N * sizeof(Event**));

    return queue;
}

/*
 * Libera a memória da fila.
 *
 *  // TODO: Implemente essa função que libera toda a memória da fila,
 *  //       destruindo inclusive os eventos que estavam na fila.
 */
void PQ_destroy(PQ *pq) {
    if (!pq) return;

    for (int i = 0; i < PQ_size(pq); i++) { free(pq->array[i]); }
    free(pq->array);
    free(pq);
}

/*
 * Insere o evento na fila segundo o seu tempo.
 *
 *   // TODO: Implemente essa função que insere o evento dado na fila segundo
 *   //       o tempo do evento.
 *   //       Assuma que 'e' não é nulo. É importante testar overflow (inserção
 *   //       em uma fila que já contém o número máximo de eventos) para evitar
 *   //       dores de cabeça com acessos inválidos na memória.
 */
void PQ_insert(PQ *pq, Event *e) {
    if (!pq || !e) return;
    if (PQ_size(pq) == PQ_max_size(pq)) { printf("PQ is full\n"); return; }

    pq->current_size++;
    pq->array[pq->current_size] = e;
    fix_up(pq, PQ_size(pq));
}

/*
 * Remove e retorna o evento mais próximo.
 *   // TODO: Implemente essa função que remove o evento com o menor tempo da   
 *   //       fila e o retorna.
 */
Event* PQ_delmin(PQ *pq) {
    if (!pq || PQ_size(pq) == 0) { 
        printf("PQ does not exist or pq size is 0!\n"); 
        return NULL; 
    }

    Event *min = pq->array[1];
    exch(pq->array[PQ_size(pq)], pq->array[1]);
    pq->current_size--;

    fix_down(pq, PQ_size(pq), 1);

    return min;
}

/*
 * Testa se a fila está vazia.
 */
bool PQ_is_empty(PQ *pq) {
    if (!pq) return false;
    return pq->current_size == 0;
}

/*
 * Retorna o tamanho da fila.
 */
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
        N = i;
    }
}
