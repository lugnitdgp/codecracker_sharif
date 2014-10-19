
#include<stdio.h>
#include<math.h>
int fact(int);
int main()
{
	long int t;
	int n,k, d,sum=0,i,f,g;
	
	scanf("%ld",&t);
	for(i=0;i<t;i++)
	{


		scanf("%d %d",&n,&k);




		if(k==1)
		{
			printf("1");

		}
		else if(k>=n)
		{
			g=pow(2,(n-1));
			printf("%d",g);

		}
		else
		{
			while(k<n-1)
			{
			    d=(fact(n-k)/fact(n-(k+1)));
			    sum+=d;
			    k=k+1;
			}
		      f=(pow(2,(n-1))-1-sum);
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