/**
 * T1 TBO, professor: Luis Antonio de Souza Junior
 * Alunos:
 *      Barbara - 2023100254
 *      Raony - 2023102512
 */

#include <stdio.h>

#include "list.h"
#include "node.h"

/**
 * @brief Encontra o caminho mínimo a partir do nó inicial para todos os outros nós
 * utilizando uma lista ordenada
 * @param nodes array de nodes
 * @param numNodes Quantidade de nós existentes
 * @param sourceIdx indice do nó inicial
 */
void djikstra(Node **nodes, int numNodes, int sourceIdx) {
    if (!nodes || numNodes <= 0 || (sourceIdx < 0 || sourceIdx >= numNodes)) return;

    List *list = createLista();
    for (int i = 0; i < numNodes; i++) {
        insertNode(list, nodes[i]);
    }

    setNodeDistance(nodes[sourceIdx], 0);
    while (getListSize(list) > 0) {
        Node *removido = popNode(list);

        float *adj = getNodeAdjList(removido);
        for (int i = 0; i < numNodes; i++) {
            if (adj[i] <= 0) continue;

            float peso = adj[i];

            if (getNodeDistance(removido) + peso < getNodeDistance(nodes[i])) {
                setNodeDistance(nodes[i], getNodeDistance(removido) + peso);
                setNodeFather(nodes[i], removido);

                decreaseKeyList(list, nodes[i]);
            }
        }
    }

    destroyList(list);
}