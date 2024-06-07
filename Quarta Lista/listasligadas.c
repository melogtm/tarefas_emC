#include<stdio.h>
#include<stdlib.h> 

#define size 5 // Tamanho arbitrário para a nossa lista, +1 pois não conta com a primeira alimentação feita pelo insert_first_element

/*
A fazer: 
a) Crie uma lista ligada (simples), sendo que um nó contenha um INT e um ponteiro para o próximo nó; (ao criar a lista, o ponteiro inicial deve apontar para NULL)

Elabore rotinas para

b) Inserir um elemento no início da lista

c) Inserir um elemento no fim da lista

d) Excluir um elemento no início da lista

e) Excluir um elemento do fim da lista

f) Procure por um elemento (valor do inteiro) na lista - retorne 1 se achou e 0 caso contrário

g) order os elementos (de forma crescente) da lista

h) inserir um elemento no meio da lista de forma a mantê-la ordenada (podem haver repetições de valores na lista)

*/

// a) Crie uma lista ligada (simples) sendo que um nó contenha um INT e um ponteiro para o próximo nó; (ao criar a 
// lista, o ponteiro inicial deve apontar para NULL 

// Irei me utilizar de typedef para não ter que escrever "struct" cada vez que utilizar o tipo Node
typedef struct node {
    int n; 
    struct node* next; 
} node;

// Rotinas de Auxílio
void print_linked(node* linked) {
    printf("A sua lista: ");
    while (linked != NULL) {
        printf("[%d][%p] ->", linked->n, linked->next);
        linked = linked->next; 
    }
    printf("\n");
}

void trocar_posicao(node* l1, node* l2) {
    int tmp = l1->n; 
    l1->n = l2->n;
    l2->n = tmp; 
}

// Rotinas (item b à h)
void insert_first_element(node* linked, int x) {
    linked->n = x;
    linked->next = NULL;
}

void insert_last_element(node* linked, int x) {
    while (linked->next != NULL) {
        linked = linked->next; 
    }

    linked->next = (node*) malloc(sizeof(node));
    linked->next->n = x;
    linked->next->next = NULL; 
}

void order(node * linked) {
    int trocado, i;
    node *ptr1;
    node *lptr = NULL;

    if (linked == NULL) {
        printf("Não há o que ordenar!\n");
        return; 
    }

    do { // bubblesort para ordenar, irá percorre toda a lista e verificar se dá pra trocar posições ou não
        trocado = 0; 
        ptr1 = linked;

        while (ptr1->next != lptr) {
            if (ptr1->n > ptr1->next->n) {
                trocar_posicao(ptr1, ptr1->next);
                trocado = 1; 
            }
            ptr1 = ptr1->next; 
        }
        lptr = ptr1; 
    } while(trocado);
}

void insert_middle_element(node * ordered_linked, int x) {
    while (ordered_linked->next != NULL) { // Vamos verificar se não estamos no último node
        if (ordered_linked->n < x) { 
            ordered_linked = ordered_linked->next;
        } else {
            break; 
        }
    }

    node* new_node = (node*) malloc(sizeof(node)); 
    new_node->n = x; 
    new_node->next = ordered_linked->next; 

    ordered_linked->next = new_node; 

    order(ordered_linked); 
}

void remove_first_element(node* linked) {
    node * ptr_first_element = linked; // Guarda onde o nosso primeiro node está na memória

    linked = linked->next; // Ir para o próximo node  

    // Substituição!
    ptr_first_element->n = linked->n; 
    ptr_first_element->next = linked->next; 
}

void remove_last_element(node* linked) {
    if (linked->next == NULL) { // Só há um elemento
        linked = NULL;
    } else {
        while (linked->next->next != NULL) {
            linked = linked->next; // Vamos até o penúltimo elemento
        }

        linked->next = NULL;
    }
}

int search_value(node * linked, int target) {
    while (linked != NULL) {
        if (linked->n == target) {
            return 1;
        }
        linked = linked->next;
    }
    return 0; 
}

void remove_element(node* linked, int target) { // Supondo não haver repetição
    int doesExist = search_value(linked, target); 

    if (!doesExist) {
        printf("Não existe esse elemento na estrutura :T\n");
        return; 
    }  

    if (linked->n == target) {
        remove_first_element(linked);
        return;
    }

    while(linked != NULL) {
        if (linked->next->n == target) {
            linked->next = linked->next->next;
            return; 
        }
        linked = linked->next;
    }
} 

int main(void) {

    int user; // elementos do usuário! 

    // Criando o nosso primeiro node (letra a)
    node* linked_list = (node*) malloc(sizeof(node)); 

    printf("Bem-vindo ao LinkedList Paradise's! \n"); 
    printf("Informe %d valores: \n", size + 1); 

    scanf("%d", &user); 

    insert_first_element(linked_list, user); 

    for (int i = 0; i < size; i++) {
        scanf("%d", &user); 
        insert_last_element(linked_list, user);
    }

    printf("Procure um valor: "); 
    scanf("%d", &user);

    if (search_value(linked_list, user) == 1) {
        printf("Existe na estrutura!\n");
    } else {
        printf("Não existe na estrutura!\n");
    }

    print_linked(linked_list);

    printf("Removendo primeiro e último node: \n");

    remove_first_element(linked_list);
    remove_last_element(linked_list);

    print_linked(linked_list);

    printf("Ordenando de forma crescente a lista: \n");

    order(linked_list);

    print_linked(linked_list);

    printf("Informe um valor para ser adicionado na lista: ");
    scanf("%d", &user);
    insert_middle_element(linked_list, user); 

    print_linked(linked_list); 

    printf("Informe um valor para ser removido da lista: ");
    scanf("%d", &user);
    remove_element(linked_list, user); 

    print_linked(linked_list); 

    free(linked_list); 
    return 0; 
}