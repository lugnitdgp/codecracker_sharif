#include<stdio.h>
#include<string.h>
#include<iostream>
#include<map>

using namespace std;
typedef long long LL;
typedef pair<int,int> II;

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
                