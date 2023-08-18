#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 5 /* Число строк матрицы */
#define N 6 /* Число столбцов матрицы */

int main()
{
int min1;
int max1;
int a[M][N];
int i, j;
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

printf("\n---------------------------------\n");
for (j=0; j<M; j++){min1 = 999; max1 = 0;
     for (i=0; i<N; i++)
    {
       if (a[j][i] < min1){min1 = a[j][i];}
       if (a[j][i] > max1){max1 = a[j][i];}
      }
      for (i=0; i<N; i++)
      {
      if (a[j][i] == min1) {a[j][i] = max1;}
      else if (a[j][i] == max1) {a[j][i] = min1;}
     }
   }

printf("\n new tablica:\n");

for(i = 0; i < M; i++)
{
   for(j = 0; j < N; j++)
       printf("%5d", a[i][j]);
       printf("\n");}
return 0;
}
