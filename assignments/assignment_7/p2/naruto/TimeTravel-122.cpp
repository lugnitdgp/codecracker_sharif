#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <time.h>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <climits>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define LD long double
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define ss(n) scanf("%s",n)
#define pnl printf("\n")
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
#define DB(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";
#define CL(a,b) memset(a,b,sizeof(a))
#define GOLD ((1+sqrt(5))/2)
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
void swaps (char *x,char *y){char temp;temp=*x;*x=*y;*y=temp;}
void swapi(int *a,int *b){int temp;temp=*a;*a=*b;*b=temp;}
ULL gcd(ULL a,ULL b){if(a==0)return b;if(b==0)return a;if(a==1||b==1)return 1;
if(a==b)return a;if(a>b)return gcd(b,a%b);else return gcd(a,b%a);}
int dp[1<<20];
int X[21];
int main()
{
	int Cases = 1;
	cin>>Cases;
	for(int Case = 0;Case<Cases;Case++)
	{
		int N;
		cin>>N;
		for(int i = 0;i<N;i++)
		{
			cin>>X[i];
		}
		if(N==1)
		{
			cout<<X[0]<<endl;
			continue;
		}
		queue<int> Q;
		sort(X,X+N);
		Q.push(0);
		memset(dp,-1,sizeof(dp));
		dp[0] = 0;
		int mask;
		while(!Q.empty())
		{
			mask = Q.front();
			Q.pop();
			for(int i = 0;i<N;i++)
			{
				if((1<<i)&mask)
					continue;
				for(int j = i+1;j<N;j++)
				{
					if(mask&(1<<j))
						continue;
					int val = mask | (1<<i) | (1<<j);
					int V = max(X[i],X[j]);
					int p = __builtin_popcount(val);
					if(p==N)
					{
						if(dp[val]==-1||dp[val]>dp[mask]+V)
							dp[val] = dp[mask] + V;
					}
					for(int k = 0;k<N;k++)
					{	
						if(val&(1<<k)){
							val^=(1<<k);
							V+=X[k];
							break;
						}
					}
					if(dp[val]==-1||dp[val]>dp[mask]+V)
					{
						dp[val] = dp[mask] + V;
						Q.push(val);
					}
				}
			}
		}
		cout<<dp[(1<<N) - 1]<<endl;
	}
}