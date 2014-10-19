#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>
#include <string.h>
using namespace std;
#define For(i,m,n) for(i = m ; i < n ; i ++ )
    #define For1(i,m,n) for(i = m ; i < n ; ++i  ){
using namespace std;

int main(){
     long long T,n,a,b,i,j,k,x,M,r;

    cin>>T;
    string s,s3;
//char *s1,*s2,s;
    For(i,0,T){cin>>n;
    cin>>s;
    cin>>r;
s3="";
    sort(s.begin(), s.end());
    a=r;
    while(r>0)
    {
        b=r%n;
if(b!=0)
        s3+=s[b-1];
else
s3+=s[b-2];
        r=r/n;
       //cout<<b<<"  "<<endl;
    }
   // s1[c]='\0';
   reverse(s3.begin(),s3.end());
    cout<<s3<<endl;
    }
    return 0;
}
