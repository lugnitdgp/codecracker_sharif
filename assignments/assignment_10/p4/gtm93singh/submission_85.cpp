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

map<int,int> v[100002];

int main()
{
	int t,n,i,m,j,temp,val,l,r;
	sin(t);
	while(t--)
	{
		sin(n);
		sin(m);
		fon(i,n)
		{
			if(i>0)
				v[i]=v[i-1];
			sin(temp);
			v[i][temp]++;
/*			for(map<int,int>::iterator it=v[i].begin(); it!=v[i].end(); ++it)
				cout<<"Number "<<it->first<<" count "<<it->second<<endl;
*/		}
		fon(i,m)
		{
			sin(val); sin(l); sin(r);
			l-=2; r--;
			
			if(temp=v[r][val])
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
		fon(i,n)
			v[i].clear();
	}
	return 0;
}
