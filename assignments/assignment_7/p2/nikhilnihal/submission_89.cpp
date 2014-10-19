#include<stdio.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
             long long  int n,x=0,i,sum=0; 
              scanf("%lld",&n);
              int a[n];
    
              for(i=0;i<n;i++)
              {
              scanf("%d",&a[i]);
              }
    qsort(a, n, sizeof(int), cmpfunc);              
              if(n==1)
              {
                      sum=a[0];
                goto A;      
              }
              else if(n==2)
              {
                   sum=a[1];
                    goto A;
                   
              }
               else if(n==3)
              {
                   sum=a[2]+a[0]+a[1];
                    //printf("%d\n",sum);
                goto A;
              }
                   
              for(i=1;i<n-2;i++)
              {
                 sum=sum+a[i];
                 x++;
              }
              sum=sum+a[0]*(x)+a[n-1]+2*a[1];
              A:
              printf("%lld\n",sum);
              
    }
    return 0;
}                    
