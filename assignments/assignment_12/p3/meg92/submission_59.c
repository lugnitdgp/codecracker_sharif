#include<stdio.h>
#include<string.h>
void main()
{
  int t,i,out=0;
  char str[101];
  scanf("%d",&t);
  while(t--)
  {
   scanf("%s",str);
   for(i=0;i<strlen(str);i++)
   {
     if(str[i]=='D'|| str[i]=='0'||str[i]=='j')
     out=out+1;
     
   }
   if(out>0)
   printf("YES\n");
   else 
   printf("NO\n");
   out=0;
  }
}
