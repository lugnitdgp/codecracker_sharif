#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>

using namespace std;
typedef long long LL;



#define INF 2000000000
#define INFLL (1LL<<62)
#define FI first
#define SE second
#define PB push_back
#define SS ({int x;scanf("%d", &x);x;})
#define SSL ({LL x;scanf("%lld", &x);x;})
#define rep(i,n) for(i=0;i<(n);i++)
#define _mp make_pair

using namespace std;
const int maxn = 400005;
typedef long long LL;
typedef pair<LL, LL> PII;
typedef vector<LL> VI;
typedef vector<PII> VP;
LL ts[maxn];
VP vp[maxn];
//void output(const VP& vec){
//    for(int i = 0; i < (int)vec.size(); i ++){
//        printf("%d %d\n", vec[i].first, vec[i].second);
//    }
//}
void norm(VP& vec){
    sort(vec.begin(), vec.end());
    LL cc = 0;
    for(int i = 0; i < (int)vec.size(); i ++){
        if(cc == 0 || vec[i].first != vec[cc-1].first){
            vec[cc++] = vec[i];
        }else{
            vec[cc-1].second += vec[i].second;
        }
    }
    vec.resize(cc);
}
VP merge(const VP& v1, const VP& v2){
    VP ret;
    for(int i = 0; i < (int)v1.size(); i ++) ret.push_back(v1[i]);
    for(int i = 0; i < (int)v2.size(); i ++) ret.push_back(v2[i]);
    norm(ret);
    return ret;
}
LL N, A, B, ans;
LL K;
LL SUM, GOAL;
VP sp;
void add(LL cur){
    if(cur%A != GOAL) return;
    B = SUM/cur;
    if(B >= K) return;
    if(A == B) ans ++;
    else if(A < B) ans += 2;
}
void dfs(LL th, LL cur){
    if(A*cur > SUM) return;
    if(th == (int)sp.size()){
        add(cur);
        return;
    }
    for(int i = 0; i <= (int)sp[th].second; i ++){
        dfs(th+1, cur);
        cur *= sp[th].first;
    }
}
void solve(){
    K -= N;
    //[1, K)
    ans = 0;
    for(A = 1; A <= 3*N && A < K; A ++){
        SUM = (LL)N*(N+A-1);
        GOAL = (A-N%A)%A;
        LL lwk = N/A, upk = (SUM/A+N)/A;
        if(upk-lwk < 200){
            for(int k = lwk; k <= upk; k ++){
                LL cur = k*A - N;
                if(cur > 0 && SUM%cur == 0) add(cur);
            }
            continue;
        }
        if(N+A-1 >= maxn) while(1);
        sp = merge(vp[N], vp[N+A-1]);
        reverse(sp.begin(), sp.end());
        bool modify = true;
        while(modify){
            modify = false;
            for(VP::iterator it = sp.begin(); it != sp.end(); it++){
                if(A%it->first == 0 && GOAL%it->first != 0){
                    modify = true;
                    sp.erase(it); break;
                }
            }
        }
        dfs(0, 1);
    }
    printf("%d\n", (int)ans);
}
char buf[1000];
void norm(VI& vec){
    for(int i = 0; i+1 < (int)vec.size(); i ++){
        int to = (vec[i]+10);
        int cc = (vec[i]-to)/10;
        vec[i+1] += cc;
        vec[i] = to;
    }
    while(vec.size() > 1 && vec.back() == 0) vec.pop_back();
}
void solveNE0(){
    scanf("%s", buf);
    int len = strlen(buf);
    VI v1;
    for(int i = len-1; i >= 0; i --) v1.push_back(buf[i]-'0');
    v1[0] --;
    VI v2(len*2 + 10, 0);
    for(int i = 0; i < len; i ++){
        for(int j = 0; j < len; j ++){
            v2[i+j] += v1[i] * v1[j];
        }
    }
    norm(v2);
    //output
    for(int i = (int)v2.size()-1; i >= 0; i --){
        printf("%d", (int)v2[i]);
    }
    printf("\n");
}
int main() {
//    double startTime = clock();
    for(int i = 2; i < maxn; i ++){
        for(int j = i+i; j < maxn; j += i){
            if(ts[j] == 0) ts[j] = i;
        }
        if(ts[i] == 0) vp[i].push_back(make_pair(i, 1));
        else{
            vp[i] = vp[i/ts[i]];
            vp[i].push_back(make_pair(ts[i], 1));
        }
        norm(vp[i]);
    }
//    printf("%lf\n", (clock()-startTime)/CLOCKS_PER_SEC);
//    output(vp[120]);
    int test;
    test=SS;
    while(test --){
         N=SS;
        if(N == 0){
            solveNE0();
        }else{
            K=SSL;
            solve();
        }
    }
//    printf("%lf\n", (clock()-startTime)/CLOCKS_PER_SEC);
    return 0;
}