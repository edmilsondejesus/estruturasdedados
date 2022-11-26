// Lista encadeada ordenada na qual cada nó armazena um número de identificação e um nome. 
// A lista está ordenada pelo número de identificação. O programa cria uma lista vazia inicialmente, e tem a opção de inclusão e exclusão de nós.
// Adicionada uma fila de atendimento, onde é possível inserir um cliente da lista ordeanda na fila circular sequencial de antedimento e também é possível tratar a fila de atendimento.
// Autor: Edmilson de Jesus
// Assunto: Manipulaão de listas encadeadas
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

struct Lista {
	  int id; //identificador
      char  *nome; // nome
      Lista *prox;      
   } Lista; // n?
   
typedef struct Lista tplista;   


//Fun??es para estrutura da lisa
//--------------------------------------------

tplista *lista;  // Primeiro ponteiro da lista


tplista * inicia_lista() {
   lista = (tplista *) malloc (sizeof(tplista)); // inicio da pilha
   lista->id=0;
   lista->nome=NULL;
   lista->prox = NULL; 
   return lista;
}

void insere_na_lista (tplista *lista, int id, char *nome) { 
   tplista *novo, *aux, *ant;
   //cria o novo nó para a lista
   novo = (tplista *) malloc (sizeof (tplista));
   novo->id=id;
   novo->nome=(char *) malloc (sizeof (nome));
   strcpy(novo->nome, nome);
   novo->prox  = NULL;
   
   //insere o novo nó na posição correta da lista
   aux=lista; // pega o ponteiro para a lista 
   
   //procura a posição correta paar inserir   
   while((aux->id < id) &&(aux->prox!=NULL)){
   		ant=aux;
   		aux=aux->prox;
   }
    	
   //Supondo que já  achou a posição correta ou chegou no final da lista
   if(aux->prox!=NULL) 	
   	novo->prox=aux->prox;
   	   	
   //Insere o item novo na posição subsequente	
   if(aux->id < id)
   		aux->prox=novo;   
   else	{
   		novo->prox=aux;   
   		ant->prox=novo;
   }
}

//verifica se a lista está vazia
int lista_vazia(void){
	return ((lista==NULL)||(lista->id==0 && lista->prox==NULL));
}

int retira_da_lista (tplista *lista, int id) {
	if(!lista_vazia()){ // Verifica se a lista está vazia
   		tplista *aux, *ant;
	    aux=lista;   
		ant=NULL;		
   		//procura a posição correta paar inserir   
    	while((aux->id != id) &&(aux->prox!=NULL)){
			ant=aux;
    		aux=aux->prox;
    	}
    	//Supondo que já  achou a posição ou chegou no final da lista
    	if(aux->id!=id){
     		printf("Identificador não encontrado!");
     		return 0;
   		}else{
   			ant->prox=aux->prox;
   			free (aux);
   			printf("Identificador %d excluído com sucesso!",id);
   			return 1; 
   		}
   	}
}

tplista *busca_na_lista (tplista *lista, int id) {
	if(!lista_vazia()){ // Verifica se a lista está vazia
   		tplista *aux, *ant;
	    aux=lista;   
		ant=NULL;		
   		//procura a posição correta paar inserir   
    	while((aux->id != id) &&(aux->prox!=NULL)){
			ant=aux;
    		aux=aux->prox;
    	}
    	//Supondo que já  achou a posição ou chegou no final da lista
    	if(aux->id!=id){
     		printf("Identificador não encontrado!");
     		return NULL;
   		}else{
   			printf("Identificador localizado!");
   			return aux; 
   		}
   	}
}

void libera_lista(tplista *lista){
	//Desempilha todos os itens da pilha
	if(!lista_vazia()) {	
		libera_lista(lista->prox);
		free(lista->prox);
	}
}


//--------------------------------------------



tplista *Plista;

//função de impressão da lista
void read_lista_recursivo(tplista **lista) {
   if (*lista != NULL) {
   	  if((*lista)->id>0)
      	printf ("Id: %d Nome: %s \n", (*lista)->id,(*lista)->nome);   	
      read_lista_recursivo (&(*lista)->prox);
   }
}

//Função contar lista recursivo
int contar_nos(tplista *lista){
	if(lista->prox==NULL)
		return 0;
	else
		return 1 + contar_nos(lista->prox);
}

 int main(void){

	int id, opcao;
	char nome[200];
	tpcliente *pCliente =(tpcliente *)malloc(sizeof(tpcliente));
	tpfila *Fila = (tpfila *) malloc(sizeof(tpfila));
    definir(Fila);
    setlocale(LC_ALL, "Portuguese");
    printf("Lista Encadeada com Fila Circular de Atendimento \n");
    Plista=inicia_lista();
    do {
	    printf("\n 1 - Inserir na Lista Encadeada;\n 2 - Remover da Lista Encadeada;\n 3 - Imprimir Lista Encadeada;\n 4 - Inserir na Fila Circular Sequencial de Atendimento;\n 5 - Atender Cliente na Fila Circular Sequencial de Atendimento;\n 6 - Imprimir Fila Sequencial de Atendimento;\n 7 - Sair:");
	    printf("\nDigite uma opção: ");
        scanf("%d", &opcao);
        if (opcao == 1){
           printf("\nDigite um id: ");
           scanf("%d", &id);
           printf("\nDigite um nome: ");
           scanf("%s", nome);           
           insere_na_lista(Plista,id, nome);
        } else if  (opcao == 2){
           printf("\nDigite um id: ");
           scanf("%d", &id);
           retira_da_lista(Plista,id);
        } else if  (opcao == 3){
        	read_lista_recursivo(&Plista);
        }else if (opcao == 4){
           //localizar id na lista encadeada e inserir na fila de atendimento	
           printf("\nDigite um id: ");
           scanf("%d", &id);
           tplista *aux=busca_na_lista (Plista, id);
           if(aux!=NULL){
	           pCliente->id = id;		    
	           strcpy(pCliente->nome, aux->nome);
    	       strcpy(pCliente->nome,nome);
        	   inserir_na_fila(Fila,pCliente);
        	}
        } else if  (opcao == 5){
           if(remover_da_fila(Fila, pCliente))
           		printf("\nCliente atendido:\n id: %d nome: %s \n",pCliente->id, pCliente->nome);
           	else
           		printf("\nFila de atendimento vazia.\n");
        } else if  (opcao == 6){
        	for(int i=Fila->inicio+1; i <= Fila->fim;i++){
        		printf("\nCliente em espera %d:\n id: %d nome: %s \n",i,Fila->A[i].id, Fila->A[i].nome);
			}	
        }  
	}while (opcao !=7);
	
}
  

