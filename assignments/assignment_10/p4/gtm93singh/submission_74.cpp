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
		vector< map<int,int> >v;
		sin(n);
		sin(m);
		fon(i,n)
		{
			v.push_back(map<int,int>());
			map<int,int>& map=v[i];
			map=v[i-1];
			sin(temp);
			map[temp]++;
		}
		fon(i,m)
		{
			sin(val); sin(l); sin(r);
			l-=2; r--;
			map<int,int>& mp1=v[r];
			j=0;
			if(l>=0)
			{
				map<int,int>& mp2=v[l];
				j=j-mp2[val];
			}
			if(mp1[val])
			{
				printf("Yes ");
				j+=mp1[val];
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
