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

/* #include <bits/stdc++.h> */ //for C++11

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define rep(i,a,b) for (int i = a; i < b; ++i)

#define repv(i,cc) rep(i,0,sz(cc))
//#define tr(c,i)\
 //     for(decltype((c).begin()) i = (c).begin(); i != (c).end();i++)

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
#define MAX 1000009
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


int main(){

   #ifdef _FOOLS_SYS_
      freopen("input.txt","r",stdin);
   #else
     // ios_base::sync_with_stdio(false);
   #endif

   int T;
   LL N,M;
   cin>>T;

   while(T-->0){
     cin>>N>>M;
     map<LL,LL> Row,Col;
     map<LL,LL>::iterator it;
     for(int i = 0; i < M; ++i){
        int r,c,v;
        cin>>r>>c>>v;
        Row[r] += v;
        Col[c] += v;
     }

     int rw, rwmx = 0;
     for(it = Row.begin();it != Row.end(); it++){
       if(it->second > rwmx){
         rw = it->first;
         rwmx = it->second;
       }
     }

     int cntr = 0;
     for(it = Row.begin();it != Row.end(); it++){
       if(it->second == rwmx)
        cntr++;
     }

     int cw, cwmx = 0;
     for(it = Col.begin();it != Col.end(); it++){
       if(it->second > cwmx){
         cw = it->first;
         cwmx = it->second;
       }
     }

     int cntc = 0;
     for(it = Col.begin();it != Col.end(); it++){
       if(it->second == cwmx)
        cntc++;
     }


     if(rwmx > cwmx){
       if(cntr == 1)
         cout<<"Row "<<rw<<"\n";
       else if(cntc == 1)
         cout<<"Column "<<cw<<"\n";
       else
         puts("Bad luck");
     }
     else if(cwmx > rwmx){
       if(cntc == 1)
        cout<<"Column "<<cw<<"\n";
       else if(cntr == 1)
         cout<<"Row "<<rw<<"\n";
       else
          puts("Bad luck");
     }
     else
        puts("Bad luck");



    }

  return 0;
}











