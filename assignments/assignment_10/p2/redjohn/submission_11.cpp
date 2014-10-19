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
#define SS ({int x;scanf("%d ", &x);x;})
#define SSL ({LL x;scanf("%lld", &x);x;})
#define rep(i,n) for(i=0;i<(n);i++)
#define _mp make_pair

int main(){
        int t=SS;
        while(t--){
        int m=SS,n,num,i,ID,str;
        n=SS;
        string name;
        map<int,string> mp;
        map<int,string> ::iterator it;
        map<int,int> marks;
        map<int,int>:: iterator itt;
        rep(i,m){
                char ch;
//                cin>>ID;
                ID=SS;
                getline(cin,name);
                mp[ID]=name;
       }
       rep(i,n){
                cin>>str>>num;
                marks[str]=max(marks[str],num);
        }

        for(it=mp.begin();it!=mp.end();it++){
                
                cout<<(*it).SE<<" "<<marks[(*it).FI]<<endl;
         }
         }
         return 0;
}         
                