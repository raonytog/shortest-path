#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void verifyArgc(int argc);
void readSourceName(FILE *input, char *s);
int readNumNodes(FILE *input);
Node **readNodes(FILE *input, int qtdNode);

#endif