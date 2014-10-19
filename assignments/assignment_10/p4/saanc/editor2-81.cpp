#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<deque>
#include<queue>
#include<set>
#include<vector>
#include<stack>
#include<map>
#include<list>
#include<functional>


using namespace std;

#define loop(i,n) for(i=0;i<n;i++)
#define loop1(i,n) for(i=1;i<=n;i++)
#define loop2(i,n,k) for(i=n;i<k;i++)
#define loop3(i,n,k) for(i=n;i<=k;i++)
#define loopr(i,n,k) for(i=n;i>=k;i--)
#define si(n) scanf("%d",&n)
#define sli(n) scanf("%ld",&n)
#define slli(n) scanf("%lld",&n)
#define fast(n) n=input()
#define sc(n) scanf("%c",&n)
#define ss(n) scanf("%s",n)
#define sf(n) scanf("%f",&n)
#define slf(n) scanf("%lf",&n)
#define sllf(n) scanf("%llf",&n)
#define pin(n) printf("%d\n",n)
#define pfn(n) printf("%f\n",n)
#define psn(n) printf("%s\n",n)
#define pcn(n) printf("%c\n",n)
#define pcw(n) printf("%c ",n)
#define ps(n) printf("%s",n)
#define pc(n) printf("%c",n)
#define piw(n) printf("%d ",n)
#define pfw(n) printf("%f ",n)
#define psw(n) printf("%s ",n)
#define plin(n) printf("%ld\n",n)
#define pdn(n) printf("%lf\n",n)
#define pliw(n) printf("%ld ",n)
#define pdw(n) printf("%lf ",n)
#define pllin(n) printf("%lld\n",n)
#define pldn(n) printf("%llf\n",n)
#define plliw(n) printf("%lld ",n)
#define pldw(n) printf("%llf ",n)
#define pw printf(" ")
#define pn printf("\n")


#define MAX 1000000


 typedef long long int LL;
 typedef long int L;
 typedef long double LD;
 typedef unsigned long long int ULL;
/*
 inline int input() {
 char c = getchar();
 while(c<'0' || c>'9') c = getchar();
 int ret = 0;
 while(c>='0' && c<='9') {
 ret = 10 * ret + c - 48;
 c = getchar();
 }
 return ret;
 }
*/
int a[100003];
int s[103][100003];
int main()
{
int i,j,k,b,c,l,n,m,t,q,p;
si(t);
while(t--)
{
loop(i,102)
{
    loop(j,100002)
    s[i][j]=0;
}

    si(n);
    si(m);

    loop(i,n)
    {
        si(a[i]);
        s[i/1000][a[i]]+=1;
    }
    loop(p,m)
    {
        LL sum=0;
        si(k);
        si(b);
        si(c);
        l=(b-1)/1000;
        q=(c-1)/1000;

        if(q>l)
        {
            loop3(i,l,q)
            sum+=s[i][k];
            if(sum==0)
            {
                psn("No 0");
                continue;
            }
            else
            {
                loop3(i,l*1000,b-2)
                {
                if(a[i]==k)
                    sum-=1;
                }
                loop3(i,c,q*1000+999)
                {
                    if(a[i]==k)
                    sum-=1;
                }
            }
            if(sum<=0)
            {
                psn("No 0");
            }
            else
            {
                psw("Yes");
                pllin(sum);
            }

        }
        else
        {
            loop3(i,b-1,c-1)
            {
                if(a[i]==k)
                    sum+=1;            }

             if(sum<=0)
            {
                psn("No 0");
            }
            else
            {
                psw("Yes");
                pllin(sum);
            }

        }

    }

}
return 0;
}
