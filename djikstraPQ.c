#include <stdio.h>

#include "PQ.h"
#include "node.h"

/**
 * @brief Encontra o caminho mínimo a partir do nó inicial para todos os outros nós
 * utilizando uma min heap
 * @param nodes array de nodes
 * @param numNodes Quantidade de nós existentes
 * @param sourceIdx indice do nó inicial
 */
void djikstra(Node **nodes, int numNodes, int sourceIdx) {
    if (!nodes || numNodes <= 0 || (sourceIdx < 0 || sourceIdx >= numNodes)) return;

    printf("Running djikstra with priory queue!\n");
    setNodeDistance(nodes[sourceIdx], 0);
    PQ *queue = pqCreate(numNodes);
    for (int i = 0; i < numNodes; i++)
        pqInsert(queue, nodes[i]);

    while (!pqIsEmpty(queue)) {
        Node *removido = pqDelmin(queue);

        float *adj = getNodeAdjList(removido);
        for (int i = 0; i < numNodes; i++) {
            if (adj[i] <= 0 || getNodePQIdx(nodes[i]) < 0) continue;

            float peso = adj[i];

            if (getNodeDistance(removido) + peso < getNodeDistance(nodes[i])) {
                setNodeDistance(nodes[i], getNodeDistance(removido) + peso);
                setNodeFather(nodes[i], removido);

                decreaseKey(queue, getNodePQIdx(nodes[i]));
            }
        }
    }

    pqDestroy(queue);
}