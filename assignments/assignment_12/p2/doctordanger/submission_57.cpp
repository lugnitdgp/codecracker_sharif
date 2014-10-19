#include<iostream>
using namespace std;
int main()
{
    int t;
    int n;
    int a[1001];
    cin>>t;
    int min;
    while(t--)
    {
        cin>>n;
        min=1000000;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<min)
                min=a[i];
        }
        if(min%2==0)
            cout<<"Durga";
        else
            cout<<"Aayush";
        cout<<endl;
    }
    return 0;
}
