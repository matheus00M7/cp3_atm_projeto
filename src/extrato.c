#include <stdio.h>
#include "../include/extrato.h"
#include "../include/util.h"

/*
    Arquivo responsavel pelo registro e exibicao do extrato.
    O sistema guarda apenas as ultimas 3 operacoes.
*/

void copiarTexto(char destino[], char origem[]) {
    int i = 0;

    while (origem[i] != '\0') {
        destino[i] = origem[i];
        i++;
    }

    destino[i] = '\0';
}

void registrarOperacao(char tipos[][20], float valores[], int *totalOperacoes, char tipo[], float valor) {
    int i;

    if (*totalOperacoes < TAM_EXTRATO) {
        copiarTexto(tipos[*totalOperacoes], tipo);
        valores[*totalOperacoes] = valor;
        (*totalOperacoes)++;
    } else {
        for (i = 0; i < TAM_EXTRATO - 1; i++) {
            copiarTexto(tipos[i], tipos[i + 1]);
            valores[i] = valores[i + 1];
        }

        copiarTexto(tipos[TAM_EXTRATO - 1], tipo);
        valores[TAM_EXTRATO - 1] = valor;
    }
}

void mostrarExtrato(char tipos[][20], float valores[], int totalOperacoes, float saldo) {
    int i;

    printf("\n------------- EXTRATO ---------------\n");

    if (totalOperacoes == 0) {
        printf("Nenhuma operacao realizada ainda.\n");
    } else {
        printf("Ultimas operacoes:\n\n");

        for (i = 0; i < totalOperacoes; i++) {
            printf("%d - %s: R$ %.2f\n", i + 1, tipos[i], valores[i]);
        }
    }

    printf("\nSaldo final: R$ %.2f\n", saldo);
    printf("-------------------------------------\n");

    pausarTela();
}