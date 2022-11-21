#include <stdio.h>
#include <stdlib.h>
const int  TMAXIMO = 50;

void read_vetor(int vetor[TMAXIMO],int n)  
 {
        int i;
        for (i = 0; i < n; i = i + 1){
				printf("Digite o valor do vetor[%3d]:",i);
				scanf("%d", &vetor[i]);
			}
   }
   
void write_vetor(int vetor[TMAXIMO], int n){
      int i;
      for (i = 0; i < n; i = i + 1) printf("%3d", vetor[i]);
      printf("\n");
      
  }
   
     
int busca(int a[TMAXIMO], int n, int x){
      int i, resultado;
      resultado=0; i=1;
      while(i < n){
		if(a[i]==x){
			resultado = i;
			i = i +1;
		}else
			i = i +1;
	  }
	  return resultado;
  }

int busca2(int a[TMAXIMO], int n, int x){
      int i;
      a[n]=x; i=0;
      while(a[i]!=x)
      	i = i +1;
	  if(i!=n+1)
	  	return i;
	  else
	  	return 0;
}

int busca_ord(int a[TMAXIMO], int n, int x){
      int i;
      a[n]=x; i=0;
      while(a[i] < x && i < n )
      	i = i +1;
	  if(i==n || a[i]!=x ) 
	  	return 0;
	  else
	  	return i;
}


int busca_bin(int a[TMAXIMO], int n, int x){
      int i, inf, sup, meio;
      int resultado = 0;
      sup = n-1;
      inf =0;      
      while( inf <=sup){
      	meio = ((inf + sup)/2);
      	if(a[meio]==x){
      		resultado = meio;
      		inf = sup +1;
		  }else
		  if(a[meio]<x){
		  	inf = meio + 1;
		  }else
		  	sup = meio -1;
	  }
	  	return resultado;
}



   int main(void){

	int m, n,resultado, m1[TMAXIMO];
	   printf("Numero de itens do Vetor:");
       scanf("%d", &m);


       if (m < TMAXIMO )
       {
       	   printf("Vetor 1:\n");
           read_vetor(m1, m);
           printf("\n");
           printf("Deseja buscar qual valor?");
       	   scanf("%d", &n);
           resultado = busca(m1, m, n);
           printf("Resultado: %3d\n",resultado);
           printf("Vetor 1:\n");
           write_vetor(m1, m);                      
       }
  
}
  
