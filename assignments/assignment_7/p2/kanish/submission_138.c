#include<stdio.h>

int main()
{
 int t;
 scanf("%d\n",&t);
 while(t--)
 {
   int i,n,sum=0;
   scanf("%d",&n)
    int a[n];
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
    for(i=1;i<n-1;i++)
    {
    sum=sum+a[i];
    }
    sum=sum+sum*a[0]+a[n-1]+2*a[0];
    printf("%d\n",sum);
 }
 return(0);
}
