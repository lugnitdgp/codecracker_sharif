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
#define pi(x) printf("%d ",x);
#define nl printf("\n");
#define pl(x) printf("%lld",x);
#define mod 1000000007
int dp[5010][5010];
int sum[5010][5010];
int main()
{
	int T;
	si(T);
	while(T--)
	{
		int n,k;
		si(n);si(k);
		n-=2;
		for(int i=0;i<=n;i++)for(int j=0;j<=k;j++)sum[i][j]=0;
		for(int i=1;i<=k;i++)sum[0][i]=1;
		for(int i=0;i<=n;i++)for(int j=0;j<=k;j++)dp[i][j]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				dp[i][j]=sum[i-j][j];
			}
			for(int j=1;j<=k;j++)
			{
				sum[i][j]=(sum[i][j-1]+dp[i][j]);
				if(sum[i][j]>=mod)sum[i][j]%=mod;
			}
		}
		pi(dp[n][k]);nl;
	}
}
