#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 5 /* Число строк матрицы */
#define N 6 /* Число столбцов матрицы */

int main()
{ int min1;
  int a[M][N];
  int i, j;
  srand (time (NULL));
  printf("dano random tablic'a:\n");
  for(i = 0; i < M; i++)
      for(j = 0; j < N; j++)
          a[i][j] = rand()%100-50;

  for(i = 0; i < M; i++)
  {
      for(j = 0; j < N; j++)
          printf("%5d", a[i][j]);
      printf("\n");
          }

printf("----------------------------------");
printf("\n");

   for (j=0; j<N; j++)
   {
        min1 = 99999;
            for (i=0; i<M; i++){
                if ((a[i][j] < min1) && (a[i][j] > 0))
                 min1 = a[i][j];
                 }
          if (min1!=99999) {printf("%5d", min1);} 
             else {printf("    -");}
          }

return 0;
}
