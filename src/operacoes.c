#include <stdio.h>
#include "../include/operacoes.h"
#include "../include/extrato.h"
#include "../include/util.h"

#define LIMITE_SAQUE 1000.00

void consultarSaldo(float saldo) {
    printf("\nSaldo atual: R$ %.2f\n", saldo);
    pausarTela();
}

float realizarDeposito(float saldo, char tipos[][20], float valores[], int *totalOperacoes) {
    float valor;

    printf("\nDigite o valor do deposito: R$ ");

    if (scanf("%f", &valor) != 1) {
        printf("\nValor invalido.\n");
        limparBuffer();
        pausarTela();
        return saldo;
    }

    limparBuffer();

    if (valor <= 0) {
        printf("\nO deposito precisa ser maior que zero.\n");
        pausarTela();
        return saldo;
    }

    saldo = saldo + valor;

    registrarOperacao(tipos, valores, totalOperacoes, "Deposito", valor);

    printf("\nDeposito feito com sucesso.\n");
    printf("Saldo atual: R$ %.2f\n", saldo);

    pausarTela();
    return saldo;
}

float realizarSaque(float saldo, char tipos[][20], float valores[], int *totalOperacoes) {
    float valor;

    printf("\nDigite o valor do saque: R$ ");

    if (scanf("%f", &valor) != 1) {
        printf("\nValor invalido.\n");
        limparBuffer();
        pausarTela();
        return saldo;
    }

    limparBuffer();

    if (valor <= 0) {
        printf("\nO saque precisa ser maior que zero.\n");
    } else if (valor > LIMITE_SAQUE) {
        printf("\nO limite por saque e de R$ %.2f.\n", LIMITE_SAQUE);
    } else if (valor > saldo) {
        printf("\nSaldo insuficiente.\n");
    } else {
        saldo = saldo - valor;

        registrarOperacao(tipos, valores, totalOperacoes, "Saque", valor);

        printf("\nSaque feito com sucesso.\n");
        printf("Saldo atual: R$ %.2f\n", saldo);
    }

    pausarTela();
    return saldo;
}