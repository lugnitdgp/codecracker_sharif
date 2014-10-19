#include<iostream>
#define mod 1000000007
using namespace std;
long long a[10001];
int main()
{
    a[0]=1;
    for(int i=1;i<10001;i++)
        a[i]=(a[i-1]*2)%mod;
    int t;
    cin>>t;
    long long n,k;
    long long sum,m;
    while(t--)
    {
        cin>>n>>k;
        if(n-1>=k)
        {
        n-=1;
        m=k>n?n:k;
        sum=1;
        for(int i=1;i<=m;i++)
        {
            sum+=((n-1)/i)%mod;
        }
        cout<<sum<<endl;
        }
        else
        {
            sum=a[n-1];
            cout<<sum<<endl;
        }
    }
    return 0;
}
