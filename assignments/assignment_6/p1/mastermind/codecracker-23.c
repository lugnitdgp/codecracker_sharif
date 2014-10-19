#include<stdio.h>
#include<string.h>
int main()
{
 int t,l;
 scanf("%d",&t);
 long long int r,i,j;
 while(t--)
 {
     scanf("%d",&l);
     char w[l],temp;
     fflush(stdin);
     gets(w);
     scanf("%lld",&r);
     for(i=0;i<l;i++)
       {
           for(j=i;j<l;j++)
           {
               if(w[i]>w[j])
               {temp=w[i];w[i]=w[j];w[j]=temp;}

           }
       }
        j=0;
      for(i=0;i<r;i++)
      {    j++;
          if(j==l)
          j=0;
      }
      printf("\n%c",w[j-1]);
 }
 return 0;
}



