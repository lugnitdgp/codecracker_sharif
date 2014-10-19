#include <algorithm>
#include <iomanip>
#include <complex>
#include "assert.h"
#include <cstdio>
#include <stack>
#include <time.h>
#include <cstdlib>
#include <ctype.h>
#include <climits>
#include <cctype>
#include <queue>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <map>
#include <numeric>
#include <set>
#include <unistd.h>
#include <bitset>
using namespace std;


#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define rep(i,a,b) for (int i = a; i < b; ++i)

#define repv(i,cc) rep(i,0,sz(cc))
//#define tr(c,i)\
      for(decltype((c).begin()) i = (c).begin(); i != (c).end();i++)

#define unq(c) sort(all(c)),(c).resize(unique(all(c))-(c).begin())
#define X first
#define Y second
#define pb push_back
//#define mp make_pair


typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

/* INF use INT_MAX INT_MIN, LLONG_MIN, LLONG_MAX , ULLONG_MAX */

#define is(a) scanf("%d",&a)
#define iull(a) scanf("%llu",&a)
#define pull(a) printf("%llu\n",a)
#define db(a) scanf("%lf",&a)
#define pc(a) putchar(a)
#define pl(a) printf("%lld\n",a)
#define pu(a) printf("%u\n",a)
#define pd(a) printf("%lf\n",a)
#define ps(a) puts(#a)

#define pi(x) cerr<<"Debug: "<< #x << " : "<< x<<"\n";
#define pts(a) puts(a)
#define MAX 101
#define EPS 1e-7


template<class T> inline string tostring( T n ){ stringstream ss; ss << n; ss.flush(); return ss.str(); }
template<class T> inline string tobinary( T n ){ string s = n ? "" : "0"; while( n ) { s += ( ( n & 1 ) + '0' ); n >>= 1; } return s; }
template<class T> inline int digits( T n ){ int cnt = n ? 0 : 1; while( n ){ n /= 10; cnt++; } return cnt; }
template<class T1, class T2> inline T2 gcd( T1 a, T2 b ){ return !b ? a : gcd( b, a%b ); }
template<class T> inline T abs( T a ){ return a < 0 ? -a : a; }

#ifndef _FOOLS_SYS_
    #define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end();i++)
    #define gc getchar_unlocked
    #define ugc ungetc
#else
    #define tr(c,i) for(decltype((c).begin()) i = (c).begin(); i != (c).end();i++)
    #define gc getchar
    #define ugc ungetchar
#endif

#define i(n) { \
	register char chchchch = 0, \
	              sssssssss = 1; \
	n = 0; \
	for(;chchchch < 33;chchchch = gc()); \
	(chchchch == 45)?sssssssss = -1,chchchch = gc():0; \
	for(;chchchch > 33;n = n * 10 + chchchch - '0',chchchch = gc()); \
	n *= sssssssss; \
}


//int mp[20][20][20][20];

int g[20][20];


bool solve(vector<vector<int> > &vis, int x, int y, int N){
        if(x >= N || y >= N) return 0;
        if(g[x][y] == -1) return 0;
        if(x == N-1 && y == N-1 ) return 1;

        if(vis[x+1][y] == -1)
         vis[x+1][y] = solve(vis,x+1,y,N);
        if( vis[x][y+1] == -1)
         vis[x][y+1] = solve(vis,x,y+1,N);

       return vis[x][y+1] || vis[x+1][y];
    }

map<pair< pair<int,int>, pair<int,int> >,int > mp;

int  Solve(vector<vector<int> > &vis,int sum,int x, int y, int N){

        if(sum == 0) return INT_MIN;
        if(g[x][y] == -1) return INT_MIN;
        if(x == N-1 && y == N-1 ){
            return sum;
        }
        bool flg1 = 0, flg2 = 0;

        if(vis[x+1][y] == -1 && x+1 < N){
           flg1 = 1;
         vis[x+1][y] = Solve(vis,sum + g[x+1][y]- mp[make_pair(make_pair(x,y),make_pair(x+1,y))], x+1,y,N);
        }
        if( vis[x][y+1] == -1 && y+1 < N){
         vis[x][y+1] = Solve(vis,sum + g[x][y+1]- mp[make_pair(make_pair(x,y),make_pair(x,y+1))],x,y+1,N);
         flg2 = 1;
        }
        if(flg1&& flg2)
         return max(vis[x][y+1],vis[x+1][y]);
        else if(flg1) return vis[x+1][y];
        else return vis[x][y+1];
    }

int main(){

   #ifdef _FOOLS_SYS_
      freopen("input.txt","r",stdin);
   #else
     // ios_base::sync_with_stdio(false);
   #endif
   int T;

   cin>>T;
   while(T-->0){
     int N;
     cin>>N;

     for(int i = 0; i < N; ++i)
       for(int j = 0; j < N; ++j)
         cin>>g[i][j];



     for(int i = 0; i < N; ++i){
        for(int j = 0; j < N - 1; ++j){
          int cur;
          cin>>cur;
          mp[make_pair(  make_pair(i,j),make_pair(i,j+1)  )] = cur;
        }

        if(i+1 < N)
        for(int j = 0; j < N ; ++j){
            int cur;
          cin>>cur;
          mp[make_pair(make_pair(i,j),make_pair(i+1,j))] = cur;
        }

      }


     vector<vector<int> > vis(22,vector<int>(22,-1));
     int res = Solve(vis,g[0][0],0,0,N);
     if(res == INT_MIN)
         puts("MURDER");
     else
     cout<<res<<"\n";

   }

   return 0;
}










