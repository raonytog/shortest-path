#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

void verifyArgc(int argc);
void readSourceName(FILE *entrada, char *s);

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

    return 0;
}

void verifyArgc(int argc) { 
    if (argc > 1) return;
    printf("ERRO: diretorio de arquivos nao informado\n");
    exit(1);
}

void readSourceName(FILE *entrada, char *s) {
    fscanf(entrada, "%s", s);
}
