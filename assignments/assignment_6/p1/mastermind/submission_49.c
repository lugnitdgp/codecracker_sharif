#include<stdio.h>
#include<string.h>
int main()
{
 int t,l,m=0;
 scanf("%d",&t);
 char res[t];
 long long int r,i,j;
 while(t--)
 {
     scanf("%d",&l);
     char w[l],temp;
     scanf("%s",w);
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
          if(j==l&&(i+1)!=r)
          j=0;
      }
      res[m]=w[j-1];m++;
 }
 for(i=0;i<m;i++)
 printf("\n%c",res[i]);
 return 0;
}
