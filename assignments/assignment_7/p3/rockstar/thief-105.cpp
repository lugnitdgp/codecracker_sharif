#include<iostream>
using namespace std;
int a[10005];
int main(){
    int test,sum,maxy,sjd,sid,avg,n,id;
    cin >> test;
    while(test--){
        cin >> n;
        maxy=-1,sum=0,sjd=0,sid=0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            sum += a[i];
            if(a[i]>maxy){
                maxy = a[i];
                id = i;
            }
        }
        avg = sum/n;
        if(sum%n){
            cout << "ANGRY\n";
            continue;
        }
        for(int i=0;i<id;i++)
            sid +=a[i];
        for(int i=id+1;i<n;i++)
            sjd += a[i];
        sid = (id)*avg-sid;
        sjd = (n-1-id)*avg-sjd;
        cout << max(sid,sjd) << "\n";
    }
}
