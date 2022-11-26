// Fila circular sequencial onde cada nó armazena um nome e identificador.
// Autor: Edmilson de Jesus
// Assunto: Manipulaão de Fila circular sequencial
// Data: 25/11/2022

#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include <string.h>
#define TAM_FILA 10

typedef struct{
	  int id; //identificador
      char  nome[200]; // nome
}tpcliente;

typedef struct{
	tpcliente A[TAM_FILA];
	int inicio, fim;
}tpfila; //estrutura da fila 

/*Cria uma fila vazia*/
void definir (tpfila *pFila){	
	pFila->fim = 0;
	pFila->inicio = 0;
}

/*Verifica se a fila está vazia*/
int fila_vazia (tpfila *pFila){
	return (pFila->inicio == pFila->fim);
}

/* Retorna 1 se a fila estiver cheia e 0 caso a fila não esteja cheia */
int fila_cheia (tpfila *pFila){
	return (pFila->inicio == ((pFila->fim + 1) % TAM_FILA));
}

/* Insere um elemento no final da fila e retrona 1 se tiver sucesso ou 0 caso contrário */
int inserir_na_fila (tpfila *pFila, tpcliente *item){
	if (fila_cheia(pFila))
		return 0;
	pFila->fim = (pFila->fim + 1) % TAM_FILA ;
	pFila->A[pFila->fim].id = item->id;
	strcpy(pFila->A[pFila->fim].nome, item->nome);
	return 1;
}
/*Remove um elemento da fila*/
int remover_da_fila(tpfila *pFila, tpcliente *item){
	if (fila_vazia(pFila))
		return 0;
	pFila->inicio = (pFila->inicio+1) % TAM_FILA;
	(*item).id=pFila->A[pFila->inicio].id;
	strcpy((*item).nome , pFila->A[pFila->inicio].nome);
	return 1;
}

/*Retorna o primeiro elemento da fila sem apagar*/
tpcliente * inicio_fila (tpfila *pFila){
	if (fila_vazia(pFila))
		return NULL;
	tpcliente *pCliente =(tpcliente *)malloc(sizeof(tpcliente));
	int index = (pFila->inicio+1) % TAM_FILA;
	pCliente->id = pFila->A[index].id;
	strcpy(pCliente->nome, pFila->A[index].nome);
	return pCliente;
}



 int main(void){

	int id, opcao;
	char nome[200];
	
	tpcliente *pCliente =(tpcliente *)malloc(sizeof(tpcliente));
	tpfila *Fila = (tpfila *) malloc(sizeof(tpfila));
    setlocale(LC_ALL, "Portuguese");
    printf("Fila Circular Sequencial\n");
    definir(Fila);
    do {
	    printf("\nDigite uma opção: \n 1 Inserir na fila;\n 2 Atender da fila;\n 3 Imprimir fila;\n 4 Sair:");
        scanf("%d", &opcao);
        if (opcao == 1){
           printf("\nDigite um id: ");
           scanf("%d", &id);
           printf("\nDigite um nome: ");
           scanf("%s", &nome);          
           pCliente->id = id;		    
           strcpy(pCliente->nome,nome);
           inserir_na_fila(Fila,pCliente);
        } else if  (opcao == 2){
           if(remover_da_fila(Fila, pCliente))
           		printf("\nCliente atendido:\n id: %d \nnome: %s \n",pCliente->id, pCliente->nome);
           	else
           		printf("\nFila de atendimento vazia.\n");
        } else if  (opcao == 3){
        	for(int i=Fila->inicio+1; i <= Fila->fim;i++){
        		printf("\nCliente em espera %d:\n id: %d \nnome: %s \n",i,Fila->A[i].id, Fila->A[i].nome);
			}	
        }  
	}while (opcao !=4);
	
}
  


