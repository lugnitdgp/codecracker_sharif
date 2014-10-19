#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;


int a[101];
int n;

int solve(int k){
    int i, j, ret = 0;
    j = k;
    i = n - 1;
    while(k--){
        ret += a[i] + a[0] + a[1] + a[1];
        i -= 2;
    }
    while(i > 1){
        ret += a[i] + a[0];
        i--;
    }
    ret += a[1];
    return ret;
}

int main(){
    int t, i, k, ans;
    cin>>t;
    while(t--){
        cin>>n;
        for(i = 0; i < n; i++){
            cin>>a[i];
        }
        sort(a, a+n);
        if(n == 1){
            printf("%d\n", a[0]);
            continue;
        }
        else if(n == 2){
            printf("%d\n", a[1]);
            continue;
        }
        ans = 1000000000;
        for(k = 0; k <= n/2 - 1; k++){
            i = solve(k);
            ans = min(ans, i);
        }
        printf("%d\n", ans);
    }
    return 0;
}
