#include <stdio.h>
#include <stdlib.h>

char *str_chr(char *s, char c)
{
    int i;
    for (i = 0; s[i] != 0; i++)
        {
        if (s[i] == c) {return &s[i];}
    }
    return 0;
}

int main()
{
    char a[10] = {0},b;
    printf("Vvedite stroku:\n");
    gets(a);
    printf("Vvedite simvol:\n");
    b = getchar();
    if (str_chr(a, b) != 0) 
    {
        printf("addres: %d", str_chr(a, b));
    }
    else {printf("Error");}
    return 0;
}
