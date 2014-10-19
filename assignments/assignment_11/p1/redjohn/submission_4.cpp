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
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> II;
typedef vector<II> VII;
typedef vector<VII> VVII;
typedef vector<VI> VVI;


#define INF 2000000000
#define INFLL (1LL<<62)
#define FI first
#define SE second
#define PB push_back
#define SS ({int x;scanf("%d\n", &x);x;})
#define SSL ({LL x;scanf("%lld", &x);x;})
#define rep(i,n) for(i=0;i<(n);i++)
#define _mp make_pair

int main(){
        int t=SS,a,b,n,i;
        while(t--){
                string s;
                a=b=0;
                cin>>s;
                n=s.size();
                rep(i,n) {
                        if(i&1) a+=s[i]-'0';
                        else b+=s[i]-'0';
                }
                printf("%s\n",(abs(a-b)%11==0)?"YES":"NO");
        }
        return 0;
}        
                                
