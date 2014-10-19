#include <cstdio>
#include <iostream>

using namespace std;

#define sd(x) scanf("%d", &x)
#define slld(x) scanf("%lld", &x)
#define INF 20000009


#define MAXN 10000

int dp[MAXN][3][2];
int a[2][MAXN], mc;

inline int f(int a, int b, int c){
    return max(a, max(b, c));
}

inline void Solve(){
    int n, i;
    sd(n);
    for(i = 0; i < n; i++){
        sd(a[0][i]);
    }
    for(i = 0; i < n; i++){
        sd(a[1][i]);
    }

    if(n == 1){
        printf("%d\n", max(a[0][0], a[1][0]));
        return;
    }
    dp[n][0][0] = 0;
    dp[n][0][1] = 0;
    dp[n][1][0] = INF;
    dp[n][1][1] = INF;
    dp[n][2][0] = INF;
    dp[n][2][1] = INF;
    for(i = n - 1; i >= 0; i--){
        mc = max(a[0][i], a[1][i]);

        dp[i][0][0] = dp[i + 1][0][0] + mc;
        if(i < n - 1){
            dp[i][0][0] = min(dp[i][0][0], dp[i + 1][1][0] + max(mc, a[0][i + 1]));
            dp[i][0][0] = min(dp[i][0][0], dp[i + 1][2][0] + max(mc, a[1][i + 1]));
            dp[i][0][0] = min(dp[i][0][0], dp[i + 2][0][1] + max(a[0][i], a[0][i + 1]) + max(a[1][i], a[1][i + 1]));
        }

        dp[i][0][1] = dp[i + 1][0][0] + mc;
        if(i < n - 1){
            dp[i][0][0] = min(dp[i][0][0], dp[i + 1][1][0] + max(mc, a[0][i + 1]));
            dp[i][0][0] = min(dp[i][0][0], dp[i + 1][2][0] + max(mc, a[1][i + 1]));
        }

        dp[i][1][0] = dp[i + 1][2][0] + max(a[1][i], a[1][i + 1]);
        dp[i][1][0] = min(dp[i][1][0], dp[i + 2][0][0] + f(a[1][i], a[1][i + 1], a[0][i + 1]));
        dp[i][1][1] = dp[i][1][0];

        dp[i][2][0] = dp[i + 1][1][0] + max(a[0][i], a[0][i + 1]);
        dp[i][2][0] = min(dp[i][2][0], dp[i + 2][0][0] + f(a[0][i], a[1][i + 1], a[0][i + 1]));
        dp[i][2][1] = dp[i][2][0];
    }
    printf("%d\n", dp[0][0][0]);
}

int main(){
    int t;
    sd(t);
    while(t--){
        Solve();
    }
    return 0;
}
