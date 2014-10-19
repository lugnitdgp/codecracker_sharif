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
        int n,m,x=-1,y=-1,v,x_m=-1,y_m=-1,flag=0;
        LL v_max=-1;
        map<int,LL> xs,ys;
        si(n);
        si(m);
        while(m--)
        {
            si(x);si(y);si(v);
            xs[x]+=v;
            xs[y]+=v;

        }
        map<int,LL>::iterator i;
        for(i=xs.begin();i!=xs.end();i++)
        {
            if((LL)(i->second)==v_max)
            {
                flag=1;
            }
            else if((i->second)>v_max)
            {
                flag=0;
                x=i->first;
            }
            //v_max=max((i->second),v_max);
            if(v_max>(LL)(i->second))
            {
                v_max=(i->second);
            }
        }
        int row=0;
        for(i=ys.begin();i!=ys.end();i++)
        {
            if((LL)(i->second)==v_max)
            {
                flag=1;
            }
            else if((LL)(i->second)>v_max)
            {
                row=1;
                flag=0;
                y=i->first;
            }
            //v_max=max((i->second),v_max);
            if(v_max>(LL)(i->second))
            {
                v_max=(i->second);
            }
        }
        if(flag)
        {
            printf("Bad luck");
        }
        else
        {
            if(!row)
            {
                printf("Row %d",x);

            }
            else
                printf("Column %d",y);
        }
        pn;
    }
}
