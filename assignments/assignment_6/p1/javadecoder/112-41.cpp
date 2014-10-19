#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<iterator>
#include<string>
#include<sstream>
#include<cassert>
#include<ctime>
#include<cmath>

#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define oo 2000000000
#define MOD 1000000007
#define LL long long int
#define PII pair<int,int>
#define DEBUG 0

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

using namespace std;
char str[46];
LL n;
string get(LL r){
    LL len=1,pw=n;
    while(r>pw) r-=pw, pw=pw*n, ++len;
    pw/=n;
    string ans="";
    for(int i=len-1;i>=0;i--){
        int j=0;
        for(;j<n and r>pw;r-=pw,j++);
        ans+=string(1,str[j]);
        pw/=n;
    }
    return ans;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        LL r;
        scanf("%s%lld",str,&r);
        sort(str,str+n);
        cout<<get(r)<<"\n";
    }
    return 0;
}
