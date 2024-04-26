#include<stdio.h>

/*
 Apresente um rotina que dados os seguintes parâmetros: (1) um número inteiro positivo e maior
 que zero e (2) um número inteiro de um único dígito. Essa rotina deve mostrar quantas vezes
 uma repetição de dois números iguais ao segundo parâmetro aparece na sequência de dígitos do
 primeiro parâmetos. Exemplos:



a. caso o número seja (parâmetro 1) 344 e o segundo parâmetro seja o número 4 deve
 ser retornado o valor 1.

b. caso o número seja (parâmetro 1) 3444 e o segundo parâmetro seja o número 4
 deve ser retornado o valor 2 (duas repetições de 44)

c. caso o número seja (parâmetro 1) 3434 e o segundo parâmetro seja o número 4
 deve ser retornado o valor 0

d. caso o número seja (parâmetro 1) 8549 e o segundo parâmetro seja o número 4
 deve ser retornado o valor 0

*/

int duplicatas(short int, short int);
int tamanho_posicoes_numero(short int);

int main(void) {
    short int primeiro, segundo;
    printf("Informe o número que será analisado: ");
    scanf("%hd", &primeiro);

    while (primeiro <= 0) {
        printf("Entrada inválida! Terá que ser um número maior que 0!\n");
        printf("Informe o número que será analisado: ");
        scanf("%hd", &primeiro);
    }

    while (getchar() != '\n'); // Limpar o buffer, tava com problema que o \n entrava no próximo scanf, o getchar() irá se sacrificar e receber \n

    printf("Informe um número de um dígito: ");
    scanf("%hd", &segundo);

    while((tamanho_posicoes_numero(segundo) != 1) || (segundo < 0)) {
        printf("Dígito inválido!\n");
        printf("Informe um número de um dígito: ");
        scanf("%hd", &segundo);
    }

    while (getchar() != '\n'); // mesma ideia de limpar o buffer depois do scanf


    printf("Vezes que o %hd%hd aparece no número %hd: %d\n", segundo, segundo, primeiro, duplicatas(primeiro, segundo));
}

int duplicatas(short int valor, short int digito) {
    // Achar o número que buscamos no valor (digito*10 + digito)
    int duplicata = (10 * digito) + digito;
    int count = 0, valor_analise;

    while (valor != 0) {
        valor_analise = (valor % 100); // pega a primeiro dupla desse valor, lendo da direita a esquerda -> 34(44) -> 3(44)4 -> (34)44

        if (valor_analise == duplicata) {
            count++; // se a dupla for igual a duplicata, adicione 1 no contador.
        }

        valor /= 10; // iremos ignorar o último digito da duplicata, e o digito à frente dele ocupará seu lugar, deixando vago para o próximo digito.
    }

    return count;
}


// Criei essa função só para verificar se o usuário digitou um dígito mesmo. Não faz parte da resposta.
int tamanho_posicoes_numero(short int valor) {
    int count = 0;

    while (valor != 0) {
        valor /= 10;
        count++;
    }

    return count;
}
