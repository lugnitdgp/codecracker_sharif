#include<stdio.h>

int main()
{
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
              int n,x=0,i,sum=0; 
              scanf("%d",&n);
              int a[n];
              for(i=0;i<n;i++)
              {
              scanf("%d",&a[i]);
              }
              for(i=1;i<n-2;i++)
              {
                 sum=sum+a[i];
                 x++;
              }
              sum=sum+a[0]*(x)+a[n-1]+2*a[1];
              printf("%d\n",sum);
              
    }
    return 0;
}                    
