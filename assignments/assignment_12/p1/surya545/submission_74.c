
#include<stdio.h>
#include<math.h>
int fact(int);
int main()
{
	long int t;
	int n[10000],k[10000], d,sum=0,i,f,g;
	scanf("%ld",&t);
	for(i=0;i<t;i++)
	{


		scanf("%d %d",&n[i],&k[i]);



	 }
	 for(i=0;i<t;i++)
  {		if(k[i]==1)
		{
			printf("1");

		}
		else if(k[i]>=n[i])
		{
			g=pow(2,(n[i]-1));
			printf("%d",g);

		}
		else
		{
			while(k[i]<n[i]-1)
			{
			    d=(fact(n[i]-k[i])/fact(n[i]-(k[i]+1)));
			    sum+=d;
			    k[i]=k[i]+1;
			}
		      f=(pow(2,(n[i]-1))-1-sum);
		      printf("%d",f);

		}
		printf("\n");
	}

       return 0;
}
int fact(int n)
{       int fact=1;
	while(n>=1)
	{
		fact=fact*n;
		n--;
	}
	return fact;
}