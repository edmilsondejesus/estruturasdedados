#include <stdio.h>
#include <stdlib.h>
// Estrutura de pilha
// Algoritmo para inserir itens na pilha e desempilhar


struct Item {
   char          valor; 
   struct Item *prox;
} Item;

typedef struct Item item;

item *pilha;  // Primeiro ponteiro da pilha


void inicia_pilha (void) {
   pilha = (item *) malloc (sizeof(item)); // inicio da pilha
   pilha->prox = NULL; 
}

void insere_na_pilha (char valor) { 
   item *novo;
   novo = (item *) malloc (sizeof (item));
   novo->valor = valor;
   novo->prox  = pilha->prox;
   pilha->prox = novo; 
}

int pilha_vazia(void){
	return (pilha==NULL);
}

char retira_da_pilha (void) {
	if(!pilha_vazia()){ // Verifica se a pilha está vazia
   		item *p;
   		p = pilha->prox;
   		char valor = p->valor;
   		pilha->prox = p->prox;
   		free (p);
   		return valor; 
	}else
		return 1;
}


libera_pilha(void){
	//Desempilha todos os itens da pilha
	while(!pilha_vazia()) 
		retira_da_pilha ();
	//por fim libera a pilha	
	free(pilha);
}

int main(void){

	int m, n, valor;
    printf("Numero de itens da pilha:");
    scanf("%d", &m);
    n=m+1;
    inicia_pilha();
    while(m> 0){
    	printf("\nItem %d: ",(n-m));
    	scanf("%d", &valor);
    	insere_na_pilha(valor);
    	m--;
	}
       	   
    printf("\n");
    printf("Imprime a pilha e desempilha!\n");
     
    while(!pilha_vazia()){
    	valor=retira_da_pilha();
    	printf("Item %d: Valor: %d \n", --n, valor);
	}
	libera_pilha();  
}
  
