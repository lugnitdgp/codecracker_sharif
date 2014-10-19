#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

#define MAX9 1000000007
#define MAX6 1000005
#define MAX5 100005

#define sin(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sst(x) scanf("%s",x)

#define pin(x) printf("%d",x)
#define pll(x) printf("%lld",x)
#define pst(x) printf("%s",x)
#define nl() printf("\n")
#define psp() printf(" ")

#define fon(x,n) for(x=0;x<n;x++)

int main()
{
	int t,n,i,m,j,temp,val,l,r;
	sin(t);
	while(t--)
	{
		sin(n);
		sin(m);
		map<int,int> v[n];
		sin(temp);
		v[0][temp]++;
		for(i=1;i<n;i++)
		{
			v[i]=v[i-1];
			sin(temp);
			v[i][temp]++;
		}
		fon(i,m)
		{
			sin(val); sin(l); sin(r);
			l-=2; r--;
			temp=v[r][val];
			if(temp!=0)
			{
				printf("Yes ");
				if(l>=0)
					j=temp-v[l][val];
				else
					j=temp;
				pin(j);nl();
			}
			else
			{
				printf("No 0\n");
			}
		}
	}
	return 0;
}
