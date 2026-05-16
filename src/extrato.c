#include <stdio.h>
#include "../include/extrato.h"
#include "../include/util.h"

/* Copia uma string para outra */
void copiarTexto(char destino[], char origem[]) {
    int i = 0;

    while (origem[i] != '\0') {
        destino[i] = origem[i];
        i++;
    }

    destino[i] = '\0';
}

/* Registra uma nova operacao no extrato */
void registrarOperacao(char tipos[][20], float valores[], int *totalOperacoes, char tipo[], float valor) {
    int i;

    if (*totalOperacoes < TAM_EXTRATO) {
        copiarTexto(tipos[*totalOperacoes], tipo);
        valores[*totalOperacoes] = valor;
        (*totalOperacoes)++;
    } else {
        /* Se o extrato estiver cheio, remove a operacao mais antiga */
        for (i = 0; i < TAM_EXTRATO - 1; i++) {
            copiarTexto(tipos[i], tipos[i + 1]);
            valores[i] = valores[i + 1];
        }

        copiarTexto(tipos[TAM_EXTRATO - 1], tipo);
        valores[TAM_EXTRATO - 1] = valor;
    }
}

/* Exibe todas as operacoes registradas */
void mostrarExtrato(char tipos[][20], float valores[], int totalOperacoes, float saldo) {
    int i;

    printf("\n------------- EXTRATO ---------------\n");
    /* Verifica se existem operacoes registradas */
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