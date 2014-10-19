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
#define INF 1000000000
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
int DP[1<<16][16];
VI E[16];
int n;
queue<PII> Q;
int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        repi(i,n) E[i].clear();
        while(!Q.empty())Q.pop();
        SET(DP,-1);
        
        repi(i,n){ int x; cin>>x; E[x].PB(i);}
        DP[1][0]=0;
        Q.push(MP(1,0));
        while(DP[1<<(n-1)][n-1]==-1 && !Q.empty())
        {
            PII now = Q.front();
            Q.pop();
            int x = DP[now.F][now.S];
            int curr = now.S; 
            int mask = now.F;

            for(int i = 0 ; i < (1<<SZ(E[curr])); i++)
            {
                int newmask = mask;
                for(int j = 0 ; j < SZ(E[curr]) ; j++)
                    if( (i>>j)&1 )
                        newmask ^= 1<<E[curr][j];
                
                if(DP[newmask][curr]!=-1)continue;;
                
                DP[newmask][curr] = x;
                
                if(DP[1<<(n-1)][n-1] != -1)break;
                
                for(int j = 0 ; j < n ; j++)
                    if(DP[newmask][j]==-1 )
                    if( (newmask>>j)&1  && (newmask>>curr)&1)
                    {
                        Q.push(MP(newmask,j));
                        DP[newmask][j] = 1 + x;
                    }
            }
        }
        n--;
        if(DP[1<<n][n] == -1) 
            cout<<"HORRIBLE\n";
        else 
            cout<<DP[1<<n][n]<<endl;
    }
    return 0;
}

