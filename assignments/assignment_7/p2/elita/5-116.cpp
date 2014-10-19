#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int i,n,j,k,l,*a,T,sum=0;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		a=(long long int*)malloc(n*sizeof(long long int));
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			
		}
		//printf("a");
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				if(a[i]>a[j])
				{
					l=a[i];
					a[i]=a[j];
					a[j]=l;
					
				}
			}
		}
		sum=0;
		//printf("%lld",n);
		if(n%2==0)
		{
			for(i=1;i<n;i=i+2)
			{
				sum=sum+a[i];
				
			}
		   sum=sum+a[0]*(n/2-1)+a[1]*2*(n/2-1);
		   
		}
		else if((n%2!=0)&&(n!=1))
		{
			sum=a[1];
			for(i=4;i<n;i=i+2)
			{
				sum=sum+a[i];
			}
			sum=sum+a[0]*((n-1)/2)+a[2]+a[1]*2*((n-1)/2-1);
			
			
		}
		else
		{
			sum=a[0];
		}
		printf("%lld\n",sum);
	}

	return 0;
}
