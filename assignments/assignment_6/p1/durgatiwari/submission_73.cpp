#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

/*typedef long long int64;
typedef unsigned long long uint64;*/
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
/*template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}*/
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ll long long int
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define nl printf("\n")
#define pl(x) printf("%lld",x)

ll powera(int n,int x)
{
	if(x==0)return 1;
	ll loc=1;
	for(int i=0;i<x;i++)loc=loc*n;
	return loc;
}
int main()
{
	int T,n,r;
	char a[50];
	si(T);
	while(T--)
	{
		si(n);
		scanf("%s",a);
		si(r);
		ll l=0,p=0;
		ll nn=n;
		while(l<r)
		{
			p++;
			if(p!=1)nn=nn*n;
			l+=nn;
		}
		l-=nn;
		int z[p],i=0,res=0;
		ll loc=0;
		memset(z,0,sizeof(z));
		while(l<r&&i<p)
		{
			loc=powera(n,p-i-1);
			if((l+loc)>r)
			{
				i++;
			}
			else
			{
				l+=loc;
				if(l==r)break;
				z[i]++;
				if(z[i]==n)i++;
			}
		}
		sort(a,a+n);
		for(int i=0;i<p;i++)
		{
			cout<<a[z[i]];
		}
		nl;
	}
}