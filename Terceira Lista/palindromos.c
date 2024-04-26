#include<stdio.h>
#include<math.h>

/*
 Elabore uma função que retorne 1 caso o
 número inteiro passado
 como parâmetro é palíndromo.
 Caso o número
 passado como parâmetro seja 0, negativo ou não ser
 palíndromo, deve ser retornado 0.

 Utilizar -lm na compilação do código por conta de math.h
*/

#define True 1
#define False 0

int eh_palindromo(short int);
int inverter_numero(short int);
int tamanho_posicoes_numero(short int);

int main(void) {
    short int numberCheck;
    printf("Informe um inteiro: ");
    scanf("%hd", &numberCheck);

    printf("Retorno da função: %d\n", eh_palindromo(numberCheck));

    return 0;
}

int eh_palindromo(short int valor) {
    // Minha ideia é "decompor o número" e depois compor ele novamente com ordem inversa
    // Se ordem inversa é igual a original, ele é palindromo
    if ((valor == inverter_numero(valor)) && (valor > 0)) {
        return True;
    }
    return False;
}

int inverter_numero(short int valor) {
    short int inverso = 0;
    int ultimo_digito, posicao_digito = 0, posicoes_disponiveis = tamanho_posicoes_numero(valor);

    while (valor != 0) {
        ultimo_digito = valor % 10;
        // Quem está no final vai para o início com "posicoes_disponiveis - posicao_digito"
        inverso += ultimo_digito * pow(10, (posicoes_disponiveis - posicao_digito));
        valor /= 10;
        posicao_digito++;
    }

    return inverso;
}

int tamanho_posicoes_numero(short int valor) {
    int count = -1; // 0 será para unidades, 1 será para dezenas...
    // Pois 10^0 -> unidades, 10^1 -> dezenas...

    while (valor != 0) {
        valor /= 10;
        count++;
    }

    return count;
}