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
LL C1[110][110];
LL C2[110][110];
LL dp[110][110];
LL P[110][110];
#define inf (1<<30)
int main()
{
	int Cases = 1;
	cin>>Cases;
	for(int Case = 0;Case<Cases;Case++)
	{
		int N;
		cin>>N;
		for(int i = 1;i<=N;i++)
		{
			for(int j = 1;j<=N;j++)
			{
				cin>>P[i][j];
			}
		}
		for(int i = 1;i<=N-1;i++)
		{
			for(int j = 1;j<=N-1;j++)
				cin>>C1[i][j+1];
			for(int j = 1;j<=N;j++)
				cin>>C2[i+1][j];
		}
		for(int j = 1;j<=N-1;j++)
			cin>>C1[N][j+1];
		memset(dp,0,sizeof(dp));
		int F = 0;
		for(int i = 1;i<=N;i++)
		{
			for(int j = 1;j<=N;j++)
			{
				if(P[i][j]==-1){
					dp[i][j] = -inf;
					continue;
				}
				dp[i][j] = max(dp[i-1][j] - C2[i][j],dp[i][j-1] - C1[i][j]);
				if(dp[i][j]<0)
					F = 1;
				dp[i][j]+=P[i][j];
			}
		}
		if(dp[N][N]<0)
			F = 1;
		cout<<endl;
		if(F==1)
			cout<<"MURDER"<<endl;
		else
			cout<<dp[N][N]<<endl;
	}
	cout<<endl;
	return 0;
}