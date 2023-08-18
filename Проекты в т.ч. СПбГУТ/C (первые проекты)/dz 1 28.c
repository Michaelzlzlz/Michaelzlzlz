#include <stdio.h>
#include <stdlib.h>
#define N 999999
int count_digits(char* s)
{ 
int i=0;
int v=0;
while(s[i]!='\0')
    { 
    if ((s[i]=='1')||(s[i]=='2')||(s[i]=='3')||
    (s[i]=='4')||(s[i]=='5')||(s[i]=='6')||
    (s[i]=='7')||(s[i]=='8')||(s[i]=='9')||
    (s[i]=='0')){v++;}
    i++;
    }
return v;
}


int main()
{
int n;
char c[N];
n = scanf("%s", c);

printf("%d", count_digits(&c));
return 0;
}
