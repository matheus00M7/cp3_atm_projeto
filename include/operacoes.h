#ifndef OPERACOES_H
#define OPERACOES_H

void consultarSaldo(float saldo);
float realizarDeposito(float saldo, char tipos[][20], float valores[], int *totalOperacoes);
float realizarSaque(float saldo, char tipos[][20], float valores[], int *totalOperacoes);

#endif
