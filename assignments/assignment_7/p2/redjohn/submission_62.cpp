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
            int num=SS;
            int lst=num-1,a[555];
            long long ans=0;
            for(int i=0;i<num;i++)a[i]=SS;
                sort(a,a+num);
            while(true){
                if(num==1){ ans+=a[0] ; break;}
                else if(num==2) {ans+=a[1]; break;}
                else if(num==3) {ans+=a[2]+a[1]+a[0]; break;}
                else {
                  if (2*a[0]+a[1]+a[num-2]+a[num-1]<a[0]+3*a[1]+a[num-1])
                  ans+=2*a[0]+a[num-2]+a[num-1];
                else
                  ans+= a[0]+2*a[1]+a[num-1];
                    num-=2;
                }
            }
            cout<<ans<<endl;
        }
        return 0;
}

