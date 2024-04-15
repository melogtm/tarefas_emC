#include<stdio.h>
#include<stdlib.h>

/*
Entrar com um n�mero inteiro positivo e menor que 10.000 e informar o valor de sua casa na unidade, na dezena, na centena e no milhar
*/

int main(void) {

	// Ir� guardar o n�mero que ser� decomposto em sua unidade, dezena, centena e milhar. 	
	int n; 
	scanf("%d", &n); 

	// Se o n�mero for menor ou igual a zero, ou for maior que 10,000, o programa ir� se encerrar, pois n�o h� nada o que se possa fazer. 	
	if ((n <= 0) || (n >= 10000)) {
		printf("Entrada invalida, somente n�meros positivos (portanto, diferente de 0) e menores que 10,000!\n");
		return -1; 
	}
	
	// Array que ir� guardar as "partes" do n�mero, sendo a posi��o 0 reservada �s unidades, posi��o 1 reservada �s dezenas e assim em diante.
	int num_vect[4] = {0, 0, 0, 0}; 
	
	// Ir� controlar qual posi��o estaremos no Array. 
	int i = 0; 

	while (n != 0) {
		num_vect[i] = n % 10; // pega a �ltima posi��o do n�mero. 
		i++; 
		n /= 10; // remove o n�mero na �ltima posi��o, fazendo com que o n�mero a sua esquerda ocupe seu espa�o.  
	} 
	
	printf("UNIDADES = %d \nDEZENAS = %d \nCENTENAS = %d \nMILHARES = %d \n", num_vect[0], num_vect[1], num_vect[2], num_vect[3]);  	
	 	
	return 0; 
}

