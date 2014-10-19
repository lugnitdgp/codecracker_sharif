
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<climits>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;

#define REP(i,s,n)  for (int i=(s),_n=(n);i<=_n;i++)
#define FOR(i,s,n)  for (int i=(s),_n=(n);i<_n;i++)
#define REPD(i,e,s)  for (int i=(e),_s=(s);i>=_s;i--)
#define tr(container, it) \
  for (typeof(container.begin()) it=container.begin(); it!=container.end();it++)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define EPS 0.000000001
#define INF (int)(1e9)

typedef unsigned long long LL;

LL dp[1000][30];
string ans;
string dict;
int di=0;

string rec(LL n, int len, int c) {
  if(len==0) return "";
  LL s=0;
  FOR(i,c,di) {
    if(s+dp[len][i]>=n) return (char)(dict[i]) + rec(n-s,len-1,i);
    s+=dp[len][i];
  }
  return "";
}

void fun(LL n) {
  int len=0;
  LL s=0;
  FOR(i,1,1000) {
    LL g=0;
    FOR(j,0,di) g+= dp[i][j];
    if(s+g>=n) { len=i; break; }
    s+=g;
  }
  ans=rec(n-s,len,0);
}


int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> di;
    cin >> dict;
    ans="";
    sort(ALL(dict));

    memset(dp,0,sizeof dp);
    FOR(i,0,di) dp[1][i]=1;
    FOR(i,2,1000) FOR(j,0,di) FOR(k,j,di) dp[i][j]+=dp[i-1][k];

    LL r;
    cin >> r;
    fun(r);
    cout << ans << endl;
  }
  return 0;
}
