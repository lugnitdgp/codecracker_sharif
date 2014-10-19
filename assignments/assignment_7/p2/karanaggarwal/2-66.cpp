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
#define inf  10000000000000000ll
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
LL DP[1<<21][2];
LL A[21];
int n;
LL f(int mask , int side)
{
    if(DP[mask][side]!=-1) return DP[mask][side];
    DP[mask][side] = inf;
    if(side==1)
    {
        repi(i,n)
        {
            if(((mask>>i)&1) != side)
                continue;
            DP[mask][side] = min(DP[mask][side] , A[i] + f(mask - (1<<i),1-side));
            for(int j = i+1; j < n ; j++)
                if(((mask>>j)&1) == side)
                    DP[mask][side] = min(DP[mask][side] , max(A[j],A[i]) + f(mask - (1<<i) - (1<<j),1-side));
        }
    }
    if(side==0)
    {
        repi(i,n)
        {
            if(((mask>>i)&1) != side)continue;
            DP[mask][side] = min(DP[mask][side] , A[i] + f(mask + (1<<i),1-side));
            for(int j = i+1; j < n ; j++)
                if(((mask>>j)&1) == side)
                    DP[mask][side] = min(DP[mask][side] , max(A[j],A[i]) + f(mask + (1<<i) + (1<<j),1-side));
        }
    }
    return DP[mask][side];
}
int main()
{
    int t;
    cin>>t; while(t--)
    {
        cin>>n;
        repi(i,n) cin>>A[i];
        SET(DP,-1);
        DP[0][0]=0;
        cout<<f((1<<n)-1,1)<<endl;

    }
    return 0;
}

