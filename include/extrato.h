#ifndef EXTRATO_H
#define EXTRATO_H

#define TAM_EXTRATO 3

void registrarOperacao(char tipos[][20], float valores[], int *totalOperacoes, char tipo[], float valor);
void mostrarExtrato(char tipos[][20], float valores[], int totalOperacoes, float saldo);

#endif
