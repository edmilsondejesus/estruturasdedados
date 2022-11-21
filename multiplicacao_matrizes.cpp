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
   
     
void multi_matriz(int a[TMAXIMO][TMAXIMO], int b[TMAXIMO][TMAXIMO],  int c[TMAXIMO][TMAXIMO], int m, int n,int ma2, int na2){
      int i, j, cola, temp;
      for (i = 0; i < m; i = i + 1)
         for (j = 0; j < na2; j = j + 1){
		    c[i][j]=0;
		   	for(cola=0; cola < ma2;cola = cola +1)
		   		c[i][j] = c[i][j] + (a[i][cola]*b[cola][j]);
		 	 
		 }
  }
   

int main(void){

	int m, n, ma2, na2, m1[TMAXIMO][TMAXIMO], m2[TMAXIMO][TMAXIMO], m3[TMAXIMO][TMAXIMO];
	   printf("Numero de linhas Matriz1:");
       scanf("%d", &m);
       printf("Numero de colunas Matriz1:");
       scanf("%d", &n);
       
       	   printf("Numero de linhas Matriz2:");
       scanf("%d", &ma2);
       printf("Numero de colunas Matriz2:");
       scanf("%d", &na2);


       if (m < TMAXIMO && n < TMAXIMO && ma2 < TMAXIMO && na2 < TMAXIMO)
       {
       	   printf("Matriz 1:\n");
           read_matriz(m1, m, n);
           printf("Matriz 2:\n");
           read_matriz(m2, ma2, na2);           
           printf("\n");
           multi_matriz(m1, m2, m3, m, n,ma2, na2);
           printf("Matriz 1:\n");
           write_matriz(m1, m, n);
           printf("Matriz 2:\n");
           write_matriz(m2, ma2, na2);
           printf("Matriz Resultado:\n");
           write_matriz(m3, m, na2);
       }
  
}
  
