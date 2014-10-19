
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

#define REP(i,s,n)  for (LL i=(s),_n=(n);i<=_n;i++)
#define FOR(i,s,n)  for (LL i=(s),_n=(n);i<_n;i++)
#define REPD(i,e,s)  for (LL i=(e),_s=(s);i>=_s;i--)
#define tr(container, it) \
  for (typeof(container.begin()) it=container.begin(); it!=container.end();it++)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define EPS 0.000000001
#define INF (int)(1e9)

typedef unsigned long long LL;

LL dp[32][30];
string ans;
string dict;
LL di=0;

string rec(LL n, LL len, LL c) {
  if(len==0) return "";
 // cout << n << " " << len << " " << c << endl;
  LL s=0;
  FOR(i,0,di) {
  //  cout << len << " " << i << ":" << dp[len][i] << endl;
    if(s+dp[len][i]>=n) return (char)(dict[i]) + rec(n-s,len-1,i);
    s+=dp[len][i];
  }
  return "";
}

void fun(LL n) {
  LL len=0;
  LL s=0;
  FOR(i,1,32) {
    LL g=0;
    FOR(j,0,di) g+= dp[i][j];
    //cout << "g:" << g << endl;
    if(s+g>=n) { len=i; break; }
    s+=g;
  }
  ans=rec(n-s,len,0);
}

LL pow(LL a, LL b) {
  LL res=1;
  while (b--) res*=a;
  return res;
}

int main() {
  LL t;
  cin >> t;
  string cp;
  while (t--) {
    cin >> di;
    cin >> cp;
    sort(ALL(cp));
    dict=cp[0];
    FOR(i,1,di) if (cp[i]!=cp[i-1]) dict+=cp[i];
    di=dict.size();
    ans="";
    LL r;
    cin >> r;
    if (di==1) {
      ans=dict[0];
      LL cnt=2;
      while (1) {
	if (cnt>r) break;
	ans+=ans;
	cnt*=2;
      }
      cnt/=2;
      for (LL i=cnt;i<r;i++) ans+=dict[0];
      cout << ans << endl;
      continue;
    }

    memset(dp,0,sizeof dp);
    FOR(i,0,di) dp[1][i]=1;
    FOR(i,2,32) {
      FOR(j,0,di) {
	dp[i][j]=pow(LL(di),(LL)i-1);
      }
    }

    fun(r);
    cout << ans << endl;
  }
  return 0;
}
