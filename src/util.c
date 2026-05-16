#include <stdio.h>
#include <stdlib.h>
#include "../include/util.h"

void limparBuffer() {
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void pausarTela() {
    printf("\nPressione Enter para continuar...");
    getchar();
}

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}