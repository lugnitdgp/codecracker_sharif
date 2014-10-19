#include<stdio.h>
int main()
{
	int t,s[26]={0};
	scanf("%d",&t);
	int n,l,k,i,r;
	char c,b[26],res[1000000];
	while(t--)
	{
		scanf("%d",&l);
		getchar();
		for(i=0;i<l;i++)
		{
			c=getchar();
			s[c-'a']+=1;
		}
		scanf("%d",&n);
		l=1;
		for(i=0;i<26;i++)
		{
			if(s[i]==1)
			{
				b[l]=i+'a';
				l=l+1;
			}
			s[i]=0;
		}
		k=0;
		l=l-1;
		while(n!=0)
		{
			r=n%l;
			n=n/l;
			if(r==0)
				r=l;
			res[k]=b[r];
			k=k+1;
		}
		res[k]='\0';
		for(i=k-1;i>=0;i--)
		{
			printf("%c",res[i]);
		}
		printf("\n");
	}
	return 0;
}
