#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 5 /* Число строк матрицы */
#define N 6 /* Число столбцов матрицы */

int main()
{ int nechet=0;
  int a[M][N];
  int i, j, n=0;
  srand (time (NULL));
  printf("dano random tablic'a:\n");
  for(i = 0; i < M; i++)
      for(j = 0; j < N; j++)
          a[i][j] = rand()%100;

  for(i = 0; i < M; i++)
  {
      for(j = 0; j < N; j++)
          printf("%5d", a[i][j]);
      printf("\n");
          }

printf("----------------------------------");
printf("\n");

   for (j=0; j<N; j++)
   {nechet=0;

            for (i=0; i<M; i++){
                if (a[i][j]%2==1){nechet++;} else {break;}
                if (nechet==M){n=j+1; continue;}
                }
   }

       if (n!=0) {printf("nechetni' stolbik:%d", n);}
        else {printf("NOT nechetni' stolbik");}
return 0;
}
