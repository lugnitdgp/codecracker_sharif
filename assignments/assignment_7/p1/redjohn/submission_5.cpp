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
int A[30][30],RR[30][30],dp[31][31],dd[30][30];
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
             /*  for(i=0;i<n;i++){
                        for(j=0;j<n;j++){
                                cout<<RR[i][j]<<" ";
                         }
                         cout<<endl;
                }
                
                
               for(i=0;i<n;i++){
                        for(j=0;j<n;j++){
                                cout<<dd[i][j]<<" ";
                         }
                         cout<<endl;
                }*/
                
                for(i=0;i<n;i++){
                        for(j=0;j<n;j++){
                                dp[i][j]=0;
                                if(A[i][j]!=-1){
                                        if(i>0 && A[i-1][j]!=-1)
                                                dp[i][j]=dp[i-1][j]-dd[i][j];
                                         if(j>0 && A[i][j-1]!=-1)
                                                dp[i][j]=max(dp[i][j],dp[i][j-1] - RR[i][j]);
                                         dp[i][j]+=A[i][j];
                                   // dp[i][j] = max( dp[i-1][j]+ dd[i][j] , dp[i][j-1]+RR[i][j]);
                                }
                                else
                                        dp[i][j]=INF;
                         }
                }
                if(dp[n-1][n-1]==INF){
                        printf("MURDER\n");
                }
                else 
                        printf("%d\n",dp[n-1][n-1]);
                
        }
        return 0;
}                                       