#include<iostream>
#include<cstdio>

using namespace std;
int A[10003],B[10003];
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,ans=0,avg;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        B[0]=A[0];
        for(int i=1;i<n;i++)
            B[i]=B[i-1]+A[i];
        avg=B[n-1];
        if(avg!=(avg/n)*n)
            cout<<"ANGRY"<<endl;
        else{
            int k1=0,k2=0;
            avg/=n;
            for(int i=1;i<n;i++){
                k1=avg*i-B[i-1];
                k2=avg-A[i];
                if(k1>0&&k2>0){
                    if(ans<max(k1,k2))
                        ans=max(k1,k2);
                }
                else if(k1<0&&k2<0){
                    if(ans<max(-k1,-k2))
                        ans=max(-k1,-k2);
                }
                else if(k1>0&&k2<0){
                    if(ans<max(k1,-k1-k2))
                        ans=max(k1,-k1-k2);
                }
                else{
                    if(ans<max(-k1-k2,k2))
                        ans=max(-k1-k2,k2);
                }

            }
            cout<<ans<<endl;
        }

    }
    return 0;
}
