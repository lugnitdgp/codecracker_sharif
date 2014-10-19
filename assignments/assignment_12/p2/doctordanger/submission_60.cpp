#include<iostream>
using namespace std;
int main()
{
    int t;
    int n;
    int a[1001];
    cin>>t;
    int max;
    while(t--)
    {
        cin>>n;
        max=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]>max)
                max=a[i];
        }
        if(max%2==0)
            cout<<"Durga";
        else
            cout<<"Aayush";
        cout<<endl;
    }
    return 0;
}
