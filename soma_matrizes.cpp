#include <stdio.h>
#include <stdlib.h>
const int  TMAXIMO = 50;

void read_matriz(int matriz[TMAXIMO][TMAXIMO], int m, int n)  
 {
        int i, j;
        for (i = 0; i < m; i = i + 1)
            for (j = 0; j < n; j = j + 1) {
				printf("Digite o valor de matriz[%3d,%3d]:",i,j);
				scanf("%d", &matriz[i][j]);
			}
   }
   
void write_matriz(int matriz[TMAXIMO][TMAXIMO], int m, int n){
      int i, j;
      for (i = 0; i < m; i = i + 1)
      {
          for (j = 0; j < n; j = j + 1) printf("%3d", matriz[i][j]);
          printf("\n");
      }
  }
   
     
void sum_matriz(int a[TMAXIMO][TMAXIMO], int b[TMAXIMO][TMAXIMO],  int c[TMAXIMO][TMAXIMO], int m, int n){
      int i, j;
      for (i = 0; i < m; i = i + 1)
         for (j = 0; j < n; j = j + 1) 
		 	c[i][j] = a[i][j] + b[i][j];
  }
   

int main(void){

	int m, n, m1[TMAXIMO][TMAXIMO], m2[TMAXIMO][TMAXIMO], m3[TMAXIMO][TMAXIMO];
	   printf("Numero de linhas:");
       scanf("%d", &m);
       printf("Numero de colunas:");
       scanf("%d", &n);
       if (m < TMAXIMO && n < TMAXIMO)
       {
       	   printf("Matriz 1:\n");
           read_matriz(m1, m, n);
           printf("Matriz 2:\n");
           read_matriz(m2, m, n);           
           printf("\n");
           sum_matriz(m1, m2, m3, m, n);
           printf("Matriz 1:\n");
           write_matriz(m1, m, n);
           printf("Matriz 2:\n");
           write_matriz(m2, m, n);
           printf("Matriz Resultado:\n");
           write_matriz(m3, m, n);
       }
  
}
  
