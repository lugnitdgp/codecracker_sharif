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
        int t=SS,i,j,q,p,k,l,r;
        string str;
        while(t--){
                int n;
                cin>>n>>str;
          //      cout<<str<<endl;
                sort(str.begin(),str.end());
                r=SS;
                p=1;
                for(i=0;;i++){
                        p=p*n;
                        if(r-p>0)
                                r=r-p;
                        else break;
                }
          //      string str="";
         //       cout<<i+1<<endl;
                r--;
                q=n;
                for(j=0;j<i+1;j++){
                      l=r%q;
//cout<<l<<endl;
                      cout<<str[l];
                       q=q*n;
                 }      
                  cout<<endl;      
                
        
        }
        return 0;
}        
        