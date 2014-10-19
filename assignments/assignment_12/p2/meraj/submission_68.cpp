#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    bool flag=false;
    long long int t, n, x, sum=0;
    cin>>t;
    while (t--)
    {
        cin>>n;
        sum=0;
        while (n--)
        {
            cin>>x;
            if(x%2!=0)
            {
                flag=true;
            }
        }
        if (!flag)
        {
            cout<<"Durga\n";
        }
        else
            cout<<"Aayush\n";
        flag=false;
    }
    return 0;
}