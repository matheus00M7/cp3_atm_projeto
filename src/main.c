#include <stdio.h>
#include "../include/menu.h"
#include "../include/operacoes.h"
#include "../include/extrato.h"
#include "../include/util.h"

/*
    Projeto Integrador - Sistema ATM em C

    Integrantes:
    Jun Uehara - RM: 570537
    Matheus Martins Lacerda - RM: 570843

    Arquivo principal do sistema.
    Aqui fica o loop do menu e o switch-case que chama as funcoes.
*/

int main() {
    int opcao = -1;
    float saldo = 0.0;

    char tipos[TAM_EXTRATO][20];
    float valores[TAM_EXTRATO];
    int totalOperacoes = 0;
    // Laço principal do sistema, que continua executando até o usuário escolher sair
    do {
        limparTela();
        exibirMenu();

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada invalida! Digite apenas numeros.\n");
            limparBuffer();
            pausarTela();
            continue;
        }

        limparBuffer();
        // Verifica qual opção o usuário escolheu
        switch (opcao) {
            case 1:
                consultarSaldo(saldo);
                break;

            case 2:
                saldo = realizarSaque(saldo, tipos, valores, &totalOperacoes);
                break;

            case 3:
                saldo = realizarDeposito(saldo, tipos, valores, &totalOperacoes);
                break;

            case 4:
                mostrarExtrato(tipos, valores, totalOperacoes, saldo);
                break;

            case 0:
                printf("\nEncerrando o sistema...\n");
                printf("Obrigado por usar o ATM!\n");
                break;

            default:
                printf("\nOpcao invalida! Escolha uma opcao do menu.\n");
                pausarTela();
                break;
        }

    } while (opcao != 0);

    return 0;
}