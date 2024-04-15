#include <stdio.h>
#include <stdlib.h>

/*
Entrar com N n�meros inteiros e maiores ou iguais a zero e dizer qual foi o maior n�mero entrado, qual o menor, a soma deles e a m�dia. Os crit�rios de parada s�o: 
(a) Pode-se pedir para que se digite o valor de N e que se entre exatamente N n�meros; ou 
(b)  um dos n�meros digitados seja negativo

Preferir adotar vetores para a solu��o dessa lista, pois trabalhar com vetores + la�os de repeti��o � bom demais :)
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
	
	// Array ir� guardar os valores digitados pelo usu�rio. 
	int vect[n]; 
	
	int i; // Compilar reclama se eu colocar isso no la�o FOR
	for (i = 0; i < n; i++) {
		printf("Informe o %da valor: ", (i + 1)); 
		
		scanf("%d", &valor); 
		
		if (valor < 0) {
			printf("Entrada de numero negativo! Encerrando o programa.\n"); 
			return -1; 
		}
		
		vect[i] = valor; // Guarda o valor inserido pelo usu�rio.
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
			maior = vect[i]; // Ir� iterar sobre o array e, se achar um n�mero maior que o "suposto" n�mero na vari�vel maior, ir� substitu�-lo e segue o la�o.
		}
	}
	
	return maior; 
}

int menor_valor(int* vect, int n) {
	int menor = vect[0]; 
	
	int i; 
	for (i = 1; i < n; i++) {
		if (menor > vect[i]) {
			menor = vect[i]; // Ir� iterar sobre o array e, se achar um n�mero menor que o "suposto" n�mero na vari�vel menor, ir� substitu�-lo e segue o la�o.
		}
	}
	
	return menor; 
}

int soma_valor(int* vect, int n) {
	int i;
	int sum = 0;
	 
	for (i = 0; i < n; i++) {
		sum += vect[i]; // Somat�rio dos valores. 
	}
	
	return sum; 
}

double media_valor(int soma, int nEntradas) {
	// TypeCasting, pois se eu armazenasse em um int, poderia perder informa��o ap�s a v�rgula. 
	return (double) soma / nEntradas; 
}
