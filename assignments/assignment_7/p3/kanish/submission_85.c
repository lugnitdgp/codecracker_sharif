#include<stdio.h>
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
          int n;
          scanf("%d",&n);

          int arr[n],i,j,tmp=0,temp=0,lw,sum=0,x,c=0,a=0,b=0;

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


           temp=0;tmp=0;
           for(j=c-1;j>=0;j--)
           temp=temp+arr[j];

          //printf("hii %d",temp);
            a=c;

            for(j=c;j<n;j++)
            {
            if(arr[j]!=x)
            {
            tmp=tmp+arr[j];
            b++;
            }
            }
          if(b>a)
          {

          temp=(temp-tmp)/x;
          //  printf("\n %d",temp);
          temp=temp+b-a+1;

          printf("%d\n",temp);
          }
          else
          {

          temp=(temp-tmp)/x;

          printf("%d\n",temp);

          }

          }
          }
          return 0;
          }
