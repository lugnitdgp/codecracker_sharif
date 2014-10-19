#include<iostream>
using namespace std;
int main()
{
    int t;
    int n;
    int a[1001];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        if(n%2==0)
            cout<<"Durga\n";
        else
            cout<<"Aayush\n";
    }
    return 0;
}
