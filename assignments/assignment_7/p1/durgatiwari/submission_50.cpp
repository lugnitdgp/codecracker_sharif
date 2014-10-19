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
int a[500][500],dp[500][500],cost[500][500],cost2[500][500];
int main()
{
	int T,n;
	si(T);
	while(T--)
	{
		for(int i=0;i<50;i++)
		{
			for(int j=0;j<50;j++) dp[i][j]=-10;
		}
		
		si(n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++) si(a[i][j]);
		}
		
		for(int i=0;i<(2*n)-1;i++)
		{
			int p=i/2;
			if(i%2==0)
			{
				for(int j=0;j<n-1;j++)
				{			
					si(cost[p][j]);
				}	
			}
			else
			{
				for(int j=0;j<n;j++)
				{
					si(cost2[p][j]);
				}
			}
		}
		int loc=0;
		dp[0][0]=a[0][0];
		for(int i=1;i<n;i++)
		{
			if(a[0][i]==-1) break;
			else
			{
				loc=dp[0][i-1]-cost[0][i-1];
				if(loc>=0)
				{
					dp[0][i]=dp[0][i-1]-cost[0][i-1]+a[0][i];
				}
				else
				{
					dp[0][i]=-1;
				}
			}
		}
		
		int loc1,loc2;
		
		for(int i=1;i<n;i++)
		{
			if(a[i][0]==-1) break;
			else
			{
				loc=dp[i-1][0]-cost2[i-1][0];
				if(loc>=0)
				{
					dp[i][0]=dp[i-1][0]-cost2[i-1][0]+a[i][0];
				}
				else
				{
					dp[i][0]=-1;
				}
			}
		}
		
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<n;j++)
			{
				if(a[i][j]!=-1)
				{
					loc1=dp[i-1][j]-cost2[i-1][j];
					loc2=dp[i][j-1]-cost[i][j-1];
					dp[i][j]=0;
					dp[i][j]+=(max(loc1,loc2)+a[i][j]);
				}
				else dp[i][j]=-1;
			}
		}
		
		if(dp[n-1][n-1]>=0)
		{
			cout<<dp[n-1][n-1]<<endl;
		}
		else
		{
			cout<<"Murder"<<endl;
		}
	}
}