#include<stdio.h> 
/* Membros

Versão do GCC utilizado para compilação
gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0

*/

#define true 1
#define false 0 
#define max_vetoresReps 20
#define max_vetoresNoReps 2 * max_vetoresReps 

/*
Enquanto escrevia o código, via a necessidade de alimentar um array inicialmente com -1,
assim poderei checar quais entradas são válidas, evitando lidar com garbage values

É muito melhor trabalhar com 

v[4] = {2, 3, -1, -1}

Do que com 

v[4] = {2, 3, -3225, 0}

*/
void iniciarVetorInvalido(int v[], int size_v) {
    for (int i = 0; i < size_v; i++) {
        v[i] = -1; 
    }
}

/*
A minha ideia é permitir um número máximo X de array inicial, e 
se o usuário informar um número negativo antes, o 
resto do array será preenchindo com -1 (uma entrada inválida) e, posteriormente, 
essas entradas serão descartadas.

Exemplo
Se permitirmos no máximo 6 entradas, e o usuário informar um número negativo na quinta posição, o 
array ficará assim.
v1[6] = {1, 2, 3, 4, -1, -1} 

E depois irei descartar esses -1:
primary[4] = {1, 2, 3, 4} 

*/

//Checa se um valor existe no vetor. Será usado no "merge()" para evitar duplicatas.
int jaExisteNoVetor(int target, int v[], int v_size) {    
    for (int i = 0; i < v_size; i++) {
        if (v[i] == target) 
            return true; 
    }
    return false; 
}

void alimentandoVetor(int vector[], int vector_number) {
    
    iniciarVetorInvalido(vector, max_vetoresReps); 

    int segurarValor; 

    for (int i = 0; i < max_vetoresReps; i++) {
        printf("Informe, para o %do vetor, o seu %do termo: ", vector_number, (i + 1));
        scanf("%d", &segurarValor);  

        if (segurarValor < 0) {
            return; // Sair da função assim que ele informar um número < 0 
        }

        vector[i] = segurarValor; 
    }
}

void ordenarVetor(int v[], int size_v) {
    // Variável temporária para segurar o valor que supostos ser o menor entre dois
    int temp;
    // -1 pois não faz sentindo analisar o último = ele será o maior no final da execução
    for (int i = 0; i < size_v - 1; i++) {
        for (int j = 0; j < size_v - i - 1; j++) {
            // Checa se o número atual é maior que seu sucesso, se for, iremos trocar eles de lugar
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp; 
            }
        }
    }
}

/*
v1[6] = {1, 2, 3, 4, -1, -1} 
Sei que, para valores diferentes -1, incrementa-se 1 em números válidos (feito por contadorEntradasInvalidas)

Daí a importância daquela primeira função de alimentar o vetor com -1 ;)

Após essa função (contadorEntradasInvalidas) retornar 4 no nosso exemplo, temos um array de destino
chamado primary que irá guardar esses valores válidos. 

primary[4] = {1, 2, 3, 4} 
*/
void filtrarEntradasInvalidas(int dest[], int invalid_vector[], int sizeValid) {
    for (int i = 0; i < sizeValid; i++) {
        dest[i] = invalid_vector[i]; 
    }

}

int contadorEntradasInvalidas(int v[]) {
    int count = 0; // irá incrementar para cada -1 (inválido) no vetor.

    for (int i = 0; i < max_vetoresReps; i++) {
        if (v[i] == -1) {
            count++; 
        }
    }

    return count; 
}

/*
O coração do código - merge

"O terceiro vetor seja um merge * dos outros dois iniciais e esses devem ser passados como 
parâmetro para uma rotina específica. Este terceiro vetor não terá valores repetidos."

* Merge é a união de dois elementos e um só

*/
int merge(int v1[], int size_v1, int v2[], int size_v2, int merged[]) {

    /*
    Como os vetores podem ter tamanhos diferentes, pensei no seguinte:
    cada vetor terá um "tickets" que, se ele quiser alocar seu elemento, terá que pagar seu ticket (coincide com seu tamanho)

    Logo, se não restar mais tickets, passamos por todos os elementos desse vetor,
    logo o resto da merge será o outro vetor (se houver elementos nele também).
    */

    int ticketsParaVetor1 = size_v1; 
    int ticketsParaVetor2 = size_v2; 
    int elementoDeV1, elementoDeV2, pontoDeParada;
    int acompanharQuarto = 0; 
    int indexOfMerge = 0;

    while ((ticketsParaVetor1 > 0) && (ticketsParaVetor2 > 0)) {
        /*
        Imagine um vetor de tamanho 5, logo seus tickets totalizam 5 inicialmente.

        Ela pagou 1 ticket e fez a requisição para adicionar seu elemento no vetor merged
        
        [!] Repare em "requisição": afinal, seu elemento pode já estar em merged, logo ela pagou à toa.

        Após pagar, ela tem 4 tickets, e o seu próximo elemento está na [5 - 4] = 1 do vetor.
        */
        elementoDeV1 = v1[size_v1 - ticketsParaVetor1];
        elementoDeV2 = v2[size_v2 - ticketsParaVetor2];

        if (elementoDeV1 <= elementoDeV2) {
            if (jaExisteNoVetor(elementoDeV1, merged, max_vetoresNoReps)) {
                ticketsParaVetor1--;
                continue; 
            } else {
                merged[indexOfMerge] = elementoDeV1; 
                ticketsParaVetor1--;
                indexOfMerge++; // Após alocar o novo elemento, vamos para o próximo "espaço" de merged.
            }
        } else {
            if (jaExisteNoVetor(elementoDeV2, merged, max_vetoresNoReps)) {
                ticketsParaVetor2--;
                continue; 
            } else {
                merged[indexOfMerge] = elementoDeV2;
                ticketsParaVetor2--;
                indexOfMerge++;
            }
        }
    }

    // Se há tickets para o segundo vetor, então não percorremos ele inteiro, mas o primeiro vetor sim. Vice-versa
    if (ticketsParaVetor2 != 0) {
        // Quero saber onde eu parei de analisar esse vetor antes do primeiro vetor zerar.
        // Se sobrou 2 tickets de um vetor de 4 posições, falta 2 elementos a serem analisados (nesse caso, se já existem no vetor e, senão, alocar)
        pontoDeParada = size_v2 - ticketsParaVetor2; 
        
        for (int i = pontoDeParada; i < size_v2; i++) {
            if (jaExisteNoVetor(v2[i], merged, max_vetoresNoReps)) {
                continue; 
            } else {
                merged[indexOfMerge] = v2[i]; 
                indexOfMerge++;
            }
        }
    }
    if (ticketsParaVetor1 != 0) {
        pontoDeParada = size_v1 - ticketsParaVetor1;

        for (int i = pontoDeParada; i < size_v1; i++) {
            if (jaExisteNoVetor(v1[i], merged, max_vetoresNoReps)) {
                continue; 
            } else {
                merged[indexOfMerge] = v1[i]; 
                indexOfMerge++;
            }
        } 
    }

    // Por fim, retornar o número de entradas válidas, pois
    // Pode ser que o primeiro ou segundo vetor esteja incompleto, daí não bate o teto máximo 
    // que alocamos para esse terceiro vetor e, para ignorar os garbage values, vamos ler 
    // o vetor resultando de [0, indexOfMerge], 
    return indexOfMerge;
}

int contarRepeticoes(int target, int v[], int size) {
    int count = 0; 

    for (int i = 0; i < size; i++) {
        if (v[i] == target) {
            count++; 
        }
    }
    return count; 
}

void procurarRepeticoes(int v[], int quarto_esp[], int size) {
    int indexDeQuarto = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((v[i] == v[j]) && (i != j) && (!jaExisteNoVetor(v[i], quarto_esp, max_vetoresNoReps))) {
                printf("[%d] - %d vezes! | ", v[i], contarRepeticoes(v[i], v, size)); 
                
                quarto_esp[indexDeQuarto] = v[i];
                
                indexDeQuarto++;
            }
        }
    }
}

// Imprime com formatação no terminal
void printarVetor(int v[], int size) {
    for (int i = 0; i < size; i++) {
        if (v[i] != -1) {
            printf("[%d] ", v[i]); 
        }
    }
}

int main(void) {
    /*
    Crie 2 vetores de inteiros positivos (maiores ou iguais a 0) *distintos* que tenham tamanho máximo de 
    20 elementos cada. E insira elementos para cada um dos vetores, onde o critério de parada para 
    inserção dos elementos em um vetor é a inserção do 20º elemento ou que seja inserido um 
    valor negativo.
    */
    int v1[max_vetoresReps]; 
    int v2[max_vetoresReps]; 
    
    alimentandoVetor(v1, 1); 
    printf("\n"); 
    alimentandoVetor(v2, 2); 

    int numeroEntradasValidasV1 = max_vetoresReps - contadorEntradasInvalidas(v1);
    int numeroEntradasValidasV2 = max_vetoresReps - contadorEntradasInvalidas(v2);

    int primary[numeroEntradasValidasV1]; 
    int secundary[numeroEntradasValidasV2];
    int merged[max_vetoresNoReps]; 
    int quarto[max_vetoresNoReps]; // Guardará o total das repetições, sendo um merge dos vetores abaixo
    int reps_primary[max_vetoresNoReps]; // Guardará as repetições do primeiro vetor  
    int reps_secundary[max_vetoresNoReps]; // Guardará as repetições do segundo vetor  

    iniciarVetorInvalido(merged, max_vetoresNoReps); 
    iniciarVetorInvalido(quarto, max_vetoresNoReps);
    iniciarVetorInvalido(reps_primary, max_vetoresNoReps); 
    iniciarVetorInvalido(reps_secundary, max_vetoresNoReps); 

    filtrarEntradasInvalidas(primary, v1, numeroEntradasValidasV1); // Filtrar entradas -1

    filtrarEntradasInvalidas(secundary, v2, numeroEntradasValidasV2);

    ordenarVetor(primary, numeroEntradasValidasV1);
    ordenarVetor(secundary, numeroEntradasValidasV2);

    int tamanhoMerge = merge(primary, numeroEntradasValidasV1, secundary, numeroEntradasValidasV2, merged);

    /*
    Apresente (mostre na tela) cada um dos elementos de todos os vetores em cada etapa.
    */

    printf("\n");

    printf("Primeiro vetor: ");
    printarVetor(primary, numeroEntradasValidasV1);

    printf("\nSegundo vetor: ");
    printarVetor(secundary, numeroEntradasValidasV2);

    printf("\nTerceiro vetor (merge): ");
    printarVetor(merged, tamanhoMerge);

    printf("\n");

    // Fica faltando só o quarto: contenha os elementos que indicaram alguma repetição de valores que estejam nos dois vetores iniciais.

    // Analisando as repetições
    printf("\n");
    printf("- São valores que se repetem no Primeiro Vetor: - \n");

    procurarRepeticoes(primary, reps_primary, numeroEntradasValidasV1);

    printf("\n");
    printf("- São valores que se repetem no Segundo Vetor: - \n");

    procurarRepeticoes(secundary, reps_secundary, numeroEntradasValidasV2);
    printf("\n"); 
    printf("\n"); 

    /*
    O quarto vetor é nada mais do que um merge dos vetores de repetições.
    */
    merge(reps_primary, max_vetoresNoReps, reps_secundary, max_vetoresNoReps, quarto);

    printf("Quarto vetor (repetições): ");
    printarVetor(quarto, max_vetoresNoReps);
    printf("\n"); 

    return 0; 
}
