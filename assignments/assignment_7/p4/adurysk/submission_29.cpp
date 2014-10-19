#include <cstdio>
#include <iostream>

using namespace std;

#define sd(x) scanf("%d", &x)
#define slld(x) scanf("%lld", &x)
#define LL long long
#define INF 2000000009


#define MAXN 1000000

LL dp[MAXN][3][2];
LL a[2][MAXN], mc;

inline LL f(LL a, LL b, LL c){
    return max(a, max(b, c));
}

int main(){
    int t, n, i, j;
    sd(t);
    while(t--){
        sd(n);
        for(i = 0; i < n; i++){
            sd(j);
            a[0][i] = j;
        }
        for(i = 0; i < n; i++){
            sd(j);
            a[1][i] = j;
        }
        if(n == 1){
            printf("%lld\n", max(a[0][0], a[1][0]));
            continue;
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
            dp[i][0][0] = min(dp[i][0][0], dp[i + 1][1][0] + max(mc, a[0][i + 1]));
            dp[i][0][0] = min(dp[i][0][0], dp[i + 1][2][0] + max(mc, a[1][i + 1]));
            dp[i][0][0] = min(dp[i][0][0], dp[i + 2][0][1] + max(a[0][i], a[0][i + 1]) + max(a[1][i], a[1][i + 1]));

            dp[i][0][1] = dp[i + 1][0][0] + mc;
            dp[i][0][1] = min(dp[i][0][1], dp[i + 1][1][0] + max(mc, a[0][i + 1]));
            dp[i][0][1] = min(dp[i][0][1], dp[i + 1][2][0] + max(mc, a[1][i + 1]));

            dp[i][1][0] = dp[i + 1][2][0] + max(a[1][i], a[1][i + 1]);
            dp[i][1][0] = min(dp[i][1][0], dp[i + 2][0][0] + f(a[1][i], a[1][i + 1], a[0][i + 1]));
            dp[i][1][1] = dp[i][1][0];

            dp[i][2][0] = dp[i + 1][1][0] + max(a[0][i], a[0][i + 1]);
            dp[i][2][0] = min(dp[i][2][0], dp[i + 2][0][0] + f(a[0][i], a[1][i + 1], a[0][i + 1]));
            dp[i][2][1] = dp[i][2][0];
        }
        printf("%lld\n", dp[0][0][0]);
    }
    return 0;
}
