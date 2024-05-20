#include <stdio.h>
#include <stdbool.h>

bool verificarDia(int dia, int mes, int c[]) {
    int qtdsDiasNoMes = c[mes - 1]; // Pega a quantidade de dias daquele mês.

    if ((dia >= 1) && (dia <= qtdsDiasNoMes)) {
        return true;
    }
    return false;
}

bool verificarMes(int mes) {
    if ((mes >= 1) && (mes <= 12)) {
        return true;
    }
    return false;
}

bool verificarAno(int ano) {
    if (ano > 0) {
        return true;
    }
    return false;
}

int main()
{
    int dia, mes, ano;

    int calendario[12];

    // Irei criar um calendário, onde 0 = Janeiro, 1 = Fev e ..., cada índice terá um elemento (inteiro) indicando quantos
    // dias tem aquele mês.
    for (int i = 0; i < 12; i++) {
        if (i % 2 == 0) {
            calendario[i] = 31;
        } else {
            calendario[i] = 30;
        }
    }

    printf("[*] Por favor, informe o dia (DD): ");

    scanf("%d", &dia);

    printf("[*] Por favor, informe o mês (MM): ");

    scanf("%d", &mes);

    printf("[*] Por favor, informe o mês (AAAA): ");

    scanf("%d", &ano);

    calendario[1] = 28;

    // Caso o ano seja divisível por quatro é um ano bissexto e, portanto, o dia 29 de fevereiro é uma data válida.
    if (ano % 4 == 0) {
        calendario[1] = 29;
    }

    if ((verificarDia(dia, mes, calendario)) && (verificarMes(mes)) && (verificarAno(ano))) {
        printf("Parabéns! A sua data %d/%d/%d é válida! \n", dia, mes, ano);
    } else {
        printf("Oops! A sua data %d/%d/%d é inválida! \n", dia, mes, ano);
    }

    return 0;
}
