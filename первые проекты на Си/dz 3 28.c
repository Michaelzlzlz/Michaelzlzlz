#include <stdio.h>
#include <stdlib.h>

int fatoi (const char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
    printf("%d ", (int)str[i]);
    }
}


int main()
{
char str[] = "ia molodec";
fatoi(str);
return 0;
}
