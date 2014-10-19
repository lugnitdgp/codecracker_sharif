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
#define NN 32
int A[30][30],RR[30][30],dp[31][31],dd[30][30],p;
int main(){
        int t=SS,i,j,k,n;
        while(t--){
                n=SS;
                memset(A,0,sizeof(A));
                memset(dp,0,sizeof(dp));                
                memset(RR,0,sizeof(RR));
                memset(dd,0,sizeof(dd));                                
                for(i=0;i<n;i++){
                        for(j=0;j<n;j++){
                                A[i][j]=SS;
                         }
                }
                for(i=0;i<2*n-1;i++){
                        if(i%2==0){
                                RR[i/2][0]=0;
                                for(k=1;k<n;k++)
                                        RR[i/2][k]=SS;
                       }
                       else{
                                for(k=0;k<n;k++)
                                dd[(i+1)/2][k]=SS;
                        }
               }
//               for(i=0;i<n;i++){
//                        for(j=0;j<n;j++){
//                                cout<<RR[i][j]<<" ";
//                         }
//                         cout<<endl;
//                }
//                
//                
//               for(i=0;i<n;i++){
//                        for(j=0;j<n;j++){
//                                cout<<dd[i][j]<<" ";
//                         }
//                         cout<<endl;
//                }
//                
                
dp[0][0]=A[0][0];
for(i=1;i<n;i++){
                        if(A[0][i]==-1)
                                dp[0][i]=INF;
                         else{
                                if(dp[0][i-1]!=INF)
                                     dp[0][i]=dp[0][i-1]-RR[0][i]+A[0][i];
                                if(dp[i][j]<0)
                                        dp[i][j]=INF;
                        }
                 }
                 
                 
                 

for(i=1;i<n;i++){
                        if(A[i][0]==-1)
                                dp[i][0]=INF;
                         else{
                                if(dp[i-1][0]!=INF)
                                     dp[i][0]=dp[i-1][0]-dd[i][0]+A[i][0];
                                if(dp[i][j]<0)
                                        dp[i][j]=INF;
                        }
                 }
//                 
//                                for(i=0;i<n;i++){
//                        for(j=0;j<n;j++){
//                                cout<<RR[i][j]<<" ";
//                         }
//                         cout<<endl;
//                }
//                
                 
//                 cout<<endl;
//                 for(i=0;i<n;i++){
//                        for(j=0;j<n;j++){
//                                cout<<dp[i][j]<<" ";
//                         }
//                         cout<<endl;
//                }
                for(i=1;i<n;i++){
                        for(j=1;j<n;j++){
                                dp[i][j]=0;
                                p=0;
                                if(A[i][j]!=-1){
                                        if(i>0 && A[i-1][j]!=-1){
                                                if(dp[i-1][j]-RR[i][j]>=0)                                                
                                                        dp[i][j]=dp[i-1][j]-dd[i][j],p=1;
                                               }
                                         if(j>0 && A[i][j-1]!=-1){
                                           //     printf("hello %d %d %d %d %d\n",dp[i-1][j],dd[i][j],RR[i][j]);
                                                if(dp[i][j-1]-RR[i][j]>=0)
                                                dp[i][j]=max(dp[i][j],dp[i][j-1] - RR[i][j]),p=1;}
                                         if(p==1)
                                             dp[i][j]+=A[i][j];
                                         else 
                                                dp[i][j]=INF;
                                         if(dp[i][j]<0)
                                                dp[i][j]=INF;
                                   // dp[i][j] = max( dp[i-1][j]+ dd[i][j] , dp[i][j-1]+RR[i][j]);
                                }
                                else
                                        dp[i][j]=INF;
                         }
                }
                
                
//               for(i=0;i<n;i++){
//                        for(j=0;j<n;j++){
//                                cout<<dp[i][j]<<" ";
//                         }
//                         cout<<endl;
//                }
                if(dp[n-1][n-1]>=INF){
                        printf("MURDER\n");
                }
                else 
                        printf("%d\n",dp[n-1][n-1]);
                
        }
        return 0;
}                                       