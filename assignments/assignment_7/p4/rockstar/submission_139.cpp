//write your code here/*
Saksham Garg :)
Algorithm:
#tags:
date: Tue Oct 22 07:33:04 PDT 2013
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long LL;
#define CLR(a) memset(a, 0, sizeof a);
#define fill(a,v,N) memset(a, v, sizeof(a[0])*N)
#define sz(a) int((a).size())
#define pb push_back
#define si(n) scanf("%d",&n)
#define sill(n) scanf("%lld",&n)
#define pi(n) printf("%d\n",n);
#define pill(n) printf("%lld\n",n);
#define pis(n) printf("%d ",n);

#define mp(a,b) make_pair(a,b);
#define MAX_S 100007
#define INF 1000000000
#define MOD 1000000000
/*
struct data{
};
bool operator < (const data &a1, const data &a2){
}
*/
LL dp[31][2];
bool fs[31][2];
int solve(int i ,int j){
   if(fs[i][j]==1)
      return dp[i][j];
   fs[i][j]=1;
   if(j==0)
      return dp[i][j] = 3*solve(i-2,0)  + 2*solve(i-2,1);
   return dp[i][j] = solve(i-2,0) + solve(i-2,1);
}
int main()
{
   int n;
   dp[0][0] = 1;
   fs[0][0] = fs[0][1] =1;
   while(cin >> n){
      if(n==-1)
         break;
      if(n%2)
         cout << "0\n";
      else
        pi(solve(n,0));
   }
}

