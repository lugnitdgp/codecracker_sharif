#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define CLR(a) a.clear()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define FORi(i,a,b) for(LET(i,a) ; i<b; i++)
#define repi(i,n) FORi(i,(__typeof(n))0,n)
#define FOR(i,a,b) for(i=a ; i<b; i++)
#define rep(i,n) FOR(i,0,n)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pi(n) printf("%d",n)
#define piw(n) printf("%d ",n)
#define pin(n) printf("%d\n",n)
using namespace std;
#define mod 1000000007
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
LL DP[1001][1001];
LL DP2[1001][1001];
int main()
{
    SET(DP,0);
    SET(DP2,0);
    DP[0][0]=1;
    DP2[0][0] = 1;
    int n,k;
    for(k = 1 ; k < 1001; k++) 
        DP2[0][k] = DP2[0][k-1] + DP[0][k];
    for(int n = 1; n < 1001 ; n++)
    {   
        DP[n][0] = 0;
        DP[n][1] = 1;
        for(k=2; k <= n; k++)
            DP[n][k] = DP2[n-k][k];
        for(k=1; k < 1001; k++)
            DP2[n][k] = DP[n][k] + DP2[n][k-1]; if(DP2[n][k] >= mod) DP2[n][k]-=mod;
    }
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>k; n-=2;
        cout<<DP[n][k]<<endl;
    }
    return 0;
}

