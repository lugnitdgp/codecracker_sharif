#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int i,j=0,k=0,l,m,n,T,x,y,z,max1=0,max2=0;
	long long int **a;
	scanf("%lld",&T);
	while(T--){
	
	 scanf("%lld %lld",&n, &m);
	a=(long long int**)malloc(n*sizeof(long long int*));
	for(i=0;i<n;i++){
	
	*(a+i)=(long long int*)malloc(2*sizeof(long long int));
	a[i][0]=0;
	a[i][1]=0;
}
	for(i=0;i<m;i++)
	{
		scanf("%lld %lld %lld", &x,&y,&z);
		a[x-1][0]=a[x-1][0]+z;
		a[y-1][1]=a[y-1][1]+z;
		//printf("%lld %lld\n", a[x-1][0],a[y-1][1]);
	}
	max1=0;
	max2=0;
	k=0;
	for(i=0;i<n;i++)
	{
		if(a[i][0]>a[max1][0])
		{
			max1=i;
		    k=0;	
		}
		if(a[i][0]==a[max1][0])
		j++;
	}
	for(i=0;i<n;i++)
	{
		if(a[i][1]>a[i][1])
		{
			max1=i;
			max2=1;
			k=1;
		}
		if(a[i][1]==a[max1][k])
		{
			j++;
		}
	}
		if(j>1)
		printf("Bad luck");
		else if(k==0)
		printf("Row %lld",max1+1);
		else
		printf("Column %lld",max1+1);
}
		return 0;

	}
        	
        