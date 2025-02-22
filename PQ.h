#ifndef PQ_H
#define PQ_H

#include "node.h"
#include <stdbool.h>

typedef struct pq PQ;

 /**
 * @brief Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 * @param max_N número máximo de elementos da fila
 * @return fila de prioridade mínima
 */
PQ* pqCreate(int max_N);

 /**
 * @brief Libera a memória da fila.
 * @param pq fila de prioridade mínima
 */
void pqDestroy(PQ *pq);

 /**
 * @brief Insere o evento na fila segundo a distância do nó inicial
 * @param pq fila de prioridade mínima
 * @param e node à inserir
 */
void pqInsert(PQ *pq, Node *e);

/**
 * @brief Remove e retorna o evento mais próximo
 * @param pq fila de prioridade mínima
 * @return node removido com a maior prioridade
 */
Node* pqDelmin(PQ *pq);

/**
 * @brief Testa se a fila está vazia.
 * @param pq fila de prioridade mínima
 * @return True se a fila estiver vazia, False se tiver pelo menos um item.
 */
bool pqIsEmpty(PQ *pq);

/**
 * @brief Retorna o tamanho da fila.
 * @param pq fila de prioridade mínima
 * @return tamanho atual da fila
 */
int pqSize(PQ *pq);

 /**
 * @brief Função auxiliar para diminuir a chave de um elemento na fila.
 * @param pq fila de prioridade mínima
 * @param idx_heap indice do nó na fila
 */
void decreaseKey(PQ *pq, int idx_heap);

#endif
