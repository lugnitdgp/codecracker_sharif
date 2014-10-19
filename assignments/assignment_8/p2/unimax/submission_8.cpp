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

bool isvowel(char str){
         if(str=='a' || str=='e' || str=='i' || str=='o' || str=='u')
                return 1;
          return 0;
}          
                
int main(){
        int n,isvo,se,i,p=0;
        string str,st;
        while(cin>>str){
                n=str.size();
                isvo=0;
                se=0;
                p=1;
                for(i=0;i<n;i++){
                        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
                                isvo=1;
                        if(i>0 && str[i]==str[i-1] && (str[i]!='e' && str[i]!='o'))
                                se=1;
                }
                for(i=0;i<n-2;i++){
                        st=str.substr(i,3);
                        if((isvowel(st[0]) && isvowel(st[1]) && isvowel(st[2])) || (!isvowel(st[0]) && !isvowel(st[1]) && !isvowel(st[2])))
                                p=0;
                                
                       // cout<<st<<endl;
                 }
              //   cout<<isvo<<" "<<p<<" "<<se<<endl;
                 if(isvo && p && !se)
                      //  printf("<%s> is acceptable.\n",str);
                      cout<<"<"<<str<<"> "<<"is acceptable."<<endl;
                  else
                                              cout<<"<"<<str<<"> "<<"is not acceptable."<<endl;
                      //  printf("<%s> is not acceptable.\n",str);
                 
         }
                        
        return 0;
}        