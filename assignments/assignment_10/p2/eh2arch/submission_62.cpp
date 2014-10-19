
//#include<conio.h>
//0000000000000000000000000000//
//%%%%   Archit Srivastava %%%//
//        NIT Durgapur        //
//0000000000000000000000000000//
#include<ctype.h>
#include<cstdio>
#include<stdio.h>
#include<utility>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<string>
#include<set>
#include<time.h>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define mod 1000007
#define pi(n) printf("%d",n)
#define pin(n) printf("%d\n",n)
#define piw(n) printf("%d ",n)
#define pll(n) printf("%lld",n)
#define plln(n) printf("%lld\n",n)
#define pllw(n) printf("%lld ",n)
#define sll(n) scanf("%lld",&n)
#define ss(s) scanf("%s",s)
#define ps(s) printf("%s",s)
#define psn(s) printf("%s\n",s)
#define psw(s) printf("%s ",s)
#define si(n) scanf("%d",&n)
#define pn printf("\n")
#define pw printf(" ")
#define mods 1000000009

inline int ri()
{
    int n=0;char c;
    while(1)
    {
        c=getchar();//_unlocked();
        if(c=='\n'||c==' '||c==EOF)break;
        n=(n<<3) + (n<<1) +c-48;
    }
    return n;
}/*
inline long long rll()
{
    long long n=0;
    char c;
    while(1)
    {
        c=getchar_unlocked();
        if(c=='\n'||c==' '||c==EOF)break;
        n=(n<<3) + (n<<1) + c - 48;
    }
    return n;
}
*/
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef unsigned long long LL;

#define PI (3.141592653589793)
#include<fstream>

int main()
{
    int t;
    si(t);
    while(t--)
    {
        int m,n;
        si(m);si(n);
        vector< pair<int,string> > p;
        char a[10000];
        map<int,int> mp;
        int x,y;string s;
        while(m--)
        {


            si(x);
            getchar();
            cin.getline(a,50);
            //scanf("%s\n",a);
            //cout<<a;pn;
            //cin>>s;
            s=a;
            p.PB(make_pair(x,s));
        }
        while(n--)
        {
            si(x);si(y);
            mp[x]=max(mp[x],y);
        }
        sort(p.begin(),p.end());
        int i;
        rep(i,p.size())
        {
            cout<<p[i].second<<" "<<mp[p[i].first];pn;
        }
    }
}
