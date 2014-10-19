// Author : Abhisar Singhal
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>   
#include <map>
#include <string>  
#include <climits> 
#include <set>
#include <string>    
#include <sstream>
#include <utility>   
#include <ctime>
#include <cassert>
#include <fstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<long long> VLL;
typedef vector<bool> VB;

#define SZ(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define X first
#define Y second
#define PB push_back
#define FOUND(A, x) (A.find(x) != A.end())
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12

#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)
#define FORALL(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
inline void inp( int &n ) {
        n=0; int ch = getcx(); int sign = 1;
        while(ch < '0' || ch > '9') { if(ch == '-') sign=-1; ch = getcx(); }
        while(ch >= '0' && ch <= '9') { n = (n << 3) + (n << 1) + ch - '0', ch = getcx(); }
		n = n * sign;
}

LL getLen(LL rank, LL sz){
	LL ret = 0, p = 1;
	while(rank > 0){
		rank -= pow(sz, p);
		p++;
		ret++;
	}
	return ret;
}

LL getRank(LL rank, LL len, LL sz){
	FOR(i, 1, len){
		rank -= pow(sz, i);
	}
	return rank;
}

char ss[100];

int main() {
	std::ios_base::sync_with_stdio(false);
	int t;
	inp(t);
	while(t--){
		int x;
		int rank;
		inp(x);
		scanf("%s", ss);
		string str(ss);
		inp(rank);
		sort(ALL(str));
		int sz = unique(ALL(str)) - str.begin();
		int fl = getLen(rank, sz);
		LL rankInLen = getRank(rank - 1, fl, sz);
		string ans;
		REP(i, fl){
			int pos = rankInLen % sz;
			ans += str[pos];
			rankInLen /= sz;
		}
		reverse(ALL(ans));
		cout << ans << endl;
	}
	return 0;
}

