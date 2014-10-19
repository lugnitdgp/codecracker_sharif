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
#define SS ({int x;scanf("%d", &x);x;})
#define SSL ({LL x;scanf("%lld", &x);x;})
#define rep(i,n) for(i=0;i<(n);i++)
#define _mp make_pair

int main(){
        int t=SS;
        while(t--){
        int n=SS,m,i,a,b;
    //    cout<<t<<n<<endl;
        LL v,ans;
        m=SS;
        map<int,LL> mpx,mpy;
        map<int,LL>:: iterator it;
        rep(i,m){
                a=SS;
                b=SS;
                v=SS;
                mpx[a]+=v;
                mpy[b]+=v;
         }
         ans=0;
         for(it=mpx.begin();it!=mpx.end();it++)
                ans=max(ans,(*it).SE);
         for(it=mpy.begin();it!=mpy.end();it++)
                ans=max(ans,(*it).SE);   
         int f=0;
         int r=0,c=0;
         for(it=mpx.begin();it!=mpx.end();it++)
                if((*it).SE==ans){
                        f++;
                        r=(*it).FI;
                 }
         for(it=mpy.begin();it!=mpy.end();it++)
                if((*it).SE==ans){
                        f++;
                        c=(*it).FI;
                 }                                 
         if(f>1){
                printf("Bad luck\n");
                //return 0;
                continue;
         }
         printf("%s %d\n",(r==0)?"Column":"Row",max(r,c));
         }
         return 0;
}         