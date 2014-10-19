#include <vector>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <deque>
#include <stack>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <map>
#include <cassert>
#define bitcount __builtin_popcount
#define mod  1000000007
#define PHI 1000000006
#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define rz(x) resize(n)
#define cl()  clear()
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define S1(x) scanf("%llu",&x)
using namespace std;

int n;
int a[1001][2];
int dp[1001][2][4][4][5];

bool check (int mask, int x)
{
    x = (1LL<<x);
    x = mask|x;
    if (x == mask) {
        return true;
    }
    return false;
}

int f (int index, int column, int m1, int m2, int flag)
{
    if (flag == 4) {
        return 10000000;
    }

    if (column == 2) {
        return f(index+1, 0, m2, 0, flag);
    }

    if (index == n) {
        if (m1 == 0 && m2 == 0) {
            return 0;
        }
        return 10000000;
    }

    int &result = dp[index][column][m1][m2][flag];
    if (result != -1) {
        return result;
    }
    result = 10000000;

    if (check (m1, column)) {
        return f (index, column+1, m1, m2, flag);
    }

    if (column == 0 && m1 == 0) {
        result = min (result, max (a[index][0], a[index][1]) + f (index+1, 0, m2, 0, 0));
    }

    if (index != n-1 && column != 1 && !check(m1,0) && !check(m1,1) && !check(m2,0)) {
        result = min (result, max (a[index][0], max (a[index][1], a[index+1][0])) + f (index, column+1, 3, m2 | (0), 0));
    }

    if (index != n-1 && column != 1 && !check(m1,0) && !check(m1,1) && !check(m2,1)) {
        result = min (result, max (a[index][0], max (a[index][1], a[index+1][1])) + f (index, column+1, 3, m2 | (1), 0));
    }

    if (index != n-1 && column != 1 && !check(m1,0) && !check(m2,1) && !check(m2,0)) {
        result = min (result, max (a[index][0], max (a[index+1][1], a[index+1][0])) + f (index, column+1, m1|(0), 3, 0));
    }

    if (index != n-1 && column != 0 && !check(m1,1) && !check(m2,1) && !check(m2,0)) {
        result = min (result, max (a[index][1], max (a[index+1][1], a[index+1][0])) + f (index, column+1, m1|(2), 3, 0));
    }

    if (index != n-1 && !check (m1, column) && !check (m2, column)) {
        int ff;
        if (column == 0 && flag == 0) {
            ff = 1;
        } else {
            if (column != 0 && flag != 0) {
                ff = flag+1;
            } else {
                ff = 0;
            }
        }
        result = min(result, max(a[index][column], a[index+1][column]) + f (index, column+1, m1|(1LL<<column), m2|(1LL<<column), ff));
    }
    return result;

}

int main()
{
    //freopen ("input.txt", "r", stdin);
    int t;
    S (t);
    while (t--) {
        S (n);
        int i,j;
        F (i, 0, 2) {
            F (j, 0, n) {
                S (a[j][i]);
            }
        }

        memset (dp, -1, sizeof(dp));
        printf ("%d\n", f (0, 0, 0, 0, 0));
    }

    return 0;
}
