#include <stdio.h>
#include <stdlib.h>

/*
Entrar com N números inteiros e maiores ou iguais a zero e dizer qual foi o maior número entrado, qual o menor, a soma deles e a média. Os critérios de parada são: 
(a) Pode-se pedir para que se digite o valor de N e que se entre exatamente N números; ou 
(b)  um dos números digitados seja negativo

Preferir adotar vetores para a solução dessa lista, pois trabalhar com vetores + laços de repetição é bom demais :)
*/

int maior_valor(int[], int); 
int menor_valor(int[], int); 
int soma_valor(int[], int); 
double media_valor(int, int); 

int main(int argc, char *argv[]) {
	
	int n, valor; 
	printf("Quantos numeros serao informados? ");
	scanf("%d", &n); 
	
	while (n <= 0) {
		printf("Por favor, informe uma entrada valida (n >= 0): "); 
		scanf("%d", &n); 
	}
	
	// Array irá guardar os valores digitados pelo usuário. 
	int vect[n]; 
	
	int i; // Compilar reclama se eu colocar isso no laço FOR
	for (i = 0; i < n; i++) {
		printf("Informe o %da valor: ", (i + 1)); 
		
		scanf("%d", &valor); 
		
		if (valor < 0) {
			printf("Entrada de numero negativo! Encerrando o programa.\n"); 
			return -1; 
		}
		
		vect[i] = valor; // Guarda o valor inserido pelo usuário.
	} 
	
	int maior, menor, soma; 
	double medium; 
		
	maior = maior_valor(vect, n); 
	menor = menor_valor(vect, n); 
	soma = soma_valor(vect, n); 
	medium = media_valor(soma, n); 
		
	printf("MAIOR = %d \n MENOR = %d \n SOMA = %d \n MEDIA = %.2lf \n", maior, menor, soma, medium);

	return 0;
}

int maior_valor(int* vect, int n) {
	int maior = vect[0]; 
	
	int i; 
	for (i = 0; i < n; i++) {
		if (maior < vect[i]) {
			maior = vect[i]; // Irá iterar sobre o array e, se achar um número maior que o "suposto" número na variável maior, irá substituí-lo e segue o laço.
		}
	}
	
	return maior; 
}

int menor_valor(int* vect, int n) {
	int menor = vect[0]; 
	
	int i; 
	for (i = 1; i < n; i++) {
		if (menor > vect[i]) {
			menor = vect[i]; // Irá iterar sobre o array e, se achar um número menor que o "suposto" número na variável menor, irá substituí-lo e segue o laço.
		}
	}
	
	return menor; 
}

int soma_valor(int* vect, int n) {
	int i;
	int sum = 0;
	 
	for (i = 0; i < n; i++) {
		sum += vect[i]; // Somatório dos valores. 
	}
	
	return sum; 
}

double media_valor(int soma, int nEntradas) {
	// TypeCasting, pois se eu armazenasse em um int, poderia perder informação após a vírgula. 
	return (double) soma / nEntradas; 
}
