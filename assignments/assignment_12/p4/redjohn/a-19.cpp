#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>

using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> II;
typedef vector<II> VII;
typedef vector<VII> VVII;
typedef vector<VI> VVI;



#define SS(n) scanf("%s",n)
#define pn puts("");
#define ps putchar(' ')
#define sz(s) int((s).size())
#define rep(i,a,b) for(int(i)=a;(i)<=(b);++(i))
#define per(i,b,a) for(int(i)=b;(i)>=(a);--(i))
#define clr(a) memset(a,0,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef long long LL; typedef vector <int> vi; typedef pair<int,int> pii; typedef map <int,int> mii; template <class T> inline T max(T a,T b,T c) {return (max(max(a,b),c));} template <class T> inline T min(T a,T b,T c) {return (min(min(a,b),c));} template <class T> inline T sqr(T x) {return x*x;} inline int inp() {int n=0,s=1;char p=getchar();if(p=='-')s=-1;while((p<'0'||p>'9')&&p!=EOF&&p!='-')p=getchar();if(p=='-')s=-1,p=getchar();while(p>='0'&&p<='9')n=(n<<3)+(n<<1)+(p-'0'),p=getchar();return n*s;} void out(int x){if(x<0)putchar('-'),x=-x;int ll=0,dd[10];while(x)dd[ll++]=x%10,x/=10;if(!ll)dd[ll++]=0;while(ll--)putchar(dd[ll]+48);} inline int ins(int x,int y,int m,int n){return (x>=1&&x<=m&&y>=1&&y<=n);} template <class T> inline T gcd(T a,T b){return (!b? a : gcd(b,a%b));} template <class T> inline T ABS(T x){return ((x)>0?(x):(-(x)));}
const int N = 250 + 11;


char str[N][N];
bool vis[N][N];
int row,col,szz;
void dfs(int x, int y, char idx) {
	if(str[x][y] != idx || !ins(x,y,row,col) || vis[x][y]) return;
	vis[x][y] = 1;
	++szz;
	dfs(x+1,y,idx), dfs(x-1,y,idx), dfs(x,y+1,idx), dfs(x,y-1,idx);
}
	

int main()
{
	int testCase, t=inp();
	for(testCase=1; testCase<=t; ++testCase)
	{
		clr(vis);
		row = inp(), col = inp();
		for(int i=1; i<=row; ++i) SS(str[i]+1);
		vector <pii> v;
		for(int i=1; i<=row; ++i) {
			for(int j=1; j<=col; ++j) {
				if(!vis[i][j]) {
					char num = str[i][j];
					szz = 0;
					dfs(i,j,num);
					v.pb(mp(szz, num-48));
				}
			}
		}
		sort(all(v)), reverse(all(v));
		pii ans = v[0];
		int cnt = 1;
		for(int i=1; i<sz(v); ++i) {
			if(v[i].ff == ans.ff && v[i].ss == ans.ss) ++cnt;
			else break;
		}
		printf("%d %d %d\n",ans.ff,ans.ss,cnt);
	}
}
		
