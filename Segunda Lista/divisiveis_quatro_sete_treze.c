#include<stdio.h>
#include<stdlib.h>

/*
Entrar com N números e entre os números digitados dizer: (a) quantos são divisíveis por 4; (b) quantos são divisíveis por 7; e (c) quantos são divisíveis por 13.
*/

int contador_quatro(int*, int); 
int contador_sete(int*, int); 
int contador_treze(int*, int); 

int main(void) {
	// Quantidade de números que serão informados.
	int n; 
	scanf("%d", &n); 
	
	if (n <= 0) {
		printf("Entrada invalida! Encerrando programa..."); 
		return -1; 
	}
	
	// vect[n], um array, irá armazenar a variável "valor", esta irá realizar a recepção dos valores que serão informados pelo usuário. 
	int vect[n], valor; 
	
	int i; 
	for (i = 0; i < n; i++) {
		printf("Informe o %da valor: ", (i + 1)); 
		scanf("%d", &valor); 
		vect[i] = valor; 
	}
	
	printf("(a) QTD DE DIVISIVEIS POR 4: %d \n(b) QTD DE DIVISIVEIS POR 7: %d\n(c) QTD DE DIVISIVEIS POR 13: %d\n", contador_quatro(vect, n), contador_sete(vect, n), contador_treze(vect, n)); 

	return 0; 
}


int contador_quatro(int* vect, int n) {
	int i;
	int sum = 0;  
	// Iterar sobre cada valor no Array 
	for (i = 0; i < n; i++) {
		if (vect[i] % 4 == 0) {
			sum++; // Se o número for divisível por 4, o contador aumentará em 1
		}
	} 
	return sum; 
}

int contador_sete(int* vect, int n) {
	int i;
	int sum = 0;  
	for (i = 0; i < n; i++) {
		if (vect[i] % 7 == 0) {
			sum++; // Se o número for divisível por 7, o contador aumentará em 1.
		}
	} 
	return sum; 
}

int contador_treze(int* vect, int n) {
	int i;
	int sum = 0;  
	for (i = 0; i < n; i++) {
		if (vect[i] % 13 == 0) {
			sum++;  // Se o número for divisível por 13, o contador aumentará em 1.
		}
	} 
	return sum; 
}
