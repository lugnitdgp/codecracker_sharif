/*================*\
|  ID   : adurysk  |
|  LANG : C++      |
\*================*/

#include<bits/stdc++.h>

using namespace std;

#define sd(x) x = GetNextInt()
#define LL long long
#define LD long double
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Fill(a, b) memset(a, b, sizeof(a))
#define INF 2000000009

typedef pair<int,int> PII;
typedef vector<int> VI;

#if 0
#define get getchar_unlocked
#else
#define get getchar
#endif

LL next_int, sign;
char in_char;

inline LL GetNextInt(){
    in_char = ' ';
    sign = 1;
    while((in_char < '0') || (in_char > '9')){
        in_char = get();
        if(in_char == '-'){
            sign = -1;
        }
    }
    next_int = 0;
    while((in_char >= '0') && (in_char <= '9')){
        next_int *= 10;
        next_int += in_char - 48;
        in_char = get();
    }
    return next_int * sign;
}

#define MAXN 1000000

LL dp[MAXN][3][2];
LL a[2][MAXN], mc;

inline LL f(LL a, LL b, LL c){
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
        printf("%lld\n", max(a[0][0], a[1][0]));
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
    cout<<dp[0][0][0]<<endl;
}

int main(){
    int t;
    sd(t);
    while(t--){
        Solve();
    }
    return 0;
}
