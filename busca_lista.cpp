#include <stdio.h>
#include <stdlib.h>
const int  TMAXIMO = 50;

void read_vetor(int *vetor,int n)  
 {
        int i, valor;
        for (i = 0; i < n; i = i + 1){
				printf("\nDigite o valor do vetor[%3d]:",i);
				scanf("%d", &valor);
				vetor[i] = valor;
			}
   }
   
void write_vetor(int *vetor, int n){
      int i;
      for (i = 0; i < n; i = i + 1) printf("%3d", vetor[i]);
      printf("\n");
      
  }
   
     
int busca(int x, int *lista, int n)
{
int i;
i = 0;
while ((i<n) and (lista[i]!=x))
i=i+1;
if (i < n)
return i;
else
return -1;
}

int busca_ord(int x, int * listaord, int m)
{
int i;
i = 0;
while ((i<m) and (listaord[i]< x))
i=i+1;
if (listaord[i]==x)
return i;
else
return -1;
}

int busca_ord_pos(int x, int * listaord, int m)
{
	int i;
	i = 0;
	while ((i<m) and (listaord[i]< x)) i=i+1;
	return i;
}


int busca_bin(int x, int * listaord, int m)
{
int inf, sup, meio;
inf = 0;
sup = m -1;
while (inf <= sup)
{
meio = (inf + sup) / 2;
if (listaord[meio] == x)
inf = sup + 1;
else
if (x < listaord[meio])
sup = meio - 1;
else
inf = meio + 1;
}
if (listaord[meio] == x)
return meio;
else
return -1;
}

int insert_no(int x, int *lista, int m){
	int indice, i;
	indice = busca_ord_pos(x, lista, m);
	printf("Indice: %3d\n",indice);
	if(indice > m-1 || lista[indice] > x){
		for(i = m-1; i >= indice ;i=i-1){
			lista[i+1]=lista[i];
			printf("lista %3d\n",lista[i+1]);
		}
		lista[indice]=	x;		
	}else
		printf("elemento se encontra na lista!\n");
		
}

   int main(void){

	int m, n, novo, resultado, m1[TMAXIMO];
	   printf("Numero de itens do Vetor:");
       scanf("%d", &m);


       if (m < TMAXIMO )
       {
       	   printf("Vetor 1:\n");
           read_vetor(m1, m);
           printf("\n");
           printf("Deseja buscar qual valor?");
       	   scanf("%d", &n);
           resultado = busca(n,m1, m);
           printf("Resultado busca: %3d\n",resultado);
           resultado = busca_ord(n,m1, m);
           printf("Resultado busca-ord: %3d\n",resultado);		   
		   resultado = busca_bin(n,m1, m);
           printf("Resultado busca-bin: %3d\n",resultado);
		   printf("Vetor 1:\n");		   
           write_vetor(m1, m);                      
        
		   printf("Deseja inserir qual valor?");
       	   scanf("%d", &novo);
           insert_no(novo, m1,m);
           m = m + 1;
		   printf("Vetor 1:\n");		   
           write_vetor(m1, m);  
       }
  
}
  
