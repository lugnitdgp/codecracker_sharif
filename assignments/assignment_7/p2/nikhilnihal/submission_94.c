#include<stdio.h>



int main()
{
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
              int n,y,temp,x=0,i,sum=0,j=0; 
              scanf("%d",&n);
              int a[n];
    
              for(i=0;i<n;i++)
              {
              scanf("%d",&a[i]);
              }
              
             for(i=n-2;i>=0;i--){
      for(j=0;j<=i;j++){
           if(a[j]>a[j+1]){
               temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;
           }
      }
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
              printf("%d\n",sum);
              
    }
    return 0;
}                    
