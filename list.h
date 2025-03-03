#include "node.h"

typedef struct cell Cell;
typedef struct list List;

/**
 * @brief Cria uma lista encadeada vazia
 * @return Lista encadeada vazia
 */
List *createLista();

/**
 * @brief Insere um nó na lista de forma ordenada
 * @param list lista encadeada
 * @parma node nó a inserir
 */
void insertNode(List *list, Node *node);

/**
 * @brief Remove o nó do começo da lista
 * @param list lista encadeada
 * @return Nó removido da lista
 */
Node* popNode(List *list);

/**
 * @brief Libera toda a memória alocada para a lista
 * @param list lista encadeada
 */
void destroyList(List *list);

/**
 * @brief Reajusta a prioridade de dado nó na lista encadeada
 * @param list lista encadeada
 * @param node nó a ter a prioridade ajustada
 */
void decreaseKeyList(List *list, Node *node);

/**
 * @brief Retorna o tamanho da lista
 * @param list lista encadeada
 * @return tamanho da lista
 */
int getListSize(List *list);

/**
 * @brief Imprime todo o conteúdo da lista
 * @param list lists encadeada
 */
void printList(List *list);