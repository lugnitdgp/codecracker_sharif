#include<stdio.h>



int main()
{
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
             long long  int n,y,temp,x=0,i,sum=0,j=0; 
              scanf("%lld",&n);
              int a[n];
    
              for(i=0;i<n;i++)
              {
              scanf("%d",&a[i]);
              }
              
                                       
                                       
                                                  
               
              if(n==1 || n==2)
              {
                      sum=a[n-1];
                goto A;      
              }
              
               else if(n==3)
              {
                   sum=a[2]+a[0]+a[1];
                    
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
