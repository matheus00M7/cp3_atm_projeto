#include <stdio.h>
#include <stdlib.h>
#include "../include/util.h"
// Função responsável por limpar o buffer do teclado
void limparBuffer() {
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
    }
}
// Função responsável por pausar a tela
void pausarTela() {
    printf("\nPressione Enter para continuar...");
    getchar();
}
// Função responsável por limpar a tela do terminal
void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}