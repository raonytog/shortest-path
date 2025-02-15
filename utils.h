#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/**
 * @brief Verifica se existem argumentos. Caso não existam, 
 * o programa é encerrado. Do contrário, segue execução normalmente
 * @param argc contagem de argumentos
 */
void verifyArgc(int argc);

/**
 * @brief Le e armazena o indice e o nome do no inicial
 * @param input Arquivo contendo a informação de nó inicial
 * @param sourceName Nome do nó incial a preencher na leitura
 * @param source_idx Indíce do nó inicial a preencher na leitura
 */
void readSourceName(FILE *input, char *sourceName, int *source_idx);

/**
 * @brief Le uma linha para analisar quantos nós existem no grafo
 * @param input Arquivo contendo os nós
 * @return O número de nós 
 */
int readNumNodes(FILE *input);

/**
 * @brief Cria cada node existente no arquivo de input
 * @param input Arquivo contendo os nós
 * @param qtdNode Quantidade de nós existentes
 * @return Array de nodes
 */
Node **readNodes(FILE *input, int qtdNode);

/**
 * @brief Destroi todos os nós
 * @param nodes array de nodes
 * @param numNodes Quantidade de nós existentes
 */
void destroyNodes(Node **nodes, int numNodes);

/**
 * @brief Imprime todos os nós
 * @param nodes array de nodes
 * @param numNodes Quantidade de nós existentes
 */
void printNodes(Node **nodes, int numNodes);

/**
 * @brief Encontra o caminho mínimo a partir do nó inicial para todos os outros nós
 * utilizando uma min heap
 * @param nodes array de nodes
 * @param numNodes Quantidade de nós existentes
 * @param sourceIdx indice do nó inicial
 */
void dijkstraPQ(Node **nodes, int numNodes, int sourceIdx);

/**
 * @brief Encontra o caminho mínimo a partir do nó inicial para todos os outros nós
 * utulizando <??????>
 * @param nodes array de nodes
 * @param numNodes Quantidade de nós existentes
 * @param sourceIdx indice do nó inicial
 */
void dijkstraLL(Node **nodes, int numNodes, int sourceIdx);

/**
 * @brief Imprime o caminho mínimo de todos os nós no terminal
 * @param nodes array de nodes
 * @param numNodes Quantidade de nós existentes
 */
void printDijkstraPath(Node **nodes, int numNodes);

/**
 * @brief Imprime o caminho mínimo de todos os nós no arquivo gerado pelo path
 * @param nodes array de nodes
 * @param numNodes Quantidade de nós existentes
 * @param path caminho para criacao do arquivo
 */
void printDijkstraPathFile(Node **nodes, int numNodes, char *path);

#endif