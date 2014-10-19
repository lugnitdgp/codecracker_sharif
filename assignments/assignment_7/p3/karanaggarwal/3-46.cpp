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

LL A[10001];
int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        LL sum=0;
        repi(i,n){   cin>>A[i]; sum += A[i];}
        if(sum % n)
        {cout<<"ANGRY\n"; continue;}
        sum/=n;
        LL mx = 0;
        for(int i=0; i < n-1; i++)
        {
            mx = max(abs(sum-A[i]),mx);
            A[i+1] += A[i]-sum;
            A[i]=sum;
        }
        cout<<mx<<endl;
    }
    return 0;
}

