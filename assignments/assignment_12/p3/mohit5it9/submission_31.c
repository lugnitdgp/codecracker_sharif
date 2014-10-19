#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int t,i,len;
scanf("%d",&t);
while(t--)
{
char str[100];int flag=0;
scanf("%s",&str);
len=strlen(str);
for(i=0;i<len;i++)
{
if(str[i]=='D' || str[i]=='J' || str[i]-48==0)
{
flag=1;break;
}
}
if(flag==1)
	printf("YES\n");
else printf("NO\n");
}
}