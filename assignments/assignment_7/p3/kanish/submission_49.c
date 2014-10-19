#include<stdio.h>
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
          int n;
          scanf("%d",&n);
          
          int arr[n],i,tmp,lw,sum=0,x,c=0;
          
          for(i=0;i<n;i++)
          {
          scanf("%d",&arr[i]);
          sum=sum+arr[i];
          }
          
          x=sum/n;
          
          if(x*n!=sum)
          printf("ANGRY\n");
          
          else
          {
          for(i=0;i<n-1;i++)
          {
          for(x=i+1;x<n;x++)
          {
          if(arr[i]<arr[x])
          {
          tmp=arr[i];
          arr[i]=arr[x];
          arr[x]=tmp;
          }
          }
          }
          
          x= sum/n;
          
          for(i=0;i<n;i++)
          {
          if(x==arr[i])
          break;
          
          else
          c++;
          }     
          
          for(;i<n;i++)
          {
          if(x==arr[i])
          c++;
          
          else
          break;
          }
          
          printf("%d\n",n-c);
          
          
          
          }     
          }
          return 0;
          }