#include <vector>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <deque>
#include <queue>
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

int a[22][22];
int b[22][22];
int n;
int dd[22][22];

int dp[21][21];

struct node
{
    int x,y,z;
};
typedef struct node node;

bool operator<(struct node a, struct node b)
{
    return a.z>b.z;
}

struct node get(int x, int y, int z)
{
    struct node s;
    s.x = x;
    s.y = y;
    s.z = z;
    return s;
}

void ff()
{
    priority_queue <struct node> p;
    p.push (get(0, 0, a[0][0]));


    while (p.size()) {
        struct node s = p.top();
        p.pop();

        int x,y,z;
        x = s.x;
        y = s.y;
        z = s.z;
        if (z < 0) {
            continue;
        }
        if (dp[x][y] > z) {
            continue;
        }
        dp[x][y] = z;

        if ((x == n-1 && y == n-1)) {
            continue;
        }
        int i;
        F (i, y+1, n) {
            if (i != y+1) {
                break;
            }
            int xx = z+a[x][i];
            if (dd[x][i] == -1) {
                continue;
            }
            if (xx < 0){
                    continue;
            }
            if (dp[x][i] > xx) {
                continue;
            }
            p.push(get(x,i,xx));
            dp[x][i] = xx;

        }
        if (x != n-1) {
            int xx = z+b[x+1][y];
            if (dd[x+1][y] == -1) {
                continue;
            }
            if (xx < 0) {
                continue;
            }
            if (dp[x+1][y] >xx) {
                    continue;
            }
            p.push(get(x+1, y, xx));
            dp[x+1][y] = xx;
        }

    }
    if (dp[n-1][n-1] == -1) {
        printf ("MURDER\n");
        return;
    }
    printf ("%d\n", dp[n-1][n-1]);
}

int main()
{
   // freopen ("input.txt", "r", stdin);
    int t;
    S (t);
    while (t--) {
        S (n);
        int i,j;
        F (i, 0, n) {
            F (j, 0, n) {
                S (a[i][j]);
                //S (b[i][j]);
                b[i][j] = a[i][j];
                dp[i][j] = -1;
                dd[i][j] = a[i][j];
            }
        }

        int index;
        index = -1;
        F (i, 0, 2*n -1) {
            if (i%2 == 0) {
                index++;
                F (j, 0, n-1) {
                    int x;
                    S (x);

                    a[index][j+1] = a[index][j+1]-x;
                }
                continue;
            }
            F (j, 0, n) {
                int x;
                S (x);

                b[index+1][j] -= x;
            }
        }


        ff();
    }

    return 0;
}
