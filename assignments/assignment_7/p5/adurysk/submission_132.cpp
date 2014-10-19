#include <cstdio>
#include <iostream>

using namespace std;

#define sd(x) scanf("%d", &x)
#define slld(x) scanf("%lld", &x)
#define INF 20000009
#define LL unsigned long long int
#define MOD 2147483647LL
LL n, ans;

inline void Solve(){
    cin>>n;
    n %= MOD;
    ans = (n - 1) * 4;
    n *= (n - 1);
    n /= 2;
    n %= MOD;
    ans += n;
    ans %= MOD;
    cout<<ans<<endl;
}

int main(){
    int t;
    sd(t);
    while(t--){
        Solve();
    }
    return 0;
}
