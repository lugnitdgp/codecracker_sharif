#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define gc getchar
#define ll long long int
#define M 1000000007
#define scan(t) t=input()
#define print(n) printf("%lld\n",n)
#define scans(s) scanf("%s",s)
#define nl printf("\n")
#define loop(start,k,end) for(k=start;k<end;k++)
#define ascan(a,i,l) for(i=0;i<l;i++) scan(a[i])
#define aprint(a,i,l) for(i=0;i<l;i++) print(a[i])
#define atprint(a,i,l) for(i=0;i<l;i++) printf("%lld ",a[i]); nl
inline ll input() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  ll ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

void merge(ll * ,ll ,ll ,ll );
void mergesort(ll *a,ll lb,ll ub)
{
    ll mid=(lb+ub)/2;
    if(lb<ub)
    {
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
void merge(ll *a,ll lb,ll mid,ll ub)
{
    ll c[ub-lb+1];
    ll i=0,lp=lb,up=mid+1;
    while(lp<=mid&&up<=ub)
    {
        if(a[lp]<a[up])
        {
            c[i++]=a[lp++];
        }
        else
        {
            c[i++]=a[up++];
        }
    }
    while(lp<=mid)
    c[i++]=a[lp++];
    while(up<=ub)
    c[i++]=a[up++];
    ll j;
    for(j=0;j<i;j++)
    a[j+lb]=c[j];
    return;
}
ll pw(ll a, ll b){
  ll r;
  if(b==0) return 1;
  r = pw(a,b/2);
  r = (r*r)%M;
  if(b%2) r = (r*a)%M;
  return r;
}
int main()
{
    ll t,a,x,n,i,y,k;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        char s[n+10],c[n+10];
        ll b[n+10];
        scanf("%s",s);
        scanf("%lld",&x);
        for(i=0;i<n;i++)
        {
            b[i]=s[i];
        }
        mergesort(b,0,n-1);
        for(i=0;i<n;i++)
        {
            s[i]=b[i];
        }
        a=log2(x)/log2(n);
        a++;
        for(i=1;i<a;i++)
        {
            x-=pw(n,i);
        }
        k=0;
        for(i=a-1;i>=0;i--)
        {
            y=x/pw(n,i);
            x=x%pw(n,i);
            if(i==0)
            c[k]=s[y-1];
            else
            c[k]=s[y];
            k++;
        }
        c[k]='\0';
        printf("%s\n",c);
    }
    return 0;
}
