#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

void verifyArgc(int argc);
void readSourceName(FILE *entrada, char *s);
int readNumNodes(FILE *entrada);

int main(int argc, char const *argv[]) {
    // verifyArgc(argc);
    // char path[100];
    // strcpy(path, argv[1]);

    char path[100] = "casos_teste_v3/caso_teste_muito_pequeno_1.txt";
    FILE *entrada = NULL;
    entrada = fopen(path, "r");

    /** source */
    char source_name[100];
    readSourceName(entrada, source_name);
    printf("\n\nsource: %s\n", source_name);

    int numNodes = readNumNodes(entrada);
    printf("num = %d\n", numNodes);

    fclose(entrada);

    return 0;
}

void verifyArgc(int argc) { 
    if (argc > 1) return;
    printf("ERRO: diretorio de arquivos nao informado\n");
    exit(1);
}

void readSourceName(FILE *entrada, char *s) {
    if (!entrada) return;
    fscanf(entrada, "%[^\n]%*c", s);
}

int readNumNodes(FILE *entrada) {
    if (!entrada) return -1;

    int count = 0;
    char buffer[1023];

    while (fscanf(entrada, "%[^\n]%*c", &buffer) == 1) {
        count++;
    }

    return count;
}