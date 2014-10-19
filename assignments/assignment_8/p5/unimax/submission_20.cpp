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

int fun(int A,int p,int i,int k){  
      //  printf("%d \n",i);   
        if(i==p && A%p==0)
                return 0;
         else if(i<p && A%p==0) 
                return INF;
         if(A%p==k){
                return fun((p-1)*(A/p),p,i+1,k)+1;
          }
          return INF;
}
int main(){
        int t,n,i,ans,k;
        while(cin>>n){
//                n=SS;
                ans=0;
                for(i=2;i<=n;i++){
                        k=n%i;
                    //    cout<<i<<" "<<fun(n,i,0,k)<<endl;

                        if(n%i==k && (ans=fun(n,i,0,k)<INF)){
                                break;
                        }
                
                 }
              //   cout<<ans<<endl;
                 if(i<=n)
                 printf("%d coconuts, %d yellow beings and %d Phil\n",n,i,k);
                 else
                 printf("%d coconuts, no solution\n",n);
                 
         }
         return 0;
}         
                                
                                  