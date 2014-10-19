#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
string str;
int a[50],p[50],c,l;
int b[27];
void func(int R,int r,string ret){
    if(!r){
        str = ret + str[R-1];
        return;
    }
    int flag;
    for(int i=0;i<l;i++){
        if(R<=p[r-1]*(i+1)){
            flag=i;
            break;
        }
    }
    func(R-(p[r-1]*flag),r-1,ret+str[flag]);
            
}
    
int main(){
    int test,R;
    long long int t;
    cin >> test;
    while(test--){
        cin >> l >> str >> R;
        for(int i=0;i<27;i++)b[i]=0;
        for(int i=0;i<l;i++)b[str[i]-'a']++;
        str="";
        for(int i=0;i<27;i++)
            if(b[i]) str += i+'a';
        l = str.length();
        a[0]=l,c=1,p[0]=l;
        while(a[c-1]<R){
             p[c] = p[c-1]*l;
             a[c] = a[c-1]+p[c];
             c++;
        }
        int id = lower_bound(a,a+c,R) - a;
        R = R - (id>0?a[id-1]:0);
        func(R,id,"");
        cout << str  <<endl;
    }
}

