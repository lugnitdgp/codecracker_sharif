
/* Author : Vineet Kumar */
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
using namespace std;

#define FOR(i,a,b) 	for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) 	FOR(i,0,n)
#define INF		INT_MAX
#define ALL(x) 		x.begin(),x.end()
#define LET(x,a)	__typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v) 	IFOR(it,v.begin(),v.end())
#define pb 		push_back
#define sz(x) 		int(x.size())
#define mp 		make_pair
#define fill(x,v)	memset(x,v,sizeof(x))
#define max(a,b)	((a)>(b)?(a):(b))
#define min(a,b)	((a)<(b)?(a):(b))
#define	si(n)		scanf("%d",&n)
#define pi(n)		printf("%d ",n)
#define pil(n)		printf("%d\n",n)
#define sd(n)		scanf("%lf",&n)
#define sl(n)		scanf("%lld",&n)
#define pl(n)		printf("%lld\n",n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
vector<LL> q,fac;
void pre()
{
	fac.pb(1);
	fac.pb(1);
	FOR(i,2,26)
		fac.pb(fac.back()*i);
}

string comp(LL req,string g, string ans,int l,int n)
{
	if(l<=0 || n<=0)
		return ans;
	int j = 0;
	LL x = 0;
	while(j<n)
	{
		x = pow(n,l-1);
		if(req<=x)
		{
			//cout <<"inside j: " << j << " ans: " << ans << "req: " << req << " x: " << x << endl;
			ans += g[j];
			ans = comp(req,g,ans,l-1,n);
			return ans;
		}
		req -= pow(n,l-1);
		j++;
		//cout <<"out j: " << j << " ans: " << ans << "req: " << req << " x: " << x << endl;
	}
	return ans;
}	
int main()
{
	int i,j,n,t;
	pre();
	string s;
	for(si(t);t--;)
	{
		si(n);
		cin >> s;
		sort(ALL(s));
		si(j);
		LL x = n;
		string ans = "";
		int l = 1;
		while(1)
		{
			if(j<=x)
			{
				ans = comp(j,s,ans,l,n);
				break;
			}
			j -= x;
			x *= n;
			l++;
			if(x>1000000009)
				break;
		}
		cout << ans << endl;
	}
	return 0;
}
