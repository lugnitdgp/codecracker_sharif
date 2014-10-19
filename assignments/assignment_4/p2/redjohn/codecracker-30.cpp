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
        int t=SS,i,n,k;
        string str;
        while(t--){
                k=0;
                cin>>str;
                n=str.size();
                if(n<5) {
                        printf("-1\n");
                        continue;
                }
                if(tolower(str[0])!='l')
                        k++;
                if(tolower(str[1])!='i')
                        k++;
                if(tolower(str[n-1])!='x')
                        k++;
                if(tolower(str[n-2])!='u')
                        k++;            
                for(i=2;i<n-2;i++)
                        if(tolower(str[i])!='n')
                                k++;
                cout<<k<<endl;                                                            


        }
        return 0;
}                        
