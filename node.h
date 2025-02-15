#ifndef _NODE_H_
#define _NODE_H_

typedef struct Node Node;

/** basics */

/**
 * @brief Cria um nó, dado o nome e um indice. Os demais atributos são inicializados com -1 ou null
 * @param name nome do nó
 * @param idx indice presente no nome do nó
 * @param qtdNodes quantidade total de nós para a lista de adjacencia
 * @return Nó criado
 */
Node *createNode(char *name, int idx, int qtdNodes);

/**
 * @brief Imprime o nó e as distancias
 * @param node nó
 */
void printNode(Node *node);

/**
 * @brief Libera memória do nó
 * @param node nó
 */
void destroyNode(Node *node);

/**
 * @brief Compara dois nós de uma array de nós com base nas distâncias
 * @param n nó 1
 * @param m nó 2
 * @return 1, se N > M, -1 se N < M, 0 se M = M
 */
int compareFloat(const void *n, const void *m);



/** getters */

/**
 * @brief Retorna o nome do nó
 * @param node nó
 * @return nome do nó
 */
char* getNodeName(Node *node);

/**
 * @brief Retorna o pai do nó
 * @param node nó
 * @return Pai do nó
 */
Node* getNodeFather(Node *node);

/**
 * @brief Retorna a distância do nó até o nó inicial
 * @param node nó
 * @returndistância do nó até o nó inicial
 */
float getNodeDistance(Node *node);

/**
 * @brief Retorna a lista de adijacencia do nó
 * @param node nó
 * @return lista de adijacencia do nó
 */
float* getNodeAdjList(Node *node);

/**
 * @brief Retorna o indice do nó na fila de prioridade
 * @param node nó
 * @return Caso o nó exista, retorna seu indíce na fila. Caso contrário, retorna -1
 */
int getNodePQIdx(Node *node);



/** setters */

/**
 * @brief Define o custo da aresta entre o nó passado e o nó do indice passado
 * @param node nó source
 * @param idx nó target
 * @param distance distância entre node e idx
 */
void setNodeAdj(Node *node, int idx, float distance);

/**
 * @brief Define father como pai do node
 * @param node nó
 * @param father pai do nó
 */
void setNodeFather(Node *node, Node *father);

/**
 * @brief Define a distância do nó origem até o node passado
 * @param node nó
 * @param distance distância do nó origem até o node
 */
void setNodeDistance(Node *node, float distance);

/**
 * @brief Define o indice do nó na fila
 * @param node nó
 * @param idx indice do nó na fila de prioridade
 */
void setNodePQIdx(Node *node, int idx);

#endif // !_NODE_H_