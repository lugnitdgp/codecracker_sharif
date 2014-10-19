#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;

int main()
{
	int t,arr[26];
	char zrr[26];
	long long int i,k,l,temp,r,sum,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&l);
		scanf("%s",zrr);
		scanf("%lld",&r);
		k=strlen(zrr);
		sort(zrr,zrr+k);
//		for(i=0;i<k;i++)
//			printf("%d ",zrr[i]);
//		printf("\n");
		temp=(r-1)%l;
		sum=(r-1)/l;
		for(i=0;i<=sum;i++)
			printf("%c",zrr[temp]);
		printf("\n");
		for(i=0;i<k;i++)
			zrr[i]=0;
	}
	return 0;
}
