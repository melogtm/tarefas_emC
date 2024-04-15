#include<stdio.h>
#include<stdlib.h>

/*
Entrar com um número inteiro positivo e menor que 10.000 e informar o valor de sua casa na unidade, na dezena, na centena e no milhar
*/

int main(void) {

	// Irá guardar o número que será decomposto em sua unidade, dezena, centena e milhar. 	
	int n; 
	scanf("%d", &n); 

	// Se o número for menor ou igual a zero, ou for maior que 10,000, o programa irá se encerrar, pois não há nada o que se possa fazer. 	
	if ((n <= 0) || (n >= 10000)) {
		printf("Entrada invalida, somente números positivos (portanto, diferente de 0) e menores que 10,000!\n");
		return -1; 
	}
	
	// Array que irá guardar as "partes" do número, sendo a posição 0 reservada às unidades, posição 1 reservada às dezenas e assim em diante.
	int num_vect[4] = {0, 0, 0, 0}; 
	
	// Irá controlar qual posição estaremos no Array. 
	int i = 0; 

	while (n != 0) {
		num_vect[i] = n % 10; // pega a última posição do número. 
		i++; 
		n /= 10; // remove o número na última posição, fazendo com que o número a sua esquerda ocupe seu espaço.  
	} 
	
	printf("UNIDADES = %d \nDEZENAS = %d \nCENTENAS = %d \nMILHARES = %d \n", num_vect[0], num_vect[1], num_vect[2], num_vect[3]);  	
	 	
	return 0; 
}

