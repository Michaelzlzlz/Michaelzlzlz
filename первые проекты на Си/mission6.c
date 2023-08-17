#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 40 /* Число строк матрицы */
#define N 3 /* Число столбцов матрицы */

int main()
{ int k;
int itog=0;
  int a[M][N];
  int i, j, n, m;
  srand (time (NULL));
  printf("dano random tablic'a:\n");
  for(i = 0; i < M; i++)
      for(j = 0; j < N; j++)
          a[i][j] = rand()%10;

  for(i = 0; i < M; i++)
  {
      for(j = 0; j < N; j++)
          printf("%5d", a[i][j]);
      printf("\n");
          }

printf("----------------------------------");
printf("\n");

for(i = 0; i < M; i++)
  {
      for(n = 0; n < M; n++) 
      {
        k=0;
        for(j = 0; j < N; j++)
        {
        if (n!=i)
        {
                if (a[i][j]==a[n][j]) 
        {k++; if (k==N) {itog++; continue;}}
        }
        }
      }
    }
if (itog==0) {printf("NET odinakovi' stroki");}
 else {printf("DA, ect' odinakovi' strocki");}
return 0;
}
