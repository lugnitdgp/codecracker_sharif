	#include<stdio.h>
	int main()
	{
	int t,j,i,u[99],p=0,x[99];
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
	x[j]=1;
	else
	x[j]=2;
	p=0;
	}

	for(i=0;x[i]!=0 ;i++)
	   {
	   if (x[i]==1)
	   printf("YES\n");
	   else if (x[i]==2)
	   printf("NO\n");
	}
	return 0;
	}