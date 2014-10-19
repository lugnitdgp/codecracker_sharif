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
#include <queue>
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
bool vis[16][1<<16];
int X[16];
struct state
{
	int mask,idx,cost;
	state(int _x, int _y,int _z)
		: mask(_x), idx(_y),cost(_z) {}
	bool operator < (const state &s) const {
		return cost > s.cost;
	}
};
int main()
{
	int Cases = 1;
	cin>>Cases;
	for(int Case = 0;Case<Cases;Case++)
	{
		int N;
		cin>>N;
		memset(vis,false,sizeof(vis));
		for(int i = 0;i<N;i++)
		{
			cin>>X[i];
		}
		priority_queue<state> Q;
		int F = 0,mask,idx,C;
		int val = (1<<(N-1)); 
		Q.push(state(1|(1<<X[0]),0,0));
		while(!Q.empty())
		{
			mask = Q.top().mask;
			idx = Q.top().idx;
			C = Q.top().cost;
			Q.pop();
			if(mask&val){

				cout<<2*C+(idx!=N-1)<<endl;
				F = 1;
				break;
			}
			if(vis[idx][mask])
				continue;
			vis[idx][mask] = true;
			for(int i = 0;i<N;i++)
			{
				if(mask&(1<<i))
				{
					int M = mask|(1<<X[i]);
					Q.push(state(M,i,C + 1));
				}
			}
		}
		if(F==0)
			cout<<"HORRIBLE"<<endl;

	}
}
