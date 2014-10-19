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
#define STF(a,b) (a(b.begin(),b.end())); 
#define MS(a,b) memset(a,b,sizeof(a));
#define STFN(a,b,c) (a(b.begin(),b.end(),c))
string inttostring(int n ){
        string str="";
        while(n>0){
                str = str + (char)(n+'0');
                n/=10;
       }
       return str;
}       
vector<string> v,v2;
void pre(){
  	int p=0,i;
  	string q;
    v.push_back("008");
  	for(i=2;8*i<=1000;i++){  
      	q=inttostring(i*8);
      	STF(reverse,q);
      	if(q.size()==2){
      	        v2.PB(q);
      	        q='0'+q;
      	        }
      	v.PB(q);
       }
//       rep(i,v.size())
//        cout<<v[i]<<endl;
//        
}
int f[10];
bool isdivisible(){
        int i,j;
        rep(i,v.size()){
               // cout<<v[i]<<endl;
                rep(j,10){
                      //  cout<<f[j]<<" "<<STFN(count,v[i],j)<<endl;
                        if(f[j]<STFN(count,v[i],j+'0'))
                                break;
                }
                if(j==10) return 1;
         }
         return 0;
}         
bool isdivisible2(){
        int i,j;
        rep(i,v2.size()){
               // cout<<v[i]<<endl;
                rep(j,10){
                      //  cout<<f[j]<<" "<<STFN(count,v[i],j)<<endl;
                        if(f[j]<STFN(count,v2[i],j+'0'))
                                break;
                }
                if(j==10) return 1;
         }
         return 0;
} 
int main() {
        pre();
    int t,n,i,flag;
  string A;
  cin>>t;
  while(t--){
        MS(f,0);
    	cin>>A;
    	flag=0;
    	n=A.size();
    	rep(i,n) f[A[i]-'0']++;
    	if(n==1){
    	        if(A=="0" || A=="8")
    	                flag=1;
    	}
    	else if(n==2){
    	        flag=isdivisible2();
    	}
    	else
                flag=isdivisible();
        printf("%s\n",(flag)?"YES":"NO");
  }
    return 0;
}