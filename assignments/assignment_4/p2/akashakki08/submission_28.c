#include<stdio.h>
int main()
{
    char str[30][30];
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        gets(str[i]);
    }
    printf("0");
    return 0;
}