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

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

LL DP[25][25];
LL E[25][25];
LL S[25][25];
LL P[25][25];
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int i,j;
        rep(i,n) rep(j,n) cin>>P[i][j];
        SET(DP,-1);
        DP[0][0]=P[0][0];
        rep(i,2*n-1)
        {
            if(i&1)
            {
                rep(j,n)
                    cin>>S[i/2][j];
            }
            else
            {
                rep(j,n-1)
                    cin>>E[i/2][j];
            }
        }
        for(i=1;i<n;i++)
            if(P[0][i]!=-1 && DP[0][i-1]-E[0][i-1] >=0)
                DP[0][i] = P[0][i] + (DP[0][i-1]  - E[0][i-1]);
        for(i=1;i<n;i++)
            if(P[i][0]!=-1 && DP[i-1][0]-S[i-1][0] >= 0)
                DP[i][0] = P[i][0] + (DP[i-1][0] - S[i-1][0]);
        for(i=1;i<n;i++)
            for(j=1; j<n; j++)
            {
                if(P[i][j]==-1)continue;
                if(DP[i][j-1]-E[i][j-1]>=0)
                    DP[i][j] = P[i][j] + (DP[i][j-1] - E[i][j-1]);
                if(DP[i-1][j]-S[i-1][j]>=0)
                        DP[i][j] = max(DP[i][j] , P[i][j] + (DP[i-1][j] - S[i-1][j]));
            }
        n--;
        if(DP[n][n]==-1) cout<<"MURDER\n";
        else cout<<DP[n][n]<<endl;
    }
    return 0;
}

