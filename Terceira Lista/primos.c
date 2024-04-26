#include<stdio.h>
/*
 Escreva uma rotina que receba como parâmetro uma quantidade
 de números a serem inseridos e que depois peça para que
 sejam digitados cada um desses números inteiros e positivos.
 Ao final, deve ser mostrado quantos desses números são primos.

  Versão do gcc usado para esse e as demais questões da lista:
 gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0

*/

// Definição para trabalhar com True e False
#define False 0
#define True 1


int eh_primo(short int);

int main(void) {
    short int nNumber;
    printf("Quantos números serão digitados? ");
    scanf("%hd", &nNumber);

    while (nNumber <= 0) {
        printf("Quantidade inválida, tente novamente: ");
        scanf("%hd", &nNumber);
    }

    short int numberToCheck, countPrimo = 0, positionNumber = 1;

    // Leitura dos números pela quantidade que o usuário informou - daria para fazer com arrays, mas preferi dessa vez usar laços.
    while (nNumber > 0) {
        printf("Insira %hd# número: ", positionNumber); // e.g. Informe o 1# número...
        scanf("%hd", &numberToCheck);

        while (numberToCheck <= 0) {
            printf("Somente números positivos!\n");
            printf("Insira #%hd número: ", positionNumber);
            scanf("%hd", &numberToCheck);
        }

        if (eh_primo(numberToCheck)) {
            countPrimo++;
        }

        positionNumber++;
        nNumber--;
    }

    printf("Quantidade de inteiros primos informados: %hd\n", countPrimo);

    return 0;
}

int eh_primo(short int valor) {
    int i;

    // Começaremos com o primeiro primo (2), e vamos até a metade desse número, onde caso ele for divísivel pela sua metade, o resultado seria 2 (menor primo).
    // Não vale a pena analisar casos onde i > valor / 2, pois se ele não for divisível pela sua metade, ele só poderá ser divisível somente por ele mesmo.
    for (i = 2; i <= valor / 2; i++) {
        // Se for divisível por algum valor de i (i != valor), ou valor = 1, ele não será primo. Exclui o 0 pois main requer um número positivo, e 0 não é positivo.
        if ((valor % i == 0) || valor == 1) {
            return False;
        }
    }
    return True;
}
