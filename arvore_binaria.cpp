// Estrutura de �rvore Bin�ria
// Autor: Edmilson de Jesus
// Assunto: Manipula��o de �rore bin�ria, inser��o, leitura em ordem, pr� ordem e p�s ordem.
// Data: 10/11/2022

#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

struct No {
      char  valor; // conte�do 01
      No *esq;
      No *dir;
   } No; // n�
   
typedef struct No tno;   


//Fun��es para estrutura de pilha
//--------------------------------------------

struct Item {
   tno  *no; 
   struct Item *prox;
} Item;

typedef struct Item item;

item *pilha;  // Primeiro ponteiro da pilha


void inicia_pilha (tno *no) {
   pilha = (item *) malloc (sizeof(item)); // inicio da pilha
   pilha->no=no;
   pilha->prox = NULL; 
}

void insere_na_pilha (tno *no) { 
   item *novo;
   novo = (item *) malloc (sizeof (item));
   novo->no = no;
   novo->prox  = pilha;
   pilha = novo; 
}

int pilha_vazia(void){
	return (pilha==NULL);
}

tno *retira_da_pilha (void) {
	if(!pilha_vazia()){ // Verifica se a pilha est� vazia
   		item *p;
   		p = pilha;
   		tno *no = p->no;
   		pilha = p->prox;
   		free (p);
   		return no; 
	}else
		return NULL;
}


void libera_pilha(void){
	//Desempilha todos os itens da pilha
	while(!pilha_vazia()) 
		retira_da_pilha ();
	//por fim libera a pilha	
	free(pilha);
}


//--------------------------------------------



tno *PArvore;

void cria_arvore(tno **pno){
    *pno = NULL;
}

//Fun��o de leitura de um n� da �rvore de cima para baixo - em ordem   
void read_em_ordem_recursivo(tno **no) {
   if (*no != NULL) {
      read_em_ordem_recursivo (&(*no)->esq);
      printf ("Valor: %d \n", (*no)->valor);   	
      read_em_ordem_recursivo (&(*no)->dir); 
   }
}

//Fun��o de leitura de um n� da �rvore da esquerda para a direita - pr�-ordem   
void read_pre_ordem_recursivo(tno **no) {
   if (*no != NULL) {
      printf ("Valor: %d \n", (*no)->valor);   	
      read_pre_ordem_recursivo (&(*no)->esq);
      read_pre_ordem_recursivo (&(*no)->dir); 
   }
}

//Fun��o de leitura de um n� da �rvore da direita para a esquerda - pos-ordem   
void read_pos_ordem_recursivo(tno **no) {
   if (*no != NULL) {
      read_pos_ordem_recursivo (&(*no)->esq);
      read_pos_ordem_recursivo (&(*no)->dir); 
      printf ("Valor: %d \n", (*no)->valor);   	
   }
}

//Fun��o contar n�s
int contar_nos(tno *no){
	if(no==NULL)
		return 0;
	else
		return 1 + contar_nos(no->dir)+contar_nos(no->esq);
}
// Lear uma �rvore em pr�-ordem iterativa
void read_pre_ordem_iterativo (tno *no) {
   inicia_pilha (no);  // pilha de n�s 
   while (true) {
      tno *x = retira_da_pilha ();
      if ( x != NULL) {
      	insere_na_pilha (x);
         insere_na_pilha (x->esq);
      }
      else {
         if (pilha_vazia ()) break;
         x = retira_da_pilha ();
         printf ("Valor: %d \n", x->valor);
         insere_na_pilha (x->dir);
      }
   }
   libera_pilha ();
}

//Fun��o que calcula a altura de um n�
int altura_arvore (tno *no) {
   if (no == NULL) 
      return -1; // Se a altura de um n� � vazia retrna -1
   else {
      int altura_esq = altura_arvore (no->esq);
      int altura_dir = altura_arvore (no->dir);
      if (altura_esq < altura_dir) 
	  	return altura_dir + 1;
      else 
	  	return altura_esq + 1;
   }
}

void insere_na_arvore(tno **no, int valor){
	if ((*no) == NULL)	{
	      (*no)=(tno *)malloc(sizeof (tno));
	      (*no)->esq=NULL;
	      (*no)->dir=NULL;
	      (*no)->valor=valor;
	      //printf("\nInsert %d: ",valor);
	}else {
		if (valor < ((*no)->valor)){
			//printf("\nmenor que %d: \n",(*no)->valor);
			insere_na_arvore(&((*no)->esq), valor);
		}else{
			//printf("\maior que %d: \n",(*no)->valor);
			insere_na_arvore(&((*no)->dir), valor);
		}
	}
}

 int main(void){

	int m, n, valor;
    setlocale(LC_ALL, "Portuguese");
    printf("Numero de itens da �rvore de maneira ordenada:");
    scanf("%d", &m);
    n=m+1;    
	cria_arvore(&PArvore);    
    
    while(m> 0){
    	printf("\nItem %d: ",(n-m));
    	scanf("%d", &valor);
    	insere_na_arvore(&PArvore, valor);
    	m--;	
	}       	       
    printf("\nImprime a �rvore em ordem recursivo:\n");
    read_em_ordem_recursivo(&PArvore);
	
	printf("\nImprime a �rvore em pr� ordem recursivo:\n");
    read_pre_ordem_recursivo(&PArvore);
    
	printf("\nImprime a �rvore em p�s ordem recursivo:\n");
    read_pos_ordem_recursivo(&PArvore);
    
    int altura=altura_arvore(PArvore);
    printf("\Altura da �rvore:\n%d",altura);

    int qtd_nos=contar_nos(PArvore);
    printf("\nQuantidade de N�s:\n%d",qtd_nos);

	printf("\n\nImprime a �rvore em pr� ordem interativa:\n");
	read_pre_ordem_iterativo(PArvore);    
}
  
