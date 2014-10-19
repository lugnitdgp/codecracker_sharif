	#include<stdio.h>
	int main()
	{
	int t,j,i,u[99],p=0;
	char s[99];
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++)
	{
			u[i]=s[i];
		  if(u[i] <= 122 && u[i]  >= 43)
		  {
		  continue;
		  }
		  else
			p++;
	}
	if(p==0)
	printf("YES\n");
	else
	printf("NO\n");
	p=0;
	}
	return 0;
	}