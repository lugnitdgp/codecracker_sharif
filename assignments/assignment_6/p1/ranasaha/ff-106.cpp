#include <bits/stdc++.h>
using namespace std;
#ifdef  __linux__
#define LLD "%lld"
#define get getchar_unlocked
#else
#define LLD "%I64d"
#endif
#define P(n) printf("%d",n)
#define SL(n) scanf(LLD,&(n))
#define PL(n) printf(LLD,n)
#define SD(n) scanf("%lf",&n)
#define SS(n) scanf("%s",n)
#define pn printf("\n")
#define ps printf(" ")
#define szz(s) int(strlen(s))
#define sz(s) int((s).size())
#define S(n) scanf("%d",&(n))
#define s(n) int n; scanf("%d",&(n))
#define S2(n,m) scanf("%d %d",&(n),&(m))
#define s2(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define S3(n,m,k) scanf("%d %d %d",&(n),&(m),&(k))
#define s3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))
#define erU(V); (V).erase(unique(all(V)),(V).end())
#define erA(V,num); (V).erase(remove(all(V),(num)),(V).end())
#define IT(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
//#pragma message("removed the lz ip ??")
#ifndef DEBUG
#define ck1 puts("ok1");
#define ck2 puts("ok2");
#define ck3 puts("ok3");
#define dir puts("-->");
#define hold int y;cin>>y;
#define show(x) cout<<#x<<": "<<x<<"\n";
#define show2(x,y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<< "\n";
#define show3(x,y,z) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<"\n";
#define show4(x,y,z,w) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<" | "<<#w<<": "<<w<<"\n";
#else
#define ck1
#define ck2
#define ck3
#define dir
#define hold
#define show(x)
#define show2(x,y)
#define show3(x,y,z)
#define show4(x,y,z,w)
#endif
#define nextP next_permutation
#define rep(i,a,b) for((i)=a;(i)<=(b);++(i))
#define per(i,b,a) for((i)=b;(i)>=(a);--(i))
#define clr(a) memset(a,0,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef long long LL;
typedef vector <int> vi;
typedef map <int,int> mii;
typedef map <pair <int,int >, int> miii;
typedef map <int, int> :: const_iterator it;
inline int ins(int x,int y,int m,int n){return (x>=1&&x<=m&&y>=1&&y<=n);}
template <class T> inline T gcd(T a,T b){return (!b? a : gcd(b,a%b));}
template <class T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}
template <class T> inline T ABS(T x){return ((x)>0?(x):(-(x)));}
template <class T> inline T max(T a,T b,T c) {return (max(max(a,b),c));}
template <class T> inline T min(T a,T b,T c) {return (min(min(a,b),c));}
template <class T> inline T cub(T x) {return x*x*x;}
template <class T> inline T sqr(T x) {return x*x;}
const double PI = 3.141592653589793;
const int N = 30000 + 10;
const int INF = INT_MAX;

char str[N];
int i,j;
int main()
{

	int testCase, t=1;
	S(t);
	for(testCase=1; testCase<=t; testCase++)
	{
		s(n);
		SS(str);
		vector <char> v;
		rep(i,0,szz(str)-1) v.pb(str[i]);
		sort(all(v));
		
		s(rank);
		
		
		vi vv;
		while(rank != 0) {
			int rem = rank%n;
			//show(rem);
			vv.pb(rem);
			rank /= n;
		}
		
		
		per(i,sz(vv)-1,0) {
			cout<<v[vv[i]-1];
		}
		pn;
	}
}
		
		
